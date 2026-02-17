#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void video_delta_reset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007ADC4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007ADC8: sb          $zero, 0x68A8($at)
    MEM_B(0X68A8, ctx->r1) = 0;
    // 0x8007ADCC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007ADD0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8007ADD4: jr          $ra
    // 0x8007ADD8: sb          $t6, 0x68A9($at)
    MEM_B(0X68A9, ctx->r1) = ctx->r14;
    return;
    // 0x8007ADD8: sb          $t6, 0x68A9($at)
    MEM_B(0X68A9, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void fb_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007ADDC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8007ADE0: addiu       $v1, $v1, 0x6870
    ctx->r3 = ADD32(ctx->r3, 0X6870);
    // 0x8007ADE4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8007ADE8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8007ADEC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8007ADF0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007ADF4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8007ADF8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007ADFC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8007AE00: beq         $v0, $zero, L_8007AE1C
    if (ctx->r2 == 0) {
        // 0x8007AE04: addiu       $s0, $zero, 0x1
        ctx->r16 = ADD32(0, 0X1);
            goto L_8007AE1C;
    }
    // 0x8007AE04: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x8007AE08: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8007AE0C: bne         $t6, $zero, L_8007AE1C
    if (ctx->r14 != 0) {
        // 0x8007AE10: sw          $t6, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r14;
            goto L_8007AE1C;
    }
    // 0x8007AE10: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8007AE14: jal         0x800D2270
    // 0x8007AE18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    osViBlack_recomp(rdram, ctx);
        goto after_0;
    // 0x8007AE18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
L_8007AE1C:
    // 0x8007AE1C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8007AE20: beq         $s1, $at, L_8007AE30
    if (ctx->r17 == ctx->r1) {
        // 0x8007AE24: nop
    
            goto L_8007AE30;
    }
    // 0x8007AE24: nop

    // 0x8007AE28: jal         0x8007AFEC
    // 0x8007AE2C: nop

    fb_swap(rdram, ctx);
        goto after_1;
    // 0x8007AE2C: nop

    after_1:
L_8007AE30:
    // 0x8007AE30: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8007AE34: addiu       $s2, $s2, 0x6740
    ctx->r18 = ADD32(ctx->r18, 0X6740);
    // 0x8007AE38: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8007AE3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8007AE40: jal         0x800C9110
    // 0x8007AE44: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x8007AE44: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8007AE48: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x8007AE4C: beq         $v0, $s1, L_8007AE78
    if (ctx->r2 == ctx->r17) {
        // 0x8007AE50: nop
    
            goto L_8007AE78;
    }
    // 0x8007AE50: nop

L_8007AE54:
    // 0x8007AE54: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007AE58: andi        $t8, $s0, 0xFF
    ctx->r24 = ctx->r16 & 0XFF;
    // 0x8007AE5C: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x8007AE60: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8007AE64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8007AE68: jal         0x800C9110
    // 0x8007AE6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x8007AE6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x8007AE70: bne         $v0, $s1, L_8007AE54
    if (ctx->r2 != ctx->r17) {
        // 0x8007AE74: nop
    
            goto L_8007AE54;
    }
    // 0x8007AE74: nop

L_8007AE78:
    // 0x8007AE78: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8007AE7C: addiu       $s1, $s1, 0x68A9
    ctx->r17 = ADD32(ctx->r17, 0X68A9);
    // 0x8007AE80: lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X0);
    // 0x8007AE84: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8007AE88: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8007AE8C: beq         $at, $zero, L_8007AED8
    if (ctx->r1 == 0) {
        // 0x8007AE90: lui         $a2, 0x8012
        ctx->r6 = S32(0X8012 << 16);
            goto L_8007AED8;
    }
    // 0x8007AE90: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8007AE94: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8007AE98: addiu       $a2, $a2, 0x68A8
    ctx->r6 = ADD32(ctx->r6, 0X68A8);
    // 0x8007AE9C: lbu         $a1, 0x0($a2)
    ctx->r5 = MEM_BU(ctx->r6, 0X0);
    // 0x8007AEA0: nop

    // 0x8007AEA4: slti        $at, $a1, 0x14
    ctx->r1 = SIGNED(ctx->r5) < 0X14 ? 1 : 0;
    // 0x8007AEA8: beq         $at, $zero, L_8007AEBC
    if (ctx->r1 == 0) {
        // 0x8007AEAC: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_8007AEBC;
    }
    // 0x8007AEAC: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8007AEB0: addiu       $t9, $a1, 0x1
    ctx->r25 = ADD32(ctx->r5, 0X1);
    // 0x8007AEB4: sb          $t9, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r25;
    // 0x8007AEB8: andi        $v0, $t9, 0xFF
    ctx->r2 = ctx->r25 & 0XFF;
L_8007AEBC:
    // 0x8007AEBC: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x8007AEC0: bne         $v0, $at, L_8007AF0C
    if (ctx->r2 != ctx->r1) {
        // 0x8007AEC4: slt         $at, $v1, $a0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8007AF0C;
    }
    // 0x8007AEC4: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8007AEC8: sb          $s0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r16;
    // 0x8007AECC: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
    // 0x8007AED0: b           L_8007AF08
    // 0x8007AED4: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
        goto L_8007AF08;
    // 0x8007AED4: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
L_8007AED8:
    // 0x8007AED8: addiu       $a2, $a2, 0x68A8
    ctx->r6 = ADD32(ctx->r6, 0X68A8);
    // 0x8007AEDC: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8007AEE0: beq         $at, $zero, L_8007AF08
    if (ctx->r1 == 0) {
        // 0x8007AEE4: sb          $zero, 0x0($a2)
        MEM_B(0X0, ctx->r6) = 0;
            goto L_8007AF08;
    }
    // 0x8007AEE4: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
    // 0x8007AEE8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8007AEEC: lbu         $t0, 0x6884($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X6884);
    // 0x8007AEF0: nop

    // 0x8007AEF4: slt         $at, $t0, $v1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8007AEF8: bne         $at, $zero, L_8007AF0C
    if (ctx->r1 != 0) {
        // 0x8007AEFC: slt         $at, $v1, $a0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8007AF0C;
    }
    // 0x8007AEFC: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8007AF00: sb          $s0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r16;
    // 0x8007AF04: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
L_8007AF08:
    // 0x8007AF08: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
L_8007AF0C:
    // 0x8007AF0C: beq         $at, $zero, L_8007AF38
    if (ctx->r1 == 0) {
        // 0x8007AF10: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8007AF38;
    }
L_8007AF10:
    // 0x8007AF10: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8007AF14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8007AF18: jal         0x800C9110
    // 0x8007AF1C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x8007AF1C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x8007AF20: lbu         $t2, 0x0($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X0);
    // 0x8007AF24: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007AF28: andi        $v1, $s0, 0xFF
    ctx->r3 = ctx->r16 & 0XFF;
    // 0x8007AF2C: slt         $at, $v1, $t2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8007AF30: bne         $at, $zero, L_8007AF10
    if (ctx->r1 != 0) {
        // 0x8007AF34: or          $s0, $v1, $zero
        ctx->r16 = ctx->r3 | 0;
            goto L_8007AF10;
    }
    // 0x8007AF34: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
L_8007AF38:
    // 0x8007AF38: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007AF3C: lw          $a0, 0x6878($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6878);
    // 0x8007AF40: jal         0x800D2980
    // 0x8007AF44: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    osViSwapBuffer_recomp(rdram, ctx);
        goto after_5;
    // 0x8007AF44: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_5:
    // 0x8007AF48: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8007AF4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8007AF50: jal         0x800C9110
    // 0x8007AF54: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_6;
    // 0x8007AF54: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x8007AF58: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8007AF5C: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8007AF60: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007AF64: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8007AF68: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8007AF6C: jr          $ra
    // 0x8007AF70: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8007AF70: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8007AB24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007AF74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007AF78: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8007AF7C: jr          $ra
    // 0x8007AF80: sb          $a0, 0x6884($at)
    MEM_B(0X6884, ctx->r1) = ctx->r4;
    return;
    // 0x8007AF80: sb          $a0, 0x6884($at)
    MEM_B(0X6884, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void vi_refresh_rate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007AF84: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007AF88: lw          $t6, 0x6710($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6710);
    // 0x8007AF8C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8007AF90: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8007AF94: lbu         $t7, 0x68A9($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X68A9);
    // 0x8007AF98: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8007AF9C: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8007AFA0: bgez        $t7, L_8007AFB8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8007AFA4: cvt.s.w     $f10, $f18
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
            goto L_8007AFB8;
    }
    // 0x8007AFA4: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8007AFA8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8007AFAC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8007AFB0: nop

    // 0x8007AFB4: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_8007AFB8:
    // 0x8007AFB8: nop

    // 0x8007AFBC: div.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8007AFC0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8007AFC4: nop

    // 0x8007AFC8: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8007AFCC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8007AFD0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007AFD4: nop

    // 0x8007AFD8: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8007AFDC: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x8007AFE0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8007AFE4: jr          $ra
    // 0x8007AFE8: nop

    return;
    // 0x8007AFE8: nop

;}
RECOMP_FUNC void fb_swap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007AFEC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007AFF0: addiu       $a1, $a1, 0x6868
    ctx->r5 = ADD32(ctx->r5, 0X6868);
    // 0x8007AFF4: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8007AFF8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007AFFC: addiu       $a0, $a0, 0x6860
    ctx->r4 = ADD32(ctx->r4, 0X6860);
    // 0x8007B000: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8007B004: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8007B008: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8007B00C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B010: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8007B014: lw          $v1, -0x1310($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X1310);
    // 0x8007B018: sw          $t8, 0x6878($at)
    MEM_W(0X6878, ctx->r1) = ctx->r24;
    // 0x8007B01C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B020: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8007B024: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8007B028: sw          $v1, 0x6880($at)
    MEM_W(0X6880, ctx->r1) = ctx->r3;
    // 0x8007B02C: addu        $t2, $a0, $t1
    ctx->r10 = ADD32(ctx->r4, ctx->r9);
    // 0x8007B030: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8007B034: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8007B038: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B03C: sw          $t3, 0x6874($at)
    MEM_W(0X6874, ctx->r1) = ctx->r11;
    // 0x8007B040: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B044: jr          $ra
    // 0x8007B048: sw          $v1, 0x687C($at)
    MEM_W(0X687C, ctx->r1) = ctx->r3;
    return;
    // 0x8007B048: sw          $v1, 0x687C($at)
    MEM_W(0X687C, ctx->r1) = ctx->r3;
;}
RECOMP_FUNC void fb_memcpy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B04C: blez        $a2, L_8007B0B0
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8007B050: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8007B0B0;
    }
    // 0x8007B050: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8007B054: andi        $a3, $a2, 0x3
    ctx->r7 = ctx->r6 & 0X3;
    // 0x8007B058: beq         $a3, $zero, L_8007B080
    if (ctx->r7 == 0) {
        // 0x8007B05C: or          $v1, $a3, $zero
        ctx->r3 = ctx->r7 | 0;
            goto L_8007B080;
    }
    // 0x8007B05C: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
L_8007B060:
    // 0x8007B060: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x8007B064: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8007B068: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8007B06C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8007B070: bne         $v1, $v0, L_8007B060
    if (ctx->r3 != ctx->r2) {
        // 0x8007B074: sb          $t6, -0x1($a1)
        MEM_B(-0X1, ctx->r5) = ctx->r14;
            goto L_8007B060;
    }
    // 0x8007B074: sb          $t6, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r14;
    // 0x8007B078: beq         $v0, $a2, L_8007B0B0
    if (ctx->r2 == ctx->r6) {
        // 0x8007B07C: nop
    
            goto L_8007B0B0;
    }
    // 0x8007B07C: nop

L_8007B080:
    // 0x8007B080: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    // 0x8007B084: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8007B088: sb          $t7, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r15;
    // 0x8007B08C: lbu         $t8, 0x1($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X1);
    // 0x8007B090: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8007B094: sb          $t8, -0x3($a1)
    MEM_B(-0X3, ctx->r5) = ctx->r24;
    // 0x8007B098: lbu         $t9, 0x2($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X2);
    // 0x8007B09C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8007B0A0: sb          $t9, -0x2($a1)
    MEM_B(-0X2, ctx->r5) = ctx->r25;
    // 0x8007B0A4: lbu         $t0, -0x1($a0)
    ctx->r8 = MEM_BU(ctx->r4, -0X1);
    // 0x8007B0A8: bne         $v0, $a2, L_8007B080
    if (ctx->r2 != ctx->r6) {
        // 0x8007B0AC: sb          $t0, -0x1($a1)
        MEM_B(-0X1, ctx->r5) = ctx->r8;
            goto L_8007B080;
    }
    // 0x8007B0AC: sb          $t0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r8;
L_8007B0B0:
    // 0x8007B0B0: jr          $ra
    // 0x8007B0B4: nop

    return;
    // 0x8007B0B4: nop

    // 0x8007B0B8: nop

    // 0x8007B0BC: nop

;}
RECOMP_FUNC void tex_init_textures(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B0C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007B0C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007B0C8: lui         $a1, 0xFF00
    ctx->r5 = S32(0XFF00 << 16);
    // 0x8007B0CC: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x8007B0D0: jal         0x80070EDC
    // 0x8007B0D4: addiu       $a0, $zero, 0x15E0
    ctx->r4 = ADD32(0, 0X15E0);
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x8007B0D4: addiu       $a0, $zero, 0x15E0
    ctx->r4 = ADD32(0, 0X15E0);
    after_0:
    // 0x8007B0D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B0DC: lui         $a1, 0xFF00
    ctx->r5 = S32(0XFF00 << 16);
    // 0x8007B0E0: sw          $v0, 0x68C8($at)
    MEM_W(0X68C8, ctx->r1) = ctx->r2;
    // 0x8007B0E4: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x8007B0E8: jal         0x80070EDC
    // 0x8007B0EC: addiu       $a0, $zero, 0x280
    ctx->r4 = ADD32(0, 0X280);
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x8007B0EC: addiu       $a0, $zero, 0x280
    ctx->r4 = ADD32(0, 0X280);
    after_1:
    // 0x8007B0F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B0F4: sw          $v0, 0x68CC($at)
    MEM_W(0X68CC, ctx->r1) = ctx->r2;
    // 0x8007B0F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B0FC: sw          $zero, 0x68D0($at)
    MEM_W(0X68D0, ctx->r1) = 0;
    // 0x8007B100: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B104: sw          $zero, 0x68E0($at)
    MEM_W(0X68E0, ctx->r1) = 0;
    // 0x8007B108: jal         0x80076EE4
    // 0x8007B10C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    asset_table_load(rdram, ctx);
        goto after_2;
    // 0x8007B10C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_2:
    // 0x8007B110: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007B114: addiu       $a1, $a1, 0x68C0
    ctx->r5 = ADD32(ctx->r5, 0X68C0);
    // 0x8007B118: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8007B11C: jal         0x80076EE4
    // 0x8007B120: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    asset_table_load(rdram, ctx);
        goto after_3;
    // 0x8007B120: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_3:
    // 0x8007B124: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007B128: addiu       $a1, $a1, 0x68C0
    ctx->r5 = ADD32(ctx->r5, 0X68C0);
    // 0x8007B12C: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8007B130: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x8007B134: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8007B138: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x8007B13C: beq         $a3, $t6, L_8007B158
    if (ctx->r7 == ctx->r14) {
        // 0x8007B140: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8007B158;
    }
    // 0x8007B140: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8007B144: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8007B148:
    // 0x8007B148: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8007B14C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8007B150: bne         $a3, $t7, L_8007B148
    if (ctx->r7 != ctx->r15) {
        // 0x8007B154: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8007B148;
    }
    // 0x8007B154: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8007B158:
    // 0x8007B158: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8007B15C: lw          $a0, 0x4($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X4);
    // 0x8007B160: addiu       $a2, $a2, 0x68D8
    ctx->r6 = ADD32(ctx->r6, 0X68D8);
    // 0x8007B164: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8007B168: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    // 0x8007B16C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8007B170: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8007B174: beq         $a3, $t8, L_8007B190
    if (ctx->r7 == ctx->r24) {
        // 0x8007B178: lui         $a1, 0xFF00
        ctx->r5 = S32(0XFF00 << 16);
            goto L_8007B190;
    }
    // 0x8007B178: lui         $a1, 0xFF00
    ctx->r5 = S32(0XFF00 << 16);
    // 0x8007B17C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8007B180:
    // 0x8007B180: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x8007B184: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8007B188: bne         $a3, $t9, L_8007B180
    if (ctx->r7 != ctx->r25) {
        // 0x8007B18C: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8007B180;
    }
    // 0x8007B18C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8007B190:
    // 0x8007B190: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8007B194: sw          $v1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r3;
    // 0x8007B198: addiu       $a0, $zero, 0x320
    ctx->r4 = ADD32(0, 0X320);
    // 0x8007B19C: jal         0x80070EDC
    // 0x8007B1A0: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_4;
    // 0x8007B1A0: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    after_4:
    // 0x8007B1A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B1A8: lui         $a1, 0xFF00
    ctx->r5 = S32(0XFF00 << 16);
    // 0x8007B1AC: sw          $v0, 0x68EC($at)
    MEM_W(0X68EC, ctx->r1) = ctx->r2;
    // 0x8007B1B0: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x8007B1B4: jal         0x80070EDC
    // 0x8007B1B8: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    mempool_alloc_safe(rdram, ctx);
        goto after_5;
    // 0x8007B1B8: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    after_5:
    // 0x8007B1BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B1C0: sw          $v0, 0x68F0($at)
    MEM_W(0X68F0, ctx->r1) = ctx->r2;
    // 0x8007B1C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B1C8: sw          $zero, 0x68F8($at)
    MEM_W(0X68F8, ctx->r1) = 0;
    // 0x8007B1CC: jal         0x80076EE4
    // 0x8007B1D0: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    asset_table_load(rdram, ctx);
        goto after_6;
    // 0x8007B1D0: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_6:
    // 0x8007B1D4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007B1D8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8007B1DC: addiu       $a2, $a2, 0x68F4
    ctx->r6 = ADD32(ctx->r6, 0X68F4);
    // 0x8007B1E0: addiu       $a1, $a1, 0x68E8
    ctx->r5 = ADD32(ctx->r5, 0X68E8);
    // 0x8007B1E4: sll         $t0, $zero, 2
    ctx->r8 = S32(0 << 2);
    // 0x8007B1E8: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8007B1EC: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x8007B1F0: addu        $t1, $v0, $t0
    ctx->r9 = ADD32(ctx->r2, ctx->r8);
    // 0x8007B1F4: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8007B1F8: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x8007B1FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8007B200: beq         $a3, $t2, L_8007B228
    if (ctx->r7 == ctx->r10) {
        // 0x8007B204: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8007B228;
    }
    // 0x8007B204: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8007B208: addiu       $t3, $v1, 0x1
    ctx->r11 = ADD32(ctx->r3, 0X1);
L_8007B20C:
    // 0x8007B20C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8007B210: addu        $t5, $a0, $t4
    ctx->r13 = ADD32(ctx->r4, ctx->r12);
    // 0x8007B214: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x8007B218: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8007B21C: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x8007B220: bne         $a3, $t6, L_8007B20C
    if (ctx->r7 != ctx->r14) {
        // 0x8007B224: addiu       $t3, $v1, 0x1
        ctx->r11 = ADD32(ctx->r3, 0X1);
            goto L_8007B20C;
    }
    // 0x8007B224: addiu       $t3, $v1, 0x1
    ctx->r11 = ADD32(ctx->r3, 0X1);
L_8007B228:
    // 0x8007B228: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x8007B22C: lui         $a1, 0xFF00
    ctx->r5 = S32(0XFF00 << 16);
    // 0x8007B230: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x8007B234: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x8007B238: jal         0x80070EDC
    // 0x8007B23C: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    mempool_alloc_safe(rdram, ctx);
        goto after_7;
    // 0x8007B23C: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_7:
    // 0x8007B240: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B244: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007B248: sw          $v0, 0x690C($at)
    MEM_W(0X690C, ctx->r1) = ctx->r2;
    // 0x8007B24C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B250: sw          $zero, 0x68E4($at)
    MEM_W(0X68E4, ctx->r1) = 0;
    // 0x8007B254: jr          $ra
    // 0x8007B258: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8007B258: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void tex_disable_modes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B25C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007B260: addiu       $v0, $v0, 0x6918
    ctx->r2 = ADD32(ctx->r2, 0X6918);
    // 0x8007B264: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8007B268: nop

    // 0x8007B26C: or          $t7, $t6, $a0
    ctx->r15 = ctx->r14 | ctx->r4;
    // 0x8007B270: jr          $ra
    // 0x8007B274: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    return;
    // 0x8007B274: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void tex_enable_modes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B278: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007B27C: addiu       $v0, $v0, 0x6918
    ctx->r2 = ADD32(ctx->r2, 0X6918);
    // 0x8007B280: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8007B284: nor         $t7, $a0, $zero
    ctx->r15 = ~(ctx->r4 | 0);
    // 0x8007B288: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x8007B28C: jr          $ra
    // 0x8007B290: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    return;
    // 0x8007B290: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
;}
RECOMP_FUNC void tex_get_table_2D(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B294: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007B298: lw          $v0, 0x68D8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X68D8);
    // 0x8007B29C: jr          $ra
    // 0x8007B2A0: nop

    return;
    // 0x8007B2A0: nop

;}
RECOMP_FUNC void tex_get_table_3D(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B2A4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007B2A8: lw          $v0, 0x68DC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X68DC);
    // 0x8007B2AC: jr          $ra
    // 0x8007B2B0: nop

    return;
    // 0x8007B2B0: nop

;}
RECOMP_FUNC void sprite_table_size(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B2B4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007B2B8: lw          $v0, 0x68F4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X68F4);
    // 0x8007B2BC: jr          $ra
    // 0x8007B2C0: nop

    return;
    // 0x8007B2C0: nop

;}
RECOMP_FUNC void load_texture(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B2C4: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8007B2C8: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x8007B2CC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8007B2D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007B2D4: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x8007B2D8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8007B2DC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8007B2E0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8007B2E4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8007B2E8: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x8007B2EC: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
    // 0x8007B2F0: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
    // 0x8007B2F4: beq         $t7, $zero, L_8007B308
    if (ctx->r15 == 0) {
        // 0x8007B2F8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8007B308;
    }
    // 0x8007B2F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8007B2FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007B300: andi        $t0, $t6, 0x7FFF
    ctx->r8 = ctx->r14 & 0X7FFF;
    // 0x8007B304: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
L_8007B308:
    // 0x8007B308: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x8007B30C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8007B310: addu        $t8, $t8, $t1
    ctx->r24 = ADD32(ctx->r24, ctx->r9);
    // 0x8007B314: lw          $t8, 0x68D8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X68D8);
    // 0x8007B318: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007B31C: slt         $at, $t0, $t8
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8007B320: beq         $at, $zero, L_8007B330
    if (ctx->r1 == 0) {
        // 0x8007B324: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_8007B330;
    }
    // 0x8007B324: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007B328: bgez        $t0, L_8007B334
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8007B32C: nop
    
            goto L_8007B334;
    }
    // 0x8007B32C: nop

L_8007B330:
    // 0x8007B330: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8007B334:
    // 0x8007B334: lw          $v0, 0x68D0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X68D0);
    // 0x8007B338: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8007B33C: blez        $v0, L_8007B388
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8007B340: lui         $s4, 0x8012
        ctx->r20 = S32(0X8012 << 16);
            goto L_8007B388;
    }
    // 0x8007B340: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8007B344: lw          $a0, 0x68C8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X68C8);
    // 0x8007B348: nop

    // 0x8007B34C: sll         $t2, $s1, 3
    ctx->r10 = S32(ctx->r17 << 3);
L_8007B350:
    // 0x8007B350: addu        $v1, $a0, $t2
    ctx->r3 = ADD32(ctx->r4, ctx->r10);
    // 0x8007B354: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x8007B358: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8007B35C: bne         $s0, $t3, L_8007B380
    if (ctx->r16 != ctx->r11) {
        // 0x8007B360: slt         $at, $s1, $v0
        ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8007B380;
    }
    // 0x8007B360: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8007B364: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8007B368: nop

    // 0x8007B36C: lbu         $t4, 0x5($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X5);
    // 0x8007B370: nop

    // 0x8007B374: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8007B378: b           L_8007B6EC
    // 0x8007B37C: sb          $t5, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r13;
        goto L_8007B6EC;
    // 0x8007B37C: sb          $t5, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r13;
L_8007B380:
    // 0x8007B380: bne         $at, $zero, L_8007B350
    if (ctx->r1 != 0) {
        // 0x8007B384: sll         $t2, $s1, 3
        ctx->r10 = S32(ctx->r17 << 3);
            goto L_8007B350;
    }
    // 0x8007B384: sll         $t2, $s1, 3
    ctx->r10 = S32(ctx->r17 << 3);
L_8007B388:
    // 0x8007B388: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007B38C: addu        $t6, $t6, $t1
    ctx->r14 = ADD32(ctx->r14, ctx->r9);
    // 0x8007B390: lw          $t6, 0x68C0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X68C0);
    // 0x8007B394: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x8007B398: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8007B39C: lw          $s2, 0x0($v0)
    ctx->r18 = MEM_W(ctx->r2, 0X0);
    // 0x8007B3A0: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x8007B3A4: addiu       $s4, $s4, 0x690C
    ctx->r20 = ADD32(ctx->r20, 0X690C);
    // 0x8007B3A8: lw          $a1, 0x0($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X0);
    // 0x8007B3AC: subu        $t9, $t8, $s2
    ctx->r25 = SUB32(ctx->r24, ctx->r18);
    // 0x8007B3B0: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
    // 0x8007B3B4: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x8007B3B8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8007B3BC: addiu       $a3, $zero, 0x28
    ctx->r7 = ADD32(0, 0X28);
    // 0x8007B3C0: jal         0x80077190
    // 0x8007B3C4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    asset_load(rdram, ctx);
        goto after_0;
    // 0x8007B3C4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_0:
    // 0x8007B3C8: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x8007B3CC: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x8007B3D0: lhu         $s1, 0x12($v1)
    ctx->r17 = MEM_HU(ctx->r3, 0X12);
    // 0x8007B3D4: lbu         $t4, 0x1D($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X1D);
    // 0x8007B3D8: sra         $t2, $s1, 8
    ctx->r10 = S32(SIGNED(ctx->r17) >> 8);
    // 0x8007B3DC: andi        $t3, $t2, 0xFFFF
    ctx->r11 = ctx->r10 & 0XFFFF;
    // 0x8007B3E0: bne         $t4, $zero, L_8007B438
    if (ctx->r12 != 0) {
        // 0x8007B3E4: or          $s1, $t3, $zero
        ctx->r17 = ctx->r11 | 0;
            goto L_8007B438;
    }
    // 0x8007B3E4: or          $s1, $t3, $zero
    ctx->r17 = ctx->r11 | 0;
    // 0x8007B3E8: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x8007B3EC: subu        $t5, $t5, $t3
    ctx->r13 = SUB32(ctx->r13, ctx->r11);
    // 0x8007B3F0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8007B3F4: lw          $a1, -0x12C0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X12C0);
    // 0x8007B3F8: sll         $t5, $t5, 5
    ctx->r13 = S32(ctx->r13 << 5);
    // 0x8007B3FC: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    // 0x8007B400: jal         0x80070F50
    // 0x8007B404: or          $s4, $t3, $zero
    ctx->r20 = ctx->r11 | 0;
    mempool_alloc(rdram, ctx);
        goto after_1;
    // 0x8007B404: or          $s4, $t3, $zero
    ctx->r20 = ctx->r11 | 0;
    after_1:
    // 0x8007B408: bne         $v0, $zero, L_8007B418
    if (ctx->r2 != 0) {
        // 0x8007B40C: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_8007B418;
    }
    // 0x8007B40C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8007B410: b           L_8007B6EC
    // 0x8007B414: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007B6EC;
    // 0x8007B414: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007B418:
    // 0x8007B418: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8007B41C: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x8007B420: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8007B424: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8007B428: jal         0x80077190
    // 0x8007B42C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    asset_load(rdram, ctx);
        goto after_2;
    // 0x8007B42C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_2:
    // 0x8007B430: b           L_8007B4DC
    // 0x8007B434: nop

        goto L_8007B4DC;
    // 0x8007B434: nop

L_8007B438:
    // 0x8007B438: jal         0x800C670C
    // 0x8007B43C: addiu       $a0, $v1, 0x20
    ctx->r4 = ADD32(ctx->r3, 0X20);
    byteswap32(rdram, ctx);
        goto after_3;
    // 0x8007B43C: addiu       $a0, $v1, 0x20
    ctx->r4 = ADD32(ctx->r3, 0X20);
    after_3:
    // 0x8007B440: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x8007B444: subu        $t8, $t8, $s1
    ctx->r24 = SUB32(ctx->r24, ctx->r17);
    // 0x8007B448: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x8007B44C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8007B450: addiu       $t7, $v0, 0x20
    ctx->r15 = ADD32(ctx->r2, 0X20);
    // 0x8007B454: lw          $a1, -0x12C0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X12C0);
    // 0x8007B458: addu        $a0, $t8, $v0
    ctx->r4 = ADD32(ctx->r24, ctx->r2);
    // 0x8007B45C: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x8007B460: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x8007B464: jal         0x80070F50
    // 0x8007B468: or          $s4, $s1, $zero
    ctx->r20 = ctx->r17 | 0;
    mempool_alloc(rdram, ctx);
        goto after_4;
    // 0x8007B468: or          $s4, $s1, $zero
    ctx->r20 = ctx->r17 | 0;
    after_4:
    // 0x8007B46C: bne         $v0, $zero, L_8007B47C
    if (ctx->r2 != 0) {
        // 0x8007B470: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_8007B47C;
    }
    // 0x8007B470: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8007B474: b           L_8007B6EC
    // 0x8007B478: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007B6EC;
    // 0x8007B478: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007B47C:
    // 0x8007B47C: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8007B480: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x8007B484: addu        $t2, $s3, $t9
    ctx->r10 = ADD32(ctx->r19, ctx->r25);
    // 0x8007B488: subu        $v0, $t2, $t3
    ctx->r2 = SUB32(ctx->r10, ctx->r11);
    // 0x8007B48C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8007B490: bgez        $v0, L_8007B4A4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8007B494: andi        $t4, $v0, 0xF
        ctx->r12 = ctx->r2 & 0XF;
            goto L_8007B4A4;
    }
    // 0x8007B494: andi        $t4, $v0, 0xF
    ctx->r12 = ctx->r2 & 0XF;
    // 0x8007B498: beq         $t4, $zero, L_8007B4A4
    if (ctx->r12 == 0) {
        // 0x8007B49C: nop
    
            goto L_8007B4A4;
    }
    // 0x8007B49C: nop

    // 0x8007B4A0: addiu       $t4, $t4, -0x10
    ctx->r12 = ADD32(ctx->r12, -0X10);
L_8007B4A4:
    // 0x8007B4A4: subu        $a1, $v0, $t4
    ctx->r5 = SUB32(ctx->r2, ctx->r12);
    // 0x8007B4A8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8007B4AC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8007B4B0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8007B4B4: jal         0x80077190
    // 0x8007B4B8: or          $a3, $t3, $zero
    ctx->r7 = ctx->r11 | 0;
    asset_load(rdram, ctx);
        goto after_5;
    // 0x8007B4B8: or          $a3, $t3, $zero
    ctx->r7 = ctx->r11 | 0;
    after_5:
    // 0x8007B4BC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8007B4C0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8007B4C4: jal         0x800C6778
    // 0x8007B4C8: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    gzip_inflate(rdram, ctx);
        goto after_6;
    // 0x8007B4C8: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    after_6:
    // 0x8007B4CC: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8007B4D0: nop

    // 0x8007B4D4: addiu       $t6, $t5, -0x20
    ctx->r14 = ADD32(ctx->r13, -0X20);
    // 0x8007B4D8: sw          $t6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r14;
L_8007B4DC:
    // 0x8007B4DC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007B4E0: lw          $v0, 0x68D0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X68D0);
    // 0x8007B4E4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8007B4E8: blez        $v0, L_8007B52C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8007B4EC: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8007B52C;
    }
    // 0x8007B4EC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007B4F0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007B4F4: lw          $a0, 0x68C8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X68C8);
    // 0x8007B4F8: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8007B4FC: sll         $t8, $s1, 3
    ctx->r24 = S32(ctx->r17 << 3);
L_8007B500:
    // 0x8007B500: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x8007B504: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x8007B508: nop

    // 0x8007B50C: bne         $v1, $t2, L_8007B518
    if (ctx->r3 != ctx->r10) {
        // 0x8007B510: nop
    
            goto L_8007B518;
    }
    // 0x8007B510: nop

    // 0x8007B514: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
L_8007B518:
    // 0x8007B518: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8007B51C: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8007B520: bne         $at, $zero, L_8007B500
    if (ctx->r1 != 0) {
        // 0x8007B524: sll         $t8, $s1, 3
        ctx->r24 = S32(ctx->r17 << 3);
            goto L_8007B500;
    }
    // 0x8007B524: sll         $t8, $s1, 3
    ctx->r24 = S32(ctx->r17 << 3);
    // 0x8007B528: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8007B52C:
    // 0x8007B52C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007B530: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8007B534: lw          $a0, 0x68C8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X68C8);
    // 0x8007B538: bne         $a1, $v1, L_8007B54C
    if (ctx->r5 != ctx->r3) {
        // 0x8007B53C: addiu       $t4, $v0, 0x1
        ctx->r12 = ADD32(ctx->r2, 0X1);
            goto L_8007B54C;
    }
    // 0x8007B53C: addiu       $t4, $v0, 0x1
    ctx->r12 = ADD32(ctx->r2, 0X1);
    // 0x8007B540: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B544: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8007B548: sw          $t4, 0x68D0($at)
    MEM_W(0X68D0, ctx->r1) = ctx->r12;
L_8007B54C:
    // 0x8007B54C: sll         $t3, $a1, 3
    ctx->r11 = S32(ctx->r5 << 3);
    // 0x8007B550: addu        $t5, $a0, $t3
    ctx->r13 = ADD32(ctx->r4, ctx->r11);
    // 0x8007B554: sw          $s0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r16;
    // 0x8007B558: lw          $t6, 0x68C8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X68C8);
    // 0x8007B55C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8007B560: addu        $t7, $t6, $t3
    ctx->r15 = ADD32(ctx->r14, ctx->r11);
    // 0x8007B564: sw          $s3, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r19;
    // 0x8007B568: lbu         $a2, 0x2($s3)
    ctx->r6 = MEM_BU(ctx->r19, 0X2);
    // 0x8007B56C: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8007B570: andi        $t8, $a2, 0xF
    ctx->r24 = ctx->r6 & 0XF;
    // 0x8007B574: bne         $t8, $at, L_8007B5F0
    if (ctx->r24 != ctx->r1) {
        // 0x8007B578: or          $a2, $t8, $zero
        ctx->r6 = ctx->r24 | 0;
            goto L_8007B5F0;
    }
    // 0x8007B578: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x8007B57C: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8007B580: addiu       $s2, $s2, 0x68E4
    ctx->r18 = ADD32(ctx->r18, 0X68E4);
    // 0x8007B584: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x8007B588: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x8007B58C: bne         $t9, $zero, L_8007B5E0
    if (ctx->r25 != 0) {
        // 0x8007B590: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_8007B5E0;
    }
    // 0x8007B590: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8007B594: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8007B598: lw          $t4, 0x68E0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X68E0);
    // 0x8007B59C: lw          $t2, 0x68CC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X68CC);
    // 0x8007B5A0: lh          $a2, 0x8($s3)
    ctx->r6 = MEM_H(ctx->r19, 0X8);
    // 0x8007B5A4: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x8007B5A8: jal         0x80077190
    // 0x8007B5AC: addu        $a1, $t2, $t4
    ctx->r5 = ADD32(ctx->r10, ctx->r12);
    asset_load(rdram, ctx);
        goto after_7;
    // 0x8007B5AC: addu        $a1, $t2, $t4
    ctx->r5 = ADD32(ctx->r10, ctx->r12);
    after_7:
    // 0x8007B5B0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8007B5B4: lw          $t3, 0x68E0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X68E0);
    // 0x8007B5B8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8007B5BC: sh          $t3, 0x8($s3)
    MEM_H(0X8, ctx->r19) = ctx->r11;
    // 0x8007B5C0: lw          $t5, 0x68E0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X68E0);
    // 0x8007B5C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B5C8: addiu       $t6, $t5, 0x20
    ctx->r14 = ADD32(ctx->r13, 0X20);
    // 0x8007B5CC: sw          $t6, 0x68E0($at)
    MEM_W(0X68E0, ctx->r1) = ctx->r14;
    // 0x8007B5D0: lbu         $a2, 0x2($s3)
    ctx->r6 = MEM_BU(ctx->r19, 0X2);
    // 0x8007B5D4: nop

    // 0x8007B5D8: andi        $t7, $a2, 0xF
    ctx->r15 = ctx->r6 & 0XF;
    // 0x8007B5DC: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
L_8007B5E0:
    // 0x8007B5E0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8007B5E4: lw          $v1, 0x68E0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X68E0);
    // 0x8007B5E8: nop

    // 0x8007B5EC: addiu       $v1, $v1, -0x20
    ctx->r3 = ADD32(ctx->r3, -0X20);
L_8007B5F0:
    // 0x8007B5F0: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8007B5F4: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8007B5F8: bne         $a2, $at, L_8007B654
    if (ctx->r6 != ctx->r1) {
        // 0x8007B5FC: addiu       $s2, $s2, 0x68E4
        ctx->r18 = ADD32(ctx->r18, 0X68E4);
            goto L_8007B654;
    }
    // 0x8007B5FC: addiu       $s2, $s2, 0x68E4
    ctx->r18 = ADD32(ctx->r18, 0X68E4);
    // 0x8007B600: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x8007B604: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8007B608: lw          $s0, 0x68E0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X68E0);
    // 0x8007B60C: bne         $t8, $zero, L_8007B650
    if (ctx->r24 != 0) {
        // 0x8007B610: addiu       $a0, $zero, 0xE
        ctx->r4 = ADD32(0, 0XE);
            goto L_8007B650;
    }
    // 0x8007B610: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x8007B614: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8007B618: lw          $t9, 0x68CC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X68CC);
    // 0x8007B61C: lh          $a2, 0x8($s3)
    ctx->r6 = MEM_H(ctx->r19, 0X8);
    // 0x8007B620: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    // 0x8007B624: jal         0x80077190
    // 0x8007B628: addu        $a1, $t9, $s0
    ctx->r5 = ADD32(ctx->r25, ctx->r16);
    asset_load(rdram, ctx);
        goto after_8;
    // 0x8007B628: addu        $a1, $t9, $s0
    ctx->r5 = ADD32(ctx->r25, ctx->r16);
    after_8:
    // 0x8007B62C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8007B630: addiu       $v1, $v1, 0x68E0
    ctx->r3 = ADD32(ctx->r3, 0X68E0);
    // 0x8007B634: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8007B638: nop

    // 0x8007B63C: sh          $t2, 0x8($s3)
    MEM_H(0X8, ctx->r19) = ctx->r10;
    // 0x8007B640: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8007B644: nop

    // 0x8007B648: addiu       $s0, $t4, 0x80
    ctx->r16 = ADD32(ctx->r12, 0X80);
    // 0x8007B64C: sw          $s0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r16;
L_8007B650:
    // 0x8007B650: addiu       $v1, $s0, -0x80
    ctx->r3 = ADD32(ctx->r16, -0X80);
L_8007B654:
    // 0x8007B654: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x8007B658: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
    // 0x8007B65C: sw          $v1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r3;
    // 0x8007B660: jal         0x80071A90
    // 0x8007B664: addu        $a0, $s3, $t5
    ctx->r4 = ADD32(ctx->r19, ctx->r13);
    align16(rdram, ctx);
        goto after_9;
    // 0x8007B664: addu        $a0, $s3, $t5
    ctx->r4 = ADD32(ctx->r19, ctx->r13);
    after_9:
    // 0x8007B668: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x8007B66C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8007B670: blez        $s4, L_8007B6B0
    if (SIGNED(ctx->r20) <= 0) {
        // 0x8007B674: or          $s0, $s3, $zero
        ctx->r16 = ctx->r19 | 0;
            goto L_8007B6B0;
    }
    // 0x8007B674: or          $s0, $s3, $zero
    ctx->r16 = ctx->r19 | 0;
L_8007B678:
    // 0x8007B678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007B67C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8007B680: jal         0x8007D544
    // 0x8007B684: sw          $v1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r3;
    material_init(rdram, ctx);
        goto after_10;
    // 0x8007B684: sw          $v1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r3;
    after_10:
    // 0x8007B688: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x8007B68C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8007B690: bltz        $v1, L_8007B6A0
    if (SIGNED(ctx->r3) < 0) {
        // 0x8007B694: nop
    
            goto L_8007B6A0;
    }
    // 0x8007B694: nop

    // 0x8007B698: sh          $v1, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r3;
    // 0x8007B69C: addiu       $s2, $s2, 0x30
    ctx->r18 = ADD32(ctx->r18, 0X30);
L_8007B6A0:
    // 0x8007B6A0: lh          $t6, 0x16($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X16);
    // 0x8007B6A4: addiu       $s2, $s2, 0x60
    ctx->r18 = ADD32(ctx->r18, 0X60);
    // 0x8007B6A8: bne         $s1, $s4, L_8007B678
    if (ctx->r17 != ctx->r20) {
        // 0x8007B6AC: addu        $s0, $s0, $t6
        ctx->r16 = ADD32(ctx->r16, ctx->r14);
            goto L_8007B678;
    }
    // 0x8007B6AC: addu        $s0, $s0, $t6
    ctx->r16 = ADD32(ctx->r16, ctx->r14);
L_8007B6B0:
    // 0x8007B6B0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8007B6B4: lw          $t7, 0x68E0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X68E0);
    // 0x8007B6B8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8007B6BC: slti        $at, $t7, 0x280
    ctx->r1 = SIGNED(ctx->r15) < 0X280 ? 1 : 0;
    // 0x8007B6C0: bne         $at, $zero, L_8007B6D0
    if (ctx->r1 != 0) {
        // 0x8007B6C4: nop
    
            goto L_8007B6D0;
    }
    // 0x8007B6C4: nop

    // 0x8007B6C8: b           L_8007B6EC
    // 0x8007B6CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007B6EC;
    // 0x8007B6CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007B6D0:
    // 0x8007B6D0: lw          $t8, 0x68D0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X68D0);
    // 0x8007B6D4: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x8007B6D8: slti        $at, $t8, 0x2BD
    ctx->r1 = SIGNED(ctx->r24) < 0X2BD ? 1 : 0;
    // 0x8007B6DC: bne         $at, $zero, L_8007B6EC
    if (ctx->r1 != 0) {
        // 0x8007B6E0: nop
    
            goto L_8007B6EC;
    }
    // 0x8007B6E0: nop

    // 0x8007B6E4: b           L_8007B6EC
    // 0x8007B6E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007B6EC;
    // 0x8007B6E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007B6EC:
    // 0x8007B6EC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8007B6F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007B6F4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8007B6F8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8007B6FC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8007B700: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8007B704: jr          $ra
    // 0x8007B708: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8007B708: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void tex_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B70C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007B710: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007B714: beq         $a0, $zero, L_8007B7B4
    if (ctx->r4 == 0) {
        // 0x8007B718: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_8007B7B4;
    }
    // 0x8007B718: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8007B71C: lbu         $t6, 0x5($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X5);
    // 0x8007B720: nop

    // 0x8007B724: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8007B728: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x8007B72C: bgtz        $t8, L_8007B7B4
    if (SIGNED(ctx->r24) > 0) {
        // 0x8007B730: sb          $t7, 0x5($a0)
        MEM_B(0X5, ctx->r4) = ctx->r15;
            goto L_8007B7B4;
    }
    // 0x8007B730: sb          $t7, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r15;
    // 0x8007B734: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007B738: lw          $a0, 0x68D0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X68D0);
    // 0x8007B73C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8007B740: blez        $a0, L_8007B7B4
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8007B744: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_8007B7B4;
    }
    // 0x8007B744: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007B748: lw          $a1, 0x68C8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X68C8);
    // 0x8007B74C: nop

    // 0x8007B750: sll         $t9, $v0, 3
    ctx->r25 = S32(ctx->r2 << 3);
L_8007B754:
    // 0x8007B754: addu        $t0, $a1, $t9
    ctx->r8 = ADD32(ctx->r5, ctx->r25);
    // 0x8007B758: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8007B75C: nop

    // 0x8007B760: bne         $a2, $t1, L_8007B7A8
    if (ctx->r6 != ctx->r9) {
        // 0x8007B764: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8007B7A8;
    }
    // 0x8007B764: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8007B768: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8007B76C: jal         0x80071380
    // 0x8007B770: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    mempool_free(rdram, ctx);
        goto after_0;
    // 0x8007B770: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    after_0:
    // 0x8007B774: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007B778: addiu       $v0, $v0, 0x68C8
    ctx->r2 = ADD32(ctx->r2, 0X68C8);
    // 0x8007B77C: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8007B780: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8007B784: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8007B788: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x8007B78C: sw          $a0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r4;
    // 0x8007B790: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8007B794: nop

    // 0x8007B798: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x8007B79C: b           L_8007B7B4
    // 0x8007B7A0: sw          $a0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r4;
        goto L_8007B7B4;
    // 0x8007B7A0: sw          $a0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r4;
    // 0x8007B7A4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8007B7A8:
    // 0x8007B7A8: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8007B7AC: bne         $at, $zero, L_8007B754
    if (ctx->r1 != 0) {
        // 0x8007B7B0: sll         $t9, $v0, 3
        ctx->r25 = S32(ctx->r2 << 3);
            goto L_8007B754;
    }
    // 0x8007B7B0: sll         $t9, $v0, 3
    ctx->r25 = S32(ctx->r2 << 3);
L_8007B7B4:
    // 0x8007B7B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007B7B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8007B7BC: jr          $ra
    // 0x8007B7C0: nop

    return;
    // 0x8007B7C0: nop

;}
RECOMP_FUNC void set_texture_colour_tag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B7C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007B7C8: jr          $ra
    // 0x8007B7CC: sw          $a0, -0x12C0($at)
    MEM_W(-0X12C0, ctx->r1) = ctx->r4;
    return;
    // 0x8007B7CC: sw          $a0, -0x12C0($at)
    MEM_W(-0X12C0, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void tex_cache_index(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B7D0: bltz        $a0, L_8007B7EC
    if (SIGNED(ctx->r4) < 0) {
        // 0x8007B7D4: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8007B7EC;
    }
    // 0x8007B7D4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007B7D8: lw          $t6, 0x68D0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X68D0);
    // 0x8007B7DC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8007B7E0: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8007B7E4: bne         $at, $zero, L_8007B7F4
    if (ctx->r1 != 0) {
        // 0x8007B7E8: nop
    
            goto L_8007B7F4;
    }
    // 0x8007B7E8: nop

L_8007B7EC:
    // 0x8007B7EC: jr          $ra
    // 0x8007B7F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8007B7F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007B7F4:
    // 0x8007B7F4: lw          $t7, 0x68C8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X68C8);
    // 0x8007B7F8: sll         $t9, $a0, 3
    ctx->r25 = S32(ctx->r4 << 3);
    // 0x8007B7FC: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8007B800: lw          $v1, 0x4($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X4);
    // 0x8007B804: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007B808: bne         $v1, $at, L_8007B818
    if (ctx->r3 != ctx->r1) {
        // 0x8007B80C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8007B818;
    }
    // 0x8007B80C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8007B810: jr          $ra
    // 0x8007B814: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8007B814: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007B818:
    // 0x8007B818: jr          $ra
    // 0x8007B81C: nop

    return;
    // 0x8007B81C: nop

;}
RECOMP_FUNC void rendermode_reset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B820: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B824: sw          $zero, 0x691C($at)
    MEM_W(0X691C, ctx->r1) = 0;
    // 0x8007B828: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B82C: sw          $zero, 0x6914($at)
    MEM_W(0X6914, ctx->r1) = 0;
    // 0x8007B830: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B834: sh          $zero, 0x6920($at)
    MEM_H(0X6920, ctx->r1) = 0;
    // 0x8007B838: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B83C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007B840: sh          $t6, 0x6922($at)
    MEM_H(0X6922, ctx->r1) = ctx->r14;
    // 0x8007B844: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B848: sw          $zero, 0x6918($at)
    MEM_W(0X6918, ctx->r1) = 0;
    // 0x8007B84C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B850: sh          $zero, 0x6924($at)
    MEM_H(0X6924, ctx->r1) = 0;
    // 0x8007B854: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8007B858: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8007B85C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8007B860: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007B864: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8007B868: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8007B86C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8007B870: lui         $t0, 0xB700
    ctx->r8 = S32(0XB700 << 16);
    // 0x8007B874: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8007B878: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007B87C: addiu       $t1, $zero, 0x205
    ctx->r9 = ADD32(0, 0X205);
    // 0x8007B880: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x8007B884: jr          $ra
    // 0x8007B888: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    return;
    // 0x8007B888: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
;}
RECOMP_FUNC void directional_lighting_on(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B88C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007B890: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B894: sh          $v0, 0x6924($at)
    MEM_H(0X6924, ctx->r1) = ctx->r2;
    // 0x8007B898: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B89C: jr          $ra
    // 0x8007B8A0: sh          $v0, 0x6922($at)
    MEM_H(0X6922, ctx->r1) = ctx->r2;
    return;
    // 0x8007B8A0: sh          $v0, 0x6922($at)
    MEM_H(0X6922, ctx->r1) = ctx->r2;
;}
RECOMP_FUNC void directional_lighting_off(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B8A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B8A8: sh          $zero, 0x6924($at)
    MEM_H(0X6924, ctx->r1) = 0;
    // 0x8007B8AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B8B0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007B8B4: jr          $ra
    // 0x8007B8B8: sh          $t6, 0x6922($at)
    MEM_H(0X6922, ctx->r1) = ctx->r14;
    return;
    // 0x8007B8B8: sh          $t6, 0x6922($at)
    MEM_H(0X6922, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void set_animated_texture_header(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B8BC: blez        $a1, L_8007B910
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8007B8C0: nop
    
            goto L_8007B910;
    }
    // 0x8007B8C0: nop

    // 0x8007B8C4: lhu         $v0, 0x12($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X12);
    // 0x8007B8C8: nop

    // 0x8007B8CC: sll         $t6, $v0, 8
    ctx->r14 = S32(ctx->r2 << 8);
    // 0x8007B8D0: slt         $at, $a1, $t6
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8007B8D4: beq         $at, $zero, L_8007B8F8
    if (ctx->r1 == 0) {
        // 0x8007B8D8: sra         $t0, $v0, 8
        ctx->r8 = S32(SIGNED(ctx->r2) >> 8);
            goto L_8007B8F8;
    }
    // 0x8007B8D8: sra         $t0, $v0, 8
    ctx->r8 = S32(SIGNED(ctx->r2) >> 8);
    // 0x8007B8DC: lh          $t8, 0x16($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X16);
    // 0x8007B8E0: sra         $t7, $a1, 16
    ctx->r15 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8007B8E4: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007B8E8: mflo        $t9
    ctx->r25 = lo;
    // 0x8007B8EC: addu        $v0, $a0, $t9
    ctx->r2 = ADD32(ctx->r4, ctx->r25);
    // 0x8007B8F0: jr          $ra
    // 0x8007B8F4: nop

    return;
    // 0x8007B8F4: nop

L_8007B8F8:
    // 0x8007B8F8: lh          $t2, 0x16($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X16);
    // 0x8007B8FC: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8007B900: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007B904: mflo        $t3
    ctx->r11 = lo;
    // 0x8007B908: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x8007B90C: nop

L_8007B910:
    // 0x8007B910: jr          $ra
    // 0x8007B914: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8007B914: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void material_set_no_tex_offset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B918: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007B91C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007B920: jal         0x8007B938
    // 0x8007B924: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    material_set(rdram, ctx);
        goto after_0;
    // 0x8007B924: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8007B928: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007B92C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007B930: jr          $ra
    // 0x8007B934: nop

    return;
    // 0x8007B934: nop

;}
RECOMP_FUNC void material_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B938: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8007B93C: addiu       $t3, $t3, 0x6922
    ctx->r11 = ADD32(ctx->r11, 0X6922);
    // 0x8007B940: lh          $v1, 0x0($t3)
    ctx->r3 = MEM_H(ctx->r11, 0X0);
    // 0x8007B944: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8007B948: beq         $a1, $zero, L_8007BA0C
    if (ctx->r5 == 0) {
        // 0x8007B94C: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_8007BA0C;
    }
    // 0x8007B94C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8007B950: beq         $a3, $zero, L_8007B988
    if (ctx->r7 == 0) {
        // 0x8007B954: lui         $t4, 0x8012
        ctx->r12 = S32(0X8012 << 16);
            goto L_8007B988;
    }
    // 0x8007B954: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8007B958: lhu         $t6, 0x12($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X12);
    // 0x8007B95C: nop

    // 0x8007B960: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x8007B964: slt         $at, $a3, $t7
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8007B968: beq         $at, $zero, L_8007B988
    if (ctx->r1 == 0) {
        // 0x8007B96C: nop
    
            goto L_8007B988;
    }
    // 0x8007B96C: nop

    // 0x8007B970: lh          $t9, 0x16($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X16);
    // 0x8007B974: sra         $t8, $a3, 16
    ctx->r24 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8007B978: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007B97C: mflo        $t6
    ctx->r14 = lo;
    // 0x8007B980: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
    // 0x8007B984: nop

L_8007B988:
    // 0x8007B988: addiu       $t4, $t4, 0x691C
    ctx->r12 = ADD32(ctx->r12, 0X691C);
    // 0x8007B98C: lh          $t7, 0x6($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X6);
    // 0x8007B990: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x8007B994: or          $a2, $a2, $t7
    ctx->r6 = ctx->r6 | ctx->r15;
    // 0x8007B998: beq         $a1, $t8, L_8007B9E8
    if (ctx->r5 == ctx->r24) {
        // 0x8007B99C: nop
    
            goto L_8007B9E8;
    }
    // 0x8007B99C: nop

    // 0x8007B9A0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007B9A4: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007B9A8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007B9AC: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007B9B0: lh          $t2, 0xA($a1)
    ctx->r10 = MEM_H(ctx->r5, 0XA);
    // 0x8007B9B4: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x8007B9B8: andi        $t6, $t2, 0xFF
    ctx->r14 = ctx->r10 & 0XFF;
    // 0x8007B9BC: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8007B9C0: sll         $t9, $t2, 3
    ctx->r25 = S32(ctx->r10 << 3);
    // 0x8007B9C4: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x8007B9C8: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8007B9CC: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8007B9D0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007B9D4: lw          $t9, 0xC($a1)
    ctx->r25 = MEM_W(ctx->r5, 0XC);
    // 0x8007B9D8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8007B9DC: addu        $t8, $t9, $t1
    ctx->r24 = ADD32(ctx->r25, ctx->r9);
    // 0x8007B9E0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8007B9E4: sw          $a1, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r5;
L_8007B9E8:
    // 0x8007B9E8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8007B9EC: addiu       $t2, $t2, 0x6920
    ctx->r10 = ADD32(ctx->r10, 0X6920);
    // 0x8007B9F0: lh          $t6, 0x0($t2)
    ctx->r14 = MEM_H(ctx->r10, 0X0);
    // 0x8007B9F4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8007B9F8: bne         $t6, $zero, L_8007BA2C
    if (ctx->r14 != 0) {
        // 0x8007B9FC: nop
    
            goto L_8007BA2C;
    }
    // 0x8007B9FC: nop

    // 0x8007BA00: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8007BA04: b           L_8007BA2C
    // 0x8007BA08: sh          $t7, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r15;
        goto L_8007BA2C;
    // 0x8007BA08: sh          $t7, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r15;
L_8007BA0C:
    // 0x8007BA0C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8007BA10: addiu       $t2, $t2, 0x6920
    ctx->r10 = ADD32(ctx->r10, 0X6920);
    // 0x8007BA14: lh          $t9, 0x0($t2)
    ctx->r25 = MEM_H(ctx->r10, 0X0);
    // 0x8007BA18: nop

    // 0x8007BA1C: beq         $t9, $zero, L_8007BA2C
    if (ctx->r25 == 0) {
        // 0x8007BA20: nop
    
            goto L_8007BA2C;
    }
    // 0x8007BA20: nop

    // 0x8007BA24: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8007BA28: sh          $zero, 0x0($t2)
    MEM_H(0X0, ctx->r10) = 0;
L_8007BA2C:
    // 0x8007BA2C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8007BA30: addiu       $t4, $t4, 0x6924
    ctx->r12 = ADD32(ctx->r12, 0X6924);
    // 0x8007BA34: lh          $t8, 0x0($t4)
    ctx->r24 = MEM_H(ctx->r12, 0X0);
    // 0x8007BA38: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x8007BA3C: beq         $t8, $zero, L_8007BA50
    if (ctx->r24 == 0) {
        // 0x8007BA40: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_8007BA50;
    }
    // 0x8007BA40: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8007BA44: andi        $t6, $a2, 0x827
    ctx->r14 = ctx->r6 & 0X827;
    // 0x8007BA48: b           L_8007BA60
    // 0x8007BA4C: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
        goto L_8007BA60;
    // 0x8007BA4C: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
L_8007BA50:
    // 0x8007BA50: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x8007BA54: ori         $at, $at, 0x93F
    ctx->r1 = ctx->r1 | 0X93F;
    // 0x8007BA58: and         $t7, $a2, $at
    ctx->r15 = ctx->r6 & ctx->r1;
    // 0x8007BA5C: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
L_8007BA60:
    // 0x8007BA60: lw          $t9, 0x6918($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6918);
    // 0x8007BA64: lui         $a1, 0x800
    ctx->r5 = S32(0X800 << 16);
    // 0x8007BA68: nor         $t8, $t9, $zero
    ctx->r24 = ~(ctx->r25 | 0);
    // 0x8007BA6C: and         $a2, $a2, $t8
    ctx->r6 = ctx->r6 & ctx->r24;
    // 0x8007BA70: sll         $t6, $a2, 4
    ctx->r14 = S32(ctx->r6 << 4);
    // 0x8007BA74: bgez        $t6, L_8007BA8C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8007BA78: lui         $a3, 0x8012
        ctx->r7 = S32(0X8012 << 16);
            goto L_8007BA8C;
    }
    // 0x8007BA78: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8007BA7C: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8007BA80: and         $t7, $a2, $at
    ctx->r15 = ctx->r6 & ctx->r1;
    // 0x8007BA84: b           L_8007BA98
    // 0x8007BA88: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
        goto L_8007BA98;
    // 0x8007BA88: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
L_8007BA8C:
    // 0x8007BA8C: addiu       $at, $zero, -0x101
    ctx->r1 = ADD32(0, -0X101);
    // 0x8007BA90: and         $t9, $a2, $at
    ctx->r25 = ctx->r6 & ctx->r1;
    // 0x8007BA94: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
L_8007BA98:
    // 0x8007BA98: addiu       $a3, $a3, 0x6914
    ctx->r7 = ADD32(ctx->r7, 0X6914);
    // 0x8007BA9C: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x8007BAA0: nop

    // 0x8007BAA4: bne         $a2, $t5, L_8007BAB4
    if (ctx->r6 != ctx->r13) {
        // 0x8007BAA8: nop
    
            goto L_8007BAB4;
    }
    // 0x8007BAA8: nop

    // 0x8007BAAC: beq         $v1, $zero, L_8007BEA4
    if (ctx->r3 == 0) {
        // 0x8007BAB0: nop
    
            goto L_8007BEA4;
    }
    // 0x8007BAB0: nop

L_8007BAB4:
    // 0x8007BAB4: beq         $t0, $zero, L_8007BAE0
    if (ctx->r8 == 0) {
        // 0x8007BAB8: and         $t0, $a2, $a1
        ctx->r8 = ctx->r6 & ctx->r5;
            goto L_8007BAE0;
    }
    // 0x8007BAB8: and         $t0, $a2, $a1
    ctx->r8 = ctx->r6 & ctx->r5;
    // 0x8007BABC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BAC0: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8007BAC4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007BAC8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007BACC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007BAD0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8007BAD4: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x8007BAD8: nop

    // 0x8007BADC: and         $t0, $a2, $a1
    ctx->r8 = ctx->r6 & ctx->r5;
L_8007BAE0:
    // 0x8007BAE0: and         $t7, $t5, $a1
    ctx->r15 = ctx->r13 & ctx->r5;
    // 0x8007BAE4: bne         $t7, $t0, L_8007BAFC
    if (ctx->r15 != ctx->r8) {
        // 0x8007BAE8: nop
    
            goto L_8007BAFC;
    }
    // 0x8007BAE8: nop

    // 0x8007BAEC: lh          $t9, 0x0($t3)
    ctx->r25 = MEM_H(ctx->r11, 0X0);
    // 0x8007BAF0: nop

    // 0x8007BAF4: beq         $t9, $zero, L_8007BB68
    if (ctx->r25 == 0) {
        // 0x8007BAF8: andi        $t9, $a2, 0x2
        ctx->r25 = ctx->r6 & 0X2;
            goto L_8007BB68;
    }
    // 0x8007BAF8: andi        $t9, $a2, 0x2
    ctx->r25 = ctx->r6 & 0X2;
L_8007BAFC:
    // 0x8007BAFC: bne         $t0, $zero, L_8007BB14
    if (ctx->r8 != 0) {
        // 0x8007BB00: lui         $t7, 0xB600
        ctx->r15 = S32(0XB600 << 16);
            goto L_8007BB14;
    }
    // 0x8007BB00: lui         $t7, 0xB600
    ctx->r15 = S32(0XB600 << 16);
    // 0x8007BB04: lh          $t8, 0x0($t4)
    ctx->r24 = MEM_H(ctx->r12, 0X0);
    // 0x8007BB08: nop

    // 0x8007BB0C: beq         $t8, $zero, L_8007BB38
    if (ctx->r24 == 0) {
        // 0x8007BB10: nop
    
            goto L_8007BB38;
    }
    // 0x8007BB10: nop

L_8007BB14:
    // 0x8007BB14: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BB18: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x8007BB1C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007BB20: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007BB24: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8007BB28: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007BB2C: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x8007BB30: b           L_8007BB68
    // 0x8007BB34: andi        $t9, $a2, 0x2
    ctx->r25 = ctx->r6 & 0X2;
        goto L_8007BB68;
    // 0x8007BB34: andi        $t9, $a2, 0x2
    ctx->r25 = ctx->r6 & 0X2;
L_8007BB38:
    // 0x8007BB38: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BB3C: lui         $v1, 0xB700
    ctx->r3 = S32(0XB700 << 16);
    // 0x8007BB40: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8007BB44: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007BB48: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007BB4C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8007BB50: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x8007BB54: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x8007BB58: sw          $v1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r3;
    // 0x8007BB5C: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x8007BB60: nop

    // 0x8007BB64: andi        $t9, $a2, 0x2
    ctx->r25 = ctx->r6 & 0X2;
L_8007BB68:
    // 0x8007BB68: andi        $t8, $t5, 0x2
    ctx->r24 = ctx->r13 & 0X2;
    // 0x8007BB6C: lui         $v1, 0xB700
    ctx->r3 = S32(0XB700 << 16);
    // 0x8007BB70: bne         $t8, $t9, L_8007BB88
    if (ctx->r24 != ctx->r25) {
        // 0x8007BB74: sw          $t9, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r25;
            goto L_8007BB88;
    }
    // 0x8007BB74: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x8007BB78: lh          $t6, 0x0($t3)
    ctx->r14 = MEM_H(ctx->r11, 0X0);
    // 0x8007BB7C: nop

    // 0x8007BB80: beq         $t6, $zero, L_8007BBCC
    if (ctx->r14 == 0) {
        // 0x8007BB84: nop
    
            goto L_8007BBCC;
    }
    // 0x8007BB84: nop

L_8007BB88:
    // 0x8007BB88: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8007BB8C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8007BB90: beq         $t9, $zero, L_8007BBB4
    if (ctx->r25 == 0) {
        // 0x8007BB94: nop
    
            goto L_8007BBB4;
    }
    // 0x8007BB94: nop

    // 0x8007BB98: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BB9C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8007BBA0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007BBA4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007BBA8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8007BBAC: b           L_8007BBCC
    // 0x8007BBB0: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
        goto L_8007BBCC;
    // 0x8007BBB0: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
L_8007BBB4:
    // 0x8007BBB4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BBB8: lui         $t9, 0xB600
    ctx->r25 = S32(0XB600 << 16);
    // 0x8007BBBC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007BBC0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007BBC4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8007BBC8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_8007BBCC:
    // 0x8007BBCC: lh          $t7, 0x0($t2)
    ctx->r15 = MEM_H(ctx->r10, 0X0);
    // 0x8007BBD0: sh          $zero, 0x0($t3)
    MEM_H(0X0, ctx->r11) = 0;
    // 0x8007BBD4: bne         $t7, $zero, L_8007BC50
    if (ctx->r15 != 0) {
        // 0x8007BBD8: sw          $a2, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r6;
            goto L_8007BC50;
    }
    // 0x8007BBD8: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
    // 0x8007BBDC: beq         $t0, $zero, L_8007BC1C
    if (ctx->r8 == 0) {
        // 0x8007BBE0: lui         $t6, 0x702
        ctx->r14 = S32(0X702 << 16);
            goto L_8007BC1C;
    }
    // 0x8007BBE0: lui         $t6, 0x702
    ctx->r14 = S32(0X702 << 16);
    // 0x8007BBE4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BBE8: lui         $t9, 0x702
    ctx->r25 = S32(0X702 << 16);
    // 0x8007BBEC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007BBF0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007BBF4: ori         $t9, $t9, 0x10
    ctx->r25 = ctx->r25 | 0X10;
    // 0x8007BBF8: andi        $t8, $a2, 0x3
    ctx->r24 = ctx->r6 & 0X3;
    // 0x8007BBFC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8007BC00: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8007BC04: sll         $t7, $t8, 4
    ctx->r15 = S32(ctx->r24 << 4);
    // 0x8007BC08: addu        $t6, $t7, $t1
    ctx->r14 = ADD32(ctx->r15, ctx->r9);
    // 0x8007BC0C: addiu       $t9, $t9, -0xB98
    ctx->r25 = ADD32(ctx->r25, -0XB98);
    // 0x8007BC10: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x8007BC14: b           L_8007BEA4
    // 0x8007BC18: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
        goto L_8007BEA4;
    // 0x8007BC18: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
L_8007BC1C:
    // 0x8007BC1C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BC20: ori         $t6, $t6, 0x10
    ctx->r14 = ctx->r14 | 0X10;
    // 0x8007BC24: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007BC28: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007BC2C: andi        $t9, $a2, 0xF
    ctx->r25 = ctx->r6 & 0XF;
    // 0x8007BC30: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8007BC34: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8007BC38: sll         $t8, $t9, 4
    ctx->r24 = S32(ctx->r25 << 4);
    // 0x8007BC3C: addu        $t7, $t8, $t1
    ctx->r15 = ADD32(ctx->r24, ctx->r9);
    // 0x8007BC40: addiu       $t6, $t6, -0xB58
    ctx->r14 = ADD32(ctx->r14, -0XB58);
    // 0x8007BC44: addu        $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // 0x8007BC48: b           L_8007BEA4
    // 0x8007BC4C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
        goto L_8007BEA4;
    // 0x8007BC4C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
L_8007BC50:
    // 0x8007BC50: lh          $t8, 0x0($t4)
    ctx->r24 = MEM_H(ctx->r12, 0X0);
    // 0x8007BC54: andi        $t7, $a2, 0x800
    ctx->r15 = ctx->r6 & 0X800;
    // 0x8007BC58: beq         $t8, $zero, L_8007BD18
    if (ctx->r24 == 0) {
        // 0x8007BC5C: andi        $t9, $a2, 0x800
        ctx->r25 = ctx->r6 & 0X800;
            goto L_8007BD18;
    }
    // 0x8007BC5C: andi        $t9, $a2, 0x800
    ctx->r25 = ctx->r6 & 0X800;
    // 0x8007BC60: beq         $t7, $zero, L_8007BCD8
    if (ctx->r15 == 0) {
        // 0x8007BC64: andi        $t6, $a2, 0x20
        ctx->r14 = ctx->r6 & 0X20;
            goto L_8007BCD8;
    }
    // 0x8007BC64: andi        $t6, $a2, 0x20
    ctx->r14 = ctx->r6 & 0X20;
    // 0x8007BC68: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8007BC6C: andi        $t9, $a2, 0x1
    ctx->r25 = ctx->r6 & 0X1;
    // 0x8007BC70: beq         $t6, $zero, L_8007BCD4
    if (ctx->r14 == 0) {
        // 0x8007BC74: andi        $t8, $a2, 0x4
        ctx->r24 = ctx->r6 & 0X4;
            goto L_8007BCD4;
    }
    // 0x8007BC74: andi        $t8, $a2, 0x4
    ctx->r24 = ctx->r6 & 0X4;
    // 0x8007BC78: beq         $t9, $zero, L_8007BC84
    if (ctx->r25 == 0) {
        // 0x8007BC7C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8007BC84;
    }
    // 0x8007BC7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8007BC80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8007BC84:
    // 0x8007BC84: beq         $t8, $zero, L_8007BC94
    if (ctx->r24 == 0) {
        // 0x8007BC88: andi        $t6, $a2, 0x20
        ctx->r14 = ctx->r6 & 0X20;
            goto L_8007BC94;
    }
    // 0x8007BC88: andi        $t6, $a2, 0x20
    ctx->r14 = ctx->r6 & 0X20;
    // 0x8007BC8C: ori         $t7, $a1, 0x2
    ctx->r15 = ctx->r5 | 0X2;
    // 0x8007BC90: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
L_8007BC94:
    // 0x8007BC94: beq         $t6, $zero, L_8007BCA4
    if (ctx->r14 == 0) {
        // 0x8007BC98: lui         $t7, 0x702
        ctx->r15 = S32(0X702 << 16);
            goto L_8007BCA4;
    }
    // 0x8007BC98: lui         $t7, 0x702
    ctx->r15 = S32(0X702 << 16);
    // 0x8007BC9C: ori         $t9, $a1, 0x4
    ctx->r25 = ctx->r5 | 0X4;
    // 0x8007BCA0: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
L_8007BCA4:
    // 0x8007BCA4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BCA8: ori         $t7, $t7, 0x10
    ctx->r15 = ctx->r15 | 0X10;
    // 0x8007BCAC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007BCB0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007BCB4: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8007BCB8: sll         $t6, $a1, 4
    ctx->r14 = S32(ctx->r5 << 4);
    // 0x8007BCBC: addu        $t9, $t6, $t1
    ctx->r25 = ADD32(ctx->r14, ctx->r9);
    // 0x8007BCC0: addiu       $t8, $t8, -0xA58
    ctx->r24 = ADD32(ctx->r24, -0XA58);
    // 0x8007BCC4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007BCC8: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x8007BCCC: b           L_8007BEA4
    // 0x8007BCD0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
        goto L_8007BEA4;
    // 0x8007BCD0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
L_8007BCD4:
    // 0x8007BCD4: andi        $t6, $a2, 0x20
    ctx->r14 = ctx->r6 & 0X20;
L_8007BCD8:
    // 0x8007BCD8: beq         $t6, $zero, L_8007BCE4
    if (ctx->r14 == 0) {
        // 0x8007BCDC: xori        $t9, $a2, 0x20
        ctx->r25 = ctx->r6 ^ 0X20;
            goto L_8007BCE4;
    }
    // 0x8007BCDC: xori        $t9, $a2, 0x20
    ctx->r25 = ctx->r6 ^ 0X20;
    // 0x8007BCE0: ori         $a2, $t9, 0x8
    ctx->r6 = ctx->r25 | 0X8;
L_8007BCE4:
    // 0x8007BCE4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BCE8: lui         $t6, 0x702
    ctx->r14 = S32(0X702 << 16);
    // 0x8007BCEC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007BCF0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007BCF4: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8007BCF8: ori         $t6, $t6, 0x10
    ctx->r14 = ctx->r14 | 0X10;
    // 0x8007BCFC: sll         $t9, $a2, 4
    ctx->r25 = S32(ctx->r6 << 4);
    // 0x8007BD00: addu        $t8, $t9, $t1
    ctx->r24 = ADD32(ctx->r25, ctx->r9);
    // 0x8007BD04: addiu       $t7, $t7, -0x9D8
    ctx->r15 = ADD32(ctx->r15, -0X9D8);
    // 0x8007BD08: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8007BD0C: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x8007BD10: b           L_8007BEA4
    // 0x8007BD14: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
        goto L_8007BEA4;
    // 0x8007BD14: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
L_8007BD18:
    // 0x8007BD18: beq         $t9, $zero, L_8007BDA0
    if (ctx->r25 == 0) {
        // 0x8007BD1C: andi        $t6, $a2, 0x10
        ctx->r14 = ctx->r6 & 0X10;
            goto L_8007BDA0;
    }
    // 0x8007BD1C: andi        $t6, $a2, 0x10
    ctx->r14 = ctx->r6 & 0X10;
    // 0x8007BD20: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x8007BD24: andi        $t7, $a2, 0x1
    ctx->r15 = ctx->r6 & 0X1;
    // 0x8007BD28: beq         $t8, $zero, L_8007BDA0
    if (ctx->r24 == 0) {
        // 0x8007BD2C: nop
    
            goto L_8007BDA0;
    }
    // 0x8007BD2C: nop

    // 0x8007BD30: beq         $t7, $zero, L_8007BD3C
    if (ctx->r15 == 0) {
        // 0x8007BD34: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8007BD3C;
    }
    // 0x8007BD34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8007BD38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8007BD3C:
    // 0x8007BD3C: andi        $t6, $a2, 0x4
    ctx->r14 = ctx->r6 & 0X4;
    // 0x8007BD40: beq         $t6, $zero, L_8007BD50
    if (ctx->r14 == 0) {
        // 0x8007BD44: andi        $t8, $a2, 0x8
        ctx->r24 = ctx->r6 & 0X8;
            goto L_8007BD50;
    }
    // 0x8007BD44: andi        $t8, $a2, 0x8
    ctx->r24 = ctx->r6 & 0X8;
    // 0x8007BD48: ori         $t9, $a1, 0x2
    ctx->r25 = ctx->r5 | 0X2;
    // 0x8007BD4C: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
L_8007BD50:
    // 0x8007BD50: beq         $t8, $zero, L_8007BD60
    if (ctx->r24 == 0) {
        // 0x8007BD54: andi        $t6, $a2, 0x20
        ctx->r14 = ctx->r6 & 0X20;
            goto L_8007BD60;
    }
    // 0x8007BD54: andi        $t6, $a2, 0x20
    ctx->r14 = ctx->r6 & 0X20;
    // 0x8007BD58: ori         $t7, $a1, 0x4
    ctx->r15 = ctx->r5 | 0X4;
    // 0x8007BD5C: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
L_8007BD60:
    // 0x8007BD60: beq         $t6, $zero, L_8007BD70
    if (ctx->r14 == 0) {
        // 0x8007BD64: lui         $t7, 0x702
        ctx->r15 = S32(0X702 << 16);
            goto L_8007BD70;
    }
    // 0x8007BD64: lui         $t7, 0x702
    ctx->r15 = S32(0X702 << 16);
    // 0x8007BD68: ori         $t9, $a1, 0x8
    ctx->r25 = ctx->r5 | 0X8;
    // 0x8007BD6C: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
L_8007BD70:
    // 0x8007BD70: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BD74: ori         $t7, $t7, 0x10
    ctx->r15 = ctx->r15 | 0X10;
    // 0x8007BD78: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007BD7C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007BD80: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8007BD84: sll         $t6, $a1, 4
    ctx->r14 = S32(ctx->r5 << 4);
    // 0x8007BD88: addu        $t9, $t6, $t1
    ctx->r25 = ADD32(ctx->r14, ctx->r9);
    // 0x8007BD8C: addiu       $t8, $t8, -0xC98
    ctx->r24 = ADD32(ctx->r24, -0XC98);
    // 0x8007BD90: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007BD94: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x8007BD98: b           L_8007BEA4
    // 0x8007BD9C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
        goto L_8007BEA4;
    // 0x8007BD9C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
L_8007BDA0:
    // 0x8007BDA0: beq         $t6, $zero, L_8007BDF0
    if (ctx->r14 == 0) {
        // 0x8007BDA4: addiu       $at, $zero, -0x801
        ctx->r1 = ADD32(0, -0X801);
            goto L_8007BDF0;
    }
    // 0x8007BDA4: addiu       $at, $zero, -0x801
    ctx->r1 = ADD32(0, -0X801);
    // 0x8007BDA8: andi        $v0, $a2, 0x7
    ctx->r2 = ctx->r6 & 0X7;
    // 0x8007BDAC: andi        $t9, $a2, 0x8
    ctx->r25 = ctx->r6 & 0X8;
    // 0x8007BDB0: beq         $t9, $zero, L_8007BDBC
    if (ctx->r25 == 0) {
        // 0x8007BDB4: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8007BDBC;
    }
    // 0x8007BDB4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8007BDB8: ori         $a1, $v0, 0x8
    ctx->r5 = ctx->r2 | 0X8;
L_8007BDBC:
    // 0x8007BDBC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BDC0: lui         $t7, 0x702
    ctx->r15 = S32(0X702 << 16);
    // 0x8007BDC4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007BDC8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007BDCC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8007BDD0: ori         $t7, $t7, 0x10
    ctx->r15 = ctx->r15 | 0X10;
    // 0x8007BDD4: sll         $t6, $a1, 4
    ctx->r14 = S32(ctx->r5 << 4);
    // 0x8007BDD8: addu        $t9, $t6, $t1
    ctx->r25 = ADD32(ctx->r14, ctx->r9);
    // 0x8007BDDC: addiu       $t8, $t8, -0xD98
    ctx->r24 = ADD32(ctx->r24, -0XD98);
    // 0x8007BDE0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007BDE4: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x8007BDE8: b           L_8007BEA4
    // 0x8007BDEC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
        goto L_8007BEA4;
    // 0x8007BDEC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
L_8007BDF0:
    // 0x8007BDF0: and         $t6, $a2, $at
    ctx->r14 = ctx->r6 & ctx->r1;
    // 0x8007BDF4: and         $t9, $t6, $a1
    ctx->r25 = ctx->r14 & ctx->r5;
    // 0x8007BDF8: beq         $t9, $zero, L_8007BE74
    if (ctx->r25 == 0) {
        // 0x8007BDFC: or          $a2, $t6, $zero
        ctx->r6 = ctx->r14 | 0;
            goto L_8007BE74;
    }
    // 0x8007BDFC: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x8007BE00: andi        $v0, $t6, 0x3
    ctx->r2 = ctx->r14 & 0X3;
    // 0x8007BE04: andi        $t8, $t6, 0x100
    ctx->r24 = ctx->r14 & 0X100;
    // 0x8007BE08: beq         $t8, $zero, L_8007BE18
    if (ctx->r24 == 0) {
        // 0x8007BE0C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8007BE18;
    }
    // 0x8007BE0C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8007BE10: b           L_8007BE40
    // 0x8007BE14: ori         $a1, $v0, 0x4
    ctx->r5 = ctx->r2 | 0X4;
        goto L_8007BE40;
    // 0x8007BE14: ori         $a1, $v0, 0x4
    ctx->r5 = ctx->r2 | 0X4;
L_8007BE18:
    // 0x8007BE18: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BE1C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007BE20: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007BE24: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007BE28: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8007BE2C: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8007BE30: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x8007BE34: nop

    // 0x8007BE38: ori         $t8, $t9, 0x2
    ctx->r24 = ctx->r25 | 0X2;
    // 0x8007BE3C: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
L_8007BE40:
    // 0x8007BE40: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BE44: lui         $t6, 0x702
    ctx->r14 = S32(0X702 << 16);
    // 0x8007BE48: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007BE4C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007BE50: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8007BE54: ori         $t6, $t6, 0x10
    ctx->r14 = ctx->r14 | 0X10;
    // 0x8007BE58: sll         $t9, $a1, 4
    ctx->r25 = S32(ctx->r5 << 4);
    // 0x8007BE5C: addu        $t8, $t9, $t1
    ctx->r24 = ADD32(ctx->r25, ctx->r9);
    // 0x8007BE60: addiu       $t7, $t7, -0x12B8
    ctx->r15 = ADD32(ctx->r15, -0X12B8);
    // 0x8007BE64: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8007BE68: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x8007BE6C: b           L_8007BEA4
    // 0x8007BE70: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
        goto L_8007BEA4;
    // 0x8007BE70: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
L_8007BE74:
    // 0x8007BE74: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BE78: lui         $t8, 0x702
    ctx->r24 = S32(0X702 << 16);
    // 0x8007BE7C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007BE80: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007BE84: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8007BE88: ori         $t8, $t8, 0x10
    ctx->r24 = ctx->r24 | 0X10;
    // 0x8007BE8C: sll         $t7, $a2, 4
    ctx->r15 = S32(ctx->r6 << 4);
    // 0x8007BE90: addu        $t6, $t7, $t1
    ctx->r14 = ADD32(ctx->r15, ctx->r9);
    // 0x8007BE94: addiu       $t9, $t9, -0x1198
    ctx->r25 = ADD32(ctx->r25, -0X1198);
    // 0x8007BE98: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007BE9C: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x8007BEA0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
L_8007BEA4:
    // 0x8007BEA4: jr          $ra
    // 0x8007BEA8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8007BEA8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void material_set_blinking_lights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007BEAC: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8007BEB0: beq         $a3, $zero, L_8007BEE8
    if (ctx->r7 == 0) {
        // 0x8007BEB4: sw          $a2, 0x78($sp)
        MEM_W(0X78, ctx->r29) = ctx->r6;
            goto L_8007BEE8;
    }
    // 0x8007BEB4: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    // 0x8007BEB8: lhu         $t6, 0x12($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X12);
    // 0x8007BEBC: nop

    // 0x8007BEC0: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x8007BEC4: slt         $at, $a3, $t7
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8007BEC8: beq         $at, $zero, L_8007BEE8
    if (ctx->r1 == 0) {
        // 0x8007BECC: nop
    
            goto L_8007BEE8;
    }
    // 0x8007BECC: nop

    // 0x8007BED0: lh          $t9, 0x16($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X16);
    // 0x8007BED4: sra         $t8, $a3, 16
    ctx->r24 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8007BED8: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007BEDC: mflo        $t6
    ctx->r14 = lo;
    // 0x8007BEE0: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
    // 0x8007BEE4: nop

L_8007BEE8:
    // 0x8007BEE8: lbu         $t7, 0x0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X0);
    // 0x8007BEEC: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8007BEF0: bne         $t7, $at, L_8007C0C0
    if (ctx->r15 != ctx->r1) {
        // 0x8007BEF4: lui         $a2, 0xB700
        ctx->r6 = S32(0XB700 << 16);
            goto L_8007C0C0;
    }
    // 0x8007BEF4: lui         $a2, 0xB700
    ctx->r6 = S32(0XB700 << 16);
    // 0x8007BEF8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BEFC: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x8007BF00: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007BF04: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007BF08: addu        $t9, $a1, $t1
    ctx->r25 = ADD32(ctx->r5, ctx->r9);
    // 0x8007BF0C: lui         $a3, 0xFD10
    ctx->r7 = S32(0XFD10 << 16);
    // 0x8007BF10: addiu       $t6, $t9, 0x20
    ctx->r14 = ADD32(ctx->r25, 0X20);
    // 0x8007BF14: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8007BF18: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x8007BF1C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BF20: lui         $t9, 0x701
    ctx->r25 = S32(0X701 << 16);
    // 0x8007BF24: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007BF28: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007BF2C: lui         $t8, 0xF510
    ctx->r24 = S32(0XF510 << 16);
    // 0x8007BF30: ori         $t8, $t8, 0x100
    ctx->r24 = ctx->r24 | 0X100;
    // 0x8007BF34: ori         $t9, $t9, 0x60
    ctx->r25 = ctx->r25 | 0X60;
    // 0x8007BF38: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8007BF3C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007BF40: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BF44: lui         $t2, 0xE600
    ctx->r10 = S32(0XE600 << 16);
    // 0x8007BF48: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007BF4C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007BF50: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007BF54: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8007BF58: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BF5C: lui         $t8, 0x73F
    ctx->r24 = S32(0X73F << 16);
    // 0x8007BF60: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007BF64: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007BF68: lui         $t3, 0xF300
    ctx->r11 = S32(0XF300 << 16);
    // 0x8007BF6C: ori         $t8, $t8, 0xF080
    ctx->r24 = ctx->r24 | 0XF080;
    // 0x8007BF70: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8007BF74: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8007BF78: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BF7C: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x8007BF80: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007BF84: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007BF88: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007BF8C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8007BF90: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BF94: lui         $t9, 0x101
    ctx->r25 = S32(0X101 << 16);
    // 0x8007BF98: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x8007BF9C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007BFA0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007BFA4: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8007BFA8: lui         $t7, 0xF510
    ctx->r15 = S32(0XF510 << 16);
    // 0x8007BFAC: ori         $t7, $t7, 0x2100
    ctx->r15 = ctx->r15 | 0X2100;
    // 0x8007BFB0: ori         $t9, $t9, 0x60
    ctx->r25 = ctx->r25 | 0X60;
    // 0x8007BFB4: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x8007BFB8: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8007BFBC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BFC0: lui         $t9, 0x10F
    ctx->r25 = S32(0X10F << 16);
    // 0x8007BFC4: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x8007BFC8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007BFCC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007BFD0: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x8007BFD4: ori         $t9, $t9, 0xC03C
    ctx->r25 = ctx->r25 | 0XC03C;
    // 0x8007BFD8: lui         $t4, 0xF200
    ctx->r12 = S32(0XF200 << 16);
    // 0x8007BFDC: sw          $t4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r12;
    // 0x8007BFE0: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x8007BFE4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BFE8: addu        $t6, $a1, $t1
    ctx->r14 = ADD32(ctx->r5, ctx->r9);
    // 0x8007BFEC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007BFF0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007BFF4: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x8007BFF8: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x8007BFFC: addiu       $t9, $t6, 0x820
    ctx->r25 = ADD32(ctx->r14, 0X820);
    // 0x8007C000: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8007C004: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C008: lui         $t6, 0x701
    ctx->r14 = S32(0X701 << 16);
    // 0x8007C00C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007C010: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007C014: ori         $t6, $t6, 0x60
    ctx->r14 = ctx->r14 | 0X60;
    // 0x8007C018: lui         $t8, 0xF510
    ctx->r24 = S32(0XF510 << 16);
    // 0x8007C01C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007C020: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8007C024: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C028: lui         $t6, 0x73F
    ctx->r14 = S32(0X73F << 16);
    // 0x8007C02C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007C030: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007C034: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007C038: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8007C03C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C040: ori         $t6, $t6, 0xF080
    ctx->r14 = ctx->r14 | 0XF080;
    // 0x8007C044: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8007C048: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007C04C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007C050: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8007C054: nop

    // 0x8007C058: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
    // 0x8007C05C: sw          $t6, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r14;
    // 0x8007C060: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C064: lui         $t8, 0xF510
    ctx->r24 = S32(0XF510 << 16);
    // 0x8007C068: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x8007C06C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007C070: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007C074: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8007C078: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x8007C07C: sw          $t0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r8;
    // 0x8007C080: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x8007C084: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C088: ori         $t9, $t9, 0x60
    ctx->r25 = ctx->r25 | 0X60;
    // 0x8007C08C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007C090: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007C094: ori         $t8, $t8, 0x2000
    ctx->r24 = ctx->r24 | 0X2000;
    // 0x8007C098: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007C09C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8007C0A0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C0A4: lui         $t6, 0xF
    ctx->r14 = S32(0XF << 16);
    // 0x8007C0A8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007C0AC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007C0B0: ori         $t6, $t6, 0xC03C
    ctx->r14 = ctx->r14 | 0XC03C;
    // 0x8007C0B4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8007C0B8: b           L_8007C2A0
    // 0x8007C0BC: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
        goto L_8007C2A0;
    // 0x8007C0BC: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_8007C0C0:
    // 0x8007C0C0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C0C4: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x8007C0C8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007C0CC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007C0D0: addu        $t9, $a1, $t1
    ctx->r25 = ADD32(ctx->r5, ctx->r9);
    // 0x8007C0D4: lui         $a3, 0xFD10
    ctx->r7 = S32(0XFD10 << 16);
    // 0x8007C0D8: addiu       $t7, $t9, 0x20
    ctx->r15 = ADD32(ctx->r25, 0X20);
    // 0x8007C0DC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8007C0E0: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x8007C0E4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C0E8: lui         $t9, 0x701
    ctx->r25 = S32(0X701 << 16);
    // 0x8007C0EC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007C0F0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007C0F4: lui         $t8, 0xF510
    ctx->r24 = S32(0XF510 << 16);
    // 0x8007C0F8: ori         $t8, $t8, 0x100
    ctx->r24 = ctx->r24 | 0X100;
    // 0x8007C0FC: ori         $t9, $t9, 0x4050
    ctx->r25 = ctx->r25 | 0X4050;
    // 0x8007C100: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8007C104: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007C108: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C10C: lui         $t2, 0xE600
    ctx->r10 = S32(0XE600 << 16);
    // 0x8007C110: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007C114: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007C118: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007C11C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8007C120: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C124: lui         $t3, 0xF300
    ctx->r11 = S32(0XF300 << 16);
    // 0x8007C128: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007C12C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007C130: lui         $t8, 0x73F
    ctx->r24 = S32(0X73F << 16);
    // 0x8007C134: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8007C138: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x8007C13C: ori         $t8, $t8, 0xF100
    ctx->r24 = ctx->r24 | 0XF100;
    // 0x8007C140: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8007C144: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C148: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x8007C14C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8007C150: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007C154: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007C158: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8007C15C: lui         $t8, 0xF510
    ctx->r24 = S32(0XF510 << 16);
    // 0x8007C160: sw          $t0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r8;
    // 0x8007C164: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x8007C168: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C16C: lui         $t7, 0x101
    ctx->r15 = S32(0X101 << 16);
    // 0x8007C170: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8007C174: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007C178: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007C17C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8007C180: ori         $t7, $t7, 0x4050
    ctx->r15 = ctx->r15 | 0X4050;
    // 0x8007C184: ori         $t8, $t8, 0x1100
    ctx->r24 = ctx->r24 | 0X1100;
    // 0x8007C188: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8007C18C: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x8007C190: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C194: lui         $t4, 0xF200
    ctx->r12 = S32(0XF200 << 16);
    // 0x8007C198: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x8007C19C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007C1A0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007C1A4: lw          $t8, 0x14($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14);
    // 0x8007C1A8: lui         $t7, 0x107
    ctx->r15 = S32(0X107 << 16);
    // 0x8007C1AC: sw          $t4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r12;
    // 0x8007C1B0: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x8007C1B4: ori         $t7, $t7, 0xC07C
    ctx->r15 = ctx->r15 | 0XC07C;
    // 0x8007C1B8: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x8007C1BC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C1C0: addu        $t8, $a1, $t1
    ctx->r24 = ADD32(ctx->r5, ctx->r9);
    // 0x8007C1C4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007C1C8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007C1CC: addiu       $t7, $t8, 0x820
    ctx->r15 = ADD32(ctx->r24, 0X820);
    // 0x8007C1D0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8007C1D4: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x8007C1D8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C1DC: lui         $t8, 0x701
    ctx->r24 = S32(0X701 << 16);
    // 0x8007C1E0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007C1E4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007C1E8: ori         $t8, $t8, 0x4050
    ctx->r24 = ctx->r24 | 0X4050;
    // 0x8007C1EC: lui         $t6, 0xF510
    ctx->r14 = S32(0XF510 << 16);
    // 0x8007C1F0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8007C1F4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8007C1F8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C1FC: lui         $t8, 0x73F
    ctx->r24 = S32(0X73F << 16);
    // 0x8007C200: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007C204: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007C208: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007C20C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8007C210: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C214: ori         $t8, $t8, 0xF100
    ctx->r24 = ctx->r24 | 0XF100;
    // 0x8007C218: sw          $v0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r2;
    // 0x8007C21C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007C220: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007C224: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8007C228: nop

    // 0x8007C22C: sw          $t3, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r11;
    // 0x8007C230: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8007C234: nop

    // 0x8007C238: sw          $t8, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r24;
    // 0x8007C23C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C240: nop

    // 0x8007C244: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
    // 0x8007C248: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007C24C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007C250: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x8007C254: lui         $t9, 0xF510
    ctx->r25 = S32(0XF510 << 16);
    // 0x8007C258: sw          $t0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r8;
    // 0x8007C25C: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x8007C260: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x8007C264: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x8007C268: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C26C: ori         $t6, $t6, 0x4050
    ctx->r14 = ctx->r14 | 0X4050;
    // 0x8007C270: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007C274: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007C278: ori         $t9, $t9, 0x1000
    ctx->r25 = ctx->r25 | 0X1000;
    // 0x8007C27C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8007C280: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8007C284: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C288: lui         $t7, 0x7
    ctx->r15 = S32(0X7 << 16);
    // 0x8007C28C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007C290: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007C294: ori         $t7, $t7, 0xC07C
    ctx->r15 = ctx->r15 | 0XC07C;
    // 0x8007C298: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8007C29C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_8007C2A0:
    // 0x8007C2A0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C2A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007C2A8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007C2AC: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007C2B0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007C2B4: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8007C2B8: sw          $zero, 0x691C($at)
    MEM_W(0X691C, ctx->r1) = 0;
    // 0x8007C2BC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C2C0: andi        $t6, $t5, 0x1F
    ctx->r14 = ctx->r13 & 0X1F;
    // 0x8007C2C4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007C2C8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007C2CC: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x8007C2D0: andi        $t9, $t6, 0x2
    ctx->r25 = ctx->r14 & 0X2;
    // 0x8007C2D4: or          $t5, $t6, $zero
    ctx->r13 = ctx->r14 | 0;
    // 0x8007C2D8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8007C2DC: beq         $t9, $zero, L_8007C300
    if (ctx->r25 == 0) {
        // 0x8007C2E0: sw          $a2, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r6;
            goto L_8007C300;
    }
    // 0x8007C2E0: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x8007C2E4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C2E8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8007C2EC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007C2F0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007C2F4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8007C2F8: b           L_8007C31C
    // 0x8007C2FC: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
        goto L_8007C31C;
    // 0x8007C2FC: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
L_8007C300:
    // 0x8007C300: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C304: lui         $t9, 0xB600
    ctx->r25 = S32(0XB600 << 16);
    // 0x8007C308: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007C30C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007C310: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007C314: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8007C318: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_8007C31C:
    // 0x8007C31C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8007C320: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007C324: sh          $t8, 0x6922($at)
    MEM_H(0X6922, ctx->r1) = ctx->r24;
    // 0x8007C328: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007C32C: sw          $zero, 0x6914($at)
    MEM_W(0X6914, ctx->r1) = 0;
    // 0x8007C330: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C334: lui         $t9, 0x702
    ctx->r25 = S32(0X702 << 16);
    // 0x8007C338: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007C33C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007C340: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8007C344: ori         $t9, $t9, 0x10
    ctx->r25 = ctx->r25 | 0X10;
    // 0x8007C348: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007C34C: sll         $t6, $t5, 4
    ctx->r14 = S32(ctx->r13 << 4);
    // 0x8007C350: addu        $t8, $t6, $at
    ctx->r24 = ADD32(ctx->r14, ctx->r1);
    // 0x8007C354: addiu       $t7, $t7, -0x8D8
    ctx->r15 = ADD32(ctx->r15, -0X8D8);
    // 0x8007C358: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8007C35C: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x8007C360: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x8007C364: jr          $ra
    // 0x8007C368: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    return;
    // 0x8007C368: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
;}
RECOMP_FUNC void sprite_opaque(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C36C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007C370: sw          $a0, -0x12BC($at)
    MEM_W(-0X12BC, ctx->r1) = ctx->r4;
    // 0x8007C374: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007C378: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007C37C: jr          $ra
    // 0x8007C380: sh          $t6, 0x6922($at)
    MEM_H(0X6922, ctx->r1) = ctx->r14;
    return;
    // 0x8007C380: sh          $t6, 0x6922($at)
    MEM_H(0X6922, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void material_load_simple(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C384: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8007C388: addiu       $a3, $a3, 0x6914
    ctx->r7 = ADD32(ctx->r7, 0X6914);
    // 0x8007C38C: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x8007C390: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8007C394: bne         $a1, $t6, L_8007C3AC
    if (ctx->r5 != ctx->r14) {
        // 0x8007C398: addiu       $t0, $t0, 0x6922
        ctx->r8 = ADD32(ctx->r8, 0X6922);
            goto L_8007C3AC;
    }
    // 0x8007C398: addiu       $t0, $t0, 0x6922
    ctx->r8 = ADD32(ctx->r8, 0X6922);
    // 0x8007C39C: lh          $t7, 0x0($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X0);
    // 0x8007C3A0: nop

    // 0x8007C3A4: beq         $t7, $zero, L_8007C574
    if (ctx->r15 == 0) {
        // 0x8007C3A8: nop
    
            goto L_8007C574;
    }
    // 0x8007C3A8: nop

L_8007C3AC:
    // 0x8007C3AC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C3B0: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8007C3B4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007C3B8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007C3BC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007C3C0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8007C3C4: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x8007C3C8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8007C3CC: sll         $t1, $v1, 4
    ctx->r9 = S32(ctx->r3 << 4);
    // 0x8007C3D0: bltz        $t1, L_8007C3E8
    if (SIGNED(ctx->r9) < 0) {
        // 0x8007C3D4: addiu       $t0, $t0, 0x6922
        ctx->r8 = ADD32(ctx->r8, 0X6922);
            goto L_8007C3E8;
    }
    // 0x8007C3D4: addiu       $t0, $t0, 0x6922
    ctx->r8 = ADD32(ctx->r8, 0X6922);
    // 0x8007C3D8: lh          $t2, 0x0($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X0);
    // 0x8007C3DC: nop

    // 0x8007C3E0: beq         $t2, $zero, L_8007C40C
    if (ctx->r10 == 0) {
        // 0x8007C3E4: nop
    
            goto L_8007C40C;
    }
    // 0x8007C3E4: nop

L_8007C3E8:
    // 0x8007C3E8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C3EC: lui         $t4, 0xB700
    ctx->r12 = S32(0XB700 << 16);
    // 0x8007C3F0: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8007C3F4: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8007C3F8: lui         $t5, 0x1
    ctx->r13 = S32(0X1 << 16);
    // 0x8007C3FC: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8007C400: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8007C404: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x8007C408: nop

L_8007C40C:
    // 0x8007C40C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8007C410: lw          $t7, 0x6918($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6918);
    // 0x8007C414: lui         $at, 0xF7FF
    ctx->r1 = S32(0XF7FF << 16);
    // 0x8007C418: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8007C41C: and         $t6, $a1, $at
    ctx->r14 = ctx->r5 & ctx->r1;
    // 0x8007C420: nor         $t8, $t7, $zero
    ctx->r24 = ~(ctx->r15 | 0);
    // 0x8007C424: and         $a1, $t6, $t8
    ctx->r5 = ctx->r14 & ctx->r24;
    // 0x8007C428: andi        $v0, $a1, 0x2
    ctx->r2 = ctx->r5 & 0X2;
    // 0x8007C42C: andi        $t9, $v1, 0x2
    ctx->r25 = ctx->r3 & 0X2;
    // 0x8007C430: bne         $t9, $v0, L_8007C448
    if (ctx->r25 != ctx->r2) {
        // 0x8007C434: addiu       $at, $zero, -0x801
        ctx->r1 = ADD32(0, -0X801);
            goto L_8007C448;
    }
    // 0x8007C434: addiu       $at, $zero, -0x801
    ctx->r1 = ADD32(0, -0X801);
    // 0x8007C438: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x8007C43C: nop

    // 0x8007C440: beq         $t1, $zero, L_8007C488
    if (ctx->r9 == 0) {
        // 0x8007C444: nop
    
            goto L_8007C488;
    }
    // 0x8007C444: nop

L_8007C448:
    // 0x8007C448: beq         $v0, $zero, L_8007C470
    if (ctx->r2 == 0) {
        // 0x8007C44C: lui         $t6, 0xB600
        ctx->r14 = S32(0XB600 << 16);
            goto L_8007C470;
    }
    // 0x8007C44C: lui         $t6, 0xB600
    ctx->r14 = S32(0XB600 << 16);
    // 0x8007C450: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C454: lui         $t3, 0xB700
    ctx->r11 = S32(0XB700 << 16);
    // 0x8007C458: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8007C45C: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8007C460: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8007C464: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8007C468: b           L_8007C488
    // 0x8007C46C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
        goto L_8007C488;
    // 0x8007C46C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_8007C470:
    // 0x8007C470: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C474: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8007C478: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8007C47C: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8007C480: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8007C484: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_8007C488:
    // 0x8007C488: sh          $zero, 0x0($t0)
    MEM_H(0X0, ctx->r8) = 0;
    // 0x8007C48C: sw          $a1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r5;
    // 0x8007C490: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8007C494: lw          $t9, -0x12BC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X12BC);
    // 0x8007C498: and         $t8, $a1, $at
    ctx->r24 = ctx->r5 & ctx->r1;
    // 0x8007C49C: bne         $t9, $zero, L_8007C52C
    if (ctx->r25 != 0) {
        // 0x8007C4A0: or          $a1, $t8, $zero
        ctx->r5 = ctx->r24 | 0;
            goto L_8007C52C;
    }
    // 0x8007C4A0: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x8007C4A4: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x8007C4A8: lui         $t3, 0x702
    ctx->r11 = S32(0X702 << 16);
    // 0x8007C4AC: andi        $t2, $t1, 0x200
    ctx->r10 = ctx->r9 & 0X200;
    // 0x8007C4B0: beq         $t2, $zero, L_8007C4F8
    if (ctx->r10 == 0) {
        // 0x8007C4B4: ori         $t3, $t3, 0x10
        ctx->r11 = ctx->r11 | 0X10;
            goto L_8007C4F8;
    }
    // 0x8007C4B4: ori         $t3, $t3, 0x10
    ctx->r11 = ctx->r11 | 0X10;
    // 0x8007C4B8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C4BC: sra         $t5, $t8, 1
    ctx->r13 = S32(SIGNED(ctx->r24) >> 1);
    // 0x8007C4C0: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x8007C4C4: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x8007C4C8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007C4CC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8007C4D0: addiu       $t9, $t9, -0x1238
    ctx->r25 = ADD32(ctx->r25, -0X1238);
    // 0x8007C4D4: addu        $t8, $t7, $at
    ctx->r24 = ADD32(ctx->r15, ctx->r1);
    // 0x8007C4D8: lui         $t4, 0x702
    ctx->r12 = S32(0X702 << 16);
    // 0x8007C4DC: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8007C4E0: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8007C4E4: ori         $t4, $t4, 0x10
    ctx->r12 = ctx->r12 | 0X10;
    // 0x8007C4E8: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x8007C4EC: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8007C4F0: b           L_8007C560
    // 0x8007C4F4: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
        goto L_8007C560;
    // 0x8007C4F4: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_8007C4F8:
    // 0x8007C4F8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C4FC: addiu       $t4, $a1, -0x10
    ctx->r12 = ADD32(ctx->r5, -0X10);
    // 0x8007C500: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x8007C504: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007C508: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8007C50C: addiu       $t7, $t7, -0x1218
    ctx->r15 = ADD32(ctx->r15, -0X1218);
    // 0x8007C510: addu        $t6, $t5, $at
    ctx->r14 = ADD32(ctx->r13, ctx->r1);
    // 0x8007C514: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8007C518: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8007C51C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8007C520: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8007C524: b           L_8007C560
    // 0x8007C528: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
        goto L_8007C560;
    // 0x8007C528: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_8007C52C:
    // 0x8007C52C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C530: sll         $t2, $a1, 4
    ctx->r10 = S32(ctx->r5 << 4);
    // 0x8007C534: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007C538: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8007C53C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007C540: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007C544: addiu       $t4, $t4, -0x1198
    ctx->r12 = ADD32(ctx->r12, -0X1198);
    // 0x8007C548: addu        $t3, $t2, $at
    ctx->r11 = ADD32(ctx->r10, ctx->r1);
    // 0x8007C54C: lui         $t1, 0x702
    ctx->r9 = S32(0X702 << 16);
    // 0x8007C550: ori         $t1, $t1, 0x10
    ctx->r9 = ctx->r9 | 0X10;
    // 0x8007C554: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8007C558: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8007C55C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
L_8007C560:
    // 0x8007C560: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007C564: sw          $zero, 0x691C($at)
    MEM_W(0X691C, ctx->r1) = 0;
    // 0x8007C568: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007C56C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007C570: sh          $t6, 0x6920($at)
    MEM_H(0X6920, ctx->r1) = ctx->r14;
L_8007C574:
    // 0x8007C574: jr          $ra
    // 0x8007C578: nop

    return;
    // 0x8007C578: nop

;}
RECOMP_FUNC void tex_load_sprite(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C57C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8007C580: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8007C584: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007C588: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8007C58C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8007C590: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8007C594: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8007C598: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8007C59C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8007C5A0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8007C5A4: bltz        $a0, L_8007C5C4
    if (SIGNED(ctx->r4) < 0) {
        // 0x8007C5A8: sw          $a1, 0x68FC($at)
        MEM_W(0X68FC, ctx->r1) = ctx->r5;
            goto L_8007C5C4;
    }
    // 0x8007C5A8: sw          $a1, 0x68FC($at)
    MEM_W(0X68FC, ctx->r1) = ctx->r5;
    // 0x8007C5AC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007C5B0: lw          $t6, 0x68F4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X68F4);
    // 0x8007C5B4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8007C5B8: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8007C5BC: bne         $at, $zero, L_8007C5CC
    if (ctx->r1 != 0) {
        // 0x8007C5C0: addiu       $t2, $t2, 0x68F8
        ctx->r10 = ADD32(ctx->r10, 0X68F8);
            goto L_8007C5CC;
    }
    // 0x8007C5C0: addiu       $t2, $t2, 0x68F8
    ctx->r10 = ADD32(ctx->r10, 0X68F8);
L_8007C5C4:
    // 0x8007C5C4: b           L_8007C958
    // 0x8007C5C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007C958;
    // 0x8007C5C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007C5CC:
    // 0x8007C5CC: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x8007C5D0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8007C5D4: blez        $a0, L_8007C628
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8007C5D8: or          $t1, $zero, $zero
        ctx->r9 = 0 | 0;
            goto L_8007C628;
    }
    // 0x8007C5D8: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x8007C5DC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007C5E0: lw          $v0, 0x68EC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X68EC);
    // 0x8007C5E4: nop

    // 0x8007C5E8: sll         $t8, $s0, 3
    ctx->r24 = S32(ctx->r16 << 3);
L_8007C5EC:
    // 0x8007C5EC: addu        $v1, $v0, $t8
    ctx->r3 = ADD32(ctx->r2, ctx->r24);
    // 0x8007C5F0: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8007C5F4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007C5F8: bne         $s1, $t9, L_8007C61C
    if (ctx->r17 != ctx->r25) {
        // 0x8007C5FC: slt         $at, $s0, $a0
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8007C61C;
    }
    // 0x8007C5FC: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8007C600: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8007C604: nop

    // 0x8007C608: lh          $t3, 0x4($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X4);
    // 0x8007C60C: nop

    // 0x8007C610: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8007C614: b           L_8007C958
    // 0x8007C618: sh          $t4, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r12;
        goto L_8007C958;
    // 0x8007C618: sh          $t4, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r12;
L_8007C61C:
    // 0x8007C61C: bne         $at, $zero, L_8007C5EC
    if (ctx->r1 != 0) {
        // 0x8007C620: sll         $t8, $s0, 3
        ctx->r24 = S32(ctx->r16 << 3);
            goto L_8007C5EC;
    }
    // 0x8007C620: sll         $t8, $s0, 3
    ctx->r24 = S32(ctx->r16 << 3);
    // 0x8007C624: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8007C628:
    // 0x8007C628: blez        $a0, L_8007C668
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8007C62C: addiu       $t0, $zero, -0x1
        ctx->r8 = ADD32(0, -0X1);
            goto L_8007C668;
    }
    // 0x8007C62C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8007C630: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007C634: lw          $v0, 0x68EC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X68EC);
    // 0x8007C638: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8007C63C: sll         $t6, $s0, 3
    ctx->r14 = S32(ctx->r16 << 3);
L_8007C640:
    // 0x8007C640: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x8007C644: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8007C648: nop

    // 0x8007C64C: bne         $v1, $t8, L_8007C658
    if (ctx->r3 != ctx->r24) {
        // 0x8007C650: nop
    
            goto L_8007C658;
    }
    // 0x8007C650: nop

    // 0x8007C654: or          $t0, $s0, $zero
    ctx->r8 = ctx->r16 | 0;
L_8007C658:
    // 0x8007C658: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007C65C: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8007C660: bne         $at, $zero, L_8007C640
    if (ctx->r1 != 0) {
        // 0x8007C664: sll         $t6, $s0, 3
        ctx->r14 = S32(ctx->r16 << 3);
            goto L_8007C640;
    }
    // 0x8007C664: sll         $t6, $s0, 3
    ctx->r14 = S32(ctx->r16 << 3);
L_8007C668:
    // 0x8007C668: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8007C66C: bne         $t0, $v1, L_8007C684
    if (ctx->r8 != ctx->r3) {
        // 0x8007C670: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_8007C684;
    }
    // 0x8007C670: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8007C674: addiu       $t9, $a0, 0x1
    ctx->r25 = ADD32(ctx->r4, 0X1);
    // 0x8007C678: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8007C67C: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x8007C680: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
L_8007C684:
    // 0x8007C684: lw          $t3, 0x68E8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X68E8);
    // 0x8007C688: sll         $t4, $s1, 2
    ctx->r12 = S32(ctx->r17 << 2);
    // 0x8007C68C: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
    // 0x8007C690: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x8007C694: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x8007C698: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8007C69C: lw          $s4, 0x68F0($s4)
    ctx->r20 = MEM_W(ctx->r20, 0X68F0);
    // 0x8007C6A0: sw          $s1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r17;
    // 0x8007C6A4: sb          $t1, 0x32($sp)
    MEM_B(0X32, ctx->r29) = ctx->r9;
    // 0x8007C6A8: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x8007C6AC: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x8007C6B0: subu        $a3, $t5, $a2
    ctx->r7 = SUB32(ctx->r13, ctx->r6);
    // 0x8007C6B4: jal         0x80077190
    // 0x8007C6B8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    asset_load(rdram, ctx);
        goto after_0;
    // 0x8007C6B8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_0:
    // 0x8007C6BC: lh          $a1, 0x2($s4)
    ctx->r5 = MEM_H(ctx->r20, 0X2);
    // 0x8007C6C0: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x8007C6C4: addu        $t6, $s4, $a1
    ctx->r14 = ADD32(ctx->r20, ctx->r5);
    // 0x8007C6C8: lbu         $s5, 0xC($t6)
    ctx->r21 = MEM_BU(ctx->r14, 0XC);
    // 0x8007C6CC: sll         $t3, $a1, 3
    ctx->r11 = S32(ctx->r5 << 3);
    // 0x8007C6D0: sll         $v1, $s5, 2
    ctx->r3 = S32(ctx->r21 << 2);
    // 0x8007C6D4: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x8007C6D8: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x8007C6DC: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8007C6E0: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x8007C6E4: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8007C6E8: addu        $s0, $t9, $t3
    ctx->r16 = ADD32(ctx->r25, ctx->r11);
    // 0x8007C6EC: sll         $t5, $s5, 5
    ctx->r13 = S32(ctx->r21 << 5);
    // 0x8007C6F0: addu        $s0, $s0, $t5
    ctx->r16 = ADD32(ctx->r16, ctx->r13);
    // 0x8007C6F4: jal         0x80071A90
    // 0x8007C6F8: addu        $s0, $s0, $v1
    ctx->r16 = ADD32(ctx->r16, ctx->r3);
    align16(rdram, ctx);
        goto after_1;
    // 0x8007C6F8: addu        $s0, $s0, $v1
    ctx->r16 = ADD32(ctx->r16, ctx->r3);
    after_1:
    // 0x8007C6FC: lh          $a0, 0x2($s4)
    ctx->r4 = MEM_H(ctx->r20, 0X2);
    // 0x8007C700: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x8007C704: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8007C708: jal         0x80071A90
    // 0x8007C70C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    align16(rdram, ctx);
        goto after_2;
    // 0x8007C70C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_2:
    // 0x8007C710: lui         $a1, 0xFF00
    ctx->r5 = S32(0XFF00 << 16);
    // 0x8007C714: addu        $a0, $s0, $v0
    ctx->r4 = ADD32(ctx->r16, ctx->r2);
    // 0x8007C718: jal         0x80070F50
    // 0x8007C71C: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    mempool_alloc(rdram, ctx);
        goto after_3;
    // 0x8007C71C: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    after_3:
    // 0x8007C720: bne         $v0, $zero, L_8007C750
    if (ctx->r2 != 0) {
        // 0x8007C724: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_8007C750;
    }
    // 0x8007C724: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8007C728: lb          $t7, 0x32($sp)
    ctx->r15 = MEM_B(ctx->r29, 0X32);
    // 0x8007C72C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007C730: beq         $t7, $zero, L_8007C748
    if (ctx->r15 == 0) {
        // 0x8007C734: addiu       $v0, $v0, 0x68F8
        ctx->r2 = ADD32(ctx->r2, 0X68F8);
            goto L_8007C748;
    }
    // 0x8007C734: addiu       $v0, $v0, 0x68F8
    ctx->r2 = ADD32(ctx->r2, 0X68F8);
    // 0x8007C738: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8007C73C: nop

    // 0x8007C740: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8007C744: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_8007C748:
    // 0x8007C748: b           L_8007C958
    // 0x8007C74C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007C958;
    // 0x8007C74C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007C750:
    // 0x8007C750: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x8007C754: jal         0x80071A90
    // 0x8007C758: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    align16(rdram, ctx);
        goto after_4;
    // 0x8007C758: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_4:
    // 0x8007C75C: lh          $a0, 0x2($s4)
    ctx->r4 = MEM_H(ctx->r20, 0X2);
    // 0x8007C760: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8007C764: sll         $t3, $a0, 2
    ctx->r11 = S32(ctx->r4 << 2);
    // 0x8007C768: jal         0x80071A90
    // 0x8007C76C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    align16(rdram, ctx);
        goto after_5;
    // 0x8007C76C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_5:
    // 0x8007C770: addu        $t4, $v0, $s3
    ctx->r12 = ADD32(ctx->r2, ctx->r19);
    // 0x8007C774: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x8007C778: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007C77C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8007C780: sll         $a0, $s5, 5
    ctx->r4 = S32(ctx->r21 << 5);
    // 0x8007C784: addiu       $a3, $a3, 0x6904
    ctx->r7 = ADD32(ctx->r7, 0X6904);
    // 0x8007C788: addiu       $a1, $a1, 0x6908
    ctx->r5 = ADD32(ctx->r5, 0X6908);
    // 0x8007C78C: addu        $t7, $t5, $a0
    ctx->r15 = ADD32(ctx->r13, ctx->r4);
    // 0x8007C790: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x8007C794: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8007C798: lh          $t3, 0x2($s4)
    ctx->r11 = MEM_H(ctx->r20, 0X2);
    // 0x8007C79C: addu        $t9, $t7, $a0
    ctx->r25 = ADD32(ctx->r15, ctx->r4);
    // 0x8007C7A0: sll         $t7, $s5, 2
    ctx->r15 = S32(ctx->r21 << 2);
    // 0x8007C7A4: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x8007C7A8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8007C7AC: addu        $t5, $t9, $t4
    ctx->r13 = ADD32(ctx->r25, ctx->r12);
    // 0x8007C7B0: addu        $t7, $t7, $s5
    ctx->r15 = ADD32(ctx->r15, ctx->r21);
    // 0x8007C7B4: addiu       $a2, $a2, 0x6900
    ctx->r6 = ADD32(ctx->r6, 0X6900);
    // 0x8007C7B8: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8007C7BC: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x8007C7C0: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x8007C7C4: sw          $t8, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r24;
    // 0x8007C7C8: blez        $s5, L_8007C844
    if (SIGNED(ctx->r21) <= 0) {
        // 0x8007C7CC: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8007C844;
    }
    // 0x8007C7CC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8007C7D0: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x8007C7D4: addiu       $s2, $s2, -0x12C0
    ctx->r18 = ADD32(ctx->r18, -0X12C0);
    // 0x8007C7D8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8007C7DC:
    // 0x8007C7DC: lui         $t3, 0xFF
    ctx->r11 = S32(0XFF << 16);
    // 0x8007C7E0: ori         $t3, $t3, 0x163
    ctx->r11 = ctx->r11 | 0X163;
    // 0x8007C7E4: sw          $t3, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r11;
    // 0x8007C7E8: lh          $t9, 0x0($s4)
    ctx->r25 = MEM_H(ctx->r20, 0X0);
    // 0x8007C7EC: sb          $v1, 0x33($sp)
    MEM_B(0X33, ctx->r29) = ctx->r3;
    // 0x8007C7F0: jal         0x8007B2C4
    // 0x8007C7F4: addu        $a0, $t9, $s0
    ctx->r4 = ADD32(ctx->r25, ctx->r16);
    load_texture(rdram, ctx);
        goto after_6;
    // 0x8007C7F4: addu        $a0, $t9, $s0
    ctx->r4 = ADD32(ctx->r25, ctx->r16);
    after_6:
    // 0x8007C7F8: lw          $t4, 0x8($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X8);
    // 0x8007C7FC: lb          $v1, 0x33($sp)
    ctx->r3 = MEM_B(ctx->r29, 0X33);
    // 0x8007C800: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x8007C804: sw          $v0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r2;
    // 0x8007C808: lw          $t6, 0x8($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X8);
    // 0x8007C80C: lui         $t3, 0xFF00
    ctx->r11 = S32(0XFF00 << 16);
    // 0x8007C810: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x8007C814: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8007C818: ori         $t3, $t3, 0xFFFF
    ctx->r11 = ctx->r11 | 0XFFFF;
    // 0x8007C81C: bne         $t8, $zero, L_8007C828
    if (ctx->r24 != 0) {
        // 0x8007C820: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8007C828;
    }
    // 0x8007C820: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8007C824: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8007C828:
    // 0x8007C828: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007C82C: sw          $t3, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r11;
    // 0x8007C830: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007C834: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8007C838: bne         $s0, $s5, L_8007C7DC
    if (ctx->r16 != ctx->r21) {
        // 0x8007C83C: sw          $t9, 0x68E4($at)
        MEM_W(0X68E4, ctx->r1) = ctx->r25;
            goto L_8007C7DC;
    }
    // 0x8007C83C: sw          $t9, 0x68E4($at)
    MEM_W(0X68E4, ctx->r1) = ctx->r25;
    // 0x8007C840: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8007C844:
    // 0x8007C844: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007C848: beq         $v1, $zero, L_8007C8B8
    if (ctx->r3 == 0) {
        // 0x8007C84C: sw          $zero, 0x68E4($at)
        MEM_W(0X68E4, ctx->r1) = 0;
            goto L_8007C8B8;
    }
    // 0x8007C84C: sw          $zero, 0x68E4($at)
    MEM_W(0X68E4, ctx->r1) = 0;
    // 0x8007C850: blez        $s5, L_8007C888
    if (SIGNED(ctx->r21) <= 0) {
        // 0x8007C854: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8007C888;
    }
    // 0x8007C854: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8007C858:
    // 0x8007C858: lw          $t4, 0x8($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X8);
    // 0x8007C85C: nop

    // 0x8007C860: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x8007C864: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x8007C868: nop

    // 0x8007C86C: beq         $a0, $zero, L_8007C87C
    if (ctx->r4 == 0) {
        // 0x8007C870: nop
    
            goto L_8007C87C;
    }
    // 0x8007C870: nop

    // 0x8007C874: jal         0x8007B70C
    // 0x8007C878: nop

    tex_free(rdram, ctx);
        goto after_7;
    // 0x8007C878: nop

    after_7:
L_8007C87C:
    // 0x8007C87C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007C880: bne         $s0, $s5, L_8007C858
    if (ctx->r16 != ctx->r21) {
        // 0x8007C884: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8007C858;
    }
    // 0x8007C884: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_8007C888:
    // 0x8007C888: lb          $t6, 0x32($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X32);
    // 0x8007C88C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007C890: beq         $t6, $zero, L_8007C8A8
    if (ctx->r14 == 0) {
        // 0x8007C894: addiu       $v0, $v0, 0x68F8
        ctx->r2 = ADD32(ctx->r2, 0X68F8);
            goto L_8007C8A8;
    }
    // 0x8007C894: addiu       $v0, $v0, 0x68F8
    ctx->r2 = ADD32(ctx->r2, 0X68F8);
    // 0x8007C898: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8007C89C: nop

    // 0x8007C8A0: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8007C8A4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_8007C8A8:
    // 0x8007C8A8: jal         0x80071380
    // 0x8007C8AC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    mempool_free(rdram, ctx);
        goto after_8;
    // 0x8007C8AC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_8:
    // 0x8007C8B0: b           L_8007C958
    // 0x8007C8B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007C958;
    // 0x8007C8B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007C8B8:
    // 0x8007C8B8: sh          $s5, 0x2($s3)
    MEM_H(0X2, ctx->r19) = ctx->r21;
    // 0x8007C8BC: lh          $t3, 0x2($s4)
    ctx->r11 = MEM_H(ctx->r20, 0X2);
    // 0x8007C8C0: or          $s1, $s3, $zero
    ctx->r17 = ctx->r19 | 0;
    // 0x8007C8C4: sh          $t3, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r11;
    // 0x8007C8C8: lh          $t9, 0x2($s4)
    ctx->r25 = MEM_H(ctx->r20, 0X2);
    // 0x8007C8CC: nop

    // 0x8007C8D0: blez        $t9, L_8007C908
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8007C8D4: lui         $a3, 0x8012
        ctx->r7 = S32(0X8012 << 16);
            goto L_8007C908;
    }
L_8007C8D4:
    // 0x8007C8D4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8007C8D8: addiu       $a3, $a3, 0x6904
    ctx->r7 = ADD32(ctx->r7, 0X6904);
    // 0x8007C8DC: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
    // 0x8007C8E0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8007C8E4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8007C8E8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8007C8EC: jal         0x8007D210
    // 0x8007C8F0: sw          $t4, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r12;
    sprite_init_frame(rdram, ctx);
        goto after_9;
    // 0x8007C8F0: sw          $t4, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r12;
    after_9:
    // 0x8007C8F4: lh          $t5, 0x2($s4)
    ctx->r13 = MEM_H(ctx->r20, 0X2);
    // 0x8007C8F8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007C8FC: slt         $at, $s0, $t5
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8007C900: bne         $at, $zero, L_8007C8D4
    if (ctx->r1 != 0) {
        // 0x8007C904: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8007C8D4;
    }
    // 0x8007C904: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_8007C908:
    // 0x8007C908: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007C90C: lw          $t6, 0x68F8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X68F8);
    // 0x8007C910: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007C914: slti        $at, $t6, 0x64
    ctx->r1 = SIGNED(ctx->r14) < 0X64 ? 1 : 0;
    // 0x8007C918: bne         $at, $zero, L_8007C928
    if (ctx->r1 != 0) {
        // 0x8007C91C: addiu       $a0, $a0, 0x68EC
        ctx->r4 = ADD32(ctx->r4, 0X68EC);
            goto L_8007C928;
    }
    // 0x8007C91C: addiu       $a0, $a0, 0x68EC
    ctx->r4 = ADD32(ctx->r4, 0X68EC);
    // 0x8007C920: b           L_8007C958
    // 0x8007C924: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007C958;
    // 0x8007C924: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007C928:
    // 0x8007C928: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8007C92C: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8007C930: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8007C934: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8007C938: addu        $t4, $t9, $t8
    ctx->r12 = ADD32(ctx->r25, ctx->r24);
    // 0x8007C93C: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8007C940: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8007C944: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8007C948: addu        $t6, $t5, $t8
    ctx->r14 = ADD32(ctx->r13, ctx->r24);
    // 0x8007C94C: sw          $s3, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r19;
    // 0x8007C950: sh          $t7, 0x4($s3)
    MEM_H(0X4, ctx->r19) = ctx->r15;
    // 0x8007C954: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
L_8007C958:
    // 0x8007C958: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C95C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8007C960: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8007C964: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8007C968: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8007C96C: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8007C970: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8007C974: jr          $ra
    // 0x8007C978: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8007C978: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void sprite_cache_index(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C97C: bltz        $a0, L_8007C998
    if (SIGNED(ctx->r4) < 0) {
        // 0x8007C980: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8007C998;
    }
    // 0x8007C980: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007C984: lw          $t6, 0x68F8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X68F8);
    // 0x8007C988: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8007C98C: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8007C990: bne         $at, $zero, L_8007C9A0
    if (ctx->r1 != 0) {
        // 0x8007C994: nop
    
            goto L_8007C9A0;
    }
    // 0x8007C994: nop

L_8007C998:
    // 0x8007C998: jr          $ra
    // 0x8007C99C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8007C99C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007C9A0:
    // 0x8007C9A0: lw          $t7, 0x68EC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X68EC);
    // 0x8007C9A4: sll         $t9, $a0, 3
    ctx->r25 = S32(ctx->r4 << 3);
    // 0x8007C9A8: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8007C9AC: lw          $v1, 0x4($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X4);
    // 0x8007C9B0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007C9B4: bne         $v1, $at, L_8007C9C4
    if (ctx->r3 != ctx->r1) {
        // 0x8007C9B8: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8007C9C4;
    }
    // 0x8007C9B8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8007C9BC: jr          $ra
    // 0x8007C9C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8007C9C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007C9C4:
    // 0x8007C9C4: jr          $ra
    // 0x8007C9C8: nop

    return;
    // 0x8007C9C8: nop

;}
RECOMP_FUNC void tex_asset_size(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C9CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007C9D0: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8007C9D4: andi        $t7, $a0, 0x8000
    ctx->r15 = ctx->r4 & 0X8000;
    // 0x8007C9D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007C9DC: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8007C9E0: beq         $t7, $zero, L_8007C9FC
    if (ctx->r15 == 0) {
        // 0x8007C9E4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8007C9FC;
    }
    // 0x8007C9E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8007C9E8: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8007C9EC: andi        $t9, $a0, 0x7FFF
    ctx->r25 = ctx->r4 & 0X7FFF;
    // 0x8007C9F0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8007C9F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007C9F8: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
L_8007C9FC:
    // 0x8007C9FC: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x8007CA00: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8007CA04: addu        $t0, $t0, $v1
    ctx->r8 = ADD32(ctx->r8, ctx->r3);
    // 0x8007CA08: lw          $t0, 0x68D8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X68D8);
    // 0x8007CA0C: nop

    // 0x8007CA10: slt         $at, $a0, $t0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8007CA14: beq         $at, $zero, L_8007CA24
    if (ctx->r1 == 0) {
        // 0x8007CA18: nop
    
            goto L_8007CA24;
    }
    // 0x8007CA18: nop

    // 0x8007CA1C: bgez        $a0, L_8007CA2C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8007CA20: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_8007CA2C;
    }
    // 0x8007CA20: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
L_8007CA24:
    // 0x8007CA24: b           L_8007CAA0
    // 0x8007CA28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007CAA0;
    // 0x8007CA28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007CA2C:
    // 0x8007CA2C: addu        $t1, $t1, $v1
    ctx->r9 = ADD32(ctx->r9, ctx->r3);
    // 0x8007CA30: lw          $t1, 0x68C0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X68C0);
    // 0x8007CA34: sll         $t2, $a0, 2
    ctx->r10 = S32(ctx->r4 << 2);
    // 0x8007CA38: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007CA3C: lw          $a1, 0x690C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X690C);
    // 0x8007CA40: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x8007CA44: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x8007CA48: lw          $t3, 0x4($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X4);
    // 0x8007CA4C: lbu         $t4, 0x1D($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X1D);
    // 0x8007CA50: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8007CA54: beq         $t4, $zero, L_8007CA80
    if (ctx->r12 == 0) {
        // 0x8007CA58: subu        $a3, $t3, $a2
        ctx->r7 = SUB32(ctx->r11, ctx->r6);
            goto L_8007CA80;
    }
    // 0x8007CA58: subu        $a3, $t3, $a2
    ctx->r7 = SUB32(ctx->r11, ctx->r6);
    // 0x8007CA5C: jal         0x80077190
    // 0x8007CA60: addiu       $a3, $zero, 0x28
    ctx->r7 = ADD32(0, 0X28);
    asset_load(rdram, ctx);
        goto after_0;
    // 0x8007CA60: addiu       $a3, $zero, 0x28
    ctx->r7 = ADD32(0, 0X28);
    after_0:
    // 0x8007CA64: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8007CA68: lw          $v1, 0x690C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X690C);
    // 0x8007CA6C: jal         0x800C670C
    // 0x8007CA70: addiu       $a0, $v1, 0x20
    ctx->r4 = ADD32(ctx->r3, 0X20);
    byteswap32(rdram, ctx);
        goto after_1;
    // 0x8007CA70: addiu       $a0, $v1, 0x20
    ctx->r4 = ADD32(ctx->r3, 0X20);
    after_1:
    // 0x8007CA74: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007CA78: lw          $a1, 0x690C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X690C);
    // 0x8007CA7C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_8007CA80:
    // 0x8007CA80: lhu         $v1, 0x12($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X12);
    // 0x8007CA84: nop

    // 0x8007CA88: sra         $t5, $v1, 8
    ctx->r13 = S32(SIGNED(ctx->r3) >> 8);
    // 0x8007CA8C: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x8007CA90: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8007CA94: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8007CA98: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x8007CA9C: addu        $v0, $t7, $a3
    ctx->r2 = ADD32(ctx->r15, ctx->r7);
L_8007CAA0:
    // 0x8007CAA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007CAA4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8007CAA8: jr          $ra
    // 0x8007CAAC: nop

    return;
    // 0x8007CAAC: nop

;}
RECOMP_FUNC void func_8007C660(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007CAB0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8007CAB4: andi        $t7, $a0, 0x8000
    ctx->r15 = ctx->r4 & 0X8000;
    // 0x8007CAB8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8007CABC: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8007CAC0: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8007CAC4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8007CAC8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8007CACC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8007CAD0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8007CAD4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8007CAD8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8007CADC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007CAE0: beq         $t7, $zero, L_8007CAF0
    if (ctx->r15 == 0) {
        // 0x8007CAE4: sw          $a0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r4;
            goto L_8007CAF0;
    }
    // 0x8007CAE4: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8007CAE8: b           L_8007CC80
    // 0x8007CAEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007CC80;
    // 0x8007CAEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007CAF0:
    // 0x8007CAF0: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8007CAF4: addiu       $s3, $s3, 0x6910
    ctx->r19 = ADD32(ctx->r19, 0X6910);
    // 0x8007CAF8: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x8007CAFC: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8007CB00: bne         $t8, $zero, L_8007CC68
    if (ctx->r24 != 0) {
        // 0x8007CB04: addiu       $s0, $s0, 0x68D8
        ctx->r16 = ADD32(ctx->r16, 0X68D8);
            goto L_8007CC68;
    }
    // 0x8007CB04: addiu       $s0, $s0, 0x68D8
    ctx->r16 = ADD32(ctx->r16, 0X68D8);
    // 0x8007CB08: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8007CB0C: lui         $a1, 0xFF00
    ctx->r5 = S32(0XFF00 << 16);
    // 0x8007CB10: jal         0x80070EDC
    // 0x8007CB14: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x8007CB14: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    after_0:
    // 0x8007CB18: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8007CB1C: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x8007CB20: blez        $t9, L_8007CB50
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8007CB24: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_8007CB50;
    }
    // 0x8007CB24: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_8007CB28:
    // 0x8007CB28: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x8007CB2C: nop

    // 0x8007CB30: addu        $t1, $t0, $s4
    ctx->r9 = ADD32(ctx->r8, ctx->r20);
    // 0x8007CB34: sb          $zero, 0x0($t1)
    MEM_B(0X0, ctx->r9) = 0;
    // 0x8007CB38: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8007CB3C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8007CB40: slt         $at, $s4, $t2
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8007CB44: bne         $at, $zero, L_8007CB28
    if (ctx->r1 != 0) {
        // 0x8007CB48: nop
    
            goto L_8007CB28;
    }
    // 0x8007CB48: nop

    // 0x8007CB4C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_8007CB50:
    // 0x8007CB50: lui         $fp, 0x8012
    ctx->r30 = S32(0X8012 << 16);
    // 0x8007CB54: addiu       $fp, $fp, 0x68F4
    ctx->r30 = ADD32(ctx->r30, 0X68F4);
    // 0x8007CB58: lw          $t3, 0x0($fp)
    ctx->r11 = MEM_W(ctx->r30, 0X0);
    // 0x8007CB5C: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8007CB60: blez        $t3, L_8007CC68
    if (SIGNED(ctx->r11) <= 0) {
        // 0x8007CB64: lui         $s7, 0x8012
        ctx->r23 = S32(0X8012 << 16);
            goto L_8007CC68;
    }
    // 0x8007CB64: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x8007CB68: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x8007CB6C: addiu       $s6, $s6, 0x68F0
    ctx->r22 = ADD32(ctx->r22, 0X68F0);
    // 0x8007CB70: addiu       $s7, $s7, 0x68E8
    ctx->r23 = ADD32(ctx->r23, 0X68E8);
    // 0x8007CB74: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_8007CB78:
    // 0x8007CB78: lw          $t4, 0x0($s7)
    ctx->r12 = MEM_W(ctx->r23, 0X0);
    // 0x8007CB7C: lw          $s1, 0x0($s6)
    ctx->r17 = MEM_W(ctx->r22, 0X0);
    // 0x8007CB80: addu        $v0, $t4, $s5
    ctx->r2 = ADD32(ctx->r12, ctx->r21);
    // 0x8007CB84: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x8007CB88: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x8007CB8C: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x8007CB90: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8007CB94: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8007CB98: jal         0x80077190
    // 0x8007CB9C: subu        $a3, $t5, $a2
    ctx->r7 = SUB32(ctx->r13, ctx->r6);
    asset_load(rdram, ctx);
        goto after_1;
    // 0x8007CB9C: subu        $a3, $t5, $a2
    ctx->r7 = SUB32(ctx->r13, ctx->r6);
    after_1:
    // 0x8007CBA0: lh          $t6, 0x2($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X2);
    // 0x8007CBA4: nop

    // 0x8007CBA8: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x8007CBAC: lbu         $v1, 0xC($t7)
    ctx->r3 = MEM_BU(ctx->r15, 0XC);
    // 0x8007CBB0: nop

    // 0x8007CBB4: blez        $v1, L_8007CC54
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8007CBB8: andi        $a0, $v1, 0x3
        ctx->r4 = ctx->r3 & 0X3;
            goto L_8007CC54;
    }
    // 0x8007CBB8: andi        $a0, $v1, 0x3
    ctx->r4 = ctx->r3 & 0X3;
    // 0x8007CBBC: beq         $a0, $zero, L_8007CBEC
    if (ctx->r4 == 0) {
        // 0x8007CBC0: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8007CBEC;
    }
    // 0x8007CBC0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8007CBC4:
    // 0x8007CBC4: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x8007CBC8: lh          $t9, 0x0($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X0);
    // 0x8007CBCC: nop

    // 0x8007CBD0: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8007CBD4: addu        $t1, $t0, $s0
    ctx->r9 = ADD32(ctx->r8, ctx->r16);
    // 0x8007CBD8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007CBDC: bne         $v0, $s0, L_8007CBC4
    if (ctx->r2 != ctx->r16) {
        // 0x8007CBE0: sb          $s2, 0x0($t1)
        MEM_B(0X0, ctx->r9) = ctx->r18;
            goto L_8007CBC4;
    }
    // 0x8007CBE0: sb          $s2, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r18;
    // 0x8007CBE4: beq         $s0, $v1, L_8007CC54
    if (ctx->r16 == ctx->r3) {
        // 0x8007CBE8: nop
    
            goto L_8007CC54;
    }
    // 0x8007CBE8: nop

L_8007CBEC:
    // 0x8007CBEC: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x8007CBF0: lh          $t3, 0x0($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X0);
    // 0x8007CBF4: nop

    // 0x8007CBF8: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8007CBFC: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x8007CC00: sb          $s2, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r18;
    // 0x8007CC04: lh          $t7, 0x0($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X0);
    // 0x8007CC08: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x8007CC0C: nop

    // 0x8007CC10: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8007CC14: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x8007CC18: sb          $s2, 0x1($t9)
    MEM_B(0X1, ctx->r25) = ctx->r18;
    // 0x8007CC1C: lh          $t1, 0x0($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X0);
    // 0x8007CC20: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x8007CC24: nop

    // 0x8007CC28: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8007CC2C: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x8007CC30: sb          $s2, 0x2($t3)
    MEM_B(0X2, ctx->r11) = ctx->r18;
    // 0x8007CC34: lh          $t5, 0x0($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X0);
    // 0x8007CC38: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x8007CC3C: nop

    // 0x8007CC40: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8007CC44: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x8007CC48: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8007CC4C: bne         $s0, $v1, L_8007CBEC
    if (ctx->r16 != ctx->r3) {
        // 0x8007CC50: sb          $s2, 0x3($t7)
        MEM_B(0X3, ctx->r15) = ctx->r18;
            goto L_8007CBEC;
    }
    // 0x8007CC50: sb          $s2, 0x3($t7)
    MEM_B(0X3, ctx->r15) = ctx->r18;
L_8007CC54:
    // 0x8007CC54: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x8007CC58: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8007CC5C: slt         $at, $s4, $t8
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8007CC60: bne         $at, $zero, L_8007CB78
    if (ctx->r1 != 0) {
        // 0x8007CC64: addiu       $s5, $s5, 0x4
        ctx->r21 = ADD32(ctx->r21, 0X4);
            goto L_8007CB78;
    }
    // 0x8007CC64: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
L_8007CC68:
    // 0x8007CC68: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x8007CC6C: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8007CC70: nop

    // 0x8007CC74: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8007CC78: lbu         $v0, 0x0($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X0);
    // 0x8007CC7C: nop

L_8007CC80:
    // 0x8007CC80: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8007CC84: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007CC88: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8007CC8C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8007CC90: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8007CC94: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8007CC98: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8007CC9C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8007CCA0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8007CCA4: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8007CCA8: jr          $ra
    // 0x8007CCAC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8007CCAC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void tex_cache_asset_id(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007CCB0: bltz        $a0, L_8007CCCC
    if (SIGNED(ctx->r4) < 0) {
        // 0x8007CCB4: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8007CCCC;
    }
    // 0x8007CCB4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007CCB8: lw          $t6, 0x68D0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X68D0);
    // 0x8007CCBC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8007CCC0: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8007CCC4: bne         $at, $zero, L_8007CCD4
    if (ctx->r1 != 0) {
        // 0x8007CCC8: nop
    
            goto L_8007CCD4;
    }
    // 0x8007CCC8: nop

L_8007CCCC:
    // 0x8007CCCC: jr          $ra
    // 0x8007CCD0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x8007CCD0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8007CCD4:
    // 0x8007CCD4: lw          $t7, 0x68C8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X68C8);
    // 0x8007CCD8: sll         $t9, $a0, 3
    ctx->r25 = S32(ctx->r4 << 3);
    // 0x8007CCDC: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8007CCE0: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8007CCE4: nop

    // 0x8007CCE8: jr          $ra
    // 0x8007CCEC: nop

    return;
    // 0x8007CCEC: nop

;}
RECOMP_FUNC void sprite_cache_asset_id(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007CCF0: bltz        $a0, L_8007CD0C
    if (SIGNED(ctx->r4) < 0) {
        // 0x8007CCF4: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8007CD0C;
    }
    // 0x8007CCF4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007CCF8: lw          $t6, 0x68F8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X68F8);
    // 0x8007CCFC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8007CD00: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8007CD04: bne         $at, $zero, L_8007CD14
    if (ctx->r1 != 0) {
        // 0x8007CD08: nop
    
            goto L_8007CD14;
    }
    // 0x8007CD08: nop

L_8007CD0C:
    // 0x8007CD0C: jr          $ra
    // 0x8007CD10: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x8007CD10: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8007CD14:
    // 0x8007CD14: lw          $t7, 0x68EC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X68EC);
    // 0x8007CD18: sll         $t9, $a0, 3
    ctx->r25 = S32(ctx->r4 << 3);
    // 0x8007CD1C: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8007CD20: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8007CD24: nop

    // 0x8007CD28: jr          $ra
    // 0x8007CD2C: nop

    return;
    // 0x8007CD2C: nop

;}
RECOMP_FUNC void load_sprite_info(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007CD30: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8007CD34: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007CD38: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007CD3C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8007CD40: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8007CD44: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8007CD48: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8007CD4C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8007CD50: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8007CD54: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8007CD58: bltz        $a0, L_8007CD78
    if (SIGNED(ctx->r4) < 0) {
        // 0x8007CD5C: sw          $a3, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r7;
            goto L_8007CD78;
    }
    // 0x8007CD5C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8007CD60: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007CD64: lw          $t6, 0x68F4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X68F4);
    // 0x8007CD68: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8007CD6C: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8007CD70: bne         $at, $zero, L_8007CD9C
    if (ctx->r1 != 0) {
        // 0x8007CD74: sll         $t1, $s0, 2
        ctx->r9 = S32(ctx->r16 << 2);
            goto L_8007CD9C;
    }
    // 0x8007CD74: sll         $t1, $s0, 2
    ctx->r9 = S32(ctx->r16 << 2);
L_8007CD78:
    // 0x8007CD78: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8007CD7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8007CD80: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x8007CD84: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8007CD88: nop

    // 0x8007CD8C: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x8007CD90: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8007CD94: b           L_8007CE98
    // 0x8007CD98: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
        goto L_8007CE98;
    // 0x8007CD98: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
L_8007CD9C:
    // 0x8007CD9C: lw          $t0, 0x68E8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X68E8);
    // 0x8007CDA0: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8007CDA4: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x8007CDA8: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x8007CDAC: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x8007CDB0: lw          $s3, 0x68F0($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X68F0);
    // 0x8007CDB4: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x8007CDB8: subu        $a3, $t2, $a2
    ctx->r7 = SUB32(ctx->r10, ctx->r6);
    // 0x8007CDBC: jal         0x80077190
    // 0x8007CDC0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    asset_load(rdram, ctx);
        goto after_0;
    // 0x8007CDC0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_0:
    // 0x8007CDC4: lbu         $t3, 0xC($s3)
    ctx->r11 = MEM_BU(ctx->r19, 0XC);
    // 0x8007CDC8: lh          $t4, 0x0($s3)
    ctx->r12 = MEM_H(ctx->r19, 0X0);
    // 0x8007CDCC: jal         0x8007B2C4
    // 0x8007CDD0: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    load_texture(rdram, ctx);
        goto after_1;
    // 0x8007CDD0: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    after_1:
    // 0x8007CDD4: beq         $v0, $zero, L_8007CD78
    if (ctx->r2 == 0) {
        // 0x8007CDD8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8007CD78;
    }
    // 0x8007CDD8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8007CDDC: lbu         $t5, 0x2($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X2);
    // 0x8007CDE0: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8007CDE4: andi        $t6, $t5, 0xF
    ctx->r14 = ctx->r13 & 0XF;
    // 0x8007CDE8: jal         0x8007B70C
    // 0x8007CDEC: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    tex_free(rdram, ctx);
        goto after_2;
    // 0x8007CDEC: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    after_2:
    // 0x8007CDF0: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x8007CDF4: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8007CDF8: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x8007CDFC: lh          $v1, 0x2($s3)
    ctx->r3 = MEM_H(ctx->r19, 0X2);
    // 0x8007CE00: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
    // 0x8007CE04: blez        $v1, L_8007CE70
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8007CE08: lw          $t3, 0x3C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X3C);
            goto L_8007CE70;
    }
    // 0x8007CE08: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
L_8007CE0C:
    // 0x8007CE0C: lbu         $s0, 0xC($s2)
    ctx->r16 = MEM_BU(ctx->r18, 0XC);
    // 0x8007CE10: lbu         $t8, 0xD($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0XD);
    // 0x8007CE14: nop

    // 0x8007CE18: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8007CE1C: beq         $at, $zero, L_8007CE5C
    if (ctx->r1 == 0) {
        // 0x8007CE20: nop
    
            goto L_8007CE5C;
    }
    // 0x8007CE20: nop

L_8007CE24:
    // 0x8007CE24: lh          $t9, 0x0($s3)
    ctx->r25 = MEM_H(ctx->r19, 0X0);
    // 0x8007CE28: jal         0x8007C9CC
    // 0x8007CE2C: addu        $a0, $t9, $s0
    ctx->r4 = ADD32(ctx->r25, ctx->r16);
    tex_asset_size(rdram, ctx);
        goto after_3;
    // 0x8007CE2C: addu        $a0, $t9, $s0
    ctx->r4 = ADD32(ctx->r25, ctx->r16);
    after_3:
    // 0x8007CE30: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x8007CE34: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007CE38: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x8007CE3C: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x8007CE40: lbu         $t2, 0xD($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0XD);
    // 0x8007CE44: nop

    // 0x8007CE48: slt         $at, $s0, $t2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8007CE4C: bne         $at, $zero, L_8007CE24
    if (ctx->r1 != 0) {
        // 0x8007CE50: nop
    
            goto L_8007CE24;
    }
    // 0x8007CE50: nop

    // 0x8007CE54: lh          $v1, 0x2($s3)
    ctx->r3 = MEM_H(ctx->r19, 0X2);
    // 0x8007CE58: nop

L_8007CE5C:
    // 0x8007CE5C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8007CE60: slt         $at, $s4, $v1
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8007CE64: bne         $at, $zero, L_8007CE0C
    if (ctx->r1 != 0) {
        // 0x8007CE68: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8007CE0C;
    }
    // 0x8007CE68: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8007CE6C: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
L_8007CE70:
    // 0x8007CE70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007CE74: sw          $v1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r3;
    // 0x8007CE78: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8007CE7C: lh          $t4, 0x4($s3)
    ctx->r12 = MEM_H(ctx->r19, 0X4);
    // 0x8007CE80: nop

    // 0x8007CE84: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x8007CE88: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8007CE8C: lh          $t6, 0x6($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X6);
    // 0x8007CE90: nop

    // 0x8007CE94: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
L_8007CE98:
    // 0x8007CE98: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8007CE9C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007CEA0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8007CEA4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8007CEA8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8007CEAC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8007CEB0: jr          $ra
    // 0x8007CEB4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8007CEB4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8007CA68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007CEB8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8007CEBC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8007CEC0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007CEC4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007CEC8: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8007CECC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8007CED0: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8007CED4: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8007CED8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8007CEDC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8007CEE0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8007CEE4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8007CEE8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8007CEEC: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8007CEF0: bltz        $a0, L_8007CF10
    if (SIGNED(ctx->r4) < 0) {
        // 0x8007CEF4: sw          $a3, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r7;
            goto L_8007CF10;
    }
    // 0x8007CEF4: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x8007CEF8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007CEFC: lw          $t6, 0x68F4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X68F4);
    // 0x8007CF00: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8007CF04: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8007CF08: bne         $at, $zero, L_8007CF28
    if (ctx->r1 != 0) {
        // 0x8007CF0C: sll         $t0, $s0, 2
        ctx->r8 = S32(ctx->r16 << 2);
            goto L_8007CF28;
    }
    // 0x8007CF0C: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
L_8007CF10:
    // 0x8007CF10: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x8007CF14: nop

    // 0x8007CF18: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x8007CF1C: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x8007CF20: b           L_8007D0D0
    // 0x8007CF24: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
        goto L_8007D0D0;
    // 0x8007CF24: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
L_8007CF28:
    // 0x8007CF28: lw          $t9, 0x68E8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X68E8);
    // 0x8007CF2C: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8007CF30: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x8007CF34: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x8007CF38: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x8007CF3C: lw          $s2, 0x68F0($s2)
    ctx->r18 = MEM_W(ctx->r18, 0X68F0);
    // 0x8007CF40: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x8007CF44: subu        $a3, $t1, $a2
    ctx->r7 = SUB32(ctx->r9, ctx->r6);
    // 0x8007CF48: jal         0x80077190
    // 0x8007CF4C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    asset_load(rdram, ctx);
        goto after_0;
    // 0x8007CF4C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_0:
    // 0x8007CF50: lh          $t2, 0x2($s2)
    ctx->r10 = MEM_H(ctx->r18, 0X2);
    // 0x8007CF54: lw          $s7, 0x50($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X50);
    // 0x8007CF58: slt         $at, $t2, $s1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x8007CF5C: beq         $at, $zero, L_8007CF84
    if (ctx->r1 == 0) {
        // 0x8007CF60: addu        $fp, $s2, $s1
        ctx->r30 = ADD32(ctx->r18, ctx->r17);
            goto L_8007CF84;
    }
    // 0x8007CF60: addu        $fp, $s2, $s1
    ctx->r30 = ADD32(ctx->r18, ctx->r17);
L_8007CF64:
    // 0x8007CF64: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
L_8007CF68:
    // 0x8007CF68: nop

    // 0x8007CF6C: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
    // 0x8007CF70: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x8007CF74: nop

    // 0x8007CF78: sw          $zero, 0x0($t4)
    MEM_W(0X0, ctx->r12) = 0;
    // 0x8007CF7C: b           L_8007D0D0
    // 0x8007CF80: sw          $zero, 0x0($s7)
    MEM_W(0X0, ctx->r23) = 0;
        goto L_8007D0D0;
    // 0x8007CF80: sw          $zero, 0x0($s7)
    MEM_W(0X0, ctx->r23) = 0;
L_8007CF84:
    // 0x8007CF84: lbu         $t5, 0xC($fp)
    ctx->r13 = MEM_BU(ctx->r30, 0XC);
    // 0x8007CF88: lh          $t6, 0x0($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X0);
    // 0x8007CF8C: jal         0x8007B2C4
    // 0x8007CF90: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    load_texture(rdram, ctx);
        goto after_1;
    // 0x8007CF90: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    after_1:
    // 0x8007CF94: bne         $v0, $zero, L_8007CFA8
    if (ctx->r2 != 0) {
        // 0x8007CF98: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8007CFA8;
    }
    // 0x8007CF98: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007CF9C: lw          $s7, 0x50($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X50);
    // 0x8007CFA0: b           L_8007CF68
    // 0x8007CFA4: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
        goto L_8007CF68;
    // 0x8007CFA4: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
L_8007CFA8:
    // 0x8007CFA8: lbu         $t7, 0xC($fp)
    ctx->r15 = MEM_BU(ctx->r30, 0XC);
    // 0x8007CFAC: lh          $t8, 0x0($s2)
    ctx->r24 = MEM_H(ctx->r18, 0X0);
    // 0x8007CFB0: jal         0x8007C9CC
    // 0x8007CFB4: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    tex_asset_size(rdram, ctx);
        goto after_2;
    // 0x8007CFB4: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x8007CFB8: lw          $s7, 0x50($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X50);
    // 0x8007CFBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007CFC0: sw          $v0, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r2;
    // 0x8007CFC4: lh          $t0, 0x4($s2)
    ctx->r8 = MEM_H(ctx->r18, 0X4);
    // 0x8007CFC8: lb          $t9, 0x3($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X3);
    // 0x8007CFCC: lb          $t2, 0x4($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X4);
    // 0x8007CFD0: lh          $t1, 0x6($s2)
    ctx->r9 = MEM_H(ctx->r18, 0X6);
    // 0x8007CFD4: lbu         $a1, 0x0($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X0);
    // 0x8007CFD8: lbu         $a2, 0x1($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X1);
    // 0x8007CFDC: subu        $s3, $t9, $t0
    ctx->r19 = SUB32(ctx->r25, ctx->r8);
    // 0x8007CFE0: subu        $s4, $t1, $t2
    ctx->r20 = SUB32(ctx->r9, ctx->r10);
    // 0x8007CFE4: addu        $s5, $s3, $a1
    ctx->r21 = ADD32(ctx->r19, ctx->r5);
    // 0x8007CFE8: jal         0x8007B70C
    // 0x8007CFEC: subu        $s6, $s4, $a2
    ctx->r22 = SUB32(ctx->r20, ctx->r6);
    tex_free(rdram, ctx);
        goto after_3;
    // 0x8007CFEC: subu        $s6, $s4, $a2
    ctx->r22 = SUB32(ctx->r20, ctx->r6);
    after_3:
    // 0x8007CFF0: lbu         $s1, 0xC($fp)
    ctx->r17 = MEM_BU(ctx->r30, 0XC);
    // 0x8007CFF4: lbu         $t3, 0xD($fp)
    ctx->r11 = MEM_BU(ctx->r30, 0XD);
    // 0x8007CFF8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8007CFFC: slt         $at, $s1, $t3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8007D000: beq         $at, $zero, L_8007D0BC
    if (ctx->r1 == 0) {
        // 0x8007D004: lw          $t4, 0x48($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X48);
            goto L_8007D0BC;
    }
    // 0x8007D004: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
L_8007D008:
    // 0x8007D008: lh          $t4, 0x0($s2)
    ctx->r12 = MEM_H(ctx->r18, 0X0);
    // 0x8007D00C: jal         0x8007B2C4
    // 0x8007D010: addu        $a0, $t4, $s1
    ctx->r4 = ADD32(ctx->r12, ctx->r17);
    load_texture(rdram, ctx);
        goto after_4;
    // 0x8007D010: addu        $a0, $t4, $s1
    ctx->r4 = ADD32(ctx->r12, ctx->r17);
    after_4:
    // 0x8007D014: beq         $v0, $zero, L_8007CF64
    if (ctx->r2 == 0) {
        // 0x8007D018: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8007CF64;
    }
    // 0x8007D018: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007D01C: lh          $t5, 0x0($s2)
    ctx->r13 = MEM_H(ctx->r18, 0X0);
    // 0x8007D020: jal         0x8007C9CC
    // 0x8007D024: addu        $a0, $t5, $s1
    ctx->r4 = ADD32(ctx->r13, ctx->r17);
    tex_asset_size(rdram, ctx);
        goto after_5;
    // 0x8007D024: addu        $a0, $t5, $s1
    ctx->r4 = ADD32(ctx->r13, ctx->r17);
    after_5:
    // 0x8007D028: lw          $t6, 0x0($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X0);
    // 0x8007D02C: nop

    // 0x8007D030: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x8007D034: sw          $t7, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r15;
    // 0x8007D038: lh          $t9, 0x4($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X4);
    // 0x8007D03C: lb          $t8, 0x3($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X3);
    // 0x8007D040: lb          $t1, 0x4($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X4);
    // 0x8007D044: lh          $t0, 0x6($s2)
    ctx->r8 = MEM_H(ctx->r18, 0X6);
    // 0x8007D048: subu        $v1, $t8, $t9
    ctx->r3 = SUB32(ctx->r24, ctx->r25);
    // 0x8007D04C: lbu         $a1, 0x0($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X0);
    // 0x8007D050: lbu         $a2, 0x1($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X1);
    // 0x8007D054: slt         $at, $v1, $s3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8007D058: beq         $at, $zero, L_8007D064
    if (ctx->r1 == 0) {
        // 0x8007D05C: subu        $a0, $t0, $t1
        ctx->r4 = SUB32(ctx->r8, ctx->r9);
            goto L_8007D064;
    }
    // 0x8007D05C: subu        $a0, $t0, $t1
    ctx->r4 = SUB32(ctx->r8, ctx->r9);
    // 0x8007D060: or          $s3, $v1, $zero
    ctx->r19 = ctx->r3 | 0;
L_8007D064:
    // 0x8007D064: addu        $v0, $v1, $a1
    ctx->r2 = ADD32(ctx->r3, ctx->r5);
    // 0x8007D068: slt         $at, $s5, $v0
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8007D06C: beq         $at, $zero, L_8007D078
    if (ctx->r1 == 0) {
        // 0x8007D070: nop
    
            goto L_8007D078;
    }
    // 0x8007D070: nop

    // 0x8007D074: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
L_8007D078:
    // 0x8007D078: subu        $v0, $a0, $a2
    ctx->r2 = SUB32(ctx->r4, ctx->r6);
    // 0x8007D07C: slt         $at, $v0, $s6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x8007D080: beq         $at, $zero, L_8007D090
    if (ctx->r1 == 0) {
        // 0x8007D084: slt         $at, $s4, $a0
        ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8007D090;
    }
    // 0x8007D084: slt         $at, $s4, $a0
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8007D088: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x8007D08C: slt         $at, $s4, $a0
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r4) ? 1 : 0;
L_8007D090:
    // 0x8007D090: beq         $at, $zero, L_8007D09C
    if (ctx->r1 == 0) {
        // 0x8007D094: nop
    
            goto L_8007D09C;
    }
    // 0x8007D094: nop

    // 0x8007D098: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
L_8007D09C:
    // 0x8007D09C: jal         0x8007B70C
    // 0x8007D0A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    tex_free(rdram, ctx);
        goto after_6;
    // 0x8007D0A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8007D0A4: lbu         $t2, 0xD($fp)
    ctx->r10 = MEM_BU(ctx->r30, 0XD);
    // 0x8007D0A8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8007D0AC: slt         $at, $s1, $t2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8007D0B0: bne         $at, $zero, L_8007D008
    if (ctx->r1 != 0) {
        // 0x8007D0B4: nop
    
            goto L_8007D008;
    }
    // 0x8007D0B4: nop

    // 0x8007D0B8: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
L_8007D0BC:
    // 0x8007D0BC: subu        $t3, $s5, $s3
    ctx->r11 = SUB32(ctx->r21, ctx->r19);
    // 0x8007D0C0: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8007D0C4: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x8007D0C8: subu        $t5, $s4, $s6
    ctx->r13 = SUB32(ctx->r20, ctx->r22);
    // 0x8007D0CC: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
L_8007D0D0:
    // 0x8007D0D0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8007D0D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007D0D8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8007D0DC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8007D0E0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8007D0E4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8007D0E8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8007D0EC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8007D0F0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8007D0F4: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8007D0F8: jr          $ra
    // 0x8007D0FC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8007D0FC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void sprite_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007D100: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007D104: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8007D108: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8007D10C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007D110: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8007D114: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8007D118: beq         $a0, $zero, L_8007D1F4
    if (ctx->r4 == 0) {
        // 0x8007D11C: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_8007D1F4;
    }
    // 0x8007D11C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8007D120: lh          $t6, 0x4($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X4);
    // 0x8007D124: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8007D128: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8007D12C: sh          $t7, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r15;
    // 0x8007D130: lh          $t8, 0x4($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X4);
    // 0x8007D134: nop

    // 0x8007D138: bgtz        $t8, L_8007D1F8
    if (SIGNED(ctx->r24) > 0) {
        // 0x8007D13C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8007D1F8;
    }
    // 0x8007D13C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8007D140: lw          $v1, 0x68F8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X68F8);
    // 0x8007D144: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8007D148: blez        $v1, L_8007D1F4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8007D14C: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_8007D1F4;
    }
    // 0x8007D14C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007D150: lw          $a0, 0x68EC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X68EC);
    // 0x8007D154: nop

    // 0x8007D158: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
L_8007D15C:
    // 0x8007D15C: sll         $t9, $s3, 3
    ctx->r25 = S32(ctx->r19 << 3);
    // 0x8007D160: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x8007D164: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8007D168: or          $s3, $t9, $zero
    ctx->r19 = ctx->r25 | 0;
    // 0x8007D16C: bne         $s2, $t1, L_8007D1E8
    if (ctx->r18 != ctx->r9) {
        // 0x8007D170: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8007D1E8;
    }
    // 0x8007D170: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8007D174: lh          $t2, 0x2($s2)
    ctx->r10 = MEM_H(ctx->r18, 0X2);
    // 0x8007D178: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8007D17C: blez        $t2, L_8007D1B0
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8007D180: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8007D1B0;
    }
    // 0x8007D180: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8007D184:
    // 0x8007D184: lw          $t3, 0x8($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X8);
    // 0x8007D188: nop

    // 0x8007D18C: addu        $t4, $t3, $s1
    ctx->r12 = ADD32(ctx->r11, ctx->r17);
    // 0x8007D190: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x8007D194: jal         0x8007B70C
    // 0x8007D198: nop

    tex_free(rdram, ctx);
        goto after_0;
    // 0x8007D198: nop

    after_0:
    // 0x8007D19C: lh          $t5, 0x2($s2)
    ctx->r13 = MEM_H(ctx->r18, 0X2);
    // 0x8007D1A0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007D1A4: slt         $at, $s0, $t5
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8007D1A8: bne         $at, $zero, L_8007D184
    if (ctx->r1 != 0) {
        // 0x8007D1AC: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8007D184;
    }
    // 0x8007D1AC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_8007D1B0:
    // 0x8007D1B0: jal         0x80071380
    // 0x8007D1B4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mempool_free(rdram, ctx);
        goto after_1;
    // 0x8007D1B4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x8007D1B8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007D1BC: addiu       $v0, $v0, 0x68EC
    ctx->r2 = ADD32(ctx->r2, 0X68EC);
    // 0x8007D1C0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8007D1C4: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8007D1C8: addu        $t7, $t6, $s3
    ctx->r15 = ADD32(ctx->r14, ctx->r19);
    // 0x8007D1CC: sw          $v1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r3;
    // 0x8007D1D0: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8007D1D4: nop

    // 0x8007D1D8: addu        $t9, $t8, $s3
    ctx->r25 = ADD32(ctx->r24, ctx->r19);
    // 0x8007D1DC: b           L_8007D1F4
    // 0x8007D1E0: sw          $v1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r3;
        goto L_8007D1F4;
    // 0x8007D1E0: sw          $v1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r3;
    // 0x8007D1E4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8007D1E8:
    // 0x8007D1E8: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8007D1EC: bne         $at, $zero, L_8007D15C
    if (ctx->r1 != 0) {
        // 0x8007D1F0: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_8007D15C;
    }
    // 0x8007D1F0: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
L_8007D1F4:
    // 0x8007D1F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8007D1F8:
    // 0x8007D1F8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8007D1FC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8007D200: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8007D204: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8007D208: jr          $ra
    // 0x8007D20C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8007D20C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void sprite_init_frame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007D210: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8007D214: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8007D218: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x8007D21C: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x8007D220: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x8007D224: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x8007D228: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x8007D22C: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x8007D230: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x8007D234: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x8007D238: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x8007D23C: lh          $t6, 0x4($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X4);
    // 0x8007D240: addu        $a3, $a0, $a2
    ctx->r7 = ADD32(ctx->r4, ctx->r6);
    // 0x8007D244: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x8007D248: lh          $t7, 0x6($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X6);
    // 0x8007D24C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8007D250: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x8007D254: lbu         $s2, 0xC($a3)
    ctx->r18 = MEM_BU(ctx->r7, 0XC);
    // 0x8007D258: lbu         $fp, 0xD($a3)
    ctx->r30 = MEM_BU(ctx->r7, 0XD);
    // 0x8007D25C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007D260: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8007D264: lw          $t1, 0x6904($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6904);
    // 0x8007D268: lw          $v0, 0x6900($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6900);
    // 0x8007D26C: lw          $v1, 0x6908($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6908);
    // 0x8007D270: slt         $at, $s2, $fp
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r30) ? 1 : 0;
    // 0x8007D274: beq         $at, $zero, L_8007D2A0
    if (ctx->r1 == 0) {
        // 0x8007D278: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_8007D2A0;
    }
    // 0x8007D278: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8007D27C: lw          $t8, 0x8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8);
    // 0x8007D280: sll         $t9, $s2, 2
    ctx->r25 = S32(ctx->r18 << 2);
    // 0x8007D284: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x8007D288: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x8007D28C: nop

    // 0x8007D290: lh          $t8, 0x6($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X6);
    // 0x8007D294: nop

    // 0x8007D298: andi        $t9, $t8, 0x3B
    ctx->r25 = ctx->r24 & 0X3B;
    // 0x8007D29C: sh          $t9, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r25;
L_8007D2A0:
    // 0x8007D2A0: slt         $at, $s2, $fp
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r30) ? 1 : 0;
    // 0x8007D2A4: beq         $at, $zero, L_8007D4D8
    if (ctx->r1 == 0) {
        // 0x8007D2A8: or          $t5, $zero, $zero
        ctx->r13 = 0 | 0;
            goto L_8007D4D8;
    }
    // 0x8007D2A8: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x8007D2AC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8007D2B0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8007D2B4: sll         $s3, $s2, 2
    ctx->r19 = S32(ctx->r18 << 2);
    // 0x8007D2B8: lui         $ra, 0x700
    ctx->r31 = S32(0X700 << 16);
    // 0x8007D2BC: addiu       $s7, $zero, 0x40
    ctx->r23 = ADD32(0, 0X40);
    // 0x8007D2C0: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x8007D2C4: lui         $s4, 0x8000
    ctx->r20 = S32(0X8000 << 16);
    // 0x8007D2C8: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
L_8007D2CC:
    // 0x8007D2CC: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x8007D2D0: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x8007D2D4: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8007D2D8: addu        $t8, $t7, $s3
    ctx->r24 = ADD32(ctx->r15, ctx->r19);
    // 0x8007D2DC: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x8007D2E0: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8007D2E4: lbu         $s0, 0x0($a0)
    ctx->r16 = MEM_BU(ctx->r4, 0X0);
    // 0x8007D2E8: lbu         $s1, 0x1($a0)
    ctx->r17 = MEM_BU(ctx->r4, 0X1);
    // 0x8007D2EC: lb          $t9, 0x3($a0)
    ctx->r25 = MEM_B(ctx->r4, 0X3);
    // 0x8007D2F0: lb          $t8, 0x4($a0)
    ctx->r24 = MEM_B(ctx->r4, 0X4);
    // 0x8007D2F4: subu        $t0, $t9, $t6
    ctx->r8 = SUB32(ctx->r25, ctx->r14);
    // 0x8007D2F8: subu        $a2, $t7, $t8
    ctx->r6 = SUB32(ctx->r15, ctx->r24);
    // 0x8007D2FC: addu        $t3, $t0, $s0
    ctx->r11 = ADD32(ctx->r8, ctx->r16);
    // 0x8007D300: addiu       $a3, $a2, -0x1
    ctx->r7 = ADD32(ctx->r6, -0X1);
    // 0x8007D304: addiu       $t3, $t3, -0x1
    ctx->r11 = ADD32(ctx->r11, -0X1);
    // 0x8007D308: subu        $t4, $a2, $s1
    ctx->r12 = SUB32(ctx->r6, ctx->r17);
    // 0x8007D30C: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
    // 0x8007D310: sh          $a3, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r7;
    // 0x8007D314: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x8007D318: sb          $a1, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r5;
    // 0x8007D31C: sb          $a1, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r5;
    // 0x8007D320: sb          $a1, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r5;
    // 0x8007D324: sb          $a1, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r5;
    // 0x8007D328: sh          $t3, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r11;
    // 0x8007D32C: sh          $a3, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r7;
    // 0x8007D330: sh          $zero, 0xE($v0)
    MEM_H(0XE, ctx->r2) = 0;
    // 0x8007D334: sb          $a1, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r5;
    // 0x8007D338: sb          $a1, 0x11($v0)
    MEM_B(0X11, ctx->r2) = ctx->r5;
    // 0x8007D33C: sb          $a1, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r5;
    // 0x8007D340: sb          $a1, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r5;
    // 0x8007D344: sh          $t3, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r11;
    // 0x8007D348: sh          $t4, 0x16($v0)
    MEM_H(0X16, ctx->r2) = ctx->r12;
    // 0x8007D34C: sh          $zero, 0x18($v0)
    MEM_H(0X18, ctx->r2) = 0;
    // 0x8007D350: sb          $a1, 0x1A($v0)
    MEM_B(0X1A, ctx->r2) = ctx->r5;
    // 0x8007D354: sb          $a1, 0x1B($v0)
    MEM_B(0X1B, ctx->r2) = ctx->r5;
    // 0x8007D358: sb          $a1, 0x1C($v0)
    MEM_B(0X1C, ctx->r2) = ctx->r5;
    // 0x8007D35C: sb          $a1, 0x1D($v0)
    MEM_B(0X1D, ctx->r2) = ctx->r5;
    // 0x8007D360: sh          $t0, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r8;
    // 0x8007D364: sh          $t4, 0x20($v0)
    MEM_H(0X20, ctx->r2) = ctx->r12;
    // 0x8007D368: sh          $zero, 0x22($v0)
    MEM_H(0X22, ctx->r2) = 0;
    // 0x8007D36C: sb          $a1, 0x24($v0)
    MEM_B(0X24, ctx->r2) = ctx->r5;
    // 0x8007D370: sb          $a1, 0x25($v0)
    MEM_B(0X25, ctx->r2) = ctx->r5;
    // 0x8007D374: sb          $a1, 0x26($v0)
    MEM_B(0X26, ctx->r2) = ctx->r5;
    // 0x8007D378: sb          $a1, 0x27($v0)
    MEM_B(0X27, ctx->r2) = ctx->r5;
    // 0x8007D37C: lh          $a3, 0xA($a0)
    ctx->r7 = MEM_H(ctx->r4, 0XA);
    // 0x8007D380: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x8007D384: andi        $t9, $a3, 0xFF
    ctx->r25 = ctx->r7 & 0XFF;
    // 0x8007D388: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x8007D38C: sll         $t8, $a3, 3
    ctx->r24 = S32(ctx->r7 << 3);
    // 0x8007D390: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x8007D394: or          $t7, $t6, $ra
    ctx->r15 = ctx->r14 | ctx->r31;
    // 0x8007D398: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x8007D39C: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8007D3A0: lw          $t8, 0xC($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XC);
    // 0x8007D3A4: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
    // 0x8007D3A8: addu        $t7, $t8, $s4
    ctx->r15 = ADD32(ctx->r24, ctx->r20);
    // 0x8007D3AC: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x8007D3B0: bne         $t5, $zero, L_8007D41C
    if (ctx->r13 != 0) {
        // 0x8007D3B4: addiu       $t1, $t1, 0x8
        ctx->r9 = ADD32(ctx->r9, 0X8);
            goto L_8007D41C;
    }
    // 0x8007D3B4: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x8007D3B8: subu        $t0, $fp, $s2
    ctx->r8 = SUB32(ctx->r30, ctx->r18);
    // 0x8007D3BC: slti        $at, $t0, 0x6
    ctx->r1 = SIGNED(ctx->r8) < 0X6 ? 1 : 0;
    // 0x8007D3C0: bne         $at, $zero, L_8007D3CC
    if (ctx->r1 != 0) {
        // 0x8007D3C4: or          $a2, $t1, $zero
        ctx->r6 = ctx->r9 | 0;
            goto L_8007D3CC;
    }
    // 0x8007D3C4: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x8007D3C8: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
L_8007D3CC:
    // 0x8007D3CC: sll         $a0, $t0, 2
    ctx->r4 = S32(ctx->r8 << 2);
    // 0x8007D3D0: addiu       $t9, $a0, -0x1
    ctx->r25 = ADD32(ctx->r4, -0X1);
    // 0x8007D3D4: addu        $a3, $s6, $s4
    ctx->r7 = ADD32(ctx->r22, ctx->r20);
    // 0x8007D3D8: andi        $t8, $a3, 0x6
    ctx->r24 = ctx->r7 & 0X6;
    // 0x8007D3DC: sll         $t6, $t9, 3
    ctx->r14 = S32(ctx->r25 << 3);
    // 0x8007D3E0: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x8007D3E4: ori         $t9, $t7, 0x1
    ctx->r25 = ctx->r15 | 0X1;
    // 0x8007D3E8: andi        $t6, $t9, 0xFF
    ctx->r14 = ctx->r25 & 0XFF;
    // 0x8007D3EC: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x8007D3F0: sll         $t9, $a0, 3
    ctx->r25 = S32(ctx->r4 << 3);
    // 0x8007D3F4: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8007D3F8: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x8007D3FC: addu        $t6, $t9, $a0
    ctx->r14 = ADD32(ctx->r25, ctx->r4);
    // 0x8007D400: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x8007D404: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8007D408: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x8007D40C: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x8007D410: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8007D414: sw          $a3, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r7;
    // 0x8007D418: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_8007D41C:
    // 0x8007D41C: lui         $t9, 0x511
    ctx->r25 = S32(0X511 << 16);
    // 0x8007D420: ori         $t9, $t9, 0x20
    ctx->r25 = ctx->r25 | 0X20;
    // 0x8007D424: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x8007D428: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007D42C: addu        $t7, $v1, $s4
    ctx->r15 = ADD32(ctx->r3, ctx->r20);
    // 0x8007D430: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8007D434: addiu       $a2, $s0, -0x1
    ctx->r6 = ADD32(ctx->r16, -0X1);
    // 0x8007D438: addiu       $a3, $s1, -0x1
    ctx->r7 = ADD32(ctx->r17, -0X1);
    // 0x8007D43C: addiu       $t0, $t2, 0x3
    ctx->r8 = ADD32(ctx->r10, 0X3);
    // 0x8007D440: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8007D444: sll         $t8, $a2, 5
    ctx->r24 = S32(ctx->r6 << 5);
    // 0x8007D448: sll         $t9, $a3, 5
    ctx->r25 = S32(ctx->r7 << 5);
    // 0x8007D44C: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x8007D450: addiu       $t6, $t2, 0x2
    ctx->r14 = ADD32(ctx->r10, 0X2);
    // 0x8007D454: addiu       $a0, $t2, 0x4
    ctx->r4 = ADD32(ctx->r10, 0X4);
    // 0x8007D458: slti        $at, $t5, 0x5
    ctx->r1 = SIGNED(ctx->r13) < 0X5 ? 1 : 0;
    // 0x8007D45C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x8007D460: sb          $s7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r23;
    // 0x8007D464: sb          $t0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r8;
    // 0x8007D468: sb          $t6, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r14;
    // 0x8007D46C: sb          $t3, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r11;
    // 0x8007D470: sh          $t8, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r24;
    // 0x8007D474: sh          $t9, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r25;
    // 0x8007D478: sh          $t8, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r24;
    // 0x8007D47C: sh          $zero, 0xA($v1)
    MEM_H(0XA, ctx->r3) = 0;
    // 0x8007D480: sh          $s5, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r21;
    // 0x8007D484: sh          $zero, 0xE($v1)
    MEM_H(0XE, ctx->r3) = 0;
    // 0x8007D488: sb          $s7, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r23;
    // 0x8007D48C: sb          $a0, 0x11($v1)
    MEM_B(0X11, ctx->r3) = ctx->r4;
    // 0x8007D490: sb          $t0, 0x12($v1)
    MEM_B(0X12, ctx->r3) = ctx->r8;
    // 0x8007D494: sb          $t3, 0x13($v1)
    MEM_B(0X13, ctx->r3) = ctx->r11;
    // 0x8007D498: sh          $s5, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r21;
    // 0x8007D49C: sh          $t9, 0x16($v1)
    MEM_H(0X16, ctx->r3) = ctx->r25;
    // 0x8007D4A0: sh          $t8, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r24;
    // 0x8007D4A4: sh          $t9, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = ctx->r25;
    // 0x8007D4A8: sh          $s5, 0x1C($v1)
    MEM_H(0X1C, ctx->r3) = ctx->r21;
    // 0x8007D4AC: sh          $zero, 0x1E($v1)
    MEM_H(0X1E, ctx->r3) = 0;
    // 0x8007D4B0: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x8007D4B4: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x8007D4B8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8007D4BC: bne         $at, $zero, L_8007D4CC
    if (ctx->r1 != 0) {
        // 0x8007D4C0: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_8007D4CC;
    }
    // 0x8007D4C0: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x8007D4C4: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x8007D4C8: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_8007D4CC:
    // 0x8007D4CC: slt         $at, $s2, $fp
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r30) ? 1 : 0;
    // 0x8007D4D0: bne         $at, $zero, L_8007D2CC
    if (ctx->r1 != 0) {
        // 0x8007D4D4: lw          $t6, 0x44($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X44);
            goto L_8007D2CC;
    }
    // 0x8007D4D4: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
L_8007D4D8:
    // 0x8007D4D8: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x8007D4DC: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8007D4E0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007D4E4: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8007D4E8: addiu       $a1, $t1, 0x8
    ctx->r5 = ADD32(ctx->r9, 0X8);
    // 0x8007D4EC: lui         $t6, 0xB800
    ctx->r14 = S32(0XB800 << 16);
    // 0x8007D4F0: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8007D4F4: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x8007D4F8: addiu       $t1, $a1, 0x8
    ctx->r9 = ADD32(ctx->r5, 0X8);
    // 0x8007D4FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007D500: sw          $t1, 0x6904($at)
    MEM_W(0X6904, ctx->r1) = ctx->r9;
    // 0x8007D504: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007D508: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8007D50C: sw          $v0, 0x6900($at)
    MEM_W(0X6900, ctx->r1) = ctx->r2;
    // 0x8007D510: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007D514: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x8007D518: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x8007D51C: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x8007D520: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x8007D524: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x8007D528: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x8007D52C: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x8007D530: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x8007D534: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x8007D538: sw          $v1, 0x6908($at)
    MEM_W(0X6908, ctx->r1) = ctx->r3;
    // 0x8007D53C: jr          $ra
    // 0x8007D540: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8007D540: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void material_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007D544: addiu       $sp, $sp, -0x280
    ctx->r29 = ADD32(ctx->r29, -0X280);
    // 0x8007D548: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007D54C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8007D550: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8007D554: sw          $a1, 0x284($sp)
    MEM_W(0X284, ctx->r29) = ctx->r5;
    // 0x8007D558: lbu         $v1, 0x2($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X2);
    // 0x8007D55C: sw          $a1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r5;
    // 0x8007D560: sra         $t7, $v1, 4
    ctx->r15 = S32(SIGNED(ctx->r3) >> 4);
    // 0x8007D564: andi        $t8, $t7, 0xF
    ctx->r24 = ctx->r15 & 0XF;
    // 0x8007D568: sw          $t8, 0x278($sp)
    MEM_W(0X278, ctx->r29) = ctx->r24;
    // 0x8007D56C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8007D570: lbu         $s0, 0x1($a0)
    ctx->r16 = MEM_BU(ctx->r4, 0X1);
    // 0x8007D574: lbu         $t5, 0x0($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X0);
    // 0x8007D578: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8007D57C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007D580: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8007D584: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8007D588: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8007D58C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8007D590: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8007D594: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8007D598: andi        $t4, $v1, 0xF
    ctx->r12 = ctx->r3 & 0XF;
L_8007D59C:
    // 0x8007D59C: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8007D5A0: beq         $at, $zero, L_8007D5B0
    if (ctx->r1 == 0) {
        // 0x8007D5A4: sll         $t7, $v0, 1
        ctx->r15 = S32(ctx->r2 << 1);
            goto L_8007D5B0;
    }
    // 0x8007D5A4: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x8007D5A8: b           L_8007D5BC
    // 0x8007D5AC: addiu       $t2, $a2, 0x1
    ctx->r10 = ADD32(ctx->r6, 0X1);
        goto L_8007D5BC;
    // 0x8007D5AC: addiu       $t2, $a2, 0x1
    ctx->r10 = ADD32(ctx->r6, 0X1);
L_8007D5B0:
    // 0x8007D5B0: bne         $v0, $t5, L_8007D5C0
    if (ctx->r2 != ctx->r13) {
        // 0x8007D5B4: slt         $at, $v0, $s0
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
            goto L_8007D5C0;
    }
    // 0x8007D5B4: slt         $at, $v0, $s0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8007D5B8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_8007D5BC:
    // 0x8007D5BC: slt         $at, $v0, $s0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
L_8007D5C0:
    // 0x8007D5C0: beq         $at, $zero, L_8007D5D0
    if (ctx->r1 == 0) {
        // 0x8007D5C4: addiu       $v1, $a2, 0x1
        ctx->r3 = ADD32(ctx->r6, 0X1);
            goto L_8007D5D0;
    }
    // 0x8007D5C4: addiu       $v1, $a2, 0x1
    ctx->r3 = ADD32(ctx->r6, 0X1);
    // 0x8007D5C8: b           L_8007D5DC
    // 0x8007D5CC: or          $t3, $v1, $zero
    ctx->r11 = ctx->r3 | 0;
        goto L_8007D5DC;
    // 0x8007D5CC: or          $t3, $v1, $zero
    ctx->r11 = ctx->r3 | 0;
L_8007D5D0:
    // 0x8007D5D0: bne         $v0, $s0, L_8007D5E0
    if (ctx->r2 != ctx->r16) {
        // 0x8007D5D4: or          $a2, $v1, $zero
        ctx->r6 = ctx->r3 | 0;
            goto L_8007D5E0;
    }
    // 0x8007D5D4: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x8007D5D8: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_8007D5DC:
    // 0x8007D5DC: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_8007D5E0:
    // 0x8007D5E0: bne         $v1, $a0, L_8007D59C
    if (ctx->r3 != ctx->r4) {
        // 0x8007D5E4: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_8007D59C;
    }
    // 0x8007D5E4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007D5E8: bne         $t0, $zero, L_8007D604
    if (ctx->r8 != 0) {
        // 0x8007D5EC: addiu       $t9, $zero, 0x2
        ctx->r25 = ADD32(0, 0X2);
            goto L_8007D604;
    }
    // 0x8007D5EC: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8007D5F0: lh          $v0, 0x6($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X6);
    // 0x8007D5F4: nop

    // 0x8007D5F8: andi        $t8, $v0, 0x40
    ctx->r24 = ctx->r2 & 0X40;
    // 0x8007D5FC: beq         $t8, $zero, L_8007D614
    if (ctx->r24 == 0) {
        // 0x8007D600: nop
    
            goto L_8007D614;
    }
    // 0x8007D600: nop

L_8007D604:
    // 0x8007D604: sw          $t9, 0x26C($sp)
    MEM_W(0X26C, ctx->r29) = ctx->r25;
    // 0x8007D608: lh          $v0, 0x6($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X6);
    // 0x8007D60C: b           L_8007D618
    // 0x8007D610: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
        goto L_8007D618;
    // 0x8007D610: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_8007D614:
    // 0x8007D614: sw          $zero, 0x26C($sp)
    MEM_W(0X26C, ctx->r29) = 0;
L_8007D618:
    // 0x8007D618: bne         $t1, $zero, L_8007D628
    if (ctx->r9 != 0) {
        // 0x8007D61C: andi        $t8, $v0, 0x400
        ctx->r24 = ctx->r2 & 0X400;
            goto L_8007D628;
    }
    // 0x8007D61C: andi        $t8, $v0, 0x400
    ctx->r24 = ctx->r2 & 0X400;
    // 0x8007D620: andi        $t6, $v0, 0x80
    ctx->r14 = ctx->r2 & 0X80;
    // 0x8007D624: beq         $t6, $zero, L_8007D638
    if (ctx->r14 == 0) {
        // 0x8007D628: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_8007D638;
    }
L_8007D628:
    // 0x8007D628: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8007D62C: sw          $t7, 0x268($sp)
    MEM_W(0X268, ctx->r29) = ctx->r15;
    // 0x8007D630: b           L_8007D63C
    // 0x8007D634: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
        goto L_8007D63C;
    // 0x8007D634: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
L_8007D638:
    // 0x8007D638: sw          $zero, 0x268($sp)
    MEM_W(0X268, ctx->r29) = 0;
L_8007D63C:
    // 0x8007D63C: bne         $t8, $zero, L_8007E69C
    if (ctx->r24 != 0) {
        // 0x8007D640: nop
    
            goto L_8007E69C;
    }
    // 0x8007D640: nop

    // 0x8007D644: sw          $t2, 0x264($sp)
    MEM_W(0X264, ctx->r29) = ctx->r10;
    // 0x8007D648: sw          $t3, 0x260($sp)
    MEM_W(0X260, ctx->r29) = ctx->r11;
    // 0x8007D64C: bne         $t4, $zero, L_8007D83C
    if (ctx->r12 != 0) {
        // 0x8007D650: sw          $t4, 0x27C($sp)
        MEM_W(0X27C, ctx->r29) = ctx->r12;
            goto L_8007D83C;
    }
    // 0x8007D650: sw          $t4, 0x27C($sp)
    MEM_W(0X27C, ctx->r29) = ctx->r12;
    // 0x8007D654: lw          $t2, 0x284($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X284);
    // 0x8007D658: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007D65C: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x8007D660: addu        $t6, $s1, $at
    ctx->r14 = ADD32(ctx->r17, ctx->r1);
    // 0x8007D664: lui         $t9, 0xFD18
    ctx->r25 = S32(0XFD18 << 16);
    // 0x8007D668: addiu       $a3, $t2, 0x8
    ctx->r7 = ADD32(ctx->r10, 0X8);
    // 0x8007D66C: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x8007D670: lui         $t7, 0xF518
    ctx->r15 = S32(0XF518 << 16);
    // 0x8007D674: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8007D678: sw          $t6, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r14;
    // 0x8007D67C: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007D680: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x8007D684: lw          $v0, 0x268($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X268);
    // 0x8007D688: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
    // 0x8007D68C: lw          $v1, 0x260($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X260);
    // 0x8007D690: andi        $t8, $v0, 0x3
    ctx->r24 = ctx->r2 & 0X3;
    // 0x8007D694: sll         $v0, $t8, 18
    ctx->r2 = S32(ctx->r24 << 18);
    // 0x8007D698: lw          $a2, 0x264($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X264);
    // 0x8007D69C: andi        $t8, $a1, 0x3
    ctx->r24 = ctx->r5 & 0X3;
    // 0x8007D6A0: andi        $t6, $v1, 0xF
    ctx->r14 = ctx->r3 & 0XF;
    // 0x8007D6A4: sll         $v1, $t6, 14
    ctx->r3 = S32(ctx->r14 << 14);
    // 0x8007D6A8: sll         $a1, $t8, 8
    ctx->r5 = S32(ctx->r24 << 8);
    // 0x8007D6AC: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007D6B0: or          $t8, $v0, $at
    ctx->r24 = ctx->r2 | ctx->r1;
    // 0x8007D6B4: andi        $t6, $a2, 0xF
    ctx->r14 = ctx->r6 & 0XF;
    // 0x8007D6B8: sll         $a2, $t6, 4
    ctx->r6 = S32(ctx->r14 << 4);
    // 0x8007D6BC: or          $t9, $t8, $v1
    ctx->r25 = ctx->r24 | ctx->r3;
    // 0x8007D6C0: or          $t6, $t9, $a1
    ctx->r14 = ctx->r25 | ctx->r5;
    // 0x8007D6C4: or          $t7, $t6, $a2
    ctx->r15 = ctx->r14 | ctx->r6;
    // 0x8007D6C8: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D6CC: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x8007D6D0: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x8007D6D4: mflo        $t0
    ctx->r8 = lo;
    // 0x8007D6D8: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8007D6DC: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D6E0: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x8007D6E4: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8007D6E8: or          $t4, $a3, $zero
    ctx->r12 = ctx->r7 | 0;
    // 0x8007D6EC: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8007D6F0: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x8007D6F4: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x8007D6F8: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x8007D6FC: beq         $at, $zero, L_8007D70C
    if (ctx->r1 == 0) {
        // 0x8007D700: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_8007D70C;
    }
    // 0x8007D700: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D704: b           L_8007D710
    // 0x8007D708: or          $ra, $t0, $zero
    ctx->r31 = ctx->r8 | 0;
        goto L_8007D710;
    // 0x8007D708: or          $ra, $t0, $zero
    ctx->r31 = ctx->r8 | 0;
L_8007D70C:
    // 0x8007D70C: addiu       $ra, $zero, 0x7FF
    ctx->r31 = ADD32(0, 0X7FF);
L_8007D710:
    // 0x8007D710: sll         $t0, $t5, 2
    ctx->r8 = S32(ctx->r13 << 2);
    // 0x8007D714: bgez        $t0, L_8007D724
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8007D718: sra         $t6, $t0, 3
        ctx->r14 = S32(SIGNED(ctx->r8) >> 3);
            goto L_8007D724;
    }
    // 0x8007D718: sra         $t6, $t0, 3
    ctx->r14 = S32(SIGNED(ctx->r8) >> 3);
    // 0x8007D71C: addiu       $at, $t0, 0x7
    ctx->r1 = ADD32(ctx->r8, 0X7);
    // 0x8007D720: sra         $t6, $at, 3
    ctx->r14 = S32(SIGNED(ctx->r1) >> 3);
L_8007D724:
    // 0x8007D724: bgtz        $t6, L_8007D734
    if (SIGNED(ctx->r14) > 0) {
        // 0x8007D728: or          $t0, $t6, $zero
        ctx->r8 = ctx->r14 | 0;
            goto L_8007D734;
    }
    // 0x8007D728: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
    // 0x8007D72C: b           L_8007D738
    // 0x8007D730: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_8007D738;
    // 0x8007D730: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8007D734:
    // 0x8007D734: or          $t2, $t0, $zero
    ctx->r10 = ctx->r8 | 0;
L_8007D738:
    // 0x8007D738: bgtz        $t0, L_8007D748
    if (SIGNED(ctx->r8) > 0) {
        // 0x8007D73C: addiu       $t7, $t2, 0x7FF
        ctx->r15 = ADD32(ctx->r10, 0X7FF);
            goto L_8007D748;
    }
    // 0x8007D73C: addiu       $t7, $t2, 0x7FF
    ctx->r15 = ADD32(ctx->r10, 0X7FF);
    // 0x8007D740: b           L_8007D74C
    // 0x8007D744: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_8007D74C;
    // 0x8007D744: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8007D748:
    // 0x8007D748: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_8007D74C:
    // 0x8007D74C: div         $zero, $t7, $a0
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r4)));
    // 0x8007D750: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x8007D754: bne         $a0, $zero, L_8007D760
    if (ctx->r4 != 0) {
        // 0x8007D758: nop
    
            goto L_8007D760;
    }
    // 0x8007D758: nop

    // 0x8007D75C: break       7
    do_break(2147997532);
L_8007D760:
    // 0x8007D760: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007D764: bne         $a0, $at, L_8007D778
    if (ctx->r4 != ctx->r1) {
        // 0x8007D768: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007D778;
    }
    // 0x8007D768: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007D76C: bne         $t7, $at, L_8007D778
    if (ctx->r15 != ctx->r1) {
        // 0x8007D770: nop
    
            goto L_8007D778;
    }
    // 0x8007D770: nop

    // 0x8007D774: break       6
    do_break(2147997556);
L_8007D778:
    // 0x8007D778: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007D77C: andi        $t7, $ra, 0xFFF
    ctx->r15 = ctx->r31 & 0XFFF;
    // 0x8007D780: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D784: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x8007D788: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D78C: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x8007D790: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D794: mflo        $t8
    ctx->r24 = lo;
    // 0x8007D798: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x8007D79C: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x8007D7A0: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x8007D7A4: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8007D7A8: sw          $t9, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r25;
    // 0x8007D7AC: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x8007D7B0: addiu       $t8, $t6, 0x7
    ctx->r24 = ADD32(ctx->r14, 0X7);
    // 0x8007D7B4: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8007D7B8: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x8007D7BC: sra         $t9, $t8, 3
    ctx->r25 = S32(SIGNED(ctx->r24) >> 3);
    // 0x8007D7C0: andi        $t7, $t9, 0x1FF
    ctx->r15 = ctx->r25 & 0X1FF;
    // 0x8007D7C4: sll         $t6, $t7, 9
    ctx->r14 = S32(ctx->r15 << 9);
    // 0x8007D7C8: or          $t9, $v0, $v1
    ctx->r25 = ctx->r2 | ctx->r3;
    // 0x8007D7CC: lui         $at, 0xF518
    ctx->r1 = S32(0XF518 << 16);
    // 0x8007D7D0: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x8007D7D4: or          $t7, $t9, $a1
    ctx->r15 = ctx->r25 | ctx->r5;
    // 0x8007D7D8: or          $t6, $t7, $a2
    ctx->r14 = ctx->r15 | ctx->r6;
    // 0x8007D7DC: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8007D7E0: addiu       $t9, $t5, -0x1
    ctx->r25 = ADD32(ctx->r13, -0X1);
    // 0x8007D7E4: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8007D7E8: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x8007D7EC: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8007D7F0: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x8007D7F4: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x8007D7F8: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8007D7FC: addiu       $t9, $s0, -0x1
    ctx->r25 = ADD32(ctx->r16, -0X1);
    // 0x8007D800: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8007D804: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x8007D808: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x8007D80C: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x8007D810: sw          $t9, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r25;
    // 0x8007D814: lw          $t7, 0x278($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X278);
    // 0x8007D818: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007D81C: beq         $t7, $zero, L_8007D82C
    if (ctx->r15 == 0) {
        // 0x8007D820: nop
    
            goto L_8007D82C;
    }
    // 0x8007D820: nop

    // 0x8007D824: bne         $t7, $at, L_8007D840
    if (ctx->r15 != ctx->r1) {
        // 0x8007D828: lw          $t9, 0x27C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X27C);
            goto L_8007D840;
    }
    // 0x8007D828: lw          $t9, 0x27C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X27C);
L_8007D82C:
    // 0x8007D82C: lh          $t8, 0x6($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X6);
    // 0x8007D830: nop

    // 0x8007D834: ori         $t6, $t8, 0x4
    ctx->r14 = ctx->r24 | 0X4;
    // 0x8007D838: sh          $t6, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r14;
L_8007D83C:
    // 0x8007D83C: lw          $t9, 0x27C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X27C);
L_8007D840:
    // 0x8007D840: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007D844: bne         $t9, $at, L_8007DA48
    if (ctx->r25 != ctx->r1) {
        // 0x8007D848: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8007DA48;
    }
    // 0x8007D848: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8007D84C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007D850: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x8007D854: addu        $t8, $s1, $at
    ctx->r24 = ADD32(ctx->r17, ctx->r1);
    // 0x8007D858: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8007D85C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D860: lui         $t7, 0xFD10
    ctx->r15 = S32(0XFD10 << 16);
    // 0x8007D864: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007D868: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x8007D86C: lui         $t6, 0xF510
    ctx->r14 = S32(0XF510 << 16);
    // 0x8007D870: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8007D874: lw          $v0, 0x268($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X268);
    // 0x8007D878: lw          $v1, 0x260($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X260);
    // 0x8007D87C: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
    // 0x8007D880: andi        $t9, $v0, 0x3
    ctx->r25 = ctx->r2 & 0X3;
    // 0x8007D884: lw          $a2, 0x264($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X264);
    // 0x8007D888: sll         $v0, $t9, 18
    ctx->r2 = S32(ctx->r25 << 18);
    // 0x8007D88C: andi        $t8, $v1, 0xF
    ctx->r24 = ctx->r3 & 0XF;
    // 0x8007D890: sll         $v1, $t8, 14
    ctx->r3 = S32(ctx->r24 << 14);
    // 0x8007D894: andi        $t9, $a1, 0x3
    ctx->r25 = ctx->r5 & 0X3;
    // 0x8007D898: sll         $a1, $t9, 8
    ctx->r5 = S32(ctx->r25 << 8);
    // 0x8007D89C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007D8A0: andi        $t8, $a2, 0xF
    ctx->r24 = ctx->r6 & 0XF;
    // 0x8007D8A4: sll         $t6, $t8, 4
    ctx->r14 = S32(ctx->r24 << 4);
    // 0x8007D8A8: or          $t9, $v0, $at
    ctx->r25 = ctx->r2 | ctx->r1;
    // 0x8007D8AC: or          $t7, $t9, $v1
    ctx->r15 = ctx->r25 | ctx->r3;
    // 0x8007D8B0: or          $t8, $t7, $a1
    ctx->r24 = ctx->r15 | ctx->r5;
    // 0x8007D8B4: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x8007D8B8: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007D8BC: or          $t6, $t8, $t6
    ctx->r14 = ctx->r24 | ctx->r14;
    // 0x8007D8C0: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D8C4: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x8007D8C8: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x8007D8CC: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8007D8D0: sll         $t4, $t5, 1
    ctx->r12 = S32(ctx->r13 << 1);
    // 0x8007D8D4: addiu       $t8, $t4, 0x7
    ctx->r24 = ADD32(ctx->r12, 0X7);
    // 0x8007D8D8: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8007D8DC: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D8E0: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x8007D8E4: sra         $t6, $t8, 3
    ctx->r14 = S32(SIGNED(ctx->r24) >> 3);
    // 0x8007D8E8: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x8007D8EC: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x8007D8F0: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x8007D8F4: andi        $t9, $t6, 0x1FF
    ctx->r25 = ctx->r14 & 0X1FF;
    // 0x8007D8F8: sll         $t7, $t9, 9
    ctx->r15 = S32(ctx->r25 << 9);
    // 0x8007D8FC: or          $t8, $v0, $v1
    ctx->r24 = ctx->r2 | ctx->r3;
    // 0x8007D900: or          $t6, $t8, $a1
    ctx->r14 = ctx->r24 | ctx->r5;
    // 0x8007D904: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x8007D908: addiu       $t7, $t5, -0x1
    ctx->r15 = ADD32(ctx->r13, -0X1);
    // 0x8007D90C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8007D910: or          $t9, $t6, $a2
    ctx->r25 = ctx->r14 | ctx->r6;
    // 0x8007D914: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x8007D918: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x8007D91C: addiu       $t7, $s0, -0x1
    ctx->r15 = ADD32(ctx->r16, -0X1);
    // 0x8007D920: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8007D924: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x8007D928: mflo        $t0
    ctx->r8 = lo;
    // 0x8007D92C: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8007D930: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x8007D934: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x8007D938: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8007D93C: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8007D940: sw          $t3, 0x21C($sp)
    MEM_W(0X21C, ctx->r29) = ctx->r11;
    // 0x8007D944: beq         $at, $zero, L_8007D954
    if (ctx->r1 == 0) {
        // 0x8007D948: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_8007D954;
    }
    // 0x8007D948: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D94C: b           L_8007D958
    // 0x8007D950: or          $ra, $t0, $zero
    ctx->r31 = ctx->r8 | 0;
        goto L_8007D958;
    // 0x8007D950: or          $ra, $t0, $zero
    ctx->r31 = ctx->r8 | 0;
L_8007D954:
    // 0x8007D954: addiu       $ra, $zero, 0x7FF
    ctx->r31 = ADD32(0, 0X7FF);
L_8007D958:
    // 0x8007D958: bgez        $t4, L_8007D968
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8007D95C: sra         $t3, $t4, 3
        ctx->r11 = S32(SIGNED(ctx->r12) >> 3);
            goto L_8007D968;
    }
    // 0x8007D95C: sra         $t3, $t4, 3
    ctx->r11 = S32(SIGNED(ctx->r12) >> 3);
    // 0x8007D960: addiu       $at, $t4, 0x7
    ctx->r1 = ADD32(ctx->r12, 0X7);
    // 0x8007D964: sra         $t3, $at, 3
    ctx->r11 = S32(SIGNED(ctx->r1) >> 3);
L_8007D968:
    // 0x8007D968: bgtz        $t3, L_8007D978
    if (SIGNED(ctx->r11) > 0) {
        // 0x8007D96C: or          $t2, $t3, $zero
        ctx->r10 = ctx->r11 | 0;
            goto L_8007D978;
    }
    // 0x8007D96C: or          $t2, $t3, $zero
    ctx->r10 = ctx->r11 | 0;
    // 0x8007D970: b           L_8007D978
    // 0x8007D974: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_8007D978;
    // 0x8007D974: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8007D978:
    // 0x8007D978: bgtz        $t3, L_8007D988
    if (SIGNED(ctx->r11) > 0) {
        // 0x8007D97C: addiu       $t8, $t2, 0x7FF
        ctx->r24 = ADD32(ctx->r10, 0X7FF);
            goto L_8007D988;
    }
    // 0x8007D97C: addiu       $t8, $t2, 0x7FF
    ctx->r24 = ADD32(ctx->r10, 0X7FF);
    // 0x8007D980: b           L_8007D98C
    // 0x8007D984: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_8007D98C;
    // 0x8007D984: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8007D988:
    // 0x8007D988: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
L_8007D98C:
    // 0x8007D98C: div         $zero, $t8, $a0
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r4)));
    // 0x8007D990: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8007D994: bne         $a0, $zero, L_8007D9A0
    if (ctx->r4 != 0) {
        // 0x8007D998: nop
    
            goto L_8007D9A0;
    }
    // 0x8007D998: nop

    // 0x8007D99C: break       7
    do_break(2147998108);
L_8007D9A0:
    // 0x8007D9A0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007D9A4: bne         $a0, $at, L_8007D9B8
    if (ctx->r4 != ctx->r1) {
        // 0x8007D9A8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007D9B8;
    }
    // 0x8007D9A8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007D9AC: bne         $t8, $at, L_8007D9B8
    if (ctx->r24 != ctx->r1) {
        // 0x8007D9B0: nop
    
            goto L_8007D9B8;
    }
    // 0x8007D9B0: nop

    // 0x8007D9B4: break       6
    do_break(2147998132);
L_8007D9B8:
    // 0x8007D9B8: andi        $t8, $ra, 0xFFF
    ctx->r24 = ctx->r31 & 0XFFF;
    // 0x8007D9BC: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007D9C0: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D9C4: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007D9C8: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D9CC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007D9D0: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D9D4: mflo        $t9
    ctx->r25 = lo;
    // 0x8007D9D8: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8007D9DC: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x8007D9E0: lw          $t8, 0x21C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X21C);
    // 0x8007D9E4: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8007D9E8: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x8007D9EC: sw          $t6, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r14;
    // 0x8007D9F0: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8007D9F4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007D9F8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007D9FC: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8007DA00: lui         $at, 0xF510
    ctx->r1 = S32(0XF510 << 16);
    // 0x8007DA04: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x8007DA08: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8007DA0C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8007DA10: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x8007DA14: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8007DA18: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8007DA1C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8007DA20: lw          $v0, 0x278($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X278);
    // 0x8007DA24: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007DA28: beq         $v0, $zero, L_8007DA38
    if (ctx->r2 == 0) {
        // 0x8007DA2C: sw          $t9, 0x4($a1)
        MEM_W(0X4, ctx->r5) = ctx->r25;
            goto L_8007DA38;
    }
    // 0x8007DA2C: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x8007DA30: bne         $v0, $at, L_8007DA4C
    if (ctx->r2 != ctx->r1) {
        // 0x8007DA34: lw          $t7, 0x27C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X27C);
            goto L_8007DA4C;
    }
    // 0x8007DA34: lw          $t7, 0x27C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X27C);
L_8007DA38:
    // 0x8007DA38: lh          $t6, 0x6($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X6);
    // 0x8007DA3C: nop

    // 0x8007DA40: ori         $t8, $t6, 0x4
    ctx->r24 = ctx->r14 | 0X4;
    // 0x8007DA44: sh          $t8, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r24;
L_8007DA48:
    // 0x8007DA48: lw          $t7, 0x27C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X27C);
L_8007DA4C:
    // 0x8007DA4C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8007DA50: bne         $t7, $at, L_8007DCF4
    if (ctx->r15 != ctx->r1) {
        // 0x8007DA54: lw          $t6, 0x27C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X27C);
            goto L_8007DCF4;
    }
    // 0x8007DA54: lw          $t6, 0x27C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X27C);
    // 0x8007DA58: lw          $v0, 0x268($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X268);
    // 0x8007DA5C: lw          $v1, 0x260($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X260);
    // 0x8007DA60: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
    // 0x8007DA64: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007DA68: andi        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 & 0X3;
    // 0x8007DA6C: sll         $v0, $t6, 18
    ctx->r2 = S32(ctx->r14 << 18);
    // 0x8007DA70: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x8007DA74: lw          $a2, 0x264($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X264);
    // 0x8007DA78: addu        $t9, $s1, $at
    ctx->r25 = ADD32(ctx->r17, ctx->r1);
    // 0x8007DA7C: andi        $t7, $v1, 0xF
    ctx->r15 = ctx->r3 & 0XF;
    // 0x8007DA80: andi        $t6, $a1, 0x3
    ctx->r14 = ctx->r5 & 0X3;
    // 0x8007DA84: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007DA88: sll         $a1, $t6, 8
    ctx->r5 = S32(ctx->r14 << 8);
    // 0x8007DA8C: sll         $v1, $t7, 14
    ctx->r3 = S32(ctx->r15 << 14);
    // 0x8007DA90: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007DA94: or          $t6, $v0, $at
    ctx->r14 = ctx->r2 | ctx->r1;
    // 0x8007DA98: andi        $t7, $a2, 0xF
    ctx->r15 = ctx->r6 & 0XF;
    // 0x8007DA9C: sll         $a2, $t7, 4
    ctx->r6 = S32(ctx->r15 << 4);
    // 0x8007DAA0: or          $t8, $t6, $v1
    ctx->r24 = ctx->r14 | ctx->r3;
    // 0x8007DAA4: lh          $a0, 0x8($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X8);
    // 0x8007DAA8: sw          $t9, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r25;
    // 0x8007DAAC: or          $t7, $t8, $a1
    ctx->r15 = ctx->r24 | ctx->r5;
    // 0x8007DAB0: or          $t9, $t7, $a2
    ctx->r25 = ctx->r15 | ctx->r6;
    // 0x8007DAB4: or          $t6, $v0, $v1
    ctx->r14 = ctx->r2 | ctx->r3;
    // 0x8007DAB8: or          $t8, $t6, $a1
    ctx->r24 = ctx->r14 | ctx->r5;
    // 0x8007DABC: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x8007DAC0: addiu       $t9, $t5, -0x1
    ctx->r25 = ADD32(ctx->r13, -0X1);
    // 0x8007DAC4: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8007DAC8: or          $t7, $t8, $a2
    ctx->r15 = ctx->r24 | ctx->r6;
    // 0x8007DACC: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x8007DAD0: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8007DAD4: addiu       $t9, $s0, -0x1
    ctx->r25 = ADD32(ctx->r16, -0X1);
    // 0x8007DAD8: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8007DADC: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x8007DAE0: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x8007DAE4: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x8007DAE8: mflo        $t2
    ctx->r10 = lo;
    // 0x8007DAEC: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8007DAF0: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x8007DAF4: sw          $t5, 0x274($sp)
    MEM_W(0X274, ctx->r29) = ctx->r13;
    // 0x8007DAF8: jal         0x8007F3B4
    // 0x8007DAFC: sw          $a3, 0x248($sp)
    MEM_W(0X248, ctx->r29) = ctx->r7;
    tex_palette_id(rdram, ctx);
        goto after_0;
    // 0x8007DAFC: sw          $a3, 0x248($sp)
    MEM_W(0X248, ctx->r29) = ctx->r7;
    after_0:
    // 0x8007DB00: lw          $a3, 0x248($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X248);
    // 0x8007DB04: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8007DB08: lw          $t5, 0x274($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X274);
    // 0x8007DB0C: lui         $t6, 0xFD50
    ctx->r14 = S32(0XFD50 << 16);
    // 0x8007DB10: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007DB14: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8007DB18: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x8007DB1C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DB20: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8007DB24: lui         $t8, 0xF550
    ctx->r24 = S32(0XF550 << 16);
    // 0x8007DB28: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8007DB2C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007DB30: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8007DB34: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DB38: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007DB3C: addiu       $t0, $t2, 0x3
    ctx->r8 = ADD32(ctx->r10, 0X3);
    // 0x8007DB40: sra         $t8, $t0, 2
    ctx->r24 = S32(SIGNED(ctx->r8) >> 2);
    // 0x8007DB44: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8007DB48: addiu       $t0, $t8, -0x1
    ctx->r8 = ADD32(ctx->r24, -0X1);
    // 0x8007DB4C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DB50: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x8007DB54: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8007DB58: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x8007DB5C: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8007DB60: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x8007DB64: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x8007DB68: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x8007DB6C: beq         $at, $zero, L_8007DB7C
    if (ctx->r1 == 0) {
        // 0x8007DB70: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_8007DB7C;
    }
    // 0x8007DB70: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DB74: b           L_8007DB80
    // 0x8007DB78: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
        goto L_8007DB80;
    // 0x8007DB78: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_8007DB7C:
    // 0x8007DB7C: addiu       $a0, $zero, 0x7FF
    ctx->r4 = ADD32(0, 0X7FF);
L_8007DB80:
    // 0x8007DB80: bgez        $t5, L_8007DB90
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8007DB84: sra         $t1, $t5, 4
        ctx->r9 = S32(SIGNED(ctx->r13) >> 4);
            goto L_8007DB90;
    }
    // 0x8007DB84: sra         $t1, $t5, 4
    ctx->r9 = S32(SIGNED(ctx->r13) >> 4);
    // 0x8007DB88: addiu       $at, $t5, 0xF
    ctx->r1 = ADD32(ctx->r13, 0XF);
    // 0x8007DB8C: sra         $t1, $at, 4
    ctx->r9 = S32(SIGNED(ctx->r1) >> 4);
L_8007DB90:
    // 0x8007DB90: addiu       $t8, $t1, 0x7FF
    ctx->r24 = ADD32(ctx->r9, 0X7FF);
    // 0x8007DB94: div         $zero, $t8, $t1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r9)));
    // 0x8007DB98: andi        $t9, $a0, 0xFFF
    ctx->r25 = ctx->r4 & 0XFFF;
    // 0x8007DB9C: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x8007DBA0: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007DBA4: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8007DBA8: bne         $t1, $zero, L_8007DBB4
    if (ctx->r9 != 0) {
        // 0x8007DBAC: nop
    
            goto L_8007DBB4;
    }
    // 0x8007DBAC: nop

    // 0x8007DBB0: break       7
    do_break(2147998640);
L_8007DBB4:
    // 0x8007DBB4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007DBB8: bne         $t1, $at, L_8007DBCC
    if (ctx->r9 != ctx->r1) {
        // 0x8007DBBC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007DBCC;
    }
    // 0x8007DBBC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007DBC0: bne         $t8, $at, L_8007DBCC
    if (ctx->r24 != ctx->r1) {
        // 0x8007DBC4: nop
    
            goto L_8007DBCC;
    }
    // 0x8007DBC4: nop

    // 0x8007DBC8: break       6
    do_break(2147998664);
L_8007DBCC:
    // 0x8007DBCC: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007DBD0: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DBD4: lui         $at, 0xF540
    ctx->r1 = S32(0XF540 << 16);
    // 0x8007DBD8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007DBDC: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DBE0: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x8007DBE4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DBE8: mflo        $t9
    ctx->r25 = lo;
    // 0x8007DBEC: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8007DBF0: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x8007DBF4: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x8007DBF8: sra         $t7, $t5, 1
    ctx->r15 = S32(SIGNED(ctx->r13) >> 1);
    // 0x8007DBFC: addiu       $t6, $t7, 0x7
    ctx->r14 = ADD32(ctx->r15, 0X7);
    // 0x8007DC00: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8007DC04: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8007DC08: sra         $t8, $t6, 3
    ctx->r24 = S32(SIGNED(ctx->r14) >> 3);
    // 0x8007DC0C: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x8007DC10: sll         $t7, $t9, 9
    ctx->r15 = S32(ctx->r25 << 9);
    // 0x8007DC14: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x8007DC18: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8007DC1C: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8007DC20: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8007DC24: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x8007DC28: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x8007DC2C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8007DC30: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8007DC34: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007DC38: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x8007DC3C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DC40: lui         $t6, 0xFD10
    ctx->r14 = S32(0XFD10 << 16);
    // 0x8007DC44: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8007DC48: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8007DC4C: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8007DC50: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DC54: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007DC58: lui         $t8, 0xE800
    ctx->r24 = S32(0XE800 << 16);
    // 0x8007DC5C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007DC60: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8007DC64: lui         $t9, 0xF500
    ctx->r25 = S32(0XF500 << 16);
    // 0x8007DC68: ori         $t9, $t9, 0x100
    ctx->r25 = ctx->r25 | 0X100;
    // 0x8007DC6C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DC70: lui         $t7, 0x700
    ctx->r15 = S32(0X700 << 16);
    // 0x8007DC74: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x8007DC78: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x8007DC7C: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8007DC80: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DC84: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x8007DC88: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8007DC8C: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8007DC90: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x8007DC94: lw          $a0, 0x278($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X278);
    // 0x8007DC98: lui         $t9, 0x703
    ctx->r25 = S32(0X703 << 16);
    // 0x8007DC9C: ori         $t9, $t9, 0xC000
    ctx->r25 = ctx->r25 | 0XC000;
    // 0x8007DCA0: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DCA4: lui         $t8, 0xF000
    ctx->r24 = S32(0XF000 << 16);
    // 0x8007DCA8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007DCAC: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007DCB0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8007DCB4: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8007DCB8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8007DCBC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8007DCC0: lh          $t6, 0x6($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X6);
    // 0x8007DCC4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DCC8: ori         $t8, $t6, 0x20
    ctx->r24 = ctx->r14 | 0X20;
    // 0x8007DCCC: beq         $a0, $zero, L_8007DCE0
    if (ctx->r4 == 0) {
        // 0x8007DCD0: sh          $t8, 0x6($s1)
        MEM_H(0X6, ctx->r17) = ctx->r24;
            goto L_8007DCE0;
    }
    // 0x8007DCD0: sh          $t8, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r24;
    // 0x8007DCD4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007DCD8: bne         $a0, $at, L_8007DCF4
    if (ctx->r4 != ctx->r1) {
        // 0x8007DCDC: lw          $t6, 0x27C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X27C);
            goto L_8007DCF4;
    }
    // 0x8007DCDC: lw          $t6, 0x27C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X27C);
L_8007DCE0:
    // 0x8007DCE0: lh          $t9, 0x6($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X6);
    // 0x8007DCE4: nop

    // 0x8007DCE8: ori         $t7, $t9, 0x4
    ctx->r15 = ctx->r25 | 0X4;
    // 0x8007DCEC: sh          $t7, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r15;
    // 0x8007DCF0: lw          $t6, 0x27C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X27C);
L_8007DCF4:
    // 0x8007DCF4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8007DCF8: bne         $t6, $at, L_8007DEEC
    if (ctx->r14 != ctx->r1) {
        // 0x8007DCFC: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8007DEEC;
    }
    // 0x8007DCFC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8007DD00: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007DD04: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x8007DD08: addu        $t9, $s1, $at
    ctx->r25 = ADD32(ctx->r17, ctx->r1);
    // 0x8007DD0C: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8007DD10: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DD14: lui         $t8, 0xFD70
    ctx->r24 = S32(0XFD70 << 16);
    // 0x8007DD18: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007DD1C: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x8007DD20: lui         $t7, 0xF570
    ctx->r15 = S32(0XF570 << 16);
    // 0x8007DD24: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x8007DD28: lw          $v0, 0x268($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X268);
    // 0x8007DD2C: lw          $v1, 0x260($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X260);
    // 0x8007DD30: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
    // 0x8007DD34: andi        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 & 0X3;
    // 0x8007DD38: lw          $a2, 0x264($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X264);
    // 0x8007DD3C: sll         $v0, $t6, 18
    ctx->r2 = S32(ctx->r14 << 18);
    // 0x8007DD40: andi        $t9, $v1, 0xF
    ctx->r25 = ctx->r3 & 0XF;
    // 0x8007DD44: sll         $v1, $t9, 14
    ctx->r3 = S32(ctx->r25 << 14);
    // 0x8007DD48: andi        $t6, $a1, 0x3
    ctx->r14 = ctx->r5 & 0X3;
    // 0x8007DD4C: sll         $a1, $t6, 8
    ctx->r5 = S32(ctx->r14 << 8);
    // 0x8007DD50: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007DD54: andi        $t9, $a2, 0xF
    ctx->r25 = ctx->r6 & 0XF;
    // 0x8007DD58: sll         $t7, $t9, 4
    ctx->r15 = S32(ctx->r25 << 4);
    // 0x8007DD5C: or          $t6, $v0, $at
    ctx->r14 = ctx->r2 | ctx->r1;
    // 0x8007DD60: or          $t8, $t6, $v1
    ctx->r24 = ctx->r14 | ctx->r3;
    // 0x8007DD64: or          $t9, $t8, $a1
    ctx->r25 = ctx->r24 | ctx->r5;
    // 0x8007DD68: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x8007DD6C: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007DD70: or          $t7, $t9, $t7
    ctx->r15 = ctx->r25 | ctx->r15;
    // 0x8007DD74: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DD78: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x8007DD7C: sw          $t7, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r15;
    // 0x8007DD80: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x8007DD84: sll         $t4, $t5, 1
    ctx->r12 = S32(ctx->r13 << 1);
    // 0x8007DD88: addiu       $t9, $t4, 0x7
    ctx->r25 = ADD32(ctx->r12, 0X7);
    // 0x8007DD8C: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x8007DD90: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DD94: or          $ra, $a3, $zero
    ctx->r31 = ctx->r7 | 0;
    // 0x8007DD98: sra         $t7, $t9, 3
    ctx->r15 = S32(SIGNED(ctx->r25) >> 3);
    // 0x8007DD9C: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x8007DDA0: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x8007DDA4: sw          $t8, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->r24;
    // 0x8007DDA8: andi        $t6, $t7, 0x1FF
    ctx->r14 = ctx->r15 & 0X1FF;
    // 0x8007DDAC: sll         $t8, $t6, 9
    ctx->r24 = S32(ctx->r14 << 9);
    // 0x8007DDB0: or          $t9, $v0, $v1
    ctx->r25 = ctx->r2 | ctx->r3;
    // 0x8007DDB4: or          $t7, $t9, $a1
    ctx->r15 = ctx->r25 | ctx->r5;
    // 0x8007DDB8: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x8007DDBC: addiu       $t8, $t5, -0x1
    ctx->r24 = ADD32(ctx->r13, -0X1);
    // 0x8007DDC0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8007DDC4: or          $t6, $t7, $a2
    ctx->r14 = ctx->r15 | ctx->r6;
    // 0x8007DDC8: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x8007DDCC: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8007DDD0: addiu       $t8, $s0, -0x1
    ctx->r24 = ADD32(ctx->r16, -0X1);
    // 0x8007DDD4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8007DDD8: sll         $t6, $t7, 12
    ctx->r14 = S32(ctx->r15 << 12);
    // 0x8007DDDC: mflo        $t0
    ctx->r8 = lo;
    // 0x8007DDE0: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8007DDE4: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x8007DDE8: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x8007DDEC: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x8007DDF0: sw          $ra, 0x1CC($sp)
    MEM_W(0X1CC, ctx->r29) = ctx->r31;
    // 0x8007DDF4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DDF8: bgez        $t4, L_8007DE08
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8007DDFC: sra         $t3, $t4, 3
        ctx->r11 = S32(SIGNED(ctx->r12) >> 3);
            goto L_8007DE08;
    }
    // 0x8007DDFC: sra         $t3, $t4, 3
    ctx->r11 = S32(SIGNED(ctx->r12) >> 3);
    // 0x8007DE00: addiu       $at, $t4, 0x7
    ctx->r1 = ADD32(ctx->r12, 0X7);
    // 0x8007DE04: sra         $t3, $at, 3
    ctx->r11 = S32(SIGNED(ctx->r1) >> 3);
L_8007DE08:
    // 0x8007DE08: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8007DE0C: beq         $at, $zero, L_8007DE1C
    if (ctx->r1 == 0) {
        // 0x8007DE10: or          $t2, $t3, $zero
        ctx->r10 = ctx->r11 | 0;
            goto L_8007DE1C;
    }
    // 0x8007DE10: or          $t2, $t3, $zero
    ctx->r10 = ctx->r11 | 0;
    // 0x8007DE14: b           L_8007DE20
    // 0x8007DE18: or          $ra, $t0, $zero
    ctx->r31 = ctx->r8 | 0;
        goto L_8007DE20;
    // 0x8007DE18: or          $ra, $t0, $zero
    ctx->r31 = ctx->r8 | 0;
L_8007DE1C:
    // 0x8007DE1C: addiu       $ra, $zero, 0x7FF
    ctx->r31 = ADD32(0, 0X7FF);
L_8007DE20:
    // 0x8007DE20: bgtz        $t3, L_8007DE30
    if (SIGNED(ctx->r11) > 0) {
        // 0x8007DE24: or          $a0, $t3, $zero
        ctx->r4 = ctx->r11 | 0;
            goto L_8007DE30;
    }
    // 0x8007DE24: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x8007DE28: b           L_8007DE30
    // 0x8007DE2C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_8007DE30;
    // 0x8007DE2C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8007DE30:
    // 0x8007DE30: bgtz        $t3, L_8007DE40
    if (SIGNED(ctx->r11) > 0) {
        // 0x8007DE34: addiu       $t9, $t2, 0x7FF
        ctx->r25 = ADD32(ctx->r10, 0X7FF);
            goto L_8007DE40;
    }
    // 0x8007DE34: addiu       $t9, $t2, 0x7FF
    ctx->r25 = ADD32(ctx->r10, 0X7FF);
    // 0x8007DE38: b           L_8007DE40
    // 0x8007DE3C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_8007DE40;
    // 0x8007DE3C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8007DE40:
    // 0x8007DE40: div         $zero, $t9, $a0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r4)));
    // 0x8007DE44: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8007DE48: bne         $a0, $zero, L_8007DE54
    if (ctx->r4 != 0) {
        // 0x8007DE4C: nop
    
            goto L_8007DE54;
    }
    // 0x8007DE4C: nop

    // 0x8007DE50: break       7
    do_break(2147999312);
L_8007DE54:
    // 0x8007DE54: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007DE58: bne         $a0, $at, L_8007DE6C
    if (ctx->r4 != ctx->r1) {
        // 0x8007DE5C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007DE6C;
    }
    // 0x8007DE5C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007DE60: bne         $t9, $at, L_8007DE6C
    if (ctx->r25 != ctx->r1) {
        // 0x8007DE64: nop
    
            goto L_8007DE6C;
    }
    // 0x8007DE64: nop

    // 0x8007DE68: break       6
    do_break(2147999336);
L_8007DE6C:
    // 0x8007DE6C: andi        $t9, $ra, 0xFFF
    ctx->r25 = ctx->r31 & 0XFFF;
    // 0x8007DE70: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007DE74: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DE78: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007DE7C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DE80: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007DE84: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DE88: mflo        $t6
    ctx->r14 = lo;
    // 0x8007DE8C: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8007DE90: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x8007DE94: lw          $t9, 0x1CC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1CC);
    // 0x8007DE98: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8007DE9C: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8007DEA0: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x8007DEA4: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8007DEA8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007DEAC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007DEB0: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8007DEB4: lui         $at, 0xF570
    ctx->r1 = S32(0XF570 << 16);
    // 0x8007DEB8: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8007DEBC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8007DEC0: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8007DEC4: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x8007DEC8: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8007DECC: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8007DED0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8007DED4: nop

    // 0x8007DED8: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x8007DEDC: lh          $t7, 0x6($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X6);
    // 0x8007DEE0: nop

    // 0x8007DEE4: ori         $t9, $t7, 0x4
    ctx->r25 = ctx->r15 | 0X4;
    // 0x8007DEE8: sh          $t9, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r25;
L_8007DEEC:
    // 0x8007DEEC: lw          $t8, 0x27C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X27C);
    // 0x8007DEF0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8007DEF4: bne         $t8, $at, L_8007E0E8
    if (ctx->r24 != ctx->r1) {
        // 0x8007DEF8: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8007E0E8;
    }
    // 0x8007DEF8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8007DEFC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007DF00: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x8007DF04: addu        $t7, $s1, $at
    ctx->r15 = ADD32(ctx->r17, ctx->r1);
    // 0x8007DF08: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8007DF0C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DF10: lui         $t6, 0xFD70
    ctx->r14 = S32(0XFD70 << 16);
    // 0x8007DF14: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007DF18: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x8007DF1C: lui         $t9, 0xF570
    ctx->r25 = S32(0XF570 << 16);
    // 0x8007DF20: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8007DF24: lw          $v0, 0x268($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X268);
    // 0x8007DF28: lw          $v1, 0x260($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X260);
    // 0x8007DF2C: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
    // 0x8007DF30: andi        $t8, $v0, 0x3
    ctx->r24 = ctx->r2 & 0X3;
    // 0x8007DF34: lw          $a2, 0x264($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X264);
    // 0x8007DF38: sll         $v0, $t8, 18
    ctx->r2 = S32(ctx->r24 << 18);
    // 0x8007DF3C: andi        $t7, $v1, 0xF
    ctx->r15 = ctx->r3 & 0XF;
    // 0x8007DF40: sll         $v1, $t7, 14
    ctx->r3 = S32(ctx->r15 << 14);
    // 0x8007DF44: andi        $t8, $a1, 0x3
    ctx->r24 = ctx->r5 & 0X3;
    // 0x8007DF48: sll         $a1, $t8, 8
    ctx->r5 = S32(ctx->r24 << 8);
    // 0x8007DF4C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007DF50: andi        $t7, $a2, 0xF
    ctx->r15 = ctx->r6 & 0XF;
    // 0x8007DF54: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x8007DF58: or          $t8, $v0, $at
    ctx->r24 = ctx->r2 | ctx->r1;
    // 0x8007DF5C: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007DF60: or          $t6, $t8, $v1
    ctx->r14 = ctx->r24 | ctx->r3;
    // 0x8007DF64: or          $t7, $t6, $a1
    ctx->r15 = ctx->r14 | ctx->r5;
    // 0x8007DF68: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x8007DF6C: or          $t9, $t7, $t9
    ctx->r25 = ctx->r15 | ctx->r25;
    // 0x8007DF70: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DF74: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x8007DF78: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x8007DF7C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DF80: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x8007DF84: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8007DF88: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x8007DF8C: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x8007DF90: or          $t7, $v0, $v1
    ctx->r15 = ctx->r2 | ctx->r3;
    // 0x8007DF94: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x8007DF98: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x8007DF9C: or          $t9, $t7, $a1
    ctx->r25 = ctx->r15 | ctx->r5;
    // 0x8007DFA0: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8007DFA4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8007DFA8: or          $t8, $t9, $a2
    ctx->r24 = ctx->r25 | ctx->r6;
    // 0x8007DFAC: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x8007DFB0: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x8007DFB4: addiu       $t6, $s0, -0x1
    ctx->r14 = ADD32(ctx->r16, -0X1);
    // 0x8007DFB8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8007DFBC: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x8007DFC0: mflo        $t2
    ctx->r10 = lo;
    // 0x8007DFC4: addiu       $t0, $t2, 0x1
    ctx->r8 = ADD32(ctx->r10, 0X1);
    // 0x8007DFC8: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x8007DFCC: sra         $t7, $t0, 1
    ctx->r15 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8007DFD0: addiu       $t0, $t7, -0x1
    ctx->r8 = ADD32(ctx->r15, -0X1);
    // 0x8007DFD4: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8007DFD8: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x8007DFDC: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x8007DFE0: sw          $t3, 0x1B0($sp)
    MEM_W(0X1B0, ctx->r29) = ctx->r11;
    // 0x8007DFE4: beq         $at, $zero, L_8007DFF4
    if (ctx->r1 == 0) {
        // 0x8007DFE8: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_8007DFF4;
    }
    // 0x8007DFE8: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DFEC: b           L_8007DFF8
    // 0x8007DFF0: or          $ra, $t0, $zero
    ctx->r31 = ctx->r8 | 0;
        goto L_8007DFF8;
    // 0x8007DFF0: or          $ra, $t0, $zero
    ctx->r31 = ctx->r8 | 0;
L_8007DFF4:
    // 0x8007DFF4: addiu       $ra, $zero, 0x7FF
    ctx->r31 = ADD32(0, 0X7FF);
L_8007DFF8:
    // 0x8007DFF8: or          $t4, $t5, $zero
    ctx->r12 = ctx->r13 | 0;
    // 0x8007DFFC: bgez        $t4, L_8007E00C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8007E000: sra         $t3, $t4, 3
        ctx->r11 = S32(SIGNED(ctx->r12) >> 3);
            goto L_8007E00C;
    }
    // 0x8007E000: sra         $t3, $t4, 3
    ctx->r11 = S32(SIGNED(ctx->r12) >> 3);
    // 0x8007E004: addiu       $at, $t4, 0x7
    ctx->r1 = ADD32(ctx->r12, 0X7);
    // 0x8007E008: sra         $t3, $at, 3
    ctx->r11 = S32(SIGNED(ctx->r1) >> 3);
L_8007E00C:
    // 0x8007E00C: bgtz        $t3, L_8007E01C
    if (SIGNED(ctx->r11) > 0) {
        // 0x8007E010: or          $t2, $t3, $zero
        ctx->r10 = ctx->r11 | 0;
            goto L_8007E01C;
    }
    // 0x8007E010: or          $t2, $t3, $zero
    ctx->r10 = ctx->r11 | 0;
    // 0x8007E014: b           L_8007E01C
    // 0x8007E018: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_8007E01C;
    // 0x8007E018: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8007E01C:
    // 0x8007E01C: bgtz        $t3, L_8007E02C
    if (SIGNED(ctx->r11) > 0) {
        // 0x8007E020: addiu       $t8, $t2, 0x7FF
        ctx->r24 = ADD32(ctx->r10, 0X7FF);
            goto L_8007E02C;
    }
    // 0x8007E020: addiu       $t8, $t2, 0x7FF
    ctx->r24 = ADD32(ctx->r10, 0X7FF);
    // 0x8007E024: b           L_8007E030
    // 0x8007E028: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_8007E030;
    // 0x8007E028: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8007E02C:
    // 0x8007E02C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
L_8007E030:
    // 0x8007E030: div         $zero, $t8, $a0
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r4)));
    // 0x8007E034: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8007E038: bne         $a0, $zero, L_8007E044
    if (ctx->r4 != 0) {
        // 0x8007E03C: nop
    
            goto L_8007E044;
    }
    // 0x8007E03C: nop

    // 0x8007E040: break       7
    do_break(2147999808);
L_8007E044:
    // 0x8007E044: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007E048: bne         $a0, $at, L_8007E05C
    if (ctx->r4 != ctx->r1) {
        // 0x8007E04C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007E05C;
    }
    // 0x8007E04C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007E050: bne         $t8, $at, L_8007E05C
    if (ctx->r24 != ctx->r1) {
        // 0x8007E054: nop
    
            goto L_8007E05C;
    }
    // 0x8007E054: nop

    // 0x8007E058: break       6
    do_break(2147999832);
L_8007E05C:
    // 0x8007E05C: andi        $t8, $ra, 0xFFF
    ctx->r24 = ctx->r31 & 0XFFF;
    // 0x8007E060: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007E064: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E068: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007E06C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E070: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007E074: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E078: mflo        $t9
    ctx->r25 = lo;
    // 0x8007E07C: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8007E080: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x8007E084: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8007E088: lw          $t8, 0x1B0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1B0);
    // 0x8007E08C: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x8007E090: sw          $t6, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r14;
    // 0x8007E094: addiu       $t9, $t4, 0x7
    ctx->r25 = ADD32(ctx->r12, 0X7);
    // 0x8007E098: sra         $t6, $t9, 3
    ctx->r14 = S32(SIGNED(ctx->r25) >> 3);
    // 0x8007E09C: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8007E0A0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007E0A4: andi        $t8, $t6, 0x1FF
    ctx->r24 = ctx->r14 & 0X1FF;
    // 0x8007E0A8: sll         $t7, $t8, 9
    ctx->r15 = S32(ctx->r24 << 9);
    // 0x8007E0AC: lui         $at, 0xF568
    ctx->r1 = S32(0XF568 << 16);
    // 0x8007E0B0: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x8007E0B4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007E0B8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8007E0BC: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8007E0C0: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x8007E0C4: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8007E0C8: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8007E0CC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8007E0D0: nop

    // 0x8007E0D4: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x8007E0D8: lh          $t9, 0x6($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X6);
    // 0x8007E0DC: nop

    // 0x8007E0E0: ori         $t6, $t9, 0x4
    ctx->r14 = ctx->r25 | 0X4;
    // 0x8007E0E4: sh          $t6, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r14;
L_8007E0E8:
    // 0x8007E0E8: lw          $t8, 0x27C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X27C);
    // 0x8007E0EC: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8007E0F0: bne         $t8, $at, L_8007E2C4
    if (ctx->r24 != ctx->r1) {
        // 0x8007E0F4: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8007E2C4;
    }
    // 0x8007E0F4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8007E0F8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007E0FC: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x8007E100: addu        $t9, $s1, $at
    ctx->r25 = ADD32(ctx->r17, ctx->r1);
    // 0x8007E104: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8007E108: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E10C: lui         $t7, 0xFD70
    ctx->r15 = S32(0XFD70 << 16);
    // 0x8007E110: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007E114: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x8007E118: lui         $t6, 0xF570
    ctx->r14 = S32(0XF570 << 16);
    // 0x8007E11C: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x8007E120: lw          $v0, 0x268($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X268);
    // 0x8007E124: lw          $v1, 0x260($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X260);
    // 0x8007E128: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
    // 0x8007E12C: andi        $t8, $v0, 0x3
    ctx->r24 = ctx->r2 & 0X3;
    // 0x8007E130: lw          $a2, 0x264($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X264);
    // 0x8007E134: sll         $v0, $t8, 18
    ctx->r2 = S32(ctx->r24 << 18);
    // 0x8007E138: andi        $t9, $v1, 0xF
    ctx->r25 = ctx->r3 & 0XF;
    // 0x8007E13C: sll         $v1, $t9, 14
    ctx->r3 = S32(ctx->r25 << 14);
    // 0x8007E140: andi        $t8, $a1, 0x3
    ctx->r24 = ctx->r5 & 0X3;
    // 0x8007E144: sll         $a1, $t8, 8
    ctx->r5 = S32(ctx->r24 << 8);
    // 0x8007E148: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007E14C: andi        $t9, $a2, 0xF
    ctx->r25 = ctx->r6 & 0XF;
    // 0x8007E150: sll         $t6, $t9, 4
    ctx->r14 = S32(ctx->r25 << 4);
    // 0x8007E154: or          $t8, $v0, $at
    ctx->r24 = ctx->r2 | ctx->r1;
    // 0x8007E158: or          $t7, $t8, $v1
    ctx->r15 = ctx->r24 | ctx->r3;
    // 0x8007E15C: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007E160: or          $t9, $t7, $a1
    ctx->r25 = ctx->r15 | ctx->r5;
    // 0x8007E164: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x8007E168: or          $t6, $t9, $t6
    ctx->r14 = ctx->r25 | ctx->r14;
    // 0x8007E16C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E170: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x8007E174: sw          $t6, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r14;
    // 0x8007E178: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E17C: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x8007E180: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8007E184: or          $t4, $a3, $zero
    ctx->r12 = ctx->r7 | 0;
    // 0x8007E188: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x8007E18C: or          $t9, $v0, $v1
    ctx->r25 = ctx->r2 | ctx->r3;
    // 0x8007E190: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x8007E194: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x8007E198: or          $t6, $t9, $a1
    ctx->r14 = ctx->r25 | ctx->r5;
    // 0x8007E19C: addiu       $t7, $t5, -0x1
    ctx->r15 = ADD32(ctx->r13, -0X1);
    // 0x8007E1A0: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8007E1A4: or          $t8, $t6, $a2
    ctx->r24 = ctx->r14 | ctx->r6;
    // 0x8007E1A8: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8007E1AC: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x8007E1B0: addiu       $t7, $s0, -0x1
    ctx->r15 = ADD32(ctx->r16, -0X1);
    // 0x8007E1B4: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8007E1B8: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x8007E1BC: mflo        $t0
    ctx->r8 = lo;
    // 0x8007E1C0: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8007E1C4: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8007E1C8: addiu       $t0, $t0, 0x3
    ctx->r8 = ADD32(ctx->r8, 0X3);
    // 0x8007E1CC: sra         $t9, $t0, 2
    ctx->r25 = S32(SIGNED(ctx->r8) >> 2);
    // 0x8007E1D0: sra         $ra, $t5, 1
    ctx->r31 = S32(SIGNED(ctx->r13) >> 1);
    // 0x8007E1D4: addiu       $ra, $ra, 0x7
    ctx->r31 = ADD32(ctx->r31, 0X7);
    // 0x8007E1D8: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x8007E1DC: sra         $t9, $ra, 3
    ctx->r25 = S32(SIGNED(ctx->r31) >> 3);
    // 0x8007E1E0: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8007E1E4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E1E8: bgez        $t5, L_8007E1F8
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8007E1EC: sra         $t1, $t5, 4
        ctx->r9 = S32(SIGNED(ctx->r13) >> 4);
            goto L_8007E1F8;
    }
    // 0x8007E1EC: sra         $t1, $t5, 4
    ctx->r9 = S32(SIGNED(ctx->r13) >> 4);
    // 0x8007E1F0: addiu       $at, $t5, 0xF
    ctx->r1 = ADD32(ctx->r13, 0XF);
    // 0x8007E1F4: sra         $t1, $at, 4
    ctx->r9 = S32(SIGNED(ctx->r1) >> 4);
L_8007E1F8:
    // 0x8007E1F8: addiu       $t8, $t1, 0x7FF
    ctx->r24 = ADD32(ctx->r9, 0X7FF);
    // 0x8007E1FC: div         $zero, $t8, $t1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r9)));
    // 0x8007E200: bne         $t1, $zero, L_8007E20C
    if (ctx->r9 != 0) {
        // 0x8007E204: nop
    
            goto L_8007E20C;
    }
    // 0x8007E204: nop

    // 0x8007E208: break       7
    do_break(2148000264);
L_8007E20C:
    // 0x8007E20C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007E210: bne         $t1, $at, L_8007E224
    if (ctx->r9 != ctx->r1) {
        // 0x8007E214: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007E224;
    }
    // 0x8007E214: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007E218: bne         $t8, $at, L_8007E224
    if (ctx->r24 != ctx->r1) {
        // 0x8007E21C: nop
    
            goto L_8007E224;
    }
    // 0x8007E21C: nop

    // 0x8007E220: break       6
    do_break(2148000288);
L_8007E224:
    // 0x8007E224: andi        $t8, $t9, 0x1FF
    ctx->r24 = ctx->r25 & 0X1FF;
    // 0x8007E228: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8007E22C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E230: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8007E234: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007E238: addiu       $a0, $zero, 0x7FF
    ctx->r4 = ADD32(0, 0X7FF);
    // 0x8007E23C: mflo        $t6
    ctx->r14 = lo;
    // 0x8007E240: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8007E244: sll         $t6, $t8, 9
    ctx->r14 = S32(ctx->r24 << 9);
    // 0x8007E248: or          $ra, $t6, $zero
    ctx->r31 = ctx->r14 | 0;
    // 0x8007E24C: beq         $at, $zero, L_8007E25C
    if (ctx->r1 == 0) {
        // 0x8007E250: sw          $t7, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r15;
            goto L_8007E25C;
    }
    // 0x8007E250: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x8007E254: b           L_8007E25C
    // 0x8007E258: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
        goto L_8007E25C;
    // 0x8007E258: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_8007E25C:
    // 0x8007E25C: andi        $t7, $a0, 0xFFF
    ctx->r15 = ctx->r4 & 0XFFF;
    // 0x8007E260: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8007E264: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x8007E268: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007E26C: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x8007E270: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8007E274: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x8007E278: lui         $at, 0xF560
    ctx->r1 = S32(0XF560 << 16);
    // 0x8007E27C: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8007E280: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8007E284: or          $t8, $ra, $at
    ctx->r24 = ctx->r31 | ctx->r1;
    // 0x8007E288: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007E28C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8007E290: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8007E294: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E298: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007E29C: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x8007E2A0: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8007E2A4: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8007E2A8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8007E2AC: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E2B0: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x8007E2B4: lh          $t8, 0x6($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X6);
    // 0x8007E2B8: nop

    // 0x8007E2BC: ori         $t6, $t8, 0x4
    ctx->r14 = ctx->r24 | 0X4;
    // 0x8007E2C0: sh          $t6, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r14;
L_8007E2C4:
    // 0x8007E2C4: lw          $t7, 0x27C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X27C);
    // 0x8007E2C8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007E2CC: bne         $t7, $at, L_8007E4B8
    if (ctx->r15 != ctx->r1) {
        // 0x8007E2D0: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8007E4B8;
    }
    // 0x8007E2D0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8007E2D4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007E2D8: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x8007E2DC: addu        $t8, $s1, $at
    ctx->r24 = ADD32(ctx->r17, ctx->r1);
    // 0x8007E2E0: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8007E2E4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E2E8: lui         $t9, 0xFD90
    ctx->r25 = S32(0XFD90 << 16);
    // 0x8007E2EC: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007E2F0: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x8007E2F4: lui         $t6, 0xF590
    ctx->r14 = S32(0XF590 << 16);
    // 0x8007E2F8: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8007E2FC: lw          $v0, 0x268($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X268);
    // 0x8007E300: lw          $v1, 0x260($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X260);
    // 0x8007E304: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
    // 0x8007E308: andi        $t7, $v0, 0x3
    ctx->r15 = ctx->r2 & 0X3;
    // 0x8007E30C: lw          $a2, 0x264($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X264);
    // 0x8007E310: sll         $v0, $t7, 18
    ctx->r2 = S32(ctx->r15 << 18);
    // 0x8007E314: andi        $t8, $v1, 0xF
    ctx->r24 = ctx->r3 & 0XF;
    // 0x8007E318: sll         $v1, $t8, 14
    ctx->r3 = S32(ctx->r24 << 14);
    // 0x8007E31C: andi        $t7, $a1, 0x3
    ctx->r15 = ctx->r5 & 0X3;
    // 0x8007E320: sll         $a1, $t7, 8
    ctx->r5 = S32(ctx->r15 << 8);
    // 0x8007E324: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007E328: andi        $t8, $a2, 0xF
    ctx->r24 = ctx->r6 & 0XF;
    // 0x8007E32C: sll         $t6, $t8, 4
    ctx->r14 = S32(ctx->r24 << 4);
    // 0x8007E330: or          $t7, $v0, $at
    ctx->r15 = ctx->r2 | ctx->r1;
    // 0x8007E334: or          $t9, $t7, $v1
    ctx->r25 = ctx->r15 | ctx->r3;
    // 0x8007E338: or          $t8, $t9, $a1
    ctx->r24 = ctx->r25 | ctx->r5;
    // 0x8007E33C: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x8007E340: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007E344: or          $t6, $t8, $t6
    ctx->r14 = ctx->r24 | ctx->r14;
    // 0x8007E348: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E34C: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x8007E350: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x8007E354: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E358: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x8007E35C: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x8007E360: or          $ra, $a3, $zero
    ctx->r31 = ctx->r7 | 0;
    // 0x8007E364: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x8007E368: or          $t8, $v0, $v1
    ctx->r24 = ctx->r2 | ctx->r3;
    // 0x8007E36C: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x8007E370: sw          $t9, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->r25;
    // 0x8007E374: or          $t6, $t8, $a1
    ctx->r14 = ctx->r24 | ctx->r5;
    // 0x8007E378: addiu       $t9, $t5, -0x1
    ctx->r25 = ADD32(ctx->r13, -0X1);
    // 0x8007E37C: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x8007E380: or          $t7, $t6, $a2
    ctx->r15 = ctx->r14 | ctx->r6;
    // 0x8007E384: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x8007E388: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8007E38C: addiu       $t9, $s0, -0x1
    ctx->r25 = ADD32(ctx->r16, -0X1);
    // 0x8007E390: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x8007E394: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x8007E398: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x8007E39C: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x8007E3A0: mflo        $t0
    ctx->r8 = lo;
    // 0x8007E3A4: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8007E3A8: or          $t4, $t5, $zero
    ctx->r12 = ctx->r13 | 0;
    // 0x8007E3AC: addiu       $t7, $t4, 0x7
    ctx->r15 = ADD32(ctx->r12, 0X7);
    // 0x8007E3B0: sra         $t8, $t0, 1
    ctx->r24 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8007E3B4: addiu       $t0, $t8, -0x1
    ctx->r8 = ADD32(ctx->r24, -0X1);
    // 0x8007E3B8: sra         $t6, $t7, 3
    ctx->r14 = S32(SIGNED(ctx->r15) >> 3);
    // 0x8007E3BC: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x8007E3C0: andi        $t9, $t6, 0x1FF
    ctx->r25 = ctx->r14 & 0X1FF;
    // 0x8007E3C4: sll         $t8, $t9, 9
    ctx->r24 = S32(ctx->r25 << 9);
    // 0x8007E3C8: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x8007E3CC: sw          $ra, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->r31;
    // 0x8007E3D0: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E3D4: bgez        $t4, L_8007E3E4
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8007E3D8: sra         $t3, $t4, 3
        ctx->r11 = S32(SIGNED(ctx->r12) >> 3);
            goto L_8007E3E4;
    }
    // 0x8007E3D8: sra         $t3, $t4, 3
    ctx->r11 = S32(SIGNED(ctx->r12) >> 3);
    // 0x8007E3DC: addiu       $at, $t4, 0x7
    ctx->r1 = ADD32(ctx->r12, 0X7);
    // 0x8007E3E0: sra         $t3, $at, 3
    ctx->r11 = S32(SIGNED(ctx->r1) >> 3);
L_8007E3E4:
    // 0x8007E3E4: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8007E3E8: beq         $at, $zero, L_8007E3F8
    if (ctx->r1 == 0) {
        // 0x8007E3EC: or          $t4, $t8, $zero
        ctx->r12 = ctx->r24 | 0;
            goto L_8007E3F8;
    }
    // 0x8007E3EC: or          $t4, $t8, $zero
    ctx->r12 = ctx->r24 | 0;
    // 0x8007E3F0: b           L_8007E3FC
    // 0x8007E3F4: or          $ra, $t0, $zero
    ctx->r31 = ctx->r8 | 0;
        goto L_8007E3FC;
    // 0x8007E3F4: or          $ra, $t0, $zero
    ctx->r31 = ctx->r8 | 0;
L_8007E3F8:
    // 0x8007E3F8: addiu       $ra, $zero, 0x7FF
    ctx->r31 = ADD32(0, 0X7FF);
L_8007E3FC:
    // 0x8007E3FC: bgtz        $t3, L_8007E40C
    if (SIGNED(ctx->r11) > 0) {
        // 0x8007E400: or          $t2, $t3, $zero
        ctx->r10 = ctx->r11 | 0;
            goto L_8007E40C;
    }
    // 0x8007E400: or          $t2, $t3, $zero
    ctx->r10 = ctx->r11 | 0;
    // 0x8007E404: b           L_8007E40C
    // 0x8007E408: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_8007E40C;
    // 0x8007E408: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8007E40C:
    // 0x8007E40C: bgtz        $t3, L_8007E41C
    if (SIGNED(ctx->r11) > 0) {
        // 0x8007E410: addiu       $t7, $t2, 0x7FF
        ctx->r15 = ADD32(ctx->r10, 0X7FF);
            goto L_8007E41C;
    }
    // 0x8007E410: addiu       $t7, $t2, 0x7FF
    ctx->r15 = ADD32(ctx->r10, 0X7FF);
    // 0x8007E414: b           L_8007E420
    // 0x8007E418: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_8007E420;
    // 0x8007E418: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8007E41C:
    // 0x8007E41C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
L_8007E420:
    // 0x8007E420: div         $zero, $t7, $a0
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r4)));
    // 0x8007E424: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8007E428: bne         $a0, $zero, L_8007E434
    if (ctx->r4 != 0) {
        // 0x8007E42C: nop
    
            goto L_8007E434;
    }
    // 0x8007E42C: nop

    // 0x8007E430: break       7
    do_break(2148000816);
L_8007E434:
    // 0x8007E434: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007E438: bne         $a0, $at, L_8007E44C
    if (ctx->r4 != ctx->r1) {
        // 0x8007E43C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007E44C;
    }
    // 0x8007E43C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007E440: bne         $t7, $at, L_8007E44C
    if (ctx->r15 != ctx->r1) {
        // 0x8007E444: nop
    
            goto L_8007E44C;
    }
    // 0x8007E444: nop

    // 0x8007E448: break       6
    do_break(2148000840);
L_8007E44C:
    // 0x8007E44C: andi        $t7, $ra, 0xFFF
    ctx->r15 = ctx->r31 & 0XFFF;
    // 0x8007E450: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007E454: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E458: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007E45C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E460: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007E464: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E468: mflo        $t6
    ctx->r14 = lo;
    // 0x8007E46C: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x8007E470: sll         $t6, $t7, 12
    ctx->r14 = S32(ctx->r15 << 12);
    // 0x8007E474: lw          $t7, 0x178($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X178);
    // 0x8007E478: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x8007E47C: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x8007E480: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x8007E484: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8007E488: lui         $at, 0xF588
    ctx->r1 = S32(0XF588 << 16);
    // 0x8007E48C: or          $t6, $t4, $at
    ctx->r14 = ctx->r12 | ctx->r1;
    // 0x8007E490: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007E494: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007E498: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8007E49C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8007E4A0: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x8007E4A4: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8007E4A8: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8007E4AC: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8007E4B0: nop

    // 0x8007E4B4: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
L_8007E4B8:
    // 0x8007E4B8: lw          $t6, 0x27C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X27C);
    // 0x8007E4BC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8007E4C0: bne         $t6, $at, L_8007E684
    if (ctx->r14 != ctx->r1) {
        // 0x8007E4C4: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8007E684;
    }
    // 0x8007E4C4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8007E4C8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007E4CC: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x8007E4D0: addu        $t7, $s1, $at
    ctx->r15 = ADD32(ctx->r17, ctx->r1);
    // 0x8007E4D4: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8007E4D8: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E4DC: lui         $t9, 0xFD90
    ctx->r25 = S32(0XFD90 << 16);
    // 0x8007E4E0: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007E4E4: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x8007E4E8: lui         $t8, 0xF590
    ctx->r24 = S32(0XF590 << 16);
    // 0x8007E4EC: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x8007E4F0: lw          $v0, 0x268($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X268);
    // 0x8007E4F4: lw          $v1, 0x260($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X260);
    // 0x8007E4F8: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
    // 0x8007E4FC: andi        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 & 0X3;
    // 0x8007E500: lw          $a2, 0x264($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X264);
    // 0x8007E504: sll         $v0, $t6, 18
    ctx->r2 = S32(ctx->r14 << 18);
    // 0x8007E508: andi        $t7, $v1, 0xF
    ctx->r15 = ctx->r3 & 0XF;
    // 0x8007E50C: sll         $v1, $t7, 14
    ctx->r3 = S32(ctx->r15 << 14);
    // 0x8007E510: andi        $t6, $a1, 0x3
    ctx->r14 = ctx->r5 & 0X3;
    // 0x8007E514: sll         $a1, $t6, 8
    ctx->r5 = S32(ctx->r14 << 8);
    // 0x8007E518: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007E51C: andi        $t7, $a2, 0xF
    ctx->r15 = ctx->r6 & 0XF;
    // 0x8007E520: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x8007E524: or          $t6, $v0, $at
    ctx->r14 = ctx->r2 | ctx->r1;
    // 0x8007E528: or          $t9, $t6, $v1
    ctx->r25 = ctx->r14 | ctx->r3;
    // 0x8007E52C: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007E530: or          $t7, $t9, $a1
    ctx->r15 = ctx->r25 | ctx->r5;
    // 0x8007E534: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x8007E538: or          $t8, $t7, $t8
    ctx->r24 = ctx->r15 | ctx->r24;
    // 0x8007E53C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E540: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x8007E544: sw          $t8, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r24;
    // 0x8007E548: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E54C: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x8007E550: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x8007E554: or          $t4, $a3, $zero
    ctx->r12 = ctx->r7 | 0;
    // 0x8007E558: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x8007E55C: or          $t7, $v0, $v1
    ctx->r15 = ctx->r2 | ctx->r3;
    // 0x8007E560: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x8007E564: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x8007E568: or          $t8, $t7, $a1
    ctx->r24 = ctx->r15 | ctx->r5;
    // 0x8007E56C: addiu       $t9, $t5, -0x1
    ctx->r25 = ADD32(ctx->r13, -0X1);
    // 0x8007E570: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8007E574: or          $t6, $t8, $a2
    ctx->r14 = ctx->r24 | ctx->r6;
    // 0x8007E578: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8007E57C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8007E580: addiu       $t9, $s0, -0x1
    ctx->r25 = ADD32(ctx->r16, -0X1);
    // 0x8007E584: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8007E588: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x8007E58C: mflo        $t0
    ctx->r8 = lo;
    // 0x8007E590: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8007E594: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8007E598: addiu       $t0, $t0, 0x3
    ctx->r8 = ADD32(ctx->r8, 0X3);
    // 0x8007E59C: sra         $t7, $t0, 2
    ctx->r15 = S32(SIGNED(ctx->r8) >> 2);
    // 0x8007E5A0: sra         $ra, $t5, 1
    ctx->r31 = S32(SIGNED(ctx->r13) >> 1);
    // 0x8007E5A4: addiu       $ra, $ra, 0x7
    ctx->r31 = ADD32(ctx->r31, 0X7);
    // 0x8007E5A8: addiu       $t0, $t7, -0x1
    ctx->r8 = ADD32(ctx->r15, -0X1);
    // 0x8007E5AC: sra         $t7, $ra, 3
    ctx->r15 = S32(SIGNED(ctx->r31) >> 3);
    // 0x8007E5B0: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x8007E5B4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E5B8: bgez        $t5, L_8007E5C8
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8007E5BC: sra         $t1, $t5, 4
        ctx->r9 = S32(SIGNED(ctx->r13) >> 4);
            goto L_8007E5C8;
    }
    // 0x8007E5BC: sra         $t1, $t5, 4
    ctx->r9 = S32(SIGNED(ctx->r13) >> 4);
    // 0x8007E5C0: addiu       $at, $t5, 0xF
    ctx->r1 = ADD32(ctx->r13, 0XF);
    // 0x8007E5C4: sra         $t1, $at, 4
    ctx->r9 = S32(SIGNED(ctx->r1) >> 4);
L_8007E5C8:
    // 0x8007E5C8: addiu       $t6, $t1, 0x7FF
    ctx->r14 = ADD32(ctx->r9, 0X7FF);
    // 0x8007E5CC: div         $zero, $t6, $t1
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r9)));
    // 0x8007E5D0: bne         $t1, $zero, L_8007E5DC
    if (ctx->r9 != 0) {
        // 0x8007E5D4: nop
    
            goto L_8007E5DC;
    }
    // 0x8007E5D4: nop

    // 0x8007E5D8: break       7
    do_break(2148001240);
L_8007E5DC:
    // 0x8007E5DC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007E5E0: bne         $t1, $at, L_8007E5F4
    if (ctx->r9 != ctx->r1) {
        // 0x8007E5E4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007E5F4;
    }
    // 0x8007E5E4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007E5E8: bne         $t6, $at, L_8007E5F4
    if (ctx->r14 != ctx->r1) {
        // 0x8007E5EC: nop
    
            goto L_8007E5F4;
    }
    // 0x8007E5EC: nop

    // 0x8007E5F0: break       6
    do_break(2148001264);
L_8007E5F4:
    // 0x8007E5F4: andi        $t6, $t7, 0x1FF
    ctx->r14 = ctx->r15 & 0X1FF;
    // 0x8007E5F8: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8007E5FC: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E600: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8007E604: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007E608: addiu       $a0, $zero, 0x7FF
    ctx->r4 = ADD32(0, 0X7FF);
    // 0x8007E60C: mflo        $t8
    ctx->r24 = lo;
    // 0x8007E610: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x8007E614: sll         $t8, $t6, 9
    ctx->r24 = S32(ctx->r14 << 9);
    // 0x8007E618: or          $ra, $t8, $zero
    ctx->r31 = ctx->r24 | 0;
    // 0x8007E61C: beq         $at, $zero, L_8007E62C
    if (ctx->r1 == 0) {
        // 0x8007E620: sw          $t9, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r25;
            goto L_8007E62C;
    }
    // 0x8007E620: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x8007E624: b           L_8007E62C
    // 0x8007E628: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
        goto L_8007E62C;
    // 0x8007E628: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_8007E62C:
    // 0x8007E62C: andi        $t9, $a0, 0xFFF
    ctx->r25 = ctx->r4 & 0XFFF;
    // 0x8007E630: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8007E634: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x8007E638: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007E63C: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x8007E640: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8007E644: sw          $t9, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r25;
    // 0x8007E648: lui         $at, 0xF580
    ctx->r1 = S32(0XF580 << 16);
    // 0x8007E64C: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8007E650: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007E654: or          $t6, $ra, $at
    ctx->r14 = ctx->r31 | ctx->r1;
    // 0x8007E658: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007E65C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8007E660: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8007E664: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E668: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007E66C: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x8007E670: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8007E674: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8007E678: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8007E67C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E680: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
L_8007E684:
    // 0x8007E684: lw          $t6, 0xC($s1)
    ctx->r14 = MEM_W(ctx->r17, 0XC);
    // 0x8007E688: nop

    // 0x8007E68C: subu        $t8, $a3, $t6
    ctx->r24 = SUB32(ctx->r7, ctx->r14);
    // 0x8007E690: sra         $t9, $t8, 3
    ctx->r25 = S32(SIGNED(ctx->r24) >> 3);
    // 0x8007E694: b           L_8007F3A0
    // 0x8007E698: sh          $t9, 0xA($s1)
    MEM_H(0XA, ctx->r17) = ctx->r25;
        goto L_8007F3A0;
    // 0x8007E698: sh          $t9, 0xA($s1)
    MEM_H(0XA, ctx->r17) = ctx->r25;
L_8007E69C:
    // 0x8007E69C: sw          $t2, 0x264($sp)
    MEM_W(0X264, ctx->r29) = ctx->r10;
    // 0x8007E6A0: sw          $t3, 0x260($sp)
    MEM_W(0X260, ctx->r29) = ctx->r11;
    // 0x8007E6A4: bne         $t4, $zero, L_8007E820
    if (ctx->r12 != 0) {
        // 0x8007E6A8: sw          $t4, 0x27C($sp)
        MEM_W(0X27C, ctx->r29) = ctx->r12;
            goto L_8007E820;
    }
    // 0x8007E6A8: sw          $t4, 0x27C($sp)
    MEM_W(0X27C, ctx->r29) = ctx->r12;
    // 0x8007E6AC: lw          $t2, 0x284($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X284);
    // 0x8007E6B0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007E6B4: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x8007E6B8: addu        $t6, $s1, $at
    ctx->r14 = ADD32(ctx->r17, ctx->r1);
    // 0x8007E6BC: lui         $t7, 0xFD18
    ctx->r15 = S32(0XFD18 << 16);
    // 0x8007E6C0: addiu       $a3, $t2, 0x8
    ctx->r7 = ADD32(ctx->r10, 0X8);
    // 0x8007E6C4: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x8007E6C8: lui         $t8, 0xF518
    ctx->r24 = S32(0XF518 << 16);
    // 0x8007E6CC: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x8007E6D0: sw          $t6, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r14;
    // 0x8007E6D4: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007E6D8: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x8007E6DC: lw          $v0, 0x268($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X268);
    // 0x8007E6E0: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
    // 0x8007E6E4: lw          $v1, 0x260($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X260);
    // 0x8007E6E8: andi        $t9, $v0, 0x3
    ctx->r25 = ctx->r2 & 0X3;
    // 0x8007E6EC: sll         $v0, $t9, 18
    ctx->r2 = S32(ctx->r25 << 18);
    // 0x8007E6F0: lw          $a2, 0x264($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X264);
    // 0x8007E6F4: andi        $t9, $a1, 0x3
    ctx->r25 = ctx->r5 & 0X3;
    // 0x8007E6F8: andi        $t6, $v1, 0xF
    ctx->r14 = ctx->r3 & 0XF;
    // 0x8007E6FC: sll         $v1, $t6, 14
    ctx->r3 = S32(ctx->r14 << 14);
    // 0x8007E700: sll         $a1, $t9, 8
    ctx->r5 = S32(ctx->r25 << 8);
    // 0x8007E704: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007E708: or          $t9, $v0, $at
    ctx->r25 = ctx->r2 | ctx->r1;
    // 0x8007E70C: andi        $t6, $a2, 0xF
    ctx->r14 = ctx->r6 & 0XF;
    // 0x8007E710: sll         $a2, $t6, 4
    ctx->r6 = S32(ctx->r14 << 4);
    // 0x8007E714: or          $t7, $t9, $v1
    ctx->r15 = ctx->r25 | ctx->r3;
    // 0x8007E718: or          $t6, $t7, $a1
    ctx->r14 = ctx->r15 | ctx->r5;
    // 0x8007E71C: or          $t8, $t6, $a2
    ctx->r24 = ctx->r14 | ctx->r6;
    // 0x8007E720: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E724: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x8007E728: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x8007E72C: mflo        $t0
    ctx->r8 = lo;
    // 0x8007E730: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8007E734: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E738: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8007E73C: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8007E740: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x8007E744: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8007E748: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x8007E74C: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x8007E750: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x8007E754: beq         $at, $zero, L_8007E764
    if (ctx->r1 == 0) {
        // 0x8007E758: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_8007E764;
    }
    // 0x8007E758: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E75C: b           L_8007E768
    // 0x8007E760: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
        goto L_8007E768;
    // 0x8007E760: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_8007E764:
    // 0x8007E764: addiu       $a0, $zero, 0x7FF
    ctx->r4 = ADD32(0, 0X7FF);
L_8007E768:
    // 0x8007E768: andi        $t6, $a0, 0xFFF
    ctx->r14 = ctx->r4 & 0XFFF;
    // 0x8007E76C: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x8007E770: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007E774: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8007E778: sw          $t9, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r25;
    // 0x8007E77C: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x8007E780: addiu       $t8, $t6, 0x7
    ctx->r24 = ADD32(ctx->r14, 0X7);
    // 0x8007E784: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x8007E788: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8007E78C: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x8007E790: sra         $t9, $t8, 3
    ctx->r25 = S32(SIGNED(ctx->r24) >> 3);
    // 0x8007E794: andi        $t7, $t9, 0x1FF
    ctx->r15 = ctx->r25 & 0X1FF;
    // 0x8007E798: sll         $t6, $t7, 9
    ctx->r14 = S32(ctx->r15 << 9);
    // 0x8007E79C: or          $t9, $v0, $v1
    ctx->r25 = ctx->r2 | ctx->r3;
    // 0x8007E7A0: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E7A4: lui         $at, 0xF518
    ctx->r1 = S32(0XF518 << 16);
    // 0x8007E7A8: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x8007E7AC: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x8007E7B0: or          $t7, $t9, $a1
    ctx->r15 = ctx->r25 | ctx->r5;
    // 0x8007E7B4: or          $t6, $t7, $a2
    ctx->r14 = ctx->r15 | ctx->r6;
    // 0x8007E7B8: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8007E7BC: addiu       $t9, $t5, -0x1
    ctx->r25 = ADD32(ctx->r13, -0X1);
    // 0x8007E7C0: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8007E7C4: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x8007E7C8: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8007E7CC: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E7D0: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x8007E7D4: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x8007E7D8: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x8007E7DC: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x8007E7E0: addiu       $t9, $s0, -0x1
    ctx->r25 = ADD32(ctx->r16, -0X1);
    // 0x8007E7E4: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8007E7E8: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x8007E7EC: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x8007E7F0: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x8007E7F4: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x8007E7F8: lw          $t7, 0x278($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X278);
    // 0x8007E7FC: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E800: beq         $t7, $zero, L_8007E810
    if (ctx->r15 == 0) {
        // 0x8007E804: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8007E810;
    }
    // 0x8007E804: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007E808: bne         $t7, $at, L_8007E824
    if (ctx->r15 != ctx->r1) {
        // 0x8007E80C: lw          $t9, 0x27C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X27C);
            goto L_8007E824;
    }
    // 0x8007E80C: lw          $t9, 0x27C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X27C);
L_8007E810:
    // 0x8007E810: lh          $t8, 0x6($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X6);
    // 0x8007E814: nop

    // 0x8007E818: ori         $t6, $t8, 0x4
    ctx->r14 = ctx->r24 | 0X4;
    // 0x8007E81C: sh          $t6, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r14;
L_8007E820:
    // 0x8007E820: lw          $t9, 0x27C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X27C);
L_8007E824:
    // 0x8007E824: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007E828: bne         $t9, $at, L_8007E9BC
    if (ctx->r25 != ctx->r1) {
        // 0x8007E82C: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8007E9BC;
    }
    // 0x8007E82C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8007E830: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007E834: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x8007E838: addu        $t8, $s1, $at
    ctx->r24 = ADD32(ctx->r17, ctx->r1);
    // 0x8007E83C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E840: lui         $t7, 0xFD10
    ctx->r15 = S32(0XFD10 << 16);
    // 0x8007E844: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007E848: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x8007E84C: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8007E850: lui         $t6, 0xF510
    ctx->r14 = S32(0XF510 << 16);
    // 0x8007E854: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8007E858: lw          $v0, 0x268($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X268);
    // 0x8007E85C: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
    // 0x8007E860: lw          $v1, 0x260($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X260);
    // 0x8007E864: andi        $t9, $v0, 0x3
    ctx->r25 = ctx->r2 & 0X3;
    // 0x8007E868: sll         $v0, $t9, 18
    ctx->r2 = S32(ctx->r25 << 18);
    // 0x8007E86C: lw          $a2, 0x264($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X264);
    // 0x8007E870: andi        $t9, $a1, 0x3
    ctx->r25 = ctx->r5 & 0X3;
    // 0x8007E874: andi        $t8, $v1, 0xF
    ctx->r24 = ctx->r3 & 0XF;
    // 0x8007E878: sll         $v1, $t8, 14
    ctx->r3 = S32(ctx->r24 << 14);
    // 0x8007E87C: sll         $a1, $t9, 8
    ctx->r5 = S32(ctx->r25 << 8);
    // 0x8007E880: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007E884: or          $t9, $v0, $at
    ctx->r25 = ctx->r2 | ctx->r1;
    // 0x8007E888: andi        $t8, $a2, 0xF
    ctx->r24 = ctx->r6 & 0XF;
    // 0x8007E88C: sll         $a2, $t8, 4
    ctx->r6 = S32(ctx->r24 << 4);
    // 0x8007E890: or          $t7, $t9, $v1
    ctx->r15 = ctx->r25 | ctx->r3;
    // 0x8007E894: or          $t8, $t7, $a1
    ctx->r24 = ctx->r15 | ctx->r5;
    // 0x8007E898: or          $t6, $t8, $a2
    ctx->r14 = ctx->r24 | ctx->r6;
    // 0x8007E89C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E8A0: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007E8A4: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x8007E8A8: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x8007E8AC: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8007E8B0: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8007E8B4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E8B8: sll         $t8, $t5, 1
    ctx->r24 = S32(ctx->r13 << 1);
    // 0x8007E8BC: addiu       $t6, $t8, 0x7
    ctx->r14 = ADD32(ctx->r24, 0X7);
    // 0x8007E8C0: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x8007E8C4: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x8007E8C8: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x8007E8CC: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x8007E8D0: sra         $t9, $t6, 3
    ctx->r25 = S32(SIGNED(ctx->r14) >> 3);
    // 0x8007E8D4: andi        $t7, $t9, 0x1FF
    ctx->r15 = ctx->r25 & 0X1FF;
    // 0x8007E8D8: sll         $t8, $t7, 9
    ctx->r24 = S32(ctx->r15 << 9);
    // 0x8007E8DC: or          $t6, $v0, $v1
    ctx->r14 = ctx->r2 | ctx->r3;
    // 0x8007E8E0: or          $t9, $t6, $a1
    ctx->r25 = ctx->r14 | ctx->r5;
    // 0x8007E8E4: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x8007E8E8: addiu       $t8, $t5, -0x1
    ctx->r24 = ADD32(ctx->r13, -0X1);
    // 0x8007E8EC: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x8007E8F0: or          $t7, $t9, $a2
    ctx->r15 = ctx->r25 | ctx->r6;
    // 0x8007E8F4: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x8007E8F8: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8007E8FC: addiu       $t8, $s0, -0x1
    ctx->r24 = ADD32(ctx->r16, -0X1);
    // 0x8007E900: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x8007E904: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x8007E908: mflo        $t0
    ctx->r8 = lo;
    // 0x8007E90C: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8007E910: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x8007E914: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x8007E918: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8007E91C: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x8007E920: beq         $at, $zero, L_8007E930
    if (ctx->r1 == 0) {
        // 0x8007E924: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_8007E930;
    }
    // 0x8007E924: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E928: b           L_8007E934
    // 0x8007E92C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
        goto L_8007E934;
    // 0x8007E92C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_8007E930:
    // 0x8007E930: addiu       $a0, $zero, 0x7FF
    ctx->r4 = ADD32(0, 0X7FF);
L_8007E934:
    // 0x8007E934: andi        $t6, $a0, 0xFFF
    ctx->r14 = ctx->r4 & 0XFFF;
    // 0x8007E938: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x8007E93C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007E940: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x8007E944: sw          $t9, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r25;
    // 0x8007E948: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8007E94C: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8007E950: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007E954: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007E958: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8007E95C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E960: lui         $at, 0xF510
    ctx->r1 = S32(0XF510 << 16);
    // 0x8007E964: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007E968: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8007E96C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8007E970: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8007E974: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E978: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007E97C: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x8007E980: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8007E984: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8007E988: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8007E98C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E990: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x8007E994: lw          $t7, 0x278($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X278);
    // 0x8007E998: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007E99C: beq         $t7, $zero, L_8007E9AC
    if (ctx->r15 == 0) {
        // 0x8007E9A0: nop
    
            goto L_8007E9AC;
    }
    // 0x8007E9A0: nop

    // 0x8007E9A4: bne         $t7, $at, L_8007E9C0
    if (ctx->r15 != ctx->r1) {
        // 0x8007E9A8: lw          $t6, 0x27C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X27C);
            goto L_8007E9C0;
    }
    // 0x8007E9A8: lw          $t6, 0x27C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X27C);
L_8007E9AC:
    // 0x8007E9AC: lh          $t9, 0x6($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X6);
    // 0x8007E9B0: nop

    // 0x8007E9B4: ori         $t8, $t9, 0x4
    ctx->r24 = ctx->r25 | 0X4;
    // 0x8007E9B8: sh          $t8, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r24;
L_8007E9BC:
    // 0x8007E9BC: lw          $t6, 0x27C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X27C);
L_8007E9C0:
    // 0x8007E9C0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8007E9C4: bne         $t6, $at, L_8007EC24
    if (ctx->r14 != ctx->r1) {
        // 0x8007E9C8: lw          $t6, 0x27C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X27C);
            goto L_8007EC24;
    }
    // 0x8007E9C8: lw          $t6, 0x27C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X27C);
    // 0x8007E9CC: lw          $v0, 0x268($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X268);
    // 0x8007E9D0: lw          $v1, 0x260($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X260);
    // 0x8007E9D4: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
    // 0x8007E9D8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007E9DC: andi        $t9, $v0, 0x3
    ctx->r25 = ctx->r2 & 0X3;
    // 0x8007E9E0: sll         $v0, $t9, 18
    ctx->r2 = S32(ctx->r25 << 18);
    // 0x8007E9E4: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x8007E9E8: lw          $a2, 0x264($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X264);
    // 0x8007E9EC: addu        $t7, $s1, $at
    ctx->r15 = ADD32(ctx->r17, ctx->r1);
    // 0x8007E9F0: andi        $t6, $v1, 0xF
    ctx->r14 = ctx->r3 & 0XF;
    // 0x8007E9F4: andi        $t9, $a1, 0x3
    ctx->r25 = ctx->r5 & 0X3;
    // 0x8007E9F8: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007E9FC: sll         $a1, $t9, 8
    ctx->r5 = S32(ctx->r25 << 8);
    // 0x8007EA00: sll         $v1, $t6, 14
    ctx->r3 = S32(ctx->r14 << 14);
    // 0x8007EA04: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007EA08: or          $t9, $v0, $at
    ctx->r25 = ctx->r2 | ctx->r1;
    // 0x8007EA0C: andi        $t6, $a2, 0xF
    ctx->r14 = ctx->r6 & 0XF;
    // 0x8007EA10: sll         $a2, $t6, 4
    ctx->r6 = S32(ctx->r14 << 4);
    // 0x8007EA14: or          $t8, $t9, $v1
    ctx->r24 = ctx->r25 | ctx->r3;
    // 0x8007EA18: lh          $a0, 0x8($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X8);
    // 0x8007EA1C: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x8007EA20: or          $t6, $t8, $a1
    ctx->r14 = ctx->r24 | ctx->r5;
    // 0x8007EA24: or          $t7, $t6, $a2
    ctx->r15 = ctx->r14 | ctx->r6;
    // 0x8007EA28: or          $t9, $v0, $v1
    ctx->r25 = ctx->r2 | ctx->r3;
    // 0x8007EA2C: or          $t8, $t9, $a1
    ctx->r24 = ctx->r25 | ctx->r5;
    // 0x8007EA30: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x8007EA34: addiu       $t7, $t5, -0x1
    ctx->r15 = ADD32(ctx->r13, -0X1);
    // 0x8007EA38: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8007EA3C: or          $t6, $t8, $a2
    ctx->r14 = ctx->r24 | ctx->r6;
    // 0x8007EA40: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x8007EA44: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8007EA48: addiu       $t7, $s0, -0x1
    ctx->r15 = ADD32(ctx->r16, -0X1);
    // 0x8007EA4C: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8007EA50: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x8007EA54: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x8007EA58: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x8007EA5C: mflo        $t2
    ctx->r10 = lo;
    // 0x8007EA60: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8007EA64: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8007EA68: sw          $t5, 0x274($sp)
    MEM_W(0X274, ctx->r29) = ctx->r13;
    // 0x8007EA6C: jal         0x8007F3B4
    // 0x8007EA70: sw          $a3, 0x248($sp)
    MEM_W(0X248, ctx->r29) = ctx->r7;
    tex_palette_id(rdram, ctx);
        goto after_1;
    // 0x8007EA70: sw          $a3, 0x248($sp)
    MEM_W(0X248, ctx->r29) = ctx->r7;
    after_1:
    // 0x8007EA74: lw          $a3, 0x248($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X248);
    // 0x8007EA78: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8007EA7C: lw          $t5, 0x274($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X274);
    // 0x8007EA80: lui         $t9, 0xFD50
    ctx->r25 = S32(0XFD50 << 16);
    // 0x8007EA84: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007EA88: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8007EA8C: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8007EA90: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EA94: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8007EA98: lui         $t8, 0xF550
    ctx->r24 = S32(0XF550 << 16);
    // 0x8007EA9C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8007EAA0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007EAA4: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8007EAA8: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EAAC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007EAB0: addiu       $t0, $t2, 0x3
    ctx->r8 = ADD32(ctx->r10, 0X3);
    // 0x8007EAB4: sra         $t8, $t0, 2
    ctx->r24 = S32(SIGNED(ctx->r8) >> 2);
    // 0x8007EAB8: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8007EABC: addiu       $t0, $t8, -0x1
    ctx->r8 = ADD32(ctx->r24, -0X1);
    // 0x8007EAC0: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EAC4: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8007EAC8: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8007EACC: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x8007EAD0: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8007EAD4: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x8007EAD8: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x8007EADC: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8007EAE0: beq         $at, $zero, L_8007EAF0
    if (ctx->r1 == 0) {
        // 0x8007EAE4: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_8007EAF0;
    }
    // 0x8007EAE4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EAE8: b           L_8007EAF4
    // 0x8007EAEC: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
        goto L_8007EAF4;
    // 0x8007EAEC: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_8007EAF0:
    // 0x8007EAF0: addiu       $a0, $zero, 0x7FF
    ctx->r4 = ADD32(0, 0X7FF);
L_8007EAF4:
    // 0x8007EAF4: andi        $t7, $a0, 0xFFF
    ctx->r15 = ctx->r4 & 0XFFF;
    // 0x8007EAF8: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x8007EAFC: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007EB00: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x8007EB04: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x8007EB08: sra         $t7, $t5, 1
    ctx->r15 = S32(SIGNED(ctx->r13) >> 1);
    // 0x8007EB0C: addiu       $t9, $t7, 0x7
    ctx->r25 = ADD32(ctx->r15, 0X7);
    // 0x8007EB10: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007EB14: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8007EB18: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8007EB1C: sra         $t6, $t9, 3
    ctx->r14 = S32(SIGNED(ctx->r25) >> 3);
    // 0x8007EB20: andi        $t8, $t6, 0x1FF
    ctx->r24 = ctx->r14 & 0X1FF;
    // 0x8007EB24: sll         $t7, $t8, 9
    ctx->r15 = S32(ctx->r24 << 9);
    // 0x8007EB28: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EB2C: lui         $at, 0xF540
    ctx->r1 = S32(0XF540 << 16);
    // 0x8007EB30: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x8007EB34: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007EB38: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8007EB3C: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8007EB40: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8007EB44: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EB48: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x8007EB4C: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x8007EB50: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x8007EB54: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8007EB58: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8007EB5C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EB60: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x8007EB64: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007EB68: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EB6C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8007EB70: lui         $t9, 0xFD10
    ctx->r25 = S32(0XFD10 << 16);
    // 0x8007EB74: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8007EB78: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EB7C: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8007EB80: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007EB84: lui         $t6, 0xE800
    ctx->r14 = S32(0XE800 << 16);
    // 0x8007EB88: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007EB8C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8007EB90: lui         $t8, 0xF500
    ctx->r24 = S32(0XF500 << 16);
    // 0x8007EB94: ori         $t8, $t8, 0x100
    ctx->r24 = ctx->r24 | 0X100;
    // 0x8007EB98: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EB9C: lui         $t7, 0x700
    ctx->r15 = S32(0X700 << 16);
    // 0x8007EBA0: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x8007EBA4: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x8007EBA8: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8007EBAC: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EBB0: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x8007EBB4: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8007EBB8: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x8007EBBC: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x8007EBC0: lui         $t8, 0x703
    ctx->r24 = S32(0X703 << 16);
    // 0x8007EBC4: ori         $t8, $t8, 0xC000
    ctx->r24 = ctx->r24 | 0XC000;
    // 0x8007EBC8: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EBCC: lui         $t6, 0xF000
    ctx->r14 = S32(0XF000 << 16);
    // 0x8007EBD0: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x8007EBD4: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8007EBD8: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x8007EBDC: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8007EBE0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007EBE4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007EBE8: lh          $t9, 0x6($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X6);
    // 0x8007EBEC: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EBF0: ori         $t6, $t9, 0x20
    ctx->r14 = ctx->r25 | 0X20;
    // 0x8007EBF4: sh          $t6, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r14;
    // 0x8007EBF8: lw          $t8, 0x278($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X278);
    // 0x8007EBFC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007EC00: beq         $t8, $zero, L_8007EC10
    if (ctx->r24 == 0) {
        // 0x8007EC04: nop
    
            goto L_8007EC10;
    }
    // 0x8007EC04: nop

    // 0x8007EC08: bne         $t8, $at, L_8007EC24
    if (ctx->r24 != ctx->r1) {
        // 0x8007EC0C: lw          $t6, 0x27C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X27C);
            goto L_8007EC24;
    }
    // 0x8007EC0C: lw          $t6, 0x27C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X27C);
L_8007EC10:
    // 0x8007EC10: lh          $t7, 0x6($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X6);
    // 0x8007EC14: nop

    // 0x8007EC18: ori         $t9, $t7, 0x4
    ctx->r25 = ctx->r15 | 0X4;
    // 0x8007EC1C: sh          $t9, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r25;
    // 0x8007EC20: lw          $t6, 0x27C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X27C);
L_8007EC24:
    // 0x8007EC24: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8007EC28: bne         $t6, $at, L_8007EDA4
    if (ctx->r14 != ctx->r1) {
        // 0x8007EC2C: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8007EDA4;
    }
    // 0x8007EC2C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8007EC30: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007EC34: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x8007EC38: addu        $t7, $s1, $at
    ctx->r15 = ADD32(ctx->r17, ctx->r1);
    // 0x8007EC3C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EC40: lui         $t8, 0xFD70
    ctx->r24 = S32(0XFD70 << 16);
    // 0x8007EC44: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007EC48: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x8007EC4C: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8007EC50: lui         $t9, 0xF570
    ctx->r25 = S32(0XF570 << 16);
    // 0x8007EC54: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8007EC58: lw          $v0, 0x268($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X268);
    // 0x8007EC5C: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
    // 0x8007EC60: lw          $v1, 0x260($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X260);
    // 0x8007EC64: andi        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 & 0X3;
    // 0x8007EC68: sll         $v0, $t6, 18
    ctx->r2 = S32(ctx->r14 << 18);
    // 0x8007EC6C: lw          $a2, 0x264($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X264);
    // 0x8007EC70: andi        $t6, $a1, 0x3
    ctx->r14 = ctx->r5 & 0X3;
    // 0x8007EC74: andi        $t7, $v1, 0xF
    ctx->r15 = ctx->r3 & 0XF;
    // 0x8007EC78: sll         $v1, $t7, 14
    ctx->r3 = S32(ctx->r15 << 14);
    // 0x8007EC7C: sll         $a1, $t6, 8
    ctx->r5 = S32(ctx->r14 << 8);
    // 0x8007EC80: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007EC84: or          $t6, $v0, $at
    ctx->r14 = ctx->r2 | ctx->r1;
    // 0x8007EC88: andi        $t7, $a2, 0xF
    ctx->r15 = ctx->r6 & 0XF;
    // 0x8007EC8C: sll         $a2, $t7, 4
    ctx->r6 = S32(ctx->r15 << 4);
    // 0x8007EC90: or          $t8, $t6, $v1
    ctx->r24 = ctx->r14 | ctx->r3;
    // 0x8007EC94: or          $t7, $t8, $a1
    ctx->r15 = ctx->r24 | ctx->r5;
    // 0x8007EC98: or          $t9, $t7, $a2
    ctx->r25 = ctx->r15 | ctx->r6;
    // 0x8007EC9C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007ECA0: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007ECA4: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x8007ECA8: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x8007ECAC: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x8007ECB0: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x8007ECB4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007ECB8: sll         $t7, $t5, 1
    ctx->r15 = S32(ctx->r13 << 1);
    // 0x8007ECBC: addiu       $t9, $t7, 0x7
    ctx->r25 = ADD32(ctx->r15, 0X7);
    // 0x8007ECC0: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x8007ECC4: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x8007ECC8: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x8007ECCC: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8007ECD0: sra         $t6, $t9, 3
    ctx->r14 = S32(SIGNED(ctx->r25) >> 3);
    // 0x8007ECD4: andi        $t8, $t6, 0x1FF
    ctx->r24 = ctx->r14 & 0X1FF;
    // 0x8007ECD8: sll         $t7, $t8, 9
    ctx->r15 = S32(ctx->r24 << 9);
    // 0x8007ECDC: or          $t9, $v0, $v1
    ctx->r25 = ctx->r2 | ctx->r3;
    // 0x8007ECE0: or          $t6, $t9, $a1
    ctx->r14 = ctx->r25 | ctx->r5;
    // 0x8007ECE4: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x8007ECE8: addiu       $t7, $t5, -0x1
    ctx->r15 = ADD32(ctx->r13, -0X1);
    // 0x8007ECEC: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8007ECF0: or          $t8, $t6, $a2
    ctx->r24 = ctx->r14 | ctx->r6;
    // 0x8007ECF4: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8007ECF8: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x8007ECFC: addiu       $t7, $s0, -0x1
    ctx->r15 = ADD32(ctx->r16, -0X1);
    // 0x8007ED00: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8007ED04: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x8007ED08: mflo        $t0
    ctx->r8 = lo;
    // 0x8007ED0C: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8007ED10: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8007ED14: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8007ED18: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8007ED1C: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8007ED20: beq         $at, $zero, L_8007ED30
    if (ctx->r1 == 0) {
        // 0x8007ED24: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_8007ED30;
    }
    // 0x8007ED24: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007ED28: b           L_8007ED34
    // 0x8007ED2C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
        goto L_8007ED34;
    // 0x8007ED2C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_8007ED30:
    // 0x8007ED30: addiu       $a0, $zero, 0x7FF
    ctx->r4 = ADD32(0, 0X7FF);
L_8007ED34:
    // 0x8007ED34: andi        $t9, $a0, 0xFFF
    ctx->r25 = ctx->r4 & 0XFFF;
    // 0x8007ED38: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x8007ED3C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007ED40: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x8007ED44: sw          $t6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r14;
    // 0x8007ED48: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8007ED4C: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8007ED50: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007ED54: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007ED58: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8007ED5C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007ED60: lui         $at, 0xF570
    ctx->r1 = S32(0XF570 << 16);
    // 0x8007ED64: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007ED68: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x8007ED6C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8007ED70: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8007ED74: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007ED78: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007ED7C: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x8007ED80: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8007ED84: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8007ED88: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8007ED8C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007ED90: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x8007ED94: lh          $t8, 0x6($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X6);
    // 0x8007ED98: nop

    // 0x8007ED9C: ori         $t6, $t8, 0x4
    ctx->r14 = ctx->r24 | 0X4;
    // 0x8007EDA0: sh          $t6, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r14;
L_8007EDA4:
    // 0x8007EDA4: lw          $t7, 0x27C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X27C);
    // 0x8007EDA8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8007EDAC: bne         $t7, $at, L_8007EF24
    if (ctx->r15 != ctx->r1) {
        // 0x8007EDB0: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8007EF24;
    }
    // 0x8007EDB0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8007EDB4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007EDB8: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x8007EDBC: addu        $t8, $s1, $at
    ctx->r24 = ADD32(ctx->r17, ctx->r1);
    // 0x8007EDC0: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EDC4: lui         $t9, 0xFD70
    ctx->r25 = S32(0XFD70 << 16);
    // 0x8007EDC8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007EDCC: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x8007EDD0: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8007EDD4: lui         $t6, 0xF570
    ctx->r14 = S32(0XF570 << 16);
    // 0x8007EDD8: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x8007EDDC: lw          $v0, 0x268($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X268);
    // 0x8007EDE0: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
    // 0x8007EDE4: lw          $v1, 0x260($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X260);
    // 0x8007EDE8: andi        $t7, $v0, 0x3
    ctx->r15 = ctx->r2 & 0X3;
    // 0x8007EDEC: sll         $v0, $t7, 18
    ctx->r2 = S32(ctx->r15 << 18);
    // 0x8007EDF0: lw          $a2, 0x264($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X264);
    // 0x8007EDF4: andi        $t7, $a1, 0x3
    ctx->r15 = ctx->r5 & 0X3;
    // 0x8007EDF8: andi        $t8, $v1, 0xF
    ctx->r24 = ctx->r3 & 0XF;
    // 0x8007EDFC: sll         $v1, $t8, 14
    ctx->r3 = S32(ctx->r24 << 14);
    // 0x8007EE00: sll         $a1, $t7, 8
    ctx->r5 = S32(ctx->r15 << 8);
    // 0x8007EE04: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007EE08: or          $t7, $v0, $at
    ctx->r15 = ctx->r2 | ctx->r1;
    // 0x8007EE0C: andi        $t8, $a2, 0xF
    ctx->r24 = ctx->r6 & 0XF;
    // 0x8007EE10: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007EE14: sll         $a2, $t8, 4
    ctx->r6 = S32(ctx->r24 << 4);
    // 0x8007EE18: or          $t9, $t7, $v1
    ctx->r25 = ctx->r15 | ctx->r3;
    // 0x8007EE1C: or          $t8, $t9, $a1
    ctx->r24 = ctx->r25 | ctx->r5;
    // 0x8007EE20: or          $t6, $t8, $a2
    ctx->r14 = ctx->r24 | ctx->r6;
    // 0x8007EE24: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EE28: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x8007EE2C: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
    // 0x8007EE30: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EE34: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x8007EE38: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x8007EE3C: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x8007EE40: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x8007EE44: or          $t8, $v0, $v1
    ctx->r24 = ctx->r2 | ctx->r3;
    // 0x8007EE48: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x8007EE4C: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x8007EE50: or          $t6, $t8, $a1
    ctx->r14 = ctx->r24 | ctx->r5;
    // 0x8007EE54: addiu       $t9, $t5, -0x1
    ctx->r25 = ADD32(ctx->r13, -0X1);
    // 0x8007EE58: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x8007EE5C: or          $t7, $t6, $a2
    ctx->r15 = ctx->r14 | ctx->r6;
    // 0x8007EE60: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x8007EE64: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8007EE68: addiu       $t9, $s0, -0x1
    ctx->r25 = ADD32(ctx->r16, -0X1);
    // 0x8007EE6C: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x8007EE70: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x8007EE74: mflo        $t2
    ctx->r10 = lo;
    // 0x8007EE78: addiu       $t0, $t2, 0x1
    ctx->r8 = ADD32(ctx->r10, 0X1);
    // 0x8007EE7C: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x8007EE80: sra         $t8, $t0, 1
    ctx->r24 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8007EE84: addiu       $t0, $t8, -0x1
    ctx->r8 = ADD32(ctx->r24, -0X1);
    // 0x8007EE88: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8007EE8C: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x8007EE90: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x8007EE94: beq         $at, $zero, L_8007EEA4
    if (ctx->r1 == 0) {
        // 0x8007EE98: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_8007EEA4;
    }
    // 0x8007EE98: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EE9C: b           L_8007EEA8
    // 0x8007EEA0: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
        goto L_8007EEA8;
    // 0x8007EEA0: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_8007EEA4:
    // 0x8007EEA4: addiu       $a0, $zero, 0x7FF
    ctx->r4 = ADD32(0, 0X7FF);
L_8007EEA8:
    // 0x8007EEA8: andi        $t7, $a0, 0xFFF
    ctx->r15 = ctx->r4 & 0XFFF;
    // 0x8007EEAC: sll         $t6, $t7, 12
    ctx->r14 = S32(ctx->r15 << 12);
    // 0x8007EEB0: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007EEB4: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x8007EEB8: sw          $t9, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r25;
    // 0x8007EEBC: addiu       $t7, $t5, 0x7
    ctx->r15 = ADD32(ctx->r13, 0X7);
    // 0x8007EEC0: sra         $t6, $t7, 3
    ctx->r14 = S32(SIGNED(ctx->r15) >> 3);
    // 0x8007EEC4: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8007EEC8: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8007EECC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007EED0: andi        $t9, $t6, 0x1FF
    ctx->r25 = ctx->r14 & 0X1FF;
    // 0x8007EED4: sll         $t8, $t9, 9
    ctx->r24 = S32(ctx->r25 << 9);
    // 0x8007EED8: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EEDC: lui         $at, 0xF568
    ctx->r1 = S32(0XF568 << 16);
    // 0x8007EEE0: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x8007EEE4: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007EEE8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007EEEC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8007EEF0: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8007EEF4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EEF8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007EEFC: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x8007EF00: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8007EF04: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8007EF08: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8007EF0C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EF10: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x8007EF14: lh          $t7, 0x6($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X6);
    // 0x8007EF18: nop

    // 0x8007EF1C: ori         $t6, $t7, 0x4
    ctx->r14 = ctx->r15 | 0X4;
    // 0x8007EF20: sh          $t6, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r14;
L_8007EF24:
    // 0x8007EF24: lw          $t9, 0x27C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X27C);
    // 0x8007EF28: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8007EF2C: bne         $t9, $at, L_8007F0A8
    if (ctx->r25 != ctx->r1) {
        // 0x8007EF30: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8007F0A8;
    }
    // 0x8007EF30: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8007EF34: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007EF38: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x8007EF3C: addu        $t7, $s1, $at
    ctx->r15 = ADD32(ctx->r17, ctx->r1);
    // 0x8007EF40: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EF44: lui         $t8, 0xFD70
    ctx->r24 = S32(0XFD70 << 16);
    // 0x8007EF48: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007EF4C: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x8007EF50: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8007EF54: lui         $t6, 0xF570
    ctx->r14 = S32(0XF570 << 16);
    // 0x8007EF58: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8007EF5C: lw          $v0, 0x268($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X268);
    // 0x8007EF60: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
    // 0x8007EF64: lw          $v1, 0x260($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X260);
    // 0x8007EF68: andi        $t9, $v0, 0x3
    ctx->r25 = ctx->r2 & 0X3;
    // 0x8007EF6C: sll         $v0, $t9, 18
    ctx->r2 = S32(ctx->r25 << 18);
    // 0x8007EF70: lw          $a2, 0x264($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X264);
    // 0x8007EF74: andi        $t9, $a1, 0x3
    ctx->r25 = ctx->r5 & 0X3;
    // 0x8007EF78: andi        $t7, $v1, 0xF
    ctx->r15 = ctx->r3 & 0XF;
    // 0x8007EF7C: sll         $v1, $t7, 14
    ctx->r3 = S32(ctx->r15 << 14);
    // 0x8007EF80: sll         $a1, $t9, 8
    ctx->r5 = S32(ctx->r25 << 8);
    // 0x8007EF84: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007EF88: or          $t9, $v0, $at
    ctx->r25 = ctx->r2 | ctx->r1;
    // 0x8007EF8C: andi        $t7, $a2, 0xF
    ctx->r15 = ctx->r6 & 0XF;
    // 0x8007EF90: sll         $a2, $t7, 4
    ctx->r6 = S32(ctx->r15 << 4);
    // 0x8007EF94: or          $t8, $t9, $v1
    ctx->r24 = ctx->r25 | ctx->r3;
    // 0x8007EF98: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007EF9C: or          $t7, $t8, $a1
    ctx->r15 = ctx->r24 | ctx->r5;
    // 0x8007EFA0: or          $t6, $t7, $a2
    ctx->r14 = ctx->r15 | ctx->r6;
    // 0x8007EFA4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EFA8: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x8007EFAC: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x8007EFB0: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EFB4: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8007EFB8: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8007EFBC: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x8007EFC0: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x8007EFC4: or          $t7, $v0, $v1
    ctx->r15 = ctx->r2 | ctx->r3;
    // 0x8007EFC8: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x8007EFCC: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8007EFD0: or          $t6, $t7, $a1
    ctx->r14 = ctx->r15 | ctx->r5;
    // 0x8007EFD4: addiu       $t8, $t5, -0x1
    ctx->r24 = ADD32(ctx->r13, -0X1);
    // 0x8007EFD8: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8007EFDC: or          $t9, $t6, $a2
    ctx->r25 = ctx->r14 | ctx->r6;
    // 0x8007EFE0: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x8007EFE4: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x8007EFE8: addiu       $t8, $s0, -0x1
    ctx->r24 = ADD32(ctx->r16, -0X1);
    // 0x8007EFEC: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8007EFF0: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x8007EFF4: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x8007EFF8: mflo        $t0
    ctx->r8 = lo;
    // 0x8007EFFC: addiu       $t0, $t0, 0x3
    ctx->r8 = ADD32(ctx->r8, 0X3);
    // 0x8007F000: sra         $ra, $t5, 1
    ctx->r31 = S32(SIGNED(ctx->r13) >> 1);
    // 0x8007F004: addiu       $ra, $ra, 0x7
    ctx->r31 = ADD32(ctx->r31, 0X7);
    // 0x8007F008: sra         $t7, $t0, 2
    ctx->r15 = S32(SIGNED(ctx->r8) >> 2);
    // 0x8007F00C: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x8007F010: sra         $t9, $ra, 3
    ctx->r25 = S32(SIGNED(ctx->r31) >> 3);
    // 0x8007F014: addiu       $t0, $t7, -0x1
    ctx->r8 = ADD32(ctx->r15, -0X1);
    // 0x8007F018: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8007F01C: andi        $t6, $t9, 0x1FF
    ctx->r14 = ctx->r25 & 0X1FF;
    // 0x8007F020: sll         $ra, $t6, 9
    ctx->r31 = S32(ctx->r14 << 9);
    // 0x8007F024: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x8007F028: beq         $at, $zero, L_8007F038
    if (ctx->r1 == 0) {
        // 0x8007F02C: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_8007F038;
    }
    // 0x8007F02C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007F030: b           L_8007F03C
    // 0x8007F034: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
        goto L_8007F03C;
    // 0x8007F034: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_8007F038:
    // 0x8007F038: addiu       $a0, $zero, 0x7FF
    ctx->r4 = ADD32(0, 0X7FF);
L_8007F03C:
    // 0x8007F03C: andi        $t7, $a0, 0xFFF
    ctx->r15 = ctx->r4 & 0XFFF;
    // 0x8007F040: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x8007F044: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007F048: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x8007F04C: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8007F050: sw          $t6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r14;
    // 0x8007F054: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007F058: lui         $at, 0xF560
    ctx->r1 = S32(0XF560 << 16);
    // 0x8007F05C: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8007F060: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007F064: or          $t7, $ra, $at
    ctx->r15 = ctx->r31 | ctx->r1;
    // 0x8007F068: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007F06C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007F070: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8007F074: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8007F078: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007F07C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007F080: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x8007F084: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8007F088: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8007F08C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8007F090: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007F094: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x8007F098: lh          $t7, 0x6($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X6);
    // 0x8007F09C: nop

    // 0x8007F0A0: ori         $t9, $t7, 0x4
    ctx->r25 = ctx->r15 | 0X4;
    // 0x8007F0A4: sh          $t9, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r25;
L_8007F0A8:
    // 0x8007F0A8: lw          $t6, 0x27C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X27C);
    // 0x8007F0AC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007F0B0: bne         $t6, $at, L_8007F218
    if (ctx->r14 != ctx->r1) {
        // 0x8007F0B4: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8007F218;
    }
    // 0x8007F0B4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8007F0B8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007F0BC: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x8007F0C0: addu        $t7, $s1, $at
    ctx->r15 = ADD32(ctx->r17, ctx->r1);
    // 0x8007F0C4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007F0C8: lui         $t8, 0xFD90
    ctx->r24 = S32(0XFD90 << 16);
    // 0x8007F0CC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007F0D0: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x8007F0D4: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8007F0D8: lui         $t9, 0xF590
    ctx->r25 = S32(0XF590 << 16);
    // 0x8007F0DC: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8007F0E0: lw          $v0, 0x268($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X268);
    // 0x8007F0E4: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
    // 0x8007F0E8: lw          $v1, 0x260($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X260);
    // 0x8007F0EC: andi        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 & 0X3;
    // 0x8007F0F0: sll         $v0, $t6, 18
    ctx->r2 = S32(ctx->r14 << 18);
    // 0x8007F0F4: lw          $a2, 0x264($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X264);
    // 0x8007F0F8: andi        $t6, $a1, 0x3
    ctx->r14 = ctx->r5 & 0X3;
    // 0x8007F0FC: andi        $t7, $v1, 0xF
    ctx->r15 = ctx->r3 & 0XF;
    // 0x8007F100: sll         $v1, $t7, 14
    ctx->r3 = S32(ctx->r15 << 14);
    // 0x8007F104: sll         $a1, $t6, 8
    ctx->r5 = S32(ctx->r14 << 8);
    // 0x8007F108: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007F10C: or          $t6, $v0, $at
    ctx->r14 = ctx->r2 | ctx->r1;
    // 0x8007F110: andi        $t7, $a2, 0xF
    ctx->r15 = ctx->r6 & 0XF;
    // 0x8007F114: sll         $a2, $t7, 4
    ctx->r6 = S32(ctx->r15 << 4);
    // 0x8007F118: or          $t8, $t6, $v1
    ctx->r24 = ctx->r14 | ctx->r3;
    // 0x8007F11C: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007F120: or          $t7, $t8, $a1
    ctx->r15 = ctx->r24 | ctx->r5;
    // 0x8007F124: or          $t9, $t7, $a2
    ctx->r25 = ctx->r15 | ctx->r6;
    // 0x8007F128: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007F12C: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x8007F130: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x8007F134: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007F138: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x8007F13C: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x8007F140: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x8007F144: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x8007F148: or          $t7, $v0, $v1
    ctx->r15 = ctx->r2 | ctx->r3;
    // 0x8007F14C: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x8007F150: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8007F154: or          $t9, $t7, $a1
    ctx->r25 = ctx->r15 | ctx->r5;
    // 0x8007F158: addiu       $t8, $t5, -0x1
    ctx->r24 = ADD32(ctx->r13, -0X1);
    // 0x8007F15C: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8007F160: or          $t6, $t9, $a2
    ctx->r14 = ctx->r25 | ctx->r6;
    // 0x8007F164: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x8007F168: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8007F16C: addiu       $t8, $s0, -0x1
    ctx->r24 = ADD32(ctx->r16, -0X1);
    // 0x8007F170: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8007F174: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x8007F178: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x8007F17C: mflo        $t0
    ctx->r8 = lo;
    // 0x8007F180: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8007F184: sra         $t7, $t0, 1
    ctx->r15 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8007F188: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x8007F18C: addiu       $t4, $t5, 0x7
    ctx->r12 = ADD32(ctx->r13, 0X7);
    // 0x8007F190: sra         $t6, $t4, 3
    ctx->r14 = S32(SIGNED(ctx->r12) >> 3);
    // 0x8007F194: addiu       $t0, $t7, -0x1
    ctx->r8 = ADD32(ctx->r15, -0X1);
    // 0x8007F198: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8007F19C: andi        $t9, $t6, 0x1FF
    ctx->r25 = ctx->r14 & 0X1FF;
    // 0x8007F1A0: sll         $t4, $t9, 9
    ctx->r12 = S32(ctx->r25 << 9);
    // 0x8007F1A4: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x8007F1A8: beq         $at, $zero, L_8007F1B8
    if (ctx->r1 == 0) {
        // 0x8007F1AC: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_8007F1B8;
    }
    // 0x8007F1AC: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007F1B0: b           L_8007F1BC
    // 0x8007F1B4: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
        goto L_8007F1BC;
    // 0x8007F1B4: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_8007F1B8:
    // 0x8007F1B8: addiu       $a0, $zero, 0x7FF
    ctx->r4 = ADD32(0, 0X7FF);
L_8007F1BC:
    // 0x8007F1BC: andi        $t7, $a0, 0xFFF
    ctx->r15 = ctx->r4 & 0XFFF;
    // 0x8007F1C0: sll         $t6, $t7, 12
    ctx->r14 = S32(ctx->r15 << 12);
    // 0x8007F1C4: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007F1C8: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x8007F1CC: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8007F1D0: sw          $t9, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r25;
    // 0x8007F1D4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007F1D8: lui         $at, 0xF588
    ctx->r1 = S32(0XF588 << 16);
    // 0x8007F1DC: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8007F1E0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007F1E4: or          $t7, $t4, $at
    ctx->r15 = ctx->r12 | ctx->r1;
    // 0x8007F1E8: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007F1EC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007F1F0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8007F1F4: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8007F1F8: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007F1FC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007F200: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x8007F204: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8007F208: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8007F20C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8007F210: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007F214: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
L_8007F218:
    // 0x8007F218: lw          $t7, 0x27C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X27C);
    // 0x8007F21C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8007F220: bne         $t7, $at, L_8007F38C
    if (ctx->r15 != ctx->r1) {
        // 0x8007F224: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8007F38C;
    }
    // 0x8007F224: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8007F228: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007F22C: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x8007F230: addu        $t9, $s1, $at
    ctx->r25 = ADD32(ctx->r17, ctx->r1);
    // 0x8007F234: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007F238: lui         $t6, 0xFD90
    ctx->r14 = S32(0XFD90 << 16);
    // 0x8007F23C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007F240: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x8007F244: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8007F248: lui         $t8, 0xF590
    ctx->r24 = S32(0XF590 << 16);
    // 0x8007F24C: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8007F250: lw          $v0, 0x268($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X268);
    // 0x8007F254: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
    // 0x8007F258: lw          $v1, 0x260($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X260);
    // 0x8007F25C: andi        $t7, $v0, 0x3
    ctx->r15 = ctx->r2 & 0X3;
    // 0x8007F260: sll         $v0, $t7, 18
    ctx->r2 = S32(ctx->r15 << 18);
    // 0x8007F264: lw          $a2, 0x264($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X264);
    // 0x8007F268: andi        $t7, $a1, 0x3
    ctx->r15 = ctx->r5 & 0X3;
    // 0x8007F26C: andi        $t9, $v1, 0xF
    ctx->r25 = ctx->r3 & 0XF;
    // 0x8007F270: sll         $v1, $t9, 14
    ctx->r3 = S32(ctx->r25 << 14);
    // 0x8007F274: sll         $a1, $t7, 8
    ctx->r5 = S32(ctx->r15 << 8);
    // 0x8007F278: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007F27C: or          $t7, $v0, $at
    ctx->r15 = ctx->r2 | ctx->r1;
    // 0x8007F280: andi        $t9, $a2, 0xF
    ctx->r25 = ctx->r6 & 0XF;
    // 0x8007F284: sll         $a2, $t9, 4
    ctx->r6 = S32(ctx->r25 << 4);
    // 0x8007F288: or          $t6, $t7, $v1
    ctx->r14 = ctx->r15 | ctx->r3;
    // 0x8007F28C: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007F290: or          $t9, $t6, $a1
    ctx->r25 = ctx->r14 | ctx->r5;
    // 0x8007F294: or          $t8, $t9, $a2
    ctx->r24 = ctx->r25 | ctx->r6;
    // 0x8007F298: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007F29C: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x8007F2A0: sw          $t8, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r24;
    // 0x8007F2A4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007F2A8: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x8007F2AC: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x8007F2B0: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x8007F2B4: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x8007F2B8: or          $t9, $v0, $v1
    ctx->r25 = ctx->r2 | ctx->r3;
    // 0x8007F2BC: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x8007F2C0: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x8007F2C4: or          $t8, $t9, $a1
    ctx->r24 = ctx->r25 | ctx->r5;
    // 0x8007F2C8: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8007F2CC: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x8007F2D0: or          $t7, $t8, $a2
    ctx->r15 = ctx->r24 | ctx->r6;
    // 0x8007F2D4: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x8007F2D8: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8007F2DC: addiu       $t6, $s0, -0x1
    ctx->r14 = ADD32(ctx->r16, -0X1);
    // 0x8007F2E0: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x8007F2E4: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x8007F2E8: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x8007F2EC: mflo        $t0
    ctx->r8 = lo;
    // 0x8007F2F0: addiu       $t0, $t0, 0x3
    ctx->r8 = ADD32(ctx->r8, 0X3);
    // 0x8007F2F4: sra         $ra, $t5, 1
    ctx->r31 = S32(SIGNED(ctx->r13) >> 1);
    // 0x8007F2F8: addiu       $ra, $ra, 0x7
    ctx->r31 = ADD32(ctx->r31, 0X7);
    // 0x8007F2FC: sra         $t9, $t0, 2
    ctx->r25 = S32(SIGNED(ctx->r8) >> 2);
    // 0x8007F300: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x8007F304: sra         $t7, $ra, 3
    ctx->r15 = S32(SIGNED(ctx->r31) >> 3);
    // 0x8007F308: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x8007F30C: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8007F310: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x8007F314: sll         $ra, $t8, 9
    ctx->r31 = S32(ctx->r24 << 9);
    // 0x8007F318: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x8007F31C: beq         $at, $zero, L_8007F32C
    if (ctx->r1 == 0) {
        // 0x8007F320: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_8007F32C;
    }
    // 0x8007F320: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007F324: b           L_8007F330
    // 0x8007F328: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
        goto L_8007F330;
    // 0x8007F328: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_8007F32C:
    // 0x8007F32C: addiu       $a0, $zero, 0x7FF
    ctx->r4 = ADD32(0, 0X7FF);
L_8007F330:
    // 0x8007F330: andi        $t9, $a0, 0xFFF
    ctx->r25 = ctx->r4 & 0XFFF;
    // 0x8007F334: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x8007F338: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007F33C: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8007F340: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8007F344: sw          $t8, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r24;
    // 0x8007F348: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007F34C: lui         $at, 0xF580
    ctx->r1 = S32(0XF580 << 16);
    // 0x8007F350: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8007F354: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8007F358: or          $t9, $ra, $at
    ctx->r25 = ctx->r31 | ctx->r1;
    // 0x8007F35C: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007F360: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007F364: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8007F368: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8007F36C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007F370: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007F374: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x8007F378: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8007F37C: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8007F380: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8007F384: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007F388: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
L_8007F38C:
    // 0x8007F38C: lw          $t9, 0xC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XC);
    // 0x8007F390: nop

    // 0x8007F394: subu        $t7, $a3, $t9
    ctx->r15 = SUB32(ctx->r7, ctx->r25);
    // 0x8007F398: sra         $t8, $t7, 3
    ctx->r24 = S32(SIGNED(ctx->r15) >> 3);
    // 0x8007F39C: sh          $t8, 0xA($s1)
    MEM_H(0XA, ctx->r17) = ctx->r24;
L_8007F3A0:
    // 0x8007F3A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007F3A4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8007F3A8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8007F3AC: jr          $ra
    // 0x8007F3B0: addiu       $sp, $sp, 0x280
    ctx->r29 = ADD32(ctx->r29, 0X280);
    return;
    // 0x8007F3B0: addiu       $sp, $sp, 0x280
    ctx->r29 = ADD32(ctx->r29, 0X280);
;}
RECOMP_FUNC void tex_palette_id(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007F3B4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8007F3B8: lw          $t8, 0x68CC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X68CC);
    // 0x8007F3BC: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8007F3C0: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8007F3C4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8007F3C8: jr          $ra
    // 0x8007F3CC: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    return;
    // 0x8007F3CC: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
;}
RECOMP_FUNC void tex_animate_texture(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007F3D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007F3D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007F3D8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8007F3DC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8007F3E0: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8007F3E4: lui         $t0, 0x400
    ctx->r8 = S32(0X400 << 16);
    // 0x8007F3E8: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x8007F3EC: sll         $v1, $v0, 8
    ctx->r3 = S32(ctx->r2 << 8);
    // 0x8007F3F0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8007F3F4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8007F3F8: and         $t2, $v0, $t0
    ctx->r10 = ctx->r2 & ctx->r8;
    // 0x8007F3FC: bgez        $v1, L_8007F4EC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8007F400: and         $t1, $v0, $at
        ctx->r9 = ctx->r2 & ctx->r1;
            goto L_8007F4EC;
    }
    // 0x8007F400: and         $t1, $v0, $at
    ctx->r9 = ctx->r2 & ctx->r1;
    // 0x8007F404: bne         $t1, $zero, L_8007F440
    if (ctx->r9 != 0) {
        // 0x8007F408: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8007F440;
    }
    // 0x8007F408: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8007F40C: jal         0x8006FB8C
    // 0x8007F410: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    rand_range(rdram, ctx);
        goto after_0;
    // 0x8007F410: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    after_0:
    // 0x8007F414: slti        $at, $v0, 0x3DA
    ctx->r1 = SIGNED(ctx->r2) < 0X3DA ? 1 : 0;
    // 0x8007F418: bne         $at, $zero, L_8007F624
    if (ctx->r1 != 0) {
        // 0x8007F41C: lui         $a1, 0xFBFF
        ctx->r5 = S32(0XFBFF << 16);
            goto L_8007F624;
    }
    // 0x8007F41C: lui         $a1, 0xFBFF
    ctx->r5 = S32(0XFBFF << 16);
    // 0x8007F420: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8007F424: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x8007F428: and         $t7, $t6, $a1
    ctx->r15 = ctx->r14 & ctx->r5;
    // 0x8007F42C: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x8007F430: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8007F434: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x8007F438: b           L_8007F624
    // 0x8007F43C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
        goto L_8007F624;
    // 0x8007F43C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
L_8007F440:
    // 0x8007F440: bne         $t2, $zero, L_8007F4B4
    if (ctx->r10 != 0) {
        // 0x8007F444: nop
    
            goto L_8007F4B4;
    }
    // 0x8007F444: nop

    // 0x8007F448: lhu         $t4, 0x14($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0X14);
    // 0x8007F44C: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x8007F450: multu       $t4, $a3
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007F454: mflo        $t5
    ctx->r13 = lo;
    // 0x8007F458: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x8007F45C: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8007F460: lhu         $v1, 0x12($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X12);
    // 0x8007F464: nop

    // 0x8007F468: slt         $at, $t6, $v1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8007F46C: bne         $at, $zero, L_8007F624
    if (ctx->r1 != 0) {
        // 0x8007F470: sll         $t7, $v1, 1
        ctx->r15 = S32(ctx->r3 << 1);
            goto L_8007F624;
    }
    // 0x8007F470: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x8007F474: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x8007F478: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8007F47C: bgez        $t9, L_8007F4A0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8007F480: sw          $t9, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r25;
            goto L_8007F4A0;
    }
    // 0x8007F480: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x8007F484: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x8007F488: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8007F48C: lui         $at, 0xF9FF
    ctx->r1 = S32(0XF9FF << 16);
    // 0x8007F490: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8007F494: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x8007F498: b           L_8007F624
    // 0x8007F49C: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
        goto L_8007F624;
    // 0x8007F49C: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
L_8007F4A0:
    // 0x8007F4A0: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8007F4A4: nop

    // 0x8007F4A8: or          $t7, $t6, $t0
    ctx->r15 = ctx->r14 | ctx->r8;
    // 0x8007F4AC: b           L_8007F624
    // 0x8007F4B0: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
        goto L_8007F624;
    // 0x8007F4B0: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
L_8007F4B4:
    // 0x8007F4B4: lhu         $t9, 0x14($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X14);
    // 0x8007F4B8: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8007F4BC: multu       $t9, $a3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007F4C0: lui         $at, 0xF9FF
    ctx->r1 = S32(0XF9FF << 16);
    // 0x8007F4C4: mflo        $t4
    ctx->r12 = lo;
    // 0x8007F4C8: subu        $t3, $t8, $t4
    ctx->r11 = SUB32(ctx->r24, ctx->r12);
    // 0x8007F4CC: bgez        $t3, L_8007F624
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8007F4D0: sw          $t3, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r11;
            goto L_8007F624;
    }
    // 0x8007F4D0: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x8007F4D4: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x8007F4D8: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8007F4DC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8007F4E0: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x8007F4E4: b           L_8007F624
    // 0x8007F4E8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
        goto L_8007F624;
    // 0x8007F4E8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
L_8007F4EC:
    // 0x8007F4EC: beq         $t1, $zero, L_8007F59C
    if (ctx->r9 == 0) {
        // 0x8007F4F0: lui         $a1, 0xFBFF
        ctx->r5 = S32(0XFBFF << 16);
            goto L_8007F59C;
    }
    // 0x8007F4F0: lui         $a1, 0xFBFF
    ctx->r5 = S32(0XFBFF << 16);
    // 0x8007F4F4: bne         $t2, $zero, L_8007F518
    if (ctx->r10 != 0) {
        // 0x8007F4F8: ori         $a1, $a1, 0xFFFF
        ctx->r5 = ctx->r5 | 0XFFFF;
            goto L_8007F518;
    }
    // 0x8007F4F8: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x8007F4FC: lhu         $t8, 0x14($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0X14);
    // 0x8007F500: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x8007F504: multu       $t8, $a3
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007F508: mflo        $t4
    ctx->r12 = lo;
    // 0x8007F50C: addu        $t3, $t9, $t4
    ctx->r11 = ADD32(ctx->r25, ctx->r12);
    // 0x8007F510: b           L_8007F530
    // 0x8007F514: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
        goto L_8007F530;
    // 0x8007F514: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
L_8007F518:
    // 0x8007F518: lhu         $t6, 0x14($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0X14);
    // 0x8007F51C: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x8007F520: multu       $t6, $a3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007F524: mflo        $t7
    ctx->r15 = lo;
    // 0x8007F528: subu        $t8, $t5, $t7
    ctx->r24 = SUB32(ctx->r13, ctx->r15);
    // 0x8007F52C: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
L_8007F530:
    // 0x8007F530: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8007F534: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8007F538: bgez        $v0, L_8007F55C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8007F53C: negu        $t9, $v0
        ctx->r25 = SUB32(0, ctx->r2);
            goto L_8007F55C;
    }
    // 0x8007F53C: negu        $t9, $v0
    ctx->r25 = SUB32(0, ctx->r2);
    // 0x8007F540: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x8007F544: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8007F548: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8007F54C: and         $t3, $t4, $a1
    ctx->r11 = ctx->r12 & ctx->r5;
    // 0x8007F550: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x8007F554: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8007F558: nop

L_8007F55C:
    // 0x8007F55C: lhu         $v1, 0x12($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X12);
    // 0x8007F560: nop

    // 0x8007F564: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8007F568: bne         $at, $zero, L_8007F58C
    if (ctx->r1 != 0) {
        // 0x8007F56C: sll         $t6, $v1, 1
        ctx->r14 = S32(ctx->r3 << 1);
            goto L_8007F58C;
    }
    // 0x8007F56C: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x8007F570: subu        $t5, $t6, $v0
    ctx->r13 = SUB32(ctx->r14, ctx->r2);
    // 0x8007F574: addiu       $t7, $t5, -0x1
    ctx->r15 = ADD32(ctx->r13, -0X1);
    // 0x8007F578: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x8007F57C: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8007F580: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8007F584: or          $t9, $t8, $t0
    ctx->r25 = ctx->r24 | ctx->r8;
    // 0x8007F588: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
L_8007F58C:
    // 0x8007F58C: bne         $a0, $zero, L_8007F530
    if (ctx->r4 != 0) {
        // 0x8007F590: nop
    
            goto L_8007F530;
    }
    // 0x8007F590: nop

    // 0x8007F594: b           L_8007F628
    // 0x8007F598: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8007F628;
    // 0x8007F598: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007F59C:
    // 0x8007F59C: bne         $t2, $zero, L_8007F5F0
    if (ctx->r10 != 0) {
        // 0x8007F5A0: nop
    
            goto L_8007F5F0;
    }
    // 0x8007F5A0: nop

    // 0x8007F5A4: lhu         $t3, 0x14($s1)
    ctx->r11 = MEM_HU(ctx->r17, 0X14);
    // 0x8007F5A8: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x8007F5AC: multu       $t3, $a3
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007F5B0: mflo        $t6
    ctx->r14 = lo;
    // 0x8007F5B4: addu        $v0, $t4, $t6
    ctx->r2 = ADD32(ctx->r12, ctx->r14);
    // 0x8007F5B8: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x8007F5BC: lhu         $v1, 0x12($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X12);
    // 0x8007F5C0: nop

    // 0x8007F5C4: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8007F5C8: bne         $at, $zero, L_8007F624
    if (ctx->r1 != 0) {
        // 0x8007F5CC: subu        $t7, $v0, $v1
        ctx->r15 = SUB32(ctx->r2, ctx->r3);
            goto L_8007F624;
    }
    // 0x8007F5CC: subu        $t7, $v0, $v1
    ctx->r15 = SUB32(ctx->r2, ctx->r3);
L_8007F5D0:
    // 0x8007F5D0: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x8007F5D4: lhu         $v1, 0x12($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X12);
    // 0x8007F5D8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007F5DC: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8007F5E0: beq         $at, $zero, L_8007F5D0
    if (ctx->r1 == 0) {
        // 0x8007F5E4: subu        $t7, $v0, $v1
        ctx->r15 = SUB32(ctx->r2, ctx->r3);
            goto L_8007F5D0;
    }
    // 0x8007F5E4: subu        $t7, $v0, $v1
    ctx->r15 = SUB32(ctx->r2, ctx->r3);
    // 0x8007F5E8: b           L_8007F628
    // 0x8007F5EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8007F628;
    // 0x8007F5EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007F5F0:
    // 0x8007F5F0: lhu         $t9, 0x14($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X14);
    // 0x8007F5F4: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8007F5F8: multu       $t9, $a3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007F5FC: mflo        $t3
    ctx->r11 = lo;
    // 0x8007F600: subu        $v0, $t8, $t3
    ctx->r2 = SUB32(ctx->r24, ctx->r11);
    // 0x8007F604: bgez        $v0, L_8007F624
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8007F608: sw          $v0, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r2;
            goto L_8007F624;
    }
    // 0x8007F608: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
L_8007F60C:
    // 0x8007F60C: lhu         $t6, 0x12($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0X12);
    // 0x8007F610: nop

    // 0x8007F614: addu        $t5, $v0, $t6
    ctx->r13 = ADD32(ctx->r2, ctx->r14);
    // 0x8007F618: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x8007F61C: bltz        $t5, L_8007F60C
    if (SIGNED(ctx->r13) < 0) {
        // 0x8007F620: or          $v0, $t5, $zero
        ctx->r2 = ctx->r13 | 0;
            goto L_8007F60C;
    }
    // 0x8007F620: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_8007F624:
    // 0x8007F624: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007F628:
    // 0x8007F628: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8007F62C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8007F630: jr          $ra
    // 0x8007F634: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8007F634: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8007F1E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007F638: lbu         $t6, 0x14($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X14);
    // 0x8007F63C: lbu         $t7, 0x15($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X15);
    // 0x8007F640: lbu         $t8, 0x16($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X16);
    // 0x8007F644: lbu         $t9, 0x17($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X17);
    // 0x8007F648: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8007F64C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8007F650: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x8007F654: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x8007F658: sb          $t6, 0x10($a0)
    MEM_B(0X10, ctx->r4) = ctx->r14;
    // 0x8007F65C: sb          $t7, 0x11($a0)
    MEM_B(0X11, ctx->r4) = ctx->r15;
    // 0x8007F660: sb          $t8, 0x12($a0)
    MEM_B(0X12, ctx->r4) = ctx->r24;
    // 0x8007F664: blez        $v1, L_8007F694
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8007F668: sb          $t9, 0x13($a0)
        MEM_B(0X13, ctx->r4) = ctx->r25;
            goto L_8007F694;
    }
    // 0x8007F668: sb          $t9, 0x13($a0)
    MEM_B(0X13, ctx->r4) = ctx->r25;
    // 0x8007F66C: sll         $t0, $v1, 3
    ctx->r8 = S32(ctx->r3 << 3);
    // 0x8007F670: addu        $a1, $t0, $a0
    ctx->r5 = ADD32(ctx->r8, ctx->r4);
    // 0x8007F674: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8007F678:
    // 0x8007F678: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x8007F67C: lw          $t2, 0x18($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X18);
    // 0x8007F680: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8007F684: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x8007F688: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8007F68C: bne         $at, $zero, L_8007F678
    if (ctx->r1 != 0) {
        // 0x8007F690: sw          $t3, 0xC($a0)
        MEM_W(0XC, ctx->r4) = ctx->r11;
            goto L_8007F678;
    }
    // 0x8007F690: sw          $t3, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r11;
L_8007F694:
    // 0x8007F694: jr          $ra
    // 0x8007F698: nop

    return;
    // 0x8007F698: nop

;}
RECOMP_FUNC void update_colour_cycle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007F69C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8007F6A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007F6A4: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x8007F6A8: bne         $at, $zero, L_8007F85C
    if (ctx->r1 != 0) {
        // 0x8007F6AC: nop
    
            goto L_8007F85C;
    }
    // 0x8007F6AC: nop

    // 0x8007F6B0: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x8007F6B4: lw          $v1, 0xC($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XC);
    // 0x8007F6B8: addu        $v0, $t7, $a1
    ctx->r2 = ADD32(ctx->r15, ctx->r5);
    // 0x8007F6BC: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8007F6C0: bne         $at, $zero, L_8007F6DC
    if (ctx->r1 != 0) {
        // 0x8007F6C4: sw          $v0, 0x8($a0)
        MEM_W(0X8, ctx->r4) = ctx->r2;
            goto L_8007F6DC;
    }
    // 0x8007F6C4: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
L_8007F6C8:
    // 0x8007F6C8: subu        $t9, $v0, $v1
    ctx->r25 = SUB32(ctx->r2, ctx->r3);
    // 0x8007F6CC: slt         $at, $t9, $v1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8007F6D0: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    // 0x8007F6D4: beq         $at, $zero, L_8007F6C8
    if (ctx->r1 == 0) {
        // 0x8007F6D8: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_8007F6C8;
    }
    // 0x8007F6D8: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8007F6DC:
    // 0x8007F6DC: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x8007F6E0: nop

    // 0x8007F6E4: sll         $t6, $v1, 3
    ctx->r14 = S32(ctx->r3 << 3);
    // 0x8007F6E8: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8007F6EC: lw          $a1, 0x18($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X18);
    // 0x8007F6F0: nop

    // 0x8007F6F4: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8007F6F8: bne         $at, $zero, L_8007F748
    if (ctx->r1 != 0) {
        // 0x8007F6FC: nop
    
            goto L_8007F748;
    }
    // 0x8007F6FC: nop

L_8007F700:
    // 0x8007F700: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8007F704: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    // 0x8007F708: subu        $t8, $v0, $a1
    ctx->r24 = SUB32(ctx->r2, ctx->r5);
    // 0x8007F70C: slt         $at, $t9, $t6
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8007F710: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x8007F714: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8007F718: bne         $at, $zero, L_8007F728
    if (ctx->r1 != 0) {
        // 0x8007F71C: or          $v1, $t9, $zero
        ctx->r3 = ctx->r25 | 0;
            goto L_8007F728;
    }
    // 0x8007F71C: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x8007F720: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8007F724: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8007F728:
    // 0x8007F728: sll         $t7, $v1, 3
    ctx->r15 = S32(ctx->r3 << 3);
    // 0x8007F72C: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x8007F730: lw          $a1, 0x18($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X18);
    // 0x8007F734: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x8007F738: nop

    // 0x8007F73C: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8007F740: beq         $at, $zero, L_8007F700
    if (ctx->r1 == 0) {
        // 0x8007F744: nop
    
            goto L_8007F700;
    }
    // 0x8007F744: nop

L_8007F748:
    // 0x8007F748: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8007F74C: addiu       $a1, $v1, 0x1
    ctx->r5 = ADD32(ctx->r3, 0X1);
    // 0x8007F750: slt         $at, $a1, $t9
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8007F754: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x8007F758: bne         $at, $zero, L_8007F764
    if (ctx->r1 != 0) {
        // 0x8007F75C: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_8007F764;
    }
    // 0x8007F75C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8007F760: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8007F764:
    // 0x8007F764: sll         $t6, $a2, 3
    ctx->r14 = S32(ctx->r6 << 3);
    // 0x8007F768: addu        $v1, $a0, $t6
    ctx->r3 = ADD32(ctx->r4, ctx->r14);
    // 0x8007F76C: lw          $t8, 0x18($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X18);
    // 0x8007F770: sll         $t7, $v0, 16
    ctx->r15 = S32(ctx->r2 << 16);
    // 0x8007F774: div         $zero, $t7, $t8
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r24))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r24)));
    // 0x8007F778: sll         $t9, $a3, 3
    ctx->r25 = S32(ctx->r7 << 3);
    // 0x8007F77C: addu        $t5, $a0, $t9
    ctx->r13 = ADD32(ctx->r4, ctx->r25);
    // 0x8007F780: lbu         $t0, 0x14($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X14);
    // 0x8007F784: lbu         $t4, 0x14($t5)
    ctx->r12 = MEM_BU(ctx->r13, 0X14);
    // 0x8007F788: lbu         $t6, 0x15($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X15);
    // 0x8007F78C: subu        $t9, $t4, $t0
    ctx->r25 = SUB32(ctx->r12, ctx->r8);
    // 0x8007F790: lbu         $t1, 0x15($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X15);
    // 0x8007F794: lbu         $t2, 0x16($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X16);
    // 0x8007F798: lbu         $t3, 0x17($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X17);
    // 0x8007F79C: bne         $t8, $zero, L_8007F7A8
    if (ctx->r24 != 0) {
        // 0x8007F7A0: nop
    
            goto L_8007F7A8;
    }
    // 0x8007F7A0: nop

    // 0x8007F7A4: break       7
    do_break(2148005796);
L_8007F7A8:
    // 0x8007F7A8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007F7AC: bne         $t8, $at, L_8007F7C0
    if (ctx->r24 != ctx->r1) {
        // 0x8007F7B0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007F7C0;
    }
    // 0x8007F7B0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007F7B4: bne         $t7, $at, L_8007F7C0
    if (ctx->r15 != ctx->r1) {
        // 0x8007F7B8: nop
    
            goto L_8007F7C0;
    }
    // 0x8007F7B8: nop

    // 0x8007F7BC: break       6
    do_break(2148005820);
L_8007F7C0:
    // 0x8007F7C0: sw          $t6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r14;
    // 0x8007F7C4: lbu         $t7, 0x16($t5)
    ctx->r15 = MEM_BU(ctx->r13, 0X16);
    // 0x8007F7C8: nop

    // 0x8007F7CC: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x8007F7D0: lbu         $t8, 0x17($t5)
    ctx->r24 = MEM_BU(ctx->r13, 0X17);
    // 0x8007F7D4: nop

    // 0x8007F7D8: sw          $t8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r24;
    // 0x8007F7DC: mflo        $a1
    ctx->r5 = lo;
    // 0x8007F7E0: nop

    // 0x8007F7E4: nop

    // 0x8007F7E8: multu       $t9, $a1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007F7EC: mflo        $t6
    ctx->r14 = lo;
    // 0x8007F7F0: srl         $t7, $t6, 16
    ctx->r15 = S32(U32(ctx->r14) >> 16);
    // 0x8007F7F4: addu        $t8, $t7, $t0
    ctx->r24 = ADD32(ctx->r15, ctx->r8);
    // 0x8007F7F8: sb          $t8, 0x10($a0)
    MEM_B(0X10, ctx->r4) = ctx->r24;
    // 0x8007F7FC: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x8007F800: nop

    // 0x8007F804: subu        $t6, $t9, $t1
    ctx->r14 = SUB32(ctx->r25, ctx->r9);
    // 0x8007F808: multu       $t6, $a1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007F80C: mflo        $t7
    ctx->r15 = lo;
    // 0x8007F810: srl         $t8, $t7, 16
    ctx->r24 = S32(U32(ctx->r15) >> 16);
    // 0x8007F814: addu        $t9, $t8, $t1
    ctx->r25 = ADD32(ctx->r24, ctx->r9);
    // 0x8007F818: sb          $t9, 0x11($a0)
    MEM_B(0X11, ctx->r4) = ctx->r25;
    // 0x8007F81C: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8007F820: nop

    // 0x8007F824: subu        $t7, $t6, $t2
    ctx->r15 = SUB32(ctx->r14, ctx->r10);
    // 0x8007F828: multu       $t7, $a1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007F82C: mflo        $t8
    ctx->r24 = lo;
    // 0x8007F830: srl         $t9, $t8, 16
    ctx->r25 = S32(U32(ctx->r24) >> 16);
    // 0x8007F834: addu        $t6, $t9, $t2
    ctx->r14 = ADD32(ctx->r25, ctx->r10);
    // 0x8007F838: sb          $t6, 0x12($a0)
    MEM_B(0X12, ctx->r4) = ctx->r14;
    // 0x8007F83C: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x8007F840: nop

    // 0x8007F844: subu        $t8, $t7, $t3
    ctx->r24 = SUB32(ctx->r15, ctx->r11);
    // 0x8007F848: multu       $t8, $a1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007F84C: mflo        $t9
    ctx->r25 = lo;
    // 0x8007F850: srl         $t6, $t9, 16
    ctx->r14 = S32(U32(ctx->r25) >> 16);
    // 0x8007F854: addu        $t7, $t6, $t3
    ctx->r15 = ADD32(ctx->r14, ctx->r11);
    // 0x8007F858: sb          $t7, 0x13($a0)
    MEM_B(0X13, ctx->r4) = ctx->r15;
L_8007F85C:
    // 0x8007F85C: jr          $ra
    // 0x8007F860: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8007F860: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void init_pulsating_light_data(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007F864: lhu         $t6, 0xC($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XC);
    // 0x8007F868: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x8007F86C: sh          $zero, 0x2($a0)
    MEM_H(0X2, ctx->r4) = 0;
    // 0x8007F870: sh          $zero, 0x4($a0)
    MEM_H(0X4, ctx->r4) = 0;
    // 0x8007F874: sh          $zero, 0x6($a0)
    MEM_H(0X6, ctx->r4) = 0;
    // 0x8007F878: blez        $v1, L_8007F8A8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8007F87C: sw          $t6, 0x8($a0)
        MEM_W(0X8, ctx->r4) = ctx->r14;
            goto L_8007F8A8;
    }
    // 0x8007F87C: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    // 0x8007F880: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x8007F884: addu        $a1, $t7, $a0
    ctx->r5 = ADD32(ctx->r15, ctx->r4);
    // 0x8007F888: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8007F88C:
    // 0x8007F88C: lhu         $t8, 0x6($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X6);
    // 0x8007F890: lhu         $t9, 0xE($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0XE);
    // 0x8007F894: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8007F898: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x8007F89C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8007F8A0: bne         $at, $zero, L_8007F88C
    if (ctx->r1 != 0) {
        // 0x8007F8A4: sh          $t0, 0x6($a0)
        MEM_H(0X6, ctx->r4) = ctx->r8;
            goto L_8007F88C;
    }
    // 0x8007F8A4: sh          $t0, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r8;
L_8007F8A8:
    // 0x8007F8A8: jr          $ra
    // 0x8007F8AC: nop

    return;
    // 0x8007F8AC: nop

;}
RECOMP_FUNC void update_pulsating_light_data(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007F8B0: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x8007F8B4: nop

    // 0x8007F8B8: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x8007F8BC: bne         $at, $zero, L_8007F9DC
    if (ctx->r1 != 0) {
        // 0x8007F8C0: nop
    
            goto L_8007F9DC;
    }
    // 0x8007F8C0: nop

    // 0x8007F8C4: lhu         $t7, 0x4($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X4);
    // 0x8007F8C8: lhu         $v1, 0x6($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X6);
    // 0x8007F8CC: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x8007F8D0: andi        $v0, $t8, 0xFFFF
    ctx->r2 = ctx->r24 & 0XFFFF;
    // 0x8007F8D4: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8007F8D8: bne         $at, $zero, L_8007F8F4
    if (ctx->r1 != 0) {
        // 0x8007F8DC: sh          $t8, 0x4($a0)
        MEM_H(0X4, ctx->r4) = ctx->r24;
            goto L_8007F8F4;
    }
    // 0x8007F8DC: sh          $t8, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r24;
L_8007F8E0:
    // 0x8007F8E0: subu        $t9, $v0, $v1
    ctx->r25 = SUB32(ctx->r2, ctx->r3);
    // 0x8007F8E4: andi        $v0, $t9, 0xFFFF
    ctx->r2 = ctx->r25 & 0XFFFF;
    // 0x8007F8E8: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8007F8EC: beq         $at, $zero, L_8007F8E0
    if (ctx->r1 == 0) {
        // 0x8007F8F0: sh          $t9, 0x4($a0)
        MEM_H(0X4, ctx->r4) = ctx->r25;
            goto L_8007F8E0;
    }
    // 0x8007F8F0: sh          $t9, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r25;
L_8007F8F4:
    // 0x8007F8F4: lhu         $v1, 0x2($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X2);
    // 0x8007F8F8: nop

    // 0x8007F8FC: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x8007F900: addu        $t1, $a0, $t0
    ctx->r9 = ADD32(ctx->r4, ctx->r8);
    // 0x8007F904: lhu         $a1, 0xE($t1)
    ctx->r5 = MEM_HU(ctx->r9, 0XE);
    // 0x8007F908: nop

    // 0x8007F90C: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8007F910: bne         $at, $zero, L_8007F960
    if (ctx->r1 != 0) {
        // 0x8007F914: nop
    
            goto L_8007F960;
    }
    // 0x8007F914: nop

L_8007F918:
    // 0x8007F918: lhu         $t4, 0x0($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0X0);
    // 0x8007F91C: addiu       $t3, $v1, 0x1
    ctx->r11 = ADD32(ctx->r3, 0X1);
    // 0x8007F920: andi        $v1, $t3, 0xFFFF
    ctx->r3 = ctx->r11 & 0XFFFF;
    // 0x8007F924: subu        $t2, $v0, $a1
    ctx->r10 = SUB32(ctx->r2, ctx->r5);
    // 0x8007F928: slt         $at, $v1, $t4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8007F92C: sh          $t2, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r10;
    // 0x8007F930: bne         $at, $zero, L_8007F940
    if (ctx->r1 != 0) {
        // 0x8007F934: sh          $t3, 0x2($a0)
        MEM_H(0X2, ctx->r4) = ctx->r11;
            goto L_8007F940;
    }
    // 0x8007F934: sh          $t3, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r11;
    // 0x8007F938: sh          $zero, 0x2($a0)
    MEM_H(0X2, ctx->r4) = 0;
    // 0x8007F93C: andi        $v1, $zero, 0xFFFF
    ctx->r3 = 0 & 0XFFFF;
L_8007F940:
    // 0x8007F940: sll         $t5, $v1, 2
    ctx->r13 = S32(ctx->r3 << 2);
    // 0x8007F944: addu        $t6, $a0, $t5
    ctx->r14 = ADD32(ctx->r4, ctx->r13);
    // 0x8007F948: lhu         $a1, 0xE($t6)
    ctx->r5 = MEM_HU(ctx->r14, 0XE);
    // 0x8007F94C: lhu         $v0, 0x4($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X4);
    // 0x8007F950: nop

    // 0x8007F954: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8007F958: beq         $at, $zero, L_8007F918
    if (ctx->r1 == 0) {
        // 0x8007F95C: nop
    
            goto L_8007F918;
    }
    // 0x8007F95C: nop

L_8007F960:
    // 0x8007F960: lhu         $t7, 0x0($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X0);
    // 0x8007F964: addiu       $a3, $v1, 0x1
    ctx->r7 = ADD32(ctx->r3, 0X1);
    // 0x8007F968: slt         $at, $a3, $t7
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8007F96C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8007F970: bne         $at, $zero, L_8007F97C
    if (ctx->r1 != 0) {
        // 0x8007F974: or          $a2, $a3, $zero
        ctx->r6 = ctx->r7 | 0;
            goto L_8007F97C;
    }
    // 0x8007F974: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x8007F978: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8007F97C:
    // 0x8007F97C: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x8007F980: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x8007F984: lhu         $t1, 0xC($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0XC);
    // 0x8007F988: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8007F98C: multu       $t1, $v0
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007F990: addu        $v1, $a0, $t8
    ctx->r3 = ADD32(ctx->r4, ctx->r24);
    // 0x8007F994: lhu         $t3, 0xE($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0XE);
    // 0x8007F998: lhu         $t5, 0xC($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0XC);
    // 0x8007F99C: mflo        $t2
    ctx->r10 = lo;
    // 0x8007F9A0: nop

    // 0x8007F9A4: nop

    // 0x8007F9A8: div         $zero, $t2, $t3
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r11))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r11)));
    // 0x8007F9AC: bne         $t3, $zero, L_8007F9B8
    if (ctx->r11 != 0) {
        // 0x8007F9B0: nop
    
            goto L_8007F9B8;
    }
    // 0x8007F9B0: nop

    // 0x8007F9B4: break       7
    do_break(2148006324);
L_8007F9B8:
    // 0x8007F9B8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007F9BC: bne         $t3, $at, L_8007F9D0
    if (ctx->r11 != ctx->r1) {
        // 0x8007F9C0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007F9D0;
    }
    // 0x8007F9C0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007F9C4: bne         $t2, $at, L_8007F9D0
    if (ctx->r10 != ctx->r1) {
        // 0x8007F9C8: nop
    
            goto L_8007F9D0;
    }
    // 0x8007F9C8: nop

    // 0x8007F9CC: break       6
    do_break(2148006348);
L_8007F9D0:
    // 0x8007F9D0: mflo        $t4
    ctx->r12 = lo;
    // 0x8007F9D4: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8007F9D8: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
L_8007F9DC:
    // 0x8007F9DC: jr          $ra
    // 0x8007F9E0: nop

    return;
    // 0x8007F9E0: nop

;}
RECOMP_FUNC void gfx_init_basic_xlu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007F9E4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8007F9E8: sltiu       $at, $a1, 0x2
    ctx->r1 = ctx->r5 < 0X2 ? 1 : 0;
    // 0x8007F9EC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8007F9F0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8007F9F4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8007F9F8: addiu       $v0, $v0, -0x6D8
    ctx->r2 = ADD32(ctx->r2, -0X6D8);
    // 0x8007F9FC: bne         $at, $zero, L_8007FA10
    if (ctx->r1 != 0) {
        // 0x8007FA00: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_8007FA10;
    }
    // 0x8007FA00: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x8007FA04: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8007FA08: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8007FA0C: addiu       $v0, $v0, -0x6A8
    ctx->r2 = ADD32(ctx->r2, -0X6A8);
L_8007FA10:
    // 0x8007FA10: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x8007FA14: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8007FA18: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x8007FA1C: sll         $t9, $v1, 4
    ctx->r25 = S32(ctx->r3 << 4);
    // 0x8007FA20: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007FA24: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8007FA28: addiu       $a2, $a1, 0x8
    ctx->r6 = ADD32(ctx->r5, 0X8);
    // 0x8007FA2C: addiu       $t2, $t2, -0x670
    ctx->r10 = ADD32(ctx->r10, -0X670);
    // 0x8007FA30: addu        $t1, $t9, $at
    ctx->r9 = ADD32(ctx->r25, ctx->r1);
    // 0x8007FA34: lui         $t8, 0x702
    ctx->r24 = S32(0X702 << 16);
    // 0x8007FA38: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8007FA3C: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x8007FA40: ori         $t8, $t8, 0x10
    ctx->r24 = ctx->r24 | 0X10;
    // 0x8007FA44: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8007FA48: sw          $t3, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r11;
    // 0x8007FA4C: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8007FA50: addiu       $a3, $a2, 0x8
    ctx->r7 = ADD32(ctx->r6, 0X8);
    // 0x8007FA54: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x8007FA58: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x8007FA5C: lw          $t5, 0x8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8);
    // 0x8007FA60: addiu       $t0, $a3, 0x8
    ctx->r8 = ADD32(ctx->r7, 0X8);
    // 0x8007FA64: lui         $t6, 0xFB00
    ctx->r14 = S32(0XFB00 << 16);
    // 0x8007FA68: sw          $t5, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r13;
    // 0x8007FA6C: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x8007FA70: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x8007FA74: addiu       $a0, $t0, 0x8
    ctx->r4 = ADD32(ctx->r8, 0X8);
    // 0x8007FA78: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x8007FA7C: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x8007FA80: jr          $ra
    // 0x8007FA84: sw          $a0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r4;
    return;
    // 0x8007FA84: sw          $a0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r4;
    // 0x8007FA88: nop

    // 0x8007FA8C: nop

;}
RECOMP_FUNC void screenimage_load(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FA90: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8007FA94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007FA98: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8007FA9C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007FAA0: jal         0x80076EE4
    // 0x8007FAA4: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    asset_table_load(rdram, ctx);
        goto after_0;
    // 0x8007FAA4: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_0:
    // 0x8007FAA8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8007FAAC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8007FAB0: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8007FAB4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007FAB8: beq         $a0, $t6, L_8007FAD0
    if (ctx->r4 == ctx->r14) {
        // 0x8007FABC: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8007FAD0;
    }
    // 0x8007FABC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8007FAC0:
    // 0x8007FAC0: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8007FAC4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8007FAC8: bne         $a0, $t7, L_8007FAC0
    if (ctx->r4 != ctx->r15) {
        // 0x8007FACC: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8007FAC0;
    }
    // 0x8007FACC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8007FAD0:
    // 0x8007FAD0: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8007FAD4: bne         $v1, $zero, L_8007FAEC
    if (ctx->r3 != 0) {
        // 0x8007FAD8: nop
    
            goto L_8007FAEC;
    }
    // 0x8007FAD8: nop

    // 0x8007FADC: jal         0x80071380
    // 0x8007FAE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mempool_free(rdram, ctx);
        goto after_1;
    // 0x8007FAE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8007FAE4: b           L_8007FB54
    // 0x8007FAE8: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
        goto L_8007FB54;
    // 0x8007FAE8: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
L_8007FAEC:
    // 0x8007FAEC: bltz        $t0, L_8007FAF8
    if (SIGNED(ctx->r8) < 0) {
        // 0x8007FAF0: slt         $at, $t0, $v1
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8007FAF8;
    }
    // 0x8007FAF0: slt         $at, $t0, $v1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8007FAF4: bne         $at, $zero, L_8007FB08
    if (ctx->r1 != 0) {
        // 0x8007FAF8: lui         $a0, 0x800F
        ctx->r4 = S32(0X800F << 16);
            goto L_8007FB08;
    }
L_8007FAF8:
    // 0x8007FAF8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8007FAFC: jal         0x800CA2B4
    // 0x8007FB00: addiu       $a0, $a0, -0x7DE0
    ctx->r4 = ADD32(ctx->r4, -0X7DE0);
    rmonPrintf_recomp(rdram, ctx);
        goto after_2;
    // 0x8007FB00: addiu       $a0, $a0, -0x7DE0
    ctx->r4 = ADD32(ctx->r4, -0X7DE0);
    after_2:
    // 0x8007FB04: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_8007FB08:
    // 0x8007FB08: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x8007FB0C: addu        $v0, $s0, $t8
    ctx->r2 = ADD32(ctx->r16, ctx->r24);
    // 0x8007FB10: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x8007FB14: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x8007FB18: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    // 0x8007FB1C: subu        $a0, $t9, $a2
    ctx->r4 = SUB32(ctx->r25, ctx->r6);
    // 0x8007FB20: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8007FB24: jal         0x80070EDC
    // 0x8007FB28: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    mempool_alloc_safe(rdram, ctx);
        goto after_3;
    // 0x8007FB28: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_3:
    // 0x8007FB2C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8007FB30: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8007FB34: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8007FB38: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8007FB3C: jal         0x80077190
    // 0x8007FB40: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    asset_load(rdram, ctx);
        goto after_4;
    // 0x8007FB40: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x8007FB44: jal         0x80071380
    // 0x8007FB48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mempool_free(rdram, ctx);
        goto after_5;
    // 0x8007FB48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8007FB4C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8007FB50: nop

L_8007FB54:
    // 0x8007FB54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007FB58: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007FB5C: jr          $ra
    // 0x8007FB60: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8007FB60: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void screenimage_draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FB64: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8007FB68: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8007FB6C: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x8007FB70: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x8007FB74: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x8007FB78: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x8007FB7C: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x8007FB80: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x8007FB84: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x8007FB88: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x8007FB8C: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x8007FB90: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007FB94: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8007FB98: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007FB9C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007FBA0: addiu       $t8, $t8, -0x640
    ctx->r24 = ADD32(ctx->r24, -0X640);
    // 0x8007FBA4: lui         $t7, 0x702
    ctx->r15 = S32(0X702 << 16);
    // 0x8007FBA8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007FBAC: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x8007FBB0: ori         $t7, $t7, 0x10
    ctx->r15 = ctx->r15 | 0X10;
    // 0x8007FBB4: lui         $s1, 0x708
    ctx->r17 = S32(0X708 << 16);
    // 0x8007FBB8: lui         $s4, 0x777
    ctx->r20 = S32(0X777 << 16);
    // 0x8007FBBC: lui         $s6, 0xF510
    ctx->r22 = S32(0XF510 << 16);
    // 0x8007FBC0: lui         $s7, 0x8
    ctx->r23 = S32(0X8 << 16);
    // 0x8007FBC4: lui         $ra, 0x4F
    ctx->r31 = S32(0X4F << 16);
    // 0x8007FBC8: addiu       $s0, $a1, 0x10
    ctx->r16 = ADD32(ctx->r5, 0X10);
    // 0x8007FBCC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8007FBD0: ori         $ra, $ra, 0xC014
    ctx->r31 = ctx->r31 | 0XC014;
    // 0x8007FBD4: ori         $s7, $s7, 0x200
    ctx->r23 = ctx->r23 | 0X200;
    // 0x8007FBD8: ori         $s6, $s6, 0xA000
    ctx->r22 = ctx->r22 | 0XA000;
    // 0x8007FBDC: ori         $s4, $s4, 0xF000
    ctx->r20 = ctx->r20 | 0XF000;
    // 0x8007FBE0: ori         $s1, $s1, 0x200
    ctx->r17 = ctx->r17 | 0X200;
    // 0x8007FBE4: lui         $s2, 0xE600
    ctx->r18 = S32(0XE600 << 16);
    // 0x8007FBE8: lui         $s3, 0xF300
    ctx->r19 = S32(0XF300 << 16);
    // 0x8007FBEC: lui         $s5, 0xE700
    ctx->r21 = S32(0XE700 << 16);
    // 0x8007FBF0: lui         $fp, 0xF200
    ctx->r30 = S32(0XF200 << 16);
    // 0x8007FBF4: lui         $t5, 0xF510
    ctx->r13 = S32(0XF510 << 16);
    // 0x8007FBF8: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x8007FBFC: lui         $t3, 0xFD10
    ctx->r11 = S32(0XFD10 << 16);
    // 0x8007FC00: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007FC04: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
L_8007FC08:
    // 0x8007FC08: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007FC0C: addu        $t7, $s0, $t4
    ctx->r15 = ADD32(ctx->r16, ctx->r12);
    // 0x8007FC10: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007FC14: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007FC18: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8007FC1C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8007FC20: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007FC24: addiu       $t2, $a3, 0x6
    ctx->r10 = ADD32(ctx->r7, 0X6);
    // 0x8007FC28: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007FC2C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007FC30: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
    // 0x8007FC34: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8007FC38: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007FC3C: lui         $at, 0xE450
    ctx->r1 = S32(0XE450 << 16);
    // 0x8007FC40: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007FC44: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007FC48: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007FC4C: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x8007FC50: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007FC54: addiu       $s0, $s0, 0xF00
    ctx->r16 = ADD32(ctx->r16, 0XF00);
    // 0x8007FC58: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007FC5C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007FC60: sw          $s4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r20;
    // 0x8007FC64: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x8007FC68: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007FC6C: nop

    // 0x8007FC70: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007FC74: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007FC78: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007FC7C: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x8007FC80: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007FC84: sll         $t7, $t2, 2
    ctx->r15 = S32(ctx->r10 << 2);
    // 0x8007FC88: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007FC8C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007FC90: sw          $s7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r23;
    // 0x8007FC94: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x8007FC98: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007FC9C: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8007FCA0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007FCA4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007FCA8: sw          $ra, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r31;
    // 0x8007FCAC: sw          $fp, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r30;
    // 0x8007FCB0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007FCB4: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8007FCB8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007FCBC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007FCC0: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x8007FCC4: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8007FCC8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8007FCCC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8007FCD0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007FCD4: lui         $t9, 0xB300
    ctx->r25 = S32(0XB300 << 16);
    // 0x8007FCD8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007FCDC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007FCE0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007FCE4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8007FCE8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007FCEC: lui         $t8, 0x1000
    ctx->r24 = S32(0X1000 << 16);
    // 0x8007FCF0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007FCF4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007FCF8: ori         $t8, $t8, 0x400
    ctx->r24 = ctx->r24 | 0X400;
    // 0x8007FCFC: lui         $t7, 0xB200
    ctx->r15 = S32(0XB200 << 16);
    // 0x8007FD00: addiu       $at, $zero, 0xF0
    ctx->r1 = ADD32(0, 0XF0);
    // 0x8007FD04: or          $a3, $t2, $zero
    ctx->r7 = ctx->r10 | 0;
    // 0x8007FD08: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007FD0C: bne         $t2, $at, L_8007FC08
    if (ctx->r10 != ctx->r1) {
        // 0x8007FD10: sw          $t8, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r24;
            goto L_8007FC08;
    }
    // 0x8007FD10: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8007FD14: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8007FD18: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x8007FD1C: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x8007FD20: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x8007FD24: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x8007FD28: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x8007FD2C: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x8007FD30: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x8007FD34: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x8007FD38: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x8007FD3C: jr          $ra
    // 0x8007FD40: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8007FD40: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8007FD44: nop

    // 0x8007FD48: nop

    // 0x8007FD4C: nop

;}
RECOMP_FUNC void load_menu_text(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FD50: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8007FD54: addiu       $t1, $t1, -0x5E4
    ctx->r9 = ADD32(ctx->r9, -0X5E4);
    // 0x8007FD58: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x8007FD5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007FD60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007FD64: bne         $v1, $zero, L_8007FD8C
    if (ctx->r3 != 0) {
        // 0x8007FD68: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_8007FD8C;
    }
    // 0x8007FD68: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8007FD6C: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x8007FD70: jal         0x80076EE4
    // 0x8007FD74: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    asset_table_load(rdram, ctx);
        goto after_0;
    // 0x8007FD74: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8007FD78: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8007FD7C: addiu       $t1, $t1, -0x5E4
    ctx->r9 = ADD32(ctx->r9, -0X5E4);
    // 0x8007FD80: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8007FD84: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
    // 0x8007FD88: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8007FD8C:
    // 0x8007FD8C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007FD90: beq         $a1, $at, L_8007FDC0
    if (ctx->r5 == ctx->r1) {
        // 0x8007FD94: lui         $t0, 0x800E
        ctx->r8 = S32(0X800E << 16);
            goto L_8007FDC0;
    }
    // 0x8007FD94: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8007FD98: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007FD9C: beq         $a1, $at, L_8007FDC8
    if (ctx->r5 == ctx->r1) {
        // 0x8007FDA0: addiu       $a2, $zero, 0x2
        ctx->r6 = ADD32(0, 0X2);
            goto L_8007FDC8;
    }
    // 0x8007FDA0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8007FDA4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8007FDA8: beq         $a1, $at, L_8007FDB8
    if (ctx->r5 == ctx->r1) {
        // 0x8007FDAC: nop
    
            goto L_8007FDB8;
    }
    // 0x8007FDAC: nop

    // 0x8007FDB0: b           L_8007FDC8
    // 0x8007FDB4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_8007FDC8;
    // 0x8007FDB4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8007FDB8:
    // 0x8007FDB8: b           L_8007FDC8
    // 0x8007FDBC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
        goto L_8007FDC8;
    // 0x8007FDBC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
L_8007FDC0:
    // 0x8007FDC0: b           L_8007FDC8
    // 0x8007FDC4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
        goto L_8007FDC8;
    // 0x8007FDC4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
L_8007FDC8:
    // 0x8007FDC8: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x8007FDCC: addu        $v0, $v1, $t6
    ctx->r2 = ADD32(ctx->r3, ctx->r14);
    // 0x8007FDD0: addiu       $t0, $t0, -0x5E0
    ctx->r8 = ADD32(ctx->r8, -0X5E0);
    // 0x8007FDD4: lw          $a3, 0x4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X4);
    // 0x8007FDD8: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x8007FDDC: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x8007FDE0: subu        $a3, $a3, $a2
    ctx->r7 = SUB32(ctx->r7, ctx->r6);
    // 0x8007FDE4: beq         $a1, $zero, L_800803CC
    if (ctx->r5 == 0) {
        // 0x8007FDE8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800803CC;
    }
    // 0x8007FDE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007FDEC: jal         0x80077190
    // 0x8007FDF0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    asset_load(rdram, ctx);
        goto after_1;
    // 0x8007FDF0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_1:
    // 0x8007FDF4: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8007FDF8: addiu       $t1, $t1, -0x5E4
    ctx->r9 = ADD32(ctx->r9, -0X5E4);
    // 0x8007FDFC: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x8007FE00: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8007FE04: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8007FE08: addiu       $t0, $t0, -0x5E0
    ctx->r8 = ADD32(ctx->r8, -0X5E0);
    // 0x8007FE0C: blez        $t8, L_8007FE60
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8007FE10: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8007FE60;
    }
    // 0x8007FE10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8007FE14: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8007FE18: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_8007FE1C:
    // 0x8007FE1C: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x8007FE20: nop

    // 0x8007FE24: addu        $v0, $a1, $v1
    ctx->r2 = ADD32(ctx->r5, ctx->r3);
    // 0x8007FE28: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8007FE2C: nop

    // 0x8007FE30: bne         $a3, $a0, L_8007FE40
    if (ctx->r7 != ctx->r4) {
        // 0x8007FE34: addu        $t9, $a0, $a1
        ctx->r25 = ADD32(ctx->r4, ctx->r5);
            goto L_8007FE40;
    }
    // 0x8007FE34: addu        $t9, $a0, $a1
    ctx->r25 = ADD32(ctx->r4, ctx->r5);
    // 0x8007FE38: b           L_8007FE44
    // 0x8007FE3C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
        goto L_8007FE44;
    // 0x8007FE3C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_8007FE40:
    // 0x8007FE40: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_8007FE44:
    // 0x8007FE44: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8007FE48: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8007FE4C: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8007FE50: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8007FE54: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8007FE58: bne         $at, $zero, L_8007FE1C
    if (ctx->r1 != 0) {
        // 0x8007FE5C: nop
    
            goto L_8007FE1C;
    }
    // 0x8007FE5C: nop

L_8007FE60:
    // 0x8007FE60: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x8007FE64: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007FE68: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8007FE6C: addiu       $a1, $a1, 0x6F90
    ctx->r5 = ADD32(ctx->r5, 0X6F90);
    // 0x8007FE70: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x8007FE74: lw          $t5, 0x4($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X4);
    // 0x8007FE78: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8007FE7C: sw          $t5, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r13;
    // 0x8007FE80: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x8007FE84: addiu       $v0, $v0, -0x44
    ctx->r2 = ADD32(ctx->r2, -0X44);
    // 0x8007FE88: sw          $t6, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r14;
    // 0x8007FE8C: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    // 0x8007FE90: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007FE94: sw          $t7, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r15;
    // 0x8007FE98: lw          $t8, 0x10($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X10);
    // 0x8007FE9C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8007FEA0: sw          $t8, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r24;
    // 0x8007FEA4: lw          $t9, 0x14($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X14);
    // 0x8007FEA8: addiu       $v1, $v1, 0x320
    ctx->r3 = ADD32(ctx->r3, 0X320);
    // 0x8007FEAC: sw          $t9, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r25;
    // 0x8007FEB0: lw          $t2, 0x18($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X18);
    // 0x8007FEB4: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8007FEB8: sw          $t2, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->r10;
    // 0x8007FEBC: lw          $t3, 0x18($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X18);
    // 0x8007FEC0: addiu       $a3, $a3, 0x116C
    ctx->r7 = ADD32(ctx->r7, 0X116C);
    // 0x8007FEC4: sw          $t3, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->r11;
    // 0x8007FEC8: lw          $t4, 0x1C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X1C);
    // 0x8007FECC: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8007FED0: sw          $t4, 0x6FA0($at)
    MEM_W(0X6FA0, ctx->r1) = ctx->r12;
    // 0x8007FED4: lw          $t5, 0x38($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X38);
    // 0x8007FED8: addiu       $t1, $t1, 0x126C
    ctx->r9 = ADD32(ctx->r9, 0X126C);
    // 0x8007FEDC: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8007FEE0: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x8007FEE4: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8007FEE8: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8007FEEC: lw          $t7, 0x40($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X40);
    // 0x8007FEF0: addiu       $a2, $a2, 0x13CC
    ctx->r6 = ADD32(ctx->r6, 0X13CC);
    // 0x8007FEF4: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
    // 0x8007FEF8: lw          $t8, 0x14($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14);
    // 0x8007FEFC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8007FF00: sw          $t8, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r24;
    // 0x8007FF04: lw          $t9, 0x74($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X74);
    // 0x8007FF08: addiu       $v0, $v0, -0x70
    ctx->r2 = ADD32(ctx->r2, -0X70);
    // 0x8007FF0C: sw          $t9, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->r25;
    // 0x8007FF10: lw          $t2, 0x78($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X78);
    // 0x8007FF14: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x8007FF18: sw          $t2, 0x54($a3)
    MEM_W(0X54, ctx->r7) = ctx->r10;
    // 0x8007FF1C: lw          $t3, 0x7C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X7C);
    // 0x8007FF20: nop

    // 0x8007FF24: sw          $t3, 0x114($t1)
    MEM_W(0X114, ctx->r9) = ctx->r11;
    // 0x8007FF28: lw          $t4, 0x7C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X7C);
    // 0x8007FF2C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8007FF30: sw          $t4, 0x134($t1)
    MEM_W(0X134, ctx->r9) = ctx->r12;
    // 0x8007FF34: lw          $t5, 0x80($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X80);
    // 0x8007FF38: nop

    // 0x8007FF3C: sw          $t5, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r13;
    // 0x8007FF40: lw          $t6, 0x80($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X80);
    // 0x8007FF44: nop

    // 0x8007FF48: sw          $t6, 0x34($a2)
    MEM_W(0X34, ctx->r6) = ctx->r14;
    // 0x8007FF4C: lw          $t7, 0x24($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X24);
    // 0x8007FF50: nop

    // 0x8007FF54: sw          $t7, 0x54($a2)
    MEM_W(0X54, ctx->r6) = ctx->r15;
    // 0x8007FF58: lw          $t8, 0x28($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X28);
    // 0x8007FF5C: nop

    // 0x8007FF60: sw          $t8, 0xB4($a2)
    MEM_W(0XB4, ctx->r6) = ctx->r24;
    // 0x8007FF64: lw          $t9, 0x88($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X88);
    // 0x8007FF68: nop

    // 0x8007FF6C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8007FF70: lw          $t3, 0x69EC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X69EC);
    // 0x8007FF74: nop

    // 0x8007FF78: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x8007FF7C: beq         $t5, $zero, L_8007FF90
    if (ctx->r13 == 0) {
        // 0x8007FF80: nop
    
            goto L_8007FF90;
    }
    // 0x8007FF80: nop

    // 0x8007FF84: lw          $t6, 0x2D8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2D8);
    // 0x8007FF88: b           L_8007FF9C
    // 0x8007FF8C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
        goto L_8007FF9C;
    // 0x8007FF8C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
L_8007FF90:
    // 0x8007FF90: lw          $t7, 0x2DC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X2DC);
    // 0x8007FF94: nop

    // 0x8007FF98: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
L_8007FF9C:
    // 0x8007FF9C: lw          $t8, 0x18($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X18);
    // 0x8007FFA0: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8007FFA4: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x8007FFA8: lw          $t9, 0x294($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X294);
    // 0x8007FFAC: addiu       $a2, $a2, 0x930
    ctx->r6 = ADD32(ctx->r6, 0X930);
    // 0x8007FFB0: sw          $t9, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r25;
    // 0x8007FFB4: lw          $t2, 0x44($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X44);
    // 0x8007FFB8: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8007FFBC: sw          $t2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r10;
    // 0x8007FFC0: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x8007FFC4: addiu       $a3, $a3, 0x64
    ctx->r7 = ADD32(ctx->r7, 0X64);
    // 0x8007FFC8: sw          $t3, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r11;
    // 0x8007FFCC: lw          $t4, 0x120($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X120);
    // 0x8007FFD0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8007FFD4: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x8007FFD8: lw          $t5, 0x124($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X124);
    // 0x8007FFDC: addiu       $v1, $v1, 0x7C
    ctx->r3 = ADD32(ctx->r3, 0X7C);
    // 0x8007FFE0: sw          $t5, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r13;
    // 0x8007FFE4: lw          $t6, 0x128($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X128);
    // 0x8007FFE8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8007FFEC: sw          $t6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r14;
    // 0x8007FFF0: lw          $t7, 0x168($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X168);
    // 0x8007FFF4: addiu       $a1, $a1, 0x94
    ctx->r5 = ADD32(ctx->r5, 0X94);
    // 0x8007FFF8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8007FFFC: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x80080000: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80080004: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
    // 0x80080008: lw          $t9, 0x154($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X154);
    // 0x8008000C: addiu       $t0, $t0, 0xAC
    ctx->r8 = ADD32(ctx->r8, 0XAC);
    // 0x80080010: sw          $t9, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r25;
    // 0x80080014: lw          $t2, 0x168($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X168);
    // 0x80080018: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008001C: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80080020: lw          $t3, 0x174($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X174);
    // 0x80080024: addiu       $v0, $v0, 0xC0
    ctx->r2 = ADD32(ctx->r2, 0XC0);
    // 0x80080028: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x8008002C: lw          $t4, 0x178($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X178);
    // 0x80080030: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80080034: sw          $t4, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r12;
    // 0x80080038: lw          $t5, 0x154($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X154);
    // 0x8008003C: addiu       $a2, $a2, 0x10C
    ctx->r6 = ADD32(ctx->r6, 0X10C);
    // 0x80080040: sw          $t5, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r13;
    // 0x80080044: lw          $t6, 0x168($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X168);
    // 0x80080048: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008004C: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80080050: lw          $t7, 0x17C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X17C);
    // 0x80080054: addiu       $v1, $v1, 0xDC
    ctx->r3 = ADD32(ctx->r3, 0XDC);
    // 0x80080058: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x8008005C: lw          $t8, 0x180($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X180);
    // 0x80080060: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80080064: sw          $t8, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r24;
    // 0x80080068: lw          $t9, 0x154($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X154);
    // 0x8008006C: addiu       $a3, $a3, 0x124
    ctx->r7 = ADD32(ctx->r7, 0X124);
    // 0x80080070: sw          $t9, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r25;
    // 0x80080074: lw          $t2, 0x168($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X168);
    // 0x80080078: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8008007C: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x80080080: lw          $t3, 0x184($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X184);
    // 0x80080084: addiu       $a1, $a1, 0xF4
    ctx->r5 = ADD32(ctx->r5, 0XF4);
    // 0x80080088: sw          $t3, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r11;
    // 0x8008008C: lw          $t4, 0x188($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X188);
    // 0x80080090: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80080094: sw          $t4, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r12;
    // 0x80080098: lw          $t5, 0x168($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X168);
    // 0x8008009C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800800A0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800800A4: lw          $t6, 0x18C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18C);
    // 0x800800A8: addiu       $t1, $t1, 0xF6C
    ctx->r9 = ADD32(ctx->r9, 0XF6C);
    // 0x800800AC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800800B0: lw          $t7, 0x190($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X190);
    // 0x800800B4: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800800B8: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    // 0x800800BC: lw          $t8, 0x154($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X154);
    // 0x800800C0: addiu       $t0, $t0, 0xF78
    ctx->r8 = ADD32(ctx->r8, 0XF78);
    // 0x800800C4: sw          $t8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r24;
    // 0x800800C8: lw          $t9, 0x168($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X168);
    // 0x800800CC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800800D0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800800D4: lw          $t2, 0x198($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X198);
    // 0x800800D8: addiu       $v0, $v0, 0x13C
    ctx->r2 = ADD32(ctx->r2, 0X13C);
    // 0x800800DC: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x800800E0: lw          $t3, 0x19C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X19C);
    // 0x800800E4: nop

    // 0x800800E8: sw          $t3, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r11;
    // 0x800800EC: lw          $t4, 0x188($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X188);
    // 0x800800F0: nop

    // 0x800800F4: sw          $t4, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r12;
    // 0x800800F8: lw          $t5, 0x168($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X168);
    // 0x800800FC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80080100: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x80080104: lw          $t6, 0x2E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2E0);
    // 0x80080108: addiu       $v1, $v1, 0x7F8
    ctx->r3 = ADD32(ctx->r3, 0X7F8);
    // 0x8008010C: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x80080110: lw          $t7, 0x5C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X5C);
    // 0x80080114: nop

    // 0x80080118: sw          $t7, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r15;
    // 0x8008011C: lw          $t8, 0x154($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X154);
    // 0x80080120: nop

    // 0x80080124: sw          $t8, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r24;
    // 0x80080128: lw          $t9, 0x264($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X264);
    // 0x8008012C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80080130: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80080134: lw          $t2, 0x268($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X268);
    // 0x80080138: addiu       $a1, $a1, 0x718
    ctx->r5 = ADD32(ctx->r5, 0X718);
    // 0x8008013C: sw          $t2, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r10;
    // 0x80080140: lw          $t3, 0x26C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X26C);
    // 0x80080144: nop

    // 0x80080148: sw          $t3, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r11;
    // 0x8008014C: lw          $t4, 0x188($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X188);
    // 0x80080150: nop

    // 0x80080154: sw          $t4, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r12;
    // 0x80080158: lw          $t5, 0x270($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X270);
    // 0x8008015C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80080160: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
    // 0x80080164: lw          $t6, 0x274($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X274);
    // 0x80080168: addiu       $a2, $a2, -0x2DC
    ctx->r6 = ADD32(ctx->r6, -0X2DC);
    // 0x8008016C: sw          $t6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r14;
    // 0x80080170: lw          $t7, 0x278($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X278);
    // 0x80080174: nop

    // 0x80080178: sw          $t7, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r15;
    // 0x8008017C: lw          $t8, 0x188($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X188);
    // 0x80080180: nop

    // 0x80080184: sw          $t8, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->r24;
    // 0x80080188: lw          $t9, 0x1A0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1A0);
    // 0x8008018C: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80080190: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80080194: lw          $t2, 0x1A4($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X1A4);
    // 0x80080198: addiu       $a3, $a3, 0xF58
    ctx->r7 = ADD32(ctx->r7, 0XF58);
    // 0x8008019C: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800801A0: lw          $t3, 0x1A8($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X1A8);
    // 0x800801A4: nop

    // 0x800801A8: sw          $t3, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r11;
    // 0x800801AC: lw          $t4, 0x1AC($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X1AC);
    // 0x800801B0: nop

    // 0x800801B4: sw          $t4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r12;
    // 0x800801B8: lw          $t5, 0x1B0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X1B0);
    // 0x800801BC: nop

    // 0x800801C0: sw          $t5, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r13;
    // 0x800801C4: lw          $t6, 0x1B4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1B4);
    // 0x800801C8: nop

    // 0x800801CC: sw          $t6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r14;
    // 0x800801D0: lw          $t7, 0x188($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X188);
    // 0x800801D4: nop

    // 0x800801D8: sw          $t7, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r15;
    // 0x800801DC: lw          $t8, 0x224($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X224);
    // 0x800801E0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800801E4: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800801E8: lw          $t9, 0x90($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X90);
    // 0x800801EC: nop

    // 0x800801F0: sw          $t9, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r25;
    // 0x800801F4: lw          $t2, 0x130($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X130);
    // 0x800801F8: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800801FC: sw          $t2, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r10;
    // 0x80080200: lw          $t3, 0x130($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X130);
    // 0x80080204: addiu       $a2, $a2, 0xF44
    ctx->r6 = ADD32(ctx->r6, 0XF44);
    // 0x80080208: sw          $t3, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->r11;
    // 0x8008020C: lw          $t4, 0x238($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X238);
    // 0x80080210: nop

    // 0x80080214: sw          $t4, 0x74($a1)
    MEM_W(0X74, ctx->r5) = ctx->r12;
    // 0x80080218: lw          $t5, 0x240($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X240);
    // 0x8008021C: nop

    // 0x80080220: sw          $t5, 0xB4($a1)
    MEM_W(0XB4, ctx->r5) = ctx->r13;
    // 0x80080224: lw          $t6, 0x130($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X130);
    // 0x80080228: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8008022C: sw          $t6, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r14;
    // 0x80080230: lw          $t7, 0x130($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X130);
    // 0x80080234: addiu       $a1, $a1, 0xF30
    ctx->r5 = ADD32(ctx->r5, 0XF30);
    // 0x80080238: sw          $t7, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r15;
    // 0x8008023C: lw          $t8, 0x238($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X238);
    // 0x80080240: nop

    // 0x80080244: sw          $t8, 0x74($v1)
    MEM_W(0X74, ctx->r3) = ctx->r24;
    // 0x80080248: lw          $t9, 0x23C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X23C);
    // 0x8008024C: nop

    // 0x80080250: sw          $t9, 0xB4($v1)
    MEM_W(0XB4, ctx->r3) = ctx->r25;
    // 0x80080254: lw          $t2, 0x240($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X240);
    // 0x80080258: nop

    // 0x8008025C: sw          $t2, 0xF4($v1)
    MEM_W(0XF4, ctx->r3) = ctx->r10;
    // 0x80080260: lw          $t3, 0x114($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X114);
    // 0x80080264: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80080268: sw          $t3, 0xF30($at)
    MEM_W(0XF30, ctx->r1) = ctx->r11;
    // 0x8008026C: lw          $t4, 0x110($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X110);
    // 0x80080270: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80080274: sw          $t4, 0xF44($at)
    MEM_W(0XF44, ctx->r1) = ctx->r12;
    // 0x80080278: lw          $t5, 0x10C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X10C);
    // 0x8008027C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80080280: sw          $t5, 0xF58($at)
    MEM_W(0XF58, ctx->r1) = ctx->r13;
    // 0x80080284: lw          $t6, 0x2E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2E0);
    // 0x80080288: sw          $zero, 0x10($t1)
    MEM_W(0X10, ctx->r9) = 0;
    // 0x8008028C: sw          $zero, 0x14($t1)
    MEM_W(0X14, ctx->r9) = 0;
    // 0x80080290: addiu       $v1, $v1, 0xF6C
    ctx->r3 = ADD32(ctx->r3, 0XF6C);
    // 0x80080294: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
L_80080298:
    // 0x80080298: lw          $t7, 0x2C4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X2C4);
    // 0x8008029C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800802A0: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x800802A4: lw          $t8, 0x2C4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X2C4);
    // 0x800802A8: sltu        $at, $v1, $t0
    ctx->r1 = ctx->r3 < ctx->r8 ? 1 : 0;
    // 0x800802AC: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x800802B0: lw          $t9, 0x2C4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X2C4);
    // 0x800802B4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800802B8: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
    // 0x800802BC: lw          $t2, 0x2C4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X2C4);
    // 0x800802C0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800802C4: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800802C8: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800802CC: bne         $at, $zero, L_80080298
    if (ctx->r1 != 0) {
        // 0x800802D0: sw          $t2, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r10;
            goto L_80080298;
    }
    // 0x800802D0: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x800802D4: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x800802D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800802DC: beq         $t3, $zero, L_800802FC
    if (ctx->r11 == 0) {
        // 0x800802E0: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_800802FC;
    }
    // 0x800802E0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800802E4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800802E8: addiu       $v1, $v1, 0xF6C
    ctx->r3 = ADD32(ctx->r3, 0XF6C);
L_800802EC:
    // 0x800802EC: lw          $t4, 0x4($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X4);
    // 0x800802F0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800802F4: bne         $t4, $zero, L_800802EC
    if (ctx->r12 != 0) {
        // 0x800802F8: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800802EC;
    }
    // 0x800802F8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_800802FC:
    // 0x800802FC: lw          $t5, 0x2E4($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X2E4);
    // 0x80080300: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x80080304: addu        $t7, $t1, $t6
    ctx->r15 = ADD32(ctx->r9, ctx->r14);
    // 0x80080308: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x8008030C: lw          $t8, 0x27C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X27C);
    // 0x80080310: addiu       $v0, $v0, 0xF84
    ctx->r2 = ADD32(ctx->r2, 0XF84);
    // 0x80080314: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80080318: lw          $t9, 0x280($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X280);
    // 0x8008031C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80080320: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80080324: lw          $t2, 0x284($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X284);
    // 0x80080328: addiu       $v1, $v1, 0xF94
    ctx->r3 = ADD32(ctx->r3, 0XF94);
    // 0x8008032C: sw          $t2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r10;
    // 0x80080330: lw          $t3, 0x288($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X288);
    // 0x80080334: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80080338: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x8008033C: lw          $t4, 0x2E8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X2E8);
    // 0x80080340: addiu       $a1, $a1, 0x558
    ctx->r5 = ADD32(ctx->r5, 0X558);
    // 0x80080344: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x80080348: lw          $t6, 0x2EC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2EC);
    // 0x8008034C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80080350: sw          $t6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r14;
    // 0x80080354: lw          $t5, 0x260($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X260);
    // 0x80080358: addiu       $v0, $a0, 0xC
    ctx->r2 = ADD32(ctx->r4, 0XC);
    // 0x8008035C: sw          $t5, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r13;
    // 0x80080360: lw          $t7, 0x260($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X260);
    // 0x80080364: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80080368: sw          $t7, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->r15;
    // 0x8008036C: lw          $t8, 0x298($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X298);
    // 0x80080370: addiu       $v1, $v1, 0x5B8
    ctx->r3 = ADD32(ctx->r3, 0X5B8);
    // 0x80080374: sw          $t8, 0x5AC($at)
    MEM_W(0X5AC, ctx->r1) = ctx->r24;
    // 0x80080378: lw          $t9, 0x29C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X29C);
    // 0x8008037C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80080380: sw          $t9, 0x5CC($at)
    MEM_W(0X5CC, ctx->r1) = ctx->r25;
    // 0x80080384: lw          $t2, 0x2A0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X2A0);
    // 0x80080388: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008038C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80080390: addiu       $a0, $a0, 0x6B8
    ctx->r4 = ADD32(ctx->r4, 0X6B8);
    // 0x80080394: sw          $t2, 0x5EC($at)
    MEM_W(0X5EC, ctx->r1) = ctx->r10;
L_80080398:
    // 0x80080398: lw          $t3, 0x298($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X298);
    // 0x8008039C: addiu       $v1, $v1, 0x80
    ctx->r3 = ADD32(ctx->r3, 0X80);
    // 0x800803A0: sw          $t3, -0x2C($v1)
    MEM_W(-0X2C, ctx->r3) = ctx->r11;
    // 0x800803A4: lw          $t4, 0x29C($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X29C);
    // 0x800803A8: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800803AC: sw          $t4, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->r12;
    // 0x800803B0: lw          $t6, 0x290($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X290);
    // 0x800803B4: nop

    // 0x800803B8: sw          $t6, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r14;
    // 0x800803BC: lw          $t5, 0x294($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X294);
    // 0x800803C0: bne         $v1, $a0, L_80080398
    if (ctx->r3 != ctx->r4) {
        // 0x800803C4: sw          $t5, 0x34($v1)
        MEM_W(0X34, ctx->r3) = ctx->r13;
            goto L_80080398;
    }
    // 0x800803C4: sw          $t5, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r13;
    // 0x800803C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800803CC:
    // 0x800803CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800803D0: jr          $ra
    // 0x800803D4: nop

    return;
    // 0x800803D4: nop

;}
RECOMP_FUNC void menu_button_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800803D8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800803DC: addiu       $v0, $v0, 0x232C
    ctx->r2 = ADD32(ctx->r2, 0X232C);
    // 0x800803E0: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800803E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800803E8: beq         $a0, $zero, L_80080404
    if (ctx->r4 == 0) {
        // 0x800803EC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80080404;
    }
    // 0x800803EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800803F0: jal         0x80071380
    // 0x800803F4: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x800803F4: nop

    after_0:
    // 0x800803F8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800803FC: addiu       $v0, $v0, 0x232C
    ctx->r2 = ADD32(ctx->r2, 0X232C);
    // 0x80080400: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_80080404:
    // 0x80080404: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80080408: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008040C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80080410: sw          $zero, 0x71EC($at)
    MEM_W(0X71EC, ctx->r1) = 0;
    // 0x80080414: addiu       $v1, $v1, 0x2324
    ctx->r3 = ADD32(ctx->r3, 0X2324);
    // 0x80080418: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8008041C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80080420: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80080424: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80080428: sw          $zero, 0x2338($at)
    MEM_W(0X2338, ctx->r1) = 0;
    // 0x8008042C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80080430: sw          $zero, 0x233C($at)
    MEM_W(0X233C, ctx->r1) = 0;
    // 0x80080434: jr          $ra
    // 0x80080438: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80080438: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8007FFEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008043C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80080440: addiu       $a2, $a2, 0x71EC
    ctx->r6 = ADD32(ctx->r6, 0X71EC);
    // 0x80080444: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80080448: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8008044C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80080450: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80080454: beq         $t6, $zero, L_80080464
    if (ctx->r14 == 0) {
        // 0x80080458: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80080464;
    }
    // 0x80080458: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008045C: jal         0x800803D8
    // 0x80080460: nop

    menu_button_free(rdram, ctx);
        goto after_0;
    // 0x80080460: nop

    after_0:
L_80080464:
    // 0x80080464: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x80080468: multu       $s0, $t1
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008046C: sll         $t5, $s0, 2
    ctx->r13 = S32(ctx->r16 << 2);
    // 0x80080470: addu        $t5, $t5, $s0
    ctx->r13 = ADD32(ctx->r13, ctx->r16);
    // 0x80080474: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80080478: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8008047C: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x80080480: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // 0x80080484: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80080488: sll         $t5, $t7, 1
    ctx->r13 = S32(ctx->r15 << 1);
    // 0x8008048C: sw          $v0, 0x2340($at)
    MEM_W(0X2340, ctx->r1) = ctx->r2;
    // 0x80080490: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80080494: sll         $t4, $s0, 5
    ctx->r12 = S32(ctx->r16 << 5);
    // 0x80080498: mflo        $v1
    ctx->r3 = lo;
    // 0x8008049C: sll         $t8, $v1, 4
    ctx->r24 = S32(ctx->r3 << 4);
    // 0x800804A0: addu        $t9, $t5, $t8
    ctx->r25 = ADD32(ctx->r13, ctx->r24);
    // 0x800804A4: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x800804A8: sw          $v0, 0x2344($at)
    MEM_W(0X2344, ctx->r1) = ctx->r2;
    // 0x800804AC: addu        $a0, $t6, $t4
    ctx->r4 = ADD32(ctx->r14, ctx->r12);
    // 0x800804B0: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x800804B4: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x800804B8: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x800804BC: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x800804C0: jal         0x80070EDC
    // 0x800804C4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x800804C4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_1:
    // 0x800804C8: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x800804CC: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800804D0: addiu       $a3, $a3, 0x232C
    ctx->r7 = ADD32(ctx->r7, 0X232C);
    // 0x800804D4: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x800804D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800804DC: addu        $t8, $v0, $v1
    ctx->r24 = ADD32(ctx->r2, ctx->r3);
    // 0x800804E0: sw          $t8, 0x2330($at)
    MEM_W(0X2330, ctx->r1) = ctx->r24;
    // 0x800804E4: lw          $t9, 0x4($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X4);
    // 0x800804E8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800804EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800804F0: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x800804F4: addiu       $a2, $a2, 0x71EC
    ctx->r6 = ADD32(ctx->r6, 0X71EC);
    // 0x800804F8: sw          $t6, 0x71EC($at)
    MEM_W(0X71EC, ctx->r1) = ctx->r14;
    // 0x800804FC: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80080500: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80080504: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80080508: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008050C: addu        $t8, $t7, $t4
    ctx->r24 = ADD32(ctx->r15, ctx->r12);
    // 0x80080510: addiu       $t0, $t0, 0x2324
    ctx->r8 = ADD32(ctx->r8, 0X2324);
    // 0x80080514: sw          $t8, 0x2324($at)
    MEM_W(0X2324, ctx->r1) = ctx->r24;
    // 0x80080518: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8008051C: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x80080520: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x80080524: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x80080528: sw          $t6, 0x2328($at)
    MEM_W(0X2328, ctx->r1) = ctx->r14;
    // 0x8008052C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80080530: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80080534: blez        $s0, L_80080858
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80080538: or          $t3, $zero, $zero
        ctx->r11 = 0 | 0;
            goto L_80080858;
    }
    // 0x80080538: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x8008053C: andi        $a0, $s0, 0x3
    ctx->r4 = ctx->r16 & 0X3;
    // 0x80080540: beq         $a0, $zero, L_800805F4
    if (ctx->r4 == 0) {
        // 0x80080544: or          $t4, $a0, $zero
        ctx->r12 = ctx->r4 | 0;
            goto L_800805F4;
    }
    // 0x80080544: or          $t4, $a0, $zero
    ctx->r12 = ctx->r4 | 0;
    // 0x80080548: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8008054C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80080550: sll         $v0, $zero, 5
    ctx->r2 = S32(0 << 5);
L_80080554:
    // 0x80080554: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x80080558: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x8008055C: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x80080560: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x80080564: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x80080568: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8008056C: lw          $t7, 0x4($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X4);
    // 0x80080570: addu        $t6, $t8, $v0
    ctx->r14 = ADD32(ctx->r24, ctx->r2);
    // 0x80080574: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x80080578: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x8008057C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80080580: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x80080584: sll         $a0, $a1, 4
    ctx->r4 = S32(ctx->r5 << 4);
    // 0x80080588: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x8008058C: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x80080590: sw          $t8, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r24;
    // 0x80080594: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80080598: lw          $t7, 0x4($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X4);
    // 0x8008059C: addu        $t6, $t8, $v0
    ctx->r14 = ADD32(ctx->r24, ctx->r2);
    // 0x800805A0: addu        $t9, $t7, $a0
    ctx->r25 = ADD32(ctx->r15, ctx->r4);
    // 0x800805A4: sw          $t9, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r25;
    // 0x800805A8: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800805AC: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800805B0: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800805B4: sw          $zero, 0x10($t8)
    MEM_W(0X10, ctx->r24) = 0;
    // 0x800805B8: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800805BC: addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
    // 0x800805C0: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x800805C4: sw          $zero, 0x14($t6)
    MEM_W(0X14, ctx->r14) = 0;
    // 0x800805C8: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800805CC: addiu       $v1, $v1, 0xC8
    ctx->r3 = ADD32(ctx->r3, 0XC8);
    // 0x800805D0: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800805D4: sw          $zero, 0x18($t8)
    MEM_W(0X18, ctx->r24) = 0;
    // 0x800805D8: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800805DC: addiu       $t2, $t2, 0x14
    ctx->r10 = ADD32(ctx->r10, 0X14);
    // 0x800805E0: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x800805E4: sw          $zero, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = 0;
    // 0x800805E8: bne         $t4, $t3, L_80080554
    if (ctx->r12 != ctx->r11) {
        // 0x800805EC: addiu       $v0, $v0, 0x20
        ctx->r2 = ADD32(ctx->r2, 0X20);
            goto L_80080554;
    }
    // 0x800805EC: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x800805F0: beq         $t3, $s0, L_80080854
    if (ctx->r11 == ctx->r16) {
        // 0x800805F4: sll         $v1, $t2, 2
        ctx->r3 = S32(ctx->r10 << 2);
            goto L_80080854;
    }
L_800805F4:
    // 0x800805F4: sll         $v1, $t2, 2
    ctx->r3 = S32(ctx->r10 << 2);
    // 0x800805F8: addu        $v1, $v1, $t2
    ctx->r3 = ADD32(ctx->r3, ctx->r10);
    // 0x800805FC: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80080600: sll         $v0, $t3, 5
    ctx->r2 = S32(ctx->r11 << 5);
    // 0x80080604: sll         $t4, $s0, 5
    ctx->r12 = S32(ctx->r16 << 5);
L_80080608:
    // 0x80080608: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x8008060C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80080610: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x80080614: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x80080618: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8008061C: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80080620: lw          $t7, 0x4($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X4);
    // 0x80080624: addu        $t6, $t8, $v0
    ctx->r14 = ADD32(ctx->r24, ctx->r2);
    // 0x80080628: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x8008062C: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x80080630: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80080634: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x80080638: sll         $a0, $a1, 4
    ctx->r4 = S32(ctx->r5 << 4);
    // 0x8008063C: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x80080640: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x80080644: sw          $t8, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r24;
    // 0x80080648: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8008064C: lw          $t7, 0x4($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X4);
    // 0x80080650: addu        $t6, $t8, $v0
    ctx->r14 = ADD32(ctx->r24, ctx->r2);
    // 0x80080654: addu        $t9, $t7, $a0
    ctx->r25 = ADD32(ctx->r15, ctx->r4);
    // 0x80080658: sw          $t9, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r25;
    // 0x8008065C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80080660: addiu       $v1, $v1, 0xC8
    ctx->r3 = ADD32(ctx->r3, 0XC8);
    // 0x80080664: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80080668: sw          $zero, 0x10($t8)
    MEM_W(0X10, ctx->r24) = 0;
    // 0x8008066C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80080670: addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
    // 0x80080674: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x80080678: sw          $zero, 0x14($t6)
    MEM_W(0X14, ctx->r14) = 0;
    // 0x8008067C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80080680: sll         $a0, $a1, 4
    ctx->r4 = S32(ctx->r5 << 4);
    // 0x80080684: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80080688: sw          $zero, 0x18($t8)
    MEM_W(0X18, ctx->r24) = 0;
    // 0x8008068C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80080690: addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
    // 0x80080694: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x80080698: sw          $zero, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = 0;
    // 0x8008069C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800806A0: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800806A4: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x800806A8: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800806AC: sw          $t8, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->r24;
    // 0x800806B0: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800806B4: lw          $t7, 0x4($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X4);
    // 0x800806B8: addu        $t6, $t8, $v0
    ctx->r14 = ADD32(ctx->r24, ctx->r2);
    // 0x800806BC: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x800806C0: sw          $t9, 0x24($t6)
    MEM_W(0X24, ctx->r14) = ctx->r25;
    // 0x800806C4: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800806C8: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x800806CC: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x800806D0: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x800806D4: sw          $t8, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->r24;
    // 0x800806D8: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800806DC: lw          $t7, 0x4($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X4);
    // 0x800806E0: addu        $t6, $t8, $v0
    ctx->r14 = ADD32(ctx->r24, ctx->r2);
    // 0x800806E4: addu        $t9, $t7, $a0
    ctx->r25 = ADD32(ctx->r15, ctx->r4);
    // 0x800806E8: sw          $t9, 0x2C($t6)
    MEM_W(0X2C, ctx->r14) = ctx->r25;
    // 0x800806EC: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800806F0: addiu       $v1, $v1, 0xC8
    ctx->r3 = ADD32(ctx->r3, 0XC8);
    // 0x800806F4: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800806F8: sw          $zero, 0x30($t8)
    MEM_W(0X30, ctx->r24) = 0;
    // 0x800806FC: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80080700: sll         $a0, $a1, 4
    ctx->r4 = S32(ctx->r5 << 4);
    // 0x80080704: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x80080708: sw          $zero, 0x34($t6)
    MEM_W(0X34, ctx->r14) = 0;
    // 0x8008070C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80080710: addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
    // 0x80080714: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80080718: sw          $zero, 0x38($t8)
    MEM_W(0X38, ctx->r24) = 0;
    // 0x8008071C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80080720: nop

    // 0x80080724: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x80080728: sw          $zero, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = 0;
    // 0x8008072C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80080730: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x80080734: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x80080738: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x8008073C: sw          $t8, 0x40($t6)
    MEM_W(0X40, ctx->r14) = ctx->r24;
    // 0x80080740: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80080744: lw          $t7, 0x4($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X4);
    // 0x80080748: addu        $t6, $t8, $v0
    ctx->r14 = ADD32(ctx->r24, ctx->r2);
    // 0x8008074C: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x80080750: sw          $t9, 0x44($t6)
    MEM_W(0X44, ctx->r14) = ctx->r25;
    // 0x80080754: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80080758: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x8008075C: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x80080760: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x80080764: sw          $t8, 0x48($t6)
    MEM_W(0X48, ctx->r14) = ctx->r24;
    // 0x80080768: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8008076C: lw          $t7, 0x4($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X4);
    // 0x80080770: addu        $t6, $t8, $v0
    ctx->r14 = ADD32(ctx->r24, ctx->r2);
    // 0x80080774: addu        $t9, $t7, $a0
    ctx->r25 = ADD32(ctx->r15, ctx->r4);
    // 0x80080778: sw          $t9, 0x4C($t6)
    MEM_W(0X4C, ctx->r14) = ctx->r25;
    // 0x8008077C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80080780: addiu       $v1, $v1, 0xC8
    ctx->r3 = ADD32(ctx->r3, 0XC8);
    // 0x80080784: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80080788: sw          $zero, 0x50($t8)
    MEM_W(0X50, ctx->r24) = 0;
    // 0x8008078C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80080790: sll         $a0, $a1, 4
    ctx->r4 = S32(ctx->r5 << 4);
    // 0x80080794: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x80080798: sw          $zero, 0x54($t6)
    MEM_W(0X54, ctx->r14) = 0;
    // 0x8008079C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800807A0: addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
    // 0x800807A4: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800807A8: sw          $zero, 0x58($t8)
    MEM_W(0X58, ctx->r24) = 0;
    // 0x800807AC: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800807B0: nop

    // 0x800807B4: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x800807B8: sw          $zero, 0x5C($t6)
    MEM_W(0X5C, ctx->r14) = 0;
    // 0x800807BC: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800807C0: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800807C4: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x800807C8: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800807CC: sw          $t8, 0x60($t6)
    MEM_W(0X60, ctx->r14) = ctx->r24;
    // 0x800807D0: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800807D4: lw          $t7, 0x4($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X4);
    // 0x800807D8: addu        $t6, $t8, $v0
    ctx->r14 = ADD32(ctx->r24, ctx->r2);
    // 0x800807DC: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x800807E0: sw          $t9, 0x64($t6)
    MEM_W(0X64, ctx->r14) = ctx->r25;
    // 0x800807E4: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800807E8: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x800807EC: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x800807F0: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x800807F4: sw          $t8, 0x68($t6)
    MEM_W(0X68, ctx->r14) = ctx->r24;
    // 0x800807F8: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800807FC: lw          $t7, 0x4($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X4);
    // 0x80080800: addu        $t6, $t8, $v0
    ctx->r14 = ADD32(ctx->r24, ctx->r2);
    // 0x80080804: addu        $t9, $t7, $a0
    ctx->r25 = ADD32(ctx->r15, ctx->r4);
    // 0x80080808: sw          $t9, 0x6C($t6)
    MEM_W(0X6C, ctx->r14) = ctx->r25;
    // 0x8008080C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80080810: addiu       $v1, $v1, 0xC8
    ctx->r3 = ADD32(ctx->r3, 0XC8);
    // 0x80080814: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80080818: sw          $zero, 0x70($t8)
    MEM_W(0X70, ctx->r24) = 0;
    // 0x8008081C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80080820: nop

    // 0x80080824: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x80080828: sw          $zero, 0x74($t6)
    MEM_W(0X74, ctx->r14) = 0;
    // 0x8008082C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80080830: nop

    // 0x80080834: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80080838: sw          $zero, 0x78($t8)
    MEM_W(0X78, ctx->r24) = 0;
    // 0x8008083C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80080840: nop

    // 0x80080844: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x80080848: addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, 0X80);
    // 0x8008084C: bne         $v0, $t4, L_80080608
    if (ctx->r2 != ctx->r12) {
        // 0x80080850: sw          $zero, 0x7C($t6)
        MEM_W(0X7C, ctx->r14) = 0;
            goto L_80080608;
    }
    // 0x80080850: sw          $zero, 0x7C($t6)
    MEM_W(0X7C, ctx->r14) = 0;
L_80080854:
    // 0x80080854: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
L_80080858:
    // 0x80080858: blez        $s0, L_80080944
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8008085C: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80080944;
    }
    // 0x8008085C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80080860: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80080864: addiu       $a2, $a2, 0x2334
    ctx->r6 = ADD32(ctx->r6, 0X2334);
    // 0x80080868: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8008086C: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
L_80080870:
    // 0x80080870: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80080874: addiu       $a0, $a0, 0x2250
    ctx->r4 = ADD32(ctx->r4, 0X2250);
    // 0x80080878: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8008087C:
    // 0x8008087C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80080880: addiu       $v0, $v0, 0x232C
    ctx->r2 = ADD32(ctx->r2, 0X232C);
L_80080884:
    // 0x80080884: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80080888: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8008088C: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x80080890: sb          $a1, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r5;
    // 0x80080894: lw          $t6, -0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X4);
    // 0x80080898: lbu         $t9, 0x0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X0);
    // 0x8008089C: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x800808A0: sb          $t9, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r25;
    // 0x800808A4: lw          $t6, -0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X4);
    // 0x800808A8: lbu         $t8, 0x1($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X1);
    // 0x800808AC: addu        $t9, $t6, $v1
    ctx->r25 = ADD32(ctx->r14, ctx->r3);
    // 0x800808B0: sb          $t8, 0x2($t9)
    MEM_B(0X2, ctx->r25) = ctx->r24;
    // 0x800808B4: lw          $t6, -0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X4);
    // 0x800808B8: lbu         $t7, 0x2($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X2);
    // 0x800808BC: addu        $t8, $t6, $v1
    ctx->r24 = ADD32(ctx->r14, ctx->r3);
    // 0x800808C0: sb          $t7, 0x3($t8)
    MEM_B(0X3, ctx->r24) = ctx->r15;
    // 0x800808C4: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x800808C8: nop

    // 0x800808CC: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x800808D0: sh          $zero, 0x4($t6)
    MEM_H(0X4, ctx->r14) = 0;
    // 0x800808D4: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x800808D8: nop

    // 0x800808DC: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800808E0: sh          $zero, 0x6($t8)
    MEM_H(0X6, ctx->r24) = 0;
    // 0x800808E4: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x800808E8: nop

    // 0x800808EC: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x800808F0: sh          $zero, 0x8($t6)
    MEM_H(0X8, ctx->r14) = 0;
    // 0x800808F4: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x800808F8: nop

    // 0x800808FC: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x80080900: sh          $zero, 0xA($t8)
    MEM_H(0XA, ctx->r24) = 0;
    // 0x80080904: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x80080908: nop

    // 0x8008090C: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x80080910: sh          $zero, 0xC($t6)
    MEM_H(0XC, ctx->r14) = 0;
    // 0x80080914: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x80080918: nop

    // 0x8008091C: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x80080920: bne         $v0, $a2, L_80080884
    if (ctx->r2 != ctx->r6) {
        // 0x80080924: sh          $zero, 0xE($t8)
        MEM_H(0XE, ctx->r24) = 0;
            goto L_80080884;
    }
    // 0x80080924: sh          $zero, 0xE($t8)
    MEM_H(0XE, ctx->r24) = 0;
    // 0x80080928: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8008092C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80080930: bne         $a3, $t1, L_8008087C
    if (ctx->r7 != ctx->r9) {
        // 0x80080934: addiu       $a0, $a0, 0x3
        ctx->r4 = ADD32(ctx->r4, 0X3);
            goto L_8008087C;
    }
    // 0x80080934: addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
    // 0x80080938: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x8008093C: bne         $t3, $s0, L_80080870
    if (ctx->r11 != ctx->r16) {
        // 0x80080940: nop
    
            goto L_80080870;
    }
    // 0x80080940: nop

L_80080944:
    // 0x80080944: sw          $zero, 0x2334($at)
    MEM_W(0X2334, ctx->r1) = 0;
    // 0x80080948: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008094C: sw          $zero, 0x2338($at)
    MEM_W(0X2338, ctx->r1) = 0;
    // 0x80080950: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80080954: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80080958: sw          $s0, 0x233C($at)
    MEM_W(0X233C, ctx->r1) = ctx->r16;
    // 0x8008095C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80080960: jr          $ra
    // 0x80080964: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80080964: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void menu_button_uvs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080968: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8008096C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80080970: nop

    // 0x80080974: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80080978: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8008097C: nop

    // 0x80080980: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80080984: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80080988: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8008098C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80080990: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80080994: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80080998: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8008099C: mul.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800809A0: sw          $t7, 0x2340($at)
    MEM_W(0X2340, ctx->r1) = ctx->r15;
    // 0x800809A4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800809A8: nop

    // 0x800809AC: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800809B0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800809B4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800809B8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800809BC: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800809C0: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800809C4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800809C8: jr          $ra
    // 0x800809CC: sw          $t9, 0x2344($at)
    MEM_W(0X2344, ctx->r1) = ctx->r25;
    return;
    // 0x800809CC: sw          $t9, 0x2344($at)
    MEM_W(0X2344, ctx->r1) = ctx->r25;
;}
RECOMP_FUNC void func_80080580(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800809D0: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x800809D4: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800809D8: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x800809DC: addiu       $fp, $fp, 0x2338
    ctx->r30 = ADD32(ctx->r30, 0X2338);
    // 0x800809E0: lw          $t7, 0x0($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X0);
    // 0x800809E4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800809E8: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x800809EC: lw          $t6, 0x71EC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X71EC);
    // 0x800809F0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800809F4: lw          $t7, 0x2334($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2334);
    // 0x800809F8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800809FC: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80080A00: lw          $s3, 0xE0($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XE0);
    // 0x80080A04: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80080A08: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80080A0C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80080A10: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80080A14: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80080A18: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80080A1C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80080A20: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80080A24: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80080A28: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x80080A2C: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x80080A30: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80080A34: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x80080A38: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x80080A3C: beq         $s3, $zero, L_80080C58
    if (ctx->r19 == 0) {
        // 0x80080A40: sw          $s3, 0x10($t8)
        MEM_W(0X10, ctx->r24) = ctx->r19;
            goto L_80080C58;
    }
    // 0x80080A40: sw          $s3, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r19;
    // 0x80080A44: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80080A48: lw          $t3, 0xD4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XD4);
    // 0x80080A4C: lw          $a1, 0x2340($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X2340);
    // 0x80080A50: subu        $t9, $a3, $t3
    ctx->r25 = SUB32(ctx->r7, ctx->r11);
    // 0x80080A54: multu       $a1, $t3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80080A58: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80080A5C: lw          $t4, 0xD8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XD8);
    // 0x80080A60: lw          $a2, 0x2344($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X2344);
    // 0x80080A64: lw          $t5, 0xD0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XD0);
    // 0x80080A68: sw          $zero, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = 0;
    // 0x80080A6C: sw          $zero, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = 0;
    // 0x80080A70: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80080A74: addiu       $v0, $v0, 0x2270
    ctx->r2 = ADD32(ctx->r2, 0X2270);
    // 0x80080A78: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x80080A7C: addiu       $a0, $sp, 0xB0
    ctx->r4 = ADD32(ctx->r29, 0XB0);
    // 0x80080A80: mflo        $t7
    ctx->r15 = lo;
    // 0x80080A84: sw          $t7, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r15;
    // 0x80080A88: nop

    // 0x80080A8C: multu       $t9, $a1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80080A90: subu        $t9, $t5, $t4
    ctx->r25 = SUB32(ctx->r13, ctx->r12);
    // 0x80080A94: mflo        $t6
    ctx->r14 = lo;
    // 0x80080A98: sw          $t6, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r14;
    // 0x80080A9C: nop

    // 0x80080AA0: multu       $a1, $a3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80080AA4: addiu       $a1, $sp, 0xA0
    ctx->r5 = ADD32(ctx->r29, 0XA0);
    // 0x80080AA8: mflo        $t8
    ctx->r24 = lo;
    // 0x80080AAC: sw          $t8, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r24;
    // 0x80080AB0: nop

    // 0x80080AB4: multu       $a2, $t4
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80080AB8: mflo        $t7
    ctx->r15 = lo;
    // 0x80080ABC: sw          $t7, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r15;
    // 0x80080AC0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80080AC4: multu       $t9, $a2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80080AC8: lw          $t9, 0x0($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X0);
    // 0x80080ACC: lw          $t7, 0x71EC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X71EC);
    // 0x80080AD0: mflo        $t6
    ctx->r14 = lo;
    // 0x80080AD4: sw          $t6, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r14;
    // 0x80080AD8: sll         $t6, $t9, 5
    ctx->r14 = S32(ctx->r25 << 5);
    // 0x80080ADC: multu       $a2, $t5
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80080AE0: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80080AE4: lw          $t9, 0x2334($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X2334);
    // 0x80080AE8: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x80080AEC: mflo        $t8
    ctx->r24 = lo;
    // 0x80080AF0: sw          $t8, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r24;
    // 0x80080AF4: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x80080AF8: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x80080AFC: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x80080B00: lw          $v1, 0x8($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X8);
    // 0x80080B04: nop

L_80080B08:
    // 0x80080B08: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x80080B0C: addiu       $ra, $ra, 0x2
    ctx->r31 = ADD32(ctx->r31, 0X2);
    // 0x80080B10: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80080B14: addu        $t7, $a0, $t8
    ctx->r15 = ADD32(ctx->r4, ctx->r24);
    // 0x80080B18: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x80080B1C: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x80080B20: sh          $t6, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r14;
    // 0x80080B24: lbu         $t9, -0xB($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0XB);
    // 0x80080B28: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x80080B2C: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80080B30: addu        $t7, $a1, $t8
    ctx->r15 = ADD32(ctx->r5, ctx->r24);
    // 0x80080B34: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x80080B38: nop

    // 0x80080B3C: sh          $t6, -0x1A($v1)
    MEM_H(-0X1A, ctx->r3) = ctx->r14;
    // 0x80080B40: lbu         $t9, -0xA($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0XA);
    // 0x80080B44: nop

    // 0x80080B48: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80080B4C: addu        $t7, $a0, $t8
    ctx->r15 = ADD32(ctx->r4, ctx->r24);
    // 0x80080B50: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x80080B54: nop

    // 0x80080B58: sh          $t6, -0x18($v1)
    MEM_H(-0X18, ctx->r3) = ctx->r14;
    // 0x80080B5C: lbu         $t9, -0x9($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X9);
    // 0x80080B60: nop

    // 0x80080B64: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80080B68: addu        $t7, $a1, $t8
    ctx->r15 = ADD32(ctx->r5, ctx->r24);
    // 0x80080B6C: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x80080B70: nop

    // 0x80080B74: sh          $t6, -0x16($v1)
    MEM_H(-0X16, ctx->r3) = ctx->r14;
    // 0x80080B78: lbu         $t9, -0x8($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X8);
    // 0x80080B7C: nop

    // 0x80080B80: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80080B84: addu        $t7, $a0, $t8
    ctx->r15 = ADD32(ctx->r4, ctx->r24);
    // 0x80080B88: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x80080B8C: nop

    // 0x80080B90: sh          $t6, -0x14($v1)
    MEM_H(-0X14, ctx->r3) = ctx->r14;
    // 0x80080B94: lbu         $t9, -0x7($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X7);
    // 0x80080B98: nop

    // 0x80080B9C: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80080BA0: addu        $t7, $a1, $t8
    ctx->r15 = ADD32(ctx->r5, ctx->r24);
    // 0x80080BA4: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x80080BA8: nop

    // 0x80080BAC: sh          $t6, -0x12($v1)
    MEM_H(-0X12, ctx->r3) = ctx->r14;
    // 0x80080BB0: lbu         $t9, -0x6($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X6);
    // 0x80080BB4: nop

    // 0x80080BB8: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80080BBC: addu        $t7, $a0, $t8
    ctx->r15 = ADD32(ctx->r4, ctx->r24);
    // 0x80080BC0: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x80080BC4: nop

    // 0x80080BC8: sh          $t6, -0xC($v1)
    MEM_H(-0XC, ctx->r3) = ctx->r14;
    // 0x80080BCC: lbu         $t9, -0x5($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X5);
    // 0x80080BD0: nop

    // 0x80080BD4: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80080BD8: addu        $t7, $a1, $t8
    ctx->r15 = ADD32(ctx->r5, ctx->r24);
    // 0x80080BDC: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x80080BE0: nop

    // 0x80080BE4: sh          $t6, -0xA($v1)
    MEM_H(-0XA, ctx->r3) = ctx->r14;
    // 0x80080BE8: lbu         $t9, -0x4($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X4);
    // 0x80080BEC: nop

    // 0x80080BF0: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80080BF4: addu        $t7, $a0, $t8
    ctx->r15 = ADD32(ctx->r4, ctx->r24);
    // 0x80080BF8: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x80080BFC: nop

    // 0x80080C00: sh          $t6, -0x8($v1)
    MEM_H(-0X8, ctx->r3) = ctx->r14;
    // 0x80080C04: lbu         $t9, -0x3($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X3);
    // 0x80080C08: nop

    // 0x80080C0C: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80080C10: addu        $t7, $a1, $t8
    ctx->r15 = ADD32(ctx->r5, ctx->r24);
    // 0x80080C14: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x80080C18: nop

    // 0x80080C1C: sh          $t6, -0x6($v1)
    MEM_H(-0X6, ctx->r3) = ctx->r14;
    // 0x80080C20: lbu         $t9, -0x2($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X2);
    // 0x80080C24: nop

    // 0x80080C28: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80080C2C: addu        $t7, $a0, $t8
    ctx->r15 = ADD32(ctx->r4, ctx->r24);
    // 0x80080C30: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x80080C34: nop

    // 0x80080C38: sh          $t6, -0x4($v1)
    MEM_H(-0X4, ctx->r3) = ctx->r14;
    // 0x80080C3C: lbu         $t9, -0x1($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X1);
    // 0x80080C40: nop

    // 0x80080C44: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80080C48: addu        $t7, $a1, $t8
    ctx->r15 = ADD32(ctx->r5, ctx->r24);
    // 0x80080C4C: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x80080C50: bne         $ra, $a2, L_80080B08
    if (ctx->r31 != ctx->r6) {
        // 0x80080C54: sh          $t6, -0x2($v1)
        MEM_H(-0X2, ctx->r3) = ctx->r14;
            goto L_80080B08;
    }
    // 0x80080C54: sh          $t6, -0x2($v1)
    MEM_H(-0X2, ctx->r3) = ctx->r14;
L_80080C58:
    // 0x80080C58: lw          $a0, 0xDC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XDC);
    // 0x80080C5C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80080C60: sra         $s3, $a0, 24
    ctx->r19 = S32(SIGNED(ctx->r4) >> 24);
    // 0x80080C64: andi        $t9, $s3, 0xFF
    ctx->r25 = ctx->r19 & 0XFF;
    // 0x80080C68: or          $s3, $t9, $zero
    ctx->r19 = ctx->r25 | 0;
    // 0x80080C6C: sra         $s4, $a0, 16
    ctx->r20 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80080C70: lw          $t9, 0x0($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X0);
    // 0x80080C74: andi        $t8, $s4, 0xFF
    ctx->r24 = ctx->r20 & 0XFF;
    // 0x80080C78: or          $s4, $t8, $zero
    ctx->r20 = ctx->r24 | 0;
    // 0x80080C7C: sra         $s5, $a0, 8
    ctx->r21 = S32(SIGNED(ctx->r4) >> 8);
    // 0x80080C80: sll         $t8, $t9, 5
    ctx->r24 = S32(ctx->r25 << 5);
    // 0x80080C84: lw          $t6, 0x71EC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X71EC);
    // 0x80080C88: andi        $t7, $s5, 0xFF
    ctx->r15 = ctx->r21 & 0XFF;
    // 0x80080C8C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80080C90: lw          $t9, 0x2334($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X2334);
    // 0x80080C94: or          $s5, $t7, $zero
    ctx->r21 = ctx->r15 | 0;
    // 0x80080C98: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x80080C9C: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80080CA0: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x80080CA4: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80080CA8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80080CAC: lw          $t3, 0xD4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XD4);
    // 0x80080CB0: lw          $t4, 0xD8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XD8);
    // 0x80080CB4: lw          $t5, 0xD0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XD0);
    // 0x80080CB8: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x80080CBC: addiu       $v1, $v1, 0x22AC
    ctx->r3 = ADD32(ctx->r3, 0X22AC);
    // 0x80080CC0: addiu       $t2, $t2, 0x22FC
    ctx->r10 = ADD32(ctx->r10, 0X22FC);
    // 0x80080CC4: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x80080CC8: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x80080CCC: andi        $s6, $a0, 0xFF
    ctx->r22 = ctx->r4 & 0XFF;
L_80080CD0:
    // 0x80080CD0: lh          $t9, 0x0($t2)
    ctx->r25 = MEM_H(ctx->r10, 0X0);
    // 0x80080CD4: lh          $t6, 0x2($t2)
    ctx->r14 = MEM_H(ctx->r10, 0X2);
    // 0x80080CD8: multu       $t9, $s3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80080CDC: lh          $t9, 0x4($t2)
    ctx->r25 = MEM_H(ctx->r10, 0X4);
    // 0x80080CE0: addiu       $ra, $ra, 0x1
    ctx->r31 = ADD32(ctx->r31, 0X1);
    // 0x80080CE4: slti        $at, $ra, 0x5
    ctx->r1 = SIGNED(ctx->r31) < 0X5 ? 1 : 0;
    // 0x80080CE8: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
    // 0x80080CEC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80080CF0: mflo        $a1
    ctx->r5 = lo;
    // 0x80080CF4: sra         $t7, $a1, 8
    ctx->r15 = S32(SIGNED(ctx->r5) >> 8);
    // 0x80080CF8: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x80080CFC: multu       $t6, $s4
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80080D00: lh          $t6, -0x2($t2)
    ctx->r14 = MEM_H(ctx->r10, -0X2);
    // 0x80080D04: mflo        $a2
    ctx->r6 = lo;
    // 0x80080D08: sra         $t8, $a2, 8
    ctx->r24 = S32(SIGNED(ctx->r6) >> 8);
    // 0x80080D0C: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x80080D10: multu       $t9, $s5
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80080D14: mflo        $a3
    ctx->r7 = lo;
    // 0x80080D18: sra         $t7, $a3, 8
    ctx->r15 = S32(SIGNED(ctx->r7) >> 8);
    // 0x80080D1C: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x80080D20: multu       $t6, $s6
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80080D24: mflo        $t0
    ctx->r8 = lo;
    // 0x80080D28: sra         $t8, $t0, 8
    ctx->r24 = S32(SIGNED(ctx->r8) >> 8);
    // 0x80080D2C: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
L_80080D30:
    // 0x80080D30: sh          $s1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r17;
    // 0x80080D34: lb          $t7, 0x0($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X0);
    // 0x80080D38: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x80080D3C: multu       $t7, $s0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80080D40: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80080D44: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80080D48: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x80080D4C: mflo        $t6
    ctx->r14 = lo;
    // 0x80080D50: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x80080D54: sh          $t8, -0xA($v0)
    MEM_H(-0XA, ctx->r2) = ctx->r24;
    // 0x80080D58: lb          $t9, -0x3($v1)
    ctx->r25 = MEM_B(ctx->r3, -0X3);
    // 0x80080D5C: lh          $t7, -0xA($v0)
    ctx->r15 = MEM_H(ctx->r2, -0XA);
    // 0x80080D60: multu       $t9, $t3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80080D64: sh          $s2, -0x8($v0)
    MEM_H(-0X8, ctx->r2) = ctx->r18;
    // 0x80080D68: lh          $t9, -0x8($v0)
    ctx->r25 = MEM_H(ctx->r2, -0X8);
    // 0x80080D6C: mflo        $t6
    ctx->r14 = lo;
    // 0x80080D70: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x80080D74: sh          $t8, -0xA($v0)
    MEM_H(-0XA, ctx->r2) = ctx->r24;
    // 0x80080D78: lb          $t7, -0x2($v1)
    ctx->r15 = MEM_B(ctx->r3, -0X2);
    // 0x80080D7C: nop

    // 0x80080D80: multu       $t7, $t5
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80080D84: mflo        $t6
    ctx->r14 = lo;
    // 0x80080D88: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x80080D8C: sh          $t8, -0x8($v0)
    MEM_H(-0X8, ctx->r2) = ctx->r24;
    // 0x80080D90: lb          $t9, -0x1($v1)
    ctx->r25 = MEM_B(ctx->r3, -0X1);
    // 0x80080D94: lh          $t7, -0x8($v0)
    ctx->r15 = MEM_H(ctx->r2, -0X8);
    // 0x80080D98: multu       $t9, $t4
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80080D9C: sh          $zero, -0x6($v0)
    MEM_H(-0X6, ctx->r2) = 0;
    // 0x80080DA0: sb          $a1, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = ctx->r5;
    // 0x80080DA4: sb          $a2, -0x3($v0)
    MEM_B(-0X3, ctx->r2) = ctx->r6;
    // 0x80080DA8: sb          $a3, -0x2($v0)
    MEM_B(-0X2, ctx->r2) = ctx->r7;
    // 0x80080DAC: sb          $t0, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r8;
    // 0x80080DB0: mflo        $t6
    ctx->r14 = lo;
    // 0x80080DB4: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x80080DB8: bne         $a0, $t1, L_80080D30
    if (ctx->r4 != ctx->r9) {
        // 0x80080DBC: sh          $t8, -0x8($v0)
        MEM_H(-0X8, ctx->r2) = ctx->r24;
            goto L_80080D30;
    }
    // 0x80080DBC: sh          $t8, -0x8($v0)
    MEM_H(-0X8, ctx->r2) = ctx->r24;
    // 0x80080DC0: bne         $at, $zero, L_80080CD0
    if (ctx->r1 != 0) {
        // 0x80080DC4: nop
    
            goto L_80080CD0;
    }
    // 0x80080DC4: nop

    // 0x80080DC8: beq         $s7, $zero, L_80080FB8
    if (ctx->r23 == 0) {
        // 0x80080DCC: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_80080FB8;
    }
    // 0x80080DCC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80080DD0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80080DD4: lw          $t6, 0x0($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X0);
    // 0x80080DD8: addiu       $t0, $t0, 0x71EC
    ctx->r8 = ADD32(ctx->r8, 0X71EC);
    // 0x80080DDC: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x80080DE0: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80080DE4: sll         $t8, $t6, 5
    ctx->r24 = S32(ctx->r14 << 5);
    // 0x80080DE8: addiu       $a3, $a3, 0x2334
    ctx->r7 = ADD32(ctx->r7, 0X2334);
    // 0x80080DEC: addu        $t6, $t7, $t8
    ctx->r14 = ADD32(ctx->r15, ctx->r24);
    // 0x80080DF0: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x80080DF4: lw          $a2, 0xE0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XE0);
    // 0x80080DF8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80080DFC: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x80080E00: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80080E04: sw          $t9, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->r25;
    // 0x80080E08: lw          $v0, 0x0($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X0);
    // 0x80080E0C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80080E10: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80080E14: sw          $t6, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r14;
    // 0x80080E18: addiu       $t9, $t9, 0x21F0
    ctx->r25 = ADD32(ctx->r25, 0X21F0);
    // 0x80080E1C: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80080E20: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80080E24: beq         $a2, $zero, L_80080E98
    if (ctx->r6 == 0) {
        // 0x80080E28: sw          $t9, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r25;
            goto L_80080E98;
    }
    // 0x80080E28: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80080E2C: lw          $v0, 0x0($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X0);
    // 0x80080E30: lui         $t6, 0x702
    ctx->r14 = S32(0X702 << 16);
    // 0x80080E34: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80080E38: sw          $t7, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r15;
    // 0x80080E3C: lui         $t8, 0xE
    ctx->r24 = S32(0XE << 16);
    // 0x80080E40: addiu       $t8, $t8, 0x2230
    ctx->r24 = ADD32(ctx->r24, 0X2230);
    // 0x80080E44: ori         $t6, $t6, 0x10
    ctx->r14 = ctx->r14 | 0X10;
    // 0x80080E48: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80080E4C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80080E50: lw          $v0, 0x0($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X0);
    // 0x80080E54: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80080E58: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80080E5C: sw          $t9, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r25;
    // 0x80080E60: lh          $a1, 0xA($a2)
    ctx->r5 = MEM_H(ctx->r6, 0XA);
    // 0x80080E64: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x80080E68: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x80080E6C: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x80080E70: sll         $t9, $a1, 3
    ctx->r25 = S32(ctx->r5 << 3);
    // 0x80080E74: andi        $t7, $t9, 0xFFFF
    ctx->r15 = ctx->r25 & 0XFFFF;
    // 0x80080E78: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x80080E7C: or          $t6, $t8, $t7
    ctx->r14 = ctx->r24 | ctx->r15;
    // 0x80080E80: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80080E84: lw          $t9, 0xC($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XC);
    // 0x80080E88: addiu       $ra, $zero, 0x1
    ctx->r31 = ADD32(0, 0X1);
    // 0x80080E8C: addu        $t8, $t9, $t1
    ctx->r24 = ADD32(ctx->r25, ctx->r9);
    // 0x80080E90: b           L_80080EC4
    // 0x80080E94: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
        goto L_80080EC4;
    // 0x80080E94: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
L_80080E98:
    // 0x80080E98: lw          $v0, 0x0($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X0);
    // 0x80080E9C: lui         $t6, 0x702
    ctx->r14 = S32(0X702 << 16);
    // 0x80080EA0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80080EA4: sw          $t7, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r15;
    // 0x80080EA8: lui         $t9, 0xE
    ctx->r25 = S32(0XE << 16);
    // 0x80080EAC: addiu       $t9, $t9, 0x2220
    ctx->r25 = ADD32(ctx->r25, 0X2220);
    // 0x80080EB0: ori         $t6, $t6, 0x10
    ctx->r14 = ctx->r14 | 0X10;
    // 0x80080EB4: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x80080EB8: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x80080EBC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80080EC0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
L_80080EC4:
    // 0x80080EC4: lw          $v0, 0x0($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X0);
    // 0x80080EC8: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80080ECC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80080ED0: sw          $t8, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r24;
    // 0x80080ED4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80080ED8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80080EDC: lw          $v0, 0x0($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X0);
    // 0x80080EE0: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80080EE4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80080EE8: sw          $t6, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r14;
    // 0x80080EEC: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x80080EF0: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x80080EF4: sll         $t7, $t8, 5
    ctx->r15 = S32(ctx->r24 << 5);
    // 0x80080EF8: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x80080EFC: addu        $t6, $t9, $t7
    ctx->r14 = ADD32(ctx->r25, ctx->r15);
    // 0x80080F00: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80080F04: addu        $t7, $t6, $t9
    ctx->r15 = ADD32(ctx->r14, ctx->r25);
    // 0x80080F08: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80080F0C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80080F10: addu        $t6, $t8, $t1
    ctx->r14 = ADD32(ctx->r24, ctx->r9);
    // 0x80080F14: andi        $t9, $t6, 0x6
    ctx->r25 = ctx->r14 & 0X6;
    // 0x80080F18: ori         $t7, $t9, 0x98
    ctx->r15 = ctx->r25 | 0X98;
    // 0x80080F1C: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x80080F20: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x80080F24: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x80080F28: ori         $t7, $t9, 0x170
    ctx->r15 = ctx->r25 | 0X170;
    // 0x80080F2C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80080F30: lw          $t6, 0x0($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X0);
    // 0x80080F34: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x80080F38: sll         $t9, $t6, 5
    ctx->r25 = S32(ctx->r14 << 5);
    // 0x80080F3C: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x80080F40: addu        $t7, $t8, $t9
    ctx->r15 = ADD32(ctx->r24, ctx->r25);
    // 0x80080F44: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80080F48: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80080F4C: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x80080F50: ori         $t9, $ra, 0x90
    ctx->r25 = ctx->r31 | 0X90;
    // 0x80080F54: addu        $t7, $t6, $t1
    ctx->r15 = ADD32(ctx->r14, ctx->r9);
    // 0x80080F58: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80080F5C: lw          $v0, 0x0($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X0);
    // 0x80080F60: andi        $t6, $t9, 0xFF
    ctx->r14 = ctx->r25 & 0XFF;
    // 0x80080F64: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80080F68: sw          $t8, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r24;
    // 0x80080F6C: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x80080F70: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x80080F74: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80080F78: ori         $t9, $t8, 0xA0
    ctx->r25 = ctx->r24 | 0XA0;
    // 0x80080F7C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80080F80: lw          $t7, 0x0($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X0);
    // 0x80080F84: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x80080F88: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x80080F8C: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x80080F90: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80080F94: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80080F98: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x80080F9C: lw          $t7, 0x8($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X8);
    // 0x80080FA0: nop

    // 0x80080FA4: addu        $t9, $t7, $t1
    ctx->r25 = ADD32(ctx->r15, ctx->r9);
    // 0x80080FA8: jal         0x8007B820
    // 0x80080FAC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    rendermode_reset(rdram, ctx);
        goto after_0;
    // 0x80080FAC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    after_0:
    // 0x80080FB0: b           L_80080FE0
    // 0x80080FB4: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
        goto L_80080FE0;
    // 0x80080FB4: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
L_80080FB8:
    // 0x80080FB8: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x80080FBC: lw          $t6, 0x71EC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X71EC);
    // 0x80080FC0: sll         $t7, $t8, 5
    ctx->r15 = S32(ctx->r24 << 5);
    // 0x80080FC4: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80080FC8: lw          $t8, 0x2334($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2334);
    // 0x80080FCC: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x80080FD0: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x80080FD4: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x80080FD8: sw          $zero, 0x18($t7)
    MEM_W(0X18, ctx->r15) = 0;
    // 0x80080FDC: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
L_80080FE0:
    // 0x80080FE0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80080FE4: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80080FE8: sw          $t9, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r25;
    // 0x80080FEC: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80080FF0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80080FF4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80080FF8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80080FFC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80081000: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80081004: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80081008: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8008100C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80081010: jr          $ra
    // 0x80081014: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x80081014: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
