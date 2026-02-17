#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void rain_render_splashes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ADBB8: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x800ADBBC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800ADBC0: lw          $t6, 0x321C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X321C);
    // 0x800ADBC4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800ADBC8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800ADBCC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800ADBD0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800ADBD4: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x800ADBD8: beq         $t6, $zero, L_800AE000
    if (ctx->r14 == 0) {
        // 0x800ADBDC: addiu       $s2, $zero, 0x1
        ctx->r18 = ADD32(0, 0X1);
            goto L_800AE000;
    }
    // 0x800ADBDC: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800ADBE0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800ADBE4: lw          $t7, 0x31FC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X31FC);
    // 0x800ADBE8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800ADBEC: lw          $t9, 0x31F0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X31F0);
    // 0x800ADBF0: sra         $t8, $t7, 2
    ctx->r24 = S32(SIGNED(ctx->r15) >> 2);
    // 0x800ADBF4: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800ADBF8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800ADBFC: mflo        $v0
    ctx->r2 = lo;
    // 0x800ADC00: sra         $t0, $v0, 14
    ctx->r8 = S32(SIGNED(ctx->r2) >> 14);
    // 0x800ADC04: slti        $at, $t0, 0x4001
    ctx->r1 = SIGNED(ctx->r8) < 0X4001 ? 1 : 0;
    // 0x800ADC08: bne         $at, $zero, L_800ADF0C
    if (ctx->r1 != 0) {
        // 0x800ADC0C: nop
    
            goto L_800ADF0C;
    }
    // 0x800ADC0C: nop

    // 0x800ADC10: jal         0x8001BB4C
    // 0x800ADC14: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    get_racer_object_by_port(rdram, ctx);
        goto after_0;
    // 0x800ADC14: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    after_0:
    // 0x800ADC18: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800ADC1C: addiu       $a2, $a2, 0x3214
    ctx->r6 = ADD32(ctx->r6, 0X3214);
    // 0x800ADC20: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x800ADC24: lw          $t2, 0x80($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X80);
    // 0x800ADC28: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x800ADC2C: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x800ADC30: bgtz        $t3, L_800ADF0C
    if (SIGNED(ctx->r11) > 0) {
        // 0x800ADC34: sw          $t3, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r11;
            goto L_800ADF0C;
    }
    // 0x800ADC34: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x800ADC38: beq         $v0, $zero, L_800ADF0C
    if (ctx->r2 == 0) {
        // 0x800ADC3C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800ADF0C;
    }
    // 0x800ADC3C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800ADC40: sll         $t5, $zero, 3
    ctx->r13 = S32(0 << 3);
    // 0x800ADC44: subu        $t5, $t5, $zero
    ctx->r13 = SUB32(ctx->r13, 0);
    // 0x800ADC48: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800ADC4C: addiu       $t6, $t6, 0x30DC
    ctx->r14 = ADD32(ctx->r14, 0X30DC);
    // 0x800ADC50: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800ADC54: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x800ADC58: addu        $s0, $t5, $t6
    ctx->r16 = ADD32(ctx->r13, ctx->r14);
L_800ADC5C:
    // 0x800ADC5C: lh          $t7, 0x6($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X6);
    // 0x800ADC60: nop

    // 0x800ADC64: bne         $t7, $zero, L_800ADC70
    if (ctx->r15 != 0) {
        // 0x800ADC68: nop
    
            goto L_800ADC70;
    }
    // 0x800ADC68: nop

    // 0x800ADC6C: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
L_800ADC70:
    // 0x800ADC70: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800ADC74: slti        $at, $v1, 0x8
    ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    // 0x800ADC78: beq         $at, $zero, L_800ADC88
    if (ctx->r1 == 0) {
        // 0x800ADC7C: addiu       $s0, $s0, 0x1C
        ctx->r16 = ADD32(ctx->r16, 0X1C);
            goto L_800ADC88;
    }
    // 0x800ADC7C: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    // 0x800ADC80: bltz        $s1, L_800ADC5C
    if (SIGNED(ctx->r17) < 0) {
        // 0x800ADC84: nop
    
            goto L_800ADC5C;
    }
    // 0x800ADC84: nop

L_800ADC88:
    // 0x800ADC88: bltz        $s1, L_800ADF0C
    if (SIGNED(ctx->r17) < 0) {
        // 0x800ADC8C: addiu       $a0, $zero, -0x2000
        ctx->r4 = ADD32(0, -0X2000);
            goto L_800ADF0C;
    }
    // 0x800ADC8C: addiu       $a0, $zero, -0x2000
    ctx->r4 = ADD32(0, -0X2000);
    // 0x800ADC90: jal         0x8006FB8C
    // 0x800ADC94: addiu       $a1, $zero, 0x2000
    ctx->r5 = ADD32(0, 0X2000);
    rand_range(rdram, ctx);
        goto after_1;
    // 0x800ADC94: addiu       $a1, $zero, 0x2000
    ctx->r5 = ADD32(0, 0X2000);
    after_1:
    // 0x800ADC98: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800ADC9C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800ADCA0: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x800ADCA4: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x800ADCA8: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x800ADCAC: addu        $t1, $t0, $at
    ctx->r9 = ADD32(ctx->r8, ctx->r1);
    // 0x800ADCB0: sw          $t1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r9;
    // 0x800ADCB4: jal         0x8006FB8C
    // 0x800ADCB8: addiu       $a1, $zero, 0x1F4
    ctx->r5 = ADD32(0, 0X1F4);
    rand_range(rdram, ctx);
        goto after_2;
    // 0x800ADCB8: addiu       $a1, $zero, 0x1F4
    ctx->r5 = ADD32(0, 0X1F4);
    after_2:
    // 0x800ADCBC: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800ADCC0: lh          $s0, 0x6E($sp)
    ctx->r16 = MEM_H(ctx->r29, 0X6E);
    // 0x800ADCC4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800ADCC8: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x800ADCCC: sra         $t2, $a0, 16
    ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800ADCD0: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    // 0x800ADCD4: jal         0x80070A04
    // 0x800ADCD8: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    sins_f(rdram, ctx);
        goto after_3;
    // 0x800ADCD8: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_3:
    // 0x800ADCDC: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800ADCE0: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x800ADCE4: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800ADCE8: lwc1        $f16, 0xC($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0XC);
    // 0x800ADCEC: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x800ADCF0: sra         $t4, $a0, 16
    ctx->r12 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800ADCF4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800ADCF8: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800ADCFC: jal         0x80070A38
    // 0x800ADD00: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
    coss_f(rdram, ctx);
        goto after_4;
    // 0x800ADD00: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
    after_4:
    // 0x800ADD04: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800ADD08: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
    // 0x800ADD0C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800ADD10: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800ADD14: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800ADD18: lwc1        $f14, 0x10($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800ADD1C: add.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800ADD20: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x800ADD24: jal         0x80029F58
    // 0x800ADD28: swc1        $f2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f2.u32l;
    get_level_segment_index_from_position(rdram, ctx);
        goto after_5;
    // 0x800ADD28: swc1        $f2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f2.u32l;
    after_5:
    // 0x800ADD2C: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x800ADD30: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x800ADD34: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800ADD38: jal         0x8002B134
    // 0x800ADD3C: addiu       $a3, $sp, 0x4C
    ctx->r7 = ADD32(ctx->r29, 0X4C);
    func_8002B0F4(rdram, ctx);
        goto after_6;
    // 0x800ADD3C: addiu       $a3, $sp, 0x4C
    ctx->r7 = ADD32(ctx->r29, 0X4C);
    after_6:
    // 0x800ADD40: beq         $v0, $zero, L_800ADF0C
    if (ctx->r2 == 0) {
        // 0x800ADD44: lui         $at, 0x447A
        ctx->r1 = S32(0X447A << 16);
            goto L_800ADF0C;
    }
    // 0x800ADD44: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x800ADD48: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800ADD4C: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800ADD50: bne         $at, $zero, L_800ADE08
    if (ctx->r1 != 0) {
        // 0x800ADD54: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800ADE08;
    }
    // 0x800ADD54: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800ADD58: addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
    // 0x800ADD5C: blez        $a0, L_800ADDC8
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800ADD60: nop
    
            goto L_800ADDC8;
    }
    // 0x800ADD60: nop

    // 0x800ADD64: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800ADD68: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x800ADD6C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800ADD70: lwc1        $f0, 0x10($t5)
    ctx->f0.u32l = MEM_W(ctx->r13, 0X10);
    // 0x800ADD74: lwc1        $f10, 0x0($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800ADD78: nop

    // 0x800ADD7C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x800ADD80: nop

    // 0x800ADD84: bc1f        L_800ADDC8
    if (!c1cs) {
        // 0x800ADD88: nop
    
            goto L_800ADDC8;
    }
    // 0x800ADD88: nop

L_800ADD8C:
    // 0x800ADD8C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800ADD90: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800ADD94: beq         $at, $zero, L_800ADDC8
    if (ctx->r1 == 0) {
        // 0x800ADD98: nop
    
            goto L_800ADDC8;
    }
    // 0x800ADD98: nop

    // 0x800ADD9C: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x800ADDA0: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x800ADDA4: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800ADDA8: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800ADDAC: nop

    // 0x800ADDB0: lwc1        $f16, 0x0($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800ADDB4: nop

    // 0x800ADDB8: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x800ADDBC: nop

    // 0x800ADDC0: bc1t        L_800ADD8C
    if (c1cs) {
        // 0x800ADDC4: nop
    
            goto L_800ADD8C;
    }
    // 0x800ADDC4: nop

L_800ADDC8:
    // 0x800ADDC8: blez        $v1, L_800ADE08
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800ADDCC: sll         $t3, $v1, 2
        ctx->r11 = S32(ctx->r3 << 2);
            goto L_800ADE08;
    }
    // 0x800ADDCC: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x800ADDD0: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x800ADDD4: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x800ADDD8: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800ADDDC: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800ADDE0: lwc1        $f4, 0x10($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X10);
    // 0x800ADDE4: lwc1        $f18, 0x0($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X0);
    // 0x800ADDE8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800ADDEC: sub.s       $f2, $f4, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x800ADDF0: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800ADDF4: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x800ADDF8: nop

    // 0x800ADDFC: bc1f        L_800ADE08
    if (!c1cs) {
        // 0x800ADE00: nop
    
            goto L_800ADE08;
    }
    // 0x800ADE00: nop

    // 0x800ADE04: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
L_800ADE08:
    // 0x800ADE08: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x800ADE0C: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x800ADE10: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x800ADE14: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800ADE18: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x800ADE1C: lwc1        $f10, 0x0($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800ADE20: lwc1        $f8, 0x10($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X10);
    // 0x800ADE24: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800ADE28: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800ADE2C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800ADE30: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x800ADE34: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x800ADE38: bc1f        L_800ADE44
    if (!c1cs) {
        // 0x800ADE3C: addiu       $t2, $t2, 0x30DC
        ctx->r10 = ADD32(ctx->r10, 0X30DC);
            goto L_800ADE44;
    }
    // 0x800ADE3C: addiu       $t2, $t2, 0x30DC
    ctx->r10 = ADD32(ctx->r10, 0X30DC);
    // 0x800ADE40: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_800ADE44:
    // 0x800ADE44: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800ADE48: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800ADE4C: bc1f        L_800ADE78
    if (!c1cs) {
        // 0x800ADE50: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_800ADE78;
    }
    // 0x800ADE50: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800ADE54: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x800ADE58: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800ADE5C: nop

    // 0x800ADE60: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800ADE64: nop

    // 0x800ADE68: bc1f        L_800ADE94
    if (!c1cs) {
        // 0x800ADE6C: nop
    
            goto L_800ADE94;
    }
    // 0x800ADE6C: nop

    // 0x800ADE70: b           L_800ADE94
    // 0x800ADE74: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
        goto L_800ADE94;
    // 0x800ADE74: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
L_800ADE78:
    // 0x800ADE78: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800ADE7C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800ADE80: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x800ADE84: nop

    // 0x800ADE88: bc1f        L_800ADE94
    if (!c1cs) {
        // 0x800ADE8C: nop
    
            goto L_800ADE94;
    }
    // 0x800ADE8C: nop

    // 0x800ADE90: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
L_800ADE94:
    // 0x800ADE94: bltz        $s1, L_800ADF0C
    if (SIGNED(ctx->r17) < 0) {
        // 0x800ADE98: sll         $t1, $s1, 3
        ctx->r9 = S32(ctx->r17 << 3);
            goto L_800ADF0C;
    }
    // 0x800ADE98: sll         $t1, $s1, 3
    ctx->r9 = S32(ctx->r17 << 3);
    // 0x800ADE9C: subu        $t1, $t1, $s1
    ctx->r9 = SUB32(ctx->r9, ctx->r17);
    // 0x800ADEA0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800ADEA4: addu        $s0, $t1, $t2
    ctx->r16 = ADD32(ctx->r9, ctx->r10);
    // 0x800ADEA8: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x800ADEAC: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x800ADEB0: lw          $v1, 0x7C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X7C);
    // 0x800ADEB4: lwc1        $f8, 0x0($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X0);
    // 0x800ADEB8: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800ADEBC: sra         $t5, $v1, 10
    ctx->r13 = S32(SIGNED(ctx->r3) >> 10);
    // 0x800ADEC0: sh          $zero, 0x18($s0)
    MEM_H(0X18, ctx->r16) = 0;
    // 0x800ADEC4: sh          $t4, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r12;
    // 0x800ADEC8: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
    // 0x800ADECC: addiu       $a1, $t5, 0xBF
    ctx->r5 = ADD32(ctx->r13, 0XBF);
    // 0x800ADED0: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    // 0x800ADED4: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    // 0x800ADED8: swc1        $f8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f8.u32l;
    // 0x800ADEDC: jal         0x8006FB8C
    // 0x800ADEE0: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    rand_range(rdram, ctx);
        goto after_7;
    // 0x800ADEE0: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    after_7:
    // 0x800ADEE4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800ADEE8: addiu       $a0, $a0, 0x3214
    ctx->r4 = ADD32(ctx->r4, 0X3214);
    // 0x800ADEEC: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800ADEF0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800ADEF4: sh          $v0, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r2;
    // 0x800ADEF8: subu        $t7, $t6, $v1
    ctx->r15 = SUB32(ctx->r14, ctx->r3);
    // 0x800ADEFC: addiu       $t8, $t7, 0x40
    ctx->r24 = ADD32(ctx->r15, 0X40);
    // 0x800ADF00: bgez        $t8, L_800ADF0C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800ADF04: sw          $t8, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r24;
            goto L_800ADF0C;
    }
    // 0x800ADF04: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800ADF08: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_800ADF0C:
    // 0x800ADF0C: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800ADF10: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800ADF14: addiu       $s1, $s1, -0x7E34
    ctx->r17 = ADD32(ctx->r17, -0X7E34);
    // 0x800ADF18: addiu       $s0, $s0, 0x30DC
    ctx->r16 = ADD32(ctx->r16, 0X30DC);
L_800ADF1C:
    // 0x800ADF1C: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
    // 0x800ADF20: lw          $t2, 0x80($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X80);
    // 0x800ADF24: beq         $t0, $zero, L_800ADFD0
    if (ctx->r8 == 0) {
        // 0x800ADF28: nop
    
            goto L_800ADFD0;
    }
    // 0x800ADF28: nop

    // 0x800ADF2C: lh          $t1, 0x18($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X18);
    // 0x800ADF30: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x800ADF34: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x800ADF38: sh          $t4, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r12;
    // 0x800ADF3C: lh          $t5, 0x18($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X18);
    // 0x800ADF40: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x800ADF44: slti        $at, $t5, 0x100
    ctx->r1 = SIGNED(ctx->r13) < 0X100 ? 1 : 0;
    // 0x800ADF48: bne         $at, $zero, L_800ADF58
    if (ctx->r1 != 0) {
        // 0x800ADF4C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800ADF58;
    }
    // 0x800ADF4C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800ADF50: b           L_800ADFD0
    // 0x800ADF54: sh          $zero, 0x6($s0)
    MEM_H(0X6, ctx->r16) = 0;
        goto L_800ADFD0;
    // 0x800ADF54: sh          $zero, 0x6($s0)
    MEM_H(0X6, ctx->r16) = 0;
L_800ADF58:
    // 0x800ADF58: beq         $s2, $zero, L_800ADF80
    if (ctx->r18 == 0) {
        // 0x800ADF5C: lui         $at, 0xC0C0
        ctx->r1 = S32(0XC0C0 << 16);
            goto L_800ADF80;
    }
    // 0x800ADF5C: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    // 0x800ADF60: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800ADF64: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x800ADF68: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800ADF6C: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800ADF70: addiu       $t8, $zero, -0x100
    ctx->r24 = ADD32(0, -0X100);
    // 0x800ADF74: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800ADF78: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800ADF7C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_800ADF80:
    // 0x800ADF80: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800ADF84: ori         $at, $at, 0xFF00
    ctx->r1 = ctx->r1 | 0XFF00;
    // 0x800ADF88: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800ADF8C: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800ADF90: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x800ADF94: lh          $t2, 0x1A($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X1A);
    // 0x800ADF98: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800ADF9C: andi        $t1, $t2, 0xFF
    ctx->r9 = ctx->r10 & 0XFF;
    // 0x800ADFA0: or          $t3, $t1, $at
    ctx->r11 = ctx->r9 | ctx->r1;
    // 0x800ADFA4: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800ADFA8: lw          $t4, 0x321C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X321C);
    // 0x800ADFAC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800ADFB0: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800ADFB4: addiu       $t5, $zero, 0x10E
    ctx->r13 = ADD32(0, 0X10E);
    // 0x800ADFB8: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800ADFBC: addiu       $a2, $a2, -0x7E2C
    ctx->r6 = ADD32(ctx->r6, -0X7E2C);
    // 0x800ADFC0: addiu       $a1, $a1, -0x7E30
    ctx->r5 = ADD32(ctx->r5, -0X7E30);
    // 0x800ADFC4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x800ADFC8: jal         0x80068754
    // 0x800ADFCC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    render_sprite_billboard(rdram, ctx);
        goto after_8;
    // 0x800ADFCC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_8:
L_800ADFD0:
    // 0x800ADFD0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800ADFD4: addiu       $t6, $t6, 0x31BC
    ctx->r14 = ADD32(ctx->r14, 0X31BC);
    // 0x800ADFD8: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    // 0x800ADFDC: bne         $s0, $t6, L_800ADF1C
    if (ctx->r16 != ctx->r14) {
        // 0x800ADFE0: nop
    
            goto L_800ADF1C;
    }
    // 0x800ADFE0: nop

    // 0x800ADFE4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800ADFE8: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x800ADFEC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800ADFF0: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800ADFF4: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800ADFF8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800ADFFC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_800AE000:
    // 0x800AE000: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800AE004: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800AE008: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800AE00C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800AE010: jr          $ra
    // 0x800AE014: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x800AE014: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void rain_lightning(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE018: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800AE01C: addiu       $a2, $a2, 0x3210
    ctx->r6 = ADD32(ctx->r6, 0X3210);
    // 0x800AE020: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800AE024: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AE028: blez        $v0, L_800AE084
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800AE02C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800AE084;
    }
    // 0x800AE02C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AE030: subu        $t6, $v0, $a0
    ctx->r14 = SUB32(ctx->r2, ctx->r4);
    // 0x800AE034: bgtz        $t6, L_800AE118
    if (SIGNED(ctx->r14) > 0) {
        // 0x800AE038: sw          $t6, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r14;
            goto L_800AE118;
    }
    // 0x800AE038: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800AE03C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800AE040: lw          $t8, 0x31FC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X31FC);
    // 0x800AE044: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x800AE048: slt         $at, $t8, $at
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800AE04C: bne         $at, $zero, L_800AE070
    if (ctx->r1 != 0) {
        // 0x800AE050: addiu       $a0, $zero, 0x27
        ctx->r4 = ADD32(0, 0X27);
            goto L_800AE070;
    }
    // 0x800AE050: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x800AE054: jal         0x800C06AC
    // 0x800AE058: nop

    check_fadeout_transition(rdram, ctx);
        goto after_0;
    // 0x800AE058: nop

    after_0:
    // 0x800AE05C: bne         $v0, $zero, L_800AE06C
    if (ctx->r2 != 0) {
        // 0x800AE060: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_800AE06C;
    }
    // 0x800AE060: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AE064: jal         0x800C06F8
    // 0x800AE068: addiu       $a0, $a0, 0x3228
    ctx->r4 = ADD32(ctx->r4, 0X3228);
    transition_begin(rdram, ctx);
        goto after_1;
    // 0x800AE068: addiu       $a0, $a0, 0x3228
    ctx->r4 = ADD32(ctx->r4, 0X3228);
    after_1:
L_800AE06C:
    // 0x800AE06C: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
L_800AE070:
    // 0x800AE070: jal         0x80001D04
    // 0x800AE074: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x800AE074: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x800AE078: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE07C: b           L_800AE118
    // 0x800AE080: sw          $zero, 0x3210($at)
    MEM_W(0X3210, ctx->r1) = 0;
        goto L_800AE118;
    // 0x800AE080: sw          $zero, 0x3210($at)
    MEM_W(0X3210, ctx->r1) = 0;
L_800AE084:
    // 0x800AE084: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800AE088: lw          $t9, 0x31F0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X31F0);
    // 0x800AE08C: ori         $at, $zero, 0xBB80
    ctx->r1 = 0 | 0XBB80;
    // 0x800AE090: slt         $at, $t9, $at
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800AE094: bne         $at, $zero, L_800AE118
    if (ctx->r1 != 0) {
        // 0x800AE098: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_800AE118;
    }
    // 0x800AE098: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AE09C: addiu       $v1, $v1, 0x320C
    ctx->r3 = ADD32(ctx->r3, 0X320C);
    // 0x800AE0A0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800AE0A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800AE0A8: blez        $v0, L_800AE0B8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800AE0AC: subu        $t0, $v0, $a0
        ctx->r8 = SUB32(ctx->r2, ctx->r4);
            goto L_800AE0B8;
    }
    // 0x800AE0AC: subu        $t0, $v0, $a0
    ctx->r8 = SUB32(ctx->r2, ctx->r4);
    // 0x800AE0B0: b           L_800AE118
    // 0x800AE0B4: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
        goto L_800AE118;
    // 0x800AE0B4: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
L_800AE0B8:
    // 0x800AE0B8: jal         0x80001D04
    // 0x800AE0BC: addiu       $a0, $zero, 0x23F
    ctx->r4 = ADD32(0, 0X23F);
    sound_play(rdram, ctx);
        goto after_3;
    // 0x800AE0BC: addiu       $a0, $zero, 0x23F
    ctx->r4 = ADD32(0, 0X23F);
    after_3:
    // 0x800AE0C0: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800AE0C4: lw          $t1, 0x31F0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X31F0);
    // 0x800AE0C8: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800AE0CC: ori         $at, $at, 0x4480
    ctx->r1 = ctx->r1 | 0X4480;
    // 0x800AE0D0: addu        $t2, $t1, $at
    ctx->r10 = ADD32(ctx->r9, ctx->r1);
    // 0x800AE0D4: sra         $t3, $t2, 5
    ctx->r11 = S32(SIGNED(ctx->r10) >> 5);
    // 0x800AE0D8: addiu       $t4, $zero, 0x258
    ctx->r12 = ADD32(0, 0X258);
    // 0x800AE0DC: subu        $t5, $t4, $t3
    ctx->r13 = SUB32(ctx->r12, ctx->r11);
    // 0x800AE0E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE0E4: sw          $t5, 0x3210($at)
    MEM_W(0X3210, ctx->r1) = ctx->r13;
    // 0x800AE0E8: addiu       $a0, $zero, 0x384
    ctx->r4 = ADD32(0, 0X384);
    // 0x800AE0EC: jal         0x8006FB8C
    // 0x800AE0F0: addiu       $a1, $zero, 0x474
    ctx->r5 = ADD32(0, 0X474);
    rand_range(rdram, ctx);
        goto after_4;
    // 0x800AE0F0: addiu       $a1, $zero, 0x474
    ctx->r5 = ADD32(0, 0X474);
    after_4:
    // 0x800AE0F4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800AE0F8: lw          $t6, 0x31F0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X31F0);
    // 0x800AE0FC: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800AE100: ori         $at, $at, 0x4480
    ctx->r1 = ctx->r1 | 0X4480;
    // 0x800AE104: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x800AE108: sra         $t8, $t7, 5
    ctx->r24 = S32(SIGNED(ctx->r15) >> 5);
    // 0x800AE10C: subu        $t9, $v0, $t8
    ctx->r25 = SUB32(ctx->r2, ctx->r24);
    // 0x800AE110: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE114: sw          $t9, 0x320C($at)
    MEM_W(0X320C, ctx->r1) = ctx->r25;
L_800AE118:
    // 0x800AE118: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AE11C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AE120: jr          $ra
    // 0x800AE124: nop

    return;
    // 0x800AE124: nop

;}
RECOMP_FUNC void rain_sound(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE128: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800AE12C: lw          $t6, 0x31F0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X31F0);
    // 0x800AE130: lui         $at, 0x4490
    ctx->r1 = S32(0X4490 << 16);
    // 0x800AE134: sra         $t7, $t6, 6
    ctx->r15 = S32(SIGNED(ctx->r14) >> 6);
    // 0x800AE138: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800AE13C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AE140: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800AE144: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800AE148: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800AE14C: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800AE150: lw          $t8, -0x7E24($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7E24);
    // 0x800AE154: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800AE158: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800AE15C: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x800AE160: lh          $a0, 0x0($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X0);
    // 0x800AE164: jal         0x80070A04
    // 0x800AE168: nop

    sins_f(rdram, ctx);
        goto after_0;
    // 0x800AE168: nop

    after_0:
    // 0x800AE16C: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800AE170: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800AE174: mul.s       $f12, $f0, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800AE178: lw          $t9, -0x7E24($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7E24);
    // 0x800AE17C: nop

    // 0x800AE180: lh          $a0, 0x0($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X0);
    // 0x800AE184: jal         0x80070A38
    // 0x800AE188: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    coss_f(rdram, ctx);
        goto after_1;
    // 0x800AE188: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x800AE18C: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800AE190: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800AE194: mul.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800AE198: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800AE19C: lw          $v0, -0x7E24($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7E24);
    // 0x800AE1A0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AE1A4: sub.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x800AE1A8: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800AE1AC: addiu       $v1, $v1, 0x3224
    ctx->r3 = ADD32(ctx->r3, 0X3224);
    // 0x800AE1B0: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x800AE1B4: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800AE1B8: neg.s       $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = -ctx->f2.fl;
    // 0x800AE1BC: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800AE1C0: lwc1        $f16, 0x10($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800AE1C4: sub.s       $f8, $f4, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x800AE1C8: beq         $a0, $zero, L_800AE1EC
    if (ctx->r4 == 0) {
        // 0x800AE1CC: add.s       $f18, $f6, $f8
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f8.fl;
            goto L_800AE1EC;
    }
    // 0x800AE1CC: add.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800AE1D0: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x800AE1D4: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x800AE1D8: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x800AE1DC: jal         0x800096D8
    // 0x800AE1E0: nop

    audspat_point_set_position(rdram, ctx);
        goto after_2;
    // 0x800AE1E0: nop

    after_2:
    // 0x800AE1E4: b           L_800AE210
    // 0x800AE1E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800AE210;
    // 0x800AE1E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800AE1EC:
    // 0x800AE1EC: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x800AE1F0: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x800AE1F4: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x800AE1F8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800AE1FC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800AE200: addiu       $a0, $zero, 0x23E
    ctx->r4 = ADD32(0, 0X23E);
    // 0x800AE204: jal         0x80009558
    // 0x800AE208: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_3;
    // 0x800AE208: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    after_3:
    // 0x800AE20C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800AE210:
    // 0x800AE210: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800AE214: jr          $ra
    // 0x800AE218: nop

    return;
    // 0x800AE218: nop

;}
RECOMP_FUNC void rain_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE21C: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x800AE220: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800AE224: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x800AE228: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x800AE22C: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x800AE230: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x800AE234: swc1        $f27, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x800AE238: swc1        $f26, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f26.u32l;
    // 0x800AE23C: swc1        $f25, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x800AE240: swc1        $f24, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f24.u32l;
    // 0x800AE244: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800AE248: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x800AE24C: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800AE250: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800AE254: sw          $a1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r5;
    // 0x800AE258: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x800AE25C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800AE260: beq         $v0, $zero, L_800AE78C
    if (ctx->r2 == 0) {
        // 0x800AE264: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_800AE78C;
    }
    // 0x800AE264: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800AE268: lbu         $s1, 0x0($v0)
    ctx->r17 = MEM_BU(ctx->r2, 0X0);
    // 0x800AE26C: lbu         $s2, 0x1($v0)
    ctx->r18 = MEM_BU(ctx->r2, 0X1);
    // 0x800AE270: sll         $t6, $s1, 5
    ctx->r14 = S32(ctx->r17 << 5);
    // 0x800AE274: sll         $t7, $s2, 5
    ctx->r15 = S32(ctx->r18 << 5);
    // 0x800AE278: sll         $v1, $t6, 1
    ctx->r3 = S32(ctx->r14 << 1);
    // 0x800AE27C: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800AE280: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800AE284: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800AE288: sw          $v1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r3;
    // 0x800AE28C: sw          $t9, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r25;
    // 0x800AE290: lh          $t5, 0x8($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X8);
    // 0x800AE294: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800AE298: multu       $t5, $a1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AE29C: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x800AE2A0: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x800AE2A4: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    // 0x800AE2A8: mflo        $a0
    ctx->r4 = lo;
    // 0x800AE2AC: jal         0x8000C8B4
    // 0x800AE2B0: nop

    normalise_time(rdram, ctx);
        goto after_0;
    // 0x800AE2B0: nop

    after_0:
    // 0x800AE2B4: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x800AE2B8: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x800AE2BC: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x800AE2C0: and         $t9, $t8, $v1
    ctx->r25 = ctx->r24 & ctx->r3;
    // 0x800AE2C4: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
    // 0x800AE2C8: lw          $t6, 0xA4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA4);
    // 0x800AE2CC: lh          $t5, 0xA($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XA);
    // 0x800AE2D0: nop

    // 0x800AE2D4: multu       $t5, $t6
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AE2D8: mflo        $a0
    ctx->r4 = lo;
    // 0x800AE2DC: jal         0x8000C8B4
    // 0x800AE2E0: nop

    normalise_time(rdram, ctx);
        goto after_1;
    // 0x800AE2E0: nop

    after_1:
    // 0x800AE2E4: lh          $t6, 0x4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4);
    // 0x800AE2E8: lh          $t7, 0x2($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X2);
    // 0x800AE2EC: multu       $t6, $s1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AE2F0: lw          $t9, 0x88($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X88);
    // 0x800AE2F4: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x800AE2F8: and         $t5, $t8, $t9
    ctx->r13 = ctx->r24 & ctx->r25;
    // 0x800AE2FC: lh          $t8, 0x6($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X6);
    // 0x800AE300: sh          $t5, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r13;
    // 0x800AE304: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800AE308: lw          $t5, 0x31FC($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X31FC);
    // 0x800AE30C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800AE310: sra         $t6, $t5, 2
    ctx->r14 = S32(SIGNED(ctx->r13) >> 2);
    // 0x800AE314: mflo        $s1
    ctx->r17 = lo;
    // 0x800AE318: sra         $t7, $s1, 8
    ctx->r15 = S32(SIGNED(ctx->r17) >> 8);
    // 0x800AE31C: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x800AE320: multu       $t8, $s2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AE324: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800AE328: lw          $t7, 0x31F0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X31F0);
    // 0x800AE32C: mflo        $s2
    ctx->r18 = lo;
    // 0x800AE330: sra         $t9, $s2, 8
    ctx->r25 = S32(SIGNED(ctx->r18) >> 8);
    // 0x800AE334: or          $s2, $t9, $zero
    ctx->r18 = ctx->r25 | 0;
    // 0x800AE338: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AE33C: lbu         $t9, 0x16($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X16);
    // 0x800AE340: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x800AE344: mflo        $v1
    ctx->r3 = lo;
    // 0x800AE348: sra         $t8, $v1, 14
    ctx->r24 = S32(SIGNED(ctx->r3) >> 14);
    // 0x800AE34C: nop

    // 0x800AE350: multu       $t9, $t8
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AE354: mflo        $v1
    ctx->r3 = lo;
    // 0x800AE358: sra         $t5, $v1, 16
    ctx->r13 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800AE35C: blez        $t5, L_800AE788
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800AE360: or          $v1, $t5, $zero
        ctx->r3 = ctx->r13 | 0;
            goto L_800AE788;
    }
    // 0x800AE360: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
    // 0x800AE364: lw          $v0, -0x7E24($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7E24);
    // 0x800AE368: subu        $t6, $t6, $s1
    ctx->r14 = SUB32(ctx->r14, ctx->r17);
    // 0x800AE36C: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x800AE370: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x800AE374: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AE378: lh          $t5, 0x0($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X0);
    // 0x800AE37C: lh          $t2, 0x2($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X2);
    // 0x800AE380: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
    // 0x800AE384: lh          $a0, 0x4($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X4);
    // 0x800AE388: sw          $v1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r3;
    // 0x800AE38C: addu        $s2, $s2, $t2
    ctx->r18 = ADD32(ctx->r18, ctx->r10);
    // 0x800AE390: sw          $t2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r10;
    // 0x800AE394: mflo        $t8
    ctx->r24 = lo;
    // 0x800AE398: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800AE39C: addu        $t6, $t5, $t9
    ctx->r14 = ADD32(ctx->r13, ctx->r25);
    // 0x800AE3A0: and         $t0, $t6, $t7
    ctx->r8 = ctx->r14 & ctx->r15;
    // 0x800AE3A4: addu        $s1, $s1, $t0
    ctx->r17 = ADD32(ctx->r17, ctx->r8);
    // 0x800AE3A8: jal         0x80070A04
    // 0x800AE3AC: sw          $t0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r8;
    sins_f(rdram, ctx);
        goto after_2;
    // 0x800AE3AC: sw          $t0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r8;
    after_2:
    // 0x800AE3B0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800AE3B4: lw          $t8, -0x7E24($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7E24);
    // 0x800AE3B8: nop

    // 0x800AE3BC: lh          $a0, 0x4($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X4);
    // 0x800AE3C0: jal         0x80070A38
    // 0x800AE3C4: swc1        $f0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f0.u32l;
    coss_f(rdram, ctx);
        goto after_3;
    // 0x800AE3C4: swc1        $f0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x800AE3C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE3CC: lwc1        $f12, 0x301C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X301C);
    // 0x800AE3D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE3D4: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800AE3D8: lwc1        $f2, 0x7C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800AE3DC: lwc1        $f14, 0x3020($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X3020);
    // 0x800AE3E0: lwc1        $f16, 0x3024($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X3024);
    // 0x800AE3E4: mul.s       $f6, $f14, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x800AE3E8: lwc1        $f18, 0x3028($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X3028);
    // 0x800AE3EC: lwc1        $f20, 0x302C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X302C);
    // 0x800AE3F0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE3F4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800AE3F8: lwc1        $f22, 0x3030($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X3030);
    // 0x800AE3FC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800AE400: lwc1        $f24, 0x3034($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X3034);
    // 0x800AE404: lwc1        $f26, 0x3038($at)
    ctx->f26.u32l = MEM_W(ctx->r1, 0X3038);
    // 0x800AE408: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800AE40C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AE410: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AE414: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800AE418: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800AE41C: addiu       $t1, $t1, 0x3220
    ctx->r9 = ADD32(ctx->r9, 0X3220);
    // 0x800AE420: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800AE424: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x800AE428: mul.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x800AE42C: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800AE430: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800AE434: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x800AE438: mul.s       $f6, $f14, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800AE43C: addu        $t9, $t9, $t5
    ctx->r25 = ADD32(ctx->r25, ctx->r13);
    // 0x800AE440: addiu       $t3, $t3, 0x303C
    ctx->r11 = ADD32(ctx->r11, 0X303C);
    // 0x800AE444: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x800AE448: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800AE44C: addu        $v0, $t3, $t9
    ctx->r2 = ADD32(ctx->r11, ctx->r25);
    // 0x800AE450: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800AE454: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x800AE458: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800AE45C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AE460: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AE464: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800AE468: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800AE46C: addiu       $t4, $t4, -0x7E28
    ctx->r12 = ADD32(ctx->r12, -0X7E28);
    // 0x800AE470: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800AE474: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x800AE478: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800AE47C: sh          $t5, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r13;
    // 0x800AE480: lw          $t2, 0x98($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X98);
    // 0x800AE484: lw          $v1, 0x84($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X84);
    // 0x800AE488: mul.s       $f6, $f18, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x800AE48C: lw          $t0, 0x9C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X9C);
    // 0x800AE490: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x800AE494: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800AE498: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800AE49C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800AE4A0: nop

    // 0x800AE4A4: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800AE4A8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AE4AC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AE4B0: nop

    // 0x800AE4B4: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800AE4B8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800AE4BC: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x800AE4C0: mul.s       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800AE4C4: sh          $t6, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r14;
    // 0x800AE4C8: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800AE4CC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800AE4D0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800AE4D4: nop

    // 0x800AE4D8: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800AE4DC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AE4E0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AE4E4: nop

    // 0x800AE4E8: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800AE4EC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800AE4F0: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x800AE4F4: mul.s       $f4, $f20, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800AE4F8: sh          $t8, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r24;
    // 0x800AE4FC: mul.s       $f6, $f22, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x800AE500: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800AE504: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800AE508: nop

    // 0x800AE50C: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800AE510: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AE514: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AE518: nop

    // 0x800AE51C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800AE520: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800AE524: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800AE528: mul.s       $f4, $f20, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x800AE52C: sh          $t9, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r25;
    // 0x800AE530: mul.s       $f6, $f22, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x800AE534: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800AE538: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800AE53C: nop

    // 0x800AE540: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800AE544: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AE548: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AE54C: nop

    // 0x800AE550: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800AE554: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800AE558: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x800AE55C: mul.s       $f4, $f24, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x800AE560: sh          $t7, 0x16($v0)
    MEM_H(0X16, ctx->r2) = ctx->r15;
    // 0x800AE564: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800AE568: mul.s       $f6, $f26, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f26.fl, ctx->f2.fl);
    // 0x800AE56C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800AE570: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800AE574: nop

    // 0x800AE578: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800AE57C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AE580: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AE584: nop

    // 0x800AE588: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800AE58C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800AE590: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x800AE594: mul.s       $f4, $f24, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f24.fl, ctx->f2.fl);
    // 0x800AE598: sh          $t5, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r13;
    // 0x800AE59C: lui         $t8, 0x4000
    ctx->r24 = S32(0X4000 << 16);
    // 0x800AE5A0: lui         $t5, 0x4002
    ctx->r13 = S32(0X4002 << 16);
    // 0x800AE5A4: mul.s       $f6, $f26, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f26.fl, ctx->f0.fl);
    // 0x800AE5A8: ori         $t8, $t8, 0x102
    ctx->r24 = ctx->r24 | 0X102;
    // 0x800AE5AC: ori         $t5, $t5, 0x300
    ctx->r13 = ctx->r13 | 0X300;
    // 0x800AE5B0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800AE5B4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800AE5B8: nop

    // 0x800AE5BC: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800AE5C0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AE5C4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AE5C8: nop

    // 0x800AE5CC: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800AE5D0: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x800AE5D4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800AE5D8: sh          $t6, 0x20($v0)
    MEM_H(0X20, ctx->r2) = ctx->r14;
    // 0x800AE5DC: lw          $t7, -0x7E34($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7E34);
    // 0x800AE5E0: lw          $v0, 0x0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X0);
    // 0x800AE5E4: sw          $t7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r15;
    // 0x800AE5E8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800AE5EC: sh          $t0, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r8;
    // 0x800AE5F0: sh          $t2, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r10;
    // 0x800AE5F4: sh          $s1, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r17;
    // 0x800AE5F8: sh          $t2, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r10;
    // 0x800AE5FC: sh          $s1, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r17;
    // 0x800AE600: sh          $s2, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r18;
    // 0x800AE604: sw          $t5, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r13;
    // 0x800AE608: sh          $s1, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r17;
    // 0x800AE60C: sh          $s2, 0x16($v0)
    MEM_H(0X16, ctx->r2) = ctx->r18;
    // 0x800AE610: sh          $t0, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r8;
    // 0x800AE614: sh          $s2, 0x1A($v0)
    MEM_H(0X1A, ctx->r2) = ctx->r18;
    // 0x800AE618: sh          $t0, 0x1C($v0)
    MEM_H(0X1C, ctx->r2) = ctx->r8;
    // 0x800AE61C: sh          $t2, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r10;
    // 0x800AE620: lbu         $t9, 0x10($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X10);
    // 0x800AE624: lbu         $t7, 0x11($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X11);
    // 0x800AE628: sll         $t6, $t9, 24
    ctx->r14 = S32(ctx->r25 << 24);
    // 0x800AE62C: lbu         $t9, 0x12($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X12);
    // 0x800AE630: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x800AE634: or          $t5, $t6, $t8
    ctx->r13 = ctx->r14 | ctx->r24;
    // 0x800AE638: sll         $t7, $t9, 8
    ctx->r15 = S32(ctx->r25 << 8);
    // 0x800AE63C: lbu         $t8, 0x13($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X13);
    // 0x800AE640: or          $t6, $t5, $t7
    ctx->r14 = ctx->r13 | ctx->r15;
    // 0x800AE644: lbu         $t5, 0x14($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X14);
    // 0x800AE648: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x800AE64C: lbu         $t8, 0x15($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X15);
    // 0x800AE650: sll         $t7, $t5, 16
    ctx->r15 = S32(ctx->r13 << 16);
    // 0x800AE654: or          $a2, $t6, $v1
    ctx->r6 = ctx->r14 | ctx->r3;
    // 0x800AE658: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x800AE65C: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x800AE660: sll         $t5, $t8, 8
    ctx->r13 = S32(ctx->r24 << 8);
    // 0x800AE664: or          $a3, $t6, $t5
    ctx->r7 = ctx->r14 | ctx->r13;
    // 0x800AE668: jal         0x8007F9E4
    // 0x800AE66C: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    gfx_init_basic_xlu(rdram, ctx);
        goto after_4;
    // 0x800AE66C: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    after_4:
    // 0x800AE670: lw          $v1, 0x68($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X68);
    // 0x800AE674: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800AE678: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800AE67C: sw          $t7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r15;
    // 0x800AE680: lh          $a0, 0xA($s3)
    ctx->r4 = MEM_H(ctx->r19, 0XA);
    // 0x800AE684: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
    // 0x800AE688: andi        $t8, $a0, 0xFF
    ctx->r24 = ctx->r4 & 0XFF;
    // 0x800AE68C: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x800AE690: sll         $t9, $a0, 3
    ctx->r25 = S32(ctx->r4 << 3);
    // 0x800AE694: andi        $t7, $t9, 0xFFFF
    ctx->r15 = ctx->r25 & 0XFFFF;
    // 0x800AE698: or          $t5, $t6, $at
    ctx->r13 = ctx->r14 | ctx->r1;
    // 0x800AE69C: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x800AE6A0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800AE6A4: lw          $t6, 0xC($s3)
    ctx->r14 = MEM_W(ctx->r19, 0XC);
    // 0x800AE6A8: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x800AE6AC: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800AE6B0: addu        $t9, $t6, $t0
    ctx->r25 = ADD32(ctx->r14, ctx->r8);
    // 0x800AE6B4: addiu       $t1, $t1, 0x3220
    ctx->r9 = ADD32(ctx->r9, 0X3220);
    // 0x800AE6B8: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800AE6BC: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800AE6C0: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x800AE6C4: multu       $t8, $t2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AE6C8: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x800AE6CC: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800AE6D0: addiu       $t3, $t3, 0x303C
    ctx->r11 = ADD32(ctx->r11, 0X303C);
    // 0x800AE6D4: addiu       $t7, $a1, 0x8
    ctx->r15 = ADD32(ctx->r5, 0X8);
    // 0x800AE6D8: sw          $t7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r15;
    // 0x800AE6DC: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x800AE6E0: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800AE6E4: addiu       $t4, $t4, -0x7E28
    ctx->r12 = ADD32(ctx->r12, -0X7E28);
    // 0x800AE6E8: mflo        $t6
    ctx->r14 = lo;
    // 0x800AE6EC: addu        $t9, $t3, $t6
    ctx->r25 = ADD32(ctx->r11, ctx->r14);
    // 0x800AE6F0: addu        $t5, $t9, $t0
    ctx->r13 = ADD32(ctx->r25, ctx->r8);
    // 0x800AE6F4: andi        $t7, $t5, 0x6
    ctx->r15 = ctx->r13 & 0X6;
    // 0x800AE6F8: ori         $t8, $t7, 0x18
    ctx->r24 = ctx->r15 | 0X18;
    // 0x800AE6FC: andi        $t6, $t8, 0xFF
    ctx->r14 = ctx->r24 & 0XFF;
    // 0x800AE700: sll         $t9, $t6, 16
    ctx->r25 = S32(ctx->r14 << 16);
    // 0x800AE704: or          $t5, $t9, $at
    ctx->r13 = ctx->r25 | ctx->r1;
    // 0x800AE708: ori         $t7, $t5, 0x50
    ctx->r15 = ctx->r13 | 0X50;
    // 0x800AE70C: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800AE710: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800AE714: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800AE718: multu       $t8, $t2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AE71C: mflo        $t6
    ctx->r14 = lo;
    // 0x800AE720: addu        $t9, $t3, $t6
    ctx->r25 = ADD32(ctx->r11, ctx->r14);
    // 0x800AE724: addu        $t5, $t9, $t0
    ctx->r13 = ADD32(ctx->r25, ctx->r8);
    // 0x800AE728: sw          $t5, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r13;
    // 0x800AE72C: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x800AE730: lui         $t6, 0x511
    ctx->r14 = S32(0X511 << 16);
    // 0x800AE734: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800AE738: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
    // 0x800AE73C: ori         $t6, $t6, 0x20
    ctx->r14 = ctx->r14 | 0X20;
    // 0x800AE740: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800AE744: lw          $t9, 0x0($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X0);
    // 0x800AE748: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x800AE74C: addu        $t5, $t9, $t0
    ctx->r13 = ADD32(ctx->r25, ctx->r8);
    // 0x800AE750: sw          $t5, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r13;
    // 0x800AE754: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x800AE758: nop

    // 0x800AE75C: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800AE760: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
    // 0x800AE764: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x800AE768: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800AE76C: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800AE770: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x800AE774: addiu       $t5, $t9, 0x4
    ctx->r13 = ADD32(ctx->r25, 0X4);
    // 0x800AE778: andi        $t7, $t5, 0xF
    ctx->r15 = ctx->r13 & 0XF;
    // 0x800AE77C: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x800AE780: sw          $t8, -0x7E34($at)
    MEM_W(-0X7E34, ctx->r1) = ctx->r24;
    // 0x800AE784: sw          $v0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r2;
L_800AE788:
    // 0x800AE788: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_800AE78C:
    // 0x800AE78C: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800AE790: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800AE794: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800AE798: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800AE79C: lwc1        $f25, 0x20($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800AE7A0: lwc1        $f24, 0x24($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800AE7A4: lwc1        $f27, 0x28($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800AE7A8: lwc1        $f26, 0x2C($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800AE7AC: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x800AE7B0: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x800AE7B4: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x800AE7B8: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x800AE7BC: jr          $ra
    // 0x800AE7C0: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x800AE7C0: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    // 0x800AE7C4: nop

    // 0x800AE7C8: nop

    // 0x800AE7CC: nop

;}
RECOMP_FUNC void reset_particles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE7D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AE7D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AE7D8: jal         0x800AE8D4
    // 0x800AE7DC: nop

    free_particle_buffers(rdram, ctx);
        goto after_0;
    // 0x800AE7DC: nop

    after_0:
    // 0x800AE7E0: jal         0x800AE998
    // 0x800AE7E4: nop

    free_particle_vertices_triangles(rdram, ctx);
        goto after_1;
    // 0x800AE7E4: nop

    after_1:
    // 0x800AE7E8: jal         0x800AE838
    // 0x800AE7EC: nop

    particle_free_dummy(rdram, ctx);
        goto after_2;
    // 0x800AE7EC: nop

    after_2:
    // 0x800AE7F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AE7F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AE7F8: jr          $ra
    // 0x800AE7FC: nop

    return;
    // 0x800AE7FC: nop

;}
RECOMP_FUNC void reset_particles_with_assets(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE800: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AE804: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AE808: jal         0x800AE8D4
    // 0x800AE80C: nop

    free_particle_buffers(rdram, ctx);
        goto after_0;
    // 0x800AE80C: nop

    after_0:
    // 0x800AE810: jal         0x800AE998
    // 0x800AE814: nop

    free_particle_vertices_triangles(rdram, ctx);
        goto after_1;
    // 0x800AE814: nop

    after_1:
    // 0x800AE818: jal         0x800AE9F0
    // 0x800AE81C: nop

    free_particle_assets(rdram, ctx);
        goto after_2;
    // 0x800AE81C: nop

    after_2:
    // 0x800AE820: jal         0x800AE838
    // 0x800AE824: nop

    particle_free_dummy(rdram, ctx);
        goto after_3;
    // 0x800AE824: nop

    after_3:
    // 0x800AE828: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AE82C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AE830: jr          $ra
    // 0x800AE834: nop

    return;
    // 0x800AE834: nop

;}
RECOMP_FUNC void particle_free_dummy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE838: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800AE83C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800AE840: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x800AE844: addiu       $s3, $s3, 0x33F0
    ctx->r19 = ADD32(ctx->r19, 0X33F0);
    // 0x800AE848: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x800AE84C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800AE850: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800AE854: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800AE858: beq         $a0, $zero, L_800AE8B8
    if (ctx->r4 == 0) {
        // 0x800AE85C: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_800AE8B8;
    }
    // 0x800AE85C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800AE860: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800AE864: addiu       $s2, $s2, 0x33F4
    ctx->r18 = ADD32(ctx->r18, 0X33F4);
    // 0x800AE868: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x800AE86C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800AE870: blez        $t6, L_800AE8AC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800AE874: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_800AE8AC;
    }
    // 0x800AE874: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800AE878:
    // 0x800AE878: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x800AE87C: nop

    // 0x800AE880: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x800AE884: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x800AE888: jal         0x8007D100
    // 0x800AE88C: nop

    sprite_free(rdram, ctx);
        goto after_0;
    // 0x800AE88C: nop

    after_0:
    // 0x800AE890: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800AE894: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800AE898: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800AE89C: bne         $at, $zero, L_800AE878
    if (ctx->r1 != 0) {
        // 0x800AE8A0: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800AE878;
    }
    // 0x800AE8A0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800AE8A4: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x800AE8A8: nop

L_800AE8AC:
    // 0x800AE8AC: jal         0x80071380
    // 0x800AE8B0: nop

    mempool_free(rdram, ctx);
        goto after_1;
    // 0x800AE8B0: nop

    after_1:
    // 0x800AE8B4: sw          $zero, 0x0($s3)
    MEM_W(0X0, ctx->r19) = 0;
L_800AE8B8:
    // 0x800AE8B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800AE8BC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800AE8C0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800AE8C4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800AE8C8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800AE8CC: jr          $ra
    // 0x800AE8D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800AE8D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void free_particle_buffers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE8D4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AE8D8: lw          $a0, 0x3238($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3238);
    // 0x800AE8DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AE8E0: beq         $a0, $zero, L_800AE8F8
    if (ctx->r4 == 0) {
        // 0x800AE8E4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800AE8F8;
    }
    // 0x800AE8E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AE8E8: jal         0x80071380
    // 0x800AE8EC: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x800AE8EC: nop

    after_0:
    // 0x800AE8F0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE8F4: sw          $zero, 0x3238($at)
    MEM_W(0X3238, ctx->r1) = 0;
L_800AE8F8:
    // 0x800AE8F8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AE8FC: lw          $a0, 0x3244($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3244);
    // 0x800AE900: nop

    // 0x800AE904: beq         $a0, $zero, L_800AE91C
    if (ctx->r4 == 0) {
        // 0x800AE908: nop
    
            goto L_800AE91C;
    }
    // 0x800AE908: nop

    // 0x800AE90C: jal         0x80071380
    // 0x800AE910: nop

    mempool_free(rdram, ctx);
        goto after_1;
    // 0x800AE910: nop

    after_1:
    // 0x800AE914: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE918: sw          $zero, 0x3244($at)
    MEM_W(0X3244, ctx->r1) = 0;
L_800AE91C:
    // 0x800AE91C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AE920: lw          $a0, 0x3250($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3250);
    // 0x800AE924: nop

    // 0x800AE928: beq         $a0, $zero, L_800AE940
    if (ctx->r4 == 0) {
        // 0x800AE92C: nop
    
            goto L_800AE940;
    }
    // 0x800AE92C: nop

    // 0x800AE930: jal         0x80071380
    // 0x800AE934: nop

    mempool_free(rdram, ctx);
        goto after_2;
    // 0x800AE934: nop

    after_2:
    // 0x800AE938: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE93C: sw          $zero, 0x3250($at)
    MEM_W(0X3250, ctx->r1) = 0;
L_800AE940:
    // 0x800AE940: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AE944: lw          $a0, 0x325C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X325C);
    // 0x800AE948: nop

    // 0x800AE94C: beq         $a0, $zero, L_800AE964
    if (ctx->r4 == 0) {
        // 0x800AE950: nop
    
            goto L_800AE964;
    }
    // 0x800AE950: nop

    // 0x800AE954: jal         0x80071380
    // 0x800AE958: nop

    mempool_free(rdram, ctx);
        goto after_3;
    // 0x800AE958: nop

    after_3:
    // 0x800AE95C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE960: sw          $zero, 0x325C($at)
    MEM_W(0X325C, ctx->r1) = 0;
L_800AE964:
    // 0x800AE964: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AE968: lw          $a0, 0x3268($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3268);
    // 0x800AE96C: nop

    // 0x800AE970: beq         $a0, $zero, L_800AE98C
    if (ctx->r4 == 0) {
        // 0x800AE974: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800AE98C;
    }
    // 0x800AE974: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AE978: jal         0x80071380
    // 0x800AE97C: nop

    mempool_free(rdram, ctx);
        goto after_4;
    // 0x800AE97C: nop

    after_4:
    // 0x800AE980: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE984: sw          $zero, 0x3268($at)
    MEM_W(0X3268, ctx->r1) = 0;
    // 0x800AE988: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800AE98C:
    // 0x800AE98C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AE990: jr          $ra
    // 0x800AE994: nop

    return;
    // 0x800AE994: nop

;}
RECOMP_FUNC void free_particle_vertices_triangles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE998: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AE99C: lw          $a0, 0x3270($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3270);
    // 0x800AE9A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AE9A4: beq         $a0, $zero, L_800AE9BC
    if (ctx->r4 == 0) {
        // 0x800AE9A8: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800AE9BC;
    }
    // 0x800AE9A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AE9AC: jal         0x80071380
    // 0x800AE9B0: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x800AE9B0: nop

    after_0:
    // 0x800AE9B4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE9B8: sw          $zero, 0x3270($at)
    MEM_W(0X3270, ctx->r1) = 0;
L_800AE9BC:
    // 0x800AE9BC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AE9C0: lw          $a0, 0x3274($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3274);
    // 0x800AE9C4: nop

    // 0x800AE9C8: beq         $a0, $zero, L_800AE9E4
    if (ctx->r4 == 0) {
        // 0x800AE9CC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800AE9E4;
    }
    // 0x800AE9CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AE9D0: jal         0x80071380
    // 0x800AE9D4: nop

    mempool_free(rdram, ctx);
        goto after_1;
    // 0x800AE9D4: nop

    after_1:
    // 0x800AE9D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE9DC: sw          $zero, 0x3274($at)
    MEM_W(0X3274, ctx->r1) = 0;
    // 0x800AE9E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800AE9E4:
    // 0x800AE9E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AE9E8: jr          $ra
    // 0x800AE9EC: nop

    return;
    // 0x800AE9EC: nop

;}
RECOMP_FUNC void free_particle_assets(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE9F0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AE9F4: lw          $a0, 0x327C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X327C);
    // 0x800AE9F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AE9FC: beq         $a0, $zero, L_800AEA14
    if (ctx->r4 == 0) {
        // 0x800AEA00: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800AEA14;
    }
    // 0x800AEA00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AEA04: jal         0x80071380
    // 0x800AEA08: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x800AEA08: nop

    after_0:
    // 0x800AEA0C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AEA10: sw          $zero, 0x327C($at)
    MEM_W(0X327C, ctx->r1) = 0;
L_800AEA14:
    // 0x800AEA14: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AEA18: lw          $a0, 0x3280($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3280);
    // 0x800AEA1C: nop

    // 0x800AEA20: beq         $a0, $zero, L_800AEA38
    if (ctx->r4 == 0) {
        // 0x800AEA24: nop
    
            goto L_800AEA38;
    }
    // 0x800AEA24: nop

    // 0x800AEA28: jal         0x80071380
    // 0x800AEA2C: nop

    mempool_free(rdram, ctx);
        goto after_1;
    // 0x800AEA2C: nop

    after_1:
    // 0x800AEA30: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AEA34: sw          $zero, 0x3280($at)
    MEM_W(0X3280, ctx->r1) = 0;
L_800AEA38:
    // 0x800AEA38: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AEA3C: lw          $a0, 0x3288($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3288);
    // 0x800AEA40: nop

    // 0x800AEA44: beq         $a0, $zero, L_800AEA5C
    if (ctx->r4 == 0) {
        // 0x800AEA48: nop
    
            goto L_800AEA5C;
    }
    // 0x800AEA48: nop

    // 0x800AEA4C: jal         0x80071380
    // 0x800AEA50: nop

    mempool_free(rdram, ctx);
        goto after_2;
    // 0x800AEA50: nop

    after_2:
    // 0x800AEA54: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AEA58: sw          $zero, 0x3288($at)
    MEM_W(0X3288, ctx->r1) = 0;
L_800AEA5C:
    // 0x800AEA5C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AEA60: lw          $a0, 0x328C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X328C);
    // 0x800AEA64: nop

    // 0x800AEA68: beq         $a0, $zero, L_800AEA84
    if (ctx->r4 == 0) {
        // 0x800AEA6C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800AEA84;
    }
    // 0x800AEA6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AEA70: jal         0x80071380
    // 0x800AEA74: nop

    mempool_free(rdram, ctx);
        goto after_3;
    // 0x800AEA74: nop

    after_3:
    // 0x800AEA78: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AEA7C: sw          $zero, 0x328C($at)
    MEM_W(0X328C, ctx->r1) = 0;
    // 0x800AEA80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800AEA84:
    // 0x800AEA84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AEA88: jr          $ra
    // 0x800AEA8C: nop

    return;
    // 0x800AEA8C: nop

;}
RECOMP_FUNC void init_particle_assets(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AEA90: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800AEA94: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800AEA98: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800AEA9C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800AEAA0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800AEAA4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800AEAA8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800AEAAC: jal         0x800AE9F0
    // 0x800AEAB0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    free_particle_assets(rdram, ctx);
        goto after_0;
    // 0x800AEAB0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x800AEAB4: jal         0x80076EE4
    // 0x800AEAB8: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    asset_table_load(rdram, ctx);
        goto after_1;
    // 0x800AEAB8: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_1:
    // 0x800AEABC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800AEAC0: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x800AEAC4: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800AEAC8: addiu       $s2, $s2, 0x3280
    ctx->r18 = ADD32(ctx->r18, 0X3280);
    // 0x800AEACC: addiu       $a1, $a1, 0x3278
    ctx->r5 = ADD32(ctx->r5, 0X3278);
    // 0x800AEAD0: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x800AEAD4: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // 0x800AEAD8: sw          $a2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r6;
    // 0x800AEADC: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x800AEAE0: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x800AEAE4: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x800AEAE8: beq         $a2, $t8, L_800AEB10
    if (ctx->r6 == ctx->r24) {
        // 0x800AEAEC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800AEB10;
    }
    // 0x800AEAEC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800AEAF0: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
L_800AEAF4:
    // 0x800AEAF4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800AEAF8: addu        $t1, $a0, $t0
    ctx->r9 = ADD32(ctx->r4, ctx->r8);
    // 0x800AEAFC: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x800AEB00: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x800AEB04: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x800AEB08: bne         $a2, $t2, L_800AEAF4
    if (ctx->r6 != ctx->r10) {
        // 0x800AEB0C: addiu       $t9, $v1, 0x1
        ctx->r25 = ADD32(ctx->r3, 0X1);
            goto L_800AEAF4;
    }
    // 0x800AEB0C: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
L_800AEB10:
    // 0x800AEB10: jal         0x80076EE4
    // 0x800AEB14: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    asset_table_load(rdram, ctx);
        goto after_2;
    // 0x800AEB14: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_2:
    // 0x800AEB18: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800AEB1C: addiu       $a1, $a1, 0x3278
    ctx->r5 = ADD32(ctx->r5, 0X3278);
    // 0x800AEB20: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x800AEB24: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AEB28: addiu       $v1, $v1, 0x327C
    ctx->r3 = ADD32(ctx->r3, 0X327C);
    // 0x800AEB2C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800AEB30: blez        $t3, L_800AEB70
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800AEB34: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_800AEB70;
    }
    // 0x800AEB34: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800AEB38: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800AEB3C:
    // 0x800AEB3C: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x800AEB40: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800AEB44: addu        $v0, $t4, $s0
    ctx->r2 = ADD32(ctx->r12, ctx->r16);
    // 0x800AEB48: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x800AEB4C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800AEB50: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800AEB54: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800AEB58: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x800AEB5C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800AEB60: slt         $at, $s1, $t8
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800AEB64: bne         $at, $zero, L_800AEB3C
    if (ctx->r1 != 0) {
        // 0x800AEB68: nop
    
            goto L_800AEB3C;
    }
    // 0x800AEB68: nop

    // 0x800AEB6C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800AEB70:
    // 0x800AEB70: jal         0x80076EE4
    // 0x800AEB74: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    asset_table_load(rdram, ctx);
        goto after_3;
    // 0x800AEB74: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_3:
    // 0x800AEB78: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x800AEB7C: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800AEB80: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x800AEB84: addiu       $s3, $s3, 0x328C
    ctx->r19 = ADD32(ctx->r19, 0X328C);
    // 0x800AEB88: addiu       $s2, $s2, 0x3284
    ctx->r18 = ADD32(ctx->r18, 0X3284);
    // 0x800AEB8C: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x800AEB90: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x800AEB94: sw          $a2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r6;
    // 0x800AEB98: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x800AEB9C: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x800AEBA0: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x800AEBA4: beq         $a2, $t1, L_800AEBCC
    if (ctx->r6 == ctx->r9) {
        // 0x800AEBA8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800AEBCC;
    }
    // 0x800AEBA8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800AEBAC: addiu       $t2, $v1, 0x1
    ctx->r10 = ADD32(ctx->r3, 0X1);
L_800AEBB0:
    // 0x800AEBB0: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800AEBB4: addu        $t4, $a0, $t3
    ctx->r12 = ADD32(ctx->r4, ctx->r11);
    // 0x800AEBB8: sw          $t2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r10;
    // 0x800AEBBC: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x800AEBC0: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
    // 0x800AEBC4: bne         $a2, $t5, L_800AEBB0
    if (ctx->r6 != ctx->r13) {
        // 0x800AEBC8: addiu       $t2, $v1, 0x1
        ctx->r10 = ADD32(ctx->r3, 0X1);
            goto L_800AEBB0;
    }
    // 0x800AEBC8: addiu       $t2, $v1, 0x1
    ctx->r10 = ADD32(ctx->r3, 0X1);
L_800AEBCC:
    // 0x800AEBCC: jal         0x80076EE4
    // 0x800AEBD0: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    asset_table_load(rdram, ctx);
        goto after_4;
    // 0x800AEBD0: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    after_4:
    // 0x800AEBD4: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x800AEBD8: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x800AEBDC: addiu       $s5, $s5, 0x3288
    ctx->r21 = ADD32(ctx->r21, 0X3288);
    // 0x800AEBE0: blez        $t6, L_800AEC64
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800AEBE4: sw          $v0, 0x0($s5)
        MEM_W(0X0, ctx->r21) = ctx->r2;
            goto L_800AEC64;
    }
    // 0x800AEBE4: sw          $v0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r2;
    // 0x800AEBE8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800AEBEC: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
L_800AEBF0:
    // 0x800AEBF0: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x800AEBF4: lw          $t9, 0x0($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X0);
    // 0x800AEBF8: addu        $v0, $t7, $s0
    ctx->r2 = ADD32(ctx->r15, ctx->r16);
    // 0x800AEBFC: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800AEC00: nop

    // 0x800AEC04: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800AEC08: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x800AEC0C: lw          $t1, 0x0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X0);
    // 0x800AEC10: nop

    // 0x800AEC14: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x800AEC18: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800AEC1C: nop

    // 0x800AEC20: lw          $v1, 0x9C($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X9C);
    // 0x800AEC24: nop

    // 0x800AEC28: beq         $s4, $v1, L_800AEC50
    if (ctx->r20 == ctx->r3) {
        // 0x800AEC2C: nop
    
            goto L_800AEC50;
    }
    // 0x800AEC2C: nop

    // 0x800AEC30: jal         0x8001E2D0
    // 0x800AEC34: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    get_misc_asset(rdram, ctx);
        goto after_5;
    // 0x800AEC34: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    after_5:
    // 0x800AEC38: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x800AEC3C: nop

    // 0x800AEC40: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x800AEC44: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800AEC48: nop

    // 0x800AEC4C: sw          $v0, 0x9C($t6)
    MEM_W(0X9C, ctx->r14) = ctx->r2;
L_800AEC50:
    // 0x800AEC50: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800AEC54: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800AEC58: slt         $at, $s1, $t7
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800AEC5C: bne         $at, $zero, L_800AEBF0
    if (ctx->r1 != 0) {
        // 0x800AEC60: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800AEBF0;
    }
    // 0x800AEC60: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800AEC64:
    // 0x800AEC64: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800AEC68: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800AEC6C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800AEC70: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800AEC74: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800AEC78: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800AEC7C: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800AEC80: jr          $ra
    // 0x800AEC84: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800AEC84: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void init_particle_buffers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AEC88: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800AEC8C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800AEC90: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800AEC94: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800AEC98: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800AEC9C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AECA0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800AECA4: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x800AECA8: or          $s4, $a3, $zero
    ctx->r20 = ctx->r7 | 0;
    // 0x800AECAC: or          $s7, $a2, $zero
    ctx->r23 = ctx->r6 | 0;
    // 0x800AECB0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800AECB4: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800AECB8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800AECBC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800AECC0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800AECC4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800AECC8: bgez        $a0, L_800AECD4
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800AECCC: sw          $zero, 0x3290($at)
        MEM_W(0X3290, ctx->r1) = 0;
            goto L_800AECD4;
    }
    // 0x800AECCC: sw          $zero, 0x3290($at)
    MEM_W(0X3290, ctx->r1) = 0;
    // 0x800AECD0: addiu       $s1, $zero, 0x10
    ctx->r17 = ADD32(0, 0X10);
L_800AECD4:
    // 0x800AECD4: lw          $fp, 0x78($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X78);
    // 0x800AECD8: bgez        $s3, L_800AECE4
    if (SIGNED(ctx->r19) >= 0) {
        // 0x800AECDC: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800AECE4;
    }
    // 0x800AECDC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AECE0: addiu       $s3, $zero, 0x10
    ctx->r19 = ADD32(0, 0X10);
L_800AECE4:
    // 0x800AECE4: bgez        $s7, L_800AECF0
    if (SIGNED(ctx->r23) >= 0) {
        // 0x800AECE8: nop
    
            goto L_800AECF0;
    }
    // 0x800AECE8: nop

    // 0x800AECEC: addiu       $s7, $zero, 0xD0
    ctx->r23 = ADD32(0, 0XD0);
L_800AECF0:
    // 0x800AECF0: bgez        $s4, L_800AECFC
    if (SIGNED(ctx->r20) >= 0) {
        // 0x800AECF4: nop
    
            goto L_800AECFC;
    }
    // 0x800AECF4: nop

    // 0x800AECF8: addiu       $s4, $zero, 0xA0
    ctx->r20 = ADD32(0, 0XA0);
L_800AECFC:
    // 0x800AECFC: bgez        $fp, L_800AED08
    if (SIGNED(ctx->r30) >= 0) {
        // 0x800AED00: nop
    
            goto L_800AED08;
    }
    // 0x800AED00: nop

    // 0x800AED04: addiu       $fp, $zero, 0x40
    ctx->r30 = ADD32(0, 0X40);
L_800AED08:
    // 0x800AED08: sw          $s1, 0x33DC($at)
    MEM_W(0X33DC, ctx->r1) = ctx->r17;
    // 0x800AED0C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AED10: sw          $zero, 0x3234($at)
    MEM_W(0X3234, ctx->r1) = 0;
    // 0x800AED14: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AED18: sw          $s3, 0x33E0($at)
    MEM_W(0X33E0, ctx->r1) = ctx->r19;
    // 0x800AED1C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AED20: sw          $zero, 0x3240($at)
    MEM_W(0X3240, ctx->r1) = 0;
    // 0x800AED24: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AED28: sw          $s7, 0x33E4($at)
    MEM_W(0X33E4, ctx->r1) = ctx->r23;
    // 0x800AED2C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AED30: sw          $zero, 0x324C($at)
    MEM_W(0X324C, ctx->r1) = 0;
    // 0x800AED34: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AED38: sw          $s4, 0x33E8($at)
    MEM_W(0X33E8, ctx->r1) = ctx->r20;
    // 0x800AED3C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AED40: sw          $zero, 0x3258($at)
    MEM_W(0X3258, ctx->r1) = 0;
    // 0x800AED44: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AED48: sw          $fp, 0x33EC($at)
    MEM_W(0X33EC, ctx->r1) = ctx->r30;
    // 0x800AED4C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AED50: jal         0x800AE998
    // 0x800AED54: sw          $zero, 0x3264($at)
    MEM_W(0X3264, ctx->r1) = 0;
    free_particle_vertices_triangles(rdram, ctx);
        goto after_0;
    // 0x800AED54: sw          $zero, 0x3264($at)
    MEM_W(0X3264, ctx->r1) = 0;
    after_0:
    // 0x800AED58: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x800AED5C: sll         $t1, $s4, 2
    ctx->r9 = S32(ctx->r20 << 2);
    // 0x800AED60: subu        $t1, $t1, $s4
    ctx->r9 = SUB32(ctx->r9, ctx->r20);
    // 0x800AED64: subu        $t6, $t6, $s1
    ctx->r14 = SUB32(ctx->r14, ctx->r17);
    // 0x800AED68: sll         $t7, $s3, 2
    ctx->r15 = S32(ctx->r19 << 2);
    // 0x800AED6C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800AED70: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x800AED74: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x800AED78: sll         $t3, $fp, 4
    ctx->r11 = S32(ctx->r30 << 4);
    // 0x800AED7C: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    // 0x800AED80: lui         $s2, 0x8080
    ctx->r18 = S32(0X8080 << 16);
    // 0x800AED84: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x800AED88: ori         $s2, $s2, 0x8080
    ctx->r18 = ctx->r18 | 0X8080;
    // 0x800AED8C: addu        $t4, $t4, $a0
    ctx->r12 = ADD32(ctx->r12, ctx->r4);
    // 0x800AED90: sll         $a0, $t4, 1
    ctx->r4 = S32(ctx->r12 << 1);
    // 0x800AED94: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800AED98: jal         0x80070EDC
    // 0x800AED9C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x800AED9C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_1:
    // 0x800AEDA0: sll         $t5, $s3, 1
    ctx->r13 = S32(ctx->r19 << 1);
    // 0x800AEDA4: addu        $t6, $s1, $t5
    ctx->r14 = ADD32(ctx->r17, ctx->r13);
    // 0x800AEDA8: addu        $a0, $t6, $s0
    ctx->r4 = ADD32(ctx->r14, ctx->r16);
    // 0x800AEDAC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AEDB0: sll         $t7, $a0, 4
    ctx->r15 = S32(ctx->r4 << 4);
    // 0x800AEDB4: sw          $v0, 0x3270($at)
    MEM_W(0X3270, ctx->r1) = ctx->r2;
    // 0x800AEDB8: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800AEDBC: jal         0x80070EDC
    // 0x800AEDC0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_2;
    // 0x800AEDC0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
    // 0x800AEDC4: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800AEDC8: addiu       $s0, $s0, 0x3274
    ctx->r16 = ADD32(ctx->r16, 0X3274);
    // 0x800AEDCC: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800AEDD0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AEDD4: jal         0x800AE8D4
    // 0x800AEDD8: sw          $zero, 0x326C($at)
    MEM_W(0X326C, ctx->r1) = 0;
    free_particle_buffers(rdram, ctx);
        goto after_3;
    // 0x800AEDD8: sw          $zero, 0x326C($at)
    MEM_W(0X326C, ctx->r1) = 0;
    after_3:
    // 0x800AEDDC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800AEDE0: lw          $t8, 0x33DC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X33DC);
    // 0x800AEDE4: nop

    // 0x800AEDE8: blez        $t8, L_800AEE0C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800AEDEC: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800AEE0C;
    }
    // 0x800AEDEC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AEDF0: sw          $zero, 0x3230($at)
    MEM_W(0X3230, ctx->r1) = 0;
    // 0x800AEDF4: sll         $a0, $s1, 7
    ctx->r4 = S32(ctx->r17 << 7);
    // 0x800AEDF8: jal         0x80070EDC
    // 0x800AEDFC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_4;
    // 0x800AEDFC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_4:
    // 0x800AEE00: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x800AEE04: addiu       $s5, $s5, 0x3238
    ctx->r21 = ADD32(ctx->r21, 0X3238);
    // 0x800AEE08: sw          $v0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r2;
L_800AEE0C:
    // 0x800AEE0C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800AEE10: lw          $t9, 0x33E0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X33E0);
    // 0x800AEE14: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x800AEE18: blez        $t9, L_800AEE40
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800AEE1C: addiu       $s5, $s5, 0x3238
        ctx->r21 = ADD32(ctx->r21, 0X3238);
            goto L_800AEE40;
    }
    // 0x800AEE1C: addiu       $s5, $s5, 0x3238
    ctx->r21 = ADD32(ctx->r21, 0X3238);
    // 0x800AEE20: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AEE24: sw          $zero, 0x323C($at)
    MEM_W(0X323C, ctx->r1) = 0;
    // 0x800AEE28: sll         $a0, $s3, 7
    ctx->r4 = S32(ctx->r19 << 7);
    // 0x800AEE2C: jal         0x80070EDC
    // 0x800AEE30: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_5;
    // 0x800AEE30: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_5:
    // 0x800AEE34: lui         $s6, 0x800E
    ctx->r22 = S32(0X800E << 16);
    // 0x800AEE38: addiu       $s6, $s6, 0x3244
    ctx->r22 = ADD32(ctx->r22, 0X3244);
    // 0x800AEE3C: sw          $v0, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r2;
L_800AEE40:
    // 0x800AEE40: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800AEE44: lw          $t1, 0x33E4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X33E4);
    // 0x800AEE48: lui         $s6, 0x800E
    ctx->r22 = S32(0X800E << 16);
    // 0x800AEE4C: blez        $t1, L_800AEE78
    if (SIGNED(ctx->r9) <= 0) {
        // 0x800AEE50: addiu       $s6, $s6, 0x3244
        ctx->r22 = ADD32(ctx->r22, 0X3244);
            goto L_800AEE78;
    }
    // 0x800AEE50: addiu       $s6, $s6, 0x3244
    ctx->r22 = ADD32(ctx->r22, 0X3244);
    // 0x800AEE54: sll         $a0, $s7, 3
    ctx->r4 = S32(ctx->r23 << 3);
    // 0x800AEE58: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AEE5C: subu        $a0, $a0, $s7
    ctx->r4 = SUB32(ctx->r4, ctx->r23);
    // 0x800AEE60: sw          $zero, 0x3248($at)
    MEM_W(0X3248, ctx->r1) = 0;
    // 0x800AEE64: sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4 << 4);
    // 0x800AEE68: jal         0x80070EDC
    // 0x800AEE6C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_6;
    // 0x800AEE6C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_6:
    // 0x800AEE70: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AEE74: sw          $v0, 0x3250($at)
    MEM_W(0X3250, ctx->r1) = ctx->r2;
L_800AEE78:
    // 0x800AEE78: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800AEE7C: lw          $t2, 0x33E8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X33E8);
    // 0x800AEE80: nop

    // 0x800AEE84: blez        $t2, L_800AEEA8
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800AEE88: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800AEEA8;
    }
    // 0x800AEE88: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AEE8C: sw          $zero, 0x3254($at)
    MEM_W(0X3254, ctx->r1) = 0;
    // 0x800AEE90: sll         $a0, $s4, 7
    ctx->r4 = S32(ctx->r20 << 7);
    // 0x800AEE94: jal         0x80070EDC
    // 0x800AEE98: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_7;
    // 0x800AEE98: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_7:
    // 0x800AEE9C: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x800AEEA0: addiu       $s7, $s7, 0x325C
    ctx->r23 = ADD32(ctx->r23, 0X325C);
    // 0x800AEEA4: sw          $v0, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r2;
L_800AEEA8:
    // 0x800AEEA8: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800AEEAC: lw          $t3, 0x33EC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X33EC);
    // 0x800AEEB0: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x800AEEB4: blez        $t3, L_800AEEE4
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800AEEB8: addiu       $s7, $s7, 0x325C
        ctx->r23 = ADD32(ctx->r23, 0X325C);
            goto L_800AEEE4;
    }
    // 0x800AEEB8: addiu       $s7, $s7, 0x325C
    ctx->r23 = ADD32(ctx->r23, 0X325C);
    // 0x800AEEBC: sll         $a0, $fp, 4
    ctx->r4 = S32(ctx->r30 << 4);
    // 0x800AEEC0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AEEC4: addu        $a0, $a0, $fp
    ctx->r4 = ADD32(ctx->r4, ctx->r30);
    // 0x800AEEC8: sw          $zero, 0x3260($at)
    MEM_W(0X3260, ctx->r1) = 0;
    // 0x800AEECC: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x800AEED0: jal         0x80070EDC
    // 0x800AEED4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_8;
    // 0x800AEED4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_8:
    // 0x800AEED8: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x800AEEDC: addiu       $fp, $fp, 0x3268
    ctx->r30 = ADD32(ctx->r30, 0X3268);
    // 0x800AEEE0: sw          $v0, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r2;
L_800AEEE4:
    // 0x800AEEE4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800AEEE8: lw          $v0, 0x33DC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X33DC);
    // 0x800AEEEC: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800AEEF0: lw          $t5, 0x3270($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3270);
    // 0x800AEEF4: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800AEEF8: sll         $t2, $v0, 3
    ctx->r10 = S32(ctx->r2 << 3);
    // 0x800AEEFC: lw          $t1, 0x0($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X0);
    // 0x800AEF00: sll         $t4, $zero, 3
    ctx->r12 = S32(0 << 3);
    // 0x800AEF04: sll         $t7, $zero, 4
    ctx->r15 = S32(0 << 4);
    // 0x800AEF08: subu        $t2, $t2, $v0
    ctx->r10 = SUB32(ctx->r10, ctx->r2);
    // 0x800AEF0C: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x800AEF10: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x800AEF14: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800AEF18: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800AEF1C: addiu       $fp, $fp, 0x3268
    ctx->r30 = ADD32(ctx->r30, 0X3268);
    // 0x800AEF20: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
    // 0x800AEF24: sw          $t9, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r25;
    // 0x800AEF28: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800AEF2C: blez        $v0, L_800AEF88
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800AEF30: addu        $s2, $t1, $t2
        ctx->r18 = ADD32(ctx->r9, ctx->r10);
            goto L_800AEF88;
    }
    // 0x800AEF30: addu        $s2, $t1, $t2
    ctx->r18 = ADD32(ctx->r9, ctx->r10);
    // 0x800AEF34: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800AEF38: addiu       $s4, $sp, 0x50
    ctx->r20 = ADD32(ctx->r29, 0X50);
    // 0x800AEF3C: addiu       $s3, $sp, 0x54
    ctx->r19 = ADD32(ctx->r29, 0X54);
L_800AEF40:
    // 0x800AEF40: lw          $t5, 0x0($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X0);
    // 0x800AEF44: sll         $t3, $s1, 4
    ctx->r11 = S32(ctx->r17 << 4);
    // 0x800AEF48: addu        $t4, $t3, $s2
    ctx->r12 = ADD32(ctx->r11, ctx->r18);
    // 0x800AEF4C: addu        $t6, $t5, $s0
    ctx->r14 = ADD32(ctx->r13, ctx->r16);
    // 0x800AEF50: sw          $t4, 0x44($t6)
    MEM_W(0X44, ctx->r14) = ctx->r12;
    // 0x800AEF54: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
    // 0x800AEF58: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800AEF5C: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x800AEF60: lw          $a0, 0x44($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X44);
    // 0x800AEF64: jal         0x800AF374
    // 0x800AEF68: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    init_triangle_particle_model(rdram, ctx);
        goto after_9;
    // 0x800AEF68: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_9:
    // 0x800AEF6C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800AEF70: lw          $t9, 0x33DC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X33DC);
    // 0x800AEF74: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800AEF78: slt         $at, $s1, $t9
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800AEF7C: bne         $at, $zero, L_800AEF40
    if (ctx->r1 != 0) {
        // 0x800AEF80: addiu       $s0, $s0, 0x70
        ctx->r16 = ADD32(ctx->r16, 0X70);
            goto L_800AEF40;
    }
    // 0x800AEF80: addiu       $s0, $s0, 0x70
    ctx->r16 = ADD32(ctx->r16, 0X70);
    // 0x800AEF84: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800AEF88:
    // 0x800AEF88: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AEF8C: addiu       $v1, $v1, 0x33E0
    ctx->r3 = ADD32(ctx->r3, 0X33E0);
    // 0x800AEF90: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800AEF94: lw          $t1, 0x0($s6)
    ctx->r9 = MEM_W(ctx->r22, 0X0);
    // 0x800AEF98: sll         $t2, $v0, 3
    ctx->r10 = S32(ctx->r2 << 3);
    // 0x800AEF9C: subu        $t2, $t2, $v0
    ctx->r10 = SUB32(ctx->r10, ctx->r2);
    // 0x800AEFA0: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x800AEFA4: addiu       $s3, $sp, 0x54
    ctx->r19 = ADD32(ctx->r29, 0X54);
    // 0x800AEFA8: addiu       $s4, $sp, 0x50
    ctx->r20 = ADD32(ctx->r29, 0X50);
    // 0x800AEFAC: blez        $v0, L_800AF008
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800AEFB0: addu        $s2, $t1, $t2
        ctx->r18 = ADD32(ctx->r9, ctx->r10);
            goto L_800AF008;
    }
    // 0x800AEFB0: addu        $s2, $t1, $t2
    ctx->r18 = ADD32(ctx->r9, ctx->r10);
    // 0x800AEFB4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800AEFB8:
    // 0x800AEFB8: lw          $t4, 0x0($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X0);
    // 0x800AEFBC: sll         $t3, $s1, 4
    ctx->r11 = S32(ctx->r17 << 4);
    // 0x800AEFC0: addu        $t5, $t3, $s2
    ctx->r13 = ADD32(ctx->r11, ctx->r18);
    // 0x800AEFC4: addu        $t6, $t4, $s0
    ctx->r14 = ADD32(ctx->r12, ctx->r16);
    // 0x800AEFC8: sw          $t5, 0x44($t6)
    MEM_W(0X44, ctx->r14) = ctx->r13;
    // 0x800AEFCC: lw          $t7, 0x0($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X0);
    // 0x800AEFD0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800AEFD4: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x800AEFD8: lw          $a0, 0x44($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X44);
    // 0x800AEFDC: jal         0x800AF418
    // 0x800AEFE0: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    init_rectangle_particle_model(rdram, ctx);
        goto after_10;
    // 0x800AEFE0: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_10:
    // 0x800AEFE4: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800AEFE8: lw          $t9, 0x33E0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X33E0);
    // 0x800AEFEC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800AEFF0: slt         $at, $s1, $t9
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800AEFF4: bne         $at, $zero, L_800AEFB8
    if (ctx->r1 != 0) {
        // 0x800AEFF8: addiu       $s0, $s0, 0x70
        ctx->r16 = ADD32(ctx->r16, 0X70);
            goto L_800AEFB8;
    }
    // 0x800AEFF8: addiu       $s0, $s0, 0x70
    ctx->r16 = ADD32(ctx->r16, 0X70);
    // 0x800AEFFC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AF000: addiu       $v1, $v1, 0x33E0
    ctx->r3 = ADD32(ctx->r3, 0X33E0);
    // 0x800AF004: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800AF008:
    // 0x800AF008: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800AF00C: addiu       $a3, $a3, 0x33E8
    ctx->r7 = ADD32(ctx->r7, 0X33E8);
    // 0x800AF010: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x800AF014: lw          $t1, 0x0($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X0);
    // 0x800AF018: sll         $t2, $v0, 3
    ctx->r10 = S32(ctx->r2 << 3);
    // 0x800AF01C: subu        $t2, $t2, $v0
    ctx->r10 = SUB32(ctx->r10, ctx->r2);
    // 0x800AF020: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x800AF024: blez        $v0, L_800AF094
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800AF028: addu        $s2, $t1, $t2
        ctx->r18 = ADD32(ctx->r9, ctx->r10);
            goto L_800AF094;
    }
    // 0x800AF028: addu        $s2, $t1, $t2
    ctx->r18 = ADD32(ctx->r9, ctx->r10);
    // 0x800AF02C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800AF030:
    // 0x800AF030: lw          $t5, 0x0($s7)
    ctx->r13 = MEM_W(ctx->r23, 0X0);
    // 0x800AF034: sll         $t3, $s1, 4
    ctx->r11 = S32(ctx->r17 << 4);
    // 0x800AF038: addu        $t4, $t3, $s2
    ctx->r12 = ADD32(ctx->r11, ctx->r18);
    // 0x800AF03C: addu        $t6, $t5, $s0
    ctx->r14 = ADD32(ctx->r13, ctx->r16);
    // 0x800AF040: sw          $t4, 0x44($t6)
    MEM_W(0X44, ctx->r14) = ctx->r12;
    // 0x800AF044: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x800AF048: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800AF04C: addiu       $t7, $t7, 0x3298
    ctx->r15 = ADD32(ctx->r15, 0X3298);
    // 0x800AF050: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
    // 0x800AF054: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x800AF058: lw          $a0, 0x44($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X44);
    // 0x800AF05C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800AF060: jal         0x800AF4E8
    // 0x800AF064: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    init_line_particle_model(rdram, ctx);
        goto after_11;
    // 0x800AF064: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_11:
    // 0x800AF068: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800AF06C: lw          $t1, 0x33E8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X33E8);
    // 0x800AF070: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800AF074: slt         $at, $s1, $t1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800AF078: bne         $at, $zero, L_800AF030
    if (ctx->r1 != 0) {
        // 0x800AF07C: addiu       $s0, $s0, 0x70
        ctx->r16 = ADD32(ctx->r16, 0X70);
            goto L_800AF030;
    }
    // 0x800AF07C: addiu       $s0, $s0, 0x70
    ctx->r16 = ADD32(ctx->r16, 0X70);
    // 0x800AF080: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800AF084: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AF088: addiu       $v1, $v1, 0x33E0
    ctx->r3 = ADD32(ctx->r3, 0X33E0);
    // 0x800AF08C: addiu       $a3, $a3, 0x33E8
    ctx->r7 = ADD32(ctx->r7, 0X33E8);
    // 0x800AF090: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800AF094:
    // 0x800AF094: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800AF098: addiu       $t0, $t0, 0x33EC
    ctx->r8 = ADD32(ctx->r8, 0X33EC);
    // 0x800AF09C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800AF0A0: lw          $t2, 0x0($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X0);
    // 0x800AF0A4: sll         $t3, $v0, 4
    ctx->r11 = S32(ctx->r2 << 4);
    // 0x800AF0A8: subu        $t3, $t3, $v0
    ctx->r11 = SUB32(ctx->r11, ctx->r2);
    // 0x800AF0AC: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x800AF0B0: blez        $v0, L_800AF128
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800AF0B4: addu        $s2, $t2, $t3
        ctx->r18 = ADD32(ctx->r10, ctx->r11);
            goto L_800AF128;
    }
    // 0x800AF0B4: addu        $s2, $t2, $t3
    ctx->r18 = ADD32(ctx->r10, ctx->r11);
    // 0x800AF0B8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800AF0BC:
    // 0x800AF0BC: lw          $t6, 0x0($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X0);
    // 0x800AF0C0: sll         $t5, $s1, 4
    ctx->r13 = S32(ctx->r17 << 4);
    // 0x800AF0C4: addu        $t4, $t5, $s2
    ctx->r12 = ADD32(ctx->r13, ctx->r18);
    // 0x800AF0C8: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x800AF0CC: sw          $t4, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->r12;
    // 0x800AF0D0: lw          $t9, 0x0($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X0);
    // 0x800AF0D4: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800AF0D8: addiu       $t8, $t8, 0x3308
    ctx->r24 = ADD32(ctx->r24, 0X3308);
    // 0x800AF0DC: sw          $t8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r24;
    // 0x800AF0E0: addu        $t1, $t9, $s0
    ctx->r9 = ADD32(ctx->r25, ctx->r16);
    // 0x800AF0E4: lw          $a0, 0x44($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X44);
    // 0x800AF0E8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800AF0EC: jal         0x800AF584
    // 0x800AF0F0: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    init_point_particle_model(rdram, ctx);
        goto after_12;
    // 0x800AF0F0: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_12:
    // 0x800AF0F4: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800AF0F8: lw          $t2, 0x33EC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X33EC);
    // 0x800AF0FC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800AF100: slt         $at, $s1, $t2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800AF104: bne         $at, $zero, L_800AF0BC
    if (ctx->r1 != 0) {
        // 0x800AF108: addiu       $s0, $s0, 0x78
        ctx->r16 = ADD32(ctx->r16, 0X78);
            goto L_800AF0BC;
    }
    // 0x800AF108: addiu       $s0, $s0, 0x78
    ctx->r16 = ADD32(ctx->r16, 0X78);
    // 0x800AF10C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800AF110: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800AF114: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AF118: addiu       $v1, $v1, 0x33E0
    ctx->r3 = ADD32(ctx->r3, 0X33E0);
    // 0x800AF11C: addiu       $a3, $a3, 0x33E8
    ctx->r7 = ADD32(ctx->r7, 0X33E8);
    // 0x800AF120: addiu       $t0, $t0, 0x33EC
    ctx->r8 = ADD32(ctx->r8, 0X33EC);
    // 0x800AF124: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800AF128:
    // 0x800AF128: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800AF12C: lw          $t3, 0x33DC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X33DC);
    // 0x800AF130: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x800AF134: blez        $t3, L_800AF170
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800AF138: addiu       $s3, $s3, 0x33F0
        ctx->r19 = ADD32(ctx->r19, 0X33F0);
            goto L_800AF170;
    }
    // 0x800AF138: addiu       $s3, $s3, 0x33F0
    ctx->r19 = ADD32(ctx->r19, 0X33F0);
    // 0x800AF13C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800AF140:
    // 0x800AF140: lw          $t5, 0x0($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X0);
    // 0x800AF144: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800AF148: addu        $t6, $t5, $s0
    ctx->r14 = ADD32(ctx->r13, ctx->r16);
    // 0x800AF14C: sh          $zero, 0x2C($t6)
    MEM_H(0X2C, ctx->r14) = 0;
    // 0x800AF150: lw          $t4, 0x33DC($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X33DC);
    // 0x800AF154: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800AF158: slt         $at, $s1, $t4
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800AF15C: bne         $at, $zero, L_800AF140
    if (ctx->r1 != 0) {
        // 0x800AF160: addiu       $s0, $s0, 0x70
        ctx->r16 = ADD32(ctx->r16, 0X70);
            goto L_800AF140;
    }
    // 0x800AF160: addiu       $s0, $s0, 0x70
    ctx->r16 = ADD32(ctx->r16, 0X70);
    // 0x800AF164: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800AF168: addiu       $t0, $t0, 0x33EC
    ctx->r8 = ADD32(ctx->r8, 0X33EC);
    // 0x800AF16C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800AF170:
    // 0x800AF170: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800AF174: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800AF178: blez        $t7, L_800AF1B0
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800AF17C: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_800AF1B0;
    }
    // 0x800AF17C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
L_800AF180:
    // 0x800AF180: lw          $t8, 0x0($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X0);
    // 0x800AF184: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800AF188: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x800AF18C: sh          $zero, 0x2C($t9)
    MEM_H(0X2C, ctx->r25) = 0;
    // 0x800AF190: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x800AF194: addiu       $s0, $s0, 0x70
    ctx->r16 = ADD32(ctx->r16, 0X70);
    // 0x800AF198: slt         $at, $s1, $t1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800AF19C: bne         $at, $zero, L_800AF180
    if (ctx->r1 != 0) {
        // 0x800AF1A0: nop
    
            goto L_800AF180;
    }
    // 0x800AF1A0: nop

    // 0x800AF1A4: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800AF1A8: addiu       $t0, $t0, 0x33EC
    ctx->r8 = ADD32(ctx->r8, 0X33EC);
    // 0x800AF1AC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800AF1B0:
    // 0x800AF1B0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AF1B4: addiu       $v1, $v1, 0x33E4
    ctx->r3 = ADD32(ctx->r3, 0X33E4);
    // 0x800AF1B8: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x800AF1BC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800AF1C0: blez        $t2, L_800AF1F8
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800AF1C4: addiu       $v0, $v0, 0x3250
        ctx->r2 = ADD32(ctx->r2, 0X3250);
            goto L_800AF1F8;
    }
    // 0x800AF1C4: addiu       $v0, $v0, 0x3250
    ctx->r2 = ADD32(ctx->r2, 0X3250);
L_800AF1C8:
    // 0x800AF1C8: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x800AF1CC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800AF1D0: addu        $t5, $t3, $s0
    ctx->r13 = ADD32(ctx->r11, ctx->r16);
    // 0x800AF1D4: sh          $zero, 0x2C($t5)
    MEM_H(0X2C, ctx->r13) = 0;
    // 0x800AF1D8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800AF1DC: addiu       $s0, $s0, 0x70
    ctx->r16 = ADD32(ctx->r16, 0X70);
    // 0x800AF1E0: slt         $at, $s1, $t6
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800AF1E4: bne         $at, $zero, L_800AF1C8
    if (ctx->r1 != 0) {
        // 0x800AF1E8: nop
    
            goto L_800AF1C8;
    }
    // 0x800AF1E8: nop

    // 0x800AF1EC: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800AF1F0: addiu       $t0, $t0, 0x33EC
    ctx->r8 = ADD32(ctx->r8, 0X33EC);
    // 0x800AF1F4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800AF1F8:
    // 0x800AF1F8: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
    // 0x800AF1FC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800AF200: blez        $t4, L_800AF238
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800AF204: addiu       $a0, $zero, 0x2F
        ctx->r4 = ADD32(0, 0X2F);
            goto L_800AF238;
    }
    // 0x800AF204: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
L_800AF208:
    // 0x800AF208: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
    // 0x800AF20C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800AF210: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x800AF214: sh          $zero, 0x2C($t8)
    MEM_H(0X2C, ctx->r24) = 0;
    // 0x800AF218: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x800AF21C: addiu       $s0, $s0, 0x70
    ctx->r16 = ADD32(ctx->r16, 0X70);
    // 0x800AF220: slt         $at, $s1, $t9
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800AF224: bne         $at, $zero, L_800AF208
    if (ctx->r1 != 0) {
        // 0x800AF228: nop
    
            goto L_800AF208;
    }
    // 0x800AF228: nop

    // 0x800AF22C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800AF230: addiu       $t0, $t0, 0x33EC
    ctx->r8 = ADD32(ctx->r8, 0X33EC);
    // 0x800AF234: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800AF238:
    // 0x800AF238: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800AF23C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800AF240: blez        $t1, L_800AF26C
    if (SIGNED(ctx->r9) <= 0) {
        // 0x800AF244: nop
    
            goto L_800AF26C;
    }
    // 0x800AF244: nop

L_800AF248:
    // 0x800AF248: lw          $t2, 0x0($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X0);
    // 0x800AF24C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800AF250: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x800AF254: sh          $zero, 0x2C($t3)
    MEM_H(0X2C, ctx->r11) = 0;
    // 0x800AF258: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x800AF25C: addiu       $s0, $s0, 0x78
    ctx->r16 = ADD32(ctx->r16, 0X78);
    // 0x800AF260: slt         $at, $s1, $t5
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800AF264: bne         $at, $zero, L_800AF248
    if (ctx->r1 != 0) {
        // 0x800AF268: nop
    
            goto L_800AF248;
    }
    // 0x800AF268: nop

L_800AF26C:
    // 0x800AF26C: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x800AF270: nop

    // 0x800AF274: bne         $t6, $zero, L_800AF348
    if (ctx->r14 != 0) {
        // 0x800AF278: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_800AF348;
    }
    // 0x800AF278: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800AF27C: jal         0x80076EE4
    // 0x800AF280: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    asset_table_load(rdram, ctx);
        goto after_13;
    // 0x800AF280: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_13:
    // 0x800AF284: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800AF288: addiu       $a2, $a2, 0x33F4
    ctx->r6 = ADD32(ctx->r6, 0X33F4);
    // 0x800AF28C: sll         $t4, $zero, 1
    ctx->r12 = S32(0 << 1);
    // 0x800AF290: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800AF294: addu        $t7, $v0, $t4
    ctx->r15 = ADD32(ctx->r2, ctx->r12);
    // 0x800AF298: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x800AF29C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800AF2A0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800AF2A4: beq         $a0, $t8, L_800AF2CC
    if (ctx->r4 == ctx->r24) {
        // 0x800AF2A8: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800AF2CC;
    }
    // 0x800AF2A8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800AF2AC: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
L_800AF2B0:
    // 0x800AF2B0: sll         $t1, $t9, 1
    ctx->r9 = S32(ctx->r25 << 1);
    // 0x800AF2B4: addu        $t2, $s2, $t1
    ctx->r10 = ADD32(ctx->r18, ctx->r9);
    // 0x800AF2B8: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800AF2BC: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x800AF2C0: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x800AF2C4: bne         $a0, $t3, L_800AF2B0
    if (ctx->r4 != ctx->r11) {
        // 0x800AF2C8: addiu       $t9, $v1, 0x1
        ctx->r25 = ADD32(ctx->r3, 0X1);
            goto L_800AF2B0;
    }
    // 0x800AF2C8: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
L_800AF2CC:
    // 0x800AF2CC: sll         $a0, $v1, 2
    ctx->r4 = S32(ctx->r3 << 2);
    // 0x800AF2D0: jal         0x80070EDC
    // 0x800AF2D4: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_14;
    // 0x800AF2D4: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_14:
    // 0x800AF2D8: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800AF2DC: addiu       $a2, $a2, 0x33F4
    ctx->r6 = ADD32(ctx->r6, 0X33F4);
    // 0x800AF2E0: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x800AF2E4: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x800AF2E8: blez        $t5, L_800AF33C
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800AF2EC: or          $s0, $s2, $zero
        ctx->r16 = ctx->r18 | 0;
            goto L_800AF33C;
    }
    // 0x800AF2EC: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x800AF2F0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800AF2F4:
    // 0x800AF2F4: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x800AF2F8: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x800AF2FC: andi        $t6, $a0, 0x3FFF
    ctx->r14 = ctx->r4 & 0X3FFF;
    // 0x800AF300: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800AF304: jal         0x8007C57C
    // 0x800AF308: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    tex_load_sprite(rdram, ctx);
        goto after_15;
    // 0x800AF308: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x800AF30C: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x800AF310: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x800AF314: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800AF318: addu        $t7, $t4, $v1
    ctx->r15 = ADD32(ctx->r12, ctx->r3);
    // 0x800AF31C: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
    // 0x800AF320: addiu       $a2, $a2, 0x33F4
    ctx->r6 = ADD32(ctx->r6, 0X33F4);
    // 0x800AF324: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800AF328: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800AF32C: slt         $at, $s1, $t8
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800AF330: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800AF334: bne         $at, $zero, L_800AF2F4
    if (ctx->r1 != 0) {
        // 0x800AF338: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800AF2F4;
    }
    // 0x800AF338: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_800AF33C:
    // 0x800AF33C: jal         0x80071380
    // 0x800AF340: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mempool_free(rdram, ctx);
        goto after_16;
    // 0x800AF340: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_16:
    // 0x800AF344: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800AF348:
    // 0x800AF348: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800AF34C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800AF350: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800AF354: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800AF358: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800AF35C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800AF360: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800AF364: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800AF368: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800AF36C: jr          $ra
    // 0x800AF370: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800AF370: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void init_triangle_particle_model(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF374: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800AF378: sh          $t6, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r14;
    // 0x800AF37C: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800AF380: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AF384: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    // 0x800AF388: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800AF38C: addiu       $v1, $v1, 0x33F8
    ctx->r3 = ADD32(ctx->r3, 0X33F8);
    // 0x800AF390: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800AF394: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
L_800AF398:
    // 0x800AF398: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x800AF39C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800AF3A0: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x800AF3A4: lh          $t9, 0x2($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X2);
    // 0x800AF3A8: sll         $t1, $a3, 16
    ctx->r9 = S32(ctx->r7 << 16);
    // 0x800AF3AC: sra         $a3, $t1, 16
    ctx->r7 = S32(SIGNED(ctx->r9) >> 16);
    // 0x800AF3B0: slti        $at, $a3, 0x3
    ctx->r1 = SIGNED(ctx->r7) < 0X3 ? 1 : 0;
    // 0x800AF3B4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800AF3B8: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x800AF3BC: sb          $t0, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r8;
    // 0x800AF3C0: sb          $t0, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r8;
    // 0x800AF3C4: sb          $t0, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r8;
    // 0x800AF3C8: sb          $t0, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r8;
    // 0x800AF3CC: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x800AF3D0: bne         $at, $zero, L_800AF398
    if (ctx->r1 != 0) {
        // 0x800AF3D4: sh          $t9, -0x8($v0)
        MEM_H(-0X8, ctx->r2) = ctx->r25;
            goto L_800AF398;
    }
    // 0x800AF3D4: sh          $t9, -0x8($v0)
    MEM_H(-0X8, ctx->r2) = ctx->r25;
    // 0x800AF3D8: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x800AF3DC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800AF3E0: sh          $t3, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r11;
    // 0x800AF3E4: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x800AF3E8: addiu       $t5, $zero, 0x40
    ctx->r13 = ADD32(0, 0X40);
    // 0x800AF3EC: sw          $t4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r12;
    // 0x800AF3F0: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x800AF3F4: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800AF3F8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800AF3FC: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
    // 0x800AF400: sb          $t6, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r14;
    // 0x800AF404: sb          $t7, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r15;
    // 0x800AF408: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x800AF40C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800AF410: jr          $ra
    // 0x800AF414: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    return;
    // 0x800AF414: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
;}
RECOMP_FUNC void init_rectangle_particle_model(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF418: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x800AF41C: sh          $t6, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r14;
    // 0x800AF420: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800AF424: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AF428: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    // 0x800AF42C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800AF430: addiu       $v1, $v1, 0x3404
    ctx->r3 = ADD32(ctx->r3, 0X3404);
    // 0x800AF434: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800AF438: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
L_800AF43C:
    // 0x800AF43C: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x800AF440: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800AF444: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x800AF448: lh          $t9, 0x2($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X2);
    // 0x800AF44C: sll         $t2, $a3, 16
    ctx->r10 = S32(ctx->r7 << 16);
    // 0x800AF450: sra         $a3, $t2, 16
    ctx->r7 = S32(SIGNED(ctx->r10) >> 16);
    // 0x800AF454: slti        $at, $a3, 0x4
    ctx->r1 = SIGNED(ctx->r7) < 0X4 ? 1 : 0;
    // 0x800AF458: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800AF45C: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x800AF460: sb          $t0, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r8;
    // 0x800AF464: sb          $t0, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r8;
    // 0x800AF468: sb          $t0, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r8;
    // 0x800AF46C: sb          $t0, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r8;
    // 0x800AF470: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x800AF474: bne         $at, $zero, L_800AF43C
    if (ctx->r1 != 0) {
        // 0x800AF478: sh          $t9, -0x8($v0)
        MEM_H(-0X8, ctx->r2) = ctx->r25;
            goto L_800AF43C;
    }
    // 0x800AF478: sh          $t9, -0x8($v0)
    MEM_H(-0X8, ctx->r2) = ctx->r25;
    // 0x800AF47C: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x800AF480: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x800AF484: sh          $t4, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r12;
    // 0x800AF488: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x800AF48C: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    // 0x800AF490: sw          $t5, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r13;
    // 0x800AF494: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x800AF498: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x800AF49C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800AF4A0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800AF4A4: sb          $a3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r7;
    // 0x800AF4A8: sb          $t0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r8;
    // 0x800AF4AC: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
    // 0x800AF4B0: sb          $t1, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r9;
    // 0x800AF4B4: sh          $zero, 0xA($v1)
    MEM_H(0XA, ctx->r3) = 0;
    // 0x800AF4B8: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x800AF4BC: sh          $zero, 0xC($v1)
    MEM_H(0XC, ctx->r3) = 0;
    // 0x800AF4C0: sh          $zero, 0xE($v1)
    MEM_H(0XE, ctx->r3) = 0;
    // 0x800AF4C4: sb          $a3, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r7;
    // 0x800AF4C8: sb          $t0, 0x11($v1)
    MEM_B(0X11, ctx->r3) = ctx->r8;
    // 0x800AF4CC: sh          $zero, 0x14($v1)
    MEM_H(0X14, ctx->r3) = 0;
    // 0x800AF4D0: sb          $t6, 0x12($v1)
    MEM_B(0X12, ctx->r3) = ctx->r14;
    // 0x800AF4D4: sb          $t1, 0x13($v1)
    MEM_B(0X13, ctx->r3) = ctx->r9;
    // 0x800AF4D8: sh          $zero, 0x1E($v1)
    MEM_H(0X1E, ctx->r3) = 0;
    // 0x800AF4DC: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x800AF4E0: jr          $ra
    // 0x800AF4E4: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    return;
    // 0x800AF4E4: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
;}
RECOMP_FUNC void init_line_particle_model(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF4E8: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x800AF4EC: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x800AF4F0: sh          $t6, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r14;
    // 0x800AF4F4: sh          $t7, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r15;
    // 0x800AF4F8: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x800AF4FC: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x800AF500: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x800AF504: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800AF508: nop

    // 0x800AF50C: sw          $t9, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r25;
    // 0x800AF510: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800AF514: nop

    // 0x800AF518: sb          $v1, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r3;
    // 0x800AF51C: sb          $v1, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r3;
    // 0x800AF520: sb          $v1, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r3;
    // 0x800AF524: sb          $v1, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r3;
    // 0x800AF528: sb          $v1, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r3;
    // 0x800AF52C: sb          $v1, 0x11($v0)
    MEM_B(0X11, ctx->r2) = ctx->r3;
    // 0x800AF530: sb          $v1, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r3;
    // 0x800AF534: sb          $v1, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r3;
    // 0x800AF538: sb          $v1, 0x24($v0)
    MEM_B(0X24, ctx->r2) = ctx->r3;
    // 0x800AF53C: sb          $v1, 0x25($v0)
    MEM_B(0X25, ctx->r2) = ctx->r3;
    // 0x800AF540: sb          $v1, 0x26($v0)
    MEM_B(0X26, ctx->r2) = ctx->r3;
    // 0x800AF544: sb          $v1, 0x27($v0)
    MEM_B(0X27, ctx->r2) = ctx->r3;
    // 0x800AF548: sb          $v1, 0x2E($v0)
    MEM_B(0X2E, ctx->r2) = ctx->r3;
    // 0x800AF54C: sb          $v1, 0x2F($v0)
    MEM_B(0X2F, ctx->r2) = ctx->r3;
    // 0x800AF550: sb          $v1, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r3;
    // 0x800AF554: sb          $v1, 0x31($v0)
    MEM_B(0X31, ctx->r2) = ctx->r3;
    // 0x800AF558: sb          $v1, 0x38($v0)
    MEM_B(0X38, ctx->r2) = ctx->r3;
    // 0x800AF55C: sb          $v1, 0x39($v0)
    MEM_B(0X39, ctx->r2) = ctx->r3;
    // 0x800AF560: sb          $v1, 0x3A($v0)
    MEM_B(0X3A, ctx->r2) = ctx->r3;
    // 0x800AF564: sb          $v1, 0x3B($v0)
    MEM_B(0X3B, ctx->r2) = ctx->r3;
    // 0x800AF568: addiu       $v0, $v0, 0x3C
    ctx->r2 = ADD32(ctx->r2, 0X3C);
    // 0x800AF56C: sb          $v1, -0x22($v0)
    MEM_B(-0X22, ctx->r2) = ctx->r3;
    // 0x800AF570: sb          $v1, -0x21($v0)
    MEM_B(-0X21, ctx->r2) = ctx->r3;
    // 0x800AF574: sb          $v1, -0x20($v0)
    MEM_B(-0X20, ctx->r2) = ctx->r3;
    // 0x800AF578: sb          $v1, -0x1F($v0)
    MEM_B(-0X1F, ctx->r2) = ctx->r3;
    // 0x800AF57C: jr          $ra
    // 0x800AF580: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    return;
    // 0x800AF580: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
;}
RECOMP_FUNC void init_point_particle_model(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF584: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x800AF588: sh          $a3, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r7;
    // 0x800AF58C: sh          $a3, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r7;
    // 0x800AF590: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800AF594: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800AF598: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    // 0x800AF59C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800AF5A0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800AF5A4: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    // 0x800AF5A8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800AF5AC: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_800AF5B0:
    // 0x800AF5B0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800AF5B4: sb          $a0, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r4;
    // 0x800AF5B8: sb          $a0, 0x11($v0)
    MEM_B(0X11, ctx->r2) = ctx->r4;
    // 0x800AF5BC: sb          $a0, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r4;
    // 0x800AF5C0: sb          $a0, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r4;
    // 0x800AF5C4: sb          $a0, 0x1A($v0)
    MEM_B(0X1A, ctx->r2) = ctx->r4;
    // 0x800AF5C8: sb          $a0, 0x1B($v0)
    MEM_B(0X1B, ctx->r2) = ctx->r4;
    // 0x800AF5CC: sb          $a0, 0x1C($v0)
    MEM_B(0X1C, ctx->r2) = ctx->r4;
    // 0x800AF5D0: sb          $a0, 0x1D($v0)
    MEM_B(0X1D, ctx->r2) = ctx->r4;
    // 0x800AF5D4: sb          $a0, 0x24($v0)
    MEM_B(0X24, ctx->r2) = ctx->r4;
    // 0x800AF5D8: sb          $a0, 0x25($v0)
    MEM_B(0X25, ctx->r2) = ctx->r4;
    // 0x800AF5DC: sb          $a0, 0x26($v0)
    MEM_B(0X26, ctx->r2) = ctx->r4;
    // 0x800AF5E0: sb          $a0, 0x27($v0)
    MEM_B(0X27, ctx->r2) = ctx->r4;
    // 0x800AF5E4: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
    // 0x800AF5E8: sb          $a0, -0x22($v0)
    MEM_B(-0X22, ctx->r2) = ctx->r4;
    // 0x800AF5EC: sb          $a0, -0x21($v0)
    MEM_B(-0X21, ctx->r2) = ctx->r4;
    // 0x800AF5F0: sb          $a0, -0x20($v0)
    MEM_B(-0X20, ctx->r2) = ctx->r4;
    // 0x800AF5F4: bne         $v1, $a2, L_800AF5B0
    if (ctx->r3 != ctx->r6) {
        // 0x800AF5F8: sb          $a0, -0x1F($v0)
        MEM_B(-0X1F, ctx->r2) = ctx->r4;
            goto L_800AF5B0;
    }
    // 0x800AF5F8: sb          $a0, -0x1F($v0)
    MEM_B(-0X1F, ctx->r2) = ctx->r4;
    // 0x800AF5FC: jr          $ra
    // 0x800AF600: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    return;
    // 0x800AF600: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
;}
RECOMP_FUNC void set_triangle_texture_coords(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF604: lw          $v0, 0x44($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X44);
    // 0x800AF608: nop

    // 0x800AF60C: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x800AF610: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800AF614: lbu         $a1, 0x0($a2)
    ctx->r5 = MEM_BU(ctx->r6, 0X0);
    // 0x800AF618: lbu         $a3, 0x1($a2)
    ctx->r7 = MEM_BU(ctx->r6, 0X1);
    // 0x800AF61C: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    // 0x800AF620: sll         $t7, $t6, 21
    ctx->r15 = S32(ctx->r14 << 21);
    // 0x800AF624: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800AF628: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x800AF62C: sll         $t1, $a3, 5
    ctx->r9 = S32(ctx->r7 << 5);
    // 0x800AF630: sra         $t2, $t8, 1
    ctx->r10 = S32(SIGNED(ctx->r24) >> 1);
    // 0x800AF634: sh          $t2, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r10;
    // 0x800AF638: sh          $zero, 0x6($v1)
    MEM_H(0X6, ctx->r3) = 0;
    // 0x800AF63C: sh          $zero, 0x8($v1)
    MEM_H(0X8, ctx->r3) = 0;
    // 0x800AF640: sh          $t1, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r9;
    // 0x800AF644: sh          $t8, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r24;
    // 0x800AF648: jr          $ra
    // 0x800AF64C: sh          $t1, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r9;
    return;
    // 0x800AF64C: sh          $t1, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r9;
;}
RECOMP_FUNC void set_rectangle_texture_coords(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF650: lw          $v0, 0x44($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X44);
    // 0x800AF654: nop

    // 0x800AF658: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x800AF65C: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800AF660: lbu         $a1, 0x0($a2)
    ctx->r5 = MEM_BU(ctx->r6, 0X0);
    // 0x800AF664: lbu         $a3, 0x1($a2)
    ctx->r7 = MEM_BU(ctx->r6, 0X1);
    // 0x800AF668: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800AF66C: sll         $t8, $a1, 5
    ctx->r24 = S32(ctx->r5 << 5);
    // 0x800AF670: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x800AF674: sll         $t1, $a3, 5
    ctx->r9 = S32(ctx->r7 << 5);
    // 0x800AF678: sh          $t1, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r9;
    // 0x800AF67C: sh          $t8, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r24;
    // 0x800AF680: sh          $t8, 0x16($v1)
    MEM_H(0X16, ctx->r3) = ctx->r24;
    // 0x800AF684: sh          $t8, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r24;
    // 0x800AF688: sh          $t1, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = ctx->r9;
    // 0x800AF68C: jr          $ra
    // 0x800AF690: sh          $t8, 0x1C($v1)
    MEM_H(0X1C, ctx->r3) = ctx->r24;
    return;
    // 0x800AF690: sh          $t8, 0x1C($v1)
    MEM_H(0X1C, ctx->r3) = ctx->r24;
;}
RECOMP_FUNC void emitter_change_settings(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF694: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800AF698: lw          $t6, 0x3278($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3278);
    // 0x800AF69C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800AF6A0: slt         $at, $a2, $t6
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800AF6A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800AF6A8: bne         $at, $zero, L_800AF6B4
    if (ctx->r1 != 0) {
        // 0x800AF6AC: sw          $a3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r7;
            goto L_800AF6B4;
    }
    // 0x800AF6AC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800AF6B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800AF6B4:
    // 0x800AF6B4: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800AF6B8: lw          $t7, 0x3284($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3284);
    // 0x800AF6BC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800AF6C0: slt         $at, $a1, $t7
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800AF6C4: bne         $at, $zero, L_800AF6D0
    if (ctx->r1 != 0) {
        // 0x800AF6C8: nop
    
            goto L_800AF6D0;
    }
    // 0x800AF6C8: nop

    // 0x800AF6CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_800AF6D0:
    // 0x800AF6D0: lw          $t8, 0x328C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X328C);
    // 0x800AF6D4: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x800AF6D8: lh          $t1, 0x8($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X8);
    // 0x800AF6DC: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800AF6E0: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800AF6E4: bne         $a2, $t1, L_800AF6FC
    if (ctx->r6 != ctx->r9) {
        // 0x800AF6E8: nop
    
            goto L_800AF6FC;
    }
    // 0x800AF6E8: nop

    // 0x800AF6EC: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x800AF6F0: nop

    // 0x800AF6F4: beq         $v0, $t2, L_800AF734
    if (ctx->r2 == ctx->r10) {
        // 0x800AF6F8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800AF734;
    }
    // 0x800AF6F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800AF6FC:
    // 0x800AF6FC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800AF700: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800AF704: jal         0x800B27C0
    // 0x800AF708: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    emitter_cleanup(rdram, ctx);
        goto after_0;
    // 0x800AF708: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x800AF70C: lh          $t3, 0x32($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X32);
    // 0x800AF710: lh          $t4, 0x36($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X36);
    // 0x800AF714: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800AF718: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800AF71C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800AF720: lh          $a3, 0x2E($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X2E);
    // 0x800AF724: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800AF728: jal         0x800AF7FC
    // 0x800AF72C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    emitter_init_with_pos(rdram, ctx);
        goto after_1;
    // 0x800AF72C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    after_1:
    // 0x800AF730: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800AF734:
    // 0x800AF734: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800AF738: jr          $ra
    // 0x800AF73C: nop

    return;
    // 0x800AF73C: nop

;}
RECOMP_FUNC void emitter_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF740: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800AF744: lw          $t6, 0x3284($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3284);
    // 0x800AF748: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800AF74C: slt         $at, $a1, $t6
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800AF750: beq         $at, $zero, L_800AF7EC
    if (ctx->r1 == 0) {
        // 0x800AF754: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_800AF7EC;
    }
    // 0x800AF754: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800AF758: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800AF75C: lw          $t7, 0x328C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X328C);
    // 0x800AF760: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800AF764: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x800AF768: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800AF76C: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x800AF770: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x800AF774: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AF778: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AF77C: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800AF780: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800AF784: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800AF788: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800AF78C: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x800AF790: nop

    // 0x800AF794: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800AF798: sll         $t1, $a3, 16
    ctx->r9 = S32(ctx->r7 << 16);
    // 0x800AF79C: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800AF7A0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AF7A4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AF7A8: sra         $a3, $t1, 16
    ctx->r7 = S32(SIGNED(ctx->r9) >> 16);
    // 0x800AF7AC: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800AF7B0: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800AF7B4: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x800AF7B8: nop

    // 0x800AF7BC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800AF7C0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800AF7C4: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800AF7C8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AF7CC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AF7D0: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800AF7D4: nop

    // 0x800AF7D8: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800AF7DC: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x800AF7E0: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800AF7E4: jal         0x800AF7FC
    // 0x800AF7E8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    emitter_init_with_pos(rdram, ctx);
        goto after_0;
    // 0x800AF7E8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_0:
L_800AF7EC:
    // 0x800AF7EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800AF7F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800AF7F4: jr          $ra
    // 0x800AF7F8: nop

    return;
    // 0x800AF7F8: nop

;}
RECOMP_FUNC void emitter_init_with_pos(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF7FC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800AF800: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800AF804: lw          $t8, 0x328C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X328C);
    // 0x800AF808: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x800AF80C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800AF810: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800AF814: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800AF818: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800AF81C: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x800AF820: sh          $a2, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r6;
    // 0x800AF824: sh          $a3, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r7;
    // 0x800AF828: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x800AF82C: lh          $t1, 0x3A($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X3A);
    // 0x800AF830: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800AF834: sh          $t1, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r9;
    // 0x800AF838: lh          $t2, 0x3E($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X3E);
    // 0x800AF83C: sh          $zero, 0x1E($a0)
    MEM_H(0X1E, ctx->r4) = 0;
    // 0x800AF840: sh          $t2, 0x1C($a0)
    MEM_H(0X1C, ctx->r4) = ctx->r10;
    // 0x800AF844: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800AF848: addiu       $t4, $zero, 0x4000
    ctx->r12 = ADD32(0, 0X4000);
    // 0x800AF84C: andi        $t3, $v0, 0x4000
    ctx->r11 = ctx->r2 & 0X4000;
    // 0x800AF850: beq         $t3, $zero, L_800AF874
    if (ctx->r11 == 0) {
        // 0x800AF854: andi        $t5, $v0, 0x400
        ctx->r13 = ctx->r2 & 0X400;
            goto L_800AF874;
    }
    // 0x800AF854: andi        $t5, $v0, 0x400
    ctx->r13 = ctx->r2 & 0X400;
    // 0x800AF858: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800AF85C: sh          $t4, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r12;
    // 0x800AF860: sb          $zero, 0x6($a0)
    MEM_B(0X6, ctx->r4) = 0;
    // 0x800AF864: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
    // 0x800AF868: swc1        $f0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
    // 0x800AF86C: b           L_800AF954
    // 0x800AF870: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
        goto L_800AF954;
    // 0x800AF870: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
L_800AF874:
    // 0x800AF874: beq         $t5, $zero, L_800AF908
    if (ctx->r13 == 0) {
        // 0x800AF878: addiu       $t6, $zero, 0x400
        ctx->r14 = ADD32(0, 0X400);
            goto L_800AF908;
    }
    // 0x800AF878: addiu       $t6, $zero, 0x400
    ctx->r14 = ADD32(0, 0X400);
    // 0x800AF87C: sb          $zero, 0x6($s0)
    MEM_B(0X6, ctx->r16) = 0;
    // 0x800AF880: sh          $t6, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r14;
    // 0x800AF884: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800AF888: lw          $t7, 0x3280($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3280);
    // 0x800AF88C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x800AF890: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800AF894: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800AF898: lui         $a1, 0x8080
    ctx->r5 = S32(0X8080 << 16);
    // 0x800AF89C: lh          $v0, 0x8($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X8);
    // 0x800AF8A0: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800AF8A4: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x800AF8A8: beq         $at, $zero, L_800AF8B8
    if (ctx->r1 == 0) {
        // 0x800AF8AC: ori         $a1, $a1, 0x8080
        ctx->r5 = ctx->r5 | 0X8080;
            goto L_800AF8B8;
    }
    // 0x800AF8AC: ori         $a1, $a1, 0x8080
    ctx->r5 = ctx->r5 | 0X8080;
    // 0x800AF8B0: b           L_800AF8BC
    // 0x800AF8B4: sb          $v0, 0x7($s0)
    MEM_B(0X7, ctx->r16) = ctx->r2;
        goto L_800AF8BC;
    // 0x800AF8B4: sb          $v0, 0x7($s0)
    MEM_B(0X7, ctx->r16) = ctx->r2;
L_800AF8B8:
    // 0x800AF8B8: sb          $t1, 0x7($s0)
    MEM_B(0X7, ctx->r16) = ctx->r9;
L_800AF8BC:
    // 0x800AF8BC: lbu         $a0, 0x7($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X7);
    // 0x800AF8C0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x800AF8C4: sll         $t2, $a0, 2
    ctx->r10 = S32(ctx->r4 << 2);
    // 0x800AF8C8: jal         0x80070EDC
    // 0x800AF8CC: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x800AF8CC: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_0:
    // 0x800AF8D0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800AF8D4: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
    // 0x800AF8D8: lh          $t3, 0x14($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X14);
    // 0x800AF8DC: nop

    // 0x800AF8E0: sh          $t3, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r11;
    // 0x800AF8E4: lh          $t4, 0x16($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X16);
    // 0x800AF8E8: nop

    // 0x800AF8EC: sh          $t4, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r12;
    // 0x800AF8F0: lh          $t5, 0x22($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X22);
    // 0x800AF8F4: nop

    // 0x800AF8F8: sh          $t5, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r13;
    // 0x800AF8FC: lh          $t6, 0x24($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X24);
    // 0x800AF900: b           L_800AF954
    // 0x800AF904: sh          $t6, 0x16($s0)
    MEM_H(0X16, ctx->r16) = ctx->r14;
        goto L_800AF954;
    // 0x800AF904: sh          $t6, 0x16($s0)
    MEM_H(0X16, ctx->r16) = ctx->r14;
L_800AF908:
    // 0x800AF908: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // 0x800AF90C: lh          $t7, 0x14($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X14);
    // 0x800AF910: nop

    // 0x800AF914: sh          $t7, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r15;
    // 0x800AF918: lh          $t8, 0x16($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X16);
    // 0x800AF91C: nop

    // 0x800AF920: sh          $t8, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r24;
    // 0x800AF924: lh          $t9, 0x18($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X18);
    // 0x800AF928: nop

    // 0x800AF92C: sh          $t9, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r25;
    // 0x800AF930: lh          $t0, 0x22($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X22);
    // 0x800AF934: nop

    // 0x800AF938: sh          $t0, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r8;
    // 0x800AF93C: lh          $t1, 0x24($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X24);
    // 0x800AF940: nop

    // 0x800AF944: sh          $t1, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r9;
    // 0x800AF948: lh          $t2, 0x26($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X26);
    // 0x800AF94C: nop

    // 0x800AF950: sh          $t2, 0x16($s0)
    MEM_H(0X16, ctx->r16) = ctx->r10;
L_800AF954:
    // 0x800AF954: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800AF958: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800AF95C: jr          $ra
    // 0x800AF960: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800AF960: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void scroll_particle_textures(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF964: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800AF968: addiu       $t0, $t0, 0x33B8
    ctx->r8 = ADD32(ctx->r8, 0X33B8);
    // 0x800AF96C: lh          $t6, 0x0($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X0);
    // 0x800AF970: sll         $t7, $a0, 6
    ctx->r15 = S32(ctx->r4 << 6);
    // 0x800AF974: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800AF978: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x800AF97C: sh          $t9, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r25;
    // 0x800AF980: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800AF984: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800AF988: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AF98C: lh          $v0, 0x0($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X0);
    // 0x800AF990: addiu       $v1, $v1, 0x32E8
    ctx->r3 = ADD32(ctx->r3, 0X32E8);
    // 0x800AF994: addiu       $a3, $a3, 0x32E8
    ctx->r7 = ADD32(ctx->r7, 0X32E8);
    // 0x800AF998: addiu       $a2, $a2, 0x3298
    ctx->r6 = ADD32(ctx->r6, 0X3298);
L_800AF99C:
    // 0x800AF99C: lh          $t1, 0x0($a3)
    ctx->r9 = MEM_H(ctx->r7, 0X0);
    // 0x800AF9A0: lh          $t3, 0x2($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X2);
    // 0x800AF9A4: lh          $t5, 0x4($a3)
    ctx->r13 = MEM_H(ctx->r7, 0X4);
    // 0x800AF9A8: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x800AF9AC: sltu        $at, $a2, $v1
    ctx->r1 = ctx->r6 < ctx->r3 ? 1 : 0;
    // 0x800AF9B0: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x800AF9B4: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x800AF9B8: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800AF9BC: sh          $t2, -0xA($a2)
    MEM_H(-0XA, ctx->r6) = ctx->r10;
    // 0x800AF9C0: sh          $t4, -0x6($a2)
    MEM_H(-0X6, ctx->r6) = ctx->r12;
    // 0x800AF9C4: sh          $t6, -0x2($a2)
    MEM_H(-0X2, ctx->r6) = ctx->r14;
    // 0x800AF9C8: bne         $at, $zero, L_800AF99C
    if (ctx->r1 != 0) {
        // 0x800AF9CC: addiu       $a3, $a3, 0x6
        ctx->r7 = ADD32(ctx->r7, 0X6);
            goto L_800AF99C;
    }
    // 0x800AF9CC: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    // 0x800AF9D0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AF9D4: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800AF9D8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AF9DC: addiu       $v1, $v1, 0x3388
    ctx->r3 = ADD32(ctx->r3, 0X3388);
    // 0x800AF9E0: addiu       $a2, $a2, 0x3388
    ctx->r6 = ADD32(ctx->r6, 0X3388);
    // 0x800AF9E4: addiu       $a0, $a0, 0x3308
    ctx->r4 = ADD32(ctx->r4, 0X3308);
L_800AF9E8:
    // 0x800AF9E8: lh          $t7, 0x0($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X0);
    // 0x800AF9EC: lh          $t9, 0x2($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X2);
    // 0x800AF9F0: lh          $t2, 0x4($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X4);
    // 0x800AF9F4: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800AF9F8: addu        $t1, $t9, $v0
    ctx->r9 = ADD32(ctx->r25, ctx->r2);
    // 0x800AF9FC: sh          $t8, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r24;
    // 0x800AFA00: sh          $t1, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r9;
    // 0x800AFA04: lh          $t1, 0xC($a2)
    ctx->r9 = MEM_H(ctx->r6, 0XC);
    // 0x800AFA08: lh          $t8, 0xA($a2)
    ctx->r24 = MEM_H(ctx->r6, 0XA);
    // 0x800AFA0C: lh          $t4, 0x6($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X6);
    // 0x800AFA10: lh          $t6, 0x8($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X8);
    // 0x800AFA14: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x800AFA18: sh          $t3, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r11;
    // 0x800AFA1C: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x800AFA20: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800AFA24: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800AFA28: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800AFA2C: lh          $t3, 0xE($a2)
    ctx->r11 = MEM_H(ctx->r6, 0XE);
    // 0x800AFA30: sh          $t7, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r15;
    // 0x800AFA34: sh          $t5, 0x16($a0)
    MEM_H(0X16, ctx->r4) = ctx->r13;
    // 0x800AFA38: sh          $t9, 0x1E($a0)
    MEM_H(0X1E, ctx->r4) = ctx->r25;
    // 0x800AFA3C: sh          $t2, 0x26($a0)
    MEM_H(0X26, ctx->r4) = ctx->r10;
    // 0x800AFA40: lh          $t2, 0x16($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X16);
    // 0x800AFA44: lh          $t9, 0x14($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X14);
    // 0x800AFA48: lh          $t5, 0x10($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X10);
    // 0x800AFA4C: lh          $t7, 0x12($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X12);
    // 0x800AFA50: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x800AFA54: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    // 0x800AFA58: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x800AFA5C: addu        $t1, $t9, $v0
    ctx->r9 = ADD32(ctx->r25, ctx->r2);
    // 0x800AFA60: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800AFA64: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800AFA68: sh          $t8, -0xA($a0)
    MEM_H(-0XA, ctx->r4) = ctx->r24;
    // 0x800AFA6C: sh          $t6, -0x12($a0)
    MEM_H(-0X12, ctx->r4) = ctx->r14;
    // 0x800AFA70: sh          $t1, -0x6($a0)
    MEM_H(-0X6, ctx->r4) = ctx->r9;
    // 0x800AFA74: sh          $t3, -0x2($a0)
    MEM_H(-0X2, ctx->r4) = ctx->r11;
    // 0x800AFA78: sh          $t4, -0x16($a0)
    MEM_H(-0X16, ctx->r4) = ctx->r12;
    // 0x800AFA7C: bne         $a0, $v1, L_800AF9E8
    if (ctx->r4 != ctx->r3) {
        // 0x800AFA80: addiu       $a2, $a2, 0x18
        ctx->r6 = ADD32(ctx->r6, 0X18);
            goto L_800AF9E8;
    }
    // 0x800AFA80: addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
    // 0x800AFA84: jr          $ra
    // 0x800AFA88: nop

    return;
    // 0x800AFA88: nop

;}
RECOMP_FUNC void obj_enable_emitter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AFA8C: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x800AFA90: sll         $t7, $a1, 5
    ctx->r15 = S32(ctx->r5 << 5);
    // 0x800AFA94: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800AFA98: lh          $a2, 0x4($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X4);
    // 0x800AFA9C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800AFAA0: andi        $t8, $a2, 0x4000
    ctx->r24 = ctx->r6 & 0X4000;
    // 0x800AFAA4: beq         $t8, $zero, L_800AFAD0
    if (ctx->r24 == 0) {
        // 0x800AFAA8: sh          $zero, 0xA($v0)
        MEM_H(0XA, ctx->r2) = 0;
            goto L_800AFAD0;
    }
    // 0x800AFAA8: sh          $zero, 0xA($v0)
    MEM_H(0XA, ctx->r2) = 0;
    // 0x800AFAAC: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800AFAB0: nop

    // 0x800AFAB4: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x800AFAB8: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800AFABC: nop

    // 0x800AFAC0: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
    // 0x800AFAC4: lwc1        $f8, 0x14($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800AFAC8: b           L_800AFC10
    // 0x800AFACC: swc1        $f8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f8.u32l;
        goto L_800AFC10;
    // 0x800AFACC: swc1        $f8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f8.u32l;
L_800AFAD0:
    // 0x800AFAD0: andi        $t9, $a2, 0x400
    ctx->r25 = ctx->r6 & 0X400;
    // 0x800AFAD4: beq         $t9, $zero, L_800AFB98
    if (ctx->r25 == 0) {
        // 0x800AFAD8: lui         $t0, 0x800E
        ctx->r8 = S32(0X800E << 16);
            goto L_800AFB98;
    }
    // 0x800AFAD8: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800AFADC: lh          $t1, 0x8($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X8);
    // 0x800AFAE0: lw          $t0, 0x3280($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X3280);
    // 0x800AFAE4: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800AFAE8: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x800AFAEC: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x800AFAF0: lbu         $a1, 0x6($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X6);
    // 0x800AFAF4: lbu         $t5, 0x17($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X17);
    // 0x800AFAF8: nop

    // 0x800AFAFC: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x800AFB00: blez        $a1, L_800AFB40
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800AFB04: sh          $t6, 0xA($v0)
        MEM_H(0XA, ctx->r2) = ctx->r14;
            goto L_800AFB40;
    }
    // 0x800AFB04: sh          $t6, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r14;
    // 0x800AFB08: blez        $a1, L_800AFB40
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800AFB0C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800AFB40;
    }
    // 0x800AFB0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800AFB10: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_800AFB14:
    // 0x800AFB14: lw          $t7, 0xC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XC);
    // 0x800AFB18: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800AFB1C: addu        $t8, $t7, $a3
    ctx->r24 = ADD32(ctx->r15, ctx->r7);
    // 0x800AFB20: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    // 0x800AFB24: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800AFB28: sh          $zero, 0x3A($a1)
    MEM_H(0X3A, ctx->r5) = 0;
    // 0x800AFB2C: lbu         $t9, 0x6($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X6);
    // 0x800AFB30: nop

    // 0x800AFB34: slt         $at, $a2, $t9
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800AFB38: bne         $at, $zero, L_800AFB14
    if (ctx->r1 != 0) {
        // 0x800AFB3C: nop
    
            goto L_800AFB14;
    }
    // 0x800AFB3C: nop

L_800AFB40:
    // 0x800AFB40: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x800AFB44: nop

    // 0x800AFB48: andi        $t1, $a1, 0x1
    ctx->r9 = ctx->r5 & 0X1;
    // 0x800AFB4C: beq         $t1, $zero, L_800AFB78
    if (ctx->r9 == 0) {
        // 0x800AFB50: andi        $t3, $a1, 0x4
        ctx->r11 = ctx->r5 & 0X4;
            goto L_800AFB78;
    }
    // 0x800AFB50: andi        $t3, $a1, 0x4
    ctx->r11 = ctx->r5 & 0X4;
    // 0x800AFB54: lh          $t0, 0x14($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X14);
    // 0x800AFB58: nop

    // 0x800AFB5C: sh          $t0, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r8;
    // 0x800AFB60: lh          $t2, 0x16($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X16);
    // 0x800AFB64: nop

    // 0x800AFB68: sh          $t2, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r10;
    // 0x800AFB6C: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x800AFB70: nop

    // 0x800AFB74: andi        $t3, $a1, 0x4
    ctx->r11 = ctx->r5 & 0X4;
L_800AFB78:
    // 0x800AFB78: beq         $t3, $zero, L_800AFC10
    if (ctx->r11 == 0) {
        // 0x800AFB7C: nop
    
            goto L_800AFC10;
    }
    // 0x800AFB7C: nop

    // 0x800AFB80: lh          $t4, 0x22($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X22);
    // 0x800AFB84: nop

    // 0x800AFB88: sh          $t4, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r12;
    // 0x800AFB8C: lh          $t5, 0x24($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X24);
    // 0x800AFB90: b           L_800AFC10
    // 0x800AFB94: sh          $t5, 0x16($v0)
    MEM_H(0X16, ctx->r2) = ctx->r13;
        goto L_800AFC10;
    // 0x800AFB94: sh          $t5, 0x16($v0)
    MEM_H(0X16, ctx->r2) = ctx->r13;
L_800AFB98:
    // 0x800AFB98: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x800AFB9C: nop

    // 0x800AFBA0: andi        $t6, $a1, 0x1
    ctx->r14 = ctx->r5 & 0X1;
    // 0x800AFBA4: beq         $t6, $zero, L_800AFBE0
    if (ctx->r14 == 0) {
        // 0x800AFBA8: andi        $t1, $a1, 0x4
        ctx->r9 = ctx->r5 & 0X4;
            goto L_800AFBE0;
    }
    // 0x800AFBA8: andi        $t1, $a1, 0x4
    ctx->r9 = ctx->r5 & 0X4;
    // 0x800AFBAC: sb          $zero, 0x6($v0)
    MEM_B(0X6, ctx->r2) = 0;
    // 0x800AFBB0: lh          $t7, 0x14($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X14);
    // 0x800AFBB4: nop

    // 0x800AFBB8: sh          $t7, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r15;
    // 0x800AFBBC: lh          $t8, 0x16($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X16);
    // 0x800AFBC0: nop

    // 0x800AFBC4: sh          $t8, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r24;
    // 0x800AFBC8: lh          $t9, 0x18($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X18);
    // 0x800AFBCC: nop

    // 0x800AFBD0: sh          $t9, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r25;
    // 0x800AFBD4: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x800AFBD8: nop

    // 0x800AFBDC: andi        $t1, $a1, 0x4
    ctx->r9 = ctx->r5 & 0X4;
L_800AFBE0:
    // 0x800AFBE0: beq         $t1, $zero, L_800AFC10
    if (ctx->r9 == 0) {
        // 0x800AFBE4: nop
    
            goto L_800AFC10;
    }
    // 0x800AFBE4: nop

    // 0x800AFBE8: sb          $zero, 0x7($v0)
    MEM_B(0X7, ctx->r2) = 0;
    // 0x800AFBEC: lh          $t0, 0x22($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X22);
    // 0x800AFBF0: nop

    // 0x800AFBF4: sh          $t0, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r8;
    // 0x800AFBF8: lh          $t2, 0x24($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X24);
    // 0x800AFBFC: nop

    // 0x800AFC00: sh          $t2, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r10;
    // 0x800AFC04: lh          $t3, 0x26($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X26);
    // 0x800AFC08: nop

    // 0x800AFC0C: sh          $t3, 0x16($v0)
    MEM_H(0X16, ctx->r2) = ctx->r11;
L_800AFC10:
    // 0x800AFC10: lh          $t4, 0x4($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X4);
    // 0x800AFC14: nop

    // 0x800AFC18: andi        $t5, $t4, 0xFDFF
    ctx->r13 = ctx->r12 & 0XFDFF;
    // 0x800AFC1C: sh          $t5, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r13;
    // 0x800AFC20: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x800AFC24: nop

    // 0x800AFC28: ori         $t7, $t6, 0xA000
    ctx->r15 = ctx->r14 | 0XA000;
    // 0x800AFC2C: sh          $t7, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r15;
    // 0x800AFC30: lh          $t8, 0x1A($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X1A);
    // 0x800AFC34: nop

    // 0x800AFC38: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800AFC3C: jr          $ra
    // 0x800AFC40: sh          $t9, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r25;
    return;
    // 0x800AFC40: sh          $t9, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r25;
;}
RECOMP_FUNC void obj_disable_emitter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AFC44: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x800AFC48: sll         $t7, $a1, 5
    ctx->r15 = S32(ctx->r5 << 5);
    // 0x800AFC4C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800AFC50: lh          $t8, 0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4);
    // 0x800AFC54: nop

    // 0x800AFC58: andi        $t9, $t8, 0x7FFF
    ctx->r25 = ctx->r24 & 0X7FFF;
    // 0x800AFC5C: sh          $t9, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r25;
    // 0x800AFC60: lh          $t0, 0x1A($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X1A);
    // 0x800AFC64: nop

    // 0x800AFC68: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x800AFC6C: jr          $ra
    // 0x800AFC70: sh          $t1, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r9;
    return;
    // 0x800AFC70: sh          $t1, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void update_vehicle_particles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AFC74: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x800AFC78: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800AFC7C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800AFC80: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800AFC84: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800AFC88: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800AFC8C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800AFC90: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800AFC94: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800AFC98: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800AFC9C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800AFCA0: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x800AFCA4: lw          $s3, 0x64($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X64);
    // 0x800AFCA8: lw          $s7, 0x74($a0)
    ctx->r23 = MEM_W(ctx->r4, 0X74);
    // 0x800AFCAC: lb          $fp, 0x1D6($s3)
    ctx->r30 = MEM_B(ctx->r19, 0X1D6);
    // 0x800AFCB0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800AFCB4: jal         0x80012E28
    // 0x800AFCB8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    object_do_player_tumble(rdram, ctx);
        goto after_0;
    // 0x800AFCB8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_0:
    // 0x800AFCBC: lw          $t6, 0x40($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X40);
    // 0x800AFCC0: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x800AFCC4: lb          $t7, 0x57($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X57);
    // 0x800AFCC8: addiu       $s5, $zero, 0xFF
    ctx->r21 = ADD32(0, 0XFF);
    // 0x800AFCCC: blez        $t7, L_800B0164
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800AFCD0: lui         $s4, 0x800E
        ctx->r20 = S32(0X800E << 16);
            goto L_800B0164;
    }
    // 0x800AFCD0: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x800AFCD4: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x800AFCD8: addiu       $s1, $s1, 0x3290
    ctx->r17 = ADD32(ctx->r17, 0X3290);
    // 0x800AFCDC: addiu       $s4, $s4, 0x3414
    ctx->r20 = ADD32(ctx->r20, 0X3414);
L_800AFCE0:
    // 0x800AFCE0: andi        $t8, $s7, 0x1
    ctx->r24 = ctx->r23 & 0X1;
    // 0x800AFCE4: beq         $t8, $zero, L_800B0088
    if (ctx->r24 == 0) {
        // 0x800AFCE8: nop
    
            goto L_800B0088;
    }
    // 0x800AFCE8: nop

    // 0x800AFCEC: beq         $fp, $zero, L_800AFD10
    if (ctx->r30 == 0) {
        // 0x800AFCF0: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_800AFD10;
    }
    // 0x800AFCF0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800AFCF4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800AFCF8: beq         $fp, $at, L_800AFF60
    if (ctx->r30 == ctx->r1) {
        // 0x800AFCFC: nop
    
            goto L_800AFF60;
    }
    // 0x800AFCFC: nop

    // 0x800AFD00: beq         $fp, $s6, L_800AFF10
    if (ctx->r30 == ctx->r22) {
        // 0x800AFD04: nop
    
            goto L_800AFF10;
    }
    // 0x800AFD04: nop

    // 0x800AFD08: b           L_800AFFB4
    // 0x800AFD0C: nop

        goto L_800AFFB4;
    // 0x800AFD0C: nop

L_800AFD10:
    // 0x800AFD10: bltz        $s0, L_800AFE44
    if (SIGNED(ctx->r16) < 0) {
        // 0x800AFD14: slti        $at, $s0, 0xA
        ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
            goto L_800AFE44;
    }
    // 0x800AFD14: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x800AFD18: beq         $at, $zero, L_800AFE48
    if (ctx->r1 == 0) {
        // 0x800AFD1C: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_800AFE48;
    }
    // 0x800AFD1C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800AFD20: lh          $v0, 0x16E($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X16E);
    // 0x800AFD24: sll         $t4, $s0, 5
    ctx->r12 = S32(ctx->r16 << 5);
    // 0x800AFD28: bgez        $v0, L_800AFD34
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800AFD2C: lui         $t8, 0x800E
        ctx->r24 = S32(0X800E << 16);
            goto L_800AFD34;
    }
    // 0x800AFD2C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800AFD30: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_800AFD34:
    // 0x800AFD34: addiu       $v0, $v0, -0x18
    ctx->r2 = ADD32(ctx->r2, -0X18);
    // 0x800AFD38: blez        $v0, L_800AFFB4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800AFD3C: slti        $at, $v0, 0x21
        ctx->r1 = SIGNED(ctx->r2) < 0X21 ? 1 : 0;
            goto L_800AFFB4;
    }
    // 0x800AFD3C: slti        $at, $v0, 0x21
    ctx->r1 = SIGNED(ctx->r2) < 0X21 ? 1 : 0;
    // 0x800AFD40: lw          $t9, 0x6C($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X6C);
    // 0x800AFD44: lw          $t8, 0x3280($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X3280);
    // 0x800AFD48: addu        $t5, $t9, $t4
    ctx->r13 = ADD32(ctx->r25, ctx->r12);
    // 0x800AFD4C: lh          $t6, 0x8($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X8);
    // 0x800AFD50: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800AFD54: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800AFD58: addiu       $t5, $t5, 0x3454
    ctx->r13 = ADD32(ctx->r13, 0X3454);
    // 0x800AFD5C: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x800AFD60: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x800AFD64: lw          $a3, 0x0($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X0);
    // 0x800AFD68: addu        $t0, $t4, $t5
    ctx->r8 = ADD32(ctx->r12, ctx->r13);
    // 0x800AFD6C: bne         $at, $zero, L_800AFD78
    if (ctx->r1 != 0) {
        // 0x800AFD70: addiu       $t2, $t0, 0x3
        ctx->r10 = ADD32(ctx->r8, 0X3);
            goto L_800AFD78;
    }
    // 0x800AFD70: addiu       $t2, $t0, 0x3
    ctx->r10 = ADD32(ctx->r8, 0X3);
    // 0x800AFD74: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
L_800AFD78:
    // 0x800AFD78: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AFD7C: lbu         $a0, 0x14($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X14);
    // 0x800AFD80: lbu         $t7, 0x0($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X0);
    // 0x800AFD84: sll         $t1, $v0, 4
    ctx->r9 = S32(ctx->r2 << 4);
    // 0x800AFD88: subu        $t9, $t7, $a0
    ctx->r25 = SUB32(ctx->r15, ctx->r4);
    // 0x800AFD8C: slti        $at, $v0, 0x11
    ctx->r1 = SIGNED(ctx->r2) < 0X11 ? 1 : 0;
    // 0x800AFD90: mflo        $t6
    ctx->r14 = lo;
    // 0x800AFD94: sra         $t8, $t6, 2
    ctx->r24 = S32(SIGNED(ctx->r14) >> 2);
    // 0x800AFD98: subu        $v1, $t1, $t8
    ctx->r3 = SUB32(ctx->r9, ctx->r24);
    // 0x800AFD9C: multu       $t9, $v1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AFDA0: lbu         $t9, 0x1($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X1);
    // 0x800AFDA4: mflo        $t4
    ctx->r12 = lo;
    // 0x800AFDA8: sra         $t5, $t4, 8
    ctx->r13 = S32(SIGNED(ctx->r12) >> 8);
    // 0x800AFDAC: addu        $t6, $t5, $a0
    ctx->r14 = ADD32(ctx->r13, ctx->r4);
    // 0x800AFDB0: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x800AFDB4: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800AFDB8: lbu         $a1, 0x15($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X15);
    // 0x800AFDBC: nop

    // 0x800AFDC0: subu        $t4, $t9, $a1
    ctx->r12 = SUB32(ctx->r25, ctx->r5);
    // 0x800AFDC4: multu       $t4, $v1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AFDC8: mflo        $t5
    ctx->r13 = lo;
    // 0x800AFDCC: sra         $t6, $t5, 8
    ctx->r14 = S32(SIGNED(ctx->r13) >> 8);
    // 0x800AFDD0: addu        $t8, $a1, $t6
    ctx->r24 = ADD32(ctx->r5, ctx->r14);
    // 0x800AFDD4: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800AFDD8: or          $t5, $t7, $t9
    ctx->r13 = ctx->r15 | ctx->r25;
    // 0x800AFDDC: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x800AFDE0: lbu         $a2, 0x16($a3)
    ctx->r6 = MEM_BU(ctx->r7, 0X16);
    // 0x800AFDE4: lbu         $t6, 0x2($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X2);
    // 0x800AFDE8: nop

    // 0x800AFDEC: subu        $t8, $t6, $a2
    ctx->r24 = SUB32(ctx->r14, ctx->r6);
    // 0x800AFDF0: multu       $t8, $v1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AFDF4: mflo        $t7
    ctx->r15 = lo;
    // 0x800AFDF8: sra         $t9, $t7, 8
    ctx->r25 = S32(SIGNED(ctx->r15) >> 8);
    // 0x800AFDFC: addu        $t4, $a2, $t9
    ctx->r12 = ADD32(ctx->r6, ctx->r25);
    // 0x800AFE00: sll         $t6, $t4, 8
    ctx->r14 = S32(ctx->r12 << 8);
    // 0x800AFE04: or          $t8, $t5, $t6
    ctx->r24 = ctx->r13 | ctx->r14;
    // 0x800AFE08: bne         $at, $zero, L_800AFE14
    if (ctx->r1 != 0) {
        // 0x800AFE0C: sw          $t8, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r24;
            goto L_800AFE14;
    }
    // 0x800AFE0C: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800AFE10: addiu       $t1, $zero, 0x100
    ctx->r9 = ADD32(0, 0X100);
L_800AFE14:
    // 0x800AFE14: lbu         $v0, 0x17($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X17);
    // 0x800AFE18: lbu         $t9, 0x0($t2)
    ctx->r25 = MEM_BU(ctx->r10, 0X0);
    // 0x800AFE1C: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800AFE20: subu        $t4, $t9, $v0
    ctx->r12 = SUB32(ctx->r25, ctx->r2);
    // 0x800AFE24: multu       $t4, $t1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AFE28: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AFE2C: mflo        $t5
    ctx->r13 = lo;
    // 0x800AFE30: sra         $t6, $t5, 8
    ctx->r14 = S32(SIGNED(ctx->r13) >> 8);
    // 0x800AFE34: addu        $t8, $v0, $t6
    ctx->r24 = ADD32(ctx->r2, ctx->r14);
    // 0x800AFE38: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x800AFE3C: b           L_800AFFB4
    // 0x800AFE40: sw          $t9, 0x3290($at)
    MEM_W(0X3290, ctx->r1) = ctx->r25;
        goto L_800AFFB4;
    // 0x800AFE40: sw          $t9, 0x3290($at)
    MEM_W(0X3290, ctx->r1) = ctx->r25;
L_800AFE44:
    // 0x800AFE44: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
L_800AFE48:
    // 0x800AFE48: beq         $s0, $at, L_800AFE70
    if (ctx->r16 == ctx->r1) {
        // 0x800AFE4C: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_800AFE70;
    }
    // 0x800AFE4C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x800AFE50: beq         $s0, $at, L_800AFE98
    if (ctx->r16 == ctx->r1) {
        // 0x800AFE54: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_800AFE98;
    }
    // 0x800AFE54: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x800AFE58: beq         $s0, $at, L_800AFEC0
    if (ctx->r16 == ctx->r1) {
        // 0x800AFE5C: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_800AFEC0;
    }
    // 0x800AFE5C: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x800AFE60: beq         $s0, $at, L_800AFEE8
    if (ctx->r16 == ctx->r1) {
        // 0x800AFE64: nop
    
            goto L_800AFEE8;
    }
    // 0x800AFE64: nop

    // 0x800AFE68: b           L_800AFFB4
    // 0x800AFE6C: nop

        goto L_800AFFB4;
    // 0x800AFE6C: nop

L_800AFE70:
    // 0x800AFE70: lbu         $v0, 0x1DE($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X1DE);
    // 0x800AFE74: nop

    // 0x800AFE78: bne         $s5, $v0, L_800AFE84
    if (ctx->r21 != ctx->r2) {
        // 0x800AFE7C: andi        $t4, $v0, 0xF
        ctx->r12 = ctx->r2 & 0XF;
            goto L_800AFE84;
    }
    // 0x800AFE7C: andi        $t4, $v0, 0xF
    ctx->r12 = ctx->r2 & 0XF;
    // 0x800AFE80: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
L_800AFE84:
    // 0x800AFE84: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800AFE88: addu        $t6, $s4, $t5
    ctx->r14 = ADD32(ctx->r20, ctx->r13);
    // 0x800AFE8C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800AFE90: b           L_800AFFB4
    // 0x800AFE94: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
        goto L_800AFFB4;
    // 0x800AFE94: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
L_800AFE98:
    // 0x800AFE98: lbu         $v0, 0x1DF($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X1DF);
    // 0x800AFE9C: nop

    // 0x800AFEA0: bne         $s5, $v0, L_800AFEAC
    if (ctx->r21 != ctx->r2) {
        // 0x800AFEA4: andi        $t8, $v0, 0xF
        ctx->r24 = ctx->r2 & 0XF;
            goto L_800AFEAC;
    }
    // 0x800AFEA4: andi        $t8, $v0, 0xF
    ctx->r24 = ctx->r2 & 0XF;
    // 0x800AFEA8: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
L_800AFEAC:
    // 0x800AFEAC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800AFEB0: addu        $t4, $s4, $t9
    ctx->r12 = ADD32(ctx->r20, ctx->r25);
    // 0x800AFEB4: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800AFEB8: b           L_800AFFB4
    // 0x800AFEBC: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
        goto L_800AFFB4;
    // 0x800AFEBC: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
L_800AFEC0:
    // 0x800AFEC0: lbu         $v0, 0x1DC($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X1DC);
    // 0x800AFEC4: nop

    // 0x800AFEC8: bne         $s5, $v0, L_800AFED4
    if (ctx->r21 != ctx->r2) {
        // 0x800AFECC: andi        $t6, $v0, 0xF
        ctx->r14 = ctx->r2 & 0XF;
            goto L_800AFED4;
    }
    // 0x800AFECC: andi        $t6, $v0, 0xF
    ctx->r14 = ctx->r2 & 0XF;
    // 0x800AFED0: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
L_800AFED4:
    // 0x800AFED4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800AFED8: addu        $t8, $s4, $t7
    ctx->r24 = ADD32(ctx->r20, ctx->r15);
    // 0x800AFEDC: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800AFEE0: b           L_800AFFB4
    // 0x800AFEE4: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
        goto L_800AFFB4;
    // 0x800AFEE4: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
L_800AFEE8:
    // 0x800AFEE8: lbu         $v0, 0x1DD($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X1DD);
    // 0x800AFEEC: nop

    // 0x800AFEF0: bne         $s5, $v0, L_800AFEFC
    if (ctx->r21 != ctx->r2) {
        // 0x800AFEF4: andi        $t4, $v0, 0xF
        ctx->r12 = ctx->r2 & 0XF;
            goto L_800AFEFC;
    }
    // 0x800AFEF4: andi        $t4, $v0, 0xF
    ctx->r12 = ctx->r2 & 0XF;
    // 0x800AFEF8: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
L_800AFEFC:
    // 0x800AFEFC: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800AFF00: addu        $t6, $s4, $t5
    ctx->r14 = ADD32(ctx->r20, ctx->r13);
    // 0x800AFF04: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800AFF08: b           L_800AFFB4
    // 0x800AFF0C: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
        goto L_800AFFB4;
    // 0x800AFF0C: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
L_800AFF10:
    // 0x800AFF10: bne         $s0, $zero, L_800AFF38
    if (ctx->r16 != 0) {
        // 0x800AFF14: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800AFF38;
    }
    // 0x800AFF14: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800AFF18: lbu         $t8, 0x1DC($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X1DC);
    // 0x800AFF1C: nop

    // 0x800AFF20: andi        $t9, $t8, 0xF
    ctx->r25 = ctx->r24 & 0XF;
    // 0x800AFF24: sll         $t4, $t9, 2
    ctx->r12 = S32(ctx->r25 << 2);
    // 0x800AFF28: addu        $t5, $s4, $t4
    ctx->r13 = ADD32(ctx->r20, ctx->r12);
    // 0x800AFF2C: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800AFF30: b           L_800AFFB4
    // 0x800AFF34: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
        goto L_800AFFB4;
    // 0x800AFF34: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
L_800AFF38:
    // 0x800AFF38: bne         $s0, $at, L_800AFFB4
    if (ctx->r16 != ctx->r1) {
        // 0x800AFF3C: nop
    
            goto L_800AFFB4;
    }
    // 0x800AFF3C: nop

    // 0x800AFF40: lbu         $t7, 0x1DD($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X1DD);
    // 0x800AFF44: nop

    // 0x800AFF48: andi        $t8, $t7, 0xF
    ctx->r24 = ctx->r15 & 0XF;
    // 0x800AFF4C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800AFF50: addu        $t4, $s4, $t9
    ctx->r12 = ADD32(ctx->r20, ctx->r25);
    // 0x800AFF54: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800AFF58: b           L_800AFFB4
    // 0x800AFF5C: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
        goto L_800AFFB4;
    // 0x800AFF5C: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
L_800AFF60:
    // 0x800AFF60: beq         $s0, $s6, L_800AFF70
    if (ctx->r16 == ctx->r22) {
        // 0x800AFF64: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800AFF70;
    }
    // 0x800AFF64: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800AFF68: bne         $s0, $at, L_800AFFB4
    if (ctx->r16 != ctx->r1) {
        // 0x800AFF6C: nop
    
            goto L_800AFFB4;
    }
    // 0x800AFF6C: nop

L_800AFF70:
    // 0x800AFF70: lb          $t6, 0x2($s3)
    ctx->r14 = MEM_B(ctx->r19, 0X2);
    // 0x800AFF74: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800AFF78: andi        $t7, $t6, 0x7
    ctx->r15 = ctx->r14 & 0X7;
    // 0x800AFF7C: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800AFF80: addiu       $t9, $t9, -0x7DB8
    ctx->r25 = ADD32(ctx->r25, -0X7DB8);
    // 0x800AFF84: lw          $t4, 0x84($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X84);
    // 0x800AFF88: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x800AFF8C: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x800AFF90: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800AFF94: addu        $v0, $v0, $t5
    ctx->r2 = ADD32(ctx->r2, ctx->r13);
    // 0x800AFF98: slti        $at, $v0, 0x101
    ctx->r1 = SIGNED(ctx->r2) < 0X101 ? 1 : 0;
    // 0x800AFF9C: bne         $at, $zero, L_800AFFA8
    if (ctx->r1 != 0) {
        // 0x800AFFA0: nop
    
            goto L_800AFFA8;
    }
    // 0x800AFFA0: nop

    // 0x800AFFA4: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
L_800AFFA8:
    // 0x800AFFA8: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x800AFFAC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AFFB0: sw          $v0, 0x347C($at)
    MEM_W(0X347C, ctx->r1) = ctx->r2;
L_800AFFB4:
    // 0x800AFFB4: beq         $t3, $zero, L_800B0138
    if (ctx->r11 == 0) {
        // 0x800AFFB8: nop
    
            goto L_800B0138;
    }
    // 0x800AFFB8: nop

    // 0x800AFFBC: lw          $a2, 0x6C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X6C);
    // 0x800AFFC0: sll         $a3, $s0, 5
    ctx->r7 = S32(ctx->r16 << 5);
    // 0x800AFFC4: addu        $v0, $a2, $a3
    ctx->r2 = ADD32(ctx->r6, ctx->r7);
    // 0x800AFFC8: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x800AFFCC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800AFFD0: andi        $t6, $v1, 0x8000
    ctx->r14 = ctx->r3 & 0X8000;
    // 0x800AFFD4: bne         $t6, $zero, L_800AFFFC
    if (ctx->r14 != 0) {
        // 0x800AFFD8: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_800AFFFC;
    }
    // 0x800AFFD8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800AFFDC: jal         0x800AFA8C
    // 0x800AFFE0: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    obj_enable_emitter(rdram, ctx);
        goto after_1;
    // 0x800AFFE0: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    after_1:
    // 0x800AFFE4: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x800AFFE8: lw          $a2, 0x6C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X6C);
    // 0x800AFFEC: nop

    // 0x800AFFF0: addu        $v0, $a2, $a3
    ctx->r2 = ADD32(ctx->r6, ctx->r7);
    // 0x800AFFF4: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x800AFFF8: nop

L_800AFFFC:
    // 0x800AFFFC: andi        $t7, $v1, 0x4000
    ctx->r15 = ctx->r3 & 0X4000;
    // 0x800B0000: beq         $t7, $zero, L_800B0020
    if (ctx->r15 == 0) {
        // 0x800B0004: andi        $t9, $v1, 0x400
        ctx->r25 = ctx->r3 & 0X400;
            goto L_800B0020;
    }
    // 0x800B0004: andi        $t9, $v1, 0x400
    ctx->r25 = ctx->r3 & 0X400;
    // 0x800B0008: sll         $t8, $s0, 5
    ctx->r24 = S32(ctx->r16 << 5);
    // 0x800B000C: addu        $a1, $a2, $t8
    ctx->r5 = ADD32(ctx->r6, ctx->r24);
    // 0x800B0010: jal         0x800B03BC
    // 0x800B0014: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    obj_trigger_emitter(rdram, ctx);
        goto after_2;
    // 0x800B0014: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x800B0018: b           L_800B013C
    // 0x800B001C: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
        goto L_800B013C;
    // 0x800B001C: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
L_800B0020:
    // 0x800B0020: beq         $t9, $zero, L_800B003C
    if (ctx->r25 == 0) {
        // 0x800B0024: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800B003C;
    }
    // 0x800B0024: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B0028: sll         $t4, $s0, 5
    ctx->r12 = S32(ctx->r16 << 5);
    // 0x800B002C: jal         0x800B03BC
    // 0x800B0030: addu        $a1, $a2, $t4
    ctx->r5 = ADD32(ctx->r6, ctx->r12);
    obj_trigger_emitter(rdram, ctx);
        goto after_3;
    // 0x800B0030: addu        $a1, $a2, $t4
    ctx->r5 = ADD32(ctx->r6, ctx->r12);
    after_3:
    // 0x800B0034: b           L_800B013C
    // 0x800B0038: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
        goto L_800B013C;
    // 0x800B0038: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
L_800B003C:
    // 0x800B003C: lh          $t5, 0xA($v0)
    ctx->r13 = MEM_H(ctx->r2, 0XA);
    // 0x800B0040: lw          $t6, 0x84($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X84);
    // 0x800B0044: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B0048: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800B004C: sh          $t7, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r15;
    // 0x800B0050: lw          $a2, 0x6C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X6C);
    // 0x800B0054: sll         $t5, $s0, 5
    ctx->r13 = S32(ctx->r16 << 5);
    // 0x800B0058: addu        $v0, $a2, $a3
    ctx->r2 = ADD32(ctx->r6, ctx->r7);
    // 0x800B005C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800B0060: lh          $t8, 0xA($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XA);
    // 0x800B0064: lh          $t4, 0x40($t9)
    ctx->r12 = MEM_H(ctx->r25, 0X40);
    // 0x800B0068: nop

    // 0x800B006C: slt         $at, $t8, $t4
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800B0070: bne         $at, $zero, L_800B0138
    if (ctx->r1 != 0) {
        // 0x800B0074: nop
    
            goto L_800B0138;
    }
    // 0x800B0074: nop

    // 0x800B0078: jal         0x800B03BC
    // 0x800B007C: addu        $a1, $a2, $t5
    ctx->r5 = ADD32(ctx->r6, ctx->r13);
    obj_trigger_emitter(rdram, ctx);
        goto after_4;
    // 0x800B007C: addu        $a1, $a2, $t5
    ctx->r5 = ADD32(ctx->r6, ctx->r13);
    after_4:
    // 0x800B0080: b           L_800B013C
    // 0x800B0084: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
        goto L_800B013C;
    // 0x800B0084: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
L_800B0088:
    // 0x800B0088: lw          $a2, 0x6C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X6C);
    // 0x800B008C: sll         $t6, $s0, 5
    ctx->r14 = S32(ctx->r16 << 5);
    // 0x800B0090: addu        $v0, $a2, $t6
    ctx->r2 = ADD32(ctx->r6, ctx->r14);
    // 0x800B0094: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x800B0098: nop

    // 0x800B009C: andi        $t7, $v1, 0x8000
    ctx->r15 = ctx->r3 & 0X8000;
    // 0x800B00A0: beq         $t7, $zero, L_800B0138
    if (ctx->r15 == 0) {
        // 0x800B00A4: andi        $t9, $v1, 0x4000
        ctx->r25 = ctx->r3 & 0X4000;
            goto L_800B0138;
    }
    // 0x800B00A4: andi        $t9, $v1, 0x4000
    ctx->r25 = ctx->r3 & 0X4000;
    // 0x800B00A8: beq         $t9, $zero, L_800B00D0
    if (ctx->r25 == 0) {
        // 0x800B00AC: andi        $t4, $v1, 0x400
        ctx->r12 = ctx->r3 & 0X400;
            goto L_800B00D0;
    }
    // 0x800B00AC: andi        $t4, $v1, 0x400
    ctx->r12 = ctx->r3 & 0X400;
    // 0x800B00B0: sll         $t8, $s0, 5
    ctx->r24 = S32(ctx->r16 << 5);
    // 0x800B00B4: addu        $v0, $a2, $t8
    ctx->r2 = ADD32(ctx->r6, ctx->r24);
    // 0x800B00B8: sb          $zero, 0x6($v0)
    MEM_B(0X6, ctx->r2) = 0;
    // 0x800B00BC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B00C0: jal         0x800AFC44
    // 0x800B00C4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    obj_disable_emitter(rdram, ctx);
        goto after_5;
    // 0x800B00C4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x800B00C8: b           L_800B0110
    // 0x800B00CC: nop

        goto L_800B0110;
    // 0x800B00CC: nop

L_800B00D0:
    // 0x800B00D0: beq         $t4, $zero, L_800B0108
    if (ctx->r12 == 0) {
        // 0x800B00D4: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800B0108;
    }
    // 0x800B00D4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B00D8: sll         $t5, $s0, 5
    ctx->r13 = S32(ctx->r16 << 5);
    // 0x800B00DC: ori         $t6, $v1, 0x200
    ctx->r14 = ctx->r3 | 0X200;
    // 0x800B00E0: addu        $a0, $a2, $t5
    ctx->r4 = ADD32(ctx->r6, ctx->r13);
    // 0x800B00E4: sh          $t6, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r14;
    // 0x800B00E8: lbu         $t7, 0x6($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X6);
    // 0x800B00EC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B00F0: bne         $t7, $zero, L_800B0110
    if (ctx->r15 != 0) {
        // 0x800B00F4: nop
    
            goto L_800B0110;
    }
    // 0x800B00F4: nop

    // 0x800B00F8: jal         0x800AFC44
    // 0x800B00FC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    obj_disable_emitter(rdram, ctx);
        goto after_6;
    // 0x800B00FC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x800B0100: b           L_800B0110
    // 0x800B0104: nop

        goto L_800B0110;
    // 0x800B0104: nop

L_800B0108:
    // 0x800B0108: jal         0x800AFC44
    // 0x800B010C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    obj_disable_emitter(rdram, ctx);
        goto after_7;
    // 0x800B010C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
L_800B0110:
    // 0x800B0110: beq         $s0, $s6, L_800B0120
    if (ctx->r16 == ctx->r22) {
        // 0x800B0114: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800B0120;
    }
    // 0x800B0114: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B0118: bne         $s0, $at, L_800B0138
    if (ctx->r16 != ctx->r1) {
        // 0x800B011C: nop
    
            goto L_800B0138;
    }
    // 0x800B011C: nop

L_800B0120:
    // 0x800B0120: lb          $t9, 0x2($s3)
    ctx->r25 = MEM_B(ctx->r19, 0X2);
    // 0x800B0124: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B0128: andi        $t8, $t9, 0x7
    ctx->r24 = ctx->r25 & 0X7;
    // 0x800B012C: sll         $t4, $t8, 1
    ctx->r12 = S32(ctx->r24 << 1);
    // 0x800B0130: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800B0134: sh          $zero, -0x7DB8($at)
    MEM_H(-0X7DB8, ctx->r1) = 0;
L_800B0138:
    // 0x800B0138: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
L_800B013C:
    // 0x800B013C: addiu       $t6, $zero, 0x100
    ctx->r14 = ADD32(0, 0X100);
    // 0x800B0140: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B0144: sw          $t6, 0x347C($at)
    MEM_W(0X347C, ctx->r1) = ctx->r14;
    // 0x800B0148: lw          $t7, 0x40($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X40);
    // 0x800B014C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B0150: lb          $t9, 0x57($t7)
    ctx->r25 = MEM_B(ctx->r15, 0X57);
    // 0x800B0154: srl         $t5, $s7, 1
    ctx->r13 = S32(U32(ctx->r23) >> 1);
    // 0x800B0158: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800B015C: bne         $at, $zero, L_800AFCE0
    if (ctx->r1 != 0) {
        // 0x800B0160: or          $s7, $t5, $zero
        ctx->r23 = ctx->r13 | 0;
            goto L_800AFCE0;
    }
    // 0x800B0160: or          $s7, $t5, $zero
    ctx->r23 = ctx->r13 | 0;
L_800B0164:
    // 0x800B0164: jal         0x80012F30
    // 0x800B0168: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    object_undo_player_tumble(rdram, ctx);
        goto after_8;
    // 0x800B0168: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_8:
    // 0x800B016C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800B0170: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B0174: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800B0178: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800B017C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800B0180: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800B0184: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800B0188: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800B018C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800B0190: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800B0194: jr          $ra
    // 0x800B0198: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x800B0198: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void obj_spawn_particle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B019C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800B01A0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800B01A4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800B01A8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800B01AC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800B01B0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800B01B4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800B01B8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800B01BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B01C0: lw          $t6, 0x40($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X40);
    // 0x800B01C4: lw          $s5, 0x74($a0)
    ctx->r21 = MEM_W(ctx->r4, 0X74);
    // 0x800B01C8: lb          $a3, 0x57($t6)
    ctx->r7 = MEM_B(ctx->r14, 0X57);
    // 0x800B01CC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800B01D0: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x800B01D4: blez        $a3, L_800B0394
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800B01D8: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800B0394;
    }
    // 0x800B01D8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800B01DC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_800B01E0:
    // 0x800B01E0: lw          $a2, 0x6C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X6C);
    // 0x800B01E4: andi        $t7, $s5, 0x1
    ctx->r15 = ctx->r21 & 0X1;
    // 0x800B01E8: beq         $t7, $zero, L_800B02B4
    if (ctx->r15 == 0) {
        // 0x800B01EC: addu        $v1, $a2, $s4
        ctx->r3 = ADD32(ctx->r6, ctx->r20);
            goto L_800B02B4;
    }
    // 0x800B01EC: addu        $v1, $a2, $s4
    ctx->r3 = ADD32(ctx->r6, ctx->r20);
    // 0x800B01F0: lh          $v0, 0x4($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X4);
    // 0x800B01F4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B01F8: andi        $t8, $v0, 0x8000
    ctx->r24 = ctx->r2 & 0X8000;
    // 0x800B01FC: bne         $t8, $zero, L_800B0224
    if (ctx->r24 != 0) {
        // 0x800B0200: andi        $t9, $v0, 0x4000
        ctx->r25 = ctx->r2 & 0X4000;
            goto L_800B0224;
    }
    // 0x800B0200: andi        $t9, $v0, 0x4000
    ctx->r25 = ctx->r2 & 0X4000;
    // 0x800B0204: jal         0x800AFA8C
    // 0x800B0208: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    obj_enable_emitter(rdram, ctx);
        goto after_0;
    // 0x800B0208: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_0:
    // 0x800B020C: lw          $a2, 0x6C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X6C);
    // 0x800B0210: nop

    // 0x800B0214: addu        $v1, $a2, $s4
    ctx->r3 = ADD32(ctx->r6, ctx->r20);
    // 0x800B0218: lh          $v0, 0x4($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X4);
    // 0x800B021C: nop

    // 0x800B0220: andi        $t9, $v0, 0x4000
    ctx->r25 = ctx->r2 & 0X4000;
L_800B0224:
    // 0x800B0224: beq         $t9, $zero, L_800B0244
    if (ctx->r25 == 0) {
        // 0x800B0228: andi        $t1, $v0, 0x400
        ctx->r9 = ctx->r2 & 0X400;
            goto L_800B0244;
    }
    // 0x800B0228: andi        $t1, $v0, 0x400
    ctx->r9 = ctx->r2 & 0X400;
    // 0x800B022C: sll         $t0, $s3, 5
    ctx->r8 = S32(ctx->r19 << 5);
    // 0x800B0230: addu        $a1, $a2, $t0
    ctx->r5 = ADD32(ctx->r6, ctx->r8);
    // 0x800B0234: jal         0x800B03BC
    // 0x800B0238: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    obj_trigger_emitter(rdram, ctx);
        goto after_1;
    // 0x800B0238: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x800B023C: b           L_800B02A4
    // 0x800B0240: lw          $t9, 0x40($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X40);
        goto L_800B02A4;
    // 0x800B0240: lw          $t9, 0x40($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X40);
L_800B0244:
    // 0x800B0244: beq         $t1, $zero, L_800B0260
    if (ctx->r9 == 0) {
        // 0x800B0248: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800B0260;
    }
    // 0x800B0248: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B024C: sll         $t2, $s3, 5
    ctx->r10 = S32(ctx->r19 << 5);
    // 0x800B0250: jal         0x800B03BC
    // 0x800B0254: addu        $a1, $a2, $t2
    ctx->r5 = ADD32(ctx->r6, ctx->r10);
    obj_trigger_emitter(rdram, ctx);
        goto after_2;
    // 0x800B0254: addu        $a1, $a2, $t2
    ctx->r5 = ADD32(ctx->r6, ctx->r10);
    after_2:
    // 0x800B0258: b           L_800B02A4
    // 0x800B025C: lw          $t9, 0x40($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X40);
        goto L_800B02A4;
    // 0x800B025C: lw          $t9, 0x40($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X40);
L_800B0260:
    // 0x800B0260: lh          $t3, 0xA($v1)
    ctx->r11 = MEM_H(ctx->r3, 0XA);
    // 0x800B0264: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B0268: addu        $t4, $t3, $s6
    ctx->r12 = ADD32(ctx->r11, ctx->r22);
    // 0x800B026C: sh          $t4, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r12;
    // 0x800B0270: lw          $a2, 0x6C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X6C);
    // 0x800B0274: sll         $t8, $s3, 5
    ctx->r24 = S32(ctx->r19 << 5);
    // 0x800B0278: addu        $v1, $a2, $s4
    ctx->r3 = ADD32(ctx->r6, ctx->r20);
    // 0x800B027C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800B0280: lh          $t5, 0xA($v1)
    ctx->r13 = MEM_H(ctx->r3, 0XA);
    // 0x800B0284: lh          $t7, 0x40($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X40);
    // 0x800B0288: nop

    // 0x800B028C: slt         $at, $t5, $t7
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800B0290: bne         $at, $zero, L_800B02A0
    if (ctx->r1 != 0) {
        // 0x800B0294: nop
    
            goto L_800B02A0;
    }
    // 0x800B0294: nop

    // 0x800B0298: jal         0x800B03BC
    // 0x800B029C: addu        $a1, $a2, $t8
    ctx->r5 = ADD32(ctx->r6, ctx->r24);
    obj_trigger_emitter(rdram, ctx);
        goto after_3;
    // 0x800B029C: addu        $a1, $a2, $t8
    ctx->r5 = ADD32(ctx->r6, ctx->r24);
    after_3:
L_800B02A0:
    // 0x800B02A0: lw          $t9, 0x40($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X40);
L_800B02A4:
    // 0x800B02A4: nop

    // 0x800B02A8: lb          $a3, 0x57($t9)
    ctx->r7 = MEM_B(ctx->r25, 0X57);
    // 0x800B02AC: b           L_800B0380
    // 0x800B02B0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
        goto L_800B0380;
    // 0x800B02B0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_800B02B4:
    // 0x800B02B4: lh          $v0, 0x4($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X4);
    // 0x800B02B8: nop

    // 0x800B02BC: andi        $t0, $v0, 0x8000
    ctx->r8 = ctx->r2 & 0X8000;
    // 0x800B02C0: beq         $t0, $zero, L_800B037C
    if (ctx->r8 == 0) {
        // 0x800B02C4: andi        $t1, $v0, 0x4000
        ctx->r9 = ctx->r2 & 0X4000;
            goto L_800B037C;
    }
    // 0x800B02C4: andi        $t1, $v0, 0x4000
    ctx->r9 = ctx->r2 & 0X4000;
    // 0x800B02C8: beq         $t1, $zero, L_800B0320
    if (ctx->r9 == 0) {
        // 0x800B02CC: andi        $t4, $v0, 0x400
        ctx->r12 = ctx->r2 & 0X400;
            goto L_800B0320;
    }
    // 0x800B02CC: andi        $t4, $v0, 0x400
    ctx->r12 = ctx->r2 & 0X400;
    // 0x800B02D0: sll         $t2, $s3, 5
    ctx->r10 = S32(ctx->r19 << 5);
    // 0x800B02D4: addu        $s1, $a2, $t2
    ctx->r17 = ADD32(ctx->r6, ctx->r10);
    // 0x800B02D8: lbu         $s0, 0x6($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X6);
    // 0x800B02DC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800B02E0: addiu       $s0, $s0, -0x40
    ctx->r16 = ADD32(ctx->r16, -0X40);
    // 0x800B02E4: bgez        $s0, L_800B02F0
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800B02E8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800B02F0;
    }
    // 0x800B02E8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B02EC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800B02F0:
    // 0x800B02F0: jal         0x800B03BC
    // 0x800B02F4: sb          $s0, 0x6($s1)
    MEM_B(0X6, ctx->r17) = ctx->r16;
    obj_trigger_emitter(rdram, ctx);
        goto after_4;
    // 0x800B02F4: sb          $s0, 0x6($s1)
    MEM_B(0X6, ctx->r17) = ctx->r16;
    after_4:
    // 0x800B02F8: bne         $s0, $zero, L_800B030C
    if (ctx->r16 != 0) {
        // 0x800B02FC: sb          $s0, 0x6($s1)
        MEM_B(0X6, ctx->r17) = ctx->r16;
            goto L_800B030C;
    }
    // 0x800B02FC: sb          $s0, 0x6($s1)
    MEM_B(0X6, ctx->r17) = ctx->r16;
    // 0x800B0300: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B0304: jal         0x800AFC44
    // 0x800B0308: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    obj_disable_emitter(rdram, ctx);
        goto after_5;
    // 0x800B0308: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_5:
L_800B030C:
    // 0x800B030C: lw          $t3, 0x40($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X40);
    // 0x800B0310: nop

    // 0x800B0314: lb          $a3, 0x57($t3)
    ctx->r7 = MEM_B(ctx->r11, 0X57);
    // 0x800B0318: b           L_800B0380
    // 0x800B031C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
        goto L_800B0380;
    // 0x800B031C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_800B0320:
    // 0x800B0320: beq         $t4, $zero, L_800B0364
    if (ctx->r12 == 0) {
        // 0x800B0324: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800B0364;
    }
    // 0x800B0324: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B0328: sll         $t6, $s3, 5
    ctx->r14 = S32(ctx->r19 << 5);
    // 0x800B032C: ori         $t5, $v0, 0x200
    ctx->r13 = ctx->r2 | 0X200;
    // 0x800B0330: addu        $a0, $a2, $t6
    ctx->r4 = ADD32(ctx->r6, ctx->r14);
    // 0x800B0334: sh          $t5, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r13;
    // 0x800B0338: lbu         $t7, 0x6($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X6);
    // 0x800B033C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B0340: bne         $t7, $zero, L_800B0350
    if (ctx->r15 != 0) {
        // 0x800B0344: nop
    
            goto L_800B0350;
    }
    // 0x800B0344: nop

    // 0x800B0348: jal         0x800AFC44
    // 0x800B034C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    obj_disable_emitter(rdram, ctx);
        goto after_6;
    // 0x800B034C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_6:
L_800B0350:
    // 0x800B0350: lw          $t8, 0x40($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X40);
    // 0x800B0354: nop

    // 0x800B0358: lb          $a3, 0x57($t8)
    ctx->r7 = MEM_B(ctx->r24, 0X57);
    // 0x800B035C: b           L_800B0380
    // 0x800B0360: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
        goto L_800B0380;
    // 0x800B0360: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_800B0364:
    // 0x800B0364: jal         0x800AFC44
    // 0x800B0368: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    obj_disable_emitter(rdram, ctx);
        goto after_7;
    // 0x800B0368: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_7:
    // 0x800B036C: lw          $t9, 0x40($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X40);
    // 0x800B0370: nop

    // 0x800B0374: lb          $a3, 0x57($t9)
    ctx->r7 = MEM_B(ctx->r25, 0X57);
    // 0x800B0378: nop

L_800B037C:
    // 0x800B037C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_800B0380:
    // 0x800B0380: slt         $at, $s3, $a3
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800B0384: srl         $t0, $s5, 1
    ctx->r8 = S32(U32(ctx->r21) >> 1);
    // 0x800B0388: addiu       $s4, $s4, 0x20
    ctx->r20 = ADD32(ctx->r20, 0X20);
    // 0x800B038C: bne         $at, $zero, L_800B01E0
    if (ctx->r1 != 0) {
        // 0x800B0390: or          $s5, $t0, $zero
        ctx->r21 = ctx->r8 | 0;
            goto L_800B01E0;
    }
    // 0x800B0390: or          $s5, $t0, $zero
    ctx->r21 = ctx->r8 | 0;
L_800B0394:
    // 0x800B0394: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800B0398: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B039C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800B03A0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800B03A4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800B03A8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800B03AC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800B03B0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800B03B4: jr          $ra
    // 0x800B03B8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800B03B8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void obj_trigger_emitter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B03BC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800B03C0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800B03C4: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800B03C8: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800B03CC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800B03D0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800B03D4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800B03D8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800B03DC: lh          $v0, 0x4($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X4);
    // 0x800B03E0: lw          $s4, 0x0($a1)
    ctx->r20 = MEM_W(ctx->r5, 0X0);
    // 0x800B03E4: andi        $t6, $v0, 0x4000
    ctx->r14 = ctx->r2 & 0X4000;
    // 0x800B03E8: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800B03EC: beq         $t6, $zero, L_800B043C
    if (ctx->r14 == 0) {
        // 0x800B03F0: or          $s5, $a0, $zero
        ctx->r21 = ctx->r4 | 0;
            goto L_800B043C;
    }
    // 0x800B03F0: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x800B03F4: jal         0x800B110C
    // 0x800B03F8: nop

    create_line_particle(rdram, ctx);
        goto after_0;
    // 0x800B03F8: nop

    after_0:
    // 0x800B03FC: beq         $v0, $zero, L_800B040C
    if (ctx->r2 == 0) {
        // 0x800B0400: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800B040C;
    }
    // 0x800B0400: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800B0404: jal         0x8000E9D0
    // 0x800B0408: nop

    add_particle_to_entity_list(rdram, ctx);
        goto after_1;
    // 0x800B0408: nop

    after_1:
L_800B040C:
    // 0x800B040C: lbu         $v0, 0x6($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X6);
    // 0x800B0410: lh          $t7, 0x4($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X4);
    // 0x800B0414: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // 0x800B0418: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x800B041C: andi        $t8, $t7, 0xDFFF
    ctx->r24 = ctx->r15 & 0XDFFF;
    // 0x800B0420: bne         $at, $zero, L_800B0434
    if (ctx->r1 != 0) {
        // 0x800B0424: sh          $t8, 0x4($s2)
        MEM_H(0X4, ctx->r18) = ctx->r24;
            goto L_800B0434;
    }
    // 0x800B0424: sh          $t8, 0x4($s2)
    MEM_H(0X4, ctx->r18) = ctx->r24;
    // 0x800B0428: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800B042C: b           L_800B054C
    // 0x800B0430: sb          $t9, 0x6($s2)
    MEM_B(0X6, ctx->r18) = ctx->r25;
        goto L_800B054C;
    // 0x800B0430: sb          $t9, 0x6($s2)
    MEM_B(0X6, ctx->r18) = ctx->r25;
L_800B0434:
    // 0x800B0434: b           L_800B054C
    // 0x800B0438: sb          $v0, 0x6($s2)
    MEM_B(0X6, ctx->r18) = ctx->r2;
        goto L_800B054C;
    // 0x800B0438: sb          $v0, 0x6($s2)
    MEM_B(0X6, ctx->r18) = ctx->r2;
L_800B043C:
    // 0x800B043C: andi        $t0, $v0, 0x400
    ctx->r8 = ctx->r2 & 0X400;
    // 0x800B0440: beq         $t0, $zero, L_800B04C0
    if (ctx->r8 == 0) {
        // 0x800B0444: nop
    
            goto L_800B04C0;
    }
    // 0x800B0444: nop

    // 0x800B0448: lbu         $t1, 0x6($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0X6);
    // 0x800B044C: lbu         $t2, 0x7($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X7);
    // 0x800B0450: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800B0454: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800B0458: beq         $at, $zero, L_800B0550
    if (ctx->r1 == 0) {
        // 0x800B045C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800B0550;
    }
    // 0x800B045C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800B0460: jal         0x800B0BF8
    // 0x800B0464: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    create_point_particle(rdram, ctx);
        goto after_2;
    // 0x800B0464: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
    // 0x800B0468: lh          $t3, 0x4($s2)
    ctx->r11 = MEM_H(ctx->r18, 0X4);
    // 0x800B046C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B0470: andi        $t4, $t3, 0xDFFF
    ctx->r12 = ctx->r11 & 0XDFFF;
    // 0x800B0474: beq         $v0, $zero, L_800B054C
    if (ctx->r2 == 0) {
        // 0x800B0478: sh          $t4, 0x4($s2)
        MEM_H(0X4, ctx->r18) = ctx->r12;
            goto L_800B054C;
    }
    // 0x800B0478: sh          $t4, 0x4($s2)
    MEM_H(0X4, ctx->r18) = ctx->r12;
    // 0x800B047C: jal         0x8000E9D0
    // 0x800B0480: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    add_particle_to_entity_list(rdram, ctx);
        goto after_3;
    // 0x800B0480: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x800B0484: lw          $t6, 0x40($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X40);
    // 0x800B0488: lbu         $t5, 0x6($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0X6);
    // 0x800B048C: ori         $t7, $t6, 0x2000
    ctx->r15 = ctx->r14 | 0X2000;
    // 0x800B0490: sw          $t7, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r15;
    // 0x800B0494: sb          $t5, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r13;
    // 0x800B0498: lbu         $t9, 0x6($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X6);
    // 0x800B049C: lw          $t8, 0xC($s2)
    ctx->r24 = MEM_W(ctx->r18, 0XC);
    // 0x800B04A0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800B04A4: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800B04A8: sw          $s0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r16;
    // 0x800B04AC: lbu         $t2, 0x6($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X6);
    // 0x800B04B0: nop

    // 0x800B04B4: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800B04B8: b           L_800B054C
    // 0x800B04BC: sb          $t3, 0x6($s2)
    MEM_B(0X6, ctx->r18) = ctx->r11;
        goto L_800B054C;
    // 0x800B04BC: sb          $t3, 0x6($s2)
    MEM_B(0X6, ctx->r18) = ctx->r11;
L_800B04C0:
    // 0x800B04C0: lh          $v0, 0xA($s2)
    ctx->r2 = MEM_H(ctx->r18, 0XA);
    // 0x800B04C4: lh          $v1, 0x40($s4)
    ctx->r3 = MEM_H(ctx->r20, 0X40);
    // 0x800B04C8: addiu       $s3, $zero, -0x2001
    ctx->r19 = ADD32(0, -0X2001);
    // 0x800B04CC: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800B04D0: bne         $at, $zero, L_800B054C
    if (ctx->r1 != 0) {
        // 0x800B04D4: subu        $t4, $v0, $v1
        ctx->r12 = SUB32(ctx->r2, ctx->r3);
            goto L_800B054C;
    }
    // 0x800B04D4: subu        $t4, $v0, $v1
    ctx->r12 = SUB32(ctx->r2, ctx->r3);
L_800B04D8:
    // 0x800B04D8: sh          $t4, 0xA($s2)
    MEM_H(0XA, ctx->r18) = ctx->r12;
    // 0x800B04DC: lh          $t5, 0x42($s4)
    ctx->r13 = MEM_H(ctx->r20, 0X42);
    // 0x800B04E0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800B04E4: blez        $t5, L_800B0534
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800B04E8: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_800B0534;
    }
    // 0x800B04E8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800B04EC:
    // 0x800B04EC: jal         0x800B1690
    // 0x800B04F0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    create_general_particle(rdram, ctx);
        goto after_4;
    // 0x800B04F0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_4:
    // 0x800B04F4: beq         $v0, $zero, L_800B0510
    if (ctx->r2 == 0) {
        // 0x800B04F8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800B0510;
    }
    // 0x800B04F8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B04FC: jal         0x8000E9D0
    // 0x800B0500: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    add_particle_to_entity_list(rdram, ctx);
        goto after_5;
    // 0x800B0500: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x800B0504: lh          $a1, 0xA($s2)
    ctx->r5 = MEM_H(ctx->r18, 0XA);
    // 0x800B0508: jal         0x800B285C
    // 0x800B050C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    particle_update(rdram, ctx);
        goto after_6;
    // 0x800B050C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_800B0510:
    // 0x800B0510: lh          $t6, 0x4($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X4);
    // 0x800B0514: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800B0518: and         $t7, $t6, $s3
    ctx->r15 = ctx->r14 & ctx->r19;
    // 0x800B051C: sh          $t7, 0x4($s2)
    MEM_H(0X4, ctx->r18) = ctx->r15;
    // 0x800B0520: lh          $t9, 0x42($s4)
    ctx->r25 = MEM_H(ctx->r20, 0X42);
    // 0x800B0524: nop

    // 0x800B0528: slt         $at, $s1, $t9
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800B052C: bne         $at, $zero, L_800B04EC
    if (ctx->r1 != 0) {
        // 0x800B0530: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_800B04EC;
    }
    // 0x800B0530: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800B0534:
    // 0x800B0534: lh          $v0, 0xA($s2)
    ctx->r2 = MEM_H(ctx->r18, 0XA);
    // 0x800B0538: lh          $v1, 0x40($s4)
    ctx->r3 = MEM_H(ctx->r20, 0X40);
    // 0x800B053C: nop

    // 0x800B0540: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800B0544: beq         $at, $zero, L_800B04D8
    if (ctx->r1 == 0) {
        // 0x800B0548: subu        $t4, $v0, $v1
        ctx->r12 = SUB32(ctx->r2, ctx->r3);
            goto L_800B04D8;
    }
    // 0x800B0548: subu        $t4, $v0, $v1
    ctx->r12 = SUB32(ctx->r2, ctx->r3);
L_800B054C:
    // 0x800B054C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800B0550:
    // 0x800B0550: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800B0554: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800B0558: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800B055C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800B0560: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800B0564: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800B0568: jr          $ra
    // 0x800B056C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800B056C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void setup_particle_velocity(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B0570: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800B0574: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B0578: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800B057C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800B0580: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800B0584: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800B0588: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x800B058C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800B0590: andi        $t7, $t6, 0x70
    ctx->r15 = ctx->r14 & 0X70;
    // 0x800B0594: beq         $t7, $zero, L_800B05C0
    if (ctx->r15 == 0) {
        // 0x800B0598: or          $s1, $a3, $zero
        ctx->r17 = ctx->r7 | 0;
            goto L_800B05C0;
    }
    // 0x800B0598: or          $s1, $a3, $zero
    ctx->r17 = ctx->r7 | 0;
    // 0x800B059C: lwc1        $f4, 0x30($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X30);
    // 0x800B05A0: nop

    // 0x800B05A4: swc1        $f4, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f4.u32l;
    // 0x800B05A8: lwc1        $f6, 0x34($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X34);
    // 0x800B05AC: nop

    // 0x800B05B0: swc1        $f6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f6.u32l;
    // 0x800B05B4: lwc1        $f8, 0x38($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X38);
    // 0x800B05B8: b           L_800B05D8
    // 0x800B05BC: swc1        $f8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f8.u32l;
        goto L_800B05D8;
    // 0x800B05BC: swc1        $f8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f8.u32l;
L_800B05C0:
    // 0x800B05C0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B05C4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800B05C8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800B05CC: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
    // 0x800B05D0: swc1        $f16, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f16.u32l;
    // 0x800B05D4: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
L_800B05D8:
    // 0x800B05D8: lw          $v1, 0x5C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X5C);
    // 0x800B05DC: nop

    // 0x800B05E0: andi        $t8, $v1, 0x700
    ctx->r24 = ctx->r3 & 0X700;
    // 0x800B05E4: beq         $t8, $zero, L_800B06D8
    if (ctx->r24 == 0) {
        // 0x800B05E8: or          $v1, $t8, $zero
        ctx->r3 = ctx->r24 | 0;
            goto L_800B06D8;
    }
    // 0x800B05E8: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x800B05EC: andi        $t9, $t8, 0x100
    ctx->r25 = ctx->r24 & 0X100;
    // 0x800B05F0: beq         $t9, $zero, L_800B0640
    if (ctx->r25 == 0) {
        // 0x800B05F4: andi        $t0, $v1, 0x200
        ctx->r8 = ctx->r3 & 0X200;
            goto L_800B0640;
    }
    // 0x800B05F4: andi        $t0, $v1, 0x200
    ctx->r8 = ctx->r3 & 0X200;
    // 0x800B05F8: lw          $a1, 0x74($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X74);
    // 0x800B05FC: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x800B0600: jal         0x8006FB8C
    // 0x800B0604: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_0;
    // 0x800B0604: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_0:
    // 0x800B0608: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800B060C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B0610: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B0614: lwc1        $f11, -0x6EE8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X6EE8);
    // 0x800B0618: lwc1        $f10, -0x6EE4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X6EE4);
    // 0x800B061C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800B0620: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800B0624: lwc1        $f18, 0x1C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800B0628: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800B062C: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800B0630: add.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = ctx->f4.d + ctx->f16.d;
    // 0x800B0634: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x800B0638: swc1        $f8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
    // 0x800B063C: andi        $t0, $v1, 0x200
    ctx->r8 = ctx->r3 & 0X200;
L_800B0640:
    // 0x800B0640: beq         $t0, $zero, L_800B0690
    if (ctx->r8 == 0) {
        // 0x800B0644: andi        $t1, $v1, 0x400
        ctx->r9 = ctx->r3 & 0X400;
            goto L_800B0690;
    }
    // 0x800B0644: andi        $t1, $v1, 0x400
    ctx->r9 = ctx->r3 & 0X400;
    // 0x800B0648: lw          $a1, 0x78($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X78);
    // 0x800B064C: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x800B0650: jal         0x8006FB8C
    // 0x800B0654: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_1;
    // 0x800B0654: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_1:
    // 0x800B0658: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x800B065C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B0660: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800B0664: lwc1        $f17, -0x6EE0($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X6EE0);
    // 0x800B0668: lwc1        $f16, -0x6EDC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X6EDC);
    // 0x800B066C: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800B0670: mul.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x800B0674: lwc1        $f8, 0x20($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800B0678: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800B067C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800B0680: add.d       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = ctx->f10.d + ctx->f6.d;
    // 0x800B0684: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x800B0688: swc1        $f4, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f4.u32l;
    // 0x800B068C: andi        $t1, $v1, 0x400
    ctx->r9 = ctx->r3 & 0X400;
L_800B0690:
    // 0x800B0690: beq         $t1, $zero, L_800B06D8
    if (ctx->r9 == 0) {
        // 0x800B0694: nop
    
            goto L_800B06D8;
    }
    // 0x800B0694: nop

    // 0x800B0698: lw          $a1, 0x7C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X7C);
    // 0x800B069C: jal         0x8006FB8C
    // 0x800B06A0: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_2;
    // 0x800B06A0: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_2:
    // 0x800B06A4: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x800B06A8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B06AC: cvt.s.w     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800B06B0: lwc1        $f7, -0x6ED8($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X6ED8);
    // 0x800B06B4: lwc1        $f6, -0x6ED4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X6ED4);
    // 0x800B06B8: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800B06BC: mul.d       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f6.d);
    // 0x800B06C0: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800B06C4: nop

    // 0x800B06C8: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x800B06CC: add.d       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f16.d + ctx->f18.d;
    // 0x800B06D0: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x800B06D4: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
L_800B06D8:
    // 0x800B06D8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800B06DC: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800B06E0: andi        $v1, $v0, 0x70
    ctx->r3 = ctx->r2 & 0X70;
    // 0x800B06E4: beq         $v1, $at, L_800B06FC
    if (ctx->r3 == ctx->r1) {
        // 0x800B06E8: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_800B06FC;
    }
    // 0x800B06E8: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x800B06EC: beq         $v1, $at, L_800B0758
    if (ctx->r3 == ctx->r1) {
        // 0x800B06F0: lw          $t5, 0x44($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X44);
            goto L_800B0758;
    }
    // 0x800B06F0: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x800B06F4: b           L_800B07AC
    // 0x800B06F8: andi        $t8, $v0, 0x4
    ctx->r24 = ctx->r2 & 0X4;
        goto L_800B07AC;
    // 0x800B06F8: andi        $t8, $v0, 0x4
    ctx->r24 = ctx->r2 & 0X4;
L_800B06FC:
    // 0x800B06FC: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x800B0700: lwc1        $f6, 0x1C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800B0704: lwc1        $f4, 0x1C($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X1C);
    // 0x800B0708: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800B070C: add.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800B0710: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800B0714: swc1        $f16, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f16.u32l;
    // 0x800B0718: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x800B071C: nop

    // 0x800B0720: lwc1        $f8, 0x20($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X20);
    // 0x800B0724: nop

    // 0x800B0728: add.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800B072C: swc1        $f10, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f10.u32l;
    // 0x800B0730: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x800B0734: nop

    // 0x800B0738: lwc1        $f4, 0x24($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X24);
    // 0x800B073C: nop

    // 0x800B0740: add.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800B0744: swc1        $f16, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f16.u32l;
    // 0x800B0748: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800B074C: b           L_800B07AC
    // 0x800B0750: andi        $t8, $v0, 0x4
    ctx->r24 = ctx->r2 & 0X4;
        goto L_800B07AC;
    // 0x800B0750: andi        $t8, $v0, 0x4
    ctx->r24 = ctx->r2 & 0X4;
    // 0x800B0754: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
L_800B0758:
    // 0x800B0758: lwc1        $f18, 0x1C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800B075C: lwc1        $f8, 0x1C($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X1C);
    // 0x800B0760: lwc1        $f6, 0x20($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800B0764: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800B0768: lwc1        $f18, 0x24($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800B076C: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
    // 0x800B0770: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800B0774: nop

    // 0x800B0778: lwc1        $f4, 0x20($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X20);
    // 0x800B077C: nop

    // 0x800B0780: mul.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800B0784: swc1        $f16, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f16.u32l;
    // 0x800B0788: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800B078C: nop

    // 0x800B0790: lwc1        $f8, 0x24($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X24);
    // 0x800B0794: nop

    // 0x800B0798: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800B079C: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
    // 0x800B07A0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800B07A4: nop

    // 0x800B07A8: andi        $t8, $v0, 0x4
    ctx->r24 = ctx->r2 & 0X4;
L_800B07AC:
    // 0x800B07AC: beq         $t8, $zero, L_800B0910
    if (ctx->r24 == 0) {
        // 0x800B07B0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800B0910;
    }
    // 0x800B07B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B07B4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B07B8: nop

    // 0x800B07BC: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x800B07C0: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x800B07C4: lwc1        $f6, 0x3C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x800B07C8: nop

    // 0x800B07CC: neg.s       $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = -ctx->f6.fl;
    // 0x800B07D0: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x800B07D4: lw          $v1, 0x5C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X5C);
    // 0x800B07D8: nop

    // 0x800B07DC: andi        $t9, $v1, 0x10
    ctx->r25 = ctx->r3 & 0X10;
    // 0x800B07E0: beq         $t9, $zero, L_800B0830
    if (ctx->r25 == 0) {
        // 0x800B07E4: andi        $t0, $v1, 0x60
        ctx->r8 = ctx->r3 & 0X60;
            goto L_800B0830;
    }
    // 0x800B07E4: andi        $t0, $v1, 0x60
    ctx->r8 = ctx->r3 & 0X60;
    // 0x800B07E8: lw          $a1, 0x70($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X70);
    // 0x800B07EC: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x800B07F0: jal         0x8006FB8C
    // 0x800B07F4: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_3;
    // 0x800B07F4: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_3:
    // 0x800B07F8: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x800B07FC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B0800: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800B0804: lwc1        $f11, -0x6ED0($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X6ED0);
    // 0x800B0808: lwc1        $f10, -0x6ECC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X6ECC);
    // 0x800B080C: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x800B0810: mul.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800B0814: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800B0818: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800B081C: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x800B0820: add.d       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = ctx->f16.d + ctx->f6.d;
    // 0x800B0824: cvt.s.d     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f8.fl = CVT_S_D(ctx->f18.d);
    // 0x800B0828: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x800B082C: andi        $t0, $v1, 0x60
    ctx->r8 = ctx->r3 & 0X60;
L_800B0830:
    // 0x800B0830: beq         $t0, $zero, L_800B08B8
    if (ctx->r8 == 0) {
        // 0x800B0834: lw          $a0, 0x48($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X48);
            goto L_800B08B8;
    }
    // 0x800B0834: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x800B0838: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x800B083C: andi        $t3, $v1, 0x20
    ctx->r11 = ctx->r3 & 0X20;
    // 0x800B0840: lh          $t2, 0x12($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X12);
    // 0x800B0844: beq         $t3, $zero, L_800B086C
    if (ctx->r11 == 0) {
        // 0x800B0848: sh          $t2, 0x28($sp)
        MEM_H(0X28, ctx->r29) = ctx->r10;
            goto L_800B086C;
    }
    // 0x800B0848: sh          $t2, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r10;
    // 0x800B084C: lh          $a1, 0x6A($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X6A);
    // 0x800B0850: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x800B0854: jal         0x8006FB8C
    // 0x800B0858: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_4;
    // 0x800B0858: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_4:
    // 0x800B085C: lh          $t4, 0x28($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X28);
    // 0x800B0860: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800B0864: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800B0868: sh          $t5, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r13;
L_800B086C:
    // 0x800B086C: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800B0870: andi        $t8, $v1, 0x40
    ctx->r24 = ctx->r3 & 0X40;
    // 0x800B0874: lh          $t7, 0x14($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X14);
    // 0x800B0878: beq         $t8, $zero, L_800B089C
    if (ctx->r24 == 0) {
        // 0x800B087C: sh          $t7, 0x2A($sp)
        MEM_H(0X2A, ctx->r29) = ctx->r15;
            goto L_800B089C;
    }
    // 0x800B087C: sh          $t7, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r15;
    // 0x800B0880: lh          $a1, 0x6C($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X6C);
    // 0x800B0884: jal         0x8006FB8C
    // 0x800B0888: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_5;
    // 0x800B0888: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_5:
    // 0x800B088C: lh          $t9, 0x2A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X2A);
    // 0x800B0890: nop

    // 0x800B0894: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x800B0898: sh          $t0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r8;
L_800B089C:
    // 0x800B089C: addiu       $s1, $sp, 0x30
    ctx->r17 = ADD32(ctx->r29, 0X30);
    // 0x800B08A0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800B08A4: jal         0x800706D0
    // 0x800B08A8: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    vec3f_rotate_py(rdram, ctx);
        goto after_6;
    // 0x800B08A8: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_6:
    // 0x800B08AC: b           L_800B08CC
    // 0x800B08B0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
        goto L_800B08CC;
    // 0x800B08B0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x800B08B4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
L_800B08B8:
    // 0x800B08B8: addiu       $s1, $sp, 0x30
    ctx->r17 = ADD32(ctx->r29, 0X30);
    // 0x800B08BC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800B08C0: jal         0x800706D0
    // 0x800B08C4: addiu       $a0, $a0, 0x12
    ctx->r4 = ADD32(ctx->r4, 0X12);
    vec3f_rotate_py(rdram, ctx);
        goto after_7;
    // 0x800B08C4: addiu       $a0, $a0, 0x12
    ctx->r4 = ADD32(ctx->r4, 0X12);
    after_7:
    // 0x800B08C8: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
L_800B08CC:
    // 0x800B08CC: jal         0x80070560
    // 0x800B08D0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    vec3f_rotate(rdram, ctx);
        goto after_8;
    // 0x800B08D0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_8:
    // 0x800B08D4: lwc1        $f10, 0x1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800B08D8: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800B08DC: lwc1        $f6, 0x20($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800B08E0: add.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800B08E4: lwc1        $f10, 0x24($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800B08E8: swc1        $f16, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f16.u32l;
    // 0x800B08EC: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800B08F0: nop

    // 0x800B08F4: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800B08F8: swc1        $f8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f8.u32l;
    // 0x800B08FC: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800B0900: nop

    // 0x800B0904: add.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800B0908: swc1        $f16, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f16.u32l;
    // 0x800B090C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800B0910:
    // 0x800B0910: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800B0914: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800B0918: jr          $ra
    // 0x800B091C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800B091C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void setup_particle_position(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B0920: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800B0924: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B0928: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B092C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800B0930: lh          $t6, 0x18($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X18);
    // 0x800B0934: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800B0938: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800B093C: nop

    // 0x800B0940: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B0944: swc1        $f6, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->f6.u32l;
    // 0x800B0948: lh          $t7, 0x1A($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X1A);
    // 0x800B094C: nop

    // 0x800B0950: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800B0954: nop

    // 0x800B0958: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B095C: swc1        $f10, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f10.u32l;
    // 0x800B0960: lh          $t8, 0x1C($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X1C);
    // 0x800B0964: nop

    // 0x800B0968: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x800B096C: nop

    // 0x800B0970: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800B0974: swc1        $f18, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f18.u32l;
    // 0x800B0978: lwc1        $f4, 0x58($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X58);
    // 0x800B097C: nop

    // 0x800B0980: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
    // 0x800B0984: lw          $t9, 0x5C($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X5C);
    // 0x800B0988: nop

    // 0x800B098C: sll         $t0, $t9, 12
    ctx->r8 = S32(ctx->r25 << 12);
    // 0x800B0990: bgez        $t0, L_800B09E4
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800B0994: nop
    
            goto L_800B09E4;
    }
    // 0x800B0994: nop

    // 0x800B0998: lw          $a1, 0x94($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X94);
    // 0x800B099C: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x800B09A0: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800B09A4: jal         0x8006FB8C
    // 0x800B09A8: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_0;
    // 0x800B09A8: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_0:
    // 0x800B09AC: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800B09B0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B09B4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800B09B8: lwc1        $f17, -0x6EC8($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X6EC8);
    // 0x800B09BC: lwc1        $f16, -0x6EC4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X6EC4);
    // 0x800B09C0: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800B09C4: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x800B09C8: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800B09CC: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x800B09D0: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800B09D4: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x800B09D8: add.d       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f6.d + ctx->f18.d;
    // 0x800B09DC: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x800B09E0: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
L_800B09E4:
    // 0x800B09E4: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x800B09E8: nop

    // 0x800B09EC: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x800B09F0: beq         $t2, $zero, L_800B0B4C
    if (ctx->r10 == 0) {
        // 0x800B09F4: nop
    
            goto L_800B0B4C;
    }
    // 0x800B09F4: nop

    // 0x800B09F8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B09FC: nop

    // 0x800B0A00: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x800B0A04: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x800B0A08: lwc1        $f16, 0x10($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X10);
    // 0x800B0A0C: nop

    // 0x800B0A10: neg.s       $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = -ctx->f16.fl;
    // 0x800B0A14: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x800B0A18: lw          $v1, 0x5C($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X5C);
    // 0x800B0A1C: nop

    // 0x800B0A20: andi        $t3, $v1, 0x1
    ctx->r11 = ctx->r3 & 0X1;
    // 0x800B0A24: beq         $t3, $zero, L_800B0A84
    if (ctx->r11 == 0) {
        // 0x800B0A28: andi        $t4, $v1, 0x6
        ctx->r12 = ctx->r3 & 0X6;
            goto L_800B0A84;
    }
    // 0x800B0A28: andi        $t4, $v1, 0x6
    ctx->r12 = ctx->r3 & 0X6;
    // 0x800B0A2C: lw          $a1, 0x60($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X60);
    // 0x800B0A30: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x800B0A34: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800B0A38: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x800B0A3C: jal         0x8006FB8C
    // 0x800B0A40: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_1;
    // 0x800B0A40: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_1:
    // 0x800B0A44: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800B0A48: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B0A4C: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800B0A50: lwc1        $f11, -0x6EC0($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X6EC0);
    // 0x800B0A54: lwc1        $f10, -0x6EBC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X6EBC);
    // 0x800B0A58: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x800B0A5C: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800B0A60: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800B0A64: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800B0A68: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800B0A6C: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x800B0A70: add.d       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f6.d + ctx->f16.d;
    // 0x800B0A74: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x800B0A78: cvt.s.d     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f8.fl = CVT_S_D(ctx->f18.d);
    // 0x800B0A7C: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x800B0A80: andi        $t4, $v1, 0x6
    ctx->r12 = ctx->r3 & 0X6;
L_800B0A84:
    // 0x800B0A84: beq         $t4, $zero, L_800B0B0C
    if (ctx->r12 == 0) {
        // 0x800B0A88: addiu       $a0, $a2, 0xC
        ctx->r4 = ADD32(ctx->r6, 0XC);
            goto L_800B0B0C;
    }
    // 0x800B0A88: addiu       $a0, $a2, 0xC
    ctx->r4 = ADD32(ctx->r6, 0XC);
    // 0x800B0A8C: lh          $t5, 0xC($a2)
    ctx->r13 = MEM_H(ctx->r6, 0XC);
    // 0x800B0A90: andi        $t6, $v1, 0x2
    ctx->r14 = ctx->r3 & 0X2;
    // 0x800B0A94: beq         $t6, $zero, L_800B0ACC
    if (ctx->r14 == 0) {
        // 0x800B0A98: sh          $t5, 0x28($sp)
        MEM_H(0X28, ctx->r29) = ctx->r13;
            goto L_800B0ACC;
    }
    // 0x800B0A98: sh          $t5, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r13;
    // 0x800B0A9C: lh          $a1, 0x64($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X64);
    // 0x800B0AA0: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x800B0AA4: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800B0AA8: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x800B0AAC: jal         0x8006FB8C
    // 0x800B0AB0: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_2;
    // 0x800B0AB0: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_2:
    // 0x800B0AB4: lh          $t7, 0x28($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X28);
    // 0x800B0AB8: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800B0ABC: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800B0AC0: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x800B0AC4: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x800B0AC8: sh          $t8, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r24;
L_800B0ACC:
    // 0x800B0ACC: lh          $t9, 0xE($a2)
    ctx->r25 = MEM_H(ctx->r6, 0XE);
    // 0x800B0AD0: andi        $t0, $v1, 0x4
    ctx->r8 = ctx->r3 & 0X4;
    // 0x800B0AD4: beq         $t0, $zero, L_800B0AF8
    if (ctx->r8 == 0) {
        // 0x800B0AD8: sh          $t9, 0x2A($sp)
        MEM_H(0X2A, ctx->r29) = ctx->r25;
            goto L_800B0AF8;
    }
    // 0x800B0AD8: sh          $t9, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r25;
    // 0x800B0ADC: lh          $a1, 0x66($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X66);
    // 0x800B0AE0: jal         0x8006FB8C
    // 0x800B0AE4: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_3;
    // 0x800B0AE4: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_3:
    // 0x800B0AE8: lh          $t1, 0x2A($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X2A);
    // 0x800B0AEC: nop

    // 0x800B0AF0: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x800B0AF4: sh          $t2, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r10;
L_800B0AF8:
    // 0x800B0AF8: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800B0AFC: jal         0x800706D0
    // 0x800B0B00: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    vec3f_rotate_py(rdram, ctx);
        goto after_4;
    // 0x800B0B00: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_4:
    // 0x800B0B04: b           L_800B0B18
    // 0x800B0B08: lwc1        $f10, 0x4C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4C);
        goto L_800B0B18;
    // 0x800B0B08: lwc1        $f10, 0x4C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4C);
L_800B0B0C:
    // 0x800B0B0C: jal         0x80070560
    // 0x800B0B10: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    vec3f_rotate(rdram, ctx);
        goto after_5;
    // 0x800B0B10: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_5:
    // 0x800B0B14: lwc1        $f10, 0x4C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4C);
L_800B0B18:
    // 0x800B0B18: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800B0B1C: lwc1        $f16, 0x50($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800B0B20: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800B0B24: lwc1        $f10, 0x54($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800B0B28: swc1        $f6, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f6.u32l;
    // 0x800B0B2C: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800B0B30: nop

    // 0x800B0B34: add.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B0B38: swc1        $f8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f8.u32l;
    // 0x800B0B3C: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800B0B40: nop

    // 0x800B0B44: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800B0B48: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
L_800B0B4C:
    // 0x800B0B4C: lbu         $v0, 0x39($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X39);
    // 0x800B0B50: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800B0B54: beq         $v0, $at, L_800B0B70
    if (ctx->r2 == ctx->r1) {
        // 0x800B0B58: nop
    
            goto L_800B0B70;
    }
    // 0x800B0B58: nop

    // 0x800B0B5C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x800B0B60: jal         0x80070560
    // 0x800B0B64: addiu       $a1, $s0, 0x4C
    ctx->r5 = ADD32(ctx->r16, 0X4C);
    vec3f_rotate(rdram, ctx);
        goto after_6;
    // 0x800B0B64: addiu       $a1, $s0, 0x4C
    ctx->r5 = ADD32(ctx->r16, 0X4C);
    after_6:
    // 0x800B0B68: lbu         $v0, 0x39($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X39);
    // 0x800B0B6C: nop

L_800B0B70:
    // 0x800B0B70: lwc1        $f16, 0x4C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x800B0B74: lwc1        $f18, 0x50($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800B0B78: lwc1        $f8, 0x54($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800B0B7C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800B0B80: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x800B0B84: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
    // 0x800B0B88: bne         $v0, $at, L_800B0B9C
    if (ctx->r2 != ctx->r1) {
        // 0x800B0B8C: swc1        $f8, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
            goto L_800B0B9C;
    }
    // 0x800B0B8C: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    // 0x800B0B90: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x800B0B94: jal         0x80070560
    // 0x800B0B98: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    vec3f_rotate(rdram, ctx);
        goto after_7;
    // 0x800B0B98: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    after_7:
L_800B0B9C:
    // 0x800B0B9C: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x800B0BA0: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800B0BA4: lwc1        $f4, 0xC($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0XC);
    // 0x800B0BA8: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800B0BAC: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800B0BB0: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800B0BB4: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x800B0BB8: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x800B0BBC: nop

    // 0x800B0BC0: lwc1        $f18, 0x10($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X10);
    // 0x800B0BC4: nop

    // 0x800B0BC8: add.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B0BCC: swc1        $f8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f8.u32l;
    // 0x800B0BD0: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x800B0BD4: nop

    // 0x800B0BD8: lwc1        $f4, 0x14($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X14);
    // 0x800B0BDC: nop

    // 0x800B0BE0: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800B0BE4: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    // 0x800B0BE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B0BEC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B0BF0: jr          $ra
    // 0x800B0BF4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800B0BF4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void create_point_particle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B0BF8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800B0BFC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B0C00: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B0C04: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800B0C08: lh          $t7, 0x8($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X8);
    // 0x800B0C0C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800B0C10: lw          $t6, 0x3280($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3280);
    // 0x800B0C14: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800B0C18: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800B0C1C: lw          $v1, 0x0($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X0);
    // 0x800B0C20: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800B0C24: lbu         $t0, 0x0($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X0);
    // 0x800B0C28: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800B0C2C: beq         $t0, $at, L_800B0C3C
    if (ctx->r8 == ctx->r1) {
        // 0x800B0C30: addiu       $a0, $zero, 0x4
        ctx->r4 = ADD32(0, 0X4);
            goto L_800B0C3C;
    }
    // 0x800B0C30: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800B0C34: b           L_800B10FC
    // 0x800B0C38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B10FC;
    // 0x800B0C38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B0C3C:
    // 0x800B0C3C: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x800B0C40: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x800B0C44: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x800B0C48: jal         0x800B2218
    // 0x800B0C4C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    particle_allocate(rdram, ctx);
        goto after_0;
    // 0x800B0C4C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x800B0C50: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800B0C54: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800B0C58: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800B0C5C: bne         $v0, $zero, L_800B0C6C
    if (ctx->r2 != 0) {
        // 0x800B0C60: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800B0C6C;
    }
    // 0x800B0C60: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B0C64: b           L_800B10FC
    // 0x800B0C68: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_800B10FC;
    // 0x800B0C68: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_800B0C6C:
    // 0x800B0C6C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800B0C70: addiu       $t3, $zero, -0x8000
    ctx->r11 = ADD32(0, -0X8000);
    // 0x800B0C74: lh          $t2, 0x2E($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X2E);
    // 0x800B0C78: sh          $t3, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r11;
    // 0x800B0C7C: sh          $t2, 0x2E($v0)
    MEM_H(0X2E, ctx->r2) = ctx->r10;
    // 0x800B0C80: lbu         $t4, 0x1($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X1);
    // 0x800B0C84: nop

    // 0x800B0C88: sb          $t4, 0x39($v0)
    MEM_B(0X39, ctx->r2) = ctx->r12;
    // 0x800B0C8C: lhu         $t5, 0x2($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X2);
    // 0x800B0C90: nop

    // 0x800B0C94: sw          $t5, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r13;
    // 0x800B0C98: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800B0C9C: sw          $a2, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->r6;
    // 0x800B0CA0: sw          $t7, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r15;
    // 0x800B0CA4: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x800B0CA8: lwc1        $f6, 0x50($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X50);
    // 0x800B0CAC: andi        $t3, $t5, 0x800
    ctx->r11 = ctx->r13 & 0X800;
    // 0x800B0CB0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800B0CB4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B0CB8: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x800B0CBC: lwc1        $f16, 0x54($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X54);
    // 0x800B0CC0: lwc1        $f10, 0x10($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X10);
    // 0x800B0CC4: nop

    // 0x800B0CC8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800B0CCC: swc1        $f18, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f18.u32l;
    // 0x800B0CD0: lh          $t6, 0x8($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X8);
    // 0x800B0CD4: sb          $zero, 0x38($v0)
    MEM_B(0X38, ctx->r2) = 0;
    // 0x800B0CD8: swc1        $f4, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f4.u32l;
    // 0x800B0CDC: sh          $t6, 0x3A($v0)
    MEM_H(0X3A, ctx->r2) = ctx->r14;
    // 0x800B0CE0: lbu         $t8, 0x14($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X14);
    // 0x800B0CE4: nop

    // 0x800B0CE8: sb          $t8, 0x6C($v0)
    MEM_B(0X6C, ctx->r2) = ctx->r24;
    // 0x800B0CEC: lbu         $t9, 0x15($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X15);
    // 0x800B0CF0: nop

    // 0x800B0CF4: sb          $t9, 0x6D($v0)
    MEM_B(0X6D, ctx->r2) = ctx->r25;
    // 0x800B0CF8: lbu         $t0, 0x16($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X16);
    // 0x800B0CFC: nop

    // 0x800B0D00: sb          $t0, 0x6E($v0)
    MEM_B(0X6E, ctx->r2) = ctx->r8;
    // 0x800B0D04: lbu         $t1, 0x17($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X17);
    // 0x800B0D08: beq         $t3, $zero, L_800B0D64
    if (ctx->r11 == 0) {
        // 0x800B0D0C: sb          $t1, 0x6F($v0)
        MEM_B(0X6F, ctx->r2) = ctx->r9;
            goto L_800B0D64;
    }
    // 0x800B0D0C: sb          $t1, 0x6F($v0)
    MEM_B(0X6F, ctx->r2) = ctx->r9;
    // 0x800B0D10: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800B0D14: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800B0D18: lw          $a0, 0x54($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X54);
    // 0x800B0D1C: nop

    // 0x800B0D20: beq         $a0, $zero, L_800B0D64
    if (ctx->r4 == 0) {
        // 0x800B0D24: nop
    
            goto L_800B0D64;
    }
    // 0x800B0D24: nop

    // 0x800B0D28: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800B0D2C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B0D30: nop

    // 0x800B0D34: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800B0D38: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800B0D3C: nop

    // 0x800B0D40: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800B0D44: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B0D48: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B0D4C: nop

    // 0x800B0D50: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800B0D54: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x800B0D58: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800B0D5C: b           L_800B0D6C
    // 0x800B0D60: sh          $t7, 0x4A($v0)
    MEM_H(0X4A, ctx->r2) = ctx->r15;
        goto L_800B0D6C;
    // 0x800B0D60: sh          $t7, 0x4A($v0)
    MEM_H(0X4A, ctx->r2) = ctx->r15;
L_800B0D64:
    // 0x800B0D64: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800B0D68: sh          $t6, 0x4A($v0)
    MEM_H(0X4A, ctx->r2) = ctx->r14;
L_800B0D6C:
    // 0x800B0D6C: lh          $t8, 0xE($v1)
    ctx->r24 = MEM_H(ctx->r3, 0XE);
    // 0x800B0D70: nop

    // 0x800B0D74: sh          $t8, 0x60($v0)
    MEM_H(0X60, ctx->r2) = ctx->r24;
    // 0x800B0D78: lh          $t9, 0x4($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X4);
    // 0x800B0D7C: nop

    // 0x800B0D80: andi        $t0, $t9, 0x100
    ctx->r8 = ctx->r25 & 0X100;
    // 0x800B0D84: beq         $t0, $zero, L_800B0D98
    if (ctx->r8 == 0) {
        // 0x800B0D88: nop
    
            goto L_800B0D98;
    }
    // 0x800B0D88: nop

    // 0x800B0D8C: lh          $t1, 0xA($a2)
    ctx->r9 = MEM_H(ctx->r6, 0XA);
    // 0x800B0D90: b           L_800B0DA8
    // 0x800B0D94: sh          $t1, 0x5C($v0)
    MEM_H(0X5C, ctx->r2) = ctx->r9;
        goto L_800B0DA8;
    // 0x800B0D94: sh          $t1, 0x5C($v0)
    MEM_H(0X5C, ctx->r2) = ctx->r9;
L_800B0D98:
    // 0x800B0D98: lbu         $t2, 0xC($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0XC);
    // 0x800B0D9C: nop

    // 0x800B0DA0: sll         $t3, $t2, 8
    ctx->r11 = S32(ctx->r10 << 8);
    // 0x800B0DA4: sh          $t3, 0x5C($v0)
    MEM_H(0X5C, ctx->r2) = ctx->r11;
L_800B0DA8:
    // 0x800B0DA8: lbu         $t4, 0xC($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0XC);
    // 0x800B0DAC: nop

    // 0x800B0DB0: slti        $at, $t4, 0xFF
    ctx->r1 = SIGNED(ctx->r12) < 0XFF ? 1 : 0;
    // 0x800B0DB4: beq         $at, $zero, L_800B0DF4
    if (ctx->r1 == 0) {
        // 0x800B0DB8: nop
    
            goto L_800B0DF4;
    }
    // 0x800B0DB8: nop

    // 0x800B0DBC: lw          $t5, 0x40($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X40);
    // 0x800B0DC0: nop

    // 0x800B0DC4: andi        $t7, $t5, 0x1000
    ctx->r15 = ctx->r13 & 0X1000;
    // 0x800B0DC8: beq         $t7, $zero, L_800B0DE4
    if (ctx->r15 == 0) {
        // 0x800B0DCC: nop
    
            goto L_800B0DE4;
    }
    // 0x800B0DCC: nop

    // 0x800B0DD0: lh          $t6, 0x6($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X6);
    // 0x800B0DD4: nop

    // 0x800B0DD8: ori         $t8, $t6, 0x100
    ctx->r24 = ctx->r14 | 0X100;
    // 0x800B0DDC: b           L_800B0DF4
    // 0x800B0DE0: sh          $t8, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r24;
        goto L_800B0DF4;
    // 0x800B0DE0: sh          $t8, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r24;
L_800B0DE4:
    // 0x800B0DE4: lh          $t9, 0x6($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X6);
    // 0x800B0DE8: nop

    // 0x800B0DEC: ori         $t0, $t9, 0x80
    ctx->r8 = ctx->r25 | 0X80;
    // 0x800B0DF0: sh          $t0, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r8;
L_800B0DF4:
    // 0x800B0DF4: lh          $a1, 0x60($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X60);
    // 0x800B0DF8: lh          $a0, 0x3A($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X3A);
    // 0x800B0DFC: nop

    // 0x800B0E00: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800B0E04: beq         $at, $zero, L_800B0E58
    if (ctx->r1 == 0) {
        // 0x800B0E08: subu        $t7, $a0, $a1
        ctx->r15 = SUB32(ctx->r4, ctx->r5);
            goto L_800B0E58;
    }
    // 0x800B0E08: subu        $t7, $a0, $a1
    ctx->r15 = SUB32(ctx->r4, ctx->r5);
    // 0x800B0E0C: lbu         $t1, 0xD($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0XD);
    // 0x800B0E10: lh          $t3, 0x5C($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X5C);
    // 0x800B0E14: sll         $t2, $t1, 8
    ctx->r10 = S32(ctx->r9 << 8);
    // 0x800B0E18: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x800B0E1C: subu        $t5, $t2, $t4
    ctx->r13 = SUB32(ctx->r10, ctx->r12);
    // 0x800B0E20: div         $zero, $t5, $t7
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r15))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r15)));
    // 0x800B0E24: bne         $t7, $zero, L_800B0E30
    if (ctx->r15 != 0) {
        // 0x800B0E28: nop
    
            goto L_800B0E30;
    }
    // 0x800B0E28: nop

    // 0x800B0E2C: break       7
    do_break(2148208172);
L_800B0E30:
    // 0x800B0E30: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B0E34: bne         $t7, $at, L_800B0E48
    if (ctx->r15 != ctx->r1) {
        // 0x800B0E38: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B0E48;
    }
    // 0x800B0E38: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B0E3C: bne         $t5, $at, L_800B0E48
    if (ctx->r13 != ctx->r1) {
        // 0x800B0E40: nop
    
            goto L_800B0E48;
    }
    // 0x800B0E40: nop

    // 0x800B0E44: break       6
    do_break(2148208196);
L_800B0E48:
    // 0x800B0E48: mflo        $t6
    ctx->r14 = lo;
    // 0x800B0E4C: sh          $t6, 0x5E($v0)
    MEM_H(0X5E, ctx->r2) = ctx->r14;
    // 0x800B0E50: b           L_800B0E60
    // 0x800B0E54: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
        goto L_800B0E60;
    // 0x800B0E54: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
L_800B0E58:
    // 0x800B0E58: sh          $zero, 0x5E($v0)
    MEM_H(0X5E, ctx->r2) = 0;
    // 0x800B0E5C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
L_800B0E60:
    // 0x800B0E60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B0E64: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x800B0E68: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x800B0E6C: jal         0x800B0920
    // 0x800B0E70: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    setup_particle_position(rdram, ctx);
        goto after_1;
    // 0x800B0E70: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_1:
    // 0x800B0E74: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800B0E78: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800B0E7C: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x800B0E80: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800B0E84: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800B0E88: andi        $t9, $t8, 0x80
    ctx->r25 = ctx->r24 & 0X80;
    // 0x800B0E8C: beq         $t9, $zero, L_800B0EB8
    if (ctx->r25 == 0) {
        // 0x800B0E90: nop
    
            goto L_800B0EB8;
    }
    // 0x800B0E90: nop

    // 0x800B0E94: lh          $t0, 0x44($a3)
    ctx->r8 = MEM_H(ctx->r7, 0X44);
    // 0x800B0E98: nop

    // 0x800B0E9C: sh          $t0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r8;
    // 0x800B0EA0: lh          $t1, 0x46($a3)
    ctx->r9 = MEM_H(ctx->r7, 0X46);
    // 0x800B0EA4: nop

    // 0x800B0EA8: sh          $t1, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r9;
    // 0x800B0EAC: lh          $t3, 0x48($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X48);
    // 0x800B0EB0: b           L_800B0EF4
    // 0x800B0EB4: sh          $t3, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r11;
        goto L_800B0EF4;
    // 0x800B0EB4: sh          $t3, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r11;
L_800B0EB8:
    // 0x800B0EB8: lh          $t2, 0x0($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X0);
    // 0x800B0EBC: lh          $t4, 0x44($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X44);
    // 0x800B0EC0: nop

    // 0x800B0EC4: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x800B0EC8: sh          $t5, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r13;
    // 0x800B0ECC: lh          $t6, 0x46($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X46);
    // 0x800B0ED0: lh          $t7, 0x2($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X2);
    // 0x800B0ED4: nop

    // 0x800B0ED8: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x800B0EDC: sh          $t8, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r24;
    // 0x800B0EE0: lh          $t0, 0x48($a3)
    ctx->r8 = MEM_H(ctx->r7, 0X48);
    // 0x800B0EE4: lh          $t9, 0x4($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X4);
    // 0x800B0EE8: nop

    // 0x800B0EEC: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800B0EF0: sh          $t1, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r9;
L_800B0EF4:
    // 0x800B0EF4: lh          $t3, 0x4A($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X4A);
    // 0x800B0EF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B0EFC: sh          $t3, 0x62($s0)
    MEM_H(0X62, ctx->r16) = ctx->r11;
    // 0x800B0F00: lh          $t2, 0x4C($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X4C);
    // 0x800B0F04: nop

    // 0x800B0F08: sh          $t2, 0x64($s0)
    MEM_H(0X64, ctx->r16) = ctx->r10;
    // 0x800B0F0C: lh          $t4, 0x4E($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X4E);
    // 0x800B0F10: nop

    // 0x800B0F14: sh          $t4, 0x66($s0)
    MEM_H(0X66, ctx->r16) = ctx->r12;
    // 0x800B0F18: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x800B0F1C: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x800B0F20: jal         0x800B0570
    // 0x800B0F24: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    setup_particle_velocity(rdram, ctx);
        goto after_2;
    // 0x800B0F24: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_2:
    // 0x800B0F28: lw          $t5, 0x40($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X40);
    // 0x800B0F2C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B0F30: sra         $t7, $t5, 4
    ctx->r15 = S32(SIGNED(ctx->r13) >> 4);
    // 0x800B0F34: andi        $t6, $t7, 0x7
    ctx->r14 = ctx->r15 & 0X7;
    // 0x800B0F38: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x800B0F3C: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800B0F40: lwc1        $f18, 0x33BC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X33BC);
    // 0x800B0F44: lbu         $t9, 0x39($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X39);
    // 0x800B0F48: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800B0F4C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800B0F50: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800B0F54: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800B0F58: bne         $t9, $at, L_800B0FA0
    if (ctx->r25 != ctx->r1) {
        // 0x800B0F5C: swc1        $f18, 0x68($s0)
        MEM_W(0X68, ctx->r16) = ctx->f18.u32l;
            goto L_800B0FA0;
    }
    // 0x800B0F5C: swc1        $f18, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f18.u32l;
    // 0x800B0F60: lwc1        $f0, 0x1C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800B0F64: lwc1        $f2, 0x20($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800B0F68: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800B0F6C: lwc1        $f14, 0x24($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800B0F70: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x800B0F74: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x800B0F78: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800B0F7C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x800B0F80: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800B0F84: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B0F88: jal         0x800CA030
    // 0x800B0F8C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x800B0F8C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_3:
    // 0x800B0F90: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800B0F94: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800B0F98: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800B0F9C: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
L_800B0FA0:
    // 0x800B0FA0: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x800B0FA4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B0FA8: andi        $t0, $v0, 0x2
    ctx->r8 = ctx->r2 & 0X2;
    // 0x800B0FAC: beq         $t0, $zero, L_800B0FE4
    if (ctx->r8 == 0) {
        // 0x800B0FB0: andi        $t6, $v0, 0x8
        ctx->r14 = ctx->r2 & 0X8;
            goto L_800B0FE4;
    }
    // 0x800B0FB0: andi        $t6, $v0, 0x8
    ctx->r14 = ctx->r2 & 0X8;
    // 0x800B0FB4: lh          $t1, 0x10($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X10);
    // 0x800B0FB8: lh          $t3, 0x1C($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X1C);
    // 0x800B0FBC: lh          $t4, 0x12($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X12);
    // 0x800B0FC0: addu        $t2, $t1, $t3
    ctx->r10 = ADD32(ctx->r9, ctx->r11);
    // 0x800B0FC4: sh          $t2, 0x10($a2)
    MEM_H(0X10, ctx->r6) = ctx->r10;
    // 0x800B0FC8: lh          $t5, 0x1E($a3)
    ctx->r13 = MEM_H(ctx->r7, 0X1E);
    // 0x800B0FCC: nop

    // 0x800B0FD0: addu        $t7, $t4, $t5
    ctx->r15 = ADD32(ctx->r12, ctx->r13);
    // 0x800B0FD4: sh          $t7, 0x12($a2)
    MEM_H(0X12, ctx->r6) = ctx->r15;
    // 0x800B0FD8: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x800B0FDC: nop

    // 0x800B0FE0: andi        $t6, $v0, 0x8
    ctx->r14 = ctx->r2 & 0X8;
L_800B0FE4:
    // 0x800B0FE4: beq         $t6, $zero, L_800B1010
    if (ctx->r14 == 0) {
        // 0x800B0FE8: nop
    
            goto L_800B1010;
    }
    // 0x800B0FE8: nop

    // 0x800B0FEC: lh          $t8, 0x14($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X14);
    // 0x800B0FF0: lh          $t9, 0x2A($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X2A);
    // 0x800B0FF4: lh          $t1, 0x16($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X16);
    // 0x800B0FF8: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800B0FFC: sh          $t0, 0x14($a2)
    MEM_H(0X14, ctx->r6) = ctx->r8;
    // 0x800B1000: lh          $t3, 0x2C($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X2C);
    // 0x800B1004: nop

    // 0x800B1008: addu        $t2, $t1, $t3
    ctx->r10 = ADD32(ctx->r9, ctx->r11);
    // 0x800B100C: sh          $t2, 0x16($a2)
    MEM_H(0X16, ctx->r6) = ctx->r10;
L_800B1010:
    // 0x800B1010: lh          $t4, 0x6($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X6);
    // 0x800B1014: sh          $zero, 0x18($s0)
    MEM_H(0X18, ctx->r16) = 0;
    // 0x800B1018: sh          $t4, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r12;
    // 0x800B101C: lh          $a0, 0x4($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X4);
    // 0x800B1020: lw          $a1, 0x44($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X44);
    // 0x800B1024: bne         $a0, $at, L_800B1034
    if (ctx->r4 != ctx->r1) {
        // 0x800B1028: nop
    
            goto L_800B1034;
    }
    // 0x800B1028: nop

    // 0x800B102C: b           L_800B10C8
    // 0x800B1030: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
        goto L_800B10C8;
    // 0x800B1030: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_800B1034:
    // 0x800B1034: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x800B1038: jal         0x8007B2C4
    // 0x800B103C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    load_texture(rdram, ctx);
        goto after_4;
    // 0x800B103C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_4:
    // 0x800B1040: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800B1044: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800B1048: beq         $v0, $zero, L_800B10C8
    if (ctx->r2 == 0) {
        // 0x800B104C: sw          $v0, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r2;
            goto L_800B10C8;
    }
    // 0x800B104C: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x800B1050: lh          $t7, 0x6($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X6);
    // 0x800B1054: nop

    // 0x800B1058: andi        $t6, $t7, 0x4
    ctx->r14 = ctx->r15 & 0X4;
    // 0x800B105C: beq         $t6, $zero, L_800B109C
    if (ctx->r14 == 0) {
        // 0x800B1060: nop
    
            goto L_800B109C;
    }
    // 0x800B1060: nop

    // 0x800B1064: lw          $t8, 0x40($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X40);
    // 0x800B1068: nop

    // 0x800B106C: andi        $t9, $t8, 0x1000
    ctx->r25 = ctx->r24 & 0X1000;
    // 0x800B1070: beq         $t9, $zero, L_800B108C
    if (ctx->r25 == 0) {
        // 0x800B1074: nop
    
            goto L_800B108C;
    }
    // 0x800B1074: nop

    // 0x800B1078: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
    // 0x800B107C: nop

    // 0x800B1080: ori         $t1, $t0, 0x100
    ctx->r9 = ctx->r8 | 0X100;
    // 0x800B1084: b           L_800B109C
    // 0x800B1088: sh          $t1, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r9;
        goto L_800B109C;
    // 0x800B1088: sh          $t1, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r9;
L_800B108C:
    // 0x800B108C: lh          $t3, 0x6($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X6);
    // 0x800B1090: nop

    // 0x800B1094: ori         $t2, $t3, 0x80
    ctx->r10 = ctx->r11 | 0X80;
    // 0x800B1098: sh          $t2, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r10;
L_800B109C:
    // 0x800B109C: lw          $t4, 0x40($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X40);
    // 0x800B10A0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B10A4: andi        $t5, $t4, 0x3
    ctx->r13 = ctx->r12 & 0X3;
    // 0x800B10A8: bne         $t5, $at, L_800B10C8
    if (ctx->r13 != ctx->r1) {
        // 0x800B10AC: nop
    
            goto L_800B10C8;
    }
    // 0x800B10AC: nop

    // 0x800B10B0: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800B10B4: nop

    // 0x800B10B8: lhu         $t6, 0x12($t7)
    ctx->r14 = MEM_HU(ctx->r15, 0X12);
    // 0x800B10BC: nop

    // 0x800B10C0: addiu       $t8, $t6, -0x1
    ctx->r24 = ADD32(ctx->r14, -0X1);
    // 0x800B10C4: sh          $t8, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r24;
L_800B10C8:
    // 0x800B10C8: sb          $zero, 0x75($s0)
    MEM_B(0X75, ctx->r16) = 0;
    // 0x800B10CC: lhu         $t9, 0xA($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0XA);
    // 0x800B10D0: sb          $zero, 0x77($s0)
    MEM_B(0X77, ctx->r16) = 0;
    // 0x800B10D4: srl         $t0, $t9, 10
    ctx->r8 = S32(U32(ctx->r25) >> 10);
    // 0x800B10D8: sb          $t0, 0x76($s0)
    MEM_B(0X76, ctx->r16) = ctx->r8;
    // 0x800B10DC: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x800B10E0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800B10E4: bne         $t1, $zero, L_800B10FC
    if (ctx->r9 != 0) {
        // 0x800B10E8: nop
    
            goto L_800B10FC;
    }
    // 0x800B10E8: nop

    // 0x800B10EC: jal         0x800B25A0
    // 0x800B10F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    particle_deallocate(rdram, ctx);
        goto after_5;
    // 0x800B10F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x800B10F4: b           L_800B10FC
    // 0x800B10F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B10FC;
    // 0x800B10F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B10FC:
    // 0x800B10FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B1100: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B1104: jr          $ra
    // 0x800B1108: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800B1108: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void create_line_particle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B110C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800B1110: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B1114: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B1118: lh          $t7, 0x8($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X8);
    // 0x800B111C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800B1120: lw          $t6, 0x3280($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3280);
    // 0x800B1124: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800B1128: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800B112C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800B1130: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B1134: lbu         $t2, 0x0($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X0);
    // 0x800B1138: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800B113C: beq         $t2, $at, L_800B114C
    if (ctx->r10 == ctx->r1) {
        // 0x800B1140: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_800B114C;
    }
    // 0x800B1140: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800B1144: b           L_800B1680
    // 0x800B1148: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B1680;
    // 0x800B1148: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B114C:
    // 0x800B114C: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x800B1150: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800B1154: lw          $t1, 0x9C($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X9C);
    // 0x800B1158: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x800B115C: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    // 0x800B1160: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x800B1164: jal         0x800B2218
    // 0x800B1168: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    particle_allocate(rdram, ctx);
        goto after_0;
    // 0x800B1168: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    after_0:
    // 0x800B116C: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x800B1170: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x800B1174: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800B1178: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800B117C: bne         $v0, $zero, L_800B118C
    if (ctx->r2 != 0) {
        // 0x800B1180: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_800B118C;
    }
    // 0x800B1180: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800B1184: b           L_800B1680
    // 0x800B1188: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B1680;
    // 0x800B1188: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B118C:
    // 0x800B118C: lh          $t3, 0x2E($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X2E);
    // 0x800B1190: addiu       $t4, $zero, -0x8000
    ctx->r12 = ADD32(0, -0X8000);
    // 0x800B1194: sh          $t4, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r12;
    // 0x800B1198: sh          $t3, 0x2E($v0)
    MEM_H(0X2E, ctx->r2) = ctx->r11;
    // 0x800B119C: lbu         $t5, 0x1($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X1);
    // 0x800B11A0: nop

    // 0x800B11A4: sb          $t5, 0x39($v0)
    MEM_B(0X39, ctx->r2) = ctx->r13;
    // 0x800B11A8: lhu         $t7, 0x2($t0)
    ctx->r15 = MEM_HU(ctx->r8, 0X2);
    // 0x800B11AC: sw          $s0, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r16;
    // 0x800B11B0: sw          $a2, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->r6;
    // 0x800B11B4: sw          $t7, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r15;
    // 0x800B11B8: lwc1        $f4, 0x10($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X10);
    // 0x800B11BC: lwc1        $f6, 0x50($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X50);
    // 0x800B11C0: nop

    // 0x800B11C4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800B11C8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B11CC: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x800B11D0: lwc1        $f16, 0x54($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X54);
    // 0x800B11D4: lwc1        $f10, 0x10($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X10);
    // 0x800B11D8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B11DC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800B11E0: swc1        $f18, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f18.u32l;
    // 0x800B11E4: lh          $t6, 0x8($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X8);
    // 0x800B11E8: sb          $zero, 0x38($v0)
    MEM_B(0X38, ctx->r2) = 0;
    // 0x800B11EC: swc1        $f4, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f4.u32l;
    // 0x800B11F0: sh          $t6, 0x3A($v0)
    MEM_H(0X3A, ctx->r2) = ctx->r14;
    // 0x800B11F4: lw          $v1, 0x3290($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3290);
    // 0x800B11F8: nop

    // 0x800B11FC: beq         $v1, $zero, L_800B120C
    if (ctx->r3 == 0) {
        // 0x800B1200: nop
    
            goto L_800B120C;
    }
    // 0x800B1200: nop

    // 0x800B1204: b           L_800B1230
    // 0x800B1208: sw          $v1, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->r3;
        goto L_800B1230;
    // 0x800B1208: sw          $v1, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->r3;
L_800B120C:
    // 0x800B120C: lbu         $t8, 0x14($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X14);
    // 0x800B1210: nop

    // 0x800B1214: sb          $t8, 0x6C($v0)
    MEM_B(0X6C, ctx->r2) = ctx->r24;
    // 0x800B1218: lbu         $t9, 0x15($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X15);
    // 0x800B121C: nop

    // 0x800B1220: sb          $t9, 0x6D($v0)
    MEM_B(0X6D, ctx->r2) = ctx->r25;
    // 0x800B1224: lbu         $t2, 0x16($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X16);
    // 0x800B1228: nop

    // 0x800B122C: sb          $t2, 0x6E($v0)
    MEM_B(0X6E, ctx->r2) = ctx->r10;
L_800B1230:
    // 0x800B1230: lw          $t4, 0x40($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X40);
    // 0x800B1234: lbu         $t3, 0x17($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X17);
    // 0x800B1238: andi        $t5, $t4, 0x800
    ctx->r13 = ctx->r12 & 0X800;
    // 0x800B123C: beq         $t5, $zero, L_800B1290
    if (ctx->r13 == 0) {
        // 0x800B1240: sb          $t3, 0x6F($v0)
        MEM_B(0X6F, ctx->r2) = ctx->r11;
            goto L_800B1290;
    }
    // 0x800B1240: sb          $t3, 0x6F($v0)
    MEM_B(0X6F, ctx->r2) = ctx->r11;
    // 0x800B1244: lw          $v1, 0x54($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X54);
    // 0x800B1248: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800B124C: beq         $v1, $zero, L_800B1290
    if (ctx->r3 == 0) {
        // 0x800B1250: nop
    
            goto L_800B1290;
    }
    // 0x800B1250: nop

    // 0x800B1254: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800B1258: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B125C: nop

    // 0x800B1260: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800B1264: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800B1268: nop

    // 0x800B126C: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800B1270: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B1274: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B1278: nop

    // 0x800B127C: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800B1280: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    // 0x800B1284: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800B1288: b           L_800B1298
    // 0x800B128C: sh          $t6, 0x4A($v0)
    MEM_H(0X4A, ctx->r2) = ctx->r14;
        goto L_800B1298;
    // 0x800B128C: sh          $t6, 0x4A($v0)
    MEM_H(0X4A, ctx->r2) = ctx->r14;
L_800B1290:
    // 0x800B1290: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800B1294: sh          $t8, 0x4A($v0)
    MEM_H(0X4A, ctx->r2) = ctx->r24;
L_800B1298:
    // 0x800B1298: lh          $t9, 0xE($t0)
    ctx->r25 = MEM_H(ctx->r8, 0XE);
    // 0x800B129C: nop

    // 0x800B12A0: sh          $t9, 0x60($v0)
    MEM_H(0X60, ctx->r2) = ctx->r25;
    // 0x800B12A4: lbu         $t2, 0xC($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0XC);
    // 0x800B12A8: nop

    // 0x800B12AC: sll         $t3, $t2, 8
    ctx->r11 = S32(ctx->r10 << 8);
    // 0x800B12B0: sh          $t3, 0x5C($v0)
    MEM_H(0X5C, ctx->r2) = ctx->r11;
    // 0x800B12B4: lbu         $t4, 0xC($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0XC);
    // 0x800B12B8: nop

    // 0x800B12BC: slti        $at, $t4, 0xFF
    ctx->r1 = SIGNED(ctx->r12) < 0XFF ? 1 : 0;
    // 0x800B12C0: beq         $at, $zero, L_800B1300
    if (ctx->r1 == 0) {
        // 0x800B12C4: nop
    
            goto L_800B1300;
    }
    // 0x800B12C4: nop

    // 0x800B12C8: lw          $t5, 0x40($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X40);
    // 0x800B12CC: nop

    // 0x800B12D0: andi        $t7, $t5, 0x1000
    ctx->r15 = ctx->r13 & 0X1000;
    // 0x800B12D4: beq         $t7, $zero, L_800B12F0
    if (ctx->r15 == 0) {
        // 0x800B12D8: nop
    
            goto L_800B12F0;
    }
    // 0x800B12D8: nop

    // 0x800B12DC: lh          $t6, 0x6($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X6);
    // 0x800B12E0: nop

    // 0x800B12E4: ori         $t8, $t6, 0x100
    ctx->r24 = ctx->r14 | 0X100;
    // 0x800B12E8: b           L_800B1300
    // 0x800B12EC: sh          $t8, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r24;
        goto L_800B1300;
    // 0x800B12EC: sh          $t8, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r24;
L_800B12F0:
    // 0x800B12F0: lh          $t9, 0x6($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X6);
    // 0x800B12F4: nop

    // 0x800B12F8: ori         $t2, $t9, 0x80
    ctx->r10 = ctx->r25 | 0X80;
    // 0x800B12FC: sh          $t2, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r10;
L_800B1300:
    // 0x800B1300: lh          $a0, 0x60($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X60);
    // 0x800B1304: lh          $v1, 0x3A($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X3A);
    // 0x800B1308: nop

    // 0x800B130C: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800B1310: beq         $at, $zero, L_800B1364
    if (ctx->r1 == 0) {
        // 0x800B1314: nop
    
            goto L_800B1364;
    }
    // 0x800B1314: nop

    // 0x800B1318: lbu         $t3, 0xD($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0XD);
    // 0x800B131C: lbu         $t4, 0xC($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0XC);
    // 0x800B1320: subu        $t6, $v1, $a0
    ctx->r14 = SUB32(ctx->r3, ctx->r4);
    // 0x800B1324: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x800B1328: sll         $t7, $t5, 8
    ctx->r15 = S32(ctx->r13 << 8);
    // 0x800B132C: div         $zero, $t7, $t6
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r14))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r14)));
    // 0x800B1330: bne         $t6, $zero, L_800B133C
    if (ctx->r14 != 0) {
        // 0x800B1334: nop
    
            goto L_800B133C;
    }
    // 0x800B1334: nop

    // 0x800B1338: break       7
    do_break(2148209464);
L_800B133C:
    // 0x800B133C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B1340: bne         $t6, $at, L_800B1354
    if (ctx->r14 != ctx->r1) {
        // 0x800B1344: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B1354;
    }
    // 0x800B1344: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B1348: bne         $t7, $at, L_800B1354
    if (ctx->r15 != ctx->r1) {
        // 0x800B134C: nop
    
            goto L_800B1354;
    }
    // 0x800B134C: nop

    // 0x800B1350: break       6
    do_break(2148209488);
L_800B1354:
    // 0x800B1354: mflo        $t8
    ctx->r24 = lo;
    // 0x800B1358: sh          $t8, 0x5E($v0)
    MEM_H(0X5E, ctx->r2) = ctx->r24;
    // 0x800B135C: b           L_800B136C
    // 0x800B1360: lh          $t9, 0x18($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X18);
        goto L_800B136C;
    // 0x800B1360: lh          $t9, 0x18($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X18);
L_800B1364:
    // 0x800B1364: sh          $zero, 0x5E($v0)
    MEM_H(0X5E, ctx->r2) = 0;
    // 0x800B1368: lh          $t9, 0x18($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X18);
L_800B136C:
    // 0x800B136C: lh          $t2, 0x1A($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X1A);
    // 0x800B1370: lh          $t3, 0x1C($a2)
    ctx->r11 = MEM_H(ctx->r6, 0X1C);
    // 0x800B1374: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x800B1378: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x800B137C: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x800B1380: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800B1384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B1388: addiu       $a1, $a2, 0xC
    ctx->r5 = ADD32(ctx->r6, 0XC);
    // 0x800B138C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800B1390: swc1        $f4, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f4.u32l;
    // 0x800B1394: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800B1398: swc1        $f8, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f8.u32l;
    // 0x800B139C: swc1        $f16, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f16.u32l;
    // 0x800B13A0: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x800B13A4: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x800B13A8: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x800B13AC: jal         0x80070560
    // 0x800B13B0: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    vec3f_rotate(rdram, ctx);
        goto after_1;
    // 0x800B13B0: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    after_1:
    // 0x800B13B4: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x800B13B8: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800B13BC: lwc1        $f18, 0xC($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0XC);
    // 0x800B13C0: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800B13C4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800B13C8: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800B13CC: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800B13D0: swc1        $f6, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f6.u32l;
    // 0x800B13D4: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800B13D8: lwc1        $f8, 0x10($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800B13DC: lwc1        $f18, 0x14($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800B13E0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800B13E4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800B13E8: swc1        $f16, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f16.u32l;
    // 0x800B13EC: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800B13F0: nop

    // 0x800B13F4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800B13F8: swc1        $f6, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f6.u32l;
    // 0x800B13FC: sb          $zero, 0x68($a3)
    MEM_B(0X68, ctx->r7) = 0;
    // 0x800B1400: sb          $zero, 0x6A($a3)
    MEM_B(0X6A, ctx->r7) = 0;
    // 0x800B1404: sb          $v0, 0x6B($a3)
    MEM_B(0X6B, ctx->r7) = ctx->r2;
    // 0x800B1408: lh          $t4, 0x6($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X6);
    // 0x800B140C: sh          $zero, 0x18($a3)
    MEM_H(0X18, ctx->r7) = 0;
    // 0x800B1410: sh          $t4, 0x1A($a3)
    MEM_H(0X1A, ctx->r7) = ctx->r12;
    // 0x800B1414: lh          $a0, 0x4($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X4);
    // 0x800B1418: lw          $v1, 0x44($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X44);
    // 0x800B141C: bne         $v0, $a0, L_800B142C
    if (ctx->r2 != ctx->r4) {
        // 0x800B1420: nop
    
            goto L_800B142C;
    }
    // 0x800B1420: nop

    // 0x800B1424: b           L_800B14D8
    // 0x800B1428: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_800B14D8;
    // 0x800B1428: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_800B142C:
    // 0x800B142C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x800B1430: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    // 0x800B1434: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x800B1438: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x800B143C: jal         0x8007B2C4
    // 0x800B1440: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    load_texture(rdram, ctx);
        goto after_2;
    // 0x800B1440: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    after_2:
    // 0x800B1444: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800B1448: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x800B144C: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800B1450: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800B1454: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800B1458: beq         $v0, $zero, L_800B14D8
    if (ctx->r2 == 0) {
        // 0x800B145C: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_800B14D8;
    }
    // 0x800B145C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800B1460: lh          $t7, 0x6($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X6);
    // 0x800B1464: nop

    // 0x800B1468: andi        $t6, $t7, 0x4
    ctx->r14 = ctx->r15 & 0X4;
    // 0x800B146C: beq         $t6, $zero, L_800B14AC
    if (ctx->r14 == 0) {
        // 0x800B1470: nop
    
            goto L_800B14AC;
    }
    // 0x800B1470: nop

    // 0x800B1474: lw          $t8, 0x40($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X40);
    // 0x800B1478: nop

    // 0x800B147C: andi        $t9, $t8, 0x1000
    ctx->r25 = ctx->r24 & 0X1000;
    // 0x800B1480: beq         $t9, $zero, L_800B149C
    if (ctx->r25 == 0) {
        // 0x800B1484: nop
    
            goto L_800B149C;
    }
    // 0x800B1484: nop

    // 0x800B1488: lh          $t2, 0x6($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X6);
    // 0x800B148C: nop

    // 0x800B1490: ori         $t3, $t2, 0x100
    ctx->r11 = ctx->r10 | 0X100;
    // 0x800B1494: b           L_800B14AC
    // 0x800B1498: sh          $t3, 0x6($a3)
    MEM_H(0X6, ctx->r7) = ctx->r11;
        goto L_800B14AC;
    // 0x800B1498: sh          $t3, 0x6($a3)
    MEM_H(0X6, ctx->r7) = ctx->r11;
L_800B149C:
    // 0x800B149C: lh          $t4, 0x6($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X6);
    // 0x800B14A0: nop

    // 0x800B14A4: ori         $t5, $t4, 0x80
    ctx->r13 = ctx->r12 | 0X80;
    // 0x800B14A8: sh          $t5, 0x6($a3)
    MEM_H(0X6, ctx->r7) = ctx->r13;
L_800B14AC:
    // 0x800B14AC: lw          $t7, 0x40($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X40);
    // 0x800B14B0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B14B4: andi        $t6, $t7, 0x3
    ctx->r14 = ctx->r15 & 0X3;
    // 0x800B14B8: bne         $t6, $at, L_800B14D8
    if (ctx->r14 != ctx->r1) {
        // 0x800B14BC: nop
    
            goto L_800B14D8;
    }
    // 0x800B14BC: nop

    // 0x800B14C0: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800B14C4: nop

    // 0x800B14C8: lhu         $t9, 0x12($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X12);
    // 0x800B14CC: nop

    // 0x800B14D0: addiu       $t2, $t9, -0x1
    ctx->r10 = ADD32(ctx->r25, -0X1);
    // 0x800B14D4: sh          $t2, 0x18($a3)
    MEM_H(0X18, ctx->r7) = ctx->r10;
L_800B14D8:
    // 0x800B14D8: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800B14DC: lwc1        $f8, 0xC($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0XC);
    // 0x800B14E0: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800B14E4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B14E8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B14EC: lw          $t5, 0x8($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X8);
    // 0x800B14F0: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800B14F4: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800B14F8: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x800B14FC: nop

    // 0x800B1500: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800B1504: sh          $t4, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r12;
    // 0x800B1508: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800B150C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B1510: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B1514: lwc1        $f16, 0x10($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800B1518: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x800B151C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B1520: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800B1524: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x800B1528: nop

    // 0x800B152C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800B1530: sh          $t6, 0x2($t8)
    MEM_H(0X2, ctx->r24) = ctx->r14;
    // 0x800B1534: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800B1538: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B153C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B1540: lwc1        $f4, 0x14($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800B1544: lw          $t3, 0x8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X8);
    // 0x800B1548: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800B154C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B1550: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x800B1554: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800B1558: beq         $t1, $at, L_800B15F4
    if (ctx->r9 == ctx->r1) {
        // 0x800B155C: sh          $t2, 0x4($t3)
        MEM_H(0X4, ctx->r11) = ctx->r10;
            goto L_800B15F4;
    }
    // 0x800B155C: sh          $t2, 0x4($t3)
    MEM_H(0X4, ctx->r11) = ctx->r10;
    // 0x800B1560: lh          $t4, 0x1E($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X1E);
    // 0x800B1564: nop

    // 0x800B1568: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800B156C: sh          $t5, 0x1E($a2)
    MEM_H(0X1E, ctx->r6) = ctx->r13;
    // 0x800B1570: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800B1574: lh          $v0, 0x1E($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X1E);
    // 0x800B1578: nop

    // 0x800B157C: slt         $at, $v0, $t7
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800B1580: bne         $at, $zero, L_800B1598
    if (ctx->r1 != 0) {
        // 0x800B1584: sll         $t6, $v0, 3
        ctx->r14 = S32(ctx->r2 << 3);
            goto L_800B1598;
    }
    // 0x800B1584: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x800B1588: sh          $zero, 0x1E($a2)
    MEM_H(0X1E, ctx->r6) = 0;
    // 0x800B158C: lh          $v0, 0x1E($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X1E);
    // 0x800B1590: nop

    // 0x800B1594: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
L_800B1598:
    // 0x800B1598: addu        $t8, $t1, $t6
    ctx->r24 = ADD32(ctx->r9, ctx->r14);
    // 0x800B159C: lbu         $t9, 0x14($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X14);
    // 0x800B15A0: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x800B15A4: nop

    // 0x800B15A8: sb          $t9, 0x6($t2)
    MEM_B(0X6, ctx->r10) = ctx->r25;
    // 0x800B15AC: lh          $t3, 0x1E($a2)
    ctx->r11 = MEM_H(ctx->r6, 0X1E);
    // 0x800B15B0: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
    // 0x800B15B4: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x800B15B8: addu        $t5, $t1, $t4
    ctx->r13 = ADD32(ctx->r9, ctx->r12);
    // 0x800B15BC: lbu         $t7, 0x15($t5)
    ctx->r15 = MEM_BU(ctx->r13, 0X15);
    // 0x800B15C0: nop

    // 0x800B15C4: sb          $t7, 0x7($t6)
    MEM_B(0X7, ctx->r14) = ctx->r15;
    // 0x800B15C8: lh          $t8, 0x1E($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X1E);
    // 0x800B15CC: lw          $t4, 0x8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X8);
    // 0x800B15D0: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800B15D4: addu        $t2, $t1, $t9
    ctx->r10 = ADD32(ctx->r9, ctx->r25);
    // 0x800B15D8: lbu         $t3, 0x16($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X16);
    // 0x800B15DC: nop

    // 0x800B15E0: sb          $t3, 0x8($t4)
    MEM_B(0X8, ctx->r12) = ctx->r11;
    // 0x800B15E4: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x800B15E8: lbu         $t5, 0x6($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X6);
    // 0x800B15EC: b           L_800B1634
    // 0x800B15F0: sb          $t5, 0x9($t7)
    MEM_B(0X9, ctx->r15) = ctx->r13;
        goto L_800B1634;
    // 0x800B15F0: sb          $t5, 0x9($t7)
    MEM_B(0X9, ctx->r15) = ctx->r13;
L_800B15F4:
    // 0x800B15F4: lbu         $t6, 0x6C($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X6C);
    // 0x800B15F8: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x800B15FC: nop

    // 0x800B1600: sb          $t6, 0x6($t8)
    MEM_B(0X6, ctx->r24) = ctx->r14;
    // 0x800B1604: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x800B1608: lbu         $t9, 0x6D($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X6D);
    // 0x800B160C: nop

    // 0x800B1610: sb          $t9, 0x7($t2)
    MEM_B(0X7, ctx->r10) = ctx->r25;
    // 0x800B1614: lw          $t4, 0x8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X8);
    // 0x800B1618: lbu         $t3, 0x6E($a3)
    ctx->r11 = MEM_BU(ctx->r7, 0X6E);
    // 0x800B161C: nop

    // 0x800B1620: sb          $t3, 0x8($t4)
    MEM_B(0X8, ctx->r12) = ctx->r11;
    // 0x800B1624: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x800B1628: lbu         $t5, 0x6($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X6);
    // 0x800B162C: nop

    // 0x800B1630: sb          $t5, 0x9($t7)
    MEM_B(0X9, ctx->r15) = ctx->r13;
L_800B1634:
    // 0x800B1634: lhu         $t6, 0xA($t0)
    ctx->r14 = MEM_HU(ctx->r8, 0XA);
    // 0x800B1638: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x800B163C: srl         $t8, $t6, 10
    ctx->r24 = S32(U32(ctx->r14) >> 10);
    // 0x800B1640: sb          $t8, 0x6A($a3)
    MEM_B(0X6A, ctx->r7) = ctx->r24;
    // 0x800B1644: lw          $t9, 0x8($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X8);
    // 0x800B1648: nop

    // 0x800B164C: sll         $t2, $t9, 22
    ctx->r10 = S32(ctx->r25 << 22);
    // 0x800B1650: srl         $t3, $t2, 26
    ctx->r11 = S32(U32(ctx->r10) >> 26);
    // 0x800B1654: sb          $t3, 0x6B($a3)
    MEM_B(0X6B, ctx->r7) = ctx->r11;
    // 0x800B1658: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800B165C: nop

    // 0x800B1660: swc1        $f8, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f8.u32l;
    // 0x800B1664: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800B1668: nop

    // 0x800B166C: swc1        $f10, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f10.u32l;
    // 0x800B1670: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800B1674: nop

    // 0x800B1678: swc1        $f16, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f16.u32l;
    // 0x800B167C: sh          $zero, 0xA($a2)
    MEM_H(0XA, ctx->r6) = 0;
L_800B1680:
    // 0x800B1680: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B1684: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B1688: jr          $ra
    // 0x800B168C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800B168C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void create_general_particle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B1690: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800B1694: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B1698: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800B169C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800B16A0: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800B16A4: lh          $t7, 0x8($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X8);
    // 0x800B16A8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800B16AC: lw          $t6, 0x3280($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3280);
    // 0x800B16B0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800B16B4: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800B16B8: lw          $a3, 0x0($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X0);
    // 0x800B16BC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B16C0: lbu         $a2, 0x0($a3)
    ctx->r6 = MEM_BU(ctx->r7, 0X0);
    // 0x800B16C4: nop

    // 0x800B16C8: beq         $a2, $at, L_800B16D8
    if (ctx->r6 == ctx->r1) {
        // 0x800B16CC: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800B16D8;
    }
    // 0x800B16CC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800B16D0: bne         $a2, $at, L_800B16E0
    if (ctx->r6 != ctx->r1) {
        // 0x800B16D4: nop
    
            goto L_800B16E0;
    }
    // 0x800B16D4: nop

L_800B16D8:
    // 0x800B16D8: b           L_800B2204
    // 0x800B16DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B2204;
    // 0x800B16DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B16E0:
    // 0x800B16E0: lw          $s1, 0x0($a1)
    ctx->r17 = MEM_W(ctx->r5, 0X0);
    // 0x800B16E4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800B16E8: lw          $t0, 0x9C($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X9C);
    // 0x800B16EC: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x800B16F0: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800B16F4: jal         0x800B2218
    // 0x800B16F8: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    particle_allocate(rdram, ctx);
        goto after_0;
    // 0x800B16F8: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    after_0:
    // 0x800B16FC: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800B1700: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800B1704: bne         $v0, $zero, L_800B1714
    if (ctx->r2 != 0) {
        // 0x800B1708: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800B1714;
    }
    // 0x800B1708: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B170C: b           L_800B2204
    // 0x800B1710: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_800B2204;
    // 0x800B1710: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_800B1714:
    // 0x800B1714: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800B1718: addiu       $t3, $zero, -0x8000
    ctx->r11 = ADD32(0, -0X8000);
    // 0x800B171C: lh          $t2, 0x2E($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X2E);
    // 0x800B1720: sh          $t3, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r11;
    // 0x800B1724: sh          $t2, 0x2E($v0)
    MEM_H(0X2E, ctx->r2) = ctx->r10;
    // 0x800B1728: lbu         $t4, 0x1($a3)
    ctx->r12 = MEM_BU(ctx->r7, 0X1);
    // 0x800B172C: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800B1730: sb          $t4, 0x39($v0)
    MEM_B(0X39, ctx->r2) = ctx->r12;
    // 0x800B1734: lhu         $t5, 0x2($a3)
    ctx->r13 = MEM_HU(ctx->r7, 0X2);
    // 0x800B1738: sw          $t1, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r9;
    // 0x800B173C: andi        $t6, $t5, 0x800
    ctx->r14 = ctx->r13 & 0X800;
    // 0x800B1740: beq         $t6, $zero, L_800B1794
    if (ctx->r14 == 0) {
        // 0x800B1744: sw          $t5, 0x40($v0)
        MEM_W(0X40, ctx->r2) = ctx->r13;
            goto L_800B1794;
    }
    // 0x800B1744: sw          $t5, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r13;
    // 0x800B1748: lw          $v1, 0x54($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X54);
    // 0x800B174C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800B1750: beq         $v1, $zero, L_800B1794
    if (ctx->r3 == 0) {
        // 0x800B1754: nop
    
            goto L_800B1794;
    }
    // 0x800B1754: nop

    // 0x800B1758: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800B175C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B1760: nop

    // 0x800B1764: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800B1768: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800B176C: nop

    // 0x800B1770: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800B1774: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B1778: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B177C: nop

    // 0x800B1780: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800B1784: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800B1788: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800B178C: b           L_800B1798
    // 0x800B1790: sh          $t9, 0x4A($v0)
    MEM_H(0X4A, ctx->r2) = ctx->r25;
        goto L_800B1798;
    // 0x800B1790: sh          $t9, 0x4A($v0)
    MEM_H(0X4A, ctx->r2) = ctx->r25;
L_800B1794:
    // 0x800B1794: sh          $t2, 0x4A($v0)
    MEM_H(0X4A, ctx->r2) = ctx->r10;
L_800B1798:
    // 0x800B1798: lw          $t3, 0x5C($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X5C);
    // 0x800B179C: lwc1        $f16, 0x50($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X50);
    // 0x800B17A0: sll         $t4, $t3, 14
    ctx->r12 = S32(ctx->r11 << 14);
    // 0x800B17A4: bgez        $t4, L_800B17FC
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800B17A8: nop
    
            goto L_800B17FC;
    }
    // 0x800B17A8: nop

    // 0x800B17AC: lw          $a1, 0x8C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X8C);
    // 0x800B17B0: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x800B17B4: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800B17B8: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x800B17BC: jal         0x8006FB8C
    // 0x800B17C0: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_1;
    // 0x800B17C0: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_1:
    // 0x800B17C4: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x800B17C8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B17CC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800B17D0: lwc1        $f9, -0x6EB8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X6EB8);
    // 0x800B17D4: lwc1        $f8, -0x6EB4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X6EB4);
    // 0x800B17D8: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800B17DC: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800B17E0: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800B17E4: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800B17E8: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800B17EC: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800B17F0: add.d       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f18.d + ctx->f10.d;
    // 0x800B17F4: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800B17F8: cvt.s.d     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f16.fl = CVT_S_D(ctx->f4.d);
L_800B17FC:
    // 0x800B17FC: lwc1        $f6, 0x10($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X10);
    // 0x800B1800: nop

    // 0x800B1804: mul.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800B1808: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x800B180C: lw          $t5, 0x5C($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X5C);
    // 0x800B1810: lwc1        $f16, 0x54($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X54);
    // 0x800B1814: sll         $t7, $t5, 13
    ctx->r15 = S32(ctx->r13 << 13);
    // 0x800B1818: bgez        $t7, L_800B1870
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800B181C: nop
    
            goto L_800B1870;
    }
    // 0x800B181C: nop

    // 0x800B1820: lw          $a1, 0x90($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X90);
    // 0x800B1824: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x800B1828: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800B182C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x800B1830: jal         0x8006FB8C
    // 0x800B1834: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_2;
    // 0x800B1834: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_2:
    // 0x800B1838: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x800B183C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B1840: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800B1844: lwc1        $f7, -0x6EB0($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X6EB0);
    // 0x800B1848: lwc1        $f6, -0x6EAC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X6EAC);
    // 0x800B184C: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x800B1850: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800B1854: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800B1858: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800B185C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800B1860: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800B1864: add.d       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f18.d + ctx->f8.d;
    // 0x800B1868: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800B186C: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
L_800B1870:
    // 0x800B1870: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800B1874: nop

    // 0x800B1878: andi        $t8, $t6, 0x1000
    ctx->r24 = ctx->r14 & 0X1000;
    // 0x800B187C: beq         $t8, $zero, L_800B18D8
    if (ctx->r24 == 0) {
        // 0x800B1880: nop
    
            goto L_800B18D8;
    }
    // 0x800B1880: nop

    // 0x800B1884: lwc1        $f0, 0x1C($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X1C);
    // 0x800B1888: lwc1        $f2, 0x20($t1)
    ctx->f2.u32l = MEM_W(ctx->r9, 0X20);
    // 0x800B188C: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800B1890: lwc1        $f14, 0x24($t1)
    ctx->f14.u32l = MEM_W(ctx->r9, 0X24);
    // 0x800B1894: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x800B1898: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800B189C: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800B18A0: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x800B18A4: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800B18A8: add.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B18AC: jal         0x800CA030
    // 0x800B18B0: add.s       $f12, $f18, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x800B18B0: add.s       $f12, $f18, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f8.fl;
    after_3:
    // 0x800B18B4: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800B18B8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B18BC: mul.s       $f10, $f0, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800B18C0: lwc1        $f4, -0x6EA8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6EA8);
    // 0x800B18C4: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800B18C8: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800B18CC: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800B18D0: b           L_800B18E8
    // 0x800B18D4: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
        goto L_800B18E8;
    // 0x800B18D4: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
L_800B18D8:
    // 0x800B18D8: lwc1        $f18, 0x10($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X10);
    // 0x800B18DC: nop

    // 0x800B18E0: mul.s       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800B18E4: swc1        $f8, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f8.u32l;
L_800B18E8:
    // 0x800B18E8: lh          $a1, 0xA($a3)
    ctx->r5 = MEM_H(ctx->r7, 0XA);
    // 0x800B18EC: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800B18F0: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x800B18F4: jal         0x8006FB8C
    // 0x800B18F8: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_4;
    // 0x800B18F8: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_4:
    // 0x800B18FC: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800B1900: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B1904: lh          $t9, 0x8($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X8);
    // 0x800B1908: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800B190C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B1910: addu        $t2, $v0, $t9
    ctx->r10 = ADD32(ctx->r2, ctx->r25);
    // 0x800B1914: sh          $t2, 0x3A($s0)
    MEM_H(0X3A, ctx->r16) = ctx->r10;
    // 0x800B1918: sb          $zero, 0x38($s0)
    MEM_B(0X38, ctx->r16) = 0;
    // 0x800B191C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B1920: swc1        $f10, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f10.u32l;
    // 0x800B1924: lw          $v1, 0x3290($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3290);
    // 0x800B1928: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B192C: beq         $v1, $zero, L_800B193C
    if (ctx->r3 == 0) {
        // 0x800B1930: nop
    
            goto L_800B193C;
    }
    // 0x800B1930: nop

    // 0x800B1934: b           L_800B1A10
    // 0x800B1938: sw          $v1, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->r3;
        goto L_800B1A10;
    // 0x800B1938: sw          $v1, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->r3;
L_800B193C:
    // 0x800B193C: beq         $t0, $at, L_800B19E0
    if (ctx->r8 == ctx->r1) {
        // 0x800B1940: nop
    
            goto L_800B19E0;
    }
    // 0x800B1940: nop

    // 0x800B1944: lh          $t3, 0x1E($a2)
    ctx->r11 = MEM_H(ctx->r6, 0X1E);
    // 0x800B1948: nop

    // 0x800B194C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800B1950: sh          $t4, 0x1E($a2)
    MEM_H(0X1E, ctx->r6) = ctx->r12;
    // 0x800B1954: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x800B1958: lh          $v0, 0x1E($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X1E);
    // 0x800B195C: nop

    // 0x800B1960: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800B1964: bne         $at, $zero, L_800B197C
    if (ctx->r1 != 0) {
        // 0x800B1968: sll         $t7, $v0, 3
        ctx->r15 = S32(ctx->r2 << 3);
            goto L_800B197C;
    }
    // 0x800B1968: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x800B196C: sh          $zero, 0x1E($a2)
    MEM_H(0X1E, ctx->r6) = 0;
    // 0x800B1970: lh          $v0, 0x1E($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X1E);
    // 0x800B1974: nop

    // 0x800B1978: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
L_800B197C:
    // 0x800B197C: addu        $t6, $t0, $t7
    ctx->r14 = ADD32(ctx->r8, ctx->r15);
    // 0x800B1980: lbu         $t8, 0x14($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X14);
    // 0x800B1984: nop

    // 0x800B1988: sb          $t8, 0x6C($s0)
    MEM_B(0X6C, ctx->r16) = ctx->r24;
    // 0x800B198C: lh          $t9, 0x1E($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X1E);
    // 0x800B1990: nop

    // 0x800B1994: sll         $t2, $t9, 3
    ctx->r10 = S32(ctx->r25 << 3);
    // 0x800B1998: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x800B199C: lbu         $t4, 0x15($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X15);
    // 0x800B19A0: nop

    // 0x800B19A4: sb          $t4, 0x6D($s0)
    MEM_B(0X6D, ctx->r16) = ctx->r12;
    // 0x800B19A8: lh          $t5, 0x1E($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X1E);
    // 0x800B19AC: nop

    // 0x800B19B0: sll         $t7, $t5, 3
    ctx->r15 = S32(ctx->r13 << 3);
    // 0x800B19B4: addu        $t6, $t0, $t7
    ctx->r14 = ADD32(ctx->r8, ctx->r15);
    // 0x800B19B8: lbu         $t8, 0x16($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X16);
    // 0x800B19BC: nop

    // 0x800B19C0: sb          $t8, 0x6E($s0)
    MEM_B(0X6E, ctx->r16) = ctx->r24;
    // 0x800B19C4: lh          $t9, 0x1E($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X1E);
    // 0x800B19C8: nop

    // 0x800B19CC: sll         $t2, $t9, 3
    ctx->r10 = S32(ctx->r25 << 3);
    // 0x800B19D0: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x800B19D4: lbu         $t4, 0x17($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X17);
    // 0x800B19D8: b           L_800B1A10
    // 0x800B19DC: sb          $t4, 0x6F($s0)
    MEM_B(0X6F, ctx->r16) = ctx->r12;
        goto L_800B1A10;
    // 0x800B19DC: sb          $t4, 0x6F($s0)
    MEM_B(0X6F, ctx->r16) = ctx->r12;
L_800B19E0:
    // 0x800B19E0: lbu         $t5, 0x14($a3)
    ctx->r13 = MEM_BU(ctx->r7, 0X14);
    // 0x800B19E4: nop

    // 0x800B19E8: sb          $t5, 0x6C($s0)
    MEM_B(0X6C, ctx->r16) = ctx->r13;
    // 0x800B19EC: lbu         $t7, 0x15($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X15);
    // 0x800B19F0: nop

    // 0x800B19F4: sb          $t7, 0x6D($s0)
    MEM_B(0X6D, ctx->r16) = ctx->r15;
    // 0x800B19F8: lbu         $t6, 0x16($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X16);
    // 0x800B19FC: nop

    // 0x800B1A00: sb          $t6, 0x6E($s0)
    MEM_B(0X6E, ctx->r16) = ctx->r14;
    // 0x800B1A04: lbu         $t8, 0x17($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X17);
    // 0x800B1A08: nop

    // 0x800B1A0C: sb          $t8, 0x6F($s0)
    MEM_B(0X6F, ctx->r16) = ctx->r24;
L_800B1A10:
    // 0x800B1A10: lw          $v1, 0x5C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X5C);
    // 0x800B1A14: lui         $at, 0xF0
    ctx->r1 = S32(0XF0 << 16);
    // 0x800B1A18: and         $t9, $v1, $at
    ctx->r25 = ctx->r3 & ctx->r1;
    // 0x800B1A1C: beq         $t9, $zero, L_800B1AFC
    if (ctx->r25 == 0) {
        // 0x800B1A20: or          $v1, $t9, $zero
        ctx->r3 = ctx->r25 | 0;
            goto L_800B1AFC;
    }
    // 0x800B1A20: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x800B1A24: sll         $t2, $t9, 11
    ctx->r10 = S32(ctx->r25 << 11);
    // 0x800B1A28: bgez        $t2, L_800B1A60
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800B1A2C: sll         $t5, $v1, 10
        ctx->r13 = S32(ctx->r3 << 10);
            goto L_800B1A60;
    }
    // 0x800B1A2C: sll         $t5, $v1, 10
    ctx->r13 = S32(ctx->r3 << 10);
    // 0x800B1A30: lbu         $a1, 0x98($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X98);
    // 0x800B1A34: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x800B1A38: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x800B1A3C: jal         0x8006FB8C
    // 0x800B1A40: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_5;
    // 0x800B1A40: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_5:
    // 0x800B1A44: lbu         $t3, 0x6C($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X6C);
    // 0x800B1A48: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800B1A4C: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B1A50: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800B1A54: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x800B1A58: sb          $t4, 0x6C($s0)
    MEM_B(0X6C, ctx->r16) = ctx->r12;
    // 0x800B1A5C: sll         $t5, $v1, 10
    ctx->r13 = S32(ctx->r3 << 10);
L_800B1A60:
    // 0x800B1A60: bgez        $t5, L_800B1A98
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800B1A64: sll         $t8, $v1, 9
        ctx->r24 = S32(ctx->r3 << 9);
            goto L_800B1A98;
    }
    // 0x800B1A64: sll         $t8, $v1, 9
    ctx->r24 = S32(ctx->r3 << 9);
    // 0x800B1A68: lbu         $a1, 0x99($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X99);
    // 0x800B1A6C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x800B1A70: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x800B1A74: jal         0x8006FB8C
    // 0x800B1A78: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_6;
    // 0x800B1A78: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_6:
    // 0x800B1A7C: lbu         $t7, 0x6D($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X6D);
    // 0x800B1A80: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800B1A84: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B1A88: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800B1A8C: addu        $t6, $t7, $v0
    ctx->r14 = ADD32(ctx->r15, ctx->r2);
    // 0x800B1A90: sb          $t6, 0x6D($s0)
    MEM_B(0X6D, ctx->r16) = ctx->r14;
    // 0x800B1A94: sll         $t8, $v1, 9
    ctx->r24 = S32(ctx->r3 << 9);
L_800B1A98:
    // 0x800B1A98: bgez        $t8, L_800B1AD0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800B1A9C: sll         $t3, $v1, 8
        ctx->r11 = S32(ctx->r3 << 8);
            goto L_800B1AD0;
    }
    // 0x800B1A9C: sll         $t3, $v1, 8
    ctx->r11 = S32(ctx->r3 << 8);
    // 0x800B1AA0: lbu         $a1, 0x9A($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X9A);
    // 0x800B1AA4: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x800B1AA8: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x800B1AAC: jal         0x8006FB8C
    // 0x800B1AB0: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_7;
    // 0x800B1AB0: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_7:
    // 0x800B1AB4: lbu         $t9, 0x6E($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X6E);
    // 0x800B1AB8: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800B1ABC: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B1AC0: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800B1AC4: addu        $t2, $t9, $v0
    ctx->r10 = ADD32(ctx->r25, ctx->r2);
    // 0x800B1AC8: sb          $t2, 0x6E($s0)
    MEM_B(0X6E, ctx->r16) = ctx->r10;
    // 0x800B1ACC: sll         $t3, $v1, 8
    ctx->r11 = S32(ctx->r3 << 8);
L_800B1AD0:
    // 0x800B1AD0: bgez        $t3, L_800B1AFC
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800B1AD4: nop
    
            goto L_800B1AFC;
    }
    // 0x800B1AD4: nop

    // 0x800B1AD8: lbu         $a1, 0x9B($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X9B);
    // 0x800B1ADC: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x800B1AE0: jal         0x8006FB8C
    // 0x800B1AE4: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_8;
    // 0x800B1AE4: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_8:
    // 0x800B1AE8: lbu         $t4, 0x6F($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X6F);
    // 0x800B1AEC: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B1AF0: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800B1AF4: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800B1AF8: sb          $t5, 0x6F($s0)
    MEM_B(0X6F, ctx->r16) = ctx->r13;
L_800B1AFC:
    // 0x800B1AFC: lh          $t7, 0xE($a3)
    ctx->r15 = MEM_H(ctx->r7, 0XE);
    // 0x800B1B00: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800B1B04: sh          $t7, 0x60($s0)
    MEM_H(0X60, ctx->r16) = ctx->r15;
    // 0x800B1B08: addiu       $a0, $a0, 0x347C
    ctx->r4 = ADD32(ctx->r4, 0X347C);
    // 0x800B1B0C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800B1B10: lbu         $t6, 0xC($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0XC);
    // 0x800B1B14: nop

    // 0x800B1B18: multu       $t6, $t8
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B1B1C: mflo        $t9
    ctx->r25 = lo;
    // 0x800B1B20: sh          $t9, 0x5C($s0)
    MEM_H(0X5C, ctx->r16) = ctx->r25;
    // 0x800B1B24: lbu         $t2, 0xC($a3)
    ctx->r10 = MEM_BU(ctx->r7, 0XC);
    // 0x800B1B28: nop

    // 0x800B1B2C: slti        $at, $t2, 0xFF
    ctx->r1 = SIGNED(ctx->r10) < 0XFF ? 1 : 0;
    // 0x800B1B30: beq         $at, $zero, L_800B1B70
    if (ctx->r1 == 0) {
        // 0x800B1B34: nop
    
            goto L_800B1B70;
    }
    // 0x800B1B34: nop

    // 0x800B1B38: lw          $t3, 0x40($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X40);
    // 0x800B1B3C: nop

    // 0x800B1B40: andi        $t4, $t3, 0x1000
    ctx->r12 = ctx->r11 & 0X1000;
    // 0x800B1B44: beq         $t4, $zero, L_800B1B60
    if (ctx->r12 == 0) {
        // 0x800B1B48: nop
    
            goto L_800B1B60;
    }
    // 0x800B1B48: nop

    // 0x800B1B4C: lh          $t5, 0x6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X6);
    // 0x800B1B50: nop

    // 0x800B1B54: ori         $t7, $t5, 0x100
    ctx->r15 = ctx->r13 | 0X100;
    // 0x800B1B58: b           L_800B1B70
    // 0x800B1B5C: sh          $t7, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r15;
        goto L_800B1B70;
    // 0x800B1B5C: sh          $t7, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r15;
L_800B1B60:
    // 0x800B1B60: lh          $t6, 0x6($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X6);
    // 0x800B1B64: nop

    // 0x800B1B68: ori         $t8, $t6, 0x80
    ctx->r24 = ctx->r14 | 0X80;
    // 0x800B1B6C: sh          $t8, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r24;
L_800B1B70:
    // 0x800B1B70: lh          $v0, 0x60($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X60);
    // 0x800B1B74: lh          $v1, 0x3A($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X3A);
    // 0x800B1B78: nop

    // 0x800B1B7C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800B1B80: beq         $at, $zero, L_800B1BE4
    if (ctx->r1 == 0) {
        // 0x800B1B84: nop
    
            goto L_800B1BE4;
    }
    // 0x800B1B84: nop

    // 0x800B1B88: lbu         $t9, 0xD($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0XD);
    // 0x800B1B8C: lbu         $t2, 0xC($a3)
    ctx->r10 = MEM_BU(ctx->r7, 0XC);
    // 0x800B1B90: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x800B1B94: subu        $t3, $t9, $t2
    ctx->r11 = SUB32(ctx->r25, ctx->r10);
    // 0x800B1B98: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B1B9C: subu        $t7, $v1, $v0
    ctx->r15 = SUB32(ctx->r3, ctx->r2);
    // 0x800B1BA0: mflo        $t5
    ctx->r13 = lo;
    // 0x800B1BA4: nop

    // 0x800B1BA8: nop

    // 0x800B1BAC: div         $zero, $t5, $t7
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r15))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r15)));
    // 0x800B1BB0: bne         $t7, $zero, L_800B1BBC
    if (ctx->r15 != 0) {
        // 0x800B1BB4: nop
    
            goto L_800B1BBC;
    }
    // 0x800B1BB4: nop

    // 0x800B1BB8: break       7
    do_break(2148211640);
L_800B1BBC:
    // 0x800B1BBC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B1BC0: bne         $t7, $at, L_800B1BD4
    if (ctx->r15 != ctx->r1) {
        // 0x800B1BC4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B1BD4;
    }
    // 0x800B1BC4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B1BC8: bne         $t5, $at, L_800B1BD4
    if (ctx->r13 != ctx->r1) {
        // 0x800B1BCC: nop
    
            goto L_800B1BD4;
    }
    // 0x800B1BCC: nop

    // 0x800B1BD0: break       6
    do_break(2148211664);
L_800B1BD4:
    // 0x800B1BD4: mflo        $t6
    ctx->r14 = lo;
    // 0x800B1BD8: sh          $t6, 0x5E($s0)
    MEM_H(0X5E, ctx->r16) = ctx->r14;
    // 0x800B1BDC: b           L_800B1BEC
    // 0x800B1BE0: sb          $zero, 0x23($sp)
    MEM_B(0X23, ctx->r29) = 0;
        goto L_800B1BEC;
    // 0x800B1BE0: sb          $zero, 0x23($sp)
    MEM_B(0X23, ctx->r29) = 0;
L_800B1BE4:
    // 0x800B1BE4: sh          $zero, 0x5E($s0)
    MEM_H(0X5E, ctx->r16) = 0;
    // 0x800B1BE8: sb          $zero, 0x23($sp)
    MEM_B(0X23, ctx->r29) = 0;
L_800B1BEC:
    // 0x800B1BEC: lh          $t8, 0x6($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X6);
    // 0x800B1BF0: lh          $v0, 0x2C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X2C);
    // 0x800B1BF4: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x800B1BF8: bne         $v0, $at, L_800B1D14
    if (ctx->r2 != ctx->r1) {
        // 0x800B1BFC: sh          $t8, 0x1A($s0)
        MEM_H(0X1A, ctx->r16) = ctx->r24;
            goto L_800B1D14;
    }
    // 0x800B1BFC: sh          $t8, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r24;
    // 0x800B1C00: lh          $a0, 0x4($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X4);
    // 0x800B1C04: jal         0x8007C57C
    // 0x800B1C08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    tex_load_sprite(rdram, ctx);
        goto after_9;
    // 0x800B1C08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x800B1C0C: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B1C10: beq         $v0, $zero, L_800B1D08
    if (ctx->r2 == 0) {
        // 0x800B1C14: sw          $v0, 0x44($s0)
        MEM_W(0X44, ctx->r16) = ctx->r2;
            goto L_800B1D08;
    }
    // 0x800B1C14: sw          $v0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r2;
    // 0x800B1C18: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x800B1C1C: nop

    // 0x800B1C20: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800B1C24: nop

    // 0x800B1C28: lh          $t4, 0x6($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X6);
    // 0x800B1C2C: nop

    // 0x800B1C30: andi        $t5, $t4, 0x4
    ctx->r13 = ctx->r12 & 0X4;
    // 0x800B1C34: beq         $t5, $zero, L_800B1C74
    if (ctx->r13 == 0) {
        // 0x800B1C38: nop
    
            goto L_800B1C74;
    }
    // 0x800B1C38: nop

    // 0x800B1C3C: lw          $t7, 0x40($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X40);
    // 0x800B1C40: nop

    // 0x800B1C44: andi        $t6, $t7, 0x1000
    ctx->r14 = ctx->r15 & 0X1000;
    // 0x800B1C48: beq         $t6, $zero, L_800B1C64
    if (ctx->r14 == 0) {
        // 0x800B1C4C: nop
    
            goto L_800B1C64;
    }
    // 0x800B1C4C: nop

    // 0x800B1C50: lh          $t8, 0x6($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X6);
    // 0x800B1C54: nop

    // 0x800B1C58: ori         $t9, $t8, 0x100
    ctx->r25 = ctx->r24 | 0X100;
    // 0x800B1C5C: b           L_800B1C74
    // 0x800B1C60: sh          $t9, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r25;
        goto L_800B1C74;
    // 0x800B1C60: sh          $t9, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r25;
L_800B1C64:
    // 0x800B1C64: lh          $t2, 0x6($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X6);
    // 0x800B1C68: nop

    // 0x800B1C6C: ori         $t3, $t2, 0x80
    ctx->r11 = ctx->r10 | 0X80;
    // 0x800B1C70: sh          $t3, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r11;
L_800B1C74:
    // 0x800B1C74: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x800B1C78: nop

    // 0x800B1C7C: andi        $t5, $t4, 0x800
    ctx->r13 = ctx->r12 & 0X800;
    // 0x800B1C80: beq         $t5, $zero, L_800B1CCC
    if (ctx->r13 == 0) {
        // 0x800B1C84: nop
    
            goto L_800B1CCC;
    }
    // 0x800B1C84: nop

    // 0x800B1C88: lw          $t7, 0x44($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X44);
    // 0x800B1C8C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B1C90: lh          $a1, 0x0($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X0);
    // 0x800B1C94: jal         0x8006FB8C
    // 0x800B1C98: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    rand_range(rdram, ctx);
        goto after_10;
    // 0x800B1C98: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    after_10:
    // 0x800B1C9C: lw          $t8, 0x40($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X40);
    // 0x800B1CA0: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B1CA4: sll         $t6, $v0, 8
    ctx->r14 = S32(ctx->r2 << 8);
    // 0x800B1CA8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B1CAC: andi        $t9, $t8, 0x3
    ctx->r25 = ctx->r24 & 0X3;
    // 0x800B1CB0: bne         $t9, $at, L_800B1E40
    if (ctx->r25 != ctx->r1) {
        // 0x800B1CB4: sh          $t6, 0x18($s0)
        MEM_H(0X18, ctx->r16) = ctx->r14;
            goto L_800B1E40;
    }
    // 0x800B1CB4: sh          $t6, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r14;
    // 0x800B1CB8: lh          $t2, 0x18($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X18);
    // 0x800B1CBC: nop

    // 0x800B1CC0: ori         $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 | 0XFF;
    // 0x800B1CC4: b           L_800B1E40
    // 0x800B1CC8: sh          $t3, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r11;
        goto L_800B1E40;
    // 0x800B1CC8: sh          $t3, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r11;
L_800B1CCC:
    // 0x800B1CCC: lw          $t4, 0x40($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X40);
    // 0x800B1CD0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B1CD4: andi        $t5, $t4, 0x3
    ctx->r13 = ctx->r12 & 0X3;
    // 0x800B1CD8: bne         $t5, $at, L_800B1D00
    if (ctx->r13 != ctx->r1) {
        // 0x800B1CDC: nop
    
            goto L_800B1D00;
    }
    // 0x800B1CDC: nop

    // 0x800B1CE0: lw          $t7, 0x44($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X44);
    // 0x800B1CE4: nop

    // 0x800B1CE8: lh          $t6, 0x0($t7)
    ctx->r14 = MEM_H(ctx->r15, 0X0);
    // 0x800B1CEC: nop

    // 0x800B1CF0: sll         $t8, $t6, 8
    ctx->r24 = S32(ctx->r14 << 8);
    // 0x800B1CF4: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800B1CF8: b           L_800B1E40
    // 0x800B1CFC: sh          $t9, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r25;
        goto L_800B1E40;
    // 0x800B1CFC: sh          $t9, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r25;
L_800B1D00:
    // 0x800B1D00: b           L_800B1E40
    // 0x800B1D04: sh          $zero, 0x18($s0)
    MEM_H(0X18, ctx->r16) = 0;
        goto L_800B1E40;
    // 0x800B1D04: sh          $zero, 0x18($s0)
    MEM_H(0X18, ctx->r16) = 0;
L_800B1D08:
    // 0x800B1D08: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800B1D0C: b           L_800B1E40
    // 0x800B1D10: sb          $t2, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r10;
        goto L_800B1E40;
    // 0x800B1D10: sb          $t2, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r10;
L_800B1D14:
    // 0x800B1D14: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B1D18: beq         $v0, $at, L_800B1D28
    if (ctx->r2 == ctx->r1) {
        // 0x800B1D1C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800B1D28;
    }
    // 0x800B1D1C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B1D20: bne         $v0, $at, L_800B1E44
    if (ctx->r2 != ctx->r1) {
        // 0x800B1D24: lb          $t3, 0x23($sp)
        ctx->r11 = MEM_B(ctx->r29, 0X23);
            goto L_800B1E44;
    }
    // 0x800B1D24: lb          $t3, 0x23($sp)
    ctx->r11 = MEM_B(ctx->r29, 0X23);
L_800B1D28:
    // 0x800B1D28: lw          $v1, 0x44($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X44);
    // 0x800B1D2C: nop

    // 0x800B1D30: beq         $v1, $zero, L_800B1E44
    if (ctx->r3 == 0) {
        // 0x800B1D34: lb          $t3, 0x23($sp)
        ctx->r11 = MEM_B(ctx->r29, 0X23);
            goto L_800B1E44;
    }
    // 0x800B1D34: lb          $t3, 0x23($sp)
    ctx->r11 = MEM_B(ctx->r29, 0X23);
    // 0x800B1D38: lh          $a0, 0x4($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X4);
    // 0x800B1D3C: jal         0x8007B2C4
    // 0x800B1D40: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    load_texture(rdram, ctx);
        goto after_11;
    // 0x800B1D40: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_11:
    // 0x800B1D44: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800B1D48: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B1D4C: beq         $v0, $zero, L_800B1E38
    if (ctx->r2 == 0) {
        // 0x800B1D50: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_800B1E38;
    }
    // 0x800B1D50: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800B1D54: lh          $t4, 0x6($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X6);
    // 0x800B1D58: nop

    // 0x800B1D5C: andi        $t5, $t4, 0x4
    ctx->r13 = ctx->r12 & 0X4;
    // 0x800B1D60: beq         $t5, $zero, L_800B1DA0
    if (ctx->r13 == 0) {
        // 0x800B1D64: nop
    
            goto L_800B1DA0;
    }
    // 0x800B1D64: nop

    // 0x800B1D68: lw          $t7, 0x40($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X40);
    // 0x800B1D6C: nop

    // 0x800B1D70: andi        $t6, $t7, 0x1000
    ctx->r14 = ctx->r15 & 0X1000;
    // 0x800B1D74: beq         $t6, $zero, L_800B1D90
    if (ctx->r14 == 0) {
        // 0x800B1D78: nop
    
            goto L_800B1D90;
    }
    // 0x800B1D78: nop

    // 0x800B1D7C: lh          $t8, 0x6($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X6);
    // 0x800B1D80: nop

    // 0x800B1D84: ori         $t9, $t8, 0x100
    ctx->r25 = ctx->r24 | 0X100;
    // 0x800B1D88: b           L_800B1DA0
    // 0x800B1D8C: sh          $t9, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r25;
        goto L_800B1DA0;
    // 0x800B1D8C: sh          $t9, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r25;
L_800B1D90:
    // 0x800B1D90: lh          $t2, 0x6($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X6);
    // 0x800B1D94: nop

    // 0x800B1D98: ori         $t3, $t2, 0x80
    ctx->r11 = ctx->r10 | 0X80;
    // 0x800B1D9C: sh          $t3, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r11;
L_800B1DA0:
    // 0x800B1DA0: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x800B1DA4: nop

    // 0x800B1DA8: andi        $t5, $t4, 0x800
    ctx->r13 = ctx->r12 & 0X800;
    // 0x800B1DAC: beq         $t5, $zero, L_800B1E00
    if (ctx->r13 == 0) {
        // 0x800B1DB0: nop
    
            goto L_800B1E00;
    }
    // 0x800B1DB0: nop

    // 0x800B1DB4: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800B1DB8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B1DBC: lhu         $a1, 0x12($t7)
    ctx->r5 = MEM_HU(ctx->r15, 0X12);
    // 0x800B1DC0: nop

    // 0x800B1DC4: sra         $t6, $a1, 8
    ctx->r14 = S32(SIGNED(ctx->r5) >> 8);
    // 0x800B1DC8: jal         0x8006FB8C
    // 0x800B1DCC: addiu       $a1, $t6, -0x1
    ctx->r5 = ADD32(ctx->r14, -0X1);
    rand_range(rdram, ctx);
        goto after_12;
    // 0x800B1DCC: addiu       $a1, $t6, -0x1
    ctx->r5 = ADD32(ctx->r14, -0X1);
    after_12:
    // 0x800B1DD0: lw          $t9, 0x40($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X40);
    // 0x800B1DD4: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B1DD8: sll         $t8, $v0, 8
    ctx->r24 = S32(ctx->r2 << 8);
    // 0x800B1DDC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B1DE0: andi        $t2, $t9, 0x3
    ctx->r10 = ctx->r25 & 0X3;
    // 0x800B1DE4: bne         $t2, $at, L_800B1E40
    if (ctx->r10 != ctx->r1) {
        // 0x800B1DE8: sh          $t8, 0x18($s0)
        MEM_H(0X18, ctx->r16) = ctx->r24;
            goto L_800B1E40;
    }
    // 0x800B1DE8: sh          $t8, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r24;
    // 0x800B1DEC: lh          $t3, 0x18($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X18);
    // 0x800B1DF0: nop

    // 0x800B1DF4: ori         $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 | 0XFF;
    // 0x800B1DF8: b           L_800B1E40
    // 0x800B1DFC: sh          $t4, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r12;
        goto L_800B1E40;
    // 0x800B1DFC: sh          $t4, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r12;
L_800B1E00:
    // 0x800B1E00: lw          $t5, 0x40($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X40);
    // 0x800B1E04: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B1E08: andi        $t7, $t5, 0x3
    ctx->r15 = ctx->r13 & 0X3;
    // 0x800B1E0C: bne         $t7, $at, L_800B1E30
    if (ctx->r15 != ctx->r1) {
        // 0x800B1E10: nop
    
            goto L_800B1E30;
    }
    // 0x800B1E10: nop

    // 0x800B1E14: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800B1E18: nop

    // 0x800B1E1C: lhu         $t8, 0x12($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X12);
    // 0x800B1E20: nop

    // 0x800B1E24: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800B1E28: b           L_800B1E40
    // 0x800B1E2C: sh          $t9, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r25;
        goto L_800B1E40;
    // 0x800B1E2C: sh          $t9, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r25;
L_800B1E30:
    // 0x800B1E30: b           L_800B1E40
    // 0x800B1E34: sh          $zero, 0x18($s0)
    MEM_H(0X18, ctx->r16) = 0;
        goto L_800B1E40;
    // 0x800B1E34: sh          $zero, 0x18($s0)
    MEM_H(0X18, ctx->r16) = 0;
L_800B1E38:
    // 0x800B1E38: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800B1E3C: sb          $t2, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r10;
L_800B1E40:
    // 0x800B1E40: lb          $t3, 0x23($sp)
    ctx->r11 = MEM_B(ctx->r29, 0X23);
L_800B1E44:
    // 0x800B1E44: nop

    // 0x800B1E48: bne         $t3, $zero, L_800B1E94
    if (ctx->r11 != 0) {
        // 0x800B1E4C: lw          $a1, 0x40($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X40);
            goto L_800B1E94;
    }
    // 0x800B1E4C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800B1E50: lh          $v0, 0x2C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X2C);
    // 0x800B1E54: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B1E58: bne         $v0, $at, L_800B1E78
    if (ctx->r2 != ctx->r1) {
        // 0x800B1E5C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800B1E78;
    }
    // 0x800B1E5C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B1E60: jal         0x800AF604
    // 0x800B1E64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    set_triangle_texture_coords(rdram, ctx);
        goto after_13;
    // 0x800B1E64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x800B1E68: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B1E6C: lh          $v0, 0x2C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X2C);
    // 0x800B1E70: nop

    // 0x800B1E74: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_800B1E78:
    // 0x800B1E78: bne         $v0, $at, L_800B1E94
    if (ctx->r2 != ctx->r1) {
        // 0x800B1E7C: lw          $a1, 0x40($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X40);
            goto L_800B1E94;
    }
    // 0x800B1E7C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800B1E80: jal         0x800AF650
    // 0x800B1E84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    set_rectangle_texture_coords(rdram, ctx);
        goto after_14;
    // 0x800B1E84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x800B1E88: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B1E8C: nop

    // 0x800B1E90: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
L_800B1E94:
    // 0x800B1E94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B1E98: jal         0x800B0920
    // 0x800B1E9C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    setup_particle_position(rdram, ctx);
        goto after_15;
    // 0x800B1E9C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_15:
    // 0x800B1EA0: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x800B1EA4: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B1EA8: andi        $t5, $t4, 0x80
    ctx->r13 = ctx->r12 & 0X80;
    // 0x800B1EAC: beq         $t5, $zero, L_800B1EDC
    if (ctx->r13 == 0) {
        // 0x800B1EB0: lw          $t9, 0x40($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X40);
            goto L_800B1EDC;
    }
    // 0x800B1EB0: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800B1EB4: lh          $t7, 0x44($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X44);
    // 0x800B1EB8: nop

    // 0x800B1EBC: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
    // 0x800B1EC0: lh          $t6, 0x46($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X46);
    // 0x800B1EC4: nop

    // 0x800B1EC8: sh          $t6, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r14;
    // 0x800B1ECC: lh          $t8, 0x48($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X48);
    // 0x800B1ED0: b           L_800B1F20
    // 0x800B1ED4: sh          $t8, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r24;
        goto L_800B1F20;
    // 0x800B1ED4: sh          $t8, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r24;
    // 0x800B1ED8: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
L_800B1EDC:
    // 0x800B1EDC: lh          $t3, 0x44($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X44);
    // 0x800B1EE0: lh          $t2, 0x0($t9)
    ctx->r10 = MEM_H(ctx->r25, 0X0);
    // 0x800B1EE4: nop

    // 0x800B1EE8: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800B1EEC: sh          $t4, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r12;
    // 0x800B1EF0: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x800B1EF4: lh          $t6, 0x46($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X46);
    // 0x800B1EF8: lh          $t7, 0x2($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X2);
    // 0x800B1EFC: nop

    // 0x800B1F00: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x800B1F04: sh          $t8, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r24;
    // 0x800B1F08: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800B1F0C: lh          $t3, 0x48($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X48);
    // 0x800B1F10: lh          $t2, 0x4($t9)
    ctx->r10 = MEM_H(ctx->r25, 0X4);
    // 0x800B1F14: nop

    // 0x800B1F18: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800B1F1C: sh          $t4, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r12;
L_800B1F20:
    // 0x800B1F20: lw          $v1, 0x5C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X5C);
    // 0x800B1F24: nop

    // 0x800B1F28: andi        $t5, $v1, 0x3800
    ctx->r13 = ctx->r3 & 0X3800;
    // 0x800B1F2C: beq         $t5, $zero, L_800B1FBC
    if (ctx->r13 == 0) {
        // 0x800B1F30: or          $v1, $t5, $zero
        ctx->r3 = ctx->r13 | 0;
            goto L_800B1FBC;
    }
    // 0x800B1F30: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
    // 0x800B1F34: andi        $t7, $t5, 0x800
    ctx->r15 = ctx->r13 & 0X800;
    // 0x800B1F38: beq         $t7, $zero, L_800B1F68
    if (ctx->r15 == 0) {
        // 0x800B1F3C: andi        $t9, $v1, 0x1000
        ctx->r25 = ctx->r3 & 0X1000;
            goto L_800B1F68;
    }
    // 0x800B1F3C: andi        $t9, $v1, 0x1000
    ctx->r25 = ctx->r3 & 0X1000;
    // 0x800B1F40: lh          $a1, 0x80($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X80);
    // 0x800B1F44: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x800B1F48: jal         0x8006FB8C
    // 0x800B1F4C: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_16;
    // 0x800B1F4C: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_16:
    // 0x800B1F50: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x800B1F54: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800B1F58: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B1F5C: addu        $t8, $t6, $v0
    ctx->r24 = ADD32(ctx->r14, ctx->r2);
    // 0x800B1F60: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
    // 0x800B1F64: andi        $t9, $v1, 0x1000
    ctx->r25 = ctx->r3 & 0X1000;
L_800B1F68:
    // 0x800B1F68: beq         $t9, $zero, L_800B1F98
    if (ctx->r25 == 0) {
        // 0x800B1F6C: andi        $t4, $v1, 0x2000
        ctx->r12 = ctx->r3 & 0X2000;
            goto L_800B1F98;
    }
    // 0x800B1F6C: andi        $t4, $v1, 0x2000
    ctx->r12 = ctx->r3 & 0X2000;
    // 0x800B1F70: lh          $a1, 0x82($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X82);
    // 0x800B1F74: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x800B1F78: jal         0x8006FB8C
    // 0x800B1F7C: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_17;
    // 0x800B1F7C: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_17:
    // 0x800B1F80: lh          $t2, 0x2($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X2);
    // 0x800B1F84: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800B1F88: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B1F8C: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x800B1F90: sh          $t3, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r11;
    // 0x800B1F94: andi        $t4, $v1, 0x2000
    ctx->r12 = ctx->r3 & 0X2000;
L_800B1F98:
    // 0x800B1F98: beq         $t4, $zero, L_800B1FBC
    if (ctx->r12 == 0) {
        // 0x800B1F9C: nop
    
            goto L_800B1FBC;
    }
    // 0x800B1F9C: nop

    // 0x800B1FA0: lh          $a1, 0x84($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X84);
    // 0x800B1FA4: jal         0x8006FB8C
    // 0x800B1FA8: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_18;
    // 0x800B1FA8: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_18:
    // 0x800B1FAC: lh          $t5, 0x4($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X4);
    // 0x800B1FB0: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B1FB4: addu        $t7, $t5, $v0
    ctx->r15 = ADD32(ctx->r13, ctx->r2);
    // 0x800B1FB8: sh          $t7, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r15;
L_800B1FBC:
    // 0x800B1FBC: lh          $t6, 0x4A($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X4A);
    // 0x800B1FC0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800B1FC4: sh          $t6, 0x62($s0)
    MEM_H(0X62, ctx->r16) = ctx->r14;
    // 0x800B1FC8: lh          $t8, 0x4C($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X4C);
    // 0x800B1FCC: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x800B1FD0: sh          $t8, 0x64($s0)
    MEM_H(0X64, ctx->r16) = ctx->r24;
    // 0x800B1FD4: lh          $t9, 0x4E($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X4E);
    // 0x800B1FD8: nop

    // 0x800B1FDC: sh          $t9, 0x66($s0)
    MEM_H(0X66, ctx->r16) = ctx->r25;
    // 0x800B1FE0: lw          $v1, 0x5C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X5C);
    // 0x800B1FE4: nop

    // 0x800B1FE8: and         $t2, $v1, $at
    ctx->r10 = ctx->r3 & ctx->r1;
    // 0x800B1FEC: beq         $t2, $zero, L_800B207C
    if (ctx->r10 == 0) {
        // 0x800B1FF0: or          $v1, $t2, $zero
        ctx->r3 = ctx->r10 | 0;
            goto L_800B207C;
    }
    // 0x800B1FF0: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
    // 0x800B1FF4: andi        $t3, $t2, 0x4000
    ctx->r11 = ctx->r10 & 0X4000;
    // 0x800B1FF8: beq         $t3, $zero, L_800B2028
    if (ctx->r11 == 0) {
        // 0x800B1FFC: andi        $t7, $v1, 0x8000
        ctx->r15 = ctx->r3 & 0X8000;
            goto L_800B2028;
    }
    // 0x800B1FFC: andi        $t7, $v1, 0x8000
    ctx->r15 = ctx->r3 & 0X8000;
    // 0x800B2000: lh          $a1, 0x86($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X86);
    // 0x800B2004: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x800B2008: jal         0x8006FB8C
    // 0x800B200C: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_19;
    // 0x800B200C: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_19:
    // 0x800B2010: lh          $t4, 0x62($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X62);
    // 0x800B2014: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800B2018: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B201C: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800B2020: sh          $t5, 0x62($s0)
    MEM_H(0X62, ctx->r16) = ctx->r13;
    // 0x800B2024: andi        $t7, $v1, 0x8000
    ctx->r15 = ctx->r3 & 0X8000;
L_800B2028:
    // 0x800B2028: beq         $t7, $zero, L_800B2058
    if (ctx->r15 == 0) {
        // 0x800B202C: sll         $t9, $v1, 15
        ctx->r25 = S32(ctx->r3 << 15);
            goto L_800B2058;
    }
    // 0x800B202C: sll         $t9, $v1, 15
    ctx->r25 = S32(ctx->r3 << 15);
    // 0x800B2030: lh          $a1, 0x88($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X88);
    // 0x800B2034: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x800B2038: jal         0x8006FB8C
    // 0x800B203C: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_20;
    // 0x800B203C: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_20:
    // 0x800B2040: lh          $t6, 0x64($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X64);
    // 0x800B2044: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800B2048: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B204C: addu        $t8, $t6, $v0
    ctx->r24 = ADD32(ctx->r14, ctx->r2);
    // 0x800B2050: sh          $t8, 0x64($s0)
    MEM_H(0X64, ctx->r16) = ctx->r24;
    // 0x800B2054: sll         $t9, $v1, 15
    ctx->r25 = S32(ctx->r3 << 15);
L_800B2058:
    // 0x800B2058: bgez        $t9, L_800B2080
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800B205C: lw          $a1, 0x40($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X40);
            goto L_800B2080;
    }
    // 0x800B205C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800B2060: lh          $a1, 0x8A($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X8A);
    // 0x800B2064: jal         0x8006FB8C
    // 0x800B2068: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_21;
    // 0x800B2068: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_21:
    // 0x800B206C: lh          $t2, 0x66($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X66);
    // 0x800B2070: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B2074: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x800B2078: sh          $t3, 0x66($s0)
    MEM_H(0X66, ctx->r16) = ctx->r11;
L_800B207C:
    // 0x800B207C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
L_800B2080:
    // 0x800B2080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B2084: jal         0x800B0570
    // 0x800B2088: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    setup_particle_velocity(rdram, ctx);
        goto after_22;
    // 0x800B2088: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_22:
    // 0x800B208C: lw          $t4, 0x40($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X40);
    // 0x800B2090: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B2094: sra         $t5, $t4, 4
    ctx->r13 = S32(SIGNED(ctx->r12) >> 4);
    // 0x800B2098: andi        $t7, $t5, 0x7
    ctx->r15 = ctx->r13 & 0X7;
    // 0x800B209C: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x800B20A0: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800B20A4: lwc1        $f4, 0x33BC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X33BC);
    // 0x800B20A8: lbu         $t8, 0x39($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X39);
    // 0x800B20AC: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B20B0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800B20B4: bne         $t8, $at, L_800B20EC
    if (ctx->r24 != ctx->r1) {
        // 0x800B20B8: swc1        $f4, 0x68($s0)
        MEM_W(0X68, ctx->r16) = ctx->f4.u32l;
            goto L_800B20EC;
    }
    // 0x800B20B8: swc1        $f4, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f4.u32l;
    // 0x800B20BC: lwc1        $f0, 0x1C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800B20C0: lwc1        $f2, 0x20($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800B20C4: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800B20C8: lwc1        $f14, 0x24($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800B20CC: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800B20D0: nop

    // 0x800B20D4: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800B20D8: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800B20DC: jal         0x800CA030
    // 0x800B20E0: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_23;
    // 0x800B20E0: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_23:
    // 0x800B20E4: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B20E8: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
L_800B20EC:
    // 0x800B20EC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x800B20F0: nop

    // 0x800B20F4: andi        $t2, $t9, 0x2
    ctx->r10 = ctx->r25 & 0X2;
    // 0x800B20F8: beq         $t2, $zero, L_800B2168
    if (ctx->r10 == 0) {
        // 0x800B20FC: nop
    
            goto L_800B2168;
    }
    // 0x800B20FC: nop

    // 0x800B2100: lbu         $t3, 0x6($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X6);
    // 0x800B2104: nop

    // 0x800B2108: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800B210C: sb          $t4, 0x6($a2)
    MEM_B(0X6, ctx->r6) = ctx->r12;
    // 0x800B2110: lh          $t5, 0x1A($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X1A);
    // 0x800B2114: andi        $v0, $t4, 0xFF
    ctx->r2 = ctx->r12 & 0XFF;
    // 0x800B2118: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800B211C: bne         $at, $zero, L_800B2168
    if (ctx->r1 != 0) {
        // 0x800B2120: nop
    
            goto L_800B2168;
    }
    // 0x800B2120: nop

    // 0x800B2124: lh          $t7, 0xC($a2)
    ctx->r15 = MEM_H(ctx->r6, 0XC);
    // 0x800B2128: lh          $t6, 0x1C($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X1C);
    // 0x800B212C: lh          $t9, 0xE($a2)
    ctx->r25 = MEM_H(ctx->r6, 0XE);
    // 0x800B2130: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x800B2134: sh          $t8, 0xC($a2)
    MEM_H(0XC, ctx->r6) = ctx->r24;
    // 0x800B2138: lh          $t2, 0x1E($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X1E);
    // 0x800B213C: lh          $t4, 0x10($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X10);
    // 0x800B2140: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x800B2144: sh          $t3, 0xE($a2)
    MEM_H(0XE, ctx->r6) = ctx->r11;
    // 0x800B2148: lh          $t5, 0x18($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X18);
    // 0x800B214C: nop

    // 0x800B2150: addu        $t7, $t4, $t5
    ctx->r15 = ADD32(ctx->r12, ctx->r13);
    // 0x800B2154: sh          $t7, 0x10($a2)
    MEM_H(0X10, ctx->r6) = ctx->r15;
    // 0x800B2158: lh          $t6, 0x1A($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X1A);
    // 0x800B215C: nop

    // 0x800B2160: subu        $t8, $v0, $t6
    ctx->r24 = SUB32(ctx->r2, ctx->r14);
    // 0x800B2164: sb          $t8, 0x6($a2)
    MEM_B(0X6, ctx->r6) = ctx->r24;
L_800B2168:
    // 0x800B2168: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x800B216C: nop

    // 0x800B2170: andi        $t2, $t9, 0x8
    ctx->r10 = ctx->r25 & 0X8;
    // 0x800B2174: beq         $t2, $zero, L_800B21E4
    if (ctx->r10 == 0) {
        // 0x800B2178: nop
    
            goto L_800B21E4;
    }
    // 0x800B2178: nop

    // 0x800B217C: lbu         $t3, 0x7($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X7);
    // 0x800B2180: nop

    // 0x800B2184: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800B2188: sb          $t4, 0x7($a2)
    MEM_B(0X7, ctx->r6) = ctx->r12;
    // 0x800B218C: lh          $t5, 0x28($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X28);
    // 0x800B2190: andi        $v0, $t4, 0xFF
    ctx->r2 = ctx->r12 & 0XFF;
    // 0x800B2194: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800B2198: bne         $at, $zero, L_800B21E4
    if (ctx->r1 != 0) {
        // 0x800B219C: nop
    
            goto L_800B21E4;
    }
    // 0x800B219C: nop

    // 0x800B21A0: lh          $t7, 0x12($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X12);
    // 0x800B21A4: lh          $t6, 0x2A($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X2A);
    // 0x800B21A8: lh          $t9, 0x14($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X14);
    // 0x800B21AC: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x800B21B0: sh          $t8, 0x12($a2)
    MEM_H(0X12, ctx->r6) = ctx->r24;
    // 0x800B21B4: lh          $t2, 0x2C($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X2C);
    // 0x800B21B8: lh          $t4, 0x16($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X16);
    // 0x800B21BC: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x800B21C0: sh          $t3, 0x14($a2)
    MEM_H(0X14, ctx->r6) = ctx->r11;
    // 0x800B21C4: lh          $t5, 0x2E($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X2E);
    // 0x800B21C8: nop

    // 0x800B21CC: addu        $t7, $t4, $t5
    ctx->r15 = ADD32(ctx->r12, ctx->r13);
    // 0x800B21D0: sh          $t7, 0x16($a2)
    MEM_H(0X16, ctx->r6) = ctx->r15;
    // 0x800B21D4: lh          $t6, 0x28($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X28);
    // 0x800B21D8: nop

    // 0x800B21DC: subu        $t8, $v0, $t6
    ctx->r24 = SUB32(ctx->r2, ctx->r14);
    // 0x800B21E0: sb          $t8, 0x7($a2)
    MEM_B(0X7, ctx->r6) = ctx->r24;
L_800B21E4:
    // 0x800B21E4: lw          $t9, 0x44($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X44);
    // 0x800B21E8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800B21EC: bne         $t9, $zero, L_800B2204
    if (ctx->r25 != 0) {
        // 0x800B21F0: nop
    
            goto L_800B2204;
    }
    // 0x800B21F0: nop

    // 0x800B21F4: jal         0x800B25A0
    // 0x800B21F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    particle_deallocate(rdram, ctx);
        goto after_24;
    // 0x800B21F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x800B21FC: b           L_800B2204
    // 0x800B2200: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B2204;
    // 0x800B2200: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B2204:
    // 0x800B2204: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2208: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800B220C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800B2210: jr          $ra
    // 0x800B2214: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800B2214: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void particle_allocate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2218: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800B221C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800B2220: beq         $a0, $a1, L_800B22FC
    if (ctx->r4 == ctx->r5) {
        // 0x800B2224: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800B22FC;
    }
    // 0x800B2224: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B2228: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800B222C: beq         $a0, $a3, L_800B23A4
    if (ctx->r4 == ctx->r7) {
        // 0x800B2230: lui         $t0, 0x800E
        ctx->r8 = S32(0X800E << 16);
            goto L_800B23A4;
    }
    // 0x800B2230: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800B2234: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x800B2238: beq         $a0, $a3, L_800B2448
    if (ctx->r4 == ctx->r7) {
        // 0x800B223C: lui         $t0, 0x800E
        ctx->r8 = S32(0X800E << 16);
            goto L_800B2448;
    }
    // 0x800B223C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800B2240: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x800B2244: beq         $a0, $a2, L_800B24EC
    if (ctx->r4 == ctx->r6) {
        // 0x800B2248: lui         $a3, 0x800E
        ctx->r7 = S32(0X800E << 16);
            goto L_800B24EC;
    }
    // 0x800B2248: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800B224C: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    // 0x800B2250: bne         $a0, $a3, L_800B258C
    if (ctx->r4 != ctx->r7) {
        // 0x800B2254: lui         $t0, 0x800E
        ctx->r8 = S32(0X800E << 16);
            goto L_800B258C;
    }
    // 0x800B2254: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800B2258: addiu       $t0, $t0, 0x3250
    ctx->r8 = ADD32(ctx->r8, 0X3250);
    // 0x800B225C: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x800B2260: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800B2264: beq         $a0, $zero, L_800B258C
    if (ctx->r4 == 0) {
        // 0x800B2268: addiu       $t1, $t1, 0x3248
        ctx->r9 = ADD32(ctx->r9, 0X3248);
            goto L_800B258C;
    }
    // 0x800B2268: addiu       $t1, $t1, 0x3248
    ctx->r9 = ADD32(ctx->r9, 0X3248);
    // 0x800B226C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800B2270: lw          $t7, 0x33E4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X33E4);
    // 0x800B2274: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800B2278: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800B227C: slt         $at, $t6, $t8
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800B2280: bne         $at, $zero, L_800B22A8
    if (ctx->r1 != 0) {
        // 0x800B2284: nop
    
            goto L_800B22A8;
    }
    // 0x800B2284: nop

    // 0x800B2288: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B228C: addiu       $v0, $v0, 0x324C
    ctx->r2 = ADD32(ctx->r2, 0X324C);
    // 0x800B2290: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800B2294: nop

    // 0x800B2298: bne         $t9, $zero, L_800B258C
    if (ctx->r25 != 0) {
        // 0x800B229C: nop
    
            goto L_800B258C;
    }
    // 0x800B229C: nop

    // 0x800B22A0: b           L_800B258C
    // 0x800B22A4: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
        goto L_800B258C;
    // 0x800B22A4: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
L_800B22A8:
    // 0x800B22A8: lh          $t2, 0x2C($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X2C);
    // 0x800B22AC: sll         $t3, $v0, 3
    ctx->r11 = S32(ctx->r2 << 3);
    // 0x800B22B0: beq         $t2, $zero, L_800B22D0
    if (ctx->r10 == 0) {
        // 0x800B22B4: subu        $t3, $t3, $v0
        ctx->r11 = SUB32(ctx->r11, ctx->r2);
            goto L_800B22D0;
    }
    // 0x800B22B4: subu        $t3, $t3, $v0
    ctx->r11 = SUB32(ctx->r11, ctx->r2);
    // 0x800B22B8: sll         $t3, $t3, 4
    ctx->r11 = S32(ctx->r11 << 4);
    // 0x800B22BC: addu        $v1, $a0, $t3
    ctx->r3 = ADD32(ctx->r4, ctx->r11);
L_800B22C0:
    // 0x800B22C0: lh          $t4, 0x9C($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X9C);
    // 0x800B22C4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B22C8: bne         $t4, $zero, L_800B22C0
    if (ctx->r12 != 0) {
        // 0x800B22CC: addiu       $v1, $v1, 0x70
        ctx->r3 = ADD32(ctx->r3, 0X70);
            goto L_800B22C0;
    }
    // 0x800B22CC: addiu       $v1, $v1, 0x70
    ctx->r3 = ADD32(ctx->r3, 0X70);
L_800B22D0:
    // 0x800B22D0: sll         $a2, $v0, 3
    ctx->r6 = S32(ctx->r2 << 3);
    // 0x800B22D4: subu        $a2, $a2, $v0
    ctx->r6 = SUB32(ctx->r6, ctx->r2);
    // 0x800B22D8: sll         $a2, $a2, 4
    ctx->r6 = S32(ctx->r6 << 4);
    // 0x800B22DC: addu        $t5, $a0, $a2
    ctx->r13 = ADD32(ctx->r4, ctx->r6);
    // 0x800B22E0: sh          $a3, 0x2C($t5)
    MEM_H(0X2C, ctx->r13) = ctx->r7;
    // 0x800B22E4: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800B22E8: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800B22EC: addiu       $t6, $t7, 0x1
    ctx->r14 = ADD32(ctx->r15, 0X1);
    // 0x800B22F0: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x800B22F4: b           L_800B258C
    // 0x800B22F8: addu        $v1, $a2, $t8
    ctx->r3 = ADD32(ctx->r6, ctx->r24);
        goto L_800B258C;
    // 0x800B22F8: addu        $v1, $a2, $t8
    ctx->r3 = ADD32(ctx->r6, ctx->r24);
L_800B22FC:
    // 0x800B22FC: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800B2300: addiu       $a3, $a3, 0x3238
    ctx->r7 = ADD32(ctx->r7, 0X3238);
    // 0x800B2304: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x800B2308: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800B230C: beq         $a0, $zero, L_800B258C
    if (ctx->r4 == 0) {
        // 0x800B2310: addiu       $t0, $t0, 0x3230
        ctx->r8 = ADD32(ctx->r8, 0X3230);
            goto L_800B258C;
    }
    // 0x800B2310: addiu       $t0, $t0, 0x3230
    ctx->r8 = ADD32(ctx->r8, 0X3230);
    // 0x800B2314: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800B2318: lw          $t2, 0x33DC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X33DC);
    // 0x800B231C: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800B2320: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x800B2324: slt         $at, $t9, $t3
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800B2328: bne         $at, $zero, L_800B2350
    if (ctx->r1 != 0) {
        // 0x800B232C: nop
    
            goto L_800B2350;
    }
    // 0x800B232C: nop

    // 0x800B2330: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B2334: addiu       $v0, $v0, 0x3234
    ctx->r2 = ADD32(ctx->r2, 0X3234);
    // 0x800B2338: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x800B233C: nop

    // 0x800B2340: bne         $t4, $zero, L_800B258C
    if (ctx->r12 != 0) {
        // 0x800B2344: nop
    
            goto L_800B258C;
    }
    // 0x800B2344: nop

    // 0x800B2348: b           L_800B258C
    // 0x800B234C: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
        goto L_800B258C;
    // 0x800B234C: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
L_800B2350:
    // 0x800B2350: lh          $t5, 0x2C($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X2C);
    // 0x800B2354: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x800B2358: beq         $t5, $zero, L_800B2378
    if (ctx->r13 == 0) {
        // 0x800B235C: subu        $t7, $t7, $v0
        ctx->r15 = SUB32(ctx->r15, ctx->r2);
            goto L_800B2378;
    }
    // 0x800B235C: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x800B2360: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x800B2364: addu        $v1, $a0, $t7
    ctx->r3 = ADD32(ctx->r4, ctx->r15);
L_800B2368:
    // 0x800B2368: lh          $t6, 0x9C($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X9C);
    // 0x800B236C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B2370: bne         $t6, $zero, L_800B2368
    if (ctx->r14 != 0) {
        // 0x800B2374: addiu       $v1, $v1, 0x70
        ctx->r3 = ADD32(ctx->r3, 0X70);
            goto L_800B2368;
    }
    // 0x800B2374: addiu       $v1, $v1, 0x70
    ctx->r3 = ADD32(ctx->r3, 0X70);
L_800B2378:
    // 0x800B2378: sll         $a2, $v0, 3
    ctx->r6 = S32(ctx->r2 << 3);
    // 0x800B237C: subu        $a2, $a2, $v0
    ctx->r6 = SUB32(ctx->r6, ctx->r2);
    // 0x800B2380: sll         $a2, $a2, 4
    ctx->r6 = S32(ctx->r6 << 4);
    // 0x800B2384: addu        $t8, $a0, $a2
    ctx->r24 = ADD32(ctx->r4, ctx->r6);
    // 0x800B2388: sh          $a1, 0x2C($t8)
    MEM_H(0X2C, ctx->r24) = ctx->r5;
    // 0x800B238C: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x800B2390: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x800B2394: addiu       $t9, $t2, 0x1
    ctx->r25 = ADD32(ctx->r10, 0X1);
    // 0x800B2398: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800B239C: b           L_800B258C
    // 0x800B23A0: addu        $v1, $a2, $t3
    ctx->r3 = ADD32(ctx->r6, ctx->r11);
        goto L_800B258C;
    // 0x800B23A0: addu        $v1, $a2, $t3
    ctx->r3 = ADD32(ctx->r6, ctx->r11);
L_800B23A4:
    // 0x800B23A4: addiu       $t0, $t0, 0x3244
    ctx->r8 = ADD32(ctx->r8, 0X3244);
    // 0x800B23A8: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x800B23AC: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800B23B0: beq         $a0, $zero, L_800B258C
    if (ctx->r4 == 0) {
        // 0x800B23B4: addiu       $t1, $t1, 0x323C
        ctx->r9 = ADD32(ctx->r9, 0X323C);
            goto L_800B258C;
    }
    // 0x800B23B4: addiu       $t1, $t1, 0x323C
    ctx->r9 = ADD32(ctx->r9, 0X323C);
    // 0x800B23B8: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800B23BC: lw          $t5, 0x33E0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X33E0);
    // 0x800B23C0: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800B23C4: addiu       $t7, $t5, -0x1
    ctx->r15 = ADD32(ctx->r13, -0X1);
    // 0x800B23C8: slt         $at, $t4, $t7
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800B23CC: bne         $at, $zero, L_800B23F4
    if (ctx->r1 != 0) {
        // 0x800B23D0: nop
    
            goto L_800B23F4;
    }
    // 0x800B23D0: nop

    // 0x800B23D4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B23D8: addiu       $v0, $v0, 0x3240
    ctx->r2 = ADD32(ctx->r2, 0X3240);
    // 0x800B23DC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800B23E0: nop

    // 0x800B23E4: bne         $t6, $zero, L_800B258C
    if (ctx->r14 != 0) {
        // 0x800B23E8: nop
    
            goto L_800B258C;
    }
    // 0x800B23E8: nop

    // 0x800B23EC: b           L_800B258C
    // 0x800B23F0: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
        goto L_800B258C;
    // 0x800B23F0: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
L_800B23F4:
    // 0x800B23F4: lh          $t8, 0x2C($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X2C);
    // 0x800B23F8: sll         $t2, $v0, 3
    ctx->r10 = S32(ctx->r2 << 3);
    // 0x800B23FC: beq         $t8, $zero, L_800B241C
    if (ctx->r24 == 0) {
        // 0x800B2400: subu        $t2, $t2, $v0
        ctx->r10 = SUB32(ctx->r10, ctx->r2);
            goto L_800B241C;
    }
    // 0x800B2400: subu        $t2, $t2, $v0
    ctx->r10 = SUB32(ctx->r10, ctx->r2);
    // 0x800B2404: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x800B2408: addu        $v1, $a0, $t2
    ctx->r3 = ADD32(ctx->r4, ctx->r10);
L_800B240C:
    // 0x800B240C: lh          $t9, 0x9C($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X9C);
    // 0x800B2410: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B2414: bne         $t9, $zero, L_800B240C
    if (ctx->r25 != 0) {
        // 0x800B2418: addiu       $v1, $v1, 0x70
        ctx->r3 = ADD32(ctx->r3, 0X70);
            goto L_800B240C;
    }
    // 0x800B2418: addiu       $v1, $v1, 0x70
    ctx->r3 = ADD32(ctx->r3, 0X70);
L_800B241C:
    // 0x800B241C: sll         $a2, $v0, 3
    ctx->r6 = S32(ctx->r2 << 3);
    // 0x800B2420: subu        $a2, $a2, $v0
    ctx->r6 = SUB32(ctx->r6, ctx->r2);
    // 0x800B2424: sll         $a2, $a2, 4
    ctx->r6 = S32(ctx->r6 << 4);
    // 0x800B2428: addu        $t3, $a0, $a2
    ctx->r11 = ADD32(ctx->r4, ctx->r6);
    // 0x800B242C: sh          $a3, 0x2C($t3)
    MEM_H(0X2C, ctx->r11) = ctx->r7;
    // 0x800B2430: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800B2434: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800B2438: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x800B243C: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x800B2440: b           L_800B258C
    // 0x800B2444: addu        $v1, $a2, $t7
    ctx->r3 = ADD32(ctx->r6, ctx->r15);
        goto L_800B258C;
    // 0x800B2444: addu        $v1, $a2, $t7
    ctx->r3 = ADD32(ctx->r6, ctx->r15);
L_800B2448:
    // 0x800B2448: addiu       $t0, $t0, 0x325C
    ctx->r8 = ADD32(ctx->r8, 0X325C);
    // 0x800B244C: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x800B2450: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800B2454: beq         $a0, $zero, L_800B258C
    if (ctx->r4 == 0) {
        // 0x800B2458: addiu       $t1, $t1, 0x3254
        ctx->r9 = ADD32(ctx->r9, 0X3254);
            goto L_800B258C;
    }
    // 0x800B2458: addiu       $t1, $t1, 0x3254
    ctx->r9 = ADD32(ctx->r9, 0X3254);
    // 0x800B245C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800B2460: lw          $t8, 0x33E8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X33E8);
    // 0x800B2464: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800B2468: addiu       $t2, $t8, -0x1
    ctx->r10 = ADD32(ctx->r24, -0X1);
    // 0x800B246C: slt         $at, $t6, $t2
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800B2470: bne         $at, $zero, L_800B2498
    if (ctx->r1 != 0) {
        // 0x800B2474: nop
    
            goto L_800B2498;
    }
    // 0x800B2474: nop

    // 0x800B2478: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B247C: addiu       $v0, $v0, 0x3258
    ctx->r2 = ADD32(ctx->r2, 0X3258);
    // 0x800B2480: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800B2484: nop

    // 0x800B2488: bne         $t9, $zero, L_800B258C
    if (ctx->r25 != 0) {
        // 0x800B248C: nop
    
            goto L_800B258C;
    }
    // 0x800B248C: nop

    // 0x800B2490: b           L_800B258C
    // 0x800B2494: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
        goto L_800B258C;
    // 0x800B2494: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
L_800B2498:
    // 0x800B2498: lh          $t3, 0x2C($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X2C);
    // 0x800B249C: sll         $t5, $v0, 3
    ctx->r13 = S32(ctx->r2 << 3);
    // 0x800B24A0: beq         $t3, $zero, L_800B24C0
    if (ctx->r11 == 0) {
        // 0x800B24A4: subu        $t5, $t5, $v0
        ctx->r13 = SUB32(ctx->r13, ctx->r2);
            goto L_800B24C0;
    }
    // 0x800B24A4: subu        $t5, $t5, $v0
    ctx->r13 = SUB32(ctx->r13, ctx->r2);
    // 0x800B24A8: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x800B24AC: addu        $v1, $a0, $t5
    ctx->r3 = ADD32(ctx->r4, ctx->r13);
L_800B24B0:
    // 0x800B24B0: lh          $t4, 0x9C($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X9C);
    // 0x800B24B4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B24B8: bne         $t4, $zero, L_800B24B0
    if (ctx->r12 != 0) {
        // 0x800B24BC: addiu       $v1, $v1, 0x70
        ctx->r3 = ADD32(ctx->r3, 0X70);
            goto L_800B24B0;
    }
    // 0x800B24BC: addiu       $v1, $v1, 0x70
    ctx->r3 = ADD32(ctx->r3, 0X70);
L_800B24C0:
    // 0x800B24C0: sll         $a2, $v0, 3
    ctx->r6 = S32(ctx->r2 << 3);
    // 0x800B24C4: subu        $a2, $a2, $v0
    ctx->r6 = SUB32(ctx->r6, ctx->r2);
    // 0x800B24C8: sll         $a2, $a2, 4
    ctx->r6 = S32(ctx->r6 << 4);
    // 0x800B24CC: addu        $t7, $a0, $a2
    ctx->r15 = ADD32(ctx->r4, ctx->r6);
    // 0x800B24D0: sh          $a3, 0x2C($t7)
    MEM_H(0X2C, ctx->r15) = ctx->r7;
    // 0x800B24D4: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800B24D8: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x800B24DC: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x800B24E0: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x800B24E4: b           L_800B258C
    // 0x800B24E8: addu        $v1, $a2, $t2
    ctx->r3 = ADD32(ctx->r6, ctx->r10);
        goto L_800B258C;
    // 0x800B24E8: addu        $v1, $a2, $t2
    ctx->r3 = ADD32(ctx->r6, ctx->r10);
L_800B24EC:
    // 0x800B24EC: addiu       $a3, $a3, 0x3268
    ctx->r7 = ADD32(ctx->r7, 0X3268);
    // 0x800B24F0: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x800B24F4: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800B24F8: beq         $a0, $zero, L_800B258C
    if (ctx->r4 == 0) {
        // 0x800B24FC: addiu       $t0, $t0, 0x3260
        ctx->r8 = ADD32(ctx->r8, 0X3260);
            goto L_800B258C;
    }
    // 0x800B24FC: addiu       $t0, $t0, 0x3260
    ctx->r8 = ADD32(ctx->r8, 0X3260);
    // 0x800B2500: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800B2504: lw          $t3, 0x33EC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X33EC);
    // 0x800B2508: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800B250C: addiu       $t5, $t3, -0x1
    ctx->r13 = ADD32(ctx->r11, -0X1);
    // 0x800B2510: slt         $at, $t9, $t5
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800B2514: bne         $at, $zero, L_800B253C
    if (ctx->r1 != 0) {
        // 0x800B2518: nop
    
            goto L_800B253C;
    }
    // 0x800B2518: nop

    // 0x800B251C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B2520: addiu       $v0, $v0, 0x3264
    ctx->r2 = ADD32(ctx->r2, 0X3264);
    // 0x800B2524: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x800B2528: nop

    // 0x800B252C: bne         $t4, $zero, L_800B258C
    if (ctx->r12 != 0) {
        // 0x800B2530: nop
    
            goto L_800B258C;
    }
    // 0x800B2530: nop

    // 0x800B2534: b           L_800B258C
    // 0x800B2538: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
        goto L_800B258C;
    // 0x800B2538: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
L_800B253C:
    // 0x800B253C: lh          $t7, 0x2C($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X2C);
    // 0x800B2540: sll         $t8, $v0, 4
    ctx->r24 = S32(ctx->r2 << 4);
    // 0x800B2544: beq         $t7, $zero, L_800B2564
    if (ctx->r15 == 0) {
        // 0x800B2548: subu        $t8, $t8, $v0
        ctx->r24 = SUB32(ctx->r24, ctx->r2);
            goto L_800B2564;
    }
    // 0x800B2548: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x800B254C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800B2550: addu        $v1, $a0, $t8
    ctx->r3 = ADD32(ctx->r4, ctx->r24);
L_800B2554:
    // 0x800B2554: lh          $t6, 0xA4($v1)
    ctx->r14 = MEM_H(ctx->r3, 0XA4);
    // 0x800B2558: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B255C: bne         $t6, $zero, L_800B2554
    if (ctx->r14 != 0) {
        // 0x800B2560: addiu       $v1, $v1, 0x78
        ctx->r3 = ADD32(ctx->r3, 0X78);
            goto L_800B2554;
    }
    // 0x800B2560: addiu       $v1, $v1, 0x78
    ctx->r3 = ADD32(ctx->r3, 0X78);
L_800B2564:
    // 0x800B2564: sll         $a1, $v0, 4
    ctx->r5 = S32(ctx->r2 << 4);
    // 0x800B2568: subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
    // 0x800B256C: sll         $a1, $a1, 3
    ctx->r5 = S32(ctx->r5 << 3);
    // 0x800B2570: addu        $t2, $a0, $a1
    ctx->r10 = ADD32(ctx->r4, ctx->r5);
    // 0x800B2574: sh          $a2, 0x2C($t2)
    MEM_H(0X2C, ctx->r10) = ctx->r6;
    // 0x800B2578: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800B257C: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x800B2580: addiu       $t9, $t3, 0x1
    ctx->r25 = ADD32(ctx->r11, 0X1);
    // 0x800B2584: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800B2588: addu        $v1, $a1, $t5
    ctx->r3 = ADD32(ctx->r5, ctx->r13);
L_800B258C:
    // 0x800B258C: beq         $v1, $zero, L_800B2598
    if (ctx->r3 == 0) {
        // 0x800B2590: addiu       $t4, $zero, -0x1
        ctx->r12 = ADD32(0, -0X1);
            goto L_800B2598;
    }
    // 0x800B2590: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800B2594: sh          $t4, 0x48($v1)
    MEM_H(0X48, ctx->r3) = ctx->r12;
L_800B2598:
    // 0x800B2598: jr          $ra
    // 0x800B259C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800B259C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void particle_deallocate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B25A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B25A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B25A8: lh          $v0, 0x2C($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2C);
    // 0x800B25AC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800B25B0: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x800B25B4: bne         $at, $zero, L_800B25CC
    if (ctx->r1 != 0) {
        // 0x800B25B8: addiu       $at, $zero, 0x80
        ctx->r1 = ADD32(0, 0X80);
            goto L_800B25CC;
    }
    // 0x800B25B8: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x800B25BC: beq         $v0, $at, L_800B25F0
    if (ctx->r2 == ctx->r1) {
        // 0x800B25C0: nop
    
            goto L_800B25F0;
    }
    // 0x800B25C0: nop

    // 0x800B25C4: b           L_800B27B4
    // 0x800B25C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800B27B4;
    // 0x800B25C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800B25CC:
    // 0x800B25CC: sltiu       $at, $v0, 0x5
    ctx->r1 = ctx->r2 < 0X5 ? 1 : 0;
    // 0x800B25D0: beq         $at, $zero, L_800B27B0
    if (ctx->r1 == 0) {
        // 0x800B25D4: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_800B27B0;
    }
    // 0x800B25D4: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800B25D8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B25DC: addu        $at, $at, $t6
    gpr jr_addend_800B25E8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800B25E0: lw          $t6, -0x6EA4($at)
    ctx->r14 = ADD32(ctx->r1, -0X6EA4);
    // 0x800B25E4: nop

    // 0x800B25E8: jr          $t6
    // 0x800B25EC: nop

    switch (jr_addend_800B25E8 >> 2) {
        case 0: goto L_800B27B0; break;
        case 1: goto L_800B2640; break;
        case 2: goto L_800B2698; break;
        case 3: goto L_800B26F0; break;
        case 4: goto L_800B2748; break;
        default: switch_error(__func__, 0x800B25E8, 0x800E915C);
    }
    // 0x800B25EC: nop

L_800B25F0:
    // 0x800B25F0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B25F4: lw          $v0, 0x3248($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3248);
    // 0x800B25F8: nop

    // 0x800B25FC: blez        $v0, L_800B27B4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800B2600: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B27B4;
    }
    // 0x800B2600: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B2604: lw          $a0, 0x44($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X44);
    // 0x800B2608: nop

    // 0x800B260C: beq         $a0, $zero, L_800B2630
    if (ctx->r4 == 0) {
        // 0x800B2610: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_800B2630;
    }
    // 0x800B2610: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x800B2614: jal         0x8007D100
    // 0x800B2618: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    sprite_free(rdram, ctx);
        goto after_0;
    // 0x800B2618: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x800B261C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B2620: lw          $v0, 0x3248($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3248);
    // 0x800B2624: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800B2628: nop

    // 0x800B262C: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
L_800B2630:
    // 0x800B2630: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B2634: sw          $t7, 0x3248($at)
    MEM_W(0X3248, ctx->r1) = ctx->r15;
    // 0x800B2638: b           L_800B27B0
    // 0x800B263C: sh          $zero, 0x2C($a1)
    MEM_H(0X2C, ctx->r5) = 0;
        goto L_800B27B0;
    // 0x800B263C: sh          $zero, 0x2C($a1)
    MEM_H(0X2C, ctx->r5) = 0;
L_800B2640:
    // 0x800B2640: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B2644: lw          $v0, 0x3230($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3230);
    // 0x800B2648: nop

    // 0x800B264C: blez        $v0, L_800B27B4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800B2650: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B27B4;
    }
    // 0x800B2650: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B2654: lw          $t8, 0x44($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X44);
    // 0x800B2658: nop

    // 0x800B265C: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x800B2660: nop

    // 0x800B2664: beq         $a0, $zero, L_800B2688
    if (ctx->r4 == 0) {
        // 0x800B2668: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_800B2688;
    }
    // 0x800B2668: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x800B266C: jal         0x8007B70C
    // 0x800B2670: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    tex_free(rdram, ctx);
        goto after_1;
    // 0x800B2670: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x800B2674: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B2678: lw          $v0, 0x3230($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3230);
    // 0x800B267C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800B2680: nop

    // 0x800B2684: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
L_800B2688:
    // 0x800B2688: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B268C: sw          $t9, 0x3230($at)
    MEM_W(0X3230, ctx->r1) = ctx->r25;
    // 0x800B2690: b           L_800B27B0
    // 0x800B2694: sh          $zero, 0x2C($a1)
    MEM_H(0X2C, ctx->r5) = 0;
        goto L_800B27B0;
    // 0x800B2694: sh          $zero, 0x2C($a1)
    MEM_H(0X2C, ctx->r5) = 0;
L_800B2698:
    // 0x800B2698: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B269C: lw          $v0, 0x323C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X323C);
    // 0x800B26A0: nop

    // 0x800B26A4: blez        $v0, L_800B27B4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800B26A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B27B4;
    }
    // 0x800B26A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B26AC: lw          $t0, 0x44($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X44);
    // 0x800B26B0: nop

    // 0x800B26B4: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x800B26B8: nop

    // 0x800B26BC: beq         $a0, $zero, L_800B26E0
    if (ctx->r4 == 0) {
        // 0x800B26C0: addiu       $t1, $v0, -0x1
        ctx->r9 = ADD32(ctx->r2, -0X1);
            goto L_800B26E0;
    }
    // 0x800B26C0: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x800B26C4: jal         0x8007B70C
    // 0x800B26C8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    tex_free(rdram, ctx);
        goto after_2;
    // 0x800B26C8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_2:
    // 0x800B26CC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B26D0: lw          $v0, 0x323C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X323C);
    // 0x800B26D4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800B26D8: nop

    // 0x800B26DC: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
L_800B26E0:
    // 0x800B26E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B26E4: sw          $t1, 0x323C($at)
    MEM_W(0X323C, ctx->r1) = ctx->r9;
    // 0x800B26E8: b           L_800B27B0
    // 0x800B26EC: sh          $zero, 0x2C($a1)
    MEM_H(0X2C, ctx->r5) = 0;
        goto L_800B27B0;
    // 0x800B26EC: sh          $zero, 0x2C($a1)
    MEM_H(0X2C, ctx->r5) = 0;
L_800B26F0:
    // 0x800B26F0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B26F4: lw          $v0, 0x3254($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3254);
    // 0x800B26F8: nop

    // 0x800B26FC: blez        $v0, L_800B27B4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800B2700: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B27B4;
    }
    // 0x800B2700: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B2704: lw          $t2, 0x44($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X44);
    // 0x800B2708: nop

    // 0x800B270C: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x800B2710: nop

    // 0x800B2714: beq         $a0, $zero, L_800B2738
    if (ctx->r4 == 0) {
        // 0x800B2718: addiu       $t3, $v0, -0x1
        ctx->r11 = ADD32(ctx->r2, -0X1);
            goto L_800B2738;
    }
    // 0x800B2718: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x800B271C: jal         0x8007B70C
    // 0x800B2720: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    tex_free(rdram, ctx);
        goto after_3;
    // 0x800B2720: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_3:
    // 0x800B2724: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B2728: lw          $v0, 0x3254($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3254);
    // 0x800B272C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800B2730: nop

    // 0x800B2734: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
L_800B2738:
    // 0x800B2738: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B273C: sw          $t3, 0x3254($at)
    MEM_W(0X3254, ctx->r1) = ctx->r11;
    // 0x800B2740: b           L_800B27B0
    // 0x800B2744: sh          $zero, 0x2C($a1)
    MEM_H(0X2C, ctx->r5) = 0;
        goto L_800B27B0;
    // 0x800B2744: sh          $zero, 0x2C($a1)
    MEM_H(0X2C, ctx->r5) = 0;
L_800B2748:
    // 0x800B2748: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800B274C: lw          $t4, 0x3260($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3260);
    // 0x800B2750: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800B2754: blez        $t4, L_800B27B4
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800B2758: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B27B4;
    }
    // 0x800B2758: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B275C: jal         0x800B2B9C
    // 0x800B2760: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    delete_point_particle_from_sequence(rdram, ctx);
        goto after_4;
    // 0x800B2760: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_4:
    // 0x800B2764: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800B2768: nop

    // 0x800B276C: lw          $t5, 0x44($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X44);
    // 0x800B2770: nop

    // 0x800B2774: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x800B2778: nop

    // 0x800B277C: beq         $a0, $zero, L_800B2794
    if (ctx->r4 == 0) {
        // 0x800B2780: nop
    
            goto L_800B2794;
    }
    // 0x800B2780: nop

    // 0x800B2784: jal         0x8007B70C
    // 0x800B2788: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    tex_free(rdram, ctx);
        goto after_5;
    // 0x800B2788: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_5:
    // 0x800B278C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800B2790: nop

L_800B2794:
    // 0x800B2794: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B2798: addiu       $v0, $v0, 0x3260
    ctx->r2 = ADD32(ctx->r2, 0X3260);
    // 0x800B279C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800B27A0: nop

    // 0x800B27A4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800B27A8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B27AC: sh          $zero, 0x2C($a1)
    MEM_H(0X2C, ctx->r5) = 0;
L_800B27B0:
    // 0x800B27B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800B27B4:
    // 0x800B27B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B27B8: jr          $ra
    // 0x800B27BC: nop

    return;
    // 0x800B27BC: nop

;}
RECOMP_FUNC void emitter_cleanup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B27C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B27C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B27C8: lh          $t6, 0x4($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X4);
    // 0x800B27CC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800B27D0: andi        $t7, $t6, 0x400
    ctx->r15 = ctx->r14 & 0X400;
    // 0x800B27D4: beq         $t7, $zero, L_800B2850
    if (ctx->r15 == 0) {
        // 0x800B27D8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B2850;
    }
    // 0x800B27D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B27DC: lw          $a0, 0xC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XC);
    // 0x800B27E0: nop

    // 0x800B27E4: beq         $a0, $zero, L_800B2850
    if (ctx->r4 == 0) {
        // 0x800B27E8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B2850;
    }
    // 0x800B27E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B27EC: lbu         $t8, 0x6($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X6);
    // 0x800B27F0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800B27F4: blez        $t8, L_800B2838
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800B27F8: nop
    
            goto L_800B2838;
    }
    // 0x800B27F8: nop

    // 0x800B27FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800B2800:
    // 0x800B2800: lw          $t9, 0xC($a1)
    ctx->r25 = MEM_W(ctx->r5, 0XC);
    // 0x800B2804: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800B2808: addu        $t0, $t9, $a0
    ctx->r8 = ADD32(ctx->r25, ctx->r4);
    // 0x800B280C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800B2810: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800B2814: sh          $zero, 0x3A($v0)
    MEM_H(0X3A, ctx->r2) = 0;
    // 0x800B2818: sw          $zero, 0x70($v0)
    MEM_W(0X70, ctx->r2) = 0;
    // 0x800B281C: lbu         $t1, 0x6($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X6);
    // 0x800B2820: nop

    // 0x800B2824: slt         $at, $v1, $t1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800B2828: bne         $at, $zero, L_800B2800
    if (ctx->r1 != 0) {
        // 0x800B282C: nop
    
            goto L_800B2800;
    }
    // 0x800B282C: nop

    // 0x800B2830: lw          $a0, 0xC($a1)
    ctx->r4 = MEM_W(ctx->r5, 0XC);
    // 0x800B2834: nop

L_800B2838:
    // 0x800B2838: jal         0x80071380
    // 0x800B283C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    mempool_free(rdram, ctx);
        goto after_0;
    // 0x800B283C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x800B2840: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800B2844: nop

    // 0x800B2848: sw          $zero, 0xC($a1)
    MEM_W(0XC, ctx->r5) = 0;
    // 0x800B284C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800B2850:
    // 0x800B2850: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B2854: jr          $ra
    // 0x800B2858: nop

    return;
    // 0x800B2858: nop

;}
RECOMP_FUNC void particle_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B285C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B2860: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B2864: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B2868: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B286C: sw          $a1, -0x7DC0($at)
    MEM_W(-0X7DC0, ctx->r1) = ctx->r5;
    // 0x800B2870: lh          $v0, 0x2C($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2C);
    // 0x800B2874: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B2878: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800B287C: bne         $v0, $at, L_800B2894
    if (ctx->r2 != ctx->r1) {
        // 0x800B2880: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800B2894;
    }
    // 0x800B2880: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800B2884: jal         0x800B2C40
    // 0x800B2888: nop

    update_line_particle(rdram, ctx);
        goto after_0;
    // 0x800B2888: nop

    after_0:
    // 0x800B288C: b           L_800B2B90
    // 0x800B2890: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800B2B90;
    // 0x800B2890: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800B2894:
    // 0x800B2894: lw          $t6, 0x40($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X40);
    // 0x800B2898: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800B289C: andi        $t7, $t6, 0x3
    ctx->r15 = ctx->r14 & 0X3;
    // 0x800B28A0: beq         $t7, $zero, L_800B28D0
    if (ctx->r15 == 0) {
        // 0x800B28A4: addiu       $a0, $zero, 0x4
        ctx->r4 = ADD32(0, 0X4);
            goto L_800B28D0;
    }
    // 0x800B28A4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800B28A8: lw          $t8, -0x7DC0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7DC0);
    // 0x800B28AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B28B0: blez        $t8, L_800B28CC
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800B28B4: nop
    
            goto L_800B28CC;
    }
    // 0x800B28B4: nop

    // 0x800B28B8: jal         0x800B351C
    // 0x800B28BC: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    update_particle_texture_frame(rdram, ctx);
        goto after_1;
    // 0x800B28BC: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_1:
    // 0x800B28C0: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x800B28C4: lh          $v0, 0x2C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X2C);
    // 0x800B28C8: nop

L_800B28CC:
    // 0x800B28CC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
L_800B28D0:
    // 0x800B28D0: bne         $a0, $v0, L_800B28EC
    if (ctx->r4 != ctx->r2) {
        // 0x800B28D4: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_800B28EC;
    }
    // 0x800B28D4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800B28D8: lbu         $t9, 0x75($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X75);
    // 0x800B28DC: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800B28E0: subu        $t1, $t0, $t9
    ctx->r9 = SUB32(ctx->r8, ctx->r25);
    // 0x800B28E4: sb          $t1, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r9;
    // 0x800B28E8: sb          $zero, 0x77($s0)
    MEM_B(0X77, ctx->r16) = 0;
L_800B28EC:
    // 0x800B28EC: beq         $v1, $zero, L_800B290C
    if (ctx->r3 == 0) {
        // 0x800B28F0: nop
    
            goto L_800B290C;
    }
    // 0x800B28F0: nop

    // 0x800B28F4: beq         $v1, $zero, L_800B2980
    if (ctx->r3 == 0) {
        // 0x800B28F8: nop
    
            goto L_800B2980;
    }
    // 0x800B28F8: nop

    // 0x800B28FC: lw          $t2, 0x70($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X70);
    // 0x800B2900: nop

    // 0x800B2904: beq         $t2, $zero, L_800B2980
    if (ctx->r10 == 0) {
        // 0x800B2908: nop
    
            goto L_800B2980;
    }
    // 0x800B2908: nop

L_800B290C:
    // 0x800B290C: lbu         $v0, 0x39($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X39);
    // 0x800B2910: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B2914: bne         $v0, $at, L_800B2930
    if (ctx->r2 != ctx->r1) {
        // 0x800B2918: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800B2930;
    }
    // 0x800B2918: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B291C: jal         0x800B38B8
    // 0x800B2920: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    move_particle_with_acceleration(rdram, ctx);
        goto after_2;
    // 0x800B2920: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800B2924: b           L_800B2984
    // 0x800B2928: lh          $a0, 0x2E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2E);
        goto L_800B2984;
    // 0x800B2928: lh          $a0, 0x2E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2E);
    // 0x800B292C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_800B2930:
    // 0x800B2930: bne         $v0, $at, L_800B2948
    if (ctx->r2 != ctx->r1) {
        // 0x800B2934: nop
    
            goto L_800B2948;
    }
    // 0x800B2934: nop

    // 0x800B2938: jal         0x800B37A0
    // 0x800B293C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    move_particle_attached_to_parent(rdram, ctx);
        goto after_3;
    // 0x800B293C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800B2940: b           L_800B2984
    // 0x800B2944: lh          $a0, 0x2E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2E);
        goto L_800B2984;
    // 0x800B2944: lh          $a0, 0x2E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2E);
L_800B2948:
    // 0x800B2948: bne         $a0, $v0, L_800B2960
    if (ctx->r4 != ctx->r2) {
        // 0x800B294C: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_800B2960;
    }
    // 0x800B294C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800B2950: jal         0x800B36A0
    // 0x800B2954: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    move_particle_basic_parent(rdram, ctx);
        goto after_4;
    // 0x800B2954: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800B2958: b           L_800B2984
    // 0x800B295C: lh          $a0, 0x2E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2E);
        goto L_800B2984;
    // 0x800B295C: lh          $a0, 0x2E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2E);
L_800B2960:
    // 0x800B2960: bne         $v0, $at, L_800B2978
    if (ctx->r2 != ctx->r1) {
        // 0x800B2964: nop
    
            goto L_800B2978;
    }
    // 0x800B2964: nop

    // 0x800B2968: jal         0x800B3AC4
    // 0x800B296C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    move_particle_forward(rdram, ctx);
        goto after_5;
    // 0x800B296C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x800B2970: b           L_800B2984
    // 0x800B2974: lh          $a0, 0x2E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2E);
        goto L_800B2984;
    // 0x800B2974: lh          $a0, 0x2E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2E);
L_800B2978:
    // 0x800B2978: jal         0x800B3A10
    // 0x800B297C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    move_particle_basic(rdram, ctx);
        goto after_6;
    // 0x800B297C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_800B2980:
    // 0x800B2980: lh          $a0, 0x2E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2E);
L_800B2984:
    // 0x800B2984: jal         0x8002A31C
    // 0x800B2988: nop

    block_boundbox(rdram, ctx);
        goto after_7;
    // 0x800B2988: nop

    after_7:
    // 0x800B298C: beq         $v0, $zero, L_800B2A84
    if (ctx->r2 == 0) {
        // 0x800B2990: nop
    
            goto L_800B2A84;
    }
    // 0x800B2990: nop

    // 0x800B2994: lh          $t3, 0x0($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X0);
    // 0x800B2998: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800B299C: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x800B29A0: nop

    // 0x800B29A4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B29A8: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x800B29AC: nop

    // 0x800B29B0: bc1t        L_800B2A6C
    if (c1cs) {
        // 0x800B29B4: nop
    
            goto L_800B2A6C;
    }
    // 0x800B29B4: nop

    // 0x800B29B8: lh          $t4, 0x6($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X6);
    // 0x800B29BC: nop

    // 0x800B29C0: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x800B29C4: nop

    // 0x800B29C8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B29CC: c.lt.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl < ctx->f12.fl;
    // 0x800B29D0: nop

    // 0x800B29D4: bc1t        L_800B2A6C
    if (c1cs) {
        // 0x800B29D8: nop
    
            goto L_800B2A6C;
    }
    // 0x800B29D8: nop

    // 0x800B29DC: lh          $t5, 0x2($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X2);
    // 0x800B29E0: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800B29E4: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x800B29E8: nop

    // 0x800B29EC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800B29F0: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x800B29F4: nop

    // 0x800B29F8: bc1t        L_800B2A6C
    if (c1cs) {
        // 0x800B29FC: nop
    
            goto L_800B2A6C;
    }
    // 0x800B29FC: nop

    // 0x800B2A00: lh          $t6, 0x8($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X8);
    // 0x800B2A04: nop

    // 0x800B2A08: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800B2A0C: nop

    // 0x800B2A10: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B2A14: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x800B2A18: nop

    // 0x800B2A1C: bc1t        L_800B2A6C
    if (c1cs) {
        // 0x800B2A20: nop
    
            goto L_800B2A6C;
    }
    // 0x800B2A20: nop

    // 0x800B2A24: lh          $t7, 0x4($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X4);
    // 0x800B2A28: lwc1        $f0, 0x14($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800B2A2C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800B2A30: nop

    // 0x800B2A34: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B2A38: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x800B2A3C: nop

    // 0x800B2A40: bc1t        L_800B2A6C
    if (c1cs) {
        // 0x800B2A44: nop
    
            goto L_800B2A6C;
    }
    // 0x800B2A44: nop

    // 0x800B2A48: lh          $t8, 0xA($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XA);
    // 0x800B2A4C: nop

    // 0x800B2A50: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x800B2A54: nop

    // 0x800B2A58: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800B2A5C: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x800B2A60: nop

    // 0x800B2A64: bc1f        L_800B2A9C
    if (!c1cs) {
        // 0x800B2A68: nop
    
            goto L_800B2A9C;
    }
    // 0x800B2A68: nop

L_800B2A6C:
    // 0x800B2A6C: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800B2A70: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x800B2A74: jal         0x80029F58
    // 0x800B2A78: nop

    get_level_segment_index_from_position(rdram, ctx);
        goto after_8;
    // 0x800B2A78: nop

    after_8:
    // 0x800B2A7C: b           L_800B2A9C
    // 0x800B2A80: sh          $v0, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r2;
        goto L_800B2A9C;
    // 0x800B2A80: sh          $v0, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r2;
L_800B2A84:
    // 0x800B2A84: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800B2A88: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800B2A8C: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x800B2A90: jal         0x80029F58
    // 0x800B2A94: nop

    get_level_segment_index_from_position(rdram, ctx);
        goto after_9;
    // 0x800B2A94: nop

    after_9:
    // 0x800B2A98: sh          $v0, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r2;
L_800B2A9C:
    // 0x800B2A9C: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800B2AA0: lw          $t9, -0x7DC0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7DC0);
    // 0x800B2AA4: lh          $t0, 0x3A($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X3A);
    // 0x800B2AA8: nop

    // 0x800B2AAC: subu        $t1, $t0, $t9
    ctx->r9 = SUB32(ctx->r8, ctx->r25);
    // 0x800B2AB0: sh          $t1, 0x3A($s0)
    MEM_H(0X3A, ctx->r16) = ctx->r9;
    // 0x800B2AB4: lh          $t2, 0x3A($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X3A);
    // 0x800B2AB8: nop

    // 0x800B2ABC: bgtz        $t2, L_800B2AD4
    if (SIGNED(ctx->r10) > 0) {
        // 0x800B2AC0: nop
    
            goto L_800B2AD4;
    }
    // 0x800B2AC0: nop

    // 0x800B2AC4: jal         0x8000FFB8
    // 0x800B2AC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    free_object(rdram, ctx);
        goto after_10;
    // 0x800B2AC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x800B2ACC: b           L_800B2B90
    // 0x800B2AD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800B2B90;
    // 0x800B2AD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800B2AD4:
    // 0x800B2AD4: lh          $v0, 0x60($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X60);
    // 0x800B2AD8: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800B2ADC: bne         $v0, $zero, L_800B2B50
    if (ctx->r2 != 0) {
        // 0x800B2AE0: lui         $t6, 0x8013
        ctx->r14 = S32(0X8013 << 16);
            goto L_800B2B50;
    }
    // 0x800B2AE0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800B2AE4: lw          $t3, -0x7DC0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7DC0);
    // 0x800B2AE8: lh          $t4, 0x5E($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X5E);
    // 0x800B2AEC: lh          $t6, 0x5C($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X5C);
    // 0x800B2AF0: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B2AF4: mflo        $t5
    ctx->r13 = lo;
    // 0x800B2AF8: addu        $t7, $t6, $t5
    ctx->r15 = ADD32(ctx->r14, ctx->r13);
    // 0x800B2AFC: sh          $t7, 0x5C($s0)
    MEM_H(0X5C, ctx->r16) = ctx->r15;
    // 0x800B2B00: lh          $t8, 0x5C($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X5C);
    // 0x800B2B04: nop

    // 0x800B2B08: slti        $at, $t8, 0xFF
    ctx->r1 = SIGNED(ctx->r24) < 0XFF ? 1 : 0;
    // 0x800B2B0C: beq         $at, $zero, L_800B2B90
    if (ctx->r1 == 0) {
        // 0x800B2B10: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800B2B90;
    }
    // 0x800B2B10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2B14: lw          $t0, 0x40($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X40);
    // 0x800B2B18: nop

    // 0x800B2B1C: andi        $t9, $t0, 0x1000
    ctx->r25 = ctx->r8 & 0X1000;
    // 0x800B2B20: beq         $t9, $zero, L_800B2B3C
    if (ctx->r25 == 0) {
        // 0x800B2B24: nop
    
            goto L_800B2B3C;
    }
    // 0x800B2B24: nop

    // 0x800B2B28: lh          $t1, 0x6($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X6);
    // 0x800B2B2C: nop

    // 0x800B2B30: ori         $t2, $t1, 0x100
    ctx->r10 = ctx->r9 | 0X100;
    // 0x800B2B34: b           L_800B2B8C
    // 0x800B2B38: sh          $t2, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r10;
        goto L_800B2B8C;
    // 0x800B2B38: sh          $t2, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r10;
L_800B2B3C:
    // 0x800B2B3C: lh          $t3, 0x6($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X6);
    // 0x800B2B40: nop

    // 0x800B2B44: ori         $t4, $t3, 0x80
    ctx->r12 = ctx->r11 | 0X80;
    // 0x800B2B48: b           L_800B2B8C
    // 0x800B2B4C: sh          $t4, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r12;
        goto L_800B2B8C;
    // 0x800B2B4C: sh          $t4, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r12;
L_800B2B50:
    // 0x800B2B50: lw          $t6, -0x7DC0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7DC0);
    // 0x800B2B54: nop

    // 0x800B2B58: subu        $t5, $v0, $t6
    ctx->r13 = SUB32(ctx->r2, ctx->r14);
    // 0x800B2B5C: sh          $t5, 0x60($s0)
    MEM_H(0X60, ctx->r16) = ctx->r13;
    // 0x800B2B60: lh          $v0, 0x60($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X60);
    // 0x800B2B64: nop

    // 0x800B2B68: bgez        $v0, L_800B2B90
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800B2B6C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800B2B90;
    }
    // 0x800B2B6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2B70: lh          $t8, 0x5E($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X5E);
    // 0x800B2B74: lh          $t7, 0x5C($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X5C);
    // 0x800B2B78: multu       $v0, $t8
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B2B7C: sh          $zero, 0x60($s0)
    MEM_H(0X60, ctx->r16) = 0;
    // 0x800B2B80: mflo        $t0
    ctx->r8 = lo;
    // 0x800B2B84: subu        $t9, $t7, $t0
    ctx->r25 = SUB32(ctx->r15, ctx->r8);
    // 0x800B2B88: sh          $t9, 0x5C($s0)
    MEM_H(0X5C, ctx->r16) = ctx->r25;
L_800B2B8C:
    // 0x800B2B8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800B2B90:
    // 0x800B2B90: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B2B94: jr          $ra
    // 0x800B2B98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800B2B98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void delete_point_particle_from_sequence(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2B9C: lw          $v0, 0x70($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X70);
    // 0x800B2BA0: nop

    // 0x800B2BA4: beq         $v0, $zero, L_800B2C38
    if (ctx->r2 == 0) {
        // 0x800B2BA8: nop
    
            goto L_800B2C38;
    }
    // 0x800B2BA8: nop

    // 0x800B2BAC: lbu         $v1, 0x6($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X6);
    // 0x800B2BB0: nop

    // 0x800B2BB4: beq         $v1, $zero, L_800B2C38
    if (ctx->r3 == 0) {
        // 0x800B2BB8: nop
    
            goto L_800B2C38;
    }
    // 0x800B2BB8: nop

    // 0x800B2BBC: lbu         $t7, 0x74($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X74);
    // 0x800B2BC0: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x800B2BC4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800B2BC8: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800B2BCC: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800B2BD0: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
    // 0x800B2BD4: bne         $a0, $t0, L_800B2C38
    if (ctx->r4 != ctx->r8) {
        // 0x800B2BD8: nop
    
            goto L_800B2C38;
    }
    // 0x800B2BD8: nop

    // 0x800B2BDC: sb          $t1, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r9;
    // 0x800B2BE0: lbu         $a1, 0x74($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X74);
    // 0x800B2BE4: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x800B2BE8: slt         $at, $a1, $t2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800B2BEC: beq         $at, $zero, L_800B2C38
    if (ctx->r1 == 0) {
        // 0x800B2BF0: sll         $v1, $a1, 2
        ctx->r3 = S32(ctx->r5 << 2);
            goto L_800B2C38;
    }
    // 0x800B2BF0: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
L_800B2BF4:
    // 0x800B2BF4: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x800B2BF8: nop

    // 0x800B2BFC: addu        $a2, $t3, $v1
    ctx->r6 = ADD32(ctx->r11, ctx->r3);
    // 0x800B2C00: lw          $t4, 0x4($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X4);
    // 0x800B2C04: nop

    // 0x800B2C08: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x800B2C0C: lw          $t5, 0xC($v0)
    ctx->r13 = MEM_W(ctx->r2, 0XC);
    // 0x800B2C10: nop

    // 0x800B2C14: addu        $t7, $t5, $v1
    ctx->r15 = ADD32(ctx->r13, ctx->r3);
    // 0x800B2C18: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x800B2C1C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800B2C20: sb          $a1, 0x74($a0)
    MEM_B(0X74, ctx->r4) = ctx->r5;
    // 0x800B2C24: lbu         $t6, 0x6($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X6);
    // 0x800B2C28: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800B2C2C: slt         $at, $a1, $t6
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800B2C30: bne         $at, $zero, L_800B2BF4
    if (ctx->r1 != 0) {
        // 0x800B2C34: nop
    
            goto L_800B2BF4;
    }
    // 0x800B2C34: nop

L_800B2C38:
    // 0x800B2C38: jr          $ra
    // 0x800B2C3C: nop

    return;
    // 0x800B2C3C: nop

;}
RECOMP_FUNC void update_line_particle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2C40: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800B2C44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B2C48: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x800B2C4C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800B2C50: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800B2C54: beq         $t6, $zero, L_800B2C80
    if (ctx->r14 == 0) {
        // 0x800B2C58: sw          $t6, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r14;
            goto L_800B2C80;
    }
    // 0x800B2C58: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x800B2C5C: lw          $a3, 0x58($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X58);
    // 0x800B2C60: nop

    // 0x800B2C64: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x800B2C68: nop

    // 0x800B2C6C: lw          $t9, 0x9C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X9C);
    // 0x800B2C70: nop

    // 0x800B2C74: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x800B2C78: lw          $v1, 0x44($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X44);
    // 0x800B2C7C: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
L_800B2C80:
    // 0x800B2C80: lbu         $t0, 0x68($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X68);
    // 0x800B2C84: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800B2C88: slti        $at, $t0, 0x2
    ctx->r1 = SIGNED(ctx->r8) < 0X2 ? 1 : 0;
    // 0x800B2C8C: beq         $at, $zero, L_800B33C8
    if (ctx->r1 == 0) {
        // 0x800B2C90: lui         $a1, 0x8013
        ctx->r5 = S32(0X8013 << 16);
            goto L_800B33C8;
    }
    // 0x800B2C90: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B2C94: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800B2C98: nop

    // 0x800B2C9C: beq         $t1, $zero, L_800B33C8
    if (ctx->r9 == 0) {
        // 0x800B2CA0: nop
    
            goto L_800B33C8;
    }
    // 0x800B2CA0: nop

    // 0x800B2CA4: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x800B2CA8: nop

    // 0x800B2CAC: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800B2CB0: nop

    // 0x800B2CB4: andi        $t4, $t3, 0x1000
    ctx->r12 = ctx->r11 & 0X1000;
    // 0x800B2CB8: beq         $t4, $zero, L_800B2D18
    if (ctx->r12 == 0) {
        // 0x800B2CBC: nop
    
            goto L_800B2D18;
    }
    // 0x800B2CBC: nop

    // 0x800B2CC0: lwc1        $f0, 0x1C($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X1C);
    // 0x800B2CC4: lwc1        $f2, 0x20($t1)
    ctx->f2.u32l = MEM_W(ctx->r9, 0X20);
    // 0x800B2CC8: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800B2CCC: lwc1        $f14, 0x24($t1)
    ctx->f14.u32l = MEM_W(ctx->r9, 0X24);
    // 0x800B2CD0: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x800B2CD4: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x800B2CD8: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800B2CDC: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    // 0x800B2CE0: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800B2CE4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B2CE8: jal         0x800CA030
    // 0x800B2CEC: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800B2CEC: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x800B2CF0: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x800B2CF4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B2CF8: lwc1        $f16, 0x8($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800B2CFC: lwc1        $f4, -0x6E90($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6E90);
    // 0x800B2D00: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800B2D04: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x800B2D08: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800B2D0C: mul.s       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800B2D10: b           L_800B2D24
    // 0x800B2D14: lw          $t5, 0x40($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X40);
        goto L_800B2D24;
    // 0x800B2D14: lw          $t5, 0x40($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X40);
L_800B2D18:
    // 0x800B2D18: lwc1        $f2, 0x8($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800B2D1C: nop

    // 0x800B2D20: lw          $t5, 0x40($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X40);
L_800B2D24:
    // 0x800B2D24: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800B2D28: andi        $t6, $t5, 0x4000
    ctx->r14 = ctx->r13 & 0X4000;
    // 0x800B2D2C: bne         $t6, $zero, L_800B2D9C
    if (ctx->r14 != 0) {
        // 0x800B2D30: addiu       $a1, $sp, 0x44
        ctx->r5 = ADD32(ctx->r29, 0X44);
            goto L_800B2D9C;
    }
    // 0x800B2D30: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x800B2D34: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B2D38: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B2D3C: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x800B2D40: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x800B2D44: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x800B2D48: lb          $v0, 0x6A($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X6A);
    // 0x800B2D4C: nop

    // 0x800B2D50: beq         $v0, $at, L_800B2D70
    if (ctx->r2 == ctx->r1) {
        // 0x800B2D54: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800B2D70;
    }
    // 0x800B2D54: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B2D58: beq         $v0, $at, L_800B2D68
    if (ctx->r2 == ctx->r1) {
        // 0x800B2D5C: nop
    
            goto L_800B2D68;
    }
    // 0x800B2D5C: nop

    // 0x800B2D60: b           L_800B2D74
    // 0x800B2D64: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
        goto L_800B2D74;
    // 0x800B2D64: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
L_800B2D68:
    // 0x800B2D68: b           L_800B2D74
    // 0x800B2D6C: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
        goto L_800B2D74;
    // 0x800B2D6C: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
L_800B2D70:
    // 0x800B2D70: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
L_800B2D74:
    // 0x800B2D74: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800B2D78: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    // 0x800B2D7C: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x800B2D80: jal         0x80070560
    // 0x800B2D84: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    vec3f_rotate(rdram, ctx);
        goto after_1;
    // 0x800B2D84: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_1:
    // 0x800B2D88: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x800B2D8C: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x800B2D90: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800B2D94: b           L_800B2E8C
    // 0x800B2D98: nop

        goto L_800B2E8C;
    // 0x800B2D98: nop

L_800B2D9C:
    // 0x800B2D9C: lwc1        $f6, 0x1C($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X1C);
    // 0x800B2DA0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B2DA4: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    // 0x800B2DA8: mul.s       $f16, $f6, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x800B2DAC: lwc1        $f8, 0x20($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X20);
    // 0x800B2DB0: nop

    // 0x800B2DB4: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x800B2DB8: mul.s       $f18, $f8, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x800B2DBC: lwc1        $f10, 0x24($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X24);
    // 0x800B2DC0: lwc1        $f8, -0x6E8C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X6E8C);
    // 0x800B2DC4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B2DC8: mul.s       $f6, $f10, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x800B2DCC: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B2DD0: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    // 0x800B2DD4: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800B2DD8: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x800B2DDC: nop

    // 0x800B2DE0: bc1f        L_800B2DF4
    if (!c1cs) {
        // 0x800B2DE4: nop
    
            goto L_800B2DF4;
    }
    // 0x800B2DE4: nop

    // 0x800B2DE8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800B2DEC: b           L_800B2E20
    // 0x800B2DF0: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
        goto L_800B2E20;
    // 0x800B2DF0: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
L_800B2DF4:
    // 0x800B2DF4: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    // 0x800B2DF8: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x800B2DFC: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x800B2E00: jal         0x800CA030
    // 0x800B2E04: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x800B2E04: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x800B2E08: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800B2E0C: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x800B2E10: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x800B2E14: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800B2E18: div.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800B2E1C: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
L_800B2E20:
    // 0x800B2E20: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800B2E24: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x800B2E28: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800B2E2C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B2E30: mul.s       $f6, $f10, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800B2E34: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    // 0x800B2E38: mul.s       $f8, $f4, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800B2E3C: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    // 0x800B2E40: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800B2E44: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    // 0x800B2E48: lb          $v0, 0x6A($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X6A);
    // 0x800B2E4C: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800B2E50: beq         $v0, $zero, L_800B2E68
    if (ctx->r2 == 0) {
        // 0x800B2E54: nop
    
            goto L_800B2E68;
    }
    // 0x800B2E54: nop

    // 0x800B2E58: beq         $v0, $at, L_800B2E78
    if (ctx->r2 == ctx->r1) {
        // 0x800B2E5C: nop
    
            goto L_800B2E78;
    }
    // 0x800B2E5C: nop

    // 0x800B2E60: b           L_800B2E8C
    // 0x800B2E64: nop

        goto L_800B2E8C;
    // 0x800B2E64: nop

L_800B2E68:
    // 0x800B2E68: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x800B2E6C: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    // 0x800B2E70: b           L_800B2E8C
    // 0x800B2E74: swc1        $f12, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f12.u32l;
        goto L_800B2E8C;
    // 0x800B2E74: swc1        $f12, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f12.u32l;
L_800B2E78:
    // 0x800B2E78: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800B2E7C: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800B2E80: neg.s       $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = -ctx->f10.fl;
    // 0x800B2E84: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    // 0x800B2E88: swc1        $f12, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f12.u32l;
L_800B2E8C:
    // 0x800B2E8C: beq         $v1, $zero, L_800B31C8
    if (ctx->r3 == 0) {
        // 0x800B2E90: lui         $a1, 0x8013
        ctx->r5 = S32(0X8013 << 16);
            goto L_800B31C8;
    }
    // 0x800B2E90: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B2E94: lbu         $t8, 0x68($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X68);
    // 0x800B2E98: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800B2E9C: bne         $t8, $zero, L_800B31C8
    if (ctx->r24 != 0) {
        // 0x800B2EA0: nop
    
            goto L_800B31C8;
    }
    // 0x800B2EA0: nop

    // 0x800B2EA4: lwc1        $f8, 0xC($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800B2EA8: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x800B2EAC: add.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800B2EB0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800B2EB4: nop

    // 0x800B2EB8: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800B2EBC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B2EC0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B2EC4: nop

    // 0x800B2EC8: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B2ECC: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x800B2ED0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800B2ED4: sh          $t0, 0xA($t2)
    MEM_H(0XA, ctx->r10) = ctx->r8;
    // 0x800B2ED8: lwc1        $f6, 0x10($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X10);
    // 0x800B2EDC: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800B2EE0: lw          $t1, 0x8($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X8);
    // 0x800B2EE4: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800B2EE8: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800B2EEC: nop

    // 0x800B2EF0: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800B2EF4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B2EF8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B2EFC: nop

    // 0x800B2F00: cvt.w.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800B2F04: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x800B2F08: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800B2F0C: sh          $t4, 0xC($t1)
    MEM_H(0XC, ctx->r9) = ctx->r12;
    // 0x800B2F10: lwc1        $f18, 0x14($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X14);
    // 0x800B2F14: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800B2F18: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x800B2F1C: add.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B2F20: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800B2F24: nop

    // 0x800B2F28: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800B2F2C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B2F30: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B2F34: nop

    // 0x800B2F38: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800B2F3C: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x800B2F40: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800B2F44: sh          $t6, 0xE($t7)
    MEM_H(0XE, ctx->r15) = ctx->r14;
    // 0x800B2F48: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800B2F4C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800B2F50: lbu         $t8, 0x6($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X6);
    // 0x800B2F54: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800B2F58: sb          $t8, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r24;
    // 0x800B2F5C: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800B2F60: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B2F64: lbu         $t9, 0x7($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X7);
    // 0x800B2F68: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B2F6C: sb          $t9, 0x11($v0)
    MEM_B(0X11, ctx->r2) = ctx->r25;
    // 0x800B2F70: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800B2F74: nop

    // 0x800B2F78: lbu         $t0, 0x8($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X8);
    // 0x800B2F7C: nop

    // 0x800B2F80: sb          $t0, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r8;
    // 0x800B2F84: lw          $t3, 0x8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X8);
    // 0x800B2F88: lbu         $t2, 0x6($a3)
    ctx->r10 = MEM_BU(ctx->r7, 0X6);
    // 0x800B2F8C: nop

    // 0x800B2F90: sb          $t2, 0x13($t3)
    MEM_B(0X13, ctx->r11) = ctx->r10;
    // 0x800B2F94: lwc1        $f4, 0xC($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800B2F98: lw          $t5, 0x8($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X8);
    // 0x800B2F9C: cvt.w.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800B2FA0: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800B2FA4: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x800B2FA8: nop

    // 0x800B2FAC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800B2FB0: sh          $t1, 0x14($t5)
    MEM_H(0X14, ctx->r13) = ctx->r9;
    // 0x800B2FB4: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800B2FB8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B2FBC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B2FC0: lwc1        $f16, 0x10($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X10);
    // 0x800B2FC4: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x800B2FC8: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B2FCC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800B2FD0: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x800B2FD4: nop

    // 0x800B2FD8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800B2FDC: sh          $t7, 0x16($t8)
    MEM_H(0X16, ctx->r24) = ctx->r15;
    // 0x800B2FE0: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800B2FE4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B2FE8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B2FEC: lwc1        $f10, 0x14($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X14);
    // 0x800B2FF0: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x800B2FF4: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800B2FF8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B2FFC: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x800B3000: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800B3004: sh          $t0, 0x18($t2)
    MEM_H(0X18, ctx->r10) = ctx->r8;
    // 0x800B3008: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800B300C: nop

    // 0x800B3010: beq         $t3, $at, L_800B3084
    if (ctx->r11 == ctx->r1) {
        // 0x800B3014: nop
    
            goto L_800B3084;
    }
    // 0x800B3014: nop

    // 0x800B3018: lh          $t4, 0x1E($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X1E);
    // 0x800B301C: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x800B3020: sll         $t1, $t4, 3
    ctx->r9 = S32(ctx->r12 << 3);
    // 0x800B3024: addu        $t5, $t3, $t1
    ctx->r13 = ADD32(ctx->r11, ctx->r9);
    // 0x800B3028: lbu         $t6, 0x14($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X14);
    // 0x800B302C: nop

    // 0x800B3030: sb          $t6, 0x1A($t7)
    MEM_B(0X1A, ctx->r15) = ctx->r14;
    // 0x800B3034: lh          $t9, 0x1E($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X1E);
    // 0x800B3038: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800B303C: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x800B3040: addu        $t2, $t8, $t0
    ctx->r10 = ADD32(ctx->r24, ctx->r8);
    // 0x800B3044: lbu         $t4, 0x15($t2)
    ctx->r12 = MEM_BU(ctx->r10, 0X15);
    // 0x800B3048: lw          $t3, 0x8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X8);
    // 0x800B304C: nop

    // 0x800B3050: sb          $t4, 0x1B($t3)
    MEM_B(0X1B, ctx->r11) = ctx->r12;
    // 0x800B3054: lh          $t5, 0x1E($a3)
    ctx->r13 = MEM_H(ctx->r7, 0X1E);
    // 0x800B3058: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800B305C: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x800B3060: addu        $t7, $t1, $t6
    ctx->r15 = ADD32(ctx->r9, ctx->r14);
    // 0x800B3064: lbu         $t9, 0x16($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X16);
    // 0x800B3068: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x800B306C: nop

    // 0x800B3070: sb          $t9, 0x1C($t8)
    MEM_B(0X1C, ctx->r24) = ctx->r25;
    // 0x800B3074: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x800B3078: lbu         $t0, 0x6($a3)
    ctx->r8 = MEM_BU(ctx->r7, 0X6);
    // 0x800B307C: b           L_800B30C4
    // 0x800B3080: sb          $t0, 0x1D($t2)
    MEM_B(0X1D, ctx->r10) = ctx->r8;
        goto L_800B30C4;
    // 0x800B3080: sb          $t0, 0x1D($t2)
    MEM_B(0X1D, ctx->r10) = ctx->r8;
L_800B3084:
    // 0x800B3084: lbu         $t4, 0x6C($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X6C);
    // 0x800B3088: lw          $t3, 0x8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X8);
    // 0x800B308C: nop

    // 0x800B3090: sb          $t4, 0x1A($t3)
    MEM_B(0X1A, ctx->r11) = ctx->r12;
    // 0x800B3094: lw          $t1, 0x8($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X8);
    // 0x800B3098: lbu         $t5, 0x6D($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X6D);
    // 0x800B309C: nop

    // 0x800B30A0: sb          $t5, 0x1B($t1)
    MEM_B(0X1B, ctx->r9) = ctx->r13;
    // 0x800B30A4: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x800B30A8: lbu         $t6, 0x6E($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X6E);
    // 0x800B30AC: nop

    // 0x800B30B0: sb          $t6, 0x1C($t7)
    MEM_B(0X1C, ctx->r15) = ctx->r14;
    // 0x800B30B4: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x800B30B8: lbu         $t9, 0x6($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X6);
    // 0x800B30BC: nop

    // 0x800B30C0: sb          $t9, 0x1D($t8)
    MEM_B(0X1D, ctx->r24) = ctx->r25;
L_800B30C4:
    // 0x800B30C4: lwc1        $f4, 0xC($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800B30C8: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800B30CC: lw          $t4, 0x8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X8);
    // 0x800B30D0: sub.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800B30D4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B30D8: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800B30DC: addiu       $a1, $a1, -0x7DC0
    ctx->r5 = ADD32(ctx->r5, -0X7DC0);
    // 0x800B30E0: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x800B30E4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B30E8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B30EC: nop

    // 0x800B30F0: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B30F4: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x800B30F8: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800B30FC: sh          $t2, 0x1E($t4)
    MEM_H(0X1E, ctx->r12) = ctx->r10;
    // 0x800B3100: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800B3104: lwc1        $f10, 0x10($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X10);
    // 0x800B3108: lw          $t1, 0x8($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X8);
    // 0x800B310C: sub.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800B3110: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800B3114: nop

    // 0x800B3118: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800B311C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B3120: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B3124: nop

    // 0x800B3128: cvt.w.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800B312C: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x800B3130: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800B3134: sh          $t5, 0x20($t1)
    MEM_H(0X20, ctx->r9) = ctx->r13;
    // 0x800B3138: lwc1        $f18, 0x4C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800B313C: lwc1        $f16, 0x14($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X14);
    // 0x800B3140: lw          $t9, 0x8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X8);
    // 0x800B3144: sub.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800B3148: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800B314C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800B3150: nop

    // 0x800B3154: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800B3158: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B315C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B3160: nop

    // 0x800B3164: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800B3168: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800B316C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800B3170: sh          $t7, 0x22($t9)
    MEM_H(0X22, ctx->r25) = ctx->r15;
    // 0x800B3174: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800B3178: nop

    // 0x800B317C: lbu         $t8, 0x6($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X6);
    // 0x800B3180: nop

    // 0x800B3184: sb          $t8, 0x24($v0)
    MEM_B(0X24, ctx->r2) = ctx->r24;
    // 0x800B3188: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800B318C: nop

    // 0x800B3190: lbu         $t0, 0x7($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X7);
    // 0x800B3194: nop

    // 0x800B3198: sb          $t0, 0x25($v0)
    MEM_B(0X25, ctx->r2) = ctx->r8;
    // 0x800B319C: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800B31A0: nop

    // 0x800B31A4: lbu         $t2, 0x8($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X8);
    // 0x800B31A8: nop

    // 0x800B31AC: sb          $t2, 0x26($v0)
    MEM_B(0X26, ctx->r2) = ctx->r10;
    // 0x800B31B0: lw          $t3, 0x8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X8);
    // 0x800B31B4: lbu         $t4, 0x6($a3)
    ctx->r12 = MEM_BU(ctx->r7, 0X6);
    // 0x800B31B8: nop

    // 0x800B31BC: sb          $t4, 0x27($t3)
    MEM_B(0X27, ctx->r11) = ctx->r12;
    // 0x800B31C0: b           L_800B34C8
    // 0x800B31C4: sb          $t5, 0x68($a2)
    MEM_B(0X68, ctx->r6) = ctx->r13;
        goto L_800B34C8;
    // 0x800B31C4: sb          $t5, 0x68($a2)
    MEM_B(0X68, ctx->r6) = ctx->r13;
L_800B31C8:
    // 0x800B31C8: beq         $v1, $zero, L_800B33C0
    if (ctx->r3 == 0) {
        // 0x800B31CC: nop
    
            goto L_800B33C0;
    }
    // 0x800B31CC: nop

    // 0x800B31D0: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800B31D4: lwc1        $f8, 0xC($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800B31D8: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x800B31DC: add.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800B31E0: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800B31E4: nop

    // 0x800B31E8: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800B31EC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B31F0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B31F4: nop

    // 0x800B31F8: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B31FC: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x800B3200: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800B3204: sh          $t6, 0x28($t7)
    MEM_H(0X28, ctx->r15) = ctx->r14;
    // 0x800B3208: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800B320C: lwc1        $f6, 0x10($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X10);
    // 0x800B3210: lw          $t0, 0x8($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X8);
    // 0x800B3214: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800B3218: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800B321C: nop

    // 0x800B3220: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800B3224: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B3228: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B322C: nop

    // 0x800B3230: cvt.w.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800B3234: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x800B3238: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800B323C: sh          $t8, 0x2A($t0)
    MEM_H(0X2A, ctx->r8) = ctx->r24;
    // 0x800B3240: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800B3244: lwc1        $f18, 0x14($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X14);
    // 0x800B3248: lw          $t3, 0x8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X8);
    // 0x800B324C: add.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B3250: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800B3254: nop

    // 0x800B3258: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800B325C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B3260: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B3264: nop

    // 0x800B3268: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800B326C: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x800B3270: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800B3274: sh          $t4, 0x2C($t3)
    MEM_H(0X2C, ctx->r11) = ctx->r12;
    // 0x800B3278: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800B327C: nop

    // 0x800B3280: lbu         $t5, 0x1A($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X1A);
    // 0x800B3284: nop

    // 0x800B3288: sb          $t5, 0x2E($v0)
    MEM_B(0X2E, ctx->r2) = ctx->r13;
    // 0x800B328C: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800B3290: nop

    // 0x800B3294: lbu         $t1, 0x1B($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X1B);
    // 0x800B3298: nop

    // 0x800B329C: sb          $t1, 0x2F($v0)
    MEM_B(0X2F, ctx->r2) = ctx->r9;
    // 0x800B32A0: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800B32A4: nop

    // 0x800B32A8: lbu         $t6, 0x1C($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1C);
    // 0x800B32AC: nop

    // 0x800B32B0: sb          $t6, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r14;
    // 0x800B32B4: lw          $t9, 0x8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X8);
    // 0x800B32B8: lbu         $t7, 0x6($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X6);
    // 0x800B32BC: nop

    // 0x800B32C0: sb          $t7, 0x31($t9)
    MEM_B(0X31, ctx->r25) = ctx->r15;
    // 0x800B32C4: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800B32C8: lwc1        $f4, 0xC($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800B32CC: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x800B32D0: sub.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800B32D4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800B32D8: nop

    // 0x800B32DC: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800B32E0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B32E4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B32E8: nop

    // 0x800B32EC: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B32F0: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x800B32F4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800B32F8: sh          $t0, 0x32($t2)
    MEM_H(0X32, ctx->r10) = ctx->r8;
    // 0x800B32FC: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800B3300: lwc1        $f10, 0x10($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X10);
    // 0x800B3304: lw          $t5, 0x8($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X8);
    // 0x800B3308: sub.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800B330C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800B3310: nop

    // 0x800B3314: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800B3318: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B331C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B3320: nop

    // 0x800B3324: cvt.w.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800B3328: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x800B332C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800B3330: sh          $t3, 0x34($t5)
    MEM_H(0X34, ctx->r13) = ctx->r11;
    // 0x800B3334: lwc1        $f18, 0x4C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800B3338: lwc1        $f16, 0x14($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X14);
    // 0x800B333C: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x800B3340: sub.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800B3344: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800B3348: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800B334C: nop

    // 0x800B3350: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800B3354: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B3358: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B335C: nop

    // 0x800B3360: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800B3364: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x800B3368: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800B336C: sh          $t6, 0x36($t7)
    MEM_H(0X36, ctx->r15) = ctx->r14;
    // 0x800B3370: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800B3374: nop

    // 0x800B3378: lbu         $t9, 0x1A($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X1A);
    // 0x800B337C: nop

    // 0x800B3380: sb          $t9, 0x38($v0)
    MEM_B(0X38, ctx->r2) = ctx->r25;
    // 0x800B3384: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800B3388: nop

    // 0x800B338C: lbu         $t8, 0x1B($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1B);
    // 0x800B3390: nop

    // 0x800B3394: sb          $t8, 0x39($v0)
    MEM_B(0X39, ctx->r2) = ctx->r24;
    // 0x800B3398: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800B339C: nop

    // 0x800B33A0: lbu         $t0, 0x1C($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X1C);
    // 0x800B33A4: nop

    // 0x800B33A8: sb          $t0, 0x3A($v0)
    MEM_B(0X3A, ctx->r2) = ctx->r8;
    // 0x800B33AC: lw          $t4, 0x8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X8);
    // 0x800B33B0: lbu         $t2, 0x6($a3)
    ctx->r10 = MEM_BU(ctx->r7, 0X6);
    // 0x800B33B4: nop

    // 0x800B33B8: sb          $t2, 0x3B($t4)
    MEM_B(0X3B, ctx->r12) = ctx->r10;
    // 0x800B33BC: sb          $t3, 0x68($a2)
    MEM_B(0X68, ctx->r6) = ctx->r11;
L_800B33C0:
    // 0x800B33C0: b           L_800B34C8
    // 0x800B33C4: addiu       $a1, $a1, -0x7DC0
    ctx->r5 = ADD32(ctx->r5, -0X7DC0);
        goto L_800B34C8;
    // 0x800B33C4: addiu       $a1, $a1, -0x7DC0
    ctx->r5 = ADD32(ctx->r5, -0X7DC0);
L_800B33C8:
    // 0x800B33C8: addiu       $a1, $a1, -0x7DC0
    ctx->r5 = ADD32(ctx->r5, -0X7DC0);
    // 0x800B33CC: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x800B33D0: lh          $t5, 0x3A($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X3A);
    // 0x800B33D4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800B33D8: subu        $t6, $t5, $t1
    ctx->r14 = SUB32(ctx->r13, ctx->r9);
    // 0x800B33DC: sh          $t6, 0x3A($a2)
    MEM_H(0X3A, ctx->r6) = ctx->r14;
    // 0x800B33E0: lh          $t7, 0x3A($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X3A);
    // 0x800B33E4: nop

    // 0x800B33E8: bgtz        $t7, L_800B3410
    if (SIGNED(ctx->r15) > 0) {
        // 0x800B33EC: nop
    
            goto L_800B3410;
    }
    // 0x800B33EC: nop

    // 0x800B33F0: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    // 0x800B33F4: jal         0x8000FFB8
    // 0x800B33F8: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    free_object(rdram, ctx);
        goto after_3;
    // 0x800B33F8: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    after_3:
    // 0x800B33FC: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x800B3400: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B3404: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x800B3408: b           L_800B34C8
    // 0x800B340C: addiu       $a1, $a1, -0x7DC0
    ctx->r5 = ADD32(ctx->r5, -0X7DC0);
        goto L_800B34C8;
    // 0x800B340C: addiu       $a1, $a1, -0x7DC0
    ctx->r5 = ADD32(ctx->r5, -0X7DC0);
L_800B3410:
    // 0x800B3410: lh          $v0, 0x60($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X60);
    // 0x800B3414: nop

    // 0x800B3418: bne         $v0, $zero, L_800B348C
    if (ctx->r2 != 0) {
        // 0x800B341C: nop
    
            goto L_800B348C;
    }
    // 0x800B341C: nop

    // 0x800B3420: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x800B3424: lh          $t8, 0x5E($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X5E);
    // 0x800B3428: lh          $t2, 0x5C($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X5C);
    // 0x800B342C: multu       $t9, $t8
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B3430: mflo        $t0
    ctx->r8 = lo;
    // 0x800B3434: addu        $t4, $t2, $t0
    ctx->r12 = ADD32(ctx->r10, ctx->r8);
    // 0x800B3438: sh          $t4, 0x5C($a2)
    MEM_H(0X5C, ctx->r6) = ctx->r12;
    // 0x800B343C: lh          $t3, 0x5C($a2)
    ctx->r11 = MEM_H(ctx->r6, 0X5C);
    // 0x800B3440: nop

    // 0x800B3444: slti        $at, $t3, 0xFF
    ctx->r1 = SIGNED(ctx->r11) < 0XFF ? 1 : 0;
    // 0x800B3448: beq         $at, $zero, L_800B34C8
    if (ctx->r1 == 0) {
        // 0x800B344C: nop
    
            goto L_800B34C8;
    }
    // 0x800B344C: nop

    // 0x800B3450: lw          $t5, 0x40($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X40);
    // 0x800B3454: nop

    // 0x800B3458: andi        $t1, $t5, 0x1000
    ctx->r9 = ctx->r13 & 0X1000;
    // 0x800B345C: beq         $t1, $zero, L_800B3478
    if (ctx->r9 == 0) {
        // 0x800B3460: nop
    
            goto L_800B3478;
    }
    // 0x800B3460: nop

    // 0x800B3464: lh          $t6, 0x6($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X6);
    // 0x800B3468: nop

    // 0x800B346C: ori         $t7, $t6, 0x100
    ctx->r15 = ctx->r14 | 0X100;
    // 0x800B3470: b           L_800B34C8
    // 0x800B3474: sh          $t7, 0x6($a2)
    MEM_H(0X6, ctx->r6) = ctx->r15;
        goto L_800B34C8;
    // 0x800B3474: sh          $t7, 0x6($a2)
    MEM_H(0X6, ctx->r6) = ctx->r15;
L_800B3478:
    // 0x800B3478: lh          $t9, 0x6($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X6);
    // 0x800B347C: nop

    // 0x800B3480: ori         $t8, $t9, 0x80
    ctx->r24 = ctx->r25 | 0X80;
    // 0x800B3484: b           L_800B34C8
    // 0x800B3488: sh          $t8, 0x6($a2)
    MEM_H(0X6, ctx->r6) = ctx->r24;
        goto L_800B34C8;
    // 0x800B3488: sh          $t8, 0x6($a2)
    MEM_H(0X6, ctx->r6) = ctx->r24;
L_800B348C:
    // 0x800B348C: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x800B3490: nop

    // 0x800B3494: subu        $t0, $v0, $t2
    ctx->r8 = SUB32(ctx->r2, ctx->r10);
    // 0x800B3498: sh          $t0, 0x60($a2)
    MEM_H(0X60, ctx->r6) = ctx->r8;
    // 0x800B349C: lh          $v0, 0x60($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X60);
    // 0x800B34A0: nop

    // 0x800B34A4: bgez        $v0, L_800B34C8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800B34A8: nop
    
            goto L_800B34C8;
    }
    // 0x800B34A8: nop

    // 0x800B34AC: lh          $t3, 0x5E($a2)
    ctx->r11 = MEM_H(ctx->r6, 0X5E);
    // 0x800B34B0: lh          $t4, 0x5C($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X5C);
    // 0x800B34B4: multu       $v0, $t3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B34B8: sh          $zero, 0x60($a2)
    MEM_H(0X60, ctx->r6) = 0;
    // 0x800B34BC: mflo        $t5
    ctx->r13 = lo;
    // 0x800B34C0: subu        $t1, $t4, $t5
    ctx->r9 = SUB32(ctx->r12, ctx->r13);
    // 0x800B34C4: sh          $t1, 0x5C($a2)
    MEM_H(0X5C, ctx->r6) = ctx->r9;
L_800B34C8:
    // 0x800B34C8: beq         $v1, $zero, L_800B3510
    if (ctx->r3 == 0) {
        // 0x800B34CC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B3510;
    }
    // 0x800B34CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B34D0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800B34D4: nop

    // 0x800B34D8: beq         $t6, $zero, L_800B3510
    if (ctx->r14 == 0) {
        // 0x800B34DC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B3510;
    }
    // 0x800B34DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B34E0: lw          $t7, 0x40($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X40);
    // 0x800B34E4: nop

    // 0x800B34E8: andi        $t9, $t7, 0x3
    ctx->r25 = ctx->r15 & 0X3;
    // 0x800B34EC: beq         $t9, $zero, L_800B3510
    if (ctx->r25 == 0) {
        // 0x800B34F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B3510;
    }
    // 0x800B34F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B34F4: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x800B34F8: nop

    // 0x800B34FC: blez        $t8, L_800B3510
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800B3500: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B3510;
    }
    // 0x800B3500: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B3504: jal         0x800B351C
    // 0x800B3508: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    update_particle_texture_frame(rdram, ctx);
        goto after_4;
    // 0x800B3508: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_4:
    // 0x800B350C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800B3510:
    // 0x800B3510: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800B3514: jr          $ra
    // 0x800B3518: nop

    return;
    // 0x800B3518: nop

;}
RECOMP_FUNC void update_particle_texture_frame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B351C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800B3520: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x800B3524: lh          $t6, 0x2C($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2C);
    // 0x800B3528: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x800B352C: bne         $t6, $at, L_800B3550
    if (ctx->r14 != ctx->r1) {
        // 0x800B3530: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_800B3550;
    }
    // 0x800B3530: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800B3534: lw          $t7, 0x44($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X44);
    // 0x800B3538: nop

    // 0x800B353C: lh          $a1, 0x0($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X0);
    // 0x800B3540: nop

    // 0x800B3544: sll         $t8, $a1, 8
    ctx->r24 = S32(ctx->r5 << 8);
    // 0x800B3548: b           L_800B3568
    // 0x800B354C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
        goto L_800B3568;
    // 0x800B354C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
L_800B3550:
    // 0x800B3550: lw          $t9, 0x44($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X44);
    // 0x800B3554: nop

    // 0x800B3558: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x800B355C: nop

    // 0x800B3560: lhu         $a1, 0x12($t6)
    ctx->r5 = MEM_HU(ctx->r14, 0X12);
    // 0x800B3564: nop

L_800B3568:
    // 0x800B3568: lw          $a3, 0x40($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X40);
    // 0x800B356C: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800B3570: addiu       $t4, $t4, -0x7DC0
    ctx->r12 = ADD32(ctx->r12, -0X7DC0);
    // 0x800B3574: lw          $t3, 0x0($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X0);
    // 0x800B3578: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800B357C: slt         $t7, $zero, $t3
    ctx->r15 = SIGNED(0) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800B3580: andi        $a2, $a3, 0x1
    ctx->r6 = ctx->r7 & 0X1;
    // 0x800B3584: andi        $t0, $a3, 0x2
    ctx->r8 = ctx->r7 & 0X2;
    // 0x800B3588: andi        $t1, $a3, 0x4
    ctx->r9 = ctx->r7 & 0X4;
    // 0x800B358C: beq         $t7, $zero, L_800B3694
    if (ctx->r15 == 0) {
        // 0x800B3590: andi        $t2, $a3, 0x8
        ctx->r10 = ctx->r7 & 0X8;
            goto L_800B3694;
    }
    // 0x800B3590: andi        $t2, $a3, 0x8
    ctx->r10 = ctx->r7 & 0X8;
    // 0x800B3594: addiu       $s0, $zero, -0x9
    ctx->r16 = ADD32(0, -0X9);
    // 0x800B3598: addiu       $t5, $zero, -0x4
    ctx->r13 = ADD32(0, -0X4);
L_800B359C:
    // 0x800B359C: lh          $a3, 0x18($a0)
    ctx->r7 = MEM_H(ctx->r4, 0X18);
    // 0x800B35A0: lh          $t3, 0x1A($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X1A);
    // 0x800B35A4: bne         $t2, $zero, L_800B361C
    if (ctx->r10 != 0) {
        // 0x800B35A8: subu        $t6, $a3, $t3
        ctx->r14 = SUB32(ctx->r7, ctx->r11);
            goto L_800B361C;
    }
    // 0x800B35A8: subu        $t6, $a3, $t3
    ctx->r14 = SUB32(ctx->r7, ctx->r11);
    // 0x800B35AC: addu        $t8, $a3, $t3
    ctx->r24 = ADD32(ctx->r7, ctx->r11);
    // 0x800B35B0: sh          $t8, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r24;
    // 0x800B35B4: lh          $a3, 0x18($a0)
    ctx->r7 = MEM_H(ctx->r4, 0X18);
    // 0x800B35B8: nop

    // 0x800B35BC: slt         $at, $a3, $a1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800B35C0: bne         $at, $zero, L_800B3678
    if (ctx->r1 != 0) {
        // 0x800B35C4: nop
    
            goto L_800B3678;
    }
    // 0x800B35C4: nop

    // 0x800B35C8: beq         $t0, $zero, L_800B35F0
    if (ctx->r8 == 0) {
        // 0x800B35CC: sll         $t9, $a1, 1
        ctx->r25 = S32(ctx->r5 << 1);
            goto L_800B35F0;
    }
    // 0x800B35CC: sll         $t9, $a1, 1
    ctx->r25 = S32(ctx->r5 << 1);
    // 0x800B35D0: lw          $t8, 0x40($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X40);
    // 0x800B35D4: subu        $t6, $t9, $a3
    ctx->r14 = SUB32(ctx->r25, ctx->r7);
    // 0x800B35D8: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800B35DC: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x800B35E0: sh          $t7, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r15;
    // 0x800B35E4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800B35E8: b           L_800B3678
    // 0x800B35EC: sw          $t9, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r25;
        goto L_800B3678;
    // 0x800B35EC: sw          $t9, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r25;
L_800B35F0:
    // 0x800B35F0: beq         $t1, $zero, L_800B3604
    if (ctx->r9 == 0) {
        // 0x800B35F4: addiu       $t7, $a1, -0x1
        ctx->r15 = ADD32(ctx->r5, -0X1);
            goto L_800B3604;
    }
    // 0x800B35F4: addiu       $t7, $a1, -0x1
    ctx->r15 = ADD32(ctx->r5, -0X1);
    // 0x800B35F8: subu        $t6, $a3, $a1
    ctx->r14 = SUB32(ctx->r7, ctx->r5);
    // 0x800B35FC: b           L_800B3678
    // 0x800B3600: sh          $t6, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r14;
        goto L_800B3678;
    // 0x800B3600: sh          $t6, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r14;
L_800B3604:
    // 0x800B3604: lw          $t8, 0x40($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X40);
    // 0x800B3608: sh          $t7, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r15;
    // 0x800B360C: and         $t9, $t8, $t5
    ctx->r25 = ctx->r24 & ctx->r13;
    // 0x800B3610: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B3614: b           L_800B3678
    // 0x800B3618: sw          $t9, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r25;
        goto L_800B3678;
    // 0x800B3618: sw          $t9, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r25;
L_800B361C:
    // 0x800B361C: sh          $t6, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r14;
    // 0x800B3620: lh          $a3, 0x18($a0)
    ctx->r7 = MEM_H(ctx->r4, 0X18);
    // 0x800B3624: nop

    // 0x800B3628: bgez        $a3, L_800B3678
    if (SIGNED(ctx->r7) >= 0) {
        // 0x800B362C: nop
    
            goto L_800B3678;
    }
    // 0x800B362C: nop

    // 0x800B3630: beq         $t1, $zero, L_800B3664
    if (ctx->r9 == 0) {
        // 0x800B3634: nop
    
            goto L_800B3664;
    }
    // 0x800B3634: nop

    // 0x800B3638: beq         $a2, $zero, L_800B365C
    if (ctx->r6 == 0) {
        // 0x800B363C: addu        $t6, $a3, $a1
        ctx->r14 = ADD32(ctx->r7, ctx->r5);
            goto L_800B365C;
    }
    // 0x800B363C: addu        $t6, $a3, $a1
    ctx->r14 = ADD32(ctx->r7, ctx->r5);
    // 0x800B3640: lw          $t8, 0x40($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X40);
    // 0x800B3644: negu        $t7, $a3
    ctx->r15 = SUB32(0, ctx->r7);
    // 0x800B3648: and         $t9, $t8, $s0
    ctx->r25 = ctx->r24 & ctx->r16;
    // 0x800B364C: sh          $t7, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r15;
    // 0x800B3650: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800B3654: b           L_800B3678
    // 0x800B3658: sw          $t9, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r25;
        goto L_800B3678;
    // 0x800B3658: sw          $t9, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r25;
L_800B365C:
    // 0x800B365C: b           L_800B3678
    // 0x800B3660: sh          $t6, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r14;
        goto L_800B3678;
    // 0x800B3660: sh          $t6, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r14;
L_800B3664:
    // 0x800B3664: lw          $t7, 0x40($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X40);
    // 0x800B3668: sh          $zero, 0x18($a0)
    MEM_H(0X18, ctx->r4) = 0;
    // 0x800B366C: and         $t8, $t7, $t5
    ctx->r24 = ctx->r15 & ctx->r13;
    // 0x800B3670: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B3674: sw          $t8, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r24;
L_800B3678:
    // 0x800B3678: lw          $t9, 0x0($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X0);
    // 0x800B367C: nop

    // 0x800B3680: slt         $t3, $v1, $t9
    ctx->r11 = SIGNED(ctx->r3) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800B3684: beq         $t3, $zero, L_800B3694
    if (ctx->r11 == 0) {
        // 0x800B3688: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800B3694;
    }
    // 0x800B3688: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800B368C: bne         $v0, $zero, L_800B359C
    if (ctx->r2 != 0) {
        // 0x800B3690: nop
    
            goto L_800B359C;
    }
    // 0x800B3690: nop

L_800B3694:
    // 0x800B3694: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x800B3698: jr          $ra
    // 0x800B369C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800B369C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void move_particle_basic_parent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B36A0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B36A4: lw          $v0, -0x7DC0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DC0);
    // 0x800B36A8: nop

    // 0x800B36AC: slt         $v1, $zero, $v0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B36B0: beq         $v1, $zero, L_800B3740
    if (ctx->r3 == 0) {
        // 0x800B36B4: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_800B3740;
    }
    // 0x800B36B4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_800B36B8:
    // 0x800B36B8: lwc1        $f4, 0x4C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4C);
    // 0x800B36BC: lwc1        $f6, 0x1C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800B36C0: lwc1        $f0, 0x20($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800B36C4: lwc1        $f10, 0x50($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X50);
    // 0x800B36C8: lwc1        $f18, 0x68($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X68);
    // 0x800B36CC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B36D0: lwc1        $f6, 0x54($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X54);
    // 0x800B36D4: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x800B36D8: swc1        $f8, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->f8.u32l;
    // 0x800B36DC: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x800B36E0: swc1        $f16, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f16.u32l;
    // 0x800B36E4: lwc1        $f8, 0x24($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800B36E8: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x800B36EC: lh          $t7, 0x62($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X62);
    // 0x800B36F0: lh          $t9, 0x2($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X2);
    // 0x800B36F4: lh          $t0, 0x64($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X64);
    // 0x800B36F8: lh          $t2, 0x4($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X4);
    // 0x800B36FC: lh          $t3, 0x66($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X66);
    // 0x800B3700: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800B3704: lwc1        $f18, 0x28($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X28);
    // 0x800B3708: swc1        $f4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f4.u32l;
    // 0x800B370C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800B3710: slt         $v1, $zero, $v0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B3714: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B3718: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800B371C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800B3720: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800B3724: swc1        $f10, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f10.u32l;
    // 0x800B3728: sh          $t8, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r24;
    // 0x800B372C: sh          $t1, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r9;
    // 0x800B3730: sh          $t4, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r12;
    // 0x800B3734: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
    // 0x800B3738: bne         $v1, $zero, L_800B36B8
    if (ctx->r3 != 0) {
        // 0x800B373C: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_800B36B8;
    }
    // 0x800B373C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_800B3740:
    // 0x800B3740: lwc1        $f6, 0x4C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4C);
    // 0x800B3744: lwc1        $f8, 0x50($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X50);
    // 0x800B3748: lwc1        $f10, 0x54($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X54);
    // 0x800B374C: lw          $v0, 0x3C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X3C);
    // 0x800B3750: swc1        $f6, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f6.u32l;
    // 0x800B3754: swc1        $f8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f8.u32l;
    // 0x800B3758: beq         $v0, $zero, L_800B3798
    if (ctx->r2 == 0) {
        // 0x800B375C: swc1        $f10, 0x14($a0)
        MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
            goto L_800B3798;
    }
    // 0x800B375C: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
    // 0x800B3760: lwc1        $f16, 0xC($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800B3764: lwc1        $f18, 0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800B3768: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800B376C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B3770: lwc1        $f16, 0x14($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800B3774: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
    // 0x800B3778: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800B377C: nop

    // 0x800B3780: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800B3784: swc1        $f10, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f10.u32l;
    // 0x800B3788: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800B378C: nop

    // 0x800B3790: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B3794: swc1        $f4, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f4.u32l;
L_800B3798:
    // 0x800B3798: jr          $ra
    // 0x800B379C: nop

    return;
    // 0x800B379C: nop

;}
RECOMP_FUNC void move_particle_attached_to_parent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B37A0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B37A4: lw          $v0, -0x7DC0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DC0);
    // 0x800B37A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B37AC: slt         $v1, $zero, $v0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B37B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B37B4: beq         $v1, $zero, L_800B380C
    if (ctx->r3 == 0) {
        // 0x800B37B8: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_800B380C;
    }
    // 0x800B37B8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800B37BC: lh          $a1, 0x62($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X62);
    // 0x800B37C0: lh          $a2, 0x64($a0)
    ctx->r6 = MEM_H(ctx->r4, 0X64);
    // 0x800B37C4: lh          $a3, 0x66($a0)
    ctx->r7 = MEM_H(ctx->r4, 0X66);
    // 0x800B37C8: lwc1        $f0, 0x28($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X28);
    // 0x800B37CC: nop

L_800B37D0:
    // 0x800B37D0: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x800B37D4: lh          $t8, 0x2($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X2);
    // 0x800B37D8: lh          $t0, 0x4($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X4);
    // 0x800B37DC: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800B37E0: slt         $v1, $zero, $v0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B37E4: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800B37E8: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x800B37EC: addu        $t9, $t8, $a2
    ctx->r25 = ADD32(ctx->r24, ctx->r6);
    // 0x800B37F0: addu        $t1, $t0, $a3
    ctx->r9 = ADD32(ctx->r8, ctx->r7);
    // 0x800B37F4: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
    // 0x800B37F8: sh          $t9, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r25;
    // 0x800B37FC: sh          $t1, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r9;
    // 0x800B3800: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
    // 0x800B3804: bne         $v1, $zero, L_800B37D0
    if (ctx->r3 != 0) {
        // 0x800B3808: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_800B37D0;
    }
    // 0x800B3808: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_800B380C:
    // 0x800B380C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B3810: lwc1        $f8, 0x58($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X58);
    // 0x800B3814: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
    // 0x800B3818: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800B381C: swc1        $f10, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f10.u32l;
    // 0x800B3820: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
    // 0x800B3824: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800B3828: jal         0x80070560
    // 0x800B382C: addiu       $a1, $a0, 0xC
    ctx->r5 = ADD32(ctx->r4, 0XC);
    vec3f_rotate(rdram, ctx);
        goto after_0;
    // 0x800B382C: addiu       $a1, $a0, 0xC
    ctx->r5 = ADD32(ctx->r4, 0XC);
    after_0:
    // 0x800B3830: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800B3834: nop

    // 0x800B3838: lwc1        $f16, 0xC($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800B383C: lwc1        $f18, 0x4C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X4C);
    // 0x800B3840: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800B3844: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B3848: lwc1        $f8, 0x50($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X50);
    // 0x800B384C: lwc1        $f18, 0x54($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X54);
    // 0x800B3850: lwc1        $f16, 0x14($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800B3854: lw          $v0, 0x3C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X3C);
    // 0x800B3858: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
    // 0x800B385C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800B3860: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B3864: swc1        $f10, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f10.u32l;
    // 0x800B3868: beq         $v0, $zero, L_800B38A8
    if (ctx->r2 == 0) {
        // 0x800B386C: swc1        $f4, 0x14($a0)
        MEM_W(0X14, ctx->r4) = ctx->f4.u32l;
            goto L_800B38A8;
    }
    // 0x800B386C: swc1        $f4, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f4.u32l;
    // 0x800B3870: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800B3874: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800B3878: lwc1        $f16, 0x10($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800B387C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800B3880: lwc1        $f6, 0x14($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800B3884: swc1        $f10, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f10.u32l;
    // 0x800B3888: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800B388C: nop

    // 0x800B3890: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B3894: swc1        $f4, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f4.u32l;
    // 0x800B3898: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800B389C: nop

    // 0x800B38A0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800B38A4: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
L_800B38A8:
    // 0x800B38A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B38AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B38B0: jr          $ra
    // 0x800B38B4: nop

    return;
    // 0x800B38B4: nop

;}
RECOMP_FUNC void move_particle_with_acceleration(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B38B8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800B38BC: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800B38C0: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800B38C4: addiu       $s2, $s2, -0x7DC0
    ctx->r18 = ADD32(ctx->r18, -0X7DC0);
    // 0x800B38C8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800B38CC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800B38D0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800B38D4: slt         $t6, $zero, $v0
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B38D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800B38DC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800B38E0: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800B38E4: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800B38E8: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800B38EC: beq         $t6, $zero, L_800B39EC
    if (ctx->r14 == 0) {
        // 0x800B38F0: addiu       $s1, $zero, 0x1
        ctx->r17 = ADD32(0, 0X1);
            goto L_800B39EC;
    }
    // 0x800B38F0: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x800B38F4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800B38F8: addiu       $s3, $sp, 0x38
    ctx->r19 = ADD32(ctx->r29, 0X38);
L_800B38FC:
    // 0x800B38FC: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800B3900: lwc1        $f6, 0x1C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800B3904: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800B3908: lwc1        $f16, 0x20($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800B390C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B3910: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800B3914: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800B3918: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800B391C: lwc1        $f16, 0x28($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X28);
    // 0x800B3920: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800B3924: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x800B3928: lh          $t8, 0x62($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X62);
    // 0x800B392C: lh          $t0, 0x2($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X2);
    // 0x800B3930: lh          $t1, 0x64($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X64);
    // 0x800B3934: lh          $t3, 0x4($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X4);
    // 0x800B3938: lh          $t4, 0x66($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X66);
    // 0x800B393C: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x800B3940: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
    // 0x800B3944: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B3948: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800B394C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800B3950: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800B3954: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800B3958: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    // 0x800B395C: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x800B3960: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
    // 0x800B3964: sh          $t2, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r10;
    // 0x800B3968: sh          $t5, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r13;
    // 0x800B396C: swc1        $f20, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f20.u32l;
    // 0x800B3970: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800B3974: swc1        $f20, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f20.u32l;
    // 0x800B3978: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800B397C: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x800B3980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B3984: jal         0x80070560
    // 0x800B3988: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    vec3f_rotate(rdram, ctx);
        goto after_0;
    // 0x800B3988: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_0:
    // 0x800B398C: lwc1        $f8, 0x1C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800B3990: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800B3994: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800B3998: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800B399C: lwc1        $f10, 0x68($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X68);
    // 0x800B39A0: swc1        $f16, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f16.u32l;
    // 0x800B39A4: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800B39A8: nop

    // 0x800B39AC: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800B39B0: lwc1        $f18, 0x24($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800B39B4: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    // 0x800B39B8: lwc1        $f8, 0x20($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800B39BC: nop

    // 0x800B39C0: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800B39C4: swc1        $f16, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f16.u32l;
    // 0x800B39C8: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800B39CC: nop

    // 0x800B39D0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800B39D4: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    // 0x800B39D8: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x800B39DC: nop

    // 0x800B39E0: slt         $v0, $s1, $t6
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800B39E4: bne         $v0, $zero, L_800B38FC
    if (ctx->r2 != 0) {
        // 0x800B39E8: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800B38FC;
    }
    // 0x800B39E8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800B39EC:
    // 0x800B39EC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800B39F0: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800B39F4: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800B39F8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800B39FC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800B3A00: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x800B3A04: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x800B3A08: jr          $ra
    // 0x800B3A0C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800B3A0C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void move_particle_basic(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3A10: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B3A14: addiu       $a1, $a1, -0x7DC0
    ctx->r5 = ADD32(ctx->r5, -0X7DC0);
    // 0x800B3A18: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800B3A1C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800B3A20: slt         $t6, $zero, $v0
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B3A24: beq         $t6, $zero, L_800B3ABC
    if (ctx->r14 == 0) {
        // 0x800B3A28: nop
    
            goto L_800B3ABC;
    }
    // 0x800B3A28: nop

L_800B3A2C:
    // 0x800B3A2C: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800B3A30: lwc1        $f6, 0x1C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800B3A34: lwc1        $f0, 0x20($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800B3A38: lwc1        $f10, 0x10($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800B3A3C: lwc1        $f18, 0x68($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X68);
    // 0x800B3A40: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B3A44: lwc1        $f6, 0x14($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800B3A48: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x800B3A4C: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
    // 0x800B3A50: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x800B3A54: swc1        $f16, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f16.u32l;
    // 0x800B3A58: lwc1        $f8, 0x24($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800B3A5C: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800B3A60: lwc1        $f18, 0x28($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X28);
    // 0x800B3A64: lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X0);
    // 0x800B3A68: lh          $t8, 0x62($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X62);
    // 0x800B3A6C: lh          $t0, 0x2($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X2);
    // 0x800B3A70: lh          $t1, 0x64($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X64);
    // 0x800B3A74: lh          $t3, 0x4($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X4);
    // 0x800B3A78: lh          $t4, 0x66($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X66);
    // 0x800B3A7C: swc1        $f4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f4.u32l;
    // 0x800B3A80: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800B3A84: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800B3A88: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B3A8C: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800B3A90: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800B3A94: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
    // 0x800B3A98: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
    // 0x800B3A9C: sh          $t9, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r25;
    // 0x800B3AA0: sh          $t2, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r10;
    // 0x800B3AA4: sh          $t5, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r13;
    // 0x800B3AA8: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800B3AAC: nop

    // 0x800B3AB0: slt         $v0, $v1, $t6
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800B3AB4: bne         $v0, $zero, L_800B3A2C
    if (ctx->r2 != 0) {
        // 0x800B3AB8: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800B3A2C;
    }
    // 0x800B3AB8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800B3ABC:
    // 0x800B3ABC: jr          $ra
    // 0x800B3AC0: nop

    return;
    // 0x800B3AC0: nop

;}
RECOMP_FUNC void move_particle_forward(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3AC4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800B3AC8: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800B3ACC: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800B3AD0: addiu       $s3, $s3, -0x7DC0
    ctx->r19 = ADD32(ctx->r19, -0X7DC0);
    // 0x800B3AD4: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x800B3AD8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800B3ADC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800B3AE0: slt         $t6, $zero, $v0
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B3AE4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800B3AE8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800B3AEC: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800B3AF0: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800B3AF4: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800B3AF8: beq         $t6, $zero, L_800B3BB4
    if (ctx->r14 == 0) {
        // 0x800B3AFC: addiu       $s1, $zero, 0x1
        ctx->r17 = ADD32(0, 0X1);
            goto L_800B3BB4;
    }
    // 0x800B3AFC: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x800B3B00: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800B3B04: addiu       $s2, $a0, 0x1C
    ctx->r18 = ADD32(ctx->r4, 0X1C);
L_800B3B08:
    // 0x800B3B08: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800B3B0C: swc1        $f20, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f20.u32l;
    // 0x800B3B10: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800B3B14: swc1        $f20, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f20.u32l;
    // 0x800B3B18: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    // 0x800B3B1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B3B20: jal         0x800706D0
    // 0x800B3B24: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    vec3f_rotate_py(rdram, ctx);
        goto after_0;
    // 0x800B3B24: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_0:
    // 0x800B3B28: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800B3B2C: lwc1        $f10, 0x1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800B3B30: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800B3B34: lwc1        $f4, 0x68($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X68);
    // 0x800B3B38: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800B3B3C: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800B3B40: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800B3B44: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x800B3B48: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800B3B4C: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800B3B50: lwc1        $f18, 0x24($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800B3B54: lwc1        $f6, 0x28($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X28);
    // 0x800B3B58: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800B3B5C: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x800B3B60: lh          $t8, 0x62($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X62);
    // 0x800B3B64: lh          $t0, 0x2($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X2);
    // 0x800B3B68: lh          $t1, 0x64($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X64);
    // 0x800B3B6C: lh          $t3, 0x4($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X4);
    // 0x800B3B70: lh          $t4, 0x66($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X66);
    // 0x800B3B74: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    // 0x800B3B78: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B3B7C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800B3B80: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800B3B84: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800B3B88: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800B3B8C: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    // 0x800B3B90: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x800B3B94: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
    // 0x800B3B98: sh          $t2, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r10;
    // 0x800B3B9C: sh          $t5, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r13;
    // 0x800B3BA0: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x800B3BA4: nop

    // 0x800B3BA8: slt         $v0, $s1, $t6
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800B3BAC: bne         $v0, $zero, L_800B3B08
    if (ctx->r2 != 0) {
        // 0x800B3BB0: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800B3B08;
    }
    // 0x800B3BB0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800B3BB4:
    // 0x800B3BB4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800B3BB8: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800B3BBC: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800B3BC0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800B3BC4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800B3BC8: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x800B3BCC: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x800B3BD0: jr          $ra
    // 0x800B3BD4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800B3BD4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void render_active_particles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3BD8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800B3BDC: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800B3BE0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800B3BE4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800B3BE8: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800B3BEC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800B3BF0: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800B3BF4: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x800B3BF8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800B3BFC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x800B3C00: jal         0x8000E988
    // 0x800B3C04: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    objGetObjList(rdram, ctx);
        goto after_0;
    // 0x800B3C04: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_0:
    // 0x800B3C08: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x800B3C0C: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800B3C10: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B3C14: slt         $at, $v1, $t6
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800B3C18: beq         $at, $zero, L_800B3C88
    if (ctx->r1 == 0) {
        // 0x800B3C1C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800B3C88;
    }
    // 0x800B3C1C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800B3C20:
    // 0x800B3C20: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800B3C24: nop

    // 0x800B3C28: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800B3C2C: addu        $t9, $s0, $t8
    ctx->r25 = ADD32(ctx->r16, ctx->r24);
    // 0x800B3C30: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x800B3C34: nop

    // 0x800B3C38: lh          $t0, 0x6($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X6);
    // 0x800B3C3C: nop

    // 0x800B3C40: andi        $t1, $t0, 0x8000
    ctx->r9 = ctx->r8 & 0X8000;
    // 0x800B3C44: beq         $t1, $zero, L_800B3C70
    if (ctx->r9 == 0) {
        // 0x800B3C48: lw          $v1, 0x38($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X38);
            goto L_800B3C70;
    }
    // 0x800B3C48: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x800B3C4C: lw          $t2, 0x40($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X40);
    // 0x800B3C50: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800B3C54: andi        $t3, $t2, 0x8000
    ctx->r11 = ctx->r10 & 0X8000;
    // 0x800B3C58: beq         $t3, $zero, L_800B3C6C
    if (ctx->r11 == 0) {
        // 0x800B3C5C: or          $a2, $s2, $zero
        ctx->r6 = ctx->r18 | 0;
            goto L_800B3C6C;
    }
    // 0x800B3C5C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800B3C60: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x800B3C64: jal         0x800B3CA0
    // 0x800B3C68: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    render_particle(rdram, ctx);
        goto after_1;
    // 0x800B3C68: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
L_800B3C6C:
    // 0x800B3C6C: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
L_800B3C70:
    // 0x800B3C70: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x800B3C74: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800B3C78: slt         $at, $v1, $t4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800B3C7C: bne         $at, $zero, L_800B3C20
    if (ctx->r1 != 0) {
        // 0x800B3C80: sw          $v1, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r3;
            goto L_800B3C20;
    }
    // 0x800B3C80: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    // 0x800B3C84: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800B3C88:
    // 0x800B3C88: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800B3C8C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800B3C90: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x800B3C94: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x800B3C98: jr          $ra
    // 0x800B3C9C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800B3C9C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void render_particle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3CA0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800B3CA4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800B3CA8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800B3CAC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800B3CB0: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800B3CB4: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x800B3CB8: lw          $t6, 0x40($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X40);
    // 0x800B3CBC: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x800B3CC0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800B3CC4: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x800B3CC8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800B3CCC: beq         $t8, $zero, L_800B3CEC
    if (ctx->r24 == 0) {
        // 0x800B3CD0: addiu       $t3, $zero, 0xA
        ctx->r11 = ADD32(0, 0XA);
            goto L_800B3CEC;
    }
    // 0x800B3CD0: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x800B3CD4: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800B3CD8: lw          $t9, 0x326C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X326C);
    // 0x800B3CDC: nop

    // 0x800B3CE0: slti        $at, $t9, 0x200
    ctx->r1 = SIGNED(ctx->r25) < 0X200 ? 1 : 0;
    // 0x800B3CE4: bne         $at, $zero, L_800B43B0
    if (ctx->r1 != 0) {
        // 0x800B3CE8: nop
    
            goto L_800B43B0;
    }
    // 0x800B3CE8: nop

L_800B3CEC:
    // 0x800B3CEC: lh          $t2, 0x5C($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X5C);
    // 0x800B3CF0: nop

    // 0x800B3CF4: sra         $t4, $t2, 8
    ctx->r12 = S32(SIGNED(ctx->r10) >> 8);
    // 0x800B3CF8: andi        $t2, $t4, 0xFF
    ctx->r10 = ctx->r12 & 0XFF;
    // 0x800B3CFC: blez        $t2, L_800B43B0
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800B3D00: nop
    
            goto L_800B43B0;
    }
    // 0x800B3D00: nop

    // 0x800B3D04: lh          $v1, 0x2C($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X2C);
    // 0x800B3D08: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800B3D0C: beq         $a1, $v1, L_800B3FDC
    if (ctx->r5 == ctx->r3) {
        // 0x800B3D10: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800B3FDC;
    }
    // 0x800B3D10: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B3D14: beq         $v1, $at, L_800B3FDC
    if (ctx->r3 == ctx->r1) {
        // 0x800B3D18: addiu       $t1, $zero, 0xFF
        ctx->r9 = ADD32(0, 0XFF);
            goto L_800B3FDC;
    }
    // 0x800B3D18: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800B3D1C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B3D20: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x800B3D24: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800B3D28: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800B3D2C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B3D30: lbu         $t6, 0x6D($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X6D);
    // 0x800B3D34: lbu         $t9, 0x6C($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X6C);
    // 0x800B3D38: lbu         $t5, 0x6E($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X6E);
    // 0x800B3D3C: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x800B3D40: sll         $t4, $t9, 24
    ctx->r12 = S32(ctx->r25 << 24);
    // 0x800B3D44: lbu         $t9, 0x6F($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X6F);
    // 0x800B3D48: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x800B3D4C: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x800B3D50: or          $t4, $t8, $t6
    ctx->r12 = ctx->r24 | ctx->r14;
    // 0x800B3D54: or          $t5, $t4, $t9
    ctx->r13 = ctx->r12 | ctx->r25;
    // 0x800B3D58: beq         $t2, $t1, L_800B3DA4
    if (ctx->r10 == ctx->r9) {
        // 0x800B3D5C: sw          $t5, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r13;
            goto L_800B3DA4;
    }
    // 0x800B3D5C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800B3D60: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800B3D64: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800B3D68: addiu       $t8, $a0, 0x8
    ctx->r24 = ADD32(ctx->r4, 0X8);
    // 0x800B3D6C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800B3D70: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B3D74: lh          $v1, 0x4A($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X4A);
    // 0x800B3D78: addiu       $t3, $zero, 0x10E
    ctx->r11 = ADD32(0, 0X10E);
    // 0x800B3D7C: andi        $t7, $v1, 0xFF
    ctx->r15 = ctx->r3 & 0XFF;
    // 0x800B3D80: sll         $t4, $t7, 24
    ctx->r12 = S32(ctx->r15 << 24);
    // 0x800B3D84: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x800B3D88: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x800B3D8C: or          $t5, $t4, $t9
    ctx->r13 = ctx->r12 | ctx->r25;
    // 0x800B3D90: or          $t6, $t5, $t8
    ctx->r14 = ctx->r13 | ctx->r24;
    // 0x800B3D94: andi        $t7, $t2, 0xFF
    ctx->r15 = ctx->r10 & 0XFF;
    // 0x800B3D98: or          $t4, $t6, $t7
    ctx->r12 = ctx->r14 | ctx->r15;
    // 0x800B3D9C: b           L_800B3DC0
    // 0x800B3DA0: sw          $t4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r12;
        goto L_800B3DC0;
    // 0x800B3DA0: sw          $t4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r12;
L_800B3DA4:
    // 0x800B3DA4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B3DA8: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x800B3DAC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800B3DB0: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800B3DB4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800B3DB8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800B3DBC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_800B3DC0:
    // 0x800B3DC0: lh          $t6, 0x2C($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X2C);
    // 0x800B3DC4: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x800B3DC8: bne         $t6, $at, L_800B3E64
    if (ctx->r14 != ctx->r1) {
        // 0x800B3DCC: nop
    
            goto L_800B3E64;
    }
    // 0x800B3DCC: nop

    // 0x800B3DD0: lh          $v1, 0x18($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X18);
    // 0x800B3DD4: lw          $t0, 0x44($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X44);
    // 0x800B3DD8: sra         $t7, $v1, 8
    ctx->r15 = S32(SIGNED(ctx->r3) >> 8);
    // 0x800B3DDC: sh          $t7, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r15;
    // 0x800B3DE0: lh          $t4, 0x18($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X18);
    // 0x800B3DE4: lh          $t5, 0x0($t0)
    ctx->r13 = MEM_H(ctx->r8, 0X0);
    // 0x800B3DE8: multu       $t4, $t1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B3DEC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B3DF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B3DF4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x800B3DF8: mflo        $t9
    ctx->r25 = lo;
    // 0x800B3DFC: nop

    // 0x800B3E00: nop

    // 0x800B3E04: div         $zero, $t9, $t5
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r13))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r13)));
    // 0x800B3E08: bne         $t5, $zero, L_800B3E14
    if (ctx->r13 != 0) {
        // 0x800B3E0C: nop
    
            goto L_800B3E14;
    }
    // 0x800B3E0C: nop

    // 0x800B3E10: break       7
    do_break(2148220432);
L_800B3E14:
    // 0x800B3E14: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B3E18: bne         $t5, $at, L_800B3E2C
    if (ctx->r13 != ctx->r1) {
        // 0x800B3E1C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B3E2C;
    }
    // 0x800B3E1C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B3E20: bne         $t9, $at, L_800B3E2C
    if (ctx->r25 != ctx->r1) {
        // 0x800B3E24: nop
    
            goto L_800B3E2C;
    }
    // 0x800B3E24: nop

    // 0x800B3E28: break       6
    do_break(2148220456);
L_800B3E2C:
    // 0x800B3E2C: mflo        $t8
    ctx->r24 = lo;
    // 0x800B3E30: sh          $t8, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r24;
    // 0x800B3E34: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x800B3E38: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800B3E3C: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x800B3E40: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x800B3E44: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800B3E48: jal         0x80068754
    // 0x800B3E4C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    render_sprite_billboard(rdram, ctx);
        goto after_0;
    // 0x800B3E4C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_0:
    // 0x800B3E50: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x800B3E54: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800B3E58: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800B3E5C: b           L_800B3F80
    // 0x800B3E60: sh          $v0, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r2;
        goto L_800B3F80;
    // 0x800B3E60: sh          $v0, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r2;
L_800B3E64:
    // 0x800B3E64: lw          $v1, 0x44($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X44);
    // 0x800B3E68: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800B3E6C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800B3E70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B3E74: beq         $t6, $zero, L_800B3F80
    if (ctx->r14 == 0) {
        // 0x800B3E78: or          $a2, $s1, $zero
        ctx->r6 = ctx->r17 | 0;
            goto L_800B3F80;
    }
    // 0x800B3E78: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x800B3E7C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B3E80: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x800B3E84: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x800B3E88: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x800B3E8C: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x800B3E90: jal         0x800696C4
    // 0x800B3E94: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    mtx_cam_push(rdram, ctx);
        goto after_1;
    // 0x800B3E94: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x800B3E98: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800B3E9C: lh          $a3, 0x18($s1)
    ctx->r7 = MEM_H(ctx->r17, 0X18);
    // 0x800B3EA0: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x800B3EA4: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x800B3EA8: sll         $t7, $a3, 8
    ctx->r15 = S32(ctx->r7 << 8);
    // 0x800B3EAC: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x800B3EB0: jal         0x8007B938
    // 0x800B3EB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    material_set(rdram, ctx);
        goto after_2;
    // 0x800B3EB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800B3EB8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B3EBC: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800B3EC0: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800B3EC4: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x800B3EC8: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x800B3ECC: lh          $a1, 0x4($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X4);
    // 0x800B3ED0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x800B3ED4: addu        $t6, $t8, $a3
    ctx->r14 = ADD32(ctx->r24, ctx->r7);
    // 0x800B3ED8: addiu       $t9, $a1, -0x1
    ctx->r25 = ADD32(ctx->r5, -0X1);
    // 0x800B3EDC: sll         $t5, $t9, 3
    ctx->r13 = S32(ctx->r25 << 3);
    // 0x800B3EE0: andi        $t7, $t6, 0x6
    ctx->r15 = ctx->r14 & 0X6;
    // 0x800B3EE4: or          $t4, $t5, $t7
    ctx->r12 = ctx->r13 | ctx->r15;
    // 0x800B3EE8: andi        $t9, $t4, 0xFF
    ctx->r25 = ctx->r12 & 0XFF;
    // 0x800B3EEC: sll         $t5, $a1, 3
    ctx->r13 = S32(ctx->r5 << 3);
    // 0x800B3EF0: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x800B3EF4: addu        $t7, $t5, $a1
    ctx->r15 = ADD32(ctx->r13, ctx->r5);
    // 0x800B3EF8: sll         $t4, $t7, 1
    ctx->r12 = S32(ctx->r15 << 1);
    // 0x800B3EFC: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x800B3F00: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x800B3F04: addiu       $t9, $t4, 0x8
    ctx->r25 = ADD32(ctx->r12, 0X8);
    // 0x800B3F08: andi        $t8, $t9, 0xFFFF
    ctx->r24 = ctx->r25 & 0XFFFF;
    // 0x800B3F0C: or          $t5, $t6, $t8
    ctx->r13 = ctx->r14 | ctx->r24;
    // 0x800B3F10: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800B3F14: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x800B3F18: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x800B3F1C: addu        $t4, $t7, $a3
    ctx->r12 = ADD32(ctx->r15, ctx->r7);
    // 0x800B3F20: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800B3F24: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B3F28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B3F2C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800B3F30: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800B3F34: lh          $a2, 0x6($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X6);
    // 0x800B3F38: nop

    // 0x800B3F3C: addiu       $t6, $a2, -0x1
    ctx->r14 = ADD32(ctx->r6, -0X1);
    // 0x800B3F40: sll         $t8, $t6, 4
    ctx->r24 = S32(ctx->r14 << 4);
    // 0x800B3F44: ori         $t5, $t8, 0x1
    ctx->r13 = ctx->r24 | 0X1;
    // 0x800B3F48: andi        $t7, $t5, 0xFF
    ctx->r15 = ctx->r13 & 0XFF;
    // 0x800B3F4C: sll         $t4, $t7, 16
    ctx->r12 = S32(ctx->r15 << 16);
    // 0x800B3F50: sll         $t6, $a2, 4
    ctx->r14 = S32(ctx->r6 << 4);
    // 0x800B3F54: andi        $t8, $t6, 0xFFFF
    ctx->r24 = ctx->r14 & 0XFFFF;
    // 0x800B3F58: or          $t9, $t4, $at
    ctx->r25 = ctx->r12 | ctx->r1;
    // 0x800B3F5C: or          $t5, $t9, $t8
    ctx->r13 = ctx->r25 | ctx->r24;
    // 0x800B3F60: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800B3F64: lw          $t7, 0xC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XC);
    // 0x800B3F68: nop

    // 0x800B3F6C: addu        $t4, $t7, $a3
    ctx->r12 = ADD32(ctx->r15, ctx->r7);
    // 0x800B3F70: jal         0x80069C80
    // 0x800B3F74: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    mtx_pop(rdram, ctx);
        goto after_3;
    // 0x800B3F74: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    after_3:
    // 0x800B3F78: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800B3F7C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
L_800B3F80:
    // 0x800B3F80: bne         $t2, $t1, L_800B3F98
    if (ctx->r10 != ctx->r9) {
        // 0x800B3F84: lui         $t8, 0xFA00
        ctx->r24 = S32(0XFA00 << 16);
            goto L_800B3F98;
    }
    // 0x800B3F84: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x800B3F88: lh          $t6, 0x4A($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X4A);
    // 0x800B3F8C: nop

    // 0x800B3F90: beq         $t1, $t6, L_800B3FB0
    if (ctx->r9 == ctx->r14) {
        // 0x800B3F94: nop
    
            goto L_800B3FB0;
    }
    // 0x800B3F94: nop

L_800B3F98:
    // 0x800B3F98: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B3F9C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800B3FA0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800B3FA4: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800B3FA8: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800B3FAC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_800B3FB0:
    // 0x800B3FB0: lbu         $t7, 0x6F($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X6F);
    // 0x800B3FB4: lui         $t6, 0xFB00
    ctx->r14 = S32(0XFB00 << 16);
    // 0x800B3FB8: beq         $t7, $zero, L_800B43B4
    if (ctx->r15 == 0) {
        // 0x800B3FBC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800B43B4;
    }
    // 0x800B3FBC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800B3FC0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B3FC4: addiu       $t9, $zero, -0x100
    ctx->r25 = ADD32(0, -0X100);
    // 0x800B3FC8: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800B3FCC: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x800B3FD0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800B3FD4: b           L_800B43B0
    // 0x800B3FD8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
        goto L_800B43B0;
    // 0x800B3FD8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_800B3FDC:
    // 0x800B3FDC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B3FE0: lui         $t5, 0xFB00
    ctx->r13 = S32(0XFB00 << 16);
    // 0x800B3FE4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800B3FE8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800B3FEC: addiu       $t7, $zero, -0x100
    ctx->r15 = ADD32(0, -0X100);
    // 0x800B3FF0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800B3FF4: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800B3FF8: lh          $v1, 0x2C($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X2C);
    // 0x800B3FFC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B4000: bne         $a1, $v1, L_800B4190
    if (ctx->r5 != ctx->r3) {
        // 0x800B4004: nop
    
            goto L_800B4190;
    }
    // 0x800B4004: nop

    // 0x800B4008: lh          $t4, 0x3A($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X3A);
    // 0x800B400C: nop

    // 0x800B4010: blez        $t4, L_800B43B4
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800B4014: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800B43B4;
    }
    // 0x800B4014: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800B4018: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B401C: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x800B4020: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800B4024: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800B4028: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800B402C: lh          $v1, 0x4A($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X4A);
    // 0x800B4030: nop

    // 0x800B4034: andi        $t8, $v1, 0xFF
    ctx->r24 = ctx->r3 & 0XFF;
    // 0x800B4038: sll         $t5, $t8, 24
    ctx->r13 = S32(ctx->r24 << 24);
    // 0x800B403C: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x800B4040: or          $t4, $t5, $t7
    ctx->r12 = ctx->r13 | ctx->r15;
    // 0x800B4044: sll         $t6, $t8, 8
    ctx->r14 = S32(ctx->r24 << 8);
    // 0x800B4048: or          $t9, $t4, $t6
    ctx->r25 = ctx->r12 | ctx->r14;
    // 0x800B404C: ori         $t8, $t9, 0xFF
    ctx->r24 = ctx->r25 | 0XFF;
    // 0x800B4050: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800B4054: lb          $t5, 0x77($s1)
    ctx->r13 = MEM_B(ctx->r17, 0X77);
    // 0x800B4058: nop

    // 0x800B405C: bne         $t5, $zero, L_800B406C
    if (ctx->r13 != 0) {
        // 0x800B4060: nop
    
            goto L_800B406C;
    }
    // 0x800B4060: nop

    // 0x800B4064: jal         0x800B43C4
    // 0x800B4068: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    regenerate_point_particles_mesh(rdram, ctx);
        goto after_4;
    // 0x800B4068: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
L_800B406C:
    // 0x800B406C: lbu         $v0, 0x75($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X75);
    // 0x800B4070: lw          $v1, 0x44($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X44);
    // 0x800B4074: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x800B4078: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x800B407C: lw          $t4, 0x8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X8);
    // 0x800B4080: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x800B4084: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x800B4088: addu        $t9, $t4, $t6
    ctx->r25 = ADD32(ctx->r12, ctx->r14);
    // 0x800B408C: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x800B4090: lh          $a3, 0x18($s1)
    ctx->r7 = MEM_H(ctx->r17, 0X18);
    // 0x800B4094: lui         $a2, 0x800
    ctx->r6 = S32(0X800 << 16);
    // 0x800B4098: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x800B409C: sll         $t8, $a3, 8
    ctx->r24 = S32(ctx->r7 << 8);
    // 0x800B40A0: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x800B40A4: ori         $a2, $a2, 0x10B
    ctx->r6 = ctx->r6 | 0X10B;
    // 0x800B40A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B40AC: jal         0x8007B938
    // 0x800B40B0: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    material_set(rdram, ctx);
        goto after_5;
    // 0x800B40B0: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_5:
    // 0x800B40B4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B40B8: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800B40BC: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x800B40C0: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x800B40C4: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800B40C8: lh          $a1, 0x4($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X4);
    // 0x800B40CC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x800B40D0: addu        $t0, $t7, $a3
    ctx->r8 = ADD32(ctx->r15, ctx->r7);
    // 0x800B40D4: addiu       $t4, $a1, -0x1
    ctx->r12 = ADD32(ctx->r5, -0X1);
    // 0x800B40D8: sll         $t6, $t4, 3
    ctx->r14 = S32(ctx->r12 << 3);
    // 0x800B40DC: andi        $t9, $t0, 0x6
    ctx->r25 = ctx->r8 & 0X6;
    // 0x800B40E0: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x800B40E4: andi        $t5, $t8, 0xFF
    ctx->r13 = ctx->r24 & 0XFF;
    // 0x800B40E8: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x800B40EC: sll         $t7, $t5, 16
    ctx->r15 = S32(ctx->r13 << 16);
    // 0x800B40F0: addu        $t9, $t6, $a1
    ctx->r25 = ADD32(ctx->r14, ctx->r5);
    // 0x800B40F4: sll         $t8, $t9, 1
    ctx->r24 = S32(ctx->r25 << 1);
    // 0x800B40F8: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x800B40FC: or          $t4, $t7, $at
    ctx->r12 = ctx->r15 | ctx->r1;
    // 0x800B4100: addiu       $t5, $t8, 0x8
    ctx->r13 = ADD32(ctx->r24, 0X8);
    // 0x800B4104: andi        $t7, $t5, 0xFFFF
    ctx->r15 = ctx->r13 & 0XFFFF;
    // 0x800B4108: or          $t6, $t4, $t7
    ctx->r14 = ctx->r12 | ctx->r15;
    // 0x800B410C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800B4110: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x800B4114: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B4118: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x800B411C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800B4120: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800B4124: lh          $a2, 0x6($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X6);
    // 0x800B4128: nop

    // 0x800B412C: addiu       $t8, $a2, -0x1
    ctx->r24 = ADD32(ctx->r6, -0X1);
    // 0x800B4130: sll         $t5, $t8, 4
    ctx->r13 = S32(ctx->r24 << 4);
    // 0x800B4134: ori         $t4, $t5, 0x1
    ctx->r12 = ctx->r13 | 0X1;
    // 0x800B4138: andi        $t7, $t4, 0xFF
    ctx->r15 = ctx->r12 & 0XFF;
    // 0x800B413C: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x800B4140: sll         $t8, $a2, 4
    ctx->r24 = S32(ctx->r6 << 4);
    // 0x800B4144: andi        $t5, $t8, 0xFFFF
    ctx->r13 = ctx->r24 & 0XFFFF;
    // 0x800B4148: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x800B414C: or          $t4, $t9, $t5
    ctx->r12 = ctx->r25 | ctx->r13;
    // 0x800B4150: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800B4154: lw          $t7, 0xC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XC);
    // 0x800B4158: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800B415C: addu        $t6, $t7, $a3
    ctx->r14 = ADD32(ctx->r15, ctx->r7);
    // 0x800B4160: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800B4164: lh          $t8, 0x4A($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X4A);
    // 0x800B4168: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x800B416C: beq         $t8, $at, L_800B43B4
    if (ctx->r24 == ctx->r1) {
        // 0x800B4170: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800B43B4;
    }
    // 0x800B4170: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800B4174: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B4178: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800B417C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800B4180: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800B4184: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800B4188: b           L_800B43B0
    // 0x800B418C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
        goto L_800B43B0;
    // 0x800B418C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_800B4190:
    // 0x800B4190: bne         $v1, $at, L_800B43B4
    if (ctx->r3 != ctx->r1) {
        // 0x800B4194: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800B43B4;
    }
    // 0x800B4194: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800B4198: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B419C: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800B41A0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800B41A4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800B41A8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800B41AC: lh          $v1, 0x4A($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X4A);
    // 0x800B41B0: lui         $a2, 0x800
    ctx->r6 = S32(0X800 << 16);
    // 0x800B41B4: andi        $t8, $v1, 0xFF
    ctx->r24 = ctx->r3 & 0XFF;
    // 0x800B41B8: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x800B41BC: sll         $t5, $t8, 16
    ctx->r13 = S32(ctx->r24 << 16);
    // 0x800B41C0: sll         $t7, $t8, 8
    ctx->r15 = S32(ctx->r24 << 8);
    // 0x800B41C4: or          $t4, $t9, $t5
    ctx->r12 = ctx->r25 | ctx->r13;
    // 0x800B41C8: or          $t6, $t4, $t7
    ctx->r14 = ctx->r12 | ctx->r15;
    // 0x800B41CC: andi        $t8, $t2, 0xFF
    ctx->r24 = ctx->r10 & 0XFF;
    // 0x800B41D0: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800B41D4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800B41D8: lbu         $a1, 0x68($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X68);
    // 0x800B41DC: ori         $a2, $a2, 0x10B
    ctx->r6 = ctx->r6 | 0X10B;
    // 0x800B41E0: slti        $at, $a1, 0x2
    ctx->r1 = SIGNED(ctx->r5) < 0X2 ? 1 : 0;
    // 0x800B41E4: bne         $at, $zero, L_800B42D0
    if (ctx->r1 != 0) {
        // 0x800B41E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800B42D0;
    }
    // 0x800B41E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B41EC: lw          $v1, 0x44($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X44);
    // 0x800B41F0: lh          $a3, 0x18($s1)
    ctx->r7 = MEM_H(ctx->r17, 0X18);
    // 0x800B41F4: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x800B41F8: sll         $t5, $a3, 8
    ctx->r13 = S32(ctx->r7 << 8);
    // 0x800B41FC: or          $a3, $t5, $zero
    ctx->r7 = ctx->r13 | 0;
    // 0x800B4200: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x800B4204: jal         0x8007B938
    // 0x800B4208: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    material_set(rdram, ctx);
        goto after_6;
    // 0x800B4208: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_6:
    // 0x800B420C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B4210: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800B4214: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800B4218: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800B421C: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x800B4220: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x800B4224: lh          $a1, 0x4($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X4);
    // 0x800B4228: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x800B422C: addu        $t9, $t8, $a3
    ctx->r25 = ADD32(ctx->r24, ctx->r7);
    // 0x800B4230: addiu       $t7, $a1, -0x1
    ctx->r15 = ADD32(ctx->r5, -0X1);
    // 0x800B4234: sll         $t6, $t7, 3
    ctx->r14 = S32(ctx->r15 << 3);
    // 0x800B4238: andi        $t5, $t9, 0x6
    ctx->r13 = ctx->r25 & 0X6;
    // 0x800B423C: or          $t4, $t6, $t5
    ctx->r12 = ctx->r14 | ctx->r13;
    // 0x800B4240: andi        $t7, $t4, 0xFF
    ctx->r15 = ctx->r12 & 0XFF;
    // 0x800B4244: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x800B4248: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x800B424C: addu        $t5, $t6, $a1
    ctx->r13 = ADD32(ctx->r14, ctx->r5);
    // 0x800B4250: sll         $t4, $t5, 1
    ctx->r12 = S32(ctx->r13 << 1);
    // 0x800B4254: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x800B4258: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x800B425C: addiu       $t7, $t4, 0x8
    ctx->r15 = ADD32(ctx->r12, 0X8);
    // 0x800B4260: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x800B4264: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x800B4268: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800B426C: lw          $t5, 0x8($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X8);
    // 0x800B4270: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x800B4274: addu        $t4, $t5, $a3
    ctx->r12 = ADD32(ctx->r13, ctx->r7);
    // 0x800B4278: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800B427C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B4280: nop

    // 0x800B4284: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800B4288: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800B428C: lh          $a2, 0x6($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X6);
    // 0x800B4290: nop

    // 0x800B4294: addiu       $t9, $a2, -0x1
    ctx->r25 = ADD32(ctx->r6, -0X1);
    // 0x800B4298: sll         $t8, $t9, 4
    ctx->r24 = S32(ctx->r25 << 4);
    // 0x800B429C: ori         $t6, $t8, 0x1
    ctx->r14 = ctx->r24 | 0X1;
    // 0x800B42A0: andi        $t5, $t6, 0xFF
    ctx->r13 = ctx->r14 & 0XFF;
    // 0x800B42A4: sll         $t4, $t5, 16
    ctx->r12 = S32(ctx->r13 << 16);
    // 0x800B42A8: sll         $t9, $a2, 4
    ctx->r25 = S32(ctx->r6 << 4);
    // 0x800B42AC: andi        $t8, $t9, 0xFFFF
    ctx->r24 = ctx->r25 & 0XFFFF;
    // 0x800B42B0: or          $t7, $t4, $at
    ctx->r15 = ctx->r12 | ctx->r1;
    // 0x800B42B4: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x800B42B8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800B42BC: lw          $t5, 0xC($v1)
    ctx->r13 = MEM_W(ctx->r3, 0XC);
    // 0x800B42C0: nop

    // 0x800B42C4: addu        $t4, $t5, $a3
    ctx->r12 = ADD32(ctx->r13, ctx->r7);
    // 0x800B42C8: b           L_800B437C
    // 0x800B42CC: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
        goto L_800B437C;
    // 0x800B42CC: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
L_800B42D0:
    // 0x800B42D0: blez        $a1, L_800B437C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800B42D4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800B437C;
    }
    // 0x800B42D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B42D8: lw          $v1, 0x44($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X44);
    // 0x800B42DC: lh          $a3, 0x18($s1)
    ctx->r7 = MEM_H(ctx->r17, 0X18);
    // 0x800B42E0: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x800B42E4: lui         $a2, 0x800
    ctx->r6 = S32(0X800 << 16);
    // 0x800B42E8: sll         $t9, $a3, 8
    ctx->r25 = S32(ctx->r7 << 8);
    // 0x800B42EC: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x800B42F0: ori         $a2, $a2, 0x10B
    ctx->r6 = ctx->r6 | 0X10B;
    // 0x800B42F4: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x800B42F8: jal         0x8007B938
    // 0x800B42FC: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    material_set(rdram, ctx);
        goto after_7;
    // 0x800B42FC: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_7:
    // 0x800B4300: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B4304: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800B4308: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800B430C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800B4310: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800B4314: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x800B4318: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x800B431C: addu        $t6, $t8, $a3
    ctx->r14 = ADD32(ctx->r24, ctx->r7);
    // 0x800B4320: andi        $t5, $t6, 0x6
    ctx->r13 = ctx->r14 & 0X6;
    // 0x800B4324: ori         $t4, $t5, 0x18
    ctx->r12 = ctx->r13 | 0X18;
    // 0x800B4328: andi        $t9, $t4, 0xFF
    ctx->r25 = ctx->r12 & 0XFF;
    // 0x800B432C: sll         $t7, $t9, 16
    ctx->r15 = S32(ctx->r25 << 16);
    // 0x800B4330: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x800B4334: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800B4338: ori         $t6, $t8, 0x50
    ctx->r14 = ctx->r24 | 0X50;
    // 0x800B433C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800B4340: lw          $t5, 0x8($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X8);
    // 0x800B4344: lui         $t7, 0x501
    ctx->r15 = S32(0X501 << 16);
    // 0x800B4348: addu        $t4, $t5, $a3
    ctx->r12 = ADD32(ctx->r13, ctx->r7);
    // 0x800B434C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800B4350: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B4354: ori         $t7, $t7, 0x10
    ctx->r15 = ctx->r15 | 0X10;
    // 0x800B4358: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800B435C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800B4360: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B4364: lh          $t6, 0x6($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X6);
    // 0x800B4368: lw          $t8, 0xC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XC);
    // 0x800B436C: sll         $t5, $t6, 4
    ctx->r13 = S32(ctx->r14 << 4);
    // 0x800B4370: addu        $t4, $t8, $t5
    ctx->r12 = ADD32(ctx->r24, ctx->r13);
    // 0x800B4374: addu        $t9, $t4, $a3
    ctx->r25 = ADD32(ctx->r12, ctx->r7);
    // 0x800B4378: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
L_800B437C:
    // 0x800B437C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800B4380: bne         $t2, $at, L_800B4398
    if (ctx->r10 != ctx->r1) {
        // 0x800B4384: lui         $t8, 0xFA00
        ctx->r24 = S32(0XFA00 << 16);
            goto L_800B4398;
    }
    // 0x800B4384: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x800B4388: lh          $t7, 0x4A($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X4A);
    // 0x800B438C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800B4390: beq         $t7, $at, L_800B43B4
    if (ctx->r15 == ctx->r1) {
        // 0x800B4394: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800B43B4;
    }
    // 0x800B4394: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800B4398:
    // 0x800B4398: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B439C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800B43A0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800B43A4: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800B43A8: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800B43AC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_800B43B0:
    // 0x800B43B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800B43B4:
    // 0x800B43B4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800B43B8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800B43BC: jr          $ra
    // 0x800B43C0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800B43C0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void regenerate_point_particles_mesh(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B43C4: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x800B43C8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800B43CC: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800B43D0: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800B43D4: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800B43D8: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800B43DC: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800B43E0: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800B43E4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800B43E8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800B43EC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800B43F0: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800B43F4: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800B43F8: lw          $s6, 0x70($a0)
    ctx->r22 = MEM_W(ctx->r4, 0X70);
    // 0x800B43FC: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800B4400: beq         $s6, $zero, L_800B49B0
    if (ctx->r22 == 0) {
        // 0x800B4404: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800B49B0;
    }
    // 0x800B4404: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800B4408: lw          $t6, 0xC($s6)
    ctx->r14 = MEM_W(ctx->r22, 0XC);
    // 0x800B440C: nop

    // 0x800B4410: beq         $t6, $zero, L_800B49B4
    if (ctx->r14 == 0) {
        // 0x800B4414: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_800B49B4;
    }
    // 0x800B4414: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800B4418: lbu         $v0, 0x6($s6)
    ctx->r2 = MEM_BU(ctx->r22, 0X6);
    // 0x800B441C: addiu       $fp, $sp, 0x7C
    ctx->r30 = ADD32(ctx->r29, 0X7C);
    // 0x800B4420: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800B4424: bltz        $v0, L_800B49B0
    if (SIGNED(ctx->r2) < 0) {
        // 0x800B4428: sll         $s2, $v0, 2
        ctx->r18 = S32(ctx->r2 << 2);
            goto L_800B49B0;
    }
    // 0x800B4428: sll         $s2, $v0, 2
    ctx->r18 = S32(ctx->r2 << 2);
    // 0x800B442C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800B4430: addiu       $s7, $sp, 0x70
    ctx->r23 = ADD32(ctx->r29, 0X70);
    // 0x800B4434: addiu       $s4, $zero, 0xA
    ctx->r20 = ADD32(0, 0XA);
L_800B4438:
    // 0x800B4438: lw          $t7, 0xC($s6)
    ctx->r15 = MEM_W(ctx->r22, 0XC);
    // 0x800B443C: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x800B4440: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x800B4444: lw          $s0, 0x0($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X0);
    // 0x800B4448: nop

    // 0x800B444C: lh          $t9, 0x3A($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X3A);
    // 0x800B4450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B4454: beq         $t9, $zero, L_800B49B4
    if (ctx->r25 == 0) {
        // 0x800B4458: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_800B49B4;
    }
    // 0x800B4458: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800B445C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800B4460: lw          $s1, 0x44($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X44);
    // 0x800B4464: swc1        $f20, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f20.u32l;
    // 0x800B4468: swc1        $f20, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f20.u32l;
    // 0x800B446C: jal         0x80070560
    // 0x800B4470: swc1        $f4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f4.u32l;
    vec3f_rotate(rdram, ctx);
        goto after_0;
    // 0x800B4470: swc1        $f4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x800B4474: swc1        $f20, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f20.u32l;
    // 0x800B4478: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800B447C: swc1        $f20, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f20.u32l;
    // 0x800B4480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B4484: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x800B4488: jal         0x80070560
    // 0x800B448C: swc1        $f6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f6.u32l;
    vec3f_rotate(rdram, ctx);
        goto after_1;
    // 0x800B448C: swc1        $f6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x800B4490: lbu         $t1, 0x75($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X75);
    // 0x800B4494: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800B4498: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x800B449C: multu       $t2, $s4
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B44A0: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800B44A4: lw          $t0, 0x8($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X8);
    // 0x800B44A8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800B44AC: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800B44B0: nop

    // 0x800B44B4: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800B44B8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B44BC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B44C0: nop

    // 0x800B44C4: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B44C8: mflo        $t3
    ctx->r11 = lo;
    // 0x800B44CC: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x800B44D0: addu        $v1, $t0, $t3
    ctx->r3 = ADD32(ctx->r8, ctx->r11);
    // 0x800B44D4: sh          $t5, 0x28($v1)
    MEM_H(0X28, ctx->r3) = ctx->r13;
    // 0x800B44D8: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800B44DC: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800B44E0: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800B44E4: addiu       $v1, $v1, 0x46
    ctx->r3 = ADD32(ctx->r3, 0X46);
    // 0x800B44E8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B44EC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800B44F0: nop

    // 0x800B44F4: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800B44F8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B44FC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B4500: nop

    // 0x800B4504: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800B4508: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x800B450C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800B4510: sh          $t7, -0x1C($v1)
    MEM_H(-0X1C, ctx->r3) = ctx->r15;
    // 0x800B4514: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800B4518: lwc1        $f16, 0x78($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800B451C: nop

    // 0x800B4520: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B4524: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800B4528: nop

    // 0x800B452C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800B4530: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B4534: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B4538: nop

    // 0x800B453C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800B4540: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x800B4544: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800B4548: sh          $t9, -0x1A($v1)
    MEM_H(-0X1A, ctx->r3) = ctx->r25;
    // 0x800B454C: lbu         $t1, 0x6C($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X6C);
    // 0x800B4550: nop

    // 0x800B4554: sb          $t1, -0x18($v1)
    MEM_B(-0X18, ctx->r3) = ctx->r9;
    // 0x800B4558: lbu         $t2, 0x6D($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X6D);
    // 0x800B455C: nop

    // 0x800B4560: sb          $t2, -0x17($v1)
    MEM_B(-0X17, ctx->r3) = ctx->r10;
    // 0x800B4564: lbu         $t0, 0x6E($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X6E);
    // 0x800B4568: nop

    // 0x800B456C: sb          $t0, -0x16($v1)
    MEM_B(-0X16, ctx->r3) = ctx->r8;
    // 0x800B4570: lh          $t3, 0x5C($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X5C);
    // 0x800B4574: nop

    // 0x800B4578: sra         $t4, $t3, 8
    ctx->r12 = S32(SIGNED(ctx->r11) >> 8);
    // 0x800B457C: sb          $t4, -0x15($v1)
    MEM_B(-0X15, ctx->r3) = ctx->r12;
    // 0x800B4580: lwc1        $f8, 0x7C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800B4584: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800B4588: nop

    // 0x800B458C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800B4590: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800B4594: nop

    // 0x800B4598: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800B459C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B45A0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B45A4: nop

    // 0x800B45A8: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B45AC: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x800B45B0: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800B45B4: sh          $t6, -0x14($v1)
    MEM_H(-0X14, ctx->r3) = ctx->r14;
    // 0x800B45B8: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800B45BC: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800B45C0: nop

    // 0x800B45C4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B45C8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800B45CC: nop

    // 0x800B45D0: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800B45D4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B45D8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B45DC: nop

    // 0x800B45E0: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800B45E4: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x800B45E8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800B45EC: sh          $t8, -0x12($v1)
    MEM_H(-0X12, ctx->r3) = ctx->r24;
    // 0x800B45F0: lwc1        $f16, 0x84($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800B45F4: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800B45F8: nop

    // 0x800B45FC: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B4600: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800B4604: nop

    // 0x800B4608: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800B460C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B4610: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B4614: nop

    // 0x800B4618: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800B461C: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x800B4620: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800B4624: sh          $t1, -0x10($v1)
    MEM_H(-0X10, ctx->r3) = ctx->r9;
    // 0x800B4628: lbu         $t2, 0x6C($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X6C);
    // 0x800B462C: nop

    // 0x800B4630: sb          $t2, -0xE($v1)
    MEM_B(-0XE, ctx->r3) = ctx->r10;
    // 0x800B4634: lbu         $t0, 0x6D($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X6D);
    // 0x800B4638: nop

    // 0x800B463C: sb          $t0, -0xD($v1)
    MEM_B(-0XD, ctx->r3) = ctx->r8;
    // 0x800B4640: lbu         $t3, 0x6E($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X6E);
    // 0x800B4644: nop

    // 0x800B4648: sb          $t3, -0xC($v1)
    MEM_B(-0XC, ctx->r3) = ctx->r11;
    // 0x800B464C: lh          $t4, 0x5C($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X5C);
    // 0x800B4650: nop

    // 0x800B4654: sra         $t5, $t4, 8
    ctx->r13 = S32(SIGNED(ctx->r12) >> 8);
    // 0x800B4658: sb          $t5, -0xB($v1)
    MEM_B(-0XB, ctx->r3) = ctx->r13;
    // 0x800B465C: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800B4660: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800B4664: nop

    // 0x800B4668: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800B466C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800B4670: nop

    // 0x800B4674: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800B4678: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B467C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B4680: nop

    // 0x800B4684: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B4688: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x800B468C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800B4690: sh          $t7, -0xA($v1)
    MEM_H(-0XA, ctx->r3) = ctx->r15;
    // 0x800B4694: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800B4698: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800B469C: nop

    // 0x800B46A0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800B46A4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800B46A8: nop

    // 0x800B46AC: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800B46B0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B46B4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B46B8: nop

    // 0x800B46BC: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800B46C0: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800B46C4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800B46C8: sh          $t9, -0x8($v1)
    MEM_H(-0X8, ctx->r3) = ctx->r25;
    // 0x800B46CC: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800B46D0: lwc1        $f18, 0x78($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800B46D4: nop

    // 0x800B46D8: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800B46DC: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800B46E0: nop

    // 0x800B46E4: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800B46E8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B46EC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B46F0: nop

    // 0x800B46F4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800B46F8: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x800B46FC: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800B4700: sh          $t2, -0x6($v1)
    MEM_H(-0X6, ctx->r3) = ctx->r10;
    // 0x800B4704: lbu         $t0, 0x6C($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X6C);
    // 0x800B4708: nop

    // 0x800B470C: sb          $t0, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r8;
    // 0x800B4710: lbu         $t3, 0x6D($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X6D);
    // 0x800B4714: nop

    // 0x800B4718: sb          $t3, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r11;
    // 0x800B471C: lbu         $t4, 0x6E($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X6E);
    // 0x800B4720: nop

    // 0x800B4724: sb          $t4, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r12;
    // 0x800B4728: lh          $t5, 0x5C($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X5C);
    // 0x800B472C: nop

    // 0x800B4730: sra         $t6, $t5, 8
    ctx->r14 = S32(SIGNED(ctx->r13) >> 8);
    // 0x800B4734: sb          $t6, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r14;
    // 0x800B4738: lwc1        $f10, 0x7C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800B473C: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800B4740: nop

    // 0x800B4744: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800B4748: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800B474C: nop

    // 0x800B4750: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800B4754: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B4758: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B475C: nop

    // 0x800B4760: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B4764: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x800B4768: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800B476C: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
    // 0x800B4770: lwc1        $f6, 0x80($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800B4774: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800B4778: nop

    // 0x800B477C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800B4780: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800B4784: nop

    // 0x800B4788: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800B478C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B4790: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B4794: nop

    // 0x800B4798: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800B479C: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x800B47A0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800B47A4: sh          $t1, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r9;
    // 0x800B47A8: lwc1        $f18, 0x84($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800B47AC: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800B47B0: nop

    // 0x800B47B4: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800B47B8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800B47BC: nop

    // 0x800B47C0: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800B47C4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B47C8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B47CC: nop

    // 0x800B47D0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800B47D4: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x800B47D8: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800B47DC: sh          $t0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r8;
    // 0x800B47E0: lbu         $t3, 0x6C($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X6C);
    // 0x800B47E4: nop

    // 0x800B47E8: sb          $t3, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r11;
    // 0x800B47EC: lbu         $t4, 0x6D($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X6D);
    // 0x800B47F0: nop

    // 0x800B47F4: sb          $t4, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r12;
    // 0x800B47F8: lbu         $t5, 0x6E($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X6E);
    // 0x800B47FC: nop

    // 0x800B4800: sb          $t5, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r13;
    // 0x800B4804: lh          $t6, 0x5C($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X5C);
    // 0x800B4808: nop

    // 0x800B480C: sra         $t7, $t6, 8
    ctx->r15 = S32(SIGNED(ctx->r14) >> 8);
    // 0x800B4810: sb          $t7, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r15;
    // 0x800B4814: lbu         $t9, 0x75($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X75);
    // 0x800B4818: lw          $t8, 0x8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X8);
    // 0x800B481C: sll         $t1, $t9, 3
    ctx->r9 = S32(ctx->r25 << 3);
    // 0x800B4820: multu       $t1, $s4
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B4824: mflo        $t2
    ctx->r10 = lo;
    // 0x800B4828: addu        $a0, $t8, $t2
    ctx->r4 = ADD32(ctx->r24, ctx->r10);
    // 0x800B482C: beq         $s3, $zero, L_800B4854
    if (ctx->r19 == 0) {
        // 0x800B4830: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_800B4854;
    }
    // 0x800B4830: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800B4834: lbu         $t3, 0x75($s5)
    ctx->r11 = MEM_BU(ctx->r21, 0X75);
    // 0x800B4838: lw          $t0, 0x8($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X8);
    // 0x800B483C: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x800B4840: multu       $t4, $s4
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B4844: mflo        $t5
    ctx->r13 = lo;
    // 0x800B4848: addu        $v0, $t0, $t5
    ctx->r2 = ADD32(ctx->r8, ctx->r13);
    // 0x800B484C: b           L_800B4858
    // 0x800B4850: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
        goto L_800B4858;
    // 0x800B4850: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
L_800B4854:
    // 0x800B4854: addiu       $v0, $a0, 0x28
    ctx->r2 = ADD32(ctx->r4, 0X28);
L_800B4858:
    // 0x800B4858: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x800B485C: addiu       $s2, $s2, -0x4
    ctx->r18 = ADD32(ctx->r18, -0X4);
    // 0x800B4860: sh          $t6, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r14;
    // 0x800B4864: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x800B4868: addiu       $v1, $v1, 0x1E
    ctx->r3 = ADD32(ctx->r3, 0X1E);
    // 0x800B486C: sh          $t7, -0x1C($v1)
    MEM_H(-0X1C, ctx->r3) = ctx->r15;
    // 0x800B4870: lh          $t9, 0x4($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X4);
    // 0x800B4874: addiu       $v0, $v0, 0x1E
    ctx->r2 = ADD32(ctx->r2, 0X1E);
    // 0x800B4878: sh          $t9, -0x1A($v1)
    MEM_H(-0X1A, ctx->r3) = ctx->r25;
    // 0x800B487C: lbu         $t1, -0x18($v0)
    ctx->r9 = MEM_BU(ctx->r2, -0X18);
    // 0x800B4880: or          $s5, $s0, $zero
    ctx->r21 = ctx->r16 | 0;
    // 0x800B4884: sb          $t1, -0x18($v1)
    MEM_B(-0X18, ctx->r3) = ctx->r9;
    // 0x800B4888: lbu         $t8, -0x17($v0)
    ctx->r24 = MEM_BU(ctx->r2, -0X17);
    // 0x800B488C: or          $s3, $s1, $zero
    ctx->r19 = ctx->r17 | 0;
    // 0x800B4890: sb          $t8, -0x17($v1)
    MEM_B(-0X17, ctx->r3) = ctx->r24;
    // 0x800B4894: lbu         $t2, -0x16($v0)
    ctx->r10 = MEM_BU(ctx->r2, -0X16);
    // 0x800B4898: nop

    // 0x800B489C: sb          $t2, -0x16($v1)
    MEM_B(-0X16, ctx->r3) = ctx->r10;
    // 0x800B48A0: lbu         $t3, -0x15($v0)
    ctx->r11 = MEM_BU(ctx->r2, -0X15);
    // 0x800B48A4: nop

    // 0x800B48A8: sb          $t3, -0x15($v1)
    MEM_B(-0X15, ctx->r3) = ctx->r11;
    // 0x800B48AC: lh          $t4, -0x14($v0)
    ctx->r12 = MEM_H(ctx->r2, -0X14);
    // 0x800B48B0: nop

    // 0x800B48B4: sh          $t4, -0x14($v1)
    MEM_H(-0X14, ctx->r3) = ctx->r12;
    // 0x800B48B8: lh          $t0, -0x12($v0)
    ctx->r8 = MEM_H(ctx->r2, -0X12);
    // 0x800B48BC: nop

    // 0x800B48C0: sh          $t0, -0x12($v1)
    MEM_H(-0X12, ctx->r3) = ctx->r8;
    // 0x800B48C4: lh          $t5, -0x10($v0)
    ctx->r13 = MEM_H(ctx->r2, -0X10);
    // 0x800B48C8: nop

    // 0x800B48CC: sh          $t5, -0x10($v1)
    MEM_H(-0X10, ctx->r3) = ctx->r13;
    // 0x800B48D0: lbu         $t6, -0xE($v0)
    ctx->r14 = MEM_BU(ctx->r2, -0XE);
    // 0x800B48D4: nop

    // 0x800B48D8: sb          $t6, -0xE($v1)
    MEM_B(-0XE, ctx->r3) = ctx->r14;
    // 0x800B48DC: lbu         $t7, -0xD($v0)
    ctx->r15 = MEM_BU(ctx->r2, -0XD);
    // 0x800B48E0: nop

    // 0x800B48E4: sb          $t7, -0xD($v1)
    MEM_B(-0XD, ctx->r3) = ctx->r15;
    // 0x800B48E8: lbu         $t9, -0xC($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0XC);
    // 0x800B48EC: nop

    // 0x800B48F0: sb          $t9, -0xC($v1)
    MEM_B(-0XC, ctx->r3) = ctx->r25;
    // 0x800B48F4: lbu         $t1, -0xB($v0)
    ctx->r9 = MEM_BU(ctx->r2, -0XB);
    // 0x800B48F8: nop

    // 0x800B48FC: sb          $t1, -0xB($v1)
    MEM_B(-0XB, ctx->r3) = ctx->r9;
    // 0x800B4900: lh          $t8, -0xA($v0)
    ctx->r24 = MEM_H(ctx->r2, -0XA);
    // 0x800B4904: nop

    // 0x800B4908: sh          $t8, -0xA($v1)
    MEM_H(-0XA, ctx->r3) = ctx->r24;
    // 0x800B490C: lh          $t2, -0x8($v0)
    ctx->r10 = MEM_H(ctx->r2, -0X8);
    // 0x800B4910: nop

    // 0x800B4914: sh          $t2, -0x8($v1)
    MEM_H(-0X8, ctx->r3) = ctx->r10;
    // 0x800B4918: lh          $t3, -0x6($v0)
    ctx->r11 = MEM_H(ctx->r2, -0X6);
    // 0x800B491C: nop

    // 0x800B4920: sh          $t3, -0x6($v1)
    MEM_H(-0X6, ctx->r3) = ctx->r11;
    // 0x800B4924: lbu         $t4, -0x4($v0)
    ctx->r12 = MEM_BU(ctx->r2, -0X4);
    // 0x800B4928: nop

    // 0x800B492C: sb          $t4, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r12;
    // 0x800B4930: lbu         $t0, -0x3($v0)
    ctx->r8 = MEM_BU(ctx->r2, -0X3);
    // 0x800B4934: nop

    // 0x800B4938: sb          $t0, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r8;
    // 0x800B493C: lbu         $t5, -0x2($v0)
    ctx->r13 = MEM_BU(ctx->r2, -0X2);
    // 0x800B4940: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x800B4944: sb          $t5, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r13;
    // 0x800B4948: lbu         $t6, -0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, -0X1);
    // 0x800B494C: nop

    // 0x800B4950: sb          $t6, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r14;
    // 0x800B4954: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x800B4958: nop

    // 0x800B495C: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
    // 0x800B4960: lh          $t9, 0x2($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X2);
    // 0x800B4964: nop

    // 0x800B4968: sh          $t9, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r25;
    // 0x800B496C: lh          $t1, 0x4($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X4);
    // 0x800B4970: nop

    // 0x800B4974: sh          $t1, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r9;
    // 0x800B4978: lbu         $t8, 0x6($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X6);
    // 0x800B497C: nop

    // 0x800B4980: sb          $t8, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r24;
    // 0x800B4984: lbu         $t2, 0x7($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X7);
    // 0x800B4988: nop

    // 0x800B498C: sb          $t2, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r10;
    // 0x800B4990: lbu         $t3, 0x8($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X8);
    // 0x800B4994: nop

    // 0x800B4998: sb          $t3, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r11;
    // 0x800B499C: lbu         $t4, 0x9($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X9);
    // 0x800B49A0: nop

    // 0x800B49A4: sb          $t4, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r12;
    // 0x800B49A8: bgez        $s2, L_800B4438
    if (SIGNED(ctx->r18) >= 0) {
        // 0x800B49AC: sb          $t0, 0x77($s0)
        MEM_B(0X77, ctx->r16) = ctx->r8;
            goto L_800B4438;
    }
    // 0x800B49AC: sb          $t0, 0x77($s0)
    MEM_B(0X77, ctx->r16) = ctx->r8;
L_800B49B0:
    // 0x800B49B0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_800B49B4:
    // 0x800B49B4: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800B49B8: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800B49BC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800B49C0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800B49C4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800B49C8: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800B49CC: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800B49D0: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800B49D4: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800B49D8: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800B49DC: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800B49E0: jr          $ra
    // 0x800B49E4: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x800B49E4: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void get_particle_asset_table(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B49E8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B49EC: lw          $v1, 0x3278($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3278);
    // 0x800B49F0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800B49F4: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800B49F8: beq         $at, $zero, L_800B4A18
    if (ctx->r1 == 0) {
        // 0x800B49FC: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_800B4A18;
    }
    // 0x800B49FC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800B4A00: lw          $t6, 0x3280($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3280);
    // 0x800B4A04: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800B4A08: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800B4A0C: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x800B4A10: jr          $ra
    // 0x800B4A14: nop

    return;
    // 0x800B4A14: nop

L_800B4A18:
    // 0x800B4A18: lw          $t9, 0x3280($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3280);
    // 0x800B4A1C: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x800B4A20: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800B4A24: lw          $v0, -0x4($t1)
    ctx->r2 = MEM_W(ctx->r9, -0X4);
    // 0x800B4A28: nop

    // 0x800B4A2C: jr          $ra
    // 0x800B4A30: nop

    return;
    // 0x800B4A30: nop

;}
RECOMP_FUNC void get_next_particle_table(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4A34: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800B4A38: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800B4A3C: addiu       $v1, $t6, 0x1
    ctx->r3 = ADD32(ctx->r14, 0X1);
    // 0x800B4A40: addiu       $a1, $a1, 0x3278
    ctx->r5 = ADD32(ctx->r5, 0X3278);
    // 0x800B4A44: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x800B4A48: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800B4A4C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800B4A50: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B4A54: bne         $at, $zero, L_800B4A74
    if (ctx->r1 != 0) {
        // 0x800B4A58: subu        $t8, $v1, $v0
        ctx->r24 = SUB32(ctx->r3, ctx->r2);
            goto L_800B4A74;
    }
    // 0x800B4A58: subu        $t8, $v1, $v0
    ctx->r24 = SUB32(ctx->r3, ctx->r2);
L_800B4A5C:
    // 0x800B4A5C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800B4A60: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800B4A64: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x800B4A68: slt         $at, $t8, $v0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B4A6C: beq         $at, $zero, L_800B4A5C
    if (ctx->r1 == 0) {
        // 0x800B4A70: subu        $t8, $v1, $v0
        ctx->r24 = SUB32(ctx->r3, ctx->r2);
            goto L_800B4A5C;
    }
    // 0x800B4A70: subu        $t8, $v1, $v0
    ctx->r24 = SUB32(ctx->r3, ctx->r2);
L_800B4A74:
    // 0x800B4A74: lw          $t9, 0x3280($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3280);
    // 0x800B4A78: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x800B4A7C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800B4A80: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800B4A84: jr          $ra
    // 0x800B4A88: nop

    return;
    // 0x800B4A88: nop

;}
RECOMP_FUNC void get_previous_particle_table(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4A8C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800B4A90: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800B4A94: addiu       $v1, $t6, -0x1
    ctx->r3 = ADD32(ctx->r14, -0X1);
    // 0x800B4A98: bgez        $v1, L_800B4AC0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800B4A9C: sw          $v1, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r3;
            goto L_800B4AC0;
    }
    // 0x800B4A9C: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x800B4AA0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B4AA4: addiu       $v0, $v0, 0x3278
    ctx->r2 = ADD32(ctx->r2, 0X3278);
L_800B4AA8:
    // 0x800B4AA8: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800B4AAC: nop

    // 0x800B4AB0: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x800B4AB4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800B4AB8: bltz        $t9, L_800B4AA8
    if (SIGNED(ctx->r25) < 0) {
        // 0x800B4ABC: or          $v1, $t9, $zero
        ctx->r3 = ctx->r25 | 0;
            goto L_800B4AA8;
    }
    // 0x800B4ABC: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
L_800B4AC0:
    // 0x800B4AC0: lw          $t0, 0x3280($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X3280);
    // 0x800B4AC4: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x800B4AC8: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800B4ACC: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x800B4AD0: jr          $ra
    // 0x800B4AD4: nop

    return;
    // 0x800B4AD4: nop

;}
