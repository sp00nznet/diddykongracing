// Stub implementations for libultra functions not handled by N64Recomp's
// built-in symbol lists or librecomp.
//
// These are N64-specific OS functions that either:
// - Don't apply to PC (hardware register manipulation)
// - Are debug functions
// - Need minimal stubs for Controller Pak support (DKR uses it for ghosts/replays)

#include "recomp.h"

extern "C" {

// Debug monitor printf - no-op on PC
void rmonPrintf_recomp(uint8_t* rdram, recomp_context* ctx) {
    // N64 debug function, not needed
}

// Set RSP status register - handled by ultramodern's RSP system
void __osSpSetStatus_recomp(uint8_t* rdram, recomp_context* ctx) {
    // RSP status is managed by the runtime
}

// Controller Pak functions - stubbed to return errors (no pak inserted)
// DKR uses Controller Pak for ghost/replay data

void osPfsIsPlug_recomp(uint8_t* rdram, recomp_context* ctx) {
    // Return error - no controller pak
    ctx->r2 = (uint64_t)(int64_t)(int32_t)1; // PFS_ERR_NOPACK
}

void osPfsInit_recomp(uint8_t* rdram, recomp_context* ctx) {
    ctx->r2 = (uint64_t)(int64_t)(int32_t)1; // PFS_ERR_NOPACK
}

void __osSiGetAccess_recomp(uint8_t* rdram, recomp_context* ctx) {
    // SI access semaphore - always grant
    ctx->r2 = 0;
}

void __osPfsGetStatus_recomp(uint8_t* rdram, recomp_context* ctx) {
    ctx->r2 = (uint64_t)(int64_t)(int32_t)1; // error
}

void __osSiRelAccess_recomp(uint8_t* rdram, recomp_context* ctx) {
    // Release SI access - no-op
    ctx->r2 = 0;
}

void __osGetId_recomp(uint8_t* rdram, recomp_context* ctx) {
    ctx->r2 = (uint64_t)(int64_t)(int32_t)1; // error
}

void __osPfsSelectBank_recomp(uint8_t* rdram, recomp_context* ctx) {
    ctx->r2 = (uint64_t)(int64_t)(int32_t)1; // error
}

void __osContRamWrite_recomp(uint8_t* rdram, recomp_context* ctx) {
    ctx->r2 = (uint64_t)(int64_t)(int32_t)1; // error
}

void __osContRamRead_recomp(uint8_t* rdram, recomp_context* ctx) {
    ctx->r2 = (uint64_t)(int64_t)(int32_t)1; // error
}

} // extern "C"
