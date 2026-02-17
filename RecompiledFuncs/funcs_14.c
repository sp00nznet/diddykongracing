#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80059208(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059248: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x8005924C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80059250: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80059254: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80059258: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8005925C: sw          $a0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r4;
    // 0x80059260: jal         0x8001BA98
    // 0x80059264: sw          $a2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r6;
    get_checkpoint_count(rdram, ctx);
        goto after_0;
    // 0x80059264: sw          $a2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r6;
    after_0:
    // 0x80059268: beq         $v0, $zero, L_800597D0
    if (ctx->r2 == 0) {
        // 0x8005926C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800597D0;
    }
    // 0x8005926C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80059270: jal         0x8006BFC8
    // 0x80059274: sw          $v0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r2;
    level_id(rdram, ctx);
        goto after_1;
    // 0x80059274: sw          $v0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r2;
    after_1:
    // 0x80059278: lw          $t0, 0xB4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB4);
    // 0x8005927C: bne         $v0, $zero, L_800592A4
    if (ctx->r2 != 0) {
        // 0x80059280: nop
    
            goto L_800592A4;
    }
    // 0x80059280: nop

    // 0x80059284: lb          $t6, 0x192($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X192);
    // 0x80059288: nop

    // 0x8005928C: slt         $at, $t6, $t0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80059290: bne         $at, $zero, L_800592A4
    if (ctx->r1 != 0) {
        // 0x80059294: nop
    
            goto L_800592A4;
    }
    // 0x80059294: nop

    // 0x80059298: sb          $zero, 0x193($s1)
    MEM_B(0X193, ctx->r17) = 0;
    // 0x8005929C: sb          $zero, 0x192($s1)
    MEM_B(0X192, ctx->r17) = 0;
    // 0x800592A0: sh          $zero, 0x190($s1)
    MEM_H(0X190, ctx->r17) = 0;
L_800592A4:
    // 0x800592A4: lwc1        $f6, 0xA8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XA8);
    // 0x800592A8: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800592AC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800592B0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800592B4: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800592B8: sub.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d - ctx->f8.d;
    // 0x800592BC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800592C0: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x800592C4: lwc1        $f17, 0x6EB0($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, 0X6EB0);
    // 0x800592C8: lwc1        $f16, 0x6EB4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6EB4);
    // 0x800592CC: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x800592D0: c.lt.d      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.d < ctx->f16.d;
    // 0x800592D4: lb          $a0, 0x192($s1)
    ctx->r4 = MEM_B(ctx->r17, 0X192);
    // 0x800592D8: bc1f        L_80059390
    if (!c1cs) {
        // 0x800592DC: addiu       $t7, $a0, -0x1
        ctx->r15 = ADD32(ctx->r4, -0X1);
            goto L_80059390;
    }
    // 0x800592DC: addiu       $t7, $a0, -0x1
    ctx->r15 = ADD32(ctx->r4, -0X1);
    // 0x800592E0: sb          $t7, 0x192($s1)
    MEM_B(0X192, ctx->r17) = ctx->r15;
    // 0x800592E4: lb          $a0, 0x192($s1)
    ctx->r4 = MEM_B(ctx->r17, 0X192);
    // 0x800592E8: nop

    // 0x800592EC: bgez        $a0, L_8005930C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800592F0: nop
    
            goto L_8005930C;
    }
    // 0x800592F0: nop

    // 0x800592F4: lb          $v0, 0x193($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X193);
    // 0x800592F8: addu        $t8, $a0, $t0
    ctx->r24 = ADD32(ctx->r4, ctx->r8);
    // 0x800592FC: blez        $v0, L_8005930C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80059300: sb          $t8, 0x192($s1)
        MEM_B(0X192, ctx->r17) = ctx->r24;
            goto L_8005930C;
    }
    // 0x80059300: sb          $t8, 0x192($s1)
    MEM_B(0X192, ctx->r17) = ctx->r24;
    // 0x80059304: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x80059308: sb          $t9, 0x193($s1)
    MEM_B(0X193, ctx->r17) = ctx->r25;
L_8005930C:
    // 0x8005930C: lh          $v0, 0x190($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X190);
    // 0x80059310: nop

    // 0x80059314: slti        $at, $v0, -0x7CFF
    ctx->r1 = SIGNED(ctx->r2) < -0X7CFF ? 1 : 0;
    // 0x80059318: bne         $at, $zero, L_80059324
    if (ctx->r1 != 0) {
        // 0x8005931C: addiu       $t1, $v0, -0x1
        ctx->r9 = ADD32(ctx->r2, -0X1);
            goto L_80059324;
    }
    // 0x8005931C: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x80059320: sh          $t1, 0x190($s1)
    MEM_H(0X190, ctx->r17) = ctx->r9;
L_80059324:
    // 0x80059324: lbu         $t2, 0x1C8($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X1C8);
    // 0x80059328: nop

    // 0x8005932C: beq         $t2, $zero, L_800597D0
    if (ctx->r10 == 0) {
        // 0x80059330: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800597D0;
    }
    // 0x80059330: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80059334: lb          $a0, 0x192($s1)
    ctx->r4 = MEM_B(ctx->r17, 0X192);
    // 0x80059338: jal         0x8001BA34
    // 0x8005933C: sw          $t0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r8;
    get_checkpoint_node(rdram, ctx);
        goto after_2;
    // 0x8005933C: sw          $t0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r8;
    after_2:
    // 0x80059340: lb          $t3, 0x3A($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X3A);
    // 0x80059344: lw          $t0, 0xB4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB4);
    // 0x80059348: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x8005934C: bne         $s0, $t3, L_80059358
    if (ctx->r16 != ctx->r11) {
        // 0x80059350: nop
    
            goto L_80059358;
    }
    // 0x80059350: nop

    // 0x80059354: sb          $zero, 0x1C8($s1)
    MEM_B(0X1C8, ctx->r17) = 0;
L_80059358:
    // 0x80059358: lb          $a0, 0x192($s1)
    ctx->r4 = MEM_B(ctx->r17, 0X192);
    // 0x8005935C: nop

    // 0x80059360: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80059364: bgez        $a0, L_80059370
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80059368: nop
    
            goto L_80059370;
    }
    // 0x80059368: nop

    // 0x8005936C: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
L_80059370:
    // 0x80059370: jal         0x8001BA34
    // 0x80059374: nop

    get_checkpoint_node(rdram, ctx);
        goto after_3;
    // 0x80059374: nop

    after_3:
    // 0x80059378: lb          $t4, 0x3A($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X3A);
    // 0x8005937C: nop

    // 0x80059380: bne         $s0, $t4, L_800597D0
    if (ctx->r16 != ctx->r12) {
        // 0x80059384: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800597D0;
    }
    // 0x80059384: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80059388: b           L_800597CC
    // 0x8005938C: sb          $zero, 0x1C8($s1)
    MEM_B(0X1C8, ctx->r17) = 0;
        goto L_800597CC;
    // 0x8005938C: sb          $zero, 0x1C8($s1)
    MEM_B(0X1C8, ctx->r17) = 0;
L_80059390:
    // 0x80059390: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80059394: nop

    // 0x80059398: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8005939C: nop

    // 0x800593A0: bc1f        L_800593B0
    if (!c1cs) {
        // 0x800593A4: nop
    
            goto L_800593B0;
    }
    // 0x800593A4: nop

    // 0x800593A8: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x800593AC: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
L_800593B0:
    // 0x800593B0: lbu         $a1, 0x1C8($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X1C8);
    // 0x800593B4: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x800593B8: swc1        $f3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(3 - 1) * 2];
    // 0x800593BC: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x800593C0: jal         0x8001BA50
    // 0x800593C4: sw          $t0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r8;
    find_next_checkpoint_node(rdram, ctx);
        goto after_4;
    // 0x800593C4: sw          $t0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r8;
    after_4:
    // 0x800593C8: lb          $s0, 0x192($s1)
    ctx->r16 = MEM_B(ctx->r17, 0X192);
    // 0x800593CC: lw          $t0, 0xB4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB4);
    // 0x800593D0: lwc1        $f2, 0x1C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800593D4: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800593D8: bgez        $s0, L_800593E8
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800593DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800593E8;
    }
    // 0x800593DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800593E0: addiu       $s0, $t0, -0x1
    ctx->r16 = ADD32(ctx->r8, -0X1);
    // 0x800593E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800593E8:
    // 0x800593E8: sw          $t0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r8;
    // 0x800593EC: jal         0x8001BA34
    // 0x800593F0: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    get_checkpoint_node(rdram, ctx);
        goto after_5;
    // 0x800593F0: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    after_5:
    // 0x800593F4: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800593F8: lwc1        $f0, 0x1C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800593FC: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80059400: sub.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80059404: lw          $t0, 0xB4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB4);
    // 0x80059408: mul.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8005940C: addiu       $a2, $sp, 0x9C
    ctx->r6 = ADD32(ctx->r29, 0X9C);
    // 0x80059410: addiu       $a3, $sp, 0x88
    ctx->r7 = ADD32(ctx->r29, 0X88);
    // 0x80059414: addiu       $v1, $sp, 0x74
    ctx->r3 = ADD32(ctx->r29, 0X74);
    // 0x80059418: add.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8005941C: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    // 0x80059420: lb          $s0, 0x192($s1)
    ctx->r16 = MEM_B(ctx->r17, 0X192);
    // 0x80059424: nop

    // 0x80059428: addiu       $s0, $s0, -0x2
    ctx->r16 = ADD32(ctx->r16, -0X2);
    // 0x8005942C: bgez        $s0, L_80059438
    if (SIGNED(ctx->r16) >= 0) {
        // 0x80059430: nop
    
            goto L_80059438;
    }
    // 0x80059430: nop

    // 0x80059434: addu        $s0, $s0, $t0
    ctx->r16 = ADD32(ctx->r16, ctx->r8);
L_80059438:
    // 0x80059438: lbu         $a1, 0x1C8($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X1C8);
    // 0x8005943C: sw          $t0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r8;
    // 0x80059440: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80059444: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x80059448: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x8005944C: jal         0x8001BA50
    // 0x80059450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    find_next_checkpoint_node(rdram, ctx);
        goto after_6;
    // 0x80059450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80059454: lh          $t5, 0x1BA($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X1BA);
    // 0x80059458: lwc1        $f10, 0x1C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8005945C: lwc1        $f16, 0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80059460: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x80059464: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80059468: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8005946C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80059470: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80059474: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80059478: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x8005947C: lw          $t0, 0xB4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB4);
    // 0x80059480: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80059484: addiu       $t8, $sp, 0x88
    ctx->r24 = ADD32(ctx->r29, 0X88);
    // 0x80059488: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8005948C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80059490: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80059494: sltu        $at, $v1, $t8
    ctx->r1 = ctx->r3 < ctx->r24 ? 1 : 0;
    // 0x80059498: swc1        $f16, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f16.u32l;
    // 0x8005949C: lh          $t6, 0x1BC($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X1BC);
    // 0x800594A0: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800594A4: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x800594A8: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800594AC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800594B0: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800594B4: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800594B8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800594BC: swc1        $f16, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f16.u32l;
    // 0x800594C0: lh          $t7, 0x1BA($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X1BA);
    // 0x800594C4: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800594C8: lwc1        $f18, 0x1C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800594CC: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800594D0: neg.s       $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = -ctx->f6.fl;
    // 0x800594D4: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800594D8: lwc1        $f18, 0x18($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X18);
    // 0x800594DC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800594E0: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800594E4: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x800594E8: bne         $s0, $t0, L_800594F4
    if (ctx->r16 != ctx->r8) {
        // 0x800594EC: swc1        $f4, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f4.u32l;
            goto L_800594F4;
    }
    // 0x800594EC: swc1        $f4, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f4.u32l;
    // 0x800594F0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800594F4:
    // 0x800594F4: bne         $at, $zero, L_80059438
    if (ctx->r1 != 0) {
        // 0x800594F8: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_80059438;
    }
    // 0x800594F8: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800594FC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80059500: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x80059504: lwc1        $f1, 0x28($sp)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80059508: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8005950C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80059510: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80059514: c.le.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d <= ctx->f0.d;
    // 0x80059518: addiu       $a0, $sp, 0x9C
    ctx->r4 = ADD32(ctx->r29, 0X9C);
    // 0x8005951C: bc1f        L_80059534
    if (!c1cs) {
        // 0x80059520: addiu       $a3, $sp, 0x54
        ctx->r7 = ADD32(ctx->r29, 0X54);
            goto L_80059534;
    }
    // 0x80059520: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    // 0x80059524: sub.d       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f0.d - ctx->f2.d;
    // 0x80059528: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x8005952C: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x80059530: swc1        $f8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f8.u32l;
L_80059534:
    // 0x80059534: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x80059538: jal         0x80022670
    // 0x8005953C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    cubic_spline_interpolation(rdram, ctx);
        goto after_7;
    // 0x8005953C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x80059540: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x80059544: swc1        $f0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
    // 0x80059548: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    // 0x8005954C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80059550: jal         0x80022670
    // 0x80059554: addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    cubic_spline_interpolation(rdram, ctx);
        goto after_8;
    // 0x80059554: addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    after_8:
    // 0x80059558: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x8005955C: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x80059560: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    // 0x80059564: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80059568: jal         0x80022670
    // 0x8005956C: addiu       $a3, $sp, 0x4C
    ctx->r7 = ADD32(ctx->r29, 0X4C);
    cubic_spline_interpolation(rdram, ctx);
        goto after_9;
    // 0x8005956C: addiu       $a3, $sp, 0x4C
    ctx->r7 = ADD32(ctx->r29, 0X4C);
    after_9:
    // 0x80059570: lwc1        $f2, 0x54($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80059574: lwc1        $f14, 0x4C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80059578: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8005957C: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x80059580: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80059584: jal         0x800CA030
    // 0x80059588: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_10;
    // 0x80059588: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    after_10:
    // 0x8005958C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80059590: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80059594: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x80059598: nop

    // 0x8005959C: bc1t        L_800595C8
    if (c1cs) {
        // 0x800595A0: nop
    
            goto L_800595C8;
    }
    // 0x800595A0: nop

    // 0x800595A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800595A8: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800595AC: div.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800595B0: lwc1        $f14, 0x4C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800595B4: mul.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800595B8: nop

    // 0x800595BC: mul.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x800595C0: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    // 0x800595C4: swc1        $f14, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f14.u32l;
L_800595C8:
    // 0x800595C8: lwc1        $f14, 0x4C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800595CC: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800595D0: jal         0x80070990
    // 0x800595D4: nop

    arctan2_f(rdram, ctx);
        goto after_11;
    // 0x800595D4: nop

    after_11:
    // 0x800595D8: lh          $t9, 0x1A0($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X1A0);
    // 0x800595DC: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x800595E0: andi        $t1, $t9, 0xFFFF
    ctx->r9 = ctx->r25 & 0XFFFF;
    // 0x800595E4: subu        $a0, $v0, $t1
    ctx->r4 = SUB32(ctx->r2, ctx->r9);
    // 0x800595E8: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    // 0x800595EC: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x800595F0: slt         $at, $a0, $at
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800595F4: bne         $at, $zero, L_80059604
    if (ctx->r1 != 0) {
        // 0x800595F8: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_80059604;
    }
    // 0x800595F8: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800595FC: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80059600: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
L_80059604:
    // 0x80059604: slti        $at, $a0, -0x8000
    ctx->r1 = SIGNED(ctx->r4) < -0X8000 ? 1 : 0;
    // 0x80059608: beq         $at, $zero, L_80059614
    if (ctx->r1 == 0) {
        // 0x8005960C: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_80059614;
    }
    // 0x8005960C: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80059610: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
L_80059614:
    // 0x80059614: slti        $at, $a0, 0x4001
    ctx->r1 = SIGNED(ctx->r4) < 0X4001 ? 1 : 0;
    // 0x80059618: beq         $at, $zero, L_80059628
    if (ctx->r1 == 0) {
        // 0x8005961C: slti        $at, $a0, -0x4000
        ctx->r1 = SIGNED(ctx->r4) < -0X4000 ? 1 : 0;
            goto L_80059628;
    }
    // 0x8005961C: slti        $at, $a0, -0x4000
    ctx->r1 = SIGNED(ctx->r4) < -0X4000 ? 1 : 0;
    // 0x80059620: beq         $at, $zero, L_80059678
    if (ctx->r1 == 0) {
        // 0x80059624: nop
    
            goto L_80059678;
    }
    // 0x80059624: nop

L_80059628:
    // 0x80059628: lb          $t2, 0x1D8($s1)
    ctx->r10 = MEM_B(ctx->r17, 0X1D8);
    // 0x8005962C: nop

    // 0x80059630: bne         $t2, $zero, L_80059678
    if (ctx->r10 != 0) {
        // 0x80059634: nop
    
            goto L_80059678;
    }
    // 0x80059634: nop

    // 0x80059638: lbu         $v0, 0x1FC($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X1FC);
    // 0x8005963C: nop

    // 0x80059640: slti        $at, $v0, 0xC8
    ctx->r1 = SIGNED(ctx->r2) < 0XC8 ? 1 : 0;
    // 0x80059644: beq         $at, $zero, L_8005967C
    if (ctx->r1 == 0) {
        // 0x80059648: nop
    
            goto L_8005967C;
    }
    // 0x80059648: nop

    // 0x8005964C: lwc1        $f18, 0x2C($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x80059650: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x80059654: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80059658: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005965C: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x80059660: c.le.d      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.d <= ctx->f16.d;
    // 0x80059664: lw          $t3, 0xC8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC8);
    // 0x80059668: bc1f        L_8005967C
    if (!c1cs) {
        // 0x8005966C: addu        $t4, $v0, $t3
        ctx->r12 = ADD32(ctx->r2, ctx->r11);
            goto L_8005967C;
    }
    // 0x8005966C: addu        $t4, $v0, $t3
    ctx->r12 = ADD32(ctx->r2, ctx->r11);
    // 0x80059670: b           L_8005967C
    // 0x80059674: sb          $t4, 0x1FC($s1)
    MEM_B(0X1FC, ctx->r17) = ctx->r12;
        goto L_8005967C;
    // 0x80059674: sb          $t4, 0x1FC($s1)
    MEM_B(0X1FC, ctx->r17) = ctx->r12;
L_80059678:
    // 0x80059678: sb          $zero, 0x1FC($s1)
    MEM_B(0X1FC, ctx->r17) = 0;
L_8005967C:
    // 0x8005967C: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80059680: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80059684: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    // 0x80059688: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8005968C: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80059690: swc1        $f10, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
    // 0x80059694: neg.s       $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = -ctx->f8.fl;
    // 0x80059698: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8005969C: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800596A0: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800596A4: lw          $v0, 0xC0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC0);
    // 0x800596A8: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800596AC: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
    // 0x800596B0: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800596B4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800596B8: mul.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800596BC: add.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800596C0: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800596C4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800596C8: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800596CC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800596D0: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800596D4: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x800596D8: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800596DC: add.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x800596E0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800596E4: div.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800596E8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800596EC: neg.s       $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = -ctx->f6.fl;
    // 0x800596F0: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x800596F4: swc1        $f10, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
    // 0x800596F8: bc1f        L_80059704
    if (!c1cs) {
        // 0x800596FC: nop
    
            goto L_80059704;
    }
    // 0x800596FC: nop

    // 0x80059700: swc1        $f2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f2.u32l;
L_80059704:
    // 0x80059704: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80059708: nop

    // 0x8005970C: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80059710: nop

    // 0x80059714: bc1f        L_80059720
    if (!c1cs) {
        // 0x80059718: nop
    
            goto L_80059720;
    }
    // 0x80059718: nop

    // 0x8005971C: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
L_80059720:
    // 0x80059720: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80059724: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80059728: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8005972C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80059730: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80059734: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80059738: lh          $t5, 0x1BA($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X1BA);
    // 0x8005973C: cvt.w.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80059740: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x80059744: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x80059748: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8005974C: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x80059750: sh          $t8, 0x1BA($s1)
    MEM_H(0X1BA, ctx->r17) = ctx->r24;
    // 0x80059754: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80059758: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8005975C: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80059760: sub.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80059764: nop

    // 0x80059768: div.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8005976C: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80059770: swc1        $f16, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f16.u32l;
    // 0x80059774: bc1f        L_80059780
    if (!c1cs) {
        // 0x80059778: nop
    
            goto L_80059780;
    }
    // 0x80059778: nop

    // 0x8005977C: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
L_80059780:
    // 0x80059780: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80059784: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80059788: nop

    // 0x8005978C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80059790: nop

    // 0x80059794: bc1f        L_800597A0
    if (!c1cs) {
        // 0x80059798: nop
    
            goto L_800597A0;
    }
    // 0x80059798: nop

    // 0x8005979C: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
L_800597A0:
    // 0x800597A0: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800597A4: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800597A8: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800597AC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800597B0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800597B4: lh          $t9, 0x1BC($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X1BC);
    // 0x800597B8: cvt.w.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800597BC: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x800597C0: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800597C4: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x800597C8: sh          $t3, 0x1BC($s1)
    MEM_H(0X1BC, ctx->r17) = ctx->r11;
L_800597CC:
    // 0x800597CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800597D0:
    // 0x800597D0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800597D4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800597D8: jr          $ra
    // 0x800597DC: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x800597DC: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void get_timestamp_from_frames(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800597E0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800597E4: lw          $t6, 0x6710($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6710);
    // 0x800597E8: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x800597EC: bne         $t6, $at, L_80059838
    if (ctx->r14 != ctx->r1) {
        // 0x800597F0: addiu       $t0, $zero, 0xE10
        ctx->r8 = ADD32(0, 0XE10);
            goto L_80059838;
    }
    // 0x800597F0: addiu       $t0, $zero, 0xE10
    ctx->r8 = ADD32(0, 0XE10);
    // 0x800597F4: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x800597F8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800597FC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80059800: lwc1        $f11, 0x6EB8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6EB8);
    // 0x80059804: lwc1        $f10, 0x6EBC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6EBC);
    // 0x80059808: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8005980C: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x80059810: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80059814: nop

    // 0x80059818: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8005981C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80059820: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80059824: nop

    // 0x80059828: cvt.w.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_D(ctx->f16.d);
    // 0x8005982C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80059830: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x80059834: nop

L_80059838:
    // 0x80059838: div         $zero, $a0, $t0
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r8)));
    // 0x8005983C: addiu       $t1, $zero, 0x3C
    ctx->r9 = ADD32(0, 0X3C);
    // 0x80059840: bne         $t0, $zero, L_8005984C
    if (ctx->r8 != 0) {
        // 0x80059844: nop
    
            goto L_8005984C;
    }
    // 0x80059844: nop

    // 0x80059848: break       7
    do_break(2147850312);
L_8005984C:
    // 0x8005984C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80059850: bne         $t0, $at, L_80059864
    if (ctx->r8 != ctx->r1) {
        // 0x80059854: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80059864;
    }
    // 0x80059854: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80059858: bne         $a0, $at, L_80059864
    if (ctx->r4 != ctx->r1) {
        // 0x8005985C: nop
    
            goto L_80059864;
    }
    // 0x8005985C: nop

    // 0x80059860: break       6
    do_break(2147850336);
L_80059864:
    // 0x80059864: mflo        $v0
    ctx->r2 = lo;
    // 0x80059868: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8005986C: nop

    // 0x80059870: multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80059874: mflo        $t8
    ctx->r24 = lo;
    // 0x80059878: subu        $t9, $a0, $t8
    ctx->r25 = SUB32(ctx->r4, ctx->r24);
    // 0x8005987C: nop

    // 0x80059880: div         $zero, $t9, $t1
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r9)));
    // 0x80059884: bne         $t1, $zero, L_80059890
    if (ctx->r9 != 0) {
        // 0x80059888: nop
    
            goto L_80059890;
    }
    // 0x80059888: nop

    // 0x8005988C: break       7
    do_break(2147850380);
L_80059890:
    // 0x80059890: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80059894: bne         $t1, $at, L_800598A8
    if (ctx->r9 != ctx->r1) {
        // 0x80059898: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800598A8;
    }
    // 0x80059898: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005989C: bne         $t9, $at, L_800598A8
    if (ctx->r25 != ctx->r1) {
        // 0x800598A0: nop
    
            goto L_800598A8;
    }
    // 0x800598A0: nop

    // 0x800598A4: break       6
    do_break(2147850404);
L_800598A8:
    // 0x800598A8: mflo        $v1
    ctx->r3 = lo;
    // 0x800598AC: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    // 0x800598B0: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x800598B4: nop

    // 0x800598B8: multu       $t2, $t0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800598BC: mflo        $t3
    ctx->r11 = lo;
    // 0x800598C0: subu        $t4, $a0, $t3
    ctx->r12 = SUB32(ctx->r4, ctx->r11);
    // 0x800598C4: nop

    // 0x800598C8: multu       $v1, $t1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800598CC: mflo        $t5
    ctx->r13 = lo;
    // 0x800598D0: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x800598D4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800598D8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800598DC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800598E0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800598E4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800598E8: div         $zero, $t7, $t1
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r9)));
    // 0x800598EC: bne         $t1, $zero, L_800598F8
    if (ctx->r9 != 0) {
        // 0x800598F0: nop
    
            goto L_800598F8;
    }
    // 0x800598F0: nop

    // 0x800598F4: break       7
    do_break(2147850484);
L_800598F8:
    // 0x800598F8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800598FC: bne         $t1, $at, L_80059910
    if (ctx->r9 != ctx->r1) {
        // 0x80059900: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80059910;
    }
    // 0x80059900: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80059904: bne         $t7, $at, L_80059910
    if (ctx->r15 != ctx->r1) {
        // 0x80059908: nop
    
            goto L_80059910;
    }
    // 0x80059908: nop

    // 0x8005990C: break       6
    do_break(2147850508);
L_80059910:
    // 0x80059910: mflo        $t8
    ctx->r24 = lo;
    // 0x80059914: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x80059918: jr          $ra
    // 0x8005991C: nop

    return;
    // 0x8005991C: nop

;}
RECOMP_FUNC void allocate_ghost_data(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059920: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80059924: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80059928: lui         $a1, 0xFF00
    ctx->r5 = S32(0XFF00 << 16);
    // 0x8005992C: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x80059930: jal         0x80070EDC
    // 0x80059934: addiu       $a0, $zero, 0x21C0
    ctx->r4 = ADD32(0, 0X21C0);
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x80059934: addiu       $a0, $zero, 0x21C0
    ctx->r4 = ADD32(0, 0X21C0);
    after_0:
    // 0x80059938: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005993C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80059940: addiu       $a0, $a0, -0x24E0
    ctx->r4 = ADD32(ctx->r4, -0X24E0);
    // 0x80059944: addiu       $v1, $v1, -0x24F0
    ctx->r3 = ADD32(ctx->r3, -0X24F0);
    // 0x80059948: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8005994C: addiu       $a1, $a1, -0x24D8
    ctx->r5 = ADD32(ctx->r5, -0X24D8);
    // 0x80059950: addiu       $t7, $v0, 0x10E0
    ctx->r15 = ADD32(ctx->r2, 0X10E0);
    // 0x80059954: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80059958: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8005995C: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x80059960: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // 0x80059964: sh          $zero, 0x2($a0)
    MEM_H(0X2, ctx->r4) = 0;
    // 0x80059968: sh          $zero, 0x4($a0)
    MEM_H(0X4, ctx->r4) = 0;
    // 0x8005996C: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
    // 0x80059970: sh          $zero, 0x2($a1)
    MEM_H(0X2, ctx->r5) = 0;
    // 0x80059974: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80059978: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005997C: sb          $zero, -0x24E3($at)
    MEM_B(-0X24E3, ctx->r1) = 0;
    // 0x80059980: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80059984: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80059988: sh          $t8, -0x24D4($at)
    MEM_H(-0X24D4, ctx->r1) = ctx->r24;
    // 0x8005998C: jr          $ra
    // 0x80059990: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80059990: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void timetrial_reset_player_ghost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059994: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80059998: lb          $t6, -0x24E3($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X24E3);
    // 0x8005999C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800599A0: addiu       $v1, $v1, -0x24E4
    ctx->r3 = ADD32(ctx->r3, -0X24E4);
    // 0x800599A4: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
    // 0x800599A8: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x800599AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800599B0: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x800599B4: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800599B8: sh          $zero, -0x24E0($at)
    MEM_H(-0X24E0, ctx->r1) = 0;
    // 0x800599BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800599C0: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800599C4: sh          $zero, -0x24D8($at)
    MEM_H(-0X24D8, ctx->r1) = 0;
    // 0x800599C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800599CC: jr          $ra
    // 0x800599D0: sh          $zero, -0x24E2($at)
    MEM_H(-0X24E2, ctx->r1) = 0;
    return;
    // 0x800599D0: sh          $zero, -0x24E2($at)
    MEM_H(-0X24E2, ctx->r1) = 0;
;}
RECOMP_FUNC void timetrial_swap_player_ghost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800599D4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800599D8: lb          $t6, -0x24E4($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X24E4);
    // 0x800599DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800599E0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800599E4: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800599E8: sb          $t8, -0x24E3($at)
    MEM_B(-0X24E3, ctx->r1) = ctx->r24;
    // 0x800599EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800599F0: jr          $ra
    // 0x800599F4: sh          $a0, -0x24D4($at)
    MEM_H(-0X24D4, ctx->r1) = ctx->r4;
    return;
    // 0x800599F4: sh          $a0, -0x24D4($at)
    MEM_H(-0X24D4, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void timetrial_map_id(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800599F8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800599FC: lh          $v0, -0x24D4($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X24D4);
    // 0x80059A00: jr          $ra
    // 0x80059A04: nop

    return;
    // 0x80059A04: nop

;}
RECOMP_FUNC void timetrial_load_player_ghost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059A08: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80059A0C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80059A10: lb          $v1, -0x24E4($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X24E4);
    // 0x80059A14: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80059A18: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80059A1C: andi        $t8, $v1, 0x1
    ctx->r24 = ctx->r3 & 0X1;
    // 0x80059A20: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x80059A24: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80059A28: lw          $t2, -0x24F0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X24F0);
    // 0x80059A2C: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80059A30: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80059A34: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80059A38: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80059A3C: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x80059A40: lh          $a1, 0x3E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X3E);
    // 0x80059A44: addiu       $t0, $sp, 0x2E
    ctx->r8 = ADD32(ctx->r29, 0X2E);
    // 0x80059A48: sra         $a2, $t6, 16
    ctx->r6 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80059A4C: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x80059A50: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80059A54: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x80059A58: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80059A5C: jal         0x80074D8C
    // 0x80059A60: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_80074B34(rdram, ctx);
        goto after_0;
    // 0x80059A60: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_0:
    // 0x80059A64: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x80059A68: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80059A6C: beq         $t3, $zero, L_80059AA8
    if (ctx->r11 == 0) {
        // 0x80059A70: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80059AA8;
    }
    // 0x80059A70: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80059A74: bne         $v0, $zero, L_80059AA0
    if (ctx->r2 != 0) {
        // 0x80059A78: addiu       $t7, $zero, -0x1
        ctx->r15 = ADD32(0, -0X1);
            goto L_80059AA0;
    }
    // 0x80059A78: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80059A7C: lh          $t4, 0x2E($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X2E);
    // 0x80059A80: sll         $t5, $v1, 1
    ctx->r13 = S32(ctx->r3 << 1);
    // 0x80059A84: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80059A88: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80059A8C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80059A90: sh          $t4, -0x24E0($at)
    MEM_H(-0X24E0, ctx->r1) = ctx->r12;
    // 0x80059A94: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80059A98: b           L_80059AA8
    // 0x80059A9C: sh          $t6, -0x24D4($at)
    MEM_H(-0X24D4, ctx->r1) = ctx->r14;
        goto L_80059AA8;
    // 0x80059A9C: sh          $t6, -0x24D4($at)
    MEM_H(-0X24D4, ctx->r1) = ctx->r14;
L_80059AA0:
    // 0x80059AA0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80059AA4: sh          $t7, -0x24D4($at)
    MEM_H(-0X24D4, ctx->r1) = ctx->r15;
L_80059AA8:
    // 0x80059AA8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80059AAC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80059AB0: jr          $ra
    // 0x80059AB4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80059AB4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void load_tt_ghost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059AB8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80059ABC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80059AC0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80059AC4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80059AC8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80059ACC: lui         $a1, 0xFF00
    ctx->r5 = S32(0XFF00 << 16);
    // 0x80059AD0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80059AD4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80059AD8: jal         0x80070EDC
    // 0x80059ADC: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x80059ADC: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    after_0:
    // 0x80059AE0: beq         $v0, $zero, L_80059B88
    if (ctx->r2 == 0) {
        // 0x80059AE4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80059B88;
    }
    // 0x80059AE4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80059AE8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80059AEC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80059AF0: addiu       $a0, $zero, 0x31
    ctx->r4 = ADD32(0, 0X31);
    // 0x80059AF4: jal         0x80077190
    // 0x80059AF8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    asset_load(rdram, ctx);
        goto after_1;
    // 0x80059AF8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80059AFC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80059B00: addiu       $v1, $v1, -0x24F0
    ctx->r3 = ADD32(ctx->r3, -0X24F0);
    // 0x80059B04: lw          $a0, 0x8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8);
    // 0x80059B08: nop

    // 0x80059B0C: beq         $a0, $zero, L_80059B20
    if (ctx->r4 == 0) {
        // 0x80059B10: lw          $a2, 0x2C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X2C);
            goto L_80059B20;
    }
    // 0x80059B10: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80059B14: jal         0x80071380
    // 0x80059B18: nop

    mempool_free(rdram, ctx);
        goto after_2;
    // 0x80059B18: nop

    after_2:
    // 0x80059B1C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
L_80059B20:
    // 0x80059B20: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80059B24: addiu       $a2, $a2, -0x8
    ctx->r6 = ADD32(ctx->r6, -0X8);
    // 0x80059B28: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80059B2C: jal         0x80070EDC
    // 0x80059B30: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    mempool_alloc_safe(rdram, ctx);
        goto after_3;
    // 0x80059B30: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_3:
    // 0x80059B34: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80059B38: addiu       $v1, $v1, -0x24F0
    ctx->r3 = ADD32(ctx->r3, -0X24F0);
    // 0x80059B3C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80059B40: beq         $v0, $zero, L_80059B80
    if (ctx->r2 == 0) {
        // 0x80059B44: sw          $v0, 0x8($v1)
        MEM_W(0X8, ctx->r3) = ctx->r2;
            goto L_80059B80;
    }
    // 0x80059B44: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x80059B48: lh          $t7, 0x4($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X4);
    // 0x80059B4C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80059B50: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80059B54: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    // 0x80059B58: lh          $t9, 0x6($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X6);
    // 0x80059B5C: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x80059B60: sh          $t9, -0x24DC($at)
    MEM_H(-0X24DC, ctx->r1) = ctx->r25;
    // 0x80059B64: lw          $a1, 0x8($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X8);
    // 0x80059B68: jal         0x800CA300
    // 0x80059B6C: nop

    bcopy_recomp(rdram, ctx);
        goto after_4;
    // 0x80059B6C: nop

    after_4:
    // 0x80059B70: jal         0x80071380
    // 0x80059B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mempool_free(rdram, ctx);
        goto after_5;
    // 0x80059B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80059B78: b           L_80059B8C
    // 0x80059B7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80059B8C;
    // 0x80059B7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80059B80:
    // 0x80059B80: jal         0x80071380
    // 0x80059B84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mempool_free(rdram, ctx);
        goto after_6;
    // 0x80059B84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_80059B88:
    // 0x80059B88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80059B8C:
    // 0x80059B8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80059B90: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80059B94: jr          $ra
    // 0x80059B98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80059B98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void timetrial_free_staff_ghost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059B9C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80059BA0: lw          $a0, -0x24E8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X24E8);
    // 0x80059BA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80059BA8: beq         $a0, $zero, L_80059BB8
    if (ctx->r4 == 0) {
        // 0x80059BAC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80059BB8;
    }
    // 0x80059BAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80059BB0: jal         0x80071380
    // 0x80059BB4: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x80059BB4: nop

    after_0:
L_80059BB8:
    // 0x80059BB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80059BBC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80059BC0: sw          $zero, -0x24E8($at)
    MEM_W(-0X24E8, ctx->r1) = 0;
    // 0x80059BC4: jr          $ra
    // 0x80059BC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80059BC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void timetrial_write_player_ghost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059BCC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80059BD0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80059BD4: lb          $v0, -0x24E4($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X24E4);
    // 0x80059BD8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80059BDC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80059BE0: sll         $t1, $v0, 1
    ctx->r9 = S32(ctx->r2 << 1);
    // 0x80059BE4: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x80059BE8: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80059BEC: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80059BF0: lh          $t2, -0x24E0($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X24E0);
    // 0x80059BF4: lw          $t4, -0x24F0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X24F0);
    // 0x80059BF8: lh          $t0, 0x3A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X3A);
    // 0x80059BFC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80059C00: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80059C04: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80059C08: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80059C0C: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x80059C10: sll         $t8, $a3, 16
    ctx->r24 = S32(ctx->r7 << 16);
    // 0x80059C14: lh          $a1, 0x2E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X2E);
    // 0x80059C18: sra         $a3, $t8, 16
    ctx->r7 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80059C1C: sra         $a2, $t6, 16
    ctx->r6 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80059C20: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80059C24: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80059C28: jal         0x80075258
    // 0x80059C2C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    func_80075000(rdram, ctx);
        goto after_0;
    // 0x80059C2C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_0:
    // 0x80059C30: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80059C34: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80059C38: jr          $ra
    // 0x80059C3C: nop

    return;
    // 0x80059C3C: nop

;}
RECOMP_FUNC void timetrial_ghost_write(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059C40: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80059C44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80059C48: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80059C4C: lw          $t0, 0x64($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X64);
    // 0x80059C50: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80059C54: lh          $a0, 0x164($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X164);
    // 0x80059C58: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80059C5C: jal         0x80070A38
    // 0x80059C60: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    coss_f(rdram, ctx);
        goto after_0;
    // 0x80059C60: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    after_0:
    // 0x80059C64: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80059C68: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80059C6C: lh          $t7, 0x166($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X166);
    // 0x80059C70: lh          $t6, 0x162($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X162);
    // 0x80059C74: nop

    // 0x80059C78: subu        $a0, $t6, $t7
    ctx->r4 = SUB32(ctx->r14, ctx->r15);
    // 0x80059C7C: sll         $t8, $a0, 16
    ctx->r24 = S32(ctx->r4 << 16);
    // 0x80059C80: jal         0x80070A38
    // 0x80059C84: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    coss_f(rdram, ctx);
        goto after_1;
    // 0x80059C84: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    after_1:
    // 0x80059C88: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80059C8C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80059C90: mul.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80059C94: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80059C98: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80059C9C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80059CA0: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x80059CA4: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x80059CA8: bc1f        L_80059CC8
    if (!c1cs) {
        // 0x80059CAC: addiu       $t1, $t1, -0x24E2
        ctx->r9 = ADD32(ctx->r9, -0X24E2);
            goto L_80059CC8;
    }
    // 0x80059CAC: addiu       $t1, $t1, -0x24E2
    ctx->r9 = ADD32(ctx->r9, -0X24E2);
    // 0x80059CB0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80059CB4: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80059CB8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80059CBC: cvt.d.s     $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f8.d = CVT_D_S(ctx->f12.fl);
    // 0x80059CC0: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x80059CC4: cvt.s.d     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f2.fl = CVT_S_D(ctx->f16.d);
L_80059CC8:
    // 0x80059CC8: lh          $t6, 0x0($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X0);
    // 0x80059CCC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80059CD0: lui         $at, 0x4188
    ctx->r1 = S32(0X4188 << 16);
    // 0x80059CD4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80059CD8: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80059CDC: mul.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80059CE0: sh          $t8, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r24;
    // 0x80059CE4: lh          $a0, 0x0($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X0);
    // 0x80059CE8: nop

    // 0x80059CEC: bgtz        $a0, L_80059E60
    if (SIGNED(ctx->r4) > 0) {
        // 0x80059CF0: sub.s       $f2, $f0, $f18
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f18.fl;
            goto L_80059E60;
    }
    // 0x80059CF0: sub.s       $f2, $f0, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x80059CF4: bgtz        $a0, L_80059E60
    if (SIGNED(ctx->r4) > 0) {
        // 0x80059CF8: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_80059E60;
    }
    // 0x80059CF8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80059CFC: lb          $a1, -0x24E4($a1)
    ctx->r5 = MEM_B(ctx->r5, -0X24E4);
    // 0x80059D00: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80059D04: addiu       $t6, $t6, -0x24E0
    ctx->r14 = ADD32(ctx->r14, -0X24E0);
    // 0x80059D08: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80059D0C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80059D10: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80059D14: sll         $t9, $a1, 1
    ctx->r25 = S32(ctx->r5 << 1);
    // 0x80059D18: addu        $v1, $t9, $t6
    ctx->r3 = ADD32(ctx->r25, ctx->r14);
    // 0x80059D1C: addiu       $t2, $t2, -0x24E4
    ctx->r10 = ADD32(ctx->r10, -0X24E4);
    // 0x80059D20: addiu       $t4, $t4, -0x24F0
    ctx->r12 = ADD32(ctx->r12, -0X24F0);
    // 0x80059D24: addiu       $t5, $t5, -0x24E0
    ctx->r13 = ADD32(ctx->r13, -0X24E0);
    // 0x80059D28: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
L_80059D2C:
    // 0x80059D2C: lh          $a3, 0x0($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X0);
    // 0x80059D30: addiu       $t7, $a0, 0x1E
    ctx->r15 = ADD32(ctx->r4, 0X1E);
    // 0x80059D34: slti        $at, $a3, 0x168
    ctx->r1 = SIGNED(ctx->r7) < 0X168 ? 1 : 0;
    // 0x80059D38: bne         $at, $zero, L_80059D70
    if (ctx->r1 != 0) {
        // 0x80059D3C: sh          $t7, 0x0($t1)
        MEM_H(0X0, ctx->r9) = ctx->r15;
            goto L_80059D70;
    }
    // 0x80059D3C: sh          $t7, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r15;
    // 0x80059D40: jal         0x8006ECF0
    // 0x80059D44: nop

    is_postrace_viewport_active(rdram, ctx);
        goto after_2;
    // 0x80059D44: nop

    after_2:
    // 0x80059D48: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80059D4C: bne         $v0, $zero, L_80059E60
    if (ctx->r2 != 0) {
        // 0x80059D50: addiu       $t2, $t2, -0x24E4
        ctx->r10 = ADD32(ctx->r10, -0X24E4);
            goto L_80059E60;
    }
    // 0x80059D50: addiu       $t2, $t2, -0x24E4
    ctx->r10 = ADD32(ctx->r10, -0X24E4);
    // 0x80059D54: lb          $t9, 0x0($t2)
    ctx->r25 = MEM_B(ctx->r10, 0X0);
    // 0x80059D58: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80059D5C: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x80059D60: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80059D64: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80059D68: b           L_80059E60
    // 0x80059D6C: sh          $t8, -0x24D8($at)
    MEM_H(-0X24D8, ctx->r1) = ctx->r24;
        goto L_80059E60;
    // 0x80059D6C: sh          $t8, -0x24D8($at)
    MEM_H(-0X24D8, ctx->r1) = ctx->r24;
L_80059D70:
    // 0x80059D70: multu       $a3, $t3
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80059D74: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80059D78: addu        $t8, $t4, $t9
    ctx->r24 = ADD32(ctx->r12, ctx->r25);
    // 0x80059D7C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80059D80: lwc1        $f4, 0xC($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80059D84: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80059D88: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80059D8C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80059D90: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x80059D94: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80059D98: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80059D9C: mflo        $t7
    ctx->r15 = lo;
    // 0x80059DA0: addu        $v0, $t7, $t6
    ctx->r2 = ADD32(ctx->r15, ctx->r14);
    // 0x80059DA4: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x80059DA8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80059DAC: lwc1        $f8, 0x10($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X10);
    // 0x80059DB0: nop

    // 0x80059DB4: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x80059DB8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80059DBC: nop

    // 0x80059DC0: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80059DC4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80059DC8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80059DCC: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80059DD0: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80059DD4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80059DD8: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    // 0x80059DDC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80059DE0: sh          $t6, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r14;
    // 0x80059DE4: lwc1        $f18, 0x14($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X14);
    // 0x80059DE8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80059DEC: nop

    // 0x80059DF0: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80059DF4: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x80059DF8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80059DFC: sh          $t8, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r24;
    // 0x80059E00: lh          $t6, 0x160($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X160);
    // 0x80059E04: lh          $t7, 0x0($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X0);
    // 0x80059E08: nop

    // 0x80059E0C: addu        $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // 0x80059E10: sh          $t9, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r25;
    // 0x80059E14: lh          $t7, 0x162($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X162);
    // 0x80059E18: lh          $t8, 0x2($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X2);
    // 0x80059E1C: nop

    // 0x80059E20: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x80059E24: sh          $t6, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r14;
    // 0x80059E28: lh          $t8, 0x164($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X164);
    // 0x80059E2C: lh          $t9, 0x4($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X4);
    // 0x80059E30: nop

    // 0x80059E34: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x80059E38: sh          $t7, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r15;
    // 0x80059E3C: lb          $a1, 0x0($t2)
    ctx->r5 = MEM_B(ctx->r10, 0X0);
    // 0x80059E40: lh          $a0, 0x0($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X0);
    // 0x80059E44: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x80059E48: addu        $v1, $t5, $t6
    ctx->r3 = ADD32(ctx->r13, ctx->r14);
    // 0x80059E4C: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    // 0x80059E50: nop

    // 0x80059E54: addiu       $t8, $t9, 0x1
    ctx->r24 = ADD32(ctx->r25, 0X1);
    // 0x80059E58: blez        $a0, L_80059D2C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80059E5C: sh          $t8, 0x0($v1)
        MEM_H(0X0, ctx->r3) = ctx->r24;
            goto L_80059D2C;
    }
    // 0x80059E5C: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
L_80059E60:
    // 0x80059E60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80059E64: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80059E68: jr          $ra
    // 0x80059E6C: nop

    return;
    // 0x80059E6C: nop

;}
RECOMP_FUNC void timetrial_ghost_full(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059E70: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80059E74: lb          $t6, -0x24E4($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X24E4);
    // 0x80059E78: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80059E7C: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80059E80: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x80059E84: lh          $v0, -0x24D8($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X24D8);
    // 0x80059E88: jr          $ra
    // 0x80059E8C: nop

    return;
    // 0x80059E8C: nop

;}
RECOMP_FUNC void timetrial_ghost_read(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059E90: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80059E94: lb          $a1, -0x24E4($a1)
    ctx->r5 = MEM_B(ctx->r5, -0X24E4);
    // 0x80059E98: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80059E9C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80059EA0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80059EA4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80059EA8: andi        $t6, $a1, 0x1
    ctx->r14 = ctx->r5 & 0X1;
    // 0x80059EAC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80059EB0: jal         0x8001B3E0
    // 0x80059EB4: sw          $t6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r14;
    timetrial_staff_ghost_check(rdram, ctx);
        goto after_0;
    // 0x80059EB4: sw          $t6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80059EB8: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x80059EBC: beq         $v0, $zero, L_80059EC8
    if (ctx->r2 == 0) {
        // 0x80059EC0: lui         $at, 0x41F0
        ctx->r1 = S32(0X41F0 << 16);
            goto L_80059EC8;
    }
    // 0x80059EC0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80059EC4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_80059EC8:
    // 0x80059EC8: lw          $t7, 0x78($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X78);
    // 0x80059ECC: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x80059ED0: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80059ED4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80059ED8: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80059EDC: lw          $t8, 0x300($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X300);
    // 0x80059EE0: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x80059EE4: bne         $t8, $zero, L_80059F20
    if (ctx->r24 != 0) {
        // 0x80059EE8: div.s       $f2, $f0, $f6
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
            goto L_80059F20;
    }
    // 0x80059EE8: div.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80059EEC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80059EF0: bne         $a1, $at, L_80059F20
    if (ctx->r5 != ctx->r1) {
        // 0x80059EF4: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80059F20;
    }
    // 0x80059EF4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80059EF8: lwc1        $f11, 0x6EC0($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6EC0);
    // 0x80059EFC: lwc1        $f10, 0x6EC4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6EC4);
    // 0x80059F00: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x80059F04: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x80059F08: lui         $at, 0x403E
    ctx->r1 = S32(0X403E << 16);
    // 0x80059F0C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80059F10: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80059F14: nop

    // 0x80059F18: div.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = DIV_D(ctx->f16.d, ctx->f18.d);
    // 0x80059F1C: cvt.s.d     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f2.fl = CVT_S_D(ctx->f4.d);
L_80059F20:
    // 0x80059F20: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80059F24: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80059F28: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80059F2C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80059F30: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80059F34: addu        $t5, $t5, $t6
    ctx->r13 = ADD32(ctx->r13, ctx->r14);
    // 0x80059F38: cvt.w.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    ctx->f6.u32l = CVT_W_S(ctx->f2.fl);
    // 0x80059F3C: lh          $t5, -0x24E0($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X24E0);
    // 0x80059F40: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x80059F44: addiu       $t7, $t5, -0x2
    ctx->r15 = ADD32(ctx->r13, -0X2);
    // 0x80059F48: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80059F4C: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80059F50: bne         $at, $zero, L_80059F7C
    if (ctx->r1 != 0) {
        // 0x80059F54: sw          $v1, 0x60($sp)
        MEM_W(0X60, ctx->r29) = ctx->r3;
            goto L_80059F7C;
    }
    // 0x80059F54: sw          $v1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r3;
    // 0x80059F58: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x80059F5C: nop

    // 0x80059F60: lbu         $v1, 0x1F7($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X1F7);
    // 0x80059F64: nop

    // 0x80059F68: blez        $v1, L_80059F74
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80059F6C: addiu       $t8, $v1, -0x1
        ctx->r24 = ADD32(ctx->r3, -0X1);
            goto L_80059F74;
    }
    // 0x80059F6C: addiu       $t8, $v1, -0x1
    ctx->r24 = ADD32(ctx->r3, -0X1);
    // 0x80059F70: sb          $t8, 0x1F7($v0)
    MEM_B(0X1F7, ctx->r2) = ctx->r24;
L_80059F74:
    // 0x80059F74: b           L_8005A40C
    // 0x80059F78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005A40C;
    // 0x80059F78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80059F7C:
    // 0x80059F7C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80059F80: beq         $a1, $at, L_80059FC8
    if (ctx->r5 == ctx->r1) {
        // 0x80059F84: addiu       $t1, $v1, -0x1
        ctx->r9 = ADD32(ctx->r3, -0X1);
            goto L_80059FC8;
    }
    // 0x80059F84: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
    // 0x80059F88: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x80059F8C: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x80059F90: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
    // 0x80059F94: jal         0x8006BFC8
    // 0x80059F98: swc1        $f2, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f2.u32l;
    level_id(rdram, ctx);
        goto after_1;
    // 0x80059F98: swc1        $f2, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x80059F9C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80059FA0: lh          $t9, -0x24D4($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X24D4);
    // 0x80059FA4: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x80059FA8: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x80059FAC: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x80059FB0: lwc1        $f2, 0x94($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80059FB4: beq         $v0, $t9, L_80059FC8
    if (ctx->r2 == ctx->r25) {
        // 0x80059FB8: addiu       $t1, $v1, -0x1
        ctx->r9 = ADD32(ctx->r3, -0X1);
            goto L_80059FC8;
    }
    // 0x80059FB8: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
    // 0x80059FBC: b           L_8005A40C
    // 0x80059FC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005A40C;
    // 0x80059FC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80059FC4: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
L_80059FC8:
    // 0x80059FC8: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80059FCC: lui         $ra, 0x8012
    ctx->r31 = S32(0X8012 << 16);
    // 0x80059FD0: addu        $ra, $ra, $t6
    ctx->r31 = ADD32(ctx->r31, ctx->r14);
    // 0x80059FD4: sll         $t7, $t1, 2
    ctx->r15 = S32(ctx->r9 << 2);
    // 0x80059FD8: lw          $ra, -0x24F0($ra)
    ctx->r31 = MEM_W(ctx->r31, -0X24F0);
    // 0x80059FDC: subu        $t7, $t7, $t1
    ctx->r15 = SUB32(ctx->r15, ctx->r9);
    // 0x80059FE0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80059FE4: addiu       $a3, $sp, 0x84
    ctx->r7 = ADD32(ctx->r29, 0X84);
    // 0x80059FE8: addiu       $t0, $sp, 0x74
    ctx->r8 = ADD32(ctx->r29, 0X74);
    // 0x80059FEC: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    // 0x80059FF0: addiu       $t4, $sp, 0x74
    ctx->r12 = ADD32(ctx->r29, 0X74);
    // 0x80059FF4: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80059FF8: addu        $t2, $ra, $t7
    ctx->r10 = ADD32(ctx->r31, ctx->r15);
L_80059FFC:
    // 0x80059FFC: bne         $t1, $t3, L_8005A068
    if (ctx->r9 != ctx->r11) {
        // 0x8005A000: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_8005A068;
    }
    // 0x8005A000: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8005A004: lh          $v1, 0xC($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XC);
    // 0x8005A008: lh          $t9, 0x18($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X18);
    // 0x8005A00C: addu        $t8, $v1, $v1
    ctx->r24 = ADD32(ctx->r3, ctx->r3);
    // 0x8005A010: subu        $t6, $t8, $t9
    ctx->r14 = SUB32(ctx->r24, ctx->r25);
    // 0x8005A014: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8005A018: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x8005A01C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8005A020: swc1        $f10, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f10.u32l;
    // 0x8005A024: lh          $a0, 0x2($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X2);
    // 0x8005A028: lh          $t8, 0xE($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XE);
    // 0x8005A02C: addu        $t7, $a0, $a0
    ctx->r15 = ADD32(ctx->r4, ctx->r4);
    // 0x8005A030: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x8005A034: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8005A038: nop

    // 0x8005A03C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8005A040: swc1        $f18, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f18.u32l;
    // 0x8005A044: lh          $a1, 0x4($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X4);
    // 0x8005A048: lh          $t7, 0x10($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X10);
    // 0x8005A04C: addu        $t6, $a1, $a1
    ctx->r14 = ADD32(ctx->r5, ctx->r5);
    // 0x8005A050: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x8005A054: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8005A058: nop

    // 0x8005A05C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005A060: b           L_8005A120
    // 0x8005A064: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
        goto L_8005A120;
    // 0x8005A064: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
L_8005A068:
    // 0x8005A068: slt         $at, $t1, $t5
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8005A06C: bne         $at, $zero, L_8005A0D8
    if (ctx->r1 != 0) {
        // 0x8005A070: nop
    
            goto L_8005A0D8;
    }
    // 0x8005A070: nop

    // 0x8005A074: lh          $v1, 0x0($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X0);
    // 0x8005A078: lh          $t6, -0xC($v0)
    ctx->r14 = MEM_H(ctx->r2, -0XC);
    // 0x8005A07C: addu        $t9, $v1, $v1
    ctx->r25 = ADD32(ctx->r3, ctx->r3);
    // 0x8005A080: subu        $t7, $t9, $t6
    ctx->r15 = SUB32(ctx->r25, ctx->r14);
    // 0x8005A084: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8005A088: nop

    // 0x8005A08C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8005A090: swc1        $f10, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f10.u32l;
    // 0x8005A094: lh          $a0, 0x2($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X2);
    // 0x8005A098: lh          $t9, -0xA($v0)
    ctx->r25 = MEM_H(ctx->r2, -0XA);
    // 0x8005A09C: addu        $t8, $a0, $a0
    ctx->r24 = ADD32(ctx->r4, ctx->r4);
    // 0x8005A0A0: subu        $t6, $t8, $t9
    ctx->r14 = SUB32(ctx->r24, ctx->r25);
    // 0x8005A0A4: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8005A0A8: nop

    // 0x8005A0AC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8005A0B0: swc1        $f18, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f18.u32l;
    // 0x8005A0B4: lh          $a1, 0x4($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X4);
    // 0x8005A0B8: lh          $t8, -0x8($v0)
    ctx->r24 = MEM_H(ctx->r2, -0X8);
    // 0x8005A0BC: addu        $t7, $a1, $a1
    ctx->r15 = ADD32(ctx->r5, ctx->r5);
    // 0x8005A0C0: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x8005A0C4: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8005A0C8: nop

    // 0x8005A0CC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005A0D0: b           L_8005A120
    // 0x8005A0D4: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
        goto L_8005A120;
    // 0x8005A0D4: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
L_8005A0D8:
    // 0x8005A0D8: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x8005A0DC: nop

    // 0x8005A0E0: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8005A0E4: nop

    // 0x8005A0E8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8005A0EC: swc1        $f10, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f10.u32l;
    // 0x8005A0F0: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x8005A0F4: nop

    // 0x8005A0F8: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x8005A0FC: nop

    // 0x8005A100: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8005A104: swc1        $f18, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f18.u32l;
    // 0x8005A108: lh          $t8, 0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4);
    // 0x8005A10C: nop

    // 0x8005A110: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8005A114: nop

    // 0x8005A118: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005A11C: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
L_8005A120:
    // 0x8005A120: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8005A124: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8005A128: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8005A12C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8005A130: bne         $a2, $t4, L_80059FFC
    if (ctx->r6 != ctx->r12) {
        // 0x8005A134: addiu       $t2, $t2, 0xC
        ctx->r10 = ADD32(ctx->r10, 0XC);
            goto L_80059FFC;
    }
    // 0x8005A134: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x8005A138: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x8005A13C: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x8005A140: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8005A144: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8005A148: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8005A14C: subu        $t6, $t6, $t9
    ctx->r14 = SUB32(ctx->r14, ctx->r25);
    // 0x8005A150: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8005A154: sub.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x8005A158: addu        $v0, $ra, $t6
    ctx->r2 = ADD32(ctx->r31, ctx->r14);
    // 0x8005A15C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8005A160: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x8005A164: swc1        $f2, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f2.u32l;
    // 0x8005A168: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005A16C: jal         0x80022574
    // 0x8005A170: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
    catmull_rom_interpolation(rdram, ctx);
        goto after_2;
    // 0x8005A170: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
    after_2:
    // 0x8005A174: lwc1        $f2, 0x94($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8005A178: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x8005A17C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8005A180: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    // 0x8005A184: jal         0x80022574
    // 0x8005A188: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    catmull_rom_interpolation(rdram, ctx);
        goto after_3;
    // 0x8005A188: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8005A18C: lwc1        $f2, 0x94($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8005A190: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x8005A194: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8005A198: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x8005A19C: jal         0x80022574
    // 0x8005A1A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    catmull_rom_interpolation(rdram, ctx);
        goto after_4;
    // 0x8005A1A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x8005A1A4: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
    // 0x8005A1A8: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x8005A1AC: lwc1        $f2, 0x94($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8005A1B0: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
    // 0x8005A1B4: lh          $a0, 0xA($v0)
    ctx->r4 = MEM_H(ctx->r2, 0XA);
    // 0x8005A1B8: addiu       $a2, $v0, 0xC
    ctx->r6 = ADD32(ctx->r2, 0XC);
    // 0x8005A1BC: lh          $t7, 0xA($a2)
    ctx->r15 = MEM_H(ctx->r6, 0XA);
    // 0x8005A1C0: andi        $t8, $a0, 0xFFFF
    ctx->r24 = ctx->r4 & 0XFFFF;
    // 0x8005A1C4: ori         $a3, $zero, 0x8001
    ctx->r7 = 0 | 0X8001;
    // 0x8005A1C8: subu        $v1, $t7, $t8
    ctx->r3 = SUB32(ctx->r15, ctx->r24);
    // 0x8005A1CC: slt         $at, $v1, $a3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8005A1D0: bne         $at, $zero, L_8005A1E0
    if (ctx->r1 != 0) {
        // 0x8005A1D4: lui         $t0, 0xFFFF
        ctx->r8 = S32(0XFFFF << 16);
            goto L_8005A1E0;
    }
    // 0x8005A1D4: lui         $t0, 0xFFFF
    ctx->r8 = S32(0XFFFF << 16);
    // 0x8005A1D8: ori         $t0, $t0, 0x1
    ctx->r8 = ctx->r8 | 0X1;
    // 0x8005A1DC: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
L_8005A1E0:
    // 0x8005A1E0: lui         $t0, 0xFFFF
    ctx->r8 = S32(0XFFFF << 16);
    // 0x8005A1E4: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x8005A1E8: beq         $at, $zero, L_8005A1F8
    if (ctx->r1 == 0) {
        // 0x8005A1EC: ori         $t0, $t0, 0x1
        ctx->r8 = ctx->r8 | 0X1;
            goto L_8005A1F8;
    }
    // 0x8005A1EC: ori         $t0, $t0, 0x1
    ctx->r8 = ctx->r8 | 0X1;
    // 0x8005A1F0: ori         $t1, $zero, 0xFFFF
    ctx->r9 = 0 | 0XFFFF;
    // 0x8005A1F4: addu        $v1, $v1, $t1
    ctx->r3 = ADD32(ctx->r3, ctx->r9);
L_8005A1F8:
    // 0x8005A1F8: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
    // 0x8005A1FC: ori         $t1, $zero, 0xFFFF
    ctx->r9 = 0 | 0XFFFF;
    // 0x8005A200: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8005A204: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8005A208: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8005A20C: nop

    // 0x8005A210: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8005A214: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005A218: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005A21C: nop

    // 0x8005A220: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8005A224: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x8005A228: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8005A22C: addu        $t6, $a0, $t8
    ctx->r14 = ADD32(ctx->r4, ctx->r24);
    // 0x8005A230: sh          $t6, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r14;
    // 0x8005A234: lh          $a1, 0x8($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X8);
    // 0x8005A238: lh          $t9, 0x8($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X8);
    // 0x8005A23C: andi        $t7, $a1, 0xFFFF
    ctx->r15 = ctx->r5 & 0XFFFF;
    // 0x8005A240: subu        $v1, $t9, $t7
    ctx->r3 = SUB32(ctx->r25, ctx->r15);
    // 0x8005A244: slt         $at, $v1, $a3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8005A248: bne         $at, $zero, L_8005A258
    if (ctx->r1 != 0) {
        // 0x8005A24C: slti        $at, $v1, -0x8000
        ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
            goto L_8005A258;
    }
    // 0x8005A24C: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x8005A250: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x8005A254: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
L_8005A258:
    // 0x8005A258: beq         $at, $zero, L_8005A264
    if (ctx->r1 == 0) {
        // 0x8005A25C: nop
    
            goto L_8005A264;
    }
    // 0x8005A25C: nop

    // 0x8005A260: addu        $v1, $v1, $t1
    ctx->r3 = ADD32(ctx->r3, ctx->r9);
L_8005A264:
    // 0x8005A264: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x8005A268: nop

    // 0x8005A26C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8005A270: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8005A274: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8005A278: nop

    // 0x8005A27C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8005A280: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005A284: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005A288: nop

    // 0x8005A28C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8005A290: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x8005A294: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8005A298: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x8005A29C: sh          $t8, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r24;
    // 0x8005A2A0: lh          $a0, 0x6($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X6);
    // 0x8005A2A4: lh          $t6, 0x6($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X6);
    // 0x8005A2A8: andi        $t9, $a0, 0xFFFF
    ctx->r25 = ctx->r4 & 0XFFFF;
    // 0x8005A2AC: subu        $v1, $t6, $t9
    ctx->r3 = SUB32(ctx->r14, ctx->r25);
    // 0x8005A2B0: slt         $at, $v1, $a3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8005A2B4: bne         $at, $zero, L_8005A2C4
    if (ctx->r1 != 0) {
        // 0x8005A2B8: slti        $at, $v1, -0x8000
        ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
            goto L_8005A2C4;
    }
    // 0x8005A2B8: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x8005A2BC: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x8005A2C0: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
L_8005A2C4:
    // 0x8005A2C4: beq         $at, $zero, L_8005A2D0
    if (ctx->r1 == 0) {
        // 0x8005A2C8: nop
    
            goto L_8005A2D0;
    }
    // 0x8005A2C8: nop

    // 0x8005A2CC: addu        $v1, $v1, $t1
    ctx->r3 = ADD32(ctx->r3, ctx->r9);
L_8005A2D0:
    // 0x8005A2D0: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x8005A2D4: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005A2D8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005A2DC: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8005A2E0: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x8005A2E4: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8005A2E8: sw          $zero, 0x74($s0)
    MEM_W(0X74, ctx->r16) = 0;
    // 0x8005A2EC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8005A2F0: nop

    // 0x8005A2F4: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8005A2F8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005A2FC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005A300: nop

    // 0x8005A304: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8005A308: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x8005A30C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8005A310: addu        $t7, $a0, $t9
    ctx->r15 = ADD32(ctx->r4, ctx->r25);
    // 0x8005A314: sh          $t7, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r15;
    // 0x8005A318: swc1        $f2, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f2.u32l;
    // 0x8005A31C: jal         0x80029F58
    // 0x8005A320: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
    get_level_segment_index_from_position(rdram, ctx);
        goto after_5;
    // 0x8005A320: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
    after_5:
    // 0x8005A324: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x8005A328: lwc1        $f2, 0x94($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8005A32C: sh          $v0, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r2;
    // 0x8005A330: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8005A334: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005A338: addiu       $t6, $t8, 0x3
    ctx->r14 = ADD32(ctx->r24, 0X3);
    // 0x8005A33C: bne         $t5, $t6, L_8005A40C
    if (ctx->r13 != ctx->r14) {
        // 0x8005A340: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8005A40C;
    }
    // 0x8005A340: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005A344: lwc1        $f13, 0x6EC8($at)
    ctx->f_odd[(13 - 1) * 2] = MEM_W(ctx->r1, 0X6EC8);
    // 0x8005A348: lwc1        $f12, 0x6ECC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X6ECC);
    // 0x8005A34C: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x8005A350: c.le.d      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.d <= ctx->f0.d;
    // 0x8005A354: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x8005A358: bc1f        L_8005A368
    if (!c1cs) {
        // 0x8005A35C: lui         $at, 0x4058
        ctx->r1 = S32(0X4058 << 16);
            goto L_8005A368;
    }
    // 0x8005A35C: lui         $at, 0x4058
    ctx->r1 = S32(0X4058 << 16);
    // 0x8005A360: b           L_8005A408
    // 0x8005A364: sb          $zero, 0x1F7($v0)
    MEM_B(0X1F7, ctx->r2) = 0;
        goto L_8005A408;
    // 0x8005A364: sb          $zero, 0x1F7($v0)
    MEM_B(0X1F7, ctx->r2) = 0;
L_8005A368:
    // 0x8005A368: sub.d       $f16, $f12, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = ctx->f12.d - ctx->f0.d;
    // 0x8005A36C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8005A370: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005A374: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8005A378: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x8005A37C: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8005A380: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8005A384: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8005A388: nop

    // 0x8005A38C: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x8005A390: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8005A394: nop

    // 0x8005A398: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8005A39C: beq         $t7, $zero, L_8005A3EC
    if (ctx->r15 == 0) {
        // 0x8005A3A0: nop
    
            goto L_8005A3EC;
    }
    // 0x8005A3A0: nop

    // 0x8005A3A4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8005A3A8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8005A3AC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8005A3B0: sub.d       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f6.d = ctx->f4.d - ctx->f6.d;
    // 0x8005A3B4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005A3B8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8005A3BC: nop

    // 0x8005A3C0: cvt.w.d     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_D(ctx->f6.d);
    // 0x8005A3C4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8005A3C8: nop

    // 0x8005A3CC: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8005A3D0: bne         $t7, $zero, L_8005A3E4
    if (ctx->r15 != 0) {
        // 0x8005A3D4: nop
    
            goto L_8005A3E4;
    }
    // 0x8005A3D4: nop

    // 0x8005A3D8: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8005A3DC: b           L_8005A3FC
    // 0x8005A3E0: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_8005A3FC;
    // 0x8005A3E0: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_8005A3E4:
    // 0x8005A3E4: b           L_8005A3FC
    // 0x8005A3E8: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_8005A3FC;
    // 0x8005A3E8: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
L_8005A3EC:
    // 0x8005A3EC: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8005A3F0: nop

    // 0x8005A3F4: bltz        $t7, L_8005A3E4
    if (SIGNED(ctx->r15) < 0) {
        // 0x8005A3F8: nop
    
            goto L_8005A3E4;
    }
    // 0x8005A3F8: nop

L_8005A3FC:
    // 0x8005A3FC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8005A400: sb          $t7, 0x1F7($v0)
    MEM_B(0X1F7, ctx->r2) = ctx->r15;
    // 0x8005A404: nop

L_8005A408:
    // 0x8005A408: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005A40C:
    // 0x8005A40C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005A410: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005A414: jr          $ra
    // 0x8005A418: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x8005A418: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void disable_racer_input(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A41C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005A420: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005A424: jr          $ra
    // 0x8005A428: sb          $t6, -0x24FC($at)
    MEM_B(-0X24FC, ctx->r1) = ctx->r14;
    return;
    // 0x8005A428: sb          $t6, -0x24FC($at)
    MEM_B(-0X24FC, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void racer_set_dialogue_camera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A42C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005A430: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005A434: jr          $ra
    // 0x8005A438: sb          $t6, -0x24FD($at)
    MEM_B(-0X24FD, ctx->r1) = ctx->r14;
    return;
    // 0x8005A438: sb          $t6, -0x24FD($at)
    MEM_B(-0X24FD, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void drm_checksum_balloon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A43C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8005A440: lw          $a1, -0x2F40($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X2F40);
    // 0x8005A444: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005A448: blez        $a1, L_8005A470
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8005A44C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8005A470;
    }
    // 0x8005A44C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005A450: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x8005A454: addiu       $v1, $v1, -0x4B04
    ctx->r3 = ADD32(ctx->r3, -0X4B04);
L_8005A458:
    // 0x8005A458: addu        $t6, $v1, $a0
    ctx->r14 = ADD32(ctx->r3, ctx->r4);
    // 0x8005A45C: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x8005A460: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8005A464: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8005A468: bne         $at, $zero, L_8005A458
    if (ctx->r1 != 0) {
        // 0x8005A46C: addu        $v0, $v0, $t7
        ctx->r2 = ADD32(ctx->r2, ctx->r15);
            goto L_8005A458;
    }
    // 0x8005A46C: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
L_8005A470:
    // 0x8005A470: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8005A474: lw          $t8, -0x2CC0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2CC0);
    // 0x8005A478: addiu       $t9, $zero, 0x800
    ctx->r25 = ADD32(0, 0X800);
    // 0x8005A47C: beq         $v0, $t8, L_8005A488
    if (ctx->r2 == ctx->r24) {
        // 0x8005A480: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8005A488;
    }
    // 0x8005A480: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005A484: sh          $t9, -0x2F3C($at)
    MEM_H(-0X2F3C, ctx->r1) = ctx->r25;
L_8005A488:
    // 0x8005A488: jr          $ra
    // 0x8005A48C: nop

    return;
    // 0x8005A48C: nop

;}
RECOMP_FUNC void racer_enter_door(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A490: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005A494: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005A498: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8005A49C: lw          $t6, 0x108($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X108);
    // 0x8005A4A0: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8005A4A4: lw          $a3, 0x64($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X64);
    // 0x8005A4A8: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
    // 0x8005A4AC: lwc1        $f14, 0x8($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8005A4B0: lwc1        $f12, 0x0($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8005A4B4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8005A4B8: jal         0x80070990
    // 0x8005A4BC: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    arctan2_f(rdram, ctx);
        goto after_0;
    // 0x8005A4BC: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8005A4C0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8005A4C4: andi        $t8, $v0, 0xFFFF
    ctx->r24 = ctx->r2 & 0XFFFF;
    // 0x8005A4C8: lh          $t9, 0x1A0($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X1A0);
    // 0x8005A4CC: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8005A4D0: andi        $t2, $t9, 0xFFFF
    ctx->r10 = ctx->r25 & 0XFFFF;
    // 0x8005A4D4: subu        $v1, $t8, $t2
    ctx->r3 = SUB32(ctx->r24, ctx->r10);
    // 0x8005A4D8: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8005A4DC: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8005A4E0: bne         $at, $zero, L_8005A4F4
    if (ctx->r1 != 0) {
        // 0x8005A4E4: addiu       $t1, $zero, -0x1
        ctx->r9 = ADD32(0, -0X1);
            goto L_8005A4F4;
    }
    // 0x8005A4E4: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8005A4E8: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8005A4EC: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8005A4F0: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8005A4F4:
    // 0x8005A4F4: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x8005A4F8: beq         $at, $zero, L_8005A508
    if (ctx->r1 == 0) {
        // 0x8005A4FC: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_8005A508;
    }
    // 0x8005A4FC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8005A500: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8005A504: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8005A508:
    // 0x8005A508: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8005A50C: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // 0x8005A510: addiu       $a1, $a1, -0x254C
    ctx->r5 = ADD32(ctx->r5, -0X254C);
    // 0x8005A514: sra         $t3, $v1, 5
    ctx->r11 = S32(SIGNED(ctx->r3) >> 5);
    // 0x8005A518: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x8005A51C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005A520: sw          $zero, -0x2554($at)
    MEM_W(-0X2554, ctx->r1) = 0;
    // 0x8005A524: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005A528: sw          $zero, -0x2550($at)
    MEM_W(-0X2550, ctx->r1) = 0;
    // 0x8005A52C: addiu       $a0, $a0, -0x2558
    ctx->r4 = ADD32(ctx->r4, -0X2558);
    // 0x8005A530: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8005A534: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005A538: sw          $zero, -0x2548($at)
    MEM_W(-0X2548, ctx->r1) = 0;
    // 0x8005A53C: lwc1        $f4, 0x2C($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X2C);
    // 0x8005A540: lui         $at, 0xC010
    ctx->r1 = S32(0XC010 << 16);
    // 0x8005A544: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8005A548: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8005A54C: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x8005A550: c.lt.d      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.d < ctx->f0.d;
    // 0x8005A554: lui         $at, 0xC014
    ctx->r1 = S32(0XC014 << 16);
    // 0x8005A558: bc1f        L_8005A574
    if (!c1cs) {
        // 0x8005A55C: nop
    
            goto L_8005A574;
    }
    // 0x8005A55C: nop

    // 0x8005A560: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005A564: nop

    // 0x8005A568: ori         $t5, $t4, 0x8000
    ctx->r13 = ctx->r12 | 0X8000;
    // 0x8005A56C: b           L_8005A5A0
    // 0x8005A570: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
        goto L_8005A5A0;
    // 0x8005A570: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
L_8005A574:
    // 0x8005A574: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8005A578: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8005A57C: nop

    // 0x8005A580: c.lt.d      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.d < ctx->f8.d;
    // 0x8005A584: nop

    // 0x8005A588: bc1f        L_8005A5A4
    if (!c1cs) {
        // 0x8005A58C: lw          $t9, 0x24($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X24);
            goto L_8005A5A4;
    }
    // 0x8005A58C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8005A590: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005A594: nop

    // 0x8005A598: ori         $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 | 0X4000;
    // 0x8005A59C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
L_8005A5A0:
    // 0x8005A5A0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
L_8005A5A4:
    // 0x8005A5A4: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8005A5A8: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8005A5AC: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x8005A5B0: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8005A5B4: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x8005A5B8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8005A5BC: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8005A5C0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8005A5C4: addiu       $t0, $t0, -0x2578
    ctx->r8 = ADD32(ctx->r8, -0X2578);
    // 0x8005A5C8: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8005A5CC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8005A5D0: mul.d       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f2.d);
    // 0x8005A5D4: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8005A5D8: addiu       $t4, $zero, -0x4B
    ctx->r12 = ADD32(0, -0X4B);
    // 0x8005A5DC: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8005A5E0: add.d       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f18.d + ctx->f10.d;
    // 0x8005A5E4: cvt.s.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f4.fl = CVT_S_D(ctx->f16.d);
    // 0x8005A5E8: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x8005A5EC: lwc1        $f18, 0x8($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8005A5F0: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8005A5F4: mul.s       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8005A5F8: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8005A5FC: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8005A600: mul.d       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f2.d);
    // 0x8005A604: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8005A608: add.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f8.d + ctx->f4.d;
    // 0x8005A60C: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
    // 0x8005A610: swc1        $f18, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f18.u32l;
    // 0x8005A614: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8005A618: nop

    // 0x8005A61C: slti        $at, $v1, 0x4C
    ctx->r1 = SIGNED(ctx->r3) < 0X4C ? 1 : 0;
    // 0x8005A620: bne         $at, $zero, L_8005A640
    if (ctx->r1 != 0) {
        // 0x8005A624: slti        $at, $v1, -0x4B
        ctx->r1 = SIGNED(ctx->r3) < -0X4B ? 1 : 0;
            goto L_8005A640;
    }
    // 0x8005A624: slti        $at, $v1, -0x4B
    ctx->r1 = SIGNED(ctx->r3) < -0X4B ? 1 : 0;
    // 0x8005A628: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005A62C: addiu       $v1, $zero, 0x4B
    ctx->r3 = ADD32(0, 0X4B);
    // 0x8005A630: ori         $t3, $t2, 0xC000
    ctx->r11 = ctx->r10 | 0XC000;
    // 0x8005A634: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8005A638: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x8005A63C: slti        $at, $v1, -0x4B
    ctx->r1 = SIGNED(ctx->r3) < -0X4B ? 1 : 0;
L_8005A640:
    // 0x8005A640: beq         $at, $zero, L_8005A658
    if (ctx->r1 == 0) {
        // 0x8005A644: nop
    
            goto L_8005A658;
    }
    // 0x8005A644: nop

    // 0x8005A648: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005A64C: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x8005A650: ori         $t6, $t5, 0xC000
    ctx->r14 = ctx->r13 | 0XC000;
    // 0x8005A654: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
L_8005A658:
    // 0x8005A658: lb          $v0, 0x200($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X200);
    // 0x8005A65C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8005A660: slti        $at, $v0, -0x1
    ctx->r1 = SIGNED(ctx->r2) < -0X1 ? 1 : 0;
    // 0x8005A664: beq         $at, $zero, L_8005A68C
    if (ctx->r1 == 0) {
        // 0x8005A668: addu        $t9, $v0, $t7
        ctx->r25 = ADD32(ctx->r2, ctx->r15);
            goto L_8005A68C;
    }
    // 0x8005A668: addu        $t9, $v0, $t7
    ctx->r25 = ADD32(ctx->r2, ctx->r15);
    // 0x8005A66C: sb          $t9, 0x200($a2)
    MEM_B(0X200, ctx->r6) = ctx->r25;
    // 0x8005A670: lb          $v0, 0x200($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X200);
    // 0x8005A674: nop

    // 0x8005A678: bltz        $v0, L_8005A690
    if (SIGNED(ctx->r2) < 0) {
        // 0x8005A67C: slti        $at, $v0, -0x1
        ctx->r1 = SIGNED(ctx->r2) < -0X1 ? 1 : 0;
            goto L_8005A690;
    }
    // 0x8005A67C: slti        $at, $v0, -0x1
    ctx->r1 = SIGNED(ctx->r2) < -0X1 ? 1 : 0;
    // 0x8005A680: sb          $t1, 0x200($a2)
    MEM_B(0X200, ctx->r6) = ctx->r9;
    // 0x8005A684: lb          $v0, 0x200($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X200);
    // 0x8005A688: nop

L_8005A68C:
    // 0x8005A68C: slti        $at, $v0, -0x1
    ctx->r1 = SIGNED(ctx->r2) < -0X1 ? 1 : 0;
L_8005A690:
    // 0x8005A690: beq         $at, $zero, L_8005A6B4
    if (ctx->r1 == 0) {
        // 0x8005A694: nop
    
            goto L_8005A6B4;
    }
    // 0x8005A694: nop

    // 0x8005A698: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8005A69C: nop

    // 0x8005A6A0: slti        $at, $v1, 0xA
    ctx->r1 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x8005A6A4: beq         $at, $zero, L_8005A6B4
    if (ctx->r1 == 0) {
        // 0x8005A6A8: slti        $at, $v1, -0x9
        ctx->r1 = SIGNED(ctx->r3) < -0X9 ? 1 : 0;
            goto L_8005A6B4;
    }
    // 0x8005A6A8: slti        $at, $v1, -0x9
    ctx->r1 = SIGNED(ctx->r3) < -0X9 ? 1 : 0;
    // 0x8005A6AC: beq         $at, $zero, L_8005A6BC
    if (ctx->r1 == 0) {
        // 0x8005A6B0: nop
    
            goto L_8005A6BC;
    }
    // 0x8005A6B0: nop

L_8005A6B4:
    // 0x8005A6B4: bne         $t1, $v0, L_8005A6F8
    if (ctx->r9 != ctx->r2) {
        // 0x8005A6B8: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8005A6F8;
    }
    // 0x8005A6B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8005A6BC:
    // 0x8005A6BC: jal         0x80066750
    // 0x8005A6C0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    check_if_showing_cutscene_camera(rdram, ctx);
        goto after_1;
    // 0x8005A6C0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_1:
    // 0x8005A6C4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8005A6C8: bne         $v0, $zero, L_8005A6E4
    if (ctx->r2 != 0) {
        // 0x8005A6CC: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8005A6E4;
    }
    // 0x8005A6CC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005A6D0: addiu       $a0, $a0, -0x2CBC
    ctx->r4 = ADD32(ctx->r4, -0X2CBC);
    // 0x8005A6D4: jal         0x800C06F8
    // 0x8005A6D8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    transition_begin(rdram, ctx);
        goto after_2;
    // 0x8005A6D8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_2:
    // 0x8005A6DC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8005A6E0: nop

L_8005A6E4:
    // 0x8005A6E4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8005A6E8: addiu       $t2, $zero, 0x3C
    ctx->r10 = ADD32(0, 0X3C);
    // 0x8005A6EC: subu        $t3, $t2, $t8
    ctx->r11 = SUB32(ctx->r10, ctx->r24);
    // 0x8005A6F0: sb          $t3, 0x200($a2)
    MEM_B(0X200, ctx->r6) = ctx->r11;
    // 0x8005A6F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8005A6F8:
    // 0x8005A6F8: jal         0x8006F5C8
    // 0x8005A6FC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    set_pause_lockout_timer(rdram, ctx);
        goto after_3;
    // 0x8005A6FC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_3:
    // 0x8005A700: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8005A704: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8005A708: lb          $v0, 0x200($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X200);
    // 0x8005A70C: nop

    // 0x8005A710: blez        $v0, L_8005A74C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8005A714: subu        $t5, $v0, $t4
        ctx->r13 = SUB32(ctx->r2, ctx->r12);
            goto L_8005A74C;
    }
    // 0x8005A714: subu        $t5, $v0, $t4
    ctx->r13 = SUB32(ctx->r2, ctx->r12);
    // 0x8005A718: sb          $t5, 0x200($a2)
    MEM_B(0X200, ctx->r6) = ctx->r13;
    // 0x8005A71C: lb          $t6, 0x200($a2)
    ctx->r14 = MEM_B(ctx->r6, 0X200);
    // 0x8005A720: nop

    // 0x8005A724: bgtz        $t6, L_8005A750
    if (SIGNED(ctx->r14) > 0) {
        // 0x8005A728: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005A750;
    }
    // 0x8005A728: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005A72C: lw          $t7, 0x108($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X108);
    // 0x8005A730: nop

    // 0x8005A734: lw          $a0, 0x3C($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X3C);
    // 0x8005A738: jal         0x8006DBA8
    // 0x8005A73C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_8006D968(rdram, ctx);
        goto after_4;
    // 0x8005A73C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_4:
    // 0x8005A740: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8005A744: nop

    // 0x8005A748: sb          $zero, 0x200($a2)
    MEM_B(0X200, ctx->r6) = 0;
L_8005A74C:
    // 0x8005A74C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005A750:
    // 0x8005A750: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005A754: jr          $ra
    // 0x8005A758: nop

    return;
    // 0x8005A758: nop

;}
RECOMP_FUNC void update_AI_racer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A75C: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x8005A760: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8005A764: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8005A768: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8005A76C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005A770: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8005A774: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x8005A778: sw          $a2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r6;
    // 0x8005A77C: sw          $a3, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r7;
    // 0x8005A780: jal         0x8006DC4C
    // 0x8005A784: sw          $t6, -0x2524($at)
    MEM_W(-0X2524, ctx->r1) = ctx->r14;
    get_game_mode(rdram, ctx);
        goto after_0;
    // 0x8005A784: sw          $t6, -0x2524($at)
    MEM_W(-0X2524, ctx->r1) = ctx->r14;
    after_0:
    // 0x8005A788: jal         0x8006BFF0
    // 0x8005A78C: sw          $v0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r2;
    level_header(rdram, ctx);
        goto after_1;
    // 0x8005A78C: sw          $v0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r2;
    after_1:
    // 0x8005A790: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x8005A794: lb          $v1, 0x1F6($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X1F6);
    // 0x8005A798: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8005A79C: blez        $v1, L_8005A7B8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8005A7A0: nop
    
            goto L_8005A7B8;
    }
    // 0x8005A7A0: nop

    // 0x8005A7A4: lw          $t7, 0xA8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA8);
    // 0x8005A7A8: nop

    // 0x8005A7AC: subu        $t8, $v1, $t7
    ctx->r24 = SUB32(ctx->r3, ctx->r15);
    // 0x8005A7B0: b           L_8005A7BC
    // 0x8005A7B4: sb          $t8, 0x1F6($s0)
    MEM_B(0X1F6, ctx->r16) = ctx->r24;
        goto L_8005A7BC;
    // 0x8005A7B4: sb          $t8, 0x1F6($s0)
    MEM_B(0X1F6, ctx->r16) = ctx->r24;
L_8005A7B8:
    // 0x8005A7B8: sb          $zero, 0x1F6($s0)
    MEM_B(0X1F6, ctx->r16) = 0;
L_8005A7BC:
    // 0x8005A7BC: lw          $t9, -0x2540($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2540);
    // 0x8005A7C0: nop

    // 0x8005A7C4: beq         $t9, $zero, L_8005A7DC
    if (ctx->r25 == 0) {
        // 0x8005A7C8: addiu       $a0, $zero, -0x3C
        ctx->r4 = ADD32(0, -0X3C);
            goto L_8005A7DC;
    }
    // 0x8005A7C8: addiu       $a0, $zero, -0x3C
    ctx->r4 = ADD32(0, -0X3C);
    // 0x8005A7CC: jal         0x8006FB8C
    // 0x8005A7D0: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    rand_range(rdram, ctx);
        goto after_2;
    // 0x8005A7D0: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_2:
    // 0x8005A7D4: addiu       $t5, $v0, 0x78
    ctx->r13 = ADD32(ctx->r2, 0X78);
    // 0x8005A7D8: sh          $t5, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = ctx->r13;
L_8005A7DC:
    // 0x8005A7DC: lh          $v0, 0x18C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X18C);
    // 0x8005A7E0: nop

    // 0x8005A7E4: blez        $v0, L_8005A800
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8005A7E8: nop
    
            goto L_8005A800;
    }
    // 0x8005A7E8: nop

    // 0x8005A7EC: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
    // 0x8005A7F0: nop

    // 0x8005A7F4: subu        $t7, $v0, $t6
    ctx->r15 = SUB32(ctx->r2, ctx->r14);
    // 0x8005A7F8: b           L_8005A804
    // 0x8005A7FC: sh          $t7, 0x18C($s0)
    MEM_H(0X18C, ctx->r16) = ctx->r15;
        goto L_8005A804;
    // 0x8005A7FC: sh          $t7, 0x18C($s0)
    MEM_H(0X18C, ctx->r16) = ctx->r15;
L_8005A800:
    // 0x8005A800: sh          $zero, 0x18C($s0)
    MEM_H(0X18C, ctx->r16) = 0;
L_8005A804:
    // 0x8005A804: jal         0x8001E2D0
    // 0x8005A808: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    get_misc_asset(rdram, ctx);
        goto after_3;
    // 0x8005A808: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_3:
    // 0x8005A80C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005A810: addiu       $v1, $v1, -0x251C
    ctx->r3 = ADD32(ctx->r3, -0X251C);
    // 0x8005A814: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8005A818: lb          $t9, 0x3($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X3);
    // 0x8005A81C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005A820: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x8005A824: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x8005A828: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8005A82C: lwc1        $f9, 0x6ED0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6ED0);
    // 0x8005A830: lwc1        $f8, 0x6ED4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6ED4);
    // 0x8005A834: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005A838: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8005A83C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8005A840: addiu       $t4, $t4, -0x2514
    ctx->r12 = ADD32(ctx->r12, -0X2514);
    // 0x8005A844: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8005A848: swc1        $f18, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f18.u32l;
    // 0x8005A84C: lh          $t7, 0x204($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X204);
    // 0x8005A850: nop

    // 0x8005A854: blez        $t7, L_8005A868
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8005A858: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8005A868;
    }
    // 0x8005A858: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005A85C: lwc1        $f4, 0x6ED8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6ED8);
    // 0x8005A860: nop

    // 0x8005A864: swc1        $f4, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f4.u32l;
L_8005A868:
    // 0x8005A868: jal         0x8001E2D0
    // 0x8005A86C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    get_misc_asset(rdram, ctx);
        goto after_4;
    // 0x8005A86C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_4:
    // 0x8005A870: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005A874: addiu       $v1, $v1, -0x251C
    ctx->r3 = ADD32(ctx->r3, -0X251C);
    // 0x8005A878: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8005A87C: lb          $t8, 0x3($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X3);
    // 0x8005A880: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005A884: sll         $t5, $t8, 2
    ctx->r13 = S32(ctx->r24 << 2);
    // 0x8005A888: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x8005A88C: lwc1        $f6, 0x0($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8005A890: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x8005A894: jal         0x8001E2D0
    // 0x8005A898: swc1        $f6, -0x2510($at)
    MEM_W(-0X2510, ctx->r1) = ctx->f6.u32l;
    get_misc_asset(rdram, ctx);
        goto after_5;
    // 0x8005A898: swc1        $f6, -0x2510($at)
    MEM_W(-0X2510, ctx->r1) = ctx->f6.u32l;
    after_5:
    // 0x8005A89C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8005A8A0: addiu       $a1, $a1, -0x251C
    ctx->r5 = ADD32(ctx->r5, -0X251C);
    // 0x8005A8A4: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8005A8A8: lb          $t8, 0x3($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X3);
    // 0x8005A8AC: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x8005A8B0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8005A8B4: addu        $t5, $v0, $t9
    ctx->r13 = ADD32(ctx->r2, ctx->r25);
    // 0x8005A8B8: lwc1        $f8, 0x0($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8005A8BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005A8C0: swc1        $f8, -0x250C($at)
    MEM_W(-0X250C, ctx->r1) = ctx->f8.u32l;
    // 0x8005A8C4: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8005A8C8: nop

    // 0x8005A8CC: swc1        $f10, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f10.u32l;
    // 0x8005A8D0: lwc1        $f18, 0x10($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8005A8D4: nop

    // 0x8005A8D8: swc1        $f18, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f18.u32l;
    // 0x8005A8DC: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8005A8E0: nop

    // 0x8005A8E4: swc1        $f4, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f4.u32l;
    // 0x8005A8E8: lh          $v1, 0x1B2($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X1B2);
    // 0x8005A8EC: nop

    // 0x8005A8F0: blez        $v1, L_8005A91C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8005A8F4: nop
    
            goto L_8005A91C;
    }
    // 0x8005A8F4: nop

    // 0x8005A8F8: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
    // 0x8005A8FC: nop

    // 0x8005A900: subu        $t8, $v1, $t6
    ctx->r24 = SUB32(ctx->r3, ctx->r14);
    // 0x8005A904: sh          $t8, 0x1B2($s0)
    MEM_H(0X1B2, ctx->r16) = ctx->r24;
    // 0x8005A908: lh          $t7, 0x1B2($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X1B2);
    // 0x8005A90C: nop

    // 0x8005A910: bgez        $t7, L_8005A91C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8005A914: nop
    
            goto L_8005A91C;
    }
    // 0x8005A914: nop

    // 0x8005A918: sh          $zero, 0x1B2($s0)
    MEM_H(0X1B2, ctx->r16) = 0;
L_8005A91C:
    // 0x8005A91C: lb          $t9, 0x1E7($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1E7);
    // 0x8005A920: nop

    // 0x8005A924: addiu       $t5, $t9, 0x1
    ctx->r13 = ADD32(ctx->r25, 0X1);
    // 0x8005A928: jal         0x80023450
    // 0x8005A92C: sb          $t5, 0x1E7($s0)
    MEM_B(0X1E7, ctx->r16) = ctx->r13;
    is_taj_challenge(rdram, ctx);
        goto after_6;
    // 0x8005A92C: sb          $t5, 0x1E7($s0)
    MEM_B(0X1E7, ctx->r16) = ctx->r13;
    after_6:
    // 0x8005A930: bne         $v0, $zero, L_8005A99C
    if (ctx->r2 != 0) {
        // 0x8005A934: addiu       $t6, $zero, 0x1E
        ctx->r14 = ADD32(0, 0X1E);
            goto L_8005A99C;
    }
    // 0x8005A934: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x8005A938: jal         0x8002359C
    // 0x8005A93C: nop

    func_80023568(rdram, ctx);
        goto after_7;
    // 0x8005A93C: nop

    after_7:
    // 0x8005A940: bne         $v0, $zero, L_8005A99C
    if (ctx->r2 != 0) {
        // 0x8005A944: addiu       $t6, $zero, 0x1E
        ctx->r14 = ADD32(0, 0X1E);
            goto L_8005A99C;
    }
    // 0x8005A944: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x8005A948: lb          $t6, 0x1D6($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D6);
    // 0x8005A94C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8005A950: beq         $t6, $at, L_8005A998
    if (ctx->r14 == ctx->r1) {
        // 0x8005A954: lui         $at, 0x42F0
        ctx->r1 = S32(0X42F0 << 16);
            goto L_8005A998;
    }
    // 0x8005A954: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8005A958: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8005A95C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005A960: lwc1        $f8, -0x253C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X253C);
    // 0x8005A964: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8005A968: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8005A96C: nop

    // 0x8005A970: bc1t        L_8005A99C
    if (c1cs) {
        // 0x8005A974: addiu       $t6, $zero, 0x1E
        ctx->r14 = ADD32(0, 0X1E);
            goto L_8005A99C;
    }
    // 0x8005A974: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x8005A978: lw          $t8, -0x2540($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2540);
    // 0x8005A97C: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x8005A980: bne         $t8, $zero, L_8005A99C
    if (ctx->r24 != 0) {
        // 0x8005A984: addiu       $t6, $zero, 0x1E
        ctx->r14 = ADD32(0, 0X1E);
            goto L_8005A99C;
    }
    // 0x8005A984: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x8005A988: lb          $t9, 0x4C($t7)
    ctx->r25 = MEM_B(ctx->r15, 0X4C);
    // 0x8005A98C: nop

    // 0x8005A990: andi        $t5, $t9, 0x40
    ctx->r13 = ctx->r25 & 0X40;
    // 0x8005A994: beq         $t5, $zero, L_8005A9A0
    if (ctx->r13 == 0) {
        // 0x8005A998: addiu       $t6, $zero, 0x1E
        ctx->r14 = ADD32(0, 0X1E);
            goto L_8005A9A0;
    }
L_8005A998:
    // 0x8005A998: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
L_8005A99C:
    // 0x8005A99C: sb          $t6, 0x201($s0)
    MEM_B(0X201, ctx->r16) = ctx->r14;
L_8005A9A0:
    // 0x8005A9A0: lb          $t8, 0x201($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X201);
    // 0x8005A9A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005A9A8: lwc1        $f2, 0x6EDC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6EDC);
    // 0x8005A9AC: bne         $t8, $zero, L_8005ABA0
    if (ctx->r24 != 0) {
        // 0x8005A9B0: addiu       $a0, $sp, 0x90
        ctx->r4 = ADD32(ctx->r29, 0X90);
            goto L_8005ABA0;
    }
    // 0x8005A9B0: addiu       $a0, $sp, 0x90
    ctx->r4 = ADD32(ctx->r29, 0X90);
    // 0x8005A9B4: jal         0x8001BAA8
    // 0x8005A9B8: swc1        $f2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f2.u32l;
    get_racer_objects(rdram, ctx);
        goto after_8;
    // 0x8005A9B8: swc1        $f2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f2.u32l;
    after_8:
    // 0x8005A9BC: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
    // 0x8005A9C0: lwc1        $f2, 0x78($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8005A9C4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8005A9C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8005A9CC: blez        $t7, L_8005AB24
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8005A9D0: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_8005AB24;
    }
    // 0x8005A9D0: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8005A9D4: andi        $v1, $t7, 0x3
    ctx->r3 = ctx->r15 & 0X3;
    // 0x8005A9D8: beq         $v1, $zero, L_8005AA3C
    if (ctx->r3 == 0) {
        // 0x8005A9DC: or          $t1, $v1, $zero
        ctx->r9 = ctx->r3 | 0;
            goto L_8005AA3C;
    }
    // 0x8005A9DC: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x8005A9E0: sll         $t9, $zero, 2
    ctx->r25 = S32(0 << 2);
    // 0x8005A9E4: addu        $a2, $v0, $t9
    ctx->r6 = ADD32(ctx->r2, ctx->r25);
    // 0x8005A9E8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8005A9EC:
    // 0x8005A9EC: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x8005A9F0: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x8005A9F4: lw          $a1, 0x64($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X64);
    // 0x8005A9F8: nop

    // 0x8005A9FC: lh          $t5, 0x0($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X0);
    // 0x8005AA00: nop

    // 0x8005AA04: bne         $t5, $zero, L_8005AA10
    if (ctx->r13 != 0) {
        // 0x8005AA08: nop
    
            goto L_8005AA10;
    }
    // 0x8005AA08: nop

    // 0x8005AA0C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
L_8005AA10:
    // 0x8005AA10: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x8005AA14: nop

    // 0x8005AA18: bne         $t3, $t6, L_8005AA24
    if (ctx->r11 != ctx->r14) {
        // 0x8005AA1C: nop
    
            goto L_8005AA24;
    }
    // 0x8005AA1C: nop

    // 0x8005AA20: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
L_8005AA24:
    // 0x8005AA24: bne         $t1, $t2, L_8005A9EC
    if (ctx->r9 != ctx->r10) {
        // 0x8005AA28: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_8005A9EC;
    }
    // 0x8005AA28: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8005AA2C: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
    // 0x8005AA30: nop

    // 0x8005AA34: beq         $t2, $t8, L_8005AB24
    if (ctx->r10 == ctx->r24) {
        // 0x8005AA38: nop
    
            goto L_8005AB24;
    }
    // 0x8005AA38: nop

L_8005AA3C:
    // 0x8005AA3C: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
    // 0x8005AA40: sll         $t5, $t2, 2
    ctx->r13 = S32(ctx->r10 << 2);
    // 0x8005AA44: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8005AA48: addu        $t1, $t9, $v0
    ctx->r9 = ADD32(ctx->r25, ctx->r2);
    // 0x8005AA4C: addu        $a2, $v0, $t5
    ctx->r6 = ADD32(ctx->r2, ctx->r13);
    // 0x8005AA50: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8005AA54:
    // 0x8005AA54: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x8005AA58: nop

    // 0x8005AA5C: lw          $a1, 0x64($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X64);
    // 0x8005AA60: nop

    // 0x8005AA64: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x8005AA68: nop

    // 0x8005AA6C: bne         $t6, $zero, L_8005AA78
    if (ctx->r14 != 0) {
        // 0x8005AA70: nop
    
            goto L_8005AA78;
    }
    // 0x8005AA70: nop

    // 0x8005AA74: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
L_8005AA78:
    // 0x8005AA78: lh          $t8, 0x0($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X0);
    // 0x8005AA7C: nop

    // 0x8005AA80: bne         $t3, $t8, L_8005AA8C
    if (ctx->r11 != ctx->r24) {
        // 0x8005AA84: nop
    
            goto L_8005AA8C;
    }
    // 0x8005AA84: nop

    // 0x8005AA88: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
L_8005AA8C:
    // 0x8005AA8C: lw          $a1, 0x4($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X4);
    // 0x8005AA90: nop

    // 0x8005AA94: lw          $v1, 0x64($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X64);
    // 0x8005AA98: nop

    // 0x8005AA9C: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x8005AAA0: nop

    // 0x8005AAA4: bne         $a0, $zero, L_8005AAB0
    if (ctx->r4 != 0) {
        // 0x8005AAA8: nop
    
            goto L_8005AAB0;
    }
    // 0x8005AAA8: nop

    // 0x8005AAAC: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
L_8005AAB0:
    // 0x8005AAB0: bne         $t3, $a0, L_8005AABC
    if (ctx->r11 != ctx->r4) {
        // 0x8005AAB4: nop
    
            goto L_8005AABC;
    }
    // 0x8005AAB4: nop

    // 0x8005AAB8: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
L_8005AABC:
    // 0x8005AABC: lw          $a1, 0x8($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X8);
    // 0x8005AAC0: nop

    // 0x8005AAC4: lw          $v1, 0x64($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X64);
    // 0x8005AAC8: nop

    // 0x8005AACC: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x8005AAD0: nop

    // 0x8005AAD4: bne         $a0, $zero, L_8005AAE0
    if (ctx->r4 != 0) {
        // 0x8005AAD8: nop
    
            goto L_8005AAE0;
    }
    // 0x8005AAD8: nop

    // 0x8005AADC: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
L_8005AAE0:
    // 0x8005AAE0: bne         $t3, $a0, L_8005AAEC
    if (ctx->r11 != ctx->r4) {
        // 0x8005AAE4: nop
    
            goto L_8005AAEC;
    }
    // 0x8005AAE4: nop

    // 0x8005AAE8: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
L_8005AAEC:
    // 0x8005AAEC: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    // 0x8005AAF0: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8005AAF4: lw          $v1, 0x64($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X64);
    // 0x8005AAF8: nop

    // 0x8005AAFC: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x8005AB00: nop

    // 0x8005AB04: bne         $a0, $zero, L_8005AB10
    if (ctx->r4 != 0) {
        // 0x8005AB08: nop
    
            goto L_8005AB10;
    }
    // 0x8005AB08: nop

    // 0x8005AB0C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
L_8005AB10:
    // 0x8005AB10: bne         $t3, $a0, L_8005AB1C
    if (ctx->r11 != ctx->r4) {
        // 0x8005AB14: nop
    
            goto L_8005AB1C;
    }
    // 0x8005AB14: nop

    // 0x8005AB18: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
L_8005AB1C:
    // 0x8005AB1C: bne         $a2, $t1, L_8005AA54
    if (ctx->r6 != ctx->r9) {
        // 0x8005AB20: nop
    
            goto L_8005AA54;
    }
    // 0x8005AB20: nop

L_8005AB24:
    // 0x8005AB24: beq         $a3, $zero, L_8005AB54
    if (ctx->r7 == 0) {
        // 0x8005AB28: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8005AB54;
    }
    // 0x8005AB28: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005AB2C: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x8005AB30: lwc1        $f10, 0xC($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8005AB34: lwc1        $f18, 0xC($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8005AB38: lwc1        $f4, 0x14($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X14);
    // 0x8005AB3C: sub.s       $f2, $f10, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8005AB40: lwc1        $f6, 0x14($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8005AB44: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8005AB48: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8005AB4C: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8005AB50: add.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f10.fl;
L_8005AB54:
    // 0x8005AB54: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x8005AB58: beq         $t0, $zero, L_8005ABA0
    if (ctx->r8 == 0) {
        // 0x8005AB5C: nop
    
            goto L_8005ABA0;
    }
    // 0x8005AB5C: nop

    // 0x8005AB60: lwc1        $f5, 0x6EE0($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6EE0);
    // 0x8005AB64: lwc1        $f4, 0x6EE4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6EE4);
    // 0x8005AB68: cvt.d.s     $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f18.d = CVT_D_S(ctx->f2.fl);
    // 0x8005AB6C: c.le.d      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.d <= ctx->f18.d;
    // 0x8005AB70: nop

    // 0x8005AB74: bc1f        L_8005ABA0
    if (!c1cs) {
        // 0x8005AB78: nop
    
            goto L_8005ABA0;
    }
    // 0x8005AB78: nop

    // 0x8005AB7C: lwc1        $f6, 0xC($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0XC);
    // 0x8005AB80: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8005AB84: lwc1        $f10, 0x14($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X14);
    // 0x8005AB88: sub.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8005AB8C: lwc1        $f18, 0x14($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8005AB90: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8005AB94: sub.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8005AB98: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8005AB9C: add.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f6.fl;
L_8005ABA0:
    // 0x8005ABA0: lh          $v0, 0x204($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X204);
    // 0x8005ABA4: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x8005ABA8: blez        $v0, L_8005ABD4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8005ABAC: nop
    
            goto L_8005ABD4;
    }
    // 0x8005ABAC: nop

    // 0x8005ABB0: lw          $a2, 0xA8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA8);
    // 0x8005ABB4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005ABB8: subu        $t7, $v0, $a2
    ctx->r15 = SUB32(ctx->r2, ctx->r6);
    // 0x8005ABBC: sh          $t7, 0x204($s0)
    MEM_H(0X204, ctx->r16) = ctx->r15;
    // 0x8005ABC0: lwc1        $f10, 0x6EE8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6EE8);
    // 0x8005ABC4: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005ABC8: nop

    // 0x8005ABCC: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8005ABD0: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
L_8005ABD4:
    // 0x8005ABD4: lh          $v0, 0x206($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X206);
    // 0x8005ABD8: lw          $a2, 0xA8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA8);
    // 0x8005ABDC: blez        $v0, L_8005ABEC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8005ABE0: subu        $t9, $v0, $a2
        ctx->r25 = SUB32(ctx->r2, ctx->r6);
            goto L_8005ABEC;
    }
    // 0x8005ABE0: subu        $t9, $v0, $a2
    ctx->r25 = SUB32(ctx->r2, ctx->r6);
    // 0x8005ABE4: sh          $v0, 0x18A($s0)
    MEM_H(0X18A, ctx->r16) = ctx->r2;
    // 0x8005ABE8: sh          $t9, 0x206($s0)
    MEM_H(0X206, ctx->r16) = ctx->r25;
L_8005ABEC:
    // 0x8005ABEC: lb          $v0, 0x201($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X201);
    // 0x8005ABF0: nop

    // 0x8005ABF4: bne         $v0, $zero, L_8005AC24
    if (ctx->r2 != 0) {
        // 0x8005ABF8: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8005AC24;
    }
    // 0x8005ABF8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005ABFC: lwc1        $f7, 0x6EF0($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6EF0);
    // 0x8005AC00: lwc1        $f6, 0x6EF4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6EF4);
    // 0x8005AC04: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x8005AC08: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x8005AC0C: addiu       $t5, $zero, 0x1E
    ctx->r13 = ADD32(0, 0X1E);
    // 0x8005AC10: bc1f        L_8005AC24
    if (!c1cs) {
        // 0x8005AC14: nop
    
            goto L_8005AC24;
    }
    // 0x8005AC14: nop

    // 0x8005AC18: sb          $t5, 0x201($s0)
    MEM_B(0X201, ctx->r16) = ctx->r13;
    // 0x8005AC1C: lb          $v0, 0x201($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X201);
    // 0x8005AC20: nop

L_8005AC24:
    // 0x8005AC24: beq         $v0, $zero, L_8005B488
    if (ctx->r2 == 0) {
        // 0x8005AC28: lw          $a3, 0xAC($sp)
        ctx->r7 = MEM_W(ctx->r29, 0XAC);
            goto L_8005B488;
    }
    // 0x8005AC28: lw          $a3, 0xAC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XAC);
    // 0x8005AC2C: jal         0x800441B0
    // 0x8005AC30: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    racer_AI_pathing_inputs(rdram, ctx);
        goto after_9;
    // 0x8005AC30: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_9:
    // 0x8005AC34: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8005AC38: lw          $t6, -0x2558($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2558);
    // 0x8005AC3C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8005AC40: andi        $t8, $t6, 0x8000
    ctx->r24 = ctx->r14 & 0X8000;
    // 0x8005AC44: addiu       $t4, $t4, -0x2514
    ctx->r12 = ADD32(ctx->r12, -0X2514);
    // 0x8005AC48: bne         $t8, $zero, L_8005AC58
    if (ctx->r24 != 0) {
        // 0x8005AC4C: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_8005AC58;
    }
    // 0x8005AC4C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8005AC50: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8005AC54: sb          $t7, 0x20C($s0)
    MEM_B(0X20C, ctx->r16) = ctx->r15;
L_8005AC58:
    // 0x8005AC58: lbu         $v0, 0x1FE($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1FE);
    // 0x8005AC5C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8005AC60: bne         $v0, $at, L_8005ACA8
    if (ctx->r2 != ctx->r1) {
        // 0x8005AC64: nop
    
            goto L_8005ACA8;
    }
    // 0x8005AC64: nop

    // 0x8005AC68: lbu         $t9, 0x1FF($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1FF);
    // 0x8005AC6C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8005AC70: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8005AC74: bgez        $t9, L_8005AC88
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8005AC78: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8005AC88;
    }
    // 0x8005AC78: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8005AC7C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8005AC80: nop

    // 0x8005AC84: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_8005AC88:
    // 0x8005AC88: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x8005AC8C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8005AC90: lwc1        $f8, 0x0($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8005AC94: div.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8005AC98: mul.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8005AC9C: swc1        $f18, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f18.u32l;
    // 0x8005ACA0: lbu         $v0, 0x1FE($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1FE);
    // 0x8005ACA4: nop

L_8005ACA8:
    // 0x8005ACA8: bne         $t3, $v0, L_8005AD24
    if (ctx->r11 != ctx->r2) {
        // 0x8005ACAC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8005AD24;
    }
    // 0x8005ACAC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005ACB0: lbu         $t5, 0x1FF($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X1FF);
    // 0x8005ACB4: lwc1        $f0, 0x0($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8005ACB8: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x8005ACBC: bgez        $t5, L_8005ACD4
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8005ACC0: cvt.s.w     $f4, $f10
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8005ACD4;
    }
    // 0x8005ACC0: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8005ACC4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8005ACC8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8005ACCC: nop

    // 0x8005ACD0: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_8005ACD4:
    // 0x8005ACD4: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8005ACD8: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x8005ACDC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8005ACE0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005ACE4: div.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8005ACE8: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x8005ACEC: sub.s       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8005ACF0: swc1        $f8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f8.u32l;
    // 0x8005ACF4: lh          $t6, 0x204($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X204);
    // 0x8005ACF8: nop

    // 0x8005ACFC: blez        $t6, L_8005AD14
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8005AD00: nop
    
            goto L_8005AD14;
    }
    // 0x8005AD00: nop

    // 0x8005AD04: lwc1        $f4, 0x0($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8005AD08: nop

    // 0x8005AD0C: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8005AD10: swc1        $f6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f6.u32l;
L_8005AD14:
    // 0x8005AD14: sw          $t8, -0x2548($at)
    MEM_W(-0X2548, ctx->r1) = ctx->r24;
    // 0x8005AD18: lbu         $v0, 0x1FE($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1FE);
    // 0x8005AD1C: nop

    // 0x8005AD20: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_8005AD24:
    // 0x8005AD24: bne         $v0, $at, L_8005ADE4
    if (ctx->r2 != ctx->r1) {
        // 0x8005AD28: nop
    
            goto L_8005ADE4;
    }
    // 0x8005AD28: nop

    // 0x8005AD2C: lbu         $t7, 0x1FF($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X1FF);
    // 0x8005AD30: nop

    // 0x8005AD34: sll         $t9, $t7, 24
    ctx->r25 = S32(ctx->r15 << 24);
    // 0x8005AD38: jal         0x80070A04
    // 0x8005AD3C: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    sins_f(rdram, ctx);
        goto after_10;
    // 0x8005AD3C: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    after_10:
    // 0x8005AD40: lui         $at, 0x3FB0
    ctx->r1 = S32(0X3FB0 << 16);
    // 0x8005AD44: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x8005AD48: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8005AD4C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8005AD50: lwc1        $f2, 0x84($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8005AD54: mul.s       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8005AD58: lwc1        $f18, 0xAC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8005AD5C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8005AD60: lbu         $t6, 0x1FF($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X1FF);
    // 0x8005AD64: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x8005AD68: sll         $t8, $t6, 24
    ctx->r24 = S32(ctx->r14 << 24);
    // 0x8005AD6C: cvt.d.s     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f12.d = CVT_D_S(ctx->f18.fl);
    // 0x8005AD70: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x8005AD74: mul.d       $f8, $f18, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f14.d);
    // 0x8005AD78: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x8005AD7C: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8005AD80: mul.d       $f4, $f8, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f12.d);
    // 0x8005AD84: add.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d + ctx->f4.d;
    // 0x8005AD88: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
    // 0x8005AD8C: swc1        $f18, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->f18.u32l;
    // 0x8005AD90: swc1        $f12, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f12.u32l;
    // 0x8005AD94: jal         0x80070A38
    // 0x8005AD98: swc1        $f13, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(13 - 1) * 2];
    coss_f(rdram, ctx);
        goto after_11;
    // 0x8005AD98: swc1        $f13, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(13 - 1) * 2];
    after_11:
    // 0x8005AD9C: lui         $at, 0x3FB0
    ctx->r1 = S32(0X3FB0 << 16);
    // 0x8005ADA0: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x8005ADA4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8005ADA8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8005ADAC: lwc1        $f2, 0x88($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X88);
    // 0x8005ADB0: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8005ADB4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8005ADB8: lwc1        $f13, 0x40($sp)
    ctx->f_odd[(13 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x8005ADBC: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8005ADC0: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x8005ADC4: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x8005ADC8: mul.d       $f10, $f18, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = MUL_D(ctx->f18.d, ctx->f14.d);
    // 0x8005ADCC: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x8005ADD0: mul.d       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f12.d);
    // 0x8005ADD4: add.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f8.d + ctx->f4.d;
    // 0x8005ADD8: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
    // 0x8005ADDC: b           L_8005AE34
    // 0x8005ADE0: swc1        $f18, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->f18.u32l;
        goto L_8005AE34;
    // 0x8005ADE0: swc1        $f18, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->f18.u32l;
L_8005ADE4:
    // 0x8005ADE4: lwc1        $f10, 0x84($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8005ADE8: lui         $at, 0x3FB0
    ctx->r1 = S32(0X3FB0 << 16);
    // 0x8005ADEC: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x8005ADF0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8005ADF4: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x8005ADF8: mul.d       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f14.d); 
    ctx->f4.d = MUL_D(ctx->f0.d, ctx->f14.d);
    // 0x8005ADFC: lwc1        $f8, 0xAC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8005AE00: nop

    // 0x8005AE04: cvt.d.s     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f12.d = CVT_D_S(ctx->f8.fl);
    // 0x8005AE08: lwc1        $f8, 0x88($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X88);
    // 0x8005AE0C: mul.d       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f12.d);
    // 0x8005AE10: cvt.d.s     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f2.d = CVT_D_S(ctx->f8.fl);
    // 0x8005AE14: mul.d       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f14.d);
    // 0x8005AE18: sub.d       $f18, $f0, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = ctx->f0.d - ctx->f6.d;
    // 0x8005AE1C: mul.d       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f12.d);
    // 0x8005AE20: cvt.s.d     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f10.fl = CVT_S_D(ctx->f18.d);
    // 0x8005AE24: swc1        $f10, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->f10.u32l;
    // 0x8005AE28: sub.d       $f18, $f2, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = ctx->f2.d - ctx->f6.d;
    // 0x8005AE2C: cvt.s.d     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f10.fl = CVT_S_D(ctx->f18.d);
    // 0x8005AE30: swc1        $f10, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->f10.u32l;
L_8005AE34:
    // 0x8005AE34: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005AE38: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8005AE3C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005AE40: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    // 0x8005AE44: jal         0x8001E2D0
    // 0x8005AE48: swc1        $f8, -0x2510($at)
    MEM_W(-0X2510, ctx->r1) = ctx->f8.u32l;
    get_misc_asset(rdram, ctx);
        goto after_12;
    // 0x8005AE48: swc1        $f8, -0x2510($at)
    MEM_W(-0X2510, ctx->r1) = ctx->f8.u32l;
    after_12:
    // 0x8005AE4C: lw          $t9, 0xA0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA0);
    // 0x8005AE50: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005AE54: sw          $v0, -0x251C($at)
    MEM_W(-0X251C, ctx->r1) = ctx->r2;
    // 0x8005AE58: lw          $t5, 0x40($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X40);
    // 0x8005AE5C: nop

    // 0x8005AE60: lbu         $a0, 0x5D($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X5D);
    // 0x8005AE64: jal         0x8001E2D0
    // 0x8005AE68: nop

    get_misc_asset(rdram, ctx);
        goto after_13;
    // 0x8005AE68: nop

    after_13:
    // 0x8005AE6C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005AE70: lw          $t6, 0xA0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA0);
    // 0x8005AE74: sw          $v0, -0x2518($at)
    MEM_W(-0X2518, ctx->r1) = ctx->r2;
    // 0x8005AE78: lwc1        $f4, 0x20($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X20);
    // 0x8005AE7C: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8005AE80: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8005AE84: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005AE88: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005AE8C: c.lt.d      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.d < ctx->f18.d;
    // 0x8005AE90: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8005AE94: bc1f        L_8005AED4
    if (!c1cs) {
        // 0x8005AE98: nop
    
            goto L_8005AED4;
    }
    // 0x8005AE98: nop

    // 0x8005AE9C: lb          $t8, 0x1E2($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1E2);
    // 0x8005AEA0: nop

    // 0x8005AEA4: slti        $at, $t8, 0x3
    ctx->r1 = SIGNED(ctx->r24) < 0X3 ? 1 : 0;
    // 0x8005AEA8: beq         $at, $zero, L_8005AED0
    if (ctx->r1 == 0) {
        // 0x8005AEAC: nop
    
            goto L_8005AED0;
    }
    // 0x8005AEAC: nop

    // 0x8005AEB0: lwc1        $f8, 0xC0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x8005AEB4: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x8005AEB8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005AEBC: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8005AEC0: c.eq.d      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.d == ctx->f4.d;
    // 0x8005AEC4: nop

    // 0x8005AEC8: bc1t        L_8005AED4
    if (c1cs) {
        // 0x8005AECC: nop
    
            goto L_8005AED4;
    }
    // 0x8005AECC: nop

L_8005AED0:
    // 0x8005AED0: sb          $zero, 0x1F1($s0)
    MEM_B(0X1F1, ctx->r16) = 0;
L_8005AED4:
    // 0x8005AED4: lb          $t7, 0x175($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X175);
    // 0x8005AED8: nop

    // 0x8005AEDC: beq         $t7, $zero, L_8005AEF8
    if (ctx->r15 == 0) {
        // 0x8005AEE0: nop
    
            goto L_8005AEF8;
    }
    // 0x8005AEE0: nop

    // 0x8005AEE4: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x8005AEE8: lw          $a2, 0xA8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA8);
    // 0x8005AEEC: jal         0x80056E6C
    // 0x8005AEF0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    racer_activate_magnet(rdram, ctx);
        goto after_14;
    // 0x8005AEF0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_14:
    // 0x8005AEF4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8005AEF8:
    // 0x8005AEF8: lb          $t9, 0x1D6($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1D6);
    // 0x8005AEFC: nop

    // 0x8005AF00: beq         $t3, $t9, L_8005AF24
    if (ctx->r11 == ctx->r25) {
        // 0x8005AF04: lw          $t5, 0xA0($sp)
        ctx->r13 = MEM_W(ctx->r29, 0XA0);
            goto L_8005AF24;
    }
    // 0x8005AF04: lw          $t5, 0xA0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA0);
    // 0x8005AF08: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8005AF0C: sb          $zero, 0x1E5($s0)
    MEM_B(0X1E5, ctx->r16) = 0;
    // 0x8005AF10: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005AF14: swc1        $f6, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f6.u32l;
    // 0x8005AF18: b           L_8005AF44
    // 0x8005AF1C: sb          $zero, -0x24D2($at)
    MEM_B(-0X24D2, ctx->r1) = 0;
        goto L_8005AF44;
    // 0x8005AF1C: sb          $zero, -0x24D2($at)
    MEM_B(-0X24D2, ctx->r1) = 0;
    // 0x8005AF20: lw          $t5, 0xA0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA0);
L_8005AF24:
    // 0x8005AF24: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8005AF28: lh          $a0, 0x2E($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X2E);
    // 0x8005AF2C: lw          $a1, 0xC($t5)
    ctx->r5 = MEM_W(ctx->r13, 0XC);
    // 0x8005AF30: lw          $a2, 0x14($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X14);
    // 0x8005AF34: jal         0x8002B134
    // 0x8005AF38: addiu       $a3, $a3, -0x24D0
    ctx->r7 = ADD32(ctx->r7, -0X24D0);
    func_8002B0F4(rdram, ctx);
        goto after_15;
    // 0x8005AF38: addiu       $a3, $a3, -0x24D0
    ctx->r7 = ADD32(ctx->r7, -0X24D0);
    after_15:
    // 0x8005AF3C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005AF40: sb          $v0, -0x24D2($at)
    MEM_B(-0X24D2, ctx->r1) = ctx->r2;
L_8005AF44:
    // 0x8005AF44: jal         0x8002AD08
    // 0x8005AF48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_collision_mode(rdram, ctx);
        goto after_16;
    // 0x8005AF48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_16:
    // 0x8005AF4C: lw          $t6, 0x148($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X148);
    // 0x8005AF50: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8005AF54: bne         $t6, $zero, L_8005AF7C
    if (ctx->r14 != 0) {
        // 0x8005AF58: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_8005AF7C;
    }
    // 0x8005AF58: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8005AF5C: addiu       $t0, $t0, -0x2540
    ctx->r8 = ADD32(ctx->r8, -0X2540);
    // 0x8005AF60: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x8005AF64: nop

    // 0x8005AF68: bne         $t8, $zero, L_8005AF7C
    if (ctx->r24 != 0) {
        // 0x8005AF6C: nop
    
            goto L_8005AF7C;
    }
    // 0x8005AF6C: nop

    // 0x8005AF70: lh          $t7, 0x204($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X204);
    // 0x8005AF74: nop

    // 0x8005AF78: blez        $t7, L_8005AFB4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8005AF7C: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8005AFB4;
    }
L_8005AF7C:
    // 0x8005AF7C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005AF80: sw          $zero, -0x254C($at)
    MEM_W(-0X254C, ctx->r1) = 0;
    // 0x8005AF84: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005AF88: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005AF8C: sw          $zero, -0x2548($at)
    MEM_W(-0X2548, ctx->r1) = 0;
    // 0x8005AF90: addiu       $v1, $v1, -0x2558
    ctx->r3 = ADD32(ctx->r3, -0X2558);
    // 0x8005AF94: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005AF98: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8005AF9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005AFA0: addiu       $v0, $v0, -0x2554
    ctx->r2 = ADD32(ctx->r2, -0X2554);
    // 0x8005AFA4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8005AFA8: sw          $zero, -0x2550($at)
    MEM_W(-0X2550, ctx->r1) = 0;
    // 0x8005AFAC: addiu       $t0, $t0, -0x2540
    ctx->r8 = ADD32(ctx->r8, -0X2540);
    // 0x8005AFB0: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_8005AFB4:
    // 0x8005AFB4: lbu         $t9, 0x1D6($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1D6);
    // 0x8005AFB8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005AFBC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005AFC0: sltiu       $at, $t9, 0xE
    ctx->r1 = ctx->r25 < 0XE ? 1 : 0;
    // 0x8005AFC4: addiu       $v1, $v1, -0x2558
    ctx->r3 = ADD32(ctx->r3, -0X2558);
    // 0x8005AFC8: beq         $at, $zero, L_8005B21C
    if (ctx->r1 == 0) {
        // 0x8005AFCC: addiu       $v0, $v0, -0x2554
        ctx->r2 = ADD32(ctx->r2, -0X2554);
            goto L_8005B21C;
    }
    // 0x8005AFCC: addiu       $v0, $v0, -0x2554
    ctx->r2 = ADD32(ctx->r2, -0X2554);
    // 0x8005AFD0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8005AFD4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005AFD8: addu        $at, $at, $t9
    gpr jr_addend_8005AFE4 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8005AFDC: lw          $t9, 0x6EF8($at)
    ctx->r25 = ADD32(ctx->r1, 0X6EF8);
    // 0x8005AFE0: nop

    // 0x8005AFE4: jr          $t9
    // 0x8005AFE8: nop

    switch (jr_addend_8005AFE4 >> 2) {
        case 0: goto L_8005AFEC; break;
        case 1: goto L_8005B044; break;
        case 2: goto L_8005B070; break;
        case 3: goto L_8005B09C; break;
        case 4: goto L_8005B018; break;
        case 5: goto L_8005B0C8; break;
        case 6: goto L_8005B100; break;
        case 7: goto L_8005B138; break;
        case 8: goto L_8005B138; break;
        case 9: goto L_8005B21C; break;
        case 10: goto L_8005B09C; break;
        case 11: goto L_8005B178; break;
        case 12: goto L_8005B1B0; break;
        case 13: goto L_8005B1E8; break;
        default: switch_error(__func__, 0x8005AFE4, 0x800E6EF8);
    }
    // 0x8005AFE8: nop

L_8005AFEC:
    // 0x8005AFEC: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x8005AFF0: lw          $a1, 0xAC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XAC);
    // 0x8005AFF4: lw          $a2, 0xA0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA0);
    // 0x8005AFF8: jal         0x8004F834
    // 0x8005AFFC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_8004F7F4(rdram, ctx);
        goto after_17;
    // 0x8005AFFC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_17:
    // 0x8005B000: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005B004: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005B008: addiu       $v0, $v0, -0x2554
    ctx->r2 = ADD32(ctx->r2, -0X2554);
    // 0x8005B00C: addiu       $v1, $v1, -0x2558
    ctx->r3 = ADD32(ctx->r3, -0X2558);
    // 0x8005B010: b           L_8005B21C
    // 0x8005B014: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_8005B21C;
    // 0x8005B014: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8005B018:
    // 0x8005B018: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x8005B01C: lw          $a1, 0xAC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XAC);
    // 0x8005B020: lw          $a2, 0xA0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B024: jal         0x8004CC60
    // 0x8005B028: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_8004CC20(rdram, ctx);
        goto after_18;
    // 0x8005B028: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_18:
    // 0x8005B02C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005B030: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005B034: addiu       $v0, $v0, -0x2554
    ctx->r2 = ADD32(ctx->r2, -0X2554);
    // 0x8005B038: addiu       $v1, $v1, -0x2558
    ctx->r3 = ADD32(ctx->r3, -0X2558);
    // 0x8005B03C: b           L_8005B21C
    // 0x8005B040: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_8005B21C;
    // 0x8005B040: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8005B044:
    // 0x8005B044: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x8005B048: lw          $a1, 0xAC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XAC);
    // 0x8005B04C: lw          $a2, 0xA0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B050: jal         0x80046564
    // 0x8005B054: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_80046524(rdram, ctx);
        goto after_19;
    // 0x8005B054: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_19:
    // 0x8005B058: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005B05C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005B060: addiu       $v0, $v0, -0x2554
    ctx->r2 = ADD32(ctx->r2, -0X2554);
    // 0x8005B064: addiu       $v1, $v1, -0x2558
    ctx->r3 = ADD32(ctx->r3, -0X2558);
    // 0x8005B068: b           L_8005B21C
    // 0x8005B06C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_8005B21C;
    // 0x8005B06C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8005B070:
    // 0x8005B070: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x8005B074: lw          $a1, 0xAC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XAC);
    // 0x8005B078: lw          $a2, 0xA0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B07C: jal         0x800497D4
    // 0x8005B080: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_80049794(rdram, ctx);
        goto after_20;
    // 0x8005B080: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_20:
    // 0x8005B084: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005B088: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005B08C: addiu       $v0, $v0, -0x2554
    ctx->r2 = ADD32(ctx->r2, -0X2554);
    // 0x8005B090: addiu       $v1, $v1, -0x2558
    ctx->r3 = ADD32(ctx->r3, -0X2558);
    // 0x8005B094: b           L_8005B21C
    // 0x8005B098: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_8005B21C;
    // 0x8005B098: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8005B09C:
    // 0x8005B09C: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x8005B0A0: lw          $a1, 0xAC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XAC);
    // 0x8005B0A4: lw          $a2, 0xA0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B0A8: jal         0x8004D99C
    // 0x8005B0AC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    update_carpet(rdram, ctx);
        goto after_21;
    // 0x8005B0AC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_21:
    // 0x8005B0B0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005B0B4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005B0B8: addiu       $v0, $v0, -0x2554
    ctx->r2 = ADD32(ctx->r2, -0X2554);
    // 0x8005B0BC: addiu       $v1, $v1, -0x2558
    ctx->r3 = ADD32(ctx->r3, -0X2558);
    // 0x8005B0C0: b           L_8005B21C
    // 0x8005B0C4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_8005B21C;
    // 0x8005B0C4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8005B0C8:
    // 0x8005B0C8: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x8005B0CC: lw          $a1, 0xAC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XAC);
    // 0x8005B0D0: lw          $a2, 0xA0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B0D4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8005B0D8: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x8005B0DC: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x8005B0E0: jal         0x8005C504
    // 0x8005B0E4: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    update_tricky(rdram, ctx);
        goto after_22;
    // 0x8005B0E4: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_22:
    // 0x8005B0E8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005B0EC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005B0F0: addiu       $v0, $v0, -0x2554
    ctx->r2 = ADD32(ctx->r2, -0X2554);
    // 0x8005B0F4: addiu       $v1, $v1, -0x2558
    ctx->r3 = ADD32(ctx->r3, -0X2558);
    // 0x8005B0F8: b           L_8005B21C
    // 0x8005B0FC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_8005B21C;
    // 0x8005B0FC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8005B100:
    // 0x8005B100: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x8005B104: lw          $a1, 0xAC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XAC);
    // 0x8005B108: lw          $a2, 0xA0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B10C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8005B110: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x8005B114: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x8005B118: jal         0x8005D270
    // 0x8005B11C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    update_bluey(rdram, ctx);
        goto after_23;
    // 0x8005B11C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_23:
    // 0x8005B120: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005B124: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005B128: addiu       $v0, $v0, -0x2554
    ctx->r2 = ADD32(ctx->r2, -0X2554);
    // 0x8005B12C: addiu       $v1, $v1, -0x2558
    ctx->r3 = ADD32(ctx->r3, -0X2558);
    // 0x8005B130: b           L_8005B21C
    // 0x8005B134: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_8005B21C;
    // 0x8005B134: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8005B138:
    // 0x8005B138: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8005B13C: addiu       $t5, $t5, -0x254C
    ctx->r13 = ADD32(ctx->r13, -0X254C);
    // 0x8005B140: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x8005B144: lw          $a1, 0xAC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XAC);
    // 0x8005B148: lw          $a2, 0xA0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B14C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8005B150: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8005B154: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x8005B158: jal         0x8005D9C0
    // 0x8005B15C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    update_smokey(rdram, ctx);
        goto after_24;
    // 0x8005B15C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_24:
    // 0x8005B160: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005B164: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005B168: addiu       $v0, $v0, -0x2554
    ctx->r2 = ADD32(ctx->r2, -0X2554);
    // 0x8005B16C: addiu       $v1, $v1, -0x2558
    ctx->r3 = ADD32(ctx->r3, -0X2558);
    // 0x8005B170: b           L_8005B21C
    // 0x8005B174: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_8005B21C;
    // 0x8005B174: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8005B178:
    // 0x8005B178: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x8005B17C: lw          $a1, 0xAC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XAC);
    // 0x8005B180: lw          $a2, 0xA0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B184: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8005B188: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x8005B18C: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x8005B190: jal         0x8005E660
    // 0x8005B194: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    update_bubbler(rdram, ctx);
        goto after_25;
    // 0x8005B194: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_25:
    // 0x8005B198: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005B19C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005B1A0: addiu       $v0, $v0, -0x2554
    ctx->r2 = ADD32(ctx->r2, -0X2554);
    // 0x8005B1A4: addiu       $v1, $v1, -0x2558
    ctx->r3 = ADD32(ctx->r3, -0X2558);
    // 0x8005B1A8: b           L_8005B21C
    // 0x8005B1AC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_8005B21C;
    // 0x8005B1AC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8005B1B0:
    // 0x8005B1B0: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x8005B1B4: lw          $a1, 0xAC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XAC);
    // 0x8005B1B8: lw          $a2, 0xA0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B1BC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8005B1C0: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x8005B1C4: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x8005B1C8: jal         0x8005EC30
    // 0x8005B1CC: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    update_wizpig(rdram, ctx);
        goto after_26;
    // 0x8005B1CC: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_26:
    // 0x8005B1D0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005B1D4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005B1D8: addiu       $v0, $v0, -0x2554
    ctx->r2 = ADD32(ctx->r2, -0X2554);
    // 0x8005B1DC: addiu       $v1, $v1, -0x2558
    ctx->r3 = ADD32(ctx->r3, -0X2558);
    // 0x8005B1E0: b           L_8005B21C
    // 0x8005B1E4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_8005B21C;
    // 0x8005B1E4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8005B1E8:
    // 0x8005B1E8: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x8005B1EC: lw          $a1, 0xAC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XAC);
    // 0x8005B1F0: lw          $a2, 0xA0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B1F4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8005B1F8: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x8005B1FC: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x8005B200: jal         0x8005F4B0
    // 0x8005B204: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    update_rocket(rdram, ctx);
        goto after_27;
    // 0x8005B204: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_27:
    // 0x8005B208: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005B20C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005B210: addiu       $v0, $v0, -0x2554
    ctx->r2 = ADD32(ctx->r2, -0X2554);
    // 0x8005B214: addiu       $v1, $v1, -0x2558
    ctx->r3 = ADD32(ctx->r3, -0X2558);
    // 0x8005B218: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8005B21C:
    // 0x8005B21C: lw          $t6, 0x94($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X94);
    // 0x8005B220: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B224: beq         $t6, $t3, L_8005B240
    if (ctx->r14 == ctx->r11) {
        // 0x8005B228: nop
    
            goto L_8005B240;
    }
    // 0x8005B228: nop

    // 0x8005B22C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8005B230: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x8005B234: lw          $a3, 0xA8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA8);
    // 0x8005B238: jal         0x800050D0
    // 0x8005B23C: nop

    racer_sound_update(rdram, ctx);
        goto after_28;
    // 0x8005B23C: nop

    after_28:
L_8005B240:
    // 0x8005B240: lwc1        $f18, 0xA8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x8005B244: lwc1        $f8, 0x84($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8005B248: swc1        $f18, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f18.u32l;
    // 0x8005B24C: lb          $t8, 0x192($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X192);
    // 0x8005B250: lw          $a1, 0xA0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B254: sw          $t8, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r24;
    // 0x8005B258: lb          $a0, 0x192($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X192);
    // 0x8005B25C: lw          $a2, 0x8C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8C);
    // 0x8005B260: lw          $a3, 0x88($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X88);
    // 0x8005B264: addiu       $t7, $s0, 0xA8
    ctx->r15 = ADD32(ctx->r16, 0XA8);
    // 0x8005B268: addiu       $t9, $s0, 0x1C8
    ctx->r25 = ADD32(ctx->r16, 0X1C8);
    // 0x8005B26C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8005B270: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8005B274: jal         0x80018618
    // 0x8005B278: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    checkpoint_is_passed(rdram, ctx);
        goto after_29;
    // 0x8005B278: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_29:
    // 0x8005B27C: addiu       $at, $zero, -0x64
    ctx->r1 = ADD32(0, -0X64);
    // 0x8005B280: bne         $v0, $at, L_8005B29C
    if (ctx->r2 != ctx->r1) {
        // 0x8005B284: or          $t2, $v0, $zero
        ctx->r10 = ctx->r2 | 0;
            goto L_8005B29C;
    }
    // 0x8005B284: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x8005B288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005B28C: jal         0x8005C410
    // 0x8005B290: sw          $v0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r2;
    racer_update_progress(rdram, ctx);
        goto after_30;
    // 0x8005B290: sw          $v0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r2;
    after_30:
    // 0x8005B294: lw          $t2, 0x9C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X9C);
    // 0x8005B298: nop

L_8005B29C:
    // 0x8005B29C: lb          $a0, 0x192($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X192);
    // 0x8005B2A0: lbu         $a1, 0x1C8($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1C8);
    // 0x8005B2A4: jal         0x8001BA50
    // 0x8005B2A8: sw          $t2, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r10;
    find_next_checkpoint_node(rdram, ctx);
        goto after_31;
    // 0x8005B2A8: sw          $t2, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r10;
    after_31:
    // 0x8005B2AC: lb          $t5, 0x1CA($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1CA);
    // 0x8005B2B0: lw          $t2, 0x9C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X9C);
    // 0x8005B2B4: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x8005B2B8: lb          $t8, 0x36($t6)
    ctx->r24 = MEM_B(ctx->r14, 0X36);
    // 0x8005B2BC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8005B2C0: bne         $t8, $at, L_8005B2E0
    if (ctx->r24 != ctx->r1) {
        // 0x8005B2C4: nop
    
            goto L_8005B2E0;
    }
    // 0x8005B2C4: nop

    // 0x8005B2C8: lb          $t9, 0x1E5($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1E5);
    // 0x8005B2CC: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x8005B2D0: beq         $t9, $zero, L_8005B2E0
    if (ctx->r25 == 0) {
        // 0x8005B2D4: sb          $t7, 0x201($s0)
        MEM_B(0X201, ctx->r16) = ctx->r15;
            goto L_8005B2E0;
    }
    // 0x8005B2D4: sb          $t7, 0x201($s0)
    MEM_B(0X201, ctx->r16) = ctx->r15;
    // 0x8005B2D8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8005B2DC: sb          $t5, 0x1C8($s0)
    MEM_B(0X1C8, ctx->r16) = ctx->r13;
L_8005B2E0:
    // 0x8005B2E0: lb          $t6, 0x1CA($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1CA);
    // 0x8005B2E4: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8005B2E8: addu        $t8, $v0, $t6
    ctx->r24 = ADD32(ctx->r2, ctx->r14);
    // 0x8005B2EC: lb          $v1, 0x36($t8)
    ctx->r3 = MEM_B(ctx->r24, 0X36);
    // 0x8005B2F0: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x8005B2F4: bne         $v1, $at, L_8005B31C
    if (ctx->r3 != ctx->r1) {
        // 0x8005B2F8: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8005B31C;
    }
    // 0x8005B2F8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8005B2FC: lb          $t9, 0x4B($t7)
    ctx->r25 = MEM_B(ctx->r15, 0X4B);
    // 0x8005B300: lb          $t6, 0x1CA($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1CA);
    // 0x8005B304: addiu       $t5, $t9, 0x1
    ctx->r13 = ADD32(ctx->r25, 0X1);
    // 0x8005B308: sb          $t5, 0x193($s0)
    MEM_B(0X193, ctx->r16) = ctx->r13;
    // 0x8005B30C: addu        $t8, $v0, $t6
    ctx->r24 = ADD32(ctx->r2, ctx->r14);
    // 0x8005B310: lb          $v1, 0x36($t8)
    ctx->r3 = MEM_B(ctx->r24, 0X36);
    // 0x8005B314: nop

    // 0x8005B318: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
L_8005B31C:
    // 0x8005B31C: bne         $v1, $at, L_8005B360
    if (ctx->r3 != ctx->r1) {
        // 0x8005B320: nop
    
            goto L_8005B360;
    }
    // 0x8005B320: nop

    // 0x8005B324: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005B328: lui         $at, 0xC010
    ctx->r1 = S32(0XC010 << 16);
    // 0x8005B32C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8005B330: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005B334: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x8005B338: c.lt.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d < ctx->f4.d;
    // 0x8005B33C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005B340: bc1f        L_8005B360
    if (!c1cs) {
        // 0x8005B344: nop
    
            goto L_8005B360;
    }
    // 0x8005B344: nop

    // 0x8005B348: lwc1        $f7, 0x6F30($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6F30);
    // 0x8005B34C: lwc1        $f6, 0x6F34($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6F34);
    // 0x8005B350: nop

    // 0x8005B354: mul.d       $f18, $f0, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x8005B358: cvt.s.d     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f8.fl = CVT_S_D(ctx->f18.d);
    // 0x8005B35C: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
L_8005B360:
    // 0x8005B360: bne         $t2, $zero, L_8005B414
    if (ctx->r10 != 0) {
        // 0x8005B364: nop
    
            goto L_8005B414;
    }
    // 0x8005B364: nop

    // 0x8005B368: lb          $t7, 0x1CA($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1CA);
    // 0x8005B36C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005B370: addu        $t9, $v0, $t7
    ctx->r25 = ADD32(ctx->r2, ctx->r15);
    // 0x8005B374: lb          $t5, 0x36($t9)
    ctx->r13 = MEM_B(ctx->r25, 0X36);
    // 0x8005B378: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005B37C: bne         $t5, $at, L_8005B388
    if (ctx->r13 != ctx->r1) {
        // 0x8005B380: nop
    
            goto L_8005B388;
    }
    // 0x8005B380: nop

    // 0x8005B384: sb          $t6, 0x1C8($s0)
    MEM_B(0X1C8, ctx->r16) = ctx->r14;
L_8005B388:
    // 0x8005B388: jal         0x8001BA98
    // 0x8005B38C: nop

    get_checkpoint_count(rdram, ctx);
        goto after_32;
    // 0x8005B38C: nop

    after_32:
    // 0x8005B390: lb          $t8, 0x192($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X192);
    // 0x8005B394: nop

    // 0x8005B398: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x8005B39C: sb          $t7, 0x192($s0)
    MEM_B(0X192, ctx->r16) = ctx->r15;
    // 0x8005B3A0: lb          $t9, 0x192($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X192);
    // 0x8005B3A4: nop

    // 0x8005B3A8: slt         $at, $t9, $v0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8005B3AC: bne         $at, $zero, L_8005B3E0
    if (ctx->r1 != 0) {
        // 0x8005B3B0: lw          $t8, 0x70($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X70);
            goto L_8005B3E0;
    }
    // 0x8005B3B0: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x8005B3B4: lh          $t5, 0x190($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X190);
    // 0x8005B3B8: sb          $zero, 0x192($s0)
    MEM_B(0X192, ctx->r16) = 0;
    // 0x8005B3BC: blez        $t5, L_8005B3E0
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8005B3C0: lw          $t8, 0x70($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X70);
            goto L_8005B3E0;
    }
    // 0x8005B3C0: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x8005B3C4: lb          $v1, 0x193($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X193);
    // 0x8005B3C8: nop

    // 0x8005B3CC: slti        $at, $v1, 0x78
    ctx->r1 = SIGNED(ctx->r3) < 0X78 ? 1 : 0;
    // 0x8005B3D0: beq         $at, $zero, L_8005B3DC
    if (ctx->r1 == 0) {
        // 0x8005B3D4: addiu       $t6, $v1, 0x1
        ctx->r14 = ADD32(ctx->r3, 0X1);
            goto L_8005B3DC;
    }
    // 0x8005B3D4: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x8005B3D8: sb          $t6, 0x193($s0)
    MEM_B(0X193, ctx->r16) = ctx->r14;
L_8005B3DC:
    // 0x8005B3DC: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
L_8005B3E0:
    // 0x8005B3E0: lh          $v1, 0x190($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X190);
    // 0x8005B3E4: lb          $t7, 0x4B($t8)
    ctx->r15 = MEM_B(ctx->r24, 0X4B);
    // 0x8005B3E8: addiu       $t8, $zero, 0x2710
    ctx->r24 = ADD32(0, 0X2710);
    // 0x8005B3EC: addiu       $t9, $t7, 0x3
    ctx->r25 = ADD32(ctx->r15, 0X3);
    // 0x8005B3F0: multu       $t9, $v0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005B3F4: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x8005B3F8: mflo        $t5
    ctx->r13 = lo;
    // 0x8005B3FC: slt         $at, $v1, $t5
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8005B400: beq         $at, $zero, L_8005B40C
    if (ctx->r1 == 0) {
        // 0x8005B404: nop
    
            goto L_8005B40C;
    }
    // 0x8005B404: nop

    // 0x8005B408: sh          $t6, 0x190($s0)
    MEM_H(0X190, ctx->r16) = ctx->r14;
L_8005B40C:
    // 0x8005B40C: b           L_8005B448
    // 0x8005B410: sh          $t8, 0x1A8($s0)
    MEM_H(0X1A8, ctx->r16) = ctx->r24;
        goto L_8005B448;
    // 0x8005B410: sh          $t8, 0x1A8($s0)
    MEM_H(0X1A8, ctx->r16) = ctx->r24;
L_8005B414:
    // 0x8005B414: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x8005B418: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005B41C: bne         $t7, $at, L_8005B444
    if (ctx->r15 != ctx->r1) {
        // 0x8005B420: nop
    
            goto L_8005B444;
    }
    // 0x8005B420: nop

    // 0x8005B424: lwc1        $f0, 0x80($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8005B428: lwc1        $f10, 0xA8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x8005B42C: nop

    // 0x8005B430: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8005B434: nop

    // 0x8005B438: bc1f        L_8005B444
    if (!c1cs) {
        // 0x8005B43C: nop
    
            goto L_8005B444;
    }
    // 0x8005B43C: nop

    // 0x8005B440: swc1        $f0, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f0.u32l;
L_8005B444:
    // 0x8005B444: sh          $t2, 0x1A8($s0)
    MEM_H(0X1A8, ctx->r16) = ctx->r10;
L_8005B448:
    // 0x8005B448: lw          $t9, 0xA0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B44C: nop

    // 0x8005B450: lwc1        $f4, 0xC($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0XC);
    // 0x8005B454: nop

    // 0x8005B458: swc1        $f4, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f4.u32l;
    // 0x8005B45C: lw          $t5, 0xA0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B460: nop

    // 0x8005B464: lwc1        $f6, 0x10($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X10);
    // 0x8005B468: nop

    // 0x8005B46C: swc1        $f6, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f6.u32l;
    // 0x8005B470: lw          $t6, 0xA0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B474: nop

    // 0x8005B478: lwc1        $f18, 0x14($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X14);
    // 0x8005B47C: b           L_8005B4BC
    // 0x8005B480: swc1        $f18, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f18.u32l;
        goto L_8005B4BC;
    // 0x8005B480: swc1        $f18, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f18.u32l;
    // 0x8005B484: lw          $a3, 0xAC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XAC);
L_8005B488:
    // 0x8005B488: jal         0x8005B884
    // 0x8005B48C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8005B818(rdram, ctx);
        goto after_33;
    // 0x8005B48C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_33:
    // 0x8005B490: lw          $t8, 0x94($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X94);
    // 0x8005B494: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8005B498: beq         $t8, $t3, L_8005B4BC
    if (ctx->r24 == ctx->r11) {
        // 0x8005B49C: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_8005B4BC;
    }
    // 0x8005B49C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8005B4A0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8005B4A4: lw          $a2, -0x2558($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X2558);
    // 0x8005B4A8: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B4AC: lw          $a1, -0x2554($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X2554);
    // 0x8005B4B0: lw          $a3, 0xA8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA8);
    // 0x8005B4B4: jal         0x800050D0
    // 0x8005B4B8: nop

    racer_sound_update(rdram, ctx);
        goto after_34;
    // 0x8005B4B8: nop

    after_34:
L_8005B4BC:
    // 0x8005B4BC: lwc1        $f8, 0xAC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8005B4C0: lb          $t7, 0x175($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X175);
    // 0x8005B4C4: cvt.d.s     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f12.d = CVT_D_S(ctx->f8.fl);
    // 0x8005B4C8: bne         $t7, $zero, L_8005B4FC
    if (ctx->r15 != 0) {
        // 0x8005B4CC: lw          $t9, 0xA8($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XA8);
            goto L_8005B4FC;
    }
    // 0x8005B4CC: lw          $t9, 0xA8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA8);
    // 0x8005B4D0: lw          $a0, 0x178($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X178);
    // 0x8005B4D4: nop

    // 0x8005B4D8: beq         $a0, $zero, L_8005B4FC
    if (ctx->r4 == 0) {
        // 0x8005B4DC: lw          $t9, 0xA8($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XA8);
            goto L_8005B4FC;
    }
    // 0x8005B4DC: lw          $t9, 0xA8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA8);
    // 0x8005B4E0: swc1        $f13, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(13 - 1) * 2];
    // 0x8005B4E4: jal         0x8000488C
    // 0x8005B4E8: swc1        $f12, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f12.u32l;
    sndp_stop(rdram, ctx);
        goto after_35;
    // 0x8005B4E8: swc1        $f12, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f12.u32l;
    after_35:
    // 0x8005B4EC: lwc1        $f13, 0x40($sp)
    ctx->f_odd[(13 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x8005B4F0: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8005B4F4: sw          $zero, 0x178($s0)
    MEM_W(0X178, ctx->r16) = 0;
    // 0x8005B4F8: lw          $t9, 0xA8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA8);
L_8005B4FC:
    // 0x8005B4FC: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B500: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x8005B504: lw          $a2, 0x88($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X88);
    // 0x8005B508: lw          $a3, 0x84($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X84);
    // 0x8005B50C: swc1        $f13, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(13 - 1) * 2];
    // 0x8005B510: swc1        $f12, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f12.u32l;
    // 0x8005B514: jal         0x80018D14
    // 0x8005B518: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_80018CE0(rdram, ctx);
        goto after_36;
    // 0x8005B518: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_36:
    // 0x8005B51C: lb          $a2, 0x188($s0)
    ctx->r6 = MEM_B(ctx->r16, 0X188);
    // 0x8005B520: lwc1        $f13, 0x40($sp)
    ctx->f_odd[(13 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x8005B524: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8005B528: blez        $a2, L_8005B550
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8005B52C: nop
    
            goto L_8005B550;
    }
    // 0x8005B52C: nop

    // 0x8005B530: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B534: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8005B538: swc1        $f13, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(13 - 1) * 2];
    // 0x8005B53C: jal         0x80057720
    // 0x8005B540: swc1        $f12, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f12.u32l;
    drop_bananas(rdram, ctx);
        goto after_37;
    // 0x8005B540: swc1        $f12, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f12.u32l;
    after_37:
    // 0x8005B544: lwc1        $f13, 0x40($sp)
    ctx->f_odd[(13 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x8005B548: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8005B54C: nop

L_8005B550:
    // 0x8005B550: lw          $t5, 0x148($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X148);
    // 0x8005B554: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8005B558: beq         $t5, $zero, L_8005B570
    if (ctx->r13 == 0) {
        // 0x8005B55C: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_8005B570;
    }
    // 0x8005B55C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005B560: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005B564: sw          $zero, 0x148($s0)
    MEM_W(0X148, ctx->r16) = 0;
    // 0x8005B568: swc1        $f16, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f16.u32l;
    // 0x8005B56C: swc1        $f16, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f16.u32l;
L_8005B570:
    // 0x8005B570: lwc1        $f14, 0x90($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X90);
    // 0x8005B574: lwc1        $f0, 0x8C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x8005B578: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005B57C: c.le.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl <= ctx->f14.fl;
    // 0x8005B580: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005B584: bc1f        L_8005B59C
    if (!c1cs) {
        // 0x8005B588: sub.s       $f10, $f14, $f0
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f0.fl;
            goto L_8005B59C;
    }
    // 0x8005B588: sub.s       $f10, $f14, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x8005B58C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005B590: lwc1        $f2, 0x6F38($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6F38);
    // 0x8005B594: b           L_8005B5A8
    // 0x8005B598: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
        goto L_8005B5A8;
    // 0x8005B598: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
L_8005B59C:
    // 0x8005B59C: lwc1        $f2, 0x6F3C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6F3C);
    // 0x8005B5A0: nop

    // 0x8005B5A4: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
L_8005B5A8:
    // 0x8005B5A8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8005B5AC: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8005B5B0: mul.d       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8005B5B4: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x8005B5B8: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8005B5BC: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x8005B5C0: add.d       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f18.d + ctx->f8.d;
    // 0x8005B5C4: mul.d       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f12.d);
    // 0x8005B5C8: add.d       $f18, $f6, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = ctx->f6.d + ctx->f4.d;
    // 0x8005B5CC: cvt.s.d     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f8.fl = CVT_S_D(ctx->f18.d);
    // 0x8005B5D0: bc1f        L_8005B5F0
    if (!c1cs) {
        // 0x8005B5D4: swc1        $f8, 0x8C($s0)
        MEM_W(0X8C, ctx->r16) = ctx->f8.u32l;
            goto L_8005B5F0;
    }
    // 0x8005B5D4: swc1        $f8, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->f8.u32l;
    // 0x8005B5D8: lwc1        $f10, 0x8C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x8005B5DC: nop

    // 0x8005B5E0: c.le.s      $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f10.fl <= ctx->f14.fl;
    // 0x8005B5E4: nop

    // 0x8005B5E8: bc1t        L_8005B618
    if (c1cs) {
        // 0x8005B5EC: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8005B618;
    }
    // 0x8005B5EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8005B5F0:
    // 0x8005B5F0: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x8005B5F4: nop

    // 0x8005B5F8: bc1f        L_8005B624
    if (!c1cs) {
        // 0x8005B5FC: nop
    
            goto L_8005B624;
    }
    // 0x8005B5FC: nop

    // 0x8005B600: lwc1        $f6, 0x8C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x8005B604: nop

    // 0x8005B608: c.le.s      $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f14.fl <= ctx->f6.fl;
    // 0x8005B60C: nop

    // 0x8005B610: bc1f        L_8005B624
    if (!c1cs) {
        // 0x8005B614: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8005B624;
    }
    // 0x8005B614: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8005B618:
    // 0x8005B618: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8005B61C: swc1        $f14, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->f14.u32l;
    // 0x8005B620: swc1        $f4, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->f4.u32l;
L_8005B624:
    // 0x8005B624: lh          $v1, 0x16A($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X16A);
    // 0x8005B628: lh          $t6, 0x16C($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X16C);
    // 0x8005B62C: lw          $t7, 0xA8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA8);
    // 0x8005B630: subu        $t8, $t6, $v1
    ctx->r24 = SUB32(ctx->r14, ctx->r3);
    // 0x8005B634: multu       $t8, $t7
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005B638: mflo        $t2
    ctx->r10 = lo;
    // 0x8005B63C: sra         $t9, $t2, 3
    ctx->r25 = S32(SIGNED(ctx->r10) >> 3);
    // 0x8005B640: slti        $at, $t9, 0x801
    ctx->r1 = SIGNED(ctx->r25) < 0X801 ? 1 : 0;
    // 0x8005B644: bne         $at, $zero, L_8005B650
    if (ctx->r1 != 0) {
        // 0x8005B648: or          $t2, $t9, $zero
        ctx->r10 = ctx->r25 | 0;
            goto L_8005B650;
    }
    // 0x8005B648: or          $t2, $t9, $zero
    ctx->r10 = ctx->r25 | 0;
    // 0x8005B64C: addiu       $t2, $zero, 0x800
    ctx->r10 = ADD32(0, 0X800);
L_8005B650:
    // 0x8005B650: slti        $at, $t2, -0x800
    ctx->r1 = SIGNED(ctx->r10) < -0X800 ? 1 : 0;
    // 0x8005B654: beq         $at, $zero, L_8005B660
    if (ctx->r1 == 0) {
        // 0x8005B658: nop
    
            goto L_8005B660;
    }
    // 0x8005B658: nop

    // 0x8005B65C: addiu       $t2, $zero, -0x800
    ctx->r10 = ADD32(0, -0X800);
L_8005B660:
    // 0x8005B660: lh          $v0, -0x2F3C($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2F3C);
    // 0x8005B664: addu        $t6, $v1, $t2
    ctx->r14 = ADD32(ctx->r3, ctx->r10);
    // 0x8005B668: beq         $v0, $zero, L_8005B678
    if (ctx->r2 == 0) {
        // 0x8005B66C: addu        $t5, $v1, $v0
        ctx->r13 = ADD32(ctx->r3, ctx->r2);
            goto L_8005B678;
    }
    // 0x8005B66C: addu        $t5, $v1, $v0
    ctx->r13 = ADD32(ctx->r3, ctx->r2);
    // 0x8005B670: b           L_8005B67C
    // 0x8005B674: sh          $t5, 0x16A($s0)
    MEM_H(0X16A, ctx->r16) = ctx->r13;
        goto L_8005B67C;
    // 0x8005B674: sh          $t5, 0x16A($s0)
    MEM_H(0X16A, ctx->r16) = ctx->r13;
L_8005B678:
    // 0x8005B678: sh          $t6, 0x16A($s0)
    MEM_H(0X16A, ctx->r16) = ctx->r14;
L_8005B67C:
    // 0x8005B67C: lh          $v0, 0x18E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X18E);
    // 0x8005B680: nop

    // 0x8005B684: blez        $v0, L_8005B74C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8005B688: slti        $at, $v0, 0x3D
        ctx->r1 = SIGNED(ctx->r2) < 0X3D ? 1 : 0;
            goto L_8005B74C;
    }
    // 0x8005B688: slti        $at, $v0, 0x3D
    ctx->r1 = SIGNED(ctx->r2) < 0X3D ? 1 : 0;
    // 0x8005B68C: bne         $at, $zero, L_8005B708
    if (ctx->r1 != 0) {
        // 0x8005B690: nop
    
            goto L_8005B708;
    }
    // 0x8005B690: nop

    // 0x8005B694: lw          $a0, 0x17C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X17C);
    // 0x8005B698: nop

    // 0x8005B69C: beq         $a0, $zero, L_8005B6CC
    if (ctx->r4 == 0) {
        // 0x8005B6A0: nop
    
            goto L_8005B6CC;
    }
    // 0x8005B6A0: nop

    // 0x8005B6A4: lw          $v0, 0xA0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B6A8: nop

    // 0x8005B6AC: lw          $a1, 0xC($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XC);
    // 0x8005B6B0: lw          $a2, 0x10($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X10);
    // 0x8005B6B4: lw          $a3, 0x14($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X14);
    // 0x8005B6B8: jal         0x800096D8
    // 0x8005B6BC: nop

    audspat_point_set_position(rdram, ctx);
        goto after_38;
    // 0x8005B6BC: nop

    after_38:
    // 0x8005B6C0: lh          $v0, 0x18E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X18E);
    // 0x8005B6C4: b           L_8005B72C
    // 0x8005B6C8: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
        goto L_8005B72C;
    // 0x8005B6C8: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
L_8005B6CC:
    // 0x8005B6CC: lw          $t8, 0x118($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X118);
    // 0x8005B6D0: lw          $t7, 0xA0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B6D4: beq         $t8, $zero, L_8005B728
    if (ctx->r24 == 0) {
        // 0x8005B6D8: addiu       $a0, $zero, 0x9F
        ctx->r4 = ADD32(0, 0X9F);
            goto L_8005B728;
    }
    // 0x8005B6D8: addiu       $a0, $zero, 0x9F
    ctx->r4 = ADD32(0, 0X9F);
    // 0x8005B6DC: lw          $a1, 0xC($t7)
    ctx->r5 = MEM_W(ctx->r15, 0XC);
    // 0x8005B6E0: lw          $a2, 0x10($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X10);
    // 0x8005B6E4: lw          $a3, 0x14($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X14);
    // 0x8005B6E8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8005B6EC: addiu       $t5, $s0, 0x17C
    ctx->r13 = ADD32(ctx->r16, 0X17C);
    // 0x8005B6F0: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8005B6F4: jal         0x80009558
    // 0x8005B6F8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_39;
    // 0x8005B6F8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_39:
    // 0x8005B6FC: lh          $v0, 0x18E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X18E);
    // 0x8005B700: b           L_8005B72C
    // 0x8005B704: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
        goto L_8005B72C;
    // 0x8005B704: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
L_8005B708:
    // 0x8005B708: lw          $a0, 0x17C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X17C);
    // 0x8005B70C: nop

    // 0x8005B710: beq         $a0, $zero, L_8005B72C
    if (ctx->r4 == 0) {
        // 0x8005B714: lw          $t6, 0xA8($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XA8);
            goto L_8005B72C;
    }
    // 0x8005B714: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
    // 0x8005B718: jal         0x800096F8
    // 0x8005B71C: nop

    audspat_point_stop(rdram, ctx);
        goto after_40;
    // 0x8005B71C: nop

    after_40:
    // 0x8005B720: lh          $v0, 0x18E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X18E);
    // 0x8005B724: sw          $zero, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = 0;
L_8005B728:
    // 0x8005B728: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
L_8005B72C:
    // 0x8005B72C: nop

    // 0x8005B730: subu        $t8, $v0, $t6
    ctx->r24 = SUB32(ctx->r2, ctx->r14);
    // 0x8005B734: sh          $t8, 0x18E($s0)
    MEM_H(0X18E, ctx->r16) = ctx->r24;
    // 0x8005B738: lh          $t7, 0x18E($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X18E);
    // 0x8005B73C: nop

    // 0x8005B740: bgtz        $t7, L_8005B74C
    if (SIGNED(ctx->r15) > 0) {
        // 0x8005B744: nop
    
            goto L_8005B74C;
    }
    // 0x8005B744: nop

    // 0x8005B748: sb          $zero, 0x189($s0)
    MEM_B(0X189, ctx->r16) = 0;
L_8005B74C:
    // 0x8005B74C: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    // 0x8005B750: lw          $v0, 0xA0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B754: beq         $a0, $zero, L_8005B770
    if (ctx->r4 == 0) {
        // 0x8005B758: nop
    
            goto L_8005B770;
    }
    // 0x8005B758: nop

    // 0x8005B75C: lw          $a1, 0xC($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XC);
    // 0x8005B760: lw          $a2, 0x10($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X10);
    // 0x8005B764: lw          $a3, 0x14($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X14);
    // 0x8005B768: jal         0x800096D8
    // 0x8005B76C: nop

    audspat_point_set_position(rdram, ctx);
        goto after_41;
    // 0x8005B76C: nop

    after_41:
L_8005B770:
    // 0x8005B770: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005B774: sb          $zero, -0x24FC($at)
    MEM_B(-0X24FC, ctx->r1) = 0;
    // 0x8005B778: lw          $v0, 0x150($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X150);
    // 0x8005B77C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8005B780: beq         $v0, $zero, L_8005B864
    if (ctx->r2 == 0) {
        // 0x8005B784: nop
    
            goto L_8005B864;
    }
    // 0x8005B784: nop

    // 0x8005B788: lw          $t9, -0x2540($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2540);
    // 0x8005B78C: lw          $t5, 0xA0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B790: bne         $t9, $zero, L_8005B864
    if (ctx->r25 != 0) {
        // 0x8005B794: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8005B864;
    }
    // 0x8005B794: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005B798: lwc1        $f18, 0xC($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0XC);
    // 0x8005B79C: jal         0x8001E2D0
    // 0x8005B7A0: swc1        $f18, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f18.u32l;
    get_misc_asset(rdram, ctx);
        goto after_42;
    // 0x8005B7A0: swc1        $f18, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f18.u32l;
    after_42:
    // 0x8005B7A4: lb          $t6, 0x3($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X3);
    // 0x8005B7A8: lw          $v1, 0xA0($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B7AC: addu        $t8, $t6, $v0
    ctx->r24 = ADD32(ctx->r14, ctx->r2);
    // 0x8005B7B0: lb          $t7, 0x0($t8)
    ctx->r15 = MEM_B(ctx->r24, 0X0);
    // 0x8005B7B4: lwc1        $f6, 0x10($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8005B7B8: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8005B7BC: lw          $t9, 0x150($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X150);
    // 0x8005B7C0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8005B7C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005B7C8: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8005B7CC: swc1        $f4, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->f4.u32l;
    // 0x8005B7D0: lw          $t5, 0x150($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X150);
    // 0x8005B7D4: lwc1        $f18, 0x14($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8005B7D8: nop

    // 0x8005B7DC: swc1        $f18, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->f18.u32l;
    // 0x8005B7E0: lwc1        $f10, 0x6F40($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6F40);
    // 0x8005B7E4: lwc1        $f8, 0x30($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X30);
    // 0x8005B7E8: lw          $t6, 0x150($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X150);
    // 0x8005B7EC: div.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8005B7F0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005B7F4: swc1        $f6, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f6.u32l;
    // 0x8005B7F8: lwc1        $f4, 0x30($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X30);
    // 0x8005B7FC: lwc1        $f8, 0x6F4C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6F4C);
    // 0x8005B800: lwc1        $f9, 0x6F48($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6F48);
    // 0x8005B804: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x8005B808: c.lt.d      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.d < ctx->f8.d;
    // 0x8005B80C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8005B810: bc1f        L_8005B830
    if (!c1cs) {
        // 0x8005B814: nop
    
            goto L_8005B830;
    }
    // 0x8005B814: nop

    // 0x8005B818: lw          $v0, 0x150($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X150);
    // 0x8005B81C: nop

    // 0x8005B820: lh          $t8, 0x6($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X6);
    // 0x8005B824: nop

    // 0x8005B828: ori         $t7, $t8, 0x4000
    ctx->r15 = ctx->r24 | 0X4000;
    // 0x8005B82C: sh          $t7, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r15;
L_8005B830:
    // 0x8005B830: lw          $v0, 0x150($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X150);
    // 0x8005B834: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8005B838: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8005B83C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005B840: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x8005B844: c.lt.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d < ctx->f4.d;
    // 0x8005B848: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005B84C: bc1f        L_8005B860
    if (!c1cs) {
        // 0x8005B850: nop
    
            goto L_8005B860;
    }
    // 0x8005B850: nop

    // 0x8005B854: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8005B858: nop

    // 0x8005B85C: swc1        $f18, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f18.u32l;
L_8005B860:
    // 0x8005B860: sw          $zero, 0x150($s0)
    MEM_W(0X150, ctx->r16) = 0;
L_8005B864:
    // 0x8005B864: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8005B868: sb          $t9, 0x1FE($s0)
    MEM_B(0X1FE, ctx->r16) = ctx->r25;
    // 0x8005B86C: jal         0x8004F7BC
    // 0x8005B870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    set_racer_tail_lights(rdram, ctx);
        goto after_43;
    // 0x8005B870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_43:
    // 0x8005B874: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8005B878: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8005B87C: jr          $ra
    // 0x8005B880: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x8005B880: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void func_8005B818(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B884: addiu       $sp, $sp, -0x120
    ctx->r29 = ADD32(ctx->r29, -0X120);
    // 0x8005B888: sw          $s3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r19;
    // 0x8005B88C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8005B890: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8005B894: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x8005B898: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8005B89C: sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
    // 0x8005B8A0: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x8005B8A4: swc1        $f29, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x8005B8A8: swc1        $f28, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f28.u32l;
    // 0x8005B8AC: swc1        $f27, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x8005B8B0: swc1        $f26, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f26.u32l;
    // 0x8005B8B4: swc1        $f25, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x8005B8B8: swc1        $f24, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f24.u32l;
    // 0x8005B8BC: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8005B8C0: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x8005B8C4: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8005B8C8: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8005B8CC: sw          $a2, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r6;
    // 0x8005B8D0: sw          $a3, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r7;
    // 0x8005B8D4: jal         0x8001E2D0
    // 0x8005B8D8: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x8005B8D8: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    after_0:
    // 0x8005B8DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005B8E0: jal         0x8006BFF0
    // 0x8005B8E4: sw          $v0, -0x251C($at)
    MEM_W(-0X251C, ctx->r1) = ctx->r2;
    level_header(rdram, ctx);
        goto after_1;
    // 0x8005B8E4: sw          $v0, -0x251C($at)
    MEM_W(-0X251C, ctx->r1) = ctx->r2;
    after_1:
    // 0x8005B8E8: jal         0x8001BA98
    // 0x8005B8EC: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    get_checkpoint_count(rdram, ctx);
        goto after_2;
    // 0x8005B8EC: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    after_2:
    // 0x8005B8F0: beq         $v0, $zero, L_8005C3B8
    if (ctx->r2 == 0) {
        // 0x8005B8F4: sw          $v0, 0x114($sp)
        MEM_W(0X114, ctx->r29) = ctx->r2;
            goto L_8005C3B8;
    }
    // 0x8005B8F4: sw          $v0, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r2;
    // 0x8005B8F8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005B8FC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8005B900: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8005B904: sb          $zero, 0x1C9($s1)
    MEM_B(0X1C9, ctx->r17) = 0;
    // 0x8005B908: sb          $zero, 0x1F5($s1)
    MEM_B(0X1F5, ctx->r17) = 0;
    // 0x8005B90C: sb          $zero, 0x187($s1)
    MEM_B(0X187, ctx->r17) = 0;
    // 0x8005B910: swc1        $f4, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->f4.u32l;
    // 0x8005B914: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x8005B918: swc1        $f2, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f2.u32l;
    // 0x8005B91C: lwc1        $f0, 0x124($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X124);
    // 0x8005B920: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8005B924: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005B928: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8005B92C: nop

    // 0x8005B930: bc1f        L_8005B948
    if (!c1cs) {
        // 0x8005B934: nop
    
            goto L_8005B948;
    }
    // 0x8005B934: nop

    // 0x8005B938: neg.s       $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = -ctx->f2.fl;
    // 0x8005B93C: swc1        $f8, 0x124($s1)
    MEM_W(0X124, ctx->r17) = ctx->f8.u32l;
    // 0x8005B940: lwc1        $f0, 0x124($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X124);
    // 0x8005B944: nop

L_8005B948:
    // 0x8005B948: lwc1        $f10, 0x8C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8005B94C: nop

    // 0x8005B950: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x8005B954: nop

    // 0x8005B958: bc1f        L_8005B96C
    if (!c1cs) {
        // 0x8005B95C: nop
    
            goto L_8005B96C;
    }
    // 0x8005B95C: nop

    // 0x8005B960: swc1        $f10, 0x124($s1)
    MEM_W(0X124, ctx->r17) = ctx->f10.u32l;
    // 0x8005B964: lwc1        $f0, 0x124($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X124);
    // 0x8005B968: nop

L_8005B96C:
    // 0x8005B96C: lwc1        $f5, 0x6F50($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6F50);
    // 0x8005B970: lwc1        $f4, 0x6F54($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6F54);
    // 0x8005B974: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x8005B978: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x8005B97C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005B980: lwc1        $f9, 0x6F58($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6F58);
    // 0x8005B984: lwc1        $f8, 0x6F5C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6F5C);
    // 0x8005B988: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005B98C: lwc1        $f19, 0x6F60($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, 0X6F60);
    // 0x8005B990: lwc1        $f18, 0x6F64($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6F64);
    // 0x8005B994: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x8005B998: nop

    // 0x8005B99C: div.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = DIV_D(ctx->f10.d, ctx->f18.d);
    // 0x8005B9A0: jal         0x800CA030
    // 0x8005B9A4: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x8005B9A4: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    after_3:
    // 0x8005B9A8: lb          $t6, 0x1D3($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X1D3);
    // 0x8005B9AC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8005B9B0: beq         $t6, $zero, L_8005B9D0
    if (ctx->r14 == 0) {
        // 0x8005B9B4: addiu       $v1, $sp, 0xF8
        ctx->r3 = ADD32(ctx->r29, 0XF8);
            goto L_8005B9D0;
    }
    // 0x8005B9B4: addiu       $v1, $sp, 0xF8
    ctx->r3 = ADD32(ctx->r29, 0XF8);
    // 0x8005B9B8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005B9BC: lwc1        $f9, 0x6F68($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6F68);
    // 0x8005B9C0: lwc1        $f8, 0x6F6C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6F6C);
    // 0x8005B9C4: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8005B9C8: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8005B9CC: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
L_8005B9D0:
    // 0x8005B9D0: lb          $t7, 0x1D6($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X1D6);
    // 0x8005B9D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005B9D8: bne         $t7, $at, L_8005BAD8
    if (ctx->r15 != ctx->r1) {
        // 0x8005B9DC: addiu       $a2, $sp, 0xE4
        ctx->r6 = ADD32(ctx->r29, 0XE4);
            goto L_8005BAD8;
    }
    // 0x8005B9DC: addiu       $a2, $sp, 0xE4
    ctx->r6 = ADD32(ctx->r29, 0XE4);
    // 0x8005B9E0: lh          $t8, 0x1BE($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X1BE);
    // 0x8005B9E4: lh          $t2, 0x1C2($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X1C2);
    // 0x8005B9E8: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x8005B9EC: andi        $t3, $t2, 0xFFFF
    ctx->r11 = ctx->r10 & 0XFFFF;
    // 0x8005B9F0: subu        $v0, $t9, $t3
    ctx->r2 = SUB32(ctx->r25, ctx->r11);
    // 0x8005B9F4: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8005B9F8: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8005B9FC: bne         $at, $zero, L_8005BA0C
    if (ctx->r1 != 0) {
        // 0x8005BA00: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8005BA0C;
    }
    // 0x8005BA00: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8005BA04: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8005BA08: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_8005BA0C:
    // 0x8005BA0C: slti        $at, $v0, -0x8000
    ctx->r1 = SIGNED(ctx->r2) < -0X8000 ? 1 : 0;
    // 0x8005BA10: beq         $at, $zero, L_8005BA1C
    if (ctx->r1 == 0) {
        // 0x8005BA14: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8005BA1C;
    }
    // 0x8005BA14: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8005BA18: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_8005BA1C:
    // 0x8005BA1C: bgez        $v0, L_8005BA28
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8005BA20: nop
    
            goto L_8005BA28;
    }
    // 0x8005BA20: nop

    // 0x8005BA24: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_8005BA28:
    // 0x8005BA28: addiu       $v0, $v0, -0xC8
    ctx->r2 = ADD32(ctx->r2, -0XC8);
    // 0x8005BA2C: bgez        $v0, L_8005BA38
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8005BA30: nop
    
            goto L_8005BA38;
    }
    // 0x8005BA30: nop

    // 0x8005BA34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005BA38:
    // 0x8005BA38: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x8005BA3C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005BA40: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8005BA44: lwc1        $f9, 0x6F70($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6F70);
    // 0x8005BA48: lwc1        $f8, 0x6F74($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6F74);
    // 0x8005BA4C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005BA50: nop

    // 0x8005BA54: div.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f8.d);
    // 0x8005BA58: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8005BA5C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8005BA60: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005BA64: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8005BA68: cvt.s.d     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f14.fl = CVT_S_D(ctx->f10.d);
    // 0x8005BA6C: sub.s       $f12, $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x8005BA70: swc1        $f14, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f14.u32l;
    // 0x8005BA74: cvt.d.s     $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f18.d = CVT_D_S(ctx->f12.fl);
    // 0x8005BA78: c.lt.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d < ctx->f4.d;
    // 0x8005BA7C: nop

    // 0x8005BA80: bc1f        L_8005BA90
    if (!c1cs) {
        // 0x8005BA84: nop
    
            goto L_8005BA90;
    }
    // 0x8005BA84: nop

    // 0x8005BA88: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8005BA8C: nop

L_8005BA90:
    // 0x8005BA90: lwc1        $f0, 0x2C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x8005BA94: neg.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
    // 0x8005BA98: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8005BA9C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8005BAA0: bc1f        L_8005BAB0
    if (!c1cs) {
        // 0x8005BAA4: nop
    
            goto L_8005BAB0;
    }
    // 0x8005BAA4: nop

    // 0x8005BAA8: b           L_8005BB08
    // 0x8005BAAC: swc1        $f2, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f2.u32l;
        goto L_8005BB08;
    // 0x8005BAAC: swc1        $f2, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f2.u32l;
L_8005BAB0:
    // 0x8005BAB0: sub.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8005BAB4: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8005BAB8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005BABC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8005BAC0: mul.d       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x8005BAC4: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x8005BAC8: add.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f4.d + ctx->f18.d;
    // 0x8005BACC: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8005BAD0: b           L_8005BB08
    // 0x8005BAD4: swc1        $f8, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f8.u32l;
        goto L_8005BB08;
    // 0x8005BAD4: swc1        $f8, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f8.u32l;
L_8005BAD8:
    // 0x8005BAD8: lwc1        $f0, 0x2C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x8005BADC: neg.s       $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = -ctx->f12.fl;
    // 0x8005BAE0: sub.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x8005BAE4: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x8005BAE8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8005BAEC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8005BAF0: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x8005BAF4: mul.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f6.d);
    // 0x8005BAF8: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x8005BAFC: add.d       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f10.d + ctx->f8.d;
    // 0x8005BB00: cvt.s.d     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f18.fl = CVT_S_D(ctx->f4.d);
    // 0x8005BB04: swc1        $f18, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f18.u32l;
L_8005BB08:
    // 0x8005BB08: lb          $a0, 0x192($s1)
    ctx->r4 = MEM_B(ctx->r17, 0X192);
    // 0x8005BB0C: addiu       $a3, $sp, 0xD0
    ctx->r7 = ADD32(ctx->r29, 0XD0);
    // 0x8005BB10: addiu       $a0, $a0, -0x2
    ctx->r4 = ADD32(ctx->r4, -0X2);
    // 0x8005BB14: bgez        $a0, L_8005BB28
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8005BB18: addiu       $t1, $sp, 0xB0
        ctx->r9 = ADD32(ctx->r29, 0XB0);
            goto L_8005BB28;
    }
    // 0x8005BB18: addiu       $t1, $sp, 0xB0
    ctx->r9 = ADD32(ctx->r29, 0XB0);
    // 0x8005BB1C: lw          $v0, 0x114($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X114);
    // 0x8005BB20: nop

    // 0x8005BB24: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
L_8005BB28:
    // 0x8005BB28: lw          $v0, 0x114($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X114);
    // 0x8005BB2C: addiu       $t0, $sp, 0x9C
    ctx->r8 = ADD32(ctx->r29, 0X9C);
    // 0x8005BB30: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8005BB34: bne         $at, $zero, L_8005BB40
    if (ctx->r1 != 0) {
        // 0x8005BB38: addiu       $s0, $sp, 0xB0
        ctx->r16 = ADD32(ctx->r29, 0XB0);
            goto L_8005BB40;
    }
    // 0x8005BB38: addiu       $s0, $sp, 0xB0
    ctx->r16 = ADD32(ctx->r29, 0XB0);
    // 0x8005BB3C: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
L_8005BB40:
    // 0x8005BB40: lbu         $a1, 0x1C8($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X1C8);
    // 0x8005BB44: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    // 0x8005BB48: sw          $t0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r8;
    // 0x8005BB4C: sw          $a3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r7;
    // 0x8005BB50: sw          $a2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r6;
    // 0x8005BB54: sw          $a0, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r4;
    // 0x8005BB58: jal         0x8001BA50
    // 0x8005BB5C: sw          $v1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r3;
    find_next_checkpoint_node(rdram, ctx);
        goto after_4;
    // 0x8005BB5C: sw          $v1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r3;
    after_4:
    // 0x8005BB60: lw          $v1, 0x70($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X70);
    // 0x8005BB64: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8005BB68: lw          $a0, 0x118($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X118);
    // 0x8005BB6C: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x8005BB70: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x8005BB74: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x8005BB78: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x8005BB7C: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x8005BB80: lwc1        $f10, 0x14($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8005BB84: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8005BB88: swc1        $f10, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f10.u32l;
    // 0x8005BB8C: lwc1        $f8, 0x18($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8005BB90: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8005BB94: swc1        $f8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f8.u32l;
    // 0x8005BB98: lb          $t4, 0x1CA($s1)
    ctx->r12 = MEM_B(ctx->r17, 0X1CA);
    // 0x8005BB9C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8005BBA0: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x8005BBA4: lb          $t6, 0x2E($t5)
    ctx->r14 = MEM_B(ctx->r13, 0X2E);
    // 0x8005BBA8: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8005BBAC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8005BBB0: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8005BBB4: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005BBB8: swc1        $f18, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f18.u32l;
    // 0x8005BBBC: lb          $t7, 0x1CA($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X1CA);
    // 0x8005BBC0: nop

    // 0x8005BBC4: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8005BBC8: lb          $t2, 0x32($t8)
    ctx->r10 = MEM_B(ctx->r24, 0X32);
    // 0x8005BBCC: nop

    // 0x8005BBD0: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x8005BBD4: nop

    // 0x8005BBD8: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8005BBDC: swc1        $f10, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->f10.u32l;
    // 0x8005BBE0: lb          $t9, 0x1CA($s1)
    ctx->r25 = MEM_B(ctx->r17, 0X1CA);
    // 0x8005BBE4: lwc1        $f8, 0x1C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8005BBE8: addu        $t3, $v0, $t9
    ctx->r11 = ADD32(ctx->r2, ctx->r25);
    // 0x8005BBEC: lb          $t4, 0x2E($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X2E);
    // 0x8005BBF0: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8005BBF4: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x8005BBF8: mul.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8005BBFC: lwc1        $f4, -0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, -0X4);
    // 0x8005BC00: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8005BC04: mul.s       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x8005BC08: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8005BC0C: swc1        $f6, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f6.u32l;
    // 0x8005BC10: lb          $t5, 0x1CA($s1)
    ctx->r13 = MEM_B(ctx->r17, 0X1CA);
    // 0x8005BC14: lwc1        $f18, 0x1C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8005BC18: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x8005BC1C: lb          $t7, 0x32($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X32);
    // 0x8005BC20: lwc1        $f6, -0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, -0X4);
    // 0x8005BC24: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8005BC28: nop

    // 0x8005BC2C: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8005BC30: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8005BC34: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8005BC38: swc1        $f10, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->f10.u32l;
    // 0x8005BC3C: lb          $t8, 0x1CA($s1)
    ctx->r24 = MEM_B(ctx->r17, 0X1CA);
    // 0x8005BC40: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8005BC44: addu        $t2, $v0, $t8
    ctx->r10 = ADD32(ctx->r2, ctx->r24);
    // 0x8005BC48: lb          $t9, 0x2E($t2)
    ctx->r25 = MEM_B(ctx->r10, 0X2E);
    // 0x8005BC4C: lwc1        $f18, 0x1C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8005BC50: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8005BC54: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8005BC58: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8005BC5C: lwc1        $f6, -0x4($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, -0X4);
    // 0x8005BC60: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8005BC64: mul.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8005BC68: add.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8005BC6C: swc1        $f10, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->f10.u32l;
    // 0x8005BC70: lw          $t3, 0x114($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X114);
    // 0x8005BC74: nop

    // 0x8005BC78: bne         $a0, $t3, L_8005BC84
    if (ctx->r4 != ctx->r11) {
        // 0x8005BC7C: nop
    
            goto L_8005BC84;
    }
    // 0x8005BC7C: nop

    // 0x8005BC80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8005BC84:
    // 0x8005BC84: bne         $t0, $s0, L_8005BB40
    if (ctx->r8 != ctx->r16) {
        // 0x8005BC88: addiu       $t1, $t1, 0x4
        ctx->r9 = ADD32(ctx->r9, 0X4);
            goto L_8005BB40;
    }
    // 0x8005BC88: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x8005BC8C: lwc1        $f8, 0x2C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x8005BC90: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8005BC94: swc1        $f8, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f8.u32l;
    // 0x8005BC98: lwc1        $f4, 0x84($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8005BC9C: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x8005BCA0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8005BCA4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8005BCA8: bc1f        L_8005BCB8
    if (!c1cs) {
        // 0x8005BCAC: nop
    
            goto L_8005BCB8;
    }
    // 0x8005BCAC: nop

    // 0x8005BCB0: neg.s       $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = -ctx->f4.fl;
    // 0x8005BCB4: swc1        $f18, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f18.u32l;
L_8005BCB8:
    // 0x8005BCB8: lwc1        $f8, 0xAC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XAC);
    // 0x8005BCBC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005BCC0: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x8005BCC4: c.eq.d      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.d == ctx->f6.d;
    // 0x8005BCC8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8005BCCC: bc1f        L_8005BCE0
    if (!c1cs) {
        // 0x8005BCD0: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8005BCE0;
    }
    // 0x8005BCD0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005BCD4: lwc1        $f4, 0x6F78($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6F78);
    // 0x8005BCD8: nop

    // 0x8005BCDC: swc1        $f4, 0xAC($s1)
    MEM_W(0XAC, ctx->r17) = ctx->f4.u32l;
L_8005BCE0:
    // 0x8005BCE0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8005BCE4: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x8005BCE8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8005BCEC:
    // 0x8005BCEC: lwc1        $f18, 0xAC($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XAC);
    // 0x8005BCF0: lwc1        $f8, 0x12C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x8005BCF4: lwc1        $f4, 0xA8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XA8);
    // 0x8005BCF8: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x8005BCFC: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x8005BD00: addiu       $a0, $sp, 0xF8
    ctx->r4 = ADD32(ctx->r29, 0XF8);
    // 0x8005BD04: addiu       $a3, $sp, 0x94
    ctx->r7 = ADD32(ctx->r29, 0X94);
    // 0x8005BD08: sub.d       $f8, $f20, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f20.d - ctx->f18.d;
    // 0x8005BD0C: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x8005BD10: add.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d + ctx->f6.d;
    // 0x8005BD14: cvt.s.d     $f22, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f22.fl = CVT_S_D(ctx->f10.d);
    // 0x8005BD18: cvt.d.s     $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f2.d = CVT_D_S(ctx->f22.fl);
    // 0x8005BD1C: c.le.d      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.d <= ctx->f2.d;
    // 0x8005BD20: nop

    // 0x8005BD24: bc1f        L_8005BD38
    if (!c1cs) {
        // 0x8005BD28: nop
    
            goto L_8005BD38;
    }
    // 0x8005BD28: nop

    // 0x8005BD2C: sub.d       $f4, $f2, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f20.d); 
    ctx->f4.d = ctx->f2.d - ctx->f20.d;
    // 0x8005BD30: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x8005BD34: cvt.s.d     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f22.fl = CVT_S_D(ctx->f4.d);
L_8005BD38:
    // 0x8005BD38: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8005BD3C: jal         0x80022670
    // 0x8005BD40: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    cubic_spline_interpolation(rdram, ctx);
        goto after_5;
    // 0x8005BD40: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_5:
    // 0x8005BD44: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8005BD48: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    // 0x8005BD4C: addiu       $a0, $sp, 0xE4
    ctx->r4 = ADD32(ctx->r29, 0XE4);
    // 0x8005BD50: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8005BD54: jal         0x80022670
    // 0x8005BD58: addiu       $a3, $sp, 0x90
    ctx->r7 = ADD32(ctx->r29, 0X90);
    cubic_spline_interpolation(rdram, ctx);
        goto after_6;
    // 0x8005BD58: addiu       $a3, $sp, 0x90
    ctx->r7 = ADD32(ctx->r29, 0X90);
    after_6:
    // 0x8005BD5C: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8005BD60: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x8005BD64: addiu       $a0, $sp, 0xD0
    ctx->r4 = ADD32(ctx->r29, 0XD0);
    // 0x8005BD68: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8005BD6C: jal         0x80022670
    // 0x8005BD70: addiu       $a3, $sp, 0x8C
    ctx->r7 = ADD32(ctx->r29, 0X8C);
    cubic_spline_interpolation(rdram, ctx);
        goto after_7;
    // 0x8005BD70: addiu       $a3, $sp, 0x8C
    ctx->r7 = ADD32(ctx->r29, 0X8C);
    after_7:
    // 0x8005BD74: lwc1        $f18, 0x68($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X68);
    // 0x8005BD78: lwc1        $f8, 0x6C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X6C);
    // 0x8005BD7C: lwc1        $f6, 0x70($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X70);
    // 0x8005BD80: sub.s       $f26, $f26, $f18
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f26.fl = ctx->f26.fl - ctx->f18.fl;
    // 0x8005BD84: sub.s       $f24, $f24, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f24.fl = ctx->f24.fl - ctx->f8.fl;
    // 0x8005BD88: bne         $s0, $zero, L_8005BE0C
    if (ctx->r16 != 0) {
        // 0x8005BD8C: sub.s       $f28, $f0, $f6
        CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f28.fl = ctx->f0.fl - ctx->f6.fl;
            goto L_8005BE0C;
    }
    // 0x8005BD8C: sub.s       $f28, $f0, $f6
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f28.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8005BD90: mul.s       $f10, $f26, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f26.fl, ctx->f26.fl);
    // 0x8005BD94: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8005BD98: mul.s       $f4, $f24, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x8005BD9C: nop

    // 0x8005BDA0: mul.s       $f8, $f28, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = MUL_S(ctx->f28.fl, ctx->f28.fl);
    // 0x8005BDA4: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8005BDA8: jal         0x800CA030
    // 0x8005BDAC: add.s       $f12, $f18, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_8;
    // 0x8005BDAC: add.s       $f12, $f18, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f8.fl;
    after_8:
    // 0x8005BDB0: lwc1        $f6, 0x12C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x8005BDB4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005BDB8: div.s       $f12, $f0, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8005BDBC: lwc1        $f18, 0x84($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8005BDC0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005BDC4: c.eq.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl == ctx->f12.fl;
    // 0x8005BDC8: nop

    // 0x8005BDCC: bc1t        L_8005BDEC
    if (c1cs) {
        // 0x8005BDD0: nop
    
            goto L_8005BDEC;
    }
    // 0x8005BDD0: nop

    // 0x8005BDD4: div.s       $f8, $f18, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = DIV_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8005BDD8: lwc1        $f4, 0xAC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XAC);
    // 0x8005BDDC: nop

    // 0x8005BDE0: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8005BDE4: b           L_8005BE0C
    // 0x8005BDE8: swc1        $f6, 0xAC($s1)
    MEM_W(0XAC, ctx->r17) = ctx->f6.u32l;
        goto L_8005BE0C;
    // 0x8005BDE8: swc1        $f6, 0xAC($s1)
    MEM_W(0XAC, ctx->r17) = ctx->f6.u32l;
L_8005BDEC:
    // 0x8005BDEC: lwc1        $f10, 0xAC($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XAC);
    // 0x8005BDF0: lwc1        $f5, 0x6F80($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6F80);
    // 0x8005BDF4: lwc1        $f4, 0x6F84($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6F84);
    // 0x8005BDF8: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8005BDFC: add.d       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f18.d + ctx->f4.d;
    // 0x8005BE00: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x8005BE04: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x8005BE08: swc1        $f6, 0xAC($s1)
    MEM_W(0XAC, ctx->r17) = ctx->f6.u32l;
L_8005BE0C:
    // 0x8005BE0C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8005BE10: slti        $at, $s0, 0x2
    ctx->r1 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x8005BE14: bne         $at, $zero, L_8005BCEC
    if (ctx->r1 != 0) {
        // 0x8005BE18: nop
    
            goto L_8005BCEC;
    }
    // 0x8005BE18: nop

    // 0x8005BE1C: lwc1        $f10, 0x68($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X68);
    // 0x8005BE20: lwc1        $f4, 0x6C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X6C);
    // 0x8005BE24: lwc1        $f6, 0x70($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X70);
    // 0x8005BE28: add.s       $f18, $f10, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f26.fl;
    // 0x8005BE2C: add.s       $f8, $f4, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f24.fl;
    // 0x8005BE30: swc1        $f18, 0x68($s1)
    MEM_W(0X68, ctx->r17) = ctx->f18.u32l;
    // 0x8005BE34: add.s       $f10, $f6, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f28.fl;
    // 0x8005BE38: swc1        $f8, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = ctx->f8.u32l;
    // 0x8005BE3C: swc1        $f10, 0x70($s1)
    MEM_W(0X70, ctx->r17) = ctx->f10.u32l;
    // 0x8005BE40: lwc1        $f4, 0xC($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8005BE44: lwc1        $f18, 0x68($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X68);
    // 0x8005BE48: lwc1        $f10, 0x70($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X70);
    // 0x8005BE4C: sub.s       $f26, $f18, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f26.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8005BE50: lwc1        $f18, 0x14($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8005BE54: mul.s       $f4, $f26, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f26.fl, ctx->f26.fl);
    // 0x8005BE58: lwc1        $f6, 0x10($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8005BE5C: lwc1        $f8, 0x6C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X6C);
    // 0x8005BE60: sub.s       $f28, $f10, $f18
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f28.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8005BE64: sub.s       $f24, $f8, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f24.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8005BE68: mul.s       $f8, $f28, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = MUL_S(ctx->f28.fl, ctx->f28.fl);
    // 0x8005BE6C: cvt.d.s     $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f2.d = CVT_D_S(ctx->f22.fl);
    // 0x8005BE70: swc1        $f2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
    // 0x8005BE74: swc1        $f3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f_odd[(3 - 1) * 2];
    // 0x8005BE78: jal         0x800CA030
    // 0x8005BE7C: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_9;
    // 0x8005BE7C: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    after_9:
    // 0x8005BE80: lwc1        $f6, 0x12C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x8005BE84: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005BE88: div.s       $f12, $f0, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8005BE8C: lwc1        $f17, 0x6F88($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, 0X6F88);
    // 0x8005BE90: lwc1        $f16, 0x6F8C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6F8C);
    // 0x8005BE94: lwc1        $f3, 0x58($sp)
    ctx->f_odd[(3 - 1) * 2] = MEM_W(ctx->r29, 0X58);
    // 0x8005BE98: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8005BE9C: nop

    // 0x8005BEA0: sub.d       $f18, $f20, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f2.d); 
    ctx->f18.d = ctx->f20.d - ctx->f2.d;
    // 0x8005BEA4: cvt.d.s     $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f14.d = CVT_D_S(ctx->f12.fl);
    // 0x8005BEA8: c.lt.d      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.d < ctx->f14.d;
    // 0x8005BEAC: swc1        $f12, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f12.u32l;
    // 0x8005BEB0: bc1f        L_8005BED4
    if (!c1cs) {
        // 0x8005BEB4: cvt.s.d     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
            goto L_8005BED4;
    }
    // 0x8005BEB4: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8005BEB8: nop

    // 0x8005BEBC: div.d       $f10, $f16, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = DIV_D(ctx->f16.d, ctx->f14.d);
    // 0x8005BEC0: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x8005BEC4: mul.s       $f26, $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f26.fl = MUL_S(ctx->f26.fl, ctx->f0.fl);
    // 0x8005BEC8: nop

    // 0x8005BECC: mul.s       $f28, $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f28.fl = MUL_S(ctx->f28.fl, ctx->f0.fl);
    // 0x8005BED0: nop

L_8005BED4:
    // 0x8005BED4: beq         $s2, $zero, L_8005BF68
    if (ctx->r18 == 0) {
        // 0x8005BED8: swc1        $f4, 0xA8($s1)
        MEM_W(0XA8, ctx->r17) = ctx->f4.u32l;
            goto L_8005BF68;
    }
    // 0x8005BED8: swc1        $f4, 0xA8($s1)
    MEM_W(0XA8, ctx->r17) = ctx->f4.u32l;
    // 0x8005BEDC: lb          $t4, 0x192($s1)
    ctx->r12 = MEM_B(ctx->r17, 0X192);
    // 0x8005BEE0: nop

    // 0x8005BEE4: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8005BEE8: sb          $t5, 0x192($s1)
    MEM_B(0X192, ctx->r17) = ctx->r13;
    // 0x8005BEEC: lw          $t7, 0x114($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X114);
    // 0x8005BEF0: lb          $t6, 0x192($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X192);
    // 0x8005BEF4: nop

    // 0x8005BEF8: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8005BEFC: bne         $at, $zero, L_8005BF30
    if (ctx->r1 != 0) {
        // 0x8005BF00: lw          $t9, 0x78($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X78);
            goto L_8005BF30;
    }
    // 0x8005BF00: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x8005BF04: lh          $t8, 0x190($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X190);
    // 0x8005BF08: sb          $zero, 0x192($s1)
    MEM_B(0X192, ctx->r17) = 0;
    // 0x8005BF0C: blez        $t8, L_8005BF30
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8005BF10: lw          $t9, 0x78($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X78);
            goto L_8005BF30;
    }
    // 0x8005BF10: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x8005BF14: lb          $v0, 0x193($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X193);
    // 0x8005BF18: nop

    // 0x8005BF1C: slti        $at, $v0, 0x78
    ctx->r1 = SIGNED(ctx->r2) < 0X78 ? 1 : 0;
    // 0x8005BF20: beq         $at, $zero, L_8005BF2C
    if (ctx->r1 == 0) {
        // 0x8005BF24: addiu       $t2, $v0, 0x1
        ctx->r10 = ADD32(ctx->r2, 0X1);
            goto L_8005BF2C;
    }
    // 0x8005BF24: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x8005BF28: sb          $t2, 0x193($s1)
    MEM_B(0X193, ctx->r17) = ctx->r10;
L_8005BF2C:
    // 0x8005BF2C: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
L_8005BF30:
    // 0x8005BF30: lw          $t5, 0x114($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X114);
    // 0x8005BF34: lb          $t3, 0x4B($t9)
    ctx->r11 = MEM_B(ctx->r25, 0X4B);
    // 0x8005BF38: lh          $v0, 0x190($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X190);
    // 0x8005BF3C: addiu       $t4, $t3, 0x3
    ctx->r12 = ADD32(ctx->r11, 0X3);
    // 0x8005BF40: multu       $t4, $t5
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005BF44: addiu       $t8, $zero, 0x2710
    ctx->r24 = ADD32(0, 0X2710);
    // 0x8005BF48: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x8005BF4C: mflo        $t6
    ctx->r14 = lo;
    // 0x8005BF50: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8005BF54: beq         $at, $zero, L_8005BF60
    if (ctx->r1 == 0) {
        // 0x8005BF58: nop
    
            goto L_8005BF60;
    }
    // 0x8005BF58: nop

    // 0x8005BF5C: sh          $t7, 0x190($s1)
    MEM_H(0X190, ctx->r17) = ctx->r15;
L_8005BF60:
    // 0x8005BF60: b           L_8005BFA8
    // 0x8005BF64: sh          $t8, 0x1A8($s1)
    MEM_H(0X1A8, ctx->r17) = ctx->r24;
        goto L_8005BFA8;
    // 0x8005BF64: sh          $t8, 0x1A8($s1)
    MEM_H(0X1A8, ctx->r17) = ctx->r24;
L_8005BF68:
    // 0x8005BF68: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8005BF6C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8005BF70: lwc1        $f8, 0xA8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XA8);
    // 0x8005BF74: nop

    // 0x8005BF78: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8005BF7C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8005BF80: nop

    // 0x8005BF84: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x8005BF88: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005BF8C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005BF90: nop

    // 0x8005BF94: cvt.w.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8005BF98: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x8005BF9C: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8005BFA0: sh          $t9, 0x1A8($s1)
    MEM_H(0X1A8, ctx->r17) = ctx->r25;
    // 0x8005BFA4: nop

L_8005BFA8:
    // 0x8005BFA8: lb          $v0, 0x1D3($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X1D3);
    // 0x8005BFAC: lw          $t3, 0x128($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X128);
    // 0x8005BFB0: blez        $v0, L_8005BFC0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8005BFB4: subu        $t4, $v0, $t3
        ctx->r12 = SUB32(ctx->r2, ctx->r11);
            goto L_8005BFC0;
    }
    // 0x8005BFB4: subu        $t4, $v0, $t3
    ctx->r12 = SUB32(ctx->r2, ctx->r11);
    // 0x8005BFB8: b           L_8005BFC4
    // 0x8005BFBC: sb          $t4, 0x1D3($s1)
    MEM_B(0X1D3, ctx->r17) = ctx->r12;
        goto L_8005BFC4;
    // 0x8005BFBC: sb          $t4, 0x1D3($s1)
    MEM_B(0X1D3, ctx->r17) = ctx->r12;
L_8005BFC0:
    // 0x8005BFC0: sb          $zero, 0x1D3($s1)
    MEM_B(0X1D3, ctx->r17) = 0;
L_8005BFC4:
    // 0x8005BFC4: lwc1        $f4, 0xB8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x8005BFC8: lwc1        $f8, 0xB4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x8005BFCC: nop

    // 0x8005BFD0: sub.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8005BFD4: mul.s       $f10, $f6, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x8005BFD8: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8005BFDC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8005BFE0: nop

    // 0x8005BFE4: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x8005BFE8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005BFEC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005BFF0: nop

    // 0x8005BFF4: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8005BFF8: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x8005BFFC: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8005C000: sh          $t6, 0x1BA($s1)
    MEM_H(0X1BA, ctx->r17) = ctx->r14;
    // 0x8005C004: lwc1        $f10, 0xA0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8005C008: lwc1        $f6, 0xA4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x8005C00C: nop

    // 0x8005C010: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8005C014: mul.s       $f18, $f8, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x8005C018: add.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x8005C01C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8005C020: nop

    // 0x8005C024: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8005C028: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005C02C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005C030: nop

    // 0x8005C034: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8005C038: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x8005C03C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8005C040: sh          $t8, 0x1BC($s1)
    MEM_H(0X1BC, ctx->r17) = ctx->r24;
    // 0x8005C044: lwc1        $f8, 0x94($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8005C048: lwc1        $f10, 0x8C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8005C04C: mul.s       $f18, $f8, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8005C050: nop

    // 0x8005C054: mul.s       $f4, $f10, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x8005C058: jal         0x800CA030
    // 0x8005C05C: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_10;
    // 0x8005C05C: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_10:
    // 0x8005C060: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8005C064: lwc1        $f12, 0x94($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8005C068: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x8005C06C: lwc1        $f14, 0x8C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8005C070: bc1t        L_8005C0C8
    if (c1cs) {
        // 0x8005C074: nop
    
            goto L_8005C0C8;
    }
    // 0x8005C074: nop

    // 0x8005C078: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8005C07C: div.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8005C080: nop

    // 0x8005C084: div.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8005C088: swc1        $f12, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f12.u32l;
    // 0x8005C08C: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8005C090: swc1        $f14, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f14.u32l;
    // 0x8005C094: jal         0x80070990
    // 0x8005C098: swc1        $f10, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f10.u32l;
    arctan2_f(rdram, ctx);
        goto after_11;
    // 0x8005C098: swc1        $f10, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f10.u32l;
    after_11:
    // 0x8005C09C: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x8005C0A0: addu        $t2, $v0, $at
    ctx->r10 = ADD32(ctx->r2, ctx->r1);
    // 0x8005C0A4: sh          $t2, 0x1A0($s1)
    MEM_H(0X1A0, ctx->r17) = ctx->r10;
    // 0x8005C0A8: lh          $t9, 0x1A0($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X1A0);
    // 0x8005C0AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005C0B0: sh          $t9, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r25;
    // 0x8005C0B4: lwc1        $f12, 0x90($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8005C0B8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8005C0BC: jal         0x80070990
    // 0x8005C0C0: nop

    arctan2_f(rdram, ctx);
        goto after_12;
    // 0x8005C0C0: nop

    after_12:
    // 0x8005C0C4: sh          $v0, 0x2($s3)
    MEM_H(0X2, ctx->r19) = ctx->r2;
L_8005C0C8:
    // 0x8005C0C8: lh          $t3, 0x1BE($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X1BE);
    // 0x8005C0CC: lh          $t4, 0x1C0($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X1C0);
    // 0x8005C0D0: lh          $t5, 0x1A0($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X1A0);
    // 0x8005C0D4: sh          $t3, 0x1C2($s1)
    MEM_H(0X1C2, ctx->r17) = ctx->r11;
    // 0x8005C0D8: sh          $t4, 0x1C4($s1)
    MEM_H(0X1C4, ctx->r17) = ctx->r12;
    // 0x8005C0DC: sh          $t5, 0x1BE($s1)
    MEM_H(0X1BE, ctx->r17) = ctx->r13;
    // 0x8005C0E0: lh          $t6, 0x2($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X2);
    // 0x8005C0E4: mfc1        $a1, $f26
    ctx->r5 = (int32_t)ctx->f26.u32l;
    // 0x8005C0E8: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x8005C0EC: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x8005C0F0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8005C0F4: jal         0x80011570
    // 0x8005C0F8: sh          $t6, 0x1C0($s1)
    MEM_H(0X1C0, ctx->r17) = ctx->r14;
    move_object(rdram, ctx);
        goto after_13;
    // 0x8005C0F8: sh          $t6, 0x1C0($s1)
    MEM_H(0X1C0, ctx->r17) = ctx->r14;
    after_13:
    // 0x8005C0FC: beq         $v0, $zero, L_8005C258
    if (ctx->r2 == 0) {
        // 0x8005C100: nop
    
            goto L_8005C258;
    }
    // 0x8005C100: nop

    // 0x8005C104: jal         0x8002C804
    // 0x8005C108: nop

    get_current_level_model(rdram, ctx);
        goto after_14;
    // 0x8005C108: nop

    after_14:
    // 0x8005C10C: lwc1        $f18, 0xC($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8005C110: lwc1        $f6, 0x10($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8005C114: lwc1        $f10, 0x14($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8005C118: add.s       $f4, $f18, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f26.fl;
    // 0x8005C11C: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8005C120: add.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f24.fl;
    // 0x8005C124: swc1        $f4, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->f4.u32l;
    // 0x8005C128: add.s       $f18, $f10, $f28
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f28.fl;
    // 0x8005C12C: swc1        $f8, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f8.u32l;
    // 0x8005C130: swc1        $f18, 0x14($s3)
    MEM_W(0X14, ctx->r19) = ctx->f18.u32l;
    // 0x8005C134: lh          $t7, 0x3E($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X3E);
    // 0x8005C138: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8005C13C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8005C140: lwc1        $f0, 0xC($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8005C144: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005C148: add.s       $f22, $f6, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x8005C14C: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x8005C150: nop

    // 0x8005C154: bc1f        L_8005C168
    if (!c1cs) {
        // 0x8005C158: nop
    
            goto L_8005C168;
    }
    // 0x8005C158: nop

    // 0x8005C15C: swc1        $f22, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->f22.u32l;
    // 0x8005C160: lwc1        $f0, 0xC($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8005C164: nop

L_8005C168:
    // 0x8005C168: lh          $t8, 0x3C($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X3C);
    // 0x8005C16C: nop

    // 0x8005C170: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8005C174: nop

    // 0x8005C178: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8005C17C: sub.s       $f22, $f10, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x8005C180: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x8005C184: nop

    // 0x8005C188: bc1f        L_8005C194
    if (!c1cs) {
        // 0x8005C18C: nop
    
            goto L_8005C194;
    }
    // 0x8005C18C: nop

    // 0x8005C190: swc1        $f22, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->f22.u32l;
L_8005C194:
    // 0x8005C194: lh          $t2, 0x42($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X42);
    // 0x8005C198: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005C19C: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8005C1A0: lwc1        $f6, 0x6F90($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6F90);
    // 0x8005C1A4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8005C1A8: lwc1        $f0, 0x10($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8005C1AC: add.s       $f22, $f4, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8005C1B0: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x8005C1B4: nop

    // 0x8005C1B8: bc1f        L_8005C1CC
    if (!c1cs) {
        // 0x8005C1BC: nop
    
            goto L_8005C1CC;
    }
    // 0x8005C1BC: nop

    // 0x8005C1C0: swc1        $f22, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f22.u32l;
    // 0x8005C1C4: lwc1        $f0, 0x10($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8005C1C8: nop

L_8005C1CC:
    // 0x8005C1CC: lh          $t9, 0x40($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X40);
    // 0x8005C1D0: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8005C1D4: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8005C1D8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8005C1DC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8005C1E0: sub.s       $f22, $f10, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f22.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8005C1E4: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x8005C1E8: nop

    // 0x8005C1EC: bc1f        L_8005C1F8
    if (!c1cs) {
        // 0x8005C1F0: nop
    
            goto L_8005C1F8;
    }
    // 0x8005C1F0: nop

    // 0x8005C1F4: swc1        $f22, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f22.u32l;
L_8005C1F8:
    // 0x8005C1F8: lh          $t3, 0x46($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X46);
    // 0x8005C1FC: lwc1        $f0, 0x14($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8005C200: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x8005C204: nop

    // 0x8005C208: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005C20C: add.s       $f22, $f6, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x8005C210: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x8005C214: nop

    // 0x8005C218: bc1f        L_8005C22C
    if (!c1cs) {
        // 0x8005C21C: nop
    
            goto L_8005C22C;
    }
    // 0x8005C21C: nop

    // 0x8005C220: swc1        $f22, 0x14($s3)
    MEM_W(0X14, ctx->r19) = ctx->f22.u32l;
    // 0x8005C224: lwc1        $f0, 0x14($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8005C228: nop

L_8005C22C:
    // 0x8005C22C: lh          $t4, 0x44($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X44);
    // 0x8005C230: nop

    // 0x8005C234: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x8005C238: nop

    // 0x8005C23C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8005C240: sub.s       $f22, $f10, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x8005C244: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x8005C248: nop

    // 0x8005C24C: bc1f        L_8005C258
    if (!c1cs) {
        // 0x8005C250: nop
    
            goto L_8005C258;
    }
    // 0x8005C250: nop

    // 0x8005C254: swc1        $f22, 0x14($s3)
    MEM_W(0X14, ctx->r19) = ctx->f22.u32l;
L_8005C258:
    // 0x8005C258: lwc1        $f18, 0x88($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8005C25C: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x8005C260: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8005C264: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8005C268: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8005C26C: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x8005C270: lwc1        $f8, 0x12C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x8005C274: bc1f        L_8005C2A8
    if (!c1cs) {
        // 0x8005C278: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8005C2A8;
    }
    // 0x8005C278: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8005C27C: nop

    // 0x8005C280: div.s       $f10, $f26, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f26.fl, ctx->f8.fl);
    // 0x8005C284: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8005C288: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8005C28C: nop

    // 0x8005C290: swc1        $f18, 0x20($s3)
    MEM_W(0X20, ctx->r19) = ctx->f18.u32l;
    // 0x8005C294: swc1        $f10, 0x1C($s3)
    MEM_W(0X1C, ctx->r19) = ctx->f10.u32l;
    // 0x8005C298: lwc1        $f4, 0x12C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x8005C29C: nop

    // 0x8005C2A0: div.s       $f6, $f28, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f28.fl, ctx->f4.fl);
    // 0x8005C2A4: swc1        $f6, 0x24($s3)
    MEM_W(0X24, ctx->r19) = ctx->f6.u32l;
L_8005C2A8:
    // 0x8005C2A8: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x8005C2AC: jal         0x80042D60
    // 0x8005C2B0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80042D20(rdram, ctx);
        goto after_15;
    // 0x8005C2B0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_15:
    // 0x8005C2B4: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x8005C2B8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8005C2BC: jal         0x80055F00
    // 0x8005C2C0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    handle_racer_items(rdram, ctx);
        goto after_16;
    // 0x8005C2C0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_16:
    // 0x8005C2C4: sb          $zero, 0x1E5($s1)
    MEM_B(0X1E5, ctx->r17) = 0;
    // 0x8005C2C8: lwc1        $f8, 0xC($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8005C2CC: lw          $t5, 0x4C($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X4C);
    // 0x8005C2D0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005C2D4: swc1        $f8, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f8.u32l;
    // 0x8005C2D8: lwc1        $f10, 0x10($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8005C2DC: lw          $t6, 0x4C($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X4C);
    // 0x8005C2E0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8005C2E4: swc1        $f10, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f10.u32l;
    // 0x8005C2E8: lwc1        $f18, 0x14($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8005C2EC: lw          $t7, 0x4C($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X4C);
    // 0x8005C2F0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8005C2F4: swc1        $f18, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f18.u32l;
    // 0x8005C2F8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005C2FC: sb          $zero, 0x1E6($s1)
    MEM_B(0X1E6, ctx->r17) = 0;
    // 0x8005C300: sh          $zero, 0x1A2($s1)
    MEM_H(0X1A2, ctx->r17) = 0;
    // 0x8005C304: sh          $zero, 0x1A6($s1)
    MEM_H(0X1A6, ctx->r17) = 0;
    // 0x8005C308: sb          $zero, 0x1D2($s1)
    MEM_B(0X1D2, ctx->r17) = 0;
    // 0x8005C30C: swc1        $f4, 0x78($s1)
    MEM_W(0X78, ctx->r17) = ctx->f4.u32l;
    // 0x8005C310: swc1        $f6, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = ctx->f6.u32l;
    // 0x8005C314: swc1        $f8, 0x80($s1)
    MEM_W(0X80, ctx->r17) = ctx->f8.u32l;
    // 0x8005C318: lwc1        $f18, 0xC($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8005C31C: swc1        $f10, 0x20($s3)
    MEM_W(0X20, ctx->r19) = ctx->f10.u32l;
    // 0x8005C320: swc1        $f18, 0xD8($s1)
    MEM_W(0XD8, ctx->r17) = ctx->f18.u32l;
    // 0x8005C324: lwc1        $f4, 0x10($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8005C328: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8005C32C: swc1        $f4, 0xDC($s1)
    MEM_W(0XDC, ctx->r17) = ctx->f4.u32l;
    // 0x8005C330: lwc1        $f6, 0x14($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8005C334: nop

    // 0x8005C338: swc1        $f6, 0xE0($s1)
    MEM_W(0XE0, ctx->r17) = ctx->f6.u32l;
    // 0x8005C33C: lwc1        $f8, 0xC($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8005C340: nop

    // 0x8005C344: swc1        $f8, 0xE4($s1)
    MEM_W(0XE4, ctx->r17) = ctx->f8.u32l;
    // 0x8005C348: lwc1        $f10, 0x10($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8005C34C: nop

    // 0x8005C350: swc1        $f10, 0xE8($s1)
    MEM_W(0XE8, ctx->r17) = ctx->f10.u32l;
    // 0x8005C354: lwc1        $f18, 0x14($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8005C358: nop

    // 0x8005C35C: swc1        $f18, 0xEC($s1)
    MEM_W(0XEC, ctx->r17) = ctx->f18.u32l;
    // 0x8005C360: lwc1        $f4, 0xC($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8005C364: nop

    // 0x8005C368: swc1        $f4, 0xF0($s1)
    MEM_W(0XF0, ctx->r17) = ctx->f4.u32l;
    // 0x8005C36C: lwc1        $f6, 0x10($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8005C370: nop

    // 0x8005C374: swc1        $f6, 0xF4($s1)
    MEM_W(0XF4, ctx->r17) = ctx->f6.u32l;
    // 0x8005C378: lwc1        $f8, 0x14($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8005C37C: nop

    // 0x8005C380: swc1        $f8, 0xF8($s1)
    MEM_W(0XF8, ctx->r17) = ctx->f8.u32l;
    // 0x8005C384: lwc1        $f10, 0xC($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8005C388: nop

    // 0x8005C38C: swc1        $f10, 0xFC($s1)
    MEM_W(0XFC, ctx->r17) = ctx->f10.u32l;
    // 0x8005C390: lwc1        $f18, 0x10($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8005C394: nop

    // 0x8005C398: swc1        $f18, 0x100($s1)
    MEM_W(0X100, ctx->r17) = ctx->f18.u32l;
    // 0x8005C39C: lwc1        $f4, 0x14($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8005C3A0: nop

    // 0x8005C3A4: swc1        $f4, 0x104($s1)
    MEM_W(0X104, ctx->r17) = ctx->f4.u32l;
    // 0x8005C3A8: sw          $zero, 0x74($s3)
    MEM_W(0X74, ctx->r19) = 0;
    // 0x8005C3AC: lw          $a1, 0x128($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X128);
    // 0x8005C3B0: jal         0x800AFC74
    // 0x8005C3B4: nop

    update_vehicle_particles(rdram, ctx);
        goto after_17;
    // 0x8005C3B4: nop

    after_17:
L_8005C3B8:
    // 0x8005C3B8: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8005C3BC: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x8005C3C0: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8005C3C4: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8005C3C8: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8005C3CC: lwc1        $f25, 0x20($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8005C3D0: lwc1        $f24, 0x24($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8005C3D4: lwc1        $f27, 0x28($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8005C3D8: lwc1        $f26, 0x2C($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8005C3DC: lwc1        $f29, 0x30($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x8005C3E0: lwc1        $f28, 0x34($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8005C3E4: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x8005C3E8: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x8005C3EC: lw          $s2, 0x44($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X44);
    // 0x8005C3F0: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
    // 0x8005C3F4: jr          $ra
    // 0x8005C3F8: addiu       $sp, $sp, 0x120
    ctx->r29 = ADD32(ctx->r29, 0X120);
    return;
    // 0x8005C3F8: addiu       $sp, $sp, 0x120
    ctx->r29 = ADD32(ctx->r29, 0X120);
;}
RECOMP_FUNC void drm_vehicle_traction(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C3FC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005C400: lwc1        $f4, 0x6F94($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6F94);
    // 0x8005C404: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005C408: jr          $ra
    // 0x8005C40C: swc1        $f4, -0x2EF4($at)
    MEM_W(-0X2EF4, ctx->r1) = ctx->f4.u32l;
    return;
    // 0x8005C40C: swc1        $f4, -0x2EF4($at)
    MEM_W(-0X2EF4, ctx->r1) = ctx->f4.u32l;
;}
RECOMP_FUNC void racer_update_progress(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C410: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005C414: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005C418: jal         0x8001BA98
    // 0x8005C41C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    get_checkpoint_count(rdram, ctx);
        goto after_0;
    // 0x8005C41C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8005C420: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8005C424: nop

    // 0x8005C428: lb          $t6, 0x192($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X192);
    // 0x8005C42C: nop

    // 0x8005C430: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8005C434: sb          $t7, 0x192($a0)
    MEM_B(0X192, ctx->r4) = ctx->r15;
    // 0x8005C438: lb          $v1, 0x192($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X192);
    // 0x8005C43C: nop

    // 0x8005C440: bgez        $v1, L_8005C460
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8005C444: nop
    
            goto L_8005C460;
    }
    // 0x8005C444: nop

    // 0x8005C448: lb          $a1, 0x193($a0)
    ctx->r5 = MEM_B(ctx->r4, 0X193);
    // 0x8005C44C: addu        $t8, $v1, $v0
    ctx->r24 = ADD32(ctx->r3, ctx->r2);
    // 0x8005C450: blez        $a1, L_8005C460
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8005C454: sb          $t8, 0x192($a0)
        MEM_B(0X192, ctx->r4) = ctx->r24;
            goto L_8005C460;
    }
    // 0x8005C454: sb          $t8, 0x192($a0)
    MEM_B(0X192, ctx->r4) = ctx->r24;
    // 0x8005C458: addiu       $t9, $a1, -0x1
    ctx->r25 = ADD32(ctx->r5, -0X1);
    // 0x8005C45C: sb          $t9, 0x193($a0)
    MEM_B(0X193, ctx->r4) = ctx->r25;
L_8005C460:
    // 0x8005C460: lh          $v0, 0x190($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X190);
    // 0x8005C464: nop

    // 0x8005C468: slti        $at, $v0, -0x7CFF
    ctx->r1 = SIGNED(ctx->r2) < -0X7CFF ? 1 : 0;
    // 0x8005C46C: bne         $at, $zero, L_8005C478
    if (ctx->r1 != 0) {
        // 0x8005C470: addiu       $t0, $v0, -0x1
        ctx->r8 = ADD32(ctx->r2, -0X1);
            goto L_8005C478;
    }
    // 0x8005C470: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x8005C474: sh          $t0, 0x190($a0)
    MEM_H(0X190, ctx->r4) = ctx->r8;
L_8005C478:
    // 0x8005C478: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005C47C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005C480: jr          $ra
    // 0x8005C484: nop

    return;
    // 0x8005C484: nop

    // 0x8005C488: nop

    // 0x8005C48C: nop

;}
RECOMP_FUNC void racer_special_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C490: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005C494: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005C498: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x8005C49C: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x8005C4A0: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x8005C4A4: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x8005C4A8: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x8005C4AC: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
    // 0x8005C4B0: lw          $t0, 0x4C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4C);
    // 0x8005C4B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005C4B8: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x8005C4BC: lw          $t1, 0x4C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4C);
    // 0x8005C4C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005C4C4: sb          $zero, 0x12($t1)
    MEM_B(0X12, ctx->r9) = 0;
    // 0x8005C4C8: swc1        $f4, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f4.u32l;
    // 0x8005C4CC: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8005C4D0: nop

    // 0x8005C4D4: swc1        $f6, -0x24C0($at)
    MEM_W(-0X24C0, ctx->r1) = ctx->f6.u32l;
    // 0x8005C4D8: lw          $t2, 0x118($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X118);
    // 0x8005C4DC: nop

    // 0x8005C4E0: beq         $t2, $zero, L_8005C4F4
    if (ctx->r10 == 0) {
        // 0x8005C4E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005C4F4;
    }
    // 0x8005C4E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005C4E8: jal         0x80006AC8
    // 0x8005C4EC: nop

    racer_sound_free(rdram, ctx);
        goto after_0;
    // 0x8005C4EC: nop

    after_0:
    // 0x8005C4F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005C4F4:
    // 0x8005C4F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005C4F8: sb          $zero, -0x24BC($at)
    MEM_B(-0X24BC, ctx->r1) = 0;
    // 0x8005C4FC: jr          $ra
    // 0x8005C500: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8005C500: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void update_tricky(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C504: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8005C508: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8005C50C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8005C510: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8005C514: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8005C518: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005C51C: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x8005C520: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8005C524: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8005C528: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8005C52C: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8005C530: jal         0x8005CC18
    // 0x8005C534: addiu       $a0, $a0, -0x2CB0
    ctx->r4 = ADD32(ctx->r4, -0X2CB0);
    set_boss_voice_clip_offset(rdram, ctx);
        goto after_0;
    // 0x8005C534: addiu       $a0, $a0, -0x2CB0
    ctx->r4 = ADD32(ctx->r4, -0X2CB0);
    after_0:
    // 0x8005C538: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
    // 0x8005C53C: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x8005C540: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8005C544: addiu       $v1, $zero, -0x11
    ctx->r3 = ADD32(0, -0X11);
    // 0x8005C548: and         $t7, $t6, $v1
    ctx->r15 = ctx->r14 & ctx->r3;
    // 0x8005C54C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8005C550: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8005C554: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005C558: and         $t9, $t8, $v1
    ctx->r25 = ctx->r24 & ctx->r3;
    // 0x8005C55C: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8005C560: lb          $t2, 0x3B($s1)
    ctx->r10 = MEM_B(ctx->r17, 0X3B);
    // 0x8005C564: nop

    // 0x8005C568: sh          $t2, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r10;
    // 0x8005C56C: lh          $t3, 0x18($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X18);
    // 0x8005C570: nop

    // 0x8005C574: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x8005C578: lh          $t4, 0x16A($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X16A);
    // 0x8005C57C: nop

    // 0x8005C580: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x8005C584: lb          $t5, 0x1D8($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1D8);
    // 0x8005C588: nop

    // 0x8005C58C: bne         $t5, $at, L_8005C5B0
    if (ctx->r13 != ctx->r1) {
        // 0x8005C590: lw          $t1, 0x70($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X70);
            goto L_8005C5B0;
    }
    // 0x8005C590: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x8005C594: jal         0x80021434
    // 0x8005C598: addiu       $a0, $zero, 0x82
    ctx->r4 = ADD32(0, 0X82);
    func_80021400(rdram, ctx);
        goto after_1;
    // 0x8005C598: addiu       $a0, $zero, 0x82
    ctx->r4 = ADD32(0, 0X82);
    after_1:
    // 0x8005C59C: lb          $t6, 0x1D8($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D8);
    // 0x8005C5A0: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x8005C5A4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8005C5A8: sb          $t7, 0x1D8($s0)
    MEM_B(0X1D8, ctx->r16) = ctx->r15;
    // 0x8005C5AC: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
L_8005C5B0:
    // 0x8005C5B0: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x8005C5B4: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x8005C5B8: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8005C5BC: bne         $t0, $t8, L_8005C634
    if (ctx->r8 != ctx->r24) {
        // 0x8005C5C0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8005C634;
    }
    // 0x8005C5C0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8005C5C4: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8005C5C8: beq         $v0, $at, L_8005C634
    if (ctx->r2 == ctx->r1) {
        // 0x8005C5CC: addiu       $t9, $v0, -0xF
        ctx->r25 = ADD32(ctx->r2, -0XF);
            goto L_8005C634;
    }
    // 0x8005C5CC: addiu       $t9, $v0, -0xF
    ctx->r25 = ADD32(ctx->r2, -0XF);
    // 0x8005C5D0: bgez        $t9, L_8005C62C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8005C5D4: sw          $t9, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r25;
            goto L_8005C62C;
    }
    // 0x8005C5D4: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8005C5D8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8005C5DC: lb          $t3, -0x24B4($t3)
    ctx->r11 = MEM_B(ctx->r11, -0X24B4);
    // 0x8005C5E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005C5E4: bne         $t3, $zero, L_8005C60C
    if (ctx->r11 != 0) {
        // 0x8005C5E8: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_8005C60C;
    }
    // 0x8005C5E8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8005C5EC: jal         0x8005CCA4
    // 0x8005C5F0: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    play_random_boss_sound(rdram, ctx);
        goto after_2;
    // 0x8005C5F0: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    after_2:
    // 0x8005C5F4: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x8005C5F8: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x8005C5FC: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x8005C600: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x8005C604: sb          $t4, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r12;
    // 0x8005C608: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
L_8005C60C:
    // 0x8005C60C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005C610: sb          $t5, -0x24B4($at)
    MEM_B(-0X24B4, ctx->r1) = ctx->r13;
    // 0x8005C614: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x8005C618: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8005C61C: nop

    // 0x8005C620: ori         $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 | 0X8000;
    // 0x8005C624: b           L_8005C634
    // 0x8005C628: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
        goto L_8005C634;
    // 0x8005C628: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
L_8005C62C:
    // 0x8005C62C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005C630: sb          $zero, -0x24B4($at)
    MEM_B(-0X24B4, ctx->r1) = 0;
L_8005C634:
    // 0x8005C634: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8005C638: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x8005C63C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8005C640: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8005C644: jal         0x8004F834
    // 0x8005C648: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    func_8004F7F4(rdram, ctx);
        goto after_3;
    // 0x8005C648: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    after_3:
    // 0x8005C64C: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x8005C650: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x8005C654: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005C658: sw          $v1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r3;
    // 0x8005C65C: swc1        $f16, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f16.u32l;
    // 0x8005C660: lh          $t8, 0x52($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X52);
    // 0x8005C664: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8005C668: sh          $t8, 0x16A($s0)
    MEM_H(0X16A, ctx->r16) = ctx->r24;
    // 0x8005C66C: lh          $t9, 0x56($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X56);
    // 0x8005C670: nop

    // 0x8005C674: sb          $t9, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r25;
    // 0x8005C678: lh          $t2, 0x54($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X54);
    // 0x8005C67C: nop

    // 0x8005C680: sh          $t2, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r10;
    // 0x8005C684: lb          $t3, 0x187($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X187);
    // 0x8005C688: nop

    // 0x8005C68C: beq         $t3, $zero, L_8005C718
    if (ctx->r11 == 0) {
        // 0x8005C690: nop
    
            goto L_8005C718;
    }
    // 0x8005C690: nop

    // 0x8005C694: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005C698: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8005C69C: beq         $a1, $v1, L_8005C718
    if (ctx->r5 == ctx->r3) {
        // 0x8005C6A0: lui         $at, 0x401E
        ctx->r1 = S32(0X401E << 16);
            goto L_8005C718;
    }
    // 0x8005C6A0: lui         $at, 0x401E
    ctx->r1 = S32(0X401E << 16);
    // 0x8005C6A4: sb          $v1, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r3;
    // 0x8005C6A8: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8005C6AC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8005C6B0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8005C6B4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005C6B8: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x8005C6BC: sb          $a1, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r5;
    // 0x8005C6C0: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8005C6C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8005C6C8: jal         0x8005CCA4
    // 0x8005C6CC: swc1        $f18, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f18.u32l;
    play_random_boss_sound(rdram, ctx);
        goto after_4;
    // 0x8005C6CC: swc1        $f18, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f18.u32l;
    after_4:
    // 0x8005C6D0: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    // 0x8005C6D4: jal         0x80001D04
    // 0x8005C6D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_5;
    // 0x8005C6D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8005C6DC: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8005C6E0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8005C6E4: jal         0x8006A168
    // 0x8005C6E8: nop

    set_camera_shake(rdram, ctx);
        goto after_6;
    // 0x8005C6E8: nop

    after_6:
    // 0x8005C6EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005C6F0: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005C6F4: lwc1        $f9, 0x6FA0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6FA0);
    // 0x8005C6F8: lwc1        $f8, 0x6FA4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6FA4);
    // 0x8005C6FC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005C700: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8005C704: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005C708: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8005C70C: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x8005C710: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8005C714: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
L_8005C718:
    // 0x8005C718: lw          $t4, 0x148($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X148);
    // 0x8005C71C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8005C720: beq         $t4, $zero, L_8005C768
    if (ctx->r12 == 0) {
        // 0x8005C724: sb          $zero, 0x187($s0)
        MEM_B(0X187, ctx->r16) = 0;
            goto L_8005C768;
    }
    // 0x8005C724: sb          $zero, 0x187($s0)
    MEM_B(0X187, ctx->r16) = 0;
    // 0x8005C728: lwc1        $f0, 0x1C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8005C72C: lwc1        $f2, 0x24($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8005C730: mul.s       $f20, $f0, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8005C734: nop

    // 0x8005C738: mul.s       $f14, $f2, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8005C73C: nop

    // 0x8005C740: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8005C744: nop

    // 0x8005C748: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8005C74C: jal         0x800CA030
    // 0x8005C750: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_7;
    // 0x8005C750: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_7:
    // 0x8005C754: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x8005C758: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005C75C: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    // 0x8005C760: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8005C764: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
L_8005C768:
    // 0x8005C768: lw          $t5, 0x68($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X68);
    // 0x8005C76C: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005C770: lw          $v0, 0x0($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X0);
    // 0x8005C774: sll         $t7, $v1, 3
    ctx->r15 = S32(ctx->r3 << 3);
    // 0x8005C778: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8005C77C: nop

    // 0x8005C780: lw          $t6, 0x44($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X44);
    // 0x8005C784: nop

    // 0x8005C788: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8005C78C: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8005C790: nop

    // 0x8005C794: sll         $t2, $t9, 4
    ctx->r10 = S32(ctx->r25 << 4);
    // 0x8005C798: addiu       $t3, $t2, -0x11
    ctx->r11 = ADD32(ctx->r10, -0X11);
    // 0x8005C79C: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x8005C7A0: beq         $a1, $v1, L_8005C890
    if (ctx->r5 == ctx->r3) {
        // 0x8005C7A4: cvt.s.w     $f20, $f10
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    ctx->f20.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8005C890;
    }
    // 0x8005C7A4: cvt.s.w     $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    ctx->f20.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8005C7A8: lwc1        $f18, 0x2C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005C7AC: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8005C7B0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8005C7B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005C7B8: cvt.d.s     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.d = CVT_D_S(ctx->f18.fl);
    // 0x8005C7BC: c.lt.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d < ctx->f4.d;
    // 0x8005C7C0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8005C7C4: bc1f        L_8005C808
    if (!c1cs) {
        // 0x8005C7C8: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8005C808;
    }
    // 0x8005C7C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005C7CC: sb          $t4, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r12;
    // 0x8005C7D0: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8005C7D4: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005C7D8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8005C7DC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8005C7E0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8005C7E4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005C7E8: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005C7EC: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8005C7F0: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x8005C7F4: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8005C7F8: sub.d       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = ctx->f10.d - ctx->f6.d;
    // 0x8005C7FC: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8005C800: b           L_8005C8B0
    // 0x8005C804: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
        goto L_8005C8B0;
    // 0x8005C804: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
L_8005C808:
    // 0x8005C808: lwc1        $f9, 0x6FA8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6FA8);
    // 0x8005C80C: lwc1        $f8, 0x6FAC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6FAC);
    // 0x8005C810: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005C814: c.lt.d      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.d < ctx->f8.d;
    // 0x8005C818: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8005C81C: bc1t        L_8005C840
    if (c1cs) {
        // 0x8005C820: nop
    
            goto L_8005C840;
    }
    // 0x8005C820: nop

    // 0x8005C824: lwc1        $f11, 0x6FB0($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6FB0);
    // 0x8005C828: lwc1        $f10, 0x6FB4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6FB4);
    // 0x8005C82C: nop

    // 0x8005C830: c.lt.d      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.d < ctx->f0.d;
    // 0x8005C834: nop

    // 0x8005C838: bc1f        L_8005C86C
    if (!c1cs) {
        // 0x8005C83C: nop
    
            goto L_8005C86C;
    }
    // 0x8005C83C: nop

L_8005C840:
    // 0x8005C840: sb          $t5, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r13;
    // 0x8005C844: lwc1        $f18, 0x5C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8005C848: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005C84C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8005C850: mul.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8005C854: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8005C858: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005C85C: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8005C860: sub.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8005C864: b           L_8005C8B0
    // 0x8005C868: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
        goto L_8005C8B0;
    // 0x8005C868: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
L_8005C86C:
    // 0x8005C86C: sb          $zero, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = 0;
    // 0x8005C870: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005C874: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8005C878: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8005C87C: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8005C880: add.d       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f8.d + ctx->f10.d;
    // 0x8005C884: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8005C888: b           L_8005C8B0
    // 0x8005C88C: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
        goto L_8005C8B0;
    // 0x8005C88C: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
L_8005C890:
    // 0x8005C890: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8005C894: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005C898: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x8005C89C: add.d       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = ctx->f0.d + ctx->f0.d;
    // 0x8005C8A0: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8005C8A4: add.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f10.d + ctx->f18.d;
    // 0x8005C8A8: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8005C8AC: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
L_8005C8B0:
    // 0x8005C8B0: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005C8B4: nop

    // 0x8005C8B8: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8005C8BC: nop

    // 0x8005C8C0: bc1f        L_8005C8EC
    if (!c1cs) {
        // 0x8005C8C4: nop
    
            goto L_8005C8EC;
    }
    // 0x8005C8C4: nop

L_8005C8C8:
    // 0x8005C8C8: add.s       $f8, $f0, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x8005C8CC: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x8005C8D0: sh          $t0, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r8;
    // 0x8005C8D4: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005C8D8: nop

    // 0x8005C8DC: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8005C8E0: nop

    // 0x8005C8E4: bc1t        L_8005C8C8
    if (c1cs) {
        // 0x8005C8E8: nop
    
            goto L_8005C8C8;
    }
    // 0x8005C8E8: nop

L_8005C8EC:
    // 0x8005C8EC: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x8005C8F0: nop

    // 0x8005C8F4: bc1f        L_8005C920
    if (!c1cs) {
        // 0x8005C8F8: nop
    
            goto L_8005C920;
    }
    // 0x8005C8F8: nop

L_8005C8FC:
    // 0x8005C8FC: sub.s       $f10, $f0, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x8005C900: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x8005C904: sh          $t0, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r8;
    // 0x8005C908: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005C90C: nop

    // 0x8005C910: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x8005C914: nop

    // 0x8005C918: bc1t        L_8005C8FC
    if (c1cs) {
        // 0x8005C91C: nop
    
            goto L_8005C8FC;
    }
    // 0x8005C91C: nop

L_8005C920:
    // 0x8005C920: lh          $t6, 0x10($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X10);
    // 0x8005C924: nop

    // 0x8005C928: bne         $t0, $t6, L_8005C954
    if (ctx->r8 != ctx->r14) {
        // 0x8005C92C: nop
    
            goto L_8005C954;
    }
    // 0x8005C92C: nop

    // 0x8005C930: lb          $t7, 0x3B($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X3B);
    // 0x8005C934: nop

    // 0x8005C938: bne         $a1, $t7, L_8005C954
    if (ctx->r5 != ctx->r15) {
        // 0x8005C93C: nop
    
            goto L_8005C954;
    }
    // 0x8005C93C: nop

    // 0x8005C940: lbu         $t8, 0x1CD($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1CD);
    // 0x8005C944: nop

    // 0x8005C948: sb          $t8, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r24;
    // 0x8005C94C: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005C950: nop

L_8005C954:
    // 0x8005C954: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8005C958: lh          $t9, 0x18($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X18);
    // 0x8005C95C: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x8005C960: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005C964: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005C968: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x8005C96C: cvt.w.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = CVT_W_S(ctx->f0.fl);
    // 0x8005C970: lb          $t4, 0x3B($s1)
    ctx->r12 = MEM_B(ctx->r17, 0X3B);
    // 0x8005C974: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x8005C978: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005C97C: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8005C980: sw          $zero, 0x74($s1)
    MEM_W(0X74, ctx->r17) = 0;
    // 0x8005C984: bne         $t4, $at, L_8005C9B8
    if (ctx->r12 != ctx->r1) {
        // 0x8005C988: sh          $t3, 0x18($s1)
        MEM_H(0X18, ctx->r17) = ctx->r11;
            goto L_8005C9B8;
    }
    // 0x8005C988: sh          $t3, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r11;
    // 0x8005C98C: lh          $a2, 0x54($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X54);
    // 0x8005C990: addiu       $t5, $zero, 0xAD
    ctx->r13 = ADD32(0, 0XAD);
    // 0x8005C994: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8005C998: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005C99C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8005C9A0: jal         0x800113CC
    // 0x8005C9A4: addiu       $a3, $zero, 0xAC
    ctx->r7 = ADD32(0, 0XAC);
    play_footstep_sounds(rdram, ctx);
        goto after_8;
    // 0x8005C9A4: addiu       $a3, $zero, 0xAC
    ctx->r7 = ADD32(0, 0XAC);
    after_8:
    // 0x8005C9A8: lw          $t6, 0x74($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X74);
    // 0x8005C9AC: nop

    // 0x8005C9B0: ori         $t7, $t6, 0x3
    ctx->r15 = ctx->r14 | 0X3;
    // 0x8005C9B4: sw          $t7, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r15;
L_8005C9B8:
    // 0x8005C9B8: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x8005C9BC: jal         0x800B019C
    // 0x8005C9C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    obj_spawn_particle(rdram, ctx);
        goto after_9;
    // 0x8005C9C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x8005C9C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005C9C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8005C9CC: jal         0x8005D1E8
    // 0x8005C9D0: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    fade_when_near_camera(rdram, ctx);
        goto after_10;
    // 0x8005C9D0: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    after_10:
    // 0x8005C9D4: lb          $v0, 0x3B($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X3B);
    // 0x8005C9D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005C9DC: beq         $v0, $at, L_8005C9F8
    if (ctx->r2 == ctx->r1) {
        // 0x8005C9E0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8005C9F8;
    }
    // 0x8005C9E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005C9E4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005C9E8: beq         $v0, $at, L_8005CA00
    if (ctx->r2 == ctx->r1) {
        // 0x8005C9EC: addiu       $a1, $zero, 0x100
        ctx->r5 = ADD32(0, 0X100);
            goto L_8005CA00;
    }
    // 0x8005C9EC: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    // 0x8005C9F0: b           L_8005CA00
    // 0x8005C9F4: addiu       $a1, $zero, 0x1500
    ctx->r5 = ADD32(0, 0X1500);
        goto L_8005CA00;
    // 0x8005C9F4: addiu       $a1, $zero, 0x1500
    ctx->r5 = ADD32(0, 0X1500);
L_8005C9F8:
    // 0x8005C9F8: b           L_8005CA00
    // 0x8005C9FC: addiu       $a1, $zero, 0x2500
    ctx->r5 = ADD32(0, 0X2500);
        goto L_8005CA00;
    // 0x8005C9FC: addiu       $a1, $zero, 0x2500
    ctx->r5 = ADD32(0, 0X2500);
L_8005CA00:
    // 0x8005CA00: jal         0x8001BAFC
    // 0x8005CA04: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    get_racer_object(rdram, ctx);
        goto after_11;
    // 0x8005CA04: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_11:
    // 0x8005CA08: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8005CA0C: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8005CA10: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8005CA14: lwc1        $f10, 0x14($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8005CA18: sub.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8005CA1C: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8005CA20: mul.s       $f18, $f20, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8005CA24: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8005CA28: swc1        $f14, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f14.u32l;
    // 0x8005CA2C: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8005CA30: jal         0x800CA030
    // 0x8005CA34: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_12;
    // 0x8005CA34: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_12:
    // 0x8005CA38: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005CA3C: lwc1        $f9, 0x6FB8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6FB8);
    // 0x8005CA40: lwc1        $f8, 0x6FBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6FBC);
    // 0x8005CA44: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8005CA48: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x8005CA4C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8005CA50: lwc1        $f14, 0x48($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8005CA54: bc1f        L_8005CAD0
    if (!c1cs) {
        // 0x8005CA58: nop
    
            goto L_8005CAD0;
    }
    // 0x8005CA58: nop

    // 0x8005CA5C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8005CA60: jal         0x80070990
    // 0x8005CA64: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    arctan2_f(rdram, ctx);
        goto after_13;
    // 0x8005CA64: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_13:
    // 0x8005CA68: lh          $t8, 0x0($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X0);
    // 0x8005CA6C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8005CA70: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x8005CA74: subu        $v1, $v0, $t9
    ctx->r3 = SUB32(ctx->r2, ctx->r25);
    // 0x8005CA78: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
    // 0x8005CA7C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8005CA80: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8005CA84: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8005CA88: bne         $at, $zero, L_8005CA9C
    if (ctx->r1 != 0) {
        // 0x8005CA8C: negu        $v0, $a1
        ctx->r2 = SUB32(0, ctx->r5);
            goto L_8005CA9C;
    }
    // 0x8005CA8C: negu        $v0, $a1
    ctx->r2 = SUB32(0, ctx->r5);
    // 0x8005CA90: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8005CA94: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8005CA98: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8005CA9C:
    // 0x8005CA9C: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x8005CAA0: beq         $at, $zero, L_8005CAAC
    if (ctx->r1 == 0) {
        // 0x8005CAA4: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8005CAAC;
    }
    // 0x8005CAA4: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8005CAA8: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8005CAAC:
    // 0x8005CAAC: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8005CAB0: beq         $at, $zero, L_8005CAC0
    if (ctx->r1 == 0) {
        // 0x8005CAB4: slt         $at, $v1, $v0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8005CAC0;
    }
    // 0x8005CAB4: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8005CAB8: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x8005CABC: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
L_8005CAC0:
    // 0x8005CAC0: beq         $at, $zero, L_8005CACC
    if (ctx->r1 == 0) {
        // 0x8005CAC4: nop
    
            goto L_8005CACC;
    }
    // 0x8005CAC4: nop

    // 0x8005CAC8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8005CACC:
    // 0x8005CACC: sh          $v1, 0x16C($s0)
    MEM_H(0X16C, ctx->r16) = ctx->r3;
L_8005CAD0:
    // 0x8005CAD0: lb          $t2, 0x3B($s1)
    ctx->r10 = MEM_B(ctx->r17, 0X3B);
    // 0x8005CAD4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005CAD8: bne         $t2, $at, L_8005CB08
    if (ctx->r10 != ctx->r1) {
        // 0x8005CADC: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_8005CB08;
    }
    // 0x8005CADC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005CAE0: lb          $t3, 0x1E7($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1E7);
    // 0x8005CAE4: nop

    // 0x8005CAE8: andi        $t4, $t3, 0x1F
    ctx->r12 = ctx->r11 & 0X1F;
    // 0x8005CAEC: slti        $at, $t4, 0xA
    ctx->r1 = SIGNED(ctx->r12) < 0XA ? 1 : 0;
    // 0x8005CAF0: beq         $at, $zero, L_8005CB0C
    if (ctx->r1 == 0) {
        // 0x8005CAF4: lw          $v1, 0x30($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X30);
            goto L_8005CB0C;
    }
    // 0x8005CAF4: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x8005CAF8: lh          $t5, 0x16C($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X16C);
    // 0x8005CAFC: nop

    // 0x8005CB00: sra         $t6, $t5, 1
    ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
    // 0x8005CB04: sh          $t6, 0x16C($s0)
    MEM_H(0X16C, ctx->r16) = ctx->r14;
L_8005CB08:
    // 0x8005CB08: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
L_8005CB0C:
    // 0x8005CB0C: addiu       $v0, $v0, -0x24C0
    ctx->r2 = ADD32(ctx->r2, -0X24C0);
    // 0x8005CB10: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8005CB14: lwc1        $f0, 0x10($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8005CB18: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005CB1C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8005CB20: lw          $s0, 0x64($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X64);
    // 0x8005CB24: bc1f        L_8005CB3C
    if (!c1cs) {
        // 0x8005CB28: lui         $at, 0x4079
        ctx->r1 = S32(0X4079 << 16);
            goto L_8005CB3C;
    }
    // 0x8005CB28: lui         $at, 0x4079
    ctx->r1 = S32(0X4079 << 16);
    // 0x8005CB2C: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x8005CB30: lwc1        $f0, 0x10($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8005CB34: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8005CB38: nop

L_8005CB3C:
    // 0x8005CB3C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8005CB40: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x8005CB44: add.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f10.d + ctx->f18.d;
    // 0x8005CB48: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x8005CB4C: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x8005CB50: nop

    // 0x8005CB54: bc1f        L_8005CB94
    if (!c1cs) {
        // 0x8005CB58: nop
    
            goto L_8005CB94;
    }
    // 0x8005CB58: nop

    // 0x8005CB5C: jal         0x800C06AC
    // 0x8005CB60: nop

    check_fadeout_transition(rdram, ctx);
        goto after_14;
    // 0x8005CB60: nop

    after_14:
    // 0x8005CB64: bne         $v0, $zero, L_8005CB84
    if (ctx->r2 != 0) {
        // 0x8005CB68: nop
    
            goto L_8005CB84;
    }
    // 0x8005CB68: nop

    // 0x8005CB6C: jal         0x8009F1C4
    // 0x8005CB70: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_15;
    // 0x8005CB70: nop

    after_15:
    // 0x8005CB74: beq         $v0, $zero, L_8005CB84
    if (ctx->r2 == 0) {
        // 0x8005CB78: nop
    
            goto L_8005CB84;
    }
    // 0x8005CB78: nop

    // 0x8005CB7C: jal         0x8006F5D8
    // 0x8005CB80: nop

    swap_lead_player(rdram, ctx);
        goto after_16;
    // 0x8005CB80: nop

    after_16:
L_8005CB84:
    // 0x8005CB84: jal         0x8006F380
    // 0x8005CB88: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    level_transition_begin(rdram, ctx);
        goto after_17;
    // 0x8005CB88: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_17:
    // 0x8005CB8C: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x8005CB90: nop

L_8005CB94:
    // 0x8005CB94: lw          $v0, 0x4C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4C);
    // 0x8005CB98: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8005CB9C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8005CBA0: addiu       $a1, $a1, -0x24BC
    ctx->r5 = ADD32(ctx->r5, -0X24BC);
    // 0x8005CBA4: bne         $s1, $t7, L_8005CBD4
    if (ctx->r17 != ctx->r15) {
        // 0x8005CBA8: nop
    
            goto L_8005CBD4;
    }
    // 0x8005CBA8: nop

    // 0x8005CBAC: lh          $t8, 0x14($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X14);
    // 0x8005CBB0: nop

    // 0x8005CBB4: andi        $t9, $t8, 0x8
    ctx->r25 = ctx->r24 & 0X8;
    // 0x8005CBB8: beq         $t9, $zero, L_8005CBD4
    if (ctx->r25 == 0) {
        // 0x8005CBBC: nop
    
            goto L_8005CBD4;
    }
    // 0x8005CBBC: nop

    // 0x8005CBC0: lb          $t2, 0x3B($s1)
    ctx->r10 = MEM_B(ctx->r17, 0X3B);
    // 0x8005CBC4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005CBC8: bne         $t2, $at, L_8005CBD4
    if (ctx->r10 != ctx->r1) {
        // 0x8005CBCC: addiu       $t3, $zero, 0x4
        ctx->r11 = ADD32(0, 0X4);
            goto L_8005CBD4;
    }
    // 0x8005CBCC: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8005CBD0: sb          $t3, 0x187($s0)
    MEM_B(0X187, ctx->r16) = ctx->r11;
L_8005CBD4:
    // 0x8005CBD4: lb          $t4, 0x1D8($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1D8);
    // 0x8005CBD8: nop

    // 0x8005CBDC: beq         $t4, $zero, L_8005CC00
    if (ctx->r12 == 0) {
        // 0x8005CBE0: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8005CC00;
    }
    // 0x8005CBE0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8005CBE4: lb          $t5, 0x0($a1)
    ctx->r13 = MEM_B(ctx->r5, 0X0);
    // 0x8005CBE8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005CBEC: bne         $t5, $zero, L_8005CBFC
    if (ctx->r13 != 0) {
        // 0x8005CBF0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8005CBFC;
    }
    // 0x8005CBF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005CBF4: jal         0x8005CD08
    // 0x8005CBF8: sb          $t6, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r14;
    racer_boss_finish(rdram, ctx);
        goto after_18;
    // 0x8005CBF8: sb          $t6, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r14;
    after_18:
L_8005CBFC:
    // 0x8005CBFC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8005CC00:
    // 0x8005CC00: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8005CC04: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8005CC08: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8005CC0C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8005CC10: jr          $ra
    // 0x8005CC14: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8005CC14: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void set_boss_voice_clip_offset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005CC18: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005CC1C: jr          $ra
    // 0x8005CC20: sw          $a0, -0x24B8($at)
    MEM_W(-0X24B8, ctx->r1) = ctx->r4;
    return;
    // 0x8005CC20: sw          $a0, -0x24B8($at)
    MEM_W(-0X24B8, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void racer_boss_sound_spatial(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005CC24: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005CC28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005CC2C: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x8005CC30: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x8005CC34: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8005CC38: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8005CC3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005CC40: jal         0x8006FB8C
    // 0x8005CC44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    rand_range(rdram, ctx);
        goto after_0;
    // 0x8005CC44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8005CC48: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8005CC4C: sll         $v1, $v0, 24
    ctx->r3 = S32(ctx->r2 << 24);
    // 0x8005CC50: sra         $t6, $v1, 24
    ctx->r14 = S32(SIGNED(ctx->r3) >> 24);
    // 0x8005CC54: bne         $t0, $zero, L_8005CC60
    if (ctx->r8 != 0) {
        // 0x8005CC58: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_8005CC60;
    }
    // 0x8005CC58: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x8005CC5C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8005CC60:
    // 0x8005CC60: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8005CC64: lw          $t7, -0x24B8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X24B8);
    // 0x8005CC68: addu        $t0, $t0, $v1
    ctx->r8 = ADD32(ctx->r8, ctx->r3);
    // 0x8005CC6C: sll         $t8, $t0, 1
    ctx->r24 = S32(ctx->r8 << 1);
    // 0x8005CC70: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8005CC74: lhu         $a0, 0x0($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X0);
    // 0x8005CC78: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8005CC7C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8005CC80: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8005CC84: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8005CC88: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8005CC8C: jal         0x80009558
    // 0x8005CC90: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_1;
    // 0x8005CC90: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_1:
    // 0x8005CC94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005CC98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005CC9C: jr          $ra
    // 0x8005CCA0: nop

    return;
    // 0x8005CCA0: nop

;}
RECOMP_FUNC void play_random_boss_sound(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005CCA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005CCA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005CCAC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8005CCB0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x8005CCB4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005CCB8: jal         0x8006FB8C
    // 0x8005CCBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    rand_range(rdram, ctx);
        goto after_0;
    // 0x8005CCBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8005CCC0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8005CCC4: sll         $v1, $v0, 24
    ctx->r3 = S32(ctx->r2 << 24);
    // 0x8005CCC8: sra         $t6, $v1, 24
    ctx->r14 = S32(SIGNED(ctx->r3) >> 24);
    // 0x8005CCCC: bne         $a2, $zero, L_8005CCD8
    if (ctx->r6 != 0) {
        // 0x8005CCD0: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_8005CCD8;
    }
    // 0x8005CCD0: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x8005CCD4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8005CCD8:
    // 0x8005CCD8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8005CCDC: lw          $t7, -0x24B8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X24B8);
    // 0x8005CCE0: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // 0x8005CCE4: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x8005CCE8: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8005CCEC: lhu         $a0, 0x0($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X0);
    // 0x8005CCF0: jal         0x80001D04
    // 0x8005CCF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_1;
    // 0x8005CCF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8005CCF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005CCFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005CD00: jr          $ra
    // 0x8005CD04: nop

    return;
    // 0x8005CD04: nop

;}
RECOMP_FUNC void racer_boss_finish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005CD08: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8005CD0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005CD10: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005CD14: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8005CD18: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8005CD1C: lb          $t7, 0x0($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X0);
    // 0x8005CD20: jal         0x8006ECD0
    // 0x8005CD24: sb          $t7, 0x43($sp)
    MEM_B(0X43, ctx->r29) = ctx->r15;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x8005CD24: sb          $t7, 0x43($sp)
    MEM_B(0X43, ctx->r29) = ctx->r15;
    after_0:
    // 0x8005CD28: lbu         $t8, 0x48($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X48);
    // 0x8005CD2C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8005CD30: sllv        $t1, $t9, $t8
    ctx->r9 = S32(ctx->r25 << (ctx->r24 & 31));
    // 0x8005CD34: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x8005CD38: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8005CD3C: jal         0x8001E2D0
    // 0x8005CD40: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    get_misc_asset(rdram, ctx);
        goto after_1;
    // 0x8005CD40: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    after_1:
    // 0x8005CD44: lb          $t4, 0x5($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X5);
    // 0x8005CD48: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    // 0x8005CD4C: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x8005CD50: lb          $t5, 0x6($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X6);
    // 0x8005CD54: nop

    // 0x8005CD58: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x8005CD5C: lb          $t6, 0x7($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X7);
    // 0x8005CD60: jal         0x8001E2D0
    // 0x8005CD64: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    get_misc_asset(rdram, ctx);
        goto after_2;
    // 0x8005CD64: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_2:
    // 0x8005CD68: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8005CD6C: lb          $t7, 0x0($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X0);
    // 0x8005CD70: lbu         $a0, 0x49($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X49);
    // 0x8005CD74: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8005CD78: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8005CD7C: beq         $a0, $t7, L_8005CD98
    if (ctx->r4 == ctx->r15) {
        // 0x8005CD80: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8005CD98;
    }
    // 0x8005CD80: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8005CD84: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_8005CD88:
    // 0x8005CD88: lb          $t9, 0x2($v1)
    ctx->r25 = MEM_B(ctx->r3, 0X2);
    // 0x8005CD8C: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x8005CD90: bne         $a0, $t9, L_8005CD88
    if (ctx->r4 != ctx->r25) {
        // 0x8005CD94: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_8005CD88;
    }
    // 0x8005CD94: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
L_8005CD98:
    // 0x8005CD98: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x8005CD9C: lb          $t6, 0x43($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X43);
    // 0x8005CDA0: lh          $t5, 0x1AC($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X1AC);
    // 0x8005CDA4: addu        $t8, $s0, $v0
    ctx->r24 = ADD32(ctx->r16, ctx->r2);
    // 0x8005CDA8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8005CDAC: lb          $s0, 0x1($t8)
    ctx->r16 = MEM_B(ctx->r24, 0X1);
    // 0x8005CDB0: bne         $t6, $v1, L_8005D1C8
    if (ctx->r14 != ctx->r3) {
        // 0x8005CDB4: sw          $t5, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r13;
            goto L_8005D1C8;
    }
    // 0x8005CDB4: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    // 0x8005CDB8: bne         $t5, $v1, L_8005CDE0
    if (ctx->r13 != ctx->r3) {
        // 0x8005CDBC: addiu       $a0, $zero, 0x3E
        ctx->r4 = ADD32(0, 0X3E);
            goto L_8005CDE0;
    }
    // 0x8005CDBC: addiu       $a0, $zero, 0x3E
    ctx->r4 = ADD32(0, 0X3E);
    // 0x8005CDC0: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
    // 0x8005CDC4: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x8005CDC8: jal         0x80000B34
    // 0x8005CDCC: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    music_play(rdram, ctx);
        goto after_3;
    // 0x8005CDCC: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    after_3:
    // 0x8005CDD0: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8005CDD4: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8005CDD8: b           L_8005CDFC
    // 0x8005CDDC: lbu         $v1, 0x48($t2)
    ctx->r3 = MEM_BU(ctx->r10, 0X48);
        goto L_8005CDFC;
    // 0x8005CDDC: lbu         $v1, 0x48($t2)
    ctx->r3 = MEM_BU(ctx->r10, 0X48);
L_8005CDE0:
    // 0x8005CDE0: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x8005CDE4: jal         0x80000B34
    // 0x8005CDE8: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    music_play(rdram, ctx);
        goto after_4;
    // 0x8005CDE8: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    after_4:
    // 0x8005CDEC: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8005CDF0: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8005CDF4: nop

    // 0x8005CDF8: lbu         $v1, 0x48($t2)
    ctx->r3 = MEM_BU(ctx->r10, 0X48);
L_8005CDFC:
    // 0x8005CDFC: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8005CE00: beq         $v1, $zero, L_8005CE0C
    if (ctx->r3 == 0) {
        // 0x8005CE04: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8005CE0C;
    }
    // 0x8005CE04: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8005CE08: bne         $v1, $at, L_8005CF98
    if (ctx->r3 != ctx->r1) {
        // 0x8005CE0C: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_8005CF98;
    }
L_8005CE0C:
    // 0x8005CE0C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8005CE10: bne         $t0, $t3, L_8005CE4C
    if (ctx->r8 != ctx->r11) {
        // 0x8005CE14: nop
    
            goto L_8005CE4C;
    }
    // 0x8005CE14: nop

    // 0x8005CE18: lhu         $t7, 0xC($t2)
    ctx->r15 = MEM_HU(ctx->r10, 0XC);
    // 0x8005CE1C: lbu         $t4, 0x49($t2)
    ctx->r12 = MEM_BU(ctx->r10, 0X49);
    // 0x8005CE20: lw          $t8, 0x4($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X4);
    // 0x8005CE24: or          $t9, $t7, $t1
    ctx->r25 = ctx->r15 | ctx->r9;
    // 0x8005CE28: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x8005CE2C: sh          $t9, 0xC($t2)
    MEM_H(0XC, ctx->r10) = ctx->r25;
    // 0x8005CE30: addu        $v0, $t8, $t6
    ctx->r2 = ADD32(ctx->r24, ctx->r14);
    // 0x8005CE34: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x8005CE38: nop

    // 0x8005CE3C: ori         $t7, $t5, 0x2
    ctx->r15 = ctx->r13 | 0X2;
    // 0x8005CE40: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8005CE44: lbu         $v1, 0x48($t2)
    ctx->r3 = MEM_BU(ctx->r10, 0X48);
    // 0x8005CE48: nop

L_8005CE4C:
    // 0x8005CE4C: bne         $v1, $zero, L_8005CECC
    if (ctx->r3 != 0) {
        // 0x8005CE50: nop
    
            goto L_8005CECC;
    }
    // 0x8005CE50: nop

    // 0x8005CE54: bne         $t0, $t3, L_8005CEA0
    if (ctx->r8 != ctx->r11) {
        // 0x8005CE58: addiu       $a0, $zero, -0xA
        ctx->r4 = ADD32(0, -0XA);
            goto L_8005CEA0;
    }
    // 0x8005CE58: addiu       $a0, $zero, -0xA
    ctx->r4 = ADD32(0, -0XA);
    // 0x8005CE5C: addiu       $a0, $zero, -0x2
    ctx->r4 = ADD32(0, -0X2);
    // 0x8005CE60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005CE64: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005CE68: jal         0x8006C3EC
    // 0x8005CE6C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    level_properties_push(rdram, ctx);
        goto after_5;
    // 0x8005CE6C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x8005CE70: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8005CE74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005CE78: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8005CE7C: jal         0x8006C3EC
    // 0x8005CE80: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    level_properties_push(rdram, ctx);
        goto after_6;
    // 0x8005CE80: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x8005CE84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005CE88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005CE8C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8005CE90: jal         0x8006C3EC
    // 0x8005CE94: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    level_properties_push(rdram, ctx);
        goto after_7;
    // 0x8005CE94: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_7:
    // 0x8005CE98: b           L_8005CF60
    // 0x8005CE9C: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
        goto L_8005CF60;
    // 0x8005CE9C: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_8005CEA0:
    // 0x8005CEA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005CEA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005CEA8: jal         0x8006C3EC
    // 0x8005CEAC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    level_properties_push(rdram, ctx);
        goto after_8;
    // 0x8005CEAC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_8:
    // 0x8005CEB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005CEB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005CEB8: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8005CEBC: jal         0x8006C3EC
    // 0x8005CEC0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    level_properties_push(rdram, ctx);
        goto after_9;
    // 0x8005CEC0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_9:
    // 0x8005CEC4: b           L_8005CF60
    // 0x8005CEC8: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
        goto L_8005CF60;
    // 0x8005CEC8: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_8005CECC:
    // 0x8005CECC: bne         $t0, $t3, L_8005CF38
    if (ctx->r8 != ctx->r11) {
        // 0x8005CED0: addiu       $a0, $zero, -0xA
        ctx->r4 = ADD32(0, -0XA);
            goto L_8005CF38;
    }
    // 0x8005CED0: addiu       $a0, $zero, -0xA
    ctx->r4 = ADD32(0, -0XA);
    // 0x8005CED4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x8005CED8: jal         0x8009EFBC
    // 0x8005CEDC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    set_eeprom_settings_value(rdram, ctx);
        goto after_10;
    // 0x8005CEDC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x8005CEE0: addiu       $a0, $zero, -0x2
    ctx->r4 = ADD32(0, -0X2);
    // 0x8005CEE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005CEE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005CEEC: jal         0x8006C3EC
    // 0x8005CEF0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    level_properties_push(rdram, ctx);
        goto after_11;
    // 0x8005CEF0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_11:
    // 0x8005CEF4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8005CEF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005CEFC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8005CF00: jal         0x8006C3EC
    // 0x8005CF04: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    level_properties_push(rdram, ctx);
        goto after_12;
    // 0x8005CF04: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_12:
    // 0x8005CF08: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8005CF0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005CF10: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8005CF14: jal         0x8006C3EC
    // 0x8005CF18: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    level_properties_push(rdram, ctx);
        goto after_13;
    // 0x8005CF18: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_13:
    // 0x8005CF1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005CF20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005CF24: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8005CF28: jal         0x8006C3EC
    // 0x8005CF2C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    level_properties_push(rdram, ctx);
        goto after_14;
    // 0x8005CF2C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_14:
    // 0x8005CF30: b           L_8005CF60
    // 0x8005CF34: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
        goto L_8005CF60;
    // 0x8005CF34: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_8005CF38:
    // 0x8005CF38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005CF3C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005CF40: jal         0x8006C3EC
    // 0x8005CF44: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    level_properties_push(rdram, ctx);
        goto after_15;
    // 0x8005CF44: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_15:
    // 0x8005CF48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005CF4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005CF50: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8005CF54: jal         0x8006C3EC
    // 0x8005CF58: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    level_properties_push(rdram, ctx);
        goto after_16;
    // 0x8005CF58: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_16:
    // 0x8005CF5C: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_8005CF60:
    // 0x8005CF60: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005CF64: bne         $t9, $at, L_8005CF7C
    if (ctx->r25 != ctx->r1) {
        // 0x8005CF68: nop
    
            goto L_8005CF7C;
    }
    // 0x8005CF68: nop

    // 0x8005CF6C: jal         0x8006F380
    // 0x8005CF70: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    level_transition_begin(rdram, ctx);
        goto after_17;
    // 0x8005CF70: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_17:
    // 0x8005CF74: b           L_8005CF88
    // 0x8005CF78: lb          $v0, 0x43($sp)
    ctx->r2 = MEM_B(ctx->r29, 0X43);
        goto L_8005CF88;
    // 0x8005CF78: lb          $v0, 0x43($sp)
    ctx->r2 = MEM_B(ctx->r29, 0X43);
L_8005CF7C:
    // 0x8005CF7C: jal         0x8006F380
    // 0x8005CF80: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    level_transition_begin(rdram, ctx);
        goto after_18;
    // 0x8005CF80: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_18:
    // 0x8005CF84: lb          $v0, 0x43($sp)
    ctx->r2 = MEM_B(ctx->r29, 0X43);
L_8005CF88:
    // 0x8005CF88: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x8005CF8C: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x8005CF90: b           L_8005D1D8
    // 0x8005CF94: sb          $t8, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r24;
        goto L_8005D1D8;
    // 0x8005CF94: sb          $t8, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r24;
L_8005CF98:
    // 0x8005CF98: lbu         $t7, 0x49($t2)
    ctx->r15 = MEM_BU(ctx->r10, 0X49);
    // 0x8005CF9C: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x8005CFA0: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8005CFA4: addu        $v0, $t5, $t9
    ctx->r2 = ADD32(ctx->r13, ctx->r25);
    // 0x8005CFA8: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8005CFAC: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8005CFB0: andi        $t4, $v1, 0x2
    ctx->r12 = ctx->r3 & 0X2;
    // 0x8005CFB4: beq         $t4, $zero, L_8005D01C
    if (ctx->r12 == 0) {
        // 0x8005CFB8: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8005D01C;
    }
    // 0x8005CFB8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005CFBC: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8005CFC0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005CFC4: bne         $t8, $at, L_8005CFE4
    if (ctx->r24 != ctx->r1) {
        // 0x8005CFC8: nop
    
            goto L_8005CFE4;
    }
    // 0x8005CFC8: nop

    // 0x8005CFCC: jal         0x8006F380
    // 0x8005CFD0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    level_transition_begin(rdram, ctx);
        goto after_19;
    // 0x8005CFD0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_19:
    // 0x8005CFD4: jal         0x8000E128
    // 0x8005CFD8: nop

    instShowBearBar(rdram, ctx);
        goto after_20;
    // 0x8005CFD8: nop

    after_20:
    // 0x8005CFDC: b           L_8005D008
    // 0x8005CFE0: lb          $t6, 0x43($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X43);
        goto L_8005D008;
    // 0x8005CFE0: lb          $t6, 0x43($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X43);
L_8005CFE4:
    // 0x8005CFE4: jal         0x8006F380
    // 0x8005CFE8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    level_transition_begin(rdram, ctx);
        goto after_21;
    // 0x8005CFE8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_21:
    // 0x8005CFEC: jal         0x8009F1C4
    // 0x8005CFF0: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_22;
    // 0x8005CFF0: nop

    after_22:
    // 0x8005CFF4: beq         $v0, $zero, L_8005D008
    if (ctx->r2 == 0) {
        // 0x8005CFF8: lb          $t6, 0x43($sp)
        ctx->r14 = MEM_B(ctx->r29, 0X43);
            goto L_8005D008;
    }
    // 0x8005CFF8: lb          $t6, 0x43($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X43);
    // 0x8005CFFC: jal         0x8006F5D8
    // 0x8005D000: nop

    swap_lead_player(rdram, ctx);
        goto after_23;
    // 0x8005D000: nop

    after_23:
    // 0x8005D004: lb          $t6, 0x43($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X43);
L_8005D008:
    // 0x8005D008: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x8005D00C: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x8005D010: sb          $t9, 0x43($sp)
    MEM_B(0X43, ctx->r29) = ctx->r25;
    // 0x8005D014: b           L_8005D1D8
    // 0x8005D018: sb          $t9, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r25;
        goto L_8005D1D8;
    // 0x8005D018: sb          $t9, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r25;
L_8005D01C:
    // 0x8005D01C: bne         $t8, $at, L_8005D180
    if (ctx->r24 != ctx->r1) {
        // 0x8005D020: addiu       $a0, $zero, -0xA
        ctx->r4 = ADD32(0, -0XA);
            goto L_8005D180;
    }
    // 0x8005D020: addiu       $a0, $zero, -0xA
    ctx->r4 = ADD32(0, -0XA);
    // 0x8005D024: ori         $t6, $v1, 0x2
    ctx->r14 = ctx->r3 | 0X2;
    // 0x8005D028: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8005D02C: lhu         $t0, 0xC($t2)
    ctx->r8 = MEM_HU(ctx->r10, 0XC);
    // 0x8005D030: sll         $t9, $t1, 6
    ctx->r25 = S32(ctx->r9 << 6);
    // 0x8005D034: and         $t7, $t0, $t1
    ctx->r15 = ctx->r8 & ctx->r9;
    // 0x8005D038: bne         $t7, $zero, L_8005D078
    if (ctx->r15 != 0) {
        // 0x8005D03C: and         $t4, $t0, $t9
        ctx->r12 = ctx->r8 & ctx->r25;
            goto L_8005D078;
    }
    // 0x8005D03C: and         $t4, $t0, $t9
    ctx->r12 = ctx->r8 & ctx->r25;
    // 0x8005D040: or          $t5, $t0, $t1
    ctx->r13 = ctx->r8 | ctx->r9;
    // 0x8005D044: sh          $t5, 0xC($t2)
    MEM_H(0XC, ctx->r10) = ctx->r13;
    // 0x8005D048: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8005D04C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005D050: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005D054: jal         0x8006C3EC
    // 0x8005D058: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    level_properties_push(rdram, ctx);
        goto after_24;
    // 0x8005D058: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_24:
    // 0x8005D05C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005D060: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8005D064: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8005D068: jal         0x8006C3EC
    // 0x8005D06C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    level_properties_push(rdram, ctx);
        goto after_25;
    // 0x8005D06C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_25:
    // 0x8005D070: b           L_8005D168
    // 0x8005D074: nop

        goto L_8005D168;
    // 0x8005D074: nop

L_8005D078:
    // 0x8005D078: bne         $t4, $zero, L_8005D144
    if (ctx->r12 != 0) {
        // 0x8005D07C: addiu       $a0, $zero, -0x1
        ctx->r4 = ADD32(0, -0X1);
            goto L_8005D144;
    }
    // 0x8005D07C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8005D080: lbu         $v1, 0x48($t2)
    ctx->r3 = MEM_BU(ctx->r10, 0X48);
    // 0x8005D084: or          $t8, $t0, $t9
    ctx->r24 = ctx->r8 | ctx->r25;
    // 0x8005D088: sh          $t8, 0xC($t2)
    MEM_H(0XC, ctx->r10) = ctx->r24;
    // 0x8005D08C: blez        $v1, L_8005D0C0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8005D090: or          $t1, $zero, $zero
        ctx->r9 = 0 | 0;
            goto L_8005D0C0;
    }
    // 0x8005D090: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x8005D094: slti        $at, $v1, 0x5
    ctx->r1 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // 0x8005D098: beq         $at, $zero, L_8005D0C0
    if (ctx->r1 == 0) {
        // 0x8005D09C: nop
    
            goto L_8005D0C0;
    }
    // 0x8005D09C: nop

    // 0x8005D0A0: lbu         $t1, 0x17($t2)
    ctx->r9 = MEM_BU(ctx->r10, 0X17);
    // 0x8005D0A4: nop

    // 0x8005D0A8: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8005D0AC: slti        $at, $t1, 0x5
    ctx->r1 = SIGNED(ctx->r9) < 0X5 ? 1 : 0;
    // 0x8005D0B0: bne         $at, $zero, L_8005D0BC
    if (ctx->r1 != 0) {
        // 0x8005D0B4: nop
    
            goto L_8005D0BC;
    }
    // 0x8005D0B4: nop

    // 0x8005D0B8: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
L_8005D0BC:
    // 0x8005D0BC: sb          $t1, 0x17($t2)
    MEM_B(0X17, ctx->r10) = ctx->r9;
L_8005D0C0:
    // 0x8005D0C0: beq         $t1, $zero, L_8005D118
    if (ctx->r9 == 0) {
        // 0x8005D0C4: addiu       $a0, $zero, -0x1
        ctx->r4 = ADD32(0, -0X1);
            goto L_8005D118;
    }
    // 0x8005D0C4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8005D0C8: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8005D0CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005D0D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005D0D4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8005D0D8: jal         0x8006C3EC
    // 0x8005D0DC: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    level_properties_push(rdram, ctx);
        goto after_26;
    // 0x8005D0DC: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    after_26:
    // 0x8005D0E0: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8005D0E4: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    // 0x8005D0E8: lbu         $a3, 0x17($t2)
    ctx->r7 = MEM_BU(ctx->r10, 0X17);
    // 0x8005D0EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005D0F0: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8005D0F4: jal         0x8006C3EC
    // 0x8005D0F8: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    level_properties_push(rdram, ctx);
        goto after_27;
    // 0x8005D0F8: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    after_27:
    // 0x8005D0FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005D100: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x8005D104: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8005D108: jal         0x8006C3EC
    // 0x8005D10C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    level_properties_push(rdram, ctx);
        goto after_28;
    // 0x8005D10C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_28:
    // 0x8005D110: b           L_8005D168
    // 0x8005D114: nop

        goto L_8005D168;
    // 0x8005D114: nop

L_8005D118:
    // 0x8005D118: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005D11C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005D120: jal         0x8006C3EC
    // 0x8005D124: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    level_properties_push(rdram, ctx);
        goto after_29;
    // 0x8005D124: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_29:
    // 0x8005D128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005D12C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8005D130: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8005D134: jal         0x8006C3EC
    // 0x8005D138: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    level_properties_push(rdram, ctx);
        goto after_30;
    // 0x8005D138: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_30:
    // 0x8005D13C: b           L_8005D168
    // 0x8005D140: nop

        goto L_8005D168;
    // 0x8005D140: nop

L_8005D144:
    // 0x8005D144: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005D148: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005D14C: jal         0x8006C3EC
    // 0x8005D150: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    level_properties_push(rdram, ctx);
        goto after_31;
    // 0x8005D150: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_31:
    // 0x8005D154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005D158: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8005D15C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8005D160: jal         0x8006C3EC
    // 0x8005D164: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    level_properties_push(rdram, ctx);
        goto after_32;
    // 0x8005D164: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_32:
L_8005D168:
    // 0x8005D168: jal         0x8006F380
    // 0x8005D16C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    level_transition_begin(rdram, ctx);
        goto after_33;
    // 0x8005D16C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_33:
    // 0x8005D170: jal         0x8000E128
    // 0x8005D174: nop

    instShowBearBar(rdram, ctx);
        goto after_34;
    // 0x8005D174: nop

    after_34:
    // 0x8005D178: b           L_8005D1B0
    // 0x8005D17C: lb          $t6, 0x43($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X43);
        goto L_8005D1B0;
    // 0x8005D17C: lb          $t6, 0x43($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X43);
L_8005D180:
    // 0x8005D180: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005D184: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005D188: jal         0x8006C3EC
    // 0x8005D18C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    level_properties_push(rdram, ctx);
        goto after_35;
    // 0x8005D18C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_35:
    // 0x8005D190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005D194: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8005D198: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8005D19C: jal         0x8006C3EC
    // 0x8005D1A0: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    level_properties_push(rdram, ctx);
        goto after_36;
    // 0x8005D1A0: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_36:
    // 0x8005D1A4: jal         0x8006F380
    // 0x8005D1A8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    level_transition_begin(rdram, ctx);
        goto after_37;
    // 0x8005D1A8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_37:
    // 0x8005D1AC: lb          $t6, 0x43($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X43);
L_8005D1B0:
    // 0x8005D1B0: nop

    // 0x8005D1B4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8005D1B8: jal         0x8009C6E4
    // 0x8005D1BC: sb          $t7, 0x43($sp)
    MEM_B(0X43, ctx->r29) = ctx->r15;
    get_save_file_index(rdram, ctx);
        goto after_38;
    // 0x8005D1BC: sb          $t7, 0x43($sp)
    MEM_B(0X43, ctx->r29) = ctx->r15;
    after_38:
    // 0x8005D1C0: jal         0x8006EE88
    // 0x8005D1C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    safe_mark_write_save_file(rdram, ctx);
        goto after_39;
    // 0x8005D1C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_39:
L_8005D1C8:
    // 0x8005D1C8: lb          $t5, 0x43($sp)
    ctx->r13 = MEM_B(ctx->r29, 0X43);
    // 0x8005D1CC: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x8005D1D0: nop

    // 0x8005D1D4: sb          $t5, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r13;
L_8005D1D8:
    // 0x8005D1D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005D1DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005D1E0: jr          $ra
    // 0x8005D1E4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8005D1E4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void fade_when_near_camera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D1E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005D1EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005D1F0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8005D1F4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8005D1F8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8005D1FC: jal         0x8001BAFC
    // 0x8005D200: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    get_racer_object(rdram, ctx);
        goto after_0;
    // 0x8005D200: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8005D204: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8005D208: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8005D20C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8005D210: jal         0x8001139C
    // 0x8005D214: sb          $t6, 0x1F7($t7)
    MEM_B(0X1F7, ctx->r15) = ctx->r14;
    get_race_countdown(rdram, ctx);
        goto after_1;
    // 0x8005D214: sb          $t6, 0x1F7($t7)
    MEM_B(0X1F7, ctx->r15) = ctx->r14;
    after_1:
    // 0x8005D218: bne         $v0, $zero, L_8005D25C
    if (ctx->r2 != 0) {
        // 0x8005D21C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005D25C;
    }
    // 0x8005D21C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005D220: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8005D224: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8005D228: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8005D22C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8005D230: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8005D234: lwc1        $f4, 0x30($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X30);
    // 0x8005D238: lwc1        $f16, 0x30($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X30);
    // 0x8005D23C: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8005D240: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8005D244: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x8005D248: nop

    // 0x8005D24C: bc1f        L_8005D258
    if (!c1cs) {
        // 0x8005D250: addiu       $t1, $zero, 0x40
        ctx->r9 = ADD32(0, 0X40);
            goto L_8005D258;
    }
    // 0x8005D250: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
    // 0x8005D254: sb          $t1, 0x1F7($t2)
    MEM_B(0X1F7, ctx->r10) = ctx->r9;
L_8005D258:
    // 0x8005D258: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005D25C:
    // 0x8005D25C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005D260: jr          $ra
    // 0x8005D264: nop

    return;
    // 0x8005D264: nop

    // 0x8005D268: nop

    // 0x8005D26C: nop

;}
RECOMP_FUNC void update_bluey(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D270: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8005D274: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8005D278: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8005D27C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8005D280: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8005D284: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005D288: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x8005D28C: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8005D290: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8005D294: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8005D298: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8005D29C: jal         0x8005CC18
    // 0x8005D2A0: addiu       $a0, $a0, -0x2C90
    ctx->r4 = ADD32(ctx->r4, -0X2C90);
    set_boss_voice_clip_offset(rdram, ctx);
        goto after_0;
    // 0x8005D2A0: addiu       $a0, $a0, -0x2C90
    ctx->r4 = ADD32(ctx->r4, -0X2C90);
    after_0:
    // 0x8005D2A4: lw          $v0, 0x74($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X74);
    // 0x8005D2A8: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x8005D2AC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8005D2B0: addiu       $v1, $zero, -0x11
    ctx->r3 = ADD32(0, -0X11);
    // 0x8005D2B4: and         $t7, $t6, $v1
    ctx->r15 = ctx->r14 & ctx->r3;
    // 0x8005D2B8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8005D2BC: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8005D2C0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005D2C4: and         $t9, $t8, $v1
    ctx->r25 = ctx->r24 & ctx->r3;
    // 0x8005D2C8: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8005D2CC: lb          $t2, 0x3B($s1)
    ctx->r10 = MEM_B(ctx->r17, 0X3B);
    // 0x8005D2D0: nop

    // 0x8005D2D4: sh          $t2, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r10;
    // 0x8005D2D8: lh          $t3, 0x18($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X18);
    // 0x8005D2DC: nop

    // 0x8005D2E0: sh          $t3, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r11;
    // 0x8005D2E4: lh          $t4, 0x16A($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X16A);
    // 0x8005D2E8: nop

    // 0x8005D2EC: sh          $t4, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r12;
    // 0x8005D2F0: lb          $t5, 0x1D8($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1D8);
    // 0x8005D2F4: nop

    // 0x8005D2F8: bne         $t5, $at, L_8005D32C
    if (ctx->r13 != ctx->r1) {
        // 0x8005D2FC: lw          $t1, 0x78($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X78);
            goto L_8005D32C;
    }
    // 0x8005D2FC: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x8005D300: jal         0x8002359C
    // 0x8005D304: nop

    func_80023568(rdram, ctx);
        goto after_1;
    // 0x8005D304: nop

    after_1:
    // 0x8005D308: beq         $v0, $zero, L_8005D32C
    if (ctx->r2 == 0) {
        // 0x8005D30C: lw          $t1, 0x78($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X78);
            goto L_8005D32C;
    }
    // 0x8005D30C: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x8005D310: jal         0x80021434
    // 0x8005D314: addiu       $a0, $zero, 0x82
    ctx->r4 = ADD32(0, 0X82);
    func_80021400(rdram, ctx);
        goto after_2;
    // 0x8005D314: addiu       $a0, $zero, 0x82
    ctx->r4 = ADD32(0, 0X82);
    after_2:
    // 0x8005D318: lb          $t6, 0x1D8($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D8);
    // 0x8005D31C: nop

    // 0x8005D320: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8005D324: sb          $t7, 0x1D8($s0)
    MEM_B(0X1D8, ctx->r16) = ctx->r15;
    // 0x8005D328: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
L_8005D32C:
    // 0x8005D32C: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x8005D330: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x8005D334: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x8005D338: bne         $v1, $a0, L_8005D344
    if (ctx->r3 != ctx->r4) {
        // 0x8005D33C: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8005D344;
    }
    // 0x8005D33C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005D340: sb          $zero, -0x24B0($at)
    MEM_B(-0X24B0, ctx->r1) = 0;
L_8005D344:
    // 0x8005D344: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x8005D348: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8005D34C: bne         $t0, $t8, L_8005D3CC
    if (ctx->r8 != ctx->r24) {
        // 0x8005D350: nop
    
            goto L_8005D3CC;
    }
    // 0x8005D350: nop

    // 0x8005D354: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x8005D358: nop

    // 0x8005D35C: beq         $a0, $v0, L_8005D3CC
    if (ctx->r4 == ctx->r2) {
        // 0x8005D360: addiu       $t9, $v0, -0xF
        ctx->r25 = ADD32(ctx->r2, -0XF);
            goto L_8005D3CC;
    }
    // 0x8005D360: addiu       $t9, $v0, -0xF
    ctx->r25 = ADD32(ctx->r2, -0XF);
    // 0x8005D364: bgez        $t9, L_8005D3C4
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8005D368: sw          $t9, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r25;
            goto L_8005D3C4;
    }
    // 0x8005D368: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8005D36C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8005D370: lb          $t3, -0x24AF($t3)
    ctx->r11 = MEM_B(ctx->r11, -0X24AF);
    // 0x8005D374: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005D378: bne         $t3, $zero, L_8005D3A4
    if (ctx->r11 != 0) {
        // 0x8005D37C: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_8005D3A4;
    }
    // 0x8005D37C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8005D380: jal         0x8005CCA4
    // 0x8005D384: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    play_random_boss_sound(rdram, ctx);
        goto after_3;
    // 0x8005D384: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    after_3:
    // 0x8005D388: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x8005D38C: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x8005D390: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8005D394: sb          $t4, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r12;
    // 0x8005D398: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x8005D39C: nop

    // 0x8005D3A0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
L_8005D3A4:
    // 0x8005D3A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005D3A8: sb          $t5, -0x24AF($at)
    MEM_B(-0X24AF, ctx->r1) = ctx->r13;
    // 0x8005D3AC: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x8005D3B0: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8005D3B4: nop

    // 0x8005D3B8: ori         $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 | 0X8000;
    // 0x8005D3BC: b           L_8005D3CC
    // 0x8005D3C0: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
        goto L_8005D3CC;
    // 0x8005D3C0: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
L_8005D3C4:
    // 0x8005D3C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005D3C8: sb          $zero, -0x24AF($at)
    MEM_B(-0X24AF, ctx->r1) = 0;
L_8005D3CC:
    // 0x8005D3CC: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8005D3D0: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x8005D3D4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8005D3D8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8005D3DC: jal         0x8004F834
    // 0x8005D3E0: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    func_8004F7F4(rdram, ctx);
        goto after_4;
    // 0x8005D3E0: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    after_4:
    // 0x8005D3E4: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x8005D3E8: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x8005D3EC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005D3F0: sw          $v1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r3;
    // 0x8005D3F4: swc1        $f16, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f16.u32l;
    // 0x8005D3F8: lh          $t8, 0x5A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X5A);
    // 0x8005D3FC: nop

    // 0x8005D400: sh          $t8, 0x16A($s0)
    MEM_H(0X16A, ctx->r16) = ctx->r24;
    // 0x8005D404: lh          $t9, 0x5E($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X5E);
    // 0x8005D408: nop

    // 0x8005D40C: sb          $t9, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r25;
    // 0x8005D410: lh          $t2, 0x5C($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X5C);
    // 0x8005D414: nop

    // 0x8005D418: sh          $t2, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r10;
    // 0x8005D41C: lb          $t3, 0x187($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X187);
    // 0x8005D420: nop

    // 0x8005D424: beq         $t3, $zero, L_8005D4B4
    if (ctx->r11 == 0) {
        // 0x8005D428: nop
    
            goto L_8005D4B4;
    }
    // 0x8005D428: nop

    // 0x8005D42C: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005D430: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8005D434: beq         $v1, $at, L_8005D4B4
    if (ctx->r3 == ctx->r1) {
        // 0x8005D438: addiu       $t4, $zero, 0x4
        ctx->r12 = ADD32(0, 0X4);
            goto L_8005D4B4;
    }
    // 0x8005D438: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8005D43C: sb          $v1, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r3;
    // 0x8005D440: sb          $t4, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r12;
    // 0x8005D444: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x8005D448: jal         0x8005CCA4
    // 0x8005D44C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    play_random_boss_sound(rdram, ctx);
        goto after_5;
    // 0x8005D44C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x8005D450: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    // 0x8005D454: jal         0x80001D04
    // 0x8005D458: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_6;
    // 0x8005D458: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x8005D45C: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8005D460: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8005D464: jal         0x8006A168
    // 0x8005D468: nop

    set_camera_shake(rdram, ctx);
        goto after_7;
    // 0x8005D468: nop

    after_7:
    // 0x8005D46C: sb          $zero, 0x187($s0)
    MEM_B(0X187, ctx->r16) = 0;
    // 0x8005D470: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005D474: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005D478: lwc1        $f9, 0x6FC0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6FC0);
    // 0x8005D47C: lwc1        $f8, 0x6FC4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6FC4);
    // 0x8005D480: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005D484: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8005D488: lui         $at, 0x401E
    ctx->r1 = S32(0X401E << 16);
    // 0x8005D48C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8005D490: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8005D494: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8005D498: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
    // 0x8005D49C: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8005D4A0: nop

    // 0x8005D4A4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005D4A8: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x8005D4AC: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8005D4B0: swc1        $f18, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f18.u32l;
L_8005D4B4:
    // 0x8005D4B4: lw          $t5, 0x148($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X148);
    // 0x8005D4B8: nop

    // 0x8005D4BC: beq         $t5, $zero, L_8005D4F8
    if (ctx->r13 == 0) {
        // 0x8005D4C0: nop
    
            goto L_8005D4F8;
    }
    // 0x8005D4C0: nop

    // 0x8005D4C4: lwc1        $f0, 0x1C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8005D4C8: lwc1        $f2, 0x24($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8005D4CC: mul.s       $f20, $f0, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8005D4D0: nop

    // 0x8005D4D4: mul.s       $f14, $f2, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8005D4D8: nop

    // 0x8005D4DC: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8005D4E0: nop

    // 0x8005D4E4: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8005D4E8: jal         0x800CA030
    // 0x8005D4EC: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_8;
    // 0x8005D4EC: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_8:
    // 0x8005D4F0: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x8005D4F4: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
L_8005D4F8:
    // 0x8005D4F8: lb          $a0, 0x192($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X192);
    // 0x8005D4FC: lbu         $a1, 0x1C8($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1C8);
    // 0x8005D500: jal         0x8001BA50
    // 0x8005D504: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    find_next_checkpoint_node(rdram, ctx);
        goto after_9;
    // 0x8005D504: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    after_9:
    // 0x8005D508: lb          $t6, 0x1CA($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1CA);
    // 0x8005D50C: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x8005D510: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x8005D514: lb          $t8, 0x36($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X36);
    // 0x8005D518: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005D51C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005D520: bne         $t8, $at, L_8005D52C
    if (ctx->r24 != ctx->r1) {
        // 0x8005D524: addiu       $t0, $zero, -0x1
        ctx->r8 = ADD32(0, -0X1);
            goto L_8005D52C;
    }
    // 0x8005D524: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8005D528: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8005D52C:
    // 0x8005D52C: lb          $t9, 0x3B($s1)
    ctx->r25 = MEM_B(ctx->r17, 0X3B);
    // 0x8005D530: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8005D534: beq         $t9, $at, L_8005D6C4
    if (ctx->r25 == ctx->r1) {
        // 0x8005D538: nop
    
            goto L_8005D6C4;
    }
    // 0x8005D538: nop

    // 0x8005D53C: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005D540: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8005D544: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8005D548: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005D54C: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x8005D550: c.lt.d      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.d < ctx->f18.d;
    // 0x8005D554: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005D558: bc1f        L_8005D634
    if (!c1cs) {
        // 0x8005D55C: nop
    
            goto L_8005D634;
    }
    // 0x8005D55C: nop

    // 0x8005D560: beq         $v1, $zero, L_8005D5F4
    if (ctx->r3 == 0) {
        // 0x8005D564: addiu       $t3, $zero, 0x3
        ctx->r11 = ADD32(0, 0X3);
            goto L_8005D5F4;
    }
    // 0x8005D564: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8005D568: lbu         $t2, 0x1CD($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X1CD);
    // 0x8005D56C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8005D570: beq         $t2, $at, L_8005D584
    if (ctx->r10 == ctx->r1) {
        // 0x8005D574: lui         $at, 0x4220
        ctx->r1 = S32(0X4220 << 16);
            goto L_8005D584;
    }
    // 0x8005D574: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8005D578: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8005D57C: nop

    // 0x8005D580: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
L_8005D584:
    // 0x8005D584: sb          $t3, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r11;
    // 0x8005D588: lb          $v0, 0x1E1($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1E1);
    // 0x8005D58C: addiu       $t5, $zero, 0x28
    ctx->r13 = ADD32(0, 0X28);
    // 0x8005D590: sll         $t4, $v0, 1
    ctx->r12 = S32(ctx->r2 << 1);
    // 0x8005D594: subu        $v0, $t5, $t4
    ctx->r2 = SUB32(ctx->r13, ctx->r12);
    // 0x8005D598: bgez        $v0, L_8005D5A8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8005D59C: slti        $at, $v0, 0x4A
        ctx->r1 = SIGNED(ctx->r2) < 0X4A ? 1 : 0;
            goto L_8005D5A8;
    }
    // 0x8005D59C: slti        $at, $v0, 0x4A
    ctx->r1 = SIGNED(ctx->r2) < 0X4A ? 1 : 0;
    // 0x8005D5A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005D5A4: slti        $at, $v0, 0x4A
    ctx->r1 = SIGNED(ctx->r2) < 0X4A ? 1 : 0;
L_8005D5A8:
    // 0x8005D5A8: bne         $at, $zero, L_8005D5B4
    if (ctx->r1 != 0) {
        // 0x8005D5AC: nop
    
            goto L_8005D5B4;
    }
    // 0x8005D5AC: nop

    // 0x8005D5B0: addiu       $v0, $zero, 0x49
    ctx->r2 = ADD32(0, 0X49);
L_8005D5B4:
    // 0x8005D5B4: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8005D5B8: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005D5BC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8005D5C0: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x8005D5C4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8005D5C8: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8005D5CC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005D5D0: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8005D5D4: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x8005D5D8: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x8005D5DC: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8005D5E0: sb          $t6, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r14;
    // 0x8005D5E4: add.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d + ctx->f6.d;
    // 0x8005D5E8: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8005D5EC: b           L_8005D6E0
    // 0x8005D5F0: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
        goto L_8005D6E0;
    // 0x8005D5F0: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
L_8005D5F4:
    // 0x8005D5F4: sb          $zero, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = 0;
    // 0x8005D5F8: sb          $zero, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = 0;
    // 0x8005D5FC: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8005D600: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005D604: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8005D608: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8005D60C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8005D610: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005D614: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005D618: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8005D61C: mul.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x8005D620: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x8005D624: sub.d       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f6.d - ctx->f4.d;
    // 0x8005D628: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8005D62C: b           L_8005D6E0
    // 0x8005D630: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
        goto L_8005D6E0;
    // 0x8005D630: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
L_8005D634:
    // 0x8005D634: lwc1        $f9, 0x6FC8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6FC8);
    // 0x8005D638: lwc1        $f8, 0x6FCC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6FCC);
    // 0x8005D63C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005D640: c.lt.d      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.d < ctx->f8.d;
    // 0x8005D644: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8005D648: bc1t        L_8005D66C
    if (c1cs) {
        // 0x8005D64C: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8005D66C;
    }
    // 0x8005D64C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8005D650: lwc1        $f7, 0x6FD0($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6FD0);
    // 0x8005D654: lwc1        $f6, 0x6FD4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6FD4);
    // 0x8005D658: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8005D65C: c.lt.d      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.d < ctx->f0.d;
    // 0x8005D660: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x8005D664: bc1f        L_8005D69C
    if (!c1cs) {
        // 0x8005D668: nop
    
            goto L_8005D69C;
    }
    // 0x8005D668: nop

L_8005D66C:
    // 0x8005D66C: sb          $t7, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r15;
    // 0x8005D670: sb          $t8, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r24;
    // 0x8005D674: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8005D678: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005D67C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8005D680: mul.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8005D684: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8005D688: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005D68C: mul.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x8005D690: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8005D694: b           L_8005D6E0
    // 0x8005D698: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
        goto L_8005D6E0;
    // 0x8005D698: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
L_8005D69C:
    // 0x8005D69C: sb          $t9, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r25;
    // 0x8005D6A0: sb          $t2, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r10;
    // 0x8005D6A4: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005D6A8: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8005D6AC: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x8005D6B0: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005D6B4: add.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d + ctx->f6.d;
    // 0x8005D6B8: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8005D6BC: b           L_8005D6E0
    // 0x8005D6C0: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
        goto L_8005D6E0;
    // 0x8005D6C0: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
L_8005D6C4:
    // 0x8005D6C4: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005D6C8: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8005D6CC: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8005D6D0: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8005D6D4: add.d       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f8.d + ctx->f10.d;
    // 0x8005D6D8: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8005D6DC: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
L_8005D6E0:
    // 0x8005D6E0: lw          $t3, 0x68($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X68);
    // 0x8005D6E4: lb          $t5, 0x3B($s1)
    ctx->r13 = MEM_B(ctx->r17, 0X3B);
    // 0x8005D6E8: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x8005D6EC: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x8005D6F0: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8005D6F4: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005D6F8: lw          $t4, 0x44($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X44);
    // 0x8005D6FC: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8005D700: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x8005D704: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8005D708: nop

    // 0x8005D70C: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x8005D710: addiu       $t2, $t9, -0x11
    ctx->r10 = ADD32(ctx->r25, -0X11);
    // 0x8005D714: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x8005D718: bc1f        L_8005D744
    if (!c1cs) {
        // 0x8005D71C: cvt.s.w     $f20, $f6
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8005D744;
    }
    // 0x8005D71C: cvt.s.w     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.fl = CVT_S_W(ctx->f6.u32l);
L_8005D720:
    // 0x8005D720: add.s       $f8, $f0, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x8005D724: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x8005D728: sh          $t0, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r8;
    // 0x8005D72C: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005D730: nop

    // 0x8005D734: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8005D738: nop

    // 0x8005D73C: bc1t        L_8005D720
    if (c1cs) {
        // 0x8005D740: nop
    
            goto L_8005D720;
    }
    // 0x8005D740: nop

L_8005D744:
    // 0x8005D744: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x8005D748: nop

    // 0x8005D74C: bc1f        L_8005D778
    if (!c1cs) {
        // 0x8005D750: nop
    
            goto L_8005D778;
    }
    // 0x8005D750: nop

L_8005D754:
    // 0x8005D754: sub.s       $f10, $f0, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x8005D758: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x8005D75C: sh          $t0, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r8;
    // 0x8005D760: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005D764: nop

    // 0x8005D768: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x8005D76C: nop

    // 0x8005D770: bc1t        L_8005D754
    if (c1cs) {
        // 0x8005D774: nop
    
            goto L_8005D754;
    }
    // 0x8005D774: nop

L_8005D778:
    // 0x8005D778: lh          $t3, 0x10($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X10);
    // 0x8005D77C: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005D780: bne         $t0, $t3, L_8005D7A8
    if (ctx->r8 != ctx->r11) {
        // 0x8005D784: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8005D7A8;
    }
    // 0x8005D784: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8005D788: bne         $v1, $at, L_8005D7A8
    if (ctx->r3 != ctx->r1) {
        // 0x8005D78C: nop
    
            goto L_8005D7A8;
    }
    // 0x8005D78C: nop

    // 0x8005D790: lbu         $t5, 0x1CD($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X1CD);
    // 0x8005D794: nop

    // 0x8005D798: sb          $t5, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r13;
    // 0x8005D79C: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005D7A0: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005D7A4: nop

L_8005D7A8:
    // 0x8005D7A8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8005D7AC: lh          $t4, 0x18($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X18);
    // 0x8005D7B0: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8005D7B4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005D7B8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005D7BC: sh          $t4, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r12;
    // 0x8005D7C0: cvt.w.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = CVT_W_S(ctx->f0.fl);
    // 0x8005D7C4: sw          $zero, 0x74($s1)
    MEM_W(0X74, ctx->r17) = 0;
    // 0x8005D7C8: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x8005D7CC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8005D7D0: bne         $v1, $zero, L_8005D804
    if (ctx->r3 != 0) {
        // 0x8005D7D4: sh          $t7, 0x18($s1)
        MEM_H(0X18, ctx->r17) = ctx->r15;
            goto L_8005D804;
    }
    // 0x8005D7D4: sh          $t7, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r15;
    // 0x8005D7D8: lh          $a2, 0x5C($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X5C);
    // 0x8005D7DC: addiu       $t8, $zero, 0xAD
    ctx->r24 = ADD32(0, 0XAD);
    // 0x8005D7E0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8005D7E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005D7E8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8005D7EC: jal         0x800113CC
    // 0x8005D7F0: addiu       $a3, $zero, 0xAC
    ctx->r7 = ADD32(0, 0XAC);
    play_footstep_sounds(rdram, ctx);
        goto after_10;
    // 0x8005D7F0: addiu       $a3, $zero, 0xAC
    ctx->r7 = ADD32(0, 0XAC);
    after_10:
    // 0x8005D7F4: lw          $t9, 0x74($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X74);
    // 0x8005D7F8: nop

    // 0x8005D7FC: ori         $t2, $t9, 0x3
    ctx->r10 = ctx->r25 | 0X3;
    // 0x8005D800: sw          $t2, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r10;
L_8005D804:
    // 0x8005D804: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x8005D808: jal         0x800B019C
    // 0x8005D80C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    obj_spawn_particle(rdram, ctx);
        goto after_11;
    // 0x8005D80C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x8005D810: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005D814: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8005D818: jal         0x8005D1E8
    // 0x8005D81C: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    fade_when_near_camera(rdram, ctx);
        goto after_12;
    // 0x8005D81C: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_12:
    // 0x8005D820: jal         0x8001BAFC
    // 0x8005D824: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    get_racer_object(rdram, ctx);
        goto after_13;
    // 0x8005D824: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_13:
    // 0x8005D828: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8005D82C: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8005D830: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8005D834: lwc1        $f10, 0x14($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8005D838: sub.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8005D83C: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8005D840: mul.s       $f18, $f20, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8005D844: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8005D848: swc1        $f14, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f14.u32l;
    // 0x8005D84C: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8005D850: jal         0x800CA030
    // 0x8005D854: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_14;
    // 0x8005D854: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_14:
    // 0x8005D858: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005D85C: lwc1        $f9, 0x6FD8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6FD8);
    // 0x8005D860: lwc1        $f8, 0x6FDC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6FDC);
    // 0x8005D864: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8005D868: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x8005D86C: lwc1        $f14, 0x50($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8005D870: bc1f        L_8005D8E0
    if (!c1cs) {
        // 0x8005D874: nop
    
            goto L_8005D8E0;
    }
    // 0x8005D874: nop

    // 0x8005D878: jal         0x80070990
    // 0x8005D87C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    arctan2_f(rdram, ctx);
        goto after_15;
    // 0x8005D87C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_15:
    // 0x8005D880: lh          $t3, 0x0($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X0);
    // 0x8005D884: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8005D888: andi        $t5, $t3, 0xFFFF
    ctx->r13 = ctx->r11 & 0XFFFF;
    // 0x8005D88C: subu        $v1, $v0, $t5
    ctx->r3 = SUB32(ctx->r2, ctx->r13);
    // 0x8005D890: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
    // 0x8005D894: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8005D898: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8005D89C: bne         $at, $zero, L_8005D8AC
    if (ctx->r1 != 0) {
        // 0x8005D8A0: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8005D8AC;
    }
    // 0x8005D8A0: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8005D8A4: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8005D8A8: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8005D8AC:
    // 0x8005D8AC: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x8005D8B0: beq         $at, $zero, L_8005D8BC
    if (ctx->r1 == 0) {
        // 0x8005D8B4: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8005D8BC;
    }
    // 0x8005D8B4: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8005D8B8: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8005D8BC:
    // 0x8005D8BC: slti        $at, $v1, 0xC01
    ctx->r1 = SIGNED(ctx->r3) < 0XC01 ? 1 : 0;
    // 0x8005D8C0: bne         $at, $zero, L_8005D8D0
    if (ctx->r1 != 0) {
        // 0x8005D8C4: slti        $at, $v1, -0xC00
        ctx->r1 = SIGNED(ctx->r3) < -0XC00 ? 1 : 0;
            goto L_8005D8D0;
    }
    // 0x8005D8C4: slti        $at, $v1, -0xC00
    ctx->r1 = SIGNED(ctx->r3) < -0XC00 ? 1 : 0;
    // 0x8005D8C8: addiu       $v1, $zero, 0xC00
    ctx->r3 = ADD32(0, 0XC00);
    // 0x8005D8CC: slti        $at, $v1, -0xC00
    ctx->r1 = SIGNED(ctx->r3) < -0XC00 ? 1 : 0;
L_8005D8D0:
    // 0x8005D8D0: beq         $at, $zero, L_8005D8DC
    if (ctx->r1 == 0) {
        // 0x8005D8D4: nop
    
            goto L_8005D8DC;
    }
    // 0x8005D8D4: nop

    // 0x8005D8D8: addiu       $v1, $zero, -0xC00
    ctx->r3 = ADD32(0, -0XC00);
L_8005D8DC:
    // 0x8005D8DC: sh          $v1, 0x16C($s0)
    MEM_H(0X16C, ctx->r16) = ctx->r3;
L_8005D8E0:
    // 0x8005D8E0: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005D8E4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005D8E8: bne         $v1, $at, L_8005D920
    if (ctx->r3 != ctx->r1) {
        // 0x8005D8EC: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_8005D920;
    }
    // 0x8005D8EC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8005D8F0: lb          $t4, 0x1E7($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1E7);
    // 0x8005D8F4: nop

    // 0x8005D8F8: andi        $t6, $t4, 0x1F
    ctx->r14 = ctx->r12 & 0X1F;
    // 0x8005D8FC: slti        $at, $t6, 0xA
    ctx->r1 = SIGNED(ctx->r14) < 0XA ? 1 : 0;
    // 0x8005D900: beq         $at, $zero, L_8005D924
    if (ctx->r1 == 0) {
        // 0x8005D904: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8005D924;
    }
    // 0x8005D904: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8005D908: lh          $t7, 0x16C($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X16C);
    // 0x8005D90C: nop

    // 0x8005D910: sra         $t8, $t7, 1
    ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
    // 0x8005D914: sh          $t8, 0x16C($s0)
    MEM_H(0X16C, ctx->r16) = ctx->r24;
    // 0x8005D918: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005D91C: nop

L_8005D920:
    // 0x8005D920: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_8005D924:
    // 0x8005D924: bne         $v1, $at, L_8005D930
    if (ctx->r3 != ctx->r1) {
        // 0x8005D928: addiu       $a1, $a1, -0x24B0
        ctx->r5 = ADD32(ctx->r5, -0X24B0);
            goto L_8005D930;
    }
    // 0x8005D928: addiu       $a1, $a1, -0x24B0
    ctx->r5 = ADD32(ctx->r5, -0X24B0);
    // 0x8005D92C: sh          $zero, 0x16C($s0)
    MEM_H(0X16C, ctx->r16) = 0;
L_8005D930:
    // 0x8005D930: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8005D934: nop

    // 0x8005D938: lw          $v0, 0x4C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4C);
    // 0x8005D93C: lw          $s0, 0x64($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X64);
    // 0x8005D940: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8005D944: nop

    // 0x8005D948: bne         $s1, $t9, L_8005D978
    if (ctx->r17 != ctx->r25) {
        // 0x8005D94C: nop
    
            goto L_8005D978;
    }
    // 0x8005D94C: nop

    // 0x8005D950: lh          $t2, 0x14($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X14);
    // 0x8005D954: nop

    // 0x8005D958: andi        $t3, $t2, 0x8
    ctx->r11 = ctx->r10 & 0X8;
    // 0x8005D95C: beq         $t3, $zero, L_8005D978
    if (ctx->r11 == 0) {
        // 0x8005D960: nop
    
            goto L_8005D978;
    }
    // 0x8005D960: nop

    // 0x8005D964: lb          $t5, 0x3B($s1)
    ctx->r13 = MEM_B(ctx->r17, 0X3B);
    // 0x8005D968: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005D96C: bne         $t5, $at, L_8005D978
    if (ctx->r13 != ctx->r1) {
        // 0x8005D970: addiu       $t4, $zero, 0x4
        ctx->r12 = ADD32(0, 0X4);
            goto L_8005D978;
    }
    // 0x8005D970: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8005D974: sb          $t4, 0x187($s0)
    MEM_B(0X187, ctx->r16) = ctx->r12;
L_8005D978:
    // 0x8005D978: lb          $t6, 0x1D8($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D8);
    // 0x8005D97C: nop

    // 0x8005D980: beq         $t6, $zero, L_8005D9A4
    if (ctx->r14 == 0) {
        // 0x8005D984: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8005D9A4;
    }
    // 0x8005D984: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8005D988: lb          $t7, 0x0($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X0);
    // 0x8005D98C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8005D990: bne         $t7, $zero, L_8005D9A0
    if (ctx->r15 != 0) {
        // 0x8005D994: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8005D9A0;
    }
    // 0x8005D994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005D998: jal         0x8005CD08
    // 0x8005D99C: sb          $t8, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r24;
    racer_boss_finish(rdram, ctx);
        goto after_16;
    // 0x8005D99C: sb          $t8, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r24;
    after_16:
L_8005D9A0:
    // 0x8005D9A0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8005D9A4:
    // 0x8005D9A4: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8005D9A8: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8005D9AC: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8005D9B0: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8005D9B4: jr          $ra
    // 0x8005D9B8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8005D9B8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8005D9BC: nop

;}
RECOMP_FUNC void update_smokey(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D9C0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8005D9C4: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8005D9C8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8005D9CC: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8005D9D0: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8005D9D4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005D9D8: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x8005D9DC: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8005D9E0: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8005D9E4: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8005D9E8: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8005D9EC: jal         0x8005CC18
    // 0x8005D9F0: addiu       $a0, $a0, -0x2C70
    ctx->r4 = ADD32(ctx->r4, -0X2C70);
    set_boss_voice_clip_offset(rdram, ctx);
        goto after_0;
    // 0x8005D9F0: addiu       $a0, $a0, -0x2C70
    ctx->r4 = ADD32(ctx->r4, -0X2C70);
    after_0:
    // 0x8005D9F4: lb          $t6, 0x3B($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X3B);
    // 0x8005D9F8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005D9FC: sh          $t6, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r14;
    // 0x8005DA00: lh          $t7, 0x16A($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X16A);
    // 0x8005DA04: lh          $t2, 0x18($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X18);
    // 0x8005DA08: sh          $t7, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r15;
    // 0x8005DA0C: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005DA10: lwc1        $f7, 0x6FE0($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6FE0);
    // 0x8005DA14: lwc1        $f6, 0x6FE4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6FE4);
    // 0x8005DA18: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x8005DA1C: c.lt.d      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.d < ctx->f6.d;
    // 0x8005DA20: nop

    // 0x8005DA24: bc1f        L_8005DA4C
    if (!c1cs) {
        // 0x8005DA28: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8005DA4C;
    }
    // 0x8005DA28: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005DA2C: lwc1        $f9, 0x6FE8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6FE8);
    // 0x8005DA30: lwc1        $f8, 0x6FEC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6FEC);
    // 0x8005DA34: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x8005DA38: c.lt.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d < ctx->f0.d;
    // 0x8005DA3C: nop

    // 0x8005DA40: bc1f        L_8005DA4C
    if (!c1cs) {
        // 0x8005DA44: nop
    
            goto L_8005DA4C;
    }
    // 0x8005DA44: nop

    // 0x8005DA48: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
L_8005DA4C:
    // 0x8005DA4C: lb          $t9, 0x1D8($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1D8);
    // 0x8005DA50: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005DA54: bne         $t9, $at, L_8005DA8C
    if (ctx->r25 != ctx->r1) {
        // 0x8005DA58: lw          $t0, 0x78($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X78);
            goto L_8005DA8C;
    }
    // 0x8005DA58: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x8005DA5C: jal         0x8002359C
    // 0x8005DA60: sh          $t2, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r10;
    func_80023568(rdram, ctx);
        goto after_1;
    // 0x8005DA60: sh          $t2, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r10;
    after_1:
    // 0x8005DA64: lh          $t2, 0x5C($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X5C);
    // 0x8005DA68: beq         $v0, $zero, L_8005DA88
    if (ctx->r2 == 0) {
        // 0x8005DA6C: addiu       $a0, $zero, 0x82
        ctx->r4 = ADD32(0, 0X82);
            goto L_8005DA88;
    }
    // 0x8005DA6C: addiu       $a0, $zero, 0x82
    ctx->r4 = ADD32(0, 0X82);
    // 0x8005DA70: jal         0x80021434
    // 0x8005DA74: sh          $t2, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r10;
    func_80021400(rdram, ctx);
        goto after_2;
    // 0x8005DA74: sh          $t2, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r10;
    after_2:
    // 0x8005DA78: lb          $t3, 0x1D8($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1D8);
    // 0x8005DA7C: lh          $t2, 0x5C($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X5C);
    // 0x8005DA80: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8005DA84: sb          $t4, 0x1D8($s0)
    MEM_B(0X1D8, ctx->r16) = ctx->r12;
L_8005DA88:
    // 0x8005DA88: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
L_8005DA8C:
    // 0x8005DA8C: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x8005DA90: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8005DA94: nop

    // 0x8005DA98: bne         $v1, $a0, L_8005DAA4
    if (ctx->r3 != ctx->r4) {
        // 0x8005DA9C: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8005DAA4;
    }
    // 0x8005DA9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005DAA0: sb          $zero, -0x24A0($at)
    MEM_B(-0X24A0, ctx->r1) = 0;
L_8005DAA4:
    // 0x8005DAA4: lh          $t5, 0x0($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X0);
    // 0x8005DAA8: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8005DAAC: bne         $t1, $t5, L_8005DB34
    if (ctx->r9 != ctx->r13) {
        // 0x8005DAB0: addiu       $t6, $zero, 0x7
        ctx->r14 = ADD32(0, 0X7);
            goto L_8005DB34;
    }
    // 0x8005DAB0: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x8005DAB4: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8005DAB8: nop

    // 0x8005DABC: beq         $a0, $v0, L_8005DB30
    if (ctx->r4 == ctx->r2) {
        // 0x8005DAC0: addiu       $t6, $v0, -0x3C
        ctx->r14 = ADD32(ctx->r2, -0X3C);
            goto L_8005DB30;
    }
    // 0x8005DAC0: addiu       $t6, $v0, -0x3C
    ctx->r14 = ADD32(ctx->r2, -0X3C);
    // 0x8005DAC4: bgez        $t6, L_8005DB28
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8005DAC8: sw          $t6, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r14;
            goto L_8005DB28;
    }
    // 0x8005DAC8: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x8005DACC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8005DAD0: lb          $t8, -0x249F($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X249F);
    // 0x8005DAD4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005DAD8: bne         $t8, $zero, L_8005DB04
    if (ctx->r24 != 0) {
        // 0x8005DADC: lw          $v0, 0x70($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X70);
            goto L_8005DB04;
    }
    // 0x8005DADC: lw          $v0, 0x70($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X70);
    // 0x8005DAE0: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x8005DAE4: jal         0x8005CCA4
    // 0x8005DAE8: sh          $t2, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r10;
    play_random_boss_sound(rdram, ctx);
        goto after_3;
    // 0x8005DAE8: sh          $t2, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r10;
    after_3:
    // 0x8005DAEC: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x8005DAF0: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x8005DAF4: lh          $t2, 0x5C($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X5C);
    // 0x8005DAF8: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x8005DAFC: sb          $t9, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r25;
    // 0x8005DB00: lw          $v0, 0x70($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X70);
L_8005DB04:
    // 0x8005DB04: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8005DB08: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005DB0C: sb          $t3, -0x249F($at)
    MEM_B(-0X249F, ctx->r1) = ctx->r11;
    // 0x8005DB10: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x8005DB14: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8005DB18: nop

    // 0x8005DB1C: ori         $t5, $t4, 0x8000
    ctx->r13 = ctx->r12 | 0X8000;
    // 0x8005DB20: b           L_8005DB30
    // 0x8005DB24: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
        goto L_8005DB30;
    // 0x8005DB24: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_8005DB28:
    // 0x8005DB28: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005DB2C: sb          $zero, -0x249F($at)
    MEM_B(-0X249F, ctx->r1) = 0;
L_8005DB30:
    // 0x8005DB30: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
L_8005DB34:
    // 0x8005DB34: sb          $t6, 0x1D6($s0)
    MEM_B(0X1D6, ctx->r16) = ctx->r14;
    // 0x8005DB38: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x8005DB3C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8005DB40: sh          $t2, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r10;
    // 0x8005DB44: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x8005DB48: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8005DB4C: jal         0x800497D4
    // 0x8005DB50: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_80049794(rdram, ctx);
        goto after_4;
    // 0x8005DB50: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_4:
    // 0x8005DB54: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x8005DB58: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x8005DB5C: lb          $t7, 0x1D7($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1D7);
    // 0x8005DB60: lh          $t2, 0x5C($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X5C);
    // 0x8005DB64: sb          $t7, 0x1D6($s0)
    MEM_B(0X1D6, ctx->r16) = ctx->r15;
    // 0x8005DB68: sw          $v1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r3;
    // 0x8005DB6C: sw          $zero, 0x74($s1)
    MEM_W(0X74, ctx->r17) = 0;
    // 0x8005DB70: lh          $t8, 0x5A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X5A);
    // 0x8005DB74: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8005DB78: sh          $t8, 0x16A($s0)
    MEM_H(0X16A, ctx->r16) = ctx->r24;
    // 0x8005DB7C: lh          $t9, 0x5E($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X5E);
    // 0x8005DB80: sh          $t2, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r10;
    // 0x8005DB84: sb          $t9, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r25;
    // 0x8005DB88: lb          $t3, 0x187($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X187);
    // 0x8005DB8C: nop

    // 0x8005DB90: beq         $t3, $zero, L_8005DC34
    if (ctx->r11 == 0) {
        // 0x8005DB94: nop
    
            goto L_8005DC34;
    }
    // 0x8005DB94: nop

    // 0x8005DB98: lb          $t4, 0x3B($s1)
    ctx->r12 = MEM_B(ctx->r17, 0X3B);
    // 0x8005DB9C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8005DBA0: beq         $t4, $at, L_8005DC34
    if (ctx->r12 == ctx->r1) {
        // 0x8005DBA4: nop
    
            goto L_8005DC34;
    }
    // 0x8005DBA4: nop

    // 0x8005DBA8: jal         0x8005CCA4
    // 0x8005DBAC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    play_random_boss_sound(rdram, ctx);
        goto after_5;
    // 0x8005DBAC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x8005DBB0: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    // 0x8005DBB4: jal         0x80001D04
    // 0x8005DBB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_6;
    // 0x8005DBB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x8005DBBC: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8005DBC0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8005DBC4: jal         0x8006A168
    // 0x8005DBC8: nop

    set_camera_shake(rdram, ctx);
        goto after_7;
    // 0x8005DBC8: nop

    after_7:
    // 0x8005DBCC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005DBD0: lwc1        $f10, 0x1C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8005DBD4: lwc1        $f1, 0x6FF0($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, 0X6FF0);
    // 0x8005DBD8: lwc1        $f0, 0x6FF4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6FF4);
    // 0x8005DBDC: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8005DBE0: mul.d       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f0.d);
    // 0x8005DBE4: lwc1        $f8, 0x24($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8005DBE8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005DBEC: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8005DBF0: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x8005DBF4: mul.d       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x8005DBF8: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8005DBFC: sb          $t5, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r13;
    // 0x8005DC00: swc1        $f6, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f6.u32l;
    // 0x8005DC04: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8005DC08: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8005DC0C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8005DC10: swc1        $f4, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f4.u32l;
    // 0x8005DC14: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x8005DC18: lwc1        $f6, 0x20($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8005DC1C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005DC20: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8005DC24: add.d       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f8.d + ctx->f10.d;
    // 0x8005DC28: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8005DC2C: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8005DC30: swc1        $f4, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f4.u32l;
L_8005DC34:
    // 0x8005DC34: lw          $t6, 0x148($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X148);
    // 0x8005DC38: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005DC3C: beq         $t6, $zero, L_8005DCA8
    if (ctx->r14 == 0) {
        // 0x8005DC40: sb          $zero, 0x187($s0)
        MEM_B(0X187, ctx->r16) = 0;
            goto L_8005DCA8;
    }
    // 0x8005DC40: sb          $zero, 0x187($s0)
    MEM_B(0X187, ctx->r16) = 0;
    // 0x8005DC44: lwc1        $f0, 0x1C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8005DC48: lwc1        $f2, 0x24($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8005DC4C: mul.s       $f20, $f0, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8005DC50: nop

    // 0x8005DC54: mul.s       $f14, $f2, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8005DC58: nop

    // 0x8005DC5C: mul.s       $f6, $f20, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8005DC60: nop

    // 0x8005DC64: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8005DC68: jal         0x800CA030
    // 0x8005DC6C: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_8;
    // 0x8005DC6C: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_8:
    // 0x8005DC70: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x8005DC74: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8005DC78: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005DC7C: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x8005DC80: cvt.d.s     $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f18.d = CVT_D_S(ctx->f2.fl);
    // 0x8005DC84: c.lt.d      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.d < ctx->f18.d;
    // 0x8005DC88: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005DC8C: swc1        $f2, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f2.u32l;
    // 0x8005DC90: bc1f        L_8005DCA8
    if (!c1cs) {
        // 0x8005DC94: addiu       $t1, $zero, -0x1
        ctx->r9 = ADD32(0, -0X1);
            goto L_8005DCA8;
    }
    // 0x8005DC94: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8005DC98: swc1        $f16, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f16.u32l;
    // 0x8005DC9C: swc1        $f16, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f16.u32l;
    // 0x8005DCA0: swc1        $f16, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f16.u32l;
    // 0x8005DCA4: swc1        $f16, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f16.u32l;
L_8005DCA8:
    // 0x8005DCA8: lw          $t7, 0x68($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X68);
    // 0x8005DCAC: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005DCB0: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x8005DCB4: sll         $t9, $v1, 3
    ctx->r25 = S32(ctx->r3 << 3);
    // 0x8005DCB8: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8005DCBC: lwc1        $f12, 0x64($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8005DCC0: lw          $t8, 0x44($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X44);
    // 0x8005DCC4: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005DCC8: addu        $t3, $t8, $t9
    ctx->r11 = ADD32(ctx->r24, ctx->r25);
    // 0x8005DCCC: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x8005DCD0: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8005DCD4: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x8005DCD8: addiu       $t6, $t5, -0x11
    ctx->r14 = ADD32(ctx->r13, -0X11);
    // 0x8005DCDC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005DCE0: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8005DCE4: lwc1        $f19, 0x6FF8($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, 0X6FF8);
    // 0x8005DCE8: lwc1        $f18, 0x6FFC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6FFC);
    // 0x8005DCEC: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8005DCF0: cvt.s.w     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005DCF4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8005DCF8: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x8005DCFC: mul.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x8005DD00: cvt.s.d     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f2.fl = CVT_S_D(ctx->f4.d);
    // 0x8005DD04: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x8005DD08: c.le.d      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.d <= ctx->f6.d;
    // 0x8005DD0C: nop

    // 0x8005DD10: bc1f        L_8005DD40
    if (!c1cs) {
        // 0x8005DD14: lui         $at, 0xC000
        ctx->r1 = S32(0XC000 << 16);
            goto L_8005DD40;
    }
    // 0x8005DD14: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8005DD18: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8005DD1C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8005DD20: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8005DD24: c.lt.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d < ctx->f0.d;
    // 0x8005DD28: nop

    // 0x8005DD2C: bc1f        L_8005DD68
    if (!c1cs) {
        // 0x8005DD30: nop
    
            goto L_8005DD68;
    }
    // 0x8005DD30: nop

    // 0x8005DD34: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8005DD38: b           L_8005DD6C
    // 0x8005DD3C: sltiu       $at, $v1, 0x6
    ctx->r1 = ctx->r3 < 0X6 ? 1 : 0;
        goto L_8005DD6C;
    // 0x8005DD3C: sltiu       $at, $v1, 0x6
    ctx->r1 = ctx->r3 < 0X6 ? 1 : 0;
L_8005DD40:
    // 0x8005DD40: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8005DD44: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8005DD48: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005DD4C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8005DD50: c.lt.d      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.d < ctx->f10.d;
    // 0x8005DD54: nop

    // 0x8005DD58: bc1f        L_8005DD68
    if (!c1cs) {
        // 0x8005DD5C: nop
    
            goto L_8005DD68;
    }
    // 0x8005DD5C: nop

    // 0x8005DD60: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8005DD64: nop

L_8005DD68:
    // 0x8005DD68: sltiu       $at, $v1, 0x6
    ctx->r1 = ctx->r3 < 0X6 ? 1 : 0;
L_8005DD6C:
    // 0x8005DD6C: beq         $at, $zero, L_8005DEAC
    if (ctx->r1 == 0) {
        // 0x8005DD70: sll         $t7, $v1, 2
        ctx->r15 = S32(ctx->r3 << 2);
            goto L_8005DEAC;
    }
    // 0x8005DD70: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x8005DD74: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005DD78: addu        $at, $at, $t7
    gpr jr_addend_8005DD84 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8005DD7C: lw          $t7, 0x7000($at)
    ctx->r15 = ADD32(ctx->r1, 0X7000);
    // 0x8005DD80: nop

    // 0x8005DD84: jr          $t7
    // 0x8005DD88: nop

    switch (jr_addend_8005DD84 >> 2) {
        case 0: goto L_8005DD8C; break;
        case 1: goto L_8005DDB0; break;
        case 2: goto L_8005DDE8; break;
        case 3: goto L_8005DE04; break;
        case 4: goto L_8005DE5C; break;
        case 5: goto L_8005DE88; break;
        default: switch_error(__func__, 0x8005DD84, 0x800E7000);
    }
    // 0x8005DD88: nop

L_8005DD8C:
    // 0x8005DD8C: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005DD90: cvt.d.s     $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.d = CVT_D_S(ctx->f12.fl);
    // 0x8005DD94: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8005DD98: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x8005DD9C: sb          $zero, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = 0;
    // 0x8005DDA0: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8005DDA4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8005DDA8: b           L_8005DEB0
    // 0x8005DDAC: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
        goto L_8005DEB0;
    // 0x8005DDAC: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
L_8005DDB0:
    // 0x8005DDB0: lbu         $t8, 0x1CD($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1CD);
    // 0x8005DDB4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8005DDB8: bne         $a0, $t8, L_8005DDD4
    if (ctx->r4 != ctx->r24) {
        // 0x8005DDBC: nop
    
            goto L_8005DDD4;
    }
    // 0x8005DDBC: nop

    // 0x8005DDC0: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005DDC4: nop

    // 0x8005DDC8: add.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x8005DDCC: b           L_8005DEB0
    // 0x8005DDD0: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
        goto L_8005DEB0;
    // 0x8005DDD0: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
L_8005DDD4:
    // 0x8005DDD4: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005DDD8: nop

    // 0x8005DDDC: sub.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x8005DDE0: b           L_8005DEB0
    // 0x8005DDE4: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
        goto L_8005DEB0;
    // 0x8005DDE4: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
L_8005DDE8:
    // 0x8005DDE8: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005DDEC: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8005DDF0: sub.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x8005DDF4: sb          $t9, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r25;
    // 0x8005DDF8: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x8005DDFC: b           L_8005DEB0
    // 0x8005DE00: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
        goto L_8005DEB0;
    // 0x8005DE00: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_8005DE04:
    // 0x8005DE04: lbu         $t3, 0x1CD($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X1CD);
    // 0x8005DE08: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8005DE0C: bne         $t3, $at, L_8005DE38
    if (ctx->r11 != ctx->r1) {
        // 0x8005DE10: nop
    
            goto L_8005DE38;
    }
    // 0x8005DE10: nop

    // 0x8005DE14: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005DE18: cvt.d.s     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.d = CVT_D_S(ctx->f12.fl);
    // 0x8005DE1C: add.d       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f0.d + ctx->f0.d;
    // 0x8005DE20: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8005DE24: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005DE28: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x8005DE2C: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8005DE30: b           L_8005DEB0
    // 0x8005DE34: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
        goto L_8005DEB0;
    // 0x8005DE34: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
L_8005DE38:
    // 0x8005DE38: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005DE3C: cvt.d.s     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.d = CVT_D_S(ctx->f12.fl);
    // 0x8005DE40: add.d       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f0.d + ctx->f0.d;
    // 0x8005DE44: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005DE48: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x8005DE4C: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8005DE50: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x8005DE54: b           L_8005DEB0
    // 0x8005DE58: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
        goto L_8005DEB0;
    // 0x8005DE58: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_8005DE5C:
    // 0x8005DE5C: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005DE60: cvt.d.s     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.d = CVT_D_S(ctx->f12.fl);
    // 0x8005DE64: add.d       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f0.d + ctx->f0.d;
    // 0x8005DE68: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8005DE6C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005DE70: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x8005DE74: sb          $t4, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r12;
    // 0x8005DE78: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8005DE7C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8005DE80: b           L_8005DEB0
    // 0x8005DE84: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
        goto L_8005DEB0;
    // 0x8005DE84: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
L_8005DE88:
    // 0x8005DE88: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005DE8C: cvt.d.s     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.d = CVT_D_S(ctx->f12.fl);
    // 0x8005DE90: add.d       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f0.d + ctx->f0.d;
    // 0x8005DE94: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8005DE98: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005DE9C: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x8005DEA0: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8005DEA4: b           L_8005DEB0
    // 0x8005DEA8: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
        goto L_8005DEB0;
    // 0x8005DEA8: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
L_8005DEAC:
    // 0x8005DEAC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_8005DEB0:
    // 0x8005DEB0: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005DEB4: nop

    // 0x8005DEB8: c.le.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl <= ctx->f0.fl;
    // 0x8005DEBC: nop

    // 0x8005DEC0: bc1f        L_8005DEEC
    if (!c1cs) {
        // 0x8005DEC4: nop
    
            goto L_8005DEEC;
    }
    // 0x8005DEC4: nop

L_8005DEC8:
    // 0x8005DEC8: sub.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x8005DECC: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    // 0x8005DED0: sh          $t1, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r9;
    // 0x8005DED4: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005DED8: nop

    // 0x8005DEDC: c.le.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl <= ctx->f0.fl;
    // 0x8005DEE0: nop

    // 0x8005DEE4: bc1t        L_8005DEC8
    if (c1cs) {
        // 0x8005DEE8: nop
    
            goto L_8005DEC8;
    }
    // 0x8005DEE8: nop

L_8005DEEC:
    // 0x8005DEEC: c.le.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl <= ctx->f16.fl;
    // 0x8005DEF0: nop

    // 0x8005DEF4: bc1f        L_8005DF20
    if (!c1cs) {
        // 0x8005DEF8: nop
    
            goto L_8005DF20;
    }
    // 0x8005DEF8: nop

L_8005DEFC:
    // 0x8005DEFC: add.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x8005DF00: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x8005DF04: sh          $t1, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r9;
    // 0x8005DF08: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005DF0C: nop

    // 0x8005DF10: c.le.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl <= ctx->f16.fl;
    // 0x8005DF14: nop

    // 0x8005DF18: bc1t        L_8005DEFC
    if (c1cs) {
        // 0x8005DF1C: nop
    
            goto L_8005DEFC;
    }
    // 0x8005DF1C: nop

L_8005DF20:
    // 0x8005DF20: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005DF24: nop

    // 0x8005DF28: bne         $a0, $v1, L_8005DF70
    if (ctx->r4 != ctx->r3) {
        // 0x8005DF2C: nop
    
            goto L_8005DF70;
    }
    // 0x8005DF2C: nop

    // 0x8005DF30: lb          $t5, 0x1E2($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1E2);
    // 0x8005DF34: lui         $at, 0xC01A
    ctx->r1 = S32(0XC01A << 16);
    // 0x8005DF38: bne         $t5, $zero, L_8005DF70
    if (ctx->r13 != 0) {
        // 0x8005DF3C: nop
    
            goto L_8005DF70;
    }
    // 0x8005DF3C: nop

    // 0x8005DF40: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005DF44: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8005DF48: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005DF4C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8005DF50: c.lt.d      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.d < ctx->f18.d;
    // 0x8005DF54: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8005DF58: bc1f        L_8005DF70
    if (!c1cs) {
        // 0x8005DF5C: nop
    
            goto L_8005DF70;
    }
    // 0x8005DF5C: nop

    // 0x8005DF60: sb          $a2, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r6;
    // 0x8005DF64: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x8005DF68: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005DF6C: nop

L_8005DF70:
    // 0x8005DF70: lh          $t6, 0x10($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X10);
    // 0x8005DF74: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8005DF78: beq         $t1, $t6, L_8005DF88
    if (ctx->r9 == ctx->r14) {
        // 0x8005DF7C: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8005DF88;
    }
    // 0x8005DF7C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8005DF80: bne         $v1, $zero, L_8005E12C
    if (ctx->r3 != 0) {
        // 0x8005DF84: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8005E12C;
    }
    // 0x8005DF84: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
L_8005DF88:
    // 0x8005DF88: bne         $v1, $at, L_8005DFB0
    if (ctx->r3 != ctx->r1) {
        // 0x8005DF8C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8005DFB0;
    }
    // 0x8005DF8C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005DF90: lbu         $t7, 0x1CD($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X1CD);
    // 0x8005DF94: nop

    // 0x8005DF98: sb          $t7, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r15;
    // 0x8005DF9C: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x8005DFA0: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005DFA4: b           L_8005E130
    // 0x8005DFA8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
        goto L_8005E130;
    // 0x8005DFA8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8005DFAC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8005DFB0:
    // 0x8005DFB0: bne         $v1, $at, L_8005DFE0
    if (ctx->r3 != ctx->r1) {
        // 0x8005DFB4: nop
    
            goto L_8005DFE0;
    }
    // 0x8005DFB4: nop

    // 0x8005DFB8: lbu         $t8, 0x1CD($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1CD);
    // 0x8005DFBC: nop

    // 0x8005DFC0: bne         $t8, $zero, L_8005DFD0
    if (ctx->r24 != 0) {
        // 0x8005DFC4: nop
    
            goto L_8005DFD0;
    }
    // 0x8005DFC4: nop

    // 0x8005DFC8: b           L_8005DFD4
    // 0x8005DFCC: sb          $a0, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r4;
        goto L_8005DFD4;
    // 0x8005DFCC: sb          $a0, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r4;
L_8005DFD0:
    // 0x8005DFD0: sb          $zero, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = 0;
L_8005DFD4:
    // 0x8005DFD4: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005DFD8: b           L_8005E130
    // 0x8005DFDC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
        goto L_8005E130;
    // 0x8005DFDC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
L_8005DFE0:
    // 0x8005DFE0: bne         $a2, $v1, L_8005E010
    if (ctx->r6 != ctx->r3) {
        // 0x8005DFE4: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8005E010;
    }
    // 0x8005DFE4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005DFE8: lbu         $t9, 0x1CD($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1CD);
    // 0x8005DFEC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8005DFF0: bne         $t9, $at, L_8005E000
    if (ctx->r25 != ctx->r1) {
        // 0x8005DFF4: addiu       $t3, $zero, 0x4
        ctx->r11 = ADD32(0, 0X4);
            goto L_8005E000;
    }
    // 0x8005DFF4: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8005DFF8: b           L_8005E004
    // 0x8005DFFC: sb          $a0, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r4;
        goto L_8005E004;
    // 0x8005DFFC: sb          $a0, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r4;
L_8005E000:
    // 0x8005E000: sb          $t3, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r11;
L_8005E004:
    // 0x8005E004: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005E008: b           L_8005E130
    // 0x8005E00C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
        goto L_8005E130;
    // 0x8005E00C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
L_8005E010:
    // 0x8005E010: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005E014: lwc1        $f7, 0x7018($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X7018);
    // 0x8005E018: lwc1        $f6, 0x701C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X701C);
    // 0x8005E01C: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x8005E020: c.lt.d      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.d < ctx->f0.d;
    // 0x8005E024: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005E028: bc1f        L_8005E09C
    if (!c1cs) {
        // 0x8005E02C: nop
    
            goto L_8005E09C;
    }
    // 0x8005E02C: nop

    // 0x8005E030: lwc1        $f9, 0x7020($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X7020);
    // 0x8005E034: lwc1        $f8, 0x7024($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7024);
    // 0x8005E038: nop

    // 0x8005E03C: c.lt.d      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.d < ctx->f8.d;
    // 0x8005E040: nop

    // 0x8005E044: bc1f        L_8005E09C
    if (!c1cs) {
        // 0x8005E048: nop
    
            goto L_8005E09C;
    }
    // 0x8005E048: nop

    // 0x8005E04C: bne         $a0, $v1, L_8005E08C
    if (ctx->r4 != ctx->r3) {
        // 0x8005E050: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_8005E08C;
    }
    // 0x8005E050: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8005E054: sb          $t4, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r12;
    // 0x8005E058: lb          $t6, 0x3B($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X3B);
    // 0x8005E05C: lw          $t5, 0x44($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X44);
    // 0x8005E060: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8005E064: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x8005E068: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8005E06C: nop

    // 0x8005E070: sll         $t3, $t9, 4
    ctx->r11 = S32(ctx->r25 << 4);
    // 0x8005E074: addiu       $t4, $t3, -0x11
    ctx->r12 = ADD32(ctx->r11, -0X11);
    // 0x8005E078: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x8005E07C: nop

    // 0x8005E080: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8005E084: b           L_8005E090
    // 0x8005E088: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
        goto L_8005E090;
    // 0x8005E088: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
L_8005E08C:
    // 0x8005E08C: sb          $zero, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = 0;
L_8005E090:
    // 0x8005E090: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005E094: b           L_8005E130
    // 0x8005E098: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
        goto L_8005E130;
    // 0x8005E098: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
L_8005E09C:
    // 0x8005E09C: bne         $v1, $zero, L_8005E0B8
    if (ctx->r3 != 0) {
        // 0x8005E0A0: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8005E0B8;
    }
    // 0x8005E0A0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8005E0A4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005E0A8: sb          $t6, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r14;
    // 0x8005E0AC: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x8005E0B0: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005E0B4: nop

L_8005E0B8:
    // 0x8005E0B8: bne         $v1, $at, L_8005E12C
    if (ctx->r3 != ctx->r1) {
        // 0x8005E0BC: nop
    
            goto L_8005E12C;
    }
    // 0x8005E0BC: nop

    // 0x8005E0C0: lb          $t5, 0x1E2($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1E2);
    // 0x8005E0C4: lui         $at, 0xC018
    ctx->r1 = S32(0XC018 << 16);
    // 0x8005E0C8: beq         $t5, $zero, L_8005E12C
    if (ctx->r13 == 0) {
        // 0x8005E0CC: nop
    
            goto L_8005E12C;
    }
    // 0x8005E0CC: nop

    // 0x8005E0D0: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005E0D4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8005E0D8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005E0DC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8005E0E0: c.lt.d      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.d < ctx->f8.d;
    // 0x8005E0E4: nop

    // 0x8005E0E8: bc1f        L_8005E12C
    if (!c1cs) {
        // 0x8005E0EC: nop
    
            goto L_8005E12C;
    }
    // 0x8005E0EC: nop

    // 0x8005E0F0: sb          $a2, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r6;
    // 0x8005E0F4: lb          $t8, 0x3B($s1)
    ctx->r24 = MEM_B(ctx->r17, 0X3B);
    // 0x8005E0F8: lw          $t7, 0x44($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X44);
    // 0x8005E0FC: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8005E100: addu        $t3, $t7, $t9
    ctx->r11 = ADD32(ctx->r15, ctx->r25);
    // 0x8005E104: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x8005E108: nop

    // 0x8005E10C: sll         $t6, $t4, 4
    ctx->r14 = S32(ctx->r12 << 4);
    // 0x8005E110: addiu       $t5, $t6, -0x11
    ctx->r13 = ADD32(ctx->r14, -0X11);
    // 0x8005E114: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x8005E118: nop

    // 0x8005E11C: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8005E120: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x8005E124: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005E128: nop

L_8005E12C:
    // 0x8005E12C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
L_8005E130:
    // 0x8005E130: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005E134: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8005E138: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005E13C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005E140: lh          $t2, 0x18($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X18);
    // 0x8005E144: cvt.w.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8005E148: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005E14C: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x8005E150: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8005E154: sw          $zero, 0x74($s1)
    MEM_W(0X74, ctx->r17) = 0;
    // 0x8005E158: beq         $v1, $at, L_8005E1B8
    if (ctx->r3 == ctx->r1) {
        // 0x8005E15C: sh          $t7, 0x18($s1)
        MEM_H(0X18, ctx->r17) = ctx->r15;
            goto L_8005E1B8;
    }
    // 0x8005E15C: sh          $t7, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r15;
    // 0x8005E160: beq         $a0, $v1, L_8005E1B8
    if (ctx->r4 == ctx->r3) {
        // 0x8005E164: sra         $t9, $t2, 4
        ctx->r25 = S32(SIGNED(ctx->r10) >> 4);
            goto L_8005E1B8;
    }
    // 0x8005E164: sra         $t9, $t2, 4
    ctx->r25 = S32(SIGNED(ctx->r10) >> 4);
    // 0x8005E168: sll         $t3, $t9, 16
    ctx->r11 = S32(ctx->r25 << 16);
    // 0x8005E16C: sra         $t2, $t3, 16
    ctx->r10 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8005E170: bne         $v1, $zero, L_8005E17C
    if (ctx->r3 != 0) {
        // 0x8005E174: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8005E17C;
    }
    // 0x8005E174: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005E178: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8005E17C:
    // 0x8005E17C: bne         $t2, $v0, L_8005E1B8
    if (ctx->r10 != ctx->r2) {
        // 0x8005E180: nop
    
            goto L_8005E1B8;
    }
    // 0x8005E180: nop

    // 0x8005E184: lh          $t5, 0x18($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X18);
    // 0x8005E188: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8005E18C: sra         $t8, $t5, 4
    ctx->r24 = S32(SIGNED(ctx->r13) >> 4);
    // 0x8005E190: bne         $t6, $t8, L_8005E1B8
    if (ctx->r14 != ctx->r24) {
        // 0x8005E194: addiu       $a0, $zero, 0x223
        ctx->r4 = ADD32(0, 0X223);
            goto L_8005E1B8;
    }
    // 0x8005E194: addiu       $a0, $zero, 0x223
    ctx->r4 = ADD32(0, 0X223);
    // 0x8005E198: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x8005E19C: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x8005E1A0: lw          $a3, 0x14($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X14);
    // 0x8005E1A4: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8005E1A8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8005E1AC: jal         0x80009558
    // 0x8005E1B0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_9;
    // 0x8005E1B0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_9:
    // 0x8005E1B4: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
L_8005E1B8:
    // 0x8005E1B8: lb          $t9, 0x1D7($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1D7);
    // 0x8005E1BC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8005E1C0: bne         $t9, $at, L_8005E204
    if (ctx->r25 != ctx->r1) {
        // 0x8005E1C4: lw          $a1, 0x60($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X60);
            goto L_8005E204;
    }
    // 0x8005E1C4: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x8005E1C8: lh          $t3, 0x0($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X0);
    // 0x8005E1CC: nop

    // 0x8005E1D0: bne         $t1, $t3, L_8005E204
    if (ctx->r9 != ctx->r11) {
        // 0x8005E1D4: lw          $a1, 0x60($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X60);
            goto L_8005E204;
    }
    // 0x8005E1D4: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x8005E1D8: jal         0x8002359C
    // 0x8005E1DC: nop

    func_80023568(rdram, ctx);
        goto after_10;
    // 0x8005E1DC: nop

    after_10:
    // 0x8005E1E0: beq         $v0, $zero, L_8005E200
    if (ctx->r2 == 0) {
        // 0x8005E1E4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8005E200;
    }
    // 0x8005E1E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005E1E8: addiu       $t4, $zero, 0xA5
    ctx->r12 = ADD32(0, 0XA5);
    // 0x8005E1EC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8005E1F0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8005E1F4: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    // 0x8005E1F8: jal         0x8005E3A4
    // 0x8005E1FC: addiu       $a3, $zero, 0x89
    ctx->r7 = ADD32(0, 0X89);
    spawn_boss_hazard(rdram, ctx);
        goto after_11;
    // 0x8005E1FC: addiu       $a3, $zero, 0x89
    ctx->r7 = ADD32(0, 0X89);
    after_11:
L_8005E200:
    // 0x8005E200: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
L_8005E204:
    // 0x8005E204: jal         0x800B019C
    // 0x8005E208: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    obj_spawn_particle(rdram, ctx);
        goto after_12;
    // 0x8005E208: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x8005E20C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005E210: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8005E214: jal         0x8005D1E8
    // 0x8005E218: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    fade_when_near_camera(rdram, ctx);
        goto after_13;
    // 0x8005E218: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_13:
    // 0x8005E21C: jal         0x8001BAFC
    // 0x8005E220: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    get_racer_object(rdram, ctx);
        goto after_14;
    // 0x8005E220: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_14:
    // 0x8005E224: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8005E228: lwc1        $f10, 0xC($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8005E22C: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8005E230: lwc1        $f6, 0x14($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8005E234: sub.s       $f20, $f8, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8005E238: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8005E23C: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8005E240: sub.s       $f14, $f18, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x8005E244: swc1        $f14, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f14.u32l;
    // 0x8005E248: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8005E24C: jal         0x800CA030
    // 0x8005E250: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_15;
    // 0x8005E250: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    after_15:
    // 0x8005E254: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005E258: lwc1        $f19, 0x7028($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, 0X7028);
    // 0x8005E25C: lwc1        $f18, 0x702C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X702C);
    // 0x8005E260: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x8005E264: c.lt.d      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.d < ctx->f18.d;
    // 0x8005E268: lwc1        $f14, 0x50($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8005E26C: bc1f        L_8005E2DC
    if (!c1cs) {
        // 0x8005E270: nop
    
            goto L_8005E2DC;
    }
    // 0x8005E270: nop

    // 0x8005E274: jal         0x80070990
    // 0x8005E278: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    arctan2_f(rdram, ctx);
        goto after_16;
    // 0x8005E278: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_16:
    // 0x8005E27C: lh          $t5, 0x0($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X0);
    // 0x8005E280: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8005E284: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x8005E288: subu        $v1, $v0, $t6
    ctx->r3 = SUB32(ctx->r2, ctx->r14);
    // 0x8005E28C: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
    // 0x8005E290: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8005E294: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8005E298: bne         $at, $zero, L_8005E2A8
    if (ctx->r1 != 0) {
        // 0x8005E29C: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8005E2A8;
    }
    // 0x8005E29C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8005E2A0: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8005E2A4: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8005E2A8:
    // 0x8005E2A8: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x8005E2AC: beq         $at, $zero, L_8005E2B8
    if (ctx->r1 == 0) {
        // 0x8005E2B0: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8005E2B8;
    }
    // 0x8005E2B0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8005E2B4: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8005E2B8:
    // 0x8005E2B8: slti        $at, $v1, 0xC01
    ctx->r1 = SIGNED(ctx->r3) < 0XC01 ? 1 : 0;
    // 0x8005E2BC: bne         $at, $zero, L_8005E2CC
    if (ctx->r1 != 0) {
        // 0x8005E2C0: slti        $at, $v1, -0xC00
        ctx->r1 = SIGNED(ctx->r3) < -0XC00 ? 1 : 0;
            goto L_8005E2CC;
    }
    // 0x8005E2C0: slti        $at, $v1, -0xC00
    ctx->r1 = SIGNED(ctx->r3) < -0XC00 ? 1 : 0;
    // 0x8005E2C4: addiu       $v1, $zero, 0xC00
    ctx->r3 = ADD32(0, 0XC00);
    // 0x8005E2C8: slti        $at, $v1, -0xC00
    ctx->r1 = SIGNED(ctx->r3) < -0XC00 ? 1 : 0;
L_8005E2CC:
    // 0x8005E2CC: beq         $at, $zero, L_8005E2D8
    if (ctx->r1 == 0) {
        // 0x8005E2D0: nop
    
            goto L_8005E2D8;
    }
    // 0x8005E2D0: nop

    // 0x8005E2D4: addiu       $v1, $zero, -0xC00
    ctx->r3 = ADD32(0, -0XC00);
L_8005E2D8:
    // 0x8005E2D8: sh          $v1, 0x16C($s0)
    MEM_H(0X16C, ctx->r16) = ctx->r3;
L_8005E2DC:
    // 0x8005E2DC: lb          $t8, 0x3B($s1)
    ctx->r24 = MEM_B(ctx->r17, 0X3B);
    // 0x8005E2E0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8005E2E4: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x8005E2E8: bne         $at, $zero, L_8005E318
    if (ctx->r1 != 0) {
        // 0x8005E2EC: addiu       $a1, $a1, -0x24A0
        ctx->r5 = ADD32(ctx->r5, -0X24A0);
            goto L_8005E318;
    }
    // 0x8005E2EC: addiu       $a1, $a1, -0x24A0
    ctx->r5 = ADD32(ctx->r5, -0X24A0);
    // 0x8005E2F0: lb          $t7, 0x1E7($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1E7);
    // 0x8005E2F4: nop

    // 0x8005E2F8: andi        $t9, $t7, 0x1F
    ctx->r25 = ctx->r15 & 0X1F;
    // 0x8005E2FC: slti        $at, $t9, 0xA
    ctx->r1 = SIGNED(ctx->r25) < 0XA ? 1 : 0;
    // 0x8005E300: beq         $at, $zero, L_8005E31C
    if (ctx->r1 == 0) {
        // 0x8005E304: lw          $v1, 0x34($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X34);
            goto L_8005E31C;
    }
    // 0x8005E304: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8005E308: lh          $t3, 0x16C($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X16C);
    // 0x8005E30C: nop

    // 0x8005E310: sra         $t4, $t3, 1
    ctx->r12 = S32(SIGNED(ctx->r11) >> 1);
    // 0x8005E314: sh          $t4, 0x16C($s0)
    MEM_H(0X16C, ctx->r16) = ctx->r12;
L_8005E318:
    // 0x8005E318: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
L_8005E31C:
    // 0x8005E31C: nop

    // 0x8005E320: lw          $v0, 0x4C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4C);
    // 0x8005E324: lw          $s0, 0x64($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X64);
    // 0x8005E328: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x8005E32C: nop

    // 0x8005E330: bne         $s1, $t5, L_8005E360
    if (ctx->r17 != ctx->r13) {
        // 0x8005E334: nop
    
            goto L_8005E360;
    }
    // 0x8005E334: nop

    // 0x8005E338: lh          $t6, 0x14($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X14);
    // 0x8005E33C: nop

    // 0x8005E340: andi        $t8, $t6, 0x8
    ctx->r24 = ctx->r14 & 0X8;
    // 0x8005E344: beq         $t8, $zero, L_8005E360
    if (ctx->r24 == 0) {
        // 0x8005E348: nop
    
            goto L_8005E360;
    }
    // 0x8005E348: nop

    // 0x8005E34C: lb          $t7, 0x3B($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X3B);
    // 0x8005E350: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005E354: bne         $t7, $at, L_8005E360
    if (ctx->r15 != ctx->r1) {
        // 0x8005E358: addiu       $t9, $zero, 0x4
        ctx->r25 = ADD32(0, 0X4);
            goto L_8005E360;
    }
    // 0x8005E358: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8005E35C: sb          $t9, 0x187($s0)
    MEM_B(0X187, ctx->r16) = ctx->r25;
L_8005E360:
    // 0x8005E360: lb          $t3, 0x1D8($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1D8);
    // 0x8005E364: nop

    // 0x8005E368: beq         $t3, $zero, L_8005E38C
    if (ctx->r11 == 0) {
        // 0x8005E36C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8005E38C;
    }
    // 0x8005E36C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8005E370: lb          $t4, 0x0($a1)
    ctx->r12 = MEM_B(ctx->r5, 0X0);
    // 0x8005E374: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8005E378: bne         $t4, $zero, L_8005E388
    if (ctx->r12 != 0) {
        // 0x8005E37C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8005E388;
    }
    // 0x8005E37C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005E380: jal         0x8005CD08
    // 0x8005E384: sb          $t5, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r13;
    racer_boss_finish(rdram, ctx);
        goto after_17;
    // 0x8005E384: sb          $t5, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r13;
    after_17:
L_8005E388:
    // 0x8005E388: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8005E38C:
    // 0x8005E38C: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8005E390: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8005E394: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8005E398: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8005E39C: jr          $ra
    // 0x8005E3A0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8005E3A0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void spawn_boss_hazard(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E3A4: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x8005E3A8: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8005E3AC: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8005E3B0: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x8005E3B4: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x8005E3B8: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8005E3BC: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x8005E3C0: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8005E3C4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8005E3C8: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x8005E3CC: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x8005E3D0: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8005E3D4: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8005E3D8: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8005E3DC: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8005E3E0: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8005E3E4: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8005E3E8: addiu       $a1, $sp, 0x7C
    ctx->r5 = ADD32(ctx->r29, 0X7C);
    // 0x8005E3EC: jal         0x8000E988
    // 0x8005E3F0: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    objGetObjList(rdram, ctx);
        goto after_0;
    // 0x8005E3F0: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    after_0:
    // 0x8005E3F4: andi        $t7, $s0, 0x100
    ctx->r15 = ctx->r16 & 0X100;
    // 0x8005E3F8: sra         $t8, $t7, 1
    ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
    // 0x8005E3FC: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x8005E400: sb          $s0, 0x64($sp)
    MEM_B(0X64, ctx->r29) = ctx->r16;
    // 0x8005E404: sb          $t9, 0x65($sp)
    MEM_B(0X65, ctx->r29) = ctx->r25;
    // 0x8005E408: lwc1        $f6, 0x38($s7)
    ctx->f6.u32l = MEM_W(ctx->r23, 0X38);
    // 0x8005E40C: lwc1        $f4, 0xC($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8005E410: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8005E414: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x8005E418: lw          $fp, 0x98($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X98);
    // 0x8005E41C: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8005E420: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8005E424: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8005E428: nop

    // 0x8005E42C: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x8005E430: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005E434: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005E438: nop

    // 0x8005E43C: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8005E440: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x8005E444: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8005E448: sh          $t1, 0x66($sp)
    MEM_H(0X66, ctx->r29) = ctx->r9;
    // 0x8005E44C: lwc1        $f6, 0x3C($s7)
    ctx->f6.u32l = MEM_W(ctx->r23, 0X3C);
    // 0x8005E450: lwc1        $f18, 0x10($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8005E454: mul.s       $f4, $f6, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8005E458: sub.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8005E45C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8005E460: nop

    // 0x8005E464: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x8005E468: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005E46C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005E470: nop

    // 0x8005E474: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8005E478: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x8005E47C: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8005E480: sh          $t3, 0x68($sp)
    MEM_H(0X68, ctx->r29) = ctx->r11;
    // 0x8005E484: lwc1        $f6, 0x40($s7)
    ctx->f6.u32l = MEM_W(ctx->r23, 0X40);
    // 0x8005E488: lwc1        $f16, 0x14($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8005E48C: mul.s       $f18, $f6, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8005E490: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8005E494: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8005E498: nop

    // 0x8005E49C: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x8005E4A0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005E4A4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005E4A8: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8005E4AC: cvt.w.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8005E4B0: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x8005E4B4: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8005E4B8: blez        $t6, L_8005E61C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8005E4BC: sh          $t5, 0x6A($sp)
        MEM_H(0X6A, ctx->r29) = ctx->r13;
            goto L_8005E61C;
    }
    // 0x8005E4BC: sh          $t5, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = ctx->r13;
    // 0x8005E4C0: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x8005E4C4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8005E4C8: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
L_8005E4CC:
    // 0x8005E4CC: lw          $s1, 0x0($s6)
    ctx->r17 = MEM_W(ctx->r22, 0X0);
    // 0x8005E4D0: addiu       $at, $zero, 0x6B
    ctx->r1 = ADD32(0, 0X6B);
    // 0x8005E4D4: lh          $t7, 0x48($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X48);
    // 0x8005E4D8: nop

    // 0x8005E4DC: bne         $t7, $at, L_8005E60C
    if (ctx->r15 != ctx->r1) {
        // 0x8005E4E0: lw          $t7, 0x7C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X7C);
            goto L_8005E60C;
    }
    // 0x8005E4E0: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x8005E4E4: lw          $s2, 0x3C($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X3C);
    // 0x8005E4E8: lb          $t8, 0x193($s7)
    ctx->r24 = MEM_B(ctx->r23, 0X193);
    // 0x8005E4EC: lb          $v0, 0x8($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X8);
    // 0x8005E4F0: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8005E4F4: beq         $t9, $v0, L_8005E504
    if (ctx->r25 == ctx->r2) {
        // 0x8005E4F8: nop
    
            goto L_8005E504;
    }
    // 0x8005E4F8: nop

    // 0x8005E4FC: bne         $v0, $zero, L_8005E60C
    if (ctx->r2 != 0) {
        // 0x8005E500: lw          $t7, 0x7C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X7C);
            goto L_8005E60C;
    }
    // 0x8005E500: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
L_8005E504:
    // 0x8005E504: lwc1        $f10, 0xC($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8005E508: lwc1        $f6, 0xC($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8005E50C: lwc1        $f16, 0x10($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8005E510: sub.s       $f0, $f10, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x8005E514: lwc1        $f18, 0x10($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8005E518: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8005E51C: sub.s       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8005E520: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8005E524: lwc1        $f8, 0x14($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8005E528: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8005E52C: sub.s       $f14, $f4, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8005E530: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8005E534: add.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8005E538: jal         0x800CA030
    // 0x8005E53C: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x8005E53C: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    after_1:
    // 0x8005E540: lb          $t0, 0x9($s2)
    ctx->r8 = MEM_B(ctx->r18, 0X9);
    // 0x8005E544: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x8005E548: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x8005E54C: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x8005E550: nop

    // 0x8005E554: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8005E558: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x8005E55C: mul.d       $f16, $f6, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f16.d = MUL_D(ctx->f6.d, ctx->f20.d);
    // 0x8005E560: c.lt.d      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.d < ctx->f16.d;
    // 0x8005E564: nop

    // 0x8005E568: bc1f        L_8005E604
    if (!c1cs) {
        // 0x8005E56C: nop
    
            goto L_8005E604;
    }
    // 0x8005E56C: nop

    // 0x8005E570: lw          $t2, 0x78($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X78);
    // 0x8005E574: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8005E578: bne         $t2, $zero, L_8005E608
    if (ctx->r10 != 0) {
        // 0x8005E57C: addiu       $a0, $sp, 0x64
        ctx->r4 = ADD32(ctx->r29, 0X64);
            goto L_8005E608;
    }
    // 0x8005E57C: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x8005E580: sw          $t3, 0x78($s1)
    MEM_W(0X78, ctx->r17) = ctx->r11;
    // 0x8005E584: jal         0x8000EA54
    // 0x8005E588: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    spawn_object(rdram, ctx);
        goto after_2;
    // 0x8005E588: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8005E58C: beq         $v0, $zero, L_8005E608
    if (ctx->r2 == 0) {
        // 0x8005E590: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8005E608;
    }
    // 0x8005E590: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8005E594: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x8005E598: lwc1        $f18, 0x1C($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X1C);
    // 0x8005E59C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005E5A0: swc1        $f18, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f18.u32l;
    // 0x8005E5A4: lwc1        $f8, 0x20($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X20);
    // 0x8005E5A8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8005E5AC: swc1        $f8, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f8.u32l;
    // 0x8005E5B0: lwc1        $f10, 0x24($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X24);
    // 0x8005E5B4: sw          $s1, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->r17;
    // 0x8005E5B8: swc1        $f10, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f10.u32l;
    // 0x8005E5BC: lb          $t4, 0xA($s2)
    ctx->r12 = MEM_B(ctx->r18, 0XA);
    // 0x8005E5C0: andi        $s4, $fp, 0xFFFF
    ctx->r20 = ctx->r30 & 0XFFFF;
    // 0x8005E5C4: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x8005E5C8: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8005E5CC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8005E5D0: jal         0x8006FB8C
    // 0x8005E5D4: sw          $t5, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r13;
    rand_range(rdram, ctx);
        goto after_3;
    // 0x8005E5D4: sw          $t5, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r13;
    after_3:
    // 0x8005E5D8: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8005E5DC: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x8005E5E0: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x8005E5E4: sh          $v0, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r2;
    // 0x8005E5E8: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8005E5EC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8005E5F0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8005E5F4: jal         0x80009558
    // 0x8005E5F8: andi        $a0, $s4, 0xFFFF
    ctx->r4 = ctx->r20 & 0XFFFF;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_4;
    // 0x8005E5F8: andi        $a0, $s4, 0xFFFF
    ctx->r4 = ctx->r20 & 0XFFFF;
    after_4:
    // 0x8005E5FC: b           L_8005E60C
    // 0x8005E600: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
        goto L_8005E60C;
    // 0x8005E600: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
L_8005E604:
    // 0x8005E604: sw          $zero, 0x78($s1)
    MEM_W(0X78, ctx->r17) = 0;
L_8005E608:
    // 0x8005E608: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
L_8005E60C:
    // 0x8005E60C: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8005E610: slt         $at, $s5, $t7
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8005E614: bne         $at, $zero, L_8005E4CC
    if (ctx->r1 != 0) {
        // 0x8005E618: addiu       $s6, $s6, 0x4
        ctx->r22 = ADD32(ctx->r22, 0X4);
            goto L_8005E4CC;
    }
    // 0x8005E618: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
L_8005E61C:
    // 0x8005E61C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8005E620: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8005E624: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8005E628: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8005E62C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8005E630: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8005E634: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8005E638: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8005E63C: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8005E640: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8005E644: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x8005E648: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x8005E64C: jr          $ra
    // 0x8005E650: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x8005E650: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x8005E654: nop

    // 0x8005E658: nop

    // 0x8005E65C: nop

;}
RECOMP_FUNC void update_bubbler(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E660: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8005E664: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8005E668: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8005E66C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8005E670: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8005E674: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005E678: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x8005E67C: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8005E680: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8005E684: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8005E688: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8005E68C: jal         0x8005CC18
    // 0x8005E690: addiu       $a0, $a0, -0x2C50
    ctx->r4 = ADD32(ctx->r4, -0X2C50);
    set_boss_voice_clip_offset(rdram, ctx);
        goto after_0;
    // 0x8005E690: addiu       $a0, $a0, -0x2C50
    ctx->r4 = ADD32(ctx->r4, -0X2C50);
    after_0:
    // 0x8005E694: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
    // 0x8005E698: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x8005E69C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8005E6A0: addiu       $v1, $zero, -0x11
    ctx->r3 = ADD32(0, -0X11);
    // 0x8005E6A4: and         $t7, $t6, $v1
    ctx->r15 = ctx->r14 & ctx->r3;
    // 0x8005E6A8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8005E6AC: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8005E6B0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005E6B4: and         $t9, $t8, $v1
    ctx->r25 = ctx->r24 & ctx->r3;
    // 0x8005E6B8: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8005E6BC: lb          $t2, 0x3B($s1)
    ctx->r10 = MEM_B(ctx->r17, 0X3B);
    // 0x8005E6C0: nop

    // 0x8005E6C4: sh          $t2, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r10;
    // 0x8005E6C8: lh          $t3, 0x18($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X18);
    // 0x8005E6CC: nop

    // 0x8005E6D0: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x8005E6D4: lh          $t4, 0x16A($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X16A);
    // 0x8005E6D8: nop

    // 0x8005E6DC: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x8005E6E0: lb          $t5, 0x1D8($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1D8);
    // 0x8005E6E4: nop

    // 0x8005E6E8: bne         $t5, $at, L_8005E70C
    if (ctx->r13 != ctx->r1) {
        // 0x8005E6EC: lw          $t1, 0x70($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X70);
            goto L_8005E70C;
    }
    // 0x8005E6EC: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x8005E6F0: jal         0x80021434
    // 0x8005E6F4: addiu       $a0, $zero, 0x82
    ctx->r4 = ADD32(0, 0X82);
    func_80021400(rdram, ctx);
        goto after_1;
    // 0x8005E6F4: addiu       $a0, $zero, 0x82
    ctx->r4 = ADD32(0, 0X82);
    after_1:
    // 0x8005E6F8: lb          $t6, 0x1D8($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D8);
    // 0x8005E6FC: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x8005E700: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8005E704: sb          $t7, 0x1D8($s0)
    MEM_B(0X1D8, ctx->r16) = ctx->r15;
    // 0x8005E708: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
L_8005E70C:
    // 0x8005E70C: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x8005E710: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x8005E714: nop

    // 0x8005E718: bne         $v1, $a0, L_8005E724
    if (ctx->r3 != ctx->r4) {
        // 0x8005E71C: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8005E724;
    }
    // 0x8005E71C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005E720: sb          $zero, -0x2490($at)
    MEM_B(-0X2490, ctx->r1) = 0;
L_8005E724:
    // 0x8005E724: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x8005E728: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8005E72C: bne         $t0, $t8, L_8005E7A8
    if (ctx->r8 != ctx->r24) {
        // 0x8005E730: nop
    
            goto L_8005E7A8;
    }
    // 0x8005E730: nop

    // 0x8005E734: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x8005E738: nop

    // 0x8005E73C: beq         $a0, $v0, L_8005E7A8
    if (ctx->r4 == ctx->r2) {
        // 0x8005E740: addiu       $t9, $v0, -0x1E
        ctx->r25 = ADD32(ctx->r2, -0X1E);
            goto L_8005E7A8;
    }
    // 0x8005E740: addiu       $t9, $v0, -0x1E
    ctx->r25 = ADD32(ctx->r2, -0X1E);
    // 0x8005E744: bgez        $t9, L_8005E7A0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8005E748: sw          $t9, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r25;
            goto L_8005E7A0;
    }
    // 0x8005E748: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8005E74C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8005E750: lb          $t3, -0x248F($t3)
    ctx->r11 = MEM_B(ctx->r11, -0X248F);
    // 0x8005E754: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005E758: bne         $t3, $zero, L_8005E780
    if (ctx->r11 != 0) {
        // 0x8005E75C: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_8005E780;
    }
    // 0x8005E75C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8005E760: jal         0x8005CCA4
    // 0x8005E764: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    play_random_boss_sound(rdram, ctx);
        goto after_2;
    // 0x8005E764: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    after_2:
    // 0x8005E768: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x8005E76C: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x8005E770: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x8005E774: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x8005E778: sb          $t4, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r12;
    // 0x8005E77C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
L_8005E780:
    // 0x8005E780: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005E784: sb          $t5, -0x248F($at)
    MEM_B(-0X248F, ctx->r1) = ctx->r13;
    // 0x8005E788: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x8005E78C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8005E790: nop

    // 0x8005E794: ori         $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 | 0X8000;
    // 0x8005E798: b           L_8005E7A8
    // 0x8005E79C: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
        goto L_8005E7A8;
    // 0x8005E79C: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
L_8005E7A0:
    // 0x8005E7A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005E7A4: sb          $zero, -0x248F($at)
    MEM_B(-0X248F, ctx->r1) = 0;
L_8005E7A8:
    // 0x8005E7A8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8005E7AC: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x8005E7B0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8005E7B4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8005E7B8: jal         0x8004F834
    // 0x8005E7BC: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    func_8004F7F4(rdram, ctx);
        goto after_3;
    // 0x8005E7BC: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    after_3:
    // 0x8005E7C0: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x8005E7C4: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x8005E7C8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005E7CC: sw          $v1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r3;
    // 0x8005E7D0: swc1        $f16, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f16.u32l;
    // 0x8005E7D4: lh          $t8, 0x52($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X52);
    // 0x8005E7D8: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8005E7DC: sh          $t8, 0x16A($s0)
    MEM_H(0X16A, ctx->r16) = ctx->r24;
    // 0x8005E7E0: lh          $t9, 0x56($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X56);
    // 0x8005E7E4: nop

    // 0x8005E7E8: sb          $t9, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r25;
    // 0x8005E7EC: lh          $t2, 0x54($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X54);
    // 0x8005E7F0: nop

    // 0x8005E7F4: sh          $t2, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r10;
    // 0x8005E7F8: lb          $t3, 0x187($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X187);
    // 0x8005E7FC: nop

    // 0x8005E800: beq         $t3, $zero, L_8005E890
    if (ctx->r11 == 0) {
        // 0x8005E804: nop
    
            goto L_8005E890;
    }
    // 0x8005E804: nop

    // 0x8005E808: lb          $v0, 0x3B($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X3B);
    // 0x8005E80C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005E810: beq         $v0, $at, L_8005E890
    if (ctx->r2 == ctx->r1) {
        // 0x8005E814: addiu       $t4, $zero, 0x2
        ctx->r12 = ADD32(0, 0X2);
            goto L_8005E890;
    }
    // 0x8005E814: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8005E818: sb          $v0, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r2;
    // 0x8005E81C: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8005E820: lui         $at, 0x401E
    ctx->r1 = S32(0X401E << 16);
    // 0x8005E824: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8005E828: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8005E82C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005E830: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x8005E834: sb          $t4, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r12;
    // 0x8005E838: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8005E83C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8005E840: jal         0x8005CCA4
    // 0x8005E844: swc1        $f18, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f18.u32l;
    play_random_boss_sound(rdram, ctx);
        goto after_4;
    // 0x8005E844: swc1        $f18, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f18.u32l;
    after_4:
    // 0x8005E848: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    // 0x8005E84C: jal         0x80001D04
    // 0x8005E850: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_5;
    // 0x8005E850: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8005E854: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8005E858: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8005E85C: jal         0x8006A168
    // 0x8005E860: nop

    set_camera_shake(rdram, ctx);
        goto after_6;
    // 0x8005E860: nop

    after_6:
    // 0x8005E864: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005E868: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005E86C: lwc1        $f9, 0x7030($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X7030);
    // 0x8005E870: lwc1        $f8, 0x7034($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7034);
    // 0x8005E874: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005E878: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8005E87C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005E880: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8005E884: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x8005E888: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8005E88C: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
L_8005E890:
    // 0x8005E890: lw          $t5, 0x148($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X148);
    // 0x8005E894: sb          $zero, 0x187($s0)
    MEM_B(0X187, ctx->r16) = 0;
    // 0x8005E898: beq         $t5, $zero, L_8005E8DC
    if (ctx->r13 == 0) {
        // 0x8005E89C: nop
    
            goto L_8005E8DC;
    }
    // 0x8005E89C: nop

    // 0x8005E8A0: lwc1        $f0, 0x1C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8005E8A4: lwc1        $f2, 0x24($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8005E8A8: mul.s       $f20, $f0, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8005E8AC: nop

    // 0x8005E8B0: mul.s       $f14, $f2, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8005E8B4: nop

    // 0x8005E8B8: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8005E8BC: nop

    // 0x8005E8C0: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8005E8C4: jal         0x800CA030
    // 0x8005E8C8: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_7;
    // 0x8005E8C8: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_7:
    // 0x8005E8CC: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x8005E8D0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005E8D4: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    // 0x8005E8D8: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_8005E8DC:
    // 0x8005E8DC: lw          $t6, 0x68($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X68);
    // 0x8005E8E0: lb          $t8, 0x3B($s1)
    ctx->r24 = MEM_B(ctx->r17, 0X3B);
    // 0x8005E8E4: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x8005E8E8: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8005E8EC: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8005E8F0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005E8F4: lw          $t7, 0x44($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X44);
    // 0x8005E8F8: nop

    // 0x8005E8FC: addu        $t2, $t7, $t9
    ctx->r10 = ADD32(ctx->r15, ctx->r25);
    // 0x8005E900: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x8005E904: sb          $t6, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r14;
    // 0x8005E908: lwc1        $f18, 0x5C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8005E90C: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x8005E910: addiu       $t5, $t4, -0x11
    ctx->r13 = ADD32(ctx->r12, -0X11);
    // 0x8005E914: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x8005E918: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005E91C: cvt.d.s     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f2.d = CVT_D_S(ctx->f18.fl);
    // 0x8005E920: add.d       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = ctx->f2.d + ctx->f2.d;
    // 0x8005E924: cvt.s.w     $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    ctx->f20.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8005E928: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005E92C: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x8005E930: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8005E934: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x8005E938: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005E93C: nop

    // 0x8005E940: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8005E944: nop

    // 0x8005E948: bc1f        L_8005E974
    if (!c1cs) {
        // 0x8005E94C: nop
    
            goto L_8005E974;
    }
    // 0x8005E94C: nop

L_8005E950:
    // 0x8005E950: add.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x8005E954: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    // 0x8005E958: sh          $t0, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r8;
    // 0x8005E95C: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005E960: nop

    // 0x8005E964: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8005E968: nop

    // 0x8005E96C: bc1t        L_8005E950
    if (c1cs) {
        // 0x8005E970: nop
    
            goto L_8005E950;
    }
    // 0x8005E970: nop

L_8005E974:
    // 0x8005E974: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x8005E978: nop

    // 0x8005E97C: bc1f        L_8005E9A8
    if (!c1cs) {
        // 0x8005E980: nop
    
            goto L_8005E9A8;
    }
    // 0x8005E980: nop

L_8005E984:
    // 0x8005E984: sub.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x8005E988: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x8005E98C: sh          $t0, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r8;
    // 0x8005E990: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005E994: nop

    // 0x8005E998: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x8005E99C: nop

    // 0x8005E9A0: bc1t        L_8005E984
    if (c1cs) {
        // 0x8005E9A4: nop
    
            goto L_8005E984;
    }
    // 0x8005E9A4: nop

L_8005E9A8:
    // 0x8005E9A8: lh          $t8, 0x10($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X10);
    // 0x8005E9AC: nop

    // 0x8005E9B0: bne         $t0, $t8, L_8005E9D8
    if (ctx->r8 != ctx->r24) {
        // 0x8005E9B4: nop
    
            goto L_8005E9D8;
    }
    // 0x8005E9B4: nop

    // 0x8005E9B8: lb          $t7, 0x3B($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X3B);
    // 0x8005E9BC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005E9C0: bne         $t7, $at, L_8005E9D8
    if (ctx->r15 != ctx->r1) {
        // 0x8005E9C4: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8005E9D8;
    }
    // 0x8005E9C4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8005E9C8: sb          $t9, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r25;
    // 0x8005E9CC: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x8005E9D0: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005E9D4: nop

L_8005E9D8:
    // 0x8005E9D8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8005E9DC: nop

    // 0x8005E9E0: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x8005E9E4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005E9E8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005E9EC: nop

    // 0x8005E9F0: cvt.w.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = CVT_W_S(ctx->f0.fl);
    // 0x8005E9F4: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x8005E9F8: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8005E9FC: sh          $t3, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r11;
    // 0x8005EA00: lh          $t4, 0x0($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X0);
    // 0x8005EA04: nop

    // 0x8005EA08: bne         $t0, $t4, L_8005EA48
    if (ctx->r8 != ctx->r12) {
        // 0x8005EA0C: nop
    
            goto L_8005EA48;
    }
    // 0x8005EA0C: nop

    // 0x8005EA10: jal         0x8002359C
    // 0x8005EA14: nop

    func_80023568(rdram, ctx);
        goto after_8;
    // 0x8005EA14: nop

    after_8:
    // 0x8005EA18: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005EA1C: beq         $v0, $zero, L_8005EA48
    if (ctx->r2 == 0) {
        // 0x8005EA20: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_8005EA48;
    }
    // 0x8005EA20: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8005EA24: bne         $v0, $at, L_8005EA30
    if (ctx->r2 != ctx->r1) {
        // 0x8005EA28: addiu       $a3, $zero, 0x110
        ctx->r7 = ADD32(0, 0X110);
            goto L_8005EA30;
    }
    // 0x8005EA28: addiu       $a3, $zero, 0x110
    ctx->r7 = ADD32(0, 0X110);
    // 0x8005EA2C: addiu       $a3, $zero, 0x12A
    ctx->r7 = ADD32(0, 0X12A);
L_8005EA30:
    // 0x8005EA30: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8005EA34: addiu       $t5, $zero, 0x245
    ctx->r13 = ADD32(0, 0X245);
    // 0x8005EA38: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8005EA3C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005EA40: jal         0x8005E3A4
    // 0x8005EA44: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    spawn_boss_hazard(rdram, ctx);
        goto after_9;
    // 0x8005EA44: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_9:
L_8005EA48:
    // 0x8005EA48: sw          $zero, 0x74($s1)
    MEM_W(0X74, ctx->r17) = 0;
    // 0x8005EA4C: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x8005EA50: jal         0x800B019C
    // 0x8005EA54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    obj_spawn_particle(rdram, ctx);
        goto after_10;
    // 0x8005EA54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x8005EA58: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005EA5C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8005EA60: jal         0x8005D1E8
    // 0x8005EA64: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    fade_when_near_camera(rdram, ctx);
        goto after_11;
    // 0x8005EA64: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_11:
    // 0x8005EA68: lb          $v0, 0x3B($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X3B);
    // 0x8005EA6C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005EA70: beq         $v0, $at, L_8005EA8C
    if (ctx->r2 == ctx->r1) {
        // 0x8005EA74: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8005EA8C;
    }
    // 0x8005EA74: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005EA78: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005EA7C: beq         $v0, $at, L_8005EA94
    if (ctx->r2 == ctx->r1) {
        // 0x8005EA80: addiu       $a1, $zero, 0x100
        ctx->r5 = ADD32(0, 0X100);
            goto L_8005EA94;
    }
    // 0x8005EA80: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    // 0x8005EA84: b           L_8005EA94
    // 0x8005EA88: addiu       $a1, $zero, 0x1500
    ctx->r5 = ADD32(0, 0X1500);
        goto L_8005EA94;
    // 0x8005EA88: addiu       $a1, $zero, 0x1500
    ctx->r5 = ADD32(0, 0X1500);
L_8005EA8C:
    // 0x8005EA8C: b           L_8005EA94
    // 0x8005EA90: addiu       $a1, $zero, 0x2500
    ctx->r5 = ADD32(0, 0X2500);
        goto L_8005EA94;
    // 0x8005EA90: addiu       $a1, $zero, 0x2500
    ctx->r5 = ADD32(0, 0X2500);
L_8005EA94:
    // 0x8005EA94: jal         0x8001BAFC
    // 0x8005EA98: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    get_racer_object(rdram, ctx);
        goto after_12;
    // 0x8005EA98: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_12:
    // 0x8005EA9C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8005EAA0: lwc1        $f18, 0xC($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8005EAA4: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8005EAA8: lwc1        $f6, 0x14($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8005EAAC: sub.s       $f20, $f10, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8005EAB0: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8005EAB4: mul.s       $f8, $f20, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8005EAB8: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8005EABC: swc1        $f14, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f14.u32l;
    // 0x8005EAC0: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8005EAC4: jal         0x800CA030
    // 0x8005EAC8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_13;
    // 0x8005EAC8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_13:
    // 0x8005EACC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005EAD0: lwc1        $f5, 0x7038($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X7038);
    // 0x8005EAD4: lwc1        $f4, 0x703C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X703C);
    // 0x8005EAD8: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x8005EADC: c.lt.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d < ctx->f4.d;
    // 0x8005EAE0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8005EAE4: lwc1        $f14, 0x48($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8005EAE8: bc1f        L_8005EB64
    if (!c1cs) {
        // 0x8005EAEC: nop
    
            goto L_8005EB64;
    }
    // 0x8005EAEC: nop

    // 0x8005EAF0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8005EAF4: jal         0x80070990
    // 0x8005EAF8: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    arctan2_f(rdram, ctx);
        goto after_14;
    // 0x8005EAF8: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_14:
    // 0x8005EAFC: lh          $t6, 0x0($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X0);
    // 0x8005EB00: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8005EB04: andi        $t8, $t6, 0xFFFF
    ctx->r24 = ctx->r14 & 0XFFFF;
    // 0x8005EB08: subu        $v1, $v0, $t8
    ctx->r3 = SUB32(ctx->r2, ctx->r24);
    // 0x8005EB0C: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
    // 0x8005EB10: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8005EB14: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8005EB18: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8005EB1C: bne         $at, $zero, L_8005EB30
    if (ctx->r1 != 0) {
        // 0x8005EB20: negu        $v0, $a1
        ctx->r2 = SUB32(0, ctx->r5);
            goto L_8005EB30;
    }
    // 0x8005EB20: negu        $v0, $a1
    ctx->r2 = SUB32(0, ctx->r5);
    // 0x8005EB24: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8005EB28: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8005EB2C: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8005EB30:
    // 0x8005EB30: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x8005EB34: beq         $at, $zero, L_8005EB40
    if (ctx->r1 == 0) {
        // 0x8005EB38: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8005EB40;
    }
    // 0x8005EB38: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8005EB3C: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8005EB40:
    // 0x8005EB40: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8005EB44: beq         $at, $zero, L_8005EB54
    if (ctx->r1 == 0) {
        // 0x8005EB48: slt         $at, $v1, $v0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8005EB54;
    }
    // 0x8005EB48: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8005EB4C: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x8005EB50: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
L_8005EB54:
    // 0x8005EB54: beq         $at, $zero, L_8005EB60
    if (ctx->r1 == 0) {
        // 0x8005EB58: nop
    
            goto L_8005EB60;
    }
    // 0x8005EB58: nop

    // 0x8005EB5C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8005EB60:
    // 0x8005EB60: sh          $v1, 0x16C($s0)
    MEM_H(0X16C, ctx->r16) = ctx->r3;
L_8005EB64:
    // 0x8005EB64: lb          $t7, 0x3B($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X3B);
    // 0x8005EB68: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005EB6C: bne         $t7, $at, L_8005EB9C
    if (ctx->r15 != ctx->r1) {
        // 0x8005EB70: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_8005EB9C;
    }
    // 0x8005EB70: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8005EB74: lb          $t9, 0x1E7($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1E7);
    // 0x8005EB78: nop

    // 0x8005EB7C: andi        $t2, $t9, 0x1F
    ctx->r10 = ctx->r25 & 0X1F;
    // 0x8005EB80: slti        $at, $t2, 0xA
    ctx->r1 = SIGNED(ctx->r10) < 0XA ? 1 : 0;
    // 0x8005EB84: beq         $at, $zero, L_8005EBA0
    if (ctx->r1 == 0) {
        // 0x8005EB88: lw          $v1, 0x30($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X30);
            goto L_8005EBA0;
    }
    // 0x8005EB88: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x8005EB8C: lh          $t3, 0x16C($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X16C);
    // 0x8005EB90: nop

    // 0x8005EB94: sra         $t4, $t3, 1
    ctx->r12 = S32(SIGNED(ctx->r11) >> 1);
    // 0x8005EB98: sh          $t4, 0x16C($s0)
    MEM_H(0X16C, ctx->r16) = ctx->r12;
L_8005EB9C:
    // 0x8005EB9C: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
L_8005EBA0:
    // 0x8005EBA0: addiu       $a1, $a1, -0x2490
    ctx->r5 = ADD32(ctx->r5, -0X2490);
    // 0x8005EBA4: lw          $v0, 0x4C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4C);
    // 0x8005EBA8: lw          $s0, 0x64($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X64);
    // 0x8005EBAC: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x8005EBB0: nop

    // 0x8005EBB4: bne         $s1, $t5, L_8005EBE4
    if (ctx->r17 != ctx->r13) {
        // 0x8005EBB8: nop
    
            goto L_8005EBE4;
    }
    // 0x8005EBB8: nop

    // 0x8005EBBC: lh          $t6, 0x14($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X14);
    // 0x8005EBC0: nop

    // 0x8005EBC4: andi        $t8, $t6, 0x8
    ctx->r24 = ctx->r14 & 0X8;
    // 0x8005EBC8: beq         $t8, $zero, L_8005EBE4
    if (ctx->r24 == 0) {
        // 0x8005EBCC: nop
    
            goto L_8005EBE4;
    }
    // 0x8005EBCC: nop

    // 0x8005EBD0: lb          $t7, 0x3B($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X3B);
    // 0x8005EBD4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005EBD8: bne         $t7, $at, L_8005EBE4
    if (ctx->r15 != ctx->r1) {
        // 0x8005EBDC: addiu       $t9, $zero, 0x4
        ctx->r25 = ADD32(0, 0X4);
            goto L_8005EBE4;
    }
    // 0x8005EBDC: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8005EBE0: sb          $t9, 0x187($s0)
    MEM_B(0X187, ctx->r16) = ctx->r25;
L_8005EBE4:
    // 0x8005EBE4: lb          $t2, 0x1D8($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X1D8);
    // 0x8005EBE8: nop

    // 0x8005EBEC: beq         $t2, $zero, L_8005EC10
    if (ctx->r10 == 0) {
        // 0x8005EBF0: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8005EC10;
    }
    // 0x8005EBF0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8005EBF4: lb          $t3, 0x0($a1)
    ctx->r11 = MEM_B(ctx->r5, 0X0);
    // 0x8005EBF8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8005EBFC: bne         $t3, $zero, L_8005EC0C
    if (ctx->r11 != 0) {
        // 0x8005EC00: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8005EC0C;
    }
    // 0x8005EC00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005EC04: jal         0x8005CD08
    // 0x8005EC08: sb          $t4, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r12;
    racer_boss_finish(rdram, ctx);
        goto after_15;
    // 0x8005EC08: sb          $t4, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r12;
    after_15:
L_8005EC0C:
    // 0x8005EC0C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8005EC10:
    // 0x8005EC10: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8005EC14: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8005EC18: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8005EC1C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8005EC20: jr          $ra
    // 0x8005EC24: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8005EC24: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8005EC28: nop

    // 0x8005EC2C: nop

;}
RECOMP_FUNC void update_wizpig(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005EC30: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8005EC34: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8005EC38: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005EC3C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8005EC40: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8005EC44: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005EC48: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x8005EC4C: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8005EC50: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8005EC54: jal         0x8005CC18
    // 0x8005EC58: addiu       $a0, $a0, -0x2C30
    ctx->r4 = ADD32(ctx->r4, -0X2C30);
    set_boss_voice_clip_offset(rdram, ctx);
        goto after_0;
    // 0x8005EC58: addiu       $a0, $a0, -0x2C30
    ctx->r4 = ADD32(ctx->r4, -0X2C30);
    after_0:
    // 0x8005EC5C: sb          $zero, 0x1EC($s0)
    MEM_B(0X1EC, ctx->r16) = 0;
    // 0x8005EC60: lb          $t6, 0x3B($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X3B);
    // 0x8005EC64: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005EC68: sh          $t6, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r14;
    // 0x8005EC6C: lh          $t7, 0x18($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X18);
    // 0x8005EC70: lwc1        $f7, 0x7040($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X7040);
    // 0x8005EC74: sh          $t7, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r15;
    // 0x8005EC78: lh          $t8, 0x16A($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X16A);
    // 0x8005EC7C: lwc1        $f6, 0x7044($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7044);
    // 0x8005EC80: sh          $t8, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r24;
    // 0x8005EC84: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005EC88: nop

    // 0x8005EC8C: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x8005EC90: c.lt.d      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.d < ctx->f6.d;
    // 0x8005EC94: nop

    // 0x8005EC98: bc1f        L_8005ECC0
    if (!c1cs) {
        // 0x8005EC9C: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8005ECC0;
    }
    // 0x8005EC9C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005ECA0: lwc1        $f9, 0x7048($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X7048);
    // 0x8005ECA4: lwc1        $f8, 0x704C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X704C);
    // 0x8005ECA8: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8005ECAC: c.lt.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d < ctx->f0.d;
    // 0x8005ECB0: nop

    // 0x8005ECB4: bc1f        L_8005ECC0
    if (!c1cs) {
        // 0x8005ECB8: nop
    
            goto L_8005ECC0;
    }
    // 0x8005ECB8: nop

    // 0x8005ECBC: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
L_8005ECC0:
    // 0x8005ECC0: lb          $t2, 0x1D8($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X1D8);
    // 0x8005ECC4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005ECC8: bne         $t2, $at, L_8005ECFC
    if (ctx->r10 != ctx->r1) {
        // 0x8005ECCC: lw          $v1, 0x58($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X58);
            goto L_8005ECFC;
    }
    // 0x8005ECCC: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x8005ECD0: jal         0x8002359C
    // 0x8005ECD4: nop

    func_80023568(rdram, ctx);
        goto after_1;
    // 0x8005ECD4: nop

    after_1:
    // 0x8005ECD8: beq         $v0, $zero, L_8005ECFC
    if (ctx->r2 == 0) {
        // 0x8005ECDC: lw          $v1, 0x58($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X58);
            goto L_8005ECFC;
    }
    // 0x8005ECDC: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x8005ECE0: jal         0x80021434
    // 0x8005ECE4: addiu       $a0, $zero, 0x82
    ctx->r4 = ADD32(0, 0X82);
    func_80021400(rdram, ctx);
        goto after_2;
    // 0x8005ECE4: addiu       $a0, $zero, 0x82
    ctx->r4 = ADD32(0, 0X82);
    after_2:
    // 0x8005ECE8: lb          $t3, 0x1D8($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1D8);
    // 0x8005ECEC: nop

    // 0x8005ECF0: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8005ECF4: sb          $t4, 0x1D8($s0)
    MEM_B(0X1D8, ctx->r16) = ctx->r12;
    // 0x8005ECF8: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
L_8005ECFC:
    // 0x8005ECFC: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x8005ED00: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8005ED04: nop

    // 0x8005ED08: bne         $t1, $a0, L_8005ED14
    if (ctx->r9 != ctx->r4) {
        // 0x8005ED0C: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8005ED14;
    }
    // 0x8005ED0C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005ED10: sb          $zero, -0x2480($at)
    MEM_B(-0X2480, ctx->r1) = 0;
L_8005ED14:
    // 0x8005ED14: lh          $t5, 0x0($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X0);
    // 0x8005ED18: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8005ED1C: bne         $t0, $t5, L_8005ED98
    if (ctx->r8 != ctx->r13) {
        // 0x8005ED20: sb          $zero, 0x1F5($s0)
        MEM_B(0X1F5, ctx->r16) = 0;
            goto L_8005ED98;
    }
    // 0x8005ED20: sb          $zero, 0x1F5($s0)
    MEM_B(0X1F5, ctx->r16) = 0;
    // 0x8005ED24: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8005ED28: nop

    // 0x8005ED2C: beq         $a0, $v0, L_8005ED98
    if (ctx->r4 == ctx->r2) {
        // 0x8005ED30: addiu       $t6, $v0, -0x1E
        ctx->r14 = ADD32(ctx->r2, -0X1E);
            goto L_8005ED98;
    }
    // 0x8005ED30: addiu       $t6, $v0, -0x1E
    ctx->r14 = ADD32(ctx->r2, -0X1E);
    // 0x8005ED34: bgez        $t6, L_8005ED90
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8005ED38: sw          $t6, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r14;
            goto L_8005ED90;
    }
    // 0x8005ED38: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8005ED3C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8005ED40: lb          $t8, -0x247F($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X247F);
    // 0x8005ED44: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005ED48: bne         $t8, $zero, L_8005ED6C
    if (ctx->r24 != 0) {
        // 0x8005ED4C: lw          $v0, 0x50($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X50);
            goto L_8005ED6C;
    }
    // 0x8005ED4C: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
    // 0x8005ED50: jal         0x8005CCA4
    // 0x8005ED54: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    play_random_boss_sound(rdram, ctx);
        goto after_3;
    // 0x8005ED54: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    after_3:
    // 0x8005ED58: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x8005ED5C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8005ED60: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x8005ED64: sb          $t9, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r25;
    // 0x8005ED68: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
L_8005ED6C:
    // 0x8005ED6C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8005ED70: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005ED74: sb          $t2, -0x247F($at)
    MEM_B(-0X247F, ctx->r1) = ctx->r10;
    // 0x8005ED78: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8005ED7C: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8005ED80: nop

    // 0x8005ED84: ori         $t4, $t3, 0x8000
    ctx->r12 = ctx->r11 | 0X8000;
    // 0x8005ED88: b           L_8005ED98
    // 0x8005ED8C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
        goto L_8005ED98;
    // 0x8005ED8C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_8005ED90:
    // 0x8005ED90: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005ED94: sb          $zero, -0x247F($at)
    MEM_B(-0X247F, ctx->r1) = 0;
L_8005ED98:
    // 0x8005ED98: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x8005ED9C: sb          $t5, 0x1D6($s0)
    MEM_B(0X1D6, ctx->r16) = ctx->r13;
    // 0x8005EDA0: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8005EDA4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8005EDA8: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8005EDAC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8005EDB0: jal         0x800497D4
    // 0x8005EDB4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_80049794(rdram, ctx);
        goto after_4;
    // 0x8005EDB4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_4:
    // 0x8005EDB8: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x8005EDBC: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8005EDC0: lb          $t6, 0x1D7($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D7);
    // 0x8005EDC4: nop

    // 0x8005EDC8: sb          $t6, 0x1D6($s0)
    MEM_B(0X1D6, ctx->r16) = ctx->r14;
    // 0x8005EDCC: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8005EDD0: sw          $zero, 0x74($s1)
    MEM_W(0X74, ctx->r17) = 0;
    // 0x8005EDD4: lh          $t7, 0x3A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X3A);
    // 0x8005EDD8: nop

    // 0x8005EDDC: sh          $t7, 0x16A($s0)
    MEM_H(0X16A, ctx->r16) = ctx->r15;
    // 0x8005EDE0: lh          $t8, 0x3E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X3E);
    // 0x8005EDE4: nop

    // 0x8005EDE8: sb          $t8, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r24;
    // 0x8005EDEC: lh          $t9, 0x3C($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X3C);
    // 0x8005EDF0: nop

    // 0x8005EDF4: sh          $t9, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r25;
    // 0x8005EDF8: lb          $t2, 0x187($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X187);
    // 0x8005EDFC: nop

    // 0x8005EE00: beq         $t2, $zero, L_8005EEA0
    if (ctx->r10 == 0) {
        // 0x8005EE04: nop
    
            goto L_8005EEA0;
    }
    // 0x8005EE04: nop

    // 0x8005EE08: lb          $t3, 0x3B($s1)
    ctx->r11 = MEM_B(ctx->r17, 0X3B);
    // 0x8005EE0C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8005EE10: beq         $t3, $at, L_8005EEA0
    if (ctx->r11 == ctx->r1) {
        // 0x8005EE14: nop
    
            goto L_8005EEA0;
    }
    // 0x8005EE14: nop

    // 0x8005EE18: jal         0x8005CCA4
    // 0x8005EE1C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    play_random_boss_sound(rdram, ctx);
        goto after_5;
    // 0x8005EE1C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x8005EE20: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    // 0x8005EE24: jal         0x80001D04
    // 0x8005EE28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_6;
    // 0x8005EE28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x8005EE2C: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8005EE30: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8005EE34: jal         0x8006A168
    // 0x8005EE38: nop

    set_camera_shake(rdram, ctx);
        goto after_7;
    // 0x8005EE38: nop

    after_7:
    // 0x8005EE3C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005EE40: lwc1        $f10, 0x1C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8005EE44: lwc1        $f1, 0x7050($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, 0X7050);
    // 0x8005EE48: lwc1        $f0, 0x7054($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7054);
    // 0x8005EE4C: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8005EE50: mul.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x8005EE54: lwc1        $f10, 0x24($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8005EE58: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005EE5C: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8005EE60: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x8005EE64: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8005EE68: sb          $t4, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r12;
    // 0x8005EE6C: mul.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x8005EE70: swc1        $f8, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f8.u32l;
    // 0x8005EE74: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8005EE78: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8005EE7C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8005EE80: swc1        $f8, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f8.u32l;
    // 0x8005EE84: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x8005EE88: lwc1        $f10, 0x20($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8005EE8C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8005EE90: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8005EE94: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x8005EE98: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8005EE9C: swc1        $f10, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f10.u32l;
L_8005EEA0:
    // 0x8005EEA0: lw          $t5, 0x148($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X148);
    // 0x8005EEA4: sb          $zero, 0x187($s0)
    MEM_B(0X187, ctx->r16) = 0;
    // 0x8005EEA8: beq         $t5, $zero, L_8005EF10
    if (ctx->r13 == 0) {
        // 0x8005EEAC: nop
    
            goto L_8005EF10;
    }
    // 0x8005EEAC: nop

    // 0x8005EEB0: lwc1        $f0, 0x1C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8005EEB4: lwc1        $f14, 0x24($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8005EEB8: mul.s       $f2, $f0, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8005EEBC: nop

    // 0x8005EEC0: mul.s       $f16, $f14, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8005EEC4: nop

    // 0x8005EEC8: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8005EECC: nop

    // 0x8005EED0: mul.s       $f6, $f16, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8005EED4: jal         0x800CA030
    // 0x8005EED8: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_8;
    // 0x8005EED8: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_8:
    // 0x8005EEDC: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x8005EEE0: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8005EEE4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8005EEE8: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x8005EEEC: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x8005EEF0: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x8005EEF4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005EEF8: bc1f        L_8005EF10
    if (!c1cs) {
        // 0x8005EEFC: swc1        $f2, 0x2C($s0)
        MEM_W(0X2C, ctx->r16) = ctx->f2.u32l;
            goto L_8005EF10;
    }
    // 0x8005EEFC: swc1        $f2, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f2.u32l;
    // 0x8005EF00: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
    // 0x8005EF04: swc1        $f18, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f18.u32l;
    // 0x8005EF08: swc1        $f18, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f18.u32l;
    // 0x8005EF0C: swc1        $f18, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f18.u32l;
L_8005EF10:
    // 0x8005EF10: lb          $a0, 0x192($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X192);
    // 0x8005EF14: lbu         $a1, 0x1C8($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1C8);
    // 0x8005EF18: jal         0x8001BA50
    // 0x8005EF1C: sh          $zero, 0x38($sp)
    MEM_H(0X38, ctx->r29) = 0;
    find_next_checkpoint_node(rdram, ctx);
        goto after_9;
    // 0x8005EF1C: sh          $zero, 0x38($sp)
    MEM_H(0X38, ctx->r29) = 0;
    after_9:
    // 0x8005EF20: lb          $t6, 0x1CA($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1CA);
    // 0x8005EF24: lh          $a2, 0x38($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X38);
    // 0x8005EF28: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x8005EF2C: lb          $t8, 0x36($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X36);
    // 0x8005EF30: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8005EF34: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005EF38: bne         $t1, $t8, L_8005EF4C
    if (ctx->r9 != ctx->r24) {
        // 0x8005EF3C: addiu       $t0, $zero, -0x1
        ctx->r8 = ADD32(0, -0X1);
            goto L_8005EF4C;
    }
    // 0x8005EF3C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8005EF40: sll         $a2, $t1, 16
    ctx->r6 = S32(ctx->r9 << 16);
    // 0x8005EF44: sra         $t9, $a2, 16
    ctx->r25 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8005EF48: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
L_8005EF4C:
    // 0x8005EF4C: lh          $t2, 0x2($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X2);
    // 0x8005EF50: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8005EF54: negu        $t3, $t2
    ctx->r11 = SUB32(0, ctx->r10);
    // 0x8005EF58: sh          $t3, 0x162($s0)
    MEM_H(0X162, ctx->r16) = ctx->r11;
    // 0x8005EF5C: lw          $t4, 0x68($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X68);
    // 0x8005EF60: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005EF64: lw          $v0, 0x0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X0);
    // 0x8005EF68: sll         $t6, $v1, 3
    ctx->r14 = S32(ctx->r3 << 3);
    // 0x8005EF6C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8005EF70: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005EF74: lw          $t5, 0x44($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X44);
    // 0x8005EF78: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8005EF7C: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8005EF80: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8005EF84: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005EF88: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x8005EF8C: addiu       $t2, $t9, -0x11
    ctx->r10 = ADD32(ctx->r25, -0X11);
    // 0x8005EF90: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x8005EF94: lwc1        $f5, 0x7058($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X7058);
    // 0x8005EF98: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005EF9C: lwc1        $f4, 0x705C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X705C);
    // 0x8005EFA0: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x8005EFA4: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8005EFA8: mul.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x8005EFAC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8005EFB0: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x8005EFB4: cvt.d.s     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.d = CVT_D_S(ctx->f12.fl);
    // 0x8005EFB8: c.le.d      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.d <= ctx->f8.d;
    // 0x8005EFBC: nop

    // 0x8005EFC0: bc1f        L_8005EFF0
    if (!c1cs) {
        // 0x8005EFC4: lui         $at, 0xC000
        ctx->r1 = S32(0XC000 << 16);
            goto L_8005EFF0;
    }
    // 0x8005EFC4: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8005EFC8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8005EFCC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005EFD0: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8005EFD4: c.lt.d      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.d < ctx->f0.d;
    // 0x8005EFD8: nop

    // 0x8005EFDC: bc1f        L_8005F018
    if (!c1cs) {
        // 0x8005EFE0: nop
    
            goto L_8005F018;
    }
    // 0x8005EFE0: nop

    // 0x8005EFE4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8005EFE8: b           L_8005F01C
    // 0x8005EFEC: sltiu       $at, $v1, 0x6
    ctx->r1 = ctx->r3 < 0X6 ? 1 : 0;
        goto L_8005F01C;
    // 0x8005EFEC: sltiu       $at, $v1, 0x6
    ctx->r1 = ctx->r3 < 0X6 ? 1 : 0;
L_8005EFF0:
    // 0x8005EFF0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8005EFF4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8005EFF8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005EFFC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8005F000: c.lt.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d < ctx->f4.d;
    // 0x8005F004: nop

    // 0x8005F008: bc1f        L_8005F018
    if (!c1cs) {
        // 0x8005F00C: nop
    
            goto L_8005F018;
    }
    // 0x8005F00C: nop

    // 0x8005F010: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8005F014: nop

L_8005F018:
    // 0x8005F018: sltiu       $at, $v1, 0x6
    ctx->r1 = ctx->r3 < 0X6 ? 1 : 0;
L_8005F01C:
    // 0x8005F01C: beq         $at, $zero, L_8005F15C
    if (ctx->r1 == 0) {
        // 0x8005F020: sll         $t3, $v1, 2
        ctx->r11 = S32(ctx->r3 << 2);
            goto L_8005F15C;
    }
    // 0x8005F020: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x8005F024: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005F028: addu        $at, $at, $t3
    gpr jr_addend_8005F034 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8005F02C: lw          $t3, 0x7060($at)
    ctx->r11 = ADD32(ctx->r1, 0X7060);
    // 0x8005F030: nop

    // 0x8005F034: jr          $t3
    // 0x8005F038: nop

    switch (jr_addend_8005F034 >> 2) {
        case 0: goto L_8005F03C; break;
        case 1: goto L_8005F060; break;
        case 2: goto L_8005F098; break;
        case 3: goto L_8005F0B4; break;
        case 4: goto L_8005F10C; break;
        case 5: goto L_8005F138; break;
        default: switch_error(__func__, 0x8005F034, 0x800E7060);
    }
    // 0x8005F038: nop

L_8005F03C:
    // 0x8005F03C: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005F040: cvt.d.s     $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f10.d = CVT_D_S(ctx->f14.fl);
    // 0x8005F044: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8005F048: add.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f8.d + ctx->f10.d;
    // 0x8005F04C: sb          $zero, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = 0;
    // 0x8005F050: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8005F054: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8005F058: b           L_8005F160
    // 0x8005F05C: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
        goto L_8005F160;
    // 0x8005F05C: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
L_8005F060:
    // 0x8005F060: lbu         $t4, 0x1CD($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X1CD);
    // 0x8005F064: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8005F068: bne         $a0, $t4, L_8005F084
    if (ctx->r4 != ctx->r12) {
        // 0x8005F06C: nop
    
            goto L_8005F084;
    }
    // 0x8005F06C: nop

    // 0x8005F070: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005F074: nop

    // 0x8005F078: add.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x8005F07C: b           L_8005F160
    // 0x8005F080: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
        goto L_8005F160;
    // 0x8005F080: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
L_8005F084:
    // 0x8005F084: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005F088: nop

    // 0x8005F08C: sub.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x8005F090: b           L_8005F160
    // 0x8005F094: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
        goto L_8005F160;
    // 0x8005F094: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
L_8005F098:
    // 0x8005F098: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005F09C: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8005F0A0: sub.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x8005F0A4: sb          $t5, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r13;
    // 0x8005F0A8: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x8005F0AC: b           L_8005F160
    // 0x8005F0B0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
        goto L_8005F160;
    // 0x8005F0B0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_8005F0B4:
    // 0x8005F0B4: lbu         $t6, 0x1CD($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X1CD);
    // 0x8005F0B8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8005F0BC: bne         $t6, $at, L_8005F0E8
    if (ctx->r14 != ctx->r1) {
        // 0x8005F0C0: nop
    
            goto L_8005F0E8;
    }
    // 0x8005F0C0: nop

    // 0x8005F0C4: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005F0C8: cvt.d.s     $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.d = CVT_D_S(ctx->f14.fl);
    // 0x8005F0CC: add.d       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f0.d + ctx->f0.d;
    // 0x8005F0D0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8005F0D4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005F0D8: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x8005F0DC: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x8005F0E0: b           L_8005F160
    // 0x8005F0E4: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
        goto L_8005F160;
    // 0x8005F0E4: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
L_8005F0E8:
    // 0x8005F0E8: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005F0EC: cvt.d.s     $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.d = CVT_D_S(ctx->f14.fl);
    // 0x8005F0F0: add.d       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f0.d + ctx->f0.d;
    // 0x8005F0F4: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8005F0F8: add.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f8.d + ctx->f10.d;
    // 0x8005F0FC: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8005F100: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x8005F104: b           L_8005F160
    // 0x8005F108: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
        goto L_8005F160;
    // 0x8005F108: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_8005F10C:
    // 0x8005F10C: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005F110: cvt.d.s     $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.d = CVT_D_S(ctx->f14.fl);
    // 0x8005F114: add.d       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f0.d + ctx->f0.d;
    // 0x8005F118: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8005F11C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8005F120: add.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d + ctx->f4.d;
    // 0x8005F124: sb          $t7, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r15;
    // 0x8005F128: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8005F12C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8005F130: b           L_8005F160
    // 0x8005F134: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
        goto L_8005F160;
    // 0x8005F134: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
L_8005F138:
    // 0x8005F138: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005F13C: cvt.d.s     $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.d = CVT_D_S(ctx->f14.fl);
    // 0x8005F140: add.d       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f0.d + ctx->f0.d;
    // 0x8005F144: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8005F148: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8005F14C: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x8005F150: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8005F154: b           L_8005F160
    // 0x8005F158: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
        goto L_8005F160;
    // 0x8005F158: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
L_8005F15C:
    // 0x8005F15C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_8005F160:
    // 0x8005F160: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005F164: nop

    // 0x8005F168: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8005F16C: nop

    // 0x8005F170: bc1f        L_8005F19C
    if (!c1cs) {
        // 0x8005F174: nop
    
            goto L_8005F19C;
    }
    // 0x8005F174: nop

L_8005F178:
    // 0x8005F178: sub.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8005F17C: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    // 0x8005F180: sh          $t0, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r8;
    // 0x8005F184: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005F188: nop

    // 0x8005F18C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8005F190: nop

    // 0x8005F194: bc1t        L_8005F178
    if (c1cs) {
        // 0x8005F198: nop
    
            goto L_8005F178;
    }
    // 0x8005F198: nop

L_8005F19C:
    // 0x8005F19C: c.le.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl <= ctx->f18.fl;
    // 0x8005F1A0: nop

    // 0x8005F1A4: bc1f        L_8005F1D0
    if (!c1cs) {
        // 0x8005F1A8: nop
    
            goto L_8005F1D0;
    }
    // 0x8005F1A8: nop

L_8005F1AC:
    // 0x8005F1AC: add.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8005F1B0: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x8005F1B4: sh          $t0, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r8;
    // 0x8005F1B8: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005F1BC: nop

    // 0x8005F1C0: c.le.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl <= ctx->f18.fl;
    // 0x8005F1C4: nop

    // 0x8005F1C8: bc1t        L_8005F1AC
    if (c1cs) {
        // 0x8005F1CC: nop
    
            goto L_8005F1AC;
    }
    // 0x8005F1CC: nop

L_8005F1D0:
    // 0x8005F1D0: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005F1D4: nop

    // 0x8005F1D8: bne         $a0, $v1, L_8005F1F8
    if (ctx->r4 != ctx->r3) {
        // 0x8005F1DC: nop
    
            goto L_8005F1F8;
    }
    // 0x8005F1DC: nop

    // 0x8005F1E0: beq         $a2, $zero, L_8005F1F8
    if (ctx->r6 == 0) {
        // 0x8005F1E4: addiu       $a3, $zero, 0x3
        ctx->r7 = ADD32(0, 0X3);
            goto L_8005F1F8;
    }
    // 0x8005F1E4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x8005F1E8: sb          $a3, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r7;
    // 0x8005F1EC: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x8005F1F0: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005F1F4: nop

L_8005F1F8:
    // 0x8005F1F8: lh          $t8, 0x10($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X10);
    // 0x8005F1FC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x8005F200: beq         $t0, $t8, L_8005F210
    if (ctx->r8 == ctx->r24) {
        // 0x8005F204: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8005F210;
    }
    // 0x8005F204: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8005F208: bne         $v1, $zero, L_8005F384
    if (ctx->r3 != 0) {
        // 0x8005F20C: nop
    
            goto L_8005F384;
    }
    // 0x8005F20C: nop

L_8005F210:
    // 0x8005F210: bne         $v1, $at, L_8005F234
    if (ctx->r3 != ctx->r1) {
        // 0x8005F214: nop
    
            goto L_8005F234;
    }
    // 0x8005F214: nop

    // 0x8005F218: lbu         $t9, 0x1CD($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1CD);
    // 0x8005F21C: nop

    // 0x8005F220: sb          $t9, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r25;
    // 0x8005F224: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x8005F228: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005F22C: b           L_8005F388
    // 0x8005F230: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
        goto L_8005F388;
    // 0x8005F230: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
L_8005F234:
    // 0x8005F234: bne         $t1, $v1, L_8005F264
    if (ctx->r9 != ctx->r3) {
        // 0x8005F238: nop
    
            goto L_8005F264;
    }
    // 0x8005F238: nop

    // 0x8005F23C: lbu         $t2, 0x1CD($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X1CD);
    // 0x8005F240: nop

    // 0x8005F244: bne         $t2, $zero, L_8005F254
    if (ctx->r10 != 0) {
        // 0x8005F248: nop
    
            goto L_8005F254;
    }
    // 0x8005F248: nop

    // 0x8005F24C: b           L_8005F258
    // 0x8005F250: sb          $a0, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r4;
        goto L_8005F258;
    // 0x8005F250: sb          $a0, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r4;
L_8005F254:
    // 0x8005F254: sb          $zero, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = 0;
L_8005F258:
    // 0x8005F258: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005F25C: b           L_8005F388
    // 0x8005F260: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
        goto L_8005F388;
    // 0x8005F260: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
L_8005F264:
    // 0x8005F264: bne         $a3, $v1, L_8005F294
    if (ctx->r7 != ctx->r3) {
        // 0x8005F268: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8005F294;
    }
    // 0x8005F268: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005F26C: lbu         $t3, 0x1CD($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X1CD);
    // 0x8005F270: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8005F274: bne         $t3, $at, L_8005F284
    if (ctx->r11 != ctx->r1) {
        // 0x8005F278: addiu       $t4, $zero, 0x4
        ctx->r12 = ADD32(0, 0X4);
            goto L_8005F284;
    }
    // 0x8005F278: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8005F27C: b           L_8005F288
    // 0x8005F280: sb          $a0, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r4;
        goto L_8005F288;
    // 0x8005F280: sb          $a0, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r4;
L_8005F284:
    // 0x8005F284: sb          $t4, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r12;
L_8005F288:
    // 0x8005F288: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005F28C: b           L_8005F388
    // 0x8005F290: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
        goto L_8005F388;
    // 0x8005F290: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
L_8005F294:
    // 0x8005F294: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005F298: lwc1        $f11, 0x7078($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X7078);
    // 0x8005F29C: lwc1        $f10, 0x707C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X707C);
    // 0x8005F2A0: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x8005F2A4: c.lt.d      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.d < ctx->f0.d;
    // 0x8005F2A8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005F2AC: bc1f        L_8005F320
    if (!c1cs) {
        // 0x8005F2B0: nop
    
            goto L_8005F320;
    }
    // 0x8005F2B0: nop

    // 0x8005F2B4: lwc1        $f5, 0x7080($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X7080);
    // 0x8005F2B8: lwc1        $f4, 0x7084($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7084);
    // 0x8005F2BC: nop

    // 0x8005F2C0: c.lt.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d < ctx->f4.d;
    // 0x8005F2C4: nop

    // 0x8005F2C8: bc1f        L_8005F320
    if (!c1cs) {
        // 0x8005F2CC: nop
    
            goto L_8005F320;
    }
    // 0x8005F2CC: nop

    // 0x8005F2D0: bne         $a0, $v1, L_8005F310
    if (ctx->r4 != ctx->r3) {
        // 0x8005F2D4: nop
    
            goto L_8005F310;
    }
    // 0x8005F2D4: nop

    // 0x8005F2D8: sb          $t1, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r9;
    // 0x8005F2DC: lb          $t6, 0x3B($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X3B);
    // 0x8005F2E0: lw          $t5, 0x44($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X44);
    // 0x8005F2E4: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8005F2E8: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x8005F2EC: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8005F2F0: nop

    // 0x8005F2F4: sll         $t2, $t9, 4
    ctx->r10 = S32(ctx->r25 << 4);
    // 0x8005F2F8: addiu       $t3, $t2, -0x11
    ctx->r11 = ADD32(ctx->r10, -0X11);
    // 0x8005F2FC: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8005F300: nop

    // 0x8005F304: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8005F308: b           L_8005F314
    // 0x8005F30C: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
        goto L_8005F314;
    // 0x8005F30C: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
L_8005F310:
    // 0x8005F310: sb          $zero, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = 0;
L_8005F314:
    // 0x8005F314: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005F318: b           L_8005F388
    // 0x8005F31C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
        goto L_8005F388;
    // 0x8005F31C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
L_8005F320:
    // 0x8005F320: bne         $v1, $zero, L_8005F338
    if (ctx->r3 != 0) {
        // 0x8005F324: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8005F338;
    }
    // 0x8005F324: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8005F328: sb          $t1, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r9;
    // 0x8005F32C: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x8005F330: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005F334: nop

L_8005F338:
    // 0x8005F338: bne         $v1, $at, L_8005F384
    if (ctx->r3 != ctx->r1) {
        // 0x8005F33C: nop
    
            goto L_8005F384;
    }
    // 0x8005F33C: nop

    // 0x8005F340: bne         $a2, $zero, L_8005F384
    if (ctx->r6 != 0) {
        // 0x8005F344: nop
    
            goto L_8005F384;
    }
    // 0x8005F344: nop

    // 0x8005F348: sb          $a3, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r7;
    // 0x8005F34C: lb          $t6, 0x3B($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X3B);
    // 0x8005F350: lw          $t4, 0x44($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X44);
    // 0x8005F354: sll         $t5, $t6, 3
    ctx->r13 = S32(ctx->r14 << 3);
    // 0x8005F358: addu        $t7, $t4, $t5
    ctx->r15 = ADD32(ctx->r12, ctx->r13);
    // 0x8005F35C: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8005F360: nop

    // 0x8005F364: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x8005F368: addiu       $t2, $t9, -0x11
    ctx->r10 = ADD32(ctx->r25, -0X11);
    // 0x8005F36C: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x8005F370: nop

    // 0x8005F374: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8005F378: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    // 0x8005F37C: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005F380: nop

L_8005F384:
    // 0x8005F384: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
L_8005F388:
    // 0x8005F388: lh          $t3, 0x18($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X18);
    // 0x8005F38C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8005F390: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005F394: sh          $t3, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r11;
    // 0x8005F398: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005F39C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005F3A0: sw          $zero, 0x74($s1)
    MEM_W(0X74, ctx->r17) = 0;
    // 0x8005F3A4: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8005F3A8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8005F3AC: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x8005F3B0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8005F3B4: bne         $a0, $v1, L_8005F3D8
    if (ctx->r4 != ctx->r3) {
        // 0x8005F3B8: sh          $t4, 0x18($s1)
        MEM_H(0X18, ctx->r17) = ctx->r12;
            goto L_8005F3D8;
    }
    // 0x8005F3B8: sh          $t4, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r12;
    // 0x8005F3BC: lh          $a2, 0x3C($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X3C);
    // 0x8005F3C0: addiu       $t5, $zero, 0xAD
    ctx->r13 = ADD32(0, 0XAD);
    // 0x8005F3C4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8005F3C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005F3CC: jal         0x800113CC
    // 0x8005F3D0: addiu       $a3, $zero, 0xAC
    ctx->r7 = ADD32(0, 0XAC);
    play_footstep_sounds(rdram, ctx);
        goto after_10;
    // 0x8005F3D0: addiu       $a3, $zero, 0xAC
    ctx->r7 = ADD32(0, 0XAC);
    after_10:
    // 0x8005F3D4: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_8005F3D8:
    // 0x8005F3D8: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x8005F3DC: nop

    // 0x8005F3E0: bne         $t0, $t7, L_8005F414
    if (ctx->r8 != ctx->r15) {
        // 0x8005F3E4: lw          $a1, 0x40($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X40);
            goto L_8005F414;
    }
    // 0x8005F3E4: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8005F3E8: jal         0x8002359C
    // 0x8005F3EC: nop

    func_80023568(rdram, ctx);
        goto after_11;
    // 0x8005F3EC: nop

    after_11:
    // 0x8005F3F0: beq         $v0, $zero, L_8005F410
    if (ctx->r2 == 0) {
        // 0x8005F3F4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8005F410;
    }
    // 0x8005F3F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005F3F8: addiu       $t8, $zero, 0xA5
    ctx->r24 = ADD32(0, 0XA5);
    // 0x8005F3FC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8005F400: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8005F404: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    // 0x8005F408: jal         0x8005E3A4
    // 0x8005F40C: addiu       $a3, $zero, 0x89
    ctx->r7 = ADD32(0, 0X89);
    spawn_boss_hazard(rdram, ctx);
        goto after_12;
    // 0x8005F40C: addiu       $a3, $zero, 0x89
    ctx->r7 = ADD32(0, 0X89);
    after_12:
L_8005F410:
    // 0x8005F410: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
L_8005F414:
    // 0x8005F414: jal         0x800B019C
    // 0x8005F418: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    obj_spawn_particle(rdram, ctx);
        goto after_13;
    // 0x8005F418: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x8005F41C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005F420: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8005F424: jal         0x8005D1E8
    // 0x8005F428: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    fade_when_near_camera(rdram, ctx);
        goto after_14;
    // 0x8005F428: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_14:
    // 0x8005F42C: jal         0x8001BAFC
    // 0x8005F430: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    get_racer_object(rdram, ctx);
        goto after_15;
    // 0x8005F430: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_15:
    // 0x8005F434: lw          $v1, 0x4C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4C);
    // 0x8005F438: lw          $s0, 0x64($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X64);
    // 0x8005F43C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8005F440: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8005F444: bne         $s1, $t9, L_8005F474
    if (ctx->r17 != ctx->r25) {
        // 0x8005F448: addiu       $a1, $a1, -0x2480
        ctx->r5 = ADD32(ctx->r5, -0X2480);
            goto L_8005F474;
    }
    // 0x8005F448: addiu       $a1, $a1, -0x2480
    ctx->r5 = ADD32(ctx->r5, -0X2480);
    // 0x8005F44C: lh          $t2, 0x14($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X14);
    // 0x8005F450: nop

    // 0x8005F454: andi        $t3, $t2, 0x8
    ctx->r11 = ctx->r10 & 0X8;
    // 0x8005F458: beq         $t3, $zero, L_8005F474
    if (ctx->r11 == 0) {
        // 0x8005F45C: nop
    
            goto L_8005F474;
    }
    // 0x8005F45C: nop

    // 0x8005F460: lb          $t6, 0x3B($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X3B);
    // 0x8005F464: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005F468: bne         $t6, $at, L_8005F474
    if (ctx->r14 != ctx->r1) {
        // 0x8005F46C: addiu       $t4, $zero, 0x4
        ctx->r12 = ADD32(0, 0X4);
            goto L_8005F474;
    }
    // 0x8005F46C: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8005F470: sb          $t4, 0x187($s0)
    MEM_B(0X187, ctx->r16) = ctx->r12;
L_8005F474:
    // 0x8005F474: lb          $t5, 0x1D8($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1D8);
    // 0x8005F478: nop

    // 0x8005F47C: beq         $t5, $zero, L_8005F4A0
    if (ctx->r13 == 0) {
        // 0x8005F480: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8005F4A0;
    }
    // 0x8005F480: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005F484: lb          $t7, 0x0($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X0);
    // 0x8005F488: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8005F48C: bne         $t7, $zero, L_8005F49C
    if (ctx->r15 != 0) {
        // 0x8005F490: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8005F49C;
    }
    // 0x8005F490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005F494: jal         0x8005CD08
    // 0x8005F498: sb          $t8, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r24;
    racer_boss_finish(rdram, ctx);
        goto after_16;
    // 0x8005F498: sb          $t8, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r24;
    after_16:
L_8005F49C:
    // 0x8005F49C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005F4A0:
    // 0x8005F4A0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8005F4A4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8005F4A8: jr          $ra
    // 0x8005F4AC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8005F4AC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void update_rocket(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F4B0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8005F4B4: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8005F4B8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005F4BC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8005F4C0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005F4C4: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8005F4C8: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8005F4CC: addiu       $a0, $a0, -0x2C10
    ctx->r4 = ADD32(ctx->r4, -0X2C10);
    // 0x8005F4D0: jal         0x8005CC18
    // 0x8005F4D4: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    set_boss_voice_clip_offset(rdram, ctx);
        goto after_0;
    // 0x8005F4D4: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8005F4D8: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8005F4DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005F4E0: sb          $zero, 0x1EC($a3)
    MEM_B(0X1EC, ctx->r7) = 0;
    // 0x8005F4E4: lb          $t6, 0x3B($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X3B);
    // 0x8005F4E8: lwc1        $f6, 0x7094($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7094);
    // 0x8005F4EC: sh          $t6, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r14;
    // 0x8005F4F0: lh          $t7, 0x18($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X18);
    // 0x8005F4F4: lwc1        $f7, 0x7090($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X7090);
    // 0x8005F4F8: sh          $t7, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r15;
    // 0x8005F4FC: lh          $t8, 0x16A($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X16A);
    // 0x8005F500: nop

    // 0x8005F504: sh          $t8, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r24;
    // 0x8005F508: lwc1        $f4, 0x2C($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X2C);
    // 0x8005F50C: nop

    // 0x8005F510: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x8005F514: c.lt.d      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.d < ctx->f6.d;
    // 0x8005F518: nop

    // 0x8005F51C: bc1f        L_8005F544
    if (!c1cs) {
        // 0x8005F520: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8005F544;
    }
    // 0x8005F520: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005F524: lwc1        $f9, 0x7098($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X7098);
    // 0x8005F528: lwc1        $f8, 0x709C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X709C);
    // 0x8005F52C: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8005F530: c.lt.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d < ctx->f0.d;
    // 0x8005F534: nop

    // 0x8005F538: bc1f        L_8005F544
    if (!c1cs) {
        // 0x8005F53C: nop
    
            goto L_8005F544;
    }
    // 0x8005F53C: nop

    // 0x8005F540: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
L_8005F544:
    // 0x8005F544: lb          $t2, 0x1D8($a3)
    ctx->r10 = MEM_B(ctx->r7, 0X1D8);
    // 0x8005F548: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005F54C: bne         $t2, $at, L_8005F58C
    if (ctx->r10 != ctx->r1) {
        // 0x8005F550: lw          $t1, 0x58($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X58);
            goto L_8005F58C;
    }
    // 0x8005F550: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x8005F554: jal         0x8002359C
    // 0x8005F558: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    func_80023568(rdram, ctx);
        goto after_1;
    // 0x8005F558: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_1:
    // 0x8005F55C: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8005F560: beq         $v0, $zero, L_8005F588
    if (ctx->r2 == 0) {
        // 0x8005F564: addiu       $a0, $zero, 0x82
        ctx->r4 = ADD32(0, 0X82);
            goto L_8005F588;
    }
    // 0x8005F564: addiu       $a0, $zero, 0x82
    ctx->r4 = ADD32(0, 0X82);
    // 0x8005F568: jal         0x80021434
    // 0x8005F56C: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    func_80021400(rdram, ctx);
        goto after_2;
    // 0x8005F56C: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_2:
    // 0x8005F570: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8005F574: nop

    // 0x8005F578: lb          $t3, 0x1D8($a3)
    ctx->r11 = MEM_B(ctx->r7, 0X1D8);
    // 0x8005F57C: nop

    // 0x8005F580: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8005F584: sb          $t4, 0x1D8($a3)
    MEM_B(0X1D8, ctx->r7) = ctx->r12;
L_8005F588:
    // 0x8005F588: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
L_8005F58C:
    // 0x8005F58C: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8005F590: lw          $t0, 0x0($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X0);
    // 0x8005F594: nop

    // 0x8005F598: bne         $t0, $at, L_8005F5A4
    if (ctx->r8 != ctx->r1) {
        // 0x8005F59C: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8005F5A4;
    }
    // 0x8005F59C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005F5A0: sb          $zero, -0x2470($at)
    MEM_B(-0X2470, ctx->r1) = 0;
L_8005F5A4:
    // 0x8005F5A4: lh          $t5, 0x0($a3)
    ctx->r13 = MEM_H(ctx->r7, 0X0);
    // 0x8005F5A8: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8005F5AC: bne         $v1, $t5, L_8005F62C
    if (ctx->r3 != ctx->r13) {
        // 0x8005F5B0: sb          $zero, 0x1F5($a3)
        MEM_B(0X1F5, ctx->r7) = 0;
            goto L_8005F62C;
    }
    // 0x8005F5B0: sb          $zero, 0x1F5($a3)
    MEM_B(0X1F5, ctx->r7) = 0;
    // 0x8005F5B4: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x8005F5B8: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8005F5BC: beq         $v0, $at, L_8005F62C
    if (ctx->r2 == ctx->r1) {
        // 0x8005F5C0: addiu       $t6, $v0, -0x1E
        ctx->r14 = ADD32(ctx->r2, -0X1E);
            goto L_8005F62C;
    }
    // 0x8005F5C0: addiu       $t6, $v0, -0x1E
    ctx->r14 = ADD32(ctx->r2, -0X1E);
    // 0x8005F5C4: bgez        $t6, L_8005F624
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8005F5C8: sw          $t6, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r14;
            goto L_8005F624;
    }
    // 0x8005F5C8: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8005F5CC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8005F5D0: lb          $t8, -0x246F($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X246F);
    // 0x8005F5D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005F5D8: bne         $t8, $zero, L_8005F600
    if (ctx->r24 != 0) {
        // 0x8005F5DC: lw          $v0, 0x50($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X50);
            goto L_8005F600;
    }
    // 0x8005F5DC: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
    // 0x8005F5E0: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x8005F5E4: jal         0x8005CCA4
    // 0x8005F5E8: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    play_random_boss_sound(rdram, ctx);
        goto after_3;
    // 0x8005F5E8: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_3:
    // 0x8005F5EC: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8005F5F0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8005F5F4: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x8005F5F8: nop

    // 0x8005F5FC: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
L_8005F600:
    // 0x8005F600: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8005F604: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005F608: sb          $t9, -0x246F($at)
    MEM_B(-0X246F, ctx->r1) = ctx->r25;
    // 0x8005F60C: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x8005F610: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8005F614: nop

    // 0x8005F618: ori         $t3, $t2, 0x8000
    ctx->r11 = ctx->r10 | 0X8000;
    // 0x8005F61C: b           L_8005F62C
    // 0x8005F620: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
        goto L_8005F62C;
    // 0x8005F620: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_8005F624:
    // 0x8005F624: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005F628: sb          $zero, -0x246F($at)
    MEM_B(-0X246F, ctx->r1) = 0;
L_8005F62C:
    // 0x8005F62C: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x8005F630: sb          $t4, 0x1D6($a3)
    MEM_B(0X1D6, ctx->r7) = ctx->r12;
    // 0x8005F634: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8005F638: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8005F63C: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8005F640: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x8005F644: jal         0x800497D4
    // 0x8005F648: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_80049794(rdram, ctx);
        goto after_4;
    // 0x8005F648: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_4:
    // 0x8005F64C: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8005F650: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8005F654: lb          $t5, 0x1D7($a3)
    ctx->r13 = MEM_B(ctx->r7, 0X1D7);
    // 0x8005F658: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8005F65C: sb          $t5, 0x1D6($a3)
    MEM_B(0X1D6, ctx->r7) = ctx->r13;
    // 0x8005F660: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x8005F664: nop

    // 0x8005F668: sw          $t0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r8;
    // 0x8005F66C: sw          $zero, 0x74($s0)
    MEM_W(0X74, ctx->r16) = 0;
    // 0x8005F670: lh          $t7, 0x3A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X3A);
    // 0x8005F674: nop

    // 0x8005F678: sh          $t7, 0x16A($a3)
    MEM_H(0X16A, ctx->r7) = ctx->r15;
    // 0x8005F67C: lh          $t8, 0x3E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X3E);
    // 0x8005F680: nop

    // 0x8005F684: sb          $t8, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r24;
    // 0x8005F688: lh          $t9, 0x3C($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X3C);
    // 0x8005F68C: nop

    // 0x8005F690: sh          $t9, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r25;
    // 0x8005F694: lb          $t2, 0x187($a3)
    ctx->r10 = MEM_B(ctx->r7, 0X187);
    // 0x8005F698: nop

    // 0x8005F69C: beq         $t2, $zero, L_8005F744
    if (ctx->r10 == 0) {
        // 0x8005F6A0: nop
    
            goto L_8005F744;
    }
    // 0x8005F6A0: nop

    // 0x8005F6A4: lb          $t3, 0x3B($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X3B);
    // 0x8005F6A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005F6AC: beq         $t3, $at, L_8005F744
    if (ctx->r11 == ctx->r1) {
        // 0x8005F6B0: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8005F744;
    }
    // 0x8005F6B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8005F6B4: jal         0x8005CCA4
    // 0x8005F6B8: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    play_random_boss_sound(rdram, ctx);
        goto after_5;
    // 0x8005F6B8: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_5:
    // 0x8005F6BC: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    // 0x8005F6C0: jal         0x80001D04
    // 0x8005F6C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_6;
    // 0x8005F6C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x8005F6C8: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8005F6CC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8005F6D0: jal         0x8006A168
    // 0x8005F6D4: nop

    set_camera_shake(rdram, ctx);
        goto after_7;
    // 0x8005F6D4: nop

    after_7:
    // 0x8005F6D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005F6DC: lwc1        $f10, 0x1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8005F6E0: lwc1        $f1, 0x70A0($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, 0X70A0);
    // 0x8005F6E4: lwc1        $f0, 0x70A4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X70A4);
    // 0x8005F6E8: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8005F6EC: mul.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x8005F6F0: lwc1        $f10, 0x24($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8005F6F4: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8005F6F8: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8005F6FC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005F700: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8005F704: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8005F708: mul.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x8005F70C: swc1        $f8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
    // 0x8005F710: sb          $t4, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r12;
    // 0x8005F714: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8005F718: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8005F71C: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8005F720: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8005F724: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    // 0x8005F728: swc1        $f18, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f18.u32l;
    // 0x8005F72C: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8005F730: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8005F734: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8005F738: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x8005F73C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8005F740: swc1        $f10, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f10.u32l;
L_8005F744:
    // 0x8005F744: lw          $t5, 0x148($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X148);
    // 0x8005F748: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005F74C: beq         $t5, $zero, L_8005F7BC
    if (ctx->r13 == 0) {
        // 0x8005F750: sb          $zero, 0x187($a3)
        MEM_B(0X187, ctx->r7) = 0;
            goto L_8005F7BC;
    }
    // 0x8005F750: sb          $zero, 0x187($a3)
    MEM_B(0X187, ctx->r7) = 0;
    // 0x8005F754: lwc1        $f0, 0x1C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8005F758: lwc1        $f14, 0x24($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8005F75C: mul.s       $f2, $f0, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8005F760: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x8005F764: mul.s       $f16, $f14, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8005F768: nop

    // 0x8005F76C: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8005F770: nop

    // 0x8005F774: mul.s       $f6, $f16, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8005F778: jal         0x800CA030
    // 0x8005F77C: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_8;
    // 0x8005F77C: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_8:
    // 0x8005F780: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x8005F784: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8005F788: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8005F78C: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x8005F790: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x8005F794: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8005F798: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x8005F79C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005F7A0: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8005F7A4: bc1f        L_8005F7BC
    if (!c1cs) {
        // 0x8005F7A8: swc1        $f2, 0x2C($a3)
        MEM_W(0X2C, ctx->r7) = ctx->f2.u32l;
            goto L_8005F7BC;
    }
    // 0x8005F7A8: swc1        $f2, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->f2.u32l;
    // 0x8005F7AC: swc1        $f18, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->f18.u32l;
    // 0x8005F7B0: swc1        $f18, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f18.u32l;
    // 0x8005F7B4: swc1        $f18, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f18.u32l;
    // 0x8005F7B8: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
L_8005F7BC:
    // 0x8005F7BC: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8005F7C0: lwc1        $f6, 0xC($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8005F7C4: cvt.d.s     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f12.d = CVT_D_S(ctx->f4.fl);
    // 0x8005F7C8: add.d       $f10, $f12, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f12.d); 
    ctx->f10.d = ctx->f12.d + ctx->f12.d;
    // 0x8005F7CC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8005F7D0: add.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f8.d + ctx->f10.d;
    // 0x8005F7D4: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8005F7D8: swc1        $f6, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f6.u32l;
    // 0x8005F7DC: lw          $t6, 0x68($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X68);
    // 0x8005F7E0: lb          $t8, 0x3B($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X3B);
    // 0x8005F7E4: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x8005F7E8: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8005F7EC: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8005F7F0: lwc1        $f0, 0xC($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8005F7F4: lw          $t7, 0x44($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X44);
    // 0x8005F7F8: nop

    // 0x8005F7FC: addu        $t2, $t7, $t9
    ctx->r10 = ADD32(ctx->r15, ctx->r25);
    // 0x8005F800: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x8005F804: nop

    // 0x8005F808: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x8005F80C: addiu       $t5, $t4, -0x11
    ctx->r13 = ADD32(ctx->r12, -0X11);
    // 0x8005F810: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x8005F814: nop

    // 0x8005F818: cvt.s.w     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    ctx->f2.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8005F81C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8005F820: nop

    // 0x8005F824: bc1f        L_8005F850
    if (!c1cs) {
        // 0x8005F828: nop
    
            goto L_8005F850;
    }
    // 0x8005F828: nop

L_8005F82C:
    // 0x8005F82C: sub.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8005F830: swc1        $f10, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f10.u32l;
    // 0x8005F834: sh          $v1, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r3;
    // 0x8005F838: lwc1        $f0, 0xC($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8005F83C: nop

    // 0x8005F840: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8005F844: nop

    // 0x8005F848: bc1t        L_8005F82C
    if (c1cs) {
        // 0x8005F84C: nop
    
            goto L_8005F82C;
    }
    // 0x8005F84C: nop

L_8005F850:
    // 0x8005F850: c.le.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl <= ctx->f18.fl;
    // 0x8005F854: nop

    // 0x8005F858: bc1f        L_8005F884
    if (!c1cs) {
        // 0x8005F85C: nop
    
            goto L_8005F884;
    }
    // 0x8005F85C: nop

L_8005F860:
    // 0x8005F860: add.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8005F864: swc1        $f4, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f4.u32l;
    // 0x8005F868: sh          $v1, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r3;
    // 0x8005F86C: lwc1        $f0, 0xC($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8005F870: nop

    // 0x8005F874: c.le.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl <= ctx->f18.fl;
    // 0x8005F878: nop

    // 0x8005F87C: bc1t        L_8005F860
    if (c1cs) {
        // 0x8005F880: nop
    
            goto L_8005F860;
    }
    // 0x8005F880: nop

L_8005F884:
    // 0x8005F884: lb          $t6, 0x3B($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X3B);
    // 0x8005F888: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005F88C: bne         $t6, $at, L_8005F8B4
    if (ctx->r14 != ctx->r1) {
        // 0x8005F890: nop
    
            goto L_8005F8B4;
    }
    // 0x8005F890: nop

    // 0x8005F894: lh          $t8, 0x10($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X10);
    // 0x8005F898: nop

    // 0x8005F89C: bne         $v1, $t8, L_8005F8B4
    if (ctx->r3 != ctx->r24) {
        // 0x8005F8A0: nop
    
            goto L_8005F8B4;
    }
    // 0x8005F8A0: nop

    // 0x8005F8A4: sb          $zero, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = 0;
    // 0x8005F8A8: swc1        $f18, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f18.u32l;
    // 0x8005F8AC: lwc1        $f0, 0xC($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8005F8B0: nop

L_8005F8B4:
    // 0x8005F8B4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8005F8B8: sw          $zero, 0x74($s0)
    MEM_W(0X74, ctx->r16) = 0;
    // 0x8005F8BC: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8005F8C0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005F8C4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005F8C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005F8CC: cvt.w.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = CVT_W_S(ctx->f0.fl);
    // 0x8005F8D0: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x8005F8D4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8005F8D8: sh          $t9, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r25;
    // 0x8005F8DC: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8005F8E0: jal         0x800AFC74
    // 0x8005F8E4: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    update_vehicle_particles(rdram, ctx);
        goto after_9;
    // 0x8005F8E4: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_9:
    // 0x8005F8E8: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8005F8EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005F8F0: jal         0x8005D1E8
    // 0x8005F8F4: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    fade_when_near_camera(rdram, ctx);
        goto after_10;
    // 0x8005F8F4: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_10:
    // 0x8005F8F8: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x8005F8FC: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8005F900: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8005F904: nop

    // 0x8005F908: beq         $t3, $at, L_8005F96C
    if (ctx->r11 == ctx->r1) {
        // 0x8005F90C: nop
    
            goto L_8005F96C;
    }
    // 0x8005F90C: nop

    // 0x8005F910: jal         0x8000BF44
    // 0x8005F914: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    racerfx_get_boost(rdram, ctx);
        goto after_11;
    // 0x8005F914: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_11:
    // 0x8005F918: beq         $v0, $zero, L_8005F96C
    if (ctx->r2 == 0) {
        // 0x8005F91C: nop
    
            goto L_8005F96C;
    }
    // 0x8005F91C: nop

    // 0x8005F920: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x8005F924: sw          $zero, 0x78($v0)
    MEM_W(0X78, ctx->r2) = 0;
    // 0x8005F928: beq         $v1, $zero, L_8005F96C
    if (ctx->r3 == 0) {
        // 0x8005F92C: addiu       $t8, $zero, 0x2
        ctx->r24 = ADD32(0, 0X2);
            goto L_8005F96C;
    }
    // 0x8005F92C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8005F930: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8005F934: lbu         $t4, 0x72($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X72);
    // 0x8005F938: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005F93C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8005F940: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8005F944: sb          $t6, 0x72($v1)
    MEM_B(0X72, ctx->r3) = ctx->r14;
    // 0x8005F948: sb          $t8, 0x70($v1)
    MEM_B(0X70, ctx->r3) = ctx->r24;
    // 0x8005F94C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8005F950: swc1        $f8, 0x74($v1)
    MEM_W(0X74, ctx->r3) = ctx->f8.u32l;
    // 0x8005F954: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8005F958: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005F95C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8005F960: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8005F964: jal         0x8000B750
    // 0x8005F968: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8000B750(rdram, ctx);
        goto after_12;
    // 0x8005F968: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_12:
L_8005F96C:
    // 0x8005F96C: jal         0x8001BAFC
    // 0x8005F970: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    get_racer_object(rdram, ctx);
        goto after_13;
    // 0x8005F970: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_13:
    // 0x8005F974: lw          $v1, 0x4C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4C);
    // 0x8005F978: lw          $a3, 0x64($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X64);
    // 0x8005F97C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8005F980: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8005F984: bne         $s0, $t9, L_8005F9B4
    if (ctx->r16 != ctx->r25) {
        // 0x8005F988: addiu       $a1, $a1, -0x2470
        ctx->r5 = ADD32(ctx->r5, -0X2470);
            goto L_8005F9B4;
    }
    // 0x8005F988: addiu       $a1, $a1, -0x2470
    ctx->r5 = ADD32(ctx->r5, -0X2470);
    // 0x8005F98C: lh          $t2, 0x14($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X14);
    // 0x8005F990: nop

    // 0x8005F994: andi        $t3, $t2, 0x8
    ctx->r11 = ctx->r10 & 0X8;
    // 0x8005F998: beq         $t3, $zero, L_8005F9B4
    if (ctx->r11 == 0) {
        // 0x8005F99C: nop
    
            goto L_8005F9B4;
    }
    // 0x8005F99C: nop

    // 0x8005F9A0: lb          $t4, 0x3B($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X3B);
    // 0x8005F9A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005F9A8: bne         $t4, $at, L_8005F9B4
    if (ctx->r12 != ctx->r1) {
        // 0x8005F9AC: addiu       $t5, $zero, 0x4
        ctx->r13 = ADD32(0, 0X4);
            goto L_8005F9B4;
    }
    // 0x8005F9AC: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x8005F9B0: sb          $t5, 0x187($a3)
    MEM_B(0X187, ctx->r7) = ctx->r13;
L_8005F9B4:
    // 0x8005F9B4: lb          $t6, 0x1D8($a3)
    ctx->r14 = MEM_B(ctx->r7, 0X1D8);
    // 0x8005F9B8: nop

    // 0x8005F9BC: beq         $t6, $zero, L_8005F9E0
    if (ctx->r14 == 0) {
        // 0x8005F9C0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8005F9E0;
    }
    // 0x8005F9C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005F9C4: lb          $t8, 0x0($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X0);
    // 0x8005F9C8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8005F9CC: bne         $t8, $zero, L_8005F9DC
    if (ctx->r24 != 0) {
        // 0x8005F9D0: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8005F9DC;
    }
    // 0x8005F9D0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8005F9D4: jal         0x8005CD08
    // 0x8005F9D8: sb          $t7, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r15;
    racer_boss_finish(rdram, ctx);
        goto after_14;
    // 0x8005F9D8: sb          $t7, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r15;
    after_14:
L_8005F9DC:
    // 0x8005F9DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005F9E0:
    // 0x8005F9E0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8005F9E4: jr          $ra
    // 0x8005F9E8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8005F9E8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8005F9EC: nop

;}
RECOMP_FUNC void allocate_object_model_pools(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F9F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005F9F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005F9F8: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x8005F9FC: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x8005FA00: jal         0x80070EDC
    // 0x8005FA04: addiu       $a0, $zero, 0x230
    ctx->r4 = ADD32(0, 0X230);
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x8005FA04: addiu       $a0, $zero, 0x230
    ctx->r4 = ADD32(0, 0X230);
    after_0:
    // 0x8005FA08: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005FA0C: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x8005FA10: sw          $v0, -0x245C($at)
    MEM_W(-0X245C, ctx->r1) = ctx->r2;
    // 0x8005FA14: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x8005FA18: jal         0x80070EDC
    // 0x8005FA1C: addiu       $a0, $zero, 0x190
    ctx->r4 = ADD32(0, 0X190);
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x8005FA1C: addiu       $a0, $zero, 0x190
    ctx->r4 = ADD32(0, 0X190);
    after_1:
    // 0x8005FA20: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005FA24: sw          $v0, -0x2458($at)
    MEM_W(-0X2458, ctx->r1) = ctx->r2;
    // 0x8005FA28: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005FA2C: sw          $zero, -0x2454($at)
    MEM_W(-0X2454, ctx->r1) = 0;
    // 0x8005FA30: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005FA34: sw          $zero, -0x244C($at)
    MEM_W(-0X244C, ctx->r1) = 0;
    // 0x8005FA38: jal         0x80076EE4
    // 0x8005FA3C: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    asset_table_load(rdram, ctx);
        goto after_2;
    // 0x8005FA3C: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_2:
    // 0x8005FA40: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8005FA44: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8005FA48: addiu       $a3, $a3, -0x2460
    ctx->r7 = ADD32(ctx->r7, -0X2460);
    // 0x8005FA4C: addiu       $a1, $a1, -0x2450
    ctx->r5 = ADD32(ctx->r5, -0X2450);
    // 0x8005FA50: sll         $t6, $zero, 2
    ctx->r14 = S32(0 << 2);
    // 0x8005FA54: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x8005FA58: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x8005FA5C: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x8005FA60: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8005FA64: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8005FA68: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8005FA6C: beq         $a2, $t8, L_8005FA94
    if (ctx->r6 == ctx->r24) {
        // 0x8005FA70: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8005FA94;
    }
    // 0x8005FA70: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8005FA74: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
L_8005FA78:
    // 0x8005FA78: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8005FA7C: addu        $t1, $a0, $t0
    ctx->r9 = ADD32(ctx->r4, ctx->r8);
    // 0x8005FA80: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8005FA84: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8005FA88: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x8005FA8C: bne         $a2, $t2, L_8005FA78
    if (ctx->r6 != ctx->r10) {
        // 0x8005FA90: addiu       $t9, $v1, 0x1
        ctx->r25 = ADD32(ctx->r3, 0X1);
            goto L_8005FA78;
    }
    // 0x8005FA90: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
L_8005FA94:
    // 0x8005FA94: addiu       $t3, $v1, -0x1
    ctx->r11 = ADD32(ctx->r3, -0X1);
    // 0x8005FA98: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x8005FA9C: jal         0x80076EE4
    // 0x8005FAA0: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    asset_table_load(rdram, ctx);
        goto after_3;
    // 0x8005FAA0: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_3:
    // 0x8005FAA4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005FAA8: sw          $v0, -0x2448($at)
    MEM_W(-0X2448, ctx->r1) = ctx->r2;
    // 0x8005FAAC: jal         0x80076EE4
    // 0x8005FAB0: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    asset_table_load(rdram, ctx);
        goto after_4;
    // 0x8005FAB0: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_4:
    // 0x8005FAB4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005FAB8: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x8005FABC: sw          $v0, -0x2444($at)
    MEM_W(-0X2444, ctx->r1) = ctx->r2;
    // 0x8005FAC0: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x8005FAC4: jal         0x80070EDC
    // 0x8005FAC8: addiu       $a0, $zero, 0xC00
    ctx->r4 = ADD32(0, 0XC00);
    mempool_alloc_safe(rdram, ctx);
        goto after_5;
    // 0x8005FAC8: addiu       $a0, $zero, 0xC00
    ctx->r4 = ADD32(0, 0XC00);
    after_5:
    // 0x8005FACC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005FAD0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8005FAD4: lw          $a1, -0x2BEC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X2BEC);
    // 0x8005FAD8: sw          $v0, -0x243C($at)
    MEM_W(-0X243C, ctx->r1) = ctx->r2;
    // 0x8005FADC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005FAE0: sw          $zero, -0x2440($at)
    MEM_W(-0X2440, ctx->r1) = 0;
    // 0x8005FAE4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005FAE8: blez        $a1, L_8005FB10
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8005FAEC: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8005FB10;
    }
    // 0x8005FAEC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8005FAF0: lui         $v0, 0x8002
    ctx->r2 = S32(0X8002 << 16);
    // 0x8005FAF4: addiu       $v0, $v0, 0x4D94
    ctx->r2 = ADD32(ctx->r2, 0X4D94);
L_8005FAF8:
    // 0x8005FAF8: addu        $t4, $v0, $v1
    ctx->r12 = ADD32(ctx->r2, ctx->r3);
    // 0x8005FAFC: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x8005FB00: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8005FB04: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8005FB08: bne         $at, $zero, L_8005FAF8
    if (ctx->r1 != 0) {
        // 0x8005FB0C: addu        $a0, $a0, $t5
        ctx->r4 = ADD32(ctx->r4, ctx->r13);
            goto L_8005FAF8;
    }
    // 0x8005FB0C: addu        $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
L_8005FB10:
    // 0x8005FB10: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8005FB14: lw          $t6, -0x2BF0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2BF0);
    // 0x8005FB18: nop

    // 0x8005FB1C: beq         $a0, $t6, L_8005FB30
    if (ctx->r4 == ctx->r14) {
        // 0x8005FB20: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005FB30;
    }
    // 0x8005FB20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005FB24: jal         0x8005C3FC
    // 0x8005FB28: nop

    drm_vehicle_traction(rdram, ctx);
        goto after_6;
    // 0x8005FB28: nop

    after_6:
    // 0x8005FB2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005FB30:
    // 0x8005FB30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005FB34: jr          $ra
    // 0x8005FB38: nop

    return;
    // 0x8005FB38: nop

;}
RECOMP_FUNC void object_model_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005FB3C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8005FB40: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8005FB44: lw          $t6, -0x2450($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2450);
    // 0x8005FB48: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8005FB4C: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8005FB50: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8005FB54: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005FB58: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8005FB5C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005FB60: bne         $at, $zero, L_8005FB6C
    if (ctx->r1 != 0) {
        // 0x8005FB64: sw          $a1, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r5;
            goto L_8005FB6C;
    }
    // 0x8005FB64: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8005FB68: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8005FB6C:
    // 0x8005FB6C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8005FB70: addiu       $t1, $t1, -0x2454
    ctx->r9 = ADD32(ctx->r9, -0X2454);
    // 0x8005FB74: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x8005FB78: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8005FB7C: blez        $a0, L_8005FBDC
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8005FB80: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_8005FBDC;
    }
    // 0x8005FB80: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005FB84: lw          $v1, -0x245C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X245C);
    // 0x8005FB88: nop

    // 0x8005FB8C: sll         $t8, $t0, 3
    ctx->r24 = S32(ctx->r8 << 3);
L_8005FB90:
    // 0x8005FB90: addu        $v0, $v1, $t8
    ctx->r2 = ADD32(ctx->r3, ctx->r24);
    // 0x8005FB94: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8005FB98: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8005FB9C: bne         $s2, $t9, L_8005FBD4
    if (ctx->r18 != ctx->r25) {
        // 0x8005FBA0: slt         $at, $t0, $a0
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8005FBD4;
    }
    // 0x8005FBA0: slt         $at, $t0, $a0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8005FBA4: lw          $s1, 0x4($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X4);
    // 0x8005FBA8: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x8005FBAC: jal         0x8005FF10
    // 0x8005FBB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    model_instance_init(rdram, ctx);
        goto after_0;
    // 0x8005FBB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x8005FBB4: beq         $v0, $zero, L_8005FBCC
    if (ctx->r2 == 0) {
        // 0x8005FBB8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8005FBCC;
    }
    // 0x8005FBB8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8005FBBC: lh          $t2, 0x30($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X30);
    // 0x8005FBC0: nop

    // 0x8005FBC4: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8005FBC8: sh          $t3, 0x30($s1)
    MEM_H(0X30, ctx->r17) = ctx->r11;
L_8005FBCC:
    // 0x8005FBCC: b           L_8005FEF8
    // 0x8005FBD0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8005FEF8;
    // 0x8005FBD0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8005FBD4:
    // 0x8005FBD4: bne         $at, $zero, L_8005FB90
    if (ctx->r1 != 0) {
        // 0x8005FBD8: sll         $t8, $t0, 3
        ctx->r24 = S32(ctx->r8 << 3);
            goto L_8005FB90;
    }
    // 0x8005FBD8: sll         $t8, $t0, 3
    ctx->r24 = S32(ctx->r8 << 3);
L_8005FBDC:
    // 0x8005FBDC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005FBE0: addiu       $v1, $v1, -0x244C
    ctx->r3 = ADD32(ctx->r3, -0X244C);
    // 0x8005FBE4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8005FBE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005FBEC: blez        $v0, L_8005FC1C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8005FBF0: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_8005FC1C;
    }
    // 0x8005FBF0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8005FBF4: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x8005FBF8: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8005FBFC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8005FC00: lw          $t5, -0x2458($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2458);
    // 0x8005FC04: sll         $t7, $t4, 2
    ctx->r15 = S32(ctx->r12 << 2);
    // 0x8005FC08: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x8005FC0C: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8005FC10: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005FC14: b           L_8005FC2C
    // 0x8005FC18: sw          $t9, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r25;
        goto L_8005FC2C;
    // 0x8005FC18: sw          $t9, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r25;
L_8005FC1C:
    // 0x8005FC1C: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
    // 0x8005FC20: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8005FC24: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8005FC28: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
L_8005FC2C:
    // 0x8005FC2C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8005FC30: lw          $t3, -0x2460($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2460);
    // 0x8005FC34: sll         $t4, $s2, 2
    ctx->r12 = S32(ctx->r18 << 2);
    // 0x8005FC38: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
    // 0x8005FC3C: lw          $s0, 0x0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X0);
    // 0x8005FC40: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x8005FC44: sb          $a3, 0x3D($sp)
    MEM_B(0X3D, ctx->r29) = ctx->r7;
    // 0x8005FC48: subu        $t5, $t6, $s0
    ctx->r13 = SUB32(ctx->r14, ctx->r16);
    // 0x8005FC4C: sw          $t5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r13;
    // 0x8005FC50: sb          $a2, 0x3E($sp)
    MEM_B(0X3E, ctx->r29) = ctx->r6;
    // 0x8005FC54: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    // 0x8005FC58: jal         0x800C673C
    // 0x8005FC5C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    gzip_size_uncompressed(rdram, ctx);
        goto after_1;
    // 0x8005FC5C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x8005FC60: addiu       $a0, $v0, 0x80
    ctx->r4 = ADD32(ctx->r2, 0X80);
    // 0x8005FC64: lui         $a1, 0xFF00
    ctx->r5 = S32(0XFF00 << 16);
    // 0x8005FC68: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // 0x8005FC6C: jal         0x80070F50
    // 0x8005FC70: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    mempool_alloc(rdram, ctx);
        goto after_2;
    // 0x8005FC70: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    after_2:
    // 0x8005FC74: bne         $v0, $zero, L_8005FCC4
    if (ctx->r2 != 0) {
        // 0x8005FC78: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_8005FCC4;
    }
    // 0x8005FC78: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8005FC7C: lb          $t7, 0x3E($sp)
    ctx->r15 = MEM_B(ctx->r29, 0X3E);
    // 0x8005FC80: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005FC84: beq         $t7, $zero, L_8005FC9C
    if (ctx->r15 == 0) {
        // 0x8005FC88: addiu       $v0, $v0, -0x244C
        ctx->r2 = ADD32(ctx->r2, -0X244C);
            goto L_8005FC9C;
    }
    // 0x8005FC88: addiu       $v0, $v0, -0x244C
    ctx->r2 = ADD32(ctx->r2, -0X244C);
    // 0x8005FC8C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8005FC90: nop

    // 0x8005FC94: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8005FC98: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_8005FC9C:
    // 0x8005FC9C: lb          $t2, 0x3D($sp)
    ctx->r10 = MEM_B(ctx->r29, 0X3D);
    // 0x8005FCA0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005FCA4: beq         $t2, $zero, L_8005FCBC
    if (ctx->r10 == 0) {
        // 0x8005FCA8: addiu       $v0, $v0, -0x2454
        ctx->r2 = ADD32(ctx->r2, -0X2454);
            goto L_8005FCBC;
    }
    // 0x8005FCA8: addiu       $v0, $v0, -0x2454
    ctx->r2 = ADD32(ctx->r2, -0X2454);
    // 0x8005FCAC: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8005FCB0: nop

    // 0x8005FCB4: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x8005FCB8: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_8005FCBC:
    // 0x8005FCBC: b           L_8005FEF8
    // 0x8005FCC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005FEF8;
    // 0x8005FCC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005FCC4:
    // 0x8005FCC4: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8005FCC8: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x8005FCCC: addu        $t5, $s1, $t6
    ctx->r13 = ADD32(ctx->r17, ctx->r14);
    // 0x8005FCD0: subu        $a1, $t5, $a3
    ctx->r5 = SUB32(ctx->r13, ctx->r7);
    // 0x8005FCD4: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x8005FCD8: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    // 0x8005FCDC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8005FCE0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8005FCE4: jal         0x80077190
    // 0x8005FCE8: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    asset_load(rdram, ctx);
        goto after_3;
    // 0x8005FCE8: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    after_3:
    // 0x8005FCEC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8005FCF0: jal         0x800C6778
    // 0x8005FCF4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    gzip_inflate(rdram, ctx);
        goto after_4;
    // 0x8005FCF4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x8005FCF8: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x8005FCFC: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x8005FD00: lw          $t9, 0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4);
    // 0x8005FD04: lw          $t3, 0x8($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X8);
    // 0x8005FD08: lw          $t6, 0x38($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X38);
    // 0x8005FD0C: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x8005FD10: addu        $t2, $t9, $s1
    ctx->r10 = ADD32(ctx->r25, ctx->r17);
    // 0x8005FD14: addu        $t4, $t3, $s1
    ctx->r12 = ADD32(ctx->r11, ctx->r17);
    // 0x8005FD18: lw          $t7, 0x14($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X14);
    // 0x8005FD1C: lw          $t9, 0x1C($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X1C);
    // 0x8005FD20: lw          $t3, 0x4C($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X4C);
    // 0x8005FD24: lh          $a0, 0x22($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X22);
    // 0x8005FD28: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x8005FD2C: sw          $t2, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r10;
    // 0x8005FD30: sw          $t4, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r12;
    // 0x8005FD34: addu        $t5, $t6, $s1
    ctx->r13 = ADD32(ctx->r14, ctx->r17);
    // 0x8005FD38: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005FD3C: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x8005FD40: addu        $t2, $t9, $s1
    ctx->r10 = ADD32(ctx->r25, ctx->r17);
    // 0x8005FD44: addu        $t4, $t3, $s1
    ctx->r12 = ADD32(ctx->r11, ctx->r17);
    // 0x8005FD48: sw          $t5, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->r13;
    // 0x8005FD4C: sw          $t8, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r24;
    // 0x8005FD50: sw          $t2, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r10;
    // 0x8005FD54: sw          $t4, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->r12;
    // 0x8005FD58: sh          $t6, 0x30($s1)
    MEM_H(0X30, ctx->r17) = ctx->r14;
    // 0x8005FD5C: sw          $zero, 0xC($s1)
    MEM_W(0XC, ctx->r17) = 0;
    // 0x8005FD60: sw          $zero, 0x10($s1)
    MEM_W(0X10, ctx->r17) = 0;
    // 0x8005FD64: sh          $zero, 0x32($s1)
    MEM_H(0X32, ctx->r17) = 0;
    // 0x8005FD68: sh          $zero, 0x52($s1)
    MEM_H(0X52, ctx->r17) = 0;
    // 0x8005FD6C: sw          $zero, 0x40($s1)
    MEM_W(0X40, ctx->r17) = 0;
    // 0x8005FD70: sh          $zero, 0x48($s1)
    MEM_H(0X48, ctx->r17) = 0;
    // 0x8005FD74: sw          $zero, 0x44($s1)
    MEM_W(0X44, ctx->r17) = 0;
    // 0x8005FD78: blez        $a0, L_8005FDF0
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8005FD7C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8005FDF0;
    }
    // 0x8005FD7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005FD80: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8005FD84: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8005FD88:
    // 0x8005FD88: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8005FD8C: sw          $t0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r8;
    // 0x8005FD90: ori         $t5, $a0, 0x8000
    ctx->r13 = ctx->r4 | 0X8000;
    // 0x8005FD94: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x8005FD98: sb          $a1, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r5;
    // 0x8005FD9C: jal         0x8007B2C4
    // 0x8005FDA0: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    load_texture(rdram, ctx);
        goto after_5;
    // 0x8005FDA0: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_5:
    // 0x8005FDA4: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8005FDA8: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x8005FDAC: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x8005FDB0: lb          $a1, 0x3F($sp)
    ctx->r5 = MEM_B(ctx->r29, 0X3F);
    // 0x8005FDB4: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x8005FDB8: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    // 0x8005FDBC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8005FDC0: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8005FDC4: addu        $s0, $t9, $v1
    ctx->r16 = ADD32(ctx->r25, ctx->r3);
    // 0x8005FDC8: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8005FDCC: nop

    // 0x8005FDD0: bne         $t2, $zero, L_8005FDDC
    if (ctx->r10 != 0) {
        // 0x8005FDD4: nop
    
            goto L_8005FDDC;
    }
    // 0x8005FDD4: nop

    // 0x8005FDD8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8005FDDC:
    // 0x8005FDDC: lh          $a0, 0x22($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X22);
    // 0x8005FDE0: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8005FDE4: slt         $at, $t0, $a0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8005FDE8: bne         $at, $zero, L_8005FD88
    if (ctx->r1 != 0) {
        // 0x8005FDEC: addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
            goto L_8005FD88;
    }
    // 0x8005FDEC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_8005FDF0:
    // 0x8005FDF0: bne         $a1, $zero, L_8005FEB0
    if (ctx->r5 != 0) {
        // 0x8005FDF4: lb          $t2, 0x3D($sp)
        ctx->r10 = MEM_B(ctx->r29, 0X3D);
            goto L_8005FEB0;
    }
    // 0x8005FDF4: lb          $t2, 0x3D($sp)
    ctx->r10 = MEM_B(ctx->r29, 0X3D);
    // 0x8005FDF8: lh          $a1, 0x28($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X28);
    // 0x8005FDFC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8005FE00: blez        $a1, L_8005FE30
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8005FE04: nop
    
            goto L_8005FE30;
    }
    // 0x8005FE04: nop

    // 0x8005FE08: lw          $v0, 0x38($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X38);
    // 0x8005FE0C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
L_8005FE10:
    // 0x8005FE10: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x8005FE14: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8005FE18: beq         $a2, $v1, L_8005FE24
    if (ctx->r6 == ctx->r3) {
        // 0x8005FE1C: slt         $at, $v1, $a0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8005FE24;
    }
    // 0x8005FE1C: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8005FE20: beq         $at, $zero, L_8005FEAC
    if (ctx->r1 == 0) {
        // 0x8005FE24: slt         $at, $t0, $a1
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_8005FEAC;
    }
L_8005FE24:
    // 0x8005FE24: slt         $at, $t0, $a1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8005FE28: bne         $at, $zero, L_8005FE10
    if (ctx->r1 != 0) {
        // 0x8005FE2C: addiu       $v0, $v0, 0xC
        ctx->r2 = ADD32(ctx->r2, 0XC);
            goto L_8005FE10;
    }
    // 0x8005FE2C: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
L_8005FE30:
    // 0x8005FE30: jal         0x800610E8
    // 0x8005FE34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    model_init_normals(rdram, ctx);
        goto after_6;
    // 0x8005FE34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x8005FE38: bne         $v0, $zero, L_8005FEAC
    if (ctx->r2 != 0) {
        // 0x8005FE3C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8005FEAC;
    }
    // 0x8005FE3C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005FE40: jal         0x80061C40
    // 0x8005FE44: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    model_anim_init(rdram, ctx);
        goto after_7;
    // 0x8005FE44: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_7:
    // 0x8005FE48: bne         $v0, $zero, L_8005FEB0
    if (ctx->r2 != 0) {
        // 0x8005FE4C: lb          $t2, 0x3D($sp)
        ctx->r10 = MEM_B(ctx->r29, 0X3D);
            goto L_8005FEB0;
    }
    // 0x8005FE4C: lb          $t2, 0x3D($sp)
    ctx->r10 = MEM_B(ctx->r29, 0X3D);
    // 0x8005FE50: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x8005FE54: jal         0x8005FF10
    // 0x8005FE58: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    model_instance_init(rdram, ctx);
        goto after_8;
    // 0x8005FE58: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x8005FE5C: beq         $v0, $zero, L_8005FEAC
    if (ctx->r2 == 0) {
        // 0x8005FE60: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8005FEAC;
    }
    // 0x8005FE60: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8005FE64: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8005FE68: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8005FE6C: addiu       $a0, $a0, -0x245C
    ctx->r4 = ADD32(ctx->r4, -0X245C);
    // 0x8005FE70: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005FE74: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x8005FE78: addu        $t5, $t6, $t4
    ctx->r13 = ADD32(ctx->r14, ctx->r12);
    // 0x8005FE7C: sw          $s2, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r18;
    // 0x8005FE80: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005FE84: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8005FE88: addu        $t8, $t7, $t4
    ctx->r24 = ADD32(ctx->r15, ctx->r12);
    // 0x8005FE8C: sw          $s1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r17;
    // 0x8005FE90: lw          $t9, -0x2454($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2454);
    // 0x8005FE94: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8005FE98: slti        $at, $t9, 0x46
    ctx->r1 = SIGNED(ctx->r25) < 0X46 ? 1 : 0;
    // 0x8005FE9C: beq         $at, $zero, L_8005FEB0
    if (ctx->r1 == 0) {
        // 0x8005FEA0: lb          $t2, 0x3D($sp)
        ctx->r10 = MEM_B(ctx->r29, 0X3D);
            goto L_8005FEB0;
    }
    // 0x8005FEA0: lb          $t2, 0x3D($sp)
    ctx->r10 = MEM_B(ctx->r29, 0X3D);
    // 0x8005FEA4: b           L_8005FEF8
    // 0x8005FEA8: sb          $zero, 0x20($v1)
    MEM_B(0X20, ctx->r3) = 0;
        goto L_8005FEF8;
    // 0x8005FEA8: sb          $zero, 0x20($v1)
    MEM_B(0X20, ctx->r3) = 0;
L_8005FEAC:
    // 0x8005FEAC: lb          $t2, 0x3D($sp)
    ctx->r10 = MEM_B(ctx->r29, 0X3D);
L_8005FEB0:
    // 0x8005FEB0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005FEB4: beq         $t2, $zero, L_8005FECC
    if (ctx->r10 == 0) {
        // 0x8005FEB8: addiu       $v0, $v0, -0x2454
        ctx->r2 = ADD32(ctx->r2, -0X2454);
            goto L_8005FECC;
    }
    // 0x8005FEB8: addiu       $v0, $v0, -0x2454
    ctx->r2 = ADD32(ctx->r2, -0X2454);
    // 0x8005FEBC: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8005FEC0: nop

    // 0x8005FEC4: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x8005FEC8: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_8005FECC:
    // 0x8005FECC: lb          $t6, 0x3E($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X3E);
    // 0x8005FED0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005FED4: beq         $t6, $zero, L_8005FEEC
    if (ctx->r14 == 0) {
        // 0x8005FED8: addiu       $v0, $v0, -0x244C
        ctx->r2 = ADD32(ctx->r2, -0X244C);
            goto L_8005FEEC;
    }
    // 0x8005FED8: addiu       $v0, $v0, -0x244C
    ctx->r2 = ADD32(ctx->r2, -0X244C);
    // 0x8005FEDC: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x8005FEE0: nop

    // 0x8005FEE4: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x8005FEE8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_8005FEEC:
    // 0x8005FEEC: jal         0x80060298
    // 0x8005FEF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    free_model_data(rdram, ctx);
        goto after_9;
    // 0x8005FEF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x8005FEF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005FEF8:
    // 0x8005FEF8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005FEFC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005FF00: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8005FF04: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8005FF08: jr          $ra
    // 0x8005FF0C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8005FF0C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void model_instance_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005FF10: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005FF14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005FF18: lh          $t6, 0x48($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X48);
    // 0x8005FF1C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8005FF20: beq         $t6, $zero, L_8005FFBC
    if (ctx->r14 == 0) {
        // 0x8005FF24: andi        $t7, $a1, 0x8
        ctx->r15 = ctx->r5 & 0X8;
            goto L_8005FFBC;
    }
    // 0x8005FF24: andi        $t7, $a1, 0x8
    ctx->r15 = ctx->r5 & 0X8;
    // 0x8005FF28: beq         $t7, $zero, L_8005FFBC
    if (ctx->r15 == 0) {
        // 0x8005FF2C: nop
    
            goto L_8005FFBC;
    }
    // 0x8005FF2C: nop

    // 0x8005FF30: lh          $a2, 0x24($a0)
    ctx->r6 = MEM_H(ctx->r4, 0X24);
    // 0x8005FF34: lh          $t0, 0x4A($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X4A);
    // 0x8005FF38: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x8005FF3C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8005FF40: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8005FF44: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8005FF48: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8005FF4C: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8005FF50: addiu       $a2, $t9, 0x24
    ctx->r6 = ADD32(ctx->r25, 0X24);
    // 0x8005FF54: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x8005FF58: addu        $a0, $t1, $a2
    ctx->r4 = ADD32(ctx->r9, ctx->r6);
    // 0x8005FF5C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x8005FF60: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x8005FF64: jal         0x80070F50
    // 0x8005FF68: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc(rdram, ctx);
        goto after_0;
    // 0x8005FF68: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_0:
    // 0x8005FF6C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8005FF70: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8005FF74: bne         $v0, $zero, L_8005FF84
    if (ctx->r2 != 0) {
        // 0x8005FF78: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8005FF84;
    }
    // 0x8005FF78: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8005FF7C: b           L_80060170
    // 0x8005FF80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80060170;
    // 0x8005FF80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005FF84:
    // 0x8005FF84: addiu       $t2, $v0, 0x24
    ctx->r10 = ADD32(ctx->r2, 0X24);
    // 0x8005FF88: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8005FF8C: lh          $t3, 0x24($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X24);
    // 0x8005FF90: addu        $t7, $v0, $a2
    ctx->r15 = ADD32(ctx->r2, ctx->r6);
    // 0x8005FF94: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8005FF98: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8005FF9C: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x8005FFA0: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x8005FFA4: addiu       $t6, $t5, 0x24
    ctx->r14 = ADD32(ctx->r13, 0X24);
    // 0x8005FFA8: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8005FFAC: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    // 0x8005FFB0: sw          $t7, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r15;
    // 0x8005FFB4: b           L_8006005C
    // 0x8005FFB8: sb          $t8, 0x1E($v0)
    MEM_B(0X1E, ctx->r2) = ctx->r24;
        goto L_8006005C;
    // 0x8005FFB8: sb          $t8, 0x1E($v0)
    MEM_B(0X1E, ctx->r2) = ctx->r24;
L_8005FFBC:
    // 0x8005FFBC: lw          $t9, 0x40($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X40);
    // 0x8005FFC0: andi        $t0, $a1, 0x1
    ctx->r8 = ctx->r5 & 0X1;
    // 0x8005FFC4: beq         $t9, $zero, L_80060020
    if (ctx->r25 == 0) {
        // 0x8005FFC8: addiu       $a0, $zero, 0x24
        ctx->r4 = ADD32(0, 0X24);
            goto L_80060020;
    }
    // 0x8005FFC8: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    // 0x8005FFCC: beq         $t0, $zero, L_80060020
    if (ctx->r8 == 0) {
        // 0x8005FFD0: ori         $a1, $zero, 0xFFFF
        ctx->r5 = 0 | 0XFFFF;
            goto L_80060020;
    }
    // 0x8005FFD0: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    // 0x8005FFD4: lh          $a2, 0x24($a3)
    ctx->r6 = MEM_H(ctx->r7, 0X24);
    // 0x8005FFD8: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x8005FFDC: sll         $t1, $a2, 2
    ctx->r9 = S32(ctx->r6 << 2);
    // 0x8005FFE0: addu        $t1, $t1, $a2
    ctx->r9 = ADD32(ctx->r9, ctx->r6);
    // 0x8005FFE4: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x8005FFE8: jal         0x80070F50
    // 0x8005FFEC: addiu       $a0, $t1, 0x24
    ctx->r4 = ADD32(ctx->r9, 0X24);
    mempool_alloc(rdram, ctx);
        goto after_1;
    // 0x8005FFEC: addiu       $a0, $t1, 0x24
    ctx->r4 = ADD32(ctx->r9, 0X24);
    after_1:
    // 0x8005FFF0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8005FFF4: bne         $v0, $zero, L_80060004
    if (ctx->r2 != 0) {
        // 0x8005FFF8: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80060004;
    }
    // 0x8005FFF8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8005FFFC: b           L_80060170
    // 0x80060000: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80060170;
    // 0x80060000: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80060004:
    // 0x80060004: addiu       $v1, $v0, 0x24
    ctx->r3 = ADD32(ctx->r2, 0X24);
    // 0x80060008: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8006000C: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x80060010: sw          $v1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r3;
    // 0x80060014: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x80060018: b           L_8006005C
    // 0x8006001C: sb          $t2, 0x1E($v0)
    MEM_B(0X1E, ctx->r2) = ctx->r10;
        goto L_8006005C;
    // 0x8006001C: sb          $t2, 0x1E($v0)
    MEM_B(0X1E, ctx->r2) = ctx->r10;
L_80060020:
    // 0x80060020: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    // 0x80060024: jal         0x80070F50
    // 0x80060028: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    mempool_alloc(rdram, ctx);
        goto after_2;
    // 0x80060028: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_2:
    // 0x8006002C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80060030: bne         $v0, $zero, L_80060040
    if (ctx->r2 != 0) {
        // 0x80060034: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80060040;
    }
    // 0x80060034: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80060038: b           L_80060170
    // 0x8006003C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80060170;
    // 0x8006003C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80060040:
    // 0x80060040: lw          $t3, 0x4($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X4);
    // 0x80060044: nop

    // 0x80060048: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8006004C: lw          $t4, 0x4($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X4);
    // 0x80060050: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x80060054: sb          $zero, 0x1E($v0)
    MEM_B(0X1E, ctx->r2) = 0;
    // 0x80060058: sw          $t4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r12;
L_8006005C:
    // 0x8006005C: lb          $t5, 0x1E($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X1E);
    // 0x80060060: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80060064: sh          $zero, 0x16($v0)
    MEM_H(0X16, ctx->r2) = 0;
    // 0x80060068: sh          $zero, 0x18($v0)
    MEM_H(0X18, ctx->r2) = 0;
    // 0x8006006C: sh          $zero, 0x1A($v0)
    MEM_H(0X1A, ctx->r2) = 0;
    // 0x80060070: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x80060074: sh          $v1, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r3;
    // 0x80060078: sh          $v1, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r3;
    // 0x8006007C: beq         $t5, $zero, L_8006016C
    if (ctx->r13 == 0) {
        // 0x80060080: sb          $zero, 0x1F($v0)
        MEM_B(0X1F, ctx->r2) = 0;
            goto L_8006016C;
    }
    // 0x80060080: sb          $zero, 0x1F($v0)
    MEM_B(0X1F, ctx->r2) = 0;
    // 0x80060084: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x80060088: lw          $a0, 0x4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X4);
    // 0x8006008C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80060090:
    // 0x80060090: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x80060094: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80060098: sh          $t6, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r14;
    // 0x8006009C: lh          $t7, 0x2($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X2);
    // 0x800600A0: addiu       $v1, $v1, 0xA
    ctx->r3 = ADD32(ctx->r3, 0XA);
    // 0x800600A4: sh          $t7, -0x8($v1)
    MEM_H(-0X8, ctx->r3) = ctx->r15;
    // 0x800600A8: lh          $t8, 0x4($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X4);
    // 0x800600AC: addiu       $a0, $a0, 0xA
    ctx->r4 = ADD32(ctx->r4, 0XA);
    // 0x800600B0: sh          $t8, -0x6($v1)
    MEM_H(-0X6, ctx->r3) = ctx->r24;
    // 0x800600B4: lbu         $t9, -0x4($a0)
    ctx->r25 = MEM_BU(ctx->r4, -0X4);
    // 0x800600B8: nop

    // 0x800600BC: sb          $t9, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r25;
    // 0x800600C0: lbu         $t0, -0x3($a0)
    ctx->r8 = MEM_BU(ctx->r4, -0X3);
    // 0x800600C4: nop

    // 0x800600C8: sb          $t0, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r8;
    // 0x800600CC: lbu         $t1, -0x2($a0)
    ctx->r9 = MEM_BU(ctx->r4, -0X2);
    // 0x800600D0: nop

    // 0x800600D4: sb          $t1, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r9;
    // 0x800600D8: lbu         $t2, -0x1($a0)
    ctx->r10 = MEM_BU(ctx->r4, -0X1);
    // 0x800600DC: nop

    // 0x800600E0: sb          $t2, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r10;
    // 0x800600E4: lh          $t3, 0x24($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X24);
    // 0x800600E8: nop

    // 0x800600EC: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800600F0: bne         $at, $zero, L_80060090
    if (ctx->r1 != 0) {
        // 0x800600F4: nop
    
            goto L_80060090;
    }
    // 0x800600F4: nop

    // 0x800600F8: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x800600FC: lw          $a0, 0x4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X4);
    // 0x80060100: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80060104:
    // 0x80060104: lh          $t4, 0x0($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X0);
    // 0x80060108: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8006010C: sh          $t4, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r12;
    // 0x80060110: lh          $t5, 0x2($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X2);
    // 0x80060114: addiu       $v1, $v1, 0xA
    ctx->r3 = ADD32(ctx->r3, 0XA);
    // 0x80060118: sh          $t5, -0x8($v1)
    MEM_H(-0X8, ctx->r3) = ctx->r13;
    // 0x8006011C: lh          $t6, 0x4($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X4);
    // 0x80060120: addiu       $a0, $a0, 0xA
    ctx->r4 = ADD32(ctx->r4, 0XA);
    // 0x80060124: sh          $t6, -0x6($v1)
    MEM_H(-0X6, ctx->r3) = ctx->r14;
    // 0x80060128: lbu         $t7, -0x4($a0)
    ctx->r15 = MEM_BU(ctx->r4, -0X4);
    // 0x8006012C: nop

    // 0x80060130: sb          $t7, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r15;
    // 0x80060134: lbu         $t8, -0x3($a0)
    ctx->r24 = MEM_BU(ctx->r4, -0X3);
    // 0x80060138: nop

    // 0x8006013C: sb          $t8, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r24;
    // 0x80060140: lbu         $t9, -0x2($a0)
    ctx->r25 = MEM_BU(ctx->r4, -0X2);
    // 0x80060144: nop

    // 0x80060148: sb          $t9, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r25;
    // 0x8006014C: lbu         $t0, -0x1($a0)
    ctx->r8 = MEM_BU(ctx->r4, -0X1);
    // 0x80060150: nop

    // 0x80060154: sb          $t0, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r8;
    // 0x80060158: lh          $t1, 0x24($a3)
    ctx->r9 = MEM_H(ctx->r7, 0X24);
    // 0x8006015C: nop

    // 0x80060160: slt         $at, $a2, $t1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80060164: bne         $at, $zero, L_80060104
    if (ctx->r1 != 0) {
        // 0x80060168: nop
    
            goto L_80060104;
    }
    // 0x80060168: nop

L_8006016C:
    // 0x8006016C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_80060170:
    // 0x80060170: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80060174: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80060178: jr          $ra
    // 0x8006017C: nop

    return;
    // 0x8006017C: nop

;}
RECOMP_FUNC void free_3d_model(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060180: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80060184: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80060188: beq         $a0, $zero, L_80060288
    if (ctx->r4 == 0) {
        // 0x8006018C: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80060288;
    }
    // 0x8006018C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80060190: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x80060194: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80060198: lh          $t6, 0x30($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X30);
    // 0x8006019C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x800601A0: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800601A4: sh          $t7, 0x30($a1)
    MEM_H(0X30, ctx->r5) = ctx->r15;
    // 0x800601A8: lh          $t8, 0x30($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X30);
    // 0x800601AC: nop

    // 0x800601B0: blez        $t8, L_800601C8
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800601B4: nop
    
            goto L_800601C8;
    }
    // 0x800601B4: nop

    // 0x800601B8: jal         0x80071380
    // 0x800601BC: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x800601BC: nop

    after_0:
    // 0x800601C0: b           L_8006028C
    // 0x800601C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8006028C;
    // 0x800601C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800601C8:
    // 0x800601C8: lw          $v1, -0x2454($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X2454);
    // 0x800601CC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x800601D0: blez        $v1, L_80060210
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800601D4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80060210;
    }
    // 0x800601D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800601D8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800601DC: lw          $a0, -0x245C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X245C);
    // 0x800601E0: nop

    // 0x800601E4: sll         $t1, $v0, 3
    ctx->r9 = S32(ctx->r2 << 3);
L_800601E8:
    // 0x800601E8: addu        $t2, $a0, $t1
    ctx->r10 = ADD32(ctx->r4, ctx->r9);
    // 0x800601EC: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x800601F0: nop

    // 0x800601F4: bne         $a1, $t3, L_80060200
    if (ctx->r5 != ctx->r11) {
        // 0x800601F8: nop
    
            goto L_80060200;
    }
    // 0x800601F8: nop

    // 0x800601FC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_80060200:
    // 0x80060200: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80060204: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80060208: bne         $at, $zero, L_800601E8
    if (ctx->r1 != 0) {
        // 0x8006020C: sll         $t1, $v0, 3
        ctx->r9 = S32(ctx->r2 << 3);
            goto L_800601E8;
    }
    // 0x8006020C: sll         $t1, $v0, 3
    ctx->r9 = S32(ctx->r2 << 3);
L_80060210:
    // 0x80060210: beq         $a2, $t0, L_80060288
    if (ctx->r6 == ctx->r8) {
        // 0x80060214: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80060288;
    }
    // 0x80060214: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80060218: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x8006021C: jal         0x80060298
    // 0x80060220: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    free_model_data(rdram, ctx);
        goto after_1;
    // 0x80060220: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_1:
    // 0x80060224: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80060228: addiu       $v1, $v1, -0x244C
    ctx->r3 = ADD32(ctx->r3, -0X244C);
    // 0x8006022C: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x80060230: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80060234: lw          $t4, -0x2458($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2458);
    // 0x80060238: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8006023C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80060240: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80060244: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80060248: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006024C: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
    // 0x80060250: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80060254: addiu       $a1, $a1, -0x245C
    ctx->r5 = ADD32(ctx->r5, -0X245C);
    // 0x80060258: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x8006025C: sll         $t1, $v0, 3
    ctx->r9 = S32(ctx->r2 << 3);
    // 0x80060260: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80060264: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80060268: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8006026C: addu        $t3, $t2, $t1
    ctx->r11 = ADD32(ctx->r10, ctx->r9);
    // 0x80060270: sw          $t0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r8;
    // 0x80060274: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x80060278: nop

    // 0x8006027C: addu        $t4, $t5, $t1
    ctx->r12 = ADD32(ctx->r13, ctx->r9);
    // 0x80060280: jal         0x80071380
    // 0x80060284: sw          $t0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r8;
    mempool_free(rdram, ctx);
        goto after_2;
    // 0x80060284: sw          $t0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r8;
    after_2:
L_80060288:
    // 0x80060288: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006028C:
    // 0x8006028C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80060290: jr          $ra
    // 0x80060294: nop

    return;
    // 0x80060294: nop

;}
RECOMP_FUNC void free_model_data(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060298: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006029C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800602A0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800602A4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800602A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800602AC: lh          $v0, 0x22($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X22);
    // 0x800602B0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800602B4: blez        $v0, L_800602FC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800602B8: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800602FC;
    }
    // 0x800602B8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800602BC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800602C0:
    // 0x800602C0: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x800602C4: nop

    // 0x800602C8: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x800602CC: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x800602D0: nop

    // 0x800602D4: beq         $a0, $zero, L_800602EC
    if (ctx->r4 == 0) {
        // 0x800602D8: nop
    
            goto L_800602EC;
    }
    // 0x800602D8: nop

    // 0x800602DC: jal         0x8007B70C
    // 0x800602E0: nop

    tex_free(rdram, ctx);
        goto after_0;
    // 0x800602E0: nop

    after_0:
    // 0x800602E4: lh          $v0, 0x22($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X22);
    // 0x800602E8: nop

L_800602EC:
    // 0x800602EC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800602F0: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800602F4: bne         $at, $zero, L_800602C0
    if (ctx->r1 != 0) {
        // 0x800602F8: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_800602C0;
    }
    // 0x800602F8: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
L_800602FC:
    // 0x800602FC: lw          $a0, 0xC($s2)
    ctx->r4 = MEM_W(ctx->r18, 0XC);
    // 0x80060300: nop

    // 0x80060304: beq         $a0, $zero, L_80060314
    if (ctx->r4 == 0) {
        // 0x80060308: nop
    
            goto L_80060314;
    }
    // 0x80060308: nop

    // 0x8006030C: jal         0x80071380
    // 0x80060310: nop

    mempool_free(rdram, ctx);
        goto after_1;
    // 0x80060310: nop

    after_1:
L_80060314:
    // 0x80060314: lw          $a0, 0x10($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X10);
    // 0x80060318: nop

    // 0x8006031C: beq         $a0, $zero, L_8006032C
    if (ctx->r4 == 0) {
        // 0x80060320: nop
    
            goto L_8006032C;
    }
    // 0x80060320: nop

    // 0x80060324: jal         0x80071380
    // 0x80060328: nop

    mempool_free(rdram, ctx);
        goto after_2;
    // 0x80060328: nop

    after_2:
L_8006032C:
    // 0x8006032C: lw          $a0, 0x40($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X40);
    // 0x80060330: nop

    // 0x80060334: beq         $a0, $zero, L_80060344
    if (ctx->r4 == 0) {
        // 0x80060338: nop
    
            goto L_80060344;
    }
    // 0x80060338: nop

    // 0x8006033C: jal         0x80071380
    // 0x80060340: nop

    mempool_free(rdram, ctx);
        goto after_3;
    // 0x80060340: nop

    after_3:
L_80060344:
    // 0x80060344: lw          $t8, 0x44($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X44);
    // 0x80060348: nop

    // 0x8006034C: beq         $t8, $zero, L_8006039C
    if (ctx->r24 == 0) {
        // 0x80060350: nop
    
            goto L_8006039C;
    }
    // 0x80060350: nop

    // 0x80060354: lh          $t9, 0x48($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X48);
    // 0x80060358: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006035C: beq         $t9, $zero, L_8006039C
    if (ctx->r25 == 0) {
        // 0x80060360: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8006039C;
    }
    // 0x80060360: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80060364:
    // 0x80060364: lw          $t0, 0x44($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X44);
    // 0x80060368: nop

    // 0x8006036C: addu        $t1, $t0, $s1
    ctx->r9 = ADD32(ctx->r8, ctx->r17);
    // 0x80060370: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x80060374: jal         0x80071380
    // 0x80060378: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    mempool_free(rdram, ctx);
        goto after_4;
    // 0x80060378: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    after_4:
    // 0x8006037C: lh          $t2, 0x48($s2)
    ctx->r10 = MEM_H(ctx->r18, 0X48);
    // 0x80060380: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80060384: slt         $at, $s0, $t2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80060388: bne         $at, $zero, L_80060364
    if (ctx->r1 != 0) {
        // 0x8006038C: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_80060364;
    }
    // 0x8006038C: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x80060390: lw          $a0, 0x44($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X44);
    // 0x80060394: jal         0x80071380
    // 0x80060398: nop

    mempool_free(rdram, ctx);
        goto after_5;
    // 0x80060398: nop

    after_5:
L_8006039C:
    // 0x8006039C: jal         0x80071380
    // 0x800603A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mempool_free(rdram, ctx);
        goto after_6;
    // 0x800603A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
    // 0x800603A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800603A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800603AC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800603B0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800603B4: jr          $ra
    // 0x800603B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800603B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void model_init_collision(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800603BC: addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // 0x800603C0: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x800603C4: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x800603C8: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x800603CC: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x800603D0: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x800603D4: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x800603D8: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x800603DC: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x800603E0: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x800603E4: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x800603E8: swc1        $f31, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x800603EC: swc1        $f30, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f30.u32l;
    // 0x800603F0: swc1        $f29, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x800603F4: swc1        $f28, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f28.u32l;
    // 0x800603F8: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x800603FC: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x80060400: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80060404: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x80060408: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8006040C: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x80060410: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80060414: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80060418: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x8006041C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80060420: bne         $t6, $zero, L_80060AF0
    if (ctx->r14 != 0) {
        // 0x80060424: lui         $s0, 0xFF00
        ctx->r16 = S32(0XFF00 << 16);
            goto L_80060AF0;
    }
    // 0x80060424: lui         $s0, 0xFF00
    ctx->r16 = S32(0XFF00 << 16);
    // 0x80060428: lh          $a0, 0x28($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X28);
    // 0x8006042C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80060430: blez        $a0, L_80060478
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80060434: ori         $s0, $s0, 0xFF
        ctx->r16 = ctx->r16 | 0XFF;
            goto L_80060478;
    }
    // 0x80060434: ori         $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 | 0XFF;
    // 0x80060438: sll         $a2, $a0, 2
    ctx->r6 = S32(ctx->r4 << 2);
    // 0x8006043C: subu        $a2, $a2, $a0
    ctx->r6 = SUB32(ctx->r6, ctx->r4);
    // 0x80060440: lw          $v0, 0x38($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X38);
    // 0x80060444: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x80060448: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8006044C:
    // 0x8006044C: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x80060450: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x80060454: lh          $a0, 0x10($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X10);
    // 0x80060458: andi        $t8, $t7, 0x200
    ctx->r24 = ctx->r15 & 0X200;
    // 0x8006045C: bne         $t8, $zero, L_8006046C
    if (ctx->r24 != 0) {
        // 0x80060460: addiu       $a1, $a1, 0xC
        ctx->r5 = ADD32(ctx->r5, 0XC);
            goto L_8006046C;
    }
    // 0x80060460: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    // 0x80060464: addu        $t9, $s4, $a0
    ctx->r25 = ADD32(ctx->r20, ctx->r4);
    // 0x80060468: subu        $s4, $t9, $v1
    ctx->r20 = SUB32(ctx->r25, ctx->r3);
L_8006046C:
    // 0x8006046C: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80060470: bne         $at, $zero, L_8006044C
    if (ctx->r1 != 0) {
        // 0x80060474: addiu       $v0, $v0, 0xC
        ctx->r2 = ADD32(ctx->r2, 0XC);
            goto L_8006044C;
    }
    // 0x80060474: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
L_80060478:
    // 0x80060478: sll         $a0, $s4, 3
    ctx->r4 = S32(ctx->r20 << 3);
    // 0x8006047C: jal         0x80070F50
    // 0x80060480: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mempool_alloc(rdram, ctx);
        goto after_0;
    // 0x80060480: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x80060484: beq         $v0, $zero, L_80060AF0
    if (ctx->r2 == 0) {
        // 0x80060488: sw          $v0, 0xC($s2)
        MEM_W(0XC, ctx->r18) = ctx->r2;
            goto L_80060AF0;
    }
    // 0x80060488: sw          $v0, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r2;
    // 0x8006048C: sll         $a0, $s4, 6
    ctx->r4 = S32(ctx->r20 << 6);
    // 0x80060490: jal         0x80070F50
    // 0x80060494: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mempool_alloc(rdram, ctx);
        goto after_1;
    // 0x80060494: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80060498: bne         $v0, $zero, L_800604B4
    if (ctx->r2 != 0) {
        // 0x8006049C: sw          $v0, 0x10($s2)
        MEM_W(0X10, ctx->r18) = ctx->r2;
            goto L_800604B4;
    }
    // 0x8006049C: sw          $v0, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r2;
    // 0x800604A0: lw          $a0, 0xC($s2)
    ctx->r4 = MEM_W(ctx->r18, 0XC);
    // 0x800604A4: jal         0x80071380
    // 0x800604A8: nop

    mempool_free(rdram, ctx);
        goto after_2;
    // 0x800604A8: nop

    after_2:
    // 0x800604AC: b           L_80060AF0
    // 0x800604B0: sw          $zero, 0xC($s2)
    MEM_W(0XC, ctx->r18) = 0;
        goto L_80060AF0;
    // 0x800604B0: sw          $zero, 0xC($s2)
    MEM_W(0XC, ctx->r18) = 0;
L_800604B4:
    // 0x800604B4: sw          $zero, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = 0;
    // 0x800604B8: lh          $a0, 0x28($s2)
    ctx->r4 = MEM_H(ctx->r18, 0X28);
    // 0x800604BC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800604C0: blez        $a0, L_800607A8
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800604C4: addiu       $s7, $zero, 0xA
        ctx->r23 = ADD32(0, 0XA);
            goto L_800607A8;
    }
    // 0x800604C4: addiu       $s7, $zero, 0xA
    ctx->r23 = ADD32(0, 0XA);
    // 0x800604C8: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
L_800604CC:
    // 0x800604CC: lw          $t3, 0x38($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X38);
    // 0x800604D0: lw          $t4, 0x7C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X7C);
    // 0x800604D4: sll         $s0, $s4, 3
    ctx->r16 = S32(ctx->r20 << 3);
    // 0x800604D8: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
    // 0x800604DC: lh          $t5, 0x10($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X10);
    // 0x800604E0: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x800604E4: lh          $s5, 0x2($v0)
    ctx->r21 = MEM_H(ctx->r2, 0X2);
    // 0x800604E8: sw          $t5, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r13;
    // 0x800604EC: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x800604F0: addiu       $t8, $v1, -0x1
    ctx->r24 = ADD32(ctx->r3, -0X1);
    // 0x800604F4: andi        $t7, $t6, 0x200
    ctx->r15 = ctx->r14 & 0X200;
    // 0x800604F8: beq         $t7, $zero, L_80060504
    if (ctx->r15 == 0) {
        // 0x800604FC: sll         $s1, $v1, 4
        ctx->r17 = S32(ctx->r3 << 4);
            goto L_80060504;
    }
    // 0x800604FC: sll         $s1, $v1, 4
    ctx->r17 = S32(ctx->r3 << 4);
    // 0x80060500: sw          $t8, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r24;
L_80060504:
    // 0x80060504: lw          $t9, 0xF4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF4);
    // 0x80060508: or          $s6, $v1, $zero
    ctx->r22 = ctx->r3 | 0;
    // 0x8006050C: slt         $at, $v1, $t9
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80060510: beq         $at, $zero, L_80060788
    if (ctx->r1 == 0) {
        // 0x80060514: lw          $t5, 0xEC($sp)
        ctx->r13 = MEM_W(ctx->r29, 0XEC);
            goto L_80060788;
    }
    // 0x80060514: lw          $t5, 0xEC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XEC);
L_80060518:
    // 0x80060518: lw          $t3, 0x8($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X8);
    // 0x8006051C: lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X4);
    // 0x80060520: addu        $a0, $t3, $s1
    ctx->r4 = ADD32(ctx->r11, ctx->r17);
    // 0x80060524: lbu         $t4, 0x1($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X1);
    // 0x80060528: nop

    // 0x8006052C: addu        $t5, $t4, $s5
    ctx->r13 = ADD32(ctx->r12, ctx->r21);
    // 0x80060530: multu       $t5, $s7
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80060534: mflo        $t6
    ctx->r14 = lo;
    // 0x80060538: addu        $v0, $t6, $v1
    ctx->r2 = ADD32(ctx->r14, ctx->r3);
    // 0x8006053C: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x80060540: nop

    // 0x80060544: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80060548: nop

    // 0x8006054C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80060550: swc1        $f6, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f6.u32l;
    // 0x80060554: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x80060558: lwc1        $f2, 0xCC($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x8006055C: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80060560: nop

    // 0x80060564: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80060568: swc1        $f10, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f10.u32l;
    // 0x8006056C: lh          $t9, 0x4($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X4);
    // 0x80060570: lwc1        $f26, 0xC8($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x80060574: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80060578: nop

    // 0x8006057C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80060580: swc1        $f6, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f6.u32l;
    // 0x80060584: lbu         $t3, 0x2($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X2);
    // 0x80060588: lbu         $t9, 0x3($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X3);
    // 0x8006058C: addu        $t4, $t3, $s5
    ctx->r12 = ADD32(ctx->r11, ctx->r21);
    // 0x80060590: multu       $t4, $s7
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80060594: addu        $t3, $t9, $s5
    ctx->r11 = ADD32(ctx->r25, ctx->r21);
    // 0x80060598: lwc1        $f24, 0xC4($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x8006059C: mflo        $t5
    ctx->r13 = lo;
    // 0x800605A0: addu        $v0, $t5, $v1
    ctx->r2 = ADD32(ctx->r13, ctx->r3);
    // 0x800605A4: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x800605A8: multu       $t3, $s7
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800605AC: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x800605B0: lh          $t8, 0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4);
    // 0x800605B4: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800605B8: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800605BC: cvt.s.w     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800605C0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800605C4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800605C8: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800605CC: mflo        $t4
    ctx->r12 = lo;
    // 0x800605D0: addu        $v0, $t4, $v1
    ctx->r2 = ADD32(ctx->r12, ctx->r3);
    // 0x800605D4: lh          $t6, 0x2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X2);
    // 0x800605D8: lh          $t5, 0x0($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X0);
    // 0x800605DC: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800605E0: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x800605E4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800605E8: swc1        $f10, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f10.u32l;
    // 0x800605EC: lh          $t7, 0x4($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X4);
    // 0x800605F0: cvt.s.w     $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    ctx->f22.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800605F4: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800605F8: lwc1        $f12, 0xB0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800605FC: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80060600: sub.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x80060604: mul.s       $f8, $f6, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f26.fl);
    // 0x80060608: sub.s       $f10, $f0, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x8006060C: mul.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x80060610: sub.s       $f10, $f24, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f24.fl - ctx->f18.fl;
    // 0x80060614: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80060618: mul.s       $f8, $f12, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x8006061C: sub.s       $f4, $f14, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f14.fl - ctx->f22.fl;
    // 0x80060620: mul.s       $f10, $f4, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x80060624: add.s       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80060628: swc1        $f20, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f20.u32l;
    // 0x8006062C: sub.s       $f6, $f22, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f22.fl - ctx->f2.fl;
    // 0x80060630: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80060634: sub.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x80060638: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8006063C: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80060640: sub.s       $f8, $f16, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x80060644: mul.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80060648: add.s       $f28, $f4, $f10
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f28.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8006064C: swc1        $f28, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f28.u32l;
    // 0x80060650: sub.s       $f4, $f12, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f26.fl;
    // 0x80060654: mul.s       $f10, $f14, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f4.fl);
    // 0x80060658: sub.s       $f4, $f26, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f26.fl - ctx->f16.fl;
    // 0x8006065C: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80060660: mul.s       $f6, $f22, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f4.fl);
    // 0x80060664: nop

    // 0x80060668: mul.s       $f10, $f20, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8006066C: add.s       $f30, $f8, $f6
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f30.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80060670: swc1        $f30, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f30.u32l;
    // 0x80060674: mul.s       $f4, $f28, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f28.fl, ctx->f28.fl);
    // 0x80060678: nop

    // 0x8006067C: mul.s       $f6, $f30, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = MUL_S(ctx->f30.fl, ctx->f30.fl);
    // 0x80060680: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80060684: jal         0x800CA030
    // 0x80060688: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x80060688: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    after_3:
    // 0x8006068C: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x80060690: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80060694: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80060698: c.lt.d      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.d < ctx->f4.d;
    // 0x8006069C: lwc1        $f2, 0xCC($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800606A0: bc1f        L_800606C8
    if (!c1cs) {
        // 0x800606A4: sll         $v0, $s4, 4
        ctx->r2 = S32(ctx->r20 << 4);
            goto L_800606C8;
    }
    // 0x800606A4: sll         $v0, $s4, 4
    ctx->r2 = S32(ctx->r20 << 4);
    // 0x800606A8: nop

    // 0x800606AC: div.s       $f16, $f20, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800606B0: nop

    // 0x800606B4: div.s       $f14, $f28, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = DIV_S(ctx->f28.fl, ctx->f0.fl);
    // 0x800606B8: swc1        $f16, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f16.u32l;
    // 0x800606BC: div.s       $f12, $f30, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f30.fl, ctx->f0.fl);
    // 0x800606C0: swc1        $f14, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f14.u32l;
    // 0x800606C4: swc1        $f12, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f12.u32l;
L_800606C8:
    // 0x800606C8: lw          $t9, 0x10($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X10);
    // 0x800606CC: lwc1        $f16, 0xA8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x800606D0: lwc1        $f12, 0xA0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800606D4: lwc1        $f14, 0xA4($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x800606D8: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x800606DC: swc1        $f16, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f16.u32l;
    // 0x800606E0: lw          $t4, 0x10($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X10);
    // 0x800606E4: mul.s       $f8, $f2, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x800606E8: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800606EC: swc1        $f14, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f14.u32l;
    // 0x800606F0: lw          $t6, 0x10($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X10);
    // 0x800606F4: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x800606F8: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800606FC: swc1        $f12, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f12.u32l;
    // 0x80060700: lwc1        $f6, 0xC8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x80060704: lw          $t8, 0x10($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X10);
    // 0x80060708: mul.s       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8006070C: lwc1        $f6, 0xC4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x80060710: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x80060714: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x80060718: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8006071C: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80060720: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80060724: neg.s       $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = -ctx->f10.fl;
    // 0x80060728: swc1        $f6, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f6.u32l;
    // 0x8006072C: lw          $t3, 0xC($s2)
    ctx->r11 = MEM_W(ctx->r18, 0XC);
    // 0x80060730: nop

    // 0x80060734: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x80060738: sh          $s4, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r20;
    // 0x8006073C: lw          $t5, 0xC($s2)
    ctx->r13 = MEM_W(ctx->r18, 0XC);
    // 0x80060740: nop

    // 0x80060744: addu        $t6, $t5, $s0
    ctx->r14 = ADD32(ctx->r13, ctx->r16);
    // 0x80060748: sh          $s4, 0x2($t6)
    MEM_H(0X2, ctx->r14) = ctx->r20;
    // 0x8006074C: lw          $t7, 0xC($s2)
    ctx->r15 = MEM_W(ctx->r18, 0XC);
    // 0x80060750: nop

    // 0x80060754: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x80060758: sh          $s4, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r20;
    // 0x8006075C: lw          $t9, 0xC($s2)
    ctx->r25 = MEM_W(ctx->r18, 0XC);
    // 0x80060760: nop

    // 0x80060764: addu        $t3, $t9, $s0
    ctx->r11 = ADD32(ctx->r25, ctx->r16);
    // 0x80060768: sh          $s4, 0x6($t3)
    MEM_H(0X6, ctx->r11) = ctx->r20;
    // 0x8006076C: lw          $t4, 0xF4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XF4);
    // 0x80060770: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80060774: bne         $s6, $t4, L_80060518
    if (ctx->r22 != ctx->r12) {
        // 0x80060778: addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
            goto L_80060518;
    }
    // 0x80060778: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8006077C: lh          $a0, 0x28($s2)
    ctx->r4 = MEM_H(ctx->r18, 0X28);
    // 0x80060780: nop

    // 0x80060784: lw          $t5, 0xEC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XEC);
L_80060788:
    // 0x80060788: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x8006078C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80060790: slt         $at, $t6, $a0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80060794: addiu       $t8, $t7, 0xC
    ctx->r24 = ADD32(ctx->r15, 0XC);
    // 0x80060798: sw          $t8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r24;
    // 0x8006079C: bne         $at, $zero, L_800604CC
    if (ctx->r1 != 0) {
        // 0x800607A0: sw          $t6, 0xEC($sp)
        MEM_W(0XEC, ctx->r29) = ctx->r14;
            goto L_800604CC;
    }
    // 0x800607A0: sw          $t6, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r14;
    // 0x800607A4: sw          $zero, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = 0;
L_800607A8:
    // 0x800607A8: addiu       $s7, $zero, 0xA
    ctx->r23 = ADD32(0, 0XA);
    // 0x800607AC: sh          $s4, 0x32($s2)
    MEM_H(0X32, ctx->r18) = ctx->r20;
    // 0x800607B0: jal         0x80060B50
    // 0x800607B4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80060910(rdram, ctx);
        goto after_4;
    // 0x800607B4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
    // 0x800607B8: lh          $a0, 0x28($s2)
    ctx->r4 = MEM_H(ctx->r18, 0X28);
    // 0x800607BC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800607C0: blez        $a0, L_80060AF0
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800607C4: addiu       $fp, $zero, 0x3
        ctx->r30 = ADD32(0, 0X3);
            goto L_80060AF0;
    }
    // 0x800607C4: addiu       $fp, $zero, 0x3
    ctx->r30 = ADD32(0, 0X3);
    // 0x800607C8: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
L_800607CC:
    // 0x800607CC: lw          $t9, 0x38($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X38);
    // 0x800607D0: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x800607D4: nop

    // 0x800607D8: addu        $v0, $t9, $t3
    ctx->r2 = ADD32(ctx->r25, ctx->r11);
    // 0x800607DC: lw          $t4, 0x8($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X8);
    // 0x800607E0: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x800607E4: lh          $s5, 0x2($v0)
    ctx->r21 = MEM_H(ctx->r2, 0X2);
    // 0x800607E8: lh          $a3, 0x10($v0)
    ctx->r7 = MEM_H(ctx->r2, 0X10);
    // 0x800607EC: andi        $t5, $t4, 0x200
    ctx->r13 = ctx->r12 & 0X200;
    // 0x800607F0: beq         $t5, $zero, L_800607FC
    if (ctx->r13 == 0) {
        // 0x800607F4: sll         $v0, $s3, 3
        ctx->r2 = S32(ctx->r19 << 3);
            goto L_800607FC;
    }
    // 0x800607F4: sll         $v0, $s3, 3
    ctx->r2 = S32(ctx->r19 << 3);
    // 0x800607F8: addiu       $a3, $v1, -0x1
    ctx->r7 = ADD32(ctx->r3, -0X1);
L_800607FC:
    // 0x800607FC: slt         $at, $v1, $a3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80060800: beq         $at, $zero, L_80060AD0
    if (ctx->r1 == 0) {
        // 0x80060804: or          $s6, $v1, $zero
        ctx->r22 = ctx->r3 | 0;
            goto L_80060AD0;
    }
    // 0x80060804: or          $s6, $v1, $zero
    ctx->r22 = ctx->r3 | 0;
    // 0x80060808: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x8006080C: sw          $a3, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r7;
L_80060810:
    // 0x80060810: lw          $v0, 0x74($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X74);
    // 0x80060814: lw          $t7, 0xC($s2)
    ctx->r15 = MEM_W(ctx->r18, 0XC);
    // 0x80060818: lw          $t9, 0x10($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X10);
    // 0x8006081C: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80060820: lhu         $t6, 0x0($t8)
    ctx->r14 = MEM_HU(ctx->r24, 0X0);
    // 0x80060824: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80060828: sll         $t3, $t6, 4
    ctx->r11 = S32(ctx->r14 << 4);
    // 0x8006082C: addu        $v1, $t9, $t3
    ctx->r3 = ADD32(ctx->r25, ctx->r11);
    // 0x80060830: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80060834: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80060838: swc1        $f4, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f4.u32l;
    // 0x8006083C: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80060840: nop

    // 0x80060844: swc1        $f8, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f8.u32l;
    // 0x80060848: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8006084C: nop

    // 0x80060850: swc1        $f10, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f10.u32l;
L_80060854:
    // 0x80060854: addiu       $s0, $a1, 0x1
    ctx->r16 = ADD32(ctx->r5, 0X1);
    // 0x80060858: slti        $at, $s0, 0x3
    ctx->r1 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // 0x8006085C: lw          $a3, 0xC($s2)
    ctx->r7 = MEM_W(ctx->r18, 0XC);
    // 0x80060860: lw          $t0, 0x10($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X10);
    // 0x80060864: bne         $at, $zero, L_80060870
    if (ctx->r1 != 0) {
        // 0x80060868: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80060870;
    }
    // 0x80060868: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006086C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80060870:
    // 0x80060870: lw          $t4, 0x8($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X8);
    // 0x80060874: sll         $t5, $s6, 4
    ctx->r13 = S32(ctx->r22 << 4);
    // 0x80060878: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x8006087C: addu        $t7, $v0, $a1
    ctx->r15 = ADD32(ctx->r2, ctx->r5);
    // 0x80060880: lbu         $t8, 0x1($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X1);
    // 0x80060884: sll         $t3, $s3, 3
    ctx->r11 = S32(ctx->r19 << 3);
    // 0x80060888: addu        $t1, $t8, $s5
    ctx->r9 = ADD32(ctx->r24, ctx->r21);
    // 0x8006088C: multu       $t1, $s7
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80060890: addu        $t4, $a3, $t3
    ctx->r12 = ADD32(ctx->r7, ctx->r11);
    // 0x80060894: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x80060898: lhu         $t7, 0x2($t5)
    ctx->r15 = MEM_HU(ctx->r13, 0X2);
    // 0x8006089C: addu        $t6, $v0, $a0
    ctx->r14 = ADD32(ctx->r2, ctx->r4);
    // 0x800608A0: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x800608A4: addu        $v1, $t0, $t8
    ctx->r3 = ADD32(ctx->r8, ctx->r24);
    // 0x800608A8: lbu         $t9, 0x1($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X1);
    // 0x800608AC: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800608B0: lwc1        $f4, 0xA8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x800608B4: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800608B8: add.s       $f20, $f6, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800608BC: mflo        $t6
    ctx->r14 = lo;
    // 0x800608C0: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800608C4: addu        $t2, $t9, $s5
    ctx->r10 = ADD32(ctx->r25, ctx->r21);
    // 0x800608C8: multu       $t2, $s7
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800608CC: lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X4);
    // 0x800608D0: lwc1        $f10, 0xA4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x800608D4: addu        $v0, $v1, $t6
    ctx->r2 = ADD32(ctx->r3, ctx->r14);
    // 0x800608D8: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x800608DC: add.s       $f24, $f8, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f24.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800608E0: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800608E4: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800608E8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800608EC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800608F0: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x800608F4: swc1        $f10, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f10.u32l;
    // 0x800608F8: lh          $t4, 0x4($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X4);
    // 0x800608FC: lh          $t3, 0x2($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X2);
    // 0x80060900: add.s       $f26, $f6, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f26.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80060904: mflo        $t5
    ctx->r13 = lo;
    // 0x80060908: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8006090C: addu        $v0, $v1, $t5
    ctx->r2 = ADD32(ctx->r3, ctx->r13);
    // 0x80060910: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x80060914: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80060918: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8006091C: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80060920: mul.s       $f4, $f20, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f28.fl);
    // 0x80060924: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x80060928: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x8006092C: swc1        $f12, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f12.u32l;
    // 0x80060930: cvt.s.w     $f30, $f6
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 6);
    ctx->f30.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80060934: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80060938: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8006093C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80060940: swc1        $f30, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f30.u32l;
    // 0x80060944: mul.s       $f10, $f24, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = MUL_S(ctx->f24.fl, ctx->f28.fl);
    // 0x80060948: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8006094C: mul.s       $f6, $f26, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = MUL_S(ctx->f26.fl, ctx->f28.fl);
    // 0x80060950: add.s       $f2, $f10, $f30
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f30.fl;
    // 0x80060954: swc1        $f2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f2.u32l;
    // 0x80060958: cvt.s.w     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8006095C: lwc1        $f8, 0xCC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x80060960: add.s       $f0, $f6, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x80060964: add.s       $f22, $f4, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f22.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80060968: swc1        $f0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f0.u32l;
    // 0x8006096C: sub.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x80060970: mul.s       $f10, $f4, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f30.fl);
    // 0x80060974: sub.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x80060978: lwc1        $f0, 0xC8($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x8006097C: mul.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x80060980: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80060984: sub.s       $f10, $f12, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x80060988: mul.s       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8006098C: sub.s       $f10, $f14, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f22.fl;
    // 0x80060990: add.s       $f20, $f6, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80060994: lwc1        $f6, 0xC4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x80060998: mov.s       $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    ctx->f2.fl = ctx->f8.fl;
    // 0x8006099C: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800609A0: sub.s       $f8, $f22, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f22.fl - ctx->f8.fl;
    // 0x800609A4: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800609A8: lwc1        $f8, 0xAC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800609AC: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800609B0: sub.s       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x800609B4: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800609B8: lwc1        $f8, 0xB0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800609BC: nop

    // 0x800609C0: sub.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x800609C4: add.s       $f28, $f6, $f10
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f28.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800609C8: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800609CC: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x800609D0: mul.s       $f4, $f14, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f10.fl);
    // 0x800609D4: sub.s       $f10, $f0, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x800609D8: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800609DC: mul.s       $f6, $f22, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f10.fl);
    // 0x800609E0: mov.s       $f24, $f28
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    ctx->f24.fl = ctx->f28.fl;
    // 0x800609E4: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x800609E8: add.s       $f30, $f8, $f6
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f30.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800609EC: mul.s       $f10, $f28, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = MUL_S(ctx->f28.fl, ctx->f28.fl);
    // 0x800609F0: mov.s       $f26, $f30
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 30);
    ctx->f26.fl = ctx->f30.fl;
    // 0x800609F4: mul.s       $f6, $f30, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = MUL_S(ctx->f30.fl, ctx->f30.fl);
    // 0x800609F8: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800609FC: jal         0x800CA030
    // 0x80060A00: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_5;
    // 0x80060A00: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    after_5:
    // 0x80060A04: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x80060A08: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80060A0C: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x80060A10: c.lt.d      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.d < ctx->f10.d;
    // 0x80060A14: lwc1        $f2, 0xCC($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x80060A18: bc1f        L_80060A34
    if (!c1cs) {
        // 0x80060A1C: nop
    
            goto L_80060A34;
    }
    // 0x80060A1C: nop

    // 0x80060A20: div.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80060A24: nop

    // 0x80060A28: div.s       $f24, $f28, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = DIV_S(ctx->f28.fl, ctx->f0.fl);
    // 0x80060A2C: nop

    // 0x80060A30: div.s       $f26, $f30, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f26.fl = DIV_S(ctx->f30.fl, ctx->f0.fl);
L_80060A34:
    // 0x80060A34: lw          $t9, 0xC($s2)
    ctx->r25 = MEM_W(ctx->r18, 0XC);
    // 0x80060A38: sll         $t3, $s3, 3
    ctx->r11 = S32(ctx->r19 << 3);
    // 0x80060A3C: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x80060A40: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x80060A44: sh          $s4, 0x2($t5)
    MEM_H(0X2, ctx->r13) = ctx->r20;
    // 0x80060A48: lw          $t8, 0x10($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X10);
    // 0x80060A4C: sll         $v0, $s4, 4
    ctx->r2 = S32(ctx->r20 << 4);
    // 0x80060A50: addu        $t6, $t8, $v0
    ctx->r14 = ADD32(ctx->r24, ctx->r2);
    // 0x80060A54: swc1        $f20, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f20.u32l;
    // 0x80060A58: lw          $t9, 0x10($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X10);
    // 0x80060A5C: mul.s       $f8, $f2, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x80060A60: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x80060A64: swc1        $f24, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f24.u32l;
    // 0x80060A68: lw          $t4, 0x10($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X10);
    // 0x80060A6C: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x80060A70: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x80060A74: swc1        $f26, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f26.u32l;
    // 0x80060A78: lwc1        $f6, 0xC8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x80060A7C: lw          $t7, 0x10($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X10);
    // 0x80060A80: mul.s       $f4, $f6, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x80060A84: lwc1        $f6, 0xC4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x80060A88: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80060A8C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80060A90: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80060A94: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80060A98: mul.s       $f8, $f6, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f26.fl);
    // 0x80060A9C: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80060AA0: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80060AA4: bne         $s0, $fp, L_80060854
    if (ctx->r16 != ctx->r30) {
        // 0x80060AA8: swc1        $f6, 0xC($t8)
        MEM_W(0XC, ctx->r24) = ctx->f6.u32l;
            goto L_80060854;
    }
    // 0x80060AA8: swc1        $f6, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f6.u32l;
    // 0x80060AAC: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x80060AB0: lw          $t3, 0xF4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XF4);
    // 0x80060AB4: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x80060AB8: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x80060ABC: sw          $t9, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r25;
    // 0x80060AC0: bne         $s6, $t3, L_80060810
    if (ctx->r22 != ctx->r11) {
        // 0x80060AC4: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_80060810;
    }
    // 0x80060AC4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80060AC8: lh          $a0, 0x28($s2)
    ctx->r4 = MEM_H(ctx->r18, 0X28);
    // 0x80060ACC: nop

L_80060AD0:
    // 0x80060AD0: lw          $t4, 0xEC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XEC);
    // 0x80060AD4: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x80060AD8: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80060ADC: slt         $at, $t5, $a0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80060AE0: addiu       $t8, $t7, 0xC
    ctx->r24 = ADD32(ctx->r15, 0XC);
    // 0x80060AE4: sw          $t8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r24;
    // 0x80060AE8: bne         $at, $zero, L_800607CC
    if (ctx->r1 != 0) {
        // 0x80060AEC: sw          $t5, 0xEC($sp)
        MEM_W(0XEC, ctx->r29) = ctx->r13;
            goto L_800607CC;
    }
    // 0x80060AEC: sw          $t5, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r13;
L_80060AF0:
    // 0x80060AF0: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x80060AF4: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80060AF8: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80060AFC: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80060B00: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80060B04: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80060B08: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80060B0C: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80060B10: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80060B14: lwc1        $f29, 0x38($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x80060B18: lwc1        $f28, 0x3C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80060B1C: lwc1        $f31, 0x40($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x80060B20: lwc1        $f30, 0x44($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80060B24: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80060B28: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80060B2C: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80060B30: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80060B34: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80060B38: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x80060B3C: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80060B40: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x80060B44: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x80060B48: jr          $ra
    // 0x80060B4C: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    return;
    // 0x80060B4C: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
;}
RECOMP_FUNC void func_80060910(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060B50: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80060B54: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80060B58: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80060B5C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80060B60: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80060B64: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80060B68: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80060B6C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80060B70: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80060B74: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80060B78: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80060B7C: sw          $zero, 0x88($sp)
    MEM_W(0X88, ctx->r29) = 0;
    // 0x80060B80: lh          $a1, 0x28($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X28);
    // 0x80060B84: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80060B88: blez        $a1, L_80060CD8
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80060B8C: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_80060CD8;
    }
    // 0x80060B8C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80060B90: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    // 0x80060B94: addiu       $fp, $zero, -0x1
    ctx->r30 = ADD32(0, -0X1);
    // 0x80060B98: addiu       $s7, $sp, 0x60
    ctx->r23 = ADD32(ctx->r29, 0X60);
    // 0x80060B9C: addiu       $s6, $sp, 0x5C
    ctx->r22 = ADD32(ctx->r29, 0X5C);
L_80060BA0:
    // 0x80060BA0: lw          $t6, 0x38($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X38);
    // 0x80060BA4: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x80060BA8: sll         $t4, $s4, 3
    ctx->r12 = S32(ctx->r20 << 3);
    // 0x80060BAC: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80060BB0: lh          $t8, 0x10($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X10);
    // 0x80060BB4: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x80060BB8: lh          $s5, 0x2($v0)
    ctx->r21 = MEM_H(ctx->r2, 0X2);
    // 0x80060BBC: sw          $t8, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r24;
    // 0x80060BC0: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x80060BC4: addiu       $t2, $v1, -0x1
    ctx->r10 = ADD32(ctx->r3, -0X1);
    // 0x80060BC8: andi        $t1, $t9, 0x200
    ctx->r9 = ctx->r25 & 0X200;
    // 0x80060BCC: beq         $t1, $zero, L_80060BDC
    if (ctx->r9 == 0) {
        // 0x80060BD0: lw          $t3, 0x78($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X78);
            goto L_80060BDC;
    }
    // 0x80060BD0: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x80060BD4: sw          $t2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r10;
    // 0x80060BD8: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
L_80060BDC:
    // 0x80060BDC: or          $s3, $v1, $zero
    ctx->r19 = ctx->r3 | 0;
    // 0x80060BE0: slt         $at, $v1, $t3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80060BE4: beq         $at, $zero, L_80060CBC
    if (ctx->r1 == 0) {
        // 0x80060BE8: lw          $t7, 0x88($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X88);
            goto L_80060CBC;
    }
    // 0x80060BE8: lw          $t7, 0x88($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X88);
    // 0x80060BEC: sw          $t4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r12;
L_80060BF0:
    // 0x80060BF0: lw          $t5, 0xC($s2)
    ctx->r13 = MEM_W(ctx->r18, 0XC);
    // 0x80060BF4: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x80060BF8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80060BFC: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80060C00: sh          $s4, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r20;
    // 0x80060C04: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80060C08:
    // 0x80060C08: addiu       $s1, $v1, 0x1
    ctx->r17 = ADD32(ctx->r3, 0X1);
    // 0x80060C0C: slti        $at, $s1, 0x3
    ctx->r1 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
    // 0x80060C10: bne         $at, $zero, L_80060C1C
    if (ctx->r1 != 0) {
        // 0x80060C14: or          $t0, $s1, $zero
        ctx->r8 = ctx->r17 | 0;
            goto L_80060C1C;
    }
    // 0x80060C14: or          $t0, $s1, $zero
    ctx->r8 = ctx->r17 | 0;
    // 0x80060C18: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_80060C1C:
    // 0x80060C1C: lw          $t8, 0x8($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X8);
    // 0x80060C20: sll         $t9, $s3, 4
    ctx->r25 = S32(ctx->r19 << 4);
    // 0x80060C24: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x80060C28: addu        $t1, $v0, $v1
    ctx->r9 = ADD32(ctx->r2, ctx->r3);
    // 0x80060C2C: addu        $t3, $v0, $t0
    ctx->r11 = ADD32(ctx->r2, ctx->r8);
    // 0x80060C30: lbu         $t2, 0x1($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X1);
    // 0x80060C34: lbu         $t4, 0x1($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X1);
    // 0x80060C38: sw          $s7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r23;
    // 0x80060C3C: sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    // 0x80060C40: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80060C44: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80060C48: addu        $a2, $t2, $s5
    ctx->r6 = ADD32(ctx->r10, ctx->r21);
    // 0x80060C4C: jal         0x80060D08
    // 0x80060C50: addu        $a3, $t4, $s5
    ctx->r7 = ADD32(ctx->r12, ctx->r21);
    func_80060AC8(rdram, ctx);
        goto after_0;
    // 0x80060C50: addu        $a3, $t4, $s5
    ctx->r7 = ADD32(ctx->r12, ctx->r21);
    after_0:
    // 0x80060C54: beq         $v0, $fp, L_80060C74
    if (ctx->r2 == ctx->r30) {
        // 0x80060C58: or          $v1, $s1, $zero
        ctx->r3 = ctx->r17 | 0;
            goto L_80060C74;
    }
    // 0x80060C58: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x80060C5C: lw          $t5, 0xC($s2)
    ctx->r13 = MEM_W(ctx->r18, 0XC);
    // 0x80060C60: sll         $t6, $s4, 3
    ctx->r14 = S32(ctx->r20 << 3);
    // 0x80060C64: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80060C68: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x80060C6C: b           L_80060C88
    // 0x80060C70: sh          $v0, 0x2($t8)
    MEM_H(0X2, ctx->r24) = ctx->r2;
        goto L_80060C88;
    // 0x80060C70: sh          $v0, 0x2($t8)
    MEM_H(0X2, ctx->r24) = ctx->r2;
L_80060C74:
    // 0x80060C74: lw          $t9, 0xC($s2)
    ctx->r25 = MEM_W(ctx->r18, 0XC);
    // 0x80060C78: sll         $t1, $s4, 3
    ctx->r9 = S32(ctx->r20 << 3);
    // 0x80060C7C: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80060C80: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x80060C84: sh          $s4, 0x2($t3)
    MEM_H(0X2, ctx->r11) = ctx->r20;
L_80060C88:
    // 0x80060C88: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80060C8C: bne         $s1, $at, L_80060C08
    if (ctx->r17 != ctx->r1) {
        // 0x80060C90: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_80060C08;
    }
    // 0x80060C90: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x80060C94: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x80060C98: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x80060C9C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80060CA0: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x80060CA4: sw          $t5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r13;
    // 0x80060CA8: bne         $s3, $t6, L_80060BF0
    if (ctx->r19 != ctx->r14) {
        // 0x80060CAC: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_80060BF0;
    }
    // 0x80060CAC: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80060CB0: lh          $a1, 0x28($s2)
    ctx->r5 = MEM_H(ctx->r18, 0X28);
    // 0x80060CB4: nop

    // 0x80060CB8: lw          $t7, 0x88($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X88);
L_80060CBC:
    // 0x80060CBC: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x80060CC0: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80060CC4: slt         $at, $t8, $a1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80060CC8: addiu       $t1, $t9, 0xC
    ctx->r9 = ADD32(ctx->r25, 0XC);
    // 0x80060CCC: sw          $t1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r9;
    // 0x80060CD0: bne         $at, $zero, L_80060BA0
    if (ctx->r1 != 0) {
        // 0x80060CD4: sw          $t8, 0x88($sp)
        MEM_W(0X88, ctx->r29) = ctx->r24;
            goto L_80060BA0;
    }
    // 0x80060CD4: sw          $t8, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r24;
L_80060CD8:
    // 0x80060CD8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80060CDC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80060CE0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80060CE4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80060CE8: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80060CEC: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80060CF0: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80060CF4: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80060CF8: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80060CFC: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80060D00: jr          $ra
    // 0x80060D04: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80060D04: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_80060AC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060D08: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80060D0C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80060D10: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80060D14: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80060D18: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80060D1C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80060D20: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80060D24: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80060D28: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80060D2C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80060D30: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80060D34: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x80060D38: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
    // 0x80060D3C: lh          $t0, 0x28($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X28);
    // 0x80060D40: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80060D44: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x80060D48: or          $s6, $a3, $zero
    ctx->r22 = ctx->r7 | 0;
    // 0x80060D4C: blez        $t0, L_80060E64
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80060D50: or          $fp, $zero, $zero
        ctx->r30 = 0 | 0;
            goto L_80060E64;
    }
    // 0x80060D50: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x80060D54: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x80060D58: addiu       $s7, $zero, 0x3
    ctx->r23 = ADD32(0, 0X3);
L_80060D5C:
    // 0x80060D5C: lw          $t6, 0x38($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X38);
    // 0x80060D60: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80060D64: nop

    // 0x80060D68: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80060D6C: lh          $t8, 0x10($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X10);
    // 0x80060D70: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x80060D74: lh          $s2, 0x2($v0)
    ctx->r18 = MEM_H(ctx->r2, 0X2);
    // 0x80060D78: sw          $t8, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r24;
    // 0x80060D7C: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x80060D80: addiu       $t2, $v1, -0x1
    ctx->r10 = ADD32(ctx->r3, -0X1);
    // 0x80060D84: andi        $t1, $t9, 0x200
    ctx->r9 = ctx->r25 & 0X200;
    // 0x80060D88: beq         $t1, $zero, L_80060D98
    if (ctx->r9 == 0) {
        // 0x80060D8C: lw          $t3, 0x70($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X70);
            goto L_80060D98;
    }
    // 0x80060D8C: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x80060D90: sw          $t2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r10;
    // 0x80060D94: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
L_80060D98:
    // 0x80060D98: or          $s4, $v1, $zero
    ctx->r20 = ctx->r3 | 0;
    // 0x80060D9C: slt         $at, $v1, $t3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80060DA0: beq         $at, $zero, L_80060E48
    if (ctx->r1 == 0) {
        // 0x80060DA4: lw          $t6, 0x74($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X74);
            goto L_80060E48;
    }
    // 0x80060DA4: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_80060DA8:
    // 0x80060DA8: lw          $t4, 0x7C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X7C);
    // 0x80060DAC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80060DB0: beq         $s4, $t4, L_80060E2C
    if (ctx->r20 == ctx->r12) {
        // 0x80060DB4: addiu       $s0, $s1, 0x1
        ctx->r16 = ADD32(ctx->r17, 0X1);
            goto L_80060E2C;
    }
L_80060DB4:
    // 0x80060DB4: addiu       $s0, $s1, 0x1
    ctx->r16 = ADD32(ctx->r17, 0X1);
    // 0x80060DB8: slti        $at, $s0, 0x3
    ctx->r1 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // 0x80060DBC: bne         $at, $zero, L_80060DC8
    if (ctx->r1 != 0) {
        // 0x80060DC0: or          $t0, $s0, $zero
        ctx->r8 = ctx->r16 | 0;
            goto L_80060DC8;
    }
    // 0x80060DC0: or          $t0, $s0, $zero
    ctx->r8 = ctx->r16 | 0;
    // 0x80060DC4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_80060DC8:
    // 0x80060DC8: lw          $t5, 0x8($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X8);
    // 0x80060DCC: sll         $t6, $s4, 4
    ctx->r14 = S32(ctx->r20 << 4);
    // 0x80060DD0: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
    // 0x80060DD4: addu        $t9, $v0, $t0
    ctx->r25 = ADD32(ctx->r2, ctx->r8);
    // 0x80060DD8: lbu         $t1, 0x1($t9)
    ctx->r9 = MEM_BU(ctx->r25, 0X1);
    // 0x80060DDC: addu        $t7, $v0, $s1
    ctx->r15 = ADD32(ctx->r2, ctx->r17);
    // 0x80060DE0: lbu         $t8, 0x1($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X1);
    // 0x80060DE4: lw          $a0, 0x4($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X4);
    // 0x80060DE8: addu        $v1, $t1, $s2
    ctx->r3 = ADD32(ctx->r9, ctx->r18);
    // 0x80060DEC: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x80060DF0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80060DF4: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x80060DF8: jal         0x80060E98
    // 0x80060DFC: addu        $a3, $t8, $s2
    ctx->r7 = ADD32(ctx->r24, ctx->r18);
    func_80060C58(rdram, ctx);
        goto after_0;
    // 0x80060DFC: addu        $a3, $t8, $s2
    ctx->r7 = ADD32(ctx->r24, ctx->r18);
    after_0:
    // 0x80060E00: beq         $v0, $zero, L_80060E24
    if (ctx->r2 == 0) {
        // 0x80060E04: nop
    
            goto L_80060E24;
    }
    // 0x80060E04: nop

    // 0x80060E08: lw          $t2, 0x8C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8C);
    // 0x80060E0C: or          $v0, $fp, $zero
    ctx->r2 = ctx->r30 | 0;
    // 0x80060E10: sw          $s1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r17;
    // 0x80060E14: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    // 0x80060E18: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x80060E1C: b           L_80060E68
    // 0x80060E20: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
        goto L_80060E68;
    // 0x80060E20: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
L_80060E24:
    // 0x80060E24: bne         $s0, $s7, L_80060DB4
    if (ctx->r16 != ctx->r23) {
        // 0x80060E28: or          $s1, $s0, $zero
        ctx->r17 = ctx->r16 | 0;
            goto L_80060DB4;
    }
    // 0x80060E28: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
L_80060E2C:
    // 0x80060E2C: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
    // 0x80060E30: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80060E34: bne         $s4, $t5, L_80060DA8
    if (ctx->r20 != ctx->r13) {
        // 0x80060E38: addiu       $fp, $fp, 0x1
        ctx->r30 = ADD32(ctx->r30, 0X1);
            goto L_80060DA8;
    }
    // 0x80060E38: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x80060E3C: lh          $t0, 0x28($s3)
    ctx->r8 = MEM_H(ctx->r19, 0X28);
    // 0x80060E40: nop

    // 0x80060E44: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_80060E48:
    // 0x80060E48: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80060E4C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80060E50: slt         $at, $t7, $t0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80060E54: addiu       $t9, $t8, 0xC
    ctx->r25 = ADD32(ctx->r24, 0XC);
    // 0x80060E58: sw          $t9, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r25;
    // 0x80060E5C: bne         $at, $zero, L_80060D5C
    if (ctx->r1 != 0) {
        // 0x80060E60: sw          $t7, 0x74($sp)
        MEM_W(0X74, ctx->r29) = ctx->r15;
            goto L_80060D5C;
    }
    // 0x80060E60: sw          $t7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r15;
L_80060E64:
    // 0x80060E64: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80060E68:
    // 0x80060E68: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80060E6C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80060E70: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80060E74: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80060E78: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80060E7C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80060E80: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80060E84: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80060E88: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80060E8C: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80060E90: jr          $ra
    // 0x80060E94: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80060E94: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_80060C58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060E98: bne         $a1, $a3, L_80060EB4
    if (ctx->r5 != ctx->r7) {
        // 0x80060E9C: lw          $v1, 0x10($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X10);
            goto L_80060EB4;
    }
    // 0x80060E9C: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
    // 0x80060EA0: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
    // 0x80060EA4: nop

    // 0x80060EA8: beq         $a2, $v1, L_80060EC8
    if (ctx->r6 == ctx->r3) {
        // 0x80060EAC: nop
    
            goto L_80060EC8;
    }
    // 0x80060EAC: nop

    // 0x80060EB0: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
L_80060EB4:
    // 0x80060EB4: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x80060EB8: bne         $a1, $v1, L_80060ED0
    if (ctx->r5 != ctx->r3) {
        // 0x80060EBC: nop
    
            goto L_80060ED0;
    }
    // 0x80060EBC: nop

    // 0x80060EC0: bne         $a2, $a3, L_80060ED0
    if (ctx->r6 != ctx->r7) {
        // 0x80060EC4: nop
    
            goto L_80060ED0;
    }
    // 0x80060EC4: nop

L_80060EC8:
    // 0x80060EC8: jr          $ra
    // 0x80060ECC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80060ECC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80060ED0:
    // 0x80060ED0: multu       $a3, $t5
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80060ED4: mflo        $t6
    ctx->r14 = lo;
    // 0x80060ED8: addu        $v0, $t6, $a0
    ctx->r2 = ADD32(ctx->r14, ctx->r4);
    // 0x80060EDC: lh          $t1, 0x0($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X0);
    // 0x80060EE0: multu       $a1, $t5
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80060EE4: addiu       $t2, $t1, -0x4
    ctx->r10 = ADD32(ctx->r9, -0X4);
    // 0x80060EE8: addiu       $t8, $t1, 0x4
    ctx->r24 = ADD32(ctx->r9, 0X4);
    // 0x80060EEC: mflo        $t7
    ctx->r15 = lo;
    // 0x80060EF0: addu        $t0, $t7, $a0
    ctx->r8 = ADD32(ctx->r15, ctx->r4);
    // 0x80060EF4: lh          $t3, 0x0($t0)
    ctx->r11 = MEM_H(ctx->r8, 0X0);
    // 0x80060EF8: nop

    // 0x80060EFC: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80060F00: beq         $at, $zero, L_80060FE8
    if (ctx->r1 == 0) {
        // 0x80060F04: slt         $at, $t3, $t8
        ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r24) ? 1 : 0;
            goto L_80060FE8;
    }
    // 0x80060F04: slt         $at, $t3, $t8
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80060F08: beq         $at, $zero, L_80060FE8
    if (ctx->r1 == 0) {
        // 0x80060F0C: nop
    
            goto L_80060FE8;
    }
    // 0x80060F0C: nop

    // 0x80060F10: lh          $a3, 0x2($v0)
    ctx->r7 = MEM_H(ctx->r2, 0X2);
    // 0x80060F14: lh          $a1, 0x2($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X2);
    // 0x80060F18: addiu       $t9, $a3, -0x4
    ctx->r25 = ADD32(ctx->r7, -0X4);
    // 0x80060F1C: slt         $at, $t9, $a1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80060F20: beq         $at, $zero, L_80060FE8
    if (ctx->r1 == 0) {
        // 0x80060F24: addiu       $t6, $a3, 0x4
        ctx->r14 = ADD32(ctx->r7, 0X4);
            goto L_80060FE8;
    }
    // 0x80060F24: addiu       $t6, $a3, 0x4
    ctx->r14 = ADD32(ctx->r7, 0X4);
    // 0x80060F28: slt         $at, $a1, $t6
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80060F2C: beq         $at, $zero, L_80060FE8
    if (ctx->r1 == 0) {
        // 0x80060F30: nop
    
            goto L_80060FE8;
    }
    // 0x80060F30: nop

    // 0x80060F34: lh          $a3, 0x4($v0)
    ctx->r7 = MEM_H(ctx->r2, 0X4);
    // 0x80060F38: lh          $a1, 0x4($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X4);
    // 0x80060F3C: addiu       $t7, $a3, -0x4
    ctx->r15 = ADD32(ctx->r7, -0X4);
    // 0x80060F40: slt         $at, $t7, $a1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80060F44: beq         $at, $zero, L_80060FE8
    if (ctx->r1 == 0) {
        // 0x80060F48: addiu       $t8, $a3, 0x4
        ctx->r24 = ADD32(ctx->r7, 0X4);
            goto L_80060FE8;
    }
    // 0x80060F48: addiu       $t8, $a3, 0x4
    ctx->r24 = ADD32(ctx->r7, 0X4);
    // 0x80060F4C: slt         $at, $a1, $t8
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80060F50: beq         $at, $zero, L_80060FE8
    if (ctx->r1 == 0) {
        // 0x80060F54: nop
    
            goto L_80060FE8;
    }
    // 0x80060F54: nop

    // 0x80060F58: multu       $v1, $t5
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80060F5C: mflo        $t9
    ctx->r25 = lo;
    // 0x80060F60: addu        $a3, $t9, $a0
    ctx->r7 = ADD32(ctx->r25, ctx->r4);
    // 0x80060F64: lh          $t4, 0x0($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X0);
    // 0x80060F68: multu       $a2, $t5
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80060F6C: addiu       $t7, $t4, -0x4
    ctx->r15 = ADD32(ctx->r12, -0X4);
    // 0x80060F70: addiu       $t8, $t4, 0x4
    ctx->r24 = ADD32(ctx->r12, 0X4);
    // 0x80060F74: mflo        $t6
    ctx->r14 = lo;
    // 0x80060F78: addu        $a1, $t6, $a0
    ctx->r5 = ADD32(ctx->r14, ctx->r4);
    // 0x80060F7C: lh          $t0, 0x0($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X0);
    // 0x80060F80: nop

    // 0x80060F84: slt         $at, $t7, $t0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80060F88: beq         $at, $zero, L_800610DC
    if (ctx->r1 == 0) {
        // 0x80060F8C: slt         $at, $t0, $t8
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r24) ? 1 : 0;
            goto L_800610DC;
    }
    // 0x80060F8C: slt         $at, $t0, $t8
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80060F90: beq         $at, $zero, L_800610E0
    if (ctx->r1 == 0) {
        // 0x80060F94: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800610E0;
    }
    // 0x80060F94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80060F98: lh          $t3, 0x2($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X2);
    // 0x80060F9C: lh          $v1, 0x2($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X2);
    // 0x80060FA0: addiu       $t9, $t3, -0x4
    ctx->r25 = ADD32(ctx->r11, -0X4);
    // 0x80060FA4: slt         $at, $t9, $v1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80060FA8: beq         $at, $zero, L_800610DC
    if (ctx->r1 == 0) {
        // 0x80060FAC: addiu       $t6, $t3, 0x4
        ctx->r14 = ADD32(ctx->r11, 0X4);
            goto L_800610DC;
    }
    // 0x80060FAC: addiu       $t6, $t3, 0x4
    ctx->r14 = ADD32(ctx->r11, 0X4);
    // 0x80060FB0: slt         $at, $v1, $t6
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80060FB4: beq         $at, $zero, L_800610E0
    if (ctx->r1 == 0) {
        // 0x80060FB8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800610E0;
    }
    // 0x80060FB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80060FBC: lh          $t3, 0x4($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X4);
    // 0x80060FC0: lh          $v1, 0x4($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X4);
    // 0x80060FC4: addiu       $t7, $t3, -0x4
    ctx->r15 = ADD32(ctx->r11, -0X4);
    // 0x80060FC8: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80060FCC: beq         $at, $zero, L_800610DC
    if (ctx->r1 == 0) {
        // 0x80060FD0: addiu       $t8, $t3, 0x4
        ctx->r24 = ADD32(ctx->r11, 0X4);
            goto L_800610DC;
    }
    // 0x80060FD0: addiu       $t8, $t3, 0x4
    ctx->r24 = ADD32(ctx->r11, 0X4);
    // 0x80060FD4: slt         $at, $v1, $t8
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80060FD8: beq         $at, $zero, L_800610E0
    if (ctx->r1 == 0) {
        // 0x80060FDC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800610E0;
    }
    // 0x80060FDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80060FE0: jr          $ra
    // 0x80060FE4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x80060FE4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80060FE8:
    // 0x80060FE8: multu       $v1, $t5
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80060FEC: mflo        $t9
    ctx->r25 = lo;
    // 0x80060FF0: addu        $a3, $t9, $a0
    ctx->r7 = ADD32(ctx->r25, ctx->r4);
    // 0x80060FF4: lh          $t4, 0x0($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X0);
    // 0x80060FF8: nop

    // 0x80060FFC: addiu       $t6, $t4, -0x4
    ctx->r14 = ADD32(ctx->r12, -0X4);
    // 0x80061000: slt         $at, $t6, $t3
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80061004: beq         $at, $zero, L_800610DC
    if (ctx->r1 == 0) {
        // 0x80061008: addiu       $t7, $t4, 0x4
        ctx->r15 = ADD32(ctx->r12, 0X4);
            goto L_800610DC;
    }
    // 0x80061008: addiu       $t7, $t4, 0x4
    ctx->r15 = ADD32(ctx->r12, 0X4);
    // 0x8006100C: slt         $at, $t3, $t7
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80061010: beq         $at, $zero, L_800610DC
    if (ctx->r1 == 0) {
        // 0x80061014: nop
    
            goto L_800610DC;
    }
    // 0x80061014: nop

    // 0x80061018: lh          $t3, 0x2($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X2);
    // 0x8006101C: lh          $a1, 0x2($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X2);
    // 0x80061020: addiu       $t8, $t3, -0x4
    ctx->r24 = ADD32(ctx->r11, -0X4);
    // 0x80061024: slt         $at, $t8, $a1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80061028: beq         $at, $zero, L_800610DC
    if (ctx->r1 == 0) {
        // 0x8006102C: addiu       $t9, $t3, 0x4
        ctx->r25 = ADD32(ctx->r11, 0X4);
            goto L_800610DC;
    }
    // 0x8006102C: addiu       $t9, $t3, 0x4
    ctx->r25 = ADD32(ctx->r11, 0X4);
    // 0x80061030: slt         $at, $a1, $t9
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80061034: beq         $at, $zero, L_800610DC
    if (ctx->r1 == 0) {
        // 0x80061038: nop
    
            goto L_800610DC;
    }
    // 0x80061038: nop

    // 0x8006103C: lh          $t3, 0x4($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X4);
    // 0x80061040: lh          $a1, 0x4($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X4);
    // 0x80061044: addiu       $t6, $t3, -0x4
    ctx->r14 = ADD32(ctx->r11, -0X4);
    // 0x80061048: slt         $at, $t6, $a1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8006104C: beq         $at, $zero, L_800610DC
    if (ctx->r1 == 0) {
        // 0x80061050: addiu       $t7, $t3, 0x4
        ctx->r15 = ADD32(ctx->r11, 0X4);
            goto L_800610DC;
    }
    // 0x80061050: addiu       $t7, $t3, 0x4
    ctx->r15 = ADD32(ctx->r11, 0X4);
    // 0x80061054: slt         $at, $a1, $t7
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80061058: beq         $at, $zero, L_800610DC
    if (ctx->r1 == 0) {
        // 0x8006105C: nop
    
            goto L_800610DC;
    }
    // 0x8006105C: nop

    // 0x80061060: multu       $a2, $t5
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80061064: addiu       $t9, $t1, 0x4
    ctx->r25 = ADD32(ctx->r9, 0X4);
    // 0x80061068: mflo        $t8
    ctx->r24 = lo;
    // 0x8006106C: addu        $a1, $t8, $a0
    ctx->r5 = ADD32(ctx->r24, ctx->r4);
    // 0x80061070: lh          $t0, 0x0($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X0);
    // 0x80061074: nop

    // 0x80061078: slt         $at, $t2, $t0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8006107C: beq         $at, $zero, L_800610DC
    if (ctx->r1 == 0) {
        // 0x80061080: slt         $at, $t0, $t9
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r25) ? 1 : 0;
            goto L_800610DC;
    }
    // 0x80061080: slt         $at, $t0, $t9
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80061084: beq         $at, $zero, L_800610DC
    if (ctx->r1 == 0) {
        // 0x80061088: nop
    
            goto L_800610DC;
    }
    // 0x80061088: nop

    // 0x8006108C: lh          $a3, 0x2($v0)
    ctx->r7 = MEM_H(ctx->r2, 0X2);
    // 0x80061090: lh          $v1, 0x2($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X2);
    // 0x80061094: addiu       $t6, $a3, -0x4
    ctx->r14 = ADD32(ctx->r7, -0X4);
    // 0x80061098: slt         $at, $t6, $v1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8006109C: beq         $at, $zero, L_800610DC
    if (ctx->r1 == 0) {
        // 0x800610A0: addiu       $t7, $a3, 0x4
        ctx->r15 = ADD32(ctx->r7, 0X4);
            goto L_800610DC;
    }
    // 0x800610A0: addiu       $t7, $a3, 0x4
    ctx->r15 = ADD32(ctx->r7, 0X4);
    // 0x800610A4: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800610A8: beq         $at, $zero, L_800610DC
    if (ctx->r1 == 0) {
        // 0x800610AC: nop
    
            goto L_800610DC;
    }
    // 0x800610AC: nop

    // 0x800610B0: lh          $a3, 0x4($v0)
    ctx->r7 = MEM_H(ctx->r2, 0X4);
    // 0x800610B4: lh          $v1, 0x4($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X4);
    // 0x800610B8: addiu       $t8, $a3, -0x4
    ctx->r24 = ADD32(ctx->r7, -0X4);
    // 0x800610BC: slt         $at, $t8, $v1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800610C0: beq         $at, $zero, L_800610DC
    if (ctx->r1 == 0) {
        // 0x800610C4: addiu       $t9, $a3, 0x4
        ctx->r25 = ADD32(ctx->r7, 0X4);
            goto L_800610DC;
    }
    // 0x800610C4: addiu       $t9, $a3, 0x4
    ctx->r25 = ADD32(ctx->r7, 0X4);
    // 0x800610C8: slt         $at, $v1, $t9
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800610CC: beq         $at, $zero, L_800610E0
    if (ctx->r1 == 0) {
        // 0x800610D0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800610E0;
    }
    // 0x800610D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800610D4: jr          $ra
    // 0x800610D8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x800610D8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800610DC:
    // 0x800610DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800610E0:
    // 0x800610E0: jr          $ra
    // 0x800610E4: nop

    return;
    // 0x800610E4: nop

;}
RECOMP_FUNC void model_init_normals(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800610E8: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x800610EC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800610F0: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800610F4: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800610F8: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800610FC: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80061100: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80061104: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80061108: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8006110C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80061110: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80061114: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80061118: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8006111C: sw          $a0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r4;
    // 0x80061120: lh          $v1, 0x28($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X28);
    // 0x80061124: lw          $ra, 0x38($a0)
    ctx->r31 = MEM_W(ctx->r4, 0X38);
    // 0x80061128: sw          $zero, 0x40($a0)
    MEM_W(0X40, ctx->r4) = 0;
    // 0x8006112C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80061130: blez        $v1, L_800611A0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80061134: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_800611A0;
    }
    // 0x80061134: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80061138: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
L_8006113C:
    // 0x8006113C: multu       $s1, $t5
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80061140: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80061144: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80061148: mflo        $t7
    ctx->r15 = lo;
    // 0x8006114C: addu        $v0, $ra, $t7
    ctx->r2 = ADD32(ctx->r31, ctx->r15);
    // 0x80061150: lbu         $t8, 0x6($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X6);
    // 0x80061154: nop

    // 0x80061158: bne         $t8, $at, L_80061174
    if (ctx->r24 != ctx->r1) {
        // 0x8006115C: nop
    
            goto L_80061174;
    }
    // 0x8006115C: nop

    // 0x80061160: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x80061164: nop

    // 0x80061168: andi        $t6, $t9, 0x8000
    ctx->r14 = ctx->r25 & 0X8000;
    // 0x8006116C: beq         $t6, $zero, L_80061190
    if (ctx->r14 == 0) {
        // 0x80061170: sll         $t8, $s1, 16
        ctx->r24 = S32(ctx->r17 << 16);
            goto L_80061190;
    }
    // 0x80061170: sll         $t8, $s1, 16
    ctx->r24 = S32(ctx->r17 << 16);
L_80061174:
    // 0x80061174: lh          $t7, 0xE($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XE);
    // 0x80061178: lh          $t9, 0x2($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X2);
    // 0x8006117C: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x80061180: subu        $a3, $t8, $t9
    ctx->r7 = SUB32(ctx->r24, ctx->r25);
    // 0x80061184: sll         $t6, $a3, 16
    ctx->r14 = S32(ctx->r7 << 16);
    // 0x80061188: sra         $a3, $t6, 16
    ctx->r7 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8006118C: sll         $t8, $s1, 16
    ctx->r24 = S32(ctx->r17 << 16);
L_80061190:
    // 0x80061190: sra         $s1, $t8, 16
    ctx->r17 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80061194: slt         $at, $s1, $v1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80061198: bne         $at, $zero, L_8006113C
    if (ctx->r1 != 0) {
        // 0x8006119C: nop
    
            goto L_8006113C;
    }
    // 0x8006119C: nop

L_800611A0:
    // 0x800611A0: blez        $a3, L_80061BF8
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800611A4: lui         $a1, 0xFF7F
        ctx->r5 = S32(0XFF7F << 16);
            goto L_80061BF8;
    }
    // 0x800611A4: lui         $a1, 0xFF7F
    ctx->r5 = S32(0XFF7F << 16);
    // 0x800611A8: lw          $t6, 0xB8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB8);
    // 0x800611AC: ori         $a1, $a1, 0x7FFF
    ctx->r5 = ctx->r5 | 0X7FFF;
    // 0x800611B0: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x800611B4: lw          $s3, 0x4($t6)
    ctx->r19 = MEM_W(ctx->r14, 0X4);
    // 0x800611B8: sw          $t7, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r15;
    // 0x800611BC: lh          $a0, 0x26($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X26);
    // 0x800611C0: sw          $ra, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r31;
    // 0x800611C4: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x800611C8: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x800611CC: sll         $a0, $t8, 2
    ctx->r4 = S32(ctx->r24 << 2);
    // 0x800611D0: jal         0x80070F50
    // 0x800611D4: sh          $a3, 0x98($sp)
    MEM_H(0X98, ctx->r29) = ctx->r7;
    mempool_alloc(rdram, ctx);
        goto after_0;
    // 0x800611D4: sh          $a3, 0x98($sp)
    MEM_H(0X98, ctx->r29) = ctx->r7;
    after_0:
    // 0x800611D8: lh          $a3, 0x98($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X98);
    // 0x800611DC: lw          $ra, 0xA4($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XA4);
    // 0x800611E0: bne         $v0, $zero, L_800611F0
    if (ctx->r2 != 0) {
        // 0x800611E4: sw          $v0, 0xAC($sp)
        MEM_W(0XAC, ctx->r29) = ctx->r2;
            goto L_800611F0;
    }
    // 0x800611E4: sw          $v0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r2;
    // 0x800611E8: b           L_80061BFC
    // 0x800611EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80061BFC;
    // 0x800611EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800611F0:
    // 0x800611F0: sll         $a0, $a3, 2
    ctx->r4 = S32(ctx->r7 << 2);
    // 0x800611F4: subu        $a0, $a0, $a3
    ctx->r4 = SUB32(ctx->r4, ctx->r7);
    // 0x800611F8: lui         $a1, 0xFF7F
    ctx->r5 = S32(0XFF7F << 16);
    // 0x800611FC: sw          $ra, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r31;
    // 0x80061200: ori         $a1, $a1, 0x7FFF
    ctx->r5 = ctx->r5 | 0X7FFF;
    // 0x80061204: jal         0x80070F50
    // 0x80061208: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    mempool_alloc(rdram, ctx);
        goto after_1;
    // 0x80061208: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    after_1:
    // 0x8006120C: lw          $ra, 0xA4($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XA4);
    // 0x80061210: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x80061214: bne         $v0, $zero, L_80061230
    if (ctx->r2 != 0) {
        // 0x80061218: sw          $v0, 0xA0($sp)
        MEM_W(0XA0, ctx->r29) = ctx->r2;
            goto L_80061230;
    }
    // 0x80061218: sw          $v0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r2;
    // 0x8006121C: lw          $a0, 0xAC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XAC);
    // 0x80061220: jal         0x80071380
    // 0x80061224: nop

    mempool_free(rdram, ctx);
        goto after_2;
    // 0x80061224: nop

    after_2:
    // 0x80061228: b           L_80061BFC
    // 0x8006122C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80061BFC;
    // 0x8006122C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80061230:
    // 0x80061230: lw          $t9, 0xB8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB8);
    // 0x80061234: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80061238: lh          $v1, 0x28($t9)
    ctx->r3 = MEM_H(ctx->r25, 0X28);
    // 0x8006123C: addiu       $s7, $sp, 0x64
    ctx->r23 = ADD32(ctx->r29, 0X64);
    // 0x80061240: blez        $v1, L_80061470
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80061244: addiu       $s6, $sp, 0x70
        ctx->r22 = ADD32(ctx->r29, 0X70);
            goto L_80061470;
    }
    // 0x80061244: addiu       $s6, $sp, 0x70
    ctx->r22 = ADD32(ctx->r29, 0X70);
    // 0x80061248: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8006124C: addiu       $fp, $sp, 0x58
    ctx->r30 = ADD32(ctx->r29, 0X58);
    // 0x80061250: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
L_80061254:
    // 0x80061254: multu       $s1, $t5
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80061258: mflo        $t7
    ctx->r15 = lo;
    // 0x8006125C: addu        $v0, $ra, $t7
    ctx->r2 = ADD32(ctx->r31, ctx->r15);
    // 0x80061260: lh          $s5, 0x4($v0)
    ctx->r21 = MEM_H(ctx->r2, 0X4);
    // 0x80061264: lh          $t6, 0x10($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X10);
    // 0x80061268: lh          $s4, 0x2($v0)
    ctx->r20 = MEM_H(ctx->r2, 0X2);
    // 0x8006126C: slt         $at, $s5, $t6
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80061270: beq         $at, $zero, L_80061458
    if (ctx->r1 == 0) {
        // 0x80061274: nop
    
            goto L_80061458;
    }
    // 0x80061274: nop

    // 0x80061278: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x8006127C: lw          $t8, 0xB0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB0);
L_80061280:
    // 0x80061280: sll         $t9, $s5, 4
    ctx->r25 = S32(ctx->r21 << 4);
    // 0x80061284: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80061288: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
L_8006128C:
    // 0x8006128C: addu        $t7, $a0, $a3
    ctx->r15 = ADD32(ctx->r4, ctx->r7);
    // 0x80061290: lbu         $t6, 0x1($t7)
    ctx->r14 = MEM_BU(ctx->r15, 0X1);
    // 0x80061294: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
    // 0x80061298: addu        $a2, $t6, $s4
    ctx->r6 = ADD32(ctx->r14, ctx->r20);
    // 0x8006129C: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x800612A0: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800612A4: multu       $t9, $s2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800612A8: addu        $t8, $s6, $v0
    ctx->r24 = ADD32(ctx->r22, ctx->r2);
    // 0x800612AC: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800612B0: mflo        $t7
    ctx->r15 = lo;
    // 0x800612B4: addu        $v1, $s3, $t7
    ctx->r3 = ADD32(ctx->r19, ctx->r15);
    // 0x800612B8: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x800612BC: addu        $t7, $s7, $v0
    ctx->r15 = ADD32(ctx->r23, ctx->r2);
    // 0x800612C0: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800612C4: nop

    // 0x800612C8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800612CC: swc1        $f6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f6.u32l;
    // 0x800612D0: lh          $t9, 0x2($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X2);
    // 0x800612D4: addu        $t8, $fp, $v0
    ctx->r24 = ADD32(ctx->r30, ctx->r2);
    // 0x800612D8: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800612DC: sll         $t9, $a3, 16
    ctx->r25 = S32(ctx->r7 << 16);
    // 0x800612E0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800612E4: sra         $a3, $t9, 16
    ctx->r7 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800612E8: slti        $at, $a3, 0x3
    ctx->r1 = SIGNED(ctx->r7) < 0X3 ? 1 : 0;
    // 0x800612EC: swc1        $f10, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f10.u32l;
    // 0x800612F0: lh          $t6, 0x4($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X4);
    // 0x800612F4: nop

    // 0x800612F8: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x800612FC: nop

    // 0x80061300: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80061304: bne         $at, $zero, L_8006128C
    if (ctx->r1 != 0) {
        // 0x80061308: swc1        $f18, 0x0($t8)
        MEM_W(0X0, ctx->r24) = ctx->f18.u32l;
            goto L_8006128C;
    }
    // 0x80061308: swc1        $f18, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f18.u32l;
    // 0x8006130C: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80061310: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80061314: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80061318: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8006131C: multu       $s5, $t5
    result = U64(U32(ctx->r21)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80061320: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80061324: lw          $t6, 0xAC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XAC);
    // 0x80061328: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8006132C: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80061330: mul.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80061334: lwc1        $f18, 0x6C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80061338: sub.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x8006133C: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80061340: mflo        $t8
    ctx->r24 = lo;
    // 0x80061344: mul.s       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80061348: addu        $s0, $t6, $t8
    ctx->r16 = ADD32(ctx->r14, ctx->r24);
    // 0x8006134C: sub.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x80061350: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    // 0x80061354: lwc1        $f16, 0x78($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80061358: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8006135C: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80061360: lwc1        $f18, 0x58($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80061364: sub.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x80061368: lwc1        $f16, 0x60($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8006136C: sub.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x80061370: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80061374: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80061378: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8006137C: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80061380: sub.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80061384: mul.s       $f16, $f4, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80061388: sub.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x8006138C: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x80061390: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80061394: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80061398: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8006139C: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800613A0: sub.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x800613A4: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800613A8: sub.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800613AC: lwc1        $f14, 0x4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800613B0: mul.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800613B4: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800613B8: sub.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x800613BC: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800613C0: mul.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800613C4: sub.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x800613C8: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800613CC: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x800613D0: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800613D4: sw          $ra, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r31;
    // 0x800613D8: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800613DC: nop

    // 0x800613E0: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800613E4: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800613E8: jal         0x800CA030
    // 0x800613EC: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x800613EC: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    after_3:
    // 0x800613F0: c.eq.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl == ctx->f20.fl;
    // 0x800613F4: lw          $ra, 0xA4($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XA4);
    // 0x800613F8: bc1t        L_80061428
    if (c1cs) {
        // 0x800613FC: addiu       $t5, $zero, 0xC
        ctx->r13 = ADD32(0, 0XC);
            goto L_80061428;
    }
    // 0x800613FC: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x80061400: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80061404: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80061408: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006140C: div.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80061410: nop

    // 0x80061414: div.s       $f18, $f6, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80061418: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    // 0x8006141C: div.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80061420: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x80061424: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
L_80061428:
    // 0x80061428: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8006142C: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80061430: lh          $t8, 0x10($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X10);
    // 0x80061434: sll         $t9, $s5, 16
    ctx->r25 = S32(ctx->r21 << 16);
    // 0x80061438: sra         $s5, $t9, 16
    ctx->r21 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8006143C: slt         $at, $s5, $t8
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80061440: bne         $at, $zero, L_80061280
    if (ctx->r1 != 0) {
        // 0x80061444: lw          $t8, 0xB0($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XB0);
            goto L_80061280;
    }
    // 0x80061444: lw          $t8, 0xB0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB0);
    // 0x80061448: lw          $t9, 0xB8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB8);
    // 0x8006144C: nop

    // 0x80061450: lh          $v1, 0x28($t9)
    ctx->r3 = MEM_H(ctx->r25, 0X28);
    // 0x80061454: nop

L_80061458:
    // 0x80061458: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006145C: sll         $t7, $s1, 16
    ctx->r15 = S32(ctx->r17 << 16);
    // 0x80061460: sra         $s1, $t7, 16
    ctx->r17 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80061464: slt         $at, $s1, $v1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80061468: bne         $at, $zero, L_80061254
    if (ctx->r1 != 0) {
        // 0x8006146C: nop
    
            goto L_80061254;
    }
    // 0x8006146C: nop

L_80061470:
    // 0x80061470: lw          $t8, 0xB8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB8);
    // 0x80061474: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80061478: lh          $a0, 0x24($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X24);
    // 0x8006147C: sw          $ra, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r31;
    // 0x80061480: lui         $a1, 0xFF7F
    ctx->r5 = S32(0XFF7F << 16);
    // 0x80061484: sll         $t9, $a0, 1
    ctx->r25 = S32(ctx->r4 << 1);
    // 0x80061488: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
    // 0x8006148C: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x80061490: jal         0x80070F50
    // 0x80061494: ori         $a1, $a1, 0x7FFF
    ctx->r5 = ctx->r5 | 0X7FFF;
    mempool_alloc(rdram, ctx);
        goto after_4;
    // 0x80061494: ori         $a1, $a1, 0x7FFF
    ctx->r5 = ctx->r5 | 0X7FFF;
    after_4:
    // 0x80061498: lw          $ra, 0xA4($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XA4);
    // 0x8006149C: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x800614A0: bne         $v0, $zero, L_800614C8
    if (ctx->r2 != 0) {
        // 0x800614A4: or          $s7, $v0, $zero
        ctx->r23 = ctx->r2 | 0;
            goto L_800614C8;
    }
    // 0x800614A4: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x800614A8: lw          $a0, 0xAC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XAC);
    // 0x800614AC: jal         0x80071380
    // 0x800614B0: nop

    mempool_free(rdram, ctx);
        goto after_5;
    // 0x800614B0: nop

    after_5:
    // 0x800614B4: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x800614B8: jal         0x80071380
    // 0x800614BC: nop

    mempool_free(rdram, ctx);
        goto after_6;
    // 0x800614BC: nop

    after_6:
    // 0x800614C0: b           L_80061BFC
    // 0x800614C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80061BFC;
    // 0x800614C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800614C8:
    // 0x800614C8: lw          $t7, 0xB8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB8);
    // 0x800614CC: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x800614D0: lh          $v1, 0x28($t7)
    ctx->r3 = MEM_H(ctx->r15, 0X28);
    // 0x800614D4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800614D8: blez        $v1, L_80061874
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800614DC: addiu       $s4, $zero, -0x1
        ctx->r20 = ADD32(0, -0X1);
            goto L_80061874;
    }
    // 0x800614DC: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // 0x800614E0: addiu       $s0, $zero, 0xFE
    ctx->r16 = ADD32(0, 0XFE);
L_800614E4:
    // 0x800614E4: multu       $s1, $t5
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800614E8: mflo        $t6
    ctx->r14 = lo;
    // 0x800614EC: addu        $t8, $ra, $t6
    ctx->r24 = ADD32(ctx->r31, ctx->r14);
    // 0x800614F0: sw          $t8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r24;
    // 0x800614F4: lh          $t7, 0xE($t8)
    ctx->r15 = MEM_H(ctx->r24, 0XE);
    // 0x800614F8: lh          $t3, 0x2($t8)
    ctx->r11 = MEM_H(ctx->r24, 0X2);
    // 0x800614FC: nop

    // 0x80061500: slt         $at, $t3, $t7
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80061504: beq         $at, $zero, L_8006185C
    if (ctx->r1 == 0) {
        // 0x80061508: nop
    
            goto L_8006185C;
    }
    // 0x80061508: nop

    // 0x8006150C: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
L_80061510:
    // 0x80061510: nop

    // 0x80061514: lbu         $t4, 0x6($t6)
    ctx->r12 = MEM_BU(ctx->r14, 0X6);
    // 0x80061518: nop

    // 0x8006151C: slti        $at, $t4, 0xFE
    ctx->r1 = SIGNED(ctx->r12) < 0XFE ? 1 : 0;
    // 0x80061520: beq         $at, $zero, L_80061684
    if (ctx->r1 == 0) {
        // 0x80061524: nop
    
            goto L_80061684;
    }
    // 0x80061524: nop

    // 0x80061528: multu       $t3, $s2
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006152C: sll         $a2, $s4, 16
    ctx->r6 = S32(ctx->r20 << 16);
    // 0x80061530: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80061534: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x80061538: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006153C: mflo        $t9
    ctx->r25 = lo;
    // 0x80061540: addu        $v1, $s3, $t9
    ctx->r3 = ADD32(ctx->r19, ctx->r25);
    // 0x80061544: lh          $t0, 0x0($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X0);
    // 0x80061548: lh          $t1, 0x2($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X2);
    // 0x8006154C: lh          $t2, 0x4($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X4);
    // 0x80061550: bltz        $s1, L_80061654
    if (SIGNED(ctx->r17) < 0) {
        // 0x80061554: nop
    
            goto L_80061654;
    }
    // 0x80061554: nop

L_80061558:
    // 0x80061558: multu       $a1, $t5
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006155C: mflo        $t7
    ctx->r15 = lo;
    // 0x80061560: addu        $a3, $ra, $t7
    ctx->r7 = ADD32(ctx->r31, ctx->r15);
    // 0x80061564: lbu         $t6, 0x6($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X6);
    // 0x80061568: nop

    // 0x8006156C: bne         $t4, $t6, L_80061634
    if (ctx->r12 != ctx->r14) {
        // 0x80061570: nop
    
            goto L_80061634;
    }
    // 0x80061570: nop

    // 0x80061574: lh          $a0, 0x2($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X2);
    // 0x80061578: bne         $a1, $s1, L_80061588
    if (ctx->r5 != ctx->r17) {
        // 0x8006157C: slt         $at, $a0, $t3
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r11) ? 1 : 0;
            goto L_80061588;
    }
    // 0x8006157C: slt         $at, $a0, $t3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80061580: bne         $at, $zero, L_800615A4
    if (ctx->r1 != 0) {
        // 0x80061584: nop
    
            goto L_800615A4;
    }
    // 0x80061584: nop

L_80061588:
    // 0x80061588: beq         $a1, $s1, L_80061634
    if (ctx->r5 == ctx->r17) {
        // 0x8006158C: nop
    
            goto L_80061634;
    }
    // 0x8006158C: nop

    // 0x80061590: lh          $t8, 0xE($a3)
    ctx->r24 = MEM_H(ctx->r7, 0XE);
    // 0x80061594: nop

    // 0x80061598: slt         $at, $a0, $t8
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8006159C: beq         $at, $zero, L_80061634
    if (ctx->r1 == 0) {
        // 0x800615A0: nop
    
            goto L_80061634;
    }
    // 0x800615A0: nop

L_800615A4:
    // 0x800615A4: bgez        $a2, L_80061634
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800615A8: nop
    
            goto L_80061634;
    }
    // 0x800615A8: nop

L_800615AC:
    // 0x800615AC: multu       $a0, $s2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800615B0: mflo        $t9
    ctx->r25 = lo;
    // 0x800615B4: addu        $v1, $s3, $t9
    ctx->r3 = ADD32(ctx->r19, ctx->r25);
    // 0x800615B8: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x800615BC: nop

    // 0x800615C0: bne         $t0, $t7, L_800615F0
    if (ctx->r8 != ctx->r15) {
        // 0x800615C4: nop
    
            goto L_800615F0;
    }
    // 0x800615C4: nop

    // 0x800615C8: lh          $t6, 0x2($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X2);
    // 0x800615CC: nop

    // 0x800615D0: bne         $t1, $t6, L_800615F0
    if (ctx->r9 != ctx->r14) {
        // 0x800615D4: nop
    
            goto L_800615F0;
    }
    // 0x800615D4: nop

    // 0x800615D8: lh          $t8, 0x4($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X4);
    // 0x800615DC: sll         $t9, $a0, 1
    ctx->r25 = S32(ctx->r4 << 1);
    // 0x800615E0: bne         $t2, $t8, L_800615F0
    if (ctx->r10 != ctx->r24) {
        // 0x800615E4: addu        $t7, $v0, $t9
        ctx->r15 = ADD32(ctx->r2, ctx->r25);
            goto L_800615F0;
    }
    // 0x800615E4: addu        $t7, $v0, $t9
    ctx->r15 = ADD32(ctx->r2, ctx->r25);
    // 0x800615E8: lh          $a2, 0x0($t7)
    ctx->r6 = MEM_H(ctx->r15, 0X0);
    // 0x800615EC: nop

L_800615F0:
    // 0x800615F0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800615F4: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x800615F8: sra         $t8, $t6, 16
    ctx->r24 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800615FC: bne         $a1, $s1, L_80061610
    if (ctx->r5 != ctx->r17) {
        // 0x80061600: or          $a0, $t8, $zero
        ctx->r4 = ctx->r24 | 0;
            goto L_80061610;
    }
    // 0x80061600: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x80061604: slt         $at, $t8, $t3
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80061608: bne         $at, $zero, L_8006162C
    if (ctx->r1 != 0) {
        // 0x8006160C: nop
    
            goto L_8006162C;
    }
    // 0x8006160C: nop

L_80061610:
    // 0x80061610: beq         $a1, $s1, L_80061634
    if (ctx->r5 == ctx->r17) {
        // 0x80061614: nop
    
            goto L_80061634;
    }
    // 0x80061614: nop

    // 0x80061618: lh          $t9, 0xE($a3)
    ctx->r25 = MEM_H(ctx->r7, 0XE);
    // 0x8006161C: nop

    // 0x80061620: slt         $at, $a0, $t9
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80061624: beq         $at, $zero, L_80061634
    if (ctx->r1 == 0) {
        // 0x80061628: nop
    
            goto L_80061634;
    }
    // 0x80061628: nop

L_8006162C:
    // 0x8006162C: bltz        $a2, L_800615AC
    if (SIGNED(ctx->r6) < 0) {
        // 0x80061630: nop
    
            goto L_800615AC;
    }
    // 0x80061630: nop

L_80061634:
    // 0x80061634: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80061638: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x8006163C: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80061640: slt         $at, $s1, $a1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80061644: bne         $at, $zero, L_80061654
    if (ctx->r1 != 0) {
        // 0x80061648: nop
    
            goto L_80061654;
    }
    // 0x80061648: nop

    // 0x8006164C: bltz        $a2, L_80061558
    if (SIGNED(ctx->r6) < 0) {
        // 0x80061650: nop
    
            goto L_80061558;
    }
    // 0x80061650: nop

L_80061654:
    // 0x80061654: bgez        $a2, L_80061678
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80061658: sll         $t8, $t3, 1
        ctx->r24 = S32(ctx->r11 << 1);
            goto L_80061678;
    }
    // 0x80061658: sll         $t8, $t3, 1
    ctx->r24 = S32(ctx->r11 << 1);
    // 0x8006165C: sll         $t8, $t3, 1
    ctx->r24 = S32(ctx->r11 << 1);
    // 0x80061660: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80061664: sh          $s6, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r22;
    // 0x80061668: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x8006166C: sll         $t7, $s6, 16
    ctx->r15 = S32(ctx->r22 << 16);
    // 0x80061670: b           L_8006182C
    // 0x80061674: sra         $s6, $t7, 16
    ctx->r22 = S32(SIGNED(ctx->r15) >> 16);
        goto L_8006182C;
    // 0x80061674: sra         $s6, $t7, 16
    ctx->r22 = S32(SIGNED(ctx->r15) >> 16);
L_80061678:
    // 0x80061678: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8006167C: b           L_8006182C
    // 0x80061680: sh          $a2, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r6;
        goto L_8006182C;
    // 0x80061680: sh          $a2, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r6;
L_80061684:
    // 0x80061684: bne         $s0, $t4, L_800616A4
    if (ctx->r16 != ctx->r12) {
        // 0x80061688: sll         $t7, $t3, 1
        ctx->r15 = S32(ctx->r11 << 1);
            goto L_800616A4;
    }
    // 0x80061688: sll         $t7, $t3, 1
    ctx->r15 = S32(ctx->r11 << 1);
    // 0x8006168C: addu        $t6, $v0, $t7
    ctx->r14 = ADD32(ctx->r2, ctx->r15);
    // 0x80061690: sh          $s6, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r22;
    // 0x80061694: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x80061698: sll         $t8, $s6, 16
    ctx->r24 = S32(ctx->r22 << 16);
    // 0x8006169C: b           L_8006182C
    // 0x800616A0: sra         $s6, $t8, 16
    ctx->r22 = S32(SIGNED(ctx->r24) >> 16);
        goto L_8006182C;
    // 0x800616A0: sra         $s6, $t8, 16
    ctx->r22 = S32(SIGNED(ctx->r24) >> 16);
L_800616A4:
    // 0x800616A4: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x800616A8: nop

    // 0x800616AC: lw          $t6, 0x8($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X8);
    // 0x800616B0: nop

    // 0x800616B4: andi        $t8, $t6, 0x8000
    ctx->r24 = ctx->r14 & 0X8000;
    // 0x800616B8: beq         $t8, $zero, L_80061824
    if (ctx->r24 == 0) {
        // 0x800616BC: sll         $t8, $t3, 1
        ctx->r24 = S32(ctx->r11 << 1);
            goto L_80061824;
    }
    // 0x800616BC: sll         $t8, $t3, 1
    ctx->r24 = S32(ctx->r11 << 1);
    // 0x800616C0: multu       $t3, $s2
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800616C4: sll         $a2, $s4, 16
    ctx->r6 = S32(ctx->r20 << 16);
    // 0x800616C8: sra         $t9, $a2, 16
    ctx->r25 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800616CC: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x800616D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800616D4: mflo        $t7
    ctx->r15 = lo;
    // 0x800616D8: addu        $v1, $s3, $t7
    ctx->r3 = ADD32(ctx->r19, ctx->r15);
    // 0x800616DC: lh          $t0, 0x0($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X0);
    // 0x800616E0: lh          $t1, 0x2($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X2);
    // 0x800616E4: lh          $t2, 0x4($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X4);
    // 0x800616E8: bltz        $s1, L_800617F0
    if (SIGNED(ctx->r17) < 0) {
        // 0x800616EC: nop
    
            goto L_800617F0;
    }
    // 0x800616EC: nop

L_800616F0:
    // 0x800616F0: multu       $a1, $t5
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800616F4: mflo        $t6
    ctx->r14 = lo;
    // 0x800616F8: addu        $a3, $ra, $t6
    ctx->r7 = ADD32(ctx->r31, ctx->r14);
    // 0x800616FC: lw          $t8, 0x8($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X8);
    // 0x80061700: nop

    // 0x80061704: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x80061708: beq         $t9, $zero, L_800617D0
    if (ctx->r25 == 0) {
        // 0x8006170C: nop
    
            goto L_800617D0;
    }
    // 0x8006170C: nop

    // 0x80061710: lh          $a0, 0x2($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X2);
    // 0x80061714: bne         $a1, $s1, L_80061724
    if (ctx->r5 != ctx->r17) {
        // 0x80061718: slt         $at, $a0, $t3
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r11) ? 1 : 0;
            goto L_80061724;
    }
    // 0x80061718: slt         $at, $a0, $t3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8006171C: bne         $at, $zero, L_80061740
    if (ctx->r1 != 0) {
        // 0x80061720: nop
    
            goto L_80061740;
    }
    // 0x80061720: nop

L_80061724:
    // 0x80061724: beq         $a1, $s1, L_800617D0
    if (ctx->r5 == ctx->r17) {
        // 0x80061728: nop
    
            goto L_800617D0;
    }
    // 0x80061728: nop

    // 0x8006172C: lh          $t7, 0xE($a3)
    ctx->r15 = MEM_H(ctx->r7, 0XE);
    // 0x80061730: nop

    // 0x80061734: slt         $at, $a0, $t7
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80061738: beq         $at, $zero, L_800617D0
    if (ctx->r1 == 0) {
        // 0x8006173C: nop
    
            goto L_800617D0;
    }
    // 0x8006173C: nop

L_80061740:
    // 0x80061740: bgez        $a2, L_800617D0
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80061744: nop
    
            goto L_800617D0;
    }
    // 0x80061744: nop

L_80061748:
    // 0x80061748: multu       $a0, $s2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006174C: mflo        $t6
    ctx->r14 = lo;
    // 0x80061750: addu        $v1, $s3, $t6
    ctx->r3 = ADD32(ctx->r19, ctx->r14);
    // 0x80061754: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x80061758: nop

    // 0x8006175C: bne         $t0, $t8, L_8006178C
    if (ctx->r8 != ctx->r24) {
        // 0x80061760: nop
    
            goto L_8006178C;
    }
    // 0x80061760: nop

    // 0x80061764: lh          $t9, 0x2($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X2);
    // 0x80061768: nop

    // 0x8006176C: bne         $t1, $t9, L_8006178C
    if (ctx->r9 != ctx->r25) {
        // 0x80061770: nop
    
            goto L_8006178C;
    }
    // 0x80061770: nop

    // 0x80061774: lh          $t7, 0x4($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X4);
    // 0x80061778: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x8006177C: bne         $t2, $t7, L_8006178C
    if (ctx->r10 != ctx->r15) {
        // 0x80061780: addu        $t8, $v0, $t6
        ctx->r24 = ADD32(ctx->r2, ctx->r14);
            goto L_8006178C;
    }
    // 0x80061780: addu        $t8, $v0, $t6
    ctx->r24 = ADD32(ctx->r2, ctx->r14);
    // 0x80061784: lh          $a2, 0x0($t8)
    ctx->r6 = MEM_H(ctx->r24, 0X0);
    // 0x80061788: nop

L_8006178C:
    // 0x8006178C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80061790: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
    // 0x80061794: sra         $t7, $t9, 16
    ctx->r15 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80061798: bne         $a1, $s1, L_800617AC
    if (ctx->r5 != ctx->r17) {
        // 0x8006179C: or          $a0, $t7, $zero
        ctx->r4 = ctx->r15 | 0;
            goto L_800617AC;
    }
    // 0x8006179C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800617A0: slt         $at, $t7, $t3
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800617A4: bne         $at, $zero, L_800617C8
    if (ctx->r1 != 0) {
        // 0x800617A8: nop
    
            goto L_800617C8;
    }
    // 0x800617A8: nop

L_800617AC:
    // 0x800617AC: beq         $a1, $s1, L_800617D0
    if (ctx->r5 == ctx->r17) {
        // 0x800617B0: nop
    
            goto L_800617D0;
    }
    // 0x800617B0: nop

    // 0x800617B4: lh          $t6, 0xE($a3)
    ctx->r14 = MEM_H(ctx->r7, 0XE);
    // 0x800617B8: nop

    // 0x800617BC: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800617C0: beq         $at, $zero, L_800617D0
    if (ctx->r1 == 0) {
        // 0x800617C4: nop
    
            goto L_800617D0;
    }
    // 0x800617C4: nop

L_800617C8:
    // 0x800617C8: bltz        $a2, L_80061748
    if (SIGNED(ctx->r6) < 0) {
        // 0x800617CC: nop
    
            goto L_80061748;
    }
    // 0x800617CC: nop

L_800617D0:
    // 0x800617D0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800617D4: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x800617D8: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800617DC: slt         $at, $s1, $a1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800617E0: bne         $at, $zero, L_800617F0
    if (ctx->r1 != 0) {
        // 0x800617E4: nop
    
            goto L_800617F0;
    }
    // 0x800617E4: nop

    // 0x800617E8: bltz        $a2, L_800616F0
    if (SIGNED(ctx->r6) < 0) {
        // 0x800617EC: nop
    
            goto L_800616F0;
    }
    // 0x800617EC: nop

L_800617F0:
    // 0x800617F0: bgez        $a2, L_80061814
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800617F4: sll         $t7, $t3, 1
        ctx->r15 = S32(ctx->r11 << 1);
            goto L_80061814;
    }
    // 0x800617F4: sll         $t7, $t3, 1
    ctx->r15 = S32(ctx->r11 << 1);
    // 0x800617F8: sll         $t7, $t3, 1
    ctx->r15 = S32(ctx->r11 << 1);
    // 0x800617FC: addu        $t6, $v0, $t7
    ctx->r14 = ADD32(ctx->r2, ctx->r15);
    // 0x80061800: sh          $s6, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r22;
    // 0x80061804: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x80061808: sll         $t8, $s6, 16
    ctx->r24 = S32(ctx->r22 << 16);
    // 0x8006180C: b           L_8006182C
    // 0x80061810: sra         $s6, $t8, 16
    ctx->r22 = S32(SIGNED(ctx->r24) >> 16);
        goto L_8006182C;
    // 0x80061810: sra         $s6, $t8, 16
    ctx->r22 = S32(SIGNED(ctx->r24) >> 16);
L_80061814:
    // 0x80061814: addu        $t6, $v0, $t7
    ctx->r14 = ADD32(ctx->r2, ctx->r15);
    // 0x80061818: b           L_8006182C
    // 0x8006181C: sh          $a2, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r6;
        goto L_8006182C;
    // 0x8006181C: sh          $a2, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r6;
    // 0x80061820: sll         $t8, $t3, 1
    ctx->r24 = S32(ctx->r11 << 1);
L_80061824:
    // 0x80061824: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80061828: sh          $s4, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r20;
L_8006182C:
    // 0x8006182C: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80061830: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x80061834: lh          $t9, 0xE($t8)
    ctx->r25 = MEM_H(ctx->r24, 0XE);
    // 0x80061838: sll         $t7, $t3, 16
    ctx->r15 = S32(ctx->r11 << 16);
    // 0x8006183C: sra         $t3, $t7, 16
    ctx->r11 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80061840: slt         $at, $t3, $t9
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80061844: bne         $at, $zero, L_80061510
    if (ctx->r1 != 0) {
        // 0x80061848: lw          $t6, 0x50($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X50);
            goto L_80061510;
    }
    // 0x80061848: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8006184C: lw          $t7, 0xB8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB8);
    // 0x80061850: nop

    // 0x80061854: lh          $v1, 0x28($t7)
    ctx->r3 = MEM_H(ctx->r15, 0X28);
    // 0x80061858: nop

L_8006185C:
    // 0x8006185C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80061860: sll         $t6, $s1, 16
    ctx->r14 = S32(ctx->r17 << 16);
    // 0x80061864: sra         $s1, $t6, 16
    ctx->r17 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80061868: slt         $at, $s1, $v1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8006186C: bne         $at, $zero, L_800614E4
    if (ctx->r1 != 0) {
        // 0x80061870: nop
    
            goto L_800614E4;
    }
    // 0x80061870: nop

L_80061874:
    // 0x80061874: sll         $a0, $s6, 2
    ctx->r4 = S32(ctx->r22 << 2);
    // 0x80061878: subu        $a0, $a0, $s6
    ctx->r4 = SUB32(ctx->r4, ctx->r22);
    // 0x8006187C: lui         $a1, 0xFF7F
    ctx->r5 = S32(0XFF7F << 16);
    // 0x80061880: sw          $ra, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r31;
    // 0x80061884: ori         $a1, $a1, 0x7FFF
    ctx->r5 = ctx->r5 | 0X7FFF;
    // 0x80061888: jal         0x80070F50
    // 0x8006188C: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    mempool_alloc(rdram, ctx);
        goto after_7;
    // 0x8006188C: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    after_7:
    // 0x80061890: lw          $ra, 0xA4($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XA4);
    // 0x80061894: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x80061898: bne         $v0, $zero, L_800618C8
    if (ctx->r2 != 0) {
        // 0x8006189C: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_800618C8;
    }
    // 0x8006189C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800618A0: lw          $a0, 0xAC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XAC);
    // 0x800618A4: jal         0x80071380
    // 0x800618A8: nop

    mempool_free(rdram, ctx);
        goto after_8;
    // 0x800618A8: nop

    after_8:
    // 0x800618AC: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x800618B0: jal         0x80071380
    // 0x800618B4: nop

    mempool_free(rdram, ctx);
        goto after_9;
    // 0x800618B4: nop

    after_9:
    // 0x800618B8: jal         0x80071380
    // 0x800618BC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    mempool_free(rdram, ctx);
        goto after_10;
    // 0x800618BC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_10:
    // 0x800618C0: b           L_80061BFC
    // 0x800618C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80061BFC;
    // 0x800618C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800618C8:
    // 0x800618C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800618CC: blez        $s6, L_80061900
    if (SIGNED(ctx->r22) <= 0) {
        // 0x800618D0: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80061900;
    }
    // 0x800618D0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800618D4:
    // 0x800618D4: multu       $a3, $t5
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800618D8: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800618DC: sll         $t7, $a3, 16
    ctx->r15 = S32(ctx->r7 << 16);
    // 0x800618E0: sra         $a3, $t7, 16
    ctx->r7 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800618E4: slt         $at, $a3, $s6
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x800618E8: mflo        $t9
    ctx->r25 = lo;
    // 0x800618EC: addu        $v1, $v0, $t9
    ctx->r3 = ADD32(ctx->r2, ctx->r25);
    // 0x800618F0: swc1        $f20, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f20.u32l;
    // 0x800618F4: swc1        $f20, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f20.u32l;
    // 0x800618F8: bne         $at, $zero, L_800618D4
    if (ctx->r1 != 0) {
        // 0x800618FC: swc1        $f20, 0x8($v1)
        MEM_W(0X8, ctx->r3) = ctx->f20.u32l;
            goto L_800618D4;
    }
    // 0x800618FC: swc1        $f20, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f20.u32l;
L_80061900:
    // 0x80061900: lw          $t8, 0xB8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB8);
    // 0x80061904: nop

    // 0x80061908: lh          $v1, 0x28($t8)
    ctx->r3 = MEM_H(ctx->r24, 0X28);
    // 0x8006190C: nop

    // 0x80061910: blez        $v1, L_80061A50
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80061914: nop
    
            goto L_80061A50;
    }
    // 0x80061914: nop

L_80061918:
    // 0x80061918: multu       $s1, $t5
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006191C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80061920: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80061924: mflo        $t9
    ctx->r25 = lo;
    // 0x80061928: addu        $t0, $ra, $t9
    ctx->r8 = ADD32(ctx->r31, ctx->r25);
    // 0x8006192C: lbu         $t7, 0x6($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X6);
    // 0x80061930: nop

    // 0x80061934: bne         $t7, $at, L_80061950
    if (ctx->r15 != ctx->r1) {
        // 0x80061938: nop
    
            goto L_80061950;
    }
    // 0x80061938: nop

    // 0x8006193C: lw          $t6, 0x8($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X8);
    // 0x80061940: nop

    // 0x80061944: andi        $t8, $t6, 0x8000
    ctx->r24 = ctx->r14 & 0X8000;
    // 0x80061948: beq         $t8, $zero, L_80061A40
    if (ctx->r24 == 0) {
        // 0x8006194C: sll         $t8, $s1, 16
        ctx->r24 = S32(ctx->r17 << 16);
            goto L_80061A40;
    }
    // 0x8006194C: sll         $t8, $s1, 16
    ctx->r24 = S32(ctx->r17 << 16);
L_80061950:
    // 0x80061950: lh          $s5, 0x4($t0)
    ctx->r21 = MEM_H(ctx->r8, 0X4);
    // 0x80061954: lh          $t9, 0x10($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X10);
    // 0x80061958: lh          $s4, 0x2($t0)
    ctx->r20 = MEM_H(ctx->r8, 0X2);
    // 0x8006195C: slt         $at, $s5, $t9
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80061960: beq         $at, $zero, L_80061A40
    if (ctx->r1 == 0) {
        // 0x80061964: sll         $t8, $s1, 16
        ctx->r24 = S32(ctx->r17 << 16);
            goto L_80061A40;
    }
    // 0x80061964: sll         $t8, $s1, 16
    ctx->r24 = S32(ctx->r17 << 16);
    // 0x80061968: lw          $t1, 0xB0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB0);
    // 0x8006196C: lw          $a1, 0xAC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XAC);
    // 0x80061970: nop

    // 0x80061974: sll         $t7, $s5, 4
    ctx->r15 = S32(ctx->r21 << 4);
L_80061978:
    // 0x80061978: addu        $a0, $t1, $t7
    ctx->r4 = ADD32(ctx->r9, ctx->r15);
    // 0x8006197C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80061980: addu        $t6, $a0, $a3
    ctx->r14 = ADD32(ctx->r4, ctx->r7);
L_80061984:
    // 0x80061984: lbu         $t8, 0x1($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X1);
    // 0x80061988: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8006198C: addu        $a2, $t8, $s4
    ctx->r6 = ADD32(ctx->r24, ctx->r20);
    // 0x80061990: sll         $t9, $a2, 16
    ctx->r25 = S32(ctx->r6 << 16);
    // 0x80061994: sra         $t7, $t9, 16
    ctx->r15 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80061998: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x8006199C: addu        $t8, $s7, $t6
    ctx->r24 = ADD32(ctx->r23, ctx->r14);
    // 0x800619A0: lh          $a2, 0x0($t8)
    ctx->r6 = MEM_H(ctx->r24, 0X0);
    // 0x800619A4: sll         $t6, $a3, 16
    ctx->r14 = S32(ctx->r7 << 16);
    // 0x800619A8: bltz        $a2, L_80061A04
    if (SIGNED(ctx->r6) < 0) {
        // 0x800619AC: sra         $a3, $t6, 16
        ctx->r7 = S32(SIGNED(ctx->r14) >> 16);
            goto L_80061A04;
    }
    // 0x800619AC: sra         $a3, $t6, 16
    ctx->r7 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800619B0: multu       $a2, $t5
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800619B4: mflo        $t9
    ctx->r25 = lo;
    // 0x800619B8: addu        $v1, $v0, $t9
    ctx->r3 = ADD32(ctx->r2, ctx->r25);
    // 0x800619BC: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800619C0: multu       $s5, $t5
    result = U64(U32(ctx->r21)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800619C4: lwc1        $f18, 0x4($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800619C8: mflo        $t7
    ctx->r15 = lo;
    // 0x800619CC: addu        $s0, $a1, $t7
    ctx->r16 = ADD32(ctx->r5, ctx->r15);
    // 0x800619D0: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800619D4: nop

    // 0x800619D8: add.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800619DC: lwc1        $f16, 0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800619E0: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x800619E4: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800619E8: nop

    // 0x800619EC: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800619F0: swc1        $f8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f8.u32l;
    // 0x800619F4: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800619F8: nop

    // 0x800619FC: add.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80061A00: swc1        $f6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f6.u32l;
L_80061A04:
    // 0x80061A04: slti        $at, $a3, 0x3
    ctx->r1 = SIGNED(ctx->r7) < 0X3 ? 1 : 0;
    // 0x80061A08: bne         $at, $zero, L_80061984
    if (ctx->r1 != 0) {
        // 0x80061A0C: addu        $t6, $a0, $a3
        ctx->r14 = ADD32(ctx->r4, ctx->r7);
            goto L_80061984;
    }
    // 0x80061A0C: addu        $t6, $a0, $a3
    ctx->r14 = ADD32(ctx->r4, ctx->r7);
    // 0x80061A10: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80061A14: lh          $v1, 0x10($t0)
    ctx->r3 = MEM_H(ctx->r8, 0X10);
    // 0x80061A18: sll         $t9, $s5, 16
    ctx->r25 = S32(ctx->r21 << 16);
    // 0x80061A1C: sra         $s5, $t9, 16
    ctx->r21 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80061A20: slt         $at, $s5, $v1
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80061A24: bne         $at, $zero, L_80061978
    if (ctx->r1 != 0) {
        // 0x80061A28: sll         $t7, $s5, 4
        ctx->r15 = S32(ctx->r21 << 4);
            goto L_80061978;
    }
    // 0x80061A28: sll         $t7, $s5, 4
    ctx->r15 = S32(ctx->r21 << 4);
    // 0x80061A2C: lw          $t6, 0xB8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB8);
    // 0x80061A30: nop

    // 0x80061A34: lh          $v1, 0x28($t6)
    ctx->r3 = MEM_H(ctx->r14, 0X28);
    // 0x80061A38: nop

    // 0x80061A3C: sll         $t8, $s1, 16
    ctx->r24 = S32(ctx->r17 << 16);
L_80061A40:
    // 0x80061A40: sra         $s1, $t8, 16
    ctx->r17 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80061A44: slt         $at, $s1, $v1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80061A48: bne         $at, $zero, L_80061918
    if (ctx->r1 != 0) {
        // 0x80061A4C: nop
    
            goto L_80061918;
    }
    // 0x80061A4C: nop

L_80061A50:
    // 0x80061A50: blez        $s6, L_80061AF0
    if (SIGNED(ctx->r22) <= 0) {
        // 0x80061A54: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_80061AF0;
    }
    // 0x80061A54: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_80061A58:
    // 0x80061A58: multu       $a3, $t5
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80061A5C: mflo        $t7
    ctx->r15 = lo;
    // 0x80061A60: addu        $s0, $s2, $t7
    ctx->r16 = ADD32(ctx->r18, ctx->r15);
    // 0x80061A64: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80061A68: lwc1        $f14, 0x4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80061A6C: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80061A70: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80061A74: sh          $a3, 0x98($sp)
    MEM_H(0X98, ctx->r29) = ctx->r7;
    // 0x80061A78: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80061A7C: nop

    // 0x80061A80: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80061A84: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80061A88: jal         0x800CA030
    // 0x80061A8C: add.s       $f12, $f16, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_11;
    // 0x80061A8C: add.s       $f12, $f16, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f8.fl;
    after_11:
    // 0x80061A90: c.eq.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl == ctx->f20.fl;
    // 0x80061A94: lh          $a3, 0x98($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X98);
    // 0x80061A98: bc1t        L_80061AD4
    if (c1cs) {
        // 0x80061A9C: addiu       $t5, $zero, 0xC
        ctx->r13 = ADD32(0, 0XC);
            goto L_80061AD4;
    }
    // 0x80061A9C: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x80061AA0: lui         $at, 0x3900
    ctx->r1 = S32(0X3900 << 16);
    // 0x80061AA4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80061AA8: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80061AAC: mul.s       $f2, $f0, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80061AB0: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80061AB4: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80061AB8: div.s       $f18, $f6, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80061ABC: nop

    // 0x80061AC0: div.s       $f16, $f4, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80061AC4: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
    // 0x80061AC8: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80061ACC: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
    // 0x80061AD0: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
L_80061AD4:
    // 0x80061AD4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80061AD8: sll         $t6, $a3, 16
    ctx->r14 = S32(ctx->r7 << 16);
    // 0x80061ADC: sra         $a3, $t6, 16
    ctx->r7 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80061AE0: slt         $at, $a3, $s6
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x80061AE4: bne         $at, $zero, L_80061A58
    if (ctx->r1 != 0) {
        // 0x80061AE8: nop
    
            goto L_80061A58;
    }
    // 0x80061AE8: nop

    // 0x80061AEC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_80061AF0:
    // 0x80061AF0: lw          $t2, 0xB8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB8);
    // 0x80061AF4: lw          $t1, 0xA0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA0);
    // 0x80061AF8: lh          $a1, 0x24($t2)
    ctx->r5 = MEM_H(ctx->r10, 0X24);
    // 0x80061AFC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80061B00: blez        $a1, L_80061BD4
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80061B04: addiu       $t0, $zero, 0x6
        ctx->r8 = ADD32(0, 0X6);
            goto L_80061BD4;
    }
    // 0x80061B04: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x80061B08: sll         $t9, $a3, 1
    ctx->r25 = S32(ctx->r7 << 1);
L_80061B0C:
    // 0x80061B0C: addu        $t7, $s7, $t9
    ctx->r15 = ADD32(ctx->r23, ctx->r25);
    // 0x80061B10: lh          $a2, 0x0($t7)
    ctx->r6 = MEM_H(ctx->r15, 0X0);
    // 0x80061B14: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80061B18: bltz        $a2, L_80061BC4
    if (SIGNED(ctx->r6) < 0) {
        // 0x80061B1C: sll         $t9, $a3, 16
        ctx->r25 = S32(ctx->r7 << 16);
            goto L_80061BC4;
    }
    // 0x80061B1C: sll         $t9, $a3, 16
    ctx->r25 = S32(ctx->r7 << 16);
    // 0x80061B20: multu       $a0, $t0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80061B24: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80061B28: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80061B2C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80061B30: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80061B34: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80061B38: mflo        $t6
    ctx->r14 = lo;
    // 0x80061B3C: addu        $v1, $t1, $t6
    ctx->r3 = ADD32(ctx->r9, ctx->r14);
    // 0x80061B40: nop

    // 0x80061B44: multu       $a2, $t5
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80061B48: mflo        $t8
    ctx->r24 = lo;
    // 0x80061B4C: addu        $v0, $s2, $t8
    ctx->r2 = ADD32(ctx->r18, ctx->r24);
    // 0x80061B50: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80061B54: nop

    // 0x80061B58: cvt.w.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80061B5C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80061B60: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x80061B64: nop

    // 0x80061B68: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80061B6C: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
    // 0x80061B70: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80061B74: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80061B78: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80061B7C: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80061B80: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80061B84: cvt.w.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80061B88: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80061B8C: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x80061B90: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80061B94: sh          $t8, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r24;
    // 0x80061B98: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80061B9C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80061BA0: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80061BA4: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80061BA8: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80061BAC: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x80061BB0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80061BB4: sh          $t7, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r15;
    // 0x80061BB8: lh          $a1, 0x24($t2)
    ctx->r5 = MEM_H(ctx->r10, 0X24);
    // 0x80061BBC: nop

    // 0x80061BC0: sll         $t9, $a3, 16
    ctx->r25 = S32(ctx->r7 << 16);
L_80061BC4:
    // 0x80061BC4: sra         $a3, $t9, 16
    ctx->r7 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80061BC8: slt         $at, $a3, $a1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80061BCC: bne         $at, $zero, L_80061B0C
    if (ctx->r1 != 0) {
        // 0x80061BD0: sll         $t9, $a3, 1
        ctx->r25 = S32(ctx->r7 << 1);
            goto L_80061B0C;
    }
    // 0x80061BD0: sll         $t9, $a3, 1
    ctx->r25 = S32(ctx->r7 << 1);
L_80061BD4:
    // 0x80061BD4: lw          $t1, 0xA0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA0);
    // 0x80061BD8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80061BDC: jal         0x80071380
    // 0x80061BE0: sw          $t1, 0x40($t2)
    MEM_W(0X40, ctx->r10) = ctx->r9;
    mempool_free(rdram, ctx);
        goto after_12;
    // 0x80061BE0: sw          $t1, 0x40($t2)
    MEM_W(0X40, ctx->r10) = ctx->r9;
    after_12:
    // 0x80061BE4: jal         0x80071380
    // 0x80061BE8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mempool_free(rdram, ctx);
        goto after_13;
    // 0x80061BE8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_13:
    // 0x80061BEC: lw          $a0, 0xAC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XAC);
    // 0x80061BF0: jal         0x80071380
    // 0x80061BF4: nop

    mempool_free(rdram, ctx);
        goto after_14;
    // 0x80061BF4: nop

    after_14:
L_80061BF8:
    // 0x80061BF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80061BFC:
    // 0x80061BFC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80061C00: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80061C04: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80061C08: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80061C0C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80061C10: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80061C14: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80061C18: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80061C1C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80061C20: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80061C24: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80061C28: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80061C2C: jr          $ra
    // 0x80061C30: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x80061C30: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void model_anim_offset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061C34: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80061C38: jr          $ra
    // 0x80061C3C: sw          $a0, -0x2440($at)
    MEM_W(-0X2440, ctx->r1) = ctx->r4;
    return;
    // 0x80061C3C: sw          $a0, -0x2440($at)
    MEM_W(-0X2440, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void model_anim_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061C40: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80061C44: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80061C48: lw          $t6, -0x2448($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2448);
    // 0x80061C4C: sll         $t7, $a1, 1
    ctx->r15 = S32(ctx->r5 << 1);
    // 0x80061C50: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80061C54: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80061C58: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80061C5C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80061C60: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80061C64: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80061C68: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80061C6C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80061C70: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80061C74: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80061C78: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80061C7C: lh          $s0, 0x0($v0)
    ctx->r16 = MEM_H(ctx->r2, 0X0);
    // 0x80061C80: lh          $v1, 0x2($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X2);
    // 0x80061C84: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80061C88: bne         $s0, $v1, L_80061C9C
    if (ctx->r16 != ctx->r3) {
        // 0x80061C8C: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_80061C9C;
    }
    // 0x80061C8C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80061C90: sh          $zero, 0x48($a0)
    MEM_H(0X48, ctx->r4) = 0;
    // 0x80061C94: b           L_80061E1C
    // 0x80061C98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80061E1C;
    // 0x80061C98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80061C9C:
    // 0x80061C9C: lw          $v0, -0x2440($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2440);
    // 0x80061CA0: lui         $a1, 0xFF00
    ctx->r5 = S32(0XFF00 << 16);
    // 0x80061CA4: beq         $v0, $zero, L_80061CC0
    if (ctx->r2 == 0) {
        // 0x80061CA8: ori         $a1, $a1, 0xFF
        ctx->r5 = ctx->r5 | 0XFF;
            goto L_80061CC0;
    }
    // 0x80061CA8: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x80061CAC: addu        $a0, $s0, $v0
    ctx->r4 = ADD32(ctx->r16, ctx->r2);
    // 0x80061CB0: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80061CB4: beq         $at, $zero, L_80061CC4
    if (ctx->r1 == 0) {
        // 0x80061CB8: subu        $t8, $v1, $s0
        ctx->r24 = SUB32(ctx->r3, ctx->r16);
            goto L_80061CC4;
    }
    // 0x80061CB8: subu        $t8, $v1, $s0
    ctx->r24 = SUB32(ctx->r3, ctx->r16);
    // 0x80061CBC: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_80061CC0:
    // 0x80061CC0: subu        $t8, $v1, $s0
    ctx->r24 = SUB32(ctx->r3, ctx->r16);
L_80061CC4:
    // 0x80061CC4: sh          $t8, 0x48($s5)
    MEM_H(0X48, ctx->r21) = ctx->r24;
    // 0x80061CC8: lh          $a0, 0x48($s5)
    ctx->r4 = MEM_H(ctx->r21, 0X48);
    // 0x80061CCC: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // 0x80061CD0: sll         $t9, $a0, 3
    ctx->r25 = S32(ctx->r4 << 3);
    // 0x80061CD4: jal         0x80070F50
    // 0x80061CD8: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    mempool_alloc(rdram, ctx);
        goto after_0;
    // 0x80061CD8: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_0:
    // 0x80061CDC: bne         $v0, $zero, L_80061CEC
    if (ctx->r2 != 0) {
        // 0x80061CE0: sw          $v0, 0x44($s5)
        MEM_W(0X44, ctx->r21) = ctx->r2;
            goto L_80061CEC;
    }
    // 0x80061CE0: sw          $v0, 0x44($s5)
    MEM_W(0X44, ctx->r21) = ctx->r2;
    // 0x80061CE4: b           L_80061E1C
    // 0x80061CE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80061E1C;
    // 0x80061CE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80061CEC:
    // 0x80061CEC: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x80061CF0: sll         $s4, $s0, 2
    ctx->r20 = S32(ctx->r16 << 2);
    // 0x80061CF4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80061CF8:
    // 0x80061CF8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80061CFC: lw          $t0, -0x2444($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2444);
    // 0x80061D00: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x80061D04: addu        $v0, $t0, $s4
    ctx->r2 = ADD32(ctx->r8, ctx->r20);
    // 0x80061D08: lw          $s2, 0x0($v0)
    ctx->r18 = MEM_W(ctx->r2, 0X0);
    // 0x80061D0C: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x80061D10: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80061D14: jal         0x800C673C
    // 0x80061D18: subu        $s3, $t1, $s2
    ctx->r19 = SUB32(ctx->r9, ctx->r18);
    gzip_size_uncompressed(rdram, ctx);
        goto after_1;
    // 0x80061D18: subu        $s3, $t1, $s2
    ctx->r19 = SUB32(ctx->r9, ctx->r18);
    after_1:
    // 0x80061D1C: addiu       $a0, $v0, 0x80
    ctx->r4 = ADD32(ctx->r2, 0X80);
    // 0x80061D20: lui         $a1, 0xFF00
    ctx->r5 = S32(0XFF00 << 16);
    // 0x80061D24: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x80061D28: jal         0x80070F50
    // 0x80061D2C: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    mempool_alloc(rdram, ctx);
        goto after_2;
    // 0x80061D2C: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    after_2:
    // 0x80061D30: lw          $t2, 0x44($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X44);
    // 0x80061D34: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80061D38: addu        $t3, $t2, $s1
    ctx->r11 = ADD32(ctx->r10, ctx->r17);
    // 0x80061D3C: sw          $v0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r2;
    // 0x80061D40: lw          $a0, 0x44($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X44);
    // 0x80061D44: lw          $s7, 0x40($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X40);
    // 0x80061D48: addu        $t4, $a0, $s1
    ctx->r12 = ADD32(ctx->r4, ctx->r17);
    // 0x80061D4C: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    // 0x80061D50: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x80061D54: bne         $v1, $zero, L_80061DA8
    if (ctx->r3 != 0) {
        // 0x80061D58: addu        $t7, $v1, $s6
        ctx->r15 = ADD32(ctx->r3, ctx->r22);
            goto L_80061DA8;
    }
    // 0x80061D58: addu        $t7, $v1, $s6
    ctx->r15 = ADD32(ctx->r3, ctx->r22);
    // 0x80061D5C: blez        $fp, L_80061D94
    if (SIGNED(ctx->r30) <= 0) {
        // 0x80061D60: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80061D94;
    }
    // 0x80061D60: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80061D64: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80061D68:
    // 0x80061D68: lw          $t5, 0x44($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X44);
    // 0x80061D6C: nop

    // 0x80061D70: addu        $t6, $t5, $s1
    ctx->r14 = ADD32(ctx->r13, ctx->r17);
    // 0x80061D74: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x80061D78: jal         0x80071380
    // 0x80061D7C: nop

    mempool_free(rdram, ctx);
        goto after_3;
    // 0x80061D7C: nop

    after_3:
    // 0x80061D80: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80061D84: bne         $s0, $fp, L_80061D68
    if (ctx->r16 != ctx->r30) {
        // 0x80061D88: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_80061D68;
    }
    // 0x80061D88: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x80061D8C: lw          $a0, 0x44($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X44);
    // 0x80061D90: nop

L_80061D94:
    // 0x80061D94: jal         0x80071380
    // 0x80061D98: nop

    mempool_free(rdram, ctx);
        goto after_4;
    // 0x80061D98: nop

    after_4:
    // 0x80061D9C: sw          $zero, 0x44($s5)
    MEM_W(0X44, ctx->r21) = 0;
    // 0x80061DA0: b           L_80061E1C
    // 0x80061DA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80061E1C;
    // 0x80061DA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80061DA8:
    // 0x80061DA8: subu        $s0, $t7, $s3
    ctx->r16 = SUB32(ctx->r15, ctx->r19);
    // 0x80061DAC: sll         $t8, $s7, 2
    ctx->r24 = S32(ctx->r23 << 2);
    // 0x80061DB0: or          $s7, $t8, $zero
    ctx->r23 = ctx->r24 | 0;
    // 0x80061DB4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80061DB8: jal         0x80077190
    // 0x80061DBC: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    asset_load(rdram, ctx);
        goto after_5;
    // 0x80061DBC: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_5:
    // 0x80061DC0: lw          $t9, 0x44($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X44);
    // 0x80061DC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80061DC8: addu        $t0, $t9, $s1
    ctx->r8 = ADD32(ctx->r25, ctx->r17);
    // 0x80061DCC: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x80061DD0: jal         0x800C6778
    // 0x80061DD4: nop

    gzip_inflate(rdram, ctx);
        goto after_6;
    // 0x80061DD4: nop

    after_6:
    // 0x80061DD8: lw          $t1, 0x44($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X44);
    // 0x80061DDC: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80061DE0: addu        $v1, $t1, $s1
    ctx->r3 = ADD32(ctx->r9, ctx->r17);
    // 0x80061DE4: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80061DE8: slt         $at, $s4, $s7
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r23) ? 1 : 0;
    // 0x80061DEC: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x80061DF0: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x80061DF4: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x80061DF8: lw          $t3, 0x44($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X44);
    // 0x80061DFC: nop

    // 0x80061E00: addu        $v1, $t3, $s1
    ctx->r3 = ADD32(ctx->r11, ctx->r17);
    // 0x80061E04: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x80061E08: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x80061E0C: addiu       $t5, $t4, 0x4
    ctx->r13 = ADD32(ctx->r12, 0X4);
    // 0x80061E10: bne         $at, $zero, L_80061CF8
    if (ctx->r1 != 0) {
        // 0x80061E14: sw          $t5, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r13;
            goto L_80061CF8;
    }
    // 0x80061E14: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80061E18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80061E1C:
    // 0x80061E1C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80061E20: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80061E24: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80061E28: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80061E2C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80061E30: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80061E34: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80061E38: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80061E3C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80061E40: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80061E44: jr          $ra
    // 0x80061E48: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80061E48: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80061C0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061E4C: lb          $v0, 0x3A($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X3A);
    // 0x80061E50: nop

    // 0x80061E54: bgez        $v0, L_80061E68
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80061E58: nop
    
            goto L_80061E68;
    }
    // 0x80061E58: nop

    // 0x80061E5C: sb          $zero, 0x3A($a0)
    MEM_B(0X3A, ctx->r4) = 0;
    // 0x80061E60: lb          $v0, 0x3A($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X3A);
    // 0x80061E64: nop

L_80061E68:
    // 0x80061E68: lw          $t6, 0x40($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X40);
    // 0x80061E6C: nop

    // 0x80061E70: lb          $v1, 0x55($t6)
    ctx->r3 = MEM_B(ctx->r14, 0X55);
    // 0x80061E74: nop

    // 0x80061E78: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80061E7C: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80061E80: beq         $at, $zero, L_80061E94
    if (ctx->r1 == 0) {
        // 0x80061E84: nop
    
            goto L_80061E94;
    }
    // 0x80061E84: nop

    // 0x80061E88: sb          $v1, 0x3A($a0)
    MEM_B(0X3A, ctx->r4) = ctx->r3;
    // 0x80061E8C: lb          $v0, 0x3A($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X3A);
    // 0x80061E90: nop

L_80061E94:
    // 0x80061E94: lw          $t7, 0x68($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X68);
    // 0x80061E98: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80061E9C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80061EA0: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    // 0x80061EA4: nop

    // 0x80061EA8: lw          $a2, 0x0($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X0);
    // 0x80061EAC: nop

    // 0x80061EB0: lw          $t0, 0x44($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X44);
    // 0x80061EB4: nop

    // 0x80061EB8: beq         $t0, $zero, L_80061F60
    if (ctx->r8 == 0) {
        // 0x80061EBC: nop
    
            goto L_80061F60;
    }
    // 0x80061EBC: nop

    // 0x80061EC0: lb          $v0, 0x3B($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X3B);
    // 0x80061EC4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80061EC8: bgez        $v0, L_80061EDC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80061ECC: nop
    
            goto L_80061EDC;
    }
    // 0x80061ECC: nop

    // 0x80061ED0: sb          $zero, 0x3B($a0)
    MEM_B(0X3B, ctx->r4) = 0;
    // 0x80061ED4: lb          $v0, 0x3B($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X3B);
    // 0x80061ED8: nop

L_80061EDC:
    // 0x80061EDC: lh          $v1, 0x48($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X48);
    // 0x80061EE0: nop

    // 0x80061EE4: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80061EE8: bne         $at, $zero, L_80061EFC
    if (ctx->r1 != 0) {
        // 0x80061EEC: addiu       $t1, $v1, -0x1
        ctx->r9 = ADD32(ctx->r3, -0X1);
            goto L_80061EFC;
    }
    // 0x80061EEC: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
    // 0x80061EF0: sb          $t1, 0x3B($a0)
    MEM_B(0X3B, ctx->r4) = ctx->r9;
    // 0x80061EF4: lh          $v1, 0x48($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X48);
    // 0x80061EF8: nop

L_80061EFC:
    // 0x80061EFC: blez        $v1, L_80061F24
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80061F00: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80061F24;
    }
    // 0x80061F00: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80061F04: lb          $t3, 0x3B($a0)
    ctx->r11 = MEM_B(ctx->r4, 0X3B);
    // 0x80061F08: lw          $t2, 0x44($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X44);
    // 0x80061F0C: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x80061F10: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80061F14: lw          $v1, 0x4($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X4);
    // 0x80061F18: b           L_80061F24
    // 0x80061F1C: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
        goto L_80061F24;
    // 0x80061F1C: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
    // 0x80061F20: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80061F24:
    // 0x80061F24: lh          $v0, 0x18($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X18);
    // 0x80061F28: nop

    // 0x80061F2C: sra         $t6, $v0, 4
    ctx->r14 = S32(SIGNED(ctx->r2) >> 4);
    // 0x80061F30: bgez        $t6, L_80061F4C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80061F34: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80061F4C;
    }
    // 0x80061F34: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80061F38: sh          $v1, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r3;
    // 0x80061F3C: lh          $v0, 0x18($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X18);
    // 0x80061F40: nop

    // 0x80061F44: sra         $t7, $v0, 4
    ctx->r15 = S32(SIGNED(ctx->r2) >> 4);
    // 0x80061F48: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80061F4C:
    // 0x80061F4C: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80061F50: beq         $at, $zero, L_80061F60
    if (ctx->r1 == 0) {
        // 0x80061F54: nop
    
            goto L_80061F60;
    }
    // 0x80061F54: nop

    // 0x80061F58: sh          $zero, 0x18($a0)
    MEM_H(0X18, ctx->r4) = 0;
    // 0x80061F5C: sh          $t8, 0x10($a1)
    MEM_H(0X10, ctx->r5) = ctx->r24;
L_80061F60:
    // 0x80061F60: jr          $ra
    // 0x80061F64: nop

    return;
    // 0x80061F64: nop

    // 0x80061F68: nop

    // 0x80061F6C: nop

;}
RECOMP_FUNC void obj_animate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061F70: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80061F74: sw          $s1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r17;
    // 0x80061F78: sw          $s0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r16;
    // 0x80061F7C: lb          $t0, 0x3A($a0)
    ctx->r8 = MEM_B(ctx->r4, 0X3A);
    // 0x80061F80: bgezl       $t0, L_80061F90
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80061F84: lw          $t1, 0x40($a0)
        ctx->r9 = MEM_W(ctx->r4, 0X40);
            goto L_80061F90;
    }
    goto skip_0;
    // 0x80061F84: lw          $t1, 0x40($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X40);
    skip_0:
    // 0x80061F88: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80061F8C: lw          $t1, 0x40($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X40);
L_80061F90:
    // 0x80061F90: lb          $t2, 0x55($t1)
    ctx->r10 = MEM_B(ctx->r9, 0X55);
    // 0x80061F94: slt         $at, $t0, $t2
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80061F98: bnel        $at, $zero, L_80061FA8
    if (ctx->r1 != 0) {
        // 0x80061F9C: lw          $t1, 0x68($a0)
        ctx->r9 = MEM_W(ctx->r4, 0X68);
            goto L_80061FA8;
    }
    goto skip_1;
    // 0x80061F9C: lw          $t1, 0x68($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X68);
    skip_1:
    // 0x80061FA0: or          $t0, $t2, $zero
    ctx->r8 = ctx->r10 | 0;
    // 0x80061FA4: lw          $t1, 0x68($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X68);
L_80061FA8:
    // 0x80061FA8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80061FAC: add         $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80061FB0: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x80061FB4: lw          $a2, 0x0($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X0);
    // 0x80061FB8: lw          $t0, 0x44($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X44);
    // 0x80061FBC: bnel        $t0, $zero, L_80061FD0
    if (ctx->r8 != 0) {
        // 0x80061FC0: lh          $t9, 0x18($a0)
        ctx->r25 = MEM_H(ctx->r4, 0X18);
            goto L_80061FD0;
    }
    goto skip_2;
    // 0x80061FC0: lh          $t9, 0x18($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X18);
    skip_2:
    // 0x80061FC4: b           L_800624BC
    // 0x80061FC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800624BC;
    // 0x80061FC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80061FCC: lh          $t9, 0x18($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X18);
L_80061FD0:
    // 0x80061FD0: lh          $t0, 0x14($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X14);
    // 0x80061FD4: lb          $a3, 0x3B($a0)
    ctx->r7 = MEM_B(ctx->r4, 0X3B);
    // 0x80061FD8: bne         $t9, $t0, L_80061FF4
    if (ctx->r25 != ctx->r8) {
        // 0x80061FDC: nop
    
            goto L_80061FF4;
    }
    // 0x80061FDC: nop

    // 0x80061FE0: lh          $t0, 0x10($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X10);
    // 0x80061FE4: bne         $a3, $t0, L_80061FF4
    if (ctx->r7 != ctx->r8) {
        // 0x80061FE8: nop
    
            goto L_80061FF4;
    }
    // 0x80061FE8: nop

    // 0x80061FEC: b           L_800624BC
    // 0x80061FF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800624BC;
    // 0x80061FF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80061FF4:
    // 0x80061FF4: bgezl       $a3, L_80062004
    if (SIGNED(ctx->r7) >= 0) {
        // 0x80061FF8: lh          $t0, 0x48($a2)
        ctx->r8 = MEM_H(ctx->r6, 0X48);
            goto L_80062004;
    }
    goto skip_3;
    // 0x80061FF8: lh          $t0, 0x48($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X48);
    skip_3:
    // 0x80061FFC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80062000: lh          $t0, 0x48($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X48);
L_80062004:
    // 0x80062004: slt         $at, $a3, $t0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80062008: bne         $at, $zero, L_80062014
    if (ctx->r1 != 0) {
        // 0x8006200C: nop
    
            goto L_80062014;
    }
    // 0x8006200C: nop

    // 0x80062010: addiu       $a3, $t0, -0x1
    ctx->r7 = ADD32(ctx->r8, -0X1);
L_80062014:
    // 0x80062014: blez        $t0, L_80062030
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80062018: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_80062030;
    }
    // 0x80062018: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8006201C: lw          $t1, 0x44($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X44);
    // 0x80062020: sll         $v0, $a3, 3
    ctx->r2 = S32(ctx->r7 << 3);
    // 0x80062024: add         $t1, $t1, $v0
    ctx->r9 = ADD32(ctx->r9, ctx->r2);
    // 0x80062028: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8006202C: addi        $t2, $t2, -0x2
    ctx->r10 = ADD32(ctx->r10, -0X2);
L_80062030:
    // 0x80062030: srl         $a0, $t9, 4
    ctx->r4 = S32(U32(ctx->r25) >> 4);
    // 0x80062034: bgezl       $a0, L_80062048
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80062038: slt         $at, $t2, $a0
        ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_80062048;
    }
    goto skip_4;
    // 0x80062038: slt         $at, $t2, $a0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r4) ? 1 : 0;
    skip_4:
    // 0x8006203C: or          $t9, $t2, $zero
    ctx->r25 = ctx->r10 | 0;
    // 0x80062040: srl         $a0, $t2, 4
    ctx->r4 = S32(U32(ctx->r10) >> 4);
    // 0x80062044: slt         $at, $t2, $a0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r4) ? 1 : 0;
L_80062048:
    // 0x80062048: beql        $at, $zero, L_80062064
    if (ctx->r1 == 0) {
        // 0x8006204C: lh          $t0, 0x10($a1)
        ctx->r8 = MEM_H(ctx->r5, 0X10);
            goto L_80062064;
    }
    goto skip_5;
    // 0x8006204C: lh          $t0, 0x10($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X10);
    skip_5:
    // 0x80062050: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80062054: or          $t9, $zero, $zero
    ctx->r25 = 0 | 0;
    // 0x80062058: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8006205C: sh          $t0, 0x10($a1)
    MEM_H(0X10, ctx->r5) = ctx->r8;
    // 0x80062060: lh          $t0, 0x10($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X10);
L_80062064:
    // 0x80062064: lw          $s1, 0xC($a1)
    ctx->r17 = MEM_W(ctx->r5, 0XC);
    // 0x80062068: beql        $a3, $t0, L_8006207C
    if (ctx->r7 == ctx->r8) {
        // 0x8006206C: lh          $s0, 0x12($a1)
        ctx->r16 = MEM_H(ctx->r5, 0X12);
            goto L_8006207C;
    }
    goto skip_6;
    // 0x8006206C: lh          $s0, 0x12($a1)
    ctx->r16 = MEM_H(ctx->r5, 0X12);
    skip_6:
    // 0x80062070: b           L_8006207C
    // 0x80062074: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
        goto L_8006207C;
    // 0x80062074: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x80062078: lh          $s0, 0x12($a1)
    ctx->r16 = MEM_H(ctx->r5, 0X12);
L_8006207C:
    // 0x8006207C: sh          $a3, 0x10($a1)
    MEM_H(0X10, ctx->r5) = ctx->r7;
    // 0x80062080: sh          $t9, 0x14($a1)
    MEM_H(0X14, ctx->r5) = ctx->r25;
    // 0x80062084: sh          $a0, 0x12($a1)
    MEM_H(0X12, ctx->r5) = ctx->r4;
    // 0x80062088: beq         $a0, $zero, L_800620A4
    if (ctx->r4 == 0) {
        // 0x8006208C: andi        $t8, $t9, 0xF
        ctx->r24 = ctx->r25 & 0XF;
            goto L_800620A4;
    }
    // 0x8006208C: andi        $t8, $t9, 0xF
    ctx->r24 = ctx->r25 & 0XF;
    // 0x80062090: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80062094: beql        $s0, $at, L_800620A8
    if (ctx->r16 == ctx->r1) {
        // 0x80062098: lw          $v0, 0x44($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X44);
            goto L_800620A8;
    }
    goto skip_7;
    // 0x80062098: lw          $v0, 0x44($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X44);
    skip_7:
    // 0x8006209C: b           L_80062138
    // 0x800620A0: lh          $v1, 0x4A($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X4A);
        goto L_80062138;
    // 0x800620A0: lh          $v1, 0x4A($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X4A);
L_800620A4:
    // 0x800620A4: lw          $v0, 0x44($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X44);
L_800620A8:
    // 0x800620A8: sll         $v1, $a3, 3
    ctx->r3 = S32(ctx->r7 << 3);
    // 0x800620AC: lw          $t5, 0x4C($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X4C);
    // 0x800620B0: add         $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800620B4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800620B8: lh          $v0, 0x24($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X24);
    // 0x800620BC: lw          $t7, 0x4($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X4);
    // 0x800620C0: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x800620C4: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800620C8: add         $t3, $t5, $v0
    ctx->r11 = ADD32(ctx->r13, ctx->r2);
L_800620CC:
    // 0x800620CC: lh          $v0, 0x0($t5)
    ctx->r2 = MEM_H(ctx->r13, 0X0);
    // 0x800620D0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800620D4: beql        $v0, $at, L_80062124
    if (ctx->r2 == ctx->r1) {
        // 0x800620D8: addiu       $t5, $t5, 0x2
        ctx->r13 = ADD32(ctx->r13, 0X2);
            goto L_80062124;
    }
    goto skip_8;
    // 0x800620D8: addiu       $t5, $t5, 0x2
    ctx->r13 = ADD32(ctx->r13, 0X2);
    skip_8:
    // 0x800620DC: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800620E0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800620E4: add         $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800620E8: add         $v1, $s1, $v0
    ctx->r3 = ADD32(ctx->r17, ctx->r2);
    // 0x800620EC: add         $v0, $t6, $v0
    ctx->r2 = ADD32(ctx->r14, ctx->r2);
    // 0x800620F0: lh          $t0, 0x0($t7)
    ctx->r8 = MEM_H(ctx->r15, 0X0);
    // 0x800620F4: lh          $t1, 0x0($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X0);
    // 0x800620F8: add         $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800620FC: sh          $t2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r10;
    // 0x80062100: lh          $t0, 0x2($t7)
    ctx->r8 = MEM_H(ctx->r15, 0X2);
    // 0x80062104: lh          $t1, 0x2($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X2);
    // 0x80062108: add         $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8006210C: sh          $t2, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r10;
    // 0x80062110: lh          $t0, 0x4($t7)
    ctx->r8 = MEM_H(ctx->r15, 0X4);
    // 0x80062114: lh          $t1, 0x4($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X4);
    // 0x80062118: add         $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8006211C: sh          $t2, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r10;
    // 0x80062120: addiu       $t5, $t5, 0x2
    ctx->r13 = ADD32(ctx->r13, 0X2);
L_80062124:
    // 0x80062124: slt         $at, $t5, $t3
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80062128: bne         $at, $zero, L_800620CC
    if (ctx->r1 != 0) {
        // 0x8006212C: addiu       $t7, $t7, 0xA
        ctx->r15 = ADD32(ctx->r15, 0XA);
            goto L_800620CC;
    }
    // 0x8006212C: addiu       $t7, $t7, 0xA
    ctx->r15 = ADD32(ctx->r15, 0XA);
    // 0x80062130: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80062134: lh          $v1, 0x4A($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X4A);
L_80062138:
    // 0x80062138: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8006213C: add         $v0, $v1, $v1
    ctx->r2 = ADD32(ctx->r3, ctx->r3);
    // 0x80062140: add         $t4, $v0, $v1
    ctx->r12 = ADD32(ctx->r2, ctx->r3);
    // 0x80062144: beq         $at, $zero, L_800621E0
    if (ctx->r1 == 0) {
        // 0x80062148: addiu       $t4, $t4, 0xC
        ctx->r12 = ADD32(ctx->r12, 0XC);
            goto L_800621E0;
    }
    // 0x80062148: addiu       $t4, $t4, 0xC
    ctx->r12 = ADD32(ctx->r12, 0XC);
    // 0x8006214C: lw          $v0, 0x44($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X44);
    // 0x80062150: sll         $v1, $a3, 3
    ctx->r3 = S32(ctx->r7 << 3);
    // 0x80062154: add         $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80062158: addiu       $v1, $s0, 0x2
    ctx->r3 = ADD32(ctx->r16, 0X2);
    // 0x8006215C: multu       $t4, $v1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80062160: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80062164: mflo        $v1
    ctx->r3 = lo;
    // 0x80062168: add         $t2, $t2, $v1
    ctx->r10 = ADD32(ctx->r10, ctx->r3);
    // 0x8006216C: nop

    // 0x80062170: lh          $v0, 0x4A($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X4A);
L_80062174:
    // 0x80062174: or          $t6, $t2, $zero
    ctx->r14 = ctx->r10 | 0;
    // 0x80062178: or          $t5, $s1, $zero
    ctx->r13 = ctx->r17 | 0;
    // 0x8006217C: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80062180: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80062184: add         $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80062188: add         $t2, $t2, $t4
    ctx->r10 = ADD32(ctx->r10, ctx->r12);
    // 0x8006218C: add         $t3, $t5, $v0
    ctx->r11 = ADD32(ctx->r13, ctx->r2);
L_80062190:
    // 0x80062190: lh          $t0, 0x0($t5)
    ctx->r8 = MEM_H(ctx->r13, 0X0);
    // 0x80062194: lb          $t1, 0x0($t6)
    ctx->r9 = MEM_B(ctx->r14, 0X0);
    // 0x80062198: addiu       $t5, $t5, 0x6
    ctx->r13 = ADD32(ctx->r13, 0X6);
    // 0x8006219C: slt         $at, $t5, $t3
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800621A0: add         $t0, $t0, $t1
    ctx->r8 = ADD32(ctx->r8, ctx->r9);
    // 0x800621A4: sh          $t0, -0x6($t5)
    MEM_H(-0X6, ctx->r13) = ctx->r8;
    // 0x800621A8: lh          $t0, -0x4($t5)
    ctx->r8 = MEM_H(ctx->r13, -0X4);
    // 0x800621AC: lb          $t1, 0x1($t6)
    ctx->r9 = MEM_B(ctx->r14, 0X1);
    // 0x800621B0: addiu       $t6, $t6, 0x3
    ctx->r14 = ADD32(ctx->r14, 0X3);
    // 0x800621B4: add         $t0, $t0, $t1
    ctx->r8 = ADD32(ctx->r8, ctx->r9);
    // 0x800621B8: sh          $t0, -0x4($t5)
    MEM_H(-0X4, ctx->r13) = ctx->r8;
    // 0x800621BC: lh          $t0, -0x2($t5)
    ctx->r8 = MEM_H(ctx->r13, -0X2);
    // 0x800621C0: lb          $t1, -0x1($t6)
    ctx->r9 = MEM_B(ctx->r14, -0X1);
    // 0x800621C4: add         $t0, $t0, $t1
    ctx->r8 = ADD32(ctx->r8, ctx->r9);
    // 0x800621C8: bne         $at, $zero, L_80062190
    if (ctx->r1 != 0) {
        // 0x800621CC: sh          $t0, -0x2($t5)
        MEM_H(-0X2, ctx->r13) = ctx->r8;
            goto L_80062190;
    }
    // 0x800621CC: sh          $t0, -0x2($t5)
    MEM_H(-0X2, ctx->r13) = ctx->r8;
    // 0x800621D0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800621D4: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800621D8: bnel        $at, $zero, L_80062174
    if (ctx->r1 != 0) {
        // 0x800621DC: lh          $v0, 0x4A($a2)
        ctx->r2 = MEM_H(ctx->r6, 0X4A);
            goto L_80062174;
    }
    goto skip_9;
    // 0x800621DC: lh          $v0, 0x4A($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X4A);
    skip_9:
L_800621E0:
    // 0x800621E0: slt         $at, $a0, $s0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800621E4: beql        $at, $zero, L_80062284
    if (ctx->r1 == 0) {
        // 0x800621E8: lw          $v0, 0x44($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X44);
            goto L_80062284;
    }
    goto skip_10;
    // 0x800621E8: lw          $v0, 0x44($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X44);
    skip_10:
    // 0x800621EC: lw          $v0, 0x44($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X44);
    // 0x800621F0: sll         $v1, $a3, 3
    ctx->r3 = S32(ctx->r7 << 3);
    // 0x800621F4: add         $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800621F8: addiu       $v1, $s0, 0x2
    ctx->r3 = ADD32(ctx->r16, 0X2);
    // 0x800621FC: multu       $t4, $v1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80062200: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80062204: mflo        $v1
    ctx->r3 = lo;
    // 0x80062208: add         $t2, $t2, $v1
    ctx->r10 = ADD32(ctx->r10, ctx->r3);
    // 0x8006220C: nop

    // 0x80062210: lh          $v0, 0x4A($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X4A);
L_80062214:
    // 0x80062214: sub         $t2, $t2, $t4
    ctx->r10 = SUB32(ctx->r10, ctx->r12);
    // 0x80062218: or          $t5, $s1, $zero
    ctx->r13 = ctx->r17 | 0;
    // 0x8006221C: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80062220: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80062224: add         $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80062228: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x8006222C: or          $t6, $t2, $zero
    ctx->r14 = ctx->r10 | 0;
    // 0x80062230: add         $t3, $t5, $v0
    ctx->r11 = ADD32(ctx->r13, ctx->r2);
L_80062234:
    // 0x80062234: lh          $t0, 0x0($t5)
    ctx->r8 = MEM_H(ctx->r13, 0X0);
    // 0x80062238: lb          $t1, 0x0($t6)
    ctx->r9 = MEM_B(ctx->r14, 0X0);
    // 0x8006223C: addiu       $t5, $t5, 0x6
    ctx->r13 = ADD32(ctx->r13, 0X6);
    // 0x80062240: slt         $at, $t5, $t3
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80062244: sub         $t0, $t0, $t1
    ctx->r8 = SUB32(ctx->r8, ctx->r9);
    // 0x80062248: sh          $t0, -0x6($t5)
    MEM_H(-0X6, ctx->r13) = ctx->r8;
    // 0x8006224C: lh          $t0, -0x4($t5)
    ctx->r8 = MEM_H(ctx->r13, -0X4);
    // 0x80062250: lb          $t1, 0x1($t6)
    ctx->r9 = MEM_B(ctx->r14, 0X1);
    // 0x80062254: addiu       $t6, $t6, 0x3
    ctx->r14 = ADD32(ctx->r14, 0X3);
    // 0x80062258: sub         $t0, $t0, $t1
    ctx->r8 = SUB32(ctx->r8, ctx->r9);
    // 0x8006225C: sh          $t0, -0x4($t5)
    MEM_H(-0X4, ctx->r13) = ctx->r8;
    // 0x80062260: lh          $t0, -0x2($t5)
    ctx->r8 = MEM_H(ctx->r13, -0X2);
    // 0x80062264: lb          $t1, -0x1($t6)
    ctx->r9 = MEM_B(ctx->r14, -0X1);
    // 0x80062268: sub         $t0, $t0, $t1
    ctx->r8 = SUB32(ctx->r8, ctx->r9);
    // 0x8006226C: bne         $at, $zero, L_80062234
    if (ctx->r1 != 0) {
        // 0x80062270: sh          $t0, -0x2($t5)
        MEM_H(-0X2, ctx->r13) = ctx->r8;
            goto L_80062234;
    }
    // 0x80062270: sh          $t0, -0x2($t5)
    MEM_H(-0X2, ctx->r13) = ctx->r8;
    // 0x80062274: slt         $at, $a0, $s0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80062278: bnel        $at, $zero, L_80062214
    if (ctx->r1 != 0) {
        // 0x8006227C: lh          $v0, 0x4A($a2)
        ctx->r2 = MEM_H(ctx->r6, 0X4A);
            goto L_80062214;
    }
    goto skip_11;
    // 0x8006227C: lh          $v0, 0x4A($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X4A);
    skip_11:
    // 0x80062280: lw          $v0, 0x44($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X44);
L_80062284:
    // 0x80062284: sll         $v1, $a3, 3
    ctx->r3 = S32(ctx->r7 << 3);
    // 0x80062288: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8006228C: add         $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80062290: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80062294: addiu       $v0, $s0, 0x2
    ctx->r2 = ADD32(ctx->r16, 0X2);
    // 0x80062298: multu       $t4, $v0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006229C: lh          $v0, 0x4A($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X4A);
    // 0x800622A0: lw          $t5, -0x243C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X243C);
    // 0x800622A4: mflo        $v1
    ctx->r3 = lo;
    // 0x800622A8: add         $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x800622AC: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800622B0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800622B4: add         $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800622B8: add         $t3, $t5, $v0
    ctx->r11 = ADD32(ctx->r13, ctx->r2);
L_800622BC:
    // 0x800622BC: lb          $t0, 0x0($t6)
    ctx->r8 = MEM_B(ctx->r14, 0X0);
    // 0x800622C0: addiu       $t5, $t5, 0x6
    ctx->r13 = ADD32(ctx->r13, 0X6);
    // 0x800622C4: slt         $at, $t5, $t3
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800622C8: multu       $t0, $t8
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800622CC: addiu       $t6, $t6, 0x3
    ctx->r14 = ADD32(ctx->r14, 0X3);
    // 0x800622D0: mflo        $t0
    ctx->r8 = lo;
    // 0x800622D4: srl         $t0, $t0, 4
    ctx->r8 = S32(U32(ctx->r8) >> 4);
    // 0x800622D8: sh          $t0, -0x6($t5)
    MEM_H(-0X6, ctx->r13) = ctx->r8;
    // 0x800622DC: lb          $t1, -0x2($t6)
    ctx->r9 = MEM_B(ctx->r14, -0X2);
    // 0x800622E0: multu       $t1, $t8
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800622E4: mflo        $t1
    ctx->r9 = lo;
    // 0x800622E8: srl         $t1, $t1, 4
    ctx->r9 = S32(U32(ctx->r9) >> 4);
    // 0x800622EC: sh          $t1, -0x4($t5)
    MEM_H(-0X4, ctx->r13) = ctx->r9;
    // 0x800622F0: lb          $t2, -0x1($t6)
    ctx->r10 = MEM_B(ctx->r14, -0X1);
    // 0x800622F4: multu       $t2, $t8
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800622F8: mflo        $t2
    ctx->r10 = lo;
    // 0x800622FC: srl         $t2, $t2, 4
    ctx->r10 = S32(U32(ctx->r10) >> 4);
    // 0x80062300: bne         $at, $zero, L_800622BC
    if (ctx->r1 != 0) {
        // 0x80062304: sh          $t2, -0x2($t5)
        MEM_H(-0X2, ctx->r13) = ctx->r10;
            goto L_800622BC;
    }
    // 0x80062304: sh          $t2, -0x2($t5)
    MEM_H(-0X2, ctx->r13) = ctx->r10;
    // 0x80062308: lw          $v0, 0x44($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X44);
    // 0x8006230C: sll         $v1, $a3, 3
    ctx->r3 = S32(ctx->r7 << 3);
    // 0x80062310: add         $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80062314: beq         $a0, $zero, L_80062330
    if (ctx->r4 == 0) {
        // 0x80062318: lw          $t6, 0x0($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X0);
            goto L_80062330;
    }
    // 0x80062318: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8006231C: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80062320: multu       $t4, $v0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80062324: mflo        $v1
    ctx->r3 = lo;
    // 0x80062328: add         $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x8006232C: addiu       $t6, $t6, -0xC
    ctx->r14 = ADD32(ctx->r14, -0XC);
L_80062330:
    // 0x80062330: lb          $v0, 0x0($t6)
    ctx->r2 = MEM_B(ctx->r14, 0X0);
    // 0x80062334: lbu         $v1, 0x1($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0X1);
    // 0x80062338: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x8006233C: or          $t0, $v0, $v1
    ctx->r8 = ctx->r2 | ctx->r3;
    // 0x80062340: lb          $v0, 0x2($t6)
    ctx->r2 = MEM_B(ctx->r14, 0X2);
    // 0x80062344: lbu         $v1, 0x3($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0X3);
    // 0x80062348: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x8006234C: or          $t1, $v0, $v1
    ctx->r9 = ctx->r2 | ctx->r3;
    // 0x80062350: lb          $v0, 0x4($t6)
    ctx->r2 = MEM_B(ctx->r14, 0X4);
    // 0x80062354: lbu         $v1, 0x5($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0X5);
    // 0x80062358: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x8006235C: or          $t2, $v0, $v1
    ctx->r10 = ctx->r2 | ctx->r3;
    // 0x80062360: lb          $v0, 0xA($t6)
    ctx->r2 = MEM_B(ctx->r14, 0XA);
    // 0x80062364: lbu         $v1, 0xB($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0XB);
    // 0x80062368: add         $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x8006236C: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x80062370: bne         $a0, $zero, L_80062380
    if (ctx->r4 != 0) {
        // 0x80062374: or          $t3, $v0, $v1
        ctx->r11 = ctx->r2 | ctx->r3;
            goto L_80062380;
    }
    // 0x80062374: or          $t3, $v0, $v1
    ctx->r11 = ctx->r2 | ctx->r3;
    // 0x80062378: add         $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x8006237C: addiu       $t6, $t6, -0xC
    ctx->r14 = ADD32(ctx->r14, -0XC);
L_80062380:
    // 0x80062380: lb          $v0, 0x0($t6)
    ctx->r2 = MEM_B(ctx->r14, 0X0);
    // 0x80062384: lbu         $v1, 0x1($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0X1);
    // 0x80062388: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8006238C: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x80062390: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80062394: sub         $v0, $v0, $t0
    ctx->r2 = SUB32(ctx->r2, ctx->r8);
    // 0x80062398: multu       $v0, $t8
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006239C: mflo        $v0
    ctx->r2 = lo;
    // 0x800623A0: srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
    // 0x800623A4: add         $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
    // 0x800623A8: sh          $t0, 0x16($a1)
    MEM_H(0X16, ctx->r5) = ctx->r8;
    // 0x800623AC: lb          $v0, 0x2($t6)
    ctx->r2 = MEM_B(ctx->r14, 0X2);
    // 0x800623B0: lbu         $v1, 0x3($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0X3);
    // 0x800623B4: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x800623B8: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800623BC: sub         $v0, $v0, $t1
    ctx->r2 = SUB32(ctx->r2, ctx->r9);
    // 0x800623C0: multu       $v0, $t8
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800623C4: mflo        $v0
    ctx->r2 = lo;
    // 0x800623C8: srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
    // 0x800623CC: add         $t1, $t1, $v0
    ctx->r9 = ADD32(ctx->r9, ctx->r2);
    // 0x800623D0: sh          $t1, 0x18($a1)
    MEM_H(0X18, ctx->r5) = ctx->r9;
    // 0x800623D4: lb          $v0, 0x4($t6)
    ctx->r2 = MEM_B(ctx->r14, 0X4);
    // 0x800623D8: lbu         $v1, 0x5($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0X5);
    // 0x800623DC: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x800623E0: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800623E4: sub         $v0, $v0, $t2
    ctx->r2 = SUB32(ctx->r2, ctx->r10);
    // 0x800623E8: multu       $v0, $t8
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800623EC: mflo        $v0
    ctx->r2 = lo;
    // 0x800623F0: srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
    // 0x800623F4: add         $t2, $t2, $v0
    ctx->r10 = ADD32(ctx->r10, ctx->r2);
    // 0x800623F8: sh          $t2, 0x1A($a1)
    MEM_H(0X1A, ctx->r5) = ctx->r10;
    // 0x800623FC: lb          $v0, 0xA($t6)
    ctx->r2 = MEM_B(ctx->r14, 0XA);
    // 0x80062400: lbu         $v1, 0xB($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0XB);
    // 0x80062404: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x80062408: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8006240C: sub         $v0, $v0, $t3
    ctx->r2 = SUB32(ctx->r2, ctx->r11);
    // 0x80062410: multu       $v0, $t8
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80062414: addiu       $v1, $a1, 0x4
    ctx->r3 = ADD32(ctx->r5, 0X4);
    // 0x80062418: mflo        $v0
    ctx->r2 = lo;
    // 0x8006241C: srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
    // 0x80062420: add         $t3, $t3, $v0
    ctx->r11 = ADD32(ctx->r11, ctx->r2);
    // 0x80062424: lb          $v0, 0x1F($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X1F);
    // 0x80062428: sh          $t3, 0x1C($a1)
    MEM_H(0X1C, ctx->r5) = ctx->r11;
    // 0x8006242C: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80062430: sb          $v0, 0x1F($a1)
    MEM_B(0X1F, ctx->r5) = ctx->r2;
    // 0x80062434: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80062438: add         $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8006243C: lh          $v0, 0x24($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X24);
    // 0x80062440: lw          $t5, 0x4C($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X4C);
    // 0x80062444: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80062448: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8006244C: lw          $t9, -0x243C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X243C);
    // 0x80062450: add         $t3, $t5, $v0
    ctx->r11 = ADD32(ctx->r13, ctx->r2);
L_80062454:
    // 0x80062454: lh          $v0, 0x0($t5)
    ctx->r2 = MEM_H(ctx->r13, 0X0);
    // 0x80062458: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006245C: addi        $t5, $t5, 0x2
    ctx->r13 = ADD32(ctx->r13, 0X2);
    // 0x80062460: beql        $v0, $at, L_800624B0
    if (ctx->r2 == ctx->r1) {
        // 0x80062464: slt         $at, $t5, $t3
        ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r11) ? 1 : 0;
            goto L_800624B0;
    }
    goto skip_12;
    // 0x80062464: slt         $at, $t5, $t3
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r11) ? 1 : 0;
    skip_12:
    // 0x80062468: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x8006246C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80062470: add         $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80062474: add         $t1, $t9, $v0
    ctx->r9 = ADD32(ctx->r25, ctx->r2);
    // 0x80062478: add         $t0, $s1, $v0
    ctx->r8 = ADD32(ctx->r17, ctx->r2);
    // 0x8006247C: lh          $v0, 0x0($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X0);
    // 0x80062480: lh          $v1, 0x0($t1)
    ctx->r3 = MEM_H(ctx->r9, 0X0);
    // 0x80062484: add         $t2, $v0, $v1
    ctx->r10 = ADD32(ctx->r2, ctx->r3);
    // 0x80062488: sh          $t2, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r10;
    // 0x8006248C: lh          $v0, 0x2($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X2);
    // 0x80062490: lh          $v1, 0x2($t1)
    ctx->r3 = MEM_H(ctx->r9, 0X2);
    // 0x80062494: add         $t2, $v0, $v1
    ctx->r10 = ADD32(ctx->r2, ctx->r3);
    // 0x80062498: sh          $t2, 0x2($t6)
    MEM_H(0X2, ctx->r14) = ctx->r10;
    // 0x8006249C: lh          $v0, 0x4($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X4);
    // 0x800624A0: lh          $v1, 0x4($t1)
    ctx->r3 = MEM_H(ctx->r9, 0X4);
    // 0x800624A4: add         $t2, $v0, $v1
    ctx->r10 = ADD32(ctx->r2, ctx->r3);
    // 0x800624A8: sh          $t2, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r10;
    // 0x800624AC: slt         $at, $t5, $t3
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r11) ? 1 : 0;
L_800624B0:
    // 0x800624B0: bne         $at, $zero, L_80062454
    if (ctx->r1 != 0) {
        // 0x800624B4: addi        $t6, $t6, 0xA
        ctx->r14 = ADD32(ctx->r14, 0XA);
            goto L_80062454;
    }
    // 0x800624B4: addi        $t6, $t6, 0xA
    ctx->r14 = ADD32(ctx->r14, 0XA);
    // 0x800624B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800624BC:
    // 0x800624BC: lw          $s0, 0x0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X0);
    // 0x800624C0: lw          $s1, 0x4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4);
    // 0x800624C4: jr          $ra
    // 0x800624C8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800624C8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x800624CC: nop

;}
RECOMP_FUNC void alCSPNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800624D0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800624D4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800624D8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800624DC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800624E0: lw          $a2, 0xC($a1)
    ctx->r6 = MEM_W(ctx->r5, 0XC);
    // 0x800624E4: sw          $zero, 0x20($a0)
    MEM_W(0X20, ctx->r4) = 0;
    // 0x800624E8: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
    // 0x800624EC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800624F0: lw          $t6, 0x3D10($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3D10);
    // 0x800624F4: ori         $t7, $zero, 0xFFFF
    ctx->r15 = 0 | 0XFFFF;
    // 0x800624F8: addiu       $t8, $zero, 0x1E8
    ctx->r24 = ADD32(0, 0X1E8);
    // 0x800624FC: addiu       $t9, $zero, 0x7FFF
    ctx->r25 = ADD32(0, 0X7FFF);
    // 0x80062500: addiu       $t0, $zero, 0x3E80
    ctx->r8 = ADD32(0, 0X3E80);
    // 0x80062504: sh          $t7, 0x30($a0)
    MEM_H(0X30, ctx->r4) = ctx->r15;
    // 0x80062508: sw          $t8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r24;
    // 0x8006250C: sw          $zero, 0x28($a0)
    MEM_W(0X28, ctx->r4) = 0;
    // 0x80062510: sw          $zero, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = 0;
    // 0x80062514: sh          $t9, 0x32($a0)
    MEM_H(0X32, ctx->r4) = ctx->r25;
    // 0x80062518: sw          $t0, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->r8;
    // 0x8006251C: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
    // 0x80062520: sw          $t6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r14;
    // 0x80062524: lw          $t1, 0x14($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X14);
    // 0x80062528: addiu       $t5, $zero, 0x9
    ctx->r13 = ADD32(0, 0X9);
    // 0x8006252C: sw          $t1, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->r9;
    // 0x80062530: lw          $t2, 0x18($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X18);
    // 0x80062534: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80062538: sw          $t2, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r10;
    // 0x8006253C: lw          $t3, 0x1C($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X1C);
    // 0x80062540: sb          $zero, 0x71($a0)
    MEM_B(0X71, ctx->r4) = 0;
    // 0x80062544: sw          $t3, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r11;
    // 0x80062548: lbu         $t4, 0x10($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X10);
    // 0x8006254C: sh          $t5, 0x38($a0)
    MEM_H(0X38, ctx->r4) = ctx->r13;
    // 0x80062550: sb          $t4, 0x70($a0)
    MEM_B(0X70, ctx->r4) = ctx->r12;
    // 0x80062554: lbu         $t6, 0x8($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X8);
    // 0x80062558: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8006255C: sb          $t6, 0x34($a0)
    MEM_B(0X34, ctx->r4) = ctx->r14;
    // 0x80062560: lbu         $a3, 0x8($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X8);
    // 0x80062564: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x80062568: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8006256C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80062570: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80062574: jal         0x800C7D50
    // 0x80062578: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    alHeapDBAlloc(rdram, ctx);
        goto after_0;
    // 0x80062578: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_0:
    // 0x8006257C: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
    // 0x80062580: jal         0x8000AE90
    // 0x80062584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    __initChanState(rdram, ctx);
        goto after_1;
    // 0x80062584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80062588: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8006258C: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80062590: addiu       $t8, $zero, 0x38
    ctx->r24 = ADD32(0, 0X38);
    // 0x80062594: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80062598: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8006259C: jal         0x800C7D50
    // 0x800625A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_2;
    // 0x800625A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x800625A4: sw          $zero, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = 0;
    // 0x800625A8: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x800625AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800625B0: blez        $t9, L_800625E0
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800625B4: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800625E0;
    }
    // 0x800625B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800625B8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800625BC:
    // 0x800625BC: lw          $t0, 0x6C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X6C);
    // 0x800625C0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800625C4: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x800625C8: sw          $v1, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->r3;
    // 0x800625CC: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x800625D0: addiu       $v1, $v1, 0x38
    ctx->r3 = ADD32(ctx->r3, 0X38);
    // 0x800625D4: slt         $at, $a0, $t1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800625D8: bne         $at, $zero, L_800625BC
    if (ctx->r1 != 0) {
        // 0x800625DC: nop
    
            goto L_800625BC;
    }
    // 0x800625DC: nop

L_800625E0:
    // 0x800625E0: sw          $zero, 0x64($s0)
    MEM_W(0X64, ctx->r16) = 0;
    // 0x800625E4: sw          $zero, 0x68($s0)
    MEM_W(0X68, ctx->r16) = 0;
    // 0x800625E8: lw          $a3, 0x4($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X4);
    // 0x800625EC: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800625F0: addiu       $t2, $zero, 0x1C
    ctx->r10 = ADD32(0, 0X1C);
    // 0x800625F4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800625F8: jal         0x800C7D50
    // 0x800625FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_3;
    // 0x800625FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x80062600: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    // 0x80062604: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // 0x80062608: jal         0x800C98BC
    // 0x8006260C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    alEvtqNew(rdram, ctx);
        goto after_4;
    // 0x8006260C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x80062610: lui         $t3, 0x8006
    ctx->r11 = S32(0X8006 << 16);
    // 0x80062614: addiu       $t3, $t3, 0x2648
    ctx->r11 = ADD32(ctx->r11, 0X2648);
    // 0x80062618: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x8006261C: sw          $t3, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r11;
    // 0x80062620: sw          $s0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r16;
    // 0x80062624: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80062628: lw          $a0, 0x3D10($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3D10);
    // 0x8006262C: jal         0x800C9930
    // 0x80062630: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    alSynAddPlayer(rdram, ctx);
        goto after_5;
    // 0x80062630: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x80062634: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80062638: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8006263C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80062640: jr          $ra
    // 0x80062644: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80062644: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void __CSPVoiceHandler(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062648: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8006264C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80062650: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80062654: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80062658: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8006265C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80062660: addiu       $t6, $a0, 0x38
    ctx->r14 = ADD32(ctx->r4, 0X38);
    // 0x80062664: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80062668: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8006266C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80062670: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80062674: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80062678: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006267C: sw          $t6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r14;
    // 0x80062680: addiu       $s5, $zero, 0x14
    ctx->r21 = ADD32(0, 0X14);
    // 0x80062684: addiu       $s6, $zero, 0x7F
    ctx->r22 = ADD32(0, 0X7F);
    // 0x80062688: addiu       $s7, $a0, 0x48
    ctx->r23 = ADD32(ctx->r4, 0X48);
    // 0x8006268C: addiu       $fp, $sp, 0x6C
    ctx->r30 = ADD32(ctx->r29, 0X6C);
L_80062690:
    // 0x80062690: lhu         $t7, 0x38($s2)
    ctx->r15 = MEM_HU(ctx->r18, 0X38);
    // 0x80062694: nop

    // 0x80062698: sltiu       $at, $t7, 0x18
    ctx->r1 = ctx->r15 < 0X18 ? 1 : 0;
    // 0x8006269C: beq         $at, $zero, L_80062BB8
    if (ctx->r1 == 0) {
        // 0x800626A0: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80062BB8;
    }
    // 0x800626A0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800626A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800626A8: addu        $at, $at, $t7
    gpr jr_addend_800626B4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800626AC: lw          $t7, 0x71C0($at)
    ctx->r15 = ADD32(ctx->r1, 0X71C0);
    // 0x800626B0: nop

    // 0x800626B4: jr          $t7
    // 0x800626B8: nop

    switch (jr_addend_800626B4 >> 2) {
        case 0: goto L_800626BC; break;
        case 1: goto L_80062BB8; break;
        case 2: goto L_80062938; break;
        case 3: goto L_80062BB8; break;
        case 4: goto L_80062BB8; break;
        case 5: goto L_800626EC; break;
        case 6: goto L_8006273C; break;
        case 7: goto L_8006294C; break;
        case 8: goto L_80062BB8; break;
        case 9: goto L_800626CC; break;
        case 10: goto L_80062960; break;
        case 11: goto L_80062BB8; break;
        case 12: goto L_80062B64; break;
        case 13: goto L_80062B84; break;
        case 14: goto L_80062BA8; break;
        case 15: goto L_800629C8; break;
        case 16: goto L_800629EC; break;
        case 17: goto L_80062AC0; break;
        case 18: goto L_80062BB8; break;
        case 19: goto L_80062BB8; break;
        case 20: goto L_80062BB8; break;
        case 21: goto L_80062938; break;
        case 22: goto L_800627A4; break;
        case 23: goto L_800628A8; break;
        default: switch_error(__func__, 0x800626B4, 0x800E71C0);
    }
    // 0x800626B8: nop

L_800626BC:
    // 0x800626BC: jal         0x80062C7C
    // 0x800626C0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    __CSPHandleNextSeqEvent(rdram, ctx);
        goto after_0;
    // 0x800626C0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x800626C4: b           L_80062BBC
    // 0x800626C8: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
        goto L_80062BBC;
    // 0x800626C8: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
L_800626CC:
    // 0x800626CC: addiu       $t8, $zero, 0x9
    ctx->r24 = ADD32(0, 0X9);
    // 0x800626D0: sh          $t8, 0x6C($sp)
    MEM_H(0X6C, ctx->r29) = ctx->r24;
    // 0x800626D4: lw          $a2, 0x5C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X5C);
    // 0x800626D8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x800626DC: jal         0x800C970C
    // 0x800626E0: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_1;
    // 0x800626E0: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    after_1:
    // 0x800626E4: b           L_80062BBC
    // 0x800626E8: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
        goto L_80062BBC;
    // 0x800626E8: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
L_800626EC:
    // 0x800626EC: lw          $s0, 0x3C($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X3C);
    // 0x800626F0: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800626F4: jal         0x800C9E10
    // 0x800626F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    alSynStopVoice(rdram, ctx);
        goto after_2;
    // 0x800626F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x800626FC: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x80062700: jal         0x800C9E90
    // 0x80062704: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    alSynFreeVoice(rdram, ctx);
        goto after_3;
    // 0x80062704: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x80062708: lw          $s1, 0x10($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X10);
    // 0x8006270C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80062710: lbu         $t9, 0x37($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X37);
    // 0x80062714: nop

    // 0x80062718: beq         $t9, $zero, L_80062728
    if (ctx->r25 == 0) {
        // 0x8006271C: nop
    
            goto L_80062728;
    }
    // 0x8006271C: nop

    // 0x80062720: jal         0x8000AEFC
    // 0x80062724: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    __seqpStopOsc(rdram, ctx);
        goto after_4;
    // 0x80062724: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
L_80062728:
    // 0x80062728: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8006272C: jal         0x8000A7C4
    // 0x80062730: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    __unmapVoice(rdram, ctx);
        goto after_5;
    // 0x80062730: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x80062734: b           L_80062BBC
    // 0x80062738: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
        goto L_80062BBC;
    // 0x80062738: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
L_8006273C:
    // 0x8006273C: lw          $s0, 0x3C($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X3C);
    // 0x80062740: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80062744: lw          $s1, 0x10($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X10);
    // 0x80062748: nop

    // 0x8006274C: lbu         $t0, 0x34($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X34);
    // 0x80062750: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80062754: bne         $t0, $zero, L_80062760
    if (ctx->r8 != 0) {
        // 0x80062758: nop
    
            goto L_80062760;
    }
    // 0x80062758: nop

    // 0x8006275C: sb          $t1, 0x34($s1)
    MEM_B(0X34, ctx->r17) = ctx->r9;
L_80062760:
    // 0x80062760: lw          $s3, 0x40($s2)
    ctx->r19 = MEM_W(ctx->r18, 0X40);
    // 0x80062764: lw          $t2, 0x1C($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X1C);
    // 0x80062768: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8006276C: addu        $t3, $t2, $s3
    ctx->r11 = ADD32(ctx->r10, ctx->r19);
    // 0x80062770: sw          $t3, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r11;
    // 0x80062774: lbu         $t4, 0x44($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0X44);
    // 0x80062778: jal         0x8000A9F8
    // 0x8006277C: sb          $t4, 0x30($s1)
    MEM_B(0X30, ctx->r17) = ctx->r12;
    __vsVol(rdram, ctx);
        goto after_6;
    // 0x8006277C: sb          $t4, 0x30($s1)
    MEM_B(0X30, ctx->r17) = ctx->r12;
    after_6:
    // 0x80062780: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x80062784: sra         $t5, $a2, 16
    ctx->r13 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80062788: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x8006278C: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x80062790: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80062794: jal         0x800C9BB0
    // 0x80062798: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    alSynSetVol(rdram, ctx);
        goto after_7;
    // 0x80062798: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_7:
    // 0x8006279C: b           L_80062BBC
    // 0x800627A0: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
        goto L_80062BBC;
    // 0x800627A0: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
L_800627A4:
    // 0x800627A4: lw          $s4, 0x40($s2)
    ctx->r20 = MEM_W(ctx->r18, 0X40);
    // 0x800627A8: lw          $t9, 0x78($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X78);
    // 0x800627AC: lw          $s1, 0x3C($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X3C);
    // 0x800627B0: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x800627B4: jalr        $t9
    // 0x800627B8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_8;
    // 0x800627B8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_8:
    // 0x800627BC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800627C0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800627C4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800627C8: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800627CC: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800627D0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800627D4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800627D8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800627DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800627E0: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800627E4: beq         $t7, $zero, L_80062830
    if (ctx->r15 == 0) {
        // 0x800627E8: or          $a1, $s2, $zero
        ctx->r5 = ctx->r18 | 0;
            goto L_80062830;
    }
    // 0x800627E8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800627EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800627F0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800627F4: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800627F8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800627FC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80062800: nop

    // 0x80062804: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80062808: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8006280C: nop

    // 0x80062810: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80062814: bne         $t7, $zero, L_80062828
    if (ctx->r15 != 0) {
        // 0x80062818: nop
    
            goto L_80062828;
    }
    // 0x80062818: nop

    // 0x8006281C: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80062820: b           L_80062840
    // 0x80062824: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_80062840;
    // 0x80062824: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_80062828:
    // 0x80062828: b           L_80062840
    // 0x8006282C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_80062840;
    // 0x8006282C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
L_80062830:
    // 0x80062830: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80062834: nop

    // 0x80062838: bltz        $t7, L_80062828
    if (SIGNED(ctx->r15) < 0) {
        // 0x8006283C: nop
    
            goto L_80062828;
    }
    // 0x8006283C: nop

L_80062840:
    // 0x80062840: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80062844: jal         0x8000A9F8
    // 0x80062848: sb          $t7, 0x36($s1)
    MEM_B(0X36, ctx->r17) = ctx->r15;
    __vsVol(rdram, ctx);
        goto after_9;
    // 0x80062848: sb          $t7, 0x36($s1)
    MEM_B(0X36, ctx->r17) = ctx->r15;
    after_9:
    // 0x8006284C: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x80062850: sra         $t8, $s0, 16
    ctx->r24 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80062854: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    // 0x80062858: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x8006285C: jal         0x8000AA88
    // 0x80062860: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    __vsDelta(rdram, ctx);
        goto after_10;
    // 0x80062860: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x80062864: sll         $a2, $s0, 16
    ctx->r6 = S32(ctx->r16 << 16);
    // 0x80062868: sra         $t0, $a2, 16
    ctx->r8 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8006286C: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x80062870: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x80062874: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x80062878: jal         0x800C9BB0
    // 0x8006287C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    alSynSetVol(rdram, ctx);
        goto after_11;
    // 0x8006287C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_11:
    // 0x80062880: addiu       $t1, $zero, 0x16
    ctx->r9 = ADD32(0, 0X16);
    // 0x80062884: sh          $t1, 0x6C($sp)
    MEM_H(0X6C, ctx->r29) = ctx->r9;
    // 0x80062888: sw          $s1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r17;
    // 0x8006288C: sw          $s4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r20;
    // 0x80062890: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80062894: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x80062898: jal         0x800C970C
    // 0x8006289C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_12;
    // 0x8006289C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_12:
    // 0x800628A0: b           L_80062BBC
    // 0x800628A4: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
        goto L_80062BBC;
    // 0x800628A4: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
L_800628A8:
    // 0x800628A8: lw          $s4, 0x40($s2)
    ctx->r20 = MEM_W(ctx->r18, 0X40);
    // 0x800628AC: lw          $t9, 0x78($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X78);
    // 0x800628B0: lw          $s1, 0x3C($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X3C);
    // 0x800628B4: lbu         $s0, 0x44($s2)
    ctx->r16 = MEM_BU(ctx->r18, 0X44);
    // 0x800628B8: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x800628BC: jalr        $t9
    // 0x800628C0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_13;
    // 0x800628C0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_13:
    // 0x800628C4: multu       $s0, $s5
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800628C8: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800628CC: lwc1        $f16, 0x28($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X28);
    // 0x800628D0: swc1        $f8, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f8.u32l;
    // 0x800628D4: lwc1        $f18, 0x2C($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x800628D8: lw          $t2, 0x60($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X60);
    // 0x800628DC: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800628E0: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800628E4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800628E8: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x800628EC: mflo        $t3
    ctx->r11 = lo;
    // 0x800628F0: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800628F4: lwc1        $f10, 0xC($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0XC);
    // 0x800628F8: nop

    // 0x800628FC: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80062900: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80062904: jal         0x800C9CE0
    // 0x80062908: nop

    alSynSetPitch(rdram, ctx);
        goto after_14;
    // 0x80062908: nop

    after_14:
    // 0x8006290C: addiu       $t5, $zero, 0x17
    ctx->r13 = ADD32(0, 0X17);
    // 0x80062910: sh          $t5, 0x6C($sp)
    MEM_H(0X6C, ctx->r29) = ctx->r13;
    // 0x80062914: sw          $s1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r17;
    // 0x80062918: sw          $s4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r20;
    // 0x8006291C: sb          $s0, 0x78($sp)
    MEM_B(0X78, ctx->r29) = ctx->r16;
    // 0x80062920: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80062924: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x80062928: jal         0x800C970C
    // 0x8006292C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_15;
    // 0x8006292C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_15:
    // 0x80062930: b           L_80062BBC
    // 0x80062934: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
        goto L_80062BBC;
    // 0x80062934: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
L_80062938:
    // 0x80062938: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x8006293C: jal         0x80062D40
    // 0x80062940: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    __CSPHandleMIDIMsg(rdram, ctx);
        goto after_16;
    // 0x80062940: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_16:
    // 0x80062944: b           L_80062BBC
    // 0x80062948: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
        goto L_80062BBC;
    // 0x80062948: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
L_8006294C:
    // 0x8006294C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80062950: jal         0x80063A2C
    // 0x80062954: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    __CSPHandleMetaMsg(rdram, ctx);
        goto after_17;
    // 0x80062954: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_17:
    // 0x80062958: b           L_80062BBC
    // 0x8006295C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
        goto L_80062BBC;
    // 0x8006295C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
L_80062960:
    // 0x80062960: lh          $t6, 0x3C($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X3C);
    // 0x80062964: lw          $s1, 0x64($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X64);
    // 0x80062968: sh          $t6, 0x32($s2)
    MEM_H(0X32, ctx->r18) = ctx->r14;
    // 0x8006296C: beq         $s1, $zero, L_80062BB8
    if (ctx->r17 == 0) {
        // 0x80062970: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80062BB8;
    }
    // 0x80062970: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80062974:
    // 0x80062974: jal         0x8000A9F8
    // 0x80062978: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    __vsVol(rdram, ctx);
        goto after_18;
    // 0x80062978: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_18:
    // 0x8006297C: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x80062980: sra         $t7, $s0, 16
    ctx->r15 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80062984: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    // 0x80062988: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    // 0x8006298C: jal         0x8000AA88
    // 0x80062990: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    __vsDelta(rdram, ctx);
        goto after_19;
    // 0x80062990: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_19:
    // 0x80062994: sll         $a2, $s0, 16
    ctx->r6 = S32(ctx->r16 << 16);
    // 0x80062998: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8006299C: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800629A0: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800629A4: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x800629A8: jal         0x800C9BB0
    // 0x800629AC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    alSynSetVol(rdram, ctx);
        goto after_20;
    // 0x800629AC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_20:
    // 0x800629B0: lw          $s1, 0x0($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X0);
    // 0x800629B4: nop

    // 0x800629B8: bne         $s1, $zero, L_80062974
    if (ctx->r17 != 0) {
        // 0x800629BC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80062974;
    }
    // 0x800629BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800629C0: b           L_80062BBC
    // 0x800629C4: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
        goto L_80062BBC;
    // 0x800629C4: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
L_800629C8:
    // 0x800629C8: lw          $t0, 0x2C($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X2C);
    // 0x800629CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800629D0: beq         $t0, $at, L_80062BB8
    if (ctx->r8 == ctx->r1) {
        // 0x800629D4: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_80062BB8;
    }
    // 0x800629D4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800629D8: sw          $t1, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r9;
    // 0x800629DC: jal         0x80062C0C
    // 0x800629E0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    __CSPPostNextSeqEvent(rdram, ctx);
        goto after_21;
    // 0x800629E0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_21:
    // 0x800629E4: b           L_80062BBC
    // 0x800629E8: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
        goto L_80062BBC;
    // 0x800629E8: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
L_800629EC:
    // 0x800629EC: lw          $t9, 0x2C($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X2C);
    // 0x800629F0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800629F4: bne         $t9, $at, L_80062BB8
    if (ctx->r25 != ctx->r1) {
        // 0x800629F8: ori         $t2, $zero, 0xFFFF
        ctx->r10 = 0 | 0XFFFF;
            goto L_80062BB8;
    }
    // 0x800629F8: ori         $t2, $zero, 0xFFFF
    ctx->r10 = 0 | 0XFFFF;
    // 0x800629FC: lbu         $t3, 0x34($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X34);
    // 0x80062A00: sh          $t2, 0x30($s2)
    MEM_H(0X30, ctx->r18) = ctx->r10;
    // 0x80062A04: blez        $t3, L_80062A58
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80062A08: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80062A58;
    }
    // 0x80062A08: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80062A0C:
    // 0x80062A0C: multu       $s0, $s5
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80062A10: lw          $t4, 0x60($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X60);
    // 0x80062A14: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80062A18: andi        $t8, $s0, 0xFF
    ctx->r24 = ctx->r16 & 0XFF;
    // 0x80062A1C: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x80062A20: mflo        $v0
    ctx->r2 = lo;
    // 0x80062A24: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x80062A28: sb          $s6, 0x10($t5)
    MEM_B(0X10, ctx->r13) = ctx->r22;
    // 0x80062A2C: lw          $t6, 0x60($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X60);
    // 0x80062A30: nop

    // 0x80062A34: addu        $v1, $t6, $v0
    ctx->r3 = ADD32(ctx->r14, ctx->r2);
    // 0x80062A38: lbu         $t7, 0x11($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X11);
    // 0x80062A3C: nop

    // 0x80062A40: sb          $t7, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r15;
    // 0x80062A44: lbu         $t0, 0x34($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0X34);
    // 0x80062A48: nop

    // 0x80062A4C: slt         $at, $t8, $t0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80062A50: bne         $at, $zero, L_80062A0C
    if (ctx->r1 != 0) {
        // 0x80062A54: nop
    
            goto L_80062A0C;
    }
    // 0x80062A54: nop

L_80062A58:
    // 0x80062A58: lw          $s1, 0x64($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X64);
    // 0x80062A5C: nop

    // 0x80062A60: beq         $s1, $zero, L_80062AB8
    if (ctx->r17 == 0) {
        // 0x80062A64: nop
    
            goto L_80062AB8;
    }
    // 0x80062A64: nop

L_80062A68:
    // 0x80062A68: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x80062A6C: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    // 0x80062A70: jal         0x800C9E10
    // 0x80062A74: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    alSynStopVoice(rdram, ctx);
        goto after_22;
    // 0x80062A74: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_22:
    // 0x80062A78: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x80062A7C: jal         0x800C9E90
    // 0x80062A80: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    alSynFreeVoice(rdram, ctx);
        goto after_23;
    // 0x80062A80: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_23:
    // 0x80062A84: lbu         $t1, 0x37($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X37);
    // 0x80062A88: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80062A8C: beq         $t1, $zero, L_80062A9C
    if (ctx->r9 == 0) {
        // 0x80062A90: nop
    
            goto L_80062A9C;
    }
    // 0x80062A90: nop

    // 0x80062A94: jal         0x8000AEFC
    // 0x80062A98: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    __seqpStopOsc(rdram, ctx);
        goto after_24;
    // 0x80062A98: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_24:
L_80062A9C:
    // 0x80062A9C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80062AA0: jal         0x8000A7C4
    // 0x80062AA4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    __unmapVoice(rdram, ctx);
        goto after_25;
    // 0x80062AA4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_25:
    // 0x80062AA8: lw          $s1, 0x64($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X64);
    // 0x80062AAC: nop

    // 0x80062AB0: bne         $s1, $zero, L_80062A68
    if (ctx->r17 != 0) {
        // 0x80062AB4: nop
    
            goto L_80062A68;
    }
    // 0x80062AB4: nop

L_80062AB8:
    // 0x80062AB8: b           L_80062BB8
    // 0x80062ABC: sw          $zero, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = 0;
        goto L_80062BB8;
    // 0x80062ABC: sw          $zero, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = 0;
L_80062AC0:
    // 0x80062AC0: lw          $t9, 0x2C($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X2C);
    // 0x80062AC4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80062AC8: bne         $t9, $at, L_80062BB8
    if (ctx->r25 != ctx->r1) {
        // 0x80062ACC: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_80062BB8;
    }
    // 0x80062ACC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80062AD0: jal         0x800C95F0
    // 0x80062AD4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    alEvtqFlushType(rdram, ctx);
        goto after_26;
    // 0x80062AD4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_26:
    // 0x80062AD8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80062ADC: jal         0x800C95F0
    // 0x80062AE0: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    alEvtqFlushType(rdram, ctx);
        goto after_27;
    // 0x80062AE0: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    after_27:
    // 0x80062AE4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80062AE8: jal         0x800C95F0
    // 0x80062AEC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    alEvtqFlushType(rdram, ctx);
        goto after_28;
    // 0x80062AEC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_28:
    // 0x80062AF0: lw          $s1, 0x64($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X64);
    // 0x80062AF4: nop

    // 0x80062AF8: beq         $s1, $zero, L_80062B3C
    if (ctx->r17 == 0) {
        // 0x80062AFC: addiu       $t2, $zero, 0x2
        ctx->r10 = ADD32(0, 0X2);
            goto L_80062B3C;
    }
    // 0x80062AFC: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
L_80062B00:
    // 0x80062B00: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    // 0x80062B04: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80062B08: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80062B0C: jal         0x8000AC34
    // 0x80062B10: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    __voiceNeedsNoteKill(rdram, ctx);
        goto after_29;
    // 0x80062B10: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    after_29:
    // 0x80062B14: beq         $v0, $zero, L_80062B28
    if (ctx->r2 == 0) {
        // 0x80062B18: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80062B28;
    }
    // 0x80062B18: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80062B1C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80062B20: jal         0x8000AB00
    // 0x80062B24: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    __seqpReleaseVoice(rdram, ctx);
        goto after_30;
    // 0x80062B24: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    after_30:
L_80062B28:
    // 0x80062B28: lw          $s1, 0x0($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X0);
    // 0x80062B2C: nop

    // 0x80062B30: bne         $s1, $zero, L_80062B00
    if (ctx->r17 != 0) {
        // 0x80062B34: nop
    
            goto L_80062B00;
    }
    // 0x80062B34: nop

    // 0x80062B38: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
L_80062B3C:
    // 0x80062B3C: sw          $t2, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r10;
    // 0x80062B40: addiu       $t3, $zero, 0x10
    ctx->r11 = ADD32(0, 0X10);
    // 0x80062B44: lui         $a2, 0x7FFF
    ctx->r6 = S32(0X7FFF << 16);
    // 0x80062B48: sh          $t3, 0x6C($sp)
    MEM_H(0X6C, ctx->r29) = ctx->r11;
    // 0x80062B4C: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x80062B50: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80062B54: jal         0x800C970C
    // 0x80062B58: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_31;
    // 0x80062B58: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    after_31:
    // 0x80062B5C: b           L_80062BBC
    // 0x80062B60: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
        goto L_80062BBC;
    // 0x80062B60: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
L_80062B64:
    // 0x80062B64: lbu         $s0, 0x3C($s2)
    ctx->r16 = MEM_BU(ctx->r18, 0X3C);
    // 0x80062B68: lw          $t5, 0x60($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X60);
    // 0x80062B6C: multu       $s0, $s5
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80062B70: lbu         $t4, 0x3D($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0X3D);
    // 0x80062B74: mflo        $t6
    ctx->r14 = lo;
    // 0x80062B78: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80062B7C: b           L_80062BB8
    // 0x80062B80: sb          $t4, 0x8($t7)
    MEM_B(0X8, ctx->r15) = ctx->r12;
        goto L_80062BB8;
    // 0x80062B80: sb          $t4, 0x8($t7)
    MEM_B(0X8, ctx->r15) = ctx->r12;
L_80062B84:
    // 0x80062B84: lw          $t8, 0x3C($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X3C);
    // 0x80062B88: lw          $a1, 0x20($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X20);
    // 0x80062B8C: sw          $t8, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r24;
    // 0x80062B90: beq         $a1, $zero, L_80062BB8
    if (ctx->r5 == 0) {
        // 0x80062B94: nop
    
            goto L_80062BB8;
    }
    // 0x80062B94: nop

    // 0x80062B98: jal         0x8000ACE0
    // 0x80062B9C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    __initFromBank(rdram, ctx);
        goto after_32;
    // 0x80062B9C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_32:
    // 0x80062BA0: b           L_80062BBC
    // 0x80062BA4: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
        goto L_80062BBC;
    // 0x80062BA4: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
L_80062BA8:
    // 0x80062BA8: lw          $a1, 0x3C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X3C);
    // 0x80062BAC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80062BB0: jal         0x8000ACE0
    // 0x80062BB4: sw          $a1, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r5;
    __initFromBank(rdram, ctx);
        goto after_33;
    // 0x80062BB4: sw          $a1, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r5;
    after_33:
L_80062BB8:
    // 0x80062BB8: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
L_80062BBC:
    // 0x80062BBC: jal         0x800C9830
    // 0x80062BC0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    alEvtqNextEvent(rdram, ctx);
        goto after_34;
    // 0x80062BC0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_34:
    // 0x80062BC4: beq         $v0, $zero, L_80062690
    if (ctx->r2 == 0) {
        // 0x80062BC8: sw          $v0, 0x28($s2)
        MEM_W(0X28, ctx->r18) = ctx->r2;
            goto L_80062690;
    }
    // 0x80062BC8: sw          $v0, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->r2;
    // 0x80062BCC: lw          $t0, 0x1C($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X1C);
    // 0x80062BD0: nop

    // 0x80062BD4: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x80062BD8: sw          $t1, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r9;
    // 0x80062BDC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80062BE0: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80062BE4: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80062BE8: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80062BEC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80062BF0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80062BF4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80062BF8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80062BFC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80062C00: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80062C04: jr          $ra
    // 0x80062C08: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80062C08: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
