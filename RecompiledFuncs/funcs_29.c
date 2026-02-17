#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_800A4C34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A517C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800A5180: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800A5184: jr          $ra
    // 0x800A5188: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    return;
    // 0x800A5188: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
;}
RECOMP_FUNC void hud_race_position(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A518C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800A5190: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A5194: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800A5198: lb          $t6, 0x1D8($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X1D8);
    // 0x800A519C: nop

    // 0x800A51A0: bne         $t6, $zero, L_800A548C
    if (ctx->r14 != 0) {
        // 0x800A51A4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A548C;
    }
    // 0x800A51A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A51A8: lh          $v1, 0x1AE($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X1AE);
    // 0x800A51AC: jal         0x8001139C
    // 0x800A51B0: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    get_race_countdown(rdram, ctx);
        goto after_0;
    // 0x800A51B0: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_0:
    // 0x800A51B4: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x800A51B8: beq         $v0, $zero, L_800A5228
    if (ctx->r2 == 0) {
        // 0x800A51BC: nop
    
            goto L_800A5228;
    }
    // 0x800A51BC: nop

    // 0x800A51C0: jal         0x8006BFD8
    // 0x800A51C4: nop

    level_type(rdram, ctx);
        goto after_1;
    // 0x800A51C4: nop

    after_1:
    // 0x800A51C8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800A51CC: beq         $v0, $at, L_800A51E4
    if (ctx->r2 == ctx->r1) {
        // 0x800A51D0: nop
    
            goto L_800A51E4;
    }
    // 0x800A51D0: nop

    // 0x800A51D4: jal         0x80023450
    // 0x800A51D8: nop

    is_taj_challenge(rdram, ctx);
        goto after_2;
    // 0x800A51D8: nop

    after_2:
    // 0x800A51DC: beq         $v0, $zero, L_800A51EC
    if (ctx->r2 == 0) {
        // 0x800A51E0: nop
    
            goto L_800A51EC;
    }
    // 0x800A51E0: nop

L_800A51E4:
    // 0x800A51E4: b           L_800A5228
    // 0x800A51E8: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_800A5228;
    // 0x800A51E8: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_800A51EC:
    // 0x800A51EC: jal         0x8006ECD0
    // 0x800A51F0: nop

    get_settings(rdram, ctx);
        goto after_3;
    // 0x800A51F0: nop

    after_3:
    // 0x800A51F4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A51F8: lw          $t7, 0x72D0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X72D0);
    // 0x800A51FC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A5200: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800A5204: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800A5208: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800A520C: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A5210: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x800A5214: lb          $v1, 0x5A($t9)
    ctx->r3 = MEM_B(ctx->r25, 0X5A);
    // 0x800A5218: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800A521C: nop

    // 0x800A5220: sh          $v1, 0x18($t1)
    MEM_H(0X18, ctx->r9) = ctx->r3;
    // 0x800A5224: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800A5228:
    // 0x800A5228: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800A522C: lw          $t2, 0x72CC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X72CC);
    // 0x800A5230: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A5234: slti        $at, $t2, 0x2
    ctx->r1 = SIGNED(ctx->r10) < 0X2 ? 1 : 0;
    // 0x800A5238: beq         $at, $zero, L_800A5298
    if (ctx->r1 == 0) {
        // 0x800A523C: addiu       $t0, $t0, 0x729C
        ctx->r8 = ADD32(ctx->r8, 0X729C);
            goto L_800A5298;
    }
    // 0x800A523C: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A5240: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x800A5244: beq         $at, $zero, L_800A525C
    if (ctx->r1 == 0) {
        // 0x800A5248: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800A525C;
    }
    // 0x800A5248: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A524C: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800A5250: addiu       $t3, $v1, -0x1
    ctx->r11 = ADD32(ctx->r3, -0X1);
    // 0x800A5254: b           L_800A5268
    // 0x800A5258: sh          $t3, 0x38($t4)
    MEM_H(0X38, ctx->r12) = ctx->r11;
        goto L_800A5268;
    // 0x800A5258: sh          $t3, 0x38($t4)
    MEM_H(0X38, ctx->r12) = ctx->r11;
L_800A525C:
    // 0x800A525C: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800A5260: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x800A5264: sh          $t5, 0x38($t6)
    MEM_H(0X38, ctx->r14) = ctx->r13;
L_800A5268:
    // 0x800A5268: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A526C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A5270: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A5274: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A5278: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A527C: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A5280: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x800A5284: jal         0x800AAB5C
    // 0x800A5288: addiu       $a3, $a3, 0x20
    ctx->r7 = ADD32(ctx->r7, 0X20);
    hud_element_render(rdram, ctx);
        goto after_4;
    // 0x800A5288: addiu       $a3, $a3, 0x20
    ctx->r7 = ADD32(ctx->r7, 0X20);
    after_4:
    // 0x800A528C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A5290: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x800A5294: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
L_800A5298:
    // 0x800A5298: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800A529C: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x800A52A0: lb          $t8, 0x1B($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X1B);
    // 0x800A52A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A52A8: addiu       $t9, $t8, 0x81
    ctx->r25 = ADD32(ctx->r24, 0X81);
    // 0x800A52AC: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800A52B0: addiu       $t4, $v1, -0x1
    ctx->r12 = ADD32(ctx->r3, -0X1);
    // 0x800A52B4: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A52B8: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x800A52BC: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800A52C0: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800A52C4: nop

    // 0x800A52C8: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800A52CC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A52D0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A52D4: nop

    // 0x800A52D8: cvt.w.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800A52DC: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x800A52E0: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800A52E4: sll         $t2, $a0, 16
    ctx->r10 = S32(ctx->r4 << 16);
    // 0x800A52E8: jal         0x80070A04
    // 0x800A52EC: sra         $a0, $t2, 16
    ctx->r4 = S32(SIGNED(ctx->r10) >> 16);
    sins_f(rdram, ctx);
        goto after_5;
    // 0x800A52EC: sra         $a0, $t2, 16
    ctx->r4 = S32(SIGNED(ctx->r10) >> 16);
    after_5:
    // 0x800A52F0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A52F4: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A52F8: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A52FC: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x800A5300: lb          $t5, 0x1C($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X1C);
    // 0x800A5304: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A5308: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x800A530C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800A5310: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A5314: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800A5318: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800A531C: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800A5320: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x800A5324: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800A5328: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800A532C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800A5330: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800A5334: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x800A5338: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A533C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A5340: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A5344: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A5348: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A534C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800A5350: add.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f18.d + ctx->f16.d;
    // 0x800A5354: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A5358: add.d       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f6.d + ctx->f4.d;
    // 0x800A535C: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A5360: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x800A5364: swc1        $f10, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f10.u32l;
    // 0x800A5368: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A536C: nop

    // 0x800A5370: lwc1        $f2, 0xC($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800A5374: nop

    // 0x800A5378: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    // 0x800A537C: lwc1        $f16, 0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800A5380: nop

    // 0x800A5384: mul.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800A5388: sub.s       $f4, $f2, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x800A538C: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x800A5390: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A5394: jal         0x800AAB5C
    // 0x800A5398: nop

    hud_element_render(rdram, ctx);
        goto after_6;
    // 0x800A5398: nop

    after_6:
    // 0x800A539C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A53A0: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A53A4: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800A53A8: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800A53AC: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    // 0x800A53B0: swc1        $f8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f8.u32l;
    // 0x800A53B4: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A53B8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x800A53BC: lb          $t7, 0x1A($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X1A);
    // 0x800A53C0: sll         $t8, $a0, 4
    ctx->r24 = S32(ctx->r4 << 4);
    // 0x800A53C4: beq         $t7, $zero, L_800A53FC
    if (ctx->r15 == 0) {
        // 0x800A53C8: nop
    
            goto L_800A53FC;
    }
    // 0x800A53C8: nop

    // 0x800A53CC: lb          $v1, 0x1B($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X1B);
    // 0x800A53D0: subu        $t9, $a1, $t8
    ctx->r25 = SUB32(ctx->r5, ctx->r24);
    // 0x800A53D4: slt         $at, $v1, $t9
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800A53D8: beq         $at, $zero, L_800A53F0
    if (ctx->r1 == 0) {
        // 0x800A53DC: addu        $t1, $v1, $t8
        ctx->r9 = ADD32(ctx->r3, ctx->r24);
            goto L_800A53F0;
    }
    // 0x800A53DC: addu        $t1, $v1, $t8
    ctx->r9 = ADD32(ctx->r3, ctx->r24);
    // 0x800A53E0: sb          $t1, 0x1B($v0)
    MEM_B(0X1B, ctx->r2) = ctx->r9;
    // 0x800A53E4: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A53E8: b           L_800A5400
    // 0x800A53EC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
        goto L_800A5400;
    // 0x800A53EC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_800A53F0:
    // 0x800A53F0: sb          $a1, 0x1B($v0)
    MEM_B(0X1B, ctx->r2) = ctx->r5;
    // 0x800A53F4: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A53F8: nop

L_800A53FC:
    // 0x800A53FC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_800A5400:
    // 0x800A5400: lh          $t2, 0x18($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X18);
    // 0x800A5404: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    // 0x800A5408: beq         $a0, $t2, L_800A5458
    if (ctx->r4 == ctx->r10) {
        // 0x800A540C: nop
    
            goto L_800A5458;
    }
    // 0x800A540C: nop

    // 0x800A5410: lb          $t3, 0x1A($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X1A);
    // 0x800A5414: addiu       $t5, $zero, -0x7F
    ctx->r13 = ADD32(0, -0X7F);
    // 0x800A5418: beq         $t3, $zero, L_800A5440
    if (ctx->r11 == 0) {
        // 0x800A541C: nop
    
            goto L_800A5440;
    }
    // 0x800A541C: nop

    // 0x800A5420: lb          $v1, 0x1B($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X1B);
    // 0x800A5424: nop

    // 0x800A5428: blez        $v1, L_800A5440
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800A542C: negu        $t4, $v1
        ctx->r12 = SUB32(0, ctx->r3);
            goto L_800A5440;
    }
    // 0x800A542C: negu        $t4, $v1
    ctx->r12 = SUB32(0, ctx->r3);
    // 0x800A5430: sb          $t4, 0x1B($v0)
    MEM_B(0X1B, ctx->r2) = ctx->r12;
    // 0x800A5434: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A5438: b           L_800A545C
    // 0x800A543C: sh          $a0, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r4;
        goto L_800A545C;
    // 0x800A543C: sh          $a0, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r4;
L_800A5440:
    // 0x800A5440: sb          $t5, 0x1B($v0)
    MEM_B(0X1B, ctx->r2) = ctx->r13;
    // 0x800A5444: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800A5448: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800A544C: sb          $t6, 0x1A($t7)
    MEM_B(0X1A, ctx->r15) = ctx->r14;
    // 0x800A5450: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A5454: nop

L_800A5458:
    // 0x800A5458: sh          $a0, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r4;
L_800A545C:
    // 0x800A545C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A5460: nop

    // 0x800A5464: lb          $t8, 0x1A($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X1A);
    // 0x800A5468: nop

    // 0x800A546C: beq         $t8, $zero, L_800A548C
    if (ctx->r24 == 0) {
        // 0x800A5470: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A548C;
    }
    // 0x800A5470: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A5474: lb          $t9, 0x1B($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X1B);
    // 0x800A5478: nop

    // 0x800A547C: bne         $a1, $t9, L_800A548C
    if (ctx->r5 != ctx->r25) {
        // 0x800A5480: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A548C;
    }
    // 0x800A5480: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A5484: sb          $zero, 0x1A($v0)
    MEM_B(0X1A, ctx->r2) = 0;
    // 0x800A5488: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A548C:
    // 0x800A548C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800A5490: jr          $ra
    // 0x800A5494: nop

    return;
    // 0x800A5494: nop

;}
RECOMP_FUNC void hud_lap_count(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5498: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A549C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A54A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A54A4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800A54A8: lb          $t7, 0x1D8($a0)
    ctx->r15 = MEM_B(ctx->r4, 0X1D8);
    // 0x800A54AC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A54B0: bne         $t7, $zero, L_800A56D8
    if (ctx->r15 != 0) {
        // 0x800A54B4: nop
    
            goto L_800A56D8;
    }
    // 0x800A54B4: nop

    // 0x800A54B8: lw          $v0, 0x72CC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X72CC);
    // 0x800A54BC: nop

    // 0x800A54C0: blez        $v0, L_800A54F0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800A54C4: nop
    
            goto L_800A54F0;
    }
    // 0x800A54C4: nop

    // 0x800A54C8: lb          $v1, 0x193($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X193);
    // 0x800A54CC: nop

    // 0x800A54D0: blez        $v1, L_800A54F0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800A54D4: sll         $t8, $v1, 2
        ctx->r24 = S32(ctx->r3 << 2);
            goto L_800A54F0;
    }
    // 0x800A54D4: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x800A54D8: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x800A54DC: lw          $t3, 0x128($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X128);
    // 0x800A54E0: nop

    // 0x800A54E4: slti        $at, $t3, 0xB4
    ctx->r1 = SIGNED(ctx->r11) < 0XB4 ? 1 : 0;
    // 0x800A54E8: bne         $at, $zero, L_800A56D8
    if (ctx->r1 != 0) {
        // 0x800A54EC: nop
    
            goto L_800A56D8;
    }
    // 0x800A54EC: nop

L_800A54F0:
    // 0x800A54F0: blez        $v0, L_800A5520
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800A54F4: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_800A5520;
    }
    // 0x800A54F4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A54F8: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x800A54FC: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x800A5500: lh          $t7, 0x0($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X0);
    // 0x800A5504: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800A5508: addu        $t6, $t4, $t7
    ctx->r14 = ADD32(ctx->r12, ctx->r15);
    // 0x800A550C: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x800A5510: lbu         $t8, 0x2D14($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X2D14);
    // 0x800A5514: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A5518: bne         $t8, $at, L_800A56D8
    if (ctx->r24 != ctx->r1) {
        // 0x800A551C: nop
    
            goto L_800A56D8;
    }
    // 0x800A551C: nop

L_800A5520:
    // 0x800A5520: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x800A5524: lw          $t9, 0x7320($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7320);
    // 0x800A5528: lb          $t4, 0x194($t5)
    ctx->r12 = MEM_B(ctx->r13, 0X194);
    // 0x800A552C: lb          $t3, 0x4B($t9)
    ctx->r11 = MEM_B(ctx->r25, 0X4B);
    // 0x800A5530: addiu       $t7, $t4, 0x1
    ctx->r15 = ADD32(ctx->r12, 0X1);
    // 0x800A5534: bne         $t3, $t7, L_800A55DC
    if (ctx->r11 != ctx->r15) {
        // 0x800A5538: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_800A55DC;
    }
    // 0x800A5538: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800A553C: beq         $at, $zero, L_800A55DC
    if (ctx->r1 == 0) {
        // 0x800A5540: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_800A55DC;
    }
    // 0x800A5540: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A5544: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A5548: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A554C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800A5550: lb          $t6, 0x21A($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X21A);
    // 0x800A5554: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A5558: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800A555C: sb          $t9, 0x21A($v0)
    MEM_B(0X21A, ctx->r2) = ctx->r25;
    // 0x800A5560: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A5564: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A5568: lb          $t5, 0x21A($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X21A);
    // 0x800A556C: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A5570: slti        $at, $t5, 0x7
    ctx->r1 = SIGNED(ctx->r13) < 0X7 ? 1 : 0;
    // 0x800A5574: bne         $at, $zero, L_800A55CC
    if (ctx->r1 != 0) {
        // 0x800A5578: addiu       $a0, $a0, 0x72BC
        ctx->r4 = ADD32(ctx->r4, 0X72BC);
            goto L_800A55CC;
    }
    // 0x800A5578: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A557C: lh          $t4, 0x218($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X218);
    // 0x800A5580: nop

    // 0x800A5584: addiu       $t3, $t4, 0x1
    ctx->r11 = ADD32(ctx->r12, 0X1);
    // 0x800A5588: sh          $t3, 0x218($v0)
    MEM_H(0X218, ctx->r2) = ctx->r11;
    // 0x800A558C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A5590: nop

    // 0x800A5594: lb          $t7, 0x21A($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X21A);
    // 0x800A5598: nop

    // 0x800A559C: addiu       $t6, $t7, -0x6
    ctx->r14 = ADD32(ctx->r15, -0X6);
    // 0x800A55A0: sb          $t6, 0x21A($v0)
    MEM_B(0X21A, ctx->r2) = ctx->r14;
    // 0x800A55A4: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A55A8: nop

    // 0x800A55AC: lh          $t8, 0x218($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X218);
    // 0x800A55B0: nop

    // 0x800A55B4: slti        $at, $t8, 0x5
    ctx->r1 = SIGNED(ctx->r24) < 0X5 ? 1 : 0;
    // 0x800A55B8: bne         $at, $zero, L_800A55CC
    if (ctx->r1 != 0) {
        // 0x800A55BC: nop
    
            goto L_800A55CC;
    }
    // 0x800A55BC: nop

    // 0x800A55C0: sh          $zero, 0x218($v0)
    MEM_H(0X218, ctx->r2) = 0;
    // 0x800A55C4: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A55C8: nop

L_800A55CC:
    // 0x800A55CC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A55D0: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A55D4: jal         0x800AAB5C
    // 0x800A55D8: addiu       $a3, $v0, 0x200
    ctx->r7 = ADD32(ctx->r2, 0X200);
    hud_element_render(rdram, ctx);
        goto after_0;
    // 0x800A55D8: addiu       $a3, $v0, 0x200
    ctx->r7 = ADD32(ctx->r2, 0X200);
    after_0:
L_800A55DC:
    // 0x800A55DC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A55E0: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A55E4: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A55E8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A55EC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A55F0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A55F4: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A55F8: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A55FC: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A5600: jal         0x800AAB5C
    // 0x800A5604: addiu       $a3, $a3, 0x60
    ctx->r7 = ADD32(ctx->r7, 0X60);
    hud_element_render(rdram, ctx);
        goto after_1;
    // 0x800A5604: addiu       $a3, $a3, 0x60
    ctx->r7 = ADD32(ctx->r7, 0X60);
    after_1:
    // 0x800A5608: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800A560C: addiu       $t2, $t2, 0x7320
    ctx->r10 = ADD32(ctx->r10, 0X7320);
    // 0x800A5610: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x800A5614: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800A5618: lb          $v0, 0x4B($t9)
    ctx->r2 = MEM_B(ctx->r25, 0X4B);
    // 0x800A561C: lb          $v1, 0x194($t1)
    ctx->r3 = MEM_B(ctx->r9, 0X194);
    // 0x800A5620: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    // 0x800A5624: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A5628: slt         $at, $v1, $t5
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800A562C: bne         $at, $zero, L_800A5640
    if (ctx->r1 != 0) {
        // 0x800A5630: addiu       $t0, $t0, 0x729C
        ctx->r8 = ADD32(ctx->r8, 0X729C);
            goto L_800A5640;
    }
    // 0x800A5630: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A5634: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800A5638: b           L_800A564C
    // 0x800A563C: sh          $v0, 0x98($t4)
    MEM_H(0X98, ctx->r12) = ctx->r2;
        goto L_800A564C;
    // 0x800A563C: sh          $v0, 0x98($t4)
    MEM_H(0X98, ctx->r12) = ctx->r2;
L_800A5640:
    // 0x800A5640: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800A5644: addiu       $t3, $v1, 0x1
    ctx->r11 = ADD32(ctx->r3, 0X1);
    // 0x800A5648: sh          $t3, 0x98($t7)
    MEM_H(0X98, ctx->r15) = ctx->r11;
L_800A564C:
    // 0x800A564C: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x800A5650: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800A5654: lb          $t8, 0x4B($t6)
    ctx->r24 = MEM_B(ctx->r14, 0X4B);
    // 0x800A5658: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A565C: sh          $t8, 0xD8($t9)
    MEM_H(0XD8, ctx->r25) = ctx->r24;
    // 0x800A5660: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A5664: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A5668: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A566C: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A5670: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A5674: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A5678: jal         0x800AAB5C
    // 0x800A567C: addiu       $a3, $a3, 0x80
    ctx->r7 = ADD32(ctx->r7, 0X80);
    hud_element_render(rdram, ctx);
        goto after_2;
    // 0x800A567C: addiu       $a3, $a3, 0x80
    ctx->r7 = ADD32(ctx->r7, 0X80);
    after_2:
    // 0x800A5680: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A5684: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A5688: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A568C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A5690: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A5694: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A5698: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A569C: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A56A0: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A56A4: jal         0x800AAB5C
    // 0x800A56A8: addiu       $a3, $a3, 0xA0
    ctx->r7 = ADD32(ctx->r7, 0XA0);
    hud_element_render(rdram, ctx);
        goto after_3;
    // 0x800A56A8: addiu       $a3, $a3, 0xA0
    ctx->r7 = ADD32(ctx->r7, 0XA0);
    after_3:
    // 0x800A56AC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A56B0: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A56B4: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A56B8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A56BC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A56C0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A56C4: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A56C8: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A56CC: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A56D0: jal         0x800AAB5C
    // 0x800A56D4: addiu       $a3, $a3, 0xC0
    ctx->r7 = ADD32(ctx->r7, 0XC0);
    hud_element_render(rdram, ctx);
        goto after_4;
    // 0x800A56D4: addiu       $a3, $a3, 0xC0
    ctx->r7 = ADD32(ctx->r7, 0XC0);
    after_4:
L_800A56D8:
    // 0x800A56D8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800A56DC: lw          $t5, 0x72CC($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X72CC);
    // 0x800A56E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A56E4: bne         $t5, $at, L_800A56F4
    if (ctx->r13 != ctx->r1) {
        // 0x800A56E8: nop
    
            goto L_800A56F4;
    }
    // 0x800A56E8: nop

    // 0x800A56EC: jal         0x8007C36C
    // 0x800A56F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprite_opaque(rdram, ctx);
        goto after_5;
    // 0x800A56F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
L_800A56F4:
    // 0x800A56F4: jal         0x8006ECE0
    // 0x800A56F8: nop

    is_game_paused(rdram, ctx);
        goto after_6;
    // 0x800A56F8: nop

    after_6:
    // 0x800A56FC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A5700: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800A5704: bne         $v0, $zero, L_800A5F94
    if (ctx->r2 != 0) {
        // 0x800A5708: addiu       $t0, $t0, 0x729C
        ctx->r8 = ADD32(ctx->r8, 0X729C);
            goto L_800A5F94;
    }
    // 0x800A5708: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A570C: lb          $v1, 0x193($t1)
    ctx->r3 = MEM_B(ctx->r9, 0X193);
    // 0x800A5710: nop

    // 0x800A5714: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x800A5718: addu        $t3, $t1, $t4
    ctx->r11 = ADD32(ctx->r9, ctx->r12);
    // 0x800A571C: lw          $t7, 0x128($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X128);
    // 0x800A5720: nop

    // 0x800A5724: slti        $at, $t7, 0x1E
    ctx->r1 = SIGNED(ctx->r15) < 0X1E ? 1 : 0;
    // 0x800A5728: beq         $at, $zero, L_800A5A28
    if (ctx->r1 == 0) {
        // 0x800A572C: nop
    
            goto L_800A5A28;
    }
    // 0x800A572C: nop

    // 0x800A5730: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A5734: nop

    // 0x800A5738: lb          $t6, 0x3DA($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X3DA);
    // 0x800A573C: nop

    // 0x800A5740: bne         $t6, $zero, L_800A5A28
    if (ctx->r14 != 0) {
        // 0x800A5744: nop
    
            goto L_800A5A28;
    }
    // 0x800A5744: nop

    // 0x800A5748: lb          $t8, 0x1D8($t1)
    ctx->r24 = MEM_B(ctx->r9, 0X1D8);
    // 0x800A574C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800A5750: bne         $t8, $zero, L_800A5A28
    if (ctx->r24 != 0) {
        // 0x800A5754: nop
    
            goto L_800A5A28;
    }
    // 0x800A5754: nop

    // 0x800A5758: bne         $a2, $v1, L_800A58BC
    if (ctx->r6 != ctx->r3) {
        // 0x800A575C: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_800A58BC;
    }
    // 0x800A575C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A5760: lw          $t9, 0x7320($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7320);
    // 0x800A5764: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x800A5768: lb          $t5, 0x4B($t9)
    ctx->r13 = MEM_B(ctx->r25, 0X4B);
    // 0x800A576C: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x800A5770: slti        $at, $t5, 0x3
    ctx->r1 = SIGNED(ctx->r13) < 0X3 ? 1 : 0;
    // 0x800A5774: bne         $at, $zero, L_800A58BC
    if (ctx->r1 != 0) {
        // 0x800A5778: nop
    
            goto L_800A58BC;
    }
    // 0x800A5778: nop

    // 0x800A577C: sb          $t4, 0x3DA($v0)
    MEM_B(0X3DA, ctx->r2) = ctx->r12;
    // 0x800A5780: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800A5784: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A5788: sb          $a2, 0x3DB($t3)
    MEM_B(0X3DB, ctx->r11) = ctx->r6;
    // 0x800A578C: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800A5790: jal         0x80001D04
    // 0x800A5794: sb          $zero, 0x3DD($t7)
    MEM_B(0X3DD, ctx->r15) = 0;
    sound_play(rdram, ctx);
        goto after_7;
    // 0x800A5794: sb          $zero, 0x3DD($t7)
    MEM_B(0X3DD, ctx->r15) = 0;
    after_7:
    // 0x800A5798: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A579C: lw          $v0, 0x72CC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X72CC);
    // 0x800A57A0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A57A4: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800A57A8: beq         $v0, $zero, L_800A57C4
    if (ctx->r2 == 0) {
        // 0x800A57AC: addiu       $t0, $t0, 0x729C
        ctx->r8 = ADD32(ctx->r8, 0X729C);
            goto L_800A57C4;
    }
    // 0x800A57AC: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A57B0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A57B4: beq         $v0, $at, L_800A5800
    if (ctx->r2 == ctx->r1) {
        // 0x800A57B8: addiu       $t7, $zero, -0x10
        ctx->r15 = ADD32(0, -0X10);
            goto L_800A5800;
    }
    // 0x800A57B8: addiu       $t7, $zero, -0x10
    ctx->r15 = ADD32(0, -0X10);
    // 0x800A57BC: b           L_800A5838
    // 0x800A57C0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
        goto L_800A5838;
    // 0x800A57C0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_800A57C4:
    // 0x800A57C4: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800A57C8: addiu       $t6, $zero, -0x15
    ctx->r14 = ADD32(0, -0X15);
    // 0x800A57CC: sb          $t6, 0x3DC($t8)
    MEM_B(0X3DC, ctx->r24) = ctx->r14;
    // 0x800A57D0: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x800A57D4: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x800A57D8: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x800A57DC: sb          $t9, 0x3FC($t5)
    MEM_B(0X3FC, ctx->r13) = ctx->r25;
    // 0x800A57E0: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800A57E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A57E8: lui         $at, 0x4353
    ctx->r1 = S32(0X4353 << 16);
    // 0x800A57EC: swc1        $f4, 0x3CC($t4)
    MEM_W(0X3CC, ctx->r12) = ctx->f4.u32l;
    // 0x800A57F0: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800A57F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A57F8: b           L_800A5A28
    // 0x800A57FC: swc1        $f6, 0x3EC($t3)
    MEM_W(0X3EC, ctx->r11) = ctx->f6.u32l;
        goto L_800A5A28;
    // 0x800A57FC: swc1        $f6, 0x3EC($t3)
    MEM_W(0X3EC, ctx->r11) = ctx->f6.u32l;
L_800A5800:
    // 0x800A5800: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800A5804: addiu       $t8, $zero, 0x1B
    ctx->r24 = ADD32(0, 0X1B);
    // 0x800A5808: sb          $t7, 0x3DC($t6)
    MEM_B(0X3DC, ctx->r14) = ctx->r15;
    // 0x800A580C: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800A5810: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x800A5814: sb          $t8, 0x3FC($t9)
    MEM_B(0X3FC, ctx->r25) = ctx->r24;
    // 0x800A5818: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x800A581C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A5820: lui         $at, 0x4353
    ctx->r1 = S32(0X4353 << 16);
    // 0x800A5824: swc1        $f8, 0x3CC($t5)
    MEM_W(0X3CC, ctx->r13) = ctx->f8.u32l;
    // 0x800A5828: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800A582C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A5830: b           L_800A5A28
    // 0x800A5834: swc1        $f10, 0x3EC($t4)
    MEM_W(0X3EC, ctx->r12) = ctx->f10.u32l;
        goto L_800A5A28;
    // 0x800A5834: swc1        $f10, 0x3EC($t4)
    MEM_W(0X3EC, ctx->r12) = ctx->f10.u32l;
L_800A5838:
    // 0x800A5838: lh          $v0, 0x0($t1)
    ctx->r2 = MEM_H(ctx->r9, 0X0);
    // 0x800A583C: addiu       $t4, $zero, -0x5A
    ctx->r12 = ADD32(0, -0X5A);
    // 0x800A5840: beq         $v0, $zero, L_800A5888
    if (ctx->r2 == 0) {
        // 0x800A5844: addiu       $t7, $zero, -0x3B
        ctx->r15 = ADD32(0, -0X3B);
            goto L_800A5888;
    }
    // 0x800A5844: addiu       $t7, $zero, -0x3B
    ctx->r15 = ADD32(0, -0X3B);
    // 0x800A5848: beq         $v0, $at, L_800A5888
    if (ctx->r2 == ctx->r1) {
        // 0x800A584C: addiu       $t3, $zero, 0x3C
        ctx->r11 = ADD32(0, 0X3C);
            goto L_800A5888;
    }
    // 0x800A584C: addiu       $t3, $zero, 0x3C
    ctx->r11 = ADD32(0, 0X3C);
    // 0x800A5850: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800A5854: addiu       $t6, $zero, 0x5B
    ctx->r14 = ADD32(0, 0X5B);
    // 0x800A5858: sb          $t3, 0x3DC($t7)
    MEM_B(0X3DC, ctx->r15) = ctx->r11;
    // 0x800A585C: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800A5860: lui         $at, 0xC28C
    ctx->r1 = S32(0XC28C << 16);
    // 0x800A5864: sb          $t6, 0x3FC($t8)
    MEM_B(0X3FC, ctx->r24) = ctx->r14;
    // 0x800A5868: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800A586C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A5870: lui         $at, 0x435D
    ctx->r1 = S32(0X435D << 16);
    // 0x800A5874: swc1        $f16, 0x3CC($t9)
    MEM_W(0X3CC, ctx->r25) = ctx->f16.u32l;
    // 0x800A5878: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x800A587C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A5880: b           L_800A5A28
    // 0x800A5884: swc1        $f18, 0x3EC($t5)
    MEM_W(0X3EC, ctx->r13) = ctx->f18.u32l;
        goto L_800A5A28;
    // 0x800A5884: swc1        $f18, 0x3EC($t5)
    MEM_W(0X3EC, ctx->r13) = ctx->f18.u32l;
L_800A5888:
    // 0x800A5888: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800A588C: lui         $at, 0xC35C
    ctx->r1 = S32(0XC35C << 16);
    // 0x800A5890: sb          $t4, 0x3DC($t3)
    MEM_B(0X3DC, ctx->r11) = ctx->r12;
    // 0x800A5894: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800A5898: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A589C: sb          $t7, 0x3FC($t6)
    MEM_B(0X3FC, ctx->r14) = ctx->r15;
    // 0x800A58A0: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800A58A4: lui         $at, 0x428E
    ctx->r1 = S32(0X428E << 16);
    // 0x800A58A8: swc1        $f4, 0x3CC($t8)
    MEM_W(0X3CC, ctx->r24) = ctx->f4.u32l;
    // 0x800A58AC: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800A58B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A58B4: b           L_800A5A28
    // 0x800A58B8: swc1        $f6, 0x3EC($t9)
    MEM_W(0X3EC, ctx->r25) = ctx->f6.u32l;
        goto L_800A5A28;
    // 0x800A58B8: swc1        $f6, 0x3EC($t9)
    MEM_W(0X3EC, ctx->r25) = ctx->f6.u32l;
L_800A58BC:
    // 0x800A58BC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800A58C0: lw          $t5, 0x7320($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7320);
    // 0x800A58C4: addiu       $t3, $v1, 0x1
    ctx->r11 = ADD32(ctx->r3, 0X1);
    // 0x800A58C8: lb          $t4, 0x4B($t5)
    ctx->r12 = MEM_B(ctx->r13, 0X4B);
    // 0x800A58CC: nop

    // 0x800A58D0: bne         $t4, $t3, L_800A5A28
    if (ctx->r12 != ctx->r11) {
        // 0x800A58D4: nop
    
            goto L_800A5A28;
    }
    // 0x800A58D4: nop

    // 0x800A58D8: beq         $v1, $zero, L_800A5A28
    if (ctx->r3 == 0) {
        // 0x800A58DC: addiu       $t7, $zero, 0x3
        ctx->r15 = ADD32(0, 0X3);
            goto L_800A5A28;
    }
    // 0x800A58DC: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x800A58E0: sb          $t7, 0x3DA($v0)
    MEM_B(0X3DA, ctx->r2) = ctx->r15;
    // 0x800A58E4: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800A58E8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800A58EC: sb          $t6, 0x3DB($t8)
    MEM_B(0X3DB, ctx->r24) = ctx->r14;
    // 0x800A58F0: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800A58F4: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x800A58F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A58FC: jal         0x80001D04
    // 0x800A5900: sb          $zero, 0x3DD($t9)
    MEM_B(0X3DD, ctx->r25) = 0;
    sound_play(rdram, ctx);
        goto after_8;
    // 0x800A5900: sb          $zero, 0x3DD($t9)
    MEM_B(0X3DD, ctx->r25) = 0;
    after_8:
    // 0x800A5904: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A5908: lw          $v0, 0x72CC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X72CC);
    // 0x800A590C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A5910: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800A5914: beq         $v0, $zero, L_800A5930
    if (ctx->r2 == 0) {
        // 0x800A5918: addiu       $t0, $t0, 0x729C
        ctx->r8 = ADD32(ctx->r8, 0X729C);
            goto L_800A5930;
    }
    // 0x800A5918: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A591C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A5920: beq         $v0, $at, L_800A596C
    if (ctx->r2 == ctx->r1) {
        // 0x800A5924: addiu       $t9, $zero, 0x29
        ctx->r25 = ADD32(0, 0X29);
            goto L_800A596C;
    }
    // 0x800A5924: addiu       $t9, $zero, 0x29
    ctx->r25 = ADD32(0, 0X29);
    // 0x800A5928: b           L_800A59A4
    // 0x800A592C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
        goto L_800A59A4;
    // 0x800A592C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_800A5930:
    // 0x800A5930: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800A5934: addiu       $t5, $zero, 0x33
    ctx->r13 = ADD32(0, 0X33);
    // 0x800A5938: sb          $t5, 0x3DC($t4)
    MEM_B(0X3DC, ctx->r12) = ctx->r13;
    // 0x800A593C: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800A5940: addiu       $t3, $zero, -0x29
    ctx->r11 = ADD32(0, -0X29);
    // 0x800A5944: lui         $at, 0x4352
    ctx->r1 = S32(0X4352 << 16);
    // 0x800A5948: sb          $t3, 0x3BC($t7)
    MEM_B(0X3BC, ctx->r15) = ctx->r11;
    // 0x800A594C: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800A5950: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A5954: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x800A5958: swc1        $f8, 0x3CC($t6)
    MEM_W(0X3CC, ctx->r14) = ctx->f8.u32l;
    // 0x800A595C: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800A5960: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A5964: b           L_800A5A28
    // 0x800A5968: swc1        $f10, 0x3AC($t8)
    MEM_W(0X3AC, ctx->r24) = ctx->f10.u32l;
        goto L_800A5A28;
    // 0x800A5968: swc1        $f10, 0x3AC($t8)
    MEM_W(0X3AC, ctx->r24) = ctx->f10.u32l;
L_800A596C:
    // 0x800A596C: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x800A5970: addiu       $t4, $zero, -0x1F
    ctx->r12 = ADD32(0, -0X1F);
    // 0x800A5974: sb          $t9, 0x3DC($t5)
    MEM_B(0X3DC, ctx->r13) = ctx->r25;
    // 0x800A5978: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800A597C: lui         $at, 0x4352
    ctx->r1 = S32(0X4352 << 16);
    // 0x800A5980: sb          $t4, 0x3BC($t3)
    MEM_B(0X3BC, ctx->r11) = ctx->r12;
    // 0x800A5984: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800A5988: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A598C: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x800A5990: swc1        $f16, 0x3CC($t7)
    MEM_W(0X3CC, ctx->r15) = ctx->f16.u32l;
    // 0x800A5994: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800A5998: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A599C: b           L_800A5A28
    // 0x800A59A0: swc1        $f18, 0x3AC($t6)
    MEM_W(0X3AC, ctx->r14) = ctx->f18.u32l;
        goto L_800A5A28;
    // 0x800A59A0: swc1        $f18, 0x3AC($t6)
    MEM_W(0X3AC, ctx->r14) = ctx->f18.u32l;
L_800A59A4:
    // 0x800A59A4: lh          $v0, 0x0($t1)
    ctx->r2 = MEM_H(ctx->r9, 0X0);
    // 0x800A59A8: addiu       $t6, $zero, -0x32
    ctx->r14 = ADD32(0, -0X32);
    // 0x800A59AC: beq         $v0, $zero, L_800A59F4
    if (ctx->r2 == 0) {
        // 0x800A59B0: addiu       $t9, $zero, -0x64
        ctx->r25 = ADD32(0, -0X64);
            goto L_800A59F4;
    }
    // 0x800A59B0: addiu       $t9, $zero, -0x64
    ctx->r25 = ADD32(0, -0X64);
    // 0x800A59B4: beq         $v0, $at, L_800A59F4
    if (ctx->r2 == ctx->r1) {
        // 0x800A59B8: addiu       $t8, $zero, 0x64
        ctx->r24 = ADD32(0, 0X64);
            goto L_800A59F4;
    }
    // 0x800A59B8: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x800A59BC: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800A59C0: addiu       $t5, $zero, 0x32
    ctx->r13 = ADD32(0, 0X32);
    // 0x800A59C4: sb          $t8, 0x3DC($t9)
    MEM_B(0X3DC, ctx->r25) = ctx->r24;
    // 0x800A59C8: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800A59CC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800A59D0: sb          $t5, 0x3BC($t4)
    MEM_B(0X3BC, ctx->r12) = ctx->r13;
    // 0x800A59D4: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800A59D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A59DC: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x800A59E0: swc1        $f4, 0x3CC($t3)
    MEM_W(0X3CC, ctx->r11) = ctx->f4.u32l;
    // 0x800A59E4: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800A59E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A59EC: b           L_800A5A28
    // 0x800A59F0: swc1        $f6, 0x3AC($t7)
    MEM_W(0X3AC, ctx->r15) = ctx->f6.u32l;
        goto L_800A5A28;
    // 0x800A59F0: swc1        $f6, 0x3AC($t7)
    MEM_W(0X3AC, ctx->r15) = ctx->f6.u32l;
L_800A59F4:
    // 0x800A59F4: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800A59F8: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800A59FC: sb          $t6, 0x3DC($t8)
    MEM_B(0X3DC, ctx->r24) = ctx->r14;
    // 0x800A5A00: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x800A5A04: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A5A08: sb          $t9, 0x3BC($t5)
    MEM_B(0X3BC, ctx->r13) = ctx->r25;
    // 0x800A5A0C: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800A5A10: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x800A5A14: swc1        $f8, 0x3CC($t4)
    MEM_W(0X3CC, ctx->r12) = ctx->f8.u32l;
    // 0x800A5A18: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800A5A1C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A5A20: nop

    // 0x800A5A24: swc1        $f10, 0x3AC($t3)
    MEM_W(0X3AC, ctx->r11) = ctx->f10.u32l;
L_800A5A28:
    // 0x800A5A28: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A5A2C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800A5A30: lb          $v1, 0x3DA($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X3DA);
    // 0x800A5A34: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A5A38: beq         $v1, $zero, L_800A5F94
    if (ctx->r3 == 0) {
        // 0x800A5A3C: nop
    
            goto L_800A5F94;
    }
    // 0x800A5A3C: nop

    // 0x800A5A40: bne         $v1, $at, L_800A5CEC
    if (ctx->r3 != ctx->r1) {
        // 0x800A5A44: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800A5CEC;
    }
    // 0x800A5A44: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A5A48: lb          $v1, 0x3DB($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X3DB);
    // 0x800A5A4C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800A5A50: bne         $a2, $v1, L_800A5BE0
    if (ctx->r6 != ctx->r3) {
        // 0x800A5A54: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_800A5BE0;
    }
    // 0x800A5A54: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A5A58: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800A5A5C: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x800A5A60: lb          $v1, 0x3DC($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X3DC);
    // 0x800A5A64: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800A5A68: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800A5A6C: subu        $t6, $v1, $t7
    ctx->r14 = SUB32(ctx->r3, ctx->r15);
    // 0x800A5A70: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x800A5A74: lwc1        $f0, 0x3CC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X3CC);
    // 0x800A5A78: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A5A7C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800A5A80: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800A5A84: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x800A5A88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A5A8C: bc1f        L_800A5AAC
    if (!c1cs) {
        // 0x800A5A90: nop
    
            goto L_800A5AAC;
    }
    // 0x800A5A90: nop

    // 0x800A5A94: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x800A5A98: nop

    // 0x800A5A9C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A5AA0: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x800A5AA4: b           L_800A5ABC
    // 0x800A5AA8: swc1        $f8, 0x3CC($v0)
    MEM_W(0X3CC, ctx->r2) = ctx->f8.u32l;
        goto L_800A5ABC;
    // 0x800A5AA8: swc1        $f8, 0x3CC($v0)
    MEM_W(0X3CC, ctx->r2) = ctx->f8.u32l;
L_800A5AAC:
    // 0x800A5AAC: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x800A5AB0: nop

    // 0x800A5AB4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A5AB8: swc1        $f16, 0x3CC($v0)
    MEM_W(0X3CC, ctx->r2) = ctx->f16.u32l;
L_800A5ABC:
    // 0x800A5ABC: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A5AC0: nop

    // 0x800A5AC4: lb          $v1, 0x3FC($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X3FC);
    // 0x800A5AC8: lwc1        $f0, 0x3EC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X3EC);
    // 0x800A5ACC: addu        $t8, $v1, $a0
    ctx->r24 = ADD32(ctx->r3, ctx->r4);
    // 0x800A5AD0: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x800A5AD4: nop

    // 0x800A5AD8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800A5ADC: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800A5AE0: nop

    // 0x800A5AE4: bc1f        L_800A5B04
    if (!c1cs) {
        // 0x800A5AE8: nop
    
            goto L_800A5B04;
    }
    // 0x800A5AE8: nop

    // 0x800A5AEC: mtc1        $a0, $f6
    ctx->f6.u32l = ctx->r4;
    // 0x800A5AF0: nop

    // 0x800A5AF4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A5AF8: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x800A5AFC: b           L_800A5B14
    // 0x800A5B00: swc1        $f10, 0x3EC($v0)
    MEM_W(0X3EC, ctx->r2) = ctx->f10.u32l;
        goto L_800A5B14;
    // 0x800A5B00: swc1        $f10, 0x3EC($v0)
    MEM_W(0X3EC, ctx->r2) = ctx->f10.u32l;
L_800A5B04:
    // 0x800A5B04: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
    // 0x800A5B08: nop

    // 0x800A5B0C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A5B10: swc1        $f18, 0x3EC($v0)
    MEM_W(0X3EC, ctx->r2) = ctx->f18.u32l;
L_800A5B14:
    // 0x800A5B14: lb          $t9, 0x193($t1)
    ctx->r25 = MEM_B(ctx->r9, 0X193);
    // 0x800A5B18: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x800A5B1C: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x800A5B20: addu        $t4, $t1, $t5
    ctx->r12 = ADD32(ctx->r9, ctx->r13);
    // 0x800A5B24: lw          $t3, 0x128($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X128);
    // 0x800A5B28: nop

    // 0x800A5B2C: slti        $at, $t3, 0x3C
    ctx->r1 = SIGNED(ctx->r11) < 0X3C ? 1 : 0;
    // 0x800A5B30: bne         $at, $zero, L_800A5B50
    if (ctx->r1 != 0) {
        // 0x800A5B34: nop
    
            goto L_800A5B50;
    }
    // 0x800A5B34: nop

    // 0x800A5B38: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800A5B3C: jal         0x80001D04
    // 0x800A5B40: sb          $t7, 0x3DB($t6)
    MEM_B(0X3DB, ctx->r14) = ctx->r15;
    sound_play(rdram, ctx);
        goto after_9;
    // 0x800A5B40: sb          $t7, 0x3DB($t6)
    MEM_B(0X3DB, ctx->r14) = ctx->r15;
    after_9:
    // 0x800A5B44: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A5B48: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A5B4C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_800A5B50:
    // 0x800A5B50: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A5B54: nop

    // 0x800A5B58: lb          $t8, 0x3DC($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X3DC);
    // 0x800A5B5C: lwc1        $f4, 0x3CC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X3CC);
    // 0x800A5B60: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x800A5B64: nop

    // 0x800A5B68: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A5B6C: c.eq.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl == ctx->f8.fl;
    // 0x800A5B70: nop

    // 0x800A5B74: bc1f        L_800A5C54
    if (!c1cs) {
        // 0x800A5B78: nop
    
            goto L_800A5C54;
    }
    // 0x800A5B78: nop

    // 0x800A5B7C: lb          $t9, 0x3FC($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X3FC);
    // 0x800A5B80: lwc1        $f10, 0x3EC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X3EC);
    // 0x800A5B84: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800A5B88: nop

    // 0x800A5B8C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A5B90: c.eq.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl == ctx->f18.fl;
    // 0x800A5B94: nop

    // 0x800A5B98: bc1f        L_800A5C54
    if (!c1cs) {
        // 0x800A5B9C: nop
    
            goto L_800A5C54;
    }
    // 0x800A5B9C: nop

    // 0x800A5BA0: lb          $t5, 0x3DD($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X3DD);
    // 0x800A5BA4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A5BA8: bne         $t5, $zero, L_800A5C54
    if (ctx->r13 != 0) {
        // 0x800A5BAC: addiu       $a1, $a1, 0x7300
        ctx->r5 = ADD32(ctx->r5, 0X7300);
            goto L_800A5C54;
    }
    // 0x800A5BAC: addiu       $a1, $a1, 0x7300
    ctx->r5 = ADD32(ctx->r5, 0X7300);
    // 0x800A5BB0: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x800A5BB4: nop

    // 0x800A5BB8: bne         $t4, $zero, L_800A5BD8
    if (ctx->r12 != 0) {
        // 0x800A5BBC: nop
    
            goto L_800A5BD8;
    }
    // 0x800A5BBC: nop

    // 0x800A5BC0: jal         0x80001D04
    // 0x800A5BC4: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    sound_play(rdram, ctx);
        goto after_10;
    // 0x800A5BC4: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    after_10:
    // 0x800A5BC8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A5BCC: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A5BD0: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A5BD4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_800A5BD8:
    // 0x800A5BD8: b           L_800A5C54
    // 0x800A5BDC: sb          $a2, 0x3DD($v0)
    MEM_B(0X3DD, ctx->r2) = ctx->r6;
        goto L_800A5C54;
    // 0x800A5BDC: sb          $a2, 0x3DD($v0)
    MEM_B(0X3DD, ctx->r2) = ctx->r6;
L_800A5BE0:
    // 0x800A5BE0: bne         $v1, $at, L_800A5C54
    if (ctx->r3 != ctx->r1) {
        // 0x800A5BE4: nop
    
            goto L_800A5C54;
    }
    // 0x800A5BE4: nop

    // 0x800A5BE8: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800A5BEC: lwc1        $f4, 0x3CC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X3CC);
    // 0x800A5BF0: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x800A5BF4: subu        $t7, $t7, $t3
    ctx->r15 = SUB32(ctx->r15, ctx->r11);
    // 0x800A5BF8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800A5BFC: addu        $t7, $t7, $t3
    ctx->r15 = ADD32(ctx->r15, ctx->r11);
    // 0x800A5C00: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800A5C04: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x800A5C08: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A5C0C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A5C10: sub.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800A5C14: swc1        $f8, 0x3CC($v0)
    MEM_W(0X3CC, ctx->r2) = ctx->f8.u32l;
    // 0x800A5C18: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A5C1C: nop

    // 0x800A5C20: lwc1        $f16, 0x3EC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X3EC);
    // 0x800A5C24: nop

    // 0x800A5C28: add.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x800A5C2C: swc1        $f10, 0x3EC($v0)
    MEM_W(0X3EC, ctx->r2) = ctx->f10.u32l;
    // 0x800A5C30: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A5C34: nop

    // 0x800A5C38: lwc1        $f18, 0x3CC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X3CC);
    // 0x800A5C3C: nop

    // 0x800A5C40: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x800A5C44: nop

    // 0x800A5C48: bc1f        L_800A5C54
    if (!c1cs) {
        // 0x800A5C4C: nop
    
            goto L_800A5C54;
    }
    // 0x800A5C4C: nop

    // 0x800A5C50: sb          $zero, 0x3DA($v0)
    MEM_B(0X3DA, ctx->r2) = 0;
L_800A5C54:
    // 0x800A5C54: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A5C58: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A5C5C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800A5C60: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x800A5C64: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800A5C68: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800A5C6C: addiu       $t9, $zero, -0x60
    ctx->r25 = ADD32(0, -0X60);
    // 0x800A5C70: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800A5C74: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800A5C78: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A5C7C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A5C80: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A5C84: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A5C88: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A5C8C: jal         0x800AAB5C
    // 0x800A5C90: addiu       $a3, $a3, 0x3E0
    ctx->r7 = ADD32(ctx->r7, 0X3E0);
    hud_element_render(rdram, ctx);
        goto after_11;
    // 0x800A5C90: addiu       $a3, $a3, 0x3E0
    ctx->r7 = ADD32(ctx->r7, 0X3E0);
    after_11:
    // 0x800A5C94: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A5C98: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A5C9C: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A5CA0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A5CA4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A5CA8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A5CAC: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A5CB0: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A5CB4: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A5CB8: jal         0x800AAB5C
    // 0x800A5CBC: addiu       $a3, $a3, 0x3C0
    ctx->r7 = ADD32(ctx->r7, 0X3C0);
    hud_element_render(rdram, ctx);
        goto after_12;
    // 0x800A5CBC: addiu       $a3, $a3, 0x3C0
    ctx->r7 = ADD32(ctx->r7, 0X3C0);
    after_12:
    // 0x800A5CC0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A5CC4: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A5CC8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800A5CCC: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x800A5CD0: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x800A5CD4: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800A5CD8: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800A5CDC: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800A5CE0: b           L_800A5F94
    // 0x800A5CE4: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
        goto L_800A5F94;
    // 0x800A5CE4: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800A5CE8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_800A5CEC:
    // 0x800A5CEC: bne         $v1, $at, L_800A5F94
    if (ctx->r3 != ctx->r1) {
        // 0x800A5CF0: nop
    
            goto L_800A5F94;
    }
    // 0x800A5CF0: nop

    // 0x800A5CF4: lb          $v1, 0x3DB($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X3DB);
    // 0x800A5CF8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A5CFC: bne         $v1, $at, L_800A5E90
    if (ctx->r3 != ctx->r1) {
        // 0x800A5D00: nop
    
            goto L_800A5E90;
    }
    // 0x800A5D00: nop

    // 0x800A5D04: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800A5D08: lb          $v1, 0x3DC($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X3DC);
    // 0x800A5D0C: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800A5D10: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x800A5D14: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800A5D18: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800A5D1C: addu        $t6, $v1, $t7
    ctx->r14 = ADD32(ctx->r3, ctx->r15);
    // 0x800A5D20: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800A5D24: lwc1        $f0, 0x3CC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X3CC);
    // 0x800A5D28: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A5D2C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800A5D30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A5D34: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x800A5D38: nop

    // 0x800A5D3C: bc1f        L_800A5D5C
    if (!c1cs) {
        // 0x800A5D40: nop
    
            goto L_800A5D5C;
    }
    // 0x800A5D40: nop

    // 0x800A5D44: mtc1        $a0, $f16
    ctx->f16.u32l = ctx->r4;
    // 0x800A5D48: nop

    // 0x800A5D4C: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A5D50: sub.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x800A5D54: b           L_800A5D6C
    // 0x800A5D58: swc1        $f18, 0x3CC($v0)
    MEM_W(0X3CC, ctx->r2) = ctx->f18.u32l;
        goto L_800A5D6C;
    // 0x800A5D58: swc1        $f18, 0x3CC($v0)
    MEM_W(0X3CC, ctx->r2) = ctx->f18.u32l;
L_800A5D5C:
    // 0x800A5D5C: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x800A5D60: nop

    // 0x800A5D64: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A5D68: swc1        $f4, 0x3CC($v0)
    MEM_W(0X3CC, ctx->r2) = ctx->f4.u32l;
L_800A5D6C:
    // 0x800A5D6C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A5D70: nop

    // 0x800A5D74: lb          $v1, 0x3BC($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X3BC);
    // 0x800A5D78: lwc1        $f0, 0x3AC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X3AC);
    // 0x800A5D7C: subu        $t8, $v1, $a0
    ctx->r24 = SUB32(ctx->r3, ctx->r4);
    // 0x800A5D80: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800A5D84: nop

    // 0x800A5D88: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A5D8C: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x800A5D90: nop

    // 0x800A5D94: bc1f        L_800A5DB4
    if (!c1cs) {
        // 0x800A5D98: nop
    
            goto L_800A5DB4;
    }
    // 0x800A5D98: nop

    // 0x800A5D9C: mtc1        $a0, $f10
    ctx->f10.u32l = ctx->r4;
    // 0x800A5DA0: nop

    // 0x800A5DA4: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A5DA8: add.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x800A5DAC: b           L_800A5DC4
    // 0x800A5DB0: swc1        $f6, 0x3AC($v0)
    MEM_W(0X3AC, ctx->r2) = ctx->f6.u32l;
        goto L_800A5DC4;
    // 0x800A5DB0: swc1        $f6, 0x3AC($v0)
    MEM_W(0X3AC, ctx->r2) = ctx->f6.u32l;
L_800A5DB4:
    // 0x800A5DB4: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800A5DB8: nop

    // 0x800A5DBC: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A5DC0: swc1        $f8, 0x3AC($v0)
    MEM_W(0X3AC, ctx->r2) = ctx->f8.u32l;
L_800A5DC4:
    // 0x800A5DC4: lb          $t9, 0x193($t1)
    ctx->r25 = MEM_B(ctx->r9, 0X193);
    // 0x800A5DC8: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x800A5DCC: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x800A5DD0: addu        $t4, $t1, $t5
    ctx->r12 = ADD32(ctx->r9, ctx->r13);
    // 0x800A5DD4: lw          $t3, 0x128($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X128);
    // 0x800A5DD8: nop

    // 0x800A5DDC: slti        $at, $t3, 0x3C
    ctx->r1 = SIGNED(ctx->r11) < 0X3C ? 1 : 0;
    // 0x800A5DE0: bne         $at, $zero, L_800A5E00
    if (ctx->r1 != 0) {
        // 0x800A5DE4: nop
    
            goto L_800A5E00;
    }
    // 0x800A5DE4: nop

    // 0x800A5DE8: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800A5DEC: jal         0x80001D04
    // 0x800A5DF0: sb          $a2, 0x3DB($t7)
    MEM_B(0X3DB, ctx->r15) = ctx->r6;
    sound_play(rdram, ctx);
        goto after_13;
    // 0x800A5DF0: sb          $a2, 0x3DB($t7)
    MEM_B(0X3DB, ctx->r15) = ctx->r6;
    after_13:
    // 0x800A5DF4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A5DF8: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A5DFC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_800A5E00:
    // 0x800A5E00: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A5E04: nop

    // 0x800A5E08: lb          $t6, 0x3DC($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X3DC);
    // 0x800A5E0C: lwc1        $f16, 0x3CC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X3CC);
    // 0x800A5E10: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x800A5E14: nop

    // 0x800A5E18: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A5E1C: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x800A5E20: nop

    // 0x800A5E24: bc1f        L_800A5F04
    if (!c1cs) {
        // 0x800A5E28: nop
    
            goto L_800A5F04;
    }
    // 0x800A5E28: nop

    // 0x800A5E2C: lb          $t8, 0x3BC($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X3BC);
    // 0x800A5E30: lwc1        $f6, 0x3AC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X3AC);
    // 0x800A5E34: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800A5E38: nop

    // 0x800A5E3C: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A5E40: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x800A5E44: nop

    // 0x800A5E48: bc1f        L_800A5F04
    if (!c1cs) {
        // 0x800A5E4C: nop
    
            goto L_800A5F04;
    }
    // 0x800A5E4C: nop

    // 0x800A5E50: lb          $t9, 0x3DD($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X3DD);
    // 0x800A5E54: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A5E58: bne         $t9, $zero, L_800A5F04
    if (ctx->r25 != 0) {
        // 0x800A5E5C: addiu       $a1, $a1, 0x7300
        ctx->r5 = ADD32(ctx->r5, 0X7300);
            goto L_800A5F04;
    }
    // 0x800A5E5C: addiu       $a1, $a1, 0x7300
    ctx->r5 = ADD32(ctx->r5, 0X7300);
    // 0x800A5E60: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x800A5E64: nop

    // 0x800A5E68: bne         $t5, $zero, L_800A5E88
    if (ctx->r13 != 0) {
        // 0x800A5E6C: nop
    
            goto L_800A5E88;
    }
    // 0x800A5E6C: nop

    // 0x800A5E70: jal         0x80001D04
    // 0x800A5E74: addiu       $a0, $zero, 0x101
    ctx->r4 = ADD32(0, 0X101);
    sound_play(rdram, ctx);
        goto after_14;
    // 0x800A5E74: addiu       $a0, $zero, 0x101
    ctx->r4 = ADD32(0, 0X101);
    after_14:
    // 0x800A5E78: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A5E7C: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A5E80: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A5E84: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_800A5E88:
    // 0x800A5E88: b           L_800A5F04
    // 0x800A5E8C: sb          $a2, 0x3DD($v0)
    MEM_B(0X3DD, ctx->r2) = ctx->r6;
        goto L_800A5F04;
    // 0x800A5E8C: sb          $a2, 0x3DD($v0)
    MEM_B(0X3DD, ctx->r2) = ctx->r6;
L_800A5E90:
    // 0x800A5E90: bne         $a2, $v1, L_800A5F04
    if (ctx->r6 != ctx->r3) {
        // 0x800A5E94: nop
    
            goto L_800A5F04;
    }
    // 0x800A5E94: nop

    // 0x800A5E98: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800A5E9C: lwc1        $f16, 0x3CC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X3CC);
    // 0x800A5EA0: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x800A5EA4: subu        $t3, $t3, $t4
    ctx->r11 = SUB32(ctx->r11, ctx->r12);
    // 0x800A5EA8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800A5EAC: addu        $t3, $t3, $t4
    ctx->r11 = ADD32(ctx->r11, ctx->r12);
    // 0x800A5EB0: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x800A5EB4: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x800A5EB8: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A5EBC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A5EC0: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x800A5EC4: swc1        $f18, 0x3CC($v0)
    MEM_W(0X3CC, ctx->r2) = ctx->f18.u32l;
    // 0x800A5EC8: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A5ECC: nop

    // 0x800A5ED0: lwc1        $f4, 0x3AC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X3AC);
    // 0x800A5ED4: nop

    // 0x800A5ED8: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800A5EDC: swc1        $f6, 0x3AC($v0)
    MEM_W(0X3AC, ctx->r2) = ctx->f6.u32l;
    // 0x800A5EE0: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A5EE4: nop

    // 0x800A5EE8: lwc1        $f10, 0x3CC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X3CC);
    // 0x800A5EEC: nop

    // 0x800A5EF0: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x800A5EF4: nop

    // 0x800A5EF8: bc1f        L_800A5F04
    if (!c1cs) {
        // 0x800A5EFC: nop
    
            goto L_800A5F04;
    }
    // 0x800A5EFC: nop

    // 0x800A5F00: sb          $zero, 0x3DA($v0)
    MEM_B(0X3DA, ctx->r2) = 0;
L_800A5F04:
    // 0x800A5F04: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A5F08: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A5F0C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800A5F10: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800A5F14: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800A5F18: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800A5F1C: addiu       $t8, $zero, -0x60
    ctx->r24 = ADD32(0, -0X60);
    // 0x800A5F20: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800A5F24: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800A5F28: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A5F2C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A5F30: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A5F34: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A5F38: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A5F3C: jal         0x800AAB5C
    // 0x800A5F40: addiu       $a3, $a3, 0x3A0
    ctx->r7 = ADD32(ctx->r7, 0X3A0);
    hud_element_render(rdram, ctx);
        goto after_15;
    // 0x800A5F40: addiu       $a3, $a3, 0x3A0
    ctx->r7 = ADD32(ctx->r7, 0X3A0);
    after_15:
    // 0x800A5F44: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A5F48: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A5F4C: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A5F50: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A5F54: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A5F58: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A5F5C: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A5F60: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A5F64: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A5F68: jal         0x800AAB5C
    // 0x800A5F6C: addiu       $a3, $a3, 0x3C0
    ctx->r7 = ADD32(ctx->r7, 0X3C0);
    hud_element_render(rdram, ctx);
        goto after_16;
    // 0x800A5F6C: addiu       $a3, $a3, 0x3C0
    ctx->r7 = ADD32(ctx->r7, 0X3C0);
    after_16:
    // 0x800A5F70: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A5F74: lw          $v0, 0x72BC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X72BC);
    // 0x800A5F78: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A5F7C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800A5F80: sw          $t9, 0x72BC($at)
    MEM_W(0X72BC, ctx->r1) = ctx->r25;
    // 0x800A5F84: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x800A5F88: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800A5F8C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800A5F90: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_800A5F94:
    // 0x800A5F94: jal         0x8007C36C
    // 0x800A5F98: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_17;
    // 0x800A5F98: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_17:
    // 0x800A5F9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A5FA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A5FA4: jr          $ra
    // 0x800A5FA8: nop

    return;
    // 0x800A5FA8: nop

;}
RECOMP_FUNC void hud_wrong_way(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5FAC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A5FB0: lw          $t6, 0x72CC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X72CC);
    // 0x800A5FB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A5FB8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800A5FBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A5FC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A5FC4: bne         $a2, $t6, L_800A5FD4
    if (ctx->r6 != ctx->r14) {
        // 0x800A5FC8: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_800A5FD4;
    }
    // 0x800A5FC8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800A5FCC: jal         0x8007C36C
    // 0x800A5FD0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    sprite_opaque(rdram, ctx);
        goto after_0;
    // 0x800A5FD0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
L_800A5FD4:
    // 0x800A5FD4: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800A5FD8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A5FDC: lbu         $t8, 0x1FC($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X1FC);
    // 0x800A5FE0: nop

    // 0x800A5FE4: slti        $at, $t8, 0x79
    ctx->r1 = SIGNED(ctx->r24) < 0X79 ? 1 : 0;
    // 0x800A5FE8: bne         $at, $zero, L_800A6108
    if (ctx->r1 != 0) {
        // 0x800A5FEC: nop
    
            goto L_800A6108;
    }
    // 0x800A5FEC: nop

    // 0x800A5FF0: lw          $t9, 0x72CC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X72CC);
    // 0x800A5FF4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A5FF8: bne         $t9, $zero, L_800A602C
    if (ctx->r25 != 0) {
        // 0x800A5FFC: addiu       $t0, $t0, 0x729C
        ctx->r8 = ADD32(ctx->r8, 0X729C);
            goto L_800A602C;
    }
    // 0x800A5FFC: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A6000: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A6004: nop

    // 0x800A6008: lb          $t1, 0x47C($v0)
    ctx->r9 = MEM_B(ctx->r2, 0X47C);
    // 0x800A600C: lwc1        $f4, 0x46C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X46C);
    // 0x800A6010: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x800A6014: nop

    // 0x800A6018: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A601C: c.eq.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl == ctx->f8.fl;
    // 0x800A6020: nop

    // 0x800A6024: bc1f        L_800A6108
    if (!c1cs) {
        // 0x800A6028: nop
    
            goto L_800A6108;
    }
    // 0x800A6028: nop

L_800A602C:
    // 0x800A602C: jal         0x8006ECE0
    // 0x800A6030: nop

    is_game_paused(rdram, ctx);
        goto after_1;
    // 0x800A6030: nop

    after_1:
    // 0x800A6034: bne         $v0, $zero, L_800A6108
    if (ctx->r2 != 0) {
        // 0x800A6038: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_800A6108;
    }
    // 0x800A6038: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A603C: addiu       $v1, $v1, 0x72F8
    ctx->r3 = ADD32(ctx->r3, 0X72F8);
    // 0x800A6040: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800A6044: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A6048: bne         $v0, $zero, L_800A605C
    if (ctx->r2 != 0) {
        // 0x800A604C: addiu       $a3, $a3, 0x732C
        ctx->r7 = ADD32(ctx->r7, 0X732C);
            goto L_800A605C;
    }
    // 0x800A604C: addiu       $a3, $a3, 0x732C
    ctx->r7 = ADD32(ctx->r7, 0X732C);
    // 0x800A6050: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x800A6054: nop

    // 0x800A6058: bne         $t2, $zero, L_800A60EC
    if (ctx->r10 != 0) {
        // 0x800A605C: lui         $a2, 0x8012
        ctx->r6 = S32(0X8012 << 16);
            goto L_800A60EC;
    }
L_800A605C:
    // 0x800A605C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A6060: addiu       $a2, $a2, 0x7300
    ctx->r6 = ADD32(ctx->r6, 0X7300);
    // 0x800A6064: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x800A6068: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A606C: bne         $t3, $zero, L_800A60EC
    if (ctx->r11 != 0) {
        // 0x800A6070: addiu       $a3, $a3, 0x732C
        ctx->r7 = ADD32(ctx->r7, 0X732C);
            goto L_800A60EC;
    }
    // 0x800A6070: addiu       $a3, $a3, 0x732C
    ctx->r7 = ADD32(ctx->r7, 0X732C);
    // 0x800A6074: bne         $v0, $zero, L_800A609C
    if (ctx->r2 != 0) {
        // 0x800A6078: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_800A609C;
    }
    // 0x800A6078: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A607C: jal         0x8006FB8C
    // 0x800A6080: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    rand_range(rdram, ctx);
        goto after_2;
    // 0x800A6080: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_2:
    // 0x800A6084: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A6088: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A608C: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x800A6090: addiu       $a2, $a2, 0x7300
    ctx->r6 = ADD32(ctx->r6, 0X7300);
    // 0x800A6094: bne         $at, $zero, L_800A60D0
    if (ctx->r1 != 0) {
        // 0x800A6098: addiu       $v1, $v1, 0x72F8
        ctx->r3 = ADD32(ctx->r3, 0X72F8);
            goto L_800A60D0;
    }
    // 0x800A6098: addiu       $v1, $v1, 0x72F8
    ctx->r3 = ADD32(ctx->r3, 0X72F8);
L_800A609C:
    // 0x800A609C: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x800A60A0: addiu       $a0, $zero, 0x66
    ctx->r4 = ADD32(0, 0X66);
    // 0x800A60A4: jal         0x80001D04
    // 0x800A60A8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    sound_play(rdram, ctx);
        goto after_3;
    // 0x800A60A8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_3:
    // 0x800A60AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A60B0: jal         0x8006FB8C
    // 0x800A60B4: addiu       $a1, $zero, 0x1E0
    ctx->r5 = ADD32(0, 0X1E0);
    rand_range(rdram, ctx);
        goto after_4;
    // 0x800A60B4: addiu       $a1, $zero, 0x1E0
    ctx->r5 = ADD32(0, 0X1E0);
    after_4:
    // 0x800A60B8: addiu       $t4, $v0, 0x78
    ctx->r12 = ADD32(ctx->r2, 0X78);
    // 0x800A60BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A60C0: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A60C4: addiu       $a3, $a3, 0x732C
    ctx->r7 = ADD32(ctx->r7, 0X732C);
    // 0x800A60C8: b           L_800A60EC
    // 0x800A60CC: sw          $t4, 0x732C($at)
    MEM_W(0X732C, ctx->r1) = ctx->r12;
        goto L_800A60EC;
    // 0x800A60CC: sw          $t4, 0x732C($at)
    MEM_W(0X732C, ctx->r1) = ctx->r12;
L_800A60D0:
    // 0x800A60D0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800A60D4: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
    // 0x800A60D8: addiu       $a0, $zero, 0x67
    ctx->r4 = ADD32(0, 0X67);
    // 0x800A60DC: jal         0x80001D04
    // 0x800A60E0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    sound_play(rdram, ctx);
        goto after_5;
    // 0x800A60E0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_5:
    // 0x800A60E4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A60E8: addiu       $a3, $a3, 0x732C
    ctx->r7 = ADD32(ctx->r7, 0X732C);
L_800A60EC:
    // 0x800A60EC: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x800A60F0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800A60F4: nop

    // 0x800A60F8: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x800A60FC: bgez        $t8, L_800A6108
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800A6100: sw          $t8, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r24;
            goto L_800A6108;
    }
    // 0x800A6100: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x800A6104: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
L_800A6108:
    // 0x800A6108: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A610C: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A6110: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A6114: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800A6118: lb          $v1, 0x47A($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X47A);
    // 0x800A611C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800A6120: beq         $v1, $zero, L_800A6334
    if (ctx->r3 == 0) {
        // 0x800A6124: nop
    
            goto L_800A6334;
    }
    // 0x800A6124: nop

    // 0x800A6128: bne         $a2, $v1, L_800A6448
    if (ctx->r6 != ctx->r3) {
        // 0x800A612C: nop
    
            goto L_800A6448;
    }
    // 0x800A612C: nop

    // 0x800A6130: lb          $v1, 0x47B($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X47B);
    // 0x800A6134: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800A6138: bne         $a2, $v1, L_800A6218
    if (ctx->r6 != ctx->r3) {
        // 0x800A613C: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_800A6218;
    }
    // 0x800A613C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A6140: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800A6144: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x800A6148: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800A614C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800A6150: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x800A6154: lwc1        $f16, 0x46C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X46C);
    // 0x800A6158: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A615C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800A6160: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x800A6164: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x800A6168: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A616C: swc1        $f18, 0x46C($v0)
    MEM_W(0X46C, ctx->r2) = ctx->f18.u32l;
    // 0x800A6170: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A6174: nop

    // 0x800A6178: lb          $t3, 0x47C($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X47C);
    // 0x800A617C: lwc1        $f4, 0x46C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X46C);
    // 0x800A6180: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x800A6184: nop

    // 0x800A6188: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A618C: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x800A6190: nop

    // 0x800A6194: bc1f        L_800A61A8
    if (!c1cs) {
        // 0x800A6198: nop
    
            goto L_800A61A8;
    }
    // 0x800A6198: nop

    // 0x800A619C: swc1        $f2, 0x46C($v0)
    MEM_W(0X46C, ctx->r2) = ctx->f2.u32l;
    // 0x800A61A0: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A61A4: nop

L_800A61A8:
    // 0x800A61A8: lwc1        $f8, 0x48C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X48C);
    // 0x800A61AC: nop

    // 0x800A61B0: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x800A61B4: swc1        $f10, 0x48C($v0)
    MEM_W(0X48C, ctx->r2) = ctx->f10.u32l;
    // 0x800A61B8: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A61BC: nop

    // 0x800A61C0: lb          $t4, 0x49C($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X49C);
    // 0x800A61C4: lwc1        $f18, 0x48C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X48C);
    // 0x800A61C8: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x800A61CC: nop

    // 0x800A61D0: cvt.s.w     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A61D4: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x800A61D8: nop

    // 0x800A61DC: bc1f        L_800A61EC
    if (!c1cs) {
        // 0x800A61E0: lw          $t5, 0x18($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X18);
            goto L_800A61EC;
    }
    // 0x800A61E0: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x800A61E4: swc1        $f2, 0x48C($v0)
    MEM_W(0X48C, ctx->r2) = ctx->f2.u32l;
    // 0x800A61E8: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
L_800A61EC:
    // 0x800A61EC: nop

    // 0x800A61F0: lbu         $t6, 0x1FC($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X1FC);
    // 0x800A61F4: nop

    // 0x800A61F8: slti        $at, $t6, 0x5B
    ctx->r1 = SIGNED(ctx->r14) < 0X5B ? 1 : 0;
    // 0x800A61FC: beq         $at, $zero, L_800A628C
    if (ctx->r1 == 0) {
        // 0x800A6200: nop
    
            goto L_800A628C;
    }
    // 0x800A6200: nop

    // 0x800A6204: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800A6208: jal         0x80001D04
    // 0x800A620C: sb          $t7, 0x47B($t8)
    MEM_B(0X47B, ctx->r24) = ctx->r15;
    sound_play(rdram, ctx);
        goto after_6;
    // 0x800A620C: sb          $t7, 0x47B($t8)
    MEM_B(0X47B, ctx->r24) = ctx->r15;
    after_6:
    // 0x800A6210: b           L_800A628C
    // 0x800A6214: nop

        goto L_800A628C;
    // 0x800A6214: nop

L_800A6218:
    // 0x800A6218: bne         $v1, $at, L_800A628C
    if (ctx->r3 != ctx->r1) {
        // 0x800A621C: nop
    
            goto L_800A628C;
    }
    // 0x800A621C: nop

    // 0x800A6220: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800A6224: lwc1        $f4, 0x46C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X46C);
    // 0x800A6228: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x800A622C: subu        $t1, $t1, $t9
    ctx->r9 = SUB32(ctx->r9, ctx->r25);
    // 0x800A6230: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800A6234: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x800A6238: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x800A623C: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x800A6240: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A6244: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A6248: sub.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800A624C: swc1        $f8, 0x46C($v0)
    MEM_W(0X46C, ctx->r2) = ctx->f8.u32l;
    // 0x800A6250: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A6254: nop

    // 0x800A6258: lwc1        $f10, 0x48C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X48C);
    // 0x800A625C: nop

    // 0x800A6260: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x800A6264: swc1        $f16, 0x48C($v0)
    MEM_W(0X48C, ctx->r2) = ctx->f16.u32l;
    // 0x800A6268: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A626C: nop

    // 0x800A6270: lwc1        $f18, 0x46C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X46C);
    // 0x800A6274: nop

    // 0x800A6278: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x800A627C: nop

    // 0x800A6280: bc1f        L_800A628C
    if (!c1cs) {
        // 0x800A6284: nop
    
            goto L_800A628C;
    }
    // 0x800A6284: nop

    // 0x800A6288: sb          $zero, 0x47A($v0)
    MEM_B(0X47A, ctx->r2) = 0;
L_800A628C:
    // 0x800A628C: jal         0x8006ECE0
    // 0x800A6290: nop

    is_game_paused(rdram, ctx);
        goto after_7;
    // 0x800A6290: nop

    after_7:
    // 0x800A6294: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A6298: bne         $v0, $zero, L_800A6448
    if (ctx->r2 != 0) {
        // 0x800A629C: addiu       $t0, $t0, 0x729C
        ctx->r8 = ADD32(ctx->r8, 0X729C);
            goto L_800A6448;
    }
    // 0x800A629C: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A62A0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A62A4: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A62A8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800A62AC: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x800A62B0: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x800A62B4: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x800A62B8: addiu       $t4, $zero, -0x60
    ctx->r12 = ADD32(0, -0X60);
    // 0x800A62BC: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x800A62C0: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800A62C4: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A62C8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A62CC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A62D0: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A62D4: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A62D8: jal         0x800AAB5C
    // 0x800A62DC: addiu       $a3, $a3, 0x460
    ctx->r7 = ADD32(ctx->r7, 0X460);
    hud_element_render(rdram, ctx);
        goto after_8;
    // 0x800A62DC: addiu       $a3, $a3, 0x460
    ctx->r7 = ADD32(ctx->r7, 0X460);
    after_8:
    // 0x800A62E0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A62E4: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A62E8: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A62EC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A62F0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A62F4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A62F8: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A62FC: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A6300: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A6304: jal         0x800AAB5C
    // 0x800A6308: addiu       $a3, $a3, 0x480
    ctx->r7 = ADD32(ctx->r7, 0X480);
    hud_element_render(rdram, ctx);
        goto after_9;
    // 0x800A6308: addiu       $a3, $a3, 0x480
    ctx->r7 = ADD32(ctx->r7, 0X480);
    after_9:
    // 0x800A630C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A6310: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A6314: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800A6318: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800A631C: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x800A6320: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800A6324: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800A6328: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800A632C: b           L_800A6448
    // 0x800A6330: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
        goto L_800A6448;
    // 0x800A6330: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_800A6334:
    // 0x800A6334: lbu         $t9, 0x1FC($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X1FC);
    // 0x800A6338: nop

    // 0x800A633C: slti        $at, $t9, 0x79
    ctx->r1 = SIGNED(ctx->r25) < 0X79 ? 1 : 0;
    // 0x800A6340: bne         $at, $zero, L_800A6448
    if (ctx->r1 != 0) {
        // 0x800A6344: nop
    
            goto L_800A6448;
    }
    // 0x800A6344: nop

    // 0x800A6348: sb          $a2, 0x47A($v0)
    MEM_B(0X47A, ctx->r2) = ctx->r6;
    // 0x800A634C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800A6350: addiu       $t2, $zero, -0x1F
    ctx->r10 = ADD32(0, -0X1F);
    // 0x800A6354: sb          $a2, 0x47B($t1)
    MEM_B(0X47B, ctx->r9) = ctx->r6;
    // 0x800A6358: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800A635C: addiu       $t4, $zero, 0x34
    ctx->r12 = ADD32(0, 0X34);
    // 0x800A6360: sb          $t2, 0x47C($t3)
    MEM_B(0X47C, ctx->r11) = ctx->r10;
    // 0x800A6364: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x800A6368: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A636C: sb          $t4, 0x49C($t5)
    MEM_B(0X49C, ctx->r13) = ctx->r12;
    // 0x800A6370: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800A6374: addiu       $t7, $zero, -0x15
    ctx->r15 = ADD32(0, -0X15);
    // 0x800A6378: sb          $zero, 0x47D($t6)
    MEM_B(0X47D, ctx->r14) = 0;
    // 0x800A637C: lw          $v1, 0x72CC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X72CC);
    // 0x800A6380: nop

    // 0x800A6384: bne         $a2, $v1, L_800A63A4
    if (ctx->r6 != ctx->r3) {
        // 0x800A6388: slti        $at, $v1, 0x2
        ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_800A63A4;
    }
    // 0x800A6388: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x800A638C: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800A6390: addiu       $t9, $zero, 0x2A
    ctx->r25 = ADD32(0, 0X2A);
    // 0x800A6394: sb          $t7, 0x47C($t8)
    MEM_B(0X47C, ctx->r24) = ctx->r15;
    // 0x800A6398: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800A639C: b           L_800A63FC
    // 0x800A63A0: sb          $t9, 0x49C($t1)
    MEM_B(0X49C, ctx->r9) = ctx->r25;
        goto L_800A63FC;
    // 0x800A63A0: sb          $t9, 0x49C($t1)
    MEM_B(0X49C, ctx->r9) = ctx->r25;
L_800A63A4:
    // 0x800A63A4: bne         $at, $zero, L_800A63FC
    if (ctx->r1 != 0) {
        // 0x800A63A8: nop
    
            goto L_800A63FC;
    }
    // 0x800A63A8: nop

    // 0x800A63AC: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x800A63B0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A63B4: lh          $v0, 0x0($t2)
    ctx->r2 = MEM_H(ctx->r10, 0X0);
    // 0x800A63B8: addiu       $t3, $zero, -0x64
    ctx->r11 = ADD32(0, -0X64);
    // 0x800A63BC: beq         $v0, $zero, L_800A63CC
    if (ctx->r2 == 0) {
        // 0x800A63C0: nop
    
            goto L_800A63CC;
    }
    // 0x800A63C0: nop

    // 0x800A63C4: bne         $v0, $at, L_800A63E4
    if (ctx->r2 != ctx->r1) {
        // 0x800A63C8: nop
    
            goto L_800A63E4;
    }
    // 0x800A63C8: nop

L_800A63CC:
    // 0x800A63CC: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800A63D0: addiu       $t5, $zero, -0x37
    ctx->r13 = ADD32(0, -0X37);
    // 0x800A63D4: sb          $t3, 0x47C($t4)
    MEM_B(0X47C, ctx->r12) = ctx->r11;
    // 0x800A63D8: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800A63DC: b           L_800A63FC
    // 0x800A63E0: sb          $t5, 0x49C($t6)
    MEM_B(0X49C, ctx->r14) = ctx->r13;
        goto L_800A63FC;
    // 0x800A63E0: sb          $t5, 0x49C($t6)
    MEM_B(0X49C, ctx->r14) = ctx->r13;
L_800A63E4:
    // 0x800A63E4: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800A63E8: addiu       $t7, $zero, 0x3B
    ctx->r15 = ADD32(0, 0X3B);
    // 0x800A63EC: sb          $t7, 0x47C($t8)
    MEM_B(0X47C, ctx->r24) = ctx->r15;
    // 0x800A63F0: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800A63F4: addiu       $t9, $zero, 0x68
    ctx->r25 = ADD32(0, 0X68);
    // 0x800A63F8: sb          $t9, 0x49C($t1)
    MEM_B(0X49C, ctx->r9) = ctx->r25;
L_800A63FC:
    // 0x800A63FC: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A6400: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x800A6404: lb          $t2, 0x49C($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X49C);
    // 0x800A6408: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A640C: addiu       $t3, $t2, 0xC8
    ctx->r11 = ADD32(ctx->r10, 0XC8);
    // 0x800A6410: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x800A6414: nop

    // 0x800A6418: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A641C: swc1        $f8, 0x48C($v0)
    MEM_W(0X48C, ctx->r2) = ctx->f8.u32l;
    // 0x800A6420: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A6424: nop

    // 0x800A6428: lb          $t4, 0x49C($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X49C);
    // 0x800A642C: nop

    // 0x800A6430: addiu       $t5, $t4, -0xC8
    ctx->r13 = ADD32(ctx->r12, -0XC8);
    // 0x800A6434: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x800A6438: nop

    // 0x800A643C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A6440: jal         0x80001D04
    // 0x800A6444: swc1        $f16, 0x46C($v0)
    MEM_W(0X46C, ctx->r2) = ctx->f16.u32l;
    sound_play(rdram, ctx);
        goto after_10;
    // 0x800A6444: swc1        $f16, 0x46C($v0)
    MEM_W(0X46C, ctx->r2) = ctx->f16.u32l;
    after_10:
L_800A6448:
    // 0x800A6448: jal         0x8007C36C
    // 0x800A644C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_11;
    // 0x800A644C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_11:
    // 0x800A6450: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A6454: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A6458: jr          $ra
    // 0x800A645C: nop

    return;
    // 0x800A645C: nop

;}
RECOMP_FUNC void hud_finish_position(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A6460: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800A6464: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A6468: lw          $a3, 0x729C($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X729C);
    // 0x800A646C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800A6470: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A6474: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A6478: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A647C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A6480: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A6484: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A6488: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A648C: jal         0x800AAB5C
    // 0x800A6490: addiu       $a3, $a3, 0x5E0
    ctx->r7 = ADD32(ctx->r7, 0X5E0);
    hud_element_render(rdram, ctx);
        goto after_0;
    // 0x800A6490: addiu       $a3, $a3, 0x5E0
    ctx->r7 = ADD32(ctx->r7, 0X5E0);
    after_0:
    // 0x800A6494: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A6498: lw          $a3, 0x729C($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X729C);
    // 0x800A649C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A64A0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A64A4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A64A8: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A64AC: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A64B0: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A64B4: jal         0x800AAB5C
    // 0x800A64B8: addiu       $a3, $a3, 0x600
    ctx->r7 = ADD32(ctx->r7, 0X600);
    hud_element_render(rdram, ctx);
        goto after_1;
    // 0x800A64B8: addiu       $a3, $a3, 0x600
    ctx->r7 = ADD32(ctx->r7, 0X600);
    after_1:
    // 0x800A64BC: jal         0x8006BFD8
    // 0x800A64C0: nop

    level_type(rdram, ctx);
        goto after_2;
    // 0x800A64C0: nop

    after_2:
    // 0x800A64C4: andi        $t6, $v0, 0x40
    ctx->r14 = ctx->r2 & 0X40;
    // 0x800A64C8: bne         $t6, $zero, L_800A6790
    if (ctx->r14 != 0) {
        // 0x800A64CC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A6790;
    }
    // 0x800A64CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A64D0: jal         0x8009F1C4
    // 0x800A64D4: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_3;
    // 0x800A64D4: nop

    after_3:
    // 0x800A64D8: bne         $v0, $zero, L_800A6790
    if (ctx->r2 != 0) {
        // 0x800A64DC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A6790;
    }
    // 0x800A64DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A64E0: jal         0x8001BAA8
    // 0x800A64E4: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    get_racer_objects(rdram, ctx);
        goto after_4;
    // 0x800A64E4: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_4:
    // 0x800A64E8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A64EC: lbu         $t7, 0x72F7($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X72F7);
    // 0x800A64F0: nop

    // 0x800A64F4: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x800A64F8: bne         $at, $zero, L_800A6790
    if (ctx->r1 != 0) {
        // 0x800A64FC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A6790;
    }
    // 0x800A64FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A6500: jal         0x8009F1C4
    // 0x800A6504: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_5;
    // 0x800A6504: nop

    after_5:
    // 0x800A6508: beq         $v0, $zero, L_800A6520
    if (ctx->r2 == 0) {
        // 0x800A650C: nop
    
            goto L_800A6520;
    }
    // 0x800A650C: nop

    // 0x800A6510: jal         0x8006ECF0
    // 0x800A6514: nop

    is_postrace_viewport_active(rdram, ctx);
        goto after_6;
    // 0x800A6514: nop

    after_6:
    // 0x800A6518: bne         $v0, $zero, L_800A6790
    if (ctx->r2 != 0) {
        // 0x800A651C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A6790;
    }
    // 0x800A651C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A6520:
    // 0x800A6520: jal         0x800C484C
    // 0x800A6524: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_7;
    // 0x800A6524: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x800A6528: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800A652C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800A6530: lh          $t0, 0x1AC($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X1AC);
    // 0x800A6534: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A6538: beq         $t8, $t0, L_800A671C
    if (ctx->r24 == ctx->r8) {
        // 0x800A653C: lui         $at, 0x420C
        ctx->r1 = S32(0X420C << 16);
            goto L_800A671C;
    }
    // 0x800A653C: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x800A6540: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800A6544: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800A6548: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x800A654C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800A6550: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x800A6554: jal         0x800C48E4
    // 0x800A6558: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_8;
    // 0x800A6558: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_8:
    // 0x800A655C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A6560: lw          $v0, 0x729C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X729C);
    // 0x800A6564: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x800A6568: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A656C: lwc1        $f4, 0x16C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X16C);
    // 0x800A6570: lwc1        $f16, 0x170($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X170);
    // 0x800A6574: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800A6578: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A657C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800A6580: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x800A6584: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800A6588: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A658C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A6590: addiu       $a3, $a3, -0x73E8
    ctx->r7 = ADD32(ctx->r7, -0X73E8);
    // 0x800A6594: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A6598: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A659C: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800A65A0: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800A65A4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800A65A8: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800A65AC: nop

    // 0x800A65B0: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800A65B4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A65B8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A65BC: nop

    // 0x800A65C0: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800A65C4: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x800A65C8: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800A65CC: jal         0x800C49A0
    // 0x800A65D0: nop

    draw_text(rdram, ctx);
        goto after_9;
    // 0x800A65D0: nop

    after_9:
    // 0x800A65D4: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800A65D8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A65DC: lw          $v0, 0x729C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X729C);
    // 0x800A65E0: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800A65E4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A65E8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A65EC: lwc1        $f4, 0x16C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X16C);
    // 0x800A65F0: lwc1        $f8, 0x170($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X170);
    // 0x800A65F4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A65F8: lb          $t6, 0x17C($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X17C);
    // 0x800A65FC: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800A6600: lb          $a2, 0x17A($v0)
    ctx->r6 = MEM_B(ctx->r2, 0X17A);
    // 0x800A6604: lb          $a3, 0x17B($v0)
    ctx->r7 = MEM_B(ctx->r2, 0X17B);
    // 0x800A6608: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800A660C: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x800A6610: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800A6614: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A6618: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A661C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800A6620: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A6624: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800A6628: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800A662C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800A6630: jal         0x800A8518
    // 0x800A6634: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    hud_timer_render(rdram, ctx);
        goto after_10;
    // 0x800A6634: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_10:
    // 0x800A6638: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A663C: lw          $v0, 0x729C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X729C);
    // 0x800A6640: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x800A6644: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A6648: lwc1        $f16, 0x2EC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X2EC);
    // 0x800A664C: lwc1        $f8, 0x2F0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X2F0);
    // 0x800A6650: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800A6654: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A6658: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800A665C: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x800A6660: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800A6664: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A6668: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A666C: addiu       $a3, $a3, -0x73E0
    ctx->r7 = ADD32(ctx->r7, -0X73E0);
    // 0x800A6670: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A6674: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A6678: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800A667C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800A6680: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800A6684: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A6688: nop

    // 0x800A668C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800A6690: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A6694: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A6698: nop

    // 0x800A669C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A66A0: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x800A66A4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A66A8: jal         0x800C49A0
    // 0x800A66AC: nop

    draw_text(rdram, ctx);
        goto after_11;
    // 0x800A66AC: nop

    after_11:
    // 0x800A66B0: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800A66B4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A66B8: lw          $v0, 0x729C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X729C);
    // 0x800A66BC: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x800A66C0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A66C4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A66C8: lwc1        $f16, 0x2EC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X2EC);
    // 0x800A66CC: lwc1        $f4, 0x2F0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X2F0);
    // 0x800A66D0: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800A66D4: lb          $t2, 0x2FC($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X2FC);
    // 0x800A66D8: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800A66DC: lb          $a2, 0x2FA($v0)
    ctx->r6 = MEM_B(ctx->r2, 0X2FA);
    // 0x800A66E0: lb          $a3, 0x2FB($v0)
    ctx->r7 = MEM_B(ctx->r2, 0X2FB);
    // 0x800A66E4: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800A66E8: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x800A66EC: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800A66F0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A66F4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A66F8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800A66FC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A6700: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800A6704: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800A6708: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800A670C: jal         0x800A8518
    // 0x800A6710: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    hud_timer_render(rdram, ctx);
        goto after_12;
    // 0x800A6710: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_12:
    // 0x800A6714: b           L_800A6790
    // 0x800A6718: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800A6790;
    // 0x800A6718: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A671C:
    // 0x800A671C: lw          $v0, 0x729C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X729C);
    // 0x800A6720: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A6724: lwc1        $f8, 0x16C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X16C);
    // 0x800A6728: lwc1        $f4, 0x170($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X170);
    // 0x800A672C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800A6730: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A6734: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800A6738: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800A673C: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800A6740: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A6744: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A6748: addiu       $a3, $a3, 0x2DCC
    ctx->r7 = ADD32(ctx->r7, 0X2DCC);
    // 0x800A674C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800A6750: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A6754: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800A6758: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x800A675C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800A6760: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800A6764: nop

    // 0x800A6768: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800A676C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A6770: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A6774: nop

    // 0x800A6778: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A677C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800A6780: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800A6784: jal         0x800C49A0
    // 0x800A6788: nop

    draw_text(rdram, ctx);
        goto after_13;
    // 0x800A6788: nop

    after_13:
    // 0x800A678C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A6790:
    // 0x800A6790: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800A6794: jr          $ra
    // 0x800A6798: nop

    return;
    // 0x800A6798: nop

;}
RECOMP_FUNC void hud_race_finish_multiplayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A679C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800A67A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A67A4: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x800A67A8: jal         0x8006BFD8
    // 0x800A67AC: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    level_type(rdram, ctx);
        goto after_0;
    // 0x800A67AC: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A67B0: jal         0x8009F1C4
    // 0x800A67B4: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    is_in_two_player_adventure(rdram, ctx);
        goto after_1;
    // 0x800A67B4: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    after_1:
    // 0x800A67B8: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800A67BC: beq         $v0, $zero, L_800A68E4
    if (ctx->r2 == 0) {
        // 0x800A67C0: nop
    
            goto L_800A68E4;
    }
    // 0x800A67C0: nop

    // 0x800A67C4: jal         0x8006ECF0
    // 0x800A67C8: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    is_postrace_viewport_active(rdram, ctx);
        goto after_2;
    // 0x800A67C8: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    after_2:
    // 0x800A67CC: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800A67D0: beq         $v0, $zero, L_800A68E4
    if (ctx->r2 == 0) {
        // 0x800A67D4: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_800A68E4;
    }
    // 0x800A67D4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A67D8: lbu         $t6, 0x7749($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7749);
    // 0x800A67DC: nop

    // 0x800A67E0: bne         $t6, $zero, L_800A68E4
    if (ctx->r14 != 0) {
        // 0x800A67E4: nop
    
            goto L_800A68E4;
    }
    // 0x800A67E4: nop

    // 0x800A67E8: jal         0x8000E184
    // 0x800A67EC: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    is_player_two_in_control(rdram, ctx);
        goto after_3;
    // 0x800A67EC: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    after_3:
    // 0x800A67F0: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800A67F4: beq         $v0, $zero, L_800A6864
    if (ctx->r2 == 0) {
        // 0x800A67F8: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_800A6864;
    }
    // 0x800A67F8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800A67FC: addiu       $t1, $t1, 0x729C
    ctx->r9 = ADD32(ctx->r9, 0X729C);
    // 0x800A6800: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A6804: lui         $at, 0x42D8
    ctx->r1 = S32(0X42D8 << 16);
    // 0x800A6808: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A680C: lwc1        $f4, 0x5F0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X5F0);
    // 0x800A6810: nop

    // 0x800A6814: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800A6818: swc1        $f6, 0x5F0($v0)
    MEM_W(0X5F0, ctx->r2) = ctx->f6.u32l;
    // 0x800A681C: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A6820: nop

    // 0x800A6824: lwc1        $f8, 0x610($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X610);
    // 0x800A6828: nop

    // 0x800A682C: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x800A6830: swc1        $f10, 0x610($v0)
    MEM_W(0X610, ctx->r2) = ctx->f10.u32l;
    // 0x800A6834: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A6838: nop

    // 0x800A683C: lwc1        $f4, 0x170($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X170);
    // 0x800A6840: nop

    // 0x800A6844: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800A6848: swc1        $f6, 0x170($v0)
    MEM_W(0X170, ctx->r2) = ctx->f6.u32l;
    // 0x800A684C: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A6850: nop

    // 0x800A6854: lwc1        $f8, 0x2F0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X2F0);
    // 0x800A6858: nop

    // 0x800A685C: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x800A6860: swc1        $f10, 0x2F0($v0)
    MEM_W(0X2F0, ctx->r2) = ctx->f10.u32l;
L_800A6864:
    // 0x800A6864: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800A6868: addiu       $t1, $t1, 0x729C
    ctx->r9 = ADD32(ctx->r9, 0X729C);
    // 0x800A686C: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A6870: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x800A6874: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A6878: lwc1        $f4, 0x5F0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X5F0);
    // 0x800A687C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800A6880: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800A6884: addiu       $v1, $v1, 0x2CF0
    ctx->r3 = ADD32(ctx->r3, 0X2CF0);
    // 0x800A6888: swc1        $f6, 0x5F0($v0)
    MEM_W(0X5F0, ctx->r2) = ctx->f6.u32l;
    // 0x800A688C: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A6890: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A6894: lwc1        $f8, 0x610($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X610);
    // 0x800A6898: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800A689C: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x800A68A0: swc1        $f10, 0x610($v0)
    MEM_W(0X610, ctx->r2) = ctx->f10.u32l;
    // 0x800A68A4: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A68A8: nop

    // 0x800A68AC: lwc1        $f4, 0x170($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X170);
    // 0x800A68B0: nop

    // 0x800A68B4: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800A68B8: swc1        $f6, 0x170($v0)
    MEM_W(0X170, ctx->r2) = ctx->f6.u32l;
    // 0x800A68BC: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A68C0: nop

    // 0x800A68C4: lwc1        $f8, 0x2F0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X2F0);
    // 0x800A68C8: nop

    // 0x800A68CC: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x800A68D0: swc1        $f10, 0x2F0($v0)
    MEM_W(0X2F0, ctx->r2) = ctx->f10.u32l;
    // 0x800A68D4: lh          $t7, 0x0($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X0);
    // 0x800A68D8: nop

    // 0x800A68DC: sb          $t7, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r15;
    // 0x800A68E0: sb          $t8, 0x7749($at)
    MEM_B(0X7749, ctx->r1) = ctx->r24;
L_800A68E4:
    // 0x800A68E4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800A68E8: addiu       $t1, $t1, 0x729C
    ctx->r9 = ADD32(ctx->r9, 0X729C);
    // 0x800A68EC: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A68F0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800A68F4: lbu         $t9, 0x5FA($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X5FA);
    // 0x800A68F8: addiu       $v1, $v1, 0x2CF0
    ctx->r3 = ADD32(ctx->r3, 0X2CF0);
    // 0x800A68FC: sltiu       $at, $t9, 0x5
    ctx->r1 = ctx->r25 < 0X5 ? 1 : 0;
    // 0x800A6900: beq         $at, $zero, L_800A72E4
    if (ctx->r1 == 0) {
        // 0x800A6904: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_800A72E4;
    }
    // 0x800A6904: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800A6908: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A690C: addu        $at, $at, $t9
    gpr jr_addend_800A6918 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800A6910: lw          $t9, -0x733C($at)
    ctx->r25 = ADD32(ctx->r1, -0X733C);
    // 0x800A6914: nop

    // 0x800A6918: jr          $t9
    // 0x800A691C: nop

    switch (jr_addend_800A6918 >> 2) {
        case 0: goto L_800A6920; break;
        case 1: goto L_800A6E64; break;
        case 2: goto L_800A7114; break;
        case 3: goto L_800A71EC; break;
        case 4: goto L_800A72B0; break;
        default: switch_error(__func__, 0x800A6918, 0x800E8CC4);
    }
    // 0x800A691C: nop

L_800A6920:
    // 0x800A6920: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x800A6924: addiu       $t4, $zero, 0x7F
    ctx->r12 = ADD32(0, 0X7F);
    // 0x800A6928: andi        $t3, $t2, 0x40
    ctx->r11 = ctx->r10 & 0X40;
    // 0x800A692C: bne         $t3, $zero, L_800A6964
    if (ctx->r11 != 0) {
        // 0x800A6930: addiu       $a0, $zero, 0x16
        ctx->r4 = ADD32(0, 0X16);
            goto L_800A6964;
    }
    // 0x800A6930: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x800A6934: sb          $t4, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r12;
    // 0x800A6938: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x800A693C: lh          $t5, 0x0($a3)
    ctx->r13 = MEM_H(ctx->r7, 0X0);
    // 0x800A6940: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    // 0x800A6944: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A6948: jal         0x80001D04
    // 0x800A694C: sb          $t5, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r13;
    sound_play(rdram, ctx);
        goto after_4;
    // 0x800A694C: sb          $t5, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r13;
    after_4:
    // 0x800A6950: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800A6954: addiu       $t1, $t1, 0x729C
    ctx->r9 = ADD32(ctx->r9, 0X729C);
    // 0x800A6958: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A695C: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800A6960: nop

L_800A6964:
    // 0x800A6964: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A6968: lw          $v1, 0x72CC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X72CC);
    // 0x800A696C: addiu       $t6, $zero, -0x14
    ctx->r14 = ADD32(0, -0X14);
    // 0x800A6970: beq         $v1, $zero, L_800A698C
    if (ctx->r3 == 0) {
        // 0x800A6974: addiu       $a2, $zero, 0x2
        ctx->r6 = ADD32(0, 0X2);
            goto L_800A698C;
    }
    // 0x800A6974: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x800A6978: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800A697C: beq         $v1, $t0, L_800A6990
    if (ctx->r3 == ctx->r8) {
        // 0x800A6980: nop
    
            goto L_800A6990;
    }
    // 0x800A6980: nop

    // 0x800A6984: b           L_800A69AC
    // 0x800A6988: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
        goto L_800A69AC;
    // 0x800A6988: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
L_800A698C:
    // 0x800A698C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800A6990:
    // 0x800A6990: sb          $t6, 0x5FD($v0)
    MEM_B(0X5FD, ctx->r2) = ctx->r14;
    // 0x800A6994: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800A6998: addiu       $v1, $zero, -0xF
    ctx->r3 = ADD32(0, -0XF);
    // 0x800A699C: sb          $v1, 0x17D($t7)
    MEM_B(0X17D, ctx->r15) = ctx->r3;
    // 0x800A69A0: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800A69A4: b           L_800A6A00
    // 0x800A69A8: sb          $v1, 0x2FD($t8)
    MEM_B(0X2FD, ctx->r24) = ctx->r3;
        goto L_800A6A00;
    // 0x800A69A8: sb          $v1, 0x2FD($t8)
    MEM_B(0X2FD, ctx->r24) = ctx->r3;
L_800A69AC:
    // 0x800A69AC: lh          $v1, 0x0($a3)
    ctx->r3 = MEM_H(ctx->r7, 0X0);
    // 0x800A69B0: addiu       $t9, $zero, -0x5A
    ctx->r25 = ADD32(0, -0X5A);
    // 0x800A69B4: beq         $v1, $zero, L_800A69C4
    if (ctx->r3 == 0) {
        // 0x800A69B8: nop
    
            goto L_800A69C4;
    }
    // 0x800A69B8: nop

    // 0x800A69BC: bne         $a2, $v1, L_800A69E4
    if (ctx->r6 != ctx->r3) {
        // 0x800A69C0: addiu       $t4, $zero, 0x37
        ctx->r12 = ADD32(0, 0X37);
            goto L_800A69E4;
    }
    // 0x800A69C0: addiu       $t4, $zero, 0x37
    ctx->r12 = ADD32(0, 0X37);
L_800A69C4:
    // 0x800A69C4: sb          $t9, 0x5FD($v0)
    MEM_B(0X5FD, ctx->r2) = ctx->r25;
    // 0x800A69C8: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800A69CC: addiu       $v1, $zero, -0x55
    ctx->r3 = ADD32(0, -0X55);
    // 0x800A69D0: sb          $v1, 0x17D($t2)
    MEM_B(0X17D, ctx->r10) = ctx->r3;
    // 0x800A69D4: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x800A69D8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x800A69DC: b           L_800A6A00
    // 0x800A69E0: sb          $v1, 0x2FD($t3)
    MEM_B(0X2FD, ctx->r11) = ctx->r3;
        goto L_800A6A00;
    // 0x800A69E0: sb          $v1, 0x2FD($t3)
    MEM_B(0X2FD, ctx->r11) = ctx->r3;
L_800A69E4:
    // 0x800A69E4: sb          $t4, 0x5FD($v0)
    MEM_B(0X5FD, ctx->r2) = ctx->r12;
    // 0x800A69E8: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800A69EC: addiu       $v1, $zero, 0x3C
    ctx->r3 = ADD32(0, 0X3C);
    // 0x800A69F0: sb          $v1, 0x17D($t5)
    MEM_B(0X17D, ctx->r13) = ctx->r3;
    // 0x800A69F4: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800A69F8: nop

    // 0x800A69FC: sb          $v1, 0x2FD($t6)
    MEM_B(0X2FD, ctx->r14) = ctx->r3;
L_800A6A00:
    // 0x800A6A00: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x800A6A04: addiu       $a0, $a0, 0x300
    ctx->r4 = ADD32(ctx->r4, 0X300);
    // 0x800A6A08: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800A6A0C: nop

    // 0x800A6A10: bne         $t7, $zero, L_800A6A60
    if (ctx->r15 != 0) {
        // 0x800A6A14: nop
    
            goto L_800A6A60;
    }
    // 0x800A6A14: nop

    // 0x800A6A18: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A6A1C: nop

    // 0x800A6A20: lb          $t8, 0x5FD($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X5FD);
    // 0x800A6A24: nop

    // 0x800A6A28: addiu       $t9, $t8, -0x4
    ctx->r25 = ADD32(ctx->r24, -0X4);
    // 0x800A6A2C: sb          $t9, 0x5FD($v0)
    MEM_B(0X5FD, ctx->r2) = ctx->r25;
    // 0x800A6A30: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A6A34: nop

    // 0x800A6A38: lb          $t2, 0x17D($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X17D);
    // 0x800A6A3C: nop

    // 0x800A6A40: addiu       $t3, $t2, -0x4
    ctx->r11 = ADD32(ctx->r10, -0X4);
    // 0x800A6A44: sb          $t3, 0x17D($v0)
    MEM_B(0X17D, ctx->r2) = ctx->r11;
    // 0x800A6A48: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A6A4C: nop

    // 0x800A6A50: lb          $t4, 0x2FD($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X2FD);
    // 0x800A6A54: nop

    // 0x800A6A58: addiu       $t5, $t4, -0x4
    ctx->r13 = ADD32(ctx->r12, -0X4);
    // 0x800A6A5C: sb          $t5, 0x2FD($v0)
    MEM_B(0X2FD, ctx->r2) = ctx->r13;
L_800A6A60:
    // 0x800A6A60: lh          $v0, 0x1AC($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X1AC);
    // 0x800A6A64: nop

    // 0x800A6A68: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x800A6A6C: beq         $at, $zero, L_800A6A80
    if (ctx->r1 == 0) {
        // 0x800A6A70: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_800A6A80;
    }
    // 0x800A6A70: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x800A6A74: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800A6A78: b           L_800A6A8C
    // 0x800A6A7C: sh          $t6, 0x618($t7)
    MEM_H(0X618, ctx->r15) = ctx->r14;
        goto L_800A6A8C;
    // 0x800A6A7C: sh          $t6, 0x618($t7)
    MEM_H(0X618, ctx->r15) = ctx->r14;
L_800A6A80:
    // 0x800A6A80: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800A6A84: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x800A6A88: sh          $t8, 0x618($t9)
    MEM_H(0X618, ctx->r25) = ctx->r24;
L_800A6A8C:
    // 0x800A6A8C: lh          $t2, 0x1AC($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X1AC);
    // 0x800A6A90: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800A6A94: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x800A6A98: sh          $t3, 0x5F8($t4)
    MEM_H(0X5F8, ctx->r12) = ctx->r11;
    // 0x800A6A9C: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800A6AA0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A6AA4: sb          $t0, 0x5FA($t5)
    MEM_B(0X5FA, ctx->r13) = ctx->r8;
    // 0x800A6AA8: lbu         $v0, 0x72F7($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X72F7);
    // 0x800A6AAC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800A6AB0: beq         $v0, $a2, L_800A6AD4
    if (ctx->r2 == ctx->r6) {
        // 0x800A6AB4: nop
    
            goto L_800A6AD4;
    }
    // 0x800A6AB4: nop

    // 0x800A6AB8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A6ABC: beq         $v0, $at, L_800A6C10
    if (ctx->r2 == ctx->r1) {
        // 0x800A6AC0: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800A6C10;
    }
    // 0x800A6AC0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800A6AC4: beq         $v0, $at, L_800A6C10
    if (ctx->r2 == ctx->r1) {
        // 0x800A6AC8: nop
    
            goto L_800A6C10;
    }
    // 0x800A6AC8: nop

    // 0x800A6ACC: b           L_800A6D70
    // 0x800A6AD0: nop

        goto L_800A6D70;
    // 0x800A6AD0: nop

L_800A6AD4:
    // 0x800A6AD4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800A6AD8: lh          $v1, 0x0($a3)
    ctx->r3 = MEM_H(ctx->r7, 0X0);
    // 0x800A6ADC: lui         $at, 0xC220
    ctx->r1 = S32(0XC220 << 16);
    // 0x800A6AE0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800A6AE4: bne         $v1, $zero, L_800A6B04
    if (ctx->r3 != 0) {
        // 0x800A6AE8: lui         $at, 0x4337
        ctx->r1 = S32(0X4337 << 16);
            goto L_800A6B04;
    }
    // 0x800A6AE8: lui         $at, 0x4337
    ctx->r1 = S32(0X4337 << 16);
    // 0x800A6AEC: lui         $at, 0x4296
    ctx->r1 = S32(0X4296 << 16);
    // 0x800A6AF0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A6AF4: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x800A6AF8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800A6AFC: b           L_800A6B18
    // 0x800A6B00: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
        goto L_800A6B18;
    // 0x800A6B00: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
L_800A6B04:
    // 0x800A6B04: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A6B08: lui         $at, 0x4346
    ctx->r1 = S32(0X4346 << 16);
    // 0x800A6B0C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800A6B10: nop

    // 0x800A6B14: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
L_800A6B18:
    // 0x800A6B18: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A6B1C: bne         $t6, $zero, L_800A6BD4
    if (ctx->r14 != 0) {
        // 0x800A6B20: nop
    
            goto L_800A6BD4;
    }
    // 0x800A6B20: nop

    // 0x800A6B24: lwc1        $f17, -0x7328($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X7328);
    // 0x800A6B28: lwc1        $f16, -0x7324($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7324);
    // 0x800A6B2C: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x800A6B30: mul.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x800A6B34: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800A6B38: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A6B3C: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x800A6B40: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800A6B44: mul.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x800A6B48: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A6B4C: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
    // 0x800A6B50: lui         $at, 0xC220
    ctx->r1 = S32(0XC220 << 16);
    // 0x800A6B54: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A6B58: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
    // 0x800A6B5C: sub.s       $f12, $f4, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x800A6B60: sub.s       $f14, $f6, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x800A6B64: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800A6B68: nop

    // 0x800A6B6C: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800A6B70: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A6B74: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A6B78: nop

    // 0x800A6B7C: cvt.w.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800A6B80: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x800A6B84: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800A6B88: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800A6B8C: nop

    // 0x800A6B90: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A6B94: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800A6B98: nop

    // 0x800A6B9C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800A6BA0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A6BA4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A6BA8: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x800A6BAC: cvt.w.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = CVT_W_S(ctx->f2.fl);
    // 0x800A6BB0: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x800A6BB4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800A6BB8: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x800A6BBC: bne         $v1, $zero, L_800A6BD4
    if (ctx->r3 != 0) {
        // 0x800A6BC0: cvt.s.w     $f2, $f6
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800A6BD4;
    }
    // 0x800A6BC0: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A6BC4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A6BC8: nop

    // 0x800A6BCC: sub.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x800A6BD0: sub.s       $f2, $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f16.fl;
L_800A6BD4:
    // 0x800A6BD4: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x800A6BD8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A6BDC: swc1        $f12, 0x16C($t3)
    MEM_W(0X16C, ctx->r11) = ctx->f12.u32l;
    // 0x800A6BE0: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800A6BE4: nop

    // 0x800A6BE8: swc1        $f0, 0x170($t4)
    MEM_W(0X170, ctx->r12) = ctx->f0.u32l;
    // 0x800A6BEC: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800A6BF0: nop

    // 0x800A6BF4: swc1        $f14, 0x2EC($t5)
    MEM_W(0X2EC, ctx->r13) = ctx->f14.u32l;
    // 0x800A6BF8: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800A6BFC: nop

    // 0x800A6C00: swc1        $f2, 0x2F0($t6)
    MEM_W(0X2F0, ctx->r14) = ctx->f2.u32l;
    // 0x800A6C04: lbu         $v0, 0x72F7($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X72F7);
    // 0x800A6C08: b           L_800A6D70
    // 0x800A6C0C: nop

        goto L_800A6D70;
    // 0x800A6C0C: nop

L_800A6C10:
    // 0x800A6C10: lh          $v1, 0x0($a3)
    ctx->r3 = MEM_H(ctx->r7, 0X0);
    // 0x800A6C14: nop

    // 0x800A6C18: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x800A6C1C: beq         $at, $zero, L_800A6C38
    if (ctx->r1 == 0) {
        // 0x800A6C20: lui         $at, 0x4296
        ctx->r1 = S32(0X4296 << 16);
            goto L_800A6C38;
    }
    // 0x800A6C20: lui         $at, 0x4296
    ctx->r1 = S32(0X4296 << 16);
    // 0x800A6C24: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A6C28: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x800A6C2C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800A6C30: b           L_800A6C4C
    // 0x800A6C34: nop

        goto L_800A6C4C;
    // 0x800A6C34: nop

L_800A6C38:
    // 0x800A6C38: lui         $at, 0x4337
    ctx->r1 = S32(0X4337 << 16);
    // 0x800A6C3C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A6C40: lui         $at, 0x4346
    ctx->r1 = S32(0X4346 << 16);
    // 0x800A6C44: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800A6C48: nop

L_800A6C4C:
    // 0x800A6C4C: beq         $v1, $zero, L_800A6C5C
    if (ctx->r3 == 0) {
        // 0x800A6C50: lui         $at, 0x428C
        ctx->r1 = S32(0X428C << 16);
            goto L_800A6C5C;
    }
    // 0x800A6C50: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x800A6C54: bne         $a2, $v1, L_800A6C70
    if (ctx->r6 != ctx->r3) {
        // 0x800A6C58: nop
    
            goto L_800A6C70;
    }
    // 0x800A6C58: nop

L_800A6C5C:
    // 0x800A6C5C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800A6C60: lui         $at, 0xC366
    ctx->r1 = S32(0XC366 << 16);
    // 0x800A6C64: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800A6C68: b           L_800A6C88
    // 0x800A6C6C: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
        goto L_800A6C88;
    // 0x800A6C6C: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
L_800A6C70:
    // 0x800A6C70: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x800A6C74: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800A6C78: lui         $at, 0xC28C
    ctx->r1 = S32(0XC28C << 16);
    // 0x800A6C7C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800A6C80: nop

    // 0x800A6C84: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
L_800A6C88:
    // 0x800A6C88: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A6C8C: bne         $t7, $zero, L_800A6D38
    if (ctx->r15 != 0) {
        // 0x800A6C90: nop
    
            goto L_800A6D38;
    }
    // 0x800A6C90: nop

    // 0x800A6C94: lwc1        $f17, -0x7320($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X7320);
    // 0x800A6C98: lwc1        $f16, -0x731C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X731C);
    // 0x800A6C9C: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x800A6CA0: mul.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x800A6CA4: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x800A6CA8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800A6CAC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A6CB0: mul.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x800A6CB4: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x800A6CB8: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
    // 0x800A6CBC: sub.s       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x800A6CC0: sub.s       $f14, $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f18.fl;
    // 0x800A6CC4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A6CC8: nop

    // 0x800A6CCC: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800A6CD0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A6CD4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A6CD8: nop

    // 0x800A6CDC: cvt.w.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800A6CE0: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x800A6CE4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A6CE8: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x800A6CEC: nop

    // 0x800A6CF0: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A6CF4: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800A6CF8: nop

    // 0x800A6CFC: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800A6D00: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A6D04: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A6D08: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x800A6D0C: cvt.w.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = CVT_W_S(ctx->f2.fl);
    // 0x800A6D10: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x800A6D14: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800A6D18: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x800A6D1C: beq         $at, $zero, L_800A6D38
    if (ctx->r1 == 0) {
        // 0x800A6D20: cvt.s.w     $f2, $f6
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800A6D38;
    }
    // 0x800A6D20: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A6D24: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x800A6D28: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A6D2C: nop

    // 0x800A6D30: sub.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x800A6D34: sub.s       $f2, $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f16.fl;
L_800A6D38:
    // 0x800A6D38: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800A6D3C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A6D40: swc1        $f12, 0x16C($t4)
    MEM_W(0X16C, ctx->r12) = ctx->f12.u32l;
    // 0x800A6D44: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800A6D48: nop

    // 0x800A6D4C: swc1        $f0, 0x170($t5)
    MEM_W(0X170, ctx->r13) = ctx->f0.u32l;
    // 0x800A6D50: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800A6D54: nop

    // 0x800A6D58: swc1        $f14, 0x2EC($t6)
    MEM_W(0X2EC, ctx->r14) = ctx->f14.u32l;
    // 0x800A6D5C: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800A6D60: nop

    // 0x800A6D64: swc1        $f2, 0x2F0($t7)
    MEM_W(0X2F0, ctx->r15) = ctx->f2.u32l;
    // 0x800A6D68: lbu         $v0, 0x72F7($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X72F7);
    // 0x800A6D6C: nop

L_800A6D70:
    // 0x800A6D70: beq         $t0, $v0, L_800A72F0
    if (ctx->r8 == ctx->r2) {
        // 0x800A6D74: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A72F0;
    }
    // 0x800A6D74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A6D78: jal         0x8006BFF0
    // 0x800A6D7C: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    level_header(rdram, ctx);
        goto after_5;
    // 0x800A6D7C: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    after_5:
    // 0x800A6D80: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800A6D84: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800A6D88: lw          $t8, 0x128($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X128);
    // 0x800A6D8C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800A6D90: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x800A6D94: lb          $t9, 0x4B($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X4B);
    // 0x800A6D98: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x800A6D9C: blez        $t9, L_800A6DD8
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800A6DA0: lw          $a0, 0x44($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X44);
            goto L_800A6DD8;
    }
    // 0x800A6DA0: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x800A6DA4: lb          $a1, 0x4B($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X4B);
    // 0x800A6DA8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_800A6DAC:
    // 0x800A6DAC: lw          $v0, 0x128($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X128);
    // 0x800A6DB0: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x800A6DB4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800A6DB8: slt         $at, $v0, $t2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800A6DBC: beq         $at, $zero, L_800A6DC8
    if (ctx->r1 == 0) {
        // 0x800A6DC0: addu        $t0, $t0, $v0
        ctx->r8 = ADD32(ctx->r8, ctx->r2);
            goto L_800A6DC8;
    }
    // 0x800A6DC0: addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
    // 0x800A6DC4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
L_800A6DC8:
    // 0x800A6DC8: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800A6DCC: bne         $at, $zero, L_800A6DAC
    if (ctx->r1 != 0) {
        // 0x800A6DD0: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_800A6DAC;
    }
    // 0x800A6DD0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800A6DD4: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
L_800A6DD8:
    // 0x800A6DD8: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800A6DDC: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    // 0x800A6DE0: jal         0x800597E0
    // 0x800A6DE4: sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
    get_timestamp_from_frames(rdram, ctx);
        goto after_6;
    // 0x800A6DE4: sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
    after_6:
    // 0x800A6DE8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800A6DEC: addiu       $t1, $t1, 0x729C
    ctx->r9 = ADD32(ctx->r9, 0X729C);
    // 0x800A6DF0: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800A6DF4: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800A6DF8: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800A6DFC: sb          $t3, 0x2FA($t4)
    MEM_B(0X2FA, ctx->r12) = ctx->r11;
    // 0x800A6E00: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800A6E04: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800A6E08: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x800A6E0C: sb          $t5, 0x2FB($t6)
    MEM_B(0X2FB, ctx->r14) = ctx->r13;
    // 0x800A6E10: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800A6E14: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800A6E18: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    // 0x800A6E1C: sb          $t7, 0x2FC($t8)
    MEM_B(0X2FC, ctx->r24) = ctx->r15;
    // 0x800A6E20: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x800A6E24: jal         0x800597E0
    // 0x800A6E28: nop

    get_timestamp_from_frames(rdram, ctx);
        goto after_7;
    // 0x800A6E28: nop

    after_7:
    // 0x800A6E2C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800A6E30: addiu       $t1, $t1, 0x729C
    ctx->r9 = ADD32(ctx->r9, 0X729C);
    // 0x800A6E34: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800A6E38: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800A6E3C: nop

    // 0x800A6E40: sb          $t9, 0x17A($t2)
    MEM_B(0X17A, ctx->r10) = ctx->r25;
    // 0x800A6E44: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800A6E48: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x800A6E4C: nop

    // 0x800A6E50: sb          $t3, 0x17B($t4)
    MEM_B(0X17B, ctx->r12) = ctx->r11;
    // 0x800A6E54: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800A6E58: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800A6E5C: b           L_800A72EC
    // 0x800A6E60: sb          $t5, 0x17C($t6)
    MEM_B(0X17C, ctx->r14) = ctx->r13;
        goto L_800A72EC;
    // 0x800A6E60: sb          $t5, 0x17C($t6)
    MEM_B(0X17C, ctx->r14) = ctx->r13;
L_800A6E64:
    // 0x800A6E64: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x800A6E68: lb          $a1, 0x5FD($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X5FD);
    // 0x800A6E6C: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800A6E70: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x800A6E74: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800A6E78: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800A6E7C: subu        $t8, $a1, $t7
    ctx->r24 = SUB32(ctx->r5, ctx->r15);
    // 0x800A6E80: addiu       $t9, $t8, 0xA0
    ctx->r25 = ADD32(ctx->r24, 0XA0);
    // 0x800A6E84: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800A6E88: lwc1        $f2, 0x5EC($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X5EC);
    // 0x800A6E8C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A6E90: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800A6E94: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800A6E98: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x800A6E9C: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x800A6EA0: bc1f        L_800A6EB0
    if (!c1cs) {
        // 0x800A6EA4: addiu       $t2, $a1, 0xA0
        ctx->r10 = ADD32(ctx->r5, 0XA0);
            goto L_800A6EB0;
    }
    // 0x800A6EA4: addiu       $t2, $a1, 0xA0
    ctx->r10 = ADD32(ctx->r5, 0XA0);
    // 0x800A6EA8: b           L_800A6EE8
    // 0x800A6EAC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_800A6EE8;
    // 0x800A6EAC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800A6EB0:
    // 0x800A6EB0: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800A6EB4: nop

    // 0x800A6EB8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A6EBC: sub.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x800A6EC0: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800A6EC4: nop

    // 0x800A6EC8: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800A6ECC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A6ED0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A6ED4: nop

    // 0x800A6ED8: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A6EDC: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800A6EE0: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800A6EE4: nop

L_800A6EE8:
    // 0x800A6EE8: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800A6EEC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800A6EF0: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A6EF4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800A6EF8: add.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800A6EFC: swc1        $f6, 0x5EC($v0)
    MEM_W(0X5EC, ctx->r2) = ctx->f6.u32l;
    // 0x800A6F00: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A6F04: nop

    // 0x800A6F08: lwc1        $f8, 0x60C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X60C);
    // 0x800A6F0C: nop

    // 0x800A6F10: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x800A6F14: swc1        $f10, 0x60C($v0)
    MEM_W(0X60C, ctx->r2) = ctx->f10.u32l;
    // 0x800A6F18: lbu         $t4, 0x72F7($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X72F7);
    // 0x800A6F1C: nop

    // 0x800A6F20: beq         $t0, $t4, L_800A7038
    if (ctx->r8 == ctx->r12) {
        // 0x800A6F24: nop
    
            goto L_800A7038;
    }
    // 0x800A6F24: nop

    // 0x800A6F28: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A6F2C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800A6F30: lb          $a1, 0x17D($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X17D);
    // 0x800A6F34: lwc1        $f0, 0x16C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X16C);
    // 0x800A6F38: addu        $t5, $a1, $a0
    ctx->r13 = ADD32(ctx->r5, ctx->r4);
    // 0x800A6F3C: addiu       $t6, $t5, 0xA0
    ctx->r14 = ADD32(ctx->r13, 0XA0);
    // 0x800A6F40: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800A6F44: addiu       $t7, $a1, 0xA0
    ctx->r15 = ADD32(ctx->r5, 0XA0);
    // 0x800A6F48: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A6F4C: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x800A6F50: nop

    // 0x800A6F54: bc1f        L_800A6F64
    if (!c1cs) {
        // 0x800A6F58: nop
    
            goto L_800A6F64;
    }
    // 0x800A6F58: nop

    // 0x800A6F5C: b           L_800A6F9C
    // 0x800A6F60: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_800A6F9C;
    // 0x800A6F60: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800A6F64:
    // 0x800A6F64: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800A6F68: nop

    // 0x800A6F6C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A6F70: sub.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x800A6F74: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A6F78: nop

    // 0x800A6F7C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800A6F80: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A6F84: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A6F88: nop

    // 0x800A6F8C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A6F90: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A6F94: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800A6F98: nop

L_800A6F9C:
    // 0x800A6F9C: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x800A6FA0: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800A6FA4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A6FA8: sub.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x800A6FAC: swc1        $f4, 0x16C($v0)
    MEM_W(0X16C, ctx->r2) = ctx->f4.u32l;
    // 0x800A6FB0: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A6FB4: nop

    // 0x800A6FB8: lb          $a1, 0x2FD($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X2FD);
    // 0x800A6FBC: lwc1        $f2, 0x2EC($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X2EC);
    // 0x800A6FC0: subu        $t9, $a1, $a0
    ctx->r25 = SUB32(ctx->r5, ctx->r4);
    // 0x800A6FC4: addiu       $t2, $t9, 0xA0
    ctx->r10 = ADD32(ctx->r25, 0XA0);
    // 0x800A6FC8: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x800A6FCC: addiu       $t3, $a1, 0xA0
    ctx->r11 = ADD32(ctx->r5, 0XA0);
    // 0x800A6FD0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A6FD4: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x800A6FD8: nop

    // 0x800A6FDC: bc1f        L_800A6FEC
    if (!c1cs) {
        // 0x800A6FE0: nop
    
            goto L_800A6FEC;
    }
    // 0x800A6FE0: nop

    // 0x800A6FE4: b           L_800A7024
    // 0x800A6FE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_800A7024;
    // 0x800A6FE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800A6FEC:
    // 0x800A6FEC: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x800A6FF0: nop

    // 0x800A6FF4: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A6FF8: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x800A6FFC: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800A7000: nop

    // 0x800A7004: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800A7008: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A700C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A7010: nop

    // 0x800A7014: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800A7018: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800A701C: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x800A7020: nop

L_800A7024:
    // 0x800A7024: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x800A7028: nop

    // 0x800A702C: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A7030: add.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x800A7034: swc1        $f6, 0x2EC($v0)
    MEM_W(0X2EC, ctx->r2) = ctx->f6.u32l;
L_800A7038:
    // 0x800A7038: beq         $a2, $zero, L_800A7104
    if (ctx->r6 == 0) {
        // 0x800A703C: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_800A7104;
    }
    // 0x800A703C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A7040: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800A7044: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x800A7048: sb          $a2, 0x5FA($t5)
    MEM_B(0X5FA, ctx->r13) = ctx->r6;
    // 0x800A704C: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800A7050: addiu       $t6, $zero, -0x78
    ctx->r14 = ADD32(0, -0X78);
    // 0x800A7054: sb          $t6, 0x5FB($t7)
    MEM_B(0X5FB, ctx->r15) = ctx->r14;
    // 0x800A7058: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800A705C: addiu       $a1, $a1, 0x7300
    ctx->r5 = ADD32(ctx->r5, 0X7300);
    // 0x800A7060: sb          $zero, 0x5FC($t8)
    MEM_B(0X5FC, ctx->r24) = 0;
    // 0x800A7064: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x800A7068: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x800A706C: bne         $t9, $zero, L_800A7104
    if (ctx->r25 != 0) {
        // 0x800A7070: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_800A7104;
    }
    // 0x800A7070: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x800A7074: bne         $t2, $at, L_800A70E0
    if (ctx->r10 != ctx->r1) {
        // 0x800A7078: nop
    
            goto L_800A70E0;
    }
    // 0x800A7078: nop

    // 0x800A707C: lh          $v1, 0x1AC($a3)
    ctx->r3 = MEM_H(ctx->r7, 0X1AC);
    // 0x800A7080: addiu       $a0, $zero, 0x146
    ctx->r4 = ADD32(0, 0X146);
    // 0x800A7084: beq         $v1, $t0, L_800A70A4
    if (ctx->r3 == ctx->r8) {
        // 0x800A7088: nop
    
            goto L_800A70A4;
    }
    // 0x800A7088: nop

    // 0x800A708C: beq         $v1, $a2, L_800A70A4
    if (ctx->r3 == ctx->r6) {
        // 0x800A7090: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800A70A4;
    }
    // 0x800A7090: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A7094: beq         $v1, $at, L_800A70B8
    if (ctx->r3 == ctx->r1) {
        // 0x800A7098: addiu       $a0, $zero, 0x14C
        ctx->r4 = ADD32(0, 0X14C);
            goto L_800A70B8;
    }
    // 0x800A7098: addiu       $a0, $zero, 0x14C
    ctx->r4 = ADD32(0, 0X14C);
    // 0x800A709C: b           L_800A70CC
    // 0x800A70A0: addiu       $a0, $zero, 0x14D
    ctx->r4 = ADD32(0, 0X14D);
        goto L_800A70CC;
    // 0x800A70A0: addiu       $a0, $zero, 0x14D
    ctx->r4 = ADD32(0, 0X14D);
L_800A70A4:
    // 0x800A70A4: jal         0x80001D04
    // 0x800A70A8: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    sound_play(rdram, ctx);
        goto after_8;
    // 0x800A70A8: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    after_8:
    // 0x800A70AC: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800A70B0: b           L_800A7104
    // 0x800A70B4: nop

        goto L_800A7104;
    // 0x800A70B4: nop

L_800A70B8:
    // 0x800A70B8: jal         0x80001D04
    // 0x800A70BC: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    sound_play(rdram, ctx);
        goto after_9;
    // 0x800A70BC: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    after_9:
    // 0x800A70C0: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800A70C4: b           L_800A7104
    // 0x800A70C8: nop

        goto L_800A7104;
    // 0x800A70C8: nop

L_800A70CC:
    // 0x800A70CC: jal         0x80001D04
    // 0x800A70D0: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    sound_play(rdram, ctx);
        goto after_10;
    // 0x800A70D0: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    after_10:
    // 0x800A70D4: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800A70D8: b           L_800A7104
    // 0x800A70DC: nop

        goto L_800A7104;
    // 0x800A70DC: nop

L_800A70E0:
    // 0x800A70E0: jal         0x8001B674
    // 0x800A70E4: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    timetrial_ghost_staff(rdram, ctx);
        goto after_11;
    // 0x800A70E4: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    after_11:
    // 0x800A70E8: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800A70EC: bne         $v0, $zero, L_800A7104
    if (ctx->r2 != 0) {
        // 0x800A70F0: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_800A7104;
    }
    // 0x800A70F0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800A70F4: jal         0x800A72FC
    // 0x800A70F8: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    hud_time_trial_message(rdram, ctx);
        goto after_12;
    // 0x800A70F8: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    after_12:
    // 0x800A70FC: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800A7100: nop

L_800A7104:
    // 0x800A7104: jal         0x800A6460
    // 0x800A7108: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    hud_finish_position(rdram, ctx);
        goto after_13;
    // 0x800A7108: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_13:
    // 0x800A710C: b           L_800A72F0
    // 0x800A7110: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A72F0;
    // 0x800A7110: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A7114:
    // 0x800A7114: lb          $t3, 0x5FB($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X5FB);
    // 0x800A7118: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x800A711C: addiu       $t7, $zero, -0x78
    ctx->r15 = ADD32(0, -0X78);
    // 0x800A7120: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800A7124: sb          $t5, 0x5FB($v0)
    MEM_B(0X5FB, ctx->r2) = ctx->r13;
    // 0x800A7128: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A712C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800A7130: lb          $t6, 0x5FB($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X5FB);
    // 0x800A7134: nop

    // 0x800A7138: slti        $at, $t6, 0x78
    ctx->r1 = SIGNED(ctx->r14) < 0X78 ? 1 : 0;
    // 0x800A713C: bne         $at, $zero, L_800A7168
    if (ctx->r1 != 0) {
        // 0x800A7140: nop
    
            goto L_800A7168;
    }
    // 0x800A7140: nop

    // 0x800A7144: sb          $t7, 0x5FB($v0)
    MEM_B(0X5FB, ctx->r2) = ctx->r15;
    // 0x800A7148: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A714C: nop

    // 0x800A7150: lb          $t8, 0x5FC($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X5FC);
    // 0x800A7154: nop

    // 0x800A7158: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800A715C: sb          $t9, 0x5FC($v0)
    MEM_B(0X5FC, ctx->r2) = ctx->r25;
    // 0x800A7160: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A7164: nop

L_800A7168:
    // 0x800A7168: lb          $t2, 0x5FC($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X5FC);
    // 0x800A716C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x800A7170: bne         $a2, $t2, L_800A71DC
    if (ctx->r6 != ctx->r10) {
        // 0x800A7174: nop
    
            goto L_800A71DC;
    }
    // 0x800A7174: nop

    // 0x800A7178: lbu         $t3, 0x72F7($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X72F7);
    // 0x800A717C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800A7180: beq         $t0, $t3, L_800A71B0
    if (ctx->r8 == ctx->r11) {
        // 0x800A7184: addiu       $t4, $zero, 0x3
        ctx->r12 = ADD32(0, 0X3);
            goto L_800A71B0;
    }
    // 0x800A7184: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x800A7188: jal         0x8009F1C4
    // 0x800A718C: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    is_in_two_player_adventure(rdram, ctx);
        goto after_14;
    // 0x800A718C: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    after_14:
    // 0x800A7190: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800A7194: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800A7198: beq         $v0, $zero, L_800A71D0
    if (ctx->r2 == 0) {
        // 0x800A719C: addiu       $t1, $t1, 0x729C
        ctx->r9 = ADD32(ctx->r9, 0X729C);
            goto L_800A71D0;
    }
    // 0x800A719C: addiu       $t1, $t1, 0x729C
    ctx->r9 = ADD32(ctx->r9, 0X729C);
    // 0x800A71A0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A71A4: lw          $v0, 0x729C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X729C);
    // 0x800A71A8: nop

    // 0x800A71AC: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
L_800A71B0:
    // 0x800A71B0: sb          $t4, 0x5FA($v0)
    MEM_B(0X5FA, ctx->r2) = ctx->r12;
    // 0x800A71B4: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    // 0x800A71B8: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x800A71BC: jal         0x80001D04
    // 0x800A71C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_15;
    // 0x800A71C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x800A71C4: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800A71C8: b           L_800A71DC
    // 0x800A71CC: nop

        goto L_800A71DC;
    // 0x800A71CC: nop

L_800A71D0:
    // 0x800A71D0: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800A71D4: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x800A71D8: sb          $t5, 0x5FA($t6)
    MEM_B(0X5FA, ctx->r14) = ctx->r13;
L_800A71DC:
    // 0x800A71DC: jal         0x800A6460
    // 0x800A71E0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    hud_finish_position(rdram, ctx);
        goto after_16;
    // 0x800A71E0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_16:
    // 0x800A71E4: b           L_800A72F0
    // 0x800A71E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A72F0;
    // 0x800A71E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A71EC:
    // 0x800A71EC: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x800A71F0: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x800A71F4: bne         $t7, $at, L_800A7204
    if (ctx->r15 != ctx->r1) {
        // 0x800A71F8: addiu       $t8, $zero, 0x4
        ctx->r24 = ADD32(0, 0X4);
            goto L_800A7204;
    }
    // 0x800A71F8: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x800A71FC: b           L_800A72A0
    // 0x800A7200: sb          $t8, 0x5FA($v0)
    MEM_B(0X5FA, ctx->r2) = ctx->r24;
        goto L_800A72A0;
    // 0x800A7200: sb          $t8, 0x5FA($v0)
    MEM_B(0X5FA, ctx->r2) = ctx->r24;
L_800A7204:
    // 0x800A7204: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x800A7208: lwc1        $f10, 0x5EC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X5EC);
    // 0x800A720C: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x800A7210: subu        $t2, $t2, $t9
    ctx->r10 = SUB32(ctx->r10, ctx->r25);
    // 0x800A7214: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800A7218: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x800A721C: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x800A7220: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x800A7224: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A7228: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x800A722C: sub.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x800A7230: swc1        $f4, 0x5EC($v0)
    MEM_W(0X5EC, ctx->r2) = ctx->f4.u32l;
    // 0x800A7234: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A7238: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A723C: lwc1        $f6, 0x60C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X60C);
    // 0x800A7240: nop

    // 0x800A7244: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800A7248: swc1        $f8, 0x60C($v0)
    MEM_W(0X60C, ctx->r2) = ctx->f8.u32l;
    // 0x800A724C: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A7250: nop

    // 0x800A7254: lwc1        $f10, 0x5EC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X5EC);
    // 0x800A7258: nop

    // 0x800A725C: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x800A7260: nop

    // 0x800A7264: bc1f        L_800A7278
    if (!c1cs) {
        // 0x800A7268: nop
    
            goto L_800A7278;
    }
    // 0x800A7268: nop

    // 0x800A726C: sb          $t3, 0x5FA($v0)
    MEM_B(0X5FA, ctx->r2) = ctx->r11;
    // 0x800A7270: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A7274: nop

L_800A7278:
    // 0x800A7278: lwc1        $f6, 0x16C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X16C);
    // 0x800A727C: nop

    // 0x800A7280: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800A7284: swc1        $f8, 0x16C($v0)
    MEM_W(0X16C, ctx->r2) = ctx->f8.u32l;
    // 0x800A7288: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A728C: nop

    // 0x800A7290: lwc1        $f10, 0x2EC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X2EC);
    // 0x800A7294: nop

    // 0x800A7298: add.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x800A729C: swc1        $f4, 0x2EC($v0)
    MEM_W(0X2EC, ctx->r2) = ctx->f4.u32l;
L_800A72A0:
    // 0x800A72A0: jal         0x800A6460
    // 0x800A72A4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    hud_finish_position(rdram, ctx);
        goto after_17;
    // 0x800A72A4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_17:
    // 0x800A72A8: b           L_800A72F0
    // 0x800A72AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A72F0;
    // 0x800A72AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A72B0:
    // 0x800A72B0: lh          $t4, 0x0($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X0);
    // 0x800A72B4: lb          $t5, 0xC($v1)
    ctx->r13 = MEM_B(ctx->r3, 0XC);
    // 0x800A72B8: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x800A72BC: bne         $t4, $t5, L_800A72CC
    if (ctx->r12 != ctx->r13) {
        // 0x800A72C0: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_800A72CC;
    }
    // 0x800A72C0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800A72C4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800A72C8: sb          $t6, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r14;
L_800A72CC:
    // 0x800A72CC: sb          $t7, 0x5FA($v0)
    MEM_B(0X5FA, ctx->r2) = ctx->r15;
    // 0x800A72D0: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800A72D4: jal         0x800A6460
    // 0x800A72D8: sb          $zero, 0x5FB($t8)
    MEM_B(0X5FB, ctx->r24) = 0;
    hud_finish_position(rdram, ctx);
        goto after_18;
    // 0x800A72D8: sb          $zero, 0x5FB($t8)
    MEM_B(0X5FB, ctx->r24) = 0;
    after_18:
    // 0x800A72DC: b           L_800A72F0
    // 0x800A72E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A72F0;
    // 0x800A72E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A72E4:
    // 0x800A72E4: jal         0x800A6460
    // 0x800A72E8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    hud_finish_position(rdram, ctx);
        goto after_19;
    // 0x800A72E8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_19:
L_800A72EC:
    // 0x800A72EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A72F0:
    // 0x800A72F0: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x800A72F4: jr          $ra
    // 0x800A72F8: nop

    return;
    // 0x800A72F8: nop

;}
RECOMP_FUNC void hud_time_trial_message(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A72FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A7300: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A7304: jal         0x8006ECD0
    // 0x800A7308: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x800A7308: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A730C: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x800A7310: nop

    // 0x800A7314: beq         $v1, $zero, L_800A7380
    if (ctx->r3 == 0) {
        // 0x800A7318: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A7380;
    }
    // 0x800A7318: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A731C: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x800A7320: nop

    // 0x800A7324: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800A7328: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800A732C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800A7330: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x800A7334: lb          $t9, 0x58($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X58);
    // 0x800A7338: nop

    // 0x800A733C: andi        $t0, $t9, 0x80
    ctx->r8 = ctx->r25 & 0X80;
    // 0x800A7340: beq         $t0, $zero, L_800A736C
    if (ctx->r8 == 0) {
        // 0x800A7344: nop
    
            goto L_800A736C;
    }
    // 0x800A7344: nop

    // 0x800A7348: jal         0x8006BFD8
    // 0x800A734C: nop

    level_type(rdram, ctx);
        goto after_1;
    // 0x800A734C: nop

    after_1:
    // 0x800A7350: bne         $v0, $zero, L_800A736C
    if (ctx->r2 != 0) {
        // 0x800A7354: addiu       $a0, $zero, 0x145
        ctx->r4 = ADD32(0, 0X145);
            goto L_800A736C;
    }
    // 0x800A7354: addiu       $a0, $zero, 0x145
    ctx->r4 = ADD32(0, 0X145);
    // 0x800A7358: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A735C: jal         0x80001D04
    // 0x800A7360: addiu       $a1, $a1, 0x7300
    ctx->r5 = ADD32(ctx->r5, 0X7300);
    sound_play(rdram, ctx);
        goto after_2;
    // 0x800A7360: addiu       $a1, $a1, 0x7300
    ctx->r5 = ADD32(ctx->r5, 0X7300);
    after_2:
    // 0x800A7364: b           L_800A7380
    // 0x800A7368: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A7380;
    // 0x800A7368: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A736C:
    // 0x800A736C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A7370: addiu       $a1, $a1, 0x7300
    ctx->r5 = ADD32(ctx->r5, 0X7300);
    // 0x800A7374: jal         0x80001D04
    // 0x800A7378: addiu       $a0, $zero, 0x102
    ctx->r4 = ADD32(0, 0X102);
    sound_play(rdram, ctx);
        goto after_3;
    // 0x800A7378: addiu       $a0, $zero, 0x102
    ctx->r4 = ADD32(0, 0X102);
    after_3:
    // 0x800A737C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A7380:
    // 0x800A7380: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A7384: jr          $ra
    // 0x800A7388: nop

    return;
    // 0x800A7388: nop

;}
RECOMP_FUNC void hud_time_trial_finish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A738C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A7390: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A7394: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A7398: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A739C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A73A0: lbu         $t6, 0x1DA($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1DA);
    // 0x800A73A4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800A73A8: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x800A73AC: beq         $at, $zero, L_800A76D8
    if (ctx->r1 == 0) {
        // 0x800A73B0: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_800A76D8;
    }
    // 0x800A73B0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800A73B4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A73B8: addu        $at, $at, $t6
    gpr jr_addend_800A73C4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800A73BC: lw          $t6, -0x7318($at)
    ctx->r14 = ADD32(ctx->r1, -0X7318);
    // 0x800A73C0: nop

    // 0x800A73C4: jr          $t6
    // 0x800A73C8: nop

    switch (jr_addend_800A73C4 >> 2) {
        case 0: goto L_800A73CC; break;
        case 1: goto L_800A7498; break;
        case 2: goto L_800A7570; break;
        case 3: goto L_800A7630; break;
        case 4: goto L_800A76B4; break;
        default: switch_error(__func__, 0x800A73C4, 0x800E8CE8);
    }
    // 0x800A73C8: nop

L_800A73CC:
    // 0x800A73CC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800A73D0: addiu       $v1, $v1, 0x2CF0
    ctx->r3 = ADD32(ctx->r3, 0X2CF0);
    // 0x800A73D4: addiu       $t7, $zero, 0x7F
    ctx->r15 = ADD32(0, 0X7F);
    // 0x800A73D8: sb          $t7, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r15;
    // 0x800A73DC: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x800A73E0: lh          $t8, 0x0($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X0);
    // 0x800A73E4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x800A73E8: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x800A73EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A73F0: jal         0x80001D04
    // 0x800A73F4: sb          $t8, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r24;
    sound_play(rdram, ctx);
        goto after_0;
    // 0x800A73F4: sb          $t8, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r24;
    after_0:
    // 0x800A73F8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A73FC: lw          $v1, 0x72CC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X72CC);
    // 0x800A7400: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800A7404: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A7408: beq         $v1, $zero, L_800A7418
    if (ctx->r3 == 0) {
        // 0x800A740C: addiu       $t0, $t0, 0x729C
        ctx->r8 = ADD32(ctx->r8, 0X729C);
            goto L_800A7418;
    }
    // 0x800A740C: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A7410: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A7414: bne         $v1, $at, L_800A7438
    if (ctx->r3 != ctx->r1) {
        // 0x800A7418: lui         $at, 0xC348
        ctx->r1 = S32(0XC348 << 16);
            goto L_800A7438;
    }
L_800A7418:
    // 0x800A7418: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x800A741C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A7420: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800A7424: nop

    // 0x800A7428: swc1        $f4, 0x1CC($t9)
    MEM_W(0X1CC, ctx->r25) = ctx->f4.u32l;
    // 0x800A742C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800A7430: b           L_800A7488
    // 0x800A7434: sb          $zero, 0x1DD($t1)
    MEM_B(0X1DD, ctx->r9) = 0;
        goto L_800A7488;
    // 0x800A7434: sb          $zero, 0x1DD($t1)
    MEM_B(0X1DD, ctx->r9) = 0;
L_800A7438:
    // 0x800A7438: lh          $v0, 0x0($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X0);
    // 0x800A743C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A7440: beq         $v0, $zero, L_800A7450
    if (ctx->r2 == 0) {
        // 0x800A7444: addiu       $t2, $zero, -0x50
        ctx->r10 = ADD32(0, -0X50);
            goto L_800A7450;
    }
    // 0x800A7444: addiu       $t2, $zero, -0x50
    ctx->r10 = ADD32(0, -0X50);
    // 0x800A7448: bne         $v0, $at, L_800A746C
    if (ctx->r2 != ctx->r1) {
        // 0x800A744C: addiu       $t5, $zero, 0x50
        ctx->r13 = ADD32(0, 0X50);
            goto L_800A746C;
    }
    // 0x800A744C: addiu       $t5, $zero, 0x50
    ctx->r13 = ADD32(0, 0X50);
L_800A7450:
    // 0x800A7450: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800A7454: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x800A7458: sb          $t2, 0x1DD($t3)
    MEM_B(0X1DD, ctx->r11) = ctx->r10;
    // 0x800A745C: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800A7460: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A7464: b           L_800A7488
    // 0x800A7468: swc1        $f6, 0x1CC($t4)
    MEM_W(0X1CC, ctx->r12) = ctx->f6.u32l;
        goto L_800A7488;
    // 0x800A7468: swc1        $f6, 0x1CC($t4)
    MEM_W(0X1CC, ctx->r12) = ctx->f6.u32l;
L_800A746C:
    // 0x800A746C: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800A7470: lui         $at, 0xC220
    ctx->r1 = S32(0XC220 << 16);
    // 0x800A7474: sb          $t5, 0x1DD($t6)
    MEM_B(0X1DD, ctx->r14) = ctx->r13;
    // 0x800A7478: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800A747C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A7480: nop

    // 0x800A7484: swc1        $f8, 0x1CC($t7)
    MEM_W(0X1CC, ctx->r15) = ctx->f8.u32l;
L_800A7488:
    // 0x800A7488: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800A748C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800A7490: b           L_800A76D8
    // 0x800A7494: sb          $t8, 0x1DA($t9)
    MEM_B(0X1DA, ctx->r25) = ctx->r24;
        goto L_800A76D8;
    // 0x800A7494: sb          $t8, 0x1DA($t9)
    MEM_B(0X1DA, ctx->r25) = ctx->r24;
L_800A7498:
    // 0x800A7498: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x800A749C: subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // 0x800A74A0: lb          $a0, 0x1DD($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X1DD);
    // 0x800A74A4: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800A74A8: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x800A74AC: subu        $t1, $a0, $v1
    ctx->r9 = SUB32(ctx->r4, ctx->r3);
    // 0x800A74B0: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x800A74B4: lwc1        $f0, 0x1CC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1CC);
    // 0x800A74B8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A74BC: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x800A74C0: nop

    // 0x800A74C4: bc1f        L_800A74E4
    if (!c1cs) {
        // 0x800A74C8: nop
    
            goto L_800A74E4;
    }
    // 0x800A74C8: nop

    // 0x800A74CC: mtc1        $v1, $f18
    ctx->f18.u32l = ctx->r3;
    // 0x800A74D0: nop

    // 0x800A74D4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800A74D8: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x800A74DC: b           L_800A7544
    // 0x800A74E0: swc1        $f6, 0x1CC($v0)
    MEM_W(0X1CC, ctx->r2) = ctx->f6.u32l;
        goto L_800A7544;
    // 0x800A74E0: swc1        $f6, 0x1CC($v0)
    MEM_W(0X1CC, ctx->r2) = ctx->f6.u32l;
L_800A74E4:
    // 0x800A74E4: mtc1        $a0, $f8
    ctx->f8.u32l = ctx->r4;
    // 0x800A74E8: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x800A74EC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A74F0: addiu       $t4, $zero, -0x78
    ctx->r12 = ADD32(0, -0X78);
    // 0x800A74F4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A74F8: swc1        $f10, 0x1CC($v0)
    MEM_W(0X1CC, ctx->r2) = ctx->f10.u32l;
    // 0x800A74FC: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800A7500: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A7504: sb          $t2, 0x1DA($t3)
    MEM_B(0X1DA, ctx->r11) = ctx->r10;
    // 0x800A7508: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x800A750C: nop

    // 0x800A7510: sb          $t4, 0x1DB($t5)
    MEM_B(0X1DB, ctx->r13) = ctx->r12;
    // 0x800A7514: lw          $t6, 0x7300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7300);
    // 0x800A7518: nop

    // 0x800A751C: bne         $t6, $zero, L_800A7544
    if (ctx->r14 != 0) {
        // 0x800A7520: nop
    
            goto L_800A7544;
    }
    // 0x800A7520: nop

    // 0x800A7524: lbu         $t7, 0x7331($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X7331);
    // 0x800A7528: nop

    // 0x800A752C: bne         $t7, $zero, L_800A7544
    if (ctx->r15 != 0) {
        // 0x800A7530: nop
    
            goto L_800A7544;
    }
    // 0x800A7530: nop

    // 0x800A7534: jal         0x800A72FC
    // 0x800A7538: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    hud_time_trial_message(rdram, ctx);
        goto after_1;
    // 0x800A7538: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x800A753C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A7540: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
L_800A7544:
    // 0x800A7544: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A7548: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A754C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A7550: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A7554: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A7558: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A755C: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A7560: jal         0x800AAB5C
    // 0x800A7564: addiu       $a3, $a3, 0x1C0
    ctx->r7 = ADD32(ctx->r7, 0X1C0);
    hud_element_render(rdram, ctx);
        goto after_2;
    // 0x800A7564: addiu       $a3, $a3, 0x1C0
    ctx->r7 = ADD32(ctx->r7, 0X1C0);
    after_2:
    // 0x800A7568: b           L_800A76DC
    // 0x800A756C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A76DC;
    // 0x800A756C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A7570:
    // 0x800A7570: lb          $t8, 0x1DB($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X1DB);
    // 0x800A7574: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x800A7578: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x800A757C: sb          $t9, 0x1DB($v0)
    MEM_B(0X1DB, ctx->r2) = ctx->r25;
    // 0x800A7580: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A7584: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A7588: lb          $t1, 0x1DB($v0)
    ctx->r9 = MEM_B(ctx->r2, 0X1DB);
    // 0x800A758C: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x800A7590: slti        $at, $t1, 0x78
    ctx->r1 = SIGNED(ctx->r9) < 0X78 ? 1 : 0;
    // 0x800A7594: bne         $at, $zero, L_800A7608
    if (ctx->r1 != 0) {
        // 0x800A7598: nop
    
            goto L_800A7608;
    }
    // 0x800A7598: nop

    // 0x800A759C: sb          $t2, 0x1DA($v0)
    MEM_B(0X1DA, ctx->r2) = ctx->r10;
    // 0x800A75A0: lw          $v1, 0x72CC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X72CC);
    // 0x800A75A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A75A8: beq         $v1, $zero, L_800A75B8
    if (ctx->r3 == 0) {
        // 0x800A75AC: addiu       $t3, $zero, 0x38
        ctx->r11 = ADD32(0, 0X38);
            goto L_800A75B8;
    }
    // 0x800A75AC: addiu       $t3, $zero, 0x38
    ctx->r11 = ADD32(0, 0X38);
    // 0x800A75B0: bne         $v1, $at, L_800A75C4
    if (ctx->r3 != ctx->r1) {
        // 0x800A75B4: nop
    
            goto L_800A75C4;
    }
    // 0x800A75B4: nop

L_800A75B8:
    // 0x800A75B8: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800A75BC: b           L_800A75F4
    // 0x800A75C0: sb          $t3, 0x1DD($t4)
    MEM_B(0X1DD, ctx->r12) = ctx->r11;
        goto L_800A75F4;
    // 0x800A75C0: sb          $t3, 0x1DD($t4)
    MEM_B(0X1DD, ctx->r12) = ctx->r11;
L_800A75C4:
    // 0x800A75C4: lh          $v0, 0x0($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X0);
    // 0x800A75C8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A75CC: beq         $v0, $zero, L_800A75DC
    if (ctx->r2 == 0) {
        // 0x800A75D0: addiu       $t5, $zero, 0x38
        ctx->r13 = ADD32(0, 0X38);
            goto L_800A75DC;
    }
    // 0x800A75D0: addiu       $t5, $zero, 0x38
    ctx->r13 = ADD32(0, 0X38);
    // 0x800A75D4: bne         $v0, $at, L_800A75E8
    if (ctx->r2 != ctx->r1) {
        // 0x800A75D8: nop
    
            goto L_800A75E8;
    }
    // 0x800A75D8: nop

L_800A75DC:
    // 0x800A75DC: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800A75E0: b           L_800A75F4
    // 0x800A75E4: sb          $t5, 0x1DD($t6)
    MEM_B(0X1DD, ctx->r14) = ctx->r13;
        goto L_800A75F4;
    // 0x800A75E4: sb          $t5, 0x1DD($t6)
    MEM_B(0X1DD, ctx->r14) = ctx->r13;
L_800A75E8:
    // 0x800A75E8: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800A75EC: addiu       $t7, $zero, -0x28
    ctx->r15 = ADD32(0, -0X28);
    // 0x800A75F0: sb          $t7, 0x1DD($t8)
    MEM_B(0X1DD, ctx->r24) = ctx->r15;
L_800A75F4:
    // 0x800A75F4: jal         0x80001D04
    // 0x800A75F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_3;
    // 0x800A75F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x800A75FC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A7600: lw          $v0, 0x729C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X729C);
    // 0x800A7604: nop

L_800A7608:
    // 0x800A7608: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A760C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A7610: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A7614: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A7618: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A761C: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A7620: jal         0x800AAB5C
    // 0x800A7624: addiu       $a3, $v0, 0x1C0
    ctx->r7 = ADD32(ctx->r2, 0X1C0);
    hud_element_render(rdram, ctx);
        goto after_4;
    // 0x800A7624: addiu       $a3, $v0, 0x1C0
    ctx->r7 = ADD32(ctx->r2, 0X1C0);
    after_4:
    // 0x800A7628: b           L_800A76DC
    // 0x800A762C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A76DC;
    // 0x800A762C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A7630:
    // 0x800A7630: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x800A7634: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x800A7638: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800A763C: addu        $t9, $t9, $a1
    ctx->r25 = ADD32(ctx->r25, ctx->r5);
    // 0x800A7640: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x800A7644: lwc1        $f16, 0x1CC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X1CC);
    // 0x800A7648: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800A764C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A7650: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A7654: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x800A7658: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A765C: swc1        $f6, 0x1CC($v0)
    MEM_W(0X1CC, ctx->r2) = ctx->f6.u32l;
    // 0x800A7660: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A7664: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x800A7668: lb          $t1, 0x1DD($v0)
    ctx->r9 = MEM_B(ctx->r2, 0X1DD);
    // 0x800A766C: lwc1        $f8, 0x1CC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1CC);
    // 0x800A7670: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x800A7674: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A7678: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A767C: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A7680: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A7684: c.lt.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl < ctx->f18.fl;
    // 0x800A7688: nop

    // 0x800A768C: bc1f        L_800A76A4
    if (!c1cs) {
        // 0x800A7690: nop
    
            goto L_800A76A4;
    }
    // 0x800A7690: nop

    // 0x800A7694: sb          $t2, 0x1DA($v0)
    MEM_B(0X1DA, ctx->r2) = ctx->r10;
    // 0x800A7698: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A769C: lw          $v0, 0x729C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X729C);
    // 0x800A76A0: nop

L_800A76A4:
    // 0x800A76A4: jal         0x800AAB5C
    // 0x800A76A8: addiu       $a3, $v0, 0x1C0
    ctx->r7 = ADD32(ctx->r2, 0X1C0);
    hud_element_render(rdram, ctx);
        goto after_5;
    // 0x800A76A8: addiu       $a3, $v0, 0x1C0
    ctx->r7 = ADD32(ctx->r2, 0X1C0);
    after_5:
    // 0x800A76AC: b           L_800A76DC
    // 0x800A76B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A76DC;
    // 0x800A76B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A76B4:
    // 0x800A76B4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800A76B8: addiu       $v1, $v1, 0x2CF0
    ctx->r3 = ADD32(ctx->r3, 0X2CF0);
    // 0x800A76BC: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800A76C0: sb          $t3, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r11;
    // 0x800A76C4: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x800A76C8: sb          $t4, 0x1DA($v0)
    MEM_B(0X1DA, ctx->r2) = ctx->r12;
    // 0x800A76CC: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x800A76D0: nop

    // 0x800A76D4: sb          $zero, 0x1DB($t5)
    MEM_B(0X1DB, ctx->r13) = 0;
L_800A76D8:
    // 0x800A76D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A76DC:
    // 0x800A76DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A76E0: jr          $ra
    // 0x800A76E4: nop

    return;
    // 0x800A76E4: nop

;}
RECOMP_FUNC void hud_balloons(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A76E8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800A76EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A76F0: jal         0x8006ECD0
    // 0x800A76F4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x800A76F4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A76F8: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x800A76FC: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x800A7700: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A7704: bne         $t6, $zero, L_800A7714
    if (ctx->r14 != 0) {
        // 0x800A7708: addiu       $t7, $zero, 0x286
        ctx->r15 = ADD32(0, 0X286);
            goto L_800A7714;
    }
    // 0x800A7708: addiu       $t7, $zero, 0x286
    ctx->r15 = ADD32(0, 0X286);
    // 0x800A770C: b           L_800A771C
    // 0x800A7710: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
        goto L_800A771C;
    // 0x800A7710: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
L_800A7714:
    // 0x800A7714: addiu       $t8, $zero, 0x348
    ctx->r24 = ADD32(0, 0X348);
    // 0x800A7718: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
L_800A771C:
    // 0x800A771C: lw          $t9, 0x10($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X10);
    // 0x800A7720: nop

    // 0x800A7724: andi        $t2, $t9, 0x4
    ctx->r10 = ctx->r25 & 0X4;
    // 0x800A7728: beq         $t2, $zero, L_800A773C
    if (ctx->r10 == 0) {
        // 0x800A772C: lui         $t4, 0x8012
        ctx->r12 = S32(0X8012 << 16);
            goto L_800A773C;
    }
    // 0x800A772C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800A7730: lw          $t4, 0x729C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X729C);
    // 0x800A7734: addiu       $t3, $zero, 0x45
    ctx->r11 = ADD32(0, 0X45);
    // 0x800A7738: sh          $t3, 0x266($t4)
    MEM_H(0X266, ctx->r12) = ctx->r11;
L_800A773C:
    // 0x800A773C: jal         0x8001E474
    // 0x800A7740: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    cutscene_id(rdram, ctx);
        goto after_1;
    // 0x800A7740: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_1:
    // 0x800A7744: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800A7748: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800A774C: bne         $v0, $at, L_800A7784
    if (ctx->r2 != ctx->r1) {
        // 0x800A7750: nop
    
            goto L_800A7784;
    }
    // 0x800A7750: nop

    // 0x800A7754: jal         0x8001AE88
    // 0x800A7758: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    get_balloon_cutscene_timer(rdram, ctx);
        goto after_2;
    // 0x800A7758: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_2:
    // 0x800A775C: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800A7760: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800A7764: sltu        $at, $v0, $t5
    ctx->r1 = ctx->r2 < ctx->r13 ? 1 : 0;
    // 0x800A7768: beq         $at, $zero, L_800A7784
    if (ctx->r1 == 0) {
        // 0x800A776C: nop
    
            goto L_800A7784;
    }
    // 0x800A776C: nop

    // 0x800A7770: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800A7774: nop

    // 0x800A7778: lh          $v1, 0x0($t6)
    ctx->r3 = MEM_H(ctx->r14, 0X0);
    // 0x800A777C: b           L_800A77F4
    // 0x800A7780: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
        goto L_800A77F4;
    // 0x800A7780: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
L_800A7784:
    // 0x800A7784: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800A7788: nop

    // 0x800A778C: lh          $v1, 0x0($t7)
    ctx->r3 = MEM_H(ctx->r15, 0X0);
    // 0x800A7790: jal         0x8001E474
    // 0x800A7794: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    cutscene_id(rdram, ctx);
        goto after_3;
    // 0x800A7794: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_3:
    // 0x800A7798: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800A779C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800A77A0: bne         $v0, $at, L_800A77F4
    if (ctx->r2 != ctx->r1) {
        // 0x800A77A4: nop
    
            goto L_800A77F4;
    }
    // 0x800A77A4: nop

    // 0x800A77A8: jal         0x8001AE88
    // 0x800A77AC: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    get_balloon_cutscene_timer(rdram, ctx);
        goto after_4;
    // 0x800A77AC: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_4:
    // 0x800A77B0: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800A77B4: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800A77B8: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800A77BC: sltu        $at, $v0, $t9
    ctx->r1 = ctx->r2 < ctx->r25 ? 1 : 0;
    // 0x800A77C0: beq         $at, $zero, L_800A77F4
    if (ctx->r1 == 0) {
        // 0x800A77C4: nop
    
            goto L_800A77F4;
    }
    // 0x800A77C4: nop

    // 0x800A77C8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A77CC: addiu       $a1, $a1, 0x7304
    ctx->r5 = ADD32(ctx->r5, 0X7304);
    // 0x800A77D0: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x800A77D4: nop

    // 0x800A77D8: bne         $t2, $zero, L_800A77F4
    if (ctx->r10 != 0) {
        // 0x800A77DC: nop
    
            goto L_800A77F4;
    }
    // 0x800A77DC: nop

    // 0x800A77E0: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    // 0x800A77E4: jal         0x80001D04
    // 0x800A77E8: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    sound_play(rdram, ctx);
        goto after_5;
    // 0x800A77E8: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_5:
    // 0x800A77EC: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800A77F0: nop

L_800A77F4:
    // 0x800A77F4: bgez        $v1, L_800A7800
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800A77F8: addiu       $t1, $zero, 0xA
        ctx->r9 = ADD32(0, 0XA);
            goto L_800A7800;
    }
    // 0x800A77F8: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x800A77FC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800A7800:
    // 0x800A7800: div         $zero, $v1, $t1
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r9)));
    // 0x800A7804: bne         $t1, $zero, L_800A7810
    if (ctx->r9 != 0) {
        // 0x800A7808: nop
    
            goto L_800A7810;
    }
    // 0x800A7808: nop

    // 0x800A780C: break       7
    do_break(2148169740);
L_800A7810:
    // 0x800A7810: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A7814: bne         $t1, $at, L_800A7828
    if (ctx->r9 != ctx->r1) {
        // 0x800A7818: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A7828;
    }
    // 0x800A7818: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A781C: bne         $v1, $at, L_800A7828
    if (ctx->r3 != ctx->r1) {
        // 0x800A7820: nop
    
            goto L_800A7828;
    }
    // 0x800A7820: nop

    // 0x800A7824: break       6
    do_break(2148169764);
L_800A7828:
    // 0x800A7828: mflo        $v0
    ctx->r2 = lo;
    // 0x800A782C: beq         $v0, $zero, L_800A78A4
    if (ctx->r2 == 0) {
        // 0x800A7830: nop
    
            goto L_800A78A4;
    }
    // 0x800A7830: nop

    // 0x800A7834: div         $zero, $v1, $t1
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r9)));
    // 0x800A7838: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A783C: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A7840: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800A7844: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A7848: sh          $v0, 0x2B8($t3)
    MEM_H(0X2B8, ctx->r11) = ctx->r2;
    // 0x800A784C: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x800A7850: bne         $t1, $zero, L_800A785C
    if (ctx->r9 != 0) {
        // 0x800A7854: nop
    
            goto L_800A785C;
    }
    // 0x800A7854: nop

    // 0x800A7858: break       7
    do_break(2148169816);
L_800A785C:
    // 0x800A785C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A7860: bne         $t1, $at, L_800A7874
    if (ctx->r9 != ctx->r1) {
        // 0x800A7864: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A7874;
    }
    // 0x800A7864: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A7868: bne         $v1, $at, L_800A7874
    if (ctx->r3 != ctx->r1) {
        // 0x800A786C: nop
    
            goto L_800A7874;
    }
    // 0x800A786C: nop

    // 0x800A7870: break       6
    do_break(2148169840);
L_800A7874:
    // 0x800A7874: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A7878: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A787C: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A7880: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A7884: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A7888: mfhi        $t4
    ctx->r12 = hi;
    // 0x800A788C: sh          $t4, 0x2D8($t5)
    MEM_H(0X2D8, ctx->r13) = ctx->r12;
    // 0x800A7890: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A7894: jal         0x800AAB5C
    // 0x800A7898: addiu       $a3, $a3, 0x2C0
    ctx->r7 = ADD32(ctx->r7, 0X2C0);
    hud_element_render(rdram, ctx);
        goto after_6;
    // 0x800A7898: addiu       $a3, $a3, 0x2C0
    ctx->r7 = ADD32(ctx->r7, 0X2C0);
    after_6:
    // 0x800A789C: b           L_800A78E0
    // 0x800A78A0: nop

        goto L_800A78E0;
    // 0x800A78A0: nop

L_800A78A4:
    // 0x800A78A4: div         $zero, $v1, $t1
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r9)));
    // 0x800A78A8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A78AC: lw          $t7, 0x729C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X729C);
    // 0x800A78B0: bne         $t1, $zero, L_800A78BC
    if (ctx->r9 != 0) {
        // 0x800A78B4: nop
    
            goto L_800A78BC;
    }
    // 0x800A78B4: nop

    // 0x800A78B8: break       7
    do_break(2148169912);
L_800A78BC:
    // 0x800A78BC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A78C0: bne         $t1, $at, L_800A78D4
    if (ctx->r9 != ctx->r1) {
        // 0x800A78C4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A78D4;
    }
    // 0x800A78C4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A78C8: bne         $v1, $at, L_800A78D4
    if (ctx->r3 != ctx->r1) {
        // 0x800A78CC: nop
    
            goto L_800A78D4;
    }
    // 0x800A78CC: nop

    // 0x800A78D0: break       6
    do_break(2148169936);
L_800A78D4:
    // 0x800A78D4: mfhi        $t6
    ctx->r14 = hi;
    // 0x800A78D8: sh          $t6, 0x2B8($t7)
    MEM_H(0X2B8, ctx->r15) = ctx->r14;
    // 0x800A78DC: nop

L_800A78E0:
    // 0x800A78E0: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A78E4: lw          $a3, 0x729C($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X729C);
    // 0x800A78E8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A78EC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A78F0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A78F4: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A78F8: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A78FC: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A7900: jal         0x800AAB5C
    // 0x800A7904: addiu       $a3, $a3, 0x2A0
    ctx->r7 = ADD32(ctx->r7, 0X2A0);
    hud_element_render(rdram, ctx);
        goto after_7;
    // 0x800A7904: addiu       $a3, $a3, 0x2A0
    ctx->r7 = ADD32(ctx->r7, 0X2A0);
    after_7:
    // 0x800A7908: jal         0x800662D8
    // 0x800A790C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    enable_pal_viewport_height_adjust(rdram, ctx);
        goto after_8;
    // 0x800A790C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_8:
    // 0x800A7910: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x800A7914: lw          $t8, 0x300($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X300);
    // 0x800A7918: nop

    // 0x800A791C: bne         $t8, $zero, L_800A792C
    if (ctx->r24 != 0) {
        // 0x800A7920: nop
    
            goto L_800A792C;
    }
    // 0x800A7920: nop

    // 0x800A7924: jal         0x8007C36C
    // 0x800A7928: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprite_opaque(rdram, ctx);
        goto after_9;
    // 0x800A7928: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_9:
L_800A792C:
    // 0x800A792C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A7930: lw          $a3, 0x729C($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X729C);
    // 0x800A7934: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A7938: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A793C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A7940: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A7944: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A7948: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A794C: jal         0x800AAB5C
    // 0x800A7950: addiu       $a3, $a3, 0x260
    ctx->r7 = ADD32(ctx->r7, 0X260);
    hud_element_render(rdram, ctx);
        goto after_10;
    // 0x800A7950: addiu       $a3, $a3, 0x260
    ctx->r7 = ADD32(ctx->r7, 0X260);
    after_10:
    // 0x800A7954: jal         0x8007C36C
    // 0x800A7958: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_11;
    // 0x800A7958: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_11:
    // 0x800A795C: jal         0x800662D8
    // 0x800A7960: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    enable_pal_viewport_height_adjust(rdram, ctx);
        goto after_12;
    // 0x800A7960: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_12:
    // 0x800A7964: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A7968: lw          $a3, 0x729C($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X729C);
    // 0x800A796C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A7970: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A7974: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A7978: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A797C: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A7980: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A7984: jal         0x800AAB5C
    // 0x800A7988: addiu       $a3, $a3, 0x280
    ctx->r7 = ADD32(ctx->r7, 0X280);
    hud_element_render(rdram, ctx);
        goto after_13;
    // 0x800A7988: addiu       $a3, $a3, 0x280
    ctx->r7 = ADD32(ctx->r7, 0X280);
    after_13:
    // 0x800A798C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A7990: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800A7994: jr          $ra
    // 0x800A7998: nop

    return;
    // 0x800A7998: nop

;}
RECOMP_FUNC void hud_sound_play(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A799C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A79A0: lw          $t6, 0x7300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7300);
    // 0x800A79A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A79A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A79AC: bne         $t6, $zero, L_800A79D0
    if (ctx->r14 != 0) {
        // 0x800A79B0: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_800A79D0;
    }
    // 0x800A79B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A79B4: jal         0x8006ECE0
    // 0x800A79B8: nop

    is_game_paused(rdram, ctx);
        goto after_0;
    // 0x800A79B8: nop

    after_0:
    // 0x800A79BC: bne         $v0, $zero, L_800A79D0
    if (ctx->r2 != 0) {
        // 0x800A79C0: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_800A79D0;
    }
    // 0x800A79C0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A79C4: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    // 0x800A79C8: jal         0x80001D04
    // 0x800A79CC: addiu       $a1, $a1, 0x7300
    ctx->r5 = ADD32(ctx->r5, 0X7300);
    sound_play(rdram, ctx);
        goto after_1;
    // 0x800A79CC: addiu       $a1, $a1, 0x7300
    ctx->r5 = ADD32(ctx->r5, 0X7300);
    after_1:
L_800A79D0:
    // 0x800A79D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A79D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A79D8: jr          $ra
    // 0x800A79DC: nop

    return;
    // 0x800A79DC: nop

;}
RECOMP_FUNC void hud_sound_play_delayed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A79E0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A79E4: addiu       $v0, $v0, 0x7334
    ctx->r2 = ADD32(ctx->r2, 0X7334);
    // 0x800A79E8: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800A79EC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800A79F0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800A79F4: bne         $t7, $zero, L_800A7A40
    if (ctx->r15 != 0) {
        // 0x800A79F8: andi        $t6, $a0, 0xFFFF
        ctx->r14 = ctx->r4 & 0XFFFF;
            goto L_800A7A40;
    }
    // 0x800A79F8: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x800A79FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A7A00: sh          $t6, 0x733C($at)
    MEM_H(0X733C, ctx->r1) = ctx->r14;
    // 0x800A7A04: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x800A7A08: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A7A0C: nop

    // 0x800A7A10: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x800A7A14: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A7A18: nop

    // 0x800A7A1C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800A7A20: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A7A24: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A7A28: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A7A2C: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800A7A30: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x800A7A34: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A7A38: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800A7A3C: sw          $a2, 0x7338($at)
    MEM_W(0X7338, ctx->r1) = ctx->r6;
L_800A7A40:
    // 0x800A7A40: jr          $ra
    // 0x800A7A44: nop

    return;
    // 0x800A7A44: nop

;}
RECOMP_FUNC void hud_sound_stop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A7A48: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A7A4C: lhu         $t7, 0x733C($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X733C);
    // 0x800A7A50: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x800A7A54: bne         $t7, $t6, L_800A7A74
    if (ctx->r15 != ctx->r14) {
        // 0x800A7A58: sw          $a0, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r4;
            goto L_800A7A74;
    }
    // 0x800A7A58: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800A7A5C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800A7A60: lw          $t8, 0x7338($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7338);
    // 0x800A7A64: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A7A68: bne         $a1, $t8, L_800A7A74
    if (ctx->r5 != ctx->r24) {
        // 0x800A7A6C: nop
    
            goto L_800A7A74;
    }
    // 0x800A7A6C: nop

    // 0x800A7A70: sw          $zero, 0x7334($at)
    MEM_W(0X7334, ctx->r1) = 0;
L_800A7A74:
    // 0x800A7A74: jr          $ra
    // 0x800A7A78: nop

    return;
    // 0x800A7A78: nop

;}
RECOMP_FUNC void hud_weapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A7A7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A7A80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A7A84: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800A7A88: lw          $t1, 0x64($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X64);
    // 0x800A7A8C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A7A90: lb          $t6, 0x1D8($t1)
    ctx->r14 = MEM_B(ctx->r9, 0X1D8);
    // 0x800A7A94: nop

    // 0x800A7A98: bne         $t6, $zero, L_800A7FB0
    if (ctx->r14 != 0) {
        // 0x800A7A9C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A7FB0;
    }
    // 0x800A7A9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A7AA0: jal         0x800662D8
    // 0x800A7AA4: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    enable_pal_viewport_height_adjust(rdram, ctx);
        goto after_0;
    // 0x800A7AA4: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    after_0:
    // 0x800A7AA8: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800A7AAC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A7AB0: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A7AB4: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A7AB8: lb          $t7, 0x172($t1)
    ctx->r15 = MEM_B(ctx->r9, 0X172);
    // 0x800A7ABC: lb          $v1, 0x174($t1)
    ctx->r3 = MEM_B(ctx->r9, 0X174);
    // 0x800A7AC0: lb          $t9, 0x5D($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X5D);
    // 0x800A7AC4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800A7AC8: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800A7ACC: beq         $v1, $t9, L_800A7B1C
    if (ctx->r3 == ctx->r25) {
        // 0x800A7AD0: addu        $a0, $t8, $v1
        ctx->r4 = ADD32(ctx->r24, ctx->r3);
            goto L_800A7B1C;
    }
    // 0x800A7AD0: addu        $a0, $t8, $v1
    ctx->r4 = ADD32(ctx->r24, ctx->r3);
    // 0x800A7AD4: bne         $v1, $zero, L_800A7AE8
    if (ctx->r3 != 0) {
        // 0x800A7AD8: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_800A7AE8;
    }
    // 0x800A7AD8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800A7ADC: addiu       $t2, $zero, 0x78
    ctx->r10 = ADD32(0, 0X78);
    // 0x800A7AE0: b           L_800A7B04
    // 0x800A7AE4: sb          $t2, 0x5C($v0)
    MEM_B(0X5C, ctx->r2) = ctx->r10;
        goto L_800A7B04;
    // 0x800A7AE4: sb          $t2, 0x5C($v0)
    MEM_B(0X5C, ctx->r2) = ctx->r10;
L_800A7AE8:
    // 0x800A7AE8: lbu         $t3, 0x72F7($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X72F7);
    // 0x800A7AEC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A7AF0: bne         $t3, $at, L_800A7B00
    if (ctx->r11 != ctx->r1) {
        // 0x800A7AF4: addiu       $t4, $zero, 0x78
        ctx->r12 = ADD32(0, 0X78);
            goto L_800A7B00;
    }
    // 0x800A7AF4: addiu       $t4, $zero, 0x78
    ctx->r12 = ADD32(0, 0X78);
    // 0x800A7AF8: b           L_800A7B04
    // 0x800A7AFC: sb          $zero, 0x5C($v0)
    MEM_B(0X5C, ctx->r2) = 0;
        goto L_800A7B04;
    // 0x800A7AFC: sb          $zero, 0x5C($v0)
    MEM_B(0X5C, ctx->r2) = 0;
L_800A7B00:
    // 0x800A7B00: sb          $t4, 0x5C($v0)
    MEM_B(0X5C, ctx->r2) = ctx->r12;
L_800A7B04:
    // 0x800A7B04: lb          $t5, 0x174($t1)
    ctx->r13 = MEM_B(ctx->r9, 0X174);
    // 0x800A7B08: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800A7B0C: nop

    // 0x800A7B10: sb          $t5, 0x5D($t6)
    MEM_B(0X5D, ctx->r14) = ctx->r13;
    // 0x800A7B14: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A7B18: nop

L_800A7B1C:
    // 0x800A7B1C: lb          $t7, 0x173($t1)
    ctx->r15 = MEM_B(ctx->r9, 0X173);
    // 0x800A7B20: nop

    // 0x800A7B24: blez        $t7, L_800A7E9C
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800A7B28: nop
    
            goto L_800A7E9C;
    }
    // 0x800A7B28: nop

    // 0x800A7B2C: lb          $v1, 0x5B($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X5B);
    // 0x800A7B30: nop

    // 0x800A7B34: slti        $at, $v1, 0x10
    ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // 0x800A7B38: beq         $at, $zero, L_800A7B94
    if (ctx->r1 == 0) {
        // 0x800A7B3C: nop
    
            goto L_800A7B94;
    }
    // 0x800A7B3C: nop

    // 0x800A7B40: lh          $t8, 0x170($t1)
    ctx->r24 = MEM_H(ctx->r9, 0X170);
    // 0x800A7B44: sll         $t9, $v1, 12
    ctx->r25 = S32(ctx->r3 << 12);
    // 0x800A7B48: bne         $t8, $zero, L_800A7B94
    if (ctx->r24 != 0) {
        // 0x800A7B4C: nop
    
            goto L_800A7B94;
    }
    // 0x800A7B4C: nop

    // 0x800A7B50: sh          $t9, 0x44($v0)
    MEM_H(0X44, ctx->r2) = ctx->r25;
    // 0x800A7B54: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A7B58: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A7B5C: lb          $t2, 0x5B($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X5B);
    // 0x800A7B60: lwc1        $f9, -0x7300($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X7300);
    // 0x800A7B64: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800A7B68: lwc1        $f8, -0x72FC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X72FC);
    // 0x800A7B6C: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x800A7B70: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x800A7B74: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800A7B78: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800A7B7C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800A7B80: nop

    // 0x800A7B84: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x800A7B88: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x800A7B8C: b           L_800A7BAC
    // 0x800A7B90: swc1        $f4, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f4.u32l;
        goto L_800A7BAC;
    // 0x800A7B90: swc1        $f4, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f4.u32l;
L_800A7B94:
    // 0x800A7B94: sh          $zero, 0x44($v0)
    MEM_H(0X44, ctx->r2) = 0;
    // 0x800A7B98: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A7B9C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A7BA0: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800A7BA4: nop

    // 0x800A7BA8: swc1        $f6, 0x48($t3)
    MEM_W(0X48, ctx->r11) = ctx->f6.u32l;
L_800A7BAC:
    // 0x800A7BAC: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800A7BB0: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x800A7BB4: sh          $a0, 0x58($t4)
    MEM_H(0X58, ctx->r12) = ctx->r4;
    // 0x800A7BB8: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A7BBC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800A7BC0: lb          $t5, 0x5B($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X5B);
    // 0x800A7BC4: nop

    // 0x800A7BC8: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800A7BCC: sb          $t7, 0x5B($v0)
    MEM_B(0X5B, ctx->r2) = ctx->r15;
    // 0x800A7BD0: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A7BD4: nop

    // 0x800A7BD8: lb          $t8, 0x5B($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X5B);
    // 0x800A7BDC: nop

    // 0x800A7BE0: slti        $at, $t8, 0x11
    ctx->r1 = SIGNED(ctx->r24) < 0X11 ? 1 : 0;
    // 0x800A7BE4: bne         $at, $zero, L_800A7CE8
    if (ctx->r1 != 0) {
        // 0x800A7BE8: nop
    
            goto L_800A7CE8;
    }
    // 0x800A7BE8: nop

    // 0x800A7BEC: sb          $t9, 0x5B($v0)
    MEM_B(0X5B, ctx->r2) = ctx->r25;
    // 0x800A7BF0: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A7BF4: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800A7BF8: lb          $t2, 0x5C($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X5C);
    // 0x800A7BFC: addiu       $t5, $zero, 0x78
    ctx->r13 = ADD32(0, 0X78);
    // 0x800A7C00: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800A7C04: sb          $t4, 0x5C($v0)
    MEM_B(0X5C, ctx->r2) = ctx->r12;
    // 0x800A7C08: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A7C0C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A7C10: lb          $v1, 0x5C($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X5C);
    // 0x800A7C14: nop

    // 0x800A7C18: slti        $at, $v1, 0x79
    ctx->r1 = SIGNED(ctx->r3) < 0X79 ? 1 : 0;
    // 0x800A7C1C: bne         $at, $zero, L_800A7C34
    if (ctx->r1 != 0) {
        // 0x800A7C20: nop
    
            goto L_800A7C34;
    }
    // 0x800A7C20: nop

    // 0x800A7C24: sb          $t5, 0x5C($v0)
    MEM_B(0X5C, ctx->r2) = ctx->r13;
    // 0x800A7C28: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A7C2C: b           L_800A7CE8
    // 0x800A7C30: nop

        goto L_800A7CE8;
    // 0x800A7C30: nop

L_800A7C34:
    // 0x800A7C34: lw          $t6, 0x72CC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X72CC);
    // 0x800A7C38: nop

    // 0x800A7C3C: bne         $t6, $zero, L_800A7CE8
    if (ctx->r14 != 0) {
        // 0x800A7C40: nop
    
            goto L_800A7CE8;
    }
    // 0x800A7C40: nop

    // 0x800A7C44: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x800A7C48: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A7C4C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A7C50: lwc1        $f19, -0x72F8($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X72F8);
    // 0x800A7C54: lwc1        $f18, -0x72F4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X72F4);
    // 0x800A7C58: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x800A7C5C: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x800A7C60: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x800A7C64: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800A7C68: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800A7C6C: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x800A7C70: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800A7C74: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800A7C78: nop

    // 0x800A7C7C: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800A7C80: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A7C84: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A7C88: nop

    // 0x800A7C8C: cvt.w.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_D(ctx->f8.d);
    // 0x800A7C90: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x800A7C94: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800A7C98: sll         $t8, $a0, 16
    ctx->r24 = S32(ctx->r4 << 16);
    // 0x800A7C9C: jal         0x80070A04
    // 0x800A7CA0: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    sins_f(rdram, ctx);
        goto after_1;
    // 0x800A7CA0: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    after_1:
    // 0x800A7CA4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A7CA8: lwc1        $f17, -0x72F0($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X72F0);
    // 0x800A7CAC: lwc1        $f16, -0x72EC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X72EC);
    // 0x800A7CB0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A7CB4: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A7CB8: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x800A7CBC: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x800A7CC0: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A7CC4: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800A7CC8: lwc1        $f6, 0x48($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X48);
    // 0x800A7CCC: nop

    // 0x800A7CD0: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800A7CD4: add.d       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f8.d + ctx->f4.d;
    // 0x800A7CD8: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x800A7CDC: swc1        $f16, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f16.u32l;
    // 0x800A7CE0: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A7CE4: nop

L_800A7CE8:
    // 0x800A7CE8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800A7CEC: lw          $t2, 0x72CC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X72CC);
    // 0x800A7CF0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800A7CF4: blez        $t2, L_800A7D20
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800A7CF8: lui         $at, 0x3FE8
        ctx->r1 = S32(0X3FE8 << 16);
            goto L_800A7D20;
    }
    // 0x800A7CF8: lui         $at, 0x3FE8
    ctx->r1 = S32(0X3FE8 << 16);
    // 0x800A7CFC: lwc1        $f18, 0x48($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X48);
    // 0x800A7D00: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800A7D04: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800A7D08: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x800A7D0C: mul.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800A7D10: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x800A7D14: swc1        $f10, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f10.u32l;
    // 0x800A7D18: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A7D1C: nop

L_800A7D20:
    // 0x800A7D20: lwc1        $f18, 0x48($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X48);
    // 0x800A7D24: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800A7D28: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800A7D2C: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x800A7D30: c.eq.d      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.d == ctx->f6.d;
    // 0x800A7D34: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A7D38: bc1t        L_800A7D5C
    if (c1cs) {
        // 0x800A7D3C: nop
    
            goto L_800A7D5C;
    }
    // 0x800A7D3C: nop

    // 0x800A7D40: jal         0x8007C36C
    // 0x800A7D44: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    sprite_opaque(rdram, ctx);
        goto after_2;
    // 0x800A7D44: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    after_2:
    // 0x800A7D48: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A7D4C: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A7D50: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A7D54: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800A7D58: nop

L_800A7D5C:
    // 0x800A7D5C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A7D60: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A7D64: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A7D68: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A7D6C: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A7D70: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A7D74: addiu       $a3, $v0, 0x40
    ctx->r7 = ADD32(ctx->r2, 0X40);
    // 0x800A7D78: jal         0x800AAB5C
    // 0x800A7D7C: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    hud_element_render(rdram, ctx);
        goto after_3;
    // 0x800A7D7C: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    after_3:
    // 0x800A7D80: jal         0x8007C36C
    // 0x800A7D84: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_4;
    // 0x800A7D84: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x800A7D88: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800A7D8C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A7D90: lb          $v1, 0x173($t1)
    ctx->r3 = MEM_B(ctx->r9, 0X173);
    // 0x800A7D94: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A7D98: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x800A7D9C: bne         $at, $zero, L_800A7DB8
    if (ctx->r1 != 0) {
        // 0x800A7DA0: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800A7DB8;
    }
    // 0x800A7DA0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A7DA4: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800A7DA8: addiu       $t3, $zero, -0x80
    ctx->r11 = ADD32(0, -0X80);
    // 0x800A7DAC: sb          $t3, 0x63A($t4)
    MEM_B(0X63A, ctx->r12) = ctx->r11;
    // 0x800A7DB0: lb          $v1, 0x173($t1)
    ctx->r3 = MEM_B(ctx->r9, 0X173);
    // 0x800A7DB4: nop

L_800A7DB8:
    // 0x800A7DB8: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x800A7DBC: beq         $at, $zero, L_800A7DE4
    if (ctx->r1 == 0) {
        // 0x800A7DC0: addiu       $a0, $a0, 0x72BC
        ctx->r4 = ADD32(ctx->r4, 0X72BC);
            goto L_800A7DE4;
    }
    // 0x800A7DC0: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A7DC4: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A7DC8: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800A7DCC: lb          $t5, 0x63A($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X63A);
    // 0x800A7DD0: nop

    // 0x800A7DD4: subu        $t7, $t5, $t6
    ctx->r15 = SUB32(ctx->r13, ctx->r14);
    // 0x800A7DD8: sb          $t7, 0x63A($v0)
    MEM_B(0X63A, ctx->r2) = ctx->r15;
    // 0x800A7DDC: lb          $v1, 0x173($t1)
    ctx->r3 = MEM_B(ctx->r9, 0X173);
    // 0x800A7DE0: nop

L_800A7DE4:
    // 0x800A7DE4: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x800A7DE8: beq         $at, $zero, L_800A7E2C
    if (ctx->r1 == 0) {
        // 0x800A7DEC: lui         $t5, 0xFA00
        ctx->r13 = S32(0XFA00 << 16);
            goto L_800A7E2C;
    }
    // 0x800A7DEC: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x800A7DF0: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800A7DF4: nop

    // 0x800A7DF8: lb          $t9, 0x63A($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X63A);
    // 0x800A7DFC: nop

    // 0x800A7E00: addiu       $t2, $t9, 0x80
    ctx->r10 = ADD32(ctx->r25, 0X80);
    // 0x800A7E04: bgez        $t2, L_800A7E18
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800A7E08: andi        $t3, $t2, 0x1F
        ctx->r11 = ctx->r10 & 0X1F;
            goto L_800A7E18;
    }
    // 0x800A7E08: andi        $t3, $t2, 0x1F
    ctx->r11 = ctx->r10 & 0X1F;
    // 0x800A7E0C: beq         $t3, $zero, L_800A7E18
    if (ctx->r11 == 0) {
        // 0x800A7E10: nop
    
            goto L_800A7E18;
    }
    // 0x800A7E10: nop

    // 0x800A7E14: addiu       $t3, $t3, -0x20
    ctx->r11 = ADD32(ctx->r11, -0X20);
L_800A7E18:
    // 0x800A7E18: slti        $at, $t3, 0x14
    ctx->r1 = SIGNED(ctx->r11) < 0X14 ? 1 : 0;
    // 0x800A7E1C: beq         $at, $zero, L_800A7E94
    if (ctx->r1 == 0) {
        // 0x800A7E20: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800A7E94;
    }
    // 0x800A7E20: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A7E24: beq         $v1, $at, L_800A7E94
    if (ctx->r3 == ctx->r1) {
        // 0x800A7E28: nop
    
            goto L_800A7E94;
    }
    // 0x800A7E28: nop

L_800A7E2C:
    // 0x800A7E2C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800A7E30: addiu       $t6, $zero, -0x60
    ctx->r14 = ADD32(0, -0X60);
    // 0x800A7E34: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800A7E38: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800A7E3C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800A7E40: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800A7E44: lb          $t7, 0x173($t1)
    ctx->r15 = MEM_B(ctx->r9, 0X173);
    // 0x800A7E48: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800A7E4C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800A7E50: sh          $t8, 0x638($t9)
    MEM_H(0X638, ctx->r25) = ctx->r24;
    // 0x800A7E54: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A7E58: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A7E5C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A7E60: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A7E64: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A7E68: jal         0x800AAB5C
    // 0x800A7E6C: addiu       $a3, $a3, 0x620
    ctx->r7 = ADD32(ctx->r7, 0X620);
    hud_element_render(rdram, ctx);
        goto after_5;
    // 0x800A7E6C: addiu       $a3, $a3, 0x620
    ctx->r7 = ADD32(ctx->r7, 0X620);
    after_5:
    // 0x800A7E70: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A7E74: addiu       $a1, $a1, 0x72BC
    ctx->r5 = ADD32(ctx->r5, 0X72BC);
    // 0x800A7E78: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800A7E7C: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x800A7E80: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x800A7E84: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x800A7E88: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800A7E8C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800A7E90: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_800A7E94:
    // 0x800A7E94: b           L_800A7F80
    // 0x800A7E98: nop

        goto L_800A7F80;
    // 0x800A7E98: nop

L_800A7E9C:
    // 0x800A7E9C: lb          $v1, 0x5B($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X5B);
    // 0x800A7EA0: nop

    // 0x800A7EA4: blez        $v1, L_800A7F80
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800A7EA8: sll         $t5, $v1, 12
        ctx->r13 = S32(ctx->r3 << 12);
            goto L_800A7F80;
    }
    // 0x800A7EA8: sll         $t5, $v1, 12
    ctx->r13 = S32(ctx->r3 << 12);
    // 0x800A7EAC: sh          $t5, 0x44($v0)
    MEM_H(0X44, ctx->r2) = ctx->r13;
    // 0x800A7EB0: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A7EB4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A7EB8: lb          $t6, 0x5B($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X5B);
    // 0x800A7EBC: lwc1        $f11, -0x72E8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X72E8);
    // 0x800A7EC0: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800A7EC4: lwc1        $f10, -0x72E4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X72E4);
    // 0x800A7EC8: cvt.d.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.d = CVT_D_W(ctx->f8.u32l);
    // 0x800A7ECC: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x800A7ED0: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800A7ED4: mul.d       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f4.d, ctx->f10.d);
    // 0x800A7ED8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800A7EDC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A7EE0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A7EE4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800A7EE8: add.d       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = ctx->f18.d + ctx->f16.d;
    // 0x800A7EEC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800A7EF0: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x800A7EF4: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A7EF8: swc1        $f8, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f8.u32l;
    // 0x800A7EFC: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A7F00: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800A7F04: lb          $t7, 0x5B($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X5B);
    // 0x800A7F08: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A7F0C: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x800A7F10: sb          $t9, 0x5B($v0)
    MEM_B(0X5B, ctx->r2) = ctx->r25;
    // 0x800A7F14: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x800A7F18: nop

    // 0x800A7F1C: sh          $a0, 0x58($t2)
    MEM_H(0X58, ctx->r10) = ctx->r4;
    // 0x800A7F20: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A7F24: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A7F28: lb          $t3, 0x5B($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X5B);
    // 0x800A7F2C: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A7F30: bgez        $t3, L_800A7F48
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800A7F34: nop
    
            goto L_800A7F48;
    }
    // 0x800A7F34: nop

    // 0x800A7F38: sb          $zero, 0x5B($v0)
    MEM_B(0X5B, ctx->r2) = 0;
    // 0x800A7F3C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A7F40: lw          $v0, 0x729C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X729C);
    // 0x800A7F44: nop

L_800A7F48:
    // 0x800A7F48: lw          $t4, 0x72CC($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X72CC);
    // 0x800A7F4C: nop

    // 0x800A7F50: beq         $t4, $zero, L_800A7F78
    if (ctx->r12 == 0) {
        // 0x800A7F54: nop
    
            goto L_800A7F78;
    }
    // 0x800A7F54: nop

    // 0x800A7F58: lwc1        $f4, 0x48($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X48);
    // 0x800A7F5C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A7F60: nop

    // 0x800A7F64: div.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = DIV_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800A7F68: swc1        $f18, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f18.u32l;
    // 0x800A7F6C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A7F70: lw          $v0, 0x729C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X729C);
    // 0x800A7F74: nop

L_800A7F78:
    // 0x800A7F78: jal         0x800AAB5C
    // 0x800A7F7C: addiu       $a3, $v0, 0x40
    ctx->r7 = ADD32(ctx->r2, 0X40);
    hud_element_render(rdram, ctx);
        goto after_6;
    // 0x800A7F7C: addiu       $a3, $v0, 0x40
    ctx->r7 = ADD32(ctx->r2, 0X40);
    after_6:
L_800A7F80:
    // 0x800A7F80: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A7F84: addiu       $a1, $a1, 0x72BC
    ctx->r5 = ADD32(ctx->r5, 0X72BC);
    // 0x800A7F88: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800A7F8C: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800A7F90: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x800A7F94: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x800A7F98: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800A7F9C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A7FA0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800A7FA4: jal         0x800662D8
    // 0x800A7FA8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    enable_pal_viewport_height_adjust(rdram, ctx);
        goto after_7;
    // 0x800A7FA8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    after_7:
    // 0x800A7FAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A7FB0:
    // 0x800A7FB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A7FB4: jr          $ra
    // 0x800A7FB8: nop

    return;
    // 0x800A7FB8: nop

;}
RECOMP_FUNC void hud_magnet_reticle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A7FBC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800A7FC0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A7FC4: lw          $v1, 0x64($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X64);
    // 0x800A7FC8: nop

    // 0x800A7FCC: lw          $t6, 0x140($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X140);
    // 0x800A7FD0: nop

    // 0x800A7FD4: beq         $t6, $zero, L_800A80B8
    if (ctx->r14 == 0) {
        // 0x800A7FD8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A80B8;
    }
    // 0x800A7FD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A7FDC: jal         0x80066460
    // 0x800A7FE0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    get_current_viewport(rdram, ctx);
        goto after_0;
    // 0x800A7FE0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x800A7FE4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800A7FE8: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A7FEC: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x800A7FF0: nop

    // 0x800A7FF4: bne         $v0, $t7, L_800A80B8
    if (ctx->r2 != ctx->r15) {
        // 0x800A7FF8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A80B8;
    }
    // 0x800A7FF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A7FFC: lw          $t8, 0x140($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X140);
    // 0x800A8000: lw          $a3, 0x729C($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X729C);
    // 0x800A8004: lwc1        $f4, 0xC($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0XC);
    // 0x800A8008: lh          $a2, 0x226($a3)
    ctx->r6 = MEM_H(ctx->r7, 0X226);
    // 0x800A800C: swc1        $f4, 0x22C($a3)
    MEM_W(0X22C, ctx->r7) = ctx->f4.u32l;
    // 0x800A8010: lw          $t9, 0x140($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X140);
    // 0x800A8014: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800A8018: lwc1        $f6, 0x10($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X10);
    // 0x800A801C: sll         $t2, $a2, 2
    ctx->r10 = S32(ctx->r6 << 2);
    // 0x800A8020: swc1        $f6, 0x230($a3)
    MEM_W(0X230, ctx->r7) = ctx->f6.u32l;
    // 0x800A8024: lw          $t0, 0x140($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X140);
    // 0x800A8028: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A802C: lwc1        $f8, 0x14($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X14);
    // 0x800A8030: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800A8034: swc1        $f8, 0x234($a3)
    MEM_W(0X234, ctx->r7) = ctx->f8.u32l;
    // 0x800A8038: lw          $t1, 0x72B4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X72B4);
    // 0x800A803C: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A8040: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800A8044: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x800A8048: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A804C: beq         $v0, $zero, L_800A80B4
    if (ctx->r2 == 0) {
        // 0x800A8050: addiu       $a3, $a3, 0x220
        ctx->r7 = ADD32(ctx->r7, 0X220);
            goto L_800A80B4;
    }
    // 0x800A8050: addiu       $a3, $a3, 0x220
    ctx->r7 = ADD32(ctx->r7, 0X220);
    // 0x800A8054: lw          $t4, 0x7298($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7298);
    // 0x800A8058: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A805C: addu        $t5, $t4, $a2
    ctx->r13 = ADD32(ctx->r12, ctx->r6);
    // 0x800A8060: sb          $zero, 0x0($t5)
    MEM_B(0X0, ctx->r13) = 0;
    // 0x800A8064: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x800A8068: jal         0x80066F1C
    // 0x800A806C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    viewport_main(rdram, ctx);
        goto after_1;
    // 0x800A806C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_1:
    // 0x800A8070: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A8074: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A8078: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A807C: jal         0x80068648
    // 0x800A8080: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    mtx_world_origin(rdram, ctx);
        goto after_2;
    // 0x800A8080: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    after_2:
    // 0x800A8084: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x800A8088: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800A808C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A8090: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A8094: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A8098: addiu       $t6, $zero, 0x100
    ctx->r14 = ADD32(0, 0X100);
    // 0x800A809C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800A80A0: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A80A4: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A80A8: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A80AC: jal         0x80068754
    // 0x800A80B0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    render_sprite_billboard(rdram, ctx);
        goto after_3;
    // 0x800A80B0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_3:
L_800A80B4:
    // 0x800A80B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A80B8:
    // 0x800A80B8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800A80BC: jr          $ra
    // 0x800A80C0: nop

    return;
    // 0x800A80C0: nop

;}
RECOMP_FUNC void hud_race_time(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A80C4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A80C8: lw          $a3, 0x72CC($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X72CC);
    // 0x800A80CC: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800A80D0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800A80D4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800A80D8: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x800A80DC: beq         $a3, $zero, L_800A8138
    if (ctx->r7 == 0) {
        // 0x800A80E0: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_800A8138;
    }
    // 0x800A80E0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800A80E4: lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X0);
    // 0x800A80E8: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x800A80EC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800A80F0: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800A80F4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800A80F8: lbu         $t9, 0x2D14($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X2D14);
    // 0x800A80FC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A8100: beq         $t9, $at, L_800A8138
    if (ctx->r25 == ctx->r1) {
        // 0x800A8104: nop
    
            goto L_800A8138;
    }
    // 0x800A8104: nop

    // 0x800A8108: blez        $a3, L_800A850C
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800A810C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800A850C;
    }
    // 0x800A810C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800A8110: lb          $v0, 0x193($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X193);
    // 0x800A8114: nop

    // 0x800A8118: blez        $v0, L_800A8508
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800A811C: sll         $t3, $v0, 2
        ctx->r11 = S32(ctx->r2 << 2);
            goto L_800A8508;
    }
    // 0x800A811C: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x800A8120: addu        $t4, $a0, $t3
    ctx->r12 = ADD32(ctx->r4, ctx->r11);
    // 0x800A8124: lw          $t5, 0x128($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X128);
    // 0x800A8128: nop

    // 0x800A812C: slti        $at, $t5, 0xB4
    ctx->r1 = SIGNED(ctx->r13) < 0XB4 ? 1 : 0;
    // 0x800A8130: beq         $at, $zero, L_800A850C
    if (ctx->r1 == 0) {
        // 0x800A8134: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800A850C;
    }
    // 0x800A8134: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800A8138:
    // 0x800A8138: lb          $t2, 0x1D8($a2)
    ctx->r10 = MEM_B(ctx->r6, 0X1D8);
    // 0x800A813C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A8140: bne         $t2, $zero, L_800A850C
    if (ctx->r10 != 0) {
        // 0x800A8144: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800A850C;
    }
    // 0x800A8144: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800A8148: lw          $t0, 0x729C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X729C);
    // 0x800A814C: lb          $v0, 0x193($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X193);
    // 0x800A8150: lb          $t1, 0x15A($t0)
    ctx->r9 = MEM_B(ctx->r8, 0X15A);
    // 0x800A8154: blez        $v0, L_800A81A8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800A8158: addiu       $t1, $t1, 0x7F
        ctx->r9 = ADD32(ctx->r9, 0X7F);
            goto L_800A81A8;
    }
    // 0x800A8158: addiu       $t1, $t1, 0x7F
    ctx->r9 = ADD32(ctx->r9, 0X7F);
    // 0x800A815C: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800A8160: addu        $v1, $a2, $t6
    ctx->r3 = ADD32(ctx->r6, ctx->r14);
    // 0x800A8164: lw          $t7, 0x128($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X128);
    // 0x800A8168: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800A816C: slti        $at, $t7, 0xB4
    ctx->r1 = SIGNED(ctx->r15) < 0XB4 ? 1 : 0;
    // 0x800A8170: beq         $at, $zero, L_800A81A8
    if (ctx->r1 == 0) {
        // 0x800A8174: nop
    
            goto L_800A81A8;
    }
    // 0x800A8174: nop

    // 0x800A8178: lw          $t8, 0x7320($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7320);
    // 0x800A817C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800A8180: lb          $t9, 0x4B($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X4B);
    // 0x800A8184: nop

    // 0x800A8188: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800A818C: beq         $at, $zero, L_800A81A8
    if (ctx->r1 == 0) {
        // 0x800A8190: nop
    
            goto L_800A81A8;
    }
    // 0x800A8190: nop

    // 0x800A8194: lw          $s0, 0x124($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X124);
    // 0x800A8198: bne         $t1, $zero, L_800A823C
    if (ctx->r9 != 0) {
        // 0x800A819C: sw          $t3, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r11;
            goto L_800A823C;
    }
    // 0x800A819C: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    // 0x800A81A0: b           L_800A823C
    // 0x800A81A4: addiu       $t1, $zero, 0xB4
    ctx->r9 = ADD32(0, 0XB4);
        goto L_800A823C;
    // 0x800A81A4: addiu       $t1, $zero, 0xB4
    ctx->r9 = ADD32(0, 0XB4);
L_800A81A8:
    // 0x800A81A8: lb          $a1, 0x194($a2)
    ctx->r5 = MEM_B(ctx->r6, 0X194);
    // 0x800A81AC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800A81B0: bltz        $a1, L_800A81F8
    if (SIGNED(ctx->r5) < 0) {
        // 0x800A81B4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800A81F8;
    }
    // 0x800A81B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A81B8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800A81BC: lw          $t4, 0x7320($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7320);
    // 0x800A81C0: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x800A81C4: lb          $a0, 0x4B($t4)
    ctx->r4 = MEM_B(ctx->r12, 0X4B);
    // 0x800A81C8: addu        $v1, $a2, $t5
    ctx->r3 = ADD32(ctx->r6, ctx->r13);
    // 0x800A81CC: blez        $a0, L_800A81F8
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800A81D0: nop
    
            goto L_800A81F8;
    }
    // 0x800A81D0: nop

L_800A81D4:
    // 0x800A81D4: lw          $t6, 0x128($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X128);
    // 0x800A81D8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800A81DC: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800A81E0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800A81E4: bne         $at, $zero, L_800A81F8
    if (ctx->r1 != 0) {
        // 0x800A81E8: addu        $s0, $s0, $t6
        ctx->r16 = ADD32(ctx->r16, ctx->r14);
            goto L_800A81F8;
    }
    // 0x800A81E8: addu        $s0, $s0, $t6
    ctx->r16 = ADD32(ctx->r16, ctx->r14);
    // 0x800A81EC: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800A81F0: bne         $at, $zero, L_800A81D4
    if (ctx->r1 != 0) {
        // 0x800A81F4: nop
    
            goto L_800A81D4;
    }
    // 0x800A81F4: nop

L_800A81F8:
    // 0x800A81F8: sltiu       $v1, $s0, 0x1
    ctx->r3 = ctx->r16 < 0X1 ? 1 : 0;
    // 0x800A81FC: bne         $v1, $zero, L_800A8224
    if (ctx->r3 != 0) {
        // 0x800A8200: nop
    
            goto L_800A8224;
    }
    // 0x800A8200: nop

    // 0x800A8204: sltu        $v1, $zero, $t2
    ctx->r3 = 0 < ctx->r10 ? 1 : 0;
    // 0x800A8208: bne         $v1, $zero, L_800A8224
    if (ctx->r3 != 0) {
        // 0x800A820C: nop
    
            goto L_800A8224;
    }
    // 0x800A820C: nop

    // 0x800A8210: jal         0x8006ECE0
    // 0x800A8214: nop

    is_game_paused(rdram, ctx);
        goto after_0;
    // 0x800A8214: nop

    after_0:
    // 0x800A8218: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A821C: lw          $t0, 0x729C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X729C);
    // 0x800A8220: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
L_800A8224:
    // 0x800A8224: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    // 0x800A8228: addiu       $t7, $zero, -0x7F
    ctx->r15 = ADD32(0, -0X7F);
    // 0x800A822C: sb          $t7, 0x15A($t0)
    MEM_B(0X15A, ctx->r8) = ctx->r15;
    // 0x800A8230: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A8234: lw          $a3, 0x72CC($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X72CC);
    // 0x800A8238: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_800A823C:
    // 0x800A823C: bne         $a3, $zero, L_800A8274
    if (ctx->r7 != 0) {
        // 0x800A8240: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800A8274;
    }
    // 0x800A8240: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A8244: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A8248: lw          $a3, 0x729C($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X729C);
    // 0x800A824C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A8250: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A8254: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A8258: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A825C: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A8260: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    // 0x800A8264: jal         0x800AAB5C
    // 0x800A8268: addiu       $a3, $a3, 0x140
    ctx->r7 = ADD32(ctx->r7, 0X140);
    hud_element_render(rdram, ctx);
        goto after_1;
    // 0x800A8268: addiu       $a3, $a3, 0x140
    ctx->r7 = ADD32(ctx->r7, 0X140);
    after_1:
    // 0x800A826C: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x800A8270: nop

L_800A8274:
    // 0x800A8274: ori         $a0, $zero, 0x8CA0
    ctx->r4 = 0 | 0X8CA0;
    // 0x800A8278: jal         0x8000C8B4
    // 0x800A827C: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    normalise_time(rdram, ctx);
        goto after_2;
    // 0x800A827C: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    after_2:
    // 0x800A8280: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x800A8284: slt         $at, $v0, $s0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800A8288: beq         $at, $zero, L_800A82A0
    if (ctx->r1 == 0) {
        // 0x800A828C: ori         $a0, $zero, 0x8CA0
        ctx->r4 = 0 | 0X8CA0;
            goto L_800A82A0;
    }
    // 0x800A828C: ori         $a0, $zero, 0x8CA0
    ctx->r4 = 0 | 0X8CA0;
    // 0x800A8290: jal         0x8000C8B4
    // 0x800A8294: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    normalise_time(rdram, ctx);
        goto after_3;
    // 0x800A8294: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    after_3:
    // 0x800A8298: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x800A829C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800A82A0:
    // 0x800A82A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A82A4: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x800A82A8: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    // 0x800A82AC: addiu       $a3, $sp, 0x4C
    ctx->r7 = ADD32(ctx->r29, 0X4C);
    // 0x800A82B0: jal         0x800597E0
    // 0x800A82B4: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    get_timestamp_from_frames(rdram, ctx);
        goto after_4;
    // 0x800A82B4: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    after_4:
    // 0x800A82B8: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800A82BC: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x800A82C0: bne         $t8, $zero, L_800A82DC
    if (ctx->r24 != 0) {
        // 0x800A82C4: ori         $a0, $zero, 0x8CA0
        ctx->r4 = 0 | 0X8CA0;
            goto L_800A82DC;
    }
    // 0x800A82C4: ori         $a0, $zero, 0x8CA0
    ctx->r4 = 0 | 0X8CA0;
    // 0x800A82C8: jal         0x8000C8B4
    // 0x800A82CC: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    normalise_time(rdram, ctx);
        goto after_5;
    // 0x800A82CC: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    after_5:
    // 0x800A82D0: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x800A82D4: bne         $v0, $s0, L_800A8378
    if (ctx->r2 != ctx->r16) {
        // 0x800A82D8: lw          $t3, 0x4C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X4C);
            goto L_800A8378;
    }
    // 0x800A82D8: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
L_800A82DC:
    // 0x800A82DC: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x800A82E0: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A82E4: slt         $at, $t9, $t1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800A82E8: beq         $at, $zero, L_800A82F8
    if (ctx->r1 == 0) {
        // 0x800A82EC: addiu       $s0, $s0, 0x72F6
        ctx->r16 = ADD32(ctx->r16, 0X72F6);
            goto L_800A82F8;
    }
    // 0x800A82EC: addiu       $s0, $s0, 0x72F6
    ctx->r16 = ADD32(ctx->r16, 0X72F6);
    // 0x800A82F0: b           L_800A82FC
    // 0x800A82F4: subu        $t1, $t1, $t9
    ctx->r9 = SUB32(ctx->r9, ctx->r25);
        goto L_800A82FC;
    // 0x800A82F4: subu        $t1, $t1, $t9
    ctx->r9 = SUB32(ctx->r9, ctx->r25);
L_800A82F8:
    // 0x800A82F8: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_800A82FC:
    // 0x800A82FC: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x800A8300: div         $zero, $t1, $at
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r1)));
    // 0x800A8304: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800A8308: lw          $t4, 0x729C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X729C);
    // 0x800A830C: addiu       $t3, $t1, -0x7F
    ctx->r11 = ADD32(ctx->r9, -0X7F);
    // 0x800A8310: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800A8314: sb          $t3, 0x15A($t4)
    MEM_B(0X15A, ctx->r12) = ctx->r11;
    // 0x800A8318: mfhi        $t5
    ctx->r13 = hi;
    // 0x800A831C: slti        $at, $t5, 0x15
    ctx->r1 = SIGNED(ctx->r13) < 0X15 ? 1 : 0;
    // 0x800A8320: bne         $at, $zero, L_800A8338
    if (ctx->r1 != 0) {
        // 0x800A8324: nop
    
            goto L_800A8338;
    }
    // 0x800A8324: nop

    // 0x800A8328: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A832C: addiu       $s0, $s0, 0x72F6
    ctx->r16 = ADD32(ctx->r16, 0X72F6);
    // 0x800A8330: b           L_800A8508
    // 0x800A8334: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
        goto L_800A8508;
    // 0x800A8334: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
L_800A8338:
    // 0x800A8338: lbu         $t7, 0x0($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X0);
    // 0x800A833C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800A8340: beq         $t7, $zero, L_800A8364
    if (ctx->r15 == 0) {
        // 0x800A8344: nop
    
            goto L_800A8364;
    }
    // 0x800A8344: nop

    // 0x800A8348: lw          $t8, 0x72CC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X72CC);
    // 0x800A834C: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    // 0x800A8350: bne         $t8, $zero, L_800A8360
    if (ctx->r24 != 0) {
        // 0x800A8354: nop
    
            goto L_800A8360;
    }
    // 0x800A8354: nop

    // 0x800A8358: jal         0x80001D04
    // 0x800A835C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_6;
    // 0x800A835C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
L_800A8360:
    // 0x800A8360: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_800A8364:
    // 0x800A8364: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A8368: lw          $t0, 0x729C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X729C);
    // 0x800A836C: b           L_800A8410
    // 0x800A8370: nop

        goto L_800A8410;
    // 0x800A8370: nop

    // 0x800A8374: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
L_800A8378:
    // 0x800A8378: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x800A837C: div         $zero, $t3, $v0
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r2)));
    // 0x800A8380: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A8384: lw          $t0, 0x729C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X729C);
    // 0x800A8388: nop

    // 0x800A838C: lb          $t9, 0x15B($t0)
    ctx->r25 = MEM_B(ctx->r8, 0X15B);
    // 0x800A8390: bne         $v0, $zero, L_800A839C
    if (ctx->r2 != 0) {
        // 0x800A8394: nop
    
            goto L_800A839C;
    }
    // 0x800A8394: nop

    // 0x800A8398: break       7
    do_break(2148172696);
L_800A839C:
    // 0x800A839C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A83A0: bne         $v0, $at, L_800A83B4
    if (ctx->r2 != ctx->r1) {
        // 0x800A83A4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A83B4;
    }
    // 0x800A83A4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A83A8: bne         $t3, $at, L_800A83B4
    if (ctx->r11 != ctx->r1) {
        // 0x800A83AC: nop
    
            goto L_800A83B4;
    }
    // 0x800A83AC: nop

    // 0x800A83B0: break       6
    do_break(2148172720);
L_800A83B4:
    // 0x800A83B4: mflo        $t4
    ctx->r12 = lo;
    // 0x800A83B8: nop

    // 0x800A83BC: nop

    // 0x800A83C0: multu       $t4, $v0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A83C4: mflo        $t5
    ctx->r13 = lo;
    // 0x800A83C8: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x800A83CC: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
    // 0x800A83D0: lb          $t7, 0x15B($t0)
    ctx->r15 = MEM_B(ctx->r8, 0X15B);
    // 0x800A83D4: nop

    // 0x800A83D8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800A83DC: sb          $t8, 0x15B($t0)
    MEM_B(0X15B, ctx->r8) = ctx->r24;
    // 0x800A83E0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A83E4: lw          $t0, 0x729C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X729C);
    // 0x800A83E8: nop

    // 0x800A83EC: lb          $t3, 0x15B($t0)
    ctx->r11 = MEM_B(ctx->r8, 0X15B);
    // 0x800A83F0: nop

    // 0x800A83F4: slti        $at, $t3, 0xA
    ctx->r1 = SIGNED(ctx->r11) < 0XA ? 1 : 0;
    // 0x800A83F8: bne         $at, $zero, L_800A8410
    if (ctx->r1 != 0) {
        // 0x800A83FC: nop
    
            goto L_800A8410;
    }
    // 0x800A83FC: nop

    // 0x800A8400: sb          $zero, 0x15B($t0)
    MEM_B(0X15B, ctx->r8) = 0;
    // 0x800A8404: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A8408: lw          $t0, 0x729C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X729C);
    // 0x800A840C: nop

L_800A8410:
    // 0x800A8410: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800A8414: lbu         $t4, 0x72F7($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X72F7);
    // 0x800A8418: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A841C: bne         $t4, $at, L_800A8488
    if (ctx->r12 != ctx->r1) {
        // 0x800A8420: nop
    
            goto L_800A8488;
    }
    // 0x800A8420: nop

    // 0x800A8424: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800A8428: lwc1        $f4, 0x16C($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X16C);
    // 0x800A842C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800A8430: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A8434: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A8438: lwc1        $f8, 0x170($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X170);
    // 0x800A843C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A8440: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800A8444: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800A8448: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x800A844C: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x800A8450: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800A8454: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x800A8458: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800A845C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A8460: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A8464: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800A8468: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A846C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800A8470: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800A8474: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800A8478: jal         0x800A8518
    // 0x800A847C: nop

    hud_timer_render(rdram, ctx);
        goto after_7;
    // 0x800A847C: nop

    after_7:
    // 0x800A8480: b           L_800A84E4
    // 0x800A8484: nop

        goto L_800A84E4;
    // 0x800A8484: nop

L_800A8488:
    // 0x800A8488: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800A848C: lwc1        $f16, 0x16C($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X16C);
    // 0x800A8490: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800A8494: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A8498: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A849C: lwc1        $f4, 0x170($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X170);
    // 0x800A84A0: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800A84A4: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x800A84A8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800A84AC: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x800A84B0: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x800A84B4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A84B8: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x800A84BC: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800A84C0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A84C4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A84C8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800A84CC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A84D0: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800A84D4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800A84D8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A84DC: jal         0x800A8518
    // 0x800A84E0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    hud_timer_render(rdram, ctx);
        goto after_8;
    // 0x800A84E0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_8:
L_800A84E4:
    // 0x800A84E4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A84E8: lw          $v1, 0x72BC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X72BC);
    // 0x800A84EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A84F0: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800A84F4: sw          $t9, 0x72BC($at)
    MEM_W(0X72BC, ctx->r1) = ctx->r25;
    // 0x800A84F8: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x800A84FC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800A8500: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800A8504: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
L_800A8508:
    // 0x800A8508: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800A850C:
    // 0x800A850C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800A8510: jr          $ra
    // 0x800A8514: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800A8514: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void hud_timer_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A8518: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x800A851C: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x800A8520: mtc1        $a1, $f8
    ctx->f8.u32l = ctx->r5;
    // 0x800A8524: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A8528: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A852C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A8530: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800A8534: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A8538: lw          $t6, 0x94($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X94);
    // 0x800A853C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800A8540: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x800A8544: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x800A8548: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800A854C: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800A8550: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800A8554: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800A8558: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800A855C: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800A8560: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
    // 0x800A8564: sw          $a3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r7;
    // 0x800A8568: swc1        $f6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
    // 0x800A856C: swc1        $f10, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f10.u32l;
    // 0x800A8570: sh          $zero, 0x64($sp)
    MEM_H(0X64, ctx->r29) = 0;
    // 0x800A8574: sh          $zero, 0x62($sp)
    MEM_H(0X62, ctx->r29) = 0;
    // 0x800A8578: sh          $zero, 0x60($sp)
    MEM_H(0X60, ctx->r29) = 0;
    // 0x800A857C: swc1        $f16, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f16.u32l;
    // 0x800A8580: bne         $t6, $zero, L_800A85AC
    if (ctx->r14 != 0) {
        // 0x800A8584: swc1        $f18, 0x74($sp)
        MEM_W(0X74, ctx->r29) = ctx->f18.u32l;
            goto L_800A85AC;
    }
    // 0x800A8584: swc1        $f18, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f18.u32l;
    // 0x800A8588: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x800A858C: addiu       $t8, $zero, 0xB
    ctx->r24 = ADD32(0, 0XB);
    // 0x800A8590: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x800A8594: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
    // 0x800A8598: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    // 0x800A859C: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x800A85A0: addiu       $s4, $zero, 0x9
    ctx->r20 = ADD32(0, 0X9);
    // 0x800A85A4: b           L_800A85CC
    // 0x800A85A8: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
        goto L_800A85CC;
    // 0x800A85A8: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
L_800A85AC:
    // 0x800A85AC: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x800A85B0: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x800A85B4: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x800A85B8: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
    // 0x800A85BC: sw          $t9, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r25;
    // 0x800A85C0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800A85C4: addiu       $s4, $zero, 0xA
    ctx->r20 = ADD32(0, 0XA);
    // 0x800A85C8: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
L_800A85CC:
    // 0x800A85CC: lw          $t2, 0x88($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X88);
    // 0x800A85D0: addiu       $s5, $zero, 0xA
    ctx->r21 = ADD32(0, 0XA);
    // 0x800A85D4: div         $zero, $t2, $s5
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r21)));
    // 0x800A85D8: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A85DC: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800A85E0: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800A85E4: addiu       $s2, $s2, 0x72C4
    ctx->r18 = ADD32(ctx->r18, 0X72C4);
    // 0x800A85E8: addiu       $s1, $s1, 0x72C0
    ctx->r17 = ADD32(ctx->r17, 0X72C0);
    // 0x800A85EC: addiu       $s0, $s0, 0x72BC
    ctx->r16 = ADD32(ctx->r16, 0X72BC);
    // 0x800A85F0: addiu       $s3, $sp, 0x60
    ctx->r19 = ADD32(ctx->r29, 0X60);
    // 0x800A85F4: sh          $s4, 0x66($sp)
    MEM_H(0X66, ctx->r29) = ctx->r20;
    // 0x800A85F8: bne         $s5, $zero, L_800A8604
    if (ctx->r21 != 0) {
        // 0x800A85FC: nop
    
            goto L_800A8604;
    }
    // 0x800A85FC: nop

    // 0x800A8600: break       7
    do_break(2148173312);
L_800A8604:
    // 0x800A8604: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A8608: bne         $s5, $at, L_800A861C
    if (ctx->r21 != ctx->r1) {
        // 0x800A860C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A861C;
    }
    // 0x800A860C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A8610: bne         $t2, $at, L_800A861C
    if (ctx->r10 != ctx->r1) {
        // 0x800A8614: nop
    
            goto L_800A861C;
    }
    // 0x800A8614: nop

    // 0x800A8618: break       6
    do_break(2148173336);
L_800A861C:
    // 0x800A861C: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x800A8620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A8624: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800A8628: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800A862C: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x800A8630: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    // 0x800A8634: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    // 0x800A8638: mflo        $t3
    ctx->r11 = lo;
    // 0x800A863C: sh          $t3, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r11;
    // 0x800A8640: jal         0x800AAB5C
    // 0x800A8644: nop

    hud_element_render(rdram, ctx);
        goto after_0;
    // 0x800A8644: nop

    after_0:
    // 0x800A8648: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    // 0x800A864C: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x800A8650: div         $zero, $t4, $s5
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r21)));
    // 0x800A8654: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800A8658: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800A865C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A8660: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x800A8664: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800A8668: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800A866C: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x800A8670: swc1        $f8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f8.u32l;
    // 0x800A8674: bne         $s5, $zero, L_800A8680
    if (ctx->r21 != 0) {
        // 0x800A8678: nop
    
            goto L_800A8680;
    }
    // 0x800A8678: nop

    // 0x800A867C: break       7
    do_break(2148173436);
L_800A8680:
    // 0x800A8680: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A8684: bne         $s5, $at, L_800A8698
    if (ctx->r21 != ctx->r1) {
        // 0x800A8688: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A8698;
    }
    // 0x800A8688: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A868C: bne         $t4, $at, L_800A8698
    if (ctx->r12 != ctx->r1) {
        // 0x800A8690: nop
    
            goto L_800A8698;
    }
    // 0x800A8690: nop

    // 0x800A8694: break       6
    do_break(2148173460);
L_800A8698:
    // 0x800A8698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A869C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800A86A0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800A86A4: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x800A86A8: mfhi        $t5
    ctx->r13 = hi;
    // 0x800A86AC: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    // 0x800A86B0: jal         0x800AAB5C
    // 0x800A86B4: nop

    hud_element_render(rdram, ctx);
        goto after_1;
    // 0x800A86B4: nop

    after_1:
    // 0x800A86B8: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x800A86BC: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800A86C0: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x800A86C4: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800A86C8: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A86CC: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800A86D0: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800A86D4: cvt.s.w     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A86D8: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800A86DC: sh          $zero, 0x78($sp)
    MEM_H(0X78, ctx->r29) = 0;
    // 0x800A86E0: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x800A86E4: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x800A86E8: add.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x800A86EC: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    // 0x800A86F0: swc1        $f8, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f8.u32l;
    // 0x800A86F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A86F8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800A86FC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800A8700: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x800A8704: jal         0x800AAB5C
    // 0x800A8708: sh          $t6, 0x66($sp)
    MEM_H(0X66, ctx->r29) = ctx->r14;
    hud_element_render(rdram, ctx);
        goto after_2;
    // 0x800A8708: sh          $t6, 0x66($sp)
    MEM_H(0X66, ctx->r29) = ctx->r14;
    after_2:
    // 0x800A870C: lw          $t8, 0x8C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8C);
    // 0x800A8710: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x800A8714: div         $zero, $t8, $s5
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r21)));
    // 0x800A8718: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800A871C: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800A8720: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A8724: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800A8728: sh          $s4, 0x66($sp)
    MEM_H(0X66, ctx->r29) = ctx->r20;
    // 0x800A872C: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x800A8730: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x800A8734: sub.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f20.fl;
    // 0x800A8738: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    // 0x800A873C: swc1        $f6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f6.u32l;
    // 0x800A8740: bne         $s5, $zero, L_800A874C
    if (ctx->r21 != 0) {
        // 0x800A8744: nop
    
            goto L_800A874C;
    }
    // 0x800A8744: nop

    // 0x800A8748: break       7
    do_break(2148173640);
L_800A874C:
    // 0x800A874C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A8750: bne         $s5, $at, L_800A8764
    if (ctx->r21 != ctx->r1) {
        // 0x800A8754: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A8764;
    }
    // 0x800A8754: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A8758: bne         $t8, $at, L_800A8764
    if (ctx->r24 != ctx->r1) {
        // 0x800A875C: nop
    
            goto L_800A8764;
    }
    // 0x800A875C: nop

    // 0x800A8760: break       6
    do_break(2148173664);
L_800A8764:
    // 0x800A8764: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A8768: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800A876C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800A8770: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x800A8774: mflo        $t9
    ctx->r25 = lo;
    // 0x800A8778: sh          $t9, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r25;
    // 0x800A877C: jal         0x800AAB5C
    // 0x800A8780: nop

    hud_element_render(rdram, ctx);
        goto after_3;
    // 0x800A8780: nop

    after_3:
    // 0x800A8784: lw          $t1, 0x8C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8C);
    // 0x800A8788: lwc1        $f8, 0x6C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800A878C: div         $zero, $t1, $s5
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r21)));
    // 0x800A8790: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800A8794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A8798: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800A879C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800A87A0: swc1        $f16, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f16.u32l;
    // 0x800A87A4: bne         $s5, $zero, L_800A87B0
    if (ctx->r21 != 0) {
        // 0x800A87A8: nop
    
            goto L_800A87B0;
    }
    // 0x800A87A8: nop

    // 0x800A87AC: break       7
    do_break(2148173740);
L_800A87B0:
    // 0x800A87B0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A87B4: bne         $s5, $at, L_800A87C8
    if (ctx->r21 != ctx->r1) {
        // 0x800A87B8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A87C8;
    }
    // 0x800A87B8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A87BC: bne         $t1, $at, L_800A87C8
    if (ctx->r9 != ctx->r1) {
        // 0x800A87C0: nop
    
            goto L_800A87C8;
    }
    // 0x800A87C0: nop

    // 0x800A87C4: break       6
    do_break(2148173764);
L_800A87C8:
    // 0x800A87C8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800A87CC: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x800A87D0: mfhi        $t2
    ctx->r10 = hi;
    // 0x800A87D4: sh          $t2, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r10;
    // 0x800A87D8: jal         0x800AAB5C
    // 0x800A87DC: nop

    hud_element_render(rdram, ctx);
        goto after_4;
    // 0x800A87DC: nop

    after_4:
    // 0x800A87E0: lwc1        $f18, 0x6C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800A87E4: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800A87E8: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800A87EC: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x800A87F0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800A87F4: sh          $zero, 0x78($sp)
    MEM_H(0X78, ctx->r29) = 0;
    // 0x800A87F8: add.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x800A87FC: swc1        $f6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
    // 0x800A8800: swc1        $f10, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f10.u32l;
    // 0x800A8804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A8808: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800A880C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800A8810: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x800A8814: jal         0x800AAB5C
    // 0x800A8818: sh          $t3, 0x66($sp)
    MEM_H(0X66, ctx->r29) = ctx->r11;
    hud_element_render(rdram, ctx);
        goto after_5;
    // 0x800A8818: sh          $t3, 0x66($sp)
    MEM_H(0X66, ctx->r29) = ctx->r11;
    after_5:
    // 0x800A881C: lw          $t4, 0x90($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X90);
    // 0x800A8820: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800A8824: div         $zero, $t4, $s5
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r21)));
    // 0x800A8828: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800A882C: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800A8830: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800A8834: sh          $s4, 0x66($sp)
    MEM_H(0X66, ctx->r29) = ctx->r20;
    // 0x800A8838: sub.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f20.fl;
    // 0x800A883C: swc1        $f4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f4.u32l;
    // 0x800A8840: swc1        $f8, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f8.u32l;
    // 0x800A8844: bne         $s5, $zero, L_800A8850
    if (ctx->r21 != 0) {
        // 0x800A8848: nop
    
            goto L_800A8850;
    }
    // 0x800A8848: nop

    // 0x800A884C: break       7
    do_break(2148173900);
L_800A8850:
    // 0x800A8850: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A8854: bne         $s5, $at, L_800A8868
    if (ctx->r21 != ctx->r1) {
        // 0x800A8858: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A8868;
    }
    // 0x800A8858: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A885C: bne         $t4, $at, L_800A8868
    if (ctx->r12 != ctx->r1) {
        // 0x800A8860: nop
    
            goto L_800A8868;
    }
    // 0x800A8860: nop

    // 0x800A8864: break       6
    do_break(2148173924);
L_800A8868:
    // 0x800A8868: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A886C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800A8870: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800A8874: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x800A8878: mflo        $t5
    ctx->r13 = lo;
    // 0x800A887C: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    // 0x800A8880: jal         0x800AAB5C
    // 0x800A8884: nop

    hud_element_render(rdram, ctx);
        goto after_6;
    // 0x800A8884: nop

    after_6:
    // 0x800A8888: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
    // 0x800A888C: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800A8890: div         $zero, $t6, $s5
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r21)));
    // 0x800A8894: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800A8898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A889C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800A88A0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800A88A4: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    // 0x800A88A8: bne         $s5, $zero, L_800A88B4
    if (ctx->r21 != 0) {
        // 0x800A88AC: nop
    
            goto L_800A88B4;
    }
    // 0x800A88AC: nop

    // 0x800A88B0: break       7
    do_break(2148174000);
L_800A88B4:
    // 0x800A88B4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A88B8: bne         $s5, $at, L_800A88CC
    if (ctx->r21 != ctx->r1) {
        // 0x800A88BC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A88CC;
    }
    // 0x800A88BC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A88C0: bne         $t6, $at, L_800A88CC
    if (ctx->r14 != ctx->r1) {
        // 0x800A88C4: nop
    
            goto L_800A88CC;
    }
    // 0x800A88C4: nop

    // 0x800A88C8: break       6
    do_break(2148174024);
L_800A88CC:
    // 0x800A88CC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800A88D0: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x800A88D4: mfhi        $t7
    ctx->r15 = hi;
    // 0x800A88D8: sh          $t7, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r15;
    // 0x800A88DC: jal         0x800AAB5C
    // 0x800A88E0: nop

    hud_element_render(rdram, ctx);
        goto after_7;
    // 0x800A88E0: nop

    after_7:
    // 0x800A88E4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800A88E8: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800A88EC: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800A88F0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800A88F4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800A88F8: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x800A88FC: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x800A8900: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x800A8904: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x800A8908: jr          $ra
    // 0x800A890C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x800A890C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void minimap_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A8910: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800A8914: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800A8918: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800A891C: lw          $t6, 0x38($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X38);
    // 0x800A8920: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A8924: srl         $t8, $t6, 16
    ctx->r24 = S32(U32(ctx->r14) >> 16);
    // 0x800A8928: sb          $t8, 0x7314($at)
    MEM_B(0X7314, ctx->r1) = ctx->r24;
    // 0x800A892C: lw          $t9, 0x38($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X38);
    // 0x800A8930: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A8934: srl         $t1, $t9, 8
    ctx->r9 = S32(U32(ctx->r25) >> 8);
    // 0x800A8938: sb          $t1, 0x7315($at)
    MEM_B(0X7315, ctx->r1) = ctx->r9;
    // 0x800A893C: lw          $t3, 0x38($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X38);
    // 0x800A8940: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A8944: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800A8948: sb          $t3, 0x7316($at)
    MEM_B(0X7316, ctx->r1) = ctx->r11;
    // 0x800A894C: lw          $a0, 0x20($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X20);
    // 0x800A8950: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    // 0x800A8954: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A8958: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A895C: addiu       $a2, $a2, 0x72E0
    ctx->r6 = ADD32(ctx->r6, 0X72E0);
    // 0x800A8960: addiu       $a1, $a1, 0x72DC
    ctx->r5 = ADD32(ctx->r5, 0X72DC);
    // 0x800A8964: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x800A8968: jal         0x8007CD30
    // 0x800A896C: sw          $a3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r7;
    load_sprite_info(rdram, ctx);
        goto after_0;
    // 0x800A896C: sw          $a3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r7;
    after_0:
    // 0x800A8970: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    // 0x800A8974: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A8978: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A897C: addiu       $t4, $sp, 0x2C
    ctx->r12 = ADD32(ctx->r29, 0X2C);
    // 0x800A8980: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800A8984: addiu       $a3, $a3, 0x72D8
    ctx->r7 = ADD32(ctx->r7, 0X72D8);
    // 0x800A8988: addiu       $a2, $a2, 0x72D4
    ctx->r6 = ADD32(ctx->r6, 0X72D4);
    // 0x800A898C: jal         0x8007CEB8
    // 0x800A8990: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8007CA68(rdram, ctx);
        goto after_1;
    // 0x800A8990: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x800A8994: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    // 0x800A8998: jal         0x8007C57C
    // 0x800A899C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    tex_load_sprite(rdram, ctx);
        goto after_2;
    // 0x800A899C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x800A89A0: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // 0x800A89A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800A89A8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800A89AC: jr          $ra
    // 0x800A89B0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800A89B0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void hud_setting(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A89B4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A89B8: lw          $t6, 0x72CC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X72CC);
    // 0x800A89BC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800A89C0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800A89C4: lb          $v0, 0x2D24($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X2D24);
    // 0x800A89C8: jr          $ra
    // 0x800A89CC: nop

    return;
    // 0x800A89CC: nop

;}
RECOMP_FUNC void hud_render_general(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A89D0: addiu       $sp, $sp, -0x160
    ctx->r29 = ADD32(ctx->r29, -0X160);
    // 0x800A89D4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800A89D8: sw          $a0, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r4;
    // 0x800A89DC: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800A89E0: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800A89E4: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800A89E8: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800A89EC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800A89F0: sw          $a1, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r5;
    // 0x800A89F4: sw          $a2, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->r6;
    // 0x800A89F8: sw          $a3, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r7;
    // 0x800A89FC: jal         0x800A1114
    // 0x800A8A00: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    hud_audio_update(rdram, ctx);
        goto after_0;
    // 0x800A8A00: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x800A8A04: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A8A08: addiu       $s0, $s0, 0x7298
    ctx->r16 = ADD32(ctx->r16, 0X7298);
    // 0x800A8A0C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x800A8A10: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800A8A14: sb          $zero, 0x1($t6)
    MEM_B(0X1, ctx->r14) = 0;
    // 0x800A8A18: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800A8A1C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A8A20: sb          $zero, 0x17($t7)
    MEM_B(0X17, ctx->r15) = 0;
    // 0x800A8A24: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800A8A28: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800A8A2C: sb          $zero, 0x8($t8)
    MEM_B(0X8, ctx->r24) = 0;
    // 0x800A8A30: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800A8A34: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800A8A38: sb          $zero, 0x11($t9)
    MEM_B(0X11, ctx->r25) = 0;
    // 0x800A8A3C: lb          $t2, 0x7293($t2)
    ctx->r10 = MEM_B(ctx->r10, 0X7293);
    // 0x800A8A40: sw          $zero, 0x7740($at)
    MEM_W(0X7740, ctx->r1) = 0;
    // 0x800A8A44: andi        $t3, $t2, 0x2
    ctx->r11 = ctx->r10 & 0X2;
    // 0x800A8A48: beq         $t3, $zero, L_800A8AC4
    if (ctx->r11 == 0) {
        // 0x800A8A4C: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_800A8AC4;
    }
    // 0x800A8A4C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A8A50: lb          $t4, 0x7290($t4)
    ctx->r12 = MEM_B(ctx->r12, 0X7290);
    // 0x800A8A54: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800A8A58: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x800A8A5C: lbu         $t5, 0x774B($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X774B);
    // 0x800A8A60: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A8A64: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800A8A68: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A8A6C: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x800A8A70: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800A8A74: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800A8A78: bgez        $t5, L_800A8A8C
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800A8A7C: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800A8A8C;
    }
    // 0x800A8A7C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A8A80: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A8A84: nop

    // 0x800A8A88: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_800A8A8C:
    // 0x800A8A8C: nop

    // 0x800A8A90: div.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800A8A94: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800A8A98: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800A8A9C: nop

    // 0x800A8AA0: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800A8AA4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A8AA8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A8AAC: nop

    // 0x800A8AB0: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800A8AB4: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x800A8AB8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800A8ABC: b           L_800A8AC8
    // 0x800A8AC0: sw          $t7, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r15;
        goto L_800A8AC8;
    // 0x800A8AC0: sw          $t7, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r15;
L_800A8AC4:
    // 0x800A8AC4: sw          $t8, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r24;
L_800A8AC8:
    // 0x800A8AC8: lw          $t9, 0x72B8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X72B8);
    // 0x800A8ACC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800A8AD0: blez        $t9, L_800A8C34
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800A8AD4: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_800A8C34;
    }
    // 0x800A8AD4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800A8AD8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A8ADC: addiu       $a1, $a1, 0x72B4
    ctx->r5 = ADD32(ctx->r5, 0X72B4);
    // 0x800A8AE0: ori         $s3, $zero, 0xC000
    ctx->r19 = 0 | 0XC000;
    // 0x800A8AE4: addiu       $s2, $zero, 0x28
    ctx->r18 = ADD32(0, 0X28);
L_800A8AE8:
    // 0x800A8AE8: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x800A8AEC: nop

    // 0x800A8AF0: addu        $t3, $t2, $s1
    ctx->r11 = ADD32(ctx->r10, ctx->r17);
    // 0x800A8AF4: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x800A8AF8: nop

    // 0x800A8AFC: beq         $t4, $zero, L_800A8C1C
    if (ctx->r12 == 0) {
        // 0x800A8B00: nop
    
            goto L_800A8C1C;
    }
    // 0x800A8B00: nop

    // 0x800A8B04: beq         $v1, $s2, L_800A8C1C
    if (ctx->r3 == ctx->r18) {
        // 0x800A8B08: nop
    
            goto L_800A8C1C;
    }
    // 0x800A8B08: nop

    // 0x800A8B0C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x800A8B10: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800A8B14: addu        $v0, $t5, $v1
    ctx->r2 = ADD32(ctx->r13, ctx->r3);
    // 0x800A8B18: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x800A8B1C: nop

    // 0x800A8B20: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800A8B24: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x800A8B28: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800A8B2C: nop

    // 0x800A8B30: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x800A8B34: lbu         $t2, 0x0($t9)
    ctx->r10 = MEM_BU(ctx->r25, 0X0);
    // 0x800A8B38: nop

    // 0x800A8B3C: slti        $at, $t2, 0x3D
    ctx->r1 = SIGNED(ctx->r10) < 0X3D ? 1 : 0;
    // 0x800A8B40: bne         $at, $zero, L_800A8C1C
    if (ctx->r1 != 0) {
        // 0x800A8B44: nop
    
            goto L_800A8C1C;
    }
    // 0x800A8B44: nop

    // 0x800A8B48: lw          $t3, 0x72B0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X72B0);
    // 0x800A8B4C: sll         $t4, $v1, 1
    ctx->r12 = S32(ctx->r3 << 1);
    // 0x800A8B50: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800A8B54: lh          $v0, 0x0($t5)
    ctx->r2 = MEM_H(ctx->r13, 0X0);
    // 0x800A8B58: nop

    // 0x800A8B5C: andi        $t6, $v0, 0xC000
    ctx->r14 = ctx->r2 & 0XC000;
    // 0x800A8B60: bne         $s3, $t6, L_800A8B8C
    if (ctx->r19 != ctx->r14) {
        // 0x800A8B64: andi        $t9, $v0, 0x8000
        ctx->r25 = ctx->r2 & 0X8000;
            goto L_800A8B8C;
    }
    // 0x800A8B64: andi        $t9, $v0, 0x8000
    ctx->r25 = ctx->r2 & 0X8000;
    // 0x800A8B68: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800A8B6C: nop

    // 0x800A8B70: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x800A8B74: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x800A8B78: jal         0x8007B70C
    // 0x800A8B7C: sw          $v1, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r3;
    tex_free(rdram, ctx);
        goto after_1;
    // 0x800A8B7C: sw          $v1, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r3;
    after_1:
    // 0x800A8B80: lw          $v1, 0x144($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X144);
    // 0x800A8B84: b           L_800A8C04
    // 0x800A8B88: nop

        goto L_800A8C04;
    // 0x800A8B88: nop

L_800A8B8C:
    // 0x800A8B8C: beq         $t9, $zero, L_800A8BB8
    if (ctx->r25 == 0) {
        // 0x800A8B90: andi        $t4, $v0, 0x4000
        ctx->r12 = ctx->r2 & 0X4000;
            goto L_800A8BB8;
    }
    // 0x800A8B90: andi        $t4, $v0, 0x4000
    ctx->r12 = ctx->r2 & 0X4000;
    // 0x800A8B94: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x800A8B98: nop

    // 0x800A8B9C: addu        $t3, $t2, $s1
    ctx->r11 = ADD32(ctx->r10, ctx->r17);
    // 0x800A8BA0: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x800A8BA4: jal         0x8007D100
    // 0x800A8BA8: sw          $v1, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r3;
    sprite_free(rdram, ctx);
        goto after_2;
    // 0x800A8BA8: sw          $v1, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r3;
    after_2:
    // 0x800A8BAC: lw          $v1, 0x144($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X144);
    // 0x800A8BB0: b           L_800A8C04
    // 0x800A8BB4: nop

        goto L_800A8C04;
    // 0x800A8BB4: nop

L_800A8BB8:
    // 0x800A8BB8: beq         $t4, $zero, L_800A8BE4
    if (ctx->r12 == 0) {
        // 0x800A8BBC: nop
    
            goto L_800A8BE4;
    }
    // 0x800A8BBC: nop

    // 0x800A8BC0: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x800A8BC4: nop

    // 0x800A8BC8: addu        $t6, $t5, $s1
    ctx->r14 = ADD32(ctx->r13, ctx->r17);
    // 0x800A8BCC: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x800A8BD0: jal         0x8000FFB8
    // 0x800A8BD4: sw          $v1, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r3;
    free_object(rdram, ctx);
        goto after_3;
    // 0x800A8BD4: sw          $v1, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r3;
    after_3:
    // 0x800A8BD8: lw          $v1, 0x144($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X144);
    // 0x800A8BDC: b           L_800A8C04
    // 0x800A8BE0: nop

        goto L_800A8C04;
    // 0x800A8BE0: nop

L_800A8BE4:
    // 0x800A8BE4: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800A8BE8: nop

    // 0x800A8BEC: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x800A8BF0: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x800A8BF4: jal         0x80060180
    // 0x800A8BF8: sw          $v1, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r3;
    free_3d_model(rdram, ctx);
        goto after_4;
    // 0x800A8BF8: sw          $v1, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r3;
    after_4:
    // 0x800A8BFC: lw          $v1, 0x144($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X144);
    // 0x800A8C00: nop

L_800A8C04:
    // 0x800A8C04: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A8C08: lw          $t9, 0x72B4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X72B4);
    // 0x800A8C0C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A8C10: addu        $t2, $t9, $s1
    ctx->r10 = ADD32(ctx->r25, ctx->r17);
    // 0x800A8C14: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
    // 0x800A8C18: addiu       $a1, $a1, 0x72B4
    ctx->r5 = ADD32(ctx->r5, 0X72B4);
L_800A8C1C:
    // 0x800A8C1C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800A8C20: lw          $t3, 0x72B8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X72B8);
    // 0x800A8C24: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800A8C28: slt         $at, $v1, $t3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800A8C2C: bne         $at, $zero, L_800A8AE8
    if (ctx->r1 != 0) {
        // 0x800A8C30: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800A8AE8;
    }
    // 0x800A8C30: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_800A8C34:
    // 0x800A8C34: jal         0x8006BFF0
    // 0x800A8C38: nop

    level_header(rdram, ctx);
        goto after_5;
    // 0x800A8C38: nop

    after_5:
    // 0x800A8C3C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A8C40: sw          $v0, 0x7320($at)
    MEM_W(0X7320, ctx->r1) = ctx->r2;
    // 0x800A8C44: jal         0x8001BAC4
    // 0x800A8C48: addiu       $a0, $sp, 0x140
    ctx->r4 = ADD32(ctx->r29, 0X140);
    get_racer_objects_by_port(rdram, ctx);
        goto after_6;
    // 0x800A8C48: addiu       $a0, $sp, 0x140
    ctx->r4 = ADD32(ctx->r29, 0X140);
    after_6:
    // 0x800A8C4C: lw          $t4, 0x160($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X160);
    // 0x800A8C50: sw          $v0, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r2;
    // 0x800A8C54: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800A8C58: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x800A8C5C: lw          $t6, 0x164($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X164);
    // 0x800A8C60: addiu       $s4, $s4, 0x72BC
    ctx->r20 = ADD32(ctx->r20, 0X72BC);
    // 0x800A8C64: sw          $t5, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r13;
    // 0x800A8C68: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800A8C6C: lw          $t8, 0x168($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X168);
    // 0x800A8C70: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A8C74: sw          $t7, 0x72C0($at)
    MEM_W(0X72C0, ctx->r1) = ctx->r15;
    // 0x800A8C78: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800A8C7C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800A8C80: lw          $t2, 0x7320($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7320);
    // 0x800A8C84: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A8C88: sw          $t9, 0x72C4($at)
    MEM_W(0X72C4, ctx->r1) = ctx->r25;
    // 0x800A8C8C: lb          $v1, 0x4C($t2)
    ctx->r3 = MEM_B(ctx->r10, 0X4C);
    // 0x800A8C90: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x800A8C94: bne         $v1, $at, L_800A8FE8
    if (ctx->r3 != ctx->r1) {
        // 0x800A8C98: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_800A8FE8;
    }
    // 0x800A8C98: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x800A8C9C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A8CA0: lbu         $v1, 0x72F7($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X72F7);
    // 0x800A8CA4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A8CA8: bne         $v1, $at, L_800A8CE4
    if (ctx->r3 != ctx->r1) {
        // 0x800A8CAC: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_800A8CE4;
    }
    // 0x800A8CAC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800A8CB0: lw          $t3, 0x72CC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X72CC);
    // 0x800A8CB4: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800A8CB8: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x800A8CBC: lb          $t4, 0x2D24($t4)
    ctx->r12 = MEM_B(ctx->r12, 0X2D24);
    // 0x800A8CC0: lw          $a1, 0x16C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X16C);
    // 0x800A8CC4: bne         $t4, $zero, L_800A8CE8
    if (ctx->r12 != 0) {
        // 0x800A8CC8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800A8CE8;
    }
    // 0x800A8CC8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A8CCC: jal         0x800A1A30
    // 0x800A8CD0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    hud_draw_eggs(rdram, ctx);
        goto after_7;
    // 0x800A8CD0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x800A8CD4: jal         0x8007B820
    // 0x800A8CD8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    rendermode_reset(rdram, ctx);
        goto after_8;
    // 0x800A8CD8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_8:
    // 0x800A8CDC: b           L_800A9C10
    // 0x800A8CE0: nop

        goto L_800A9C10;
    // 0x800A8CE0: nop

L_800A8CE4:
    // 0x800A8CE4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_800A8CE8:
    // 0x800A8CE8: bne         $v1, $at, L_800A8FDC
    if (ctx->r3 != ctx->r1) {
        // 0x800A8CEC: nop
    
            goto L_800A8FDC;
    }
    // 0x800A8CEC: nop

    // 0x800A8CF0: lw          $t5, 0x140($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X140);
    // 0x800A8CF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800A8CF8: blez        $t5, L_800A8E04
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800A8CFC: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800A8E04;
    }
    // 0x800A8CFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A8D00: andi        $t0, $t5, 0x3
    ctx->r8 = ctx->r13 & 0X3;
    // 0x800A8D04: beq         $t0, $zero, L_800A8D54
    if (ctx->r8 == 0) {
        // 0x800A8D08: or          $a3, $t0, $zero
        ctx->r7 = ctx->r8 | 0;
            goto L_800A8D54;
    }
    // 0x800A8D08: or          $a3, $t0, $zero
    ctx->r7 = ctx->r8 | 0;
    // 0x800A8D0C: sll         $t6, $zero, 2
    ctx->r14 = S32(0 << 2);
    // 0x800A8D10: addu        $a0, $v0, $t6
    ctx->r4 = ADD32(ctx->r2, ctx->r14);
    // 0x800A8D14: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
L_800A8D18:
    // 0x800A8D18: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800A8D1C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800A8D20: lw          $v1, 0x64($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X64);
    // 0x800A8D24: nop

    // 0x800A8D28: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x800A8D2C: nop

    // 0x800A8D30: bne         $s3, $t8, L_800A8D3C
    if (ctx->r19 != ctx->r24) {
        // 0x800A8D34: nop
    
            goto L_800A8D3C;
    }
    // 0x800A8D34: nop

    // 0x800A8D38: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_800A8D3C:
    // 0x800A8D3C: bne         $a3, $a1, L_800A8D18
    if (ctx->r7 != ctx->r5) {
        // 0x800A8D40: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_800A8D18;
    }
    // 0x800A8D40: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800A8D44: lw          $t9, 0x140($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X140);
    // 0x800A8D48: nop

    // 0x800A8D4C: beq         $a1, $t9, L_800A8E04
    if (ctx->r5 == ctx->r25) {
        // 0x800A8D50: nop
    
            goto L_800A8E04;
    }
    // 0x800A8D50: nop

L_800A8D54:
    // 0x800A8D54: lw          $t2, 0x140($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X140);
    // 0x800A8D58: sll         $t4, $a1, 2
    ctx->r12 = S32(ctx->r5 << 2);
    // 0x800A8D5C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800A8D60: addu        $a3, $t3, $v0
    ctx->r7 = ADD32(ctx->r11, ctx->r2);
    // 0x800A8D64: addu        $a0, $v0, $t4
    ctx->r4 = ADD32(ctx->r2, ctx->r12);
    // 0x800A8D68: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
L_800A8D6C:
    // 0x800A8D6C: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x800A8D70: nop

    // 0x800A8D74: lw          $v1, 0x64($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X64);
    // 0x800A8D78: nop

    // 0x800A8D7C: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x800A8D80: nop

    // 0x800A8D84: bne         $s3, $t6, L_800A8D90
    if (ctx->r19 != ctx->r14) {
        // 0x800A8D88: nop
    
            goto L_800A8D90;
    }
    // 0x800A8D88: nop

    // 0x800A8D8C: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_800A8D90:
    // 0x800A8D90: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x800A8D94: nop

    // 0x800A8D98: lw          $v1, 0x64($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X64);
    // 0x800A8D9C: nop

    // 0x800A8DA0: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x800A8DA4: nop

    // 0x800A8DA8: bne         $s3, $t8, L_800A8DB4
    if (ctx->r19 != ctx->r24) {
        // 0x800A8DAC: nop
    
            goto L_800A8DB4;
    }
    // 0x800A8DAC: nop

    // 0x800A8DB0: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_800A8DB4:
    // 0x800A8DB4: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800A8DB8: nop

    // 0x800A8DBC: lw          $v1, 0x64($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X64);
    // 0x800A8DC0: nop

    // 0x800A8DC4: lh          $t2, 0x0($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X0);
    // 0x800A8DC8: nop

    // 0x800A8DCC: bne         $s3, $t2, L_800A8DD8
    if (ctx->r19 != ctx->r10) {
        // 0x800A8DD0: nop
    
            goto L_800A8DD8;
    }
    // 0x800A8DD0: nop

    // 0x800A8DD4: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_800A8DD8:
    // 0x800A8DD8: lw          $t3, 0xC($a0)
    ctx->r11 = MEM_W(ctx->r4, 0XC);
    // 0x800A8DDC: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800A8DE0: lw          $v1, 0x64($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X64);
    // 0x800A8DE4: nop

    // 0x800A8DE8: lh          $t4, 0x0($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X0);
    // 0x800A8DEC: nop

    // 0x800A8DF0: bne         $s3, $t4, L_800A8DFC
    if (ctx->r19 != ctx->r12) {
        // 0x800A8DF4: nop
    
            goto L_800A8DFC;
    }
    // 0x800A8DF4: nop

    // 0x800A8DF8: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_800A8DFC:
    // 0x800A8DFC: bne         $a0, $a3, L_800A8D6C
    if (ctx->r4 != ctx->r7) {
        // 0x800A8E00: nop
    
            goto L_800A8D6C;
    }
    // 0x800A8E00: nop

L_800A8E04:
    // 0x800A8E04: beq         $a2, $zero, L_800A8FDC
    if (ctx->r6 == 0) {
        // 0x800A8E08: lui         $s2, 0x8012
        ctx->r18 = S32(0X8012 << 16);
            goto L_800A8FDC;
    }
    // 0x800A8E08: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800A8E0C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800A8E10: addiu       $s2, $s2, 0x729C
    ctx->r18 = ADD32(ctx->r18, 0X729C);
    // 0x800A8E14: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A8E18: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800A8E1C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A8E20: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A8E24: lwc1        $f18, 0x64C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X64C);
    // 0x800A8E28: lwc1        $f16, 0x650($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X650);
    // 0x800A8E2C: cvt.w.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800A8E30: lwc1        $f6, 0x66C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X66C);
    // 0x800A8E34: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800A8E38: lwc1        $f18, 0x670($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X670);
    // 0x800A8E3C: mfc1        $s0, $f8
    ctx->r16 = (int32_t)ctx->f8.u32l;
    // 0x800A8E40: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800A8E44: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x800A8E48: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800A8E4C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A8E50: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A8E54: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800A8E58: cvt.w.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800A8E5C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800A8E60: mfc1        $s1, $f4
    ctx->r17 = (int32_t)ctx->f4.u32l;
    // 0x800A8E64: nop

    // 0x800A8E68: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800A8E6C: nop

    // 0x800A8E70: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800A8E74: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A8E78: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A8E7C: nop

    // 0x800A8E80: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800A8E84: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800A8E88: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800A8E8C: nop

    // 0x800A8E90: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A8E94: nop

    // 0x800A8E98: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800A8E9C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A8EA0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A8EA4: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x800A8EA8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A8EAC: lui         $at, 0x435D
    ctx->r1 = S32(0X435D << 16);
    // 0x800A8EB0: swc1        $f16, 0x64C($v0)
    MEM_W(0X64C, ctx->r2) = ctx->f16.u32l;
    // 0x800A8EB4: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800A8EB8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A8EBC: lui         $at, 0x4345
    ctx->r1 = S32(0X4345 << 16);
    // 0x800A8EC0: swc1        $f4, 0x66C($t9)
    MEM_W(0X66C, ctx->r25) = ctx->f4.u32l;
    // 0x800A8EC4: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x800A8EC8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A8ECC: lui         $at, 0x4325
    ctx->r1 = S32(0X4325 << 16);
    // 0x800A8ED0: swc1        $f6, 0x670($t2)
    MEM_W(0X670, ctx->r10) = ctx->f6.u32l;
    // 0x800A8ED4: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x800A8ED8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A8EDC: cvt.w.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800A8EE0: swc1        $f10, 0x650($t3)
    MEM_W(0X650, ctx->r11) = ctx->f10.u32l;
    // 0x800A8EE4: lw          $t4, 0x300($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X300);
    // 0x800A8EE8: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x800A8EEC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A8EF0: bne         $t4, $zero, L_800A8F74
    if (ctx->r12 != 0) {
        // 0x800A8EF4: lui         $at, 0x800F
        ctx->r1 = S32(0X800F << 16);
            goto L_800A8F74;
    }
    // 0x800A8EF4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A8EF8: lwc1        $f1, -0x72E0($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X72E0);
    // 0x800A8EFC: lwc1        $f0, -0x72DC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X72DC);
    // 0x800A8F00: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A8F04: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800A8F08: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A8F0C: lwc1        $f18, 0x64C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X64C);
    // 0x800A8F10: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A8F14: sub.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x800A8F18: swc1        $f16, 0x64C($v0)
    MEM_W(0X64C, ctx->r2) = ctx->f16.u32l;
    // 0x800A8F1C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A8F20: nop

    // 0x800A8F24: lwc1        $f4, 0x66C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X66C);
    // 0x800A8F28: nop

    // 0x800A8F2C: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800A8F30: swc1        $f10, 0x66C($v0)
    MEM_W(0X66C, ctx->r2) = ctx->f10.u32l;
    // 0x800A8F34: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A8F38: nop

    // 0x800A8F3C: lwc1        $f18, 0x650($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X650);
    // 0x800A8F40: nop

    // 0x800A8F44: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x800A8F48: mul.d       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x800A8F4C: cvt.s.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f4.fl = CVT_S_D(ctx->f16.d);
    // 0x800A8F50: swc1        $f4, 0x650($v0)
    MEM_W(0X650, ctx->r2) = ctx->f4.u32l;
    // 0x800A8F54: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A8F58: nop

    // 0x800A8F5C: lwc1        $f6, 0x670($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X670);
    // 0x800A8F60: nop

    // 0x800A8F64: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x800A8F68: mul.d       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x800A8F6C: cvt.s.d     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f8.fl = CVT_S_D(ctx->f18.d);
    // 0x800A8F70: swc1        $f8, 0x670($v0)
    MEM_W(0X670, ctx->r2) = ctx->f8.u32l;
L_800A8F74:
    // 0x800A8F74: lw          $a1, 0x16C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X16C);
    // 0x800A8F78: sw          $v1, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r3;
    // 0x800A8F7C: jal         0x800A1EE4
    // 0x800A8F80: sw          $a3, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r7;
    hud_eggs_portrait(rdram, ctx);
        goto after_9;
    // 0x800A8F80: sw          $a3, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r7;
    after_9:
    // 0x800A8F84: mtc1        $s0, $f16
    ctx->f16.u32l = ctx->r16;
    // 0x800A8F88: addiu       $t5, $zero, -0x2
    ctx->r13 = ADD32(0, -0X2);
    // 0x800A8F8C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A8F90: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A8F94: sw          $t5, 0x2DB4($at)
    MEM_W(0X2DB4, ctx->r1) = ctx->r13;
    // 0x800A8F98: lw          $v1, 0xF4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XF4);
    // 0x800A8F9C: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x800A8FA0: mtc1        $s1, $f6
    ctx->f6.u32l = ctx->r17;
    // 0x800A8FA4: lw          $a3, 0xF0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XF0);
    // 0x800A8FA8: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A8FAC: swc1        $f4, 0x64C($t6)
    MEM_W(0X64C, ctx->r14) = ctx->f4.u32l;
    // 0x800A8FB0: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800A8FB4: mtc1        $v1, $f18
    ctx->f18.u32l = ctx->r3;
    // 0x800A8FB8: swc1        $f10, 0x650($t7)
    MEM_W(0X650, ctx->r15) = ctx->f10.u32l;
    // 0x800A8FBC: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800A8FC0: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x800A8FC4: mtc1        $a3, $f16
    ctx->f16.u32l = ctx->r7;
    // 0x800A8FC8: swc1        $f8, 0x66C($t8)
    MEM_W(0X66C, ctx->r24) = ctx->f8.u32l;
    // 0x800A8FCC: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A8FD0: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800A8FD4: nop

    // 0x800A8FD8: swc1        $f4, 0x670($t9)
    MEM_W(0X670, ctx->r25) = ctx->f4.u32l;
L_800A8FDC:
    // 0x800A8FDC: b           L_800A9C10
    // 0x800A8FE0: nop

        goto L_800A9C10;
    // 0x800A8FE0: nop

    // 0x800A8FE4: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
L_800A8FE8:
    // 0x800A8FE8: bne         $v1, $at, L_800A96B4
    if (ctx->r3 != ctx->r1) {
        // 0x800A8FEC: addiu       $at, $zero, 0x41
        ctx->r1 = ADD32(0, 0X41);
            goto L_800A96B4;
    }
    // 0x800A8FEC: addiu       $at, $zero, 0x41
    ctx->r1 = ADD32(0, 0X41);
    // 0x800A8FF0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A8FF4: lbu         $v1, 0x72F7($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X72F7);
    // 0x800A8FF8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A8FFC: bne         $v1, $at, L_800A906C
    if (ctx->r3 != ctx->r1) {
        // 0x800A9000: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_800A906C;
    }
    // 0x800A9000: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800A9004: lw          $t2, 0x72CC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X72CC);
    // 0x800A9008: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800A900C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800A9010: lb          $t3, 0x2D24($t3)
    ctx->r11 = MEM_B(ctx->r11, 0X2D24);
    // 0x800A9014: nop

    // 0x800A9018: bne         $t3, $zero, L_800A9070
    if (ctx->r11 != 0) {
        // 0x800A901C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800A9070;
    }
    // 0x800A901C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A9020: jal         0x80068748
    // 0x800A9024: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_10;
    // 0x800A9024: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_10:
    // 0x800A9028: jal         0x8007C36C
    // 0x800A902C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_11;
    // 0x800A902C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_11:
    // 0x800A9030: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A9034: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A9038: jal         0x8006816C
    // 0x800A903C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    mtx_ortho(rdram, ctx);
        goto after_12;
    // 0x800A903C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_12:
    // 0x800A9040: lw          $a1, 0x16C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X16C);
    // 0x800A9044: jal         0x800A2388
    // 0x800A9048: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    hud_battle_portraits(rdram, ctx);
        goto after_13;
    // 0x800A9048: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_13:
    // 0x800A904C: jal         0x80068748
    // 0x800A9050: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_14;
    // 0x800A9050: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_14:
    // 0x800A9054: jal         0x8007B820
    // 0x800A9058: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    rendermode_reset(rdram, ctx);
        goto after_15;
    // 0x800A9058: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_15:
    // 0x800A905C: jal         0x8007C36C
    // 0x800A9060: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprite_opaque(rdram, ctx);
        goto after_16;
    // 0x800A9060: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_16:
    // 0x800A9064: b           L_800A9C10
    // 0x800A9068: nop

        goto L_800A9C10;
    // 0x800A9068: nop

L_800A906C:
    // 0x800A906C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_800A9070:
    // 0x800A9070: bne         $v1, $at, L_800A96A8
    if (ctx->r3 != ctx->r1) {
        // 0x800A9074: nop
    
            goto L_800A96A8;
    }
    // 0x800A9074: nop

    // 0x800A9078: lw          $t4, 0x140($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X140);
    // 0x800A907C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800A9080: blez        $t4, L_800A918C
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800A9084: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800A918C;
    }
    // 0x800A9084: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A9088: andi        $t0, $t4, 0x3
    ctx->r8 = ctx->r12 & 0X3;
    // 0x800A908C: beq         $t0, $zero, L_800A90DC
    if (ctx->r8 == 0) {
        // 0x800A9090: or          $a2, $t0, $zero
        ctx->r6 = ctx->r8 | 0;
            goto L_800A90DC;
    }
    // 0x800A9090: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x800A9094: sll         $t5, $zero, 2
    ctx->r13 = S32(0 << 2);
    // 0x800A9098: addu        $a0, $v0, $t5
    ctx->r4 = ADD32(ctx->r2, ctx->r13);
    // 0x800A909C: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
L_800A90A0:
    // 0x800A90A0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800A90A4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800A90A8: lw          $v1, 0x64($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X64);
    // 0x800A90AC: nop

    // 0x800A90B0: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x800A90B4: nop

    // 0x800A90B8: bne         $s3, $t7, L_800A90C4
    if (ctx->r19 != ctx->r15) {
        // 0x800A90BC: nop
    
            goto L_800A90C4;
    }
    // 0x800A90BC: nop

    // 0x800A90C0: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
L_800A90C4:
    // 0x800A90C4: bne         $a2, $a1, L_800A90A0
    if (ctx->r6 != ctx->r5) {
        // 0x800A90C8: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_800A90A0;
    }
    // 0x800A90C8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800A90CC: lw          $t8, 0x140($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X140);
    // 0x800A90D0: nop

    // 0x800A90D4: beq         $a1, $t8, L_800A918C
    if (ctx->r5 == ctx->r24) {
        // 0x800A90D8: nop
    
            goto L_800A918C;
    }
    // 0x800A90D8: nop

L_800A90DC:
    // 0x800A90DC: lw          $t9, 0x140($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X140);
    // 0x800A90E0: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x800A90E4: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x800A90E8: addu        $a2, $t2, $v0
    ctx->r6 = ADD32(ctx->r10, ctx->r2);
    // 0x800A90EC: addu        $a0, $v0, $t3
    ctx->r4 = ADD32(ctx->r2, ctx->r11);
    // 0x800A90F0: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
L_800A90F4:
    // 0x800A90F4: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x800A90F8: nop

    // 0x800A90FC: lw          $v1, 0x64($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X64);
    // 0x800A9100: nop

    // 0x800A9104: lh          $t5, 0x0($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X0);
    // 0x800A9108: nop

    // 0x800A910C: bne         $s3, $t5, L_800A9118
    if (ctx->r19 != ctx->r13) {
        // 0x800A9110: nop
    
            goto L_800A9118;
    }
    // 0x800A9110: nop

    // 0x800A9114: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
L_800A9118:
    // 0x800A9118: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800A911C: nop

    // 0x800A9120: lw          $v1, 0x64($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X64);
    // 0x800A9124: nop

    // 0x800A9128: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x800A912C: nop

    // 0x800A9130: bne         $s3, $t7, L_800A913C
    if (ctx->r19 != ctx->r15) {
        // 0x800A9134: nop
    
            goto L_800A913C;
    }
    // 0x800A9134: nop

    // 0x800A9138: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
L_800A913C:
    // 0x800A913C: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    // 0x800A9140: nop

    // 0x800A9144: lw          $v1, 0x64($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X64);
    // 0x800A9148: nop

    // 0x800A914C: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    // 0x800A9150: nop

    // 0x800A9154: bne         $s3, $t9, L_800A9160
    if (ctx->r19 != ctx->r25) {
        // 0x800A9158: nop
    
            goto L_800A9160;
    }
    // 0x800A9158: nop

    // 0x800A915C: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
L_800A9160:
    // 0x800A9160: lw          $t2, 0xC($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XC);
    // 0x800A9164: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800A9168: lw          $v1, 0x64($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X64);
    // 0x800A916C: nop

    // 0x800A9170: lh          $t3, 0x0($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X0);
    // 0x800A9174: nop

    // 0x800A9178: bne         $s3, $t3, L_800A9184
    if (ctx->r19 != ctx->r11) {
        // 0x800A917C: nop
    
            goto L_800A9184;
    }
    // 0x800A917C: nop

    // 0x800A9180: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
L_800A9184:
    // 0x800A9184: bne         $a0, $a2, L_800A90F4
    if (ctx->r4 != ctx->r6) {
        // 0x800A9188: nop
    
            goto L_800A90F4;
    }
    // 0x800A9188: nop

L_800A918C:
    // 0x800A918C: beq         $s0, $zero, L_800A96A8
    if (ctx->r16 == 0) {
        // 0x800A9190: lui         $s2, 0x8012
        ctx->r18 = S32(0X8012 << 16);
            goto L_800A96A8;
    }
    // 0x800A9190: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800A9194: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800A9198: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800A919C: lw          $t4, 0x72AC($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X72AC);
    // 0x800A91A0: addiu       $s2, $s2, 0x729C
    ctx->r18 = ADD32(ctx->r18, 0X729C);
    // 0x800A91A4: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800A91A8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A91AC: sw          $t4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r12;
    // 0x800A91B0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A91B4: lwc1        $f6, 0x64C($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X64C);
    // 0x800A91B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A91BC: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800A91C0: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800A91C4: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x800A91C8: nop

    // 0x800A91CC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800A91D0: sw          $t6, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r14;
    // 0x800A91D4: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800A91D8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A91DC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A91E0: lwc1        $f18, 0x650($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X650);
    // 0x800A91E4: nop

    // 0x800A91E8: cvt.w.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800A91EC: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x800A91F0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800A91F4: jal         0x8007C36C
    // 0x800A91F8: sw          $t8, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r24;
    sprite_opaque(rdram, ctx);
        goto after_17;
    // 0x800A91F8: sw          $t8, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r24;
    after_17:
    // 0x800A91FC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A9200: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A9204: jal         0x8006816C
    // 0x800A9208: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    mtx_ortho(rdram, ctx);
        goto after_18;
    // 0x800A9208: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_18:
    // 0x800A920C: jal         0x80068748
    // 0x800A9210: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_19;
    // 0x800A9210: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_19:
    // 0x800A9214: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x800A9218: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A921C: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800A9220: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x800A9224: swc1        $f16, 0x64C($t9)
    MEM_W(0X64C, ctx->r25) = ctx->f16.u32l;
    // 0x800A9228: lw          $t2, 0x300($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X300);
    // 0x800A922C: lui         $t5, 0x8000
    ctx->r13 = S32(0X8000 << 16);
    // 0x800A9230: bne         $t2, $zero, L_800A924C
    if (ctx->r10 != 0) {
        // 0x800A9234: lui         $s1, 0x8012
        ctx->r17 = S32(0X8012 << 16);
            goto L_800A924C;
    }
    // 0x800A9234: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800A9238: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A923C: lwc1        $f4, -0x72D8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X72D8);
    // 0x800A9240: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x800A9244: b           L_800A9260
    // 0x800A9248: swc1        $f4, 0x650($t3)
    MEM_W(0X650, ctx->r11) = ctx->f4.u32l;
        goto L_800A9260;
    // 0x800A9248: swc1        $f4, 0x650($t3)
    MEM_W(0X650, ctx->r11) = ctx->f4.u32l;
L_800A924C:
    // 0x800A924C: lui         $at, 0x4325
    ctx->r1 = S32(0X4325 << 16);
    // 0x800A9250: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A9254: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x800A9258: nop

    // 0x800A925C: swc1        $f6, 0x650($t4)
    MEM_W(0X650, ctx->r12) = ctx->f6.u32l;
L_800A9260:
    // 0x800A9260: lw          $t5, 0x300($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X300);
    // 0x800A9264: addiu       $s1, $s1, 0x7295
    ctx->r17 = ADD32(ctx->r17, 0X7295);
    // 0x800A9268: bne         $t5, $zero, L_800A92EC
    if (ctx->r13 != 0) {
        // 0x800A926C: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_800A92EC;
    }
    // 0x800A926C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A9270: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9274: lui         $at, 0x4284
    ctx->r1 = S32(0X4284 << 16);
    // 0x800A9278: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A927C: lwc1        $f12, 0x36C($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X36C);
    // 0x800A9280: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800A9284: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A9288: sub.s       $f18, $f10, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x800A928C: lwc1        $f10, 0x370($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X370);
    // 0x800A9290: sub.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x800A9294: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800A9298: nop

    // 0x800A929C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800A92A0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A92A4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A92A8: lui         $at, 0xC2E4
    ctx->r1 = S32(0XC2E4 << 16);
    // 0x800A92AC: cvt.w.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800A92B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A92B4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800A92B8: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x800A92BC: sub.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800A92C0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800A92C4: nop

    // 0x800A92C8: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800A92CC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A92D0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A92D4: nop

    // 0x800A92D8: cvt.w.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800A92DC: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x800A92E0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800A92E4: b           L_800A935C
    // 0x800A92E8: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
        goto L_800A935C;
    // 0x800A92E8: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
L_800A92EC:
    // 0x800A92EC: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A92F0: lui         $at, 0x4284
    ctx->r1 = S32(0X4284 << 16);
    // 0x800A92F4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A92F8: lwc1        $f12, 0x36C($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X36C);
    // 0x800A92FC: lwc1        $f18, 0x370($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X370);
    // 0x800A9300: sub.s       $f4, $f16, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x800A9304: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A9308: nop

    // 0x800A930C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800A9310: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A9314: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A9318: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x800A931C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A9320: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A9324: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A9328: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x800A932C: sub.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800A9330: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800A9334: nop

    // 0x800A9338: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800A933C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A9340: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A9344: nop

    // 0x800A9348: cvt.w.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A934C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800A9350: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x800A9354: nop

    // 0x800A9358: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
L_800A935C:
    // 0x800A935C: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x800A9360: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A9364: addiu       $t2, $v1, 0x1
    ctx->r10 = ADD32(ctx->r3, 0X1);
    // 0x800A9368: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x800A936C: add.s       $f6, $f12, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x800A9370: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A9374: swc1        $f6, 0x36C($v0)
    MEM_W(0X36C, ctx->r2) = ctx->f6.u32l;
    // 0x800A9378: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A937C: cvt.s.w     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    ctx->f2.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A9380: lwc1        $f18, 0x370($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X370);
    // 0x800A9384: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800A9388: add.s       $f8, $f18, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x800A938C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800A9390: swc1        $f8, 0x370($v0)
    MEM_W(0X370, ctx->r2) = ctx->f8.u32l;
    // 0x800A9394: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9398: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A939C: lwc1        $f16, 0xEC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XEC);
    // 0x800A93A0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800A93A4: add.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x800A93A8: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A93AC: swc1        $f4, 0xEC($v0)
    MEM_W(0XEC, ctx->r2) = ctx->f4.u32l;
    // 0x800A93B0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A93B4: nop

    // 0x800A93B8: lwc1        $f6, 0xF0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XF0);
    // 0x800A93BC: nop

    // 0x800A93C0: add.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x800A93C4: swc1        $f10, 0xF0($v0)
    MEM_W(0XF0, ctx->r2) = ctx->f10.u32l;
    // 0x800A93C8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A93CC: nop

    // 0x800A93D0: lwc1        $f18, 0x38C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X38C);
    // 0x800A93D4: nop

    // 0x800A93D8: add.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x800A93DC: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x800A93E0: swc1        $f8, 0x38C($v0)
    MEM_W(0X38C, ctx->r2) = ctx->f8.u32l;
    // 0x800A93E4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A93E8: cvt.s.w     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800A93EC: lwc1        $f16, 0x390($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X390);
    // 0x800A93F0: nop

    // 0x800A93F4: add.s       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x800A93F8: swc1        $f4, 0x390($v0)
    MEM_W(0X390, ctx->r2) = ctx->f4.u32l;
    // 0x800A93FC: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9400: nop

    // 0x800A9404: lwc1        $f6, 0x10C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10C);
    // 0x800A9408: nop

    // 0x800A940C: add.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800A9410: swc1        $f10, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = ctx->f10.u32l;
    // 0x800A9414: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9418: nop

    // 0x800A941C: lwc1        $f8, 0x110($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X110);
    // 0x800A9420: nop

    // 0x800A9424: sub.s       $f16, $f8, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x800A9428: swc1        $f16, 0x110($v0)
    MEM_W(0X110, ctx->r2) = ctx->f16.u32l;
    // 0x800A942C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9430: nop

    // 0x800A9434: lwc1        $f4, 0x12C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X12C);
    // 0x800A9438: nop

    // 0x800A943C: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800A9440: swc1        $f6, 0x12C($v0)
    MEM_W(0X12C, ctx->r2) = ctx->f6.u32l;
    // 0x800A9444: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9448: nop

    // 0x800A944C: lwc1        $f10, 0x130($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X130);
    // 0x800A9450: nop

    // 0x800A9454: sub.s       $f18, $f10, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x800A9458: swc1        $f18, 0x130($v0)
    MEM_W(0X130, ctx->r2) = ctx->f18.u32l;
    // 0x800A945C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9460: nop

    // 0x800A9464: lwc1        $f8, 0x24C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X24C);
    // 0x800A9468: nop

    // 0x800A946C: add.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x800A9470: swc1        $f16, 0x24C($v0)
    MEM_W(0X24C, ctx->r2) = ctx->f16.u32l;
    // 0x800A9474: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9478: nop

    // 0x800A947C: lwc1        $f4, 0x250($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X250);
    // 0x800A9480: nop

    // 0x800A9484: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x800A9488: swc1        $f6, 0x250($v0)
    MEM_W(0X250, ctx->r2) = ctx->f6.u32l;
    // 0x800A948C: lb          $t3, 0x3($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X3);
    // 0x800A9490: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x800A9494: addiu       $t4, $t3, 0x38
    ctx->r12 = ADD32(ctx->r11, 0X38);
    // 0x800A9498: sh          $t4, 0x646($t5)
    MEM_H(0X646, ctx->r13) = ctx->r12;
    // 0x800A949C: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x800A94A0: nop

    // 0x800A94A4: bne         $t6, $zero, L_800A94DC
    if (ctx->r14 != 0) {
        // 0x800A94A8: nop
    
            goto L_800A94DC;
    }
    // 0x800A94A8: nop

    // 0x800A94AC: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A94B0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A94B4: lwc1        $f10, 0x64C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X64C);
    // 0x800A94B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A94BC: sub.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800A94C0: swc1        $f8, 0x64C($v0)
    MEM_W(0X64C, ctx->r2) = ctx->f8.u32l;
    // 0x800A94C4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A94C8: nop

    // 0x800A94CC: lwc1        $f16, 0x66C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X66C);
    // 0x800A94D0: nop

    // 0x800A94D4: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x800A94D8: swc1        $f6, 0x66C($v0)
    MEM_W(0X66C, ctx->r2) = ctx->f6.u32l;
L_800A94DC:
    // 0x800A94DC: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x800A94E0: sb          $t7, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r15;
    // 0x800A94E4: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x800A94E8: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
    // 0x800A94EC: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    // 0x800A94F0: jal         0x800AAB5C
    // 0x800A94F4: addiu       $a3, $a3, 0x640
    ctx->r7 = ADD32(ctx->r7, 0X640);
    hud_element_render(rdram, ctx);
        goto after_20;
    // 0x800A94F4: addiu       $a3, $a3, 0x640
    ctx->r7 = ADD32(ctx->r7, 0X640);
    after_20:
    // 0x800A94F8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A94FC: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
    // 0x800A9500: lb          $t8, 0xFB($v0)
    ctx->r24 = MEM_B(ctx->r2, 0XFB);
    // 0x800A9504: lwc1        $f0, 0x4C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800A9508: lwc1        $f2, 0x48($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800A950C: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800A9510: bne         $t8, $zero, L_800A952C
    if (ctx->r24 != 0) {
        // 0x800A9514: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A952C;
    }
    // 0x800A9514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A9518: lb          $v1, 0x185($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X185);
    // 0x800A951C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800A9520: bne         $v1, $at, L_800A9530
    if (ctx->r3 != ctx->r1) {
        // 0x800A9524: lw          $a1, 0x16C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X16C);
            goto L_800A9530;
    }
    // 0x800A9524: lw          $a1, 0x16C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X16C);
    // 0x800A9528: sb          $v1, 0xFB($v0)
    MEM_B(0XFB, ctx->r2) = ctx->r3;
L_800A952C:
    // 0x800A952C: lw          $a1, 0x16C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X16C);
L_800A9530:
    // 0x800A9530: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x800A9534: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
    // 0x800A9538: jal         0x800A469C
    // 0x800A953C: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    hud_bananas(rdram, ctx);
        goto after_21;
    // 0x800A953C: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    after_21:
    // 0x800A9540: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9544: lwc1        $f0, 0x4C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800A9548: lwc1        $f10, 0x36C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X36C);
    // 0x800A954C: lwc1        $f2, 0x48($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800A9550: sub.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x800A9554: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800A9558: swc1        $f18, 0x36C($v0)
    MEM_W(0X36C, ctx->r2) = ctx->f18.u32l;
    // 0x800A955C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9560: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A9564: lwc1        $f8, 0x370($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X370);
    // 0x800A9568: nop

    // 0x800A956C: sub.s       $f16, $f8, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x800A9570: swc1        $f16, 0x370($v0)
    MEM_W(0X370, ctx->r2) = ctx->f16.u32l;
    // 0x800A9574: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9578: nop

    // 0x800A957C: lwc1        $f4, 0xEC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XEC);
    // 0x800A9580: nop

    // 0x800A9584: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800A9588: swc1        $f6, 0xEC($v0)
    MEM_W(0XEC, ctx->r2) = ctx->f6.u32l;
    // 0x800A958C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9590: nop

    // 0x800A9594: lwc1        $f10, 0xF0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XF0);
    // 0x800A9598: nop

    // 0x800A959C: sub.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x800A95A0: swc1        $f18, 0xF0($v0)
    MEM_W(0XF0, ctx->r2) = ctx->f18.u32l;
    // 0x800A95A4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A95A8: nop

    // 0x800A95AC: lwc1        $f8, 0x38C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X38C);
    // 0x800A95B0: nop

    // 0x800A95B4: sub.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x800A95B8: swc1        $f16, 0x38C($v0)
    MEM_W(0X38C, ctx->r2) = ctx->f16.u32l;
    // 0x800A95BC: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A95C0: nop

    // 0x800A95C4: lwc1        $f4, 0x390($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X390);
    // 0x800A95C8: nop

    // 0x800A95CC: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x800A95D0: swc1        $f6, 0x390($v0)
    MEM_W(0X390, ctx->r2) = ctx->f6.u32l;
    // 0x800A95D4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A95D8: nop

    // 0x800A95DC: lwc1        $f10, 0x10C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10C);
    // 0x800A95E0: nop

    // 0x800A95E4: sub.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x800A95E8: swc1        $f18, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = ctx->f18.u32l;
    // 0x800A95EC: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A95F0: nop

    // 0x800A95F4: lwc1        $f8, 0x110($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X110);
    // 0x800A95F8: nop

    // 0x800A95FC: add.s       $f16, $f8, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f14.fl;
    // 0x800A9600: swc1        $f16, 0x110($v0)
    MEM_W(0X110, ctx->r2) = ctx->f16.u32l;
    // 0x800A9604: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9608: nop

    // 0x800A960C: lwc1        $f4, 0x12C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X12C);
    // 0x800A9610: nop

    // 0x800A9614: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800A9618: swc1        $f6, 0x12C($v0)
    MEM_W(0X12C, ctx->r2) = ctx->f6.u32l;
    // 0x800A961C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9620: nop

    // 0x800A9624: lwc1        $f10, 0x130($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X130);
    // 0x800A9628: nop

    // 0x800A962C: add.s       $f18, $f10, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f14.fl;
    // 0x800A9630: swc1        $f18, 0x130($v0)
    MEM_W(0X130, ctx->r2) = ctx->f18.u32l;
    // 0x800A9634: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9638: nop

    // 0x800A963C: lwc1        $f8, 0x24C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X24C);
    // 0x800A9640: nop

    // 0x800A9644: sub.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x800A9648: swc1        $f16, 0x24C($v0)
    MEM_W(0X24C, ctx->r2) = ctx->f16.u32l;
    // 0x800A964C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9650: nop

    // 0x800A9654: lwc1        $f4, 0x250($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X250);
    // 0x800A9658: nop

    // 0x800A965C: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800A9660: swc1        $f6, 0x250($v0)
    MEM_W(0X250, ctx->r2) = ctx->f6.u32l;
    // 0x800A9664: lw          $t9, 0xE4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE4);
    // 0x800A9668: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x800A966C: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x800A9670: nop

    // 0x800A9674: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A9678: swc1        $f18, 0x64C($t2)
    MEM_W(0X64C, ctx->r10) = ctx->f18.u32l;
    // 0x800A967C: lw          $t3, 0xE0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XE0);
    // 0x800A9680: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x800A9684: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x800A9688: nop

    // 0x800A968C: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A9690: jal         0x8007C36C
    // 0x800A9694: swc1        $f16, 0x650($t4)
    MEM_W(0X650, ctx->r12) = ctx->f16.u32l;
    sprite_opaque(rdram, ctx);
        goto after_22;
    // 0x800A9694: swc1        $f16, 0x650($t4)
    MEM_W(0X650, ctx->r12) = ctx->f16.u32l;
    after_22:
    // 0x800A9698: jal         0x8007B820
    // 0x800A969C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    rendermode_reset(rdram, ctx);
        goto after_23;
    // 0x800A969C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_23:
    // 0x800A96A0: jal         0x80068748
    // 0x800A96A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_24;
    // 0x800A96A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_24:
L_800A96A8:
    // 0x800A96A8: b           L_800A9C10
    // 0x800A96AC: nop

        goto L_800A9C10;
    // 0x800A96AC: nop

    // 0x800A96B0: addiu       $at, $zero, 0x41
    ctx->r1 = ADD32(0, 0X41);
L_800A96B4:
    // 0x800A96B4: bne         $v1, $at, L_800A9C10
    if (ctx->r3 != ctx->r1) {
        // 0x800A96B8: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_800A9C10;
    }
    // 0x800A96B8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A96BC: lbu         $v1, 0x72F7($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X72F7);
    // 0x800A96C0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A96C4: bne         $v1, $at, L_800A98B8
    if (ctx->r3 != ctx->r1) {
        // 0x800A96C8: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_800A98B8;
    }
    // 0x800A96C8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800A96CC: lw          $t5, 0x72CC($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X72CC);
    // 0x800A96D0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800A96D4: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800A96D8: lb          $t6, 0x2D24($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X2D24);
    // 0x800A96DC: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800A96E0: bne         $t6, $zero, L_800A98B8
    if (ctx->r14 != 0) {
        // 0x800A96E4: addiu       $s2, $s2, 0x729C
        ctx->r18 = ADD32(ctx->r18, 0X729C);
            goto L_800A98B8;
    }
    // 0x800A96E4: addiu       $s2, $s2, 0x729C
    ctx->r18 = ADD32(ctx->r18, 0X729C);
    // 0x800A96E8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800A96EC: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A96F0: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800A96F4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A96F8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A96FC: lwc1        $f4, 0x64C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X64C);
    // 0x800A9700: lwc1        $f10, 0x650($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X650);
    // 0x800A9704: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A9708: lwc1        $f8, 0x40C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X40C);
    // 0x800A970C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800A9710: lwc1        $f4, 0x410($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X410);
    // 0x800A9714: mfc1        $s0, $f6
    ctx->r16 = (int32_t)ctx->f6.u32l;
    // 0x800A9718: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A971C: addiu       $a0, $sp, 0xCC
    ctx->r4 = ADD32(ctx->r29, 0XCC);
    // 0x800A9720: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800A9724: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A9728: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A972C: nop

    // 0x800A9730: cvt.w.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800A9734: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A9738: mfc1        $s1, $f18
    ctx->r17 = (int32_t)ctx->f18.u32l;
    // 0x800A973C: nop

    // 0x800A9740: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800A9744: nop

    // 0x800A9748: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800A974C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A9750: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A9754: nop

    // 0x800A9758: cvt.w.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A975C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800A9760: mfc1        $s3, $f16
    ctx->r19 = (int32_t)ctx->f16.u32l;
    // 0x800A9764: nop

    // 0x800A9768: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800A976C: nop

    // 0x800A9770: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800A9774: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A9778: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A977C: nop

    // 0x800A9780: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A9784: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x800A9788: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800A978C: jal         0x8001BAA8
    // 0x800A9790: sw          $t3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r11;
    get_racer_objects(rdram, ctx);
        goto after_25;
    // 0x800A9790: sw          $t3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r11;
    after_25:
    // 0x800A9794: lw          $t4, 0xCC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XCC);
    // 0x800A9798: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800A979C: blez        $t4, L_800A9868
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800A97A0: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800A9868;
    }
    // 0x800A97A0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_800A97A4:
    // 0x800A97A4: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x800A97A8: nop

    // 0x800A97AC: lw          $a0, 0x64($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X64);
    // 0x800A97B0: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    // 0x800A97B4: jal         0x800A4B38
    // 0x800A97B8: sw          $v1, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r3;
    hud_treasure(rdram, ctx);
        goto after_26;
    // 0x800A97B8: sw          $v1, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r3;
    after_26:
    // 0x800A97BC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A97C0: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x800A97C4: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x800A97C8: lwc1        $f1, -0x72C8($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X72C8);
    // 0x800A97CC: lwc1        $f0, -0x72C4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X72C4);
    // 0x800A97D0: lw          $v1, 0xD0($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XD0);
    // 0x800A97D4: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x800A97D8: bne         $t6, $zero, L_800A9824
    if (ctx->r14 != 0) {
        // 0x800A97DC: lui         $at, 0x425C
        ctx->r1 = S32(0X425C << 16);
            goto L_800A9824;
    }
    // 0x800A97DC: lui         $at, 0x425C
    ctx->r1 = S32(0X425C << 16);
    // 0x800A97E0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A97E4: nop

    // 0x800A97E8: lwc1        $f10, 0x650($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X650);
    // 0x800A97EC: nop

    // 0x800A97F0: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x800A97F4: add.d       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f18.d + ctx->f0.d;
    // 0x800A97F8: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x800A97FC: swc1        $f16, 0x650($v0)
    MEM_W(0X650, ctx->r2) = ctx->f16.u32l;
    // 0x800A9800: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9804: nop

    // 0x800A9808: lwc1        $f4, 0x410($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X410);
    // 0x800A980C: nop

    // 0x800A9810: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800A9814: add.d       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f6.d + ctx->f0.d;
    // 0x800A9818: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x800A981C: b           L_800A9854
    // 0x800A9820: swc1        $f18, 0x410($v0)
    MEM_W(0X410, ctx->r2) = ctx->f18.u32l;
        goto L_800A9854;
    // 0x800A9820: swc1        $f18, 0x410($v0)
    MEM_W(0X410, ctx->r2) = ctx->f18.u32l;
L_800A9824:
    // 0x800A9824: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9828: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A982C: lwc1        $f8, 0x650($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X650);
    // 0x800A9830: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A9834: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800A9838: swc1        $f4, 0x650($v0)
    MEM_W(0X650, ctx->r2) = ctx->f4.u32l;
    // 0x800A983C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9840: nop

    // 0x800A9844: lwc1        $f6, 0x410($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X410);
    // 0x800A9848: nop

    // 0x800A984C: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800A9850: swc1        $f18, 0x410($v0)
    MEM_W(0X410, ctx->r2) = ctx->f18.u32l;
L_800A9854:
    // 0x800A9854: lw          $t7, 0xCC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XCC);
    // 0x800A9858: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800A985C: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800A9860: bne         $at, $zero, L_800A97A4
    if (ctx->r1 != 0) {
        // 0x800A9864: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_800A97A4;
    }
    // 0x800A9864: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
L_800A9868:
    // 0x800A9868: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
    // 0x800A986C: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x800A9870: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A9874: mtc1        $s1, $f4
    ctx->f4.u32l = ctx->r17;
    // 0x800A9878: mtc1        $s3, $f10
    ctx->f10.u32l = ctx->r19;
    // 0x800A987C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A9880: swc1        $f16, 0x64C($t8)
    MEM_W(0X64C, ctx->r24) = ctx->f16.u32l;
    // 0x800A9884: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800A9888: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A988C: swc1        $f6, 0x650($t9)
    MEM_W(0X650, ctx->r25) = ctx->f6.u32l;
    // 0x800A9890: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x800A9894: nop

    // 0x800A9898: swc1        $f18, 0x40C($t2)
    MEM_W(0X40C, ctx->r10) = ctx->f18.u32l;
    // 0x800A989C: lw          $t3, 0xBC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XBC);
    // 0x800A98A0: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x800A98A4: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x800A98A8: nop

    // 0x800A98AC: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A98B0: b           L_800A9C10
    // 0x800A98B4: swc1        $f16, 0x410($t4)
    MEM_W(0X410, ctx->r12) = ctx->f16.u32l;
        goto L_800A9C10;
    // 0x800A98B4: swc1        $f16, 0x410($t4)
    MEM_W(0X410, ctx->r12) = ctx->f16.u32l;
L_800A98B8:
    // 0x800A98B8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A98BC: bne         $v1, $at, L_800A9C10
    if (ctx->r3 != ctx->r1) {
        // 0x800A98C0: nop
    
            goto L_800A9C10;
    }
    // 0x800A98C0: nop

    // 0x800A98C4: lw          $t5, 0x140($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X140);
    // 0x800A98C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800A98CC: blez        $t5, L_800A99D8
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800A98D0: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800A99D8;
    }
    // 0x800A98D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A98D4: andi        $t0, $t5, 0x3
    ctx->r8 = ctx->r13 & 0X3;
    // 0x800A98D8: beq         $t0, $zero, L_800A9928
    if (ctx->r8 == 0) {
        // 0x800A98DC: or          $a3, $t0, $zero
        ctx->r7 = ctx->r8 | 0;
            goto L_800A9928;
    }
    // 0x800A98DC: or          $a3, $t0, $zero
    ctx->r7 = ctx->r8 | 0;
    // 0x800A98E0: sll         $t6, $zero, 2
    ctx->r14 = S32(0 << 2);
    // 0x800A98E4: addu        $a0, $v0, $t6
    ctx->r4 = ADD32(ctx->r2, ctx->r14);
    // 0x800A98E8: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
L_800A98EC:
    // 0x800A98EC: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800A98F0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800A98F4: lw          $v1, 0x64($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X64);
    // 0x800A98F8: nop

    // 0x800A98FC: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x800A9900: nop

    // 0x800A9904: bne         $s3, $t8, L_800A9910
    if (ctx->r19 != ctx->r24) {
        // 0x800A9908: nop
    
            goto L_800A9910;
    }
    // 0x800A9908: nop

    // 0x800A990C: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_800A9910:
    // 0x800A9910: bne         $a3, $a1, L_800A98EC
    if (ctx->r7 != ctx->r5) {
        // 0x800A9914: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_800A98EC;
    }
    // 0x800A9914: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800A9918: lw          $t9, 0x140($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X140);
    // 0x800A991C: nop

    // 0x800A9920: beq         $a1, $t9, L_800A99D8
    if (ctx->r5 == ctx->r25) {
        // 0x800A9924: nop
    
            goto L_800A99D8;
    }
    // 0x800A9924: nop

L_800A9928:
    // 0x800A9928: lw          $t2, 0x140($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X140);
    // 0x800A992C: sll         $t4, $a1, 2
    ctx->r12 = S32(ctx->r5 << 2);
    // 0x800A9930: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800A9934: addu        $a3, $t3, $v0
    ctx->r7 = ADD32(ctx->r11, ctx->r2);
    // 0x800A9938: addu        $a0, $v0, $t4
    ctx->r4 = ADD32(ctx->r2, ctx->r12);
    // 0x800A993C: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
L_800A9940:
    // 0x800A9940: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x800A9944: nop

    // 0x800A9948: lw          $v1, 0x64($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X64);
    // 0x800A994C: nop

    // 0x800A9950: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x800A9954: nop

    // 0x800A9958: bne         $s3, $t6, L_800A9964
    if (ctx->r19 != ctx->r14) {
        // 0x800A995C: nop
    
            goto L_800A9964;
    }
    // 0x800A995C: nop

    // 0x800A9960: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_800A9964:
    // 0x800A9964: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x800A9968: nop

    // 0x800A996C: lw          $v1, 0x64($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X64);
    // 0x800A9970: nop

    // 0x800A9974: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x800A9978: nop

    // 0x800A997C: bne         $s3, $t8, L_800A9988
    if (ctx->r19 != ctx->r24) {
        // 0x800A9980: nop
    
            goto L_800A9988;
    }
    // 0x800A9980: nop

    // 0x800A9984: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_800A9988:
    // 0x800A9988: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800A998C: nop

    // 0x800A9990: lw          $v1, 0x64($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X64);
    // 0x800A9994: nop

    // 0x800A9998: lh          $t2, 0x0($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X0);
    // 0x800A999C: nop

    // 0x800A99A0: bne         $s3, $t2, L_800A99AC
    if (ctx->r19 != ctx->r10) {
        // 0x800A99A4: nop
    
            goto L_800A99AC;
    }
    // 0x800A99A4: nop

    // 0x800A99A8: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_800A99AC:
    // 0x800A99AC: lw          $t3, 0xC($a0)
    ctx->r11 = MEM_W(ctx->r4, 0XC);
    // 0x800A99B0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800A99B4: lw          $v1, 0x64($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X64);
    // 0x800A99B8: nop

    // 0x800A99BC: lh          $t4, 0x0($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X0);
    // 0x800A99C0: nop

    // 0x800A99C4: bne         $s3, $t4, L_800A99D0
    if (ctx->r19 != ctx->r12) {
        // 0x800A99C8: nop
    
            goto L_800A99D0;
    }
    // 0x800A99C8: nop

    // 0x800A99CC: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_800A99D0:
    // 0x800A99D0: bne         $a0, $a3, L_800A9940
    if (ctx->r4 != ctx->r7) {
        // 0x800A99D4: nop
    
            goto L_800A9940;
    }
    // 0x800A99D4: nop

L_800A99D8:
    // 0x800A99D8: beq         $a2, $zero, L_800A9C10
    if (ctx->r6 == 0) {
        // 0x800A99DC: lui         $s2, 0x8012
        ctx->r18 = S32(0X8012 << 16);
            goto L_800A9C10;
    }
    // 0x800A99DC: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800A99E0: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800A99E4: addiu       $s2, $s2, 0x729C
    ctx->r18 = ADD32(ctx->r18, 0X729C);
    // 0x800A99E8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A99EC: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800A99F0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A99F4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A99F8: lwc1        $f4, 0x64C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X64C);
    // 0x800A99FC: lwc1        $f10, 0x650($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X650);
    // 0x800A9A00: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A9A04: lwc1        $f8, 0x40C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X40C);
    // 0x800A9A08: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800A9A0C: lwc1        $f4, 0x410($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X410);
    // 0x800A9A10: mfc1        $s0, $f6
    ctx->r16 = (int32_t)ctx->f6.u32l;
    // 0x800A9A14: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800A9A18: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x800A9A1C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800A9A20: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A9A24: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A9A28: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800A9A2C: cvt.w.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800A9A30: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800A9A34: mfc1        $s1, $f18
    ctx->r17 = (int32_t)ctx->f18.u32l;
    // 0x800A9A38: nop

    // 0x800A9A3C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800A9A40: nop

    // 0x800A9A44: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800A9A48: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A9A4C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A9A50: nop

    // 0x800A9A54: cvt.w.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A9A58: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800A9A5C: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x800A9A60: nop

    // 0x800A9A64: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A9A68: nop

    // 0x800A9A6C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800A9A70: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A9A74: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A9A78: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x800A9A7C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A9A80: lui         $at, 0x4325
    ctx->r1 = S32(0X4325 << 16);
    // 0x800A9A84: swc1        $f10, 0x64C($v0)
    MEM_W(0X64C, ctx->r2) = ctx->f10.u32l;
    // 0x800A9A88: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800A9A8C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A9A90: lui         $at, 0x4351
    ctx->r1 = S32(0X4351 << 16);
    // 0x800A9A94: swc1        $f18, 0x650($t9)
    MEM_W(0X650, ctx->r25) = ctx->f18.u32l;
    // 0x800A9A98: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x800A9A9C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A9AA0: lui         $at, 0x4341
    ctx->r1 = S32(0X4341 << 16);
    // 0x800A9AA4: swc1        $f8, 0x40C($t2)
    MEM_W(0X40C, ctx->r10) = ctx->f8.u32l;
    // 0x800A9AA8: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x800A9AAC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A9AB0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A9AB4: swc1        $f16, 0x410($t3)
    MEM_W(0X410, ctx->r11) = ctx->f16.u32l;
    // 0x800A9AB8: lw          $t4, 0x300($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X300);
    // 0x800A9ABC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800A9AC0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A9AC4: bne         $t4, $zero, L_800A9BB8
    if (ctx->r12 != 0) {
        // 0x800A9AC8: lui         $at, 0x800F
        ctx->r1 = S32(0X800F << 16);
            goto L_800A9BB8;
    }
    // 0x800A9AC8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A9ACC: lwc1        $f1, -0x72C0($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X72C0);
    // 0x800A9AD0: lwc1        $f0, -0x72BC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X72BC);
    // 0x800A9AD4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9AD8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800A9ADC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A9AE0: lwc1        $f4, 0x64C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X64C);
    // 0x800A9AE4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A9AE8: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800A9AEC: swc1        $f10, 0x64C($v0)
    MEM_W(0X64C, ctx->r2) = ctx->f10.u32l;
    // 0x800A9AF0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9AF4: nop

    // 0x800A9AF8: lwc1        $f18, 0x40C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X40C);
    // 0x800A9AFC: nop

    // 0x800A9B00: sub.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x800A9B04: swc1        $f16, 0x40C($v0)
    MEM_W(0X40C, ctx->r2) = ctx->f16.u32l;
    // 0x800A9B08: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9B0C: nop

    // 0x800A9B10: lwc1        $f4, 0x650($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X650);
    // 0x800A9B14: nop

    // 0x800A9B18: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800A9B1C: mul.d       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x800A9B20: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x800A9B24: swc1        $f18, 0x650($v0)
    MEM_W(0X650, ctx->r2) = ctx->f18.u32l;
    // 0x800A9B28: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9B2C: nop

    // 0x800A9B30: lwc1        $f8, 0x410($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X410);
    // 0x800A9B34: nop

    // 0x800A9B38: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x800A9B3C: mul.d       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f0.d);
    // 0x800A9B40: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x800A9B44: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800A9B48: swc1        $f6, 0x410($v0)
    MEM_W(0X410, ctx->r2) = ctx->f6.u32l;
    // 0x800A9B4C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9B50: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800A9B54: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A9B58: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A9B5C: lwc1        $f10, 0x650($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X650);
    // 0x800A9B60: nop

    // 0x800A9B64: cvt.w.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800A9B68: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x800A9B6C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800A9B70: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800A9B74: nop

    // 0x800A9B78: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A9B7C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800A9B80: swc1        $f16, 0x650($v0)
    MEM_W(0X650, ctx->r2) = ctx->f16.u32l;
    // 0x800A9B84: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9B88: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800A9B8C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A9B90: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A9B94: lwc1        $f4, 0x410($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X410);
    // 0x800A9B98: nop

    // 0x800A9B9C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A9BA0: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x800A9BA4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800A9BA8: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800A9BAC: nop

    // 0x800A9BB0: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A9BB4: swc1        $f18, 0x410($v0)
    MEM_W(0X410, ctx->r2) = ctx->f18.u32l;
L_800A9BB8:
    // 0x800A9BB8: sw          $v1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r3;
    // 0x800A9BBC: jal         0x800A4B38
    // 0x800A9BC0: sw          $a1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r5;
    hud_treasure(rdram, ctx);
        goto after_27;
    // 0x800A9BC0: sw          $a1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r5;
    after_27:
    // 0x800A9BC4: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
    // 0x800A9BC8: lw          $v1, 0xA8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XA8);
    // 0x800A9BCC: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A9BD0: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800A9BD4: mtc1        $s1, $f4
    ctx->f4.u32l = ctx->r17;
    // 0x800A9BD8: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    // 0x800A9BDC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A9BE0: swc1        $f16, 0x64C($t9)
    MEM_W(0X64C, ctx->r25) = ctx->f16.u32l;
    // 0x800A9BE4: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x800A9BE8: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x800A9BEC: swc1        $f6, 0x650($t2)
    MEM_W(0X650, ctx->r10) = ctx->f6.u32l;
    // 0x800A9BF0: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A9BF4: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x800A9BF8: mtc1        $a1, $f8
    ctx->f8.u32l = ctx->r5;
    // 0x800A9BFC: swc1        $f18, 0x40C($t3)
    MEM_W(0X40C, ctx->r11) = ctx->f18.u32l;
    // 0x800A9C00: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A9C04: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x800A9C08: nop

    // 0x800A9C0C: swc1        $f16, 0x410($t4)
    MEM_W(0X410, ctx->r12) = ctx->f16.u32l;
L_800A9C10:
    // 0x800A9C10: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A9C14: lw          $v0, 0x7740($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7740);
    // 0x800A9C18: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800A9C1C: addiu       $s2, $s2, 0x729C
    ctx->r18 = ADD32(ctx->r18, 0X729C);
    // 0x800A9C20: beq         $v0, $zero, L_800A9C6C
    if (ctx->r2 == 0) {
        // 0x800A9C24: addiu       $s3, $zero, -0x1
        ctx->r19 = ADD32(0, -0X1);
            goto L_800A9C6C;
    }
    // 0x800A9C24: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // 0x800A9C28: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A9C2C: addiu       $a1, $a1, 0x7340
    ctx->r5 = ADD32(ctx->r5, 0X7340);
    // 0x800A9C30: sll         $t5, $v0, 3
    ctx->r13 = S32(ctx->r2 << 3);
    // 0x800A9C34: addu        $t6, $a1, $t5
    ctx->r14 = ADD32(ctx->r5, ctx->r13);
    // 0x800A9C38: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    // 0x800A9C3C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800A9C40: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800A9C44: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800A9C48: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800A9C4C: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x800A9C50: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x800A9C54: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800A9C58: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800A9C5C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800A9C60: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800A9C64: jal         0x80078F08
    // 0x800A9C68: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    texrect_draw(rdram, ctx);
        goto after_28;
    // 0x800A9C68: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_28:
L_800A9C6C:
    // 0x800A9C6C: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x800A9C70: lw          $t4, 0x160($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X160);
    // 0x800A9C74: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800A9C78: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800A9C7C: lw          $t6, 0x164($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X164);
    // 0x800A9C80: lw          $t5, 0x72C0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X72C0);
    // 0x800A9C84: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A9C88: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800A9C8C: lw          $t8, 0x168($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X168);
    // 0x800A9C90: lw          $t7, 0x72C4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X72C4);
    // 0x800A9C94: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A9C98: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800A9C9C: lw          $t9, 0x7320($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7320);
    // 0x800A9CA0: nop

    // 0x800A9CA4: lbu         $t2, 0xBC($t9)
    ctx->r10 = MEM_BU(ctx->r25, 0XBC);
    // 0x800A9CA8: nop

    // 0x800A9CAC: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x800A9CB0: bne         $t3, $zero, L_800AA92C
    if (ctx->r11 != 0) {
        // 0x800A9CB4: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_800AA92C;
    }
    // 0x800A9CB4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800A9CB8: lw          $t4, 0x140($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X140);
    // 0x800A9CBC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A9CC0: blez        $t4, L_800A9E44
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800A9CC4: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800A9E44;
    }
    // 0x800A9CC4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800A9CC8: andi        $t0, $t4, 0x3
    ctx->r8 = ctx->r12 & 0X3;
    // 0x800A9CCC: beq         $t0, $zero, L_800A9D34
    if (ctx->r8 == 0) {
        // 0x800A9CD0: or          $a2, $t0, $zero
        ctx->r6 = ctx->r8 | 0;
            goto L_800A9D34;
    }
    // 0x800A9CD0: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x800A9CD4: lw          $t5, 0x150($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X150);
    // 0x800A9CD8: sll         $t6, $zero, 2
    ctx->r14 = S32(0 << 2);
    // 0x800A9CDC: addu        $s0, $t5, $t6
    ctx->r16 = ADD32(ctx->r13, ctx->r14);
L_800A9CE0:
    // 0x800A9CE0: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800A9CE4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800A9CE8: lw          $v0, 0x64($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X64);
    // 0x800A9CEC: nop

    // 0x800A9CF0: beq         $v0, $zero, L_800A9D1C
    if (ctx->r2 == 0) {
        // 0x800A9CF4: nop
    
            goto L_800A9D1C;
    }
    // 0x800A9CF4: nop

    // 0x800A9CF8: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x800A9CFC: nop

    // 0x800A9D00: beq         $s3, $t8, L_800A9D1C
    if (ctx->r19 == ctx->r24) {
        // 0x800A9D04: nop
    
            goto L_800A9D1C;
    }
    // 0x800A9D04: nop

    // 0x800A9D08: lb          $t9, 0x1D8($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X1D8);
    // 0x800A9D0C: nop

    // 0x800A9D10: bne         $t9, $zero, L_800A9D1C
    if (ctx->r25 != 0) {
        // 0x800A9D14: nop
    
            goto L_800A9D1C;
    }
    // 0x800A9D14: nop

    // 0x800A9D18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800A9D1C:
    // 0x800A9D1C: bne         $a2, $v1, L_800A9CE0
    if (ctx->r6 != ctx->r3) {
        // 0x800A9D20: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800A9CE0;
    }
    // 0x800A9D20: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800A9D24: lw          $t2, 0x140($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X140);
    // 0x800A9D28: nop

    // 0x800A9D2C: beq         $v1, $t2, L_800A9E44
    if (ctx->r3 == ctx->r10) {
        // 0x800A9D30: nop
    
            goto L_800A9E44;
    }
    // 0x800A9D30: nop

L_800A9D34:
    // 0x800A9D34: lw          $a2, 0x140($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X140);
    // 0x800A9D38: lw          $t3, 0x150($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X150);
    // 0x800A9D3C: sll         $s1, $v1, 2
    ctx->r17 = S32(ctx->r3 << 2);
    // 0x800A9D40: sll         $t4, $a2, 2
    ctx->r12 = S32(ctx->r6 << 2);
    // 0x800A9D44: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x800A9D48: addu        $s0, $t3, $s1
    ctx->r16 = ADD32(ctx->r11, ctx->r17);
L_800A9D4C:
    // 0x800A9D4C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x800A9D50: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x800A9D54: lw          $v0, 0x64($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X64);
    // 0x800A9D58: nop

    // 0x800A9D5C: beq         $v0, $zero, L_800A9D88
    if (ctx->r2 == 0) {
        // 0x800A9D60: nop
    
            goto L_800A9D88;
    }
    // 0x800A9D60: nop

    // 0x800A9D64: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x800A9D68: nop

    // 0x800A9D6C: beq         $s3, $t6, L_800A9D88
    if (ctx->r19 == ctx->r14) {
        // 0x800A9D70: nop
    
            goto L_800A9D88;
    }
    // 0x800A9D70: nop

    // 0x800A9D74: lb          $t7, 0x1D8($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X1D8);
    // 0x800A9D78: nop

    // 0x800A9D7C: bne         $t7, $zero, L_800A9D88
    if (ctx->r15 != 0) {
        // 0x800A9D80: nop
    
            goto L_800A9D88;
    }
    // 0x800A9D80: nop

    // 0x800A9D84: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800A9D88:
    // 0x800A9D88: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x800A9D8C: nop

    // 0x800A9D90: lw          $a1, 0x64($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X64);
    // 0x800A9D94: nop

    // 0x800A9D98: beq         $a1, $zero, L_800A9DC4
    if (ctx->r5 == 0) {
        // 0x800A9D9C: nop
    
            goto L_800A9DC4;
    }
    // 0x800A9D9C: nop

    // 0x800A9DA0: lh          $t9, 0x0($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X0);
    // 0x800A9DA4: nop

    // 0x800A9DA8: beq         $s3, $t9, L_800A9DC4
    if (ctx->r19 == ctx->r25) {
        // 0x800A9DAC: nop
    
            goto L_800A9DC4;
    }
    // 0x800A9DAC: nop

    // 0x800A9DB0: lb          $t2, 0x1D8($a1)
    ctx->r10 = MEM_B(ctx->r5, 0X1D8);
    // 0x800A9DB4: nop

    // 0x800A9DB8: bne         $t2, $zero, L_800A9DC4
    if (ctx->r10 != 0) {
        // 0x800A9DBC: nop
    
            goto L_800A9DC4;
    }
    // 0x800A9DBC: nop

    // 0x800A9DC0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800A9DC4:
    // 0x800A9DC4: lw          $t3, 0x8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X8);
    // 0x800A9DC8: nop

    // 0x800A9DCC: lw          $a1, 0x64($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X64);
    // 0x800A9DD0: nop

    // 0x800A9DD4: beq         $a1, $zero, L_800A9E00
    if (ctx->r5 == 0) {
        // 0x800A9DD8: nop
    
            goto L_800A9E00;
    }
    // 0x800A9DD8: nop

    // 0x800A9DDC: lh          $t4, 0x0($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X0);
    // 0x800A9DE0: nop

    // 0x800A9DE4: beq         $s3, $t4, L_800A9E00
    if (ctx->r19 == ctx->r12) {
        // 0x800A9DE8: nop
    
            goto L_800A9E00;
    }
    // 0x800A9DE8: nop

    // 0x800A9DEC: lb          $t5, 0x1D8($a1)
    ctx->r13 = MEM_B(ctx->r5, 0X1D8);
    // 0x800A9DF0: nop

    // 0x800A9DF4: bne         $t5, $zero, L_800A9E00
    if (ctx->r13 != 0) {
        // 0x800A9DF8: nop
    
            goto L_800A9E00;
    }
    // 0x800A9DF8: nop

    // 0x800A9DFC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800A9E00:
    // 0x800A9E00: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x800A9E04: nop

    // 0x800A9E08: lw          $a1, 0x64($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X64);
    // 0x800A9E0C: nop

    // 0x800A9E10: beq         $a1, $zero, L_800A9E3C
    if (ctx->r5 == 0) {
        // 0x800A9E14: nop
    
            goto L_800A9E3C;
    }
    // 0x800A9E14: nop

    // 0x800A9E18: lh          $t7, 0x0($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X0);
    // 0x800A9E1C: nop

    // 0x800A9E20: beq         $s3, $t7, L_800A9E3C
    if (ctx->r19 == ctx->r15) {
        // 0x800A9E24: nop
    
            goto L_800A9E3C;
    }
    // 0x800A9E24: nop

    // 0x800A9E28: lb          $t8, 0x1D8($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X1D8);
    // 0x800A9E2C: nop

    // 0x800A9E30: bne         $t8, $zero, L_800A9E3C
    if (ctx->r24 != 0) {
        // 0x800A9E34: nop
    
            goto L_800A9E3C;
    }
    // 0x800A9E34: nop

    // 0x800A9E38: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800A9E3C:
    // 0x800A9E3C: bne         $s1, $a2, L_800A9D4C
    if (ctx->r17 != ctx->r6) {
        // 0x800A9E40: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_800A9D4C;
    }
    // 0x800A9E40: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
L_800A9E44:
    // 0x800A9E44: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A9E48: lw          $t9, 0x72CC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X72CC);
    // 0x800A9E4C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A9E50: bne         $t9, $at, L_800A9E6C
    if (ctx->r25 != ctx->r1) {
        // 0x800A9E54: nop
    
            goto L_800A9E6C;
    }
    // 0x800A9E54: nop

    // 0x800A9E58: jal         0x8006ECF0
    // 0x800A9E5C: sb          $a0, 0x113($sp)
    MEM_B(0X113, ctx->r29) = ctx->r4;
    is_postrace_viewport_active(rdram, ctx);
        goto after_29;
    // 0x800A9E5C: sb          $a0, 0x113($sp)
    MEM_B(0X113, ctx->r29) = ctx->r4;
    after_29:
    // 0x800A9E60: lbu         $a0, 0x113($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X113);
    // 0x800A9E64: bne         $v0, $zero, L_800AA92C
    if (ctx->r2 != 0) {
        // 0x800A9E68: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_800AA92C;
    }
    // 0x800A9E68: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800A9E6C:
    // 0x800A9E6C: jal         0x80066750
    // 0x800A9E70: sb          $a0, 0x113($sp)
    MEM_B(0X113, ctx->r29) = ctx->r4;
    check_if_showing_cutscene_camera(rdram, ctx);
        goto after_30;
    // 0x800A9E70: sb          $a0, 0x113($sp)
    MEM_B(0X113, ctx->r29) = ctx->r4;
    after_30:
    // 0x800A9E74: lbu         $a0, 0x113($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X113);
    // 0x800A9E78: bne         $v0, $zero, L_800AA92C
    if (ctx->r2 != 0) {
        // 0x800A9E7C: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_800AA92C;
    }
    // 0x800A9E7C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800A9E80: bne         $a0, $zero, L_800AA928
    if (ctx->r4 != 0) {
        // 0x800A9E84: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_800AA928;
    }
    // 0x800A9E84: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800A9E88: lw          $t2, 0x72CC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X72CC);
    // 0x800A9E8C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800A9E90: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800A9E94: lb          $t3, 0x2D24($t3)
    ctx->r11 = MEM_B(ctx->r11, 0X2D24);
    // 0x800A9E98: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A9E9C: beq         $t3, $at, L_800A9EAC
    if (ctx->r11 == ctx->r1) {
        // 0x800A9EA0: nop
    
            goto L_800A9EAC;
    }
    // 0x800A9EA0: nop

    // 0x800A9EA4: b           L_800AA92C
    // 0x800A9EA8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_800AA92C;
    // 0x800A9EA8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800A9EAC:
    // 0x800A9EAC: jal         0x8007B820
    // 0x800A9EB0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    rendermode_reset(rdram, ctx);
        goto after_31;
    // 0x800A9EB0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_31:
    // 0x800A9EB4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A9EB8: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A9EBC: jal         0x8006816C
    // 0x800A9EC0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    mtx_ortho(rdram, ctx);
        goto after_32;
    // 0x800A9EC0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_32:
    // 0x800A9EC4: jal         0x8002C804
    // 0x800A9EC8: nop

    get_current_level_model(rdram, ctx);
        goto after_33;
    // 0x800A9EC8: nop

    after_33:
    // 0x800A9ECC: beq         $v0, $zero, L_800AA928
    if (ctx->r2 == 0) {
        // 0x800A9ED0: sw          $v0, 0x158($sp)
        MEM_W(0X158, ctx->r29) = ctx->r2;
            goto L_800AA928;
    }
    // 0x800A9ED0: sw          $v0, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r2;
    // 0x800A9ED4: jal         0x80069F60
    // 0x800A9ED8: nop

    cam_get_active_camera(rdram, ctx);
        goto after_34;
    // 0x800A9ED8: nop

    after_34:
    // 0x800A9EDC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800A9EE0: jal         0x80068748
    // 0x800A9EE4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_35;
    // 0x800A9EE4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_35:
    // 0x800A9EE8: lw          $t4, 0x158($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X158);
    // 0x800A9EEC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A9EF0: lw          $v0, 0x72CC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X72CC);
    // 0x800A9EF4: lw          $t5, 0x20($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X20);
    // 0x800A9EF8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A9EFC: beq         $v0, $at, L_800A9F38
    if (ctx->r2 == ctx->r1) {
        // 0x800A9F00: sw          $t5, 0x154($sp)
        MEM_W(0X154, ctx->r29) = ctx->r13;
            goto L_800A9F38;
    }
    // 0x800A9F00: sw          $t5, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r13;
    // 0x800A9F04: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A9F08: beq         $v0, $at, L_800A9F70
    if (ctx->r2 == ctx->r1) {
        // 0x800A9F0C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800A9F70;
    }
    // 0x800A9F0C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A9F10: beq         $v0, $at, L_800AA04C
    if (ctx->r2 == ctx->r1) {
        // 0x800A9F14: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_800AA04C;
    }
    // 0x800A9F14: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A9F18: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A9F1C: addiu       $t6, $zero, 0x87
    ctx->r14 = ADD32(0, 0X87);
    // 0x800A9F20: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A9F24: sw          $t6, 0x7318($at)
    MEM_W(0X7318, ctx->r1) = ctx->r14;
    // 0x800A9F28: addiu       $s0, $s0, 0x731C
    ctx->r16 = ADD32(ctx->r16, 0X731C);
    // 0x800A9F2C: addiu       $t7, $zero, -0x62
    ctx->r15 = ADD32(0, -0X62);
    // 0x800A9F30: b           L_800AA094
    // 0x800A9F34: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
        goto L_800AA094;
    // 0x800A9F34: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
L_800A9F38:
    // 0x800A9F38: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A9F3C: lw          $t9, 0x72E0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X72E0);
    // 0x800A9F40: addiu       $t8, $zero, 0x87
    ctx->r24 = ADD32(0, 0X87);
    // 0x800A9F44: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A9F48: sw          $t8, 0x7318($at)
    MEM_W(0X7318, ctx->r1) = ctx->r24;
    // 0x800A9F4C: negu        $t2, $t9
    ctx->r10 = SUB32(0, ctx->r25);
    // 0x800A9F50: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A9F54: addiu       $s0, $s0, 0x731C
    ctx->r16 = ADD32(ctx->r16, 0X731C);
    // 0x800A9F58: bgez        $t2, L_800A9F68
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800A9F5C: sra         $t3, $t2, 1
        ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
            goto L_800A9F68;
    }
    // 0x800A9F5C: sra         $t3, $t2, 1
    ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
    // 0x800A9F60: addiu       $at, $t2, 0x1
    ctx->r1 = ADD32(ctx->r10, 0X1);
    // 0x800A9F64: sra         $t3, $at, 1
    ctx->r11 = S32(SIGNED(ctx->r1) >> 1);
L_800A9F68:
    // 0x800A9F68: b           L_800AA094
    // 0x800A9F6C: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
        goto L_800AA094;
    // 0x800A9F6C: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
L_800A9F70:
    // 0x800A9F70: jal         0x8006BFD8
    // 0x800A9F74: nop

    level_type(rdram, ctx);
        goto after_36;
    // 0x800A9F74: nop

    after_36:
    // 0x800A9F78: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x800A9F7C: beq         $v0, $at, L_800A9FAC
    if (ctx->r2 == ctx->r1) {
        // 0x800A9F80: nop
    
            goto L_800A9FAC;
    }
    // 0x800A9F80: nop

    // 0x800A9F84: jal         0x8006BFD8
    // 0x800A9F88: nop

    level_type(rdram, ctx);
        goto after_37;
    // 0x800A9F88: nop

    after_37:
    // 0x800A9F8C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x800A9F90: beq         $v0, $at, L_800A9FAC
    if (ctx->r2 == ctx->r1) {
        // 0x800A9F94: nop
    
            goto L_800A9FAC;
    }
    // 0x800A9F94: nop

    // 0x800A9F98: jal         0x8006BFD8
    // 0x800A9F9C: nop

    level_type(rdram, ctx);
        goto after_38;
    // 0x800A9F9C: nop

    after_38:
    // 0x800A9FA0: addiu       $at, $zero, 0x41
    ctx->r1 = ADD32(0, 0X41);
    // 0x800A9FA4: bne         $v0, $at, L_800A9FFC
    if (ctx->r2 != ctx->r1) {
        // 0x800A9FA8: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_800A9FFC;
    }
    // 0x800A9FA8: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
L_800A9FAC:
    // 0x800A9FAC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800A9FB0: lw          $t4, 0x72DC($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X72DC);
    // 0x800A9FB4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A9FB8: lw          $t7, 0x72E0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X72E0);
    // 0x800A9FBC: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A9FC0: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x800A9FC4: addiu       $s0, $s0, 0x731C
    ctx->r16 = ADD32(ctx->r16, 0X731C);
    // 0x800A9FC8: bgez        $t4, L_800A9FD8
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800A9FCC: sra         $t5, $t4, 1
        ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
            goto L_800A9FD8;
    }
    // 0x800A9FCC: sra         $t5, $t4, 1
    ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
    // 0x800A9FD0: addiu       $at, $t4, 0x1
    ctx->r1 = ADD32(ctx->r12, 0X1);
    // 0x800A9FD4: sra         $t5, $at, 1
    ctx->r13 = S32(SIGNED(ctx->r1) >> 1);
L_800A9FD8:
    // 0x800A9FD8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A9FDC: addiu       $t6, $t5, -0x8
    ctx->r14 = ADD32(ctx->r13, -0X8);
    // 0x800A9FE0: sw          $t6, 0x7318($at)
    MEM_W(0X7318, ctx->r1) = ctx->r14;
    // 0x800A9FE4: bgez        $t8, L_800A9FF4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800A9FE8: sra         $t9, $t8, 1
        ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
            goto L_800A9FF4;
    }
    // 0x800A9FE8: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x800A9FEC: addiu       $at, $t8, 0x1
    ctx->r1 = ADD32(ctx->r24, 0X1);
    // 0x800A9FF0: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_800A9FF4:
    // 0x800A9FF4: b           L_800AA094
    // 0x800A9FF8: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
        goto L_800AA094;
    // 0x800A9FF8: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
L_800A9FFC:
    // 0x800A9FFC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800AA000: lw          $t2, 0x72DC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X72DC);
    // 0x800AA004: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800AA008: lw          $t5, 0x72E0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X72E0);
    // 0x800AA00C: addiu       $t7, $zero, -0x3C
    ctx->r15 = ADD32(0, -0X3C);
    // 0x800AA010: addiu       $s0, $s0, 0x731C
    ctx->r16 = ADD32(ctx->r16, 0X731C);
    // 0x800AA014: bgez        $t2, L_800AA024
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800AA018: sra         $t3, $t2, 1
        ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
            goto L_800AA024;
    }
    // 0x800AA018: sra         $t3, $t2, 1
    ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
    // 0x800AA01C: addiu       $at, $t2, 0x1
    ctx->r1 = ADD32(ctx->r10, 0X1);
    // 0x800AA020: sra         $t3, $at, 1
    ctx->r11 = S32(SIGNED(ctx->r1) >> 1);
L_800AA024:
    // 0x800AA024: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AA028: addiu       $t4, $t3, 0x48
    ctx->r12 = ADD32(ctx->r11, 0X48);
    // 0x800AA02C: sw          $t4, 0x7318($at)
    MEM_W(0X7318, ctx->r1) = ctx->r12;
    // 0x800AA030: bgez        $t5, L_800AA040
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800AA034: sra         $t6, $t5, 1
        ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
            goto L_800AA040;
    }
    // 0x800AA034: sra         $t6, $t5, 1
    ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
    // 0x800AA038: addiu       $at, $t5, 0x1
    ctx->r1 = ADD32(ctx->r13, 0X1);
    // 0x800AA03C: sra         $t6, $at, 1
    ctx->r14 = S32(SIGNED(ctx->r1) >> 1);
L_800AA040:
    // 0x800AA040: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x800AA044: b           L_800AA094
    // 0x800AA048: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
        goto L_800AA094;
    // 0x800AA048: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
L_800AA04C:
    // 0x800AA04C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800AA050: lw          $t9, 0x72DC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X72DC);
    // 0x800AA054: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800AA058: lw          $t4, 0x72E0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X72E0);
    // 0x800AA05C: addiu       $s0, $s0, 0x731C
    ctx->r16 = ADD32(ctx->r16, 0X731C);
    // 0x800AA060: bgez        $t9, L_800AA070
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800AA064: sra         $t2, $t9, 1
        ctx->r10 = S32(SIGNED(ctx->r25) >> 1);
            goto L_800AA070;
    }
    // 0x800AA064: sra         $t2, $t9, 1
    ctx->r10 = S32(SIGNED(ctx->r25) >> 1);
    // 0x800AA068: addiu       $at, $t9, 0x1
    ctx->r1 = ADD32(ctx->r25, 0X1);
    // 0x800AA06C: sra         $t2, $at, 1
    ctx->r10 = S32(SIGNED(ctx->r1) >> 1);
L_800AA070:
    // 0x800AA070: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AA074: addiu       $t3, $t2, -0x8
    ctx->r11 = ADD32(ctx->r10, -0X8);
    // 0x800AA078: sw          $t3, 0x7318($at)
    MEM_W(0X7318, ctx->r1) = ctx->r11;
    // 0x800AA07C: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x800AA080: bgez        $t5, L_800AA090
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800AA084: sra         $t7, $t5, 1
        ctx->r15 = S32(SIGNED(ctx->r13) >> 1);
            goto L_800AA090;
    }
    // 0x800AA084: sra         $t7, $t5, 1
    ctx->r15 = S32(SIGNED(ctx->r13) >> 1);
    // 0x800AA088: addiu       $at, $t5, 0x1
    ctx->r1 = ADD32(ctx->r13, 0X1);
    // 0x800AA08C: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_800AA090:
    // 0x800AA090: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
L_800AA094:
    // 0x800AA094: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x800AA098: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x800AA09C: nop

    // 0x800AA0A0: bne         $t6, $zero, L_800AA0F0
    if (ctx->r14 != 0) {
        // 0x800AA0A4: nop
    
            goto L_800AA0F0;
    }
    // 0x800AA0A4: nop

    // 0x800AA0A8: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800AA0AC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800AA0B0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800AA0B4: lwc1        $f11, -0x72B8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X72B8);
    // 0x800AA0B8: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x800AA0BC: lwc1        $f10, -0x72B4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X72B4);
    // 0x800AA0C0: nop

    // 0x800AA0C4: mul.d       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x800AA0C8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800AA0CC: nop

    // 0x800AA0D0: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800AA0D4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AA0D8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AA0DC: nop

    // 0x800AA0E0: cvt.w.d     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_D(ctx->f18.d);
    // 0x800AA0E4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800AA0E8: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
    // 0x800AA0EC: nop

L_800AA0F0:
    // 0x800AA0F0: jal         0x8007C36C
    // 0x800AA0F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_39;
    // 0x800AA0F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_39:
    // 0x800AA0F8: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x800AA0FC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800AA100: lw          $t2, 0x7318($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7318);
    // 0x800AA104: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x800AA108: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800AA10C: lw          $t3, 0x72E4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X72E4);
    // 0x800AA110: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800AA114: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800AA118: lw          $t5, 0x72E8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X72E8);
    // 0x800AA11C: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800AA120: addu        $t7, $t4, $t5
    ctx->r15 = ADD32(ctx->r12, ctx->r13);
    // 0x800AA124: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x800AA128: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x800AA12C: cvt.s.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800AA130: lw          $t8, 0x300($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X300);
    // 0x800AA134: swc1        $f18, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->f18.u32l;
    // 0x800AA138: bne         $t8, $zero, L_800AA154
    if (ctx->r24 != 0) {
        // 0x800AA13C: swc1        $f0, 0x12C($sp)
        MEM_W(0X12C, ctx->r29) = ctx->f0.u32l;
            goto L_800AA154;
    }
    // 0x800AA13C: swc1        $f0, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->f0.u32l;
    // 0x800AA140: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800AA144: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800AA148: nop

    // 0x800AA14C: sub.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x800AA150: swc1        $f0, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->f0.u32l;
L_800AA154:
    // 0x800AA154: lh          $t9, 0x4($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X4);
    // 0x800AA158: sh          $zero, 0x122($sp)
    MEM_H(0X122, ctx->r29) = 0;
    // 0x800AA15C: negu        $t2, $t9
    ctx->r10 = SUB32(0, ctx->r25);
    // 0x800AA160: jal         0x8009C850
    // 0x800AA164: sh          $t2, 0x124($sp)
    MEM_H(0X124, ctx->r29) = ctx->r10;
    get_filtered_cheats(rdram, ctx);
        goto after_40;
    // 0x800AA164: sh          $t2, 0x124($sp)
    MEM_H(0X124, ctx->r29) = ctx->r10;
    after_40:
    // 0x800AA168: andi        $t3, $v0, 0x4
    ctx->r11 = ctx->r2 & 0X4;
    // 0x800AA16C: beq         $t3, $zero, L_800AA19C
    if (ctx->r11 == 0) {
        // 0x800AA170: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800AA19C;
    }
    // 0x800AA170: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800AA174: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800AA178: lw          $t5, 0x72DC($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X72DC);
    // 0x800AA17C: lwc1        $f0, 0x12C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x800AA180: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x800AA184: addiu       $t4, $zero, -0x8000
    ctx->r12 = ADD32(0, -0X8000);
    // 0x800AA188: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800AA18C: sh          $t4, 0x120($sp)
    MEM_H(0X120, ctx->r29) = ctx->r12;
    // 0x800AA190: sub.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x800AA194: b           L_800AA1A0
    // 0x800AA198: swc1        $f0, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->f0.u32l;
        goto L_800AA1A0;
    // 0x800AA198: swc1        $f0, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->f0.u32l;
L_800AA19C:
    // 0x800AA19C: sh          $zero, 0x120($sp)
    MEM_H(0X120, ctx->r29) = 0;
L_800AA1A0:
    // 0x800AA1A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AA1A4: lw          $t7, 0x10C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X10C);
    // 0x800AA1A8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800AA1AC: slti        $at, $t7, 0xA1
    ctx->r1 = SIGNED(ctx->r15) < 0XA1 ? 1 : 0;
    // 0x800AA1B0: sh          $zero, 0x138($sp)
    MEM_H(0X138, ctx->r29) = 0;
    // 0x800AA1B4: swc1        $f4, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->f4.u32l;
    // 0x800AA1B8: sw          $t7, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r15;
    // 0x800AA1BC: bne         $at, $zero, L_800AA1CC
    if (ctx->r1 != 0) {
        // 0x800AA1C0: swc1        $f16, 0x134($sp)
        MEM_W(0X134, ctx->r29) = ctx->f16.u32l;
            goto L_800AA1CC;
    }
    // 0x800AA1C0: swc1        $f16, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->f16.u32l;
    // 0x800AA1C4: addiu       $t6, $zero, 0xA0
    ctx->r14 = ADD32(0, 0XA0);
    // 0x800AA1C8: sw          $t6, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r14;
L_800AA1CC:
    // 0x800AA1CC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800AA1D0: lbu         $t8, 0x72F7($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X72F7);
    // 0x800AA1D4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800AA1D8: bne         $t8, $at, L_800AA20C
    if (ctx->r24 != ctx->r1) {
        // 0x800AA1DC: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_800AA20C;
    }
    // 0x800AA1DC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800AA1E0: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x800AA1E4: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x800AA1E8: addiu       $t9, $t0, 0x8
    ctx->r25 = ADD32(ctx->r8, 0X8);
    // 0x800AA1EC: sw          $t9, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r25;
    // 0x800AA1F0: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x800AA1F4: lw          $t3, 0x10C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X10C);
    // 0x800AA1F8: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x800AA1FC: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x800AA200: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x800AA204: b           L_800AA25C
    // 0x800AA208: sw          $t5, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r13;
        goto L_800AA25C;
    // 0x800AA208: sw          $t5, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r13;
L_800AA20C:
    // 0x800AA20C: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x800AA210: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800AA214: addiu       $t7, $t0, 0x8
    ctx->r15 = ADD32(ctx->r8, 0X8);
    // 0x800AA218: sw          $t7, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r15;
    // 0x800AA21C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800AA220: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x800AA224: lbu         $t4, 0x7315($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X7315);
    // 0x800AA228: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800AA22C: lbu         $t9, 0x7314($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X7314);
    // 0x800AA230: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800AA234: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x800AA238: lbu         $t8, 0x7316($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X7316);
    // 0x800AA23C: sll         $t2, $t9, 24
    ctx->r10 = S32(ctx->r25 << 24);
    // 0x800AA240: lw          $t4, 0x10C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X10C);
    // 0x800AA244: or          $t7, $t2, $t5
    ctx->r15 = ctx->r10 | ctx->r13;
    // 0x800AA248: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x800AA24C: or          $t3, $t7, $t9
    ctx->r11 = ctx->r15 | ctx->r25;
    // 0x800AA250: andi        $t2, $t4, 0xFF
    ctx->r10 = ctx->r12 & 0XFF;
    // 0x800AA254: or          $t5, $t3, $t2
    ctx->r13 = ctx->r11 | ctx->r10;
    // 0x800AA258: sw          $t5, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r13;
L_800AA25C:
    // 0x800AA25C: lw          $t6, 0x154($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X154);
    // 0x800AA260: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800AA264: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800AA268: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800AA26C: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800AA270: addiu       $a3, $sp, 0x120
    ctx->r7 = ADD32(ctx->r29, 0X120);
    // 0x800AA274: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800AA278: jal         0x80068E34
    // 0x800AA27C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    render_ortho_triangle_image(rdram, ctx);
        goto after_41;
    // 0x800AA27C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_41:
    // 0x800AA280: lw          $v0, 0x158($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X158);
    // 0x800AA284: addiu       $at, $zero, 0x168
    ctx->r1 = ADD32(0, 0X168);
    // 0x800AA288: lh          $t8, 0x3E($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X3E);
    // 0x800AA28C: lh          $t7, 0x3C($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X3C);
    // 0x800AA290: lh          $t4, 0x46($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X46);
    // 0x800AA294: lh          $t3, 0x44($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X44);
    // 0x800AA298: subu        $t9, $t8, $t7
    ctx->r25 = SUB32(ctx->r24, ctx->r15);
    // 0x800AA29C: subu        $t2, $t4, $t3
    ctx->r10 = SUB32(ctx->r12, ctx->r11);
    // 0x800AA2A0: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x800AA2A4: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800AA2A8: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800AA2AC: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800AA2B0: nop

    // 0x800AA2B4: div.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800AA2B8: swc1        $f16, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->f16.u32l;
    // 0x800AA2BC: lhu         $a0, 0x24($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X24);
    // 0x800AA2C0: nop

    // 0x800AA2C4: sll         $t5, $a0, 16
    ctx->r13 = S32(ctx->r4 << 16);
    // 0x800AA2C8: subu        $t5, $t5, $a0
    ctx->r13 = SUB32(ctx->r13, ctx->r4);
    // 0x800AA2CC: div         $zero, $t5, $at
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r1)));
    // 0x800AA2D0: mflo        $t6
    ctx->r14 = lo;
    // 0x800AA2D4: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x800AA2D8: jal         0x80070A38
    // 0x800AA2DC: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    coss_f(rdram, ctx);
        goto after_42;
    // 0x800AA2DC: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    after_42:
    // 0x800AA2E0: lw          $t9, 0x158($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X158);
    // 0x800AA2E4: swc1        $f0, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->f0.u32l;
    // 0x800AA2E8: lhu         $a0, 0x24($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X24);
    // 0x800AA2EC: addiu       $at, $zero, 0x168
    ctx->r1 = ADD32(0, 0X168);
    // 0x800AA2F0: sll         $t4, $a0, 16
    ctx->r12 = S32(ctx->r4 << 16);
    // 0x800AA2F4: subu        $t4, $t4, $a0
    ctx->r12 = SUB32(ctx->r12, ctx->r4);
    // 0x800AA2F8: div         $zero, $t4, $at
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r1)));
    // 0x800AA2FC: mflo        $t3
    ctx->r11 = lo;
    // 0x800AA300: sll         $t2, $t3, 16
    ctx->r10 = S32(ctx->r11 << 16);
    // 0x800AA304: jal         0x80070A04
    // 0x800AA308: sra         $a0, $t2, 16
    ctx->r4 = S32(SIGNED(ctx->r10) >> 16);
    sins_f(rdram, ctx);
        goto after_43;
    // 0x800AA308: sra         $a0, $t2, 16
    ctx->r4 = S32(SIGNED(ctx->r10) >> 16);
    after_43:
    // 0x800AA30C: jal         0x8000E4D8
    // 0x800AA310: swc1        $f0, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->f0.u32l;
    is_in_time_trial(rdram, ctx);
        goto after_44;
    // 0x800AA310: swc1        $f0, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->f0.u32l;
    after_44:
    // 0x800AA314: beq         $v0, $zero, L_800AA424
    if (ctx->r2 == 0) {
        // 0x800AA318: nop
    
            goto L_800AA424;
    }
    // 0x800AA318: nop

    // 0x800AA31C: jal         0x8001B2BC
    // 0x800AA320: nop

    timetrial_valid_player_ghost(rdram, ctx);
        goto after_45;
    // 0x800AA320: nop

    after_45:
    // 0x800AA324: beq         $v0, $zero, L_800AA424
    if (ctx->r2 == 0) {
        // 0x800AA328: nop
    
            goto L_800AA424;
    }
    // 0x800AA328: nop

    // 0x800AA32C: jal         0x8001B314
    // 0x800AA330: nop

    timetrial_player_ghost(rdram, ctx);
        goto after_46;
    // 0x800AA330: nop

    after_46:
    // 0x800AA334: beq         $v0, $zero, L_800AA424
    if (ctx->r2 == 0) {
        // 0x800AA338: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800AA424;
    }
    // 0x800AA338: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800AA33C: lwc1        $f4, 0x11C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x800AA340: lwc1        $f12, 0xC($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800AA344: lwc1        $f14, 0x14($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800AA348: lw          $a2, 0x114($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X114);
    // 0x800AA34C: lw          $a3, 0x118($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X118);
    // 0x800AA350: jal         0x800AA948
    // 0x800AA354: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    minimap_marker_pos(rdram, ctx);
        goto after_47;
    // 0x800AA354: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_47:
    // 0x800AA358: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x800AA35C: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x800AA360: sh          $t6, 0x1E6($t8)
    MEM_H(0X1E6, ctx->r24) = ctx->r14;
    // 0x800AA364: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800AA368: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800AA36C: sh          $zero, 0x1E4($t7)
    MEM_H(0X1E4, ctx->r15) = 0;
    // 0x800AA370: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800AA374: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800AA378: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800AA37C: swc1        $f6, 0x1E8($t9)
    MEM_W(0X1E8, ctx->r25) = ctx->f6.u32l;
    // 0x800AA380: lbu         $t3, 0x39($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X39);
    // 0x800AA384: lw          $t4, 0x108($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X108);
    // 0x800AA388: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x800AA38C: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x800AA390: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800AA394: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800AA398: bgez        $t3, L_800AA3B0
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800AA39C: cvt.s.w     $f10, $f18
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800AA3B0;
    }
    // 0x800AA39C: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800AA3A0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800AA3A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AA3A8: nop

    // 0x800AA3AC: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_800AA3B0:
    // 0x800AA3B0: mul.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800AA3B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800AA3B8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800AA3BC: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x800AA3C0: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x800AA3C4: mul.d       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f8.d);
    // 0x800AA3C8: addiu       $t5, $t0, 0x8
    ctx->r13 = ADD32(ctx->r8, 0X8);
    // 0x800AA3CC: sw          $t5, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r13;
    // 0x800AA3D0: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x800AA3D4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800AA3D8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800AA3DC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800AA3E0: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800AA3E4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AA3E8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AA3EC: lui         $at, 0x3C3C
    ctx->r1 = S32(0X3C3C << 16);
    // 0x800AA3F0: cvt.w.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_D(ctx->f4.d);
    // 0x800AA3F4: ori         $at, $at, 0x3C00
    ctx->r1 = ctx->r1 | 0X3C00;
    // 0x800AA3F8: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800AA3FC: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800AA400: andi        $t8, $v1, 0xFF
    ctx->r24 = ctx->r3 & 0XFF;
    // 0x800AA404: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x800AA408: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x800AA40C: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x800AA410: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800AA414: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800AA418: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800AA41C: jal         0x800AAB5C
    // 0x800AA420: addiu       $a3, $a3, 0x1E0
    ctx->r7 = ADD32(ctx->r7, 0X1E0);
    hud_element_render(rdram, ctx);
        goto after_48;
    // 0x800AA420: addiu       $a3, $a3, 0x1E0
    ctx->r7 = ADD32(ctx->r7, 0X1E0);
    after_48:
L_800AA424:
    // 0x800AA424: jal         0x8001B674
    // 0x800AA428: nop

    timetrial_ghost_staff(rdram, ctx);
        goto after_49;
    // 0x800AA428: nop

    after_49:
    // 0x800AA42C: beq         $v0, $zero, L_800AA544
    if (ctx->r2 == 0) {
        // 0x800AA430: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800AA544;
    }
    // 0x800AA430: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800AA434: lw          $t9, 0x108($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X108);
    // 0x800AA438: lwc1        $f16, 0x11C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x800AA43C: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800AA440: lwc1        $f12, 0xC($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800AA444: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800AA448: lwc1        $f14, 0x14($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800AA44C: lw          $a2, 0x114($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X114);
    // 0x800AA450: lw          $a3, 0x118($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X118);
    // 0x800AA454: swc1        $f18, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f18.u32l;
    // 0x800AA458: jal         0x800AA948
    // 0x800AA45C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    minimap_marker_pos(rdram, ctx);
        goto after_50;
    // 0x800AA45C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_50:
    // 0x800AA460: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x800AA464: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800AA468: sh          $zero, 0x1E4($t4)
    MEM_H(0X1E4, ctx->r12) = 0;
    // 0x800AA46C: lbu         $t3, 0x39($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X39);
    // 0x800AA470: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800AA474: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x800AA478: addiu       $t1, $t1, 0x2D3C
    ctx->r9 = ADD32(ctx->r9, 0X2D3C);
    // 0x800AA47C: bgez        $t3, L_800AA494
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800AA480: cvt.s.w     $f10, $f4
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800AA494;
    }
    // 0x800AA480: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AA484: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800AA488: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800AA48C: nop

    // 0x800AA490: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_800AA494:
    // 0x800AA494: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800AA498: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800AA49C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800AA4A0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800AA4A4: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x800AA4A8: mul.d       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x800AA4AC: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x800AA4B0: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800AA4B4: addiu       $t5, $t0, 0x8
    ctx->r13 = ADD32(ctx->r8, 0X8);
    // 0x800AA4B8: sw          $t5, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r13;
    // 0x800AA4BC: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800AA4C0: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x800AA4C4: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800AA4C8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AA4CC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AA4D0: lbu         $t7, 0x1A($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X1A);
    // 0x800AA4D4: cvt.w.d     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.u32l = CVT_W_D(ctx->f16.d);
    // 0x800AA4D8: lbu         $t3, 0x18($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X18);
    // 0x800AA4DC: lbu         $t8, 0x19($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X19);
    // 0x800AA4E0: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800AA4E4: sll         $t9, $t7, 8
    ctx->r25 = S32(ctx->r15 << 8);
    // 0x800AA4E8: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x800AA4EC: sll         $t2, $t3, 24
    ctx->r10 = S32(ctx->r11 << 24);
    // 0x800AA4F0: or          $t5, $t9, $t2
    ctx->r13 = ctx->r25 | ctx->r10;
    // 0x800AA4F4: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x800AA4F8: or          $t4, $t5, $t7
    ctx->r12 = ctx->r13 | ctx->r15;
    // 0x800AA4FC: andi        $t3, $v1, 0xFF
    ctx->r11 = ctx->r3 & 0XFF;
    // 0x800AA500: or          $t9, $t4, $t3
    ctx->r25 = ctx->r12 | ctx->r11;
    // 0x800AA504: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800AA508: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800AA50C: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x800AA510: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800AA514: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x800AA518: swc1        $f10, 0x1E8($t2)
    MEM_W(0X1E8, ctx->r10) = ctx->f10.u32l;
    // 0x800AA51C: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x800AA520: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800AA524: sh          $t6, 0x1E6($t8)
    MEM_H(0X1E6, ctx->r24) = ctx->r14;
    // 0x800AA528: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x800AA52C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800AA530: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800AA534: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800AA538: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800AA53C: jal         0x800AAB5C
    // 0x800AA540: addiu       $a3, $a3, 0x1E0
    ctx->r7 = ADD32(ctx->r7, 0X1E0);
    hud_element_render(rdram, ctx);
        goto after_51;
    // 0x800AA540: addiu       $a3, $a3, 0x1E0
    ctx->r7 = ADD32(ctx->r7, 0X1E0);
    after_51:
L_800AA544:
    // 0x800AA544: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800AA548: lw          $t5, 0x7320($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7320);
    // 0x800AA54C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800AA550: lb          $t7, 0x4C($t5)
    ctx->r15 = MEM_B(ctx->r13, 0X4C);
    // 0x800AA554: nop

    // 0x800AA558: bne         $t7, $at, L_800AA600
    if (ctx->r15 != ctx->r1) {
        // 0x800AA55C: lw          $v0, 0x140($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X140);
            goto L_800AA600;
    }
    // 0x800AA55C: lw          $v0, 0x140($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X140);
    // 0x800AA560: jal         0x80018CA0
    // 0x800AA564: nop

    find_taj_object(rdram, ctx);
        goto after_52;
    // 0x800AA564: nop

    after_52:
    // 0x800AA568: beq         $v0, $zero, L_800AA5FC
    if (ctx->r2 == 0) {
        // 0x800AA56C: nop
    
            goto L_800AA5FC;
    }
    // 0x800AA56C: nop

    // 0x800AA570: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x800AA574: addiu       $t4, $zero, 0xE
    ctx->r12 = ADD32(0, 0XE);
    // 0x800AA578: sh          $t4, 0x1E6($t3)
    MEM_H(0X1E6, ctx->r11) = ctx->r12;
    // 0x800AA57C: lwc1        $f6, 0x11C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x800AA580: lw          $a3, 0x118($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X118);
    // 0x800AA584: lw          $a2, 0x114($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X114);
    // 0x800AA588: lwc1        $f14, 0x14($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800AA58C: lwc1        $f12, 0xC($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800AA590: jal         0x800AA948
    // 0x800AA594: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    minimap_marker_pos(rdram, ctx);
        goto after_53;
    // 0x800AA594: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_53:
    // 0x800AA598: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800AA59C: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800AA5A0: sh          $zero, 0x1E4($t9)
    MEM_H(0X1E4, ctx->r25) = 0;
    // 0x800AA5A4: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x800AA5A8: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x800AA5AC: addiu       $t2, $t0, 0x8
    ctx->r10 = ADD32(ctx->r8, 0X8);
    // 0x800AA5B0: sw          $t2, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r10;
    // 0x800AA5B4: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x800AA5B8: lw          $t8, 0x108($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X108);
    // 0x800AA5BC: ori         $at, $at, 0xFF00
    ctx->r1 = ctx->r1 | 0XFF00;
    // 0x800AA5C0: andi        $t5, $t8, 0xFF
    ctx->r13 = ctx->r24 & 0XFF;
    // 0x800AA5C4: or          $t7, $t5, $at
    ctx->r15 = ctx->r13 | ctx->r1;
    // 0x800AA5C8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800AA5CC: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x800AA5D0: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x800AA5D4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AA5D8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800AA5DC: swc1        $f18, 0x1E8($t4)
    MEM_W(0X1E8, ctx->r12) = ctx->f18.u32l;
    // 0x800AA5E0: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x800AA5E4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800AA5E8: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800AA5EC: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800AA5F0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800AA5F4: jal         0x800AAB5C
    // 0x800AA5F8: addiu       $a3, $a3, 0x1E0
    ctx->r7 = ADD32(ctx->r7, 0X1E0);
    hud_element_render(rdram, ctx);
        goto after_54;
    // 0x800AA5F8: addiu       $a3, $a3, 0x1E0
    ctx->r7 = ADD32(ctx->r7, 0X1E0);
    after_54:
L_800AA5FC:
    // 0x800AA5FC: lw          $v0, 0x140($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X140);
L_800AA600:
    // 0x800AA600: lw          $t3, 0x150($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X150);
    // 0x800AA604: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800AA608: bltz        $v0, L_800AA8D0
    if (SIGNED(ctx->r2) < 0) {
        // 0x800AA60C: sll         $s1, $v0, 2
        ctx->r17 = S32(ctx->r2 << 2);
            goto L_800AA8D0;
    }
    // 0x800AA60C: sll         $s1, $v0, 2
    ctx->r17 = S32(ctx->r2 << 2);
    // 0x800AA610: addu        $s0, $t3, $s1
    ctx->r16 = ADD32(ctx->r11, ctx->r17);
L_800AA614:
    // 0x800AA614: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800AA618: lw          $a2, 0x114($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X114);
    // 0x800AA61C: lw          $a1, 0x64($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X64);
    // 0x800AA620: lw          $a3, 0x118($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X118);
    // 0x800AA624: beq         $a1, $zero, L_800AA8C4
    if (ctx->r5 == 0) {
        // 0x800AA628: nop
    
            goto L_800AA8C4;
    }
    // 0x800AA628: nop

    // 0x800AA62C: lw          $t9, 0x108($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X108);
    // 0x800AA630: lwc1        $f12, 0xC($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800AA634: lwc1        $f14, 0x14($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800AA638: lwc1        $f4, 0x11C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x800AA63C: andi        $t2, $t9, 0xFF
    ctx->r10 = ctx->r25 & 0XFF;
    // 0x800AA640: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
    // 0x800AA644: sw          $a1, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r5;
    // 0x800AA648: jal         0x800AA948
    // 0x800AA64C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    minimap_marker_pos(rdram, ctx);
        goto after_55;
    // 0x800AA64C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_55:
    // 0x800AA650: lw          $a1, 0x148($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X148);
    // 0x800AA654: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800AA658: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x800AA65C: nop

    // 0x800AA660: beq         $s3, $t6, L_800AA700
    if (ctx->r19 == ctx->r14) {
        // 0x800AA664: nop
    
            goto L_800AA700;
    }
    // 0x800AA664: nop

    // 0x800AA668: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800AA66C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800AA670: lwc1        $f16, 0x1F0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X1F0);
    // 0x800AA674: addiu       $t8, $zero, 0x1B
    ctx->r24 = ADD32(0, 0X1B);
    // 0x800AA678: sub.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x800AA67C: addiu       $at, $zero, 0x168
    ctx->r1 = ADD32(0, 0X168);
    // 0x800AA680: swc1        $f10, 0x1F0($v0)
    MEM_W(0X1F0, ctx->r2) = ctx->f10.u32l;
    // 0x800AA684: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x800AA688: nop

    // 0x800AA68C: sh          $t8, 0x1E6($t5)
    MEM_H(0X1E6, ctx->r13) = ctx->r24;
    // 0x800AA690: lw          $t3, 0x158($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X158);
    // 0x800AA694: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800AA698: lhu         $t9, 0x24($t3)
    ctx->r25 = MEM_HU(ctx->r11, 0X24);
    // 0x800AA69C: lh          $t4, 0x0($t7)
    ctx->r12 = MEM_H(ctx->r15, 0X0);
    // 0x800AA6A0: sll         $t2, $t9, 16
    ctx->r10 = S32(ctx->r25 << 16);
    // 0x800AA6A4: subu        $t2, $t2, $t9
    ctx->r10 = SUB32(ctx->r10, ctx->r25);
    // 0x800AA6A8: div         $zero, $t2, $at
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r1)));
    // 0x800AA6AC: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800AA6B0: mflo        $t6
    ctx->r14 = lo;
    // 0x800AA6B4: subu        $t5, $t4, $t6
    ctx->r13 = SUB32(ctx->r12, ctx->r14);
    // 0x800AA6B8: sh          $t5, 0x1E4($t7)
    MEM_H(0X1E4, ctx->r15) = ctx->r13;
    // 0x800AA6BC: jal         0x8009C850
    // 0x800AA6C0: sw          $a1, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r5;
    get_filtered_cheats(rdram, ctx);
        goto after_56;
    // 0x800AA6C0: sw          $a1, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r5;
    after_56:
    // 0x800AA6C4: lw          $a1, 0x148($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X148);
    // 0x800AA6C8: andi        $t3, $v0, 0x4
    ctx->r11 = ctx->r2 & 0X4;
    // 0x800AA6CC: beq         $t3, $zero, L_800AA6EC
    if (ctx->r11 == 0) {
        // 0x800AA6D0: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_800AA6EC;
    }
    // 0x800AA6D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800AA6D4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800AA6D8: ori         $t2, $zero, 0xFFFF
    ctx->r10 = 0 | 0XFFFF;
    // 0x800AA6DC: lh          $t9, 0x1E4($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X1E4);
    // 0x800AA6E0: nop

    // 0x800AA6E4: subu        $t4, $t2, $t9
    ctx->r12 = SUB32(ctx->r10, ctx->r25);
    // 0x800AA6E8: sh          $t4, 0x1E4($v0)
    MEM_H(0X1E4, ctx->r2) = ctx->r12;
L_800AA6EC:
    // 0x800AA6EC: jal         0x8007C36C
    // 0x800AA6F0: sw          $a1, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r5;
    sprite_opaque(rdram, ctx);
        goto after_57;
    // 0x800AA6F0: sw          $a1, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r5;
    after_57:
    // 0x800AA6F4: lw          $a1, 0x148($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X148);
    // 0x800AA6F8: b           L_800AA718
    // 0x800AA6FC: nop

        goto L_800AA718;
    // 0x800AA6FC: nop

L_800AA700:
    // 0x800AA700: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x800AA704: addiu       $t8, $zero, 0xE
    ctx->r24 = ADD32(0, 0XE);
    // 0x800AA708: sh          $zero, 0x1E4($t6)
    MEM_H(0X1E4, ctx->r14) = 0;
    // 0x800AA70C: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x800AA710: nop

    // 0x800AA714: sh          $t8, 0x1E6($t5)
    MEM_H(0X1E6, ctx->r13) = ctx->r24;
L_800AA718:
    // 0x800AA718: jal         0x80023450
    // 0x800AA71C: sw          $a1, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r5;
    is_taj_challenge(rdram, ctx);
        goto after_58;
    // 0x800AA71C: sw          $a1, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r5;
    after_58:
    // 0x800AA720: lw          $a1, 0x148($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X148);
    // 0x800AA724: beq         $v0, $zero, L_800AA764
    if (ctx->r2 == 0) {
        // 0x800AA728: lui         $t8, 0xFA00
        ctx->r24 = S32(0XFA00 << 16);
            goto L_800AA764;
    }
    // 0x800AA728: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x800AA72C: lb          $t7, 0x1D6($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X1D6);
    // 0x800AA730: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800AA734: bne         $t7, $at, L_800AA764
    if (ctx->r15 != ctx->r1) {
        // 0x800AA738: lui         $t2, 0xFA00
        ctx->r10 = S32(0XFA00 << 16);
            goto L_800AA764;
    }
    // 0x800AA738: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x800AA73C: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x800AA740: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x800AA744: addiu       $t3, $t0, 0x8
    ctx->r11 = ADD32(ctx->r8, 0X8);
    // 0x800AA748: sw          $t3, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r11;
    // 0x800AA74C: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x800AA750: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x800AA754: ori         $at, $at, 0xFF00
    ctx->r1 = ctx->r1 | 0XFF00;
    // 0x800AA758: or          $t4, $t9, $at
    ctx->r12 = ctx->r25 | ctx->r1;
    // 0x800AA75C: b           L_800AA7B8
    // 0x800AA760: sw          $t4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r12;
        goto L_800AA7B8;
    // 0x800AA760: sw          $t4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r12;
L_800AA764:
    // 0x800AA764: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x800AA768: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800AA76C: addiu       $t6, $t0, 0x8
    ctx->r14 = ADD32(ctx->r8, 0X8);
    // 0x800AA770: sw          $t6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r14;
    // 0x800AA774: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x800AA778: lb          $t5, 0x3($a1)
    ctx->r13 = MEM_B(ctx->r5, 0X3);
    // 0x800AA77C: addiu       $t3, $t3, 0x2D3C
    ctx->r11 = ADD32(ctx->r11, 0X2D3C);
    // 0x800AA780: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x800AA784: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x800AA788: addu        $v0, $t7, $t3
    ctx->r2 = ADD32(ctx->r15, ctx->r11);
    // 0x800AA78C: lbu         $t9, 0x2($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X2);
    // 0x800AA790: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x800AA794: lbu         $t2, 0x1($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X1);
    // 0x800AA798: sll         $t4, $t9, 8
    ctx->r12 = S32(ctx->r25 << 8);
    // 0x800AA79C: sll         $t5, $t8, 24
    ctx->r13 = S32(ctx->r24 << 24);
    // 0x800AA7A0: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800AA7A4: or          $t7, $t4, $t5
    ctx->r15 = ctx->r12 | ctx->r13;
    // 0x800AA7A8: sll         $t9, $t2, 16
    ctx->r25 = S32(ctx->r10 << 16);
    // 0x800AA7AC: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x800AA7B0: or          $t4, $t6, $t8
    ctx->r12 = ctx->r14 | ctx->r24;
    // 0x800AA7B4: sw          $t4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r12;
L_800AA7B8:
    // 0x800AA7B8: jal         0x8006BFD8
    // 0x800AA7BC: sw          $a1, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r5;
    level_type(rdram, ctx);
        goto after_59;
    // 0x800AA7BC: sw          $a1, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r5;
    after_59:
    // 0x800AA7C0: lw          $a1, 0x148($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X148);
    // 0x800AA7C4: andi        $t5, $v0, 0x40
    ctx->r13 = ctx->r2 & 0X40;
    // 0x800AA7C8: beq         $t5, $zero, L_800AA7E0
    if (ctx->r13 == 0) {
        // 0x800AA7CC: lui         $t2, 0x8000
        ctx->r10 = S32(0X8000 << 16);
            goto L_800AA7E0;
    }
    // 0x800AA7CC: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x800AA7D0: lb          $t3, 0x1D8($a1)
    ctx->r11 = MEM_B(ctx->r5, 0X1D8);
    // 0x800AA7D4: nop

    // 0x800AA7D8: bne         $t3, $zero, L_800AA8BC
    if (ctx->r11 != 0) {
        // 0x800AA7DC: nop
    
            goto L_800AA8BC;
    }
    // 0x800AA7DC: nop

L_800AA7E0:
    // 0x800AA7E0: lw          $t2, 0x300($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X300);
    // 0x800AA7E4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800AA7E8: bne         $t2, $zero, L_800AA808
    if (ctx->r10 != 0) {
        // 0x800AA7EC: nop
    
            goto L_800AA808;
    }
    // 0x800AA7EC: nop

    // 0x800AA7F0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800AA7F4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AA7F8: lwc1        $f6, 0x1EC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1EC);
    // 0x800AA7FC: nop

    // 0x800AA800: sub.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x800AA804: swc1        $f4, 0x1EC($v0)
    MEM_W(0X1EC, ctx->r2) = ctx->f4.u32l;
L_800AA808:
    // 0x800AA808: jal         0x8006BFD8
    // 0x800AA80C: sw          $a1, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r5;
    level_type(rdram, ctx);
        goto after_60;
    // 0x800AA80C: sw          $a1, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r5;
    after_60:
    // 0x800AA810: lw          $a1, 0x148($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X148);
    // 0x800AA814: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x800AA818: bne         $v0, $at, L_800AA88C
    if (ctx->r2 != ctx->r1) {
        // 0x800AA81C: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_800AA88C;
    }
    // 0x800AA81C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800AA820: lb          $v0, 0x212($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X212);
    // 0x800AA824: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800AA828: beq         $v0, $zero, L_800AA854
    if (ctx->r2 == 0) {
        // 0x800AA82C: nop
    
            goto L_800AA854;
    }
    // 0x800AA82C: nop

    // 0x800AA830: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800AA834: beq         $v0, $at, L_800AA864
    if (ctx->r2 == ctx->r1) {
        // 0x800AA838: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800AA864;
    }
    // 0x800AA838: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800AA83C: beq         $v0, $at, L_800AA878
    if (ctx->r2 == ctx->r1) {
        // 0x800AA840: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800AA878;
    }
    // 0x800AA840: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800AA844: beq         $v0, $at, L_800AA878
    if (ctx->r2 == ctx->r1) {
        // 0x800AA848: nop
    
            goto L_800AA878;
    }
    // 0x800AA848: nop

    // 0x800AA84C: b           L_800AA8A4
    // 0x800AA850: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
        goto L_800AA8A4;
    // 0x800AA850: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
L_800AA854:
    // 0x800AA854: lwc1        $f16, -0x72B0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X72B0);
    // 0x800AA858: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800AA85C: b           L_800AA8A0
    // 0x800AA860: swc1        $f16, 0x1E8($t7)
    MEM_W(0X1E8, ctx->r15) = ctx->f16.u32l;
        goto L_800AA8A0;
    // 0x800AA860: swc1        $f16, 0x1E8($t7)
    MEM_W(0X1E8, ctx->r15) = ctx->f16.u32l;
L_800AA864:
    // 0x800AA864: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800AA868: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800AA86C: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800AA870: b           L_800AA8A0
    // 0x800AA874: swc1        $f8, 0x1E8($t9)
    MEM_W(0X1E8, ctx->r25) = ctx->f8.u32l;
        goto L_800AA8A0;
    // 0x800AA874: swc1        $f8, 0x1E8($t9)
    MEM_W(0X1E8, ctx->r25) = ctx->f8.u32l;
L_800AA878:
    // 0x800AA878: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800AA87C: lwc1        $f10, -0x72AC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X72AC);
    // 0x800AA880: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x800AA884: b           L_800AA8A0
    // 0x800AA888: swc1        $f10, 0x1E8($t6)
    MEM_W(0X1E8, ctx->r14) = ctx->f10.u32l;
        goto L_800AA8A0;
    // 0x800AA888: swc1        $f10, 0x1E8($t6)
    MEM_W(0X1E8, ctx->r14) = ctx->f10.u32l;
L_800AA88C:
    // 0x800AA88C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800AA890: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800AA894: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x800AA898: nop

    // 0x800AA89C: swc1        $f6, 0x1E8($t8)
    MEM_W(0X1E8, ctx->r24) = ctx->f6.u32l;
L_800AA8A0:
    // 0x800AA8A0: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
L_800AA8A4:
    // 0x800AA8A4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800AA8A8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800AA8AC: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800AA8B0: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800AA8B4: jal         0x800AAB5C
    // 0x800AA8B8: addiu       $a3, $a3, 0x1E0
    ctx->r7 = ADD32(ctx->r7, 0X1E0);
    hud_element_render(rdram, ctx);
        goto after_61;
    // 0x800AA8B8: addiu       $a3, $a3, 0x1E0
    ctx->r7 = ADD32(ctx->r7, 0X1E0);
    after_61:
L_800AA8BC:
    // 0x800AA8BC: jal         0x8007C36C
    // 0x800AA8C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_62;
    // 0x800AA8C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_62:
L_800AA8C4:
    // 0x800AA8C4: addiu       $s1, $s1, -0x4
    ctx->r17 = ADD32(ctx->r17, -0X4);
    // 0x800AA8C8: bgez        $s1, L_800AA614
    if (SIGNED(ctx->r17) >= 0) {
        // 0x800AA8CC: addiu       $s0, $s0, -0x4
        ctx->r16 = ADD32(ctx->r16, -0X4);
            goto L_800AA614;
    }
    // 0x800AA8CC: addiu       $s0, $s0, -0x4
    ctx->r16 = ADD32(ctx->r16, -0X4);
L_800AA8D0:
    // 0x800AA8D0: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x800AA8D4: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x800AA8D8: addiu       $t4, $t0, 0x8
    ctx->r12 = ADD32(ctx->r8, 0X8);
    // 0x800AA8DC: sw          $t4, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r12;
    // 0x800AA8E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800AA8E4: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x800AA8E8: jal         0x80068748
    // 0x800AA8EC: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_63;
    // 0x800AA8EC: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
    after_63:
    // 0x800AA8F0: jal         0x8007C36C
    // 0x800AA8F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprite_opaque(rdram, ctx);
        goto after_64;
    // 0x800AA8F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_64:
    // 0x800AA8F8: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x800AA8FC: lw          $t2, 0x160($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X160);
    // 0x800AA900: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800AA904: sw          $t3, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r11;
    // 0x800AA908: lw          $t9, 0x164($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X164);
    // 0x800AA90C: lw          $t7, 0x72C0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X72C0);
    // 0x800AA910: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800AA914: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x800AA918: lw          $t8, 0x168($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X168);
    // 0x800AA91C: lw          $t6, 0x72C4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X72C4);
    // 0x800AA920: nop

    // 0x800AA924: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
L_800AA928:
    // 0x800AA928: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800AA92C:
    // 0x800AA92C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800AA930: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800AA934: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800AA938: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800AA93C: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800AA940: jr          $ra
    // 0x800AA944: addiu       $sp, $sp, 0x160
    ctx->r29 = ADD32(ctx->r29, 0X160);
    return;
    // 0x800AA944: addiu       $sp, $sp, 0x160
    ctx->r29 = ADD32(ctx->r29, 0X160);
;}
RECOMP_FUNC void minimap_marker_pos(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA948: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800AA94C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AA950: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    // 0x800AA954: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    // 0x800AA958: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800AA95C: jal         0x8002C804
    // 0x800AA960: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    get_current_level_model(rdram, ctx);
        goto after_0;
    // 0x800AA960: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800AA964: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x800AA968: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AA96C: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800AA970: lh          $v1, 0x3C($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X3C);
    // 0x800AA974: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AA978: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800AA97C: lwc1        $f10, 0x28($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X28);
    // 0x800AA980: lh          $t6, 0x3E($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X3E);
    // 0x800AA984: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AA988: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800AA98C: subu        $a2, $t6, $v1
    ctx->r6 = SUB32(ctx->r14, ctx->r3);
    // 0x800AA990: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800AA994: sub.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x800AA998: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x800AA99C: lh          $a0, 0x44($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X44);
    // 0x800AA9A0: mul.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x800AA9A4: lui         $at, 0xC270
    ctx->r1 = S32(0XC270 << 16);
    // 0x800AA9A8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800AA9AC: lwc1        $f6, 0x2C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x800AA9B0: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AA9B4: lh          $t7, 0x46($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X46);
    // 0x800AA9B8: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800AA9BC: div.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800AA9C0: mtc1        $a0, $f10
    ctx->f10.u32l = ctx->r4;
    // 0x800AA9C4: mul.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800AA9C8: subu        $a3, $t7, $a0
    ctx->r7 = SUB32(ctx->r15, ctx->r4);
    // 0x800AA9CC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800AA9D0: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800AA9D4: mtc1        $a3, $f10
    ctx->f10.u32l = ctx->r7;
    // 0x800AA9D8: sub.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x800AA9DC: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x800AA9E0: mul.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800AA9E4: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800AA9E8: nop

    // 0x800AA9EC: div.s       $f2, $f16, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800AA9F0: jal         0x8009C850
    // 0x800AA9F4: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    get_filtered_cheats(rdram, ctx);
        goto after_1;
    // 0x800AA9F4: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x800AA9F8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800AA9FC: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800AAA00: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800AAA04: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800AAA08: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800AAA0C: andi        $t8, $v0, 0x4
    ctx->r24 = ctx->r2 & 0X4;
    // 0x800AAA10: beq         $t8, $zero, L_800AAAB4
    if (ctx->r24 == 0) {
        // 0x800AAA14: nop
    
            goto L_800AAAB4;
    }
    // 0x800AAA14: nop

    // 0x800AAA18: mul.s       $f18, $f0, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x800AAA1C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800AAA20: lw          $t9, 0x7318($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7318);
    // 0x800AAA24: lh          $t0, 0x34($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X34);
    // 0x800AAA28: mul.s       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x800AAA2C: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x800AAA30: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800AAA34: lw          $t1, 0x72DC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X72DC);
    // 0x800AAA38: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800AAA3C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800AAA40: addiu       $v0, $v0, 0x729C
    ctx->r2 = ADD32(ctx->r2, 0X729C);
    // 0x800AAA44: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800AAA48: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x800AAA4C: sub.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x800AAA50: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x800AAA54: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800AAA58: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800AAA5C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800AAA60: cvt.s.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800AAA64: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800AAA68: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800AAA6C: sub.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800AAA70: swc1        $f18, 0x1EC($t2)
    MEM_W(0X1EC, ctx->r10) = ctx->f18.u32l;
    // 0x800AAA74: mul.s       $f16, $f0, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x800AAA78: lw          $t4, 0x731C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X731C);
    // 0x800AAA7C: lh          $t3, 0x36($a1)
    ctx->r11 = MEM_H(ctx->r5, 0X36);
    // 0x800AAA80: lw          $t6, 0x72E0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X72E0);
    // 0x800AAA84: mul.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x800AAA88: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800AAA8C: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x800AAA90: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800AAA94: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AAA98: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800AAA9C: sub.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x800AAAA0: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AAAA4: sub.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x800AAAA8: add.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800AAAAC: b           L_800AAB4C
    // 0x800AAAB0: swc1        $f10, 0x1F0($t7)
    MEM_W(0X1F0, ctx->r15) = ctx->f10.u32l;
        goto L_800AAB4C;
    // 0x800AAAB0: swc1        $f10, 0x1F0($t7)
    MEM_W(0X1F0, ctx->r15) = ctx->f10.u32l;
L_800AAAB4:
    // 0x800AAAB4: mul.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x800AAAB8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800AAABC: lw          $t8, 0x7318($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7318);
    // 0x800AAAC0: lh          $t9, 0x30($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X30);
    // 0x800AAAC4: mul.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x800AAAC8: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x800AAACC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800AAAD0: lw          $t0, 0x72DC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X72DC);
    // 0x800AAAD4: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800AAAD8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800AAADC: addiu       $v0, $v0, 0x729C
    ctx->r2 = ADD32(ctx->r2, 0X729C);
    // 0x800AAAE0: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800AAAE4: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800AAAE8: add.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x800AAAEC: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x800AAAF0: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800AAAF4: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800AAAF8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800AAAFC: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800AAB00: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800AAB04: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800AAB08: sub.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800AAB0C: swc1        $f8, 0x1EC($t1)
    MEM_W(0X1EC, ctx->r9) = ctx->f8.u32l;
    // 0x800AAB10: mul.s       $f16, $f0, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x800AAB14: lw          $t3, 0x731C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X731C);
    // 0x800AAB18: lh          $t2, 0x32($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X32);
    // 0x800AAB1C: lw          $t5, 0x72E0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X72E0);
    // 0x800AAB20: mul.s       $f18, $f2, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x800AAB24: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800AAB28: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x800AAB2C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800AAB30: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800AAB34: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x800AAB38: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800AAB3C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800AAB40: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800AAB44: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800AAB48: swc1        $f18, 0x1F0($t6)
    MEM_W(0X1F0, ctx->r14) = ctx->f18.u32l;
L_800AAB4C:
    // 0x800AAB4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AAB50: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800AAB54: jr          $ra
    // 0x800AAB58: nop

    return;
    // 0x800AAB58: nop

;}
RECOMP_FUNC void hud_element_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AAB5C: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x800AAB60: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800AAB64: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800AAB68: sw          $a0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r4;
    // 0x800AAB6C: sw          $a1, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r5;
    // 0x800AAB70: sw          $a2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r6;
    // 0x800AAB74: lh          $t0, 0x6($a3)
    ctx->r8 = MEM_H(ctx->r7, 0X6);
    // 0x800AAB78: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800AAB7C: lw          $v1, 0x72B0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X72B0);
    // 0x800AAB80: sll         $t6, $t0, 1
    ctx->r14 = S32(ctx->r8 << 1);
    // 0x800AAB84: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x800AAB88: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x800AAB8C: ori         $t2, $zero, 0xC000
    ctx->r10 = 0 | 0XC000;
    // 0x800AAB90: andi        $v0, $t8, 0xC000
    ctx->r2 = ctx->r24 & 0XC000;
    // 0x800AAB94: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x800AAB98: bne         $t2, $v0, L_800AABB8
    if (ctx->r10 != ctx->r2) {
        // 0x800AAB9C: sw          $t8, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r24;
            goto L_800AABB8;
    }
    // 0x800AAB9C: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x800AABA0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800AABA4: lb          $t3, 0x7290($t3)
    ctx->r11 = MEM_B(ctx->r11, 0X7290);
    // 0x800AABA8: nop

    // 0x800AABAC: negu        $t4, $t3
    ctx->r12 = SUB32(0, ctx->r11);
    // 0x800AABB0: b           L_800AABC8
    // 0x800AABB4: sw          $t4, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r12;
        goto L_800AABC8;
    // 0x800AABB4: sw          $t4, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r12;
L_800AABB8:
    // 0x800AABB8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800AABBC: lb          $t5, 0x7290($t5)
    ctx->r13 = MEM_B(ctx->r13, 0X7290);
    // 0x800AABC0: nop

    // 0x800AABC4: sw          $t5, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r13;
L_800AABC8:
    // 0x800AABC8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800AABCC: addiu       $t1, $t1, 0x72B4
    ctx->r9 = ADD32(ctx->r9, 0X72B4);
    // 0x800AABD0: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800AABD4: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x800AABD8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800AABDC: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800AABE0: nop

    // 0x800AABE4: bne         $t9, $zero, L_800AAD10
    if (ctx->r25 != 0) {
        // 0x800AABE8: nop
    
            goto L_800AAD10;
    }
    // 0x800AABE8: nop

    // 0x800AABEC: bne         $t2, $v0, L_800AAC2C
    if (ctx->r10 != ctx->r2) {
        // 0x800AABF0: lw          $t8, 0x38($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X38);
            goto L_800AAC2C;
    }
    // 0x800AABF0: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800AABF4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800AABF8: nop

    // 0x800AABFC: andi        $t3, $a0, 0x3FFF
    ctx->r11 = ctx->r4 & 0X3FFF;
    // 0x800AAC00: jal         0x8007B2C4
    // 0x800AAC04: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    load_texture(rdram, ctx);
        goto after_0;
    // 0x800AAC04: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_0:
    // 0x800AAC08: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800AAC0C: lh          $t5, 0x6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X6);
    // 0x800AAC10: addiu       $t1, $t1, 0x72B4
    ctx->r9 = ADD32(ctx->r9, 0X72B4);
    // 0x800AAC14: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800AAC18: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800AAC1C: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x800AAC20: b           L_800AACF4
    // 0x800AAC24: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
        goto L_800AACF4;
    // 0x800AAC24: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
    // 0x800AAC28: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
L_800AAC2C:
    // 0x800AAC2C: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800AAC30: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x800AAC34: beq         $t9, $zero, L_800AAC64
    if (ctx->r25 == 0) {
        // 0x800AAC38: andi        $a0, $t8, 0x3FFF
        ctx->r4 = ctx->r24 & 0X3FFF;
            goto L_800AAC64;
    }
    // 0x800AAC38: andi        $a0, $t8, 0x3FFF
    ctx->r4 = ctx->r24 & 0X3FFF;
    // 0x800AAC3C: jal         0x8007C57C
    // 0x800AAC40: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    tex_load_sprite(rdram, ctx);
        goto after_1;
    // 0x800AAC40: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x800AAC44: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800AAC48: lh          $t5, 0x6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X6);
    // 0x800AAC4C: addiu       $t1, $t1, 0x72B4
    ctx->r9 = ADD32(ctx->r9, 0X72B4);
    // 0x800AAC50: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x800AAC54: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x800AAC58: addu        $t6, $t3, $t4
    ctx->r14 = ADD32(ctx->r11, ctx->r12);
    // 0x800AAC5C: b           L_800AACF4
    // 0x800AAC60: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
        goto L_800AACF4;
    // 0x800AAC60: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
L_800AAC64:
    // 0x800AAC64: andi        $t9, $t7, 0x4000
    ctx->r25 = ctx->r15 & 0X4000;
    // 0x800AAC68: beq         $t9, $zero, L_800AACCC
    if (ctx->r25 == 0) {
        // 0x800AAC6C: or          $t8, $t7, $zero
        ctx->r24 = ctx->r15 | 0;
            goto L_800AACCC;
    }
    // 0x800AAC6C: or          $t8, $t7, $zero
    ctx->r24 = ctx->r15 | 0;
    // 0x800AAC70: sb          $t8, 0x9C($sp)
    MEM_B(0X9C, ctx->r29) = ctx->r24;
    // 0x800AAC74: lh          $t5, 0x6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X6);
    // 0x800AAC78: addiu       $a0, $sp, 0x9C
    ctx->r4 = ADD32(ctx->r29, 0X9C);
    // 0x800AAC7C: sll         $t3, $t5, 1
    ctx->r11 = S32(ctx->r13 << 1);
    // 0x800AAC80: addu        $t4, $v1, $t3
    ctx->r12 = ADD32(ctx->r3, ctx->r11);
    // 0x800AAC84: lh          $t6, 0x0($t4)
    ctx->r14 = MEM_H(ctx->r12, 0X0);
    // 0x800AAC88: sh          $zero, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = 0;
    // 0x800AAC8C: andi        $t9, $t6, 0x100
    ctx->r25 = ctx->r14 & 0X100;
    // 0x800AAC90: sra         $t7, $t9, 1
    ctx->r15 = S32(SIGNED(ctx->r25) >> 1);
    // 0x800AAC94: ori         $t8, $t7, 0x8
    ctx->r24 = ctx->r15 | 0X8;
    // 0x800AAC98: sb          $t8, 0x9D($sp)
    MEM_B(0X9D, ctx->r29) = ctx->r24;
    // 0x800AAC9C: sh          $zero, 0xA0($sp)
    MEM_H(0XA0, ctx->r29) = 0;
    // 0x800AACA0: sh          $zero, 0xA2($sp)
    MEM_H(0XA2, ctx->r29) = 0;
    // 0x800AACA4: jal         0x8000EA54
    // 0x800AACA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    spawn_object(rdram, ctx);
        goto after_2;
    // 0x800AACA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x800AACAC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800AACB0: lh          $t3, 0x6($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X6);
    // 0x800AACB4: addiu       $t1, $t1, 0x72B4
    ctx->r9 = ADD32(ctx->r9, 0X72B4);
    // 0x800AACB8: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800AACBC: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800AACC0: addu        $t6, $t5, $t4
    ctx->r14 = ADD32(ctx->r13, ctx->r12);
    // 0x800AACC4: b           L_800AACF4
    // 0x800AACC8: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
        goto L_800AACF4;
    // 0x800AACC8: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
L_800AACCC:
    // 0x800AACCC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800AACD0: jal         0x8005FB3C
    // 0x800AACD4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    object_model_init(rdram, ctx);
        goto after_3;
    // 0x800AACD4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x800AACD8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800AACDC: lh          $t7, 0x6($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X6);
    // 0x800AACE0: addiu       $t1, $t1, 0x72B4
    ctx->r9 = ADD32(ctx->r9, 0X72B4);
    // 0x800AACE4: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800AACE8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800AACEC: addu        $t3, $t9, $t8
    ctx->r11 = ADD32(ctx->r25, ctx->r24);
    // 0x800AACF0: sw          $v0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r2;
L_800AACF4:
    // 0x800AACF4: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
    // 0x800AACF8: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800AACFC: sll         $t4, $t0, 2
    ctx->r12 = S32(ctx->r8 << 2);
    // 0x800AAD00: addu        $t6, $t5, $t4
    ctx->r14 = ADD32(ctx->r13, ctx->r12);
    // 0x800AAD04: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800AAD08: nop

    // 0x800AAD0C: beq         $t7, $zero, L_800AB51C
    if (ctx->r15 == 0) {
        // 0x800AAD10: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_800AB51C;
    }
L_800AAD10:
    // 0x800AAD10: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800AAD14: lw          $t9, 0x7298($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7298);
    // 0x800AAD18: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AAD1C: addu        $t8, $t9, $t0
    ctx->r24 = ADD32(ctx->r25, ctx->r8);
    // 0x800AAD20: sb          $zero, 0x0($t8)
    MEM_B(0X0, ctx->r24) = 0;
    // 0x800AAD24: lw          $t3, 0xB8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB8);
    // 0x800AAD28: lw          $t4, 0xBC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XBC);
    // 0x800AAD2C: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x800AAD30: lw          $t7, 0xC0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC0);
    // 0x800AAD34: sw          $t5, 0x72BC($at)
    MEM_W(0X72BC, ctx->r1) = ctx->r13;
    // 0x800AAD38: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x800AAD3C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AAD40: sw          $t6, 0x72C0($at)
    MEM_W(0X72C0, ctx->r1) = ctx->r14;
    // 0x800AAD44: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x800AAD48: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AAD4C: sw          $t9, 0x72C4($at)
    MEM_W(0X72C4, ctx->r1) = ctx->r25;
    // 0x800AAD50: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
    // 0x800AAD54: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x800AAD58: beq         $t0, $at, L_800AADE0
    if (ctx->r8 == ctx->r1) {
        // 0x800AAD5C: ori         $t2, $zero, 0xC000
        ctx->r10 = 0 | 0XC000;
            goto L_800AADE0;
    }
    // 0x800AAD5C: ori         $t2, $zero, 0xC000
    ctx->r10 = 0 | 0XC000;
    // 0x800AAD60: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x800AAD64: beq         $t0, $at, L_800AADB8
    if (ctx->r8 == ctx->r1) {
        // 0x800AAD68: lui         $t4, 0x8012
        ctx->r12 = S32(0X8012 << 16);
            goto L_800AADB8;
    }
    // 0x800AAD68: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800AAD6C: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x800AAD70: beq         $t0, $at, L_800AADB8
    if (ctx->r8 == ctx->r1) {
        // 0x800AAD74: slti        $at, $t0, 0x2F
        ctx->r1 = SIGNED(ctx->r8) < 0X2F ? 1 : 0;
            goto L_800AADB8;
    }
    // 0x800AAD74: slti        $at, $t0, 0x2F
    ctx->r1 = SIGNED(ctx->r8) < 0X2F ? 1 : 0;
    // 0x800AAD78: bne         $at, $zero, L_800AAD84
    if (ctx->r1 != 0) {
        // 0x800AAD7C: slti        $at, $t0, 0x36
        ctx->r1 = SIGNED(ctx->r8) < 0X36 ? 1 : 0;
            goto L_800AAD84;
    }
    // 0x800AAD7C: slti        $at, $t0, 0x36
    ctx->r1 = SIGNED(ctx->r8) < 0X36 ? 1 : 0;
    // 0x800AAD80: bne         $at, $zero, L_800AADB8
    if (ctx->r1 != 0) {
        // 0x800AAD84: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_800AADB8;
    }
L_800AAD84:
    // 0x800AAD84: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x800AAD88: beq         $t0, $at, L_800AADB8
    if (ctx->r8 == ctx->r1) {
        // 0x800AAD8C: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_800AADB8;
    }
    // 0x800AAD8C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800AAD90: lb          $t8, 0x7293($t8)
    ctx->r24 = MEM_B(ctx->r24, 0X7293);
    // 0x800AAD94: lw          $t5, 0xA4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA4);
    // 0x800AAD98: andi        $t3, $t8, 0x1
    ctx->r11 = ctx->r24 & 0X1;
    // 0x800AAD9C: beq         $t3, $zero, L_800AADB8
    if (ctx->r11 == 0) {
        // 0x800AADA0: nop
    
            goto L_800AADB8;
    }
    // 0x800AADA0: nop

    // 0x800AADA4: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x800AADA8: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800AADAC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800AADB0: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800AADB4: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
L_800AADB8:
    // 0x800AADB8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800AADBC: lw          $t6, 0x72E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X72E8);
    // 0x800AADC0: lw          $t4, 0x72E4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X72E4);
    // 0x800AADC4: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800AADC8: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x800AADCC: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x800AADD0: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
    // 0x800AADD4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800AADD8: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800AADDC: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
L_800AADE0:
    // 0x800AADE0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800AADE4: lw          $t9, 0x72B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X72B0);
    // 0x800AADE8: sll         $t8, $t0, 1
    ctx->r24 = S32(ctx->r8 << 1);
    // 0x800AADEC: addu        $t3, $t9, $t8
    ctx->r11 = ADD32(ctx->r25, ctx->r24);
    // 0x800AADF0: lh          $v0, 0x0($t3)
    ctx->r2 = MEM_H(ctx->r11, 0X0);
    // 0x800AADF4: slti        $at, $t0, 0x2F
    ctx->r1 = SIGNED(ctx->r8) < 0X2F ? 1 : 0;
    // 0x800AADF8: andi        $t5, $v0, 0xC000
    ctx->r13 = ctx->r2 & 0XC000;
    // 0x800AADFC: bne         $t2, $t5, L_800AB300
    if (ctx->r10 != ctx->r13) {
        // 0x800AAE00: andi        $t9, $v0, 0x8000
        ctx->r25 = ctx->r2 & 0X8000;
            goto L_800AB300;
    }
    // 0x800AAE00: andi        $t9, $v0, 0x8000
    ctx->r25 = ctx->r2 & 0X8000;
    // 0x800AAE04: bne         $at, $zero, L_800AB05C
    if (ctx->r1 != 0) {
        // 0x800AAE08: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_800AB05C;
    }
    // 0x800AAE08: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800AAE0C: slti        $at, $t0, 0x36
    ctx->r1 = SIGNED(ctx->r8) < 0X36 ? 1 : 0;
    // 0x800AAE10: beq         $at, $zero, L_800AB05C
    if (ctx->r1 == 0) {
        // 0x800AAE14: lui         $a0, 0x8000
        ctx->r4 = S32(0X8000 << 16);
            goto L_800AB05C;
    }
    // 0x800AAE14: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x800AAE18: lw          $a0, 0x300($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X300);
    // 0x800AAE1C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800AAE20: bne         $a0, $zero, L_800AAE48
    if (ctx->r4 != 0) {
        // 0x800AAE24: lui         $t4, 0x8012
        ctx->r12 = S32(0X8012 << 16);
            goto L_800AAE48;
    }
    // 0x800AAE24: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800AAE28: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800AAE2C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800AAE30: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x800AAE34: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800AAE38: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
    // 0x800AAE3C: swc1        $f16, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f16.u32l;
    // 0x800AAE40: lw          $a0, 0x300($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X300);
    // 0x800AAE44: nop

L_800AAE48:
    // 0x800AAE48: lb          $t4, 0x7293($t4)
    ctx->r12 = MEM_B(ctx->r12, 0X7293);
    // 0x800AAE4C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800AAE50: andi        $t6, $t4, 0x2
    ctx->r14 = ctx->r12 & 0X2;
    // 0x800AAE54: beq         $t6, $zero, L_800AAED0
    if (ctx->r14 == 0) {
        // 0x800AAE58: addiu       $v1, $zero, 0xFF
        ctx->r3 = ADD32(0, 0XFF);
            goto L_800AAED0;
    }
    // 0x800AAE58: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x800AAE5C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800AAE60: lb          $t7, 0x7290($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X7290);
    // 0x800AAE64: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800AAE68: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800AAE6C: lbu         $t9, 0x774B($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X774B);
    // 0x800AAE70: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800AAE74: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800AAE78: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800AAE7C: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800AAE80: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800AAE84: bgez        $t9, L_800AAE98
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800AAE88: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800AAE98;
    }
    // 0x800AAE88: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800AAE8C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800AAE90: nop

    // 0x800AAE94: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_800AAE98:
    // 0x800AAE98: nop

    // 0x800AAE9C: div.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800AAEA0: sub.s       $f18, $f0, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x800AAEA4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800AAEA8: nop

    // 0x800AAEAC: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800AAEB0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AAEB4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AAEB8: nop

    // 0x800AAEBC: cvt.w.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800AAEC0: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x800AAEC4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800AAEC8: b           L_800AAED4
    // 0x800AAECC: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
        goto L_800AAED4;
    // 0x800AAECC: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
L_800AAED0:
    // 0x800AAED0: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
L_800AAED4:
    // 0x800AAED4: sll         $t5, $t0, 2
    ctx->r13 = S32(ctx->r8 << 2);
    // 0x800AAED8: addu        $t4, $t3, $t5
    ctx->r12 = ADD32(ctx->r11, ctx->r13);
    // 0x800AAEDC: lw          $v0, 0x0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X0);
    // 0x800AAEE0: lh          $t6, 0x18($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X18);
    // 0x800AAEE4: lh          $t7, 0x16($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X16);
    // 0x800AAEE8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800AAEEC: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AAEF0: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800AAEF4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AAEF8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AAEFC: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800AAF00: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    // 0x800AAF04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800AAF08: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800AAF0C: mflo        $t9
    ctx->r25 = lo;
    // 0x800AAF10: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x800AAF14: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
    // 0x800AAF18: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800AAF1C: nop

    // 0x800AAF20: cvt.w.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800AAF24: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800AAF28: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x800AAF2C: nop

    // 0x800AAF30: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800AAF34: sh          $t3, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r11;
    // 0x800AAF38: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800AAF3C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AAF40: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AAF44: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800AAF48: sw          $zero, 0x90($sp)
    MEM_W(0X90, ctx->r29) = 0;
    // 0x800AAF4C: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800AAF50: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x800AAF54: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800AAF58: bne         $a0, $zero, L_800AB00C
    if (ctx->r4 != 0) {
        // 0x800AAF5C: sh          $t4, 0x8E($sp)
        MEM_H(0X8E, ctx->r29) = ctx->r12;
            goto L_800AB00C;
    }
    // 0x800AAF5C: sh          $t4, 0x8E($sp)
    MEM_H(0X8E, ctx->r29) = ctx->r12;
    // 0x800AAF60: lh          $t6, 0x6($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X6);
    // 0x800AAF64: addiu       $at, $zero, 0x35
    ctx->r1 = ADD32(0, 0X35);
    // 0x800AAF68: bne         $t6, $at, L_800AAFD4
    if (ctx->r14 != ctx->r1) {
        // 0x800AAF6C: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800AAFD4;
    }
    // 0x800AAF6C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800AAF70: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800AAF74: bne         $v1, $at, L_800AAF84
    if (ctx->r3 != ctx->r1) {
        // 0x800AAF78: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800AAF84;
    }
    // 0x800AAF78: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800AAF7C: b           L_800AAF8C
    // 0x800AAF80: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
        goto L_800AAF8C;
    // 0x800AAF80: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
L_800AAF84:
    // 0x800AAF84: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x800AAF88: or          $v0, $v1, $at
    ctx->r2 = ctx->r3 | ctx->r1;
L_800AAF8C:
    // 0x800AAF8C: sh          $zero, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = 0;
    // 0x800AAF90: sh          $zero, 0x8E($sp)
    MEM_H(0X8E, ctx->r29) = 0;
    // 0x800AAF94: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800AAF98: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AAF9C: lw          $a3, 0x10($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X10);
    // 0x800AAFA0: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x800AAFA4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800AAFA8: lwc1        $f8, -0x72A8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X72A8);
    // 0x800AAFAC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800AAFB0: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800AAFB4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800AAFB8: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800AAFBC: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    // 0x800AAFC0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x800AAFC4: jal         0x80079150
    // 0x800AAFC8: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    texrect_draw_scaled(rdram, ctx);
        goto after_4;
    // 0x800AAFC8: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_4:
    // 0x800AAFCC: b           L_800AB030
    // 0x800AAFD0: nop

        goto L_800AB030;
    // 0x800AAFD0: nop

L_800AAFD4:
    // 0x800AAFD4: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800AAFD8: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800AAFDC: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800AAFE0: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x800AAFE4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800AAFE8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800AAFEC: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800AAFF0: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    // 0x800AAFF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800AAFF8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800AAFFC: jal         0x80078F08
    // 0x800AB000: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    texrect_draw(rdram, ctx);
        goto after_5;
    // 0x800AB000: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_5:
    // 0x800AB004: b           L_800AB030
    // 0x800AB008: nop

        goto L_800AB030;
    // 0x800AB008: nop

L_800AB00C:
    // 0x800AB00C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800AB010: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x800AB014: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800AB018: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800AB01C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800AB020: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800AB024: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x800AB028: jal         0x80078F08
    // 0x800AB02C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    texrect_draw(rdram, ctx);
        goto after_6;
    // 0x800AB02C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_6:
L_800AB030:
    // 0x800AB030: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x800AB034: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x800AB038: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800AB03C: bne         $t7, $zero, L_800AB45C
    if (ctx->r15 != 0) {
        // 0x800AB040: nop
    
            goto L_800AB45C;
    }
    // 0x800AB040: nop

    // 0x800AB044: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800AB048: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AB04C: nop

    // 0x800AB050: add.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x800AB054: b           L_800AB45C
    // 0x800AB058: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
        goto L_800AB45C;
    // 0x800AB058: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
L_800AB05C:
    // 0x800AB05C: lb          $t9, 0x7295($t9)
    ctx->r25 = MEM_B(ctx->r25, 0X7295);
    // 0x800AB060: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x800AB064: beq         $t9, $zero, L_800AB108
    if (ctx->r25 == 0) {
        // 0x800AB068: lui         $at, 0x3FF0
        ctx->r1 = S32(0X3FF0 << 16);
            goto L_800AB108;
    }
    // 0x800AB068: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800AB06C: lw          $t8, 0x300($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X300);
    // 0x800AB070: nop

    // 0x800AB074: bne         $t8, $zero, L_800AB108
    if (ctx->r24 != 0) {
        // 0x800AB078: nop
    
            goto L_800AB108;
    }
    // 0x800AB078: nop

    // 0x800AB07C: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x800AB080: sll         $t5, $t0, 2
    ctx->r13 = S32(ctx->r8 << 2);
    // 0x800AB084: addu        $t4, $t3, $t5
    ctx->r12 = ADD32(ctx->r11, ctx->r13);
    // 0x800AB088: lw          $v0, 0x0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X0);
    // 0x800AB08C: lh          $t6, 0x18($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X18);
    // 0x800AB090: lh          $t7, 0x16($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X16);
    // 0x800AB094: sh          $zero, 0x74($sp)
    MEM_H(0X74, ctx->r29) = 0;
    // 0x800AB098: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AB09C: sh          $zero, 0x76($sp)
    MEM_H(0X76, ctx->r29) = 0;
    // 0x800AB0A0: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
    // 0x800AB0A4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800AB0A8: lwc1        $f19, -0x72A0($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X72A0);
    // 0x800AB0AC: lwc1        $f18, -0x729C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X729C);
    // 0x800AB0B0: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800AB0B4: lw          $t8, 0x2DB4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2DB4);
    // 0x800AB0B8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800AB0BC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800AB0C0: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800AB0C4: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x800AB0C8: mflo        $t9
    ctx->r25 = lo;
    // 0x800AB0CC: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x800AB0D0: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x800AB0D4: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800AB0D8: lw          $a3, 0x10($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X10);
    // 0x800AB0DC: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x800AB0E0: mul.d       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f18.d);
    // 0x800AB0E4: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x800AB0E8: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x800AB0EC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800AB0F0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800AB0F4: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x800AB0F8: jal         0x80079150
    // 0x800AB0FC: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    texrect_draw_scaled(rdram, ctx);
        goto after_7;
    // 0x800AB0FC: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_7:
    // 0x800AB100: b           L_800AB460
    // 0x800AB104: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
        goto L_800AB460;
    // 0x800AB104: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
L_800AB108:
    // 0x800AB108: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800AB10C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800AB110: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800AB114: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x800AB118: c.eq.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d == ctx->f6.d;
    // 0x800AB11C: nop

    // 0x800AB120: bc1f        L_800AB280
    if (!c1cs) {
        // 0x800AB124: nop
    
            goto L_800AB280;
    }
    // 0x800AB124: nop

    // 0x800AB128: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800AB12C: sll         $t4, $t0, 2
    ctx->r12 = S32(ctx->r8 << 2);
    // 0x800AB130: addu        $t6, $t5, $t4
    ctx->r14 = ADD32(ctx->r13, ctx->r12);
    // 0x800AB134: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    // 0x800AB138: lh          $t7, 0x18($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X18);
    // 0x800AB13C: lh          $t9, 0x16($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X16);
    // 0x800AB140: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800AB144: multu       $t7, $t9
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AB148: lw          $v0, 0x2DB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2DB4);
    // 0x800AB14C: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800AB150: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800AB154: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800AB158: addiu       $a1, $a1, 0x7740
    ctx->r5 = ADD32(ctx->r5, 0X7740);
    // 0x800AB15C: addiu       $t5, $t5, 0x7340
    ctx->r13 = ADD32(ctx->r13, 0X7340);
    // 0x800AB160: mflo        $t8
    ctx->r24 = lo;
    // 0x800AB164: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
    // 0x800AB168: bne         $v0, $at, L_800AB1D8
    if (ctx->r2 != ctx->r1) {
        // 0x800AB16C: nop
    
            goto L_800AB1D8;
    }
    // 0x800AB16C: nop

    // 0x800AB170: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800AB174: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800AB178: sll         $t3, $a0, 3
    ctx->r11 = S32(ctx->r4 << 3);
    // 0x800AB17C: addu        $v0, $t3, $t5
    ctx->r2 = ADD32(ctx->r11, ctx->r13);
    // 0x800AB180: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800AB184: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x800AB188: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AB18C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AB190: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800AB194: addiu       $t8, $a0, 0x1
    ctx->r24 = ADD32(ctx->r4, 0X1);
    // 0x800AB198: cvt.w.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800AB19C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800AB1A0: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x800AB1A4: nop

    // 0x800AB1A8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800AB1AC: sh          $t6, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r14;
    // 0x800AB1B0: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800AB1B4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AB1B8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AB1BC: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800AB1C0: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800AB1C4: cvt.w.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800AB1C8: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800AB1CC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800AB1D0: b           L_800AB45C
    // 0x800AB1D4: sh          $t9, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r25;
        goto L_800AB45C;
    // 0x800AB1D4: sh          $t9, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r25;
L_800AB1D8:
    // 0x800AB1D8: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800AB1DC: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    // 0x800AB1E0: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800AB1E4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AB1E8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AB1EC: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800AB1F0: srl         $t7, $v0, 24
    ctx->r15 = S32(U32(ctx->r2) >> 24);
    // 0x800AB1F4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800AB1F8: srl         $t8, $v0, 16
    ctx->r24 = S32(U32(ctx->r2) >> 16);
    // 0x800AB1FC: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800AB200: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x800AB204: andi        $t3, $t8, 0xFF
    ctx->r11 = ctx->r24 & 0XFF;
    // 0x800AB208: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800AB20C: sh          $t5, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r13;
    // 0x800AB210: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800AB214: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AB218: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AB21C: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800AB220: srl         $t5, $v0, 8
    ctx->r13 = S32(U32(ctx->r2) >> 8);
    // 0x800AB224: cvt.w.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800AB228: andi        $t9, $t7, 0xFF
    ctx->r25 = ctx->r15 & 0XFF;
    // 0x800AB22C: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x800AB230: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800AB234: sh          $t6, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r14;
    // 0x800AB238: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x800AB23C: andi        $t4, $t5, 0xFF
    ctx->r12 = ctx->r13 & 0XFF;
    // 0x800AB240: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800AB244: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x800AB248: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800AB24C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x800AB250: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800AB254: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800AB258: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800AB25C: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x800AB260: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800AB264: jal         0x80078F08
    // 0x800AB268: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    texrect_draw(rdram, ctx);
        goto after_8;
    // 0x800AB268: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_8:
    // 0x800AB26C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800AB270: jal         0x8007B820
    // 0x800AB274: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    rendermode_reset(rdram, ctx);
        goto after_9;
    // 0x800AB274: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    after_9:
    // 0x800AB278: b           L_800AB460
    // 0x800AB27C: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
        goto L_800AB460;
    // 0x800AB27C: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
L_800AB280:
    // 0x800AB280: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800AB284: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x800AB288: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800AB28C: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x800AB290: lh          $t3, 0x18($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X18);
    // 0x800AB294: lh          $t5, 0x16($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X16);
    // 0x800AB298: sh          $zero, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = 0;
    // 0x800AB29C: multu       $t3, $t5
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AB2A0: sh          $zero, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = 0;
    // 0x800AB2A4: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
    // 0x800AB2A8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800AB2AC: lw          $t6, 0x2DB4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2DB4);
    // 0x800AB2B0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800AB2B4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800AB2B8: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800AB2BC: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x800AB2C0: mflo        $t4
    ctx->r12 = lo;
    // 0x800AB2C4: addu        $v0, $v0, $t4
    ctx->r2 = ADD32(ctx->r2, ctx->r12);
    // 0x800AB2C8: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x800AB2CC: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800AB2D0: lw          $a3, 0x10($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X10);
    // 0x800AB2D4: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x800AB2D8: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800AB2DC: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x800AB2E0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800AB2E4: jal         0x80079150
    // 0x800AB2E8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    texrect_draw_scaled(rdram, ctx);
        goto after_10;
    // 0x800AB2E8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_10:
    // 0x800AB2EC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800AB2F0: jal         0x8007B820
    // 0x800AB2F4: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    rendermode_reset(rdram, ctx);
        goto after_11;
    // 0x800AB2F4: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    after_11:
    // 0x800AB2F8: b           L_800AB460
    // 0x800AB2FC: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
        goto L_800AB460;
    // 0x800AB2FC: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
L_800AB300:
    // 0x800AB300: beq         $t9, $zero, L_800AB384
    if (ctx->r25 == 0) {
        // 0x800AB304: andi        $t6, $v0, 0x4000
        ctx->r14 = ctx->r2 & 0X4000;
            goto L_800AB384;
    }
    // 0x800AB304: andi        $t6, $v0, 0x4000
    ctx->r14 = ctx->r2 & 0X4000;
    // 0x800AB308: jal         0x80069F60
    // 0x800AB30C: nop

    cam_get_active_camera(rdram, ctx);
        goto after_12;
    // 0x800AB30C: nop

    after_12:
    // 0x800AB310: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800AB314: sw          $v0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r2;
    // 0x800AB318: lh          $t3, 0x6($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X6);
    // 0x800AB31C: addiu       $t1, $t1, 0x72B4
    ctx->r9 = ADD32(ctx->r9, 0X72B4);
    // 0x800AB320: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800AB324: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x800AB328: lh          $t6, 0x4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4);
    // 0x800AB32C: lh          $t7, 0x4($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X4);
    // 0x800AB330: addu        $t4, $t8, $t5
    ctx->r12 = ADD32(ctx->r24, ctx->r13);
    // 0x800AB334: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    // 0x800AB338: subu        $t9, $t6, $t7
    ctx->r25 = SUB32(ctx->r14, ctx->r15);
    // 0x800AB33C: sh          $t9, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r25;
    // 0x800AB340: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800AB344: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800AB348: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800AB34C: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800AB350: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800AB354: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800AB358: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800AB35C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x800AB360: jal         0x80068E34
    // 0x800AB364: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    render_ortho_triangle_image(rdram, ctx);
        goto after_13;
    // 0x800AB364: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    after_13:
    // 0x800AB368: lw          $t8, 0xA8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA8);
    // 0x800AB36C: lh          $t3, 0x4($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X4);
    // 0x800AB370: lh          $t5, 0x4($t8)
    ctx->r13 = MEM_H(ctx->r24, 0X4);
    // 0x800AB374: nop

    // 0x800AB378: addu        $t4, $t3, $t5
    ctx->r12 = ADD32(ctx->r11, ctx->r13);
    // 0x800AB37C: b           L_800AB45C
    // 0x800AB380: sh          $t4, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r12;
        goto L_800AB45C;
    // 0x800AB380: sh          $t4, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r12;
L_800AB384:
    // 0x800AB384: beq         $t6, $zero, L_800AB404
    if (ctx->r14 == 0) {
        // 0x800AB388: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800AB404;
    }
    // 0x800AB388: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800AB38C: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800AB390: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x800AB394: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800AB398: lw          $a3, 0x0($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X0);
    // 0x800AB39C: lh          $t3, 0x0($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X0);
    // 0x800AB3A0: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800AB3A4: sh          $t3, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r11;
    // 0x800AB3A8: lh          $t5, 0x2($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X2);
    // 0x800AB3AC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800AB3B0: sh          $t5, 0x2($a3)
    MEM_H(0X2, ctx->r7) = ctx->r13;
    // 0x800AB3B4: lh          $t4, 0x4($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X4);
    // 0x800AB3B8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800AB3BC: sh          $t4, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r12;
    // 0x800AB3C0: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800AB3C4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800AB3C8: swc1        $f16, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f16.u32l;
    // 0x800AB3CC: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800AB3D0: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800AB3D4: swc1        $f10, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f10.u32l;
    // 0x800AB3D8: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800AB3DC: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800AB3E0: swc1        $f4, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f4.u32l;
    // 0x800AB3E4: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800AB3E8: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800AB3EC: sb          $zero, 0x3A($a3)
    MEM_B(0X3A, ctx->r7) = 0;
    // 0x800AB3F0: sb          $t6, 0x39($a3)
    MEM_B(0X39, ctx->r7) = ctx->r14;
    // 0x800AB3F4: jal         0x80012D5C
    // 0x800AB3F8: swc1        $f6, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f6.u32l;
    render_object(rdram, ctx);
        goto after_14;
    // 0x800AB3F8: swc1        $f6, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f6.u32l;
    after_14:
    // 0x800AB3FC: b           L_800AB460
    // 0x800AB400: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
        goto L_800AB460;
    // 0x800AB400: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
L_800AB404:
    // 0x800AB404: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800AB408: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800AB40C: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800AB410: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800AB414: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800AB418: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x800AB41C: jal         0x800696C4
    // 0x800AB420: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    mtx_cam_push(rdram, ctx);
        goto after_15;
    // 0x800AB420: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_15:
    // 0x800AB424: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800AB428: lh          $t9, 0x6($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X6);
    // 0x800AB42C: addiu       $t1, $t1, 0x72B4
    ctx->r9 = ADD32(ctx->r9, 0X72B4);
    // 0x800AB430: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800AB434: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x800AB438: addu        $t3, $t7, $t8
    ctx->r11 = ADD32(ctx->r15, ctx->r24);
    // 0x800AB43C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x800AB440: nop

    // 0x800AB444: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800AB448: jal         0x800AB52C
    // 0x800AB44C: nop

    hud_draw_model(rdram, ctx);
        goto after_16;
    // 0x800AB44C: nop

    after_16:
    // 0x800AB450: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800AB454: jal         0x80069C80
    // 0x800AB458: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    mtx_pop(rdram, ctx);
        goto after_17;
    // 0x800AB458: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    after_17:
L_800AB45C:
    // 0x800AB45C: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
L_800AB460:
    // 0x800AB460: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x800AB464: beq         $t0, $at, L_800AB4EC
    if (ctx->r8 == ctx->r1) {
        // 0x800AB468: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_800AB4EC;
    }
    // 0x800AB468: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800AB46C: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x800AB470: beq         $t0, $at, L_800AB4C4
    if (ctx->r8 == ctx->r1) {
        // 0x800AB474: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_800AB4C4;
    }
    // 0x800AB474: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800AB478: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x800AB47C: beq         $t0, $at, L_800AB4C4
    if (ctx->r8 == ctx->r1) {
        // 0x800AB480: slti        $at, $t0, 0x2F
        ctx->r1 = SIGNED(ctx->r8) < 0X2F ? 1 : 0;
            goto L_800AB4C4;
    }
    // 0x800AB480: slti        $at, $t0, 0x2F
    ctx->r1 = SIGNED(ctx->r8) < 0X2F ? 1 : 0;
    // 0x800AB484: bne         $at, $zero, L_800AB490
    if (ctx->r1 != 0) {
        // 0x800AB488: slti        $at, $t0, 0x36
        ctx->r1 = SIGNED(ctx->r8) < 0X36 ? 1 : 0;
            goto L_800AB490;
    }
    // 0x800AB488: slti        $at, $t0, 0x36
    ctx->r1 = SIGNED(ctx->r8) < 0X36 ? 1 : 0;
    // 0x800AB48C: bne         $at, $zero, L_800AB4C4
    if (ctx->r1 != 0) {
        // 0x800AB490: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_800AB4C4;
    }
L_800AB490:
    // 0x800AB490: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x800AB494: beq         $t0, $at, L_800AB4C4
    if (ctx->r8 == ctx->r1) {
        // 0x800AB498: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_800AB4C4;
    }
    // 0x800AB498: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800AB49C: lb          $t5, 0x7293($t5)
    ctx->r13 = MEM_B(ctx->r13, 0X7293);
    // 0x800AB4A0: lw          $t6, 0xA4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA4);
    // 0x800AB4A4: andi        $t4, $t5, 0x1
    ctx->r12 = ctx->r13 & 0X1;
    // 0x800AB4A8: beq         $t4, $zero, L_800AB4C4
    if (ctx->r12 == 0) {
        // 0x800AB4AC: nop
    
            goto L_800AB4C4;
    }
    // 0x800AB4AC: nop

    // 0x800AB4B0: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x800AB4B4: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800AB4B8: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800AB4BC: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800AB4C0: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
L_800AB4C4:
    // 0x800AB4C4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800AB4C8: lw          $t7, 0x72E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X72E8);
    // 0x800AB4CC: lw          $t9, 0x72E4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X72E4);
    // 0x800AB4D0: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800AB4D4: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x800AB4D8: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x800AB4DC: nop

    // 0x800AB4E0: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800AB4E4: sub.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800AB4E8: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
L_800AB4EC:
    // 0x800AB4EC: lw          $t3, 0x72BC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X72BC);
    // 0x800AB4F0: lw          $t5, 0xB8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB8);
    // 0x800AB4F4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800AB4F8: sw          $t3, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r11;
    // 0x800AB4FC: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
    // 0x800AB500: lw          $t4, 0x72C0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X72C0);
    // 0x800AB504: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800AB508: sw          $t4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r12;
    // 0x800AB50C: lw          $t7, 0xC0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC0);
    // 0x800AB510: lw          $t9, 0x72C4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X72C4);
    // 0x800AB514: nop

    // 0x800AB518: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
L_800AB51C:
    // 0x800AB51C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800AB520: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800AB524: jr          $ra
    // 0x800AB528: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x800AB528: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void hud_draw_model(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AB52C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800AB530: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800AB534: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800AB538: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800AB53C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800AB540: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800AB544: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800AB548: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800AB54C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800AB550: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800AB554: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800AB558: lh          $a1, 0x28($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X28);
    // 0x800AB55C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800AB560: blez        $a1, L_800AB6C0
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800AB564: or          $s7, $zero, $zero
        ctx->r23 = 0 | 0;
            goto L_800AB6C0;
    }
    // 0x800AB564: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x800AB568: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800AB56C: addiu       $s2, $s2, 0x72BC
    ctx->r18 = ADD32(ctx->r18, 0X72BC);
    // 0x800AB570: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
L_800AB574:
    // 0x800AB574: lw          $t6, 0x38($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X38);
    // 0x800AB578: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x800AB57C: addu        $v0, $t6, $fp
    ctx->r2 = ADD32(ctx->r14, ctx->r30);
    // 0x800AB580: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x800AB584: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800AB588: andi        $t7, $a3, 0x100
    ctx->r15 = ctx->r7 & 0X100;
    // 0x800AB58C: bne         $t7, $zero, L_800AB6B0
    if (ctx->r15 != 0) {
        // 0x800AB590: nop
    
            goto L_800AB6B0;
    }
    // 0x800AB590: nop

    // 0x800AB594: lh          $v1, 0x2($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X2);
    // 0x800AB598: lh          $a0, 0x4($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X4);
    // 0x800AB59C: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x800AB5A0: lh          $t8, 0xE($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XE);
    // 0x800AB5A4: lh          $t9, 0x10($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X10);
    // 0x800AB5A8: lw          $t2, 0x4($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X4);
    // 0x800AB5AC: lw          $t4, 0x8($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X8);
    // 0x800AB5B0: lbu         $a1, 0x0($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X0);
    // 0x800AB5B4: addu        $t3, $t3, $v1
    ctx->r11 = ADD32(ctx->r11, ctx->r3);
    // 0x800AB5B8: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x800AB5BC: sll         $t5, $a0, 4
    ctx->r13 = S32(ctx->r4 << 4);
    // 0x800AB5C0: subu        $s0, $t8, $v1
    ctx->r16 = SUB32(ctx->r24, ctx->r3);
    // 0x800AB5C4: subu        $s4, $t9, $a0
    ctx->r20 = SUB32(ctx->r25, ctx->r4);
    // 0x800AB5C8: addu        $s5, $t2, $t3
    ctx->r21 = ADD32(ctx->r10, ctx->r11);
    // 0x800AB5CC: bne         $a1, $at, L_800AB5DC
    if (ctx->r5 != ctx->r1) {
        // 0x800AB5D0: addu        $t0, $t4, $t5
        ctx->r8 = ADD32(ctx->r12, ctx->r13);
            goto L_800AB5DC;
    }
    // 0x800AB5D0: addu        $t0, $t4, $t5
    ctx->r8 = ADD32(ctx->r12, ctx->r13);
    // 0x800AB5D4: b           L_800AB5F0
    // 0x800AB5D8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
        goto L_800AB5F0;
    // 0x800AB5D8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800AB5DC:
    // 0x800AB5DC: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x800AB5E0: sll         $t7, $a1, 3
    ctx->r15 = S32(ctx->r5 << 3);
    // 0x800AB5E4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800AB5E8: lw          $s1, 0x0($t8)
    ctx->r17 = MEM_W(ctx->r24, 0X0);
    // 0x800AB5EC: nop

L_800AB5F0:
    // 0x800AB5F0: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800AB5F4: and         $a2, $a3, $at
    ctx->r6 = ctx->r7 & ctx->r1;
    // 0x800AB5F8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800AB5FC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800AB600: jal         0x8007B918
    // 0x800AB604: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    material_set_no_tex_offset(rdram, ctx);
        goto after_0;
    // 0x800AB604: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    after_0:
    // 0x800AB608: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x800AB60C: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x800AB610: addu        $a0, $s5, $t1
    ctx->r4 = ADD32(ctx->r21, ctx->r9);
    // 0x800AB614: addiu       $t2, $s0, -0x1
    ctx->r10 = ADD32(ctx->r16, -0X1);
    // 0x800AB618: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800AB61C: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x800AB620: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x800AB624: andi        $t4, $a0, 0x6
    ctx->r12 = ctx->r4 & 0X6;
    // 0x800AB628: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x800AB62C: sll         $t9, $s0, 3
    ctx->r25 = S32(ctx->r16 << 3);
    // 0x800AB630: addu        $t2, $t9, $s0
    ctx->r10 = ADD32(ctx->r25, ctx->r16);
    // 0x800AB634: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x800AB638: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x800AB63C: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x800AB640: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800AB644: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x800AB648: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x800AB64C: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800AB650: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x800AB654: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x800AB658: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800AB65C: bne         $s1, $zero, L_800AB668
    if (ctx->r17 != 0) {
        // 0x800AB660: sw          $a0, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->r4;
            goto L_800AB668;
    }
    // 0x800AB660: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x800AB664: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
L_800AB668:
    // 0x800AB668: addiu       $t9, $s4, -0x1
    ctx->r25 = ADD32(ctx->r20, -0X1);
    // 0x800AB66C: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x800AB670: sll         $t2, $t9, 4
    ctx->r10 = S32(ctx->r25 << 4);
    // 0x800AB674: or          $t3, $t2, $s6
    ctx->r11 = ctx->r10 | ctx->r22;
    // 0x800AB678: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x800AB67C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800AB680: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x800AB684: sll         $t8, $t4, 16
    ctx->r24 = S32(ctx->r12 << 16);
    // 0x800AB688: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x800AB68C: sll         $t6, $s4, 4
    ctx->r14 = S32(ctx->r20 << 4);
    // 0x800AB690: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x800AB694: or          $t5, $t8, $at
    ctx->r13 = ctx->r24 | ctx->r1;
    // 0x800AB698: or          $t9, $t5, $t7
    ctx->r25 = ctx->r13 | ctx->r15;
    // 0x800AB69C: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800AB6A0: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x800AB6A4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800AB6A8: lh          $a1, 0x28($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X28);
    // 0x800AB6AC: nop

L_800AB6B0:
    // 0x800AB6B0: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x800AB6B4: slt         $at, $s7, $a1
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800AB6B8: bne         $at, $zero, L_800AB574
    if (ctx->r1 != 0) {
        // 0x800AB6BC: addiu       $fp, $fp, 0xC
        ctx->r30 = ADD32(ctx->r30, 0XC);
            goto L_800AB574;
    }
    // 0x800AB6BC: addiu       $fp, $fp, 0xC
    ctx->r30 = ADD32(ctx->r30, 0XC);
L_800AB6C0:
    // 0x800AB6C0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800AB6C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800AB6C8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800AB6CC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800AB6D0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800AB6D4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800AB6D8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800AB6DC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800AB6E0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800AB6E4: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800AB6E8: jr          $ra
    // 0x800AB6EC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800AB6EC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void minimap_fade(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AB6F0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800AB6F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AB6F8: sb          $t6, 0x7291($at)
    MEM_B(0X7291, ctx->r1) = ctx->r14;
    // 0x800AB6FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AB700: jr          $ra
    // 0x800AB704: sb          $a0, 0x7293($at)
    MEM_B(0X7293, ctx->r1) = ctx->r4;
    return;
    // 0x800AB704: sb          $a0, 0x7293($at)
    MEM_B(0X7293, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void minimap_opacity_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AB708: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800AB70C: lbu         $t6, 0x774B($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X774B);
    // 0x800AB710: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AB714: sb          $t6, 0x7290($at)
    MEM_B(0X7290, ctx->r1) = ctx->r14;
    // 0x800AB718: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AB71C: jr          $ra
    // 0x800AB720: sb          $a0, 0x7293($at)
    MEM_B(0X7293, ctx->r1) = ctx->r4;
    return;
    // 0x800AB720: sb          $a0, 0x7293($at)
    MEM_B(0X7293, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void hud_reset_race_start(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AB724: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AB728: jr          $ra
    // 0x800AB72C: sb          $zero, 0x7294($at)
    MEM_B(0X7294, ctx->r1) = 0;
    return;
    // 0x800AB72C: sb          $zero, 0x7294($at)
    MEM_B(0X7294, ctx->r1) = 0;
;}
RECOMP_FUNC void hud_visibility(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AB730: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800AB734: subu        $t8, $t7, $a0
    ctx->r24 = SUB32(ctx->r15, ctx->r4);
    // 0x800AB738: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AB73C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800AB740: jr          $ra
    // 0x800AB744: sb          $t8, 0x7292($at)
    MEM_B(0X7292, ctx->r1) = ctx->r24;
    return;
    // 0x800AB744: sb          $t8, 0x7292($at)
    MEM_B(0X7292, ctx->r1) = ctx->r24;
    // 0x800AB748: nop

    // 0x800AB74C: nop

;}
RECOMP_FUNC void weather_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AB750: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AB754: addiu       $v1, $v1, 0x2E68
    ctx->r3 = ADD32(ctx->r3, 0X2E68);
    // 0x800AB758: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800AB75C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800AB760: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AB764: sw          $zero, 0x2E64($at)
    MEM_W(0X2E64, ctx->r1) = 0;
    // 0x800AB768: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800AB76C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800AB770: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x800AB774: addiu       $v0, $v0, -0x7E40
    ctx->r2 = ADD32(ctx->r2, -0X7E40);
    // 0x800AB778: sw          $zero, -0x7E90($at)
    MEM_W(-0X7E90, ctx->r1) = 0;
    // 0x800AB77C: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x800AB780: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800AB784: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800AB788: sra         $t0, $t8, 1
    ctx->r8 = S32(SIGNED(ctx->r24) >> 1);
    // 0x800AB78C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800AB790: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AB794: sw          $t0, -0x7E3C($at)
    MEM_W(-0X7E3C, ctx->r1) = ctx->r8;
    // 0x800AB798: addiu       $a0, $a0, 0x2EA4
    ctx->r4 = ADD32(ctx->r4, 0X2EA4);
    // 0x800AB79C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800AB7A0: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800AB7A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AB7A8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800AB7AC: sw          $zero, 0x2E9C($at)
    MEM_W(0X2E9C, ctx->r1) = 0;
    // 0x800AB7B0: addiu       $a1, $a1, -0x7E48
    ctx->r5 = ADD32(ctx->r5, -0X7E48);
    // 0x800AB7B4: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x800AB7B8: addiu       $t1, $zero, -0x200
    ctx->r9 = ADD32(0, -0X200);
    // 0x800AB7BC: sh          $a2, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r6;
    // 0x800AB7C0: sh          $t1, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r9;
    // 0x800AB7C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AB7C8: sw          $zero, 0x3010($at)
    MEM_W(0X3010, ctx->r1) = 0;
    // 0x800AB7CC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AB7D0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800AB7D4: sw          $t2, 0x3014($at)
    MEM_W(0X3014, ctx->r1) = ctx->r10;
    // 0x800AB7D8: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800AB7DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AB7E0: addiu       $a3, $a3, 0x2EAC
    ctx->r7 = ADD32(ctx->r7, 0X2EAC);
    // 0x800AB7E4: sw          $zero, 0x3018($at)
    MEM_W(0X3018, ctx->r1) = 0;
    // 0x800AB7E8: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x800AB7EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AB7F0: bne         $t3, $zero, L_800AB854
    if (ctx->r11 != 0) {
        // 0x800AB7F4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800AB854;
    }
    // 0x800AB7F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AB7F8: jal         0x80076EE4
    // 0x800AB7FC: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    asset_table_load(rdram, ctx);
        goto after_0;
    // 0x800AB7FC: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    after_0:
    // 0x800AB800: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AB804: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800AB808: addiu       $a3, $a3, 0x2EAC
    ctx->r7 = ADD32(ctx->r7, 0X2EAC);
    // 0x800AB80C: addiu       $a0, $a0, 0x2EB0
    ctx->r4 = ADD32(ctx->r4, 0X2EB0);
    // 0x800AB810: sll         $t4, $zero, 2
    ctx->r12 = S32(0 << 2);
    // 0x800AB814: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x800AB818: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800AB81C: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x800AB820: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800AB824: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x800AB828: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800AB82C: beq         $a2, $t6, L_800AB854
    if (ctx->r6 == ctx->r14) {
        // 0x800AB830: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800AB854;
    }
    // 0x800AB830: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800AB834: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
L_800AB838:
    // 0x800AB838: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800AB83C: addu        $t9, $a1, $t8
    ctx->r25 = ADD32(ctx->r5, ctx->r24);
    // 0x800AB840: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800AB844: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800AB848: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x800AB84C: bne         $a2, $t0, L_800AB838
    if (ctx->r6 != ctx->r8) {
        // 0x800AB850: addiu       $t7, $v1, 0x1
        ctx->r15 = ADD32(ctx->r3, 0X1);
            goto L_800AB838;
    }
    // 0x800AB850: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
L_800AB854:
    // 0x800AB854: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AB858: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800AB85C: sw          $zero, -0x7E38($at)
    MEM_W(-0X7E38, ctx->r1) = 0;
    // 0x800AB860: jr          $ra
    // 0x800AB864: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800AB864: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void weather_clip_planes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AB868: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800AB86C: addiu       $v0, $v0, -0x7E48
    ctx->r2 = ADD32(ctx->r2, -0X7E48);
    // 0x800AB870: lh          $t0, 0x2($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X2);
    // 0x800AB874: lh          $t1, 0x0($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X0);
    // 0x800AB878: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x800AB87C: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x800AB880: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800AB884: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800AB888: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800AB88C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800AB890: slt         $at, $t0, $t1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800AB894: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x800AB898: beq         $at, $zero, L_800AB8AC
    if (ctx->r1 == 0) {
        // 0x800AB89C: or          $a0, $t7, $zero
        ctx->r4 = ctx->r15 | 0;
            goto L_800AB8AC;
    }
    // 0x800AB89C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800AB8A0: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x800AB8A4: jr          $ra
    // 0x800AB8A8: sh          $t9, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r25;
    return;
    // 0x800AB8A8: sh          $t9, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r25;
L_800AB8AC:
    // 0x800AB8AC: sh          $a1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r5;
    // 0x800AB8B0: sh          $a0, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r4;
    // 0x800AB8B4: jr          $ra
    // 0x800AB8B8: nop

    return;
    // 0x800AB8B8: nop

;}
RECOMP_FUNC void weather_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AB8BC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AB8C0: lw          $a0, 0x2E9C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2E9C);
    // 0x800AB8C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AB8C8: beq         $a0, $zero, L_800AB8E0
    if (ctx->r4 == 0) {
        // 0x800AB8CC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800AB8E0;
    }
    // 0x800AB8CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AB8D0: jal         0x80071380
    // 0x800AB8D4: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x800AB8D4: nop

    after_0:
    // 0x800AB8D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AB8DC: sw          $zero, 0x2E9C($at)
    MEM_W(0X2E9C, ctx->r1) = 0;
L_800AB8E0:
    // 0x800AB8E0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800AB8E4: addiu       $v0, $v0, 0x2EA4
    ctx->r2 = ADD32(ctx->r2, 0X2EA4);
    // 0x800AB8E8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800AB8EC: nop

    // 0x800AB8F0: beq         $a0, $zero, L_800AB90C
    if (ctx->r4 == 0) {
        // 0x800AB8F4: nop
    
            goto L_800AB90C;
    }
    // 0x800AB8F4: nop

    // 0x800AB8F8: jal         0x80071380
    // 0x800AB8FC: nop

    mempool_free(rdram, ctx);
        goto after_1;
    // 0x800AB8FC: nop

    after_1:
    // 0x800AB900: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800AB904: addiu       $v0, $v0, 0x2EA4
    ctx->r2 = ADD32(ctx->r2, 0X2EA4);
    // 0x800AB908: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_800AB90C:
    // 0x800AB90C: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x800AB910: nop

    // 0x800AB914: beq         $a0, $zero, L_800AB930
    if (ctx->r4 == 0) {
        // 0x800AB918: nop
    
            goto L_800AB930;
    }
    // 0x800AB918: nop

    // 0x800AB91C: jal         0x80071380
    // 0x800AB920: nop

    mempool_free(rdram, ctx);
        goto after_2;
    // 0x800AB920: nop

    after_2:
    // 0x800AB924: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800AB928: addiu       $v0, $v0, 0x2EA4
    ctx->r2 = ADD32(ctx->r2, 0X2EA4);
    // 0x800AB92C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
L_800AB930:
    // 0x800AB930: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AB934: lw          $a0, 0x2E64($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2E64);
    // 0x800AB938: nop

    // 0x800AB93C: beq         $a0, $zero, L_800AB954
    if (ctx->r4 == 0) {
        // 0x800AB940: nop
    
            goto L_800AB954;
    }
    // 0x800AB940: nop

    // 0x800AB944: jal         0x80071380
    // 0x800AB948: nop

    mempool_free(rdram, ctx);
        goto after_3;
    // 0x800AB948: nop

    after_3:
    // 0x800AB94C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AB950: sw          $zero, 0x2E64($at)
    MEM_W(0X2E64, ctx->r1) = 0;
L_800AB954:
    // 0x800AB954: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800AB958: addiu       $v0, $v0, 0x2E68
    ctx->r2 = ADD32(ctx->r2, 0X2E68);
    // 0x800AB95C: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800AB960: nop

    // 0x800AB964: beq         $a0, $zero, L_800AB980
    if (ctx->r4 == 0) {
        // 0x800AB968: nop
    
            goto L_800AB980;
    }
    // 0x800AB968: nop

    // 0x800AB96C: jal         0x80071380
    // 0x800AB970: nop

    mempool_free(rdram, ctx);
        goto after_4;
    // 0x800AB970: nop

    after_4:
    // 0x800AB974: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800AB978: addiu       $v0, $v0, 0x2E68
    ctx->r2 = ADD32(ctx->r2, 0X2E68);
    // 0x800AB97C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_800AB980:
    // 0x800AB980: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    // 0x800AB984: nop

    // 0x800AB988: beq         $a0, $zero, L_800AB9A4
    if (ctx->r4 == 0) {
        // 0x800AB98C: nop
    
            goto L_800AB9A4;
    }
    // 0x800AB98C: nop

    // 0x800AB990: jal         0x8007B70C
    // 0x800AB994: nop

    tex_free(rdram, ctx);
        goto after_5;
    // 0x800AB994: nop

    after_5:
    // 0x800AB998: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800AB99C: addiu       $v0, $v0, 0x2E68
    ctx->r2 = ADD32(ctx->r2, 0X2E68);
    // 0x800AB9A0: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
L_800AB9A4:
    // 0x800AB9A4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AB9A8: lw          $a0, 0x2EA0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2EA0);
    // 0x800AB9AC: nop

    // 0x800AB9B0: beq         $a0, $zero, L_800AB9C8
    if (ctx->r4 == 0) {
        // 0x800AB9B4: nop
    
            goto L_800AB9C8;
    }
    // 0x800AB9B4: nop

    // 0x800AB9B8: jal         0x80071380
    // 0x800AB9BC: nop

    mempool_free(rdram, ctx);
        goto after_6;
    // 0x800AB9BC: nop

    after_6:
    // 0x800AB9C0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AB9C4: sw          $zero, 0x2EA0($at)
    MEM_W(0X2EA0, ctx->r1) = 0;
L_800AB9C8:
    // 0x800AB9C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AB9CC: sw          $zero, 0x3018($at)
    MEM_W(0X3018, ctx->r1) = 0;
    // 0x800AB9D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AB9D4: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800AB9D8: lw          $t7, 0x31EC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X31EC);
    // 0x800AB9DC: sw          $zero, 0x3010($at)
    MEM_W(0X3010, ctx->r1) = 0;
    // 0x800AB9E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AB9E4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800AB9E8: beq         $t7, $zero, L_800AB9F8
    if (ctx->r15 == 0) {
        // 0x800AB9EC: sw          $t6, 0x3014($at)
        MEM_W(0X3014, ctx->r1) = ctx->r14;
            goto L_800AB9F8;
    }
    // 0x800AB9EC: sw          $t6, 0x3014($at)
    MEM_W(0X3014, ctx->r1) = ctx->r14;
    // 0x800AB9F0: jal         0x800AD780
    // 0x800AB9F4: nop

    free_rain_memory(rdram, ctx);
        goto after_7;
    // 0x800AB9F4: nop

    after_7:
L_800AB9F8:
    // 0x800AB9F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AB9FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800ABA00: jr          $ra
    // 0x800ABA04: nop

    return;
    // 0x800ABA04: nop

;}
RECOMP_FUNC void weather_reset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ABA08: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800ABA0C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800ABA10: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800ABA14: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800ABA18: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800ABA1C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800ABA20: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800ABA24: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800ABA28: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x800ABA2C: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x800ABA30: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800ABA34: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800ABA38: jal         0x800AB8BC
    // 0x800ABA3C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    weather_free(rdram, ctx);
        goto after_0;
    // 0x800ABA3C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    after_0:
    // 0x800ABA40: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800ABA44: addiu       $v0, $v0, -0x7E88
    ctx->r2 = ADD32(ctx->r2, -0X7E88);
    // 0x800ABA48: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x800ABA4C: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x800ABA50: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x800ABA54: slti        $at, $s1, 0x2
    ctx->r1 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
    // 0x800ABA58: sw          $s0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r16;
    // 0x800ABA5C: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x800ABA60: sw          $s0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r16;
    // 0x800ABA64: sw          $s2, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r18;
    // 0x800ABA68: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    // 0x800ABA6C: sw          $s2, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r18;
    // 0x800ABA70: sw          $zero, 0x28($v0)
    MEM_W(0X28, ctx->r2) = 0;
    // 0x800ABA74: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800ABA78: sw          $zero, 0x34($v0)
    MEM_W(0X34, ctx->r2) = 0;
    // 0x800ABA7C: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x800ABA80: sw          $v1, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r3;
    // 0x800ABA84: sw          $v1, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r3;
    // 0x800ABA88: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x800ABA8C: sw          $a2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r6;
    // 0x800ABA90: sw          $a3, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r7;
    // 0x800ABA94: bne         $at, $zero, L_800ABAA0
    if (ctx->r1 != 0) {
        // 0x800ABA98: sw          $a3, 0x38($v0)
        MEM_W(0X38, ctx->r2) = ctx->r7;
            goto L_800ABAA0;
    }
    // 0x800ABA98: sw          $a3, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r7;
    // 0x800ABA9C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_800ABAA0:
    // 0x800ABAA0: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x800ABAA4: subu        $t6, $t6, $s1
    ctx->r14 = SUB32(ctx->r14, ctx->r17);
    // 0x800ABAA8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800ABAAC: subu        $t6, $t6, $s1
    ctx->r14 = SUB32(ctx->r14, ctx->r17);
    // 0x800ABAB0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800ABAB4: addiu       $t7, $t7, 0x2DE0
    ctx->r15 = ADD32(ctx->r15, 0X2DE0);
    // 0x800ABAB8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800ABABC: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
    // 0x800ABAC0: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x800ABAC4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800ABAC8: bne         $t8, $at, L_800ABAE4
    if (ctx->r24 != ctx->r1) {
        // 0x800ABACC: lui         $s6, 0xFFAA
        ctx->r22 = S32(0XFFAA << 16);
            goto L_800ABAE4;
    }
    // 0x800ABACC: lui         $s6, 0xFFAA
    ctx->r22 = S32(0XFFAA << 16);
    // 0x800ABAD0: addiu       $a0, $a2, 0x1
    ctx->r4 = ADD32(ctx->r6, 0X1);
    // 0x800ABAD4: jal         0x800AD6A4
    // 0x800ABAD8: addiu       $a1, $a3, 0x1
    ctx->r5 = ADD32(ctx->r7, 0X1);
    rain_init(rdram, ctx);
        goto after_1;
    // 0x800ABAD8: addiu       $a1, $a3, 0x1
    ctx->r5 = ADD32(ctx->r7, 0X1);
    after_1:
    // 0x800ABADC: b           L_800AC070
    // 0x800ABAE0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_800AC070;
    // 0x800ABAE0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_800ABAE4:
    // 0x800ABAE4: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x800ABAE8: ori         $s6, $s6, 0x55FF
    ctx->r22 = ctx->r22 | 0X55FF;
    // 0x800ABAEC: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x800ABAF0: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x800ABAF4: sll         $a0, $t9, 2
    ctx->r4 = S32(ctx->r25 << 2);
    // 0x800ABAF8: jal         0x80070EDC
    // 0x800ABAFC: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_2;
    // 0x800ABAFC: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_2:
    // 0x800ABB00: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x800ABB04: addiu       $s5, $s5, 0x2E68
    ctx->r21 = ADD32(ctx->r21, 0X2E68);
    // 0x800ABB08: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x800ABB0C: lw          $t3, 0x10($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X10);
    // 0x800ABB10: lh          $t8, 0x24($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X24);
    // 0x800ABB14: lh          $t9, 0x26($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X26);
    // 0x800ABB18: lw          $t5, 0x18($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X18);
    // 0x800ABB1C: lw          $t2, 0xC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XC);
    // 0x800ABB20: lw          $t4, 0x14($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X14);
    // 0x800ABB24: sw          $t1, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->r9;
    // 0x800ABB28: sw          $t3, 0x10($s5)
    MEM_W(0X10, ctx->r21) = ctx->r11;
    // 0x800ABB2C: sh          $t8, 0x24($s5)
    MEM_H(0X24, ctx->r21) = ctx->r24;
    // 0x800ABB30: sh          $t9, 0x26($s5)
    MEM_H(0X26, ctx->r21) = ctx->r25;
    // 0x800ABB34: lh          $t1, 0x24($s5)
    ctx->r9 = MEM_H(ctx->r21, 0X24);
    // 0x800ABB38: lh          $t3, 0x26($s5)
    ctx->r11 = MEM_H(ctx->r21, 0X26);
    // 0x800ABB3C: sw          $t5, 0x18($s5)
    MEM_W(0X18, ctx->r21) = ctx->r13;
    // 0x800ABB40: lw          $t6, 0x1C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1C);
    // 0x800ABB44: lw          $t7, 0x20($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X20);
    // 0x800ABB48: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
    // 0x800ABB4C: sw          $t2, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r10;
    // 0x800ABB50: sw          $t4, 0x14($s5)
    MEM_W(0X14, ctx->r21) = ctx->r12;
    // 0x800ABB54: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x800ABB58: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x800ABB5C: sw          $v0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r2;
    // 0x800ABB60: sh          $t2, 0x28($s5)
    MEM_H(0X28, ctx->r21) = ctx->r10;
    // 0x800ABB64: sh          $t4, 0x2A($s5)
    MEM_H(0X2A, ctx->r21) = ctx->r12;
    // 0x800ABB68: sw          $t6, 0x1C($s5)
    MEM_W(0X1C, ctx->r21) = ctx->r14;
    // 0x800ABB6C: bne         $t5, $zero, L_800ABB7C
    if (ctx->r13 != 0) {
        // 0x800ABB70: sw          $t7, 0x20($s5)
        MEM_W(0X20, ctx->r21) = ctx->r15;
            goto L_800ABB7C;
    }
    // 0x800ABB70: sw          $t7, 0x20($s5)
    MEM_W(0X20, ctx->r21) = ctx->r15;
    // 0x800ABB74: jal         0x800AC094
    // 0x800ABB78: nop

    snow_init(rdram, ctx);
        goto after_3;
    // 0x800ABB78: nop

    after_3:
L_800ABB7C:
    // 0x800ABB7C: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800ABB80: addiu       $s3, $s3, -0x7E90
    ctx->r19 = ADD32(ctx->r19, -0X7E90);
    // 0x800ABB84: sw          $s4, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r20;
    // 0x800ABB88: sll         $a0, $s4, 1
    ctx->r4 = S32(ctx->r20 << 1);
    // 0x800ABB8C: jal         0x80070EDC
    // 0x800ABB90: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_4;
    // 0x800ABB90: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_4:
    // 0x800ABB94: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800ABB98: sw          $v0, 0x2EA0($at)
    MEM_W(0X2EA0, ctx->r1) = ctx->r2;
    // 0x800ABB9C: sll         $a0, $s4, 4
    ctx->r4 = S32(ctx->r20 << 4);
    // 0x800ABBA0: jal         0x80070EDC
    // 0x800ABBA4: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_5;
    // 0x800ABBA4: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_5:
    // 0x800ABBA8: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x800ABBAC: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800ABBB0: addiu       $s2, $s2, 0x2E64
    ctx->r18 = ADD32(ctx->r18, 0X2E64);
    // 0x800ABBB4: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // 0x800ABBB8: blez        $t6, L_800ABCB8
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800ABBBC: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_800ABCB8;
    }
    // 0x800ABBBC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800ABBC0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800ABBC4:
    // 0x800ABBC4: lw          $a1, 0x18($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X18);
    // 0x800ABBC8: jal         0x8006FB8C
    // 0x800ABBCC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    rand_range(rdram, ctx);
        goto after_6;
    // 0x800ABBCC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x800ABBD0: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800ABBD4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800ABBD8: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x800ABBDC: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    // 0x800ABBE0: lw          $a1, 0x1C($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X1C);
    // 0x800ABBE4: jal         0x8006FB8C
    // 0x800ABBE8: nop

    rand_range(rdram, ctx);
        goto after_7;
    // 0x800ABBE8: nop

    after_7:
    // 0x800ABBEC: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800ABBF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800ABBF4: addu        $t1, $t9, $s0
    ctx->r9 = ADD32(ctx->r25, ctx->r16);
    // 0x800ABBF8: sw          $v0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r2;
    // 0x800ABBFC: lw          $a1, 0x20($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X20);
    // 0x800ABC00: jal         0x8006FB8C
    // 0x800ABC04: nop

    rand_range(rdram, ctx);
        goto after_8;
    // 0x800ABC04: nop

    after_8:
    // 0x800ABC08: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x800ABC0C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800ABC10: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x800ABC14: sw          $v0, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r2;
    // 0x800ABC18: jal         0x8006FB8C
    // 0x800ABC1C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    rand_range(rdram, ctx);
        goto after_9;
    // 0x800ABC1C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_9:
    // 0x800ABC20: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800ABC24: addiu       $t4, $v0, 0x5
    ctx->r12 = ADD32(ctx->r2, 0X5);
    // 0x800ABC28: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800ABC2C: sllv        $t6, $t5, $t4
    ctx->r14 = S32(ctx->r13 << (ctx->r12 & 31));
    // 0x800ABC30: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x800ABC34: sb          $t6, 0xC($t8)
    MEM_B(0XC, ctx->r24) = ctx->r14;
    // 0x800ABC38: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800ABC3C: jal         0x8006FB8C
    // 0x800ABC40: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    rand_range(rdram, ctx);
        goto after_10;
    // 0x800ABC40: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_10:
    // 0x800ABC44: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x800ABC48: addiu       $t9, $v0, 0x5
    ctx->r25 = ADD32(ctx->r2, 0X5);
    // 0x800ABC4C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800ABC50: sllv        $t2, $t1, $t9
    ctx->r10 = S32(ctx->r9 << (ctx->r25 & 31));
    // 0x800ABC54: addu        $t5, $t3, $s0
    ctx->r13 = ADD32(ctx->r11, ctx->r16);
    // 0x800ABC58: sb          $t2, 0xD($t5)
    MEM_B(0XD, ctx->r13) = ctx->r10;
    // 0x800ABC5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800ABC60: jal         0x8006FB8C
    // 0x800ABC64: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    rand_range(rdram, ctx);
        goto after_11;
    // 0x800ABC64: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_11:
    // 0x800ABC68: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x800ABC6C: addiu       $t4, $v0, 0x5
    ctx->r12 = ADD32(ctx->r2, 0X5);
    // 0x800ABC70: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800ABC74: sllv        $t6, $t7, $t4
    ctx->r14 = S32(ctx->r15 << (ctx->r12 & 31));
    // 0x800ABC78: addu        $t1, $t8, $s0
    ctx->r9 = ADD32(ctx->r24, ctx->r16);
    // 0x800ABC7C: sb          $t6, 0xE($t1)
    MEM_B(0XE, ctx->r9) = ctx->r14;
    // 0x800ABC80: lw          $a1, 0x4($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X4);
    // 0x800ABC84: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800ABC88: jal         0x8006FB8C
    // 0x800ABC8C: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    rand_range(rdram, ctx);
        goto after_12;
    // 0x800ABC8C: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    after_12:
    // 0x800ABC90: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800ABC94: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800ABC98: addu        $t3, $t9, $s0
    ctx->r11 = ADD32(ctx->r25, ctx->r16);
    // 0x800ABC9C: sb          $v0, 0xF($t3)
    MEM_B(0XF, ctx->r11) = ctx->r2;
    // 0x800ABCA0: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x800ABCA4: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x800ABCA8: slt         $at, $s1, $t2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800ABCAC: bne         $at, $zero, L_800ABBC4
    if (ctx->r1 != 0) {
        // 0x800ABCB0: nop
    
            goto L_800ABBC4;
    }
    // 0x800ABCB0: nop

    // 0x800ABCB4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800ABCB8:
    // 0x800ABCB8: sll         $s0, $s4, 2
    ctx->r16 = S32(ctx->r20 << 2);
    // 0x800ABCBC: sll         $s2, $s0, 2
    ctx->r18 = S32(ctx->r16 << 2);
    // 0x800ABCC0: addu        $s2, $s2, $s0
    ctx->r18 = ADD32(ctx->r18, ctx->r16);
    // 0x800ABCC4: sll         $s2, $s2, 1
    ctx->r18 = S32(ctx->r18 << 1);
    // 0x800ABCC8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800ABCCC: jal         0x80070EDC
    // 0x800ABCD0: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_13;
    // 0x800ABCD0: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_13:
    // 0x800ABCD4: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x800ABCD8: addiu       $s3, $s3, 0x2EA4
    ctx->r19 = ADD32(ctx->r19, 0X2EA4);
    // 0x800ABCDC: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x800ABCE0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800ABCE4: jal         0x80070EDC
    // 0x800ABCE8: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_14;
    // 0x800ABCE8: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_14:
    // 0x800ABCEC: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800ABCF0: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800ABCF4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800ABCF8: sw          $v0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r2;
    // 0x800ABCFC: addiu       $v1, $v1, 0x2E94
    ctx->r3 = ADD32(ctx->r3, 0X2E94);
    // 0x800ABD00: addiu       $t0, $t0, 0x2EAC
    ctx->r8 = ADD32(ctx->r8, 0X2EAC);
    // 0x800ABD04: addiu       $a3, $a3, 0x2EA4
    ctx->r7 = ADD32(ctx->r7, 0X2EA4);
    // 0x800ABD08: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_800ABD0C:
    // 0x800ABD0C: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x800ABD10: blez        $s0, L_800ABEA0
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800ABD14: sw          $t5, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r13;
            goto L_800ABEA0;
    }
    // 0x800ABD14: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800ABD18: andi        $a2, $s0, 0x3
    ctx->r6 = ctx->r16 & 0X3;
    // 0x800ABD1C: beq         $a2, $zero, L_800ABD7C
    if (ctx->r6 == 0) {
        // 0x800ABD20: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_800ABD7C;
    }
    // 0x800ABD20: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800ABD24: sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17 << 2);
    // 0x800ABD28: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x800ABD2C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
L_800ABD30:
    // 0x800ABD30: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800ABD34: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800ABD38: addu        $t4, $t7, $v0
    ctx->r12 = ADD32(ctx->r15, ctx->r2);
    // 0x800ABD3C: sb          $a0, 0x6($t4)
    MEM_B(0X6, ctx->r12) = ctx->r4;
    // 0x800ABD40: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800ABD44: nop

    // 0x800ABD48: addu        $t6, $t8, $v0
    ctx->r14 = ADD32(ctx->r24, ctx->r2);
    // 0x800ABD4C: sb          $a0, 0x7($t6)
    MEM_B(0X7, ctx->r14) = ctx->r4;
    // 0x800ABD50: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x800ABD54: nop

    // 0x800ABD58: addu        $t9, $t1, $v0
    ctx->r25 = ADD32(ctx->r9, ctx->r2);
    // 0x800ABD5C: sb          $a0, 0x8($t9)
    MEM_B(0X8, ctx->r25) = ctx->r4;
    // 0x800ABD60: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800ABD64: nop

    // 0x800ABD68: addu        $t2, $t3, $v0
    ctx->r10 = ADD32(ctx->r11, ctx->r2);
    // 0x800ABD6C: sb          $a0, 0x9($t2)
    MEM_B(0X9, ctx->r10) = ctx->r4;
    // 0x800ABD70: bne         $a1, $s1, L_800ABD30
    if (ctx->r5 != ctx->r17) {
        // 0x800ABD74: addiu       $v0, $v0, 0xA
        ctx->r2 = ADD32(ctx->r2, 0XA);
            goto L_800ABD30;
    }
    // 0x800ABD74: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x800ABD78: beq         $s1, $s0, L_800ABE9C
    if (ctx->r17 == ctx->r16) {
        // 0x800ABD7C: sll         $v0, $s1, 2
        ctx->r2 = S32(ctx->r17 << 2);
            goto L_800ABE9C;
    }
L_800ABD7C:
    // 0x800ABD7C: sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17 << 2);
    // 0x800ABD80: sll         $a1, $s0, 2
    ctx->r5 = S32(ctx->r16 << 2);
    // 0x800ABD84: addu        $a1, $a1, $s0
    ctx->r5 = ADD32(ctx->r5, ctx->r16);
    // 0x800ABD88: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x800ABD8C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800ABD90: sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5 << 1);
L_800ABD94:
    // 0x800ABD94: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800ABD98: nop

    // 0x800ABD9C: addu        $t7, $t5, $v0
    ctx->r15 = ADD32(ctx->r13, ctx->r2);
    // 0x800ABDA0: sb          $a0, 0x6($t7)
    MEM_B(0X6, ctx->r15) = ctx->r4;
    // 0x800ABDA4: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800ABDA8: nop

    // 0x800ABDAC: addu        $t8, $t4, $v0
    ctx->r24 = ADD32(ctx->r12, ctx->r2);
    // 0x800ABDB0: sb          $a0, 0x7($t8)
    MEM_B(0X7, ctx->r24) = ctx->r4;
    // 0x800ABDB4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800ABDB8: nop

    // 0x800ABDBC: addu        $t1, $t6, $v0
    ctx->r9 = ADD32(ctx->r14, ctx->r2);
    // 0x800ABDC0: sb          $a0, 0x8($t1)
    MEM_B(0X8, ctx->r9) = ctx->r4;
    // 0x800ABDC4: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800ABDC8: nop

    // 0x800ABDCC: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x800ABDD0: sb          $a0, 0x9($t3)
    MEM_B(0X9, ctx->r11) = ctx->r4;
    // 0x800ABDD4: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x800ABDD8: nop

    // 0x800ABDDC: addu        $t5, $t2, $v0
    ctx->r13 = ADD32(ctx->r10, ctx->r2);
    // 0x800ABDE0: sb          $a0, 0x10($t5)
    MEM_B(0X10, ctx->r13) = ctx->r4;
    // 0x800ABDE4: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800ABDE8: nop

    // 0x800ABDEC: addu        $t4, $t7, $v0
    ctx->r12 = ADD32(ctx->r15, ctx->r2);
    // 0x800ABDF0: sb          $a0, 0x11($t4)
    MEM_B(0X11, ctx->r12) = ctx->r4;
    // 0x800ABDF4: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800ABDF8: nop

    // 0x800ABDFC: addu        $t6, $t8, $v0
    ctx->r14 = ADD32(ctx->r24, ctx->r2);
    // 0x800ABE00: sb          $a0, 0x12($t6)
    MEM_B(0X12, ctx->r14) = ctx->r4;
    // 0x800ABE04: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x800ABE08: nop

    // 0x800ABE0C: addu        $t9, $t1, $v0
    ctx->r25 = ADD32(ctx->r9, ctx->r2);
    // 0x800ABE10: sb          $a0, 0x13($t9)
    MEM_B(0X13, ctx->r25) = ctx->r4;
    // 0x800ABE14: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800ABE18: nop

    // 0x800ABE1C: addu        $t2, $t3, $v0
    ctx->r10 = ADD32(ctx->r11, ctx->r2);
    // 0x800ABE20: sb          $a0, 0x1A($t2)
    MEM_B(0X1A, ctx->r10) = ctx->r4;
    // 0x800ABE24: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800ABE28: nop

    // 0x800ABE2C: addu        $t7, $t5, $v0
    ctx->r15 = ADD32(ctx->r13, ctx->r2);
    // 0x800ABE30: sb          $a0, 0x1B($t7)
    MEM_B(0X1B, ctx->r15) = ctx->r4;
    // 0x800ABE34: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800ABE38: nop

    // 0x800ABE3C: addu        $t8, $t4, $v0
    ctx->r24 = ADD32(ctx->r12, ctx->r2);
    // 0x800ABE40: sb          $a0, 0x1C($t8)
    MEM_B(0X1C, ctx->r24) = ctx->r4;
    // 0x800ABE44: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800ABE48: nop

    // 0x800ABE4C: addu        $t1, $t6, $v0
    ctx->r9 = ADD32(ctx->r14, ctx->r2);
    // 0x800ABE50: sb          $a0, 0x1D($t1)
    MEM_B(0X1D, ctx->r9) = ctx->r4;
    // 0x800ABE54: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800ABE58: nop

    // 0x800ABE5C: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x800ABE60: sb          $a0, 0x24($t3)
    MEM_B(0X24, ctx->r11) = ctx->r4;
    // 0x800ABE64: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x800ABE68: nop

    // 0x800ABE6C: addu        $t5, $t2, $v0
    ctx->r13 = ADD32(ctx->r10, ctx->r2);
    // 0x800ABE70: sb          $a0, 0x25($t5)
    MEM_B(0X25, ctx->r13) = ctx->r4;
    // 0x800ABE74: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800ABE78: nop

    // 0x800ABE7C: addu        $t4, $t7, $v0
    ctx->r12 = ADD32(ctx->r15, ctx->r2);
    // 0x800ABE80: sb          $a0, 0x26($t4)
    MEM_B(0X26, ctx->r12) = ctx->r4;
    // 0x800ABE84: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800ABE88: nop

    // 0x800ABE8C: addu        $t6, $t8, $v0
    ctx->r14 = ADD32(ctx->r24, ctx->r2);
    // 0x800ABE90: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
    // 0x800ABE94: bne         $v0, $a1, L_800ABD94
    if (ctx->r2 != ctx->r5) {
        // 0x800ABE98: sb          $a0, 0x27($t6)
        MEM_B(0X27, ctx->r14) = ctx->r4;
            goto L_800ABD94;
    }
    // 0x800ABE98: sb          $a0, 0x27($t6)
    MEM_B(0X27, ctx->r14) = ctx->r4;
L_800ABE9C:
    // 0x800ABE9C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800ABEA0:
    // 0x800ABEA0: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800ABEA4: sltu        $at, $a3, $t0
    ctx->r1 = ctx->r7 < ctx->r8 ? 1 : 0;
    // 0x800ABEA8: bne         $at, $zero, L_800ABD0C
    if (ctx->r1 != 0) {
        // 0x800ABEAC: nop
    
            goto L_800ABD0C;
    }
    // 0x800ABEAC: nop

    // 0x800ABEB0: lw          $v0, 0x8($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X8);
    // 0x800ABEB4: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800ABEB8: lbu         $s2, 0x0($v0)
    ctx->r18 = MEM_BU(ctx->r2, 0X0);
    // 0x800ABEBC: lbu         $s3, 0x1($v0)
    ctx->r19 = MEM_BU(ctx->r2, 0X1);
    // 0x800ABEC0: addiu       $s4, $s4, -0x7E3C
    ctx->r20 = ADD32(ctx->r20, -0X7E3C);
    // 0x800ABEC4: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x800ABEC8: sll         $t1, $s2, 5
    ctx->r9 = S32(ctx->r18 << 5);
    // 0x800ABECC: sll         $t2, $s3, 5
    ctx->r10 = S32(ctx->r19 << 5);
    // 0x800ABED0: addiu       $s2, $t1, -0x1
    ctx->r18 = ADD32(ctx->r9, -0X1);
    // 0x800ABED4: addiu       $s3, $t2, -0x1
    ctx->r19 = ADD32(ctx->r10, -0X1);
    // 0x800ABED8: sll         $t9, $s2, 16
    ctx->r25 = S32(ctx->r18 << 16);
    // 0x800ABEDC: sll         $t5, $s3, 16
    ctx->r13 = S32(ctx->r19 << 16);
    // 0x800ABEE0: sll         $t4, $a0, 4
    ctx->r12 = S32(ctx->r4 << 4);
    // 0x800ABEE4: sra         $s2, $t9, 16
    ctx->r18 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800ABEE8: sra         $s3, $t5, 16
    ctx->r19 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800ABEEC: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800ABEF0: jal         0x80070EDC
    // 0x800ABEF4: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_15;
    // 0x800ABEF4: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_15:
    // 0x800ABEF8: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x800ABEFC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800ABF00: addiu       $v1, $v1, 0x2E9C
    ctx->r3 = ADD32(ctx->r3, 0X2E9C);
    // 0x800ABF04: blez        $t8, L_800AC064
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800ABF08: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_800AC064;
    }
    // 0x800ABF08: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800ABF0C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800ABF10:
    // 0x800ABF10: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800ABF14: sll         $a0, $s1, 1
    ctx->r4 = S32(ctx->r17 << 1);
    // 0x800ABF18: addu        $t1, $t6, $s0
    ctx->r9 = ADD32(ctx->r14, ctx->r16);
    // 0x800ABF1C: sb          $zero, 0x0($t1)
    MEM_B(0X0, ctx->r9) = 0;
    // 0x800ABF20: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800ABF24: addiu       $v0, $a0, 0x3
    ctx->r2 = ADD32(ctx->r4, 0X3);
    // 0x800ABF28: addu        $t3, $t9, $s0
    ctx->r11 = ADD32(ctx->r25, ctx->r16);
    // 0x800ABF2C: sb          $v0, 0x1($t3)
    MEM_B(0X1, ctx->r11) = ctx->r2;
    // 0x800ABF30: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x800ABF34: addiu       $a1, $a0, 0x1
    ctx->r5 = ADD32(ctx->r4, 0X1);
    // 0x800ABF38: addu        $t5, $t2, $s0
    ctx->r13 = ADD32(ctx->r10, ctx->r16);
    // 0x800ABF3C: sh          $zero, 0x4($t5)
    MEM_H(0X4, ctx->r13) = 0;
    // 0x800ABF40: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800ABF44: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800ABF48: addu        $t4, $t7, $s0
    ctx->r12 = ADD32(ctx->r15, ctx->r16);
    // 0x800ABF4C: sh          $s3, 0x6($t4)
    MEM_H(0X6, ctx->r12) = ctx->r19;
    // 0x800ABF50: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800ABF54: nop

    // 0x800ABF58: addu        $t6, $t8, $s0
    ctx->r14 = ADD32(ctx->r24, ctx->r16);
    // 0x800ABF5C: sb          $a1, 0x2($t6)
    MEM_B(0X2, ctx->r14) = ctx->r5;
    // 0x800ABF60: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x800ABF64: nop

    // 0x800ABF68: addu        $t9, $t1, $s0
    ctx->r25 = ADD32(ctx->r9, ctx->r16);
    // 0x800ABF6C: sh          $s2, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r18;
    // 0x800ABF70: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800ABF74: nop

    // 0x800ABF78: addu        $t2, $t3, $s0
    ctx->r10 = ADD32(ctx->r11, ctx->r16);
    // 0x800ABF7C: sh          $zero, 0xA($t2)
    MEM_H(0XA, ctx->r10) = 0;
    // 0x800ABF80: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800ABF84: nop

    // 0x800ABF88: addu        $t7, $t5, $s0
    ctx->r15 = ADD32(ctx->r13, ctx->r16);
    // 0x800ABF8C: sb          $a0, 0x3($t7)
    MEM_B(0X3, ctx->r15) = ctx->r4;
    // 0x800ABF90: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800ABF94: nop

    // 0x800ABF98: addu        $t8, $t4, $s0
    ctx->r24 = ADD32(ctx->r12, ctx->r16);
    // 0x800ABF9C: sh          $zero, 0xC($t8)
    MEM_H(0XC, ctx->r24) = 0;
    // 0x800ABFA0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800ABFA4: nop

    // 0x800ABFA8: addu        $t1, $t6, $s0
    ctx->r9 = ADD32(ctx->r14, ctx->r16);
    // 0x800ABFAC: sh          $zero, 0xE($t1)
    MEM_H(0XE, ctx->r9) = 0;
    // 0x800ABFB0: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800ABFB4: addiu       $t1, $a0, 0x2
    ctx->r9 = ADD32(ctx->r4, 0X2);
    // 0x800ABFB8: addu        $t3, $t9, $s0
    ctx->r11 = ADD32(ctx->r25, ctx->r16);
    // 0x800ABFBC: sb          $zero, 0x10($t3)
    MEM_B(0X10, ctx->r11) = 0;
    // 0x800ABFC0: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x800ABFC4: nop

    // 0x800ABFC8: addu        $t5, $t2, $s0
    ctx->r13 = ADD32(ctx->r10, ctx->r16);
    // 0x800ABFCC: sb          $v0, 0x11($t5)
    MEM_B(0X11, ctx->r13) = ctx->r2;
    // 0x800ABFD0: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800ABFD4: nop

    // 0x800ABFD8: addu        $t4, $t7, $s0
    ctx->r12 = ADD32(ctx->r15, ctx->r16);
    // 0x800ABFDC: sh          $zero, 0x14($t4)
    MEM_H(0X14, ctx->r12) = 0;
    // 0x800ABFE0: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800ABFE4: nop

    // 0x800ABFE8: addu        $t6, $t8, $s0
    ctx->r14 = ADD32(ctx->r24, ctx->r16);
    // 0x800ABFEC: sh          $s3, 0x16($t6)
    MEM_H(0X16, ctx->r14) = ctx->r19;
    // 0x800ABFF0: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800ABFF4: nop

    // 0x800ABFF8: addu        $t3, $t9, $s0
    ctx->r11 = ADD32(ctx->r25, ctx->r16);
    // 0x800ABFFC: sb          $t1, 0x12($t3)
    MEM_B(0X12, ctx->r11) = ctx->r9;
    // 0x800AC000: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x800AC004: nop

    // 0x800AC008: addu        $t5, $t2, $s0
    ctx->r13 = ADD32(ctx->r10, ctx->r16);
    // 0x800AC00C: sh          $s2, 0x18($t5)
    MEM_H(0X18, ctx->r13) = ctx->r18;
    // 0x800AC010: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800AC014: nop

    // 0x800AC018: addu        $t4, $t7, $s0
    ctx->r12 = ADD32(ctx->r15, ctx->r16);
    // 0x800AC01C: sh          $s3, 0x1A($t4)
    MEM_H(0X1A, ctx->r12) = ctx->r19;
    // 0x800AC020: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800AC024: nop

    // 0x800AC028: addu        $t6, $t8, $s0
    ctx->r14 = ADD32(ctx->r24, ctx->r16);
    // 0x800AC02C: sb          $a1, 0x13($t6)
    MEM_B(0X13, ctx->r14) = ctx->r5;
    // 0x800AC030: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800AC034: nop

    // 0x800AC038: addu        $t1, $t9, $s0
    ctx->r9 = ADD32(ctx->r25, ctx->r16);
    // 0x800AC03C: sh          $s2, 0x1C($t1)
    MEM_H(0X1C, ctx->r9) = ctx->r18;
    // 0x800AC040: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800AC044: nop

    // 0x800AC048: addu        $t2, $t3, $s0
    ctx->r10 = ADD32(ctx->r11, ctx->r16);
    // 0x800AC04C: sh          $zero, 0x1E($t2)
    MEM_H(0X1E, ctx->r10) = 0;
    // 0x800AC050: lw          $t5, 0x0($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X0);
    // 0x800AC054: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    // 0x800AC058: slt         $at, $s1, $t5
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800AC05C: bne         $at, $zero, L_800ABF10
    if (ctx->r1 != 0) {
        // 0x800AC060: nop
    
            goto L_800ABF10;
    }
    // 0x800AC060: nop

L_800AC064:
    // 0x800AC064: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800AC068: sw          $zero, -0x7E38($at)
    MEM_W(-0X7E38, ctx->r1) = 0;
    // 0x800AC06C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_800AC070:
    // 0x800AC070: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800AC074: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800AC078: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800AC07C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800AC080: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800AC084: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800AC088: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800AC08C: jr          $ra
    // 0x800AC090: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800AC090: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void snow_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC094: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800AC098: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800AC09C: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x800AC0A0: addiu       $s4, $s4, 0x2E68
    ctx->r20 = ADD32(ctx->r20, 0X2E68);
    // 0x800AC0A4: lw          $v0, 0x4($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X4);
    // 0x800AC0A8: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x800AC0AC: div         $zero, $t6, $v0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r2)));
    // 0x800AC0B0: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800AC0B4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800AC0B8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800AC0BC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800AC0C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800AC0C4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800AC0C8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800AC0CC: bne         $v0, $zero, L_800AC0D8
    if (ctx->r2 != 0) {
        // 0x800AC0D0: nop
    
            goto L_800AC0D8;
    }
    // 0x800AC0D0: nop

    // 0x800AC0D4: break       7
    do_break(2148188372);
L_800AC0D8:
    // 0x800AC0D8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AC0DC: bne         $v0, $at, L_800AC0F0
    if (ctx->r2 != ctx->r1) {
        // 0x800AC0E0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800AC0F0;
    }
    // 0x800AC0E0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AC0E4: bne         $t6, $at, L_800AC0F0
    if (ctx->r14 != ctx->r1) {
        // 0x800AC0E8: nop
    
            goto L_800AC0F0;
    }
    // 0x800AC0E8: nop

    // 0x800AC0EC: break       6
    do_break(2148188396);
L_800AC0F0:
    // 0x800AC0F0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800AC0F4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800AC0F8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800AC0FC: lui         $s6, 0xFFFC
    ctx->r22 = S32(0XFFFC << 16);
    // 0x800AC100: mflo        $s5
    ctx->r21 = lo;
    // 0x800AC104: blez        $v0, L_800AC178
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800AC108: or          $s3, $s1, $zero
        ctx->r19 = ctx->r17 | 0;
            goto L_800AC178;
    }
L_800AC108:
    // 0x800AC108: or          $s3, $s1, $zero
    ctx->r19 = ctx->r17 | 0;
    // 0x800AC10C: sll         $t7, $s3, 16
    ctx->r15 = S32(ctx->r19 << 16);
    // 0x800AC110: sra         $s3, $t7, 16
    ctx->r19 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800AC114: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x800AC118: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800AC11C: jal         0x80070A6C
    // 0x800AC120: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    coss_s16(rdram, ctx);
        goto after_0;
    // 0x800AC120: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_0:
    // 0x800AC124: lw          $t1, 0x0($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X0);
    // 0x800AC128: sll         $t0, $v0, 3
    ctx->r8 = S32(ctx->r2 << 3);
    // 0x800AC12C: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x800AC130: sw          $t0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r8;
    // 0x800AC134: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x800AC138: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x800AC13C: sra         $t5, $a0, 16
    ctx->r13 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800AC140: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x800AC144: sw          $s6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r22;
    // 0x800AC148: jal         0x80070A70
    // 0x800AC14C: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    sins_s16(rdram, ctx);
        goto after_1;
    // 0x800AC14C: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_1:
    // 0x800AC150: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x800AC154: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x800AC158: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x800AC15C: sw          $t6, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r14;
    // 0x800AC160: lw          $t9, 0x4($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X4);
    // 0x800AC164: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800AC168: slt         $at, $s2, $t9
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800AC16C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x800AC170: bne         $at, $zero, L_800AC108
    if (ctx->r1 != 0) {
        // 0x800AC174: addu        $s1, $s1, $s5
        ctx->r17 = ADD32(ctx->r17, ctx->r21);
            goto L_800AC108;
    }
    // 0x800AC174: addu        $s1, $s1, $s5
    ctx->r17 = ADD32(ctx->r17, ctx->r21);
L_800AC178:
    // 0x800AC178: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800AC17C: lw          $t1, 0x2EAC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X2EAC);
    // 0x800AC180: nop

    // 0x800AC184: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x800AC188: jal         0x8007B2C4
    // 0x800AC18C: nop

    load_texture(rdram, ctx);
        goto after_2;
    // 0x800AC18C: nop

    after_2:
    // 0x800AC190: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800AC194: sw          $v0, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r2;
    // 0x800AC198: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800AC19C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800AC1A0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800AC1A4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800AC1A8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800AC1AC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800AC1B0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800AC1B4: jr          $ra
    // 0x800AC1B8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800AC1B8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void weather_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC1BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800AC1C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800AC1C4: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x800AC1C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800AC1CC: blez        $s0, L_800AC3B8
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800AC1D0: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800AC3B8;
    }
    // 0x800AC1D0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800AC1D4: addiu       $v0, $v0, -0x7E88
    ctx->r2 = ADD32(ctx->r2, -0X7E88);
    // 0x800AC1D8: lw          $t6, 0x14($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X14);
    // 0x800AC1DC: nop

    // 0x800AC1E0: bne         $a0, $t6, L_800AC228
    if (ctx->r4 != ctx->r14) {
        // 0x800AC1E4: nop
    
            goto L_800AC228;
    }
    // 0x800AC1E4: nop

    // 0x800AC1E8: lw          $t7, 0x20($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X20);
    // 0x800AC1EC: nop

    // 0x800AC1F0: bne         $a1, $t7, L_800AC228
    if (ctx->r5 != ctx->r15) {
        // 0x800AC1F4: nop
    
            goto L_800AC228;
    }
    // 0x800AC1F4: nop

    // 0x800AC1F8: lw          $t8, 0x2C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X2C);
    // 0x800AC1FC: nop

    // 0x800AC200: bne         $a2, $t8, L_800AC228
    if (ctx->r6 != ctx->r24) {
        // 0x800AC204: nop
    
            goto L_800AC228;
    }
    // 0x800AC204: nop

    // 0x800AC208: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800AC20C: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800AC210: bne         $a3, $t9, L_800AC228
    if (ctx->r7 != ctx->r25) {
        // 0x800AC214: nop
    
            goto L_800AC228;
    }
    // 0x800AC214: nop

    // 0x800AC218: lw          $t0, 0x30($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X30);
    // 0x800AC21C: nop

    // 0x800AC220: beq         $v1, $t0, L_800AC3B8
    if (ctx->r3 == ctx->r8) {
        // 0x800AC224: nop
    
            goto L_800AC3B8;
    }
    // 0x800AC224: nop

L_800AC228:
    // 0x800AC228: lw          $t1, 0xC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XC);
    // 0x800AC22C: lw          $t4, 0x18($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X18);
    // 0x800AC230: subu        $t2, $a0, $t1
    ctx->r10 = SUB32(ctx->r4, ctx->r9);
    // 0x800AC234: div         $zero, $t2, $s0
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r16)));
    // 0x800AC238: subu        $t5, $a1, $t4
    ctx->r13 = SUB32(ctx->r5, ctx->r12);
    // 0x800AC23C: lw          $t7, 0x24($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X24);
    // 0x800AC240: sw          $a0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r4;
    // 0x800AC244: subu        $t8, $a2, $t7
    ctx->r24 = SUB32(ctx->r6, ctx->r15);
    // 0x800AC248: sw          $a1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r5;
    // 0x800AC24C: sw          $a2, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r6;
    // 0x800AC250: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800AC254: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800AC258: bne         $s0, $zero, L_800AC264
    if (ctx->r16 != 0) {
        // 0x800AC25C: nop
    
            goto L_800AC264;
    }
    // 0x800AC25C: nop

    // 0x800AC260: break       7
    do_break(2148188768);
L_800AC264:
    // 0x800AC264: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AC268: bne         $s0, $at, L_800AC27C
    if (ctx->r16 != ctx->r1) {
        // 0x800AC26C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800AC27C;
    }
    // 0x800AC26C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AC270: bne         $t2, $at, L_800AC27C
    if (ctx->r10 != ctx->r1) {
        // 0x800AC274: nop
    
            goto L_800AC27C;
    }
    // 0x800AC274: nop

    // 0x800AC278: break       6
    do_break(2148188792);
L_800AC27C:
    // 0x800AC27C: mflo        $t3
    ctx->r11 = lo;
    // 0x800AC280: sw          $t3, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r11;
    // 0x800AC284: nop

    // 0x800AC288: div         $zero, $t5, $s0
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r16)));
    // 0x800AC28C: bne         $s0, $zero, L_800AC298
    if (ctx->r16 != 0) {
        // 0x800AC290: nop
    
            goto L_800AC298;
    }
    // 0x800AC290: nop

    // 0x800AC294: break       7
    do_break(2148188820);
L_800AC298:
    // 0x800AC298: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AC29C: bne         $s0, $at, L_800AC2B0
    if (ctx->r16 != ctx->r1) {
        // 0x800AC2A0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800AC2B0;
    }
    // 0x800AC2A0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AC2A4: bne         $t5, $at, L_800AC2B0
    if (ctx->r13 != ctx->r1) {
        // 0x800AC2A8: nop
    
            goto L_800AC2B0;
    }
    // 0x800AC2A8: nop

    // 0x800AC2AC: break       6
    do_break(2148188844);
L_800AC2B0:
    // 0x800AC2B0: mflo        $t6
    ctx->r14 = lo;
    // 0x800AC2B4: sw          $t6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r14;
    // 0x800AC2B8: nop

    // 0x800AC2BC: div         $zero, $t8, $s0
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r16)));
    // 0x800AC2C0: bne         $s0, $zero, L_800AC2CC
    if (ctx->r16 != 0) {
        // 0x800AC2C4: nop
    
            goto L_800AC2CC;
    }
    // 0x800AC2C4: nop

    // 0x800AC2C8: break       7
    do_break(2148188872);
L_800AC2CC:
    // 0x800AC2CC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AC2D0: bne         $s0, $at, L_800AC2E4
    if (ctx->r16 != ctx->r1) {
        // 0x800AC2D4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800AC2E4;
    }
    // 0x800AC2D4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AC2D8: bne         $t8, $at, L_800AC2E4
    if (ctx->r24 != ctx->r1) {
        // 0x800AC2DC: nop
    
            goto L_800AC2E4;
    }
    // 0x800AC2DC: nop

    // 0x800AC2E0: break       6
    do_break(2148188896);
L_800AC2E4:
    // 0x800AC2E4: mflo        $t9
    ctx->r25 = lo;
    // 0x800AC2E8: sw          $t9, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r25;
    // 0x800AC2EC: lw          $t0, 0x31EC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X31EC);
    // 0x800AC2F0: nop

    // 0x800AC2F4: bne         $t0, $zero, L_800AC384
    if (ctx->r8 != 0) {
        // 0x800AC2F8: nop
    
            goto L_800AC384;
    }
    // 0x800AC2F8: nop

    // 0x800AC2FC: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800AC300: lw          $t4, 0x30($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X30);
    // 0x800AC304: subu        $t2, $a3, $t1
    ctx->r10 = SUB32(ctx->r7, ctx->r9);
    // 0x800AC308: div         $zero, $t2, $s0
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r16)));
    // 0x800AC30C: subu        $t5, $v1, $t4
    ctx->r13 = SUB32(ctx->r3, ctx->r12);
    // 0x800AC310: bne         $s0, $zero, L_800AC31C
    if (ctx->r16 != 0) {
        // 0x800AC314: nop
    
            goto L_800AC31C;
    }
    // 0x800AC314: nop

    // 0x800AC318: break       7
    do_break(2148188952);
L_800AC31C:
    // 0x800AC31C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AC320: bne         $s0, $at, L_800AC334
    if (ctx->r16 != ctx->r1) {
        // 0x800AC324: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800AC334;
    }
    // 0x800AC324: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AC328: bne         $t2, $at, L_800AC334
    if (ctx->r10 != ctx->r1) {
        // 0x800AC32C: nop
    
            goto L_800AC334;
    }
    // 0x800AC32C: nop

    // 0x800AC330: break       6
    do_break(2148188976);
L_800AC334:
    // 0x800AC334: sw          $a3, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r7;
    // 0x800AC338: sw          $v1, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r3;
    // 0x800AC33C: sw          $s0, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r16;
    // 0x800AC340: mflo        $t3
    ctx->r11 = lo;
    // 0x800AC344: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800AC348: nop

    // 0x800AC34C: div         $zero, $t5, $s0
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r16)));
    // 0x800AC350: bne         $s0, $zero, L_800AC35C
    if (ctx->r16 != 0) {
        // 0x800AC354: nop
    
            goto L_800AC35C;
    }
    // 0x800AC354: nop

    // 0x800AC358: break       7
    do_break(2148189016);
L_800AC35C:
    // 0x800AC35C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AC360: bne         $s0, $at, L_800AC374
    if (ctx->r16 != ctx->r1) {
        // 0x800AC364: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800AC374;
    }
    // 0x800AC364: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AC368: bne         $t5, $at, L_800AC374
    if (ctx->r13 != ctx->r1) {
        // 0x800AC36C: nop
    
            goto L_800AC374;
    }
    // 0x800AC36C: nop

    // 0x800AC370: break       6
    do_break(2148189040);
L_800AC374:
    // 0x800AC374: mflo        $t6
    ctx->r14 = lo;
    // 0x800AC378: sw          $t6, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r14;
    // 0x800AC37C: b           L_800AC3BC
    // 0x800AC380: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800AC3BC;
    // 0x800AC380: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800AC384:
    // 0x800AC384: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    // 0x800AC388: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x800AC38C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AC390: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800AC394: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x800AC398: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800AC39C: sw          $v1, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r3;
    // 0x800AC3A0: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x800AC3A4: addiu       $a0, $a3, 0x1
    ctx->r4 = ADD32(ctx->r7, 0X1);
    // 0x800AC3A8: addiu       $a1, $v1, 0x1
    ctx->r5 = ADD32(ctx->r3, 0X1);
    // 0x800AC3AC: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x800AC3B0: jal         0x800AD824
    // 0x800AC3B4: nop

    rain_set(rdram, ctx);
        goto after_0;
    // 0x800AC3B4: nop

    after_0:
L_800AC3B8:
    // 0x800AC3B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800AC3BC:
    // 0x800AC3BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800AC3C0: jr          $ra
    // 0x800AC3C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800AC3C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void weather_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC3C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AC3CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AC3D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800AC3D4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800AC3D8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800AC3DC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800AC3E0: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800AC3E4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800AC3E8: sw          $t7, -0x7E34($at)
    MEM_W(-0X7E34, ctx->r1) = ctx->r15;
    // 0x800AC3EC: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x800AC3F0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800AC3F4: sw          $t9, -0x7E30($at)
    MEM_W(-0X7E30, ctx->r1) = ctx->r25;
    // 0x800AC3F8: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x800AC3FC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800AC400: sw          $t1, -0x7E2C($at)
    MEM_W(-0X7E2C, ctx->r1) = ctx->r9;
    // 0x800AC404: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x800AC408: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800AC40C: jal         0x80069F60
    // 0x800AC410: sw          $t3, -0x7E28($at)
    MEM_W(-0X7E28, ctx->r1) = ctx->r11;
    cam_get_active_camera(rdram, ctx);
        goto after_0;
    // 0x800AC410: sw          $t3, -0x7E28($at)
    MEM_W(-0X7E28, ctx->r1) = ctx->r11;
    after_0:
    // 0x800AC414: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800AC418: jal         0x80069FFC
    // 0x800AC41C: sw          $v0, -0x7E24($at)
    MEM_W(-0X7E24, ctx->r1) = ctx->r2;
    get_camera_matrix(rdram, ctx);
        goto after_1;
    // 0x800AC41C: sw          $v0, -0x7E24($at)
    MEM_W(-0X7E24, ctx->r1) = ctx->r2;
    after_1:
    // 0x800AC420: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800AC424: lw          $t4, 0x31EC($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X31EC);
    // 0x800AC428: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800AC42C: beq         $t4, $zero, L_800AC448
    if (ctx->r12 == 0) {
        // 0x800AC430: sw          $v0, -0x7E20($at)
        MEM_W(-0X7E20, ctx->r1) = ctx->r2;
            goto L_800AC448;
    }
    // 0x800AC430: sw          $v0, -0x7E20($at)
    MEM_W(-0X7E20, ctx->r1) = ctx->r2;
    // 0x800AC434: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800AC438: jal         0x800ADA18
    // 0x800AC43C: nop

    rain_update(rdram, ctx);
        goto after_2;
    // 0x800AC43C: nop

    after_2:
    // 0x800AC440: b           L_800AC5D4
    // 0x800AC444: nop

        goto L_800AC5D4;
    // 0x800AC444: nop

L_800AC448:
    // 0x800AC448: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800AC44C: addiu       $v0, $v0, -0x7E88
    ctx->r2 = ADD32(ctx->r2, -0X7E88);
    // 0x800AC450: lw          $v1, 0x3C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X3C);
    // 0x800AC454: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800AC458: blez        $v1, L_800AC518
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800AC45C: slt         $at, $a0, $v1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800AC518;
    }
    // 0x800AC45C: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800AC460: beq         $at, $zero, L_800AC4EC
    if (ctx->r1 == 0) {
        // 0x800AC464: nop
    
            goto L_800AC4EC;
    }
    // 0x800AC464: nop

    // 0x800AC468: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x800AC46C: lw          $t0, 0x10($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X10);
    // 0x800AC470: multu       $t6, $a0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AC474: lw          $t4, 0x1C($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X1C);
    // 0x800AC478: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x800AC47C: lw          $t9, 0xC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC);
    // 0x800AC480: lw          $t3, 0x18($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X18);
    // 0x800AC484: mflo        $t7
    ctx->r15 = lo;
    // 0x800AC488: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x800AC48C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800AC490: multu       $t0, $a0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AC494: lw          $t8, 0x28($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X28);
    // 0x800AC498: lw          $t7, 0x24($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X24);
    // 0x800AC49C: mflo        $t1
    ctx->r9 = lo;
    // 0x800AC4A0: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x800AC4A4: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x800AC4A8: multu       $t4, $a0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AC4AC: lw          $t2, 0x34($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X34);
    // 0x800AC4B0: lw          $t1, 0x30($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X30);
    // 0x800AC4B4: mflo        $t6
    ctx->r14 = lo;
    // 0x800AC4B8: addu        $t5, $t3, $t6
    ctx->r13 = ADD32(ctx->r11, ctx->r14);
    // 0x800AC4BC: subu        $t6, $v1, $a0
    ctx->r14 = SUB32(ctx->r3, ctx->r4);
    // 0x800AC4C0: multu       $t8, $a0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AC4C4: sw          $t5, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r13;
    // 0x800AC4C8: sw          $t6, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r14;
    // 0x800AC4CC: mflo        $t0
    ctx->r8 = lo;
    // 0x800AC4D0: addu        $t9, $t7, $t0
    ctx->r25 = ADD32(ctx->r15, ctx->r8);
    // 0x800AC4D4: sw          $t9, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r25;
    // 0x800AC4D8: multu       $t2, $a0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AC4DC: mflo        $t4
    ctx->r12 = lo;
    // 0x800AC4E0: addu        $t3, $t1, $t4
    ctx->r11 = ADD32(ctx->r9, ctx->r12);
    // 0x800AC4E4: b           L_800AC518
    // 0x800AC4E8: sw          $t3, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r11;
        goto L_800AC518;
    // 0x800AC4E8: sw          $t3, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r11;
L_800AC4EC:
    // 0x800AC4EC: lw          $t5, 0x8($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X8);
    // 0x800AC4F0: lw          $t8, 0x14($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X14);
    // 0x800AC4F4: lw          $t7, 0x20($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X20);
    // 0x800AC4F8: lw          $t0, 0x2C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X2C);
    // 0x800AC4FC: lw          $t9, 0x38($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X38);
    // 0x800AC500: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x800AC504: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800AC508: sw          $t8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r24;
    // 0x800AC50C: sw          $t7, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r15;
    // 0x800AC510: sw          $t0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r8;
    // 0x800AC514: sw          $t9, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r25;
L_800AC518:
    // 0x800AC518: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800AC51C: lw          $t2, -0x7E90($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7E90);
    // 0x800AC520: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800AC524: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800AC528: multu       $t2, $t1
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AC52C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800AC530: addiu       $a1, $a1, -0x7E48
    ctx->r5 = ADD32(ctx->r5, -0X7E48);
    // 0x800AC534: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800AC538: mflo        $t4
    ctx->r12 = lo;
    // 0x800AC53C: sra         $t3, $t4, 16
    ctx->r11 = S32(SIGNED(ctx->r12) >> 16);
    // 0x800AC540: sw          $t3, -0x7E8C($at)
    MEM_W(-0X7E8C, ctx->r1) = ctx->r11;
    // 0x800AC544: lh          $t6, 0x2($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X2);
    // 0x800AC548: lh          $v1, 0x0($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X0);
    // 0x800AC54C: lw          $t8, 0x30($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X30);
    // 0x800AC550: subu        $t5, $t6, $v1
    ctx->r13 = SUB32(ctx->r14, ctx->r3);
    // 0x800AC554: multu       $t5, $t8
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AC558: mflo        $t7
    ctx->r15 = lo;
    // 0x800AC55C: addu        $t0, $v1, $t7
    ctx->r8 = ADD32(ctx->r3, ctx->r15);
    // 0x800AC560: sra         $t9, $t0, 16
    ctx->r25 = S32(SIGNED(ctx->r8) >> 16);
    // 0x800AC564: jal         0x800AC628
    // 0x800AC568: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    snow_update(rdram, ctx);
        goto after_3;
    // 0x800AC568: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    after_3:
    // 0x800AC56C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800AC570: lw          $t2, -0x7E8C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7E8C);
    // 0x800AC574: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800AC578: blez        $t2, L_800AC5D4
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800AC57C: addiu       $a1, $a1, -0x7E48
        ctx->r5 = ADD32(ctx->r5, -0X7E48);
            goto L_800AC5D4;
    }
    // 0x800AC57C: addiu       $a1, $a1, -0x7E48
    ctx->r5 = ADD32(ctx->r5, -0X7E48);
    // 0x800AC580: lw          $t1, 0x4($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X4);
    // 0x800AC584: lh          $t4, 0x0($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X0);
    // 0x800AC588: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800AC58C: slt         $at, $t1, $t4
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800AC590: beq         $at, $zero, L_800AC5D4
    if (ctx->r1 == 0) {
        // 0x800AC594: lui         $t5, 0x800E
        ctx->r13 = S32(0X800E << 16);
            goto L_800AC5D4;
    }
    // 0x800AC594: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800AC598: lw          $t3, -0x7E38($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7E38);
    // 0x800AC59C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AC5A0: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x800AC5A4: addu        $t5, $t5, $t6
    ctx->r13 = ADD32(ctx->r13, ctx->r14);
    // 0x800AC5A8: lw          $t5, 0x2EA4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X2EA4);
    // 0x800AC5AC: jal         0x800AC77C
    // 0x800AC5B0: sw          $t5, 0x2E94($at)
    MEM_W(0X2E94, ctx->r1) = ctx->r13;
    snow_vertices(rdram, ctx);
        goto after_4;
    // 0x800AC5B0: sw          $t5, 0x2E94($at)
    MEM_W(0X2E94, ctx->r1) = ctx->r13;
    after_4:
    // 0x800AC5B4: jal         0x800ACB04
    // 0x800AC5B8: nop

    snow_render(rdram, ctx);
        goto after_5;
    // 0x800AC5B8: nop

    after_5:
    // 0x800AC5BC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800AC5C0: addiu       $v0, $v0, -0x7E38
    ctx->r2 = ADD32(ctx->r2, -0X7E38);
    // 0x800AC5C4: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800AC5C8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800AC5CC: subu        $t0, $t7, $t8
    ctx->r8 = SUB32(ctx->r15, ctx->r24);
    // 0x800AC5D0: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
L_800AC5D4:
    // 0x800AC5D4: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800AC5D8: lw          $t9, -0x7E34($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7E34);
    // 0x800AC5DC: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x800AC5E0: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800AC5E4: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x800AC5E8: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800AC5EC: lw          $t1, -0x7E30($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7E30);
    // 0x800AC5F0: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800AC5F4: sw          $t1, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r9;
    // 0x800AC5F8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800AC5FC: lw          $t3, -0x7E2C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7E2C);
    // 0x800AC600: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800AC604: sw          $t3, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r11;
    // 0x800AC608: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800AC60C: lw          $t5, -0x7E28($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7E28);
    // 0x800AC610: nop

    // 0x800AC614: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x800AC618: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AC61C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AC620: jr          $ra
    // 0x800AC624: nop

    return;
    // 0x800AC624: nop

;}
RECOMP_FUNC void snow_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC628: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800AC62C: addiu       $t1, $t1, -0x7E90
    ctx->r9 = ADD32(ctx->r9, -0X7E90);
    // 0x800AC630: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800AC634: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800AC638: blez        $t6, L_800AC774
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800AC63C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800AC774;
    }
    // 0x800AC63C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AC640: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800AC644: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800AC648: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800AC64C: addiu       $t2, $t2, 0x2E64
    ctx->r10 = ADD32(ctx->r10, 0X2E64);
    // 0x800AC650: addiu       $t4, $t4, 0x2E68
    ctx->r12 = ADD32(ctx->r12, 0X2E68);
    // 0x800AC654: addiu       $t5, $t5, -0x7E88
    ctx->r13 = ADD32(ctx->r13, -0X7E88);
    // 0x800AC658: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800AC65C: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
L_800AC660:
    // 0x800AC660: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x800AC664: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x800AC668: addu        $a1, $t7, $a0
    ctx->r5 = ADD32(ctx->r15, ctx->r4);
    // 0x800AC66C: lbu         $t8, 0xF($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0XF);
    // 0x800AC670: nop

    // 0x800AC674: multu       $t8, $t3
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AC678: lw          $t8, 0xC($t5)
    ctx->r24 = MEM_W(ctx->r13, 0XC);
    // 0x800AC67C: mflo        $t9
    ctx->r25 = lo;
    // 0x800AC680: addu        $v1, $t9, $t6
    ctx->r3 = ADD32(ctx->r25, ctx->r14);
    // 0x800AC684: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800AC688: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800AC68C: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x800AC690: multu       $t6, $a2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AC694: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x800AC698: mflo        $t8
    ctx->r24 = lo;
    // 0x800AC69C: sra         $t7, $t8, 1
    ctx->r15 = S32(SIGNED(ctx->r24) >> 1);
    // 0x800AC6A0: lw          $t8, 0x18($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X18);
    // 0x800AC6A4: addu        $t6, $t9, $t7
    ctx->r14 = ADD32(ctx->r25, ctx->r15);
    // 0x800AC6A8: and         $t9, $t6, $t8
    ctx->r25 = ctx->r14 & ctx->r24;
    // 0x800AC6AC: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x800AC6B0: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x800AC6B4: lw          $t8, 0x18($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X18);
    // 0x800AC6B8: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x800AC6BC: addu        $a1, $t7, $a0
    ctx->r5 = ADD32(ctx->r15, ctx->r4);
    // 0x800AC6C0: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800AC6C4: addu        $t7, $t6, $t9
    ctx->r15 = ADD32(ctx->r14, ctx->r25);
    // 0x800AC6C8: multu       $t7, $a2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AC6CC: lw          $t9, 0x4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X4);
    // 0x800AC6D0: mflo        $t8
    ctx->r24 = lo;
    // 0x800AC6D4: sra         $t6, $t8, 1
    ctx->r14 = S32(SIGNED(ctx->r24) >> 1);
    // 0x800AC6D8: lw          $t8, 0x1C($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X1C);
    // 0x800AC6DC: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x800AC6E0: and         $t9, $t7, $t8
    ctx->r25 = ctx->r15 & ctx->r24;
    // 0x800AC6E4: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x800AC6E8: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x800AC6EC: lw          $t8, 0x24($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X24);
    // 0x800AC6F0: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x800AC6F4: addu        $a1, $t6, $a0
    ctx->r5 = ADD32(ctx->r14, ctx->r4);
    // 0x800AC6F8: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800AC6FC: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x800AC700: multu       $t6, $a2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AC704: lw          $t9, 0x8($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X8);
    // 0x800AC708: mflo        $t8
    ctx->r24 = lo;
    // 0x800AC70C: sra         $t7, $t8, 1
    ctx->r15 = S32(SIGNED(ctx->r24) >> 1);
    // 0x800AC710: lw          $t8, 0x20($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X20);
    // 0x800AC714: addu        $t6, $t9, $t7
    ctx->r14 = ADD32(ctx->r25, ctx->r15);
    // 0x800AC718: and         $t9, $t6, $t8
    ctx->r25 = ctx->r14 & ctx->r24;
    // 0x800AC71C: sw          $t9, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r25;
    // 0x800AC720: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x800AC724: nop

    // 0x800AC728: addu        $a1, $t7, $a0
    ctx->r5 = ADD32(ctx->r15, ctx->r4);
    // 0x800AC72C: lbu         $t6, 0xF($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0XF);
    // 0x800AC730: nop

    // 0x800AC734: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x800AC738: sb          $t8, 0xF($a1)
    MEM_B(0XF, ctx->r5) = ctx->r24;
    // 0x800AC73C: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x800AC740: lw          $t0, 0x4($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X4);
    // 0x800AC744: addu        $a1, $t9, $a0
    ctx->r5 = ADD32(ctx->r25, ctx->r4);
    // 0x800AC748: lbu         $a3, 0xF($a1)
    ctx->r7 = MEM_BU(ctx->r5, 0XF);
    // 0x800AC74C: nop

    // 0x800AC750: slt         $at, $a3, $t0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800AC754: bne         $at, $zero, L_800AC760
    if (ctx->r1 != 0) {
        // 0x800AC758: subu        $t7, $a3, $t0
        ctx->r15 = SUB32(ctx->r7, ctx->r8);
            goto L_800AC760;
    }
    // 0x800AC758: subu        $t7, $a3, $t0
    ctx->r15 = SUB32(ctx->r7, ctx->r8);
    // 0x800AC75C: sb          $t7, 0xF($a1)
    MEM_B(0XF, ctx->r5) = ctx->r15;
L_800AC760:
    // 0x800AC760: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800AC764: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800AC768: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800AC76C: bne         $at, $zero, L_800AC660
    if (ctx->r1 != 0) {
        // 0x800AC770: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_800AC660;
    }
    // 0x800AC770: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
L_800AC774:
    // 0x800AC774: jr          $ra
    // 0x800AC778: nop

    return;
    // 0x800AC778: nop

;}
RECOMP_FUNC void snow_vertices(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC77C: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x800AC780: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800AC784: lw          $v0, -0x7E24($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7E24);
    // 0x800AC788: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800AC78C: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800AC790: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800AC794: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800AC798: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800AC79C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800AC7A0: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800AC7A4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800AC7A8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800AC7AC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800AC7B0: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800AC7B4: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800AC7B8: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x800AC7BC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800AC7C0: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800AC7C4: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800AC7C8: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800AC7CC: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800AC7D0: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x800AC7D4: addiu       $s4, $s4, 0x2E98
    ctx->r20 = ADD32(ctx->r20, 0X2E98);
    // 0x800AC7D8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800AC7DC: sw          $zero, 0x0($s4)
    MEM_W(0X0, ctx->r20) = 0;
    // 0x800AC7E0: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800AC7E4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AC7E8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AC7EC: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800AC7F0: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800AC7F4: lw          $t9, -0x7E8C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7E8C);
    // 0x800AC7F8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800AC7FC: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x800AC800: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800AC804: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x800AC808: lw          $s1, 0x2E94($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X2E94);
    // 0x800AC80C: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x800AC810: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800AC814: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x800AC818: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800AC81C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AC820: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AC824: lui         $fp, 0x8013
    ctx->r30 = S32(0X8013 << 16);
    // 0x800AC828: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800AC82C: addiu       $fp, $fp, -0x7E20
    ctx->r30 = ADD32(ctx->r30, -0X7E20);
    // 0x800AC830: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800AC834: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x800AC838: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800AC83C: addiu       $s7, $s7, 0x2E64
    ctx->r23 = ADD32(ctx->r23, 0X2E64);
    // 0x800AC840: addiu       $s6, $s6, -0x7E48
    ctx->r22 = ADD32(ctx->r22, -0X7E48);
    // 0x800AC844: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800AC848: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800AC84C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800AC850: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800AC854: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AC858: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AC85C: lui         $at, 0x3780
    ctx->r1 = S32(0X3780 << 16);
    // 0x800AC860: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800AC864: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800AC868: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x800AC86C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800AC870: blez        $t9, L_800ACACC
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800AC874: addiu       $s5, $sp, 0x64
        ctx->r21 = ADD32(ctx->r29, 0X64);
            goto L_800ACACC;
    }
    // 0x800AC874: addiu       $s5, $sp, 0x64
    ctx->r21 = ADD32(ctx->r29, 0X64);
    // 0x800AC878: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800AC87C: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    // 0x800AC880: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x800AC884: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    // 0x800AC888: addiu       $s0, $s0, 0x2E68
    ctx->r16 = ADD32(ctx->r16, 0X2E68);
L_800AC88C:
    // 0x800AC88C: lw          $t1, 0x0($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X0);
    // 0x800AC890: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x800AC894: addu        $v0, $t1, $s3
    ctx->r2 = ADD32(ctx->r9, ctx->r19);
    // 0x800AC898: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800AC89C: lw          $t4, 0x18($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X18);
    // 0x800AC8A0: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x800AC8A4: subu        $t3, $t2, $v1
    ctx->r11 = SUB32(ctx->r10, ctx->r3);
    // 0x800AC8A8: and         $t5, $t3, $t4
    ctx->r13 = ctx->r11 & ctx->r12;
    // 0x800AC8AC: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800AC8B0: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800AC8B4: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x800AC8B8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800AC8BC: lw          $t1, 0x1C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1C);
    // 0x800AC8C0: lw          $t3, 0x10($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X10);
    // 0x800AC8C4: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x800AC8C8: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800AC8CC: lw          $t7, 0x20($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X20);
    // 0x800AC8D0: lw          $a0, 0x0($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X0);
    // 0x800AC8D4: swc1        $f18, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
    // 0x800AC8D8: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x800AC8DC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800AC8E0: subu        $t9, $t8, $a3
    ctx->r25 = SUB32(ctx->r24, ctx->r7);
    // 0x800AC8E4: and         $t2, $t9, $t1
    ctx->r10 = ctx->r25 & ctx->r9;
    // 0x800AC8E8: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800AC8EC: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x800AC8F0: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x800AC8F4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AC8F8: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800AC8FC: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800AC900: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    // 0x800AC904: lw          $t5, 0x8($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X8);
    // 0x800AC908: nop

    // 0x800AC90C: subu        $t6, $t5, $t0
    ctx->r14 = SUB32(ctx->r13, ctx->r8);
    // 0x800AC910: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x800AC914: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x800AC918: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x800AC91C: nop

    // 0x800AC920: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800AC924: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x800AC928: jal         0x8006F92C
    // 0x800AC92C: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    mtxf_transform_dir(rdram, ctx);
        goto after_0;
    // 0x800AC92C: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x800AC930: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800AC934: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800AC938: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800AC93C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AC940: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AC944: lh          $t5, 0x0($s6)
    ctx->r13 = MEM_H(ctx->r22, 0X0);
    // 0x800AC948: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800AC94C: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800AC950: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800AC954: sll         $t3, $v0, 16
    ctx->r11 = S32(ctx->r2 << 16);
    // 0x800AC958: sra         $t4, $t3, 16
    ctx->r12 = S32(SIGNED(ctx->r11) >> 16);
    // 0x800AC95C: slt         $at, $t4, $t5
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800AC960: beq         $at, $zero, L_800ACAB4
    if (ctx->r1 == 0) {
        // 0x800AC964: sh          $t4, 0x74($sp)
        MEM_H(0X74, ctx->r29) = ctx->r12;
            goto L_800ACAB4;
    }
    // 0x800AC964: sh          $t4, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r12;
    // 0x800AC968: lw          $t6, 0x4($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X4);
    // 0x800AC96C: sh          $t4, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r12;
    // 0x800AC970: slt         $at, $t6, $t4
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800AC974: beq         $at, $zero, L_800ACAB4
    if (ctx->r1 == 0) {
        // 0x800AC978: nop
    
            goto L_800ACAB4;
    }
    // 0x800AC978: nop

    // 0x800AC97C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800AC980: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800AC984: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800AC988: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AC98C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AC990: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800AC994: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800AC998: lh          $t2, 0x24($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X24);
    // 0x800AC99C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800AC9A0: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x800AC9A4: addiu       $s1, $s1, 0x28
    ctx->r17 = ADD32(ctx->r17, 0X28);
    // 0x800AC9A8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800AC9AC: sh          $t4, 0x70($sp)
    MEM_H(0X70, ctx->r29) = ctx->r12;
    // 0x800AC9B0: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800AC9B4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AC9B8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AC9BC: subu        $t5, $t4, $t2
    ctx->r13 = SUB32(ctx->r12, ctx->r10);
    // 0x800AC9C0: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800AC9C4: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x800AC9C8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800AC9CC: sh          $t1, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r9;
    // 0x800AC9D0: sh          $t5, -0x28($s1)
    MEM_H(-0X28, ctx->r17) = ctx->r13;
    // 0x800AC9D4: lh          $t7, 0x26($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X26);
    // 0x800AC9D8: lh          $t6, 0x72($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X72);
    // 0x800AC9DC: nop

    // 0x800AC9E0: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x800AC9E4: sh          $t9, -0x26($s1)
    MEM_H(-0X26, ctx->r17) = ctx->r25;
    // 0x800AC9E8: lh          $t1, 0x74($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X74);
    // 0x800AC9EC: nop

    // 0x800AC9F0: sh          $t1, -0x24($s1)
    MEM_H(-0X24, ctx->r17) = ctx->r9;
    // 0x800AC9F4: lh          $t3, 0x24($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X24);
    // 0x800AC9F8: lh          $t8, 0x70($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X70);
    // 0x800AC9FC: nop

    // 0x800ACA00: addu        $t4, $t8, $t3
    ctx->r12 = ADD32(ctx->r24, ctx->r11);
    // 0x800ACA04: sh          $t4, -0x1E($s1)
    MEM_H(-0X1E, ctx->r17) = ctx->r12;
    // 0x800ACA08: lh          $t5, 0x26($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X26);
    // 0x800ACA0C: lh          $t2, 0x72($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X72);
    // 0x800ACA10: nop

    // 0x800ACA14: addu        $t6, $t2, $t5
    ctx->r14 = ADD32(ctx->r10, ctx->r13);
    // 0x800ACA18: sh          $t6, -0x1C($s1)
    MEM_H(-0X1C, ctx->r17) = ctx->r14;
    // 0x800ACA1C: lh          $t7, 0x74($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X74);
    // 0x800ACA20: nop

    // 0x800ACA24: sh          $t7, -0x1A($s1)
    MEM_H(-0X1A, ctx->r17) = ctx->r15;
    // 0x800ACA28: lh          $t1, 0x24($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X24);
    // 0x800ACA2C: lh          $t9, 0x70($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X70);
    // 0x800ACA30: nop

    // 0x800ACA34: addu        $t8, $t9, $t1
    ctx->r24 = ADD32(ctx->r25, ctx->r9);
    // 0x800ACA38: sh          $t8, -0x14($s1)
    MEM_H(-0X14, ctx->r17) = ctx->r24;
    // 0x800ACA3C: lh          $t4, 0x26($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X26);
    // 0x800ACA40: lh          $t3, 0x72($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X72);
    // 0x800ACA44: nop

    // 0x800ACA48: subu        $t2, $t3, $t4
    ctx->r10 = SUB32(ctx->r11, ctx->r12);
    // 0x800ACA4C: sh          $t2, -0x12($s1)
    MEM_H(-0X12, ctx->r17) = ctx->r10;
    // 0x800ACA50: lh          $t5, 0x74($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X74);
    // 0x800ACA54: nop

    // 0x800ACA58: sh          $t5, -0x10($s1)
    MEM_H(-0X10, ctx->r17) = ctx->r13;
    // 0x800ACA5C: lh          $t7, 0x24($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X24);
    // 0x800ACA60: lh          $t6, 0x70($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X70);
    // 0x800ACA64: nop

    // 0x800ACA68: subu        $t9, $t6, $t7
    ctx->r25 = SUB32(ctx->r14, ctx->r15);
    // 0x800ACA6C: sh          $t9, -0xA($s1)
    MEM_H(-0XA, ctx->r17) = ctx->r25;
    // 0x800ACA70: lh          $t8, 0x26($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X26);
    // 0x800ACA74: lh          $t1, 0x72($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X72);
    // 0x800ACA78: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800ACA7C: subu        $t3, $t1, $t8
    ctx->r11 = SUB32(ctx->r9, ctx->r24);
    // 0x800ACA80: sh          $t3, -0x8($s1)
    MEM_H(-0X8, ctx->r17) = ctx->r11;
    // 0x800ACA84: lh          $t4, 0x74($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X74);
    // 0x800ACA88: nop

    // 0x800ACA8C: sh          $t4, -0x6($s1)
    MEM_H(-0X6, ctx->r17) = ctx->r12;
    // 0x800ACA90: lw          $t2, 0x0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X0);
    // 0x800ACA94: nop

    // 0x800ACA98: addiu       $t5, $t2, 0x4
    ctx->r13 = ADD32(ctx->r10, 0X4);
    // 0x800ACA9C: sw          $t5, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r13;
    // 0x800ACAA0: lw          $t6, 0x2EA0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2EA0);
    // 0x800ACAA4: sra         $t9, $t5, 2
    ctx->r25 = S32(SIGNED(ctx->r13) >> 2);
    // 0x800ACAA8: sll         $t1, $t9, 1
    ctx->r9 = S32(ctx->r25 << 1);
    // 0x800ACAAC: addu        $t8, $t6, $t1
    ctx->r24 = ADD32(ctx->r14, ctx->r9);
    // 0x800ACAB0: sh          $s2, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r18;
L_800ACAB4:
    // 0x800ACAB4: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800ACAB8: lw          $t3, -0x7E8C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7E8C);
    // 0x800ACABC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800ACAC0: slt         $at, $s2, $t3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800ACAC4: bne         $at, $zero, L_800AC88C
    if (ctx->r1 != 0) {
        // 0x800ACAC8: addiu       $s3, $s3, 0x10
        ctx->r19 = ADD32(ctx->r19, 0X10);
            goto L_800AC88C;
    }
    // 0x800ACAC8: addiu       $s3, $s3, 0x10
    ctx->r19 = ADD32(ctx->r19, 0X10);
L_800ACACC:
    // 0x800ACACC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800ACAD0: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800ACAD4: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800ACAD8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800ACADC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800ACAE0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800ACAE4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800ACAE8: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800ACAEC: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800ACAF0: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800ACAF4: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800ACAF8: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800ACAFC: jr          $ra
    // 0x800ACB00: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x800ACB00: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void snow_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ACB04: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800ACB08: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800ACB0C: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x800ACB10: addiu       $s1, $s1, 0x2E68
    ctx->r17 = ADD32(ctx->r17, 0X2E68);
    // 0x800ACB14: lw          $t6, 0x8($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X8);
    // 0x800ACB18: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800ACB1C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800ACB20: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800ACB24: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800ACB28: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800ACB2C: beq         $t6, $zero, L_800ACD8C
    if (ctx->r14 == 0) {
        // 0x800ACB30: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_800ACD8C;
    }
    // 0x800ACB30: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800ACB34: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x800ACB38: addiu       $s3, $s3, 0x2E98
    ctx->r19 = ADD32(ctx->r19, 0X2E98);
    // 0x800ACB3C: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x800ACB40: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800ACB44: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x800ACB48: addiu       $s5, $s5, -0x7E3C
    ctx->r21 = ADD32(ctx->r21, -0X7E3C);
    // 0x800ACB4C: addiu       $s4, $s4, -0x7E40
    ctx->r20 = ADD32(ctx->r20, -0X7E40);
    // 0x800ACB50: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x800ACB54: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800ACB58: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x800ACB5C: sw          $t7, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r15;
    // 0x800ACB60: bne         $at, $zero, L_800ACD8C
    if (ctx->r1 != 0) {
        // 0x800ACB64: sw          $t8, 0x0($s5)
        MEM_W(0X0, ctx->r21) = ctx->r24;
            goto L_800ACD8C;
    }
    // 0x800ACB64: sw          $t8, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r24;
    // 0x800ACB68: jal         0x80069FF0
    // 0x800ACB6C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    get_projection_matrix_s16(rdram, ctx);
        goto after_0;
    // 0x800ACB6C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_0:
    // 0x800ACB70: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800ACB74: addiu       $s0, $s0, -0x7E34
    ctx->r16 = ADD32(ctx->r16, -0X7E34);
    // 0x800ACB78: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800ACB7C: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x800ACB80: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800ACB84: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800ACB88: lui         $t7, 0x100
    ctx->r15 = S32(0X100 << 16);
    // 0x800ACB8C: ori         $t7, $t7, 0x40
    ctx->r15 = ctx->r15 | 0X40;
    // 0x800ACB90: addu        $t8, $v0, $t3
    ctx->r24 = ADD32(ctx->r2, ctx->r11);
    // 0x800ACB94: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800ACB98: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800ACB9C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800ACBA0: lui         $t6, 0xBC00
    ctx->r14 = S32(0XBC00 << 16);
    // 0x800ACBA4: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800ACBA8: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800ACBAC: ori         $t6, $t6, 0xA
    ctx->r14 = ctx->r14 | 0XA;
    // 0x800ACBB0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800ACBB4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800ACBB8: lw          $a1, 0x8($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X8);
    // 0x800ACBBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800ACBC0: jal         0x8007B918
    // 0x800ACBC4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    material_set_no_tex_offset(rdram, ctx);
        goto after_1;
    // 0x800ACBC4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x800ACBC8: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800ACBCC: lw          $t1, 0x0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X0);
    // 0x800ACBD0: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800ACBD4: slt         $at, $v0, $t1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800ACBD8: beq         $at, $zero, L_800ACCBC
    if (ctx->r1 == 0) {
        // 0x800ACBDC: lui         $t3, 0x8000
        ctx->r11 = S32(0X8000 << 16);
            goto L_800ACCBC;
    }
    // 0x800ACBDC: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x800ACBE0: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800ACBE4: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800ACBE8: addiu       $t5, $t5, 0x2E94
    ctx->r13 = ADD32(ctx->r13, 0X2E94);
    // 0x800ACBEC: addiu       $s2, $s2, 0x2E9C
    ctx->r18 = ADD32(ctx->r18, 0X2E9C);
    // 0x800ACBF0: lui         $s1, 0x500
    ctx->r17 = S32(0X500 << 16);
    // 0x800ACBF4: lui         $ra, 0x400
    ctx->r31 = S32(0X400 << 16);
    // 0x800ACBF8: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
L_800ACBFC:
    // 0x800ACBFC: multu       $t0, $t4
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800ACC00: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x800ACC04: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800ACC08: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x800ACC0C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800ACC10: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800ACC14: mflo        $t7
    ctx->r15 = lo;
    // 0x800ACC18: addu        $t2, $t7, $t8
    ctx->r10 = ADD32(ctx->r15, ctx->r24);
    // 0x800ACC1C: addu        $a3, $t2, $t3
    ctx->r7 = ADD32(ctx->r10, ctx->r11);
    // 0x800ACC20: andi        $t8, $a3, 0x6
    ctx->r24 = ctx->r7 & 0X6;
    // 0x800ACC24: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800ACC28: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x800ACC2C: andi        $t6, $t9, 0xFF
    ctx->r14 = ctx->r25 & 0XFF;
    // 0x800ACC30: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x800ACC34: sll         $t9, $v0, 3
    ctx->r25 = S32(ctx->r2 << 3);
    // 0x800ACC38: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x800ACC3C: or          $t8, $t7, $ra
    ctx->r24 = ctx->r15 | ctx->r31;
    // 0x800ACC40: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800ACC44: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x800ACC48: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x800ACC4C: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x800ACC50: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800ACC54: sw          $a3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r7;
    // 0x800ACC58: lw          $a2, 0x0($s5)
    ctx->r6 = MEM_W(ctx->r21, 0X0);
    // 0x800ACC5C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800ACC60: addiu       $t8, $a2, -0x1
    ctx->r24 = ADD32(ctx->r6, -0X1);
    // 0x800ACC64: sll         $t6, $t8, 4
    ctx->r14 = S32(ctx->r24 << 4);
    // 0x800ACC68: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800ACC6C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800ACC70: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x800ACC74: andi        $t9, $t7, 0xFF
    ctx->r25 = ctx->r15 & 0XFF;
    // 0x800ACC78: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x800ACC7C: sll         $t7, $a2, 4
    ctx->r15 = S32(ctx->r6 << 4);
    // 0x800ACC80: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x800ACC84: or          $t6, $t8, $s1
    ctx->r14 = ctx->r24 | ctx->r17;
    // 0x800ACC88: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x800ACC8C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800ACC90: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800ACC94: nop

    // 0x800ACC98: addu        $t6, $t7, $t3
    ctx->r14 = ADD32(ctx->r15, ctx->r11);
    // 0x800ACC9C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800ACCA0: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800ACCA4: lw          $t1, 0x0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X0);
    // 0x800ACCA8: addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
    // 0x800ACCAC: addu        $t9, $t0, $v0
    ctx->r25 = ADD32(ctx->r8, ctx->r2);
    // 0x800ACCB0: slt         $at, $t9, $t1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800ACCB4: bne         $at, $zero, L_800ACBFC
    if (ctx->r1 != 0) {
        // 0x800ACCB8: nop
    
            goto L_800ACBFC;
    }
    // 0x800ACCB8: nop

L_800ACCBC:
    // 0x800ACCBC: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x800ACCC0: multu       $t0, $t4
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800ACCC4: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800ACCC8: addiu       $t5, $t5, 0x2E94
    ctx->r13 = ADD32(ctx->r13, 0X2E94);
    // 0x800ACCCC: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x800ACCD0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800ACCD4: subu        $v0, $t1, $t0
    ctx->r2 = SUB32(ctx->r9, ctx->r8);
    // 0x800ACCD8: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x800ACCDC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800ACCE0: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800ACCE4: lui         $ra, 0x400
    ctx->r31 = S32(0X400 << 16);
    // 0x800ACCE8: lui         $s1, 0x500
    ctx->r17 = S32(0X500 << 16);
    // 0x800ACCEC: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800ACCF0: mflo        $t8
    ctx->r24 = lo;
    // 0x800ACCF4: addu        $t2, $t8, $t7
    ctx->r10 = ADD32(ctx->r24, ctx->r15);
    // 0x800ACCF8: addu        $a3, $t2, $t3
    ctx->r7 = ADD32(ctx->r10, ctx->r11);
    // 0x800ACCFC: andi        $t7, $a3, 0x6
    ctx->r15 = ctx->r7 & 0X6;
    // 0x800ACD00: sll         $t8, $t9, 3
    ctx->r24 = S32(ctx->r25 << 3);
    // 0x800ACD04: or          $t6, $t8, $t7
    ctx->r14 = ctx->r24 | ctx->r15;
    // 0x800ACD08: andi        $t9, $t6, 0xFF
    ctx->r25 = ctx->r14 & 0XFF;
    // 0x800ACD0C: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x800ACD10: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x800ACD14: addu        $t9, $t6, $v0
    ctx->r25 = ADD32(ctx->r14, ctx->r2);
    // 0x800ACD18: or          $t7, $t8, $ra
    ctx->r15 = ctx->r24 | ctx->r31;
    // 0x800ACD1C: sll         $t8, $t9, 1
    ctx->r24 = S32(ctx->r25 << 1);
    // 0x800ACD20: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x800ACD24: andi        $t9, $t6, 0xFFFF
    ctx->r25 = ctx->r14 & 0XFFFF;
    // 0x800ACD28: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x800ACD2C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800ACD30: sw          $a3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r7;
    // 0x800ACD34: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x800ACD38: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800ACD3C: subu        $a2, $t7, $t0
    ctx->r6 = SUB32(ctx->r15, ctx->r8);
    // 0x800ACD40: sra         $t9, $a2, 1
    ctx->r25 = S32(SIGNED(ctx->r6) >> 1);
    // 0x800ACD44: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800ACD48: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800ACD4C: addiu       $t8, $t9, -0x1
    ctx->r24 = ADD32(ctx->r25, -0X1);
    // 0x800ACD50: sll         $t6, $t8, 4
    ctx->r14 = S32(ctx->r24 << 4);
    // 0x800ACD54: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x800ACD58: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x800ACD5C: andi        $t9, $t7, 0xFF
    ctx->r25 = ctx->r15 & 0XFF;
    // 0x800ACD60: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x800ACD64: sll         $t7, $a2, 4
    ctx->r15 = S32(ctx->r6 << 4);
    // 0x800ACD68: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x800ACD6C: or          $t6, $t8, $s1
    ctx->r14 = ctx->r24 | ctx->r17;
    // 0x800ACD70: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x800ACD74: addiu       $s2, $s2, 0x2E9C
    ctx->r18 = ADD32(ctx->r18, 0X2E9C);
    // 0x800ACD78: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800ACD7C: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800ACD80: nop

    // 0x800ACD84: addu        $t6, $t7, $t3
    ctx->r14 = ADD32(ctx->r15, ctx->r11);
    // 0x800ACD88: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
L_800ACD8C:
    // 0x800ACD8C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800ACD90: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800ACD94: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800ACD98: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACD9C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800ACDA0: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800ACDA4: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800ACDA8: jr          $ra
    // 0x800ACDAC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800ACDAC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void lensflare_off(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ACDB0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800ACDB4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800ACDB8: jr          $ra
    // 0x800ACDBC: sw          $t6, 0x3014($at)
    MEM_W(0X3014, ctx->r1) = ctx->r14;
    return;
    // 0x800ACDBC: sw          $t6, 0x3014($at)
    MEM_W(0X3014, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void lensflare_on(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ACDC0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800ACDC4: lw          $t6, 0x3010($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3010);
    // 0x800ACDC8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800ACDCC: beq         $t6, $zero, L_800ACDD8
    if (ctx->r14 == 0) {
        // 0x800ACDD0: nop
    
            goto L_800ACDD8;
    }
    // 0x800ACDD0: nop

    // 0x800ACDD4: sw          $zero, 0x3014($at)
    MEM_W(0X3014, ctx->r1) = 0;
L_800ACDD8:
    // 0x800ACDD8: jr          $ra
    // 0x800ACDDC: nop

    return;
    // 0x800ACDDC: nop

;}
RECOMP_FUNC void lensflare_remove(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ACDE0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800ACDE4: addiu       $v0, $v0, 0x3010
    ctx->r2 = ADD32(ctx->r2, 0X3010);
    // 0x800ACDE8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800ACDEC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800ACDF0: bne         $a0, $t6, L_800ACE00
    if (ctx->r4 != ctx->r14) {
        // 0x800ACDF4: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800ACE00;
    }
    // 0x800ACDF4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800ACDF8: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800ACDFC: sw          $t7, 0x3014($at)
    MEM_W(0X3014, ctx->r1) = ctx->r15;
L_800ACE00:
    // 0x800ACE00: jr          $ra
    // 0x800ACE04: nop

    return;
    // 0x800ACE04: nop

;}
RECOMP_FUNC void lensflare_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ACE08: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800ACE0C: addiu       $a1, $a1, 0x3010
    ctx->r5 = ADD32(ctx->r5, 0X3010);
    // 0x800ACE10: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    // 0x800ACE14: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800ACE18: sw          $zero, 0x3014($at)
    MEM_W(0X3014, ctx->r1) = 0;
    // 0x800ACE1C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800ACE20: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800ACE24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800ACE28: lw          $v1, 0x3C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X3C);
    // 0x800ACE2C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800ACE30: lbu         $v0, 0xC($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XC);
    // 0x800ACE34: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800ACE38: beq         $v0, $a2, L_800ACE64
    if (ctx->r2 == ctx->r6) {
        // 0x800ACE3C: addiu       $a1, $a1, -0x7E10
        ctx->r5 = ADD32(ctx->r5, -0X7E10);
            goto L_800ACE64;
    }
    // 0x800ACE3C: addiu       $a1, $a1, -0x7E10
    ctx->r5 = ADD32(ctx->r5, -0X7E10);
    // 0x800ACE40: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800ACE44: beq         $v0, $at, L_800ACE78
    if (ctx->r2 == ctx->r1) {
        // 0x800ACE48: lui         $t8, 0x800E
        ctx->r24 = S32(0X800E << 16);
            goto L_800ACE78;
    }
    // 0x800ACE48: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800ACE4C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800ACE50: beq         $v0, $at, L_800ACE88
    if (ctx->r2 == ctx->r1) {
        // 0x800ACE54: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_800ACE88;
    }
    // 0x800ACE54: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800ACE58: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800ACE5C: b           L_800ACE94
    // 0x800ACE60: sw          $zero, -0x7E1C($at)
    MEM_W(-0X7E1C, ctx->r1) = 0;
        goto L_800ACE94;
    // 0x800ACE60: sw          $zero, -0x7E1C($at)
    MEM_W(-0X7E1C, ctx->r1) = 0;
L_800ACE64:
    // 0x800ACE64: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800ACE68: addiu       $t7, $t7, 0x2F30
    ctx->r15 = ADD32(ctx->r15, 0X2F30);
    // 0x800ACE6C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800ACE70: b           L_800ACE94
    // 0x800ACE74: sw          $t7, -0x7E1C($at)
    MEM_W(-0X7E1C, ctx->r1) = ctx->r15;
        goto L_800ACE94;
    // 0x800ACE74: sw          $t7, -0x7E1C($at)
    MEM_W(-0X7E1C, ctx->r1) = ctx->r15;
L_800ACE78:
    // 0x800ACE78: addiu       $t8, $t8, 0x2F70
    ctx->r24 = ADD32(ctx->r24, 0X2F70);
    // 0x800ACE7C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800ACE80: b           L_800ACE94
    // 0x800ACE84: sw          $t8, -0x7E1C($at)
    MEM_W(-0X7E1C, ctx->r1) = ctx->r24;
        goto L_800ACE94;
    // 0x800ACE84: sw          $t8, -0x7E1C($at)
    MEM_W(-0X7E1C, ctx->r1) = ctx->r24;
L_800ACE88:
    // 0x800ACE88: addiu       $t9, $t9, 0x2FC0
    ctx->r25 = ADD32(ctx->r25, 0X2FC0);
    // 0x800ACE8C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800ACE90: sw          $t9, -0x7E1C($at)
    MEM_W(-0X7E1C, ctx->r1) = ctx->r25;
L_800ACE94:
    // 0x800ACE94: lbu         $v0, 0xD($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XD);
    // 0x800ACE98: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800ACE9C: beq         $v0, $a2, L_800ACEC8
    if (ctx->r2 == ctx->r6) {
        // 0x800ACEA0: addiu       $a0, $sp, 0x1C
        ctx->r4 = ADD32(ctx->r29, 0X1C);
            goto L_800ACEC8;
    }
    // 0x800ACEA0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x800ACEA4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800ACEA8: beq         $v0, $at, L_800ACEDC
    if (ctx->r2 == ctx->r1) {
        // 0x800ACEAC: lui         $t1, 0x800E
        ctx->r9 = S32(0X800E << 16);
            goto L_800ACEDC;
    }
    // 0x800ACEAC: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800ACEB0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800ACEB4: beq         $v0, $at, L_800ACEEC
    if (ctx->r2 == ctx->r1) {
        // 0x800ACEB8: lui         $t2, 0x800E
        ctx->r10 = S32(0X800E << 16);
            goto L_800ACEEC;
    }
    // 0x800ACEB8: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800ACEBC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800ACEC0: b           L_800ACEF8
    // 0x800ACEC4: sw          $zero, -0x7E18($at)
    MEM_W(-0X7E18, ctx->r1) = 0;
        goto L_800ACEF8;
    // 0x800ACEC4: sw          $zero, -0x7E18($at)
    MEM_W(-0X7E18, ctx->r1) = 0;
L_800ACEC8:
    // 0x800ACEC8: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800ACECC: addiu       $t0, $t0, 0x2F30
    ctx->r8 = ADD32(ctx->r8, 0X2F30);
    // 0x800ACED0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800ACED4: b           L_800ACEF8
    // 0x800ACED8: sw          $t0, -0x7E18($at)
    MEM_W(-0X7E18, ctx->r1) = ctx->r8;
        goto L_800ACEF8;
    // 0x800ACED8: sw          $t0, -0x7E18($at)
    MEM_W(-0X7E18, ctx->r1) = ctx->r8;
L_800ACEDC:
    // 0x800ACEDC: addiu       $t1, $t1, 0x2F70
    ctx->r9 = ADD32(ctx->r9, 0X2F70);
    // 0x800ACEE0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800ACEE4: b           L_800ACEF8
    // 0x800ACEE8: sw          $t1, -0x7E18($at)
    MEM_W(-0X7E18, ctx->r1) = ctx->r9;
        goto L_800ACEF8;
    // 0x800ACEE8: sw          $t1, -0x7E18($at)
    MEM_W(-0X7E18, ctx->r1) = ctx->r9;
L_800ACEEC:
    // 0x800ACEEC: addiu       $t2, $t2, 0x2FC0
    ctx->r10 = ADD32(ctx->r10, 0X2FC0);
    // 0x800ACEF0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800ACEF4: sw          $t2, -0x7E18($at)
    MEM_W(-0X7E18, ctx->r1) = ctx->r10;
L_800ACEF8:
    // 0x800ACEF8: lbu         $t3, 0xE($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0XE);
    // 0x800ACEFC: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800ACF00: bne         $a2, $t3, L_800ACF18
    if (ctx->r6 != ctx->r11) {
        // 0x800ACF04: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_800ACF18;
    }
    // 0x800ACF04: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800ACF08: addiu       $t4, $t4, 0x2F10
    ctx->r12 = ADD32(ctx->r12, 0X2F10);
    // 0x800ACF0C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800ACF10: b           L_800ACF1C
    // 0x800ACF14: sw          $t4, -0x7E14($at)
    MEM_W(-0X7E14, ctx->r1) = ctx->r12;
        goto L_800ACF1C;
    // 0x800ACF14: sw          $t4, -0x7E14($at)
    MEM_W(-0X7E14, ctx->r1) = ctx->r12;
L_800ACF18:
    // 0x800ACF18: sw          $zero, -0x7E14($at)
    MEM_W(-0X7E14, ctx->r1) = 0;
L_800ACF1C:
    // 0x800ACF1C: lh          $t5, 0xA($v1)
    ctx->r13 = MEM_H(ctx->r3, 0XA);
    // 0x800ACF20: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800ACF24: sh          $t5, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r13;
    // 0x800ACF28: lh          $t6, 0x8($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X8);
    // 0x800ACF2C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800ACF30: sh          $zero, 0x20($sp)
    MEM_H(0X20, ctx->r29) = 0;
    // 0x800ACF34: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x800ACF38: swc1        $f0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f0.u32l;
    // 0x800ACF3C: sh          $t6, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r14;
    // 0x800ACF40: jal         0x800706D0
    // 0x800ACF44: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
    vec3f_rotate_py(rdram, ctx);
        goto after_0;
    // 0x800ACF44: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
    after_0:
    // 0x800ACF48: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800ACF4C: addiu       $a1, $a1, -0x7E10
    ctx->r5 = ADD32(ctx->r5, -0X7E10);
    // 0x800ACF50: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800ACF54: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800ACF58: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800ACF5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800ACF60: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x800ACF64: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x800ACF68: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x800ACF6C: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
    // 0x800ACF70: swc1        $f16, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f16.u32l;
    // 0x800ACF74: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
    // 0x800ACF78: jr          $ra
    // 0x800ACF7C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800ACF7C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void lensflare_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ACF80: addiu       $sp, $sp, -0xF0
    ctx->r29 = ADD32(ctx->r29, -0XF0);
    // 0x800ACF84: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x800ACF88: lui         $s6, 0x800E
    ctx->r22 = S32(0X800E << 16);
    // 0x800ACF8C: addiu       $s6, $s6, 0x3010
    ctx->r22 = ADD32(ctx->r22, 0X3010);
    // 0x800ACF90: lw          $t7, 0x0($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X0);
    // 0x800ACF94: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x800ACF98: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x800ACF9C: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x800ACFA0: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x800ACFA4: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x800ACFA8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800ACFAC: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x800ACFB0: or          $s7, $a2, $zero
    ctx->r23 = ctx->r6 | 0;
    // 0x800ACFB4: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x800ACFB8: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x800ACFBC: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x800ACFC0: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x800ACFC4: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x800ACFC8: swc1        $f25, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x800ACFCC: swc1        $f24, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f24.u32l;
    // 0x800ACFD0: swc1        $f23, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800ACFD4: swc1        $f22, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f22.u32l;
    // 0x800ACFD8: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800ACFDC: beq         $t7, $zero, L_800AD478
    if (ctx->r15 == 0) {
        // 0x800ACFE0: swc1        $f20, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
            goto L_800AD478;
    }
    // 0x800ACFE0: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x800ACFE4: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800ACFE8: lw          $t9, 0x3014($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3014);
    // 0x800ACFEC: nop

    // 0x800ACFF0: bne         $t9, $zero, L_800AD47C
    if (ctx->r25 != 0) {
        // 0x800ACFF4: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_800AD47C;
    }
    // 0x800ACFF4: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x800ACFF8: jal         0x80066450
    // 0x800ACFFC: nop

    cam_get_viewport_layout(rdram, ctx);
        goto after_0;
    // 0x800ACFFC: nop

    after_0:
    // 0x800AD000: bne         $v0, $zero, L_800AD478
    if (ctx->r2 != 0) {
        // 0x800AD004: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_800AD478;
    }
    // 0x800AD004: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800AD008: lw          $t6, 0x0($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X0);
    // 0x800AD00C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800AD010: lw          $t3, 0x3C($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X3C);
    // 0x800AD014: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800AD018: swc1        $f20, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f20.u32l;
    // 0x800AD01C: swc1        $f20, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f20.u32l;
    // 0x800AD020: sw          $t3, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r11;
    // 0x800AD024: jal         0x80069FE4
    // 0x800AD028: swc1        $f10, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f10.u32l;
    get_projection_matrix_f32(rdram, ctx);
        goto after_1;
    // 0x800AD028: swc1        $f10, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x800AD02C: addiu       $a1, $sp, 0xD8
    ctx->r5 = ADD32(ctx->r29, 0XD8);
    // 0x800AD030: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800AD034: jal         0x8006F92C
    // 0x800AD038: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mtxf_transform_dir(rdram, ctx);
        goto after_2;
    // 0x800AD038: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x800AD03C: lui         $fp, 0x8013
    ctx->r30 = S32(0X8013 << 16);
    // 0x800AD040: addiu       $fp, $fp, -0x7E10
    ctx->r30 = ADD32(ctx->r30, -0X7E10);
    // 0x800AD044: lwc1        $f6, 0x0($fp)
    ctx->f6.u32l = MEM_W(ctx->r30, 0X0);
    // 0x800AD048: lwc1        $f4, 0xD8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800AD04C: lwc1        $f10, 0x4($fp)
    ctx->f10.u32l = MEM_W(ctx->r30, 0X4);
    // 0x800AD050: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800AD054: lwc1        $f6, 0xDC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x800AD058: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800AD05C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800AD060: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800AD064: lwc1        $f6, 0xE0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x800AD068: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800AD06C: lwc1        $f8, 0x8($fp)
    ctx->f8.u32l = MEM_W(ctx->r30, 0X8);
    // 0x800AD070: nop

    // 0x800AD074: mul.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800AD078: add.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800AD07C: c.lt.s      $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f20.fl < ctx->f18.fl;
    // 0x800AD080: nop

    // 0x800AD084: bc1f        L_800AD47C
    if (!c1cs) {
        // 0x800AD088: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_800AD47C;
    }
    // 0x800AD088: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x800AD08C: jal         0x80066F1C
    // 0x800AD090: swc1        $f18, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f18.u32l;
    viewport_main(rdram, ctx);
        goto after_3;
    // 0x800AD090: swc1        $f18, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x800AD094: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800AD098: jal         0x80068648
    // 0x800AD09C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    mtx_world_origin(rdram, ctx);
        goto after_4;
    // 0x800AD09C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_4:
    // 0x800AD0A0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800AD0A4: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x800AD0A8: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x800AD0AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800AD0B0: lwc1        $f12, 0x0($fp)
    ctx->f12.u32l = MEM_W(ctx->r30, 0X0);
    // 0x800AD0B4: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800AD0B8: mul.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x800AD0BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800AD0C0: lwc1        $f14, 0x4($fp)
    ctx->f14.u32l = MEM_W(ctx->r30, 0X4);
    // 0x800AD0C4: lwc1        $f2, 0x8($fp)
    ctx->f2.u32l = MEM_W(ctx->r30, 0X8);
    // 0x800AD0C8: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800AD0CC: lwc1        $f18, 0xC8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x800AD0D0: mul.s       $f8, $f14, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f6.fl);
    // 0x800AD0D4: swc1        $f10, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f10.u32l;
    // 0x800AD0D8: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800AD0DC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800AD0E0: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800AD0E4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800AD0E8: mul.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800AD0EC: swc1        $f10, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f10.u32l;
    // 0x800AD0F0: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800AD0F4: lwc1        $f6, 0xD8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800AD0F8: mul.s       $f20, $f18, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x800AD0FC: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800AD100: sh          $zero, 0xA4($sp)
    MEM_H(0XA4, ctx->r29) = 0;
    // 0x800AD104: swc1        $f10, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f10.u32l;
    // 0x800AD108: mul.s       $f22, $f20, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f22.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x800AD10C: lwc1        $f10, 0xDC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x800AD110: sh          $zero, 0xA6($sp)
    MEM_H(0XA6, ctx->r29) = 0;
    // 0x800AD114: sh          $zero, 0xA8($sp)
    MEM_H(0XA8, ctx->r29) = 0;
    // 0x800AD118: mul.s       $f16, $f24, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f24.fl, ctx->f18.fl);
    // 0x800AD11C: lui         $s4, 0xFA00
    ctx->r20 = S32(0XFA00 << 16);
    // 0x800AD120: addiu       $s3, $sp, 0xA4
    ctx->r19 = ADD32(ctx->r29, 0XA4);
    // 0x800AD124: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800AD128: mul.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x800AD12C: sub.s       $f4, $f8, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x800AD130: mul.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800AD134: swc1        $f4, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f4.u32l;
    // 0x800AD138: lwc1        $f4, 0xE0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x800AD13C: nop

    // 0x800AD140: mul.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800AD144: sub.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f14.fl;
    // 0x800AD148: swc1        $f8, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f8.u32l;
    // 0x800AD14C: sub.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x800AD150: swc1        $f6, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f6.u32l;
L_800AD154:
    // 0x800AD154: bne         $s2, $zero, L_800AD168
    if (ctx->r18 != 0) {
        // 0x800AD158: lui         $s0, 0x8013
        ctx->r16 = S32(0X8013 << 16);
            goto L_800AD168;
    }
    // 0x800AD158: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800AD15C: lw          $s0, -0x7E14($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7E14);
    // 0x800AD160: b           L_800AD188
    // 0x800AD164: nop

        goto L_800AD188;
    // 0x800AD164: nop

L_800AD168:
    // 0x800AD168: bne         $s2, $v0, L_800AD180
    if (ctx->r18 != ctx->r2) {
        // 0x800AD16C: lui         $s0, 0x8013
        ctx->r16 = S32(0X8013 << 16);
            goto L_800AD180;
    }
    // 0x800AD16C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800AD170: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800AD174: lw          $s0, -0x7E1C($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7E1C);
    // 0x800AD178: b           L_800AD188
    // 0x800AD17C: nop

        goto L_800AD188;
    // 0x800AD17C: nop

L_800AD180:
    // 0x800AD180: lw          $s0, -0x7E18($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7E18);
    // 0x800AD184: nop

L_800AD188:
    // 0x800AD188: beq         $s0, $zero, L_800AD2EC
    if (ctx->r16 == 0) {
        // 0x800AD18C: nop
    
            goto L_800AD2EC;
    }
    // 0x800AD18C: nop

    // 0x800AD190: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x800AD194: nop

    // 0x800AD198: blez        $t5, L_800AD2EC
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800AD19C: nop
    
            goto L_800AD2EC;
    }
    // 0x800AD19C: nop

L_800AD1A0:
    // 0x800AD1A0: lwc1        $f8, 0xCC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800AD1A4: lwc1        $f4, 0xD0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x800AD1A8: lwc1        $f10, 0xD4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800AD1AC: swc1        $f8, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f8.u32l;
    // 0x800AD1B0: swc1        $f4, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f4.u32l;
    // 0x800AD1B4: beq         $s2, $zero, L_800AD210
    if (ctx->r18 == 0) {
        // 0x800AD1B8: swc1        $f10, 0xB8($sp)
        MEM_W(0XB8, ctx->r29) = ctx->f10.u32l;
            goto L_800AD210;
    }
    // 0x800AD1B8: swc1        $f10, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f10.u32l;
    // 0x800AD1BC: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800AD1C0: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
    // 0x800AD1C4: lwc1        $f8, 0xD8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800AD1C8: nop

    // 0x800AD1CC: mul.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800AD1D0: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800AD1D4: nop

    // 0x800AD1D8: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800AD1DC: swc1        $f8, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f8.u32l;
    // 0x800AD1E0: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800AD1E4: lwc1        $f8, 0xDC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x800AD1E8: nop

    // 0x800AD1EC: mul.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800AD1F0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800AD1F4: lwc1        $f6, 0xE0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x800AD1F8: swc1        $f8, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f8.u32l;
    // 0x800AD1FC: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800AD200: nop

    // 0x800AD204: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AD208: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800AD20C: swc1        $f4, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f4.u32l;
L_800AD210:
    // 0x800AD210: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800AD214: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800AD218: mul.s       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800AD21C: swc1        $f10, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f10.u32l;
    // 0x800AD220: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800AD224: nop

    // 0x800AD228: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800AD22C: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800AD230: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x800AD234: lbu         $t3, 0x5($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X5);
    // 0x800AD238: lbu         $t7, 0x4($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X4);
    // 0x800AD23C: sll         $t5, $t3, 16
    ctx->r13 = S32(ctx->r11 << 16);
    // 0x800AD240: sll         $t9, $t7, 24
    ctx->r25 = S32(ctx->r15 << 24);
    // 0x800AD244: or          $t8, $t9, $t5
    ctx->r24 = ctx->r25 | ctx->r13;
    // 0x800AD248: lbu         $t9, 0x7($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X7);
    // 0x800AD24C: lbu         $t7, 0x6($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X6);
    // 0x800AD250: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800AD254: sll         $t6, $t7, 8
    ctx->r14 = S32(ctx->r15 << 8);
    // 0x800AD258: or          $t3, $t8, $t6
    ctx->r11 = ctx->r24 | ctx->r14;
    // 0x800AD25C: bgez        $t9, L_800AD270
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800AD260: cvt.s.w     $f4, $f8
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800AD270;
    }
    // 0x800AD260: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800AD264: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800AD268: nop

    // 0x800AD26C: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_800AD270:
    // 0x800AD270: mul.s       $f10, $f4, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x800AD274: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800AD278: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800AD27C: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x800AD280: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800AD284: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x800AD288: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800AD28C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AD290: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AD294: nop

    // 0x800AD298: cvt.w.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800AD29C: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x800AD2A0: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800AD2A4: andi        $t7, $t4, 0xFF
    ctx->r15 = ctx->r12 & 0XFF;
    // 0x800AD2A8: or          $t8, $t3, $t7
    ctx->r24 = ctx->r11 | ctx->r15;
    // 0x800AD2AC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800AD2B0: lw          $t6, 0x0($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X0);
    // 0x800AD2B4: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x800AD2B8: lw          $t9, 0x68($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X68);
    // 0x800AD2BC: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x800AD2C0: addu        $t3, $t9, $t4
    ctx->r11 = ADD32(ctx->r25, ctx->r12);
    // 0x800AD2C4: lw          $t7, 0x0($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X0);
    // 0x800AD2C8: addiu       $t8, $zero, 0x104
    ctx->r24 = ADD32(0, 0X104);
    // 0x800AD2CC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800AD2D0: jal         0x80068754
    // 0x800AD2D4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    render_sprite_billboard(rdram, ctx);
        goto after_5;
    // 0x800AD2D4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_5:
    // 0x800AD2D8: lw          $t6, 0x10($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X10);
    // 0x800AD2DC: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x800AD2E0: bgtz        $t6, L_800AD1A0
    if (SIGNED(ctx->r14) > 0) {
        // 0x800AD2E4: nop
    
            goto L_800AD1A0;
    }
    // 0x800AD2E4: nop

    // 0x800AD2E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800AD2EC:
    // 0x800AD2EC: bne         $s2, $v0, L_800AD354
    if (ctx->r18 != ctx->r2) {
        // 0x800AD2F0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800AD354;
    }
    // 0x800AD2F0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800AD2F4: lwc1        $f12, 0x0($fp)
    ctx->f12.u32l = MEM_W(ctx->r30, 0X0);
    // 0x800AD2F8: lwc1        $f6, 0xD8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800AD2FC: lwc1        $f14, 0x4($fp)
    ctx->f14.u32l = MEM_W(ctx->r30, 0X4);
    // 0x800AD300: mul.s       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800AD304: lwc1        $f10, 0xDC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x800AD308: lwc1        $f2, 0x8($fp)
    ctx->f2.u32l = MEM_W(ctx->r30, 0X8);
    // 0x800AD30C: swc1        $f6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f6.u32l;
    // 0x800AD310: mul.s       $f8, $f10, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800AD314: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800AD318: lwc1        $f8, 0xE0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x800AD31C: nop

    // 0x800AD320: mul.s       $f6, $f2, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x800AD324: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800AD328: mul.s       $f0, $f6, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x800AD32C: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800AD330: mul.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x800AD334: sub.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800AD338: mul.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x800AD33C: swc1        $f4, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f4.u32l;
    // 0x800AD340: sub.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800AD344: mul.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800AD348: swc1        $f4, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f4.u32l;
    // 0x800AD34C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800AD350: swc1        $f10, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f10.u32l;
L_800AD354:
    // 0x800AD354: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800AD358: bne         $s2, $at, L_800AD154
    if (ctx->r18 != ctx->r1) {
        // 0x800AD35C: nop
    
            goto L_800AD154;
    }
    // 0x800AD35C: nop

    // 0x800AD360: jal         0x8007A970
    // 0x800AD364: nop

    fb_size(rdram, ctx);
        goto after_6;
    // 0x800AD364: nop

    after_6:
    // 0x800AD368: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800AD36C: lw          $t2, 0x98($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X98);
    // 0x800AD370: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800AD374: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800AD378: addiu       $t4, $t4, 0x2EB8
    ctx->r12 = ADD32(ctx->r12, 0X2EB8);
    // 0x800AD37C: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x800AD380: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800AD384: sra         $t0, $v0, 16
    ctx->r8 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800AD388: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800AD38C: sw          $t4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r12;
    // 0x800AD390: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800AD394: andi        $t5, $t0, 0xFFFF
    ctx->r13 = ctx->r8 & 0XFFFF;
    // 0x800AD398: sw          $s4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r20;
    // 0x800AD39C: or          $t0, $t5, $zero
    ctx->r8 = ctx->r13 | 0;
    // 0x800AD3A0: lbu         $t5, 0x11($t2)
    ctx->r13 = MEM_BU(ctx->r10, 0X11);
    // 0x800AD3A4: lbu         $t7, 0x10($t2)
    ctx->r15 = MEM_BU(ctx->r10, 0X10);
    // 0x800AD3A8: sll         $t9, $t5, 16
    ctx->r25 = S32(ctx->r13 << 16);
    // 0x800AD3AC: sll         $t8, $t7, 24
    ctx->r24 = S32(ctx->r15 << 24);
    // 0x800AD3B0: or          $t4, $t8, $t9
    ctx->r12 = ctx->r24 | ctx->r25;
    // 0x800AD3B4: lbu         $t8, 0x13($t2)
    ctx->r24 = MEM_BU(ctx->r10, 0X13);
    // 0x800AD3B8: lbu         $t7, 0x12($t2)
    ctx->r15 = MEM_BU(ctx->r10, 0X12);
    // 0x800AD3BC: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800AD3C0: sll         $t6, $t7, 8
    ctx->r14 = S32(ctx->r15 << 8);
    // 0x800AD3C4: andi        $t1, $v0, 0xFFFF
    ctx->r9 = ctx->r2 & 0XFFFF;
    // 0x800AD3C8: or          $t5, $t4, $t6
    ctx->r13 = ctx->r12 | ctx->r14;
    // 0x800AD3CC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800AD3D0: bgez        $t8, L_800AD3E8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800AD3D4: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800AD3E8;
    }
    // 0x800AD3D4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AD3D8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800AD3DC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800AD3E0: nop

    // 0x800AD3E4: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800AD3E8:
    // 0x800AD3E8: mul.s       $f10, $f6, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x800AD3EC: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x800AD3F0: lui         $t6, 0xFCFF
    ctx->r14 = S32(0XFCFF << 16);
    // 0x800AD3F4: lui         $t8, 0xFFFD
    ctx->r24 = S32(0XFFFD << 16);
    // 0x800AD3F8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800AD3FC: ori         $t8, $t8, 0xF6FB
    ctx->r24 = ctx->r24 | 0XF6FB;
    // 0x800AD400: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800AD404: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AD408: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AD40C: ori         $t6, $t6, 0xFFFF
    ctx->r14 = ctx->r14 | 0XFFFF;
    // 0x800AD410: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800AD414: addiu       $a3, $v1, 0x8
    ctx->r7 = ADD32(ctx->r3, 0X8);
    // 0x800AD418: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x800AD41C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800AD420: andi        $t7, $t3, 0xFF
    ctx->r15 = ctx->r11 & 0XFF;
    // 0x800AD424: or          $t4, $t5, $t7
    ctx->r12 = ctx->r13 | ctx->r15;
    // 0x800AD428: sw          $t4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r12;
    // 0x800AD42C: andi        $t9, $t1, 0x3FF
    ctx->r25 = ctx->r9 & 0X3FF;
    // 0x800AD430: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x800AD434: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800AD438: sll         $t3, $t9, 14
    ctx->r11 = S32(ctx->r25 << 14);
    // 0x800AD43C: andi        $t7, $t0, 0x3FF
    ctx->r15 = ctx->r8 & 0X3FF;
    // 0x800AD440: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x800AD444: or          $t5, $t3, $at
    ctx->r13 = ctx->r11 | ctx->r1;
    // 0x800AD448: sll         $t4, $t7, 2
    ctx->r12 = S32(ctx->r15 << 2);
    // 0x800AD44C: or          $t6, $t5, $t4
    ctx->r14 = ctx->r13 | ctx->r12;
    // 0x800AD450: addiu       $v0, $a3, 0x8
    ctx->r2 = ADD32(ctx->r7, 0X8);
    // 0x800AD454: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x800AD458: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x800AD45C: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x800AD460: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800AD464: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800AD468: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x800AD46C: sw          $v1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r3;
    // 0x800AD470: jal         0x8007B820
    // 0x800AD474: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    rendermode_reset(rdram, ctx);
        goto after_7;
    // 0x800AD474: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
L_800AD478:
    // 0x800AD478: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_800AD47C:
    // 0x800AD47C: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800AD480: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800AD484: lwc1        $f23, 0x28($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800AD488: lwc1        $f22, 0x2C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800AD48C: lwc1        $f25, 0x30($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x800AD490: lwc1        $f24, 0x34($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800AD494: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x800AD498: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x800AD49C: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x800AD4A0: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x800AD4A4: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x800AD4A8: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x800AD4AC: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x800AD4B0: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x800AD4B4: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x800AD4B8: jr          $ra
    // 0x800AD4BC: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
    return;
    // 0x800AD4BC: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
;}
RECOMP_FUNC void lensflare_override_add(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD4C0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AD4C4: addiu       $v1, $v1, 0x3018
    ctx->r3 = ADD32(ctx->r3, 0X3018);
    // 0x800AD4C8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800AD4CC: nop

    // 0x800AD4D0: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x800AD4D4: beq         $at, $zero, L_800AD4F0
    if (ctx->r1 == 0) {
        // 0x800AD4D8: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_800AD4F0;
    }
    // 0x800AD4D8: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800AD4DC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800AD4E0: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800AD4E4: sw          $a0, -0x7E00($at)
    MEM_W(-0X7E00, ctx->r1) = ctx->r4;
    // 0x800AD4E8: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x800AD4EC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_800AD4F0:
    // 0x800AD4F0: jr          $ra
    // 0x800AD4F4: nop

    return;
    // 0x800AD4F4: nop

;}
RECOMP_FUNC void lensflare_override_remove(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD4F8: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800AD4FC: addiu       $a3, $a3, 0x3018
    ctx->r7 = ADD32(ctx->r7, 0X3018);
    // 0x800AD500: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    // 0x800AD504: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AD508: blez        $a1, L_800AD544
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800AD50C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800AD544;
    }
    // 0x800AD50C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800AD510: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800AD514: addiu       $t7, $t7, -0x7E00
    ctx->r15 = ADD32(ctx->r15, -0X7E00);
    // 0x800AD518: sll         $t6, $zero, 2
    ctx->r14 = S32(0 << 2);
    // 0x800AD51C: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
L_800AD520:
    // 0x800AD520: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800AD524: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800AD528: bne         $a0, $t8, L_800AD534
    if (ctx->r4 != ctx->r24) {
        // 0x800AD52C: slt         $at, $v1, $a1
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_800AD534;
    }
    // 0x800AD52C: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800AD530: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800AD534:
    // 0x800AD534: beq         $at, $zero, L_800AD544
    if (ctx->r1 == 0) {
        // 0x800AD538: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_800AD544;
    }
    // 0x800AD538: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800AD53C: beq         $v0, $zero, L_800AD520
    if (ctx->r2 == 0) {
        // 0x800AD540: nop
    
            goto L_800AD520;
    }
    // 0x800AD540: nop

L_800AD544:
    // 0x800AD544: beq         $v0, $zero, L_800AD588
    if (ctx->r2 == 0) {
        // 0x800AD548: addiu       $t9, $a1, -0x1
        ctx->r25 = ADD32(ctx->r5, -0X1);
            goto L_800AD588;
    }
    // 0x800AD548: addiu       $t9, $a1, -0x1
    ctx->r25 = ADD32(ctx->r5, -0X1);
    // 0x800AD54C: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800AD550: slt         $at, $v1, $t9
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800AD554: beq         $at, $zero, L_800AD588
    if (ctx->r1 == 0) {
        // 0x800AD558: sw          $t9, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r25;
            goto L_800AD588;
    }
    // 0x800AD558: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x800AD55C: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800AD560: addiu       $t1, $t1, -0x7E00
    ctx->r9 = ADD32(ctx->r9, -0X7E00);
    // 0x800AD564: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x800AD568: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x800AD56C: addu        $v0, $t2, $t1
    ctx->r2 = ADD32(ctx->r10, ctx->r9);
    // 0x800AD570: addu        $a2, $t0, $t1
    ctx->r6 = ADD32(ctx->r8, ctx->r9);
L_800AD574:
    // 0x800AD574: lw          $t3, 0x4($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X4);
    // 0x800AD578: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800AD57C: sltu        $at, $a2, $v0
    ctx->r1 = ctx->r6 < ctx->r2 ? 1 : 0;
    // 0x800AD580: bne         $at, $zero, L_800AD574
    if (ctx->r1 != 0) {
        // 0x800AD584: sw          $t3, -0x4($a2)
        MEM_W(-0X4, ctx->r6) = ctx->r11;
            goto L_800AD574;
    }
    // 0x800AD584: sw          $t3, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->r11;
L_800AD588:
    // 0x800AD588: jr          $ra
    // 0x800AD58C: nop

    return;
    // 0x800AD58C: nop

;}
RECOMP_FUNC void lensflare_override(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD590: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800AD594: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800AD598: lui         $s6, 0x800E
    ctx->r22 = S32(0X800E << 16);
    // 0x800AD59C: addiu       $s6, $s6, 0x3018
    ctx->r22 = ADD32(ctx->r22, 0X3018);
    // 0x800AD5A0: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800AD5A4: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x800AD5A8: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x800AD5AC: addiu       $s5, $s5, 0x3014
    ctx->r21 = ADD32(ctx->r21, 0X3014);
    // 0x800AD5B0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800AD5B4: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800AD5B8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800AD5BC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800AD5C0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800AD5C4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800AD5C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800AD5CC: blez        $v0, L_800AD67C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800AD5D0: sw          $zero, 0x0($s5)
        MEM_W(0X0, ctx->r21) = 0;
            goto L_800AD67C;
    }
    // 0x800AD5D0: sw          $zero, 0x0($s5)
    MEM_W(0X0, ctx->r21) = 0;
    // 0x800AD5D4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800AD5D8: lw          $t6, 0x3010($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3010);
    // 0x800AD5DC: nop

    // 0x800AD5E0: beq         $t6, $zero, L_800AD680
    if (ctx->r14 == 0) {
        // 0x800AD5E4: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_800AD680;
    }
    // 0x800AD5E4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800AD5E8: blez        $v0, L_800AD67C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800AD5EC: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_800AD67C;
    }
    // 0x800AD5EC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800AD5F0: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800AD5F4: addiu       $s0, $s0, -0x7E00
    ctx->r16 = ADD32(ctx->r16, -0X7E00);
    // 0x800AD5F8: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
L_800AD5FC:
    // 0x800AD5FC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800AD600: lwc1        $f4, 0xC($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0XC);
    // 0x800AD604: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800AD608: lwc1        $f8, 0x10($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X10);
    // 0x800AD60C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800AD610: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800AD614: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800AD618: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800AD61C: lwc1        $f16, 0x14($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X14);
    // 0x800AD620: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800AD624: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800AD628: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800AD62C: lw          $s2, 0x3C($v0)
    ctx->r18 = MEM_W(ctx->r2, 0X3C);
    // 0x800AD630: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800AD634: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800AD638: jal         0x800CA030
    // 0x800AD63C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800AD63C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x800AD640: lh          $t7, 0x8($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X8);
    // 0x800AD644: nop

    // 0x800AD648: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x800AD64C: nop

    // 0x800AD650: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800AD654: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x800AD658: nop

    // 0x800AD65C: bc1f        L_800AD668
    if (!c1cs) {
        // 0x800AD660: nop
    
            goto L_800AD668;
    }
    // 0x800AD660: nop

    // 0x800AD664: sw          $s4, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r20;
L_800AD668:
    // 0x800AD668: lw          $t8, 0x0($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X0);
    // 0x800AD66C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800AD670: slt         $at, $s1, $t8
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800AD674: bne         $at, $zero, L_800AD5FC
    if (ctx->r1 != 0) {
        // 0x800AD678: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800AD5FC;
    }
    // 0x800AD678: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800AD67C:
    // 0x800AD67C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_800AD680:
    // 0x800AD680: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800AD684: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800AD688: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800AD68C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800AD690: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800AD694: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800AD698: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800AD69C: jr          $ra
    // 0x800AD6A0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800AD6A0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void rain_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD6A4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800AD6A8: addiu       $v0, $v0, 0x31F0
    ctx->r2 = ADD32(ctx->r2, 0X31F0);
    // 0x800AD6AC: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x800AD6B0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD6B4: sw          $zero, 0x31F4($at)
    MEM_W(0X31F4, ctx->r1) = 0;
    // 0x800AD6B8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800AD6BC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD6C0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AD6C4: sw          $t6, 0x31F8($at)
    MEM_W(0X31F8, ctx->r1) = ctx->r14;
    // 0x800AD6C8: addiu       $v1, $v1, 0x31FC
    ctx->r3 = ADD32(ctx->r3, 0X31FC);
    // 0x800AD6CC: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800AD6D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD6D4: sw          $zero, 0x3200($at)
    MEM_W(0X3200, ctx->r1) = 0;
    // 0x800AD6D8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800AD6DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD6E0: sw          $t7, 0x3204($at)
    MEM_W(0X3204, ctx->r1) = ctx->r15;
    // 0x800AD6E4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD6E8: sw          $zero, 0x3208($at)
    MEM_W(0X3208, ctx->r1) = 0;
    // 0x800AD6EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD6F0: sw          $zero, 0x320C($at)
    MEM_W(0X320C, ctx->r1) = 0;
    // 0x800AD6F4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD6F8: sw          $zero, 0x3210($at)
    MEM_W(0X3210, ctx->r1) = 0;
    // 0x800AD6FC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD700: sw          $zero, 0x3214($at)
    MEM_W(0X3214, ctx->r1) = 0;
    // 0x800AD704: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800AD708: lw          $t8, 0x2EAC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2EAC);
    // 0x800AD70C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AD710: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD714: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AD718: sw          $zero, 0x3220($at)
    MEM_W(0X3220, ctx->r1) = 0;
    // 0x800AD71C: lw          $a0, 0x4($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X4);
    // 0x800AD720: jal         0x8007B2C4
    // 0x800AD724: nop

    load_texture(rdram, ctx);
        goto after_0;
    // 0x800AD724: nop

    after_0:
    // 0x800AD728: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800AD72C: lw          $t9, 0x2EAC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X2EAC);
    // 0x800AD730: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD734: sw          $v0, 0x31C8($at)
    MEM_W(0X31C8, ctx->r1) = ctx->r2;
    // 0x800AD738: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    // 0x800AD73C: jal         0x8007B2C4
    // 0x800AD740: nop

    load_texture(rdram, ctx);
        goto after_1;
    // 0x800AD740: nop

    after_1:
    // 0x800AD744: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800AD748: lw          $t0, 0x2EAC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2EAC);
    // 0x800AD74C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD750: sw          $v0, 0x31E0($at)
    MEM_W(0X31E0, ctx->r1) = ctx->r2;
    // 0x800AD754: lw          $a0, 0xC($t0)
    ctx->r4 = MEM_W(ctx->r8, 0XC);
    // 0x800AD758: jal         0x8007C57C
    // 0x800AD75C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    tex_load_sprite(rdram, ctx);
        goto after_2;
    // 0x800AD75C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x800AD760: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD764: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AD768: sw          $v0, 0x321C($at)
    MEM_W(0X321C, ctx->r1) = ctx->r2;
    // 0x800AD76C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD770: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800AD774: sw          $t1, 0x31EC($at)
    MEM_W(0X31EC, ctx->r1) = ctx->r9;
    // 0x800AD778: jr          $ra
    // 0x800AD77C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800AD77C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void free_rain_memory(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD780: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AD784: lw          $a0, 0x31C8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C8);
    // 0x800AD788: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AD78C: beq         $a0, $zero, L_800AD7A4
    if (ctx->r4 == 0) {
        // 0x800AD790: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800AD7A4;
    }
    // 0x800AD790: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AD794: jal         0x8007B70C
    // 0x800AD798: nop

    tex_free(rdram, ctx);
        goto after_0;
    // 0x800AD798: nop

    after_0:
    // 0x800AD79C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD7A0: sw          $zero, 0x3218($at)
    MEM_W(0X3218, ctx->r1) = 0;
L_800AD7A4:
    // 0x800AD7A4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AD7A8: lw          $a0, 0x31E0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31E0);
    // 0x800AD7AC: nop

    // 0x800AD7B0: beq         $a0, $zero, L_800AD7C8
    if (ctx->r4 == 0) {
        // 0x800AD7B4: nop
    
            goto L_800AD7C8;
    }
    // 0x800AD7B4: nop

    // 0x800AD7B8: jal         0x8007B70C
    // 0x800AD7BC: nop

    tex_free(rdram, ctx);
        goto after_1;
    // 0x800AD7BC: nop

    after_1:
    // 0x800AD7C0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD7C4: sw          $zero, 0x3218($at)
    MEM_W(0X3218, ctx->r1) = 0;
L_800AD7C8:
    // 0x800AD7C8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AD7CC: lw          $a0, 0x321C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X321C);
    // 0x800AD7D0: nop

    // 0x800AD7D4: beq         $a0, $zero, L_800AD7EC
    if (ctx->r4 == 0) {
        // 0x800AD7D8: nop
    
            goto L_800AD7EC;
    }
    // 0x800AD7D8: nop

    // 0x800AD7DC: jal         0x8007D100
    // 0x800AD7E0: nop

    sprite_free(rdram, ctx);
        goto after_2;
    // 0x800AD7E0: nop

    after_2:
    // 0x800AD7E4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD7E8: sw          $zero, 0x321C($at)
    MEM_W(0X321C, ctx->r1) = 0;
L_800AD7EC:
    // 0x800AD7EC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AD7F0: lw          $a0, 0x3224($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3224);
    // 0x800AD7F4: nop

    // 0x800AD7F8: beq         $a0, $zero, L_800AD814
    if (ctx->r4 == 0) {
        // 0x800AD7FC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800AD814;
    }
    // 0x800AD7FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AD800: jal         0x800096F8
    // 0x800AD804: nop

    audspat_point_stop(rdram, ctx);
        goto after_3;
    // 0x800AD804: nop

    after_3:
    // 0x800AD808: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD80C: sw          $zero, 0x3224($at)
    MEM_W(0X3224, ctx->r1) = 0;
    // 0x800AD810: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800AD814:
    // 0x800AD814: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD818: sw          $zero, 0x31EC($at)
    MEM_W(0X31EC, ctx->r1) = 0;
    // 0x800AD81C: jr          $ra
    // 0x800AD820: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800AD820: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void rain_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD824: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x800AD828: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x800AD82C: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800AD830: bne         $t6, $zero, L_800AD87C
    if (ctx->r14 != 0) {
        // 0x800AD834: lui         $a2, 0x800E
        ctx->r6 = S32(0X800E << 16);
            goto L_800AD87C;
    }
    // 0x800AD834: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800AD838: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x800AD83C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800AD840: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800AD844: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x800AD848: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800AD84C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AD850: addiu       $v1, $v1, 0x3208
    ctx->r3 = ADD32(ctx->r3, 0X3208);
    // 0x800AD854: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800AD858: nop

    // 0x800AD85C: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800AD860: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AD864: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AD868: nop

    // 0x800AD86C: cvt.w.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_D(ctx->f8.d);
    // 0x800AD870: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800AD874: b           L_800AD8C0
    // 0x800AD878: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
        goto L_800AD8C0;
    // 0x800AD878: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
L_800AD87C:
    // 0x800AD87C: lui         $at, 0x404E
    ctx->r1 = S32(0X404E << 16);
    // 0x800AD880: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800AD884: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800AD888: cvt.d.s     $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f16.d = CVT_D_S(ctx->f12.fl);
    // 0x800AD88C: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x800AD890: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AD894: addiu       $v1, $v1, 0x3208
    ctx->r3 = ADD32(ctx->r3, 0X3208);
    // 0x800AD898: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800AD89C: nop

    // 0x800AD8A0: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800AD8A4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AD8A8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AD8AC: nop

    // 0x800AD8B0: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x800AD8B4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800AD8B8: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x800AD8BC: nop

L_800AD8C0:
    // 0x800AD8C0: addiu       $a2, $a2, 0x31F8
    ctx->r6 = ADD32(ctx->r6, 0X31F8);
    // 0x800AD8C4: sw          $a0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r4;
    // 0x800AD8C8: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800AD8CC: lw          $t0, 0x31F0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X31F0);
    // 0x800AD8D0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800AD8D4: subu        $t1, $a0, $t0
    ctx->r9 = SUB32(ctx->r4, ctx->r8);
    // 0x800AD8D8: div         $zero, $t1, $v0
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r2)));
    // 0x800AD8DC: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800AD8E0: addiu       $a3, $a3, 0x3204
    ctx->r7 = ADD32(ctx->r7, 0X3204);
    // 0x800AD8E4: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800AD8E8: or          $t9, $a0, $zero
    ctx->r25 = ctx->r4 | 0;
    // 0x800AD8EC: bne         $v0, $zero, L_800AD8F8
    if (ctx->r2 != 0) {
        // 0x800AD8F0: nop
    
            goto L_800AD8F8;
    }
    // 0x800AD8F0: nop

    // 0x800AD8F4: break       7
    do_break(2148194548);
L_800AD8F8:
    // 0x800AD8F8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AD8FC: bne         $v0, $at, L_800AD910
    if (ctx->r2 != ctx->r1) {
        // 0x800AD900: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800AD910;
    }
    // 0x800AD900: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AD904: bne         $t1, $at, L_800AD910
    if (ctx->r9 != ctx->r1) {
        // 0x800AD908: nop
    
            goto L_800AD910;
    }
    // 0x800AD908: nop

    // 0x800AD90C: break       6
    do_break(2148194572);
L_800AD910:
    // 0x800AD910: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD914: or          $t3, $a1, $zero
    ctx->r11 = ctx->r5 | 0;
    // 0x800AD918: mflo        $t2
    ctx->r10 = lo;
    // 0x800AD91C: sw          $t2, 0x31F4($at)
    MEM_W(0X31F4, ctx->r1) = ctx->r10;
    // 0x800AD920: sw          $a1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r5;
    // 0x800AD924: lw          $t4, 0x31FC($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X31FC);
    // 0x800AD928: nop

    // 0x800AD92C: subu        $t5, $a1, $t4
    ctx->r13 = SUB32(ctx->r5, ctx->r12);
    // 0x800AD930: div         $zero, $t5, $v0
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r2)));
    // 0x800AD934: bne         $v0, $zero, L_800AD940
    if (ctx->r2 != 0) {
        // 0x800AD938: nop
    
            goto L_800AD940;
    }
    // 0x800AD938: nop

    // 0x800AD93C: break       7
    do_break(2148194620);
L_800AD940:
    // 0x800AD940: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AD944: bne         $v0, $at, L_800AD958
    if (ctx->r2 != ctx->r1) {
        // 0x800AD948: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800AD958;
    }
    // 0x800AD948: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AD94C: bne         $t5, $at, L_800AD958
    if (ctx->r13 != ctx->r1) {
        // 0x800AD950: nop
    
            goto L_800AD958;
    }
    // 0x800AD950: nop

    // 0x800AD954: break       6
    do_break(2148194644);
L_800AD958:
    // 0x800AD958: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD95C: mflo        $t6
    ctx->r14 = lo;
    // 0x800AD960: sw          $t6, 0x3200($at)
    MEM_W(0X3200, ctx->r1) = ctx->r14;
    // 0x800AD964: jr          $ra
    // 0x800AD968: nop

    return;
    // 0x800AD968: nop

;}
RECOMP_FUNC void rain_fog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD96C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800AD970: lw          $t6, 0x31EC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X31EC);
    // 0x800AD974: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800AD978: beq         $t6, $zero, L_800AD9FC
    if (ctx->r14 == 0) {
        // 0x800AD97C: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_800AD9FC;
    }
    // 0x800AD97C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800AD980: jal         0x80066450
    // 0x800AD984: nop

    cam_get_viewport_layout(rdram, ctx);
        goto after_0;
    // 0x800AD984: nop

    after_0:
    // 0x800AD988: bne         $v0, $zero, L_800AD9FC
    if (ctx->r2 != 0) {
        // 0x800AD98C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800AD9FC;
    }
    // 0x800AD98C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800AD990: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800AD994: lw          $v0, 0x31F0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31F0);
    // 0x800AD998: addiu       $t2, $zero, 0xF
    ctx->r10 = ADD32(0, 0XF);
    // 0x800AD99C: negu        $at, $v0
    ctx->r1 = SUB32(0, ctx->r2);
    // 0x800AD9A0: sll         $v1, $at, 2
    ctx->r3 = S32(ctx->r1 << 2);
    // 0x800AD9A4: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
    // 0x800AD9A8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800AD9AC: sll         $t0, $at, 2
    ctx->r8 = S32(ctx->r1 << 2);
    // 0x800AD9B0: subu        $v1, $v1, $at
    ctx->r3 = SUB32(ctx->r3, ctx->r1);
    // 0x800AD9B4: addu        $t0, $t0, $at
    ctx->r8 = ADD32(ctx->r8, ctx->r1);
    // 0x800AD9B8: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800AD9BC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800AD9C0: sra         $t7, $v1, 16
    ctx->r15 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800AD9C4: sra         $t8, $t0, 16
    ctx->r24 = S32(SIGNED(ctx->r8) >> 16);
    // 0x800AD9C8: addiu       $v1, $t7, 0x3FA
    ctx->r3 = ADD32(ctx->r15, 0X3FA);
    // 0x800AD9CC: addiu       $t0, $t8, 0x3FF
    ctx->r8 = ADD32(ctx->r24, 0X3FF);
    // 0x800AD9D0: sll         $a2, $t0, 16
    ctx->r6 = S32(ctx->r8 << 16);
    // 0x800AD9D4: sll         $a1, $v1, 16
    ctx->r5 = S32(ctx->r3 << 16);
    // 0x800AD9D8: sra         $t9, $a1, 16
    ctx->r25 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800AD9DC: sra         $t1, $a2, 16
    ctx->r9 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800AD9E0: addiu       $t3, $zero, 0x24
    ctx->r11 = ADD32(0, 0X24);
    // 0x800AD9E4: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800AD9E8: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x800AD9EC: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x800AD9F0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800AD9F4: jal         0x800306A4
    // 0x800AD9F8: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    set_fog(rdram, ctx);
        goto after_1;
    // 0x800AD9F8: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    after_1:
L_800AD9FC:
    // 0x800AD9FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800ADA00: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800ADA04: jr          $ra
    // 0x800ADA08: nop

    return;
    // 0x800ADA08: nop

;}
RECOMP_FUNC void rain_opacity_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ADA0C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800ADA10: jr          $ra
    // 0x800ADA14: sw          $a0, 0x31FC($at)
    MEM_W(0X31FC, ctx->r1) = ctx->r4;
    return;
    // 0x800ADA14: sw          $a0, 0x31FC($at)
    MEM_W(0X31FC, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void rain_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ADA18: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800ADA1C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800ADA20: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800ADA24: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800ADA28: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800ADA2C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800ADA30: jal         0x80066450
    // 0x800ADA34: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    cam_get_viewport_layout(rdram, ctx);
        goto after_0;
    // 0x800ADA34: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x800ADA38: bne         $v0, $zero, L_800ADB9C
    if (ctx->r2 != 0) {
        // 0x800ADA3C: lui         $t6, 0x800E
        ctx->r14 = S32(0X800E << 16);
            goto L_800ADB9C;
    }
    // 0x800ADA3C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800ADA40: lw          $t6, 0x31EC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X31EC);
    // 0x800ADA44: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800ADA48: beq         $t6, $zero, L_800ADB9C
    if (ctx->r14 == 0) {
        // 0x800ADA4C: addiu       $v1, $v1, 0x3208
        ctx->r3 = ADD32(ctx->r3, 0X3208);
            goto L_800ADB9C;
    }
    // 0x800ADA4C: addiu       $v1, $v1, 0x3208
    ctx->r3 = ADD32(ctx->r3, 0X3208);
    // 0x800ADA50: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800ADA54: nop

    // 0x800ADA58: blez        $v0, L_800ADAE8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800ADA5C: slt         $at, $s2, $v0
        ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_800ADAE8;
    }
    // 0x800ADA5C: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800ADA60: beq         $at, $zero, L_800ADAC0
    if (ctx->r1 == 0) {
        // 0x800ADA64: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_800ADAC0;
    }
    // 0x800ADA64: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800ADA68: subu        $t7, $v0, $s2
    ctx->r15 = SUB32(ctx->r2, ctx->r18);
    // 0x800ADA6C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800ADA70: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800ADA74: lw          $t9, 0x31F4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X31F4);
    // 0x800ADA78: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800ADA7C: multu       $t9, $s2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800ADA80: addiu       $s0, $s0, 0x31F0
    ctx->r16 = ADD32(ctx->r16, 0X31F0);
    // 0x800ADA84: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800ADA88: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800ADA8C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800ADA90: addiu       $a0, $a0, 0x31FC
    ctx->r4 = ADD32(ctx->r4, 0X31FC);
    // 0x800ADA94: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x800ADA98: mflo        $t0
    ctx->r8 = lo;
    // 0x800ADA9C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800ADAA0: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x800ADAA4: lw          $t3, 0x3200($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3200);
    // 0x800ADAA8: nop

    // 0x800ADAAC: multu       $t3, $s2
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800ADAB0: mflo        $t4
    ctx->r12 = lo;
    // 0x800ADAB4: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x800ADAB8: b           L_800ADAE8
    // 0x800ADABC: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
        goto L_800ADAE8;
    // 0x800ADABC: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
L_800ADAC0:
    // 0x800ADAC0: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800ADAC4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800ADAC8: lw          $t6, 0x31F8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X31F8);
    // 0x800ADACC: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800ADAD0: addiu       $s0, $s0, 0x31F0
    ctx->r16 = ADD32(ctx->r16, 0X31F0);
    // 0x800ADAD4: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800ADAD8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800ADADC: lw          $t7, 0x3204($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3204);
    // 0x800ADAE0: addiu       $a0, $a0, 0x31FC
    ctx->r4 = ADD32(ctx->r4, 0X31FC);
    // 0x800ADAE4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
L_800ADAE8:
    // 0x800ADAE8: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800ADAEC: addiu       $s0, $s0, 0x31F0
    ctx->r16 = ADD32(ctx->r16, 0X31F0);
    // 0x800ADAF0: jal         0x800AE128
    // 0x800ADAF4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    rain_sound(rdram, ctx);
        goto after_1;
    // 0x800ADAF4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x800ADAF8: jal         0x800ADBB8
    // 0x800ADAFC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    rain_render_splashes(rdram, ctx);
        goto after_2;
    // 0x800ADAFC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x800ADB00: jal         0x800AE018
    // 0x800ADB04: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    rain_lightning(rdram, ctx);
        goto after_3;
    // 0x800ADB04: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_3:
    // 0x800ADB08: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800ADB0C: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800ADB10: slti        $at, $t9, 0x100
    ctx->r1 = SIGNED(ctx->r25) < 0X100 ? 1 : 0;
    // 0x800ADB14: bne         $at, $zero, L_800ADB9C
    if (ctx->r1 != 0) {
        // 0x800ADB18: addiu       $s3, $s3, -0x7E34
        ctx->r19 = ADD32(ctx->r19, -0X7E34);
            goto L_800ADB9C;
    }
    // 0x800ADB18: addiu       $s3, $s3, -0x7E34
    ctx->r19 = ADD32(ctx->r19, -0X7E34);
    // 0x800ADB1C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800ADB20: addiu       $a1, $a1, -0x7E30
    ctx->r5 = ADD32(ctx->r5, -0X7E30);
    // 0x800ADB24: jal         0x8006816C
    // 0x800ADB28: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    mtx_ortho(rdram, ctx);
        goto after_4;
    // 0x800ADB28: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_4:
    // 0x800ADB2C: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800ADB30: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x800ADB34: addiu       $s1, $s1, 0x31EC
    ctx->r17 = ADD32(ctx->r17, 0X31EC);
    // 0x800ADB38: addiu       $s0, $s0, 0x31BC
    ctx->r16 = ADD32(ctx->r16, 0X31BC);
    // 0x800ADB3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800ADB40:
    // 0x800ADB40: jal         0x800AE21C
    // 0x800ADB44: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    rain_render(rdram, ctx);
        goto after_5;
    // 0x800ADB44: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_5:
    // 0x800ADB48: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // 0x800ADB4C: bne         $s0, $s1, L_800ADB40
    if (ctx->r16 != ctx->r17) {
        // 0x800ADB50: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800ADB40;
    }
    // 0x800ADB50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800ADB54: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x800ADB58: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x800ADB5C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800ADB60: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x800ADB64: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800ADB68: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800ADB6C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x800ADB70: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x800ADB74: lui         $t2, 0xFB00
    ctx->r10 = S32(0XFB00 << 16);
    // 0x800ADB78: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x800ADB7C: sw          $t3, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r11;
    // 0x800ADB80: addiu       $t4, $zero, -0x100
    ctx->r12 = ADD32(0, -0X100);
    // 0x800ADB84: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800ADB88: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800ADB8C: jal         0x8007B820
    // 0x800ADB90: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    rendermode_reset(rdram, ctx);
        goto after_6;
    // 0x800ADB90: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    after_6:
    // 0x800ADB94: jal         0x800684EC
    // 0x800ADB98: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    viewport_reset(rdram, ctx);
        goto after_7;
    // 0x800ADB98: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_7:
L_800ADB9C:
    // 0x800ADB9C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800ADBA0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800ADBA4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800ADBA8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800ADBAC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800ADBB0: jr          $ra
    // 0x800ADBB4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800ADBB4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
