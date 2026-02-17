#!/usr/bin/env node
/**
 * generate_symbols.js
 * Parses the DKR decomp symbol_addrs file and splat YAML to generate
 * an N64Recomp-compatible TOML symbols file.
 */

const fs = require('fs');
const path = require('path');

// US v1.1 (v80) - matches ROM SHA1 6d96743d46f8c0cd0edb0ec5600b003c89b93755
const SYMBOL_FILE = path.resolve(__dirname, '../../dkr-decomp/ver/symbols/symbol_addrs.us.v80.txt');
const OUTPUT_FILE = path.resolve(__dirname, '../dkr.us.syms.toml');

// From splat YAML: main segment
const MAIN_ROM_START = 0x1000;
const MAIN_VRAM_START = 0x80000400;

// Code ends where textbin (RSP microcode) begins
// aspMain textbin is at ROM 0xD8760 in v80
const CODE_ROM_END = 0xD8760;
const CODE_VRAM_END = MAIN_VRAM_START + (CODE_ROM_END - MAIN_ROM_START); // 0x800D7B60

function parseSymbolFile(filePath) {
    const content = fs.readFileSync(filePath, 'utf-8');
    const lines = content.split('\n');

    let currentSection = 'unknown';
    let isTextSection = false;
    const functions = [];
    const dataSymbols = [];

    for (const line of lines) {
        const trimmed = line.trim();

        // Section comment
        if (trimmed.startsWith('//')) {
            const comment = trimmed.substring(2).trim();
            if (comment.includes('.text')) {
                currentSection = comment;
                isTextSection = true;
            } else if (comment.includes('.data') || comment.includes('.rodata') || comment.includes('.bss')) {
                currentSection = comment;
                isTextSection = false;
            } else if (comment === '' || comment.startsWith('_')) {
                // Keep current section type for ambiguous comments
            } else {
                // Other comments (like "// bcopy", "// sinf", "// cosf")
                // These are typically libultra function sections still in .text
                // Keep isTextSection = true if we were already in text
                currentSection = comment;
            }
            continue;
        }

        // Symbol line: name = 0xADDRESS; // optional comment
        const match = trimmed.match(/^(\w+)\s*=\s*0x([0-9A-Fa-f]+)\s*;(.*)$/);
        if (!match) continue;

        const name = match[1];
        const vram = parseInt(match[2], 16);
        const comment = match[3].trim();

        // Parse size if available
        let size = 0;
        const sizeMatch = comment.match(/size:0x([0-9A-Fa-f]+)/);
        if (sizeMatch) {
            size = parseInt(sizeMatch[1], 16);
        }

        // Classify: is this a function or data?
        // A symbol in the code VRAM range that isn't explicitly in a .data/.rodata/.bss section is a function
        const isInCodeRange = vram >= MAIN_VRAM_START && vram < CODE_VRAM_END;
        const isExplicitData = currentSection.includes('.data') || currentSection.includes('.rodata') || currentSection.includes('.bss');

        if (isInCodeRange && !isExplicitData) {
            functions.push({ name, vram, size, section: currentSection });
        } else {
            dataSymbols.push({ name, vram, size, section: currentSection });
        }
    }

    return { functions, dataSymbols };
}

function calculateFunctionSizes(functions) {
    // Sort by VRAM address
    functions.sort((a, b) => a.vram - b.vram);

    // Remove duplicates (same VRAM address)
    const unique = [];
    const seen = new Set();
    for (const func of functions) {
        if (!seen.has(func.vram)) {
            seen.add(func.vram);
            unique.push(func);
        }
    }

    // Calculate sizes from gaps
    for (let i = 0; i < unique.length; i++) {
        if (unique[i].size > 0) continue; // Already has a size

        if (i + 1 < unique.length) {
            unique[i].size = unique[i + 1].vram - unique[i].vram;
        } else {
            // Last function - extends to end of code section
            unique[i].size = CODE_VRAM_END - unique[i].vram;
        }
    }

    // Filter out any with invalid sizes
    return unique.filter(f => f.size > 0 && f.size % 4 === 0);
}

function generateToml(functions) {
    const sectionSize = CODE_ROM_END - MAIN_ROM_START;

    let toml = `# Diddy Kong Racing (US v1.0) - N64Recomp Symbol File\n`;
    toml += `# Auto-generated from DKR decomp project symbol data\n`;
    toml += `# https://github.com/DavidSM64/Diddy-Kong-Racing\n\n`;

    toml += `[[section]]\n`;
    toml += `name = "..main"\n`;
    toml += `rom = 0x${MAIN_ROM_START.toString(16).toUpperCase()}\n`;
    toml += `vram = 0x${MAIN_VRAM_START.toString(16).toUpperCase()}\n`;
    toml += `size = 0x${sectionSize.toString(16).toUpperCase()}\n\n`;

    for (const func of functions) {
        toml += `[[section.functions]]\n`;
        toml += `name = "${func.name}"\n`;
        toml += `vram = 0x${func.vram.toString(16).toUpperCase()}\n`;
        toml += `size = 0x${func.size.toString(16).toUpperCase()}\n\n`;
    }

    return toml;
}

// Main
console.log('Parsing symbol file...');
const { functions, dataSymbols } = parseSymbolFile(SYMBOL_FILE);
console.log(`Found ${functions.length} function symbols, ${dataSymbols.length} data symbols`);

console.log('Calculating function sizes...');
const processedFuncs = calculateFunctionSizes(functions);
console.log(`Processed ${processedFuncs.length} functions with valid sizes`);

if (processedFuncs.length > 0) {
    console.log(`First function: ${processedFuncs[0].name} at 0x${processedFuncs[0].vram.toString(16)} size 0x${processedFuncs[0].size.toString(16)}`);
    console.log(`Last function: ${processedFuncs[processedFuncs.length-1].name} at 0x${processedFuncs[processedFuncs.length-1].vram.toString(16)} size 0x${processedFuncs[processedFuncs.length-1].size.toString(16)}`);
}

console.log('Generating TOML...');
const toml = generateToml(processedFuncs);
fs.writeFileSync(OUTPUT_FILE, toml);
console.log(`Written to ${OUTPUT_FILE}`);
console.log(`Total code coverage: 0x${(CODE_ROM_END - MAIN_ROM_START).toString(16)} bytes`);
