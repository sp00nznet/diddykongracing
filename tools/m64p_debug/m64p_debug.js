// m64p_debug.js — Mupen64Plus CLI debugger wrapper
// Usage: node m64p_debug.js [script.txt]
// If script.txt provided, runs those commands then exits.
// Otherwise reads commands from stdin (for piping).

const { spawn } = require('child_process');
const fs = require('fs');
const path = require('path');
const readline = require('readline');

const M64P = path.join(__dirname, 'Release', 'mupen64plus-ui-console.exe');
const ROM = 'D:\\diddy\\dkr.z64';

const args = ['--emumode', '0', '--noosd', '--debug', ROM];

// Force line-buffered stdout on Windows by setting environment
const env = Object.assign({}, process.env);
// Disable C runtime buffering
env['PYTHONUNBUFFERED'] = '1';

console.error('[m64p] Launching:', M64P, args.join(' '));

const proc = spawn(M64P, args, {
    cwd: path.join(__dirname, 'Release'),
    stdio: ['pipe', 'pipe', 'pipe'],
    env: env
});

// Also capture from stderr since mupen may output there
proc.stderr.setEncoding('utf8');
proc.stdout.setEncoding('utf8');

let outputBuffer = '';
let waitResolve = null;

proc.stdout.on('data', (data) => {
    const text = data.toString();
    process.stdout.write(text);
    outputBuffer += text;
    // If we're waiting for output and see the (dbg) prompt, resolve
    if (waitResolve && outputBuffer.includes('(dbg)')) {
        const result = outputBuffer;
        outputBuffer = '';
        waitResolve(result);
        waitResolve = null;
    }
});

proc.stderr.on('data', (data) => {
    const text = data.toString();
    process.stderr.write(text);
    // Mupen may output debugger responses to stderr too
    outputBuffer += text;
    if (waitResolve && outputBuffer.includes('(dbg)')) {
        const result = outputBuffer;
        outputBuffer = '';
        waitResolve(result);
        waitResolve = null;
    }
});

proc.on('exit', (code) => {
    console.error(`[m64p] Process exited with code ${code}`);
    process.exit(code || 0);
});

function waitForPrompt(timeoutMs = 10000) {
    return new Promise((resolve, reject) => {
        // Check if we already have a prompt
        if (outputBuffer.includes('(dbg)')) {
            const result = outputBuffer;
            outputBuffer = '';
            resolve(result);
            return;
        }
        waitResolve = resolve;
        const timer = setTimeout(() => {
            if (waitResolve) {
                const result = outputBuffer;
                outputBuffer = '';
                waitResolve = null;
                resolve(result);
            }
        }, timeoutMs);
    });
}

// Dump full RDRAM to a file
function dumpRdram(filename) {
    sendCommand(`dumpmem 80000000 800000 ${filename}`);
}

function sendCommand(cmd) {
    console.error(`[m64p] >>> ${cmd}`);
    proc.stdin.write(cmd + '\n');
}

async function runScript(commands) {
    // Wait for initial prompt
    await waitForPrompt(15000);

    for (const cmd of commands) {
        const trimmed = cmd.trim();
        if (!trimmed || trimmed.startsWith('#')) continue;

        // Special: "wait <ms>" pauses between commands
        if (trimmed.startsWith('wait ')) {
            const ms = parseInt(trimmed.split(' ')[1]) || 1000;
            console.error(`[m64p] waiting ${ms}ms...`);
            await new Promise(r => setTimeout(r, ms));
            continue;
        }

        sendCommand(trimmed);
        // 'run' may take a very long time before a breakpoint hits
        const timeout = trimmed === 'run' ? 120000 : 5000;
        const output = await waitForPrompt(timeout);
    }
}

async function main() {
    const scriptFile = process.argv[2];

    if (scriptFile) {
        // Run commands from file
        const commands = fs.readFileSync(scriptFile, 'utf8').split('\n');
        await runScript(commands);
        // After script, keep listening for breakpoint hits
        console.error('[m64p] Script complete. Waiting for breakpoints (2 min)...');

        // Listen for breakpoint hits and dump state when they fire
        const listenForBreaks = async () => {
            while (true) {
                const output = await waitForPrompt(120000);
                if (!output) break;
                if (output.includes('PC at') || output.includes('Hit breakpoint')) {
                    console.error('[m64p] BREAKPOINT HIT! Dumping state...');
                    sendCommand('pc');
                    await waitForPrompt(3000);
                    sendCommand('bp trig');
                    await waitForPrompt(3000);
                    sendCommand('mem 80123A6C 4');
                    await waitForPrompt(3000);
                    sendCommand('mem 800DF9F0 4');
                    await waitForPrompt(3000);
                    sendCommand('mem 800DD88C 4');
                    await waitForPrompt(3000);
                    sendCommand('mem 800DCDD0 4');
                    await waitForPrompt(3000);
                    sendCommand('mem 800DFA54 4');
                    await waitForPrompt(3000);
                    // Continue execution to catch next break
                    sendCommand('run');
                } else {
                    break;
                }
            }
            sendCommand('quit');
            setTimeout(() => process.exit(0), 2000);
        };
        await listenForBreaks();
    } else {
        // Interactive: read commands from stdin line by line
        await waitForPrompt(15000);
        console.error('[m64p] Ready. Enter commands:');

        const rl = readline.createInterface({
            input: process.stdin,
            output: process.stderr,
            prompt: ''
        });

        rl.on('line', async (line) => {
            const trimmed = line.trim();
            if (!trimmed) return;
            if (trimmed === 'quit' || trimmed === 'exit') {
                sendCommand('quit');
                setTimeout(() => process.exit(0), 2000);
                return;
            }
            sendCommand(trimmed);
        });

        rl.on('close', () => {
            sendCommand('quit');
            setTimeout(() => process.exit(0), 2000);
        });
    }
}

main().catch(err => {
    console.error('[m64p] Error:', err);
    process.exit(1);
});
