#ifndef F3DDKR_H
#define F3DDKR_H

#include <cstdint>
#include <cstring>
#include <cmath>

// ============================================================
// f3ddkr HLE - Software renderer for DKR's custom RSP microcode
// ============================================================

// --- RSP (DMA) commands ---
#define F3DDKR_G_SPNOOP     0x00
#define F3DDKR_G_MTX        0x01
#define F3DDKR_G_VTX        0x04
#define F3DDKR_G_TRIN       0x05
#define F3DDKR_G_DL         0x06
#define F3DDKR_G_DMADL      0x07

// --- Immediate commands ---
#define F3DDKR_G_MOVEWORD   0xBC
#define F3DDKR_G_ENDDL      0xB8
#define F3DDKR_G_DMA_OFFSETS 0xBF

// --- RDP commands ---
#define F3DDKR_G_NOOP           0xC0
#define F3DDKR_G_SETCIMG        0xFF
#define F3DDKR_G_SETZIMG        0xFE
#define F3DDKR_G_SETTIMG        0xFD
#define F3DDKR_G_SETCOMBINE     0xFC
#define F3DDKR_G_SETENVCOLOR    0xFB
#define F3DDKR_G_SETPRIMCOLOR   0xFA
#define F3DDKR_G_SETBLENDCOLOR  0xF9
#define F3DDKR_G_SETFOGCOLOR    0xF8
#define F3DDKR_G_SETFILLCOLOR   0xF7
#define F3DDKR_G_FILLRECT       0xF6
#define F3DDKR_G_SETTILE        0xF5
#define F3DDKR_G_LOADTILE       0xF4
#define F3DDKR_G_LOADBLOCK      0xF3
#define F3DDKR_G_SETTILESIZE    0xF2
#define F3DDKR_G_LOADTLUT       0xF0
#define F3DDKR_G_RDPSETOTHERMODE 0xEF
#define F3DDKR_G_SETPRIMDEPTH   0xEE
#define F3DDKR_G_SETSCISSOR     0xED
#define F3DDKR_G_RDPFULLSYNC    0xE9
#define F3DDKR_G_RDPTILESYNC    0xE8
#define F3DDKR_G_RDPPIPESYNC    0xE7
#define F3DDKR_G_RDPLOADSYNC    0xE6
#define F3DDKR_G_TEXRECT        0xE4

// --- G_MOVEWORD indices (from f3ddkr.h) ---
#define F3DDKR_MW_BILLBOARD     0x02
#define F3DDKR_MW_MVPMATRIX     0x0A
#define F3DDKR_MW_SEGMENT       0x06
#define F3DDKR_MW_FOG           0x08

// --- Cycle type extraction from other_mode_h ---
#define G_CYC_1CYCLE    0
#define G_CYC_2CYCLE    1
#define G_CYC_COPY      2
#define G_CYC_FILL      3
#define CYCLE_TYPE_SHIFT 20
#define CYCLE_TYPE_MASK  0x3

// --- Other mode L bit flags ---
#define F3DDKR_AA_EN        0x8
#define F3DDKR_Z_CMP        0x10
#define F3DDKR_Z_UPD        0x20
#define F3DDKR_IM_RD        0x40
#define F3DDKR_CVG_X_ALPHA  0x2000
#define F3DDKR_ALPHA_CVG_SEL 0x4000
#define F3DDKR_FORCE_BL     0x4000  // in cycle bits

// --- Texture format/size ---
#define FMT_RGBA    0
#define FMT_YUV     1
#define FMT_CI      2
#define FMT_IA      3
#define FMT_I       4

#define SIZ_4b      0
#define SIZ_8b      1
#define SIZ_16b     2
#define SIZ_32b     3

// --- Triangle flags ---
#define TRI_BACKFACE_DRAW 0x40

// ============================================================
// RDRAM access helpers (LE host, N64 byte ordering)
// ============================================================

static inline uint32_t rdram_read_u32(uint8_t* rdram, uint32_t phys) {
    return *(uint32_t*)(rdram + (phys & 0x7FFFFF));
}

static inline void rdram_write_u32(uint8_t* rdram, uint32_t phys, uint32_t val) {
    *(uint32_t*)(rdram + (phys & 0x7FFFFF)) = val;
}

static inline uint16_t rdram_read_u16(uint8_t* rdram, uint32_t phys) {
    return *(uint16_t*)(rdram + ((phys & 0x7FFFFF) ^ 2));
}

static inline void rdram_write_u16(uint8_t* rdram, uint32_t phys, uint16_t val) {
    *(uint16_t*)(rdram + ((phys & 0x7FFFFF) ^ 2)) = val;
}

static inline int16_t rdram_read_s16(uint8_t* rdram, uint32_t phys) {
    return (int16_t)rdram_read_u16(rdram, phys);
}

static inline uint8_t rdram_read_u8(uint8_t* rdram, uint32_t phys) {
    return rdram[(phys & 0x7FFFFF) ^ 3];
}

static inline void rdram_write_u8(uint8_t* rdram, uint32_t phys, uint8_t val) {
    rdram[(phys & 0x7FFFFF) ^ 3] = val;
}

// ============================================================
// State structures
// ============================================================

struct TransformedVertex {
    float cx, cy, cz, cw;   // clip-space coordinates
    float sx, sy;            // screen-space (after perspective divide)
    uint8_t r, g, b, a;     // vertex color
};

struct TileDescriptor {
    uint8_t format;
    uint8_t size;       // texel size (0=4b, 1=8b, 2=16b, 3=32b)
    uint16_t line;      // TMEM line stride in 64-bit words
    uint16_t tmem_addr; // TMEM offset in 64-bit words
    uint8_t palette;
    uint8_t clamp_t, mirror_t, mask_t, shift_t;
    uint8_t clamp_s, mirror_s, mask_s, shift_s;
    uint16_t sl, tl, sh, th; // tile size (s10.2 fixed-point)
};

struct F3DDKRState {
    uint8_t* rdram;

    // Color image (framebuffer)
    uint32_t ci_addr;
    uint8_t  ci_format;
    uint8_t  ci_size;     // pixel size (2=16bit, 3=32bit)
    uint16_t ci_width;

    // Z image
    uint32_t zi_addr;

    // Texture image source
    uint32_t ti_addr;
    uint8_t  ti_format;
    uint8_t  ti_size;
    uint16_t ti_width;

    // Colors
    uint32_t fill_color;
    uint32_t env_color;
    uint32_t prim_color;
    uint32_t blend_color;
    uint32_t fog_color;

    // Other mode
    uint32_t other_mode_h;
    uint32_t other_mode_l;

    // Combine mode
    uint64_t combine_mode;

    // Matrices (3 slots: 0=viewport/projection, 1=model, 2=billboard)
    float matrices[3][4][4];
    int active_matrix_index;

    // Vertex buffer
    TransformedVertex vertex_buffer[64];
    int num_vertices;  // total loaded vertices (for append tracking)
    bool billboard_enabled;

    // DMA offsets (G_DMA_OFFSETS / 0xBF)
    uint32_t vertex_dma_offset;
    uint32_t matrix_dma_offset;

    // Segment table
    uint32_t segments[16];

    // Viewport (raw N64 values for vertex transform)
    float vp_scale_x, vp_scale_y; // vscale / 4.0 (preserves sign!)
    float vp_trans_x, vp_trans_y; // vtrans / 4.0
    // Derived positive dimensions for clipping
    float vp_x, vp_y, vp_w, vp_h;
    float vp_near, vp_far;

    // Scissor
    int sc_xl, sc_yl, sc_xh, sc_yh;

    // DL call stack
    static constexpr int MAX_DL_STACK = 16;
    uint32_t dl_stack_addr[MAX_DL_STACK];
    int dl_stack_remaining[MAX_DL_STACK];
    int dl_stack_depth;

    // TMEM
    uint8_t tmem[4096];
    TileDescriptor tiles[8];

    // Logging
    int dl_total_count;     // total DLs processed
    int tri_total_count;    // total triangles submitted
    int cmd_counts[256];    // per-opcode count for logging
};

// ============================================================
// Public API
// ============================================================

void f3ddkr_process_dl(uint8_t* rdram, uint32_t dl_addr, uint32_t dl_size);

#endif // F3DDKR_H
