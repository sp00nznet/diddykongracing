// read_dump.js — Read state variables from RDRAM dump files
// Usage: node read_dump.js <rdram_dump.bin>
// Reads key DKR state variables from an 8MB RDRAM dump

const fs = require('fs');

const file = process.argv[2];
if (!file) {
    console.error('Usage: node read_dump.js <rdram_dump.bin>');
    process.exit(1);
}

const buf = fs.readFileSync(file);
console.log(`Read ${buf.length} bytes from ${file}`);

// RDRAM dump starts at virtual address 0x80000000
// To read address 0x80XXXXXX, offset = 0xXXXXXX
function readU32(vaddr) {
    const offset = vaddr - 0x80000000;
    if (offset < 0 || offset + 4 > buf.length) return null;
    return buf.readUInt32BE(offset);
}

function readS32(vaddr) {
    const offset = vaddr - 0x80000000;
    if (offset < 0 || offset + 4 > buf.length) return null;
    return buf.readInt32BE(offset);
}

function readU8(vaddr) {
    const offset = vaddr - 0x80000000;
    if (offset < 0 || offset + 1 > buf.length) return null;
    return buf.readUInt8(offset);
}

function readU16(vaddr) {
    const offset = vaddr - 0x80000000;
    if (offset < 0 || offset + 2 > buf.length) return null;
    return buf.readUInt16BE(offset);
}

const GAME_MODES = { '-1': 'INTRO', '0': 'INGAME', '1': 'MENU', '5': 'LOCKUP' };

console.log('\n=== DKR Game State ===');

const gm = readS32(0x80123A6C);
console.log(`gGameMode:          ${gm} (${GAME_MODES[String(gm)] || '?'})`);
console.log(`gCurrentMenuId:     ${readU8(0x800DF9F0)}`);
console.log(`gMenuCurIndex:      ${readU8(0x800DF9E0)}`);
console.log(`gIsInRace:          ${readS32(0x800DD88C)}`);
console.log(`gScreenStatus:      0x${(readU32(0x800DD8F0) >>> 0).toString(16)}`);
console.log(`gRenderMenu:        ${readS32(0x80123A70)}`);
console.log(`gPlayableMapId:     ${readS32(0x80123A7C)}`);
console.log(`gMapId:             ${readS32(0x800DD890)}`);

console.log('\n=== Transition State ===');
console.log(`gRaceEndTransition: 0x${(readU32(0x800DCDD0) >>> 0).toString(16)}`);
console.log(`gTrackIdToLoad:     ${readS32(0x800DFA54)}`);
console.log(`gGameCurrentCutscene: ${readS32(0x80123A88)}`);
console.log(`gGameCurrentEntrance: ${readS32(0x80123A84)}`);

console.log('\n=== Display List ===');
console.log(`gCurrDisplayList:   0x${(readU32(0x80121778) >>> 0).toString(16)}`);
console.log(`gDisplayLists[0]:   0x${(readU32(0x80121770) >>> 0).toString(16)}`);
console.log(`gDisplayLists[1]:   0x${(readU32(0x80121774) >>> 0).toString(16)}`);

console.log('\n=== Input ===');
console.log(`gControllerCurrData:    0x${(readU32(0x80121690) >>> 0).toString(16)}`);
console.log(`gControllerBtnPressed:  0x${(readU32(0x801216C0) >>> 0).toString(16)}`);

console.log('\n=== Audio ===');
console.log(`gMusicPlayer:       0x${(readU32(0x800DCBA0) >>> 0).toString(16)}`);
console.log(`gJinglePlayer:      0x${(readU32(0x800DCBA4) >>> 0).toString(16)}`);

console.log('\n=== Camera ===');
console.log(`gActiveCameraID:    ${readS32(0x80121264)}`);
console.log(`gNumCameras:        ${readS32(0x80121268)}`);

console.log('\n=== Race ===');
console.log(`gNumRacers:         ${readS32(0x8011B470)}`);
console.log(`gRaceFinishTriggered: ${readS32(0x8011B334)}`);
console.log(`gCurrentDefaultVehicle: ${readS32(0x800DD884)}`);
