// m64p_dump.js — Run DKR in mupen64plus, dump RDRAM at timed intervals
// Avoids the stdout buffering problem by using dumpmem to write files
// Usage: node m64p_dump.js [seconds_to_run] [dump_interval_seconds]

const { spawn } = require('child_process');
const fs = require('fs');
const path = require('path');

const M64P = path.join(__dirname, 'Release', 'mupen64plus-ui-console.exe');
const ROM = 'D:\\diddy\\dkr.z64';
const DUMP_DIR = path.join(__dirname, 'dumps');

if (!fs.existsSync(DUMP_DIR)) fs.mkdirSync(DUMP_DIR);

const totalSeconds = parseInt(process.argv[2]) || 15;
const intervalSeconds = parseInt(process.argv[3]) || 5;

console.log(`[dump] Will run DKR for ${totalSeconds}s, dumping every ${intervalSeconds}s`);
console.log(`[dump] Dumps go to: ${DUMP_DIR}`);

const emumode = process.argv[4] || '1';
console.log(`[dump] Using emumode ${emumode}`);
const proc = spawn(M64P, ['--emumode', emumode, '--noosd', '--debug', ROM], {
    cwd: path.join(__dirname, 'Release'),
    stdio: ['pipe', 'pipe', 'pipe']
});

let allOutput = '';
proc.stdout.on('data', d => { allOutput += d.toString(); });
proc.stderr.on('data', d => { allOutput += d.toString(); });
proc.on('exit', code => {
    console.log(`[dump] mupen exited (code ${code})`);
    console.log('[dump] --- Full output ---');
    console.log(allOutput);
});

function send(cmd) {
    console.log(`[dump] >>> ${cmd}`);
    proc.stdin.write(cmd + '\n');
}

// Key DKR state addresses (virtual)
const STATE_VARS = {
    'gGameMode':          '80123A6C',
    'gCurrentMenuId':     '800DF9F0',
    'gIsInRace':          '800DD88C',
    'gScreenStatus':      '800DD8F0',
    'gRaceEndTransition': '800DCDD0',
    'gTrackIdToLoad':     '800DFA54',
    'gRenderMenu':        '80123A70',
    'gCurrDisplayList':   '80121778',
    'gMusicPlayer':       '800DCBA0',
    'gPlayableMapId':     '80123A7C',
};

async function sleep(ms) {
    return new Promise(r => setTimeout(r, ms));
}

async function main() {
    // Wait for debugger init (starts paused)
    await sleep(3000);

    // Start execution
    send('run');

    let dumpNum = 0;
    const startTime = Date.now();

    while ((Date.now() - startTime) < totalSeconds * 1000) {
        await sleep(intervalSeconds * 1000);
        dumpNum++;

        const elapsed = ((Date.now() - startTime) / 1000).toFixed(1);
        console.log(`\n[dump] === Snapshot #${dumpNum} at ${elapsed}s ===`);

        // Pause, dump, resume
        send('pause');
        await sleep(500);

        // Dump full RDRAM (8MB) to file
        const rdramFile = path.join(DUMP_DIR, `rdram_${dumpNum}.bin`).replace(/\\/g, '/');
        send(`dumpmem 80000000 800000 ${rdramFile}`);
        await sleep(500);

        // Also dump state variables via mem command (these get buffered but will appear on exit)
        for (const [name, addr] of Object.entries(STATE_VARS)) {
            send(`mem ${addr} 4`);
        }
        await sleep(200);

        send('run');
    }

    // Final dump
    dumpNum++;
    console.log(`\n[dump] === Final snapshot #${dumpNum} ===`);
    send('pause');
    await sleep(500);
    const finalFile = path.join(DUMP_DIR, `rdram_final.bin`).replace(/\\/g, '/');
    send(`dumpmem 80000000 800000 ${finalFile}`);
    await sleep(500);

    for (const [name, addr] of Object.entries(STATE_VARS)) {
        send(`mem ${addr} 4`);
    }
    await sleep(500);

    send('quit');

    // Wait for process to exit
    await sleep(3000);
    if (!proc.killed) proc.kill();
}

main().catch(err => {
    console.error('[dump] Error:', err);
    proc.kill();
    process.exit(1);
});
