#include "f3ddkr.h"
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cfloat>

// ============================================================
// Global state (single-threaded DL processing)
// ============================================================
static F3DDKRState g_state;
static bool g_initialized = false;
// Log first N occurrences of each opcode (then go silent)
static constexpr int LOG_FIRST_N = 1;

static void log_cmd(uint8_t op, const char* name, uint32_t w0, uint32_t w1) {
    if (g_state.cmd_counts[op] < LOG_FIRST_N) {
        fprintf(stderr, "[F3DDKR] %s (0x%02X): w0=0x%08X w1=0x%08X (count=%d)\n",
                name, op, w0, w1, g_state.cmd_counts[op] + 1);
        fflush(stderr);
    }
    g_state.cmd_counts[op]++;
}

// ============================================================
// Initialization
// ============================================================
static void f3ddkr_init(uint8_t* rdram) {
    memset(&g_state, 0, sizeof(g_state));
    g_state.rdram = rdram;

    // Default viewport: 320x240 centered
    g_state.vp_scale_x = -160.0f; // DKR default: negative
    g_state.vp_scale_y = -120.0f;
    g_state.vp_trans_x = 160.0f;
    g_state.vp_trans_y = 120.0f;
    g_state.vp_x = 0;
    g_state.vp_y = 0;
    g_state.vp_w = 320;
    g_state.vp_h = 240;
    g_state.vp_near = 0.0f;
    g_state.vp_far = 1.0f;

    // Default scissor: full screen
    g_state.sc_xh = 320;
    g_state.sc_yh = 240;

    // Identity matrices
    for (int m = 0; m < 3; m++) {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                g_state.matrices[m][i][j] = (i == j) ? 1.0f : 0.0f;
    }

    g_initialized = true;
}

// ============================================================
// Address resolution
// ============================================================
static inline uint32_t addr_to_phys(uint32_t addr) {
    return addr & 0x7FFFFF;
}

// Resolve a segmented address through the segment table
// Used for RDP image commands (SETCIMG, SETZIMG, SETTIMG) and G_DL
static inline uint32_t resolve_segment(uint32_t addr) {
    uint8_t seg = (addr >> 24) & 0xF;
    uint32_t offset = addr & 0x00FFFFFF;
    uint32_t resolved = g_state.segments[seg] + offset;
    return resolved & 0x7FFFFF;
}

// ============================================================
// Pixel write helpers
// ============================================================
static inline void write_pixel_16(uint8_t* rdram, uint32_t fb_addr, uint32_t fb_width,
                                   int x, int y, uint16_t color16) {
    if (x < 0 || y < 0 || (uint32_t)x >= fb_width) return;
    uint32_t phys = fb_addr + ((uint32_t)y * fb_width + (uint32_t)x) * 2;
    if (phys + 1 >= 0x800000) return;
    rdram_write_u16(rdram, phys, color16);
}

static inline void write_pixel_32(uint8_t* rdram, uint32_t fb_addr, uint32_t fb_width,
                                   int x, int y, uint32_t color32) {
    if (x < 0 || y < 0 || (uint32_t)x >= fb_width) return;
    uint32_t phys = fb_addr + ((uint32_t)y * fb_width + (uint32_t)x) * 4;
    if (phys + 3 >= 0x800000) return;
    rdram_write_u32(rdram, phys, color32);
}

// Read existing framebuffer pixel (for blender)
static inline void read_fb_pixel(int x, int y, uint8_t& r, uint8_t& g, uint8_t& b, uint8_t& a) {
    if (g_state.ci_addr == 0) { r = g = b = a = 0; return; }
    if (g_state.ci_size == SIZ_16b) {
        uint32_t phys = g_state.ci_addr + ((uint32_t)y * g_state.ci_width + (uint32_t)x) * 2;
        if (phys + 1 >= 0x800000) { r = g = b = a = 0; return; }
        uint16_t pixel = rdram_read_u16(g_state.rdram, phys);
        r = ((pixel >> 11) & 0x1F) << 3;
        g = ((pixel >> 6) & 0x1F) << 3;
        b = ((pixel >> 1) & 0x1F) << 3;
        a = (pixel & 1) ? 0xFF : 0;
    } else if (g_state.ci_size == SIZ_32b) {
        uint32_t phys = g_state.ci_addr + ((uint32_t)y * g_state.ci_width + (uint32_t)x) * 4;
        if (phys + 3 >= 0x800000) { r = g = b = a = 0; return; }
        uint32_t pixel = rdram_read_u32(g_state.rdram, phys);
        r = (pixel >> 24) & 0xFF;
        g = (pixel >> 16) & 0xFF;
        b = (pixel >> 8) & 0xFF;
        a = pixel & 0xFF;
    } else {
        r = g = b = a = 0;
    }
}

static inline uint16_t rgba8888_to_rgba5551(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    return ((r >> 3) << 11) | ((g >> 3) << 6) | ((b >> 3) << 1) | (a ? 1 : 0);
}

static inline void rgba5551_to_rgba8888(uint16_t c, uint8_t& r, uint8_t& g, uint8_t& b, uint8_t& a) {
    r = ((c >> 11) & 0x1F) << 3;
    g = ((c >> 6) & 0x1F) << 3;
    b = ((c >> 1) & 0x1F) << 3;
    a = (c & 1) ? 0xFF : 0;
}

// Write a pixel to the framebuffer with RDP blender
// shade_a: raw vertex alpha (pre-combiner), used for A_SHADE blender input
static int g_pixel_write_count = 0;

static void write_fb_pixel(int x, int y, uint8_t r, uint8_t g, uint8_t b, uint8_t a,
                            uint8_t shade_a = 255) {
    if (g_state.ci_addr == 0) return;
    if (x < g_state.sc_xl || x >= g_state.sc_xh || y < g_state.sc_yl || y >= g_state.sc_yh) return;

    // Alpha test: skip fully transparent pixels
    if (a == 0) return;

    // RDP Blender: applies when FORCE_BL is set in 1-cycle or 2-cycle mode
    uint32_t cycle_type = (g_state.other_mode_h >> CYCLE_TYPE_SHIFT) & CYCLE_TYPE_MASK;
    bool do_blend = (cycle_type == G_CYC_1CYCLE || cycle_type == G_CYC_2CYCLE) &&
                    (g_state.other_mode_l & F3DDKR_FORCE_BL);

    if (do_blend) {
        // Read existing framebuffer pixel
        uint8_t mem_r, mem_g, mem_b, mem_a;
        read_fb_pixel(x, y, mem_r, mem_g, mem_b, mem_a);

        // Get blender mux settings
        // In 1-cycle mode: use cycle 0 (c1) settings
        // In 2-cycle mode: use cycle 1 (c2) settings for final output
        int p_sel, a_sel, m_sel, b_sel;
        if (cycle_type == G_CYC_2CYCLE) {
            p_sel = (g_state.other_mode_l >> BL_M1A_1_SHIFT) & 3;
            a_sel = (g_state.other_mode_l >> BL_M1B_1_SHIFT) & 3;
            m_sel = (g_state.other_mode_l >> BL_M2A_1_SHIFT) & 3;
            b_sel = (g_state.other_mode_l >> BL_M2B_1_SHIFT) & 3;
        } else {
            p_sel = (g_state.other_mode_l >> BL_M1A_0_SHIFT) & 3;
            a_sel = (g_state.other_mode_l >> BL_M1B_0_SHIFT) & 3;
            m_sel = (g_state.other_mode_l >> BL_M2A_0_SHIFT) & 3;
            b_sel = (g_state.other_mode_l >> BL_M2B_0_SHIFT) & 3;
        }

        // Select P color (pixel source)
        int pr, pg, pb;
        switch (p_sel) {
            case G_BL_CLR_IN:  pr = r; pg = g; pb = b; break;
            case G_BL_CLR_MEM: pr = mem_r; pg = mem_g; pb = mem_b; break;
            case G_BL_CLR_BL:  pr = (g_state.blend_color >> 24) & 0xFF;
                               pg = (g_state.blend_color >> 16) & 0xFF;
                               pb = (g_state.blend_color >> 8) & 0xFF; break;
            case G_BL_CLR_FOG: pr = (g_state.fog_color >> 24) & 0xFF;
                               pg = (g_state.fog_color >> 16) & 0xFF;
                               pb = (g_state.fog_color >> 8) & 0xFF; break;
            default: pr = pg = pb = 0; break;
        }

        // Select A factor
        int af;
        switch (a_sel) {
            case G_BL_A_IN:    af = a; break;
            case G_BL_A_FOG:   af = (g_state.fog_color & 0xFF); break;
            case G_BL_A_SHADE: af = shade_a; break;
            default:           af = 0; break;
        }

        // Select M color (memory/blend source)
        int mr, mg, mb;
        switch (m_sel) {
            case G_BL_CLR_IN:  mr = r; mg = g; mb = b; break;
            case G_BL_CLR_MEM: mr = mem_r; mg = mem_g; mb = mem_b; break;
            case G_BL_CLR_BL:  mr = (g_state.blend_color >> 24) & 0xFF;
                               mg = (g_state.blend_color >> 16) & 0xFF;
                               mb = (g_state.blend_color >> 8) & 0xFF; break;
            case G_BL_CLR_FOG: mr = (g_state.fog_color >> 24) & 0xFF;
                               mg = (g_state.fog_color >> 16) & 0xFF;
                               mb = (g_state.fog_color >> 8) & 0xFF; break;
            default: mr = mg = mb = 0; break;
        }

        // Select B factor
        int bf;
        switch (b_sel) {
            case G_BL_1MA:   bf = 255 - af; break;
            case G_BL_A_MEM: bf = mem_a; break;
            case G_BL_1:     bf = 255; break;
            default:         bf = 0; break;
        }

        // Blender formula: out = (P * A + M * B) / (A + B)
        int denom = af + bf;
        if (denom > 0) {
            r = (uint8_t)std::clamp((pr * af + mr * bf) / denom, 0, 255);
            g = (uint8_t)std::clamp((pg * af + mg * bf) / denom, 0, 255);
            b = (uint8_t)std::clamp((pb * af + mb * bf) / denom, 0, 255);
        }
        a = 255; // blended pixel has full coverage
    }

    // Write final pixel to framebuffer
    if (g_state.ci_size == SIZ_16b) {
        uint16_t pixel = rgba8888_to_rgba5551(r, g, b, a);
        write_pixel_16(g_state.rdram, g_state.ci_addr, g_state.ci_width, x, y, pixel);
    } else if (g_state.ci_size == SIZ_32b) {
        uint32_t pixel = ((uint32_t)r << 24) | ((uint32_t)g << 16) | ((uint32_t)b << 8) | a;
        write_pixel_32(g_state.rdram, g_state.ci_addr, g_state.ci_width, x, y, pixel);
    }

    g_pixel_write_count++;
}

// ============================================================
// N64 Color Combiner
// ============================================================
// Formula per cycle: color = (A - B) * C + D
//                    alpha = (Aa - Ab) * Ac + Ad

struct CombineInput {
    uint8_t r, g, b, a;
};

// Extract combine mode fields from the 64-bit combine_mode value
struct CombineMode {
    // Cycle 0
    int a0, b0, c0, d0;     // RGB inputs
    int Aa0, Ab0, Ac0, Ad0; // Alpha inputs
    // Cycle 1
    int a1, b1, c1, d1;
    int Aa1, Ab1, Ac1, Ad1;
};

static CombineMode decode_combine_mode() {
    CombineMode cm;
    uint32_t hi = (uint32_t)(g_state.combine_mode >> 32);
    uint32_t lo = (uint32_t)(g_state.combine_mode & 0xFFFFFFFF);

    // Upper 32 bits (data in bits 23:0 after opcode byte)
    cm.a0  = (hi >> 20) & 0xF;
    cm.c0  = (hi >> 15) & 0x1F;
    cm.Aa0 = (hi >> 12) & 0x7;
    cm.Ac0 = (hi >> 9) & 0x7;
    cm.a1  = (hi >> 5) & 0xF;
    cm.c1  = hi & 0x1F;

    // Lower 32 bits
    cm.b0  = (lo >> 28) & 0xF;
    cm.b1  = (lo >> 24) & 0xF;
    cm.Aa1 = (lo >> 21) & 0x7;
    cm.Ac1 = (lo >> 18) & 0x7;
    cm.d0  = (lo >> 15) & 0x7;
    cm.Ab0 = (lo >> 12) & 0x7;
    cm.Ad0 = (lo >> 9) & 0x7;
    cm.d1  = (lo >> 6) & 0x7;
    cm.Ab1 = (lo >> 3) & 0x7;
    cm.Ad1 = lo & 0x7;

    return cm;
}

// Get RGB color for a combine input selector (a/b inputs, 4-bit)
// 0=COMBINED, 1=TEXEL0, 2=TEXEL1, 3=PRIMITIVE, 4=SHADE, 5=ENVIRONMENT, 6=1, 7=NOISE, 8+=0
static inline void get_cc_rgb_ab(int sel, const CombineInput& tex, const CombineInput& shade,
                                  const CombineInput& combined, uint8_t& r, uint8_t& g, uint8_t& b) {
    switch (sel) {
        case 0: r = combined.r; g = combined.g; b = combined.b; break;
        case 1: r = tex.r; g = tex.g; b = tex.b; break;
        case 2: r = tex.r; g = tex.g; b = tex.b; break; // TEXEL1 = TEXEL0 (single texture)
        case 3: r = (g_state.prim_color >> 24) & 0xFF; g = (g_state.prim_color >> 16) & 0xFF; b = (g_state.prim_color >> 8) & 0xFF; break;
        case 4: r = shade.r; g = shade.g; b = shade.b; break;
        case 5: r = (g_state.env_color >> 24) & 0xFF; g = (g_state.env_color >> 16) & 0xFF; b = (g_state.env_color >> 8) & 0xFF; break;
        case 6: r = g = b = 255; break; // 1.0
        default: r = g = b = 0; break;  // NOISE or invalid = 0
    }
}

// Get RGB multiplier for combine input (c input, 5-bit)
// 0=COMBINED, 1=TEXEL0, 2=TEXEL1, 3=PRIMITIVE, 4=SHADE, 5=ENVIRONMENT,
// 6=SCALE(?), 7=COMBINED_ALPHA, 8=TEXEL0_ALPHA, 9=TEXEL1_ALPHA,
// 10=PRIMITIVE_ALPHA, 11=SHADE_ALPHA, 12=ENV_ALPHA, 13=LOD_FRACTION,
// 14=PRIM_LOD_FRAC, 15=K5, 16+=0
static inline void get_cc_rgb_c(int sel, const CombineInput& tex, const CombineInput& shade,
                                 const CombineInput& combined, uint8_t& r, uint8_t& g, uint8_t& b) {
    switch (sel) {
        case 0: r = combined.r; g = combined.g; b = combined.b; break;
        case 1: r = tex.r; g = tex.g; b = tex.b; break;
        case 2: r = tex.r; g = tex.g; b = tex.b; break;
        case 3: r = (g_state.prim_color >> 24) & 0xFF; g = (g_state.prim_color >> 16) & 0xFF; b = (g_state.prim_color >> 8) & 0xFF; break;
        case 4: r = shade.r; g = shade.g; b = shade.b; break;
        case 5: r = (g_state.env_color >> 24) & 0xFF; g = (g_state.env_color >> 16) & 0xFF; b = (g_state.env_color >> 8) & 0xFF; break;
        case 7: r = g = b = combined.a; break;    // COMBINED_ALPHA
        case 8: r = g = b = tex.a; break;          // TEXEL0_ALPHA
        case 9: r = g = b = tex.a; break;          // TEXEL1_ALPHA
        case 10: r = g = b = g_state.prim_color & 0xFF; break; // PRIMITIVE_ALPHA
        case 11: r = g = b = shade.a; break;       // SHADE_ALPHA
        case 12: r = g = b = g_state.env_color & 0xFF; break;  // ENV_ALPHA
        default: r = g = b = 0; break;
    }
}

// Get RGB for d (add) input, 3-bit
// 0=COMBINED, 1=TEXEL0, 2=TEXEL1, 3=PRIMITIVE, 4=SHADE, 5=ENVIRONMENT, 6=1, 7=0
static inline void get_cc_rgb_d(int sel, const CombineInput& tex, const CombineInput& shade,
                                 const CombineInput& combined, uint8_t& r, uint8_t& g, uint8_t& b) {
    switch (sel) {
        case 0: r = combined.r; g = combined.g; b = combined.b; break;
        case 1: r = tex.r; g = tex.g; b = tex.b; break;
        case 2: r = tex.r; g = tex.g; b = tex.b; break;
        case 3: r = (g_state.prim_color >> 24) & 0xFF; g = (g_state.prim_color >> 16) & 0xFF; b = (g_state.prim_color >> 8) & 0xFF; break;
        case 4: r = shade.r; g = shade.g; b = shade.b; break;
        case 5: r = (g_state.env_color >> 24) & 0xFF; g = (g_state.env_color >> 16) & 0xFF; b = (g_state.env_color >> 8) & 0xFF; break;
        case 6: r = g = b = 255; break;
        default: r = g = b = 0; break;
    }
}

// Get alpha for combine input (a/b/d), 3-bit
// 0=COMBINED, 1=TEXEL0, 2=TEXEL1, 3=PRIMITIVE, 4=SHADE, 5=ENVIRONMENT, 6=1, 7=0
static inline uint8_t get_cc_alpha_abd(int sel, const CombineInput& tex, const CombineInput& shade,
                                        const CombineInput& combined) {
    switch (sel) {
        case 0: return combined.a;
        case 1: return tex.a;
        case 2: return tex.a;
        case 3: return g_state.prim_color & 0xFF;
        case 4: return shade.a;
        case 5: return g_state.env_color & 0xFF;
        case 6: return 255;
        default: return 0;
    }
}

// Get alpha multiplier (c input), 3-bit
// 0=LOD_FRACTION, 1=TEXEL0, 2=TEXEL1, 3=PRIMITIVE, 4=SHADE, 5=ENVIRONMENT, 6=PRIM_LOD_FRAC, 7=0
static inline uint8_t get_cc_alpha_c(int sel, const CombineInput& tex, const CombineInput& shade,
                                      const CombineInput& combined) {
    switch (sel) {
        case 0: return 0; // LOD_FRACTION (unimplemented, treat as 0)
        case 1: return tex.a;
        case 2: return tex.a;
        case 3: return g_state.prim_color & 0xFF;
        case 4: return shade.a;
        case 5: return g_state.env_color & 0xFF;
        case 6: return 0; // PRIM_LOD_FRAC (unimplemented)
        default: return 0;
    }
}

// Execute one cycle of the color combiner
static CombineInput combine_cycle(int a_sel, int b_sel, int c_sel, int d_sel,
                                   int Aa_sel, int Ab_sel, int Ac_sel, int Ad_sel,
                                   const CombineInput& tex, const CombineInput& shade,
                                   const CombineInput& combined) {
    uint8_t ar, ag, ab, br, bg, bb, cr, cg, cb, dr, dg, db;
    get_cc_rgb_ab(a_sel, tex, shade, combined, ar, ag, ab);
    get_cc_rgb_ab(b_sel, tex, shade, combined, br, bg, bb);
    get_cc_rgb_c(c_sel, tex, shade, combined, cr, cg, cb);
    get_cc_rgb_d(d_sel, tex, shade, combined, dr, dg, db);

    uint8_t Aa = get_cc_alpha_abd(Aa_sel, tex, shade, combined);
    uint8_t Ab = get_cc_alpha_abd(Ab_sel, tex, shade, combined);
    uint8_t Ac = get_cc_alpha_c(Ac_sel, tex, shade, combined);
    uint8_t Ad = get_cc_alpha_abd(Ad_sel, tex, shade, combined);

    CombineInput result;
    // (A - B) * C + D, all in [0,255] range
    // Use signed math: A-B can be negative, multiply by C/255, add D, clamp to [0,255]
    result.r = (uint8_t)std::clamp(((int)ar - (int)br) * (int)cr / 255 + (int)dr, 0, 255);
    result.g = (uint8_t)std::clamp(((int)ag - (int)bg) * (int)cg / 255 + (int)dg, 0, 255);
    result.b = (uint8_t)std::clamp(((int)ab - (int)bb) * (int)cb / 255 + (int)db, 0, 255);
    result.a = (uint8_t)std::clamp(((int)Aa - (int)Ab) * (int)Ac / 255 + (int)Ad, 0, 255);

    return result;
}

// Run the full color combiner (1-cycle or 2-cycle)
static CombineInput run_color_combiner(const CombineInput& tex, const CombineInput& shade) {
    CombineMode cm = decode_combine_mode();
    uint32_t cycle_type = (g_state.other_mode_h >> CYCLE_TYPE_SHIFT) & CYCLE_TYPE_MASK;

    CombineInput combined = {0, 0, 0, 0};

    // Cycle 0
    combined = combine_cycle(cm.a0, cm.b0, cm.c0, cm.d0,
                              cm.Aa0, cm.Ab0, cm.Ac0, cm.Ad0,
                              tex, shade, combined);

    // Cycle 1 (only for 2-cycle mode)
    if (cycle_type == G_CYC_2CYCLE) {
        combined = combine_cycle(cm.a1, cm.b1, cm.c1, cm.d1,
                                  cm.Aa1, cm.Ab1, cm.Ac1, cm.Ad1,
                                  tex, shade, combined);
    }

    return combined;
}

// ============================================================
// Z-buffer helpers
// ============================================================
static inline uint16_t read_zbuf(int x, int y) {
    if (g_state.zi_addr == 0) return 0;
    uint32_t phys = g_state.zi_addr + ((uint32_t)y * g_state.ci_width + (uint32_t)x) * 2;
    return rdram_read_u16(g_state.rdram, phys);
}

static inline void write_zbuf(int x, int y, uint16_t z) {
    if (g_state.zi_addr == 0) return;
    uint32_t phys = g_state.zi_addr + ((uint32_t)y * g_state.ci_width + (uint32_t)x) * 2;
    rdram_write_u16(g_state.rdram, phys, z);
}

// ============================================================
// Phase 1: Fill Rect
// ============================================================
static void cmd_fill_rect(uint32_t w0, uint32_t w1) {
    // 10.2 fixed-point coordinates
    int lrx = (w0 >> 14) & 0x3FF;
    int lry = w0 & 0x3FF;
    int ulx = (w1 >> 14) & 0x3FF;
    int uly = w1 & 0x3FF;

    // Convert from 10.2 to integer (truncate fractional)
    // Note: G_FILLRECT on N64 — upper-left is inclusive, lower-right is exclusive
    int x0 = ulx >> 2;
    int y0 = uly >> 2;
    int x1 = (lrx >> 2) + 1;
    int y1 = (lry >> 2) + 1;

    // Clamp to scissor
    if (x0 < g_state.sc_xl) x0 = g_state.sc_xl;
    if (y0 < g_state.sc_yl) y0 = g_state.sc_yl;
    if (x1 > g_state.sc_xh) x1 = g_state.sc_xh;
    if (y1 > g_state.sc_yh) y1 = g_state.sc_yh;

    if (g_state.ci_addr == 0) return;

    uint32_t cycle_type = (g_state.other_mode_h >> CYCLE_TYPE_SHIFT) & CYCLE_TYPE_MASK;

    if (cycle_type == G_CYC_FILL) {
        // In fill mode, fill_color is written directly as-is
        if (g_state.ci_size == SIZ_16b) {
            // fill_color contains two 16-bit pixels packed: [pixel1 | pixel0]
            uint16_t color = (uint16_t)(g_state.fill_color >> 16);
            for (int y = y0; y < y1; y++) {
                for (int x = x0; x < x1; x++) {
                    write_pixel_16(g_state.rdram, g_state.ci_addr, g_state.ci_width, x, y, color);
                }
            }
        } else if (g_state.ci_size == SIZ_32b) {
            for (int y = y0; y < y1; y++) {
                for (int x = x0; x < x1; x++) {
                    write_pixel_32(g_state.rdram, g_state.ci_addr, g_state.ci_width, x, y, g_state.fill_color);
                }
            }
        }
    } else {
        // In 1-cycle/2-cycle modes, use env_color or prim_color
        uint8_t r = (g_state.fill_color >> 24) & 0xFF;
        uint8_t g = (g_state.fill_color >> 16) & 0xFF;
        uint8_t b = (g_state.fill_color >> 8) & 0xFF;
        uint8_t a = g_state.fill_color & 0xFF;
        for (int y = y0; y < y1; y++) {
            for (int x = x0; x < x1; x++) {
                write_fb_pixel(x, y, r, g, b, a);
            }
        }
    }
}

// ============================================================
// Phase 2: Matrix loading
// ============================================================

static void load_matrix(uint32_t rdram_addr, int index) {
    if (index < 0 || index > 2) return;
    uint32_t phys = addr_to_phys(rdram_addr);

    // N64 Mtx format: 64 bytes total
    // First 32 bytes: integer halves of 16 elements (as s16, row-major)
    // Next 32 bytes: fractional halves of 16 elements (as u16, row-major)
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int idx = i * 4 + j;
            int16_t int_part = rdram_read_s16(g_state.rdram, phys + idx * 2);
            uint16_t frac_part = rdram_read_u16(g_state.rdram, phys + 32 + idx * 2);
            int32_t fixed = ((int32_t)int_part << 16) | frac_part;
            g_state.matrices[index][i][j] = (float)fixed / 65536.0f;
        }
    }
}

static void cmd_mtx(uint32_t w0, uint32_t w1) {
    // gSPMatrixDKR: gDma1p(pkt, G_MTX, m, sizeof(Mtx), (i) << 6)
    // w0 = (0x01 << 24) | ((param & 0xFF) << 16) | (length & 0xFFFF)
    // param = index << 6, so index = (w0 >> 22) & 0x3
    int index = (w0 >> 22) & 0x3;
    uint32_t addr = w1;

    log_cmd(F3DDKR_G_MTX, "G_MTX", w0, w1);

    // Apply matrix DMA offset if set
    if (g_state.matrix_dma_offset) {
        addr += g_state.matrix_dma_offset;
    }

    load_matrix(addr, index);
}

// ============================================================
// Phase 2: Vertex loading and transform
// ============================================================
static void transform_vertex(float x, float y, float z, int mat_idx,
                              float& cx, float& cy, float& cz, float& cw) {
    const float (*m)[4] = g_state.matrices[mat_idx];
    // N64 row-vector convention: clip = [x, y, z, 1] * matrix
    // result[j] = sum_i(vertex[i] * matrix[i][j])
    cx = m[0][0]*x + m[1][0]*y + m[2][0]*z + m[3][0];
    cy = m[0][1]*x + m[1][1]*y + m[2][1]*z + m[3][1];
    cz = m[0][2]*x + m[1][2]*y + m[2][2]*z + m[3][2];
    cw = m[0][3]*x + m[1][3]*y + m[2][3]*z + m[3][3];
}

static void cmd_vtx(uint32_t w0, uint32_t w1) {
    // gSPVertexDKR: gDma1p(pkt, G_VTX, v, length, param)
    // param at bits [23:16]: ((n-1) << 3) | (v_addr & 6) | append
    // count = ((w0 >> 19) & 0x1F) + 1
    // append = (w0 >> 16) & 1
    int count = ((w0 >> 19) & 0x1F) + 1;
    int append = (w0 >> 16) & 1;
    uint32_t addr = addr_to_phys(w1);

    // Apply vertex DMA offset (set by G_DMA_OFFSETS / 0xBF)
    addr += g_state.vertex_dma_offset;
    addr &= 0x7FFFFF;

    log_cmd(F3DDKR_G_VTX, "G_VTX", w0, w1);

    int start_idx = 0;
    if (append) {
        start_idx = g_state.num_vertices;
    } else {
        g_state.num_vertices = 0;
    }

    // DKR vertex: 10 bytes each (s16 x, s16 y, s16 z, u8 r, u8 g, u8 b, u8 a)
    int loaded = 0;
    for (int i = 0; i < count && (start_idx + i) < 64; i++) {
        uint32_t v_addr = addr + i * 10;

        int16_t vx = rdram_read_s16(g_state.rdram, v_addr + 0);
        int16_t vy = rdram_read_s16(g_state.rdram, v_addr + 2);
        int16_t vz = rdram_read_s16(g_state.rdram, v_addr + 4);
        uint8_t vr = rdram_read_u8(g_state.rdram, v_addr + 6);
        uint8_t vg = rdram_read_u8(g_state.rdram, v_addr + 7);
        uint8_t vb = rdram_read_u8(g_state.rdram, v_addr + 8);
        uint8_t va = rdram_read_u8(g_state.rdram, v_addr + 9);

        TransformedVertex& tv = g_state.vertex_buffer[start_idx + i];
        tv.r = vr;
        tv.g = vg;
        tv.b = vb;
        tv.a = va;

        // Transform by active matrix
        transform_vertex((float)vx, (float)vy, (float)vz, g_state.active_matrix_index,
                         tv.cx, tv.cy, tv.cz, tv.cw);

        // Billboard: add anchor vertex's clip coords
        if (g_state.billboard_enabled && (start_idx + i) > 0) {
            const TransformedVertex& anchor = g_state.vertex_buffer[0];
            tv.cx += anchor.cx;
            tv.cy += anchor.cy;
            tv.cz += anchor.cz;
            tv.cw += anchor.cw;
        }

        // Perspective divide to screen space using N64 viewport transform
        if (fabsf(tv.cw) > 0.0001f) {
            float inv_w = 1.0f / tv.cw;
            tv.sx = tv.cx * inv_w * g_state.vp_scale_x + g_state.vp_trans_x;
            tv.sy = tv.cy * inv_w * g_state.vp_scale_y + g_state.vp_trans_y;
        } else {
            tv.sx = 0;
            tv.sy = 0;
        }

        loaded++;
    }
    g_state.num_vertices = start_idx + loaded;
}

// ============================================================
// Phase 3: TMEM / Texture loading
// ============================================================
static void cmd_settimg(uint32_t w0, uint32_t w1) {
    g_state.ti_format = (w0 >> 21) & 0x7;
    g_state.ti_size = (w0 >> 19) & 0x3;
    g_state.ti_width = (w0 & 0xFFF) + 1;
    g_state.ti_addr = resolve_segment(w1);
    log_cmd(F3DDKR_G_SETTIMG, "G_SETTIMG", w0, w1);
}

static void cmd_settile(uint32_t w0, uint32_t w1) {
    int tile_idx = (w1 >> 24) & 0x7;
    TileDescriptor& t = g_state.tiles[tile_idx];
    t.format = (w0 >> 21) & 0x7;
    t.size = (w0 >> 19) & 0x3;
    t.line = (w0 >> 9) & 0x1FF;
    t.tmem_addr = w0 & 0x1FF;
    t.palette = (w1 >> 20) & 0xF;
    t.clamp_t = (w1 >> 19) & 0x1;
    t.mirror_t = (w1 >> 18) & 0x1;
    t.mask_t = (w1 >> 14) & 0xF;
    t.shift_t = (w1 >> 10) & 0xF;
    t.clamp_s = (w1 >> 9) & 0x1;
    t.mirror_s = (w1 >> 8) & 0x1;
    t.mask_s = (w1 >> 4) & 0xF;
    t.shift_s = w1 & 0xF;
    log_cmd(F3DDKR_G_SETTILE, "G_SETTILE", w0, w1);
}

static void cmd_settilesize(uint32_t w0, uint32_t w1) {
    int tile_idx = (w1 >> 24) & 0x7;
    TileDescriptor& t = g_state.tiles[tile_idx];
    t.sl = (w0 >> 12) & 0xFFF;
    t.tl = w0 & 0xFFF;
    t.sh = (w1 >> 12) & 0xFFF;
    t.th = w1 & 0xFFF;
    log_cmd(F3DDKR_G_SETTILESIZE, "G_SETTILESIZE", w0, w1);
}

static void cmd_loadblock(uint32_t w0, uint32_t w1) {
    int tile_idx = (w1 >> 24) & 0x7;
    uint16_t sl = (w0 >> 12) & 0xFFF;
    uint16_t tl = w0 & 0xFFF;
    uint16_t sh = (w1 >> 12) & 0xFFF; // number of texels - 1
    uint16_t dxt = w1 & 0xFFF;

    log_cmd(F3DDKR_G_LOADBLOCK, "G_LOADBLOCK", w0, w1);

    TileDescriptor& t = g_state.tiles[tile_idx];
    uint32_t tmem_offset = t.tmem_addr * 8; // convert from 64-bit words to bytes

    // Calculate bytes to copy based on texel size
    int num_texels = sh + 1;
    int bytes_per_texel;
    switch (t.size) {
        case SIZ_4b:  bytes_per_texel = 1; num_texels = (num_texels + 1) / 2; break; // 4-bit packed
        case SIZ_8b:  bytes_per_texel = 1; break;
        case SIZ_16b: bytes_per_texel = 2; break;
        case SIZ_32b: bytes_per_texel = 4; break;
        default:      bytes_per_texel = 2; break;
    }
    if (t.size == SIZ_4b) {
        bytes_per_texel = 1; // already adjusted num_texels
    }

    // For RGBA32 textures, LOADBLOCK uses SIZ_16b on the tile with 2x texel count,
    // but the texture image (ti_size) tells us the true format
    bool is_rgba32 = (g_state.ti_size == SIZ_32b);

    if (is_rgba32) {
        // RGBA32: interleave into two TMEM banks
        // Low bank (0x000-0x7FF): R,G bytes
        // High bank (0x800-0xFFF): B,A bytes
        // When tile uses SIZ_16b for loading, num_texels counts 16-bit units (2x actual)
        // When tile uses SIZ_32b, num_texels is already the 32-bit texel count
        int actual_texels = (t.size == SIZ_16b) ? num_texels / 2 : num_texels;
        for (int i = 0; i < actual_texels; i++) {
            uint32_t src = g_state.ti_addr + i * 4;
            uint32_t lo = tmem_offset + i * 2;
            uint32_t hi = lo + 0x800;
            if (lo + 1 >= 2048 || hi + 1 >= 4096) break;
            g_state.tmem[lo]     = rdram_read_u8(g_state.rdram, src + 0); // R
            g_state.tmem[lo + 1] = rdram_read_u8(g_state.rdram, src + 1); // G
            g_state.tmem[hi]     = rdram_read_u8(g_state.rdram, src + 2); // B
            g_state.tmem[hi + 1] = rdram_read_u8(g_state.rdram, src + 3); // A
        }
    } else {
        uint32_t bytes_to_copy = num_texels * bytes_per_texel;
        if (bytes_to_copy > 4096 - tmem_offset) {
            bytes_to_copy = 4096 - tmem_offset;
        }

        // Copy from RDRAM to TMEM byte by byte
        for (uint32_t i = 0; i < bytes_to_copy; i++) {
            g_state.tmem[tmem_offset + i] = rdram_read_u8(g_state.rdram, g_state.ti_addr + i);
        }
    }
}

static void cmd_loadtile(uint32_t w0, uint32_t w1) {
    int tile_idx = (w1 >> 24) & 0x7;
    log_cmd(F3DDKR_G_LOADTILE, "G_LOADTILE", w0, w1);

    TileDescriptor& t = g_state.tiles[tile_idx];

    uint16_t sl = (w0 >> 12) & 0xFFF;
    uint16_t tl = w0 & 0xFFF;
    uint16_t sh = (w1 >> 12) & 0xFFF;
    uint16_t th = w1 & 0xFFF;

    // Convert from 10.2 fixed-point to integer
    int x0 = sl >> 2, y0 = tl >> 2;
    int x1 = sh >> 2, y1 = th >> 2;
    int width = x1 - x0 + 1;
    int height = y1 - y0 + 1;

    int bytes_per_texel;
    switch (t.size) {
        case SIZ_4b:  bytes_per_texel = 0; break; // special
        case SIZ_8b:  bytes_per_texel = 1; break;
        case SIZ_16b: bytes_per_texel = 2; break;
        case SIZ_32b: bytes_per_texel = 4; break;
        default:      bytes_per_texel = 2; break;
    }

    uint32_t tmem_offset = t.tmem_addr * 8;
    uint32_t src_line_bytes = g_state.ti_width * (bytes_per_texel ? bytes_per_texel : 1);

    for (int row = 0; row < height; row++) {
        uint32_t tmem_row = tmem_offset + row * t.line * 8;

        if (t.size == SIZ_32b) {
            // RGBA32: interleave R,G to low bank, B,A to high bank
            for (int col = 0; col < width; col++) {
                uint32_t src_addr = g_state.ti_addr + ((y0 + row) * g_state.ti_width + x0 + col) * 4;
                uint32_t lo = tmem_row + col * 2;
                uint32_t hi = lo + 0x800;
                if (lo + 1 >= 2048 || hi + 1 >= 4096) break;
                g_state.tmem[lo]     = rdram_read_u8(g_state.rdram, src_addr + 0); // R
                g_state.tmem[lo + 1] = rdram_read_u8(g_state.rdram, src_addr + 1); // G
                g_state.tmem[hi]     = rdram_read_u8(g_state.rdram, src_addr + 2); // B
                g_state.tmem[hi + 1] = rdram_read_u8(g_state.rdram, src_addr + 3); // A
            }
        } else {
            int row_bytes;
            if (t.size == SIZ_4b) {
                row_bytes = (width + 1) / 2;
            } else {
                row_bytes = width * bytes_per_texel;
            }
            if (tmem_row + (uint32_t)row_bytes > 4096) break;

            for (int col = 0; col < row_bytes; col++) {
                uint32_t src_addr = g_state.ti_addr;
                if (t.size == SIZ_4b) {
                    src_addr += (y0 + row) * ((g_state.ti_width + 1) / 2) + x0 / 2 + col;
                } else {
                    src_addr += ((y0 + row) * g_state.ti_width + x0) * bytes_per_texel + col;
                }
                g_state.tmem[tmem_row + col] = rdram_read_u8(g_state.rdram, src_addr);
            }
        }
    }
}

static void cmd_loadtlut(uint32_t w0, uint32_t w1) {
    int tile_idx = (w1 >> 24) & 0x7;
    uint16_t sh = (w1 >> 12) & 0xFFF;
    int count = (sh >> 2) + 1; // number of palette entries

    log_cmd(F3DDKR_G_LOADTLUT, "G_LOADTLUT", w0, w1);

    TileDescriptor& t = g_state.tiles[tile_idx];
    uint32_t tmem_offset = t.tmem_addr * 8;

    // TLUT entries are 16-bit, loaded into upper half of TMEM (0x800+)
    for (int i = 0; i < count && i < 256; i++) {
        uint16_t entry = rdram_read_u16(g_state.rdram, g_state.ti_addr + i * 2);
        if (tmem_offset + i * 2 + 1 < 4096) {
            // Store in TMEM as big-endian 16-bit
            g_state.tmem[tmem_offset + i * 2] = (entry >> 8) & 0xFF;
            g_state.tmem[tmem_offset + i * 2 + 1] = entry & 0xFF;
        }
    }
}

// ============================================================
// Phase 3: Texture sampling
// ============================================================
static inline uint16_t tmem_read_u16(uint32_t tmem_byte_addr) {
    if (tmem_byte_addr + 1 >= 4096) return 0;
    return ((uint16_t)g_state.tmem[tmem_byte_addr] << 8) | g_state.tmem[tmem_byte_addr + 1];
}

static inline uint32_t tmem_read_u32(uint32_t tmem_byte_addr) {
    if (tmem_byte_addr + 3 >= 4096) return 0;
    return ((uint32_t)g_state.tmem[tmem_byte_addr] << 24) |
           ((uint32_t)g_state.tmem[tmem_byte_addr + 1] << 16) |
           ((uint32_t)g_state.tmem[tmem_byte_addr + 2] << 8) |
           g_state.tmem[tmem_byte_addr + 3];
}

// Wrap/clamp/mirror a texture coordinate
static inline int wrap_coord(int coord, int mask, int clamp, int mirror, int tile_size) {
    if (clamp) {
        if (coord < 0) return 0;
        if (coord > tile_size) return tile_size;
        return coord;
    }
    if (mask) {
        int wrapped = coord & ((1 << mask) - 1);
        if (mirror && (coord & (1 << mask))) {
            wrapped = ((1 << mask) - 1) - wrapped;
        }
        return wrapped;
    }
    return coord;
}

// Sample a texel from TMEM
static void sample_texel(int tile_idx, int s, int t,
                          uint8_t& r, uint8_t& g_out, uint8_t& b, uint8_t& a) {
    const TileDescriptor& td = g_state.tiles[tile_idx];

    int s_wrapped = wrap_coord(s, td.mask_s, td.clamp_s, td.mirror_s, (td.sh - td.sl) >> 2);
    int t_wrapped = wrap_coord(t, td.mask_t, td.clamp_t, td.mirror_t, (td.th - td.tl) >> 2);

    uint32_t tmem_base = td.tmem_addr * 8;
    uint32_t line_stride = td.line * 8; // bytes per row in TMEM

    switch (td.format) {
        case FMT_RGBA: {
            if (td.size == SIZ_16b) {
                uint32_t addr = tmem_base + t_wrapped * line_stride + s_wrapped * 2;
                uint16_t texel = tmem_read_u16(addr);
                rgba5551_to_rgba8888(texel, r, g_out, b, a);
            } else if (td.size == SIZ_32b) {
                // RGBA32: R,G in low bank, B,A in high bank (+0x800)
                uint32_t lo_addr = (tmem_base + t_wrapped * line_stride + s_wrapped * 2) & 0x7FF;
                uint32_t hi_addr = lo_addr + 0x800;
                r = (lo_addr + 1 < 2048) ? g_state.tmem[lo_addr] : 0;
                g_out = (lo_addr + 1 < 2048) ? g_state.tmem[lo_addr + 1] : 0;
                b = (hi_addr + 1 < 4096) ? g_state.tmem[hi_addr] : 0;
                a = (hi_addr + 1 < 4096) ? g_state.tmem[hi_addr + 1] : 0;
            } else {
                r = g_out = b = a = 0xFF;
            }
            break;
        }
        case FMT_CI: {
            uint8_t ci;
            if (td.size == SIZ_4b) {
                uint32_t addr = tmem_base + t_wrapped * line_stride + s_wrapped / 2;
                if (addr < 4096) {
                    uint8_t byte = g_state.tmem[addr];
                    ci = (s_wrapped & 1) ? (byte & 0x0F) : ((byte >> 4) & 0x0F);
                } else {
                    ci = 0;
                }
                // Look up in TLUT (palette)
                uint32_t tlut_base = 0x800 + td.palette * 16 * 2; // Each palette is 16 entries * 2 bytes
                uint16_t texel = tmem_read_u16(tlut_base + ci * 2);
                rgba5551_to_rgba8888(texel, r, g_out, b, a);
            } else if (td.size == SIZ_8b) {
                uint32_t addr = tmem_base + t_wrapped * line_stride + s_wrapped;
                ci = (addr < 4096) ? g_state.tmem[addr] : 0;
                // 256-color palette in upper TMEM
                uint32_t tlut_base = 0x800;
                uint16_t texel = tmem_read_u16(tlut_base + ci * 2);
                rgba5551_to_rgba8888(texel, r, g_out, b, a);
            } else {
                r = g_out = b = a = 0xFF;
            }
            break;
        }
        case FMT_IA: {
            if (td.size == SIZ_16b) {
                uint32_t addr = tmem_base + t_wrapped * line_stride + s_wrapped * 2;
                uint16_t texel = tmem_read_u16(addr);
                r = g_out = b = (texel >> 8) & 0xFF;
                a = texel & 0xFF;
            } else if (td.size == SIZ_8b) {
                uint32_t addr = tmem_base + t_wrapped * line_stride + s_wrapped;
                uint8_t texel = (addr < 4096) ? g_state.tmem[addr] : 0;
                r = g_out = b = (texel >> 4) << 4; // I4
                a = (texel & 0xF) << 4;             // A4
            } else if (td.size == SIZ_4b) {
                uint32_t addr = tmem_base + t_wrapped * line_stride + s_wrapped / 2;
                uint8_t byte = (addr < 4096) ? g_state.tmem[addr] : 0;
                uint8_t nib = (s_wrapped & 1) ? (byte & 0x0F) : ((byte >> 4) & 0x0F);
                r = g_out = b = (nib >> 1) << 5; // I3
                a = (nib & 1) ? 0xFF : 0;         // A1
            } else {
                r = g_out = b = a = 0xFF;
            }
            break;
        }
        case FMT_I: {
            if (td.size == SIZ_8b) {
                uint32_t addr = tmem_base + t_wrapped * line_stride + s_wrapped;
                uint8_t texel = (addr < 4096) ? g_state.tmem[addr] : 0;
                r = g_out = b = a = texel;
            } else if (td.size == SIZ_4b) {
                uint32_t addr = tmem_base + t_wrapped * line_stride + s_wrapped / 2;
                uint8_t byte = (addr < 4096) ? g_state.tmem[addr] : 0;
                uint8_t nib = (s_wrapped & 1) ? (byte & 0x0F) : ((byte >> 4) & 0x0F);
                r = g_out = b = a = (nib << 4) | nib;
            } else {
                r = g_out = b = a = 0xFF;
            }
            break;
        }
        default:
            r = g_out = b = 0xFF;
            a = 0xFF;
            break;
    }
}

// ============================================================
// Phase 2 & 3: Triangle rasterizer
// ============================================================

// Edge structure for scanline rasterizer
struct Edge {
    float x;         // current x position
    float dx;        // x increment per scanline
    float z, dz;     // z interpolation
    float r, g, b, a;
    float dr, dg, db, da;
    float u, v;      // texture coords
    float du, dv;
    int y_start, y_end;
};

static void init_edge(Edge& e, const TransformedVertex& v0, const TransformedVertex& v1,
                       float u0, float v0_tc, float u1, float v1_tc) {
    float dy = v1.sy - v0.sy;
    if (fabsf(dy) < 0.001f) {
        e.y_start = e.y_end = (int)v0.sy;
        return;
    }

    e.y_start = (int)ceilf(v0.sy);
    e.y_end = (int)ceilf(v1.sy);

    float inv_dy = 1.0f / dy;
    float prestep = (float)e.y_start - v0.sy;

    e.dx = (v1.sx - v0.sx) * inv_dy;
    e.x = v0.sx + prestep * e.dx;

    // Z interpolation (use cz/cw for depth)
    float z0 = (v0.cw != 0) ? v0.cz / v0.cw : 0;
    float z1 = (v1.cw != 0) ? v1.cz / v1.cw : 0;
    e.dz = (z1 - z0) * inv_dy;
    e.z = z0 + prestep * e.dz;

    // Color interpolation
    e.dr = ((float)v1.r - (float)v0.r) * inv_dy;
    e.dg = ((float)v1.g - (float)v0.g) * inv_dy;
    e.db = ((float)v1.b - (float)v0.b) * inv_dy;
    e.da = ((float)v1.a - (float)v0.a) * inv_dy;
    e.r = (float)v0.r + prestep * e.dr;
    e.g = (float)v0.g + prestep * e.dg;
    e.b = (float)v0.b + prestep * e.db;
    e.a = (float)v0.a + prestep * e.da;

    // UV interpolation
    e.du = (u1 - u0) * inv_dy;
    e.dv = (v1_tc - v0_tc) * inv_dy;
    e.u = u0 + prestep * e.du;
    e.v = v0_tc + prestep * e.dv;
}

static void draw_scanline(int y, float x_left, float x_right,
                           float zl, float zr,
                           float rl, float gl, float bl, float al,
                           float rr, float gr, float br, float ar,
                           float ul, float vl, float ur, float vr,
                           bool textured, int tile_idx, bool z_test) {
    int xl = (int)ceilf(x_left);
    int xr = (int)ceilf(x_right);

    if (xl >= xr) return;
    if (y < g_state.sc_yl || y >= g_state.sc_yh) return;
    if (xl < g_state.sc_xl) xl = g_state.sc_xl;
    if (xr > g_state.sc_xh) xr = g_state.sc_xh;

    float dx = x_right - x_left;
    if (fabsf(dx) < 0.001f) return;
    float inv_dx = 1.0f / dx;

    float prestep = (float)xl - x_left;

    float dz = (zr - zl) * inv_dx;
    float z = zl + prestep * dz;

    float dr = (rr - rl) * inv_dx, cur_r = rl + prestep * dr;
    float dg = (gr - gl) * inv_dx, cur_g = gl + prestep * dg;
    float db = (br - bl) * inv_dx, cur_b = bl + prestep * db;
    float da = (ar - al) * inv_dx, cur_a = al + prestep * da;

    float du_dx = 0, dv_dx = 0, cur_u = 0, cur_v = 0;
    if (textured) {
        du_dx = (ur - ul) * inv_dx;
        dv_dx = (vr - vl) * inv_dx;
        cur_u = ul + prestep * du_dx;
        cur_v = vl + prestep * dv_dx;
    }

    for (int x = xl; x < xr; x++) {
        // Z-buffer test
        if (z_test) {
            // Convert z from [-1,1] to [0, 0x7FFF]
            uint16_t z16 = (uint16_t)std::clamp((z * 0.5f + 0.5f) * 0x7FFF, 0.0f, (float)0x7FFF);
            uint16_t existing_z = read_zbuf(x, y);
            if (z16 >= existing_z) {
                z += dz;
                cur_r += dr; cur_g += dg; cur_b += db; cur_a += da;
                if (textured) { cur_u += du_dx; cur_v += dv_dx; }
                continue;
            }
            // Write new z
            if (g_state.other_mode_l & F3DDKR_Z_UPD) {
                write_zbuf(x, y, z16);
            }
        }

        uint8_t pr, pg, pb, pa;
        pr = (uint8_t)std::clamp(cur_r, 0.0f, 255.0f);
        pg = (uint8_t)std::clamp(cur_g, 0.0f, 255.0f);
        pb = (uint8_t)std::clamp(cur_b, 0.0f, 255.0f);
        pa = (uint8_t)std::clamp(cur_a, 0.0f, 255.0f);

        CombineInput shade_in = { pr, pg, pb, pa };
        CombineInput tex_in = { 0, 0, 0, 255 };

        if (textured) {
            int si = (int)floorf(cur_u);
            int ti = (int)floorf(cur_v);
            sample_texel(tile_idx, si, ti, tex_in.r, tex_in.g, tex_in.b, tex_in.a);
        }

        // Run color combiner, then blender (shade_a = pre-combiner vertex alpha)
        CombineInput out = run_color_combiner(tex_in, shade_in);
        write_fb_pixel(x, y, out.r, out.g, out.b, out.a, pa);

        z += dz;
        cur_r += dr; cur_g += dg; cur_b += db; cur_a += da;
        if (textured) { cur_u += du_dx; cur_v += dv_dx; }
    }
}

// Rasterize a single triangle
static void rasterize_triangle(const TransformedVertex& v0, const TransformedVertex& v1,
                                const TransformedVertex& v2,
                                float u0, float v0_tc, float u1, float v1_tc,
                                float u2, float v2_tc,
                                bool textured, int tile_idx) {
    // Sort vertices by Y coordinate (v_top.sy <= v_mid.sy <= v_bot.sy)
    const TransformedVertex* verts[3] = { &v0, &v1, &v2 };
    float uvs[3][2] = { {u0, v0_tc}, {u1, v1_tc}, {u2, v2_tc} };

    // Simple bubble sort by sy
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2 - i; j++) {
            if (verts[j]->sy > verts[j+1]->sy) {
                std::swap(verts[j], verts[j+1]);
                std::swap(uvs[j][0], uvs[j+1][0]);
                std::swap(uvs[j][1], uvs[j+1][1]);
            }
        }
    }

    const TransformedVertex& top = *verts[0];
    const TransformedVertex& mid = *verts[1];
    const TransformedVertex& bot = *verts[2];

    bool z_test = (g_state.other_mode_l & F3DDKR_Z_CMP) != 0;

    // Degenerate triangle check
    if ((int)ceilf(top.sy) >= (int)ceilf(bot.sy)) return;

    // Build edges: top->bot (long edge), top->mid (short edge 1), mid->bot (short edge 2)
    Edge long_edge, short1, short2;
    init_edge(long_edge, top, bot, uvs[0][0], uvs[0][1], uvs[2][0], uvs[2][1]);
    init_edge(short1, top, mid, uvs[0][0], uvs[0][1], uvs[1][0], uvs[1][1]);
    init_edge(short2, mid, bot, uvs[1][0], uvs[1][1], uvs[2][0], uvs[2][1]);

    // Upper half: top to mid
    for (int y = short1.y_start; y < short1.y_end && y < (int)g_state.vp_h + (int)g_state.vp_y; y++) {
        if (y >= 0) {
            float xl = long_edge.x, xr = short1.x;
            float zl = long_edge.z, zr = short1.z;
            float rl = long_edge.r, rr = short1.r;
            float gl_c = long_edge.g, gr_c = short1.g;
            float bl = long_edge.b, br = short1.b;
            float al = long_edge.a, ar = short1.a;
            float ul = long_edge.u, ur_c = short1.u;
            float vl = long_edge.v, vr_c = short1.v;

            if (xl > xr) {
                std::swap(xl, xr); std::swap(zl, zr);
                std::swap(rl, rr); std::swap(gl_c, gr_c);
                std::swap(bl, br); std::swap(al, ar);
                std::swap(ul, ur_c); std::swap(vl, vr_c);
            }
            draw_scanline(y, xl, xr, zl, zr, rl, gl_c, bl, al, rr, gr_c, br, ar,
                          ul, vl, ur_c, vr_c, textured, tile_idx, z_test);
        }
        long_edge.x += long_edge.dx; long_edge.z += long_edge.dz;
        long_edge.r += long_edge.dr; long_edge.g += long_edge.dg;
        long_edge.b += long_edge.db; long_edge.a += long_edge.da;
        long_edge.u += long_edge.du; long_edge.v += long_edge.dv;
        short1.x += short1.dx; short1.z += short1.dz;
        short1.r += short1.dr; short1.g += short1.dg;
        short1.b += short1.db; short1.a += short1.da;
        short1.u += short1.du; short1.v += short1.dv;
    }

    // Lower half: mid to bot
    for (int y = short2.y_start; y < short2.y_end && y < (int)g_state.vp_h + (int)g_state.vp_y; y++) {
        if (y >= 0) {
            float xl = long_edge.x, xr = short2.x;
            float zl = long_edge.z, zr = short2.z;
            float rl = long_edge.r, rr = short2.r;
            float gl_c = long_edge.g, gr_c = short2.g;
            float bl = long_edge.b, br = short2.b;
            float al = long_edge.a, ar = short2.a;
            float ul = long_edge.u, ur_c = short2.u;
            float vl = long_edge.v, vr_c = short2.v;

            if (xl > xr) {
                std::swap(xl, xr); std::swap(zl, zr);
                std::swap(rl, rr); std::swap(gl_c, gr_c);
                std::swap(bl, br); std::swap(al, ar);
                std::swap(ul, ur_c); std::swap(vl, vr_c);
            }
            draw_scanline(y, xl, xr, zl, zr, rl, gl_c, bl, al, rr, gr_c, br, ar,
                          ul, vl, ur_c, vr_c, textured, tile_idx, z_test);
        }
        long_edge.x += long_edge.dx; long_edge.z += long_edge.dz;
        long_edge.r += long_edge.dr; long_edge.g += long_edge.dg;
        long_edge.b += long_edge.db; long_edge.a += long_edge.da;
        long_edge.u += long_edge.du; long_edge.v += long_edge.dv;
        short2.x += short2.dx; short2.z += short2.dz;
        short2.r += short2.dr; short2.g += short2.dg;
        short2.b += short2.db; short2.a += short2.da;
        short2.u += short2.du; short2.v += short2.dv;
    }
}

// ============================================================
// Phase 2: G_TRIN handler
// ============================================================
static void cmd_trin(uint32_t w0, uint32_t w1) {
    // gSPPolygon: w0 = (G_TRIN << 24) | (((numTris-1) << 4) | texEnabled) << 16) | (numTris*16)
    int count = ((w0 >> 20) & 0xF) + 1;
    int tex_enabled = (w0 >> 16) & 0x1;
    uint32_t addr = addr_to_phys(w1);

    log_cmd(F3DDKR_G_TRIN, "G_TRIN", w0, w1);

    for (int i = 0; i < count; i++) {
        uint32_t tri_addr = addr + i * 16;

        // Triangle struct: flags(1), vi0(1), vi1(1), vi2(1), uv0(4), uv1(4), uv2(4)
        uint8_t flags = rdram_read_u8(g_state.rdram, tri_addr + 0);
        uint8_t vi0   = rdram_read_u8(g_state.rdram, tri_addr + 1);
        uint8_t vi1   = rdram_read_u8(g_state.rdram, tri_addr + 2);
        uint8_t vi2   = rdram_read_u8(g_state.rdram, tri_addr + 3);

        // Bounds check
        if (vi0 >= 64 || vi1 >= 64 || vi2 >= 64) continue;

        const TransformedVertex& v0 = g_state.vertex_buffer[vi0];
        const TransformedVertex& v1 = g_state.vertex_buffer[vi1];
        const TransformedVertex& v2 = g_state.vertex_buffer[vi2];

        g_state.tri_total_count++;

        // Skip if any vertex is behind camera (w <= 0)
        if (v0.cw <= 0.001f || v1.cw <= 0.001f || v2.cw <= 0.001f) continue;

        // Backface culling using screen-space cross product
        float cross = (v1.sx - v0.sx) * (v2.sy - v0.sy) - (v2.sx - v0.sx) * (v1.sy - v0.sy);
        if (!(flags & TRI_BACKFACE_DRAW)) {
            if (cross <= 0.0f) continue;
        }

        // UV coordinates from triangle struct (s10.5 fixed-point → s16)
        float u0 = 0, v0_tc = 0, u1 = 0, v1_tc = 0, u2 = 0, v2_tc = 0;
        if (tex_enabled) {
            int16_t raw_u0 = rdram_read_s16(g_state.rdram, tri_addr + 4);
            int16_t raw_v0 = rdram_read_s16(g_state.rdram, tri_addr + 6);
            int16_t raw_u1 = rdram_read_s16(g_state.rdram, tri_addr + 8);
            int16_t raw_v1 = rdram_read_s16(g_state.rdram, tri_addr + 10);
            int16_t raw_u2 = rdram_read_s16(g_state.rdram, tri_addr + 12);
            int16_t raw_v2 = rdram_read_s16(g_state.rdram, tri_addr + 14);

            // Convert s10.5 fixed-point to float
            u0 = raw_u0 / 32.0f;
            v0_tc = raw_v0 / 32.0f;
            u1 = raw_u1 / 32.0f;
            v1_tc = raw_v1 / 32.0f;
            u2 = raw_u2 / 32.0f;
            v2_tc = raw_v2 / 32.0f;
        }

        rasterize_triangle(v0, v1, v2, u0, v0_tc, u1, v1_tc, u2, v2_tc,
                           tex_enabled != 0, 0); // tile 0 by default
    }

    // Reset vertex index after drawing (matches GLideN64)
    g_state.num_vertices = 0;
}

// ============================================================
// Phase 3: G_TEXRECT handler
// ============================================================
static void cmd_texrect(uint32_t w0, uint32_t w1, uint32_t st_word, uint32_t dsdx_word) {
    // G_TEXRECT: 3-command sequence
    // w0/w1: rect coords + tile
    // st_word: (S << 16) | T from RDPHALF_1
    // dsdx_word: (dSdX << 16) | dTdY from RDPHALF_2
    int lrx = (w0 >> 12) & 0xFFF;
    int lry = w0 & 0xFFF;
    int tile_idx = (w1 >> 24) & 0x7;
    int ulx = (w1 >> 12) & 0xFFF;
    int uly = w1 & 0xFFF;

    int16_t s = (int16_t)(st_word >> 16);
    int16_t t = (int16_t)(st_word & 0xFFFF);
    int16_t dsdx = (int16_t)(dsdx_word >> 16);
    int16_t dtdy = (int16_t)(dsdx_word & 0xFFFF);

    log_cmd(F3DDKR_G_TEXRECT, "G_TEXRECT", w0, w1);

    // Convert 10.2 fixed-point coords to integer
    int x0 = ulx >> 2;
    int y0 = uly >> 2;
    int x1 = lrx >> 2;
    int y1 = lry >> 2;

    // Clamp to scissor
    if (x0 < g_state.sc_xl) x0 = g_state.sc_xl;
    if (y0 < g_state.sc_yl) y0 = g_state.sc_yl;
    if (x1 >= g_state.sc_xh) x1 = g_state.sc_xh - 1;
    if (y1 >= g_state.sc_yh) y1 = g_state.sc_yh - 1;

    // s and t are s10.5 fixed-point, dsdx and dtdy are s5.10 fixed-point
    float fs = s / 32.0f;
    float ft = t / 32.0f;
    float fdsdx = dsdx / 1024.0f;
    float fdtdy = dtdy / 1024.0f;

    uint32_t cycle_type = (g_state.other_mode_h >> CYCLE_TYPE_SHIFT) & CYCLE_TYPE_MASK;
    bool copy_mode = (cycle_type == G_CYC_COPY);

    float cur_t = ft;
    for (int y = y0; y <= y1; y++) {
        float cur_s = fs;
        for (int x = x0; x <= x1; x++) {
            uint8_t tr, tg, tb, ta;
            int si = (int)floorf(cur_s);
            int ti = (int)floorf(cur_t);
            sample_texel(tile_idx, si, ti, tr, tg, tb, ta);

            if (copy_mode) {
                // In copy mode, write texel directly (no combiner/blender)
                write_fb_pixel(x, y, tr, tg, tb, ta);
            } else {
                // Run color combiner
                CombineInput tex_in = { tr, tg, tb, ta };
                CombineInput shade_in = { 255, 255, 255, 255 }; // TEXRECT has no shade
                CombineInput out = run_color_combiner(tex_in, shade_in);
                write_fb_pixel(x, y, out.r, out.g, out.b, out.a);
            }
            cur_s += fdsdx;
        }
        cur_t += fdtdy;
    }
}

// ============================================================
// Command handlers: color, mode, flow control
// ============================================================
static void cmd_setcimg(uint32_t w0, uint32_t w1) {
    g_state.ci_format = (w0 >> 21) & 0x7;
    g_state.ci_size = (w0 >> 19) & 0x3;
    g_state.ci_width = (w0 & 0xFFF) + 1;
    uint32_t old_ci = g_state.ci_addr;
    g_state.ci_addr = resolve_segment(w1);
    // Log CI changes only for first few
    if (g_state.cmd_counts[F3DDKR_G_SETCIMG] < LOG_FIRST_N) {
        fprintf(stderr, "[F3DDKR] G_SETCIMG: phys=0x%06X (was 0x%06X) fmt=%d siz=%d w=%d\n",
                g_state.ci_addr, old_ci, g_state.ci_format, g_state.ci_size, g_state.ci_width);
        fflush(stderr);
    }
    g_state.cmd_counts[F3DDKR_G_SETCIMG]++;
}

static void cmd_setzimg(uint32_t w0, uint32_t w1) {
    g_state.zi_addr = resolve_segment(w1);
    if (g_state.cmd_counts[F3DDKR_G_SETZIMG] < LOG_FIRST_N) {
        fprintf(stderr, "[F3DDKR] G_SETZIMG (0xFE): w1=0x%08X -> phys=0x%06X\n",
                w1, g_state.zi_addr);
        fflush(stderr);
    }
    g_state.cmd_counts[F3DDKR_G_SETZIMG]++;
}

static void cmd_moveword(uint32_t w0, uint32_t w1) {
    uint8_t index = w0 & 0xFF;
    uint16_t offset = (w0 >> 8) & 0xFFFF;

    switch (index) {
        case F3DDKR_MW_BILLBOARD:
            g_state.billboard_enabled = (w1 & 1) != 0;
            log_cmd(F3DDKR_G_MOVEWORD, "G_MOVEWORD(billboard)", w0, w1);
            break;
        case F3DDKR_MW_MVPMATRIX:
            g_state.active_matrix_index = (w1 >> 6) & 0x3;
            log_cmd(F3DDKR_G_MOVEWORD, "G_MOVEWORD(matrix)", w0, w1);
            break;
        case F3DDKR_MW_SEGMENT: {
            int seg = offset / 4;
            if (seg < 16) {
                g_state.segments[seg] = w1;
            }
            log_cmd(F3DDKR_G_MOVEWORD, "G_MOVEWORD(segment)", w0, w1);
            break;
        }
        case F3DDKR_MW_FOG:
            g_state.fog_multiplier = (int16_t)(w1 >> 16);
            g_state.fog_offset = (int16_t)(w1 & 0xFFFF);
            log_cmd(F3DDKR_G_MOVEWORD, "G_MOVEWORD(fog)", w0, w1);
            break;
        default:
            log_cmd(F3DDKR_G_MOVEWORD, "G_MOVEWORD(other)", w0, w1);
            break;
    }
}

// ============================================================
// Main DL parser loop
// ============================================================
static void process_dl_recursive(uint8_t* rdram, uint32_t dl_phys_addr, int max_commands);

static void process_dl_recursive(uint8_t* rdram, uint32_t dl_phys_addr, int max_commands) {
    int cmd_index = 0;

    while (max_commands == 0 || cmd_index < max_commands) {
        uint32_t cmd_addr = dl_phys_addr + cmd_index * 8;
        if (cmd_addr + 7 >= 0x800000) break;

        uint32_t w0 = rdram_read_u32(rdram, cmd_addr);
        uint32_t w1 = rdram_read_u32(rdram, cmd_addr + 4);
        uint8_t op = (w0 >> 24) & 0xFF;

        cmd_index++;

        switch (op) {
            // === Flow control ===
            case F3DDKR_G_ENDDL:
                log_cmd(op, "G_ENDDL", w0, w1);
                return;

            case F3DDKR_G_DL: {
                log_cmd(op, "G_DL", w0, w1);
                uint8_t push = (w0 >> 16) & 0xFF;
                uint32_t sub_addr = resolve_segment(w1);
                if (push == 0) {
                    // Push: recurse, then continue
                    if (g_state.dl_stack_depth < F3DDKRState::MAX_DL_STACK) {
                        g_state.dl_stack_depth++;
                        process_dl_recursive(rdram, sub_addr, 0);
                        g_state.dl_stack_depth--;
                    }
                } else {
                    // Branch (nopush): jump, don't return
                    process_dl_recursive(rdram, sub_addr, 0);
                    return;
                }
                break;
            }

            case F3DDKR_G_DMADL: {
                log_cmd(op, "G_DMADL", w0, w1);
                int num_cmds = (w0 >> 16) & 0xFF;
                uint32_t sub_addr = addr_to_phys(w1);
                if (g_state.dl_stack_depth < F3DDKRState::MAX_DL_STACK) {
                    g_state.dl_stack_depth++;
                    process_dl_recursive(rdram, sub_addr, num_cmds);
                    g_state.dl_stack_depth--;
                }
                break;
            }

            // === DKR-specific ===
            case F3DDKR_G_DMA_OFFSETS:
                g_state.vertex_dma_offset = w1 & 0x00FFFFFF;
                g_state.matrix_dma_offset = w0 & 0x00FFFFFF;
                log_cmd(F3DDKR_G_DMA_OFFSETS, "G_DMA_OFFSETS", w0, w1);
                break;

            // === Vertex / Matrix / Triangle ===
            case F3DDKR_G_MTX:
                cmd_mtx(w0, w1);
                break;

            case F3DDKR_G_VTX:
                cmd_vtx(w0, w1);
                break;

            case F3DDKR_G_TRIN:
                cmd_trin(w0, w1);
                break;

            // === G_MOVEWORD ===
            case F3DDKR_G_MOVEWORD:
                cmd_moveword(w0, w1);
                break;

            // === Color image / Z image / Tex image ===
            case F3DDKR_G_SETCIMG:
                cmd_setcimg(w0, w1);
                break;

            case F3DDKR_G_SETZIMG:
                cmd_setzimg(w0, w1);
                break;

            case F3DDKR_G_SETTIMG:
                cmd_settimg(w0, w1);
                break;

            // === Colors ===
            case F3DDKR_G_SETFILLCOLOR:
                g_state.fill_color = w1;
                log_cmd(op, "G_SETFILLCOLOR", w0, w1);
                break;

            case F3DDKR_G_SETENVCOLOR:
                g_state.env_color = w1;
                log_cmd(op, "G_SETENVCOLOR", w0, w1);
                break;

            case F3DDKR_G_SETPRIMCOLOR:
                g_state.prim_color = w1;
                log_cmd(op, "G_SETPRIMCOLOR", w0, w1);
                break;

            case F3DDKR_G_SETBLENDCOLOR:
                g_state.blend_color = w1;
                log_cmd(op, "G_SETBLENDCOLOR", w0, w1);
                break;

            case F3DDKR_G_SETFOGCOLOR:
                g_state.fog_color = w1;
                log_cmd(op, "G_SETFOGCOLOR", w0, w1);
                break;

            // === Modes ===
            case F3DDKR_G_RDPSETOTHERMODE:
                g_state.other_mode_h = w0 & 0x00FFFFFF;
                g_state.other_mode_l = w1;
                log_cmd(op, "G_RDPSETOTHERMODE", w0, w1);
                break;

            case F3DDKR_G_SETCOMBINE:
                g_state.combine_mode = ((uint64_t)w0 << 32) | w1;
                log_cmd(op, "G_SETCOMBINE", w0, w1);
                break;

            // === Fill rect ===
            case F3DDKR_G_FILLRECT:
                log_cmd(op, "G_FILLRECT", w0, w1);
                cmd_fill_rect(w0, w1);
                break;

            // === Texture commands ===
            case F3DDKR_G_SETTILE:
                cmd_settile(w0, w1);
                break;

            case F3DDKR_G_LOADTILE:
                cmd_loadtile(w0, w1);
                break;

            case F3DDKR_G_LOADBLOCK:
                cmd_loadblock(w0, w1);
                break;

            case F3DDKR_G_SETTILESIZE:
                cmd_settilesize(w0, w1);
                break;

            case F3DDKR_G_LOADTLUT:
                cmd_loadtlut(w0, w1);
                break;

            // === Tex rect (3-command sequence: TEXRECT + RDPHALF_1 + RDPHALF_2) ===
            case F3DDKR_G_TEXRECT: {
                // RDPHALF_1 (0xB3): w1 = (S << 16) | T
                uint32_t addr1 = dl_phys_addr + cmd_index * 8;
                if (addr1 + 7 >= 0x800000) break;
                uint32_t rh1_w1 = rdram_read_u32(rdram, addr1 + 4);
                cmd_index++;

                // RDPHALF_2 (0xB2): w1 = (dSdX << 16) | dTdY
                uint32_t addr2 = dl_phys_addr + cmd_index * 8;
                if (addr2 + 7 >= 0x800000) break;
                uint32_t rh2_w1 = rdram_read_u32(rdram, addr2 + 4);
                cmd_index++;

                cmd_texrect(w0, w1, rh1_w1, rh2_w1);
                break;
            }

            // === Scissor ===
            case F3DDKR_G_SETSCISSOR: {
                g_state.sc_xl = (w0 >> 12) & 0xFFF;
                g_state.sc_yl = w0 & 0xFFF;
                g_state.sc_xh = (w1 >> 12) & 0xFFF;
                g_state.sc_yh = w1 & 0xFFF;
                // Convert from 10.2 fixed-point
                g_state.sc_xl >>= 2;
                g_state.sc_yl >>= 2;
                g_state.sc_xh >>= 2;
                g_state.sc_yh >>= 2;
                log_cmd(op, "G_SETSCISSOR", w0, w1);
                break;
            }

            // === Sync / Noop (ignore) ===
            case F3DDKR_G_RDPFULLSYNC:
            case F3DDKR_G_RDPTILESYNC:
            case F3DDKR_G_RDPPIPESYNC:
            case F3DDKR_G_RDPLOADSYNC:
            case F3DDKR_G_NOOP:
            case F3DDKR_G_SPNOOP:
                break;

            case F3DDKR_G_SETPRIMDEPTH:
                log_cmd(op, "G_SETPRIMDEPTH", w0, w1);
                break;

            // === G_MOVEMEM (0x03) — viewport, lights ===
            case 0x03: {
                uint8_t param = (w0 >> 16) & 0xFF;
                if (param == 0x80) {
                    // G_MV_VIEWPORT: load 16 bytes of viewport data
                    uint32_t vp_addr = addr_to_phys(w1);
                    // Vp_t: s16 vscale[4], s16 vtrans[4]
                    int16_t vscale_x = rdram_read_s16(g_state.rdram, vp_addr + 0);
                    int16_t vscale_y = rdram_read_s16(g_state.rdram, vp_addr + 2);
                    int16_t vtrans_x = rdram_read_s16(g_state.rdram, vp_addr + 8);
                    int16_t vtrans_y = rdram_read_s16(g_state.rdram, vp_addr + 10);
                    // Store raw viewport values (divided by 4 to get screen units)
                    // PRESERVES SIGN — negative scale flips axes and winding order
                    g_state.vp_scale_x = (float)vscale_x / 4.0f;
                    g_state.vp_scale_y = (float)vscale_y / 4.0f;
                    g_state.vp_trans_x = (float)vtrans_x / 4.0f;
                    g_state.vp_trans_y = (float)vtrans_y / 4.0f;
                    // Derived positive dimensions for scissor/clipping
                    g_state.vp_w = fabsf(g_state.vp_scale_x) * 2.0f;
                    g_state.vp_h = fabsf(g_state.vp_scale_y) * 2.0f;
                    g_state.vp_x = g_state.vp_trans_x - g_state.vp_w / 2.0f;
                    g_state.vp_y = g_state.vp_trans_y - g_state.vp_h / 2.0f;
                    if (g_state.cmd_counts[0x03] < LOG_FIRST_N) {
                        fprintf(stderr, "[F3DDKR] G_MOVEMEM(viewport): vp=(%g,%g %gx%g) scale=(%g,%g) trans=(%g,%g)\n",
                                g_state.vp_x, g_state.vp_y, g_state.vp_w, g_state.vp_h,
                                g_state.vp_scale_x, g_state.vp_scale_y,
                                g_state.vp_trans_x, g_state.vp_trans_y);
                        fflush(stderr);
                    }
                }
                g_state.cmd_counts[0x03]++;
                break;
            }

            // === Geometry mode ===
            case 0xB7: // G_SETGEOMETRYMODE
                g_state.geometry_mode |= w1;
                g_state.cmd_counts[op]++;
                break;
            case 0xB6: // G_CLEARGEOMETRYMODE
                g_state.geometry_mode &= ~w1;
                g_state.cmd_counts[op]++;
                break;

            // === G_TEXTURE (0xBB) — texture enable/scale, no-op ===
            case 0xBB:
                g_state.cmd_counts[op]++;
                break;

            // === G_SETOTHERMODE_H (0xBA) ===
            case 0xBA: {
                // Modifies individual bits in other_mode_h
                uint8_t shift = (w0 >> 8) & 0xFF;
                uint8_t length = w0 & 0xFF;
                uint32_t mask = ((1u << length) - 1) << shift;
                g_state.other_mode_h = (g_state.other_mode_h & ~mask) | (w1 & mask);
                g_state.cmd_counts[op]++;
                break;
            }

            // === G_SETOTHERMODE_L (0xB9) ===
            case 0xB9: {
                uint8_t shift = (w0 >> 8) & 0xFF;
                uint8_t length = w0 & 0xFF;
                uint32_t mask = ((1u << length) - 1) << shift;
                g_state.other_mode_l = (g_state.other_mode_l & ~mask) | (w1 & mask);
                g_state.cmd_counts[op]++;
                break;
            }

            // === G_PERSPNORMALIZE (0xB4) — no-op ===
            case 0xB4:
                g_state.cmd_counts[op]++;
                break;

            // === G_RDPHALF_1 (0xB3) / G_RDPHALF_2 (0xB2) — consumed by TEXRECT, stray ones are no-ops ===
            case 0xB3:
            case 0xB2:
                g_state.cmd_counts[op]++;
                break;

            // === G_RESERVED0 (0x02) — viewport for DKR? No-op for now ===
            case 0x02:
                g_state.cmd_counts[op]++;
                break;

            default:
                if (g_state.cmd_counts[op] < 1) {
                    fprintf(stderr, "[F3DDKR] Unknown opcode 0x%02X: w0=0x%08X w1=0x%08X\n", op, w0, w1);
                    fflush(stderr);
                }
                g_state.cmd_counts[op]++;
                break;
        }

        // Safety: limit total commands per DL to prevent infinite loops
        if (cmd_index > 10000) {
            fprintf(stderr, "[F3DDKR] Warning: exceeded 10000 commands, aborting DL\n");
            fflush(stderr);
            break;
        }
    }
}

// ============================================================
// Public API
// ============================================================
void f3ddkr_process_dl(uint8_t* rdram, uint32_t dl_addr, uint32_t dl_size) {
    if (!g_initialized) {
        f3ddkr_init(rdram);
    }
    g_state.rdram = rdram;
    g_state.dl_stack_depth = 0;
    g_state.dl_total_count++;

    uint32_t phys = addr_to_phys(dl_addr);

    if (g_state.dl_total_count <= 3) {
        fprintf(stderr, "[F3DDKR] Processing DL #%d: addr=0x%08X (phys=0x%06X) size=0x%X\n",
                g_state.dl_total_count, dl_addr, phys, dl_size);
        fflush(stderr);
    }

    process_dl_recursive(rdram, phys, 0);
}

uint32_t f3ddkr_get_last_ci_addr() {
    return g_state.ci_addr;
}

uint16_t f3ddkr_get_last_ci_width() {
    return g_state.ci_width;
}
