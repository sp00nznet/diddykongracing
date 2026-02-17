#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void __resetPerfChanState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000ADF4: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x8000ADF8: lw          $t6, 0x60($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X60);
    // 0x8000ADFC: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8000AE00: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000AE04: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x8000AE08: sb          $zero, 0x6($t7)
    MEM_B(0X6, ctx->r15) = 0;
    // 0x8000AE0C: lw          $t8, 0x60($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X60);
    // 0x8000AE10: addiu       $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
    // 0x8000AE14: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8000AE18: sb          $zero, 0xA($t9)
    MEM_B(0XA, ctx->r25) = 0;
    // 0x8000AE1C: lw          $t1, 0x60($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X60);
    // 0x8000AE20: addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
    // 0x8000AE24: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x8000AE28: sb          $t0, 0x7($t2)
    MEM_B(0X7, ctx->r10) = ctx->r8;
    // 0x8000AE2C: lw          $t3, 0x60($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X60);
    // 0x8000AE30: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x8000AE34: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x8000AE38: sb          $v1, 0x9($t4)
    MEM_B(0X9, ctx->r12) = ctx->r3;
    // 0x8000AE3C: lw          $t5, 0x60($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X60);
    // 0x8000AE40: addiu       $t2, $zero, 0xC8
    ctx->r10 = ADD32(0, 0XC8);
    // 0x8000AE44: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x8000AE48: sb          $v1, 0x10($t6)
    MEM_B(0X10, ctx->r14) = ctx->r3;
    // 0x8000AE4C: lw          $t8, 0x60($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X60);
    // 0x8000AE50: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000AE54: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8000AE58: sb          $t7, 0x8($t9)
    MEM_B(0X8, ctx->r25) = ctx->r15;
    // 0x8000AE5C: lw          $t1, 0x60($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X60);
    // 0x8000AE60: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000AE64: addu        $t0, $t1, $v0
    ctx->r8 = ADD32(ctx->r9, ctx->r2);
    // 0x8000AE68: sb          $zero, 0xB($t0)
    MEM_B(0XB, ctx->r8) = 0;
    // 0x8000AE6C: lw          $t3, 0x60($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X60);
    // 0x8000AE70: nop

    // 0x8000AE74: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x8000AE78: sh          $t2, 0x4($t4)
    MEM_H(0X4, ctx->r12) = ctx->r10;
    // 0x8000AE7C: lw          $t5, 0x60($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X60);
    // 0x8000AE80: nop

    // 0x8000AE84: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x8000AE88: jr          $ra
    // 0x8000AE8C: swc1        $f4, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f4.u32l;
    return;
    // 0x8000AE8C: swc1        $f4, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f4.u32l;
;}
RECOMP_FUNC void __initChanState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000AE90: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000AE94: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000AE98: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000AE9C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000AEA0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000AEA4: lbu         $t6, 0x34($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X34);
    // 0x8000AEA8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8000AEAC: blez        $t6, L_8000AEE4
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8000AEB0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8000AEE4;
    }
    // 0x8000AEB0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000AEB4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8000AEB8:
    // 0x8000AEB8: lw          $t7, 0x60($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X60);
    // 0x8000AEBC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8000AEC0: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x8000AEC4: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x8000AEC8: jal         0x8000ADF4
    // 0x8000AECC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    __resetPerfChanState(rdram, ctx);
        goto after_0;
    // 0x8000AECC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x8000AED0: lbu         $t9, 0x34($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X34);
    // 0x8000AED4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000AED8: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8000AEDC: bne         $at, $zero, L_8000AEB8
    if (ctx->r1 != 0) {
        // 0x8000AEE0: addiu       $s2, $s2, 0x14
        ctx->r18 = ADD32(ctx->r18, 0X14);
            goto L_8000AEB8;
    }
    // 0x8000AEE0: addiu       $s2, $s2, 0x14
    ctx->r18 = ADD32(ctx->r18, 0X14);
L_8000AEE4:
    // 0x8000AEE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000AEE8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000AEEC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000AEF0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000AEF4: jr          $ra
    // 0x8000AEF8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8000AEF8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void __seqpStopOsc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000AEFC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8000AF00: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8000AF04: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x8000AF08: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8000AF0C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8000AF10: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8000AF14: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8000AF18: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8000AF1C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000AF20: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000AF24: lw          $s0, 0x50($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X50);
    // 0x8000AF28: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x8000AF2C: beq         $s0, $zero, L_8000AFE4
    if (ctx->r16 == 0) {
        // 0x8000AF30: or          $s5, $a0, $zero
        ctx->r21 = ctx->r4 | 0;
            goto L_8000AFE4;
    }
    // 0x8000AF30: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x8000AF34: addiu       $s7, $zero, 0x17
    ctx->r23 = ADD32(0, 0X17);
    // 0x8000AF38: addiu       $s6, $zero, 0x16
    ctx->r22 = ADD32(0, 0X16);
L_8000AF3C:
    // 0x8000AF3C: lh          $s3, 0xC($s0)
    ctx->r19 = MEM_H(ctx->r16, 0XC);
    // 0x8000AF40: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x8000AF44: beq         $s3, $s6, L_8000AF54
    if (ctx->r19 == ctx->r22) {
        // 0x8000AF48: nop
    
            goto L_8000AF54;
    }
    // 0x8000AF48: nop

    // 0x8000AF4C: bne         $s3, $s7, L_8000AFDC
    if (ctx->r19 != ctx->r23) {
        // 0x8000AF50: nop
    
            goto L_8000AFDC;
    }
    // 0x8000AF50: nop

L_8000AF54:
    // 0x8000AF54: lw          $t6, 0x10($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X10);
    // 0x8000AF58: nop

    // 0x8000AF5C: bne         $s2, $t6, L_8000AFDC
    if (ctx->r18 != ctx->r14) {
        // 0x8000AF60: nop
    
            goto L_8000AFDC;
    }
    // 0x8000AF60: nop

    // 0x8000AF64: lw          $t9, 0x7C($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X7C);
    // 0x8000AF68: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    // 0x8000AF6C: jalr        $t9
    // 0x8000AF70: addiu       $s4, $s5, 0x48
    ctx->r20 = ADD32(ctx->r21, 0X48);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8000AF70: addiu       $s4, $s5, 0x48
    ctx->r20 = ADD32(ctx->r21, 0X48);
    after_0:
    // 0x8000AF74: jal         0x800C8CC0
    // 0x8000AF78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alUnlink(rdram, ctx);
        goto after_1;
    // 0x8000AF78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8000AF7C: beq         $s1, $zero, L_8000AF98
    if (ctx->r17 == 0) {
        // 0x8000AF80: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8000AF98;
    }
    // 0x8000AF80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000AF84: lw          $t7, 0x8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X8);
    // 0x8000AF88: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x8000AF8C: nop

    // 0x8000AF90: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x8000AF94: sw          $t0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r8;
L_8000AF98:
    // 0x8000AF98: jal         0x800C8CF0
    // 0x8000AF9C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    alLink(rdram, ctx);
        goto after_2;
    // 0x8000AF9C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_2:
    // 0x8000AFA0: bne         $s3, $s6, L_8000AFBC
    if (ctx->r19 != ctx->r22) {
        // 0x8000AFA4: nop
    
            goto L_8000AFBC;
    }
    // 0x8000AFA4: nop

    // 0x8000AFA8: lbu         $t1, 0x37($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0X37);
    // 0x8000AFAC: nop

    // 0x8000AFB0: andi        $t2, $t1, 0xFE
    ctx->r10 = ctx->r9 & 0XFE;
    // 0x8000AFB4: b           L_8000AFCC
    // 0x8000AFB8: sb          $t2, 0x37($s2)
    MEM_B(0X37, ctx->r18) = ctx->r10;
        goto L_8000AFCC;
    // 0x8000AFB8: sb          $t2, 0x37($s2)
    MEM_B(0X37, ctx->r18) = ctx->r10;
L_8000AFBC:
    // 0x8000AFBC: lbu         $t3, 0x37($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X37);
    // 0x8000AFC0: nop

    // 0x8000AFC4: andi        $t4, $t3, 0xFD
    ctx->r12 = ctx->r11 & 0XFD;
    // 0x8000AFC8: sb          $t4, 0x37($s2)
    MEM_B(0X37, ctx->r18) = ctx->r12;
L_8000AFCC:
    // 0x8000AFCC: lbu         $t5, 0x37($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0X37);
    // 0x8000AFD0: nop

    // 0x8000AFD4: beq         $t5, $zero, L_8000AFE8
    if (ctx->r13 == 0) {
        // 0x8000AFD8: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8000AFE8;
    }
    // 0x8000AFD8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8000AFDC:
    // 0x8000AFDC: bne         $s1, $zero, L_8000AF3C
    if (ctx->r17 != 0) {
        // 0x8000AFE0: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_8000AF3C;
    }
    // 0x8000AFE0: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_8000AFE4:
    // 0x8000AFE4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8000AFE8:
    // 0x8000AFE8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000AFEC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8000AFF0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8000AFF4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8000AFF8: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8000AFFC: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8000B000: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x8000B004: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x8000B008: jr          $ra
    // 0x8000B00C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8000B00C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void set_voice_limit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B010: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8000B014: jr          $ra
    // 0x8000B018: sb          $a1, 0x70($a0)
    MEM_B(0X70, ctx->r4) = ctx->r5;
    return;
    // 0x8000B018: sb          $a1, 0x70($a0)
    MEM_B(0X70, ctx->r4) = ctx->r5;
    // 0x8000B01C: nop

;}
RECOMP_FUNC void racerfx_alloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B020: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8000B024: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8000B028: sll         $s1, $a0, 2
    ctx->r17 = S32(ctx->r4 << 2);
    // 0x8000B02C: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x8000B030: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8000B034: addu        $s1, $s1, $a0
    ctx->r17 = ADD32(ctx->r17, ctx->r4);
    // 0x8000B038: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8000B03C: sll         $s1, $s1, 1
    ctx->r17 = S32(ctx->r17 << 1);
    // 0x8000B040: sll         $s0, $a1, 4
    ctx->r16 = S32(ctx->r5 << 4);
    // 0x8000B044: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8000B048: addu        $a0, $s0, $s1
    ctx->r4 = ADD32(ctx->r16, ctx->r17);
    // 0x8000B04C: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x8000B050: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8000B054: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x8000B058: sw          $s7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r23;
    // 0x8000B05C: sw          $s6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r22;
    // 0x8000B060: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x8000B064: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x8000B068: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8000B06C: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8000B070: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8000B074: jal         0x80070EDC
    // 0x8000B078: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x8000B078: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_0:
    // 0x8000B07C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8000B080: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8000B084: addu        $t8, $v0, $s0
    ctx->r24 = ADD32(ctx->r2, ctx->r16);
    // 0x8000B088: addiu       $a1, $a1, -0x3344
    ctx->r5 = ADD32(ctx->r5, -0X3344);
    // 0x8000B08C: addiu       $v1, $v1, -0x333C
    ctx->r3 = ADD32(ctx->r3, -0X333C);
    // 0x8000B090: addu        $t0, $t8, $s0
    ctx->r8 = ADD32(ctx->r24, ctx->r16);
    // 0x8000B094: addu        $t2, $t0, $s1
    ctx->r10 = ADD32(ctx->r8, ctx->r17);
    // 0x8000B098: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000B09C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8000B0A0: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x8000B0A4: sw          $t2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r10;
    // 0x8000B0A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000B0AC: sw          $s3, -0x4A88($at)
    MEM_W(-0X4A88, ctx->r1) = ctx->r19;
    // 0x8000B0B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000B0B4: sw          $zero, -0x4A84($at)
    MEM_W(-0X4A84, ctx->r1) = 0;
    // 0x8000B0B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000B0BC: sw          $s2, -0x4A80($at)
    MEM_W(-0X4A80, ctx->r1) = ctx->r18;
    // 0x8000B0C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000B0C4: sw          $zero, -0x4A7C($at)
    MEM_W(-0X4A7C, ctx->r1) = 0;
    // 0x8000B0C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000B0CC: sw          $zero, -0x4A78($at)
    MEM_W(-0X4A78, ctx->r1) = 0;
    // 0x8000B0D0: jal         0x8001E2D0
    // 0x8000B0D4: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    get_misc_asset(rdram, ctx);
        goto after_1;
    // 0x8000B0D4: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_1:
    // 0x8000B0D8: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8000B0DC: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8000B0E0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8000B0E4: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x8000B0E8: addiu       $s3, $s3, -0x4A18
    ctx->r19 = ADD32(ctx->r19, -0X4A18);
    // 0x8000B0EC: addiu       $s1, $s1, -0x4A60
    ctx->r17 = ADD32(ctx->r17, -0X4A60);
    // 0x8000B0F0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8000B0F4: addiu       $s7, $sp, 0x58
    ctx->r23 = ADD32(ctx->r29, 0X58);
    // 0x8000B0F8: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
L_8000B0FC:
    // 0x8000B0FC: addiu       $t3, $zero, 0x7E
    ctx->r11 = ADD32(0, 0X7E);
    // 0x8000B100: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x8000B104: sb          $t3, 0x58($sp)
    MEM_B(0X58, ctx->r29) = ctx->r11;
    // 0x8000B108: sb          $t4, 0x59($sp)
    MEM_B(0X59, ctx->r29) = ctx->r12;
    // 0x8000B10C: sh          $zero, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = 0;
    // 0x8000B110: sh          $zero, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = 0;
    // 0x8000B114: sh          $zero, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = 0;
    // 0x8000B118: sb          $s2, 0x60($sp)
    MEM_B(0X60, ctx->r29) = ctx->r18;
    // 0x8000B11C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8000B120: jal         0x8000EA54
    // 0x8000B124: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    spawn_object(rdram, ctx);
        goto after_2;
    // 0x8000B124: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8000B128: beq         $v0, $zero, L_8000B198
    if (ctx->r2 == 0) {
        // 0x8000B12C: sw          $v0, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r2;
            goto L_8000B198;
    }
    // 0x8000B12C: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8000B130: sw          $zero, 0x78($v0)
    MEM_W(0X78, ctx->r2) = 0;
    // 0x8000B134: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8000B138: sll         $t7, $s2, 7
    ctx->r15 = S32(ctx->r18 << 7);
    // 0x8000B13C: addu        $s0, $s5, $t7
    ctx->r16 = ADD32(ctx->r21, ctx->r15);
    // 0x8000B140: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8000B144: sw          $zero, 0x7C($t6)
    MEM_W(0X7C, ctx->r14) = 0;
    // 0x8000B148: lh          $a0, 0x6C($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X6C);
    // 0x8000B14C: addiu       $t8, $t8, -0x4A70
    ctx->r24 = ADD32(ctx->r24, -0X4A70);
    // 0x8000B150: sb          $zero, 0x70($s0)
    MEM_B(0X70, ctx->r16) = 0;
    // 0x8000B154: swc1        $f20, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f20.u32l;
    // 0x8000B158: addu        $s4, $s2, $t8
    ctx->r20 = ADD32(ctx->r18, ctx->r24);
    // 0x8000B15C: jal         0x8007C57C
    // 0x8000B160: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    tex_load_sprite(rdram, ctx);
        goto after_3;
    // 0x8000B160: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8000B164: lh          $a0, 0x6E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X6E);
    // 0x8000B168: jal         0x8007B2C4
    // 0x8000B16C: sw          $v0, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r2;
    load_texture(rdram, ctx);
        goto after_4;
    // 0x8000B16C: sw          $v0, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r2;
    after_4:
    // 0x8000B170: sw          $v0, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r2;
    // 0x8000B174: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000B178: jal         0x8006FB8C
    // 0x8000B17C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    rand_range(rdram, ctx);
        goto after_5;
    // 0x8000B17C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_5:
    // 0x8000B180: sb          $v0, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r2;
    // 0x8000B184: sb          $zero, 0x73($s0)
    MEM_B(0X73, ctx->r16) = 0;
    // 0x8000B188: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000B18C: jal         0x8006FB8C
    // 0x8000B190: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    rand_range(rdram, ctx);
        goto after_6;
    // 0x8000B190: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_6:
    // 0x8000B194: sb          $v0, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r2;
L_8000B198:
    // 0x8000B198: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8000B19C: slti        $at, $s2, 0xA
    ctx->r1 = SIGNED(ctx->r18) < 0XA ? 1 : 0;
    // 0x8000B1A0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8000B1A4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8000B1A8: bne         $at, $zero, L_8000B0FC
    if (ctx->r1 != 0) {
        // 0x8000B1AC: sb          $s6, -0x1($s3)
        MEM_B(-0X1, ctx->r19) = ctx->r22;
            goto L_8000B0FC;
    }
    // 0x8000B1AC: sb          $s6, -0x1($s3)
    MEM_B(-0X1, ctx->r19) = ctx->r22;
    // 0x8000B1B0: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
    // 0x8000B1B4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000B1B8: addiu       $t0, $zero, 0x8D
    ctx->r8 = ADD32(0, 0X8D);
    // 0x8000B1BC: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x8000B1C0: sw          $t9, -0x3330($at)
    MEM_W(-0X3330, ctx->r1) = ctx->r25;
    // 0x8000B1C4: sb          $t0, 0x58($sp)
    MEM_B(0X58, ctx->r29) = ctx->r8;
    // 0x8000B1C8: sb          $t1, 0x59($sp)
    MEM_B(0X59, ctx->r29) = ctx->r9;
    // 0x8000B1CC: sh          $zero, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = 0;
    // 0x8000B1D0: sh          $zero, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = 0;
    // 0x8000B1D4: sh          $zero, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = 0;
    // 0x8000B1D8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8000B1DC: jal         0x8000EA54
    // 0x8000B1E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    spawn_object(rdram, ctx);
        goto after_7;
    // 0x8000B1E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x8000B1E4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000B1E8: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8000B1EC: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8000B1F0: sw          $v0, -0x3334($at)
    MEM_W(-0X3334, ctx->r1) = ctx->r2;
    // 0x8000B1F4: addiu       $s1, $s1, -0x49E0
    ctx->r17 = ADD32(ctx->r17, -0X49E0);
    // 0x8000B1F8: addiu       $s0, $s0, -0x4A08
    ctx->r16 = ADD32(ctx->r16, -0X4A08);
L_8000B1FC:
    // 0x8000B1FC: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x8000B200: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000B204: jal         0x8006FB8C
    // 0x8000B208: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    rand_range(rdram, ctx);
        goto after_8;
    // 0x8000B208: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_8:
    // 0x8000B20C: sb          $v0, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r2;
    // 0x8000B210: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000B214: jal         0x8006FB8C
    // 0x8000B218: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    rand_range(rdram, ctx);
        goto after_9;
    // 0x8000B218: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_9:
    // 0x8000B21C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8000B220: sb          $v0, -0x2($s0)
    MEM_B(-0X2, ctx->r16) = ctx->r2;
    // 0x8000B224: bne         $s0, $s1, L_8000B1FC
    if (ctx->r16 != ctx->r17) {
        // 0x8000B228: sb          $zero, -0x1($s0)
        MEM_B(-0X1, ctx->r16) = 0;
            goto L_8000B1FC;
    }
    // 0x8000B228: sb          $zero, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = 0;
    // 0x8000B22C: addiu       $t2, $zero, 0x1B
    ctx->r10 = ADD32(0, 0X1B);
    // 0x8000B230: addiu       $t3, $zero, 0x8A
    ctx->r11 = ADD32(0, 0X8A);
    // 0x8000B234: sb          $t2, 0x58($sp)
    MEM_B(0X58, ctx->r29) = ctx->r10;
    // 0x8000B238: sb          $t3, 0x59($sp)
    MEM_B(0X59, ctx->r29) = ctx->r11;
    // 0x8000B23C: sh          $zero, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = 0;
    // 0x8000B240: sh          $zero, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = 0;
    // 0x8000B244: sh          $zero, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = 0;
    // 0x8000B248: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8000B24C: jal         0x8000EA54
    // 0x8000B250: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    spawn_object(rdram, ctx);
        goto after_10;
    // 0x8000B250: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x8000B254: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8000B258: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000B25C: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x8000B260: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8000B264: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8000B268: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8000B26C: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x8000B270: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x8000B274: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x8000B278: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x8000B27C: lw          $s6, 0x34($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X34);
    // 0x8000B280: lw          $s7, 0x38($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X38);
    // 0x8000B284: sw          $v0, -0x332C($at)
    MEM_W(-0X332C, ctx->r1) = ctx->r2;
    // 0x8000B288: jr          $ra
    // 0x8000B28C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8000B28C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void racerfx_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B290: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000B294: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000B298: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8000B29C: addiu       $s0, $s0, -0x333C
    ctx->r16 = ADD32(ctx->r16, -0X333C);
    // 0x8000B2A0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8000B2A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000B2A8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000B2AC: beq         $a0, $zero, L_8000B2D4
    if (ctx->r4 == 0) {
        // 0x8000B2B0: sw          $s1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r17;
            goto L_8000B2D4;
    }
    // 0x8000B2B0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000B2B4: jal         0x80071380
    // 0x8000B2B8: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x8000B2B8: nop

    after_0:
    // 0x8000B2BC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000B2C0: addiu       $v0, $v0, -0x3344
    ctx->r2 = ADD32(ctx->r2, -0X3344);
    // 0x8000B2C4: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x8000B2C8: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x8000B2CC: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8000B2D0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
L_8000B2D4:
    // 0x8000B2D4: jal         0x8001E2D0
    // 0x8000B2D8: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    get_misc_asset(rdram, ctx);
        goto after_1;
    // 0x8000B2D8: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_1:
    // 0x8000B2DC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8000B2E0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000B2E4: addiu       $s2, $zero, 0x500
    ctx->r18 = ADD32(0, 0X500);
L_8000B2E8:
    // 0x8000B2E8: lw          $a0, 0x78($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X78);
    // 0x8000B2EC: nop

    // 0x8000B2F0: beq         $a0, $zero, L_8000B304
    if (ctx->r4 == 0) {
        // 0x8000B2F4: nop
    
            goto L_8000B304;
    }
    // 0x8000B2F4: nop

    // 0x8000B2F8: jal         0x8007D100
    // 0x8000B2FC: nop

    sprite_free(rdram, ctx);
        goto after_2;
    // 0x8000B2FC: nop

    after_2:
    // 0x8000B300: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
L_8000B304:
    // 0x8000B304: lw          $a0, 0x7C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X7C);
    // 0x8000B308: nop

    // 0x8000B30C: beq         $a0, $zero, L_8000B320
    if (ctx->r4 == 0) {
        // 0x8000B310: nop
    
            goto L_8000B320;
    }
    // 0x8000B310: nop

    // 0x8000B314: jal         0x8007B70C
    // 0x8000B318: nop

    tex_free(rdram, ctx);
        goto after_3;
    // 0x8000B318: nop

    after_3:
    // 0x8000B31C: sw          $zero, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = 0;
L_8000B320:
    // 0x8000B320: addiu       $s1, $s1, 0x80
    ctx->r17 = ADD32(ctx->r17, 0X80);
    // 0x8000B324: bne         $s1, $s2, L_8000B2E8
    if (ctx->r17 != ctx->r18) {
        // 0x8000B328: addiu       $s0, $s0, 0x80
        ctx->r16 = ADD32(ctx->r16, 0X80);
            goto L_8000B2E8;
    }
    // 0x8000B328: addiu       $s0, $s0, 0x80
    ctx->r16 = ADD32(ctx->r16, 0X80);
    // 0x8000B32C: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8000B330: addiu       $s0, $s0, -0x3334
    ctx->r16 = ADD32(ctx->r16, -0X3334);
    // 0x8000B334: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8000B338: nop

    // 0x8000B33C: beq         $a0, $zero, L_8000B34C
    if (ctx->r4 == 0) {
        // 0x8000B340: nop
    
            goto L_8000B34C;
    }
    // 0x8000B340: nop

    // 0x8000B344: jal         0x8000FFB8
    // 0x8000B348: nop

    free_object(rdram, ctx);
        goto after_4;
    // 0x8000B348: nop

    after_4:
L_8000B34C:
    // 0x8000B34C: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x8000B350: addiu       $s1, $s1, -0x332C
    ctx->r17 = ADD32(ctx->r17, -0X332C);
    // 0x8000B354: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8000B358: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x8000B35C: beq         $a0, $zero, L_8000B36C
    if (ctx->r4 == 0) {
        // 0x8000B360: nop
    
            goto L_8000B36C;
    }
    // 0x8000B360: nop

    // 0x8000B364: jal         0x8000FFB8
    // 0x8000B368: nop

    free_object(rdram, ctx);
        goto after_5;
    // 0x8000B368: nop

    after_5:
L_8000B36C:
    // 0x8000B36C: jal         0x8001004C
    // 0x8000B370: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    gParticlePtrList_flush(rdram, ctx);
        goto after_6;
    // 0x8000B370: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    after_6:
    // 0x8000B374: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000B378: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000B37C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000B380: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000B384: jr          $ra
    // 0x8000B388: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8000B388: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8000B38C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B38C: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x8000B390: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x8000B394: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8000B398: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8000B39C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8000B3A0: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x8000B3A4: addiu       $s5, $sp, 0x64
    ctx->r21 = ADD32(ctx->r29, 0X64);
    // 0x8000B3A8: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x8000B3AC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8000B3B0: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8000B3B4: sw          $a1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r5;
    // 0x8000B3B8: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8000B3BC: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x8000B3C0: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8000B3C4: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8000B3C8: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8000B3CC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8000B3D0: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8000B3D4: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x8000B3D8: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8000B3DC: swc1        $f6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
    // 0x8000B3E0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8000B3E4: jal         0x800706D0
    // 0x8000B3E8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    vec3f_rotate_py(rdram, ctx);
        goto after_0;
    // 0x8000B3E8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x8000B3EC: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8000B3F0: lwc1        $f10, 0xC($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8000B3F4: or          $s0, $s6, $zero
    ctx->r16 = ctx->r22 | 0;
    // 0x8000B3F8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8000B3FC: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // 0x8000B400: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8000B404: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x8000B408: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8000B40C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000B410: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000B414: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8000B418: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8000B41C: addiu       $s0, $s0, 0xA
    ctx->r16 = ADD32(ctx->r16, 0XA);
    // 0x8000B420: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x8000B424: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8000B428: sh          $t7, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r15;
    // 0x8000B42C: lwc1        $f6, 0x10($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8000B430: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8000B434: addiu       $s2, $s2, -0x3328
    ctx->r18 = ADD32(ctx->r18, -0X3328);
    // 0x8000B438: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8000B43C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8000B440: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8000B444: nop

    // 0x8000B448: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8000B44C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000B450: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000B454: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8000B458: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8000B45C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000B460: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x8000B464: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8000B468: sh          $t9, -0x8($s0)
    MEM_H(-0X8, ctx->r16) = ctx->r25;
    // 0x8000B46C: lwc1        $f18, 0x14($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8000B470: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8000B474: sh          $s4, -0x4($s0)
    MEM_H(-0X4, ctx->r16) = ctx->r20;
    // 0x8000B478: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8000B47C: sh          $s4, -0x2($s0)
    MEM_H(-0X2, ctx->r16) = ctx->r20;
    // 0x8000B480: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000B484: nop

    // 0x8000B488: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8000B48C: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8000B490: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8000B494: sh          $t7, -0x6($s0)
    MEM_H(-0X6, ctx->r16) = ctx->r15;
    // 0x8000B498: nop

L_8000B49C:
    // 0x8000B49C: lwc1        $f8, 0x0($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8000B4A0: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x8000B4A4: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8000B4A8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000B4AC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8000B4B0: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    // 0x8000B4B4: lwc1        $f16, -0x4($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, -0X4);
    // 0x8000B4B8: swc1        $f22, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f22.u32l;
    // 0x8000B4BC: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x8000B4C0: jal         0x80070560
    // 0x8000B4C4: swc1        $f18, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f18.u32l;
    vec3f_rotate(rdram, ctx);
        goto after_1;
    // 0x8000B4C4: swc1        $f18, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x8000B4C8: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8000B4CC: lwc1        $f6, 0xC($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8000B4D0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000B4D4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8000B4D8: addiu       $s0, $s0, 0xA
    ctx->r16 = ADD32(ctx->r16, 0XA);
    // 0x8000B4DC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8000B4E0: nop

    // 0x8000B4E4: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8000B4E8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000B4EC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000B4F0: nop

    // 0x8000B4F4: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8000B4F8: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x8000B4FC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8000B500: sh          $t9, -0xA($s0)
    MEM_H(-0XA, ctx->r16) = ctx->r25;
    // 0x8000B504: lwc1        $f18, 0x10($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8000B508: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8000B50C: nop

    // 0x8000B510: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8000B514: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8000B518: nop

    // 0x8000B51C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8000B520: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000B524: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000B528: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8000B52C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8000B530: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000B534: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8000B538: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8000B53C: sh          $t7, -0x8($s0)
    MEM_H(-0X8, ctx->r16) = ctx->r15;
    // 0x8000B540: lwc1        $f10, 0x14($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8000B544: lwc1        $f8, 0x6C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8000B548: sh          $s4, -0x4($s0)
    MEM_H(-0X4, ctx->r16) = ctx->r20;
    // 0x8000B54C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8000B550: sh          $s4, -0x2($s0)
    MEM_H(-0X2, ctx->r16) = ctx->r20;
    // 0x8000B554: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000B558: slti        $at, $s1, 0x8
    ctx->r1 = SIGNED(ctx->r17) < 0X8 ? 1 : 0;
    // 0x8000B55C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8000B560: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x8000B564: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8000B568: bne         $at, $zero, L_8000B49C
    if (ctx->r1 != 0) {
        // 0x8000B56C: sh          $t9, -0x6($s0)
        MEM_H(-0X6, ctx->r16) = ctx->r25;
            goto L_8000B49C;
    }
    // 0x8000B56C: sh          $t9, -0x6($s0)
    MEM_H(-0X6, ctx->r16) = ctx->r25;
    // 0x8000B570: lw          $v0, 0xB8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XB8);
    // 0x8000B574: lh          $s1, 0xB6($sp)
    ctx->r17 = MEM_H(ctx->r29, 0XB6);
    // 0x8000B578: lbu         $s6, 0x1($v0)
    ctx->r22 = MEM_BU(ctx->r2, 0X1);
    // 0x8000B57C: lbu         $s2, 0x0($v0)
    ctx->r18 = MEM_BU(ctx->r2, 0X0);
    // 0x8000B580: addiu       $s6, $s6, -0x1
    ctx->r22 = ADD32(ctx->r22, -0X1);
    // 0x8000B584: sll         $t7, $s6, 4
    ctx->r15 = S32(ctx->r22 << 4);
    // 0x8000B588: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x8000B58C: sll         $t6, $s2, 4
    ctx->r14 = S32(ctx->r18 << 4);
    // 0x8000B590: or          $s2, $t6, $zero
    ctx->r18 = ctx->r14 | 0;
    // 0x8000B594: or          $s6, $t7, $zero
    ctx->r22 = ctx->r15 | 0;
    // 0x8000B598: sll         $s3, $t7, 16
    ctx->r19 = S32(ctx->r15 << 16);
    // 0x8000B59C: addiu       $s0, $sp, 0x80
    ctx->r16 = ADD32(ctx->r29, 0X80);
    // 0x8000B5A0: addiu       $s5, $sp, 0xA0
    ctx->r21 = ADD32(ctx->r29, 0XA0);
    // 0x8000B5A4: lui         $s4, 0xFFFF
    ctx->r20 = S32(0XFFFF << 16);
L_8000B5A8:
    // 0x8000B5A8: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x8000B5AC: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8000B5B0: jal         0x80070A70
    // 0x8000B5B4: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    sins_s16(rdram, ctx);
        goto after_2;
    // 0x8000B5B4: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_2:
    // 0x8000B5B8: multu       $v0, $s2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000B5BC: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x8000B5C0: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8000B5C4: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x8000B5C8: mflo        $t9
    ctx->r25 = lo;
    // 0x8000B5CC: sra         $t6, $t9, 16
    ctx->r14 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8000B5D0: addu        $t7, $t6, $s2
    ctx->r15 = ADD32(ctx->r14, ctx->r18);
    // 0x8000B5D4: jal         0x80070A6C
    // 0x8000B5D8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    coss_s16(rdram, ctx);
        goto after_3;
    // 0x8000B5D8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    after_3:
    // 0x8000B5DC: multu       $s6, $v0
    result = U64(U32(ctx->r22)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000B5E0: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8000B5E4: addiu       $s1, $s1, 0x2000
    ctx->r17 = ADD32(ctx->r17, 0X2000);
    // 0x8000B5E8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8000B5EC: sltu        $at, $s0, $s5
    ctx->r1 = ctx->r16 < ctx->r21 ? 1 : 0;
    // 0x8000B5F0: mflo        $t6
    ctx->r14 = lo;
    // 0x8000B5F4: addu        $t7, $s3, $t6
    ctx->r15 = ADD32(ctx->r19, ctx->r14);
    // 0x8000B5F8: and         $t8, $t7, $s4
    ctx->r24 = ctx->r15 & ctx->r20;
    // 0x8000B5FC: sll         $t7, $s1, 16
    ctx->r15 = S32(ctx->r17 << 16);
    // 0x8000B600: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x8000B604: sra         $t9, $t7, 16
    ctx->r25 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8000B608: sw          $t6, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r14;
    // 0x8000B60C: bne         $at, $zero, L_8000B5A8
    if (ctx->r1 != 0) {
        // 0x8000B610: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_8000B5A8;
    }
    // 0x8000B610: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x8000B614: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x8000B618: andi        $t7, $s6, 0xFFFF
    ctx->r15 = ctx->r22 & 0XFFFF;
    // 0x8000B61C: lw          $v0, 0xA4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XA4);
    // 0x8000B620: sh          $t9, 0xB6($sp)
    MEM_H(0XB6, ctx->r29) = ctx->r25;
    // 0x8000B624: or          $t4, $t6, $t7
    ctx->r12 = ctx->r14 | ctx->r15;
    // 0x8000B628: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8000B62C: addiu       $s0, $sp, 0x80
    ctx->r16 = ADD32(ctx->r29, 0X80);
    // 0x8000B630: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x8000B634: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
L_8000B638:
    // 0x8000B638: addiu       $a1, $s1, 0x1
    ctx->r5 = ADD32(ctx->r17, 0X1);
    // 0x8000B63C: andi        $a2, $a1, 0x7
    ctx->r6 = ctx->r5 & 0X7;
    // 0x8000B640: addiu       $t8, $a2, 0x1
    ctx->r24 = ADD32(ctx->r6, 0X1);
    // 0x8000B644: sll         $t9, $a1, 8
    ctx->r25 = S32(ctx->r5 << 8);
    // 0x8000B648: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x8000B64C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8000B650: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8000B654: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8000B658: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x8000B65C: addu        $t8, $a0, $t9
    ctx->r24 = ADD32(ctx->r4, ctx->r25);
    // 0x8000B660: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    // 0x8000B664: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x8000B668: addiu       $a3, $s1, 0x2
    ctx->r7 = ADD32(ctx->r17, 0X2);
    // 0x8000B66C: andi        $t0, $a3, 0x7
    ctx->r8 = ctx->r7 & 0X7;
    // 0x8000B670: addiu       $t9, $t0, 0x1
    ctx->r25 = ADD32(ctx->r8, 0X1);
    // 0x8000B674: sll         $t7, $a3, 8
    ctx->r15 = S32(ctx->r7 << 8);
    // 0x8000B678: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x8000B67C: sw          $t8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r24;
    // 0x8000B680: sw          $t4, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r12;
    // 0x8000B684: sw          $t6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r14;
    // 0x8000B688: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x8000B68C: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x8000B690: addu        $t9, $a0, $t7
    ctx->r25 = ADD32(ctx->r4, ctx->r15);
    // 0x8000B694: sw          $t6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r14;
    // 0x8000B698: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x8000B69C: addiu       $t1, $s1, 0x3
    ctx->r9 = ADD32(ctx->r17, 0X3);
    // 0x8000B6A0: andi        $t2, $t1, 0x7
    ctx->r10 = ctx->r9 & 0X7;
    // 0x8000B6A4: addiu       $t7, $t2, 0x1
    ctx->r15 = ADD32(ctx->r10, 0X1);
    // 0x8000B6A8: sll         $t6, $t1, 8
    ctx->r14 = S32(ctx->r9 << 8);
    // 0x8000B6AC: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x8000B6B0: sw          $t9, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r25;
    // 0x8000B6B4: sw          $t4, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r12;
    // 0x8000B6B8: sw          $t8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r24;
    // 0x8000B6BC: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x8000B6C0: sll         $t6, $t2, 2
    ctx->r14 = S32(ctx->r10 << 2);
    // 0x8000B6C4: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8000B6C8: sw          $t8, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r24;
    // 0x8000B6CC: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8000B6D0: addiu       $v1, $s1, 0x4
    ctx->r3 = ADD32(ctx->r17, 0X4);
    // 0x8000B6D4: andi        $t3, $v1, 0x7
    ctx->r11 = ctx->r3 & 0X7;
    // 0x8000B6D8: addiu       $t6, $t3, 0x1
    ctx->r14 = ADD32(ctx->r11, 0X1);
    // 0x8000B6DC: sll         $t8, $v1, 8
    ctx->r24 = S32(ctx->r3 << 8);
    // 0x8000B6E0: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8000B6E4: sw          $t7, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r15;
    // 0x8000B6E8: sw          $t4, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r12;
    // 0x8000B6EC: sw          $t9, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r25;
    // 0x8000B6F0: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x8000B6F4: sll         $t8, $t3, 2
    ctx->r24 = S32(ctx->r11 << 2);
    // 0x8000B6F8: addu        $t6, $a0, $t8
    ctx->r14 = ADD32(ctx->r4, ctx->r24);
    // 0x8000B6FC: sw          $t9, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r25;
    // 0x8000B700: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8000B704: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x8000B708: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // 0x8000B70C: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x8000B710: bne         $v1, $t5, L_8000B638
    if (ctx->r3 != ctx->r13) {
        // 0x8000B714: sw          $t7, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->r15;
            goto L_8000B638;
    }
    // 0x8000B714: sw          $t7, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r15;
    // 0x8000B718: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8000B71C: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8000B720: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8000B724: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8000B728: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8000B72C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8000B730: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8000B734: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8000B738: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8000B73C: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8000B740: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8000B744: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8000B748: jr          $ra
    // 0x8000B74C: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x8000B74C: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void func_8000B750(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B750: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8000B754: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8000B758: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000B75C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8000B760: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000B764: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x8000B768: bne         $a1, $at, L_8000B788
    if (ctx->r5 != ctx->r1) {
        // 0x8000B76C: sw          $a3, 0x8C($sp)
        MEM_W(0X8C, ctx->r29) = ctx->r7;
            goto L_8000B788;
    }
    // 0x8000B76C: sw          $a3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r7;
    // 0x8000B770: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8000B774: addiu       $v1, $v1, -0x3330
    ctx->r3 = ADD32(ctx->r3, -0X3330);
    // 0x8000B778: lw          $s0, 0x0($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X0);
    // 0x8000B77C: nop

    // 0x8000B780: addiu       $t6, $s0, -0x1
    ctx->r14 = ADD32(ctx->r16, -0X1);
    // 0x8000B784: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_8000B788:
    // 0x8000B788: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8000B78C: addiu       $v1, $v1, -0x3330
    ctx->r3 = ADD32(ctx->r3, -0X3330);
    // 0x8000B790: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8000B794: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x8000B798: bgez        $t7, L_8000B7A4
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8000B79C: nop
    
            goto L_8000B7A4;
    }
    // 0x8000B79C: nop

    // 0x8000B7A0: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_8000B7A4:
    // 0x8000B7A4: bltz        $s0, L_8000BAD0
    if (SIGNED(ctx->r16) < 0) {
        // 0x8000B7A8: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8000BAD0;
    }
    // 0x8000B7A8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8000B7AC: beq         $at, $zero, L_8000BACC
    if (ctx->r1 == 0) {
        // 0x8000B7B0: addiu       $a0, $zero, 0x14
        ctx->r4 = ADD32(0, 0X14);
            goto L_8000BACC;
    }
    // 0x8000B7B0: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x8000B7B4: jal         0x8001E2D0
    // 0x8000B7B8: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x8000B7B8: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
    after_0:
    // 0x8000B7BC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8000B7C0: addiu       $t6, $t6, -0x4A60
    ctx->r14 = ADD32(ctx->r14, -0X4A60);
    // 0x8000B7C4: sll         $t5, $s0, 2
    ctx->r13 = S32(ctx->r16 << 2);
    // 0x8000B7C8: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x8000B7CC: addu        $t2, $t5, $t6
    ctx->r10 = ADD32(ctx->r13, ctx->r14);
    // 0x8000B7D0: lw          $a3, 0x0($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X0);
    // 0x8000B7D4: sll         $t9, $s0, 7
    ctx->r25 = S32(ctx->r16 << 7);
    // 0x8000B7D8: lw          $a2, 0x88($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X88);
    // 0x8000B7DC: addu        $v1, $t9, $v0
    ctx->r3 = ADD32(ctx->r25, ctx->r2);
    // 0x8000B7E0: sll         $t8, $a1, 7
    ctx->r24 = S32(ctx->r5 << 7);
    // 0x8000B7E4: addu        $t4, $t8, $v0
    ctx->r12 = ADD32(ctx->r24, ctx->r2);
    // 0x8000B7E8: beq         $a3, $zero, L_8000BACC
    if (ctx->r7 == 0) {
        // 0x8000B7EC: or          $t3, $v1, $zero
        ctx->r11 = ctx->r3 | 0;
            goto L_8000BACC;
    }
    // 0x8000B7EC: or          $t3, $v1, $zero
    ctx->r11 = ctx->r3 | 0;
    // 0x8000B7F0: beq         $a2, $zero, L_8000B818
    if (ctx->r6 == 0) {
        // 0x8000B7F4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8000B818;
    }
    // 0x8000B7F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000B7F8: beq         $a2, $at, L_8000B820
    if (ctx->r6 == ctx->r1) {
        // 0x8000B7FC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8000B820;
    }
    // 0x8000B7FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000B800: beq         $a2, $at, L_8000B828
    if (ctx->r6 == ctx->r1) {
        // 0x8000B804: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_8000B828;
    }
    // 0x8000B804: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x8000B808: beq         $a2, $at, L_8000B830
    if (ctx->r6 == ctx->r1) {
        // 0x8000B80C: addiu       $v0, $v1, 0x48
        ctx->r2 = ADD32(ctx->r3, 0X48);
            goto L_8000B830;
    }
    // 0x8000B80C: addiu       $v0, $v1, 0x48
    ctx->r2 = ADD32(ctx->r3, 0X48);
    // 0x8000B810: b           L_8000B830
    // 0x8000B814: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000B830;
    // 0x8000B814: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000B818:
    // 0x8000B818: b           L_8000B830
    // 0x8000B81C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8000B830;
    // 0x8000B81C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8000B820:
    // 0x8000B820: b           L_8000B830
    // 0x8000B824: addiu       $v0, $v1, 0x24
    ctx->r2 = ADD32(ctx->r3, 0X24);
        goto L_8000B830;
    // 0x8000B824: addiu       $v0, $v1, 0x24
    ctx->r2 = ADD32(ctx->r3, 0X24);
L_8000B828:
    // 0x8000B828: b           L_8000B830
    // 0x8000B82C: addiu       $v0, $v1, 0x48
    ctx->r2 = ADD32(ctx->r3, 0X48);
        goto L_8000B830;
    // 0x8000B82C: addiu       $v0, $v1, 0x48
    ctx->r2 = ADD32(ctx->r3, 0X48);
L_8000B830:
    // 0x8000B830: beq         $v0, $zero, L_8000BAB8
    if (ctx->r2 == 0) {
        // 0x8000B834: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8000BAB8;
    }
    // 0x8000B834: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000B838: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8000B83C: sb          $a2, -0x4A38($at)
    MEM_B(-0X4A38, ctx->r1) = ctx->r6;
    // 0x8000B840: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000B844: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8000B848: sb          $a1, -0x4A28($at)
    MEM_B(-0X4A28, ctx->r1) = ctx->r5;
    // 0x8000B84C: lbu         $t7, 0x70($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X70);
    // 0x8000B850: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000B854: bne         $t7, $at, L_8000BA18
    if (ctx->r15 != ctx->r1) {
        // 0x8000B858: lw          $a0, 0x80($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X80);
            goto L_8000BA18;
    }
    // 0x8000B858: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x8000B85C: lbu         $t8, 0x72($t3)
    ctx->r24 = MEM_BU(ctx->r11, 0X72);
    // 0x8000B860: sw          $t4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r12;
    // 0x8000B864: sll         $t9, $t8, 28
    ctx->r25 = S32(ctx->r24 << 28);
    // 0x8000B868: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8000B86C: sw          $t3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r11;
    // 0x8000B870: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x8000B874: jal         0x80070A38
    // 0x8000B878: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    coss_f(rdram, ctx);
        goto after_1;
    // 0x8000B878: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_1:
    // 0x8000B87C: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8000B880: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x8000B884: lwc1        $f6, 0x18($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8000B888: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8000B88C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8000B890: lwc1        $f12, 0x74($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0X74);
    // 0x8000B894: lwc1        $f18, 0x20($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8000B898: lwc1        $f16, 0x1C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8000B89C: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8000B8A0: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x8000B8A4: mul.s       $f2, $f10, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8000B8A8: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8000B8AC: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x8000B8B0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000B8B4: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8000B8B8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8000B8BC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8000B8C0: andi        $v1, $a1, 0x3
    ctx->r3 = ctx->r5 & 0X3;
    // 0x8000B8C4: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8000B8C8: addiu       $t1, $t1, -0x4A7C
    ctx->r9 = ADD32(ctx->r9, -0X4A7C);
    // 0x8000B8CC: mul.s       $f14, $f4, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8000B8D0: bne         $v1, $at, L_8000B8F4
    if (ctx->r3 != ctx->r1) {
        // 0x8000B8D4: addiu       $t0, $t0, -0x4A84
        ctx->r8 = ADD32(ctx->r8, -0X4A84);
            goto L_8000B8F4;
    }
    // 0x8000B8D4: addiu       $t0, $t0, -0x4A84
    ctx->r8 = ADD32(ctx->r8, -0X4A84);
    // 0x8000B8D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000B8DC: lwc1        $f0, 0x56C0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X56C0);
    // 0x8000B8E0: nop

    // 0x8000B8E4: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8000B8E8: nop

    // 0x8000B8EC: mul.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8000B8F0: nop

L_8000B8F4:
    // 0x8000B8F4: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8000B8F8: bne         $at, $zero, L_8000B91C
    if (ctx->r1 != 0) {
        // 0x8000B8FC: addiu       $t6, $zero, -0x8000
        ctx->r14 = ADD32(0, -0X8000);
            goto L_8000B91C;
    }
    // 0x8000B8FC: addiu       $t6, $zero, -0x8000
    ctx->r14 = ADD32(0, -0X8000);
    // 0x8000B900: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000B904: lwc1        $f0, 0x56C4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X56C4);
    // 0x8000B908: nop

    // 0x8000B90C: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8000B910: nop

    // 0x8000B914: mul.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8000B918: nop

L_8000B91C:
    // 0x8000B91C: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8000B920: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000B924: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
    // 0x8000B928: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8000B92C: lw          $v1, -0x4A78($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4A78);
    // 0x8000B930: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    // 0x8000B934: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8000B938: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x8000B93C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8000B940: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x8000B944: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000B948: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8000B94C: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x8000B950: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8000B954: lw          $t8, -0x3344($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X3344);
    // 0x8000B958: addu        $t5, $t5, $t9
    ctx->r13 = ADD32(ctx->r13, ctx->r25);
    // 0x8000B95C: sh          $t6, 0x50($sp)
    MEM_H(0X50, ctx->r29) = ctx->r14;
    // 0x8000B960: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x8000B964: sh          $zero, 0x52($sp)
    MEM_H(0X52, ctx->r29) = 0;
    // 0x8000B968: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
    // 0x8000B96C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8000B970: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    // 0x8000B974: swc1        $f18, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
    // 0x8000B978: swc1        $f16, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f16.u32l;
    // 0x8000B97C: addu        $a0, $t8, $t5
    ctx->r4 = ADD32(ctx->r24, ctx->r13);
    // 0x8000B980: lbu         $t8, 0x72($t3)
    ctx->r24 = MEM_BU(ctx->r11, 0X72);
    // 0x8000B984: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x8000B988: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x8000B98C: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x8000B990: sll         $t5, $t8, 12
    ctx->r13 = S32(ctx->r24 << 12);
    // 0x8000B994: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8000B998: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x8000B99C: lw          $t7, 0x7C($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X7C);
    // 0x8000B9A0: lw          $t6, -0x333C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X333C);
    // 0x8000B9A4: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8000B9A8: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x8000B9AC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8000B9B0: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    // 0x8000B9B4: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8000B9B8: jal         0x8000B38C
    // 0x8000B9BC: addu        $a1, $t6, $t9
    ctx->r5 = ADD32(ctx->r14, ctx->r25);
    func_8000B38C(rdram, ctx);
        goto after_2;
    // 0x8000B9BC: addu        $a1, $t6, $t9
    ctx->r5 = ADD32(ctx->r14, ctx->r25);
    after_2:
    // 0x8000B9C0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8000B9C4: addiu       $t0, $t0, -0x4A84
    ctx->r8 = ADD32(ctx->r8, -0X4A84);
    // 0x8000B9C8: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x8000B9CC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8000B9D0: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8000B9D4: addiu       $t1, $t1, -0x4A7C
    ctx->r9 = ADD32(ctx->r9, -0X4A7C);
    // 0x8000B9D8: sll         $t6, $s0, 28
    ctx->r14 = S32(ctx->r16 << 28);
    // 0x8000B9DC: sll         $t8, $t9, 14
    ctx->r24 = S32(ctx->r25 << 14);
    // 0x8000B9E0: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x8000B9E4: or          $t5, $t6, $t8
    ctx->r13 = ctx->r14 | ctx->r24;
    // 0x8000B9E8: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x8000B9EC: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8000B9F0: or          $t9, $t5, $t7
    ctx->r25 = ctx->r13 | ctx->r15;
    // 0x8000B9F4: sw          $t9, 0x7C($t6)
    MEM_W(0X7C, ctx->r14) = ctx->r25;
    // 0x8000B9F8: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x8000B9FC: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x8000BA00: addiu       $t5, $t8, 0x9
    ctx->r13 = ADD32(ctx->r24, 0X9);
    // 0x8000BA04: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x8000BA08: lw          $a3, 0x0($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X0);
    // 0x8000BA0C: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
    // 0x8000BA10: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8000BA14: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
L_8000BA18:
    // 0x8000BA18: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8000BA1C: sw          $a0, 0x78($a3)
    MEM_W(0X78, ctx->r7) = ctx->r4;
    // 0x8000BA20: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x8000BA24: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    // 0x8000BA28: swc1        $f0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f0.u32l;
    // 0x8000BA2C: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x8000BA30: nop

    // 0x8000BA34: swc1        $f0, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->f0.u32l;
    // 0x8000BA38: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x8000BA3C: nop

    // 0x8000BA40: swc1        $f0, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->f0.u32l;
    // 0x8000BA44: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8000BA48: nop

    // 0x8000BA4C: swc1        $f6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f6.u32l;
    // 0x8000BA50: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8000BA54: nop

    // 0x8000BA58: swc1        $f4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f4.u32l;
    // 0x8000BA5C: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8000BA60: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x8000BA64: jal         0x80070560
    // 0x8000BA68: swc1        $f8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f8.u32l;
    vec3f_rotate(rdram, ctx);
        goto after_3;
    // 0x8000BA68: swc1        $f8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x8000BA6C: jal         0x80011560
    // 0x8000BA70: nop

    ignore_bounds_check(rdram, ctx);
        goto after_4;
    // 0x8000BA70: nop

    after_4:
    // 0x8000BA74: lw          $v0, 0x80($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X80);
    // 0x8000BA78: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8000BA7C: lwc1        $f18, 0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8000BA80: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8000BA84: add.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8000BA88: lwc1        $f10, 0x7C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8000BA8C: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8000BA90: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8000BA94: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8000BA98: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8000BA9C: add.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8000BAA0: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x8000BAA4: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8000BAA8: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x8000BAAC: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8000BAB0: jal         0x80011570
    // 0x8000BAB4: nop

    move_object(rdram, ctx);
        goto after_5;
    // 0x8000BAB4: nop

    after_5:
L_8000BAB8:
    // 0x8000BAB8: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
    // 0x8000BABC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000BAC0: beq         $t7, $zero, L_8000BACC
    if (ctx->r15 == 0) {
        // 0x8000BAC4: addu        $at, $at, $s0
        ctx->r1 = ADD32(ctx->r1, ctx->r16);
            goto L_8000BACC;
    }
    // 0x8000BAC4: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8000BAC8: sb          $zero, -0x4A18($at)
    MEM_B(-0X4A18, ctx->r1) = 0;
L_8000BACC:
    // 0x8000BACC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8000BAD0:
    // 0x8000BAD0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8000BAD4: jr          $ra
    // 0x8000BAD8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8000BAD8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void racerfx_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BADC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000BAE0: addiu       $v0, $v0, -0x4A78
    ctx->r2 = ADD32(ctx->r2, -0X4A78);
    // 0x8000BAE4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8000BAE8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8000BAEC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8000BAF0: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x8000BAF4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8000BAF8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000BAFC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8000BB00: sw          $zero, -0x4A84($at)
    MEM_W(-0X4A84, ctx->r1) = 0;
    // 0x8000BB04: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8000BB08: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000BB0C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000BB10: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x8000BB14: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8000BB18: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8000BB1C: sw          $zero, -0x4A7C($at)
    MEM_W(-0X4A7C, ctx->r1) = 0;
    // 0x8000BB20: jal         0x8001E2D0
    // 0x8000BB24: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x8000BB24: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_0:
    // 0x8000BB28: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
    // 0x8000BB2C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000BB30: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000BB34: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000BB38: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x8000BB3C: sw          $t9, -0x3330($at)
    MEM_W(-0X3330, ctx->r1) = ctx->r25;
    // 0x8000BB40: addiu       $a0, $a0, -0x4A60
    ctx->r4 = ADD32(ctx->r4, -0X4A60);
    // 0x8000BB44: addiu       $v1, $v1, -0x4A18
    ctx->r3 = ADD32(ctx->r3, -0X4A18);
    // 0x8000BB48: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8000BB4C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8000BB50:
    // 0x8000BB50: lbu         $t4, 0x0($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X0);
    // 0x8000BB54: sll         $t5, $t0, 2
    ctx->r13 = S32(ctx->r8 << 2);
    // 0x8000BB58: beq         $t4, $zero, L_8000BB74
    if (ctx->r12 == 0) {
        // 0x8000BB5C: addu        $t7, $a0, $t5
        ctx->r15 = ADD32(ctx->r4, ctx->r13);
            goto L_8000BB74;
    }
    // 0x8000BB5C: addu        $t7, $a0, $t5
    ctx->r15 = ADD32(ctx->r4, ctx->r13);
    // 0x8000BB60: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x8000BB64: nop

    // 0x8000BB68: beq         $v0, $zero, L_8000BB74
    if (ctx->r2 == 0) {
        // 0x8000BB6C: nop
    
            goto L_8000BB74;
    }
    // 0x8000BB6C: nop

    // 0x8000BB70: sw          $zero, 0x78($v0)
    MEM_W(0X78, ctx->r2) = 0;
L_8000BB74:
    // 0x8000BB74: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8000BB78: slti        $at, $t0, 0xA
    ctx->r1 = SIGNED(ctx->r8) < 0XA ? 1 : 0;
    // 0x8000BB7C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000BB80: bne         $at, $zero, L_8000BB50
    if (ctx->r1 != 0) {
        // 0x8000BB84: sb          $t2, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r10;
            goto L_8000BB50;
    }
    // 0x8000BB84: sb          $t2, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r10;
    // 0x8000BB88: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8000BB8C: lw          $t6, -0x4B90($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4B90);
    // 0x8000BB90: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8000BB94: blez        $t6, L_8000BF0C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8000BB98: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8000BF0C;
    }
    // 0x8000BB98: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8000BB9C: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8000BBA0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8000BBA4: mtc1        $s1, $f4
    ctx->f4.u32l = ctx->r17;
    // 0x8000BBA8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000BBAC: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8000BBB0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8000BBB4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8000BBB8: addiu       $s3, $s3, -0x4B9C
    ctx->r19 = ADD32(ctx->r19, -0X4B9C);
    // 0x8000BBBC: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8000BBC0: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
L_8000BBC4:
    // 0x8000BBC4: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x8000BBC8: lw          $t8, 0x300($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X300);
    // 0x8000BBCC: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x8000BBD0: bne         $t8, $zero, L_8000BBE8
    if (ctx->r24 != 0) {
        // 0x8000BBD4: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8000BBE8;
    }
    // 0x8000BBD4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000BBD8: lwc1        $f6, 0x56C8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X56C8);
    // 0x8000BBDC: nop

    // 0x8000BBE0: mul.s       $f2, $f16, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x8000BBE4: nop

L_8000BBE8:
    // 0x8000BBE8: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x8000BBEC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8000BBF0: addu        $t4, $t9, $s2
    ctx->r12 = ADD32(ctx->r25, ctx->r18);
    // 0x8000BBF4: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8000BBF8: addiu       $t8, $t8, -0x4A70
    ctx->r24 = ADD32(ctx->r24, -0X4A70);
    // 0x8000BBFC: lw          $s0, 0x64($t5)
    ctx->r16 = MEM_W(ctx->r13, 0X64);
    // 0x8000BC00: nop

    // 0x8000BC04: lb          $a0, 0x2($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X2);
    // 0x8000BC08: lh          $t6, 0x18E($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X18E);
    // 0x8000BC0C: sll         $t7, $a0, 7
    ctx->r15 = S32(ctx->r4 << 7);
    // 0x8000BC10: beq         $t6, $zero, L_8000BC2C
    if (ctx->r14 == 0) {
        // 0x8000BC14: addu        $v0, $t7, $t3
        ctx->r2 = ADD32(ctx->r15, ctx->r11);
            goto L_8000BC2C;
    }
    // 0x8000BC14: addu        $v0, $t7, $t3
    ctx->r2 = ADD32(ctx->r15, ctx->r11);
    // 0x8000BC18: addu        $v1, $a0, $t8
    ctx->r3 = ADD32(ctx->r4, ctx->r24);
    // 0x8000BC1C: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x8000BC20: nop

    // 0x8000BC24: addu        $t4, $t9, $s1
    ctx->r12 = ADD32(ctx->r25, ctx->r17);
    // 0x8000BC28: sb          $t4, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r12;
L_8000BC2C:
    // 0x8000BC2C: lbu         $t5, 0x72($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X72);
    // 0x8000BC30: nop

    // 0x8000BC34: addu        $t7, $t5, $s1
    ctx->r15 = ADD32(ctx->r13, ctx->r17);
    // 0x8000BC38: sb          $t7, 0x72($v0)
    MEM_B(0X72, ctx->r2) = ctx->r15;
    // 0x8000BC3C: lb          $t6, 0x1D3($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D3);
    // 0x8000BC40: nop

    // 0x8000BC44: beq         $t6, $zero, L_8000BD4C
    if (ctx->r14 == 0) {
        // 0x8000BC48: nop
    
            goto L_8000BD4C;
    }
    // 0x8000BC48: nop

    // 0x8000BC4C: lbu         $t9, 0x70($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X70);
    // 0x8000BC50: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x8000BC54: bne         $t9, $zero, L_8000BC9C
    if (ctx->r25 != 0) {
        // 0x8000BC58: sb          $t8, 0x73($v0)
        MEM_B(0X73, ctx->r2) = ctx->r24;
            goto L_8000BC9C;
    }
    // 0x8000BC58: sb          $t8, 0x73($v0)
    MEM_B(0X73, ctx->r2) = ctx->r24;
    // 0x8000BC5C: mul.s       $f10, $f2, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x8000BC60: lwc1        $f8, 0x74($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8000BC64: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000BC68: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8000BC6C: swc1        $f4, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f4.u32l;
    // 0x8000BC70: lwc1        $f6, 0x56CC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X56CC);
    // 0x8000BC74: lwc1        $f0, 0x74($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8000BC78: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x8000BC7C: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8000BC80: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000BC84: bc1f        L_8000BC9C
    if (!c1cs) {
        // 0x8000BC88: nop
    
            goto L_8000BC9C;
    }
    // 0x8000BC88: nop

    // 0x8000BC8C: lwc1        $f8, 0x56D0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X56D0);
    // 0x8000BC90: sb          $t2, 0x70($v0)
    MEM_B(0X70, ctx->r2) = ctx->r10;
    // 0x8000BC94: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8000BC98: swc1        $f10, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f10.u32l;
L_8000BC9C:
    // 0x8000BC9C: lbu         $t4, 0x70($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X70);
    // 0x8000BCA0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000BCA4: bne         $t4, $at, L_8000BCE8
    if (ctx->r12 != ctx->r1) {
        // 0x8000BCA8: nop
    
            goto L_8000BCE8;
    }
    // 0x8000BCA8: nop

    // 0x8000BCAC: mul.s       $f6, $f2, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x8000BCB0: lwc1        $f4, 0x74($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8000BCB4: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x8000BCB8: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8000BCBC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8000BCC0: swc1        $f8, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f8.u32l;
    // 0x8000BCC4: lwc1        $f0, 0x74($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8000BCC8: nop

    // 0x8000BCCC: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x8000BCD0: nop

    // 0x8000BCD4: bc1f        L_8000BCE8
    if (!c1cs) {
        // 0x8000BCD8: nop
    
            goto L_8000BCE8;
    }
    // 0x8000BCD8: nop

    // 0x8000BCDC: sub.s       $f10, $f14, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x8000BCE0: sb          $t5, 0x70($v0)
    MEM_B(0X70, ctx->r2) = ctx->r13;
    // 0x8000BCE4: swc1        $f10, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f10.u32l;
L_8000BCE8:
    // 0x8000BCE8: lbu         $t7, 0x70($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X70);
    // 0x8000BCEC: nop

    // 0x8000BCF0: bne         $t1, $t7, L_8000BD40
    if (ctx->r9 != ctx->r15) {
        // 0x8000BCF4: nop
    
            goto L_8000BD40;
    }
    // 0x8000BCF4: nop

    // 0x8000BCF8: lwc1        $f0, 0x74($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8000BCFC: lui         $at, 0x3E00
    ctx->r1 = S32(0X3E00 << 16);
    // 0x8000BD00: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x8000BD04: nop

    // 0x8000BD08: bc1f        L_8000BD40
    if (!c1cs) {
        // 0x8000BD0C: nop
    
            goto L_8000BD40;
    }
    // 0x8000BD0C: nop

    // 0x8000BD10: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000BD14: nop

    // 0x8000BD18: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8000BD1C: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x8000BD20: swc1        $f8, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f8.u32l;
    // 0x8000BD24: lwc1        $f10, 0x74($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8000BD28: nop

    // 0x8000BD2C: c.lt.s      $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl < ctx->f10.fl;
    // 0x8000BD30: nop

    // 0x8000BD34: bc1f        L_8000BD40
    if (!c1cs) {
        // 0x8000BD38: nop
    
            goto L_8000BD40;
    }
    // 0x8000BD38: nop

    // 0x8000BD3C: swc1        $f14, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f14.u32l;
L_8000BD40:
    // 0x8000BD40: lbu         $v1, 0x70($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X70);
    // 0x8000BD44: b           L_8000BE00
    // 0x8000BD48: nop

        goto L_8000BE00;
    // 0x8000BD48: nop

L_8000BD4C:
    // 0x8000BD4C: lb          $a0, 0x73($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X73);
    // 0x8000BD50: nop

    // 0x8000BD54: blez        $a0, L_8000BD68
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8000BD58: subu        $t6, $a0, $s1
        ctx->r14 = SUB32(ctx->r4, ctx->r17);
            goto L_8000BD68;
    }
    // 0x8000BD58: subu        $t6, $a0, $s1
    ctx->r14 = SUB32(ctx->r4, ctx->r17);
    // 0x8000BD5C: lbu         $v1, 0x70($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X70);
    // 0x8000BD60: b           L_8000BE00
    // 0x8000BD64: sb          $t6, 0x73($v0)
    MEM_B(0X73, ctx->r2) = ctx->r14;
        goto L_8000BE00;
    // 0x8000BD64: sb          $t6, 0x73($v0)
    MEM_B(0X73, ctx->r2) = ctx->r14;
L_8000BD68:
    // 0x8000BD68: lbu         $t8, 0x70($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X70);
    // 0x8000BD6C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000BD70: bne         $t1, $t8, L_8000BDB4
    if (ctx->r9 != ctx->r24) {
        // 0x8000BD74: nop
    
            goto L_8000BDB4;
    }
    // 0x8000BD74: nop

    // 0x8000BD78: lwc1        $f6, 0x56D4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X56D4);
    // 0x8000BD7C: lwc1        $f4, 0x74($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8000BD80: mul.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8000BD84: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x8000BD88: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8000BD8C: swc1        $f10, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f10.u32l;
    // 0x8000BD90: lwc1        $f0, 0x74($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8000BD94: nop

    // 0x8000BD98: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8000BD9C: nop

    // 0x8000BDA0: bc1f        L_8000BDB4
    if (!c1cs) {
        // 0x8000BDA4: nop
    
            goto L_8000BDB4;
    }
    // 0x8000BDA4: nop

    // 0x8000BDA8: add.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x8000BDAC: sb          $zero, 0x70($v0)
    MEM_B(0X70, ctx->r2) = 0;
    // 0x8000BDB0: swc1        $f6, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f6.u32l;
L_8000BDB4:
    // 0x8000BDB4: lbu         $v1, 0x70($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X70);
    // 0x8000BDB8: nop

    // 0x8000BDBC: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8000BDC0: beq         $at, $zero, L_8000BE00
    if (ctx->r1 == 0) {
        // 0x8000BDC4: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8000BE00;
    }
    // 0x8000BDC4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000BDC8: lwc1        $f8, 0x56D8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X56D8);
    // 0x8000BDCC: lwc1        $f4, 0x74($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8000BDD0: mul.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x8000BDD4: andi        $v1, $zero, 0xFF
    ctx->r3 = 0 & 0XFF;
    // 0x8000BDD8: sub.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8000BDDC: swc1        $f6, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f6.u32l;
    // 0x8000BDE0: lwc1        $f8, 0x74($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8000BDE4: nop

    // 0x8000BDE8: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x8000BDEC: nop

    // 0x8000BDF0: bc1f        L_8000BDFC
    if (!c1cs) {
        // 0x8000BDF4: nop
    
            goto L_8000BDFC;
    }
    // 0x8000BDF4: nop

    // 0x8000BDF8: swc1        $f12, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f12.u32l;
L_8000BDFC:
    // 0x8000BDFC: sb          $zero, 0x70($v0)
    MEM_B(0X70, ctx->r2) = 0;
L_8000BE00:
    // 0x8000BE00: bgtz        $v1, L_8000BE20
    if (SIGNED(ctx->r3) > 0) {
        // 0x8000BE04: nop
    
            goto L_8000BE20;
    }
    // 0x8000BE04: nop

    // 0x8000BE08: lwc1        $f4, 0x74($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8000BE0C: nop

    // 0x8000BE10: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x8000BE14: nop

    // 0x8000BE18: bc1f        L_8000BE74
    if (!c1cs) {
        // 0x8000BE1C: nop
    
            goto L_8000BE74;
    }
    // 0x8000BE1C: nop

L_8000BE20:
    // 0x8000BE20: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x8000BE24: lb          $a1, 0x2($s0)
    ctx->r5 = MEM_B(ctx->r16, 0X2);
    // 0x8000BE28: addu        $t4, $t9, $s2
    ctx->r12 = ADD32(ctx->r25, ctx->r18);
    // 0x8000BE2C: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x8000BE30: lb          $a2, 0x1D7($s0)
    ctx->r6 = MEM_B(ctx->r16, 0X1D7);
    // 0x8000BE34: lb          $a3, 0x203($s0)
    ctx->r7 = MEM_B(ctx->r16, 0X203);
    // 0x8000BE38: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x8000BE3C: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    // 0x8000BE40: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x8000BE44: jal         0x8000B750
    // 0x8000BE48: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8000B750(rdram, ctx);
        goto after_1;
    // 0x8000BE48: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x8000BE4C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000BE50: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8000BE54: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8000BE58: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8000BE5C: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x8000BE60: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x8000BE64: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8000BE68: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8000BE6C: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8000BE70: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8000BE74:
    // 0x8000BE74: lb          $v1, 0x2($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X2);
    // 0x8000BE78: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8000BE7C: addiu       $t7, $t7, -0x4A08
    ctx->r15 = ADD32(ctx->r15, -0X4A08);
    // 0x8000BE80: sll         $t5, $v1, 2
    ctx->r13 = S32(ctx->r3 << 2);
    // 0x8000BE84: addu        $v0, $t5, $t7
    ctx->r2 = ADD32(ctx->r13, ctx->r15);
    // 0x8000BE88: lbu         $t6, 0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1);
    // 0x8000BE8C: lbu         $t9, 0x2($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X2);
    // 0x8000BE90: addu        $t8, $t6, $s1
    ctx->r24 = ADD32(ctx->r14, ctx->r17);
    // 0x8000BE94: addu        $t4, $t9, $s1
    ctx->r12 = ADD32(ctx->r25, ctx->r17);
    // 0x8000BE98: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    // 0x8000BE9C: sb          $t4, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r12;
    // 0x8000BEA0: lb          $t5, 0x175($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X175);
    // 0x8000BEA4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8000BEA8: beq         $t5, $zero, L_8000BED8
    if (ctx->r13 == 0) {
        // 0x8000BEAC: nop
    
            goto L_8000BED8;
    }
    // 0x8000BEAC: nop

    // 0x8000BEB0: lbu         $t7, 0x3($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X3);
    // 0x8000BEB4: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x8000BEB8: addu        $v1, $t7, $t6
    ctx->r3 = ADD32(ctx->r15, ctx->r14);
    // 0x8000BEBC: slti        $at, $v1, 0x20
    ctx->r1 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
    // 0x8000BEC0: beq         $at, $zero, L_8000BED0
    if (ctx->r1 == 0) {
        // 0x8000BEC4: addiu       $t8, $zero, 0x20
        ctx->r24 = ADD32(0, 0X20);
            goto L_8000BED0;
    }
    // 0x8000BEC4: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x8000BEC8: b           L_8000BEF8
    // 0x8000BECC: sb          $v1, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r3;
        goto L_8000BEF8;
    // 0x8000BECC: sb          $v1, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r3;
L_8000BED0:
    // 0x8000BED0: b           L_8000BEF8
    // 0x8000BED4: sb          $t8, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r24;
        goto L_8000BEF8;
    // 0x8000BED4: sb          $t8, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r24;
L_8000BED8:
    // 0x8000BED8: lbu         $t9, 0x3($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X3);
    // 0x8000BEDC: nop

    // 0x8000BEE0: subu        $v1, $t9, $s1
    ctx->r3 = SUB32(ctx->r25, ctx->r17);
    // 0x8000BEE4: blez        $v1, L_8000BEF4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8000BEE8: nop
    
            goto L_8000BEF4;
    }
    // 0x8000BEE8: nop

    // 0x8000BEEC: b           L_8000BEF8
    // 0x8000BEF0: sb          $v1, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r3;
        goto L_8000BEF8;
    // 0x8000BEF0: sb          $v1, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r3;
L_8000BEF4:
    // 0x8000BEF4: sb          $zero, 0x3($v0)
    MEM_B(0X3, ctx->r2) = 0;
L_8000BEF8:
    // 0x8000BEF8: lw          $t4, -0x4B90($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4B90);
    // 0x8000BEFC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8000BF00: slt         $at, $t0, $t4
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8000BF04: bne         $at, $zero, L_8000BBC4
    if (ctx->r1 != 0) {
        // 0x8000BF08: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_8000BBC4;
    }
    // 0x8000BF08: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_8000BF0C:
    // 0x8000BF0C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000BF10: lw          $a0, -0x332C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X332C);
    // 0x8000BF14: nop

    // 0x8000BF18: beq         $a0, $zero, L_8000BF2C
    if (ctx->r4 == 0) {
        // 0x8000BF1C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8000BF2C;
    }
    // 0x8000BF1C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8000BF20: jal         0x80011134
    // 0x8000BF24: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    obj_tex_animate(rdram, ctx);
        goto after_2;
    // 0x8000BF24: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x8000BF28: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8000BF2C:
    // 0x8000BF2C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8000BF30: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8000BF34: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x8000BF38: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x8000BF3C: jr          $ra
    // 0x8000BF40: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8000BF40: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void racerfx_get_boost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BF44: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000BF48: bne         $a0, $at, L_8000BF5C
    if (ctx->r4 != ctx->r1) {
        // 0x8000BF4C: nop
    
            goto L_8000BF5C;
    }
    // 0x8000BF4C: nop

    // 0x8000BF50: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000BF54: lw          $a0, -0x3330($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3330);
    // 0x8000BF58: nop

L_8000BF5C:
    // 0x8000BF5C: bltz        $a0, L_8000BF6C
    if (SIGNED(ctx->r4) < 0) {
        // 0x8000BF60: slti        $at, $a0, 0xA
        ctx->r1 = SIGNED(ctx->r4) < 0XA ? 1 : 0;
            goto L_8000BF6C;
    }
    // 0x8000BF60: slti        $at, $a0, 0xA
    ctx->r1 = SIGNED(ctx->r4) < 0XA ? 1 : 0;
    // 0x8000BF64: bne         $at, $zero, L_8000BF74
    if (ctx->r1 != 0) {
        // 0x8000BF68: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_8000BF74;
    }
    // 0x8000BF68: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
L_8000BF6C:
    // 0x8000BF6C: jr          $ra
    // 0x8000BF70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8000BF70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000BF74:
    // 0x8000BF74: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000BF78: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8000BF7C: lw          $v0, -0x4A60($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4A60);
    // 0x8000BF80: nop

    // 0x8000BF84: jr          $ra
    // 0x8000BF88: nop

    return;
    // 0x8000BF88: nop

;}
RECOMP_FUNC void allocate_object_pools(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BF8C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000BF90: lwc1        $f12, 0x56DC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X56DC);
    // 0x8000BF94: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000BF98: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000BF9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000BFA0: lwc1        $f14, 0x56E0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X56E0);
    // 0x8000BFA4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8000BFA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000BFAC: jal         0x8001D28C
    // 0x8000BFB0: addiu       $a3, $zero, -0x2000
    ctx->r7 = ADD32(0, -0X2000);
    set_world_shading(rdram, ctx);
        goto after_0;
    // 0x8000BFB0: addiu       $a3, $zero, -0x2000
    ctx->r7 = ADD32(0, -0X2000);
    after_0:
    // 0x8000BFB4: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    // 0x8000BFB8: ori         $a0, $a0, 0x5800
    ctx->r4 = ctx->r4 | 0X5800;
    // 0x8000BFBC: jal         0x80070DB8
    // 0x8000BFC0: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    mempool_new_sub(rdram, ctx);
        goto after_1;
    // 0x8000BFC0: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    after_1:
    // 0x8000BFC4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000BFC8: sw          $v0, -0x4C18($at)
    MEM_W(-0X4C18, ctx->r1) = ctx->r2;
    // 0x8000BFCC: addiu       $a0, $zero, 0x320
    ctx->r4 = ADD32(0, 0X320);
    // 0x8000BFD0: jal         0x80070EDC
    // 0x8000BFD4: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_2;
    // 0x8000BFD4: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_2:
    // 0x8000BFD8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000BFDC: sw          $v0, -0x4BBC($at)
    MEM_W(-0X4BBC, ctx->r1) = ctx->r2;
    // 0x8000BFE0: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    // 0x8000BFE4: jal         0x80070EDC
    // 0x8000BFE8: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_3;
    // 0x8000BFE8: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_3:
    // 0x8000BFEC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000BFF0: sw          $v0, -0x4C14($at)
    MEM_W(-0X4C14, ctx->r1) = ctx->r2;
    // 0x8000BFF4: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    // 0x8000BFF8: jal         0x80070EDC
    // 0x8000BFFC: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_4;
    // 0x8000BFFC: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_4:
    // 0x8000C000: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C004: sw          $v0, -0x4C0C($at)
    MEM_W(-0X4C0C, ctx->r1) = ctx->r2;
    // 0x8000C008: addiu       $a0, $zero, 0xE10
    ctx->r4 = ADD32(0, 0XE10);
    // 0x8000C00C: jal         0x80070EDC
    // 0x8000C010: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_5;
    // 0x8000C010: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_5:
    // 0x8000C014: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C018: sw          $v0, -0x4BB4($at)
    MEM_W(-0X4BB4, ctx->r1) = ctx->r2;
    // 0x8000C01C: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    // 0x8000C020: jal         0x80070EDC
    // 0x8000C024: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_6;
    // 0x8000C024: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_6:
    // 0x8000C028: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C02C: sw          $v0, -0x4BA4($at)
    MEM_W(-0X4BA4, ctx->r1) = ctx->r2;
    // 0x8000C030: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x8000C034: jal         0x80070EDC
    // 0x8000C038: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_7;
    // 0x8000C038: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_7:
    // 0x8000C03C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C040: sw          $v0, -0x4B9C($at)
    MEM_W(-0X4B9C, ctx->r1) = ctx->r2;
    // 0x8000C044: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x8000C048: jal         0x80070EDC
    // 0x8000C04C: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_8;
    // 0x8000C04C: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_8:
    // 0x8000C050: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C054: sw          $v0, -0x4B94($at)
    MEM_W(-0X4B94, ctx->r1) = ctx->r2;
    // 0x8000C058: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x8000C05C: jal         0x80070EDC
    // 0x8000C060: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_9;
    // 0x8000C060: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_9:
    // 0x8000C064: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C068: sw          $v0, -0x4B98($at)
    MEM_W(-0X4B98, ctx->r1) = ctx->r2;
    // 0x8000C06C: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    // 0x8000C070: jal         0x80070EDC
    // 0x8000C074: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_10;
    // 0x8000C074: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_10:
    // 0x8000C078: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C07C: sw          $v0, -0x4B7C($at)
    MEM_W(-0X4B7C, ctx->r1) = ctx->r2;
    // 0x8000C080: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8000C084: jal         0x80070EDC
    // 0x8000C088: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_11;
    // 0x8000C088: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_11:
    // 0x8000C08C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C090: sw          $v0, -0x4CB4($at)
    MEM_W(-0X4CB4, ctx->r1) = ctx->r2;
    // 0x8000C094: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    // 0x8000C098: jal         0x80070EDC
    // 0x8000C09C: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_12;
    // 0x8000C09C: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_12:
    // 0x8000C0A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C0A4: sw          $v0, -0x4A8C($at)
    MEM_W(-0X4A8C, ctx->r1) = ctx->r2;
    // 0x8000C0A8: jal         0x80076EE4
    // 0x8000C0AC: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    asset_table_load(rdram, ctx);
        goto after_13;
    // 0x8000C0AC: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    after_13:
    // 0x8000C0B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C0B4: sw          $v0, -0x4BC8($at)
    MEM_W(-0X4BC8, ctx->r1) = ctx->r2;
    // 0x8000C0B8: jal         0x800772DC
    // 0x8000C0BC: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    asset_table_size(rdram, ctx);
        goto after_14;
    // 0x8000C0BC: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    after_14:
    // 0x8000C0C0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000C0C4: sra         $t6, $v0, 1
    ctx->r14 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8000C0C8: addiu       $v1, $t6, -0x1
    ctx->r3 = ADD32(ctx->r14, -0X1);
    // 0x8000C0CC: addiu       $a0, $a0, -0x4BC4
    ctx->r4 = ADD32(ctx->r4, -0X4BC4);
    // 0x8000C0D0: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x8000C0D4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000C0D8: lw          $a1, -0x4BC8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4BC8);
    // 0x8000C0DC: sll         $t8, $v1, 1
    ctx->r24 = S32(ctx->r3 << 1);
    // 0x8000C0E0: addu        $t9, $a1, $t8
    ctx->r25 = ADD32(ctx->r5, ctx->r24);
    // 0x8000C0E4: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x8000C0E8: nop

    // 0x8000C0EC: bne         $t0, $zero, L_8000C110
    if (ctx->r8 != 0) {
        // 0x8000C0F0: addiu       $t1, $v1, -0x1
        ctx->r9 = ADD32(ctx->r3, -0X1);
            goto L_8000C110;
    }
    // 0x8000C0F0: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
L_8000C0F4:
    // 0x8000C0F4: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x8000C0F8: addu        $t3, $a1, $t2
    ctx->r11 = ADD32(ctx->r5, ctx->r10);
    // 0x8000C0FC: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8000C100: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x8000C104: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x8000C108: beq         $t4, $zero, L_8000C0F4
    if (ctx->r12 == 0) {
        // 0x8000C10C: addiu       $t1, $v1, -0x1
        ctx->r9 = ADD32(ctx->r3, -0X1);
            goto L_8000C0F4;
    }
    // 0x8000C10C: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
L_8000C110:
    // 0x8000C110: addiu       $a0, $zero, 0x800
    ctx->r4 = ADD32(0, 0X800);
    // 0x8000C114: jal         0x80070EDC
    // 0x8000C118: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_15;
    // 0x8000C118: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_15:
    // 0x8000C11C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C120: sw          $v0, -0x4D28($at)
    MEM_W(-0X4D28, ctx->r1) = ctx->r2;
    // 0x8000C124: jal         0x80076EE4
    // 0x8000C128: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    asset_table_load(rdram, ctx);
        goto after_16;
    // 0x8000C128: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    after_16:
    // 0x8000C12C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000C130: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8000C134: addiu       $a2, $a2, -0x4D18
    ctx->r6 = ADD32(ctx->r6, -0X4D18);
    // 0x8000C138: addiu       $a1, $a1, -0x4D1C
    ctx->r5 = ADD32(ctx->r5, -0X4D1C);
    // 0x8000C13C: sll         $t5, $zero, 2
    ctx->r13 = S32(0 << 2);
    // 0x8000C140: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8000C144: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x8000C148: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x8000C14C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8000C150: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x8000C154: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8000C158: beq         $a3, $t7, L_8000C180
    if (ctx->r7 == ctx->r15) {
        // 0x8000C15C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8000C180;
    }
    // 0x8000C15C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8000C160: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
L_8000C164:
    // 0x8000C164: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8000C168: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x8000C16C: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8000C170: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8000C174: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x8000C178: bne         $a3, $t1, L_8000C164
    if (ctx->r7 != ctx->r9) {
        // 0x8000C17C: addiu       $t8, $v1, 0x1
        ctx->r24 = ADD32(ctx->r3, 0X1);
            goto L_8000C164;
    }
    // 0x8000C17C: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
L_8000C180:
    // 0x8000C180: addiu       $t2, $v1, -0x1
    ctx->r10 = ADD32(ctx->r3, -0X1);
    // 0x8000C184: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
    // 0x8000C188: sll         $a0, $t2, 2
    ctx->r4 = S32(ctx->r10 << 2);
    // 0x8000C18C: jal         0x80070EDC
    // 0x8000C190: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    mempool_alloc_safe(rdram, ctx);
        goto after_17;
    // 0x8000C190: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_17:
    // 0x8000C194: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8000C198: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C19C: sw          $v0, -0x4C38($at)
    MEM_W(-0X4C38, ctx->r1) = ctx->r2;
    // 0x8000C1A0: addiu       $a2, $a2, -0x4D18
    ctx->r6 = ADD32(ctx->r6, -0X4D18);
    // 0x8000C1A4: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x8000C1A8: jal         0x80070EDC
    // 0x8000C1AC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    mempool_alloc_safe(rdram, ctx);
        goto after_18;
    // 0x8000C1AC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_18:
    // 0x8000C1B0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8000C1B4: addiu       $a2, $a2, -0x4D18
    ctx->r6 = ADD32(ctx->r6, -0X4D18);
    // 0x8000C1B8: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x8000C1BC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000C1C0: addiu       $a0, $a0, -0x4C34
    ctx->r4 = ADD32(ctx->r4, -0X4C34);
    // 0x8000C1C4: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8000C1C8: blez        $t4, L_8000C1F4
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8000C1CC: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8000C1F4;
    }
    // 0x8000C1CC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8000C1D0:
    // 0x8000C1D0: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8000C1D4: nop

    // 0x8000C1D8: addu        $t6, $t5, $v1
    ctx->r14 = ADD32(ctx->r13, ctx->r3);
    // 0x8000C1DC: sb          $zero, 0x0($t6)
    MEM_B(0X0, ctx->r14) = 0;
    // 0x8000C1E0: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x8000C1E4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000C1E8: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8000C1EC: bne         $at, $zero, L_8000C1D0
    if (ctx->r1 != 0) {
        // 0x8000C1F0: nop
    
            goto L_8000C1D0;
    }
    // 0x8000C1F0: nop

L_8000C1F4:
    // 0x8000C1F4: jal         0x80076EE4
    // 0x8000C1F8: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    asset_table_load(rdram, ctx);
        goto after_19;
    // 0x8000C1F8: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_19:
    // 0x8000C1FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C200: sw          $v0, -0x4D14($at)
    MEM_W(-0X4D14, ctx->r1) = ctx->r2;
    // 0x8000C204: jal         0x80076EE4
    // 0x8000C208: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    asset_table_load(rdram, ctx);
        goto after_20;
    // 0x8000C208: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_20:
    // 0x8000C20C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000C210: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000C214: addiu       $a1, $a1, -0x4D10
    ctx->r5 = ADD32(ctx->r5, -0X4D10);
    // 0x8000C218: addiu       $a0, $a0, -0x4CE0
    ctx->r4 = ADD32(ctx->r4, -0X4CE0);
    // 0x8000C21C: sll         $t8, $zero, 2
    ctx->r24 = S32(0 << 2);
    // 0x8000C220: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8000C224: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8000C228: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8000C22C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8000C230: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x8000C234: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8000C238: beq         $a3, $t0, L_8000C260
    if (ctx->r7 == ctx->r8) {
        // 0x8000C23C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8000C260;
    }
    // 0x8000C23C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8000C240: addiu       $t1, $v1, 0x1
    ctx->r9 = ADD32(ctx->r3, 0X1);
L_8000C244:
    // 0x8000C244: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8000C248: addu        $t3, $a2, $t2
    ctx->r11 = ADD32(ctx->r6, ctx->r10);
    // 0x8000C24C: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8000C250: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8000C254: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x8000C258: bne         $a3, $t4, L_8000C244
    if (ctx->r7 != ctx->r12) {
        // 0x8000C25C: addiu       $t1, $v1, 0x1
        ctx->r9 = ADD32(ctx->r3, 0X1);
            goto L_8000C244;
    }
    // 0x8000C25C: addiu       $t1, $v1, 0x1
    ctx->r9 = ADD32(ctx->r3, 0X1);
L_8000C260:
    // 0x8000C260: lw          $v0, 0x104($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X104);
    // 0x8000C264: lw          $t7, 0x108($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X108);
    // 0x8000C268: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8000C26C: lw          $t6, -0x4D14($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4D14);
    // 0x8000C270: subu        $a1, $t7, $v0
    ctx->r5 = SUB32(ctx->r15, ctx->r2);
    // 0x8000C274: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8000C278: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x8000C27C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x8000C280: jal         0x8000C2D8
    // 0x8000C284: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    decrypt_magic_codes(rdram, ctx);
        goto after_21;
    // 0x8000C284: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    after_21:
    // 0x8000C288: addiu       $a0, $zero, 0x800
    ctx->r4 = ADD32(0, 0X800);
    // 0x8000C28C: jal         0x80070EDC
    // 0x8000C290: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_22;
    // 0x8000C290: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_22:
    // 0x8000C294: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C298: sw          $v0, -0x4C28($at)
    MEM_W(-0X4C28, ctx->r1) = ctx->r2;
    // 0x8000C29C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C2A0: sb          $zero, -0x4CBC($at)
    MEM_B(-0X4CBC, ctx->r1) = 0;
    // 0x8000C2A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C2A8: sb          $zero, -0x4B8C($at)
    MEM_B(-0X4B8C, ctx->r1) = 0;
    // 0x8000C2AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C2B0: sb          $zero, -0x4B8B($at)
    MEM_B(-0X4B8B, ctx->r1) = 0;
    // 0x8000C2B4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8000C2B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000C2BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C2C0: jal         0x8000C460
    // 0x8000C2C4: swc1        $f4, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->f4.u32l;
    clear_object_pointers(rdram, ctx);
        goto after_23;
    // 0x8000C2C4: swc1        $f4, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->f4.u32l;
    after_23:
    // 0x8000C2C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000C2CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000C2D0: jr          $ra
    // 0x8000C2D4: nop

    return;
    // 0x8000C2D4: nop

;}
RECOMP_FUNC void decrypt_magic_codes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C2D8: sra         $a2, $a1, 2
    ctx->r6 = S32(SIGNED(ctx->r5) >> 2);
    // 0x8000C2DC: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8000C2E0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8000C2E4: blez        $a2, L_8000C458
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8000C2E8: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8000C458;
    }
    // 0x8000C2E8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8000C2EC:
    // 0x8000C2EC: lbu         $t6, 0x3($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X3);
    // 0x8000C2F0: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x8000C2F4: andi        $t7, $t6, 0xC0
    ctx->r15 = ctx->r14 & 0XC0;
    // 0x8000C2F8: lbu         $t3, 0x1($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X1);
    // 0x8000C2FC: sra         $t8, $t7, 6
    ctx->r24 = S32(SIGNED(ctx->r15) >> 6);
    // 0x8000C300: lbu         $t7, 0x2($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X2);
    // 0x8000C304: andi        $t1, $t9, 0xC0
    ctx->r9 = ctx->r25 & 0XC0;
    // 0x8000C308: or          $t2, $t8, $t1
    ctx->r10 = ctx->r24 | ctx->r9;
    // 0x8000C30C: andi        $t4, $t3, 0xC0
    ctx->r12 = ctx->r11 & 0XC0;
    // 0x8000C310: sra         $t5, $t4, 2
    ctx->r13 = S32(SIGNED(ctx->r12) >> 2);
    // 0x8000C314: andi        $t9, $t7, 0xC0
    ctx->r25 = ctx->r15 & 0XC0;
    // 0x8000C318: sra         $t8, $t9, 4
    ctx->r24 = S32(SIGNED(ctx->r25) >> 4);
    // 0x8000C31C: or          $t6, $t2, $t5
    ctx->r14 = ctx->r10 | ctx->r13;
    // 0x8000C320: or          $t1, $t6, $t8
    ctx->r9 = ctx->r14 | ctx->r24;
    // 0x8000C324: sb          $t1, 0x0($sp)
    MEM_B(0X0, ctx->r29) = ctx->r9;
    // 0x8000C328: lbu         $t3, 0x3($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X3);
    // 0x8000C32C: lbu         $t5, 0x0($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X0);
    // 0x8000C330: andi        $t4, $t3, 0x30
    ctx->r12 = ctx->r11 & 0X30;
    // 0x8000C334: sra         $t2, $t4, 4
    ctx->r10 = S32(SIGNED(ctx->r12) >> 4);
    // 0x8000C338: lbu         $t4, 0x2($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X2);
    // 0x8000C33C: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x8000C340: andi        $t7, $t5, 0x30
    ctx->r15 = ctx->r13 & 0X30;
    // 0x8000C344: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8000C348: or          $t6, $t2, $t9
    ctx->r14 = ctx->r10 | ctx->r25;
    // 0x8000C34C: andi        $t5, $t4, 0x30
    ctx->r13 = ctx->r12 & 0X30;
    // 0x8000C350: andi        $t1, $t8, 0x30
    ctx->r9 = ctx->r24 & 0X30;
    // 0x8000C354: or          $t3, $t6, $t1
    ctx->r11 = ctx->r14 | ctx->r9;
    // 0x8000C358: sra         $t7, $t5, 2
    ctx->r15 = S32(SIGNED(ctx->r13) >> 2);
    // 0x8000C35C: or          $t2, $t3, $t7
    ctx->r10 = ctx->r11 | ctx->r15;
    // 0x8000C360: sb          $t2, 0x1($sp)
    MEM_B(0X1, ctx->r29) = ctx->r10;
    // 0x8000C364: lbu         $t1, 0x0($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X0);
    // 0x8000C368: lbu         $t9, 0x3($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X3);
    // 0x8000C36C: lbu         $t7, 0x1($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X1);
    // 0x8000C370: andi        $t4, $t1, 0xC
    ctx->r12 = ctx->r9 & 0XC;
    // 0x8000C374: andi        $t8, $t9, 0xC
    ctx->r24 = ctx->r25 & 0XC;
    // 0x8000C378: lbu         $t1, 0x2($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X2);
    // 0x8000C37C: sra         $t6, $t8, 2
    ctx->r14 = S32(SIGNED(ctx->r24) >> 2);
    // 0x8000C380: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x8000C384: andi        $t2, $t7, 0xC
    ctx->r10 = ctx->r15 & 0XC;
    // 0x8000C388: sll         $t9, $t2, 2
    ctx->r25 = S32(ctx->r10 << 2);
    // 0x8000C38C: or          $t3, $t6, $t5
    ctx->r11 = ctx->r14 | ctx->r13;
    // 0x8000C390: or          $t8, $t3, $t9
    ctx->r24 = ctx->r11 | ctx->r25;
    // 0x8000C394: andi        $t4, $t1, 0xC
    ctx->r12 = ctx->r9 & 0XC;
    // 0x8000C398: or          $t6, $t8, $t4
    ctx->r14 = ctx->r24 | ctx->r12;
    // 0x8000C39C: sb          $t6, 0x2($sp)
    MEM_B(0X2, ctx->r29) = ctx->r14;
    // 0x8000C3A0: lbu         $t5, 0x3($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X3);
    // 0x8000C3A4: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x8000C3A8: lbu         $t3, 0x0($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X0);
    // 0x8000C3AC: andi        $t7, $t5, 0x3
    ctx->r15 = ctx->r13 & 0X3;
    // 0x8000C3B0: andi        $t4, $t8, 0x3
    ctx->r12 = ctx->r24 & 0X3;
    // 0x8000C3B4: sll         $t9, $t3, 6
    ctx->r25 = S32(ctx->r11 << 6);
    // 0x8000C3B8: lbu         $t2, 0x2($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X2);
    // 0x8000C3BC: lbu         $a0, 0x0($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X0);
    // 0x8000C3C0: or          $t1, $t7, $t9
    ctx->r9 = ctx->r15 | ctx->r25;
    // 0x8000C3C4: sll         $t6, $t4, 4
    ctx->r14 = S32(ctx->r12 << 4);
    // 0x8000C3C8: or          $t5, $t1, $t6
    ctx->r13 = ctx->r9 | ctx->r14;
    // 0x8000C3CC: andi        $t3, $t2, 0x3
    ctx->r11 = ctx->r10 & 0X3;
    // 0x8000C3D0: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x8000C3D4: andi        $t1, $a0, 0xAA
    ctx->r9 = ctx->r4 & 0XAA;
    // 0x8000C3D8: andi        $t8, $a0, 0x55
    ctx->r24 = ctx->r4 & 0X55;
    // 0x8000C3DC: or          $t9, $t5, $t7
    ctx->r25 = ctx->r13 | ctx->r15;
    // 0x8000C3E0: sll         $t4, $t8, 1
    ctx->r12 = S32(ctx->r24 << 1);
    // 0x8000C3E4: sra         $t6, $t1, 1
    ctx->r14 = S32(SIGNED(ctx->r9) >> 1);
    // 0x8000C3E8: sb          $t9, 0x3($sp)
    MEM_B(0X3, ctx->r29) = ctx->r25;
    // 0x8000C3EC: or          $t2, $t4, $t6
    ctx->r10 = ctx->r12 | ctx->r14;
    // 0x8000C3F0: sb          $t2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r10;
    // 0x8000C3F4: lbu         $a1, 0x1($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X1);
    // 0x8000C3F8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000C3FC: andi        $t3, $a1, 0x55
    ctx->r11 = ctx->r5 & 0X55;
    // 0x8000C400: andi        $t7, $a1, 0xAA
    ctx->r15 = ctx->r5 & 0XAA;
    // 0x8000C404: sra         $t9, $t7, 1
    ctx->r25 = S32(SIGNED(ctx->r15) >> 1);
    // 0x8000C408: sll         $t5, $t3, 1
    ctx->r13 = S32(ctx->r11 << 1);
    // 0x8000C40C: or          $t8, $t5, $t9
    ctx->r24 = ctx->r13 | ctx->r25;
    // 0x8000C410: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    // 0x8000C414: lbu         $a3, 0x2($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X2);
    // 0x8000C418: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8000C41C: andi        $t1, $a3, 0x55
    ctx->r9 = ctx->r7 & 0X55;
    // 0x8000C420: andi        $t6, $a3, 0xAA
    ctx->r14 = ctx->r7 & 0XAA;
    // 0x8000C424: sra         $t2, $t6, 1
    ctx->r10 = S32(SIGNED(ctx->r14) >> 1);
    // 0x8000C428: sll         $t4, $t1, 1
    ctx->r12 = S32(ctx->r9 << 1);
    // 0x8000C42C: or          $t3, $t4, $t2
    ctx->r11 = ctx->r12 | ctx->r10;
    // 0x8000C430: sb          $t3, -0x2($v0)
    MEM_B(-0X2, ctx->r2) = ctx->r11;
    // 0x8000C434: lbu         $t0, 0x3($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X3);
    // 0x8000C438: nop

    // 0x8000C43C: andi        $t7, $t0, 0x55
    ctx->r15 = ctx->r8 & 0X55;
    // 0x8000C440: andi        $t9, $t0, 0xAA
    ctx->r25 = ctx->r8 & 0XAA;
    // 0x8000C444: sra         $t8, $t9, 1
    ctx->r24 = S32(SIGNED(ctx->r25) >> 1);
    // 0x8000C448: sll         $t5, $t7, 1
    ctx->r13 = S32(ctx->r15 << 1);
    // 0x8000C44C: or          $t1, $t5, $t8
    ctx->r9 = ctx->r13 | ctx->r24;
    // 0x8000C450: bne         $v1, $a2, L_8000C2EC
    if (ctx->r3 != ctx->r6) {
        // 0x8000C454: sb          $t1, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = ctx->r9;
            goto L_8000C2EC;
    }
    // 0x8000C454: sb          $t1, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r9;
L_8000C458:
    // 0x8000C458: jr          $ra
    // 0x8000C45C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8000C45C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void clear_object_pointers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C460: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000C464: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C468: sb          $v0, -0x4D5A($at)
    MEM_B(-0X4D5A, ctx->r1) = ctx->r2;
    // 0x8000C46C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C470: sw          $zero, -0x4D24($at)
    MEM_W(-0X4D24, ctx->r1) = 0;
    // 0x8000C474: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C478: sw          $zero, -0x4D20($at)
    MEM_W(-0X4D20, ctx->r1) = 0;
    // 0x8000C47C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C480: sw          $zero, -0x4BB8($at)
    MEM_W(-0X4BB8, ctx->r1) = 0;
    // 0x8000C484: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C488: sw          $zero, -0x4C10($at)
    MEM_W(-0X4C10, ctx->r1) = 0;
    // 0x8000C48C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C490: sw          $zero, -0x4BB0($at)
    MEM_W(-0X4BB0, ctx->r1) = 0;
    // 0x8000C494: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C498: sw          $zero, -0x4BAC($at)
    MEM_W(-0X4BAC, ctx->r1) = 0;
    // 0x8000C49C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C4A0: sw          $zero, -0x4B90($at)
    MEM_W(-0X4B90, ctx->r1) = 0;
    // 0x8000C4A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C4A8: sh          $zero, -0x4C08($at)
    MEM_H(-0X4C08, ctx->r1) = 0;
    // 0x8000C4AC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000C4B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C4B4: addiu       $a1, $a1, -0x4D5E
    ctx->r5 = ADD32(ctx->r5, -0X4D5E);
    // 0x8000C4B8: sb          $zero, -0x4D5F($at)
    MEM_B(-0X4D5F, ctx->r1) = 0;
    // 0x8000C4BC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000C4C0: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x8000C4C4: sb          $zero, 0x1($a1)
    MEM_B(0X1, ctx->r5) = 0;
    // 0x8000C4C8: addiu       $v1, $v1, -0x4B7C
    ctx->r3 = ADD32(ctx->r3, -0X4B7C);
    // 0x8000C4CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8000C4D0:
    // 0x8000C4D0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8000C4D4: nop

    // 0x8000C4D8: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x8000C4DC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8000C4E0: slti        $at, $a0, 0x200
    ctx->r1 = SIGNED(ctx->r4) < 0X200 ? 1 : 0;
    // 0x8000C4E4: bne         $at, $zero, L_8000C4D0
    if (ctx->r1 != 0) {
        // 0x8000C4E8: sw          $zero, 0x0($t7)
        MEM_W(0X0, ctx->r15) = 0;
            goto L_8000C4D0;
    }
    // 0x8000C4E8: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x8000C4EC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000C4F0: addiu       $a0, $a0, -0x4CB4
    ctx->r4 = ADD32(ctx->r4, -0X4CB4);
    // 0x8000C4F4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8000C4F8:
    // 0x8000C4F8: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8000C4FC: nop

    // 0x8000C500: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x8000C504: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000C508: slti        $at, $v1, 0x8
    ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    // 0x8000C50C: bne         $at, $zero, L_8000C4F8
    if (ctx->r1 != 0) {
        // 0x8000C510: sb          $zero, 0x0($t9)
        MEM_B(0X0, ctx->r25) = 0;
            goto L_8000C4F8;
    }
    // 0x8000C510: sb          $zero, 0x0($t9)
    MEM_B(0X0, ctx->r25) = 0;
    // 0x8000C514: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000C518: addiu       $v1, $v1, -0x4A8C
    ctx->r3 = ADD32(ctx->r3, -0X4A8C);
    // 0x8000C51C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000C520: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
L_8000C524:
    // 0x8000C524: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x8000C528: nop

    // 0x8000C52C: addu        $t1, $t0, $a0
    ctx->r9 = ADD32(ctx->r8, ctx->r4);
    // 0x8000C530: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x8000C534: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8000C538: nop

    // 0x8000C53C: addu        $t3, $t2, $a0
    ctx->r11 = ADD32(ctx->r10, ctx->r4);
    // 0x8000C540: sw          $zero, 0x40($t3)
    MEM_W(0X40, ctx->r11) = 0;
    // 0x8000C544: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8000C548: nop

    // 0x8000C54C: addu        $t5, $t4, $a0
    ctx->r13 = ADD32(ctx->r12, ctx->r4);
    // 0x8000C550: sw          $zero, 0x80($t5)
    MEM_W(0X80, ctx->r13) = 0;
    // 0x8000C554: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8000C558: nop

    // 0x8000C55C: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x8000C560: addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    // 0x8000C564: bne         $a0, $a1, L_8000C524
    if (ctx->r4 != ctx->r5) {
        // 0x8000C568: sw          $zero, 0xC0($t7)
        MEM_W(0XC0, ctx->r15) = 0;
            goto L_8000C524;
    }
    // 0x8000C568: sw          $zero, 0xC0($t7)
    MEM_W(0XC0, ctx->r15) = 0;
    // 0x8000C56C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000C570: addiu       $v1, $v1, -0x4B78
    ctx->r3 = ADD32(ctx->r3, -0X4B78);
    // 0x8000C574: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8000C578: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8000C57C: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x8000C580: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C584: sw          $zero, -0x4C24($at)
    MEM_W(-0X4C24, ctx->r1) = 0;
    // 0x8000C588: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C58C: sw          $zero, -0x4C20($at)
    MEM_W(-0X4C20, ctx->r1) = 0;
    // 0x8000C590: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C594: sw          $zero, -0x4C1C($at)
    MEM_W(-0X4C1C, ctx->r1) = 0;
    // 0x8000C598: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C59C: sw          $zero, -0x4BF8($at)
    MEM_W(-0X4BF8, ctx->r1) = 0;
    // 0x8000C5A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C5A4: sb          $zero, -0x4CAC($at)
    MEM_B(-0X4CAC, ctx->r1) = 0;
    // 0x8000C5A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C5AC: sh          $zero, -0x4C06($at)
    MEM_H(-0X4C06, ctx->r1) = 0;
    // 0x8000C5B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C5B4: sb          $v0, -0x4C02($at)
    MEM_B(-0X4C02, ctx->r1) = ctx->r2;
    // 0x8000C5B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C5BC: sh          $zero, -0x4C04($at)
    MEM_H(-0X4C04, ctx->r1) = 0;
    // 0x8000C5C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C5C4: sb          $zero, -0x4D3C($at)
    MEM_B(-0X4D3C, ctx->r1) = 0;
    // 0x8000C5C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C5CC: sb          $zero, -0x4B8A($at)
    MEM_B(-0X4B8A, ctx->r1) = 0;
    // 0x8000C5D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C5D4: sb          $zero, -0x4B89($at)
    MEM_B(-0X4B89, ctx->r1) = 0;
    // 0x8000C5D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C5DC: sw          $zero, -0x4B20($at)
    MEM_W(-0X4B20, ctx->r1) = 0;
    // 0x8000C5E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C5E4: sb          $zero, -0x4C80($at)
    MEM_B(-0X4C80, ctx->r1) = 0;
    // 0x8000C5E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C5EC: sb          $v0, -0x4C7F($at)
    MEM_B(-0X4C7F, ctx->r1) = ctx->r2;
    // 0x8000C5F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C5F4: sb          $zero, -0x4D2D($at)
    MEM_B(-0X4D2D, ctx->r1) = 0;
    // 0x8000C5F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C5FC: jr          $ra
    // 0x8000C600: sb          $zero, -0x4CAB($at)
    MEM_B(-0X4CAB, ctx->r1) = 0;
    return;
    // 0x8000C600: sb          $zero, -0x4CAB($at)
    MEM_B(-0X4CAB, ctx->r1) = 0;
;}
RECOMP_FUNC void free_all_objects(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C604: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000C608: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000C60C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8000C610: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8000C614: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000C618: jal         0x80059B9C
    // 0x8000C61C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    timetrial_free_staff_ghost(rdram, ctx);
        goto after_0;
    // 0x8000C61C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x8000C620: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8000C624: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000C628: addiu       $s0, $s0, -0x3374
    ctx->r16 = ADD32(ctx->r16, -0X3374);
    // 0x8000C62C: sb          $zero, -0x3348($at)
    MEM_B(-0X3348, ctx->r1) = 0;
    // 0x8000C630: lb          $t6, 0x0($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X0);
    // 0x8000C634: nop

    // 0x8000C638: beq         $t6, $zero, L_8000C648
    if (ctx->r14 == 0) {
        // 0x8000C63C: nop
    
            goto L_8000C648;
    }
    // 0x8000C63C: nop

    // 0x8000C640: jal         0x800724E4
    // 0x8000C644: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    rumble_init(rdram, ctx);
        goto after_1;
    // 0x8000C644: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
L_8000C648:
    // 0x8000C648: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x8000C64C: addiu       $s1, $s1, -0x334C
    ctx->r17 = ADD32(ctx->r17, -0X334C);
    // 0x8000C650: lb          $t7, 0x0($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X0);
    // 0x8000C654: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x8000C658: beq         $t7, $zero, L_8000C678
    if (ctx->r15 == 0) {
        // 0x8000C65C: nop
    
            goto L_8000C678;
    }
    // 0x8000C65C: nop

    // 0x8000C660: jal         0x8009F1C4
    // 0x8000C664: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_2;
    // 0x8000C664: nop

    after_2:
    // 0x8000C668: beq         $v0, $zero, L_8000C678
    if (ctx->r2 == 0) {
        // 0x8000C66C: nop
    
            goto L_8000C678;
    }
    // 0x8000C66C: nop

    // 0x8000C670: jal         0x8006F5D8
    // 0x8000C674: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
    swap_lead_player(rdram, ctx);
        goto after_3;
    // 0x8000C674: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
    after_3:
L_8000C678:
    // 0x8000C678: jal         0x8001004C
    // 0x8000C67C: nop

    gParticlePtrList_flush(rdram, ctx);
        goto after_4;
    // 0x8000C67C: nop

    after_4:
    // 0x8000C680: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8000C684: lw          $s2, -0x4C24($s2)
    ctx->r18 = MEM_W(ctx->r18, -0X4C24);
    // 0x8000C688: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000C68C: blez        $s2, L_8000C6C0
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8000C690: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8000C6C0;
    }
    // 0x8000C690: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8000C694: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8000C698: addiu       $s3, $s3, -0x4C28
    ctx->r19 = ADD32(ctx->r19, -0X4C28);
L_8000C69C:
    // 0x8000C69C: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x8000C6A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8000C6A4: addu        $t9, $t8, $s1
    ctx->r25 = ADD32(ctx->r24, ctx->r17);
    // 0x8000C6A8: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x8000C6AC: jal         0x800101AC
    // 0x8000C6B0: nop

    obj_destroy(rdram, ctx);
        goto after_5;
    // 0x8000C6B0: nop

    after_5:
    // 0x8000C6B4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000C6B8: bne         $s0, $s2, L_8000C69C
    if (ctx->r16 != ctx->r18) {
        // 0x8000C6BC: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8000C69C;
    }
    // 0x8000C6BC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_8000C6C0:
    // 0x8000C6C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C6C4: sw          $zero, -0x4BB8($at)
    MEM_W(-0X4BB8, ctx->r1) = 0;
    // 0x8000C6C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C6CC: sw          $zero, -0x4C24($at)
    MEM_W(-0X4C24, ctx->r1) = 0;
    // 0x8000C6D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C6D4: jal         0x8000C460
    // 0x8000C6D8: sw          $zero, -0x4C20($at)
    MEM_W(-0X4C20, ctx->r1) = 0;
    clear_object_pointers(rdram, ctx);
        goto after_6;
    // 0x8000C6D8: sw          $zero, -0x4C20($at)
    MEM_W(-0X4C20, ctx->r1) = 0;
    after_6:
    // 0x8000C6DC: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8000C6E0: addiu       $s0, $s0, -0x4BD0
    ctx->r16 = ADD32(ctx->r16, -0X4BD0);
    // 0x8000C6E4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8000C6E8: jal         0x80071380
    // 0x8000C6EC: nop

    mempool_free(rdram, ctx);
        goto after_7;
    // 0x8000C6EC: nop

    after_7:
    // 0x8000C6F0: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x8000C6F4: jal         0x80071380
    // 0x8000C6F8: nop

    mempool_free(rdram, ctx);
        goto after_8;
    // 0x8000C6F8: nop

    after_8:
    // 0x8000C6FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000C700: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000C704: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8000C708: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8000C70C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8000C710: jr          $ra
    // 0x8000C714: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8000C714: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void load_object_header(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C718: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8000C71C: lw          $t6, -0x4C34($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4C34);
    // 0x8000C720: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000C724: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000C728: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8000C72C: addu        $v1, $t6, $a0
    ctx->r3 = ADD32(ctx->r14, ctx->r4);
    // 0x8000C730: lbu         $a1, 0x0($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X0);
    // 0x8000C734: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8000C738: beq         $a1, $zero, L_8000C768
    if (ctx->r5 == 0) {
        // 0x8000C73C: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_8000C768;
    }
    // 0x8000C73C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000C740: addiu       $t8, $a1, 0x1
    ctx->r24 = ADD32(ctx->r5, 0X1);
    // 0x8000C744: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
    // 0x8000C748: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8000C74C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8000C750: lw          $t9, -0x4C38($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4C38);
    // 0x8000C754: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8000C758: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x8000C75C: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x8000C760: b           L_8000C838
    // 0x8000C764: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000C838;
    // 0x8000C764: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000C768:
    // 0x8000C768: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8000C76C: lw          $t4, -0x4D1C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4D1C);
    // 0x8000C770: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x8000C774: addu        $v0, $t4, $t3
    ctx->r2 = ADD32(ctx->r12, ctx->r11);
    // 0x8000C778: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x8000C77C: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x8000C780: lw          $a0, -0x4C18($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C18);
    // 0x8000C784: subu        $a1, $t5, $a2
    ctx->r5 = SUB32(ctx->r13, ctx->r6);
    // 0x8000C788: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x8000C78C: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8000C790: jal         0x800710D0
    // 0x8000C794: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    mempool_alloc_pool(rdram, ctx);
        goto after_0;
    // 0x8000C794: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_0:
    // 0x8000C798: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8000C79C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8000C7A0: beq         $v0, $zero, L_8000C828
    if (ctx->r2 == 0) {
        // 0x8000C7A4: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8000C828;
    }
    // 0x8000C7A4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8000C7A8: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    // 0x8000C7AC: jal         0x80077190
    // 0x8000C7B0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    asset_load(rdram, ctx);
        goto after_1;
    // 0x8000C7B0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8000C7B4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8000C7B8: nop

    // 0x8000C7BC: lw          $t6, 0x24($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X24);
    // 0x8000C7C0: lw          $t8, 0x1C($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X1C);
    // 0x8000C7C4: lw          $t9, 0x14($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X14);
    // 0x8000C7C8: lw          $t2, 0x18($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X18);
    // 0x8000C7CC: lw          $t4, 0x10($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X10);
    // 0x8000C7D0: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x8000C7D4: addu        $t0, $a1, $t8
    ctx->r8 = ADD32(ctx->r5, ctx->r24);
    // 0x8000C7D8: addu        $t1, $a1, $t9
    ctx->r9 = ADD32(ctx->r5, ctx->r25);
    // 0x8000C7DC: addu        $t3, $a1, $t2
    ctx->r11 = ADD32(ctx->r5, ctx->r10);
    // 0x8000C7E0: addu        $t5, $a1, $t4
    ctx->r13 = ADD32(ctx->r5, ctx->r12);
    // 0x8000C7E4: sw          $t7, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r15;
    // 0x8000C7E8: sw          $t0, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r8;
    // 0x8000C7EC: sw          $t1, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r9;
    // 0x8000C7F0: sw          $t3, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r11;
    // 0x8000C7F4: sw          $t5, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r13;
    // 0x8000C7F8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8000C7FC: lw          $t6, -0x4C38($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4C38);
    // 0x8000C800: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8000C804: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8000C808: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8000C80C: sw          $a1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r5;
    // 0x8000C810: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8000C814: lw          $t9, -0x4C34($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4C34);
    // 0x8000C818: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8000C81C: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x8000C820: b           L_8000C830
    // 0x8000C824: sb          $t0, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r8;
        goto L_8000C830;
    // 0x8000C824: sb          $t0, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r8;
L_8000C828:
    // 0x8000C828: b           L_8000C834
    // 0x8000C82C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000C834;
    // 0x8000C82C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000C830:
    // 0x8000C830: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_8000C834:
    // 0x8000C834: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000C838:
    // 0x8000C838: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8000C83C: jr          $ra
    // 0x8000C840: nop

    return;
    // 0x8000C840: nop

;}
RECOMP_FUNC void try_free_object_header(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C844: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8000C848: addiu       $a2, $a2, -0x4C34
    ctx->r6 = ADD32(ctx->r6, -0X4C34);
    // 0x8000C84C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x8000C850: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000C854: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000C858: addu        $v0, $t6, $a0
    ctx->r2 = ADD32(ctx->r14, ctx->r4);
    // 0x8000C85C: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x8000C860: nop

    // 0x8000C864: beq         $v1, $zero, L_8000C8A4
    if (ctx->r3 == 0) {
        // 0x8000C868: addiu       $t7, $v1, -0x1
        ctx->r15 = ADD32(ctx->r3, -0X1);
            goto L_8000C8A4;
    }
    // 0x8000C868: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x8000C86C: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x8000C870: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8000C874: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8000C878: addu        $t9, $t8, $a0
    ctx->r25 = ADD32(ctx->r24, ctx->r4);
    // 0x8000C87C: lbu         $t0, 0x0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X0);
    // 0x8000C880: nop

    // 0x8000C884: bne         $t0, $zero, L_8000C8A8
    if (ctx->r8 != 0) {
        // 0x8000C888: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8000C8A8;
    }
    // 0x8000C888: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000C88C: lw          $t1, -0x4C38($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4C38);
    // 0x8000C890: sll         $t2, $a0, 2
    ctx->r10 = S32(ctx->r4 << 2);
    // 0x8000C894: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8000C898: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x8000C89C: jal         0x80071380
    // 0x8000C8A0: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x8000C8A0: nop

    after_0:
L_8000C8A4:
    // 0x8000C8A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000C8A8:
    // 0x8000C8A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000C8AC: jr          $ra
    // 0x8000C8B0: nop

    return;
    // 0x8000C8B0: nop

;}
RECOMP_FUNC void normalise_time(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C8B4: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x8000C8B8: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x8000C8BC: nop

    // 0x8000C8C0: bne         $t6, $zero, L_8000C8D0
    if (ctx->r14 != 0) {
        // 0x8000C8C4: nop
    
            goto L_8000C8D0;
    }
    // 0x8000C8C4: nop

    // 0x8000C8C8: bgez        $a0, L_8000C8D8
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8000C8CC: sll         $v0, $a0, 2
        ctx->r2 = S32(ctx->r4 << 2);
            goto L_8000C8D8;
    }
    // 0x8000C8CC: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
L_8000C8D0:
    // 0x8000C8D0: jr          $ra
    // 0x8000C8D4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8000C8D4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8000C8D8:
    // 0x8000C8D8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8000C8DC: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8000C8E0: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x8000C8E4: mflo        $v0
    ctx->r2 = lo;
    // 0x8000C8E8: nop

    // 0x8000C8EC: nop

    // 0x8000C8F0: jr          $ra
    // 0x8000C8F4: nop

    return;
    // 0x8000C8F4: nop

;}
RECOMP_FUNC void track_spawn_objects(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C8F8: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8000C8FC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000C900: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000C904: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000C908: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000C90C: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8000C910: jal         0x8006ECD0
    // 0x8000C914: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x8000C914: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8000C918: lbu         $t8, 0x49($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X49);
    // 0x8000C91C: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8000C920: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8000C924: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8000C928: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8000C92C: lhu         $s0, 0xC($v0)
    ctx->r16 = MEM_HU(ctx->r2, 0XC);
    // 0x8000C930: andi        $t1, $v1, 0x4
    ctx->r9 = ctx->r3 & 0X4;
    // 0x8000C934: sltiu       $v1, $t1, 0x1
    ctx->r3 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x8000C938: beq         $v1, $zero, L_8000C958
    if (ctx->r3 == 0) {
        // 0x8000C93C: ori         $t6, $s0, 0x820
        ctx->r14 = ctx->r16 | 0X820;
            goto L_8000C958;
    }
    // 0x8000C93C: ori         $t6, $s0, 0x820
    ctx->r14 = ctx->r16 | 0X820;
    // 0x8000C940: lbu         $t3, 0x48($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X48);
    // 0x8000C944: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8000C948: sllv        $t5, $t4, $t3
    ctx->r13 = S32(ctx->r12 << (ctx->r11 & 31));
    // 0x8000C94C: and         $v1, $t5, $t6
    ctx->r3 = ctx->r13 & ctx->r14;
    // 0x8000C950: sltu        $t6, $zero, $v1
    ctx->r14 = 0 < ctx->r3 ? 1 : 0;
    // 0x8000C954: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
L_8000C958:
    // 0x8000C958: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8000C95C: addiu       $s0, $s0, -0x4C7D
    ctx->r16 = ADD32(ctx->r16, -0X4C7D);
    // 0x8000C960: sb          $v1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r3;
    // 0x8000C964: lbu         $t7, 0x49($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X49);
    // 0x8000C968: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x8000C96C: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8000C970: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8000C974: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8000C978: nop

    // 0x8000C97C: andi        $t2, $t1, 0x2
    ctx->r10 = ctx->r9 & 0X2;
    // 0x8000C980: bne         $t2, $zero, L_8000C98C
    if (ctx->r10 != 0) {
        // 0x8000C984: nop
    
            goto L_8000C98C;
    }
    // 0x8000C984: nop

    // 0x8000C988: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_8000C98C:
    // 0x8000C98C: jal         0x8009C814
    // 0x8000C990: nop

    is_in_tracks_mode(rdram, ctx);
        goto after_1;
    // 0x8000C990: nop

    after_1:
    // 0x8000C994: beq         $v0, $zero, L_8000C9A0
    if (ctx->r2 == 0) {
        // 0x8000C998: nop
    
            goto L_8000C9A0;
    }
    // 0x8000C998: nop

    // 0x8000C99C: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_8000C9A0:
    // 0x8000C9A0: jal         0x8006BFD8
    // 0x8000C9A4: nop

    level_type(rdram, ctx);
        goto after_2;
    // 0x8000C9A4: nop

    after_2:
    // 0x8000C9A8: beq         $v0, $zero, L_8000C9B4
    if (ctx->r2 == 0) {
        // 0x8000C9AC: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8000C9B4;
    }
    // 0x8000C9AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C9B0: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_8000C9B4:
    // 0x8000C9B4: sb          $zero, -0x4D42($at)
    MEM_B(-0X4D42, ctx->r1) = 0;
    // 0x8000C9B8: addiu       $a0, $zero, 0x3000
    ctx->r4 = ADD32(0, 0X3000);
    // 0x8000C9BC: jal         0x80070EDC
    // 0x8000C9C0: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_3;
    // 0x8000C9C0: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_3:
    // 0x8000C9C4: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
    // 0x8000C9C8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8000C9CC: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x8000C9D0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8000C9D4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8000C9D8: addiu       $t3, $t3, -0x4BD0
    ctx->r11 = ADD32(ctx->r11, -0X4BD0);
    // 0x8000C9DC: addiu       $t5, $t5, -0x4BE8
    ctx->r13 = ADD32(ctx->r13, -0X4BE8);
    // 0x8000C9E0: addiu       $t7, $t7, -0x4BE0
    ctx->r15 = ADD32(ctx->r15, -0X4BE0);
    // 0x8000C9E4: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x8000C9E8: addu        $a1, $t4, $t3
    ctx->r5 = ADD32(ctx->r12, ctx->r11);
    // 0x8000C9EC: addu        $s1, $t4, $t5
    ctx->r17 = ADD32(ctx->r12, ctx->r13);
    // 0x8000C9F0: addiu       $t6, $v0, 0x10
    ctx->r14 = ADD32(ctx->r2, 0X10);
    // 0x8000C9F4: addu        $s2, $t4, $t7
    ctx->r18 = ADD32(ctx->r12, ctx->r15);
    // 0x8000C9F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C9FC: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8000CA00: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x8000CA04: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
    // 0x8000CA08: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8000CA0C: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x8000CA10: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x8000CA14: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x8000CA18: jal         0x80076EE4
    // 0x8000CA1C: sw          $t8, -0x4BD8($at)
    MEM_W(-0X4BD8, ctx->r1) = ctx->r24;
    asset_table_load(rdram, ctx);
        goto after_4;
    // 0x8000CA1C: sw          $t8, -0x4BD8($at)
    MEM_W(-0X4BD8, ctx->r1) = ctx->r24;
    after_4:
    // 0x8000CA20: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8000CA24: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8000CA28: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8000CA2C: beq         $a1, $t9, L_8000CA48
    if (ctx->r5 == ctx->r25) {
        // 0x8000CA30: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8000CA48;
    }
    // 0x8000CA30: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000CA34: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
L_8000CA38:
    // 0x8000CA38: lw          $t0, 0x4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X4);
    // 0x8000CA3C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8000CA40: bne         $a1, $t0, L_8000CA38
    if (ctx->r5 != ctx->r8) {
        // 0x8000CA44: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8000CA38;
    }
    // 0x8000CA44: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_8000CA48:
    // 0x8000CA48: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x8000CA4C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8000CA50: slt         $at, $t1, $a0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8000CA54: bne         $at, $zero, L_8000CA60
    if (ctx->r1 != 0) {
        // 0x8000CA58: addiu       $a0, $zero, 0x15
        ctx->r4 = ADD32(0, 0X15);
            goto L_8000CA60;
    }
    // 0x8000CA58: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x8000CA5C: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
L_8000CA60:
    // 0x8000CA60: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x8000CA64: nop

    // 0x8000CA68: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x8000CA6C: addu        $v1, $v0, $t4
    ctx->r3 = ADD32(ctx->r2, ctx->r12);
    // 0x8000CA70: lw          $s0, 0x0($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X0);
    // 0x8000CA74: lw          $t3, 0x4($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X4);
    // 0x8000CA78: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8000CA7C: subu        $a3, $t3, $s0
    ctx->r7 = SUB32(ctx->r11, ctx->r16);
    // 0x8000CA80: beq         $a3, $zero, L_8000CBAC
    if (ctx->r7 == 0) {
        // 0x8000CA84: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8000CBAC;
    }
    // 0x8000CA84: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000CA88: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    // 0x8000CA8C: jal         0x800C673C
    // 0x8000CA90: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    gzip_size_uncompressed(rdram, ctx);
        goto after_5;
    // 0x8000CA90: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    after_5:
    // 0x8000CA94: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x8000CA98: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x8000CA9C: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x8000CAA0: subu        $a1, $t6, $a3
    ctx->r5 = SUB32(ctx->r14, ctx->r7);
    // 0x8000CAA4: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    // 0x8000CAA8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8000CAAC: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x8000CAB0: jal         0x80077190
    // 0x8000CAB4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    asset_load(rdram, ctx);
        goto after_6;
    // 0x8000CAB4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_6:
    // 0x8000CAB8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8000CABC: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x8000CAC0: jal         0x800C6778
    // 0x8000CAC4: nop

    gzip_inflate(rdram, ctx);
        goto after_7;
    // 0x8000CAC4: nop

    after_7:
    // 0x8000CAC8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8000CACC: jal         0x80071380
    // 0x8000CAD0: nop

    mempool_free(rdram, ctx);
        goto after_8;
    // 0x8000CAD0: nop

    after_8:
    // 0x8000CAD4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8000CAD8: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x8000CADC: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8000CAE0: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x8000CAE4: addiu       $t9, $t8, 0x10
    ctx->r25 = ADD32(ctx->r24, 0X10);
    // 0x8000CAE8: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x8000CAEC: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8000CAF0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000CAF4: sw          $t1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r9;
    // 0x8000CAF8: sw          $t2, -0x4BC0($at)
    MEM_W(-0X4BC0, ctx->r1) = ctx->r10;
    // 0x8000CAFC: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x8000CB00: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000CB04: blez        $t4, L_8000CB58
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8000CB08: nop
    
            goto L_8000CB58;
    }
    // 0x8000CB08: nop

L_8000CB0C:
    // 0x8000CB0C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8000CB10: jal         0x8000EA54
    // 0x8000CB14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    spawn_object(rdram, ctx);
        goto after_9;
    // 0x8000CB14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x8000CB18: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8000CB1C: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x8000CB20: lbu         $a0, 0x1($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X1);
    // 0x8000CB24: nop

    // 0x8000CB28: andi        $t3, $a0, 0x3F
    ctx->r11 = ctx->r4 & 0X3F;
    // 0x8000CB2C: addu        $s0, $s0, $t3
    ctx->r16 = ADD32(ctx->r16, ctx->r11);
    // 0x8000CB30: addu        $t5, $t3, $v1
    ctx->r13 = ADD32(ctx->r11, ctx->r3);
    // 0x8000CB34: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8000CB38: bne         $at, $zero, L_8000CB0C
    if (ctx->r1 != 0) {
        // 0x8000CB3C: sw          $t5, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r13;
            goto L_8000CB0C;
    }
    // 0x8000CB3C: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x8000CB40: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8000CB44: nop

    // 0x8000CB48: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8000CB4C: nop

    // 0x8000CB50: addiu       $t9, $t8, 0x10
    ctx->r25 = ADD32(ctx->r24, 0X10);
    // 0x8000CB54: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
L_8000CB58:
    // 0x8000CB58: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000CB5C: sw          $zero, -0x4C10($at)
    MEM_W(-0X4C10, ctx->r1) = 0;
    // 0x8000CB60: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x8000CB64: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8000CB68: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000CB6C: addiu       $s1, $s1, -0x4CD4
    ctx->r17 = ADD32(ctx->r17, -0X4CD4);
    // 0x8000CB70: sw          $s0, -0x4CC0($at)
    MEM_W(-0X4CC0, ctx->r1) = ctx->r16;
    // 0x8000CB74: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x8000CB78: nop

    // 0x8000CB7C: bne         $t0, $zero, L_8000CBA4
    if (ctx->r8 != 0) {
        // 0x8000CB80: nop
    
            goto L_8000CBA4;
    }
    // 0x8000CB80: nop

    // 0x8000CB84: jal         0x8001004C
    // 0x8000CB88: nop

    gParticlePtrList_flush(rdram, ctx);
        goto after_10;
    // 0x8000CB88: nop

    after_10:
    // 0x8000CB8C: jal         0x80017ECC
    // 0x8000CB90: nop

    checkpoint_update_all(rdram, ctx);
        goto after_11;
    // 0x8000CB90: nop

    after_11:
    // 0x8000CB94: jal         0x8001BC88
    // 0x8000CB98: nop

    spectate_update(rdram, ctx);
        goto after_12;
    // 0x8000CB98: nop

    after_12:
    // 0x8000CB9C: jal         0x8001E970
    // 0x8000CBA0: nop

    func_8001E93C(rdram, ctx);
        goto after_13;
    // 0x8000CBA0: nop

    after_13:
L_8000CBA4:
    // 0x8000CBA4: sw          $s0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r16;
    // 0x8000CBA8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8000CBAC:
    // 0x8000CBAC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000CBB0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000CBB4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000CBB8: jr          $ra
    // 0x8000CBBC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8000CBBC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_8000CBC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000CBC0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000CBC4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000CBC8: addiu       $v0, $v0, -0x4C38
    ctx->r2 = ADD32(ctx->r2, -0X4C38);
    // 0x8000CBCC: addiu       $v1, $v1, -0x4C78
    ctx->r3 = ADD32(ctx->r3, -0X4C78);
L_8000CBD0:
    // 0x8000CBD0: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8000CBD4: sw          $zero, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = 0;
    // 0x8000CBD8: sw          $zero, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = 0;
    // 0x8000CBDC: sw          $zero, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = 0;
    // 0x8000CBE0: bne         $v1, $v0, L_8000CBD0
    if (ctx->r3 != ctx->r2) {
        // 0x8000CBE4: sw          $zero, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = 0;
            goto L_8000CBD0;
    }
    // 0x8000CBE4: sw          $zero, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = 0;
    // 0x8000CBE8: jr          $ra
    // 0x8000CBEC: nop

    return;
    // 0x8000CBEC: nop

;}
RECOMP_FUNC void func_8000CBF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000CBF0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8000CBF4: addiu       $t7, $t7, -0x4C78
    ctx->r15 = ADD32(ctx->r15, -0X4C78);
    // 0x8000CBF8: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8000CBFC: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8000CC00: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8000CC04: nop

    // 0x8000CC08: bne         $v1, $zero, L_8000CC18
    if (ctx->r3 != 0) {
        // 0x8000CC0C: nop
    
            goto L_8000CC18;
    }
    // 0x8000CC0C: nop

    // 0x8000CC10: jr          $ra
    // 0x8000CC14: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    return;
    // 0x8000CC14: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
L_8000CC18:
    // 0x8000CC18: jr          $ra
    // 0x8000CC1C: nop

    return;
    // 0x8000CC1C: nop

;}
RECOMP_FUNC void func_8000CC20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000CC20: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000CC24: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8000CC28: addiu       $a1, $a1, -0x4C78
    ctx->r5 = ADD32(ctx->r5, -0X4C78);
    // 0x8000CC2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000CC30: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
L_8000CC34:
    // 0x8000CC34: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x8000CC38: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8000CC3C: nop

    // 0x8000CC40: bne         $t8, $zero, L_8000CC50
    if (ctx->r24 != 0) {
        // 0x8000CC44: nop
    
            goto L_8000CC50;
    }
    // 0x8000CC44: nop

    // 0x8000CC48: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8000CC4C: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
L_8000CC50:
    // 0x8000CC50: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000CC54: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x8000CC58: bne         $at, $zero, L_8000CC34
    if (ctx->r1 != 0) {
        // 0x8000CC5C: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_8000CC34;
    }
    // 0x8000CC5C: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8000CC60: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000CC64: beq         $v1, $at, L_8000CC74
    if (ctx->r3 == ctx->r1) {
        // 0x8000CC68: sll         $t9, $v1, 2
        ctx->r25 = S32(ctx->r3 << 2);
            goto L_8000CC74;
    }
    // 0x8000CC68: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x8000CC6C: addu        $t0, $a1, $t9
    ctx->r8 = ADD32(ctx->r5, ctx->r25);
    // 0x8000CC70: sw          $a0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r4;
L_8000CC74:
    // 0x8000CC74: jr          $ra
    // 0x8000CC78: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8000CC78: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void track_setup_racers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000CC7C: addiu       $sp, $sp, -0x150
    ctx->r29 = ADD32(ctx->r29, -0X150);
    // 0x8000CC80: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000CC84: sb          $zero, -0x4D60($at)
    MEM_B(-0X4D60, ctx->r1) = 0;
    // 0x8000CC88: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000CC8C: sw          $zero, -0x4CD0($at)
    MEM_W(-0X4CD0, ctx->r1) = 0;
    // 0x8000CC90: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000CC94: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000CC98: sb          $zero, -0x4CBC($at)
    MEM_B(-0X4CBC, ctx->r1) = 0;
    // 0x8000CC9C: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8000CCA0: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8000CCA4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000CCA8: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x8000CCAC: addiu       $s1, $s1, -0x4B80
    ctx->r17 = ADD32(ctx->r17, -0X4B80);
    // 0x8000CCB0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8000CCB4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8000CCB8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000CCBC: sw          $zero, -0x4B90($at)
    MEM_W(-0X4B90, ctx->r1) = 0;
    // 0x8000CCC0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8000CCC4: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x8000CCC8: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8000CCCC: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8000CCD0: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8000CCD4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8000CCD8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000CCDC: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
    // 0x8000CCE0: jal         0x800521F8
    // 0x8000CCE4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_taj_status(rdram, ctx);
        goto after_0;
    // 0x8000CCE4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8000CCE8: jal         0x8006BFF0
    // 0x8000CCEC: nop

    level_header(rdram, ctx);
        goto after_1;
    // 0x8000CCEC: nop

    after_1:
    // 0x8000CCF0: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    // 0x8000CCF4: lbu         $v1, 0x4C($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X4C);
    // 0x8000CCF8: addiu       $s6, $zero, 0x6
    ctx->r22 = ADD32(0, 0X6);
    // 0x8000CCFC: beq         $s6, $v1, L_8000E080
    if (ctx->r22 == ctx->r3) {
        // 0x8000CD00: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_8000E080;
    }
    // 0x8000CD00: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8000CD04: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8000CD08: beq         $v1, $at, L_8000E080
    if (ctx->r3 == ctx->r1) {
        // 0x8000CD0C: addiu       $t7, $zero, -0x1
        ctx->r15 = ADD32(0, -0X1);
            goto L_8000E080;
    }
    // 0x8000CD0C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8000CD10: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8000CD14: beq         $v1, $at, L_8000CD20
    if (ctx->r3 == ctx->r1) {
        // 0x8000CD18: andi        $t6, $v1, 0x40
        ctx->r14 = ctx->r3 & 0X40;
            goto L_8000CD20;
    }
    // 0x8000CD18: andi        $t6, $v1, 0x40
    ctx->r14 = ctx->r3 & 0X40;
    // 0x8000CD1C: beq         $t6, $zero, L_8000CD34
    if (ctx->r14 == 0) {
        // 0x8000CD20: lui         $s4, 0x8012
        ctx->r20 = S32(0X8012 << 16);
            goto L_8000CD34;
    }
L_8000CD20:
    // 0x8000CD20: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8000CD24: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000CD28: addiu       $s4, $s4, -0x4B8C
    ctx->r20 = ADD32(ctx->r20, -0X4B8C);
    // 0x8000CD2C: sb          $zero, -0x4B8B($at)
    MEM_B(-0X4B8B, ctx->r1) = 0;
    // 0x8000CD30: sb          $zero, 0x0($s4)
    MEM_B(0X0, ctx->r20) = 0;
L_8000CD34:
    // 0x8000CD34: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8000CD38: addiu       $s4, $s4, -0x4B8C
    ctx->r20 = ADD32(ctx->r20, -0X4B8C);
    // 0x8000CD3C: sw          $t7, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r15;
    // 0x8000CD40: jal         0x8000E4C8
    // 0x8000CD44: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    is_time_trial_enabled(rdram, ctx);
        goto after_2;
    // 0x8000CD44: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    after_2:
    // 0x8000CD48: beq         $v0, $zero, L_8000CD7C
    if (ctx->r2 == 0) {
        // 0x8000CD4C: nop
    
            goto L_8000CD7C;
    }
    // 0x8000CD4C: nop

    // 0x8000CD50: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x8000CD54: nop

    // 0x8000CD58: bne         $t8, $zero, L_8000CD7C
    if (ctx->r24 != 0) {
        // 0x8000CD5C: nop
    
            goto L_8000CD7C;
    }
    // 0x8000CD5C: nop

    // 0x8000CD60: jal         0x80069FBC
    // 0x8000CD64: nop

    cam_get_cameras(rdram, ctx);
        goto after_3;
    // 0x8000CD64: nop

    after_3:
    // 0x8000CD68: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x8000CD6C: lbu         $t9, 0x3B($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X3B);
    // 0x8000CD70: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8000CD74: sw          $t9, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r25;
    // 0x8000CD78: sb          $t5, 0x3B($v0)
    MEM_B(0X3B, ctx->r2) = ctx->r13;
L_8000CD7C:
    // 0x8000CD7C: jal         0x8006DC4C
    // 0x8000CD80: nop

    get_game_mode(rdram, ctx);
        goto after_4;
    // 0x8000CD80: nop

    after_4:
    // 0x8000CD84: jal         0x8006ECD0
    // 0x8000CD88: sw          $v0, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r2;
    get_settings(rdram, ctx);
        goto after_5;
    // 0x8000CD88: sw          $v0, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r2;
    after_5:
    // 0x8000CD8C: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x8000CD90: jal         0x8001E2D0
    // 0x8000CD94: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    get_misc_asset(rdram, ctx);
        goto after_6;
    // 0x8000CD94: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_6:
    // 0x8000CD98: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8000CD9C: addiu       $t3, $t3, -0x4CBB
    ctx->r11 = ADD32(ctx->r11, -0X4CBB);
    // 0x8000CDA0: lb          $t6, 0x0($t3)
    ctx->r14 = MEM_B(ctx->r11, 0X0);
    // 0x8000CDA4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8000CDA8: addiu       $t4, $t4, -0x4BFE
    ctx->r12 = ADD32(ctx->r12, -0X4BFE);
    // 0x8000CDAC: sw          $v0, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r2;
    // 0x8000CDB0: sh          $t6, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r14;
    // 0x8000CDB4: lbu         $t8, 0x49($s7)
    ctx->r24 = MEM_BU(ctx->r23, 0X49);
    // 0x8000CDB8: lw          $t7, 0x4($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X4);
    // 0x8000CDBC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8000CDC0: addu        $v1, $t7, $t9
    ctx->r3 = ADD32(ctx->r15, ctx->r25);
    // 0x8000CDC4: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8000CDC8: addiu       $v0, $sp, 0xB4
    ctx->r2 = ADD32(ctx->r29, 0XB4);
    // 0x8000CDCC: andi        $t5, $a0, 0x1
    ctx->r13 = ctx->r4 & 0X1;
    // 0x8000CDD0: bne         $t5, $zero, L_8000CDE8
    if (ctx->r13 != 0) {
        // 0x8000CDD4: addiu       $a1, $sp, 0xD4
        ctx->r5 = ADD32(ctx->r29, 0XD4);
            goto L_8000CDE8;
    }
    // 0x8000CDD4: addiu       $a1, $sp, 0xD4
    ctx->r5 = ADD32(ctx->r29, 0XD4);
    // 0x8000CDD8: ori         $t6, $a0, 0x1
    ctx->r14 = ctx->r4 | 0X1;
    // 0x8000CDDC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8000CDE0: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8000CDE4: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
L_8000CDE8:
    // 0x8000CDE8: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x8000CDEC: addiu       $v1, $sp, 0xF4
    ctx->r3 = ADD32(ctx->r29, 0XF4);
    // 0x8000CDF0: beq         $t7, $zero, L_8000CE00
    if (ctx->r15 == 0) {
        // 0x8000CDF4: addiu       $a0, $sp, 0xD4
        ctx->r4 = ADD32(ctx->r29, 0XD4);
            goto L_8000CE00;
    }
    // 0x8000CDF4: addiu       $a0, $sp, 0xD4
    ctx->r4 = ADD32(ctx->r29, 0XD4);
    // 0x8000CDF8: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8000CDFC: sb          $t9, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r25;
L_8000CE00:
    // 0x8000CE00: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8000CE04: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x8000CE08: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000CE0C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8000CE10: sw          $zero, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = 0;
    // 0x8000CE14: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
    // 0x8000CE18: bne         $at, $zero, L_8000CE00
    if (ctx->r1 != 0) {
        // 0x8000CE1C: sw          $zero, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = 0;
            goto L_8000CE00;
    }
    // 0x8000CE1C: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x8000CE20: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000CE24: lw          $v0, -0x4C24($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4C24);
    // 0x8000CE28: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8000CE2C: blez        $v0, L_8000CF70
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8000CE30: or          $s5, $zero, $zero
        ctx->r21 = 0 | 0;
            goto L_8000CF70;
    }
    // 0x8000CE30: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8000CE34: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000CE38: lw          $a0, -0x4C28($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C28);
    // 0x8000CE3C: sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2 << 2);
    // 0x8000CE40: addiu       $t2, $sp, 0x94
    ctx->r10 = ADD32(ctx->r29, 0X94);
    // 0x8000CE44: addiu       $t1, $sp, 0xB4
    ctx->r9 = ADD32(ctx->r29, 0XB4);
    // 0x8000CE48: addiu       $t0, $sp, 0xD4
    ctx->r8 = ADD32(ctx->r29, 0XD4);
    // 0x8000CE4C: addiu       $a3, $sp, 0xF4
    ctx->r7 = ADD32(ctx->r29, 0XF4);
    // 0x8000CE50: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
L_8000CE54:
    // 0x8000CE54: lw          $s1, 0x0($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X0);
    // 0x8000CE58: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x8000CE5C: lh          $t5, 0x6($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X6);
    // 0x8000CE60: nop

    // 0x8000CE64: andi        $t6, $t5, 0x8000
    ctx->r14 = ctx->r13 & 0X8000;
    // 0x8000CE68: bne         $t6, $zero, L_8000CF64
    if (ctx->r14 != 0) {
        // 0x8000CE6C: slt         $at, $s5, $a1
        ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_8000CF64;
    }
    // 0x8000CE6C: slt         $at, $s5, $a1
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8000CE70: lh          $t8, 0x48($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X48);
    // 0x8000CE74: nop

    // 0x8000CE78: bne         $a2, $t8, L_8000CF64
    if (ctx->r6 != ctx->r24) {
        // 0x8000CE7C: slt         $at, $s5, $a1
        ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_8000CF64;
    }
    // 0x8000CE7C: slt         $at, $s5, $a1
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8000CE80: lw          $t7, 0x7C($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X7C);
    // 0x8000CE84: nop

    // 0x8000CE88: bne         $s0, $t7, L_8000CF64
    if (ctx->r16 != ctx->r15) {
        // 0x8000CE8C: slt         $at, $s5, $a1
        ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_8000CF64;
    }
    // 0x8000CE8C: slt         $at, $s5, $a1
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8000CE90: lw          $v0, 0x78($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X78);
    // 0x8000CE94: nop

    // 0x8000CE98: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x8000CE9C: beq         $at, $zero, L_8000CF44
    if (ctx->r1 == 0) {
        // 0x8000CEA0: nop
    
            goto L_8000CF44;
    }
    // 0x8000CEA0: nop

    // 0x8000CEA4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8000CEA8: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8000CEAC: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8000CEB0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000CEB4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000CEB8: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8000CEBC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8000CEC0: addu        $t8, $a3, $t6
    ctx->r24 = ADD32(ctx->r7, ctx->r14);
    // 0x8000CEC4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8000CEC8: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x8000CECC: nop

    // 0x8000CED0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8000CED4: sw          $t5, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r13;
    // 0x8000CED8: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8000CEDC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000CEE0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000CEE4: lwc1        $f8, 0x10($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8000CEE8: lw          $t6, 0x78($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X78);
    // 0x8000CEEC: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8000CEF0: sll         $t5, $t6, 2
    ctx->r13 = S32(ctx->r14 << 2);
    // 0x8000CEF4: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x8000CEF8: addu        $t8, $t0, $t5
    ctx->r24 = ADD32(ctx->r8, ctx->r13);
    // 0x8000CEFC: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8000CF00: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000CF04: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8000CF08: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x8000CF0C: lwc1        $f16, 0x14($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8000CF10: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000CF14: lw          $t5, 0x78($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X78);
    // 0x8000CF18: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8000CF1C: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x8000CF20: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x8000CF24: addu        $t8, $t1, $t9
    ctx->r24 = ADD32(ctx->r9, ctx->r25);
    // 0x8000CF28: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x8000CF2C: lw          $t5, 0x78($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X78);
    // 0x8000CF30: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8000CF34: lh          $t7, 0x0($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X0);
    // 0x8000CF38: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x8000CF3C: addu        $t6, $t2, $t9
    ctx->r14 = ADD32(ctx->r10, ctx->r25);
    // 0x8000CF40: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
L_8000CF44:
    // 0x8000CF44: lw          $v0, 0x3C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X3C);
    // 0x8000CF48: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000CF4C: lb          $v1, 0xB($v0)
    ctx->r3 = MEM_B(ctx->r2, 0XB);
    // 0x8000CF50: nop

    // 0x8000CF54: beq         $v1, $at, L_8000CF64
    if (ctx->r3 == ctx->r1) {
        // 0x8000CF58: slt         $at, $s5, $a1
        ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_8000CF64;
    }
    // 0x8000CF58: slt         $at, $s5, $a1
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8000CF5C: or          $fp, $v1, $zero
    ctx->r30 = ctx->r3 | 0;
    // 0x8000CF60: slt         $at, $s5, $a1
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r5) ? 1 : 0;
L_8000CF64:
    // 0x8000CF64: bne         $at, $zero, L_8000CE54
    if (ctx->r1 != 0) {
        // 0x8000CF68: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_8000CE54;
    }
    // 0x8000CF68: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8000CF6C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8000CF70:
    // 0x8000CF70: sb          $fp, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r30;
    // 0x8000CF74: lb          $t8, 0x0($t3)
    ctx->r24 = MEM_B(ctx->r11, 0X0);
    // 0x8000CF78: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8000CF7C: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x8000CF80: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000CF84: sh          $t8, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r24;
    // 0x8000CF88: addiu       $s0, $s0, -0x3350
    ctx->r16 = ADD32(ctx->r16, -0X3350);
    // 0x8000CF8C: addiu       $v0, $s3, 0x1
    ctx->r2 = ADD32(ctx->r19, 0X1);
    // 0x8000CF90: sw          $t5, -0x4B90($at)
    MEM_W(-0X4B90, ctx->r1) = ctx->r13;
    // 0x8000CF94: sw          $v0, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r2;
    // 0x8000CF98: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x8000CF9C: jal         0x8006C3DC
    // 0x8000CFA0: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    race_is_adventure_2P(rdram, ctx);
        goto after_7;
    // 0x8000CFA0: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    after_7:
    // 0x8000CFA4: beq         $v0, $zero, L_8000CFC0
    if (ctx->r2 == 0) {
        // 0x8000CFA8: addiu       $t9, $zero, 0x2
        ctx->r25 = ADD32(0, 0X2);
            goto L_8000CFC0;
    }
    // 0x8000CFA8: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8000CFAC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8000CFB0: sw          $t9, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r25;
    // 0x8000CFB4: sb          $t7, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r15;
    // 0x8000CFB8: jal         0x80024A20
    // 0x8000CFBC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_scene_viewport_num(rdram, ctx);
        goto after_8;
    // 0x8000CFBC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_8:
L_8000CFC0:
    // 0x8000CFC0: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x8000CFC4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8000CFC8: bne         $t6, $at, L_8000CFD4
    if (ctx->r14 != ctx->r1) {
        // 0x8000CFCC: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_8000CFD4;
    }
    // 0x8000CFCC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8000CFD0: sb          $zero, 0x0($s4)
    MEM_B(0X0, ctx->r20) = 0;
L_8000CFD4:
    // 0x8000CFD4: lbu         $t8, 0x0($s4)
    ctx->r24 = MEM_BU(ctx->r20, 0X0);
    // 0x8000CFD8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000CFDC: sb          $t8, -0x4B8B($at)
    MEM_B(-0X4B8B, ctx->r1) = ctx->r24;
    // 0x8000CFE0: lbu         $t5, -0x4B8B($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X4B8B);
    // 0x8000CFE4: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x8000CFE8: beq         $t5, $zero, L_8000CFF8
    if (ctx->r13 == 0) {
        // 0x8000CFEC: lw          $t7, 0x68($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X68);
            goto L_8000CFF8;
    }
    // 0x8000CFEC: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x8000CFF0: sw          $t9, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r25;
    // 0x8000CFF4: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
L_8000CFF8:
    // 0x8000CFF8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8000CFFC: andi        $t6, $t7, 0x40
    ctx->r14 = ctx->r15 & 0X40;
    // 0x8000D000: beq         $t7, $at, L_8000D01C
    if (ctx->r15 == ctx->r1) {
        // 0x8000D004: sw          $t6, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r14;
            goto L_8000D01C;
    }
    // 0x8000D004: sw          $t6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r14;
    // 0x8000D008: lw          $t8, 0x144($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X144);
    // 0x8000D00C: lw          $t7, 0x144($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X144);
    // 0x8000D010: slti        $at, $t8, 0x3
    ctx->r1 = SIGNED(ctx->r24) < 0X3 ? 1 : 0;
    // 0x8000D014: bne         $at, $zero, L_8000D058
    if (ctx->r1 != 0) {
        // 0x8000D018: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8000D058;
    }
    // 0x8000D018: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_8000D01C:
    // 0x8000D01C: lw          $t5, 0x144($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X144);
    // 0x8000D020: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000D024: jal         0x8006C530
    // 0x8000D028: sw          $t5, -0x4B90($at)
    MEM_W(-0X4B90, ctx->r1) = ctx->r13;
    level_properties_get(rdram, ctx);
        goto after_9;
    // 0x8000D028: sw          $t5, -0x4B90($at)
    MEM_W(-0X4B90, ctx->r1) = ctx->r13;
    after_9:
    // 0x8000D02C: bne         $v0, $zero, L_8000D070
    if (ctx->r2 != 0) {
        // 0x8000D030: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_8000D070;
    }
    // 0x8000D030: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8000D034: addiu       $v1, $v1, -0x3388
    ctx->r3 = ADD32(ctx->r3, -0X3388);
    // 0x8000D038: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x8000D03C: lw          $t9, 0x94($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X94);
    // 0x8000D040: beq         $v0, $zero, L_8000D070
    if (ctx->r2 == 0) {
        // 0x8000D044: addu        $t6, $t9, $v0
        ctx->r14 = ADD32(ctx->r25, ctx->r2);
            goto L_8000D070;
    }
    // 0x8000D044: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x8000D048: sw          $t6, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r14;
    // 0x8000D04C: b           L_8000D070
    // 0x8000D050: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
        goto L_8000D070;
    // 0x8000D050: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x8000D054: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_8000D058:
    // 0x8000D058: bne         $t7, $at, L_8000D074
    if (ctx->r15 != ctx->r1) {
        // 0x8000D05C: lw          $t8, 0x64($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X64);
            goto L_8000D074;
    }
    // 0x8000D05C: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x8000D060: jal         0x8009C984
    // 0x8000D064: nop

    get_multiplayer_racer_count(rdram, ctx);
        goto after_10;
    // 0x8000D064: nop

    after_10:
    // 0x8000D068: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000D06C: sw          $v0, -0x4B90($at)
    MEM_W(-0X4B90, ctx->r1) = ctx->r2;
L_8000D070:
    // 0x8000D070: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
L_8000D074:
    // 0x8000D074: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000D078: beq         $t8, $zero, L_8000D090
    if (ctx->r24 == 0) {
        // 0x8000D07C: addiu       $a1, $a1, -0x4D44
        ctx->r5 = ADD32(ctx->r5, -0X4D44);
            goto L_8000D090;
    }
    // 0x8000D07C: addiu       $a1, $a1, -0x4D44
    ctx->r5 = ADD32(ctx->r5, -0X4D44);
    // 0x8000D080: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8000D084: addiu       $a2, $a2, -0x4B90
    ctx->r6 = ADD32(ctx->r6, -0X4B90);
    // 0x8000D088: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x8000D08C: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
L_8000D090:
    // 0x8000D090: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x8000D094: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8000D098: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8000D09C: addiu       $a2, $a2, -0x4B90
    ctx->r6 = ADD32(ctx->r6, -0X4B90);
    // 0x8000D0A0: bne         $t9, $at, L_8000D0BC
    if (ctx->r25 != ctx->r1) {
        // 0x8000D0A4: sb          $zero, 0x0($a1)
        MEM_B(0X0, ctx->r5) = 0;
            goto L_8000D0BC;
    }
    // 0x8000D0A4: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x8000D0A8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8000D0AC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8000D0B0: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8000D0B4: sw          $a3, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r7;
    // 0x8000D0B8: sb          $a3, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r7;
L_8000D0BC:
    // 0x8000D0BC: lw          $t7, 0x138($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X138);
    // 0x8000D0C0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000D0C4: addiu       $v0, $v0, -0x3374
    ctx->r2 = ADD32(ctx->r2, -0X3374);
    // 0x8000D0C8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8000D0CC: bne         $t7, $a3, L_8000D0F0
    if (ctx->r15 != ctx->r7) {
        // 0x8000D0D0: sb          $zero, 0x0($v0)
        MEM_B(0X0, ctx->r2) = 0;
            goto L_8000D0F0;
    }
    // 0x8000D0D0: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8000D0D4: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x8000D0D8: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8000D0DC: bne         $t8, $zero, L_8000D0F0
    if (ctx->r24 != 0) {
        // 0x8000D0E0: nop
    
            goto L_8000D0F0;
    }
    // 0x8000D0E0: nop

    // 0x8000D0E4: sw          $s6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r22;
    // 0x8000D0E8: sb          $a3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r7;
    // 0x8000D0EC: sb          $t5, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r13;
L_8000D0F0:
    // 0x8000D0F0: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x8000D0F4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000D0F8: blez        $v1, L_8000D118
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8000D0FC: addiu       $v0, $sp, 0x11C
        ctx->r2 = ADD32(ctx->r29, 0X11C);
            goto L_8000D118;
    }
    // 0x8000D0FC: addiu       $v0, $sp, 0x11C
    ctx->r2 = ADD32(ctx->r29, 0X11C);
    // 0x8000D100: addu        $a0, $v1, $v0
    ctx->r4 = ADD32(ctx->r3, ctx->r2);
L_8000D104:
    // 0x8000D104: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000D108: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x8000D10C: bne         $at, $zero, L_8000D104
    if (ctx->r1 != 0) {
        // 0x8000D110: sb          $zero, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = 0;
            goto L_8000D104;
    }
    // 0x8000D110: sb          $zero, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = 0;
    // 0x8000D114: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8000D118:
    // 0x8000D118: lw          $t6, 0x144($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X144);
    // 0x8000D11C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000D120: blez        $t6, L_8000D2E0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8000D124: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_8000D2E0;
    }
    // 0x8000D124: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8000D128: andi        $v0, $t6, 0x3
    ctx->r2 = ctx->r14 & 0X3;
    // 0x8000D12C: beq         $v0, $zero, L_8000D1A4
    if (ctx->r2 == 0) {
        // 0x8000D130: or          $t1, $v0, $zero
        ctx->r9 = ctx->r2 | 0;
            goto L_8000D1A4;
    }
    // 0x8000D130: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x8000D134: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x8000D138: subu        $t7, $t7, $s0
    ctx->r15 = SUB32(ctx->r15, ctx->r16);
    // 0x8000D13C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8000D140: addu        $a2, $s7, $t7
    ctx->r6 = ADD32(ctx->r23, ctx->r15);
    // 0x8000D144: addiu       $t0, $sp, 0x114
    ctx->r8 = ADD32(ctx->r29, 0X114);
    // 0x8000D148: addiu       $a3, $sp, 0x11C
    ctx->r7 = ADD32(ctx->r29, 0X11C);
L_8000D14C:
    // 0x8000D14C: lb          $v0, 0x5A($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X5A);
    // 0x8000D150: nop

    // 0x8000D154: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000D158: beq         $at, $zero, L_8000D178
    if (ctx->r1 == 0) {
        // 0x8000D15C: addu        $a0, $a3, $v0
        ctx->r4 = ADD32(ctx->r7, ctx->r2);
            goto L_8000D178;
    }
    // 0x8000D15C: addu        $a0, $a3, $v0
    ctx->r4 = ADD32(ctx->r7, ctx->r2);
    // 0x8000D160: lb          $t8, 0x0($a0)
    ctx->r24 = MEM_B(ctx->r4, 0X0);
    // 0x8000D164: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8000D168: bne         $t8, $zero, L_8000D17C
    if (ctx->r24 != 0) {
        // 0x8000D16C: addu        $t9, $t0, $a1
        ctx->r25 = ADD32(ctx->r8, ctx->r5);
            goto L_8000D17C;
    }
    // 0x8000D16C: addu        $t9, $t0, $a1
    ctx->r25 = ADD32(ctx->r8, ctx->r5);
    // 0x8000D170: b           L_8000D18C
    // 0x8000D174: sb          $t5, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r13;
        goto L_8000D18C;
    // 0x8000D174: sb          $t5, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r13;
L_8000D178:
    // 0x8000D178: addu        $t9, $t0, $a1
    ctx->r25 = ADD32(ctx->r8, ctx->r5);
L_8000D17C:
    // 0x8000D17C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8000D180: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8000D184: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8000D188: sb          $s0, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r16;
L_8000D18C:
    // 0x8000D18C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000D190: bne         $t1, $s0, L_8000D14C
    if (ctx->r9 != ctx->r16) {
        // 0x8000D194: addiu       $a2, $a2, 0x18
        ctx->r6 = ADD32(ctx->r6, 0X18);
            goto L_8000D14C;
    }
    // 0x8000D194: addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
    // 0x8000D198: lw          $t7, 0x144($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X144);
    // 0x8000D19C: nop

    // 0x8000D1A0: beq         $s0, $t7, L_8000D2D8
    if (ctx->r16 == ctx->r15) {
        // 0x8000D1A4: sll         $t8, $s0, 2
        ctx->r24 = S32(ctx->r16 << 2);
            goto L_8000D2D8;
    }
L_8000D1A4:
    // 0x8000D1A4: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x8000D1A8: subu        $t8, $t8, $s0
    ctx->r24 = SUB32(ctx->r24, ctx->r16);
    // 0x8000D1AC: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8000D1B0: addu        $a2, $s7, $t8
    ctx->r6 = ADD32(ctx->r23, ctx->r24);
    // 0x8000D1B4: addiu       $a3, $sp, 0x11C
    ctx->r7 = ADD32(ctx->r29, 0X11C);
    // 0x8000D1B8: addiu       $t0, $sp, 0x114
    ctx->r8 = ADD32(ctx->r29, 0X114);
L_8000D1BC:
    // 0x8000D1BC: lb          $v0, 0x5A($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X5A);
    // 0x8000D1C0: nop

    // 0x8000D1C4: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000D1C8: beq         $at, $zero, L_8000D1E8
    if (ctx->r1 == 0) {
        // 0x8000D1CC: addu        $a0, $a3, $v0
        ctx->r4 = ADD32(ctx->r7, ctx->r2);
            goto L_8000D1E8;
    }
    // 0x8000D1CC: addu        $a0, $a3, $v0
    ctx->r4 = ADD32(ctx->r7, ctx->r2);
    // 0x8000D1D0: lb          $t5, 0x0($a0)
    ctx->r13 = MEM_B(ctx->r4, 0X0);
    // 0x8000D1D4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8000D1D8: bne         $t5, $zero, L_8000D1EC
    if (ctx->r13 != 0) {
        // 0x8000D1DC: addu        $t6, $t0, $a1
        ctx->r14 = ADD32(ctx->r8, ctx->r5);
            goto L_8000D1EC;
    }
    // 0x8000D1DC: addu        $t6, $t0, $a1
    ctx->r14 = ADD32(ctx->r8, ctx->r5);
    // 0x8000D1E0: b           L_8000D1FC
    // 0x8000D1E4: sb          $t9, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r25;
        goto L_8000D1FC;
    // 0x8000D1E4: sb          $t9, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r25;
L_8000D1E8:
    // 0x8000D1E8: addu        $t6, $t0, $a1
    ctx->r14 = ADD32(ctx->r8, ctx->r5);
L_8000D1EC:
    // 0x8000D1EC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8000D1F0: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x8000D1F4: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x8000D1F8: sb          $s0, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r16;
L_8000D1FC:
    // 0x8000D1FC: lb          $v0, 0x72($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X72);
    // 0x8000D200: nop

    // 0x8000D204: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000D208: beq         $at, $zero, L_8000D228
    if (ctx->r1 == 0) {
        // 0x8000D20C: addu        $a0, $a3, $v0
        ctx->r4 = ADD32(ctx->r7, ctx->r2);
            goto L_8000D228;
    }
    // 0x8000D20C: addu        $a0, $a3, $v0
    ctx->r4 = ADD32(ctx->r7, ctx->r2);
    // 0x8000D210: lb          $t8, 0x0($a0)
    ctx->r24 = MEM_B(ctx->r4, 0X0);
    // 0x8000D214: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8000D218: bne         $t8, $zero, L_8000D22C
    if (ctx->r24 != 0) {
        // 0x8000D21C: addu        $t6, $t0, $a1
        ctx->r14 = ADD32(ctx->r8, ctx->r5);
            goto L_8000D22C;
    }
    // 0x8000D21C: addu        $t6, $t0, $a1
    ctx->r14 = ADD32(ctx->r8, ctx->r5);
    // 0x8000D220: b           L_8000D240
    // 0x8000D224: sb          $t5, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r13;
        goto L_8000D240;
    // 0x8000D224: sb          $t5, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r13;
L_8000D228:
    // 0x8000D228: addu        $t6, $t0, $a1
    ctx->r14 = ADD32(ctx->r8, ctx->r5);
L_8000D22C:
    // 0x8000D22C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8000D230: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x8000D234: addiu       $t9, $s0, 0x1
    ctx->r25 = ADD32(ctx->r16, 0X1);
    // 0x8000D238: sb          $t9, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r25;
    // 0x8000D23C: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
L_8000D240:
    // 0x8000D240: lb          $v0, 0x8A($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X8A);
    // 0x8000D244: nop

    // 0x8000D248: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000D24C: beq         $at, $zero, L_8000D26C
    if (ctx->r1 == 0) {
        // 0x8000D250: addu        $a0, $a3, $v0
        ctx->r4 = ADD32(ctx->r7, ctx->r2);
            goto L_8000D26C;
    }
    // 0x8000D250: addu        $a0, $a3, $v0
    ctx->r4 = ADD32(ctx->r7, ctx->r2);
    // 0x8000D254: lb          $t8, 0x0($a0)
    ctx->r24 = MEM_B(ctx->r4, 0X0);
    // 0x8000D258: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8000D25C: bne         $t8, $zero, L_8000D270
    if (ctx->r24 != 0) {
        // 0x8000D260: addu        $t6, $t0, $a1
        ctx->r14 = ADD32(ctx->r8, ctx->r5);
            goto L_8000D270;
    }
    // 0x8000D260: addu        $t6, $t0, $a1
    ctx->r14 = ADD32(ctx->r8, ctx->r5);
    // 0x8000D264: b           L_8000D284
    // 0x8000D268: sb          $t5, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r13;
        goto L_8000D284;
    // 0x8000D268: sb          $t5, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r13;
L_8000D26C:
    // 0x8000D26C: addu        $t6, $t0, $a1
    ctx->r14 = ADD32(ctx->r8, ctx->r5);
L_8000D270:
    // 0x8000D270: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8000D274: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x8000D278: addiu       $t9, $s0, 0x2
    ctx->r25 = ADD32(ctx->r16, 0X2);
    // 0x8000D27C: sb          $t9, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r25;
    // 0x8000D280: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
L_8000D284:
    // 0x8000D284: lb          $v0, 0xA2($a2)
    ctx->r2 = MEM_B(ctx->r6, 0XA2);
    // 0x8000D288: nop

    // 0x8000D28C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000D290: beq         $at, $zero, L_8000D2B0
    if (ctx->r1 == 0) {
        // 0x8000D294: addu        $a0, $a3, $v0
        ctx->r4 = ADD32(ctx->r7, ctx->r2);
            goto L_8000D2B0;
    }
    // 0x8000D294: addu        $a0, $a3, $v0
    ctx->r4 = ADD32(ctx->r7, ctx->r2);
    // 0x8000D298: lb          $t8, 0x0($a0)
    ctx->r24 = MEM_B(ctx->r4, 0X0);
    // 0x8000D29C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8000D2A0: bne         $t8, $zero, L_8000D2B4
    if (ctx->r24 != 0) {
        // 0x8000D2A4: addu        $t6, $t0, $a1
        ctx->r14 = ADD32(ctx->r8, ctx->r5);
            goto L_8000D2B4;
    }
    // 0x8000D2A4: addu        $t6, $t0, $a1
    ctx->r14 = ADD32(ctx->r8, ctx->r5);
    // 0x8000D2A8: b           L_8000D2C8
    // 0x8000D2AC: sb          $t5, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r13;
        goto L_8000D2C8;
    // 0x8000D2AC: sb          $t5, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r13;
L_8000D2B0:
    // 0x8000D2B0: addu        $t6, $t0, $a1
    ctx->r14 = ADD32(ctx->r8, ctx->r5);
L_8000D2B4:
    // 0x8000D2B4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8000D2B8: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x8000D2BC: addiu       $t9, $s0, 0x3
    ctx->r25 = ADD32(ctx->r16, 0X3);
    // 0x8000D2C0: sb          $t9, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r25;
    // 0x8000D2C4: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
L_8000D2C8:
    // 0x8000D2C8: lw          $t8, 0x144($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X144);
    // 0x8000D2CC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8000D2D0: bne         $s0, $t8, L_8000D1BC
    if (ctx->r16 != ctx->r24) {
        // 0x8000D2D4: addiu       $a2, $a2, 0x60
        ctx->r6 = ADD32(ctx->r6, 0X60);
            goto L_8000D1BC;
    }
    // 0x8000D2D4: addiu       $a2, $a2, 0x60
    ctx->r6 = ADD32(ctx->r6, 0X60);
L_8000D2D8:
    // 0x8000D2D8: lw          $v0, 0x144($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X144);
    // 0x8000D2DC: nop

L_8000D2E0:
    // 0x8000D2E0: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000D2E4: addiu       $a3, $sp, 0x11C
    ctx->r7 = ADD32(ctx->r29, 0X11C);
    // 0x8000D2E8: addiu       $t0, $sp, 0x114
    ctx->r8 = ADD32(ctx->r29, 0X114);
    // 0x8000D2EC: beq         $at, $zero, L_8000D354
    if (ctx->r1 == 0) {
        // 0x8000D2F0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8000D354;
    }
    // 0x8000D2F0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000D2F4: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x8000D2F8: subu        $t5, $t5, $v0
    ctx->r13 = SUB32(ctx->r13, ctx->r2);
    // 0x8000D2FC: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8000D300: addu        $a2, $s7, $t5
    ctx->r6 = ADD32(ctx->r23, ctx->r13);
L_8000D304:
    // 0x8000D304: lb          $v0, 0x5A($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X5A);
    // 0x8000D308: nop

    // 0x8000D30C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000D310: beq         $at, $zero, L_8000D330
    if (ctx->r1 == 0) {
        // 0x8000D314: addu        $a0, $a3, $v0
        ctx->r4 = ADD32(ctx->r7, ctx->r2);
            goto L_8000D330;
    }
    // 0x8000D314: addu        $a0, $a3, $v0
    ctx->r4 = ADD32(ctx->r7, ctx->r2);
    // 0x8000D318: lb          $t9, 0x0($a0)
    ctx->r25 = MEM_B(ctx->r4, 0X0);
    // 0x8000D31C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8000D320: bne         $t9, $zero, L_8000D334
    if (ctx->r25 != 0) {
        // 0x8000D324: addu        $t7, $t0, $a1
        ctx->r15 = ADD32(ctx->r8, ctx->r5);
            goto L_8000D334;
    }
    // 0x8000D324: addu        $t7, $t0, $a1
    ctx->r15 = ADD32(ctx->r8, ctx->r5);
    // 0x8000D328: b           L_8000D344
    // 0x8000D32C: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
        goto L_8000D344;
    // 0x8000D32C: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
L_8000D330:
    // 0x8000D330: addu        $t7, $t0, $a1
    ctx->r15 = ADD32(ctx->r8, ctx->r5);
L_8000D334:
    // 0x8000D334: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8000D338: andi        $t8, $a1, 0xFF
    ctx->r24 = ctx->r5 & 0XFF;
    // 0x8000D33C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x8000D340: sb          $s0, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r16;
L_8000D344:
    // 0x8000D344: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000D348: slt         $at, $s0, $v1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000D34C: bne         $at, $zero, L_8000D304
    if (ctx->r1 != 0) {
        // 0x8000D350: addiu       $a2, $a2, 0x18
        ctx->r6 = ADD32(ctx->r6, 0X18);
            goto L_8000D304;
    }
    // 0x8000D350: addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
L_8000D354:
    // 0x8000D354: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000D358: blez        $a1, L_8000D3CC
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8000D35C: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8000D3CC;
    }
    // 0x8000D35C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8000D360: addiu       $s5, $zero, 0x18
    ctx->r21 = ADD32(0, 0X18);
L_8000D364:
    // 0x8000D364: blez        $v1, L_8000D3BC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8000D368: addu        $v0, $a3, $s2
        ctx->r2 = ADD32(ctx->r7, ctx->r18);
            goto L_8000D3BC;
    }
    // 0x8000D368: addu        $v0, $a3, $s2
    ctx->r2 = ADD32(ctx->r7, ctx->r18);
L_8000D36C:
    // 0x8000D36C: lb          $t5, 0x0($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X0);
    // 0x8000D370: addu        $t6, $t0, $s0
    ctx->r14 = ADD32(ctx->r8, ctx->r16);
    // 0x8000D374: bne         $t5, $zero, L_8000D3A8
    if (ctx->r13 != 0) {
        // 0x8000D378: nop
    
            goto L_8000D3A8;
    }
    // 0x8000D378: nop

    // 0x8000D37C: lb          $t7, 0x0($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X0);
    // 0x8000D380: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8000D384: multu       $t7, $s5
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000D388: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x8000D38C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000D390: mflo        $t8
    ctx->r24 = lo;
    // 0x8000D394: addu        $t5, $s7, $t8
    ctx->r13 = ADD32(ctx->r23, ctx->r24);
    // 0x8000D398: sb          $s2, 0x5A($t5)
    MEM_B(0X5A, ctx->r13) = ctx->r18;
    // 0x8000D39C: lw          $v1, -0x4B90($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4B90);
    // 0x8000D3A0: nop

    // 0x8000D3A4: or          $s2, $v1, $zero
    ctx->r18 = ctx->r3 | 0;
L_8000D3A8:
    // 0x8000D3A8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8000D3AC: slt         $at, $s2, $v1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000D3B0: bne         $at, $zero, L_8000D36C
    if (ctx->r1 != 0) {
        // 0x8000D3B4: addu        $v0, $a3, $s2
        ctx->r2 = ADD32(ctx->r7, ctx->r18);
            goto L_8000D36C;
    }
    // 0x8000D3B4: addu        $v0, $a3, $s2
    ctx->r2 = ADD32(ctx->r7, ctx->r18);
    // 0x8000D3B8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8000D3BC:
    // 0x8000D3BC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000D3C0: bne         $s0, $a0, L_8000D364
    if (ctx->r16 != ctx->r4) {
        // 0x8000D3C4: nop
    
            goto L_8000D364;
    }
    // 0x8000D3C4: nop

    // 0x8000D3C8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8000D3CC:
    // 0x8000D3CC: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x8000D3D0: addiu       $s5, $zero, 0x18
    ctx->r21 = ADD32(0, 0X18);
    // 0x8000D3D4: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x8000D3D8: jal         0x80070EDC
    // 0x8000D3DC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    mempool_alloc_safe(rdram, ctx);
        goto after_11;
    // 0x8000D3DC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_11:
    // 0x8000D3E0: sh          $zero, 0xC($v0)
    MEM_H(0XC, ctx->r2) = 0;
    // 0x8000D3E4: sh          $zero, 0xA($v0)
    MEM_H(0XA, ctx->r2) = 0;
    // 0x8000D3E8: sh          $zero, 0x8($v0)
    MEM_H(0X8, ctx->r2) = 0;
    // 0x8000D3EC: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x8000D3F0: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x8000D3F4: lb          $t6, 0x4D($t9)
    ctx->r14 = MEM_B(ctx->r25, 0X4D);
    // 0x8000D3F8: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8000D3FC: bne         $t6, $zero, L_8000D410
    if (ctx->r14 != 0) {
        // 0x8000D400: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_8000D410;
    }
    // 0x8000D400: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000D404: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000D408: b           L_8000D41C
    // 0x8000D40C: sb          $zero, -0x4C7E($at)
    MEM_B(-0X4C7E, ctx->r1) = 0;
        goto L_8000D41C;
    // 0x8000D40C: sb          $zero, -0x4C7E($at)
    MEM_B(-0X4C7E, ctx->r1) = 0;
L_8000D410:
    // 0x8000D410: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8000D414: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000D418: sb          $t7, -0x4C7E($at)
    MEM_B(-0X4C7E, ctx->r1) = ctx->r15;
L_8000D41C:
    // 0x8000D41C: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x8000D420: lw          $v1, -0x4B90($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4B90);
    // 0x8000D424: lb          $t5, 0xB8($t8)
    ctx->r13 = MEM_B(ctx->r24, 0XB8);
    // 0x8000D428: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000D42C: sb          $t9, 0x127($sp)
    MEM_B(0X127, ctx->r29) = ctx->r25;
    // 0x8000D430: blez        $v1, L_8000D9AC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8000D434: sb          $t5, -0x4D5B($at)
        MEM_B(-0X4D5B, ctx->r1) = ctx->r13;
            goto L_8000D9AC;
    }
    // 0x8000D434: sb          $t5, -0x4D5B($at)
    MEM_B(-0X4D5B, ctx->r1) = ctx->r13;
    // 0x8000D438: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x8000D43C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_8000D440:
    // 0x8000D440: beq         $v0, $a0, L_8000D4A8
    if (ctx->r2 == ctx->r4) {
        // 0x8000D444: or          $s4, $s0, $zero
        ctx->r20 = ctx->r16 | 0;
            goto L_8000D4A8;
    }
    // 0x8000D444: or          $s4, $s0, $zero
    ctx->r20 = ctx->r16 | 0;
    // 0x8000D448: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x8000D44C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8000D450: bne         $t6, $zero, L_8000D4A8
    if (ctx->r14 != 0) {
        // 0x8000D454: nop
    
            goto L_8000D4A8;
    }
    // 0x8000D454: nop

    // 0x8000D458: lb          $t7, -0x4D44($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X4D44);
    // 0x8000D45C: nop

    // 0x8000D460: bne         $t7, $zero, L_8000D4A8
    if (ctx->r15 != 0) {
        // 0x8000D464: nop
    
            goto L_8000D4A8;
    }
    // 0x8000D464: nop

    // 0x8000D468: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_8000D46C:
    // 0x8000D46C: multu       $s2, $s5
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000D470: mflo        $t8
    ctx->r24 = lo;
    // 0x8000D474: addu        $t5, $s7, $t8
    ctx->r13 = ADD32(ctx->r23, ctx->r24);
    // 0x8000D478: lb          $t9, 0x5A($t5)
    ctx->r25 = MEM_B(ctx->r13, 0X5A);
    // 0x8000D47C: nop

    // 0x8000D480: bne         $s0, $t9, L_8000D490
    if (ctx->r16 != ctx->r25) {
        // 0x8000D484: nop
    
            goto L_8000D490;
    }
    // 0x8000D484: nop

    // 0x8000D488: or          $s4, $s2, $zero
    ctx->r20 = ctx->r18 | 0;
    // 0x8000D48C: or          $s2, $v1, $zero
    ctx->r18 = ctx->r3 | 0;
L_8000D490:
    // 0x8000D490: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8000D494: slt         $at, $s2, $v1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000D498: bne         $at, $zero, L_8000D46C
    if (ctx->r1 != 0) {
        // 0x8000D49C: nop
    
            goto L_8000D46C;
    }
    // 0x8000D49C: nop

    // 0x8000D4A0: b           L_8000D4A8
    // 0x8000D4A4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
        goto L_8000D4A8;
    // 0x8000D4A4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8000D4A8:
    // 0x8000D4A8: lw          $t6, 0x144($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X144);
    // 0x8000D4AC: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8000D4B0: slt         $at, $s4, $t6
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8000D4B4: beq         $at, $zero, L_8000D4C4
    if (ctx->r1 == 0) {
        // 0x8000D4B8: sll         $a2, $s0, 2
        ctx->r6 = S32(ctx->r16 << 2);
            goto L_8000D4C4;
    }
    // 0x8000D4B8: sll         $a2, $s0, 2
    ctx->r6 = S32(ctx->r16 << 2);
    // 0x8000D4BC: b           L_8000D4C8
    // 0x8000D4C0: sh          $s4, 0xE($s6)
    MEM_H(0XE, ctx->r22) = ctx->r20;
        goto L_8000D4C8;
    // 0x8000D4C0: sh          $s4, 0xE($s6)
    MEM_H(0XE, ctx->r22) = ctx->r20;
L_8000D4C4:
    // 0x8000D4C4: sh          $t7, 0xE($s6)
    MEM_H(0XE, ctx->r22) = ctx->r15;
L_8000D4C8:
    // 0x8000D4C8: bne         $v0, $a0, L_8000D4E0
    if (ctx->r2 != ctx->r4) {
        // 0x8000D4CC: addiu       $t5, $sp, 0xF4
        ctx->r13 = ADD32(ctx->r29, 0XF4);
            goto L_8000D4E0;
    }
    // 0x8000D4CC: addiu       $t5, $sp, 0xF4
    ctx->r13 = ADD32(ctx->r29, 0XF4);
    // 0x8000D4D0: lh          $t8, 0xE($s6)
    ctx->r24 = MEM_H(ctx->r22, 0XE);
    // 0x8000D4D4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8000D4D8: beq         $t8, $at, L_8000D994
    if (ctx->r24 == ctx->r1) {
        // 0x8000D4DC: nop
    
            goto L_8000D994;
    }
    // 0x8000D4DC: nop

L_8000D4E0:
    // 0x8000D4E0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000D4E4: addu        $s3, $a2, $t5
    ctx->r19 = ADD32(ctx->r6, ctx->r13);
    // 0x8000D4E8: addiu       $t9, $sp, 0xD4
    ctx->r25 = ADD32(ctx->r29, 0XD4);
    // 0x8000D4EC: lb          $v0, -0x4D44($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X4D44);
    // 0x8000D4F0: addu        $t6, $a2, $t9
    ctx->r14 = ADD32(ctx->r6, ctx->r25);
    // 0x8000D4F4: addiu       $t5, $sp, 0x94
    ctx->r13 = ADD32(ctx->r29, 0X94);
    // 0x8000D4F8: addiu       $t7, $sp, 0xB4
    ctx->r15 = ADD32(ctx->r29, 0XB4);
    // 0x8000D4FC: addu        $t8, $a2, $t7
    ctx->r24 = ADD32(ctx->r6, ctx->r15);
    // 0x8000D500: addu        $t9, $a2, $t5
    ctx->r25 = ADD32(ctx->r6, ctx->r13);
    // 0x8000D504: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000D508: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x8000D50C: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
    // 0x8000D510: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
    // 0x8000D514: bne         $v0, $at, L_8000D560
    if (ctx->r2 != ctx->r1) {
        // 0x8000D518: addiu       $s1, $zero, 0x1
        ctx->r17 = ADD32(0, 0X1);
            goto L_8000D560;
    }
    // 0x8000D518: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x8000D51C: bne         $s0, $zero, L_8000D544
    if (ctx->r16 != 0) {
        // 0x8000D520: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_8000D544;
    }
    // 0x8000D520: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8000D524: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8000D528: lb          $t6, -0x4D5B($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X4D5B);
    // 0x8000D52C: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x8000D530: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8000D534: addu        $fp, $fp, $t7
    ctx->r30 = ADD32(ctx->r30, ctx->r15);
    // 0x8000D538: lb          $fp, -0x3270($fp)
    ctx->r30 = MEM_B(ctx->r30, -0X3270);
    // 0x8000D53C: b           L_8000D5E0
    // 0x8000D540: nop

        goto L_8000D5E0;
    // 0x8000D540: nop

L_8000D544:
    // 0x8000D544: lb          $t8, -0x4D5B($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X4D5B);
    // 0x8000D548: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x8000D54C: sll         $t5, $t8, 1
    ctx->r13 = S32(ctx->r24 << 1);
    // 0x8000D550: addu        $fp, $fp, $t5
    ctx->r30 = ADD32(ctx->r30, ctx->r13);
    // 0x8000D554: lb          $fp, -0x326F($fp)
    ctx->r30 = MEM_B(ctx->r30, -0X326F);
    // 0x8000D558: b           L_8000D5E0
    // 0x8000D55C: nop

        goto L_8000D5E0;
    // 0x8000D55C: nop

L_8000D560:
    // 0x8000D560: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000D564: bne         $v0, $at, L_8000D580
    if (ctx->r2 != ctx->r1) {
        // 0x8000D568: nop
    
            goto L_8000D580;
    }
    // 0x8000D568: nop

    // 0x8000D56C: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x8000D570: nop

    // 0x8000D574: lb          $fp, 0x4D($t9)
    ctx->r30 = MEM_B(ctx->r25, 0X4D);
    // 0x8000D578: b           L_8000D5E0
    // 0x8000D57C: nop

        goto L_8000D5E0;
    // 0x8000D57C: nop

L_8000D580:
    // 0x8000D580: lh          $t6, 0xE($s6)
    ctx->r14 = MEM_H(ctx->r22, 0XE);
    // 0x8000D584: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8000D588: beq         $t6, $at, L_8000D5A4
    if (ctx->r14 == ctx->r1) {
        // 0x8000D58C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8000D5A4;
    }
    // 0x8000D58C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000D590: jal         0x8006C3DC
    // 0x8000D594: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    race_is_adventure_2P(rdram, ctx);
        goto after_12;
    // 0x8000D594: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    after_12:
    // 0x8000D598: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x8000D59C: beq         $v0, $zero, L_8000D5B8
    if (ctx->r2 == 0) {
        // 0x8000D5A0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8000D5B8;
    }
    // 0x8000D5A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8000D5A4:
    // 0x8000D5A4: jal         0x8009C794
    // 0x8000D5A8: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    get_player_selected_vehicle(rdram, ctx);
        goto after_13;
    // 0x8000D5A8: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    after_13:
    // 0x8000D5AC: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x8000D5B0: b           L_8000D5E0
    // 0x8000D5B4: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
        goto L_8000D5E0;
    // 0x8000D5B4: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
L_8000D5B8:
    // 0x8000D5B8: lw          $t7, 0x144($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X144);
    // 0x8000D5BC: nop

    // 0x8000D5C0: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x8000D5C4: bne         $at, $zero, L_8000D5E0
    if (ctx->r1 != 0) {
        // 0x8000D5C8: nop
    
            goto L_8000D5E0;
    }
    // 0x8000D5C8: nop

    // 0x8000D5CC: lh          $a0, 0xE($s6)
    ctx->r4 = MEM_H(ctx->r22, 0XE);
    // 0x8000D5D0: jal         0x8009C794
    // 0x8000D5D4: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    get_player_selected_vehicle(rdram, ctx);
        goto after_14;
    // 0x8000D5D4: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    after_14:
    // 0x8000D5D8: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x8000D5DC: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
L_8000D5E0:
    // 0x8000D5E0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8000D5E4: lb          $t8, -0x4D44($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X4D44);
    // 0x8000D5E8: lh          $v1, 0xE($s6)
    ctx->r3 = MEM_H(ctx->r22, 0XE);
    // 0x8000D5EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000D5F0: bne         $t8, $at, L_8000D634
    if (ctx->r24 != ctx->r1) {
        // 0x8000D5F4: lui         $t5, 0x800E
        ctx->r13 = S32(0X800E << 16);
            goto L_8000D634;
    }
    // 0x8000D5F4: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8000D5F8: addu        $t5, $t5, $s0
    ctx->r13 = ADD32(ctx->r13, ctx->r16);
    // 0x8000D5FC: lb          $t5, -0x3250($t5)
    ctx->r13 = MEM_B(ctx->r13, -0X3250);
    // 0x8000D600: sll         $t6, $fp, 2
    ctx->r14 = S32(ctx->r30 << 2);
    // 0x8000D604: addu        $t6, $t6, $fp
    ctx->r14 = ADD32(ctx->r14, ctx->r30);
    // 0x8000D608: sll         $t9, $t5, 1
    ctx->r25 = S32(ctx->r13 << 1);
    // 0x8000D60C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8000D610: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x8000D614: sll         $t5, $s4, 2
    ctx->r13 = S32(ctx->r20 << 2);
    // 0x8000D618: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000D61C: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x8000D620: subu        $t5, $t5, $s4
    ctx->r13 = SUB32(ctx->r13, ctx->r20);
    // 0x8000D624: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8000D628: lh          $v0, -0x32E8($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X32E8);
    // 0x8000D62C: b           L_8000D698
    // 0x8000D630: addu        $a3, $s7, $t5
    ctx->r7 = ADD32(ctx->r23, ctx->r13);
        goto L_8000D698;
    // 0x8000D630: addu        $a3, $s7, $t5
    ctx->r7 = ADD32(ctx->r23, ctx->r13);
L_8000D634:
    // 0x8000D634: slti        $at, $fp, 0x5
    ctx->r1 = SIGNED(ctx->r30) < 0X5 ? 1 : 0;
    // 0x8000D638: beq         $at, $zero, L_8000D67C
    if (ctx->r1 == 0) {
        // 0x8000D63C: sll         $t9, $fp, 1
        ctx->r25 = S32(ctx->r30 << 1);
            goto L_8000D67C;
    }
    // 0x8000D63C: sll         $t9, $fp, 1
    ctx->r25 = S32(ctx->r30 << 1);
    // 0x8000D640: multu       $s4, $s5
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000D644: sll         $t8, $fp, 2
    ctx->r24 = S32(ctx->r30 << 2);
    // 0x8000D648: addu        $t8, $t8, $fp
    ctx->r24 = ADD32(ctx->r24, ctx->r30);
    // 0x8000D64C: sll         $t5, $t8, 2
    ctx->r13 = S32(ctx->r24 << 2);
    // 0x8000D650: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000D654: mflo        $t6
    ctx->r14 = lo;
    // 0x8000D658: addu        $a3, $s7, $t6
    ctx->r7 = ADD32(ctx->r23, ctx->r14);
    // 0x8000D65C: lb          $t9, 0x59($a3)
    ctx->r25 = MEM_B(ctx->r7, 0X59);
    // 0x8000D660: nop

    // 0x8000D664: sll         $t7, $t9, 1
    ctx->r15 = S32(ctx->r25 << 1);
    // 0x8000D668: addu        $t6, $t7, $t5
    ctx->r14 = ADD32(ctx->r15, ctx->r13);
    // 0x8000D66C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8000D670: lh          $v0, -0x32E8($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X32E8);
    // 0x8000D674: b           L_8000D69C
    // 0x8000D678: andi        $t7, $v0, 0x100
    ctx->r15 = ctx->r2 & 0X100;
        goto L_8000D69C;
    // 0x8000D678: andi        $t7, $v0, 0x100
    ctx->r15 = ctx->r2 & 0X100;
L_8000D67C:
    // 0x8000D67C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000D680: sll         $t8, $s4, 2
    ctx->r24 = S32(ctx->r20 << 2);
    // 0x8000D684: subu        $t8, $t8, $s4
    ctx->r24 = SUB32(ctx->r24, ctx->r20);
    // 0x8000D688: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x8000D68C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8000D690: lh          $v0, -0x328E($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X328E);
    // 0x8000D694: addu        $a3, $s7, $t8
    ctx->r7 = ADD32(ctx->r23, ctx->r24);
L_8000D698:
    // 0x8000D698: andi        $t7, $v0, 0x100
    ctx->r15 = ctx->r2 & 0X100;
L_8000D69C:
    // 0x8000D69C: sra         $t5, $t7, 1
    ctx->r13 = S32(SIGNED(ctx->r15) >> 1);
    // 0x8000D6A0: ori         $t6, $t5, 0x10
    ctx->r14 = ctx->r13 | 0X10;
    // 0x8000D6A4: sb          $v0, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r2;
    // 0x8000D6A8: sb          $t6, 0x1($s6)
    MEM_B(0X1, ctx->r22) = ctx->r14;
    // 0x8000D6AC: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x8000D6B0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8000D6B4: sh          $t9, 0x2($s6)
    MEM_H(0X2, ctx->r22) = ctx->r25;
    // 0x8000D6B8: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x8000D6BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8000D6C0: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x8000D6C4: nop

    // 0x8000D6C8: sh          $t7, 0x4($s6)
    MEM_H(0X4, ctx->r22) = ctx->r15;
    // 0x8000D6CC: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x8000D6D0: nop

    // 0x8000D6D4: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8000D6D8: nop

    // 0x8000D6DC: sh          $t6, 0x6($s6)
    MEM_H(0X6, ctx->r22) = ctx->r14;
    // 0x8000D6E0: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8000D6E4: nop

    // 0x8000D6E8: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x8000D6EC: bne         $v1, $at, L_8000D710
    if (ctx->r3 != ctx->r1) {
        // 0x8000D6F0: sh          $t8, 0xC($s6)
        MEM_H(0XC, ctx->r22) = ctx->r24;
            goto L_8000D710;
    }
    // 0x8000D6F0: sh          $t8, 0xC($s6)
    MEM_H(0XC, ctx->r22) = ctx->r24;
    // 0x8000D6F4: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    // 0x8000D6F8: jal         0x80061C34
    // 0x8000D6FC: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    model_anim_offset(rdram, ctx);
        goto after_15;
    // 0x8000D6FC: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    after_15:
    // 0x8000D700: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x8000D704: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x8000D708: lh          $v1, 0xE($s6)
    ctx->r3 = MEM_H(ctx->r22, 0XE);
    // 0x8000D70C: nop

L_8000D710:
    // 0x8000D710: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8000D714: bne         $v1, $at, L_8000D734
    if (ctx->r3 != ctx->r1) {
        // 0x8000D718: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8000D734;
    }
    // 0x8000D718: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000D71C: lw          $t7, 0x144($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X144);
    // 0x8000D720: addiu       $s1, $zero, 0x5
    ctx->r17 = ADD32(0, 0X5);
    // 0x8000D724: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x8000D728: bne         $at, $zero, L_8000D734
    if (ctx->r1 != 0) {
        // 0x8000D72C: ori         $t5, $s1, 0x8
        ctx->r13 = ctx->r17 | 0X8;
            goto L_8000D734;
    }
    // 0x8000D72C: ori         $t5, $s1, 0x8
    ctx->r13 = ctx->r17 | 0X8;
    // 0x8000D730: or          $s1, $t5, $zero
    ctx->r17 = ctx->r13 | 0;
L_8000D734:
    // 0x8000D734: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8000D738: beq         $v1, $at, L_8000D758
    if (ctx->r3 == ctx->r1) {
        // 0x8000D73C: slti        $at, $fp, 0x5
        ctx->r1 = SIGNED(ctx->r30) < 0X5 ? 1 : 0;
            goto L_8000D758;
    }
    // 0x8000D73C: slti        $at, $fp, 0x5
    ctx->r1 = SIGNED(ctx->r30) < 0X5 ? 1 : 0;
    // 0x8000D740: lw          $t6, 0x144($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X144);
    // 0x8000D744: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000D748: bne         $t6, $at, L_8000D754
    if (ctx->r14 != ctx->r1) {
        // 0x8000D74C: ori         $t9, $s1, 0x10
        ctx->r25 = ctx->r17 | 0X10;
            goto L_8000D754;
    }
    // 0x8000D74C: ori         $t9, $s1, 0x10
    ctx->r25 = ctx->r17 | 0X10;
    // 0x8000D750: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
L_8000D754:
    // 0x8000D754: slti        $at, $fp, 0x5
    ctx->r1 = SIGNED(ctx->r30) < 0X5 ? 1 : 0;
L_8000D758:
    // 0x8000D758: bne         $at, $zero, L_8000D77C
    if (ctx->r1 != 0) {
        // 0x8000D75C: nop
    
            goto L_8000D77C;
    }
    // 0x8000D75C: nop

    // 0x8000D760: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x8000D764: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    // 0x8000D768: jal         0x80061C34
    // 0x8000D76C: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    model_anim_offset(rdram, ctx);
        goto after_16;
    // 0x8000D76C: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    after_16:
    // 0x8000D770: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x8000D774: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x8000D778: nop

L_8000D77C:
    // 0x8000D77C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8000D780: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8000D784: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    // 0x8000D788: jal         0x8000EA54
    // 0x8000D78C: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    spawn_object(rdram, ctx);
        goto after_17;
    // 0x8000D78C: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    after_17:
    // 0x8000D790: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x8000D794: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x8000D798: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x8000D79C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x8000D7A0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8000D7A4: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x8000D7A8: lw          $t5, -0x4B9C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4B9C);
    // 0x8000D7AC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8000D7B0: addu        $t6, $t5, $a2
    ctx->r14 = ADD32(ctx->r13, ctx->r6);
    // 0x8000D7B4: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x8000D7B8: lw          $t9, -0x4B98($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4B98);
    // 0x8000D7BC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8000D7C0: addu        $t8, $t9, $a2
    ctx->r24 = ADD32(ctx->r25, ctx->r6);
    // 0x8000D7C4: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    // 0x8000D7C8: lw          $t7, -0x4B94($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4B94);
    // 0x8000D7CC: sll         $t5, $s4, 2
    ctx->r13 = S32(ctx->r20 << 2);
    // 0x8000D7D0: addu        $t6, $t7, $t5
    ctx->r14 = ADD32(ctx->r15, ctx->r13);
    // 0x8000D7D4: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x8000D7D8: lw          $s3, 0x64($v0)
    ctx->r19 = MEM_W(ctx->r2, 0X64);
    // 0x8000D7DC: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x8000D7E0: sb          $fp, 0x1D6($s3)
    MEM_B(0X1D6, ctx->r19) = ctx->r30;
    // 0x8000D7E4: sb          $fp, 0x1D7($s3)
    MEM_B(0X1D7, ctx->r19) = ctx->r30;
    // 0x8000D7E8: lb          $t9, 0x127($sp)
    ctx->r25 = MEM_B(ctx->r29, 0X127);
    // 0x8000D7EC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000D7F0: beq         $t9, $at, L_8000D808
    if (ctx->r25 == ctx->r1) {
        // 0x8000D7F4: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_8000D808;
    }
    // 0x8000D7F4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8000D7F8: beq         $t9, $fp, L_8000D808
    if (ctx->r25 == ctx->r30) {
        // 0x8000D7FC: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8000D808;
    }
    // 0x8000D7FC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8000D800: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000D804: sb          $t8, -0x4D60($at)
    MEM_B(-0X4D60, ctx->r1) = ctx->r24;
L_8000D808:
    // 0x8000D808: sb          $fp, 0x127($sp)
    MEM_B(0X127, ctx->r29) = ctx->r30;
    // 0x8000D80C: lb          $v0, 0x1D6($s3)
    ctx->r2 = MEM_B(ctx->r19, 0X1D6);
    // 0x8000D810: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000D814: beq         $v0, $at, L_8000D82C
    if (ctx->r2 == ctx->r1) {
        // 0x8000D818: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8000D82C;
    }
    // 0x8000D818: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8000D81C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8000D820: beq         $v0, $at, L_8000D82C
    if (ctx->r2 == ctx->r1) {
        // 0x8000D824: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_8000D82C;
    }
    // 0x8000D824: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8000D828: bne         $v0, $at, L_8000D834
    if (ctx->r2 != ctx->r1) {
        // 0x8000D82C: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8000D834;
    }
L_8000D82C:
    // 0x8000D82C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000D830: sb          $t7, -0x4C7E($at)
    MEM_B(-0X4C7E, ctx->r1) = ctx->r15;
L_8000D834:
    // 0x8000D834: sb          $fp, 0x1CB($s3)
    MEM_B(0X1CB, ctx->r19) = ctx->r30;
    // 0x8000D838: lb          $v0, 0x1CB($s3)
    ctx->r2 = MEM_B(ctx->r19, 0X1CB);
    // 0x8000D83C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8000D840: bltz        $v0, L_8000D850
    if (SIGNED(ctx->r2) < 0) {
        // 0x8000D844: slti        $at, $v0, 0x3
        ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
            goto L_8000D850;
    }
    // 0x8000D844: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8000D848: bne         $at, $zero, L_8000D854
    if (ctx->r1 != 0) {
        // 0x8000D84C: nop
    
            goto L_8000D854;
    }
    // 0x8000D84C: nop

L_8000D850:
    // 0x8000D850: sb          $zero, 0x1CB($s3)
    MEM_B(0X1CB, ctx->r19) = 0;
L_8000D854:
    // 0x8000D854: sb          $s4, 0x2($s3)
    MEM_B(0X2, ctx->r19) = ctx->r20;
    // 0x8000D858: lb          $t5, 0x59($a3)
    ctx->r13 = MEM_B(ctx->r7, 0X59);
    // 0x8000D85C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8000D860: sb          $t5, 0x3($s3)
    MEM_B(0X3, ctx->r19) = ctx->r13;
    // 0x8000D864: lb          $t6, -0x4D44($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X4D44);
    // 0x8000D868: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000D86C: bne         $t6, $at, L_8000D880
    if (ctx->r14 != ctx->r1) {
        // 0x8000D870: addu        $t9, $t9, $s0
        ctx->r25 = ADD32(ctx->r25, ctx->r16);
            goto L_8000D880;
    }
    // 0x8000D870: addu        $t9, $t9, $s0
    ctx->r25 = ADD32(ctx->r25, ctx->r16);
    // 0x8000D874: lb          $t9, -0x3250($t9)
    ctx->r25 = MEM_B(ctx->r25, -0X3250);
    // 0x8000D878: b           L_8000D88C
    // 0x8000D87C: sb          $t9, 0x3($s3)
    MEM_B(0X3, ctx->r19) = ctx->r25;
        goto L_8000D88C;
    // 0x8000D87C: sb          $t9, 0x3($s3)
    MEM_B(0X3, ctx->r19) = ctx->r25;
L_8000D880:
    // 0x8000D880: lb          $t8, 0x59($a3)
    ctx->r24 = MEM_B(ctx->r7, 0X59);
    // 0x8000D884: nop

    // 0x8000D888: sb          $t8, 0x3($s3)
    MEM_B(0X3, ctx->r19) = ctx->r24;
L_8000D88C:
    // 0x8000D88C: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x8000D890: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8000D894: bne         $t7, $at, L_8000D8A4
    if (ctx->r15 != ctx->r1) {
        // 0x8000D898: addiu       $t5, $zero, 0x8
        ctx->r13 = ADD32(0, 0X8);
            goto L_8000D8A4;
    }
    // 0x8000D898: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x8000D89C: b           L_8000D8A8
    // 0x8000D8A0: sb          $t5, 0x185($s3)
    MEM_B(0X185, ctx->r19) = ctx->r13;
        goto L_8000D8A8;
    // 0x8000D8A0: sb          $t5, 0x185($s3)
    MEM_B(0X185, ctx->r19) = ctx->r13;
L_8000D8A4:
    // 0x8000D8A4: sb          $zero, 0x185($s3)
    MEM_B(0X185, ctx->r19) = 0;
L_8000D8A8:
    // 0x8000D8A8: jal         0x8009C850
    // 0x8000D8AC: nop

    get_filtered_cheats(rdram, ctx);
        goto after_18;
    // 0x8000D8AC: nop

    after_18:
    // 0x8000D8B0: andi        $t6, $v0, 0x80
    ctx->r14 = ctx->r2 & 0X80;
    // 0x8000D8B4: beq         $t6, $zero, L_8000D8E4
    if (ctx->r14 == 0) {
        // 0x8000D8B8: lw          $t5, 0x138($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X138);
            goto L_8000D8E4;
    }
    // 0x8000D8B8: lw          $t5, 0x138($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X138);
    // 0x8000D8BC: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x8000D8C0: nop

    // 0x8000D8C4: bne         $t9, $zero, L_8000D8E4
    if (ctx->r25 != 0) {
        // 0x8000D8C8: lw          $t5, 0x138($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X138);
            goto L_8000D8E4;
    }
    // 0x8000D8C8: lw          $t5, 0x138($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X138);
    // 0x8000D8CC: lh          $t8, 0x0($s3)
    ctx->r24 = MEM_H(ctx->r19, 0X0);
    // 0x8000D8D0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000D8D4: beq         $t8, $at, L_8000D8E0
    if (ctx->r24 == ctx->r1) {
        // 0x8000D8D8: addiu       $t7, $zero, 0xA
        ctx->r15 = ADD32(0, 0XA);
            goto L_8000D8E0;
    }
    // 0x8000D8D8: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x8000D8DC: sb          $t7, 0x185($s3)
    MEM_B(0X185, ctx->r19) = ctx->r15;
L_8000D8E0:
    // 0x8000D8E0: lw          $t5, 0x138($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X138);
L_8000D8E4:
    // 0x8000D8E4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000D8E8: bne         $t5, $at, L_8000D8FC
    if (ctx->r13 != ctx->r1) {
        // 0x8000D8EC: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8000D8FC;
    }
    // 0x8000D8EC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8000D8F0: lb          $t6, -0x4D44($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X4D44);
    // 0x8000D8F4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000D8F8: bne         $t6, $at, L_8000D920
    if (ctx->r14 != ctx->r1) {
        // 0x8000D8FC: slti        $at, $fp, 0x5
        ctx->r1 = SIGNED(ctx->r30) < 0X5 ? 1 : 0;
            goto L_8000D920;
    }
L_8000D8FC:
    // 0x8000D8FC: slti        $at, $fp, 0x5
    ctx->r1 = SIGNED(ctx->r30) < 0X5 ? 1 : 0;
    // 0x8000D900: beq         $at, $zero, L_8000D920
    if (ctx->r1 == 0) {
        // 0x8000D904: nop
    
            goto L_8000D920;
    }
    // 0x8000D904: nop

    // 0x8000D908: lb          $a0, 0x3($s3)
    ctx->r4 = MEM_B(ctx->r19, 0X3);
    // 0x8000D90C: lb          $a1, 0x1D6($s3)
    ctx->r5 = MEM_B(ctx->r19, 0X1D6);
    // 0x8000D910: jal         0x80004B40
    // 0x8000D914: nop

    racer_sound_init(rdram, ctx);
        goto after_19;
    // 0x8000D914: nop

    after_19:
    // 0x8000D918: b           L_8000D924
    // 0x8000D91C: sw          $v0, 0x118($s3)
    MEM_W(0X118, ctx->r19) = ctx->r2;
        goto L_8000D924;
    // 0x8000D91C: sw          $v0, 0x118($s3)
    MEM_W(0X118, ctx->r19) = ctx->r2;
L_8000D920:
    // 0x8000D920: sw          $zero, 0x118($s3)
    MEM_W(0X118, ctx->r19) = 0;
L_8000D924:
    // 0x8000D924: lb          $t9, 0x3($s3)
    ctx->r25 = MEM_B(ctx->r19, 0X3);
    // 0x8000D928: lw          $t8, 0x128($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X128);
    // 0x8000D92C: nop

    // 0x8000D930: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x8000D934: lb          $t5, 0x0($t7)
    ctx->r13 = MEM_B(ctx->r15, 0X0);
    // 0x8000D938: lw          $t9, 0x4C($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4C);
    // 0x8000D93C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8000D940: sb          $t6, 0x12($t9)
    MEM_B(0X12, ctx->r25) = ctx->r14;
    // 0x8000D944: lb          $t8, 0x1D6($s3)
    ctx->r24 = MEM_B(ctx->r19, 0X1D6);
    // 0x8000D948: nop

    // 0x8000D94C: addiu       $t7, $t8, -0x5
    ctx->r15 = ADD32(ctx->r24, -0X5);
    // 0x8000D950: sltiu       $at, $t7, 0x9
    ctx->r1 = ctx->r15 < 0X9 ? 1 : 0;
    // 0x8000D954: beq         $at, $zero, L_8000D98C
    if (ctx->r1 == 0) {
        // 0x8000D958: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8000D98C;
    }
    // 0x8000D958: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8000D95C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000D960: addu        $at, $at, $t7
    gpr jr_addend_8000D96C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8000D964: lw          $t7, 0x56E4($at)
    ctx->r15 = ADD32(ctx->r1, 0X56E4);
    // 0x8000D968: nop

    // 0x8000D96C: jr          $t7
    // 0x8000D970: nop

    switch (jr_addend_8000D96C >> 2) {
        case 0: goto L_8000D974; break;
        case 1: goto L_8000D974; break;
        case 2: goto L_8000D974; break;
        case 3: goto L_8000D974; break;
        case 4: goto L_8000D974; break;
        case 5: goto L_8000D98C; break;
        case 6: goto L_8000D974; break;
        case 7: goto L_8000D974; break;
        case 8: goto L_8000D974; break;
        default: switch_error(__func__, 0x8000D96C, 0x800E56E4);
    }
    // 0x8000D970: nop

L_8000D974:
    // 0x8000D974: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8000D978: jal         0x8005C490
    // 0x8000D97C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    racer_special_init(rdram, ctx);
        goto after_20;
    // 0x8000D97C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_20:
    // 0x8000D980: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x8000D984: b           L_8000D994
    // 0x8000D988: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_8000D994;
    // 0x8000D988: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_8000D98C:
    // 0x8000D98C: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x8000D990: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_8000D994:
    // 0x8000D994: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000D998: lw          $v1, -0x4B90($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4B90);
    // 0x8000D99C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000D9A0: slt         $at, $s0, $v1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000D9A4: bne         $at, $zero, L_8000D440
    if (ctx->r1 != 0) {
        // 0x8000D9A8: nop
    
            goto L_8000D440;
    }
    // 0x8000D9A8: nop

L_8000D9AC:
    // 0x8000D9AC: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x8000D9B0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8000D9B4: beq         $a0, $at, L_8000D9C4
    if (ctx->r4 == ctx->r1) {
        // 0x8000D9B8: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_8000D9C4;
    }
    // 0x8000D9B8: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8000D9BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000D9C0: sb          $zero, -0x4D44($at)
    MEM_B(-0X4D44, ctx->r1) = 0;
L_8000D9C4:
    // 0x8000D9C4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8000D9C8: lb          $t5, -0x4D44($t5)
    ctx->r13 = MEM_B(ctx->r13, -0X4D44);
    // 0x8000D9CC: nop

    // 0x8000D9D0: beq         $t5, $zero, L_8000D9DC
    if (ctx->r13 == 0) {
        // 0x8000D9D4: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8000D9DC;
    }
    // 0x8000D9D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000D9D8: sb          $zero, -0x4D60($at)
    MEM_B(-0X4D60, ctx->r1) = 0;
L_8000D9DC:
    // 0x8000D9DC: jal         0x8006DC4C
    // 0x8000D9E0: nop

    get_game_mode(rdram, ctx);
        goto after_21;
    // 0x8000D9E0: nop

    after_21:
    // 0x8000D9E4: bne         $v0, $zero, L_8000DA9C
    if (ctx->r2 != 0) {
        // 0x8000D9E8: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_8000DA9C;
    }
    // 0x8000D9E8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000D9EC: lw          $v0, -0x4C24($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4C24);
    // 0x8000D9F0: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8000D9F4: blez        $v0, L_8000DA9C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8000D9F8: lui         $s3, 0x8012
        ctx->r19 = S32(0X8012 << 16);
            goto L_8000DA9C;
    }
    // 0x8000D9F8: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8000D9FC: addiu       $s3, $s3, -0x4C28
    ctx->r19 = ADD32(ctx->r19, -0X4C28);
L_8000DA00:
    // 0x8000DA00: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x8000DA04: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8000DA08: addu        $t9, $t6, $s5
    ctx->r25 = ADD32(ctx->r14, ctx->r21);
    // 0x8000DA0C: lw          $s1, 0x0($t9)
    ctx->r17 = MEM_W(ctx->r25, 0X0);
    // 0x8000DA10: nop

    // 0x8000DA14: lw          $t8, 0x40($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X40);
    // 0x8000DA18: nop

    // 0x8000DA1C: lhu         $s0, 0x30($t8)
    ctx->r16 = MEM_HU(ctx->r24, 0X30);
    // 0x8000DA20: nop

    // 0x8000DA24: andi        $t7, $s0, 0x20
    ctx->r15 = ctx->r16 & 0X20;
    // 0x8000DA28: beq         $t7, $zero, L_8000DA58
    if (ctx->r15 == 0) {
        // 0x8000DA2C: andi        $t6, $s0, 0x40
        ctx->r14 = ctx->r16 & 0X40;
            goto L_8000DA58;
    }
    // 0x8000DA2C: andi        $t6, $s0, 0x40
    ctx->r14 = ctx->r16 & 0X40;
    // 0x8000DA30: lbu         $t5, -0x4B8B($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X4B8B);
    // 0x8000DA34: nop

    // 0x8000DA38: beq         $t5, $zero, L_8000DA58
    if (ctx->r13 == 0) {
        // 0x8000DA3C: nop
    
            goto L_8000DA58;
    }
    // 0x8000DA3C: nop

    // 0x8000DA40: jal         0x8000FFB8
    // 0x8000DA44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    free_object(rdram, ctx);
        goto after_22;
    // 0x8000DA44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_22:
    // 0x8000DA48: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000DA4C: lw          $v0, -0x4C24($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4C24);
    // 0x8000DA50: b           L_8000DA8C
    // 0x8000DA54: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_8000DA8C;
    // 0x8000DA54: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8000DA58:
    // 0x8000DA58: beq         $t6, $zero, L_8000DA88
    if (ctx->r14 == 0) {
        // 0x8000DA5C: nop
    
            goto L_8000DA88;
    }
    // 0x8000DA5C: nop

    // 0x8000DA60: lw          $t9, 0x144($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X144);
    // 0x8000DA64: nop

    // 0x8000DA68: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x8000DA6C: bne         $at, $zero, L_8000DA88
    if (ctx->r1 != 0) {
        // 0x8000DA70: nop
    
            goto L_8000DA88;
    }
    // 0x8000DA70: nop

    // 0x8000DA74: jal         0x8000FFB8
    // 0x8000DA78: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    free_object(rdram, ctx);
        goto after_23;
    // 0x8000DA78: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_23:
    // 0x8000DA7C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000DA80: lw          $v0, -0x4C24($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4C24);
    // 0x8000DA84: nop

L_8000DA88:
    // 0x8000DA88: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8000DA8C:
    // 0x8000DA8C: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8000DA90: bne         $at, $zero, L_8000DA00
    if (ctx->r1 != 0) {
        // 0x8000DA94: addiu       $s5, $s5, 0x4
        ctx->r21 = ADD32(ctx->r21, 0X4);
            goto L_8000DA00;
    }
    // 0x8000DA94: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x8000DA98: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8000DA9C:
    // 0x8000DA9C: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x8000DAA0: addiu       $s5, $s5, -0x3378
    ctx->r21 = ADD32(ctx->r21, -0X3378);
    // 0x8000DAA4: jal         0x80059B9C
    // 0x8000DAA8: sw          $zero, 0x0($s5)
    MEM_W(0X0, ctx->r21) = 0;
    timetrial_free_staff_ghost(rdram, ctx);
        goto after_24;
    // 0x8000DAA8: sw          $zero, 0x0($s5)
    MEM_W(0X0, ctx->r21) = 0;
    after_24:
    // 0x8000DAAC: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8000DAB0: addiu       $s1, $s1, -0x4D48
    ctx->r17 = ADD32(ctx->r17, -0X4D48);
    // 0x8000DAB4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8000DAB8: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x8000DABC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8000DAC0: lbu         $t7, -0x4B8B($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X4B8B);
    // 0x8000DAC4: nop

    // 0x8000DAC8: beq         $t7, $zero, L_8000DC90
    if (ctx->r15 == 0) {
        // 0x8000DACC: nop
    
            goto L_8000DC90;
    }
    // 0x8000DACC: nop

    // 0x8000DAD0: lw          $t5, 0x144($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X144);
    // 0x8000DAD4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000DAD8: bne         $t5, $at, L_8000DC90
    if (ctx->r13 != ctx->r1) {
        // 0x8000DADC: nop
    
            goto L_8000DC90;
    }
    // 0x8000DADC: nop

    // 0x8000DAE0: jal         0x80059994
    // 0x8000DAE4: nop

    timetrial_reset_player_ghost(rdram, ctx);
        goto after_25;
    // 0x8000DAE4: nop

    after_25:
    // 0x8000DAE8: jal         0x8001B69C
    // 0x8000DAEC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    timetrial_init_player_ghost(rdram, ctx);
        goto after_26;
    // 0x8000DAEC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_26:
    // 0x8000DAF0: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8000DAF4: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8000DAF8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000DAFC: addiu       $s0, $s0, -0x3368
    ctx->r16 = ADD32(ctx->r16, -0X3368);
    // 0x8000DB00: sb          $zero, -0x3360($at)
    MEM_B(-0X3360, ctx->r1) = 0;
    // 0x8000DB04: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x8000DB08: nop

    // 0x8000DB0C: slti        $at, $t6, 0x5
    ctx->r1 = SIGNED(ctx->r14) < 0X5 ? 1 : 0;
    // 0x8000DB10: bne         $at, $zero, L_8000DB1C
    if (ctx->r1 != 0) {
        // 0x8000DB14: nop
    
            goto L_8000DB1C;
    }
    // 0x8000DB14: nop

    // 0x8000DB18: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
L_8000DB1C:
    // 0x8000DB1C: jal         0x8001B2BC
    // 0x8000DB20: nop

    timetrial_valid_player_ghost(rdram, ctx);
        goto after_27;
    // 0x8000DB20: nop

    after_27:
    // 0x8000DB24: beq         $v0, $zero, L_8000DBD8
    if (ctx->r2 == 0) {
        // 0x8000DB28: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_8000DBD8;
    }
    // 0x8000DB28: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8000DB2C: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x8000DB30: lh          $t9, -0x3364($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X3364);
    // 0x8000DB34: sll         $t5, $t7, 2
    ctx->r13 = S32(ctx->r15 << 2);
    // 0x8000DB38: addu        $t5, $t5, $t7
    ctx->r13 = ADD32(ctx->r13, ctx->r15);
    // 0x8000DB3C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8000DB40: sll         $t8, $t9, 1
    ctx->r24 = S32(ctx->r25 << 1);
    // 0x8000DB44: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x8000DB48: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000DB4C: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x8000DB50: lh          $v0, -0x32E8($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X32E8);
    // 0x8000DB54: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8000DB58: andi        $t7, $v0, 0x100
    ctx->r15 = ctx->r2 & 0X100;
    // 0x8000DB5C: sra         $t5, $t7, 1
    ctx->r13 = S32(SIGNED(ctx->r15) >> 1);
    // 0x8000DB60: ori         $t8, $t5, 0x10
    ctx->r24 = ctx->r13 | 0X10;
    // 0x8000DB64: sb          $t8, 0x1($s6)
    MEM_B(0X1, ctx->r22) = ctx->r24;
    // 0x8000DB68: sb          $v0, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r2;
    // 0x8000DB6C: lw          $t6, 0xF4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF4);
    // 0x8000DB70: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8000DB74: sh          $t6, 0x2($s6)
    MEM_H(0X2, ctx->r22) = ctx->r14;
    // 0x8000DB78: lw          $t9, 0xD4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD4);
    // 0x8000DB7C: nop

    // 0x8000DB80: sh          $t9, 0x4($s6)
    MEM_H(0X4, ctx->r22) = ctx->r25;
    // 0x8000DB84: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x8000DB88: nop

    // 0x8000DB8C: sh          $t7, 0x6($s6)
    MEM_H(0X6, ctx->r22) = ctx->r15;
    // 0x8000DB90: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    // 0x8000DB94: jal         0x8000EA54
    // 0x8000DB98: sh          $t5, 0xC($s6)
    MEM_H(0XC, ctx->r22) = ctx->r13;
    spawn_object(rdram, ctx);
        goto after_28;
    // 0x8000DB98: sh          $t5, 0xC($s6)
    MEM_H(0XC, ctx->r22) = ctx->r13;
    after_28:
    // 0x8000DB9C: addiu       $t8, $zero, 0x3A
    ctx->r24 = ADD32(0, 0X3A);
    // 0x8000DBA0: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x8000DBA4: sh          $t8, 0x48($v0)
    MEM_H(0X48, ctx->r2) = ctx->r24;
    // 0x8000DBA8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000DBAC: lwc1        $f4, 0x5708($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5708);
    // 0x8000DBB0: lw          $t6, 0x50($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X50);
    // 0x8000DBB4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000DBB8: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
    // 0x8000DBBC: lw          $t9, 0x4C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4C);
    // 0x8000DBC0: addiu       $v1, $v1, -0x4D4C
    ctx->r3 = ADD32(ctx->r3, -0X4D4C);
    // 0x8000DBC4: sh          $zero, 0x14($t9)
    MEM_H(0X14, ctx->r25) = 0;
    // 0x8000DBC8: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000DBCC: lw          $s3, 0x64($v0)
    ctx->r19 = MEM_W(ctx->r2, 0X64);
    // 0x8000DBD0: addiu       $t5, $zero, 0x60
    ctx->r13 = ADD32(0, 0X60);
    // 0x8000DBD4: sb          $t5, 0x1F7($s3)
    MEM_B(0X1F7, ctx->r19) = ctx->r13;
L_8000DBD8:
    // 0x8000DBD8: jal         0x8006BFC8
    // 0x8000DBDC: nop

    level_id(rdram, ctx);
        goto after_29;
    // 0x8000DBDC: nop

    after_29:
    // 0x8000DBE0: jal         0x8001B530
    // 0x8000DBE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    timetrial_init_staff_ghost(rdram, ctx);
        goto after_30;
    // 0x8000DBE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_30:
    // 0x8000DBE8: beq         $v0, $zero, L_8000DC90
    if (ctx->r2 == 0) {
        // 0x8000DBEC: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_8000DC90;
    }
    // 0x8000DBEC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8000DBF0: lh          $t8, -0x4BFC($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X4BFC);
    // 0x8000DBF4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000DBF8: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x8000DBFC: addu        $t6, $t6, $t8
    ctx->r14 = ADD32(ctx->r14, ctx->r24);
    // 0x8000DC00: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x8000DC04: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x8000DC08: lh          $v0, -0x32D8($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X32D8);
    // 0x8000DC0C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8000DC10: andi        $t7, $v0, 0x100
    ctx->r15 = ctx->r2 & 0X100;
    // 0x8000DC14: sra         $t5, $t7, 1
    ctx->r13 = S32(SIGNED(ctx->r15) >> 1);
    // 0x8000DC18: ori         $t8, $t5, 0x10
    ctx->r24 = ctx->r13 | 0X10;
    // 0x8000DC1C: sb          $t8, 0x1($s6)
    MEM_B(0X1, ctx->r22) = ctx->r24;
    // 0x8000DC20: sb          $v0, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r2;
    // 0x8000DC24: lw          $t6, 0xF4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF4);
    // 0x8000DC28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8000DC2C: sh          $t6, 0x2($s6)
    MEM_H(0X2, ctx->r22) = ctx->r14;
    // 0x8000DC30: lw          $t9, 0xD4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD4);
    // 0x8000DC34: nop

    // 0x8000DC38: sh          $t9, 0x4($s6)
    MEM_H(0X4, ctx->r22) = ctx->r25;
    // 0x8000DC3C: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x8000DC40: nop

    // 0x8000DC44: sh          $t7, 0x6($s6)
    MEM_H(0X6, ctx->r22) = ctx->r15;
    // 0x8000DC48: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    // 0x8000DC4C: jal         0x8000EA54
    // 0x8000DC50: sh          $t5, 0xC($s6)
    MEM_H(0XC, ctx->r22) = ctx->r13;
    spawn_object(rdram, ctx);
        goto after_31;
    // 0x8000DC50: sh          $t5, 0xC($s6)
    MEM_H(0XC, ctx->r22) = ctx->r13;
    after_31:
    // 0x8000DC54: addiu       $t8, $zero, 0x3A
    ctx->r24 = ADD32(0, 0X3A);
    // 0x8000DC58: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x8000DC5C: sh          $t8, 0x48($v0)
    MEM_H(0X48, ctx->r2) = ctx->r24;
    // 0x8000DC60: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000DC64: lwc1        $f6, 0x570C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X570C);
    // 0x8000DC68: lw          $t6, 0x50($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X50);
    // 0x8000DC6C: addiu       $t5, $zero, 0x60
    ctx->r13 = ADD32(0, 0X60);
    // 0x8000DC70: swc1        $f6, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f6.u32l;
    // 0x8000DC74: lw          $t9, 0x4C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4C);
    // 0x8000DC78: nop

    // 0x8000DC7C: sh          $zero, 0x14($t9)
    MEM_H(0X14, ctx->r25) = 0;
    // 0x8000DC80: sw          $v0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r2;
    // 0x8000DC84: lw          $s3, 0x64($v0)
    ctx->r19 = MEM_W(ctx->r2, 0X64);
    // 0x8000DC88: nop

    // 0x8000DC8C: sb          $t5, 0x1F7($s3)
    MEM_B(0X1F7, ctx->r19) = ctx->r13;
L_8000DC90:
    // 0x8000DC90: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8000DC94: lw          $t6, -0x4B90($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4B90);
    // 0x8000DC98: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x8000DC9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000DCA0: blez        $t6, L_8000DE44
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8000DCA4: sw          $t8, -0x4CD0($at)
        MEM_W(-0X4CD0, ctx->r1) = ctx->r24;
            goto L_8000DE44;
    }
    // 0x8000DCA4: sw          $t8, -0x4CD0($at)
    MEM_W(-0X4CD0, ctx->r1) = ctx->r24;
    // 0x8000DCA8: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
L_8000DCAC:
    // 0x8000DCAC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8000DCB0: lw          $t9, -0x4B9C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4B9C);
    // 0x8000DCB4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000DCB8: addu        $t7, $t9, $s5
    ctx->r15 = ADD32(ctx->r25, ctx->r21);
    // 0x8000DCBC: lw          $s1, 0x0($t7)
    ctx->r17 = MEM_W(ctx->r15, 0X0);
    // 0x8000DCC0: nop

    // 0x8000DCC4: lw          $s3, 0x64($s1)
    ctx->r19 = MEM_W(ctx->r17, 0X64);
    // 0x8000DCC8: nop

    // 0x8000DCCC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8000DCD0:
    // 0x8000DCD0: jal         0x8004DE78
    // 0x8000DCD4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    update_player_racer(rdram, ctx);
        goto after_32;
    // 0x8000DCD4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_32:
    // 0x8000DCD8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000DCDC: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x8000DCE0: bne         $at, $zero, L_8000DCD0
    if (ctx->r1 != 0) {
        // 0x8000DCE4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8000DCD0;
    }
    // 0x8000DCE4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8000DCE8: lh          $t5, 0x0($s3)
    ctx->r13 = MEM_H(ctx->r19, 0X0);
    // 0x8000DCEC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000DCF0: bne         $t5, $at, L_8000DD68
    if (ctx->r13 != ctx->r1) {
        // 0x8000DCF4: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8000DD68;
    }
    // 0x8000DCF4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000DCF8: lw          $t6, 0x40($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X40);
    // 0x8000DCFC: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8000DD00: lb          $a0, 0x55($t6)
    ctx->r4 = MEM_B(ctx->r14, 0X55);
    // 0x8000DD04: andi        $t8, $s4, 0x1
    ctx->r24 = ctx->r20 & 0X1;
    // 0x8000DD08: blez        $a0, L_8000DDCC
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8000DD0C: or          $s4, $t8, $zero
        ctx->r20 = ctx->r24 | 0;
            goto L_8000DDCC;
    }
    // 0x8000DD0C: or          $s4, $t8, $zero
    ctx->r20 = ctx->r24 | 0;
    // 0x8000DD10: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8000DD14:
    // 0x8000DD14: lw          $t9, 0x68($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X68);
    // 0x8000DD18: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000DD1C: addu        $t7, $t9, $v1
    ctx->r15 = ADD32(ctx->r25, ctx->r3);
    // 0x8000DD20: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x8000DD24: nop

    // 0x8000DD28: beq         $v0, $zero, L_8000DD58
    if (ctx->r2 == 0) {
        // 0x8000DD2C: slt         $at, $s0, $a0
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8000DD58;
    }
    // 0x8000DD2C: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8000DD30: lb          $t5, 0x20($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X20);
    // 0x8000DD34: sll         $t8, $s4, 1
    ctx->r24 = S32(ctx->r20 << 1);
    // 0x8000DD38: beq         $t5, $zero, L_8000DD58
    if (ctx->r13 == 0) {
        // 0x8000DD3C: slt         $at, $s0, $a0
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8000DD58;
    }
    // 0x8000DD3C: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8000DD40: sb          $t8, 0x20($v0)
    MEM_B(0X20, ctx->r2) = ctx->r24;
    // 0x8000DD44: lw          $t6, 0x40($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X40);
    // 0x8000DD48: nop

    // 0x8000DD4C: lb          $a0, 0x55($t6)
    ctx->r4 = MEM_B(ctx->r14, 0X55);
    // 0x8000DD50: nop

    // 0x8000DD54: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
L_8000DD58:
    // 0x8000DD58: bne         $at, $zero, L_8000DD14
    if (ctx->r1 != 0) {
        // 0x8000DD5C: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8000DD14;
    }
    // 0x8000DD5C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000DD60: b           L_8000DDCC
    // 0x8000DD64: nop

        goto L_8000DDCC;
    // 0x8000DD64: nop

L_8000DD68:
    // 0x8000DD68: lw          $t9, 0x40($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X40);
    // 0x8000DD6C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000DD70: lb          $a0, 0x55($t9)
    ctx->r4 = MEM_B(ctx->r25, 0X55);
    // 0x8000DD74: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8000DD78: blez        $a0, L_8000DDCC
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8000DD7C: nop
    
            goto L_8000DDCC;
    }
    // 0x8000DD7C: nop

L_8000DD80:
    // 0x8000DD80: lw          $t7, 0x68($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X68);
    // 0x8000DD84: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000DD88: addu        $t5, $t7, $v1
    ctx->r13 = ADD32(ctx->r15, ctx->r3);
    // 0x8000DD8C: lw          $v0, 0x0($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X0);
    // 0x8000DD90: nop

    // 0x8000DD94: beq         $v0, $zero, L_8000DDC4
    if (ctx->r2 == 0) {
        // 0x8000DD98: slt         $at, $s0, $a0
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8000DDC4;
    }
    // 0x8000DD98: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8000DD9C: lb          $t8, 0x20($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X20);
    // 0x8000DDA0: nop

    // 0x8000DDA4: beq         $t8, $zero, L_8000DDC4
    if (ctx->r24 == 0) {
        // 0x8000DDA8: slt         $at, $s0, $a0
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8000DDC4;
    }
    // 0x8000DDA8: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8000DDAC: sb          $zero, 0x20($v0)
    MEM_B(0X20, ctx->r2) = 0;
    // 0x8000DDB0: lw          $t6, 0x40($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X40);
    // 0x8000DDB4: nop

    // 0x8000DDB8: lb          $a0, 0x55($t6)
    ctx->r4 = MEM_B(ctx->r14, 0X55);
    // 0x8000DDBC: nop

    // 0x8000DDC0: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
L_8000DDC4:
    // 0x8000DDC4: bne         $at, $zero, L_8000DD80
    if (ctx->r1 != 0) {
        // 0x8000DDC8: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8000DD80;
    }
    // 0x8000DDC8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_8000DDCC:
    // 0x8000DDCC: jal         0x8009C850
    // 0x8000DDD0: nop

    get_filtered_cheats(rdram, ctx);
        goto after_33;
    // 0x8000DDD0: nop

    after_33:
    // 0x8000DDD4: andi        $t9, $v0, 0x10
    ctx->r25 = ctx->r2 & 0X10;
    // 0x8000DDD8: beq         $t9, $zero, L_8000DDF4
    if (ctx->r25 == 0) {
        // 0x8000DDDC: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8000DDF4;
    }
    // 0x8000DDDC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000DDE0: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8000DDE4: lwc1        $f10, 0x5710($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5710);
    // 0x8000DDE8: nop

    // 0x8000DDEC: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8000DDF0: swc1        $f16, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f16.u32l;
L_8000DDF4:
    // 0x8000DDF4: jal         0x8009C850
    // 0x8000DDF8: nop

    get_filtered_cheats(rdram, ctx);
        goto after_34;
    // 0x8000DDF8: nop

    after_34:
    // 0x8000DDFC: andi        $t7, $v0, 0x20
    ctx->r15 = ctx->r2 & 0X20;
    // 0x8000DE00: beq         $t7, $zero, L_8000DE1C
    if (ctx->r15 == 0) {
        // 0x8000DE04: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8000DE1C;
    }
    // 0x8000DE04: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000DE08: lwc1        $f18, 0x8($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8000DE0C: lwc1        $f4, 0x5714($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5714);
    // 0x8000DE10: nop

    // 0x8000DE14: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8000DE18: swc1        $f6, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f6.u32l;
L_8000DE1C:
    // 0x8000DE1C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000DE20: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8000DE24: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8000DE28: swc1        $f0, 0x90($s3)
    MEM_W(0X90, ctx->r19) = ctx->f0.u32l;
    // 0x8000DE2C: swc1        $f0, 0x8C($s3)
    MEM_W(0X8C, ctx->r19) = ctx->f0.u32l;
    // 0x8000DE30: lw          $t5, -0x4B90($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4B90);
    // 0x8000DE34: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8000DE38: slt         $at, $s2, $t5
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8000DE3C: bne         $at, $zero, L_8000DCAC
    if (ctx->r1 != 0) {
        // 0x8000DE40: addiu       $s5, $s5, 0x4
        ctx->r21 = ADD32(ctx->r21, 0X4);
            goto L_8000DCAC;
    }
    // 0x8000DE40: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
L_8000DE44:
    // 0x8000DE44: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x8000DE48: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x8000DE4C: beq         $t8, $zero, L_8000DE7C
    if (ctx->r24 == 0) {
        // 0x8000DE50: addiu       $t5, $zero, 0x50
        ctx->r13 = ADD32(0, 0X50);
            goto L_8000DE7C;
    }
    // 0x8000DE50: addiu       $t5, $zero, 0x50
    ctx->r13 = ADD32(0, 0X50);
    // 0x8000DE54: bne         $t6, $zero, L_8000DE7C
    if (ctx->r14 != 0) {
        // 0x8000DE58: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_8000DE7C;
    }
    // 0x8000DE58: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8000DE5C: lbu         $t9, -0x4B8B($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X4B8B);
    // 0x8000DE60: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8000DE64: bne         $t9, $zero, L_8000DE7C
    if (ctx->r25 != 0) {
        // 0x8000DE68: nop
    
            goto L_8000DE7C;
    }
    // 0x8000DE68: nop

    // 0x8000DE6C: lb          $t7, -0x4D44($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X4D44);
    // 0x8000DE70: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000DE74: beq         $t7, $zero, L_8000DE88
    if (ctx->r15 == 0) {
        // 0x8000DE78: nop
    
            goto L_8000DE88;
    }
    // 0x8000DE78: nop

L_8000DE7C:
    // 0x8000DE7C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000DE80: b           L_8000DE8C
    // 0x8000DE84: sw          $t5, -0x4CD0($at)
    MEM_W(-0X4CD0, ctx->r1) = ctx->r13;
        goto L_8000DE8C;
    // 0x8000DE84: sw          $t5, -0x4CD0($at)
    MEM_W(-0X4CD0, ctx->r1) = ctx->r13;
L_8000DE88:
    // 0x8000DE88: sw          $zero, -0x4CD0($at)
    MEM_W(-0X4CD0, ctx->r1) = 0;
L_8000DE8C:
    // 0x8000DE8C: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x8000DE90: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x8000DE94: bne         $t8, $zero, L_8000DF00
    if (ctx->r24 != 0) {
        // 0x8000DE98: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8000DF00;
    }
    // 0x8000DE98: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000DE9C: bne         $t6, $at, L_8000DF00
    if (ctx->r14 != ctx->r1) {
        // 0x8000DEA0: nop
    
            goto L_8000DF00;
    }
    // 0x8000DEA0: nop

    // 0x8000DEA4: jal         0x8009F1B4
    // 0x8000DEA8: nop

    is_in_adventure_two(rdram, ctx);
        goto after_35;
    // 0x8000DEA8: nop

    after_35:
    // 0x8000DEAC: bne         $v0, $zero, L_8000DF00
    if (ctx->r2 != 0) {
        // 0x8000DEB0: nop
    
            goto L_8000DF00;
    }
    // 0x8000DEB0: nop

    // 0x8000DEB4: jal         0x8006C3DC
    // 0x8000DEB8: nop

    race_is_adventure_2P(rdram, ctx);
        goto after_36;
    // 0x8000DEB8: nop

    after_36:
    // 0x8000DEBC: bne         $v0, $zero, L_8000DF00
    if (ctx->r2 != 0) {
        // 0x8000DEC0: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8000DF00;
    }
    // 0x8000DEC0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8000DEC4: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
    // 0x8000DEC8: addiu       $s1, $zero, 0x8
    ctx->r17 = ADD32(0, 0X8);
    // 0x8000DECC: addiu       $s0, $zero, 0x32
    ctx->r16 = ADD32(0, 0X32);
L_8000DED0:
    // 0x8000DED0: sb          $s0, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r16;
    // 0x8000DED4: sb          $s1, 0x1($s6)
    MEM_B(0X1, ctx->r22) = ctx->r17;
    // 0x8000DED8: sh          $zero, 0x2($s6)
    MEM_H(0X2, ctx->r22) = 0;
    // 0x8000DEDC: sh          $zero, 0x4($s6)
    MEM_H(0X4, ctx->r22) = 0;
    // 0x8000DEE0: sh          $zero, 0x6($s6)
    MEM_H(0X6, ctx->r22) = 0;
    // 0x8000DEE4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8000DEE8: jal         0x8000EA54
    // 0x8000DEEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    spawn_object(rdram, ctx);
        goto after_37;
    // 0x8000DEEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_37:
    // 0x8000DEF0: sw          $s2, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->r18;
    // 0x8000DEF4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8000DEF8: bne         $s2, $s3, L_8000DED0
    if (ctx->r18 != ctx->r19) {
        // 0x8000DEFC: sw          $zero, 0x3C($v0)
        MEM_W(0X3C, ctx->r2) = 0;
            goto L_8000DED0;
    }
    // 0x8000DEFC: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
L_8000DF00:
    // 0x8000DF00: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000DF04: sh          $zero, -0x4D32($at)
    MEM_H(-0X4D32, ctx->r1) = 0;
    // 0x8000DF08: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000DF0C: sw          $zero, -0x4CCC($at)
    MEM_W(-0X4CCC, ctx->r1) = 0;
    // 0x8000DF10: jal         0x8009D874
    // 0x8000DF14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_next_taj_challenge_menu(rdram, ctx);
        goto after_38;
    // 0x8000DF14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_38:
    // 0x8000DF18: lbu         $t9, 0x48($s7)
    ctx->r25 = MEM_BU(ctx->r23, 0X48);
    // 0x8000DF1C: nop

    // 0x8000DF20: bne         $t9, $zero, L_8000E018
    if (ctx->r25 != 0) {
        // 0x8000DF24: lw          $t6, 0x130($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X130);
            goto L_8000E018;
    }
    // 0x8000DF24: lw          $t6, 0x130($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X130);
    // 0x8000DF28: jal         0x8009C814
    // 0x8000DF2C: nop

    is_in_tracks_mode(rdram, ctx);
        goto after_39;
    // 0x8000DF2C: nop

    after_39:
    // 0x8000DF30: bne         $v0, $zero, L_8000E014
    if (ctx->r2 != 0) {
        // 0x8000DF34: addiu       $a0, $zero, 0x10
        ctx->r4 = ADD32(0, 0X10);
            goto L_8000E014;
    }
    // 0x8000DF34: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x8000DF38: jal         0x8001E2D0
    // 0x8000DF3C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    get_misc_asset(rdram, ctx);
        goto after_40;
    // 0x8000DF3C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    after_40:
    // 0x8000DF40: lhu         $v1, 0x14($s7)
    ctx->r3 = MEM_HU(ctx->r23, 0X14);
    // 0x8000DF44: nop

    // 0x8000DF48: andi        $t7, $v1, 0x1
    ctx->r15 = ctx->r3 & 0X1;
    // 0x8000DF4C: bne         $t7, $zero, L_8000DF78
    if (ctx->r15 != 0) {
        // 0x8000DF50: andi        $t9, $v1, 0x2
        ctx->r25 = ctx->r3 & 0X2;
            goto L_8000DF78;
    }
    // 0x8000DF50: andi        $t9, $v1, 0x2
    ctx->r25 = ctx->r3 & 0X2;
    // 0x8000DF54: lw          $t5, 0x0($s7)
    ctx->r13 = MEM_W(ctx->r23, 0X0);
    // 0x8000DF58: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8000DF5C: lh          $t8, 0x0($t5)
    ctx->r24 = MEM_H(ctx->r13, 0X0);
    // 0x8000DF60: nop

    // 0x8000DF64: slt         $at, $t8, $t6
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8000DF68: bne         $at, $zero, L_8000DF78
    if (ctx->r1 != 0) {
        // 0x8000DF6C: nop
    
            goto L_8000DF78;
    }
    // 0x8000DF6C: nop

    // 0x8000DF70: b           L_8000DFCC
    // 0x8000DF74: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
        goto L_8000DFCC;
    // 0x8000DF74: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_8000DF78:
    // 0x8000DF78: bne         $t9, $zero, L_8000DFA4
    if (ctx->r25 != 0) {
        // 0x8000DF7C: andi        $t6, $v1, 0x4
        ctx->r14 = ctx->r3 & 0X4;
            goto L_8000DFA4;
    }
    // 0x8000DF7C: andi        $t6, $v1, 0x4
    ctx->r14 = ctx->r3 & 0X4;
    // 0x8000DF80: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
    // 0x8000DF84: lb          $t8, 0x1($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X1);
    // 0x8000DF88: lh          $t5, 0x0($t7)
    ctx->r13 = MEM_H(ctx->r15, 0X0);
    // 0x8000DF8C: nop

    // 0x8000DF90: slt         $at, $t5, $t8
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8000DF94: bne         $at, $zero, L_8000DFA4
    if (ctx->r1 != 0) {
        // 0x8000DF98: nop
    
            goto L_8000DFA4;
    }
    // 0x8000DF98: nop

    // 0x8000DF9C: b           L_8000DFCC
    // 0x8000DFA0: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
        goto L_8000DFCC;
    // 0x8000DFA0: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
L_8000DFA4:
    // 0x8000DFA4: bne         $t6, $zero, L_8000DFCC
    if (ctx->r14 != 0) {
        // 0x8000DFA8: nop
    
            goto L_8000DFCC;
    }
    // 0x8000DFA8: nop

    // 0x8000DFAC: lw          $t9, 0x0($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X0);
    // 0x8000DFB0: lb          $t5, 0x2($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X2);
    // 0x8000DFB4: lh          $t7, 0x0($t9)
    ctx->r15 = MEM_H(ctx->r25, 0X0);
    // 0x8000DFB8: nop

    // 0x8000DFBC: slt         $at, $t7, $t5
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8000DFC0: bne         $at, $zero, L_8000DFCC
    if (ctx->r1 != 0) {
        // 0x8000DFC4: nop
    
            goto L_8000DFCC;
    }
    // 0x8000DFC4: nop

    // 0x8000DFC8: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
L_8000DFCC:
    // 0x8000DFCC: beq         $s2, $zero, L_8000E018
    if (ctx->r18 == 0) {
        // 0x8000DFD0: lw          $t6, 0x130($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X130);
            goto L_8000E018;
    }
    // 0x8000DFD0: lw          $t6, 0x130($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X130);
    // 0x8000DFD4: jal         0x80039360
    // 0x8000DFD8: addiu       $a0, $zero, 0x250
    ctx->r4 = ADD32(0, 0X250);
    set_taj_voice_line(rdram, ctx);
        goto after_41;
    // 0x8000DFD8: addiu       $a0, $zero, 0x250
    ctx->r4 = ADD32(0, 0X250);
    after_41:
    // 0x8000DFDC: lhu         $t8, 0x14($s7)
    ctx->r24 = MEM_HU(ctx->r23, 0X14);
    // 0x8000DFE0: addiu       $t6, $s2, 0x1F
    ctx->r14 = ADD32(ctx->r18, 0X1F);
    // 0x8000DFE4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8000DFE8: sllv        $t7, $t9, $t6
    ctx->r15 = S32(ctx->r25 << (ctx->r14 & 31));
    // 0x8000DFEC: or          $t5, $t8, $t7
    ctx->r13 = ctx->r24 | ctx->r15;
    // 0x8000DFF0: sh          $t5, 0x14($s7)
    MEM_H(0X14, ctx->r23) = ctx->r13;
    // 0x8000DFF4: jal         0x800521F8
    // 0x8000DFF8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_taj_status(rdram, ctx);
        goto after_42;
    // 0x8000DFF8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_42:
    // 0x8000DFFC: jal         0x8009D874
    // 0x8000E000: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    set_next_taj_challenge_menu(rdram, ctx);
        goto after_43;
    // 0x8000E000: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_43:
    // 0x8000E004: jal         0x8009C6E4
    // 0x8000E008: nop

    get_save_file_index(rdram, ctx);
        goto after_44;
    // 0x8000E008: nop

    after_44:
    // 0x8000E00C: jal         0x8006EE88
    // 0x8000E010: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    safe_mark_write_save_file(rdram, ctx);
        goto after_45;
    // 0x8000E010: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_45:
L_8000E014:
    // 0x8000E014: lw          $t6, 0x130($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X130);
L_8000E018:
    // 0x8000E018: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8000E01C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E020: bltz        $t6, L_8000E038
    if (SIGNED(ctx->r14) < 0) {
        // 0x8000E024: sb          $t9, -0x4D5C($at)
        MEM_B(-0X4D5C, ctx->r1) = ctx->r25;
            goto L_8000E038;
    }
    // 0x8000E024: sb          $t9, -0x4D5C($at)
    MEM_B(-0X4D5C, ctx->r1) = ctx->r25;
    // 0x8000E028: lw          $t8, 0x130($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X130);
    // 0x8000E02C: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x8000E030: nop

    // 0x8000E034: sb          $t8, 0x3B($t7)
    MEM_B(0X3B, ctx->r15) = ctx->r24;
L_8000E038:
    // 0x8000E038: jal         0x8000E148
    // 0x8000E03C: nop

    racetype_demo(rdram, ctx);
        goto after_46;
    // 0x8000E03C: nop

    after_46:
    // 0x8000E040: beq         $v0, $zero, L_8000E068
    if (ctx->r2 == 0) {
        // 0x8000E044: nop
    
            goto L_8000E068;
    }
    // 0x8000E044: nop

    // 0x8000E048: jal         0x800724E4
    // 0x8000E04C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    rumble_init(rdram, ctx);
        goto after_47;
    // 0x8000E04C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_47:
    // 0x8000E050: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E054: sw          $zero, -0x4CD0($at)
    MEM_W(-0X4CD0, ctx->r1) = 0;
    // 0x8000E058: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000E05C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8000E060: jal         0x8006BF50
    // 0x8000E064: nop

    level_music_start(rdram, ctx);
        goto after_48;
    // 0x8000E064: nop

    after_48:
L_8000E068:
    // 0x8000E068: jal         0x800712F0
    // 0x8000E06C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mempool_free_timer(rdram, ctx);
        goto after_49;
    // 0x8000E06C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_49:
    // 0x8000E070: jal         0x80071380
    // 0x8000E074: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    mempool_free(rdram, ctx);
        goto after_50;
    // 0x8000E074: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_50:
    // 0x8000E078: jal         0x800712F0
    // 0x8000E07C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    mempool_free_timer(rdram, ctx);
        goto after_51;
    // 0x8000E07C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_51:
L_8000E080:
    // 0x8000E080: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8000E084: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000E088: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E08C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000E090: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8000E094: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8000E098: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8000E09C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8000E0A0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8000E0A4: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8000E0A8: jr          $ra
    // 0x8000E0AC: addiu       $sp, $sp, 0x150
    ctx->r29 = ADD32(ctx->r29, 0X150);
    return;
    // 0x8000E0AC: addiu       $sp, $sp, 0x150
    ctx->r29 = ADD32(ctx->r29, 0X150);
;}
RECOMP_FUNC void get_contpak_error(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E0B0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8000E0B4: lw          $t6, -0x4D48($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4D48);
    // 0x8000E0B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000E0BC: sltiu       $at, $t6, 0x9
    ctx->r1 = ctx->r14 < 0X9 ? 1 : 0;
    // 0x8000E0C0: beq         $at, $zero, L_8000E114
    if (ctx->r1 == 0) {
        // 0x8000E0C4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8000E114;
    }
    // 0x8000E0C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000E0C8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8000E0CC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000E0D0: addu        $at, $at, $t6
    gpr jr_addend_8000E0DC = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8000E0D4: lw          $t6, 0x5718($at)
    ctx->r14 = ADD32(ctx->r1, 0X5718);
    // 0x8000E0D8: nop

    // 0x8000E0DC: jr          $t6
    // 0x8000E0E0: nop

    switch (jr_addend_8000E0DC >> 2) {
        case 0: goto L_8000E104; break;
        case 1: goto L_8000E0E4; break;
        case 2: goto L_8000E0F4; break;
        case 3: goto L_8000E0F4; break;
        case 4: goto L_8000E0FC; break;
        case 5: goto L_8000E104; break;
        case 6: goto L_8000E0FC; break;
        case 7: goto L_8000E0EC; break;
        case 8: goto L_8000E104; break;
        default: switch_error(__func__, 0x8000E0DC, 0x800E5718);
    }
    // 0x8000E0E0: nop

L_8000E0E4:
    // 0x8000E0E4: b           L_8000E118
    // 0x8000E0E8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000E118;
    // 0x8000E0E8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000E0EC:
    // 0x8000E0EC: b           L_8000E118
    // 0x8000E0F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000E118;
    // 0x8000E0F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000E0F4:
    // 0x8000E0F4: b           L_8000E118
    // 0x8000E0F8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_8000E118;
    // 0x8000E0F8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8000E0FC:
    // 0x8000E0FC: b           L_8000E118
    // 0x8000E100: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8000E118;
    // 0x8000E100: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8000E104:
    // 0x8000E104: jal         0x80059E70
    // 0x8000E108: nop

    timetrial_ghost_full(rdram, ctx);
        goto after_0;
    // 0x8000E108: nop

    after_0:
    // 0x8000E10C: b           L_8000E11C
    // 0x8000E110: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000E11C;
    // 0x8000E110: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000E114:
    // 0x8000E114: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000E118:
    // 0x8000E118: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000E11C:
    // 0x8000E11C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000E120: jr          $ra
    // 0x8000E124: nop

    return;
    // 0x8000E124: nop

;}
RECOMP_FUNC void instShowBearBar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E128: addiu       $t6, $zero, -0x8000
    ctx->r14 = ADD32(0, -0X8000);
    // 0x8000E12C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000E130: jr          $ra
    // 0x8000E134: sh          $t6, -0x3388($at)
    MEM_H(-0X3388, ctx->r1) = ctx->r14;
    return;
    // 0x8000E134: sh          $t6, -0x3388($at)
    MEM_H(-0X3388, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_8000E138(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E138: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000E13C: lb          $v0, -0x4D60($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X4D60);
    // 0x8000E140: jr          $ra
    // 0x8000E144: nop

    return;
    // 0x8000E144: nop

;}
RECOMP_FUNC void racetype_demo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E148: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000E14C: lb          $v0, -0x3374($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X3374);
    // 0x8000E150: jr          $ra
    // 0x8000E154: nop

    return;
    // 0x8000E154: nop

;}
RECOMP_FUNC void is_race_started_by_player_two(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E158: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8000E15C: lb          $t6, -0x3350($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X3350);
    // 0x8000E160: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000E164: beq         $t6, $zero, L_8000E17C
    if (ctx->r14 == 0) {
        // 0x8000E168: nop
    
            goto L_8000E17C;
    }
    // 0x8000E168: nop

    // 0x8000E16C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000E170: lb          $v0, -0x3354($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X3354);
    // 0x8000E174: jr          $ra
    // 0x8000E178: nop

    return;
    // 0x8000E178: nop

L_8000E17C:
    // 0x8000E17C: jr          $ra
    // 0x8000E180: nop

    return;
    // 0x8000E180: nop

;}
RECOMP_FUNC void is_player_two_in_control(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E184: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000E188: lb          $v0, -0x3348($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X3348);
    // 0x8000E18C: jr          $ra
    // 0x8000E190: nop

    return;
    // 0x8000E190: nop

;}
RECOMP_FUNC void toggle_lead_player_index(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E194: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000E198: addiu       $v0, $v0, -0x3354
    ctx->r2 = ADD32(ctx->r2, -0X3354);
    // 0x8000E19C: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8000E1A0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8000E1A4: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x8000E1A8: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x8000E1AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000E1B0: jr          $ra
    // 0x8000E1B4: sb          $zero, -0x3350($at)
    MEM_B(-0X3350, ctx->r1) = 0;
    return;
    // 0x8000E1B4: sb          $zero, -0x3350($at)
    MEM_B(-0X3350, ctx->r1) = 0;
;}
RECOMP_FUNC void reset_lead_player_index(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E1B8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000E1BC: sb          $zero, -0x3354($at)
    MEM_B(-0X3354, ctx->r1) = 0;
    // 0x8000E1C0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000E1C4: jr          $ra
    // 0x8000E1C8: sb          $zero, -0x3350($at)
    MEM_B(-0X3350, ctx->r1) = 0;
    return;
    // 0x8000E1C8: sb          $zero, -0x3350($at)
    MEM_B(-0X3350, ctx->r1) = 0;
;}
RECOMP_FUNC void find_non_car_racers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E1CC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000E1D0: lb          $v0, -0x4C7E($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X4C7E);
    // 0x8000E1D4: jr          $ra
    // 0x8000E1D8: nop

    return;
    // 0x8000E1D8: nop

;}
RECOMP_FUNC void check_if_silver_coin_race(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E1DC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000E1E0: lb          $v0, -0x4C7D($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X4C7D);
    // 0x8000E1E4: jr          $ra
    // 0x8000E1E8: nop

    return;
    // 0x8000E1E8: nop

;}
RECOMP_FUNC void despawn_player_racer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E1EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E1F0: sw          $a0, -0x4D40($at)
    MEM_W(-0X4D40, ctx->r1) = ctx->r4;
    // 0x8000E1F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E1F8: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8000E1FC: sb          $t6, -0x4D3C($at)
    MEM_B(-0X4D3C, ctx->r1) = ctx->r14;
    // 0x8000E200: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8000E204: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E208: sb          $a1, -0x4D3B($at)
    MEM_B(-0X4D3B, ctx->r1) = ctx->r5;
    // 0x8000E20C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000E210: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8000E214: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000E218: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000E21C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000E220: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8000E224: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E228: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8000E22C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8000E230: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x8000E234: nop

    // 0x8000E238: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8000E23C: sh          $t8, -0x4D3A($at)
    MEM_H(-0X4D3A, ctx->r1) = ctx->r24;
    // 0x8000E240: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8000E244: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000E248: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000E24C: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8000E250: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E254: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8000E258: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8000E25C: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x8000E260: nop

    // 0x8000E264: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8000E268: sh          $t0, -0x4D38($at)
    MEM_H(-0X4D38, ctx->r1) = ctx->r8;
    // 0x8000E26C: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x8000E270: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000E274: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000E278: lwc1        $f16, 0x14($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8000E27C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E280: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8000E284: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x8000E288: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8000E28C: sh          $t2, -0x4D36($at)
    MEM_H(-0X4D36, ctx->r1) = ctx->r10;
    // 0x8000E290: lh          $t3, 0x0($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X0);
    // 0x8000E294: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E298: jal         0x8000FFB8
    // 0x8000E29C: sh          $t3, -0x4D34($at)
    MEM_H(-0X4D34, ctx->r1) = ctx->r11;
    free_object(rdram, ctx);
        goto after_0;
    // 0x8000E29C: sh          $t3, -0x4D34($at)
    MEM_H(-0X4D34, ctx->r1) = ctx->r11;
    after_0:
    // 0x8000E2A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000E2A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E2A8: sw          $zero, -0x4B90($at)
    MEM_W(-0X4B90, ctx->r1) = 0;
    // 0x8000E2AC: jr          $ra
    // 0x8000E2B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8000E2B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void transform_player_vehicle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E2B4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000E2B8: addiu       $v1, $v1, -0x4D3C
    ctx->r3 = ADD32(ctx->r3, -0X4D3C);
    // 0x8000E2BC: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x8000E2C0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8000E2C4: beq         $v0, $zero, L_8000E4AC
    if (ctx->r2 == 0) {
        // 0x8000E2C8: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8000E4AC;
    }
    // 0x8000E2C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000E2CC: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8000E2D0: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
    // 0x8000E2D4: lb          $t7, 0x0($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X0);
    // 0x8000E2D8: nop

    // 0x8000E2DC: bne         $t7, $zero, L_8000E4B0
    if (ctx->r15 != 0) {
        // 0x8000E2E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8000E4B0;
    }
    // 0x8000E2E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000E2E4: jal         0x8006ECD0
    // 0x8000E2E8: nop

    get_settings(rdram, ctx);
        goto after_0;
    // 0x8000E2E8: nop

    after_0:
    // 0x8000E2EC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000E2F0: lb          $a0, -0x4D3B($a0)
    ctx->r4 = MEM_B(ctx->r4, -0X4D3B);
    // 0x8000E2F4: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x8000E2F8: slti        $at, $a0, 0x5
    ctx->r1 = SIGNED(ctx->r4) < 0X5 ? 1 : 0;
    // 0x8000E2FC: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8000E300: sh          $zero, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = 0;
    // 0x8000E304: beq         $at, $zero, L_8000E338
    if (ctx->r1 == 0) {
        // 0x8000E308: sb          $t8, 0x2D($sp)
        MEM_B(0X2D, ctx->r29) = ctx->r24;
            goto L_8000E338;
    }
    // 0x8000E308: sb          $t8, 0x2D($sp)
    MEM_B(0X2D, ctx->r29) = ctx->r24;
    // 0x8000E30C: lb          $t9, 0x59($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X59);
    // 0x8000E310: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x8000E314: addu        $t1, $t1, $a0
    ctx->r9 = ADD32(ctx->r9, ctx->r4);
    // 0x8000E318: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8000E31C: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x8000E320: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x8000E324: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8000E328: addu        $v1, $v1, $t3
    ctx->r3 = ADD32(ctx->r3, ctx->r11);
    // 0x8000E32C: lh          $v1, -0x32E8($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X32E8);
    // 0x8000E330: b           L_8000E34C
    // 0x8000E334: nop

        goto L_8000E34C;
    // 0x8000E334: nop

L_8000E338:
    // 0x8000E338: sll         $t4, $a0, 1
    ctx->r12 = S32(ctx->r4 << 1);
    // 0x8000E33C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8000E340: addu        $v1, $v1, $t4
    ctx->r3 = ADD32(ctx->r3, ctx->r12);
    // 0x8000E344: lh          $v1, -0x328E($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X328E);
    // 0x8000E348: nop

L_8000E34C:
    // 0x8000E34C: jal         0x8006DD54
    // 0x8000E350: sh          $v1, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r3;
    set_level_default_vehicle(rdram, ctx);
        goto after_1;
    // 0x8000E350: sh          $v1, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r3;
    after_1:
    // 0x8000E354: lh          $v1, 0x22($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X22);
    // 0x8000E358: lbu         $t5, 0x2D($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X2D);
    // 0x8000E35C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8000E360: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8000E364: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8000E368: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8000E36C: andi        $t6, $v1, 0x100
    ctx->r14 = ctx->r3 & 0X100;
    // 0x8000E370: lh          $t9, -0x4D3A($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X4D3A);
    // 0x8000E374: lh          $t1, -0x4D38($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X4D38);
    // 0x8000E378: lh          $t0, -0x4D36($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X4D36);
    // 0x8000E37C: lh          $t2, -0x4D34($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X4D34);
    // 0x8000E380: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x8000E384: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x8000E388: sb          $t8, 0x2D($sp)
    MEM_B(0X2D, ctx->r29) = ctx->r24;
    // 0x8000E38C: sh          $zero, 0x36($sp)
    MEM_H(0X36, ctx->r29) = 0;
    // 0x8000E390: sh          $zero, 0x34($sp)
    MEM_H(0X34, ctx->r29) = 0;
    // 0x8000E394: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8000E398: sb          $v1, 0x2C($sp)
    MEM_B(0X2C, ctx->r29) = ctx->r3;
    // 0x8000E39C: sh          $t9, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r25;
    // 0x8000E3A0: sh          $t1, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r9;
    // 0x8000E3A4: sh          $t0, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r8;
    // 0x8000E3A8: jal         0x800521F8
    // 0x8000E3AC: sh          $t2, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r10;
    set_taj_status(rdram, ctx);
        goto after_2;
    // 0x8000E3AC: sh          $t2, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r10;
    after_2:
    // 0x8000E3B0: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8000E3B4: jal         0x8000EA54
    // 0x8000E3B8: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    spawn_object(rdram, ctx);
        goto after_3;
    // 0x8000E3B8: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_3:
    // 0x8000E3BC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8000E3C0: lw          $t4, -0x4B9C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4B9C);
    // 0x8000E3C4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8000E3C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E3CC: sw          $t3, -0x4B90($at)
    MEM_W(-0X4B90, ctx->r1) = ctx->r11;
    // 0x8000E3D0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8000E3D4: sw          $v0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r2;
    // 0x8000E3D8: lw          $t6, -0x4B94($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4B94);
    // 0x8000E3DC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8000E3E0: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x8000E3E4: lw          $t5, -0x4B98($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4B98);
    // 0x8000E3E8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000E3EC: sw          $v0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r2;
    // 0x8000E3F0: addiu       $a1, $a1, -0x4D3B
    ctx->r5 = ADD32(ctx->r5, -0X4D3B);
    // 0x8000E3F4: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x8000E3F8: lb          $t7, 0x0($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X0);
    // 0x8000E3FC: nop

    // 0x8000E400: sb          $t7, 0x1D6($v1)
    MEM_B(0X1D6, ctx->r3) = ctx->r15;
    // 0x8000E404: lb          $t8, 0x0($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X0);
    // 0x8000E408: sb          $zero, 0x2($v1)
    MEM_B(0X2, ctx->r3) = 0;
    // 0x8000E40C: sb          $t8, 0x1D7($v1)
    MEM_B(0X1D7, ctx->r3) = ctx->r24;
    // 0x8000E410: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8000E414: nop

    // 0x8000E418: lb          $t1, 0x59($t9)
    ctx->r9 = MEM_B(ctx->r25, 0X59);
    // 0x8000E41C: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x8000E420: sw          $zero, 0x118($v1)
    MEM_W(0X118, ctx->r3) = 0;
    // 0x8000E424: sb          $t1, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r9;
    // 0x8000E428: jal         0x8009C850
    // 0x8000E42C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    get_filtered_cheats(rdram, ctx);
        goto after_4;
    // 0x8000E42C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_4:
    // 0x8000E430: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8000E434: andi        $t0, $v0, 0x10
    ctx->r8 = ctx->r2 & 0X10;
    // 0x8000E438: beq         $t0, $zero, L_8000E454
    if (ctx->r8 == 0) {
        // 0x8000E43C: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8000E454;
    }
    // 0x8000E43C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000E440: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8000E444: lwc1        $f6, 0x573C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X573C);
    // 0x8000E448: nop

    // 0x8000E44C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8000E450: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
L_8000E454:
    // 0x8000E454: jal         0x8009C850
    // 0x8000E458: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    get_filtered_cheats(rdram, ctx);
        goto after_5;
    // 0x8000E458: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    after_5:
    // 0x8000E45C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8000E460: andi        $t2, $v0, 0x20
    ctx->r10 = ctx->r2 & 0X20;
    // 0x8000E464: beq         $t2, $zero, L_8000E484
    if (ctx->r10 == 0) {
        // 0x8000E468: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_8000E484;
    }
    // 0x8000E468: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8000E46C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000E470: lwc1        $f16, 0x5740($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X5740);
    // 0x8000E474: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8000E478: nop

    // 0x8000E47C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8000E480: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
L_8000E484:
    // 0x8000E484: sw          $zero, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = 0;
    // 0x8000E488: lh          $t3, -0x4D34($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X4D34);
    // 0x8000E48C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8000E490: sh          $t3, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r11;
    // 0x8000E494: lh          $t4, -0x4D38($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X4D38);
    // 0x8000E498: nop

    // 0x8000E49C: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8000E4A0: nop

    // 0x8000E4A4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000E4A8: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
L_8000E4AC:
    // 0x8000E4AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000E4B0:
    // 0x8000E4B0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8000E4B4: jr          $ra
    // 0x8000E4B8: nop

    return;
    // 0x8000E4B8: nop

;}
RECOMP_FUNC void set_time_trial_enabled(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E4BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E4C0: jr          $ra
    // 0x8000E4C4: sb          $a0, -0x4B8C($at)
    MEM_B(-0X4B8C, ctx->r1) = ctx->r4;
    return;
    // 0x8000E4C4: sb          $a0, -0x4B8C($at)
    MEM_B(-0X4B8C, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void is_time_trial_enabled(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E4C8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000E4CC: lbu         $v0, -0x4B8C($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4B8C);
    // 0x8000E4D0: jr          $ra
    // 0x8000E4D4: nop

    return;
    // 0x8000E4D4: nop

;}
RECOMP_FUNC void is_in_time_trial(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E4D8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000E4DC: lbu         $v0, -0x4B8B($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4B8B);
    // 0x8000E4E0: jr          $ra
    // 0x8000E4E4: nop

    return;
    // 0x8000E4E4: nop

;}
RECOMP_FUNC void func_8000E4E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E4E8: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x8000E4EC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000E4F0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8000E4F4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8000E4F8: addiu       $t6, $t6, -0x4BE0
    ctx->r14 = ADD32(ctx->r14, -0X4BE0);
    // 0x8000E4FC: lw          $v0, -0x4BD0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4BD0);
    // 0x8000E500: addu        $a1, $v1, $t6
    ctx->r5 = ADD32(ctx->r3, ctx->r14);
    // 0x8000E504: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8000E508: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8000E50C: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x8000E510: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x8000E514: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8000E518: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8000E51C: addu        $t9, $t9, $v1
    ctx->r25 = ADD32(ctx->r25, ctx->r3);
    // 0x8000E520: lw          $t9, -0x4BE8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4BE8);
    // 0x8000E524: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8000E528: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x8000E52C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8000E530: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
L_8000E534:
    // 0x8000E534: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8000E538: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
    // 0x8000E53C: sb          $zero, 0x1($t0)
    MEM_B(0X1, ctx->r8) = 0;
    // 0x8000E540: sb          $zero, 0x2($t0)
    MEM_B(0X2, ctx->r8) = 0;
    // 0x8000E544: sb          $zero, 0x3($t0)
    MEM_B(0X3, ctx->r8) = 0;
    // 0x8000E548: bne         $a3, $v0, L_8000E534
    if (ctx->r7 != ctx->r2) {
        // 0x8000E54C: addiu       $t0, $t0, 0x4
        ctx->r8 = ADD32(ctx->r8, 0X4);
            goto L_8000E534;
    }
    // 0x8000E54C: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8000E550: jr          $ra
    // 0x8000E554: nop

    return;
    // 0x8000E554: nop

;}
RECOMP_FUNC void func_8000E558(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E558: lw          $v0, 0x3C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X3C);
    // 0x8000E55C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000E560: bne         $v0, $zero, L_8000E570
    if (ctx->r2 != 0) {
        // 0x8000E564: addiu       $a1, $a1, -0x4BE8
        ctx->r5 = ADD32(ctx->r5, -0X4BE8);
            goto L_8000E570;
    }
    // 0x8000E564: addiu       $a1, $a1, -0x4BE8
    ctx->r5 = ADD32(ctx->r5, -0X4BE8);
    // 0x8000E568: jr          $ra
    // 0x8000E56C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8000E56C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000E570:
    // 0x8000E570: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8000E574: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8000E578: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8000E57C: bne         $at, $zero, L_8000E5A8
    if (ctx->r1 != 0) {
        // 0x8000E580: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8000E5A8;
    }
    // 0x8000E580: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8000E584: lw          $t6, -0x4BE0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4BE0);
    // 0x8000E588: nop

    // 0x8000E58C: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8000E590: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x8000E594: slt         $at, $t8, $v0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8000E598: bne         $at, $zero, L_8000E5A8
    if (ctx->r1 != 0) {
        // 0x8000E59C: nop
    
            goto L_8000E5A8;
    }
    // 0x8000E59C: nop

    // 0x8000E5A0: jr          $ra
    // 0x8000E5A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8000E5A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000E5A8:
    // 0x8000E5A8: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x8000E5AC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8000E5B0: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8000E5B4: bne         $at, $zero, L_8000E5E0
    if (ctx->r1 != 0) {
        // 0x8000E5B8: nop
    
            goto L_8000E5E0;
    }
    // 0x8000E5B8: nop

    // 0x8000E5BC: lw          $t9, -0x4BDC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4BDC);
    // 0x8000E5C0: nop

    // 0x8000E5C4: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x8000E5C8: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x8000E5CC: slt         $at, $t1, $v1
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000E5D0: bne         $at, $zero, L_8000E5E4
    if (ctx->r1 != 0) {
        // 0x8000E5D4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000E5E4;
    }
    // 0x8000E5D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000E5D8: jr          $ra
    // 0x8000E5DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8000E5DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000E5E0:
    // 0x8000E5E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000E5E4:
    // 0x8000E5E4: jr          $ra
    // 0x8000E5E8: nop

    return;
    // 0x8000E5E8: nop

;}
RECOMP_FUNC void func_8000E5EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E5EC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8000E5F0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8000E5F4: addiu       $t3, $t3, -0x4BE0
    ctx->r11 = ADD32(ctx->r11, -0X4BE0);
    // 0x8000E5F8: addiu       $a2, $a2, -0x4BE8
    ctx->r6 = ADD32(ctx->r6, -0X4BE8);
    // 0x8000E5FC: lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1);
    // 0x8000E600: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x8000E604: lw          $t7, 0x0($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X0);
    // 0x8000E608: lw          $a1, 0x4($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X4);
    // 0x8000E60C: lw          $t9, 0x4($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X4);
    // 0x8000E610: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8000E614: andi        $t6, $v0, 0x3F
    ctx->r14 = ctx->r2 & 0X3F;
    // 0x8000E618: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000E61C: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x8000E620: addu        $t4, $t9, $a1
    ctx->r12 = ADD32(ctx->r25, ctx->r5);
    // 0x8000E624: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8000E628: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x8000E62C: bne         $at, $zero, L_8000E648
    if (ctx->r1 != 0) {
        // 0x8000E630: sw          $t4, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r12;
            goto L_8000E648;
    }
    // 0x8000E630: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x8000E634: slt         $at, $a0, $t8
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8000E638: beq         $at, $zero, L_8000E64C
    if (ctx->r1 == 0) {
        // 0x8000E63C: slt         $at, $a0, $a1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_8000E64C;
    }
    // 0x8000E63C: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8000E640: b           L_8000E66C
    // 0x8000E644: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
        goto L_8000E66C;
    // 0x8000E644: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_8000E648:
    // 0x8000E648: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
L_8000E64C:
    // 0x8000E64C: bne         $at, $zero, L_8000E670
    if (ctx->r1 != 0) {
        // 0x8000E650: lw          $t0, 0x1C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X1C);
            goto L_8000E670;
    }
    // 0x8000E650: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E654: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8000E658: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8000E65C: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8000E660: beq         $at, $zero, L_8000E670
    if (ctx->r1 == 0) {
        // 0x8000E664: lw          $t0, 0x1C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X1C);
            goto L_8000E670;
    }
    // 0x8000E664: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E668: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
L_8000E66C:
    // 0x8000E66C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
L_8000E670:
    // 0x8000E670: addu        $a2, $a0, $v0
    ctx->r6 = ADD32(ctx->r4, ctx->r2);
    // 0x8000E674: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x8000E678: addu        $a3, $sp, $t8
    ctx->r7 = ADD32(ctx->r29, ctx->r24);
    // 0x8000E67C: lw          $a3, 0x2C($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X2C);
    // 0x8000E680: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8000E684: sltu        $at, $a2, $a3
    ctx->r1 = ctx->r6 < ctx->r7 ? 1 : 0;
    // 0x8000E688: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8000E68C: beq         $at, $zero, L_8000E6F0
    if (ctx->r1 == 0) {
        // 0x8000E690: or          $t0, $t8, $zero
        ctx->r8 = ctx->r24 | 0;
            goto L_8000E6F0;
    }
    // 0x8000E690: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x8000E694: subu        $t2, $a3, $a2
    ctx->r10 = SUB32(ctx->r7, ctx->r6);
    // 0x8000E698: andi        $t9, $t2, 0x3
    ctx->r25 = ctx->r10 & 0X3;
    // 0x8000E69C: beq         $t9, $zero, L_8000E6C0
    if (ctx->r25 == 0) {
        // 0x8000E6A0: addu        $t1, $t9, $a2
        ctx->r9 = ADD32(ctx->r25, ctx->r6);
            goto L_8000E6C0;
    }
    // 0x8000E6A0: addu        $t1, $t9, $a2
    ctx->r9 = ADD32(ctx->r25, ctx->r6);
L_8000E6A4:
    // 0x8000E6A4: lbu         $t4, 0x0($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X0);
    // 0x8000E6A8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8000E6AC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000E6B0: bne         $t1, $a1, L_8000E6A4
    if (ctx->r9 != ctx->r5) {
        // 0x8000E6B4: sb          $t4, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r12;
            goto L_8000E6A4;
    }
    // 0x8000E6B4: sb          $t4, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r12;
    // 0x8000E6B8: beq         $a1, $a3, L_8000E6F0
    if (ctx->r5 == ctx->r7) {
        // 0x8000E6BC: nop
    
            goto L_8000E6F0;
    }
    // 0x8000E6BC: nop

L_8000E6C0:
    // 0x8000E6C0: lbu         $t5, 0x0($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X0);
    // 0x8000E6C4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8000E6C8: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
    // 0x8000E6CC: lbu         $t6, -0x3($a1)
    ctx->r14 = MEM_BU(ctx->r5, -0X3);
    // 0x8000E6D0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000E6D4: sb          $t6, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r14;
    // 0x8000E6D8: lbu         $t7, -0x2($a1)
    ctx->r15 = MEM_BU(ctx->r5, -0X2);
    // 0x8000E6DC: nop

    // 0x8000E6E0: sb          $t7, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r15;
    // 0x8000E6E4: lbu         $t8, -0x1($a1)
    ctx->r24 = MEM_BU(ctx->r5, -0X1);
    // 0x8000E6E8: bne         $a1, $a3, L_8000E6C0
    if (ctx->r5 != ctx->r7) {
        // 0x8000E6EC: sb          $t8, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r24;
            goto L_8000E6C0;
    }
    // 0x8000E6EC: sb          $t8, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r24;
L_8000E6F0:
    // 0x8000E6F0: addu        $v1, $t3, $t0
    ctx->r3 = ADD32(ctx->r11, ctx->r8);
    // 0x8000E6F4: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8000E6F8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8000E6FC: subu        $t4, $t9, $v0
    ctx->r12 = SUB32(ctx->r25, ctx->r2);
    // 0x8000E700: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8000E704: lw          $a2, -0x4C24($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4C24);
    // 0x8000E708: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8000E70C: blez        $a2, L_8000E794
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8000E710: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8000E794;
    }
    // 0x8000E710: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000E714: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8000E718: addiu       $t3, $t3, -0x4C28
    ctx->r11 = ADD32(ctx->r11, -0X4C28);
L_8000E71C:
    // 0x8000E71C: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x8000E720: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8000E724: addu        $t6, $t5, $t0
    ctx->r14 = ADD32(ctx->r13, ctx->r8);
    // 0x8000E728: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    // 0x8000E72C: nop

    // 0x8000E730: beq         $v1, $zero, L_8000E78C
    if (ctx->r3 == 0) {
        // 0x8000E734: slt         $at, $a1, $a2
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_8000E78C;
    }
    // 0x8000E734: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8000E738: lw          $t1, 0x3C($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X3C);
    // 0x8000E73C: nop

    // 0x8000E740: beq         $t1, $zero, L_8000E788
    if (ctx->r9 == 0) {
        // 0x8000E744: slt         $at, $a0, $t1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r9) ? 1 : 0;
            goto L_8000E788;
    }
    // 0x8000E744: slt         $at, $a0, $t1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8000E748: beq         $at, $zero, L_8000E770
    if (ctx->r1 == 0) {
        // 0x8000E74C: or          $t2, $t1, $zero
        ctx->r10 = ctx->r9 | 0;
            goto L_8000E770;
    }
    // 0x8000E74C: or          $t2, $t1, $zero
    ctx->r10 = ctx->r9 | 0;
    // 0x8000E750: slt         $at, $t1, $a3
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8000E754: beq         $at, $zero, L_8000E770
    if (ctx->r1 == 0) {
        // 0x8000E758: subu        $t7, $t1, $v0
        ctx->r15 = SUB32(ctx->r9, ctx->r2);
            goto L_8000E770;
    }
    // 0x8000E758: subu        $t7, $t1, $v0
    ctx->r15 = SUB32(ctx->r9, ctx->r2);
    // 0x8000E75C: sw          $t7, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r15;
    // 0x8000E760: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8000E764: lw          $a2, -0x4C24($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4C24);
    // 0x8000E768: b           L_8000E78C
    // 0x8000E76C: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
        goto L_8000E78C;
    // 0x8000E76C: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
L_8000E770:
    // 0x8000E770: bne         $a0, $t2, L_8000E78C
    if (ctx->r4 != ctx->r10) {
        // 0x8000E774: slt         $at, $a1, $a2
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_8000E78C;
    }
    // 0x8000E774: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8000E778: sw          $zero, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = 0;
    // 0x8000E77C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8000E780: lw          $a2, -0x4C24($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4C24);
    // 0x8000E784: nop

L_8000E788:
    // 0x8000E788: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
L_8000E78C:
    // 0x8000E78C: bne         $at, $zero, L_8000E71C
    if (ctx->r1 != 0) {
        // 0x8000E790: addiu       $t0, $t0, 0x4
        ctx->r8 = ADD32(ctx->r8, 0X4);
            goto L_8000E71C;
    }
    // 0x8000E790: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
L_8000E794:
    // 0x8000E794: jr          $ra
    // 0x8000E798: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8000E798: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8000E79C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E79C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8000E7A0: lw          $a2, -0x4BC0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4BC0);
    // 0x8000E7A4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8000E7A8: sll         $t0, $a2, 2
    ctx->r8 = S32(ctx->r6 << 2);
    // 0x8000E7AC: addiu       $t8, $t8, -0x4BE0
    ctx->r24 = ADD32(ctx->r24, -0X4BE0);
    // 0x8000E7B0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8000E7B4: lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1);
    // 0x8000E7B8: lbu         $v1, 0x1($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X1);
    // 0x8000E7BC: addu        $t5, $t5, $t0
    ctx->r13 = ADD32(ctx->r13, ctx->r8);
    // 0x8000E7C0: addu        $t1, $t0, $t8
    ctx->r9 = ADD32(ctx->r8, ctx->r24);
    // 0x8000E7C4: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x8000E7C8: lw          $t5, -0x4BD0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4BD0);
    // 0x8000E7CC: andi        $t6, $v0, 0x3F
    ctx->r14 = ctx->r2 & 0X3F;
    // 0x8000E7D0: andi        $t7, $v1, 0x3F
    ctx->r15 = ctx->r3 & 0X3F;
    // 0x8000E7D4: slt         $at, $t7, $t6
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8000E7D8: addu        $a3, $t9, $t5
    ctx->r7 = ADD32(ctx->r25, ctx->r13);
    // 0x8000E7DC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8000E7E0: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x8000E7E4: beq         $at, $zero, L_8000E820
    if (ctx->r1 == 0) {
        // 0x8000E7E8: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_8000E820;
    }
    // 0x8000E7E8: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x8000E7EC: addu        $t0, $a0, $t6
    ctx->r8 = ADD32(ctx->r4, ctx->r14);
    // 0x8000E7F0: sltu        $at, $t0, $a3
    ctx->r1 = ctx->r8 < ctx->r7 ? 1 : 0;
    // 0x8000E7F4: addu        $a2, $a0, $t7
    ctx->r6 = ADD32(ctx->r4, ctx->r15);
    // 0x8000E7F8: beq         $at, $zero, L_8000E858
    if (ctx->r1 == 0) {
        // 0x8000E7FC: or          $t2, $a3, $zero
        ctx->r10 = ctx->r7 | 0;
            goto L_8000E858;
    }
    // 0x8000E7FC: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
L_8000E800:
    // 0x8000E800: lbu         $t6, 0x0($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X0);
    // 0x8000E804: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8000E808: sltu        $at, $t0, $t2
    ctx->r1 = ctx->r8 < ctx->r10 ? 1 : 0;
    // 0x8000E80C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8000E810: bne         $at, $zero, L_8000E800
    if (ctx->r1 != 0) {
        // 0x8000E814: sb          $t6, -0x1($a2)
        MEM_B(-0X1, ctx->r6) = ctx->r14;
            goto L_8000E800;
    }
    // 0x8000E814: sb          $t6, -0x1($a2)
    MEM_B(-0X1, ctx->r6) = ctx->r14;
    // 0x8000E818: b           L_8000E85C
    // 0x8000E81C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_8000E85C;
    // 0x8000E81C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8000E820:
    // 0x8000E820: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000E824: beq         $at, $zero, L_8000E858
    if (ctx->r1 == 0) {
        // 0x8000E828: addu        $t7, $a3, $v1
        ctx->r15 = ADD32(ctx->r7, ctx->r3);
            goto L_8000E858;
    }
    // 0x8000E828: addu        $t7, $a3, $v1
    ctx->r15 = ADD32(ctx->r7, ctx->r3);
    // 0x8000E82C: subu        $a2, $t7, $v0
    ctx->r6 = SUB32(ctx->r15, ctx->r2);
    // 0x8000E830: addu        $t2, $a0, $v1
    ctx->r10 = ADD32(ctx->r4, ctx->r3);
    // 0x8000E834: sltu        $at, $t2, $a2
    ctx->r1 = ctx->r10 < ctx->r6 ? 1 : 0;
    // 0x8000E838: beq         $at, $zero, L_8000E858
    if (ctx->r1 == 0) {
        // 0x8000E83C: or          $t0, $a3, $zero
        ctx->r8 = ctx->r7 | 0;
            goto L_8000E858;
    }
    // 0x8000E83C: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
L_8000E840:
    // 0x8000E840: lbu         $t8, -0x1($t0)
    ctx->r24 = MEM_BU(ctx->r8, -0X1);
    // 0x8000E844: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8000E848: sltu        $at, $t2, $a2
    ctx->r1 = ctx->r10 < ctx->r6 ? 1 : 0;
    // 0x8000E84C: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8000E850: bne         $at, $zero, L_8000E840
    if (ctx->r1 != 0) {
        // 0x8000E854: sb          $t8, 0x0($a2)
        MEM_B(0X0, ctx->r6) = ctx->r24;
            goto L_8000E840;
    }
    // 0x8000E854: sb          $t8, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r24;
L_8000E858:
    // 0x8000E858: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8000E85C:
    // 0x8000E85C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8000E860: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
L_8000E864:
    // 0x8000E864: lbu         $t9, 0x0($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X0);
    // 0x8000E868: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8000E86C: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000E870: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8000E874: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8000E878: bne         $at, $zero, L_8000E864
    if (ctx->r1 != 0) {
        // 0x8000E87C: sb          $t9, -0x1($a3)
        MEM_B(-0X1, ctx->r7) = ctx->r25;
            goto L_8000E864;
    }
    // 0x8000E87C: sb          $t9, -0x1($a3)
    MEM_B(-0X1, ctx->r7) = ctx->r25;
    // 0x8000E880: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x8000E884: nop

    // 0x8000E888: addu        $t6, $t5, $v1
    ctx->r14 = ADD32(ctx->r13, ctx->r3);
    // 0x8000E88C: subu        $t7, $t6, $v0
    ctx->r15 = SUB32(ctx->r14, ctx->r2);
    // 0x8000E890: jr          $ra
    // 0x8000E894: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    return;
    // 0x8000E894: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
;}
RECOMP_FUNC void func_8000E898(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E898: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8000E89C: addiu       $t7, $t7, -0x4BE0
    ctx->r15 = ADD32(ctx->r15, -0X4BE0);
    // 0x8000E8A0: sll         $a2, $a1, 2
    ctx->r6 = S32(ctx->r5 << 2);
    // 0x8000E8A4: lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1);
    // 0x8000E8A8: addu        $a3, $a2, $t7
    ctx->r7 = ADD32(ctx->r6, ctx->r15);
    // 0x8000E8AC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8000E8B0: lw          $t0, 0x0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X0);
    // 0x8000E8B4: addu        $t8, $t8, $a2
    ctx->r24 = ADD32(ctx->r24, ctx->r6);
    // 0x8000E8B8: lw          $t8, -0x4BE8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4BE8);
    // 0x8000E8BC: andi        $t6, $v0, 0x3F
    ctx->r14 = ctx->r2 & 0X3F;
    // 0x8000E8C0: addu        $t9, $t0, $t6
    ctx->r25 = ADD32(ctx->r8, ctx->r14);
    // 0x8000E8C4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8000E8C8: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x8000E8CC: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x8000E8D0: blez        $t6, L_8000E940
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8000E8D4: addu        $v1, $t0, $t8
        ctx->r3 = ADD32(ctx->r8, ctx->r24);
            goto L_8000E940;
    }
    // 0x8000E8D4: addu        $v1, $t0, $t8
    ctx->r3 = ADD32(ctx->r8, ctx->r24);
    // 0x8000E8D8: andi        $t0, $t6, 0x3
    ctx->r8 = ctx->r14 & 0X3;
    // 0x8000E8DC: beq         $t0, $zero, L_8000E908
    if (ctx->r8 == 0) {
        // 0x8000E8E0: or          $a1, $t0, $zero
        ctx->r5 = ctx->r8 | 0;
            goto L_8000E908;
    }
    // 0x8000E8E0: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x8000E8E4: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
    // 0x8000E8E8: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
L_8000E8EC:
    // 0x8000E8EC: lbu         $t2, 0x0($a3)
    ctx->r10 = MEM_BU(ctx->r7, 0X0);
    // 0x8000E8F0: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8000E8F4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8000E8F8: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8000E8FC: bne         $a1, $t1, L_8000E8EC
    if (ctx->r5 != ctx->r9) {
        // 0x8000E900: sb          $t2, -0x1($a2)
        MEM_B(-0X1, ctx->r6) = ctx->r10;
            goto L_8000E8EC;
    }
    // 0x8000E900: sb          $t2, -0x1($a2)
    MEM_B(-0X1, ctx->r6) = ctx->r10;
    // 0x8000E904: beq         $t1, $v0, L_8000E940
    if (ctx->r9 == ctx->r2) {
        // 0x8000E908: addu        $a2, $v1, $t1
        ctx->r6 = ADD32(ctx->r3, ctx->r9);
            goto L_8000E940;
    }
L_8000E908:
    // 0x8000E908: addu        $a2, $v1, $t1
    ctx->r6 = ADD32(ctx->r3, ctx->r9);
    // 0x8000E90C: addu        $a3, $a0, $t1
    ctx->r7 = ADD32(ctx->r4, ctx->r9);
L_8000E910:
    // 0x8000E910: lbu         $t3, 0x0($a3)
    ctx->r11 = MEM_BU(ctx->r7, 0X0);
    // 0x8000E914: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x8000E918: sb          $t3, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r11;
    // 0x8000E91C: lbu         $t4, 0x1($a3)
    ctx->r12 = MEM_BU(ctx->r7, 0X1);
    // 0x8000E920: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8000E924: sb          $t4, -0x3($a2)
    MEM_B(-0X3, ctx->r6) = ctx->r12;
    // 0x8000E928: lbu         $t5, 0x2($a3)
    ctx->r13 = MEM_BU(ctx->r7, 0X2);
    // 0x8000E92C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8000E930: sb          $t5, -0x2($a2)
    MEM_B(-0X2, ctx->r6) = ctx->r13;
    // 0x8000E934: lbu         $t6, -0x1($a3)
    ctx->r14 = MEM_BU(ctx->r7, -0X1);
    // 0x8000E938: bne         $t1, $v0, L_8000E910
    if (ctx->r9 != ctx->r2) {
        // 0x8000E93C: sb          $t6, -0x1($a2)
        MEM_B(-0X1, ctx->r6) = ctx->r14;
            goto L_8000E910;
    }
    // 0x8000E93C: sb          $t6, -0x1($a2)
    MEM_B(-0X1, ctx->r6) = ctx->r14;
L_8000E940:
    // 0x8000E940: jr          $ra
    // 0x8000E944: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8000E944: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void get_object(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E948: bltz        $a0, L_8000E964
    if (SIGNED(ctx->r4) < 0) {
        // 0x8000E94C: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8000E964;
    }
    // 0x8000E94C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8000E950: lw          $t6, -0x4C24($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4C24);
    // 0x8000E954: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8000E958: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8000E95C: bne         $at, $zero, L_8000E96C
    if (ctx->r1 != 0) {
        // 0x8000E960: nop
    
            goto L_8000E96C;
    }
    // 0x8000E960: nop

L_8000E964:
    // 0x8000E964: jr          $ra
    // 0x8000E968: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8000E968: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000E96C:
    // 0x8000E96C: lw          $t7, -0x4C28($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4C28);
    // 0x8000E970: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8000E974: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8000E978: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x8000E97C: nop

    // 0x8000E980: jr          $ra
    // 0x8000E984: nop

    return;
    // 0x8000E984: nop

;}
RECOMP_FUNC void objGetObjList(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E988: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8000E98C: lw          $t6, -0x4C20($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4C20);
    // 0x8000E990: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8000E994: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8000E998: lw          $t7, -0x4C24($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4C24);
    // 0x8000E99C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000E9A0: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8000E9A4: lw          $v0, -0x4C28($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4C28);
    // 0x8000E9A8: jr          $ra
    // 0x8000E9AC: nop

    return;
    // 0x8000E9AC: nop

;}
RECOMP_FUNC void obj_count(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E9B0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000E9B4: lw          $v0, -0x4C24($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4C24);
    // 0x8000E9B8: jr          $ra
    // 0x8000E9BC: nop

    return;
    // 0x8000E9BC: nop

;}
RECOMP_FUNC void particle_count(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E9C0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000E9C4: lw          $v0, -0x4C1C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4C1C);
    // 0x8000E9C8: jr          $ra
    // 0x8000E9CC: nop

    return;
    // 0x8000E9CC: nop

;}
RECOMP_FUNC void add_particle_to_entity_list(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E9D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000E9D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000E9D8: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x8000E9DC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8000E9E0: ori         $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 | 0X8000;
    // 0x8000E9E4: sh          $t7, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r15;
    // 0x8000E9E8: lh          $a0, 0x2C($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X2C);
    // 0x8000E9EC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x8000E9F0: ori         $t8, $a0, 0xC000
    ctx->r24 = ctx->r4 | 0XC000;
    // 0x8000E9F4: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8000E9F8: jal         0x800245E8
    // 0x8000E9FC: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    func_800245B4(rdram, ctx);
        goto after_0;
    // 0x8000E9FC: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    after_0:
    // 0x8000EA00: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000EA04: addiu       $v0, $v0, -0x4C24
    ctx->r2 = ADD32(ctx->r2, -0X4C24);
    // 0x8000EA08: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8000EA0C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8000EA10: lw          $t1, -0x4C28($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4C28);
    // 0x8000EA14: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8000EA18: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8000EA1C: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x8000EA20: sw          $a1, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r5;
    // 0x8000EA24: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x8000EA28: nop

    // 0x8000EA2C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8000EA30: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8000EA34: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000EA38: addiu       $v0, $v0, -0x4C1C
    ctx->r2 = ADD32(ctx->r2, -0X4C1C);
    // 0x8000EA3C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8000EA40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000EA44: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8000EA48: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8000EA4C: jr          $ra
    // 0x8000EA50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8000EA50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void spawn_object(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000EA54: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8000EA58: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000EA5C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8000EA60: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8000EA64: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000EA68: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000EA6C: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x8000EA70: jal         0x8006ECD0
    // 0x8000EA74: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x8000EA74: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8000EA78: lw          $v1, 0x68($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X68);
    // 0x8000EA7C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8000EA80: lbu         $t7, 0x1($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1);
    // 0x8000EA84: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x8000EA88: andi        $t8, $t7, 0x80
    ctx->r24 = ctx->r15 & 0X80;
    // 0x8000EA8C: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8000EA90: or          $a1, $t6, $t9
    ctx->r5 = ctx->r14 | ctx->r25;
    // 0x8000EA94: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8000EA98: jal         0x800B7BD8
    // 0x8000EA9C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    update_object_stack_trace(rdram, ctx);
        goto after_1;
    // 0x8000EA9C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x8000EAA0: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
    // 0x8000EAA4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8000EAA8: andi        $t0, $v1, 0x2
    ctx->r8 = ctx->r3 & 0X2;
    // 0x8000EAAC: beq         $t0, $zero, L_8000EAC0
    if (ctx->r8 == 0) {
        // 0x8000EAB0: or          $v1, $t0, $zero
        ctx->r3 = ctx->r8 | 0;
            goto L_8000EAC0;
    }
    // 0x8000EAB0: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x8000EAB4: lh          $a0, 0x66($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X66);
    // 0x8000EAB8: b           L_8000EAE0
    // 0x8000EABC: nop

        goto L_8000EAE0;
    // 0x8000EABC: nop

L_8000EAC0:
    // 0x8000EAC0: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x8000EAC4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8000EAC8: lw          $t1, -0x4BC8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4BC8);
    // 0x8000EACC: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x8000EAD0: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x8000EAD4: lh          $a0, 0x0($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X0);
    // 0x8000EAD8: nop

    // 0x8000EADC: sh          $a0, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r4;
L_8000EAE0:
    // 0x8000EAE0: lw          $t7, -0x4D18($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4D18);
    // 0x8000EAE4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000EAE8: slt         $at, $a0, $t7
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8000EAEC: bne         $at, $zero, L_8000EAF8
    if (ctx->r1 != 0) {
        // 0x8000EAF0: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_8000EAF8;
    }
    // 0x8000EAF0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000EAF4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8000EAF8:
    // 0x8000EAF8: addiu       $v0, $v0, -0x4D28
    ctx->r2 = ADD32(ctx->r2, -0X4D28);
L_8000EAFC:
    // 0x8000EAFC: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8000EB00: nop

    // 0x8000EB04: addu        $t6, $t8, $s0
    ctx->r14 = ADD32(ctx->r24, ctx->r16);
    // 0x8000EB08: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8000EB0C: slti        $at, $s0, 0x800
    ctx->r1 = SIGNED(ctx->r16) < 0X800 ? 1 : 0;
    // 0x8000EB10: bne         $at, $zero, L_8000EAFC
    if (ctx->r1 != 0) {
        // 0x8000EB14: sw          $zero, 0x0($t6)
        MEM_W(0X0, ctx->r14) = 0;
            goto L_8000EAFC;
    }
    // 0x8000EB14: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    // 0x8000EB18: lw          $s2, 0x0($v0)
    ctx->r18 = MEM_W(ctx->r2, 0X0);
    // 0x8000EB1C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8000EB20: sh          $t9, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r25;
    // 0x8000EB24: sh          $a0, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r4;
    // 0x8000EB28: jal         0x8000C718
    // 0x8000EB2C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    load_object_header(rdram, ctx);
        goto after_2;
    // 0x8000EB2C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_2:
    // 0x8000EB30: bne         $v0, $zero, L_8000EB40
    if (ctx->r2 != 0) {
        // 0x8000EB34: sw          $v0, 0x40($s2)
        MEM_W(0X40, ctx->r18) = ctx->r2;
            goto L_8000EB40;
    }
    // 0x8000EB34: sw          $v0, 0x40($s2)
    MEM_W(0X40, ctx->r18) = ctx->r2;
    // 0x8000EB38: b           L_8000F62C
    // 0x8000EB3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000F62C;
    // 0x8000EB3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000EB40:
    // 0x8000EB40: lw          $s0, 0x40($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X40);
    // 0x8000EB44: nop

    // 0x8000EB48: lhu         $t0, 0x30($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X30);
    // 0x8000EB4C: nop

    // 0x8000EB50: andi        $t2, $t0, 0x80
    ctx->r10 = ctx->r8 & 0X80;
    // 0x8000EB54: beq         $t2, $zero, L_8000EB6C
    if (ctx->r10 == 0) {
        // 0x8000EB58: nop
    
            goto L_8000EB6C;
    }
    // 0x8000EB58: nop

    // 0x8000EB5C: lh          $t1, 0x6($s2)
    ctx->r9 = MEM_H(ctx->r18, 0X6);
    // 0x8000EB60: lw          $s0, 0x40($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X40);
    // 0x8000EB64: ori         $t3, $t1, 0x80
    ctx->r11 = ctx->r9 | 0X80;
    // 0x8000EB68: sh          $t3, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r11;
L_8000EB6C:
    // 0x8000EB6C: lb          $t4, 0x54($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X54);
    // 0x8000EB70: addiu       $at, $zero, 0x63
    ctx->r1 = ADD32(0, 0X63);
    // 0x8000EB74: bne         $t4, $at, L_8000EBA4
    if (ctx->r12 != ctx->r1) {
        // 0x8000EB78: lw          $v0, 0x68($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X68);
            goto L_8000EBA4;
    }
    // 0x8000EB78: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    // 0x8000EB7C: lw          $t5, 0x10($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X10);
    // 0x8000EB80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000EB84: andi        $t7, $t5, 0x1
    ctx->r15 = ctx->r13 & 0X1;
    // 0x8000EB88: beq         $t7, $zero, L_8000EBA4
    if (ctx->r15 == 0) {
        // 0x8000EB8C: lw          $v0, 0x68($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X68);
            goto L_8000EBA4;
    }
    // 0x8000EB8C: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    // 0x8000EB90: jal         0x800B7BD8
    // 0x8000EB94: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    update_object_stack_trace(rdram, ctx);
        goto after_3;
    // 0x8000EB94: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_3:
    // 0x8000EB98: b           L_8000F62C
    // 0x8000EB9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000F62C;
    // 0x8000EB9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000EBA0: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
L_8000EBA4:
    // 0x8000EBA4: nop

    // 0x8000EBA8: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x8000EBAC: nop

    // 0x8000EBB0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8000EBB4: nop

    // 0x8000EBB8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000EBBC: swc1        $f6, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f6.u32l;
    // 0x8000EBC0: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x8000EBC4: lwc1        $f12, 0xC($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8000EBC8: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8000EBCC: nop

    // 0x8000EBD0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8000EBD4: swc1        $f10, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->f10.u32l;
    // 0x8000EBD8: lh          $t9, 0x6($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X6);
    // 0x8000EBDC: lwc1        $f14, 0x10($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8000EBE0: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8000EBE4: nop

    // 0x8000EBE8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8000EBEC: swc1        $f18, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->f18.u32l;
    // 0x8000EBF0: lw          $a2, 0x14($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X14);
    // 0x8000EBF4: jal         0x80029F58
    // 0x8000EBF8: nop

    get_level_segment_index_from_position(rdram, ctx);
        goto after_4;
    // 0x8000EBF8: nop

    after_4:
    // 0x8000EBFC: sh          $v0, 0x2E($s2)
    MEM_H(0X2E, ctx->r18) = ctx->r2;
    // 0x8000EC00: lh          $t0, 0x4E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X4E);
    // 0x8000EC04: nop

    // 0x8000EC08: sh          $t0, 0x2C($s2)
    MEM_H(0X2C, ctx->r18) = ctx->r8;
    // 0x8000EC0C: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x8000EC10: nop

    // 0x8000EC14: sw          $t2, 0x3C($s2)
    MEM_W(0X3C, ctx->r18) = ctx->r10;
    // 0x8000EC18: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x8000EC1C: nop

    // 0x8000EC20: sh          $t1, 0x4A($s2)
    MEM_H(0X4A, ctx->r18) = ctx->r9;
    // 0x8000EC24: lh          $a0, 0x66($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X66);
    // 0x8000EC28: jal         0x800245E8
    // 0x8000EC2C: nop

    func_800245B4(rdram, ctx);
        goto after_5;
    // 0x8000EC2C: nop

    after_5:
    // 0x8000EC30: lw          $s0, 0x40($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X40);
    // 0x8000EC34: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8000EC38: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8000EC3C: nop

    // 0x8000EC40: swc1        $f4, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f4.u32l;
    // 0x8000EC44: lh          $t3, 0x50($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X50);
    // 0x8000EC48: lwc1        $f10, 0x8($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8000EC4C: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8000EC50: sb          $t4, 0x39($s2)
    MEM_B(0X39, ctx->r18) = ctx->r12;
    // 0x8000EC54: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000EC58: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8000EC5C: swc1        $f16, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->f16.u32l;
    // 0x8000EC60: lb          $a0, 0x54($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X54);
    // 0x8000EC64: jal         0x80023E64
    // 0x8000EC68: nop

    obj_init_property_flags(rdram, ctx);
        goto after_6;
    // 0x8000EC68: nop

    after_6:
    // 0x8000EC6C: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x8000EC70: lw          $s0, 0x40($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X40);
    // 0x8000EC74: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    // 0x8000EC78: lb          $t5, 0x52($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X52);
    // 0x8000EC7C: addiu       $t6, $s2, 0x80
    ctx->r14 = ADD32(ctx->r18, 0X80);
    // 0x8000EC80: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x8000EC84: sb          $t7, 0x52($s0)
    MEM_B(0X52, ctx->r16) = ctx->r15;
    // 0x8000EC88: lw          $s0, 0x40($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X40);
    // 0x8000EC8C: andi        $t9, $a3, 0x10
    ctx->r25 = ctx->r7 & 0X10;
    // 0x8000EC90: lb          $t8, 0x53($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X53);
    // 0x8000EC94: lb          $s3, 0x55($s0)
    ctx->r19 = MEM_B(ctx->r16, 0X55);
    // 0x8000EC98: sw          $t8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r24;
    // 0x8000EC9C: beq         $t9, $zero, L_8000ECA8
    if (ctx->r25 == 0) {
        // 0x8000ECA0: sw          $t6, 0x68($s2)
        MEM_W(0X68, ctx->r18) = ctx->r14;
            goto L_8000ECA8;
    }
    // 0x8000ECA0: sw          $t6, 0x68($s2)
    MEM_W(0X68, ctx->r18) = ctx->r14;
    // 0x8000ECA4: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_8000ECA8:
    // 0x8000ECA8: lb          $t0, 0x54($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X54);
    // 0x8000ECAC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000ECB0: addiu       $t2, $t0, -0x3E
    ctx->r10 = ADD32(ctx->r8, -0X3E);
    // 0x8000ECB4: sltiu       $at, $t2, 0x27
    ctx->r1 = ctx->r10 < 0X27 ? 1 : 0;
    // 0x8000ECB8: beq         $at, $zero, L_8000EDE0
    if (ctx->r1 == 0) {
        // 0x8000ECBC: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_8000EDE0;
    }
    // 0x8000ECBC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8000ECC0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000ECC4: addu        $at, $at, $t2
    gpr jr_addend_8000ECD0 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8000ECC8: lw          $t2, 0x5744($at)
    ctx->r10 = ADD32(ctx->r1, 0X5744);
    // 0x8000ECCC: nop

    // 0x8000ECD0: jr          $t2
    // 0x8000ECD4: nop

    switch (jr_addend_8000ECD0 >> 2) {
        case 0: goto L_8000ECD8; break;
        case 1: goto L_8000EDE0; break;
        case 2: goto L_8000EDE0; break;
        case 3: goto L_8000EDE0; break;
        case 4: goto L_8000EDE0; break;
        case 5: goto L_8000EDE0; break;
        case 6: goto L_8000EDE0; break;
        case 7: goto L_8000EDE0; break;
        case 8: goto L_8000EDE0; break;
        case 9: goto L_8000EDE0; break;
        case 10: goto L_8000EDE0; break;
        case 11: goto L_8000EDE0; break;
        case 12: goto L_8000EDE0; break;
        case 13: goto L_8000EDE0; break;
        case 14: goto L_8000EDE0; break;
        case 15: goto L_8000ED98; break;
        case 16: goto L_8000EDE0; break;
        case 17: goto L_8000EDE0; break;
        case 18: goto L_8000EDE0; break;
        case 19: goto L_8000EDE0; break;
        case 20: goto L_8000EDE0; break;
        case 21: goto L_8000EDE0; break;
        case 22: goto L_8000EDE0; break;
        case 23: goto L_8000EDE0; break;
        case 24: goto L_8000ECF4; break;
        case 25: goto L_8000EDE0; break;
        case 26: goto L_8000EDE0; break;
        case 27: goto L_8000EDE0; break;
        case 28: goto L_8000EDE0; break;
        case 29: goto L_8000ED10; break;
        case 30: goto L_8000EDE0; break;
        case 31: goto L_8000EDE0; break;
        case 32: goto L_8000EDE0; break;
        case 33: goto L_8000ED40; break;
        case 34: goto L_8000EDE0; break;
        case 35: goto L_8000EDE0; break;
        case 36: goto L_8000EDE0; break;
        case 37: goto L_8000EDE0; break;
        case 38: goto L_8000ED54; break;
        default: switch_error(__func__, 0x8000ECD0, 0x800E5744);
    }
    // 0x8000ECD4: nop

L_8000ECD8:
    // 0x8000ECD8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8000ECDC: jal         0x80061C34
    // 0x8000ECE0: sw          $a2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r6;
    model_anim_offset(rdram, ctx);
        goto after_7;
    // 0x8000ECE0: sw          $a2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r6;
    after_7:
    // 0x8000ECE4: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x8000ECE8: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    // 0x8000ECEC: b           L_8000EDE4
    // 0x8000ECF0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
        goto L_8000EDE4;
    // 0x8000ECF0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
L_8000ECF4:
    // 0x8000ECF4: jal         0x8009C76C
    // 0x8000ECF8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    get_character_id_from_slot(rdram, ctx);
        goto after_8;
    // 0x8000ECF8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_8:
    // 0x8000ECFC: sb          $v0, 0x3A($s2)
    MEM_B(0X3A, ctx->r18) = ctx->r2;
    // 0x8000ED00: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    // 0x8000ED04: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8000ED08: b           L_8000EDE0
    // 0x8000ED0C: addiu       $s3, $v0, 0x1
    ctx->r19 = ADD32(ctx->r2, 0X1);
        goto L_8000EDE0;
    // 0x8000ED0C: addiu       $s3, $v0, 0x1
    ctx->r19 = ADD32(ctx->r2, 0X1);
L_8000ED10:
    // 0x8000ED10: lbu         $t3, 0x48($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X48);
    // 0x8000ED14: lhu         $t1, 0xE($s1)
    ctx->r9 = MEM_HU(ctx->r17, 0XE);
    // 0x8000ED18: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x8000ED1C: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8000ED20: srav        $a2, $t1, $t5
    ctx->r6 = S32(SIGNED(ctx->r9) >> (ctx->r13 & 31));
    // 0x8000ED24: andi        $t7, $a2, 0x3
    ctx->r15 = ctx->r6 & 0X3;
    // 0x8000ED28: beq         $t7, $zero, L_8000EDE0
    if (ctx->r15 == 0) {
        // 0x8000ED2C: or          $a2, $t7, $zero
        ctx->r6 = ctx->r15 | 0;
            goto L_8000EDE0;
    }
    // 0x8000ED2C: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x8000ED30: addiu       $a2, $t7, -0x1
    ctx->r6 = ADD32(ctx->r15, -0X1);
    // 0x8000ED34: addiu       $s3, $a2, 0x1
    ctx->r19 = ADD32(ctx->r6, 0X1);
    // 0x8000ED38: b           L_8000EDE0
    // 0x8000ED3C: sb          $a2, 0x3A($s2)
    MEM_B(0X3A, ctx->r18) = ctx->r6;
        goto L_8000EDE0;
    // 0x8000ED3C: sb          $a2, 0x3A($s2)
    MEM_B(0X3A, ctx->r18) = ctx->r6;
L_8000ED40:
    // 0x8000ED40: lbu         $a2, 0x17($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X17);
    // 0x8000ED44: nop

    // 0x8000ED48: addiu       $s3, $a2, 0x1
    ctx->r19 = ADD32(ctx->r6, 0X1);
    // 0x8000ED4C: b           L_8000EDE0
    // 0x8000ED50: sb          $a2, 0x3A($s2)
    MEM_B(0X3A, ctx->r18) = ctx->r6;
        goto L_8000EDE0;
    // 0x8000ED50: sb          $a2, 0x3A($s2)
    MEM_B(0X3A, ctx->r18) = ctx->r6;
L_8000ED54:
    // 0x8000ED54: lhu         $t8, 0xE($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0XE);
    // 0x8000ED58: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8000ED5C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000ED60: sw          $t8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r24;
L_8000ED64:
    // 0x8000ED64: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x8000ED68: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x8000ED6C: andi        $t9, $t6, 0x3
    ctx->r25 = ctx->r14 & 0X3;
    // 0x8000ED70: bne         $v0, $t9, L_8000ED7C
    if (ctx->r2 != ctx->r25) {
        // 0x8000ED74: sra         $t2, $t0, 2
        ctx->r10 = S32(SIGNED(ctx->r8) >> 2);
            goto L_8000ED7C;
    }
    // 0x8000ED74: sra         $t2, $t0, 2
    ctx->r10 = S32(SIGNED(ctx->r8) >> 2);
    // 0x8000ED78: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8000ED7C:
    // 0x8000ED7C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8000ED80: slti        $at, $s3, 0x4
    ctx->r1 = SIGNED(ctx->r19) < 0X4 ? 1 : 0;
    // 0x8000ED84: bne         $at, $zero, L_8000ED64
    if (ctx->r1 != 0) {
        // 0x8000ED88: sw          $t2, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r10;
            goto L_8000ED64;
    }
    // 0x8000ED88: sw          $t2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r10;
    // 0x8000ED8C: sb          $a2, 0x3A($s2)
    MEM_B(0X3A, ctx->r18) = ctx->r6;
    // 0x8000ED90: b           L_8000EDE0
    // 0x8000ED94: addiu       $s3, $a2, 0x1
    ctx->r19 = ADD32(ctx->r6, 0X1);
        goto L_8000EDE0;
    // 0x8000ED94: addiu       $s3, $a2, 0x1
    ctx->r19 = ADD32(ctx->r6, 0X1);
L_8000ED98:
    // 0x8000ED98: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8000ED9C: jal         0x8009F1B4
    // 0x8000EDA0: sw          $a2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r6;
    is_in_adventure_two(rdram, ctx);
        goto after_9;
    // 0x8000EDA0: sw          $a2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r6;
    after_9:
    // 0x8000EDA4: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x8000EDA8: beq         $v0, $zero, L_8000EDCC
    if (ctx->r2 == 0) {
        // 0x8000EDAC: nop
    
            goto L_8000EDCC;
    }
    // 0x8000EDAC: nop

    // 0x8000EDB0: lw          $t3, 0x40($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X40);
    // 0x8000EDB4: nop

    // 0x8000EDB8: lw          $v0, 0x10($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X10);
    // 0x8000EDBC: nop

    // 0x8000EDC0: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x8000EDC4: nop

    // 0x8000EDC8: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_8000EDCC:
    // 0x8000EDCC: lw          $t5, 0x40($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X40);
    // 0x8000EDD0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8000EDD4: sb          $t1, 0x55($t5)
    MEM_B(0X55, ctx->r13) = ctx->r9;
    // 0x8000EDD8: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    // 0x8000EDDC: nop

L_8000EDE0:
    // 0x8000EDE0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
L_8000EDE4:
    // 0x8000EDE4: nop

    // 0x8000EDE8: bne         $t7, $zero, L_8000EF18
    if (ctx->r15 != 0) {
        // 0x8000EDEC: lw          $t8, 0x64($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X64);
            goto L_8000EF18;
    }
    // 0x8000EDEC: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x8000EDF0: lh          $v0, 0x4A($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X4A);
    // 0x8000EDF4: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x8000EDF8: beq         $v0, $at, L_8000EE54
    if (ctx->r2 == ctx->r1) {
        // 0x8000EDFC: addiu       $at, $zero, 0xCB
        ctx->r1 = ADD32(0, 0XCB);
            goto L_8000EE54;
    }
    // 0x8000EDFC: addiu       $at, $zero, 0xCB
    ctx->r1 = ADD32(0, 0XCB);
    // 0x8000EE00: bne         $v0, $at, L_8000EF18
    if (ctx->r2 != ctx->r1) {
        // 0x8000EE04: lw          $t8, 0x64($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X64);
            goto L_8000EF18;
    }
    // 0x8000EE04: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x8000EE08: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8000EE0C: jal         0x8009F1B4
    // 0x8000EE10: sw          $a2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r6;
    is_in_adventure_two(rdram, ctx);
        goto after_10;
    // 0x8000EE10: sw          $a2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r6;
    after_10:
    // 0x8000EE14: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x8000EE18: beq         $v0, $zero, L_8000EE3C
    if (ctx->r2 == 0) {
        // 0x8000EE1C: nop
    
            goto L_8000EE3C;
    }
    // 0x8000EE1C: nop

    // 0x8000EE20: lw          $t8, 0x40($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X40);
    // 0x8000EE24: nop

    // 0x8000EE28: lw          $v0, 0x10($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X10);
    // 0x8000EE2C: nop

    // 0x8000EE30: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x8000EE34: nop

    // 0x8000EE38: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_8000EE3C:
    // 0x8000EE3C: lw          $t0, 0x40($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X40);
    // 0x8000EE40: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8000EE44: sb          $t9, 0x55($t0)
    MEM_B(0X55, ctx->r8) = ctx->r25;
    // 0x8000EE48: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    // 0x8000EE4C: b           L_8000EF18
    // 0x8000EE50: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
        goto L_8000EF18;
    // 0x8000EE50: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
L_8000EE54:
    // 0x8000EE54: jal         0x8009F1B4
    // 0x8000EE58: nop

    is_in_adventure_two(rdram, ctx);
        goto after_11;
    // 0x8000EE58: nop

    after_11:
    // 0x8000EE5C: beq         $v0, $zero, L_8000EF00
    if (ctx->r2 == 0) {
        // 0x8000EE60: addiu       $s3, $zero, 0x5
        ctx->r19 = ADD32(0, 0X5);
            goto L_8000EF00;
    }
    // 0x8000EE60: addiu       $s3, $zero, 0x5
    ctx->r19 = ADD32(0, 0X5);
    // 0x8000EE64: lw          $t2, 0x40($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X40);
    // 0x8000EE68: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8000EE6C: lw          $v0, 0x10($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X10);
    // 0x8000EE70: sll         $s0, $a2, 2
    ctx->r16 = S32(ctx->r6 << 2);
    // 0x8000EE74: lw          $t3, 0x14($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X14);
    // 0x8000EE78: nop

    // 0x8000EE7C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8000EE80: lw          $t4, 0x40($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X40);
    // 0x8000EE84: nop

    // 0x8000EE88: lw          $t1, 0x10($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X10);
    // 0x8000EE8C: nop

    // 0x8000EE90: addu        $v0, $t1, $s0
    ctx->r2 = ADD32(ctx->r9, ctx->r16);
    // 0x8000EE94: lw          $t5, 0x14($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X14);
    // 0x8000EE98: nop

    // 0x8000EE9C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8000EEA0: lw          $t7, 0x40($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X40);
    // 0x8000EEA4: nop

    // 0x8000EEA8: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x8000EEAC: nop

    // 0x8000EEB0: addu        $v0, $t8, $s0
    ctx->r2 = ADD32(ctx->r24, ctx->r16);
    // 0x8000EEB4: lw          $t6, 0x18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X18);
    // 0x8000EEB8: nop

    // 0x8000EEBC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8000EEC0: lw          $t9, 0x40($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X40);
    // 0x8000EEC4: nop

    // 0x8000EEC8: lw          $t0, 0x10($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X10);
    // 0x8000EECC: nop

    // 0x8000EED0: addu        $v0, $t0, $s0
    ctx->r2 = ADD32(ctx->r8, ctx->r16);
    // 0x8000EED4: lw          $t2, 0x1C($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X1C);
    // 0x8000EED8: nop

    // 0x8000EEDC: sw          $t2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r10;
    // 0x8000EEE0: lw          $t3, 0x40($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X40);
    // 0x8000EEE4: nop

    // 0x8000EEE8: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x8000EEEC: nop

    // 0x8000EEF0: addu        $v0, $t4, $s0
    ctx->r2 = ADD32(ctx->r12, ctx->r16);
    // 0x8000EEF4: lw          $t1, 0x20($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X20);
    // 0x8000EEF8: nop

    // 0x8000EEFC: sw          $t1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r9;
L_8000EF00:
    // 0x8000EF00: lw          $t7, 0x40($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X40);
    // 0x8000EF04: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x8000EF08: sb          $t5, 0x55($t7)
    MEM_B(0X55, ctx->r15) = ctx->r13;
    // 0x8000EF0C: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    // 0x8000EF10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000EF14: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
L_8000EF18:
    // 0x8000EF18: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x8000EF1C: bne         $t8, $zero, L_8000EFEC
    if (ctx->r24 != 0) {
        // 0x8000EF20: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8000EFEC;
    }
    // 0x8000EF20: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8000EF24: slt         $at, $a2, $s3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8000EF28: beq         $at, $zero, L_8000F0C4
    if (ctx->r1 == 0) {
        // 0x8000EF2C: sll         $s0, $a2, 2
        ctx->r16 = S32(ctx->r6 << 2);
            goto L_8000F0C4;
    }
    // 0x8000EF2C: sll         $s0, $a2, 2
    ctx->r16 = S32(ctx->r6 << 2);
L_8000EF30:
    // 0x8000EF30: bne         $a2, $zero, L_8000EF58
    if (ctx->r6 != 0) {
        // 0x8000EF34: addiu       $s1, $a2, 0x1
        ctx->r17 = ADD32(ctx->r6, 0X1);
            goto L_8000EF58;
    }
    // 0x8000EF34: addiu       $s1, $a2, 0x1
    ctx->r17 = ADD32(ctx->r6, 0X1);
    // 0x8000EF38: andi        $t6, $a3, 0x4
    ctx->r14 = ctx->r7 & 0X4;
    // 0x8000EF3C: beq         $t6, $zero, L_8000EF5C
    if (ctx->r14 == 0) {
        // 0x8000EF40: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8000EF5C;
    }
    // 0x8000EF40: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000EF44: lw          $t9, 0x68($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X68);
    // 0x8000EF48: nop

    // 0x8000EF4C: addu        $t0, $t9, $s0
    ctx->r8 = ADD32(ctx->r25, ctx->r16);
    // 0x8000EF50: b           L_8000EFD0
    // 0x8000EF54: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
        goto L_8000EFD0;
    // 0x8000EF54: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
L_8000EF58:
    // 0x8000EF58: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8000EF5C:
    // 0x8000EF5C: bne         $a2, $at, L_8000EF80
    if (ctx->r6 != ctx->r1) {
        // 0x8000EF60: andi        $t2, $a3, 0x8
        ctx->r10 = ctx->r7 & 0X8;
            goto L_8000EF80;
    }
    // 0x8000EF60: andi        $t2, $a3, 0x8
    ctx->r10 = ctx->r7 & 0X8;
    // 0x8000EF64: beq         $t2, $zero, L_8000EF80
    if (ctx->r10 == 0) {
        // 0x8000EF68: nop
    
            goto L_8000EF80;
    }
    // 0x8000EF68: nop

    // 0x8000EF6C: lw          $t3, 0x68($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X68);
    // 0x8000EF70: nop

    // 0x8000EF74: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x8000EF78: b           L_8000EFD0
    // 0x8000EF7C: sw          $zero, 0x0($t4)
    MEM_W(0X0, ctx->r12) = 0;
        goto L_8000EFD0;
    // 0x8000EF7C: sw          $zero, 0x0($t4)
    MEM_W(0X0, ctx->r12) = 0;
L_8000EF80:
    // 0x8000EF80: lw          $t1, 0x40($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X40);
    // 0x8000EF84: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x8000EF88: lw          $t5, 0x10($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X10);
    // 0x8000EF8C: nop

    // 0x8000EF90: addu        $t7, $t5, $s0
    ctx->r15 = ADD32(ctx->r13, ctx->r16);
    // 0x8000EF94: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x8000EF98: jal         0x8005FB3C
    // 0x8000EF9C: sb          $v1, 0x37($sp)
    MEM_B(0X37, ctx->r29) = ctx->r3;
    object_model_init(rdram, ctx);
        goto after_12;
    // 0x8000EF9C: sb          $v1, 0x37($sp)
    MEM_B(0X37, ctx->r29) = ctx->r3;
    after_12:
    // 0x8000EFA0: lw          $t8, 0x68($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X68);
    // 0x8000EFA4: lb          $v1, 0x37($sp)
    ctx->r3 = MEM_B(ctx->r29, 0X37);
    // 0x8000EFA8: addu        $t6, $t8, $s0
    ctx->r14 = ADD32(ctx->r24, ctx->r16);
    // 0x8000EFAC: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x8000EFB0: lw          $t9, 0x68($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X68);
    // 0x8000EFB4: nop

    // 0x8000EFB8: addu        $t0, $t9, $s0
    ctx->r8 = ADD32(ctx->r25, ctx->r16);
    // 0x8000EFBC: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8000EFC0: nop

    // 0x8000EFC4: bne         $t2, $zero, L_8000EFD4
    if (ctx->r10 != 0) {
        // 0x8000EFC8: lw          $a3, 0x6C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X6C);
            goto L_8000EFD4;
    }
    // 0x8000EFC8: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    // 0x8000EFCC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8000EFD0:
    // 0x8000EFD0: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
L_8000EFD4:
    // 0x8000EFD4: slt         $at, $s1, $s3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8000EFD8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8000EFDC: bne         $at, $zero, L_8000EF30
    if (ctx->r1 != 0) {
        // 0x8000EFE0: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8000EF30;
    }
    // 0x8000EFE0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8000EFE4: b           L_8000F0C4
    // 0x8000EFE8: nop

        goto L_8000F0C4;
    // 0x8000EFE8: nop

L_8000EFEC:
    // 0x8000EFEC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8000EFF0: bne         $t3, $at, L_8000F060
    if (ctx->r11 != ctx->r1) {
        // 0x8000EFF4: slt         $at, $a2, $s3
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r19) ? 1 : 0;
            goto L_8000F060;
    }
    // 0x8000EFF4: slt         $at, $a2, $s3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8000EFF8: beq         $at, $zero, L_8000F0C4
    if (ctx->r1 == 0) {
        // 0x8000EFFC: sll         $s0, $a2, 2
        ctx->r16 = S32(ctx->r6 << 2);
            goto L_8000F0C4;
    }
    // 0x8000EFFC: sll         $s0, $a2, 2
    ctx->r16 = S32(ctx->r6 << 2);
L_8000F000:
    // 0x8000F000: lw          $t4, 0x40($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X40);
    // 0x8000F004: addiu       $s1, $a2, 0x1
    ctx->r17 = ADD32(ctx->r6, 0X1);
    // 0x8000F008: lw          $t1, 0x10($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X10);
    // 0x8000F00C: nop

    // 0x8000F010: addu        $t5, $t1, $s0
    ctx->r13 = ADD32(ctx->r9, ctx->r16);
    // 0x8000F014: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x8000F018: jal         0x8007B2C4
    // 0x8000F01C: sb          $v1, 0x37($sp)
    MEM_B(0X37, ctx->r29) = ctx->r3;
    load_texture(rdram, ctx);
        goto after_13;
    // 0x8000F01C: sb          $v1, 0x37($sp)
    MEM_B(0X37, ctx->r29) = ctx->r3;
    after_13:
    // 0x8000F020: lw          $t7, 0x68($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X68);
    // 0x8000F024: lb          $v1, 0x37($sp)
    ctx->r3 = MEM_B(ctx->r29, 0X37);
    // 0x8000F028: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x8000F02C: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    // 0x8000F030: lw          $t6, 0x68($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X68);
    // 0x8000F034: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8000F038: addu        $t9, $t6, $s0
    ctx->r25 = ADD32(ctx->r14, ctx->r16);
    // 0x8000F03C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8000F040: slt         $at, $s1, $s3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8000F044: bne         $t0, $zero, L_8000F050
    if (ctx->r8 != 0) {
        // 0x8000F048: nop
    
            goto L_8000F050;
    }
    // 0x8000F048: nop

    // 0x8000F04C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8000F050:
    // 0x8000F050: bne         $at, $zero, L_8000F000
    if (ctx->r1 != 0) {
        // 0x8000F054: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8000F000;
    }
    // 0x8000F054: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8000F058: b           L_8000F0C4
    // 0x8000F05C: nop

        goto L_8000F0C4;
    // 0x8000F05C: nop

L_8000F060:
    // 0x8000F060: slt         $at, $a2, $s3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8000F064: beq         $at, $zero, L_8000F0C4
    if (ctx->r1 == 0) {
        // 0x8000F068: sll         $s0, $a2, 2
        ctx->r16 = S32(ctx->r6 << 2);
            goto L_8000F0C4;
    }
    // 0x8000F068: sll         $s0, $a2, 2
    ctx->r16 = S32(ctx->r6 << 2);
L_8000F06C:
    // 0x8000F06C: lw          $t2, 0x40($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X40);
    // 0x8000F070: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8000F074: lw          $t3, 0x10($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X10);
    // 0x8000F078: addiu       $s1, $a2, 0x1
    ctx->r17 = ADD32(ctx->r6, 0X1);
    // 0x8000F07C: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x8000F080: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x8000F084: jal         0x8007C57C
    // 0x8000F088: sb          $v1, 0x37($sp)
    MEM_B(0X37, ctx->r29) = ctx->r3;
    tex_load_sprite(rdram, ctx);
        goto after_14;
    // 0x8000F088: sb          $v1, 0x37($sp)
    MEM_B(0X37, ctx->r29) = ctx->r3;
    after_14:
    // 0x8000F08C: lw          $t1, 0x68($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X68);
    // 0x8000F090: lb          $v1, 0x37($sp)
    ctx->r3 = MEM_B(ctx->r29, 0X37);
    // 0x8000F094: addu        $t5, $t1, $s0
    ctx->r13 = ADD32(ctx->r9, ctx->r16);
    // 0x8000F098: sw          $v0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r2;
    // 0x8000F09C: lw          $t7, 0x68($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X68);
    // 0x8000F0A0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8000F0A4: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x8000F0A8: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x8000F0AC: slt         $at, $s1, $s3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8000F0B0: bne         $t6, $zero, L_8000F0BC
    if (ctx->r14 != 0) {
        // 0x8000F0B4: nop
    
            goto L_8000F0BC;
    }
    // 0x8000F0B4: nop

    // 0x8000F0B8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8000F0BC:
    // 0x8000F0BC: bne         $at, $zero, L_8000F06C
    if (ctx->r1 != 0) {
        // 0x8000F0C0: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8000F06C;
    }
    // 0x8000F0C0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8000F0C4:
    // 0x8000F0C4: beq         $v1, $zero, L_8000F0EC
    if (ctx->r3 == 0) {
        // 0x8000F0C8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8000F0EC;
    }
    // 0x8000F0C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000F0CC: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    // 0x8000F0D0: jal         0x8000F648
    // 0x8000F0D4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    objFreeAssets(rdram, ctx);
        goto after_15;
    // 0x8000F0D4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_15:
    // 0x8000F0D8: lh          $a0, 0x4E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X4E);
    // 0x8000F0DC: jal         0x8000C844
    // 0x8000F0E0: nop

    try_free_object_header(rdram, ctx);
        goto after_16;
    // 0x8000F0E0: nop

    after_16:
    // 0x8000F0E4: b           L_8000F62C
    // 0x8000F0E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000F62C;
    // 0x8000F0E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000F0EC:
    // 0x8000F0EC: lw          $t0, 0x40($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X40);
    // 0x8000F0F0: lw          $t9, 0x68($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X68);
    // 0x8000F0F4: lb          $t2, 0x55($t0)
    ctx->r10 = MEM_B(ctx->r8, 0X55);
    // 0x8000F0F8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000F0FC: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8000F100: addu        $a1, $t9, $t3
    ctx->r5 = ADD32(ctx->r25, ctx->r11);
    // 0x8000F104: jal         0x80023610
    // 0x8000F108: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    get_object_property_size(rdram, ctx);
        goto after_17;
    // 0x8000F108: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    after_17:
    // 0x8000F10C: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8000F110: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000F114: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8000F118: sw          $zero, -0x4C30($at)
    MEM_W(-0X4C30, ctx->r1) = 0;
    // 0x8000F11C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000F120: andi        $t1, $t4, 0x1
    ctx->r9 = ctx->r12 & 0X1;
    // 0x8000F124: sw          $zero, -0x4C2C($at)
    MEM_W(-0X4C2C, ctx->r1) = 0;
    // 0x8000F128: beq         $t1, $zero, L_8000F14C
    if (ctx->r9 == 0) {
        // 0x8000F12C: addu        $a2, $a2, $v0
        ctx->r6 = ADD32(ctx->r6, ctx->r2);
            goto L_8000F14C;
    }
    // 0x8000F12C: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x8000F130: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000F134: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8000F138: jal         0x8000F7EC
    // 0x8000F13C: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    init_object_shading(rdram, ctx);
        goto after_18;
    // 0x8000F13C: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_18:
    // 0x8000F140: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8000F144: nop

    // 0x8000F148: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
L_8000F14C:
    // 0x8000F14C: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8000F150: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000F154: andi        $t7, $t5, 0x2
    ctx->r15 = ctx->r13 & 0X2;
    // 0x8000F158: beq         $t7, $zero, L_8000F198
    if (ctx->r15 == 0) {
        // 0x8000F15C: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_8000F198;
    }
    // 0x8000F15C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8000F160: jal         0x8000FBCC
    // 0x8000F164: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    init_object_shadow(rdram, ctx);
        goto after_19;
    // 0x8000F164: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_19:
    // 0x8000F168: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8000F16C: bne         $v0, $zero, L_8000F198
    if (ctx->r2 != 0) {
        // 0x8000F170: addu        $a2, $a2, $v0
        ctx->r6 = ADD32(ctx->r6, ctx->r2);
            goto L_8000F198;
    }
    // 0x8000F170: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x8000F174: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    // 0x8000F178: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000F17C: jal         0x8000F648
    // 0x8000F180: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    objFreeAssets(rdram, ctx);
        goto after_20;
    // 0x8000F180: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_20:
    // 0x8000F184: lh          $a0, 0x4E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X4E);
    // 0x8000F188: jal         0x8000C844
    // 0x8000F18C: nop

    try_free_object_header(rdram, ctx);
        goto after_21;
    // 0x8000F18C: nop

    after_21:
    // 0x8000F190: b           L_8000F62C
    // 0x8000F194: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000F62C;
    // 0x8000F194: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000F198:
    // 0x8000F198: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8000F19C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000F1A0: andi        $t6, $t8, 0x4
    ctx->r14 = ctx->r24 & 0X4;
    // 0x8000F1A4: beq         $t6, $zero, L_8000F200
    if (ctx->r14 == 0) {
        // 0x8000F1A8: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_8000F200;
    }
    // 0x8000F1A8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8000F1AC: jal         0x8000FC6C
    // 0x8000F1B0: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    init_object_water_effect(rdram, ctx);
        goto after_22;
    // 0x8000F1B0: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_22:
    // 0x8000F1B4: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8000F1B8: bne         $v0, $zero, L_8000F200
    if (ctx->r2 != 0) {
        // 0x8000F1BC: addu        $a2, $a2, $v0
        ctx->r6 = ADD32(ctx->r6, ctx->r2);
            goto L_8000F200;
    }
    // 0x8000F1BC: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x8000F1C0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000F1C4: lw          $v0, -0x4C30($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4C30);
    // 0x8000F1C8: nop

    // 0x8000F1CC: beq         $v0, $zero, L_8000F1E0
    if (ctx->r2 == 0) {
        // 0x8000F1D0: lw          $a2, 0x64($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X64);
            goto L_8000F1E0;
    }
    // 0x8000F1D0: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    // 0x8000F1D4: jal         0x8007B70C
    // 0x8000F1D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    tex_free(rdram, ctx);
        goto after_23;
    // 0x8000F1D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_23:
    // 0x8000F1DC: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
L_8000F1E0:
    // 0x8000F1E0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000F1E4: jal         0x8000F648
    // 0x8000F1E8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    objFreeAssets(rdram, ctx);
        goto after_24;
    // 0x8000F1E8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_24:
    // 0x8000F1EC: lh          $a0, 0x4E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X4E);
    // 0x8000F1F0: jal         0x8000C844
    // 0x8000F1F4: nop

    try_free_object_header(rdram, ctx);
        goto after_25;
    // 0x8000F1F4: nop

    after_25:
    // 0x8000F1F8: b           L_8000F62C
    // 0x8000F1FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000F62C;
    // 0x8000F1FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000F200:
    // 0x8000F200: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8000F204: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000F208: andi        $t2, $t0, 0x10
    ctx->r10 = ctx->r8 & 0X10;
    // 0x8000F20C: beq         $t2, $zero, L_8000F228
    if (ctx->r10 == 0) {
        // 0x8000F210: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_8000F228;
    }
    // 0x8000F210: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8000F214: jal         0x8000FD20
    // 0x8000F218: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    init_object_interaction_data(rdram, ctx);
        goto after_26;
    // 0x8000F218: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_26:
    // 0x8000F21C: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8000F220: nop

    // 0x8000F224: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
L_8000F228:
    // 0x8000F228: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8000F22C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000F230: andi        $t3, $t9, 0x20
    ctx->r11 = ctx->r25 & 0X20;
    // 0x8000F234: beq         $t3, $zero, L_8000F250
    if (ctx->r11 == 0) {
        // 0x8000F238: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_8000F250;
    }
    // 0x8000F238: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8000F23C: jal         0x8000FD34
    // 0x8000F240: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    obj_init_collision(rdram, ctx);
        goto after_27;
    // 0x8000F240: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_27:
    // 0x8000F244: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8000F248: nop

    // 0x8000F24C: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
L_8000F250:
    // 0x8000F250: lw          $s0, 0x40($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X40);
    // 0x8000F254: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000F258: lb          $v0, 0x56($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X56);
    // 0x8000F25C: nop

    // 0x8000F260: blez        $v0, L_8000F27C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8000F264: slti        $at, $v0, 0xA
        ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
            goto L_8000F27C;
    }
    // 0x8000F264: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x8000F268: beq         $at, $zero, L_8000F27C
    if (ctx->r1 == 0) {
        // 0x8000F26C: nop
    
            goto L_8000F27C;
    }
    // 0x8000F26C: nop

    // 0x8000F270: sw          $a2, 0x60($s2)
    MEM_W(0X60, ctx->r18) = ctx->r6;
    // 0x8000F274: lw          $s0, 0x40($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X40);
    // 0x8000F278: addiu       $a2, $a2, 0x30
    ctx->r6 = ADD32(ctx->r6, 0X30);
L_8000F27C:
    // 0x8000F27C: lb          $t4, 0x57($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X57);
    // 0x8000F280: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8000F284: blez        $t4, L_8000F2A0
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8000F288: nop
    
            goto L_8000F2A0;
    }
    // 0x8000F288: nop

    // 0x8000F28C: jal         0x8000FAC4
    // 0x8000F290: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    obj_init_emitter(rdram, ctx);
        goto after_28;
    // 0x8000F290: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_28:
    // 0x8000F294: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8000F298: lw          $s0, 0x40($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X40);
    // 0x8000F29C: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
L_8000F2A0:
    // 0x8000F2A0: lb          $t1, 0x5A($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X5A);
    // 0x8000F2A4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000F2A8: blez        $t1, L_8000F2C8
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8000F2AC: subu        $a1, $a2, $s2
        ctx->r5 = SUB32(ctx->r6, ctx->r18);
            goto L_8000F2C8;
    }
    // 0x8000F2AC: subu        $a1, $a2, $s2
    ctx->r5 = SUB32(ctx->r6, ctx->r18);
    // 0x8000F2B0: sw          $a2, 0x70($s2)
    MEM_W(0X70, ctx->r18) = ctx->r6;
    // 0x8000F2B4: lb          $t5, 0x5A($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X5A);
    // 0x8000F2B8: nop

    // 0x8000F2BC: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8000F2C0: addu        $a2, $a2, $t7
    ctx->r6 = ADD32(ctx->r6, ctx->r15);
    // 0x8000F2C4: subu        $a1, $a2, $s2
    ctx->r5 = SUB32(ctx->r6, ctx->r18);
L_8000F2C8:
    // 0x8000F2C8: lw          $a0, -0x4C18($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C18);
    // 0x8000F2CC: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8000F2D0: jal         0x800710D0
    // 0x8000F2D4: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    mempool_alloc_pool(rdram, ctx);
        goto after_29;
    // 0x8000F2D4: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    after_29:
    // 0x8000F2D8: bne         $v0, $zero, L_8000F33C
    if (ctx->r2 != 0) {
        // 0x8000F2DC: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_8000F33C;
    }
    // 0x8000F2DC: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8000F2E0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000F2E4: lw          $v0, -0x4C30($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4C30);
    // 0x8000F2E8: nop

    // 0x8000F2EC: beq         $v0, $zero, L_8000F2FC
    if (ctx->r2 == 0) {
        // 0x8000F2F0: nop
    
            goto L_8000F2FC;
    }
    // 0x8000F2F0: nop

    // 0x8000F2F4: jal         0x8007B70C
    // 0x8000F2F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    tex_free(rdram, ctx);
        goto after_30;
    // 0x8000F2F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_30:
L_8000F2FC:
    // 0x8000F2FC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000F300: lw          $v0, -0x4C2C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4C2C);
    // 0x8000F304: nop

    // 0x8000F308: beq         $v0, $zero, L_8000F31C
    if (ctx->r2 == 0) {
        // 0x8000F30C: lw          $a2, 0x64($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X64);
            goto L_8000F31C;
    }
    // 0x8000F30C: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    // 0x8000F310: jal         0x8007B70C
    // 0x8000F314: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    tex_free(rdram, ctx);
        goto after_31;
    // 0x8000F314: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_31:
    // 0x8000F318: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
L_8000F31C:
    // 0x8000F31C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000F320: jal         0x8000F648
    // 0x8000F324: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    objFreeAssets(rdram, ctx);
        goto after_32;
    // 0x8000F324: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_32:
    // 0x8000F328: lh          $a0, 0x4E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X4E);
    // 0x8000F32C: jal         0x8000C844
    // 0x8000F330: nop

    try_free_object_header(rdram, ctx);
        goto after_33;
    // 0x8000F330: nop

    after_33:
    // 0x8000F334: b           L_8000F62C
    // 0x8000F338: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000F62C;
    // 0x8000F338: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000F33C:
    // 0x8000F33C: andi        $t8, $s1, 0xF
    ctx->r24 = ctx->r17 & 0XF;
    // 0x8000F340: beq         $t8, $zero, L_8000F354
    if (ctx->r24 == 0) {
        // 0x8000F344: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8000F354;
    }
    // 0x8000F344: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000F348: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x8000F34C: and         $t6, $s1, $at
    ctx->r14 = ctx->r17 & ctx->r1;
    // 0x8000F350: addiu       $s1, $t6, 0x10
    ctx->r17 = ADD32(ctx->r14, 0X10);
L_8000F354:
    // 0x8000F354: sra         $t0, $s1, 2
    ctx->r8 = S32(SIGNED(ctx->r17) >> 2);
    // 0x8000F358: blez        $t0, L_8000F390
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8000F35C: sll         $s0, $a2, 2
        ctx->r16 = S32(ctx->r6 << 2);
            goto L_8000F390;
    }
    // 0x8000F35C: sll         $s0, $a2, 2
    ctx->r16 = S32(ctx->r6 << 2);
    // 0x8000F360: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000F364: addiu       $a1, $a1, -0x4D28
    ctx->r5 = ADD32(ctx->r5, -0X4D28);
    // 0x8000F368: addu        $v1, $v0, $s0
    ctx->r3 = ADD32(ctx->r2, ctx->r16);
    // 0x8000F36C: sll         $a0, $t0, 2
    ctx->r4 = S32(ctx->r8 << 2);
L_8000F370:
    // 0x8000F370: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x8000F374: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000F378: addu        $t9, $t2, $s0
    ctx->r25 = ADD32(ctx->r10, ctx->r16);
    // 0x8000F37C: lw          $t3, 0x0($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X0);
    // 0x8000F380: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8000F384: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8000F388: bne         $at, $zero, L_8000F370
    if (ctx->r1 != 0) {
        // 0x8000F38C: sw          $t3, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->r11;
            goto L_8000F370;
    }
    // 0x8000F38C: sw          $t3, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r11;
L_8000F390:
    // 0x8000F390: lw          $v1, 0x58($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X58);
    // 0x8000F394: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000F398: beq         $v1, $zero, L_8000F3B0
    if (ctx->r3 == 0) {
        // 0x8000F39C: addiu       $a1, $a1, -0x4D28
        ctx->r5 = ADD32(ctx->r5, -0X4D28);
            goto L_8000F3B0;
    }
    // 0x8000F39C: addiu       $a1, $a1, -0x4D28
    ctx->r5 = ADD32(ctx->r5, -0X4D28);
    // 0x8000F3A0: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x8000F3A4: addu        $t4, $v0, $v1
    ctx->r12 = ADD32(ctx->r2, ctx->r3);
    // 0x8000F3A8: subu        $t5, $t4, $t1
    ctx->r13 = SUB32(ctx->r12, ctx->r9);
    // 0x8000F3AC: sw          $t5, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->r13;
L_8000F3B0:
    // 0x8000F3B0: lw          $v1, 0x50($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X50);
    // 0x8000F3B4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000F3B8: beq         $v1, $zero, L_8000F3D0
    if (ctx->r3 == 0) {
        // 0x8000F3BC: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8000F3D0;
    }
    // 0x8000F3BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000F3C0: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8000F3C4: addu        $t7, $v0, $v1
    ctx->r15 = ADD32(ctx->r2, ctx->r3);
    // 0x8000F3C8: subu        $t6, $t7, $t8
    ctx->r14 = SUB32(ctx->r15, ctx->r24);
    // 0x8000F3CC: sw          $t6, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->r14;
L_8000F3D0:
    // 0x8000F3D0: lw          $v1, 0x54($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X54);
    // 0x8000F3D4: nop

    // 0x8000F3D8: beq         $v1, $zero, L_8000F3F0
    if (ctx->r3 == 0) {
        // 0x8000F3DC: nop
    
            goto L_8000F3F0;
    }
    // 0x8000F3DC: nop

    // 0x8000F3E0: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x8000F3E4: addu        $t0, $v0, $v1
    ctx->r8 = ADD32(ctx->r2, ctx->r3);
    // 0x8000F3E8: subu        $t9, $t0, $t2
    ctx->r25 = SUB32(ctx->r8, ctx->r10);
    // 0x8000F3EC: sw          $t9, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->r25;
L_8000F3F0:
    // 0x8000F3F0: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x8000F3F4: nop

    // 0x8000F3F8: beq         $v1, $zero, L_8000F410
    if (ctx->r3 == 0) {
        // 0x8000F3FC: nop
    
            goto L_8000F410;
    }
    // 0x8000F3FC: nop

    // 0x8000F400: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x8000F404: addu        $t3, $v0, $v1
    ctx->r11 = ADD32(ctx->r2, ctx->r3);
    // 0x8000F408: subu        $t1, $t3, $t4
    ctx->r9 = SUB32(ctx->r11, ctx->r12);
    // 0x8000F40C: sw          $t1, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->r9;
L_8000F410:
    // 0x8000F410: lw          $v1, 0x4C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4C);
    // 0x8000F414: nop

    // 0x8000F418: beq         $v1, $zero, L_8000F430
    if (ctx->r3 == 0) {
        // 0x8000F41C: nop
    
            goto L_8000F430;
    }
    // 0x8000F41C: nop

    // 0x8000F420: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8000F424: addu        $t5, $v0, $v1
    ctx->r13 = ADD32(ctx->r2, ctx->r3);
    // 0x8000F428: subu        $t8, $t5, $t7
    ctx->r24 = SUB32(ctx->r13, ctx->r15);
    // 0x8000F42C: sw          $t8, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->r24;
L_8000F430:
    // 0x8000F430: lw          $v1, 0x5C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X5C);
    // 0x8000F434: nop

    // 0x8000F438: beq         $v1, $zero, L_8000F450
    if (ctx->r3 == 0) {
        // 0x8000F43C: nop
    
            goto L_8000F450;
    }
    // 0x8000F43C: nop

    // 0x8000F440: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x8000F444: addu        $t6, $v0, $v1
    ctx->r14 = ADD32(ctx->r2, ctx->r3);
    // 0x8000F448: subu        $t2, $t6, $t0
    ctx->r10 = SUB32(ctx->r14, ctx->r8);
    // 0x8000F44C: sw          $t2, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->r10;
L_8000F450:
    // 0x8000F450: lw          $v1, 0x60($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X60);
    // 0x8000F454: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8000F458: beq         $v1, $zero, L_8000F470
    if (ctx->r3 == 0) {
        // 0x8000F45C: addiu       $s0, $s0, -0x4C24
        ctx->r16 = ADD32(ctx->r16, -0X4C24);
            goto L_8000F470;
    }
    // 0x8000F45C: addiu       $s0, $s0, -0x4C24
    ctx->r16 = ADD32(ctx->r16, -0X4C24);
    // 0x8000F460: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x8000F464: addu        $t9, $v0, $v1
    ctx->r25 = ADD32(ctx->r2, ctx->r3);
    // 0x8000F468: subu        $t4, $t9, $t3
    ctx->r12 = SUB32(ctx->r25, ctx->r11);
    // 0x8000F46C: sw          $t4, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->r12;
L_8000F470:
    // 0x8000F470: lw          $v1, 0x40($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X40);
    // 0x8000F474: nop

    // 0x8000F478: lb          $t1, 0x57($v1)
    ctx->r9 = MEM_B(ctx->r3, 0X57);
    // 0x8000F47C: nop

    // 0x8000F480: blez        $t1, L_8000F4A0
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8000F484: nop
    
            goto L_8000F4A0;
    }
    // 0x8000F484: nop

    // 0x8000F488: lw          $t5, 0x6C($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X6C);
    // 0x8000F48C: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8000F490: addu        $t7, $v0, $t5
    ctx->r15 = ADD32(ctx->r2, ctx->r13);
    // 0x8000F494: subu        $t6, $t7, $t8
    ctx->r14 = SUB32(ctx->r15, ctx->r24);
    // 0x8000F498: lw          $v1, 0x40($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X40);
    // 0x8000F49C: sw          $t6, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->r14;
L_8000F4A0:
    // 0x8000F4A0: lb          $t0, 0x5A($v1)
    ctx->r8 = MEM_B(ctx->r3, 0X5A);
    // 0x8000F4A4: addiu       $t1, $v0, 0x80
    ctx->r9 = ADD32(ctx->r2, 0X80);
    // 0x8000F4A8: blez        $t0, L_8000F4C4
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8000F4AC: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_8000F4C4;
    }
    // 0x8000F4AC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8000F4B0: lw          $t2, 0x70($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X70);
    // 0x8000F4B4: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x8000F4B8: addu        $t9, $v0, $t2
    ctx->r25 = ADD32(ctx->r2, ctx->r10);
    // 0x8000F4BC: subu        $t4, $t9, $t3
    ctx->r12 = SUB32(ctx->r25, ctx->r11);
    // 0x8000F4C0: sw          $t4, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->r12;
L_8000F4C4:
    // 0x8000F4C4: sw          $t1, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->r9;
    // 0x8000F4C8: lw          $s1, 0x6C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X6C);
    // 0x8000F4CC: nop

    // 0x8000F4D0: andi        $t5, $s1, 0x1
    ctx->r13 = ctx->r17 & 0X1;
    // 0x8000F4D4: beq         $t5, $zero, L_8000F500
    if (ctx->r13 == 0) {
        // 0x8000F4D8: or          $s1, $t5, $zero
        ctx->r17 = ctx->r13 | 0;
            goto L_8000F500;
    }
    // 0x8000F4D8: or          $s1, $t5, $zero
    ctx->r17 = ctx->r13 | 0;
    // 0x8000F4DC: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8000F4E0: lw          $t7, -0x4C28($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4C28);
    // 0x8000F4E4: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x8000F4E8: addu        $t0, $t7, $t6
    ctx->r8 = ADD32(ctx->r15, ctx->r14);
    // 0x8000F4EC: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x8000F4F0: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8000F4F4: nop

    // 0x8000F4F8: addiu       $t9, $t2, 0x1
    ctx->r25 = ADD32(ctx->r10, 0X1);
    // 0x8000F4FC: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
L_8000F500:
    // 0x8000F500: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8000F504: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x8000F508: jal         0x800238F0
    // 0x8000F50C: addiu       $s0, $s0, -0x4C24
    ctx->r16 = ADD32(ctx->r16, -0X4C24);
    run_object_init_func(rdram, ctx);
        goto after_34;
    // 0x8000F50C: addiu       $s0, $s0, -0x4C24
    ctx->r16 = ADD32(ctx->r16, -0X4C24);
    after_34:
    // 0x8000F510: lw          $v0, 0x4C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4C);
    // 0x8000F514: nop

    // 0x8000F518: beq         $v0, $zero, L_8000F54C
    if (ctx->r2 == 0) {
        // 0x8000F51C: nop
    
            goto L_8000F54C;
    }
    // 0x8000F51C: nop

    // 0x8000F520: lwc1        $f18, 0xC($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8000F524: nop

    // 0x8000F528: swc1        $f18, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f18.u32l;
    // 0x8000F52C: lw          $t3, 0x4C($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X4C);
    // 0x8000F530: lwc1        $f4, 0x10($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8000F534: nop

    // 0x8000F538: swc1        $f4, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f4.u32l;
    // 0x8000F53C: lw          $t4, 0x4C($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X4C);
    // 0x8000F540: lwc1        $f6, 0x14($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X14);
    // 0x8000F544: nop

    // 0x8000F548: swc1        $f6, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f6.u32l;
L_8000F54C:
    // 0x8000F54C: lw          $t1, 0x40($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X40);
    // 0x8000F550: nop

    // 0x8000F554: lb          $v0, 0x56($t1)
    ctx->r2 = MEM_B(ctx->r9, 0X56);
    // 0x8000F558: nop

    // 0x8000F55C: blez        $v0, L_8000F5F4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8000F560: slti        $at, $v0, 0xA
        ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
            goto L_8000F5F4;
    }
    // 0x8000F560: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x8000F564: beq         $at, $zero, L_8000F5F4
    if (ctx->r1 == 0) {
        // 0x8000F568: nop
    
            goto L_8000F5F4;
    }
    // 0x8000F568: nop

    // 0x8000F56C: jal         0x8000F99C
    // 0x8000F570: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    obj_init_attachpoint(rdram, ctx);
        goto after_35;
    // 0x8000F570: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_35:
    // 0x8000F574: beq         $v0, $zero, L_8000F5F4
    if (ctx->r2 == 0) {
        // 0x8000F578: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_8000F5F4;
    }
    // 0x8000F578: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000F57C: lw          $v0, -0x4C30($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4C30);
    // 0x8000F580: nop

    // 0x8000F584: beq         $v0, $zero, L_8000F594
    if (ctx->r2 == 0) {
        // 0x8000F588: nop
    
            goto L_8000F594;
    }
    // 0x8000F588: nop

    // 0x8000F58C: jal         0x8007B70C
    // 0x8000F590: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    tex_free(rdram, ctx);
        goto after_36;
    // 0x8000F590: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_36:
L_8000F594:
    // 0x8000F594: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000F598: lw          $v0, -0x4C2C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4C2C);
    // 0x8000F59C: nop

    // 0x8000F5A0: beq         $v0, $zero, L_8000F5B4
    if (ctx->r2 == 0) {
        // 0x8000F5A4: lw          $a2, 0x64($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X64);
            goto L_8000F5B4;
    }
    // 0x8000F5A4: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    // 0x8000F5A8: jal         0x8007B70C
    // 0x8000F5AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    tex_free(rdram, ctx);
        goto after_37;
    // 0x8000F5AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_37:
    // 0x8000F5B0: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
L_8000F5B4:
    // 0x8000F5B4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000F5B8: jal         0x8000F648
    // 0x8000F5BC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    objFreeAssets(rdram, ctx);
        goto after_38;
    // 0x8000F5BC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_38:
    // 0x8000F5C0: lh          $a0, 0x4E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X4E);
    // 0x8000F5C4: jal         0x8000C844
    // 0x8000F5C8: nop

    try_free_object_header(rdram, ctx);
        goto after_39;
    // 0x8000F5C8: nop

    after_39:
    // 0x8000F5CC: jal         0x80071380
    // 0x8000F5D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mempool_free(rdram, ctx);
        goto after_40;
    // 0x8000F5D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_40:
    // 0x8000F5D4: beq         $s1, $zero, L_8000F5EC
    if (ctx->r17 == 0) {
        // 0x8000F5D8: nop
    
            goto L_8000F5EC;
    }
    // 0x8000F5D8: nop

    // 0x8000F5DC: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8000F5E0: nop

    // 0x8000F5E4: addiu       $t8, $t5, -0x1
    ctx->r24 = ADD32(ctx->r13, -0X1);
    // 0x8000F5E8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
L_8000F5EC:
    // 0x8000F5EC: b           L_8000F62C
    // 0x8000F5F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000F62C;
    // 0x8000F5F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000F5F4:
    // 0x8000F5F4: lw          $t7, 0x40($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X40);
    // 0x8000F5F8: nop

    // 0x8000F5FC: lb          $t6, 0x5A($t7)
    ctx->r14 = MEM_B(ctx->r15, 0X5A);
    // 0x8000F600: nop

    // 0x8000F604: blez        $t6, L_8000F614
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8000F608: nop
    
            goto L_8000F614;
    }
    // 0x8000F608: nop

    // 0x8000F60C: jal         0x8000F758
    // 0x8000F610: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    light_setup_light_sources(rdram, ctx);
        goto after_41;
    // 0x8000F610: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_41:
L_8000F614:
    // 0x8000F614: jal         0x80061C34
    // 0x8000F618: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    model_anim_offset(rdram, ctx);
        goto after_42;
    // 0x8000F618: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_42:
    // 0x8000F61C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000F620: jal         0x800B7BD8
    // 0x8000F624: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    update_object_stack_trace(rdram, ctx);
        goto after_43;
    // 0x8000F624: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_43:
    // 0x8000F628: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
L_8000F62C:
    // 0x8000F62C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000F630: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000F634: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8000F638: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F63C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8000F640: jr          $ra
    // 0x8000F644: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8000F644: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void objFreeAssets(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F648: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000F64C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8000F650: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8000F654: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x8000F658: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8000F65C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000F660: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000F664: bne         $a2, $zero, L_8000F6B0
    if (ctx->r6 != 0) {
        // 0x8000F668: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_8000F6B0;
    }
    // 0x8000F668: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000F66C: blez        $a1, L_8000F73C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8000F670: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8000F73C;
    }
    // 0x8000F670: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8000F674: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8000F678:
    // 0x8000F678: lw          $t6, 0x68($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X68);
    // 0x8000F67C: nop

    // 0x8000F680: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x8000F684: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x8000F688: nop

    // 0x8000F68C: beq         $v0, $zero, L_8000F69C
    if (ctx->r2 == 0) {
        // 0x8000F690: nop
    
            goto L_8000F69C;
    }
    // 0x8000F690: nop

    // 0x8000F694: jal         0x80060180
    // 0x8000F698: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    free_3d_model(rdram, ctx);
        goto after_0;
    // 0x8000F698: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_0:
L_8000F69C:
    // 0x8000F69C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000F6A0: bne         $s1, $s2, L_8000F678
    if (ctx->r17 != ctx->r18) {
        // 0x8000F6A4: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8000F678;
    }
    // 0x8000F6A4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8000F6A8: b           L_8000F740
    // 0x8000F6AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8000F740;
    // 0x8000F6AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8000F6B0:
    // 0x8000F6B0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8000F6B4: bne         $a2, $at, L_8000F700
    if (ctx->r6 != ctx->r1) {
        // 0x8000F6B8: nop
    
            goto L_8000F700;
    }
    // 0x8000F6B8: nop

    // 0x8000F6BC: blez        $s2, L_8000F73C
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8000F6C0: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8000F73C;
    }
    // 0x8000F6C0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8000F6C4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8000F6C8:
    // 0x8000F6C8: lw          $t8, 0x68($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X68);
    // 0x8000F6CC: nop

    // 0x8000F6D0: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x8000F6D4: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x8000F6D8: nop

    // 0x8000F6DC: beq         $v0, $zero, L_8000F6EC
    if (ctx->r2 == 0) {
        // 0x8000F6E0: nop
    
            goto L_8000F6EC;
    }
    // 0x8000F6E0: nop

    // 0x8000F6E4: jal         0x8007B70C
    // 0x8000F6E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    tex_free(rdram, ctx);
        goto after_1;
    // 0x8000F6E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
L_8000F6EC:
    // 0x8000F6EC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000F6F0: bne         $s1, $s2, L_8000F6C8
    if (ctx->r17 != ctx->r18) {
        // 0x8000F6F4: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8000F6C8;
    }
    // 0x8000F6F4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8000F6F8: b           L_8000F740
    // 0x8000F6FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8000F740;
    // 0x8000F6FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8000F700:
    // 0x8000F700: blez        $s2, L_8000F73C
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8000F704: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8000F73C;
    }
    // 0x8000F704: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8000F708: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8000F70C:
    // 0x8000F70C: lw          $t0, 0x68($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X68);
    // 0x8000F710: nop

    // 0x8000F714: addu        $t1, $t0, $s0
    ctx->r9 = ADD32(ctx->r8, ctx->r16);
    // 0x8000F718: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x8000F71C: nop

    // 0x8000F720: beq         $v0, $zero, L_8000F730
    if (ctx->r2 == 0) {
        // 0x8000F724: nop
    
            goto L_8000F730;
    }
    // 0x8000F724: nop

    // 0x8000F728: jal         0x8007D100
    // 0x8000F72C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    sprite_free(rdram, ctx);
        goto after_2;
    // 0x8000F72C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
L_8000F730:
    // 0x8000F730: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000F734: bne         $s1, $s2, L_8000F70C
    if (ctx->r17 != ctx->r18) {
        // 0x8000F738: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8000F70C;
    }
    // 0x8000F738: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8000F73C:
    // 0x8000F73C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8000F740:
    // 0x8000F740: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000F744: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8000F748: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F74C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8000F750: jr          $ra
    // 0x8000F754: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8000F754: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void light_setup_light_sources(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F758: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8000F75C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000F760: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8000F764: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8000F768: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000F76C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000F770: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000F774: lw          $s0, 0x40($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X40);
    // 0x8000F778: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8000F77C: lb          $t6, 0x5A($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X5A);
    // 0x8000F780: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8000F784: blez        $t6, L_8000F7CC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8000F788: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8000F7CC;
    }
    // 0x8000F788: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8000F78C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_8000F790:
    // 0x8000F790: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x8000F794: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000F798: jal         0x80031FC8
    // 0x8000F79C: addu        $a1, $t7, $s3
    ctx->r5 = ADD32(ctx->r15, ctx->r19);
    light_add_from_object_header(rdram, ctx);
        goto after_0;
    // 0x8000F79C: addu        $a1, $t7, $s3
    ctx->r5 = ADD32(ctx->r15, ctx->r19);
    after_0:
    // 0x8000F7A0: lw          $t8, 0x70($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X70);
    // 0x8000F7A4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000F7A8: addu        $t9, $t8, $s4
    ctx->r25 = ADD32(ctx->r24, ctx->r20);
    // 0x8000F7AC: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    // 0x8000F7B0: lw          $s0, 0x40($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X40);
    // 0x8000F7B4: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x8000F7B8: lb          $t0, 0x5A($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X5A);
    // 0x8000F7BC: addiu       $s3, $s3, 0x18
    ctx->r19 = ADD32(ctx->r19, 0X18);
    // 0x8000F7C0: slt         $at, $s1, $t0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8000F7C4: bne         $at, $zero, L_8000F790
    if (ctx->r1 != 0) {
        // 0x8000F7C8: nop
    
            goto L_8000F790;
    }
    // 0x8000F7C8: nop

L_8000F7CC:
    // 0x8000F7CC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8000F7D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000F7D4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F7D8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000F7DC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8000F7E0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8000F7E4: jr          $ra
    // 0x8000F7E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8000F7E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
