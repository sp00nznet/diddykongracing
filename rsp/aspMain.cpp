#include "librecomp/rsp.hpp"
#include "librecomp/rsp_vu_impl.hpp"
#include <cstdio>
#include <cstring>
static int asp_cmd_count = 0;
static int asp_task_id = 0;
static int asp_adpcm_cmd_count = 0;
extern "C" int g_asp_task_id = 0; // global, readable from other files

// [PATCH] HLE intercepts for broken audio commands.
//
// DKR's aspMain has several broken/no-op dispatch handlers:
//   - dispatch[2] (A_CLEARBUFF) → L_11EC: reads 1 byte from wrong RDRAM addr (no-op)
//   - dispatch[4] (A_LOADBUFF)  → L_123C: hardcoded DMEM 0x4C0, wrong RDRAM source
//   - dispatch[6] (A_SAVEBUFF)  → L_1270: sets params only, NO DMA write to RDRAM
//   - dispatch[12] (A_MIXER)    → L_1E3C: enters at loop body, skipping ALL setup
//   - dispatch[13] (A_INTERLEAVE) → L_1390: enters at loop continuation (no-op)
//
// The microcode has ZERO calls to the DMA write subroutine (L_1144).
// On real N64 hardware, aspMain never writes processed audio back to RDRAM.
// POLEF, RESAMPLE etc. process audio entirely within DMEM.
//
// Fix: HLE intercept CLEARBUFF, LOADBUFF, MIXER, INTERLEAVE, and SAVEBUFF.
// MIXER implements the full VMULF/VMACF accumulation that the native handler
// skips due to entering at the loop body without register initialization.
// SAVEBUFF runs L_1270's param logic (needed by other commands) and
// only does DMA write after INTERLEAVE (for the final stereo output).
static int savebuff_count = 0;
static int loadbuff_count = 0;
static bool did_interleave = false;  // Set by INTERLEAVE, consumed by SAVEBUFF

// ============================================================================
// naudio HLE state — matches mupen64plus naudio_dk implementation
// ============================================================================
// DKR uses the naudio variant of aspMain (same as Banjo-Kazooie).
// The raw microcode dispatch table has critical bugs:
//   - dispatch[9] (SETVOL) → L_132C: actually an interleave handler, NOT SETVOL
//   - dispatch[3] (ENVMIXER) reads params[0,2] for L/R addresses but they're
//     never set correctly by the broken SETVOL handler
// Fix: Full HLE for both SETVOL and ENVMIXER based on mupen64plus reference.

// DKR DMEM buffer layout (all offsets relative to audio base 0x5C0):
// INPUT      = 0x000 → DMEM 0x5C0   (mono input from RESAMPLE/ADPCM)
// DRY_LEFT   = 0x440 → DMEM 0xA00   (left dry output accumulator)
// DRY_RIGHT  = 0x580 → DMEM 0xB40   (right dry output accumulator)
// WET_LEFT   = 0x6C0 → DMEM 0xC80   (left wet/reverb accumulator)
// WET_RIGHT  = 0x800 → DMEM 0xDC0   (right wet/reverb accumulator)
// ENVMIXER processes 160 samples (320 bytes) per voice.

static struct {
    int16_t vol[2];       // current volume: [0]=left, [1]=right
    int16_t target[2];    // target volume: [0]=left, [1]=right
    int32_t rate[2];      // volume ramp rate: [0]=left, [1]=right
    int16_t dry;          // dry send level
    int16_t wet;          // wet/reverb send level
} naudio_state;

// Helper: read a big-endian 16-bit signed sample from DMEM
static inline int16_t dmem_read_s16(uint32_t addr) {
    addr &= 0xFFF;
    return (int16_t)((RSP_MEM_BU(0, addr) << 8) | RSP_MEM_BU(1, addr));
}

// Helper: write a big-endian 16-bit signed sample to DMEM
static inline void dmem_write_s16(uint32_t addr, int16_t val) {
    addr &= 0xFFF;
    RSP_MEM_B(0, addr) = (uint8_t)((uint16_t)val >> 8);
    RSP_MEM_B(1, addr) = (uint8_t)((uint16_t)val & 0xFF);
}

// Helper: clamp int32 to int16 range
static inline int16_t clamp16(int32_t v) {
    if (v > 32767) return 32767;
    if (v < -32768) return -32768;
    return (int16_t)v;
}

// RDRAM helpers: read/write big-endian values with XOR 3 byte order
static inline int16_t rdram_read_s16(uint8_t* rdram, uint32_t addr) {
    return (int16_t)((rdram[addr ^ 3] << 8) | rdram[(addr + 1) ^ 3]);
}
static inline void rdram_write_s16(uint8_t* rdram, uint32_t addr, int16_t val) {
    rdram[addr ^ 3] = (uint8_t)((uint16_t)val >> 8);
    rdram[(addr + 1) ^ 3] = (uint8_t)((uint16_t)val & 0xFF);
}
static inline int32_t rdram_read_s32(uint8_t* rdram, uint32_t addr) {
    return (int32_t)(
        ((uint32_t)rdram[addr ^ 3] << 24) |
        ((uint32_t)rdram[(addr + 1) ^ 3] << 16) |
        ((uint32_t)rdram[(addr + 2) ^ 3] << 8) |
        (uint32_t)rdram[(addr + 3) ^ 3]
    );
}
static inline void rdram_write_s32(uint8_t* rdram, uint32_t addr, int32_t val) {
    rdram[addr ^ 3] = (uint8_t)((uint32_t)val >> 24);
    rdram[(addr + 1) ^ 3] = (uint8_t)((uint32_t)val >> 16);
    rdram[(addr + 2) ^ 3] = (uint8_t)((uint32_t)val >> 8);
    rdram[(addr + 3) ^ 3] = (uint8_t)((uint32_t)val & 0xFF);
}

// ENVMIXER state buffer layout in RDRAM (80 bytes = 0x50):
// Offsets 0x00-0x0F: v20 (8x int16_t) — left dry volume per sample group
// Offsets 0x10-0x1F: v21 (8x int16_t) — right dry volume per sample group
// Offsets 0x20-0x2F: v18 (8x int16_t) — left wet volume per sample group
// Offsets 0x30-0x3F: v19 (8x int16_t) — right wet volume per sample group
// Offsets 0x40-0x4F: v24 (8x int16_t) — envelope state (targets/rates)
// For A_INIT: we initialize from naudio_state set by SETVOL commands.
// For A_CONTINUE: we load from RDRAM and resume where we left off.

// Expected dispatch table values (IMEM addresses for audio command handlers)
static const uint16_t expected_dispatch[16] = {
    0x1118, 0x14A4, 0x11EC, 0x1BA0,
    0x123C, 0x18D4, 0x1270, 0x12D4,
    0x12F0, 0x132C, 0x1428, 0x12A4,
    0x1E3C, 0x1390, 0x1758, 0x1480,
};

static bool asp_check_dispatch_table() {
    for (int i = 0; i < 16; i++) {
        uint16_t val = (uint16_t)RSP_MEM_HU_LOAD(0x10, i * 2);
        if (val != expected_dispatch[i]) {
            fprintf(stderr, "[ASP] DISPATCH TABLE CORRUPTED at index %d (DMEM[0x%03X]): got 0x%04X, expected 0x%04X (task#%d, cmd#%d)\n",
                i, 0x10 + i * 2, val, expected_dispatch[i], asp_task_id, asp_cmd_count);
            // Dump full dispatch table
            fprintf(stderr, "[ASP] Dispatch table dump:");
            for (int j = 0; j < 16; j++) {
                fprintf(stderr, " %04X", (uint16_t)RSP_MEM_HU_LOAD(0x10, j * 2));
            }
            fprintf(stderr, "\n");
            fflush(stderr);
            return false;
        }
    }
    return true;
}

// Custom DMA functions that handle the full SP_RD_LEN/SP_WR_LEN register format:
//   bits[11:0]  = length per row minus 1
//   bits[19:12] = row count minus 1
//   bits[31:20] = RDRAM skip between rows
// The library's dma_rdram_to_dmem only handles single-row DMA and has an
// assert(dmem_addr + rd_len <= 0x1000) that fires for multi-row transfers.
// RSP_MEM_B already wraps DMEM addresses at 0xFFF, so byte accesses are safe.
static void asp_dma_rdram_to_dmem(uint8_t* rdram, uint32_t dmem_addr, uint32_t dram_addr, uint32_t rd_len_reg) {
    uint32_t length = (rd_len_reg & 0xFFF) + 1;
    uint32_t count = ((rd_len_reg >> 12) & 0xFF) + 1;
    uint32_t skip = (rd_len_reg >> 20) & 0xFFF;
    dram_addr &= 0xFFFFF8;
    for (uint32_t row = 0; row < count; row++) {
        for (uint32_t i = 0; i < length; i++) {
            RSP_MEM_B(i, dmem_addr) = MEM_B(0, (int64_t)(int32_t)(dram_addr + i + 0x80000000));
        }
        dmem_addr = (dmem_addr + length) & 0xFFF;
        dram_addr += length + skip;
    }
}

static int asp_dma_write_count = 0;

static void asp_dma_dmem_to_rdram(uint8_t* rdram, uint32_t dmem_addr, uint32_t dram_addr, uint32_t wr_len_reg) {
    uint32_t length = (wr_len_reg & 0xFFF) + 1;
    uint32_t count = ((wr_len_reg >> 12) & 0xFF) + 1;
    uint32_t skip = (wr_len_reg >> 20) & 0xFFF;
    uint32_t orig_dram = dram_addr;
    dram_addr &= 0xFFFFF8;

    asp_dma_write_count++;
    if (asp_task_id <= 3) {
        // Check if DMEM source has non-zero data
        int nz = 0;
        for (uint32_t i = 0; i < length * count && i < 256; i++) {
            if (RSP_MEM_BU(i, dmem_addr) != 0) nz++;
        }
        fprintf(stderr, "[ASP-DMA-WR] t%d #%d: dmem=0x%03X dram=0x%06X len=%u cnt=%u skip=%u dmem_nz=%d\n",
                asp_task_id, asp_dma_write_count, dmem_addr, dram_addr, length, count, skip, nz);
        fflush(stderr);
    }

    for (uint32_t row = 0; row < count; row++) {
        for (uint32_t i = 0; i < length; i++) {
            MEM_B(0, (int64_t)(int32_t)(dram_addr + i + 0x80000000)) = RSP_MEM_B(i, dmem_addr);
        }
        dmem_addr = (dmem_addr + length) & 0xFFF;
        dram_addr += length + skip;
    }
}
static int op_hist[16] = {};
RspExitReason aspMain(uint8_t* rdram, [[maybe_unused]] uint32_t ucode_addr) {
    asp_cmd_count = 0;
    asp_task_id++;
    g_asp_task_id = asp_task_id;
    memset(op_hist, 0, sizeof(op_hist));
    // RSP general-purpose registers persist across tasks on real N64 hardware.
    // Making them static matches this behavior. The startup code below reinitializes
    // the registers it needs (r1, r24, r23, r28, r27) each task. Critical for audio:
    // r10 is set by RESAMPLE and checked by ENVMIXER — if r10==0, ENVMIXER skips all
    // voice processing. Without persistence, the first ENVMIXER in each task gets r10=0.
    static uint32_t           r1 = 0,  r2 = 0,  r3 = 0,  r4 = 0,  r5 = 0,  r6 = 0,  r7 = 0;
    static uint32_t  r8 = 0,  r9 = 0, r10 = 0, r11 = 0, r12 = 0, r13 = 0, r14 = 0, r15 = 0;
    static uint32_t r16 = 0, r17 = 0, r18 = 0, r19 = 0, r20 = 0, r21 = 0, r22 = 0, r23 = 0;
    static uint32_t r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    static uint32_t dma_mem_address = 0, dma_dram_address = 0, jump_target = 0;
    const char * debug_file = NULL; int debug_line = 0;
    static RSP rsp{};  // Persist DMEM across tasks (like real N64 RSP)
    r1 = 0xFC0;
    // addi        $24, $zero, 0x360
    r24 = RSP_ADD32(0, 0X360);
    // addi        $23, $zero, 0xF90
    r23 = RSP_ADD32(0, 0XF90);
    // lw          $28, 0x30($1)
    r28 = RSP_MEM_W_LOAD(0X30, r1);
    // lw          $27, 0x34($1)
    r27 = RSP_MEM_W_LOAD(0X34, r1);
    static uint32_t saved_data_size = 0;
    saved_data_size = r27;
    // Diagnostic: log ucode_data_size, dispatch table, and ENVMIXER params
    if (asp_task_id <= 3 || (asp_task_id >= 91 && asp_task_id <= 92)) {
        uint32_t udata_sz = RSP_MEM_W_LOAD(0x1C, 0xFC0);  // task->t.ucode_data_size from DMEM
        uint16_t p0 = RSP_MEM_HU_LOAD(0x0, r24);  // params[0] (L output addr)
        uint16_t p2 = RSP_MEM_HU_LOAD(0x2, r24);  // params[2] (R output addr)
        fprintf(stderr, "[ASP] t%d: ucode_data_size=0x%X, data_size(cmds)=0x%X, params[0]=0x%04X params[2]=0x%04X\n",
                asp_task_id, udata_sz, r27, p0, p2);
        // Dump dispatch table from DMEM
        if (asp_task_id == 1) {
            fprintf(stderr, "[ASP] Dispatch table from DMEM:");
            for (int i = 0; i < 16; i++) {
                fprintf(stderr, " [%d]=0x%04X", i, (uint16_t)RSP_MEM_HU_LOAD(0x10, i * 2));
            }
            fprintf(stderr, "\n");
            // Dump params[0x10..0x1F]
            fprintf(stderr, "[ASP] Params[0x10..0x1E]:");
            for (int i = 0; i < 8; i++) {
                fprintf(stderr, " 0x%04X", (uint16_t)RSP_MEM_HU_LOAD(0x10 + i * 2, r24));
            }
            fprintf(stderr, "\n");
        }
        fflush(stderr);
    }
    // mfc0        $5, DPC_STATUS
    r5 = 0;
    // andi        $4, $5, 0x1
    r4 = r5 & 0X1;
    // beq         $4, $zero, L_1034
    if (r4 == 0) {
        // andi        $4, $5, 0x100
        r4 = r5 & 0X100;
        goto L_1034;
    }
    // andi        $4, $5, 0x100
    r4 = r5 & 0X100;
    // beq         $4, $zero, L_1034
    if (r4 == 0) {
        // nop
    
        goto L_1034;
    }
    // nop

L_1028:
    // mfc0        $4, DPC_STATUS
    r4 = 0;
    // andi        $4, $4, 0x100
    r4 = r4 & 0X100;
    // bgtz        $4, L_1028
    if (RSP_SIGNED(r4) > 0) {
        // nop
    
        goto L_1028;
    }
L_1034:
    // nop

    // jal         0x1160
    r31 = 0x1040;
    // nop

    goto L_1160;
    // nop

L_1040:
    // addi        $2, $zero, 0xF
    r2 = RSP_ADD32(0, 0XF);
    // addi        $1, $zero, 0x320
    r1 = RSP_ADD32(0, 0X320);
L_1048:
    // sw          $zero, 0x0($1)
    RSP_MEM_W_STORE(0X0, r1, 0);
    // bgtz        $2, L_1048
    if (RSP_SIGNED(r2) > 0) {
        // addi        $2, $2, -0x1
        r2 = RSP_ADD32(r2, -0X1);
        goto L_1048;
    }
    // addi        $2, $2, -0x1
    r2 = RSP_ADD32(r2, -0X1);
L_1054:
    // mfc0        $2, SP_DMA_BUSY
    r2 = 0;
    // bne         $2, $zero, L_1054
    if (r2 != 0) {
        // addi        $29, $zero, 0x380
        r29 = RSP_ADD32(0, 0X380);
        goto L_1054;
    }
    // addi        $29, $zero, 0x380
    r29 = RSP_ADD32(0, 0X380);
    // mtc0        $zero, SP_SEMAPHORE
    // [PATCH] DMA is synchronous in recompiled version - load first command batch
    // before processing any commands. On real RSP, the boot code or async DMA
    // would have populated DMEM[0x380] before the microcode reached this point.
    goto L_10D4;
L_1064:
    // lw          $26, 0x0($29)
    r26 = RSP_MEM_W_LOAD(0X0, r29);
    // lw          $25, 0x4($29)
    r25 = RSP_MEM_W_LOAD(0X4, r29);
    // srl         $1, $26, 23
    r1 = S32(U32(r26) >> 23);
    // andi        $1, $1, 0xFE
    r1 = r1 & 0XFE;
    // [DEBUG] Trace command dispatch
    asp_cmd_count++;
    if (r1/2 < 16) op_hist[r1/2]++;
    // Dump commands around the first voice (incl. SETBUFF/SAVEBUFF/RESAMPLE/ENVMIXER)
    if (asp_task_id == 91 && asp_cmd_count <= 30) {
        uint16_t p0  = RSP_MEM_HU_LOAD(0x0, r24);
        uint16_t p2  = RSP_MEM_HU_LOAD(0x2, r24);
        uint16_t p10 = RSP_MEM_HU_LOAD(0x10, r24);
        uint16_t p12 = RSP_MEM_HU_LOAD(0x12, r24);
        uint16_t p14 = RSP_MEM_HU_LOAD(0x14, r24);
        fprintf(stderr, "[ASP] t91 cmd#%d: op=%d w0=0x%08X w1=0x%08X  p[0]=0x%03X p[2]=0x%03X p[10]=0x%03X p[12]=0x%03X p[14]=0x%03X\n",
                asp_cmd_count, r1/2, r26, r25, p0, p2, p10, p12, p14);
        fflush(stderr);
    }
    // addi        $28, $28, 0x8
    r28 = RSP_ADD32(r28, 0X8);
    // addi        $27, $27, -0x8
    r27 = RSP_ADD32(r27, -0X8);
    // addi        $29, $29, 0x8
    r29 = RSP_ADD32(r29, 0X8);
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
    // add         $2, $zero, $1
    r2 = RSP_ADD32(0, r1);
    // lh          $2, 0x10($2)
    // [PATCH] Use static dispatch table instead of DMEM read.
    // Audio processing (POLEF, RESAMPLE) writes output via SDV stores that wrap
    // around the 4KB DMEM and overwrite the dispatch table at DMEM[0x10..0x2F].
    // On real RSP hardware this is harmless (table already consumed), but in the
    // recomp we re-read it for every command. The table never changes, so use
    // the known-good static copy.
    if ((r1 / 2) >= 16) {
        fprintf(stderr, "[ASP] Bad opcode: r1=%u (op=%u) w0=0x%08X w1=0x%08X task#%d cmd#%d r29=0x%X r30=%d\n",
                r1, r1/2, r26, r25, asp_task_id, asp_cmd_count, r29, (int32_t)r30);
        fflush(stderr);
        return RspExitReason::Broke;
    }
    if ((r1 / 2) == 1) {
        asp_adpcm_cmd_count++;
        if (asp_adpcm_cmd_count <= 5) {
            fprintf(stderr, "[ASP] ADPCM cmd! t%d cmd#%d total_adpcm=%d w0=0x%08X w1=0x%08X\n",
                    asp_task_id, asp_cmd_count, asp_adpcm_cmd_count, r26, r25);
            fflush(stderr);
        }
    }
    // Log ALL SETVOL (op=9) and ENVMIXER (op=3) commands
    if ((r1 / 2) == 9) {
        static int setvol_count = 0;
        setvol_count++;
        if (setvol_count <= 20) {
            fprintf(stderr, "[ASP] SETVOL #%d: w0=0x%08X w1=0x%08X flags=0x%02X (t%d cmd#%d)\n",
                    setvol_count, r26, r25, (U32(r26) >> 16) & 0xFF, asp_task_id, asp_cmd_count);
            fflush(stderr);
        }
    }
    if ((r1 / 2) == 3) {
        static int envmixer_total = 0;
        envmixer_total++;
        if (envmixer_total <= 20) {
            uint8_t env_flags = (U32(r26) >> 16) & 0xFF;
            fprintf(stderr, "[ASP] ENVMIXER #%d: w0=0x%08X w1=0x%08X flags=0x%02X init=%d aux=%d (t%d cmd#%d)\n",
                    envmixer_total, r26, r25, env_flags, env_flags & 1, (env_flags >> 3) & 1,
                    asp_task_id, asp_cmd_count);
            fflush(stderr);
        }
    }
    // [PATCH] HLE intercepts for broken audio command handlers.
    // Uses naudio_dk encoding per mupen64plus: w0[11:0]=dmem, w0[23:12]=count,
    // w1=rdram_addr. Audio base offset = 0x5C0.
    //
    // CLEARBUFF (op=2): L_11EC is a no-op. HLE zeros the specified DMEM buffer.
    // LOADBUFF (op=4): L_123C is broken. HLE does DMA read (RDRAM→DMEM).
    // SAVEBUFF (op=6): L_1270 only sets params. HLE does DMA write (DMEM→RDRAM).
    // MIXER (op=12): dispatch[12]=L_1E3C enters at loop body, skipping ALL
    //   setup (r1,r2,r17,r18,v31). HLE implements full VMULF/VMACF mixer.
    // INTERLEAVE (op=13): L_1390 is broken. HLE interleaves L/R channels.
    if ((r1 / 2) == 2) {
        // A_CLEARBUFF: Zero DMEM buffer.
        // w0[15:0] = DMEM offset (relative to audio base 0x5C0)
        // w1[15:0] = byte count
        uint16_t dmem_off = r26 & 0xFFFF;
        uint16_t count    = r25 & 0xFFFF;
        uint32_t dmem_addr = (dmem_off + 0x5C0) & 0xFFF;
        for (uint16_t i = 0; i < count; i++) {
            RSP_MEM_B(i, dmem_addr) = 0;
        }
        static int clearbuff_log = 0;
        clearbuff_log++;
        if (clearbuff_log <= 40) {
            fprintf(stderr, "[ASP] CLEARBUFF #%d: off=0x%03X dmem=0x%03X count=%u (t%d cmd#%d)\n",
                    clearbuff_log, dmem_off, dmem_addr, count, asp_task_id, asp_cmd_count);
            fflush(stderr);
        }
        goto L_1098;
    }
    if ((r1 / 2) == 4) {
        // A_LOADBUFF: DMA read from RDRAM to DMEM.
        //
        // naudio encoding (DKR uses alist_process_naudio_dk per mupen64plus):
        //   w0[11:0]  = DMEM offset (relative to audio base 0x5C0)
        //   w0[23:12] = byte count
        //   w1        = RDRAM physical address
        //
        // Fallback to SETBUFF params if naudio count is 0.
        uint16_t na_dmem  = r26 & 0xFFF;
        uint16_t na_count = (U32(r26) >> 12) & 0xFFF;
        uint16_t sb_dmem  = RSP_MEM_HU_LOAD(0x10, r24);
        uint16_t sb_count = RSP_MEM_HU_LOAD(0x14, r24);

        uint16_t byte_count = na_count > 0 ? na_count : sb_count;
        uint16_t dmem_off   = na_count > 0 ? na_dmem : sb_dmem;
        uint32_t dmem_dst   = (dmem_off + 0x5C0) & 0xFFF;
        uint32_t rdram_src  = r25 & 0xFFFFFF;

        loadbuff_count++;

        if (byte_count > 0 && rdram_src + byte_count <= 0x800000) {
            for (uint32_t i = 0; i < byte_count; i++) {
                RSP_MEM_B(i, dmem_dst) = rdram[(rdram_src + i) ^ 3];
            }
        }

        if (loadbuff_count <= 20) {
            int rdram_nz = 0, dmem_nz = 0;
            for (uint32_t i = 0; i < byte_count && i < 64; i++) {
                if (rdram[(rdram_src + i) ^ 3] != 0) rdram_nz++;
                if (RSP_MEM_BU(i, dmem_dst) != 0) dmem_nz++;
            }
            fprintf(stderr, "[ASP] LOADBUFF #%d: rdram=0x%06X dmem=0x%03X count=%u(na=%u sb=%u) rdram_nz=%d dmem_nz=%d (t%d cmd#%d)\n",
                    loadbuff_count, rdram_src, dmem_dst, byte_count, na_count, sb_count, rdram_nz, dmem_nz, asp_task_id, asp_cmd_count);
            fprintf(stderr, "[ASP]   RDRAM[0x%06X]:", rdram_src);
            for (int j = 0; j < 16 && j < (int)byte_count; j++)
                fprintf(stderr, " %02X", rdram[(rdram_src + j) ^ 3]);
            fprintf(stderr, "\n");
            fflush(stderr);
        }
        goto L_1098;
    }
    if ((r1 / 2) == 6) {
        // A_SAVEBUFF: DMA write from DMEM to RDRAM.
        //
        // DKR's SAVEBUFF doesn't encode count in w0 (lower 24 bits are 0).
        // Use SETBUFF params[0x14] as byte count, same fallback as LOADBUFF.
        // DMEM source: (w0[11:0] + 0x5C0) & 0xFFF = 0x5C0 for most calls.
        // RDRAM dest:  w1 & 0xFFFFFF.
        //
        // Also update params for the raw microcode path (L_1270 compatibility):
        uint32_t flags = (U32(r26) >> 16) & 0x8;
        if (flags == 0) {
            RSP_MEM_H_STORE(0x0, r24, RSP_ADD32(r26, 0x5C0));
            RSP_MEM_H_STORE(0x2, r24, RSP_ADD32(S32(U32(r25) >> 16), 0x5C0));
            RSP_MEM_H_STORE(0x4, r24, r25);
        } else {
            RSP_MEM_H_STORE(0xE, r24, RSP_ADD32(r25, 0x5C0));
            RSP_MEM_H_STORE(0xA, r24, RSP_ADD32(r26, 0x5C0));
            RSP_MEM_H_STORE(0xC, r24, RSP_ADD32(S32(U32(r25) >> 16), 0x5C0));
        }

        savebuff_count++;

        // Determine byte count: try naudio encoding first, fall back to SETBUFF
        uint16_t na_dmem  = r26 & 0xFFF;
        uint16_t na_count = (U32(r26) >> 12) & 0xFFF;
        uint16_t sb_dmem  = RSP_MEM_HU_LOAD(0x10, r24);
        uint16_t sb_count = RSP_MEM_HU_LOAD(0x14, r24);

        uint16_t byte_count = na_count > 0 ? na_count : sb_count;
        uint16_t dmem_off   = na_count > 0 ? na_dmem : sb_dmem;
        uint32_t dmem_src   = (dmem_off + 0x5C0) & 0xFFF;
        uint32_t rdram_dst  = r25 & 0xFFFFFF;

        if (byte_count > 0 && rdram_dst + byte_count <= 0x800000) {
            for (uint32_t i = 0; i < byte_count; i++) {
                rdram[(rdram_dst + i) ^ 3] = RSP_MEM_BU(i, dmem_src);
            }
        }

        // Log: first 20, after INTERLEAVE, or writes to AI DAC range (0x3F????)
        if (savebuff_count <= 20 || did_interleave || rdram_dst >= 0x3F0000) {
            int nz = 0;
            for (uint32_t i = 0; i < byte_count && i < 64; i++) {
                if (RSP_MEM_BU(i, dmem_src) != 0) nz++;
            }
            const char* tag = did_interleave ? "POST-INTLV" : (rdram_dst >= 0x3F0000 ? "AI-BUF" : "");
            fprintf(stderr, "[ASP] SAVEBUFF #%d %s: dmem=0x%03X rdram=0x%06X count=%u(na=%u sb=%u) nz=%d flags=0x%X (t%d cmd#%d)\n",
                    savebuff_count, tag, dmem_src, rdram_dst, byte_count, na_count, sb_count, nz, flags, asp_task_id, asp_cmd_count);
            if (did_interleave && byte_count >= 16) {
                fprintf(stderr, "[ASP]   DMEM[0x%03X]:", dmem_src);
                for (int j = 0; j < 16; j++)
                    fprintf(stderr, " %02X", RSP_MEM_BU(j, dmem_src));
                fprintf(stderr, "\n");
                // Also check what's at RDRAM after the write
                fprintf(stderr, "[ASP]   RDRAM[0x%06X]:", rdram_dst);
                for (int j = 0; j < 16; j++)
                    fprintf(stderr, " %02X", rdram[(rdram_dst + j) ^ 3]);
                fprintf(stderr, "\n");
            }
            fflush(stderr);
        }

        if (did_interleave) did_interleave = false;
        goto L_1098;
    }
    if ((r1 / 2) == 12) {
        // A_MIXER: Mix source audio into destination buffer.
        //
        // dispatch[12] = 0x1E3C enters at the MIXER loop body, skipping ALL
        // register setup (r1, r2, r17, r18, v31 initialization). The setup
        // code at IMEM 0x1DBC is unreachable from dispatch — it's only reached
        // when ENVMIXER (dispatch[3]) chains into the mixer, but DKR never
        // sends op=3 commands. This is a microcode bug.
        //
        // w0[15:0] = gain (signed Q15 fixed-point)
        // w1[31:16] = source DMEM offset (relative to audio base 0x5C0)
        // w1[15:0] = destination DMEM offset (relative to audio base 0x5C0)
        // Count from params[0x14] (set by preceding SETBUFF op=8)
        //
        // Operation: dest[i] = dest[i] * mixer_const + src[i] * gain
        // mixer_const = DMEM[0x0C..0x0D] (element 6 of vector constant table)
        uint16_t byte_count = RSP_MEM_HU_LOAD(0x14, r24);  // params[0x14]
        if (byte_count == 0) {
            goto L_1098;
        }

        int16_t gain = (int16_t)(r26 & 0xFFFF);
        uint16_t src_off = (U32(r25) >> 16) & 0xFFFF;
        uint16_t dst_off = r25 & 0xFFFF;
        uint32_t src_addr = (src_off + 0x5C0) & 0xFFF;
        uint32_t dst_addr = (dst_off + 0x5C0) & 0xFFF;

        // Mixer constant: "1.0" in Q15 = 0x7FFF.
        // On real RSP, this lives in v31[6] loaded from DMEM[0x0C..0x0D].
        // But RESAMPLE's SQV stores wrap around DMEM and corrupt the constant table.
        // Hardcode the known-good value (same fix as the static dispatch table).
        int16_t mixer_const = 0x7FFF;

        static int mixer_log = 0;
        mixer_log++;
        if (mixer_log <= 30) {
            int src_nz = 0, dst_nz = 0;
            for (uint32_t i = 0; i < byte_count && i < 32; i++) {
                if (RSP_MEM_BU(i, src_addr) != 0) src_nz++;
                if (RSP_MEM_BU(i, dst_addr) != 0) dst_nz++;
            }
            fprintf(stderr, "[ASP] MIXER #%d: gain=0x%04X src=0x%03X dst=0x%03X count=%u const=0x%04X src_nz=%d dst_nz=%d (t%d cmd#%d)\n",
                    mixer_log, (uint16_t)gain, src_addr, dst_addr, byte_count, (uint16_t)mixer_const, src_nz, dst_nz, asp_task_id, asp_cmd_count);
            fflush(stderr);
        }

        uint16_t num_samples = byte_count / 2;
        for (uint16_t i = 0; i < num_samples; i++) {
            uint32_t s_off = (src_addr + i * 2) & 0xFFF;
            uint32_t d_off = (dst_addr + i * 2) & 0xFFF;

            // Read 16-bit signed samples (big-endian in DMEM)
            int16_t src_sample = (int16_t)((RSP_MEM_BU(0, s_off) << 8) | RSP_MEM_BU(1, s_off));
            int16_t dst_sample = (int16_t)((RSP_MEM_BU(0, d_off) << 8) | RSP_MEM_BU(1, d_off));

            // VMULF: acc = dst * mixer_const * 2 + 0x8000 (rounding)
            // VMACF: acc += src * gain * 2
            int64_t acc = (int64_t)dst_sample * (int64_t)mixer_const;
            acc = (acc << 1) + 0x8000;
            acc += (int64_t)src_sample * (int64_t)gain * 2;

            // Clamp to signed 16-bit
            int32_t result = (int32_t)(acc >> 16);
            if (result > 32767) result = 32767;
            if (result < -32768) result = -32768;

            // Write back (big-endian)
            RSP_MEM_B(0, d_off) = (uint8_t)(result >> 8);
            RSP_MEM_B(1, d_off) = (uint8_t)(result & 0xFF);
        }

        goto L_1098;
    }
    if ((r1 / 2) == 13) {
        // A_INTERLEAVE: Interleave left and right channels into stereo output.
        // w1[31:16] = left channel DMEM offset, w1[15:0] = right channel DMEM offset
        // Count from params[0x14] (bytes per channel, set by preceding SETBUFF).
        // Output goes to DMEM[0x5C0].
        uint16_t count     = RSP_MEM_HU_LOAD(0x14, r24);
        uint16_t left_off  = (U32(r25) >> 16) & 0xFFFF;
        uint16_t right_off = r25 & 0xFFFF;
        uint32_t left_addr  = (left_off + 0x5C0) & 0xFFF;
        uint32_t right_addr = (right_off + 0x5C0) & 0xFFF;
        uint32_t out_addr   = 0x5C0;

        // Interleave: for each sample pair, write left then right.
        uint16_t num_samples = count / 2;  // samples per channel (count is in bytes)
        for (uint16_t i = 0; i < num_samples; i++) {
            // Read 16-bit samples from left and right channels
            uint8_t lh = RSP_MEM_BU(i * 2,     left_addr);
            uint8_t ll = RSP_MEM_BU(i * 2 + 1, left_addr);
            uint8_t rh = RSP_MEM_BU(i * 2,     right_addr);
            uint8_t rl = RSP_MEM_BU(i * 2 + 1, right_addr);
            // Write interleaved: L, R, L, R, ...
            RSP_MEM_B(i * 4,     out_addr) = lh;
            RSP_MEM_B(i * 4 + 1, out_addr) = ll;
            RSP_MEM_B(i * 4 + 2, out_addr) = rh;
            RSP_MEM_B(i * 4 + 3, out_addr) = rl;
        }

        static int interleave_count = 0;
        interleave_count++;
        if (asp_task_id >= 89 && interleave_count <= 100) {
            int nz = 0;
            for (uint32_t i = 0; i < count * 2 && i < 640; i++) {
                if (RSP_MEM_BU(i, out_addr) != 0) nz++;
            }
            // Also check the source L/R channel buffers
            int lnz = 0, rnz = 0;
            for (uint32_t i = 0; i < count && i < 320; i++) {
                if (RSP_MEM_BU(i, left_addr) != 0) lnz++;
                if (RSP_MEM_BU(i, right_addr) != 0) rnz++;
            }
            fprintf(stderr, "[ASP] INTERLEAVE #%d: left=0x%03X right=0x%03X out=0x%03X count=%u nz=%d lnz=%d rnz=%d (t%d cmd#%d)\n",
                    interleave_count, left_addr, right_addr, out_addr, count, nz, lnz, rnz, asp_task_id, asp_cmd_count);
            fflush(stderr);
        }

        did_interleave = true;
        goto L_1098;
    }
    if ((r1 / 2) == 8) {
        // A_SETBUFF: Set buffer parameters for the next processing command.
        //
        // In naudio, op=8 with flags=0x00 sets MAIN buffers (for RESAMPLE/ADPCM):
        //   params[0x10] = input, params[0x12] = output, params[0x14] = count
        // With flags=0x08 it sets AUX buffers (for ENVMIXER aux send):
        //   params[0x16] = aux dry left, params[0x18] = aux dry right, params[0x1A] = aux wet
        uint8_t sb_flags = (U32(r26) >> 16) & 0xFF;
        if (sb_flags & 0x08) {
            // AUX mode
            RSP_MEM_H_STORE(0X16, r24, r26);                    // params[0x16] = w0 low16
            RSP_MEM_H_STORE(0X18, r24, S32(U32(r25) >> 16));    // params[0x18] = w1 high16
            RSP_MEM_H_STORE(0X1A, r24, r25);                    // params[0x1A] = w1 low16
        } else {
            // MAIN mode — store to SETBUFF params (for HLE handlers)
            RSP_MEM_H_STORE(0X10, r24, r26);                    // params[0x10] = w0 low16 (input)
            RSP_MEM_H_STORE(0X12, r24, S32(U32(r25) >> 16));    // params[0x12] = w1 high16 (output)
            RSP_MEM_H_STORE(0X14, r24, r25);                    // params[0x14] = w1 low16 (count)
            // Also write to params[0,2,4] for raw microcode handlers (RESAMPLE, ADPCM).
            // DKR's naudio doesn't send SAVEBUFF before each voice, so params[0,2,4]
            // stay at zero. The raw handlers expect these to be set with +0x5C0 base.
            RSP_MEM_H_STORE(0x0, r24, RSP_ADD32(r26 & 0xFFFF, 0x5C0));                     // params[0] = input + 0x5C0
            RSP_MEM_H_STORE(0x2, r24, RSP_ADD32(S32(U32(r25) >> 16) & 0xFFFF, 0x5C0));     // params[2] = output + 0x5C0
            RSP_MEM_H_STORE(0x4, r24, r25);                                                 // params[4] = count
        }
        goto L_1098;
    }
    if ((r1 / 2) == 9) {
        // A_SETVOL HLE: dispatch[9]=L_132C is broken (routes to interleave code).
        //
        // DKR sends 5 SETVOL commands per voice (differs from standard naudio):
        //   0x06 (A_VOL|A_LEFT): vol[0] from w0[15:0]
        //   0x04 (A_VOL):        vol[1] from w0[15:0]
        //   0x02 (A_LEFT):       target[0] from w0[15:0], rate[0] from w1
        //   0x00 (none):         target[1] from w0[15:0], rate[1] from w1
        //   0x08 (A_AUX):        dry from w0[15:0], wet from w1[15:0]
        //
        // Note: standard naudio packs dry/wet into A_VOL|A_LEFT's w1 and
        // gets vol[1] from ENVMIXER command word. DKR sends w1=0 for A_VOL|A_LEFT
        // and sends dry/wet separately via A_AUX. DKR's ENVMIXER w0[15:0]=0.
        uint8_t sv_flags = (U32(r26) >> 16) & 0xFF;

        if (sv_flags & 0x08) {
            // A_AUX: Set dry and wet send levels
            naudio_state.dry = (int16_t)(r26 & 0xFFFF);
            naudio_state.wet = (int16_t)(r25 & 0xFFFF);
        } else if (sv_flags & 0x04) {
            // A_VOL: Set current volume
            if (sv_flags & 0x02) {
                // A_VOL|A_LEFT: left volume (DKR sends dry/wet=0 in w1, uses A_AUX)
                naudio_state.vol[0] = (int16_t)(r26 & 0xFFFF);
            } else {
                // A_VOL only: right volume
                naudio_state.vol[1] = (int16_t)(r26 & 0xFFFF);
            }
        } else {
            // A_RATE: Set target volume and ramp rate
            if (sv_flags & 0x02) {
                // A_LEFT: left target/rate
                naudio_state.target[0] = (int16_t)(r26 & 0xFFFF);
                naudio_state.rate[0] = (int32_t)r25;
            } else {
                // A_RIGHT: right target/rate
                naudio_state.target[1] = (int16_t)(r26 & 0xFFFF);
                naudio_state.rate[1] = (int32_t)r25;
            }
        }

        static int setvol_hle_log = 0;
        setvol_hle_log++;
        if (setvol_hle_log <= 30) {
            fprintf(stderr, "[ASP-HLE] SETVOL #%d: flags=0x%02X w0=0x%08X w1=0x%08X → vol=[%d,%d] tgt=[%d,%d] rate=[%d,%d] dry=%d wet=%d (t%d)\n",
                    setvol_hle_log, sv_flags, r26, r25,
                    naudio_state.vol[0], naudio_state.vol[1],
                    naudio_state.target[0], naudio_state.target[1],
                    naudio_state.rate[0], naudio_state.rate[1],
                    naudio_state.dry, naudio_state.wet, asp_task_id);
            fflush(stderr);
        }
        goto L_1098;
    }
    if ((r1 / 2) == 3) {
        // A_ENVMIXER HLE: Linear envelope mixer (mupen64plus alist_envmix_lin).
        //
        // w0[17:16] flags: bit 0 = A_INIT (initialize from SETVOL state)
        //                  bit 3 = A_AUX (enable aux/reverb sends)
        // w0[15:0] = right channel volume (vol[1])
        // w1 = segment address of 80-byte state buffer in RDRAM
        //
        // The mixer processes the input buffer sample-by-sample, applying
        // volume envelopes (with linear ramp toward target) and mixing into
        // 4 output buffers: dry L/R and wet L/R.
        uint8_t env_flags = (U32(r26) >> 16) & 0xFF;
        bool is_init = (env_flags & 0x01) != 0;
        bool has_aux = (env_flags & 0x08) != 0;

        // Note: standard naudio sets vol[1] from ENVMIXER w0[15:0], but DKR sends
        // 0x0000 here and sets vol[1] via SETVOL flags=0x04 instead. Don't overwrite.

        // Resolve segment address for state buffer
        uint32_t seg_addr = r25;
        uint8_t seg_id = (seg_addr >> 24) & 0x0F;
        uint32_t seg_base = RSP_MEM_W_LOAD(0x320, seg_id * 4);
        uint32_t rdram_addr = (seg_base + (seg_addr & 0x00FFFFFF)) & 0x7FFFFF;

        // Get buffer parameters from SETBUFF params
        uint16_t in_off  = RSP_MEM_HU_LOAD(0x10, r24);  // input offset (relative to 0x5C0)
        uint16_t count   = RSP_MEM_HU_LOAD(0x14, r24);  // byte count

        // DKR naudio buffer addresses
        uint32_t in_addr  = (in_off + 0x5C0) & 0xFFF;
        uint32_t dl_addr = 0xA00;  // DRY_LEFT
        uint32_t dr_addr = 0xB40;  // DRY_RIGHT
        uint32_t wl_addr = 0xC80;  // WET_LEFT
        uint32_t wr_addr = 0xDC0;  // WET_RIGHT

        uint16_t num_samples = count / 2;
        if (num_samples > 160) num_samples = 160;  // safety cap

        // Ramp state: {value, step, target} as int64_t (Q15.16 fixed-point)
        int64_t ramp_val[2];
        int64_t ramp_step[2];
        int64_t ramp_target[2];
        int16_t dry_gain, wet_gain;

        if (is_init) {
            // A_INIT: Initialize from SETVOL state
            // Per mupen64plus: step = rate / 8 (RSP processes 8 samples per vector)
            ramp_val[0]    = (int64_t)naudio_state.vol[0] << 16;
            ramp_val[1]    = (int64_t)naudio_state.vol[1] << 16;
            ramp_target[0] = (int64_t)naudio_state.target[0] << 16;
            ramp_target[1] = (int64_t)naudio_state.target[1] << 16;
            ramp_step[0]   = (int64_t)naudio_state.rate[0] / 8;
            ramp_step[1]   = (int64_t)naudio_state.rate[1] / 8;
            dry_gain       = naudio_state.dry;
            wet_gain       = naudio_state.wet;
        } else {
            // A_CONTINUE: Load state from RDRAM (self-consistent with our save format)
            // Layout (byte offsets, big-endian):
            //   0-1:   wet (int16)
            //   2-3:   dry (int16)
            //   4-5:   target[0] hi (int16)
            //   6-7:   target[1] hi (int16)
            //   8-11:  step[0] (int32)
            //   12-15: step[1] (int32)
            //   16-19: value[0] (int32)
            //   20-23: value[1] (int32)
            wet_gain       = rdram_read_s16(rdram, rdram_addr + 0);
            dry_gain       = rdram_read_s16(rdram, rdram_addr + 2);
            ramp_target[0] = (int64_t)rdram_read_s16(rdram, rdram_addr + 4) << 16;
            ramp_target[1] = (int64_t)rdram_read_s16(rdram, rdram_addr + 6) << 16;
            ramp_step[0]   = (int64_t)rdram_read_s32(rdram, rdram_addr + 8);
            ramp_step[1]   = (int64_t)rdram_read_s32(rdram, rdram_addr + 12);
            ramp_val[0]    = (int64_t)rdram_read_s32(rdram, rdram_addr + 16);
            ramp_val[1]    = (int64_t)rdram_read_s32(rdram, rdram_addr + 20);
        }

        // Process each sample (mupen64plus alist_envmix_lin pattern)
        for (uint16_t i = 0; i < num_samples; i++) {
            // Ramp step FIRST, then use (matches mupen64plus ramp_step function)
            for (int ch = 0; ch < 2; ch++) {
                ramp_val[ch] += ramp_step[ch];
                bool reached = (ramp_step[ch] <= 0)
                    ? (ramp_val[ch] <= ramp_target[ch])
                    : (ramp_val[ch] >= ramp_target[ch]);
                if (reached) {
                    ramp_val[ch] = ramp_target[ch];
                    ramp_step[ch] = 0;  // Stop ramping (critical for state save)
                }
            }

            int16_t vol_l = (int16_t)(ramp_val[0] >> 16);
            int16_t vol_r = (int16_t)(ramp_val[1] >> 16);

            // Combined gain = clamp(vol * dry_or_wet + 0x4000) >> 15 (mupen64plus)
            int16_t gain_dl = clamp16(((int32_t)vol_l * (int32_t)dry_gain + 0x4000) >> 15);
            int16_t gain_dr = clamp16(((int32_t)vol_r * (int32_t)dry_gain + 0x4000) >> 15);
            int16_t gain_wl = clamp16(((int32_t)vol_l * (int32_t)wet_gain + 0x4000) >> 15);
            int16_t gain_wr = clamp16(((int32_t)vol_r * (int32_t)wet_gain + 0x4000) >> 15);

            // Read mono input sample
            int16_t in_sample = dmem_read_s16(in_addr + i * 2);

            // Mix into output buffers: dst = clamp(dst + (src * gain) >> 15)
            int16_t cur;
            cur = dmem_read_s16(dl_addr + i * 2);
            dmem_write_s16(dl_addr + i * 2, clamp16((int32_t)cur + (((int32_t)in_sample * (int32_t)gain_dl) >> 15)));
            cur = dmem_read_s16(dr_addr + i * 2);
            dmem_write_s16(dr_addr + i * 2, clamp16((int32_t)cur + (((int32_t)in_sample * (int32_t)gain_dr) >> 15)));

            if (has_aux) {
                cur = dmem_read_s16(wl_addr + i * 2);
                dmem_write_s16(wl_addr + i * 2, clamp16((int32_t)cur + (((int32_t)in_sample * (int32_t)gain_wl) >> 15)));
                cur = dmem_read_s16(wr_addr + i * 2);
                dmem_write_s16(wr_addr + i * 2, clamp16((int32_t)cur + (((int32_t)in_sample * (int32_t)gain_wr) >> 15)));
            }
        }

        // Save state back to RDRAM (must match load format above)
        rdram_write_s16(rdram, rdram_addr + 0,  wet_gain);
        rdram_write_s16(rdram, rdram_addr + 2,  dry_gain);
        rdram_write_s16(rdram, rdram_addr + 4,  (int16_t)(ramp_target[0] >> 16));
        rdram_write_s16(rdram, rdram_addr + 6,  (int16_t)(ramp_target[1] >> 16));
        rdram_write_s32(rdram, rdram_addr + 8,  (int32_t)ramp_step[0]);
        rdram_write_s32(rdram, rdram_addr + 12, (int32_t)ramp_step[1]);
        rdram_write_s32(rdram, rdram_addr + 16, (int32_t)ramp_val[0]);
        rdram_write_s32(rdram, rdram_addr + 20, (int32_t)ramp_val[1]);
        // Clear remaining bytes (24-79)
        for (int i = 24; i < 80; i++) rdram[(rdram_addr + i) ^ 3] = 0;

        static int envmixer_hle_log = 0;
        envmixer_hle_log++;
        if (envmixer_hle_log <= 20) {
            int dl_nz = 0, dr_nz = 0, in_nz = 0;
            for (uint16_t j = 0; j < num_samples && j < 32; j++) {
                if (dmem_read_s16(dl_addr + j * 2) != 0) dl_nz++;
                if (dmem_read_s16(dr_addr + j * 2) != 0) dr_nz++;
                if (dmem_read_s16(in_addr + j * 2) != 0) in_nz++;
            }
            fprintf(stderr, "[ASP-HLE] ENVMIXER #%d: init=%d aux=%d samples=%u in=0x%03X vol=[%d,%d] tgt=[%d,%d] step=[%d,%d] dry=%d wet=%d in_nz=%d dl=%d dr=%d (t%d)\n",
                    envmixer_hle_log, is_init, has_aux, num_samples, in_addr,
                    (int16_t)(ramp_val[0] >> 16), (int16_t)(ramp_val[1] >> 16),
                    (int16_t)(ramp_target[0] >> 16), (int16_t)(ramp_target[1] >> 16),
                    (int32_t)ramp_step[0], (int32_t)ramp_step[1],
                    dry_gain, wet_gain, in_nz, dl_nz, dr_nz, asp_task_id);
            fflush(stderr);
        }

        goto L_1098;
    }
    r2 = expected_dispatch[r1 / 2];
    // jr          $2
    jump_target = r2;
    debug_file = __FILE__; debug_line = __LINE__;
    // nop

    goto do_indirect_jump;
    // nop

    // break       0
    return RspExitReason::Broke;
L_1098:
    // bgtz        $30, L_1064
    if (RSP_SIGNED(r30) > 0) {
        // nop
    
        goto L_1064;
    }
    // nop

    // blez        $27, L_10B8
    if (RSP_SIGNED(r27) <= 0) {
        // nop
    
        goto L_10B8;
    }
    // nop

    // jal         0x1160
    r31 = 0x10B0;
    // nop

    goto L_1160;
    // nop

L_10B0:
    // j           L_10D4
    // nop

    goto L_10D4;
    // nop

L_10B8:
    // mfc0        $1, SP_DMA_BUSY
    r1 = 0;
    // bne         $1, $zero, L_10B8
    if (r1 != 0) {
        // nop
    
        goto L_10B8;
    }
    // nop

    // mtc0        $zero, SP_SEMAPHORE
    // ori         $1, $zero, 0x4000
    r1 = 0 | 0X4000;
    // mtc0        $1, SP_STATUS
    // Print opcode histogram for tasks 89-95
    if (asp_task_id >= 89 && asp_task_id <= 110) {
        fprintf(stderr, "[ASP] t%d hist (%d cmds, sz=%d):", asp_task_id, asp_cmd_count, (int)saved_data_size);
        for (int i = 0; i < 16; i++) {
            if (op_hist[i] > 0) fprintf(stderr, " op%d=%d", i, op_hist[i]);
        }
        fprintf(stderr, "\n");
        fflush(stderr);
    }
    // break       0
    return RspExitReason::Broke;
L_10D4:
    // nop

L_10D8:
    // b           L_10D8
    // [PATCH] Was an infinite DMA stall loop on real RSP hardware.
    // In recompiled version, DMA is synchronous so we fall through
    // to the command batch loading code immediately.
    // nop

    // addi        $5, $ra, 0x0
    r5 = RSP_ADD32(r31, 0X0);
    // add         $2, $zero, $28
    r2 = RSP_ADD32(0, r28);
    // addi        $3, $27, 0x0
    r3 = RSP_ADD32(r27, 0X0);
    // addi        $4, $3, -0x140
    r4 = RSP_ADD32(r3, -0X140);
    // blez        $4, L_10FC
    if (RSP_SIGNED(r4) <= 0) {
        // addi        $1, $zero, 0x380
        r1 = RSP_ADD32(0, 0X380);
        goto L_10FC;
    }
    // addi        $1, $zero, 0x380
    r1 = RSP_ADD32(0, 0X380);
    // addi        $3, $zero, 0x140
    r3 = RSP_ADD32(0, 0X140);
L_10FC:
    // addi        $30, $3, 0x0
    r30 = RSP_ADD32(r3, 0X0);
    // jal         0x1194
    r31 = 0x1108;
    // addi        $3, $3, -0x1
    r3 = RSP_ADD32(r3, -0X1);
    goto L_1194;
    // addi        $3, $3, -0x1
    r3 = RSP_ADD32(r3, -0X1);
L_1108:
    // addi        $29, $zero, 0x380
    r29 = RSP_ADD32(0, 0X380);
    // jr          $5
    // [PATCH] After loading a command batch via DMA, always go to L_1064 to
    // process commands. The original jr $5 returned to the caller, but in
    // the recompiled version the stall-based flow doesn't work.
    goto L_1064;
    // nop

    // mfc0        $4, SP_SEMAPHORE
    r4 = 0;
L_1118:
    // mfc0        $4, SP_DMA_FULL
    r4 = 0;
    // bne         $4, $zero, L_1118
    if (r4 != 0) {
        // nop
    
        goto L_1118;
    }
    // nop

    // [PATCH] On real RSP, every command handler jumps to L_1118 which starts a
    // background DMA for the next command batch while continuing to process commands.
    // In the recompiled version DMA is synchronous, so we only do the DMA when
    // r22 == 0 (set by L_1194 for batch loading). When handlers return here
    // after processing a command, r22 is already set (0x80000000) so we skip
    // the DMA and go directly to L_1098 (the command loop) which checks if there
    // are more commands in the current batch. We must NOT return via jr r31 to
    // L_1108, because L_1108 resets r29=0x380 (the DMEM read pointer), which
    // would cause every command to re-read the first command in the batch.
    if (r22 != 0) {
        goto L_1098;
    }
    // mtc0        $1, SP_MEM_ADDR
    SET_DMA_MEM(r1);
    // mtc0        $2, SP_DRAM_ADDR
    SET_DMA_DRAM(r2);
    // [DEBUG] Trace DMA reads
    if (asp_cmd_count < 50) {
        fprintf(stderr, "[ASP] DMA_READ: dmem=0x%03X dram=0x%08X len=0x%X\n", r1, r2, r3);
        fflush(stderr);
    }
    // mtc0        $3, SP_RD_LEN
    // [PATCH] Use custom multi-row DMA that properly handles the full SP_RD_LEN
    // register format (length/count/skip) and DMEM address wrapping.
    asp_dma_rdram_to_dmem(rdram, dma_mem_address, dma_dram_address, r3);
    // lui         $4, 0x8000
    r4 = S32(0X8000 << 16);
    // or          $22, $4, $22
    r22 = r4 | r22;
    // jr          $ra
    jump_target = r31;
    debug_file = __FILE__; debug_line = __LINE__;
    // nop

    goto do_indirect_jump;
    // nop

    // mfc0        $4, SP_SEMAPHORE
    r4 = 0;
L_1144:
    // mfc0        $4, SP_DMA_FULL
    r4 = 0;
    // bne         $4, $zero, L_1144
    if (r4 != 0) {
        // nop
    
        goto L_1144;
    }
    // nop

    // mtc0        $1, SP_MEM_ADDR
    SET_DMA_MEM(r1);
    // mtc0        $2, SP_DRAM_ADDR
    SET_DMA_DRAM(r2);
    // [DEBUG] Trace DMA writes
    if (asp_cmd_count < 50) {
        fprintf(stderr, "[ASP] DMA_WRITE: dmem=0x%03X dram=0x%08X len=0x%X\n", r1, r2, r3);
        fflush(stderr);
    }
    // mtc0        $3, SP_WR_LEN
    // [PATCH] Use custom multi-row DMA for writes too.
    asp_dma_dmem_to_rdram(rdram, dma_mem_address, dma_dram_address, r3);
    // lui         $4, 0x8000
    r4 = S32(0X8000 << 16);
L_1160:
    // or          $22, $4, $22
    r22 = r4 | r22;
    // jr          $ra
    jump_target = r31;
    debug_file = __FILE__; debug_line = __LINE__;
    // nop

    goto do_indirect_jump;
    // nop

    // andi        $3, $25, 0xFFFF
    r3 = r25 & 0XFFFF;
    // beq         $3, $zero, L_1098
    if (r3 == 0) {
        // addi        $4, $zero, 0x5C0
        r4 = RSP_ADD32(0, 0X5C0);
        goto L_1098;
    }
    // addi        $4, $zero, 0x5C0
    r4 = RSP_ADD32(0, 0X5C0);
    // andi        $1, $26, 0xFFFF
    r1 = r26 & 0XFFFF;
    // add         $1, $1, $4
    r1 = RSP_ADD32(r1, r4);
    // vxor        $v1, $v1, $v1
    rsp.VXOR<0>(rsp.vpu.r[1], rsp.vpu.r[1], rsp.vpu.r[1]);
    // addi        $3, $3, -0x10
    r3 = RSP_ADD32(r3, -0X10);
    // beq         $22, $zero, L_11A0
    if (r22 == 0) {
        // nop
    
        goto L_11A0;
    }
    // nop

L_1190:
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
L_1194:
    // bne         $5, $zero, L_1190
    if (r5 != 0) {
        // nop
    
        goto L_1190;
    }
    // nop

    // and         $22, $zero, $zero
    r22 = 0 & 0;
    // [PATCH] Perform DMA directly, bypassing the clear loop and L_1118.
    {
        uint32_t first_row_len = (r3 & 0xFFF) + 1;
        uint32_t dma_count = ((r3 >> 12) & 0xFF) + 1;
        uint32_t dma_skip = (r3 >> 20) & 0xFFF;
        uint32_t total_dmem_bytes = first_row_len * dma_count;
        bool dma_wraps = ((r1 & 0xFFF) + total_dmem_bytes) > 0x1000;

        if (asp_task_id <= 3) {
            fprintf(stderr, "[ASP] L_1194 DMA: dmem=0x%03X dram=0x%08X len=%d count=%d skip=%d total=%d wraps=%d r31=0x%04X\n",
                r1, r2, first_row_len, dma_count, dma_skip, total_dmem_bytes, dma_wraps, r31);
            fflush(stderr);
        }

        uint8_t saved_lower_dmem[0x5C0];
        if (dma_wraps) {
            memcpy(saved_lower_dmem, dmem, 0x5C0);
        }

        SET_DMA_MEM(r1);
        SET_DMA_DRAM(r2);
        asp_dma_rdram_to_dmem(rdram, dma_mem_address, dma_dram_address, r3);

        if (dma_wraps) {
            memcpy(dmem, saved_lower_dmem, 0x5C0);
        }
    }
    r22 = S32(0X8000 << 16);  // mark DMA complete
    jump_target = r31;
    debug_file = __FILE__; debug_line = __LINE__;
    goto do_indirect_jump;
L_11A0:
    // sdv         $v1[0], 0x0($1)
    rsp.SDV<0>(rsp.vpu.r[1], r1, 0X0);
    // sdv         $v1[0], 0x8($1)
    rsp.SDV<0>(rsp.vpu.r[1], r1, 0X1);
    // addi        $1, $1, 0x10
    r1 = RSP_ADD32(r1, 0X10);
    // bgtz        $3, L_11A0
    if (RSP_SIGNED(r3) > 0) {
        // addi        $3, $3, -0x10
        r3 = RSP_ADD32(r3, -0X10);
        goto L_11A0;
    }
    // addi        $3, $3, -0x10
    r3 = RSP_ADD32(r3, -0X10);
    // j           L_1118
    // [PATCH] After A_CLEARBUFF's clear loop, return to command dispatch instead
    // of starting a DMA with destroyed register values. The original L_1118
    // DMA was a pipeline optimization (background DMA for next command batch)
    // that doesn't work with synchronous DMA.
    goto L_1098;

    goto L_1098;
    // nop

    // lhu         $3, 0x4($24)
    r3 = RSP_MEM_HU_LOAD(0X4, r24);
L_11C0:
    // beq         $3, $zero, L_1098
    if (r3 == 0) {
        // sll         $2, $25, 8
        r2 = S32(r25) << 8;
        goto L_1098;
    }
    // sll         $2, $25, 8
    r2 = S32(r25) << 8;
    // srl         $2, $2, 8
    r2 = S32(U32(r2) >> 8);
    // srl         $4, $25, 24
    r4 = S32(U32(r25) >> 24);
    // sll         $4, $4, 2
    r4 = S32(r4) << 2;
    // lw          $5, 0x320($4)
    r5 = RSP_MEM_W_LOAD(0X320, r4);
    // add         $2, $2, $5
    r2 = RSP_ADD32(r2, r5);
    // lhu         $1, 0x0($24)
    r1 = RSP_MEM_HU_LOAD(0X0, r24);
    // jal         0x1194
    r31 = 0x11E8;
    // addi        $3, $3, -0x1
    r3 = RSP_ADD32(r3, -0X1);
    goto L_1194;
    // addi        $3, $3, -0x1
    r3 = RSP_ADD32(r3, -0X1);
L_11E8:
    // j           L_1118
    // nop

    goto L_1118;
L_11EC:
    // nop

    // lhu         $3, 0x4($24)
    r3 = RSP_MEM_HU_LOAD(0X4, r24);
    // beq         $3, $zero, L_1098
    if (r3 == 0) {
        // sll         $2, $25, 8
        r2 = S32(r25) << 8;
        goto L_1098;
    }
    // sll         $2, $25, 8
    r2 = S32(r25) << 8;
    // srl         $2, $2, 8
    r2 = S32(U32(r2) >> 8);
    // srl         $4, $25, 24
    r4 = S32(U32(r25) >> 24);
    // sll         $4, $4, 2
    r4 = S32(r4) << 2;
    // lw          $5, 0x320($4)
    r5 = RSP_MEM_W_LOAD(0X320, r4);
    // add         $2, $2, $5
    r2 = RSP_ADD32(r2, r5);
    // lhu         $1, 0x2($24)
    r1 = RSP_MEM_HU_LOAD(0X2, r24);
    // jal         0x11C0
    r31 = 0x121C;
    // addi        $3, $3, -0x1
    r3 = RSP_ADD32(r3, -0X1);
    goto L_11C0;
    // addi        $3, $3, -0x1
    r3 = RSP_ADD32(r3, -0X1);
L_121C:
    // j           L_1118
    // nop

    goto L_1118;
    // nop

    // sll         $2, $25, 8
    r2 = S32(r25) << 8;
    // srl         $2, $2, 8
    r2 = S32(U32(r2) >> 8);
    // srl         $4, $25, 24
    r4 = S32(U32(r25) >> 24);
    // sll         $4, $4, 2
    r4 = S32(r4) << 2;
    // lw          $5, 0x320($4)
    r5 = RSP_MEM_W_LOAD(0X320, r4);
    // add         $2, $2, $5
    r2 = RSP_ADD32(r2, r5);
L_123C:
    // addi        $1, $zero, 0x4C0
    r1 = RSP_ADD32(0, 0X4C0);
    // andi        $3, $26, 0xFFFF
    r3 = r26 & 0XFFFF;
    // jal         0x1194
    r31 = 0x124C;
    // addi        $3, $3, -0x1
    r3 = RSP_ADD32(r3, -0X1);
    goto L_1194;
    // addi        $3, $3, -0x1
    r3 = RSP_ADD32(r3, -0X1);
L_124C:
    // j           L_1118
    // nop

    goto L_1118;
    // nop

    // sll         $3, $25, 8
    r3 = S32(r25) << 8;
    // srl         $3, $3, 8
    r3 = S32(U32(r3) >> 8);
    // srl         $2, $25, 24
    r2 = S32(U32(r25) >> 24);
    // sll         $2, $2, 2
    r2 = S32(r2) << 2;
    // add         $4, $zero, $2
    r4 = RSP_ADD32(0, r2);
    // j           L_1118
    // sw          $3, 0x320($4)
    RSP_MEM_W_STORE(0X320, r4, r3);
    goto L_1118;
    // sw          $3, 0x320($4)
    RSP_MEM_W_STORE(0X320, r4, r3);
L_1270:
    // addi        $1, $26, 0x5C0
    r1 = RSP_ADD32(r26, 0X5C0);
    // srl         $2, $25, 16
    r2 = S32(U32(r25) >> 16);
    // addi        $2, $2, 0x5C0
    r2 = RSP_ADD32(r2, 0X5C0);
    // srl         $4, $26, 16
    r4 = S32(U32(r26) >> 16);
    // andi        $4, $4, 0x8
    r4 = r4 & 0X8;
    // bgtz        $4, L_129C
    if (RSP_SIGNED(r4) > 0) {
        // addi        $3, $25, 0x5C0
        r3 = RSP_ADD32(r25, 0X5C0);
        goto L_129C;
    }
    // addi        $3, $25, 0x5C0
    r3 = RSP_ADD32(r25, 0X5C0);
    // sh          $1, 0x0($24)
    RSP_MEM_H_STORE(0X0, r24, r1);
    // sh          $2, 0x2($24)
    RSP_MEM_H_STORE(0X2, r24, r2);
    // j           L_1118
    // sh          $25, 0x4($24)
    RSP_MEM_H_STORE(0X4, r24, r25);
    goto L_1118;
    // sh          $25, 0x4($24)
    RSP_MEM_H_STORE(0X4, r24, r25);
L_129C:
    // sh          $3, 0xE($24)
    RSP_MEM_H_STORE(0XE, r24, r3);
    // sh          $1, 0xA($24)
    RSP_MEM_H_STORE(0XA, r24, r1);
L_12A4:
    // j           L_1118
    // sh          $2, 0xC($24)
    RSP_MEM_H_STORE(0XC, r24, r2);
    goto L_1118;
    // sh          $2, 0xC($24)
    RSP_MEM_H_STORE(0XC, r24, r2);
    // srl         $2, $26, 16
    r2 = S32(U32(r26) >> 16);
    // andi        $1, $2, 0x8
    r1 = r2 & 0X8;
    // beq         $1, $zero, L_12C8
    if (r1 == 0) {
        // andi        $1, $2, 0x4
        r1 = r2 & 0X4;
        goto L_12C8;
    }
    // andi        $1, $2, 0x4
    r1 = r2 & 0X4;
    // sh          $26, 0x1C($24)
    RSP_MEM_H_STORE(0X1C, r24, r26);
    // j           L_1118
    // sh          $25, 0x1E($24)
    RSP_MEM_H_STORE(0X1E, r24, r25);
    goto L_1118;
    // sh          $25, 0x1E($24)
    RSP_MEM_H_STORE(0X1E, r24, r25);
L_12C8:
    // beq         $1, $zero, L_12E8
    if (r1 == 0) {
        // andi        $1, $2, 0x2
        r1 = r2 & 0X2;
        goto L_12E8;
    }
    // andi        $1, $2, 0x2
    r1 = r2 & 0X2;
    // beq         $1, $zero, L_12E0
    if (r1 == 0) {
        // nop
    
        goto L_12E0;
    }
L_12D4:
    // nop

    // j           L_1118
    // sh          $26, 0x6($24)
    RSP_MEM_H_STORE(0X6, r24, r26);
    goto L_1118;
    // sh          $26, 0x6($24)
    RSP_MEM_H_STORE(0X6, r24, r26);
L_12E0:
    // j           L_1118
    // sh          $26, 0x8($24)
    RSP_MEM_H_STORE(0X8, r24, r26);
    goto L_1118;
    // sh          $26, 0x8($24)
    RSP_MEM_H_STORE(0X8, r24, r26);
L_12E8:
    // beq         $1, $zero, L_1300
    if (r1 == 0) {
        // srl         $1, $25, 16
        r1 = S32(U32(r25) >> 16);
        goto L_1300;
    }
    // srl         $1, $25, 16
    r1 = S32(U32(r25) >> 16);
L_12F0:
    // sh          $26, 0x10($24)
    RSP_MEM_H_STORE(0X10, r24, r26);
    // sh          $1, 0x12($24)
    RSP_MEM_H_STORE(0X12, r24, r1);
    // j           L_1118
    // sh          $25, 0x14($24)
    RSP_MEM_H_STORE(0X14, r24, r25);
    goto L_1118;
    // sh          $25, 0x14($24)
    RSP_MEM_H_STORE(0X14, r24, r25);
L_1300:
    // sh          $26, 0x16($24)
    RSP_MEM_H_STORE(0X16, r24, r26);
    // sh          $1, 0x18($24)
    RSP_MEM_H_STORE(0X18, r24, r1);
    // j           L_1118
    // sh          $25, 0x1A($24)
    RSP_MEM_H_STORE(0X1A, r24, r25);
    goto L_1118;
    // sh          $25, 0x1A($24)
    RSP_MEM_H_STORE(0X1A, r24, r25);
    // lhu         $4, 0x4($24)
    r4 = RSP_MEM_HU_LOAD(0X4, r24);
    // lhu         $3, 0x2($24)
    r3 = RSP_MEM_HU_LOAD(0X2, r24);
    // beq         $4, $zero, L_1098
    if (r4 == 0) {
        // andi        $2, $25, 0xFFFF
        r2 = r25 & 0XFFFF;
        goto L_1098;
    }
    // andi        $2, $25, 0xFFFF
    r2 = r25 & 0XFFFF;
    // addi        $2, $2, 0x5C0
    r2 = RSP_ADD32(r2, 0X5C0);
    // srl         $1, $25, 16
    r1 = S32(U32(r25) >> 16);
    // addi        $1, $1, 0x5C0
    r1 = RSP_ADD32(r1, 0X5C0);
L_132C:
    // beq         $22, $zero, L_1344
    if (r22 == 0) {
        // nop
    
        goto L_1344;
    }
    // nop

L_1334:
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
    // bne         $5, $zero, L_1334
    if (r5 != 0) {
        // nop
    
        goto L_1334;
    }
    // nop

    // and         $22, $zero, $zero
    r22 = 0 & 0;
L_1344:
    // lqv         $v1[0], 0x0($1)
    rsp.LQV<0>(rsp.vpu.r[1], r1, 0X0);
    // lqv         $v2[0], 0x0($2)
    rsp.LQV<0>(rsp.vpu.r[2], r2, 0X0);
    // ssv         $v1[0], 0x0($3)
    rsp.SSV<0>(rsp.vpu.r[1], r3, 0X0);
    // ssv         $v2[0], 0x2($3)
    rsp.SSV<0>(rsp.vpu.r[2], r3, 0X1);
    // ssv         $v1[2], 0x4($3)
    rsp.SSV<2>(rsp.vpu.r[1], r3, 0X2);
    // ssv         $v2[2], 0x6($3)
    rsp.SSV<2>(rsp.vpu.r[2], r3, 0X3);
    // ssv         $v1[4], 0x8($3)
    rsp.SSV<4>(rsp.vpu.r[1], r3, 0X4);
    // ssv         $v2[4], 0xA($3)
    rsp.SSV<4>(rsp.vpu.r[2], r3, 0X5);
    // ssv         $v1[6], 0xC($3)
    rsp.SSV<6>(rsp.vpu.r[1], r3, 0X6);
    // ssv         $v2[6], 0xE($3)
    rsp.SSV<6>(rsp.vpu.r[2], r3, 0X7);
    // ssv         $v1[8], 0x10($3)
    rsp.SSV<8>(rsp.vpu.r[1], r3, 0X8);
    // ssv         $v2[8], 0x12($3)
    rsp.SSV<8>(rsp.vpu.r[2], r3, 0X9);
    // ssv         $v1[10], 0x14($3)
    rsp.SSV<10>(rsp.vpu.r[1], r3, 0XA);
    // ssv         $v2[10], 0x16($3)
    rsp.SSV<10>(rsp.vpu.r[2], r3, 0XB);
    // ssv         $v1[12], 0x18($3)
    rsp.SSV<12>(rsp.vpu.r[1], r3, 0XC);
    // ssv         $v2[12], 0x1A($3)
    rsp.SSV<12>(rsp.vpu.r[2], r3, 0XD);
    // ssv         $v1[14], 0x1C($3)
    rsp.SSV<14>(rsp.vpu.r[1], r3, 0XE);
    // ssv         $v2[14], 0x1E($3)
    rsp.SSV<14>(rsp.vpu.r[2], r3, 0XF);
    // addi        $4, $4, -0x10
    r4 = RSP_ADD32(r4, -0X10);
L_1390:
    // addi        $1, $1, 0x10
    r1 = RSP_ADD32(r1, 0X10);
    // addi        $2, $2, 0x10
    r2 = RSP_ADD32(r2, 0X10);
    // bgtz        $4, L_1344
    if (RSP_SIGNED(r4) > 0) {
        // addi        $3, $3, 0x20
        r3 = RSP_ADD32(r3, 0X20);
        goto L_1344;
    }
    // addi        $3, $3, 0x20
    r3 = RSP_ADD32(r3, 0X20);
    // j           L_1118
    // nop

    goto L_1118;
    // nop

    // andi        $3, $25, 0xFFFF
    r3 = r25 & 0XFFFF;
    // beq         $3, $zero, L_1098
    if (r3 == 0) {
        // andi        $1, $26, 0xFFFF
        r1 = r26 & 0XFFFF;
        goto L_1098;
    }
    // andi        $1, $26, 0xFFFF
    r1 = r26 & 0XFFFF;
    // addi        $1, $1, 0x5C0
    r1 = RSP_ADD32(r1, 0X5C0);
    // srl         $2, $25, 16
    r2 = S32(U32(r25) >> 16);
    // addi        $2, $2, 0x5C0
    r2 = RSP_ADD32(r2, 0X5C0);
    // beq         $22, $zero, L_13D8
    if (r22 == 0) {
        // nop
    
        goto L_13D8;
    }
    // nop

L_13C8:
    // mfc0        $4, SP_DMA_BUSY
    r4 = 0;
    // bne         $4, $zero, L_13C8
    if (r4 != 0) {
        // nop
    
        goto L_13C8;
    }
    // nop

    // and         $22, $zero, $zero
    r22 = 0 & 0;
L_13D8:
    // ldv         $v1[0], 0x0($1)
    rsp.LDV<0>(rsp.vpu.r[1], r1, 0X0);
    // ldv         $v2[0], 0x8($1)
    rsp.LDV<0>(rsp.vpu.r[2], r1, 0X1);
    // addi        $3, $3, -0x10
    r3 = RSP_ADD32(r3, -0X10);
    // addi        $1, $1, 0x10
    r1 = RSP_ADD32(r1, 0X10);
    // sdv         $v1[0], 0x0($2)
    rsp.SDV<0>(rsp.vpu.r[1], r2, 0X0);
    // sdv         $v2[0], 0x8($2)
    rsp.SDV<0>(rsp.vpu.r[2], r2, 0X1);
    // bgtz        $3, L_13D8
    if (RSP_SIGNED(r3) > 0) {
        // addi        $2, $2, 0x10
        r2 = RSP_ADD32(r2, 0X10);
        goto L_13D8;
    }
    // addi        $2, $2, 0x10
    r2 = RSP_ADD32(r2, 0X10);
    // j           L_1118
    // nop

    goto L_1118;
    // nop

    // sll         $1, $25, 8
    r1 = S32(r25) << 8;
    // srl         $1, $1, 8
    r1 = S32(U32(r1) >> 8);
    // srl         $3, $25, 24
    r3 = S32(U32(r25) >> 24);
    // sll         $3, $3, 2
    r3 = S32(r3) << 2;
    // lw          $2, 0x320($3)
    r2 = RSP_MEM_W_LOAD(0X320, r3);
    // add         $1, $1, $2
    r1 = RSP_ADD32(r1, r2);
    // sw          $1, 0x10($24)
    RSP_MEM_W_STORE(0X10, r24, r1);
    // j           L_1118
    // nop

    goto L_1118;
    // nop

    // lqv         $v31[0], 0x0($zero)
    rsp.LQV<0>(rsp.vpu.r[31], 0, 0X0);
L_1428:
    // vxor        $v27, $v27, $v27
    rsp.VXOR<0>(rsp.vpu.r[27], rsp.vpu.r[27], rsp.vpu.r[27]);
    // lhu         $21, 0x0($24)
    r21 = RSP_MEM_HU_LOAD(0X0, r24);
    // vxor        $v25, $v25, $v25
    rsp.VXOR<0>(rsp.vpu.r[25], rsp.vpu.r[25], rsp.vpu.r[25]);
    // vxor        $v24, $v24, $v24
    rsp.VXOR<0>(rsp.vpu.r[24], rsp.vpu.r[24], rsp.vpu.r[24]);
    // addi        $20, $21, 0x1
    r20 = RSP_ADD32(r21, 0X1);
    // lhu         $19, 0x2($24)
    r19 = RSP_MEM_HU_LOAD(0X2, r24);
    // vxor        $v13, $v13, $v13
    rsp.VXOR<0>(rsp.vpu.r[13], rsp.vpu.r[13], rsp.vpu.r[13]);
    // vxor        $v14, $v14, $v14
    rsp.VXOR<0>(rsp.vpu.r[14], rsp.vpu.r[14], rsp.vpu.r[14]);
    // lhu         $18, 0x4($24)
    r18 = RSP_MEM_HU_LOAD(0X4, r24);
    // vxor        $v15, $v15, $v15
    rsp.VXOR<0>(rsp.vpu.r[15], rsp.vpu.r[15], rsp.vpu.r[15]);
    // lui         $1, 0xFF
    r1 = S32(0XFF << 16);
    // vxor        $v16, $v16, $v16
    rsp.VXOR<0>(rsp.vpu.r[16], rsp.vpu.r[16], rsp.vpu.r[16]);
    // ori         $1, $1, 0xFFFF
    r1 = r1 | 0XFFFF;
    // vxor        $v17, $v17, $v17
    rsp.VXOR<0>(rsp.vpu.r[17], rsp.vpu.r[17], rsp.vpu.r[17]);
    // and         $17, $25, $1
    r17 = r25 & r1;
    // vxor        $v18, $v18, $v18
    rsp.VXOR<0>(rsp.vpu.r[18], rsp.vpu.r[18], rsp.vpu.r[18]);
    // srl         $2, $25, 24
    r2 = S32(U32(r25) >> 24);
    // vxor        $v19, $v19, $v19
    rsp.VXOR<0>(rsp.vpu.r[19], rsp.vpu.r[19], rsp.vpu.r[19]);
    // sll         $2, $2, 2
    r2 = S32(r2) << 2;
    // lw          $3, 0x320($2)
    r3 = RSP_MEM_W_LOAD(0X320, r2);
    // add         $17, $17, $3
    r17 = RSP_ADD32(r17, r3);
    // sqv         $v27[0], 0x0($19)
    rsp.SQV<0>(rsp.vpu.r[27], r19, 0X0);
L_1480:
    // sqv         $v27[0], 0x10($19)
    rsp.SQV<0>(rsp.vpu.r[27], r19, 0X1);
    // srl         $1, $26, 16
    r1 = S32(U32(r26) >> 16);
    // andi        $1, $1, 0x1
    r1 = r1 & 0X1;
    // bgtz        $1, L_14C0
    if (RSP_SIGNED(r1) > 0) {
        // srl         $1, $26, 16
        r1 = S32(U32(r26) >> 16);
        goto L_14C0;
    }
    // srl         $1, $26, 16
    r1 = S32(U32(r26) >> 16);
    // andi        $1, $1, 0x2
    r1 = r1 & 0X2;
    // beq         $zero, $1, L_14A4
    if (0 == r1) {
        // addi        $2, $17, 0x0
        r2 = RSP_ADD32(r17, 0X0);
        goto L_14A4;
    }
    // addi        $2, $17, 0x0
    r2 = RSP_ADD32(r17, 0X0);
    // lw          $2, 0x10($24)
    r2 = RSP_MEM_W_LOAD(0X10, r24);
L_14A4:
    // addi        $1, $19, 0x0
    r1 = RSP_ADD32(r19, 0X0);
    // jal         0x1194
    r31 = 0x14B0;
    // addi        $3, $zero, 0x1F
    r3 = RSP_ADD32(0, 0X1F);
    goto L_1194;
    // addi        $3, $zero, 0x1F
    r3 = RSP_ADD32(0, 0X1F);
L_14B0:
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
    // bne         $5, $zero, L_14B0
    if (r5 != 0) {
        // nop
    
        goto L_14B0;
    }
    // nop

    // add         $22, $zero, $zero
    r22 = RSP_ADD32(0, 0);
L_14C0:
    // beq         $22, $zero, L_14D8
    if (r22 == 0) {
        // nop
    
        goto L_14D8;
    }
    // nop

L_14C8:
    // mfc0        $1, SP_DMA_BUSY
    r1 = 0;
    // bne         $1, $zero, L_14C8
    if (r1 != 0) {
        // nop
    
        goto L_14C8;
    }
    // nop

    // and         $22, $zero, $zero
    r22 = 0 & 0;
L_14D8:
    // addi        $16, $zero, 0x30
    r16 = RSP_ADD32(0, 0X30);
    // addi        $15, $zero, 0x4C0
    r15 = RSP_ADD32(0, 0X4C0);
    // ldv         $v25[0], 0x0($16)
    rsp.LDV<0>(rsp.vpu.r[25], r16, 0X0);
    // ldv         $v24[8], 0x0($16)
    rsp.LDV<8>(rsp.vpu.r[24], r16, 0X0);
    // ldv         $v23[0], 0x8($16)
    rsp.LDV<0>(rsp.vpu.r[23], r16, 0X1);
    // ldv         $v23[8], 0x8($16)
    rsp.LDV<8>(rsp.vpu.r[23], r16, 0X1);
    // lqv         $v27[0], 0x10($19)
    rsp.LQV<0>(rsp.vpu.r[27], r19, 0X1);
    // addi        $19, $19, 0x20
    r19 = RSP_ADD32(r19, 0X20);
    // beq         $18, $zero, L_16B4
    if (r18 == 0) {
        // ldv         $v1[0], 0x0($20)
        rsp.LDV<0>(rsp.vpu.r[1], r20, 0X0);
        goto L_16B4;
    }
    // ldv         $v1[0], 0x0($20)
    rsp.LDV<0>(rsp.vpu.r[1], r20, 0X0);
    // lbu         $1, 0x0($21)
    r1 = RSP_MEM_BU(0X0, r21);
    // andi        $11, $1, 0xF
    r11 = r1 & 0XF;
    // sll         $11, $11, 5
    r11 = S32(r11) << 5;
    // vand        $v3, $v25, $v1[0]
    rsp.VAND<8>(rsp.vpu.r[3], rsp.vpu.r[25], rsp.vpu.r[1]);
    // add         $13, $11, $15
    r13 = RSP_ADD32(r11, r15);
    // vand        $v4, $v24, $v1[1]
    rsp.VAND<9>(rsp.vpu.r[4], rsp.vpu.r[24], rsp.vpu.r[1]);
    // srl         $14, $1, 4
    r14 = S32(U32(r1) >> 4);
    // vand        $v5, $v25, $v1[2]
    rsp.VAND<10>(rsp.vpu.r[5], rsp.vpu.r[25], rsp.vpu.r[1]);
    // addi        $2, $zero, 0xC
    r2 = RSP_ADD32(0, 0XC);
    // vand        $v6, $v24, $v1[3]
    rsp.VAND<11>(rsp.vpu.r[6], rsp.vpu.r[24], rsp.vpu.r[1]);
    // sub         $14, $2, $14
    r14 = RSP_SUB32(r2, r14);
    // addi        $2, $14, -0x1
    r2 = RSP_ADD32(r14, -0X1);
    // addi        $3, $zero, 0x1
    r3 = RSP_ADD32(0, 0X1);
    // sll         $3, $3, 15
    r3 = S32(r3) << 15;
    // srlv        $4, $3, $2
    r4 = S32(U32(r3) >> (r2 & 31));
    // mtc2        $4, $v22[0]
    rsp.MTC2<0>(r4, rsp.vpu.r[22]);
    // lqv         $v21[0], 0x0($13)
    rsp.LQV<0>(rsp.vpu.r[21], r13, 0X0);
    // lqv         $v20[0], 0x10($13)
    rsp.LQV<0>(rsp.vpu.r[20], r13, 0X1);
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
    // lrv         $v19[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[19], r13, 0X2);
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
    // lrv         $v18[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[18], r13, 0X2);
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
    // lrv         $v17[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[17], r13, 0X2);
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
    // lrv         $v16[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[16], r13, 0X2);
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
    // lrv         $v15[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[15], r13, 0X2);
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
    // lrv         $v14[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[14], r13, 0X2);
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
    // lrv         $v13[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[13], r13, 0X2);
L_1580:
    // addi        $20, $20, 0x9
    r20 = RSP_ADD32(r20, 0X9);
    // vmudn       $v30, $v3, $v23
    rsp.VMUDN<0>(rsp.vpu.r[30], rsp.vpu.r[3], rsp.vpu.r[23]);
    // addi        $21, $21, 0x9
    r21 = RSP_ADD32(r21, 0X9);
    // vmadn       $v30, $v4, $v23
    rsp.VMADN<0>(rsp.vpu.r[30], rsp.vpu.r[4], rsp.vpu.r[23]);
    // ldv         $v1[0], 0x0($20)
    rsp.LDV<0>(rsp.vpu.r[1], r20, 0X0);
    // vmudn       $v29, $v5, $v23
    rsp.VMUDN<0>(rsp.vpu.r[29], rsp.vpu.r[5], rsp.vpu.r[23]);
    // lbu         $1, 0x0($21)
    r1 = RSP_MEM_BU(0X0, r21);
    // vmadn       $v29, $v6, $v23
    rsp.VMADN<0>(rsp.vpu.r[29], rsp.vpu.r[6], rsp.vpu.r[23]);
    // blez        $14, L_15B0
    if (RSP_SIGNED(r14) <= 0) {
        // andi        $11, $1, 0xF
        r11 = r1 & 0XF;
        goto L_15B0;
    }
    // andi        $11, $1, 0xF
    r11 = r1 & 0XF;
    // vmudm       $v30, $v30, $v22[0]
    rsp.VMUDM<8>(rsp.vpu.r[30], rsp.vpu.r[30], rsp.vpu.r[22]);
    // vmudm       $v29, $v29, $v22[0]
    rsp.VMUDM<8>(rsp.vpu.r[29], rsp.vpu.r[29], rsp.vpu.r[22]);
L_15B0:
    // sll         $11, $11, 5
    r11 = S32(r11) << 5;
    // vand        $v3, $v25, $v1[0]
    rsp.VAND<8>(rsp.vpu.r[3], rsp.vpu.r[25], rsp.vpu.r[1]);
    // add         $13, $11, $15
    r13 = RSP_ADD32(r11, r15);
    // vand        $v4, $v24, $v1[1]
    rsp.VAND<9>(rsp.vpu.r[4], rsp.vpu.r[24], rsp.vpu.r[1]);
    // vand        $v5, $v25, $v1[2]
    rsp.VAND<10>(rsp.vpu.r[5], rsp.vpu.r[25], rsp.vpu.r[1]);
    // vand        $v6, $v24, $v1[3]
    rsp.VAND<11>(rsp.vpu.r[6], rsp.vpu.r[24], rsp.vpu.r[1]);
    // srl         $14, $1, 4
    r14 = S32(U32(r1) >> 4);
    // vmudh       $v2, $v21, $v27[6]
    rsp.VMUDH<14>(rsp.vpu.r[2], rsp.vpu.r[21], rsp.vpu.r[27]);
    // addi        $2, $zero, 0xC
    r2 = RSP_ADD32(0, 0XC);
    // vmadh       $v2, $v20, $v27[7]
    rsp.VMADH<15>(rsp.vpu.r[2], rsp.vpu.r[20], rsp.vpu.r[27]);
    // sub         $14, $2, $14
    r14 = RSP_SUB32(r2, r14);
    // vmadh       $v2, $v19, $v30[0]
    rsp.VMADH<8>(rsp.vpu.r[2], rsp.vpu.r[19], rsp.vpu.r[30]);
    // addi        $2, $14, -0x1
    r2 = RSP_ADD32(r14, -0X1);
    // vmadh       $v2, $v18, $v30[1]
    rsp.VMADH<9>(rsp.vpu.r[2], rsp.vpu.r[18], rsp.vpu.r[30]);
    // addi        $3, $zero, 0x1
    r3 = RSP_ADD32(0, 0X1);
    // vmadh       $v2, $v17, $v30[2]
    rsp.VMADH<10>(rsp.vpu.r[2], rsp.vpu.r[17], rsp.vpu.r[30]);
    // sll         $3, $3, 15
    r3 = S32(r3) << 15;
    // vmadh       $v2, $v16, $v30[3]
    rsp.VMADH<11>(rsp.vpu.r[2], rsp.vpu.r[16], rsp.vpu.r[30]);
    // srlv        $4, $3, $2
    r4 = S32(U32(r3) >> (r2 & 31));
    // vmadh       $v28, $v15, $v30[4]
    rsp.VMADH<12>(rsp.vpu.r[28], rsp.vpu.r[15], rsp.vpu.r[30]);
    // mtc2        $4, $v22[0]
    rsp.MTC2<0>(r4, rsp.vpu.r[22]);
    // vmadh       $v2, $v14, $v30[5]
    rsp.VMADH<13>(rsp.vpu.r[2], rsp.vpu.r[14], rsp.vpu.r[30]);
    // vmadh       $v2, $v13, $v30[6]
    rsp.VMADH<14>(rsp.vpu.r[2], rsp.vpu.r[13], rsp.vpu.r[30]);
    // vmadh       $v2, $v30, $v31[5]
    rsp.VMADH<13>(rsp.vpu.r[2], rsp.vpu.r[30], rsp.vpu.r[31]);
    // vsar        $v26, $v7, $v28[1]
    rsp.VSAR<9>(rsp.vpu.r[26], rsp.vpu.r[7]);
    // vsar        $v28, $v7, $v28[0]
    rsp.VSAR<8>(rsp.vpu.r[28], rsp.vpu.r[7]);
    // vmudn       $v2, $v26, $v31[4]
    rsp.VMUDN<12>(rsp.vpu.r[2], rsp.vpu.r[26], rsp.vpu.r[31]);
    // vmadh       $v28, $v28, $v31[4]
    rsp.VMADH<12>(rsp.vpu.r[28], rsp.vpu.r[28], rsp.vpu.r[31]);
    // vmudh       $v2, $v19, $v29[0]
    rsp.VMUDH<8>(rsp.vpu.r[2], rsp.vpu.r[19], rsp.vpu.r[29]);
    // addi        $12, $13, -0x2
    r12 = RSP_ADD32(r13, -0X2);
    // vmadh       $v2, $v18, $v29[1]
    rsp.VMADH<9>(rsp.vpu.r[2], rsp.vpu.r[18], rsp.vpu.r[29]);
    // lrv         $v19[0], 0x20($12)
    rsp.LRV<0>(rsp.vpu.r[19], r12, 0X2);
    // vmadh       $v2, $v17, $v29[2]
    rsp.VMADH<10>(rsp.vpu.r[2], rsp.vpu.r[17], rsp.vpu.r[29]);
    // addi        $12, $12, -0x2
    r12 = RSP_ADD32(r12, -0X2);
    // vmadh       $v2, $v16, $v29[3]
    rsp.VMADH<11>(rsp.vpu.r[2], rsp.vpu.r[16], rsp.vpu.r[29]);
    // lrv         $v18[0], 0x20($12)
    rsp.LRV<0>(rsp.vpu.r[18], r12, 0X2);
    // vmadh       $v2, $v15, $v29[4]
    rsp.VMADH<12>(rsp.vpu.r[2], rsp.vpu.r[15], rsp.vpu.r[29]);
    // addi        $12, $12, -0x2
    r12 = RSP_ADD32(r12, -0X2);
    // vmadh       $v2, $v14, $v29[5]
    rsp.VMADH<13>(rsp.vpu.r[2], rsp.vpu.r[14], rsp.vpu.r[29]);
    // lrv         $v17[0], 0x20($12)
    rsp.LRV<0>(rsp.vpu.r[17], r12, 0X2);
    // vmadh       $v2, $v13, $v29[6]
    rsp.VMADH<14>(rsp.vpu.r[2], rsp.vpu.r[13], rsp.vpu.r[29]);
    // addi        $12, $12, -0x2
    r12 = RSP_ADD32(r12, -0X2);
    // vmadh       $v2, $v29, $v31[5]
    rsp.VMADH<13>(rsp.vpu.r[2], rsp.vpu.r[29], rsp.vpu.r[31]);
    // lrv         $v16[0], 0x20($12)
    rsp.LRV<0>(rsp.vpu.r[16], r12, 0X2);
    // vmadh       $v2, $v21, $v28[6]
    rsp.VMADH<14>(rsp.vpu.r[2], rsp.vpu.r[21], rsp.vpu.r[28]);
    // addi        $12, $12, -0x2
    r12 = RSP_ADD32(r12, -0X2);
    // vmadh       $v2, $v20, $v28[7]
    rsp.VMADH<15>(rsp.vpu.r[2], rsp.vpu.r[20], rsp.vpu.r[28]);
    // lrv         $v15[0], 0x20($12)
    rsp.LRV<0>(rsp.vpu.r[15], r12, 0X2);
    // vsar        $v26, $v7, $v27[1]
    rsp.VSAR<9>(rsp.vpu.r[26], rsp.vpu.r[7]);
    // addi        $12, $12, -0x2
    r12 = RSP_ADD32(r12, -0X2);
    // vsar        $v27, $v7, $v27[0]
    rsp.VSAR<8>(rsp.vpu.r[27], rsp.vpu.r[7]);
    // lrv         $v14[0], 0x20($12)
    rsp.LRV<0>(rsp.vpu.r[14], r12, 0X2);
    // addi        $12, $12, -0x2
    r12 = RSP_ADD32(r12, -0X2);
    // lrv         $v13[0], 0x20($12)
    rsp.LRV<0>(rsp.vpu.r[13], r12, 0X2);
    // lqv         $v21[0], 0x0($13)
    rsp.LQV<0>(rsp.vpu.r[21], r13, 0X0);
    // vmudn       $v2, $v26, $v31[4]
    rsp.VMUDN<12>(rsp.vpu.r[2], rsp.vpu.r[26], rsp.vpu.r[31]);
    // lqv         $v20[0], 0x10($13)
    rsp.LQV<0>(rsp.vpu.r[20], r13, 0X1);
    // vmadh       $v27, $v27, $v31[4]
    rsp.VMADH<12>(rsp.vpu.r[27], rsp.vpu.r[27], rsp.vpu.r[31]);
    // addi        $18, $18, -0x20
    r18 = RSP_ADD32(r18, -0X20);
    // sdv         $v28[0], 0x0($19)
    rsp.SDV<0>(rsp.vpu.r[28], r19, 0X0);
    // sdv         $v28[8], 0x8($19)
    rsp.SDV<8>(rsp.vpu.r[28], r19, 0X1);
    // sdv         $v27[0], 0x10($19)
    rsp.SDV<0>(rsp.vpu.r[27], r19, 0X2);
    // sdv         $v27[8], 0x18($19)
    rsp.SDV<8>(rsp.vpu.r[27], r19, 0X3);
    // bgtz        $18, L_1580
    if (RSP_SIGNED(r18) > 0) {
        // addi        $19, $19, 0x20
        r19 = RSP_ADD32(r19, 0X20);
        goto L_1580;
    }
    // addi        $19, $19, 0x20
    r19 = RSP_ADD32(r19, 0X20);
L_16B4:
    // addi        $1, $19, -0x20
    r1 = RSP_ADD32(r19, -0X20);
    // addi        $2, $17, 0x0
    r2 = RSP_ADD32(r17, 0X0);
    // jal         0x11C0
    r31 = 0x16C4;
    // addi        $3, $zero, 0x1F
    r3 = RSP_ADD32(0, 0X1F);
    goto L_11C0;
    // addi        $3, $zero, 0x1F
    r3 = RSP_ADD32(0, 0X1F);
L_16C4:
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
    // bne         $5, $zero, L_16C4
    if (r5 != 0) {
        // nop
    
        goto L_16C4;
    }
    // nop

    // j           L_1118
    // and         $22, $zero, $zero
    r22 = 0 & 0;
    goto L_1118;
    // and         $22, $zero, $zero
    r22 = 0 & 0;
    // [PATCH] This block was dead code (unreachable after the goto above).
    // It's the setup phase for A_POLEF/A_RESAMPLE that initializes r20, r21, r19
    // from DMEM parameters. Without this, the POLEF handler uses uninitialized
    // r20 as an output buffer address and overwrites the dispatch table at DMEM[0x10].
    // We add a label so L_1758 can jump here.
L_POLEF_SETUP:
    // lqv         $v31[0], 0x0($zero)
    rsp.LQV<0>(rsp.vpu.r[31], 0, 0X0);
    // vxor        $v28, $v28, $v28
    rsp.VXOR<0>(rsp.vpu.r[28], rsp.vpu.r[28], rsp.vpu.r[28]);
    // lhu         $21, 0x0($24)
    // [PATCH] Read from SETBUFF bank (r24+0x10) instead of SAVEBUFF bank (r24+0).
    // A_SETBUFF (L_12F0) stores dmemin at DMEM[r24+0x10] and count at DMEM[r24+0x14].
    // POLEF is always in-place (dmemin == dmemout), so r21 = r20 = dmemin.
    r21 = RSP_MEM_HU_LOAD(0X10, r24);
    // vxor        $v17, $v17, $v17
    rsp.VXOR<0>(rsp.vpu.r[17], rsp.vpu.r[17], rsp.vpu.r[17]);
    // lhu         $20, 0x2($24)
    r20 = RSP_MEM_HU_LOAD(0X10, r24);
    // vxor        $v18, $v18, $v18
    rsp.VXOR<0>(rsp.vpu.r[18], rsp.vpu.r[18], rsp.vpu.r[18]);
    // lhu         $19, 0x4($24)
    r19 = RSP_MEM_HU_LOAD(0X14, r24);
    // vxor        $v19, $v19, $v19
    rsp.VXOR<0>(rsp.vpu.r[19], rsp.vpu.r[19], rsp.vpu.r[19]);
    // beq         $19, $zero, L_184C
    if (r19 == 0) {
        // andi        $14, $26, 0xFFFF
        r14 = r26 & 0XFFFF;
        goto L_184C;
    }
    // andi        $14, $26, 0xFFFF
    r14 = r26 & 0XFFFF;
    // mtc2        $14, $v31[10]
    rsp.MTC2<10>(r14, rsp.vpu.r[31]);
    // sll         $14, $14, 2
    r14 = S32(r14) << 2;
    // mtc2        $14, $v16[0]
    rsp.MTC2<0>(r14, rsp.vpu.r[16]);
    // lui         $1, 0xFF
    r1 = S32(0XFF << 16);
    // vxor        $v20, $v20, $v20
    rsp.VXOR<0>(rsp.vpu.r[20], rsp.vpu.r[20], rsp.vpu.r[20]);
    // ori         $1, $1, 0xFFFF
    r1 = r1 | 0XFFFF;
    // vxor        $v21, $v21, $v21
    rsp.VXOR<0>(rsp.vpu.r[21], rsp.vpu.r[21], rsp.vpu.r[21]);
    // and         $18, $25, $1
    r18 = r25 & r1;
    // vxor        $v22, $v22, $v22
    rsp.VXOR<0>(rsp.vpu.r[22], rsp.vpu.r[22], rsp.vpu.r[22]);
    // srl         $2, $25, 24
    r2 = S32(U32(r25) >> 24);
    // vxor        $v23, $v23, $v23
    rsp.VXOR<0>(rsp.vpu.r[23], rsp.vpu.r[23], rsp.vpu.r[23]);
    // sll         $2, $2, 2
    r2 = S32(r2) << 2;
    // lw          $3, 0x320($2)
    r3 = RSP_MEM_W_LOAD(0X320, r2);
    // add         $18, $18, $3
    r18 = RSP_ADD32(r18, r3);
    // slv         $v28[0], 0x0($23)
    rsp.SLV<0>(rsp.vpu.r[28], r23, 0X0);
    // srl         $1, $26, 16
    r1 = S32(U32(r26) >> 16);
    // andi        $1, $1, 0x1
    r1 = r1 & 0X1;
    // bgtz        $1, L_176C
    if (RSP_SIGNED(r1) > 0) {
        // nop
    
        goto L_176C;
    }
    // nop

    // addi        $1, $23, 0x0
    r1 = RSP_ADD32(r23, 0X0);
    // addi        $2, $18, 0x0
    r2 = RSP_ADD32(r18, 0X0);
    // jal         0x1194
    r31 = 0x175C;
    // addi        $3, $zero, 0x7
    r3 = RSP_ADD32(0, 0X7);
    goto L_1194;
L_1758:
    // [PATCH] On real RSP, setup code at IMEM ~0x1318 runs before the POLEF handler
    // to initialize r20/r21/r19 from DMEM parameters and load filter state via DMA.
    // In the recomp, that code is unreachable dead code. We redirect here so it runs.
    // The setup code either:
    //   - Calls L_1194 for DMA and returns to L_175C (first frame)
    //   - Jumps to L_176C directly (continuation frame)
    goto L_POLEF_SETUP;
    // addi        $3, $zero, 0x7
    r3 = RSP_ADD32(0, 0X7);
L_175C:
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
    // bne         $5, $zero, L_175C
    if (r5 != 0) {
        // nop
    
        goto L_175C;
    }
    // nop

    // add         $22, $zero, $zero
    r22 = RSP_ADD32(0, 0);
L_176C:
    // beq         $22, $zero, L_1784
    if (r22 == 0) {
        // nop
    
        goto L_1784;
    }
    // nop

L_1774:
    // mfc0        $1, SP_DMA_BUSY
    r1 = 0;
    // bne         $1, $zero, L_1774
    if (r1 != 0) {
        // nop
    
        goto L_1774;
    }
    // nop

    // add         $22, $zero, $zero
    r22 = RSP_ADD32(0, 0);
L_1784:
    // addi        $13, $zero, 0x4C0
    r13 = RSP_ADD32(0, 0X4C0);
    // addi        $1, $zero, 0x4
    r1 = RSP_ADD32(0, 0X4);
    // mtc2        $1, $v14[0]
    rsp.MTC2<0>(r1, rsp.vpu.r[14]);
    // lqv         $v24[0], 0x10($13)
    rsp.LQV<0>(rsp.vpu.r[24], r13, 0X1);
    // vmudm       $v16, $v24, $v16[0]
    rsp.VMUDM<8>(rsp.vpu.r[16], rsp.vpu.r[24], rsp.vpu.r[16]);
    // ldv         $v28[8], 0x0($23)
    rsp.LDV<8>(rsp.vpu.r[28], r23, 0X0);
    // sqv         $v16[0], 0x10($13)
    rsp.SQV<0>(rsp.vpu.r[16], r13, 0X1);
    // lqv         $v25[0], 0x0($13)
    rsp.LQV<0>(rsp.vpu.r[25], r13, 0X0);
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
    // lrv         $v23[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[23], r13, 0X2);
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
    // lrv         $v22[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[22], r13, 0X2);
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
    // lrv         $v21[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[21], r13, 0X2);
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
    // lrv         $v20[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[20], r13, 0X2);
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
    // lrv         $v19[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[19], r13, 0X2);
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
    // lrv         $v18[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[18], r13, 0X2);
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
    // lrv         $v17[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[17], r13, 0X2);
    // ldv         $v30[0], 0x0($21)
    rsp.LDV<0>(rsp.vpu.r[30], r21, 0X0);
    // ldv         $v30[8], 0x8($21)
    rsp.LDV<8>(rsp.vpu.r[30], r21, 0X1);
L_17E4:
    // vmudh       $v16, $v25, $v28[6]
    rsp.VMUDH<14>(rsp.vpu.r[16], rsp.vpu.r[25], rsp.vpu.r[28]);
    // addi        $21, $21, 0x10
    r21 = RSP_ADD32(r21, 0X10);
    // vmadh       $v16, $v24, $v28[7]
    rsp.VMADH<15>(rsp.vpu.r[16], rsp.vpu.r[24], rsp.vpu.r[28]);
    // addi        $19, $19, -0x10
    r19 = RSP_ADD32(r19, -0X10);
    // vmadh       $v16, $v23, $v30[0]
    rsp.VMADH<8>(rsp.vpu.r[16], rsp.vpu.r[23], rsp.vpu.r[30]);
    // vmadh       $v16, $v22, $v30[1]
    rsp.VMADH<9>(rsp.vpu.r[16], rsp.vpu.r[22], rsp.vpu.r[30]);
    // vmadh       $v16, $v21, $v30[2]
    rsp.VMADH<10>(rsp.vpu.r[16], rsp.vpu.r[21], rsp.vpu.r[30]);
    // vmadh       $v16, $v20, $v30[3]
    rsp.VMADH<11>(rsp.vpu.r[16], rsp.vpu.r[20], rsp.vpu.r[30]);
    // vmadh       $v28, $v19, $v30[4]
    rsp.VMADH<12>(rsp.vpu.r[28], rsp.vpu.r[19], rsp.vpu.r[30]);
    // vmadh       $v16, $v18, $v30[5]
    rsp.VMADH<13>(rsp.vpu.r[16], rsp.vpu.r[18], rsp.vpu.r[30]);
    // vmadh       $v16, $v17, $v30[6]
    rsp.VMADH<14>(rsp.vpu.r[16], rsp.vpu.r[17], rsp.vpu.r[30]);
    // vmadh       $v16, $v30, $v31[5]
    rsp.VMADH<13>(rsp.vpu.r[16], rsp.vpu.r[30], rsp.vpu.r[31]);
    // ldv         $v30[0], 0x0($21)
    rsp.LDV<0>(rsp.vpu.r[30], r21, 0X0);
    // vsar        $v26, $v15, $v28[1]
    rsp.VSAR<9>(rsp.vpu.r[26], rsp.vpu.r[15]);
    // ldv         $v30[8], 0x8($21)
    rsp.LDV<8>(rsp.vpu.r[30], r21, 0X1);
    // vsar        $v28, $v15, $v28[0]
    rsp.VSAR<8>(rsp.vpu.r[28], rsp.vpu.r[15]);
    // vmudn       $v16, $v26, $v14[0]
    rsp.VMUDN<8>(rsp.vpu.r[16], rsp.vpu.r[26], rsp.vpu.r[14]);
    // vmadh       $v28, $v28, $v14[0]
    rsp.VMADH<8>(rsp.vpu.r[28], rsp.vpu.r[28], rsp.vpu.r[14]);
    // sdv         $v28[0], 0x0($20)
    rsp.SDV<0>(rsp.vpu.r[28], r20, 0X0);
    // sdv         $v28[8], 0x8($20)
    rsp.SDV<8>(rsp.vpu.r[28], r20, 0X1);
    // bgtz        $19, L_17E4
    if (RSP_SIGNED(r19) > 0) {
        // addi        $20, $20, 0x10
        r20 = RSP_ADD32(r20, 0X10);
        goto L_17E4;
    }
    // addi        $20, $20, 0x10
    r20 = RSP_ADD32(r20, 0X10);
    // addi        $1, $20, -0x8
    r1 = RSP_ADD32(r20, -0X8);
    // addi        $2, $18, 0x0
    r2 = RSP_ADD32(r18, 0X0);
    // jal         0x11C0
    r31 = 0x184C;
    // addi        $3, $zero, 0x7
    r3 = RSP_ADD32(0, 0X7);
    goto L_11C0;
    // addi        $3, $zero, 0x7
    r3 = RSP_ADD32(0, 0X7);
L_184C:
    // j           L_1118
    // nop

    goto L_1118;
    // nop

    // [PATCH] This block was dead code (unreachable after the goto above).
    // It's the setup phase for A_RESAMPLE that initializes r8, r19, r18
    // from DMEM parameters and loads resampler state from DRAM.
    // We add a label so L_18D4 can jump here.
L_RESAMPLE_SETUP:
    {
        static int resample_trace = 0;
        resample_trace++;
        if (resample_trace <= 30) {
            fprintf(stderr, "[R10-TRACE] RESAMPLE_SETUP #%d: r10=%d r7=0x%X w0=0x%08X (t%d cmd#%d)\n",
                    resample_trace, r10, r7, r26, asp_task_id, asp_cmd_count);
            fflush(stderr);
        }
    }
    // lh          $8, 0x0($24)
    r8 = RSP_MEM_H_LOAD(0X0, r24);
    // lh          $19, 0x2($24)
    r19 = RSP_MEM_H_LOAD(0X2, r24);
    // lh          $18, 0x4($24)
    r18 = RSP_MEM_H_LOAD(0X4, r24);
    // lui         $4, 0xFF
    r4 = S32(0XFF << 16);
    // ori         $4, $4, 0xFFFF
    r4 = r4 | 0XFFFF;
    // and         $2, $25, $4
    r2 = r25 & r4;
    // srl         $5, $25, 24
    r5 = S32(U32(r25) >> 24);
    // sll         $5, $5, 2
    r5 = S32(r5) << 2;
    // lw          $6, 0x320($5)
    r6 = RSP_MEM_W_LOAD(0X320, r5);
    // add         $2, $2, $6
    r2 = RSP_ADD32(r2, r6);
    // addi        $1, $23, 0x0
    r1 = RSP_ADD32(r23, 0X0);
    // sw          $2, 0x40($23)
    RSP_MEM_W_STORE(0X40, r23, r2);
    // addi        $3, $zero, 0x1F
    r3 = RSP_ADD32(0, 0X1F);
    // srl         $7, $26, 16
    r7 = S32(U32(r26) >> 16);
    // andi        $10, $7, 0x1
    r10 = r7 & 0X1;
    // bgtz        $10, L_18B8
    if (RSP_SIGNED(r10) > 0) {
        // nop

        goto L_18B8;
    }
    // nop

    // jal         0x1194
    r31 = 0x18A0;
    // add         $10, $zero, $7
    r10 = RSP_ADD32(0, r7);
    goto L_1194;
    // add         $10, $zero, $7
    r10 = RSP_ADD32(0, r7);
L_18A0:
    // add         $7, $zero, $10
    r7 = RSP_ADD32(0, r10);
L_18A4:
    // mfc0        $1, SP_DMA_BUSY
    r1 = 0;
    // bne         $1, $zero, L_18A4
    if (r1 != 0) {
        // nop
    
        goto L_18A4;
    }
    // nop

    // j           L_195C
    // add         $22, $zero, $zero
    r22 = RSP_ADD32(0, 0);
    goto L_195C;
    // add         $22, $zero, $zero
    r22 = RSP_ADD32(0, 0);
L_18B8:
    // beq         $22, $zero, L_18D0
    if (r22 == 0) {
        // nop
    
        goto L_18D0;
    }
    // nop

L_18C0:
    // mfc0        $10, SP_DMA_BUSY
    r10 = 0;
    // bne         $10, $zero, L_18C0
    if (r10 != 0) {
        // nop
    
        goto L_18C0;
    }
    // nop

    // and         $22, $zero, $zero
    r22 = 0 & 0;
L_18D0:
    // sh          $zero, 0x8($23)
    RSP_MEM_H_STORE(0X8, r23, 0);
    // [PATCH] Jump to handler body, NOT to L_18D4 which redirects to setup.
    // On real RSP, L_18D0 falls through to L_18D4 which IS the handler body.
    // In the recomp, L_18D4 redirects to L_RESAMPLE_SETUP (for first-time init).
    // Re-entering setup from L_18D0 creates an infinite loop, so skip to the body.
    goto L_18D4_BODY;
L_18D4:
    // [PATCH] On real RSP, setup code at IMEM ~0x1854 runs before the RESAMPLE handler
    // to initialize r8/r19/r18 from DMEM parameters and load resampler state via DMA.
    // In the recomp, that code is unreachable dead code. We redirect here so it runs.
    // After setup, control flows through L_18B8 → L_18D0 → L_18D4_BODY (not back here).
    goto L_RESAMPLE_SETUP;
L_18D4_BODY:
    {
        static int body_trace = 0;
        body_trace++;
        if (body_trace <= 30) {
            fprintf(stderr, "[R10-TRACE] L_18D4_BODY #%d: r10=%d r7=0x%X r22=0x%X (t%d cmd#%d)\n",
                    body_trace, r10, r7, r22, asp_task_id, asp_cmd_count);
            fflush(stderr);
        }
    }
    // Original handler body: clear state, check bit 1 of r7 for state restore
    // vxor        $v16, $v16, $v16
    rsp.VXOR<0>(rsp.vpu.r[16], rsp.vpu.r[16], rsp.vpu.r[16]);
    // sdv         $v16[0], 0x0($23)
    rsp.SDV<0>(rsp.vpu.r[16], r23, 0X0);
    // andi        $10, $7, 0x2
    r10 = r7 & 0X2;
    // beq         $10, $zero, L_18FC
    if (r10 == 0) {
        // nop

        goto L_18FC;
    }
    // nop

    // lh          $11, 0xA($23)
    r11 = RSP_MEM_H_LOAD(0XA, r23);
    // lqv         $v3[0], 0x10($23)
    rsp.LQV<0>(rsp.vpu.r[3], r23, 0X1);
    // sdv         $v3[0], 0x3F0($8)
    rsp.SDV<0>(rsp.vpu.r[3], r8, -0X2);
    // sdv         $v3[8], 0x3F8($8)
    rsp.SDV<8>(rsp.vpu.r[3], r8, -0X1);
    // sub         $8, $8, $11
    r8 = RSP_SUB32(r8, r11);
L_18FC:
    // addi        $8, $8, -0x8
    r8 = RSP_ADD32(r8, -0X8);
    // lsv         $v23[14], 0x8($23)
    rsp.LSV<14>(rsp.vpu.r[23], r23, 0X4);
    // ldv         $v16[0], 0x0($23)
    rsp.LDV<0>(rsp.vpu.r[16], r23, 0X0);
    // sdv         $v16[0], 0x0($8)
    rsp.SDV<0>(rsp.vpu.r[16], r8, 0X0);
    // mtc2        $8, $v18[4]
    rsp.MTC2<4>(r8, rsp.vpu.r[18]);
    // addi        $10, $zero, 0xD0
    r10 = RSP_ADD32(0, 0XD0);
    // mtc2        $10, $v18[6]
    rsp.MTC2<6>(r10, rsp.vpu.r[18]);
    // mtc2        $26, $v18[8]
    rsp.MTC2<8>(r26, rsp.vpu.r[18]);
    // addi        $10, $zero, 0x40
    r10 = RSP_ADD32(0, 0X40);
    // mtc2        $10, $v18[10]
    rsp.MTC2<10>(r10, rsp.vpu.r[18]);
    {
        static int r10set_trace = 0;
        r10set_trace++;
        if (r10set_trace <= 10) {
            fprintf(stderr, "[R10-TRACE] r10 SET TO 0x40 #%d (t%d cmd#%d)\n",
                    r10set_trace, asp_task_id, asp_cmd_count);
            fflush(stderr);
        }
    }
    // addi        $9, $zero, 0x50
    r9 = RSP_ADD32(0, 0X50);
    // lqv         $v31[0], 0x10($9)
    rsp.LQV<0>(rsp.vpu.r[31], r9, 0X1);
    // lqv         $v25[0], 0x0($9)
    rsp.LQV<0>(rsp.vpu.r[25], r9, 0X0);
    // vsub        $v25, $v25, $v31
    rsp.VSUB<0>(rsp.vpu.r[25], rsp.vpu.r[25], rsp.vpu.r[31]);
    // lqv         $v30[0], 0x20($9)
    rsp.LQV<0>(rsp.vpu.r[30], r9, 0X2);
    // lqv         $v29[0], 0x30($9)
    rsp.LQV<0>(rsp.vpu.r[29], r9, 0X3);
    // lqv         $v28[0], 0x40($9)
    rsp.LQV<0>(rsp.vpu.r[28], r9, 0X4);
    // lqv         $v27[0], 0x50($9)
    rsp.LQV<0>(rsp.vpu.r[27], r9, 0X5);
    // lqv         $v26[0], 0x60($9)
    rsp.LQV<0>(rsp.vpu.r[26], r9, 0X6);
    // vsub        $v25, $v25, $v31
    rsp.VSUB<0>(rsp.vpu.r[25], rsp.vpu.r[25], rsp.vpu.r[31]);
    // lqv         $v24[0], 0x70($9)
    rsp.LQV<0>(rsp.vpu.r[24], r9, 0X7);
    // addi        $21, $23, 0x20
    r21 = RSP_ADD32(r23, 0X20);
    // addi        $20, $23, 0x30
    r20 = RSP_ADD32(r23, 0X30);
    // vxor        $v22, $v22, $v22
    rsp.VXOR<0>(rsp.vpu.r[22], rsp.vpu.r[22], rsp.vpu.r[22]);
L_195C:
    // vmudm       $v23, $v31, $v23[7]
    rsp.VMUDM<15>(rsp.vpu.r[23], rsp.vpu.r[31], rsp.vpu.r[23]);
    // vmadm       $v22, $v25, $v18[4]
    rsp.VMADM<12>(rsp.vpu.r[22], rsp.vpu.r[25], rsp.vpu.r[18]);
    // vmadn       $v23, $v31, $v30[0]
    rsp.VMADN<8>(rsp.vpu.r[23], rsp.vpu.r[31], rsp.vpu.r[30]);
    // vmudn       $v21, $v31, $v18[2]
    rsp.VMUDN<10>(rsp.vpu.r[21], rsp.vpu.r[31], rsp.vpu.r[18]);
    // vmadn       $v21, $v22, $v30[2]
    rsp.VMADN<10>(rsp.vpu.r[21], rsp.vpu.r[22], rsp.vpu.r[30]);
    // vmudl       $v17, $v23, $v18[5]
    rsp.VMUDL<13>(rsp.vpu.r[17], rsp.vpu.r[23], rsp.vpu.r[18]);
    // vmudn       $v17, $v17, $v30[4]
    rsp.VMUDN<12>(rsp.vpu.r[17], rsp.vpu.r[17], rsp.vpu.r[30]);
    // vmadn       $v17, $v31, $v18[3]
    rsp.VMADN<11>(rsp.vpu.r[17], rsp.vpu.r[31], rsp.vpu.r[18]);
    // lqv         $v25[0], 0x0($9)
    rsp.LQV<0>(rsp.vpu.r[25], r9, 0X0);
    // sqv         $v21[0], 0x0($21)
    rsp.SQV<0>(rsp.vpu.r[21], r21, 0X0);
    // sqv         $v17[0], 0x0($20)
    rsp.SQV<0>(rsp.vpu.r[17], r20, 0X0);
    // ssv         $v23[7], 0x8($23)
    rsp.SSV<7>(rsp.vpu.r[23], r23, 0X4);
    // lh          $17, 0x0($21)
    r17 = RSP_MEM_H_LOAD(0X0, r21);
    // lh          $9, 0x0($20)
    r9 = RSP_MEM_H_LOAD(0X0, r20);
    // lh          $13, 0x8($21)
    r13 = RSP_MEM_H_LOAD(0X8, r21);
    // lh          $5, 0x8($20)
    r5 = RSP_MEM_H_LOAD(0X8, r20);
    // lh          $16, 0x2($21)
    r16 = RSP_MEM_H_LOAD(0X2, r21);
    // lh          $8, 0x2($20)
    r8 = RSP_MEM_H_LOAD(0X2, r20);
    // lh          $12, 0xA($21)
    r12 = RSP_MEM_H_LOAD(0XA, r21);
    // lh          $4, 0xA($20)
    r4 = RSP_MEM_H_LOAD(0XA, r20);
    // lh          $15, 0x4($21)
    r15 = RSP_MEM_H_LOAD(0X4, r21);
    // lh          $7, 0x4($20)
    r7 = RSP_MEM_H_LOAD(0X4, r20);
    // lh          $11, 0xC($21)
    r11 = RSP_MEM_H_LOAD(0XC, r21);
    // lh          $3, 0xC($20)
    r3 = RSP_MEM_H_LOAD(0XC, r20);
    // lh          $14, 0x6($21)
    r14 = RSP_MEM_H_LOAD(0X6, r21);
    // lh          $6, 0x6($20)
    r6 = RSP_MEM_H_LOAD(0X6, r20);
    // lh          $10, 0xE($21)
    r10 = RSP_MEM_H_LOAD(0XE, r21);
    // lh          $2, 0xE($20)
    r2 = RSP_MEM_H_LOAD(0XE, r20);
    // ldv         $v16[0], 0x0($17)
    rsp.LDV<0>(rsp.vpu.r[16], r17, 0X0);
    // vmudm       $v23, $v31, $v23[7]
    rsp.VMUDM<15>(rsp.vpu.r[23], rsp.vpu.r[31], rsp.vpu.r[23]);
    // ldv         $v15[0], 0x0($9)
    rsp.LDV<0>(rsp.vpu.r[15], r9, 0X0);
    // vmadh       $v23, $v31, $v22[7]
    rsp.VMADH<15>(rsp.vpu.r[23], rsp.vpu.r[31], rsp.vpu.r[22]);
    // ldv         $v16[8], 0x0($13)
    rsp.LDV<8>(rsp.vpu.r[16], r13, 0X0);
    // vmadm       $v22, $v25, $v18[4]
    rsp.VMADM<12>(rsp.vpu.r[22], rsp.vpu.r[25], rsp.vpu.r[18]);
    // ldv         $v15[8], 0x0($5)
    rsp.LDV<8>(rsp.vpu.r[15], r5, 0X0);
    // vmadn       $v23, $v31, $v30[0]
    rsp.VMADN<8>(rsp.vpu.r[23], rsp.vpu.r[31], rsp.vpu.r[30]);
    // ldv         $v14[0], 0x0($16)
    rsp.LDV<0>(rsp.vpu.r[14], r16, 0X0);
    // vmudn       $v21, $v31, $v18[2]
    rsp.VMUDN<10>(rsp.vpu.r[21], rsp.vpu.r[31], rsp.vpu.r[18]);
    // ldv         $v13[0], 0x0($8)
    rsp.LDV<0>(rsp.vpu.r[13], r8, 0X0);
    // vmadn       $v21, $v22, $v30[2]
    rsp.VMADN<10>(rsp.vpu.r[21], rsp.vpu.r[22], rsp.vpu.r[30]);
    // ldv         $v14[8], 0x0($12)
    rsp.LDV<8>(rsp.vpu.r[14], r12, 0X0);
    // vmudl       $v17, $v23, $v18[5]
    rsp.VMUDL<13>(rsp.vpu.r[17], rsp.vpu.r[23], rsp.vpu.r[18]);
    // ldv         $v13[8], 0x0($4)
    rsp.LDV<8>(rsp.vpu.r[13], r4, 0X0);
    // ldv         $v12[0], 0x0($15)
    rsp.LDV<0>(rsp.vpu.r[12], r15, 0X0);
    // ldv         $v11[0], 0x0($7)
    rsp.LDV<0>(rsp.vpu.r[11], r7, 0X0);
    // ldv         $v12[8], 0x0($11)
    rsp.LDV<8>(rsp.vpu.r[12], r11, 0X0);
    // vmudn       $v17, $v17, $v30[4]
    rsp.VMUDN<12>(rsp.vpu.r[17], rsp.vpu.r[17], rsp.vpu.r[30]);
    // ldv         $v11[8], 0x0($3)
    rsp.LDV<8>(rsp.vpu.r[11], r3, 0X0);
    // ldv         $v10[0], 0x0($14)
    rsp.LDV<0>(rsp.vpu.r[10], r14, 0X0);
    // ldv         $v9[0], 0x0($6)
    rsp.LDV<0>(rsp.vpu.r[9], r6, 0X0);
    // vmadn       $v17, $v31, $v18[3]
    rsp.VMADN<11>(rsp.vpu.r[17], rsp.vpu.r[31], rsp.vpu.r[18]);
    // ldv         $v10[8], 0x0($10)
    rsp.LDV<8>(rsp.vpu.r[10], r10, 0X0);
    // vmulf       $v8, $v16, $v15
    rsp.VMULF<0>(rsp.vpu.r[8], rsp.vpu.r[16], rsp.vpu.r[15]);
    // ldv         $v9[8], 0x0($2)
    rsp.LDV<8>(rsp.vpu.r[9], r2, 0X0);
    // vmulf       $v7, $v14, $v13
    rsp.VMULF<0>(rsp.vpu.r[7], rsp.vpu.r[14], rsp.vpu.r[13]);
    // sqv         $v21[0], 0x0($21)
    rsp.SQV<0>(rsp.vpu.r[21], r21, 0X0);
    // vmulf       $v6, $v12, $v11
    rsp.VMULF<0>(rsp.vpu.r[6], rsp.vpu.r[12], rsp.vpu.r[11]);
    // sqv         $v17[0], 0x0($20)
    rsp.SQV<0>(rsp.vpu.r[17], r20, 0X0);
    // lh          $17, 0x0($21)
    r17 = RSP_MEM_H_LOAD(0X0, r21);
    // vmulf       $v5, $v10, $v9
    rsp.VMULF<0>(rsp.vpu.r[5], rsp.vpu.r[10], rsp.vpu.r[9]);
L_1A4C:
    // lh          $9, 0x0($20)
    r9 = RSP_MEM_H_LOAD(0X0, r20);
    // vadd        $v8, $v8, $v8[1q]
    rsp.VADD<3>(rsp.vpu.r[8], rsp.vpu.r[8], rsp.vpu.r[8]);
    // lh          $13, 0x8($21)
    r13 = RSP_MEM_H_LOAD(0X8, r21);
    // vadd        $v7, $v7, $v7[1q]
    rsp.VADD<3>(rsp.vpu.r[7], rsp.vpu.r[7], rsp.vpu.r[7]);
    // lh          $5, 0x8($20)
    r5 = RSP_MEM_H_LOAD(0X8, r20);
    // vadd        $v6, $v6, $v6[1q]
    rsp.VADD<3>(rsp.vpu.r[6], rsp.vpu.r[6], rsp.vpu.r[6]);
    // lh          $16, 0x2($21)
    r16 = RSP_MEM_H_LOAD(0X2, r21);
    // vadd        $v5, $v5, $v5[1q]
    rsp.VADD<3>(rsp.vpu.r[5], rsp.vpu.r[5], rsp.vpu.r[5]);
    // lh          $8, 0x2($20)
    r8 = RSP_MEM_H_LOAD(0X2, r20);
    // vadd        $v8, $v8, $v8[2h]
    rsp.VADD<6>(rsp.vpu.r[8], rsp.vpu.r[8], rsp.vpu.r[8]);
    // lh          $12, 0xA($21)
    r12 = RSP_MEM_H_LOAD(0XA, r21);
    // vadd        $v7, $v7, $v7[2h]
    rsp.VADD<6>(rsp.vpu.r[7], rsp.vpu.r[7], rsp.vpu.r[7]);
    // lh          $4, 0xA($20)
    r4 = RSP_MEM_H_LOAD(0XA, r20);
    // vadd        $v6, $v6, $v6[2h]
    rsp.VADD<6>(rsp.vpu.r[6], rsp.vpu.r[6], rsp.vpu.r[6]);
    // lh          $15, 0x4($21)
    r15 = RSP_MEM_H_LOAD(0X4, r21);
    // vadd        $v5, $v5, $v5[2h]
    rsp.VADD<6>(rsp.vpu.r[5], rsp.vpu.r[5], rsp.vpu.r[5]);
    // lh          $7, 0x4($20)
    r7 = RSP_MEM_H_LOAD(0X4, r20);
    // vmudn       $v4, $v29, $v8[0h]
    rsp.VMUDN<4>(rsp.vpu.r[4], rsp.vpu.r[29], rsp.vpu.r[8]);
    // lh          $11, 0xC($21)
    r11 = RSP_MEM_H_LOAD(0XC, r21);
    // vmadn       $v4, $v28, $v7[0h]
    rsp.VMADN<4>(rsp.vpu.r[4], rsp.vpu.r[28], rsp.vpu.r[7]);
    // lh          $3, 0xC($20)
    r3 = RSP_MEM_H_LOAD(0XC, r20);
    // vmadn       $v4, $v27, $v6[0h]
    rsp.VMADN<4>(rsp.vpu.r[4], rsp.vpu.r[27], rsp.vpu.r[6]);
    // lh          $14, 0x6($21)
    r14 = RSP_MEM_H_LOAD(0X6, r21);
    // vmadn       $v4, $v26, $v5[0h]
    rsp.VMADN<4>(rsp.vpu.r[4], rsp.vpu.r[26], rsp.vpu.r[5]);
    // lh          $6, 0x6($20)
    r6 = RSP_MEM_H_LOAD(0X6, r20);
    // lh          $10, 0xE($21)
    r10 = RSP_MEM_H_LOAD(0XE, r21);
    // addi        $18, $18, -0x10
    r18 = RSP_ADD32(r18, -0X10);
    // sqv         $v4[0], 0x0($19)
    rsp.SQV<0>(rsp.vpu.r[4], r19, 0X0);
    // blez        $18, L_1ACC
    if (RSP_SIGNED(r18) <= 0) {
        // lh          $2, 0xE($20)
        r2 = RSP_MEM_H_LOAD(0XE, r20);
        goto L_1ACC;
    }
    // lh          $2, 0xE($20)
    r2 = RSP_MEM_H_LOAD(0XE, r20);
    // j           L_1A4C
    // addi        $19, $19, 0x10
    r19 = RSP_ADD32(r19, 0X10);
    goto L_1A4C;
    // addi        $19, $19, 0x10
    r19 = RSP_ADD32(r19, 0X10);
L_1ACC:
    // ssv         $v23[0], 0x8($23)
    rsp.SSV<0>(rsp.vpu.r[23], r23, 0X4);
    // ldv         $v16[0], 0x0($17)
    rsp.LDV<0>(rsp.vpu.r[16], r17, 0X0);
    // sdv         $v16[0], 0x0($23)
    rsp.SDV<0>(rsp.vpu.r[16], r23, 0X0);
    // lh          $6, 0x0($24)
    r6 = RSP_MEM_H_LOAD(0X0, r24);
    // addi        $17, $17, 0x8
    r17 = RSP_ADD32(r17, 0X8);
    // sub         $5, $17, $6
    r5 = RSP_SUB32(r17, r6);
    // andi        $4, $5, 0xF
    r4 = r5 & 0XF;
    // sub         $17, $17, $4
    r17 = RSP_SUB32(r17, r4);
    // beq         $4, $zero, L_1AF8
    if (r4 == 0) {
        // addi        $7, $zero, 0x10
        r7 = RSP_ADD32(0, 0X10);
        goto L_1AF8;
    }
    // addi        $7, $zero, 0x10
    r7 = RSP_ADD32(0, 0X10);
    // sub         $4, $7, $4
    r4 = RSP_SUB32(r7, r4);
L_1AF8:
    // sh          $4, 0xA($23)
    RSP_MEM_H_STORE(0XA, r23, r4);
    // ldv         $v3[0], 0x0($17)
    rsp.LDV<0>(rsp.vpu.r[3], r17, 0X0);
    // ldv         $v3[8], 0x8($17)
    rsp.LDV<8>(rsp.vpu.r[3], r17, 0X1);
    // sqv         $v3[0], 0x10($23)
    rsp.SQV<0>(rsp.vpu.r[3], r23, 0X1);
    // lw          $2, 0x40($23)
    r2 = RSP_MEM_W_LOAD(0X40, r23);
    // addi        $1, $23, 0x0
    r1 = RSP_ADD32(r23, 0X0);
    // jal         0x11C0
    r31 = 0x1B18;
    // addi        $3, $zero, 0x1F
    r3 = RSP_ADD32(0, 0X1F);
    goto L_11C0;
    // addi        $3, $zero, 0x1F
    r3 = RSP_ADD32(0, 0X1F);
L_1B18:
    // j           L_1118
    // nop

    goto L_1118;
    // nop

    // lui         $4, 0xFF
    r4 = S32(0XFF << 16);
    // ori         $4, $4, 0xFFFF
    r4 = r4 | 0XFFFF;
    // and         $2, $25, $4
    r2 = r25 & r4;
    // srl         $5, $25, 24
    r5 = S32(U32(r25) >> 24);
    // sll         $5, $5, 2
    r5 = S32(r5) << 2;
    // lw          $6, 0x320($5)
    r6 = RSP_MEM_W_LOAD(0X320, r5);
    // add         $2, $2, $6
    r2 = RSP_ADD32(r2, r6);
    // addi        $1, $23, 0x0
    r1 = RSP_ADD32(r23, 0X0);
    // addi        $3, $zero, 0x4F
    r3 = RSP_ADD32(0, 0X4F);
    // vxor        $v0, $v0, $v0
    rsp.VXOR<0>(rsp.vpu.r[0], rsp.vpu.r[0], rsp.vpu.r[0]);
    // addi        $11, $zero, 0x50
    r11 = RSP_ADD32(0, 0X50);
    // lqv         $v31[0], 0x10($11)
    rsp.LQV<0>(rsp.vpu.r[31], r11, 0X1);
    // lqv         $v10[0], 0x0($zero)
    rsp.LQV<0>(rsp.vpu.r[10], 0, 0X0);
    // srl         $12, $26, 16
    r12 = S32(U32(r26) >> 16);
    // andi        $10, $12, 0x1
    r10 = r12 & 0X1;
    // beq         $10, $zero, L_1B6C
    if (r10 == 0) {
        // lqv         $v24[0], 0x10($24)
        rsp.LQV<0>(rsp.vpu.r[24], r24, 0X1);
        goto L_1B6C;
    }
    // lqv         $v24[0], 0x10($24)
    rsp.LQV<0>(rsp.vpu.r[24], r24, 0X1);
    // j           L_1C18
    // nop

    goto L_1C18;
    // nop

L_1B6C:
    // jal         0x1194
    r31 = 0x1B74;
    // nop

    goto L_1194;
    // nop

L_1B74:
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
    // bne         $5, $zero, L_1B74
    if (r5 != 0) {
        // nop
    
        goto L_1B74;
    }
    // nop

    // add         $22, $zero, $zero
    r22 = RSP_ADD32(0, 0);
    // lqv         $v20[0], 0x0($23)
    rsp.LQV<0>(rsp.vpu.r[20], r23, 0X0);
    // lqv         $v21[0], 0x10($23)
    rsp.LQV<0>(rsp.vpu.r[21], r23, 0X1);
    // lqv         $v18[0], 0x20($23)
    rsp.LQV<0>(rsp.vpu.r[18], r23, 0X2);
    // lqv         $v19[0], 0x30($23)
    rsp.LQV<0>(rsp.vpu.r[19], r23, 0X3);
    // lqv         $v24[0], 0x40($23)
    rsp.LQV<0>(rsp.vpu.r[24], r23, 0X4);
    // bne         $zero, $zero, L_1BB0
    if (0 != 0) {
        // nop
    
        goto L_1BB0;
    }
    // nop

L_1BA0:
    // mfc0        $9, SP_DMA_BUSY
    r9 = 0;
    // bne         $9, $zero, L_1BA0
    if (r9 != 0) {
        // nop
    
        goto L_1BA0;
    }
    // nop

    // and         $22, $zero, $zero
    r22 = 0 & 0;
L_1BB0:
    // lh          $13, 0x0($24)
    r13 = RSP_MEM_H_LOAD(0X0, r24);
    // lh          $19, 0x2($24)
    r19 = RSP_MEM_H_LOAD(0X2, r24);
    // lh          $18, 0xA($24)
    r18 = RSP_MEM_H_LOAD(0XA, r24);
    // lh          $17, 0xC($24)
    r17 = RSP_MEM_H_LOAD(0XC, r24);
    // lh          $16, 0xE($24)
    r16 = RSP_MEM_H_LOAD(0XE, r24);
    // lh          $14, 0x4($24)
    r14 = RSP_MEM_H_LOAD(0X4, r24);
    // addi        $15, $zero, 0x10
    r15 = RSP_ADD32(0, 0X10);
    // mfc2        $21, $v24[2]
    rsp.MFC2<2>(r21, rsp.vpu.r[24]);
    // mfc2        $20, $v24[8]
    rsp.MFC2<8>(r20, rsp.vpu.r[24]);
    // andi        $9, $12, 0x8
    r9 = r12 & 0X8;
    // bgtz        $9, L_1BEC
    if (RSP_SIGNED(r9) > 0) {
        // nop
    
        goto L_1BEC;
    }
    // nop

    // addi        $17, $23, 0x50
    r17 = RSP_ADD32(r23, 0X50);
    // add         $16, $zero, $17
    r16 = RSP_ADD32(0, r17);
    // addi        $15, $zero, 0x0
    r15 = RSP_ADD32(0, 0X0);
L_1BEC:
    {
        static int envcheck_trace = 0;
        envcheck_trace++;
        if (envcheck_trace <= 30) {
            fprintf(stderr, "[R10-TRACE] L_1BEC ENVMIXER check #%d: r10=%d r12=0x%X r9=%d L=0x%03X R=0x%03X auxA=0x%03X auxC=0x%03X r17=0x%03X r13=0x%03X r19=0x%03X (t%d cmd#%d)\n",
                    envcheck_trace, r10, r12, r9, r13, r19, r18, r17, r17, r13, r19, asp_task_id, asp_cmd_count);
            fflush(stderr);
        }
    }
    // beq         $10, $zero, L_1CC8
    if (r10 == 0) {
        // lqv         $v30[0], 0x70($11)
        rsp.LQV<0>(rsp.vpu.r[30], r11, 0X7);
        goto L_1CC8;
    }
    // lqv         $v30[0], 0x70($11)
    rsp.LQV<0>(rsp.vpu.r[30], r11, 0X7);
    // lqv         $v17[0], 0x0($13)
    rsp.LQV<0>(rsp.vpu.r[17], r13, 0X0);
    // lqv         $v29[0], 0x0($19)
    rsp.LQV<0>(rsp.vpu.r[29], r19, 0X0);
    // lqv         $v27[0], 0x0($17)
    rsp.LQV<0>(rsp.vpu.r[27], r17, 0X0);
    // vxor        $v21, $v21, $v21
    rsp.VXOR<0>(rsp.vpu.r[21], rsp.vpu.r[21], rsp.vpu.r[21]);
    // lsv         $v20[14], 0x6($24)
    rsp.LSV<14>(rsp.vpu.r[20], r24, 0X3);
    // vmudl       $v23, $v30, $v24[2]
    rsp.VMUDL<10>(rsp.vpu.r[23], rsp.vpu.r[30], rsp.vpu.r[24]);
    // vmadn       $v23, $v30, $v24[1]
    rsp.VMADN<9>(rsp.vpu.r[23], rsp.vpu.r[30], rsp.vpu.r[24]);
    // vmadm       $v22, $v31, $v0[0]
    rsp.VMADM<8>(rsp.vpu.r[22], rsp.vpu.r[31], rsp.vpu.r[0]);
    // vmadm       $v21, $v31, $v21[7]
    rsp.VMADM<15>(rsp.vpu.r[21], rsp.vpu.r[31], rsp.vpu.r[21]);
L_1C18:
    // vmadh       $v20, $v31, $v20[7]
    rsp.VMADH<15>(rsp.vpu.r[20], rsp.vpu.r[31], rsp.vpu.r[20]);
    // bgtz        $21, L_1C30
    if (RSP_SIGNED(r21) > 0) {
        // vmadn       $v21, $v31, $v0[0]
        rsp.VMADN<8>(rsp.vpu.r[21], rsp.vpu.r[31], rsp.vpu.r[0]);
        goto L_1C30;
    }
    // vmadn       $v21, $v31, $v0[0]
    rsp.VMADN<8>(rsp.vpu.r[21], rsp.vpu.r[31], rsp.vpu.r[0]);
    // vge         $v20, $v20, $v24[0]
    rsp.VGE<8>(rsp.vpu.r[20], rsp.vpu.r[20], rsp.vpu.r[24]);
    // j           L_1CB4
    // nop

    goto L_1CB4;
    // nop

L_1C30:
    // vcl         $v20, $v20, $v24[0]
    rsp.VCL<8>(rsp.vpu.r[20], rsp.vpu.r[20], rsp.vpu.r[24]);
    // vmulf       $v16, $v20, $v24[6]
    rsp.VMULF<14>(rsp.vpu.r[16], rsp.vpu.r[20], rsp.vpu.r[24]);
    // vmulf       $v15, $v20, $v24[7]
    rsp.VMULF<15>(rsp.vpu.r[15], rsp.vpu.r[20], rsp.vpu.r[24]);
    // vmulf       $v29, $v29, $v10[6]
    rsp.VMULF<14>(rsp.vpu.r[29], rsp.vpu.r[29], rsp.vpu.r[10]);
    // vmacf       $v29, $v17, $v16
    rsp.VMACF<0>(rsp.vpu.r[29], rsp.vpu.r[17], rsp.vpu.r[16]);
    // vmulf       $v27, $v27, $v10[6]
    rsp.VMULF<14>(rsp.vpu.r[27], rsp.vpu.r[27], rsp.vpu.r[10]);
    // vmacf       $v27, $v17, $v15
    rsp.VMACF<0>(rsp.vpu.r[27], rsp.vpu.r[17], rsp.vpu.r[15]);
    // sqv         $v29[0], 0x0($19)
    rsp.SQV<0>(rsp.vpu.r[29], r19, 0X0);
    // sqv         $v27[0], 0x0($17)
    rsp.SQV<0>(rsp.vpu.r[27], r17, 0X0);
    // lqv         $v28[0], 0x0($18)
    rsp.LQV<0>(rsp.vpu.r[28], r18, 0X0);
    // lqv         $v26[0], 0x0($16)
    rsp.LQV<0>(rsp.vpu.r[26], r16, 0X0);
    // vxor        $v19, $v19, $v19
    rsp.VXOR<0>(rsp.vpu.r[19], rsp.vpu.r[19], rsp.vpu.r[19]);
    // lsv         $v18[14], 0x8($24)
    rsp.LSV<14>(rsp.vpu.r[18], r24, 0X4);
    // vmudl       $v23, $v30, $v24[5]
    rsp.VMUDL<13>(rsp.vpu.r[23], rsp.vpu.r[30], rsp.vpu.r[24]);
    // vmadn       $v23, $v30, $v24[4]
    rsp.VMADN<12>(rsp.vpu.r[23], rsp.vpu.r[30], rsp.vpu.r[24]);
    // vmadm       $v22, $v31, $v0[0]
    rsp.VMADM<8>(rsp.vpu.r[22], rsp.vpu.r[31], rsp.vpu.r[0]);
    // vmadm       $v19, $v31, $v19[7]
    rsp.VMADM<15>(rsp.vpu.r[19], rsp.vpu.r[31], rsp.vpu.r[19]);
    // vmadh       $v18, $v31, $v18[7]
    rsp.VMADH<15>(rsp.vpu.r[18], rsp.vpu.r[31], rsp.vpu.r[18]);
    // bgtz        $20, L_1C8C
    if (RSP_SIGNED(r20) > 0) {
        // vmadn       $v19, $v31, $v0[0]
        rsp.VMADN<8>(rsp.vpu.r[19], rsp.vpu.r[31], rsp.vpu.r[0]);
        goto L_1C8C;
    }
    // vmadn       $v19, $v31, $v0[0]
    rsp.VMADN<8>(rsp.vpu.r[19], rsp.vpu.r[31], rsp.vpu.r[0]);
    // vge         $v18, $v18, $v24[3]
    rsp.VGE<11>(rsp.vpu.r[18], rsp.vpu.r[18], rsp.vpu.r[24]);
    // j           L_1D10
    // nop

    goto L_1D10;
    // nop

L_1C8C:
    // vcl         $v18, $v18, $v24[3]
    rsp.VCL<11>(rsp.vpu.r[18], rsp.vpu.r[18], rsp.vpu.r[24]);
    // vmulf       $v16, $v18, $v24[6]
    rsp.VMULF<14>(rsp.vpu.r[16], rsp.vpu.r[18], rsp.vpu.r[24]);
    // vmulf       $v15, $v18, $v24[7]
    rsp.VMULF<15>(rsp.vpu.r[15], rsp.vpu.r[18], rsp.vpu.r[24]);
    // vmulf       $v28, $v28, $v10[6]
    rsp.VMULF<14>(rsp.vpu.r[28], rsp.vpu.r[28], rsp.vpu.r[10]);
    // vmacf       $v28, $v17, $v16
    rsp.VMACF<0>(rsp.vpu.r[28], rsp.vpu.r[17], rsp.vpu.r[16]);
    // vmulf       $v26, $v26, $v10[6]
    rsp.VMULF<14>(rsp.vpu.r[26], rsp.vpu.r[26], rsp.vpu.r[10]);
    // vmacf       $v26, $v17, $v15
    rsp.VMACF<0>(rsp.vpu.r[26], rsp.vpu.r[17], rsp.vpu.r[15]);
    // sqv         $v28[0], 0x0($18)
    rsp.SQV<0>(rsp.vpu.r[28], r18, 0X0);
    // sqv         $v26[0], 0x0($16)
    rsp.SQV<0>(rsp.vpu.r[26], r16, 0X0);
    // addi        $14, $14, -0x10
    r14 = RSP_ADD32(r14, -0X10);
L_1CB4:
    // addi        $13, $13, 0x10
    r13 = RSP_ADD32(r13, 0X10);
    // addi        $19, $19, 0x10
    r19 = RSP_ADD32(r19, 0X10);
    // addi        $18, $18, 0x10
    r18 = RSP_ADD32(r18, 0X10);
    // add         $17, $17, $15
    r17 = RSP_ADD32(r17, r15);
    // add         $16, $16, $15
    r16 = RSP_ADD32(r16, r15);
L_1CC8:
    // vaddc       $v21, $v21, $v24[2]
    rsp.VADDC<10>(rsp.vpu.r[21], rsp.vpu.r[21], rsp.vpu.r[24]);
    // vadd        $v20, $v20, $v24[1]
    rsp.VADD<9>(rsp.vpu.r[20], rsp.vpu.r[20], rsp.vpu.r[24]);
    // bgtz        $21, L_1CF4
    if (RSP_SIGNED(r21) > 0) {
        // lqv         $v17[0], 0x0($13)
        rsp.LQV<0>(rsp.vpu.r[17], r13, 0X0);
        goto L_1CF4;
    }
    // lqv         $v17[0], 0x0($13)
    rsp.LQV<0>(rsp.vpu.r[17], r13, 0X0);
    // vge         $v20, $v20, $v24[0]
    rsp.VGE<8>(rsp.vpu.r[20], rsp.vpu.r[20], rsp.vpu.r[24]);
    // vaddc       $v19, $v19, $v24[5]
    rsp.VADDC<13>(rsp.vpu.r[19], rsp.vpu.r[19], rsp.vpu.r[24]);
    // lqv         $v29[0], 0x0($19)
    rsp.LQV<0>(rsp.vpu.r[29], r19, 0X0);
    // vadd        $v18, $v18, $v24[4]
    rsp.VADD<12>(rsp.vpu.r[18], rsp.vpu.r[18], rsp.vpu.r[24]);
    // lqv         $v27[0], 0x0($17)
    rsp.LQV<0>(rsp.vpu.r[27], r17, 0X0);
    // j           L_1D88
    // nop

    goto L_1D88;
    // nop

L_1CF4:
    // vcl         $v20, $v20, $v24[0]
    rsp.VCL<8>(rsp.vpu.r[20], rsp.vpu.r[20], rsp.vpu.r[24]);
    // vaddc       $v19, $v19, $v24[5]
    rsp.VADDC<13>(rsp.vpu.r[19], rsp.vpu.r[19], rsp.vpu.r[24]);
    // lqv         $v29[0], 0x0($19)
    rsp.LQV<0>(rsp.vpu.r[29], r19, 0X0);
    // vadd        $v18, $v18, $v24[4]
    rsp.VADD<12>(rsp.vpu.r[18], rsp.vpu.r[18], rsp.vpu.r[24]);
    // lqv         $v27[0], 0x0($17)
    rsp.LQV<0>(rsp.vpu.r[27], r17, 0X0);
    // vmulf       $v16, $v20, $v24[6]
    rsp.VMULF<14>(rsp.vpu.r[16], rsp.vpu.r[20], rsp.vpu.r[24]);
    // sqv         $v20[0], 0x0($23)
    rsp.SQV<0>(rsp.vpu.r[20], r23, 0X0);
L_1D10:
    // vmulf       $v15, $v20, $v24[7]
    rsp.VMULF<15>(rsp.vpu.r[15], rsp.vpu.r[20], rsp.vpu.r[24]);
    // sqv         $v21[0], 0x10($23)
    rsp.SQV<0>(rsp.vpu.r[21], r23, 0X1);
    // vmulf       $v29, $v29, $v10[6]
    rsp.VMULF<14>(rsp.vpu.r[29], rsp.vpu.r[29], rsp.vpu.r[10]);
    // vmacf       $v29, $v17, $v16
    rsp.VMACF<0>(rsp.vpu.r[29], rsp.vpu.r[17], rsp.vpu.r[16]);
    // lqv         $v28[0], 0x0($18)
    rsp.LQV<0>(rsp.vpu.r[28], r18, 0X0);
    // vmulf       $v27, $v27, $v10[6]
    rsp.VMULF<14>(rsp.vpu.r[27], rsp.vpu.r[27], rsp.vpu.r[10]);
    // lqv         $v26[0], 0x0($16)
    rsp.LQV<0>(rsp.vpu.r[26], r16, 0X0);
    // vmacf       $v27, $v17, $v15
    rsp.VMACF<0>(rsp.vpu.r[27], rsp.vpu.r[17], rsp.vpu.r[15]);
    // bgtz        $20, L_1D50
    if (RSP_SIGNED(r20) > 0) {
        // sqv         $v29[0], 0x0($19)
        rsp.SQV<0>(rsp.vpu.r[29], r19, 0X0);
        goto L_1D50;
    }
    // sqv         $v29[0], 0x0($19)
    rsp.SQV<0>(rsp.vpu.r[29], r19, 0X0);
    // vge         $v18, $v18, $v24[3]
    rsp.VGE<11>(rsp.vpu.r[18], rsp.vpu.r[18], rsp.vpu.r[24]);
    // vaddc       $v21, $v21, $v24[2]
    rsp.VADDC<10>(rsp.vpu.r[21], rsp.vpu.r[21], rsp.vpu.r[24]);
    // sqv         $v27[0], 0x0($17)
    rsp.SQV<0>(rsp.vpu.r[27], r17, 0X0);
    // vadd        $v20, $v20, $v24[1]
    rsp.VADD<9>(rsp.vpu.r[20], rsp.vpu.r[20], rsp.vpu.r[24]);
    // j           L_1DE0
    // nop

    goto L_1DE0;
    // nop

L_1D50:
    // vcl         $v18, $v18, $v24[3]
    rsp.VCL<11>(rsp.vpu.r[18], rsp.vpu.r[18], rsp.vpu.r[24]);
    // vaddc       $v21, $v21, $v24[2]
    rsp.VADDC<10>(rsp.vpu.r[21], rsp.vpu.r[21], rsp.vpu.r[24]);
    // sqv         $v27[0], 0x0($17)
    rsp.SQV<0>(rsp.vpu.r[27], r17, 0X0);
    // vadd        $v20, $v20, $v24[1]
    rsp.VADD<9>(rsp.vpu.r[20], rsp.vpu.r[20], rsp.vpu.r[24]);
    // vmulf       $v16, $v18, $v24[6]
    rsp.VMULF<14>(rsp.vpu.r[16], rsp.vpu.r[18], rsp.vpu.r[24]);
    // addi        $14, $14, -0x10
    r14 = RSP_ADD32(r14, -0X10);
    // vmulf       $v15, $v18, $v24[7]
    rsp.VMULF<15>(rsp.vpu.r[15], rsp.vpu.r[18], rsp.vpu.r[24]);
    // addi        $19, $19, 0x10
    r19 = RSP_ADD32(r19, 0X10);
    // vmulf       $v28, $v28, $v10[6]
    rsp.VMULF<14>(rsp.vpu.r[28], rsp.vpu.r[28], rsp.vpu.r[10]);
    // add         $17, $17, $15
    r17 = RSP_ADD32(r17, r15);
    // vmacf       $v28, $v17, $v16
    rsp.VMACF<0>(rsp.vpu.r[28], rsp.vpu.r[17], rsp.vpu.r[16]);
    // addi        $13, $13, 0x10
    r13 = RSP_ADD32(r13, 0X10);
    // vmulf       $v26, $v26, $v10[6]
    rsp.VMULF<14>(rsp.vpu.r[26], rsp.vpu.r[26], rsp.vpu.r[10]);
    // vmacf       $v26, $v17, $v15
    rsp.VMACF<0>(rsp.vpu.r[26], rsp.vpu.r[17], rsp.vpu.r[15]);
L_1D88:
    // sqv         $v28[0], 0x0($18)
    rsp.SQV<0>(rsp.vpu.r[28], r18, 0X0);
    // addi        $18, $18, 0x10
    r18 = RSP_ADD32(r18, 0X10);
    // blez        $14, L_1DA0
    if (RSP_SIGNED(r14) <= 0) {
        // sqv         $v26[0], 0x0($16)
        rsp.SQV<0>(rsp.vpu.r[26], r16, 0X0);
        goto L_1DA0;
    }
    // sqv         $v26[0], 0x0($16)
    rsp.SQV<0>(rsp.vpu.r[26], r16, 0X0);
    // j           L_1D50
    // add         $16, $16, $15
    r16 = RSP_ADD32(r16, r15);
    goto L_1D50;
    // add         $16, $16, $15
    r16 = RSP_ADD32(r16, r15);
L_1DA0:
    // sqv         $v18[0], 0x20($23)
    rsp.SQV<0>(rsp.vpu.r[18], r23, 0X2);
    // sqv         $v19[0], 0x30($23)
    rsp.SQV<0>(rsp.vpu.r[19], r23, 0X3);
    // sqv         $v24[0], 0x40($23)
    rsp.SQV<0>(rsp.vpu.r[24], r23, 0X4);
    // jal         0x11C0
    r31 = 0x1DB4;
    // addi        $3, $zero, 0x4F
    r3 = RSP_ADD32(0, 0X4F);
    goto L_11C0;
    // addi        $3, $zero, 0x4F
    r3 = RSP_ADD32(0, 0X4F);
L_1DB4:
    // j           L_1118
    // nop

    goto L_1118;
    // nop

    // lqv         $v31[0], 0x0($zero)
    rsp.LQV<0>(rsp.vpu.r[31], 0, 0X0);
    // lhu         $18, 0x4($24)
    r18 = RSP_MEM_HU_LOAD(0X4, r24);
    // beq         $18, $zero, L_1EB4
    if (r18 == 0) {
        // nop
    
        goto L_1EB4;
    }
    // nop

    // andi        $2, $25, 0xFFFF
    r2 = r25 & 0XFFFF;
    // addi        $2, $2, 0x5C0
    r2 = RSP_ADD32(r2, 0X5C0);
    // srl         $1, $25, 16
    r1 = S32(U32(r25) >> 16);
    // addi        $1, $1, 0x5C0
    r1 = RSP_ADD32(r1, 0X5C0);
    // andi        $17, $26, 0xFFFF
    r17 = r26 & 0XFFFF;
L_1DE0:
    // mtc2        $17, $v30[0]
    rsp.MTC2<0>(r17, rsp.vpu.r[30]);
    // beq         $22, $zero, L_1DFC
    if (r22 == 0) {
        // nop
    
        goto L_1DFC;
    }
    // nop

L_1DEC:
    // mfc0        $3, SP_DMA_BUSY
    r3 = 0;
    // bne         $3, $zero, L_1DEC
    if (r3 != 0) {
        // nop
    
        goto L_1DEC;
    }
    // nop

    // add         $22, $zero, $zero
    r22 = RSP_ADD32(0, 0);
L_1DFC:
    // lqv         $v25[0], 0x0($2)
    rsp.LQV<0>(rsp.vpu.r[25], r2, 0X0);
    // lqv         $v29[0], 0x0($1)
    rsp.LQV<0>(rsp.vpu.r[29], r1, 0X0);
    // lqv         $v24[0], 0x10($2)
    rsp.LQV<0>(rsp.vpu.r[24], r2, 0X1);
    // lqv         $v28[0], 0x10($1)
    rsp.LQV<0>(rsp.vpu.r[28], r1, 0X1);
    // vmulf       $v25, $v25, $v31[6]
    rsp.VMULF<14>(rsp.vpu.r[25], rsp.vpu.r[25], rsp.vpu.r[31]);
    // lqv         $v27[0], 0x20($1)
    rsp.LQV<0>(rsp.vpu.r[27], r1, 0X2);
    // lqv         $v23[0], 0x20($2)
    rsp.LQV<0>(rsp.vpu.r[23], r2, 0X2);
    // vmacf       $v25, $v29, $v30[0]
    rsp.VMACF<8>(rsp.vpu.r[25], rsp.vpu.r[29], rsp.vpu.r[30]);
    // addi        $18, $18, -0x20
    r18 = RSP_ADD32(r18, -0X20);
    // vmulf       $v24, $v24, $v31[6]
    rsp.VMULF<14>(rsp.vpu.r[24], rsp.vpu.r[24], rsp.vpu.r[31]);
    // lqv         $v26[0], 0x30($1)
    rsp.LQV<0>(rsp.vpu.r[26], r1, 0X3);
    // lqv         $v22[0], 0x30($2)
    rsp.LQV<0>(rsp.vpu.r[22], r2, 0X3);
    // addi        $1, $1, 0x40
    r1 = RSP_ADD32(r1, 0X40);
    // addi        $2, $2, 0x40
    r2 = RSP_ADD32(r2, 0X40);
    // vmacf       $v24, $v28, $v30[0]
    rsp.VMACF<8>(rsp.vpu.r[24], rsp.vpu.r[28], rsp.vpu.r[30]);
    // blez        $18, L_1EAC
    if (RSP_SIGNED(r18) <= 0) {
        // nop
    
        goto L_1EAC;
    }
L_1E3C:
    // nop

L_1E40:
    // vmulf       $v23, $v23, $v31[6]
    rsp.VMULF<14>(rsp.vpu.r[23], rsp.vpu.r[23], rsp.vpu.r[31]);
    // sqv         $v25[0], 0x7C0($2)
    rsp.SQV<0>(rsp.vpu.r[25], r2, -0X4);
    // lqv         $v29[0], 0x0($1)
    rsp.LQV<0>(rsp.vpu.r[29], r1, 0X0);
    // lqv         $v25[0], 0x0($2)
    rsp.LQV<0>(rsp.vpu.r[25], r2, 0X0);
    // vmacf       $v23, $v27, $v30[0]
    rsp.VMACF<8>(rsp.vpu.r[23], rsp.vpu.r[27], rsp.vpu.r[30]);
    // vmulf       $v22, $v22, $v31[6]
    rsp.VMULF<14>(rsp.vpu.r[22], rsp.vpu.r[22], rsp.vpu.r[31]);
    // sqv         $v24[0], 0x7D0($2)
    rsp.SQV<0>(rsp.vpu.r[24], r2, -0X3);
    // lqv         $v28[0], 0x10($1)
    rsp.LQV<0>(rsp.vpu.r[28], r1, 0X1);
    // lqv         $v24[0], 0x10($2)
    rsp.LQV<0>(rsp.vpu.r[24], r2, 0X1);
    // vmacf       $v22, $v26, $v30[0]
    rsp.VMACF<8>(rsp.vpu.r[22], rsp.vpu.r[26], rsp.vpu.r[30]);
    // addi        $1, $1, 0x40
    r1 = RSP_ADD32(r1, 0X40);
    // vmulf       $v25, $v25, $v31[6]
    rsp.VMULF<14>(rsp.vpu.r[25], rsp.vpu.r[25], rsp.vpu.r[31]);
    // sqv         $v23[0], 0x7E0($2)
    rsp.SQV<0>(rsp.vpu.r[23], r2, -0X2);
    // lqv         $v27[0], 0x7E0($1)
    rsp.LQV<0>(rsp.vpu.r[27], r1, -0X2);
    // lqv         $v23[0], 0x20($2)
    rsp.LQV<0>(rsp.vpu.r[23], r2, 0X2);
    // vmacf       $v25, $v29, $v30[0]
    rsp.VMACF<8>(rsp.vpu.r[25], rsp.vpu.r[29], rsp.vpu.r[30]);
    // addi        $18, $18, -0x40
    r18 = RSP_ADD32(r18, -0X40);
    // vmulf       $v24, $v24, $v31[6]
    rsp.VMULF<14>(rsp.vpu.r[24], rsp.vpu.r[24], rsp.vpu.r[31]);
    // sqv         $v22[0], 0x7F0($2)
    rsp.SQV<0>(rsp.vpu.r[22], r2, -0X1);
    // lqv         $v26[0], 0x7F0($1)
    rsp.LQV<0>(rsp.vpu.r[26], r1, -0X1);
    // lqv         $v22[0], 0x30($2)
    rsp.LQV<0>(rsp.vpu.r[22], r2, 0X3);
    // vmacf       $v24, $v28, $v30[0]
    rsp.VMACF<8>(rsp.vpu.r[24], rsp.vpu.r[28], rsp.vpu.r[30]);
    // bgtz        $18, L_1E40
    if (RSP_SIGNED(r18) > 0) {
        // addi        $2, $2, 0x40
        r2 = RSP_ADD32(r2, 0X40);
        goto L_1E40;
    }
    // addi        $2, $2, 0x40
    r2 = RSP_ADD32(r2, 0X40);
    // addi        $18, $18, 0x20
    r18 = RSP_ADD32(r18, 0X20);
    // blez        $18, L_1EB4
    if (RSP_SIGNED(r18) <= 0) {
        // nop
    
        goto L_1EB4;
    }
    // nop

L_1EAC:
    // sqv         $v25[0], 0x7C0($2)
    rsp.SQV<0>(rsp.vpu.r[25], r2, -0X4);
    // sqv         $v24[0], 0x7D0($2)
    rsp.SQV<0>(rsp.vpu.r[24], r2, -0X3);
L_1EB4:
    // j           L_1118
    // nop

    goto L_1118;
    // nop

    // nop

    return RspExitReason::ImemOverrun;
do_indirect_jump:
    switch ((jump_target | 0x1000) & 0X1FFF) { 
        case 0x10B0: goto L_10B0;
        case 0x1040: goto L_1040;
        case 0x11E8: goto L_11E8;
        case 0x1108: goto L_1108;
        case 0x124C: goto L_124C;
        case 0x121C: goto L_121C;
        case 0x14B0: goto L_14B0;
        case 0x16C4: goto L_16C4;
        case 0x175C: goto L_175C;
        case 0x184C: goto L_184C;
        case 0x14A4: goto L_14A4;
        case 0x18A0: goto L_18A0;
        case 0x1B18: goto L_1B18;
        case 0x1B74: goto L_1B74;
        case 0x1DB4: goto L_1DB4;
        case 0x1118: goto L_1118;
        case 0x11EC: goto L_11EC;
        case 0x1BA0: goto L_1BA0;
        case 0x123C: goto L_123C;
        case 0x18D4: goto L_18D4;
        case 0x12F0: goto L_12F0;
        case 0x1270: goto L_1270;
        case 0x12D4: goto L_12D4;
        case 0x132C: goto L_132C;
        case 0x1428: goto L_1428;
        case 0x12A4: goto L_12A4;
        case 0x1E3C: goto L_1E3C;
        case 0x1390: goto L_1390;
        case 0x1758: goto L_1758;
        case 0x1480: goto L_1480;
    }
    fprintf(stderr, "Unhandled jump target 0x%04X in microcode aspMain, coming from [%s:%d]\n", jump_target, debug_file, debug_line);
    fprintf(stderr, "Register dump: r0  = %08X r1  = %08X r2  = %08X r3  = %08X r4  = %08X r5  = %08X r6  = %08X r7  = %08X\n"
           "               r8  = %08X r9  = %08X r10 = %08X r11 = %08X r12 = %08X r13 = %08X r14 = %08X r15 = %08X\n"
           "               r16 = %08X r17 = %08X r18 = %08X r19 = %08X r20 = %08X r21 = %08X r22 = %08X r23 = %08X\n"
           "               r24 = %08X r25 = %08X r26 = %08X r27 = %08X r28 = %08X r29 = %08X r30 = %08X r31 = %08X\n",
           0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, r15, r16,
           r17, r18, r19, r20, r21, r22, r23, r24, r25, r26, r27, r28, r29, r30, r31);
    fflush(stderr);
    return RspExitReason::UnhandledJumpTarget;
}
