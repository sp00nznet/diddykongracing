#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void coss_s16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070A6C: addiu       $a0, $a0, 0x4000
    ctx->r4 = ADD32(ctx->r4, 0X4000);
;}
RECOMP_FUNC void sins_s16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070A70: sll         $v0, $a0, 17
    ctx->r2 = S32(ctx->r4 << 17);
    // 0x80070A74: bgezl       $v0, L_80070A84
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80070A78: srl         $t2, $a0, 3
        ctx->r10 = S32(U32(ctx->r4) >> 3);
            goto L_80070A84;
    }
    goto skip_0;
    // 0x80070A78: srl         $t2, $a0, 3
    ctx->r10 = S32(U32(ctx->r4) >> 3);
    skip_0:
    // 0x80070A7C: xori        $a0, $a0, 0x7FFF
    ctx->r4 = ctx->r4 ^ 0X7FFF;
    // 0x80070A80: srl         $t2, $a0, 3
    ctx->r10 = S32(U32(ctx->r4) >> 3);
L_80070A84:
    // 0x80070A84: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80070A88: andi        $t2, $t2, 0x7FE
    ctx->r10 = ctx->r10 & 0X7FE;
    // 0x80070A8C: addiu       $v0, $v0, -0x2654
    ctx->r2 = ADD32(ctx->r2, -0X2654);
    // 0x80070A90: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x80070A94: lhu         $t2, 0x2($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X2);
    // 0x80070A98: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80070A9C: andi        $t1, $a0, 0xF
    ctx->r9 = ctx->r4 & 0XF;
    // 0x80070AA0: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80070AA4: subu        $t2, $t2, $v0
    ctx->r10 = SUB32(ctx->r10, ctx->r2);
    // 0x80070AA8: multu       $t2, $t1
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80070AAC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80070AB0: mflo        $t2
    ctx->r10 = lo;
    // 0x80070AB4: srl         $t2, $t2, 3
    ctx->r10 = S32(U32(ctx->r10) >> 3);
    // 0x80070AB8: bgez        $a0, L_80070AC4
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80070ABC: addu        $v0, $v0, $t2
        ctx->r2 = ADD32(ctx->r2, ctx->r10);
            goto L_80070AC4;
    }
    // 0x80070ABC: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x80070AC0: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_80070AC4:
    // 0x80070AC4: jr          $ra
    // 0x80070AC8: nop

    return;
    // 0x80070AC8: nop

;}
RECOMP_FUNC void coss_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070ACC: addiu       $a0, $a0, 0x4000
    ctx->r4 = ADD32(ctx->r4, 0X4000);
;}
RECOMP_FUNC void sins_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070AD0: sll         $v0, $a0, 17
    ctx->r2 = S32(ctx->r4 << 17);
    // 0x80070AD4: bgezl       $v0, L_80070AE4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80070AD8: srl         $t2, $a0, 3
        ctx->r10 = S32(U32(ctx->r4) >> 3);
            goto L_80070AE4;
    }
    goto skip_0;
    // 0x80070AD8: srl         $t2, $a0, 3
    ctx->r10 = S32(U32(ctx->r4) >> 3);
    skip_0:
    // 0x80070ADC: xori        $a0, $a0, 0x7FFF
    ctx->r4 = ctx->r4 ^ 0X7FFF;
    // 0x80070AE0: srl         $t2, $a0, 3
    ctx->r10 = S32(U32(ctx->r4) >> 3);
L_80070AE4:
    // 0x80070AE4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80070AE8: andi        $t2, $t2, 0x7FE
    ctx->r10 = ctx->r10 & 0X7FE;
    // 0x80070AEC: addiu       $v0, $v0, -0x2654
    ctx->r2 = ADD32(ctx->r2, -0X2654);
    // 0x80070AF0: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x80070AF4: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80070AF8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80070AFC: bgez        $a0, L_80070B08
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80070B00: sll         $v0, $v0, 1
        ctx->r2 = S32(ctx->r2 << 1);
            goto L_80070B08;
    }
    // 0x80070B00: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80070B04: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_80070B08:
    // 0x80070B08: jr          $ra
    // 0x80070B0C: nop

    return;
    // 0x80070B0C: nop

;}
RECOMP_FUNC void calc_dyn_lighting_for_level_segment(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070B10: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x80070B14: lw          $t2, 0x4($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X4);
    // 0x80070B18: lw          $t3, 0x8($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X8);
    // 0x80070B1C: lhu         $t0, 0x20($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X20);
    // 0x80070B20: lw          $a2, 0xC($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XC);
    // 0x80070B24: lw          $a1, 0x2C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X2C);
    // 0x80070B28: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80070B2C: xor         $v0, $v0, $v0
    ctx->r2 = ctx->r2 ^ ctx->r2;
L_80070B30:
    // 0x80070B30: lbu         $t4, 0x6($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X6);
    // 0x80070B34: addiu       $t4, $t4, -0xFF
    ctx->r12 = ADD32(ctx->r12, -0XFF);
    // 0x80070B38: beql        $t4, $zero, L_80070C48
    if (ctx->r12 == 0) {
        // 0x80070B3C: lhu         $t4, 0x2($a2)
        ctx->r12 = MEM_HU(ctx->r6, 0X2);
            goto L_80070C48;
    }
    goto skip_0;
    // 0x80070B3C: lhu         $t4, 0x2($a2)
    ctx->r12 = MEM_HU(ctx->r6, 0X2);
    skip_0:
    // 0x80070B40: beql        $v0, $zero, L_80070B74
    if (ctx->r2 == 0) {
        // 0x80070B44: nop
    
            goto L_80070B74;
    }
    goto skip_1;
    // 0x80070B44: nop

    skip_1:
    // 0x80070B48: ori         $t4, $zero, 0xA
    ctx->r12 = 0 | 0XA;
    // 0x80070B4C: multu       $v0, $t4
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80070B50: ori         $t5, $zero, 0xA
    ctx->r13 = 0 | 0XA;
    // 0x80070B54: mflo        $t4
    ctx->r12 = lo;
    // 0x80070B58: addu        $a0, $a0, $t4
    ctx->r4 = ADD32(ctx->r4, ctx->r12);
    // 0x80070B5C: nop

    // 0x80070B60: multu       $v0, $t5
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80070B64: xor         $v0, $v0, $v0
    ctx->r2 = ctx->r2 ^ ctx->r2;
    // 0x80070B68: mflo        $t5
    ctx->r13 = lo;
    // 0x80070B6C: addu        $a1, $a1, $t5
    ctx->r5 = ADD32(ctx->r5, ctx->r13);
    // 0x80070B70: nop

L_80070B74:
    // 0x80070B74: lhu         $t5, 0x2($a2)
    ctx->r13 = MEM_HU(ctx->r6, 0X2);
    // 0x80070B78: lhu         $t4, 0xE($a2)
    ctx->r12 = MEM_HU(ctx->r6, 0XE);
    // 0x80070B7C: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    // 0x80070B80: subu        $t4, $t4, $t5
    ctx->r12 = SUB32(ctx->r12, ctx->r13);
L_80070B84:
    // 0x80070B84: lh          $t5, 0x0($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X0);
    // 0x80070B88: lh          $t6, 0x2($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X2);
    // 0x80070B8C: lh          $t7, 0x4($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X4);
    // 0x80070B90: mult        $t5, $t1
    result = S64(S32(ctx->r13)) * S64(S32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80070B94: lbu         $t8, 0x7($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X7);
    // 0x80070B98: lbu         $a3, 0x6($a1)
    ctx->r7 = MEM_BU(ctx->r5, 0X6);
    // 0x80070B9C: lbu         $t9, 0x8($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X8);
    // 0x80070BA0: sll         $t8, $t8, 16
    ctx->r24 = S32(ctx->r24 << 16);
    // 0x80070BA4: lbu         $v1, 0x9($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X9);
    // 0x80070BA8: or          $t8, $a3, $t8
    ctx->r24 = ctx->r7 | ctx->r24;
    // 0x80070BAC: mflo        $t5
    ctx->r13 = lo;
    // 0x80070BB0: nop

    // 0x80070BB4: nop

    // 0x80070BB8: mult        $t6, $t2
    result = S64(S32(ctx->r14)) * S64(S32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80070BBC: mflo        $t6
    ctx->r14 = lo;
    // 0x80070BC0: add         $t5, $t5, $t6
    ctx->r13 = ADD32(ctx->r13, ctx->r14);
    // 0x80070BC4: nop

    // 0x80070BC8: mult        $t7, $t3
    result = S64(S32(ctx->r15)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80070BCC: mflo        $t7
    ctx->r15 = lo;
    // 0x80070BD0: add         $t5, $t5, $t7
    ctx->r13 = ADD32(ctx->r13, ctx->r15);
    // 0x80070BD4: blez        $t5, L_80070BF4
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80070BD8: nop
    
            goto L_80070BF4;
    }
    // 0x80070BD8: nop

    // 0x80070BDC: srl         $t5, $t5, 22
    ctx->r13 = S32(U32(ctx->r13) >> 22);
    // 0x80070BE0: addu        $v1, $v1, $t5
    ctx->r3 = ADD32(ctx->r3, ctx->r13);
    // 0x80070BE4: sltiu       $t5, $v1, 0x81
    ctx->r13 = ctx->r3 < 0X81 ? 1 : 0;
    // 0x80070BE8: bne         $t5, $zero, L_80070BF4
    if (ctx->r13 != 0) {
        // 0x80070BEC: nop
    
            goto L_80070BF4;
    }
    // 0x80070BEC: nop

    // 0x80070BF0: ori         $v1, $zero, 0x80
    ctx->r3 = 0 | 0X80;
L_80070BF4:
    // 0x80070BF4: multu       $v1, $t8
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80070BF8: addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
    // 0x80070BFC: addiu       $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
    // 0x80070C00: addiu       $a0, $a0, 0xA
    ctx->r4 = ADD32(ctx->r4, 0XA);
    // 0x80070C04: mflo        $t8
    ctx->r24 = lo;
    // 0x80070C08: srl         $t8, $t8, 7
    ctx->r24 = S32(U32(ctx->r24) >> 7);
    // 0x80070C0C: sb          $t8, -0x4($a0)
    MEM_B(-0X4, ctx->r4) = ctx->r24;
    // 0x80070C10: multu       $v1, $t9
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80070C14: srl         $t8, $t8, 16
    ctx->r24 = S32(U32(ctx->r24) >> 16);
    // 0x80070C18: sb          $t8, -0x3($a0)
    MEM_B(-0X3, ctx->r4) = ctx->r24;
    // 0x80070C1C: mflo        $t9
    ctx->r25 = lo;
    // 0x80070C20: srl         $t9, $t9, 7
    ctx->r25 = S32(U32(ctx->r25) >> 7);
    // 0x80070C24: sb          $t9, -0x2($a0)
    MEM_B(-0X2, ctx->r4) = ctx->r25;
    // 0x80070C28: bnel        $t4, $zero, L_80070B84
    if (ctx->r12 != 0) {
        // 0x80070C2C: nop
    
            goto L_80070B84;
    }
    goto skip_2;
    // 0x80070C2C: nop

    skip_2:
    // 0x80070C30: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x80070C34: bnel        $t0, $zero, L_80070B30
    if (ctx->r8 != 0) {
        // 0x80070C38: nop
    
            goto L_80070B30;
    }
    goto skip_3;
    // 0x80070C38: nop

    skip_3:
    // 0x80070C3C: jr          $ra
    // 0x80070C40: nop

    return;
    // 0x80070C40: nop

;}
RECOMP_FUNC void func_80070A04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
L_80070B30:
    // 0x80070C44: lhu         $t4, 0x2($a2)
    ctx->r12 = MEM_HU(ctx->r6, 0X2);
    // 0x80070C48: lhu         $t5, 0xE($a2)
    ctx->r13 = MEM_HU(ctx->r6, 0XE);
    // 0x80070C4C: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    // 0x80070C50: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x80070C54: subu        $t4, $t5, $t4
    ctx->r12 = SUB32(ctx->r13, ctx->r12);
    // 0x80070C58: addu        $v0, $v0, $t4
    ctx->r2 = ADD32(ctx->r2, ctx->r12);
    // 0x80070C5C: bnel        $t0, $zero, L_80070B30
    if (ctx->r8 != 0) {
        // 0x80070C60: nop
    
            goto L_80070B30;
    }
    goto skip_0;
    // 0x80070C60: nop

    skip_0:
    // 0x80070C64: jr          $ra
    // 0x80070C68: nop

    return;
    // 0x80070C68: nop

;}
RECOMP_FUNC void area_triangle_2d(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070C6C: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x80070C70: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x80070C74: mtc1        $a3, $f6
    ctx->f6.u32l = ctx->r7;
    // 0x80070C78: sub.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80070C7C: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    // 0x80070C80: lwc1        $f8, 0x10($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X10);
    // 0x80070C84: sub.s       $f14, $f6, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x80070C88: mul.s       $f12, $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80070C8C: lwc1        $f10, 0x14($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80070C90: sub.s       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80070C94: mul.s       $f14, $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80070C98: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80070C9C: sub.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80070CA0: mul.s       $f16, $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80070CA4: sub.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80070CA8: mul.s       $f18, $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x80070CAC: sub.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x80070CB0: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80070CB4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80070CB8: add.s       $f12, $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x80070CBC: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80070CC0: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80070CC4: sqrt.s      $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = sqrtf(ctx->f12.fl);
    // 0x80070CC8: sqrt.s      $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = sqrtf(ctx->f16.fl);
    // 0x80070CCC: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80070CD0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80070CD4: add.s       $f18, $f12, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f12.fl + ctx->f16.fl;
    // 0x80070CD8: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x80070CDC: add.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x80070CE0: mul.s       $f18, $f10, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80070CE4: sub.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f12.fl;
    // 0x80070CE8: sub.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x80070CEC: mul.s       $f0, $f4, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80070CF0: sub.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80070CF4: mul.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80070CF8: nop

    // 0x80070CFC: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80070D00: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80070D04: bc1fl       L_80070D10
    if (!c1cs) {
        // 0x80070D08: nop
    
            goto L_80070D10;
    }
    goto skip_0;
    // 0x80070D08: nop

    skip_0:
    // 0x80070D0C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80070D10:
    // 0x80070D10: jr          $ra
    // 0x80070D14: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    return;
    // 0x80070D14: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
;}
RECOMP_FUNC void set_breakpoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void dmacopy_doubleword(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
L_80070D44:
    // 0x80070D44: ld          $t0, 0x0($a0)
    ctx->r8 = LD(ctx->r4, 0X0);
    // 0x80070D48: ld          $t1, 0x8($a0)
    ctx->r9 = LD(ctx->r4, 0X8);
    // 0x80070D4C: addi        $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x80070D50: addi        $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80070D54: sd          $t0, -0x10($a1)
    SD(ctx->r8, -0X10, ctx->r5);
    // 0x80070D58: bne         $a1, $a2, L_80070D44
    if (ctx->r5 != ctx->r6) {
        // 0x80070D5C: sd          $t1, -0x8($a1)
        SD(ctx->r9, -0X8, ctx->r5);
            goto L_80070D44;
    }
    // 0x80070D5C: sd          $t1, -0x8($a1)
    SD(ctx->r9, -0X8, ctx->r5);
    // 0x80070D60: jr          $ra
    // 0x80070D64: nop

    return;
    // 0x80070D64: nop

    // 0x80070D68: nop

    // 0x80070D6C: nop

;}
RECOMP_FUNC void mempool_init_main(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070D70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070D74: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80070D78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070D7C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80070D80: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80070D84: addiu       $a0, $a0, -0x2650
    ctx->r4 = ADD32(ctx->r4, -0X2650);
    // 0x80070D88: lui         $t7, 0x8040
    ctx->r15 = S32(0X8040 << 16);
    // 0x80070D8C: sw          $t6, 0x3B40($at)
    MEM_W(0X3B40, ctx->r1) = ctx->r14;
    // 0x80070D90: subu        $a1, $t7, $a0
    ctx->r5 = SUB32(ctx->r15, ctx->r4);
    // 0x80070D94: jal         0x80070E24
    // 0x80070D98: addiu       $a2, $zero, 0x640
    ctx->r6 = ADD32(0, 0X640);
    mempool_init(rdram, ctx);
        goto after_0;
    // 0x80070D98: addiu       $a2, $zero, 0x640
    ctx->r6 = ADD32(0, 0X640);
    after_0:
    // 0x80070D9C: jal         0x800712F0
    // 0x80070DA0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    mempool_free_timer(rdram, ctx);
        goto after_1;
    // 0x80070DA0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x80070DA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070DA8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80070DAC: sw          $zero, 0x4348($at)
    MEM_W(0X4348, ctx->r1) = 0;
    // 0x80070DB0: jr          $ra
    // 0x80070DB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80070DB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void mempool_new_sub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070DB8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80070DBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070DC0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80070DC4: jal         0x8006F750
    // 0x80070DC8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    interrupts_disable(rdram, ctx);
        goto after_0;
    // 0x80070DC8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_0:
    // 0x80070DCC: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80070DD0: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80070DD4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80070DD8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80070DDC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80070DE0: addu        $a3, $t6, $t8
    ctx->r7 = ADD32(ctx->r14, ctx->r24);
    // 0x80070DE4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80070DE8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80070DEC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80070DF0: jal         0x80070EDC
    // 0x80070DF4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x80070DF4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_1:
    // 0x80070DF8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80070DFC: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80070E00: jal         0x80070E24
    // 0x80070E04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mempool_init(rdram, ctx);
        goto after_2;
    // 0x80070E04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80070E08: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80070E0C: jal         0x8006F77C
    // 0x80070E10: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    interrupts_enable(rdram, ctx);
        goto after_3;
    // 0x80070E10: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_3:
    // 0x80070E14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070E18: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80070E1C: jr          $ra
    // 0x80070E20: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80070E20: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void mempool_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070E24: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80070E28: addiu       $t1, $t1, 0x3B40
    ctx->r9 = ADD32(ctx->r9, 0X3B40);
    // 0x80070E2C: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x80070E30: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80070E34: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80070E38: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80070E3C: addiu       $t9, $t9, 0x3B00
    ctx->r25 = ADD32(ctx->r25, 0X3B00);
    // 0x80070E40: addu        $a3, $t8, $t9
    ctx->r7 = ADD32(ctx->r24, ctx->r25);
    // 0x80070E44: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x80070E48: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
    // 0x80070E4C: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x80070E50: sw          $a0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r4;
    // 0x80070E54: sw          $a1, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r5;
    // 0x80070E58: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x80070E5C: blez        $a2, L_80070E7C
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80070E60: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80070E7C;
    }
    // 0x80070E60: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80070E64:
    // 0x80070E64: sh          $v1, 0xE($t0)
    MEM_H(0XE, ctx->r8) = ctx->r3;
    // 0x80070E68: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x80070E6C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80070E70: slt         $at, $v1, $t2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80070E74: bne         $at, $zero, L_80070E64
    if (ctx->r1 != 0) {
        // 0x80070E78: addiu       $t0, $t0, 0x14
        ctx->r8 = ADD32(ctx->r8, 0X14);
            goto L_80070E64;
    }
    // 0x80070E78: addiu       $t0, $t0, 0x14
    ctx->r8 = ADD32(ctx->r8, 0X14);
L_80070E7C:
    // 0x80070E7C: sll         $v1, $a2, 2
    ctx->r3 = S32(ctx->r6 << 2);
    // 0x80070E80: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x80070E84: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80070E88: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x80070E8C: lw          $t0, 0x8($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X8);
    // 0x80070E90: andi        $t3, $a0, 0xF
    ctx->r11 = ctx->r4 & 0XF;
    // 0x80070E94: beq         $t3, $zero, L_80070EB0
    if (ctx->r11 == 0) {
        // 0x80070E98: subu        $t6, $a1, $v1
        ctx->r14 = SUB32(ctx->r5, ctx->r3);
            goto L_80070EB0;
    }
    // 0x80070E98: subu        $t6, $a1, $v1
    ctx->r14 = SUB32(ctx->r5, ctx->r3);
    // 0x80070E9C: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80070EA0: and         $t4, $a0, $at
    ctx->r12 = ctx->r4 & ctx->r1;
    // 0x80070EA4: addiu       $t5, $t4, 0x10
    ctx->r13 = ADD32(ctx->r12, 0X10);
    // 0x80070EA8: b           L_80070EB4
    // 0x80070EAC: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
        goto L_80070EB4;
    // 0x80070EAC: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
L_80070EB0:
    // 0x80070EB0: sw          $a0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r4;
L_80070EB4:
    // 0x80070EB4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80070EB8: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
    // 0x80070EBC: sh          $zero, 0x8($t0)
    MEM_H(0X8, ctx->r8) = 0;
    // 0x80070EC0: sh          $a0, 0xA($t0)
    MEM_H(0XA, ctx->r8) = ctx->r4;
    // 0x80070EC4: sh          $a0, 0xC($t0)
    MEM_H(0XC, ctx->r8) = ctx->r4;
    // 0x80070EC8: lw          $t7, 0x4($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X4);
    // 0x80070ECC: lw          $v0, 0x8($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X8);
    // 0x80070ED0: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80070ED4: jr          $ra
    // 0x80070ED8: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
    return;
    // 0x80070ED8: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
;}
RECOMP_FUNC void mempool_alloc_safe(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070EDC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80070EE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070EE4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80070EE8: bne         $a0, $zero, L_80070F0C
    if (ctx->r4 != 0) {
        // 0x80070EEC: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_80070F0C;
    }
    // 0x80070EEC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80070EF0: jal         0x800B8230
    // 0x80070EF4: nop

    stack_pointer(rdram, ctx);
        goto after_0;
    // 0x80070EF4: nop

    after_0:
    // 0x80070EF8: lw          $a0, 0x14($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X14);
    // 0x80070EFC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80070F00: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80070F04: jal         0x800B7980
    // 0x80070F08: nop

    dump_memory_to_cpak(rdram, ctx);
        goto after_1;
    // 0x80070F08: nop

    after_1:
L_80070F0C:
    // 0x80070F0C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80070F10: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80070F14: jal         0x80070F7C
    // 0x80070F18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mempool_slot_find(rdram, ctx);
        goto after_2;
    // 0x80070F18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x80070F1C: bne         $v0, $zero, L_80070F40
    if (ctx->r2 != 0) {
        // 0x80070F20: sw          $v0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r2;
            goto L_80070F40;
    }
    // 0x80070F20: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80070F24: jal         0x800B8230
    // 0x80070F28: nop

    stack_pointer(rdram, ctx);
        goto after_3;
    // 0x80070F28: nop

    after_3:
    // 0x80070F2C: lw          $a0, 0x14($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X14);
    // 0x80070F30: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80070F34: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80070F38: jal         0x800B7980
    // 0x80070F3C: nop

    dump_memory_to_cpak(rdram, ctx);
        goto after_4;
    // 0x80070F3C: nop

    after_4:
L_80070F40:
    // 0x80070F40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070F44: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80070F48: jr          $ra
    // 0x80070F4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80070F4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void mempool_alloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070F50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070F54: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80070F58: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80070F5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070F60: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80070F64: jal         0x80070F7C
    // 0x80070F68: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mempool_slot_find(rdram, ctx);
        goto after_0;
    // 0x80070F68: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80070F6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070F70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070F74: jr          $ra
    // 0x80070F78: nop

    return;
    // 0x80070F78: nop

;}
RECOMP_FUNC void mempool_slot_find(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070F7C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80070F80: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80070F84: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80070F88: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80070F8C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80070F90: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80070F94: jal         0x8006F750
    // 0x80070F98: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    interrupts_disable(rdram, ctx);
        goto after_0;
    // 0x80070F98: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_0:
    // 0x80070F9C: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80070FA0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80070FA4: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80070FA8: addiu       $t8, $t8, 0x3B00
    ctx->r24 = ADD32(ctx->r24, 0X3B00);
    // 0x80070FAC: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80070FB0: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80070FB4: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x80070FB8: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x80070FBC: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x80070FC0: bne         $t2, $t3, L_80070FDC
    if (ctx->r10 != ctx->r11) {
        // 0x80070FC4: andi        $t4, $s1, 0xF
        ctx->r12 = ctx->r17 & 0XF;
            goto L_80070FDC;
    }
    // 0x80070FC4: andi        $t4, $s1, 0xF
    ctx->r12 = ctx->r17 & 0XF;
    // 0x80070FC8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80070FCC: jal         0x8006F77C
    // 0x80070FD0: nop

    interrupts_enable(rdram, ctx);
        goto after_1;
    // 0x80070FD0: nop

    after_1:
    // 0x80070FD4: b           L_800710BC
    // 0x80070FD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800710BC;
    // 0x80070FD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80070FDC:
    // 0x80070FDC: beq         $t4, $zero, L_80070FF0
    if (ctx->r12 == 0) {
        // 0x80070FE0: addiu       $s0, $zero, -0x1
        ctx->r16 = ADD32(0, -0X1);
            goto L_80070FF0;
    }
    // 0x80070FE0: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x80070FE4: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80070FE8: and         $t5, $s1, $at
    ctx->r13 = ctx->r17 & ctx->r1;
    // 0x80070FEC: addiu       $s1, $t5, 0x10
    ctx->r17 = ADD32(ctx->r13, 0X10);
L_80070FF0:
    // 0x80070FF0: lui         $a2, 0x7FFF
    ctx->r6 = S32(0X7FFF << 16);
    // 0x80070FF4: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x80070FF8: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x80070FFC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80071000: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x80071004: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_80071008:
    // 0x80071008: multu       $a0, $t0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007100C: mflo        $t6
    ctx->r14 = lo;
    // 0x80071010: addu        $v0, $t6, $t1
    ctx->r2 = ADD32(ctx->r14, ctx->r9);
    // 0x80071014: lh          $t7, 0x8($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X8);
    // 0x80071018: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8007101C: bne         $t7, $zero, L_80071048
    if (ctx->r15 != 0) {
        // 0x80071020: nop
    
            goto L_80071048;
    }
    // 0x80071020: nop

    // 0x80071024: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x80071028: nop

    // 0x8007102C: slt         $at, $v1, $s1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80071030: bne         $at, $zero, L_80071048
    if (ctx->r1 != 0) {
        // 0x80071034: slt         $at, $v1, $a2
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_80071048;
    }
    // 0x80071034: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80071038: beq         $at, $zero, L_80071048
    if (ctx->r1 == 0) {
        // 0x8007103C: nop
    
            goto L_80071048;
    }
    // 0x8007103C: nop

    // 0x80071040: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x80071044: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
L_80071048:
    // 0x80071048: lh          $a0, 0xC($a1)
    ctx->r4 = MEM_H(ctx->r5, 0XC);
    // 0x8007104C: nop

    // 0x80071050: bne         $a0, $a3, L_80071008
    if (ctx->r4 != ctx->r7) {
        // 0x80071054: nop
    
            goto L_80071008;
    }
    // 0x80071054: nop

    // 0x80071058: beq         $s0, $a3, L_800710AC
    if (ctx->r16 == ctx->r7) {
        // 0x8007105C: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_800710AC;
    }
    // 0x8007105C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80071060: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80071064: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80071068: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8007106C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80071070: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80071074: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x80071078: jal         0x800719CC
    // 0x8007107C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    mempool_slot_assign(rdram, ctx);
        goto after_2;
    // 0x8007107C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_2:
    // 0x80071080: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80071084: jal         0x8006F77C
    // 0x80071088: nop

    interrupts_enable(rdram, ctx);
        goto after_3;
    // 0x80071088: nop

    after_3:
    // 0x8007108C: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x80071090: multu       $s0, $t0
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80071094: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80071098: mflo        $t9
    ctx->r25 = lo;
    // 0x8007109C: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x800710A0: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x800710A4: b           L_800710C0
    // 0x800710A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800710C0;
    // 0x800710A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800710AC:
    // 0x800710AC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800710B0: jal         0x8006F77C
    // 0x800710B4: nop

    interrupts_enable(rdram, ctx);
        goto after_4;
    // 0x800710B4: nop

    after_4:
    // 0x800710B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800710BC:
    // 0x800710BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800710C0:
    // 0x800710C0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800710C4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800710C8: jr          $ra
    // 0x800710CC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800710CC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void mempool_alloc_pool(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800710D0: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800710D4: lw          $a3, 0x3B40($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X3B40);
    // 0x800710D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800710DC: beq         $a3, $zero, L_80071124
    if (ctx->r7 == 0) {
        // 0x800710E0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80071124;
    }
    // 0x800710E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800710E4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800710E8: addiu       $t7, $t7, 0x3B00
    ctx->r15 = ADD32(ctx->r15, 0X3B00);
    // 0x800710EC: sll         $t6, $a3, 4
    ctx->r14 = S32(ctx->r7 << 4);
    // 0x800710F0: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
L_800710F4:
    // 0x800710F4: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x800710F8: nop

    // 0x800710FC: bne         $a0, $t8, L_80071118
    if (ctx->r4 != ctx->r24) {
        // 0x80071100: nop
    
            goto L_80071118;
    }
    // 0x80071100: nop

    // 0x80071104: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80071108: jal         0x80070F7C
    // 0x8007110C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    mempool_slot_find(rdram, ctx);
        goto after_0;
    // 0x8007110C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80071110: b           L_8007112C
    // 0x80071114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8007112C;
    // 0x80071114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80071118:
    // 0x80071118: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x8007111C: bne         $a3, $zero, L_800710F4
    if (ctx->r7 != 0) {
        // 0x80071120: addiu       $v0, $v0, -0x10
        ctx->r2 = ADD32(ctx->r2, -0X10);
            goto L_800710F4;
    }
    // 0x80071120: addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
L_80071124:
    // 0x80071124: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80071128: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8007112C:
    // 0x8007112C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071130: jr          $ra
    // 0x80071134: nop

    return;
    // 0x80071134: nop

;}
RECOMP_FUNC void mempool_alloc_fixed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071138: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8007113C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80071140: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80071144: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80071148: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8007114C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80071150: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80071154: jal         0x8006F750
    // 0x80071158: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    interrupts_disable(rdram, ctx);
        goto after_0;
    // 0x80071158: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    after_0:
    // 0x8007115C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80071160: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80071164: addiu       $v0, $v0, 0x3B00
    ctx->r2 = ADD32(ctx->r2, 0X3B00);
    // 0x80071168: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x8007116C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80071170: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80071174: bne         $t7, $t8, L_80071190
    if (ctx->r15 != ctx->r24) {
        // 0x80071178: andi        $t9, $s2, 0xF
        ctx->r25 = ctx->r18 & 0XF;
            goto L_80071190;
    }
    // 0x80071178: andi        $t9, $s2, 0xF
    ctx->r25 = ctx->r18 & 0XF;
    // 0x8007117C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80071180: jal         0x8006F77C
    // 0x80071184: nop

    interrupts_enable(rdram, ctx);
        goto after_1;
    // 0x80071184: nop

    after_1:
    // 0x80071188: b           L_800712D8
    // 0x8007118C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800712D8;
    // 0x8007118C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80071190:
    // 0x80071190: beq         $t9, $zero, L_800711A4
    if (ctx->r25 == 0) {
        // 0x80071194: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800711A4;
    }
    // 0x80071194: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80071198: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x8007119C: and         $t2, $s2, $at
    ctx->r10 = ctx->r18 & ctx->r1;
    // 0x800711A0: addiu       $s2, $t2, 0x10
    ctx->r18 = ADD32(ctx->r10, 0X10);
L_800711A4:
    // 0x800711A4: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x800711A8: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x800711AC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_800711B0:
    // 0x800711B0: multu       $s0, $t0
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800711B4: mflo        $t3
    ctx->r11 = lo;
    // 0x800711B8: addu        $v1, $t3, $t1
    ctx->r3 = ADD32(ctx->r11, ctx->r9);
    // 0x800711BC: lh          $t4, 0x8($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X8);
    // 0x800711C0: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800711C4: bne         $t4, $zero, L_800712B8
    if (ctx->r12 != 0) {
        // 0x800711C8: nop
    
            goto L_800712B8;
    }
    // 0x800711C8: nop

    // 0x800711CC: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x800711D0: nop

    // 0x800711D4: sltu        $at, $s1, $a0
    ctx->r1 = ctx->r17 < ctx->r4 ? 1 : 0;
    // 0x800711D8: bne         $at, $zero, L_800712B8
    if (ctx->r1 != 0) {
        // 0x800711DC: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_800712B8;
    }
    // 0x800711DC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800711E0: lw          $t5, 0x4($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X4);
    // 0x800711E4: addu        $t7, $s1, $s2
    ctx->r15 = ADD32(ctx->r17, ctx->r18);
    // 0x800711E8: addu        $t6, $a0, $t5
    ctx->r14 = ADD32(ctx->r4, ctx->r13);
    // 0x800711EC: sltu        $at, $t6, $t7
    ctx->r1 = ctx->r14 < ctx->r15 ? 1 : 0;
    // 0x800711F0: bne         $at, $zero, L_800712B8
    if (ctx->r1 != 0) {
        // 0x800711F4: nop
    
            goto L_800712B8;
    }
    // 0x800711F4: nop

    // 0x800711F8: bne         $s1, $a0, L_80071244
    if (ctx->r17 != ctx->r4) {
        // 0x800711FC: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_80071244;
    }
    // 0x800711FC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80071200: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80071204: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80071208: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8007120C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80071210: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80071214: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80071218: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x8007121C: jal         0x800719CC
    // 0x80071220: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    mempool_slot_assign(rdram, ctx);
        goto after_2;
    // 0x80071220: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_2:
    // 0x80071224: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80071228: jal         0x8006F77C
    // 0x8007122C: nop

    interrupts_enable(rdram, ctx);
        goto after_3;
    // 0x8007122C: nop

    after_3:
    // 0x80071230: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80071234: nop

    // 0x80071238: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8007123C: b           L_800712DC
    // 0x80071240: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_800712DC;
    // 0x80071240: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80071244:
    // 0x80071244: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x80071248: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8007124C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80071250: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80071254: subu        $a2, $s1, $v0
    ctx->r6 = SUB32(ctx->r17, ctx->r2);
    // 0x80071258: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8007125C: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x80071260: jal         0x800719CC
    // 0x80071264: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    mempool_slot_assign(rdram, ctx);
        goto after_4;
    // 0x80071264: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_4:
    // 0x80071268: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8007126C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80071270: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80071274: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80071278: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8007127C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80071280: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80071284: jal         0x800719CC
    // 0x80071288: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    mempool_slot_assign(rdram, ctx);
        goto after_5;
    // 0x80071288: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    after_5:
    // 0x8007128C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80071290: jal         0x8006F77C
    // 0x80071294: nop

    interrupts_enable(rdram, ctx);
        goto after_6;
    // 0x80071294: nop

    after_6:
    // 0x80071298: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x8007129C: multu       $s0, $t0
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800712A0: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800712A4: mflo        $t4
    ctx->r12 = lo;
    // 0x800712A8: addu        $t5, $t4, $t1
    ctx->r13 = ADD32(ctx->r12, ctx->r9);
    // 0x800712AC: lw          $v0, 0x0($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X0);
    // 0x800712B0: b           L_800712DC
    // 0x800712B4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_800712DC;
    // 0x800712B4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800712B8:
    // 0x800712B8: lh          $s0, 0xC($a1)
    ctx->r16 = MEM_H(ctx->r5, 0XC);
    // 0x800712BC: nop

    // 0x800712C0: bne         $s0, $a2, L_800711B0
    if (ctx->r16 != ctx->r6) {
        // 0x800712C4: nop
    
            goto L_800711B0;
    }
    // 0x800712C4: nop

    // 0x800712C8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800712CC: jal         0x8006F77C
    // 0x800712D0: nop

    interrupts_enable(rdram, ctx);
        goto after_7;
    // 0x800712D0: nop

    after_7:
    // 0x800712D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800712D8:
    // 0x800712D8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800712DC:
    // 0x800712DC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800712E0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800712E4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800712E8: jr          $ra
    // 0x800712EC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800712EC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void mempool_free_timer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800712F0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800712F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800712F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800712FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80071300: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80071304: jal         0x8006F750
    // 0x80071308: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    interrupts_disable(rdram, ctx);
        goto after_0;
    // 0x80071308: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    after_0:
    // 0x8007130C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80071310: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80071314: bne         $s0, $zero, L_8007135C
    if (ctx->r16 != 0) {
        // 0x80071318: sw          $s0, 0x434C($at)
        MEM_W(0X434C, ctx->r1) = ctx->r16;
            goto L_8007135C;
    }
    // 0x80071318: sw          $s0, 0x434C($at)
    MEM_W(0X434C, ctx->r1) = ctx->r16;
    // 0x8007131C: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80071320: addiu       $s1, $s1, 0x4348
    ctx->r17 = ADD32(ctx->r17, 0X4348);
    // 0x80071324: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80071328: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8007132C: blez        $s0, L_8007135C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80071330: addiu       $s2, $s2, 0x3B48
        ctx->r18 = ADD32(ctx->r18, 0X3B48);
            goto L_8007135C;
    }
    // 0x80071330: addiu       $s2, $s2, 0x3B48
    ctx->r18 = ADD32(ctx->r18, 0X3B48);
    // 0x80071334: addiu       $v0, $s0, -0x1
    ctx->r2 = ADD32(ctx->r16, -0X1);
L_80071338:
    // 0x80071338: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x8007133C: addu        $t7, $s2, $t6
    ctx->r15 = ADD32(ctx->r18, ctx->r14);
    // 0x80071340: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x80071344: jal         0x800714B8
    // 0x80071348: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    mempool_free_addr(rdram, ctx);
        goto after_1;
    // 0x80071348: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    after_1:
    // 0x8007134C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80071350: nop

    // 0x80071354: bgtz        $s0, L_80071338
    if (SIGNED(ctx->r16) > 0) {
        // 0x80071358: addiu       $v0, $s0, -0x1
        ctx->r2 = ADD32(ctx->r16, -0X1);
            goto L_80071338;
    }
    // 0x80071358: addiu       $v0, $s0, -0x1
    ctx->r2 = ADD32(ctx->r16, -0X1);
L_8007135C:
    // 0x8007135C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80071360: jal         0x8006F77C
    // 0x80071364: nop

    interrupts_enable(rdram, ctx);
        goto after_2;
    // 0x80071364: nop

    after_2:
    // 0x80071368: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8007136C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80071370: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80071374: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80071378: jr          $ra
    // 0x8007137C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8007137C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void mempool_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071380: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80071384: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071388: jal         0x8006F750
    // 0x8007138C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    interrupts_disable(rdram, ctx);
        goto after_0;
    // 0x8007138C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80071390: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80071394: lw          $t6, 0x434C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X434C);
    // 0x80071398: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8007139C: bne         $t6, $zero, L_800713B4
    if (ctx->r14 != 0) {
        // 0x800713A0: sw          $v0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r2;
            goto L_800713B4;
    }
    // 0x800713A0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800713A4: jal         0x800714B8
    // 0x800713A8: nop

    mempool_free_addr(rdram, ctx);
        goto after_1;
    // 0x800713A8: nop

    after_1:
    // 0x800713AC: b           L_800713C0
    // 0x800713B0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
        goto L_800713C0;
    // 0x800713B0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_800713B4:
    // 0x800713B4: jal         0x80071680
    // 0x800713B8: nop

    mempool_free_queue(rdram, ctx);
        goto after_2;
    // 0x800713B8: nop

    after_2:
    // 0x800713BC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_800713C0:
    // 0x800713C0: jal         0x8006F77C
    // 0x800713C4: nop

    interrupts_enable(rdram, ctx);
        goto after_3;
    // 0x800713C4: nop

    after_3:
    // 0x800713C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800713CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800713D0: jr          $ra
    // 0x800713D4: nop

    return;
    // 0x800713D4: nop

;}
RECOMP_FUNC void mempool_free_queue_clear(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800713D8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800713DC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800713E0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800713E4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800713E8: jal         0x8006F750
    // 0x800713EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    interrupts_disable(rdram, ctx);
        goto after_0;
    // 0x800713EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x800713F0: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800713F4: addiu       $s1, $s1, 0x4348
    ctx->r17 = ADD32(ctx->r17, 0X4348);
    // 0x800713F8: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800713FC: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80071400: blez        $v1, L_80071494
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80071404: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_80071494;
    }
    // 0x80071404: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80071408: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8007140C: addiu       $s2, $s2, 0x3B48
    ctx->r18 = ADD32(ctx->r18, 0X3B48);
    // 0x80071410: addiu       $s0, $s0, 0x3B48
    ctx->r16 = ADD32(ctx->r16, 0X3B48);
L_80071414:
    // 0x80071414: lbu         $t6, 0x4($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X4);
    // 0x80071418: nop

    // 0x8007141C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80071420: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x80071424: bne         $t8, $zero, L_80071474
    if (ctx->r24 != 0) {
        // 0x80071428: sb          $t7, 0x4($s0)
        MEM_B(0X4, ctx->r16) = ctx->r15;
            goto L_80071474;
    }
    // 0x80071428: sb          $t7, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r15;
    // 0x8007142C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80071430: jal         0x800714B8
    // 0x80071434: nop

    mempool_free_addr(rdram, ctx);
        goto after_1;
    // 0x80071434: nop

    after_1:
    // 0x80071438: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8007143C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80071440: sll         $t9, $v1, 3
    ctx->r25 = S32(ctx->r3 << 3);
    // 0x80071444: addu        $v0, $s2, $t9
    ctx->r2 = ADD32(ctx->r18, ctx->r25);
    // 0x80071448: lw          $t0, -0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, -0X8);
    // 0x8007144C: addiu       $t2, $v1, -0x1
    ctx->r10 = ADD32(ctx->r3, -0X1);
    // 0x80071450: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x80071454: lbu         $t1, -0x4($v0)
    ctx->r9 = MEM_BU(ctx->r2, -0X4);
    // 0x80071458: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x8007145C: addiu       $t4, $t4, 0x3B48
    ctx->r12 = ADD32(ctx->r12, 0X3B48);
    // 0x80071460: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    // 0x80071464: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x80071468: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
    // 0x8007146C: b           L_80071488
    // 0x80071470: sb          $t1, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r9;
        goto L_80071488;
    // 0x80071470: sb          $t1, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r9;
L_80071474:
    // 0x80071474: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80071478: addiu       $t6, $t6, 0x3B48
    ctx->r14 = ADD32(ctx->r14, 0X3B48);
    // 0x8007147C: sll         $t5, $v1, 3
    ctx->r13 = S32(ctx->r3 << 3);
    // 0x80071480: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    // 0x80071484: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_80071488:
    // 0x80071488: sltu        $at, $s0, $a0
    ctx->r1 = ctx->r16 < ctx->r4 ? 1 : 0;
    // 0x8007148C: bne         $at, $zero, L_80071414
    if (ctx->r1 != 0) {
        // 0x80071490: nop
    
            goto L_80071414;
    }
    // 0x80071490: nop

L_80071494:
    // 0x80071494: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80071498: jal         0x8006F77C
    // 0x8007149C: nop

    interrupts_enable(rdram, ctx);
        goto after_2;
    // 0x8007149C: nop

    after_2:
    // 0x800714A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800714A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800714A8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800714AC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800714B0: jr          $ra
    // 0x800714B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800714B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void mempool_free_addr(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800714B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800714BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800714C0: jal         0x8007182C
    // 0x800714C4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    mempool_get_pool(rdram, ctx);
        goto after_0;
    // 0x800714C4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x800714C8: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x800714CC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800714D0: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
    // 0x800714D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800714D8: lw          $v1, 0x3B08($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3B08);
    // 0x800714DC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800714E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800714E4: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x800714E8: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
L_800714EC:
    // 0x800714EC: multu       $a1, $a2
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800714F0: mflo        $t7
    ctx->r15 = lo;
    // 0x800714F4: addu        $v0, $t7, $v1
    ctx->r2 = ADD32(ctx->r15, ctx->r3);
    // 0x800714F8: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800714FC: nop

    // 0x80071500: bne         $a0, $t8, L_80071534
    if (ctx->r4 != ctx->r24) {
        // 0x80071504: nop
    
            goto L_80071534;
    }
    // 0x80071504: nop

    // 0x80071508: lh          $v1, 0x8($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X8);
    // 0x8007150C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80071510: beq         $v1, $at, L_80071520
    if (ctx->r3 == ctx->r1) {
        // 0x80071514: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80071520;
    }
    // 0x80071514: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80071518: bne         $v1, $at, L_80071548
    if (ctx->r3 != ctx->r1) {
        // 0x8007151C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80071548;
    }
    // 0x8007151C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80071520:
    // 0x80071520: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80071524: jal         0x8007188C
    // 0x80071528: nop

    mempool_slot_clear(rdram, ctx);
        goto after_1;
    // 0x80071528: nop

    after_1:
    // 0x8007152C: b           L_80071548
    // 0x80071530: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80071548;
    // 0x80071530: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80071534:
    // 0x80071534: lh          $a1, 0xC($v0)
    ctx->r5 = MEM_H(ctx->r2, 0XC);
    // 0x80071538: nop

    // 0x8007153C: bne         $a1, $a3, L_800714EC
    if (ctx->r5 != ctx->r7) {
        // 0x80071540: nop
    
            goto L_800714EC;
    }
    // 0x80071540: nop

    // 0x80071544: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80071548:
    // 0x80071548: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8007154C: jr          $ra
    // 0x80071550: nop

    return;
    // 0x80071550: nop

;}
RECOMP_FUNC void func_80071314(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071554: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80071558: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8007155C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80071560: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80071564: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80071568: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8007156C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80071570: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80071574: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80071578: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8007157C: jal         0x8006F750
    // 0x80071580: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    interrupts_disable(rdram, ctx);
        goto after_0;
    // 0x80071580: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80071584: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80071588: lw          $s2, 0x3B40($s2)
    ctx->r18 = MEM_W(ctx->r18, 0X3B40);
    // 0x8007158C: addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
    // 0x80071590: beq         $s2, $s6, L_80071644
    if (ctx->r18 == ctx->r22) {
        // 0x80071594: sw          $v0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r2;
            goto L_80071644;
    }
    // 0x80071594: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x80071598: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8007159C: addiu       $t7, $t7, 0x3B00
    ctx->r15 = ADD32(ctx->r15, 0X3B00);
    // 0x800715A0: sll         $t6, $s2, 4
    ctx->r14 = S32(ctx->r18 << 4);
    // 0x800715A4: addu        $s5, $t6, $t7
    ctx->r21 = ADD32(ctx->r14, ctx->r15);
    // 0x800715A8: addiu       $fp, $zero, 0x4
    ctx->r30 = ADD32(0, 0X4);
    // 0x800715AC: addiu       $s7, $zero, 0x14
    ctx->r23 = ADD32(0, 0X14);
    // 0x800715B0: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_800715B4:
    // 0x800715B4: lw          $s4, 0x8($s5)
    ctx->r20 = MEM_W(ctx->r21, 0X8);
    // 0x800715B8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800715BC:
    // 0x800715BC: multu       $s0, $s7
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800715C0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800715C4: mflo        $t8
    ctx->r24 = lo;
    // 0x800715C8: addu        $s1, $t8, $s4
    ctx->r17 = ADD32(ctx->r24, ctx->r20);
    // 0x800715CC: lh          $v0, 0x8($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X8);
    // 0x800715D0: nop

    // 0x800715D4: bne         $s3, $v0, L_800715EC
    if (ctx->r19 != ctx->r2) {
        // 0x800715D8: nop
    
            goto L_800715EC;
    }
    // 0x800715D8: nop

    // 0x800715DC: jal         0x8007188C
    // 0x800715E0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mempool_slot_clear(rdram, ctx);
        goto after_1;
    // 0x800715E0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x800715E4: lh          $v0, 0x8($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X8);
    // 0x800715E8: nop

L_800715EC:
    // 0x800715EC: bne         $fp, $v0, L_80071628
    if (ctx->r30 != ctx->r2) {
        // 0x800715F0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80071628;
    }
    // 0x800715F0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800715F4: lw          $t9, 0x4($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X4);
    // 0x800715F8: nop

    // 0x800715FC: bne         $s3, $t9, L_80071614
    if (ctx->r19 != ctx->r25) {
        // 0x80071600: nop
    
            goto L_80071614;
    }
    // 0x80071600: nop

    // 0x80071604: jal         0x8007188C
    // 0x80071608: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mempool_slot_clear(rdram, ctx);
        goto after_2;
    // 0x80071608: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x8007160C: b           L_8007162C
    // 0x80071610: lh          $s0, 0xC($s1)
    ctx->r16 = MEM_H(ctx->r17, 0XC);
        goto L_8007162C;
    // 0x80071610: lh          $s0, 0xC($s1)
    ctx->r16 = MEM_H(ctx->r17, 0XC);
L_80071614:
    // 0x80071614: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80071618: jal         0x8006F77C
    // 0x8007161C: nop

    interrupts_enable(rdram, ctx);
        goto after_3;
    // 0x8007161C: nop

    after_3:
    // 0x80071620: b           L_80071654
    // 0x80071624: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_80071654;
    // 0x80071624: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80071628:
    // 0x80071628: lh          $s0, 0xC($s1)
    ctx->r16 = MEM_H(ctx->r17, 0XC);
L_8007162C:
    // 0x8007162C: nop

    // 0x80071630: bne         $s0, $s6, L_800715BC
    if (ctx->r16 != ctx->r22) {
        // 0x80071634: nop
    
            goto L_800715BC;
    }
    // 0x80071634: nop

    // 0x80071638: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x8007163C: bne         $s2, $s6, L_800715B4
    if (ctx->r18 != ctx->r22) {
        // 0x80071640: addiu       $s5, $s5, -0x10
        ctx->r21 = ADD32(ctx->r21, -0X10);
            goto L_800715B4;
    }
    // 0x80071640: addiu       $s5, $s5, -0x10
    ctx->r21 = ADD32(ctx->r21, -0X10);
L_80071644:
    // 0x80071644: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80071648: jal         0x8006F77C
    // 0x8007164C: nop

    interrupts_enable(rdram, ctx);
        goto after_4;
    // 0x8007164C: nop

    after_4:
    // 0x80071650: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80071654:
    // 0x80071654: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80071658: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8007165C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80071660: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80071664: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80071668: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8007166C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80071670: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80071674: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80071678: jr          $ra
    // 0x8007167C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8007167C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void mempool_free_queue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071680: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80071684: addiu       $a1, $a1, 0x4348
    ctx->r5 = ADD32(ctx->r5, 0X4348);
    // 0x80071688: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8007168C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80071690: addiu       $t7, $t7, 0x3B48
    ctx->r15 = ADD32(ctx->r15, 0X3B48);
    // 0x80071694: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x80071698: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x8007169C: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x800716A0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800716A4: lw          $t8, 0x434C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X434C);
    // 0x800716A8: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x800716AC: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x800716B0: jr          $ra
    // 0x800716B4: sb          $t8, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r24;
    return;
    // 0x800716B4: sb          $t8, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r24;
;}
RECOMP_FUNC void mempool_locked_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800716B8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800716BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800716C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800716C4: jal         0x8006F750
    // 0x800716C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    interrupts_disable(rdram, ctx);
        goto after_0;
    // 0x800716C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x800716CC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800716D0: jal         0x8007182C
    // 0x800716D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mempool_get_pool(rdram, ctx);
        goto after_1;
    // 0x800716D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800716D8: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x800716DC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800716E0: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800716E4: lw          $a0, 0x3B08($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3B08);
    // 0x800716E8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800716EC: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800716F0: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x800716F4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800716F8: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
L_800716FC:
    // 0x800716FC: multu       $v1, $a2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80071700: mflo        $t7
    ctx->r15 = lo;
    // 0x80071704: addu        $a1, $t7, $a0
    ctx->r5 = ADD32(ctx->r15, ctx->r4);
    // 0x80071708: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8007170C: nop

    // 0x80071710: bne         $s0, $t8, L_80071748
    if (ctx->r16 != ctx->r24) {
        // 0x80071714: nop
    
            goto L_80071748;
    }
    // 0x80071714: nop

    // 0x80071718: lh          $v0, 0x8($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X8);
    // 0x8007171C: nop

    // 0x80071720: beq         $a3, $v0, L_80071730
    if (ctx->r7 == ctx->r2) {
        // 0x80071724: ori         $t9, $v0, 0x2
        ctx->r25 = ctx->r2 | 0X2;
            goto L_80071730;
    }
    // 0x80071724: ori         $t9, $v0, 0x2
    ctx->r25 = ctx->r2 | 0X2;
    // 0x80071728: bne         $t0, $v0, L_80071748
    if (ctx->r8 != ctx->r2) {
        // 0x8007172C: ori         $t9, $v0, 0x2
        ctx->r25 = ctx->r2 | 0X2;
            goto L_80071748;
    }
    // 0x8007172C: ori         $t9, $v0, 0x2
    ctx->r25 = ctx->r2 | 0X2;
L_80071730:
    // 0x80071730: sh          $t9, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r25;
    // 0x80071734: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80071738: jal         0x8006F77C
    // 0x8007173C: nop

    interrupts_enable(rdram, ctx);
        goto after_2;
    // 0x8007173C: nop

    after_2:
    // 0x80071740: b           L_80071768
    // 0x80071744: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80071768;
    // 0x80071744: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80071748:
    // 0x80071748: lh          $v1, 0xC($a1)
    ctx->r3 = MEM_H(ctx->r5, 0XC);
    // 0x8007174C: nop

    // 0x80071750: bne         $v1, $t1, L_800716FC
    if (ctx->r3 != ctx->r9) {
        // 0x80071754: nop
    
            goto L_800716FC;
    }
    // 0x80071754: nop

    // 0x80071758: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8007175C: jal         0x8006F77C
    // 0x80071760: nop

    interrupts_enable(rdram, ctx);
        goto after_3;
    // 0x80071760: nop

    after_3:
    // 0x80071764: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80071768:
    // 0x80071768: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007176C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80071770: jr          $ra
    // 0x80071774: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80071774: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void mempool_locked_unset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071778: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007177C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071780: jal         0x8006F750
    // 0x80071784: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    interrupts_disable(rdram, ctx);
        goto after_0;
    // 0x80071784: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80071788: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8007178C: jal         0x8007182C
    // 0x80071790: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    mempool_get_pool(rdram, ctx);
        goto after_1;
    // 0x80071790: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // 0x80071794: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x80071798: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007179C: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800717A0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800717A4: lw          $a0, 0x3B08($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3B08);
    // 0x800717A8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800717AC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x800717B0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
L_800717B4:
    // 0x800717B4: multu       $v1, $a1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800717B8: mflo        $t7
    ctx->r15 = lo;
    // 0x800717BC: addu        $v0, $t7, $a0
    ctx->r2 = ADD32(ctx->r15, ctx->r4);
    // 0x800717C0: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800717C4: nop

    // 0x800717C8: bne         $a3, $t8, L_800717FC
    if (ctx->r7 != ctx->r24) {
        // 0x800717CC: nop
    
            goto L_800717FC;
    }
    // 0x800717CC: nop

    // 0x800717D0: lh          $v1, 0x8($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X8);
    // 0x800717D4: nop

    // 0x800717D8: andi        $t9, $v1, 0x2
    ctx->r25 = ctx->r3 & 0X2;
    // 0x800717DC: beq         $t9, $zero, L_800717FC
    if (ctx->r25 == 0) {
        // 0x800717E0: xori        $t0, $v1, 0x2
        ctx->r8 = ctx->r3 ^ 0X2;
            goto L_800717FC;
    }
    // 0x800717E0: xori        $t0, $v1, 0x2
    ctx->r8 = ctx->r3 ^ 0X2;
    // 0x800717E4: sh          $t0, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r8;
    // 0x800717E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800717EC: jal         0x8006F77C
    // 0x800717F0: nop

    interrupts_enable(rdram, ctx);
        goto after_2;
    // 0x800717F0: nop

    after_2:
    // 0x800717F4: b           L_8007181C
    // 0x800717F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8007181C;
    // 0x800717F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800717FC:
    // 0x800717FC: lh          $v1, 0xC($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XC);
    // 0x80071800: nop

    // 0x80071804: bne         $v1, $a2, L_800717B4
    if (ctx->r3 != ctx->r6) {
        // 0x80071808: nop
    
            goto L_800717B4;
    }
    // 0x80071808: nop

    // 0x8007180C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80071810: jal         0x8006F77C
    // 0x80071814: nop

    interrupts_enable(rdram, ctx);
        goto after_3;
    // 0x80071814: nop

    after_3:
    // 0x80071818: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007181C:
    // 0x8007181C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071820: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80071824: jr          $ra
    // 0x80071828: nop

    return;
    // 0x80071828: nop

;}
RECOMP_FUNC void mempool_get_pool(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007182C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80071830: lw          $v1, 0x3B40($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3B40);
    // 0x80071834: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80071838: blez        $v1, L_80071884
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8007183C: sll         $t6, $v1, 4
        ctx->r14 = S32(ctx->r3 << 4);
            goto L_80071884;
    }
    // 0x8007183C: sll         $t6, $v1, 4
    ctx->r14 = S32(ctx->r3 << 4);
    // 0x80071840: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80071844: addiu       $t7, $t7, 0x3B00
    ctx->r15 = ADD32(ctx->r15, 0X3B00);
    // 0x80071848: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
L_8007184C:
    // 0x8007184C: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    // 0x80071850: nop

    // 0x80071854: sltu        $at, $a0, $a1
    ctx->r1 = ctx->r4 < ctx->r5 ? 1 : 0;
    // 0x80071858: beq         $at, $zero, L_80071878
    if (ctx->r1 == 0) {
        // 0x8007185C: nop
    
            goto L_80071878;
    }
    // 0x8007185C: nop

    // 0x80071860: lw          $t8, 0xC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XC);
    // 0x80071864: nop

    // 0x80071868: addu        $t9, $t8, $a0
    ctx->r25 = ADD32(ctx->r24, ctx->r4);
    // 0x8007186C: sltu        $at, $a1, $t9
    ctx->r1 = ctx->r5 < ctx->r25 ? 1 : 0;
    // 0x80071870: bne         $at, $zero, L_80071884
    if (ctx->r1 != 0) {
        // 0x80071874: nop
    
            goto L_80071884;
    }
    // 0x80071874: nop

L_80071878:
    // 0x80071878: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8007187C: bgtz        $v1, L_8007184C
    if (SIGNED(ctx->r3) > 0) {
        // 0x80071880: addiu       $v0, $v0, -0x10
        ctx->r2 = ADD32(ctx->r2, -0X10);
            goto L_8007184C;
    }
    // 0x80071880: addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
L_80071884:
    // 0x80071884: jr          $ra
    // 0x80071888: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80071888: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void mempool_slot_clear(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007188C: addiu       $t2, $zero, 0x14
    ctx->r10 = ADD32(0, 0X14);
    // 0x80071890: multu       $a1, $t2
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80071894: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80071898: addiu       $t7, $t7, 0x3B00
    ctx->r15 = ADD32(ctx->r15, 0X3B00);
    // 0x8007189C: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x800718A0: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800718A4: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800718A8: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800718AC: mflo        $t8
    ctx->r24 = lo;
    // 0x800718B0: addu        $a3, $t8, $v0
    ctx->r7 = ADD32(ctx->r24, ctx->r2);
    // 0x800718B4: lh          $a2, 0xC($a3)
    ctx->r6 = MEM_H(ctx->r7, 0XC);
    // 0x800718B8: lh          $t0, 0xA($a3)
    ctx->r8 = MEM_H(ctx->r7, 0XA);
    // 0x800718BC: beq         $a2, $t3, L_80071934
    if (ctx->r6 == ctx->r11) {
        // 0x800718C0: sh          $zero, 0x8($a3)
        MEM_H(0X8, ctx->r7) = 0;
            goto L_80071934;
    }
    // 0x800718C0: sh          $zero, 0x8($a3)
    MEM_H(0X8, ctx->r7) = 0;
    // 0x800718C4: multu       $a2, $t2
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800718C8: mflo        $t9
    ctx->r25 = lo;
    // 0x800718CC: addu        $a0, $t9, $v0
    ctx->r4 = ADD32(ctx->r25, ctx->r2);
    // 0x800718D0: lh          $t4, 0x8($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X8);
    // 0x800718D4: nop

    // 0x800718D8: bne         $t4, $zero, L_80071934
    if (ctx->r12 != 0) {
        // 0x800718DC: nop
    
            goto L_80071934;
    }
    // 0x800718DC: nop

    // 0x800718E0: lw          $t5, 0x4($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X4);
    // 0x800718E4: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800718E8: nop

    // 0x800718EC: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800718F0: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x800718F4: lh          $t1, 0xC($a0)
    ctx->r9 = MEM_H(ctx->r4, 0XC);
    // 0x800718F8: nop

    // 0x800718FC: beq         $t1, $t3, L_80071914
    if (ctx->r9 == ctx->r11) {
        // 0x80071900: sh          $t1, 0xC($a3)
        MEM_H(0XC, ctx->r7) = ctx->r9;
            goto L_80071914;
    }
    // 0x80071900: sh          $t1, 0xC($a3)
    MEM_H(0XC, ctx->r7) = ctx->r9;
    // 0x80071904: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80071908: mflo        $t8
    ctx->r24 = lo;
    // 0x8007190C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80071910: sh          $a1, 0xA($t9)
    MEM_H(0XA, ctx->r25) = ctx->r5;
L_80071914:
    // 0x80071914: lw          $t4, 0x4($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X4);
    // 0x80071918: nop

    // 0x8007191C: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x80071920: multu       $t5, $t2
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80071924: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x80071928: mflo        $t7
    ctx->r15 = lo;
    // 0x8007192C: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80071930: sh          $a2, 0xE($t8)
    MEM_H(0XE, ctx->r24) = ctx->r6;
L_80071934:
    // 0x80071934: beq         $t0, $t3, L_800719AC
    if (ctx->r8 == ctx->r11) {
        // 0x80071938: nop
    
            goto L_800719AC;
    }
    // 0x80071938: nop

    // 0x8007193C: multu       $t0, $t2
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80071940: mflo        $t9
    ctx->r25 = lo;
    // 0x80071944: addu        $a0, $t9, $v0
    ctx->r4 = ADD32(ctx->r25, ctx->r2);
    // 0x80071948: lh          $t4, 0x8($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X8);
    // 0x8007194C: nop

    // 0x80071950: bne         $t4, $zero, L_800719AC
    if (ctx->r12 != 0) {
        // 0x80071954: nop
    
            goto L_800719AC;
    }
    // 0x80071954: nop

    // 0x80071958: lw          $t5, 0x4($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X4);
    // 0x8007195C: lw          $t6, 0x4($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X4);
    // 0x80071960: nop

    // 0x80071964: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80071968: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8007196C: lh          $t1, 0xC($a3)
    ctx->r9 = MEM_H(ctx->r7, 0XC);
    // 0x80071970: nop

    // 0x80071974: beq         $t1, $t3, L_8007198C
    if (ctx->r9 == ctx->r11) {
        // 0x80071978: sh          $t1, 0xC($a0)
        MEM_H(0XC, ctx->r4) = ctx->r9;
            goto L_8007198C;
    }
    // 0x80071978: sh          $t1, 0xC($a0)
    MEM_H(0XC, ctx->r4) = ctx->r9;
    // 0x8007197C: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80071980: mflo        $t8
    ctx->r24 = lo;
    // 0x80071984: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80071988: sh          $t0, 0xA($t9)
    MEM_H(0XA, ctx->r25) = ctx->r8;
L_8007198C:
    // 0x8007198C: lw          $t4, 0x4($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X4);
    // 0x80071990: nop

    // 0x80071994: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x80071998: multu       $t5, $t2
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007199C: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x800719A0: mflo        $t7
    ctx->r15 = lo;
    // 0x800719A4: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x800719A8: sh          $a1, 0xE($t8)
    MEM_H(0XE, ctx->r24) = ctx->r5;
L_800719AC:
    // 0x800719AC: jr          $ra
    // 0x800719B0: nop

    return;
    // 0x800719B0: nop

;}
RECOMP_FUNC void get_memory_pool_address(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800719B4: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x800719B8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800719BC: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800719C0: lw          $v0, 0x3B08($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3B08);
    // 0x800719C4: jr          $ra
    // 0x800719C8: nop

    return;
    // 0x800719C8: nop

;}
RECOMP_FUNC void mempool_slot_assign(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800719CC: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x800719D0: multu       $a1, $t3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800719D4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800719D8: addiu       $t7, $t7, 0x3B00
    ctx->r15 = ADD32(ctx->r15, 0X3B00);
    // 0x800719DC: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x800719E0: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800719E4: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800719E8: mflo        $t8
    ctx->r24 = lo;
    // 0x800719EC: addu        $t0, $v0, $t8
    ctx->r8 = ADD32(ctx->r2, ctx->r24);
    // 0x800719F0: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x800719F4: sh          $a3, 0x8($t0)
    MEM_H(0X8, ctx->r8) = ctx->r7;
    // 0x800719F8: sw          $a2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r6;
    // 0x800719FC: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x80071A00: slt         $at, $a2, $t1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80071A04: beq         $at, $zero, L_80071A84
    if (ctx->r1 == 0) {
        // 0x80071A08: sw          $t9, 0x10($t0)
        MEM_W(0X10, ctx->r8) = ctx->r25;
            goto L_80071A84;
    }
    // 0x80071A08: sw          $t9, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r25;
    // 0x80071A0C: lw          $a3, 0x4($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X4);
    // 0x80071A10: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80071A14: multu       $a3, $t3
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80071A18: addiu       $t6, $a3, 0x1
    ctx->r14 = ADD32(ctx->r7, 0X1);
    // 0x80071A1C: mflo        $t4
    ctx->r12 = lo;
    // 0x80071A20: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x80071A24: lh          $a0, 0xE($t5)
    ctx->r4 = MEM_H(ctx->r13, 0XE);
    // 0x80071A28: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80071A2C: multu       $a0, $t3
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80071A30: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x80071A34: subu        $t4, $t1, $a2
    ctx->r12 = SUB32(ctx->r9, ctx->r6);
    // 0x80071A38: addu        $t9, $t8, $a2
    ctx->r25 = ADD32(ctx->r24, ctx->r6);
    // 0x80071A3C: mflo        $t7
    ctx->r15 = lo;
    // 0x80071A40: addu        $t2, $v0, $t7
    ctx->r10 = ADD32(ctx->r2, ctx->r15);
    // 0x80071A44: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x80071A48: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x80071A4C: lw          $t5, 0x10($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X10);
    // 0x80071A50: nop

    // 0x80071A54: sh          $t5, 0x8($t2)
    MEM_H(0X8, ctx->r10) = ctx->r13;
    // 0x80071A58: lh          $t1, 0xC($t0)
    ctx->r9 = MEM_H(ctx->r8, 0XC);
    // 0x80071A5C: sh          $a1, 0xA($t2)
    MEM_H(0XA, ctx->r10) = ctx->r5;
    // 0x80071A60: sh          $t1, 0xC($t2)
    MEM_H(0XC, ctx->r10) = ctx->r9;
    // 0x80071A64: beq         $t1, $at, L_80071A7C
    if (ctx->r9 == ctx->r1) {
        // 0x80071A68: sh          $a0, 0xC($t0)
        MEM_H(0XC, ctx->r8) = ctx->r4;
            goto L_80071A7C;
    }
    // 0x80071A68: sh          $a0, 0xC($t0)
    MEM_H(0XC, ctx->r8) = ctx->r4;
    // 0x80071A6C: multu       $t1, $t3
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80071A70: mflo        $t6
    ctx->r14 = lo;
    // 0x80071A74: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80071A78: sh          $a0, 0xA($t7)
    MEM_H(0XA, ctx->r15) = ctx->r4;
L_80071A7C:
    // 0x80071A7C: jr          $ra
    // 0x80071A80: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80071A80: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80071A84:
    // 0x80071A84: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80071A88: jr          $ra
    // 0x80071A8C: nop

    return;
    // 0x80071A8C: nop

;}
RECOMP_FUNC void align16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071A90: andi        $v1, $a0, 0xF
    ctx->r3 = ctx->r4 & 0XF;
    // 0x80071A94: blez        $v1, L_80071AA4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80071A98: nop
    
            goto L_80071AA4;
    }
    // 0x80071A98: nop

    // 0x80071A9C: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x80071AA0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
L_80071AA4:
    // 0x80071AA4: jr          $ra
    // 0x80071AA8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80071AA8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void align8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071AAC: andi        $v1, $a0, 0x7
    ctx->r3 = ctx->r4 & 0X7;
    // 0x80071AB0: blez        $v1, L_80071AC0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80071AB4: nop
    
            goto L_80071AC0;
    }
    // 0x80071AB4: nop

    // 0x80071AB8: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x80071ABC: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_80071AC0:
    // 0x80071AC0: jr          $ra
    // 0x80071AC4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80071AC4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void align4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071AC8: andi        $v1, $a0, 0x3
    ctx->r3 = ctx->r4 & 0X3;
    // 0x80071ACC: blez        $v1, L_80071ADC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80071AD0: nop
    
            goto L_80071ADC;
    }
    // 0x80071AD0: nop

    // 0x80071AD4: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x80071AD8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
L_80071ADC:
    // 0x80071ADC: jr          $ra
    // 0x80071AE0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80071AE0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void find_active_pool_slot_colours(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071AE4: addiu       $sp, $sp, -0x238
    ctx->r29 = ADD32(ctx->r29, -0X238);
    // 0x80071AE8: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x80071AEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80071AF0: addiu       $a0, $sp, 0x138
    ctx->r4 = ADD32(ctx->r29, 0X138);
    // 0x80071AF4: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80071AF8: addiu       $v1, $sp, 0x138
    ctx->r3 = ADD32(ctx->r29, 0X138);
L_80071AFC:
    // 0x80071AFC: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x80071B00: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80071B04: sw          $zero, -0xC($a1)
    MEM_W(-0XC, ctx->r5) = 0;
    // 0x80071B08: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x80071B0C: sw          $zero, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = 0;
    // 0x80071B10: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x80071B14: sw          $zero, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = 0;
    // 0x80071B18: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80071B1C: sw          $zero, -0x10($a0)
    MEM_W(-0X10, ctx->r4) = 0;
    // 0x80071B20: bne         $a1, $v1, L_80071AFC
    if (ctx->r5 != ctx->r3) {
        // 0x80071B24: sw          $zero, -0x10($a1)
        MEM_W(-0X10, ctx->r5) = 0;
            goto L_80071AFC;
    }
    // 0x80071B24: sw          $zero, -0x10($a1)
    MEM_W(-0X10, ctx->r5) = 0;
    // 0x80071B28: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80071B2C: lw          $a0, 0x3B40($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3B40);
    // 0x80071B30: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80071B34: blez        $a0, L_80071C24
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80071B38: addiu       $a1, $t6, 0x3B00
        ctx->r5 = ADD32(ctx->r14, 0X3B00);
            goto L_80071C24;
    }
    // 0x80071B38: addiu       $a1, $t6, 0x3B00
    ctx->r5 = ADD32(ctx->r14, 0X3B00);
    // 0x80071B3C: sll         $t7, $a0, 4
    ctx->r15 = S32(ctx->r4 << 4);
    // 0x80071B40: addu        $t2, $t7, $a1
    ctx->r10 = ADD32(ctx->r15, ctx->r5);
    // 0x80071B44: addiu       $s0, $zero, 0x14
    ctx->r16 = ADD32(0, 0X14);
    // 0x80071B48: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80071B4C: addiu       $t4, $sp, 0x38
    ctx->r12 = ADD32(ctx->r29, 0X38);
    // 0x80071B50: addiu       $t3, $sp, 0x138
    ctx->r11 = ADD32(ctx->r29, 0X138);
L_80071B54:
    // 0x80071B54: lw          $a0, 0x8($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X8);
    // 0x80071B58: nop

    // 0x80071B5C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_80071B60:
    // 0x80071B60: lh          $t8, 0x8($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X8);
    // 0x80071B64: nop

    // 0x80071B68: beq         $t8, $zero, L_80071BEC
    if (ctx->r24 == 0) {
        // 0x80071B6C: nop
    
            goto L_80071BEC;
    }
    // 0x80071B6C: nop

    // 0x80071B70: lw          $a2, 0x10($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X10);
    // 0x80071B74: lw          $t9, 0x138($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X138);
    // 0x80071B78: beq         $a2, $zero, L_80071BEC
    if (ctx->r6 == 0) {
        // 0x80071B7C: or          $a3, $a2, $zero
        ctx->r7 = ctx->r6 | 0;
            goto L_80071BEC;
    }
    // 0x80071B7C: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80071B80: beq         $a2, $t9, L_80071BBC
    if (ctx->r6 == ctx->r25) {
        // 0x80071B84: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_80071BBC;
    }
    // 0x80071B84: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80071B88: beq         $t9, $zero, L_80071BC0
    if (ctx->r25 == 0) {
        // 0x80071B8C: slti        $at, $t0, 0x40
        ctx->r1 = SIGNED(ctx->r8) < 0X40 ? 1 : 0;
            goto L_80071BC0;
    }
    // 0x80071B8C: slti        $at, $t0, 0x40
    ctx->r1 = SIGNED(ctx->r8) < 0X40 ? 1 : 0;
L_80071B90:
    // 0x80071B90: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80071B94: slti        $at, $t0, 0x40
    ctx->r1 = SIGNED(ctx->r8) < 0X40 ? 1 : 0;
    // 0x80071B98: beq         $at, $zero, L_80071BBC
    if (ctx->r1 == 0) {
        // 0x80071B9C: sll         $t7, $t0, 2
        ctx->r15 = S32(ctx->r8 << 2);
            goto L_80071BBC;
    }
    // 0x80071B9C: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x80071BA0: addu        $t6, $t3, $t7
    ctx->r14 = ADD32(ctx->r11, ctx->r15);
    // 0x80071BA4: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    // 0x80071BA8: nop

    // 0x80071BAC: beq         $a3, $a2, L_80071BC0
    if (ctx->r7 == ctx->r6) {
        // 0x80071BB0: slti        $at, $t0, 0x40
        ctx->r1 = SIGNED(ctx->r8) < 0X40 ? 1 : 0;
            goto L_80071BC0;
    }
    // 0x80071BB0: slti        $at, $t0, 0x40
    ctx->r1 = SIGNED(ctx->r8) < 0X40 ? 1 : 0;
    // 0x80071BB4: bne         $a2, $zero, L_80071B90
    if (ctx->r6 != 0) {
        // 0x80071BB8: nop
    
            goto L_80071B90;
    }
    // 0x80071BB8: nop

L_80071BBC:
    // 0x80071BBC: slti        $at, $t0, 0x40
    ctx->r1 = SIGNED(ctx->r8) < 0X40 ? 1 : 0;
L_80071BC0:
    // 0x80071BC0: beq         $at, $zero, L_80071BE8
    if (ctx->r1 == 0) {
        // 0x80071BC4: sll         $a2, $t0, 2
        ctx->r6 = S32(ctx->r8 << 2);
            goto L_80071BE8;
    }
    // 0x80071BC4: sll         $a2, $t0, 2
    ctx->r6 = S32(ctx->r8 << 2);
    // 0x80071BC8: addu        $t8, $t3, $a2
    ctx->r24 = ADD32(ctx->r11, ctx->r6);
    // 0x80071BCC: sw          $a3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r7;
    // 0x80071BD0: addu        $t1, $t4, $a2
    ctx->r9 = ADD32(ctx->r12, ctx->r6);
    // 0x80071BD4: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x80071BD8: nop

    // 0x80071BDC: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x80071BE0: b           L_80071BEC
    // 0x80071BE4: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
        goto L_80071BEC;
    // 0x80071BE4: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
L_80071BE8:
    // 0x80071BE8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80071BEC:
    // 0x80071BEC: lh          $a3, 0xC($v1)
    ctx->r7 = MEM_H(ctx->r3, 0XC);
    // 0x80071BF0: nop

    // 0x80071BF4: beq         $a3, $t5, L_80071C0C
    if (ctx->r7 == ctx->r13) {
        // 0x80071BF8: or          $a2, $a3, $zero
        ctx->r6 = ctx->r7 | 0;
            goto L_80071C0C;
    }
    // 0x80071BF8: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x80071BFC: multu       $a3, $s0
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80071C00: mflo        $t6
    ctx->r14 = lo;
    // 0x80071C04: addu        $v1, $a0, $t6
    ctx->r3 = ADD32(ctx->r4, ctx->r14);
    // 0x80071C08: nop

L_80071C0C:
    // 0x80071C0C: bne         $a2, $t5, L_80071B60
    if (ctx->r6 != ctx->r13) {
        // 0x80071C10: nop
    
            goto L_80071B60;
    }
    // 0x80071C10: nop

    // 0x80071C14: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x80071C18: sltu        $at, $a1, $t2
    ctx->r1 = ctx->r5 < ctx->r10 ? 1 : 0;
    // 0x80071C1C: bne         $at, $zero, L_80071B54
    if (ctx->r1 != 0) {
        // 0x80071C20: nop
    
            goto L_80071B54;
    }
    // 0x80071C20: nop

L_80071C24:
    // 0x80071C24: lw          $t8, 0x138($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X138);
    // 0x80071C28: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x80071C2C: beq         $t8, $zero, L_80071C5C
    if (ctx->r24 == 0) {
        // 0x80071C30: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80071C5C;
    }
    // 0x80071C30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80071C34: sll         $t9, $zero, 2
    ctx->r25 = S32(0 << 2);
    // 0x80071C38: addiu       $t7, $sp, 0x138
    ctx->r15 = ADD32(ctx->r29, 0X138);
    // 0x80071C3C: addu        $a0, $t9, $t7
    ctx->r4 = ADD32(ctx->r25, ctx->r15);
    // 0x80071C40: addiu       $v1, $sp, 0x238
    ctx->r3 = ADD32(ctx->r29, 0X238);
L_80071C44:
    // 0x80071C44: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x80071C48: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80071C4C: beq         $t6, $zero, L_80071C5C
    if (ctx->r14 == 0) {
        // 0x80071C50: nop
    
            goto L_80071C5C;
    }
    // 0x80071C50: nop

    // 0x80071C54: bne         $a0, $v1, L_80071C44
    if (ctx->r4 != ctx->r3) {
        // 0x80071C58: nop
    
            goto L_80071C44;
    }
    // 0x80071C58: nop

L_80071C5C:
    // 0x80071C5C: jr          $ra
    // 0x80071C60: addiu       $sp, $sp, 0x238
    ctx->r29 = ADD32(ctx->r29, 0X238);
    return;
    // 0x80071C60: addiu       $sp, $sp, 0x238
    ctx->r29 = ADD32(ctx->r29, 0X238);
;}
RECOMP_FUNC void get_memory_colour_tag_count(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071C64: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80071C68: lw          $v0, 0x3B08($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3B08);
    // 0x80071C6C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80071C70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80071C74: addiu       $a2, $zero, 0x640
    ctx->r6 = ADD32(0, 0X640);
L_80071C78:
    // 0x80071C78: lh          $t6, 0x8($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X8);
    // 0x80071C7C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80071C80: beq         $t6, $zero, L_80071C9C
    if (ctx->r14 == 0) {
        // 0x80071C84: nop
    
            goto L_80071C9C;
    }
    // 0x80071C84: nop

    // 0x80071C88: lw          $t7, 0x10($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X10);
    // 0x80071C8C: nop

    // 0x80071C90: bne         $a0, $t7, L_80071C9C
    if (ctx->r4 != ctx->r15) {
        // 0x80071C94: nop
    
            goto L_80071C9C;
    }
    // 0x80071C94: nop

    // 0x80071C98: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80071C9C:
    // 0x80071C9C: lh          $t8, 0x1C($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X1C);
    // 0x80071CA0: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // 0x80071CA4: beq         $t8, $zero, L_80071CC0
    if (ctx->r24 == 0) {
        // 0x80071CA8: nop
    
            goto L_80071CC0;
    }
    // 0x80071CA8: nop

    // 0x80071CAC: lw          $t9, 0x10($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X10);
    // 0x80071CB0: nop

    // 0x80071CB4: bne         $a0, $t9, L_80071CC0
    if (ctx->r4 != ctx->r25) {
        // 0x80071CB8: nop
    
            goto L_80071CC0;
    }
    // 0x80071CB8: nop

    // 0x80071CBC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80071CC0:
    // 0x80071CC0: lh          $t0, 0x1C($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X1C);
    // 0x80071CC4: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // 0x80071CC8: beq         $t0, $zero, L_80071CE4
    if (ctx->r8 == 0) {
        // 0x80071CCC: nop
    
            goto L_80071CE4;
    }
    // 0x80071CCC: nop

    // 0x80071CD0: lw          $t1, 0x10($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X10);
    // 0x80071CD4: nop

    // 0x80071CD8: bne         $a0, $t1, L_80071CE4
    if (ctx->r4 != ctx->r9) {
        // 0x80071CDC: nop
    
            goto L_80071CE4;
    }
    // 0x80071CDC: nop

    // 0x80071CE0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80071CE4:
    // 0x80071CE4: lh          $t2, 0x1C($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X1C);
    // 0x80071CE8: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // 0x80071CEC: beq         $t2, $zero, L_80071D08
    if (ctx->r10 == 0) {
        // 0x80071CF0: nop
    
            goto L_80071D08;
    }
    // 0x80071CF0: nop

    // 0x80071CF4: lw          $t3, 0x10($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X10);
    // 0x80071CF8: nop

    // 0x80071CFC: bne         $a0, $t3, L_80071D08
    if (ctx->r4 != ctx->r11) {
        // 0x80071D00: nop
    
            goto L_80071D08;
    }
    // 0x80071D00: nop

    // 0x80071D04: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80071D08:
    // 0x80071D08: bne         $a1, $a2, L_80071C78
    if (ctx->r5 != ctx->r6) {
        // 0x80071D0C: addiu       $v0, $v0, 0x14
        ctx->r2 = ADD32(ctx->r2, 0X14);
            goto L_80071C78;
    }
    // 0x80071D0C: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // 0x80071D10: jr          $ra
    // 0x80071D14: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80071D14: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void mempool_print_tags_usb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071D18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071D1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071D20: lui         $a0, 0xFF00
    ctx->r4 = S32(0XFF00 << 16);
    // 0x80071D24: jal         0x80071C64
    // 0x80071D28: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    get_memory_colour_tag_count(rdram, ctx);
        goto after_0;
    // 0x80071D28: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_0:
    // 0x80071D2C: lui         $a0, 0xFF
    ctx->r4 = S32(0XFF << 16);
    // 0x80071D30: jal         0x80071C64
    // 0x80071D34: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    get_memory_colour_tag_count(rdram, ctx);
        goto after_1;
    // 0x80071D34: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_1:
    // 0x80071D38: jal         0x80071C64
    // 0x80071D3C: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    get_memory_colour_tag_count(rdram, ctx);
        goto after_2;
    // 0x80071D3C: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    after_2:
    // 0x80071D40: lui         $a0, 0xFFFF
    ctx->r4 = S32(0XFFFF << 16);
    // 0x80071D44: jal         0x80071C64
    // 0x80071D48: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    get_memory_colour_tag_count(rdram, ctx);
        goto after_3;
    // 0x80071D48: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_3:
    // 0x80071D4C: lui         $a0, 0xFF00
    ctx->r4 = S32(0XFF00 << 16);
    // 0x80071D50: jal         0x80071C64
    // 0x80071D54: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    get_memory_colour_tag_count(rdram, ctx);
        goto after_4;
    // 0x80071D54: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    after_4:
    // 0x80071D58: lui         $a0, 0xFF
    ctx->r4 = S32(0XFF << 16);
    // 0x80071D5C: jal         0x80071C64
    // 0x80071D60: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    get_memory_colour_tag_count(rdram, ctx);
        goto after_5;
    // 0x80071D60: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    after_5:
    // 0x80071D64: jal         0x80071C64
    // 0x80071D68: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    get_memory_colour_tag_count(rdram, ctx);
        goto after_6;
    // 0x80071D68: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_6:
    // 0x80071D6C: lui         $a0, 0x7F7F
    ctx->r4 = S32(0X7F7F << 16);
    // 0x80071D70: jal         0x80071C64
    // 0x80071D74: ori         $a0, $a0, 0x7FFF
    ctx->r4 = ctx->r4 | 0X7FFF;
    get_memory_colour_tag_count(rdram, ctx);
        goto after_7;
    // 0x80071D74: ori         $a0, $a0, 0x7FFF
    ctx->r4 = ctx->r4 | 0X7FFF;
    after_7:
    // 0x80071D78: lui         $a0, 0xFF7F
    ctx->r4 = S32(0XFF7F << 16);
    // 0x80071D7C: jal         0x80071C64
    // 0x80071D80: ori         $a0, $a0, 0x7FFF
    ctx->r4 = ctx->r4 | 0X7FFF;
    get_memory_colour_tag_count(rdram, ctx);
        goto after_8;
    // 0x80071D80: ori         $a0, $a0, 0x7FFF
    ctx->r4 = ctx->r4 | 0X7FFF;
    after_8:
    // 0x80071D84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071D88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071D8C: jr          $ra
    // 0x80071D90: nop

    return;
    // 0x80071D90: nop

;}
RECOMP_FUNC void mempool_print_tags_screen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071D94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071D98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071D9C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80071DA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80071DA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80071DA8: jal         0x800B6814
    // 0x80071DAC: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    set_render_printf_background_colour(rdram, ctx);
        goto after_0;
    // 0x80071DAC: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_0:
    // 0x80071DB0: lui         $a0, 0xFF00
    ctx->r4 = S32(0XFF00 << 16);
    // 0x80071DB4: jal         0x80071C64
    // 0x80071DB8: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    get_memory_colour_tag_count(rdram, ctx);
        goto after_1;
    // 0x80071DB8: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_1:
    // 0x80071DBC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80071DC0: addiu       $a0, $a0, 0x7AB8
    ctx->r4 = ADD32(ctx->r4, 0X7AB8);
    // 0x80071DC4: jal         0x800B643C
    // 0x80071DC8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    render_printf(rdram, ctx);
        goto after_2;
    // 0x80071DC8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80071DCC: lui         $a0, 0xFF
    ctx->r4 = S32(0XFF << 16);
    // 0x80071DD0: jal         0x80071C64
    // 0x80071DD4: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    get_memory_colour_tag_count(rdram, ctx);
        goto after_3;
    // 0x80071DD4: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_3:
    // 0x80071DD8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80071DDC: addiu       $a0, $a0, 0x7AC0
    ctx->r4 = ADD32(ctx->r4, 0X7AC0);
    // 0x80071DE0: jal         0x800B643C
    // 0x80071DE4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    render_printf(rdram, ctx);
        goto after_4;
    // 0x80071DE4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x80071DE8: jal         0x80071C64
    // 0x80071DEC: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    get_memory_colour_tag_count(rdram, ctx);
        goto after_5;
    // 0x80071DEC: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    after_5:
    // 0x80071DF0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80071DF4: addiu       $a0, $a0, 0x7ACC
    ctx->r4 = ADD32(ctx->r4, 0X7ACC);
    // 0x80071DF8: jal         0x800B643C
    // 0x80071DFC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    render_printf(rdram, ctx);
        goto after_6;
    // 0x80071DFC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x80071E00: lui         $a0, 0xFFFF
    ctx->r4 = S32(0XFFFF << 16);
    // 0x80071E04: jal         0x80071C64
    // 0x80071E08: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    get_memory_colour_tag_count(rdram, ctx);
        goto after_7;
    // 0x80071E08: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_7:
    // 0x80071E0C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80071E10: addiu       $a0, $a0, 0x7AD8
    ctx->r4 = ADD32(ctx->r4, 0X7AD8);
    // 0x80071E14: jal         0x800B643C
    // 0x80071E18: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    render_printf(rdram, ctx);
        goto after_8;
    // 0x80071E18: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_8:
    // 0x80071E1C: lui         $a0, 0xFF00
    ctx->r4 = S32(0XFF00 << 16);
    // 0x80071E20: jal         0x80071C64
    // 0x80071E24: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    get_memory_colour_tag_count(rdram, ctx);
        goto after_9;
    // 0x80071E24: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    after_9:
    // 0x80071E28: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80071E2C: addiu       $a0, $a0, 0x7AE4
    ctx->r4 = ADD32(ctx->r4, 0X7AE4);
    // 0x80071E30: jal         0x800B643C
    // 0x80071E34: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    render_printf(rdram, ctx);
        goto after_10;
    // 0x80071E34: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_10:
    // 0x80071E38: lui         $a0, 0xFF
    ctx->r4 = S32(0XFF << 16);
    // 0x80071E3C: jal         0x80071C64
    // 0x80071E40: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    get_memory_colour_tag_count(rdram, ctx);
        goto after_11;
    // 0x80071E40: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    after_11:
    // 0x80071E44: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80071E48: addiu       $a0, $a0, 0x7AF0
    ctx->r4 = ADD32(ctx->r4, 0X7AF0);
    // 0x80071E4C: jal         0x800B643C
    // 0x80071E50: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    render_printf(rdram, ctx);
        goto after_12;
    // 0x80071E50: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_12:
    // 0x80071E54: jal         0x80071C64
    // 0x80071E58: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    get_memory_colour_tag_count(rdram, ctx);
        goto after_13;
    // 0x80071E58: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_13:
    // 0x80071E5C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80071E60: addiu       $a0, $a0, 0x7AFC
    ctx->r4 = ADD32(ctx->r4, 0X7AFC);
    // 0x80071E64: jal         0x800B643C
    // 0x80071E68: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    render_printf(rdram, ctx);
        goto after_14;
    // 0x80071E68: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_14:
    // 0x80071E6C: lui         $a0, 0x7F7F
    ctx->r4 = S32(0X7F7F << 16);
    // 0x80071E70: jal         0x80071C64
    // 0x80071E74: ori         $a0, $a0, 0x7FFF
    ctx->r4 = ctx->r4 | 0X7FFF;
    get_memory_colour_tag_count(rdram, ctx);
        goto after_15;
    // 0x80071E74: ori         $a0, $a0, 0x7FFF
    ctx->r4 = ctx->r4 | 0X7FFF;
    after_15:
    // 0x80071E78: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80071E7C: addiu       $a0, $a0, 0x7B08
    ctx->r4 = ADD32(ctx->r4, 0X7B08);
    // 0x80071E80: jal         0x800B643C
    // 0x80071E84: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    render_printf(rdram, ctx);
        goto after_16;
    // 0x80071E84: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_16:
    // 0x80071E88: lui         $a0, 0xFF7F
    ctx->r4 = S32(0XFF7F << 16);
    // 0x80071E8C: jal         0x80071C64
    // 0x80071E90: ori         $a0, $a0, 0x7FFF
    ctx->r4 = ctx->r4 | 0X7FFF;
    get_memory_colour_tag_count(rdram, ctx);
        goto after_17;
    // 0x80071E90: ori         $a0, $a0, 0x7FFF
    ctx->r4 = ctx->r4 | 0X7FFF;
    after_17:
    // 0x80071E94: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80071E98: addiu       $a0, $a0, 0x7B14
    ctx->r4 = ADD32(ctx->r4, 0X7B14);
    // 0x80071E9C: jal         0x800B643C
    // 0x80071EA0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    render_printf(rdram, ctx);
        goto after_18;
    // 0x80071EA0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_18:
    // 0x80071EA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071EA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071EAC: jr          $ra
    // 0x80071EB0: nop

    return;
    // 0x80071EB0: nop

;}
RECOMP_FUNC void mmSlotPrint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071EB4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80071EB8: lw          $v1, 0x3B40($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3B40);
    // 0x80071EBC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80071EC0: bltz        $v1, L_80071F20
    if (SIGNED(ctx->r3) < 0) {
        // 0x80071EC4: addiu       $a0, $t6, 0x3B00
        ctx->r4 = ADD32(ctx->r14, 0X3B00);
            goto L_80071F20;
    }
    // 0x80071EC4: addiu       $a0, $t6, 0x3B00
    ctx->r4 = ADD32(ctx->r14, 0X3B00);
    // 0x80071EC8: sll         $t7, $v1, 4
    ctx->r15 = S32(ctx->r3 << 4);
    // 0x80071ECC: addu        $t0, $t7, $a0
    ctx->r8 = ADD32(ctx->r15, ctx->r4);
    // 0x80071ED0: addiu       $t4, $zero, 0x14
    ctx->r12 = ADD32(0, 0X14);
    // 0x80071ED4: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
L_80071ED8:
    // 0x80071ED8: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
    // 0x80071EDC: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80071EE0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80071EE4:
    // 0x80071EE4: lh          $a1, 0x8($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X8);
    // 0x80071EE8: lh          $a3, 0xC($v0)
    ctx->r7 = MEM_H(ctx->r2, 0XC);
    // 0x80071EEC: beq         $a1, $zero, L_80071EF4
    if (ctx->r5 == 0) {
        // 0x80071EF0: or          $a2, $a3, $zero
        ctx->r6 = ctx->r7 | 0;
            goto L_80071EF4;
    }
    // 0x80071EF0: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
L_80071EF4:
    // 0x80071EF4: beq         $a2, $t3, L_80071F0C
    if (ctx->r6 == ctx->r11) {
        // 0x80071EF8: nop
    
            goto L_80071F0C;
    }
    // 0x80071EF8: nop

    // 0x80071EFC: multu       $a3, $t4
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80071F00: mflo        $t8
    ctx->r24 = lo;
    // 0x80071F04: addu        $v0, $v1, $t8
    ctx->r2 = ADD32(ctx->r3, ctx->r24);
    // 0x80071F08: nop

L_80071F0C:
    // 0x80071F0C: bne         $a2, $t3, L_80071EE4
    if (ctx->r6 != ctx->r11) {
        // 0x80071F10: nop
    
            goto L_80071EE4;
    }
    // 0x80071F10: nop

    // 0x80071F14: sltu        $at, $t0, $a0
    ctx->r1 = ctx->r8 < ctx->r4 ? 1 : 0;
    // 0x80071F18: beq         $at, $zero, L_80071ED8
    if (ctx->r1 == 0) {
        // 0x80071F1C: nop
    
            goto L_80071ED8;
    }
    // 0x80071F1C: nop

L_80071F20:
    // 0x80071F20: jr          $ra
    // 0x80071F24: nop

    return;
    // 0x80071F24: nop

;}
RECOMP_FUNC void func_80071CE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071F28: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80071F2C: lw          $v0, 0x3B40($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3B40);
    // 0x80071F30: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80071F34: beq         $v0, $a1, L_80071F68
    if (ctx->r2 == ctx->r5) {
        // 0x80071F38: addiu       $a0, $v0, 0x1
        ctx->r4 = ADD32(ctx->r2, 0X1);
            goto L_80071F68;
    }
    // 0x80071F38: addiu       $a0, $v0, 0x1
    ctx->r4 = ADD32(ctx->r2, 0X1);
    // 0x80071F3C: andi        $t6, $a0, 0x3
    ctx->r14 = ctx->r4 & 0X3;
    // 0x80071F40: negu        $a0, $t6
    ctx->r4 = SUB32(0, ctx->r14);
    // 0x80071F44: beq         $a0, $zero, L_80071F5C
    if (ctx->r4 == 0) {
        // 0x80071F48: addu        $v1, $a0, $v0
        ctx->r3 = ADD32(ctx->r4, ctx->r2);
            goto L_80071F5C;
    }
    // 0x80071F48: addu        $v1, $a0, $v0
    ctx->r3 = ADD32(ctx->r4, ctx->r2);
L_80071F4C:
    // 0x80071F4C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80071F50: bne         $v1, $v0, L_80071F4C
    if (ctx->r3 != ctx->r2) {
        // 0x80071F54: nop
    
            goto L_80071F4C;
    }
    // 0x80071F54: nop

    // 0x80071F58: beq         $v0, $a1, L_80071F68
    if (ctx->r2 == ctx->r5) {
        // 0x80071F5C: addiu       $v0, $v0, -0x4
        ctx->r2 = ADD32(ctx->r2, -0X4);
            goto L_80071F68;
    }
L_80071F5C:
    // 0x80071F5C: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
L_80071F60:
    // 0x80071F60: bne         $v0, $a1, L_80071F60
    if (ctx->r2 != ctx->r5) {
        // 0x80071F64: addiu       $v0, $v0, -0x4
        ctx->r2 = ADD32(ctx->r2, -0X4);
            goto L_80071F60;
    }
    // 0x80071F64: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
L_80071F68:
    // 0x80071F68: jr          $ra
    // 0x80071F6C: nop

    return;
    // 0x80071F6C: nop

;}
RECOMP_FUNC void input_get_id(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072490: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80072494: beq         $a0, $zero, L_800724A8
    if (ctx->r4 == 0) {
        // 0x80072498: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800724A8;
    }
    // 0x80072498: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007249C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800724A0: bne         $a0, $at, L_800724C0
    if (ctx->r4 != ctx->r1) {
        // 0x800724A4: nop
    
            goto L_800724C0;
    }
    // 0x800724A4: nop

L_800724A8:
    // 0x800724A8: jal         0x8000E158
    // 0x800724AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    is_race_started_by_player_two(rdram, ctx);
        goto after_0;
    // 0x800724AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800724B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800724B4: beq         $v0, $zero, L_800724C0
    if (ctx->r2 == 0) {
        // 0x800724B8: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_800724C0;
    }
    // 0x800724B8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800724BC: subu        $a0, $t6, $a0
    ctx->r4 = SUB32(ctx->r14, ctx->r4);
L_800724C0:
    // 0x800724C0: jal         0x8006A738
    // 0x800724C4: nop

    input_player_id(rdram, ctx);
        goto after_1;
    // 0x800724C4: nop

    after_1:
    // 0x800724C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800724CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800724D0: jr          $ra
    // 0x800724D4: nop

    return;
    // 0x800724D4: nop

;}
RECOMP_FUNC void rumble_enable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800724D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800724DC: jr          $ra
    // 0x800724E0: sw          $a0, -0x1600($at)
    MEM_W(-0X1600, ctx->r1) = ctx->r4;
    return;
    // 0x800724E0: sw          $a0, -0x1600($at)
    MEM_W(-0X1600, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void rumble_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800724E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800724E8: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800724EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800724F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800724F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800724F8: beq         $t6, $zero, L_8007251C
    if (ctx->r14 == 0) {
        // 0x800724FC: sb          $t6, 0x4764($at)
        MEM_B(0X4764, ctx->r1) = ctx->r14;
            goto L_8007251C;
    }
    // 0x800724FC: sb          $t6, 0x4764($at)
    MEM_B(0X4764, ctx->r1) = ctx->r14;
    // 0x80072500: addiu       $t7, $zero, 0x79
    ctx->r15 = ADD32(0, 0X79);
    // 0x80072504: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80072508: sw          $t7, 0x4768($at)
    MEM_W(0X4768, ctx->r1) = ctx->r15;
    // 0x8007250C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80072510: addiu       $t8, $zero, 0xF
    ctx->r24 = ADD32(0, 0XF);
    // 0x80072514: b           L_80072524
    // 0x80072518: sb          $t8, 0x4766($at)
    MEM_B(0X4766, ctx->r1) = ctx->r24;
        goto L_80072524;
    // 0x80072518: sb          $t8, 0x4766($at)
    MEM_B(0X4766, ctx->r1) = ctx->r24;
L_8007251C:
    // 0x8007251C: jal         0x80072954
    // 0x80072520: nop

    rumble_kill(rdram, ctx);
        goto after_0;
    // 0x80072520: nop

    after_0:
L_80072524:
    // 0x80072524: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80072528: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007252C: jr          $ra
    // 0x80072530: nop

    return;
    // 0x80072530: nop

;}
RECOMP_FUNC void rumble_exists(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072534: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80072538: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8007253C: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80072540: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80072544: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80072548: bltz        $t7, L_8007255C
    if (SIGNED(ctx->r15) < 0) {
        // 0x8007254C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8007255C;
    }
    // 0x8007254C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80072550: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x80072554: bne         $at, $zero, L_80072564
    if (ctx->r1 != 0) {
        // 0x80072558: nop
    
            goto L_80072564;
    }
    // 0x80072558: nop

L_8007255C:
    // 0x8007255C: b           L_80072584
    // 0x80072560: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80072584;
    // 0x80072560: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80072564:
    // 0x80072564: jal         0x80072490
    // 0x80072568: nop

    input_get_id(rdram, ctx);
        goto after_0;
    // 0x80072568: nop

    after_0:
    // 0x8007256C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80072570: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80072574: lbu         $t8, 0x4765($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X4765);
    // 0x80072578: sllv        $t0, $t9, $v0
    ctx->r8 = S32(ctx->r25 << (ctx->r2 & 31));
    // 0x8007257C: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x80072580: and         $v0, $t8, $t1
    ctx->r2 = ctx->r24 & ctx->r9;
L_80072584:
    // 0x80072584: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80072588: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007258C: jr          $ra
    // 0x80072590: nop

    return;
    // 0x80072590: nop

;}
RECOMP_FUNC void rumble_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072594: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80072598: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8007259C: andi        $t8, $a1, 0xFF
    ctx->r24 = ctx->r5 & 0XFF;
    // 0x800725A0: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800725A4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800725A8: slti        $at, $t8, 0x13
    ctx->r1 = SIGNED(ctx->r24) < 0X13 ? 1 : 0;
    // 0x800725AC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800725B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800725B4: beq         $at, $zero, L_80072660
    if (ctx->r1 == 0) {
        // 0x800725B8: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_80072660;
    }
    // 0x800725B8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800725BC: bltz        $t7, L_80072660
    if (SIGNED(ctx->r15) < 0) {
        // 0x800725C0: slti        $at, $t7, 0x4
        ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
            goto L_80072660;
    }
    // 0x800725C0: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x800725C4: beq         $at, $zero, L_80072664
    if (ctx->r1 == 0) {
        // 0x800725C8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80072664;
    }
    // 0x800725C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800725CC: sh          $t7, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r15;
    // 0x800725D0: jal         0x80072490
    // 0x800725D4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    input_get_id(rdram, ctx);
        goto after_0;
    // 0x800725D4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_0:
    // 0x800725D8: andi        $t9, $v0, 0xFFFF
    ctx->r25 = ctx->r2 & 0XFFFF;
    // 0x800725DC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800725E0: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800725E4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800725E8: addiu       $t1, $t1, 0x4738
    ctx->r9 = ADD32(ctx->r9, 0X4738);
    // 0x800725EC: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x800725F0: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
    // 0x800725F4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800725F8: lh          $t2, 0x0($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X0);
    // 0x800725FC: lh          $a0, 0x22($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X22);
    // 0x80072600: bne         $a2, $t2, L_80072634
    if (ctx->r6 != ctx->r10) {
        // 0x80072604: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_80072634;
    }
    // 0x80072604: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80072608: lh          $t3, 0x8($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X8);
    // 0x8007260C: addiu       $t4, $zero, -0x12C
    ctx->r12 = ADD32(0, -0X12C);
    // 0x80072610: bgez        $t3, L_8007261C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80072614: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_8007261C;
    }
    // 0x80072614: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80072618: sh          $t4, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r12;
L_8007261C:
    // 0x8007261C: lw          $t5, 0x4760($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X4760);
    // 0x80072620: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x80072624: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x80072628: lh          $t9, 0x2($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2);
    // 0x8007262C: b           L_80072660
    // 0x80072630: sh          $t9, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r25;
        goto L_80072660;
    // 0x80072630: sh          $t9, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r25;
L_80072634:
    // 0x80072634: sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
    // 0x80072638: lw          $t0, 0x4760($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X4760);
    // 0x8007263C: sll         $t2, $a2, 2
    ctx->r10 = S32(ctx->r6 << 2);
    // 0x80072640: addu        $v0, $t0, $t2
    ctx->r2 = ADD32(ctx->r8, ctx->r10);
    // 0x80072644: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x80072648: nop

    // 0x8007264C: beq         $a1, $zero, L_80072664
    if (ctx->r5 == 0) {
        // 0x80072650: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80072664;
    }
    // 0x80072650: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80072654: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x80072658: jal         0x800727C4
    // 0x8007265C: nop

    rumble_start(rdram, ctx);
        goto after_1;
    // 0x8007265C: nop

    after_1:
L_80072660:
    // 0x80072660: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80072664:
    // 0x80072664: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80072668: jr          $ra
    // 0x8007266C: nop

    return;
    // 0x8007266C: nop

;}
RECOMP_FUNC void rumble_set_fade(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072670: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80072674: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80072678: andi        $t8, $a1, 0xFF
    ctx->r24 = ctx->r5 & 0XFF;
    // 0x8007267C: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80072680: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80072684: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80072688: slti        $at, $t8, 0x13
    ctx->r1 = SIGNED(ctx->r24) < 0X13 ? 1 : 0;
    // 0x8007268C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80072690: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80072694: beq         $at, $zero, L_800727B4
    if (ctx->r1 == 0) {
        // 0x80072698: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_800727B4;
    }
    // 0x80072698: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8007269C: bltz        $t7, L_800727B4
    if (SIGNED(ctx->r15) < 0) {
        // 0x800726A0: slti        $at, $t7, 0x4
        ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
            goto L_800727B4;
    }
    // 0x800726A0: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x800726A4: beq         $at, $zero, L_800727B8
    if (ctx->r1 == 0) {
        // 0x800726A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800727B8;
    }
    // 0x800726A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800726AC: sh          $t7, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r15;
    // 0x800726B0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800726B4: jal         0x80072490
    // 0x800726B8: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    input_get_id(rdram, ctx);
        goto after_0;
    // 0x800726B8: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x800726BC: andi        $t9, $v0, 0xFFFF
    ctx->r25 = ctx->r2 & 0XFFFF;
    // 0x800726C0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800726C4: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800726C8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800726CC: addiu       $t1, $t1, 0x4738
    ctx->r9 = ADD32(ctx->r9, 0X4738);
    // 0x800726D0: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x800726D4: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
    // 0x800726D8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800726DC: lh          $t2, 0x0($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X0);
    // 0x800726E0: lh          $a0, 0x22($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X22);
    // 0x800726E4: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800726E8: bne         $a2, $t2, L_8007271C
    if (ctx->r6 != ctx->r10) {
        // 0x800726EC: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8007271C;
    }
    // 0x800726EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800726F0: lh          $t3, 0x8($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X8);
    // 0x800726F4: addiu       $t4, $zero, -0x12C
    ctx->r12 = ADD32(0, -0X12C);
    // 0x800726F8: bgez        $t3, L_80072704
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800726FC: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_80072704;
    }
    // 0x800726FC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80072700: sh          $t4, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r12;
L_80072704:
    // 0x80072704: lw          $t5, 0x4760($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X4760);
    // 0x80072708: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x8007270C: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x80072710: lh          $t9, 0x2($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2);
    // 0x80072714: b           L_800727B4
    // 0x80072718: sh          $t9, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r25;
        goto L_800727B4;
    // 0x80072718: sh          $t9, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r25;
L_8007271C:
    // 0x8007271C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80072720: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80072724: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80072728: nop

    // 0x8007272C: bc1f        L_80072738
    if (!c1cs) {
        // 0x80072730: nop
    
            goto L_80072738;
    }
    // 0x80072730: nop

    // 0x80072734: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_80072738:
    // 0x80072738: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8007273C: nop

    // 0x80072740: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80072744: nop

    // 0x80072748: bc1f        L_80072754
    if (!c1cs) {
        // 0x8007274C: nop
    
            goto L_80072754;
    }
    // 0x8007274C: nop

    // 0x80072750: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_80072754:
    // 0x80072754: sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
    // 0x80072758: lw          $t0, 0x4760($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X4760);
    // 0x8007275C: sll         $t2, $a2, 2
    ctx->r10 = S32(ctx->r6 << 2);
    // 0x80072760: addu        $v0, $t0, $t2
    ctx->r2 = ADD32(ctx->r8, ctx->r10);
    // 0x80072764: lh          $a3, 0x0($v0)
    ctx->r7 = MEM_H(ctx->r2, 0X0);
    // 0x80072768: nop

    // 0x8007276C: beq         $a3, $zero, L_800727B8
    if (ctx->r7 == 0) {
        // 0x80072770: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800727B8;
    }
    // 0x80072770: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80072774: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
    // 0x80072778: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x8007277C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80072780: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80072784: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80072788: nop

    // 0x8007278C: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80072790: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80072794: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80072798: nop

    // 0x8007279C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800727A0: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800727A4: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800727A8: sll         $t4, $a1, 16
    ctx->r12 = S32(ctx->r5 << 16);
    // 0x800727AC: jal         0x800727C4
    // 0x800727B0: sra         $a1, $t4, 16
    ctx->r5 = S32(SIGNED(ctx->r12) >> 16);
    rumble_start(rdram, ctx);
        goto after_1;
    // 0x800727B0: sra         $a1, $t4, 16
    ctx->r5 = S32(SIGNED(ctx->r12) >> 16);
    after_1:
L_800727B4:
    // 0x800727B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800727B8:
    // 0x800727B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800727BC: jr          $ra
    // 0x800727C0: nop

    return;
    // 0x800727C0: nop

;}
RECOMP_FUNC void rumble_start(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800727C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800727C8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800727CC: lbu         $t9, 0x4764($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X4764);
    // 0x800727D0: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x800727D4: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800727D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800727DC: sll         $a3, $a1, 16
    ctx->r7 = S32(ctx->r5 << 16);
    // 0x800727E0: sra         $t8, $a3, 16
    ctx->r24 = S32(SIGNED(ctx->r7) >> 16);
    // 0x800727E4: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800727E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800727EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800727F0: beq         $t9, $zero, L_800728B8
    if (ctx->r25 == 0) {
        // 0x800727F4: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_800728B8;
    }
    // 0x800727F4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800727F8: bltz        $t7, L_800728B8
    if (SIGNED(ctx->r15) < 0) {
        // 0x800727FC: slti        $at, $t7, 0x4
        ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
            goto L_800728B8;
    }
    // 0x800727FC: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x80072800: beq         $at, $zero, L_800728BC
    if (ctx->r1 == 0) {
        // 0x80072804: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800728BC;
    }
    // 0x80072804: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80072808: jal         0x80072490
    // 0x8007280C: sh          $t8, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r24;
    input_get_id(rdram, ctx);
        goto after_0;
    // 0x8007280C: sh          $t8, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r24;
    after_0:
    // 0x80072810: lh          $a3, 0x1E($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X1E);
    // 0x80072814: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80072818: multu       $a3, $a3
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007281C: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x80072820: addiu       $t0, $t0, 0x4766
    ctx->r8 = ADD32(ctx->r8, 0X4766);
    // 0x80072824: sra         $t2, $a0, 16
    ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80072828: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8007282C: lbu         $t5, 0x0($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X0);
    // 0x80072830: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80072834: sllv        $t4, $t3, $t2
    ctx->r12 = S32(ctx->r11 << (ctx->r10 & 31));
    // 0x80072838: addiu       $t1, $t1, 0x4767
    ctx->r9 = ADD32(ctx->r9, 0X4767);
    // 0x8007283C: lbu         $t7, 0x0($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X0);
    // 0x80072840: nor         $t8, $t4, $zero
    ctx->r24 = ~(ctx->r12 | 0);
    // 0x80072844: or          $t6, $t5, $t4
    ctx->r14 = ctx->r13 | ctx->r12;
    // 0x80072848: mflo        $t4
    ctx->r12 = lo;
    // 0x8007284C: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80072850: and         $t9, $t7, $t8
    ctx->r25 = ctx->r15 & ctx->r24;
    // 0x80072854: sb          $t6, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r14;
    // 0x80072858: sb          $t9, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r25;
    // 0x8007285C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80072860: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80072864: lwc1        $f9, 0x7D70($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X7D70);
    // 0x80072868: lwc1        $f8, 0x7D74($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7D74);
    // 0x8007286C: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x80072870: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80072874: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80072878: addu        $t2, $t2, $a0
    ctx->r10 = ADD32(ctx->r10, ctx->r4);
    // 0x8007287C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80072880: addiu       $t3, $t3, 0x4738
    ctx->r11 = ADD32(ctx->r11, 0X4738);
    // 0x80072884: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80072888: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x8007288C: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80072890: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80072894: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80072898: addu        $v1, $t2, $t3
    ctx->r3 = ADD32(ctx->r10, ctx->r11);
    // 0x8007289C: cvt.w.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_D(ctx->f10.d);
    // 0x800728A0: lh          $t6, 0x22($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X22);
    // 0x800728A4: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x800728A8: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800728AC: sh          $t6, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r14;
    // 0x800728B0: sh          $a2, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r6;
    // 0x800728B4: sh          $a2, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r6;
L_800728B8:
    // 0x800728B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800728BC:
    // 0x800728BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800728C0: jr          $ra
    // 0x800728C4: nop

    return;
    // 0x800728C4: nop

;}
RECOMP_FUNC void rumble_stop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800728C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800728CC: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x800728D0: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800728D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800728D8: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800728DC: bltz        $t7, L_80072944
    if (SIGNED(ctx->r15) < 0) {
        // 0x800728E0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80072944;
    }
    // 0x800728E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800728E4: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x800728E8: beq         $at, $zero, L_80072948
    if (ctx->r1 == 0) {
        // 0x800728EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80072948;
    }
    // 0x800728EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800728F0: jal         0x80072490
    // 0x800728F4: nop

    input_get_id(rdram, ctx);
        goto after_0;
    // 0x800728F4: nop

    after_0:
    // 0x800728F8: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x800728FC: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80072900: sll         $t3, $t8, 2
    ctx->r11 = S32(ctx->r24 << 2);
    // 0x80072904: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80072908: addu        $t3, $t3, $t8
    ctx->r11 = ADD32(ctx->r11, ctx->r24);
    // 0x8007290C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80072910: addiu       $a1, $a1, 0x4767
    ctx->r5 = ADD32(ctx->r5, 0X4767);
    // 0x80072914: addiu       $t4, $t4, 0x4738
    ctx->r12 = ADD32(ctx->r12, 0X4738);
    // 0x80072918: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x8007291C: lbu         $t9, 0x0($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X0);
    // 0x80072920: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80072924: addu        $v1, $t3, $t4
    ctx->r3 = ADD32(ctx->r11, ctx->r12);
    // 0x80072928: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8007292C: sllv        $t1, $t0, $t8
    ctx->r9 = S32(ctx->r8 << (ctx->r24 & 31));
    // 0x80072930: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x80072934: sb          $t2, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r10;
    // 0x80072938: sh          $a2, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r6;
    // 0x8007293C: sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
    // 0x80072940: sh          $zero, 0x8($v1)
    MEM_H(0X8, ctx->r3) = 0;
L_80072944:
    // 0x80072944: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80072948:
    // 0x80072948: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007294C: jr          $ra
    // 0x80072950: nop

    return;
    // 0x80072950: nop

;}
RECOMP_FUNC void rumble_kill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072954: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80072958: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007295C: jr          $ra
    // 0x80072960: sw          $t6, -0x1604($at)
    MEM_W(-0X1604, ctx->r1) = ctx->r14;
    return;
    // 0x80072960: sw          $t6, -0x1604($at)
    MEM_W(-0X1604, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void rumble_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072964: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80072968: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8007296C: lw          $t6, -0x1600($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X1600);
    // 0x80072970: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80072974: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x80072978: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8007297C: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80072980: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80072984: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80072988: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8007298C: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80072990: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80072994: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80072998: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8007299C: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x800729A0: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800729A4: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800729A8: beq         $t6, $zero, L_80072E6C
    if (ctx->r14 == 0) {
        // 0x800729AC: sw          $a0, 0x78($sp)
        MEM_W(0X78, ctx->r29) = ctx->r4;
            goto L_80072E6C;
    }
    // 0x800729AC: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x800729B0: lui         $fp, 0x8012
    ctx->r30 = S32(0X8012 << 16);
    // 0x800729B4: addiu       $fp, $fp, 0x4766
    ctx->r30 = ADD32(ctx->r30, 0X4766);
    // 0x800729B8: lbu         $t7, 0x0($fp)
    ctx->r15 = MEM_BU(ctx->r30, 0X0);
    // 0x800729BC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800729C0: bne         $t7, $zero, L_800729D4
    if (ctx->r15 != 0) {
        // 0x800729C4: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_800729D4;
    }
    // 0x800729C4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800729C8: lw          $t8, -0x1604($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X1604);
    // 0x800729CC: nop

    // 0x800729D0: beq         $t8, $zero, L_80072E6C
    if (ctx->r24 == 0) {
        // 0x800729D4: addiu       $v0, $v0, 0x4768
        ctx->r2 = ADD32(ctx->r2, 0X4768);
            goto L_80072E6C;
    }
L_800729D4:
    // 0x800729D4: addiu       $v0, $v0, 0x4768
    ctx->r2 = ADD32(ctx->r2, 0X4768);
    // 0x800729D8: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800729DC: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x800729E0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800729E4: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800729E8: slti        $at, $t1, 0x79
    ctx->r1 = SIGNED(ctx->r9) < 0X79 ? 1 : 0;
    // 0x800729EC: bne         $at, $zero, L_80072ADC
    if (ctx->r1 != 0) {
        // 0x800729F0: sw          $t1, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r9;
            goto L_80072ADC;
    }
    // 0x800729F0: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x800729F4: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800729F8: lw          $a0, 0x4590($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4590);
    // 0x800729FC: jal         0x800CD7F0
    // 0x80072A00: addiu       $a1, $sp, 0x6D
    ctx->r5 = ADD32(ctx->r29, 0X6D);
    osPfsIsPlug_recomp(rdram, ctx);
        goto after_0;
    // 0x80072A00: addiu       $a1, $sp, 0x6D
    ctx->r5 = ADD32(ctx->r29, 0X6D);
    after_0:
    // 0x80072A04: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x80072A08: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80072A0C: addiu       $s4, $s4, 0x4767
    ctx->r20 = ADD32(ctx->r20, 0X4767);
    // 0x80072A10: addiu       $s6, $s6, 0x4598
    ctx->r22 = ADD32(ctx->r22, 0X4598);
    // 0x80072A14: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80072A18: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80072A1C: addiu       $s7, $zero, 0x68
    ctx->r23 = ADD32(0, 0X68);
L_80072A20:
    // 0x80072A20: lbu         $t3, 0x6D($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X6D);
    // 0x80072A24: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x80072A28: and         $t4, $t3, $v1
    ctx->r12 = ctx->r11 & ctx->r3;
    // 0x80072A2C: beq         $t4, $zero, L_80072ABC
    if (ctx->r12 == 0) {
        // 0x80072A30: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_80072ABC;
    }
    // 0x80072A30: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80072A34: lbu         $t5, 0x0($fp)
    ctx->r13 = MEM_BU(ctx->r30, 0X0);
    // 0x80072A38: lbu         $t7, 0x4765($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X4765);
    // 0x80072A3C: nor         $t6, $t5, $zero
    ctx->r14 = ~(ctx->r13 | 0);
    // 0x80072A40: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x80072A44: and         $t9, $t8, $v1
    ctx->r25 = ctx->r24 & ctx->r3;
    // 0x80072A48: bne         $t9, $zero, L_80072ABC
    if (ctx->r25 != 0) {
        // 0x80072A4C: nop
    
            goto L_80072ABC;
    }
    // 0x80072A4C: nop

    // 0x80072A50: multu       $s3, $s7
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80072A54: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80072A58: lw          $a0, 0x4590($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4590);
    // 0x80072A5C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80072A60: mflo        $t0
    ctx->r8 = lo;
    // 0x80072A64: addu        $a1, $s6, $t0
    ctx->r5 = ADD32(ctx->r22, ctx->r8);
    // 0x80072A68: jal         0x8007231C
    // 0x80072A6C: nop

    osMotorInit_recomp(rdram, ctx);
        goto after_1;
    // 0x80072A6C: nop

    after_1:
    // 0x80072A70: beq         $v0, $zero, L_80072AAC
    if (ctx->r2 == 0) {
        // 0x80072A74: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_80072AAC;
    }
    // 0x80072A74: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80072A78: lbu         $t1, 0x0($fp)
    ctx->r9 = MEM_BU(ctx->r30, 0X0);
    // 0x80072A7C: lbu         $t3, 0x0($s4)
    ctx->r11 = MEM_BU(ctx->r20, 0X0);
    // 0x80072A80: nor         $v0, $s1, $zero
    ctx->r2 = ~(ctx->r17 | 0);
    // 0x80072A84: and         $t2, $t1, $v0
    ctx->r10 = ctx->r9 & ctx->r2;
    // 0x80072A88: and         $t4, $t3, $v0
    ctx->r12 = ctx->r11 & ctx->r2;
    // 0x80072A8C: sb          $t2, 0x0($fp)
    MEM_B(0X0, ctx->r30) = ctx->r10;
    // 0x80072A90: sb          $t4, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r12;
    // 0x80072A94: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80072A98: lbu         $t5, 0x4765($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X4765);
    // 0x80072A9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80072AA0: and         $t6, $t5, $v0
    ctx->r14 = ctx->r13 & ctx->r2;
    // 0x80072AA4: b           L_80072ABC
    // 0x80072AA8: sb          $t6, 0x4765($at)
    MEM_B(0X4765, ctx->r1) = ctx->r14;
        goto L_80072ABC;
    // 0x80072AA8: sb          $t6, 0x4765($at)
    MEM_B(0X4765, ctx->r1) = ctx->r14;
L_80072AAC:
    // 0x80072AAC: lbu         $t7, 0x4765($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X4765);
    // 0x80072AB0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80072AB4: or          $t8, $t7, $s1
    ctx->r24 = ctx->r15 | ctx->r17;
    // 0x80072AB8: sb          $t8, 0x4765($at)
    MEM_B(0X4765, ctx->r1) = ctx->r24;
L_80072ABC:
    // 0x80072ABC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80072AC0: andi        $t9, $s3, 0xFF
    ctx->r25 = ctx->r19 & 0XFF;
    // 0x80072AC4: sll         $v1, $s1, 1
    ctx->r3 = S32(ctx->r17 << 1);
    // 0x80072AC8: andi        $t0, $v1, 0xFF
    ctx->r8 = ctx->r3 & 0XFF;
    // 0x80072ACC: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x80072AD0: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x80072AD4: bne         $at, $zero, L_80072A20
    if (ctx->r1 != 0) {
        // 0x80072AD8: or          $s3, $t9, $zero
        ctx->r19 = ctx->r25 | 0;
            goto L_80072A20;
    }
    // 0x80072AD8: or          $s3, $t9, $zero
    ctx->r19 = ctx->r25 | 0;
L_80072ADC:
    // 0x80072ADC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80072AE0: lbu         $t1, 0x4765($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X4765);
    // 0x80072AE4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80072AE8: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80072AEC: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x80072AF0: lw          $a0, -0x1604($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1604);
    // 0x80072AF4: addiu       $s6, $s6, 0x4598
    ctx->r22 = ADD32(ctx->r22, 0X4598);
    // 0x80072AF8: addiu       $s4, $s4, 0x4767
    ctx->r20 = ADD32(ctx->r20, 0X4767);
    // 0x80072AFC: bne         $t1, $zero, L_80072B0C
    if (ctx->r9 != 0) {
        // 0x80072B00: addiu       $s7, $zero, 0x68
        ctx->r23 = ADD32(0, 0X68);
            goto L_80072B0C;
    }
    // 0x80072B00: addiu       $s7, $zero, 0x68
    ctx->r23 = ADD32(0, 0X68);
    // 0x80072B04: beq         $a0, $zero, L_80072E70
    if (ctx->r4 == 0) {
        // 0x80072B08: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_80072E70;
    }
    // 0x80072B08: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_80072B0C:
    // 0x80072B0C: beq         $a0, $zero, L_80072B30
    if (ctx->r4 == 0) {
        // 0x80072B10: or          $s5, $zero, $zero
        ctx->r21 = 0 | 0;
            goto L_80072B30;
    }
    // 0x80072B10: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80072B14: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80072B18: lw          $a0, 0x4590($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4590);
    // 0x80072B1C: jal         0x800CD7F0
    // 0x80072B20: addiu       $a1, $sp, 0x6D
    ctx->r5 = ADD32(ctx->r29, 0X6D);
    osPfsIsPlug_recomp(rdram, ctx);
        goto after_2;
    // 0x80072B20: addiu       $a1, $sp, 0x6D
    ctx->r5 = ADD32(ctx->r29, 0X6D);
    after_2:
    // 0x80072B24: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80072B28: lw          $a0, -0x1604($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1604);
    // 0x80072B2C: nop

L_80072B30:
    // 0x80072B30: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80072B34: lwc1        $f23, 0x7D78($at)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r1, 0X7D78);
    // 0x80072B38: lwc1        $f22, 0x7D7C($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X7D7C);
    // 0x80072B3C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80072B40: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80072B44: lwc1        $f21, 0x7D80($at)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r1, 0X7D80);
    // 0x80072B48: lwc1        $f20, 0x7D84($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X7D84);
    // 0x80072B4C: addiu       $s0, $s0, 0x4738
    ctx->r16 = ADD32(ctx->r16, 0X4738);
    // 0x80072B50: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80072B54: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80072B58:
    // 0x80072B58: beq         $a0, $zero, L_80072BD8
    if (ctx->r4 == 0) {
        // 0x80072B5C: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_80072BD8;
    }
    // 0x80072B5C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80072B60: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80072B64: sh          $t2, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r10;
    // 0x80072B68: lh          $v0, 0x4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4);
    // 0x80072B6C: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x80072B70: sh          $v0, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r2;
    // 0x80072B74: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x80072B78: lbu         $t3, 0x6D($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X6D);
    // 0x80072B7C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80072B80: and         $t4, $t3, $v1
    ctx->r12 = ctx->r11 & ctx->r3;
    // 0x80072B84: bne         $t4, $zero, L_80072B98
    if (ctx->r12 != 0) {
        // 0x80072B88: nop
    
            goto L_80072B98;
    }
    // 0x80072B88: nop

    // 0x80072B8C: lw          $a0, -0x1604($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1604);
    // 0x80072B90: b           L_80072E30
    // 0x80072B94: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
        goto L_80072E30;
    // 0x80072B94: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_80072B98:
    // 0x80072B98: multu       $s3, $s7
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80072B9C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80072BA0: lw          $a0, 0x4590($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4590);
    // 0x80072BA4: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80072BA8: mflo        $t5
    ctx->r13 = lo;
    // 0x80072BAC: addu        $s2, $s6, $t5
    ctx->r18 = ADD32(ctx->r22, ctx->r13);
    // 0x80072BB0: jal         0x8007231C
    // 0x80072BB4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    osMotorInit_recomp(rdram, ctx);
        goto after_3;
    // 0x80072BB4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_3:
    // 0x80072BB8: bne         $v0, $zero, L_80072BC8
    if (ctx->r2 != 0) {
        // 0x80072BBC: nop
    
            goto L_80072BC8;
    }
    // 0x80072BBC: nop

    // 0x80072BC0: jal         0x80071F70
    // 0x80072BC4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    osMotorStop_recomp(rdram, ctx);
        goto after_4;
    // 0x80072BC4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
L_80072BC8:
    // 0x80072BC8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80072BCC: lw          $a0, -0x1604($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1604);
    // 0x80072BD0: b           L_80072E30
    // 0x80072BD4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
        goto L_80072E30;
    // 0x80072BD4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_80072BD8:
    // 0x80072BD8: lbu         $v0, 0x0($fp)
    ctx->r2 = MEM_BU(ctx->r30, 0X0);
    // 0x80072BDC: lbu         $t6, 0x4765($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X4765);
    // 0x80072BE0: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x80072BE4: and         $t7, $v0, $t6
    ctx->r15 = ctx->r2 & ctx->r14;
    // 0x80072BE8: and         $t8, $t7, $v1
    ctx->r24 = ctx->r15 & ctx->r3;
    // 0x80072BEC: beq         $t8, $zero, L_80072E2C
    if (ctx->r24 == 0) {
        // 0x80072BF0: nop
    
            goto L_80072E2C;
    }
    // 0x80072BF0: nop

    // 0x80072BF4: lh          $v1, 0x4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4);
    // 0x80072BF8: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x80072BFC: bgtz        $v1, L_80072C40
    if (SIGNED(ctx->r3) > 0) {
        // 0x80072C00: subu        $t4, $v1, $t3
        ctx->r12 = SUB32(ctx->r3, ctx->r11);
            goto L_80072C40;
    }
    // 0x80072C00: subu        $t4, $v1, $t3
    ctx->r12 = SUB32(ctx->r3, ctx->r11);
    // 0x80072C04: multu       $s3, $s7
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80072C08: nor         $t9, $s1, $zero
    ctx->r25 = ~(ctx->r17 | 0);
    // 0x80072C0C: and         $t0, $v0, $t9
    ctx->r8 = ctx->r2 & ctx->r25;
    // 0x80072C10: sb          $t0, 0x0($fp)
    MEM_B(0X0, ctx->r30) = ctx->r8;
    // 0x80072C14: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80072C18: sh          $t1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r9;
    // 0x80072C1C: sh          $zero, 0x8($s0)
    MEM_H(0X8, ctx->r16) = 0;
    // 0x80072C20: mflo        $t2
    ctx->r10 = lo;
    // 0x80072C24: addu        $a0, $s6, $t2
    ctx->r4 = ADD32(ctx->r22, ctx->r10);
    // 0x80072C28: jal         0x80071F70
    // 0x80072C2C: nop

    osMotorStop_recomp(rdram, ctx);
        goto after_5;
    // 0x80072C2C: nop

    after_5:
    // 0x80072C30: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80072C34: lw          $a0, -0x1604($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1604);
    // 0x80072C38: b           L_80072E30
    // 0x80072C3C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
        goto L_80072E30;
    // 0x80072C3C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_80072C40:
    // 0x80072C40: sh          $t4, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r12;
    // 0x80072C44: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x80072C48: lh          $t5, 0x8($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X8);
    // 0x80072C4C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80072C50: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80072C54: sh          $t7, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r15;
    // 0x80072C58: lh          $v0, 0x8($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X8);
    // 0x80072C5C: nop

    // 0x80072C60: bgez        $v0, L_80072C74
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80072C64: slti        $at, $v0, 0x259
        ctx->r1 = SIGNED(ctx->r2) < 0X259 ? 1 : 0;
            goto L_80072C74;
    }
    // 0x80072C64: slti        $at, $v0, 0x259
    ctx->r1 = SIGNED(ctx->r2) < 0X259 ? 1 : 0;
    // 0x80072C68: lw          $a0, -0x1604($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1604);
    // 0x80072C6C: b           L_80072E30
    // 0x80072C70: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
        goto L_80072E30;
    // 0x80072C70: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_80072C74:
    // 0x80072C74: bne         $at, $zero, L_80072CC0
    if (ctx->r1 != 0) {
        // 0x80072C78: nop
    
            goto L_80072CC0;
    }
    // 0x80072C78: nop

    // 0x80072C7C: multu       $s3, $s7
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80072C80: lbu         $t8, 0x0($fp)
    ctx->r24 = MEM_BU(ctx->r30, 0X0);
    // 0x80072C84: nor         $t9, $s1, $zero
    ctx->r25 = ~(ctx->r17 | 0);
    // 0x80072C88: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x80072C8C: sb          $t0, 0x0($fp)
    MEM_B(0X0, ctx->r30) = ctx->r8;
    // 0x80072C90: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80072C94: addiu       $t2, $zero, -0x12C
    ctx->r10 = ADD32(0, -0X12C);
    // 0x80072C98: sh          $t1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r9;
    // 0x80072C9C: sh          $t2, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r10;
    // 0x80072CA0: mflo        $t3
    ctx->r11 = lo;
    // 0x80072CA4: addu        $a0, $s6, $t3
    ctx->r4 = ADD32(ctx->r22, ctx->r11);
    // 0x80072CA8: jal         0x80071F70
    // 0x80072CAC: nop

    osMotorStop_recomp(rdram, ctx);
        goto after_6;
    // 0x80072CAC: nop

    after_6:
    // 0x80072CB0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80072CB4: lw          $a0, -0x1604($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1604);
    // 0x80072CB8: b           L_80072E30
    // 0x80072CBC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
        goto L_80072E30;
    // 0x80072CBC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_80072CC0:
    // 0x80072CC0: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    // 0x80072CC4: nop

    // 0x80072CC8: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x80072CCC: nop

    // 0x80072CD0: cvt.d.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.d = CVT_D_W(ctx->f4.u32l);
    // 0x80072CD4: c.lt.d      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.d < ctx->f0.d;
    // 0x80072CD8: nop

    // 0x80072CDC: bc1f        L_80072D20
    if (!c1cs) {
        // 0x80072CE0: nop
    
            goto L_80072D20;
    }
    // 0x80072CE0: nop

    // 0x80072CE4: lbu         $t4, 0x0($s4)
    ctx->r12 = MEM_BU(ctx->r20, 0X0);
    // 0x80072CE8: nop

    // 0x80072CEC: and         $t5, $t4, $s1
    ctx->r13 = ctx->r12 & ctx->r17;
    // 0x80072CF0: bne         $t5, $zero, L_80072E20
    if (ctx->r13 != 0) {
        // 0x80072CF4: nop
    
            goto L_80072E20;
    }
    // 0x80072CF4: nop

    // 0x80072CF8: multu       $s3, $s7
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80072CFC: mflo        $t6
    ctx->r14 = lo;
    // 0x80072D00: addu        $a0, $s6, $t6
    ctx->r4 = ADD32(ctx->r22, ctx->r14);
    // 0x80072D04: jal         0x80072098
    // 0x80072D08: nop

    osMotorStart_recomp(rdram, ctx);
        goto after_7;
    // 0x80072D08: nop

    after_7:
    // 0x80072D0C: lbu         $t7, 0x0($s4)
    ctx->r15 = MEM_BU(ctx->r20, 0X0);
    // 0x80072D10: or          $s5, $s5, $v0
    ctx->r21 = ctx->r21 | ctx->r2;
    // 0x80072D14: or          $t8, $t7, $s1
    ctx->r24 = ctx->r15 | ctx->r17;
    // 0x80072D18: b           L_80072E20
    // 0x80072D1C: sb          $t8, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r24;
        goto L_80072E20;
    // 0x80072D1C: sb          $t8, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r24;
L_80072D20:
    // 0x80072D20: c.lt.d      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.d < ctx->f22.d;
    // 0x80072D24: nop

    // 0x80072D28: bc1f        L_80072D70
    if (!c1cs) {
        // 0x80072D2C: nop
    
            goto L_80072D70;
    }
    // 0x80072D2C: nop

    // 0x80072D30: lbu         $t9, 0x0($s4)
    ctx->r25 = MEM_BU(ctx->r20, 0X0);
    // 0x80072D34: nop

    // 0x80072D38: and         $t0, $t9, $s1
    ctx->r8 = ctx->r25 & ctx->r17;
    // 0x80072D3C: beq         $t0, $zero, L_80072E20
    if (ctx->r8 == 0) {
        // 0x80072D40: nop
    
            goto L_80072E20;
    }
    // 0x80072D40: nop

    // 0x80072D44: multu       $s3, $s7
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80072D48: mflo        $t1
    ctx->r9 = lo;
    // 0x80072D4C: addu        $a0, $s6, $t1
    ctx->r4 = ADD32(ctx->r22, ctx->r9);
    // 0x80072D50: jal         0x80071F70
    // 0x80072D54: nop

    osMotorStop_recomp(rdram, ctx);
        goto after_8;
    // 0x80072D54: nop

    after_8:
    // 0x80072D58: lbu         $t2, 0x0($s4)
    ctx->r10 = MEM_BU(ctx->r20, 0X0);
    // 0x80072D5C: nor         $t3, $s1, $zero
    ctx->r11 = ~(ctx->r17 | 0);
    // 0x80072D60: and         $t4, $t2, $t3
    ctx->r12 = ctx->r10 & ctx->r11;
    // 0x80072D64: or          $s5, $s5, $v0
    ctx->r21 = ctx->r21 | ctx->r2;
    // 0x80072D68: b           L_80072E20
    // 0x80072D6C: sb          $t4, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r12;
        goto L_80072E20;
    // 0x80072D6C: sb          $t4, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r12;
L_80072D70:
    // 0x80072D70: lh          $v1, 0x6($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X6);
    // 0x80072D74: nop

    // 0x80072D78: slti        $at, $v1, 0x100
    ctx->r1 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80072D7C: bne         $at, $zero, L_80072DD0
    if (ctx->r1 != 0) {
        // 0x80072D80: nop
    
            goto L_80072DD0;
    }
    // 0x80072D80: nop

    // 0x80072D84: lbu         $t5, 0x0($s4)
    ctx->r13 = MEM_BU(ctx->r20, 0X0);
    // 0x80072D88: nop

    // 0x80072D8C: and         $t6, $t5, $s1
    ctx->r14 = ctx->r13 & ctx->r17;
    // 0x80072D90: bne         $t6, $zero, L_80072DC8
    if (ctx->r14 != 0) {
        // 0x80072D94: addiu       $t0, $v1, -0x100
        ctx->r8 = ADD32(ctx->r3, -0X100);
            goto L_80072DC8;
    }
    // 0x80072D94: addiu       $t0, $v1, -0x100
    ctx->r8 = ADD32(ctx->r3, -0X100);
    // 0x80072D98: multu       $s3, $s7
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80072D9C: mflo        $t7
    ctx->r15 = lo;
    // 0x80072DA0: addu        $a0, $s6, $t7
    ctx->r4 = ADD32(ctx->r22, ctx->r15);
    // 0x80072DA4: jal         0x80072098
    // 0x80072DA8: nop

    osMotorStart_recomp(rdram, ctx);
        goto after_9;
    // 0x80072DA8: nop

    after_9:
    // 0x80072DAC: lbu         $t8, 0x0($s4)
    ctx->r24 = MEM_BU(ctx->r20, 0X0);
    // 0x80072DB0: or          $s5, $s5, $v0
    ctx->r21 = ctx->r21 | ctx->r2;
    // 0x80072DB4: or          $t9, $t8, $s1
    ctx->r25 = ctx->r24 | ctx->r17;
    // 0x80072DB8: sb          $t9, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r25;
    // 0x80072DBC: lh          $v1, 0x6($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X6);
    // 0x80072DC0: nop

    // 0x80072DC4: addiu       $t0, $v1, -0x100
    ctx->r8 = ADD32(ctx->r3, -0X100);
L_80072DC8:
    // 0x80072DC8: b           L_80072E20
    // 0x80072DCC: sh          $t0, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r8;
        goto L_80072E20;
    // 0x80072DCC: sh          $t0, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r8;
L_80072DD0:
    // 0x80072DD0: lbu         $t1, 0x0($s4)
    ctx->r9 = MEM_BU(ctx->r20, 0X0);
    // 0x80072DD4: nop

    // 0x80072DD8: and         $t2, $t1, $s1
    ctx->r10 = ctx->r9 & ctx->r17;
    // 0x80072DDC: beq         $t2, $zero, L_80072E18
    if (ctx->r10 == 0) {
        // 0x80072DE0: addu        $t7, $v1, $a0
        ctx->r15 = ADD32(ctx->r3, ctx->r4);
            goto L_80072E18;
    }
    // 0x80072DE0: addu        $t7, $v1, $a0
    ctx->r15 = ADD32(ctx->r3, ctx->r4);
    // 0x80072DE4: multu       $s3, $s7
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80072DE8: mflo        $t3
    ctx->r11 = lo;
    // 0x80072DEC: addu        $a0, $s6, $t3
    ctx->r4 = ADD32(ctx->r22, ctx->r11);
    // 0x80072DF0: jal         0x80071F70
    // 0x80072DF4: nop

    osMotorStop_recomp(rdram, ctx);
        goto after_10;
    // 0x80072DF4: nop

    after_10:
    // 0x80072DF8: lbu         $t4, 0x0($s4)
    ctx->r12 = MEM_BU(ctx->r20, 0X0);
    // 0x80072DFC: nor         $t5, $s1, $zero
    ctx->r13 = ~(ctx->r17 | 0);
    // 0x80072E00: and         $t6, $t4, $t5
    ctx->r14 = ctx->r12 & ctx->r13;
    // 0x80072E04: sb          $t6, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r14;
    // 0x80072E08: lh          $v1, 0x6($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X6);
    // 0x80072E0C: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    // 0x80072E10: or          $s5, $s5, $v0
    ctx->r21 = ctx->r21 | ctx->r2;
    // 0x80072E14: addu        $t7, $v1, $a0
    ctx->r15 = ADD32(ctx->r3, ctx->r4);
L_80072E18:
    // 0x80072E18: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x80072E1C: sh          $t8, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r24;
L_80072E20:
    // 0x80072E20: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80072E24: lw          $a0, -0x1604($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1604);
    // 0x80072E28: nop

L_80072E2C:
    // 0x80072E2C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_80072E30:
    // 0x80072E30: andi        $t9, $s3, 0xFF
    ctx->r25 = ctx->r19 & 0XFF;
    // 0x80072E34: sll         $v1, $s1, 1
    ctx->r3 = S32(ctx->r17 << 1);
    // 0x80072E38: andi        $t0, $v1, 0xFF
    ctx->r8 = ctx->r3 & 0XFF;
    // 0x80072E3C: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x80072E40: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x80072E44: or          $s3, $t9, $zero
    ctx->r19 = ctx->r25 | 0;
    // 0x80072E48: bne         $at, $zero, L_80072B58
    if (ctx->r1 != 0) {
        // 0x80072E4C: addiu       $s0, $s0, 0xA
        ctx->r16 = ADD32(ctx->r16, 0XA);
            goto L_80072B58;
    }
    // 0x80072E4C: addiu       $s0, $s0, 0xA
    ctx->r16 = ADD32(ctx->r16, 0XA);
    // 0x80072E50: beq         $s5, $zero, L_80072E5C
    if (ctx->r21 == 0) {
        // 0x80072E54: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80072E5C;
    }
    // 0x80072E54: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80072E58: sb          $zero, 0x4765($at)
    MEM_B(0X4765, ctx->r1) = 0;
L_80072E5C:
    // 0x80072E5C: beq         $a0, $zero, L_80072E6C
    if (ctx->r4 == 0) {
        // 0x80072E60: addiu       $t1, $a0, -0x1
        ctx->r9 = ADD32(ctx->r4, -0X1);
            goto L_80072E6C;
    }
    // 0x80072E60: addiu       $t1, $a0, -0x1
    ctx->r9 = ADD32(ctx->r4, -0X1);
    // 0x80072E64: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80072E68: sw          $t1, -0x1604($at)
    MEM_W(-0X1604, ctx->r1) = ctx->r9;
L_80072E6C:
    // 0x80072E6C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_80072E70:
    // 0x80072E70: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80072E74: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80072E78: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80072E7C: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80072E80: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80072E84: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80072E88: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80072E8C: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80072E90: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80072E94: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80072E98: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80072E9C: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x80072EA0: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x80072EA4: jr          $ra
    // 0x80072EA8: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80072EA8: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_80072C54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072EAC: bgtz        $a0, L_80072EBC
    if (SIGNED(ctx->r4) > 0) {
        // 0x80072EB0: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80072EBC;
    }
    // 0x80072EB0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80072EB4: jr          $ra
    // 0x80072EB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80072EB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80072EBC:
    // 0x80072EBC: addiu       $t6, $a0, 0x1F
    ctx->r14 = ADD32(ctx->r4, 0X1F);
    // 0x80072EC0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80072EC4: beq         $a0, $zero, L_80073074
    if (ctx->r4 == 0) {
        // 0x80072EC8: sllv        $v0, $t7, $t6
        ctx->r2 = S32(ctx->r15 << (ctx->r14 & 31));
            goto L_80073074;
    }
    // 0x80072EC8: sllv        $v0, $t7, $t6
    ctx->r2 = S32(ctx->r15 << (ctx->r14 & 31));
    // 0x80072ECC: andi        $a1, $a0, 0x3
    ctx->r5 = ctx->r4 & 0X3;
    // 0x80072ED0: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    // 0x80072ED4: beq         $a1, $zero, L_80072F4C
    if (ctx->r5 == 0) {
        // 0x80072ED8: addu        $t0, $a1, $a0
        ctx->r8 = ADD32(ctx->r5, ctx->r4);
            goto L_80072F4C;
    }
    // 0x80072ED8: addu        $t0, $a1, $a0
    ctx->r8 = ADD32(ctx->r5, ctx->r4);
    // 0x80072EDC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80072EE0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80072EE4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80072EE8: addiu       $t1, $t1, 0x4774
    ctx->r9 = ADD32(ctx->r9, 0X4774);
    // 0x80072EEC: addiu       $t2, $t2, 0x4770
    ctx->r10 = ADD32(ctx->r10, 0X4770);
    // 0x80072EF0: addiu       $t3, $t3, 0x476C
    ctx->r11 = ADD32(ctx->r11, 0X476C);
    // 0x80072EF4: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
L_80072EF8:
    // 0x80072EF8: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x80072EFC: addiu       $a1, $a0, -0x1
    ctx->r5 = ADD32(ctx->r4, -0X1);
    // 0x80072F00: bne         $a2, $zero, L_80072F24
    if (ctx->r6 != 0) {
        // 0x80072F04: srl         $t6, $v0, 1
        ctx->r14 = S32(U32(ctx->r2) >> 1);
            goto L_80072F24;
    }
    // 0x80072F04: srl         $t6, $v0, 1
    ctx->r14 = S32(U32(ctx->r2) >> 1);
    // 0x80072F08: lw          $a3, 0x0($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X0);
    // 0x80072F0C: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x80072F10: lbu         $t8, 0x0($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X0);
    // 0x80072F14: addiu       $t9, $a3, 0x1
    ctx->r25 = ADD32(ctx->r7, 0X1);
    // 0x80072F18: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80072F1C: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x80072F20: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
L_80072F24:
    // 0x80072F24: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x80072F28: srl         $t8, $a2, 1
    ctx->r24 = S32(U32(ctx->r6) >> 1);
    // 0x80072F2C: and         $t7, $t5, $a2
    ctx->r15 = ctx->r13 & ctx->r6;
    // 0x80072F30: beq         $t7, $zero, L_80072F3C
    if (ctx->r15 == 0) {
        // 0x80072F34: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80072F3C;
    }
    // 0x80072F34: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80072F38: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_80072F3C:
    // 0x80072F3C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80072F40: bne         $t0, $a1, L_80072EF8
    if (ctx->r8 != ctx->r5) {
        // 0x80072F44: sw          $t8, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r24;
            goto L_80072EF8;
    }
    // 0x80072F44: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x80072F48: beq         $a1, $zero, L_80073074
    if (ctx->r5 == 0) {
        // 0x80072F4C: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_80073074;
    }
L_80072F4C:
    // 0x80072F4C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80072F50: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80072F54: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80072F58: addiu       $t3, $t3, 0x476C
    ctx->r11 = ADD32(ctx->r11, 0X476C);
    // 0x80072F5C: addiu       $t2, $t2, 0x4770
    ctx->r10 = ADD32(ctx->r10, 0X4770);
    // 0x80072F60: addiu       $t1, $t1, 0x4774
    ctx->r9 = ADD32(ctx->r9, 0X4774);
    // 0x80072F64: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
L_80072F68:
    // 0x80072F68: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x80072F6C: srl         $t6, $v0, 1
    ctx->r14 = S32(U32(ctx->r2) >> 1);
    // 0x80072F70: bne         $a2, $zero, L_80072F94
    if (ctx->r6 != 0) {
        // 0x80072F74: addiu       $a0, $a0, -0x4
        ctx->r4 = ADD32(ctx->r4, -0X4);
            goto L_80072F94;
    }
    // 0x80072F74: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x80072F78: lw          $a3, 0x0($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X0);
    // 0x80072F7C: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x80072F80: lbu         $t9, 0x0($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X0);
    // 0x80072F84: addiu       $t5, $a3, 0x1
    ctx->r13 = ADD32(ctx->r7, 0X1);
    // 0x80072F88: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x80072F8C: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x80072F90: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
L_80072F94:
    // 0x80072F94: lw          $a1, 0x0($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X0);
    // 0x80072F98: srl         $t8, $a2, 1
    ctx->r24 = S32(U32(ctx->r6) >> 1);
    // 0x80072F9C: and         $t7, $a1, $a2
    ctx->r15 = ctx->r5 & ctx->r6;
    // 0x80072FA0: beq         $t7, $zero, L_80072FAC
    if (ctx->r15 == 0) {
        // 0x80072FA4: or          $a2, $t8, $zero
        ctx->r6 = ctx->r24 | 0;
            goto L_80072FAC;
    }
    // 0x80072FA4: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x80072FA8: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_80072FAC:
    // 0x80072FAC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80072FB0: bne         $t8, $zero, L_80072FD4
    if (ctx->r24 != 0) {
        // 0x80072FB4: sw          $t8, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r24;
            goto L_80072FD4;
    }
    // 0x80072FB4: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x80072FB8: lw          $a3, 0x0($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X0);
    // 0x80072FBC: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x80072FC0: lbu         $a1, 0x0($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X0);
    // 0x80072FC4: addiu       $t5, $a3, 0x1
    ctx->r13 = ADD32(ctx->r7, 0X1);
    // 0x80072FC8: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x80072FCC: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x80072FD0: sw          $a1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r5;
L_80072FD4:
    // 0x80072FD4: and         $t7, $a1, $a2
    ctx->r15 = ctx->r5 & ctx->r6;
    // 0x80072FD8: beq         $t7, $zero, L_80072FE4
    if (ctx->r15 == 0) {
        // 0x80072FDC: srl         $t6, $v0, 1
        ctx->r14 = S32(U32(ctx->r2) >> 1);
            goto L_80072FE4;
    }
    // 0x80072FDC: srl         $t6, $v0, 1
    ctx->r14 = S32(U32(ctx->r2) >> 1);
    // 0x80072FE0: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_80072FE4:
    // 0x80072FE4: srl         $t8, $a2, 1
    ctx->r24 = S32(U32(ctx->r6) >> 1);
    // 0x80072FE8: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x80072FEC: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x80072FF0: bne         $t8, $zero, L_80073014
    if (ctx->r24 != 0) {
        // 0x80072FF4: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80073014;
    }
    // 0x80072FF4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80072FF8: lw          $a3, 0x0($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X0);
    // 0x80072FFC: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x80073000: lbu         $a1, 0x0($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X0);
    // 0x80073004: addiu       $t5, $a3, 0x1
    ctx->r13 = ADD32(ctx->r7, 0X1);
    // 0x80073008: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x8007300C: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x80073010: sw          $a1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r5;
L_80073014:
    // 0x80073014: and         $t7, $a1, $a2
    ctx->r15 = ctx->r5 & ctx->r6;
    // 0x80073018: beq         $t7, $zero, L_80073024
    if (ctx->r15 == 0) {
        // 0x8007301C: srl         $t6, $v0, 1
        ctx->r14 = S32(U32(ctx->r2) >> 1);
            goto L_80073024;
    }
    // 0x8007301C: srl         $t6, $v0, 1
    ctx->r14 = S32(U32(ctx->r2) >> 1);
    // 0x80073020: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_80073024:
    // 0x80073024: srl         $t8, $a2, 1
    ctx->r24 = S32(U32(ctx->r6) >> 1);
    // 0x80073028: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8007302C: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x80073030: bne         $t8, $zero, L_80073054
    if (ctx->r24 != 0) {
        // 0x80073034: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80073054;
    }
    // 0x80073034: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80073038: lw          $a3, 0x0($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X0);
    // 0x8007303C: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x80073040: lbu         $a1, 0x0($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X0);
    // 0x80073044: addiu       $t5, $a3, 0x1
    ctx->r13 = ADD32(ctx->r7, 0X1);
    // 0x80073048: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x8007304C: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x80073050: sw          $a1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r5;
L_80073054:
    // 0x80073054: and         $t7, $a1, $a2
    ctx->r15 = ctx->r5 & ctx->r6;
    // 0x80073058: beq         $t7, $zero, L_80073064
    if (ctx->r15 == 0) {
        // 0x8007305C: srl         $t6, $v0, 1
        ctx->r14 = S32(U32(ctx->r2) >> 1);
            goto L_80073064;
    }
    // 0x8007305C: srl         $t6, $v0, 1
    ctx->r14 = S32(U32(ctx->r2) >> 1);
    // 0x80073060: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_80073064:
    // 0x80073064: srl         $t8, $a2, 1
    ctx->r24 = S32(U32(ctx->r6) >> 1);
    // 0x80073068: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8007306C: bne         $a0, $zero, L_80072F68
    if (ctx->r4 != 0) {
        // 0x80073070: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80072F68;
    }
    // 0x80073070: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_80073074:
    // 0x80073074: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80073078: jr          $ra
    // 0x8007307C: nop

    return;
    // 0x8007307C: nop

;}
RECOMP_FUNC void func_80072E28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073080: blez        $a0, L_800732BC
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80073084: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_800732BC;
    }
    // 0x80073084: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80073088: addiu       $t6, $a0, 0x1F
    ctx->r14 = ADD32(ctx->r4, 0X1F);
    // 0x8007308C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80073090: beq         $a0, $zero, L_8007329C
    if (ctx->r4 == 0) {
        // 0x80073094: sllv        $v0, $t7, $t6
        ctx->r2 = S32(ctx->r15 << (ctx->r14 & 31));
            goto L_8007329C;
    }
    // 0x80073094: sllv        $v0, $t7, $t6
    ctx->r2 = S32(ctx->r15 << (ctx->r14 & 31));
    // 0x80073098: andi        $v1, $a0, 0x3
    ctx->r3 = ctx->r4 & 0X3;
    // 0x8007309C: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // 0x800730A0: beq         $v1, $zero, L_80073128
    if (ctx->r3 == 0) {
        // 0x800730A4: addu        $a3, $v1, $a0
        ctx->r7 = ADD32(ctx->r3, ctx->r4);
            goto L_80073128;
    }
    // 0x800730A4: addu        $a3, $v1, $a0
    ctx->r7 = ADD32(ctx->r3, ctx->r4);
    // 0x800730A8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800730AC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800730B0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800730B4: addiu       $t0, $t0, 0x4774
    ctx->r8 = ADD32(ctx->r8, 0X4774);
    // 0x800730B8: addiu       $t1, $t1, 0x476C
    ctx->r9 = ADD32(ctx->r9, 0X476C);
    // 0x800730BC: addiu       $t2, $t2, 0x4770
    ctx->r10 = ADD32(ctx->r10, 0X4770);
    // 0x800730C0: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
L_800730C4:
    // 0x800730C4: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x800730C8: addiu       $v1, $a0, -0x1
    ctx->r3 = ADD32(ctx->r4, -0X1);
    // 0x800730CC: bne         $a1, $zero, L_800730F8
    if (ctx->r5 != 0) {
        // 0x800730D0: and         $t7, $a2, $v0
        ctx->r15 = ctx->r6 & ctx->r2;
            goto L_800730F8;
    }
    // 0x800730D0: and         $t7, $a2, $v0
    ctx->r15 = ctx->r6 & ctx->r2;
    // 0x800730D4: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x800730D8: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800730DC: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x800730E0: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x800730E4: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800730E8: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x800730EC: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800730F0: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x800730F4: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
L_800730F8:
    // 0x800730F8: beq         $t7, $zero, L_80073110
    if (ctx->r15 == 0) {
        // 0x800730FC: srl         $t9, $v0, 1
        ctx->r25 = S32(U32(ctx->r2) >> 1);
            goto L_80073110;
    }
    // 0x800730FC: srl         $t9, $v0, 1
    ctx->r25 = S32(U32(ctx->r2) >> 1);
    // 0x80073100: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x80073104: nop

    // 0x80073108: or          $t8, $t6, $a1
    ctx->r24 = ctx->r14 | ctx->r5;
    // 0x8007310C: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
L_80073110:
    // 0x80073110: srl         $t4, $a1, 1
    ctx->r12 = S32(U32(ctx->r5) >> 1);
    // 0x80073114: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x80073118: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8007311C: bne         $a3, $v1, L_800730C4
    if (ctx->r7 != ctx->r3) {
        // 0x80073120: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_800730C4;
    }
    // 0x80073120: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80073124: beq         $v1, $zero, L_8007329C
    if (ctx->r3 == 0) {
        // 0x80073128: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_8007329C;
    }
L_80073128:
    // 0x80073128: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8007312C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80073130: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80073134: addiu       $t2, $t2, 0x4770
    ctx->r10 = ADD32(ctx->r10, 0X4770);
    // 0x80073138: addiu       $t1, $t1, 0x476C
    ctx->r9 = ADD32(ctx->r9, 0X476C);
    // 0x8007313C: addiu       $t0, $t0, 0x4774
    ctx->r8 = ADD32(ctx->r8, 0X4774);
    // 0x80073140: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
L_80073144:
    // 0x80073144: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x80073148: and         $t9, $a2, $v0
    ctx->r25 = ctx->r6 & ctx->r2;
    // 0x8007314C: bne         $a1, $zero, L_80073178
    if (ctx->r5 != 0) {
        // 0x80073150: addiu       $a0, $a0, -0x4
        ctx->r4 = ADD32(ctx->r4, -0X4);
            goto L_80073178;
    }
    // 0x80073150: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x80073154: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x80073158: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x8007315C: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x80073160: sb          $t5, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r13;
    // 0x80073164: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x80073168: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
    // 0x8007316C: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x80073170: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x80073174: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
L_80073178:
    // 0x80073178: beq         $t9, $zero, L_80073190
    if (ctx->r25 == 0) {
        // 0x8007317C: srl         $t7, $v0, 1
        ctx->r15 = S32(U32(ctx->r2) >> 1);
            goto L_80073190;
    }
    // 0x8007317C: srl         $t7, $v0, 1
    ctx->r15 = S32(U32(ctx->r2) >> 1);
    // 0x80073180: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80073184: nop

    // 0x80073188: or          $t5, $t4, $a1
    ctx->r13 = ctx->r12 | ctx->r5;
    // 0x8007318C: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
L_80073190:
    // 0x80073190: srl         $t6, $a1, 1
    ctx->r14 = S32(U32(ctx->r5) >> 1);
    // 0x80073194: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80073198: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x8007319C: bne         $t6, $zero, L_800731C8
    if (ctx->r14 != 0) {
        // 0x800731A0: or          $a1, $t6, $zero
        ctx->r5 = ctx->r14 | 0;
            goto L_800731C8;
    }
    // 0x800731A0: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800731A4: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x800731A8: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800731AC: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x800731B0: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x800731B4: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800731B8: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x800731BC: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800731C0: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x800731C4: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
L_800731C8:
    // 0x800731C8: and         $t7, $a2, $v0
    ctx->r15 = ctx->r6 & ctx->r2;
    // 0x800731CC: beq         $t7, $zero, L_800731E4
    if (ctx->r15 == 0) {
        // 0x800731D0: srl         $t9, $v0, 1
        ctx->r25 = S32(U32(ctx->r2) >> 1);
            goto L_800731E4;
    }
    // 0x800731D0: srl         $t9, $v0, 1
    ctx->r25 = S32(U32(ctx->r2) >> 1);
    // 0x800731D4: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x800731D8: nop

    // 0x800731DC: or          $t8, $t6, $a1
    ctx->r24 = ctx->r14 | ctx->r5;
    // 0x800731E0: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
L_800731E4:
    // 0x800731E4: srl         $t4, $a1, 1
    ctx->r12 = S32(U32(ctx->r5) >> 1);
    // 0x800731E8: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x800731EC: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    // 0x800731F0: bne         $t4, $zero, L_8007321C
    if (ctx->r12 != 0) {
        // 0x800731F4: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_8007321C;
    }
    // 0x800731F4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x800731F8: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x800731FC: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x80073200: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x80073204: sb          $t5, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r13;
    // 0x80073208: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x8007320C: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80073210: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x80073214: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x80073218: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
L_8007321C:
    // 0x8007321C: and         $t9, $a2, $v0
    ctx->r25 = ctx->r6 & ctx->r2;
    // 0x80073220: beq         $t9, $zero, L_80073238
    if (ctx->r25 == 0) {
        // 0x80073224: srl         $t7, $v0, 1
        ctx->r15 = S32(U32(ctx->r2) >> 1);
            goto L_80073238;
    }
    // 0x80073224: srl         $t7, $v0, 1
    ctx->r15 = S32(U32(ctx->r2) >> 1);
    // 0x80073228: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x8007322C: nop

    // 0x80073230: or          $t5, $t4, $a1
    ctx->r13 = ctx->r12 | ctx->r5;
    // 0x80073234: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
L_80073238:
    // 0x80073238: srl         $t6, $a1, 1
    ctx->r14 = S32(U32(ctx->r5) >> 1);
    // 0x8007323C: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x80073240: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80073244: bne         $t6, $zero, L_80073270
    if (ctx->r14 != 0) {
        // 0x80073248: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_80073270;
    }
    // 0x80073248: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007324C: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x80073250: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x80073254: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x80073258: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x8007325C: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80073260: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80073264: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80073268: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x8007326C: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
L_80073270:
    // 0x80073270: and         $t7, $a2, $v0
    ctx->r15 = ctx->r6 & ctx->r2;
    // 0x80073274: beq         $t7, $zero, L_8007328C
    if (ctx->r15 == 0) {
        // 0x80073278: srl         $t9, $v0, 1
        ctx->r25 = S32(U32(ctx->r2) >> 1);
            goto L_8007328C;
    }
    // 0x80073278: srl         $t9, $v0, 1
    ctx->r25 = S32(U32(ctx->r2) >> 1);
    // 0x8007327C: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x80073280: nop

    // 0x80073284: or          $t8, $t6, $a1
    ctx->r24 = ctx->r14 | ctx->r5;
    // 0x80073288: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
L_8007328C:
    // 0x8007328C: srl         $t4, $a1, 1
    ctx->r12 = S32(U32(ctx->r5) >> 1);
    // 0x80073290: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x80073294: bne         $a0, $zero, L_80073144
    if (ctx->r4 != 0) {
        // 0x80073298: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_80073144;
    }
    // 0x80073298: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8007329C:
    // 0x8007329C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800732A0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800732A4: addiu       $t2, $t2, 0x4770
    ctx->r10 = ADD32(ctx->r10, 0X4770);
    // 0x800732A8: addiu       $t1, $t1, 0x476C
    ctx->r9 = ADD32(ctx->r9, 0X476C);
    // 0x800732AC: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800732B0: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x800732B4: nop

    // 0x800732B8: sb          $t5, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r13;
L_800732BC:
    // 0x800732BC: jr          $ra
    // 0x800732C0: nop

    return;
    // 0x800732C0: nop

;}
