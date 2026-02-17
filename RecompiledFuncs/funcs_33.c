#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void set_textbox_display_value(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3698: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C369C: jr          $ra
    // 0x800C36A0: sh          $a0, 0x3C04($at)
    MEM_H(0X3C04, ctx->r1) = ctx->r4;
    return;
    // 0x800C36A0: sh          $a0, 0x3C04($at)
    MEM_H(0X3C04, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void reset_delayed_text(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C36A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C36A8: jr          $ra
    // 0x800C36AC: sw          $zero, 0x3C08($at)
    MEM_W(0X3C08, ctx->r1) = 0;
    return;
    // 0x800C36AC: sw          $zero, 0x3C08($at)
    MEM_W(0X3C08, ctx->r1) = 0;
;}
RECOMP_FUNC void set_delayed_text(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C36B0: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x800C36B4: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x800C36B8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800C36BC: bne         $t6, $zero, L_800C3700
    if (ctx->r14 != 0) {
        // 0x800C36C0: lui         $at, 0x404E
        ctx->r1 = S32(0X404E << 16);
            goto L_800C3700;
    }
    // 0x800C36C0: lui         $at, 0x404E
    ctx->r1 = S32(0X404E << 16);
    // 0x800C36C4: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x800C36C8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800C36CC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800C36D0: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x800C36D4: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800C36D8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800C36DC: nop

    // 0x800C36E0: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800C36E4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C36E8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C36EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C36F0: cvt.w.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_D(ctx->f8.d);
    // 0x800C36F4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800C36F8: b           L_800C3738
    // 0x800C36FC: swc1        $f10, 0x3C08($at)
    MEM_W(0X3C08, ctx->r1) = ctx->f10.u32l;
        goto L_800C3738;
    // 0x800C36FC: swc1        $f10, 0x3C08($at)
    MEM_W(0X3C08, ctx->r1) = ctx->f10.u32l;
L_800C3700:
    // 0x800C3700: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800C3704: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800C3708: cvt.d.s     $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f16.d = CVT_D_S(ctx->f12.fl);
    // 0x800C370C: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x800C3710: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800C3714: nop

    // 0x800C3718: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800C371C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C3720: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C3724: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C3728: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x800C372C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800C3730: swc1        $f6, 0x3C08($at)
    MEM_W(0X3C08, ctx->r1) = ctx->f6.u32l;
    // 0x800C3734: nop

L_800C3738:
    // 0x800C3738: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C373C: jr          $ra
    // 0x800C3740: sw          $a0, 0x3C0C($at)
    MEM_W(0X3C0C, ctx->r1) = ctx->r4;
    return;
    // 0x800C3740: sw          $a0, 0x3C0C($at)
    MEM_W(0X3C0C, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void set_current_text(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3744: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800C3748: lb          $t6, 0x3C00($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X3C00);
    // 0x800C374C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C3750: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C3754: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C3758: beq         $t6, $zero, L_800C393C
    if (ctx->r14 == 0) {
        // 0x800C375C: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_800C393C;
    }
    // 0x800C375C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C3760: bltz        $a0, L_800C393C
    if (SIGNED(ctx->r4) < 0) {
        // 0x800C3764: lui         $t7, 0x8013
        ctx->r15 = S32(0X8013 << 16);
            goto L_800C393C;
    }
    // 0x800C3764: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C3768: lh          $t7, -0x52B0($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X52B0);
    // 0x800C376C: nop

    // 0x800C3770: slt         $at, $a0, $t7
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800C3774: beq         $at, $zero, L_800C3940
    if (ctx->r1 == 0) {
        // 0x800C3778: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_800C3940;
    }
    // 0x800C3778: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800C377C: jal         0x8009F064
    // 0x800C3780: nop

    get_language(rdram, ctx);
        goto after_0;
    // 0x800C3780: nop

    after_0:
    // 0x800C3784: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C3788: beq         $v0, $at, L_800C37AC
    if (ctx->r2 == ctx->r1) {
        // 0x800C378C: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_800C37AC;
    }
    // 0x800C378C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800C3790: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800C3794: beq         $v0, $at, L_800C37B4
    if (ctx->r2 == ctx->r1) {
        // 0x800C3798: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800C37B4;
    }
    // 0x800C3798: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800C379C: beq         $v0, $at, L_800C37BC
    if (ctx->r2 == ctx->r1) {
        // 0x800C37A0: nop
    
            goto L_800C37BC;
    }
    // 0x800C37A0: nop

    // 0x800C37A4: b           L_800C37C4
    // 0x800C37A8: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
        goto L_800C37C4;
    // 0x800C37A8: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
L_800C37AC:
    // 0x800C37AC: b           L_800C37C0
    // 0x800C37B0: addiu       $s0, $s0, 0x55
    ctx->r16 = ADD32(ctx->r16, 0X55);
        goto L_800C37C0;
    // 0x800C37B0: addiu       $s0, $s0, 0x55
    ctx->r16 = ADD32(ctx->r16, 0X55);
L_800C37B4:
    // 0x800C37B4: b           L_800C37C0
    // 0x800C37B8: addiu       $s0, $s0, 0xAA
    ctx->r16 = ADD32(ctx->r16, 0XAA);
        goto L_800C37C0;
    // 0x800C37B8: addiu       $s0, $s0, 0xAA
    ctx->r16 = ADD32(ctx->r16, 0XAA);
L_800C37BC:
    // 0x800C37BC: addiu       $s0, $s0, 0xFF
    ctx->r16 = ADD32(ctx->r16, 0XFF);
L_800C37C0:
    // 0x800C37C0: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
L_800C37C4:
    // 0x800C37C4: and         $a2, $s0, $at
    ctx->r6 = ctx->r16 & ctx->r1;
    // 0x800C37C8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800C37CC: lw          $a1, -0x52C0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X52C0);
    // 0x800C37D0: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x800C37D4: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800C37D8: jal         0x80077190
    // 0x800C37DC: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    asset_load(rdram, ctx);
        goto after_1;
    // 0x800C37DC: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_1:
    // 0x800C37E0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C37E4: lw          $a0, -0x52C0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X52C0);
    // 0x800C37E8: andi        $t9, $s0, 0x1
    ctx->r25 = ctx->r16 & 0X1;
    // 0x800C37EC: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x800C37F0: addu        $v1, $a0, $t2
    ctx->r3 = ADD32(ctx->r4, ctx->r10);
    // 0x800C37F4: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x800C37F8: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x800C37FC: lw          $t3, 0x4($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X4);
    // 0x800C3800: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x800C3804: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x800C3808: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x800C380C: and         $t5, $t0, $a1
    ctx->r13 = ctx->r8 & ctx->r5;
    // 0x800C3810: and         $t4, $t3, $a1
    ctx->r12 = ctx->r11 & ctx->r5;
    // 0x800C3814: beq         $t1, $zero, L_800C387C
    if (ctx->r9 == 0) {
        // 0x800C3818: subu        $a3, $t4, $t5
        ctx->r7 = SUB32(ctx->r12, ctx->r13);
            goto L_800C387C;
    }
    // 0x800C3818: subu        $a3, $t4, $t5
    ctx->r7 = SUB32(ctx->r12, ctx->r13);
    // 0x800C381C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800C3820: addiu       $s0, $s0, -0x526C
    ctx->r16 = ADD32(ctx->r16, -0X526C);
    // 0x800C3824: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x800C3828: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800C382C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800C3830: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x800C3834: lw          $a1, -0x5278($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X5278);
    // 0x800C3838: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800C383C: jal         0x80077190
    // 0x800C3840: xor         $a2, $t0, $t1
    ctx->r6 = ctx->r8 ^ ctx->r9;
    asset_load(rdram, ctx);
        goto after_2;
    // 0x800C3840: xor         $a2, $t0, $t1
    ctx->r6 = ctx->r8 ^ ctx->r9;
    after_2:
    // 0x800C3844: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800C3848: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800C384C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800C3850: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x800C3854: lw          $t2, -0x5278($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5278);
    // 0x800C3858: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C385C: jal         0x800C32C4
    // 0x800C3860: sw          $t2, -0x5270($at)
    MEM_W(-0X5270, ctx->r1) = ctx->r10;
    find_next_subtitle(rdram, ctx);
        goto after_3;
    // 0x800C3860: sw          $t2, -0x5270($at)
    MEM_W(-0X5270, ctx->r1) = ctx->r10;
    after_3:
    // 0x800C3864: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x800C3868: nop

    // 0x800C386C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800C3870: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x800C3874: b           L_800C3948
    // 0x800C3878: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
        goto L_800C3948;
    // 0x800C3878: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
L_800C387C:
    // 0x800C387C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800C3880: addiu       $s0, $s0, -0x529C
    ctx->r16 = ADD32(ctx->r16, -0X529C);
    // 0x800C3884: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x800C3888: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800C388C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800C3890: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x800C3894: lw          $a1, -0x52A8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X52A8);
    // 0x800C3898: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800C389C: xor         $a2, $t0, $t1
    ctx->r6 = ctx->r8 ^ ctx->r9;
    // 0x800C38A0: jal         0x80077190
    // 0x800C38A4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    asset_load(rdram, ctx);
        goto after_4;
    // 0x800C38A4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_4:
    // 0x800C38A8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800C38AC: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800C38B0: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x800C38B4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800C38B8: lw          $t9, -0x52A8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X52A8);
    // 0x800C38BC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C38C0: addiu       $t2, $v1, 0x1
    ctx->r10 = ADD32(ctx->r3, 0X1);
    // 0x800C38C4: addiu       $a0, $a0, -0x52A0
    ctx->r4 = ADD32(ctx->r4, -0X52A0);
    // 0x800C38C8: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x800C38CC: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x800C38D0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C38D4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800C38D8: sb          $zero, -0x52B8($at)
    MEM_B(-0X52B8, ctx->r1) = 0;
    // 0x800C38DC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C38E0: sb          $zero, -0x52BA($at)
    MEM_B(-0X52BA, ctx->r1) = 0;
    // 0x800C38E4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C38E8: sb          $zero, -0x52BC($at)
    MEM_B(-0X52BC, ctx->r1) = 0;
    // 0x800C38EC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C38F0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800C38F4: sb          $t4, -0x52B9($at)
    MEM_B(-0X52B9, ctx->r1) = ctx->r12;
    // 0x800C38F8: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x800C38FC: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800C3900: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800C3904: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x800C3908: addu        $t7, $t6, $a3
    ctx->r15 = ADD32(ctx->r14, ctx->r7);
    // 0x800C390C: addiu       $a1, $a1, -0x52B7
    ctx->r5 = ADD32(ctx->r5, -0X52B7);
    // 0x800C3910: sb          $t5, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r13;
    // 0x800C3914: lbu         $t8, 0x0($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X0);
    // 0x800C3918: nop

    // 0x800C391C: bne         $t8, $zero, L_800C3948
    if (ctx->r24 != 0) {
        // 0x800C3920: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_800C3948;
    }
    // 0x800C3920: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C3924: sh          $zero, -0x52B2($at)
    MEM_H(-0X52B2, ctx->r1) = 0;
    // 0x800C3928: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C392C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C3930: sb          $v0, -0x52B6($at)
    MEM_B(-0X52B6, ctx->r1) = ctx->r2;
    // 0x800C3934: b           L_800C3948
    // 0x800C3938: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
        goto L_800C3948;
    // 0x800C3938: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
L_800C393C:
    // 0x800C393C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
L_800C3940:
    // 0x800C3940: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C3944: sb          $t9, -0x52BC($at)
    MEM_B(-0X52BC, ctx->r1) = ctx->r25;
L_800C3948:
    // 0x800C3948: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C394C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C3950: jr          $ra
    // 0x800C3954: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800C3954: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void textbox_visible(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3958: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800C395C: lb          $t6, 0x3C00($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X3C00);
    // 0x800C3960: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800C3964: beq         $t6, $zero, L_800C3990
    if (ctx->r14 == 0) {
        // 0x800C3968: lui         $t7, 0x8013
        ctx->r15 = S32(0X8013 << 16);
            goto L_800C3990;
    }
    // 0x800C3968: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C396C: lbu         $t7, -0x52B7($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X52B7);
    // 0x800C3970: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800C3974: beq         $t7, $zero, L_800C3990
    if (ctx->r15 == 0) {
        // 0x800C3978: nop
    
            goto L_800C3990;
    }
    // 0x800C3978: nop

    // 0x800C397C: lb          $t8, -0x52B8($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X52B8);
    // 0x800C3980: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800C3984: beq         $t8, $zero, L_800C3990
    if (ctx->r24 == 0) {
        // 0x800C3988: nop
    
            goto L_800C3990;
    }
    // 0x800C3988: nop

    // 0x800C398C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_800C3990:
    // 0x800C3990: jr          $ra
    // 0x800C3994: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800C3994: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void process_onscreen_textbox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3998: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C399C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800C39A0: lb          $t6, 0x3C00($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X3C00);
    // 0x800C39A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C39A8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C39AC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C39B0: beq         $t6, $zero, L_800C3AA8
    if (ctx->r14 == 0) {
        // 0x800C39B4: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_800C3AA8;
    }
    // 0x800C39B4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800C39B8: jal         0x8006ECE0
    // 0x800C39BC: nop

    is_game_paused(rdram, ctx);
        goto after_0;
    // 0x800C39BC: nop

    after_0:
    // 0x800C39C0: bne         $v0, $zero, L_800C39F8
    if (ctx->r2 != 0) {
        // 0x800C39C4: lui         $s0, 0x800E
        ctx->r16 = S32(0X800E << 16);
            goto L_800C39F8;
    }
    // 0x800C39C4: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800C39C8: addiu       $s0, $s0, 0x3C08
    ctx->r16 = ADD32(ctx->r16, 0X3C08);
    // 0x800C39CC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800C39D0: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800C39D4: blez        $v0, L_800C39F8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800C39D8: subu        $t8, $v0, $t7
        ctx->r24 = SUB32(ctx->r2, ctx->r15);
            goto L_800C39F8;
    }
    // 0x800C39D8: subu        $t8, $v0, $t7
    ctx->r24 = SUB32(ctx->r2, ctx->r15);
    // 0x800C39DC: bgtz        $t8, L_800C39F8
    if (SIGNED(ctx->r24) > 0) {
        // 0x800C39E0: sw          $t8, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r24;
            goto L_800C39F8;
    }
    // 0x800C39E0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800C39E4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800C39E8: lw          $a0, 0x3C0C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C0C);
    // 0x800C39EC: jal         0x800C3744
    // 0x800C39F0: nop

    set_current_text(rdram, ctx);
        goto after_1;
    // 0x800C39F0: nop

    after_1:
    // 0x800C39F4: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_800C39F8:
    // 0x800C39F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800C39FC: jal         0x800C3474
    // 0x800C3A00: nop

    process_subtitles(rdram, ctx);
        goto after_2;
    // 0x800C3A00: nop

    after_2:
    // 0x800C3A04: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800C3A08: lbu         $t0, -0x52B7($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X52B7);
    // 0x800C3A0C: nop

    // 0x800C3A10: beq         $t0, $zero, L_800C3AAC
    if (ctx->r8 == 0) {
        // 0x800C3A14: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800C3AAC;
    }
    // 0x800C3A14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C3A18: jal         0x8005A41C
    // 0x800C3A1C: nop

    disable_racer_input(rdram, ctx);
        goto after_3;
    // 0x800C3A1C: nop

    after_3:
    // 0x800C3A20: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800C3A24: addiu       $s1, $s1, -0x52BA
    ctx->r17 = ADD32(ctx->r17, -0X52BA);
    // 0x800C3A28: lb          $v0, 0x0($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X0);
    // 0x800C3A2C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800C3A30: beq         $v0, $zero, L_800C3AA0
    if (ctx->r2 == 0) {
        // 0x800C3A34: addiu       $s0, $s0, -0x52BB
        ctx->r16 = ADD32(ctx->r16, -0X52BB);
            goto L_800C3AA0;
    }
    // 0x800C3A34: addiu       $s0, $s0, -0x52BB
    ctx->r16 = ADD32(ctx->r16, -0X52BB);
    // 0x800C3A38: lb          $t1, 0x0($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X0);
    // 0x800C3A3C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800C3A40: nop

    // 0x800C3A44: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x800C3A48: sb          $t3, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r11;
    // 0x800C3A4C: lb          $t4, 0x0($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X0);
    // 0x800C3A50: nop

    // 0x800C3A54: bgez        $t4, L_800C3A90
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800C3A58: nop
    
            goto L_800C3A90;
    }
    // 0x800C3A58: nop

L_800C3A5C:
    // 0x800C3A5C: jal         0x8000C8B4
    // 0x800C3A60: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    normalise_time(rdram, ctx);
        goto after_4;
    // 0x800C3A60: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_4:
    // 0x800C3A64: lb          $t5, 0x0($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X0);
    // 0x800C3A68: lb          $t7, 0x0($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X0);
    // 0x800C3A6C: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800C3A70: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x800C3A74: lb          $t9, 0x0($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X0);
    // 0x800C3A78: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800C3A7C: bltz        $t9, L_800C3A5C
    if (SIGNED(ctx->r25) < 0) {
        // 0x800C3A80: sb          $t8, 0x0($s1)
        MEM_B(0X0, ctx->r17) = ctx->r24;
            goto L_800C3A5C;
    }
    // 0x800C3A80: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x800C3A84: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C3A88: lb          $v0, -0x52BA($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X52BA);
    // 0x800C3A8C: nop

L_800C3A90:
    // 0x800C3A90: bgtz        $v0, L_800C3AA0
    if (SIGNED(ctx->r2) > 0) {
        // 0x800C3A94: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_800C3AA0;
    }
    // 0x800C3A94: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800C3A98: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C3A9C: sb          $t0, -0x52BC($at)
    MEM_B(-0X52BC, ctx->r1) = ctx->r8;
L_800C3AA0:
    // 0x800C3AA0: jal         0x8009D530
    // 0x800C3AA4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    npc_dialogue_loop(rdram, ctx);
        goto after_5;
    // 0x800C3AA4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_5:
L_800C3AA8:
    // 0x800C3AA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800C3AAC:
    // 0x800C3AAC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800C3AB0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800C3AB4: jr          $ra
    // 0x800C3AB8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800C3AB8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void dialogue_challenge_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3ABC: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x800C3AC0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800C3AC4: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x800C3AC8: addiu       $t7, $zero, 0xF
    ctx->r15 = ADD32(0, 0XF);
    // 0x800C3ACC: addiu       $t8, $zero, 0xB4
    ctx->r24 = ADD32(0, 0XB4);
    // 0x800C3AD0: addiu       $t9, $zero, 0x7D
    ctx->r25 = ADD32(0, 0X7D);
    // 0x800C3AD4: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x800C3AD8: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x800C3ADC: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x800C3AE0: addiu       $t3, $zero, 0xF
    ctx->r11 = ADD32(0, 0XF);
    // 0x800C3AE4: addiu       $t4, $zero, 0x7D
    ctx->r12 = ADD32(0, 0X7D);
    // 0x800C3AE8: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800C3AEC: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800C3AF0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800C3AF4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800C3AF8: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x800C3AFC: sw          $t9, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r25;
    // 0x800C3B00: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x800C3B04: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x800C3B08: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x800C3B0C: sw          $t0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r8;
    // 0x800C3B10: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    // 0x800C3B14: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
    // 0x800C3B18: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
    // 0x800C3B1C: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x800C3B20: sw          $t3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r11;
    // 0x800C3B24: sw          $t2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r10;
    // 0x800C3B28: sw          $t1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r9;
    // 0x800C3B2C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800C3B30: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800C3B34: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x800C3B38: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x800C3B3C: jal         0x800C543C
    // 0x800C3B40: addiu       $a3, $zero, 0xB4
    ctx->r7 = ADD32(0, 0XB4);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_0;
    // 0x800C3B40: addiu       $a3, $zero, 0xB4
    ctx->r7 = ADD32(0, 0XB4);
    after_0:
    // 0x800C3B44: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800C3B48: jal         0x800C54DC
    // 0x800C3B4C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_dialogue_font(rdram, ctx);
        goto after_1;
    // 0x800C3B4C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x800C3B50: addiu       $t5, $zero, 0x80
    ctx->r13 = ADD32(0, 0X80);
    // 0x800C3B54: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800C3B58: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800C3B5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C3B60: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800C3B64: jal         0x800C551C
    // 0x800C3B68: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_2;
    // 0x800C3B68: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_2:
    // 0x800C3B6C: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x800C3B70: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x800C3B74: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x800C3B78: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x800C3B7C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800C3B80: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800C3B84: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800C3B88: jal         0x800C5560
    // 0x800C3B8C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    set_current_text_colour(rdram, ctx);
        goto after_3;
    // 0x800C3B8C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_3:
    // 0x800C3B90: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C3B94: lh          $a0, -0x52B2($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X52B2);
    // 0x800C3B98: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800C3B9C: beq         $a0, $zero, L_800C3C2C
    if (ctx->r4 == 0) {
        // 0x800C3BA0: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800C3C2C;
    }
    // 0x800C3BA0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C3BA4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C3BA8: lw          $v0, -0x52A0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X52A0);
    // 0x800C3BAC: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
    // 0x800C3BB0: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x800C3BB4: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800C3BB8: beq         $s2, $t8, L_800C3C2C
    if (ctx->r18 == ctx->r24) {
        // 0x800C3BBC: andi        $v1, $t8, 0xFF
        ctx->r3 = ctx->r24 & 0XFF;
            goto L_800C3C2C;
    }
    // 0x800C3BBC: andi        $v1, $t8, 0xFF
    ctx->r3 = ctx->r24 & 0XFF;
    // 0x800C3BC0: addiu       $s3, $sp, 0x40
    ctx->r19 = ADD32(ctx->r29, 0X40);
    // 0x800C3BC4: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
L_800C3BC8:
    // 0x800C3BC8: bne         $at, $zero, L_800C3C04
    if (ctx->r1 != 0) {
        // 0x800C3BCC: slti        $at, $v1, 0xD
        ctx->r1 = SIGNED(ctx->r3) < 0XD ? 1 : 0;
            goto L_800C3C04;
    }
    // 0x800C3BCC: slti        $at, $v1, 0xD
    ctx->r1 = SIGNED(ctx->r3) < 0XD ? 1 : 0;
    // 0x800C3BD0: beq         $at, $zero, L_800C3C04
    if (ctx->r1 == 0) {
        // 0x800C3BD4: or          $a1, $s3, $zero
        ctx->r5 = ctx->r19 | 0;
            goto L_800C3C04;
    }
    // 0x800C3BD4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800C3BD8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C3BDC: jal         0x800C3E0C
    // 0x800C3BE0: sw          $a2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r6;
    func_800C38B4(rdram, ctx);
        goto after_4;
    // 0x800C3BE0: sw          $a2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r6;
    after_4:
    // 0x800C3BE4: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800C3BE8: lw          $t9, -0x52A0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X52A0);
    // 0x800C3BEC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C3BF0: addu        $s0, $t9, $v0
    ctx->r16 = ADD32(ctx->r25, ctx->r2);
    // 0x800C3BF4: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    // 0x800C3BF8: lh          $a0, -0x52B2($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X52B2);
    // 0x800C3BFC: lw          $a2, 0x7C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X7C);
    // 0x800C3C00: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_800C3C04:
    // 0x800C3C04: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C3C08: bne         $v1, $at, L_800C3C14
    if (ctx->r3 != ctx->r1) {
        // 0x800C3C0C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800C3C14;
    }
    // 0x800C3C0C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800C3C10: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_800C3C14:
    // 0x800C3C14: beq         $a2, $a0, L_800C3C2C
    if (ctx->r6 == ctx->r4) {
        // 0x800C3C18: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800C3C2C;
    }
    // 0x800C3C18: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800C3C1C: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    // 0x800C3C20: nop

    // 0x800C3C24: bne         $s2, $v1, L_800C3BC8
    if (ctx->r18 != ctx->r3) {
        // 0x800C3C28: slti        $at, $v1, 0x3
        ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
            goto L_800C3BC8;
    }
    // 0x800C3C28: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
L_800C3C2C:
    // 0x800C3C2C: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800C3C30: lw          $t0, -0x52A0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X52A0);
    // 0x800C3C34: addiu       $s3, $sp, 0x40
    ctx->r19 = ADD32(ctx->r29, 0X40);
    // 0x800C3C38: addu        $t1, $t0, $s1
    ctx->r9 = ADD32(ctx->r8, ctx->r17);
    // 0x800C3C3C: lbu         $v1, 0x0($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X0);
    // 0x800C3C40: nop

    // 0x800C3C44: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x800C3C48: bne         $at, $zero, L_800C3C64
    if (ctx->r1 != 0) {
        // 0x800C3C4C: slti        $at, $v1, 0xD
        ctx->r1 = SIGNED(ctx->r3) < 0XD ? 1 : 0;
            goto L_800C3C64;
    }
    // 0x800C3C4C: slti        $at, $v1, 0xD
    ctx->r1 = SIGNED(ctx->r3) < 0XD ? 1 : 0;
    // 0x800C3C50: beq         $at, $zero, L_800C3C64
    if (ctx->r1 == 0) {
        // 0x800C3C54: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800C3C64;
    }
    // 0x800C3C54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C3C58: jal         0x800C3E0C
    // 0x800C3C5C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800C38B4(rdram, ctx);
        goto after_5;
    // 0x800C3C5C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_5:
    // 0x800C3C60: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_800C3C64:
    // 0x800C3C64: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_800C3C68:
    // 0x800C3C68: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800C3C6C: lw          $t2, -0x52A0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X52A0);
    // 0x800C3C70: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x800C3C74: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800C3C78: bne         $t3, $zero, L_800C3C8C
    if (ctx->r11 != 0) {
        // 0x800C3C7C: addu        $s0, $t2, $s1
        ctx->r16 = ADD32(ctx->r10, ctx->r17);
            goto L_800C3C8C;
    }
    // 0x800C3C7C: addu        $s0, $t2, $s1
    ctx->r16 = ADD32(ctx->r10, ctx->r17);
    // 0x800C3C80: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x800C3C84: b           L_800C3CA4
    // 0x800C3C88: nop

        goto L_800C3CA4;
    // 0x800C3C88: nop

L_800C3C8C:
    // 0x800C3C8C: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x800C3C90: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x800C3C94: nop

    // 0x800C3C98: subu        $a1, $t4, $t5
    ctx->r5 = SUB32(ctx->r12, ctx->r13);
    // 0x800C3C9C: sra         $t6, $a1, 1
    ctx->r14 = S32(SIGNED(ctx->r5) >> 1);
    // 0x800C3CA0: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
L_800C3CA4:
    // 0x800C3CA4: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800C3CA8: lh          $t7, 0x3C04($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X3C04);
    // 0x800C3CAC: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x800C3CB0: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800C3CB4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x800C3CB8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800C3CBC: jal         0x800C56C8
    // 0x800C3CC0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    render_dialogue_text(rdram, ctx);
        goto after_6;
    // 0x800C3CC0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_6:
    // 0x800C3CC4: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x800C3CC8: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x800C3CCC: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800C3CD0: lw          $t2, -0x52A0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X52A0);
    // 0x800C3CD4: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800C3CD8: sw          $t1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r9;
    // 0x800C3CDC: addu        $s0, $t2, $s1
    ctx->r16 = ADD32(ctx->r10, ctx->r17);
    // 0x800C3CE0: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    // 0x800C3CE4: nop

    // 0x800C3CE8: blez        $v1, L_800C3D00
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800C3CEC: nop
    
            goto L_800C3D00;
    }
    // 0x800C3CEC: nop

L_800C3CF0:
    // 0x800C3CF0: lbu         $v1, 0x1($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X1);
    // 0x800C3CF4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800C3CF8: bgtz        $v1, L_800C3CF0
    if (SIGNED(ctx->r3) > 0) {
        // 0x800C3CFC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800C3CF0;
    }
    // 0x800C3CFC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800C3D00:
    // 0x800C3D00: bne         $v1, $zero, L_800C3D1C
    if (ctx->r3 != 0) {
        // 0x800C3D04: slti        $at, $v1, 0x3
        ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
            goto L_800C3D1C;
    }
    // 0x800C3D04: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
L_800C3D08:
    // 0x800C3D08: lbu         $v1, 0x1($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X1);
    // 0x800C3D0C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800C3D10: beq         $v1, $zero, L_800C3D08
    if (ctx->r3 == 0) {
        // 0x800C3D14: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800C3D08;
    }
    // 0x800C3D14: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800C3D18: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
L_800C3D1C:
    // 0x800C3D1C: beq         $at, $zero, L_800C3D2C
    if (ctx->r1 == 0) {
        // 0x800C3D20: slti        $at, $v1, 0x3
        ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
            goto L_800C3D2C;
    }
    // 0x800C3D20: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x800C3D24: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800C3D28: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
L_800C3D2C:
    // 0x800C3D2C: bne         $at, $zero, L_800C3D48
    if (ctx->r1 != 0) {
        // 0x800C3D30: slti        $at, $v1, 0xD
        ctx->r1 = SIGNED(ctx->r3) < 0XD ? 1 : 0;
            goto L_800C3D48;
    }
    // 0x800C3D30: slti        $at, $v1, 0xD
    ctx->r1 = SIGNED(ctx->r3) < 0XD ? 1 : 0;
    // 0x800C3D34: beq         $at, $zero, L_800C3D48
    if (ctx->r1 == 0) {
        // 0x800C3D38: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800C3D48;
    }
    // 0x800C3D38: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C3D3C: jal         0x800C3E0C
    // 0x800C3D40: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800C38B4(rdram, ctx);
        goto after_7;
    // 0x800C3D40: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_7:
    // 0x800C3D44: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_800C3D48:
    // 0x800C3D48: bne         $s2, $zero, L_800C3C68
    if (ctx->r18 != 0) {
        // 0x800C3D4C: nop
    
            goto L_800C3C68;
    }
    // 0x800C3D4C: nop

    // 0x800C3D50: jal         0x8006A794
    // 0x800C3D54: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    input_pressed(rdram, ctx);
        goto after_8;
    // 0x800C3D54: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_8:
    // 0x800C3D58: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800C3D5C: lb          $t3, -0x52B9($t3)
    ctx->r11 = MEM_B(ctx->r11, -0X52B9);
    // 0x800C3D60: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800C3D64: bne         $t3, $zero, L_800C3D70
    if (ctx->r11 != 0) {
        // 0x800C3D68: lui         $s0, 0x8013
        ctx->r16 = S32(0X8013 << 16);
            goto L_800C3D70;
    }
    // 0x800C3D68: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800C3D6C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800C3D70:
    // 0x800C3D70: addiu       $s0, $s0, -0x52B6
    ctx->r16 = ADD32(ctx->r16, -0X52B6);
    // 0x800C3D74: lbu         $t4, 0x0($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X0);
    // 0x800C3D78: andi        $t5, $v1, 0x8000
    ctx->r13 = ctx->r3 & 0X8000;
    // 0x800C3D7C: bne         $t4, $zero, L_800C3DEC
    if (ctx->r12 != 0) {
        // 0x800C3D80: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800C3DEC;
    }
    // 0x800C3D80: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800C3D84: bne         $t5, $zero, L_800C3D98
    if (ctx->r13 != 0) {
        // 0x800C3D88: lui         $t6, 0x8013
        ctx->r14 = S32(0X8013 << 16);
            goto L_800C3D98;
    }
    // 0x800C3D88: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C3D8C: lb          $t6, -0x52BC($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X52BC);
    // 0x800C3D90: nop

    // 0x800C3D94: beq         $t6, $zero, L_800C3DE8
    if (ctx->r14 == 0) {
        // 0x800C3D98: lui         $t7, 0x8013
        ctx->r15 = S32(0X8013 << 16);
            goto L_800C3DE8;
    }
L_800C3D98:
    // 0x800C3D98: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C3D9C: lw          $t7, -0x52A0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X52A0);
    // 0x800C3DA0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C3DA4: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x800C3DA8: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x800C3DAC: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800C3DB0: bne         $t9, $at, L_800C3DCC
    if (ctx->r25 != ctx->r1) {
        // 0x800C3DB4: addiu       $a0, $zero, 0x3
        ctx->r4 = ADD32(0, 0X3);
            goto L_800C3DCC;
    }
    // 0x800C3DB4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800C3DB8: lh          $t0, -0x52B2($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X52B2);
    // 0x800C3DBC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C3DC0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800C3DC4: b           L_800C3DD8
    // 0x800C3DC8: sh          $t1, -0x52B2($at)
    MEM_H(-0X52B2, ctx->r1) = ctx->r9;
        goto L_800C3DD8;
    // 0x800C3DC8: sh          $t1, -0x52B2($at)
    MEM_H(-0X52B2, ctx->r1) = ctx->r9;
L_800C3DCC:
    // 0x800C3DCC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C3DD0: jal         0x8009D4AC
    // 0x800C3DD4: sb          $zero, -0x52B7($at)
    MEM_B(-0X52B7, ctx->r1) = 0;
    dialogue_npc_finish(rdram, ctx);
        goto after_9;
    // 0x800C3DD4: sb          $zero, -0x52B7($at)
    MEM_B(-0X52B7, ctx->r1) = 0;
    after_9:
L_800C3DD8:
    // 0x800C3DD8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C3DDC: sb          $zero, -0x52BC($at)
    MEM_B(-0X52BC, ctx->r1) = 0;
    // 0x800C3DE0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C3DE4: sb          $zero, -0x52BA($at)
    MEM_B(-0X52BA, ctx->r1) = 0;
L_800C3DE8:
    // 0x800C3DE8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800C3DEC:
    // 0x800C3DEC: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x800C3DF0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800C3DF4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800C3DF8: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x800C3DFC: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x800C3E00: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x800C3E04: jr          $ra
    // 0x800C3E08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800C3E08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_800C38B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3E0C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800C3E10: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800C3E14: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800C3E18: addiu       $s3, $s3, -0x52A0
    ctx->r19 = ADD32(ctx->r19, -0X52A0);
    // 0x800C3E1C: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x800C3E20: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800C3E24: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800C3E28: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800C3E2C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800C3E30: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800C3E34: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800C3E38: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800C3E3C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800C3E40: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800C3E44: addu        $s0, $t6, $a0
    ctx->r16 = ADD32(ctx->r14, ctx->r4);
    // 0x800C3E48: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800C3E4C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800C3E50: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x800C3E54: bne         $at, $zero, L_800C4120
    if (ctx->r1 != 0) {
        // 0x800C3E58: or          $s2, $a1, $zero
        ctx->r18 = ctx->r5 | 0;
            goto L_800C4120;
    }
    // 0x800C3E58: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800C3E5C: slti        $at, $v0, 0xD
    ctx->r1 = SIGNED(ctx->r2) < 0XD ? 1 : 0;
    // 0x800C3E60: beq         $at, $zero, L_800C4120
    if (ctx->r1 == 0) {
        // 0x800C3E64: addiu       $fp, $zero, 0x4
        ctx->r30 = ADD32(0, 0X4);
            goto L_800C4120;
    }
    // 0x800C3E64: addiu       $fp, $zero, 0x4
    ctx->r30 = ADD32(0, 0X4);
    // 0x800C3E68: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x800C3E6C: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x800C3E70: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x800C3E74: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800C3E78: addiu       $s4, $s4, -0x52BA
    ctx->r20 = ADD32(ctx->r20, -0X52BA);
    // 0x800C3E7C: addiu       $s5, $s5, -0x52B8
    ctx->r21 = ADD32(ctx->r21, -0X52B8);
    // 0x800C3E80: addiu       $s6, $s6, -0x52B9
    ctx->r22 = ADD32(ctx->r22, -0X52B9);
    // 0x800C3E84: addiu       $s7, $s7, -0x52BB
    ctx->r23 = ADD32(ctx->r23, -0X52BB);
    // 0x800C3E88: addiu       $t7, $v0, -0x3
    ctx->r15 = ADD32(ctx->r2, -0X3);
L_800C3E8C:
    // 0x800C3E8C: sltiu       $at, $t7, 0xA
    ctx->r1 = ctx->r15 < 0XA ? 1 : 0;
    // 0x800C3E90: beq         $at, $zero, L_800C410C
    if (ctx->r1 == 0) {
        // 0x800C3E94: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_800C410C;
    }
    // 0x800C3E94: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800C3E98: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C3E9C: addu        $at, $at, $t7
    gpr jr_addend_800C3EA8 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800C3EA0: lw          $t7, -0x6750($at)
    ctx->r15 = ADD32(ctx->r1, -0X6750);
    // 0x800C3EA4: nop

    // 0x800C3EA8: jr          $t7
    // 0x800C3EAC: nop

    switch (jr_addend_800C3EA8 >> 2) {
        case 0: goto L_800C3EB0; break;
        case 1: goto L_800C3EDC; break;
        case 2: goto L_800C3F88; break;
        case 3: goto L_800C4000; break;
        case 4: goto L_800C4034; break;
        case 5: goto L_800C4058; break;
        case 6: goto L_800C4084; break;
        case 7: goto L_800C40A8; break;
        case 8: goto L_800C40E0; break;
        case 9: goto L_800C40F8; break;
        default: switch_error(__func__, 0x800C3EA8, 0x800E98B0);
    }
    // 0x800C3EAC: nop

L_800C3EB0:
    // 0x800C3EB0: lbu         $a1, 0x1($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1);
    // 0x800C3EB4: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800C3EB8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800C3EBC: jal         0x800C54DC
    // 0x800C3EC0: sw          $a1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r5;
    set_dialogue_font(rdram, ctx);
        goto after_0;
    // 0x800C3EC0: sw          $a1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r5;
    after_0:
    // 0x800C3EC4: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x800C3EC8: nop

    // 0x800C3ECC: addu        $s0, $t9, $s1
    ctx->r16 = ADD32(ctx->r25, ctx->r17);
    // 0x800C3ED0: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800C3ED4: b           L_800C4110
    // 0x800C3ED8: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
        goto L_800C4110;
    // 0x800C3ED8: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
L_800C3EDC:
    // 0x800C3EDC: lbu         $t1, 0x1($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X1);
    // 0x800C3EE0: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x800C3EE4: sw          $t1, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r9;
    // 0x800C3EE8: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x800C3EEC: addiu       $at, $zero, 0xF0
    ctx->r1 = ADD32(0, 0XF0);
    // 0x800C3EF0: addu        $t3, $s1, $t2
    ctx->r11 = ADD32(ctx->r17, ctx->r10);
    // 0x800C3EF4: lbu         $t5, 0x2($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0X2);
    // 0x800C3EF8: nop

    // 0x800C3EFC: sw          $t5, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r13;
    // 0x800C3F00: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x800C3F04: sll         $t7, $t5, 5
    ctx->r15 = S32(ctx->r13 << 5);
    // 0x800C3F08: bne         $t6, $zero, L_800C3F28
    if (ctx->r14 != 0) {
        // 0x800C3F0C: addu        $t7, $t7, $t5
        ctx->r15 = ADD32(ctx->r15, ctx->r13);
            goto L_800C3F28;
    }
    // 0x800C3F0C: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x800C3F10: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C3F14: div         $zero, $t7, $at
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r1)));
    // 0x800C3F18: mflo        $a2
    ctx->r6 = lo;
    // 0x800C3F1C: sw          $a2, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r6;
    // 0x800C3F20: b           L_800C3F30
    // 0x800C3F24: subu        $v0, $a2, $t5
    ctx->r2 = SUB32(ctx->r6, ctx->r13);
        goto L_800C3F30;
    // 0x800C3F24: subu        $v0, $a2, $t5
    ctx->r2 = SUB32(ctx->r6, ctx->r13);
L_800C3F28:
    // 0x800C3F28: lw          $a2, 0x8($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X8);
    // 0x800C3F2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C3F30:
    // 0x800C3F30: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x800C3F34: lw          $a1, 0x4($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X4);
    // 0x800C3F38: addu        $t0, $s1, $t9
    ctx->r8 = ADD32(ctx->r17, ctx->r25);
    // 0x800C3F3C: lbu         $t2, 0x3($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X3);
    // 0x800C3F40: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800C3F44: addiu       $a3, $t2, 0x41
    ctx->r7 = ADD32(ctx->r10, 0X41);
    // 0x800C3F48: sw          $a3, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r7;
    // 0x800C3F4C: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x800C3F50: nop

    // 0x800C3F54: addu        $t5, $s1, $t4
    ctx->r13 = ADD32(ctx->r17, ctx->r12);
    // 0x800C3F58: lbu         $t7, 0x4($t5)
    ctx->r15 = MEM_BU(ctx->r13, 0X4);
    // 0x800C3F5C: addiu       $s1, $s1, 0x5
    ctx->r17 = ADD32(ctx->r17, 0X5);
    // 0x800C3F60: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C3F64: sw          $t8, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r24;
    // 0x800C3F68: jal         0x800C543C
    // 0x800C3F6C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_1;
    // 0x800C3F6C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_1:
    // 0x800C3F70: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x800C3F74: nop

    // 0x800C3F78: addu        $s0, $t0, $s1
    ctx->r16 = ADD32(ctx->r8, ctx->r17);
    // 0x800C3F7C: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800C3F80: b           L_800C4110
    // 0x800C3F84: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
        goto L_800C4110;
    // 0x800C3F84: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
L_800C3F88:
    // 0x800C3F88: lbu         $a1, 0x1($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1);
    // 0x800C3F8C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800C3F90: sw          $a1, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r5;
    // 0x800C3F94: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x800C3F98: nop

    // 0x800C3F9C: addu        $t3, $s1, $t2
    ctx->r11 = ADD32(ctx->r17, ctx->r10);
    // 0x800C3FA0: lbu         $a2, 0x2($t3)
    ctx->r6 = MEM_BU(ctx->r11, 0X2);
    // 0x800C3FA4: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800C3FA8: sw          $a2, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r6;
    // 0x800C3FAC: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x800C3FB0: nop

    // 0x800C3FB4: addu        $t6, $s1, $t5
    ctx->r14 = ADD32(ctx->r17, ctx->r13);
    // 0x800C3FB8: lbu         $a3, 0x3($t6)
    ctx->r7 = MEM_BU(ctx->r14, 0X3);
    // 0x800C3FBC: nop

    // 0x800C3FC0: sw          $a3, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r7;
    // 0x800C3FC4: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x800C3FC8: nop

    // 0x800C3FCC: addu        $t9, $s1, $t8
    ctx->r25 = ADD32(ctx->r17, ctx->r24);
    // 0x800C3FD0: lbu         $t0, 0x4($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X4);
    // 0x800C3FD4: addiu       $s1, $s1, 0x5
    ctx->r17 = ADD32(ctx->r17, 0X5);
    // 0x800C3FD8: sw          $t0, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r8;
    // 0x800C3FDC: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x800C3FE0: jal         0x800C5560
    // 0x800C3FE4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    set_current_text_colour(rdram, ctx);
        goto after_2;
    // 0x800C3FE4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_2:
    // 0x800C3FE8: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    // 0x800C3FEC: nop

    // 0x800C3FF0: addu        $s0, $t3, $s1
    ctx->r16 = ADD32(ctx->r11, ctx->r17);
    // 0x800C3FF4: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800C3FF8: b           L_800C4110
    // 0x800C3FFC: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
        goto L_800C4110;
    // 0x800C3FFC: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
L_800C4000:
    // 0x800C4000: lbu         $t4, 0x1($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X1);
    // 0x800C4004: nop

    // 0x800C4008: bne         $t4, $zero, L_800C4018
    if (ctx->r12 != 0) {
        // 0x800C400C: nop
    
            goto L_800C4018;
    }
    // 0x800C400C: nop

    // 0x800C4010: b           L_800C401C
    // 0x800C4014: sw          $fp, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r30;
        goto L_800C401C;
    // 0x800C4014: sw          $fp, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r30;
L_800C4018:
    // 0x800C4018: sw          $zero, 0x24($s2)
    MEM_W(0X24, ctx->r18) = 0;
L_800C401C:
    // 0x800C401C: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x800C4020: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800C4024: addu        $s0, $t5, $s1
    ctx->r16 = ADD32(ctx->r13, ctx->r17);
    // 0x800C4028: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800C402C: b           L_800C4110
    // 0x800C4030: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
        goto L_800C4110;
    // 0x800C4030: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
L_800C4034:
    // 0x800C4034: lbu         $t6, 0x1($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X1);
    // 0x800C4038: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800C403C: sw          $t6, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->r14;
    // 0x800C4040: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x800C4044: nop

    // 0x800C4048: addu        $s0, $t7, $s1
    ctx->r16 = ADD32(ctx->r15, ctx->r17);
    // 0x800C404C: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800C4050: b           L_800C4110
    // 0x800C4054: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
        goto L_800C4110;
    // 0x800C4054: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
L_800C4058:
    // 0x800C4058: lw          $t8, 0x2C($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X2C);
    // 0x800C405C: lbu         $t9, 0x1($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1);
    // 0x800C4060: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800C4064: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800C4068: sw          $t0, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r8;
    // 0x800C406C: lw          $t1, 0x0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X0);
    // 0x800C4070: nop

    // 0x800C4074: addu        $s0, $t1, $s1
    ctx->r16 = ADD32(ctx->r9, ctx->r17);
    // 0x800C4078: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800C407C: b           L_800C4110
    // 0x800C4080: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
        goto L_800C4110;
    // 0x800C4080: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
L_800C4084:
    // 0x800C4084: lbu         $t2, 0x1($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X1);
    // 0x800C4088: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800C408C: sw          $t2, 0x30($s2)
    MEM_W(0X30, ctx->r18) = ctx->r10;
    // 0x800C4090: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    // 0x800C4094: nop

    // 0x800C4098: addu        $s0, $t3, $s1
    ctx->r16 = ADD32(ctx->r11, ctx->r17);
    // 0x800C409C: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800C40A0: b           L_800C4110
    // 0x800C40A4: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
        goto L_800C4110;
    // 0x800C40A4: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
L_800C40A8:
    // 0x800C40A8: lb          $t4, 0x0($s4)
    ctx->r12 = MEM_B(ctx->r20, 0X0);
    // 0x800C40AC: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    // 0x800C40B0: bne         $t4, $zero, L_800C40D0
    if (ctx->r12 != 0) {
        // 0x800C40B4: nop
    
            goto L_800C40D0;
    }
    // 0x800C40B4: nop

    // 0x800C40B8: lbu         $t6, 0x1($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X1);
    // 0x800C40BC: jal         0x8000C8B4
    // 0x800C40C0: sb          $t6, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r14;
    normalise_time(rdram, ctx);
        goto after_3;
    // 0x800C40C0: sb          $t6, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r14;
    after_3:
    // 0x800C40C4: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x800C40C8: sb          $v0, 0x0($s7)
    MEM_B(0X0, ctx->r23) = ctx->r2;
    // 0x800C40CC: addu        $s0, $t7, $s1
    ctx->r16 = ADD32(ctx->r15, ctx->r17);
L_800C40D0:
    // 0x800C40D0: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
    // 0x800C40D4: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800C40D8: b           L_800C410C
    // 0x800C40DC: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
        goto L_800C410C;
    // 0x800C40DC: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
L_800C40E0:
    // 0x800C40E0: lbu         $t8, 0x1($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1);
    // 0x800C40E4: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800C40E8: sb          $t8, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r24;
    // 0x800C40EC: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
    // 0x800C40F0: b           L_800C410C
    // 0x800C40F4: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
        goto L_800C410C;
    // 0x800C40F4: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
L_800C40F8:
    // 0x800C40F8: lbu         $t9, 0x1($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1);
    // 0x800C40FC: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800C4100: sb          $t9, 0x0($s5)
    MEM_B(0X0, ctx->r21) = ctx->r25;
    // 0x800C4104: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
    // 0x800C4108: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
L_800C410C:
    // 0x800C410C: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
L_800C4110:
    // 0x800C4110: bne         $at, $zero, L_800C4120
    if (ctx->r1 != 0) {
        // 0x800C4114: slti        $at, $v0, 0xD
        ctx->r1 = SIGNED(ctx->r2) < 0XD ? 1 : 0;
            goto L_800C4120;
    }
    // 0x800C4114: slti        $at, $v0, 0xD
    ctx->r1 = SIGNED(ctx->r2) < 0XD ? 1 : 0;
    // 0x800C4118: bne         $at, $zero, L_800C3E8C
    if (ctx->r1 != 0) {
        // 0x800C411C: addiu       $t7, $v0, -0x3
        ctx->r15 = ADD32(ctx->r2, -0X3);
            goto L_800C3E8C;
    }
    // 0x800C411C: addiu       $t7, $v0, -0x3
    ctx->r15 = ADD32(ctx->r2, -0X3);
L_800C4120:
    // 0x800C4120: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800C4124: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x800C4128: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800C412C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800C4130: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800C4134: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800C4138: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800C413C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800C4140: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800C4144: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800C4148: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800C414C: jr          $ra
    // 0x800C4150: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800C4150: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800C4154: nop

    // 0x800C4158: nop

    // 0x800C415C: nop

;}
RECOMP_FUNC void load_fonts(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4160: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C4164: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C4168: jal         0x80076EE4
    // 0x800C416C: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    asset_table_load(rdram, ctx);
        goto after_0;
    // 0x800C416C: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    after_0:
    // 0x800C4170: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800C4174: addiu       $v1, $v1, -0x525C
    ctx->r3 = ADD32(ctx->r3, -0X525C);
    // 0x800C4178: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800C417C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800C4180: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C4184: addiu       $a0, $a0, -0x5260
    ctx->r4 = ADD32(ctx->r4, -0X5260);
    // 0x800C4188: addiu       $t7, $v0, 0x4
    ctx->r15 = ADD32(ctx->r2, 0X4);
    // 0x800C418C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800C4190: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C4194: blez        $t6, L_800C41C4
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800C4198: sw          $t6, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r14;
            goto L_800C41C4;
    }
    // 0x800C4198: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800C419C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C41A0:
    // 0x800C41A0: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C41A4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800C41A8: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x800C41AC: sb          $zero, 0x28($t3)
    MEM_B(0X28, ctx->r11) = 0;
    // 0x800C41B0: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x800C41B4: addiu       $v0, $v0, 0x400
    ctx->r2 = ADD32(ctx->r2, 0X400);
    // 0x800C41B8: slt         $at, $a1, $t4
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800C41BC: bne         $at, $zero, L_800C41A0
    if (ctx->r1 != 0) {
        // 0x800C41C0: nop
    
            goto L_800C41A0;
    }
    // 0x800C41C0: nop

L_800C41C4:
    // 0x800C41C4: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x800C41C8: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x800C41CC: jal         0x80070EDC
    // 0x800C41D0: addiu       $a0, $zero, 0x940
    ctx->r4 = ADD32(0, 0X940);
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x800C41D0: addiu       $a0, $zero, 0x940
    ctx->r4 = ADD32(0, 0X940);
    after_1:
    // 0x800C41D4: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800C41D8: addiu       $a2, $a2, -0x5258
    ctx->r6 = ADD32(ctx->r6, -0X5258);
    // 0x800C41DC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800C41E0: addiu       $t6, $v0, 0x140
    ctx->r14 = ADD32(ctx->r2, 0X140);
    // 0x800C41E4: addiu       $v1, $v1, -0x5254
    ctx->r3 = ADD32(ctx->r3, -0X5254);
    // 0x800C41E8: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x800C41EC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800C41F0: addiu       $v0, $zero, 0x13F
    ctx->r2 = ADD32(0, 0X13F);
    // 0x800C41F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C41F8: addiu       $t2, $zero, 0x4000
    ctx->r10 = ADD32(0, 0X4000);
    // 0x800C41FC: addiu       $t1, $zero, 0xF0
    ctx->r9 = ADD32(0, 0XF0);
    // 0x800C4200: addiu       $t0, $zero, 0x140
    ctx->r8 = ADD32(0, 0X140);
    // 0x800C4204: addiu       $a3, $zero, 0xEF
    ctx->r7 = ADD32(0, 0XEF);
    // 0x800C4208: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_800C420C:
    // 0x800C420C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800C4210: nop

    // 0x800C4214: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x800C4218: sh          $zero, 0x0($t8)
    MEM_H(0X0, ctx->r24) = 0;
    // 0x800C421C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800C4220: nop

    // 0x800C4224: addu        $t3, $t9, $a1
    ctx->r11 = ADD32(ctx->r25, ctx->r5);
    // 0x800C4228: sh          $zero, 0x2($t3)
    MEM_H(0X2, ctx->r11) = 0;
    // 0x800C422C: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x800C4230: nop

    // 0x800C4234: addu        $t5, $t4, $a1
    ctx->r13 = ADD32(ctx->r12, ctx->r5);
    // 0x800C4238: sh          $zero, 0x4($t5)
    MEM_H(0X4, ctx->r13) = 0;
    // 0x800C423C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800C4240: nop

    // 0x800C4244: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x800C4248: sh          $zero, 0x6($t7)
    MEM_H(0X6, ctx->r15) = 0;
    // 0x800C424C: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800C4250: nop

    // 0x800C4254: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x800C4258: sh          $v0, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r2;
    // 0x800C425C: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x800C4260: nop

    // 0x800C4264: addu        $t4, $t3, $a1
    ctx->r12 = ADD32(ctx->r11, ctx->r5);
    // 0x800C4268: sh          $a3, 0xA($t4)
    MEM_H(0XA, ctx->r12) = ctx->r7;
    // 0x800C426C: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x800C4270: nop

    // 0x800C4274: addu        $t6, $t5, $a1
    ctx->r14 = ADD32(ctx->r13, ctx->r5);
    // 0x800C4278: sh          $t0, 0xC($t6)
    MEM_H(0XC, ctx->r14) = ctx->r8;
    // 0x800C427C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800C4280: nop

    // 0x800C4284: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x800C4288: sh          $t1, 0xE($t8)
    MEM_H(0XE, ctx->r24) = ctx->r9;
    // 0x800C428C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800C4290: nop

    // 0x800C4294: addu        $t3, $t9, $a1
    ctx->r11 = ADD32(ctx->r25, ctx->r5);
    // 0x800C4298: sb          $a0, 0x10($t3)
    MEM_B(0X10, ctx->r11) = ctx->r4;
    // 0x800C429C: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x800C42A0: nop

    // 0x800C42A4: addu        $t5, $t4, $a1
    ctx->r13 = ADD32(ctx->r12, ctx->r5);
    // 0x800C42A8: sb          $a0, 0x11($t5)
    MEM_B(0X11, ctx->r13) = ctx->r4;
    // 0x800C42AC: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800C42B0: nop

    // 0x800C42B4: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x800C42B8: sb          $a0, 0x12($t7)
    MEM_B(0X12, ctx->r15) = ctx->r4;
    // 0x800C42BC: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800C42C0: nop

    // 0x800C42C4: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x800C42C8: sb          $zero, 0x13($t9)
    MEM_B(0X13, ctx->r25) = 0;
    // 0x800C42CC: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x800C42D0: nop

    // 0x800C42D4: addu        $t4, $t3, $a1
    ctx->r12 = ADD32(ctx->r11, ctx->r5);
    // 0x800C42D8: sb          $a0, 0x14($t4)
    MEM_B(0X14, ctx->r12) = ctx->r4;
    // 0x800C42DC: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x800C42E0: nop

    // 0x800C42E4: addu        $t6, $t5, $a1
    ctx->r14 = ADD32(ctx->r13, ctx->r5);
    // 0x800C42E8: sb          $a0, 0x15($t6)
    MEM_B(0X15, ctx->r14) = ctx->r4;
    // 0x800C42EC: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800C42F0: nop

    // 0x800C42F4: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x800C42F8: sb          $a0, 0x16($t8)
    MEM_B(0X16, ctx->r24) = ctx->r4;
    // 0x800C42FC: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800C4300: nop

    // 0x800C4304: addu        $t3, $t9, $a1
    ctx->r11 = ADD32(ctx->r25, ctx->r5);
    // 0x800C4308: sb          $zero, 0x17($t3)
    MEM_B(0X17, ctx->r11) = 0;
    // 0x800C430C: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x800C4310: nop

    // 0x800C4314: addu        $t5, $t4, $a1
    ctx->r13 = ADD32(ctx->r12, ctx->r5);
    // 0x800C4318: sb          $a0, 0x18($t5)
    MEM_B(0X18, ctx->r13) = ctx->r4;
    // 0x800C431C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800C4320: nop

    // 0x800C4324: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x800C4328: sb          $a0, 0x19($t7)
    MEM_B(0X19, ctx->r15) = ctx->r4;
    // 0x800C432C: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800C4330: nop

    // 0x800C4334: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x800C4338: sb          $a0, 0x1A($t9)
    MEM_B(0X1A, ctx->r25) = ctx->r4;
    // 0x800C433C: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x800C4340: nop

    // 0x800C4344: addu        $t4, $t3, $a1
    ctx->r12 = ADD32(ctx->r11, ctx->r5);
    // 0x800C4348: sb          $zero, 0x1B($t4)
    MEM_B(0X1B, ctx->r12) = 0;
    // 0x800C434C: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x800C4350: nop

    // 0x800C4354: addu        $t6, $t5, $a1
    ctx->r14 = ADD32(ctx->r13, ctx->r5);
    // 0x800C4358: sb          $a0, 0x1C($t6)
    MEM_B(0X1C, ctx->r14) = ctx->r4;
    // 0x800C435C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800C4360: nop

    // 0x800C4364: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x800C4368: beq         $a1, $zero, L_800C4384
    if (ctx->r5 == 0) {
        // 0x800C436C: sb          $a0, 0x1D($t8)
        MEM_B(0X1D, ctx->r24) = ctx->r4;
            goto L_800C4384;
    }
    // 0x800C436C: sb          $a0, 0x1D($t8)
    MEM_B(0X1D, ctx->r24) = ctx->r4;
    // 0x800C4370: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800C4374: nop

    // 0x800C4378: addu        $t3, $t9, $a1
    ctx->r11 = ADD32(ctx->r25, ctx->r5);
    // 0x800C437C: b           L_800C4394
    // 0x800C4380: sh          $t2, 0x1E($t3)
    MEM_H(0X1E, ctx->r11) = ctx->r10;
        goto L_800C4394;
    // 0x800C4380: sh          $t2, 0x1E($t3)
    MEM_H(0X1E, ctx->r11) = ctx->r10;
L_800C4384:
    // 0x800C4384: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x800C4388: nop

    // 0x800C438C: addu        $t5, $t4, $a1
    ctx->r13 = ADD32(ctx->r12, ctx->r5);
    // 0x800C4390: sh          $zero, 0x1E($t5)
    MEM_H(0X1E, ctx->r13) = 0;
L_800C4394:
    // 0x800C4394: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800C4398: nop

    // 0x800C439C: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x800C43A0: sh          $zero, 0x20($t7)
    MEM_H(0X20, ctx->r15) = 0;
    // 0x800C43A4: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800C43A8: nop

    // 0x800C43AC: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x800C43B0: sh          $zero, 0x22($t9)
    MEM_H(0X22, ctx->r25) = 0;
    // 0x800C43B4: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x800C43B8: nop

    // 0x800C43BC: addu        $t4, $t3, $a1
    ctx->r12 = ADD32(ctx->r11, ctx->r5);
    // 0x800C43C0: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    // 0x800C43C4: slti        $at, $a1, 0x140
    ctx->r1 = SIGNED(ctx->r5) < 0X140 ? 1 : 0;
    // 0x800C43C8: bne         $at, $zero, L_800C420C
    if (ctx->r1 != 0) {
        // 0x800C43CC: sw          $zero, 0x24($t4)
        MEM_W(0X24, ctx->r12) = 0;
            goto L_800C420C;
    }
    // 0x800C43CC: sw          $zero, 0x24($t4)
    MEM_W(0X24, ctx->r12) = 0;
    // 0x800C43D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C43D4: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
L_800C43D8:
    // 0x800C43D8: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800C43DC: nop

    // 0x800C43E0: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800C43E4: sb          $a0, 0x1($t6)
    MEM_B(0X1, ctx->r14) = ctx->r4;
    // 0x800C43E8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C43EC: nop

    // 0x800C43F0: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C43F4: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x800C43F8: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C43FC: nop

    // 0x800C4400: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x800C4404: sb          $a0, 0x10($t3)
    MEM_B(0X10, ctx->r11) = ctx->r4;
    // 0x800C4408: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C440C: nop

    // 0x800C4410: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800C4414: sb          $a0, 0x11($t5)
    MEM_B(0X11, ctx->r13) = ctx->r4;
    // 0x800C4418: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C441C: nop

    // 0x800C4420: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800C4424: sb          $a0, 0x12($t7)
    MEM_B(0X12, ctx->r15) = ctx->r4;
    // 0x800C4428: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800C442C: nop

    // 0x800C4430: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800C4434: sb          $zero, 0x13($t9)
    MEM_B(0X13, ctx->r25) = 0;
    // 0x800C4438: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800C443C: nop

    // 0x800C4440: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x800C4444: sb          $a0, 0x14($t4)
    MEM_B(0X14, ctx->r12) = ctx->r4;
    // 0x800C4448: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800C444C: nop

    // 0x800C4450: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800C4454: sb          $a0, 0x15($t6)
    MEM_B(0X15, ctx->r14) = ctx->r4;
    // 0x800C4458: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C445C: nop

    // 0x800C4460: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C4464: sb          $a0, 0x16($t8)
    MEM_B(0X16, ctx->r24) = ctx->r4;
    // 0x800C4468: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C446C: nop

    // 0x800C4470: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x800C4474: sb          $zero, 0x17($t3)
    MEM_B(0X17, ctx->r11) = 0;
    // 0x800C4478: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C447C: nop

    // 0x800C4480: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800C4484: sw          $zero, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = 0;
    // 0x800C4488: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C448C: nop

    // 0x800C4490: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800C4494: sb          $a0, 0x21($t7)
    MEM_B(0X21, ctx->r15) = ctx->r4;
    // 0x800C4498: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800C449C: nop

    // 0x800C44A0: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800C44A4: sw          $zero, 0x24($t9)
    MEM_W(0X24, ctx->r25) = 0;
    // 0x800C44A8: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800C44AC: nop

    // 0x800C44B0: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x800C44B4: sb          $a0, 0x30($t4)
    MEM_B(0X30, ctx->r12) = ctx->r4;
    // 0x800C44B8: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800C44BC: nop

    // 0x800C44C0: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800C44C4: sb          $a0, 0x31($t6)
    MEM_B(0X31, ctx->r14) = ctx->r4;
    // 0x800C44C8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C44CC: nop

    // 0x800C44D0: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C44D4: sb          $a0, 0x32($t8)
    MEM_B(0X32, ctx->r24) = ctx->r4;
    // 0x800C44D8: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C44DC: nop

    // 0x800C44E0: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x800C44E4: sb          $zero, 0x33($t3)
    MEM_B(0X33, ctx->r11) = 0;
    // 0x800C44E8: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C44EC: nop

    // 0x800C44F0: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800C44F4: sb          $a0, 0x34($t5)
    MEM_B(0X34, ctx->r13) = ctx->r4;
    // 0x800C44F8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C44FC: nop

    // 0x800C4500: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800C4504: sb          $a0, 0x35($t7)
    MEM_B(0X35, ctx->r15) = ctx->r4;
    // 0x800C4508: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800C450C: nop

    // 0x800C4510: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800C4514: sb          $a0, 0x36($t9)
    MEM_B(0X36, ctx->r25) = ctx->r4;
    // 0x800C4518: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800C451C: nop

    // 0x800C4520: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x800C4524: sb          $zero, 0x37($t4)
    MEM_B(0X37, ctx->r12) = 0;
    // 0x800C4528: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800C452C: nop

    // 0x800C4530: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800C4534: sw          $zero, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = 0;
    // 0x800C4538: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C453C: nop

    // 0x800C4540: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C4544: sb          $a0, 0x41($t8)
    MEM_B(0X41, ctx->r24) = ctx->r4;
    // 0x800C4548: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C454C: nop

    // 0x800C4550: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x800C4554: sw          $zero, 0x44($t3)
    MEM_W(0X44, ctx->r11) = 0;
    // 0x800C4558: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C455C: nop

    // 0x800C4560: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800C4564: sb          $a0, 0x50($t5)
    MEM_B(0X50, ctx->r13) = ctx->r4;
    // 0x800C4568: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C456C: nop

    // 0x800C4570: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800C4574: sb          $a0, 0x51($t7)
    MEM_B(0X51, ctx->r15) = ctx->r4;
    // 0x800C4578: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800C457C: nop

    // 0x800C4580: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800C4584: sb          $a0, 0x52($t9)
    MEM_B(0X52, ctx->r25) = ctx->r4;
    // 0x800C4588: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800C458C: nop

    // 0x800C4590: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x800C4594: sb          $zero, 0x53($t4)
    MEM_B(0X53, ctx->r12) = 0;
    // 0x800C4598: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800C459C: nop

    // 0x800C45A0: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800C45A4: sb          $a0, 0x54($t6)
    MEM_B(0X54, ctx->r14) = ctx->r4;
    // 0x800C45A8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C45AC: nop

    // 0x800C45B0: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C45B4: sb          $a0, 0x55($t8)
    MEM_B(0X55, ctx->r24) = ctx->r4;
    // 0x800C45B8: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C45BC: nop

    // 0x800C45C0: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x800C45C4: sb          $a0, 0x56($t3)
    MEM_B(0X56, ctx->r11) = ctx->r4;
    // 0x800C45C8: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C45CC: nop

    // 0x800C45D0: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800C45D4: sb          $zero, 0x57($t5)
    MEM_B(0X57, ctx->r13) = 0;
    // 0x800C45D8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C45DC: nop

    // 0x800C45E0: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800C45E4: sw          $zero, 0x5C($t7)
    MEM_W(0X5C, ctx->r15) = 0;
    // 0x800C45E8: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800C45EC: nop

    // 0x800C45F0: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800C45F4: sb          $a0, 0x61($t9)
    MEM_B(0X61, ctx->r25) = ctx->r4;
    // 0x800C45F8: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800C45FC: nop

    // 0x800C4600: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x800C4604: sw          $zero, 0x64($t4)
    MEM_W(0X64, ctx->r12) = 0;
    // 0x800C4608: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800C460C: nop

    // 0x800C4610: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800C4614: sb          $a0, 0x70($t6)
    MEM_B(0X70, ctx->r14) = ctx->r4;
    // 0x800C4618: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C461C: nop

    // 0x800C4620: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C4624: sb          $a0, 0x71($t8)
    MEM_B(0X71, ctx->r24) = ctx->r4;
    // 0x800C4628: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C462C: nop

    // 0x800C4630: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x800C4634: sb          $a0, 0x72($t3)
    MEM_B(0X72, ctx->r11) = ctx->r4;
    // 0x800C4638: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C463C: nop

    // 0x800C4640: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800C4644: sb          $zero, 0x73($t5)
    MEM_B(0X73, ctx->r13) = 0;
    // 0x800C4648: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C464C: nop

    // 0x800C4650: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800C4654: sb          $a0, 0x74($t7)
    MEM_B(0X74, ctx->r15) = ctx->r4;
    // 0x800C4658: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800C465C: nop

    // 0x800C4660: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800C4664: sb          $a0, 0x75($t9)
    MEM_B(0X75, ctx->r25) = ctx->r4;
    // 0x800C4668: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800C466C: nop

    // 0x800C4670: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x800C4674: sb          $a0, 0x76($t4)
    MEM_B(0X76, ctx->r12) = ctx->r4;
    // 0x800C4678: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800C467C: nop

    // 0x800C4680: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800C4684: sb          $zero, 0x77($t6)
    MEM_B(0X77, ctx->r14) = 0;
    // 0x800C4688: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C468C: nop

    // 0x800C4690: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C4694: addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, 0X80);
    // 0x800C4698: bne         $v0, $a1, L_800C43D8
    if (ctx->r2 != ctx->r5) {
        // 0x800C469C: sw          $zero, 0x7C($t8)
        MEM_W(0X7C, ctx->r24) = 0;
            goto L_800C43D8;
    }
    // 0x800C469C: sw          $zero, 0x7C($t8)
    MEM_W(0X7C, ctx->r24) = 0;
    // 0x800C46A0: jal         0x800C46D0
    // 0x800C46A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    load_font(rdram, ctx);
        goto after_2;
    // 0x800C46A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x800C46A8: jal         0x800C46D0
    // 0x800C46AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    load_font(rdram, ctx);
        goto after_3;
    // 0x800C46AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x800C46B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C46B4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C46B8: sw          $zero, -0x5250($at)
    MEM_W(-0X5250, ctx->r1) = 0;
    // 0x800C46BC: jr          $ra
    // 0x800C46C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C46C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void set_kerning(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C46C4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C46C8: jr          $ra
    // 0x800C46CC: sw          $a0, -0x5250($at)
    MEM_W(-0X5250, ctx->r1) = ctx->r4;
    return;
    // 0x800C46CC: sw          $a0, -0x5250($at)
    MEM_W(-0X5250, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void load_font(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C46D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C46D4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C46D8: lw          $t6, -0x5260($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5260);
    // 0x800C46DC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C46E0: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800C46E4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800C46E8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800C46EC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C46F0: beq         $at, $zero, L_800C4770
    if (ctx->r1 == 0) {
        // 0x800C46F4: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_800C4770;
    }
    // 0x800C46F4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C46F8: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800C46FC: lw          $t8, -0x525C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X525C);
    // 0x800C4700: sll         $t7, $a0, 10
    ctx->r15 = S32(ctx->r4 << 10);
    // 0x800C4704: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x800C4708: lbu         $t9, 0x28($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X28);
    // 0x800C470C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C4710: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800C4714: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x800C4718: bne         $t1, $at, L_800C4770
    if (ctx->r9 != ctx->r1) {
        // 0x800C471C: sb          $t0, 0x28($v0)
        MEM_B(0X28, ctx->r2) = ctx->r8;
            goto L_800C4770;
    }
    // 0x800C471C: sb          $t0, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r8;
    // 0x800C4720: lh          $t2, 0x40($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X40);
    // 0x800C4724: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // 0x800C4728: beq         $s3, $t2, L_800C4770
    if (ctx->r19 == ctx->r10) {
        // 0x800C472C: sll         $s0, $zero, 1
        ctx->r16 = S32(0 << 1);
            goto L_800C4770;
    }
    // 0x800C472C: sll         $s0, $zero, 1
    ctx->r16 = S32(0 << 1);
    // 0x800C4730: addu        $s1, $v0, $s0
    ctx->r17 = ADD32(ctx->r2, ctx->r16);
    // 0x800C4734: sll         $t3, $zero, 2
    ctx->r11 = S32(0 << 2);
    // 0x800C4738: lh          $a0, 0x40($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X40);
    // 0x800C473C: addu        $s2, $v0, $t3
    ctx->r18 = ADD32(ctx->r2, ctx->r11);
L_800C4740:
    // 0x800C4740: jal         0x8007B2C4
    // 0x800C4744: nop

    load_texture(rdram, ctx);
        goto after_0;
    // 0x800C4744: nop

    after_0:
    // 0x800C4748: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800C474C: slti        $at, $s0, 0x40
    ctx->r1 = SIGNED(ctx->r16) < 0X40 ? 1 : 0;
    // 0x800C4750: sw          $v0, 0x80($s2)
    MEM_W(0X80, ctx->r18) = ctx->r2;
    // 0x800C4754: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800C4758: beq         $at, $zero, L_800C4770
    if (ctx->r1 == 0) {
        // 0x800C475C: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800C4770;
    }
    // 0x800C475C: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800C4760: lh          $a0, 0x40($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X40);
    // 0x800C4764: nop

    // 0x800C4768: bne         $s3, $a0, L_800C4740
    if (ctx->r19 != ctx->r4) {
        // 0x800C476C: nop
    
            goto L_800C4740;
    }
    // 0x800C476C: nop

L_800C4770:
    // 0x800C4770: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C4774: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800C4778: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800C477C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4780: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800C4784: jr          $ra
    // 0x800C4788: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800C4788: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void unload_font(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C478C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C4790: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C4794: lw          $t6, -0x5260($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5260);
    // 0x800C4798: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C479C: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800C47A0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800C47A4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800C47A8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C47AC: beq         $at, $zero, L_800C4830
    if (ctx->r1 == 0) {
        // 0x800C47B0: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_800C4830;
    }
    // 0x800C47B0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C47B4: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800C47B8: lw          $t8, -0x525C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X525C);
    // 0x800C47BC: sll         $t7, $a0, 10
    ctx->r15 = S32(ctx->r4 << 10);
    // 0x800C47C0: addu        $s2, $t7, $t8
    ctx->r18 = ADD32(ctx->r15, ctx->r24);
    // 0x800C47C4: lbu         $v0, 0x28($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X28);
    // 0x800C47C8: nop

    // 0x800C47CC: blez        $v0, L_800C4830
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800C47D0: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_800C4830;
    }
    // 0x800C47D0: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x800C47D4: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x800C47D8: bne         $t0, $zero, L_800C4830
    if (ctx->r8 != 0) {
        // 0x800C47DC: sb          $t9, 0x28($s2)
        MEM_B(0X28, ctx->r18) = ctx->r25;
            goto L_800C4830;
    }
    // 0x800C47DC: sb          $t9, 0x28($s2)
    MEM_B(0X28, ctx->r18) = ctx->r25;
    // 0x800C47E0: lh          $t1, 0x40($s2)
    ctx->r9 = MEM_H(ctx->r18, 0X40);
    // 0x800C47E4: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // 0x800C47E8: beq         $s3, $t1, L_800C4830
    if (ctx->r19 == ctx->r9) {
        // 0x800C47EC: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_800C4830;
    }
    // 0x800C47EC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800C47F0: sll         $t2, $zero, 2
    ctx->r10 = S32(0 << 2);
    // 0x800C47F4: addu        $s0, $s2, $t2
    ctx->r16 = ADD32(ctx->r18, ctx->r10);
L_800C47F8:
    // 0x800C47F8: lw          $a0, 0x80($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X80);
    // 0x800C47FC: jal         0x8007B70C
    // 0x800C4800: nop

    tex_free(rdram, ctx);
        goto after_0;
    // 0x800C4800: nop

    after_0:
    // 0x800C4804: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800C4808: slti        $at, $s1, 0x20
    ctx->r1 = SIGNED(ctx->r17) < 0X20 ? 1 : 0;
    // 0x800C480C: sw          $zero, 0x80($s0)
    MEM_W(0X80, ctx->r16) = 0;
    // 0x800C4810: beq         $at, $zero, L_800C4830
    if (ctx->r1 == 0) {
        // 0x800C4814: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800C4830;
    }
    // 0x800C4814: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800C4818: sll         $t3, $s1, 1
    ctx->r11 = S32(ctx->r17 << 1);
    // 0x800C481C: addu        $t4, $s2, $t3
    ctx->r12 = ADD32(ctx->r18, ctx->r11);
    // 0x800C4820: lh          $t5, 0x40($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X40);
    // 0x800C4824: nop

    // 0x800C4828: bne         $s3, $t5, L_800C47F8
    if (ctx->r19 != ctx->r13) {
        // 0x800C482C: nop
    
            goto L_800C47F8;
    }
    // 0x800C482C: nop

L_800C4830:
    // 0x800C4830: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C4834: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800C4838: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800C483C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4840: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800C4844: jr          $ra
    // 0x800C4848: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800C4848: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void set_text_font(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C484C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C4850: lw          $t6, -0x5260($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5260);
    // 0x800C4854: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C4858: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800C485C: beq         $at, $zero, L_800C4870
    if (ctx->r1 == 0) {
        // 0x800C4860: nop
    
            goto L_800C4870;
    }
    // 0x800C4860: nop

    // 0x800C4864: lw          $t7, -0x5258($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5258);
    // 0x800C4868: nop

    // 0x800C486C: sb          $a0, 0x1D($t7)
    MEM_B(0X1D, ctx->r15) = ctx->r4;
L_800C4870:
    // 0x800C4870: jr          $ra
    // 0x800C4874: nop

    return;
    // 0x800C4874: nop

;}
RECOMP_FUNC void get_loaded_font(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4878: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C487C: lw          $t7, -0x5260($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5260);
    // 0x800C4880: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800C4884: slt         $at, $a0, $t7
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800C4888: beq         $at, $zero, L_800C48DC
    if (ctx->r1 == 0) {
        // 0x800C488C: andi        $t6, $a1, 0xFF
        ctx->r14 = ctx->r5 & 0XFF;
            goto L_800C48DC;
    }
    // 0x800C488C: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x800C4890: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800C4894: lw          $t9, -0x525C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X525C);
    // 0x800C4898: sll         $t8, $a0, 10
    ctx->r24 = S32(ctx->r4 << 10);
    // 0x800C489C: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x800C48A0: lbu         $t0, 0x28($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X28);
    // 0x800C48A4: addiu       $a1, $t6, -0x20
    ctx->r5 = ADD32(ctx->r14, -0X20);
    // 0x800C48A8: beq         $t0, $zero, L_800C48DC
    if (ctx->r8 == 0) {
        // 0x800C48AC: andi        $t1, $a1, 0xFF
        ctx->r9 = ctx->r5 & 0XFF;
            goto L_800C48DC;
    }
    // 0x800C48AC: andi        $t1, $a1, 0xFF
    ctx->r9 = ctx->r5 & 0XFF;
    // 0x800C48B0: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x800C48B4: addu        $t3, $v1, $t2
    ctx->r11 = ADD32(ctx->r3, ctx->r10);
    // 0x800C48B8: lbu         $a0, 0x100($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X100);
    // 0x800C48BC: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800C48C0: beq         $a0, $at, L_800C48DC
    if (ctx->r4 == ctx->r1) {
        // 0x800C48C4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800C48DC;
    }
    // 0x800C48C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C48C8: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x800C48CC: addu        $t5, $v1, $t4
    ctx->r13 = ADD32(ctx->r3, ctx->r12);
    // 0x800C48D0: lw          $v0, 0x80($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X80);
    // 0x800C48D4: jr          $ra
    // 0x800C48D8: nop

    return;
    // 0x800C48D8: nop

L_800C48DC:
    // 0x800C48DC: jr          $ra
    // 0x800C48E0: nop

    return;
    // 0x800C48E0: nop

;}
RECOMP_FUNC void set_text_colour(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C48E4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C48E8: addiu       $v0, $v0, -0x5258
    ctx->r2 = ADD32(ctx->r2, -0X5258);
    // 0x800C48EC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800C48F0: nop

    // 0x800C48F4: sb          $a0, 0x14($t6)
    MEM_B(0X14, ctx->r14) = ctx->r4;
    // 0x800C48F8: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800C48FC: nop

    // 0x800C4900: sb          $a1, 0x15($t7)
    MEM_B(0X15, ctx->r15) = ctx->r5;
    // 0x800C4904: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800C4908: nop

    // 0x800C490C: sb          $a2, 0x16($t8)
    MEM_B(0X16, ctx->r24) = ctx->r6;
    // 0x800C4910: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800C4914: nop

    // 0x800C4918: sb          $a3, 0x17($t9)
    MEM_B(0X17, ctx->r25) = ctx->r7;
    // 0x800C491C: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800C4920: lw          $t0, 0x10($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X10);
    // 0x800C4924: jr          $ra
    // 0x800C4928: sb          $t0, 0x1C($t1)
    MEM_B(0X1C, ctx->r9) = ctx->r8;
    return;
    // 0x800C4928: sb          $t0, 0x1C($t1)
    MEM_B(0X1C, ctx->r9) = ctx->r8;
;}
RECOMP_FUNC void set_text_background_colour(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C492C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C4930: addiu       $v0, $v0, -0x5258
    ctx->r2 = ADD32(ctx->r2, -0X5258);
    // 0x800C4934: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800C4938: nop

    // 0x800C493C: sb          $a0, 0x18($t6)
    MEM_B(0X18, ctx->r14) = ctx->r4;
    // 0x800C4940: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800C4944: nop

    // 0x800C4948: sb          $a1, 0x19($t7)
    MEM_B(0X19, ctx->r15) = ctx->r5;
    // 0x800C494C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800C4950: nop

    // 0x800C4954: sb          $a2, 0x1A($t8)
    MEM_B(0X1A, ctx->r24) = ctx->r6;
    // 0x800C4958: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800C495C: jr          $ra
    // 0x800C4960: sb          $a3, 0x1B($t9)
    MEM_B(0X1B, ctx->r25) = ctx->r7;
    return;
    // 0x800C4960: sb          $a3, 0x1B($t9)
    MEM_B(0X1B, ctx->r25) = ctx->r7;
;}
RECOMP_FUNC void draw_text_plain_unused(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4964: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C4968: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x800C496C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800C4970: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800C4974: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C4978: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C497C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800C4980: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C4984: lw          $a1, -0x5258($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X5258);
    // 0x800C4988: jal         0x800C4B04
    // 0x800C498C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    render_text_string(rdram, ctx);
        goto after_0;
    // 0x800C498C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x800C4990: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4994: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C4998: jr          $ra
    // 0x800C499C: nop

    return;
    // 0x800C499C: nop

;}
RECOMP_FUNC void draw_text(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C49A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C49A4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800C49A8: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800C49AC: addiu       $v0, $zero, -0x8000
    ctx->r2 = ADD32(0, -0X8000);
    // 0x800C49B0: lw          $s0, -0x5258($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X5258);
    // 0x800C49B4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C49B8: bne         $a1, $v0, L_800C49D4
    if (ctx->r5 != ctx->r2) {
        // 0x800C49BC: sw          $a3, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r7;
            goto L_800C49D4;
    }
    // 0x800C49BC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800C49C0: lh          $t6, 0xC($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XC);
    // 0x800C49C4: nop

    // 0x800C49C8: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x800C49CC: b           L_800C49D8
    // 0x800C49D0: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
        goto L_800C49D8;
    // 0x800C49D0: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
L_800C49D4:
    // 0x800C49D4: sh          $a1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r5;
L_800C49D8:
    // 0x800C49D8: bne         $a2, $v0, L_800C49F4
    if (ctx->r6 != ctx->r2) {
        // 0x800C49DC: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_800C49F4;
    }
    // 0x800C49DC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800C49E0: lh          $t8, 0xE($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XE);
    // 0x800C49E4: nop

    // 0x800C49E8: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x800C49EC: b           L_800C49F8
    // 0x800C49F0: sh          $t9, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r25;
        goto L_800C49F8;
    // 0x800C49F0: sh          $t9, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r25;
L_800C49F4:
    // 0x800C49F4: sh          $a2, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r6;
L_800C49F8:
    // 0x800C49F8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C49FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C4A00: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800C4A04: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800C4A08: jal         0x800C4B04
    // 0x800C4A0C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    render_text_string(rdram, ctx);
        goto after_0;
    // 0x800C4A0C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x800C4A10: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C4A14: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800C4A18: jr          $ra
    // 0x800C4A1C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800C4A1C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void draw_dialogue_text_unused(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4A20: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C4A24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C4A28: bltz        $a1, L_800C4A60
    if (SIGNED(ctx->r5) < 0) {
        // 0x800C4A2C: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_800C4A60;
    }
    // 0x800C4A2C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800C4A30: slti        $at, $a1, 0x8
    ctx->r1 = SIGNED(ctx->r5) < 0X8 ? 1 : 0;
    // 0x800C4A34: beq         $at, $zero, L_800C4A60
    if (ctx->r1 == 0) {
        // 0x800C4A38: sll         $t7, $a1, 2
        ctx->r15 = S32(ctx->r5 << 2);
            goto L_800C4A60;
    }
    // 0x800C4A38: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x800C4A3C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800C4A40: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C4A44: lw          $t8, -0x5258($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5258);
    // 0x800C4A48: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C4A4C: addu        $t7, $t7, $a1
    ctx->r15 = ADD32(ctx->r15, ctx->r5);
    // 0x800C4A50: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C4A54: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x800C4A58: jal         0x800C4B04
    // 0x800C4A5C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    render_text_string(rdram, ctx);
        goto after_0;
    // 0x800C4A5C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
L_800C4A60:
    // 0x800C4A60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4A64: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C4A68: jr          $ra
    // 0x800C4A6C: nop

    return;
    // 0x800C4A6C: nop

;}
RECOMP_FUNC void draw_dialogue_text_pos_unused(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4A70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C4A74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C4A78: bltz        $a1, L_800C4AF4
    if (SIGNED(ctx->r5) < 0) {
        // 0x800C4A7C: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_800C4AF4;
    }
    // 0x800C4A7C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800C4A80: slti        $at, $a1, 0x8
    ctx->r1 = SIGNED(ctx->r5) < 0X8 ? 1 : 0;
    // 0x800C4A84: beq         $at, $zero, L_800C4AF4
    if (ctx->r1 == 0) {
        // 0x800C4A88: addiu       $v0, $zero, -0x8000
        ctx->r2 = ADD32(0, -0X8000);
            goto L_800C4AF4;
    }
    // 0x800C4A88: addiu       $v0, $zero, -0x8000
    ctx->r2 = ADD32(0, -0X8000);
    // 0x800C4A8C: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x800C4A90: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800C4A94: lw          $t8, -0x5258($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5258);
    // 0x800C4A98: addu        $t7, $t7, $a1
    ctx->r15 = ADD32(ctx->r15, ctx->r5);
    // 0x800C4A9C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C4AA0: bne         $a2, $v0, L_800C4ABC
    if (ctx->r6 != ctx->r2) {
        // 0x800C4AA4: addu        $a1, $t7, $t8
        ctx->r5 = ADD32(ctx->r15, ctx->r24);
            goto L_800C4ABC;
    }
    // 0x800C4AA4: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x800C4AA8: lh          $t9, 0xC($a1)
    ctx->r25 = MEM_H(ctx->r5, 0XC);
    // 0x800C4AAC: nop

    // 0x800C4AB0: sra         $t0, $t9, 1
    ctx->r8 = S32(SIGNED(ctx->r25) >> 1);
    // 0x800C4AB4: b           L_800C4AC0
    // 0x800C4AB8: sh          $t0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r8;
        goto L_800C4AC0;
    // 0x800C4AB8: sh          $t0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r8;
L_800C4ABC:
    // 0x800C4ABC: sh          $a2, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r6;
L_800C4AC0:
    // 0x800C4AC0: bne         $a3, $v0, L_800C4ADC
    if (ctx->r7 != ctx->r2) {
        // 0x800C4AC4: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800C4ADC;
    }
    // 0x800C4AC4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C4AC8: lh          $t1, 0xE($a1)
    ctx->r9 = MEM_H(ctx->r5, 0XE);
    // 0x800C4ACC: nop

    // 0x800C4AD0: sra         $t2, $t1, 1
    ctx->r10 = S32(SIGNED(ctx->r9) >> 1);
    // 0x800C4AD4: b           L_800C4AE0
    // 0x800C4AD8: sh          $t2, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r10;
        goto L_800C4AE0;
    // 0x800C4AD8: sh          $t2, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r10;
L_800C4ADC:
    // 0x800C4ADC: sh          $a3, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r7;
L_800C4AE0:
    // 0x800C4AE0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C4AE4: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800C4AE8: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x800C4AEC: jal         0x800C4B04
    // 0x800C4AF0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    render_text_string(rdram, ctx);
        goto after_0;
    // 0x800C4AF0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
L_800C4AF4:
    // 0x800C4AF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4AF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C4AFC: jr          $ra
    // 0x800C4B00: nop

    return;
    // 0x800C4B00: nop

;}
RECOMP_FUNC void render_text_string(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4B04: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x800C4B08: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800C4B0C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800C4B10: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800C4B14: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800C4B18: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C4B1C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800C4B20: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800C4B24: or          $s3, $a3, $zero
    ctx->r19 = ctx->r7 | 0;
    // 0x800C4B28: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800C4B2C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C4B30: sw          $a2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r6;
    // 0x800C4B34: addiu       $s5, $zero, -0x1
    ctx->r21 = ADD32(0, -0X1);
    // 0x800C4B38: beq         $a2, $zero, L_800C52DC
    if (ctx->r6 == 0) {
        // 0x800C4B3C: addiu       $s4, $zero, -0x1
        ctx->r20 = ADD32(0, -0X1);
            goto L_800C52DC;
    }
    // 0x800C4B3C: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // 0x800C4B40: lbu         $t7, 0x1D($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X1D);
    // 0x800C4B44: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800C4B48: lw          $t9, -0x525C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X525C);
    // 0x800C4B4C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800C4B50: sll         $t8, $t7, 10
    ctx->r24 = S32(ctx->r15 << 10);
    // 0x800C4B54: lh          $s0, 0x0($a1)
    ctx->r16 = MEM_H(ctx->r5, 0X0);
    // 0x800C4B58: lh          $ra, 0x2($a1)
    ctx->r31 = MEM_H(ctx->r5, 0X2);
    // 0x800C4B5C: addu        $t3, $t8, $t9
    ctx->r11 = ADD32(ctx->r24, ctx->r25);
    // 0x800C4B60: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800C4B64: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800C4B68: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800C4B6C: addiu       $t8, $t8, 0x3C20
    ctx->r24 = ADD32(ctx->r24, 0X3C20);
    // 0x800C4B70: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800C4B74: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800C4B78: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800C4B7C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800C4B80: lw          $t9, -0x5258($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5258);
    // 0x800C4B84: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800C4B88: beq         $a1, $t9, L_800C4CF8
    if (ctx->r5 == ctx->r25) {
        // 0x800C4B8C: andi        $t6, $s3, 0x5
        ctx->r14 = ctx->r19 & 0X5;
            goto L_800C4CF8;
    }
    // 0x800C4B8C: andi        $t6, $s3, 0x5
    ctx->r14 = ctx->r19 & 0X5;
    // 0x800C4B90: lh          $a0, 0xA($a1)
    ctx->r4 = MEM_H(ctx->r5, 0XA);
    // 0x800C4B94: lh          $a1, 0x6($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X6);
    // 0x800C4B98: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800C4B9C: subu        $t6, $a0, $a1
    ctx->r14 = SUB32(ctx->r4, ctx->r5);
    // 0x800C4BA0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800C4BA4: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800C4BA8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800C4BAC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C4BB0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C4BB4: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
    // 0x800C4BB8: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800C4BBC: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800C4BC0: addu        $a2, $a1, $a0
    ctx->r6 = ADD32(ctx->r5, ctx->r4);
    // 0x800C4BC4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x800C4BC8: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800C4BCC: lh          $t7, 0x4($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X4);
    // 0x800C4BD0: sra         $t9, $a2, 1
    ctx->r25 = S32(SIGNED(ctx->r6) >> 1);
    // 0x800C4BD4: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800C4BD8: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x800C4BDC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800C4BE0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800C4BE4: nop

    // 0x800C4BE8: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800C4BEC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C4BF0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C4BF4: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800C4BF8: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800C4BFC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C4C00: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800C4C04: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x800C4C08: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800C4C0C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800C4C10: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C4C14: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x800C4C18: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800C4C1C: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x800C4C20: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800C4C24: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x800C4C28: subu        $t9, $a2, $v0
    ctx->r25 = SUB32(ctx->r6, ctx->r2);
    // 0x800C4C2C: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x800C4C30: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x800C4C34: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800C4C38: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800C4C3C: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800C4C40: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800C4C44: nop

    // 0x800C4C48: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800C4C4C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C4C50: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C4C54: nop

    // 0x800C4C58: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800C4C5C: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x800C4C60: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800C4C64: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x800C4C68: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x800C4C6C: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x800C4C70: lh          $t7, 0x8($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X8);
    // 0x800C4C74: nop

    // 0x800C4C78: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800C4C7C: nop

    // 0x800C4C80: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800C4C84: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800C4C88: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800C4C8C: nop

    // 0x800C4C90: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800C4C94: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C4C98: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C4C9C: nop

    // 0x800C4CA0: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800C4CA4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800C4CA8: addu        $t8, $a2, $v0
    ctx->r24 = ADD32(ctx->r6, ctx->r2);
    // 0x800C4CAC: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x800C4CB0: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x800C4CB4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800C4CB8: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x800C4CBC: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x800C4CC0: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800C4CC4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800C4CC8: nop

    // 0x800C4CCC: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800C4CD0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C4CD4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C4CD8: nop

    // 0x800C4CDC: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800C4CE0: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    // 0x800C4CE4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800C4CE8: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x800C4CEC: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x800C4CF0: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
    // 0x800C4CF4: andi        $t6, $s3, 0x5
    ctx->r14 = ctx->r19 & 0X5;
L_800C4CF8:
    // 0x800C4CF8: beq         $t6, $zero, L_800C4D3C
    if (ctx->r14 == 0) {
        // 0x800C4CFC: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_800C4D3C;
    }
    // 0x800C4CFC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800C4D00: lbu         $a2, 0x1D($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0X1D);
    // 0x800C4D04: sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // 0x800C4D08: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    // 0x800C4D0C: jal         0x800C5300
    // 0x800C4D10: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    get_text_width(rdram, ctx);
        goto after_0;
    // 0x800C4D10: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    after_0:
    // 0x800C4D14: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800C4D18: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    // 0x800C4D1C: andi        $t7, $s3, 0x1
    ctx->r15 = ctx->r19 & 0X1;
    // 0x800C4D20: beq         $t7, $zero, L_800C4D34
    if (ctx->r15 == 0) {
        // 0x800C4D24: or          $s5, $v0, $zero
        ctx->r21 = ctx->r2 | 0;
            goto L_800C4D34;
    }
    // 0x800C4D24: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x800C4D28: subu        $s0, $s0, $v0
    ctx->r16 = SUB32(ctx->r16, ctx->r2);
    // 0x800C4D2C: b           L_800C4D3C
    // 0x800C4D30: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_800C4D3C;
    // 0x800C4D30: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800C4D34:
    // 0x800C4D34: sra         $t8, $v0, 1
    ctx->r24 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800C4D38: subu        $s0, $s0, $t8
    ctx->r16 = SUB32(ctx->r16, ctx->r24);
L_800C4D3C:
    // 0x800C4D3C: andi        $t9, $s3, 0x2
    ctx->r25 = ctx->r19 & 0X2;
    // 0x800C4D40: beq         $t9, $zero, L_800C4D58
    if (ctx->r25 == 0) {
        // 0x800C4D44: andi        $t7, $s3, 0x8
        ctx->r15 = ctx->r19 & 0X8;
            goto L_800C4D58;
    }
    // 0x800C4D44: andi        $t7, $s3, 0x8
    ctx->r15 = ctx->r19 & 0X8;
    // 0x800C4D48: lhu         $t6, 0x22($t3)
    ctx->r14 = MEM_HU(ctx->r11, 0X22);
    // 0x800C4D4C: nop

    // 0x800C4D50: subu        $ra, $ra, $t6
    ctx->r31 = SUB32(ctx->r31, ctx->r14);
    // 0x800C4D54: addiu       $ra, $ra, 0x1
    ctx->r31 = ADD32(ctx->r31, 0X1);
L_800C4D58:
    // 0x800C4D58: beq         $t7, $zero, L_800C4D70
    if (ctx->r15 == 0) {
        // 0x800C4D5C: nop
    
            goto L_800C4D70;
    }
    // 0x800C4D5C: nop

    // 0x800C4D60: lhu         $t8, 0x22($t3)
    ctx->r24 = MEM_HU(ctx->r11, 0X22);
    // 0x800C4D64: nop

    // 0x800C4D68: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x800C4D6C: subu        $ra, $ra, $t9
    ctx->r31 = SUB32(ctx->r31, ctx->r25);
L_800C4D70:
    // 0x800C4D70: lbu         $t6, 0x1B($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X1B);
    // 0x800C4D74: nop

    // 0x800C4D78: beq         $t6, $zero, L_800C4EA4
    if (ctx->r14 == 0) {
        // 0x800C4D7C: nop
    
            goto L_800C4EA4;
    }
    // 0x800C4D7C: nop

    // 0x800C4D80: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800C4D84: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x800C4D88: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800C4D8C: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800C4D90: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800C4D94: lbu         $t6, 0x18($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X18);
    // 0x800C4D98: lbu         $t9, 0x19($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X19);
    // 0x800C4D9C: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x800C4DA0: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x800C4DA4: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x800C4DA8: lbu         $t7, 0x1A($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X1A);
    // 0x800C4DAC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C4DB0: sll         $t6, $t7, 8
    ctx->r14 = S32(ctx->r15 << 8);
    // 0x800C4DB4: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x800C4DB8: lbu         $t8, 0x1B($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X1B);
    // 0x800C4DBC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800C4DC0: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x800C4DC4: bne         $s5, $at, L_800C4DEC
    if (ctx->r21 != ctx->r1) {
        // 0x800C4DC8: sw          $t6, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->r14;
            goto L_800C4DEC;
    }
    // 0x800C4DC8: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800C4DCC: lbu         $a2, 0x1D($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0X1D);
    // 0x800C4DD0: sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // 0x800C4DD4: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    // 0x800C4DD8: jal         0x800C5300
    // 0x800C4DDC: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    get_text_width(rdram, ctx);
        goto after_1;
    // 0x800C4DDC: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    after_1:
    // 0x800C4DE0: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800C4DE4: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    // 0x800C4DE8: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
L_800C4DEC:
    // 0x800C4DEC: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800C4DF0: lhu         $t7, 0x22($t3)
    ctx->r15 = MEM_HU(ctx->r11, 0X22);
    // 0x800C4DF4: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800C4DF8: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800C4DFC: lui         $t8, 0x702
    ctx->r24 = S32(0X702 << 16);
    // 0x800C4E00: lui         $t6, 0xE
    ctx->r14 = S32(0XE << 16);
    // 0x800C4E04: addiu       $t6, $t6, 0x3C68
    ctx->r14 = ADD32(ctx->r14, 0X3C68);
    // 0x800C4E08: ori         $t8, $t8, 0x10
    ctx->r24 = ctx->r24 | 0X10;
    // 0x800C4E0C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800C4E10: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800C4E14: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800C4E18: addu        $t1, $t7, $ra
    ctx->r9 = ADD32(ctx->r15, ctx->r31);
    // 0x800C4E1C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800C4E20: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800C4E24: lh          $t9, 0x4($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X4);
    // 0x800C4E28: addu        $t8, $s0, $s5
    ctx->r24 = ADD32(ctx->r16, ctx->r21);
    // 0x800C4E2C: addu        $t6, $t9, $t8
    ctx->r14 = ADD32(ctx->r25, ctx->r24);
    // 0x800C4E30: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800C4E34: andi        $t9, $t7, 0x3FF
    ctx->r25 = ctx->r15 & 0X3FF;
    // 0x800C4E38: lh          $t7, 0x6($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X6);
    // 0x800C4E3C: sll         $t8, $t9, 14
    ctx->r24 = S32(ctx->r25 << 14);
    // 0x800C4E40: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x800C4E44: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x800C4E48: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x800C4E4C: addu        $t9, $t1, $t7
    ctx->r25 = ADD32(ctx->r9, ctx->r15);
    // 0x800C4E50: andi        $t8, $t9, 0x3FF
    ctx->r24 = ctx->r25 & 0X3FF;
    // 0x800C4E54: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800C4E58: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x800C4E5C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800C4E60: lh          $t8, 0x4($s2)
    ctx->r24 = MEM_H(ctx->r18, 0X4);
    // 0x800C4E64: nop

    // 0x800C4E68: addu        $t6, $t8, $s0
    ctx->r14 = ADD32(ctx->r24, ctx->r16);
    // 0x800C4E6C: lh          $t8, 0x6($s2)
    ctx->r24 = MEM_H(ctx->r18, 0X6);
    // 0x800C4E70: andi        $t7, $t6, 0x3FF
    ctx->r15 = ctx->r14 & 0X3FF;
    // 0x800C4E74: sll         $t9, $t7, 14
    ctx->r25 = S32(ctx->r15 << 14);
    // 0x800C4E78: addu        $t6, $ra, $t8
    ctx->r14 = ADD32(ctx->r31, ctx->r24);
    // 0x800C4E7C: andi        $t7, $t6, 0x3FF
    ctx->r15 = ctx->r14 & 0X3FF;
    // 0x800C4E80: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800C4E84: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x800C4E88: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800C4E8C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800C4E90: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x800C4E94: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800C4E98: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800C4E9C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800C4EA0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_800C4EA4:
    // 0x800C4EA4: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800C4EA8: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800C4EAC: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800C4EB0: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800C4EB4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800C4EB8: lbu         $t9, 0x1C($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X1C);
    // 0x800C4EBC: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x800C4EC0: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x800C4EC4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800C4EC8: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800C4ECC: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x800C4ED0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800C4ED4: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800C4ED8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800C4EDC: lbu         $t8, 0x14($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X14);
    // 0x800C4EE0: lbu         $t9, 0x15($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X15);
    // 0x800C4EE4: sll         $t6, $t8, 24
    ctx->r14 = S32(ctx->r24 << 24);
    // 0x800C4EE8: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x800C4EEC: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x800C4EF0: lbu         $t6, 0x16($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X16);
    // 0x800C4EF4: nop

    // 0x800C4EF8: sll         $t8, $t6, 8
    ctx->r24 = S32(ctx->r14 << 8);
    // 0x800C4EFC: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x800C4F00: lbu         $t7, 0x17($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X17);
    // 0x800C4F04: nop

    // 0x800C4F08: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x800C4F0C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800C4F10: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800C4F14: lui         $t7, 0xE
    ctx->r15 = S32(0XE << 16);
    // 0x800C4F18: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800C4F1C: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800C4F20: lui         $t9, 0x702
    ctx->r25 = S32(0X702 << 16);
    // 0x800C4F24: ori         $t9, $t9, 0x10
    ctx->r25 = ctx->r25 | 0X10;
    // 0x800C4F28: addiu       $t7, $t7, 0x3C58
    ctx->r15 = ADD32(ctx->r15, 0X3C58);
    // 0x800C4F2C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800C4F30: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800C4F34: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800C4F38: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x800C4F3C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800C4F40: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800C4F44: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800C4F48: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800C4F4C: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
    // 0x800C4F50: lh          $t9, 0x20($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X20);
    // 0x800C4F54: lh          $t7, 0x22($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X22);
    // 0x800C4F58: lbu         $t6, 0x0($t8)
    ctx->r14 = MEM_BU(ctx->r24, 0X0);
    // 0x800C4F5C: addu        $s0, $s0, $t9
    ctx->r16 = ADD32(ctx->r16, ctx->r25);
    // 0x800C4F60: beq         $t6, $zero, L_800C5270
    if (ctx->r14 == 0) {
        // 0x800C4F64: addu        $ra, $ra, $t7
        ctx->r31 = ADD32(ctx->r31, ctx->r15);
            goto L_800C5270;
    }
    // 0x800C4F64: addu        $ra, $ra, $t7
    ctx->r31 = ADD32(ctx->r31, ctx->r15);
    // 0x800C4F68: lh          $t9, 0xA($s2)
    ctx->r25 = MEM_H(ctx->r18, 0XA);
    // 0x800C4F6C: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x800C4F70: slt         $at, $t9, $ra
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r31) ? 1 : 0;
    // 0x800C4F74: bne         $at, $zero, L_800C5270
    if (ctx->r1 != 0) {
        // 0x800C4F78: addu        $s3, $t8, $zero
        ctx->r19 = ADD32(ctx->r24, 0);
            goto L_800C5270;
    }
    // 0x800C4F78: addu        $s3, $t8, $zero
    ctx->r19 = ADD32(ctx->r24, 0);
    // 0x800C4F7C: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x800C4F80: andi        $v0, $t6, 0xFF
    ctx->r2 = ctx->r14 & 0XFF;
    // 0x800C4F84: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
L_800C4F88:
    // 0x800C4F88: slti        $at, $a0, 0x21
    ctx->r1 = SIGNED(ctx->r4) < 0X21 ? 1 : 0;
    // 0x800C4F8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C4F90: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800C4F94: bne         $at, $zero, L_800C4FA4
    if (ctx->r1 != 0) {
        // 0x800C4F98: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_800C4FA4;
    }
    // 0x800C4F98: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800C4F9C: slti        $at, $v1, 0x80
    ctx->r1 = SIGNED(ctx->r3) < 0X80 ? 1 : 0;
    // 0x800C4FA0: bne         $at, $zero, L_800C5054
    if (ctx->r1 != 0) {
        // 0x800C4FA4: addiu       $t7, $v1, -0x9
        ctx->r15 = ADD32(ctx->r3, -0X9);
            goto L_800C5054;
    }
L_800C4FA4:
    // 0x800C4FA4: addiu       $t7, $v1, -0x9
    ctx->r15 = ADD32(ctx->r3, -0X9);
    // 0x800C4FA8: sltiu       $at, $t7, 0x18
    ctx->r1 = ctx->r15 < 0X18 ? 1 : 0;
    // 0x800C4FAC: beq         $at, $zero, L_800C5048
    if (ctx->r1 == 0) {
        // 0x800C4FB0: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_800C5048;
    }
    // 0x800C4FB0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800C4FB4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C4FB8: addu        $at, $at, $t7
    gpr jr_addend_800C4FC4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800C4FBC: lw          $t7, -0x6720($at)
    ctx->r15 = ADD32(ctx->r1, -0X6720);
    // 0x800C4FC0: nop

    // 0x800C4FC4: jr          $t7
    // 0x800C4FC8: nop

    switch (jr_addend_800C4FC4 >> 2) {
        case 0: goto L_800C4FE8; break;
        case 1: goto L_800C4FD8; break;
        case 2: goto L_800C5030; break;
        case 3: goto L_800C5048; break;
        case 4: goto L_800C503C; break;
        case 5: goto L_800C5048; break;
        case 6: goto L_800C5048; break;
        case 7: goto L_800C5048; break;
        case 8: goto L_800C5048; break;
        case 9: goto L_800C5048; break;
        case 10: goto L_800C5048; break;
        case 11: goto L_800C5048; break;
        case 12: goto L_800C5048; break;
        case 13: goto L_800C5048; break;
        case 14: goto L_800C5048; break;
        case 15: goto L_800C5048; break;
        case 16: goto L_800C5048; break;
        case 17: goto L_800C5048; break;
        case 18: goto L_800C5048; break;
        case 19: goto L_800C5048; break;
        case 20: goto L_800C5048; break;
        case 21: goto L_800C5048; break;
        case 22: goto L_800C5048; break;
        case 23: goto L_800C4FCC; break;
        default: switch_error(__func__, 0x800C4FC4, 0x800E98E0);
    }
    // 0x800C4FC8: nop

L_800C4FCC:
    // 0x800C4FCC: lhu         $t6, 0x24($t3)
    ctx->r14 = MEM_HU(ctx->r11, 0X24);
    // 0x800C4FD0: b           L_800C5114
    // 0x800C4FD4: addu        $s0, $s0, $t6
    ctx->r16 = ADD32(ctx->r16, ctx->r14);
        goto L_800C5114;
    // 0x800C4FD4: addu        $s0, $s0, $t6
    ctx->r16 = ADD32(ctx->r16, ctx->r14);
L_800C4FD8:
    // 0x800C4FD8: lhu         $t9, 0x22($t3)
    ctx->r25 = MEM_HU(ctx->r11, 0X22);
    // 0x800C4FDC: lh          $s0, 0x20($s2)
    ctx->r16 = MEM_H(ctx->r18, 0X20);
    // 0x800C4FE0: b           L_800C5114
    // 0x800C4FE4: addu        $ra, $ra, $t9
    ctx->r31 = ADD32(ctx->r31, ctx->r25);
        goto L_800C5114;
    // 0x800C4FE4: addu        $ra, $ra, $t9
    ctx->r31 = ADD32(ctx->r31, ctx->r25);
L_800C4FE8:
    // 0x800C4FE8: lh          $t7, 0x20($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X20);
    // 0x800C4FEC: lhu         $v0, 0x26($t3)
    ctx->r2 = MEM_HU(ctx->r11, 0X26);
    // 0x800C4FF0: subu        $t6, $s0, $t7
    ctx->r14 = SUB32(ctx->r16, ctx->r15);
    // 0x800C4FF4: div         $zero, $t6, $v0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r2)));
    // 0x800C4FF8: addu        $t8, $s0, $v0
    ctx->r24 = ADD32(ctx->r16, ctx->r2);
    // 0x800C4FFC: bne         $v0, $zero, L_800C5008
    if (ctx->r2 != 0) {
        // 0x800C5000: nop
    
            goto L_800C5008;
    }
    // 0x800C5000: nop

    // 0x800C5004: break       7
    do_break(2148290564);
L_800C5008:
    // 0x800C5008: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C500C: bne         $v0, $at, L_800C5020
    if (ctx->r2 != ctx->r1) {
        // 0x800C5010: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C5020;
    }
    // 0x800C5010: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C5014: bne         $t6, $at, L_800C5020
    if (ctx->r14 != ctx->r1) {
        // 0x800C5018: nop
    
            goto L_800C5020;
    }
    // 0x800C5018: nop

    // 0x800C501C: break       6
    do_break(2148290588);
L_800C5020:
    // 0x800C5020: mfhi        $t9
    ctx->r25 = hi;
    // 0x800C5024: subu        $s0, $t8, $t9
    ctx->r16 = SUB32(ctx->r24, ctx->r25);
    // 0x800C5028: b           L_800C5114
    // 0x800C502C: nop

        goto L_800C5114;
    // 0x800C502C: nop

L_800C5030:
    // 0x800C5030: lhu         $t7, 0x22($t3)
    ctx->r15 = MEM_HU(ctx->r11, 0X22);
    // 0x800C5034: b           L_800C5114
    // 0x800C5038: addu        $ra, $ra, $t7
    ctx->r31 = ADD32(ctx->r31, ctx->r15);
        goto L_800C5114;
    // 0x800C5038: addu        $ra, $ra, $t7
    ctx->r31 = ADD32(ctx->r31, ctx->r15);
L_800C503C:
    // 0x800C503C: lh          $s0, 0x20($s2)
    ctx->r16 = MEM_H(ctx->r18, 0X20);
    // 0x800C5040: b           L_800C5114
    // 0x800C5044: nop

        goto L_800C5114;
    // 0x800C5044: nop

L_800C5048:
    // 0x800C5048: lhu         $t6, 0x24($t3)
    ctx->r14 = MEM_HU(ctx->r11, 0X24);
    // 0x800C504C: b           L_800C5114
    // 0x800C5050: addu        $s0, $s0, $t6
    ctx->r16 = ADD32(ctx->r16, ctx->r14);
        goto L_800C5114;
    // 0x800C5050: addu        $s0, $s0, $t6
    ctx->r16 = ADD32(ctx->r16, ctx->r14);
L_800C5054:
    // 0x800C5054: addiu       $a0, $v1, -0x20
    ctx->r4 = ADD32(ctx->r3, -0X20);
    // 0x800C5058: andi        $t8, $a0, 0xFF
    ctx->r24 = ctx->r4 & 0XFF;
    // 0x800C505C: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800C5060: addu        $v0, $t3, $t9
    ctx->r2 = ADD32(ctx->r11, ctx->r25);
    // 0x800C5064: lbu         $a3, 0x100($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X100);
    // 0x800C5068: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800C506C: beq         $a3, $at, L_800C5114
    if (ctx->r7 == ctx->r1) {
        // 0x800C5070: nop
    
            goto L_800C5114;
    }
    // 0x800C5070: nop

    // 0x800C5074: beq         $s4, $a3, L_800C50CC
    if (ctx->r20 == ctx->r7) {
        // 0x800C5078: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_800C50CC;
    }
    // 0x800C5078: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800C507C: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x800C5080: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800C5084: addu        $t6, $t3, $t7
    ctx->r14 = ADD32(ctx->r11, ctx->r15);
    // 0x800C5088: lw          $a0, 0x80($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X80);
    // 0x800C508C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800C5090: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800C5094: lh          $a2, 0xA($a0)
    ctx->r6 = MEM_H(ctx->r4, 0XA);
    // 0x800C5098: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800C509C: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x800C50A0: sll         $t7, $t9, 16
    ctx->r15 = S32(ctx->r25 << 16);
    // 0x800C50A4: sll         $t8, $a2, 3
    ctx->r24 = S32(ctx->r6 << 3);
    // 0x800C50A8: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x800C50AC: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x800C50B0: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x800C50B4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800C50B8: lw          $t8, 0xC($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XC);
    // 0x800C50BC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C50C0: addu        $t6, $t8, $at
    ctx->r14 = ADD32(ctx->r24, ctx->r1);
    // 0x800C50C4: or          $s4, $a3, $zero
    ctx->r20 = ctx->r7 | 0;
    // 0x800C50C8: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
L_800C50CC:
    // 0x800C50CC: lbu         $t9, 0x102($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X102);
    // 0x800C50D0: nop

    // 0x800C50D4: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
    // 0x800C50D8: lbu         $t7, 0x103($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X103);
    // 0x800C50DC: nop

    // 0x800C50E0: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    // 0x800C50E4: lbu         $t8, 0x107($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X107);
    // 0x800C50E8: lbu         $t4, 0x104($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X104);
    // 0x800C50EC: lbu         $t5, 0x105($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X105);
    // 0x800C50F0: lbu         $s5, 0x106($v0)
    ctx->r21 = MEM_BU(ctx->r2, 0X106);
    // 0x800C50F4: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x800C50F8: lhu         $v1, 0x20($t3)
    ctx->r3 = MEM_HU(ctx->r11, 0X20);
    // 0x800C50FC: nop

    // 0x800C5100: bne         $v1, $zero, L_800C5114
    if (ctx->r3 != 0) {
        // 0x800C5104: or          $t0, $v1, $zero
        ctx->r8 = ctx->r3 | 0;
            goto L_800C5114;
    }
    // 0x800C5104: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x800C5108: lbu         $t0, 0x101($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X101);
    // 0x800C510C: b           L_800C5114
    // 0x800C5110: nop

        goto L_800C5114;
    // 0x800C5110: nop

L_800C5114:
    // 0x800C5114: beq         $a1, $zero, L_800C5224
    if (ctx->r5 == 0) {
        // 0x800C5118: lui         $at, 0xE400
        ctx->r1 = S32(0XE400 << 16);
            goto L_800C5224;
    }
    // 0x800C5118: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x800C511C: lh          $t6, 0x4($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X4);
    // 0x800C5120: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x800C5124: addu        $t9, $t6, $s0
    ctx->r25 = ADD32(ctx->r14, ctx->r16);
    // 0x800C5128: lh          $t6, 0x6($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X6);
    // 0x800C512C: addu        $a1, $t9, $t7
    ctx->r5 = ADD32(ctx->r25, ctx->r15);
    // 0x800C5130: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x800C5134: addu        $t9, $t6, $ra
    ctx->r25 = ADD32(ctx->r14, ctx->r31);
    // 0x800C5138: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x800C513C: addu        $a2, $t9, $t7
    ctx->r6 = ADD32(ctx->r25, ctx->r15);
    // 0x800C5140: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x800C5144: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x800C5148: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x800C514C: sll         $t6, $s5, 2
    ctx->r14 = S32(ctx->r21 << 2);
    // 0x800C5150: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x800C5154: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800C5158: addu        $v0, $t6, $a1
    ctx->r2 = ADD32(ctx->r14, ctx->r5);
    // 0x800C515C: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x800C5160: sll         $t8, $t4, 5
    ctx->r24 = S32(ctx->r12 << 5);
    // 0x800C5164: sll         $t6, $t5, 5
    ctx->r14 = S32(ctx->r13 << 5);
    // 0x800C5168: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x800C516C: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x800C5170: or          $t4, $t8, $zero
    ctx->r12 = ctx->r24 | 0;
    // 0x800C5174: bgez        $a1, L_800C5190
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800C5178: or          $t5, $t6, $zero
        ctx->r13 = ctx->r14 | 0;
            goto L_800C5190;
    }
    // 0x800C5178: or          $t5, $t6, $zero
    ctx->r13 = ctx->r14 | 0;
    // 0x800C517C: blez        $v0, L_800C5190
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800C5180: negu        $t9, $a1
        ctx->r25 = SUB32(0, ctx->r5);
            goto L_800C5190;
    }
    // 0x800C5180: negu        $t9, $a1
    ctx->r25 = SUB32(0, ctx->r5);
    // 0x800C5184: sll         $t7, $t9, 3
    ctx->r15 = S32(ctx->r25 << 3);
    // 0x800C5188: addu        $t4, $t8, $t7
    ctx->r12 = ADD32(ctx->r24, ctx->r15);
    // 0x800C518C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_800C5190:
    // 0x800C5190: bgez        $a2, L_800C51AC
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800C5194: andi        $t7, $t2, 0xFFF
        ctx->r15 = ctx->r10 & 0XFFF;
            goto L_800C51AC;
    }
    // 0x800C5194: andi        $t7, $t2, 0xFFF
    ctx->r15 = ctx->r10 & 0XFFF;
    // 0x800C5198: blez        $v1, L_800C51AC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800C519C: negu        $t8, $a2
        ctx->r24 = SUB32(0, ctx->r6);
            goto L_800C51AC;
    }
    // 0x800C519C: negu        $t8, $a2
    ctx->r24 = SUB32(0, ctx->r6);
    // 0x800C51A0: sll         $t6, $t8, 3
    ctx->r14 = S32(ctx->r24 << 3);
    // 0x800C51A4: addu        $t5, $t5, $t6
    ctx->r13 = ADD32(ctx->r13, ctx->r14);
    // 0x800C51A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800C51AC:
    // 0x800C51AC: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800C51B0: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x800C51B4: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800C51B8: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800C51BC: andi        $t9, $t1, 0xFFF
    ctx->r25 = ctx->r9 & 0XFFF;
    // 0x800C51C0: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x800C51C4: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x800C51C8: andi        $t8, $a1, 0xFFF
    ctx->r24 = ctx->r5 & 0XFFF;
    // 0x800C51CC: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x800C51D0: andi        $t9, $a2, 0xFFF
    ctx->r25 = ctx->r6 & 0XFFF;
    // 0x800C51D4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800C51D8: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x800C51DC: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800C51E0: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800C51E4: lui         $t6, 0xB300
    ctx->r14 = S32(0XB300 << 16);
    // 0x800C51E8: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800C51EC: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800C51F0: andi        $t8, $t5, 0xFFFF
    ctx->r24 = ctx->r13 & 0XFFFF;
    // 0x800C51F4: sll         $t7, $t4, 16
    ctx->r15 = S32(ctx->r12 << 16);
    // 0x800C51F8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800C51FC: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x800C5200: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800C5204: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800C5208: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x800C520C: addiu       $t9, $a3, 0x8
    ctx->r25 = ADD32(ctx->r7, 0X8);
    // 0x800C5210: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800C5214: ori         $t8, $t8, 0x400
    ctx->r24 = ctx->r24 | 0X400;
    // 0x800C5218: lui         $t7, 0xB200
    ctx->r15 = S32(0XB200 << 16);
    // 0x800C521C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x800C5220: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
L_800C5224:
    // 0x800C5224: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C5228: lw          $t6, -0x5250($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5250);
    // 0x800C522C: nop

    // 0x800C5230: beq         $t6, $zero, L_800C5244
    if (ctx->r14 == 0) {
        // 0x800C5234: nop
    
            goto L_800C5244;
    }
    // 0x800C5234: nop

    // 0x800C5238: beq         $t0, $zero, L_800C5244
    if (ctx->r8 == 0) {
        // 0x800C523C: nop
    
            goto L_800C5244;
    }
    // 0x800C523C: nop

    // 0x800C5240: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_800C5244:
    // 0x800C5244: lbu         $v0, 0x1($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X1);
    // 0x800C5248: addu        $s0, $s0, $t0
    ctx->r16 = ADD32(ctx->r16, ctx->r8);
    // 0x800C524C: beq         $v0, $zero, L_800C5270
    if (ctx->r2 == 0) {
        // 0x800C5250: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_800C5270;
    }
    // 0x800C5250: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800C5254: lh          $t9, 0xA($s2)
    ctx->r25 = MEM_H(ctx->r18, 0XA);
    // 0x800C5258: nop

    // 0x800C525C: slt         $at, $t9, $ra
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r31) ? 1 : 0;
    // 0x800C5260: beq         $at, $zero, L_800C4F88
    if (ctx->r1 == 0) {
        // 0x800C5264: andi        $a0, $v0, 0xFF
        ctx->r4 = ctx->r2 & 0XFF;
            goto L_800C4F88;
    }
    // 0x800C5264: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x800C5268: sw          $t5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r13;
    // 0x800C526C: sw          $t4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r12;
L_800C5270:
    // 0x800C5270: lh          $t7, 0x20($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X20);
    // 0x800C5274: lh          $t6, 0x22($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X22);
    // 0x800C5278: subu        $t8, $s0, $t7
    ctx->r24 = SUB32(ctx->r16, ctx->r15);
    // 0x800C527C: subu        $t9, $ra, $t6
    ctx->r25 = SUB32(ctx->r31, ctx->r14);
    // 0x800C5280: sh          $t8, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r24;
    // 0x800C5284: sh          $t9, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r25;
    // 0x800C5288: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800C528C: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x800C5290: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800C5294: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800C5298: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C529C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800C52A0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800C52A4: lw          $t6, -0x5258($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5258);
    // 0x800C52A8: nop

    // 0x800C52AC: beq         $s2, $t6, L_800C52BC
    if (ctx->r18 == ctx->r14) {
        // 0x800C52B0: nop
    
            goto L_800C52BC;
    }
    // 0x800C52B0: nop

    // 0x800C52B4: jal         0x80067C7C
    // 0x800C52B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    viewport_scissor(rdram, ctx);
        goto after_2;
    // 0x800C52B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
L_800C52BC:
    // 0x800C52BC: jal         0x8007B820
    // 0x800C52C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    rendermode_reset(rdram, ctx);
        goto after_3;
    // 0x800C52C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x800C52C4: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800C52C8: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x800C52CC: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800C52D0: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800C52D4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800C52D8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_800C52DC:
    // 0x800C52DC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800C52E0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800C52E4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800C52E8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800C52EC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800C52F0: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800C52F4: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800C52F8: jr          $ra
    // 0x800C52FC: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x800C52FC: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void get_text_width(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5300: bne         $a0, $zero, L_800C5310
    if (ctx->r4 != 0) {
        // 0x800C5304: lui         $t8, 0x8013
        ctx->r24 = S32(0X8013 << 16);
            goto L_800C5310;
    }
    // 0x800C5304: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800C5308: jr          $ra
    // 0x800C530C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800C530C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C5310:
    // 0x800C5310: bgez        $a2, L_800C532C
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800C5314: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_800C532C;
    }
    // 0x800C5314: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x800C5318: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C531C: lw          $t6, -0x5258($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5258);
    // 0x800C5320: nop

    // 0x800C5324: lbu         $a2, 0x1D($t6)
    ctx->r6 = MEM_BU(ctx->r14, 0X1D);
    // 0x800C5328: nop

L_800C532C:
    // 0x800C532C: lw          $t8, -0x525C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X525C);
    // 0x800C5330: lbu         $t9, 0x0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X0);
    // 0x800C5334: sll         $t7, $a2, 10
    ctx->r15 = S32(ctx->r6 << 10);
    // 0x800C5338: beq         $t9, $zero, L_800C5430
    if (ctx->r25 == 0) {
        // 0x800C533C: addu        $v0, $t7, $t8
        ctx->r2 = ADD32(ctx->r15, ctx->r24);
            goto L_800C5430;
    }
    // 0x800C533C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x800C5340: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800C5344: lw          $t2, -0x5250($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5250);
    // 0x800C5348: lbu         $t0, 0x0($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X0);
    // 0x800C534C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800C5350: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800C5354: addiu       $t3, $zero, 0x9
    ctx->r11 = ADD32(0, 0X9);
    // 0x800C5358: andi        $a2, $t0, 0xFF
    ctx->r6 = ctx->r8 & 0XFF;
L_800C535C:
    // 0x800C535C: slti        $at, $a2, 0x21
    ctx->r1 = SIGNED(ctx->r6) < 0X21 ? 1 : 0;
    // 0x800C5360: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800C5364: bne         $at, $zero, L_800C5378
    if (ctx->r1 != 0) {
        // 0x800C5368: or          $t1, $a2, $zero
        ctx->r9 = ctx->r6 | 0;
            goto L_800C5378;
    }
    // 0x800C5368: or          $t1, $a2, $zero
    ctx->r9 = ctx->r6 | 0;
    // 0x800C536C: slti        $at, $a2, 0x80
    ctx->r1 = SIGNED(ctx->r6) < 0X80 ? 1 : 0;
    // 0x800C5370: bne         $at, $zero, L_800C53D0
    if (ctx->r1 != 0) {
        // 0x800C5374: addiu       $a2, $t1, -0x20
        ctx->r6 = ADD32(ctx->r9, -0X20);
            goto L_800C53D0;
    }
    // 0x800C5374: addiu       $a2, $t1, -0x20
    ctx->r6 = ADD32(ctx->r9, -0X20);
L_800C5378:
    // 0x800C5378: bne         $t3, $t1, L_800C53C4
    if (ctx->r11 != ctx->r9) {
        // 0x800C537C: nop
    
            goto L_800C53C4;
    }
    // 0x800C537C: nop

    // 0x800C5380: lhu         $a2, 0x26($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X26);
    // 0x800C5384: nop

    // 0x800C5388: div         $zero, $v1, $a2
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r6)));
    // 0x800C538C: addu        $t5, $v1, $a2
    ctx->r13 = ADD32(ctx->r3, ctx->r6);
    // 0x800C5390: bne         $a2, $zero, L_800C539C
    if (ctx->r6 != 0) {
        // 0x800C5394: nop
    
            goto L_800C539C;
    }
    // 0x800C5394: nop

    // 0x800C5398: break       7
    do_break(2148291480);
L_800C539C:
    // 0x800C539C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C53A0: bne         $a2, $at, L_800C53B4
    if (ctx->r6 != ctx->r1) {
        // 0x800C53A4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C53B4;
    }
    // 0x800C53A4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C53A8: bne         $v1, $at, L_800C53B4
    if (ctx->r3 != ctx->r1) {
        // 0x800C53AC: nop
    
            goto L_800C53B4;
    }
    // 0x800C53AC: nop

    // 0x800C53B0: break       6
    do_break(2148291504);
L_800C53B4:
    // 0x800C53B4: mfhi        $t6
    ctx->r14 = hi;
    // 0x800C53B8: subu        $v1, $t5, $t6
    ctx->r3 = SUB32(ctx->r13, ctx->r14);
    // 0x800C53BC: b           L_800C540C
    // 0x800C53C0: nop

        goto L_800C540C;
    // 0x800C53C0: nop

L_800C53C4:
    // 0x800C53C4: lhu         $t7, 0x24($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X24);
    // 0x800C53C8: b           L_800C540C
    // 0x800C53CC: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
        goto L_800C540C;
    // 0x800C53CC: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
L_800C53D0:
    // 0x800C53D0: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x800C53D4: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800C53D8: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x800C53DC: lbu         $t5, 0x100($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X100);
    // 0x800C53E0: nop

    // 0x800C53E4: beq         $t4, $t5, L_800C540C
    if (ctx->r12 == ctx->r13) {
        // 0x800C53E8: nop
    
            goto L_800C540C;
    }
    // 0x800C53E8: nop

    // 0x800C53EC: lhu         $a2, 0x20($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X20);
    // 0x800C53F0: nop

    // 0x800C53F4: bne         $a2, $zero, L_800C5408
    if (ctx->r6 != 0) {
        // 0x800C53F8: nop
    
            goto L_800C5408;
    }
    // 0x800C53F8: nop

    // 0x800C53FC: lbu         $t6, 0x101($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X101);
    // 0x800C5400: b           L_800C540C
    // 0x800C5404: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
        goto L_800C540C;
    // 0x800C5404: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
L_800C5408:
    // 0x800C5408: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
L_800C540C:
    // 0x800C540C: beq         $t2, $zero, L_800C5420
    if (ctx->r10 == 0) {
        // 0x800C5410: nop
    
            goto L_800C5420;
    }
    // 0x800C5410: nop

    // 0x800C5414: beq         $v1, $a0, L_800C5420
    if (ctx->r3 == ctx->r4) {
        // 0x800C5418: nop
    
            goto L_800C5420;
    }
    // 0x800C5418: nop

    // 0x800C541C: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
L_800C5420:
    // 0x800C5420: lbu         $t0, 0x1($a3)
    ctx->r8 = MEM_BU(ctx->r7, 0X1);
    // 0x800C5424: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800C5428: bne         $t0, $zero, L_800C535C
    if (ctx->r8 != 0) {
        // 0x800C542C: andi        $a2, $t0, 0xFF
        ctx->r6 = ctx->r8 & 0XFF;
            goto L_800C535C;
    }
    // 0x800C542C: andi        $a2, $t0, 0xFF
    ctx->r6 = ctx->r8 & 0XFF;
L_800C5430:
    // 0x800C5430: subu        $v0, $v1, $a1
    ctx->r2 = SUB32(ctx->r3, ctx->r5);
    // 0x800C5434: jr          $ra
    // 0x800C5438: nop

    return;
    // 0x800C5438: nop

;}
RECOMP_FUNC void set_current_dialogue_box_coords(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C543C: blez        $a0, L_800C54D4
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800C5440: slti        $at, $a0, 0x8
        ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
            goto L_800C54D4;
    }
    // 0x800C5440: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x800C5444: beq         $at, $zero, L_800C54D4
    if (ctx->r1 == 0) {
        // 0x800C5448: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_800C54D4;
    }
    // 0x800C5448: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800C544C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C5450: lw          $t7, -0x5258($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5258);
    // 0x800C5454: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800C5458: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800C545C: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800C5460: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C5464: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x800C5468: beq         $at, $zero, L_800C547C
    if (ctx->r1 == 0) {
        // 0x800C546C: sh          $zero, 0x2($v0)
        MEM_H(0X2, ctx->r2) = 0;
            goto L_800C547C;
    }
    // 0x800C546C: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x800C5470: sh          $a1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r5;
    // 0x800C5474: b           L_800C5484
    // 0x800C5478: sh          $a3, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r7;
        goto L_800C5484;
    // 0x800C5478: sh          $a3, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r7;
L_800C547C:
    // 0x800C547C: sh          $a1, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r5;
    // 0x800C5480: sh          $a3, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r7;
L_800C5484:
    // 0x800C5484: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
    // 0x800C5488: nop

    // 0x800C548C: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800C5490: beq         $at, $zero, L_800C54A4
    if (ctx->r1 == 0) {
        // 0x800C5494: nop
    
            goto L_800C54A4;
    }
    // 0x800C5494: nop

    // 0x800C5498: sh          $a2, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r6;
    // 0x800C549C: b           L_800C54AC
    // 0x800C54A0: sh          $v1, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r3;
        goto L_800C54AC;
    // 0x800C54A0: sh          $v1, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r3;
L_800C54A4:
    // 0x800C54A4: sh          $a2, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r6;
    // 0x800C54A8: sh          $v1, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r3;
L_800C54AC:
    // 0x800C54AC: lh          $t8, 0x8($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X8);
    // 0x800C54B0: lh          $t9, 0x4($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X4);
    // 0x800C54B4: lh          $t2, 0xA($v0)
    ctx->r10 = MEM_H(ctx->r2, 0XA);
    // 0x800C54B8: lh          $t3, 0x6($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X6);
    // 0x800C54BC: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x800C54C0: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x800C54C4: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800C54C8: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800C54CC: sh          $t1, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r9;
    // 0x800C54D0: sh          $t5, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r13;
L_800C54D4:
    // 0x800C54D4: jr          $ra
    // 0x800C54D8: nop

    return;
    // 0x800C54D8: nop

;}
RECOMP_FUNC void set_dialogue_font(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C54DC: bltz        $a0, L_800C5514
    if (SIGNED(ctx->r4) < 0) {
        // 0x800C54E0: slti        $at, $a0, 0x8
        ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
            goto L_800C5514;
    }
    // 0x800C54E0: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x800C54E4: beq         $at, $zero, L_800C5514
    if (ctx->r1 == 0) {
        // 0x800C54E8: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_800C5514;
    }
    // 0x800C54E8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800C54EC: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800C54F0: lw          $t8, -0x5260($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5260);
    // 0x800C54F4: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C54F8: lw          $t7, -0x5258($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5258);
    // 0x800C54FC: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800C5500: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800C5504: slt         $at, $a1, $t8
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800C5508: beq         $at, $zero, L_800C5514
    if (ctx->r1 == 0) {
        // 0x800C550C: addu        $v0, $t6, $t7
        ctx->r2 = ADD32(ctx->r14, ctx->r15);
            goto L_800C5514;
    }
    // 0x800C550C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C5510: sb          $a1, 0x1D($v0)
    MEM_B(0X1D, ctx->r2) = ctx->r5;
L_800C5514:
    // 0x800C5514: jr          $ra
    // 0x800C5518: nop

    return;
    // 0x800C5518: nop

;}
RECOMP_FUNC void set_current_dialogue_background_colour(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C551C: blez        $a0, L_800C5558
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800C5520: slti        $at, $a0, 0x8
        ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
            goto L_800C5558;
    }
    // 0x800C5520: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x800C5524: beq         $at, $zero, L_800C5558
    if (ctx->r1 == 0) {
        // 0x800C5528: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_800C5558;
    }
    // 0x800C5528: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800C552C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C5530: lw          $t7, -0x5258($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5258);
    // 0x800C5534: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800C5538: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800C553C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C5540: sb          $a1, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r5;
    // 0x800C5544: sb          $a2, 0x11($v0)
    MEM_B(0X11, ctx->r2) = ctx->r6;
    // 0x800C5548: sb          $a3, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r7;
    // 0x800C554C: lw          $t8, 0x10($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X10);
    // 0x800C5550: nop

    // 0x800C5554: sb          $t8, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r24;
L_800C5558:
    // 0x800C5558: jr          $ra
    // 0x800C555C: nop

    return;
    // 0x800C555C: nop

;}
RECOMP_FUNC void set_current_text_colour(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5560: blez        $a0, L_800C55A8
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800C5564: slti        $at, $a0, 0x8
        ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
            goto L_800C55A8;
    }
    // 0x800C5564: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x800C5568: beq         $at, $zero, L_800C55A8
    if (ctx->r1 == 0) {
        // 0x800C556C: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_800C55A8;
    }
    // 0x800C556C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800C5570: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C5574: lw          $t7, -0x5258($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5258);
    // 0x800C5578: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800C557C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800C5580: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C5584: sb          $a1, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r5;
    // 0x800C5588: sb          $a2, 0x15($v0)
    MEM_B(0X15, ctx->r2) = ctx->r6;
    // 0x800C558C: sb          $a3, 0x16($v0)
    MEM_B(0X16, ctx->r2) = ctx->r7;
    // 0x800C5590: lw          $t8, 0x10($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X10);
    // 0x800C5594: nop

    // 0x800C5598: sb          $t8, 0x17($v0)
    MEM_B(0X17, ctx->r2) = ctx->r24;
    // 0x800C559C: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x800C55A0: nop

    // 0x800C55A4: sb          $t9, 0x1C($v0)
    MEM_B(0X1C, ctx->r2) = ctx->r25;
L_800C55A8:
    // 0x800C55A8: jr          $ra
    // 0x800C55AC: nop

    return;
    // 0x800C55AC: nop

;}
RECOMP_FUNC void set_current_text_background_colour(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C55B0: blez        $a0, L_800C55EC
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800C55B4: slti        $at, $a0, 0x8
        ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
            goto L_800C55EC;
    }
    // 0x800C55B4: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x800C55B8: beq         $at, $zero, L_800C55EC
    if (ctx->r1 == 0) {
        // 0x800C55BC: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_800C55EC;
    }
    // 0x800C55BC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800C55C0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C55C4: lw          $t7, -0x5258($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5258);
    // 0x800C55C8: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800C55CC: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800C55D0: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C55D4: sb          $a1, 0x18($v0)
    MEM_B(0X18, ctx->r2) = ctx->r5;
    // 0x800C55D8: sb          $a2, 0x19($v0)
    MEM_B(0X19, ctx->r2) = ctx->r6;
    // 0x800C55DC: sb          $a3, 0x1A($v0)
    MEM_B(0X1A, ctx->r2) = ctx->r7;
    // 0x800C55E0: lw          $t8, 0x10($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X10);
    // 0x800C55E4: nop

    // 0x800C55E8: sb          $t8, 0x1B($v0)
    MEM_B(0X1B, ctx->r2) = ctx->r24;
L_800C55EC:
    // 0x800C55EC: jr          $ra
    // 0x800C55F0: nop

    return;
    // 0x800C55F0: nop

;}
RECOMP_FUNC void set_current_text_offset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C55F4: blez        $a0, L_800C5630
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800C55F8: slti        $at, $a0, 0x8
        ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
            goto L_800C5630;
    }
    // 0x800C55F8: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x800C55FC: beq         $at, $zero, L_800C5630
    if (ctx->r1 == 0) {
        // 0x800C5600: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_800C5630;
    }
    // 0x800C5600: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800C5604: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C5608: lw          $t7, -0x5258($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5258);
    // 0x800C560C: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800C5610: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800C5614: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C5618: lh          $t8, 0x20($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X20);
    // 0x800C561C: lh          $t0, 0x22($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X22);
    // 0x800C5620: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x800C5624: addu        $t1, $t0, $a2
    ctx->r9 = ADD32(ctx->r8, ctx->r6);
    // 0x800C5628: sh          $t9, 0x20($v0)
    MEM_H(0X20, ctx->r2) = ctx->r25;
    // 0x800C562C: sh          $t1, 0x22($v0)
    MEM_H(0X22, ctx->r2) = ctx->r9;
L_800C5630:
    // 0x800C5630: jr          $ra
    // 0x800C5634: nop

    return;
    // 0x800C5634: nop

;}
RECOMP_FUNC void reset_current_text_offset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5638: blez        $a0, L_800C5664
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800C563C: slti        $at, $a0, 0x8
        ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
            goto L_800C5664;
    }
    // 0x800C563C: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x800C5640: beq         $at, $zero, L_800C5664
    if (ctx->r1 == 0) {
        // 0x800C5644: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_800C5664;
    }
    // 0x800C5644: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800C5648: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C564C: lw          $t7, -0x5258($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5258);
    // 0x800C5650: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800C5654: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800C5658: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C565C: sh          $zero, 0x20($v0)
    MEM_H(0X20, ctx->r2) = 0;
    // 0x800C5660: sh          $zero, 0x22($v0)
    MEM_H(0X22, ctx->r2) = 0;
L_800C5664:
    // 0x800C5664: jr          $ra
    // 0x800C5668: nop

    return;
    // 0x800C5668: nop

;}
RECOMP_FUNC void render_global_dialogue_text(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C566C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C5670: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C5674: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800C5678: lw          $t6, -0x5258($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5258);
    // 0x800C567C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800C5680: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800C5684: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800C5688: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C568C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C5690: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800C5694: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C5698: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800C569C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800C56A0: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800C56A4: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x800C56A8: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x800C56AC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800C56B0: jal         0x800C56C8
    // 0x800C56B4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    render_dialogue_text(rdram, ctx);
        goto after_0;
    // 0x800C56B4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_0:
    // 0x800C56B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C56BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C56C0: jr          $ra
    // 0x800C56C4: nop

    return;
    // 0x800C56C4: nop

;}
RECOMP_FUNC void render_dialogue_text(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C56C8: addiu       $sp, $sp, -0x148
    ctx->r29 = ADD32(ctx->r29, -0X148);
    // 0x800C56CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C56D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C56D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C56D8: sw          $a1, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r5;
    // 0x800C56DC: sw          $a2, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r6;
    // 0x800C56E0: bne         $a3, $zero, L_800C56F0
    if (ctx->r7 != 0) {
        // 0x800C56E4: sw          $a3, 0x154($sp)
        MEM_W(0X154, ctx->r29) = ctx->r7;
            goto L_800C56F0;
    }
    // 0x800C56E4: sw          $a3, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r7;
    // 0x800C56E8: b           L_800C5978
    // 0x800C56EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C5978;
    // 0x800C56EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C56F0:
    // 0x800C56F0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C56F4: lw          $a0, -0x5254($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5254);
    // 0x800C56F8: sll         $t7, $zero, 5
    ctx->r15 = S32(0 << 5);
    // 0x800C56FC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800C5700: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800C5704: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800C5708: addu        $v0, $a0, $t7
    ctx->r2 = ADD32(ctx->r4, ctx->r15);
L_800C570C:
    // 0x800C570C: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x800C5710: sll         $t9, $v1, 5
    ctx->r25 = S32(ctx->r3 << 5);
    // 0x800C5714: bne         $a1, $t8, L_800C5720
    if (ctx->r5 != ctx->r24) {
        // 0x800C5718: nop
    
            goto L_800C5720;
    }
    // 0x800C5718: nop

    // 0x800C571C: addu        $a3, $t9, $a0
    ctx->r7 = ADD32(ctx->r25, ctx->r4);
L_800C5720:
    // 0x800C5720: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800C5724: slti        $at, $v1, 0x40
    ctx->r1 = SIGNED(ctx->r3) < 0X40 ? 1 : 0;
    // 0x800C5728: beq         $at, $zero, L_800C5738
    if (ctx->r1 == 0) {
        // 0x800C572C: addiu       $v0, $v0, 0x20
        ctx->r2 = ADD32(ctx->r2, 0X20);
            goto L_800C5738;
    }
    // 0x800C572C: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x800C5730: beq         $a3, $zero, L_800C570C
    if (ctx->r7 == 0) {
        // 0x800C5734: nop
    
            goto L_800C570C;
    }
    // 0x800C5734: nop

L_800C5738:
    // 0x800C5738: beq         $a3, $zero, L_800C5974
    if (ctx->r7 == 0) {
        // 0x800C573C: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_800C5974;
    }
    // 0x800C573C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800C5740: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x800C5744: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800C5748: lw          $t3, -0x5258($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5258);
    // 0x800C574C: lw          $t4, 0x14C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X14C);
    // 0x800C5750: addu        $t2, $t2, $s0
    ctx->r10 = ADD32(ctx->r10, ctx->r16);
    // 0x800C5754: addiu       $v0, $zero, -0x8000
    ctx->r2 = ADD32(0, -0X8000);
    // 0x800C5758: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x800C575C: bne         $t4, $v0, L_800C5774
    if (ctx->r12 != ctx->r2) {
        // 0x800C5760: addu        $t0, $t2, $t3
        ctx->r8 = ADD32(ctx->r10, ctx->r11);
            goto L_800C5774;
    }
    // 0x800C5760: addu        $t0, $t2, $t3
    ctx->r8 = ADD32(ctx->r10, ctx->r11);
    // 0x800C5764: lh          $t5, 0xC($t0)
    ctx->r13 = MEM_H(ctx->r8, 0XC);
    // 0x800C5768: nop

    // 0x800C576C: sra         $t6, $t5, 1
    ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
    // 0x800C5770: sw          $t6, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r14;
L_800C5774:
    // 0x800C5774: lw          $t7, 0x150($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X150);
    // 0x800C5778: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800C577C: bne         $t7, $v0, L_800C5794
    if (ctx->r15 != ctx->r2) {
        // 0x800C5780: nop
    
            goto L_800C5794;
    }
    // 0x800C5780: nop

    // 0x800C5784: lh          $t8, 0xE($t0)
    ctx->r24 = MEM_H(ctx->r8, 0XE);
    // 0x800C5788: nop

    // 0x800C578C: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x800C5790: sw          $t9, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r25;
L_800C5794:
    // 0x800C5794: lbu         $v0, 0x1D($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X1D);
    // 0x800C5798: lw          $v1, 0x15C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X15C);
    // 0x800C579C: beq         $a1, $v0, L_800C585C
    if (ctx->r5 == ctx->r2) {
        // 0x800C57A0: sll         $t2, $v0, 10
        ctx->r10 = S32(ctx->r2 << 10);
            goto L_800C585C;
    }
    // 0x800C57A0: sll         $t2, $v0, 10
    ctx->r10 = S32(ctx->r2 << 10);
    // 0x800C57A4: lw          $t3, -0x525C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X525C);
    // 0x800C57A8: andi        $t4, $v1, 0x5
    ctx->r12 = ctx->r3 & 0X5;
    // 0x800C57AC: beq         $t4, $zero, L_800C581C
    if (ctx->r12 == 0) {
        // 0x800C57B0: addu        $t1, $t2, $t3
        ctx->r9 = ADD32(ctx->r10, ctx->r11);
            goto L_800C581C;
    }
    // 0x800C57B0: addu        $t1, $t2, $t3
    ctx->r9 = ADD32(ctx->r10, ctx->r11);
    // 0x800C57B4: lw          $a2, 0x158($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X158);
    // 0x800C57B8: lw          $a0, 0x154($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X154);
    // 0x800C57BC: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800C57C0: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800C57C4: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x800C57C8: jal         0x800C64C0
    // 0x800C57CC: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    parse_string_with_number(rdram, ctx);
        goto after_0;
    // 0x800C57CC: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    after_0:
    // 0x800C57D0: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800C57D4: lw          $a1, 0x14C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X14C);
    // 0x800C57D8: lbu         $a2, 0x1D($t0)
    ctx->r6 = MEM_BU(ctx->r8, 0X1D);
    // 0x800C57DC: jal         0x800C5300
    // 0x800C57E0: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    get_text_width(rdram, ctx);
        goto after_1;
    // 0x800C57E0: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_1:
    // 0x800C57E4: lw          $v1, 0x15C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X15C);
    // 0x800C57E8: lw          $a0, 0x14C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X14C);
    // 0x800C57EC: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x800C57F0: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800C57F4: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800C57F8: andi        $t5, $v1, 0x1
    ctx->r13 = ctx->r3 & 0X1;
    // 0x800C57FC: beq         $t5, $zero, L_800C5814
    if (ctx->r13 == 0) {
        // 0x800C5800: sra         $t6, $v0, 1
        ctx->r14 = S32(SIGNED(ctx->r2) >> 1);
            goto L_800C5814;
    }
    // 0x800C5800: sra         $t6, $v0, 1
    ctx->r14 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800C5804: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x800C5808: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800C580C: b           L_800C581C
    // 0x800C5810: sw          $a0, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r4;
        goto L_800C581C;
    // 0x800C5810: sw          $a0, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r4;
L_800C5814:
    // 0x800C5814: subu        $a0, $a0, $t6
    ctx->r4 = SUB32(ctx->r4, ctx->r14);
    // 0x800C5818: sw          $a0, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r4;
L_800C581C:
    // 0x800C581C: andi        $t7, $v1, 0x2
    ctx->r15 = ctx->r3 & 0X2;
    // 0x800C5820: beq         $t7, $zero, L_800C5840
    if (ctx->r15 == 0) {
        // 0x800C5824: andi        $t4, $v1, 0x8
        ctx->r12 = ctx->r3 & 0X8;
            goto L_800C5840;
    }
    // 0x800C5824: andi        $t4, $v1, 0x8
    ctx->r12 = ctx->r3 & 0X8;
    // 0x800C5828: lw          $t8, 0x150($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X150);
    // 0x800C582C: lhu         $t9, 0x22($t1)
    ctx->r25 = MEM_HU(ctx->r9, 0X22);
    // 0x800C5830: nop

    // 0x800C5834: subu        $t2, $t8, $t9
    ctx->r10 = SUB32(ctx->r24, ctx->r25);
    // 0x800C5838: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800C583C: sw          $t3, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r11;
L_800C5840:
    // 0x800C5840: beq         $t4, $zero, L_800C585C
    if (ctx->r12 == 0) {
        // 0x800C5844: nop
    
            goto L_800C585C;
    }
    // 0x800C5844: nop

    // 0x800C5848: lhu         $t6, 0x22($t1)
    ctx->r14 = MEM_HU(ctx->r9, 0X22);
    // 0x800C584C: lw          $t5, 0x150($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X150);
    // 0x800C5850: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x800C5854: subu        $t8, $t5, $t7
    ctx->r24 = SUB32(ctx->r13, ctx->r15);
    // 0x800C5858: sw          $t8, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r24;
L_800C585C:
    // 0x800C585C: lw          $a0, 0x24($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X24);
    // 0x800C5860: lw          $s0, 0x158($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X158);
    // 0x800C5864: bne         $a0, $zero, L_800C5878
    if (ctx->r4 != 0) {
        // 0x800C5868: addiu       $v1, $t0, 0x24
        ctx->r3 = ADD32(ctx->r8, 0X24);
            goto L_800C5878;
    }
    // 0x800C5868: addiu       $v1, $t0, 0x24
    ctx->r3 = ADD32(ctx->r8, 0X24);
    // 0x800C586C: sw          $a3, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->r7;
    // 0x800C5870: b           L_800C58C4
    // 0x800C5874: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
        goto L_800C58C4;
    // 0x800C5874: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
L_800C5878:
    // 0x800C5878: beq         $a0, $zero, L_800C58BC
    if (ctx->r4 == 0) {
        // 0x800C587C: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_800C58BC;
    }
    // 0x800C587C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800C5880: lbu         $t9, 0x1($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1);
    // 0x800C5884: nop

    // 0x800C5888: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800C588C: beq         $at, $zero, L_800C58BC
    if (ctx->r1 == 0) {
        // 0x800C5890: nop
    
            goto L_800C58BC;
    }
    // 0x800C5890: nop

L_800C5894:
    // 0x800C5894: addiu       $v1, $v0, 0x1C
    ctx->r3 = ADD32(ctx->r2, 0X1C);
    // 0x800C5898: lw          $v0, 0x1C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1C);
    // 0x800C589C: nop

    // 0x800C58A0: beq         $v0, $zero, L_800C58BC
    if (ctx->r2 == 0) {
        // 0x800C58A4: nop
    
            goto L_800C58BC;
    }
    // 0x800C58A4: nop

    // 0x800C58A8: lbu         $t2, 0x1($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X1);
    // 0x800C58AC: nop

    // 0x800C58B0: slt         $at, $s0, $t2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800C58B4: bne         $at, $zero, L_800C5894
    if (ctx->r1 != 0) {
        // 0x800C58B8: nop
    
            goto L_800C5894;
    }
    // 0x800C58B8: nop

L_800C58BC:
    // 0x800C58BC: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x800C58C0: sw          $v0, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r2;
L_800C58C4:
    // 0x800C58C4: sb          $s0, 0x1($a3)
    MEM_B(0X1, ctx->r7) = ctx->r16;
    // 0x800C58C8: lw          $t3, 0x154($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X154);
    // 0x800C58CC: nop

    // 0x800C58D0: sw          $t3, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r11;
    // 0x800C58D4: lw          $t4, 0x14C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X14C);
    // 0x800C58D8: nop

    // 0x800C58DC: sh          $t4, 0x8($a3)
    MEM_H(0X8, ctx->r7) = ctx->r12;
    // 0x800C58E0: lw          $t6, 0x150($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X150);
    // 0x800C58E4: sh          $zero, 0xC($a3)
    MEM_H(0XC, ctx->r7) = 0;
    // 0x800C58E8: sh          $zero, 0xE($a3)
    MEM_H(0XE, ctx->r7) = 0;
    // 0x800C58EC: sh          $t6, 0xA($a3)
    MEM_H(0XA, ctx->r7) = ctx->r14;
    // 0x800C58F0: lbu         $t5, 0x14($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X14);
    // 0x800C58F4: nop

    // 0x800C58F8: sb          $t5, 0x10($a3)
    MEM_B(0X10, ctx->r7) = ctx->r13;
    // 0x800C58FC: lbu         $t7, 0x15($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X15);
    // 0x800C5900: nop

    // 0x800C5904: sb          $t7, 0x11($a3)
    MEM_B(0X11, ctx->r7) = ctx->r15;
    // 0x800C5908: lbu         $t8, 0x16($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X16);
    // 0x800C590C: nop

    // 0x800C5910: sb          $t8, 0x12($a3)
    MEM_B(0X12, ctx->r7) = ctx->r24;
    // 0x800C5914: lbu         $t9, 0x17($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X17);
    // 0x800C5918: nop

    // 0x800C591C: sb          $t9, 0x13($a3)
    MEM_B(0X13, ctx->r7) = ctx->r25;
    // 0x800C5920: lbu         $t2, 0x18($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X18);
    // 0x800C5924: nop

    // 0x800C5928: sb          $t2, 0x14($a3)
    MEM_B(0X14, ctx->r7) = ctx->r10;
    // 0x800C592C: lbu         $t3, 0x19($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X19);
    // 0x800C5930: nop

    // 0x800C5934: sb          $t3, 0x15($a3)
    MEM_B(0X15, ctx->r7) = ctx->r11;
    // 0x800C5938: lbu         $t4, 0x1A($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0X1A);
    // 0x800C593C: nop

    // 0x800C5940: sb          $t4, 0x16($a3)
    MEM_B(0X16, ctx->r7) = ctx->r12;
    // 0x800C5944: lbu         $t6, 0x1B($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X1B);
    // 0x800C5948: nop

    // 0x800C594C: sb          $t6, 0x17($a3)
    MEM_B(0X17, ctx->r7) = ctx->r14;
    // 0x800C5950: lbu         $t5, 0x1C($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X1C);
    // 0x800C5954: nop

    // 0x800C5958: sb          $t5, 0x18($a3)
    MEM_B(0X18, ctx->r7) = ctx->r13;
    // 0x800C595C: lbu         $t7, 0x1D($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X1D);
    // 0x800C5960: nop

    // 0x800C5964: sb          $t7, 0x19($a3)
    MEM_B(0X19, ctx->r7) = ctx->r15;
    // 0x800C5968: lhu         $t8, 0x1E($t0)
    ctx->r24 = MEM_HU(ctx->r8, 0X1E);
    // 0x800C596C: nop

    // 0x800C5970: sh          $t8, 0x1A($a3)
    MEM_H(0X1A, ctx->r7) = ctx->r24;
L_800C5974:
    // 0x800C5974: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_800C5978:
    // 0x800C5978: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C597C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C5980: jr          $ra
    // 0x800C5984: addiu       $sp, $sp, 0x148
    ctx->r29 = ADD32(ctx->r29, 0X148);
    return;
    // 0x800C5984: addiu       $sp, $sp, 0x148
    ctx->r29 = ADD32(ctx->r29, 0X148);
;}
RECOMP_FUNC void move_dialogue_box_to_front(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5988: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800C598C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C5990: lw          $t7, -0x5258($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5258);
    // 0x800C5994: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800C5998: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800C599C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C59A0: lw          $a2, 0x24($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X24);
    // 0x800C59A4: addiu       $v1, $v0, 0x24
    ctx->r3 = ADD32(ctx->r2, 0X24);
    // 0x800C59A8: beq         $a2, $zero, L_800C59D4
    if (ctx->r6 == 0) {
        // 0x800C59AC: nop
    
            goto L_800C59D4;
    }
    // 0x800C59AC: nop

    // 0x800C59B0: beq         $a2, $a1, L_800C59D4
    if (ctx->r6 == ctx->r5) {
        // 0x800C59B4: nop
    
            goto L_800C59D4;
    }
    // 0x800C59B4: nop

L_800C59B8:
    // 0x800C59B8: addiu       $v1, $a2, 0x1C
    ctx->r3 = ADD32(ctx->r6, 0X1C);
    // 0x800C59BC: lw          $a2, 0x1C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X1C);
    // 0x800C59C0: nop

    // 0x800C59C4: beq         $a2, $zero, L_800C59D4
    if (ctx->r6 == 0) {
        // 0x800C59C8: nop
    
            goto L_800C59D4;
    }
    // 0x800C59C8: nop

    // 0x800C59CC: bne         $a2, $a1, L_800C59B8
    if (ctx->r6 != ctx->r5) {
        // 0x800C59D0: nop
    
            goto L_800C59B8;
    }
    // 0x800C59D0: nop

L_800C59D4:
    // 0x800C59D4: beq         $a2, $zero, L_800C59EC
    if (ctx->r6 == 0) {
        // 0x800C59D8: nop
    
            goto L_800C59EC;
    }
    // 0x800C59D8: nop

    // 0x800C59DC: lw          $t8, 0x1C($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X1C);
    // 0x800C59E0: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800C59E4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800C59E8: sb          $t9, 0x1($a1)
    MEM_B(0X1, ctx->r5) = ctx->r25;
L_800C59EC:
    // 0x800C59EC: jr          $ra
    // 0x800C59F0: nop

    return;
    // 0x800C59F0: nop

;}
RECOMP_FUNC void dialogue_clear(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C59F4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800C59F8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C59FC: lw          $t7, -0x5258($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5258);
    // 0x800C5A00: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800C5A04: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800C5A08: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C5A0C: lw          $v1, 0x24($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X24);
    // 0x800C5A10: nop

    // 0x800C5A14: beq         $v1, $zero, L_800C5A40
    if (ctx->r3 == 0) {
        // 0x800C5A18: nop
    
            goto L_800C5A40;
    }
    // 0x800C5A18: nop

    // 0x800C5A1C: beq         $v1, $zero, L_800C5A3C
    if (ctx->r3 == 0) {
        // 0x800C5A20: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_800C5A3C;
    }
    // 0x800C5A20: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800C5A24: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
L_800C5A28:
    // 0x800C5A28: sb          $v1, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r3;
    // 0x800C5A2C: lw          $a0, 0x1C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1C);
    // 0x800C5A30: nop

    // 0x800C5A34: bne         $a0, $zero, L_800C5A28
    if (ctx->r4 != 0) {
        // 0x800C5A38: nop
    
            goto L_800C5A28;
    }
    // 0x800C5A38: nop

L_800C5A3C:
    // 0x800C5A3C: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
L_800C5A40:
    // 0x800C5A40: jr          $ra
    // 0x800C5A44: nop

    return;
    // 0x800C5A44: nop

;}
RECOMP_FUNC void align_text_in_box(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5A48: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800C5A4C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C5A50: lw          $t7, -0x5258($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5258);
    // 0x800C5A54: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800C5A58: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800C5A5C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800C5A60: beq         $a1, $zero, L_800C5B4C
    if (ctx->r5 == 0) {
        // 0x800C5A64: addu        $v0, $t6, $t7
        ctx->r2 = ADD32(ctx->r14, ctx->r15);
            goto L_800C5B4C;
    }
    // 0x800C5A64: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C5A68: lbu         $v1, 0x19($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X19);
    // 0x800C5A6C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800C5A70: beq         $v1, $at, L_800C5B4C
    if (ctx->r3 == ctx->r1) {
        // 0x800C5A74: sll         $t8, $v1, 10
        ctx->r24 = S32(ctx->r3 << 10);
            goto L_800C5B4C;
    }
    // 0x800C5A74: sll         $t8, $v1, 10
    ctx->r24 = S32(ctx->r3 << 10);
    // 0x800C5A78: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800C5A7C: lw          $a2, 0x10($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X10);
    // 0x800C5A80: lw          $t9, -0x525C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X525C);
    // 0x800C5A84: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800C5A88: beq         $a2, $at, L_800C5B44
    if (ctx->r6 == ctx->r1) {
        // 0x800C5A8C: addu        $a0, $t8, $t9
        ctx->r4 = ADD32(ctx->r24, ctx->r25);
            goto L_800C5B44;
    }
    // 0x800C5A8C: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x800C5A90: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C5A94: beq         $a2, $at, L_800C5AAC
    if (ctx->r6 == ctx->r1) {
        // 0x800C5A98: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800C5AAC;
    }
    // 0x800C5A98: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800C5A9C: beq         $a2, $at, L_800C5AC4
    if (ctx->r6 == ctx->r1) {
        // 0x800C5AA0: nop
    
            goto L_800C5AC4;
    }
    // 0x800C5AA0: nop

    // 0x800C5AA4: b           L_800C5B28
    // 0x800C5AA8: lh          $t4, 0xC($a1)
    ctx->r12 = MEM_H(ctx->r5, 0XC);
        goto L_800C5B28;
    // 0x800C5AA8: lh          $t4, 0xC($a1)
    ctx->r12 = MEM_H(ctx->r5, 0XC);
L_800C5AAC:
    // 0x800C5AAC: lhu         $t0, 0x22($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X22);
    // 0x800C5AB0: nop

    // 0x800C5AB4: multu       $a3, $t0
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C5AB8: mflo        $a3
    ctx->r7 = lo;
    // 0x800C5ABC: b           L_800C5B28
    // 0x800C5AC0: lh          $t4, 0xC($a1)
    ctx->r12 = MEM_H(ctx->r5, 0XC);
        goto L_800C5B28;
    // 0x800C5AC0: lh          $t4, 0xC($a1)
    ctx->r12 = MEM_H(ctx->r5, 0XC);
L_800C5AC4:
    // 0x800C5AC4: lhu         $v1, 0x22($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X22);
    // 0x800C5AC8: lh          $t1, 0xE($v0)
    ctx->r9 = MEM_H(ctx->r2, 0XE);
    // 0x800C5ACC: nop

    // 0x800C5AD0: div         $zero, $t1, $v1
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r3)));
    // 0x800C5AD4: bne         $v1, $zero, L_800C5AE0
    if (ctx->r3 != 0) {
        // 0x800C5AD8: nop
    
            goto L_800C5AE0;
    }
    // 0x800C5AD8: nop

    // 0x800C5ADC: break       7
    do_break(2148293340);
L_800C5AE0:
    // 0x800C5AE0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C5AE4: bne         $v1, $at, L_800C5AF8
    if (ctx->r3 != ctx->r1) {
        // 0x800C5AE8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C5AF8;
    }
    // 0x800C5AE8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C5AEC: bne         $t1, $at, L_800C5AF8
    if (ctx->r9 != ctx->r1) {
        // 0x800C5AF0: nop
    
            goto L_800C5AF8;
    }
    // 0x800C5AF0: nop

    // 0x800C5AF4: break       6
    do_break(2148293364);
L_800C5AF8:
    // 0x800C5AF8: mflo        $t2
    ctx->r10 = lo;
    // 0x800C5AFC: nop

    // 0x800C5B00: nop

    // 0x800C5B04: multu       $a3, $t2
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C5B08: mflo        $t3
    ctx->r11 = lo;
    // 0x800C5B0C: nop

    // 0x800C5B10: nop

    // 0x800C5B14: multu       $t3, $v1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C5B18: mflo        $a3
    ctx->r7 = lo;
    // 0x800C5B1C: nop

    // 0x800C5B20: nop

    // 0x800C5B24: lh          $t4, 0xC($a1)
    ctx->r12 = MEM_H(ctx->r5, 0XC);
L_800C5B28:
    // 0x800C5B28: lw          $t5, 0x8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8);
    // 0x800C5B2C: lh          $t7, 0xE($a1)
    ctx->r15 = MEM_H(ctx->r5, 0XE);
    // 0x800C5B30: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800C5B34: addu        $t8, $t7, $a3
    ctx->r24 = ADD32(ctx->r15, ctx->r7);
    // 0x800C5B38: sh          $t6, 0xC($a1)
    MEM_H(0XC, ctx->r5) = ctx->r14;
    // 0x800C5B3C: jr          $ra
    // 0x800C5B40: sh          $t8, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r24;
    return;
    // 0x800C5B40: sh          $t8, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r24;
L_800C5B44:
    // 0x800C5B44: sh          $zero, 0xC($a1)
    MEM_H(0XC, ctx->r5) = 0;
    // 0x800C5B48: sh          $zero, 0xE($a1)
    MEM_H(0XE, ctx->r5) = 0;
L_800C5B4C:
    // 0x800C5B4C: jr          $ra
    // 0x800C5B50: nop

    return;
    // 0x800C5B50: nop

;}
RECOMP_FUNC void open_dialogue_box(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5B54: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C5B58: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800C5B5C: lw          $t6, -0x5258($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5258);
    // 0x800C5B60: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800C5B64: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C5B68: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C5B6C: lhu         $t8, 0x1E($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X1E);
    // 0x800C5B70: nop

    // 0x800C5B74: ori         $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 | 0X8000;
    // 0x800C5B78: jr          $ra
    // 0x800C5B7C: sh          $t9, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r25;
    return;
    // 0x800C5B7C: sh          $t9, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r25;
;}
RECOMP_FUNC void dialogue_close(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5B80: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C5B84: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800C5B88: lw          $t6, -0x5258($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5258);
    // 0x800C5B8C: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800C5B90: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C5B94: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C5B98: lhu         $t8, 0x1E($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X1E);
    // 0x800C5B9C: nop

    // 0x800C5BA0: andi        $t9, $t8, 0x7FFF
    ctx->r25 = ctx->r24 & 0X7FFF;
    // 0x800C5BA4: jr          $ra
    // 0x800C5BA8: sh          $t9, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r25;
    return;
    // 0x800C5BA8: sh          $t9, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r25;
;}
RECOMP_FUNC void set_dialogue_box_unused_flag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5BAC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C5BB0: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800C5BB4: lw          $t6, -0x5258($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5258);
    // 0x800C5BB8: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800C5BBC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C5BC0: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C5BC4: lhu         $t8, 0x1E($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X1E);
    // 0x800C5BC8: nop

    // 0x800C5BCC: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x800C5BD0: jr          $ra
    // 0x800C5BD4: sh          $t9, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r25;
    return;
    // 0x800C5BD4: sh          $t9, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r25;
;}
RECOMP_FUNC void dialogue_box_clear_unused_flag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5BD8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C5BDC: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800C5BE0: lw          $t6, -0x5258($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5258);
    // 0x800C5BE4: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800C5BE8: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C5BEC: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C5BF0: lhu         $t8, 0x1E($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X1E);
    // 0x800C5BF4: nop

    // 0x800C5BF8: andi        $t9, $t8, 0xFFFE
    ctx->r25 = ctx->r24 & 0XFFFE;
    // 0x800C5BFC: jr          $ra
    // 0x800C5C00: sh          $t9, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r25;
    return;
    // 0x800C5C00: sh          $t9, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r25;
;}
RECOMP_FUNC void enable_dialogue_box_vertices(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5C04: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C5C08: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800C5C0C: lw          $t6, -0x5258($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5258);
    // 0x800C5C10: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800C5C14: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C5C18: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C5C1C: lhu         $t8, 0x1E($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X1E);
    // 0x800C5C20: nop

    // 0x800C5C24: ori         $t9, $t8, 0x4000
    ctx->r25 = ctx->r24 | 0X4000;
    // 0x800C5C28: jr          $ra
    // 0x800C5C2C: sh          $t9, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r25;
    return;
    // 0x800C5C2C: sh          $t9, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r25;
;}
RECOMP_FUNC void clear_dialogue_box_open_flag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5C30: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C5C34: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800C5C38: lw          $t6, -0x5258($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5258);
    // 0x800C5C3C: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800C5C40: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C5C44: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C5C48: lhu         $t8, 0x1E($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X1E);
    // 0x800C5C4C: nop

    // 0x800C5C50: andi        $t9, $t8, 0xBFFF
    ctx->r25 = ctx->r24 & 0XBFFF;
    // 0x800C5C54: jr          $ra
    // 0x800C5C58: sh          $t9, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r25;
    return;
    // 0x800C5C58: sh          $t9, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r25;
;}
RECOMP_FUNC void render_dialogue_boxes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5C5C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800C5C60: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C5C64: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800C5C68: addiu       $s0, $s0, 0x3C78
    ctx->r16 = ADD32(ctx->r16, 0X3C78);
    // 0x800C5C6C: lb          $t6, 0x0($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X0);
    // 0x800C5C70: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800C5C74: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800C5C78: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800C5C7C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800C5C80: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x800C5C84: or          $s6, $a2, $zero
    ctx->r22 = ctx->r6 | 0;
    // 0x800C5C88: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800C5C8C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800C5C90: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800C5C94: beq         $t6, $zero, L_800C5CD0
    if (ctx->r14 == 0) {
        // 0x800C5C98: sw          $s1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r17;
            goto L_800C5CD0;
    }
    // 0x800C5C98: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800C5C9C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C5CA0: addiu       $v0, $v0, -0x524C
    ctx->r2 = ADD32(ctx->r2, -0X524C);
    // 0x800C5CA4: lb          $t7, 0x0($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X0);
    // 0x800C5CA8: nop

    // 0x800C5CAC: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800C5CB0: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x800C5CB4: lb          $t9, 0x0($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X0);
    // 0x800C5CB8: nop

    // 0x800C5CBC: bne         $t9, $zero, L_800C5CD0
    if (ctx->r25 != 0) {
        // 0x800C5CC0: nop
    
            goto L_800C5CD0;
    }
    // 0x800C5CC0: nop

    // 0x800C5CC4: jal         0x8009EEEC
    // 0x800C5CC8: nop

    dialogue_close_stub(rdram, ctx);
        goto after_0;
    // 0x800C5CC8: nop

    after_0:
    // 0x800C5CCC: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_800C5CD0:
    // 0x800C5CD0: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800C5CD4: addiu       $s3, $s3, -0x5258
    ctx->r19 = ADD32(ctx->r19, -0X5258);
    // 0x800C5CD8: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x800C5CDC: addiu       $s1, $zero, 0x28
    ctx->r17 = ADD32(0, 0X28);
    // 0x800C5CE0: addiu       $s4, $zero, 0x8
    ctx->r20 = ADD32(0, 0X8);
L_800C5CE4:
    // 0x800C5CE4: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x800C5CE8: nop

    // 0x800C5CEC: addu        $t1, $t0, $s1
    ctx->r9 = ADD32(ctx->r8, ctx->r17);
    // 0x800C5CF0: lhu         $v0, 0x1E($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X1E);
    // 0x800C5CF4: nop

    // 0x800C5CF8: andi        $t2, $v0, 0x8000
    ctx->r10 = ctx->r2 & 0X8000;
    // 0x800C5CFC: beq         $t2, $zero, L_800C5D38
    if (ctx->r10 == 0) {
        // 0x800C5D00: andi        $t3, $v0, 0x4000
        ctx->r11 = ctx->r2 & 0X4000;
            goto L_800C5D38;
    }
    // 0x800C5D00: andi        $t3, $v0, 0x4000
    ctx->r11 = ctx->r2 & 0X4000;
    // 0x800C5D04: beq         $t3, $zero, L_800C5D28
    if (ctx->r11 == 0) {
        // 0x800C5D08: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800C5D28;
    }
    // 0x800C5D08: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C5D0C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C5D10: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800C5D14: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x800C5D18: jal         0x800C60B8
    // 0x800C5D1C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    render_dialogue_box(rdram, ctx);
        goto after_1;
    // 0x800C5D1C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_1:
    // 0x800C5D20: b           L_800C5D3C
    // 0x800C5D24: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_800C5D3C;
    // 0x800C5D24: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800C5D28:
    // 0x800C5D28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C5D2C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C5D30: jal         0x800C60B8
    // 0x800C5D34: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    render_dialogue_box(rdram, ctx);
        goto after_2;
    // 0x800C5D34: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_2:
L_800C5D38:
    // 0x800C5D38: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800C5D3C:
    // 0x800C5D3C: bne         $s0, $s4, L_800C5CE4
    if (ctx->r16 != ctx->r20) {
        // 0x800C5D40: addiu       $s1, $s1, 0x28
        ctx->r17 = ADD32(ctx->r17, 0X28);
            goto L_800C5CE4;
    }
    // 0x800C5D40: addiu       $s1, $s1, 0x28
    ctx->r17 = ADD32(ctx->r17, 0X28);
    // 0x800C5D44: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800C5D48: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C5D4C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800C5D50: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800C5D54: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800C5D58: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800C5D5C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800C5D60: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800C5D64: jr          $ra
    // 0x800C5D68: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800C5D68: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void s32_to_string(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5D6C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C5D70: bgez        $a1, L_800C5D88
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800C5D74: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800C5D88;
    }
    // 0x800C5D74: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800C5D78: addiu       $t6, $zero, 0x2D
    ctx->r14 = ADD32(0, 0X2D);
    // 0x800C5D7C: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x800C5D80: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C5D84: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
L_800C5D88:
    // 0x800C5D88: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800C5D8C: lw          $a3, 0x3C7C($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X3C7C);
    // 0x800C5D90: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800C5D94: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800C5D98: bne         $at, $zero, L_800C5DF0
    if (ctx->r1 != 0) {
        // 0x800C5D9C: addiu       $t1, $zero, 0x30
        ctx->r9 = ADD32(0, 0X30);
            goto L_800C5DF0;
    }
    // 0x800C5D9C: addiu       $t1, $zero, 0x30
    ctx->r9 = ADD32(0, 0X30);
    // 0x800C5DA0: div         $zero, $a1, $a3
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r7)));
    // 0x800C5DA4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800C5DA8: bne         $a3, $zero, L_800C5DB4
    if (ctx->r7 != 0) {
        // 0x800C5DAC: nop
    
            goto L_800C5DB4;
    }
    // 0x800C5DAC: nop

    // 0x800C5DB0: break       7
    do_break(2148294064);
L_800C5DB4:
    // 0x800C5DB4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C5DB8: bne         $a3, $at, L_800C5DCC
    if (ctx->r7 != ctx->r1) {
        // 0x800C5DBC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C5DCC;
    }
    // 0x800C5DBC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C5DC0: bne         $a1, $at, L_800C5DCC
    if (ctx->r5 != ctx->r1) {
        // 0x800C5DC4: nop
    
            goto L_800C5DCC;
    }
    // 0x800C5DC4: nop

    // 0x800C5DC8: break       6
    do_break(2148294088);
L_800C5DCC:
    // 0x800C5DCC: mflo        $t3
    ctx->r11 = lo;
    // 0x800C5DD0: addiu       $t1, $t3, 0x30
    ctx->r9 = ADD32(ctx->r11, 0X30);
    // 0x800C5DD4: andi        $t8, $t1, 0xFF
    ctx->r24 = ctx->r9 & 0XFF;
    // 0x800C5DD8: multu       $t3, $a3
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C5DDC: or          $t1, $t8, $zero
    ctx->r9 = ctx->r24 | 0;
    // 0x800C5DE0: or          $t2, $t3, $zero
    ctx->r10 = ctx->r11 | 0;
    // 0x800C5DE4: mflo        $t7
    ctx->r15 = lo;
    // 0x800C5DE8: subu        $a1, $a1, $t7
    ctx->r5 = SUB32(ctx->r5, ctx->r15);
    // 0x800C5DEC: nop

L_800C5DF0:
    // 0x800C5DF0: beq         $v1, $zero, L_800C5E00
    if (ctx->r3 == 0) {
        // 0x800C5DF4: sll         $t9, $a2, 2
        ctx->r25 = S32(ctx->r6 << 2);
            goto L_800C5E00;
    }
    // 0x800C5DF4: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x800C5DF8: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x800C5DFC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800C5E00:
    // 0x800C5E00: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800C5E04: addiu       $t5, $t5, 0x3C7C
    ctx->r13 = ADD32(ctx->r13, 0X3C7C);
    // 0x800C5E08: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800C5E0C: addiu       $t4, $t4, 0x3CA0
    ctx->r12 = ADD32(ctx->r12, 0X3CA0);
    // 0x800C5E10: addu        $t0, $t9, $t5
    ctx->r8 = ADD32(ctx->r25, ctx->r13);
L_800C5E14:
    // 0x800C5E14: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    // 0x800C5E18: addiu       $t1, $zero, 0x30
    ctx->r9 = ADD32(0, 0X30);
    // 0x800C5E1C: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800C5E20: bne         $at, $zero, L_800C5E78
    if (ctx->r1 != 0) {
        // 0x800C5E24: or          $a3, $a2, $zero
        ctx->r7 = ctx->r6 | 0;
            goto L_800C5E78;
    }
    // 0x800C5E24: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x800C5E28: div         $zero, $a1, $a2
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r6)));
    // 0x800C5E2C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800C5E30: bne         $a2, $zero, L_800C5E3C
    if (ctx->r6 != 0) {
        // 0x800C5E34: nop
    
            goto L_800C5E3C;
    }
    // 0x800C5E34: nop

    // 0x800C5E38: break       7
    do_break(2148294200);
L_800C5E3C:
    // 0x800C5E3C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C5E40: bne         $a2, $at, L_800C5E54
    if (ctx->r6 != ctx->r1) {
        // 0x800C5E44: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C5E54;
    }
    // 0x800C5E44: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C5E48: bne         $a1, $at, L_800C5E54
    if (ctx->r5 != ctx->r1) {
        // 0x800C5E4C: nop
    
            goto L_800C5E54;
    }
    // 0x800C5E4C: nop

    // 0x800C5E50: break       6
    do_break(2148294224);
L_800C5E54:
    // 0x800C5E54: mflo        $a3
    ctx->r7 = lo;
    // 0x800C5E58: addiu       $t1, $a3, 0x30
    ctx->r9 = ADD32(ctx->r7, 0X30);
    // 0x800C5E5C: andi        $t7, $t1, 0xFF
    ctx->r15 = ctx->r9 & 0XFF;
    // 0x800C5E60: multu       $a3, $a2
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C5E64: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x800C5E68: or          $t1, $t7, $zero
    ctx->r9 = ctx->r15 | 0;
    // 0x800C5E6C: mflo        $t6
    ctx->r14 = lo;
    // 0x800C5E70: subu        $a1, $a1, $t6
    ctx->r5 = SUB32(ctx->r5, ctx->r14);
    // 0x800C5E74: nop

L_800C5E78:
    // 0x800C5E78: beq         $v1, $zero, L_800C5E88
    if (ctx->r3 == 0) {
        // 0x800C5E7C: nop
    
            goto L_800C5E88;
    }
    // 0x800C5E7C: nop

    // 0x800C5E80: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x800C5E84: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800C5E88:
    // 0x800C5E88: lw          $a3, 0x4($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X4);
    // 0x800C5E8C: addiu       $t1, $zero, 0x30
    ctx->r9 = ADD32(0, 0X30);
    // 0x800C5E90: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800C5E94: bne         $at, $zero, L_800C5EEC
    if (ctx->r1 != 0) {
        // 0x800C5E98: nop
    
            goto L_800C5EEC;
    }
    // 0x800C5E98: nop

    // 0x800C5E9C: div         $zero, $a1, $a3
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r7)));
    // 0x800C5EA0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800C5EA4: bne         $a3, $zero, L_800C5EB0
    if (ctx->r7 != 0) {
        // 0x800C5EA8: nop
    
            goto L_800C5EB0;
    }
    // 0x800C5EA8: nop

    // 0x800C5EAC: break       7
    do_break(2148294316);
L_800C5EB0:
    // 0x800C5EB0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C5EB4: bne         $a3, $at, L_800C5EC8
    if (ctx->r7 != ctx->r1) {
        // 0x800C5EB8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C5EC8;
    }
    // 0x800C5EB8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C5EBC: bne         $a1, $at, L_800C5EC8
    if (ctx->r5 != ctx->r1) {
        // 0x800C5EC0: nop
    
            goto L_800C5EC8;
    }
    // 0x800C5EC0: nop

    // 0x800C5EC4: break       6
    do_break(2148294340);
L_800C5EC8:
    // 0x800C5EC8: mflo        $t3
    ctx->r11 = lo;
    // 0x800C5ECC: addiu       $t1, $t3, 0x30
    ctx->r9 = ADD32(ctx->r11, 0X30);
    // 0x800C5ED0: andi        $t9, $t1, 0xFF
    ctx->r25 = ctx->r9 & 0XFF;
    // 0x800C5ED4: multu       $t3, $a3
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C5ED8: or          $t1, $t9, $zero
    ctx->r9 = ctx->r25 | 0;
    // 0x800C5EDC: or          $t2, $t3, $zero
    ctx->r10 = ctx->r11 | 0;
    // 0x800C5EE0: mflo        $t8
    ctx->r24 = lo;
    // 0x800C5EE4: subu        $a1, $a1, $t8
    ctx->r5 = SUB32(ctx->r5, ctx->r24);
    // 0x800C5EE8: nop

L_800C5EEC:
    // 0x800C5EEC: beq         $v1, $zero, L_800C5EFC
    if (ctx->r3 == 0) {
        // 0x800C5EF0: nop
    
            goto L_800C5EFC;
    }
    // 0x800C5EF0: nop

    // 0x800C5EF4: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x800C5EF8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800C5EFC:
    // 0x800C5EFC: lw          $a3, 0x8($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X8);
    // 0x800C5F00: addiu       $t1, $zero, 0x30
    ctx->r9 = ADD32(0, 0X30);
    // 0x800C5F04: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800C5F08: bne         $at, $zero, L_800C5F60
    if (ctx->r1 != 0) {
        // 0x800C5F0C: nop
    
            goto L_800C5F60;
    }
    // 0x800C5F0C: nop

    // 0x800C5F10: div         $zero, $a1, $a3
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r7)));
    // 0x800C5F14: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800C5F18: bne         $a3, $zero, L_800C5F24
    if (ctx->r7 != 0) {
        // 0x800C5F1C: nop
    
            goto L_800C5F24;
    }
    // 0x800C5F1C: nop

    // 0x800C5F20: break       7
    do_break(2148294432);
L_800C5F24:
    // 0x800C5F24: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C5F28: bne         $a3, $at, L_800C5F3C
    if (ctx->r7 != ctx->r1) {
        // 0x800C5F2C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C5F3C;
    }
    // 0x800C5F2C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C5F30: bne         $a1, $at, L_800C5F3C
    if (ctx->r5 != ctx->r1) {
        // 0x800C5F34: nop
    
            goto L_800C5F3C;
    }
    // 0x800C5F34: nop

    // 0x800C5F38: break       6
    do_break(2148294456);
L_800C5F3C:
    // 0x800C5F3C: mflo        $t3
    ctx->r11 = lo;
    // 0x800C5F40: addiu       $t1, $t3, 0x30
    ctx->r9 = ADD32(ctx->r11, 0X30);
    // 0x800C5F44: andi        $t6, $t1, 0xFF
    ctx->r14 = ctx->r9 & 0XFF;
    // 0x800C5F48: multu       $t3, $a3
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C5F4C: or          $t1, $t6, $zero
    ctx->r9 = ctx->r14 | 0;
    // 0x800C5F50: or          $t2, $t3, $zero
    ctx->r10 = ctx->r11 | 0;
    // 0x800C5F54: mflo        $t5
    ctx->r13 = lo;
    // 0x800C5F58: subu        $a1, $a1, $t5
    ctx->r5 = SUB32(ctx->r5, ctx->r13);
    // 0x800C5F5C: nop

L_800C5F60:
    // 0x800C5F60: beq         $v1, $zero, L_800C5F70
    if (ctx->r3 == 0) {
        // 0x800C5F64: nop
    
            goto L_800C5F70;
    }
    // 0x800C5F64: nop

    // 0x800C5F68: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x800C5F6C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800C5F70:
    // 0x800C5F70: lw          $a3, 0xC($t0)
    ctx->r7 = MEM_W(ctx->r8, 0XC);
    // 0x800C5F74: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x800C5F78: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800C5F7C: bne         $at, $zero, L_800C5FD4
    if (ctx->r1 != 0) {
        // 0x800C5F80: addiu       $t1, $zero, 0x30
        ctx->r9 = ADD32(0, 0X30);
            goto L_800C5FD4;
    }
    // 0x800C5F80: addiu       $t1, $zero, 0x30
    ctx->r9 = ADD32(0, 0X30);
    // 0x800C5F84: div         $zero, $a1, $a3
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r7)));
    // 0x800C5F88: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800C5F8C: bne         $a3, $zero, L_800C5F98
    if (ctx->r7 != 0) {
        // 0x800C5F90: nop
    
            goto L_800C5F98;
    }
    // 0x800C5F90: nop

    // 0x800C5F94: break       7
    do_break(2148294548);
L_800C5F98:
    // 0x800C5F98: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C5F9C: bne         $a3, $at, L_800C5FB0
    if (ctx->r7 != ctx->r1) {
        // 0x800C5FA0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C5FB0;
    }
    // 0x800C5FA0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C5FA4: bne         $a1, $at, L_800C5FB0
    if (ctx->r5 != ctx->r1) {
        // 0x800C5FA8: nop
    
            goto L_800C5FB0;
    }
    // 0x800C5FA8: nop

    // 0x800C5FAC: break       6
    do_break(2148294572);
L_800C5FB0:
    // 0x800C5FB0: mflo        $t3
    ctx->r11 = lo;
    // 0x800C5FB4: addiu       $t1, $t3, 0x30
    ctx->r9 = ADD32(ctx->r11, 0X30);
    // 0x800C5FB8: andi        $t8, $t1, 0xFF
    ctx->r24 = ctx->r9 & 0XFF;
    // 0x800C5FBC: multu       $t3, $a3
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C5FC0: or          $t1, $t8, $zero
    ctx->r9 = ctx->r24 | 0;
    // 0x800C5FC4: or          $t2, $t3, $zero
    ctx->r10 = ctx->r11 | 0;
    // 0x800C5FC8: mflo        $t7
    ctx->r15 = lo;
    // 0x800C5FCC: subu        $a1, $a1, $t7
    ctx->r5 = SUB32(ctx->r5, ctx->r15);
    // 0x800C5FD0: nop

L_800C5FD4:
    // 0x800C5FD4: beq         $v1, $zero, L_800C5FE4
    if (ctx->r3 == 0) {
        // 0x800C5FD8: nop
    
            goto L_800C5FE4;
    }
    // 0x800C5FD8: nop

    // 0x800C5FDC: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x800C5FE0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800C5FE4:
    // 0x800C5FE4: bne         $t0, $t4, L_800C5E14
    if (ctx->r8 != ctx->r12) {
        // 0x800C5FE8: nop
    
            goto L_800C5E14;
    }
    // 0x800C5FE8: nop

    // 0x800C5FEC: addiu       $t9, $a1, 0x30
    ctx->r25 = ADD32(ctx->r5, 0X30);
    // 0x800C5FF0: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x800C5FF4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C5FF8: jr          $ra
    // 0x800C5FFC: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    return;
    // 0x800C5FFC: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void render_fill_rectangle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C6004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C6008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C600C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800C6010: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C6014: jal         0x8007A970
    // 0x800C6018: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    fb_size(rdram, ctx);
        goto after_0;
    // 0x800C6018: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x800C601C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x800C6020: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800C6024: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800C6028: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800C602C: bltz        $a3, L_800C60A8
    if (SIGNED(ctx->r7) < 0) {
        // 0x800C6030: andi        $t6, $v0, 0xFFFF
        ctx->r14 = ctx->r2 & 0XFFFF;
            goto L_800C60A8;
    }
    // 0x800C6030: andi        $t6, $v0, 0xFFFF
    ctx->r14 = ctx->r2 & 0XFFFF;
    // 0x800C6034: sltu        $at, $a1, $t6
    ctx->r1 = ctx->r5 < ctx->r14 ? 1 : 0;
    // 0x800C6038: beq         $at, $zero, L_800C60AC
    if (ctx->r1 == 0) {
        // 0x800C603C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C60AC;
    }
    // 0x800C603C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C6040: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800C6044: srl         $t7, $v0, 16
    ctx->r15 = S32(U32(ctx->r2) >> 16);
    // 0x800C6048: bltz        $a0, L_800C60A8
    if (SIGNED(ctx->r4) < 0) {
        // 0x800C604C: sltu        $at, $a2, $t7
        ctx->r1 = ctx->r6 < ctx->r15 ? 1 : 0;
            goto L_800C60A8;
    }
    // 0x800C604C: sltu        $at, $a2, $t7
    ctx->r1 = ctx->r6 < ctx->r15 ? 1 : 0;
    // 0x800C6050: beq         $at, $zero, L_800C60A8
    if (ctx->r1 == 0) {
        // 0x800C6054: andi        $t9, $a3, 0x3FF
        ctx->r25 = ctx->r7 & 0X3FF;
            goto L_800C60A8;
    }
    // 0x800C6054: andi        $t9, $a3, 0x3FF
    ctx->r25 = ctx->r7 & 0X3FF;
    // 0x800C6058: bgez        $a1, L_800C6064
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800C605C: sll         $t1, $t9, 14
        ctx->r9 = S32(ctx->r25 << 14);
            goto L_800C6064;
    }
    // 0x800C605C: sll         $t1, $t9, 14
    ctx->r9 = S32(ctx->r25 << 14);
    // 0x800C6060: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_800C6064:
    // 0x800C6064: bgez        $a2, L_800C6070
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800C6068: lui         $at, 0xF600
        ctx->r1 = S32(0XF600 << 16);
            goto L_800C6070;
    }
    // 0x800C6068: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x800C606C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800C6070:
    // 0x800C6070: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x800C6074: or          $t2, $t1, $at
    ctx->r10 = ctx->r9 | ctx->r1;
    // 0x800C6078: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800C607C: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x800C6080: andi        $t8, $a2, 0x3FF
    ctx->r24 = ctx->r6 & 0X3FF;
    // 0x800C6084: andi        $t3, $a0, 0x3FF
    ctx->r11 = ctx->r4 & 0X3FF;
    // 0x800C6088: andi        $t6, $a1, 0x3FF
    ctx->r14 = ctx->r5 & 0X3FF;
    // 0x800C608C: sll         $t7, $t6, 14
    ctx->r15 = S32(ctx->r14 << 14);
    // 0x800C6090: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800C6094: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800C6098: or          $t1, $t7, $t9
    ctx->r9 = ctx->r15 | ctx->r25;
    // 0x800C609C: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x800C60A0: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800C60A4: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
L_800C60A8:
    // 0x800C60A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C60AC:
    // 0x800C60AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C60B0: jr          $ra
    // 0x800C60B4: nop

    return;
    // 0x800C60B4: nop

;}
RECOMP_FUNC void render_dialogue_box(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C60B8: addiu       $sp, $sp, -0x180
    ctx->r29 = ADD32(ctx->r29, -0X180);
    // 0x800C60BC: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x800C60C0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C60C4: lw          $t7, -0x5258($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5258);
    // 0x800C60C8: addu        $t6, $t6, $a3
    ctx->r14 = ADD32(ctx->r14, ctx->r7);
    // 0x800C60CC: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x800C60D0: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800C60D4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800C60D8: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x800C60DC: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x800C60E0: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x800C60E4: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800C60E8: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800C60EC: sw          $a2, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r6;
    // 0x800C60F0: addu        $s1, $t6, $t7
    ctx->r17 = ADD32(ctx->r14, ctx->r15);
    // 0x800C60F4: lbu         $t8, 0x13($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X13);
    // 0x800C60F8: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800C60FC: beq         $t8, $zero, L_800C6354
    if (ctx->r24 == 0) {
        // 0x800C6100: or          $s3, $a0, $zero
        ctx->r19 = ctx->r4 | 0;
            goto L_800C6354;
    }
    // 0x800C6100: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800C6104: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C6108: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800C610C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800C6110: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800C6114: addiu       $t3, $t3, 0x3C20
    ctx->r11 = ADD32(ctx->r11, 0X3C20);
    // 0x800C6118: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x800C611C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800C6120: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800C6124: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C6128: lui         $t5, 0x702
    ctx->r13 = S32(0X702 << 16);
    // 0x800C612C: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800C6130: sw          $t4, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r12;
    // 0x800C6134: lui         $t6, 0xE
    ctx->r14 = S32(0XE << 16);
    // 0x800C6138: addiu       $t6, $t6, 0x3C68
    ctx->r14 = ADD32(ctx->r14, 0X3C68);
    // 0x800C613C: ori         $t5, $t5, 0x10
    ctx->r13 = ctx->r13 | 0X10;
    // 0x800C6140: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800C6144: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800C6148: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x800C614C: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x800C6150: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800C6154: sw          $t7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r15;
    // 0x800C6158: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800C615C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800C6160: lh          $t1, 0x4($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X4);
    // 0x800C6164: lh          $t0, 0x8($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X8);
    // 0x800C6168: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800C616C: subu        $t9, $t0, $t1
    ctx->r25 = SUB32(ctx->r8, ctx->r9);
    // 0x800C6170: slti        $at, $t9, 0xA
    ctx->r1 = SIGNED(ctx->r25) < 0XA ? 1 : 0;
    // 0x800C6174: bne         $at, $zero, L_800C6198
    if (ctx->r1 != 0) {
        // 0x800C6178: addiu       $a1, $t1, -0x2
        ctx->r5 = ADD32(ctx->r9, -0X2);
            goto L_800C6198;
    }
    // 0x800C6178: addiu       $a1, $t1, -0x2
    ctx->r5 = ADD32(ctx->r9, -0X2);
    // 0x800C617C: lh          $v0, 0xA($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XA);
    // 0x800C6180: lh          $s0, 0x6($s1)
    ctx->r16 = MEM_H(ctx->r17, 0X6);
    // 0x800C6184: addiu       $a3, $t1, 0x2
    ctx->r7 = ADD32(ctx->r9, 0X2);
    // 0x800C6188: subu        $t2, $v0, $s0
    ctx->r10 = SUB32(ctx->r2, ctx->r16);
    // 0x800C618C: slti        $at, $t2, 0xA
    ctx->r1 = SIGNED(ctx->r10) < 0XA ? 1 : 0;
    // 0x800C6190: beq         $at, $zero, L_800C61BC
    if (ctx->r1 == 0) {
        // 0x800C6194: addiu       $a2, $s0, 0x2
        ctx->r6 = ADD32(ctx->r16, 0X2);
            goto L_800C61BC;
    }
    // 0x800C6194: addiu       $a2, $s0, 0x2
    ctx->r6 = ADD32(ctx->r16, 0X2);
L_800C6198:
    // 0x800C6198: lh          $t3, 0xA($s1)
    ctx->r11 = MEM_H(ctx->r17, 0XA);
    // 0x800C619C: lh          $a2, 0x6($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X6);
    // 0x800C61A0: addiu       $t4, $t3, 0x2
    ctx->r12 = ADD32(ctx->r11, 0X2);
    // 0x800C61A4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800C61A8: addiu       $a3, $t0, 0x2
    ctx->r7 = ADD32(ctx->r8, 0X2);
    // 0x800C61AC: jal         0x800C6000
    // 0x800C61B0: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    render_fill_rectangle(rdram, ctx);
        goto after_0;
    // 0x800C61B0: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    after_0:
    // 0x800C61B4: b           L_800C624C
    // 0x800C61B8: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
        goto L_800C624C;
    // 0x800C61B8: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
L_800C61BC:
    // 0x800C61BC: addiu       $t5, $v0, -0x2
    ctx->r13 = ADD32(ctx->r2, -0X2);
    // 0x800C61C0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800C61C4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800C61C8: jal         0x800C6000
    // 0x800C61CC: addiu       $a1, $t1, -0x2
    ctx->r5 = ADD32(ctx->r9, -0X2);
    render_fill_rectangle(rdram, ctx);
        goto after_1;
    // 0x800C61CC: addiu       $a1, $t1, -0x2
    ctx->r5 = ADD32(ctx->r9, -0X2);
    after_1:
    // 0x800C61D0: lh          $s0, 0x6($s1)
    ctx->r16 = MEM_H(ctx->r17, 0X6);
    // 0x800C61D4: lh          $a1, 0x4($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X4);
    // 0x800C61D8: lh          $a3, 0x8($s1)
    ctx->r7 = MEM_H(ctx->r17, 0X8);
    // 0x800C61DC: addiu       $t6, $s0, 0x2
    ctx->r14 = ADD32(ctx->r16, 0X2);
    // 0x800C61E0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800C61E4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800C61E8: addiu       $a2, $s0, -0x2
    ctx->r6 = ADD32(ctx->r16, -0X2);
    // 0x800C61EC: addiu       $a1, $a1, -0x2
    ctx->r5 = ADD32(ctx->r5, -0X2);
    // 0x800C61F0: jal         0x800C6000
    // 0x800C61F4: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    render_fill_rectangle(rdram, ctx);
        goto after_2;
    // 0x800C61F4: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    after_2:
    // 0x800C61F8: lh          $t0, 0x8($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X8);
    // 0x800C61FC: lh          $t7, 0xA($s1)
    ctx->r15 = MEM_H(ctx->r17, 0XA);
    // 0x800C6200: lh          $a2, 0x6($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X6);
    // 0x800C6204: addiu       $t8, $t7, -0x2
    ctx->r24 = ADD32(ctx->r15, -0X2);
    // 0x800C6208: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800C620C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800C6210: addiu       $a1, $t0, -0x2
    ctx->r5 = ADD32(ctx->r8, -0X2);
    // 0x800C6214: addiu       $a3, $t0, 0x2
    ctx->r7 = ADD32(ctx->r8, 0X2);
    // 0x800C6218: jal         0x800C6000
    // 0x800C621C: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    render_fill_rectangle(rdram, ctx);
        goto after_3;
    // 0x800C621C: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    after_3:
    // 0x800C6220: lh          $v0, 0xA($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XA);
    // 0x800C6224: lh          $a1, 0x4($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X4);
    // 0x800C6228: lh          $a3, 0x8($s1)
    ctx->r7 = MEM_H(ctx->r17, 0X8);
    // 0x800C622C: addiu       $t9, $v0, 0x2
    ctx->r25 = ADD32(ctx->r2, 0X2);
    // 0x800C6230: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800C6234: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800C6238: addiu       $a2, $v0, -0x2
    ctx->r6 = ADD32(ctx->r2, -0X2);
    // 0x800C623C: addiu       $a1, $a1, -0x2
    ctx->r5 = ADD32(ctx->r5, -0X2);
    // 0x800C6240: jal         0x800C6000
    // 0x800C6244: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    render_fill_rectangle(rdram, ctx);
        goto after_4;
    // 0x800C6244: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    after_4:
    // 0x800C6248: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
L_800C624C:
    // 0x800C624C: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x800C6250: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x800C6254: sw          $t2, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r10;
    // 0x800C6258: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800C625C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800C6260: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x800C6264: lui         $t5, 0xFB00
    ctx->r13 = S32(0XFB00 << 16);
    // 0x800C6268: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800C626C: sw          $t4, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r12;
    // 0x800C6270: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800C6274: lbu         $t7, 0x10($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X10);
    // 0x800C6278: lbu         $t2, 0x11($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X11);
    // 0x800C627C: sll         $t8, $t7, 24
    ctx->r24 = S32(ctx->r15 << 24);
    // 0x800C6280: lbu         $t6, 0x12($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X12);
    // 0x800C6284: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x800C6288: or          $t4, $t8, $t3
    ctx->r12 = ctx->r24 | ctx->r11;
    // 0x800C628C: lbu         $t8, 0x13($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X13);
    // 0x800C6290: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x800C6294: or          $t9, $t4, $t7
    ctx->r25 = ctx->r12 | ctx->r15;
    // 0x800C6298: or          $t3, $t9, $t8
    ctx->r11 = ctx->r25 | ctx->r24;
    // 0x800C629C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800C62A0: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800C62A4: lb          $t5, 0x3CA0($t5)
    ctx->r13 = MEM_B(ctx->r13, 0X3CA0);
    // 0x800C62A8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800C62AC: bltz        $t5, L_800C633C
    if (SIGNED(ctx->r13) < 0) {
        // 0x800C62B0: addiu       $s0, $t6, 0x3CA0
        ctx->r16 = ADD32(ctx->r14, 0X3CA0);
            goto L_800C633C;
    }
    // 0x800C62B0: addiu       $s0, $t6, 0x3CA0
    ctx->r16 = ADD32(ctx->r14, 0X3CA0);
    // 0x800C62B4: lb          $v0, 0x0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X0);
    // 0x800C62B8: nop

L_800C62BC:
    // 0x800C62BC: lh          $t4, 0x4($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X4);
    // 0x800C62C0: lb          $t7, 0x1($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1);
    // 0x800C62C4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800C62C8: beq         $t7, $zero, L_800C62E0
    if (ctx->r15 == 0) {
        // 0x800C62CC: addu        $a1, $v0, $t4
        ctx->r5 = ADD32(ctx->r2, ctx->r12);
            goto L_800C62E0;
    }
    // 0x800C62CC: addu        $a1, $v0, $t4
    ctx->r5 = ADD32(ctx->r2, ctx->r12);
    // 0x800C62D0: lb          $t2, 0x2($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X2);
    // 0x800C62D4: lh          $t9, 0xA($s1)
    ctx->r25 = MEM_H(ctx->r17, 0XA);
    // 0x800C62D8: b           L_800C62F0
    // 0x800C62DC: addu        $a2, $t2, $t9
    ctx->r6 = ADD32(ctx->r10, ctx->r25);
        goto L_800C62F0;
    // 0x800C62DC: addu        $a2, $t2, $t9
    ctx->r6 = ADD32(ctx->r10, ctx->r25);
L_800C62E0:
    // 0x800C62E0: lb          $t8, 0x2($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X2);
    // 0x800C62E4: lh          $t3, 0x6($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X6);
    // 0x800C62E8: nop

    // 0x800C62EC: addu        $a2, $t8, $t3
    ctx->r6 = ADD32(ctx->r24, ctx->r11);
L_800C62F0:
    // 0x800C62F0: lh          $t5, 0x8($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X8);
    // 0x800C62F4: lb          $t6, 0x3($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X3);
    // 0x800C62F8: subu        $a3, $t5, $v0
    ctx->r7 = SUB32(ctx->r13, ctx->r2);
    // 0x800C62FC: beq         $t6, $zero, L_800C6314
    if (ctx->r14 == 0) {
        // 0x800C6300: nop
    
            goto L_800C6314;
    }
    // 0x800C6300: nop

    // 0x800C6304: lb          $t4, 0x4($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X4);
    // 0x800C6308: lh          $t7, 0xA($s1)
    ctx->r15 = MEM_H(ctx->r17, 0XA);
    // 0x800C630C: b           L_800C6324
    // 0x800C6310: addu        $v0, $t4, $t7
    ctx->r2 = ADD32(ctx->r12, ctx->r15);
        goto L_800C6324;
    // 0x800C6310: addu        $v0, $t4, $t7
    ctx->r2 = ADD32(ctx->r12, ctx->r15);
L_800C6314:
    // 0x800C6314: lb          $t2, 0x4($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X4);
    // 0x800C6318: lh          $t9, 0x6($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X6);
    // 0x800C631C: nop

    // 0x800C6320: addu        $v0, $t2, $t9
    ctx->r2 = ADD32(ctx->r10, ctx->r25);
L_800C6324:
    // 0x800C6324: jal         0x800C6000
    // 0x800C6328: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    render_fill_rectangle(rdram, ctx);
        goto after_5;
    // 0x800C6328: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_5:
    // 0x800C632C: lb          $v0, 0x5($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X5);
    // 0x800C6330: addiu       $s0, $s0, 0x5
    ctx->r16 = ADD32(ctx->r16, 0X5);
    // 0x800C6334: bgez        $v0, L_800C62BC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800C6338: nop
    
            goto L_800C62BC;
    }
    // 0x800C6338: nop

L_800C633C:
    // 0x800C633C: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x800C6340: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x800C6344: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800C6348: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x800C634C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800C6350: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_800C6354:
    // 0x800C6354: beq         $s2, $zero, L_800C63AC
    if (ctx->r18 == 0) {
        // 0x800C6358: nop
    
            goto L_800C63AC;
    }
    // 0x800C6358: nop

    // 0x800C635C: lw          $t5, 0x188($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X188);
    // 0x800C6360: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800C6364: beq         $t5, $zero, L_800C63AC
    if (ctx->r13 == 0) {
        // 0x800C6368: addiu       $s0, $s0, 0x3C78
        ctx->r16 = ADD32(ctx->r16, 0X3C78);
            goto L_800C63AC;
    }
    // 0x800C6368: addiu       $s0, $s0, 0x3C78
    ctx->r16 = ADD32(ctx->r16, 0X3C78);
    // 0x800C636C: lb          $t6, 0x0($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X0);
    // 0x800C6370: nop

    // 0x800C6374: bne         $t6, $zero, L_800C6390
    if (ctx->r14 != 0) {
        // 0x800C6378: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_800C6390;
    }
    // 0x800C6378: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800C637C: jal         0x8009EEE4
    // 0x800C6380: nop

    dialogue_open_stub(rdram, ctx);
        goto after_6;
    // 0x800C6380: nop

    after_6:
    // 0x800C6384: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800C6388: sb          $t4, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r12;
    // 0x800C638C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
L_800C6390:
    // 0x800C6390: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C6394: lw          $a3, 0x188($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X188);
    // 0x800C6398: sb          $t7, -0x524C($at)
    MEM_B(-0X524C, ctx->r1) = ctx->r15;
    // 0x800C639C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C63A0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800C63A4: jal         0x8009EEF4
    // 0x800C63A8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    dialogue_ortho(rdram, ctx);
        goto after_7;
    // 0x800C63A8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_7:
L_800C63AC:
    // 0x800C63AC: lw          $s0, 0x24($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X24);
    // 0x800C63B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C63B4: beq         $s0, $zero, L_800C64A0
    if (ctx->r16 == 0) {
        // 0x800C63B8: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_800C64A0;
    }
    // 0x800C63B8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800C63BC: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800C63C0: addiu       $s2, $sp, 0x6C
    ctx->r18 = ADD32(ctx->r29, 0X6C);
L_800C63C4:
    // 0x800C63C4: lh          $t2, 0x8($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X8);
    // 0x800C63C8: lh          $t9, 0xC($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XC);
    // 0x800C63CC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800C63D0: addu        $t8, $t2, $t9
    ctx->r24 = ADD32(ctx->r10, ctx->r25);
    // 0x800C63D4: sh          $t8, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r24;
    // 0x800C63D8: lh          $t5, 0xE($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XE);
    // 0x800C63DC: lh          $t3, 0xA($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XA);
    // 0x800C63E0: nop

    // 0x800C63E4: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x800C63E8: sh          $t6, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r14;
    // 0x800C63EC: lbu         $t4, 0x10($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X10);
    // 0x800C63F0: nop

    // 0x800C63F4: sb          $t4, 0x14($s1)
    MEM_B(0X14, ctx->r17) = ctx->r12;
    // 0x800C63F8: lbu         $t7, 0x11($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X11);
    // 0x800C63FC: nop

    // 0x800C6400: sb          $t7, 0x15($s1)
    MEM_B(0X15, ctx->r17) = ctx->r15;
    // 0x800C6404: lbu         $t2, 0x12($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X12);
    // 0x800C6408: nop

    // 0x800C640C: sb          $t2, 0x16($s1)
    MEM_B(0X16, ctx->r17) = ctx->r10;
    // 0x800C6410: lbu         $t9, 0x13($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X13);
    // 0x800C6414: nop

    // 0x800C6418: sb          $t9, 0x17($s1)
    MEM_B(0X17, ctx->r17) = ctx->r25;
    // 0x800C641C: lbu         $t8, 0x14($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X14);
    // 0x800C6420: nop

    // 0x800C6424: sb          $t8, 0x18($s1)
    MEM_B(0X18, ctx->r17) = ctx->r24;
    // 0x800C6428: lbu         $t3, 0x15($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X15);
    // 0x800C642C: nop

    // 0x800C6430: sb          $t3, 0x19($s1)
    MEM_B(0X19, ctx->r17) = ctx->r11;
    // 0x800C6434: lbu         $t5, 0x16($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X16);
    // 0x800C6438: nop

    // 0x800C643C: sb          $t5, 0x1A($s1)
    MEM_B(0X1A, ctx->r17) = ctx->r13;
    // 0x800C6440: lbu         $t6, 0x17($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X17);
    // 0x800C6444: nop

    // 0x800C6448: sb          $t6, 0x1B($s1)
    MEM_B(0X1B, ctx->r17) = ctx->r14;
    // 0x800C644C: lbu         $t4, 0x18($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X18);
    // 0x800C6450: nop

    // 0x800C6454: sb          $t4, 0x1C($s1)
    MEM_B(0X1C, ctx->r17) = ctx->r12;
    // 0x800C6458: lbu         $t7, 0x19($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X19);
    // 0x800C645C: nop

    // 0x800C6460: sb          $t7, 0x1D($s1)
    MEM_B(0X1D, ctx->r17) = ctx->r15;
    // 0x800C6464: lbu         $a2, 0x1($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X1);
    // 0x800C6468: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x800C646C: jal         0x800C64C0
    // 0x800C6470: nop

    parse_string_with_number(rdram, ctx);
        goto after_8;
    // 0x800C6470: nop

    after_8:
    // 0x800C6474: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800C6478: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800C647C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800C6480: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800C6484: jal         0x800C4B04
    // 0x800C6488: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    render_text_string(rdram, ctx);
        goto after_9;
    // 0x800C6488: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_9:
    // 0x800C648C: lw          $s0, 0x1C($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X1C);
    // 0x800C6490: nop

    // 0x800C6494: bne         $s0, $zero, L_800C63C4
    if (ctx->r16 != 0) {
        // 0x800C6498: nop
    
            goto L_800C63C4;
    }
    // 0x800C6498: nop

    // 0x800C649C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_800C64A0:
    // 0x800C64A0: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800C64A4: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800C64A8: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x800C64AC: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x800C64B0: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x800C64B4: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x800C64B8: jr          $ra
    // 0x800C64BC: addiu       $sp, $sp, 0x180
    ctx->r29 = ADD32(ctx->r29, 0X180);
    return;
    // 0x800C64BC: addiu       $sp, $sp, 0x180
    ctx->r29 = ADD32(ctx->r29, 0X180);
;}
RECOMP_FUNC void parse_string_with_number(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C64C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C64C4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C64C8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800C64CC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800C64D0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C64D4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C64D8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800C64DC: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800C64E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C64E4: beq         $v0, $zero, L_800C6538
    if (ctx->r2 == 0) {
        // 0x800C64E8: or          $s3, $a2, $zero
        ctx->r19 = ctx->r6 | 0;
            goto L_800C6538;
    }
    // 0x800C64E8: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x800C64EC: addiu       $s2, $sp, 0x2C
    ctx->r18 = ADD32(ctx->r29, 0X2C);
    // 0x800C64F0: addiu       $s1, $zero, 0x7E
    ctx->r17 = ADD32(0, 0X7E);
L_800C64F4:
    // 0x800C64F4: bne         $s1, $v0, L_800C650C
    if (ctx->r17 != ctx->r2) {
        // 0x800C64F8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800C650C;
    }
    // 0x800C64F8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C64FC: jal         0x800C5D6C
    // 0x800C6500: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    s32_to_string(rdram, ctx);
        goto after_0;
    // 0x800C6500: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_0:
    // 0x800C6504: b           L_800C6528
    // 0x800C6508: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_800C6528;
    // 0x800C6508: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800C650C:
    // 0x800C650C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800C6510: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800C6514: sb          $v0, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r2;
    // 0x800C6518: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800C651C: nop

    // 0x800C6520: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800C6524: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
L_800C6528:
    // 0x800C6528: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800C652C: nop

    // 0x800C6530: bne         $v0, $zero, L_800C64F4
    if (ctx->r2 != 0) {
        // 0x800C6534: nop
    
            goto L_800C64F4;
    }
    // 0x800C6534: nop

L_800C6538:
    // 0x800C6538: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800C653C: nop

    // 0x800C6540: sb          $zero, 0x0($t9)
    MEM_B(0X0, ctx->r25) = 0;
    // 0x800C6544: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C6548: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800C654C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800C6550: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800C6554: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800C6558: jr          $ra
    // 0x800C655C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800C655C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void gzip_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C66D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C66D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C66D8: addiu       $a0, $zero, 0x2800
    ctx->r4 = ADD32(0, 0X2800);
    // 0x800C66DC: jal         0x80070EDC
    // 0x800C66E0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x800C66E0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_0:
    // 0x800C66E4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C66E8: sw          $v0, 0x3CF0($at)
    MEM_W(0X3CF0, ctx->r1) = ctx->r2;
    // 0x800C66EC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x800C66F0: jal         0x80070EDC
    // 0x800C66F4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x800C66F4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_1:
    // 0x800C66F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C66FC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C6700: sw          $v0, 0x3CF4($at)
    MEM_W(0X3CF4, ctx->r1) = ctx->r2;
    // 0x800C6704: jr          $ra
    // 0x800C6708: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C6708: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void byteswap32(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C670C: lbu         $t6, 0x1($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X1);
    // 0x800C6710: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x800C6714: lbu         $t8, 0x2($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X2);
    // 0x800C6718: lbu         $t0, 0x3($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X3);
    // 0x800C671C: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x800C6720: or          $v1, $v1, $t7
    ctx->r3 = ctx->r3 | ctx->r15;
    // 0x800C6724: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800C6728: or          $v1, $v1, $t9
    ctx->r3 = ctx->r3 | ctx->r25;
    // 0x800C672C: sll         $t1, $t0, 24
    ctx->r9 = S32(ctx->r8 << 24);
    // 0x800C6730: addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
    // 0x800C6734: jr          $ra
    // 0x800C6738: or          $v0, $v1, $t1
    ctx->r2 = ctx->r3 | ctx->r9;
    return;
    // 0x800C6738: or          $v0, $v1, $t1
    ctx->r2 = ctx->r3 | ctx->r9;
;}
RECOMP_FUNC void gzip_size_uncompressed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C673C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800C6740: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C6744: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800C6748: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C674C: lw          $a1, 0x3CF4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3CF4);
    // 0x800C6750: jal         0x80077190
    // 0x800C6754: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    asset_load(rdram, ctx);
        goto after_0;
    // 0x800C6754: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_0:
    // 0x800C6758: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800C675C: lw          $a0, 0x3CF4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3CF4);
    // 0x800C6760: jal         0x800C670C
    // 0x800C6764: nop

    byteswap32(rdram, ctx);
        goto after_1;
    // 0x800C6764: nop

    after_1:
    // 0x800C6768: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C676C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C6770: jr          $ra
    // 0x800C6774: nop

    return;
    // 0x800C6774: nop

;}
RECOMP_FUNC void gzip_inflate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6778: addiu       $t6, $a0, 0x5
    ctx->r14 = ADD32(ctx->r4, 0X5);
    // 0x800C677C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C6780: sw          $t6, 0x3CF8($at)
    MEM_W(0X3CF8, ctx->r1) = ctx->r14;
    // 0x800C6784: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C6788: sw          $a1, 0x3CFC($at)
    MEM_W(0X3CFC, ctx->r1) = ctx->r5;
    // 0x800C678C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C6790: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C6794: sw          $zero, -0x4F6C($at)
    MEM_W(-0X4F6C, ctx->r1) = 0;
    // 0x800C6798: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C679C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C67A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C67A4: jal         0x800C6E20
    // 0x800C67A8: sw          $zero, -0x4F70($at)
    MEM_W(-0X4F70, ctx->r1) = 0;
    gzip_inflate_block(rdram, ctx);
        goto after_0;
    // 0x800C67A8: sw          $zero, -0x4F70($at)
    MEM_W(-0X4F70, ctx->r1) = 0;
    after_0:
    // 0x800C67AC: beq         $v0, $zero, L_800C67C8
    if (ctx->r2 == 0) {
        // 0x800C67B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C67C8;
    }
    // 0x800C67B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C67B4:
    // 0x800C67B4: jal         0x800C6E20
    // 0x800C67B8: nop

    gzip_inflate_block(rdram, ctx);
        goto after_1;
    // 0x800C67B8: nop

    after_1:
    // 0x800C67BC: bne         $v0, $zero, L_800C67B4
    if (ctx->r2 != 0) {
        // 0x800C67C0: nop
    
            goto L_800C67B4;
    }
    // 0x800C67C0: nop

    // 0x800C67C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C67C8:
    // 0x800C67C8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800C67CC: jr          $ra
    // 0x800C67D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C67D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void gzip_huft_build(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C67D4: addiu       $sp, $sp, -0x5F8
    ctx->r29 = ADD32(ctx->r29, -0X5F8);
    // 0x800C67D8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800C67DC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800C67E0: addiu       $s1, $sp, 0x5B0
    ctx->r17 = ADD32(ctx->r29, 0X5B0);
    // 0x800C67E4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800C67E8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800C67EC: sw          $a1, 0x5FC($sp)
    MEM_W(0X5FC, ctx->r29) = ctx->r5;
    // 0x800C67F0: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800C67F4: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800C67F8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800C67FC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800C6800: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800C6804: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800C6808: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C680C: sw          $a2, 0x600($sp)
    MEM_W(0X600, ctx->r29) = ctx->r6;
    // 0x800C6810: sw          $a3, 0x604($sp)
    MEM_W(0X604, ctx->r29) = ctx->r7;
    // 0x800C6814: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    // 0x800C6818: jal         0x800D0A40
    // 0x800C681C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    bzero_recomp(rdram, ctx);
        goto after_0;
    // 0x800C681C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x800C6820: lw          $t6, 0x5FC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5FC);
    // 0x800C6824: or          $fp, $s2, $zero
    ctx->r30 = ctx->r18 | 0;
    // 0x800C6828: andi        $v0, $t6, 0x3
    ctx->r2 = ctx->r14 & 0X3;
    // 0x800C682C: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x800C6830: beq         $v0, $zero, L_800C6868
    if (ctx->r2 == 0) {
        // 0x800C6834: or          $ra, $t6, $zero
        ctx->r31 = ctx->r14 | 0;
            goto L_800C6868;
    }
    // 0x800C6834: or          $ra, $t6, $zero
    ctx->r31 = ctx->r14 | 0;
    // 0x800C6838: addu        $v1, $v0, $t6
    ctx->r3 = ADD32(ctx->r2, ctx->r14);
L_800C683C:
    // 0x800C683C: lw          $t7, 0x0($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X0);
    // 0x800C6840: addiu       $ra, $ra, -0x1
    ctx->r31 = ADD32(ctx->r31, -0X1);
    // 0x800C6844: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800C6848: addu        $v0, $s1, $t8
    ctx->r2 = ADD32(ctx->r17, ctx->r24);
    // 0x800C684C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800C6850: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x800C6854: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800C6858: bne         $v1, $ra, L_800C683C
    if (ctx->r3 != ctx->r31) {
        // 0x800C685C: sw          $t6, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r14;
            goto L_800C683C;
    }
    // 0x800C685C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800C6860: beq         $ra, $zero, L_800C68F0
    if (ctx->r31 == 0) {
        // 0x800C6864: lw          $t7, 0x5FC($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X5FC);
            goto L_800C68F0;
    }
    // 0x800C6864: lw          $t7, 0x5FC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5FC);
L_800C6868:
    // 0x800C6868: lw          $t7, 0x0($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X0);
    // 0x800C686C: addiu       $ra, $ra, -0x4
    ctx->r31 = ADD32(ctx->r31, -0X4);
    // 0x800C6870: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800C6874: addu        $v0, $s1, $t8
    ctx->r2 = ADD32(ctx->r17, ctx->r24);
    // 0x800C6878: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800C687C: addiu       $fp, $fp, 0x10
    ctx->r30 = ADD32(ctx->r30, 0X10);
    // 0x800C6880: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800C6884: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800C6888: lw          $t7, -0xC($fp)
    ctx->r15 = MEM_W(ctx->r30, -0XC);
    // 0x800C688C: nop

    // 0x800C6890: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800C6894: addu        $v0, $s1, $t8
    ctx->r2 = ADD32(ctx->r17, ctx->r24);
    // 0x800C6898: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800C689C: nop

    // 0x800C68A0: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800C68A4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800C68A8: lw          $t7, -0x8($fp)
    ctx->r15 = MEM_W(ctx->r30, -0X8);
    // 0x800C68AC: nop

    // 0x800C68B0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800C68B4: addu        $v0, $s1, $t8
    ctx->r2 = ADD32(ctx->r17, ctx->r24);
    // 0x800C68B8: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800C68BC: nop

    // 0x800C68C0: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800C68C4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800C68C8: lw          $t7, -0x4($fp)
    ctx->r15 = MEM_W(ctx->r30, -0X4);
    // 0x800C68CC: nop

    // 0x800C68D0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800C68D4: addu        $v0, $s1, $t8
    ctx->r2 = ADD32(ctx->r17, ctx->r24);
    // 0x800C68D8: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800C68DC: nop

    // 0x800C68E0: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800C68E4: bne         $ra, $zero, L_800C6868
    if (ctx->r31 != 0) {
        // 0x800C68E8: sw          $t6, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r14;
            goto L_800C6868;
    }
    // 0x800C68E8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800C68EC: lw          $t7, 0x5FC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5FC);
L_800C68F0:
    // 0x800C68F0: lw          $t8, 0x5B0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5B0);
    // 0x800C68F4: lw          $a1, 0x610($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X610);
    // 0x800C68F8: bne         $t7, $t8, L_800C6918
    if (ctx->r15 != ctx->r24) {
        // 0x800C68FC: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_800C6918;
    }
    // 0x800C68FC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800C6900: lw          $a1, 0x610($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X610);
    // 0x800C6904: lw          $s5, 0x60C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60C);
    // 0x800C6908: nop

    // 0x800C690C: sw          $zero, 0x0($s5)
    MEM_W(0X0, ctx->r21) = 0;
    // 0x800C6910: b           L_800C6DEC
    // 0x800C6914: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
        goto L_800C6DEC;
    // 0x800C6914: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_800C6918:
    // 0x800C6918: lw          $s0, 0x0($a1)
    ctx->r16 = MEM_W(ctx->r5, 0X0);
    // 0x800C691C: addiu       $a0, $sp, 0x5B4
    ctx->r4 = ADD32(ctx->r29, 0X5B4);
    // 0x800C6920: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
L_800C6924:
    // 0x800C6924: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x800C6928: nop

    // 0x800C692C: bne         $t9, $zero, L_800C6944
    if (ctx->r25 != 0) {
        // 0x800C6930: sltu        $at, $s0, $a3
        ctx->r1 = ctx->r16 < ctx->r7 ? 1 : 0;
            goto L_800C6944;
    }
    // 0x800C6930: sltu        $at, $s0, $a3
    ctx->r1 = ctx->r16 < ctx->r7 ? 1 : 0;
    // 0x800C6934: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800C6938: bne         $a3, $v0, L_800C6924
    if (ctx->r7 != ctx->r2) {
        // 0x800C693C: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_800C6924;
    }
    // 0x800C693C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800C6940: sltu        $at, $s0, $a3
    ctx->r1 = ctx->r16 < ctx->r7 ? 1 : 0;
L_800C6944:
    // 0x800C6944: beq         $at, $zero, L_800C6950
    if (ctx->r1 == 0) {
        // 0x800C6948: or          $s4, $a3, $zero
        ctx->r20 = ctx->r7 | 0;
            goto L_800C6950;
    }
    // 0x800C6948: or          $s4, $a3, $zero
    ctx->r20 = ctx->r7 | 0;
    // 0x800C694C: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
L_800C6950:
    // 0x800C6950: addiu       $ra, $zero, 0x10
    ctx->r31 = ADD32(0, 0X10);
    // 0x800C6954: addiu       $v1, $sp, 0x5F0
    ctx->r3 = ADD32(ctx->r29, 0X5F0);
L_800C6958:
    // 0x800C6958: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C695C: nop

    // 0x800C6960: bne         $t6, $zero, L_800C6978
    if (ctx->r14 != 0) {
        // 0x800C6964: sltu        $at, $ra, $s0
        ctx->r1 = ctx->r31 < ctx->r16 ? 1 : 0;
            goto L_800C6978;
    }
    // 0x800C6964: sltu        $at, $ra, $s0
    ctx->r1 = ctx->r31 < ctx->r16 ? 1 : 0;
    // 0x800C6968: addiu       $ra, $ra, -0x1
    ctx->r31 = ADD32(ctx->r31, -0X1);
    // 0x800C696C: bne         $ra, $zero, L_800C6958
    if (ctx->r31 != 0) {
        // 0x800C6970: addiu       $v1, $v1, -0x4
        ctx->r3 = ADD32(ctx->r3, -0X4);
            goto L_800C6958;
    }
    // 0x800C6970: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x800C6974: sltu        $at, $ra, $s0
    ctx->r1 = ctx->r31 < ctx->r16 ? 1 : 0;
L_800C6978:
    // 0x800C6978: beq         $at, $zero, L_800C6984
    if (ctx->r1 == 0) {
        // 0x800C697C: sw          $ra, 0x5A8($sp)
        MEM_W(0X5A8, ctx->r29) = ctx->r31;
            goto L_800C6984;
    }
    // 0x800C697C: sw          $ra, 0x5A8($sp)
    MEM_W(0X5A8, ctx->r29) = ctx->r31;
    // 0x800C6980: or          $s0, $ra, $zero
    ctx->r16 = ctx->r31 | 0;
L_800C6984:
    // 0x800C6984: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C6988: sltu        $at, $a3, $ra
    ctx->r1 = ctx->r7 < ctx->r31 ? 1 : 0;
    // 0x800C698C: sw          $s0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r16;
    // 0x800C6990: beq         $at, $zero, L_800C69C0
    if (ctx->r1 == 0) {
        // 0x800C6994: sllv        $v0, $t7, $a3
        ctx->r2 = S32(ctx->r15 << (ctx->r7 & 31));
            goto L_800C69C0;
    }
    // 0x800C6994: sllv        $v0, $t7, $a3
    ctx->r2 = S32(ctx->r15 << (ctx->r7 & 31));
    // 0x800C6998: sll         $t8, $ra, 2
    ctx->r24 = S32(ctx->r31 << 2);
    // 0x800C699C: addiu       $t9, $sp, 0x5B0
    ctx->r25 = ADD32(ctx->r29, 0X5B0);
    // 0x800C69A0: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
L_800C69A4:
    // 0x800C69A4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800C69A8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800C69AC: subu        $v0, $v0, $t6
    ctx->r2 = SUB32(ctx->r2, ctx->r14);
    // 0x800C69B0: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x800C69B4: sltu        $at, $a0, $a1
    ctx->r1 = ctx->r4 < ctx->r5 ? 1 : 0;
    // 0x800C69B8: bne         $at, $zero, L_800C69A4
    if (ctx->r1 != 0) {
        // 0x800C69BC: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_800C69A4;
    }
    // 0x800C69BC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800C69C0:
    // 0x800C69C0: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x800C69C4: addiu       $ra, $ra, -0x1
    ctx->r31 = ADD32(ctx->r31, -0X1);
    // 0x800C69C8: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x800C69CC: addu        $t8, $a0, $v0
    ctx->r24 = ADD32(ctx->r4, ctx->r2);
    // 0x800C69D0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800C69D4: sw          $zero, 0x80($sp)
    MEM_W(0X80, ctx->r29) = 0;
    // 0x800C69D8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800C69DC: addiu       $fp, $sp, 0x5B4
    ctx->r30 = ADD32(ctx->r29, 0X5B4);
    // 0x800C69E0: addiu       $a2, $sp, 0x84
    ctx->r6 = ADD32(ctx->r29, 0X84);
    // 0x800C69E4: beq         $ra, $zero, L_800C6A74
    if (ctx->r31 == 0) {
        // 0x800C69E8: addiu       $v1, $v1, -0x4
        ctx->r3 = ADD32(ctx->r3, -0X4);
            goto L_800C6A74;
    }
    // 0x800C69E8: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x800C69EC: andi        $a1, $ra, 0x3
    ctx->r5 = ctx->r31 & 0X3;
    // 0x800C69F0: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    // 0x800C69F4: beq         $a1, $zero, L_800C6A2C
    if (ctx->r5 == 0) {
        // 0x800C69F8: addu        $v0, $a1, $ra
        ctx->r2 = ADD32(ctx->r5, ctx->r31);
            goto L_800C6A2C;
    }
    // 0x800C69F8: addu        $v0, $a1, $ra
    ctx->r2 = ADD32(ctx->r5, ctx->r31);
    // 0x800C69FC: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x800C6A00: addiu       $t6, $sp, 0x5B0
    ctx->r14 = ADD32(ctx->r29, 0X5B0);
    // 0x800C6A04: addu        $a0, $t9, $t6
    ctx->r4 = ADD32(ctx->r25, ctx->r14);
L_800C6A08:
    // 0x800C6A08: lw          $t7, 0x0($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X0);
    // 0x800C6A0C: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x800C6A10: addu        $a3, $a3, $t7
    ctx->r7 = ADD32(ctx->r7, ctx->r15);
    // 0x800C6A14: sw          $a3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r7;
    // 0x800C6A18: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800C6A1C: bne         $a0, $v1, L_800C6A08
    if (ctx->r4 != ctx->r3) {
        // 0x800C6A20: addiu       $fp, $fp, 0x4
        ctx->r30 = ADD32(ctx->r30, 0X4);
            goto L_800C6A08;
    }
    // 0x800C6A20: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x800C6A24: addiu       $t8, $sp, 0x5B0
    ctx->r24 = ADD32(ctx->r29, 0X5B0);
    // 0x800C6A28: beq         $v1, $t8, L_800C6A74
    if (ctx->r3 == ctx->r24) {
        // 0x800C6A2C: addiu       $v0, $sp, 0x5B0
        ctx->r2 = ADD32(ctx->r29, 0X5B0);
            goto L_800C6A74;
    }
L_800C6A2C:
    // 0x800C6A2C: addiu       $v0, $sp, 0x5B0
    ctx->r2 = ADD32(ctx->r29, 0X5B0);
L_800C6A30:
    // 0x800C6A30: lw          $t9, 0x0($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X0);
    // 0x800C6A34: addiu       $v1, $v1, -0x10
    ctx->r3 = ADD32(ctx->r3, -0X10);
    // 0x800C6A38: addu        $a3, $a3, $t9
    ctx->r7 = ADD32(ctx->r7, ctx->r25);
    // 0x800C6A3C: sw          $a3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r7;
    // 0x800C6A40: lw          $t6, 0x4($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X4);
    // 0x800C6A44: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x800C6A48: addu        $a3, $a3, $t6
    ctx->r7 = ADD32(ctx->r7, ctx->r14);
    // 0x800C6A4C: sw          $a3, -0xC($a2)
    MEM_W(-0XC, ctx->r6) = ctx->r7;
    // 0x800C6A50: lw          $t7, 0x8($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X8);
    // 0x800C6A54: addiu       $fp, $fp, 0x10
    ctx->r30 = ADD32(ctx->r30, 0X10);
    // 0x800C6A58: addu        $a3, $a3, $t7
    ctx->r7 = ADD32(ctx->r7, ctx->r15);
    // 0x800C6A5C: sw          $a3, -0x8($a2)
    MEM_W(-0X8, ctx->r6) = ctx->r7;
    // 0x800C6A60: lw          $t8, -0x4($fp)
    ctx->r24 = MEM_W(ctx->r30, -0X4);
    // 0x800C6A64: nop

    // 0x800C6A68: addu        $a3, $a3, $t8
    ctx->r7 = ADD32(ctx->r7, ctx->r24);
    // 0x800C6A6C: bne         $v1, $v0, L_800C6A30
    if (ctx->r3 != ctx->r2) {
        // 0x800C6A70: sw          $a3, -0x4($a2)
        MEM_W(-0X4, ctx->r6) = ctx->r7;
            goto L_800C6A30;
    }
    // 0x800C6A70: sw          $a3, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->r7;
L_800C6A74:
    // 0x800C6A74: or          $fp, $s2, $zero
    ctx->r30 = ctx->r18 | 0;
    // 0x800C6A78: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x800C6A7C: addiu       $a1, $sp, 0x7C
    ctx->r5 = ADD32(ctx->r29, 0X7C);
    // 0x800C6A80: addiu       $a0, $sp, 0xC4
    ctx->r4 = ADD32(ctx->r29, 0XC4);
L_800C6A84:
    // 0x800C6A84: lw          $a3, 0x0($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X0);
    // 0x800C6A88: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x800C6A8C: beq         $a3, $zero, L_800C6AB4
    if (ctx->r7 == 0) {
        // 0x800C6A90: sll         $t9, $a3, 2
        ctx->r25 = S32(ctx->r7 << 2);
            goto L_800C6AB4;
    }
    // 0x800C6A90: sll         $t9, $a3, 2
    ctx->r25 = S32(ctx->r7 << 2);
    // 0x800C6A94: addu        $v0, $a1, $t9
    ctx->r2 = ADD32(ctx->r5, ctx->r25);
    // 0x800C6A98: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800C6A9C: nop

    // 0x800C6AA0: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x800C6AA4: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x800C6AA8: sw          $ra, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r31;
    // 0x800C6AAC: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x800C6AB0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_800C6AB4:
    // 0x800C6AB4: lw          $t9, 0x5FC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5FC);
    // 0x800C6AB8: addiu       $ra, $ra, 0x1
    ctx->r31 = ADD32(ctx->r31, 0X1);
    // 0x800C6ABC: sltu        $at, $ra, $t9
    ctx->r1 = ctx->r31 < ctx->r25 ? 1 : 0;
    // 0x800C6AC0: bne         $at, $zero, L_800C6A84
    if (ctx->r1 != 0) {
        // 0x800C6AC4: nop
    
            goto L_800C6A84;
    }
    // 0x800C6AC4: nop

    // 0x800C6AC8: lw          $t6, 0x5A8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5A8);
    // 0x800C6ACC: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x800C6AD0: slt         $at, $t6, $s4
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x800C6AD4: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
    // 0x800C6AD8: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x800C6ADC: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800C6AE0: negu        $t2, $s0
    ctx->r10 = SUB32(0, ctx->r16);
    // 0x800C6AE4: sw          $zero, 0x544($sp)
    MEM_W(0X544, ctx->r29) = 0;
    // 0x800C6AE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C6AEC: bne         $at, $zero, L_800C6DEC
    if (ctx->r1 != 0) {
        // 0x800C6AF0: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_800C6DEC;
    }
    // 0x800C6AF0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800C6AF4: sll         $t7, $s4, 2
    ctx->r15 = S32(ctx->r20 << 2);
    // 0x800C6AF8: addiu       $t8, $sp, 0x5B0
    ctx->r24 = ADD32(ctx->r29, 0X5B0);
    // 0x800C6AFC: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x800C6B00: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800C6B04: lw          $s5, 0x60C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60C);
    // 0x800C6B08: addiu       $s2, $s2, -0x4F68
    ctx->r18 = ADD32(ctx->r18, -0X4F68);
    // 0x800C6B0C: addiu       $s7, $s7, 0x3CF0
    ctx->r23 = ADD32(ctx->r23, 0X3CF0);
    // 0x800C6B10: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x800C6B14: addiu       $s3, $sp, 0x584
    ctx->r19 = ADD32(ctx->r29, 0X584);
L_800C6B18:
    // 0x800C6B18: lw          $s6, 0x0($v0)
    ctx->r22 = MEM_W(ctx->r2, 0X0);
    // 0x800C6B1C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800C6B20: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x800C6B24: beq         $s6, $zero, L_800C6DD4
    if (ctx->r22 == 0) {
        // 0x800C6B28: addiu       $s6, $s6, -0x1
        ctx->r22 = ADD32(ctx->r22, -0X1);
            goto L_800C6DD4;
    }
    // 0x800C6B28: addiu       $s6, $s6, -0x1
    ctx->r22 = ADD32(ctx->r22, -0X1);
    // 0x800C6B2C: lw          $t6, 0x5FC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5FC);
    // 0x800C6B30: addiu       $t9, $sp, 0x7C
    ctx->r25 = ADD32(ctx->r29, 0X7C);
    // 0x800C6B34: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800C6B38: addu        $t3, $t5, $t9
    ctx->r11 = ADD32(ctx->r13, ctx->r25);
    // 0x800C6B3C: addiu       $t8, $sp, 0xC4
    ctx->r24 = ADD32(ctx->r29, 0XC4);
    // 0x800C6B40: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800C6B44: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C6B48: addiu       $t6, $s4, 0x1F
    ctx->r14 = ADD32(ctx->r20, 0X1F);
    // 0x800C6B4C: sllv        $t8, $t7, $t6
    ctx->r24 = S32(ctx->r15 << (ctx->r14 & 31));
    // 0x800C6B50: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x800C6B54: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x800C6B58: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
L_800C6B5C:
    // 0x800C6B5C: addu        $v1, $t2, $s0
    ctx->r3 = ADD32(ctx->r10, ctx->r16);
    // 0x800C6B60: slt         $at, $v1, $s4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x800C6B64: beq         $at, $zero, L_800C6C84
    if (ctx->r1 == 0) {
        // 0x800C6B68: addiu       $s1, $s6, 0x1
        ctx->r17 = ADD32(ctx->r22, 0X1);
            goto L_800C6C84;
    }
    // 0x800C6B68: addiu       $s1, $s6, 0x1
    ctx->r17 = ADD32(ctx->r22, 0X1);
    // 0x800C6B6C: addiu       $t9, $sp, 0x544
    ctx->r25 = ADD32(ctx->r29, 0X544);
    // 0x800C6B70: addu        $t1, $t5, $t9
    ctx->r9 = ADD32(ctx->r13, ctx->r25);
    // 0x800C6B74: lw          $t7, 0x5A8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5A8);
L_800C6B78:
    // 0x800C6B78: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x800C6B7C: subu        $t0, $t7, $v1
    ctx->r8 = SUB32(ctx->r15, ctx->r3);
    // 0x800C6B80: sltu        $at, $s0, $t0
    ctx->r1 = ctx->r16 < ctx->r8 ? 1 : 0;
    // 0x800C6B84: addiu       $t5, $t5, 0x4
    ctx->r13 = ADD32(ctx->r13, 0X4);
    // 0x800C6B88: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x800C6B8C: addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
    // 0x800C6B90: beq         $at, $zero, L_800C6B9C
    if (ctx->r1 == 0) {
        // 0x800C6B94: or          $t2, $v1, $zero
        ctx->r10 = ctx->r3 | 0;
            goto L_800C6B9C;
    }
    // 0x800C6B94: or          $t2, $v1, $zero
    ctx->r10 = ctx->r3 | 0;
    // 0x800C6B98: or          $t0, $s0, $zero
    ctx->r8 = ctx->r16 | 0;
L_800C6B9C:
    // 0x800C6B9C: subu        $v0, $s4, $t2
    ctx->r2 = SUB32(ctx->r20, ctx->r10);
    // 0x800C6BA0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800C6BA4: sllv        $a0, $t6, $v0
    ctx->r4 = S32(ctx->r14 << (ctx->r2 & 31));
    // 0x800C6BA8: sltu        $at, $s1, $a0
    ctx->r1 = ctx->r17 < ctx->r4 ? 1 : 0;
    // 0x800C6BAC: beq         $at, $zero, L_800C6BF8
    if (ctx->r1 == 0) {
        // 0x800C6BB0: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_800C6BF8;
    }
    // 0x800C6BB0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800C6BB4: addiu       $a3, $v0, 0x1
    ctx->r7 = ADD32(ctx->r2, 0X1);
    // 0x800C6BB8: subu        $v1, $a0, $s6
    ctx->r3 = SUB32(ctx->r4, ctx->r22);
    // 0x800C6BBC: sll         $t8, $s4, 2
    ctx->r24 = S32(ctx->r20 << 2);
    // 0x800C6BC0: addiu       $t9, $sp, 0x5B0
    ctx->r25 = ADD32(ctx->r29, 0X5B0);
    // 0x800C6BC4: sltu        $at, $a3, $t0
    ctx->r1 = ctx->r7 < ctx->r8 ? 1 : 0;
    // 0x800C6BC8: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800C6BCC: beq         $at, $zero, L_800C6BF8
    if (ctx->r1 == 0) {
        // 0x800C6BD0: addu        $a2, $t8, $t9
        ctx->r6 = ADD32(ctx->r24, ctx->r25);
            goto L_800C6BF8;
    }
    // 0x800C6BD0: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
L_800C6BD4:
    // 0x800C6BD4: lw          $a0, 0x4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X4);
    // 0x800C6BD8: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800C6BDC: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x800C6BE0: beq         $at, $zero, L_800C6BF8
    if (ctx->r1 == 0) {
        // 0x800C6BE4: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_800C6BF8;
    }
    // 0x800C6BE4: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800C6BE8: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800C6BEC: sltu        $at, $a3, $t0
    ctx->r1 = ctx->r7 < ctx->r8 ? 1 : 0;
    // 0x800C6BF0: bne         $at, $zero, L_800C6BD4
    if (ctx->r1 != 0) {
        // 0x800C6BF4: subu        $v1, $v0, $a0
        ctx->r3 = SUB32(ctx->r2, ctx->r4);
            goto L_800C6BD4;
    }
    // 0x800C6BF4: subu        $v1, $v0, $a0
    ctx->r3 = SUB32(ctx->r2, ctx->r4);
L_800C6BF8:
    // 0x800C6BF8: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x800C6BFC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C6C00: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x800C6C04: sllv        $t0, $t7, $a3
    ctx->r8 = S32(ctx->r15 << (ctx->r7 & 31));
    // 0x800C6C08: sll         $t6, $v1, 3
    ctx->r14 = S32(ctx->r3 << 3);
    // 0x800C6C0C: addu        $t9, $v1, $t0
    ctx->r25 = ADD32(ctx->r3, ctx->r8);
    // 0x800C6C10: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x800C6C14: addu        $a2, $t6, $t8
    ctx->r6 = ADD32(ctx->r14, ctx->r24);
    // 0x800C6C18: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x800C6C1C: addiu       $a0, $a2, 0x8
    ctx->r4 = ADD32(ctx->r6, 0X8);
    // 0x800C6C20: sw          $a0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r4;
    // 0x800C6C24: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x800C6C28: addiu       $s5, $a2, 0x4
    ctx->r21 = ADD32(ctx->r6, 0X4);
    // 0x800C6C2C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800C6C30: beq         $t4, $zero, L_800C6C74
    if (ctx->r12 == 0) {
        // 0x800C6C34: sw          $a0, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r4;
            goto L_800C6C74;
    }
    // 0x800C6C34: sw          $a0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r4;
    // 0x800C6C38: sw          $ra, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r31;
    // 0x800C6C3C: addiu       $t6, $a3, 0x10
    ctx->r14 = ADD32(ctx->r7, 0X10);
    // 0x800C6C40: sb          $t6, 0x584($sp)
    MEM_B(0X584, ctx->r29) = ctx->r14;
    // 0x800C6C44: sb          $s0, 0x585($sp)
    MEM_B(0X585, ctx->r29) = ctx->r16;
    // 0x800C6C48: sw          $a0, 0x588($sp)
    MEM_W(0X588, ctx->r29) = ctx->r4;
    // 0x800C6C4C: subu        $t9, $t2, $s0
    ctx->r25 = SUB32(ctx->r10, ctx->r16);
    // 0x800C6C50: lw          $t8, -0x4($t1)
    ctx->r24 = MEM_W(ctx->r9, -0X4);
    // 0x800C6C54: srlv        $t7, $ra, $t9
    ctx->r15 = S32(U32(ctx->r31) >> (ctx->r25 & 31));
    // 0x800C6C58: lw          $at, 0x0($s3)
    ctx->r1 = MEM_W(ctx->r19, 0X0);
    // 0x800C6C5C: sll         $t6, $t7, 3
    ctx->r14 = S32(ctx->r15 << 3);
    // 0x800C6C60: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x800C6C64: sw          $at, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r1;
    // 0x800C6C68: lw          $t6, 0x4($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X4);
    // 0x800C6C6C: nop

    // 0x800C6C70: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
L_800C6C74:
    // 0x800C6C74: addu        $v1, $t2, $s0
    ctx->r3 = ADD32(ctx->r10, ctx->r16);
    // 0x800C6C78: slt         $at, $v1, $s4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x800C6C7C: bne         $at, $zero, L_800C6B78
    if (ctx->r1 != 0) {
        // 0x800C6C80: lw          $t7, 0x5A8($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X5A8);
            goto L_800C6B78;
    }
    // 0x800C6C80: lw          $t7, 0x5A8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5A8);
L_800C6C84:
    // 0x800C6C84: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800C6C88: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800C6C8C: subu        $v1, $s4, $t2
    ctx->r3 = SUB32(ctx->r20, ctx->r10);
    // 0x800C6C90: sllv        $a1, $t8, $t2
    ctx->r5 = S32(ctx->r24 << (ctx->r10 & 31));
    // 0x800C6C94: sltu        $at, $fp, $t7
    ctx->r1 = ctx->r30 < ctx->r15 ? 1 : 0;
    // 0x800C6C98: sb          $v1, 0x585($sp)
    MEM_B(0X585, ctx->r29) = ctx->r3;
    // 0x800C6C9C: bne         $at, $zero, L_800C6CB0
    if (ctx->r1 != 0) {
        // 0x800C6CA0: addiu       $a1, $a1, -0x1
        ctx->r5 = ADD32(ctx->r5, -0X1);
            goto L_800C6CB0;
    }
    // 0x800C6CA0: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800C6CA4: addiu       $t9, $zero, 0x63
    ctx->r25 = ADD32(0, 0X63);
    // 0x800C6CA8: b           L_800C6D30
    // 0x800C6CAC: sb          $t9, 0x584($sp)
    MEM_B(0X584, ctx->r29) = ctx->r25;
        goto L_800C6D30;
    // 0x800C6CAC: sb          $t9, 0x584($sp)
    MEM_B(0X584, ctx->r29) = ctx->r25;
L_800C6CB0:
    // 0x800C6CB0: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x800C6CB4: lw          $t6, 0x600($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X600);
    // 0x800C6CB8: lw          $a0, 0x600($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X600);
    // 0x800C6CBC: sltu        $at, $v0, $t6
    ctx->r1 = ctx->r2 < ctx->r14 ? 1 : 0;
    // 0x800C6CC0: beq         $at, $zero, L_800C6CF0
    if (ctx->r1 == 0) {
        // 0x800C6CC4: sltiu       $at, $v0, 0x100
        ctx->r1 = ctx->r2 < 0X100 ? 1 : 0;
            goto L_800C6CF0;
    }
    // 0x800C6CC4: sltiu       $at, $v0, 0x100
    ctx->r1 = ctx->r2 < 0X100 ? 1 : 0;
    // 0x800C6CC8: beq         $at, $zero, L_800C6CDC
    if (ctx->r1 == 0) {
        // 0x800C6CCC: addiu       $t7, $zero, 0xF
        ctx->r15 = ADD32(0, 0XF);
            goto L_800C6CDC;
    }
    // 0x800C6CCC: addiu       $t7, $zero, 0xF
    ctx->r15 = ADD32(0, 0XF);
    // 0x800C6CD0: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x800C6CD4: b           L_800C6CE0
    // 0x800C6CD8: sb          $t8, 0x584($sp)
    MEM_B(0X584, ctx->r29) = ctx->r24;
        goto L_800C6CE0;
    // 0x800C6CD8: sb          $t8, 0x584($sp)
    MEM_B(0X584, ctx->r29) = ctx->r24;
L_800C6CDC:
    // 0x800C6CDC: sb          $t7, 0x584($sp)
    MEM_B(0X584, ctx->r29) = ctx->r15;
L_800C6CE0:
    // 0x800C6CE0: lw          $t9, 0x0($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X0);
    // 0x800C6CE4: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x800C6CE8: b           L_800C6D30
    // 0x800C6CEC: sh          $t9, 0x588($sp)
    MEM_H(0X588, ctx->r29) = ctx->r25;
        goto L_800C6D30;
    // 0x800C6CEC: sh          $t9, 0x588($sp)
    MEM_H(0X588, ctx->r29) = ctx->r25;
L_800C6CF0:
    // 0x800C6CF0: lw          $t8, 0x608($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X608);
    // 0x800C6CF4: subu        $t6, $v0, $a0
    ctx->r14 = SUB32(ctx->r2, ctx->r4);
    // 0x800C6CF8: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x800C6CFC: lbu         $t9, 0x0($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X0);
    // 0x800C6D00: lw          $t6, 0x604($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X604);
    // 0x800C6D04: sb          $t9, 0x584($sp)
    MEM_B(0X584, ctx->r29) = ctx->r25;
    // 0x800C6D08: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x800C6D0C: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x800C6D10: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x800C6D14: sll         $t8, $a0, 1
    ctx->r24 = S32(ctx->r4 << 1);
    // 0x800C6D18: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x800C6D1C: negu        $t6, $t8
    ctx->r14 = SUB32(0, ctx->r24);
    // 0x800C6D20: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x800C6D24: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x800C6D28: nop

    // 0x800C6D2C: sh          $t8, 0x588($sp)
    MEM_H(0X588, ctx->r29) = ctx->r24;
L_800C6D30:
    // 0x800C6D30: srlv        $a3, $ra, $t2
    ctx->r7 = S32(U32(ctx->r31) >> (ctx->r10 & 31));
    // 0x800C6D34: sltu        $at, $a3, $t0
    ctx->r1 = ctx->r7 < ctx->r8 ? 1 : 0;
    // 0x800C6D38: beq         $at, $zero, L_800C6D68
    if (ctx->r1 == 0) {
        // 0x800C6D3C: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_800C6D68;
    }
    // 0x800C6D3C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800C6D40: sllv        $v0, $t9, $v1
    ctx->r2 = S32(ctx->r25 << (ctx->r3 & 31));
L_800C6D44:
    // 0x800C6D44: lw          $at, 0x0($s3)
    ctx->r1 = MEM_W(ctx->r19, 0X0);
    // 0x800C6D48: sll         $t6, $a3, 3
    ctx->r14 = S32(ctx->r7 << 3);
    // 0x800C6D4C: addu        $t7, $a2, $t6
    ctx->r15 = ADD32(ctx->r6, ctx->r14);
    // 0x800C6D50: sw          $at, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r1;
    // 0x800C6D54: lw          $t9, 0x4($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X4);
    // 0x800C6D58: addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // 0x800C6D5C: sltu        $at, $a3, $t0
    ctx->r1 = ctx->r7 < ctx->r8 ? 1 : 0;
    // 0x800C6D60: bne         $at, $zero, L_800C6D44
    if (ctx->r1 != 0) {
        // 0x800C6D64: sw          $t9, 0x4($t7)
        MEM_W(0X4, ctx->r15) = ctx->r25;
            goto L_800C6D44;
    }
    // 0x800C6D64: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
L_800C6D68:
    // 0x800C6D68: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x800C6D6C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x800C6D70: and         $t6, $ra, $a3
    ctx->r14 = ctx->r31 & ctx->r7;
    // 0x800C6D74: beq         $t6, $zero, L_800C6D8C
    if (ctx->r14 == 0) {
        // 0x800C6D78: srl         $t8, $a3, 1
        ctx->r24 = S32(U32(ctx->r7) >> 1);
            goto L_800C6D8C;
    }
L_800C6D78:
    // 0x800C6D78: srl         $t8, $a3, 1
    ctx->r24 = S32(U32(ctx->r7) >> 1);
    // 0x800C6D7C: xor         $ra, $ra, $a3
    ctx->r31 = ctx->r31 ^ ctx->r7;
    // 0x800C6D80: and         $t7, $ra, $t8
    ctx->r15 = ctx->r31 & ctx->r24;
    // 0x800C6D84: bne         $t7, $zero, L_800C6D78
    if (ctx->r15 != 0) {
        // 0x800C6D88: or          $a3, $t8, $zero
        ctx->r7 = ctx->r24 | 0;
            goto L_800C6D78;
    }
    // 0x800C6D88: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
L_800C6D8C:
    // 0x800C6D8C: xor         $ra, $ra, $a3
    ctx->r31 = ctx->r31 ^ ctx->r7;
    // 0x800C6D90: and         $t9, $ra, $a1
    ctx->r25 = ctx->r31 & ctx->r5;
    // 0x800C6D94: beq         $t9, $v0, L_800C6DC4
    if (ctx->r25 == ctx->r2) {
        // 0x800C6D98: or          $a1, $s6, $zero
        ctx->r5 = ctx->r22 | 0;
            goto L_800C6DC4;
    }
    // 0x800C6D98: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
L_800C6D9C:
    // 0x800C6D9C: subu        $t2, $t2, $s0
    ctx->r10 = SUB32(ctx->r10, ctx->r16);
    // 0x800C6DA0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800C6DA4: sllv        $t8, $t6, $t2
    ctx->r24 = S32(ctx->r14 << (ctx->r10 & 31));
    // 0x800C6DA8: lw          $t6, -0x4($t3)
    ctx->r14 = MEM_W(ctx->r11, -0X4);
    // 0x800C6DAC: addiu       $t7, $t8, -0x1
    ctx->r15 = ADD32(ctx->r24, -0X1);
    // 0x800C6DB0: and         $t9, $ra, $t7
    ctx->r25 = ctx->r31 & ctx->r15;
    // 0x800C6DB4: addiu       $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
    // 0x800C6DB8: addiu       $t5, $t5, -0x4
    ctx->r13 = ADD32(ctx->r13, -0X4);
    // 0x800C6DBC: bne         $t9, $t6, L_800C6D9C
    if (ctx->r25 != ctx->r14) {
        // 0x800C6DC0: addiu       $t3, $t3, -0x4
        ctx->r11 = ADD32(ctx->r11, -0X4);
            goto L_800C6D9C;
    }
    // 0x800C6DC0: addiu       $t3, $t3, -0x4
    ctx->r11 = ADD32(ctx->r11, -0X4);
L_800C6DC4:
    // 0x800C6DC4: bne         $s6, $zero, L_800C6B5C
    if (ctx->r22 != 0) {
        // 0x800C6DC8: addiu       $s6, $s6, -0x1
        ctx->r22 = ADD32(ctx->r22, -0X1);
            goto L_800C6B5C;
    }
    // 0x800C6DC8: addiu       $s6, $s6, -0x1
    ctx->r22 = ADD32(ctx->r22, -0X1);
    // 0x800C6DCC: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x800C6DD0: nop

L_800C6DD4:
    // 0x800C6DD4: lw          $t8, 0x5A8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5A8);
    // 0x800C6DD8: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800C6DDC: slt         $at, $t8, $s4
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x800C6DE0: beq         $at, $zero, L_800C6B18
    if (ctx->r1 == 0) {
        // 0x800C6DE4: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800C6B18;
    }
    // 0x800C6DE4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800C6DE8: sw          $s5, 0x60C($sp)
    MEM_W(0X60C, ctx->r29) = ctx->r21;
L_800C6DEC:
    // 0x800C6DEC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800C6DF0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C6DF4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800C6DF8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800C6DFC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800C6E00: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800C6E04: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800C6E08: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800C6E0C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800C6E10: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800C6E14: jr          $ra
    // 0x800C6E18: addiu       $sp, $sp, 0x5F8
    ctx->r29 = ADD32(ctx->r29, 0X5F8);
    return;
    // 0x800C6E18: addiu       $sp, $sp, 0x5F8
    ctx->r29 = ADD32(ctx->r29, 0X5F8);
    // 0x800C6E1C: nop

;}
