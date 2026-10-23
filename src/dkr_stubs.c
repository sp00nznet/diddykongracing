// libultra internals that DKR's recompiled code calls but N64ModernRuntime doesn't provide
// (they're on N64Recomp's built-in ignore list, so the recompiler leaves them out).
//
// The controller pak ones report "no pak": DKR keeps ghosts and time-trial data there, and says
// so when it finds none. Emulating a pak is on ROADMAP.md.
#include "recomp.h"

#define PFS_ERR_NOPACK 1
#define RETURN(name, value) RECOMP_FUNC void name(uint8_t* rdram, recomp_context* ctx) { ctx->r2 = (gpr)(int32_t)(value); }

RECOMP_FUNC void rmonPrintf_recomp(uint8_t* rdram, recomp_context* ctx) {}      // debug monitor output
RECOMP_FUNC void __osSpSetStatus_recomp(uint8_t* rdram, recomp_context* ctx) {} // the runtime owns the RSP

RETURN(__osSiGetAccess_recomp, 0)
RETURN(__osSiRelAccess_recomp, 0)
RETURN(osPfsIsPlug_recomp, PFS_ERR_NOPACK)
RETURN(osPfsInit_recomp, PFS_ERR_NOPACK)
RETURN(__osPfsGetStatus_recomp, PFS_ERR_NOPACK)
RETURN(__osGetId_recomp, PFS_ERR_NOPACK)
RETURN(__osPfsSelectBank_recomp, PFS_ERR_NOPACK)
RETURN(__osContRamRead_recomp, PFS_ERR_NOPACK)
RETURN(__osContRamWrite_recomp, PFS_ERR_NOPACK)
