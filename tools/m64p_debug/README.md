# mupen64plus CLI Debugger Tools

Custom mupen64plus build with `DBG` support enabled, providing CLI-based debugging for N64 games. Useful for inspecting game state variables at runtime without a full GUI debugger.

## Building mupen64plus with debug support

1. Extract `mupen64plus-core-src-2.6.0.tar.gz`
2. Add `DBG` to the C/C++ preprocessor defines in the MSVC project
3. Build with MSBuild (Release x64):
   ```
   msbuild mupen64plus-core.vcxproj /p:Configuration=Release /p:Platform=x64
   ```
4. The built binaries go into `Release/`

## Tools

### m64p_state.js — Timed state snapshots

Boots a ROM, runs it for a set duration, and periodically pauses to read memory addresses. Outputs formatted snapshots of game state.

```
node m64p_state.js <config.json> [total_seconds] [interval_seconds]
```

- `config.json` — Path to a game-specific config file (see below)
- `total_seconds` — How long to run (default: 20)
- `interval_seconds` — Pause interval between snapshots (default: 10)

Example:
```
node m64p_state.js dkr_state.json 60 5
```

### m64p_debug.js — Interactive debugger / script runner

Wraps the mupen64plus debugger CLI. Can run a script file of commands or be used interactively.

```
node m64p_debug.js [script.txt]
```

Script files support `wait <ms>` for delays between commands and `#` comments.

### read_dump.js — RDRAM dump reader

Reads game state variables from an 8MB RDRAM binary dump (created via `dumpmem` in the debugger).

```
node read_dump.js <rdram_dump.bin>
```

Currently DKR-specific (hardcoded addresses).

## Config file format

The config JSON file defines everything game-specific for `m64p_state.js`:

```json
{
    "rom": "D:\\path\\to\\game.z64",
    "emumode": 1,
    "state_reads": [
        { "name": "gSomeVariable", "addr": "80123ABC", "size": 4 },
        { "name": "gAnotherVar",   "addr": "800DFACE", "size": 4 }
    ],
    "labels": {
        "gSomeVariable": {
            "00000000": "STATE_A",
            "00000001": "STATE_B"
        }
    }
}
```

Fields:

| Field | Required | Description |
|-------|----------|-------------|
| `rom` | yes | Absolute path to the ROM file |
| `emumode` | no | Emulator mode (default: 1). **Use emumode 1 (cached interpreter). Emumode 0 (pure interpreter) causes thread faults with the debug interface.** |
| `state_reads` | yes | Array of memory addresses to read each snapshot |
| `state_reads[].name` | yes | Display name for the variable |
| `state_reads[].addr` | yes | N64 virtual address as 8-char hex string (e.g. `"80123ABC"`) |
| `state_reads[].size` | yes | Bytes to read (typically 4) |
| `labels` | no | Map of variable name to value-label pairs. When a read value matches a key, the label is shown in output. |

## Adding a new game

1. Find the addresses you care about from a decomp project, symbol map, or by searching in the debugger
2. Create a config JSON file following the format above
3. Run: `node m64p_state.js your_game.json 30 5`

## Emumode note

Always use `emumode 1` (cached interpreter) for debug sessions. Emumode 0 (pure interpreter) causes thread faults when the debug interface is active. Emumode 2 (dynamic recompiler) does not support the debug breakpoint/step interface.
