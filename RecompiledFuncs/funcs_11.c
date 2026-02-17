#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void play_taj_voice_clip(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003AC7C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8003AC80: addiu       $a3, $a3, -0x25AC
    ctx->r7 = ADD32(ctx->r7, -0X25AC);
    // 0x8003AC84: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x8003AC88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003AC8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003AC90: beq         $a2, $zero, L_8003ACBC
    if (ctx->r6 == 0) {
        // 0x8003AC94: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_8003ACBC;
    }
    // 0x8003AC94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003AC98: andi        $t6, $a1, 0x1
    ctx->r14 = ctx->r5 & 0X1;
    // 0x8003AC9C: beq         $t6, $zero, L_8003ACBC
    if (ctx->r14 == 0) {
        // 0x8003ACA0: nop
    
            goto L_8003ACBC;
    }
    // 0x8003ACA0: nop

    // 0x8003ACA4: jal         0x8000488C
    // 0x8003ACA8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    sndp_stop(rdram, ctx);
        goto after_0;
    // 0x8003ACA8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x8003ACAC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8003ACB0: addiu       $a3, $a3, -0x25AC
    ctx->r7 = ADD32(ctx->r7, -0X25AC);
    // 0x8003ACB4: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x8003ACB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8003ACBC:
    // 0x8003ACBC: bne         $a2, $zero, L_8003ACD4
    if (ctx->r6 != 0) {
        // 0x8003ACC0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8003ACD4;
    }
    // 0x8003ACC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003ACC4: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    // 0x8003ACC8: jal         0x80001D04
    // 0x8003ACCC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    sound_play(rdram, ctx);
        goto after_1;
    // 0x8003ACCC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_1:
    // 0x8003ACD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003ACD4:
    // 0x8003ACD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003ACD8: jr          $ra
    // 0x8003ACDC: nop

    return;
    // 0x8003ACDC: nop

;}
RECOMP_FUNC void obj_loop_gbparkwarden(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003ACE0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8003ACE4: jr          $ra
    // 0x8003ACE8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8003ACE8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void get_npc_pos_y(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003ACEC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8003ACF0: lwc1        $f0, -0x25B0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X25B0);
    // 0x8003ACF4: jr          $ra
    // 0x8003ACF8: nop

    return;
    // 0x8003ACF8: nop

;}
RECOMP_FUNC void obj_init_checkpoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003ACFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003AD00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003AD04: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8003AD08: lbu         $t7, 0x8($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X8);
    // 0x8003AD0C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8003AD10: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8003AD14: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003AD18: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003AD1C: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x8003AD20: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003AD24: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8003AD28: nop

    // 0x8003AD2C: bc1f        L_8003AD3C
    if (!c1cs) {
        // 0x8003AD30: nop
    
            goto L_8003AD3C;
    }
    // 0x8003AD30: nop

    // 0x8003AD34: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8003AD38: nop

L_8003AD3C:
    // 0x8003AD3C: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8003AD40: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    // 0x8003AD44: lbu         $t9, 0xA($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0XA);
    // 0x8003AD48: nop

    // 0x8003AD4C: sll         $t0, $t9, 10
    ctx->r8 = S32(ctx->r25 << 10);
    // 0x8003AD50: jal         0x80011390
    // 0x8003AD54: sh          $t0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r8;
    path_enable(rdram, ctx);
        goto after_0;
    // 0x8003AD54: sh          $t0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r8;
    after_0:
    // 0x8003AD58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003AD5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003AD60: jr          $ra
    // 0x8003AD64: nop

    return;
    // 0x8003AD64: nop

;}
RECOMP_FUNC void obj_loop_checkpoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003AD68: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8003AD6C: jr          $ra
    // 0x8003AD70: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8003AD70: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void obj_init_modechange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003AD74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003AD78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003AD7C: lbu         $t7, 0x8($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X8);
    // 0x8003AD80: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8003AD84: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8003AD88: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003AD8C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003AD90: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x8003AD94: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003AD98: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8003AD9C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8003ADA0: bc1f        L_8003ADB0
    if (!c1cs) {
        // 0x8003ADA4: nop
    
            goto L_8003ADB0;
    }
    // 0x8003ADA4: nop

    // 0x8003ADA8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8003ADAC: nop

L_8003ADB0:
    // 0x8003ADB0: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8003ADB4: lw          $v0, 0x64($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X64);
    // 0x8003ADB8: swc1        $f0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f0.u32l;
    // 0x8003ADBC: lbu         $t9, 0x9($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X9);
    // 0x8003ADC0: nop

    // 0x8003ADC4: sll         $t0, $t9, 10
    ctx->r8 = S32(ctx->r25 << 10);
    // 0x8003ADC8: sh          $t0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r8;
    // 0x8003ADCC: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    // 0x8003ADD0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8003ADD4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8003ADD8: jal         0x80070A04
    // 0x8003ADDC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    sins_f(rdram, ctx);
        goto after_0;
    // 0x8003ADDC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_0:
    // 0x8003ADE0: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8003ADE4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8003ADE8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003ADEC: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x8003ADF0: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x8003ADF4: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    // 0x8003ADF8: jal         0x80070A38
    // 0x8003ADFC: nop

    coss_f(rdram, ctx);
        goto after_1;
    // 0x8003ADFC: nop

    after_1:
    // 0x8003AE00: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8003AE04: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8003AE08: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8003AE0C: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x8003AE10: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8003AE14: lwc1        $f16, 0xC($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0XC);
    // 0x8003AE18: lwc1        $f4, 0x14($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X14);
    // 0x8003AE1C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8003AE20: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8003AE24: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8003AE28: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8003AE2C: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8003AE30: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    // 0x8003AE34: lbu         $t1, 0x8($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X8);
    // 0x8003AE38: nop

    // 0x8003AE3C: sw          $t1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r9;
    // 0x8003AE40: lbu         $t2, 0xA($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0XA);
    // 0x8003AE44: nop

    // 0x8003AE48: sb          $t2, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r10;
    // 0x8003AE4C: lw          $t4, 0x4C($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X4C);
    // 0x8003AE50: nop

    // 0x8003AE54: sh          $t3, 0x14($t4)
    MEM_H(0X14, ctx->r12) = ctx->r11;
    // 0x8003AE58: lw          $t5, 0x4C($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X4C);
    // 0x8003AE5C: nop

    // 0x8003AE60: sb          $zero, 0x11($t5)
    MEM_B(0X11, ctx->r13) = 0;
    // 0x8003AE64: lw          $t7, 0x4C($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X4C);
    // 0x8003AE68: lbu         $t6, 0x8($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X8);
    // 0x8003AE6C: nop

    // 0x8003AE70: sb          $t6, 0x10($t7)
    MEM_B(0X10, ctx->r15) = ctx->r14;
    // 0x8003AE74: lw          $t8, 0x4C($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X4C);
    // 0x8003AE78: nop

    // 0x8003AE7C: sb          $zero, 0x12($t8)
    MEM_B(0X12, ctx->r24) = 0;
    // 0x8003AE80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003AE84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003AE88: jr          $ra
    // 0x8003AE8C: nop

    return;
    // 0x8003AE8C: nop

;}
RECOMP_FUNC void obj_loop_modechange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003AE90: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8003AE94: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8003AE98: sw          $s7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r23;
    // 0x8003AE9C: sw          $s6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r22;
    // 0x8003AEA0: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x8003AEA4: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x8003AEA8: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x8003AEAC: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x8003AEB0: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8003AEB4: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8003AEB8: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8003AEBC: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x8003AEC0: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8003AEC4: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8003AEC8: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x8003AECC: lw          $s2, 0x64($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X64);
    // 0x8003AED0: lw          $t6, 0x4C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4C);
    // 0x8003AED4: lw          $v0, 0x10($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X10);
    // 0x8003AED8: lbu         $t7, 0x13($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X13);
    // 0x8003AEDC: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8003AEE0: slt         $at, $t7, $v0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003AEE4: beq         $at, $zero, L_8003B05C
    if (ctx->r1 == 0) {
        // 0x8003AEE8: addiu       $a0, $sp, 0x74
        ctx->r4 = ADD32(ctx->r29, 0X74);
            goto L_8003B05C;
    }
    // 0x8003AEE8: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    // 0x8003AEEC: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8003AEF0: jal         0x8001BAA8
    // 0x8003AEF4: cvt.s.w     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    ctx->f22.fl = CVT_S_W(ctx->f4.u32l);
    get_racer_objects(rdram, ctx);
        goto after_0;
    // 0x8003AEF4: cvt.s.w     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    ctx->f22.fl = CVT_S_W(ctx->f4.u32l);
    after_0:
    // 0x8003AEF8: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x8003AEFC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8003AF00: blez        $t8, L_8003B05C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8003AF04: or          $s5, $v0, $zero
        ctx->r21 = ctx->r2 | 0;
            goto L_8003B05C;
    }
    // 0x8003AF04: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x8003AF08: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8003AF0C: addiu       $s7, $zero, 0xFF
    ctx->r23 = ADD32(0, 0XFF);
    // 0x8003AF10: addiu       $s6, $zero, 0x4
    ctx->r22 = ADD32(0, 0X4);
L_8003AF14:
    // 0x8003AF14: lw          $s0, 0x0($s5)
    ctx->r16 = MEM_W(ctx->r21, 0X0);
    // 0x8003AF18: lbu         $t9, 0x14($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X14);
    // 0x8003AF1C: lw          $s1, 0x64($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X64);
    // 0x8003AF20: nop

    // 0x8003AF24: lb          $t0, 0x1D6($s1)
    ctx->r8 = MEM_B(ctx->r17, 0X1D6);
    // 0x8003AF28: nop

    // 0x8003AF2C: beq         $t9, $t0, L_8003B04C
    if (ctx->r25 == ctx->r8) {
        // 0x8003AF30: lw          $t5, 0x74($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X74);
            goto L_8003B04C;
    }
    // 0x8003AF30: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x8003AF34: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003AF38: lwc1        $f8, 0xC($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8003AF3C: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003AF40: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8003AF44: lwc1        $f16, 0x10($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8003AF48: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8003AF4C: sub.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8003AF50: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003AF54: lwc1        $f4, 0x14($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8003AF58: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8003AF5C: sub.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8003AF60: mul.s       $f16, $f14, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8003AF64: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8003AF68: jal         0x800CA030
    // 0x8003AF6C: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x8003AF6C: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    after_1:
    // 0x8003AF70: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x8003AF74: nop

    // 0x8003AF78: bc1f        L_8003B04C
    if (!c1cs) {
        // 0x8003AF7C: lw          $t5, 0x74($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X74);
            goto L_8003B04C;
    }
    // 0x8003AF7C: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x8003AF80: lwc1        $f18, 0x0($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8003AF84: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003AF88: lwc1        $f8, 0x8($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8003AF8C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8003AF90: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003AF94: lwc1        $f4, 0xC($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8003AF98: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8003AF9C: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x8003AFA0: add.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8003AFA4: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x8003AFA8: nop

    // 0x8003AFAC: bc1f        L_8003B04C
    if (!c1cs) {
        // 0x8003AFB0: lw          $t5, 0x74($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X74);
            goto L_8003B04C;
    }
    // 0x8003AFB0: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x8003AFB4: sb          $zero, 0x1E0($s1)
    MEM_B(0X1E0, ctx->r17) = 0;
    // 0x8003AFB8: lbu         $v0, 0x14($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X14);
    // 0x8003AFBC: nop

    // 0x8003AFC0: bne         $v0, $zero, L_8003AFD4
    if (ctx->r2 != 0) {
        // 0x8003AFC4: nop
    
            goto L_8003AFD4;
    }
    // 0x8003AFC4: nop

    // 0x8003AFC8: lb          $t1, 0x1D7($s1)
    ctx->r9 = MEM_B(ctx->r17, 0X1D7);
    // 0x8003AFCC: b           L_8003AFD8
    // 0x8003AFD0: sb          $t1, 0x1D6($s1)
    MEM_B(0X1D6, ctx->r17) = ctx->r9;
        goto L_8003AFD8;
    // 0x8003AFD0: sb          $t1, 0x1D6($s1)
    MEM_B(0X1D6, ctx->r17) = ctx->r9;
L_8003AFD4:
    // 0x8003AFD4: sb          $v0, 0x1D6($s1)
    MEM_B(0X1D6, ctx->r17) = ctx->r2;
L_8003AFD8:
    // 0x8003AFD8: lbu         $t2, 0x14($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X14);
    // 0x8003AFDC: nop

    // 0x8003AFE0: bne         $s6, $t2, L_8003B03C
    if (ctx->r22 != ctx->r10) {
        // 0x8003AFE4: nop
    
            goto L_8003B03C;
    }
    // 0x8003AFE4: nop

    // 0x8003AFE8: lb          $t3, 0x1D8($s1)
    ctx->r11 = MEM_B(ctx->r17, 0X1D8);
    // 0x8003AFEC: nop

    // 0x8003AFF0: bne         $t3, $zero, L_8003B004
    if (ctx->r11 != 0) {
        // 0x8003AFF4: nop
    
            goto L_8003B004;
    }
    // 0x8003AFF4: nop

    // 0x8003AFF8: lh          $a0, 0x0($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X0);
    // 0x8003AFFC: jal         0x80072594
    // 0x8003B000: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    rumble_set(rdram, ctx);
        goto after_2;
    // 0x8003B000: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_2:
L_8003B004:
    // 0x8003B004: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003B008: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003B00C: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x8003B010: jal         0x8001C558
    // 0x8003B014: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    ainode_find_nearest(rdram, ctx);
        goto after_3;
    // 0x8003B014: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x8003B018: beq         $v0, $s7, L_8003B030
    if (ctx->r2 == ctx->r23) {
        // 0x8003B01C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8003B030;
    }
    // 0x8003B01C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8003B020: jal         0x8001D248
    // 0x8003B024: nop

    ainode_get(rdram, ctx);
        goto after_4;
    // 0x8003B024: nop

    after_4:
    // 0x8003B028: b           L_8003B034
    // 0x8003B02C: sw          $v0, 0x158($s1)
    MEM_W(0X158, ctx->r17) = ctx->r2;
        goto L_8003B034;
    // 0x8003B02C: sw          $v0, 0x158($s1)
    MEM_W(0X158, ctx->r17) = ctx->r2;
L_8003B030:
    // 0x8003B030: sw          $zero, 0x158($s1)
    MEM_W(0X158, ctx->r17) = 0;
L_8003B034:
    // 0x8003B034: sw          $zero, 0x15C($s1)
    MEM_W(0X15C, ctx->r17) = 0;
    // 0x8003B038: sh          $zero, 0x19A($s1)
    MEM_H(0X19A, ctx->r17) = 0;
L_8003B03C:
    // 0x8003B03C: lh          $t4, 0x0($s3)
    ctx->r12 = MEM_H(ctx->r19, 0X0);
    // 0x8003B040: nop

    // 0x8003B044: sh          $t4, 0x198($s1)
    MEM_H(0X198, ctx->r17) = ctx->r12;
    // 0x8003B048: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
L_8003B04C:
    // 0x8003B04C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8003B050: slt         $at, $s4, $t5
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8003B054: bne         $at, $zero, L_8003AF14
    if (ctx->r1 != 0) {
        // 0x8003B058: addiu       $s5, $s5, 0x4
        ctx->r21 = ADD32(ctx->r21, 0X4);
            goto L_8003AF14;
    }
    // 0x8003B058: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
L_8003B05C:
    // 0x8003B05C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8003B060: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x8003B064: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8003B068: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8003B06C: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8003B070: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8003B074: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8003B078: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x8003B07C: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x8003B080: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x8003B084: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x8003B088: lw          $s6, 0x3C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X3C);
    // 0x8003B08C: lw          $s7, 0x40($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X40);
    // 0x8003B090: jr          $ra
    // 0x8003B094: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8003B094: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void obj_init_bonus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B098: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003B09C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003B0A0: lbu         $t7, 0x8($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X8);
    // 0x8003B0A4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8003B0A8: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8003B0AC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003B0B0: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003B0B4: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x8003B0B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003B0BC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8003B0C0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8003B0C4: bc1f        L_8003B0D4
    if (!c1cs) {
        // 0x8003B0C8: nop
    
            goto L_8003B0D4;
    }
    // 0x8003B0C8: nop

    // 0x8003B0CC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8003B0D0: nop

L_8003B0D4:
    // 0x8003B0D4: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8003B0D8: lw          $v0, 0x64($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X64);
    // 0x8003B0DC: swc1        $f0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f0.u32l;
    // 0x8003B0E0: lbu         $t9, 0x9($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X9);
    // 0x8003B0E4: nop

    // 0x8003B0E8: sll         $t0, $t9, 10
    ctx->r8 = S32(ctx->r25 << 10);
    // 0x8003B0EC: sh          $t0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r8;
    // 0x8003B0F0: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    // 0x8003B0F4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8003B0F8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8003B0FC: jal         0x80070A04
    // 0x8003B100: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    sins_f(rdram, ctx);
        goto after_0;
    // 0x8003B100: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_0:
    // 0x8003B104: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8003B108: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8003B10C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003B110: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x8003B114: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x8003B118: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    // 0x8003B11C: jal         0x80070A38
    // 0x8003B120: nop

    coss_f(rdram, ctx);
        goto after_1;
    // 0x8003B120: nop

    after_1:
    // 0x8003B124: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8003B128: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8003B12C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8003B130: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x8003B134: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8003B138: lwc1        $f16, 0xC($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0XC);
    // 0x8003B13C: lwc1        $f4, 0x14($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X14);
    // 0x8003B140: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8003B144: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8003B148: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8003B14C: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8003B150: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8003B154: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    // 0x8003B158: lbu         $t1, 0x8($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X8);
    // 0x8003B15C: nop

    // 0x8003B160: sw          $t1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r9;
    // 0x8003B164: lbu         $t2, 0xA($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0XA);
    // 0x8003B168: nop

    // 0x8003B16C: sb          $t2, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r10;
    // 0x8003B170: lw          $t4, 0x4C($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X4C);
    // 0x8003B174: nop

    // 0x8003B178: sh          $t3, 0x14($t4)
    MEM_H(0X14, ctx->r12) = ctx->r11;
    // 0x8003B17C: lw          $t5, 0x4C($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X4C);
    // 0x8003B180: nop

    // 0x8003B184: sb          $zero, 0x11($t5)
    MEM_B(0X11, ctx->r13) = 0;
    // 0x8003B188: lw          $t7, 0x4C($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X4C);
    // 0x8003B18C: lbu         $t6, 0x8($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X8);
    // 0x8003B190: nop

    // 0x8003B194: sb          $t6, 0x10($t7)
    MEM_B(0X10, ctx->r15) = ctx->r14;
    // 0x8003B198: lw          $t8, 0x4C($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X4C);
    // 0x8003B19C: nop

    // 0x8003B1A0: sb          $zero, 0x12($t8)
    MEM_B(0X12, ctx->r24) = 0;
    // 0x8003B1A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003B1A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003B1AC: jr          $ra
    // 0x8003B1B0: nop

    return;
    // 0x8003B1B0: nop

;}
RECOMP_FUNC void obj_loop_bonus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B1B4: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x8003B1B8: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8003B1BC: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x8003B1C0: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x8003B1C4: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x8003B1C8: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x8003B1CC: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8003B1D0: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x8003B1D4: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8003B1D8: swc1        $f25, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x8003B1DC: swc1        $f24, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f24.u32l;
    // 0x8003B1E0: swc1        $f23, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8003B1E4: swc1        $f22, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f22.u32l;
    // 0x8003B1E8: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8003B1EC: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x8003B1F0: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x8003B1F4: lw          $s4, 0x64($a0)
    ctx->r20 = MEM_W(ctx->r4, 0X64);
    // 0x8003B1F8: lw          $t6, 0x4C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4C);
    // 0x8003B1FC: lw          $v0, 0x10($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X10);
    // 0x8003B200: lbu         $t7, 0x13($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X13);
    // 0x8003B204: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x8003B208: slt         $at, $t7, $v0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003B20C: beq         $at, $zero, L_8003B368
    if (ctx->r1 == 0) {
        // 0x8003B210: addiu       $a0, $sp, 0x84
        ctx->r4 = ADD32(ctx->r29, 0X84);
            goto L_8003B368;
    }
    // 0x8003B210: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x8003B214: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8003B218: jal         0x8001BAA8
    // 0x8003B21C: cvt.s.w     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    ctx->f22.fl = CVT_S_W(ctx->f4.u32l);
    get_racer_objects(rdram, ctx);
        goto after_0;
    // 0x8003B21C: cvt.s.w     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    ctx->f22.fl = CVT_S_W(ctx->f4.u32l);
    after_0:
    // 0x8003B220: lw          $t8, 0x84($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X84);
    // 0x8003B224: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8003B228: blez        $t8, L_8003B368
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8003B22C: lui         $at, 0x3FE0
        ctx->r1 = S32(0X3FE0 << 16);
            goto L_8003B368;
    }
    // 0x8003B22C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8003B230: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8003B234: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003B238: cvt.d.s     $f6, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f6.d = CVT_D_S(ctx->f22.fl);
    // 0x8003B23C: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8003B240: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x8003B244: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8003B248: addiu       $s6, $zero, 0xA
    ctx->r22 = ADD32(0, 0XA);
    // 0x8003B24C: cvt.s.d     $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f20.fl = CVT_S_D(ctx->f10.d);
L_8003B250:
    // 0x8003B250: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x8003B254: lwc1        $f18, 0x10($s5)
    ctx->f18.u32l = MEM_W(ctx->r21, 0X10);
    // 0x8003B258: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003B25C: lw          $s1, 0x64($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X64);
    // 0x8003B260: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8003B264: c.lt.s      $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f14.fl < ctx->f20.fl;
    // 0x8003B268: nop

    // 0x8003B26C: bc1f        L_8003B358
    if (!c1cs) {
        // 0x8003B270: lw          $t2, 0x84($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X84);
            goto L_8003B358;
    }
    // 0x8003B270: lw          $t2, 0x84($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X84);
    // 0x8003B274: neg.s       $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = -ctx->f20.fl;
    // 0x8003B278: c.lt.s      $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f4.fl < ctx->f14.fl;
    // 0x8003B27C: nop

    // 0x8003B280: bc1f        L_8003B358
    if (!c1cs) {
        // 0x8003B284: lw          $t2, 0x84($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X84);
            goto L_8003B358;
    }
    // 0x8003B284: lw          $t2, 0x84($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X84);
    // 0x8003B288: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003B28C: lwc1        $f8, 0xC($s5)
    ctx->f8.u32l = MEM_W(ctx->r21, 0XC);
    // 0x8003B290: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003B294: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8003B298: lwc1        $f16, 0x14($s5)
    ctx->f16.u32l = MEM_W(ctx->r21, 0X14);
    // 0x8003B29C: mul.s       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8003B2A0: sub.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8003B2A4: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8003B2A8: nop

    // 0x8003B2AC: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8003B2B0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8003B2B4: jal         0x800CA030
    // 0x8003B2B8: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x8003B2B8: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_1:
    // 0x8003B2BC: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x8003B2C0: nop

    // 0x8003B2C4: bc1f        L_8003B358
    if (!c1cs) {
        // 0x8003B2C8: lw          $t2, 0x84($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X84);
            goto L_8003B358;
    }
    // 0x8003B2C8: lw          $t2, 0x84($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X84);
    // 0x8003B2CC: lwc1        $f10, 0x0($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0X0);
    // 0x8003B2D0: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003B2D4: lwc1        $f4, 0x8($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X8);
    // 0x8003B2D8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8003B2DC: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003B2E0: lwc1        $f16, 0xC($s4)
    ctx->f16.u32l = MEM_W(ctx->r20, 0XC);
    // 0x8003B2E4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8003B2E8: add.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8003B2EC: add.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8003B2F0: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x8003B2F4: nop

    // 0x8003B2F8: bc1f        L_8003B358
    if (!c1cs) {
        // 0x8003B2FC: lw          $t2, 0x84($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X84);
            goto L_8003B358;
    }
    // 0x8003B2FC: lw          $t2, 0x84($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X84);
    // 0x8003B300: lb          $t9, 0x185($s1)
    ctx->r25 = MEM_B(ctx->r17, 0X185);
    // 0x8003B304: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    // 0x8003B308: slti        $at, $t9, 0xA
    ctx->r1 = SIGNED(ctx->r25) < 0XA ? 1 : 0;
    // 0x8003B30C: beq         $at, $zero, L_8003B354
    if (ctx->r1 == 0) {
        // 0x8003B310: addiu       $t0, $zero, 0x4
        ctx->r8 = ADD32(0, 0X4);
            goto L_8003B354;
    }
    // 0x8003B310: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8003B314: sb          $s6, 0x185($s1)
    MEM_B(0X185, ctx->r17) = ctx->r22;
    // 0x8003B318: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x8003B31C: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x8003B320: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8003B324: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8003B328: jal         0x80009558
    // 0x8003B32C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_2;
    // 0x8003B32C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_2:
    // 0x8003B330: lb          $a0, 0x3($s1)
    ctx->r4 = MEM_B(ctx->r17, 0X3);
    // 0x8003B334: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8003B338: addiu       $a0, $a0, 0x7B
    ctx->r4 = ADD32(ctx->r4, 0X7B);
    // 0x8003B33C: andi        $t1, $a0, 0xFFFF
    ctx->r9 = ctx->r4 & 0XFFFF;
    // 0x8003B340: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x8003B344: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x8003B348: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8003B34C: jal         0x80001EA8
    // 0x8003B350: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    sound_play_spatial(rdram, ctx);
        goto after_3;
    // 0x8003B350: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_3:
L_8003B354:
    // 0x8003B354: lw          $t2, 0x84($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X84);
L_8003B358:
    // 0x8003B358: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8003B35C: slt         $at, $s2, $t2
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8003B360: bne         $at, $zero, L_8003B250
    if (ctx->r1 != 0) {
        // 0x8003B364: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_8003B250;
    }
    // 0x8003B364: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
L_8003B368:
    // 0x8003B368: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8003B36C: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8003B370: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8003B374: lwc1        $f23, 0x28($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8003B378: lwc1        $f22, 0x2C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8003B37C: lwc1        $f25, 0x30($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x8003B380: lwc1        $f24, 0x34($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8003B384: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8003B388: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8003B38C: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8003B390: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x8003B394: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x8003B398: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x8003B39C: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x8003B3A0: jr          $ra
    // 0x8003B3A4: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x8003B3A4: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void obj_init_goldenballoon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B3A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003B3AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003B3B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003B3B4: lb          $a3, 0x8($a1)
    ctx->r7 = MEM_B(ctx->r5, 0X8);
    // 0x8003B3B8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003B3BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003B3C0: bne         $a3, $at, L_8003B3DC
    if (ctx->r7 != ctx->r1) {
        // 0x8003B3C4: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_8003B3DC;
    }
    // 0x8003B3C4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8003B3C8: jal         0x8000CC20
    // 0x8003B3CC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_8000CC20(rdram, ctx);
        goto after_0;
    // 0x8003B3CC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8003B3D0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8003B3D4: b           L_8003B3F4
    // 0x8003B3D8: sb          $v0, 0x8($a2)
    MEM_B(0X8, ctx->r6) = ctx->r2;
        goto L_8003B3F4;
    // 0x8003B3D8: sb          $v0, 0x8($a2)
    MEM_B(0X8, ctx->r6) = ctx->r2;
L_8003B3DC:
    // 0x8003B3DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003B3E0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8003B3E4: jal         0x8000CBF0
    // 0x8003B3E8: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_8000CBF0(rdram, ctx);
        goto after_1;
    // 0x8003B3E8: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_1:
    // 0x8003B3EC: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8003B3F0: nop

L_8003B3F4:
    // 0x8003B3F4: lb          $t6, 0x8($a2)
    ctx->r14 = MEM_B(ctx->r6, 0X8);
    // 0x8003B3F8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003B3FC: bne         $t6, $at, L_8003B418
    if (ctx->r14 != ctx->r1) {
        // 0x8003B400: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8003B418;
    }
    // 0x8003B400: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003B404: addiu       $a0, $a0, 0x6530
    ctx->r4 = ADD32(ctx->r4, 0X6530);
    // 0x8003B408: jal         0x800CA2B4
    // 0x8003B40C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    rmonPrintf_recomp(rdram, ctx);
        goto after_2;
    // 0x8003B40C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_2:
    // 0x8003B410: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8003B414: nop

L_8003B418:
    // 0x8003B418: lw          $t8, 0x4C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4C);
    // 0x8003B41C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8003B420: sh          $t7, 0x14($t8)
    MEM_H(0X14, ctx->r24) = ctx->r15;
    // 0x8003B424: lw          $t0, 0x4C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4C);
    // 0x8003B428: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8003B42C: sb          $t9, 0x11($t0)
    MEM_B(0X11, ctx->r8) = ctx->r25;
    // 0x8003B430: lw          $t2, 0x4C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4C);
    // 0x8003B434: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
    // 0x8003B438: sb          $t1, 0x10($t2)
    MEM_B(0X10, ctx->r10) = ctx->r9;
    // 0x8003B43C: lw          $t3, 0x4C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4C);
    // 0x8003B440: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8003B444: sb          $zero, 0x12($t3)
    MEM_B(0X12, ctx->r11) = 0;
    // 0x8003B448: lbu         $t5, 0x9($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X9);
    // 0x8003B44C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003B450: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x8003B454: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x8003B458: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003B45C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003B460: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8003B464: nop

    // 0x8003B468: bc1f        L_8003B478
    if (!c1cs) {
        // 0x8003B46C: nop
    
            goto L_8003B478;
    }
    // 0x8003B46C: nop

    // 0x8003B470: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8003B474: nop

L_8003B478:
    // 0x8003B478: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8003B47C: lw          $t6, 0x40($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X40);
    // 0x8003B480: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x8003B484: lwc1        $f8, 0xC($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0XC);
    // 0x8003B488: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8003B48C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8003B490: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8003B494: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x8003B498: sb          $t7, 0xD($v0)
    MEM_B(0XD, ctx->r2) = ctx->r15;
    // 0x8003B49C: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x8003B4A0: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
    // 0x8003B4A4: lb          $t8, 0xA($a2)
    ctx->r24 = MEM_B(ctx->r6, 0XA);
    // 0x8003B4A8: nop

    // 0x8003B4AC: beq         $t8, $zero, L_8003B4F0
    if (ctx->r24 == 0) {
        // 0x8003B4B0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8003B4F0;
    }
    // 0x8003B4B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003B4B4: jal         0x8006ECD0
    // 0x8003B4B8: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    get_settings(rdram, ctx);
        goto after_3;
    // 0x8003B4B8: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_3:
    // 0x8003B4BC: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8003B4C0: lhu         $t9, 0x14($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X14);
    // 0x8003B4C4: lb          $t0, 0xA($a2)
    ctx->r8 = MEM_B(ctx->r6, 0XA);
    // 0x8003B4C8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8003B4CC: addiu       $t1, $t0, 0x2
    ctx->r9 = ADD32(ctx->r8, 0X2);
    // 0x8003B4D0: sllv        $t3, $t2, $t1
    ctx->r11 = S32(ctx->r10 << (ctx->r9 & 31));
    // 0x8003B4D4: and         $t4, $t9, $t3
    ctx->r12 = ctx->r25 & ctx->r11;
    // 0x8003B4D8: beq         $t4, $zero, L_8003B4E8
    if (ctx->r12 == 0) {
        // 0x8003B4DC: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_8003B4E8;
    }
    // 0x8003B4DC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8003B4E0: b           L_8003B4EC
    // 0x8003B4E4: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
        goto L_8003B4EC;
    // 0x8003B4E4: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
L_8003B4E8:
    // 0x8003B4E8: sw          $t5, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r13;
L_8003B4EC:
    // 0x8003B4EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8003B4F0:
    // 0x8003B4F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003B4F4: jr          $ra
    // 0x8003B4F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8003B4F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void obj_loop_goldenballoon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B4FC: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8003B500: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8003B504: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x8003B508: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003B50C: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x8003B510: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8003B514: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8003B518: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003B51C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8003B520: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x8003B524: bne         $t7, $zero, L_8003B544
    if (ctx->r15 != 0) {
        // 0x8003B528: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_8003B544;
    }
    // 0x8003B528: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8003B52C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003B530: lwc1        $f9, 0x66F0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X66F0);
    // 0x8003B534: lwc1        $f8, 0x66F4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X66F4);
    // 0x8003B538: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8003B53C: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8003B540: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
L_8003B544:
    // 0x8003B544: lui         $t8, 0xA000
    ctx->r24 = S32(0XA000 << 16);
    // 0x8003B548: lw          $t9, 0x284($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X284);
    // 0x8003B54C: lui         $at, 0x240B
    ctx->r1 = S32(0X240B << 16);
    // 0x8003B550: ori         $at, $at, 0x17D7
    ctx->r1 = ctx->r1 | 0X17D7;
    // 0x8003B554: beq         $t9, $at, L_8003B560
    if (ctx->r25 == ctx->r1) {
        // 0x8003B558: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8003B560;
    }
    // 0x8003B558: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8003B55C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_8003B560:
    // 0x8003B560: jal         0x8006ECD0
    // 0x8003B564: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x8003B564: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x8003B568: lbu         $t3, 0x49($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X49);
    // 0x8003B56C: lw          $v1, 0x3C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X3C);
    // 0x8003B570: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x8003B574: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8003B578: lb          $t0, 0x8($v1)
    ctx->r8 = MEM_B(ctx->r3, 0X8);
    // 0x8003B57C: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8003B580: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8003B584: lui         $t1, 0x1
    ctx->r9 = S32(0X1 << 16);
    // 0x8003B588: sllv        $a1, $t1, $t0
    ctx->r5 = S32(ctx->r9 << (ctx->r8 & 31));
    // 0x8003B58C: and         $t7, $t6, $a1
    ctx->r15 = ctx->r14 & ctx->r5;
    // 0x8003B590: beq         $t7, $zero, L_8003B5E0
    if (ctx->r15 == 0) {
        // 0x8003B594: nop
    
            goto L_8003B5E0;
    }
    // 0x8003B594: nop

    // 0x8003B598: lw          $t8, 0x7C($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X7C);
    // 0x8003B59C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8003B5A0: blez        $t8, L_8003B5D0
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8003B5A4: nop
    
            goto L_8003B5D0;
    }
    // 0x8003B5A4: nop

    // 0x8003B5A8: sw          $t9, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r25;
    // 0x8003B5AC: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8003B5B0: jal         0x800B019C
    // 0x8003B5B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    obj_spawn_particle(rdram, ctx);
        goto after_1;
    // 0x8003B5B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x8003B5B8: lw          $t1, 0x7C($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X7C);
    // 0x8003B5BC: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x8003B5C0: nop

    // 0x8003B5C4: subu        $t3, $t1, $t0
    ctx->r11 = SUB32(ctx->r9, ctx->r8);
    // 0x8003B5C8: b           L_8003B7F8
    // 0x8003B5CC: sw          $t3, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = ctx->r11;
        goto L_8003B7F8;
    // 0x8003B5CC: sw          $t3, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = ctx->r11;
L_8003B5D0:
    // 0x8003B5D0: jal         0x8000FFB8
    // 0x8003B5D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    free_object(rdram, ctx);
        goto after_2;
    // 0x8003B5D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x8003B5D8: b           L_8003B7FC
    // 0x8003B5DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8003B7FC;
    // 0x8003B5DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8003B5E0:
    // 0x8003B5E0: lh          $t2, 0x6($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X6);
    // 0x8003B5E4: lw          $t5, 0x78($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X78);
    // 0x8003B5E8: ori         $t4, $t2, 0x4000
    ctx->r12 = ctx->r10 | 0X4000;
    // 0x8003B5EC: bne         $t5, $zero, L_8003B7F8
    if (ctx->r13 != 0) {
        // 0x8003B5F0: sh          $t4, 0x6($s1)
        MEM_H(0X6, ctx->r17) = ctx->r12;
            goto L_8003B7F8;
    }
    // 0x8003B5F0: sh          $t4, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r12;
    // 0x8003B5F4: lh          $t6, 0x6($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X6);
    // 0x8003B5F8: lbu         $a0, 0x39($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X39);
    // 0x8003B5FC: andi        $t7, $t6, 0xBFFF
    ctx->r15 = ctx->r14 & 0XBFFF;
    // 0x8003B600: sh          $t7, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r15;
    // 0x8003B604: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x8003B608: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8003B60C: sll         $t8, $v1, 1
    ctx->r24 = S32(ctx->r3 << 1);
    // 0x8003B610: subu        $t1, $t9, $t8
    ctx->r9 = SUB32(ctx->r25, ctx->r24);
    // 0x8003B614: slt         $at, $a0, $t1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8003B618: beq         $at, $zero, L_8003B62C
    if (ctx->r1 == 0) {
        // 0x8003B61C: addiu       $t3, $zero, 0xFF
        ctx->r11 = ADD32(0, 0XFF);
            goto L_8003B62C;
    }
    // 0x8003B61C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8003B620: addu        $t0, $a0, $t8
    ctx->r8 = ADD32(ctx->r4, ctx->r24);
    // 0x8003B624: b           L_8003B630
    // 0x8003B628: sb          $t0, 0x39($s1)
    MEM_B(0X39, ctx->r17) = ctx->r8;
        goto L_8003B630;
    // 0x8003B628: sb          $t0, 0x39($s1)
    MEM_B(0X39, ctx->r17) = ctx->r8;
L_8003B62C:
    // 0x8003B62C: sb          $t3, 0x39($s1)
    MEM_B(0X39, ctx->r17) = ctx->r11;
L_8003B630:
    // 0x8003B630: lw          $a0, 0x4C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4C);
    // 0x8003B634: nop

    // 0x8003B638: lbu         $t2, 0x13($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X13);
    // 0x8003B63C: nop

    // 0x8003B640: slti        $at, $t2, 0x2D
    ctx->r1 = SIGNED(ctx->r10) < 0X2D ? 1 : 0;
    // 0x8003B644: beq         $at, $zero, L_8003B738
    if (ctx->r1 == 0) {
        // 0x8003B648: nop
    
            goto L_8003B738;
    }
    // 0x8003B648: nop

    // 0x8003B64C: bne         $s0, $zero, L_8003B738
    if (ctx->r16 != 0) {
        // 0x8003B650: nop
    
            goto L_8003B738;
    }
    // 0x8003B650: nop

    // 0x8003B654: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8003B658: nop

    // 0x8003B65C: beq         $v1, $zero, L_8003B738
    if (ctx->r3 == 0) {
        // 0x8003B660: nop
    
            goto L_8003B738;
    }
    // 0x8003B660: nop

    // 0x8003B664: lw          $t4, 0x40($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X40);
    // 0x8003B668: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003B66C: lb          $t5, 0x54($t4)
    ctx->r13 = MEM_B(ctx->r12, 0X54);
    // 0x8003B670: nop

    // 0x8003B674: bne         $a2, $t5, L_8003B738
    if (ctx->r6 != ctx->r13) {
        // 0x8003B678: nop
    
            goto L_8003B738;
    }
    // 0x8003B678: nop

    // 0x8003B67C: lw          $a0, 0x64($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X64);
    // 0x8003B680: nop

    // 0x8003B684: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x8003B688: nop

    // 0x8003B68C: bne         $t6, $zero, L_8003B738
    if (ctx->r14 != 0) {
        // 0x8003B690: nop
    
            goto L_8003B738;
    }
    // 0x8003B690: nop

    // 0x8003B694: lbu         $t8, 0x48($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X48);
    // 0x8003B698: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8003B69C: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8003B6A0: addu        $v1, $t7, $t9
    ctx->r3 = ADD32(ctx->r15, ctx->r25);
    // 0x8003B6A4: lh          $t1, 0x0($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X0);
    // 0x8003B6A8: nop

    // 0x8003B6AC: addiu       $t0, $t1, 0x1
    ctx->r8 = ADD32(ctx->r9, 0X1);
    // 0x8003B6B0: sh          $t0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r8;
    // 0x8003B6B4: lbu         $t3, 0x48($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X48);
    // 0x8003B6B8: nop

    // 0x8003B6BC: beq         $t3, $zero, L_8003B6DC
    if (ctx->r11 == 0) {
        // 0x8003B6C0: nop
    
            goto L_8003B6DC;
    }
    // 0x8003B6C0: nop

    // 0x8003B6C4: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8003B6C8: nop

    // 0x8003B6CC: lh          $t2, 0x0($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X0);
    // 0x8003B6D0: nop

    // 0x8003B6D4: addiu       $t4, $t2, 0x1
    ctx->r12 = ADD32(ctx->r10, 0X1);
    // 0x8003B6D8: sh          $t4, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r12;
L_8003B6DC:
    // 0x8003B6DC: lbu         $t6, 0x49($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X49);
    // 0x8003B6E0: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x8003B6E4: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8003B6E8: addu        $v1, $t5, $t8
    ctx->r3 = ADD32(ctx->r13, ctx->r24);
    // 0x8003B6EC: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8003B6F0: addiu       $a0, $zero, 0x23D
    ctx->r4 = ADD32(0, 0X23D);
    // 0x8003B6F4: or          $t9, $t7, $a1
    ctx->r25 = ctx->r15 | ctx->r5;
    // 0x8003B6F8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8003B6FC: lw          $a3, 0x14($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X14);
    // 0x8003B700: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x8003B704: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x8003B708: jal         0x80001EA8
    // 0x8003B70C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    sound_play_spatial(rdram, ctx);
        goto after_3;
    // 0x8003B70C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x8003B710: lh          $t3, 0x6($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X6);
    // 0x8003B714: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x8003B718: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8003B71C: ori         $t2, $t3, 0x4000
    ctx->r10 = ctx->r11 | 0X4000;
    // 0x8003B720: sw          $t1, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = ctx->r9;
    // 0x8003B724: sw          $t0, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r8;
    // 0x8003B728: sh          $t2, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r10;
    // 0x8003B72C: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8003B730: jal         0x800B019C
    // 0x8003B734: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    obj_spawn_particle(rdram, ctx);
        goto after_4;
    // 0x8003B734: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
L_8003B738:
    // 0x8003B738: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8003B73C: lw          $s0, 0x64($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X64);
    // 0x8003B740: sb          $zero, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = 0;
    // 0x8003B744: swc1        $f2, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f2.u32l;
    // 0x8003B748: lbu         $t4, 0x39($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X39);
    // 0x8003B74C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8003B750: slti        $at, $t4, 0xFF
    ctx->r1 = SIGNED(ctx->r12) < 0XFF ? 1 : 0;
    // 0x8003B754: beq         $at, $zero, L_8003B764
    if (ctx->r1 == 0) {
        // 0x8003B758: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8003B764;
    }
    // 0x8003B758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003B75C: b           L_8003B770
    // 0x8003B760: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_8003B770;
    // 0x8003B760: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8003B764:
    // 0x8003B764: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003B768: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8003B76C: nop

L_8003B770:
    // 0x8003B770: lbu         $t6, 0xD($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XD);
    // 0x8003B774: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8003B778: bne         $t6, $at, L_8003B7EC
    if (ctx->r14 != ctx->r1) {
        // 0x8003B77C: lw          $a2, 0x2C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X2C);
            goto L_8003B7EC;
    }
    // 0x8003B77C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8003B780: lwc1        $f12, 0xC($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8003B784: lwc1        $f14, 0x10($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8003B788: lw          $a2, 0x14($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X14);
    // 0x8003B78C: jal         0x8001C558
    // 0x8003B790: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    ainode_find_nearest(rdram, ctx);
        goto after_5;
    // 0x8003B790: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x8003B794: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x8003B798: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8003B79C: beq         $a0, $at, L_8003B7F8
    if (ctx->r4 == ctx->r1) {
        // 0x8003B7A0: sb          $v0, 0xD($s0)
        MEM_B(0XD, ctx->r16) = ctx->r2;
            goto L_8003B7F8;
    }
    // 0x8003B7A0: sb          $v0, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r2;
    // 0x8003B7A4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8003B7A8: jal         0x8001CC7C
    // 0x8003B7AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ainode_find_next(rdram, ctx);
        goto after_6;
    // 0x8003B7AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x8003B7B0: lbu         $a1, 0xD($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0XD);
    // 0x8003B7B4: sb          $v0, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r2;
    // 0x8003B7B8: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x8003B7BC: jal         0x8001CC7C
    // 0x8003B7C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ainode_find_next(rdram, ctx);
        goto after_7;
    // 0x8003B7C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x8003B7C4: lbu         $a1, 0xE($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0XE);
    // 0x8003B7C8: sb          $v0, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r2;
    // 0x8003B7CC: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x8003B7D0: jal         0x8001CC7C
    // 0x8003B7D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ainode_find_next(rdram, ctx);
        goto after_8;
    // 0x8003B7D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x8003B7D8: lbu         $t5, 0xD($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0XD);
    // 0x8003B7DC: sb          $v0, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r2;
    // 0x8003B7E0: b           L_8003B7F8
    // 0x8003B7E4: sb          $t5, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r13;
        goto L_8003B7F8;
    // 0x8003B7E4: sb          $t5, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r13;
    // 0x8003B7E8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
L_8003B7EC:
    // 0x8003B7EC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8003B7F0: jal         0x8001C6F8
    // 0x8003B7F4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8001C6C4(rdram, ctx);
        goto after_9;
    // 0x8003B7F4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_9:
L_8003B7F8:
    // 0x8003B7F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8003B7FC:
    // 0x8003B7FC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8003B800: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8003B804: jr          $ra
    // 0x8003B808: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8003B808: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void obj_init_door(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B80C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8003B810: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003B814: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003B818: lb          $a3, 0xC($a1)
    ctx->r7 = MEM_B(ctx->r5, 0XC);
    // 0x8003B81C: lw          $v1, 0x64($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X64);
    // 0x8003B820: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003B824: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003B828: bne         $a3, $at, L_8003B84C
    if (ctx->r7 != ctx->r1) {
        // 0x8003B82C: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_8003B84C;
    }
    // 0x8003B82C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8003B830: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8003B834: jal         0x8000CC20
    // 0x8003B838: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_8000CC20(rdram, ctx);
        goto after_0;
    // 0x8003B838: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8003B83C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8003B840: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8003B844: b           L_8003B86C
    // 0x8003B848: sb          $v0, 0xC($a2)
    MEM_B(0XC, ctx->r6) = ctx->r2;
        goto L_8003B86C;
    // 0x8003B848: sb          $v0, 0xC($a2)
    MEM_B(0XC, ctx->r6) = ctx->r2;
L_8003B84C:
    // 0x8003B84C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003B850: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8003B854: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8003B858: jal         0x8000CBF0
    // 0x8003B85C: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    func_8000CBF0(rdram, ctx);
        goto after_1;
    // 0x8003B85C: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_1:
    // 0x8003B860: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8003B864: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8003B868: nop

L_8003B86C:
    // 0x8003B86C: lb          $t6, 0xC($a2)
    ctx->r14 = MEM_B(ctx->r6, 0XC);
    // 0x8003B870: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003B874: sb          $t6, 0xE($v1)
    MEM_B(0XE, ctx->r3) = ctx->r14;
    // 0x8003B878: lbu         $t7, 0xE($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0XE);
    // 0x8003B87C: lb          $t1, 0xE($v1)
    ctx->r9 = MEM_B(ctx->r3, 0XE);
    // 0x8003B880: sb          $t7, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r15;
    // 0x8003B884: lbu         $t8, 0xD($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0XD);
    // 0x8003B888: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003B88C: sb          $t8, 0x11($v1)
    MEM_B(0X11, ctx->r3) = ctx->r24;
    // 0x8003B890: lbu         $t9, 0xD($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0XD);
    // 0x8003B894: addiu       $a0, $a0, 0x6544
    ctx->r4 = ADD32(ctx->r4, 0X6544);
    // 0x8003B898: sb          $t9, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r25;
    // 0x8003B89C: lbu         $t0, 0xB($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0XB);
    // 0x8003B8A0: bne         $t1, $at, L_8003B8C0
    if (ctx->r9 != ctx->r1) {
        // 0x8003B8A4: sb          $t0, 0x12($v1)
        MEM_B(0X12, ctx->r3) = ctx->r8;
            goto L_8003B8C0;
    }
    // 0x8003B8A4: sb          $t0, 0x12($v1)
    MEM_B(0X12, ctx->r3) = ctx->r8;
    // 0x8003B8A8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8003B8AC: jal         0x800CA2B4
    // 0x8003B8B0: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    rmonPrintf_recomp(rdram, ctx);
        goto after_2;
    // 0x8003B8B0: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_2:
    // 0x8003B8B4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8003B8B8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8003B8BC: nop

L_8003B8C0:
    // 0x8003B8C0: lbu         $t2, 0xA($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0XA);
    // 0x8003B8C4: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003B8C8: sb          $t2, 0x3A($s0)
    MEM_B(0X3A, ctx->r16) = ctx->r10;
    // 0x8003B8CC: lbu         $t4, 0x8($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X8);
    // 0x8003B8D0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8003B8D4: sll         $t5, $t4, 10
    ctx->r13 = S32(ctx->r12 << 10);
    // 0x8003B8D8: sh          $t5, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r13;
    // 0x8003B8DC: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x8003B8E0: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x8003B8E4: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x8003B8E8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003B8EC: sw          $t6, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r14;
    // 0x8003B8F0: lbu         $t7, 0x9($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X9);
    // 0x8003B8F4: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x8003B8F8: andi        $t8, $t7, 0x3F
    ctx->r24 = ctx->r15 & 0X3F;
    // 0x8003B8FC: sll         $t9, $t8, 10
    ctx->r25 = S32(ctx->r24 << 10);
    // 0x8003B900: sw          $t9, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r25;
    // 0x8003B904: lbu         $t1, 0x12($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X12);
    // 0x8003B908: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003B90C: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x8003B910: nop

    // 0x8003B914: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8003B918: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8003B91C: nop

    // 0x8003B920: bc1f        L_8003B930
    if (!c1cs) {
        // 0x8003B924: nop
    
            goto L_8003B930;
    }
    // 0x8003B924: nop

    // 0x8003B928: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8003B92C: nop

L_8003B930:
    // 0x8003B930: div.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8003B934: lw          $t2, 0x40($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X40);
    // 0x8003B938: addiu       $t5, $zero, 0x21
    ctx->r13 = ADD32(0, 0X21);
    // 0x8003B93C: lwc1        $f10, 0xC($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0XC);
    // 0x8003B940: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8003B944: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x8003B948: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8003B94C: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    // 0x8003B950: lbu         $t3, 0xF($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0XF);
    // 0x8003B954: nop

    // 0x8003B958: sb          $t3, 0x13($v1)
    MEM_B(0X13, ctx->r3) = ctx->r11;
    // 0x8003B95C: lb          $t4, 0x11($a2)
    ctx->r12 = MEM_B(ctx->r6, 0X11);
    // 0x8003B960: nop

    // 0x8003B964: sb          $t4, 0x14($v1)
    MEM_B(0X14, ctx->r3) = ctx->r12;
    // 0x8003B968: lw          $t6, 0x4C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4C);
    // 0x8003B96C: nop

    // 0x8003B970: sh          $t5, 0x14($t6)
    MEM_H(0X14, ctx->r14) = ctx->r13;
    // 0x8003B974: lw          $t8, 0x4C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4C);
    // 0x8003B978: nop

    // 0x8003B97C: sb          $t7, 0x11($t8)
    MEM_B(0X11, ctx->r24) = ctx->r15;
    // 0x8003B980: lw          $t0, 0x4C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4C);
    // 0x8003B984: nop

    // 0x8003B988: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x8003B98C: lw          $t1, 0x4C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4C);
    // 0x8003B990: nop

    // 0x8003B994: sb          $zero, 0x12($t1)
    MEM_B(0X12, ctx->r9) = 0;
    // 0x8003B998: lw          $t3, 0x40($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X40);
    // 0x8003B99C: lb          $t2, 0x3A($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X3A);
    // 0x8003B9A0: lb          $t4, 0x55($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X55);
    // 0x8003B9A4: nop

    // 0x8003B9A8: slt         $at, $t2, $t4
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8003B9AC: bne         $at, $zero, L_8003B9BC
    if (ctx->r1 != 0) {
        // 0x8003B9B0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8003B9BC;
    }
    // 0x8003B9B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003B9B4: sb          $zero, 0x3A($s0)
    MEM_B(0X3A, ctx->r16) = 0;
    // 0x8003B9B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8003B9BC:
    // 0x8003B9BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003B9C0: jr          $ra
    // 0x8003B9C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8003B9C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void obj_loop_door(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B9C8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8003B9CC: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8003B9D0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003B9D4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8003B9D8: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8003B9DC: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x8003B9E0: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003B9E4: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x8003B9E8: lw          $t8, 0x300($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X300);
    // 0x8003B9EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003B9F0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8003B9F4: bne         $t8, $zero, L_8003BA14
    if (ctx->r24 != 0) {
        // 0x8003B9F8: sw          $t6, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r14;
            goto L_8003BA14;
    }
    // 0x8003B9F8: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x8003B9FC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003BA00: lwc1        $f9, 0x66F8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X66F8);
    // 0x8003BA04: lwc1        $f8, 0x66FC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X66FC);
    // 0x8003BA08: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8003BA0C: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8003BA10: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
L_8003BA14:
    // 0x8003BA14: jal         0x8006ECD0
    // 0x8003BA18: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x8003BA18: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x8003BA1C: lbu         $t3, 0x49($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X49);
    // 0x8003BA20: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x8003BA24: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
    // 0x8003BA28: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8003BA2C: lb          $v1, 0xE($t0)
    ctx->r3 = MEM_B(ctx->r8, 0XE);
    // 0x8003BA30: addu        $t5, $t9, $t4
    ctx->r13 = ADD32(ctx->r25, ctx->r12);
    // 0x8003BA34: lw          $a1, 0x0($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X0);
    // 0x8003BA38: bltz        $v1, L_8003C1D4
    if (SIGNED(ctx->r3) < 0) {
        // 0x8003BA3C: or          $t1, $v0, $zero
        ctx->r9 = ctx->r2 | 0;
            goto L_8003C1D4;
    }
    // 0x8003BA3C: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x8003BA40: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x8003BA44: sllv        $t7, $t6, $v1
    ctx->r15 = S32(ctx->r14 << (ctx->r3 & 31));
    // 0x8003BA48: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    // 0x8003BA4C: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x8003BA50: nop

    // 0x8003BA54: lbu         $a0, 0x13($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X13);
    // 0x8003BA58: nop

    // 0x8003BA5C: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8003BA60: lbu         $t8, 0xF($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0XF);
    // 0x8003BA64: nop

    // 0x8003BA68: andi        $t3, $t8, 0x1
    ctx->r11 = ctx->r24 & 0X1;
    // 0x8003BA6C: bne         $t3, $zero, L_8003BA7C
    if (ctx->r11 != 0) {
        // 0x8003BA70: lw          $t9, 0x54($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X54);
            goto L_8003BA7C;
    }
    // 0x8003BA70: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8003BA74: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
    // 0x8003BA78: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
L_8003BA7C:
    // 0x8003BA7C: nop

    // 0x8003BA80: and         $t4, $a1, $t9
    ctx->r12 = ctx->r5 & ctx->r25;
    // 0x8003BA84: bne         $t4, $zero, L_8003BBC8
    if (ctx->r12 != 0) {
        // 0x8003BA88: sw          $t4, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r12;
            goto L_8003BBC8;
    }
    // 0x8003BA88: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x8003BA8C: lbu         $t6, 0x12($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X12);
    // 0x8003BA90: nop

    // 0x8003BA94: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8003BA98: beq         $at, $zero, L_8003BBC8
    if (ctx->r1 == 0) {
        // 0x8003BA9C: nop
    
            goto L_8003BBC8;
    }
    // 0x8003BA9C: nop

    // 0x8003BAA0: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8003BAA4: nop

    // 0x8003BAA8: beq         $v1, $zero, L_8003BBC8
    if (ctx->r3 == 0) {
        // 0x8003BAAC: nop
    
            goto L_8003BBC8;
    }
    // 0x8003BAAC: nop

    // 0x8003BAB0: lw          $t7, 0x40($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X40);
    // 0x8003BAB4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003BAB8: lb          $t8, 0x54($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X54);
    // 0x8003BABC: nop

    // 0x8003BAC0: bne         $a2, $t8, L_8003BBC8
    if (ctx->r6 != ctx->r24) {
        // 0x8003BAC4: nop
    
            goto L_8003BBC8;
    }
    // 0x8003BAC4: nop

    // 0x8003BAC8: lw          $v0, 0x64($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X64);
    // 0x8003BACC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003BAD0: lh          $t3, 0x0($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X0);
    // 0x8003BAD4: nop

    // 0x8003BAD8: beq         $t3, $at, L_8003BBA8
    if (ctx->r11 == ctx->r1) {
        // 0x8003BADC: nop
    
            goto L_8003BBA8;
    }
    // 0x8003BADC: nop

    // 0x8003BAE0: lw          $t9, 0x5C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X5C);
    // 0x8003BAE4: nop

    // 0x8003BAE8: lw          $t4, 0x100($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X100);
    // 0x8003BAEC: nop

    // 0x8003BAF0: bne         $v1, $t4, L_8003BBA8
    if (ctx->r3 != ctx->r12) {
        // 0x8003BAF4: nop
    
            goto L_8003BBA8;
    }
    // 0x8003BAF4: nop

    // 0x8003BAF8: lb          $t5, 0x13($t0)
    ctx->r13 = MEM_B(ctx->r8, 0X13);
    // 0x8003BAFC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003BB00: beq         $t5, $at, L_8003BBA4
    if (ctx->r13 == ctx->r1) {
        // 0x8003BB04: addiu       $t3, $zero, 0x12C
        ctx->r11 = ADD32(0, 0X12C);
            goto L_8003BBA4;
    }
    // 0x8003BB04: addiu       $t3, $zero, 0x12C
    ctx->r11 = ADD32(0, 0X12C);
    // 0x8003BB08: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x8003BB0C: jal         0x800C3958
    // 0x8003BB10: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    textbox_visible(rdram, ctx);
        goto after_1;
    // 0x8003BB10: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    after_1:
    // 0x8003BB14: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8003BB18: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8003BB1C: bne         $v0, $zero, L_8003BBA4
    if (ctx->r2 != 0) {
        // 0x8003BB20: addiu       $t3, $zero, 0x12C
        ctx->r11 = ADD32(0, 0X12C);
            goto L_8003BBA4;
    }
    // 0x8003BB20: addiu       $t3, $zero, 0x12C
    ctx->r11 = ADD32(0, 0X12C);
    // 0x8003BB24: lh          $t6, 0xC($t0)
    ctx->r14 = MEM_H(ctx->r8, 0XC);
    // 0x8003BB28: addiu       $a0, $zero, -0x8
    ctx->r4 = ADD32(0, -0X8);
    // 0x8003BB2C: bne         $t6, $zero, L_8003BBA4
    if (ctx->r14 != 0) {
        // 0x8003BB30: addiu       $t3, $zero, 0x12C
        ctx->r11 = ADD32(0, 0X12C);
            goto L_8003BBA4;
    }
    // 0x8003BB30: addiu       $t3, $zero, 0x12C
    ctx->r11 = ADD32(0, 0X12C);
    // 0x8003BB34: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x8003BB38: jal         0x80000C98
    // 0x8003BB3C: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    music_fade(rdram, ctx);
        goto after_2;
    // 0x8003BB3C: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    after_2:
    // 0x8003BB40: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8003BB44: addiu       $t7, $zero, 0x8C
    ctx->r15 = ADD32(0, 0X8C);
    // 0x8003BB48: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x8003BB4C: jal         0x80000C38
    // 0x8003BB50: sw          $t7, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r15;
    music_jingle_voicelimit_set(rdram, ctx);
        goto after_3;
    // 0x8003BB50: sw          $t7, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r15;
    after_3:
    // 0x8003BB54: jal         0x80008140
    // 0x8003BB58: nop

    audspat_jingle_off(rdram, ctx);
        goto after_4;
    // 0x8003BB58: nop

    after_4:
    // 0x8003BB5C: jal         0x80001BC0
    // 0x8003BB60: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    music_jingle_play(rdram, ctx);
        goto after_5;
    // 0x8003BB60: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_5:
    // 0x8003BB64: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8003BB68: nop

    // 0x8003BB6C: lbu         $a0, 0x10($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X10);
    // 0x8003BB70: jal         0x800C3698
    // 0x8003BB74: nop

    set_textbox_display_value(rdram, ctx);
        goto after_6;
    // 0x8003BB74: nop

    after_6:
    // 0x8003BB78: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8003BB7C: nop

    // 0x8003BB80: lb          $a0, 0x13($t0)
    ctx->r4 = MEM_B(ctx->r8, 0X13);
    // 0x8003BB84: nop

    // 0x8003BB88: andi        $t8, $a0, 0xFF
    ctx->r24 = ctx->r4 & 0XFF;
    // 0x8003BB8C: jal         0x800C3744
    // 0x8003BB90: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    set_current_text(rdram, ctx);
        goto after_7;
    // 0x8003BB90: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_7:
    // 0x8003BB94: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8003BB98: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8003BB9C: nop

    // 0x8003BBA0: addiu       $t3, $zero, 0x12C
    ctx->r11 = ADD32(0, 0X12C);
L_8003BBA4:
    // 0x8003BBA4: sh          $t3, 0xC($t0)
    MEM_H(0XC, ctx->r8) = ctx->r11;
L_8003BBA8:
    // 0x8003BBA8: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x8003BBAC: jal         0x800C3958
    // 0x8003BBB0: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    textbox_visible(rdram, ctx);
        goto after_8;
    // 0x8003BBB0: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    after_8:
    // 0x8003BBB4: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8003BBB8: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8003BBBC: beq         $v0, $zero, L_8003BBC8
    if (ctx->r2 == 0) {
        // 0x8003BBC0: addiu       $t9, $zero, 0x12C
        ctx->r25 = ADD32(0, 0X12C);
            goto L_8003BBC8;
    }
    // 0x8003BBC0: addiu       $t9, $zero, 0x12C
    ctx->r25 = ADD32(0, 0X12C);
    // 0x8003BBC4: sh          $t9, 0xC($t0)
    MEM_H(0XC, ctx->r8) = ctx->r25;
L_8003BBC8:
    // 0x8003BBC8: lw          $t4, 0x8($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X8);
    // 0x8003BBCC: nop

    // 0x8003BBD0: beq         $t4, $zero, L_8003BC40
    if (ctx->r12 == 0) {
        // 0x8003BBD4: nop
    
            goto L_8003BC40;
    }
    // 0x8003BBD4: nop

    // 0x8003BBD8: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x8003BBDC: jal         0x80001C08
    // 0x8003BBE0: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    music_jingle_playing(rdram, ctx);
        goto after_9;
    // 0x8003BBE0: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    after_9:
    // 0x8003BBE4: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8003BBE8: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8003BBEC: bne         $v0, $zero, L_8003BC40
    if (ctx->r2 != 0) {
        // 0x8003BBF0: nop
    
            goto L_8003BC40;
    }
    // 0x8003BBF0: nop

    // 0x8003BBF4: lw          $v1, 0x64($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X64);
    // 0x8003BBF8: lw          $v0, 0x8($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X8);
    // 0x8003BBFC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8003BC00: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003BC04: beq         $at, $zero, L_8003BC14
    if (ctx->r1 == 0) {
        // 0x8003BC08: subu        $t5, $v0, $v1
        ctx->r13 = SUB32(ctx->r2, ctx->r3);
            goto L_8003BC14;
    }
    // 0x8003BC08: subu        $t5, $v0, $v1
    ctx->r13 = SUB32(ctx->r2, ctx->r3);
    // 0x8003BC0C: b           L_8003BC40
    // 0x8003BC10: sw          $t5, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r13;
        goto L_8003BC40;
    // 0x8003BC10: sw          $t5, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r13;
L_8003BC14:
    // 0x8003BC14: sw          $zero, 0x8($t0)
    MEM_W(0X8, ctx->r8) = 0;
    // 0x8003BC18: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x8003BC1C: jal         0x80000C98
    // 0x8003BC20: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    music_fade(rdram, ctx);
        goto after_10;
    // 0x8003BC20: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    after_10:
    // 0x8003BC24: jal         0x80000C38
    // 0x8003BC28: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    music_jingle_voicelimit_set(rdram, ctx);
        goto after_11;
    // 0x8003BC28: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_11:
    // 0x8003BC2C: jal         0x80008168
    // 0x8003BC30: nop

    audspat_jingle_on(rdram, ctx);
        goto after_12;
    // 0x8003BC30: nop

    after_12:
    // 0x8003BC34: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8003BC38: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8003BC3C: nop

L_8003BC40:
    // 0x8003BC40: lh          $v0, 0xC($t0)
    ctx->r2 = MEM_H(ctx->r8, 0XC);
    // 0x8003BC44: lw          $v1, 0x64($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X64);
    // 0x8003BC48: blez        $v0, L_8003BC5C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8003BC4C: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_8003BC5C;
    }
    // 0x8003BC4C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003BC50: subu        $t6, $v0, $v1
    ctx->r14 = SUB32(ctx->r2, ctx->r3);
    // 0x8003BC54: b           L_8003BC60
    // 0x8003BC58: sh          $t6, 0xC($t0)
    MEM_H(0XC, ctx->r8) = ctx->r14;
        goto L_8003BC60;
    // 0x8003BC58: sh          $t6, 0xC($t0)
    MEM_H(0XC, ctx->r8) = ctx->r14;
L_8003BC5C:
    // 0x8003BC5C: sh          $zero, 0xC($t0)
    MEM_H(0XC, ctx->r8) = 0;
L_8003BC60:
    // 0x8003BC60: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x8003BC64: lbu         $t8, 0x12($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X12);
    // 0x8003BC68: lbu         $t7, 0x13($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X13);
    // 0x8003BC6C: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8003BC70: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8003BC74: beq         $at, $zero, L_8003BCD8
    if (ctx->r1 == 0) {
        // 0x8003BC78: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8003BCD8;
    }
    // 0x8003BC78: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8003BC7C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8003BC80: nop

    // 0x8003BC84: beq         $v1, $zero, L_8003BCD8
    if (ctx->r3 == 0) {
        // 0x8003BC88: nop
    
            goto L_8003BCD8;
    }
    // 0x8003BC88: nop

    // 0x8003BC8C: lw          $t3, 0x40($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X40);
    // 0x8003BC90: nop

    // 0x8003BC94: lb          $t9, 0x54($t3)
    ctx->r25 = MEM_B(ctx->r11, 0X54);
    // 0x8003BC98: nop

    // 0x8003BC9C: bne         $a2, $t9, L_8003BCD8
    if (ctx->r6 != ctx->r25) {
        // 0x8003BCA0: nop
    
            goto L_8003BCD8;
    }
    // 0x8003BCA0: nop

    // 0x8003BCA4: lw          $v0, 0x64($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X64);
    // 0x8003BCA8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003BCAC: lb          $a0, 0x1D6($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X1D6);
    // 0x8003BCB0: nop

    // 0x8003BCB4: beq         $a0, $a2, L_8003BCCC
    if (ctx->r4 == ctx->r6) {
        // 0x8003BCB8: nop
    
            goto L_8003BCCC;
    }
    // 0x8003BCB8: nop

    // 0x8003BCBC: beq         $a0, $at, L_8003BCD8
    if (ctx->r4 == ctx->r1) {
        // 0x8003BCC0: addiu       $a0, $zero, 0x4
        ctx->r4 = ADD32(0, 0X4);
            goto L_8003BCD8;
    }
    // 0x8003BCC0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8003BCC4: b           L_8003BCD8
    // 0x8003BCC8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
        goto L_8003BCD8;
    // 0x8003BCC8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_8003BCCC:
    // 0x8003BCCC: b           L_8003BCD8
    // 0x8003BCD0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
        goto L_8003BCD8;
    // 0x8003BCD0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8003BCD4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
L_8003BCD8:
    // 0x8003BCD8: lbu         $t4, 0x10($t2)
    ctx->r12 = MEM_BU(ctx->r10, 0X10);
    // 0x8003BCDC: lbu         $v0, 0x0($t2)
    ctx->r2 = MEM_BU(ctx->r10, 0X0);
    // 0x8003BCE0: addiu       $at, $zero, 0x87
    ctx->r1 = ADD32(0, 0X87);
    // 0x8003BCE4: beq         $v0, $at, L_8003BCF8
    if (ctx->r2 == ctx->r1) {
        // 0x8003BCE8: and         $a0, $a0, $t4
        ctx->r4 = ctx->r4 & ctx->r12;
            goto L_8003BCF8;
    }
    // 0x8003BCE8: and         $a0, $a0, $t4
    ctx->r4 = ctx->r4 & ctx->r12;
    // 0x8003BCEC: addiu       $at, $zero, 0xD7
    ctx->r1 = ADD32(0, 0XD7);
    // 0x8003BCF0: bne         $v0, $at, L_8003BD20
    if (ctx->r2 != ctx->r1) {
        // 0x8003BCF4: nop
    
            goto L_8003BD20;
    }
    // 0x8003BCF4: nop

L_8003BCF8:
    // 0x8003BCF8: sw          $a0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r4;
    // 0x8003BCFC: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x8003BD00: jal         0x800235F4
    // 0x8003BD04: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    obj_door_override(rdram, ctx);
        goto after_13;
    // 0x8003BD04: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    after_13:
    // 0x8003BD08: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8003BD0C: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8003BD10: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8003BD14: beq         $v0, $zero, L_8003BD20
    if (ctx->r2 == 0) {
        // 0x8003BD18: nop
    
            goto L_8003BD20;
    }
    // 0x8003BD18: nop

    // 0x8003BD1C: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
L_8003BD20:
    // 0x8003BD20: lb          $t5, 0x15($t0)
    ctx->r13 = MEM_B(ctx->r8, 0X15);
    // 0x8003BD24: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8003BD28: bne         $t5, $zero, L_8003BD74
    if (ctx->r13 != 0) {
        // 0x8003BD2C: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_8003BD74;
    }
    // 0x8003BD2C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003BD30: lbu         $v0, 0x12($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X12);
    // 0x8003BD34: bne         $a0, $zero, L_8003BD60
    if (ctx->r4 != 0) {
        // 0x8003BD38: lw          $t8, 0x50($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X50);
            goto L_8003BD60;
    }
    // 0x8003BD38: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8003BD3C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8003BD40: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8003BD44: beq         $t6, $zero, L_8003BD5C
    if (ctx->r14 == 0) {
        // 0x8003BD48: slt         $at, $t7, $v0
        ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8003BD5C;
    }
    // 0x8003BD48: slt         $at, $t7, $v0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003BD4C: beq         $at, $zero, L_8003BD60
    if (ctx->r1 == 0) {
        // 0x8003BD50: lw          $t8, 0x50($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X50);
            goto L_8003BD60;
    }
    // 0x8003BD50: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8003BD54: b           L_8003BD74
    // 0x8003BD58: sb          $a2, 0x15($t0)
    MEM_B(0X15, ctx->r8) = ctx->r6;
        goto L_8003BD74;
    // 0x8003BD58: sb          $a2, 0x15($t0)
    MEM_B(0X15, ctx->r8) = ctx->r6;
L_8003BD5C:
    // 0x8003BD5C: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
L_8003BD60:
    // 0x8003BD60: addiu       $t3, $v0, 0xA
    ctx->r11 = ADD32(ctx->r2, 0XA);
    // 0x8003BD64: slt         $at, $t3, $t8
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8003BD68: beq         $at, $zero, L_8003BD74
    if (ctx->r1 == 0) {
        // 0x8003BD6C: addiu       $t9, $zero, -0x1
        ctx->r25 = ADD32(0, -0X1);
            goto L_8003BD74;
    }
    // 0x8003BD6C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8003BD70: sb          $t9, 0x15($t0)
    MEM_B(0X15, ctx->r8) = ctx->r25;
L_8003BD74:
    // 0x8003BD74: lbu         $t4, 0xF($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0XF);
    // 0x8003BD78: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8003BD7C: andi        $t5, $t4, 0x2
    ctx->r13 = ctx->r12 & 0X2;
    // 0x8003BD80: beq         $t5, $zero, L_8003BEFC
    if (ctx->r13 == 0) {
        // 0x8003BD84: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8003BEFC;
    }
    // 0x8003BD84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003BD88: beq         $t6, $zero, L_8003BE58
    if (ctx->r14 == 0) {
        // 0x8003BD8C: nop
    
            goto L_8003BE58;
    }
    // 0x8003BD8C: nop

    // 0x8003BD90: lbu         $t7, 0x0($t2)
    ctx->r15 = MEM_BU(ctx->r10, 0X0);
    // 0x8003BD94: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x8003BD98: bne         $t7, $at, L_8003BE58
    if (ctx->r15 != ctx->r1) {
        // 0x8003BD9C: nop
    
            goto L_8003BE58;
    }
    // 0x8003BD9C: nop

    // 0x8003BDA0: lb          $t3, 0x14($t2)
    ctx->r11 = MEM_B(ctx->r10, 0X14);
    // 0x8003BDA4: lw          $t8, 0x4($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X4);
    // 0x8003BDA8: sll         $t9, $t3, 2
    ctx->r25 = S32(ctx->r11 << 2);
    // 0x8003BDAC: addu        $t4, $t8, $t9
    ctx->r12 = ADD32(ctx->r24, ctx->r25);
    // 0x8003BDB0: lw          $v0, 0x0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X0);
    // 0x8003BDB4: nop

    // 0x8003BDB8: andi        $t5, $v0, 0x2
    ctx->r13 = ctx->r2 & 0X2;
    // 0x8003BDBC: beq         $t5, $zero, L_8003BE4C
    if (ctx->r13 == 0) {
        // 0x8003BDC0: andi        $t6, $v0, 0x4
        ctx->r14 = ctx->r2 & 0X4;
            goto L_8003BE4C;
    }
    // 0x8003BDC0: andi        $t6, $v0, 0x4
    ctx->r14 = ctx->r2 & 0X4;
    // 0x8003BDC4: lbu         $v0, 0x48($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X48);
    // 0x8003BDC8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8003BDCC: beq         $v0, $at, L_8003BDE8
    if (ctx->r2 == ctx->r1) {
        // 0x8003BDD0: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8003BDE8;
    }
    // 0x8003BDD0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8003BDD4: lhu         $t6, 0xC($t1)
    ctx->r14 = MEM_HU(ctx->r9, 0XC);
    // 0x8003BDD8: sllv        $t3, $t7, $v0
    ctx->r11 = S32(ctx->r15 << (ctx->r2 & 31));
    // 0x8003BDDC: and         $t8, $t6, $t3
    ctx->r24 = ctx->r14 & ctx->r11;
    // 0x8003BDE0: beq         $t8, $zero, L_8003BE2C
    if (ctx->r24 == 0) {
        // 0x8003BDE4: nop
    
            goto L_8003BE2C;
    }
    // 0x8003BDE4: nop

L_8003BDE8:
    // 0x8003BDE8: lbu         $t9, 0x15($t2)
    ctx->r25 = MEM_BU(ctx->r10, 0X15);
    // 0x8003BDEC: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8003BDF0: andi        $t4, $t9, 0xFF
    ctx->r12 = ctx->r25 & 0XFF;
    // 0x8003BDF4: slti        $at, $t4, 0xA
    ctx->r1 = SIGNED(ctx->r12) < 0XA ? 1 : 0;
    // 0x8003BDF8: bne         $at, $zero, L_8003BE0C
    if (ctx->r1 != 0) {
        // 0x8003BDFC: sb          $t9, 0x10($t0)
        MEM_B(0X10, ctx->r8) = ctx->r25;
            goto L_8003BE0C;
    }
    // 0x8003BDFC: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x8003BE00: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x8003BE04: b           L_8003BE10
    // 0x8003BE08: sb          $t5, 0x3A($s0)
    MEM_B(0X3A, ctx->r16) = ctx->r13;
        goto L_8003BE10;
    // 0x8003BE08: sb          $t5, 0x3A($s0)
    MEM_B(0X3A, ctx->r16) = ctx->r13;
L_8003BE0C:
    // 0x8003BE0C: sb          $t7, 0x3A($s0)
    MEM_B(0X3A, ctx->r16) = ctx->r15;
L_8003BE10:
    // 0x8003BE10: lb          $t3, 0x14($t2)
    ctx->r11 = MEM_B(ctx->r10, 0X14);
    // 0x8003BE14: lw          $t6, 0x4($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X4);
    // 0x8003BE18: sll         $t8, $t3, 2
    ctx->r24 = S32(ctx->r11 << 2);
    // 0x8003BE1C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8003BE20: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x8003BE24: b           L_8003BE4C
    // 0x8003BE28: andi        $t6, $v0, 0x4
    ctx->r14 = ctx->r2 & 0X4;
        goto L_8003BE4C;
    // 0x8003BE28: andi        $t6, $v0, 0x4
    ctx->r14 = ctx->r2 & 0X4;
L_8003BE2C:
    // 0x8003BE2C: sb          $zero, 0x3A($s0)
    MEM_B(0X3A, ctx->r16) = 0;
    // 0x8003BE30: lb          $t5, 0x14($t2)
    ctx->r13 = MEM_B(ctx->r10, 0X14);
    // 0x8003BE34: lw          $t4, 0x4($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X4);
    // 0x8003BE38: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8003BE3C: addu        $t3, $t4, $t7
    ctx->r11 = ADD32(ctx->r12, ctx->r15);
    // 0x8003BE40: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x8003BE44: nop

    // 0x8003BE48: andi        $t6, $v0, 0x4
    ctx->r14 = ctx->r2 & 0X4;
L_8003BE4C:
    // 0x8003BE4C: beq         $t6, $zero, L_8003BE58
    if (ctx->r14 == 0) {
        // 0x8003BE50: nop
    
            goto L_8003BE58;
    }
    // 0x8003BE50: nop

    // 0x8003BE54: sb          $a2, 0x3A($s0)
    MEM_B(0X3A, ctx->r16) = ctx->r6;
L_8003BE58:
    // 0x8003BE58: lb          $v1, 0x15($t0)
    ctx->r3 = MEM_B(ctx->r8, 0X15);
    // 0x8003BE5C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003BE60: bne         $a2, $v1, L_8003BEB8
    if (ctx->r6 != ctx->r3) {
        // 0x8003BE64: nop
    
            goto L_8003BEB8;
    }
    // 0x8003BE64: nop

    // 0x8003BE68: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003BE6C: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8003BE70: lwc1        $f7, 0x6700($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6700);
    // 0x8003BE74: lwc1        $f6, 0x6704($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6704);
    // 0x8003BE78: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003BE7C: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8003BE80: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x8003BE84: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8003BE88: cvt.d.s     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f2.d = CVT_D_S(ctx->f16.fl);
    // 0x8003BE8C: c.lt.d      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.d < ctx->f8.d;
    // 0x8003BE90: nop

    // 0x8003BE94: bc1f        L_8003C028
    if (!c1cs) {
        // 0x8003BE98: nop
    
            goto L_8003C028;
    }
    // 0x8003BE98: nop

    // 0x8003BE9C: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x8003BEA0: add.d       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = ctx->f0.d + ctx->f0.d;
    // 0x8003BEA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8003BEA8: add.d       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f2.d + ctx->f16.d;
    // 0x8003BEAC: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8003BEB0: b           L_8003C028
    // 0x8003BEB4: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
        goto L_8003C028;
    // 0x8003BEB4: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
L_8003BEB8:
    // 0x8003BEB8: bne         $v1, $at, L_8003C028
    if (ctx->r3 != ctx->r1) {
        // 0x8003BEBC: nop
    
            goto L_8003C028;
    }
    // 0x8003BEBC: nop

    // 0x8003BEC0: lwc1        $f2, 0x10($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003BEC4: lwc1        $f6, 0x0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8003BEC8: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8003BECC: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x8003BED0: nop

    // 0x8003BED4: bc1f        L_8003C028
    if (!c1cs) {
        // 0x8003BED8: nop
    
            goto L_8003C028;
    }
    // 0x8003BED8: nop

    // 0x8003BEDC: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x8003BEE0: add.d       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = ctx->f0.d + ctx->f0.d;
    // 0x8003BEE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8003BEE8: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x8003BEEC: sub.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d - ctx->f16.d;
    // 0x8003BEF0: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8003BEF4: b           L_8003C028
    // 0x8003BEF8: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
        goto L_8003C028;
    // 0x8003BEF8: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
L_8003BEFC:
    // 0x8003BEFC: lbu         $t8, 0x0($t2)
    ctx->r24 = MEM_BU(ctx->r10, 0X0);
    // 0x8003BF00: addiu       $at, $zero, 0xD7
    ctx->r1 = ADD32(0, 0XD7);
    // 0x8003BF04: bne         $t8, $at, L_8003BF9C
    if (ctx->r24 != ctx->r1) {
        // 0x8003BF08: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8003BF9C;
    }
    // 0x8003BF08: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8003BF0C: sb          $zero, 0x3A($s0)
    MEM_B(0X3A, ctx->r16) = 0;
    // 0x8003BF10: lbu         $a0, 0x48($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X48);
    // 0x8003BF14: lhu         $v1, 0xC($t1)
    ctx->r3 = MEM_HU(ctx->r9, 0XC);
    // 0x8003BF18: sllv        $t5, $t9, $a0
    ctx->r13 = S32(ctx->r25 << (ctx->r4 & 31));
    // 0x8003BF1C: and         $t4, $v1, $t5
    ctx->r12 = ctx->r3 & ctx->r13;
    // 0x8003BF20: beq         $t4, $zero, L_8003BF54
    if (ctx->r12 == 0) {
        // 0x8003BF24: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8003BF54;
    }
    // 0x8003BF24: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8003BF28: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x8003BF2C: sll         $t3, $a0, 1
    ctx->r11 = S32(ctx->r4 << 1);
    // 0x8003BF30: addu        $t6, $t7, $t3
    ctx->r14 = ADD32(ctx->r15, ctx->r11);
    // 0x8003BF34: lh          $t8, 0x0($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X0);
    // 0x8003BF38: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8003BF3C: bne         $t8, $at, L_8003BF58
    if (ctx->r24 != ctx->r1) {
        // 0x8003BF40: addiu       $t9, $v0, 0x6
        ctx->r25 = ADD32(ctx->r2, 0X6);
            goto L_8003BF58;
    }
    // 0x8003BF40: addiu       $t9, $v0, 0x6
    ctx->r25 = ADD32(ctx->r2, 0X6);
    // 0x8003BF44: sb          $a2, 0x3A($s0)
    MEM_B(0X3A, ctx->r16) = ctx->r6;
    // 0x8003BF48: lhu         $v1, 0xC($t1)
    ctx->r3 = MEM_HU(ctx->r9, 0XC);
    // 0x8003BF4C: lbu         $v0, 0x48($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X48);
    // 0x8003BF50: nop

L_8003BF54:
    // 0x8003BF54: addiu       $t9, $v0, 0x6
    ctx->r25 = ADD32(ctx->r2, 0X6);
L_8003BF58:
    // 0x8003BF58: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8003BF5C: sllv        $t4, $t5, $t9
    ctx->r12 = S32(ctx->r13 << (ctx->r25 & 31));
    // 0x8003BF60: and         $t7, $v1, $t4
    ctx->r15 = ctx->r3 & ctx->r12;
    // 0x8003BF64: beq         $t7, $zero, L_8003BF7C
    if (ctx->r15 == 0) {
        // 0x8003BF68: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8003BF7C;
    }
    // 0x8003BF68: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8003BF6C: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8003BF70: sb          $t3, 0x3A($s0)
    MEM_B(0X3A, ctx->r16) = ctx->r11;
    // 0x8003BF74: lbu         $v0, 0x48($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X48);
    // 0x8003BF78: nop

L_8003BF7C:
    // 0x8003BF7C: bne         $v0, $at, L_8003BF9C
    if (ctx->r2 != ctx->r1) {
        // 0x8003BF80: nop
    
            goto L_8003BF9C;
    }
    // 0x8003BF80: nop

    // 0x8003BF84: lb          $v0, 0x3A($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X3A);
    // 0x8003BF88: nop

    // 0x8003BF8C: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8003BF90: beq         $at, $zero, L_8003BF9C
    if (ctx->r1 == 0) {
        // 0x8003BF94: addiu       $t6, $v0, 0x1
        ctx->r14 = ADD32(ctx->r2, 0X1);
            goto L_8003BF9C;
    }
    // 0x8003BF94: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8003BF98: sb          $t6, 0x3A($s0)
    MEM_B(0X3A, ctx->r16) = ctx->r14;
L_8003BF9C:
    // 0x8003BF9C: lb          $v1, 0x15($t0)
    ctx->r3 = MEM_B(ctx->r8, 0X15);
    // 0x8003BFA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003BFA4: bne         $a2, $v1, L_8003BFC8
    if (ctx->r6 != ctx->r3) {
        // 0x8003BFA8: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_8003BFC8;
    }
    // 0x8003BFA8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003BFAC: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x8003BFB0: lw          $t5, 0x7C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X7C);
    // 0x8003BFB4: nop

    // 0x8003BFB8: subu        $v0, $t8, $t5
    ctx->r2 = SUB32(ctx->r24, ctx->r13);
    // 0x8003BFBC: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x8003BFC0: b           L_8003BFE8
    // 0x8003BFC4: sra         $v0, $t9, 16
    ctx->r2 = S32(SIGNED(ctx->r25) >> 16);
        goto L_8003BFE8;
    // 0x8003BFC4: sra         $v0, $t9, 16
    ctx->r2 = S32(SIGNED(ctx->r25) >> 16);
L_8003BFC8:
    // 0x8003BFC8: bne         $v1, $at, L_8003BFEC
    if (ctx->r3 != ctx->r1) {
        // 0x8003BFCC: sra         $t5, $v0, 3
        ctx->r13 = S32(SIGNED(ctx->r2) >> 3);
            goto L_8003BFEC;
    }
    // 0x8003BFCC: sra         $t5, $v0, 3
    ctx->r13 = S32(SIGNED(ctx->r2) >> 3);
    // 0x8003BFD0: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x8003BFD4: lw          $t3, 0x78($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X78);
    // 0x8003BFD8: nop

    // 0x8003BFDC: subu        $v0, $t7, $t3
    ctx->r2 = SUB32(ctx->r15, ctx->r11);
    // 0x8003BFE0: sll         $t6, $v0, 16
    ctx->r14 = S32(ctx->r2 << 16);
    // 0x8003BFE4: sra         $v0, $t6, 16
    ctx->r2 = S32(SIGNED(ctx->r14) >> 16);
L_8003BFE8:
    // 0x8003BFE8: sra         $t5, $v0, 3
    ctx->r13 = S32(SIGNED(ctx->r2) >> 3);
L_8003BFEC:
    // 0x8003BFEC: sll         $t9, $t5, 16
    ctx->r25 = S32(ctx->r13 << 16);
    // 0x8003BFF0: sra         $v0, $t9, 16
    ctx->r2 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8003BFF4: slti        $at, $v0, 0x201
    ctx->r1 = SIGNED(ctx->r2) < 0X201 ? 1 : 0;
    // 0x8003BFF8: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
    // 0x8003BFFC: bne         $at, $zero, L_8003C00C
    if (ctx->r1 != 0) {
        // 0x8003C000: slti        $at, $v0, -0x200
        ctx->r1 = SIGNED(ctx->r2) < -0X200 ? 1 : 0;
            goto L_8003C00C;
    }
    // 0x8003C000: slti        $at, $v0, -0x200
    ctx->r1 = SIGNED(ctx->r2) < -0X200 ? 1 : 0;
    // 0x8003C004: addiu       $v0, $zero, 0x200
    ctx->r2 = ADD32(0, 0X200);
    // 0x8003C008: slti        $at, $v0, -0x200
    ctx->r1 = SIGNED(ctx->r2) < -0X200 ? 1 : 0;
L_8003C00C:
    // 0x8003C00C: beq         $at, $zero, L_8003C01C
    if (ctx->r1 == 0) {
        // 0x8003C010: subu        $t7, $v1, $v0
        ctx->r15 = SUB32(ctx->r3, ctx->r2);
            goto L_8003C01C;
    }
    // 0x8003C010: subu        $t7, $v1, $v0
    ctx->r15 = SUB32(ctx->r3, ctx->r2);
    // 0x8003C014: addiu       $v0, $zero, -0x200
    ctx->r2 = ADD32(0, -0X200);
    // 0x8003C018: subu        $t7, $v1, $v0
    ctx->r15 = SUB32(ctx->r3, ctx->r2);
L_8003C01C:
    // 0x8003C01C: beq         $v0, $zero, L_8003C028
    if (ctx->r2 == 0) {
        // 0x8003C020: sh          $t7, 0x0($s0)
        MEM_H(0X0, ctx->r16) = ctx->r15;
            goto L_8003C028;
    }
    // 0x8003C020: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
    // 0x8003C024: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8003C028:
    // 0x8003C028: beq         $a1, $zero, L_8003C078
    if (ctx->r5 == 0) {
        // 0x8003C02C: nop
    
            goto L_8003C078;
    }
    // 0x8003C02C: nop

    // 0x8003C030: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x8003C034: addiu       $a0, $zero, 0x222
    ctx->r4 = ADD32(0, 0X222);
    // 0x8003C038: bne         $t3, $zero, L_8003C0A8
    if (ctx->r11 != 0) {
        // 0x8003C03C: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8003C0A8;
    }
    // 0x8003C03C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8003C040: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8003C044: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x8003C048: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x8003C04C: addiu       $t8, $t0, 0x4
    ctx->r24 = ADD32(ctx->r8, 0X4);
    // 0x8003C050: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8003C054: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x8003C058: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x8003C05C: jal         0x80009558
    // 0x8003C060: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_14;
    // 0x8003C060: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_14:
    // 0x8003C064: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8003C068: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8003C06C: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8003C070: b           L_8003C0AC
    // 0x8003C074: lb          $v0, 0x14($t0)
    ctx->r2 = MEM_B(ctx->r8, 0X14);
        goto L_8003C0AC;
    // 0x8003C074: lb          $v0, 0x14($t0)
    ctx->r2 = MEM_B(ctx->r8, 0X14);
L_8003C078:
    // 0x8003C078: lw          $v0, 0x4($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X4);
    // 0x8003C07C: sb          $zero, 0x15($t0)
    MEM_B(0X15, ctx->r8) = 0;
    // 0x8003C080: beq         $v0, $zero, L_8003C0A8
    if (ctx->r2 == 0) {
        // 0x8003C084: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8003C0A8;
    }
    // 0x8003C084: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8003C088: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x8003C08C: jal         0x800096F8
    // 0x8003C090: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    audspat_point_stop(rdram, ctx);
        goto after_15;
    // 0x8003C090: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    after_15:
    // 0x8003C094: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8003C098: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8003C09C: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8003C0A0: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8003C0A4: nop

L_8003C0A8:
    // 0x8003C0A8: lb          $v0, 0x14($t0)
    ctx->r2 = MEM_B(ctx->r8, 0X14);
L_8003C0AC:
    // 0x8003C0AC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8003C0B0: bltz        $v0, L_8003C0F4
    if (SIGNED(ctx->r2) < 0) {
        // 0x8003C0B4: nop
    
            goto L_8003C0F4;
    }
    // 0x8003C0B4: nop

    // 0x8003C0B8: lhu         $t9, 0x8($t1)
    ctx->r25 = MEM_HU(ctx->r9, 0X8);
    // 0x8003C0BC: sllv        $a0, $t5, $v0
    ctx->r4 = S32(ctx->r13 << (ctx->r2 & 31));
    // 0x8003C0C0: and         $t4, $t9, $a0
    ctx->r12 = ctx->r25 & ctx->r4;
    // 0x8003C0C4: beq         $t4, $zero, L_8003C1D4
    if (ctx->r12 == 0) {
        // 0x8003C0C8: nop
    
            goto L_8003C1D4;
    }
    // 0x8003C0C8: nop

    // 0x8003C0CC: lbu         $t3, 0x49($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X49);
    // 0x8003C0D0: lw          $t7, 0x4($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X4);
    // 0x8003C0D4: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x8003C0D8: addu        $v0, $t7, $t6
    ctx->r2 = ADD32(ctx->r15, ctx->r14);
    // 0x8003C0DC: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8003C0E0: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x8003C0E4: nop

    // 0x8003C0E8: or          $t9, $t8, $t5
    ctx->r25 = ctx->r24 | ctx->r13;
    // 0x8003C0EC: b           L_8003C1D4
    // 0x8003C0F0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
        goto L_8003C1D4;
    // 0x8003C0F0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_8003C0F4:
    // 0x8003C0F4: lb          $t4, 0x13($t2)
    ctx->r12 = MEM_B(ctx->r10, 0X13);
    // 0x8003C0F8: lw          $v1, 0x4($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X4);
    // 0x8003C0FC: bne         $t4, $zero, L_8003C168
    if (ctx->r12 != 0) {
        // 0x8003C100: nop
    
            goto L_8003C168;
    }
    // 0x8003C100: nop

    // 0x8003C104: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8003C108: lbu         $t6, 0x10($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X10);
    // 0x8003C10C: lh          $t7, 0x0($t3)
    ctx->r15 = MEM_H(ctx->r11, 0X0);
    // 0x8003C110: nop

    // 0x8003C114: slt         $at, $t7, $t6
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8003C118: bne         $at, $zero, L_8003C144
    if (ctx->r1 != 0) {
        // 0x8003C11C: nop
    
            goto L_8003C144;
    }
    // 0x8003C11C: nop

    // 0x8003C120: lbu         $t8, 0x49($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X49);
    // 0x8003C124: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x8003C128: sll         $t5, $t8, 2
    ctx->r13 = S32(ctx->r24 << 2);
    // 0x8003C12C: addu        $v0, $v1, $t5
    ctx->r2 = ADD32(ctx->r3, ctx->r13);
    // 0x8003C130: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8003C134: nop

    // 0x8003C138: or          $t3, $t9, $t4
    ctx->r11 = ctx->r25 | ctx->r12;
    // 0x8003C13C: b           L_8003C1D4
    // 0x8003C140: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
        goto L_8003C1D4;
    // 0x8003C140: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_8003C144:
    // 0x8003C144: lbu         $t7, 0x49($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X49);
    // 0x8003C148: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x8003C14C: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8003C150: addu        $v0, $v1, $t6
    ctx->r2 = ADD32(ctx->r3, ctx->r14);
    // 0x8003C154: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8003C158: nor         $t9, $t5, $zero
    ctx->r25 = ~(ctx->r13 | 0);
    // 0x8003C15C: and         $t4, $t8, $t9
    ctx->r12 = ctx->r24 & ctx->r25;
    // 0x8003C160: b           L_8003C1D4
    // 0x8003C164: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
        goto L_8003C1D4;
    // 0x8003C164: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_8003C168:
    // 0x8003C168: lbu         $t7, 0x48($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X48);
    // 0x8003C16C: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8003C170: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x8003C174: addu        $t5, $t3, $t6
    ctx->r13 = ADD32(ctx->r11, ctx->r14);
    // 0x8003C178: lh          $t8, 0x0($t5)
    ctx->r24 = MEM_H(ctx->r13, 0X0);
    // 0x8003C17C: lbu         $t9, 0x10($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X10);
    // 0x8003C180: nop

    // 0x8003C184: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8003C188: bne         $at, $zero, L_8003C1B4
    if (ctx->r1 != 0) {
        // 0x8003C18C: nop
    
            goto L_8003C1B4;
    }
    // 0x8003C18C: nop

    // 0x8003C190: lbu         $t4, 0x49($t1)
    ctx->r12 = MEM_BU(ctx->r9, 0X49);
    // 0x8003C194: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x8003C198: sll         $t7, $t4, 2
    ctx->r15 = S32(ctx->r12 << 2);
    // 0x8003C19C: addu        $v0, $v1, $t7
    ctx->r2 = ADD32(ctx->r3, ctx->r15);
    // 0x8003C1A0: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8003C1A4: nop

    // 0x8003C1A8: or          $t5, $t3, $t6
    ctx->r13 = ctx->r11 | ctx->r14;
    // 0x8003C1AC: b           L_8003C1D4
    // 0x8003C1B0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
        goto L_8003C1D4;
    // 0x8003C1B0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_8003C1B4:
    // 0x8003C1B4: lbu         $t8, 0x49($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X49);
    // 0x8003C1B8: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x8003C1BC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8003C1C0: addu        $v0, $v1, $t9
    ctx->r2 = ADD32(ctx->r3, ctx->r25);
    // 0x8003C1C4: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8003C1C8: nor         $t3, $t7, $zero
    ctx->r11 = ~(ctx->r15 | 0);
    // 0x8003C1CC: and         $t6, $t4, $t3
    ctx->r14 = ctx->r12 & ctx->r11;
    // 0x8003C1D0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_8003C1D4:
    // 0x8003C1D4: lw          $t8, 0x4C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4C);
    // 0x8003C1D8: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8003C1DC: sb          $t5, 0x13($t8)
    MEM_B(0X13, ctx->r24) = ctx->r13;
    // 0x8003C1E0: lw          $t9, 0x4C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4C);
    // 0x8003C1E4: nop

    // 0x8003C1E8: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    // 0x8003C1EC: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x8003C1F0: nop

    // 0x8003C1F4: lh          $t7, 0x14($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X14);
    // 0x8003C1F8: nop

    // 0x8003C1FC: andi        $t4, $t7, 0xFFF7
    ctx->r12 = ctx->r15 & 0XFFF7;
    // 0x8003C200: sh          $t4, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r12;
    // 0x8003C204: lw          $t3, 0x5C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X5C);
    // 0x8003C208: nop

    // 0x8003C20C: sw          $zero, 0x100($t3)
    MEM_W(0X100, ctx->r11) = 0;
    // 0x8003C210: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003C214: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8003C218: jr          $ra
    // 0x8003C21C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8003C21C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void obj_init_ttdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C220: sb          $zero, 0x3A($a0)
    MEM_B(0X3A, ctx->r4) = 0;
    // 0x8003C224: lbu         $t7, 0x8($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X8);
    // 0x8003C228: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x8003C22C: sll         $t8, $t7, 10
    ctx->r24 = S32(ctx->r15 << 10);
    // 0x8003C230: sh          $t8, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r24;
    // 0x8003C234: lb          $t9, 0xE($a1)
    ctx->r25 = MEM_B(ctx->r5, 0XE);
    // 0x8003C238: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8003C23C: sb          $t9, 0xF($v0)
    MEM_B(0XF, ctx->r2) = ctx->r25;
    // 0x8003C240: lbu         $t0, 0xB($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0XB);
    // 0x8003C244: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003C248: sb          $t0, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r8;
    // 0x8003C24C: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8003C250: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x8003C254: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8003C258: lbu         $t1, 0xA($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0XA);
    // 0x8003C25C: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x8003C260: sb          $t1, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r9;
    // 0x8003C264: lh          $t2, 0x0($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X0);
    // 0x8003C268: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003C26C: sw          $t2, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r10;
    // 0x8003C270: lbu         $t3, 0x9($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X9);
    // 0x8003C274: nop

    // 0x8003C278: andi        $t4, $t3, 0x3F
    ctx->r12 = ctx->r11 & 0X3F;
    // 0x8003C27C: sll         $t5, $t4, 10
    ctx->r13 = S32(ctx->r12 << 10);
    // 0x8003C280: sw          $t5, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r13;
    // 0x8003C284: lbu         $t7, 0xC($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0XC);
    // 0x8003C288: nop

    // 0x8003C28C: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8003C290: nop

    // 0x8003C294: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8003C298: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8003C29C: nop

    // 0x8003C2A0: bc1f        L_8003C2B0
    if (!c1cs) {
        // 0x8003C2A4: nop
    
            goto L_8003C2B0;
    }
    // 0x8003C2A4: nop

    // 0x8003C2A8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8003C2AC: nop

L_8003C2B0:
    // 0x8003C2B0: div.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8003C2B4: lw          $t8, 0x40($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X40);
    // 0x8003C2B8: lw          $t0, 0x4C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4C);
    // 0x8003C2BC: lwc1        $f10, 0xC($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0XC);
    // 0x8003C2C0: addiu       $t9, $zero, 0x21
    ctx->r25 = ADD32(0, 0X21);
    // 0x8003C2C4: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8003C2C8: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x8003C2CC: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8003C2D0: swc1        $f16, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f16.u32l;
    // 0x8003C2D4: sh          $t9, 0x14($t0)
    MEM_H(0X14, ctx->r8) = ctx->r25;
    // 0x8003C2D8: lw          $t2, 0x4C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X4C);
    // 0x8003C2DC: nop

    // 0x8003C2E0: sb          $t1, 0x11($t2)
    MEM_B(0X11, ctx->r10) = ctx->r9;
    // 0x8003C2E4: lw          $t4, 0x4C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X4C);
    // 0x8003C2E8: nop

    // 0x8003C2EC: sb          $t3, 0x10($t4)
    MEM_B(0X10, ctx->r12) = ctx->r11;
    // 0x8003C2F0: lw          $t5, 0x4C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X4C);
    // 0x8003C2F4: nop

    // 0x8003C2F8: sb          $zero, 0x12($t5)
    MEM_B(0X12, ctx->r13) = 0;
    // 0x8003C2FC: lw          $t7, 0x40($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X40);
    // 0x8003C300: lb          $t6, 0x3A($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X3A);
    // 0x8003C304: lb          $t8, 0x55($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X55);
    // 0x8003C308: nop

    // 0x8003C30C: slt         $at, $t6, $t8
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8003C310: bne         $at, $zero, L_8003C31C
    if (ctx->r1 != 0) {
        // 0x8003C314: nop
    
            goto L_8003C31C;
    }
    // 0x8003C314: nop

    // 0x8003C318: sb          $zero, 0x3A($a0)
    MEM_B(0X3A, ctx->r4) = 0;
L_8003C31C:
    // 0x8003C31C: jr          $ra
    // 0x8003C320: nop

    return;
    // 0x8003C320: nop

;}
RECOMP_FUNC void obj_loop_ttdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C324: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8003C328: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003C32C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8003C330: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8003C334: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8003C338: lw          $s0, 0x64($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X64);
    // 0x8003C33C: jal         0x8006ECD0
    // 0x8003C340: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x8003C340: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    after_0:
    // 0x8003C344: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8003C348: lbu         $t6, 0xF($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XF);
    // 0x8003C34C: nop

    // 0x8003C350: bne         $t6, $zero, L_8003C370
    if (ctx->r14 != 0) {
        // 0x8003C354: nop
    
            goto L_8003C370;
    }
    // 0x8003C354: nop

    // 0x8003C358: lbu         $t7, 0x16($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X16);
    // 0x8003C35C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8003C360: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8003C364: lb          $t8, -0x2FFC($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X2FFC);
    // 0x8003C368: b           L_8003C388
    // 0x8003C36C: sb          $t8, 0x3A($s1)
    MEM_B(0X3A, ctx->r17) = ctx->r24;
        goto L_8003C388;
    // 0x8003C36C: sb          $t8, 0x3A($s1)
    MEM_B(0X3A, ctx->r17) = ctx->r24;
L_8003C370:
    // 0x8003C370: lbu         $t9, 0x16($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X16);
    // 0x8003C374: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8003C378: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8003C37C: lb          $t0, -0x2FF4($t0)
    ctx->r8 = MEM_B(ctx->r8, -0X2FF4);
    // 0x8003C380: nop

    // 0x8003C384: sb          $t0, 0x3A($s1)
    MEM_B(0X3A, ctx->r17) = ctx->r8;
L_8003C388:
    // 0x8003C388: lw          $v1, 0x4C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X4C);
    // 0x8003C38C: lbu         $t2, 0x12($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X12);
    // 0x8003C390: lbu         $t1, 0x13($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X13);
    // 0x8003C394: nop

    // 0x8003C398: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8003C39C: beq         $at, $zero, L_8003C4AC
    if (ctx->r1 == 0) {
        // 0x8003C3A0: nop
    
            goto L_8003C4AC;
    }
    // 0x8003C3A0: nop

    // 0x8003C3A4: lbu         $t3, 0x16($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X16);
    // 0x8003C3A8: nop

    // 0x8003C3AC: slti        $at, $t3, 0x4
    ctx->r1 = SIGNED(ctx->r11) < 0X4 ? 1 : 0;
    // 0x8003C3B0: bne         $at, $zero, L_8003C3D4
    if (ctx->r1 != 0) {
        // 0x8003C3B4: nop
    
            goto L_8003C3D4;
    }
    // 0x8003C3B4: nop

    // 0x8003C3B8: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8003C3BC: nop

    // 0x8003C3C0: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x8003C3C4: nop

    // 0x8003C3C8: slti        $at, $t5, 0x2F
    ctx->r1 = SIGNED(ctx->r13) < 0X2F ? 1 : 0;
    // 0x8003C3CC: beq         $at, $zero, L_8003C4AC
    if (ctx->r1 == 0) {
        // 0x8003C3D0: nop
    
            goto L_8003C4AC;
    }
    // 0x8003C3D0: nop

L_8003C3D4:
    // 0x8003C3D4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8003C3D8: nop

    // 0x8003C3DC: beq         $v0, $zero, L_8003C4AC
    if (ctx->r2 == 0) {
        // 0x8003C3E0: nop
    
            goto L_8003C4AC;
    }
    // 0x8003C3E0: nop

    // 0x8003C3E4: lw          $t6, 0x40($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X40);
    // 0x8003C3E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003C3EC: lb          $t7, 0x54($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X54);
    // 0x8003C3F0: nop

    // 0x8003C3F4: bne         $t7, $at, L_8003C4AC
    if (ctx->r15 != ctx->r1) {
        // 0x8003C3F8: nop
    
            goto L_8003C4AC;
    }
    // 0x8003C3F8: nop

    // 0x8003C3FC: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x8003C400: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8003C404: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x8003C408: nop

    // 0x8003C40C: beq         $a0, $t8, L_8003C498
    if (ctx->r4 == ctx->r24) {
        // 0x8003C410: nop
    
            goto L_8003C498;
    }
    // 0x8003C410: nop

    // 0x8003C414: lw          $t9, 0x5C($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X5C);
    // 0x8003C418: nop

    // 0x8003C41C: lw          $t0, 0x100($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X100);
    // 0x8003C420: nop

    // 0x8003C424: bne         $v0, $t0, L_8003C498
    if (ctx->r2 != ctx->r8) {
        // 0x8003C428: nop
    
            goto L_8003C498;
    }
    // 0x8003C428: nop

    // 0x8003C42C: lb          $t1, 0x13($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X13);
    // 0x8003C430: nop

    // 0x8003C434: beq         $a0, $t1, L_8003C494
    if (ctx->r4 == ctx->r9) {
        // 0x8003C438: addiu       $t5, $zero, 0x12C
        ctx->r13 = ADD32(0, 0X12C);
            goto L_8003C494;
    }
    // 0x8003C438: addiu       $t5, $zero, 0x12C
    ctx->r13 = ADD32(0, 0X12C);
    // 0x8003C43C: jal         0x800C3958
    // 0x8003C440: nop

    textbox_visible(rdram, ctx);
        goto after_1;
    // 0x8003C440: nop

    after_1:
    // 0x8003C444: bne         $v0, $zero, L_8003C494
    if (ctx->r2 != 0) {
        // 0x8003C448: addiu       $t5, $zero, 0x12C
        ctx->r13 = ADD32(0, 0X12C);
            goto L_8003C494;
    }
    // 0x8003C448: addiu       $t5, $zero, 0x12C
    ctx->r13 = ADD32(0, 0X12C);
    // 0x8003C44C: lh          $t2, 0xC($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XC);
    // 0x8003C450: nop

    // 0x8003C454: bne         $t2, $zero, L_8003C494
    if (ctx->r10 != 0) {
        // 0x8003C458: addiu       $t5, $zero, 0x12C
        ctx->r13 = ADD32(0, 0X12C);
            goto L_8003C494;
    }
    // 0x8003C458: addiu       $t5, $zero, 0x12C
    ctx->r13 = ADD32(0, 0X12C);
    // 0x8003C45C: jal         0x80000C98
    // 0x8003C460: addiu       $a0, $zero, -0x8
    ctx->r4 = ADD32(0, -0X8);
    music_fade(rdram, ctx);
        goto after_2;
    // 0x8003C460: addiu       $a0, $zero, -0x8
    ctx->r4 = ADD32(0, -0X8);
    after_2:
    // 0x8003C464: addiu       $t3, $zero, 0x8C
    ctx->r11 = ADD32(0, 0X8C);
    // 0x8003C468: sw          $t3, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r11;
    // 0x8003C46C: jal         0x80000C38
    // 0x8003C470: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    music_jingle_voicelimit_set(rdram, ctx);
        goto after_3;
    // 0x8003C470: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_3:
    // 0x8003C474: jal         0x80001BC0
    // 0x8003C478: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    music_jingle_play(rdram, ctx);
        goto after_4;
    // 0x8003C478: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_4:
    // 0x8003C47C: lb          $a0, 0x13($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X13);
    // 0x8003C480: nop

    // 0x8003C484: andi        $t4, $a0, 0xFF
    ctx->r12 = ctx->r4 & 0XFF;
    // 0x8003C488: jal         0x800C3744
    // 0x8003C48C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    set_current_text(rdram, ctx);
        goto after_5;
    // 0x8003C48C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_5:
    // 0x8003C490: addiu       $t5, $zero, 0x12C
    ctx->r13 = ADD32(0, 0X12C);
L_8003C494:
    // 0x8003C494: sh          $t5, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r13;
L_8003C498:
    // 0x8003C498: jal         0x800C3958
    // 0x8003C49C: nop

    textbox_visible(rdram, ctx);
        goto after_6;
    // 0x8003C49C: nop

    after_6:
    // 0x8003C4A0: beq         $v0, $zero, L_8003C4AC
    if (ctx->r2 == 0) {
        // 0x8003C4A4: addiu       $t6, $zero, 0x12C
        ctx->r14 = ADD32(0, 0X12C);
            goto L_8003C4AC;
    }
    // 0x8003C4A4: addiu       $t6, $zero, 0x12C
    ctx->r14 = ADD32(0, 0X12C);
    // 0x8003C4A8: sh          $t6, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r14;
L_8003C4AC:
    // 0x8003C4AC: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x8003C4B0: nop

    // 0x8003C4B4: beq         $t7, $zero, L_8003C4FC
    if (ctx->r15 == 0) {
        // 0x8003C4B8: nop
    
            goto L_8003C4FC;
    }
    // 0x8003C4B8: nop

    // 0x8003C4BC: jal         0x80001C08
    // 0x8003C4C0: nop

    music_jingle_playing(rdram, ctx);
        goto after_7;
    // 0x8003C4C0: nop

    after_7:
    // 0x8003C4C4: bne         $v0, $zero, L_8003C4FC
    if (ctx->r2 != 0) {
        // 0x8003C4C8: nop
    
            goto L_8003C4FC;
    }
    // 0x8003C4C8: nop

    // 0x8003C4CC: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8003C4D0: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8003C4D4: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8003C4D8: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003C4DC: beq         $at, $zero, L_8003C4EC
    if (ctx->r1 == 0) {
        // 0x8003C4E0: subu        $t8, $v0, $v1
        ctx->r24 = SUB32(ctx->r2, ctx->r3);
            goto L_8003C4EC;
    }
    // 0x8003C4E0: subu        $t8, $v0, $v1
    ctx->r24 = SUB32(ctx->r2, ctx->r3);
    // 0x8003C4E4: b           L_8003C4FC
    // 0x8003C4E8: sw          $t8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r24;
        goto L_8003C4FC;
    // 0x8003C4E8: sw          $t8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r24;
L_8003C4EC:
    // 0x8003C4EC: jal         0x80000C98
    // 0x8003C4F0: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    music_fade(rdram, ctx);
        goto after_8;
    // 0x8003C4F0: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    after_8:
    // 0x8003C4F4: jal         0x80000C38
    // 0x8003C4F8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    music_jingle_voicelimit_set(rdram, ctx);
        goto after_9;
    // 0x8003C4F8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_9:
L_8003C4FC:
    // 0x8003C4FC: lh          $v0, 0xC($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XC);
    // 0x8003C500: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8003C504: blez        $v0, L_8003C514
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8003C508: subu        $t9, $v0, $v1
        ctx->r25 = SUB32(ctx->r2, ctx->r3);
            goto L_8003C514;
    }
    // 0x8003C508: subu        $t9, $v0, $v1
    ctx->r25 = SUB32(ctx->r2, ctx->r3);
    // 0x8003C50C: b           L_8003C518
    // 0x8003C510: sh          $t9, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r25;
        goto L_8003C518;
    // 0x8003C510: sh          $t9, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r25;
L_8003C514:
    // 0x8003C514: sh          $zero, 0xC($s0)
    MEM_H(0XC, ctx->r16) = 0;
L_8003C518:
    // 0x8003C518: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8003C51C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8003C520: lbu         $t1, 0x16($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X16);
    // 0x8003C524: nop

    // 0x8003C528: slti        $at, $t1, 0x4
    ctx->r1 = SIGNED(ctx->r9) < 0X4 ? 1 : 0;
    // 0x8003C52C: bne         $at, $zero, L_8003C588
    if (ctx->r1 != 0) {
        // 0x8003C530: nop
    
            goto L_8003C588;
    }
    // 0x8003C530: nop

    // 0x8003C534: lw          $t2, 0x4C($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X4C);
    // 0x8003C538: lbu         $t4, 0x12($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X12);
    // 0x8003C53C: lbu         $t3, 0x13($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X13);
    // 0x8003C540: nop

    // 0x8003C544: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8003C548: beq         $at, $zero, L_8003C588
    if (ctx->r1 == 0) {
        // 0x8003C54C: nop
    
            goto L_8003C588;
    }
    // 0x8003C54C: nop

    // 0x8003C550: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x8003C554: nop

    // 0x8003C558: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x8003C55C: nop

    // 0x8003C560: slti        $at, $t6, 0x2F
    ctx->r1 = SIGNED(ctx->r14) < 0X2F ? 1 : 0;
    // 0x8003C564: bne         $at, $zero, L_8003C588
    if (ctx->r1 != 0) {
        // 0x8003C568: nop
    
            goto L_8003C588;
    }
    // 0x8003C568: nop

    // 0x8003C56C: lh          $v1, 0x0($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X0);
    // 0x8003C570: lw          $t7, 0x7C($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X7C);
    // 0x8003C574: nop

    // 0x8003C578: subu        $v0, $v1, $t7
    ctx->r2 = SUB32(ctx->r3, ctx->r15);
    // 0x8003C57C: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x8003C580: b           L_8003C5A0
    // 0x8003C584: sra         $v0, $t8, 16
    ctx->r2 = S32(SIGNED(ctx->r24) >> 16);
        goto L_8003C5A0;
    // 0x8003C584: sra         $v0, $t8, 16
    ctx->r2 = S32(SIGNED(ctx->r24) >> 16);
L_8003C588:
    // 0x8003C588: lh          $v1, 0x0($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X0);
    // 0x8003C58C: lw          $t1, 0x78($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X78);
    // 0x8003C590: nop

    // 0x8003C594: subu        $v0, $v1, $t1
    ctx->r2 = SUB32(ctx->r3, ctx->r9);
    // 0x8003C598: sll         $t2, $v0, 16
    ctx->r10 = S32(ctx->r2 << 16);
    // 0x8003C59C: sra         $v0, $t2, 16
    ctx->r2 = S32(SIGNED(ctx->r10) >> 16);
L_8003C5A0:
    // 0x8003C5A0: sra         $t4, $v0, 3
    ctx->r12 = S32(SIGNED(ctx->r2) >> 3);
    // 0x8003C5A4: sll         $t0, $t4, 16
    ctx->r8 = S32(ctx->r12 << 16);
    // 0x8003C5A8: sra         $v0, $t0, 16
    ctx->r2 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8003C5AC: slti        $at, $v0, 0x201
    ctx->r1 = SIGNED(ctx->r2) < 0X201 ? 1 : 0;
    // 0x8003C5B0: bne         $at, $zero, L_8003C5C0
    if (ctx->r1 != 0) {
        // 0x8003C5B4: slti        $at, $v0, -0x200
        ctx->r1 = SIGNED(ctx->r2) < -0X200 ? 1 : 0;
            goto L_8003C5C0;
    }
    // 0x8003C5B4: slti        $at, $v0, -0x200
    ctx->r1 = SIGNED(ctx->r2) < -0X200 ? 1 : 0;
    // 0x8003C5B8: addiu       $v0, $zero, 0x200
    ctx->r2 = ADD32(0, 0X200);
    // 0x8003C5BC: slti        $at, $v0, -0x200
    ctx->r1 = SIGNED(ctx->r2) < -0X200 ? 1 : 0;
L_8003C5C0:
    // 0x8003C5C0: beq         $at, $zero, L_8003C5D0
    if (ctx->r1 == 0) {
        // 0x8003C5C4: subu        $t6, $v1, $v0
        ctx->r14 = SUB32(ctx->r3, ctx->r2);
            goto L_8003C5D0;
    }
    // 0x8003C5C4: subu        $t6, $v1, $v0
    ctx->r14 = SUB32(ctx->r3, ctx->r2);
    // 0x8003C5C8: addiu       $v0, $zero, -0x200
    ctx->r2 = ADD32(0, -0X200);
    // 0x8003C5CC: subu        $t6, $v1, $v0
    ctx->r14 = SUB32(ctx->r3, ctx->r2);
L_8003C5D0:
    // 0x8003C5D0: bne         $v0, $zero, L_8003C5DC
    if (ctx->r2 != 0) {
        // 0x8003C5D4: sh          $t6, 0x0($s1)
        MEM_H(0X0, ctx->r17) = ctx->r14;
            goto L_8003C5DC;
    }
    // 0x8003C5D4: sh          $t6, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r14;
    // 0x8003C5D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8003C5DC:
    // 0x8003C5DC: beq         $a0, $zero, L_8003C618
    if (ctx->r4 == 0) {
        // 0x8003C5E0: nop
    
            goto L_8003C618;
    }
    // 0x8003C5E0: nop

    // 0x8003C5E4: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x8003C5E8: addiu       $a0, $zero, 0x222
    ctx->r4 = ADD32(0, 0X222);
    // 0x8003C5EC: bne         $t7, $zero, L_8003C634
    if (ctx->r15 != 0) {
        // 0x8003C5F0: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8003C634;
    }
    // 0x8003C5F0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8003C5F4: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x8003C5F8: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x8003C5FC: lw          $a3, 0x14($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X14);
    // 0x8003C600: addiu       $t9, $s0, 0x4
    ctx->r25 = ADD32(ctx->r16, 0X4);
    // 0x8003C604: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8003C608: jal         0x80009558
    // 0x8003C60C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_10;
    // 0x8003C60C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_10:
    // 0x8003C610: b           L_8003C638
    // 0x8003C614: lw          $t2, 0x4C($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X4C);
        goto L_8003C638;
    // 0x8003C614: lw          $t2, 0x4C($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X4C);
L_8003C618:
    // 0x8003C618: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x8003C61C: nop

    // 0x8003C620: beq         $v0, $zero, L_8003C634
    if (ctx->r2 == 0) {
        // 0x8003C624: nop
    
            goto L_8003C634;
    }
    // 0x8003C624: nop

    // 0x8003C628: jal         0x800096F8
    // 0x8003C62C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    audspat_point_stop(rdram, ctx);
        goto after_11;
    // 0x8003C62C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_11:
    // 0x8003C630: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
L_8003C634:
    // 0x8003C634: lw          $t2, 0x4C($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X4C);
L_8003C638:
    // 0x8003C638: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8003C63C: sb          $t1, 0x13($t2)
    MEM_B(0X13, ctx->r10) = ctx->r9;
    // 0x8003C640: lw          $t3, 0x4C($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X4C);
    // 0x8003C644: nop

    // 0x8003C648: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
    // 0x8003C64C: lw          $v1, 0x4C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X4C);
    // 0x8003C650: nop

    // 0x8003C654: lh          $t4, 0x14($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X14);
    // 0x8003C658: nop

    // 0x8003C65C: andi        $t0, $t4, 0xFFF7
    ctx->r8 = ctx->r12 & 0XFFF7;
    // 0x8003C660: sh          $t0, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r8;
    // 0x8003C664: lw          $t5, 0x5C($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X5C);
    // 0x8003C668: nop

    // 0x8003C66C: sw          $zero, 0x100($t5)
    MEM_W(0X100, ctx->r13) = 0;
    // 0x8003C670: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003C674: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8003C678: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8003C67C: jr          $ra
    // 0x8003C680: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8003C680: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void obj_init_trigger(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C684: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8003C688: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003C68C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8003C690: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8003C694: lb          $a2, 0x9($a1)
    ctx->r6 = MEM_B(ctx->r5, 0X9);
    // 0x8003C698: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003C69C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003C6A0: bne         $a2, $at, L_8003C6B8
    if (ctx->r6 != ctx->r1) {
        // 0x8003C6A4: or          $s1, $a1, $zero
        ctx->r17 = ctx->r5 | 0;
            goto L_8003C6B8;
    }
    // 0x8003C6A4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8003C6A8: jal         0x8000CC20
    // 0x8003C6AC: nop

    func_8000CC20(rdram, ctx);
        goto after_0;
    // 0x8003C6AC: nop

    after_0:
    // 0x8003C6B0: b           L_8003C6C4
    // 0x8003C6B4: sb          $v0, 0x9($s1)
    MEM_B(0X9, ctx->r17) = ctx->r2;
        goto L_8003C6C4;
    // 0x8003C6B4: sb          $v0, 0x9($s1)
    MEM_B(0X9, ctx->r17) = ctx->r2;
L_8003C6B8:
    // 0x8003C6B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003C6BC: jal         0x8000CBF0
    // 0x8003C6C0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_8000CBF0(rdram, ctx);
        goto after_1;
    // 0x8003C6C0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_1:
L_8003C6C4:
    // 0x8003C6C4: lb          $t6, 0x9($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X9);
    // 0x8003C6C8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003C6CC: bne         $t6, $at, L_8003C6DC
    if (ctx->r14 != ctx->r1) {
        // 0x8003C6D0: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8003C6DC;
    }
    // 0x8003C6D0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003C6D4: jal         0x800CA2B4
    // 0x8003C6D8: addiu       $a0, $a0, 0x6558
    ctx->r4 = ADD32(ctx->r4, 0X6558);
    rmonPrintf_recomp(rdram, ctx);
        goto after_2;
    // 0x8003C6D8: addiu       $a0, $a0, 0x6558
    ctx->r4 = ADD32(ctx->r4, 0X6558);
    after_2:
L_8003C6DC:
    // 0x8003C6DC: lbu         $t8, 0x8($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X8);
    // 0x8003C6E0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8003C6E4: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8003C6E8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003C6EC: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003C6F0: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x8003C6F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003C6F8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8003C6FC: nop

    // 0x8003C700: bc1f        L_8003C710
    if (!c1cs) {
        // 0x8003C704: nop
    
            goto L_8003C710;
    }
    // 0x8003C704: nop

    // 0x8003C708: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8003C70C: nop

L_8003C710:
    // 0x8003C710: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8003C714: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x8003C718: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x8003C71C: lbu         $t0, 0xA($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0XA);
    // 0x8003C720: nop

    // 0x8003C724: sll         $t1, $t0, 10
    ctx->r9 = S32(ctx->r8 << 10);
    // 0x8003C728: sh          $t1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r9;
    // 0x8003C72C: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8003C730: jal         0x80070A04
    // 0x8003C734: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    sins_f(rdram, ctx);
        goto after_3;
    // 0x8003C734: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_3:
    // 0x8003C738: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8003C73C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003C740: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x8003C744: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x8003C748: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8003C74C: jal         0x80070A38
    // 0x8003C750: nop

    coss_f(rdram, ctx);
        goto after_4;
    // 0x8003C750: nop

    after_4:
    // 0x8003C754: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8003C758: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8003C75C: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x8003C760: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003C764: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8003C768: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003C76C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8003C770: nop

    // 0x8003C774: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8003C778: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8003C77C: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8003C780: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    // 0x8003C784: lbu         $t2, 0x8($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X8);
    // 0x8003C788: nop

    // 0x8003C78C: sw          $t2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r10;
    // 0x8003C790: lbu         $t3, 0xD($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0XD);
    // 0x8003C794: nop

    // 0x8003C798: sb          $t3, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r11;
    // 0x8003C79C: lw          $t5, 0x4C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4C);
    // 0x8003C7A0: nop

    // 0x8003C7A4: sh          $t4, 0x14($t5)
    MEM_H(0X14, ctx->r13) = ctx->r12;
    // 0x8003C7A8: lw          $t6, 0x4C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4C);
    // 0x8003C7AC: nop

    // 0x8003C7B0: sb          $zero, 0x11($t6)
    MEM_B(0X11, ctx->r14) = 0;
    // 0x8003C7B4: lw          $t8, 0x4C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4C);
    // 0x8003C7B8: lbu         $t7, 0x8($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X8);
    // 0x8003C7BC: nop

    // 0x8003C7C0: sb          $t7, 0x10($t8)
    MEM_B(0X10, ctx->r24) = ctx->r15;
    // 0x8003C7C4: lw          $t9, 0x4C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4C);
    // 0x8003C7C8: nop

    // 0x8003C7CC: sb          $zero, 0x12($t9)
    MEM_B(0X12, ctx->r25) = 0;
    // 0x8003C7D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003C7D4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8003C7D8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8003C7DC: jr          $ra
    // 0x8003C7E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8003C7E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void obj_loop_trigger(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C7E4: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x8003C7E8: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8003C7EC: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x8003C7F0: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8003C7F4: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8003C7F8: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8003C7FC: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8003C800: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8003C804: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8003C808: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8003C80C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8003C810: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8003C814: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x8003C818: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8003C81C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8003C820: sw          $a1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r5;
    // 0x8003C824: lw          $fp, 0x3C($a0)
    ctx->r30 = MEM_W(ctx->r4, 0X3C);
    // 0x8003C828: lw          $s2, 0x64($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X64);
    // 0x8003C82C: jal         0x8006ECD0
    // 0x8003C830: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x8003C830: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    after_0:
    // 0x8003C834: lbu         $t7, 0x49($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X49);
    // 0x8003C838: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x8003C83C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8003C840: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8003C844: lw          $s0, 0x0($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X0);
    // 0x8003C848: jal         0x8006BFD8
    // 0x8003C84C: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    level_type(rdram, ctx);
        goto after_1;
    // 0x8003C84C: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    after_1:
    // 0x8003C850: lb          $v1, 0x9($fp)
    ctx->r3 = MEM_B(ctx->r30, 0X9);
    // 0x8003C854: nop

    // 0x8003C858: bltz        $v1, L_8003C9F0
    if (SIGNED(ctx->r3) < 0) {
        // 0x8003C85C: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_8003C9F0;
    }
    // 0x8003C85C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8003C860: lw          $t1, 0x4C($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X4C);
    // 0x8003C864: lw          $a1, 0x10($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X10);
    // 0x8003C868: lbu         $t2, 0x13($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X13);
    // 0x8003C86C: lui         $t0, 0x1
    ctx->r8 = S32(0X1 << 16);
    // 0x8003C870: slt         $at, $t2, $a1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8003C874: beq         $at, $zero, L_8003C9EC
    if (ctx->r1 == 0) {
        // 0x8003C878: sllv        $a2, $t0, $v1
        ctx->r6 = S32(ctx->r8 << (ctx->r3 & 31));
            goto L_8003C9EC;
    }
    // 0x8003C878: sllv        $a2, $t0, $v1
    ctx->r6 = S32(ctx->r8 << (ctx->r3 & 31));
    // 0x8003C87C: andi        $t3, $v0, 0xFF
    ctx->r11 = ctx->r2 & 0XFF;
    // 0x8003C880: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8003C884: bne         $t3, $at, L_8003C894
    if (ctx->r11 != ctx->r1) {
        // 0x8003C888: and         $t4, $s0, $a2
        ctx->r12 = ctx->r16 & ctx->r6;
            goto L_8003C894;
    }
    // 0x8003C888: and         $t4, $s0, $a2
    ctx->r12 = ctx->r16 & ctx->r6;
    // 0x8003C88C: bne         $t4, $zero, L_8003C9F0
    if (ctx->r12 != 0) {
        // 0x8003C890: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_8003C9F0;
    }
    // 0x8003C890: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_8003C894:
    // 0x8003C894: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8003C898: addiu       $a0, $sp, 0x8C
    ctx->r4 = ADD32(ctx->r29, 0X8C);
    // 0x8003C89C: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x8003C8A0: jal         0x8001BAA8
    // 0x8003C8A4: cvt.s.w     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    ctx->f22.fl = CVT_S_W(ctx->f4.u32l);
    get_racer_objects(rdram, ctx);
        goto after_2;
    // 0x8003C8A4: cvt.s.w     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    ctx->f22.fl = CVT_S_W(ctx->f4.u32l);
    after_2:
    // 0x8003C8A8: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
    // 0x8003C8AC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8003C8B0: blez        $t5, L_8003C9EC
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8003C8B4: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_8003C9EC;
    }
    // 0x8003C8B4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8003C8B8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8003C8BC: addiu       $s6, $zero, 0xFF
    ctx->r22 = ADD32(0, 0XFF);
    // 0x8003C8C0: addiu       $s5, $zero, -0x1
    ctx->r21 = ADD32(0, -0X1);
L_8003C8C4:
    // 0x8003C8C4: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8003C8C8: lbu         $v1, 0x14($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X14);
    // 0x8003C8CC: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x8003C8D0: andi        $t7, $v1, 0x1
    ctx->r15 = ctx->r3 & 0X1;
    // 0x8003C8D4: bne         $t7, $zero, L_8003C8EC
    if (ctx->r15 != 0) {
        // 0x8003C8D8: andi        $t8, $v1, 0x2
        ctx->r24 = ctx->r3 & 0X2;
            goto L_8003C8EC;
    }
    // 0x8003C8D8: andi        $t8, $v1, 0x2
    ctx->r24 = ctx->r3 & 0X2;
    // 0x8003C8DC: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x8003C8E0: nop

    // 0x8003C8E4: beq         $s5, $t6, L_8003C904
    if (ctx->r21 == ctx->r14) {
        // 0x8003C8E8: nop
    
            goto L_8003C904;
    }
    // 0x8003C8E8: nop

L_8003C8EC:
    // 0x8003C8EC: bne         $t8, $zero, L_8003C9DC
    if (ctx->r24 != 0) {
        // 0x8003C8F0: lw          $t7, 0x8C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X8C);
            goto L_8003C9DC;
    }
    // 0x8003C8F0: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
    // 0x8003C8F4: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x8003C8F8: nop

    // 0x8003C8FC: beq         $s5, $t9, L_8003C9DC
    if (ctx->r21 == ctx->r25) {
        // 0x8003C900: lw          $t7, 0x8C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X8C);
            goto L_8003C9DC;
    }
    // 0x8003C900: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
L_8003C904:
    // 0x8003C904: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003C908: lwc1        $f8, 0xC($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0XC);
    // 0x8003C90C: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003C910: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8003C914: lwc1        $f16, 0x10($s4)
    ctx->f16.u32l = MEM_W(ctx->r20, 0X10);
    // 0x8003C918: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8003C91C: sub.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8003C920: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003C924: lwc1        $f4, 0x14($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X14);
    // 0x8003C928: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8003C92C: sub.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8003C930: mul.s       $f16, $f14, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8003C934: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8003C938: jal         0x800CA030
    // 0x8003C93C: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x8003C93C: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    after_3:
    // 0x8003C940: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x8003C944: nop

    // 0x8003C948: bc1f        L_8003C9DC
    if (!c1cs) {
        // 0x8003C94C: lw          $t7, 0x8C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X8C);
            goto L_8003C9DC;
    }
    // 0x8003C94C: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
    // 0x8003C950: lwc1        $f18, 0x0($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8003C954: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003C958: lwc1        $f8, 0x8($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8003C95C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8003C960: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003C964: lwc1        $f4, 0xC($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8003C968: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x8003C96C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8003C970: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x8003C974: add.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8003C978: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x8003C97C: nop

    // 0x8003C980: bc1f        L_8003C9DC
    if (!c1cs) {
        // 0x8003C984: lw          $t7, 0x8C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X8C);
            goto L_8003C9DC;
    }
    // 0x8003C984: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
    // 0x8003C988: lbu         $t1, 0x49($s7)
    ctx->r9 = MEM_BU(ctx->r23, 0X49);
    // 0x8003C98C: lw          $t0, 0x4($s7)
    ctx->r8 = MEM_W(ctx->r23, 0X4);
    // 0x8003C990: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8003C994: addu        $v0, $t0, $t2
    ctx->r2 = ADD32(ctx->r8, ctx->r10);
    // 0x8003C998: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8003C99C: nop

    // 0x8003C9A0: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x8003C9A4: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8003C9A8: lbu         $a0, 0xB($fp)
    ctx->r4 = MEM_BU(ctx->r30, 0XB);
    // 0x8003C9AC: nop

    // 0x8003C9B0: beq         $s6, $a0, L_8003C9C0
    if (ctx->r22 == ctx->r4) {
        // 0x8003C9B4: nop
    
            goto L_8003C9C0;
    }
    // 0x8003C9B4: nop

    // 0x8003C9B8: jal         0x800C3744
    // 0x8003C9BC: nop

    set_current_text(rdram, ctx);
        goto after_4;
    // 0x8003C9BC: nop

    after_4:
L_8003C9C0:
    // 0x8003C9C0: lbu         $v0, 0xC($fp)
    ctx->r2 = MEM_BU(ctx->r30, 0XC);
    // 0x8003C9C4: nop

    // 0x8003C9C8: beq         $s6, $v0, L_8003C9DC
    if (ctx->r22 == ctx->r2) {
        // 0x8003C9CC: lw          $t7, 0x8C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X8C);
            goto L_8003C9DC;
    }
    // 0x8003C9CC: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
    // 0x8003C9D0: jal         0x80021434
    // 0x8003C9D4: addiu       $a0, $v0, 0x80
    ctx->r4 = ADD32(ctx->r2, 0X80);
    func_80021400(rdram, ctx);
        goto after_5;
    // 0x8003C9D4: addiu       $a0, $v0, 0x80
    ctx->r4 = ADD32(ctx->r2, 0X80);
    after_5:
    // 0x8003C9D8: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
L_8003C9DC:
    // 0x8003C9DC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8003C9E0: slt         $at, $s3, $t7
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8003C9E4: bne         $at, $zero, L_8003C8C4
    if (ctx->r1 != 0) {
        // 0x8003C9E8: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8003C8C4;
    }
    // 0x8003C9E8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_8003C9EC:
    // 0x8003C9EC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_8003C9F0:
    // 0x8003C9F0: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8003C9F4: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8003C9F8: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8003C9FC: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8003CA00: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8003CA04: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8003CA08: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8003CA0C: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8003CA10: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8003CA14: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8003CA18: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8003CA1C: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x8003CA20: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x8003CA24: jr          $ra
    // 0x8003CA28: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x8003CA28: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void obj_init_bridge_whaleramp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003CA2C: lbu         $t6, 0x8($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X8);
    // 0x8003CA30: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x8003CA34: sb          $t6, 0x3A($a0)
    MEM_B(0X3A, ctx->r4) = ctx->r14;
    // 0x8003CA38: lbu         $t8, 0x9($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X9);
    // 0x8003CA3C: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8003CA40: sll         $t9, $t8, 10
    ctx->r25 = S32(ctx->r24 << 10);
    // 0x8003CA44: sh          $t9, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r25;
    // 0x8003CA48: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8003CA4C: lw          $t1, 0x4C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4C);
    // 0x8003CA50: addiu       $t0, $zero, 0x21
    ctx->r8 = ADD32(0, 0X21);
    // 0x8003CA54: sh          $t0, 0x14($t1)
    MEM_H(0X14, ctx->r9) = ctx->r8;
    // 0x8003CA58: lw          $t3, 0x4C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X4C);
    // 0x8003CA5C: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x8003CA60: sb          $t2, 0x11($t3)
    MEM_B(0X11, ctx->r11) = ctx->r10;
    // 0x8003CA64: lw          $t5, 0x4C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X4C);
    // 0x8003CA68: addiu       $t4, $zero, 0x14
    ctx->r12 = ADD32(0, 0X14);
    // 0x8003CA6C: sb          $t4, 0x10($t5)
    MEM_B(0X10, ctx->r13) = ctx->r12;
    // 0x8003CA70: lw          $t6, 0x4C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4C);
    // 0x8003CA74: nop

    // 0x8003CA78: sb          $zero, 0x12($t6)
    MEM_B(0X12, ctx->r14) = 0;
    // 0x8003CA7C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8003CA80: lw          $t8, 0x40($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X40);
    // 0x8003CA84: lb          $t7, 0x3A($a0)
    ctx->r15 = MEM_B(ctx->r4, 0X3A);
    // 0x8003CA88: lb          $t9, 0x55($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X55);
    // 0x8003CA8C: nop

    // 0x8003CA90: slt         $at, $t7, $t9
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8003CA94: bne         $at, $zero, L_8003CAA0
    if (ctx->r1 != 0) {
        // 0x8003CA98: nop
    
            goto L_8003CAA0;
    }
    // 0x8003CA98: nop

    // 0x8003CA9C: sb          $zero, 0x3A($a0)
    MEM_B(0X3A, ctx->r4) = 0;
L_8003CAA0:
    // 0x8003CAA0: jr          $ra
    // 0x8003CAA4: nop

    return;
    // 0x8003CAA4: nop

;}
RECOMP_FUNC void obj_loop_bridge_whaleramp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003CAA8: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8003CAAC: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8003CAB0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003CAB4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8003CAB8: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x8003CABC: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x8003CAC0: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003CAC4: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x8003CAC8: lw          $v1, 0x64($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X64);
    // 0x8003CACC: lw          $t0, 0x3C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X3C);
    // 0x8003CAD0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003CAD4: bne         $t7, $zero, L_8003CAF4
    if (ctx->r15 != 0) {
        // 0x8003CAD8: mov.s       $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
            goto L_8003CAF4;
    }
    // 0x8003CAD8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8003CADC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003CAE0: lwc1        $f9, 0x6708($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6708);
    // 0x8003CAE4: lwc1        $f8, 0x670C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X670C);
    // 0x8003CAE8: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8003CAEC: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8003CAF0: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
L_8003CAF4:
    // 0x8003CAF4: lbu         $t8, 0xB($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0XB);
    // 0x8003CAF8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003CAFC: beq         $t8, $at, L_8003CC2C
    if (ctx->r24 == ctx->r1) {
        // 0x8003CB00: nop
    
            goto L_8003CC2C;
    }
    // 0x8003CB00: nop

    // 0x8003CB04: lw          $t9, 0x78($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X78);
    // 0x8003CB08: nop

    // 0x8003CB0C: beq         $t9, $zero, L_8003CBB4
    if (ctx->r25 == 0) {
        // 0x8003CB10: nop
    
            goto L_8003CBB4;
    }
    // 0x8003CB10: nop

    // 0x8003CB14: lb          $t1, 0xE($t0)
    ctx->r9 = MEM_B(ctx->r8, 0XE);
    // 0x8003CB18: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8003CB1C: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x8003CB20: nop

    // 0x8003CB24: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003CB28: cvt.d.s     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.d = CVT_D_S(ctx->f18.fl);
    // 0x8003CB2C: add.d       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f0.d + ctx->f0.d;
    // 0x8003CB30: cvt.s.d     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f2.fl = CVT_S_D(ctx->f4.d);
    // 0x8003CB34: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x8003CB38: nop

    // 0x8003CB3C: bc1f        L_8003CB7C
    if (!c1cs) {
        // 0x8003CB40: nop
    
            goto L_8003CB7C;
    }
    // 0x8003CB40: nop

    // 0x8003CB44: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8003CB48: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003CB4C: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x8003CB50: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003CB54: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8003CB58: nop

    // 0x8003CB5C: bc1f        L_8003CD60
    if (!c1cs) {
        // 0x8003CB60: nop
    
            goto L_8003CD60;
    }
    // 0x8003CB60: nop

    // 0x8003CB64: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003CB68: nop

    // 0x8003CB6C: mul.s       $f18, $f12, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x8003CB70: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x8003CB74: b           L_8003CD60
    // 0x8003CB78: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
        goto L_8003CD60;
    // 0x8003CB78: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
L_8003CB7C:
    // 0x8003CB7C: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8003CB80: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003CB84: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x8003CB88: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003CB8C: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x8003CB90: nop

    // 0x8003CB94: bc1f        L_8003CD60
    if (!c1cs) {
        // 0x8003CB98: nop
    
            goto L_8003CD60;
    }
    // 0x8003CB98: nop

    // 0x8003CB9C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003CBA0: nop

    // 0x8003CBA4: mul.s       $f16, $f12, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x8003CBA8: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x8003CBAC: b           L_8003CD60
    // 0x8003CBB0: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
        goto L_8003CD60;
    // 0x8003CBB0: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
L_8003CBB4:
    // 0x8003CBB4: lbu         $t2, 0xC($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0XC);
    // 0x8003CBB8: nop

    // 0x8003CBBC: blez        $t2, L_8003CBF8
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8003CBC0: nop
    
            goto L_8003CBF8;
    }
    // 0x8003CBC0: nop

    // 0x8003CBC4: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003CBC8: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8003CBCC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003CBD0: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8003CBD4: nop

    // 0x8003CBD8: bc1f        L_8003CD60
    if (!c1cs) {
        // 0x8003CBDC: nop
    
            goto L_8003CD60;
    }
    // 0x8003CBDC: nop

    // 0x8003CBE0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003CBE4: nop

    // 0x8003CBE8: mul.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x8003CBEC: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8003CBF0: b           L_8003CD60
    // 0x8003CBF4: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
        goto L_8003CD60;
    // 0x8003CBF4: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
L_8003CBF8:
    // 0x8003CBF8: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003CBFC: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8003CC00: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003CC04: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8003CC08: nop

    // 0x8003CC0C: bc1f        L_8003CD60
    if (!c1cs) {
        // 0x8003CC10: nop
    
            goto L_8003CD60;
    }
    // 0x8003CC10: nop

    // 0x8003CC14: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003CC18: nop

    // 0x8003CC1C: mul.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x8003CC20: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8003CC24: b           L_8003CD60
    // 0x8003CC28: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
        goto L_8003CD60;
    // 0x8003CC28: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
L_8003CC2C:
    // 0x8003CC2C: lw          $t3, 0x78($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X78);
    // 0x8003CC30: nop

    // 0x8003CC34: beq         $t3, $zero, L_8003CCC4
    if (ctx->r11 == 0) {
        // 0x8003CC38: nop
    
            goto L_8003CCC4;
    }
    // 0x8003CC38: nop

    // 0x8003CC3C: lh          $v0, 0x2($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X2);
    // 0x8003CC40: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x8003CC44: slti        $at, $v0, -0x12FF
    ctx->r1 = SIGNED(ctx->r2) < -0X12FF ? 1 : 0;
    // 0x8003CC48: bne         $at, $zero, L_8003CC6C
    if (ctx->r1 != 0) {
        // 0x8003CC4C: sll         $t5, $t4, 2
        ctx->r13 = S32(ctx->r12 << 2);
            goto L_8003CC6C;
    }
    // 0x8003CC4C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8003CC50: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8003CC54: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8003CC58: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8003CC5C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8003CC60: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8003CC64: subu        $t6, $v0, $t5
    ctx->r14 = SUB32(ctx->r2, ctx->r13);
    // 0x8003CC68: sh          $t6, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r14;
L_8003CC6C:
    // 0x8003CC6C: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x8003CC70: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x8003CC74: bne         $t7, $zero, L_8003CD60
    if (ctx->r15 != 0) {
        // 0x8003CC78: addiu       $a2, $sp, 0x4C
        ctx->r6 = ADD32(ctx->r29, 0X4C);
            goto L_8003CD60;
    }
    // 0x8003CC78: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    // 0x8003CC7C: lbu         $a0, 0xA($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0XA);
    // 0x8003CC80: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    // 0x8003CC84: sw          $v1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r3;
    // 0x8003CC88: jal         0x8001E3A0
    // 0x8003CC8C: addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
    obj_bridge_pos(rdram, ctx);
        goto after_0;
    // 0x8003CC8C: addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
    after_0:
    // 0x8003CC90: lw          $v1, 0x60($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X60);
    // 0x8003CC94: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x8003CC98: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x8003CC9C: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x8003CCA0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8003CCA4: addiu       $t9, $v1, 0x4
    ctx->r25 = ADD32(ctx->r3, 0X4);
    // 0x8003CCA8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8003CCAC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8003CCB0: jal         0x80009558
    // 0x8003CCB4: addiu       $a0, $zero, 0x249
    ctx->r4 = ADD32(0, 0X249);
    audspat_play_sound_at_position(rdram, ctx);
        goto after_1;
    // 0x8003CCB4: addiu       $a0, $zero, 0x249
    ctx->r4 = ADD32(0, 0X249);
    after_1:
    // 0x8003CCB8: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x8003CCBC: b           L_8003CD64
    // 0x8003CCC0: lbu         $v1, 0xB($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0XB);
        goto L_8003CD64;
    // 0x8003CCC0: lbu         $v1, 0xB($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0XB);
L_8003CCC4:
    // 0x8003CCC4: lh          $v0, 0x2($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X2);
    // 0x8003CCC8: lw          $t1, 0x74($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X74);
    // 0x8003CCCC: bgez        $v0, L_8003CD3C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8003CCD0: sll         $t2, $t1, 2
        ctx->r10 = S32(ctx->r9 << 2);
            goto L_8003CD3C;
    }
    // 0x8003CCD0: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8003CCD4: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8003CCD8: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8003CCDC: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x8003CCE0: sh          $t3, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r11;
    // 0x8003CCE4: lw          $t4, 0x4($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X4);
    // 0x8003CCE8: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x8003CCEC: bne         $t4, $zero, L_8003CD60
    if (ctx->r12 != 0) {
        // 0x8003CCF0: addiu       $a2, $sp, 0x40
        ctx->r6 = ADD32(ctx->r29, 0X40);
            goto L_8003CD60;
    }
    // 0x8003CCF0: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x8003CCF4: lbu         $a0, 0xA($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0XA);
    // 0x8003CCF8: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    // 0x8003CCFC: sw          $v1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r3;
    // 0x8003CD00: jal         0x8001E3A0
    // 0x8003CD04: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    obj_bridge_pos(rdram, ctx);
        goto after_2;
    // 0x8003CD04: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    after_2:
    // 0x8003CD08: lw          $v1, 0x60($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X60);
    // 0x8003CD0C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8003CD10: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8003CD14: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x8003CD18: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8003CD1C: addiu       $t6, $v1, 0x4
    ctx->r14 = ADD32(ctx->r3, 0X4);
    // 0x8003CD20: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8003CD24: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8003CD28: jal         0x80009558
    // 0x8003CD2C: addiu       $a0, $zero, 0x249
    ctx->r4 = ADD32(0, 0X249);
    audspat_play_sound_at_position(rdram, ctx);
        goto after_3;
    // 0x8003CD2C: addiu       $a0, $zero, 0x249
    ctx->r4 = ADD32(0, 0X249);
    after_3:
    // 0x8003CD30: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x8003CD34: b           L_8003CD64
    // 0x8003CD38: lbu         $v1, 0xB($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0XB);
        goto L_8003CD64;
    // 0x8003CD38: lbu         $v1, 0xB($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0XB);
L_8003CD3C:
    // 0x8003CD3C: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    // 0x8003CD40: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    // 0x8003CD44: nop

    // 0x8003CD48: beq         $a0, $zero, L_8003CD60
    if (ctx->r4 == 0) {
        // 0x8003CD4C: nop
    
            goto L_8003CD60;
    }
    // 0x8003CD4C: nop

    // 0x8003CD50: jal         0x800096F8
    // 0x8003CD54: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    audspat_point_stop(rdram, ctx);
        goto after_4;
    // 0x8003CD54: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    after_4:
    // 0x8003CD58: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x8003CD5C: nop

L_8003CD60:
    // 0x8003CD60: lbu         $v1, 0xB($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0XB);
L_8003CD64:
    // 0x8003CD64: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003CD68: beq         $v1, $zero, L_8003CD80
    if (ctx->r3 == 0) {
        // 0x8003CD6C: nop
    
            goto L_8003CD80;
    }
    // 0x8003CD6C: nop

    // 0x8003CD70: beq         $v1, $at, L_8003CDAC
    if (ctx->r3 == ctx->r1) {
        // 0x8003CD74: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_8003CDAC;
    }
    // 0x8003CD74: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8003CD78: b           L_8003CE20
    // 0x8003CD7C: lbu         $a0, 0xA($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0XA);
        goto L_8003CE20;
    // 0x8003CD7C: lbu         $a0, 0xA($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0XA);
L_8003CD80:
    // 0x8003CD80: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x8003CD84: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
    // 0x8003CD88: lbu         $t8, 0xC($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0XC);
    // 0x8003CD8C: lbu         $t7, 0x13($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X13);
    // 0x8003CD90: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8003CD94: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8003CD98: beq         $at, $zero, L_8003CE6C
    if (ctx->r1 == 0) {
        // 0x8003CD9C: addiu       $t8, $zero, 0xFF
        ctx->r24 = ADD32(0, 0XFF);
            goto L_8003CE6C;
    }
    // 0x8003CD9C: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8003CDA0: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x8003CDA4: b           L_8003CE68
    // 0x8003CDA8: sw          $t9, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r25;
        goto L_8003CE68;
    // 0x8003CDA8: sw          $t9, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r25;
L_8003CDAC:
    // 0x8003CDAC: sw          $t1, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r9;
    // 0x8003CDB0: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    // 0x8003CDB4: jal         0x8001BAFC
    // 0x8003CDB8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    get_racer_object(rdram, ctx);
        goto after_5;
    // 0x8003CDB8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x8003CDBC: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x8003CDC0: beq         $v0, $zero, L_8003CE10
    if (ctx->r2 == 0) {
        // 0x8003CDC4: nop
    
            goto L_8003CE10;
    }
    // 0x8003CDC4: nop

    // 0x8003CDC8: lw          $a0, 0x64($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X64);
    // 0x8003CDCC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003CDD0: lb          $v1, 0x1D6($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X1D6);
    // 0x8003CDD4: nop

    // 0x8003CDD8: beq         $v1, $at, L_8003CDF0
    if (ctx->r3 == ctx->r1) {
        // 0x8003CDDC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8003CDF0;
    }
    // 0x8003CDDC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003CDE0: beq         $v1, $at, L_8003CDF8
    if (ctx->r3 == ctx->r1) {
        // 0x8003CDE4: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_8003CDF8;
    }
    // 0x8003CDE4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8003CDE8: b           L_8003CDF8
    // 0x8003CDEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8003CDF8;
    // 0x8003CDEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8003CDF0:
    // 0x8003CDF0: b           L_8003CDF8
    // 0x8003CDF4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8003CDF8;
    // 0x8003CDF4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8003CDF8:
    // 0x8003CDF8: lbu         $t2, 0xF($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0XF);
    // 0x8003CDFC: nop

    // 0x8003CE00: and         $t3, $t2, $v0
    ctx->r11 = ctx->r10 & ctx->r2;
    // 0x8003CE04: beq         $t3, $zero, L_8003CE10
    if (ctx->r11 == 0) {
        // 0x8003CE08: nop
    
            goto L_8003CE10;
    }
    // 0x8003CE08: nop

    // 0x8003CE0C: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
L_8003CE10:
    // 0x8003CE10: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x8003CE14: b           L_8003CE6C
    // 0x8003CE18: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
        goto L_8003CE6C;
    // 0x8003CE18: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8003CE1C: lbu         $a0, 0xA($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0XA);
L_8003CE20:
    // 0x8003CE20: jal         0x8001E320
    // 0x8003CE24: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    is_bridge_raised(rdram, ctx);
        goto after_6;
    // 0x8003CE24: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    after_6:
    // 0x8003CE28: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x8003CE2C: beq         $v0, $zero, L_8003CE44
    if (ctx->r2 == 0) {
        // 0x8003CE30: nop
    
            goto L_8003CE44;
    }
    // 0x8003CE30: nop

    // 0x8003CE34: lbu         $t4, 0xD($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0XD);
    // 0x8003CE38: nop

    // 0x8003CE3C: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8003CE40: sw          $t5, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r13;
L_8003CE44:
    // 0x8003CE44: lw          $v0, 0x78($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X78);
    // 0x8003CE48: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x8003CE4C: blez        $v0, L_8003CE5C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8003CE50: subu        $t7, $v0, $t6
        ctx->r15 = SUB32(ctx->r2, ctx->r14);
            goto L_8003CE5C;
    }
    // 0x8003CE50: subu        $t7, $v0, $t6
    ctx->r15 = SUB32(ctx->r2, ctx->r14);
    // 0x8003CE54: b           L_8003CE60
    // 0x8003CE58: sw          $t7, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r15;
        goto L_8003CE60;
    // 0x8003CE58: sw          $t7, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r15;
L_8003CE5C:
    // 0x8003CE5C: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
L_8003CE60:
    // 0x8003CE60: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x8003CE64: nop

L_8003CE68:
    // 0x8003CE68: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
L_8003CE6C:
    // 0x8003CE6C: sb          $t8, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r24;
    // 0x8003CE70: lw          $t9, 0x4C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4C);
    // 0x8003CE74: nop

    // 0x8003CE78: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    // 0x8003CE7C: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x8003CE80: nop

    // 0x8003CE84: lh          $t1, 0x14($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X14);
    // 0x8003CE88: nop

    // 0x8003CE8C: andi        $t2, $t1, 0xFFF7
    ctx->r10 = ctx->r9 & 0XFFF7;
    // 0x8003CE90: sh          $t2, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r10;
    // 0x8003CE94: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003CE98: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8003CE9C: jr          $ra
    // 0x8003CEA0: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8003CEA0: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void obj_init_rampswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003CEA4: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x8003CEA8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8003CEAC: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x8003CEB0: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x8003CEB4: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x8003CEB8: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
    // 0x8003CEBC: lw          $t0, 0x4C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4C);
    // 0x8003CEC0: nop

    // 0x8003CEC4: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x8003CEC8: lw          $t1, 0x4C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4C);
    // 0x8003CECC: nop

    // 0x8003CED0: sb          $zero, 0x12($t1)
    MEM_B(0X12, ctx->r9) = 0;
    // 0x8003CED4: lbu         $t2, 0x8($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X8);
    // 0x8003CED8: jr          $ra
    // 0x8003CEDC: sw          $t2, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r10;
    return;
    // 0x8003CEDC: sw          $t2, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r10;
;}
RECOMP_FUNC void obj_loop_rampswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003CEE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003CEE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003CEE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003CEEC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003CEF0: lw          $v0, 0x4C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4C);
    // 0x8003CEF4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8003CEF8: lbu         $t6, 0x13($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X13);
    // 0x8003CEFC: nop

    // 0x8003CF00: slti        $at, $t6, 0x2D
    ctx->r1 = SIGNED(ctx->r14) < 0X2D ? 1 : 0;
    // 0x8003CF04: beq         $at, $zero, L_8003CF2C
    if (ctx->r1 == 0) {
        // 0x8003CF08: addiu       $t7, $zero, 0xFF
        ctx->r15 = ADD32(0, 0XFF);
            goto L_8003CF2C;
    }
    // 0x8003CF08: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8003CF0C: lw          $a0, 0x78($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X78);
    // 0x8003CF10: jal         0x8001E378
    // 0x8003CF14: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    start_bridge_timer(rdram, ctx);
        goto after_0;
    // 0x8003CF14: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8003CF18: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8003CF1C: nop

    // 0x8003CF20: lw          $v0, 0x4C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4C);
    // 0x8003CF24: nop

    // 0x8003CF28: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
L_8003CF2C:
    // 0x8003CF2C: sb          $t7, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r15;
    // 0x8003CF30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003CF34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003CF38: jr          $ra
    // 0x8003CF3C: nop

    return;
    // 0x8003CF3C: nop

;}
RECOMP_FUNC void obj_init_seamonster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003CF40: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8003CF44: jr          $ra
    // 0x8003CF48: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8003CF48: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void obj_loop_seamonster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003CF4C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8003CF50: jr          $ra
    // 0x8003CF54: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8003CF54: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void obj_init_fogchanger(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003CF58: lbu         $t6, 0x8($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X8);
    // 0x8003CF5C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8003CF60: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8003CF64: bgez        $t6, L_8003CF78
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8003CF68: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8003CF78;
    }
    // 0x8003CF68: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003CF6C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003CF70: nop

    // 0x8003CF74: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8003CF78:
    // 0x8003CF78: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8003CF7C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003CF80: nop

    // 0x8003CF84: mul.s       $f0, $f6, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8003CF88: nop

    // 0x8003CF8C: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8003CF90: jr          $ra
    // 0x8003CF94: swc1        $f0, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x8003CF94: swc1        $f0, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->f0.u32l;
;}
RECOMP_FUNC void obj_init_skycontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003CF98: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x8003CF9C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8003CFA0: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x8003CFA4: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x8003CFA8: nop

    // 0x8003CFAC: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
    // 0x8003CFB0: lbu         $t9, 0x9($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X9);
    // 0x8003CFB4: lw          $t0, 0x4C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4C);
    // 0x8003CFB8: nop

    // 0x8003CFBC: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x8003CFC0: lbu         $t1, 0x8($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X8);
    // 0x8003CFC4: nop

    // 0x8003CFC8: sw          $t1, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r9;
    // 0x8003CFCC: lbu         $t2, 0x9($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X9);
    // 0x8003CFD0: jr          $ra
    // 0x8003CFD4: sw          $t2, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r10;
    return;
    // 0x8003CFD4: sw          $t2, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r10;
;}
RECOMP_FUNC void obj_loop_skycontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003CFD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003CFDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003CFE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003CFE4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003CFE8: lw          $t6, 0x4C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4C);
    // 0x8003CFEC: lw          $t8, 0x7C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X7C);
    // 0x8003CFF0: lbu         $t7, 0x13($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X13);
    // 0x8003CFF4: nop

    // 0x8003CFF8: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8003CFFC: beq         $at, $zero, L_8003D014
    if (ctx->r1 == 0) {
        // 0x8003D000: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8003D014;
    }
    // 0x8003D000: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003D004: lw          $a0, 0x78($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X78);
    // 0x8003D008: jal         0x80028084
    // 0x8003D00C: nop

    set_skydome_visbility(rdram, ctx);
        goto after_0;
    // 0x8003D00C: nop

    after_0:
    // 0x8003D010: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003D014:
    // 0x8003D014: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003D018: jr          $ra
    // 0x8003D01C: nop

    return;
    // 0x8003D01C: nop

;}
RECOMP_FUNC void obj_init_ainode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D020: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003D024: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003D028: lbu         $a2, 0x9($a1)
    ctx->r6 = MEM_BU(ctx->r5, 0X9);
    // 0x8003D02C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8003D030: bne         $a2, $at, L_8003D04C
    if (ctx->r6 != ctx->r1) {
        // 0x8003D034: nop
    
            goto L_8003D04C;
    }
    // 0x8003D034: nop

    // 0x8003D038: jal         0x8001C4C0
    // 0x8003D03C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    ainode_register(rdram, ctx);
        goto after_0;
    // 0x8003D03C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8003D040: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8003D044: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    // 0x8003D048: sb          $v0, 0x9($a1)
    MEM_B(0X9, ctx->r5) = ctx->r2;
L_8003D04C:
    // 0x8003D04C: jal         0x8001D1F0
    // 0x8003D050: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ainode_tail_set(rdram, ctx);
        goto after_1;
    // 0x8003D050: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x8003D054: jal         0x8001D1E0
    // 0x8003D058: nop

    ainode_enable(rdram, ctx);
        goto after_2;
    // 0x8003D058: nop

    after_2:
    // 0x8003D05C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003D060: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003D064: jr          $ra
    // 0x8003D068: nop

    return;
    // 0x8003D068: nop

;}
RECOMP_FUNC void obj_loop_ainode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D06C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8003D070: jr          $ra
    // 0x8003D074: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8003D074: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void obj_init_treasuresucker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D078: addiu       $t6, $zero, 0x78
    ctx->r14 = ADD32(0, 0X78);
    // 0x8003D07C: sh          $t6, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r14;
    // 0x8003D080: lb          $t7, 0x8($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X8);
    // 0x8003D084: nop

    // 0x8003D088: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8003D08C: andi        $t9, $t8, 0x3
    ctx->r25 = ctx->r24 & 0X3;
    // 0x8003D090: jr          $ra
    // 0x8003D094: sw          $t9, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r25;
    return;
    // 0x8003D094: sw          $t9, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r25;
;}
RECOMP_FUNC void obj_loop_treasuresucker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D098: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8003D09C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003D0A0: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8003D0A4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8003D0A8: lw          $a0, 0x78($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X78);
    // 0x8003D0AC: jal         0x8001BAFC
    // 0x8003D0B0: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    get_racer_object(rdram, ctx);
        goto after_0;
    // 0x8003D0B0: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_0:
    // 0x8003D0B4: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8003D0B8: beq         $v0, $zero, L_8003D2DC
    if (ctx->r2 == 0) {
        // 0x8003D0BC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8003D2DC;
    }
    // 0x8003D0BC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8003D0C0: lw          $a3, 0x64($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X64);
    // 0x8003D0C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8003D0C8: lb          $t6, 0x185($a3)
    ctx->r14 = MEM_B(ctx->r7, 0X185);
    // 0x8003D0CC: nop

    // 0x8003D0D0: beq         $t6, $zero, L_8003D144
    if (ctx->r14 == 0) {
        // 0x8003D0D4: nop
    
            goto L_8003D144;
    }
    // 0x8003D0D4: nop

    // 0x8003D0D8: lw          $t7, 0x7C($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X7C);
    // 0x8003D0DC: nop

    // 0x8003D0E0: bne         $t7, $zero, L_8003D144
    if (ctx->r15 != 0) {
        // 0x8003D0E4: nop
    
            goto L_8003D144;
    }
    // 0x8003D0E4: nop

    // 0x8003D0E8: lwc1        $f4, 0xC($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC);
    // 0x8003D0EC: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8003D0F0: lwc1        $f8, 0x10($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X10);
    // 0x8003D0F4: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8003D0F8: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8003D0FC: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8003D100: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8003D104: lwc1        $f16, 0x14($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X14);
    // 0x8003D108: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8003D10C: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8003D110: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8003D114: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003D118: lwc1        $f16, 0x6710($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6710);
    // 0x8003D11C: mul.s       $f10, $f12, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8003D120: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8003D124: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x8003D128: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8003D12C: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8003D130: nop

    // 0x8003D134: bc1f        L_8003D144
    if (!c1cs) {
        // 0x8003D138: nop
    
            goto L_8003D144;
    }
    // 0x8003D138: nop

    // 0x8003D13C: sw          $t8, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->r24;
    // 0x8003D140: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8003D144:
    // 0x8003D144: lw          $v0, 0x7C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X7C);
    // 0x8003D148: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x8003D14C: blez        $v0, L_8003D190
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8003D150: subu        $t0, $v0, $t9
        ctx->r8 = SUB32(ctx->r2, ctx->r25);
            goto L_8003D190;
    }
    // 0x8003D150: subu        $t0, $v0, $t9
    ctx->r8 = SUB32(ctx->r2, ctx->r25);
    // 0x8003D154: bgtz        $t0, L_8003D190
    if (SIGNED(ctx->r8) > 0) {
        // 0x8003D158: sw          $t0, 0x7C($a2)
        MEM_W(0X7C, ctx->r6) = ctx->r8;
            goto L_8003D190;
    }
    // 0x8003D158: sw          $t0, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->r8;
    // 0x8003D15C: lb          $v0, 0x185($a3)
    ctx->r2 = MEM_B(ctx->r7, 0X185);
    // 0x8003D160: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x8003D164: blez        $v0, L_8003D18C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8003D168: addiu       $t2, $v0, -0x1
        ctx->r10 = ADD32(ctx->r2, -0X1);
            goto L_8003D18C;
    }
    // 0x8003D168: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x8003D16C: sb          $t2, 0x185($a3)
    MEM_B(0X185, ctx->r7) = ctx->r10;
    // 0x8003D170: lb          $t3, 0x185($a3)
    ctx->r11 = MEM_B(ctx->r7, 0X185);
    // 0x8003D174: nop

    // 0x8003D178: beq         $t3, $zero, L_8003D184
    if (ctx->r11 == 0) {
        // 0x8003D17C: nop
    
            goto L_8003D184;
    }
    // 0x8003D17C: nop

    // 0x8003D180: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8003D184:
    // 0x8003D184: b           L_8003D190
    // 0x8003D188: sw          $t4, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->r12;
        goto L_8003D190;
    // 0x8003D188: sw          $t4, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->r12;
L_8003D18C:
    // 0x8003D18C: sw          $zero, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = 0;
L_8003D190:
    // 0x8003D190: beq         $a0, $zero, L_8003D2E0
    if (ctx->r4 == 0) {
        // 0x8003D194: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8003D2E0;
    }
    // 0x8003D194: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003D198: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8003D19C: lwc1        $f18, 0xC($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8003D1A0: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x8003D1A4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003D1A8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003D1AC: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x8003D1B0: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8003D1B4: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8003D1B8: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8003D1BC: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x8003D1C0: addiu       $t5, $zero, 0x61
    ctx->r13 = ADD32(0, 0X61);
    // 0x8003D1C4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8003D1C8: sh          $t6, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r14;
    // 0x8003D1CC: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8003D1D0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003D1D4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003D1D8: lwc1        $f6, 0x10($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8003D1DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8003D1E0: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8003D1E4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8003D1E8: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x8003D1EC: nop

    // 0x8003D1F0: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8003D1F4: addiu       $t1, $t0, 0xA
    ctx->r9 = ADD32(ctx->r8, 0XA);
    // 0x8003D1F8: sh          $t1, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r9;
    // 0x8003D1FC: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x8003D200: lwc1        $f10, 0x14($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8003D204: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003D208: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003D20C: sb          $t4, 0x25($sp)
    MEM_B(0X25, ctx->r29) = ctx->r12;
    // 0x8003D210: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8003D214: sb          $t5, 0x24($sp)
    MEM_B(0X24, ctx->r29) = ctx->r13;
    // 0x8003D218: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x8003D21C: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8003D220: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8003D224: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8003D228: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x8003D22C: jal         0x8000EA54
    // 0x8003D230: sh          $t3, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r11;
    spawn_object(rdram, ctx);
        goto after_1;
    // 0x8003D230: sh          $t3, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r11;
    after_1:
    // 0x8003D234: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x8003D238: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8003D23C: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x8003D240: beq         $v0, $zero, L_8003D2DC
    if (ctx->r2 == 0) {
        // 0x8003D244: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_8003D2DC;
    }
    // 0x8003D244: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8003D248: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003D24C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003D250: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003D254: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8003D258: mul.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x8003D25C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8003D260: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003D264: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x8003D268: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8003D26C: nop

    // 0x8003D270: div.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f8.d);
    // 0x8003D274: swc1        $f2, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f2.u32l;
    // 0x8003D278: lwc1        $f18, 0xC($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8003D27C: lwc1        $f16, 0xC($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0XC);
    // 0x8003D280: nop

    // 0x8003D284: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8003D288: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x8003D28C: nop

    // 0x8003D290: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8003D294: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
    // 0x8003D298: lwc1        $f10, 0x14($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8003D29C: lwc1        $f8, 0x14($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X14);
    // 0x8003D2A0: sw          $a3, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r7;
    // 0x8003D2A4: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8003D2A8: nop

    // 0x8003D2AC: div.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8003D2B0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8003D2B4: swc1        $f18, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f18.u32l;
    // 0x8003D2B8: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8003D2BC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003D2C0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003D2C4: nop

    // 0x8003D2C8: cvt.w.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = CVT_W_S(ctx->f0.fl);
    // 0x8003D2CC: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x8003D2D0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8003D2D4: sw          $t7, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->r15;
    // 0x8003D2D8: nop

L_8003D2DC:
    // 0x8003D2DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003D2E0:
    // 0x8003D2E0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8003D2E4: jr          $ra
    // 0x8003D2E8: nop

    return;
    // 0x8003D2E8: nop

;}
RECOMP_FUNC void obj_init_flycoin(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D2EC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8003D2F0: jr          $ra
    // 0x8003D2F4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8003D2F4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void obj_loop_flycoin(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D2F8: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8003D2FC: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x8003D300: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003D304: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x8003D308: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8003D30C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003D310: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003D314: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003D318: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8003D31C: bne         $t7, $zero, L_8003D33C
    if (ctx->r15 != 0) {
        // 0x8003D320: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_8003D33C;
    }
    // 0x8003D320: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8003D324: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003D328: lwc1        $f9, 0x6718($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6718);
    // 0x8003D32C: lwc1        $f8, 0x671C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X671C);
    // 0x8003D330: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x8003D334: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8003D338: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_8003D33C:
    // 0x8003D33C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8003D340: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8003D344: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8003D348: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x8003D34C: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x8003D350: lwc1        $f6, 0x20($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8003D354: lwc1        $f18, 0x1C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8003D358: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8003D35C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003D360: sub.d       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f8.d - ctx->f4.d;
    // 0x8003D364: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8003D368: lwc1        $f10, 0x24($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8003D36C: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8003D370: swc1        $f16, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f16.u32l;
    // 0x8003D374: lwc1        $f8, 0x20($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8003D378: nop

    // 0x8003D37C: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8003D380: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8003D384: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8003D388: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8003D38C: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x8003D390: jal         0x80011570
    // 0x8003D394: nop

    move_object(rdram, ctx);
        goto after_0;
    // 0x8003D394: nop

    after_0:
    // 0x8003D398: lw          $t8, 0x78($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X78);
    // 0x8003D39C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8003D3A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003D3A4: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x8003D3A8: bgtz        $t0, L_8003D408
    if (SIGNED(ctx->r8) > 0) {
        // 0x8003D3AC: sw          $t0, 0x78($s0)
        MEM_W(0X78, ctx->r16) = ctx->r8;
            goto L_8003D408;
    }
    // 0x8003D3AC: sw          $t0, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r8;
    // 0x8003D3B0: lw          $v0, 0x7C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X7C);
    // 0x8003D3B4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8003D3B8: lb          $t2, 0x193($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X193);
    // 0x8003D3BC: nop

    // 0x8003D3C0: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8003D3C4: sb          $t3, 0x193($v0)
    MEM_B(0X193, ctx->r2) = ctx->r11;
    // 0x8003D3C8: lb          $t4, 0x193($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X193);
    // 0x8003D3CC: nop

    // 0x8003D3D0: slti        $at, $t4, 0xA
    ctx->r1 = SIGNED(ctx->r12) < 0XA ? 1 : 0;
    // 0x8003D3D4: bne         $at, $zero, L_8003D3E0
    if (ctx->r1 != 0) {
        // 0x8003D3D8: nop
    
            goto L_8003D3E0;
    }
    // 0x8003D3D8: nop

    // 0x8003D3DC: sb          $t5, 0x1D8($v0)
    MEM_B(0X1D8, ctx->r2) = ctx->r13;
L_8003D3E0:
    // 0x8003D3E0: jal         0x8000FFB8
    // 0x8003D3E4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    free_object(rdram, ctx);
        goto after_1;
    // 0x8003D3E4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_1:
    // 0x8003D3E8: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8003D3EC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003D3F0: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x8003D3F4: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    // 0x8003D3F8: beq         $t6, $at, L_8003D40C
    if (ctx->r14 == ctx->r1) {
        // 0x8003D3FC: lw          $t8, 0x2C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X2C);
            goto L_8003D40C;
    }
    // 0x8003D3FC: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8003D400: jal         0x80001D04
    // 0x8003D404: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x8003D404: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
L_8003D408:
    // 0x8003D408: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
L_8003D40C:
    // 0x8003D40C: lh          $t7, 0x18($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X18);
    // 0x8003D410: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8003D414: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8003D418: sh          $t0, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r8;
    // 0x8003D41C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003D420: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003D424: jr          $ra
    // 0x8003D428: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8003D428: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void obj_init_bananacreator(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D42C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8003D430: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x8003D434: jr          $ra
    // 0x8003D438: sh          $t6, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r14;
    return;
    // 0x8003D438: sh          $t6, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void obj_loop_bananacreator(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D43C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8003D440: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8003D444: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8003D448: lw          $t6, 0x7C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7C);
    // 0x8003D44C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003D450: beq         $t6, $zero, L_8003D468
    if (ctx->r14 == 0) {
        // 0x8003D454: nop
    
            goto L_8003D468;
    }
    // 0x8003D454: nop

    // 0x8003D458: lw          $t7, 0x78($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X78);
    // 0x8003D45C: nop

    // 0x8003D460: subu        $t8, $t7, $a1
    ctx->r24 = SUB32(ctx->r15, ctx->r5);
    // 0x8003D464: sw          $t8, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r24;
L_8003D468:
    // 0x8003D468: lw          $t9, 0x78($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X78);
    // 0x8003D46C: nop

    // 0x8003D470: bgtz        $t9, L_8003D568
    if (SIGNED(ctx->r25) > 0) {
        // 0x8003D474: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8003D568;
    }
    // 0x8003D474: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8003D478: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8003D47C: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003D480: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x8003D484: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003D488: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003D48C: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x8003D490: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8003D494: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8003D498: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8003D49C: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x8003D4A0: addiu       $t0, $zero, 0x53
    ctx->r8 = ADD32(0, 0X53);
    // 0x8003D4A4: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8003D4A8: sh          $t1, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r9;
    // 0x8003D4AC: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x8003D4B0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003D4B4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003D4B8: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003D4BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8003D4C0: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8003D4C4: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8003D4C8: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x8003D4CC: nop

    // 0x8003D4D0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8003D4D4: addiu       $t6, $t5, -0x3
    ctx->r14 = ADD32(ctx->r13, -0X3);
    // 0x8003D4D8: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8003D4DC: sh          $t6, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r14;
    // 0x8003D4E0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003D4E4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003D4E8: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003D4EC: sb          $t9, 0x39($sp)
    MEM_B(0X39, ctx->r29) = ctx->r25;
    // 0x8003D4F0: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8003D4F4: sb          $t0, 0x38($sp)
    MEM_B(0X38, ctx->r29) = ctx->r8;
    // 0x8003D4F8: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x8003D4FC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8003D500: jal         0x8000EA54
    // 0x8003D504: sh          $t8, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r24;
    spawn_object(rdram, ctx);
        goto after_0;
    // 0x8003D504: sh          $t8, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r24;
    after_0:
    // 0x8003D508: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8003D50C: beq         $v0, $zero, L_8003D55C
    if (ctx->r2 == 0) {
        // 0x8003D510: sw          $t1, 0x7C($s0)
        MEM_W(0X7C, ctx->r16) = ctx->r9;
            goto L_8003D55C;
    }
    // 0x8003D510: sw          $t1, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r9;
    // 0x8003D514: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x8003D518: lw          $v0, 0x64($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X64);
    // 0x8003D51C: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x8003D520: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
    // 0x8003D524: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003D528: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003D52C: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8003D530: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x8003D534: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003D538: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003D53C: addiu       $t2, $zero, 0x22
    ctx->r10 = ADD32(0, 0X22);
    // 0x8003D540: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8003D544: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8003D548: addiu       $a3, $zero, 0x2C
    ctx->r7 = ADD32(0, 0X2C);
    // 0x8003D54C: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8003D550: jal         0x8003FC84
    // 0x8003D554: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    obj_spawn_effect(rdram, ctx);
        goto after_1;
    // 0x8003D554: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x8003D558: sw          $zero, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = 0;
L_8003D55C:
    // 0x8003D55C: addiu       $t3, $zero, 0x4B0
    ctx->r11 = ADD32(0, 0X4B0);
    // 0x8003D560: sw          $t3, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r11;
    // 0x8003D564: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8003D568:
    // 0x8003D568: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8003D56C: jr          $ra
    // 0x8003D570: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8003D570: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void obj_init_banana(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D574: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003D578: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003D57C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003D580: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x8003D584: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8003D588: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x8003D58C: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x8003D590: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x8003D594: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
    // 0x8003D598: lw          $t0, 0x4C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4C);
    // 0x8003D59C: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
    // 0x8003D5A0: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x8003D5A4: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x8003D5A8: sh          $t1, 0x7C($a0)
    MEM_H(0X7C, ctx->r4) = ctx->r9;
    // 0x8003D5AC: sh          $t2, 0x7E($a0)
    MEM_H(0X7E, ctx->r4) = ctx->r10;
    // 0x8003D5B0: jal         0x8009C850
    // 0x8003D5B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    get_filtered_cheats(rdram, ctx);
        goto after_0;
    // 0x8003D5B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003D5B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003D5BC: andi        $t3, $v0, 0x1000
    ctx->r11 = ctx->r2 & 0X1000;
    // 0x8003D5C0: beq         $t3, $zero, L_8003D5D4
    if (ctx->r11 == 0) {
        // 0x8003D5C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8003D5D4;
    }
    // 0x8003D5C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003D5C8: jal         0x8000FFB8
    // 0x8003D5CC: nop

    free_object(rdram, ctx);
        goto after_1;
    // 0x8003D5CC: nop

    after_1:
    // 0x8003D5D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003D5D4:
    // 0x8003D5D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003D5D8: jr          $ra
    // 0x8003D5DC: nop

    return;
    // 0x8003D5DC: nop

;}
RECOMP_FUNC void obj_loop_banana(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D5E0: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8003D5E4: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x8003D5E8: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003D5EC: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x8003D5F0: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8003D5F4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8003D5F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003D5FC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003D600: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x8003D604: bne         $t7, $zero, L_8003D624
    if (ctx->r15 != 0) {
        // 0x8003D608: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_8003D624;
    }
    // 0x8003D608: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8003D60C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003D610: lwc1        $f9, 0x6720($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6720);
    // 0x8003D614: lwc1        $f8, 0x6724($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6724);
    // 0x8003D618: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x8003D61C: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8003D620: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_8003D624:
    // 0x8003D624: lw          $t8, 0x64($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X64);
    // 0x8003D628: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x8003D62C: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x8003D630: lh          $t9, 0x18($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X18);
    // 0x8003D634: lw          $t5, 0x78($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X78);
    // 0x8003D638: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x8003D63C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003D640: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x8003D644: bne         $t5, $at, L_8003D6AC
    if (ctx->r13 != ctx->r1) {
        // 0x8003D648: sh          $t4, 0x18($s0)
        MEM_H(0X18, ctx->r16) = ctx->r12;
            goto L_8003D6AC;
    }
    // 0x8003D648: sh          $t4, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r12;
    // 0x8003D64C: lh          $t6, 0x6($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X6);
    // 0x8003D650: addiu       $t1, $s0, 0x78
    ctx->r9 = ADD32(ctx->r16, 0X78);
    // 0x8003D654: ori         $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 | 0X4000;
    // 0x8003D658: sh          $t7, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r15;
    // 0x8003D65C: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x8003D660: lh          $t8, 0x6($t1)
    ctx->r24 = MEM_H(ctx->r9, 0X6);
    // 0x8003D664: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8003D668: subu        $t9, $t8, $t2
    ctx->r25 = SUB32(ctx->r24, ctx->r10);
    // 0x8003D66C: sh          $t9, 0x6($t1)
    MEM_H(0X6, ctx->r9) = ctx->r25;
    // 0x8003D670: sw          $t3, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r11;
    // 0x8003D674: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x8003D678: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x8003D67C: jal         0x800B019C
    // 0x8003D680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    obj_spawn_particle(rdram, ctx);
        goto after_0;
    // 0x8003D680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8003D684: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8003D688: nop

    // 0x8003D68C: lh          $t4, 0x6($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X6);
    // 0x8003D690: nop

    // 0x8003D694: bgtz        $t4, L_8003DBD4
    if (SIGNED(ctx->r12) > 0) {
        // 0x8003D698: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8003DBD4;
    }
    // 0x8003D698: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003D69C: jal         0x8000FFB8
    // 0x8003D6A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    free_object(rdram, ctx);
        goto after_1;
    // 0x8003D6A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8003D6A4: b           L_8003DBD4
    // 0x8003D6A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8003DBD4;
    // 0x8003D6A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8003D6AC:
    // 0x8003D6AC: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8003D6B0: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x8003D6B4: lb          $v0, 0x8($t5)
    ctx->r2 = MEM_B(ctx->r13, 0X8);
    // 0x8003D6B8: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8003D6BC: blez        $v0, L_8003D6D0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8003D6C0: addiu       $t1, $s0, 0x78
        ctx->r9 = ADD32(ctx->r16, 0X78);
            goto L_8003D6D0;
    }
    // 0x8003D6C0: addiu       $t1, $s0, 0x78
    ctx->r9 = ADD32(ctx->r16, 0X78);
    // 0x8003D6C4: subu        $t7, $v0, $t6
    ctx->r15 = SUB32(ctx->r2, ctx->r14);
    // 0x8003D6C8: b           L_8003D6D8
    // 0x8003D6CC: sb          $t7, 0x8($t5)
    MEM_B(0X8, ctx->r13) = ctx->r15;
        goto L_8003D6D8;
    // 0x8003D6CC: sb          $t7, 0x8($t5)
    MEM_B(0X8, ctx->r13) = ctx->r15;
L_8003D6D0:
    // 0x8003D6D0: sb          $zero, 0x8($t8)
    MEM_B(0X8, ctx->r24) = 0;
    // 0x8003D6D4: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
L_8003D6D8:
    // 0x8003D6D8: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8003D6DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003D6E0: bne         $t2, $at, L_8003D950
    if (ctx->r10 != ctx->r1) {
        // 0x8003D6E4: lw          $t5, 0x3C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X3C);
            goto L_8003D950;
    }
    // 0x8003D6E4: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8003D6E8: lwc1        $f18, 0x1C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8003D6EC: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003D6F0: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8003D6F4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8003D6F8: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    // 0x8003D6FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8003D700: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8003D704: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    // 0x8003D708: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    // 0x8003D70C: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8003D710: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003D714: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8003D718: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x8003D71C: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8003D720: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003D724: swc1        $f16, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f16.u32l;
    // 0x8003D728: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8003D72C: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003D730: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8003D734: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x8003D738: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x8003D73C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8003D740: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8003D744: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
    // 0x8003D748: jal         0x80031170
    // 0x8003D74C: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
    generate_collision_candidates(rdram, ctx);
        goto after_2;
    // 0x8003D74C: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x8003D750: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8003D754: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8003D758: addiu       $t3, $sp, 0x48
    ctx->r11 = ADD32(ctx->r29, 0X48);
    // 0x8003D75C: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x8003D760: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8003D764: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8003D768: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x8003D76C: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    // 0x8003D770: jal         0x80031640
    // 0x8003D774: addiu       $a3, $sp, 0x43
    ctx->r7 = ADD32(ctx->r29, 0X43);
    resolve_collisions(rdram, ctx);
        goto after_3;
    // 0x8003D774: addiu       $a3, $sp, 0x43
    ctx->r7 = ADD32(ctx->r29, 0X43);
    after_3:
    // 0x8003D778: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8003D77C: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003D780: lwc1        $f0, 0x54($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8003D784: sub.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x8003D788: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8003D78C: div.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8003D790: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003D794: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003D798: mtc1        $zero, $f13
    ctx->f_odd[(13 - 1) * 2] = 0;
    // 0x8003D79C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003D7A0: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x8003D7A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003D7A8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8003D7AC: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
    // 0x8003D7B0: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8003D7B4: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003D7B8: sub.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x8003D7BC: nop

    // 0x8003D7C0: div.s       $f6, $f16, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8003D7C4: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    // 0x8003D7C8: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8003D7CC: nop

    // 0x8003D7D0: sub.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8003D7D4: nop

    // 0x8003D7D8: div.s       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8003D7DC: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
    // 0x8003D7E0: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8003D7E4: nop

    // 0x8003D7E8: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x8003D7EC: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8003D7F0: nop

    // 0x8003D7F4: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x8003D7F8: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8003D7FC: nop

    // 0x8003D800: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    // 0x8003D804: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8003D808: nop

    // 0x8003D80C: lb          $t6, 0x9($t4)
    ctx->r14 = MEM_B(ctx->r12, 0X9);
    // 0x8003D810: nop

    // 0x8003D814: beq         $t6, $at, L_8003D870
    if (ctx->r14 == ctx->r1) {
        // 0x8003D818: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8003D870;
    }
    // 0x8003D818: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003D81C: lwc1        $f1, 0x6728($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, 0X6728);
    // 0x8003D820: lwc1        $f0, 0x672C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X672C);
    // 0x8003D824: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8003D828: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8003D82C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8003D830: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8003D834: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x8003D838: sub.d       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = ctx->f8.d - ctx->f18.d;
    // 0x8003D83C: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8003D840: cvt.s.d     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f6.fl = CVT_S_D(ctx->f16.d);
    // 0x8003D844: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8003D848: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8003D84C: mul.d       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x8003D850: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    // 0x8003D854: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x8003D858: mul.d       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x8003D85C: cvt.s.d     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f18.fl = CVT_S_D(ctx->f8.d);
    // 0x8003D860: swc1        $f18, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f18.u32l;
    // 0x8003D864: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x8003D868: b           L_8003D884
    // 0x8003D86C: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
        goto L_8003D884;
    // 0x8003D86C: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
L_8003D870:
    // 0x8003D870: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003D874: nop

    // 0x8003D878: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x8003D87C: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x8003D880: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
L_8003D884:
    // 0x8003D884: lwc1        $f2, 0x1C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8003D888: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8003D88C: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x8003D890: c.lt.d      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.d < ctx->f12.d;
    // 0x8003D894: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x8003D898: bc1f        L_8003D8A4
    if (!c1cs) {
        // 0x8003D89C: lui         $at, 0x3FE0
        ctx->r1 = S32(0X3FE0 << 16);
            goto L_8003D8A4;
    }
    // 0x8003D89C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8003D8A0: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
L_8003D8A4:
    // 0x8003D8A4: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8003D8A8: nop

    // 0x8003D8AC: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x8003D8B0: c.lt.d      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.d < ctx->f12.d;
    // 0x8003D8B4: nop

    // 0x8003D8B8: bc1f        L_8003D8C4
    if (!c1cs) {
        // 0x8003D8BC: nop
    
            goto L_8003D8C4;
    }
    // 0x8003D8BC: nop

    // 0x8003D8C0: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_8003D8C4:
    // 0x8003D8C4: blez        $t7, L_8003D900
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8003D8C8: nop
    
            goto L_8003D900;
    }
    // 0x8003D8C8: nop

    // 0x8003D8CC: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x8003D8D0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8003D8D4: cvt.d.s     $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f16.d = CVT_D_S(ctx->f2.fl);
    // 0x8003D8D8: c.lt.d      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.d < ctx->f12.d;
    // 0x8003D8DC: nop

    // 0x8003D8E0: bc1f        L_8003D900
    if (!c1cs) {
        // 0x8003D8E4: nop
    
            goto L_8003D900;
    }
    // 0x8003D8E4: nop

    // 0x8003D8E8: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8003D8EC: c.lt.d      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.d < ctx->f12.d;
    // 0x8003D8F0: nop

    // 0x8003D8F4: bc1f        L_8003D900
    if (!c1cs) {
        // 0x8003D8F8: nop
    
            goto L_8003D900;
    }
    // 0x8003D8F8: nop

    // 0x8003D8FC: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
L_8003D900:
    // 0x8003D900: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003D904: lwc1        $f4, 0x6730($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6730);
    // 0x8003D908: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x8003D90C: jal         0x8002B9FC
    // 0x8003D910: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    func_8002B9BC(rdram, ctx);
        goto after_4;
    // 0x8003D910: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x8003D914: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8003D918: beq         $v0, $zero, L_8003D950
    if (ctx->r2 == 0) {
        // 0x8003D91C: lw          $t5, 0x3C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X3C);
            goto L_8003D950;
    }
    // 0x8003D91C: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8003D920: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003D924: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8003D928: nop

    // 0x8003D92C: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x8003D930: nop

    // 0x8003D934: bc1f        L_8003D950
    if (!c1cs) {
        // 0x8003D938: lw          $t5, 0x3C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X3C);
            goto L_8003D950;
    }
    // 0x8003D938: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8003D93C: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x8003D940: lwc1        $f18, 0x58($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8003D944: nop

    // 0x8003D948: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
    // 0x8003D94C: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
L_8003D950:
    // 0x8003D950: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003D954: lb          $t8, 0x9($t5)
    ctx->r24 = MEM_B(ctx->r13, 0X9);
    // 0x8003D958: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x8003D95C: beq         $t8, $at, L_8003D968
    if (ctx->r24 == ctx->r1) {
        // 0x8003D960: addiu       $a0, $zero, 0x46
        ctx->r4 = ADD32(0, 0X46);
            goto L_8003D968;
    }
    // 0x8003D960: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
    // 0x8003D964: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
L_8003D968:
    // 0x8003D968: lh          $v0, 0x4($t1)
    ctx->r2 = MEM_H(ctx->r9, 0X4);
    // 0x8003D96C: nop

    // 0x8003D970: blez        $v0, L_8003D980
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8003D974: subu        $t9, $v0, $t2
        ctx->r25 = SUB32(ctx->r2, ctx->r10);
            goto L_8003D980;
    }
    // 0x8003D974: subu        $t9, $v0, $t2
    ctx->r25 = SUB32(ctx->r2, ctx->r10);
    // 0x8003D978: b           L_8003D984
    // 0x8003D97C: sh          $t9, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r25;
        goto L_8003D984;
    // 0x8003D97C: sh          $t9, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r25;
L_8003D980:
    // 0x8003D980: sh          $zero, 0x4($t1)
    MEM_H(0X4, ctx->r9) = 0;
L_8003D984:
    // 0x8003D984: lw          $t3, 0x4C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4C);
    // 0x8003D988: nop

    // 0x8003D98C: lbu         $t4, 0x13($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X13);
    // 0x8003D990: nop

    // 0x8003D994: slti        $at, $t4, 0x78
    ctx->r1 = SIGNED(ctx->r12) < 0X78 ? 1 : 0;
    // 0x8003D998: beq         $at, $zero, L_8003DA0C
    if (ctx->r1 == 0) {
        // 0x8003D99C: nop
    
            goto L_8003DA0C;
    }
    // 0x8003D99C: nop

    // 0x8003D9A0: sw          $a0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r4;
    // 0x8003D9A4: jal         0x8006BFD8
    // 0x8003D9A8: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    level_type(rdram, ctx);
        goto after_5;
    // 0x8003D9A8: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    after_5:
    // 0x8003D9AC: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8003D9B0: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8003D9B4: addiu       $at, $zero, 0x41
    ctx->r1 = ADD32(0, 0X41);
    // 0x8003D9B8: bne         $v0, $at, L_8003DA0C
    if (ctx->r2 != ctx->r1) {
        // 0x8003D9BC: nop
    
            goto L_8003DA0C;
    }
    // 0x8003D9BC: nop

    // 0x8003D9C0: lw          $t6, 0x4C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4C);
    // 0x8003D9C4: nop

    // 0x8003D9C8: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    // 0x8003D9CC: nop

    // 0x8003D9D0: beq         $v1, $zero, L_8003DA0C
    if (ctx->r3 == 0) {
        // 0x8003D9D4: nop
    
            goto L_8003DA0C;
    }
    // 0x8003D9D4: nop

    // 0x8003D9D8: lw          $t7, 0x40($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X40);
    // 0x8003D9DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003D9E0: lb          $t5, 0x54($t7)
    ctx->r13 = MEM_B(ctx->r15, 0X54);
    // 0x8003D9E4: nop

    // 0x8003D9E8: bne         $t5, $at, L_8003DA0C
    if (ctx->r13 != ctx->r1) {
        // 0x8003D9EC: nop
    
            goto L_8003DA0C;
    }
    // 0x8003D9EC: nop

    // 0x8003D9F0: lw          $t0, 0x64($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X64);
    // 0x8003D9F4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003D9F8: lh          $t8, 0x0($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X0);
    // 0x8003D9FC: nop

    // 0x8003DA00: bne         $t8, $at, L_8003DA0C
    if (ctx->r24 != ctx->r1) {
        // 0x8003DA04: nop
    
            goto L_8003DA0C;
    }
    // 0x8003DA04: nop

    // 0x8003DA08: addiu       $a0, $a0, 0x1E
    ctx->r4 = ADD32(ctx->r4, 0X1E);
L_8003DA0C:
    // 0x8003DA0C: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x8003DA10: nop

    // 0x8003DA14: lbu         $t2, 0x13($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X13);
    // 0x8003DA18: nop

    // 0x8003DA1C: slt         $at, $t2, $a0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8003DA20: beq         $at, $zero, L_8003DBD4
    if (ctx->r1 == 0) {
        // 0x8003DA24: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8003DBD4;
    }
    // 0x8003DA24: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003DA28: lh          $t9, 0x4($t1)
    ctx->r25 = MEM_H(ctx->r9, 0X4);
    // 0x8003DA2C: nop

    // 0x8003DA30: bne         $t9, $zero, L_8003DBD4
    if (ctx->r25 != 0) {
        // 0x8003DA34: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8003DBD4;
    }
    // 0x8003DA34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003DA38: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8003DA3C: nop

    // 0x8003DA40: beq         $v1, $zero, L_8003DBD4
    if (ctx->r3 == 0) {
        // 0x8003DA44: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8003DBD4;
    }
    // 0x8003DA44: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003DA48: lw          $t3, 0x40($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X40);
    // 0x8003DA4C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003DA50: lb          $t4, 0x54($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X54);
    // 0x8003DA54: nop

    // 0x8003DA58: bne         $t4, $at, L_8003DBD4
    if (ctx->r12 != ctx->r1) {
        // 0x8003DA5C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8003DBD4;
    }
    // 0x8003DA5C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003DA60: lw          $t0, 0x64($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X64);
    // 0x8003DA64: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x8003DA68: sw          $v1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r3;
    // 0x8003DA6C: jal         0x8006BFD8
    // 0x8003DA70: sw          $t0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r8;
    level_type(rdram, ctx);
        goto after_6;
    // 0x8003DA70: sw          $t0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r8;
    after_6:
    // 0x8003DA74: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
    // 0x8003DA78: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x8003DA7C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8003DA80: addiu       $at, $zero, 0x41
    ctx->r1 = ADD32(0, 0X41);
    // 0x8003DA84: bne         $v0, $at, L_8003DAA0
    if (ctx->r2 != ctx->r1) {
        // 0x8003DA88: addiu       $a0, $zero, 0x22
        ctx->r4 = ADD32(0, 0X22);
            goto L_8003DAA0;
    }
    // 0x8003DA88: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    // 0x8003DA8C: lb          $t6, 0x185($t0)
    ctx->r14 = MEM_B(ctx->r8, 0X185);
    // 0x8003DA90: nop

    // 0x8003DA94: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x8003DA98: beq         $at, $zero, L_8003DBD4
    if (ctx->r1 == 0) {
        // 0x8003DA9C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8003DBD4;
    }
    // 0x8003DA9C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8003DAA0:
    // 0x8003DAA0: lw          $t7, 0x180($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X180);
    // 0x8003DAA4: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x8003DAA8: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x8003DAAC: lw          $a3, 0x14($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X14);
    // 0x8003DAB0: lw          $a2, 0x10($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X10);
    // 0x8003DAB4: lw          $a1, 0xC($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XC);
    // 0x8003DAB8: addiu       $t8, $t0, 0x180
    ctx->r24 = ADD32(ctx->r8, 0X180);
    // 0x8003DABC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8003DAC0: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x8003DAC4: sw          $t0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r8;
    // 0x8003DAC8: sw          $v1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r3;
    // 0x8003DACC: jal         0x80009558
    // 0x8003DAD0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_7;
    // 0x8003DAD0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_7:
    // 0x8003DAD4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8003DAD8: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
    // 0x8003DADC: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x8003DAE0: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8003DAE4: beq         $a0, $zero, L_8003DB0C
    if (ctx->r4 == 0) {
        // 0x8003DAE8: nop
    
            goto L_8003DB0C;
    }
    // 0x8003DAE8: nop

    // 0x8003DAEC: sw          $v1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r3;
    // 0x8003DAF0: sw          $t0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r8;
    // 0x8003DAF4: jal         0x800096F8
    // 0x8003DAF8: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    audspat_point_stop(rdram, ctx);
        goto after_8;
    // 0x8003DAF8: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    after_8:
    // 0x8003DAFC: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
    // 0x8003DB00: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x8003DB04: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8003DB08: nop

L_8003DB0C:
    // 0x8003DB0C: lh          $t2, 0x0($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X0);
    // 0x8003DB10: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003DB14: beq         $t2, $at, L_8003DB64
    if (ctx->r10 == ctx->r1) {
        // 0x8003DB18: nop
    
            goto L_8003DB64;
    }
    // 0x8003DB18: nop

    // 0x8003DB1C: lb          $t9, 0x185($t0)
    ctx->r25 = MEM_B(ctx->r8, 0X185);
    // 0x8003DB20: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8003DB24: bne         $t9, $at, L_8003DB64
    if (ctx->r25 != ctx->r1) {
        // 0x8003DB28: nop
    
            goto L_8003DB64;
    }
    // 0x8003DB28: nop

    // 0x8003DB2C: lb          $a0, 0x3($t0)
    ctx->r4 = MEM_B(ctx->r8, 0X3);
    // 0x8003DB30: lw          $a1, 0xC($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XC);
    // 0x8003DB34: lw          $a2, 0x10($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X10);
    // 0x8003DB38: lw          $a3, 0x14($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X14);
    // 0x8003DB3C: addiu       $a0, $a0, 0x7B
    ctx->r4 = ADD32(ctx->r4, 0X7B);
    // 0x8003DB40: andi        $t3, $a0, 0xFFFF
    ctx->r11 = ctx->r4 & 0XFFFF;
    // 0x8003DB44: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x8003DB48: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x8003DB4C: sw          $t0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r8;
    // 0x8003DB50: jal         0x80001EA8
    // 0x8003DB54: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    sound_play_spatial(rdram, ctx);
        goto after_9;
    // 0x8003DB54: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_9:
    // 0x8003DB58: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x8003DB5C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8003DB60: nop

L_8003DB64:
    // 0x8003DB64: lb          $t4, 0x185($t0)
    ctx->r12 = MEM_B(ctx->r8, 0X185);
    // 0x8003DB68: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8003DB6C: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x8003DB70: sb          $t6, 0x185($t0)
    MEM_B(0X185, ctx->r8) = ctx->r14;
    // 0x8003DB74: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8003DB78: nop

    // 0x8003DB7C: lw          $v0, 0x4($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X4);
    // 0x8003DB80: nop

    // 0x8003DB84: beq         $v0, $zero, L_8003DB90
    if (ctx->r2 == 0) {
        // 0x8003DB88: nop
    
            goto L_8003DB90;
    }
    // 0x8003DB88: nop

    // 0x8003DB8C: sw          $t5, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r13;
L_8003DB90:
    // 0x8003DB90: jal         0x8009C90C
    // 0x8003DB94: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    get_number_of_active_players(rdram, ctx);
        goto after_10;
    // 0x8003DB94: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    after_10:
    // 0x8003DB98: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8003DB9C: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8003DBA0: bne         $at, $zero, L_8003DBB8
    if (ctx->r1 != 0) {
        // 0x8003DBA4: addiu       $t8, $zero, -0x1
        ctx->r24 = ADD32(0, -0X1);
            goto L_8003DBB8;
    }
    // 0x8003DBA4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8003DBA8: jal         0x8000FFB8
    // 0x8003DBAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    free_object(rdram, ctx);
        goto after_11;
    // 0x8003DBAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8003DBB0: b           L_8003DBD4
    // 0x8003DBB4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8003DBD4;
    // 0x8003DBB4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8003DBB8:
    // 0x8003DBB8: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8003DBBC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8003DBC0: sw          $t2, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r10;
    // 0x8003DBC4: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x8003DBC8: jal         0x800B019C
    // 0x8003DBCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    obj_spawn_particle(rdram, ctx);
        goto after_12;
    // 0x8003DBCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8003DBD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8003DBD4:
    // 0x8003DBD4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8003DBD8: jr          $ra
    // 0x8003DBDC: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8003DBDC: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void obj_init_silvercoin_adv2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DBE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003DBE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003DBE8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003DBEC: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x8003DBF0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8003DBF4: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x8003DBF8: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x8003DBFC: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x8003DC00: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
    // 0x8003DC04: lw          $t0, 0x4C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4C);
    // 0x8003DC08: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8003DC0C: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x8003DC10: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x8003DC14: sw          $t1, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r9;
    // 0x8003DC18: sw          $t2, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r10;
    // 0x8003DC1C: jal         0x8009C814
    // 0x8003DC20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    is_in_tracks_mode(rdram, ctx);
        goto after_0;
    // 0x8003DC20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003DC24: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003DC28: bne         $v0, $zero, L_8003DC68
    if (ctx->r2 != 0) {
        // 0x8003DC2C: nop
    
            goto L_8003DC68;
    }
    // 0x8003DC2C: nop

    // 0x8003DC30: jal         0x8000E1DC
    // 0x8003DC34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    check_if_silver_coin_race(rdram, ctx);
        goto after_1;
    // 0x8003DC34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x8003DC38: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003DC3C: beq         $v0, $zero, L_8003DC64
    if (ctx->r2 == 0) {
        // 0x8003DC40: addiu       $t3, $zero, 0x3
        ctx->r11 = ADD32(0, 0X3);
            goto L_8003DC64;
    }
    // 0x8003DC40: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8003DC44: jal         0x8009F1B4
    // 0x8003DC48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    is_in_adventure_two(rdram, ctx);
        goto after_2;
    // 0x8003DC48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x8003DC4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003DC50: beq         $v0, $zero, L_8003DC64
    if (ctx->r2 == 0) {
        // 0x8003DC54: addiu       $t3, $zero, 0x3
        ctx->r11 = ADD32(0, 0X3);
            goto L_8003DC64;
    }
    // 0x8003DC54: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8003DC58: b           L_8003DC68
    // 0x8003DC5C: sw          $zero, 0x78($a0)
    MEM_W(0X78, ctx->r4) = 0;
        goto L_8003DC68;
    // 0x8003DC5C: sw          $zero, 0x78($a0)
    MEM_W(0X78, ctx->r4) = 0;
    // 0x8003DC60: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
L_8003DC64:
    // 0x8003DC64: sw          $t3, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r11;
L_8003DC68:
    // 0x8003DC68: lw          $t4, 0x78($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X78);
    // 0x8003DC6C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003DC70: bne         $t4, $at, L_8003DC90
    if (ctx->r12 != ctx->r1) {
        // 0x8003DC74: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8003DC90;
    }
    // 0x8003DC74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003DC78: lh          $t5, 0x6($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X6);
    // 0x8003DC7C: nop

    // 0x8003DC80: ori         $t6, $t5, 0x600
    ctx->r14 = ctx->r13 | 0X600;
    // 0x8003DC84: jal         0x8000FFB8
    // 0x8003DC88: sh          $t6, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r14;
    free_object(rdram, ctx);
        goto after_3;
    // 0x8003DC88: sh          $t6, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r14;
    after_3:
    // 0x8003DC8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003DC90:
    // 0x8003DC90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003DC94: jr          $ra
    // 0x8003DC98: nop

    return;
    // 0x8003DC98: nop

;}
RECOMP_FUNC void obj_init_silvercoin(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DC9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003DCA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003DCA4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003DCA8: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x8003DCAC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8003DCB0: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x8003DCB4: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x8003DCB8: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x8003DCBC: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
    // 0x8003DCC0: lw          $t0, 0x4C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4C);
    // 0x8003DCC4: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8003DCC8: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x8003DCCC: sw          $t1, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r9;
    // 0x8003DCD0: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
    // 0x8003DCD4: jal         0x8009C814
    // 0x8003DCD8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    is_in_tracks_mode(rdram, ctx);
        goto after_0;
    // 0x8003DCD8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003DCDC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003DCE0: bne         $v0, $zero, L_8003DD20
    if (ctx->r2 != 0) {
        // 0x8003DCE4: nop
    
            goto L_8003DD20;
    }
    // 0x8003DCE4: nop

    // 0x8003DCE8: jal         0x8000E1DC
    // 0x8003DCEC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    check_if_silver_coin_race(rdram, ctx);
        goto after_1;
    // 0x8003DCEC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x8003DCF0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003DCF4: beq         $v0, $zero, L_8003DD1C
    if (ctx->r2 == 0) {
        // 0x8003DCF8: addiu       $t2, $zero, 0x3
        ctx->r10 = ADD32(0, 0X3);
            goto L_8003DD1C;
    }
    // 0x8003DCF8: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x8003DCFC: jal         0x8009F1B4
    // 0x8003DD00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    is_in_adventure_two(rdram, ctx);
        goto after_2;
    // 0x8003DD00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x8003DD04: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003DD08: bne         $v0, $zero, L_8003DD1C
    if (ctx->r2 != 0) {
        // 0x8003DD0C: addiu       $t2, $zero, 0x3
        ctx->r10 = ADD32(0, 0X3);
            goto L_8003DD1C;
    }
    // 0x8003DD0C: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x8003DD10: b           L_8003DD20
    // 0x8003DD14: sw          $zero, 0x78($a0)
    MEM_W(0X78, ctx->r4) = 0;
        goto L_8003DD20;
    // 0x8003DD14: sw          $zero, 0x78($a0)
    MEM_W(0X78, ctx->r4) = 0;
    // 0x8003DD18: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
L_8003DD1C:
    // 0x8003DD1C: sw          $t2, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r10;
L_8003DD20:
    // 0x8003DD20: lw          $t3, 0x78($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X78);
    // 0x8003DD24: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003DD28: bne         $t3, $at, L_8003DD48
    if (ctx->r11 != ctx->r1) {
        // 0x8003DD2C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8003DD48;
    }
    // 0x8003DD2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003DD30: lh          $t4, 0x6($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X6);
    // 0x8003DD34: nop

    // 0x8003DD38: ori         $t5, $t4, 0x600
    ctx->r13 = ctx->r12 | 0X600;
    // 0x8003DD3C: jal         0x8000FFB8
    // 0x8003DD40: sh          $t5, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r13;
    free_object(rdram, ctx);
        goto after_3;
    // 0x8003DD40: sh          $t5, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r13;
    after_3:
    // 0x8003DD44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003DD48:
    // 0x8003DD48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003DD4C: jr          $ra
    // 0x8003DD50: nop

    return;
    // 0x8003DD50: nop

;}
RECOMP_FUNC void obj_loop_silvercoin(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DD54: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003DD58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003DD5C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8003DD60: jal         0x8006C3DC
    // 0x8003DD64: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    race_is_adventure_2P(rdram, ctx);
        goto after_0;
    // 0x8003DD64: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003DD68: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8003DD6C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x8003DD70: beq         $v0, $zero, L_8003DD88
    if (ctx->r2 == 0) {
        // 0x8003DD74: nop
    
            goto L_8003DD88;
    }
    // 0x8003DD74: nop

    // 0x8003DD78: lw          $a1, 0x78($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X78);
    // 0x8003DD7C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003DD80: bne         $a1, $at, L_8003DDA0
    if (ctx->r5 != ctx->r1) {
        // 0x8003DD84: nop
    
            goto L_8003DDA0;
    }
    // 0x8003DD84: nop

L_8003DD88:
    // 0x8003DD88: bne         $v0, $zero, L_8003DE80
    if (ctx->r2 != 0) {
        // 0x8003DD8C: nop
    
            goto L_8003DE80;
    }
    // 0x8003DD8C: nop

    // 0x8003DD90: lw          $a1, 0x78($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X78);
    // 0x8003DD94: nop

    // 0x8003DD98: bne         $a1, $zero, L_8003DE80
    if (ctx->r5 != 0) {
        // 0x8003DD9C: nop
    
            goto L_8003DE80;
    }
    // 0x8003DD9C: nop

L_8003DDA0:
    // 0x8003DDA0: lw          $v0, 0x4C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X4C);
    // 0x8003DDA4: nop

    // 0x8003DDA8: lbu         $t6, 0x13($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X13);
    // 0x8003DDAC: nop

    // 0x8003DDB0: slti        $at, $t6, 0x50
    ctx->r1 = SIGNED(ctx->r14) < 0X50 ? 1 : 0;
    // 0x8003DDB4: beq         $at, $zero, L_8003DE70
    if (ctx->r1 == 0) {
        // 0x8003DDB8: nop
    
            goto L_8003DE70;
    }
    // 0x8003DDB8: nop

    // 0x8003DDBC: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8003DDC0: nop

    // 0x8003DDC4: beq         $v1, $zero, L_8003DE70
    if (ctx->r3 == 0) {
        // 0x8003DDC8: nop
    
            goto L_8003DE70;
    }
    // 0x8003DDC8: nop

    // 0x8003DDCC: lw          $t7, 0x40($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X40);
    // 0x8003DDD0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003DDD4: lb          $t8, 0x54($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X54);
    // 0x8003DDD8: nop

    // 0x8003DDDC: bne         $t8, $at, L_8003DE70
    if (ctx->r24 != ctx->r1) {
        // 0x8003DDE0: nop
    
            goto L_8003DE70;
    }
    // 0x8003DDE0: nop

    // 0x8003DDE4: lw          $v0, 0x64($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X64);
    // 0x8003DDE8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003DDEC: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    // 0x8003DDF0: nop

    // 0x8003DDF4: beq         $a0, $at, L_8003DE70
    if (ctx->r4 == ctx->r1) {
        // 0x8003DDF8: nop
    
            goto L_8003DE70;
    }
    // 0x8003DDF8: nop

    // 0x8003DDFC: lb          $t9, 0x1D8($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X1D8);
    // 0x8003DE00: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8003DE04: bne         $t9, $zero, L_8003DE70
    if (ctx->r25 != 0) {
        // 0x8003DE08: sllv        $v1, $t0, $a0
        ctx->r3 = S32(ctx->r8 << (ctx->r4 & 31));
            goto L_8003DE70;
    }
    // 0x8003DE08: sllv        $v1, $t0, $a0
    ctx->r3 = S32(ctx->r8 << (ctx->r4 & 31));
    // 0x8003DE0C: and         $t1, $a1, $v1
    ctx->r9 = ctx->r5 & ctx->r3;
    // 0x8003DE10: bne         $t1, $zero, L_8003DE70
    if (ctx->r9 != 0) {
        // 0x8003DE14: or          $t2, $a1, $v1
        ctx->r10 = ctx->r5 | ctx->r3;
            goto L_8003DE70;
    }
    // 0x8003DE14: or          $t2, $a1, $v1
    ctx->r10 = ctx->r5 | ctx->r3;
    // 0x8003DE18: addiu       $t3, $zero, 0x10
    ctx->r11 = ADD32(0, 0X10);
    // 0x8003DE1C: sw          $t2, 0x78($a2)
    MEM_W(0X78, ctx->r6) = ctx->r10;
    // 0x8003DE20: sw          $t3, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->r11;
    // 0x8003DE24: lh          $t5, 0x0($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X0);
    // 0x8003DE28: lh          $t4, 0x6($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X6);
    // 0x8003DE2C: addiu       $t6, $zero, 0x200
    ctx->r14 = ADD32(0, 0X200);
    // 0x8003DE30: sllv        $t7, $t6, $t5
    ctx->r15 = S32(ctx->r14 << (ctx->r13 & 31));
    // 0x8003DE34: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x8003DE38: sh          $t8, 0x6($a2)
    MEM_H(0X6, ctx->r6) = ctx->r24;
    // 0x8003DE3C: lb          $a0, 0x202($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X202);
    // 0x8003DE40: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8003DE44: addiu       $a0, $a0, 0x2B
    ctx->r4 = ADD32(ctx->r4, 0X2B);
    // 0x8003DE48: andi        $t9, $a0, 0xFF
    ctx->r25 = ctx->r4 & 0XFF;
    // 0x8003DE4C: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x8003DE50: jal         0x80001BC0
    // 0x8003DE54: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    music_jingle_play(rdram, ctx);
        goto after_1;
    // 0x8003DE54: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // 0x8003DE58: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8003DE5C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8003DE60: lb          $t0, 0x202($v0)
    ctx->r8 = MEM_B(ctx->r2, 0X202);
    // 0x8003DE64: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x8003DE68: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8003DE6C: sb          $t1, 0x202($v0)
    MEM_B(0X202, ctx->r2) = ctx->r9;
L_8003DE70:
    // 0x8003DE70: lh          $t2, 0x18($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X18);
    // 0x8003DE74: sll         $t3, $a3, 3
    ctx->r11 = S32(ctx->r7 << 3);
    // 0x8003DE78: addu        $t6, $t2, $t3
    ctx->r14 = ADD32(ctx->r10, ctx->r11);
    // 0x8003DE7C: sh          $t6, 0x18($a2)
    MEM_H(0X18, ctx->r6) = ctx->r14;
L_8003DE80:
    // 0x8003DE80: lw          $v0, 0x7C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X7C);
    // 0x8003DE84: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8003DE88: blez        $v0, L_8003DEA4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8003DE8C: subu        $t5, $v0, $a3
        ctx->r13 = SUB32(ctx->r2, ctx->r7);
            goto L_8003DEA4;
    }
    // 0x8003DE8C: subu        $t5, $v0, $a3
    ctx->r13 = SUB32(ctx->r2, ctx->r7);
    // 0x8003DE90: sw          $t5, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->r13;
    // 0x8003DE94: sw          $t4, 0x74($a2)
    MEM_W(0X74, ctx->r6) = ctx->r12;
    // 0x8003DE98: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8003DE9C: jal         0x800B019C
    // 0x8003DEA0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_spawn_particle(rdram, ctx);
        goto after_2;
    // 0x8003DEA0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_2:
L_8003DEA4:
    // 0x8003DEA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003DEA8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003DEAC: jr          $ra
    // 0x8003DEB0: nop

    return;
    // 0x8003DEB0: nop

;}
RECOMP_FUNC void obj_init_worldkey(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DEB4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003DEB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003DEBC: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x8003DEC0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8003DEC4: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x8003DEC8: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x8003DECC: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x8003DED0: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
    // 0x8003DED4: lw          $t0, 0x4C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4C);
    // 0x8003DED8: nop

    // 0x8003DEDC: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x8003DEE0: lbu         $t1, 0x8($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X8);
    // 0x8003DEE4: nop

    // 0x8003DEE8: andi        $t2, $t1, 0xF
    ctx->r10 = ctx->r9 & 0XF;
    // 0x8003DEEC: sb          $t2, 0x8($a1)
    MEM_B(0X8, ctx->r5) = ctx->r10;
    // 0x8003DEF0: andi        $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 & 0XFF;
    // 0x8003DEF4: sw          $t3, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r11;
    // 0x8003DEF8: jal         0x8006ECD0
    // 0x8003DEFC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x8003DEFC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003DF00: jal         0x8009C814
    // 0x8003DF04: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    is_in_tracks_mode(rdram, ctx);
        goto after_1;
    // 0x8003DF04: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8003DF08: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8003DF0C: bne         $v0, $zero, L_8003DF30
    if (ctx->r2 != 0) {
        // 0x8003DF10: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8003DF30;
    }
    // 0x8003DF10: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8003DF14: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8003DF18: lw          $t6, 0x78($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X78);
    // 0x8003DF1C: lhu         $t5, 0x8($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X8);
    // 0x8003DF20: sllv        $t8, $t7, $t6
    ctx->r24 = S32(ctx->r15 << (ctx->r14 & 31));
    // 0x8003DF24: and         $t9, $t5, $t8
    ctx->r25 = ctx->r13 & ctx->r24;
    // 0x8003DF28: beq         $t9, $zero, L_8003DF3C
    if (ctx->r25 == 0) {
        // 0x8003DF2C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8003DF3C;
    }
    // 0x8003DF2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003DF30:
    // 0x8003DF30: jal         0x8000FFB8
    // 0x8003DF34: nop

    free_object(rdram, ctx);
        goto after_2;
    // 0x8003DF34: nop

    after_2:
    // 0x8003DF38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003DF3C:
    // 0x8003DF3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003DF40: jr          $ra
    // 0x8003DF44: nop

    return;
    // 0x8003DF44: nop

;}
RECOMP_FUNC void obj_loop_worldkey(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DF48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003DF4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003DF50: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003DF54: lw          $v1, 0x4C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4C);
    // 0x8003DF58: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8003DF5C: lbu         $t6, 0x13($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X13);
    // 0x8003DF60: nop

    // 0x8003DF64: slti        $at, $t6, 0x32
    ctx->r1 = SIGNED(ctx->r14) < 0X32 ? 1 : 0;
    // 0x8003DF68: beq         $at, $zero, L_8003DFEC
    if (ctx->r1 == 0) {
        // 0x8003DF6C: lw          $t6, 0x1C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X1C);
            goto L_8003DFEC;
    }
    // 0x8003DF6C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8003DF70: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8003DF74: nop

    // 0x8003DF78: beq         $v0, $zero, L_8003DFEC
    if (ctx->r2 == 0) {
        // 0x8003DF7C: lw          $t6, 0x1C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X1C);
            goto L_8003DFEC;
    }
    // 0x8003DF7C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8003DF80: lw          $t7, 0x40($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X40);
    // 0x8003DF84: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003DF88: lb          $t8, 0x54($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X54);
    // 0x8003DF8C: nop

    // 0x8003DF90: bne         $t8, $at, L_8003DFEC
    if (ctx->r24 != ctx->r1) {
        // 0x8003DF94: lw          $t6, 0x1C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X1C);
            goto L_8003DFEC;
    }
    // 0x8003DF94: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8003DF98: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x8003DF9C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003DFA0: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    // 0x8003DFA4: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    // 0x8003DFA8: beq         $t9, $at, L_8003DFEC
    if (ctx->r25 == ctx->r1) {
        // 0x8003DFAC: lw          $t6, 0x1C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X1C);
            goto L_8003DFEC;
    }
    // 0x8003DFAC: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8003DFB0: jal         0x80001BC0
    // 0x8003DFB4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    music_jingle_play(rdram, ctx);
        goto after_0;
    // 0x8003DFB4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8003DFB8: jal         0x8006ECD0
    // 0x8003DFBC: nop

    get_settings(rdram, ctx);
        goto after_1;
    // 0x8003DFBC: nop

    after_1:
    // 0x8003DFC0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003DFC4: lhu         $t0, 0x8($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X8);
    // 0x8003DFC8: lw          $t1, 0x78($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X78);
    // 0x8003DFCC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8003DFD0: sllv        $t3, $t2, $t1
    ctx->r11 = S32(ctx->r10 << (ctx->r9 & 31));
    // 0x8003DFD4: or          $t4, $t0, $t3
    ctx->r12 = ctx->r8 | ctx->r11;
    // 0x8003DFD8: jal         0x8000FFB8
    // 0x8003DFDC: sh          $t4, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r12;
    free_object(rdram, ctx);
        goto after_2;
    // 0x8003DFDC: sh          $t4, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r12;
    after_2:
    // 0x8003DFE0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8003DFE4: nop

    // 0x8003DFE8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
L_8003DFEC:
    // 0x8003DFEC: lh          $t5, 0x0($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X0);
    // 0x8003DFF0: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x8003DFF4: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x8003DFF8: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
    // 0x8003DFFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003E000: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003E004: jr          $ra
    // 0x8003E008: nop

    return;
    // 0x8003E008: nop

;}
RECOMP_FUNC void obj_init_weaponballoon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E00C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003E010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003E014: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x8003E018: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8003E01C: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x8003E020: lw          $t9, 0x4C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4C);
    // 0x8003E024: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8003E028: sb          $t8, 0x11($t9)
    MEM_B(0X11, ctx->r25) = ctx->r24;
    // 0x8003E02C: lw          $t1, 0x4C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4C);
    // 0x8003E030: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x8003E034: sb          $t0, 0x10($t1)
    MEM_B(0X10, ctx->r9) = ctx->r8;
    // 0x8003E038: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003E03C: jal         0x8009C850
    // 0x8003E040: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    get_filtered_cheats(rdram, ctx);
        goto after_0;
    // 0x8003E040: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003E044: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003E048: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8003E04C: sll         $t2, $v0, 14
    ctx->r10 = S32(ctx->r2 << 14);
    // 0x8003E050: bgez        $t2, L_8003E060
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8003E054: andi        $t3, $v0, 0x8000
        ctx->r11 = ctx->r2 & 0X8000;
            goto L_8003E060;
    }
    // 0x8003E054: andi        $t3, $v0, 0x8000
    ctx->r11 = ctx->r2 & 0X8000;
    // 0x8003E058: b           L_8003E0A8
    // 0x8003E05C: sb          $zero, 0x9($a1)
    MEM_B(0X9, ctx->r5) = 0;
        goto L_8003E0A8;
    // 0x8003E05C: sb          $zero, 0x9($a1)
    MEM_B(0X9, ctx->r5) = 0;
L_8003E060:
    // 0x8003E060: beq         $t3, $zero, L_8003E074
    if (ctx->r11 == 0) {
        // 0x8003E064: sll         $t5, $v0, 15
        ctx->r13 = S32(ctx->r2 << 15);
            goto L_8003E074;
    }
    // 0x8003E064: sll         $t5, $v0, 15
    ctx->r13 = S32(ctx->r2 << 15);
    // 0x8003E068: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8003E06C: b           L_8003E0A8
    // 0x8003E070: sb          $t4, 0x9($a1)
    MEM_B(0X9, ctx->r5) = ctx->r12;
        goto L_8003E0A8;
    // 0x8003E070: sb          $t4, 0x9($a1)
    MEM_B(0X9, ctx->r5) = ctx->r12;
L_8003E074:
    // 0x8003E074: bgez        $t5, L_8003E088
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8003E078: sll         $t7, $v0, 13
        ctx->r15 = S32(ctx->r2 << 13);
            goto L_8003E088;
    }
    // 0x8003E078: sll         $t7, $v0, 13
    ctx->r15 = S32(ctx->r2 << 13);
    // 0x8003E07C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8003E080: b           L_8003E0A8
    // 0x8003E084: sb          $t6, 0x9($a1)
    MEM_B(0X9, ctx->r5) = ctx->r14;
        goto L_8003E0A8;
    // 0x8003E084: sb          $t6, 0x9($a1)
    MEM_B(0X9, ctx->r5) = ctx->r14;
L_8003E088:
    // 0x8003E088: bgez        $t7, L_8003E09C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8003E08C: sll         $t9, $v0, 12
        ctx->r25 = S32(ctx->r2 << 12);
            goto L_8003E09C;
    }
    // 0x8003E08C: sll         $t9, $v0, 12
    ctx->r25 = S32(ctx->r2 << 12);
    // 0x8003E090: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8003E094: b           L_8003E0A8
    // 0x8003E098: sb          $t8, 0x9($a1)
    MEM_B(0X9, ctx->r5) = ctx->r24;
        goto L_8003E0A8;
    // 0x8003E098: sb          $t8, 0x9($a1)
    MEM_B(0X9, ctx->r5) = ctx->r24;
L_8003E09C:
    // 0x8003E09C: bgez        $t9, L_8003E0A8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8003E0A0: addiu       $t0, $zero, 0x4
        ctx->r8 = ADD32(0, 0X4);
            goto L_8003E0A8;
    }
    // 0x8003E0A0: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8003E0A4: sb          $t0, 0x9($a1)
    MEM_B(0X9, ctx->r5) = ctx->r8;
L_8003E0A8:
    // 0x8003E0A8: lbu         $t1, 0x8($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X8);
    // 0x8003E0AC: nop

    // 0x8003E0B0: slti        $at, $t1, 0x6
    ctx->r1 = SIGNED(ctx->r9) < 0X6 ? 1 : 0;
    // 0x8003E0B4: bne         $at, $zero, L_8003E0C0
    if (ctx->r1 != 0) {
        // 0x8003E0B8: nop
    
            goto L_8003E0C0;
    }
    // 0x8003E0B8: nop

    // 0x8003E0BC: sb          $zero, 0x8($a1)
    MEM_B(0X8, ctx->r5) = 0;
L_8003E0C0:
    // 0x8003E0C0: lw          $t3, 0x40($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X40);
    // 0x8003E0C4: lb          $t2, 0x3A($a0)
    ctx->r10 = MEM_B(ctx->r4, 0X3A);
    // 0x8003E0C8: lb          $t4, 0x55($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X55);
    // 0x8003E0CC: nop

    // 0x8003E0D0: slt         $at, $t2, $t4
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8003E0D4: bne         $at, $zero, L_8003E0E0
    if (ctx->r1 != 0) {
        // 0x8003E0D8: nop
    
            goto L_8003E0E0;
    }
    // 0x8003E0D8: nop

    // 0x8003E0DC: sb          $zero, 0x3A($a0)
    MEM_B(0X3A, ctx->r4) = 0;
L_8003E0E0:
    // 0x8003E0E0: lbu         $t5, 0x9($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X9);
    // 0x8003E0E4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8003E0E8: sb          $t5, 0x3A($a0)
    MEM_B(0X3A, ctx->r4) = ctx->r13;
    // 0x8003E0EC: lb          $t6, 0x3A($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X3A);
    // 0x8003E0F0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003E0F4: sw          $t6, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r14;
    // 0x8003E0F8: lbu         $t8, 0xA($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0XA);
    // 0x8003E0FC: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x8003E100: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8003E104: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003E108: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003E10C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8003E110: nop

    // 0x8003E114: bc1f        L_8003E124
    if (!c1cs) {
        // 0x8003E118: nop
    
            goto L_8003E124;
    }
    // 0x8003E118: nop

    // 0x8003E11C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8003E120: nop

L_8003E124:
    // 0x8003E124: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8003E128: lw          $t9, 0x40($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X40);
    // 0x8003E12C: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x8003E130: lwc1        $f8, 0xC($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0XC);
    // 0x8003E134: nop

    // 0x8003E138: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8003E13C: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
    // 0x8003E140: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8003E144: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x8003E148: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x8003E14C: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
    // 0x8003E150: jal         0x8009C850
    // 0x8003E154: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    get_filtered_cheats(rdram, ctx);
        goto after_1;
    // 0x8003E154: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x8003E158: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003E15C: andi        $t0, $v0, 0x800
    ctx->r8 = ctx->r2 & 0X800;
    // 0x8003E160: beq         $t0, $zero, L_8003E174
    if (ctx->r8 == 0) {
        // 0x8003E164: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8003E174;
    }
    // 0x8003E164: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003E168: jal         0x8000FFB8
    // 0x8003E16C: nop

    free_object(rdram, ctx);
        goto after_2;
    // 0x8003E16C: nop

    after_2:
    // 0x8003E170: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003E174:
    // 0x8003E174: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003E178: jr          $ra
    // 0x8003E17C: nop

    return;
    // 0x8003E17C: nop

;}
RECOMP_FUNC void obj_loop_weaponballoon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E180: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8003E184: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003E188: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8003E18C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8003E190: lw          $a2, 0x64($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X64);
    // 0x8003E194: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8003E198: lh          $t6, 0x4($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X4);
    // 0x8003E19C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003E1A0: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8003E1A4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8003E1A8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003E1AC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8003E1B0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8003E1B4: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8003E1B8: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8003E1BC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003E1C0: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8003E1C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003E1C8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8003E1CC: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8003E1D0: sub.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f18.d - ctx->f16.d;
    // 0x8003E1D4: mul.d       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f4.d);
    // 0x8003E1D8: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8003E1DC: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
    // 0x8003E1E0: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8003E1E4: lwc1        $f6, 0x673C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X673C);
    // 0x8003E1E8: lwc1        $f7, 0x6738($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6738);
    // 0x8003E1EC: cvt.d.s     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.d = CVT_D_S(ctx->f16.fl);
    // 0x8003E1F0: c.lt.d      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.d < ctx->f6.d;
    // 0x8003E1F4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003E1F8: bc1f        L_8003E218
    if (!c1cs) {
        // 0x8003E1FC: nop
    
            goto L_8003E218;
    }
    // 0x8003E1FC: nop

    // 0x8003E200: lwc1        $f8, 0x6740($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6740);
    // 0x8003E204: nop

    // 0x8003E208: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    // 0x8003E20C: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8003E210: nop

    // 0x8003E214: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
L_8003E218:
    // 0x8003E218: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003E21C: lwc1        $f11, 0x6748($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6748);
    // 0x8003E220: lwc1        $f10, 0x674C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X674C);
    // 0x8003E224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003E228: c.lt.d      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.d < ctx->f10.d;
    // 0x8003E22C: nop

    // 0x8003E230: bc1f        L_8003E24C
    if (!c1cs) {
        // 0x8003E234: nop
    
            goto L_8003E24C;
    }
    // 0x8003E234: nop

    // 0x8003E238: lh          $t7, 0x6($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X6);
    // 0x8003E23C: nop

    // 0x8003E240: ori         $t8, $t7, 0x4000
    ctx->r24 = ctx->r15 | 0X4000;
    // 0x8003E244: b           L_8003E25C
    // 0x8003E248: sh          $t8, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r24;
        goto L_8003E25C;
    // 0x8003E248: sh          $t8, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r24;
L_8003E24C:
    // 0x8003E24C: lh          $t9, 0x6($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X6);
    // 0x8003E250: nop

    // 0x8003E254: andi        $t0, $t9, 0xBFFF
    ctx->r8 = ctx->r25 & 0XBFFF;
    // 0x8003E258: sh          $t0, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r8;
L_8003E25C:
    // 0x8003E25C: lw          $t1, 0x7C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X7C);
    // 0x8003E260: nop

    // 0x8003E264: blez        $t1, L_8003E298
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8003E268: nop
    
            goto L_8003E298;
    }
    // 0x8003E268: nop

    // 0x8003E26C: sw          $t2, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r10;
    // 0x8003E270: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8003E274: jal         0x800B019C
    // 0x8003E278: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    obj_spawn_particle(rdram, ctx);
        goto after_0;
    // 0x8003E278: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    after_0:
    // 0x8003E27C: lw          $t3, 0x7C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X7C);
    // 0x8003E280: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x8003E284: nop

    // 0x8003E288: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x8003E28C: sw          $t5, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r13;
    // 0x8003E290: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8003E294: nop

L_8003E298:
    // 0x8003E298: lh          $v0, 0x4($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X4);
    // 0x8003E29C: addiu       $at, $zero, 0x5A
    ctx->r1 = ADD32(0, 0X5A);
    // 0x8003E2A0: beq         $v0, $zero, L_8003E2F8
    if (ctx->r2 == 0) {
        // 0x8003E2A4: nop
    
            goto L_8003E2F8;
    }
    // 0x8003E2A4: nop

    // 0x8003E2A8: bne         $v0, $at, L_8003E2D0
    if (ctx->r2 != ctx->r1) {
        // 0x8003E2AC: lw          $t8, 0x44($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X44);
            goto L_8003E2D0;
    }
    // 0x8003E2AC: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x8003E2B0: lw          $t6, 0x4C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4C);
    // 0x8003E2B4: nop

    // 0x8003E2B8: lbu         $t7, 0x13($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X13);
    // 0x8003E2BC: nop

    // 0x8003E2C0: slti        $at, $t7, 0x2D
    ctx->r1 = SIGNED(ctx->r15) < 0X2D ? 1 : 0;
    // 0x8003E2C4: bne         $at, $zero, L_8003E2E8
    if (ctx->r1 != 0) {
        // 0x8003E2C8: nop
    
            goto L_8003E2E8;
    }
    // 0x8003E2C8: nop

    // 0x8003E2CC: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
L_8003E2D0:
    // 0x8003E2D0: nop

    // 0x8003E2D4: subu        $t9, $v0, $t8
    ctx->r25 = SUB32(ctx->r2, ctx->r24);
    // 0x8003E2D8: subu        $t0, $t9, $t8
    ctx->r8 = SUB32(ctx->r25, ctx->r24);
    // 0x8003E2DC: sh          $t0, 0x4($a2)
    MEM_H(0X4, ctx->r6) = ctx->r8;
    // 0x8003E2E0: lh          $v0, 0x4($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X4);
    // 0x8003E2E4: nop

L_8003E2E8:
    // 0x8003E2E8: bgez        $v0, L_8003E5E4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8003E2EC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8003E5E4;
    }
    // 0x8003E2EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003E2F0: b           L_8003E5E0
    // 0x8003E2F4: sh          $zero, 0x4($a2)
    MEM_H(0X4, ctx->r6) = 0;
        goto L_8003E5E0;
    // 0x8003E2F4: sh          $zero, 0x4($a2)
    MEM_H(0X4, ctx->r6) = 0;
L_8003E2F8:
    // 0x8003E2F8: lw          $v1, 0x4C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4C);
    // 0x8003E2FC: nop

    // 0x8003E300: lbu         $t1, 0x13($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X13);
    // 0x8003E304: nop

    // 0x8003E308: slti        $at, $t1, 0x2D
    ctx->r1 = SIGNED(ctx->r9) < 0X2D ? 1 : 0;
    // 0x8003E30C: beq         $at, $zero, L_8003E5E4
    if (ctx->r1 == 0) {
        // 0x8003E310: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8003E5E4;
    }
    // 0x8003E310: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003E314: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8003E318: nop

    // 0x8003E31C: beq         $v0, $zero, L_8003E5E4
    if (ctx->r2 == 0) {
        // 0x8003E320: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8003E5E4;
    }
    // 0x8003E320: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003E324: lw          $t2, 0x40($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X40);
    // 0x8003E328: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8003E32C: lb          $t3, 0x54($t2)
    ctx->r11 = MEM_B(ctx->r10, 0X54);
    // 0x8003E330: nop

    // 0x8003E334: bne         $a0, $t3, L_8003E5E4
    if (ctx->r4 != ctx->r11) {
        // 0x8003E338: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8003E5E4;
    }
    // 0x8003E338: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003E33C: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x8003E340: nop

    // 0x8003E344: lb          $t4, 0x1D6($v1)
    ctx->r12 = MEM_B(ctx->r3, 0X1D6);
    // 0x8003E348: nop

    // 0x8003E34C: slti        $at, $t4, 0x5
    ctx->r1 = SIGNED(ctx->r12) < 0X5 ? 1 : 0;
    // 0x8003E350: bne         $at, $zero, L_8003E368
    if (ctx->r1 != 0) {
        // 0x8003E354: nop
    
            goto L_8003E368;
    }
    // 0x8003E354: nop

    // 0x8003E358: lh          $t5, 0x0($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X0);
    // 0x8003E35C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003E360: beq         $t5, $at, L_8003E5E4
    if (ctx->r13 == ctx->r1) {
        // 0x8003E364: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8003E5E4;
    }
    // 0x8003E364: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8003E368:
    // 0x8003E368: lw          $t6, 0x78($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X78);
    // 0x8003E36C: lb          $v0, 0x172($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X172);
    // 0x8003E370: sb          $t6, 0x172($v1)
    MEM_B(0X172, ctx->r3) = ctx->r14;
    // 0x8003E374: lb          $t7, 0x172($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X172);
    // 0x8003E378: nop

    // 0x8003E37C: bne         $v0, $t7, L_8003E3A8
    if (ctx->r2 != ctx->r15) {
        // 0x8003E380: nop
    
            goto L_8003E3A8;
    }
    // 0x8003E380: nop

    // 0x8003E384: lb          $t9, 0x173($v1)
    ctx->r25 = MEM_B(ctx->r3, 0X173);
    // 0x8003E388: nop

    // 0x8003E38C: beq         $t9, $zero, L_8003E3A8
    if (ctx->r25 == 0) {
        // 0x8003E390: nop
    
            goto L_8003E3A8;
    }
    // 0x8003E390: nop

    // 0x8003E394: lb          $t8, 0x174($v1)
    ctx->r24 = MEM_B(ctx->r3, 0X174);
    // 0x8003E398: nop

    // 0x8003E39C: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x8003E3A0: b           L_8003E3AC
    // 0x8003E3A4: sb          $t0, 0x174($v1)
    MEM_B(0X174, ctx->r3) = ctx->r8;
        goto L_8003E3AC;
    // 0x8003E3A4: sb          $t0, 0x174($v1)
    MEM_B(0X174, ctx->r3) = ctx->r8;
L_8003E3A8:
    // 0x8003E3A8: sb          $zero, 0x174($v1)
    MEM_B(0X174, ctx->r3) = 0;
L_8003E3AC:
    // 0x8003E3AC: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    // 0x8003E3B0: jal         0x8006BFD8
    // 0x8003E3B4: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    level_type(rdram, ctx);
        goto after_1;
    // 0x8003E3B4: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    after_1:
    // 0x8003E3B8: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x8003E3BC: andi        $t1, $v0, 0x40
    ctx->r9 = ctx->r2 & 0X40;
    // 0x8003E3C0: beq         $t1, $zero, L_8003E3F4
    if (ctx->r9 == 0) {
        // 0x8003E3C4: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8003E3F4;
    }
    // 0x8003E3C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8003E3C8: lb          $t2, 0x174($v1)
    ctx->r10 = MEM_B(ctx->r3, 0X174);
    // 0x8003E3CC: nop

    // 0x8003E3D0: slti        $at, $t2, 0x2
    ctx->r1 = SIGNED(ctx->r10) < 0X2 ? 1 : 0;
    // 0x8003E3D4: bne         $at, $zero, L_8003E3E0
    if (ctx->r1 != 0) {
        // 0x8003E3D8: nop
    
            goto L_8003E3E0;
    }
    // 0x8003E3D8: nop

    // 0x8003E3DC: sb          $a0, 0x174($v1)
    MEM_B(0X174, ctx->r3) = ctx->r4;
L_8003E3E0:
    // 0x8003E3E0: lb          $t3, 0x172($v1)
    ctx->r11 = MEM_B(ctx->r3, 0X172);
    // 0x8003E3E4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003E3E8: bne         $t3, $at, L_8003E3F8
    if (ctx->r11 != ctx->r1) {
        // 0x8003E3EC: addiu       $t4, $zero, 0x3
        ctx->r12 = ADD32(0, 0X3);
            goto L_8003E3F8;
    }
    // 0x8003E3EC: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8003E3F0: sb          $a0, 0x174($v1)
    MEM_B(0X174, ctx->r3) = ctx->r4;
L_8003E3F4:
    // 0x8003E3F4: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
L_8003E3F8:
    // 0x8003E3F8: sb          $t4, 0x2D($sp)
    MEM_B(0X2D, ctx->r29) = ctx->r12;
    // 0x8003E3FC: jal         0x8009C850
    // 0x8003E400: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    get_filtered_cheats(rdram, ctx);
        goto after_2;
    // 0x8003E400: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    after_2:
    // 0x8003E404: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x8003E408: sll         $t5, $v0, 11
    ctx->r13 = S32(ctx->r2 << 11);
    // 0x8003E40C: bgez        $t5, L_8003E418
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8003E410: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_8003E418;
    }
    // 0x8003E410: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8003E414: sb          $a0, 0x174($v1)
    MEM_B(0X174, ctx->r3) = ctx->r4;
L_8003E418:
    // 0x8003E418: lb          $t6, 0x174($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X174);
    // 0x8003E41C: nop

    // 0x8003E420: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x8003E424: bne         $at, $zero, L_8003E434
    if (ctx->r1 != 0) {
        // 0x8003E428: nop
    
            goto L_8003E434;
    }
    // 0x8003E428: nop

    // 0x8003E42C: sb          $a0, 0x174($v1)
    MEM_B(0X174, ctx->r3) = ctx->r4;
    // 0x8003E430: sb          $a0, 0x2D($sp)
    MEM_B(0X2D, ctx->r29) = ctx->r4;
L_8003E434:
    // 0x8003E434: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x8003E438: jal         0x8001E2D0
    // 0x8003E43C: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    get_misc_asset(rdram, ctx);
        goto after_3;
    // 0x8003E43C: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    after_3:
    // 0x8003E440: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x8003E444: nop

    // 0x8003E448: lb          $t7, 0x172($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X172);
    // 0x8003E44C: lb          $t8, 0x174($v1)
    ctx->r24 = MEM_B(ctx->r3, 0X174);
    // 0x8003E450: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8003E454: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x8003E458: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8003E45C: sll         $t0, $t8, 1
    ctx->r8 = S32(ctx->r24 << 1);
    // 0x8003E460: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8003E464: lbu         $t4, 0x209($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X209);
    // 0x8003E468: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x8003E46C: lb          $t3, 0x1($t2)
    ctx->r11 = MEM_B(ctx->r10, 0X1);
    // 0x8003E470: lb          $a2, 0x173($v1)
    ctx->r6 = MEM_B(ctx->r3, 0X173);
    // 0x8003E474: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x8003E478: sb          $t5, 0x209($v1)
    MEM_B(0X209, ctx->r3) = ctx->r13;
    // 0x8003E47C: sb          $t3, 0x173($v1)
    MEM_B(0X173, ctx->r3) = ctx->r11;
    // 0x8003E480: jal         0x8009C90C
    // 0x8003E484: sb          $a2, 0x2E($sp)
    MEM_B(0X2E, ctx->r29) = ctx->r6;
    get_number_of_active_players(rdram, ctx);
        goto after_4;
    // 0x8003E484: sb          $a2, 0x2E($sp)
    MEM_B(0X2E, ctx->r29) = ctx->r6;
    after_4:
    // 0x8003E488: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x8003E48C: lb          $a2, 0x2E($sp)
    ctx->r6 = MEM_B(ctx->r29, 0X2E);
    // 0x8003E490: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8003E494: beq         $at, $zero, L_8003E4A0
    if (ctx->r1 == 0) {
        // 0x8003E498: addiu       $t6, $zero, 0x10
        ctx->r14 = ADD32(0, 0X10);
            goto L_8003E4A0;
    }
    // 0x8003E498: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x8003E49C: sw          $t6, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r14;
L_8003E4A0:
    // 0x8003E4A0: lh          $a3, 0x0($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X0);
    // 0x8003E4A4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003E4A8: bne         $a3, $at, L_8003E4D4
    if (ctx->r7 != ctx->r1) {
        // 0x8003E4AC: addiu       $a0, $zero, 0xE
        ctx->r4 = ADD32(0, 0XE);
            goto L_8003E4D4;
    }
    // 0x8003E4AC: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x8003E4B0: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8003E4B4: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x8003E4B8: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x8003E4BC: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8003E4C0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8003E4C4: jal         0x80009558
    // 0x8003E4C8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_5;
    // 0x8003E4C8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_5:
    // 0x8003E4CC: b           L_8003E5C4
    // 0x8003E4D0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
        goto L_8003E5C4;
    // 0x8003E4D0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
L_8003E4D4:
    // 0x8003E4D4: lb          $v0, 0x174($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X174);
    // 0x8003E4D8: lb          $t8, 0x2D($sp)
    ctx->r24 = MEM_B(ctx->r29, 0X2D);
    // 0x8003E4DC: nop

    // 0x8003E4E0: bne         $t8, $v0, L_8003E574
    if (ctx->r24 != ctx->r2) {
        // 0x8003E4E4: nop
    
            goto L_8003E574;
    }
    // 0x8003E4E4: nop

    // 0x8003E4E8: lb          $t9, 0x1D8($v1)
    ctx->r25 = MEM_B(ctx->r3, 0X1D8);
    // 0x8003E4EC: nop

    // 0x8003E4F0: bne         $t9, $zero, L_8003E5C4
    if (ctx->r25 != 0) {
        // 0x8003E4F4: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_8003E5C4;
    }
    // 0x8003E4F4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8003E4F8: lb          $t0, 0x173($v1)
    ctx->r8 = MEM_B(ctx->r3, 0X173);
    // 0x8003E4FC: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x8003E500: beq         $a2, $t0, L_8003E554
    if (ctx->r6 == ctx->r8) {
        // 0x8003E504: addiu       $t2, $zero, 0x4
        ctx->r10 = ADD32(0, 0X4);
            goto L_8003E554;
    }
    // 0x8003E504: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x8003E508: addiu       $a0, $zero, 0x13E
    ctx->r4 = ADD32(0, 0X13E);
    // 0x8003E50C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8003E510: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x8003E514: jal         0x800A79E0
    // 0x8003E518: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    hud_sound_play_delayed(rdram, ctx);
        goto after_6;
    // 0x8003E518: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    after_6:
    // 0x8003E51C: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x8003E520: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003E524: lb          $a2, 0x174($v1)
    ctx->r6 = MEM_B(ctx->r3, 0X174);
    // 0x8003E528: nop

    // 0x8003E52C: slti        $at, $a2, 0x3
    ctx->r1 = SIGNED(ctx->r6) < 0X3 ? 1 : 0;
    // 0x8003E530: bne         $at, $zero, L_8003E540
    if (ctx->r1 != 0) {
        // 0x8003E534: addiu       $a0, $a2, 0xA0
        ctx->r4 = ADD32(ctx->r6, 0XA0);
            goto L_8003E540;
    }
    // 0x8003E534: addiu       $a0, $a2, 0xA0
    ctx->r4 = ADD32(ctx->r6, 0XA0);
    // 0x8003E538: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8003E53C: addiu       $a0, $a2, 0xA0
    ctx->r4 = ADD32(ctx->r6, 0XA0);
L_8003E540:
    // 0x8003E540: andi        $t1, $a0, 0xFFFF
    ctx->r9 = ctx->r4 & 0XFFFF;
    // 0x8003E544: jal         0x80001D04
    // 0x8003E548: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    sound_play(rdram, ctx);
        goto after_7;
    // 0x8003E548: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_7:
    // 0x8003E54C: b           L_8003E5C4
    // 0x8003E550: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
        goto L_8003E5C4;
    // 0x8003E550: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
L_8003E554:
    // 0x8003E554: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8003E558: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x8003E55C: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x8003E560: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8003E564: jal         0x80009558
    // 0x8003E568: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_8;
    // 0x8003E568: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_8:
    // 0x8003E56C: b           L_8003E5C4
    // 0x8003E570: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
        goto L_8003E5C4;
    // 0x8003E570: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
L_8003E574:
    // 0x8003E574: lb          $t3, 0x1D8($v1)
    ctx->r11 = MEM_B(ctx->r3, 0X1D8);
    // 0x8003E578: nop

    // 0x8003E57C: bne         $t3, $zero, L_8003E5C4
    if (ctx->r11 != 0) {
        // 0x8003E580: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_8003E5C4;
    }
    // 0x8003E580: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8003E584: blez        $v0, L_8003E5AC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8003E588: addiu       $a0, $zero, 0x13E
        ctx->r4 = ADD32(0, 0X13E);
            goto L_8003E5AC;
    }
    // 0x8003E588: addiu       $a0, $zero, 0x13E
    ctx->r4 = ADD32(0, 0X13E);
    // 0x8003E58C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8003E590: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x8003E594: jal         0x800A79E0
    // 0x8003E598: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    hud_sound_play_delayed(rdram, ctx);
        goto after_9;
    // 0x8003E598: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    after_9:
    // 0x8003E59C: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x8003E5A0: nop

    // 0x8003E5A4: lb          $v0, 0x174($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X174);
    // 0x8003E5A8: nop

L_8003E5AC:
    // 0x8003E5AC: addiu       $a0, $v0, 0xA0
    ctx->r4 = ADD32(ctx->r2, 0XA0);
    // 0x8003E5B0: andi        $t4, $a0, 0xFFFF
    ctx->r12 = ctx->r4 & 0XFFFF;
    // 0x8003E5B4: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8003E5B8: jal         0x80001D04
    // 0x8003E5BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_10;
    // 0x8003E5BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x8003E5C0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
L_8003E5C4:
    // 0x8003E5C4: sw          $t5, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r13;
    // 0x8003E5C8: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8003E5CC: jal         0x800B019C
    // 0x8003E5D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    obj_spawn_particle(rdram, ctx);
        goto after_11;
    // 0x8003E5D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8003E5D4: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8003E5D8: addiu       $t6, $zero, 0x5A
    ctx->r14 = ADD32(0, 0X5A);
    // 0x8003E5DC: sh          $t6, 0x4($t7)
    MEM_H(0X4, ctx->r15) = ctx->r14;
L_8003E5E0:
    // 0x8003E5E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8003E5E4:
    // 0x8003E5E4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8003E5E8: jr          $ra
    // 0x8003E5EC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8003E5EC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void obj_init_wballoonpop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E5F0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8003E5F4: jr          $ra
    // 0x8003E5F8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8003E5F8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void obj_loop_wballoonpop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E5FC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8003E600: jr          $ra
    // 0x8003E604: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8003E604: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void obj_init_weapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E608: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003E60C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003E610: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003E614: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003E618: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x8003E61C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8003E620: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x8003E624: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x8003E628: addiu       $t9, $zero, 0x18
    ctx->r25 = ADD32(0, 0X18);
    // 0x8003E62C: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
    // 0x8003E630: lw          $t0, 0x4C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4C);
    // 0x8003E634: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8003E638: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x8003E63C: lw          $t1, 0x4C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4C);
    // 0x8003E640: addiu       $a0, $zero, 0x1E0
    ctx->r4 = ADD32(0, 0X1E0);
    // 0x8003E644: sb          $zero, 0x12($t1)
    MEM_B(0X12, ctx->r9) = 0;
    // 0x8003E648: jal         0x8000C8B4
    // 0x8003E64C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    normalise_time(rdram, ctx);
        goto after_0;
    // 0x8003E64C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8003E650: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8003E654: nop

    // 0x8003E658: sw          $v0, 0x78($a1)
    MEM_W(0X78, ctx->r5) = ctx->r2;
    // 0x8003E65C: sw          $zero, 0x7C($a1)
    MEM_W(0X7C, ctx->r5) = 0;
    // 0x8003E660: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003E664: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003E668: jr          $ra
    // 0x8003E66C: nop

    return;
    // 0x8003E66C: nop

;}
RECOMP_FUNC void obj_loop_weapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E670: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003E674: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003E678: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x8003E67C: nop

    // 0x8003E680: lbu         $t6, 0x18($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X18);
    // 0x8003E684: nop

    // 0x8003E688: sltiu       $at, $t6, 0xC
    ctx->r1 = ctx->r14 < 0XC ? 1 : 0;
    // 0x8003E68C: beq         $at, $zero, L_8003E6C4
    if (ctx->r1 == 0) {
        // 0x8003E690: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8003E6C4;
    }
    // 0x8003E690: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8003E694: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003E698: addu        $at, $at, $t6
    gpr jr_addend_8003E6A4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8003E69C: lw          $t6, 0x6750($at)
    ctx->r14 = ADD32(ctx->r1, 0X6750);
    // 0x8003E6A0: nop

    // 0x8003E6A4: jr          $t6
    // 0x8003E6A8: nop

    switch (jr_addend_8003E6A4 >> 2) {
        case 0: goto L_8003E6AC; break;
        case 1: goto L_8003E6AC; break;
        case 2: goto L_8003E6BC; break;
        case 3: goto L_8003E6BC; break;
        case 4: goto L_8003E6C4; break;
        case 5: goto L_8003E6C4; break;
        case 6: goto L_8003E6C4; break;
        case 7: goto L_8003E6C4; break;
        case 8: goto L_8003E6C4; break;
        case 9: goto L_8003E6C4; break;
        case 10: goto L_8003E6BC; break;
        case 11: goto L_8003E6BC; break;
        default: switch_error(__func__, 0x8003E6A4, 0x800E6750);
    }
    // 0x8003E6A8: nop

L_8003E6AC:
    // 0x8003E6AC: jal         0x8003E6D4
    // 0x8003E6B0: nop

    weapon_projectile(rdram, ctx);
        goto after_0;
    // 0x8003E6B0: nop

    after_0:
    // 0x8003E6B4: b           L_8003E6C8
    // 0x8003E6B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8003E6C8;
    // 0x8003E6B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003E6BC:
    // 0x8003E6BC: jal         0x8003F328
    // 0x8003E6C0: nop

    weapon_trap(rdram, ctx);
        goto after_1;
    // 0x8003E6C0: nop

    after_1:
L_8003E6C4:
    // 0x8003E6C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003E6C8:
    // 0x8003E6C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003E6CC: jr          $ra
    // 0x8003E6D0: nop

    return;
    // 0x8003E6D0: nop

;}
RECOMP_FUNC void weapon_projectile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E6D4: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x8003E6D8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8003E6DC: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8003E6E0: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8003E6E4: sw          $a1, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r5;
    // 0x8003E6E8: lw          $v1, 0x4C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4C);
    // 0x8003E6EC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003E6F0: lh          $t6, 0x14($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X14);
    // 0x8003E6F4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003E6F8: ori         $t7, $t6, 0x100
    ctx->r15 = ctx->r14 | 0X100;
    // 0x8003E6FC: sh          $t7, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r15;
    // 0x8003E700: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8003E704: lw          $s1, 0x64($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X64);
    // 0x8003E708: swc1        $f4, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f4.u32l;
    // 0x8003E70C: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8003E710: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003E714: swc1        $f6, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f6.u32l;
    // 0x8003E718: lwc1        $f8, 0x14($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8003E71C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003E720: swc1        $f8, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f8.u32l;
    // 0x8003E724: lh          $t8, 0x0($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X0);
    // 0x8003E728: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x8003E72C: sh          $t8, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r24;
    // 0x8003E730: lh          $t9, 0x2($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X2);
    // 0x8003E734: sh          $zero, 0x40($sp)
    MEM_H(0X40, ctx->r29) = 0;
    // 0x8003E738: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x8003E73C: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x8003E740: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x8003E744: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x8003E748: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    // 0x8003E74C: jal         0x8006FE70
    // 0x8003E750: sh          $t9, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r25;
    mtxf_from_transform(rdram, ctx);
        goto after_0;
    // 0x8003E750: sh          $t9, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r25;
    after_0:
    // 0x8003E754: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003E758: lw          $a3, 0x10($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X10);
    // 0x8003E75C: addiu       $t0, $s0, 0x1C
    ctx->r8 = ADD32(ctx->r16, 0X1C);
    // 0x8003E760: addiu       $t1, $s0, 0x20
    ctx->r9 = ADD32(ctx->r16, 0X20);
    // 0x8003E764: addiu       $t2, $s0, 0x24
    ctx->r10 = ADD32(ctx->r16, 0X24);
    // 0x8003E768: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8003E76C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003E770: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8003E774: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8003E778: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8003E77C: jal         0x8006F88C
    // 0x8003E780: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    mtxf_transform_point(rdram, ctx);
        goto after_1;
    // 0x8003E780: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    after_1:
    // 0x8003E784: lw          $t3, 0xEC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XEC);
    // 0x8003E788: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x8003E78C: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x8003E790: lw          $t4, 0x300($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X300);
    // 0x8003E794: cvt.s.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003E798: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003E79C: bne         $t4, $zero, L_8003E7B8
    if (ctx->r12 != 0) {
        // 0x8003E7A0: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_8003E7B8;
    }
    // 0x8003E7A0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8003E7A4: lwc1        $f5, 0x6780($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6780);
    // 0x8003E7A8: lwc1        $f4, 0x6784($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6784);
    // 0x8003E7AC: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x8003E7B0: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x8003E7B4: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
L_8003E7B8:
    // 0x8003E7B8: lwc1        $f10, 0x1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8003E7BC: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003E7C0: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8003E7C4: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8003E7C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8003E7CC: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    // 0x8003E7D0: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8003E7D4: addiu       $a2, $sp, 0xC8
    ctx->r6 = ADD32(ctx->r29, 0XC8);
    // 0x8003E7D8: swc1        $f18, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f18.u32l;
    // 0x8003E7DC: lwc1        $f6, 0x20($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8003E7E0: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003E7E4: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8003E7E8: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x8003E7EC: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8003E7F0: swc1        $f8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f8.u32l;
    // 0x8003E7F4: lwc1        $f18, 0x24($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8003E7F8: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003E7FC: mul.s       $f6, $f18, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8003E800: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8003E804: swc1        $f4, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f4.u32l;
    // 0x8003E808: lbu         $t5, 0x18($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X18);
    // 0x8003E80C: nop

    // 0x8003E810: beq         $t5, $at, L_8003E88C
    if (ctx->r13 == ctx->r1) {
        // 0x8003E814: lui         $at, 0x4180
        ctx->r1 = S32(0X4180 << 16);
            goto L_8003E88C;
    }
    // 0x8003E814: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8003E818: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003E81C: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    // 0x8003E820: swc1        $f2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f2.u32l;
    // 0x8003E824: jal         0x80031170
    // 0x8003E828: swc1        $f10, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f10.u32l;
    generate_collision_candidates(rdram, ctx);
        goto after_2;
    // 0x8003E828: swc1        $f10, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x8003E82C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8003E830: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8003E834: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8003E838: addiu       $t8, $sp, 0xA4
    ctx->r24 = ADD32(ctx->r29, 0XA4);
    // 0x8003E83C: sw          $zero, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = 0;
    // 0x8003E840: sb          $t6, 0x97($sp)
    MEM_B(0X97, ctx->r29) = ctx->r14;
    // 0x8003E844: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8003E848: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8003E84C: addiu       $a1, $sp, 0xC8
    ctx->r5 = ADD32(ctx->r29, 0XC8);
    // 0x8003E850: addiu       $a2, $sp, 0xC4
    ctx->r6 = ADD32(ctx->r29, 0XC4);
    // 0x8003E854: jal         0x80031640
    // 0x8003E858: addiu       $a3, $sp, 0x97
    ctx->r7 = ADD32(ctx->r29, 0X97);
    resolve_collisions(rdram, ctx);
        goto after_3;
    // 0x8003E858: addiu       $a3, $sp, 0x97
    ctx->r7 = ADD32(ctx->r29, 0X97);
    after_3:
    // 0x8003E85C: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
    // 0x8003E860: lwc1        $f2, 0xC0($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x8003E864: blez        $t9, L_8003E88C
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8003E868: addiu       $a0, $sp, 0xB0
        ctx->r4 = ADD32(ctx->r29, 0XB0);
            goto L_8003E88C;
    }
    // 0x8003E868: addiu       $a0, $sp, 0xB0
    ctx->r4 = ADD32(ctx->r29, 0XB0);
    // 0x8003E86C: addiu       $a1, $sp, 0xAC
    ctx->r5 = ADD32(ctx->r29, 0XAC);
    // 0x8003E870: addiu       $a2, $sp, 0xA8
    ctx->r6 = ADD32(ctx->r29, 0XA8);
    // 0x8003E874: jal         0x8002AD14
    // 0x8003E878: swc1        $f2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f2.u32l;
    get_collision_normal(rdram, ctx);
        goto after_4;
    // 0x8003E878: swc1        $f2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f2.u32l;
    after_4:
    // 0x8003E87C: lwc1        $f2, 0xC0($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x8003E880: beq         $v0, $zero, L_8003E88C
    if (ctx->r2 == 0) {
        // 0x8003E884: nop
    
            goto L_8003E88C;
    }
    // 0x8003E884: nop

    // 0x8003E888: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
L_8003E88C:
    // 0x8003E88C: lwc1        $f8, 0xC8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x8003E890: lwc1        $f18, 0xBC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x8003E894: lwc1        $f16, 0xCC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x8003E898: lwc1        $f6, 0xB8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x8003E89C: lwc1        $f4, 0xD0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x8003E8A0: lwc1        $f10, 0xB4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x8003E8A4: sub.s       $f0, $f8, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x8003E8A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003E8AC: sub.s       $f12, $f16, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x8003E8B0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8003E8B4: sub.s       $f14, $f4, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8003E8B8: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8003E8BC: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x8003E8C0: swc1        $f14, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f14.u32l;
    // 0x8003E8C4: swc1        $f12, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f12.u32l;
    // 0x8003E8C8: swc1        $f0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f0.u32l;
    // 0x8003E8CC: jal         0x80011570
    // 0x8003E8D0: swc1        $f2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f2.u32l;
    move_object(rdram, ctx);
        goto after_5;
    // 0x8003E8D0: swc1        $f2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f2.u32l;
    after_5:
    // 0x8003E8D4: lwc1        $f2, 0xC0($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x8003E8D8: beq         $v0, $zero, L_8003E8E4
    if (ctx->r2 == 0) {
        // 0x8003E8DC: nop
    
            goto L_8003E8E4;
    }
    // 0x8003E8DC: nop

    // 0x8003E8E0: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
L_8003E8E4:
    // 0x8003E8E4: lwc1        $f8, 0xB0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x8003E8E8: lwc1        $f16, 0xA8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x8003E8EC: mul.s       $f18, $f8, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8003E8F0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003E8F4: mul.s       $f6, $f16, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8003E8F8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003E8FC: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8003E900: nop

    // 0x8003E904: div.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8003E908: swc1        $f10, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f10.u32l;
    // 0x8003E90C: lwc1        $f0, 0x10($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8003E910: lwc1        $f6, 0xB0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x8003E914: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8003E918: nop

    // 0x8003E91C: div.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8003E920: c.lt.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl < ctx->f18.fl;
    // 0x8003E924: swc1        $f18, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f18.u32l;
    // 0x8003E928: bc1f        L_8003E934
    if (!c1cs) {
        // 0x8003E92C: nop
    
            goto L_8003E934;
    }
    // 0x8003E92C: nop

    // 0x8003E930: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
L_8003E934:
    // 0x8003E934: lbu         $v0, 0x18($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X18);
    // 0x8003E938: nop

    // 0x8003E93C: bne         $v0, $zero, L_8003E9CC
    if (ctx->r2 != 0) {
        // 0x8003E940: nop
    
            goto L_8003E9CC;
    }
    // 0x8003E940: nop

    // 0x8003E944: jal         0x8001BA98
    // 0x8003E948: nop

    get_checkpoint_count(rdram, ctx);
        goto after_6;
    // 0x8003E948: nop

    after_6:
    // 0x8003E94C: blez        $v0, L_8003E9C4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8003E950: addiu       $t5, $zero, -0x1
        ctx->r13 = ADD32(0, -0X1);
            goto L_8003E9C4;
    }
    // 0x8003E950: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x8003E954: lb          $a0, 0x19($s1)
    ctx->r4 = MEM_B(ctx->r17, 0X19);
    // 0x8003E958: lwc1        $f4, 0xB4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x8003E95C: lw          $a2, 0xBC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XBC);
    // 0x8003E960: lw          $a3, 0xB8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB8);
    // 0x8003E964: addiu       $t0, $s1, 0xC
    ctx->r8 = ADD32(ctx->r17, 0XC);
    // 0x8003E968: addiu       $t1, $sp, 0x97
    ctx->r9 = ADD32(ctx->r29, 0X97);
    // 0x8003E96C: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8003E970: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8003E974: sw          $v0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r2;
    // 0x8003E978: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8003E97C: jal         0x80018618
    // 0x8003E980: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    checkpoint_is_passed(rdram, ctx);
        goto after_7;
    // 0x8003E980: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_7:
    // 0x8003E984: lw          $v1, 0x9C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X9C);
    // 0x8003E988: bne         $v0, $zero, L_8003E9B8
    if (ctx->r2 != 0) {
        // 0x8003E98C: nop
    
            goto L_8003E9B8;
    }
    // 0x8003E98C: nop

    // 0x8003E990: lb          $t2, 0x19($s1)
    ctx->r10 = MEM_B(ctx->r17, 0X19);
    // 0x8003E994: nop

    // 0x8003E998: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8003E99C: sb          $t3, 0x19($s1)
    MEM_B(0X19, ctx->r17) = ctx->r11;
    // 0x8003E9A0: lb          $t4, 0x19($s1)
    ctx->r12 = MEM_B(ctx->r17, 0X19);
    // 0x8003E9A4: nop

    // 0x8003E9A8: slt         $at, $t4, $v1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003E9AC: bne         $at, $zero, L_8003E9B8
    if (ctx->r1 != 0) {
        // 0x8003E9B0: nop
    
            goto L_8003E9B8;
    }
    // 0x8003E9B0: nop

    // 0x8003E9B4: sb          $zero, 0x19($s1)
    MEM_B(0X19, ctx->r17) = 0;
L_8003E9B8:
    // 0x8003E9B8: lbu         $v0, 0x18($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X18);
    // 0x8003E9BC: b           L_8003E9CC
    // 0x8003E9C0: nop

        goto L_8003E9CC;
    // 0x8003E9C0: nop

L_8003E9C4:
    // 0x8003E9C4: lbu         $v0, 0x18($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X18);
    // 0x8003E9C8: sb          $t5, 0x19($s1)
    MEM_B(0X19, ctx->r17) = ctx->r13;
L_8003E9CC:
    // 0x8003E9CC: bne         $v0, $zero, L_8003E9EC
    if (ctx->r2 != 0) {
        // 0x8003E9D0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8003E9EC;
    }
    // 0x8003E9D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003E9D4: lw          $a1, 0xEC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XEC);
    // 0x8003E9D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003E9DC: jal         0x8003EE18
    // 0x8003E9E0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    homing_rocket_prevent_overshoot(rdram, ctx);
        goto after_8;
    // 0x8003E9E0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_8:
    // 0x8003E9E4: b           L_8003E9FC
    // 0x8003E9E8: lw          $v1, 0x4C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4C);
        goto L_8003E9FC;
    // 0x8003E9E8: lw          $v1, 0x4C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4C);
L_8003E9EC:
    // 0x8003E9EC: lw          $a1, 0xEC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XEC);
    // 0x8003E9F0: jal         0x8003EC54
    // 0x8003E9F4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    rocket_prevent_overshoot(rdram, ctx);
        goto after_9;
    // 0x8003E9F4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_9:
    // 0x8003E9F8: lw          $v1, 0x4C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4C);
L_8003E9FC:
    // 0x8003E9FC: nop

    // 0x8003EA00: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8003EA04: nop

    // 0x8003EA08: beq         $v0, $zero, L_8003EB44
    if (ctx->r2 == 0) {
        // 0x8003EA0C: nop
    
            goto L_8003EB44;
    }
    // 0x8003EA0C: nop

    // 0x8003EA10: lw          $t6, 0x4($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X4);
    // 0x8003EA14: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8003EA18: bne         $v0, $t6, L_8003EA4C
    if (ctx->r2 != ctx->r14) {
        // 0x8003EA1C: addiu       $a0, $zero, 0x1C2
        ctx->r4 = ADD32(0, 0X1C2);
            goto L_8003EA4C;
    }
    // 0x8003EA1C: addiu       $a0, $zero, 0x1C2
    ctx->r4 = ADD32(0, 0X1C2);
    // 0x8003EA20: jal         0x8000C8B4
    // 0x8003EA24: sw          $v0, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r2;
    normalise_time(rdram, ctx);
        goto after_10;
    // 0x8003EA24: sw          $v0, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r2;
    after_10:
    // 0x8003EA28: lw          $v1, 0x78($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X78);
    // 0x8003EA2C: lw          $a1, 0xE4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XE4);
    // 0x8003EA30: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003EA34: beq         $at, $zero, L_8003EB44
    if (ctx->r1 == 0) {
        // 0x8003EA38: nop
    
            goto L_8003EB44;
    }
    // 0x8003EA38: nop

    // 0x8003EA3C: beq         $v1, $zero, L_8003EB44
    if (ctx->r3 == 0) {
        // 0x8003EA40: nop
    
            goto L_8003EB44;
    }
    // 0x8003EA40: nop

    // 0x8003EA44: lw          $v1, 0x4C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4C);
    // 0x8003EA48: nop

L_8003EA4C:
    // 0x8003EA4C: lbu         $t7, 0x18($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X18);
    // 0x8003EA50: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // 0x8003EA54: bne         $t7, $zero, L_8003EA7C
    if (ctx->r15 != 0) {
        // 0x8003EA58: nop
    
            goto L_8003EA7C;
    }
    // 0x8003EA58: nop

    // 0x8003EA5C: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8003EA60: nop

    // 0x8003EA64: bne         $a1, $t8, L_8003EA74
    if (ctx->r5 != ctx->r24) {
        // 0x8003EA68: nop
    
            goto L_8003EA74;
    }
    // 0x8003EA68: nop

    // 0x8003EA6C: b           L_8003EA7C
    // 0x8003EA70: addiu       $v0, $zero, 0x4B
    ctx->r2 = ADD32(0, 0X4B);
        goto L_8003EA7C;
    // 0x8003EA70: addiu       $v0, $zero, 0x4B
    ctx->r2 = ADD32(0, 0X4B);
L_8003EA74:
    // 0x8003EA74: b           L_8003EA7C
    // 0x8003EA78: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
        goto L_8003EA7C;
    // 0x8003EA78: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
L_8003EA7C:
    // 0x8003EA7C: lbu         $t9, 0x13($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X13);
    // 0x8003EA80: nop

    // 0x8003EA84: slt         $at, $t9, $v0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003EA88: beq         $at, $zero, L_8003EB44
    if (ctx->r1 == 0) {
        // 0x8003EA8C: nop
    
            goto L_8003EB44;
    }
    // 0x8003EA8C: nop

    // 0x8003EA90: lw          $t0, 0x40($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X40);
    // 0x8003EA94: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8003EA98: lb          $t1, 0x54($t0)
    ctx->r9 = MEM_B(ctx->r8, 0X54);
    // 0x8003EA9C: nop

    // 0x8003EAA0: bne         $a0, $t1, L_8003EB04
    if (ctx->r4 != ctx->r9) {
        // 0x8003EAA4: nop
    
            goto L_8003EB04;
    }
    // 0x8003EAA4: nop

    // 0x8003EAA8: lw          $v1, 0x64($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X64);
    // 0x8003EAAC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8003EAB0: sb          $a0, 0x187($v1)
    MEM_B(0X187, ctx->r3) = ctx->r4;
    // 0x8003EAB4: lw          $t2, 0x4($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X4);
    // 0x8003EAB8: lh          $t3, 0x0($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X0);
    // 0x8003EABC: lw          $v0, 0x64($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X64);
    // 0x8003EAC0: bne         $a2, $t3, L_8003EAD8
    if (ctx->r6 != ctx->r11) {
        // 0x8003EAC4: nop
    
            goto L_8003EAD8;
    }
    // 0x8003EAC4: nop

    // 0x8003EAC8: lh          $t4, 0x0($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X0);
    // 0x8003EACC: nop

    // 0x8003EAD0: beq         $a2, $t4, L_8003EAE8
    if (ctx->r6 == ctx->r12) {
        // 0x8003EAD4: nop
    
            goto L_8003EAE8;
    }
    // 0x8003EAD4: nop

L_8003EAD8:
    // 0x8003EAD8: lbu         $t5, 0x1EF($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X1EF);
    // 0x8003EADC: nop

    // 0x8003EAE0: ori         $t6, $t5, 0x2
    ctx->r14 = ctx->r13 | 0X2;
    // 0x8003EAE4: sb          $t6, 0x1EF($v0)
    MEM_B(0X1EF, ctx->r2) = ctx->r14;
L_8003EAE8:
    // 0x8003EAE8: lb          $t7, 0x1D8($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X1D8);
    // 0x8003EAEC: nop

    // 0x8003EAF0: bne         $t7, $zero, L_8003EB04
    if (ctx->r15 != 0) {
        // 0x8003EAF4: nop
    
            goto L_8003EB04;
    }
    // 0x8003EAF4: nop

    // 0x8003EAF8: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x8003EAFC: jal         0x80072594
    // 0x8003EB00: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    rumble_set(rdram, ctx);
        goto after_11;
    // 0x8003EB00: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_11:
L_8003EB04:
    // 0x8003EB04: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003EB08: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003EB0C: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x8003EB10: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003EB14: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003EB18: addiu       $t8, $zero, 0x11
    ctx->r24 = ADD32(0, 0X11);
    // 0x8003EB1C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8003EB20: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8003EB24: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8003EB28: addiu       $a3, $zero, 0x2C
    ctx->r7 = ADD32(0, 0X2C);
    // 0x8003EB2C: jal         0x8003FC84
    // 0x8003EB30: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    obj_spawn_effect(rdram, ctx);
        goto after_12;
    // 0x8003EB30: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_12:
    // 0x8003EB34: jal         0x8000FFB8
    // 0x8003EB38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    free_object(rdram, ctx);
        goto after_13;
    // 0x8003EB38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x8003EB3C: b           L_8003EC44
    // 0x8003EB40: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8003EC44;
    // 0x8003EB40: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8003EB44:
    // 0x8003EB44: lw          $t0, 0x7C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X7C);
    // 0x8003EB48: lw          $t1, 0xEC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XEC);
    // 0x8003EB4C: lw          $v1, 0x60($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X60);
    // 0x8003EB50: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8003EB54: beq         $v1, $zero, L_8003EBF4
    if (ctx->r3 == 0) {
        // 0x8003EB58: sw          $t2, 0x7C($s0)
        MEM_W(0X7C, ctx->r16) = ctx->r10;
            goto L_8003EBF4;
    }
    // 0x8003EB58: sw          $t2, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r10;
    // 0x8003EB5C: lw          $s1, 0x4($v1)
    ctx->r17 = MEM_W(ctx->r3, 0X4);
    // 0x8003EB60: slti        $at, $t2, 0x8
    ctx->r1 = SIGNED(ctx->r10) < 0X8 ? 1 : 0;
    // 0x8003EB64: beq         $at, $zero, L_8003EB8C
    if (ctx->r1 == 0) {
        // 0x8003EB68: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_8003EB8C;
    }
    // 0x8003EB68: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8003EB6C: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8003EB70: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8003EB74: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8003EB78: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003EB7C: nop

    // 0x8003EB80: mul.s       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x8003EB84: b           L_8003EBF4
    // 0x8003EB88: swc1        $f18, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f18.u32l;
        goto L_8003EBF4;
    // 0x8003EB88: swc1        $f18, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f18.u32l;
L_8003EB8C:
    // 0x8003EB8C: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x8003EB90: beq         $at, $zero, L_8003EBC8
    if (ctx->r1 == 0) {
        // 0x8003EB94: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8003EBC8;
    }
    // 0x8003EB94: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8003EB98: addiu       $t3, $v0, -0x8
    ctx->r11 = ADD32(ctx->r2, -0X8);
    // 0x8003EB9C: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x8003EBA0: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8003EBA4: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003EBA8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003EBAC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8003EBB0: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8003EBB4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003EBB8: nop

    // 0x8003EBBC: sub.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x8003EBC0: b           L_8003EBF4
    // 0x8003EBC4: swc1        $f18, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f18.u32l;
        goto L_8003EBF4;
    // 0x8003EBC4: swc1        $f18, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f18.u32l;
L_8003EBC8:
    // 0x8003EBC8: sll         $t4, $a0, 28
    ctx->r12 = S32(ctx->r4 << 28);
    // 0x8003EBCC: jal         0x80070A04
    // 0x8003EBD0: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    sins_f(rdram, ctx);
        goto after_14;
    // 0x8003EBD0: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    after_14:
    // 0x8003EBD4: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8003EBD8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003EBDC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003EBE0: mul.s       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8003EBE4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003EBE8: nop

    // 0x8003EBEC: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8003EBF0: swc1        $f6, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f6.u32l;
L_8003EBF4:
    // 0x8003EBF4: lw          $t6, 0x78($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X78);
    // 0x8003EBF8: lw          $t7, 0xEC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XEC);
    // 0x8003EBFC: addiu       $a3, $zero, 0x2C
    ctx->r7 = ADD32(0, 0X2C);
    // 0x8003EC00: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x8003EC04: bgez        $t8, L_8003EC40
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8003EC08: sw          $t8, 0x78($s0)
        MEM_W(0X78, ctx->r16) = ctx->r24;
            goto L_8003EC40;
    }
    // 0x8003EC08: sw          $t8, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r24;
    // 0x8003EC0C: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003EC10: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003EC14: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x8003EC18: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003EC1C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003EC20: addiu       $t0, $zero, 0x11
    ctx->r8 = ADD32(0, 0X11);
    // 0x8003EC24: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8003EC28: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8003EC2C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8003EC30: jal         0x8003FC84
    // 0x8003EC34: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    obj_spawn_effect(rdram, ctx);
        goto after_15;
    // 0x8003EC34: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_15:
    // 0x8003EC38: jal         0x8000FFB8
    // 0x8003EC3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    free_object(rdram, ctx);
        goto after_16;
    // 0x8003EC3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
L_8003EC40:
    // 0x8003EC40: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8003EC44:
    // 0x8003EC44: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8003EC48: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8003EC4C: jr          $ra
    // 0x8003EC50: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    return;
    // 0x8003EC50: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
;}
RECOMP_FUNC void rocket_prevent_overshoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003EC54: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8003EC58: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003EC5C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003EC60: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8003EC64: lw          $v0, 0x4C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4C);
    // 0x8003EC68: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8003EC6C: lbu         $t6, 0x13($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X13);
    // 0x8003EC70: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8003EC74: slti        $at, $t6, 0x50
    ctx->r1 = SIGNED(ctx->r14) < 0X50 ? 1 : 0;
    // 0x8003EC78: bne         $at, $zero, L_8003EC90
    if (ctx->r1 != 0) {
        // 0x8003EC7C: nop
    
            goto L_8003EC90;
    }
    // 0x8003EC7C: nop

    // 0x8003EC80: lw          $t7, 0x8($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X8);
    // 0x8003EC84: nop

    // 0x8003EC88: beq         $t7, $zero, L_8003ECC4
    if (ctx->r15 == 0) {
        // 0x8003EC8C: nop
    
            goto L_8003ECC4;
    }
    // 0x8003EC8C: nop

L_8003EC90:
    // 0x8003EC90: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8003EC94: nop

    // 0x8003EC98: beq         $a1, $zero, L_8003ECC4
    if (ctx->r5 == 0) {
        // 0x8003EC9C: nop
    
            goto L_8003ECC4;
    }
    // 0x8003EC9C: nop

    // 0x8003ECA0: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x8003ECA4: nop

    // 0x8003ECA8: beq         $a1, $t8, L_8003ECC4
    if (ctx->r5 == ctx->r24) {
        // 0x8003ECAC: nop
    
            goto L_8003ECC4;
    }
    // 0x8003ECAC: nop

    // 0x8003ECB0: lh          $t9, 0x48($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X48);
    // 0x8003ECB4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003ECB8: bne         $t9, $at, L_8003ECC4
    if (ctx->r25 != ctx->r1) {
        // 0x8003ECBC: nop
    
            goto L_8003ECC4;
    }
    // 0x8003ECBC: nop

    // 0x8003ECC0: sw          $a1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r5;
L_8003ECC4:
    // 0x8003ECC4: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8003ECC8: nop

    // 0x8003ECCC: beq         $v0, $zero, L_8003EDFC
    if (ctx->r2 == 0) {
        // 0x8003ECD0: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8003EDFC;
    }
    // 0x8003ECD0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8003ECD4: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8003ECD8: lwc1        $f6, 0xC($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8003ECDC: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8003ECE0: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8003ECE4: lwc1        $f10, 0x10($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X10);
    // 0x8003ECE8: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8003ECEC: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8003ECF0: lwc1        $f16, 0x14($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8003ECF4: lwc1        $f18, 0x14($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X14);
    // 0x8003ECF8: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8003ECFC: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8003ED00: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x8003ED04: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x8003ED08: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8003ED0C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8003ED10: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8003ED14: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x8003ED18: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8003ED1C: jal         0x800CA030
    // 0x8003ED20: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8003ED20: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_0:
    // 0x8003ED24: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8003ED28: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8003ED2C: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8003ED30: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8003ED34: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8003ED38: bc1f        L_8003EDF8
    if (!c1cs) {
        // 0x8003ED3C: swc1        $f0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
            goto L_8003EDF8;
    }
    // 0x8003ED3C: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8003ED40: lui         $at, 0xC1C8
    ctx->r1 = S32(0XC1C8 << 16);
    // 0x8003ED44: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003ED48: nop

    // 0x8003ED4C: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
    // 0x8003ED50: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8003ED54: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x8003ED58: jal         0x80070990
    // 0x8003ED5C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    arctan2_f(rdram, ctx);
        goto after_1;
    // 0x8003ED5C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_1:
    // 0x8003ED60: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8003ED64: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x8003ED68: lh          $t1, 0x0($a3)
    ctx->r9 = MEM_H(ctx->r7, 0X0);
    // 0x8003ED6C: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x8003ED70: andi        $a2, $v1, 0xFFFF
    ctx->r6 = ctx->r3 & 0XFFFF;
    // 0x8003ED74: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x8003ED78: subu        $a0, $a2, $t2
    ctx->r4 = SUB32(ctx->r6, ctx->r10);
    // 0x8003ED7C: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8003ED80: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8003ED84: slt         $at, $a0, $at
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8003ED88: bne         $at, $zero, L_8003ED98
    if (ctx->r1 != 0) {
        // 0x8003ED8C: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8003ED98;
    }
    // 0x8003ED8C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8003ED90: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8003ED94: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
L_8003ED98:
    // 0x8003ED98: slti        $at, $a0, -0x8000
    ctx->r1 = SIGNED(ctx->r4) < -0X8000 ? 1 : 0;
    // 0x8003ED9C: beq         $at, $zero, L_8003EDA8
    if (ctx->r1 == 0) {
        // 0x8003EDA0: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8003EDA8;
    }
    // 0x8003EDA0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8003EDA4: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
L_8003EDA8:
    // 0x8003EDA8: slti        $at, $a0, 0x6001
    ctx->r1 = SIGNED(ctx->r4) < 0X6001 ? 1 : 0;
    // 0x8003EDAC: beq         $at, $zero, L_8003EDBC
    if (ctx->r1 == 0) {
        // 0x8003EDB0: slti        $at, $a0, -0x6000
        ctx->r1 = SIGNED(ctx->r4) < -0X6000 ? 1 : 0;
            goto L_8003EDBC;
    }
    // 0x8003EDB0: slti        $at, $a0, -0x6000
    ctx->r1 = SIGNED(ctx->r4) < -0X6000 ? 1 : 0;
    // 0x8003EDB4: beq         $at, $zero, L_8003EDD4
    if (ctx->r1 == 0) {
        // 0x8003EDB8: nop
    
            goto L_8003EDD4;
    }
    // 0x8003EDB8: nop

L_8003EDBC:
    // 0x8003EDBC: lw          $t3, 0x4C($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X4C);
    // 0x8003EDC0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8003EDC4: sw          $a1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r5;
    // 0x8003EDC8: lw          $t5, 0x4C($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X4C);
    // 0x8003EDCC: nop

    // 0x8003EDD0: sb          $t4, 0x13($t5)
    MEM_B(0X13, ctx->r13) = ctx->r12;
L_8003EDD4:
    // 0x8003EDD4: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8003EDD8: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8003EDDC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8003EDE0: jal         0x80070990
    // 0x8003EDE4: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    arctan2_f(rdram, ctx);
        goto after_2;
    // 0x8003EDE4: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_2:
    // 0x8003EDE8: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8003EDEC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8003EDF0: sh          $v0, 0x2($a3)
    MEM_H(0X2, ctx->r7) = ctx->r2;
    // 0x8003EDF4: sh          $a2, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r6;
L_8003EDF8:
    // 0x8003EDF8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_8003EDFC:
    // 0x8003EDFC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8003EE00: jal         0x8003F138
    // 0x8003EE04: addiu       $a2, $zero, 0x137
    ctx->r6 = ADD32(0, 0X137);
    play_rocket_trailing_sound(rdram, ctx);
        goto after_3;
    // 0x8003EE04: addiu       $a2, $zero, 0x137
    ctx->r6 = ADD32(0, 0X137);
    after_3:
    // 0x8003EE08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003EE0C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003EE10: jr          $ra
    // 0x8003EE14: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8003EE14: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void homing_rocket_prevent_overshoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003EE18: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8003EE1C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8003EE20: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x8003EE24: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x8003EE28: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x8003EE2C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8003EE30: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003EE34: beq         $v0, $zero, L_8003F0BC
    if (ctx->r2 == 0) {
        // 0x8003EE38: or          $s1, $a2, $zero
        ctx->r17 = ctx->r6 | 0;
            goto L_8003F0BC;
    }
    // 0x8003EE38: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8003EE3C: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x8003EE40: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003EE44: lh          $t6, 0x1BA($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X1BA);
    // 0x8003EE48: lwc1        $f13, 0x6788($at)
    ctx->f_odd[(13 - 1) * 2] = MEM_W(ctx->r1, 0X6788);
    // 0x8003EE4C: lwc1        $f12, 0x678C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X678C);
    // 0x8003EE50: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x8003EE54: sh          $t7, 0x14($a2)
    MEM_H(0X14, ctx->r6) = ctx->r15;
    // 0x8003EE58: lh          $t8, 0x1BC($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X1BC);
    // 0x8003EE5C: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x8003EE60: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x8003EE64: sh          $t9, 0x16($a2)
    MEM_H(0X16, ctx->r6) = ctx->r25;
    // 0x8003EE68: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8003EE6C: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8003EE70: nop

    // 0x8003EE74: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8003EE78: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    // 0x8003EE7C: lwc1        $f18, 0x10($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8003EE80: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8003EE84: nop

    // 0x8003EE88: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8003EE8C: lwc1        $f18, 0x68($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8003EE90: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    // 0x8003EE94: lwc1        $f8, 0x14($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8003EE98: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8003EE9C: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8003EEA0: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8003EEA4: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    // 0x8003EEA8: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8003EEAC: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8003EEB0: mul.s       $f8, $f6, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8003EEB4: add.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8003EEB8: mul.s       $f2, $f10, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x8003EEBC: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8003EEC0: c.lt.d      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.d < ctx->f12.d;
    // 0x8003EEC4: nop

    // 0x8003EEC8: bc1f        L_8003EEEC
    if (!c1cs) {
        // 0x8003EECC: mov.s       $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
            goto L_8003EEEC;
    }
    // 0x8003EECC: mov.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
    // 0x8003EED0: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x8003EED4: c.lt.d      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.d < ctx->f6.d;
    // 0x8003EED8: nop

    // 0x8003EEDC: bc1f        L_8003EEEC
    if (!c1cs) {
        // 0x8003EEE0: nop
    
            goto L_8003EEEC;
    }
    // 0x8003EEE0: nop

    // 0x8003EEE4: b           L_8003F0FC
    // 0x8003EEE8: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
        goto L_8003F0FC;
    // 0x8003EEE8: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
L_8003EEEC:
    // 0x8003EEEC: add.s       $f12, $f16, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f14.fl;
    // 0x8003EEF0: sw          $v1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r3;
    // 0x8003EEF4: jal         0x800CA030
    // 0x8003EEF8: sw          $t0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r8;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8003EEF8: sw          $t0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r8;
    after_0:
    // 0x8003EEFC: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8003EF00: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003EF04: lw          $v1, 0x70($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X70);
    // 0x8003EF08: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8003EF0C: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x8003EF10: bc1f        L_8003EF98
    if (!c1cs) {
        // 0x8003EF14: swc1        $f0, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
            goto L_8003EF98;
    }
    // 0x8003EF14: swc1        $f0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
    // 0x8003EF18: lb          $a1, 0x19($s1)
    ctx->r5 = MEM_B(ctx->r17, 0X19);
    // 0x8003EF1C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003EF20: beq         $a1, $at, L_8003EF9C
    if (ctx->r5 == ctx->r1) {
        // 0x8003EF24: lui         $at, 0xC1C8
        ctx->r1 = S32(0XC1C8 << 16);
            goto L_8003EF9C;
    }
    // 0x8003EF24: lui         $at, 0xC1C8
    ctx->r1 = S32(0XC1C8 << 16);
    // 0x8003EF28: lw          $t2, 0x8($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X8);
    // 0x8003EF2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003EF30: bne         $t2, $zero, L_8003EF98
    if (ctx->r10 != 0) {
        // 0x8003EF34: addiu       $t4, $sp, 0x68
        ctx->r12 = ADD32(ctx->r29, 0X68);
            goto L_8003EF98;
    }
    // 0x8003EF34: addiu       $t4, $sp, 0x68
    ctx->r12 = ADD32(ctx->r29, 0X68);
    // 0x8003EF38: lh          $t3, 0x16($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X16);
    // 0x8003EF3C: lbu         $a2, 0x1C8($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X1C8);
    // 0x8003EF40: lh          $a3, 0x14($s1)
    ctx->r7 = MEM_H(ctx->r17, 0X14);
    // 0x8003EF44: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8003EF48: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8003EF4C: addiu       $t5, $sp, 0x64
    ctx->r13 = ADD32(ctx->r29, 0X64);
    // 0x8003EF50: addiu       $t6, $sp, 0x60
    ctx->r14 = ADD32(ctx->r29, 0X60);
    // 0x8003EF54: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x8003EF58: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8003EF5C: sw          $t0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r8;
    // 0x8003EF60: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8003EF64: jal         0x80019590
    // 0x8003EF68: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    homing_rocket_get_next_direction(rdram, ctx);
        goto after_1;
    // 0x8003EF68: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x8003EF6C: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8003EF70: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8003EF74: lwc1        $f12, 0x64($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8003EF78: jal         0x80070990
    // 0x8003EF7C: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    arctan2_f(rdram, ctx);
        goto after_2;
    // 0x8003EF7C: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    after_2:
    // 0x8003EF80: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x8003EF84: andi        $t7, $v0, 0xFFFF
    ctx->r15 = ctx->r2 & 0XFFFF;
    // 0x8003EF88: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8003EF8C: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
    // 0x8003EF90: b           L_8003EFAC
    // 0x8003EF94: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
        goto L_8003EFAC;
    // 0x8003EF94: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
L_8003EF98:
    // 0x8003EF98: lui         $at, 0xC1C8
    ctx->r1 = S32(0XC1C8 << 16);
L_8003EF9C:
    // 0x8003EF9C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003EFA0: sw          $t0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r8;
    // 0x8003EFA4: swc1        $f10, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f10.u32l;
    // 0x8003EFA8: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
L_8003EFAC:
    // 0x8003EFAC: lwc1        $f12, 0x68($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8003EFB0: lwc1        $f14, 0x60($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8003EFB4: jal         0x80070990
    // 0x8003EFB8: sw          $t0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r8;
    arctan2_f(rdram, ctx);
        goto after_3;
    // 0x8003EFB8: sw          $t0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r8;
    after_3:
    // 0x8003EFBC: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    // 0x8003EFC0: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x8003EFC4: addu        $a0, $v0, $at
    ctx->r4 = ADD32(ctx->r2, ctx->r1);
    // 0x8003EFC8: andi        $a2, $a0, 0xFFFF
    ctx->r6 = ctx->r4 & 0XFFFF;
    // 0x8003EFCC: andi        $t2, $a1, 0xFFFF
    ctx->r10 = ctx->r5 & 0XFFFF;
    // 0x8003EFD0: ori         $a3, $zero, 0x8001
    ctx->r7 = 0 | 0X8001;
    // 0x8003EFD4: subu        $v1, $a2, $t2
    ctx->r3 = SUB32(ctx->r6, ctx->r10);
    // 0x8003EFD8: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x8003EFDC: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x8003EFE0: slt         $at, $v1, $a3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8003EFE4: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x8003EFE8: bne         $at, $zero, L_8003EFF8
    if (ctx->r1 != 0) {
        // 0x8003EFEC: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8003EFF8;
    }
    // 0x8003EFEC: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8003EFF0: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8003EFF4: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8003EFF8:
    // 0x8003EFF8: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x8003EFFC: beq         $at, $zero, L_8003F008
    if (ctx->r1 == 0) {
        // 0x8003F000: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8003F008;
    }
    // 0x8003F000: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8003F004: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8003F008:
    // 0x8003F008: beq         $t3, $zero, L_8003F078
    if (ctx->r11 == 0) {
        // 0x8003F00C: slti        $at, $v1, 0x6001
        ctx->r1 = SIGNED(ctx->r3) < 0X6001 ? 1 : 0;
            goto L_8003F078;
    }
    // 0x8003F00C: slti        $at, $v1, 0x6001
    ctx->r1 = SIGNED(ctx->r3) < 0X6001 ? 1 : 0;
    // 0x8003F010: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    // 0x8003F014: lh          $v0, 0x2($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X2);
    // 0x8003F018: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003F01C: andi        $t8, $v0, 0xFFFF
    ctx->r24 = ctx->r2 & 0XFFFF;
    // 0x8003F020: mflo        $t4
    ctx->r12 = lo;
    // 0x8003F024: srav        $t5, $t4, $t1
    ctx->r13 = S32(SIGNED(ctx->r12) >> (ctx->r9 & 31));
    // 0x8003F028: addu        $t6, $a1, $t5
    ctx->r14 = ADD32(ctx->r5, ctx->r13);
    // 0x8003F02C: sh          $t6, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r14;
    // 0x8003F030: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8003F034: nop

    // 0x8003F038: subu        $v1, $t7, $t8
    ctx->r3 = SUB32(ctx->r15, ctx->r24);
    // 0x8003F03C: slt         $at, $v1, $a3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8003F040: bne         $at, $zero, L_8003F050
    if (ctx->r1 != 0) {
        // 0x8003F044: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8003F050;
    }
    // 0x8003F044: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8003F048: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8003F04C: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8003F050:
    // 0x8003F050: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x8003F054: beq         $at, $zero, L_8003F060
    if (ctx->r1 == 0) {
        // 0x8003F058: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8003F060;
    }
    // 0x8003F058: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8003F05C: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8003F060:
    // 0x8003F060: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003F064: mflo        $t9
    ctx->r25 = lo;
    // 0x8003F068: srav        $t2, $t9, $t1
    ctx->r10 = S32(SIGNED(ctx->r25) >> (ctx->r9 & 31));
    // 0x8003F06C: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x8003F070: b           L_8003F0BC
    // 0x8003F074: sh          $t3, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r11;
        goto L_8003F0BC;
    // 0x8003F074: sh          $t3, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r11;
L_8003F078:
    // 0x8003F078: beq         $at, $zero, L_8003F088
    if (ctx->r1 == 0) {
        // 0x8003F07C: slti        $at, $v1, -0x6000
        ctx->r1 = SIGNED(ctx->r3) < -0X6000 ? 1 : 0;
            goto L_8003F088;
    }
    // 0x8003F07C: slti        $at, $v1, -0x6000
    ctx->r1 = SIGNED(ctx->r3) < -0X6000 ? 1 : 0;
    // 0x8003F080: beq         $at, $zero, L_8003F0A0
    if (ctx->r1 == 0) {
        // 0x8003F084: nop
    
            goto L_8003F0A0;
    }
    // 0x8003F084: nop

L_8003F088:
    // 0x8003F088: lw          $t4, 0x4C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4C);
    // 0x8003F08C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8003F090: sw          $t0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r8;
    // 0x8003F094: lw          $t6, 0x4C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4C);
    // 0x8003F098: nop

    // 0x8003F09C: sb          $t5, 0x13($t6)
    MEM_B(0X13, ctx->r14) = ctx->r13;
L_8003F0A0:
    // 0x8003F0A0: lwc1        $f12, 0x64($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8003F0A4: lwc1        $f14, 0x6C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8003F0A8: jal         0x80070990
    // 0x8003F0AC: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    arctan2_f(rdram, ctx);
        goto after_4;
    // 0x8003F0AC: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    after_4:
    // 0x8003F0B0: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x8003F0B4: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    // 0x8003F0B8: sh          $a2, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r6;
L_8003F0BC:
    // 0x8003F0BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003F0C0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8003F0C4: jal         0x8003F138
    // 0x8003F0C8: addiu       $a2, $zero, 0x136
    ctx->r6 = ADD32(0, 0X136);
    play_rocket_trailing_sound(rdram, ctx);
        goto after_5;
    // 0x8003F0C8: addiu       $a2, $zero, 0x136
    ctx->r6 = ADD32(0, 0X136);
    after_5:
    // 0x8003F0CC: jal         0x8009C90C
    // 0x8003F0D0: nop

    get_number_of_active_players(rdram, ctx);
        goto after_6;
    // 0x8003F0D0: nop

    after_6:
    // 0x8003F0D4: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8003F0D8: beq         $at, $zero, L_8003F100
    if (ctx->r1 == 0) {
        // 0x8003F0DC: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8003F100;
    }
    // 0x8003F0DC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8003F0E0: lw          $t8, 0x74($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X74);
    // 0x8003F0E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003F0E8: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x8003F0EC: sw          $t9, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r25;
    // 0x8003F0F0: lw          $a1, 0x7C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X7C);
    // 0x8003F0F4: jal         0x800B019C
    // 0x8003F0F8: nop

    obj_spawn_particle(rdram, ctx);
        goto after_7;
    // 0x8003F0F8: nop

    after_7:
L_8003F0FC:
    // 0x8003F0FC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8003F100:
    // 0x8003F100: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x8003F104: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x8003F108: jr          $ra
    // 0x8003F10C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x8003F10C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
