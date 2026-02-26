// audio_diag.cpp — Diagnostic wrappers for audio filter functions
// Wraps alAdpcmPull, alLoadParam, alSynStartVoice, alSynStartVoiceParams
// to diagnose why ADPCM decode commands (op=1) are never generated.

#include <cstdio>
#include <cstdint>
#include "recomp.h"

// Original functions (defined in RecompiledFuncs)
extern "C" {
    void alAdpcmPull(uint8_t* rdram, recomp_context* ctx);
    void alLoadParam(uint8_t* rdram, recomp_context* ctx);
    void alSynStartVoice(uint8_t* rdram, recomp_context* ctx);
    void alSynStartVoiceParams(uint8_t* rdram, recomp_context* ctx);
}

// --------------------------------------------------------------------------
// Helper: read a 32-bit word from N64 RDRAM given an N64 virtual address
// --------------------------------------------------------------------------
static inline int32_t rd_w(uint8_t* rdram, uint64_t n64_addr) {
    return *(int32_t*)(rdram + (n64_addr - 0xFFFFFFFF80000000ULL));
}
static inline uint8_t rd_bu(uint8_t* rdram, uint64_t n64_addr) {
    return *(uint8_t*)(rdram + ((n64_addr ^ 3) - 0xFFFFFFFF80000000ULL));
}

// --------------------------------------------------------------------------
// ALLoadFilter struct offsets (from DKR decomp)
// --------------------------------------------------------------------------
// +0x04: handler       +0x08: setParam
// +0x1C: loop.start    +0x20: loop.end      +0x24: loop.count
// +0x28: table (ALWaveTable*)
// +0x2C: bookSize      +0x30: dma           +0x34: dmaState
// +0x38: sample        +0x3C: lastsam       +0x40: first
// +0x44: memin
//
// ALWaveTable struct:
// +0x00: base (u8*)    +0x04: len (s32)     +0x08: type (u8)
// +0x0C: waveInfo (union: adpcmWave / rawWave)
//   For ADPCM: +0x0C: loop (ALADPCMloop*)  +0x10: book (ALADPCMBook*)

static int adpcm_pull_count = 0;
static int adpcm_skip_overflow = 0;
static int adpcm_decode_ok = 0;

// --------------------------------------------------------------------------
// alAdpcmPull wrapper — diagnose overflow skip
// --------------------------------------------------------------------------
extern "C" RECOMP_FUNC void alAdpcmPull_wrapper(uint8_t* rdram, recomp_context* ctx) {
    adpcm_pull_count++;

    // Read args: a0=filter, a1=outp, a2=outCount, a3=sampleOffset, stack=cmdPtr
    uint64_t filter = ctx->r4;
    int32_t outCount = (int32_t)ctx->r6;

    // Read filter fields
    int32_t table_ptr  = rd_w(rdram, filter + 0x28);
    int32_t memin      = rd_w(rdram, filter + 0x44);
    int32_t sample     = rd_w(rdram, filter + 0x38);
    int32_t lastsam    = rd_w(rdram, filter + 0x3C);
    int32_t loop_end   = rd_w(rdram, filter + 0x20);
    int32_t loop_count = rd_w(rdram, filter + 0x24);
    int32_t first_flag = rd_w(rdram, filter + 0x40);
    int32_t dma_func   = rd_w(rdram, filter + 0x30);
    int32_t handler    = rd_w(rdram, filter + 0x04);

    // Read wavetable fields
    int32_t tbl_base = 0, tbl_len = 0;
    uint8_t tbl_type = 0;
    int32_t book_ptr = 0;
    uint64_t table_n64 = (uint64_t)(int64_t)(int32_t)table_ptr;
    if (table_ptr != 0) {
        tbl_base = rd_w(rdram, table_n64 + 0x00);
        tbl_len  = rd_w(rdram, table_n64 + 0x04);
        tbl_type = rd_bu(rdram, table_n64 + 0x08);
        book_ptr = rd_w(rdram, table_n64 + 0x10);  // ADPCM book
    }

    // Compute what the overflow check will do
    // nLeft = lastsam ? (16 - lastsam) : 0
    int32_t nLeft = lastsam ? (16 - lastsam) : 0;
    int32_t tsam = outCount - nLeft;
    if (tsam < 0) tsam = 0;
    int32_t nframes = (tsam + 15) >> 4;
    int32_t nbytes = nframes * 9;

    // overFlow = memin + nbytes - (table->base + table->len)
    int32_t overFlow = memin + nbytes - (tbl_base + tbl_len);
    if (overFlow < 0) overFlow = 0;
    int32_t nOver = (overFlow / 9) << 4;
    int32_t nSam = nframes << 4;
    if (nOver > nSam + nLeft) nOver = nSam + nLeft;
    int32_t nOver_rounded = nOver - (nOver & 0xF);
    bool will_decode = (nOver_rounded < outCount);

    if (!will_decode) adpcm_skip_overflow++;
    else adpcm_decode_ok++;

    // Log first 30 calls and every 500th after
    if (adpcm_pull_count <= 3 || (adpcm_pull_count % 2000) == 0) {
        fprintf(stderr,
            "[ADPCM-PULL #%d] outCount=%d table=0x%08X base=0x%08X len=%d type=%d book=0x%08X\n"
            "  memin=0x%08X sample=%d lastsam=%d loop_end=%d loop_count=%d first=%d dma=0x%08X handler=0x%08X\n"
            "  nframes=%d nbytes=%d overFlow=%d nOver=%d nOver_rnd=%d will_decode=%s\n"
            "  [totals: calls=%d decoded=%d skipped=%d]\n",
            adpcm_pull_count, outCount, table_ptr, tbl_base, tbl_len, tbl_type, book_ptr,
            memin, sample, lastsam, loop_end, loop_count, first_flag, dma_func, handler,
            nframes, nbytes, overFlow, nOver, nOver_rounded, will_decode ? "YES" : "NO",
            adpcm_pull_count, adpcm_decode_ok, adpcm_skip_overflow);
        fflush(stderr);
    }

    // Call the real function
    alAdpcmPull(rdram, ctx);
}

// --------------------------------------------------------------------------
// alLoadParam wrapper — log SET_WAVETABLE (paramID=5)
// --------------------------------------------------------------------------
static int load_param_count = 0;
static int set_wavetable_count = 0;

extern "C" RECOMP_FUNC void alLoadParam_wrapper(uint8_t* rdram, recomp_context* ctx) {
    load_param_count++;

    uint64_t filter = ctx->r4;
    int32_t paramID = (int32_t)ctx->r5;
    uint64_t param = ctx->r6;

    if (paramID == 5) { // AL_FILTER_SET_WAVETABLE
        set_wavetable_count++;
        // param is the wavetable pointer (N64 address)
        int32_t wt_ptr = (int32_t)param;
        uint64_t wt_n64 = param;
        int32_t wt_base = 0, wt_len = 0;
        uint8_t wt_type = 0, wt_flags = 0;
        int32_t wt_book = 0, wt_loop = 0;
        if (wt_ptr != 0) {
            wt_base  = rd_w(rdram, wt_n64 + 0x00);
            wt_len   = rd_w(rdram, wt_n64 + 0x04);
            wt_type  = rd_bu(rdram, wt_n64 + 0x08);
            wt_flags = rd_bu(rdram, wt_n64 + 0x09);
            wt_loop  = rd_w(rdram, wt_n64 + 0x0C);
            wt_book  = rd_w(rdram, wt_n64 + 0x10);
        }

        if (set_wavetable_count <= 3) {
            fprintf(stderr,
                "[LOAD-PARAM SET_WAVETABLE #%d] filter=0x%08X wt=0x%08X\n"
                "  base=0x%08X len=%d (0x%X) type=%d flags=0x%02X\n"
                "  loop=0x%08X book=0x%08X\n",
                set_wavetable_count, (int32_t)filter, wt_ptr,
                wt_base, wt_len, wt_len, wt_type, wt_flags,
                wt_loop, wt_book);
            fflush(stderr);
        }
    } else if (paramID == 4) { // AL_FILTER_RESET
        if (load_param_count <= 3) {
            int32_t table_val = rd_w(rdram, filter + 0x28);
            fprintf(stderr, "[LOAD-PARAM RESET #%d] filter=0x%08X table=0x%08X\n",
                    load_param_count, (int32_t)filter, table_val);
            fflush(stderr);
        }
    }

    // Call the real function
    alLoadParam(rdram, ctx);
}

// --------------------------------------------------------------------------
// alSynStartVoice wrapper
// --------------------------------------------------------------------------
static int syn_start_voice_count = 0;

extern "C" RECOMP_FUNC void alSynStartVoice_wrapper(uint8_t* rdram, recomp_context* ctx) {
    syn_start_voice_count++;

    // a0=synth, a1=voice, a2=wavetable
    uint64_t synth = ctx->r4;
    uint64_t voice = ctx->r5;
    uint64_t wt = ctx->r6;
    int32_t wt_ptr = (int32_t)wt;

    int32_t wt_base = 0, wt_len = 0;
    uint8_t wt_type = 0;
    if (wt_ptr != 0) {
        wt_base = rd_w(rdram, wt + 0x00);
        wt_len  = rd_w(rdram, wt + 0x04);
        wt_type = rd_bu(rdram, wt + 0x08);
    }

    // Check voice+0x08 (pvoice pointer, checked before allocating param)
    int32_t pvoice_ptr = rd_w(rdram, voice + 0x08);

    if (syn_start_voice_count <= 3 || (syn_start_voice_count % 2000) == 0) {
        fprintf(stderr,
            "[SYN-START #%d] synth=0x%08X voice=0x%08X(pv=0x%08X) wt=0x%08X base=0x%08X len=%d type=%d\n",
            syn_start_voice_count, (int32_t)synth, (int32_t)voice, pvoice_ptr,
            wt_ptr, wt_base, wt_len, wt_type);
        fflush(stderr);
    }

    alSynStartVoice(rdram, ctx);
}

// --------------------------------------------------------------------------
// alSynStartVoiceParams wrapper
// --------------------------------------------------------------------------
static int syn_start_params_count = 0;

extern "C" RECOMP_FUNC void alSynStartVoiceParams_wrapper(uint8_t* rdram, recomp_context* ctx) {
    syn_start_params_count++;

    // a0=synth, a1=voice, a2=wavetable, a3=pitch(float bits)
    uint64_t synth = ctx->r4;
    uint64_t voice = ctx->r5;
    uint64_t wt = ctx->r6;
    int32_t wt_ptr = (int32_t)wt;

    int32_t wt_base = 0, wt_len = 0;
    uint8_t wt_type = 0;
    if (wt_ptr != 0) {
        wt_base = rd_w(rdram, wt + 0x00);
        wt_len  = rd_w(rdram, wt + 0x04);
        wt_type = rd_bu(rdram, wt + 0x08);
    }

    int32_t pvoice_ptr = rd_w(rdram, voice + 0x08);

    if (syn_start_params_count <= 3 || (syn_start_params_count % 2000) == 0) {
        fprintf(stderr,
            "[SYN-START-PARAMS #%d] synth=0x%08X voice=0x%08X(pv=0x%08X) wt=0x%08X base=0x%08X len=%d type=%d\n",
            syn_start_params_count, (int32_t)synth, (int32_t)voice, pvoice_ptr,
            wt_ptr, wt_base, wt_len, wt_type);
        fflush(stderr);
    }

    alSynStartVoiceParams(rdram, ctx);
}
