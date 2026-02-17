#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void resolve_collisions(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031640: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80031644: sb          $t0, 0x1($sp)
    MEM_B(0X1, ctx->r29) = ctx->r8;
    // 0x80031648: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8003164C: lw          $t0, -0x2708($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2708);
    // 0x80031650: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80031654: sb          $zero, 0x0($sp)
    MEM_B(0X0, ctx->r29) = 0;
    // 0x80031658: beq         $t0, $zero, L_80031B8C
    if (ctx->r8 == 0) {
        // 0x8003165C: sw          $zero, -0x4990($at)
        MEM_W(-0X4990, ctx->r1) = 0;
            goto L_80031B8C;
    }
    // 0x8003165C: sw          $zero, -0x4990($at)
    MEM_W(-0X4990, ctx->r1) = 0;
L_80031660:
    // 0x80031660: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
L_80031664:
    // 0x80031664: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80031668: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8003166C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80031670: or          $t7, $zero, $zero
    ctx->r15 = 0 | 0;
    // 0x80031674: lw          $t5, -0x270C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X270C);
    // 0x80031678: lw          $t1, -0x2710($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2710);
    // 0x8003167C: lw          $t0, -0x2708($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2708);
L_80031680:
    // 0x80031680: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80031684: blezl       $t2, L_800316A0
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80031688: lhu         $v0, 0x0($t2)
        ctx->r2 = MEM_HU(ctx->r10, 0X0);
            goto L_800316A0;
    }
    goto skip_0;
    // 0x80031688: lhu         $v0, 0x0($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0X0);
    skip_0:
    // 0x8003168C: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x80031690: or          $t3, $t3, $t2
    ctx->r11 = ctx->r11 | ctx->r10;
    // 0x80031694: j           L_80031984
    // 0x80031698: lw          $t3, 0x18($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X18);
        goto L_80031984;
    // 0x80031698: lw          $t3, 0x18($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X18);
    // 0x8003169C: lhu         $v0, 0x0($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0X0);
L_800316A0:
    // 0x800316A0: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800316A4: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800316A8: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800316AC: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x800316B0: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800316B4: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800316B8: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800316BC: mul.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800316C0: lwc1        $f16, 0x8($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800316C4: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800316C8: mul.s       $f10, $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800316CC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800316D0: mul.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800316D4: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800316D8: add.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800316DC: add.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800316E0: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800316E4: sub.s       $f18, $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x800316E8: lwc1        $f8, 0x64F0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X64F0);
    // 0x800316EC: c.olt.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl < ctx->f8.fl;
    // 0x800316F0: bc1fl       L_80031988
    if (!c1cs) {
        // 0x800316F4: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_80031988;
    }
    goto skip_1;
    // 0x800316F4: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    skip_1:
    // 0x800316F8: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800316FC: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80031700: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80031704: mul.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80031708: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003170C: mul.s       $f10, $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80031710: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80031714: mul.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80031718: add.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8003171C: add.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80031720: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80031724: sub.s       $f16, $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x80031728: lwc1        $f8, 0x64F4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X64F4);
    // 0x8003172C: c.olt.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl < ctx->f8.fl;
    // 0x80031730: bc1tl       L_80031988
    if (c1cs) {
        // 0x80031734: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_80031988;
    }
    goto skip_2;
    // 0x80031734: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    skip_2:
    // 0x80031738: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8003173C: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80031740: sub.s       $f0, $f10, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80031744: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80031748: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8003174C: sub.s       $f2, $f10, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80031750: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80031754: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80031758: sub.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8003175C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80031760: sub.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80031764: c.ueq.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x80031768: bc1t        L_80031774
    if (c1cs) {
        // 0x8003176C: nop
    
            goto L_80031774;
    }
    // 0x8003176C: nop

    // 0x80031770: div.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f16.fl, ctx->f8.fl);
L_80031774:
    // 0x80031774: mul.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80031778: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8003177C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80031780: mul.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80031784: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80031788: mul.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8003178C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80031790: add.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80031794: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80031798: add.s       $f2, $f6, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x8003179C: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800317A0: add.s       $f4, $f6, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f4.fl;
L_800317A4:
    // 0x800317A4: lhu         $v1, 0x2($t2)
    ctx->r3 = MEM_HU(ctx->r10, 0X2);
    // 0x800317A8: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x800317AC: andi        $t9, $v1, 0x8000
    ctx->r25 = ctx->r3 & 0X8000;
    // 0x800317B0: beql        $t9, $zero, L_800317C4
    if (ctx->r25 == 0) {
        // 0x800317B4: sll         $v1, $v1, 4
        ctx->r3 = S32(ctx->r3 << 4);
            goto L_800317C4;
    }
    goto skip_3;
    // 0x800317B4: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    skip_3:
    // 0x800317B8: andi        $v1, $v1, 0x7FFF
    ctx->r3 = ctx->r3 & 0X7FFF;
    // 0x800317BC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800317C0: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
L_800317C4:
    // 0x800317C4: addu        $v1, $v1, $t3
    ctx->r3 = ADD32(ctx->r3, ctx->r11);
    // 0x800317C8: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800317CC: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800317D0: mul.s       $f6, $f0, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800317D4: nop

    // 0x800317D8: mul.s       $f8, $f2, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x800317DC: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800317E0: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800317E4: mul.s       $f8, $f4, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800317E8: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800317EC: lwc1        $f8, 0xC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XC);
    // 0x800317F0: beq         $t8, $zero, L_800317FC
    if (ctx->r24 == 0) {
        // 0x800317F4: add.s       $f6, $f6, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
            goto L_800317FC;
    }
    // 0x800317F4: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800317F8: neg.s       $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = -ctx->f6.fl;
L_800317FC:
    // 0x800317FC: c.ole.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl <= ctx->f10.fl;
    // 0x80031800: bc1fl       L_80031988
    if (!c1cs) {
        // 0x80031804: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_80031988;
    }
    goto skip_4;
    // 0x80031804: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    skip_4:
    // 0x80031808: addiu       $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
    // 0x8003180C: bne         $t4, $zero, L_800317A4
    if (ctx->r12 != 0) {
        // 0x80031810: addiu       $t2, $t2, 0x2
        ctx->r10 = ADD32(ctx->r10, 0X2);
            goto L_800317A4;
    }
    // 0x80031810: addiu       $t2, $t2, 0x2
    ctx->r10 = ADD32(ctx->r10, 0X2);
    // 0x80031814: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80031818: lwc1        $f0, 0x64F8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X64F8);
    // 0x8003181C: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80031820: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80031824: c.ult.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80031828: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8003182C: bc1t        L_80031888
    if (c1cs) {
        // 0x80031830: nop
    
            goto L_80031888;
    }
    // 0x80031830: nop

    // 0x80031834: lb          $v1, 0x0($t5)
    ctx->r3 = MEM_B(ctx->r13, 0X0);
    // 0x80031838: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8003183C: beq         $v1, $at, L_80031888
    if (ctx->r3 == ctx->r1) {
        // 0x80031840: nop
    
            goto L_80031888;
    }
    // 0x80031840: nop

    // 0x80031844: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80031848: lw          $v1, -0x498C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X498C);
    // 0x8003184C: bne         $v1, $zero, L_80031888
    if (ctx->r3 != 0) {
        // 0x80031850: nop
    
            goto L_80031888;
    }
    // 0x80031850: nop

    // 0x80031854: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80031858: mul.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8003185C: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80031860: mul.s       $f4, $f6, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80031864: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80031868: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8003186C: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80031870: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80031874: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80031878: sub.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x8003187C: div.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80031880: j           L_80031908
    // 0x80031884: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
        goto L_80031908;
    // 0x80031884: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
L_80031888:
    // 0x80031888: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003188C: lwc1        $f10, 0x64FC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X64FC);
    // 0x80031890: c.olt.s     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x80031894: bc1f        L_800318E0
    if (!c1cs) {
        // 0x80031898: nop
    
            goto L_800318E0;
    }
    // 0x80031898: nop

    // 0x8003189C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800318A0: lw          $v1, -0x498C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X498C);
    // 0x800318A4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800318A8: beq         $v1, $at, L_800318E0
    if (ctx->r3 == ctx->r1) {
        // 0x800318AC: nop
    
            goto L_800318E0;
    }
    // 0x800318AC: nop

    // 0x800318B0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800318B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800318B8: sw          $v1, -0x4990($at)
    MEM_W(-0X4990, ctx->r1) = ctx->r3;
    // 0x800318BC: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800318C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800318C4: swc1        $f6, -0x499C($at)
    MEM_W(-0X499C, ctx->r1) = ctx->f6.u32l;
    // 0x800318C8: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800318CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800318D0: swc1        $f6, -0x4998($at)
    MEM_W(-0X4998, ctx->r1) = ctx->f6.u32l;
    // 0x800318D4: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800318D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800318DC: swc1        $f6, -0x4994($at)
    MEM_W(-0X4994, ctx->r1) = ctx->f6.u32l;
L_800318E0:
    // 0x800318E0: mul.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800318E4: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800318E8: mul.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x800318EC: nop

    // 0x800318F0: mul.s       $f4, $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800318F4: sub.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800318F8: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800318FC: sub.s       $f2, $f6, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x80031900: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80031904: sub.s       $f4, $f6, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f4.fl;
L_80031908:
    // 0x80031908: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8003190C: lw          $v1, -0x4990($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4990);
    // 0x80031910: bnel        $v1, $zero, L_80031940
    if (ctx->r3 != 0) {
        // 0x80031914: lb          $t4, 0x0($t5)
        ctx->r12 = MEM_B(ctx->r13, 0X0);
            goto L_80031940;
    }
    goto skip_5;
    // 0x80031914: lb          $t4, 0x0($t5)
    ctx->r12 = MEM_B(ctx->r13, 0X0);
    skip_5:
    // 0x80031918: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8003191C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80031920: swc1        $f6, -0x499C($at)
    MEM_W(-0X499C, ctx->r1) = ctx->f6.u32l;
    // 0x80031924: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80031928: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8003192C: swc1        $f6, -0x4998($at)
    MEM_W(-0X4998, ctx->r1) = ctx->f6.u32l;
    // 0x80031930: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80031934: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80031938: swc1        $f6, -0x4994($at)
    MEM_W(-0X4994, ctx->r1) = ctx->f6.u32l;
    // 0x8003193C: lb          $t4, 0x0($t5)
    ctx->r12 = MEM_B(ctx->r13, 0X0);
L_80031940:
    // 0x80031940: lb          $v0, 0x0($a3)
    ctx->r2 = MEM_B(ctx->r7, 0X0);
    // 0x80031944: slt         $at, $v0, $t4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80031948: beql        $at, $zero, L_80031958
    if (ctx->r1 == 0) {
        // 0x8003194C: addiu       $t6, $t6, 0x1
        ctx->r14 = ADD32(ctx->r14, 0X1);
            goto L_80031958;
    }
    goto skip_6;
    // 0x8003194C: addiu       $t6, $t6, 0x1
    ctx->r14 = ADD32(ctx->r14, 0X1);
    skip_6:
    // 0x80031950: sb          $t4, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r12;
    // 0x80031954: addiu       $t6, $t6, 0x1
    ctx->r14 = ADD32(ctx->r14, 0X1);
L_80031958:
    // 0x80031958: slti        $at, $t6, 0xB
    ctx->r1 = SIGNED(ctx->r14) < 0XB ? 1 : 0;
    // 0x8003195C: bne         $at, $zero, L_80031974
    if (ctx->r1 != 0) {
        // 0x80031960: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80031974;
    }
    // 0x80031960: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80031964: or          $t7, $zero, $zero
    ctx->r15 = 0 | 0;
    // 0x80031968: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8003196C: lwc1        $f2, 0x4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80031970: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
L_80031974:
    // 0x80031974: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x80031978: swc1        $f2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f2.u32l;
    // 0x8003197C: j           L_80031994
    // 0x80031980: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
        goto L_80031994;
    // 0x80031980: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
L_80031984:
    // 0x80031984: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_80031988:
    // 0x80031988: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x8003198C: bne         $t0, $zero, L_80031680
    if (ctx->r8 != 0) {
        // 0x80031990: addiu       $t1, $t1, 0x4
        ctx->r9 = ADD32(ctx->r9, 0X4);
            goto L_80031680;
    }
    // 0x80031990: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
L_80031994:
    // 0x80031994: bne         $t7, $zero, L_80031664
    if (ctx->r15 != 0) {
        // 0x80031998: nop
    
            goto L_80031664;
    }
    // 0x80031998: nop

    // 0x8003199C: beq         $t6, $zero, L_800319C0
    if (ctx->r14 == 0) {
        // 0x800319A0: lbu         $t2, 0x1($sp)
        ctx->r10 = MEM_BU(ctx->r29, 0X1);
            goto L_800319C0;
    }
    // 0x800319A0: lbu         $t2, 0x1($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X1);
    // 0x800319A4: lw          $t1, 0x14($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14);
    // 0x800319A8: lw          $t0, 0x0($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X0);
    // 0x800319AC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800319B0: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800319B4: lbu         $t0, 0x0($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X0);
    // 0x800319B8: or          $t0, $t0, $t2
    ctx->r8 = ctx->r8 | ctx->r10;
    // 0x800319BC: sb          $t0, 0x0($sp)
    MEM_B(0X0, ctx->r29) = ctx->r8;
L_800319C0:
    // 0x800319C0: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x800319C4: sb          $t2, 0x1($sp)
    MEM_B(0X1, ctx->r29) = ctx->r10;
    // 0x800319C8: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
L_800319CC:
    // 0x800319CC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800319D0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800319D4: or          $t7, $zero, $zero
    ctx->r15 = 0 | 0;
    // 0x800319D8: lw          $t1, -0x2710($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2710);
    // 0x800319DC: lw          $t0, -0x2708($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2708);
L_800319E0:
    // 0x800319E0: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800319E4: blezl       $t2, L_80031A00
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800319E8: lhu         $v0, 0x0($t2)
        ctx->r2 = MEM_HU(ctx->r10, 0X0);
            goto L_80031A00;
    }
    goto skip_7;
    // 0x800319E8: lhu         $v0, 0x0($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0X0);
    skip_7:
    // 0x800319EC: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x800319F0: or          $t3, $t3, $t2
    ctx->r11 = ctx->r11 | ctx->r10;
    // 0x800319F4: j           L_80031B58
    // 0x800319F8: lw          $t3, 0x18($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X18);
        goto L_80031B58;
    // 0x800319F8: lw          $t3, 0x18($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X18);
    // 0x800319FC: lhu         $v0, 0x0($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0X0);
L_80031A00:
    // 0x80031A00: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80031A04: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80031A08: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80031A0C: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x80031A10: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80031A14: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80031A18: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80031A1C: mul.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80031A20: lwc1        $f16, 0x8($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80031A24: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80031A28: mul.s       $f10, $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80031A2C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80031A30: mul.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80031A34: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80031A38: add.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80031A3C: add.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80031A40: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80031A44: sub.s       $f18, $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x80031A48: lwc1        $f8, 0x6500($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6500);
    // 0x80031A4C: c.olt.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl < ctx->f8.fl;
    // 0x80031A50: bc1f        L_80031B58
    if (!c1cs) {
        // 0x80031A54: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_80031B58;
    }
    // 0x80031A54: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80031A58: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80031A5C: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80031A60: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80031A64: neg.s       $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = -ctx->f8.fl;
    // 0x80031A68: c.ole.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl <= ctx->f8.fl;
    // 0x80031A6C: bc1t        L_80031B58
    if (c1cs) {
        // 0x80031A70: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_80031B58;
    }
    // 0x80031A70: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80031A74: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80031A78: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80031A7C: lwc1        $f2, 0x4($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80031A80: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80031A84: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
L_80031A88:
    // 0x80031A88: lhu         $v1, 0x2($t2)
    ctx->r3 = MEM_HU(ctx->r10, 0X2);
    // 0x80031A8C: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x80031A90: andi        $t9, $v1, 0x8000
    ctx->r25 = ctx->r3 & 0X8000;
    // 0x80031A94: beql        $t9, $zero, L_80031AA8
    if (ctx->r25 == 0) {
        // 0x80031A98: sll         $v1, $v1, 4
        ctx->r3 = S32(ctx->r3 << 4);
            goto L_80031AA8;
    }
    goto skip_8;
    // 0x80031A98: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    skip_8:
    // 0x80031A9C: andi        $v1, $v1, 0x7FFF
    ctx->r3 = ctx->r3 & 0X7FFF;
    // 0x80031AA0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80031AA4: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
L_80031AA8:
    // 0x80031AA8: addu        $v1, $v1, $t3
    ctx->r3 = ADD32(ctx->r3, ctx->r11);
    // 0x80031AAC: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80031AB0: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80031AB4: mul.s       $f6, $f0, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80031AB8: nop

    // 0x80031ABC: mul.s       $f8, $f2, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80031AC0: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80031AC4: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80031AC8: mul.s       $f8, $f4, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80031ACC: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80031AD0: lwc1        $f8, 0xC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80031AD4: beq         $t8, $zero, L_80031AE0
    if (ctx->r24 == 0) {
        // 0x80031AD8: add.s       $f6, $f6, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
            goto L_80031AE0;
    }
    // 0x80031AD8: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80031ADC: neg.s       $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = -ctx->f6.fl;
L_80031AE0:
    // 0x80031AE0: c.ole.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl <= ctx->f10.fl;
    // 0x80031AE4: bc1fl       L_80031B5C
    if (!c1cs) {
        // 0x80031AE8: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_80031B5C;
    }
    goto skip_9;
    // 0x80031AE8: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    skip_9:
    // 0x80031AEC: addiu       $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
    // 0x80031AF0: bne         $t4, $zero, L_80031A88
    if (ctx->r12 != 0) {
        // 0x80031AF4: addiu       $t2, $t2, 0x2
        ctx->r10 = ADD32(ctx->r10, 0X2);
            goto L_80031A88;
    }
    // 0x80031AF4: addiu       $t2, $t2, 0x2
    ctx->r10 = ADD32(ctx->r10, 0X2);
    // 0x80031AF8: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80031AFC: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80031B00: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80031B04: mul.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80031B08: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80031B0C: addiu       $t6, $t6, 0x1
    ctx->r14 = ADD32(ctx->r14, 0X1);
    // 0x80031B10: mul.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x80031B14: slti        $at, $t6, 0xB
    ctx->r1 = SIGNED(ctx->r14) < 0XB ? 1 : 0;
    // 0x80031B18: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80031B1C: mul.s       $f4, $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80031B20: sub.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80031B24: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80031B28: sub.s       $f2, $f6, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x80031B2C: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80031B30: bne         $at, $zero, L_80031B48
    if (ctx->r1 != 0) {
        // 0x80031B34: sub.s       $f4, $f6, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f4.fl;
            goto L_80031B48;
    }
    // 0x80031B34: sub.s       $f4, $f6, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80031B38: or          $t7, $zero, $zero
    ctx->r15 = 0 | 0;
    // 0x80031B3C: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80031B40: lwc1        $f2, 0x4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80031B44: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
L_80031B48:
    // 0x80031B48: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x80031B4C: swc1        $f2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f2.u32l;
    // 0x80031B50: j           L_80031B64
    // 0x80031B54: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
        goto L_80031B64;
    // 0x80031B54: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
L_80031B58:
    // 0x80031B58: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_80031B5C:
    // 0x80031B5C: bne         $t0, $zero, L_800319E0
    if (ctx->r8 != 0) {
        // 0x80031B60: addiu       $t1, $t1, 0x4
        ctx->r9 = ADD32(ctx->r9, 0X4);
            goto L_800319E0;
    }
    // 0x80031B60: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
L_80031B64:
    // 0x80031B64: bne         $t7, $zero, L_800319CC
    if (ctx->r15 != 0) {
        // 0x80031B68: nop
    
            goto L_800319CC;
    }
    // 0x80031B68: nop

    // 0x80031B6C: lw          $t0, 0x10($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X10);
    // 0x80031B70: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    // 0x80031B74: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    // 0x80031B78: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x80031B7C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80031B80: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80031B84: bne         $t0, $zero, L_80031660
    if (ctx->r8 != 0) {
        // 0x80031B88: sw          $t0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r8;
            goto L_80031660;
    }
    // 0x80031B88: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
L_80031B8C:
    // 0x80031B8C: jr          $ra
    // 0x80031B90: lb          $v0, 0x0($sp)
    ctx->r2 = MEM_B(ctx->r29, 0X0);
    return;
    // 0x80031B90: lb          $v0, 0x0($sp)
    ctx->r2 = MEM_B(ctx->r29, 0X0);
    // 0x80031B94: nop

    // 0x80031B98: nop

    // 0x80031B9C: nop

;}
RECOMP_FUNC void lights_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031BA0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80031BA4: lw          $a0, -0x3140($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3140);
    // 0x80031BA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80031BAC: beq         $a0, $zero, L_80031BDC
    if (ctx->r4 == 0) {
        // 0x80031BB0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80031BDC;
    }
    // 0x80031BB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80031BB4: jal         0x80071380
    // 0x80031BB8: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x80031BB8: nop

    after_0:
    // 0x80031BBC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80031BC0: sw          $zero, -0x3140($at)
    MEM_W(-0X3140, ctx->r1) = 0;
    // 0x80031BC4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80031BC8: sw          $zero, -0x313C($at)
    MEM_W(-0X313C, ctx->r1) = 0;
    // 0x80031BCC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80031BD0: sw          $zero, -0x3130($at)
    MEM_W(-0X3130, ctx->r1) = 0;
    // 0x80031BD4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80031BD8: sw          $zero, -0x312C($at)
    MEM_W(-0X312C, ctx->r1) = 0;
L_80031BDC:
    // 0x80031BDC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80031BE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80031BE4: sw          $zero, -0x3134($at)
    MEM_W(-0X3134, ctx->r1) = 0;
    // 0x80031BE8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80031BEC: sw          $zero, -0x3138($at)
    MEM_W(-0X3138, ctx->r1) = 0;
    // 0x80031BF0: jr          $ra
    // 0x80031BF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80031BF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lights_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031BF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80031BFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80031C00: jal         0x80031BA0
    // 0x80031C04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    lights_free(rdram, ctx);
        goto after_0;
    // 0x80031C04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80031C08: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80031C0C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80031C10: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80031C14: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80031C18: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80031C1C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80031C20: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80031C24: addiu       $a2, $a2, -0x3138
    ctx->r6 = ADD32(ctx->r6, -0X3138);
    // 0x80031C28: lui         $a1, 0xFF00
    ctx->r5 = S32(0XFF00 << 16);
    // 0x80031C2C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80031C30: sll         $a0, $t7, 2
    ctx->r4 = S32(ctx->r15 << 2);
    // 0x80031C34: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x80031C38: jal         0x80070EDC
    // 0x80031C3C: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x80031C3C: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    after_1:
    // 0x80031C40: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80031C44: addiu       $a2, $a2, -0x3138
    ctx->r6 = ADD32(ctx->r6, -0X3138);
    // 0x80031C48: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x80031C4C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80031C50: sll         $t3, $t0, 4
    ctx->r11 = S32(ctx->r8 << 4);
    // 0x80031C54: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x80031C58: addu        $t3, $t3, $t0
    ctx->r11 = ADD32(ctx->r11, ctx->r8);
    // 0x80031C5C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80031C60: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80031C64: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x80031C68: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80031C6C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80031C70: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x80031C74: addu        $t6, $t6, $t0
    ctx->r14 = ADD32(ctx->r14, ctx->r8);
    // 0x80031C78: addiu       $t1, $t1, -0x3130
    ctx->r9 = ADD32(ctx->r9, -0X3130);
    // 0x80031C7C: addiu       $a3, $a3, -0x3140
    ctx->r7 = ADD32(ctx->r7, -0X3140);
    // 0x80031C80: addiu       $a1, $a1, -0x313C
    ctx->r5 = ADD32(ctx->r5, -0X313C);
    // 0x80031C84: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80031C88: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x80031C8C: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80031C90: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x80031C94: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80031C98: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80031C9C: sw          $t7, -0x312C($at)
    MEM_W(-0X312C, ctx->r1) = ctx->r15;
    // 0x80031CA0: blez        $t0, L_80031CDC
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80031CA4: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80031CDC;
    }
    // 0x80031CA4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80031CA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80031CAC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80031CB0:
    // 0x80031CB0: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80031CB4: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x80031CB8: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x80031CBC: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x80031CC0: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80031CC4: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x80031CC8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80031CCC: slt         $at, $v1, $t4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80031CD0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80031CD4: bne         $at, $zero, L_80031CB0
    if (ctx->r1 != 0) {
        // 0x80031CD8: addiu       $a0, $a0, 0x88
        ctx->r4 = ADD32(ctx->r4, 0X88);
            goto L_80031CB0;
    }
    // 0x80031CD8: addiu       $a0, $a0, 0x88
    ctx->r4 = ADD32(ctx->r4, 0X88);
L_80031CDC:
    // 0x80031CDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80031CE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80031CE4: jr          $ra
    // 0x80031CE8: nop

    return;
    // 0x80031CE8: nop

;}
RECOMP_FUNC void light_add_from_level_object_entry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031CEC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80031CF0: addiu       $v1, $v1, -0x3134
    ctx->r3 = ADD32(ctx->r3, -0X3134);
    // 0x80031CF4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80031CF8: lw          $t6, -0x3138($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3138);
    // 0x80031CFC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80031D00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80031D04: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80031D08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80031D0C: beq         $at, $zero, L_80031FB8
    if (ctx->r1 == 0) {
        // 0x80031D10: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80031FB8;
    }
    // 0x80031D10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80031D14: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80031D18: lw          $t7, -0x3140($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X3140);
    // 0x80031D1C: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80031D20: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80031D24: lw          $a2, 0x0($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X0);
    // 0x80031D28: addiu       $t1, $v0, 0x1
    ctx->r9 = ADD32(ctx->r2, 0X1);
    // 0x80031D2C: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80031D30: lbu         $t2, 0x8($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X8);
    // 0x80031D34: nop

    // 0x80031D38: andi        $t3, $t2, 0xF0
    ctx->r11 = ctx->r10 & 0XF0;
    // 0x80031D3C: sra         $t4, $t3, 4
    ctx->r12 = S32(SIGNED(ctx->r11) >> 4);
    // 0x80031D40: sb          $t4, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r12;
    // 0x80031D44: lbu         $t5, 0x8($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X8);
    // 0x80031D48: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80031D4C: andi        $t6, $t5, 0xF
    ctx->r14 = ctx->r13 & 0XF;
    // 0x80031D50: sb          $t6, 0x3($a2)
    MEM_B(0X3, ctx->r6) = ctx->r14;
    // 0x80031D54: lbu         $t7, 0x9($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X9);
    // 0x80031D58: nop

    // 0x80031D5C: andi        $t8, $t7, 0xE0
    ctx->r24 = ctx->r15 & 0XE0;
    // 0x80031D60: sra         $t9, $t8, 5
    ctx->r25 = S32(SIGNED(ctx->r24) >> 5);
    // 0x80031D64: sb          $t9, 0x1($a2)
    MEM_B(0X1, ctx->r6) = ctx->r25;
    // 0x80031D68: lbu         $t1, 0x9($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X9);
    // 0x80031D6C: sb          $t3, 0x4($a2)
    MEM_B(0X4, ctx->r6) = ctx->r11;
    // 0x80031D70: andi        $t2, $t1, 0x1F
    ctx->r10 = ctx->r9 & 0X1F;
    // 0x80031D74: sb          $t2, 0x2($a2)
    MEM_B(0X2, ctx->r6) = ctx->r10;
    // 0x80031D78: sw          $zero, 0xC($a2)
    MEM_W(0XC, ctx->r6) = 0;
    // 0x80031D7C: sh          $zero, 0x6($a2)
    MEM_H(0X6, ctx->r6) = 0;
    // 0x80031D80: sh          $zero, 0x8($a2)
    MEM_H(0X8, ctx->r6) = 0;
    // 0x80031D84: beq         $a0, $zero, L_80031DB0
    if (ctx->r4 == 0) {
        // 0x80031D88: sh          $zero, 0xA($a2)
        MEM_H(0XA, ctx->r6) = 0;
            goto L_80031DB0;
    }
    // 0x80031D88: sh          $zero, 0xA($a2)
    MEM_H(0XA, ctx->r6) = 0;
    // 0x80031D8C: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80031D90: nop

    // 0x80031D94: swc1        $f4, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f4.u32l;
    // 0x80031D98: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80031D9C: nop

    // 0x80031DA0: swc1        $f6, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f6.u32l;
    // 0x80031DA4: lwc1        $f8, 0x14($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80031DA8: b           L_80031DF8
    // 0x80031DAC: swc1        $f8, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f8.u32l;
        goto L_80031DF8;
    // 0x80031DAC: swc1        $f8, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f8.u32l;
L_80031DB0:
    // 0x80031DB0: lh          $t4, 0x2($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X2);
    // 0x80031DB4: nop

    // 0x80031DB8: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x80031DBC: nop

    // 0x80031DC0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80031DC4: swc1        $f16, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f16.u32l;
    // 0x80031DC8: lh          $t5, 0x4($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X4);
    // 0x80031DCC: nop

    // 0x80031DD0: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x80031DD4: nop

    // 0x80031DD8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80031DDC: swc1        $f4, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f4.u32l;
    // 0x80031DE0: lh          $t6, 0x6($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X6);
    // 0x80031DE4: nop

    // 0x80031DE8: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80031DEC: nop

    // 0x80031DF0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80031DF4: swc1        $f8, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f8.u32l;
L_80031DF8:
    // 0x80031DF8: lbu         $t7, 0xA($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0XA);
    // 0x80031DFC: sw          $zero, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = 0;
    // 0x80031E00: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x80031E04: sw          $t8, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r24;
    // 0x80031E08: sh          $zero, 0x3C($a2)
    MEM_H(0X3C, ctx->r6) = 0;
    // 0x80031E0C: lbu         $t9, 0xB($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0XB);
    // 0x80031E10: sw          $zero, 0x30($a2)
    MEM_W(0X30, ctx->r6) = 0;
    // 0x80031E14: sll         $t1, $t9, 16
    ctx->r9 = S32(ctx->r25 << 16);
    // 0x80031E18: sw          $t1, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->r9;
    // 0x80031E1C: sh          $zero, 0x3E($a2)
    MEM_H(0X3E, ctx->r6) = 0;
    // 0x80031E20: lbu         $t2, 0xC($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0XC);
    // 0x80031E24: sw          $zero, 0x34($a2)
    MEM_W(0X34, ctx->r6) = 0;
    // 0x80031E28: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x80031E2C: sw          $t3, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r11;
    // 0x80031E30: sh          $zero, 0x40($a2)
    MEM_H(0X40, ctx->r6) = 0;
    // 0x80031E34: lbu         $t4, 0xD($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0XD);
    // 0x80031E38: sw          $zero, 0x38($a2)
    MEM_W(0X38, ctx->r6) = 0;
    // 0x80031E3C: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x80031E40: sw          $t5, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->r13;
    // 0x80031E44: sh          $zero, 0x42($a2)
    MEM_H(0X42, ctx->r6) = 0;
    // 0x80031E48: sw          $zero, 0x44($a2)
    MEM_W(0X44, ctx->r6) = 0;
    // 0x80031E4C: lbu         $t6, 0x1C($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X1C);
    // 0x80031E50: nop

    // 0x80031E54: slti        $at, $t6, 0x7
    ctx->r1 = SIGNED(ctx->r14) < 0X7 ? 1 : 0;
    // 0x80031E58: beq         $at, $zero, L_80031EDC
    if (ctx->r1 == 0) {
        // 0x80031E5C: nop
    
            goto L_80031EDC;
    }
    // 0x80031E5C: nop

    // 0x80031E60: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80031E64: jal         0x8006BFF0
    // 0x80031E68: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    level_header(rdram, ctx);
        goto after_0;
    // 0x80031E68: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80031E6C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80031E70: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80031E74: lbu         $t7, 0x1C($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X1C);
    // 0x80031E78: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80031E7C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80031E80: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80031E84: lw          $t0, 0x74($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X74);
    // 0x80031E88: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80031E8C: beq         $t0, $at, L_80031EDC
    if (ctx->r8 == ctx->r1) {
        // 0x80031E90: addiu       $t2, $t0, 0x14
        ctx->r10 = ADD32(ctx->r8, 0X14);
            goto L_80031EDC;
    }
    // 0x80031E90: addiu       $t2, $t0, 0x14
    ctx->r10 = ADD32(ctx->r8, 0X14);
    // 0x80031E94: sw          $t0, 0x44($a2)
    MEM_W(0X44, ctx->r6) = ctx->r8;
    // 0x80031E98: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80031E9C: sh          $zero, 0x4A($a2)
    MEM_H(0X4A, ctx->r6) = 0;
    // 0x80031EA0: andi        $a0, $t1, 0xFFFF
    ctx->r4 = ctx->r9 & 0XFFFF;
    // 0x80031EA4: sh          $zero, 0x4C($a2)
    MEM_H(0X4C, ctx->r6) = 0;
    // 0x80031EA8: sh          $zero, 0x4E($a2)
    MEM_H(0X4E, ctx->r6) = 0;
    // 0x80031EAC: sw          $t2, 0x44($a2)
    MEM_W(0X44, ctx->r6) = ctx->r10;
    // 0x80031EB0: blez        $a0, L_80031EDC
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80031EB4: sh          $t1, 0x48($a2)
        MEM_H(0X48, ctx->r6) = ctx->r9;
            goto L_80031EDC;
    }
    // 0x80031EB4: sh          $t1, 0x48($a2)
    MEM_H(0X48, ctx->r6) = ctx->r9;
    // 0x80031EB8: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_80031EBC:
    // 0x80031EBC: lhu         $t3, 0x4E($a2)
    ctx->r11 = MEM_HU(ctx->r6, 0X4E);
    // 0x80031EC0: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x80031EC4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80031EC8: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80031ECC: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80031ED0: sh          $t5, 0x4E($a2)
    MEM_H(0X4E, ctx->r6) = ctx->r13;
    // 0x80031ED4: bne         $at, $zero, L_80031EBC
    if (ctx->r1 != 0) {
        // 0x80031ED8: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_80031EBC;
    }
    // 0x80031ED8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_80031EDC:
    // 0x80031EDC: lh          $t6, 0xE($a1)
    ctx->r14 = MEM_H(ctx->r5, 0XE);
    // 0x80031EE0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80031EE4: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80031EE8: ori         $t3, $zero, 0xFFFF
    ctx->r11 = 0 | 0XFFFF;
    // 0x80031EEC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80031EF0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80031EF4: swc1        $f16, 0x5C($a2)
    MEM_W(0X5C, ctx->r6) = ctx->f16.u32l;
    // 0x80031EF8: lh          $t7, 0x10($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X10);
    // 0x80031EFC: lwc1        $f0, 0x5C($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X5C);
    // 0x80031F00: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80031F04: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80031F08: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80031F0C: ori         $t7, $zero, 0xFFFF
    ctx->r15 = 0 | 0XFFFF;
    // 0x80031F10: div.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80031F14: swc1        $f4, 0x60($a2)
    MEM_W(0X60, ctx->r6) = ctx->f4.u32l;
    // 0x80031F18: lh          $t8, 0x12($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X12);
    // 0x80031F1C: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80031F20: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80031F24: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80031F28: swc1        $f10, 0x68($a2)
    MEM_W(0X68, ctx->r6) = ctx->f10.u32l;
    // 0x80031F2C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80031F30: swc1        $f18, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f18.u32l;
    // 0x80031F34: swc1        $f8, 0x64($a2)
    MEM_W(0X64, ctx->r6) = ctx->f8.u32l;
    // 0x80031F38: lh          $t9, 0x14($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X14);
    // 0x80031F3C: nop

    // 0x80031F40: sh          $t9, 0x70($a2)
    MEM_H(0X70, ctx->r6) = ctx->r25;
    // 0x80031F44: lh          $t1, 0x18($a1)
    ctx->r9 = MEM_H(ctx->r5, 0X18);
    // 0x80031F48: nop

    // 0x80031F4C: sh          $t1, 0x74($a2)
    MEM_H(0X74, ctx->r6) = ctx->r9;
    // 0x80031F50: lh          $t2, 0x18($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X18);
    // 0x80031F54: nop

    // 0x80031F58: beq         $t2, $zero, L_80031F68
    if (ctx->r10 == 0) {
        // 0x80031F5C: nop
    
            goto L_80031F68;
    }
    // 0x80031F5C: nop

    // 0x80031F60: b           L_80031F6C
    // 0x80031F64: sh          $t3, 0x78($a2)
    MEM_H(0X78, ctx->r6) = ctx->r11;
        goto L_80031F6C;
    // 0x80031F64: sh          $t3, 0x78($a2)
    MEM_H(0X78, ctx->r6) = ctx->r11;
L_80031F68:
    // 0x80031F68: sh          $zero, 0x78($a2)
    MEM_H(0X78, ctx->r6) = 0;
L_80031F6C:
    // 0x80031F6C: lh          $t4, 0x16($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X16);
    // 0x80031F70: nop

    // 0x80031F74: sh          $t4, 0x72($a2)
    MEM_H(0X72, ctx->r6) = ctx->r12;
    // 0x80031F78: lh          $t5, 0x1A($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X1A);
    // 0x80031F7C: nop

    // 0x80031F80: sh          $t5, 0x76($a2)
    MEM_H(0X76, ctx->r6) = ctx->r13;
    // 0x80031F84: lh          $t6, 0x1A($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X1A);
    // 0x80031F88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80031F8C: beq         $t6, $zero, L_80031FA0
    if (ctx->r14 == 0) {
        // 0x80031F90: nop
    
            goto L_80031FA0;
    }
    // 0x80031F90: nop

    // 0x80031F94: sh          $t7, 0x7A($a2)
    MEM_H(0X7A, ctx->r6) = ctx->r15;
    // 0x80031F98: b           L_80031FA4
    // 0x80031F9C: sh          $zero, 0x7A($a2)
    MEM_H(0X7A, ctx->r6) = 0;
        goto L_80031FA4;
    // 0x80031F9C: sh          $zero, 0x7A($a2)
    MEM_H(0X7A, ctx->r6) = 0;
L_80031FA0:
    // 0x80031FA0: sh          $zero, 0x7A($a2)
    MEM_H(0X7A, ctx->r6) = 0;
L_80031FA4:
    // 0x80031FA4: sb          $t8, 0x5($a2)
    MEM_B(0X5, ctx->r6) = ctx->r24;
    // 0x80031FA8: jal         0x80032464
    // 0x80031FAC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    light_update(rdram, ctx);
        goto after_1;
    // 0x80031FAC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x80031FB0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80031FB4: nop

L_80031FB8:
    // 0x80031FB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80031FBC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80031FC0: jr          $ra
    // 0x80031FC4: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    return;
    // 0x80031FC4: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
;}
RECOMP_FUNC void light_add_from_object_header(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031FC8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80031FCC: addiu       $v1, $v1, -0x3134
    ctx->r3 = ADD32(ctx->r3, -0X3134);
    // 0x80031FD0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80031FD4: lw          $t6, -0x3138($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3138);
    // 0x80031FD8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80031FDC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80031FE0: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80031FE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80031FE8: beq         $at, $zero, L_80032240
    if (ctx->r1 == 0) {
        // 0x80031FEC: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80032240;
    }
    // 0x80031FEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80031FF0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80031FF4: lw          $t7, -0x3140($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X3140);
    // 0x80031FF8: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80031FFC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80032000: lw          $a2, 0x0($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X0);
    // 0x80032004: addiu       $t0, $v0, 0x1
    ctx->r8 = ADD32(ctx->r2, 0X1);
    // 0x80032008: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8003200C: lw          $t1, 0x8($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X8);
    // 0x80032010: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80032014: srl         $t2, $t1, 28
    ctx->r10 = S32(U32(ctx->r9) >> 28);
    // 0x80032018: sb          $t2, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r10;
    // 0x8003201C: lbu         $t3, 0x9($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X9);
    // 0x80032020: nop

    // 0x80032024: sb          $t3, 0x1($a2)
    MEM_B(0X1, ctx->r6) = ctx->r11;
    // 0x80032028: lbu         $t4, 0xB($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0XB);
    // 0x8003202C: nop

    // 0x80032030: sb          $t4, 0x2($a2)
    MEM_B(0X2, ctx->r6) = ctx->r12;
    // 0x80032034: lbu         $t5, 0xA($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0XA);
    // 0x80032038: nop

    // 0x8003203C: sb          $t5, 0x3($a2)
    MEM_B(0X3, ctx->r6) = ctx->r13;
    // 0x80032040: lbu         $t6, 0x8($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X8);
    // 0x80032044: sw          $a0, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r4;
    // 0x80032048: andi        $t7, $t6, 0xF
    ctx->r15 = ctx->r14 & 0XF;
    // 0x8003204C: sb          $t7, 0x4($a2)
    MEM_B(0X4, ctx->r6) = ctx->r15;
    // 0x80032050: lh          $t8, 0xC($a1)
    ctx->r24 = MEM_H(ctx->r5, 0XC);
    // 0x80032054: nop

    // 0x80032058: sh          $t8, 0x6($a2)
    MEM_H(0X6, ctx->r6) = ctx->r24;
    // 0x8003205C: lh          $t9, 0xE($a1)
    ctx->r25 = MEM_H(ctx->r5, 0XE);
    // 0x80032060: lh          $t1, 0x6($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X6);
    // 0x80032064: sh          $t9, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r25;
    // 0x80032068: lh          $t0, 0x10($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X10);
    // 0x8003206C: lh          $t2, 0x8($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X8);
    // 0x80032070: sh          $t0, 0xA($a2)
    MEM_H(0XA, ctx->r6) = ctx->r8;
    // 0x80032074: lh          $t3, 0xA($a2)
    ctx->r11 = MEM_H(ctx->r6, 0XA);
    // 0x80032078: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x8003207C: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x80032080: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x80032084: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80032088: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8003208C: swc1        $f6, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f6.u32l;
    // 0x80032090: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80032094: swc1        $f10, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f10.u32l;
    // 0x80032098: swc1        $f18, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f18.u32l;
    // 0x8003209C: lbu         $t4, 0x2($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X2);
    // 0x800320A0: sw          $zero, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = 0;
    // 0x800320A4: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x800320A8: sw          $t5, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r13;
    // 0x800320AC: sh          $zero, 0x3C($a2)
    MEM_H(0X3C, ctx->r6) = 0;
    // 0x800320B0: lbu         $t6, 0x3($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X3);
    // 0x800320B4: sw          $zero, 0x30($a2)
    MEM_W(0X30, ctx->r6) = 0;
    // 0x800320B8: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x800320BC: sw          $t7, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->r15;
    // 0x800320C0: sh          $zero, 0x3E($a2)
    MEM_H(0X3E, ctx->r6) = 0;
    // 0x800320C4: lbu         $t8, 0x4($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X4);
    // 0x800320C8: sw          $zero, 0x34($a2)
    MEM_W(0X34, ctx->r6) = 0;
    // 0x800320CC: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800320D0: sw          $t9, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r25;
    // 0x800320D4: sh          $zero, 0x40($a2)
    MEM_H(0X40, ctx->r6) = 0;
    // 0x800320D8: lbu         $t0, 0x5($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X5);
    // 0x800320DC: sw          $zero, 0x38($a2)
    MEM_W(0X38, ctx->r6) = 0;
    // 0x800320E0: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x800320E4: sw          $t1, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->r9;
    // 0x800320E8: sh          $zero, 0x42($a2)
    MEM_H(0X42, ctx->r6) = 0;
    // 0x800320EC: lhu         $a0, 0x6($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X6);
    // 0x800320F0: nop

    // 0x800320F4: beq         $a0, $at, L_80032168
    if (ctx->r4 == ctx->r1) {
        // 0x800320F8: nop
    
            goto L_80032168;
    }
    // 0x800320F8: nop

    // 0x800320FC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80032100: jal         0x8001E2D0
    // 0x80032104: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x80032104: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80032108: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8003210C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80032110: sw          $v0, 0x44($a2)
    MEM_W(0X44, ctx->r6) = ctx->r2;
    // 0x80032114: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80032118: addiu       $t3, $v0, 0x14
    ctx->r11 = ADD32(ctx->r2, 0X14);
    // 0x8003211C: andi        $a0, $t2, 0xFFFF
    ctx->r4 = ctx->r10 & 0XFFFF;
    // 0x80032120: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80032124: sh          $zero, 0x4A($a2)
    MEM_H(0X4A, ctx->r6) = 0;
    // 0x80032128: sh          $zero, 0x4C($a2)
    MEM_H(0X4C, ctx->r6) = 0;
    // 0x8003212C: sh          $zero, 0x4E($a2)
    MEM_H(0X4E, ctx->r6) = 0;
    // 0x80032130: sw          $t3, 0x44($a2)
    MEM_W(0X44, ctx->r6) = ctx->r11;
    // 0x80032134: blez        $a0, L_8003216C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80032138: sh          $t2, 0x48($a2)
        MEM_H(0X48, ctx->r6) = ctx->r10;
            goto L_8003216C;
    }
    // 0x80032138: sh          $t2, 0x48($a2)
    MEM_H(0X48, ctx->r6) = ctx->r10;
    // 0x8003213C: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
L_80032140:
    // 0x80032140: lhu         $t4, 0x4E($a2)
    ctx->r12 = MEM_HU(ctx->r6, 0X4E);
    // 0x80032144: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x80032148: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8003214C: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80032150: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80032154: sh          $t6, 0x4E($a2)
    MEM_H(0X4E, ctx->r6) = ctx->r14;
    // 0x80032158: bne         $at, $zero, L_80032140
    if (ctx->r1 != 0) {
        // 0x8003215C: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_80032140;
    }
    // 0x8003215C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80032160: b           L_80032170
    // 0x80032164: lhu         $t7, 0x12($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X12);
        goto L_80032170;
    // 0x80032164: lhu         $t7, 0x12($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X12);
L_80032168:
    // 0x80032168: sw          $zero, 0x44($a2)
    MEM_W(0X44, ctx->r6) = 0;
L_8003216C:
    // 0x8003216C: lhu         $t7, 0x12($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X12);
L_80032170:
    // 0x80032170: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80032174: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80032178: bgez        $t7, L_8003218C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8003217C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8003218C;
    }
    // 0x8003217C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80032180: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80032184: nop

    // 0x80032188: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8003218C:
    // 0x8003218C: swc1        $f6, 0x5C($a2)
    MEM_W(0X5C, ctx->r6) = ctx->f6.u32l;
    // 0x80032190: lhu         $t8, 0x14($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X14);
    // 0x80032194: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80032198: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8003219C: bgez        $t8, L_800321B0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800321A0: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800321B0;
    }
    // 0x800321A0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800321A4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800321A8: nop

    // 0x800321AC: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_800321B0:
    // 0x800321B0: swc1        $f16, 0x60($a2)
    MEM_W(0X60, ctx->r6) = ctx->f16.u32l;
    // 0x800321B4: lhu         $t9, 0x16($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0X16);
    // 0x800321B8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800321BC: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800321C0: bgez        $t9, L_800321D4
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800321C4: cvt.s.w     $f8, $f4
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800321D4;
    }
    // 0x800321C4: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800321C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800321CC: nop

    // 0x800321D0: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
L_800321D4:
    // 0x800321D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800321D8: lwc1        $f0, 0x5C($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X5C);
    // 0x800321DC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800321E0: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800321E4: nop

    // 0x800321E8: div.s       $f16, $f18, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800321EC: swc1        $f8, 0x64($a2)
    MEM_W(0X64, ctx->r6) = ctx->f8.u32l;
    // 0x800321F0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800321F4: swc1        $f10, 0x68($a2)
    MEM_W(0X68, ctx->r6) = ctx->f10.u32l;
    // 0x800321F8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800321FC: swc1        $f16, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f16.u32l;
    // 0x80032200: lbu         $t0, 0x0($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X0);
    // 0x80032204: sh          $zero, 0x74($a2)
    MEM_H(0X74, ctx->r6) = 0;
    // 0x80032208: sll         $t1, $t0, 8
    ctx->r9 = S32(ctx->r8 << 8);
    // 0x8003220C: sh          $t1, 0x70($a2)
    MEM_H(0X70, ctx->r6) = ctx->r9;
    // 0x80032210: sh          $zero, 0x78($a2)
    MEM_H(0X78, ctx->r6) = 0;
    // 0x80032214: lbu         $t2, 0x1($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X1);
    // 0x80032218: sh          $zero, 0x76($a2)
    MEM_H(0X76, ctx->r6) = 0;
    // 0x8003221C: sll         $t3, $t2, 8
    ctx->r11 = S32(ctx->r10 << 8);
    // 0x80032220: sh          $t3, 0x72($a2)
    MEM_H(0X72, ctx->r6) = ctx->r11;
    // 0x80032224: sh          $zero, 0x7A($a2)
    MEM_H(0X7A, ctx->r6) = 0;
    // 0x80032228: sb          $t4, 0x5($a2)
    MEM_B(0X5, ctx->r6) = ctx->r12;
    // 0x8003222C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80032230: jal         0x80032464
    // 0x80032234: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    light_update(rdram, ctx);
        goto after_1;
    // 0x80032234: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80032238: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8003223C: nop

L_80032240:
    // 0x80032240: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80032244: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80032248: jr          $ra
    // 0x8003224C: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    return;
    // 0x8003224C: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
;}
RECOMP_FUNC void light_disable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032250: jr          $ra
    // 0x80032254: sb          $zero, 0x4($a0)
    MEM_B(0X4, ctx->r4) = 0;
    return;
    // 0x80032254: sb          $zero, 0x4($a0)
    MEM_B(0X4, ctx->r4) = 0;
;}
RECOMP_FUNC void light_enable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032258: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8003225C: jr          $ra
    // 0x80032260: sb          $t6, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r14;
    return;
    // 0x80032260: sb          $t6, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void light_toggle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032264: lbu         $t6, 0x4($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X4);
    // 0x80032268: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003226C: bne         $t6, $at, L_8003227C
    if (ctx->r14 != ctx->r1) {
        // 0x80032270: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8003227C;
    }
    // 0x80032270: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80032274: jr          $ra
    // 0x80032278: sb          $zero, 0x4($a0)
    MEM_B(0X4, ctx->r4) = 0;
    return;
    // 0x80032278: sb          $zero, 0x4($a0)
    MEM_B(0X4, ctx->r4) = 0;
L_8003227C:
    // 0x8003227C: sb          $t7, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r15;
    // 0x80032280: jr          $ra
    // 0x80032284: nop

    return;
    // 0x80032284: nop

;}
RECOMP_FUNC void light_setup_colour_change(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032288: blez        $a2, L_800322D4
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8003228C: nop
    
            goto L_800322D4;
    }
    // 0x8003228C: nop

    // 0x80032290: lw          $t7, 0x1C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1C);
    // 0x80032294: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x80032298: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x8003229C: div         $zero, $t8, $a2
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r6)));
    // 0x800322A0: sh          $a2, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r6;
    // 0x800322A4: bne         $a2, $zero, L_800322B0
    if (ctx->r6 != 0) {
        // 0x800322A8: nop
    
            goto L_800322B0;
    }
    // 0x800322A8: nop

    // 0x800322AC: break       7
    do_break(2147689132);
L_800322B0:
    // 0x800322B0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800322B4: bne         $a2, $at, L_800322C8
    if (ctx->r6 != ctx->r1) {
        // 0x800322B8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800322C8;
    }
    // 0x800322B8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800322BC: bne         $t8, $at, L_800322C8
    if (ctx->r24 != ctx->r1) {
        // 0x800322C0: nop
    
            goto L_800322C8;
    }
    // 0x800322C0: nop

    // 0x800322C4: break       6
    do_break(2147689156);
L_800322C8:
    // 0x800322C8: mflo        $t9
    ctx->r25 = lo;
    // 0x800322CC: sw          $t9, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r25;
    // 0x800322D0: nop

L_800322D4:
    // 0x800322D4: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x800322D8: nop

    // 0x800322DC: blez        $v0, L_80032328
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800322E0: nop
    
            goto L_80032328;
    }
    // 0x800322E0: nop

    // 0x800322E4: lw          $t1, 0x20($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X20);
    // 0x800322E8: sll         $t0, $a3, 16
    ctx->r8 = S32(ctx->r7 << 16);
    // 0x800322EC: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x800322F0: div         $zero, $t2, $v0
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r2)));
    // 0x800322F4: sh          $v0, 0x3E($a0)
    MEM_H(0X3E, ctx->r4) = ctx->r2;
    // 0x800322F8: bne         $v0, $zero, L_80032304
    if (ctx->r2 != 0) {
        // 0x800322FC: nop
    
            goto L_80032304;
    }
    // 0x800322FC: nop

    // 0x80032300: break       7
    do_break(2147689216);
L_80032304:
    // 0x80032304: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80032308: bne         $v0, $at, L_8003231C
    if (ctx->r2 != ctx->r1) {
        // 0x8003230C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8003231C;
    }
    // 0x8003230C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80032310: bne         $t2, $at, L_8003231C
    if (ctx->r10 != ctx->r1) {
        // 0x80032314: nop
    
            goto L_8003231C;
    }
    // 0x80032314: nop

    // 0x80032318: break       6
    do_break(2147689240);
L_8003231C:
    // 0x8003231C: mflo        $t3
    ctx->r11 = lo;
    // 0x80032320: sw          $t3, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r11;
    // 0x80032324: nop

L_80032328:
    // 0x80032328: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8003232C: lw          $t4, 0x14($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X14);
    // 0x80032330: blez        $v0, L_8003237C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80032334: nop
    
            goto L_8003237C;
    }
    // 0x80032334: nop

    // 0x80032338: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x8003233C: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x80032340: subu        $t7, $t5, $t6
    ctx->r15 = SUB32(ctx->r13, ctx->r14);
    // 0x80032344: div         $zero, $t7, $v0
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r2)));
    // 0x80032348: sh          $v0, 0x40($a0)
    MEM_H(0X40, ctx->r4) = ctx->r2;
    // 0x8003234C: bne         $v0, $zero, L_80032358
    if (ctx->r2 != 0) {
        // 0x80032350: nop
    
            goto L_80032358;
    }
    // 0x80032350: nop

    // 0x80032354: break       7
    do_break(2147689300);
L_80032358:
    // 0x80032358: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003235C: bne         $v0, $at, L_80032370
    if (ctx->r2 != ctx->r1) {
        // 0x80032360: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80032370;
    }
    // 0x80032360: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80032364: bne         $t7, $at, L_80032370
    if (ctx->r15 != ctx->r1) {
        // 0x80032368: nop
    
            goto L_80032370;
    }
    // 0x80032368: nop

    // 0x8003236C: break       6
    do_break(2147689324);
L_80032370:
    // 0x80032370: mflo        $t8
    ctx->r24 = lo;
    // 0x80032374: sw          $t8, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r24;
    // 0x80032378: nop

L_8003237C:
    // 0x8003237C: jr          $ra
    // 0x80032380: nop

    return;
    // 0x80032380: nop

;}
RECOMP_FUNC void light_setup_intensity_change(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032384: blez        $a2, L_800323D0
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80032388: nop
    
            goto L_800323D0;
    }
    // 0x80032388: nop

    // 0x8003238C: lw          $t7, 0x28($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X28);
    // 0x80032390: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x80032394: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80032398: div         $zero, $t8, $a2
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r6)));
    // 0x8003239C: sh          $a2, 0x42($a0)
    MEM_H(0X42, ctx->r4) = ctx->r6;
    // 0x800323A0: bne         $a2, $zero, L_800323AC
    if (ctx->r6 != 0) {
        // 0x800323A4: nop
    
            goto L_800323AC;
    }
    // 0x800323A4: nop

    // 0x800323A8: break       7
    do_break(2147689384);
L_800323AC:
    // 0x800323AC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800323B0: bne         $a2, $at, L_800323C4
    if (ctx->r6 != ctx->r1) {
        // 0x800323B4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800323C4;
    }
    // 0x800323B4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800323B8: bne         $t8, $at, L_800323C4
    if (ctx->r24 != ctx->r1) {
        // 0x800323BC: nop
    
            goto L_800323C4;
    }
    // 0x800323BC: nop

    // 0x800323C0: break       6
    do_break(2147689408);
L_800323C4:
    // 0x800323C4: mflo        $t9
    ctx->r25 = lo;
    // 0x800323C8: sw          $t9, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->r25;
    // 0x800323CC: nop

L_800323D0:
    // 0x800323D0: jr          $ra
    // 0x800323D4: nop

    return;
    // 0x800323D4: nop

;}
RECOMP_FUNC void light_update_all(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800323D8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800323DC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800323E0: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x800323E4: addiu       $s3, $s3, -0x3134
    ctx->r19 = ADD32(ctx->r19, -0X3134);
    // 0x800323E8: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x800323EC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800323F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800323F4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800323F8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800323FC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80032400: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80032404: blez        $t6, L_80032444
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80032408: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80032444;
    }
    // 0x80032408: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8003240C: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x80032410: addiu       $s4, $s4, -0x3140
    ctx->r20 = ADD32(ctx->r20, -0X3140);
    // 0x80032414: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80032418:
    // 0x80032418: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x8003241C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80032420: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x80032424: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x80032428: jal         0x80032464
    // 0x8003242C: nop

    light_update(rdram, ctx);
        goto after_0;
    // 0x8003242C: nop

    after_0:
    // 0x80032430: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x80032434: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80032438: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8003243C: bne         $at, $zero, L_80032418
    if (ctx->r1 != 0) {
        // 0x80032440: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80032418;
    }
    // 0x80032440: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_80032444:
    // 0x80032444: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80032448: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003244C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80032450: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80032454: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80032458: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8003245C: jr          $ra
    // 0x80032460: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80032460: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void light_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032464: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80032468: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003246C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80032470: lw          $a3, 0xC($a0)
    ctx->r7 = MEM_W(ctx->r4, 0XC);
    // 0x80032474: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80032478: beq         $a3, $zero, L_80032504
    if (ctx->r7 == 0) {
        // 0x8003247C: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_80032504;
    }
    // 0x8003247C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80032480: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x80032484: lh          $t7, 0x8($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X8);
    // 0x80032488: lh          $t8, 0xA($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XA);
    // 0x8003248C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80032490: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80032494: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80032498: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003249C: addiu       $a1, $a2, 0x10
    ctx->r5 = ADD32(ctx->r6, 0X10);
    // 0x800324A0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800324A4: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
    // 0x800324A8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800324AC: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
    // 0x800324B0: swc1        $f18, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f18.u32l;
    // 0x800324B4: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800324B8: jal         0x80070560
    // 0x800324BC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    vec3f_rotate(rdram, ctx);
        goto after_0;
    // 0x800324BC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x800324C0: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x800324C4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800324C8: lw          $a3, 0xC($a2)
    ctx->r7 = MEM_W(ctx->r6, 0XC);
    // 0x800324CC: lwc1        $f4, 0x10($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800324D0: lwc1        $f6, 0xC($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800324D4: lwc1        $f10, 0x14($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800324D8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800324DC: lwc1        $f4, 0x18($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X18);
    // 0x800324E0: swc1        $f8, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f8.u32l;
    // 0x800324E4: lwc1        $f16, 0x10($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X10);
    // 0x800324E8: nop

    // 0x800324EC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800324F0: swc1        $f18, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f18.u32l;
    // 0x800324F4: lwc1        $f6, 0x14($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X14);
    // 0x800324F8: sb          $t3, 0x5($a2)
    MEM_B(0X5, ctx->r6) = ctx->r11;
    // 0x800324FC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80032500: swc1        $f8, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f8.u32l;
L_80032504:
    // 0x80032504: lw          $a1, 0x44($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X44);
    // 0x80032508: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8003250C: beq         $a1, $zero, L_800326C8
    if (ctx->r5 == 0) {
        // 0x80032510: nop
    
            goto L_800326C8;
    }
    // 0x80032510: nop

    // 0x80032514: lhu         $t9, 0x4C($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X4C);
    // 0x80032518: lhu         $v0, 0x4A($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X4A);
    // 0x8003251C: addu        $t4, $t9, $s0
    ctx->r12 = ADD32(ctx->r25, ctx->r16);
    // 0x80032520: sll         $t5, $v0, 3
    ctx->r13 = S32(ctx->r2 << 3);
    // 0x80032524: sh          $t4, 0x4C($a2)
    MEM_H(0X4C, ctx->r6) = ctx->r12;
    // 0x80032528: addu        $t6, $a1, $t5
    ctx->r14 = ADD32(ctx->r5, ctx->r13);
    // 0x8003252C: lw          $v1, 0x4($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X4);
    // 0x80032530: andi        $a0, $t4, 0xFFFF
    ctx->r4 = ctx->r12 & 0XFFFF;
    // 0x80032534: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80032538: bne         $at, $zero, L_8003258C
    if (ctx->r1 != 0) {
        // 0x8003253C: nop
    
            goto L_8003258C;
    }
    // 0x8003253C: nop

L_80032540:
    // 0x80032540: lhu         $t9, 0x48($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X48);
    // 0x80032544: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x80032548: andi        $v0, $t8, 0xFFFF
    ctx->r2 = ctx->r24 & 0XFFFF;
    // 0x8003254C: subu        $t7, $a0, $v1
    ctx->r15 = SUB32(ctx->r4, ctx->r3);
    // 0x80032550: slt         $at, $t9, $v0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80032554: sh          $t7, 0x4C($a2)
    MEM_H(0X4C, ctx->r6) = ctx->r15;
    // 0x80032558: beq         $at, $zero, L_8003256C
    if (ctx->r1 == 0) {
        // 0x8003255C: sh          $t8, 0x4A($a2)
        MEM_H(0X4A, ctx->r6) = ctx->r24;
            goto L_8003256C;
    }
    // 0x8003255C: sh          $t8, 0x4A($a2)
    MEM_H(0X4A, ctx->r6) = ctx->r24;
    // 0x80032560: lw          $a1, 0x44($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X44);
    // 0x80032564: sh          $zero, 0x4A($a2)
    MEM_H(0X4A, ctx->r6) = 0;
    // 0x80032568: andi        $v0, $zero, 0xFFFF
    ctx->r2 = 0 & 0XFFFF;
L_8003256C:
    // 0x8003256C: sll         $t4, $v0, 3
    ctx->r12 = S32(ctx->r2 << 3);
    // 0x80032570: addu        $t5, $a1, $t4
    ctx->r13 = ADD32(ctx->r5, ctx->r12);
    // 0x80032574: lw          $v1, 0x4($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X4);
    // 0x80032578: lhu         $a0, 0x4C($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0X4C);
    // 0x8003257C: nop

    // 0x80032580: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80032584: beq         $at, $zero, L_80032540
    if (ctx->r1 == 0) {
        // 0x80032588: nop
    
            goto L_80032540;
    }
    // 0x80032588: nop

L_8003258C:
    // 0x8003258C: lhu         $t7, 0x48($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0X48);
    // 0x80032590: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x80032594: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80032598: slt         $at, $v0, $t8
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8003259C: addu        $v1, $a1, $t6
    ctx->r3 = ADD32(ctx->r5, ctx->r14);
    // 0x800325A0: beq         $at, $zero, L_800325B8
    if (ctx->r1 == 0) {
        // 0x800325A4: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_800325B8;
    }
    // 0x800325A4: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x800325A8: addiu       $t9, $t0, 0x1
    ctx->r25 = ADD32(ctx->r8, 0X1);
    // 0x800325AC: sll         $t4, $t9, 3
    ctx->r12 = S32(ctx->r25 << 3);
    // 0x800325B0: b           L_800325BC
    // 0x800325B4: addu        $a3, $a1, $t4
    ctx->r7 = ADD32(ctx->r5, ctx->r12);
        goto L_800325BC;
    // 0x800325B4: addu        $a3, $a1, $t4
    ctx->r7 = ADD32(ctx->r5, ctx->r12);
L_800325B8:
    // 0x800325B8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
L_800325BC:
    // 0x800325BC: lw          $t5, 0x4($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X4);
    // 0x800325C0: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x800325C4: div         $zero, $t6, $t5
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r13))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r13)));
    // 0x800325C8: lbu         $a1, 0x0($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X0);
    // 0x800325CC: lbu         $t7, 0x0($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X0);
    // 0x800325D0: bne         $t5, $zero, L_800325DC
    if (ctx->r13 != 0) {
        // 0x800325D4: nop
    
            goto L_800325DC;
    }
    // 0x800325D4: nop

    // 0x800325D8: break       7
    do_break(2147689944);
L_800325DC:
    // 0x800325DC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800325E0: bne         $t5, $at, L_800325F4
    if (ctx->r13 != ctx->r1) {
        // 0x800325E4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800325F4;
    }
    // 0x800325E4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800325E8: bne         $t6, $at, L_800325F4
    if (ctx->r14 != ctx->r1) {
        // 0x800325EC: nop
    
            goto L_800325F4;
    }
    // 0x800325EC: nop

    // 0x800325F0: break       6
    do_break(2147689968);
L_800325F4:
    // 0x800325F4: subu        $t8, $t7, $a1
    ctx->r24 = SUB32(ctx->r15, ctx->r5);
    // 0x800325F8: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x800325FC: mflo        $v0
    ctx->r2 = lo;
    // 0x80032600: nop

    // 0x80032604: nop

    // 0x80032608: multu       $t8, $a0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003260C: mflo        $t9
    ctx->r25 = lo;
    // 0x80032610: nop

    // 0x80032614: nop

    // 0x80032618: multu       $t9, $v0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003261C: mflo        $t4
    ctx->r12 = lo;
    // 0x80032620: addu        $t5, $t4, $t6
    ctx->r13 = ADD32(ctx->r12, ctx->r14);
    // 0x80032624: sw          $t5, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r13;
    // 0x80032628: lbu         $t7, 0x1($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X1);
    // 0x8003262C: lbu         $t0, 0x1($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X1);
    // 0x80032630: nop

    // 0x80032634: subu        $t8, $t7, $t0
    ctx->r24 = SUB32(ctx->r15, ctx->r8);
    // 0x80032638: multu       $t8, $a0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003263C: sll         $t6, $t0, 16
    ctx->r14 = S32(ctx->r8 << 16);
    // 0x80032640: mflo        $t9
    ctx->r25 = lo;
    // 0x80032644: nop

    // 0x80032648: nop

    // 0x8003264C: multu       $t9, $v0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80032650: mflo        $t4
    ctx->r12 = lo;
    // 0x80032654: addu        $t5, $t4, $t6
    ctx->r13 = ADD32(ctx->r12, ctx->r14);
    // 0x80032658: sw          $t5, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->r13;
    // 0x8003265C: lbu         $t7, 0x2($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X2);
    // 0x80032660: lbu         $t1, 0x2($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X2);
    // 0x80032664: nop

    // 0x80032668: subu        $t8, $t7, $t1
    ctx->r24 = SUB32(ctx->r15, ctx->r9);
    // 0x8003266C: multu       $t8, $a0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80032670: sll         $t6, $t1, 16
    ctx->r14 = S32(ctx->r9 << 16);
    // 0x80032674: mflo        $t9
    ctx->r25 = lo;
    // 0x80032678: nop

    // 0x8003267C: nop

    // 0x80032680: multu       $t9, $v0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80032684: mflo        $t4
    ctx->r12 = lo;
    // 0x80032688: addu        $t5, $t4, $t6
    ctx->r13 = ADD32(ctx->r12, ctx->r14);
    // 0x8003268C: sw          $t5, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r13;
    // 0x80032690: lbu         $t7, 0x3($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X3);
    // 0x80032694: lbu         $t2, 0x3($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X3);
    // 0x80032698: nop

    // 0x8003269C: subu        $t8, $t7, $t2
    ctx->r24 = SUB32(ctx->r15, ctx->r10);
    // 0x800326A0: multu       $t8, $a0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800326A4: sll         $t6, $t2, 16
    ctx->r14 = S32(ctx->r10 << 16);
    // 0x800326A8: mflo        $t9
    ctx->r25 = lo;
    // 0x800326AC: nop

    // 0x800326B0: nop

    // 0x800326B4: multu       $t9, $v0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800326B8: mflo        $t4
    ctx->r12 = lo;
    // 0x800326BC: addu        $t5, $t4, $t6
    ctx->r13 = ADD32(ctx->r12, ctx->r14);
    // 0x800326C0: b           L_80032828
    // 0x800326C4: sw          $t5, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->r13;
        goto L_80032828;
    // 0x800326C4: sw          $t5, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->r13;
L_800326C8:
    // 0x800326C8: lhu         $v1, 0x3C($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X3C);
    // 0x800326CC: nop

    // 0x800326D0: beq         $v1, $zero, L_80032720
    if (ctx->r3 == 0) {
        // 0x800326D4: slt         $at, $s0, $v1
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80032720;
    }
    // 0x800326D4: slt         $at, $s0, $v1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800326D8: beq         $at, $zero, L_80032704
    if (ctx->r1 == 0) {
        // 0x800326DC: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80032704;
    }
    // 0x800326DC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800326E0: lw          $t8, 0x2C($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X2C);
    // 0x800326E4: lw          $t7, 0x1C($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X1C);
    // 0x800326E8: multu       $t8, $s0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800326EC: subu        $t6, $v1, $s0
    ctx->r14 = SUB32(ctx->r3, ctx->r16);
    // 0x800326F0: sh          $t6, 0x3C($a2)
    MEM_H(0X3C, ctx->r6) = ctx->r14;
    // 0x800326F4: mflo        $t9
    ctx->r25 = lo;
    // 0x800326F8: addu        $t4, $t7, $t9
    ctx->r12 = ADD32(ctx->r15, ctx->r25);
    // 0x800326FC: b           L_80032720
    // 0x80032700: sw          $t4, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r12;
        goto L_80032720;
    // 0x80032700: sw          $t4, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r12;
L_80032704:
    // 0x80032704: lw          $t8, 0x2C($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X2C);
    // 0x80032708: lw          $t5, 0x1C($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X1C);
    // 0x8003270C: multu       $t8, $v0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80032710: sh          $zero, 0x3C($a2)
    MEM_H(0X3C, ctx->r6) = 0;
    // 0x80032714: mflo        $t7
    ctx->r15 = lo;
    // 0x80032718: addu        $t9, $t5, $t7
    ctx->r25 = ADD32(ctx->r13, ctx->r15);
    // 0x8003271C: sw          $t9, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r25;
L_80032720:
    // 0x80032720: lhu         $v1, 0x3E($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X3E);
    // 0x80032724: nop

    // 0x80032728: beq         $v1, $zero, L_80032778
    if (ctx->r3 == 0) {
        // 0x8003272C: slt         $at, $s0, $v1
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80032778;
    }
    // 0x8003272C: slt         $at, $s0, $v1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80032730: beq         $at, $zero, L_8003275C
    if (ctx->r1 == 0) {
        // 0x80032734: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8003275C;
    }
    // 0x80032734: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80032738: lw          $t6, 0x30($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X30);
    // 0x8003273C: lw          $t4, 0x20($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X20);
    // 0x80032740: multu       $t6, $s0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80032744: subu        $t7, $v1, $s0
    ctx->r15 = SUB32(ctx->r3, ctx->r16);
    // 0x80032748: sh          $t7, 0x3E($a2)
    MEM_H(0X3E, ctx->r6) = ctx->r15;
    // 0x8003274C: mflo        $t8
    ctx->r24 = lo;
    // 0x80032750: addu        $t5, $t4, $t8
    ctx->r13 = ADD32(ctx->r12, ctx->r24);
    // 0x80032754: b           L_80032778
    // 0x80032758: sw          $t5, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->r13;
        goto L_80032778;
    // 0x80032758: sw          $t5, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->r13;
L_8003275C:
    // 0x8003275C: lw          $t6, 0x30($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X30);
    // 0x80032760: lw          $t9, 0x20($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X20);
    // 0x80032764: multu       $t6, $v0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80032768: sh          $zero, 0x3E($a2)
    MEM_H(0X3E, ctx->r6) = 0;
    // 0x8003276C: mflo        $t4
    ctx->r12 = lo;
    // 0x80032770: addu        $t8, $t9, $t4
    ctx->r24 = ADD32(ctx->r25, ctx->r12);
    // 0x80032774: sw          $t8, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->r24;
L_80032778:
    // 0x80032778: lhu         $v1, 0x40($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X40);
    // 0x8003277C: nop

    // 0x80032780: beq         $v1, $zero, L_800327D0
    if (ctx->r3 == 0) {
        // 0x80032784: slt         $at, $s0, $v1
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800327D0;
    }
    // 0x80032784: slt         $at, $s0, $v1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80032788: beq         $at, $zero, L_800327B4
    if (ctx->r1 == 0) {
        // 0x8003278C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800327B4;
    }
    // 0x8003278C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80032790: lw          $t7, 0x34($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X34);
    // 0x80032794: lw          $t5, 0x24($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X24);
    // 0x80032798: multu       $t7, $s0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003279C: subu        $t4, $v1, $s0
    ctx->r12 = SUB32(ctx->r3, ctx->r16);
    // 0x800327A0: sh          $t4, 0x40($a2)
    MEM_H(0X40, ctx->r6) = ctx->r12;
    // 0x800327A4: mflo        $t6
    ctx->r14 = lo;
    // 0x800327A8: addu        $t9, $t5, $t6
    ctx->r25 = ADD32(ctx->r13, ctx->r14);
    // 0x800327AC: b           L_800327D0
    // 0x800327B0: sw          $t9, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r25;
        goto L_800327D0;
    // 0x800327B0: sw          $t9, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r25;
L_800327B4:
    // 0x800327B4: lw          $t7, 0x34($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X34);
    // 0x800327B8: lw          $t8, 0x24($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X24);
    // 0x800327BC: multu       $t7, $v0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800327C0: sh          $zero, 0x40($a2)
    MEM_H(0X40, ctx->r6) = 0;
    // 0x800327C4: mflo        $t5
    ctx->r13 = lo;
    // 0x800327C8: addu        $t6, $t8, $t5
    ctx->r14 = ADD32(ctx->r24, ctx->r13);
    // 0x800327CC: sw          $t6, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r14;
L_800327D0:
    // 0x800327D0: lhu         $v1, 0x42($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X42);
    // 0x800327D4: nop

    // 0x800327D8: beq         $v1, $zero, L_80032828
    if (ctx->r3 == 0) {
        // 0x800327DC: slt         $at, $s0, $v1
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80032828;
    }
    // 0x800327DC: slt         $at, $s0, $v1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800327E0: beq         $at, $zero, L_8003280C
    if (ctx->r1 == 0) {
        // 0x800327E4: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8003280C;
    }
    // 0x800327E4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800327E8: lw          $t4, 0x38($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X38);
    // 0x800327EC: lw          $t9, 0x28($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X28);
    // 0x800327F0: multu       $t4, $s0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800327F4: subu        $t5, $v1, $s0
    ctx->r13 = SUB32(ctx->r3, ctx->r16);
    // 0x800327F8: sh          $t5, 0x42($a2)
    MEM_H(0X42, ctx->r6) = ctx->r13;
    // 0x800327FC: mflo        $t7
    ctx->r15 = lo;
    // 0x80032800: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x80032804: b           L_80032828
    // 0x80032808: sw          $t8, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->r24;
        goto L_80032828;
    // 0x80032808: sw          $t8, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->r24;
L_8003280C:
    // 0x8003280C: lw          $t4, 0x38($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X38);
    // 0x80032810: lw          $t6, 0x28($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X28);
    // 0x80032814: multu       $t4, $v0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80032818: sh          $zero, 0x42($a2)
    MEM_H(0X42, ctx->r6) = 0;
    // 0x8003281C: mflo        $t9
    ctx->r25 = lo;
    // 0x80032820: addu        $t7, $t6, $t9
    ctx->r15 = ADD32(ctx->r14, ctx->r25);
    // 0x80032824: sw          $t7, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->r15;
L_80032828:
    // 0x80032828: lhu         $v1, 0x78($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X78);
    // 0x8003282C: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80032830: beq         $v1, $zero, L_800328AC
    if (ctx->r3 == 0) {
        // 0x80032834: nop
    
            goto L_800328AC;
    }
    // 0x80032834: nop

    // 0x80032838: bne         $v1, $at, L_8003285C
    if (ctx->r3 != ctx->r1) {
        // 0x8003283C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8003285C;
    }
    // 0x8003283C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80032840: lh          $t5, 0x74($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X74);
    // 0x80032844: lh          $t8, 0x70($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X70);
    // 0x80032848: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003284C: mflo        $t4
    ctx->r12 = lo;
    // 0x80032850: addu        $t6, $t8, $t4
    ctx->r14 = ADD32(ctx->r24, ctx->r12);
    // 0x80032854: b           L_800328A8
    // 0x80032858: sh          $t6, 0x70($a2)
    MEM_H(0X70, ctx->r6) = ctx->r14;
        goto L_800328A8;
    // 0x80032858: sh          $t6, 0x70($a2)
    MEM_H(0X70, ctx->r6) = ctx->r14;
L_8003285C:
    // 0x8003285C: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80032860: beq         $at, $zero, L_8003288C
    if (ctx->r1 == 0) {
        // 0x80032864: nop
    
            goto L_8003288C;
    }
    // 0x80032864: nop

    // 0x80032868: lh          $t7, 0x74($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X74);
    // 0x8003286C: lh          $t9, 0x70($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X70);
    // 0x80032870: multu       $t7, $s0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80032874: subu        $t4, $v0, $s0
    ctx->r12 = SUB32(ctx->r2, ctx->r16);
    // 0x80032878: sh          $t4, 0x78($a2)
    MEM_H(0X78, ctx->r6) = ctx->r12;
    // 0x8003287C: mflo        $t5
    ctx->r13 = lo;
    // 0x80032880: addu        $t8, $t9, $t5
    ctx->r24 = ADD32(ctx->r25, ctx->r13);
    // 0x80032884: b           L_800328A8
    // 0x80032888: sh          $t8, 0x70($a2)
    MEM_H(0X70, ctx->r6) = ctx->r24;
        goto L_800328A8;
    // 0x80032888: sh          $t8, 0x70($a2)
    MEM_H(0X70, ctx->r6) = ctx->r24;
L_8003288C:
    // 0x8003288C: lh          $t7, 0x74($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X74);
    // 0x80032890: lh          $t6, 0x70($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X70);
    // 0x80032894: multu       $t7, $v0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80032898: sh          $zero, 0x78($a2)
    MEM_H(0X78, ctx->r6) = 0;
    // 0x8003289C: mflo        $t9
    ctx->r25 = lo;
    // 0x800328A0: addu        $t5, $t6, $t9
    ctx->r13 = ADD32(ctx->r14, ctx->r25);
    // 0x800328A4: sh          $t5, 0x70($a2)
    MEM_H(0X70, ctx->r6) = ctx->r13;
L_800328A8:
    // 0x800328A8: sb          $t3, 0x5($a2)
    MEM_B(0X5, ctx->r6) = ctx->r11;
L_800328AC:
    // 0x800328AC: lhu         $v1, 0x7A($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X7A);
    // 0x800328B0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800328B4: beq         $v1, $zero, L_80032930
    if (ctx->r3 == 0) {
        // 0x800328B8: nop
    
            goto L_80032930;
    }
    // 0x800328B8: nop

    // 0x800328BC: bne         $v1, $at, L_800328E0
    if (ctx->r3 != ctx->r1) {
        // 0x800328C0: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800328E0;
    }
    // 0x800328C0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800328C4: lh          $t4, 0x76($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X76);
    // 0x800328C8: lh          $t8, 0x72($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X72);
    // 0x800328CC: multu       $t4, $s0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800328D0: mflo        $t7
    ctx->r15 = lo;
    // 0x800328D4: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x800328D8: b           L_8003292C
    // 0x800328DC: sh          $t6, 0x72($a2)
    MEM_H(0X72, ctx->r6) = ctx->r14;
        goto L_8003292C;
    // 0x800328DC: sh          $t6, 0x72($a2)
    MEM_H(0X72, ctx->r6) = ctx->r14;
L_800328E0:
    // 0x800328E0: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800328E4: beq         $at, $zero, L_80032910
    if (ctx->r1 == 0) {
        // 0x800328E8: nop
    
            goto L_80032910;
    }
    // 0x800328E8: nop

    // 0x800328EC: lh          $t5, 0x76($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X76);
    // 0x800328F0: lh          $t9, 0x72($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X72);
    // 0x800328F4: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800328F8: subu        $t7, $v0, $s0
    ctx->r15 = SUB32(ctx->r2, ctx->r16);
    // 0x800328FC: sh          $t7, 0x7A($a2)
    MEM_H(0X7A, ctx->r6) = ctx->r15;
    // 0x80032900: mflo        $t4
    ctx->r12 = lo;
    // 0x80032904: addu        $t8, $t9, $t4
    ctx->r24 = ADD32(ctx->r25, ctx->r12);
    // 0x80032908: b           L_8003292C
    // 0x8003290C: sh          $t8, 0x72($a2)
    MEM_H(0X72, ctx->r6) = ctx->r24;
        goto L_8003292C;
    // 0x8003290C: sh          $t8, 0x72($a2)
    MEM_H(0X72, ctx->r6) = ctx->r24;
L_80032910:
    // 0x80032910: lh          $t5, 0x76($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X76);
    // 0x80032914: lh          $t6, 0x72($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X72);
    // 0x80032918: multu       $t5, $v0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003291C: sh          $zero, 0x7A($a2)
    MEM_H(0X7A, ctx->r6) = 0;
    // 0x80032920: mflo        $t9
    ctx->r25 = lo;
    // 0x80032924: addu        $t4, $t6, $t9
    ctx->r12 = ADD32(ctx->r14, ctx->r25);
    // 0x80032928: sh          $t4, 0x72($a2)
    MEM_H(0X72, ctx->r6) = ctx->r12;
L_8003292C:
    // 0x8003292C: sb          $t3, 0x5($a2)
    MEM_B(0X5, ctx->r6) = ctx->r11;
L_80032930:
    // 0x80032930: lbu         $t8, 0x5($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X5);
    // 0x80032934: nop

    // 0x80032938: beq         $t8, $zero, L_80032BE0
    if (ctx->r24 == 0) {
        // 0x8003293C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80032BE0;
    }
    // 0x8003293C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80032940: lwc1        $f2, 0x10($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X10);
    // 0x80032944: lwc1        $f0, 0x5C($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X5C);
    // 0x80032948: lbu         $t4, 0x0($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X0);
    // 0x8003294C: sub.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80032950: addiu       $s0, $a2, 0x7C
    ctx->r16 = ADD32(ctx->r6, 0X7C);
    // 0x80032954: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80032958: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8003295C: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80032960: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80032964: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80032968: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x8003296C: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80032970: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80032974: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    // 0x80032978: add.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8003297C: sh          $t5, 0x50($a2)
    MEM_H(0X50, ctx->r6) = ctx->r13;
    // 0x80032980: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80032984: nop

    // 0x80032988: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8003298C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80032990: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80032994: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80032998: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8003299C: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x800329A0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800329A4: bne         $t4, $at, L_80032A10
    if (ctx->r12 != ctx->r1) {
        // 0x800329A8: sh          $t9, 0x56($a2)
        MEM_H(0X56, ctx->r6) = ctx->r25;
            goto L_80032A10;
    }
    // 0x800329A8: sh          $t9, 0x56($a2)
    MEM_H(0X56, ctx->r6) = ctx->r25;
    // 0x800329AC: lwc1        $f2, 0x14($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800329B0: nop

    // 0x800329B4: sub.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800329B8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800329BC: nop

    // 0x800329C0: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800329C4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800329C8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800329CC: nop

    // 0x800329D0: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800329D4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800329D8: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x800329DC: add.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800329E0: sh          $t7, 0x52($a2)
    MEM_H(0X52, ctx->r6) = ctx->r15;
    // 0x800329E4: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800329E8: nop

    // 0x800329EC: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800329F0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800329F4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800329F8: nop

    // 0x800329FC: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80032A00: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    // 0x80032A04: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80032A08: b           L_80032A78
    // 0x80032A0C: sh          $t6, 0x58($a2)
    MEM_H(0X58, ctx->r6) = ctx->r14;
        goto L_80032A78;
    // 0x80032A0C: sh          $t6, 0x58($a2)
    MEM_H(0X58, ctx->r6) = ctx->r14;
L_80032A10:
    // 0x80032A10: lwc1        $f2, 0x14($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X14);
    // 0x80032A14: lwc1        $f0, 0x60($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X60);
    // 0x80032A18: nop

    // 0x80032A1C: sub.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80032A20: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80032A24: nop

    // 0x80032A28: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80032A2C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80032A30: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80032A34: nop

    // 0x80032A38: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80032A3C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80032A40: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x80032A44: add.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80032A48: sh          $t4, 0x52($a2)
    MEM_H(0X52, ctx->r6) = ctx->r12;
    // 0x80032A4C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80032A50: nop

    // 0x80032A54: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80032A58: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80032A5C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80032A60: nop

    // 0x80032A64: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80032A68: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x80032A6C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80032A70: sh          $t7, 0x58($a2)
    MEM_H(0X58, ctx->r6) = ctx->r15;
    // 0x80032A74: nop

L_80032A78:
    // 0x80032A78: lbu         $t5, 0x0($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X0);
    // 0x80032A7C: nop

    // 0x80032A80: bne         $t5, $zero, L_80032AF0
    if (ctx->r13 != 0) {
        // 0x80032A84: nop
    
            goto L_80032AF0;
    }
    // 0x80032A84: nop

    // 0x80032A88: lwc1        $f2, 0x18($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X18);
    // 0x80032A8C: lwc1        $f0, 0x64($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X64);
    // 0x80032A90: nop

    // 0x80032A94: sub.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80032A98: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80032A9C: nop

    // 0x80032AA0: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80032AA4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80032AA8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80032AAC: nop

    // 0x80032AB0: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80032AB4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80032AB8: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x80032ABC: add.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80032AC0: sh          $t9, 0x54($a2)
    MEM_H(0X54, ctx->r6) = ctx->r25;
    // 0x80032AC4: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80032AC8: nop

    // 0x80032ACC: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x80032AD0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80032AD4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80032AD8: nop

    // 0x80032ADC: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80032AE0: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x80032AE4: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80032AE8: b           L_80032B58
    // 0x80032AEC: sh          $t8, 0x5A($a2)
    MEM_H(0X5A, ctx->r6) = ctx->r24;
        goto L_80032B58;
    // 0x80032AEC: sh          $t8, 0x5A($a2)
    MEM_H(0X5A, ctx->r6) = ctx->r24;
L_80032AF0:
    // 0x80032AF0: lwc1        $f2, 0x18($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X18);
    // 0x80032AF4: lwc1        $f0, 0x5C($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X5C);
    // 0x80032AF8: nop

    // 0x80032AFC: sub.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80032B00: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80032B04: nop

    // 0x80032B08: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80032B0C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80032B10: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80032B14: nop

    // 0x80032B18: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80032B1C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80032B20: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x80032B24: add.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80032B28: sh          $t5, 0x54($a2)
    MEM_H(0X54, ctx->r6) = ctx->r13;
    // 0x80032B2C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80032B30: nop

    // 0x80032B34: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80032B38: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80032B3C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80032B40: nop

    // 0x80032B44: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80032B48: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x80032B4C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80032B50: sh          $t9, 0x5A($a2)
    MEM_H(0X5A, ctx->r6) = ctx->r25;
    // 0x80032B54: nop

L_80032B58:
    // 0x80032B58: lbu         $t4, 0x1($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X1);
    // 0x80032B5C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80032B60: bne         $t4, $at, L_80032BD8
    if (ctx->r12 != ctx->r1) {
        // 0x80032B64: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_80032BD8;
    }
    // 0x80032B64: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80032B68: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80032B6C: lh          $t8, 0x70($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X70);
    // 0x80032B70: swc1        $f18, 0x84($a2)
    MEM_W(0X84, ctx->r6) = ctx->f18.u32l;
    // 0x80032B74: sh          $t8, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r24;
    // 0x80032B78: lh          $t7, 0x72($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X72);
    // 0x80032B7C: sh          $zero, 0x44($sp)
    MEM_H(0X44, ctx->r29) = 0;
    // 0x80032B80: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80032B84: jal         0x800706D0
    // 0x80032B88: sh          $t7, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r15;
    vec3f_rotate_py(rdram, ctx);
        goto after_1;
    // 0x80032B88: sh          $t7, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r15;
    after_1:
    // 0x80032B8C: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x80032B90: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80032B94: lw          $a3, 0xC($a2)
    ctx->r7 = MEM_W(ctx->r6, 0XC);
    // 0x80032B98: nop

    // 0x80032B9C: beq         $a3, $zero, L_80032BB4
    if (ctx->r7 == 0) {
        // 0x80032BA0: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80032BB4;
    }
    // 0x80032BA0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80032BA4: jal         0x80070560
    // 0x80032BA8: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    vec3f_rotate(rdram, ctx);
        goto after_2;
    // 0x80032BA8: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_2:
    // 0x80032BAC: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x80032BB0: nop

L_80032BB4:
    // 0x80032BB4: lwc1        $f4, 0x7C($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X7C);
    // 0x80032BB8: lwc1        $f8, 0x80($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X80);
    // 0x80032BBC: lwc1        $f16, 0x84($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X84);
    // 0x80032BC0: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80032BC4: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80032BC8: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x80032BCC: swc1        $f6, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->f6.u32l;
    // 0x80032BD0: swc1        $f10, 0x80($a2)
    MEM_W(0X80, ctx->r6) = ctx->f10.u32l;
    // 0x80032BD4: swc1        $f18, 0x84($a2)
    MEM_W(0X84, ctx->r6) = ctx->f18.u32l;
L_80032BD8:
    // 0x80032BD8: sb          $zero, 0x5($a2)
    MEM_B(0X5, ctx->r6) = 0;
    // 0x80032BDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80032BE0:
    // 0x80032BE0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80032BE4: jr          $ra
    // 0x80032BE8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80032BE8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void light_remove(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032BEC: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80032BF0: addiu       $t0, $t0, -0x3134
    ctx->r8 = ADD32(ctx->r8, -0X3134);
    // 0x80032BF4: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x80032BF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80032BFC: blez        $a1, L_80032C38
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80032C00: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80032C38;
    }
    // 0x80032C00: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80032C04: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80032C08: lw          $t6, -0x3140($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3140);
    // 0x80032C0C: sll         $t7, $zero, 2
    ctx->r15 = S32(0 << 2);
    // 0x80032C10: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
L_80032C14:
    // 0x80032C14: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x80032C18: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80032C1C: bne         $a0, $a3, L_80032C28
    if (ctx->r4 != ctx->r7) {
        // 0x80032C20: slt         $at, $v1, $a1
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_80032C28;
    }
    // 0x80032C20: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80032C24: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_80032C28:
    // 0x80032C28: beq         $at, $zero, L_80032C38
    if (ctx->r1 == 0) {
        // 0x80032C2C: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_80032C38;
    }
    // 0x80032C2C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80032C30: beq         $v0, $zero, L_80032C14
    if (ctx->r2 == 0) {
        // 0x80032C34: nop
    
            goto L_80032C14;
    }
    // 0x80032C34: nop

L_80032C38:
    // 0x80032C38: beq         $v0, $zero, L_80032CA4
    if (ctx->r2 == 0) {
        // 0x80032C3C: addiu       $t8, $a1, -0x1
        ctx->r24 = ADD32(ctx->r5, -0X1);
            goto L_80032CA4;
    }
    // 0x80032C3C: addiu       $t8, $a1, -0x1
    ctx->r24 = ADD32(ctx->r5, -0X1);
    // 0x80032C40: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80032C44: slt         $at, $v1, $t8
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80032C48: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80032C4C: beq         $at, $zero, L_80032C8C
    if (ctx->r1 == 0) {
        // 0x80032C50: or          $a1, $t8, $zero
        ctx->r5 = ctx->r24 | 0;
            goto L_80032C8C;
    }
    // 0x80032C50: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x80032C54: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80032C58: addiu       $a3, $a3, -0x3140
    ctx->r7 = ADD32(ctx->r7, -0X3140);
    // 0x80032C5C: sll         $a0, $v1, 2
    ctx->r4 = S32(ctx->r3 << 2);
L_80032C60:
    // 0x80032C60: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x80032C64: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80032C68: addu        $a2, $t9, $a0
    ctx->r6 = ADD32(ctx->r25, ctx->r4);
    // 0x80032C6C: lw          $t1, 0x4($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X4);
    // 0x80032C70: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80032C74: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // 0x80032C78: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x80032C7C: nop

    // 0x80032C80: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80032C84: bne         $at, $zero, L_80032C60
    if (ctx->r1 != 0) {
        // 0x80032C88: nop
    
            goto L_80032C60;
    }
    // 0x80032C88: nop

L_80032C8C:
    // 0x80032C8C: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80032C90: addiu       $a3, $a3, -0x3140
    ctx->r7 = ADD32(ctx->r7, -0X3140);
    // 0x80032C94: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x80032C98: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x80032C9C: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80032CA0: sw          $v0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r2;
L_80032CA4:
    // 0x80032CA4: jr          $ra
    // 0x80032CA8: nop

    return;
    // 0x80032CA8: nop

;}
RECOMP_FUNC void light_count(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032CAC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80032CB0: lw          $v0, -0x3134($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3134);
    // 0x80032CB4: jr          $ra
    // 0x80032CB8: nop

    return;
    // 0x80032CB8: nop

;}
RECOMP_FUNC void light_update_shading(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032CBC: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80032CC0: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80032CC4: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x80032CC8: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x80032CCC: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x80032CD0: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x80032CD4: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x80032CD8: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x80032CDC: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80032CE0: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80032CE4: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80032CE8: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x80032CEC: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x80032CF0: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80032CF4: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x80032CF8: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80032CFC: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x80032D00: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80032D04: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80032D08: lw          $v1, 0x40($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X40);
    // 0x80032D0C: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x80032D10: lbu         $t6, 0x3D($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X3D);
    // 0x80032D14: nop

    // 0x80032D18: bne         $t6, $zero, L_800337D8
    if (ctx->r14 != 0) {
        // 0x80032D1C: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_800337D8;
    }
    // 0x80032D1C: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x80032D20: lb          $v0, 0x53($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X53);
    // 0x80032D24: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80032D28: beq         $v0, $zero, L_80032D50
    if (ctx->r2 == 0) {
        // 0x80032D2C: lui         $s7, 0x8012
        ctx->r23 = S32(0X8012 << 16);
            goto L_80032D50;
    }
    // 0x80032D2C: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x80032D30: beq         $v0, $at, L_80032D58
    if (ctx->r2 == ctx->r1) {
        // 0x80032D34: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80032D58;
    }
    // 0x80032D34: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80032D38: beq         $v0, $at, L_80032D60
    if (ctx->r2 == ctx->r1) {
        // 0x80032D3C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80032D60;
    }
    // 0x80032D3C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80032D40: beq         $v0, $at, L_80032D68
    if (ctx->r2 == ctx->r1) {
        // 0x80032D44: addiu       $v1, $zero, 0x4
        ctx->r3 = ADD32(0, 0X4);
            goto L_80032D68;
    }
    // 0x80032D44: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x80032D48: b           L_80032D68
    // 0x80032D4C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80032D68;
    // 0x80032D4C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80032D50:
    // 0x80032D50: b           L_80032D68
    // 0x80032D54: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_80032D68;
    // 0x80032D54: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_80032D58:
    // 0x80032D58: b           L_80032D68
    // 0x80032D5C: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
        goto L_80032D68;
    // 0x80032D5C: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
L_80032D60:
    // 0x80032D60: b           L_80032D68
    // 0x80032D64: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
        goto L_80032D68;
    // 0x80032D64: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
L_80032D68:
    // 0x80032D68: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80032D6C: lwc1        $f4, 0xC($fp)
    ctx->f4.u32l = MEM_W(ctx->r30, 0XC);
    // 0x80032D70: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80032D74: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80032D78: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80032D7C: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x80032D80: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80032D84: addiu       $s1, $s1, -0x3128
    ctx->r17 = ADD32(ctx->r17, -0X3128);
    // 0x80032D88: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80032D8C: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80032D90: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80032D94: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80032D98: sh          $t8, 0x82($sp)
    MEM_H(0X82, ctx->r29) = ctx->r24;
    // 0x80032D9C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80032DA0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80032DA4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80032DA8: lwc1        $f8, 0x10($fp)
    ctx->f8.u32l = MEM_W(ctx->r30, 0X10);
    // 0x80032DAC: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80032DB0: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80032DB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80032DB8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80032DBC: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x80032DC0: addiu       $s7, $s7, -0x25B4
    ctx->r23 = ADD32(ctx->r23, -0X25B4);
    // 0x80032DC4: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80032DC8: sh          $t2, 0x80($sp)
    MEM_H(0X80, ctx->r29) = ctx->r10;
    // 0x80032DCC: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80032DD0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80032DD4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80032DD8: lwc1        $f16, 0x14($fp)
    ctx->f16.u32l = MEM_W(ctx->r30, 0X14);
    // 0x80032DDC: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x80032DE0: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80032DE4: lw          $t5, -0x3134($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X3134);
    // 0x80032DE8: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x80032DEC: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80032DF0: blez        $t5, L_800332D0
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80032DF4: sh          $t4, 0x7E($sp)
        MEM_H(0X7E, ctx->r29) = ctx->r12;
            goto L_800332D0;
    }
    // 0x80032DF4: sh          $t4, 0x7E($sp)
    MEM_H(0X7E, ctx->r29) = ctx->r12;
    // 0x80032DF8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80032DFC: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x80032E00: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80032E04: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x80032E08: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80032E0C: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x80032E10: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80032E14: addiu       $s3, $s3, -0x3130
    ctx->r19 = ADD32(ctx->r19, -0X3130);
    // 0x80032E18: addiu       $s4, $s4, -0x25B8
    ctx->r20 = ADD32(ctx->r20, -0X25B8);
    // 0x80032E1C: addiu       $s6, $s6, -0x25BC
    ctx->r22 = ADD32(ctx->r22, -0X25BC);
    // 0x80032E20: sw          $v1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r3;
    // 0x80032E24: addiu       $s2, $zero, 0x14
    ctx->r18 = ADD32(0, 0X14);
L_80032E28:
    // 0x80032E28: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80032E2C: lw          $t6, -0x3140($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3140);
    // 0x80032E30: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x80032E34: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x80032E38: lw          $s0, 0x0($t7)
    ctx->r16 = MEM_W(ctx->r15, 0X0);
    // 0x80032E3C: nop

    // 0x80032E40: lbu         $t8, 0x2($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X2);
    // 0x80032E44: nop

    // 0x80032E48: and         $t2, $t8, $t9
    ctx->r10 = ctx->r24 & ctx->r25;
    // 0x80032E4C: beq         $t2, $zero, L_800332B8
    if (ctx->r10 == 0) {
        // 0x80032E50: nop
    
            goto L_800332B8;
    }
    // 0x80032E50: nop

    // 0x80032E54: lbu         $t3, 0x4($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X4);
    // 0x80032E58: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80032E5C: bne         $t3, $at, L_800332B8
    if (ctx->r11 != ctx->r1) {
        // 0x80032E60: nop
    
            goto L_800332B8;
    }
    // 0x80032E60: nop

    // 0x80032E64: lh          $t4, 0x82($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X82);
    // 0x80032E68: lh          $t5, 0x50($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X50);
    // 0x80032E6C: nop

    // 0x80032E70: slt         $at, $t4, $t5
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80032E74: bne         $at, $zero, L_800332B8
    if (ctx->r1 != 0) {
        // 0x80032E78: nop
    
            goto L_800332B8;
    }
    // 0x80032E78: nop

    // 0x80032E7C: lh          $t6, 0x56($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X56);
    // 0x80032E80: lh          $t7, 0x80($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X80);
    // 0x80032E84: slt         $at, $t6, $t4
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80032E88: bne         $at, $zero, L_800332B8
    if (ctx->r1 != 0) {
        // 0x80032E8C: nop
    
            goto L_800332B8;
    }
    // 0x80032E8C: nop

    // 0x80032E90: lh          $t8, 0x52($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X52);
    // 0x80032E94: nop

    // 0x80032E98: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80032E9C: bne         $at, $zero, L_800332B8
    if (ctx->r1 != 0) {
        // 0x80032EA0: nop
    
            goto L_800332B8;
    }
    // 0x80032EA0: nop

    // 0x80032EA4: lh          $t9, 0x58($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X58);
    // 0x80032EA8: lh          $t2, 0x7E($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X7E);
    // 0x80032EAC: slt         $at, $t9, $t7
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80032EB0: bne         $at, $zero, L_800332B8
    if (ctx->r1 != 0) {
        // 0x80032EB4: nop
    
            goto L_800332B8;
    }
    // 0x80032EB4: nop

    // 0x80032EB8: lh          $t3, 0x54($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X54);
    // 0x80032EBC: nop

    // 0x80032EC0: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80032EC4: bne         $at, $zero, L_800332B8
    if (ctx->r1 != 0) {
        // 0x80032EC8: nop
    
            goto L_800332B8;
    }
    // 0x80032EC8: nop

    // 0x80032ECC: lh          $t5, 0x5A($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X5A);
    // 0x80032ED0: nop

    // 0x80032ED4: slt         $at, $t5, $t2
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80032ED8: bne         $at, $zero, L_800332B8
    if (ctx->r1 != 0) {
        // 0x80032EDC: nop
    
            goto L_800332B8;
    }
    // 0x80032EDC: nop

    // 0x80032EE0: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x80032EE4: nop

    // 0x80032EE8: bne         $t6, $zero, L_80032FC0
    if (ctx->r14 != 0) {
        // 0x80032EEC: nop
    
            goto L_80032FC0;
    }
    // 0x80032EEC: nop

    // 0x80032EF0: lw          $t4, 0x28($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X28);
    // 0x80032EF4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80032EF8: slt         $at, $t4, $at
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80032EFC: bne         $at, $zero, L_800332B8
    if (ctx->r1 != 0) {
        // 0x80032F00: nop
    
            goto L_800332B8;
    }
    // 0x80032F00: nop

    // 0x80032F04: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80032F08: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x80032F0C: multu       $t9, $s2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80032F10: mflo        $t7
    ctx->r15 = lo;
    // 0x80032F14: addu        $t3, $t8, $t7
    ctx->r11 = ADD32(ctx->r24, ctx->r15);
    // 0x80032F18: sw          $s0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r16;
    // 0x80032F1C: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80032F20: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x80032F24: multu       $t4, $s2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80032F28: lw          $t5, 0x1C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1C);
    // 0x80032F2C: nop

    // 0x80032F30: sra         $t2, $t5, 16
    ctx->r10 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80032F34: mflo        $t9
    ctx->r25 = lo;
    // 0x80032F38: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x80032F3C: sw          $t2, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r10;
    // 0x80032F40: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80032F44: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x80032F48: multu       $t4, $s2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80032F4C: lw          $t7, 0x20($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X20);
    // 0x80032F50: nop

    // 0x80032F54: sra         $t3, $t7, 16
    ctx->r11 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80032F58: mflo        $t6
    ctx->r14 = lo;
    // 0x80032F5C: addu        $t9, $t5, $t6
    ctx->r25 = ADD32(ctx->r13, ctx->r14);
    // 0x80032F60: sw          $t3, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r11;
    // 0x80032F64: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80032F68: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x80032F6C: multu       $t4, $s2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80032F70: lw          $t2, 0x24($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X24);
    // 0x80032F74: nop

    // 0x80032F78: sra         $t8, $t2, 16
    ctx->r24 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80032F7C: mflo        $t5
    ctx->r13 = lo;
    // 0x80032F80: addu        $t6, $t7, $t5
    ctx->r14 = ADD32(ctx->r15, ctx->r13);
    // 0x80032F84: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x80032F88: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80032F8C: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x80032F90: multu       $t4, $s2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80032F94: lw          $t3, 0x28($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X28);
    // 0x80032F98: nop

    // 0x80032F9C: sra         $t9, $t3, 16
    ctx->r25 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80032FA0: mflo        $t7
    ctx->r15 = lo;
    // 0x80032FA4: addu        $t5, $t2, $t7
    ctx->r13 = ADD32(ctx->r10, ctx->r15);
    // 0x80032FA8: sw          $t9, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->r25;
    // 0x80032FAC: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80032FB0: nop

    // 0x80032FB4: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x80032FB8: b           L_800332B8
    // 0x80032FBC: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
        goto L_800332B8;
    // 0x80032FBC: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
L_80032FC0:
    // 0x80032FC0: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80032FC4: lwc1        $f6, 0xC($fp)
    ctx->f6.u32l = MEM_W(ctx->r30, 0XC);
    // 0x80032FC8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80032FCC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80032FD0: swc1        $f8, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f8.u32l;
    // 0x80032FD4: lwc1        $f16, 0x10($fp)
    ctx->f16.u32l = MEM_W(ctx->r30, 0X10);
    // 0x80032FD8: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80032FDC: nop

    // 0x80032FE0: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80032FE4: swc1        $f18, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f18.u32l;
    // 0x80032FE8: lwc1        $f6, 0x14($fp)
    ctx->f6.u32l = MEM_W(ctx->r30, 0X14);
    // 0x80032FEC: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80032FF0: nop

    // 0x80032FF4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80032FF8: swc1        $f8, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->f8.u32l;
    // 0x80032FFC: lbu         $t3, 0x0($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X0);
    // 0x80033000: nop

    // 0x80033004: bne         $t3, $at, L_80033010
    if (ctx->r11 != ctx->r1) {
        // 0x80033008: nop
    
            goto L_80033010;
    }
    // 0x80033008: nop

    // 0x8003300C: swc1        $f22, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f22.u32l;
L_80033010:
    // 0x80033010: lwc1        $f0, 0x0($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X0);
    // 0x80033014: lwc1        $f2, 0x0($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X0);
    // 0x80033018: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8003301C: lwc1        $f12, 0x0($s7)
    ctx->f12.u32l = MEM_W(ctx->r23, 0X0);
    // 0x80033020: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80033024: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80033028: nop

    // 0x8003302C: mul.s       $f4, $f12, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80033030: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80033034: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80033038: swc1        $f6, -0x25C0($at)
    MEM_W(-0X25C0, ctx->r1) = ctx->f6.u32l;
    // 0x8003303C: lwc1        $f8, 0x68($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X68);
    // 0x80033040: nop

    // 0x80033044: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80033048: nop

    // 0x8003304C: bc1f        L_800332B8
    if (!c1cs) {
        // 0x80033050: nop
    
            goto L_800332B8;
    }
    // 0x80033050: nop

    // 0x80033054: lbu         $t4, 0x1($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X1);
    // 0x80033058: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003305C: bne         $t4, $at, L_80033078
    if (ctx->r12 != ctx->r1) {
        // 0x80033060: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80033078;
    }
    // 0x80033060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80033064: jal         0x80033C48
    // 0x80033068: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    light_direction_calc(rdram, ctx);
        goto after_0;
    // 0x80033068: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    after_0:
    // 0x8003306C: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    // 0x80033070: b           L_8003307C
    // 0x80033074: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
        goto L_8003307C;
    // 0x80033074: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_80033078:
    // 0x80033078: mov.s       $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    ctx->f20.fl = ctx->f24.fl;
L_8003307C:
    // 0x8003307C: c.lt.s      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl < ctx->f20.fl;
    // 0x80033080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80033084: bc1f        L_800332B8
    if (!c1cs) {
        // 0x80033088: nop
    
            goto L_800332B8;
    }
    // 0x80033088: nop

    // 0x8003308C: jal         0x80033A54
    // 0x80033090: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    light_distance_calc(rdram, ctx);
        goto after_1;
    // 0x80033090: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    after_1:
    // 0x80033094: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80033098: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    // 0x8003309C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800330A0: addiu       $t0, $t0, -0x312C
    ctx->r8 = ADD32(ctx->r8, -0X312C);
    // 0x800330A4: c.lt.s      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl < ctx->f20.fl;
    // 0x800330A8: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x800330AC: bc1f        L_800332B8
    if (!c1cs) {
        // 0x800330B0: nop
    
            goto L_800332B8;
    }
    // 0x800330B0: nop

    // 0x800330B4: lw          $t2, 0x40($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X40);
    // 0x800330B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800330BC: lbu         $t7, 0x71($t2)
    ctx->r15 = MEM_BU(ctx->r10, 0X71);
    // 0x800330C0: nop

    // 0x800330C4: beq         $t7, $zero, L_80033194
    if (ctx->r15 == 0) {
        // 0x800330C8: nop
    
            goto L_80033194;
    }
    // 0x800330C8: nop

    // 0x800330CC: lwc1        $f12, -0x25C0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X25C0);
    // 0x800330D0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800330D4: c.lt.s      $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f22.fl < ctx->f12.fl;
    // 0x800330D8: nop

    // 0x800330DC: bc1f        L_80033130
    if (!c1cs) {
        // 0x800330E0: nop
    
            goto L_80033130;
    }
    // 0x800330E0: nop

    // 0x800330E4: jal         0x800CA030
    // 0x800330E8: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x800330E8: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    after_2:
    // 0x800330EC: nop

    // 0x800330F0: div.s       $f2, $f24, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f24.fl, ctx->f0.fl);
    // 0x800330F4: lwc1        $f10, 0x0($s6)
    ctx->f10.u32l = MEM_W(ctx->r22, 0X0);
    // 0x800330F8: lwc1        $f18, 0x0($s4)
    ctx->f18.u32l = MEM_W(ctx->r20, 0X0);
    // 0x800330FC: lwc1        $f6, 0x0($s7)
    ctx->f6.u32l = MEM_W(ctx->r23, 0X0);
    // 0x80033100: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    // 0x80033104: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80033108: addiu       $t0, $t0, -0x312C
    ctx->r8 = ADD32(ctx->r8, -0X312C);
    // 0x8003310C: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x80033110: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80033114: nop

    // 0x80033118: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8003311C: swc1        $f16, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f16.u32l;
    // 0x80033120: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80033124: swc1        $f4, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f4.u32l;
    // 0x80033128: b           L_80033140
    // 0x8003312C: swc1        $f8, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->f8.u32l;
        goto L_80033140;
    // 0x8003312C: swc1        $f8, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->f8.u32l;
L_80033130:
    // 0x80033130: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80033134: swc1        $f26, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f26.u32l;
    // 0x80033138: swc1        $f26, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f26.u32l;
    // 0x8003313C: swc1        $f10, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->f10.u32l;
L_80033140:
    // 0x80033140: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80033144: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x80033148: multu       $t5, $t1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003314C: lwc1        $f16, 0x0($s6)
    ctx->f16.u32l = MEM_W(ctx->r22, 0X0);
    // 0x80033150: mflo        $t8
    ctx->r24 = lo;
    // 0x80033154: addu        $t6, $t9, $t8
    ctx->r14 = ADD32(ctx->r25, ctx->r24);
    // 0x80033158: swc1        $f16, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f16.u32l;
    // 0x8003315C: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80033160: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x80033164: multu       $t4, $t1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80033168: lwc1        $f18, 0x0($s4)
    ctx->f18.u32l = MEM_W(ctx->r20, 0X0);
    // 0x8003316C: mflo        $t2
    ctx->r10 = lo;
    // 0x80033170: addu        $t7, $t3, $t2
    ctx->r15 = ADD32(ctx->r11, ctx->r10);
    // 0x80033174: swc1        $f18, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f18.u32l;
    // 0x80033178: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8003317C: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x80033180: multu       $t9, $t1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80033184: lwc1        $f4, 0x0($s7)
    ctx->f4.u32l = MEM_W(ctx->r23, 0X0);
    // 0x80033188: mflo        $t8
    ctx->r24 = lo;
    // 0x8003318C: addu        $t6, $t5, $t8
    ctx->r14 = ADD32(ctx->r13, ctx->r24);
    // 0x80033190: swc1        $f4, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f4.u32l;
L_80033194:
    // 0x80033194: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80033198: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x8003319C: multu       $t3, $s2
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800331A0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800331A4: mflo        $t2
    ctx->r10 = lo;
    // 0x800331A8: addu        $t7, $t4, $t2
    ctx->r15 = ADD32(ctx->r12, ctx->r10);
    // 0x800331AC: sw          $s0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r16;
    // 0x800331B0: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800331B4: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x800331B8: multu       $t6, $s2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800331BC: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
    // 0x800331C0: nop

    // 0x800331C4: sra         $t5, $t9, 16
    ctx->r13 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800331C8: mflo        $t3
    ctx->r11 = lo;
    // 0x800331CC: addu        $t4, $t8, $t3
    ctx->r12 = ADD32(ctx->r24, ctx->r11);
    // 0x800331D0: sw          $t5, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r13;
    // 0x800331D4: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800331D8: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x800331DC: multu       $t6, $s2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800331E0: lw          $t2, 0x20($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X20);
    // 0x800331E4: nop

    // 0x800331E8: sra         $t7, $t2, 16
    ctx->r15 = S32(SIGNED(ctx->r10) >> 16);
    // 0x800331EC: mflo        $t8
    ctx->r24 = lo;
    // 0x800331F0: addu        $t3, $t9, $t8
    ctx->r11 = ADD32(ctx->r25, ctx->r24);
    // 0x800331F4: sw          $t7, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r15;
    // 0x800331F8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800331FC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80033200: multu       $t6, $s2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80033204: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80033208: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8003320C: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x80033210: cvt.w.s     $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    ctx->f6.u32l = CVT_W_S(ctx->f20.fl);
    // 0x80033214: lw          $t5, 0x24($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X24);
    // 0x80033218: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8003321C: sra         $t4, $t5, 16
    ctx->r12 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80033220: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x80033224: mflo        $t9
    ctx->r25 = lo;
    // 0x80033228: addu        $t8, $t2, $t9
    ctx->r24 = ADD32(ctx->r10, ctx->r25);
    // 0x8003322C: beq         $t3, $zero, L_80033278
    if (ctx->r11 == 0) {
        // 0x80033230: sw          $t4, 0xC($t8)
        MEM_W(0XC, ctx->r24) = ctx->r12;
            goto L_80033278;
    }
    // 0x80033230: sw          $t4, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r12;
    // 0x80033234: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80033238: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8003323C: sub.s       $f6, $f20, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f20.fl - ctx->f6.fl;
    // 0x80033240: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80033244: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80033248: nop

    // 0x8003324C: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80033250: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80033254: nop

    // 0x80033258: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x8003325C: bne         $t3, $zero, L_80033270
    if (ctx->r11 != 0) {
        // 0x80033260: nop
    
            goto L_80033270;
    }
    // 0x80033260: nop

    // 0x80033264: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x80033268: b           L_80033288
    // 0x8003326C: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_80033288;
    // 0x8003326C: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_80033270:
    // 0x80033270: b           L_80033288
    // 0x80033274: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_80033288;
    // 0x80033274: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
L_80033278:
    // 0x80033278: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x8003327C: nop

    // 0x80033280: bltz        $t3, L_80033270
    if (SIGNED(ctx->r11) < 0) {
        // 0x80033284: nop
    
            goto L_80033270;
    }
    // 0x80033284: nop

L_80033288:
    // 0x80033288: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x8003328C: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x80033290: multu       $t2, $s2
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80033294: andi        $t5, $t3, 0xFF
    ctx->r13 = ctx->r11 & 0XFF;
    // 0x80033298: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8003329C: mflo        $t9
    ctx->r25 = lo;
    // 0x800332A0: addu        $t4, $t6, $t9
    ctx->r12 = ADD32(ctx->r14, ctx->r25);
    // 0x800332A4: sw          $t5, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->r13;
    // 0x800332A8: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800332AC: nop

    // 0x800332B0: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x800332B4: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
L_800332B8:
    // 0x800332B8: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800332BC: lw          $t3, -0x3134($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X3134);
    // 0x800332C0: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800332C4: slt         $at, $s5, $t3
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800332C8: bne         $at, $zero, L_80032E28
    if (ctx->r1 != 0) {
        // 0x800332CC: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80032E28;
    }
    // 0x800332CC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800332D0:
    // 0x800332D0: lw          $t2, 0x40($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X40);
    // 0x800332D4: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800332D8: lbu         $t6, 0x71($t2)
    ctx->r14 = MEM_BU(ctx->r10, 0X71);
    // 0x800332DC: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x800332E0: addiu       $s3, $s3, -0x3130
    ctx->r19 = ADD32(ctx->r19, -0X3130);
    // 0x800332E4: addiu       $t0, $t0, -0x312C
    ctx->r8 = ADD32(ctx->r8, -0X312C);
    // 0x800332E8: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x800332EC: beq         $t6, $zero, L_80033734
    if (ctx->r14 == 0) {
        // 0x800332F0: addiu       $s2, $zero, 0x14
        ctx->r18 = ADD32(0, 0X14);
            goto L_80033734;
    }
    // 0x800332F0: addiu       $s2, $zero, 0x14
    ctx->r18 = ADD32(0, 0X14);
    // 0x800332F4: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800332F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800332FC: bne         $a3, $zero, L_8003331C
    if (ctx->r7 != 0) {
        // 0x80033300: nop
    
            goto L_8003331C;
    }
    // 0x80033300: nop

    // 0x80033304: lw          $t9, 0x54($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X54);
    // 0x80033308: nop

    // 0x8003330C: sb          $zero, 0x7($t9)
    MEM_B(0X7, ctx->r25) = 0;
    // 0x80033310: lw          $t5, 0x54($fp)
    ctx->r13 = MEM_W(ctx->r30, 0X54);
    // 0x80033314: b           L_800337D4
    // 0x80033318: sb          $zero, 0x11($t5)
    MEM_B(0X11, ctx->r13) = 0;
        goto L_800337D4;
    // 0x80033318: sb          $zero, 0x11($t5)
    MEM_B(0X11, ctx->r13) = 0;
L_8003331C:
    // 0x8003331C: bne         $a3, $at, L_8003342C
    if (ctx->r7 != ctx->r1) {
        // 0x80033320: nop
    
            goto L_8003342C;
    }
    // 0x80033320: nop

    // 0x80033324: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x80033328: lw          $t7, 0x54($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X54);
    // 0x8003332C: lw          $t8, 0x4($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X4);
    // 0x80033330: lui         $at, 0x4600
    ctx->r1 = S32(0X4600 << 16);
    // 0x80033334: sb          $t8, 0x4($t7)
    MEM_B(0X4, ctx->r15) = ctx->r24;
    // 0x80033338: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    // 0x8003333C: lw          $t6, 0x54($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X54);
    // 0x80033340: lw          $t2, 0x8($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X8);
    // 0x80033344: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80033348: sb          $t2, 0x5($t6)
    MEM_B(0X5, ctx->r14) = ctx->r10;
    // 0x8003334C: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x80033350: lw          $t4, 0x54($fp)
    ctx->r12 = MEM_W(ctx->r30, 0X54);
    // 0x80033354: lw          $t5, 0xC($t9)
    ctx->r13 = MEM_W(ctx->r25, 0XC);
    // 0x80033358: nop

    // 0x8003335C: sb          $t5, 0x6($t4)
    MEM_B(0X6, ctx->r12) = ctx->r13;
    // 0x80033360: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x80033364: lw          $t3, 0x54($fp)
    ctx->r11 = MEM_W(ctx->r30, 0X54);
    // 0x80033368: lw          $t7, 0x10($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X10);
    // 0x8003336C: nop

    // 0x80033370: sb          $t7, 0x7($t3)
    MEM_B(0X7, ctx->r11) = ctx->r15;
    // 0x80033374: lw          $t2, 0x54($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X54);
    // 0x80033378: nop

    // 0x8003337C: sb          $zero, 0x11($t2)
    MEM_B(0X11, ctx->r10) = 0;
    // 0x80033380: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x80033384: lw          $t4, 0x54($fp)
    ctx->r12 = MEM_W(ctx->r30, 0X54);
    // 0x80033388: lwc1        $f8, 0x0($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8003338C: nop

    // 0x80033390: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80033394: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80033398: nop

    // 0x8003339C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800333A0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800333A4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800333A8: nop

    // 0x800333AC: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800333B0: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    // 0x800333B4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800333B8: sh          $t5, 0x8($t4)
    MEM_H(0X8, ctx->r12) = ctx->r13;
    // 0x800333BC: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800333C0: lw          $t2, 0x54($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X54);
    // 0x800333C4: lwc1        $f18, 0x4($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X4);
    // 0x800333C8: nop

    // 0x800333CC: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800333D0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800333D4: nop

    // 0x800333D8: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800333DC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800333E0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800333E4: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800333E8: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800333EC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800333F0: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x800333F4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800333F8: sh          $t3, 0xA($t2)
    MEM_H(0XA, ctx->r10) = ctx->r11;
    // 0x800333FC: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x80033400: lw          $t4, 0x54($fp)
    ctx->r12 = MEM_W(ctx->r30, 0X54);
    // 0x80033404: lwc1        $f8, 0x8($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X8);
    // 0x80033408: nop

    // 0x8003340C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80033410: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80033414: nop

    // 0x80033418: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8003341C: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    // 0x80033420: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80033424: b           L_800337D4
    // 0x80033428: sh          $t5, 0xC($t4)
    MEM_H(0XC, ctx->r12) = ctx->r13;
        goto L_800337D4;
    // 0x80033428: sh          $t5, 0xC($t4)
    MEM_H(0XC, ctx->r12) = ctx->r13;
L_8003342C:
    // 0x8003342C: lw          $a2, 0x0($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X0);
    // 0x80033430: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80033434: lw          $t8, 0x24($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X24);
    // 0x80033438: lw          $t7, 0x10($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X10);
    // 0x8003343C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80033440: slt         $at, $t8, $t7
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80033444: beq         $at, $zero, L_80033458
    if (ctx->r1 == 0) {
        // 0x80033448: addiu       $v1, $a2, 0x28
        ctx->r3 = ADD32(ctx->r6, 0X28);
            goto L_80033458;
    }
    // 0x80033448: addiu       $v1, $a2, 0x28
    ctx->r3 = ADD32(ctx->r6, 0X28);
    // 0x8003344C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80033450: b           L_80033458
    // 0x80033454: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80033458;
    // 0x80033454: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80033458:
    // 0x80033458: slti        $at, $a3, 0x3
    ctx->r1 = SIGNED(ctx->r7) < 0X3 ? 1 : 0;
    // 0x8003345C: bne         $at, $zero, L_800334E0
    if (ctx->r1 != 0) {
        // 0x80033460: addiu       $s5, $zero, 0x2
        ctx->r21 = ADD32(0, 0X2);
            goto L_800334E0;
    }
    // 0x80033460: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
L_80033464:
    // 0x80033464: multu       $a1, $s2
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80033468: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
    // 0x8003346C: mflo        $t3
    ctx->r11 = lo;
    // 0x80033470: addu        $t2, $a2, $t3
    ctx->r10 = ADD32(ctx->r6, ctx->r11);
    // 0x80033474: lw          $t6, 0x10($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X10);
    // 0x80033478: nop

    // 0x8003347C: slt         $at, $t6, $v0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80033480: beq         $at, $zero, L_800334D0
    if (ctx->r1 == 0) {
        // 0x80033484: nop
    
            goto L_800334D0;
    }
    // 0x80033484: nop

    // 0x80033488: multu       $a0, $s2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003348C: sll         $a1, $s5, 16
    ctx->r5 = S32(ctx->r21 << 16);
    // 0x80033490: sra         $t3, $a1, 16
    ctx->r11 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80033494: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x80033498: mflo        $t9
    ctx->r25 = lo;
    // 0x8003349C: addu        $t5, $a2, $t9
    ctx->r13 = ADD32(ctx->r6, ctx->r25);
    // 0x800334A0: lw          $t4, 0x10($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X10);
    // 0x800334A4: nop

    // 0x800334A8: slt         $at, $t4, $v0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800334AC: beq         $at, $zero, L_800334D0
    if (ctx->r1 == 0) {
        // 0x800334B0: nop
    
            goto L_800334D0;
    }
    // 0x800334B0: nop

    // 0x800334B4: sll         $a1, $a0, 16
    ctx->r5 = S32(ctx->r4 << 16);
    // 0x800334B8: sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21 << 16);
    // 0x800334BC: sra         $t8, $a1, 16
    ctx->r24 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800334C0: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800334C4: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x800334C8: b           L_800334D0
    // 0x800334CC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
        goto L_800334D0;
    // 0x800334CC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
L_800334D0:
    // 0x800334D0: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800334D4: slt         $at, $s5, $a3
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800334D8: bne         $at, $zero, L_80033464
    if (ctx->r1 != 0) {
        // 0x800334DC: addiu       $v1, $v1, 0x14
        ctx->r3 = ADD32(ctx->r3, 0X14);
            goto L_80033464;
    }
    // 0x800334DC: addiu       $v1, $v1, 0x14
    ctx->r3 = ADD32(ctx->r3, 0X14);
L_800334E0:
    // 0x800334E0: multu       $a0, $s2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800334E4: lw          $t9, 0x54($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X54);
    // 0x800334E8: lui         $at, 0x4600
    ctx->r1 = S32(0X4600 << 16);
    // 0x800334EC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800334F0: mflo        $v0
    ctx->r2 = lo;
    // 0x800334F4: addu        $t2, $a2, $v0
    ctx->r10 = ADD32(ctx->r6, ctx->r2);
    // 0x800334F8: lw          $t6, 0x4($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X4);
    // 0x800334FC: multu       $a0, $t1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80033500: sb          $t6, 0x4($t9)
    MEM_B(0X4, ctx->r25) = ctx->r14;
    // 0x80033504: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x80033508: lw          $t7, 0x54($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X54);
    // 0x8003350C: addu        $t4, $t5, $v0
    ctx->r12 = ADD32(ctx->r13, ctx->r2);
    // 0x80033510: lw          $t8, 0x8($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X8);
    // 0x80033514: nop

    // 0x80033518: sb          $t8, 0x5($t7)
    MEM_B(0X5, ctx->r15) = ctx->r24;
    // 0x8003351C: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    // 0x80033520: lw          $t9, 0x54($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X54);
    // 0x80033524: addu        $t2, $t3, $v0
    ctx->r10 = ADD32(ctx->r11, ctx->r2);
    // 0x80033528: lw          $t6, 0xC($t2)
    ctx->r14 = MEM_W(ctx->r10, 0XC);
    // 0x8003352C: mflo        $v1
    ctx->r3 = lo;
    // 0x80033530: sb          $t6, 0x6($t9)
    MEM_B(0X6, ctx->r25) = ctx->r14;
    // 0x80033534: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x80033538: lw          $t7, 0x54($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X54);
    // 0x8003353C: addu        $t4, $t5, $v0
    ctx->r12 = ADD32(ctx->r13, ctx->r2);
    // 0x80033540: lw          $t8, 0x10($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X10);
    // 0x80033544: multu       $a1, $s2
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80033548: sb          $t8, 0x7($t7)
    MEM_B(0X7, ctx->r15) = ctx->r24;
    // 0x8003354C: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x80033550: lw          $t5, 0x54($fp)
    ctx->r13 = MEM_W(ctx->r30, 0X54);
    // 0x80033554: addu        $t2, $t3, $v1
    ctx->r10 = ADD32(ctx->r11, ctx->r3);
    // 0x80033558: lwc1        $f18, 0x0($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X0);
    // 0x8003355C: nop

    // 0x80033560: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80033564: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80033568: mflo        $a3
    ctx->r7 = lo;
    // 0x8003356C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80033570: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80033574: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80033578: multu       $a1, $t1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003357C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80033580: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80033584: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80033588: sh          $t9, 0x8($t5)
    MEM_H(0X8, ctx->r13) = ctx->r25;
    // 0x8003358C: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x80033590: lw          $t2, 0x54($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X54);
    // 0x80033594: addu        $t8, $t4, $v1
    ctx->r24 = ADD32(ctx->r12, ctx->r3);
    // 0x80033598: lwc1        $f8, 0x4($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X4);
    // 0x8003359C: nop

    // 0x800335A0: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800335A4: mflo        $v0
    ctx->r2 = lo;
    // 0x800335A8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800335AC: nop

    // 0x800335B0: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800335B4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800335B8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800335BC: nop

    // 0x800335C0: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800335C4: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x800335C8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800335CC: sh          $t3, 0xA($t2)
    MEM_H(0XA, ctx->r10) = ctx->r11;
    // 0x800335D0: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800335D4: lw          $t8, 0x54($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X54);
    // 0x800335D8: addu        $t9, $t6, $v1
    ctx->r25 = ADD32(ctx->r14, ctx->r3);
    // 0x800335DC: lwc1        $f18, 0x8($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X8);
    // 0x800335E0: nop

    // 0x800335E4: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800335E8: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800335EC: nop

    // 0x800335F0: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800335F4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800335F8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800335FC: nop

    // 0x80033600: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80033604: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x80033608: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8003360C: sh          $t4, 0xC($t8)
    MEM_H(0XC, ctx->r24) = ctx->r12;
    // 0x80033610: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x80033614: lw          $t6, 0x54($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X54);
    // 0x80033618: addu        $t3, $t7, $a3
    ctx->r11 = ADD32(ctx->r15, ctx->r7);
    // 0x8003361C: lw          $t2, 0x4($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X4);
    // 0x80033620: nop

    // 0x80033624: sb          $t2, 0xE($t6)
    MEM_B(0XE, ctx->r14) = ctx->r10;
    // 0x80033628: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x8003362C: lw          $t8, 0x54($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X54);
    // 0x80033630: addu        $t5, $t9, $a3
    ctx->r13 = ADD32(ctx->r25, ctx->r7);
    // 0x80033634: lw          $t4, 0x8($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X8);
    // 0x80033638: nop

    // 0x8003363C: sb          $t4, 0xF($t8)
    MEM_B(0XF, ctx->r24) = ctx->r12;
    // 0x80033640: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x80033644: lw          $t6, 0x54($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X54);
    // 0x80033648: addu        $t3, $t7, $a3
    ctx->r11 = ADD32(ctx->r15, ctx->r7);
    // 0x8003364C: lw          $t2, 0xC($t3)
    ctx->r10 = MEM_W(ctx->r11, 0XC);
    // 0x80033650: nop

    // 0x80033654: sb          $t2, 0x10($t6)
    MEM_B(0X10, ctx->r14) = ctx->r10;
    // 0x80033658: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x8003365C: lw          $t8, 0x54($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X54);
    // 0x80033660: addu        $t5, $t9, $a3
    ctx->r13 = ADD32(ctx->r25, ctx->r7);
    // 0x80033664: lw          $t4, 0x10($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X10);
    // 0x80033668: nop

    // 0x8003366C: sb          $t4, 0x11($t8)
    MEM_B(0X11, ctx->r24) = ctx->r12;
    // 0x80033670: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x80033674: lw          $t9, 0x54($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X54);
    // 0x80033678: addu        $t3, $t7, $v0
    ctx->r11 = ADD32(ctx->r15, ctx->r2);
    // 0x8003367C: lwc1        $f8, 0x0($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80033680: nop

    // 0x80033684: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80033688: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8003368C: nop

    // 0x80033690: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x80033694: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80033698: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003369C: nop

    // 0x800336A0: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800336A4: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    // 0x800336A8: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800336AC: sh          $t6, 0x12($t9)
    MEM_H(0X12, ctx->r25) = ctx->r14;
    // 0x800336B0: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x800336B4: lw          $t3, 0x54($fp)
    ctx->r11 = MEM_W(ctx->r30, 0X54);
    // 0x800336B8: addu        $t4, $t5, $v0
    ctx->r12 = ADD32(ctx->r13, ctx->r2);
    // 0x800336BC: lwc1        $f18, 0x4($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X4);
    // 0x800336C0: nop

    // 0x800336C4: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800336C8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800336CC: nop

    // 0x800336D0: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800336D4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800336D8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800336DC: nop

    // 0x800336E0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800336E4: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800336E8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800336EC: sh          $t7, 0x14($t3)
    MEM_H(0X14, ctx->r11) = ctx->r15;
    // 0x800336F0: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x800336F4: lw          $t4, 0x54($fp)
    ctx->r12 = MEM_W(ctx->r30, 0X54);
    // 0x800336F8: addu        $t6, $t2, $v0
    ctx->r14 = ADD32(ctx->r10, ctx->r2);
    // 0x800336FC: lwc1        $f8, 0x8($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X8);
    // 0x80033700: nop

    // 0x80033704: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80033708: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8003370C: nop

    // 0x80033710: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80033714: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80033718: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003371C: nop

    // 0x80033720: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80033724: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    // 0x80033728: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8003372C: b           L_800337D4
    // 0x80033730: sh          $t5, 0x16($t4)
    MEM_H(0X16, ctx->r12) = ctx->r13;
        goto L_800337D4;
    // 0x80033730: sh          $t5, 0x16($t4)
    MEM_H(0X16, ctx->r12) = ctx->r13;
L_80033734:
    // 0x80033734: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80033738: nop

    // 0x8003373C: blez        $a3, L_800337A4
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80033740: slti        $at, $a3, 0x2
        ctx->r1 = SIGNED(ctx->r7) < 0X2 ? 1 : 0;
            goto L_800337A4;
    }
    // 0x80033740: slti        $at, $a3, 0x2
    ctx->r1 = SIGNED(ctx->r7) < 0X2 ? 1 : 0;
    // 0x80033744: bne         $at, $zero, L_80033754
    if (ctx->r1 != 0) {
        // 0x80033748: nop
    
            goto L_80033754;
    }
    // 0x80033748: nop

    // 0x8003374C: jal         0x80033824
    // 0x80033750: nop

    light_update_ambience(rdram, ctx);
        goto after_3;
    // 0x80033750: nop

    after_3:
L_80033754:
    // 0x80033754: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x80033758: lw          $t3, 0x54($fp)
    ctx->r11 = MEM_W(ctx->r30, 0X54);
    // 0x8003375C: lw          $t7, 0x4($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X4);
    // 0x80033760: nop

    // 0x80033764: sb          $t7, 0x4($t3)
    MEM_B(0X4, ctx->r11) = ctx->r15;
    // 0x80033768: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x8003376C: lw          $t9, 0x54($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X54);
    // 0x80033770: lw          $t6, 0x8($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X8);
    // 0x80033774: nop

    // 0x80033778: sb          $t6, 0x5($t9)
    MEM_B(0X5, ctx->r25) = ctx->r14;
    // 0x8003377C: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x80033780: lw          $t8, 0x54($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X54);
    // 0x80033784: lw          $t4, 0xC($t5)
    ctx->r12 = MEM_W(ctx->r13, 0XC);
    // 0x80033788: nop

    // 0x8003378C: sb          $t4, 0x6($t8)
    MEM_B(0X6, ctx->r24) = ctx->r12;
    // 0x80033790: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x80033794: lw          $t2, 0x54($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X54);
    // 0x80033798: lw          $t3, 0x10($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X10);
    // 0x8003379C: b           L_800337D4
    // 0x800337A0: sb          $t3, 0x7($t2)
    MEM_B(0X7, ctx->r10) = ctx->r11;
        goto L_800337D4;
    // 0x800337A0: sb          $t3, 0x7($t2)
    MEM_B(0X7, ctx->r10) = ctx->r11;
L_800337A4:
    // 0x800337A4: lw          $t6, 0x54($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X54);
    // 0x800337A8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800337AC: sb          $v0, 0x4($t6)
    MEM_B(0X4, ctx->r14) = ctx->r2;
    // 0x800337B0: lw          $t9, 0x54($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X54);
    // 0x800337B4: nop

    // 0x800337B8: sb          $v0, 0x5($t9)
    MEM_B(0X5, ctx->r25) = ctx->r2;
    // 0x800337BC: lw          $t5, 0x54($fp)
    ctx->r13 = MEM_W(ctx->r30, 0X54);
    // 0x800337C0: nop

    // 0x800337C4: sb          $v0, 0x6($t5)
    MEM_B(0X6, ctx->r13) = ctx->r2;
    // 0x800337C8: lw          $t4, 0x54($fp)
    ctx->r12 = MEM_W(ctx->r30, 0X54);
    // 0x800337CC: nop

    // 0x800337D0: sb          $zero, 0x7($t4)
    MEM_B(0X7, ctx->r12) = 0;
L_800337D4:
    // 0x800337D4: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_800337D8:
    // 0x800337D8: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800337DC: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800337E0: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800337E4: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800337E8: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800337EC: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800337F0: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x800337F4: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800337F8: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x800337FC: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80033800: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80033804: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x80033808: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x8003380C: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x80033810: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x80033814: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x80033818: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x8003381C: jr          $ra
    // 0x80033820: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80033820: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void light_update_ambience(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033824: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80033828: addiu       $t2, $t2, -0x3128
    ctx->r10 = ADD32(ctx->r10, -0X3128);
    // 0x8003382C: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x80033830: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80033834: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x80033838: bne         $at, $zero, L_80033A4C
    if (ctx->r1 != 0) {
        // 0x8003383C: addiu       $a0, $zero, 0x14
        ctx->r4 = ADD32(0, 0X14);
            goto L_80033A4C;
    }
    // 0x8003383C: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x80033840: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80033844: addiu       $t3, $t3, -0x3130
    ctx->r11 = ADD32(ctx->r11, -0X3130);
    // 0x80033848: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
L_8003384C:
    // 0x8003384C: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80033850: nop

    // 0x80033854: addu        $a1, $v1, $a0
    ctx->r5 = ADD32(ctx->r3, ctx->r4);
    // 0x80033858: lw          $a2, 0x10($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X10);
    // 0x8003385C: nop

    // 0x80033860: slti        $at, $a2, 0x2
    ctx->r1 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
    // 0x80033864: bne         $at, $zero, L_80033A38
    if (ctx->r1 != 0) {
        // 0x80033868: nop
    
            goto L_80033A38;
    }
    // 0x80033868: nop

    // 0x8003386C: lw          $a3, 0x10($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X10);
    // 0x80033870: lw          $t1, 0x4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X4);
    // 0x80033874: slt         $at, $a3, $a2
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80033878: bne         $at, $zero, L_80033924
    if (ctx->r1 != 0) {
        // 0x8003387C: sll         $t7, $a3, 16
        ctx->r15 = S32(ctx->r7 << 16);
            goto L_80033924;
    }
    // 0x8003387C: sll         $t7, $a3, 16
    ctx->r15 = S32(ctx->r7 << 16);
    // 0x80033880: sll         $t7, $a2, 16
    ctx->r15 = S32(ctx->r6 << 16);
    // 0x80033884: div         $zero, $t7, $a3
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r7)));
    // 0x80033888: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x8003388C: bne         $a3, $zero, L_80033898
    if (ctx->r7 != 0) {
        // 0x80033890: nop
    
            goto L_80033898;
    }
    // 0x80033890: nop

    // 0x80033894: break       7
    do_break(2147694740);
L_80033898:
    // 0x80033898: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003389C: bne         $a3, $at, L_800338B0
    if (ctx->r7 != ctx->r1) {
        // 0x800338A0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800338B0;
    }
    // 0x800338A0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800338A4: bne         $t7, $at, L_800338B0
    if (ctx->r15 != ctx->r1) {
        // 0x800338A8: nop
    
            goto L_800338B0;
    }
    // 0x800338A8: nop

    // 0x800338AC: break       6
    do_break(2147694764);
L_800338B0:
    // 0x800338B0: mflo        $t0
    ctx->r8 = lo;
    // 0x800338B4: nop

    // 0x800338B8: nop

    // 0x800338BC: multu       $t8, $t0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800338C0: mflo        $t9
    ctx->r25 = lo;
    // 0x800338C4: sra         $t5, $t9, 16
    ctx->r13 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800338C8: addu        $t6, $t1, $t5
    ctx->r14 = ADD32(ctx->r9, ctx->r13);
    // 0x800338CC: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800338D0: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x800338D4: nop

    // 0x800338D8: addu        $t8, $v1, $a0
    ctx->r24 = ADD32(ctx->r3, ctx->r4);
    // 0x800338DC: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x800338E0: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x800338E4: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800338E8: mflo        $t5
    ctx->r13 = lo;
    // 0x800338EC: sra         $t6, $t5, 16
    ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800338F0: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x800338F4: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x800338F8: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x800338FC: nop

    // 0x80033900: addu        $t5, $v1, $a0
    ctx->r13 = ADD32(ctx->r3, ctx->r4);
    // 0x80033904: lw          $t7, 0xC($t5)
    ctx->r15 = MEM_W(ctx->r13, 0XC);
    // 0x80033908: lw          $t9, 0xC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XC);
    // 0x8003390C: multu       $t7, $t0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80033910: mflo        $t6
    ctx->r14 = lo;
    // 0x80033914: sra         $t8, $t6, 16
    ctx->r24 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80033918: addu        $t5, $t9, $t8
    ctx->r13 = ADD32(ctx->r25, ctx->r24);
    // 0x8003391C: b           L_800339D8
    // 0x80033920: sw          $t5, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r13;
        goto L_800339D8;
    // 0x80033920: sw          $t5, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r13;
L_80033924:
    // 0x80033924: div         $zero, $t7, $a2
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r6)));
    // 0x80033928: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x8003392C: bne         $a2, $zero, L_80033938
    if (ctx->r6 != 0) {
        // 0x80033930: nop
    
            goto L_80033938;
    }
    // 0x80033930: nop

    // 0x80033934: break       7
    do_break(2147694900);
L_80033938:
    // 0x80033938: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003393C: bne         $a2, $at, L_80033950
    if (ctx->r6 != ctx->r1) {
        // 0x80033940: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80033950;
    }
    // 0x80033940: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80033944: bne         $t7, $at, L_80033950
    if (ctx->r15 != ctx->r1) {
        // 0x80033948: nop
    
            goto L_80033950;
    }
    // 0x80033948: nop

    // 0x8003394C: break       6
    do_break(2147694924);
L_80033950:
    // 0x80033950: mflo        $t0
    ctx->r8 = lo;
    // 0x80033954: nop

    // 0x80033958: nop

    // 0x8003395C: multu       $t1, $t0
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80033960: mflo        $t9
    ctx->r25 = lo;
    // 0x80033964: sra         $t8, $t9, 16
    ctx->r24 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80033968: addu        $t5, $t6, $t8
    ctx->r13 = ADD32(ctx->r14, ctx->r24);
    // 0x8003396C: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x80033970: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80033974: nop

    // 0x80033978: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
    // 0x8003397C: addu        $t7, $v1, $a0
    ctx->r15 = ADD32(ctx->r3, ctx->r4);
    // 0x80033980: multu       $t6, $t0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80033984: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80033988: mflo        $t8
    ctx->r24 = lo;
    // 0x8003398C: sra         $t5, $t8, 16
    ctx->r13 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80033990: addu        $t7, $t9, $t5
    ctx->r15 = ADD32(ctx->r25, ctx->r13);
    // 0x80033994: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
    // 0x80033998: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8003399C: nop

    // 0x800339A0: lw          $t9, 0xC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XC);
    // 0x800339A4: addu        $t6, $v1, $a0
    ctx->r14 = ADD32(ctx->r3, ctx->r4);
    // 0x800339A8: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800339AC: lw          $t8, 0xC($t6)
    ctx->r24 = MEM_W(ctx->r14, 0XC);
    // 0x800339B0: mflo        $t5
    ctx->r13 = lo;
    // 0x800339B4: sra         $t7, $t5, 16
    ctx->r15 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800339B8: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x800339BC: sw          $t6, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r14;
    // 0x800339C0: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x800339C4: nop

    // 0x800339C8: addu        $t9, $v1, $a0
    ctx->r25 = ADD32(ctx->r3, ctx->r4);
    // 0x800339CC: lw          $t5, 0x10($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X10);
    // 0x800339D0: nop

    // 0x800339D4: sw          $t5, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r13;
L_800339D8:
    // 0x800339D8: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x800339DC: nop

    // 0x800339E0: lw          $t8, 0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4);
    // 0x800339E4: nop

    // 0x800339E8: slti        $at, $t8, 0x100
    ctx->r1 = SIGNED(ctx->r24) < 0X100 ? 1 : 0;
    // 0x800339EC: bne         $at, $zero, L_80033A00
    if (ctx->r1 != 0) {
        // 0x800339F0: nop
    
            goto L_80033A00;
    }
    // 0x800339F0: nop

    // 0x800339F4: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x800339F8: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x800339FC: nop

L_80033A00:
    // 0x80033A00: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x80033A04: nop

    // 0x80033A08: slti        $at, $t7, 0x100
    ctx->r1 = SIGNED(ctx->r15) < 0X100 ? 1 : 0;
    // 0x80033A0C: bne         $at, $zero, L_80033A20
    if (ctx->r1 != 0) {
        // 0x80033A10: nop
    
            goto L_80033A20;
    }
    // 0x80033A10: nop

    // 0x80033A14: sw          $t4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r12;
    // 0x80033A18: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80033A1C: nop

L_80033A20:
    // 0x80033A20: lw          $t6, 0xC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XC);
    // 0x80033A24: nop

    // 0x80033A28: slti        $at, $t6, 0x100
    ctx->r1 = SIGNED(ctx->r14) < 0X100 ? 1 : 0;
    // 0x80033A2C: bne         $at, $zero, L_80033A38
    if (ctx->r1 != 0) {
        // 0x80033A30: nop
    
            goto L_80033A38;
    }
    // 0x80033A30: nop

    // 0x80033A34: sw          $t4, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r12;
L_80033A38:
    // 0x80033A38: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x80033A3C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80033A40: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80033A44: bne         $at, $zero, L_8003384C
    if (ctx->r1 != 0) {
        // 0x80033A48: addiu       $a0, $a0, 0x14
        ctx->r4 = ADD32(ctx->r4, 0X14);
            goto L_8003384C;
    }
    // 0x80033A48: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
L_80033A4C:
    // 0x80033A4C: jr          $ra
    // 0x80033A50: nop

    return;
    // 0x80033A50: nop

;}
RECOMP_FUNC void light_distance_calc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033A54: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80033A58: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80033A5C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80033A60: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80033A64: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80033A68: lw          $t6, 0x28($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X28);
    // 0x80033A6C: lbu         $t7, 0x3($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X3);
    // 0x80033A70: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80033A74: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x80033A78: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80033A7C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80033A80: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80033A84: sltiu       $at, $t8, 0x5
    ctx->r1 = ctx->r24 < 0X5 ? 1 : 0;
    // 0x80033A88: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80033A8C: beq         $at, $zero, L_80033C2C
    if (ctx->r1 == 0) {
        // 0x80033A90: div.s       $f20, $f6, $f8
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
            goto L_80033C2C;
    }
    // 0x80033A90: div.s       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80033A94: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80033A98: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80033A9C: addu        $at, $at, $t8
    gpr jr_addend_80033AA8 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80033AA0: lw          $t8, 0x6510($at)
    ctx->r24 = ADD32(ctx->r1, 0X6510);
    // 0x80033AA4: nop

    // 0x80033AA8: jr          $t8
    // 0x80033AAC: nop

    switch (jr_addend_80033AA8 >> 2) {
        case 0: goto L_80033AB0; break;
        case 1: goto L_80033AE4; break;
        case 2: goto L_80033B24; break;
        case 3: goto L_80033B88; break;
        case 4: goto L_80033BF4; break;
        default: switch_error(__func__, 0x80033AA8, 0x800E6510);
    }
    // 0x80033AAC: nop

L_80033AB0:
    // 0x80033AB0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80033AB4: lwc1        $f12, -0x25C0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X25C0);
    // 0x80033AB8: jal         0x800CA030
    // 0x80033ABC: nop

    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80033ABC: nop

    after_0:
    // 0x80033AC0: lwc1        $f16, 0x6C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80033AC4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80033AC8: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80033ACC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80033AD0: nop

    // 0x80033AD4: sub.s       $f2, $f10, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80033AD8: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80033ADC: b           L_80033C30
    // 0x80033AE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80033C30;
    // 0x80033AE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80033AE4:
    // 0x80033AE4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80033AE8: lwc1        $f12, -0x25C0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X25C0);
    // 0x80033AEC: jal         0x800CA030
    // 0x80033AF0: nop

    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x80033AF0: nop

    after_1:
    // 0x80033AF4: lwc1        $f4, 0x6C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80033AF8: nop

    // 0x80033AFC: mul.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80033B00: jal         0x800CA030
    // 0x80033B04: nop

    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x80033B04: nop

    after_2:
    // 0x80033B08: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80033B0C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80033B10: nop

    // 0x80033B14: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80033B18: mul.s       $f20, $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f8.fl);
    // 0x80033B1C: b           L_80033C30
    // 0x80033B20: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80033C30;
    // 0x80033B20: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80033B24:
    // 0x80033B24: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80033B28: lwc1        $f12, -0x25C0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X25C0);
    // 0x80033B2C: jal         0x800CA030
    // 0x80033B30: nop

    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x80033B30: nop

    after_3:
    // 0x80033B34: lwc1        $f16, 0x6C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80033B38: lui         $at, 0x4680
    ctx->r1 = S32(0X4680 << 16);
    // 0x80033B3C: mul.s       $f10, $f0, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80033B40: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80033B44: nop

    // 0x80033B48: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80033B4C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80033B50: nop

    // 0x80033B54: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80033B58: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80033B5C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80033B60: nop

    // 0x80033B64: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80033B68: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x80033B6C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80033B70: sll         $t0, $a0, 16
    ctx->r8 = S32(ctx->r4 << 16);
    // 0x80033B74: jal         0x80070A38
    // 0x80033B78: sra         $a0, $t0, 16
    ctx->r4 = S32(SIGNED(ctx->r8) >> 16);
    coss_f(rdram, ctx);
        goto after_4;
    // 0x80033B78: sra         $a0, $t0, 16
    ctx->r4 = S32(SIGNED(ctx->r8) >> 16);
    after_4:
    // 0x80033B7C: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80033B80: b           L_80033C30
    // 0x80033B84: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80033C30;
    // 0x80033B84: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80033B88:
    // 0x80033B88: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80033B8C: lwc1        $f12, -0x25C0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X25C0);
    // 0x80033B90: jal         0x800CA030
    // 0x80033B94: nop

    sqrtf_recomp(rdram, ctx);
        goto after_5;
    // 0x80033B94: nop

    after_5:
    // 0x80033B98: lwc1        $f8, 0x6C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80033B9C: lui         $at, 0x4680
    ctx->r1 = S32(0X4680 << 16);
    // 0x80033BA0: mul.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80033BA4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80033BA8: nop

    // 0x80033BAC: mul.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x80033BB0: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80033BB4: nop

    // 0x80033BB8: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x80033BBC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80033BC0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80033BC4: nop

    // 0x80033BC8: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80033BCC: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x80033BD0: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80033BD4: sll         $t3, $a0, 16
    ctx->r11 = S32(ctx->r4 << 16);
    // 0x80033BD8: jal         0x80070A38
    // 0x80033BDC: sra         $a0, $t3, 16
    ctx->r4 = S32(SIGNED(ctx->r11) >> 16);
    coss_f(rdram, ctx);
        goto after_6;
    // 0x80033BDC: sra         $a0, $t3, 16
    ctx->r4 = S32(SIGNED(ctx->r11) >> 16);
    after_6:
    // 0x80033BE0: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80033BE4: nop

    // 0x80033BE8: mul.s       $f20, $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x80033BEC: b           L_80033C2C
    // 0x80033BF0: nop

        goto L_80033C2C;
    // 0x80033BF0: nop

L_80033BF4:
    // 0x80033BF4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80033BF8: lwc1        $f12, -0x25C0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X25C0);
    // 0x80033BFC: jal         0x800CA030
    // 0x80033C00: nop

    sqrtf_recomp(rdram, ctx);
        goto after_7;
    // 0x80033C00: nop

    after_7:
    // 0x80033C04: lwc1        $f16, 0x6C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80033C08: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80033C0C: mul.s       $f10, $f0, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80033C10: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80033C14: nop

    // 0x80033C18: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80033C1C: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80033C20: nop

    // 0x80033C24: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80033C28: nop

L_80033C2C:
    // 0x80033C2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80033C30:
    // 0x80033C30: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
    // 0x80033C34: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80033C38: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80033C3C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80033C40: jr          $ra
    // 0x80033C44: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80033C44: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void light_direction_calc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033C48: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80033C4C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80033C50: lwc1        $f12, -0x25C0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X25C0);
    // 0x80033C54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80033C58: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x80033C5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80033C60: bc1f        L_80033CE4
    if (!c1cs) {
        // 0x80033C64: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80033CE4;
    }
    // 0x80033C64: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80033C68: jal         0x800CA030
    // 0x80033C6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80033C6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80033C70: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80033C74: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80033C78: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80033C7C: div.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80033C80: lwc1        $f6, -0x25BC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X25BC);
    // 0x80033C84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80033C88: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80033C8C: lwc1        $f10, 0x7C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x80033C90: lwc1        $f18, -0x25B8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X25B8);
    // 0x80033C94: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80033C98: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80033C9C: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80033CA0: lwc1        $f6, 0x80($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X80);
    // 0x80033CA4: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80033CA8: nop

    // 0x80033CAC: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80033CB0: lwc1        $f18, -0x25B4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X25B4);
    // 0x80033CB4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80033CB8: lwc1        $f6, 0x84($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X84);
    // 0x80033CBC: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80033CC0: add.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x80033CC4: mul.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80033CC8: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80033CCC: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x80033CD0: nop

    // 0x80033CD4: bc1f        L_80033CEC
    if (!c1cs) {
        // 0x80033CD8: nop
    
            goto L_80033CEC;
    }
    // 0x80033CD8: nop

    // 0x80033CDC: b           L_80033CEC
    // 0x80033CE0: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
        goto L_80033CEC;
    // 0x80033CE0: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
L_80033CE4:
    // 0x80033CE4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80033CE8: nop

L_80033CEC:
    // 0x80033CEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80033CF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80033CF4: jr          $ra
    // 0x80033CF8: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    return;
    // 0x80033CF8: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x80033CFC: nop

;}
RECOMP_FUNC void obj_init_scenery(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033D00: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x80033D04: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80033D08: ori         $t7, $t6, 0x2
    ctx->r15 = ctx->r14 | 0X2;
    // 0x80033D0C: sh          $t7, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r15;
    // 0x80033D10: lbu         $t9, 0x9($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X9);
    // 0x80033D14: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80033D18: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80033D1C: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80033D20: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80033D24: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80033D28: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80033D2C: nop

    // 0x80033D30: bc1f        L_80033D40
    if (!c1cs) {
        // 0x80033D34: nop
    
            goto L_80033D40;
    }
    // 0x80033D34: nop

    // 0x80033D38: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80033D3C: nop

L_80033D40:
    // 0x80033D40: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80033D44: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x80033D48: lw          $t0, 0x50($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X50);
    // 0x80033D4C: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80033D50: nop

    // 0x80033D54: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80033D58: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
    // 0x80033D5C: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80033D60: nop

    // 0x80033D64: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80033D68: swc1        $f18, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f18.u32l;
    // 0x80033D6C: lbu         $t1, 0x8($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X8);
    // 0x80033D70: nop

    // 0x80033D74: sb          $t1, 0x3A($a0)
    MEM_B(0X3A, ctx->r4) = ctx->r9;
    // 0x80033D78: lbu         $t3, 0xA($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0XA);
    // 0x80033D7C: nop

    // 0x80033D80: sll         $t4, $t3, 10
    ctx->r12 = S32(ctx->r11 << 10);
    // 0x80033D84: sh          $t4, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r12;
    // 0x80033D88: lbu         $t5, 0xB($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0XB);
    // 0x80033D8C: nop

    // 0x80033D90: beq         $t5, $zero, L_80033DE4
    if (ctx->r13 == 0) {
        // 0x80033D94: nop
    
            goto L_80033DE4;
    }
    // 0x80033D94: nop

    // 0x80033D98: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x80033D9C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80033DA0: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x80033DA4: lw          $t9, 0x4C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4C);
    // 0x80033DA8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80033DAC: sb          $t8, 0x11($t9)
    MEM_B(0X11, ctx->r25) = ctx->r24;
    // 0x80033DB0: lw          $t1, 0x4C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4C);
    // 0x80033DB4: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x80033DB8: sb          $t0, 0x10($t1)
    MEM_B(0X10, ctx->r9) = ctx->r8;
    // 0x80033DBC: lw          $t2, 0x4C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X4C);
    // 0x80033DC0: addiu       $t3, $zero, -0x5
    ctx->r11 = ADD32(0, -0X5);
    // 0x80033DC4: sb          $zero, 0x12($t2)
    MEM_B(0X12, ctx->r10) = 0;
    // 0x80033DC8: lw          $t4, 0x4C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X4C);
    // 0x80033DCC: nop

    // 0x80033DD0: sb          $t3, 0x16($t4)
    MEM_B(0X16, ctx->r12) = ctx->r11;
    // 0x80033DD4: lw          $t6, 0x4C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4C);
    // 0x80033DD8: lbu         $t5, 0xB($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0XB);
    // 0x80033DDC: nop

    // 0x80033DE0: sb          $t5, 0x17($t6)
    MEM_B(0X17, ctx->r14) = ctx->r13;
L_80033DE4:
    // 0x80033DE4: lw          $t8, 0x40($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X40);
    // 0x80033DE8: lb          $t7, 0x3A($a0)
    ctx->r15 = MEM_B(ctx->r4, 0X3A);
    // 0x80033DEC: lb          $t9, 0x55($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X55);
    // 0x80033DF0: nop

    // 0x80033DF4: slt         $at, $t7, $t9
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80033DF8: bne         $at, $zero, L_80033E04
    if (ctx->r1 != 0) {
        // 0x80033DFC: nop
    
            goto L_80033E04;
    }
    // 0x80033DFC: nop

    // 0x80033E00: sb          $zero, 0x3A($a0)
    MEM_B(0X3A, ctx->r4) = 0;
L_80033E04:
    // 0x80033E04: sw          $zero, 0x78($a0)
    MEM_W(0X78, ctx->r4) = 0;
    // 0x80033E08: jr          $ra
    // 0x80033E0C: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
    return;
    // 0x80033E0C: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
;}
RECOMP_FUNC void obj_loop_scenery(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033E10: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80033E14: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80033E18: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80033E1C: lw          $v0, 0x4C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4C);
    // 0x80033E20: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80033E24: beq         $v0, $zero, L_80033F78
    if (ctx->r2 == 0) {
        // 0x80033E28: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80033F78;
    }
    // 0x80033E28: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80033E2C: lh          $t6, 0x7C($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X7C);
    // 0x80033E30: addiu       $v1, $a0, 0x78
    ctx->r3 = ADD32(ctx->r4, 0X78);
    // 0x80033E34: blez        $t6, L_80033E54
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80033E38: nop
    
            goto L_80033E54;
    }
    // 0x80033E38: nop

    // 0x80033E3C: lh          $t7, 0x4($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X4);
    // 0x80033E40: nop

    // 0x80033E44: subu        $t8, $t7, $a1
    ctx->r24 = SUB32(ctx->r15, ctx->r5);
    // 0x80033E48: sh          $t8, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r24;
    // 0x80033E4C: lw          $v0, 0x4C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4C);
    // 0x80033E50: nop

L_80033E54:
    // 0x80033E54: lh          $t9, 0x14($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X14);
    // 0x80033E58: addiu       $v1, $s0, 0x78
    ctx->r3 = ADD32(ctx->r16, 0X78);
    // 0x80033E5C: andi        $t0, $t9, 0x40
    ctx->r8 = ctx->r25 & 0X40;
    // 0x80033E60: beq         $t0, $zero, L_80033F2C
    if (ctx->r8 == 0) {
        // 0x80033E64: nop
    
            goto L_80033F2C;
    }
    // 0x80033E64: nop

    // 0x80033E68: lh          $t1, 0x4($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X4);
    // 0x80033E6C: addiu       $a0, $zero, 0x13C
    ctx->r4 = ADD32(0, 0X13C);
    // 0x80033E70: bgtz        $t1, L_80033F2C
    if (SIGNED(ctx->r9) > 0) {
        // 0x80033E74: addiu       $t2, $zero, 0x4
        ctx->r10 = ADD32(0, 0X4);
            goto L_80033F2C;
    }
    // 0x80033E74: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x80033E78: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x80033E7C: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x80033E80: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x80033E84: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x80033E88: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80033E8C: jal         0x80009558
    // 0x80033E90: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_0;
    // 0x80033E90: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_0:
    // 0x80033E94: lw          $t3, 0x4C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4C);
    // 0x80033E98: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80033E9C: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80033EA0: addiu       $t5, $zero, 0x71C
    ctx->r13 = ADD32(0, 0X71C);
    // 0x80033EA4: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x80033EA8: sh          $t5, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r13;
    // 0x80033EAC: sh          $t6, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r14;
    // 0x80033EB0: jal         0x8009C90C
    // 0x80033EB4: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    get_number_of_active_players(rdram, ctx);
        goto after_1;
    // 0x80033EB4: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    after_1:
    // 0x80033EB8: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80033EBC: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80033EC0: beq         $at, $zero, L_80033F40
    if (ctx->r1 == 0) {
        // 0x80033EC4: nop
    
            goto L_80033F40;
    }
    // 0x80033EC4: nop

    // 0x80033EC8: lw          $t7, 0x40($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X40);
    // 0x80033ECC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80033ED0: lb          $v0, 0x57($t7)
    ctx->r2 = MEM_B(ctx->r15, 0X57);
    // 0x80033ED4: nop

    // 0x80033ED8: blez        $v0, L_80033F40
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80033EDC: nop
    
            goto L_80033F40;
    }
    // 0x80033EDC: nop

    // 0x80033EE0: bne         $v0, $at, L_80033EF0
    if (ctx->r2 != ctx->r1) {
        // 0x80033EE4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80033EF0;
    }
    // 0x80033EE4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80033EE8: b           L_80033F04
    // 0x80033EEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_80033F04;
    // 0x80033EEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80033EF0:
    // 0x80033EF0: addiu       $a1, $v0, -0x1
    ctx->r5 = ADD32(ctx->r2, -0X1);
    // 0x80033EF4: jal         0x8006FB8C
    // 0x80033EF8: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    rand_range(rdram, ctx);
        goto after_2;
    // 0x80033EF8: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_2:
    // 0x80033EFC: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80033F00: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_80033F04:
    // 0x80033F04: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80033F08: sllv        $t9, $t8, $a2
    ctx->r25 = S32(ctx->r24 << (ctx->r6 & 31));
    // 0x80033F0C: sw          $t9, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r25;
    // 0x80033F10: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x80033F14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80033F18: jal         0x800B019C
    // 0x80033F1C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    obj_spawn_particle(rdram, ctx);
        goto after_3;
    // 0x80033F1C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x80033F20: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80033F24: b           L_80033F44
    // 0x80033F28: lh          $t1, 0x6($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X6);
        goto L_80033F44;
    // 0x80033F28: lh          $t1, 0x6($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X6);
L_80033F2C:
    // 0x80033F2C: lh          $t0, 0x4($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X4);
    // 0x80033F30: nop

    // 0x80033F34: bgtz        $t0, L_80033F40
    if (SIGNED(ctx->r8) > 0) {
        // 0x80033F38: nop
    
            goto L_80033F40;
    }
    // 0x80033F38: nop

    // 0x80033F3C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_80033F40:
    // 0x80033F40: lh          $t1, 0x6($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X6);
L_80033F44:
    // 0x80033F44: nop

    // 0x80033F48: sh          $t1, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r9;
    // 0x80033F4C: lh          $t2, 0x6($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X6);
    // 0x80033F50: nop

    // 0x80033F54: negu        $at, $t2
    ctx->r1 = SUB32(0, ctx->r10);
    // 0x80033F58: sll         $t3, $at, 2
    ctx->r11 = S32(ctx->r1 << 2);
    // 0x80033F5C: subu        $t3, $t3, $at
    ctx->r11 = SUB32(ctx->r11, ctx->r1);
    // 0x80033F60: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80033F64: addu        $t3, $t3, $at
    ctx->r11 = ADD32(ctx->r11, ctx->r1);
    // 0x80033F68: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80033F6C: sra         $t4, $t3, 8
    ctx->r12 = S32(SIGNED(ctx->r11) >> 8);
    // 0x80033F70: sh          $t4, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r12;
    // 0x80033F74: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80033F78:
    // 0x80033F78: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80033F7C: jr          $ra
    // 0x80033F80: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80033F80: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void obj_init_fireball_octoweapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033F84: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80033F88: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x80033F8C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80033F90: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x80033F94: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x80033F98: jr          $ra
    // 0x80033F9C: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
    return;
    // 0x80033F9C: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
;}
RECOMP_FUNC void obj_loop_fireball_octoweapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033FA0: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80033FA4: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x80033FA8: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x80033FAC: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80033FB0: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x80033FB4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80033FB8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80033FBC: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x80033FC0: lw          $v1, 0x78($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X78);
    // 0x80033FC4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80033FC8: bne         $t7, $zero, L_80033FEC
    if (ctx->r15 != 0) {
        // 0x80033FCC: swc1        $f0, 0x7C($sp)
        MEM_W(0X7C, ctx->r29) = ctx->f0.u32l;
            goto L_80033FEC;
    }
    // 0x80033FCC: swc1        $f0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f0.u32l;
    // 0x80033FD0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80033FD4: lwc1        $f9, 0x6570($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6570);
    // 0x80033FD8: lwc1        $f8, 0x6574($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6574);
    // 0x80033FDC: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80033FE0: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80033FE4: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x80033FE8: swc1        $f4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f4.u32l;
L_80033FEC:
    // 0x80033FEC: lh          $t8, 0x48($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X48);
    // 0x80033FF0: addiu       $at, $zero, 0x74
    ctx->r1 = ADD32(0, 0X74);
    // 0x80033FF4: bne         $t8, $at, L_8003404C
    if (ctx->r24 != ctx->r1) {
        // 0x80033FF8: nop
    
            goto L_8003404C;
    }
    // 0x80033FF8: nop

    // 0x80033FFC: lw          $t9, 0x7C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X7C);
    // 0x80034000: nop

    // 0x80034004: bgez        $t9, L_8003404C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80034008: nop
    
            goto L_8003404C;
    }
    // 0x80034008: nop

    // 0x8003400C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80034010: nop

    // 0x80034014: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x80034018: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x8003401C: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
    // 0x80034020: jal         0x80011560
    // 0x80034024: sw          $v1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r3;
    ignore_bounds_check(rdram, ctx);
        goto after_0;
    // 0x80034024: sw          $v1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r3;
    after_0:
    // 0x80034028: lw          $v1, 0x84($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X84);
    // 0x8003402C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80034030: lw          $a1, 0xC($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XC);
    // 0x80034034: lw          $a2, 0x10($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X10);
    // 0x80034038: lw          $a3, 0x14($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X14);
    // 0x8003403C: jal         0x80011570
    // 0x80034040: nop

    move_object(rdram, ctx);
        goto after_1;
    // 0x80034040: nop

    after_1:
    // 0x80034044: b           L_800342F8
    // 0x80034048: lw          $t6, 0x8C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8C);
        goto L_800342F8;
    // 0x80034048: lw          $t6, 0x8C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8C);
L_8003404C:
    // 0x8003404C: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80034050: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80034054: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80034058: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8003405C: lwc1        $f19, 0x6578($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, 0X6578);
    // 0x80034060: lwc1        $f18, 0x657C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X657C);
    // 0x80034064: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80034068: mul.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f18.d);
    // 0x8003406C: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80034070: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80034074: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80034078: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8003407C: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
    // 0x80034080: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80034084: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x80034088: c.lt.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d < ctx->f0.d;
    // 0x8003408C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80034090: bc1f        L_800340A4
    if (!c1cs) {
        // 0x80034094: cvt.d.s     $f16, $f4
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
            goto L_800340A4;
    }
    // 0x80034094: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x80034098: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003409C: nop

    // 0x800340A0: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
L_800340A4:
    // 0x800340A4: lui         $at, 0xC024
    ctx->r1 = S32(0XC024 << 16);
    // 0x800340A8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800340AC: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x800340B0: c.lt.d      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.d < ctx->f10.d;
    // 0x800340B4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800340B8: bc1f        L_800340C8
    if (!c1cs) {
        // 0x800340BC: nop
    
            goto L_800340C8;
    }
    // 0x800340BC: nop

    // 0x800340C0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800340C4: nop

L_800340C8:
    // 0x800340C8: lwc1        $f14, 0x1C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800340CC: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800340D0: sub.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x800340D4: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800340D8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800340DC: mul.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800340E0: cvt.d.s     $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f8.d = CVT_D_S(ctx->f14.fl);
    // 0x800340E4: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x800340E8: mul.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x800340EC: add.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d + ctx->f6.d;
    // 0x800340F0: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800340F4: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x800340F8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800340FC: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    // 0x80034100: lwc1        $f8, 0x10($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80034104: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80034108: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8003410C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80034110: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80034114: mul.d       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f18.d);
    // 0x80034118: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8003411C: cvt.s.d     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f2.fl = CVT_S_D(ctx->f8.d);
    // 0x80034120: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x80034124: c.lt.d      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.d < ctx->f0.d;
    // 0x80034128: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8003412C: bc1f        L_80034140
    if (!c1cs) {
        // 0x80034130: nop
    
            goto L_80034140;
    }
    // 0x80034130: nop

    // 0x80034134: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80034138: nop

    // 0x8003413C: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
L_80034140:
    // 0x80034140: lui         $at, 0xC024
    ctx->r1 = S32(0XC024 << 16);
    // 0x80034144: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80034148: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x8003414C: c.lt.d      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.d < ctx->f10.d;
    // 0x80034150: nop

    // 0x80034154: bc1f        L_80034164
    if (!c1cs) {
        // 0x80034158: nop
    
            goto L_80034164;
    }
    // 0x80034158: nop

    // 0x8003415C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80034160: nop

L_80034164:
    // 0x80034164: lwc1        $f12, 0x20($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80034168: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8003416C: sub.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x80034170: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80034174: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80034178: mul.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f6.d);
    // 0x8003417C: cvt.d.s     $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f8.d = CVT_D_S(ctx->f12.fl);
    // 0x80034180: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80034184: mul.d       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x80034188: add.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f8.d + ctx->f4.d;
    // 0x8003418C: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80034190: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x80034194: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80034198: swc1        $f10, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f10.u32l;
    // 0x8003419C: lwc1        $f8, 0x14($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X14);
    // 0x800341A0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800341A4: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800341A8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800341AC: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x800341B0: mul.d       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x800341B4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800341B8: cvt.s.d     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f2.fl = CVT_S_D(ctx->f8.d);
    // 0x800341BC: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x800341C0: c.lt.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d < ctx->f0.d;
    // 0x800341C4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800341C8: bc1f        L_800341DC
    if (!c1cs) {
        // 0x800341CC: nop
    
            goto L_800341DC;
    }
    // 0x800341CC: nop

    // 0x800341D0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800341D4: nop

    // 0x800341D8: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
L_800341DC:
    // 0x800341DC: lui         $at, 0xC024
    ctx->r1 = S32(0XC024 << 16);
    // 0x800341E0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800341E4: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x800341E8: c.lt.d      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.d < ctx->f6.d;
    // 0x800341EC: nop

    // 0x800341F0: bc1f        L_80034200
    if (!c1cs) {
        // 0x800341F4: nop
    
            goto L_80034200;
    }
    // 0x800341F4: nop

    // 0x800341F8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800341FC: nop

L_80034200:
    // 0x80034200: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80034204: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80034208: sub.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8003420C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80034210: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x80034214: mul.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f4.d);
    // 0x80034218: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x8003421C: lwc1        $f14, 0x1C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80034220: mul.d       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f16.d);
    // 0x80034224: add.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f8.d + ctx->f10.d;
    // 0x80034228: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8003422C: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80034230: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    // 0x80034234: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80034238: nop

    // 0x8003423C: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80034240: jal         0x800CA030
    // 0x80034244: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x80034244: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_2:
    // 0x80034248: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8003424C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80034250: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80034254: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80034258: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x8003425C: lwc1        $f2, 0x7C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80034260: bc1f        L_80034294
    if (!c1cs) {
        // 0x80034264: nop
    
            goto L_80034294;
    }
    // 0x80034264: nop

    // 0x80034268: lwc1        $f12, 0x1C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8003426C: lwc1        $f14, 0x24($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80034270: jal         0x80070990
    // 0x80034274: nop

    arctan2_f(rdram, ctx);
        goto after_3;
    // 0x80034274: nop

    after_3:
    // 0x80034278: lwc1        $f2, 0x7C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8003427C: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x80034280: lw          $t1, 0x8C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8C);
    // 0x80034284: lh          $t0, 0x2($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X2);
    // 0x80034288: sll         $t2, $t1, 9
    ctx->r10 = S32(ctx->r9 << 9);
    // 0x8003428C: subu        $t3, $t0, $t2
    ctx->r11 = SUB32(ctx->r8, ctx->r10);
    // 0x80034290: sh          $t3, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r11;
L_80034294:
    // 0x80034294: lwc1        $f8, 0x1C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80034298: lwc1        $f4, 0x20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8003429C: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800342A0: lwc1        $f8, 0x24($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800342A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800342A8: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800342AC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800342B0: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800342B4: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800342B8: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x800342BC: jal         0x80011570
    // 0x800342C0: nop

    move_object(rdram, ctx);
        goto after_4;
    // 0x800342C0: nop

    after_4:
    // 0x800342C4: lh          $t4, 0x4A($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X4A);
    // 0x800342C8: addiu       $at, $zero, 0x12A
    ctx->r1 = ADD32(0, 0X12A);
    // 0x800342CC: bne         $t4, $at, L_800342F4
    if (ctx->r12 != ctx->r1) {
        // 0x800342D0: addiu       $a1, $sp, 0x4C
        ctx->r5 = ADD32(ctx->r29, 0X4C);
            goto L_800342F4;
    }
    // 0x800342D0: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x800342D4: lwc1        $f12, 0x10($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800342D8: jal         0x8002AD48
    // 0x800342DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    get_wave_properties(rdram, ctx);
        goto after_5;
    // 0x800342DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x800342E0: beq         $v0, $zero, L_800342F8
    if (ctx->r2 == 0) {
        // 0x800342E4: lw          $t6, 0x8C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X8C);
            goto L_800342F8;
    }
    // 0x800342E4: lw          $t6, 0x8C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8C);
    // 0x800342E8: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800342EC: nop

    // 0x800342F0: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
L_800342F4:
    // 0x800342F4: lw          $t6, 0x8C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8C);
L_800342F8:
    // 0x800342F8: lh          $t5, 0x18($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X18);
    // 0x800342FC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80034300: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80034304: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80034308: lw          $t9, 0x64($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X64);
    // 0x8003430C: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x80034310: sh          $t8, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r24;
    // 0x80034314: sw          $t9, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r25;
    // 0x80034318: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x8003431C: nop

    // 0x80034320: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80034324: nop

    // 0x80034328: beq         $a0, $zero, L_800343F4
    if (ctx->r4 == 0) {
        // 0x8003432C: nop
    
            goto L_800343F4;
    }
    // 0x8003432C: nop

    // 0x80034330: lbu         $t1, 0x13($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X13);
    // 0x80034334: nop

    // 0x80034338: slti        $at, $t1, 0x3C
    ctx->r1 = SIGNED(ctx->r9) < 0X3C ? 1 : 0;
    // 0x8003433C: beq         $at, $zero, L_800343F4
    if (ctx->r1 == 0) {
        // 0x80034340: nop
    
            goto L_800343F4;
    }
    // 0x80034340: nop

    // 0x80034344: lw          $t0, 0x40($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X40);
    // 0x80034348: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8003434C: lb          $t2, 0x54($t0)
    ctx->r10 = MEM_B(ctx->r8, 0X54);
    // 0x80034350: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80034354: bne         $a1, $t2, L_800343F4
    if (ctx->r5 != ctx->r10) {
        // 0x80034358: nop
    
            goto L_800343F4;
    }
    // 0x80034358: nop

    // 0x8003435C: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x80034360: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80034364: lh          $t3, 0x0($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X0);
    // 0x80034368: nop

    // 0x8003436C: beq         $t3, $at, L_800343F4
    if (ctx->r11 == ctx->r1) {
        // 0x80034370: nop
    
            goto L_800343F4;
    }
    // 0x80034370: nop

    // 0x80034374: lh          $t4, 0x48($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X48);
    // 0x80034378: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    // 0x8003437C: bne         $t4, $at, L_800343C8
    if (ctx->r12 != ctx->r1) {
        // 0x80034380: addiu       $t6, $zero, 0x14
        ctx->r14 = ADD32(0, 0X14);
            goto L_800343C8;
    }
    // 0x80034380: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x80034384: sb          $a1, 0x187($v0)
    MEM_B(0X187, ctx->r2) = ctx->r5;
    // 0x80034388: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x8003438C: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80034390: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80034394: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80034398: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003439C: sw          $t6, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r14;
    // 0x800343A0: addiu       $t5, $zero, 0x11
    ctx->r13 = ADD32(0, 0X11);
    // 0x800343A4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800343A8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x800343AC: addiu       $a3, $zero, 0x2C
    ctx->r7 = ADD32(0, 0X2C);
    // 0x800343B0: jal         0x8003FC84
    // 0x800343B4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    obj_spawn_effect(rdram, ctx);
        goto after_6;
    // 0x800343B4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_6:
    // 0x800343B8: jal         0x8000FFB8
    // 0x800343BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    free_object(rdram, ctx);
        goto after_7;
    // 0x800343BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x800343C0: b           L_800343F8
    // 0x800343C4: lh          $t1, 0x48($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X48);
        goto L_800343F8;
    // 0x800343C4: lh          $t1, 0x48($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X48);
L_800343C8:
    // 0x800343C8: lw          $t7, 0x7C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X7C);
    // 0x800343CC: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x800343D0: blez        $t7, L_800343F4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800343D4: addiu       $t9, $zero, -0x3C
        ctx->r25 = ADD32(0, -0X3C);
            goto L_800343F4;
    }
    // 0x800343D4: addiu       $t9, $zero, -0x3C
    ctx->r25 = ADD32(0, -0X3C);
    // 0x800343D8: sh          $t8, 0x204($v0)
    MEM_H(0X204, ctx->r2) = ctx->r24;
    // 0x800343DC: sw          $t9, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r25;
    // 0x800343E0: sw          $v1, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r3;
    // 0x800343E4: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x800343E8: addiu       $a0, $zero, 0x24A
    ctx->r4 = ADD32(0, 0X24A);
    // 0x800343EC: jal         0x80001D04
    // 0x800343F0: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    sound_play(rdram, ctx);
        goto after_8;
    // 0x800343F0: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    after_8:
L_800343F4:
    // 0x800343F4: lh          $t1, 0x48($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X48);
L_800343F8:
    // 0x800343F8: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    // 0x800343FC: bne         $t1, $at, L_800344C8
    if (ctx->r9 != ctx->r1) {
        // 0x80034400: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_800344C8;
    }
    // 0x80034400: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80034404: sw          $t0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r8;
    // 0x80034408: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x8003440C: jal         0x800B019C
    // 0x80034410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    obj_spawn_particle(rdram, ctx);
        goto after_9;
    // 0x80034410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80034414: lw          $t2, 0x7C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X7C);
    // 0x80034418: lw          $t3, 0x8C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8C);
    // 0x8003441C: nop

    // 0x80034420: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x80034424: bgez        $t4, L_80034560
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80034428: sw          $t4, 0x7C($s0)
        MEM_W(0X7C, ctx->r16) = ctx->r12;
            goto L_80034560;
    }
    // 0x80034428: sw          $t4, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r12;
    // 0x8003442C: lh          $t5, 0x4A($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X4A);
    // 0x80034430: addiu       $at, $zero, 0x12A
    ctx->r1 = ADD32(0, 0X12A);
    // 0x80034434: bne         $t5, $at, L_80034474
    if (ctx->r13 != ctx->r1) {
        // 0x80034438: nop
    
            goto L_80034474;
    }
    // 0x80034438: nop

    // 0x8003443C: jal         0x8000FFB8
    // 0x80034440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    free_object(rdram, ctx);
        goto after_10;
    // 0x80034440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80034444: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80034448: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003444C: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x80034450: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80034454: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80034458: addiu       $t7, $zero, 0x11
    ctx->r15 = ADD32(0, 0X11);
    // 0x8003445C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80034460: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80034464: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80034468: addiu       $a3, $zero, 0x2C
    ctx->r7 = ADD32(0, 0X2C);
    // 0x8003446C: jal         0x8003FC84
    // 0x80034470: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    obj_spawn_effect(rdram, ctx);
        goto after_11;
    // 0x80034470: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_11:
L_80034474:
    // 0x80034474: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80034478: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8003447C: lwc1        $f7, 0x6580($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6580);
    // 0x80034480: lwc1        $f6, 0x6584($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6584);
    // 0x80034484: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80034488: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8003448C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80034490: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80034494: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80034498: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x8003449C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800344A0: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800344A4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800344A8: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x800344AC: nop

    // 0x800344B0: bc1f        L_80034564
    if (!c1cs) {
        // 0x800344B4: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80034564;
    }
    // 0x800344B4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800344B8: jal         0x8000FFB8
    // 0x800344BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    free_object(rdram, ctx);
        goto after_12;
    // 0x800344BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x800344C0: b           L_80034564
    // 0x800344C4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80034564;
    // 0x800344C4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800344C8:
    // 0x800344C8: lw          $v0, 0x7C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X7C);
    // 0x800344CC: lw          $t0, 0x8C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8C);
    // 0x800344D0: bgez        $v0, L_800344FC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800344D4: subu        $t2, $v0, $t0
        ctx->r10 = SUB32(ctx->r2, ctx->r8);
            goto L_800344FC;
    }
    // 0x800344D4: subu        $t2, $v0, $t0
    ctx->r10 = SUB32(ctx->r2, ctx->r8);
    // 0x800344D8: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
    // 0x800344DC: nop

    // 0x800344E0: addu        $t1, $v0, $t9
    ctx->r9 = ADD32(ctx->r2, ctx->r25);
    // 0x800344E4: sw          $t1, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r9;
    // 0x800344E8: bltz        $t1, L_80034510
    if (SIGNED(ctx->r9) < 0) {
        // 0x800344EC: or          $v0, $t1, $zero
        ctx->r2 = ctx->r9 | 0;
            goto L_80034510;
    }
    // 0x800344EC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800344F0: sw          $zero, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = 0;
    // 0x800344F4: b           L_80034510
    // 0x800344F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80034510;
    // 0x800344F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800344FC:
    // 0x800344FC: sw          $t2, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r10;
    // 0x80034500: bgtz        $t2, L_80034510
    if (SIGNED(ctx->r10) > 0) {
        // 0x80034504: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_80034510;
    }
    // 0x80034504: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x80034508: sw          $zero, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = 0;
    // 0x8003450C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80034510:
    // 0x80034510: bne         $v0, $zero, L_80034564
    if (ctx->r2 != 0) {
        // 0x80034514: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80034564;
    }
    // 0x80034514: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80034518: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x8003451C: nop

    // 0x80034520: lw          $a0, 0x1C($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X1C);
    // 0x80034524: nop

    // 0x80034528: beq         $a0, $zero, L_80034538
    if (ctx->r4 == 0) {
        // 0x8003452C: nop
    
            goto L_80034538;
    }
    // 0x8003452C: nop

    // 0x80034530: jal         0x8000488C
    // 0x80034534: nop

    sndp_stop(rdram, ctx);
        goto after_13;
    // 0x80034534: nop

    after_13:
L_80034538:
    // 0x80034538: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8003453C: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x80034540: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x80034544: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80034548: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8003454C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80034550: jal         0x80009558
    // 0x80034554: addiu       $a0, $zero, 0x155
    ctx->r4 = ADD32(0, 0X155);
    audspat_play_sound_at_position(rdram, ctx);
        goto after_14;
    // 0x80034554: addiu       $a0, $zero, 0x155
    ctx->r4 = ADD32(0, 0X155);
    after_14:
    // 0x80034558: jal         0x8000FFB8
    // 0x8003455C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    free_object(rdram, ctx);
        goto after_15;
    // 0x8003455C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
L_80034560:
    // 0x80034560: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80034564:
    // 0x80034564: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80034568: jr          $ra
    // 0x8003456C: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x8003456C: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void obj_init_lasergun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034570: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x80034574: addiu       $t6, $zero, 0x22
    ctx->r14 = ADD32(0, 0X22);
    // 0x80034578: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x8003457C: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x80034580: nop

    // 0x80034584: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
    // 0x80034588: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x8003458C: lb          $t9, 0xA($a1)
    ctx->r25 = MEM_B(ctx->r5, 0XA);
    // 0x80034590: nop

    // 0x80034594: sb          $t9, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r25;
    // 0x80034598: lb          $t0, 0xB($a1)
    ctx->r8 = MEM_B(ctx->r5, 0XB);
    // 0x8003459C: nop

    // 0x800345A0: sb          $t0, 0xF($v0)
    MEM_B(0XF, ctx->r2) = ctx->r8;
    // 0x800345A4: lbu         $t1, 0xC($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0XC);
    // 0x800345A8: lb          $t3, 0xF($v0)
    ctx->r11 = MEM_B(ctx->r2, 0XF);
    // 0x800345AC: sb          $t1, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r9;
    // 0x800345B0: lbu         $t2, 0xD($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0XD);
    // 0x800345B4: sh          $t3, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r11;
    // 0x800345B8: sb          $t2, 0x11($v0)
    MEM_B(0X11, ctx->r2) = ctx->r10;
    // 0x800345BC: lbu         $t5, 0x8($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X8);
    // 0x800345C0: nop

    // 0x800345C4: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x800345C8: sh          $t6, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r14;
    // 0x800345CC: lbu         $t8, 0x9($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X9);
    // 0x800345D0: nop

    // 0x800345D4: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x800345D8: jr          $ra
    // 0x800345DC: sh          $t9, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r25;
    return;
    // 0x800345DC: sh          $t9, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r25;
;}
RECOMP_FUNC void obj_loop_lasergun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800345E0: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x800345E4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800345E8: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x800345EC: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x800345F0: swc1        $f23, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800345F4: swc1        $f22, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f22.u32l;
    // 0x800345F8: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800345FC: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x80034600: lw          $s1, 0x64($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X64);
    // 0x80034604: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80034608: lh          $v0, 0xC($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XC);
    // 0x8003460C: nop

    // 0x80034610: blez        $v0, L_80034620
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80034614: subu        $t6, $v0, $a1
        ctx->r14 = SUB32(ctx->r2, ctx->r5);
            goto L_80034620;
    }
    // 0x80034614: subu        $t6, $v0, $a1
    ctx->r14 = SUB32(ctx->r2, ctx->r5);
    // 0x80034618: b           L_80034860
    // 0x8003461C: sh          $t6, 0xC($s1)
    MEM_H(0XC, ctx->r17) = ctx->r14;
        goto L_80034860;
    // 0x8003461C: sh          $t6, 0xC($s1)
    MEM_H(0XC, ctx->r17) = ctx->r14;
L_80034620:
    // 0x80034620: lw          $v1, 0x4C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4C);
    // 0x80034624: lbu         $t7, 0x11($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X11);
    // 0x80034628: lbu         $t8, 0x13($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X13);
    // 0x8003462C: nop

    // 0x80034630: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80034634: bne         $at, $zero, L_80034864
    if (ctx->r1 != 0) {
        // 0x80034638: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_80034864;
    }
    // 0x80034638: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8003463C: lb          $t9, 0xE($s1)
    ctx->r25 = MEM_B(ctx->r17, 0XE);
    // 0x80034640: nop

    // 0x80034644: beq         $t9, $zero, L_800346FC
    if (ctx->r25 == 0) {
        // 0x80034648: nop
    
            goto L_800346FC;
    }
    // 0x80034648: nop

    // 0x8003464C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80034650: nop

    // 0x80034654: beq         $v0, $zero, L_800346FC
    if (ctx->r2 == 0) {
        // 0x80034658: nop
    
            goto L_800346FC;
    }
    // 0x80034658: nop

    // 0x8003465C: lh          $t0, 0x48($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X48);
    // 0x80034660: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80034664: bne         $t0, $at, L_800346FC
    if (ctx->r8 != ctx->r1) {
        // 0x80034668: nop
    
            goto L_800346FC;
    }
    // 0x80034668: nop

    // 0x8003466C: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80034670: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80034674: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80034678: sub.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8003467C: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80034680: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x80034684: sub.s       $f22, $f8, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80034688: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003468C: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80034690: mul.s       $f6, $f22, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x80034694: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80034698: swc1        $f14, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f14.u32l;
    // 0x8003469C: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800346A0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800346A4: jal         0x800CA030
    // 0x800346A8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800346A8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x800346AC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800346B0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800346B4: lwc1        $f14, 0x58($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800346B8: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x800346BC: nop

    // 0x800346C0: bc1f        L_800346FC
    if (!c1cs) {
        // 0x800346C4: nop
    
            goto L_800346FC;
    }
    // 0x800346C4: nop

    // 0x800346C8: div.s       $f12, $f20, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800346CC: nop

    // 0x800346D0: div.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = DIV_S(ctx->f22.fl, ctx->f0.fl);
    // 0x800346D4: jal         0x80070990
    // 0x800346D8: div.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
    arctan2_f(rdram, ctx);
        goto after_1;
    // 0x800346D8: div.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
    after_1:
    // 0x800346DC: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x800346E0: addu        $t2, $v0, $at
    ctx->r10 = ADD32(ctx->r2, ctx->r1);
    // 0x800346E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800346E8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800346EC: sh          $t2, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r10;
    // 0x800346F0: jal         0x80070990
    // 0x800346F4: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    arctan2_f(rdram, ctx);
        goto after_2;
    // 0x800346F4: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_2:
    // 0x800346F8: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
L_800346FC:
    // 0x800346FC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80034700: lb          $t4, 0xF($s1)
    ctx->r12 = MEM_B(ctx->r17, 0XF);
    // 0x80034704: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80034708: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003470C: sh          $t4, 0xC($s1)
    MEM_H(0XC, ctx->r17) = ctx->r12;
    // 0x80034710: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80034714: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80034718: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x8003471C: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80034720: addiu       $t2, $zero, 0xC6
    ctx->r10 = ADD32(0, 0XC6);
    // 0x80034724: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80034728: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x8003472C: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80034730: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80034734: sh          $t6, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r14;
    // 0x80034738: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8003473C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80034740: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80034744: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80034748: addiu       $a0, $zero, 0x133
    ctx->r4 = ADD32(0, 0X133);
    // 0x8003474C: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80034750: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80034754: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x80034758: nop

    // 0x8003475C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80034760: sh          $t8, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = ctx->r24;
    // 0x80034764: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80034768: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003476C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80034770: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80034774: sb          $t1, 0x49($sp)
    MEM_B(0X49, ctx->r29) = ctx->r9;
    // 0x80034778: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8003477C: sb          $t2, 0x48($sp)
    MEM_B(0X48, ctx->r29) = ctx->r10;
    // 0x80034780: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x80034784: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80034788: sh          $t0, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r8;
    // 0x8003478C: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x80034790: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x80034794: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x80034798: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8003479C: jal         0x80009558
    // 0x800347A0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_3;
    // 0x800347A0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_3:
    // 0x800347A4: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x800347A8: jal         0x8000EA54
    // 0x800347AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    spawn_object(rdram, ctx);
        goto after_4;
    // 0x800347AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x800347B0: beq         $v0, $zero, L_80034860
    if (ctx->r2 == 0) {
        // 0x800347B4: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80034860;
    }
    // 0x800347B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800347B8: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x800347BC: lh          $t4, 0x0($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X0);
    // 0x800347C0: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800347C4: sh          $t4, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r12;
    // 0x800347C8: lh          $t5, 0x2($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X2);
    // 0x800347CC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800347D0: sh          $t5, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r13;
    // 0x800347D4: lbu         $t6, 0x10($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X10);
    // 0x800347D8: sw          $s1, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r17;
    // 0x800347DC: sw          $t6, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->r14;
    // 0x800347E0: swc1        $f22, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f22.u32l;
    // 0x800347E4: swc1        $f22, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f22.u32l;
    // 0x800347E8: swc1        $f22, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f22.u32l;
    // 0x800347EC: swc1        $f18, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f18.u32l;
    // 0x800347F0: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x800347F4: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x800347F8: sh          $t7, 0xA4($sp)
    MEM_H(0XA4, ctx->r29) = ctx->r15;
    // 0x800347FC: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    // 0x80034800: sh          $zero, 0xA8($sp)
    MEM_H(0XA8, ctx->r29) = 0;
    // 0x80034804: sw          $v0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r2;
    // 0x80034808: addiu       $a1, $sp, 0xA4
    ctx->r5 = ADD32(ctx->r29, 0XA4);
    // 0x8003480C: jal         0x8006FE70
    // 0x80034810: sh          $t8, 0xA6($sp)
    MEM_H(0XA6, ctx->r29) = ctx->r24;
    mtxf_from_transform(rdram, ctx);
        goto after_5;
    // 0x80034810: sh          $t8, 0xA6($sp)
    MEM_H(0XA6, ctx->r29) = ctx->r24;
    after_5:
    // 0x80034814: lb          $t9, 0xE($s1)
    ctx->r25 = MEM_B(ctx->r17, 0XE);
    // 0x80034818: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8003481C: lw          $v1, 0xC0($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XC0);
    // 0x80034820: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80034824: bne         $t9, $zero, L_80034838
    if (ctx->r25 != 0) {
        // 0x80034828: addiu       $a0, $sp, 0x64
        ctx->r4 = ADD32(ctx->r29, 0X64);
            goto L_80034838;
    }
    // 0x80034828: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x8003482C: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80034830: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80034834: nop

L_80034838:
    // 0x80034838: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x8003483C: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80034840: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80034844: addiu       $t0, $v1, 0x1C
    ctx->r8 = ADD32(ctx->r3, 0X1C);
    // 0x80034848: addiu       $t1, $v1, 0x20
    ctx->r9 = ADD32(ctx->r3, 0X20);
    // 0x8003484C: addiu       $t2, $v1, 0x24
    ctx->r10 = ADD32(ctx->r3, 0X24);
    // 0x80034850: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80034854: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80034858: jal         0x8006F88C
    // 0x8003485C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    mtxf_transform_point(rdram, ctx);
        goto after_6;
    // 0x8003485C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_6:
L_80034860:
    // 0x80034860: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80034864:
    // 0x80034864: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80034868: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8003486C: lwc1        $f23, 0x28($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80034870: lwc1        $f22, 0x2C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80034874: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x80034878: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x8003487C: jr          $ra
    // 0x80034880: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    return;
    // 0x80034880: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
;}
RECOMP_FUNC void obj_init_laserbolt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034884: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80034888: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x8003488C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80034890: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x80034894: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x80034898: jr          $ra
    // 0x8003489C: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
    return;
    // 0x8003489C: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
;}
RECOMP_FUNC void obj_loop_laserbolt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800348A0: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x800348A4: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x800348A8: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800348AC: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x800348B0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800348B4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800348B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800348BC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800348C0: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x800348C4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800348C8: bne         $t7, $zero, L_800348E8
    if (ctx->r15 != 0) {
        // 0x800348CC: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_800348E8;
    }
    // 0x800348CC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x800348D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800348D4: lwc1        $f9, 0x6588($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6588);
    // 0x800348D8: lwc1        $f8, 0x658C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X658C);
    // 0x800348DC: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x800348E0: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800348E4: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_800348E8:
    // 0x800348E8: lwc1        $f18, 0x1C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800348EC: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800348F0: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800348F4: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x800348F8: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    // 0x800348FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80034900: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80034904: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x80034908: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    // 0x8003490C: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80034910: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80034914: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80034918: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x8003491C: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80034920: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80034924: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    // 0x80034928: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8003492C: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80034930: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80034934: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x80034938: sb          $t0, 0x4F($sp)
    MEM_B(0X4F, ctx->r29) = ctx->r8;
    // 0x8003493C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80034940: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80034944: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x80034948: jal         0x80031170
    // 0x8003494C: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    generate_collision_candidates(rdram, ctx);
        goto after_0;
    // 0x8003494C: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x80034950: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80034954: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80034958: addiu       $t9, $sp, 0x38
    ctx->r25 = ADD32(ctx->r29, 0X38);
    // 0x8003495C: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x80034960: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80034964: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80034968: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x8003496C: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x80034970: jal         0x80031640
    // 0x80034974: addiu       $a3, $sp, 0x4E
    ctx->r7 = ADD32(ctx->r29, 0X4E);
    resolve_collisions(rdram, ctx);
        goto after_1;
    // 0x80034974: addiu       $a3, $sp, 0x4E
    ctx->r7 = ADD32(ctx->r29, 0X4E);
    after_1:
    // 0x80034978: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8003497C: lb          $t0, 0x4F($sp)
    ctx->r8 = MEM_B(ctx->r29, 0X4F);
    // 0x80034980: lwc1        $f0, 0x5C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80034984: beq         $t1, $zero, L_800349D8
    if (ctx->r9 == 0) {
        // 0x80034988: nop
    
            goto L_800349D8;
    }
    // 0x80034988: nop

    // 0x8003498C: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80034990: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80034994: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80034998: sub.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x8003499C: nop

    // 0x800349A0: div.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800349A4: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
    // 0x800349A8: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800349AC: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800349B0: sub.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x800349B4: nop

    // 0x800349B8: div.s       $f6, $f16, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800349BC: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    // 0x800349C0: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800349C4: nop

    // 0x800349C8: sub.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800349CC: nop

    // 0x800349D0: div.s       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800349D4: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
L_800349D8:
    // 0x800349D8: lwc1        $f16, 0x1C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800349DC: lwc1        $f4, 0x20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800349E0: mul.s       $f6, $f16, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800349E4: lwc1        $f8, 0x24($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800349E8: sb          $t0, 0x4F($sp)
    MEM_B(0X4F, ctx->r29) = ctx->r8;
    // 0x800349EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800349F0: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800349F4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800349F8: mul.s       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800349FC: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80034A00: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80034A04: jal         0x80011570
    // 0x80034A08: nop

    move_object(rdram, ctx);
        goto after_2;
    // 0x80034A08: nop

    after_2:
    // 0x80034A0C: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80034A10: lb          $t0, 0x4F($sp)
    ctx->r8 = MEM_B(ctx->r29, 0X4F);
    // 0x80034A14: beq         $t2, $zero, L_80034A50
    if (ctx->r10 == 0) {
        // 0x80034A18: lui         $at, 0x4210
        ctx->r1 = S32(0X4210 << 16);
            goto L_80034A50;
    }
    // 0x80034A18: lui         $at, 0x4210
    ctx->r1 = S32(0X4210 << 16);
    // 0x80034A1C: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80034A20: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80034A24: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80034A28: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80034A2C: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x80034A30: lwc1        $f4, 0x6590($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6590);
    // 0x80034A34: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80034A38: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80034A3C: addiu       $a3, $zero, 0x2C
    ctx->r7 = ADD32(0, 0X2C);
    // 0x80034A40: sub.s       $f14, $f16, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x80034A44: jal         0x8003FC84
    // 0x80034A48: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    obj_spawn_effect(rdram, ctx);
        goto after_3;
    // 0x80034A48: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x80034A4C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80034A50:
    // 0x80034A50: lw          $v0, 0x78($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X78);
    // 0x80034A54: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x80034A58: blez        $v0, L_80034A68
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80034A5C: subu        $t4, $v0, $t3
        ctx->r12 = SUB32(ctx->r2, ctx->r11);
            goto L_80034A68;
    }
    // 0x80034A5C: subu        $t4, $v0, $t3
    ctx->r12 = SUB32(ctx->r2, ctx->r11);
    // 0x80034A60: b           L_80034A6C
    // 0x80034A64: sw          $t4, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r12;
        goto L_80034A6C;
    // 0x80034A64: sw          $t4, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r12;
L_80034A68:
    // 0x80034A68: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80034A6C:
    // 0x80034A6C: lw          $v1, 0x4C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4C);
    // 0x80034A70: nop

    // 0x80034A74: lbu         $t5, 0x13($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X13);
    // 0x80034A78: nop

    // 0x80034A7C: slti        $at, $t5, 0x50
    ctx->r1 = SIGNED(ctx->r13) < 0X50 ? 1 : 0;
    // 0x80034A80: beq         $at, $zero, L_80034B10
    if (ctx->r1 == 0) {
        // 0x80034A84: nop
    
            goto L_80034B10;
    }
    // 0x80034A84: nop

    // 0x80034A88: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80034A8C: nop

    // 0x80034A90: beq         $v0, $zero, L_80034B10
    if (ctx->r2 == 0) {
        // 0x80034A94: nop
    
            goto L_80034B10;
    }
    // 0x80034A94: nop

    // 0x80034A98: lh          $t6, 0x48($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X48);
    // 0x80034A9C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80034AA0: bne         $a0, $t6, L_80034B10
    if (ctx->r4 != ctx->r14) {
        // 0x80034AA4: addiu       $a3, $zero, 0x2C
        ctx->r7 = ADD32(0, 0X2C);
            goto L_80034B10;
    }
    // 0x80034AA4: addiu       $a3, $zero, 0x2C
    ctx->r7 = ADD32(0, 0X2C);
    // 0x80034AA8: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x80034AAC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80034AB0: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x80034AB4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80034AB8: beq         $t7, $at, L_80034AC4
    if (ctx->r15 == ctx->r1) {
        // 0x80034ABC: addiu       $t9, $zero, 0x11
        ctx->r25 = ADD32(0, 0X11);
            goto L_80034AC4;
    }
    // 0x80034ABC: addiu       $t9, $zero, 0x11
    ctx->r25 = ADD32(0, 0X11);
    // 0x80034AC0: sb          $a0, 0x187($v1)
    MEM_B(0X187, ctx->r3) = ctx->r4;
L_80034AC4:
    // 0x80034AC4: lw          $v0, 0x7C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X7C);
    // 0x80034AC8: addiu       $t8, $zero, 0xB4
    ctx->r24 = ADD32(0, 0XB4);
    // 0x80034ACC: beq         $v0, $zero, L_80034AD8
    if (ctx->r2 == 0) {
        // 0x80034AD0: lui         $at, 0x4210
        ctx->r1 = S32(0X4210 << 16);
            goto L_80034AD8;
    }
    // 0x80034AD0: lui         $at, 0x4210
    ctx->r1 = S32(0X4210 << 16);
    // 0x80034AD4: sh          $t8, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r24;
L_80034AD8:
    // 0x80034AD8: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80034ADC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80034AE0: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80034AE4: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x80034AE8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80034AEC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80034AF0: sb          $t0, 0x4F($sp)
    MEM_B(0X4F, ctx->r29) = ctx->r8;
    // 0x80034AF4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80034AF8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80034AFC: sub.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80034B00: jal         0x8003FC84
    // 0x80034B04: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    obj_spawn_effect(rdram, ctx);
        goto after_4;
    // 0x80034B04: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_4:
    // 0x80034B08: lb          $t0, 0x4F($sp)
    ctx->r8 = MEM_B(ctx->r29, 0X4F);
    // 0x80034B0C: nop

L_80034B10:
    // 0x80034B10: beq         $t0, $zero, L_80034B24
    if (ctx->r8 == 0) {
        // 0x80034B14: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80034B24;
    }
    // 0x80034B14: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80034B18: jal         0x8000FFB8
    // 0x80034B1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    free_object(rdram, ctx);
        goto after_5;
    // 0x80034B1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80034B20: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80034B24:
    // 0x80034B24: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80034B28: jr          $ra
    // 0x80034B2C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80034B2C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void obj_init_torch_mist(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034B30: lbu         $t7, 0x9($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X9);
    // 0x80034B34: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80034B38: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80034B3C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80034B40: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80034B44: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80034B48: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80034B4C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80034B50: nop

    // 0x80034B54: bc1f        L_80034B64
    if (!c1cs) {
        // 0x80034B58: nop
    
            goto L_80034B64;
    }
    // 0x80034B58: nop

    // 0x80034B5C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80034B60: nop

L_80034B64:
    // 0x80034B64: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80034B68: lw          $t8, 0x40($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X40);
    // 0x80034B6C: nop

    // 0x80034B70: lwc1        $f8, 0xC($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XC);
    // 0x80034B74: nop

    // 0x80034B78: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80034B7C: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
    // 0x80034B80: lbu         $t9, 0x8($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X8);
    // 0x80034B84: jr          $ra
    // 0x80034B88: sw          $t9, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r25;
    return;
    // 0x80034B88: sw          $t9, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r25;
;}
RECOMP_FUNC void obj_loop_torch_mist(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034B8C: lw          $t7, 0x78($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X78);
    // 0x80034B90: lh          $t6, 0x18($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X18);
    // 0x80034B94: multu       $t7, $a1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80034B98: mflo        $t8
    ctx->r24 = lo;
    // 0x80034B9C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80034BA0: jr          $ra
    // 0x80034BA4: sh          $t9, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r25;
    return;
    // 0x80034BA4: sh          $t9, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r25;
;}
RECOMP_FUNC void obj_init_effectbox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034BA8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80034BAC: jr          $ra
    // 0x80034BB0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x80034BB0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void obj_loop_effectbox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034BB4: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80034BB8: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80034BBC: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80034BC0: swc1        $f31, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x80034BC4: swc1        $f30, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f30.u32l;
    // 0x80034BC8: swc1        $f29, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x80034BCC: swc1        $f28, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f28.u32l;
    // 0x80034BD0: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x80034BD4: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x80034BD8: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80034BDC: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x80034BE0: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80034BE4: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x80034BE8: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80034BEC: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80034BF0: sw          $a1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r5;
    // 0x80034BF4: lw          $s0, 0x3C($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X3C);
    // 0x80034BF8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80034BFC: sw          $a2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r6;
    // 0x80034C00: jal         0x8001BAA8
    // 0x80034C04: addiu       $a0, $sp, 0x8C
    ctx->r4 = ADD32(ctx->r29, 0X8C);
    get_racer_objects(rdram, ctx);
        goto after_0;
    // 0x80034C04: addiu       $a0, $sp, 0x8C
    ctx->r4 = ADD32(ctx->r29, 0X8C);
    after_0:
    // 0x80034C08: sw          $v0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r2;
    // 0x80034C0C: lbu         $a0, 0xB($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XB);
    // 0x80034C10: nop

    // 0x80034C14: sll         $t6, $a0, 8
    ctx->r14 = S32(ctx->r4 << 8);
    // 0x80034C18: negu        $a0, $t6
    ctx->r4 = SUB32(0, ctx->r14);
    // 0x80034C1C: sll         $t7, $a0, 16
    ctx->r15 = S32(ctx->r4 << 16);
    // 0x80034C20: jal         0x80070A38
    // 0x80034C24: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    coss_f(rdram, ctx);
        goto after_1;
    // 0x80034C24: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    after_1:
    // 0x80034C28: lbu         $a0, 0xB($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XB);
    // 0x80034C2C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80034C30: sll         $t9, $a0, 8
    ctx->r25 = S32(ctx->r4 << 8);
    // 0x80034C34: negu        $a0, $t9
    ctx->r4 = SUB32(0, ctx->r25);
    // 0x80034C38: sll         $t0, $a0, 16
    ctx->r8 = S32(ctx->r4 << 16);
    // 0x80034C3C: jal         0x80070A04
    // 0x80034C40: sra         $a0, $t0, 16
    ctx->r4 = S32(SIGNED(ctx->r8) >> 16);
    sins_f(rdram, ctx);
        goto after_2;
    // 0x80034C40: sra         $a0, $t0, 16
    ctx->r4 = S32(SIGNED(ctx->r8) >> 16);
    after_2:
    // 0x80034C44: lbu         $t2, 0x8($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X8);
    // 0x80034C48: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80034C4C: multu       $t2, $v0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80034C50: lbu         $t4, 0x9($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X9);
    // 0x80034C54: lbu         $t6, 0xA($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XA);
    // 0x80034C58: lw          $t8, 0x8C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8C);
    // 0x80034C5C: lw          $a2, 0x98($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X98);
    // 0x80034C60: lw          $a1, 0x94($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X94);
    // 0x80034C64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80034C68: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80034C6C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80034C70: mflo        $t3
    ctx->r11 = lo;
    // 0x80034C74: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80034C78: nop

    // 0x80034C7C: multu       $t4, $v0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80034C80: cvt.s.w     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    ctx->f22.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80034C84: mflo        $t5
    ctx->r13 = lo;
    // 0x80034C88: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x80034C8C: nop

    // 0x80034C90: multu       $t6, $v0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80034C94: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80034C98: mflo        $t7
    ctx->r15 = lo;
    // 0x80034C9C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80034CA0: blez        $t8, L_80034E70
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80034CA4: cvt.s.w     $f24, $f8
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    ctx->f24.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80034E70;
    }
    // 0x80034CA4: cvt.s.w     $f24, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    ctx->f24.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80034CA8: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x80034CAC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80034CB0: mtc1        $at, $f27
    ctx->f_odd[(27 - 1) * 2] = ctx->r1;
    // 0x80034CB4: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x80034CB8: neg.s       $f28, $f18
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f28.fl = -ctx->f18.fl;
L_80034CBC:
    // 0x80034CBC: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80034CC0: lwc1        $f4, 0xC($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80034CC4: lwc1        $f8, 0x10($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X10);
    // 0x80034CC8: lwc1        $f10, 0xC($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80034CCC: lwc1        $f6, 0x10($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80034CD0: sub.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80034CD4: lwc1        $f4, 0x14($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X14);
    // 0x80034CD8: sub.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80034CDC: lwc1        $f10, 0x14($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80034CE0: c.lt.s      $f28, $f2
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f28.fl < ctx->f2.fl;
    // 0x80034CE4: sub.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80034CE8: bc1f        L_80034E64
    if (!c1cs) {
        // 0x80034CEC: lw          $t5, 0x8C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X8C);
            goto L_80034E64;
    }
    // 0x80034CEC: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
    // 0x80034CF0: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x80034CF4: nop

    // 0x80034CF8: bc1f        L_80034E64
    if (!c1cs) {
        // 0x80034CFC: lw          $t5, 0x8C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X8C);
            goto L_80034E64;
    }
    // 0x80034CFC: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
    // 0x80034D00: mul.s       $f6, $f14, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x80034D04: neg.s       $f10, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = -ctx->f22.fl;
    // 0x80034D08: mul.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80034D0C: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80034D10: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80034D14: nop

    // 0x80034D18: bc1f        L_80034E64
    if (!c1cs) {
        // 0x80034D1C: lw          $t5, 0x8C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X8C);
            goto L_80034E64;
    }
    // 0x80034D1C: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
    // 0x80034D20: c.lt.s      $f16, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f16.fl < ctx->f22.fl;
    // 0x80034D24: nop

    // 0x80034D28: bc1f        L_80034E64
    if (!c1cs) {
        // 0x80034D2C: lw          $t5, 0x8C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X8C);
            goto L_80034E64;
    }
    // 0x80034D2C: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
    // 0x80034D30: neg.s       $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = -ctx->f14.fl;
    // 0x80034D34: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80034D38: neg.s       $f10, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = -ctx->f24.fl;
    // 0x80034D3C: mul.s       $f8, $f12, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x80034D40: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80034D44: c.lt.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl < ctx->f12.fl;
    // 0x80034D48: nop

    // 0x80034D4C: bc1f        L_80034E64
    if (!c1cs) {
        // 0x80034D50: lw          $t5, 0x8C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X8C);
            goto L_80034E64;
    }
    // 0x80034D50: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
    // 0x80034D54: c.lt.s      $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f12.fl < ctx->f24.fl;
    // 0x80034D58: nop

    // 0x80034D5C: bc1f        L_80034E60
    if (!c1cs) {
        // 0x80034D60: nop
    
            goto L_80034E60;
    }
    // 0x80034D60: nop

    // 0x80034D64: div.s       $f12, $f18, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f12.fl = DIV_S(ctx->f18.fl, ctx->f30.fl);
    // 0x80034D68: lw          $v0, 0x64($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X64);
    // 0x80034D6C: lbu         $t9, 0xC($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0XC);
    // 0x80034D70: nop

    // 0x80034D74: sb          $t9, 0x1FE($v0)
    MEM_B(0X1FE, ctx->r2) = ctx->r25;
    // 0x80034D78: lbu         $t0, 0xD($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0XD);
    // 0x80034D7C: andi        $t1, $t9, 0xFF
    ctx->r9 = ctx->r25 & 0XFF;
    // 0x80034D80: sb          $t0, 0x1FF($v0)
    MEM_B(0X1FF, ctx->r2) = ctx->r8;
    // 0x80034D84: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80034D88: nop

    // 0x80034D8C: bc1f        L_80034E64
    if (!c1cs) {
        // 0x80034D90: lw          $t5, 0x8C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X8C);
            goto L_80034E64;
    }
    // 0x80034D90: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
    // 0x80034D94: bne         $a3, $t1, L_80034E64
    if (ctx->r7 != ctx->r9) {
        // 0x80034D98: lw          $t5, 0x8C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X8C);
            goto L_80034E64;
    }
    // 0x80034D98: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
    // 0x80034D9C: sub.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x80034DA0: andi        $t2, $t0, 0xFF
    ctx->r10 = ctx->r8 & 0XFF;
    // 0x80034DA4: div.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80034DA8: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80034DAC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80034DB0: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80034DB4: sub.d       $f10, $f26, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f26.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f26.d - ctx->f8.d;
    // 0x80034DB8: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
    // 0x80034DBC: bgez        $t2, L_80034DD0
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80034DC0: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80034DD0;
    }
    // 0x80034DC0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80034DC4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80034DC8: nop

    // 0x80034DCC: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80034DD0:
    // 0x80034DD0: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80034DD4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80034DD8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80034DDC: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80034DE0: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80034DE4: nop

    // 0x80034DE8: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80034DEC: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80034DF0: nop

    // 0x80034DF4: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x80034DF8: beq         $t4, $zero, L_80034E44
    if (ctx->r12 == 0) {
        // 0x80034DFC: nop
    
            goto L_80034E44;
    }
    // 0x80034DFC: nop

    // 0x80034E00: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80034E04: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80034E08: sub.s       $f4, $f10, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80034E0C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80034E10: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80034E14: nop

    // 0x80034E18: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80034E1C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80034E20: nop

    // 0x80034E24: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x80034E28: bne         $t4, $zero, L_80034E3C
    if (ctx->r12 != 0) {
        // 0x80034E2C: nop
    
            goto L_80034E3C;
    }
    // 0x80034E2C: nop

    // 0x80034E30: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x80034E34: b           L_80034E54
    // 0x80034E38: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_80034E54;
    // 0x80034E38: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_80034E3C:
    // 0x80034E3C: b           L_80034E54
    // 0x80034E40: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_80034E54;
    // 0x80034E40: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
L_80034E44:
    // 0x80034E44: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x80034E48: nop

    // 0x80034E4C: bltz        $t4, L_80034E3C
    if (SIGNED(ctx->r12) < 0) {
        // 0x80034E50: nop
    
            goto L_80034E3C;
    }
    // 0x80034E50: nop

L_80034E54:
    // 0x80034E54: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80034E58: sb          $t4, 0x1FF($v0)
    MEM_B(0X1FF, ctx->r2) = ctx->r12;
    // 0x80034E5C: nop

L_80034E60:
    // 0x80034E60: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
L_80034E64:
    // 0x80034E64: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80034E68: bne         $a0, $t5, L_80034CBC
    if (ctx->r4 != ctx->r13) {
        // 0x80034E6C: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80034CBC;
    }
    // 0x80034E6C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_80034E70:
    // 0x80034E70: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80034E74: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80034E78: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80034E7C: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80034E80: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80034E84: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80034E88: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80034E8C: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80034E90: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80034E94: lwc1        $f29, 0x38($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x80034E98: lwc1        $f28, 0x3C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80034E9C: lwc1        $f31, 0x40($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x80034EA0: lwc1        $f30, 0x44($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80034EA4: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80034EA8: jr          $ra
    // 0x80034EAC: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x80034EAC: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void obj_init_trophycab(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034EB0: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x80034EB4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80034EB8: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x80034EBC: lw          $t9, 0x4C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4C);
    // 0x80034EC0: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80034EC4: sb          $t8, 0x11($t9)
    MEM_B(0X11, ctx->r25) = ctx->r24;
    // 0x80034EC8: lbu         $t1, 0x8($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X8);
    // 0x80034ECC: nop

    // 0x80034ED0: sll         $t2, $t1, 10
    ctx->r10 = S32(ctx->r9 << 10);
    // 0x80034ED4: jr          $ra
    // 0x80034ED8: sh          $t2, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r10;
    return;
    // 0x80034ED8: sh          $t2, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r10;
;}
RECOMP_FUNC void obj_loop_trophycab(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034EDC: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80034EE0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80034EE4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80034EE8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80034EEC: jal         0x8006ECD0
    // 0x80034EF0: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x80034EF0: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80034EF4: jal         0x8006BFF0
    // 0x80034EF8: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    level_header(rdram, ctx);
        goto after_1;
    // 0x80034EF8: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    after_1:
    // 0x80034EFC: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x80034F00: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x80034F04: sw          $t6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r14;
    // 0x80034F08: lw          $t7, 0x7C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X7C);
    // 0x80034F0C: nop

    // 0x80034F10: bne         $t7, $zero, L_80034FB8
    if (ctx->r15 != 0) {
        // 0x80034F14: nop
    
            goto L_80034FB8;
    }
    // 0x80034F14: nop

    // 0x80034F18: lb          $a0, 0x4C($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X4C);
    // 0x80034F1C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80034F20: beq         $a0, $at, L_80034FB8
    if (ctx->r4 == ctx->r1) {
        // 0x80034F24: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80034FB8;
    }
    // 0x80034F24: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80034F28: beq         $a0, $at, L_80034FB8
    if (ctx->r4 == ctx->r1) {
        // 0x80034F2C: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_80034FB8;
    }
    // 0x80034F2C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80034F30: sw          $t8, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r24;
    // 0x80034F34: lbu         $t0, 0x48($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X48);
    // 0x80034F38: lhu         $t9, 0xE($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0XE);
    // 0x80034F3C: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80034F40: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x80034F44: srav        $t3, $t9, $t2
    ctx->r11 = S32(SIGNED(ctx->r25) >> (ctx->r10 & 31));
    // 0x80034F48: andi        $t4, $t3, 0x3
    ctx->r12 = ctx->r11 & 0X3;
    // 0x80034F4C: beq         $t4, $zero, L_80034FB8
    if (ctx->r12 == 0) {
        // 0x80034F50: addiu       $t5, $zero, 0x80
        ctx->r13 = ADD32(0, 0X80);
            goto L_80034FB8;
    }
    // 0x80034F50: addiu       $t5, $zero, 0x80
    ctx->r13 = ADD32(0, 0X80);
    // 0x80034F54: sb          $t5, 0x44($sp)
    MEM_B(0X44, ctx->r29) = ctx->r13;
    // 0x80034F58: lw          $t6, 0x3C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X3C);
    // 0x80034F5C: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x80034F60: lh          $t7, 0x2($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X2);
    // 0x80034F64: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80034F68: sh          $t7, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r15;
    // 0x80034F6C: lw          $t8, 0x3C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X3C);
    // 0x80034F70: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80034F74: lh          $t0, 0x4($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X4);
    // 0x80034F78: nop

    // 0x80034F7C: sh          $t0, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r8;
    // 0x80034F80: lw          $t1, 0x3C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X3C);
    // 0x80034F84: nop

    // 0x80034F88: lh          $t9, 0x6($t1)
    ctx->r25 = MEM_H(ctx->r9, 0X6);
    // 0x80034F8C: sb          $t2, 0x45($sp)
    MEM_B(0X45, ctx->r29) = ctx->r10;
    // 0x80034F90: sw          $v1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r3;
    // 0x80034F94: jal         0x8000EA54
    // 0x80034F98: sh          $t9, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r25;
    spawn_object(rdram, ctx);
        goto after_2;
    // 0x80034F98: sh          $t9, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r25;
    after_2:
    // 0x80034F9C: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x80034FA0: beq         $v0, $zero, L_80034FB8
    if (ctx->r2 == 0) {
        // 0x80034FA4: nop
    
            goto L_80034FB8;
    }
    // 0x80034FA4: nop

    // 0x80034FA8: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x80034FAC: lh          $t3, 0x0($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X0);
    // 0x80034FB0: nop

    // 0x80034FB4: sh          $t3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r11;
L_80034FB8:
    // 0x80034FB8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80034FBC: lwc1        $f4, 0x6594($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6594);
    // 0x80034FC0: lw          $t4, 0x54($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X54);
    // 0x80034FC4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80034FC8: swc1        $f4, 0x2C($t4)
    MEM_W(0X2C, ctx->r12) = ctx->f4.u32l;
    // 0x80034FCC: lw          $t5, 0x54($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X54);
    // 0x80034FD0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80034FD4: swc1        $f6, 0x28($t5)
    MEM_W(0X28, ctx->r13) = ctx->f6.u32l;
    // 0x80034FD8: jal         0x8001BAFC
    // 0x80034FDC: sw          $v1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r3;
    get_racer_object(rdram, ctx);
        goto after_3;
    // 0x80034FDC: sw          $v1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r3;
    after_3:
    // 0x80034FE0: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x80034FE4: beq         $v0, $zero, L_80035260
    if (ctx->r2 == 0) {
        // 0x80034FE8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80035260;
    }
    // 0x80034FE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80034FEC: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80034FF0: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80034FF4: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80034FF8: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80034FFC: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80035000: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80035004: sub.s       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80035008: sw          $v1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r3;
    // 0x8003500C: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80035010: jal         0x800CA030
    // 0x80035014: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_4;
    // 0x80035014: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_4:
    // 0x80035018: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x8003501C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80035020: lbu         $a0, 0x48($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X48);
    // 0x80035024: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80035028: sll         $t8, $a0, 1
    ctx->r24 = S32(ctx->r4 << 1);
    // 0x8003502C: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x80035030: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x80035034: lhu         $v0, 0xC($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0XC);
    // 0x80035038: slti        $t9, $t1, 0x8
    ctx->r25 = SIGNED(ctx->r9) < 0X8 ? 1 : 0;
    // 0x8003503C: xori        $t9, $t9, 0x1
    ctx->r25 = ctx->r25 ^ 0X1;
    // 0x80035040: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x80035044: beq         $t9, $zero, L_80035060
    if (ctx->r25 == 0) {
        // 0x80035048: ori         $t6, $v0, 0x800
        ctx->r14 = ctx->r2 | 0X800;
            goto L_80035060;
    }
    // 0x80035048: ori         $t6, $v0, 0x800
    ctx->r14 = ctx->r2 | 0X800;
    // 0x8003504C: addiu       $t3, $a0, 0x6
    ctx->r11 = ADD32(ctx->r4, 0X6);
    // 0x80035050: sllv        $t5, $t4, $t3
    ctx->r13 = S32(ctx->r12 << (ctx->r11 & 31));
    // 0x80035054: and         $t6, $t5, $t6
    ctx->r14 = ctx->r13 & ctx->r14;
    // 0x80035058: sltu        $t7, $zero, $t6
    ctx->r15 = 0 < ctx->r14 ? 1 : 0;
    // 0x8003505C: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
L_80035060:
    // 0x80035060: lw          $t8, 0x78($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X78);
    // 0x80035064: nop

    // 0x80035068: bne         $t8, $zero, L_80035108
    if (ctx->r24 != 0) {
        // 0x8003506C: lw          $v1, 0x50($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X50);
            goto L_80035108;
    }
    // 0x8003506C: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x80035070: jal         0x800C3958
    // 0x80035074: nop

    textbox_visible(rdram, ctx);
        goto after_5;
    // 0x80035074: nop

    after_5:
    // 0x80035078: bne         $v0, $zero, L_80035108
    if (ctx->r2 != 0) {
        // 0x8003507C: lw          $v1, 0x50($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X50);
            goto L_80035108;
    }
    // 0x8003507C: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x80035080: lw          $t0, 0x5C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X5C);
    // 0x80035084: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x80035088: lw          $t1, 0x100($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X100);
    // 0x8003508C: nop

    // 0x80035090: beq         $t1, $zero, L_80035104
    if (ctx->r9 == 0) {
        // 0x80035094: nop
    
            goto L_80035104;
    }
    // 0x80035094: nop

    // 0x80035098: lh          $t9, 0x4($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X4);
    // 0x8003509C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800350A0: bne         $t9, $zero, L_80035108
    if (ctx->r25 != 0) {
        // 0x800350A4: lw          $v1, 0x50($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X50);
            goto L_80035108;
    }
    // 0x800350A4: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x800350A8: beq         $t2, $zero, L_800350D0
    if (ctx->r10 == 0) {
        // 0x800350AC: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_800350D0;
    }
    // 0x800350AC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800350B0: sw          $t4, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r12;
    // 0x800350B4: addiu       $a0, $zero, 0x12F
    ctx->r4 = ADD32(0, 0X12F);
    // 0x800350B8: jal         0x80001D04
    // 0x800350BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_6;
    // 0x800350BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x800350C0: jal         0x800A3DB8
    // 0x800350C4: nop

    hud_speedometre_reset(rdram, ctx);
        goto after_7;
    // 0x800350C4: nop

    after_7:
    // 0x800350C8: b           L_80035108
    // 0x800350CC: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
        goto L_80035108;
    // 0x800350CC: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
L_800350D0:
    // 0x800350D0: jal         0x800C3744
    // 0x800350D4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    set_current_text(rdram, ctx);
        goto after_8;
    // 0x800350D4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_8:
    // 0x800350D8: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x800350DC: addiu       $t3, $zero, 0xB4
    ctx->r11 = ADD32(0, 0XB4);
    // 0x800350E0: addiu       $t6, $zero, 0x8C
    ctx->r14 = ADD32(0, 0X8C);
    // 0x800350E4: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x800350E8: sh          $t3, 0x4($t5)
    MEM_H(0X4, ctx->r13) = ctx->r11;
    // 0x800350EC: jal         0x80000C38
    // 0x800350F0: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    music_jingle_voicelimit_set(rdram, ctx);
        goto after_9;
    // 0x800350F0: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    after_9:
    // 0x800350F4: jal         0x80000C98
    // 0x800350F8: addiu       $a0, $zero, -0x8
    ctx->r4 = ADD32(0, -0X8);
    music_fade(rdram, ctx);
        goto after_10;
    // 0x800350F8: addiu       $a0, $zero, -0x8
    ctx->r4 = ADD32(0, -0X8);
    after_10:
    // 0x800350FC: jal         0x80001BC0
    // 0x80035100: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    music_jingle_play(rdram, ctx);
        goto after_11;
    // 0x80035100: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_11:
L_80035104:
    // 0x80035104: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
L_80035108:
    // 0x80035108: nop

    // 0x8003510C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80035110: nop

    // 0x80035114: beq         $t7, $zero, L_80035164
    if (ctx->r15 == 0) {
        // 0x80035118: nop
    
            goto L_80035164;
    }
    // 0x80035118: nop

    // 0x8003511C: jal         0x80001C08
    // 0x80035120: nop

    music_jingle_playing(rdram, ctx);
        goto after_12;
    // 0x80035120: nop

    after_12:
    // 0x80035124: bne         $v0, $zero, L_80035164
    if (ctx->r2 != 0) {
        // 0x80035128: nop
    
            goto L_80035164;
    }
    // 0x80035128: nop

    // 0x8003512C: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80035130: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x80035134: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x80035138: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8003513C: slt         $at, $t0, $v0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80035140: beq         $at, $zero, L_80035154
    if (ctx->r1 == 0) {
        // 0x80035144: addiu       $a0, $zero, 0x8
        ctx->r4 = ADD32(0, 0X8);
            goto L_80035154;
    }
    // 0x80035144: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80035148: subu        $t1, $v0, $t0
    ctx->r9 = SUB32(ctx->r2, ctx->r8);
    // 0x8003514C: b           L_80035164
    // 0x80035150: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
        goto L_80035164;
    // 0x80035150: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
L_80035154:
    // 0x80035154: jal         0x80000C98
    // 0x80035158: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    music_fade(rdram, ctx);
        goto after_13;
    // 0x80035158: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    after_13:
    // 0x8003515C: jal         0x80000C38
    // 0x80035160: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    music_jingle_voicelimit_set(rdram, ctx);
        goto after_14;
    // 0x80035160: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_14:
L_80035164:
    // 0x80035164: lw          $t2, 0x5C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X5C);
    // 0x80035168: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x8003516C: lw          $t4, 0x100($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X100);
    // 0x80035170: nop

    // 0x80035174: bne         $t4, $zero, L_80035198
    if (ctx->r12 != 0) {
        // 0x80035178: addiu       $t3, $zero, 0xB4
        ctx->r11 = ADD32(0, 0XB4);
            goto L_80035198;
    }
    // 0x80035178: addiu       $t3, $zero, 0xB4
    ctx->r11 = ADD32(0, 0XB4);
    // 0x8003517C: jal         0x800C3958
    // 0x80035180: nop

    textbox_visible(rdram, ctx);
        goto after_15;
    // 0x80035180: nop

    after_15:
    // 0x80035184: beq         $v0, $zero, L_800351A0
    if (ctx->r2 == 0) {
        // 0x80035188: lw          $v1, 0x50($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X50);
            goto L_800351A0;
    }
    // 0x80035188: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x8003518C: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x80035190: nop

    // 0x80035194: addiu       $t3, $zero, 0xB4
    ctx->r11 = ADD32(0, 0XB4);
L_80035198:
    // 0x80035198: sh          $t3, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r11;
    // 0x8003519C: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
L_800351A0:
    // 0x800351A0: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x800351A4: lh          $v0, 0x4($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X4);
    // 0x800351A8: nop

    // 0x800351AC: blez        $v0, L_800351BC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800351B0: subu        $t5, $v0, $t6
        ctx->r13 = SUB32(ctx->r2, ctx->r14);
            goto L_800351BC;
    }
    // 0x800351B0: subu        $t5, $v0, $t6
    ctx->r13 = SUB32(ctx->r2, ctx->r14);
    // 0x800351B4: b           L_800351C0
    // 0x800351B8: sh          $t5, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r13;
        goto L_800351C0;
    // 0x800351B8: sh          $t5, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r13;
L_800351BC:
    // 0x800351BC: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
L_800351C0:
    // 0x800351C0: lw          $t7, 0x78($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X78);
    // 0x800351C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800351C8: bne         $t7, $at, L_80035230
    if (ctx->r15 != ctx->r1) {
        // 0x800351CC: nop
    
            goto L_80035230;
    }
    // 0x800351CC: nop

    // 0x800351D0: jal         0x800AB708
    // 0x800351D4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    minimap_opacity_set(rdram, ctx);
        goto after_16;
    // 0x800351D4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_16:
    // 0x800351D8: jal         0x800AB730
    // 0x800351DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    hud_visibility(rdram, ctx);
        goto after_17;
    // 0x800351DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_17:
    // 0x800351E0: jal         0x8009D530
    // 0x800351E4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    npc_dialogue_loop(rdram, ctx);
        goto after_18;
    // 0x800351E4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_18:
    // 0x800351E8: beq         $v0, $zero, L_80035228
    if (ctx->r2 == 0) {
        // 0x800351EC: addiu       $a0, $zero, 0x4
        ctx->r4 = ADD32(0, 0X4);
            goto L_80035228;
    }
    // 0x800351EC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800351F0: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
    // 0x800351F4: jal         0x8009D4AC
    // 0x800351F8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    dialogue_npc_finish(rdram, ctx);
        goto after_19;
    // 0x800351F8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_19:
    // 0x800351FC: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80035200: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80035204: bne         $v1, $at, L_80035220
    if (ctx->r3 != ctx->r1) {
        // 0x80035208: nop
    
            goto L_80035220;
    }
    // 0x80035208: nop

    // 0x8003520C: jal         0x8006F494
    // 0x80035210: nop

    begin_trophy_race_teleport(rdram, ctx);
        goto after_20;
    // 0x80035210: nop

    after_20:
    // 0x80035214: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80035218: b           L_80035228
    // 0x8003521C: sw          $t0, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r8;
        goto L_80035228;
    // 0x8003521C: sw          $t0, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r8;
L_80035220:
    // 0x80035220: jal         0x800AB730
    // 0x80035224: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    hud_visibility(rdram, ctx);
        goto after_21;
    // 0x80035224: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_21:
L_80035228:
    // 0x80035228: jal         0x8005A41C
    // 0x8003522C: nop

    disable_racer_input(rdram, ctx);
        goto after_22;
    // 0x8003522C: nop

    after_22:
L_80035230:
    // 0x80035230: lw          $t1, 0x5C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X5C);
    // 0x80035234: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80035238: sw          $zero, 0x100($t1)
    MEM_W(0X100, ctx->r9) = 0;
    // 0x8003523C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80035240: nop

    // 0x80035244: beq         $t8, $zero, L_80035260
    if (ctx->r24 == 0) {
        // 0x80035248: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80035260;
    }
    // 0x80035248: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003524C: lwc1        $f8, 0x6598($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6598);
    // 0x80035250: lw          $t9, 0x54($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X54);
    // 0x80035254: nop

    // 0x80035258: swc1        $f8, 0x28($t9)
    MEM_W(0X28, ctx->r25) = ctx->f8.u32l;
    // 0x8003525C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80035260:
    // 0x80035260: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80035264: jr          $ra
    // 0x80035268: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80035268: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void obj_init_collectegg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003526C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80035270: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x80035274: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80035278: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x8003527C: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x80035280: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x80035284: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
    // 0x80035288: lw          $t0, 0x4C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4C);
    // 0x8003528C: nop

    // 0x80035290: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x80035294: lw          $t1, 0x4C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4C);
    // 0x80035298: jr          $ra
    // 0x8003529C: sb          $zero, 0x12($t1)
    MEM_B(0X12, ctx->r9) = 0;
    return;
    // 0x8003529C: sb          $zero, 0x12($t1)
    MEM_B(0X12, ctx->r9) = 0;
;}
RECOMP_FUNC void obj_loop_collectegg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800352A0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800352A4: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x800352A8: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x800352AC: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800352B0: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x800352B4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800352B8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800352BC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800352C0: lw          $s1, 0x64($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X64);
    // 0x800352C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800352C8: bne         $t6, $zero, L_800352E8
    if (ctx->r14 != 0) {
        // 0x800352CC: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_800352E8;
    }
    // 0x800352CC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x800352D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800352D4: lwc1        $f9, 0x65A0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X65A0);
    // 0x800352D8: lwc1        $f8, 0x65A4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X65A4);
    // 0x800352DC: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x800352E0: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800352E4: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_800352E8:
    // 0x800352E8: lb          $v0, 0xB($s1)
    ctx->r2 = MEM_B(ctx->r17, 0XB);
    // 0x800352EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800352F0: beq         $v0, $zero, L_8003531C
    if (ctx->r2 == 0) {
        // 0x800352F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8003531C;
    }
    // 0x800352F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800352F8: beq         $v0, $at, L_8003532C
    if (ctx->r2 == ctx->r1) {
        // 0x800352FC: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8003532C;
    }
    // 0x800352FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80035300: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80035304: beq         $v0, $at, L_8003557C
    if (ctx->r2 == ctx->r1) {
        // 0x80035308: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8003557C;
    }
    // 0x80035308: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8003530C: beq         $v0, $at, L_80035634
    if (ctx->r2 == ctx->r1) {
        // 0x80035310: nop
    
            goto L_80035634;
    }
    // 0x80035310: nop

    // 0x80035314: b           L_80035670
    // 0x80035318: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80035670;
    // 0x80035318: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8003531C:
    // 0x8003531C: jal         0x80036080
    // 0x80035320: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    try_to_collect_egg(rdram, ctx);
        goto after_0;
    // 0x80035320: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x80035324: b           L_80035670
    // 0x80035328: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80035670;
    // 0x80035328: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8003532C:
    // 0x8003532C: lwc1        $f18, 0x1C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80035330: lh          $t7, 0x6($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X6);
    // 0x80035334: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80035338: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003533C: andi        $t8, $t7, 0xBFFF
    ctx->r24 = ctx->r15 & 0XBFFF;
    // 0x80035340: sh          $t8, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r24;
    // 0x80035344: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80035348: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x8003534C: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    // 0x80035350: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80035354: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80035358: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8003535C: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    // 0x80035360: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x80035364: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x80035368: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8003536C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80035370: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    // 0x80035374: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80035378: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003537C: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80035380: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80035384: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80035388: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x8003538C: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80035390: jal         0x80031170
    // 0x80035394: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    generate_collision_candidates(rdram, ctx);
        goto after_1;
    // 0x80035394: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x80035398: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8003539C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800353A0: addiu       $t0, $sp, 0x34
    ctx->r8 = ADD32(ctx->r29, 0X34);
    // 0x800353A4: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x800353A8: sb          $zero, 0x33($sp)
    MEM_B(0X33, ctx->r29) = 0;
    // 0x800353AC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800353B0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800353B4: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800353B8: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x800353BC: jal         0x80031640
    // 0x800353C0: addiu       $a3, $sp, 0x33
    ctx->r7 = ADD32(ctx->r29, 0X33);
    resolve_collisions(rdram, ctx);
        goto after_2;
    // 0x800353C0: addiu       $a3, $sp, 0x33
    ctx->r7 = ADD32(ctx->r29, 0X33);
    after_2:
    // 0x800353C4: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800353C8: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800353CC: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800353D0: sub.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x800353D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800353D8: div.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800353DC: lwc1        $f3, 0x65A8($at)
    ctx->f_odd[(3 - 1) * 2] = MEM_W(ctx->r1, 0X65A8);
    // 0x800353E0: lwc1        $f2, 0x65AC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X65AC);
    // 0x800353E4: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800353E8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800353EC: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
    // 0x800353F0: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800353F4: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800353F8: sub.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x800353FC: nop

    // 0x80035400: div.s       $f6, $f16, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80035404: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    // 0x80035408: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8003540C: nop

    // 0x80035410: sub.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80035414: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80035418: div.s       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8003541C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80035420: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x80035424: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80035428: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
    // 0x8003542C: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80035430: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80035434: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x80035438: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8003543C: sub.d       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = ctx->f8.d - ctx->f18.d;
    // 0x80035440: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x80035444: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80035448: cvt.s.d     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f6.fl = CVT_S_D(ctx->f16.d);
    // 0x8003544C: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    // 0x80035450: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80035454: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80035458: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8003545C: mul.d       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f2.d);
    // 0x80035460: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    // 0x80035464: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x80035468: mul.d       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f2.d);
    // 0x8003546C: cvt.s.d     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f18.fl = CVT_S_D(ctx->f8.d);
    // 0x80035470: lwc1        $f8, 0x20($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80035474: swc1        $f18, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f18.u32l;
    // 0x80035478: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x8003547C: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
    // 0x80035480: lwc1        $f16, 0x65B4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X65B4);
    // 0x80035484: lwc1        $f17, 0x65B0($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, 0X65B0);
    // 0x80035488: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
    // 0x8003548C: mul.d       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f16.d);
    // 0x80035490: lui         $at, 0xC4FA
    ctx->r1 = S32(0XC4FA << 16);
    // 0x80035494: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80035498: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003549C: nop

    // 0x800354A0: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x800354A4: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x800354A8: bc1t        L_800354D0
    if (c1cs) {
        // 0x800354AC: swc1        $f4, 0x20($s0)
        MEM_W(0X20, ctx->r16) = ctx->f4.u32l;
            goto L_800354D0;
    }
    // 0x800354AC: swc1        $f4, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f4.u32l;
    // 0x800354B0: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800354B4: lb          $t2, 0x33($sp)
    ctx->r10 = MEM_B(ctx->r29, 0X33);
    // 0x800354B8: beq         $t1, $zero, L_800354EC
    if (ctx->r9 == 0) {
        // 0x800354BC: slti        $at, $t2, 0x5
        ctx->r1 = SIGNED(ctx->r10) < 0X5 ? 1 : 0;
            goto L_800354EC;
    }
    // 0x800354BC: slti        $at, $t2, 0x5
    ctx->r1 = SIGNED(ctx->r10) < 0X5 ? 1 : 0;
    // 0x800354C0: bne         $at, $zero, L_800354D0
    if (ctx->r1 != 0) {
        // 0x800354C4: slti        $at, $t2, 0xA
        ctx->r1 = SIGNED(ctx->r10) < 0XA ? 1 : 0;
            goto L_800354D0;
    }
    // 0x800354C4: slti        $at, $t2, 0xA
    ctx->r1 = SIGNED(ctx->r10) < 0XA ? 1 : 0;
    // 0x800354C8: bne         $at, $zero, L_800354F0
    if (ctx->r1 != 0) {
        // 0x800354CC: lw          $t3, 0x34($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X34);
            goto L_800354F0;
    }
    // 0x800354CC: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
L_800354D0:
    // 0x800354D0: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x800354D4: nop

    // 0x800354D8: beq         $v0, $zero, L_800354E4
    if (ctx->r2 == 0) {
        // 0x800354DC: nop
    
            goto L_800354E4;
    }
    // 0x800354DC: nop

    // 0x800354E0: sw          $zero, 0x78($v0)
    MEM_W(0X78, ctx->r2) = 0;
L_800354E4:
    // 0x800354E4: jal         0x8000FFB8
    // 0x800354E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    free_object(rdram, ctx);
        goto after_3;
    // 0x800354E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_800354EC:
    // 0x800354EC: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
L_800354F0:
    // 0x800354F0: lb          $t4, 0x33($sp)
    ctx->r12 = MEM_B(ctx->r29, 0X33);
    // 0x800354F4: beq         $t3, $zero, L_80035514
    if (ctx->r11 == 0) {
        // 0x800354F8: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80035514;
    }
    // 0x800354F8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800354FC: bne         $t4, $at, L_80035518
    if (ctx->r12 != ctx->r1) {
        // 0x80035500: lw          $t5, 0x34($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X34);
            goto L_80035518;
    }
    // 0x80035500: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80035504: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80035508: sb          $zero, 0xB($s1)
    MEM_B(0XB, ctx->r17) = 0;
    // 0x8003550C: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x80035510: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
L_80035514:
    // 0x80035514: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
L_80035518:
    // 0x80035518: lb          $t6, 0x33($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X33);
    // 0x8003551C: beq         $t5, $zero, L_8003566C
    if (ctx->r13 == 0) {
        // 0x80035520: slti        $at, $t6, 0x6
        ctx->r1 = SIGNED(ctx->r14) < 0X6 ? 1 : 0;
            goto L_8003566C;
    }
    // 0x80035520: slti        $at, $t6, 0x6
    ctx->r1 = SIGNED(ctx->r14) < 0X6 ? 1 : 0;
    // 0x80035524: bne         $at, $zero, L_8003566C
    if (ctx->r1 != 0) {
        // 0x80035528: slti        $at, $t6, 0xA
        ctx->r1 = SIGNED(ctx->r14) < 0XA ? 1 : 0;
            goto L_8003566C;
    }
    // 0x80035528: slti        $at, $t6, 0xA
    ctx->r1 = SIGNED(ctx->r14) < 0XA ? 1 : 0;
    // 0x8003552C: beq         $at, $zero, L_8003566C
    if (ctx->r1 == 0) {
        // 0x80035530: addiu       $t7, $t6, -0x6
        ctx->r15 = ADD32(ctx->r14, -0X6);
            goto L_8003566C;
    }
    // 0x80035530: addiu       $t7, $t6, -0x6
    ctx->r15 = ADD32(ctx->r14, -0X6);
    // 0x80035534: sb          $t7, 0xA($s1)
    MEM_B(0XA, ctx->r17) = ctx->r15;
    // 0x80035538: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8003553C: lb          $a0, 0xA($s1)
    ctx->r4 = MEM_B(ctx->r17, 0XA);
    // 0x80035540: jal         0x8001BAFC
    // 0x80035544: sb          $t8, 0xB($s1)
    MEM_B(0XB, ctx->r17) = ctx->r24;
    get_racer_object(rdram, ctx);
        goto after_4;
    // 0x80035544: sb          $t8, 0xB($s1)
    MEM_B(0XB, ctx->r17) = ctx->r24;
    after_4:
    // 0x80035548: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003554C: beq         $v0, $zero, L_8003556C
    if (ctx->r2 == 0) {
        // 0x80035550: addiu       $t1, $zero, 0x258
        ctx->r9 = ADD32(0, 0X258);
            goto L_8003556C;
    }
    // 0x80035550: addiu       $t1, $zero, 0x258
    ctx->r9 = ADD32(0, 0X258);
    // 0x80035554: lw          $a2, 0x64($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X64);
    // 0x80035558: nop

    // 0x8003555C: lb          $t9, 0x1CF($a2)
    ctx->r25 = MEM_B(ctx->r6, 0X1CF);
    // 0x80035560: nop

    // 0x80035564: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80035568: sb          $t0, 0x1CF($a2)
    MEM_B(0X1CF, ctx->r6) = ctx->r8;
L_8003556C:
    // 0x8003556C: sh          $t1, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r9;
    // 0x80035570: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x80035574: b           L_8003566C
    // 0x80035578: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
        goto L_8003566C;
    // 0x80035578: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
L_8003557C:
    // 0x8003557C: lh          $t2, 0x8($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X8);
    // 0x80035580: lb          $a0, 0xA($s1)
    ctx->r4 = MEM_B(ctx->r17, 0XA);
    // 0x80035584: subu        $t3, $t2, $a1
    ctx->r11 = SUB32(ctx->r10, ctx->r5);
    // 0x80035588: jal         0x8001BAFC
    // 0x8003558C: sh          $t3, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r11;
    get_racer_object(rdram, ctx);
        goto after_5;
    // 0x8003558C: sh          $t3, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r11;
    after_5:
    // 0x80035590: beq         $v0, $zero, L_800355A4
    if (ctx->r2 == 0) {
        // 0x80035594: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_800355A4;
    }
    // 0x80035594: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80035598: lw          $a2, 0x64($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X64);
    // 0x8003559C: nop

    // 0x800355A0: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
L_800355A4:
    // 0x800355A4: lh          $v1, 0x8($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X8);
    // 0x800355A8: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x800355AC: bgtz        $v1, L_800355E0
    if (SIGNED(ctx->r3) > 0) {
        // 0x800355B0: addiu       $t6, $zero, 0x4
        ctx->r14 = ADD32(0, 0X4);
            goto L_800355E0;
    }
    // 0x800355B0: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x800355B4: beq         $v0, $zero, L_800355CC
    if (ctx->r2 == 0) {
        // 0x800355B8: nop
    
            goto L_800355CC;
    }
    // 0x800355B8: nop

    // 0x800355BC: lb          $t4, 0x193($a2)
    ctx->r12 = MEM_B(ctx->r6, 0X193);
    // 0x800355C0: nop

    // 0x800355C4: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800355C8: sb          $t5, 0x193($a2)
    MEM_B(0X193, ctx->r6) = ctx->r13;
L_800355CC:
    // 0x800355CC: lw          $t7, 0x4($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X4);
    // 0x800355D0: sb          $t6, 0xB($s1)
    MEM_B(0XB, ctx->r17) = ctx->r14;
    // 0x800355D4: sw          $zero, 0x78($t7)
    MEM_W(0X78, ctx->r15) = 0;
    // 0x800355D8: lh          $v1, 0x8($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X8);
    // 0x800355DC: nop

L_800355E0:
    // 0x800355E0: slti        $at, $v1, 0x21C
    ctx->r1 = SIGNED(ctx->r3) < 0X21C ? 1 : 0;
    // 0x800355E4: beq         $at, $zero, L_80035608
    if (ctx->r1 == 0) {
        // 0x800355E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80035608;
    }
    // 0x800355E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800355EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800355F0: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    // 0x800355F4: jal         0x80036080
    // 0x800355F8: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    try_to_collect_egg(rdram, ctx);
        goto after_6;
    // 0x800355F8: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    after_6:
    // 0x800355FC: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x80035600: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x80035604: nop

L_80035608:
    // 0x80035608: beq         $a3, $zero, L_80035670
    if (ctx->r7 == 0) {
        // 0x8003560C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80035670;
    }
    // 0x8003560C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80035610: lb          $t8, 0xB($s1)
    ctx->r24 = MEM_B(ctx->r17, 0XB);
    // 0x80035614: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80035618: beq         $t8, $at, L_80035670
    if (ctx->r24 == ctx->r1) {
        // 0x8003561C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80035670;
    }
    // 0x8003561C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80035620: lb          $t9, 0x1CF($a2)
    ctx->r25 = MEM_B(ctx->r6, 0X1CF);
    // 0x80035624: nop

    // 0x80035628: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x8003562C: b           L_8003566C
    // 0x80035630: sb          $t0, 0x1CF($a2)
    MEM_B(0X1CF, ctx->r6) = ctx->r8;
        goto L_8003566C;
    // 0x80035630: sb          $t0, 0x1CF($a2)
    MEM_B(0X1CF, ctx->r6) = ctx->r8;
L_80035634:
    // 0x80035634: lb          $a0, 0xA($s1)
    ctx->r4 = MEM_B(ctx->r17, 0XA);
    // 0x80035638: jal         0x8001BAFC
    // 0x8003563C: nop

    get_racer_object(rdram, ctx);
        goto after_7;
    // 0x8003563C: nop

    after_7:
    // 0x80035640: beq         $v0, $zero, L_80035668
    if (ctx->r2 == 0) {
        // 0x80035644: addiu       $t3, $zero, 0x80
        ctx->r11 = ADD32(0, 0X80);
            goto L_80035668;
    }
    // 0x80035644: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x80035648: lw          $a2, 0x64($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X64);
    // 0x8003564C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80035650: lb          $t1, 0x193($a2)
    ctx->r9 = MEM_B(ctx->r6, 0X193);
    // 0x80035654: nop

    // 0x80035658: slti        $at, $t1, 0x3
    ctx->r1 = SIGNED(ctx->r9) < 0X3 ? 1 : 0;
    // 0x8003565C: bne         $at, $zero, L_80035668
    if (ctx->r1 != 0) {
        // 0x80035660: nop
    
            goto L_80035668;
    }
    // 0x80035660: nop

    // 0x80035664: sb          $t2, 0x1D8($a2)
    MEM_B(0X1D8, ctx->r6) = ctx->r10;
L_80035668:
    // 0x80035668: sh          $t3, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r11;
L_8003566C:
    // 0x8003566C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80035670:
    // 0x80035670: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80035674: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80035678: jr          $ra
    // 0x8003567C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8003567C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void obj_init_eggcreator(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035680: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80035684: jr          $ra
    // 0x80035688: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x80035688: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void obj_loop_eggcreator(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003568C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80035690: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80035694: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80035698: lw          $t6, 0x78($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X78);
    // 0x8003569C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800356A0: bne         $t6, $zero, L_80035760
    if (ctx->r14 != 0) {
        // 0x800356A4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80035760;
    }
    // 0x800356A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800356A8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800356AC: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800356B0: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800356B4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800356B8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800356BC: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x800356C0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800356C4: addiu       $t4, $zero, 0x34
    ctx->r12 = ADD32(0, 0X34);
    // 0x800356C8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800356CC: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x800356D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800356D4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800356D8: sh          $t8, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r24;
    // 0x800356DC: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800356E0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800356E4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800356E8: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800356EC: nop

    // 0x800356F0: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800356F4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800356F8: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x800356FC: nop

    // 0x80035700: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80035704: sh          $t0, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r8;
    // 0x80035708: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x8003570C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80035710: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80035714: lwc1        $f16, 0x14($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80035718: sb          $t3, 0x21($sp)
    MEM_B(0X21, ctx->r29) = ctx->r11;
    // 0x8003571C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80035720: sb          $t4, 0x20($sp)
    MEM_B(0X20, ctx->r29) = ctx->r12;
    // 0x80035724: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x80035728: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8003572C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80035730: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80035734: jal         0x8000EA54
    // 0x80035738: sh          $t2, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r10;
    spawn_object(rdram, ctx);
        goto after_0;
    // 0x80035738: sh          $t2, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r10;
    after_0:
    // 0x8003573C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80035740: beq         $v0, $zero, L_80035760
    if (ctx->r2 == 0) {
        // 0x80035744: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80035760;
    }
    // 0x80035744: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80035748: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x8003574C: nop

    // 0x80035750: sw          $a2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r6;
    // 0x80035754: sw          $v0, 0x78($a2)
    MEM_W(0X78, ctx->r6) = ctx->r2;
    // 0x80035758: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x8003575C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80035760:
    // 0x80035760: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80035764: jr          $ra
    // 0x80035768: nop

    return;
    // 0x80035768: nop

;}
RECOMP_FUNC void obj_init_lighthouse_rocketsignpost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003576C: lbu         $t7, 0x9($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X9);
    // 0x80035770: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80035774: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80035778: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003577C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80035780: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80035784: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80035788: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8003578C: nop

    // 0x80035790: bc1f        L_800357A0
    if (!c1cs) {
        // 0x80035794: nop
    
            goto L_800357A0;
    }
    // 0x80035794: nop

    // 0x80035798: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8003579C: nop

L_800357A0:
    // 0x800357A0: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800357A4: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x800357A8: lb          $t1, 0x3A($a0)
    ctx->r9 = MEM_B(ctx->r4, 0X3A);
    // 0x800357AC: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800357B0: nop

    // 0x800357B4: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800357B8: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
    // 0x800357BC: lbu         $t9, 0xA($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0XA);
    // 0x800357C0: nop

    // 0x800357C4: sll         $t0, $t9, 10
    ctx->r8 = S32(ctx->r25 << 10);
    // 0x800357C8: sh          $t0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r8;
    // 0x800357CC: lb          $t2, 0x55($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X55);
    // 0x800357D0: nop

    // 0x800357D4: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800357D8: bne         $at, $zero, L_800357E4
    if (ctx->r1 != 0) {
        // 0x800357DC: nop
    
            goto L_800357E4;
    }
    // 0x800357DC: nop

    // 0x800357E0: sb          $zero, 0x3A($a0)
    MEM_B(0X3A, ctx->r4) = 0;
L_800357E4:
    // 0x800357E4: lw          $t4, 0x4C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X4C);
    // 0x800357E8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800357EC: sh          $t3, 0x14($t4)
    MEM_H(0X14, ctx->r12) = ctx->r11;
    // 0x800357F0: lw          $t6, 0x4C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4C);
    // 0x800357F4: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x800357F8: sb          $t5, 0x11($t6)
    MEM_B(0X11, ctx->r14) = ctx->r13;
    // 0x800357FC: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x80035800: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x80035804: sb          $t7, 0x10($t8)
    MEM_B(0X10, ctx->r24) = ctx->r15;
    // 0x80035808: lw          $t9, 0x4C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4C);
    // 0x8003580C: jr          $ra
    // 0x80035810: sb          $zero, 0x12($t9)
    MEM_B(0X12, ctx->r25) = 0;
    return;
    // 0x80035810: sb          $zero, 0x12($t9)
    MEM_B(0X12, ctx->r25) = 0;
;}
RECOMP_FUNC void obj_loop_rocketsignpost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035814: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80035818: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003581C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80035820: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80035824: jal         0x8001BAFC
    // 0x80035828: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    get_racer_object(rdram, ctx);
        goto after_0;
    // 0x80035828: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8003582C: beq         $v0, $zero, L_800358AC
    if (ctx->r2 == 0) {
        // 0x80035830: lw          $t4, 0x20($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X20);
            goto L_800358AC;
    }
    // 0x80035830: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80035834: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80035838: nop

    // 0x8003583C: lw          $v1, 0x4C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X4C);
    // 0x80035840: nop

    // 0x80035844: lbu         $t7, 0x13($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X13);
    // 0x80035848: nop

    // 0x8003584C: slti        $at, $t7, 0xC8
    ctx->r1 = SIGNED(ctx->r15) < 0XC8 ? 1 : 0;
    // 0x80035850: beq         $at, $zero, L_800358AC
    if (ctx->r1 == 0) {
        // 0x80035854: lw          $t4, 0x20($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X20);
            goto L_800358AC;
    }
    // 0x80035854: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80035858: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8003585C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80035860: bne         $v0, $t8, L_800358AC
    if (ctx->r2 != ctx->r24) {
        // 0x80035864: lw          $t4, 0x20($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X20);
            goto L_800358AC;
    }
    // 0x80035864: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80035868: jal         0x8006A794
    // 0x8003586C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    input_pressed(rdram, ctx);
        goto after_1;
    // 0x8003586C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80035870: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80035874: andi        $t9, $v0, 0x2000
    ctx->r25 = ctx->r2 & 0X2000;
    // 0x80035878: bne         $t9, $zero, L_800358A0
    if (ctx->r25 != 0) {
        // 0x8003587C: nop
    
            goto L_800358A0;
    }
    // 0x8003587C: nop

    // 0x80035880: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80035884: nop

    // 0x80035888: lw          $t1, 0x5C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X5C);
    // 0x8003588C: nop

    // 0x80035890: lw          $t2, 0x100($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X100);
    // 0x80035894: nop

    // 0x80035898: bne         $a1, $t2, L_800358AC
    if (ctx->r5 != ctx->r10) {
        // 0x8003589C: lw          $t4, 0x20($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X20);
            goto L_800358AC;
    }
    // 0x8003589C: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
L_800358A0:
    // 0x800358A0: jal         0x8006F4DC
    // 0x800358A4: nop

    begin_lighthouse_rocket_cutscene(rdram, ctx);
        goto after_2;
    // 0x800358A4: nop

    after_2:
    // 0x800358A8: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
L_800358AC:
    // 0x800358AC: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800358B0: lw          $t5, 0x4C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4C);
    // 0x800358B4: nop

    // 0x800358B8: sb          $t3, 0x13($t5)
    MEM_B(0X13, ctx->r13) = ctx->r11;
    // 0x800358BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800358C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800358C4: jr          $ra
    // 0x800358C8: nop

    return;
    // 0x800358C8: nop

;}
RECOMP_FUNC void obj_init_airzippers_waterzippers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800358CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800358D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800358D4: lbu         $t7, 0x9($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X9);
    // 0x800358D8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800358DC: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800358E0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800358E4: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800358E8: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x800358EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800358F0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800358F4: nop

    // 0x800358F8: bc1f        L_80035908
    if (!c1cs) {
        // 0x800358FC: nop
    
            goto L_80035908;
    }
    // 0x800358FC: nop

    // 0x80035900: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80035904: nop

L_80035908:
    // 0x80035908: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8003590C: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x80035910: lb          $t1, 0x3A($a0)
    ctx->r9 = MEM_B(ctx->r4, 0X3A);
    // 0x80035914: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80035918: nop

    // 0x8003591C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80035920: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
    // 0x80035924: lbu         $t9, 0xA($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0XA);
    // 0x80035928: nop

    // 0x8003592C: sll         $t0, $t9, 10
    ctx->r8 = S32(ctx->r25 << 10);
    // 0x80035930: sh          $t0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r8;
    // 0x80035934: lb          $t2, 0x55($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X55);
    // 0x80035938: nop

    // 0x8003593C: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80035940: bne         $at, $zero, L_8003594C
    if (ctx->r1 != 0) {
        // 0x80035944: nop
    
            goto L_8003594C;
    }
    // 0x80035944: nop

    // 0x80035948: sb          $zero, 0x3A($a0)
    MEM_B(0X3A, ctx->r4) = 0;
L_8003594C:
    // 0x8003594C: lw          $t4, 0x4C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X4C);
    // 0x80035950: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80035954: sh          $t3, 0x14($t4)
    MEM_H(0X14, ctx->r12) = ctx->r11;
    // 0x80035958: lw          $t5, 0x4C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X4C);
    // 0x8003595C: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x80035960: sb          $zero, 0x11($t5)
    MEM_B(0X11, ctx->r13) = 0;
    // 0x80035964: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x80035968: nop

    // 0x8003596C: sb          $t6, 0x10($t7)
    MEM_B(0X10, ctx->r15) = ctx->r14;
    // 0x80035970: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x80035974: nop

    // 0x80035978: sb          $zero, 0x12($t8)
    MEM_B(0X12, ctx->r24) = 0;
    // 0x8003597C: jal         0x8009C850
    // 0x80035980: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    get_filtered_cheats(rdram, ctx);
        goto after_0;
    // 0x80035980: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80035984: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80035988: sll         $t9, $v0, 10
    ctx->r25 = S32(ctx->r2 << 10);
    // 0x8003598C: bgez        $t9, L_800359A0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80035990: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800359A0;
    }
    // 0x80035990: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80035994: jal         0x8000FFB8
    // 0x80035998: nop

    free_object(rdram, ctx);
        goto after_1;
    // 0x80035998: nop

    after_1:
    // 0x8003599C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800359A0:
    // 0x800359A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800359A4: jr          $ra
    // 0x800359A8: nop

    return;
    // 0x800359A8: nop

;}
RECOMP_FUNC void obj_loop_airzippers_waterzippers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800359AC: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800359B0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800359B4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800359B8: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800359BC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800359C0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800359C4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800359C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800359CC: jal         0x8000E1CC
    // 0x800359D0: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    find_non_car_racers(rdram, ctx);
        goto after_0;
    // 0x800359D0: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800359D4: bne         $v0, $zero, L_800359F0
    if (ctx->r2 != 0) {
        // 0x800359D8: nop
    
            goto L_800359F0;
    }
    // 0x800359D8: nop

    // 0x800359DC: lh          $t6, 0x6($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X6);
    // 0x800359E0: nop

    // 0x800359E4: ori         $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 | 0X4000;
    // 0x800359E8: b           L_80035A00
    // 0x800359EC: sh          $t7, 0x6($s3)
    MEM_H(0X6, ctx->r19) = ctx->r15;
        goto L_80035A00;
    // 0x800359EC: sh          $t7, 0x6($s3)
    MEM_H(0X6, ctx->r19) = ctx->r15;
L_800359F0:
    // 0x800359F0: lh          $t8, 0x6($s3)
    ctx->r24 = MEM_H(ctx->r19, 0X6);
    // 0x800359F4: nop

    // 0x800359F8: andi        $t9, $t8, 0xBFFF
    ctx->r25 = ctx->r24 & 0XBFFF;
    // 0x800359FC: sh          $t9, 0x6($s3)
    MEM_H(0X6, ctx->r19) = ctx->r25;
L_80035A00:
    // 0x80035A00: lw          $t0, 0x4C($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X4C);
    // 0x80035A04: nop

    // 0x80035A08: lbu         $t1, 0x13($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X13);
    // 0x80035A0C: nop

    // 0x80035A10: slti        $at, $t1, 0x64
    ctx->r1 = SIGNED(ctx->r9) < 0X64 ? 1 : 0;
    // 0x80035A14: beq         $at, $zero, L_80035B0C
    if (ctx->r1 == 0) {
        // 0x80035A18: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80035B0C;
    }
    // 0x80035A18: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80035A1C: lh          $t2, 0x6($s3)
    ctx->r10 = MEM_H(ctx->r19, 0X6);
    // 0x80035A20: nop

    // 0x80035A24: andi        $t3, $t2, 0x4000
    ctx->r11 = ctx->r10 & 0X4000;
    // 0x80035A28: bne         $t3, $zero, L_80035B0C
    if (ctx->r11 != 0) {
        // 0x80035A2C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80035B0C;
    }
    // 0x80035A2C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80035A30: jal         0x8001BAA8
    // 0x80035A34: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    get_racer_objects(rdram, ctx);
        goto after_1;
    // 0x80035A34: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_1:
    // 0x80035A38: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80035A3C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80035A40: blez        $t4, L_80035B08
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80035A44: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_80035B08;
    }
    // 0x80035A44: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80035A48: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
L_80035A4C:
    // 0x80035A4C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80035A50: nop

    // 0x80035A54: lw          $s0, 0x64($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X64);
    // 0x80035A58: nop

    // 0x80035A5C: lbu         $t5, 0x1F5($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X1F5);
    // 0x80035A60: nop

    // 0x80035A64: bne         $t5, $zero, L_80035AF8
    if (ctx->r13 != 0) {
        // 0x80035A68: lw          $t9, 0x40($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X40);
            goto L_80035AF8;
    }
    // 0x80035A68: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80035A6C: lb          $t6, 0x1D3($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D3);
    // 0x80035A70: nop

    // 0x80035A74: slti        $at, $t6, 0xF
    ctx->r1 = SIGNED(ctx->r14) < 0XF ? 1 : 0;
    // 0x80035A78: beq         $at, $zero, L_80035AF8
    if (ctx->r1 == 0) {
        // 0x80035A7C: lw          $t9, 0x40($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X40);
            goto L_80035AF8;
    }
    // 0x80035A7C: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80035A80: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80035A84: lwc1        $f6, 0xC($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0XC);
    // 0x80035A88: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80035A8C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80035A90: lwc1        $f10, 0x10($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X10);
    // 0x80035A94: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80035A98: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80035A9C: lwc1        $f16, 0x14($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80035AA0: lwc1        $f18, 0x14($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X14);
    // 0x80035AA4: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80035AA8: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80035AAC: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80035AB0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80035AB4: jal         0x800CA030
    // 0x80035AB8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x80035AB8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_2:
    // 0x80035ABC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80035AC0: nop

    // 0x80035AC4: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80035AC8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80035ACC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80035AD0: nop

    // 0x80035AD4: cvt.w.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80035AD8: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x80035ADC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80035AE0: slti        $at, $t8, 0x64
    ctx->r1 = SIGNED(ctx->r24) < 0X64 ? 1 : 0;
    // 0x80035AE4: beq         $at, $zero, L_80035AF8
    if (ctx->r1 == 0) {
        // 0x80035AE8: lw          $t9, 0x40($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X40);
            goto L_80035AF8;
    }
    // 0x80035AE8: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80035AEC: sb          $s4, 0x1F5($s0)
    MEM_B(0X1F5, ctx->r16) = ctx->r20;
    // 0x80035AF0: sw          $s3, 0x14C($s0)
    MEM_W(0X14C, ctx->r16) = ctx->r19;
    // 0x80035AF4: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
L_80035AF8:
    // 0x80035AF8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80035AFC: slt         $at, $s1, $t9
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80035B00: bne         $at, $zero, L_80035A4C
    if (ctx->r1 != 0) {
        // 0x80035B04: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80035A4C;
    }
    // 0x80035B04: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80035B08:
    // 0x80035B08: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80035B0C:
    // 0x80035B0C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80035B10: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80035B14: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80035B18: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80035B1C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80035B20: jr          $ra
    // 0x80035B24: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80035B24: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void obj_init_groundzipper(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035B28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80035B2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80035B30: lbu         $t7, 0x9($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X9);
    // 0x80035B34: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80035B38: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80035B3C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80035B40: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80035B44: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80035B48: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80035B4C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80035B50: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80035B54: bc1f        L_80035B64
    if (!c1cs) {
        // 0x80035B58: nop
    
            goto L_80035B64;
    }
    // 0x80035B58: nop

    // 0x80035B5C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80035B60: nop

L_80035B64:
    // 0x80035B64: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80035B68: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x80035B6C: lw          $t8, 0x50($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X50);
    // 0x80035B70: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80035B74: nop

    // 0x80035B78: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80035B7C: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
    // 0x80035B80: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80035B84: nop

    // 0x80035B88: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80035B8C: swc1        $f18, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f18.u32l;
    // 0x80035B90: lbu         $t0, 0xA($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0XA);
    // 0x80035B94: lw          $t3, 0x40($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X40);
    // 0x80035B98: sll         $t1, $t0, 10
    ctx->r9 = S32(ctx->r8 << 10);
    // 0x80035B9C: sh          $t1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r9;
    // 0x80035BA0: lb          $t2, 0x3A($a0)
    ctx->r10 = MEM_B(ctx->r4, 0X3A);
    // 0x80035BA4: lb          $t4, 0x55($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X55);
    // 0x80035BA8: nop

    // 0x80035BAC: slt         $at, $t2, $t4
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80035BB0: bne         $at, $zero, L_80035BC0
    if (ctx->r1 != 0) {
        // 0x80035BB4: lui         $at, 0x41E0
        ctx->r1 = S32(0X41E0 << 16);
            goto L_80035BC0;
    }
    // 0x80035BB4: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80035BB8: sb          $zero, 0x3A($a0)
    MEM_B(0X3A, ctx->r4) = 0;
    // 0x80035BBC: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
L_80035BC0:
    // 0x80035BC0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80035BC4: nop

    // 0x80035BC8: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80035BCC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80035BD0: nop

    // 0x80035BD4: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80035BD8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80035BDC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80035BE0: nop

    // 0x80035BE4: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80035BE8: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80035BEC: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80035BF0: addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
    // 0x80035BF4: bgez        $v0, L_80035C00
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80035BF8: sw          $v0, 0x78($a0)
        MEM_W(0X78, ctx->r4) = ctx->r2;
            goto L_80035C00;
    }
    // 0x80035BF8: sw          $v0, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r2;
    // 0x80035BFC: sw          $zero, 0x78($a0)
    MEM_W(0X78, ctx->r4) = 0;
L_80035C00:
    // 0x80035C00: lw          $t6, 0x78($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X78);
    // 0x80035C04: nop

    // 0x80035C08: slti        $at, $t6, 0x100
    ctx->r1 = SIGNED(ctx->r14) < 0X100 ? 1 : 0;
    // 0x80035C0C: bne         $at, $zero, L_80035C18
    if (ctx->r1 != 0) {
        // 0x80035C10: nop
    
            goto L_80035C18;
    }
    // 0x80035C10: nop

    // 0x80035C14: sw          $t7, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r15;
L_80035C18:
    // 0x80035C18: lw          $t9, 0x4C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4C);
    // 0x80035C1C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80035C20: sh          $t8, 0x14($t9)
    MEM_H(0X14, ctx->r25) = ctx->r24;
    // 0x80035C24: lw          $t0, 0x4C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4C);
    // 0x80035C28: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
    // 0x80035C2C: sb          $zero, 0x11($t0)
    MEM_B(0X11, ctx->r8) = 0;
    // 0x80035C30: lw          $t3, 0x4C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X4C);
    // 0x80035C34: addiu       $t4, $zero, -0x64
    ctx->r12 = ADD32(0, -0X64);
    // 0x80035C38: sb          $t1, 0x10($t3)
    MEM_B(0X10, ctx->r11) = ctx->r9;
    // 0x80035C3C: lw          $t2, 0x4C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X4C);
    // 0x80035C40: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x80035C44: sb          $zero, 0x12($t2)
    MEM_B(0X12, ctx->r10) = 0;
    // 0x80035C48: lw          $t5, 0x4C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X4C);
    // 0x80035C4C: nop

    // 0x80035C50: sb          $t4, 0x16($t5)
    MEM_B(0X16, ctx->r13) = ctx->r12;
    // 0x80035C54: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x80035C58: nop

    // 0x80035C5C: sb          $t6, 0x17($t7)
    MEM_B(0X17, ctx->r15) = ctx->r14;
    // 0x80035C60: jal         0x8009C850
    // 0x80035C64: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    get_filtered_cheats(rdram, ctx);
        goto after_0;
    // 0x80035C64: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80035C68: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80035C6C: sll         $t8, $v0, 10
    ctx->r24 = S32(ctx->r2 << 10);
    // 0x80035C70: bgez        $t8, L_80035C84
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80035C74: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80035C84;
    }
    // 0x80035C74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80035C78: jal         0x8000FFB8
    // 0x80035C7C: nop

    free_object(rdram, ctx);
        goto after_1;
    // 0x80035C7C: nop

    after_1:
    // 0x80035C80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80035C84:
    // 0x80035C84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80035C88: jr          $ra
    // 0x80035C8C: nop

    return;
    // 0x80035C8C: nop

;}
RECOMP_FUNC void obj_loop_groundzipper(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035C90: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80035C94: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80035C98: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80035C9C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80035CA0: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80035CA4: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80035CA8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80035CAC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80035CB0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80035CB4: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x80035CB8: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x80035CBC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80035CC0: andi        $t7, $t6, 0xBFFF
    ctx->r15 = ctx->r14 & 0XBFFF;
    // 0x80035CC4: sh          $t7, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r15;
    // 0x80035CC8: lh          $t8, 0x6($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X6);
    // 0x80035CCC: nop

    // 0x80035CD0: ori         $t9, $t8, 0x1000
    ctx->r25 = ctx->r24 | 0X1000;
    // 0x80035CD4: sh          $t9, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r25;
    // 0x80035CD8: jal         0x8001BAFC
    // 0x80035CDC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    get_racer_object(rdram, ctx);
        goto after_0;
    // 0x80035CDC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80035CE0: lw          $t0, 0x4C($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X4C);
    // 0x80035CE4: lw          $t2, 0x78($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X78);
    // 0x80035CE8: lbu         $t1, 0x13($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X13);
    // 0x80035CEC: nop

    // 0x80035CF0: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80035CF4: beq         $at, $zero, L_80035E3C
    if (ctx->r1 == 0) {
        // 0x80035CF8: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_80035E3C;
    }
    // 0x80035CF8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80035CFC: jal         0x8001BAA8
    // 0x80035D00: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    get_racer_objects(rdram, ctx);
        goto after_1;
    // 0x80035D00: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    after_1:
    // 0x80035D04: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x80035D08: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80035D0C: blez        $t3, L_80035E38
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80035D10: or          $s4, $v0, $zero
        ctx->r20 = ctx->r2 | 0;
            goto L_80035E38;
    }
    // 0x80035D10: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80035D14: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x80035D18: addiu       $s5, $zero, -0x1
    ctx->r21 = ADD32(0, -0X1);
L_80035D1C:
    // 0x80035D1C: lw          $s1, 0x0($s4)
    ctx->r17 = MEM_W(ctx->r20, 0X0);
    // 0x80035D20: nop

    // 0x80035D24: lw          $s0, 0x64($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X64);
    // 0x80035D28: nop

    // 0x80035D2C: lb          $t4, 0x1D3($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1D3);
    // 0x80035D30: nop

    // 0x80035D34: slti        $at, $t4, 0xF
    ctx->r1 = SIGNED(ctx->r12) < 0XF ? 1 : 0;
    // 0x80035D38: beq         $at, $zero, L_80035E28
    if (ctx->r1 == 0) {
        // 0x80035D3C: lw          $t4, 0x54($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X54);
            goto L_80035E28;
    }
    // 0x80035D3C: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x80035D40: lb          $t5, 0x1E2($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1E2);
    // 0x80035D44: nop

    // 0x80035D48: beq         $t5, $zero, L_80035E28
    if (ctx->r13 == 0) {
        // 0x80035D4C: lw          $t4, 0x54($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X54);
            goto L_80035E28;
    }
    // 0x80035D4C: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x80035D50: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80035D54: lwc1        $f6, 0xC($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0XC);
    // 0x80035D58: lwc1        $f8, 0x10($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80035D5C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80035D60: lwc1        $f10, 0x10($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X10);
    // 0x80035D64: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80035D68: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80035D6C: lwc1        $f16, 0x14($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80035D70: lwc1        $f18, 0x14($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X14);
    // 0x80035D74: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80035D78: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80035D7C: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80035D80: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80035D84: jal         0x800CA030
    // 0x80035D88: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x80035D88: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_2:
    // 0x80035D8C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80035D90: lw          $t8, 0x78($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X78);
    // 0x80035D94: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80035D98: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80035D9C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80035DA0: nop

    // 0x80035DA4: cvt.w.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80035DA8: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x80035DAC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80035DB0: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80035DB4: beq         $at, $zero, L_80035E28
    if (ctx->r1 == 0) {
        // 0x80035DB8: lw          $t4, 0x54($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X54);
            goto L_80035E28;
    }
    // 0x80035DB8: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x80035DBC: lh          $t9, 0x0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X0);
    // 0x80035DC0: addiu       $a0, $zero, 0x107
    ctx->r4 = ADD32(0, 0X107);
    // 0x80035DC4: beq         $s5, $t9, L_80035DE0
    if (ctx->r21 == ctx->r25) {
        // 0x80035DC8: nop
    
            goto L_80035DE0;
    }
    // 0x80035DC8: nop

    // 0x80035DCC: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x80035DD0: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x80035DD4: lw          $a3, 0x14($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X14);
    // 0x80035DD8: jal         0x80001EA8
    // 0x80035DDC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    sound_play_spatial(rdram, ctx);
        goto after_3;
    // 0x80035DDC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
L_80035DE0:
    // 0x80035DE0: jal         0x8000C8B4
    // 0x80035DE4: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    normalise_time(rdram, ctx);
        goto after_4;
    // 0x80035DE4: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    after_4:
    // 0x80035DE8: lbu         $t0, 0x20C($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X20C);
    // 0x80035DEC: sb          $v0, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r2;
    // 0x80035DF0: beq         $t0, $zero, L_80035E08
    if (ctx->r8 == 0) {
        // 0x80035DF4: sb          $s6, 0x203($s0)
        MEM_B(0X203, ctx->r16) = ctx->r22;
            goto L_80035E08;
    }
    // 0x80035DF4: sb          $s6, 0x203($s0)
    MEM_B(0X203, ctx->r16) = ctx->r22;
    // 0x80035DF8: lb          $t1, 0x203($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X203);
    // 0x80035DFC: nop

    // 0x80035E00: ori         $t2, $t1, 0x4
    ctx->r10 = ctx->r9 | 0X4;
    // 0x80035E04: sb          $t2, 0x203($s0)
    MEM_B(0X203, ctx->r16) = ctx->r10;
L_80035E08:
    // 0x80035E08: lb          $t3, 0x1D8($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1D8);
    // 0x80035E0C: nop

    // 0x80035E10: bne         $t3, $zero, L_80035E28
    if (ctx->r11 != 0) {
        // 0x80035E14: lw          $t4, 0x54($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X54);
            goto L_80035E28;
    }
    // 0x80035E14: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x80035E18: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80035E1C: jal         0x80072594
    // 0x80035E20: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    rumble_set(rdram, ctx);
        goto after_5;
    // 0x80035E20: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_5:
    // 0x80035E24: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
L_80035E28:
    // 0x80035E28: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80035E2C: slt         $at, $s3, $t4
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80035E30: bne         $at, $zero, L_80035D1C
    if (ctx->r1 != 0) {
        // 0x80035E34: addiu       $s4, $s4, 0x4
        ctx->r20 = ADD32(ctx->r20, 0X4);
            goto L_80035D1C;
    }
    // 0x80035E34: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
L_80035E38:
    // 0x80035E38: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80035E3C:
    // 0x80035E3C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80035E40: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80035E44: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80035E48: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80035E4C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80035E50: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80035E54: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80035E58: jr          $ra
    // 0x80035E5C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80035E5C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void obj_init_timetrialghost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035E60: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80035E64: lw          $t6, 0x40($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X40);
    // 0x80035E68: sw          $zero, 0x78($a0)
    MEM_W(0X78, ctx->r4) = 0;
    // 0x80035E6C: jr          $ra
    // 0x80035E70: sw          $t6, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r14;
    return;
    // 0x80035E70: sw          $t6, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void obj_loop_timetrialghost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035E74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80035E78: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80035E7C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80035E80: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80035E84: addiu       $t6, $zero, 0x28
    ctx->r14 = ADD32(0, 0X28);
    // 0x80035E88: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80035E8C: sb          $zero, 0x3B($a0)
    MEM_B(0X3B, ctx->r4) = 0;
    // 0x80035E90: jal         0x8001139C
    // 0x80035E94: sh          $t6, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r14;
    get_race_countdown(rdram, ctx);
        goto after_0;
    // 0x80035E94: sh          $t6, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r14;
    after_0:
    // 0x80035E98: bne         $v0, $zero, L_80035EB4
    if (ctx->r2 != 0) {
        // 0x80035E9C: nop
    
            goto L_80035EB4;
    }
    // 0x80035E9C: nop

    // 0x80035EA0: lw          $t7, 0x78($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X78);
    // 0x80035EA4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80035EA8: nop

    // 0x80035EAC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80035EB0: sw          $t9, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r25;
L_80035EB4:
    // 0x80035EB4: jal         0x80059E90
    // 0x80035EB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    timetrial_ghost_read(rdram, ctx);
        goto after_1;
    // 0x80035EB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80035EBC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80035EC0: jal         0x800B019C
    // 0x80035EC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    obj_spawn_particle(rdram, ctx);
        goto after_2;
    // 0x80035EC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80035EC8: jal         0x8001BAFC
    // 0x80035ECC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    get_racer_object(rdram, ctx);
        goto after_3;
    // 0x80035ECC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x80035ED0: lw          $v1, 0x60($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X60);
    // 0x80035ED4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80035ED8: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80035EDC: lw          $a0, 0x64($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X64);
    // 0x80035EE0: bne         $a1, $t0, L_80035F2C
    if (ctx->r5 != ctx->r8) {
        // 0x80035EE4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80035F2C;
    }
    // 0x80035EE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80035EE8: lb          $v0, 0x1D6($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X1D6);
    // 0x80035EEC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80035EF0: beq         $v0, $a1, L_80035F00
    if (ctx->r2 == ctx->r5) {
        // 0x80035EF4: nop
    
            goto L_80035F00;
    }
    // 0x80035EF4: nop

    // 0x80035EF8: bne         $v0, $at, L_80035F2C
    if (ctx->r2 != ctx->r1) {
        // 0x80035EFC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80035F2C;
    }
    // 0x80035EFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80035F00:
    // 0x80035F00: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80035F04: addiu       $t1, $zero, 0x4000
    ctx->r9 = ADD32(0, 0X4000);
    // 0x80035F08: lb          $t2, 0x3A($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X3A);
    // 0x80035F0C: sh          $t1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r9;
    // 0x80035F10: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80035F14: sb          $t3, 0x3A($v0)
    MEM_B(0X3A, ctx->r2) = ctx->r11;
    // 0x80035F18: lb          $t4, 0x3A($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X3A);
    // 0x80035F1C: nop

    // 0x80035F20: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x80035F24: sb          $t5, 0x3A($v0)
    MEM_B(0X3A, ctx->r2) = ctx->r13;
    // 0x80035F28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80035F2C:
    // 0x80035F2C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80035F30: jr          $ra
    // 0x80035F34: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80035F34: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void obj_init_characterflag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035F38: lh          $t6, 0xE($a1)
    ctx->r14 = MEM_H(ctx->r5, 0XE);
    // 0x80035F3C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80035F40: sw          $t7, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r15;
    // 0x80035F44: sw          $t6, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r14;
    // 0x80035F48: lh          $t9, 0xC($a1)
    ctx->r25 = MEM_H(ctx->r5, 0XC);
    // 0x80035F4C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80035F50: sll         $t0, $t9, 10
    ctx->r8 = S32(ctx->r25 << 10);
    // 0x80035F54: sh          $t0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r8;
    // 0x80035F58: lh          $t1, 0xA($a1)
    ctx->r9 = MEM_H(ctx->r5, 0XA);
    // 0x80035F5C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80035F60: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x80035F64: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80035F68: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80035F6C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80035F70: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80035F74: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80035F78: nop

    // 0x80035F7C: bc1f        L_80035F8C
    if (!c1cs) {
        // 0x80035F80: nop
    
            goto L_80035F8C;
    }
    // 0x80035F80: nop

    // 0x80035F84: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80035F88: nop

L_80035F8C:
    // 0x80035F8C: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80035F90: lw          $t3, 0x40($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X40);
    // 0x80035F94: nop

    // 0x80035F98: lwc1        $f8, 0xC($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0XC);
    // 0x80035F9C: nop

    // 0x80035FA0: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80035FA4: jr          $ra
    // 0x80035FA8: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
    return;
    // 0x80035FA8: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
;}
RECOMP_FUNC void obj_loop_characterflag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035FAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80035FB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80035FB4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80035FB8: lw          $t6, 0x7C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7C);
    // 0x80035FBC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80035FC0: bgez        $t6, L_80036074
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80035FC4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80036074;
    }
    // 0x80035FC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80035FC8: lw          $a0, 0x78($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X78);
    // 0x80035FCC: jal         0x8001BAFC
    // 0x80035FD0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    get_racer_object(rdram, ctx);
        goto after_0;
    // 0x80035FD0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80035FD4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80035FD8: beq         $v0, $zero, L_80036070
    if (ctx->r2 == 0) {
        // 0x80035FDC: lui         $t8, 0x800E
        ctx->r24 = S32(0X800E << 16);
            goto L_80036070;
    }
    // 0x80035FDC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80035FE0: lw          $a0, 0x64($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X64);
    // 0x80035FE4: lw          $v1, 0x64($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X64);
    // 0x80035FE8: lb          $t7, 0x3($a0)
    ctx->r15 = MEM_B(ctx->r4, 0X3);
    // 0x80035FEC: addiu       $t8, $t8, -0x3110
    ctx->r24 = ADD32(ctx->r24, -0X3110);
    // 0x80035FF0: bltz        $t7, L_80036004
    if (SIGNED(ctx->r15) < 0) {
        // 0x80035FF4: sw          $t7, 0x7C($a2)
        MEM_W(0X7C, ctx->r6) = ctx->r15;
            goto L_80036004;
    }
    // 0x80035FF4: sw          $t7, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->r15;
    // 0x80035FF8: slti        $at, $t7, 0xA
    ctx->r1 = SIGNED(ctx->r15) < 0XA ? 1 : 0;
    // 0x80035FFC: bne         $at, $zero, L_80036008
    if (ctx->r1 != 0) {
        // 0x80036000: nop
    
            goto L_80036008;
    }
    // 0x80036000: nop

L_80036004:
    // 0x80036004: sw          $zero, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = 0;
L_80036008:
    // 0x80036008: sw          $t8, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r24;
    // 0x8003600C: lw          $t0, 0x7C($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X7C);
    // 0x80036010: lw          $t9, 0x68($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X68);
    // 0x80036014: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80036018: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x8003601C: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80036020: lui         $t6, 0x4000
    ctx->r14 = S32(0X4000 << 16);
    // 0x80036024: sw          $t3, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r11;
    // 0x80036028: lbu         $v0, 0x0($t3)
    ctx->r2 = MEM_BU(ctx->r11, 0X0);
    // 0x8003602C: lbu         $a0, 0x1($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X1);
    // 0x80036030: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80036034: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80036038: sll         $t4, $v0, 21
    ctx->r12 = S32(ctx->r2 << 21);
    // 0x8003603C: sll         $t5, $a0, 5
    ctx->r13 = S32(ctx->r4 << 5);
    // 0x80036040: lui         $t7, 0x4001
    ctx->r15 = S32(0X4001 << 16);
    // 0x80036044: ori         $t6, $t6, 0x103
    ctx->r14 = ctx->r14 | 0X103;
    // 0x80036048: ori         $t7, $t7, 0x203
    ctx->r15 = ctx->r15 | 0X203;
    // 0x8003604C: or          $t8, $t4, $t5
    ctx->r24 = ctx->r12 | ctx->r13;
    // 0x80036050: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80036054: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80036058: sw          $t4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r12;
    // 0x8003605C: sw          $t5, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r13;
    // 0x80036060: sw          $t7, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r15;
    // 0x80036064: sw          $t4, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r12;
    // 0x80036068: sw          $t8, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r24;
    // 0x8003606C: sw          $t5, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r13;
L_80036070:
    // 0x80036070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80036074:
    // 0x80036074: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80036078: jr          $ra
    // 0x8003607C: nop

    return;
    // 0x8003607C: nop

;}
RECOMP_FUNC void try_to_collect_egg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036080: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80036084: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80036088: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8003608C: lw          $v1, 0x4C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4C);
    // 0x80036090: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80036094: lbu         $t6, 0x13($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X13);
    // 0x80036098: nop

    // 0x8003609C: slti        $at, $t6, 0x28
    ctx->r1 = SIGNED(ctx->r14) < 0X28 ? 1 : 0;
    // 0x800360A0: beq         $at, $zero, L_800361C8
    if (ctx->r1 == 0) {
        // 0x800360A4: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800361C8;
    }
    // 0x800360A4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800360A8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800360AC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800360B0: lw          $t7, 0x40($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X40);
    // 0x800360B4: nop

    // 0x800360B8: lb          $t8, 0x54($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X54);
    // 0x800360BC: nop

    // 0x800360C0: bne         $a3, $t8, L_800361C8
    if (ctx->r7 != ctx->r24) {
        // 0x800360C4: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800361C8;
    }
    // 0x800360C4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800360C8: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x800360CC: nop

    // 0x800360D0: lw          $t9, 0x144($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X144);
    // 0x800360D4: nop

    // 0x800360D8: bne         $t9, $zero, L_800361C8
    if (ctx->r25 != 0) {
        // 0x800360DC: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800361C8;
    }
    // 0x800360DC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800360E0: sb          $a3, 0xB($a1)
    MEM_B(0XB, ctx->r5) = ctx->r7;
    // 0x800360E4: lh          $t0, 0x6($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X6);
    // 0x800360E8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800360EC: ori         $t1, $t0, 0x4000
    ctx->r9 = ctx->r8 | 0X4000;
    // 0x800360F0: sh          $t1, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r9;
    // 0x800360F4: sw          $a0, 0x144($v1)
    MEM_W(0X144, ctx->r3) = ctx->r4;
    // 0x800360F8: lh          $t2, 0x0($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X0);
    // 0x800360FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80036100: negu        $t3, $t2
    ctx->r11 = SUB32(0, ctx->r10);
    // 0x80036104: sh          $t3, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r11;
    // 0x80036108: lh          $t4, 0x2($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X2);
    // 0x8003610C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80036110: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x80036114: sh          $t5, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r13;
    // 0x80036118: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x8003611C: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x80036120: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x80036124: sh          $t7, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r15;
    // 0x80036128: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8003612C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80036130: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80036134: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    // 0x80036138: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8003613C: nop

    // 0x80036140: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x80036144: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
    // 0x80036148: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8003614C: sw          $v0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r2;
    // 0x80036150: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x80036154: jal         0x800700B4
    // 0x80036158: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    mtxf_from_inverse_transform(rdram, ctx);
        goto after_0;
    // 0x80036158: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8003615C: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x80036160: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x80036164: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x80036168: addiu       $t8, $s0, 0xC
    ctx->r24 = ADD32(ctx->r16, 0XC);
    // 0x8003616C: addiu       $t9, $s0, 0x10
    ctx->r25 = ADD32(ctx->r16, 0X10);
    // 0x80036170: addiu       $t0, $s0, 0x14
    ctx->r8 = ADD32(ctx->r16, 0X14);
    // 0x80036174: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80036178: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8003617C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80036180: jal         0x8006F88C
    // 0x80036184: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    mtxf_transform_point(rdram, ctx);
        goto after_1;
    // 0x80036184: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    after_1:
    // 0x80036188: lw          $v0, 0x90($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X90);
    // 0x8003618C: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80036190: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80036194: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80036198: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8003619C: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800361A0: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x800361A4: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800361A8: nop

    // 0x800361AC: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800361B0: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
    // 0x800361B4: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800361B8: nop

    // 0x800361BC: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800361C0: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    // 0x800361C4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800361C8:
    // 0x800361C8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800361CC: jr          $ra
    // 0x800361D0: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x800361D0: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void obj_init_stopwatchman(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800361D4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800361D8: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x800361DC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800361E0: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x800361E4: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x800361E8: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x800361EC: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
    // 0x800361F0: lw          $t0, 0x4C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4C);
    // 0x800361F4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800361F8: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x800361FC: lw          $t1, 0x4C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4C);
    // 0x80036200: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80036204: sb          $zero, 0x12($t1)
    MEM_B(0X12, ctx->r9) = 0;
    // 0x80036208: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x8003620C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80036210: sb          $t2, 0xD($v0)
    MEM_B(0XD, ctx->r2) = ctx->r10;
    // 0x80036214: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x80036218: jr          $ra
    // 0x8003621C: sw          $zero, -0x25A8($at)
    MEM_W(-0X25A8, ctx->r1) = 0;
    return;
    // 0x8003621C: sw          $zero, -0x25A8($at)
    MEM_W(-0X25A8, ctx->r1) = 0;
;}
RECOMP_FUNC void obj_loop_stopwatchman(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036220: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80036224: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x80036228: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8003622C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80036230: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80036234: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x80036238: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x8003623C: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80036240: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80036244: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x80036248: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003624C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80036250: bne         $t7, $zero, L_80036270
    if (ctx->r15 != 0) {
        // 0x80036254: swc1        $f4, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->f4.u32l;
            goto L_80036270;
    }
    // 0x80036254: swc1        $f4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f4.u32l;
    // 0x80036258: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003625C: lwc1        $f11, 0x65B8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X65B8);
    // 0x80036260: lwc1        $f10, 0x65BC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X65BC);
    // 0x80036264: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x80036268: mul.d       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x8003626C: cvt.s.d     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f2.fl = CVT_S_D(ctx->f18.d);
L_80036270:
    // 0x80036270: lh          $t8, 0x18($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X18);
    // 0x80036274: lw          $s1, 0x64($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X64);
    // 0x80036278: bne         $t8, $zero, L_800362B0
    if (ctx->r24 != 0) {
        // 0x8003627C: nop
    
            goto L_800362B0;
    }
    // 0x8003627C: nop

    // 0x80036280: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80036284: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80036288: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8003628C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80036290: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80036294: c.lt.d      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.d < ctx->f8.d;
    // 0x80036298: nop

    // 0x8003629C: bc1f        L_800362B0
    if (!c1cs) {
        // 0x800362A0: nop
    
            goto L_800362B0;
    }
    // 0x800362A0: nop

    // 0x800362A4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800362A8: nop

    // 0x800362AC: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
L_800362B0:
    // 0x800362B0: jal         0x8006BFF0
    // 0x800362B4: swc1        $f2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f2.u32l;
    level_header(rdram, ctx);
        goto after_0;
    // 0x800362B4: swc1        $f2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x800362B8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800362BC: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x800362C0: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    // 0x800362C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800362C8: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x800362CC: jal         0x8001BAFC
    // 0x800362D0: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    get_racer_object(rdram, ctx);
        goto after_1;
    // 0x800362D0: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    after_1:
    // 0x800362D4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800362D8: beq         $v0, $zero, L_800363E4
    if (ctx->r2 == 0) {
        // 0x800362DC: sw          $v0, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r2;
            goto L_800363E4;
    }
    // 0x800362DC: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x800362E0: lw          $v0, 0x64($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X64);
    // 0x800362E4: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800362E8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800362EC: lwc1        $f6, 0x38($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X38);
    // 0x800362F0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800362F4: mul.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800362F8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800362FC: lwc1        $f10, 0x50($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X50);
    // 0x80036300: lwc1        $f18, 0xC($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80036304: mul.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80036308: sub.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8003630C: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80036310: lwc1        $f10, 0x14($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X14);
    // 0x80036314: sub.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80036318: lwc1        $f8, 0x40($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8003631C: sub.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80036320: lwc1        $f4, 0x58($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80036324: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80036328: nop

    // 0x8003632C: mul.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80036330: sub.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80036334: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80036338: swc1        $f14, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f14.u32l;
    // 0x8003633C: sub.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x80036340: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x80036344: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80036348: sub.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x8003634C: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x80036350: swc1        $f16, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f16.u32l;
    // 0x80036354: mul.s       $f18, $f16, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80036358: jal         0x800CA030
    // 0x8003635C: add.s       $f12, $f4, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x8003635C: add.s       $f12, $f4, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f18.fl;
    after_2:
    // 0x80036360: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    // 0x80036364: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
    // 0x80036368: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003636C: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80036370: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80036374: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80036378: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8003637C: jal         0x80070990
    // 0x80036380: sub.s       $f14, $f6, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f4.fl;
    arctan2_f(rdram, ctx);
        goto after_3;
    // 0x80036380: sub.s       $f14, $f6, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f4.fl;
    after_3:
    // 0x80036384: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x80036388: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8003638C: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x80036390: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80036394: andi        $t1, $t0, 0xFFFF
    ctx->r9 = ctx->r8 & 0XFFFF;
    // 0x80036398: subu        $v1, $v0, $t1
    ctx->r3 = SUB32(ctx->r2, ctx->r9);
    // 0x8003639C: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800363A0: bne         $at, $zero, L_800363B4
    if (ctx->r1 != 0) {
        // 0x800363A4: slti        $at, $v1, -0x8000
        ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
            goto L_800363B4;
    }
    // 0x800363A4: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x800363A8: lui         $v1, 0xFFFF
    ctx->r3 = S32(0XFFFF << 16);
    // 0x800363AC: ori         $v1, $v1, 0x1
    ctx->r3 = ctx->r3 | 0X1;
    // 0x800363B0: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
L_800363B4:
    // 0x800363B4: beq         $at, $zero, L_800363C4
    if (ctx->r1 == 0) {
        // 0x800363B8: lw          $t2, 0x50($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X50);
            goto L_800363C4;
    }
    // 0x800363B8: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x800363BC: ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
    // 0x800363C0: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
L_800363C4:
    // 0x800363C4: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    // 0x800363C8: lw          $t3, 0x108($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X108);
    // 0x800363CC: nop

    // 0x800363D0: beq         $t3, $zero, L_800363E4
    if (ctx->r11 == 0) {
        // 0x800363D4: nop
    
            goto L_800363E4;
    }
    // 0x800363D4: nop

    // 0x800363D8: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
    // 0x800363DC: sw          $t4, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r12;
    // 0x800363E0: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
L_800363E4:
    // 0x800363E4: jal         0x8006A794
    // 0x800363E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    input_pressed(rdram, ctx);
        goto after_4;
    // 0x800363E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x800363EC: lw          $t5, 0x78($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X78);
    // 0x800363F0: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
    // 0x800363F4: bne         $t5, $zero, L_80036514
    if (ctx->r13 != 0) {
        // 0x800363F8: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80036514;
    }
    // 0x800363F8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800363FC: lwc1        $f18, 0x70($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80036400: lwc1        $f11, 0x65C0($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X65C0);
    // 0x80036404: lwc1        $f10, 0x65C4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X65C4);
    // 0x80036408: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x8003640C: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x80036410: nop

    // 0x80036414: bc1f        L_80036514
    if (!c1cs) {
        // 0x80036418: nop
    
            goto L_80036514;
    }
    // 0x80036418: nop

    // 0x8003641C: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
    // 0x80036420: slti        $at, $v1, -0x1FFF
    ctx->r1 = SIGNED(ctx->r3) < -0X1FFF ? 1 : 0;
    // 0x80036424: bne         $t6, $zero, L_80036514
    if (ctx->r14 != 0) {
        // 0x80036428: nop
    
            goto L_80036514;
    }
    // 0x80036428: nop

    // 0x8003642C: bne         $at, $zero, L_80036514
    if (ctx->r1 != 0) {
        // 0x80036430: slti        $at, $v1, 0x2000
        ctx->r1 = SIGNED(ctx->r3) < 0X2000 ? 1 : 0;
            goto L_80036514;
    }
    // 0x80036430: slti        $at, $v1, 0x2000
    ctx->r1 = SIGNED(ctx->r3) < 0X2000 ? 1 : 0;
    // 0x80036434: beq         $at, $zero, L_80036514
    if (ctx->r1 == 0) {
        // 0x80036438: nop
    
            goto L_80036514;
    }
    // 0x80036438: nop

    // 0x8003643C: lw          $v1, 0x4C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4C);
    // 0x80036440: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x80036444: lh          $t7, 0x14($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X14);
    // 0x80036448: andi        $t1, $v0, 0x2000
    ctx->r9 = ctx->r2 & 0X2000;
    // 0x8003644C: andi        $t8, $t7, 0x8
    ctx->r24 = ctx->r15 & 0X8;
    // 0x80036450: beq         $t8, $zero, L_80036468
    if (ctx->r24 == 0) {
        // 0x80036454: nop
    
            goto L_80036468;
    }
    // 0x80036454: nop

    // 0x80036458: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x8003645C: nop

    // 0x80036460: beq         $t9, $t0, L_80036470
    if (ctx->r25 == ctx->r8) {
        // 0x80036464: andi        $t2, $v0, 0x2000
        ctx->r10 = ctx->r2 & 0X2000;
            goto L_80036470;
    }
    // 0x80036464: andi        $t2, $v0, 0x2000
    ctx->r10 = ctx->r2 & 0X2000;
L_80036468:
    // 0x80036468: beq         $t1, $zero, L_80036514
    if (ctx->r9 == 0) {
        // 0x8003646C: andi        $t2, $v0, 0x2000
        ctx->r10 = ctx->r2 & 0X2000;
            goto L_80036514;
    }
    // 0x8003646C: andi        $t2, $v0, 0x2000
    ctx->r10 = ctx->r2 & 0X2000;
L_80036470:
    // 0x80036470: beq         $t2, $zero, L_8003648C
    if (ctx->r10 == 0) {
        // 0x80036474: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_8003648C;
    }
    // 0x80036474: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80036478: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8003647C: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x80036480: jal         0x80056970
    // 0x80036484: nop

    play_char_horn_sound(rdram, ctx);
        goto after_5;
    // 0x80036484: nop

    after_5:
    // 0x80036488: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8003648C:
    // 0x8003648C: sw          $t3, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r11;
    // 0x80036490: addiu       $t4, $s1, 0x12
    ctx->r12 = ADD32(ctx->r17, 0X12);
    // 0x80036494: addiu       $t5, $s1, 0x13
    ctx->r13 = ADD32(ctx->r17, 0X13);
    // 0x80036498: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8003649C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800364A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800364A4: addiu       $a1, $s1, 0x20
    ctx->r5 = ADD32(ctx->r17, 0X20);
    // 0x800364A8: addiu       $a2, $s1, 0x22
    ctx->r6 = ADD32(ctx->r17, 0X22);
    // 0x800364AC: jal         0x80030790
    // 0x800364B0: addiu       $a3, $s1, 0x11
    ctx->r7 = ADD32(ctx->r17, 0X11);
    get_fog_settings(rdram, ctx);
        goto after_6;
    // 0x800364B0: addiu       $a3, $s1, 0x11
    ctx->r7 = ADD32(ctx->r17, 0X11);
    after_6:
    // 0x800364B4: addiu       $t6, $zero, 0x384
    ctx->r14 = ADD32(0, 0X384);
    // 0x800364B8: addiu       $t7, $zero, 0x3E6
    ctx->r15 = ADD32(0, 0X3E6);
    // 0x800364BC: addiu       $t8, $zero, 0xF0
    ctx->r24 = ADD32(0, 0XF0);
    // 0x800364C0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800364C4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800364C8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800364CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800364D0: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x800364D4: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x800364D8: jal         0x80030E20
    // 0x800364DC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    slowly_change_fog(rdram, ctx);
        goto after_7;
    // 0x800364DC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_7:
    // 0x800364E0: jal         0x800012E8
    // 0x800364E4: nop

    music_channel_reset_all(rdram, ctx);
        goto after_8;
    // 0x800364E4: nop

    after_8:
    // 0x800364E8: jal         0x80000B34
    // 0x800364EC: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    music_play(rdram, ctx);
        goto after_9;
    // 0x800364EC: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    after_9:
    // 0x800364F0: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x800364F4: nop

    // 0x800364F8: beq         $t9, $zero, L_80036514
    if (ctx->r25 == 0) {
        // 0x800364FC: nop
    
            goto L_80036514;
    }
    // 0x800364FC: nop

    // 0x80036500: jal         0x80006AC8
    // 0x80036504: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    racer_sound_free(rdram, ctx);
        goto after_10;
    // 0x80036504: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_10:
    // 0x80036508: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8003650C: nop

    // 0x80036510: sw          $zero, 0x118($t0)
    MEM_W(0X118, ctx->r8) = 0;
L_80036514:
    // 0x80036514: lw          $v0, 0x78($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X78);
    // 0x80036518: nop

    // 0x8003651C: beq         $v0, $zero, L_80036540
    if (ctx->r2 == 0) {
        // 0x80036520: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_80036540;
    }
    // 0x80036520: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80036524: jal         0x8005A41C
    // 0x80036528: nop

    disable_racer_input(rdram, ctx);
        goto after_11;
    // 0x80036528: nop

    after_11:
    // 0x8003652C: jal         0x800AB6F0
    // 0x80036530: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    minimap_fade(rdram, ctx);
        goto after_12;
    // 0x80036530: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_12:
    // 0x80036534: lw          $v0, 0x78($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X78);
    // 0x80036538: nop

    // 0x8003653C: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
L_80036540:
    // 0x80036540: bne         $at, $zero, L_80036558
    if (ctx->r1 != 0) {
        // 0x80036544: nop
    
            goto L_80036558;
    }
    // 0x80036544: nop

    // 0x80036548: jal         0x8009D530
    // 0x8003654C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    npc_dialogue_loop(rdram, ctx);
        goto after_13;
    // 0x8003654C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_13:
    // 0x80036550: b           L_80036564
    // 0x80036554: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80036564;
    // 0x80036554: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80036558:
    // 0x80036558: jal         0x8009D4AC
    // 0x8003655C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    dialogue_npc_finish(rdram, ctx);
        goto after_14;
    // 0x8003655C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_14:
    // 0x80036560: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80036564:
    // 0x80036564: lw          $v0, 0x78($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X78);
    // 0x80036568: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003656C: beq         $v0, $at, L_80036598
    if (ctx->r2 == ctx->r1) {
        // 0x80036570: addiu       $t1, $zero, 0xFF
        ctx->r9 = ADD32(0, 0XFF);
            goto L_80036598;
    }
    // 0x80036570: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80036574: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80036578: beq         $v0, $at, L_8003675C
    if (ctx->r2 == ctx->r1) {
        // 0x8003657C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8003675C;
    }
    // 0x8003657C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80036580: beq         $v0, $at, L_80036894
    if (ctx->r2 == ctx->r1) {
        // 0x80036584: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80036894;
    }
    // 0x80036584: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80036588: beq         $v0, $at, L_800369EC
    if (ctx->r2 == ctx->r1) {
        // 0x8003658C: nop
    
            goto L_800369EC;
    }
    // 0x8003658C: nop

    // 0x80036590: b           L_80036A30
    // 0x80036594: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_80036A30;
    // 0x80036594: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80036598:
    // 0x80036598: sb          $zero, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = 0;
    // 0x8003659C: sb          $t1, 0xD($s1)
    MEM_B(0XD, ctx->r17) = ctx->r9;
    // 0x800365A0: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800365A4: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x800365A8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800365AC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800365B0: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x800365B4: c.lt.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d < ctx->f4.d;
    // 0x800365B8: nop

    // 0x800365BC: bc1f        L_800365E0
    if (!c1cs) {
        // 0x800365C0: lui         $at, 0x4024
        ctx->r1 = S32(0X4024 << 16);
            goto L_800365E0;
    }
    // 0x800365C0: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x800365C4: swc1        $f1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(1 - 1) * 2];
    // 0x800365C8: jal         0x8005A42C
    // 0x800365CC: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    racer_set_dialogue_camera(rdram, ctx);
        goto after_15;
    // 0x800365CC: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    after_15:
    // 0x800365D0: lwc1        $f1, 0x38($sp)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x800365D4: lwc1        $f0, 0x3C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800365D8: nop

    // 0x800365DC: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
L_800365E0:
    // 0x800365E0: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800365E4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800365E8: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800365EC: c.lt.d      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.d < ctx->f0.d;
    // 0x800365F0: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800365F4: bc1f        L_80036710
    if (!c1cs) {
        // 0x800365F8: addiu       $t5, $zero, 0x2
        ctx->r13 = ADD32(0, 0X2);
            goto L_80036710;
    }
    // 0x800365F8: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x800365FC: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80036600: div.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80036604: jal         0x80070990
    // 0x80036608: div.s       $f14, $f6, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    arctan2_f(rdram, ctx);
        goto after_16;
    // 0x80036608: div.s       $f14, $f6, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    after_16:
    // 0x8003660C: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80036610: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80036614: andi        $t2, $a0, 0xFFFF
    ctx->r10 = ctx->r4 & 0XFFFF;
    // 0x80036618: subu        $v1, $v0, $t2
    ctx->r3 = SUB32(ctx->r2, ctx->r10);
    // 0x8003661C: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
    // 0x80036620: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x80036624: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80036628: bne         $at, $zero, L_80036638
    if (ctx->r1 != 0) {
        // 0x8003662C: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_80036638;
    }
    // 0x8003662C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80036630: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80036634: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_80036638:
    // 0x80036638: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x8003663C: beq         $at, $zero, L_80036648
    if (ctx->r1 == 0) {
        // 0x80036640: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_80036648;
    }
    // 0x80036640: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80036644: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_80036648:
    // 0x80036648: blez        $v1, L_8003665C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8003664C: slti        $at, $v1, 0x10
        ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
            goto L_8003665C;
    }
    // 0x8003664C: slti        $at, $v1, 0x10
    ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // 0x80036650: beq         $at, $zero, L_80036660
    if (ctx->r1 == 0) {
        // 0x80036654: lui         $at, 0xC000
        ctx->r1 = S32(0XC000 << 16);
            goto L_80036660;
    }
    // 0x80036654: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80036658: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
L_8003665C:
    // 0x8003665C: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
L_80036660:
    // 0x80036660: sra         $t3, $v1, 4
    ctx->r11 = S32(SIGNED(ctx->r3) >> 4);
    // 0x80036664: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80036668: addu        $t4, $a0, $t3
    ctx->r12 = ADD32(ctx->r4, ctx->r11);
    // 0x8003666C: slti        $at, $v1, 0x801
    ctx->r1 = SIGNED(ctx->r3) < 0X801 ? 1 : 0;
    // 0x80036670: beq         $at, $zero, L_80036680
    if (ctx->r1 == 0) {
        // 0x80036674: sh          $t4, 0x0($s0)
        MEM_H(0X0, ctx->r16) = ctx->r12;
            goto L_80036680;
    }
    // 0x80036674: sh          $t4, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r12;
    // 0x80036678: slti        $at, $v1, -0x800
    ctx->r1 = SIGNED(ctx->r3) < -0X800 ? 1 : 0;
    // 0x8003667C: beq         $at, $zero, L_8003668C
    if (ctx->r1 == 0) {
        // 0x80036680: lui         $at, 0xBF00
        ctx->r1 = S32(0XBF00 << 16);
            goto L_8003668C;
    }
L_80036680:
    // 0x80036680: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x80036684: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80036688: nop

L_8003668C:
    // 0x8003668C: lwc1        $f0, 0x14($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80036690: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80036694: sub.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80036698: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8003669C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800366A0: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x800366A4: mul.d       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f8.d);
    // 0x800366A8: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x800366AC: add.d       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f10.d + ctx->f6.d;
    // 0x800366B0: cvt.s.d     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f18.fl = CVT_S_D(ctx->f4.d);
    // 0x800366B4: swc1        $f18, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f18.u32l;
    // 0x800366B8: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x800366BC: jal         0x80070A04
    // 0x800366C0: nop

    sins_f(rdram, ctx);
        goto after_17;
    // 0x800366C0: nop

    after_17:
    // 0x800366C4: lwc1        $f8, 0x14($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800366C8: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x800366CC: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800366D0: jal         0x80070A38
    // 0x800366D4: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
    coss_f(rdram, ctx);
        goto after_18;
    // 0x800366D4: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
    after_18:
    // 0x800366D8: lwc1        $f6, 0x14($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800366DC: lwc1        $f2, 0x7C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800366E0: mul.s       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800366E4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800366E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800366EC: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    // 0x800366F0: lwc1        $f18, 0x14($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800366F4: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800366F8: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800366FC: nop

    // 0x80036700: mul.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80036704: sub.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80036708: b           L_8003671C
    // 0x8003670C: swc1        $f18, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f18.u32l;
        goto L_8003671C;
    // 0x8003670C: swc1        $f18, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f18.u32l;
L_80036710:
    // 0x80036710: sw          $t5, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r13;
    // 0x80036714: lwc1        $f2, 0x7C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80036718: nop

L_8003671C:
    // 0x8003671C: lwc1        $f8, 0x1C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80036720: lwc1        $f4, 0x20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80036724: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80036728: lwc1        $f18, 0x24($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8003672C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80036730: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80036734: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80036738: mul.s       $f8, $f18, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8003673C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80036740: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80036744: jal         0x80011570
    // 0x80036748: nop

    move_object(rdram, ctx);
        goto after_19;
    // 0x80036748: nop

    after_19:
    // 0x8003674C: jal         0x8006F5C8
    // 0x80036750: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_pause_lockout_timer(rdram, ctx);
        goto after_20;
    // 0x80036750: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_20:
    // 0x80036754: b           L_80036AF4
    // 0x80036758: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
        goto L_80036AF4;
    // 0x80036758: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
L_8003675C:
    // 0x8003675C: jal         0x8005A42C
    // 0x80036760: nop

    racer_set_dialogue_camera(rdram, ctx);
        goto after_21;
    // 0x80036760: nop

    after_21:
    // 0x80036764: lwc1        $f2, 0x7C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80036768: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x8003676C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80036770: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80036774: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x80036778: mul.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x8003677C: sb          $zero, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = 0;
    // 0x80036780: lwc1        $f18, 0x4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80036784: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80036788: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x8003678C: add.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d + ctx->f6.d;
    // 0x80036790: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x80036794: swc1        $f4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f4.u32l;
    // 0x80036798: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x8003679C: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x800367A0: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x800367A4: andi        $t8, $a0, 0xFFFF
    ctx->r24 = ctx->r4 & 0XFFFF;
    // 0x800367A8: subu        $v1, $t7, $t8
    ctx->r3 = SUB32(ctx->r15, ctx->r24);
    // 0x800367AC: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
    // 0x800367B0: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x800367B4: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800367B8: bne         $at, $zero, L_800367C8
    if (ctx->r1 != 0) {
        // 0x800367BC: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_800367C8;
    }
    // 0x800367BC: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800367C0: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x800367C4: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_800367C8:
    // 0x800367C8: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x800367CC: beq         $at, $zero, L_800367D8
    if (ctx->r1 == 0) {
        // 0x800367D0: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_800367D8;
    }
    // 0x800367D0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800367D4: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_800367D8:
    // 0x800367D8: blez        $v1, L_800367EC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800367DC: slti        $at, $v1, 0x10
        ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
            goto L_800367EC;
    }
    // 0x800367DC: slti        $at, $v1, 0x10
    ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // 0x800367E0: beq         $at, $zero, L_800367EC
    if (ctx->r1 == 0) {
        // 0x800367E4: nop
    
            goto L_800367EC;
    }
    // 0x800367E4: nop

    // 0x800367E8: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
L_800367EC:
    // 0x800367EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800367F0: sra         $t9, $v1, 4
    ctx->r25 = S32(SIGNED(ctx->r3) >> 4);
    // 0x800367F4: lwc1        $f1, 0x65C8($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, 0X65C8);
    // 0x800367F8: lwc1        $f0, 0x65CC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X65CC);
    // 0x800367FC: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x80036800: sh          $t0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r8;
    // 0x80036804: lwc1        $f18, 0x78($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80036808: slti        $at, $v1, 0x500
    ctx->r1 = SIGNED(ctx->r3) < 0X500 ? 1 : 0;
    // 0x8003680C: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x80036810: mul.d       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x80036814: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x80036818: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
    // 0x8003681C: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80036820: nop

    // 0x80036824: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x80036828: mul.d       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f0.d);
    // 0x8003682C: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x80036830: beq         $at, $zero, L_8003685C
    if (ctx->r1 == 0) {
        // 0x80036834: swc1        $f6, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
            goto L_8003685C;
    }
    // 0x80036834: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    // 0x80036838: slti        $at, $v1, -0x4FF
    ctx->r1 = SIGNED(ctx->r3) < -0X4FF ? 1 : 0;
    // 0x8003683C: bne         $at, $zero, L_8003685C
    if (ctx->r1 != 0) {
        // 0x80036840: addiu       $t1, $zero, 0x3
        ctx->r9 = ADD32(0, 0X3);
            goto L_8003685C;
    }
    // 0x80036840: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x80036844: sw          $t1, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r9;
    // 0x80036848: addiu       $a0, $zero, 0x141
    ctx->r4 = ADD32(0, 0X141);
    // 0x8003684C: jal         0x80036C0C
    // 0x80036850: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    play_tt_voice_clip(rdram, ctx);
        goto after_22;
    // 0x80036850: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_22:
    // 0x80036854: lwc1        $f2, 0x7C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80036858: nop

L_8003685C:
    // 0x8003685C: lwc1        $f10, 0x1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80036860: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80036864: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80036868: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8003686C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80036870: mul.s       $f8, $f18, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80036874: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80036878: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8003687C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80036880: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80036884: jal         0x80011570
    // 0x80036888: nop

    move_object(rdram, ctx);
        goto after_23;
    // 0x80036888: nop

    after_23:
    // 0x8003688C: b           L_80036AF4
    // 0x80036890: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
        goto L_80036AF4;
    // 0x80036890: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
L_80036894:
    // 0x80036894: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80036898: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8003689C: lwc1        $f1, 0x65D0($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, 0X65D0);
    // 0x800368A0: lwc1        $f0, 0x65D4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X65D4);
    // 0x800368A4: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x800368A8: mul.d       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f0.d);
    // 0x800368AC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800368B0: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x800368B4: swc1        $f6, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f6.u32l;
    // 0x800368B8: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800368BC: sb          $t2, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r10;
    // 0x800368C0: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x800368C4: mul.d       $f18, $f4, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x800368C8: cvt.s.d     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f8.fl = CVT_S_D(ctx->f18.d);
    // 0x800368CC: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    // 0x800368D0: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800368D4: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800368D8: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x800368DC: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x800368E0: add.d       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f10.d + ctx->f18.d;
    // 0x800368E4: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x800368E8: swc1        $f6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f6.u32l;
    // 0x800368EC: jal         0x8005A42C
    // 0x800368F0: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    racer_set_dialogue_camera(rdram, ctx);
        goto after_24;
    // 0x800368F0: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    after_24:
    // 0x800368F4: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x800368F8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800368FC: bne         $v1, $at, L_800369A8
    if (ctx->r3 != ctx->r1) {
        // 0x80036900: addiu       $t3, $zero, 0x4
        ctx->r11 = ADD32(0, 0X4);
            goto L_800369A8;
    }
    // 0x80036900: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80036904: jal         0x8000E4C8
    // 0x80036908: sw          $t3, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r11;
    is_time_trial_enabled(rdram, ctx);
        goto after_25;
    // 0x80036908: sw          $t3, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r11;
    after_25:
    // 0x8003690C: beq         $v0, $zero, L_80036928
    if (ctx->r2 == 0) {
        // 0x80036910: addiu       $a0, $zero, 0x143
        ctx->r4 = ADD32(0, 0X143);
            goto L_80036928;
    }
    // 0x80036910: addiu       $a0, $zero, 0x143
    ctx->r4 = ADD32(0, 0X143);
    // 0x80036914: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    // 0x80036918: jal         0x80036C0C
    // 0x8003691C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    play_tt_voice_clip(rdram, ctx);
        goto after_26;
    // 0x8003691C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_26:
    // 0x80036920: b           L_80036934
    // 0x80036924: lh          $t4, 0x20($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X20);
        goto L_80036934;
    // 0x80036924: lh          $t4, 0x20($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X20);
L_80036928:
    // 0x80036928: jal         0x80036C0C
    // 0x8003692C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    play_tt_voice_clip(rdram, ctx);
        goto after_27;
    // 0x8003692C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_27:
    // 0x80036930: lh          $t4, 0x20($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X20);
L_80036934:
    // 0x80036934: lbu         $a1, 0x11($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X11);
    // 0x80036938: lbu         $a2, 0x12($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X12);
    // 0x8003693C: lbu         $a3, 0x13($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X13);
    // 0x80036940: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80036944: lh          $t5, 0x22($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X22);
    // 0x80036948: addiu       $t6, $zero, 0xB4
    ctx->r14 = ADD32(0, 0XB4);
    // 0x8003694C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80036950: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80036954: jal         0x80030E20
    // 0x80036958: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    slowly_change_fog(rdram, ctx);
        goto after_28;
    // 0x80036958: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_28:
    // 0x8003695C: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x80036960: nop

    // 0x80036964: lbu         $a0, 0x52($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X52);
    // 0x80036968: jal         0x80000B34
    // 0x8003696C: nop

    music_play(rdram, ctx);
        goto after_29;
    // 0x8003696C: nop

    after_29:
    // 0x80036970: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x80036974: nop

    // 0x80036978: lhu         $a0, 0x54($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X54);
    // 0x8003697C: jal         0x80001074
    // 0x80036980: nop

    music_dynamic_set(rdram, ctx);
        goto after_30;
    // 0x80036980: nop

    after_30:
    // 0x80036984: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x80036988: nop

    // 0x8003698C: lb          $a0, 0x3($t9)
    ctx->r4 = MEM_B(ctx->r25, 0X3);
    // 0x80036990: lb          $a1, 0x1D6($t9)
    ctx->r5 = MEM_B(ctx->r25, 0X1D6);
    // 0x80036994: jal         0x80004B40
    // 0x80036998: nop

    racer_sound_init(rdram, ctx);
        goto after_31;
    // 0x80036998: nop

    after_31:
    // 0x8003699C: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800369A0: nop

    // 0x800369A4: sw          $v0, 0x118($t0)
    MEM_W(0X118, ctx->r8) = ctx->r2;
L_800369A8:
    // 0x800369A8: lwc1        $f0, 0x7C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800369AC: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800369B0: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800369B4: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800369B8: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800369BC: addiu       $t1, $zero, 0xB4
    ctx->r9 = ADD32(0, 0XB4);
    // 0x800369C0: sw          $t1, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r9;
    // 0x800369C4: mul.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800369C8: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800369CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800369D0: mul.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800369D4: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x800369D8: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x800369DC: jal         0x80011570
    // 0x800369E0: nop

    move_object(rdram, ctx);
        goto after_32;
    // 0x800369E0: nop

    after_32:
    // 0x800369E4: b           L_80036AF4
    // 0x800369E8: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
        goto L_80036AF4;
    // 0x800369E8: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
L_800369EC:
    // 0x800369EC: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800369F0: lwc1        $f8, 0x7C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800369F4: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x800369F8: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x800369FC: add.d       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f18.d + ctx->f6.d;
    // 0x80036A00: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x80036A04: jal         0x8005A42C
    // 0x80036A08: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
    racer_set_dialogue_camera(rdram, ctx);
        goto after_33;
    // 0x80036A08: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
    after_33:
    // 0x80036A0C: lw          $v0, 0x7C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X7C);
    // 0x80036A10: nop

    // 0x80036A14: slti        $at, $v0, 0x8C
    ctx->r1 = SIGNED(ctx->r2) < 0X8C ? 1 : 0;
    // 0x80036A18: beq         $at, $zero, L_80036AF0
    if (ctx->r1 == 0) {
        // 0x80036A1C: addiu       $t2, $v0, 0x3C
        ctx->r10 = ADD32(ctx->r2, 0X3C);
            goto L_80036AF0;
    }
    // 0x80036A1C: addiu       $t2, $v0, 0x3C
    ctx->r10 = ADD32(ctx->r2, 0X3C);
    // 0x80036A20: sw          $t2, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r10;
    // 0x80036A24: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
    // 0x80036A28: b           L_80036AF0
    // 0x80036A2C: sb          $zero, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = 0;
        goto L_80036AF0;
    // 0x80036A2C: sb          $zero, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = 0;
L_80036A30:
    // 0x80036A30: sb          $zero, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = 0;
    // 0x80036A34: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80036A38: lbu         $t3, 0xD($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0XD);
    // 0x80036A3C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80036A40: bne         $t3, $at, L_80036AB0
    if (ctx->r11 != ctx->r1) {
        // 0x80036A44: swc1        $f8, 0x14($s1)
        MEM_W(0X14, ctx->r17) = ctx->f8.u32l;
            goto L_80036AB0;
    }
    // 0x80036A44: swc1        $f8, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f8.u32l;
    // 0x80036A48: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80036A4C: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80036A50: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x80036A54: jal         0x8001C558
    // 0x80036A58: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    ainode_find_nearest(rdram, ctx);
        goto after_34;
    // 0x80036A58: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_34:
    // 0x80036A5C: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x80036A60: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80036A64: beq         $a0, $at, L_80036AF0
    if (ctx->r4 == ctx->r1) {
        // 0x80036A68: sb          $v0, 0xD($s1)
        MEM_B(0XD, ctx->r17) = ctx->r2;
            goto L_80036AF0;
    }
    // 0x80036A68: sb          $v0, 0xD($s1)
    MEM_B(0XD, ctx->r17) = ctx->r2;
    // 0x80036A6C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80036A70: jal         0x8001CC7C
    // 0x80036A74: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ainode_find_next(rdram, ctx);
        goto after_35;
    // 0x80036A74: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_35:
    // 0x80036A78: lbu         $a1, 0xD($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0XD);
    // 0x80036A7C: sb          $v0, 0xE($s1)
    MEM_B(0XE, ctx->r17) = ctx->r2;
    // 0x80036A80: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x80036A84: jal         0x8001CC7C
    // 0x80036A88: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ainode_find_next(rdram, ctx);
        goto after_36;
    // 0x80036A88: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_36:
    // 0x80036A8C: lbu         $a1, 0xE($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0XE);
    // 0x80036A90: sb          $v0, 0xF($s1)
    MEM_B(0XF, ctx->r17) = ctx->r2;
    // 0x80036A94: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x80036A98: jal         0x8001CC7C
    // 0x80036A9C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ainode_find_next(rdram, ctx);
        goto after_37;
    // 0x80036A9C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_37:
    // 0x80036AA0: lbu         $t4, 0xD($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0XD);
    // 0x80036AA4: sb          $v0, 0x10($s1)
    MEM_B(0X10, ctx->r17) = ctx->r2;
    // 0x80036AA8: b           L_80036AF0
    // 0x80036AAC: sb          $t4, 0xC($s1)
    MEM_B(0XC, ctx->r17) = ctx->r12;
        goto L_80036AF0;
    // 0x80036AAC: sb          $t4, 0xC($s1)
    MEM_B(0XC, ctx->r17) = ctx->r12;
L_80036AB0:
    // 0x80036AB0: lw          $a2, 0x7C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X7C);
    // 0x80036AB4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80036AB8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80036ABC: jal         0x8001C6F8
    // 0x80036AC0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8001C6C4(rdram, ctx);
        goto after_38;
    // 0x80036AC0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_38:
    // 0x80036AC4: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x80036AC8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80036ACC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80036AD0: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x80036AD4: mul.d       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f6.d);
    // 0x80036AD8: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80036ADC: nop

    // 0x80036AE0: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x80036AE4: add.d       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = ctx->f8.d + ctx->f4.d;
    // 0x80036AE8: cvt.s.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f6.fl = CVT_S_D(ctx->f18.d);
    // 0x80036AEC: swc1        $f6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f6.u32l;
L_80036AF0:
    // 0x80036AF0: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
L_80036AF4:
    // 0x80036AF4: lh          $a0, 0x2E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2E);
    // 0x80036AF8: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x80036AFC: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x80036B00: addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
    // 0x80036B04: jal         0x8002B134
    // 0x80036B08: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    func_8002B0F4(rdram, ctx);
        goto after_39;
    // 0x80036B08: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    after_39:
    // 0x80036B0C: beq         $v0, $zero, L_80036B88
    if (ctx->r2 == 0) {
        // 0x80036B10: addiu       $v1, $v0, -0x1
        ctx->r3 = ADD32(ctx->r2, -0X1);
            goto L_80036B88;
    }
    // 0x80036B10: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x80036B14: bltz        $v1, L_80036B88
    if (SIGNED(ctx->r3) < 0) {
        // 0x80036B18: sll         $a0, $v1, 2
        ctx->r4 = S32(ctx->r3 << 2);
            goto L_80036B88;
    }
    // 0x80036B18: sll         $a0, $v1, 2
    ctx->r4 = S32(ctx->r3 << 2);
    // 0x80036B1C: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x80036B20: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80036B24: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80036B28: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x80036B2C: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
L_80036B30:
    // 0x80036B30: nop

    // 0x80036B34: addu        $t6, $t5, $a0
    ctx->r14 = ADD32(ctx->r13, ctx->r4);
    // 0x80036B38: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x80036B3C: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x80036B40: lb          $v1, 0x10($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X10);
    // 0x80036B44: nop

    // 0x80036B48: beq         $a1, $v1, L_80036B80
    if (ctx->r5 == ctx->r3) {
        // 0x80036B4C: nop
    
            goto L_80036B80;
    }
    // 0x80036B4C: nop

    // 0x80036B50: beq         $a2, $v1, L_80036B80
    if (ctx->r6 == ctx->r3) {
        // 0x80036B54: nop
    
            goto L_80036B80;
    }
    // 0x80036B54: nop

    // 0x80036B58: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80036B5C: nop

    // 0x80036B60: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x80036B64: c.lt.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d < ctx->f4.d;
    // 0x80036B68: nop

    // 0x80036B6C: bc1f        L_80036B80
    if (!c1cs) {
        // 0x80036B70: nop
    
            goto L_80036B80;
    }
    // 0x80036B70: nop

    // 0x80036B74: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80036B78: nop

    // 0x80036B7C: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
L_80036B80:
    // 0x80036B80: bgez        $a0, L_80036B30
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80036B84: lw          $t5, 0x48($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X48);
            goto L_80036B30;
    }
    // 0x80036B84: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
L_80036B88:
    // 0x80036B88: lw          $t7, 0x78($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X78);
    // 0x80036B8C: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    // 0x80036B90: beq         $t7, $zero, L_80036BA4
    if (ctx->r15 == 0) {
        // 0x80036B94: sh          $zero, 0x4($s0)
        MEM_H(0X4, ctx->r16) = 0;
            goto L_80036BA4;
    }
    // 0x80036B94: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // 0x80036B98: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80036B9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80036BA0: swc1        $f6, -0x25B0($at)
    MEM_W(-0X25B0, ctx->r1) = ctx->f6.u32l;
L_80036BA4:
    // 0x80036BA4: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80036BA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80036BAC: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x80036BB0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80036BB4: nop

    // 0x80036BB8: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80036BBC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80036BC0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80036BC4: nop

    // 0x80036BC8: cvt.w.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = CVT_W_D(ctx->f8.d);
    // 0x80036BCC: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x80036BD0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80036BD4: jal         0x80061E4C
    // 0x80036BD8: sh          $t9, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r25;
    func_80061C0C(rdram, ctx);
        goto after_40;
    // 0x80036BD8: sh          $t9, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r25;
    after_40:
    // 0x80036BDC: lw          $v0, 0x7C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X7C);
    // 0x80036BE0: lw          $t0, 0x84($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X84);
    // 0x80036BE4: blez        $v0, L_80036BF4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80036BE8: subu        $t1, $v0, $t0
        ctx->r9 = SUB32(ctx->r2, ctx->r8);
            goto L_80036BF4;
    }
    // 0x80036BE8: subu        $t1, $v0, $t0
    ctx->r9 = SUB32(ctx->r2, ctx->r8);
    // 0x80036BEC: b           L_80036BF8
    // 0x80036BF0: sw          $t1, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r9;
        goto L_80036BF8;
    // 0x80036BF0: sw          $t1, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r9;
L_80036BF4:
    // 0x80036BF4: sw          $zero, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = 0;
L_80036BF8:
    // 0x80036BF8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80036BFC: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80036C00: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80036C04: jr          $ra
    // 0x80036C08: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80036C08: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void play_tt_voice_clip(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036C0C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80036C10: addiu       $a3, $a3, -0x25A8
    ctx->r7 = ADD32(ctx->r7, -0X25A8);
    // 0x80036C14: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80036C18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80036C1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80036C20: beq         $a2, $zero, L_80036C4C
    if (ctx->r6 == 0) {
        // 0x80036C24: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80036C4C;
    }
    // 0x80036C24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80036C28: andi        $t6, $a1, 0x1
    ctx->r14 = ctx->r5 & 0X1;
    // 0x80036C2C: beq         $t6, $zero, L_80036C4C
    if (ctx->r14 == 0) {
        // 0x80036C30: nop
    
            goto L_80036C4C;
    }
    // 0x80036C30: nop

    // 0x80036C34: jal         0x8000488C
    // 0x80036C38: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    sndp_stop(rdram, ctx);
        goto after_0;
    // 0x80036C38: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x80036C3C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80036C40: addiu       $a3, $a3, -0x25A8
    ctx->r7 = ADD32(ctx->r7, -0X25A8);
    // 0x80036C44: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x80036C48: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80036C4C:
    // 0x80036C4C: bne         $a2, $zero, L_80036C64
    if (ctx->r6 != 0) {
        // 0x80036C50: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80036C64;
    }
    // 0x80036C50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80036C54: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    // 0x80036C58: jal         0x80001D04
    // 0x80036C5C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    sound_play(rdram, ctx);
        goto after_1;
    // 0x80036C5C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_1:
    // 0x80036C60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80036C64:
    // 0x80036C64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80036C68: jr          $ra
    // 0x80036C6C: nop

    return;
    // 0x80036C6C: nop

;}
